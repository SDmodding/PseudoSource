// File Line: 85
// RVA: 0x29E790
void __fastcall TargetJumpTask::~TargetJumpTask(TargetJumpTask *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterPhysicsComponent> *p_m_pCharacterPhysicsComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rcx
  UFG::qNode<ITask,ITask> *v18; // rax

  this->vfptr = (ITaskVtbl *)&TargetJumpTask::`vftable;
  p_m_pTargetSimObject = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    mPrev = p_m_pTargetSimObject->mPrev;
    mNext = p_m_pTargetSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
    p_m_pTargetSimObject->mNext = p_m_pTargetSimObject;
  }
  p_m_pTargetSimObject->m_pPointer = 0i64;
  v5 = p_m_pTargetSimObject->mPrev;
  v6 = p_m_pTargetSimObject->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
  p_m_pTargetSimObject->mNext = p_m_pTargetSimObject;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v8 = p_m_pTransformNodeComponent->mPrev;
    v9 = this->m_pTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  }
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  v10 = p_m_pTransformNodeComponent->mPrev;
  v11 = this->m_pTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  p_m_pCharacterPhysicsComponent = &this->m_pCharacterPhysicsComponent;
  if ( this->m_pCharacterPhysicsComponent.m_pPointer )
  {
    v13 = p_m_pCharacterPhysicsComponent->mPrev;
    v14 = this->m_pCharacterPhysicsComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pCharacterPhysicsComponent->mPrev = p_m_pCharacterPhysicsComponent;
    this->m_pCharacterPhysicsComponent.mNext = &this->m_pCharacterPhysicsComponent;
  }
  this->m_pCharacterPhysicsComponent.m_pPointer = 0i64;
  v15 = p_m_pCharacterPhysicsComponent->mPrev;
  v16 = this->m_pCharacterPhysicsComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pCharacterPhysicsComponent->mPrev = p_m_pCharacterPhysicsComponent;
  this->m_pCharacterPhysicsComponent.mNext = &this->m_pCharacterPhysicsComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = this->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 136
// RVA: 0x29E9E0
void __fastcall TargetPlayTask::~TargetPlayTask(TargetPlayTask *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&TargetPlayTask::`vftable;
  p_mTarget = &this->mTarget;
  if ( this->mTarget.m_pPointer )
  {
    mPrev = p_mTarget->mPrev;
    mNext = p_mTarget->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mTarget->mPrev = p_mTarget;
    p_mTarget->mNext = p_mTarget;
  }
  p_mTarget->m_pPointer = 0i64;
  v5 = p_mTarget->mPrev;
  v6 = p_mTarget->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mTarget->mPrev = p_mTarget;
  p_mTarget->mNext = p_mTarget;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 236
// RVA: 0x29EB60
void __fastcall TargetSyncPositionTask::~TargetSyncPositionTask(TargetSyncPositionTask *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mSimObjectTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&TargetSyncPositionTask::`vftable;
  p_mSimObjectTarget = &this->mSimObjectTarget;
  if ( this->mSimObjectTarget.m_pPointer )
  {
    mPrev = p_mSimObjectTarget->mPrev;
    mNext = p_mSimObjectTarget->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mSimObjectTarget->mPrev = p_mSimObjectTarget;
    p_mSimObjectTarget->mNext = p_mSimObjectTarget;
  }
  p_mSimObjectTarget->m_pPointer = 0i64;
  v5 = p_mSimObjectTarget->mPrev;
  v6 = p_mSimObjectTarget->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mSimObjectTarget->mPrev = p_mSimObjectTarget;
  p_mSimObjectTarget->mNext = p_mSimObjectTarget;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 530
// RVA: 0x2E55B0
void __fastcall TargetAttackRightsTask::~TargetAttackRightsTask(TargetAttackRightsTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *p_mTargetAttackRightsComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&TargetAttackRightsTask::`vftable;
  p_mTargetAttackRightsComponent = &this->mTargetAttackRightsComponent;
  if ( this->mTargetAttackRightsComponent.m_pPointer )
  {
    mPrev = p_mTargetAttackRightsComponent->mPrev;
    mNext = p_mTargetAttackRightsComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mTargetAttackRightsComponent->mPrev = p_mTargetAttackRightsComponent;
    p_mTargetAttackRightsComponent->mNext = p_mTargetAttackRightsComponent;
  }
  p_mTargetAttackRightsComponent->m_pPointer = 0i64;
  v5 = p_mTargetAttackRightsComponent->mPrev;
  v6 = p_mTargetAttackRightsComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mTargetAttackRightsComponent->mPrev = p_mTargetAttackRightsComponent;
  p_mTargetAttackRightsComponent->mNext = p_mTargetAttackRightsComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 651
// RVA: 0x29E690
void __fastcall TargetFractureStrengthTask::~TargetFractureStrengthTask(TargetFractureStrengthTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *p_mRigidBody; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&TargetFractureStrengthTask::`vftable;
  p_mRigidBody = &this->mRigidBody;
  if ( this->mRigidBody.m_pPointer )
  {
    mPrev = p_mRigidBody->mPrev;
    mNext = p_mRigidBody->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mRigidBody->mPrev = p_mRigidBody;
    p_mRigidBody->mNext = p_mRigidBody;
  }
  p_mRigidBody->m_pPointer = 0i64;
  v5 = p_mRigidBody->mPrev;
  v6 = p_mRigidBody->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mRigidBody->mPrev = p_mRigidBody;
  p_mRigidBody->mNext = p_mRigidBody;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

