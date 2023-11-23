// File Line: 384
// RVA: 0x29D030
void __fastcall ParkourSyncPositionTask::~ParkourSyncPositionTask(ParkourSyncPositionTask *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mParkourSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&ParkourSyncPositionTask::`vftable;
  p_mParkourSimObject = &this->mParkourSimObject;
  if ( this->mParkourSimObject.m_pPointer )
  {
    mPrev = p_mParkourSimObject->mPrev;
    mNext = p_mParkourSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mParkourSimObject->mPrev = p_mParkourSimObject;
    p_mParkourSimObject->mNext = p_mParkourSimObject;
  }
  p_mParkourSimObject->m_pPointer = 0i64;
  v5 = p_mParkourSimObject->mPrev;
  v6 = p_mParkourSimObject->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mParkourSimObject->mPrev = p_mParkourSimObject;
  p_mParkourSimObject->mNext = p_mParkourSimObject;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 424
// RVA: 0x29CF30
void __fastcall ParkourConstrainTask::~ParkourConstrainTask(ParkourConstrainTask *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mParkourSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&ParkourConstrainTask::`vftable;
  p_mParkourSimObject = &this->mParkourSimObject;
  if ( this->mParkourSimObject.m_pPointer )
  {
    mPrev = p_mParkourSimObject->mPrev;
    mNext = p_mParkourSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mParkourSimObject->mPrev = p_mParkourSimObject;
    p_mParkourSimObject->mNext = p_mParkourSimObject;
  }
  p_mParkourSimObject->m_pPointer = 0i64;
  v5 = p_mParkourSimObject->mPrev;
  v6 = p_mParkourSimObject->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mParkourSimObject->mPrev = p_mParkourSimObject;
  p_mParkourSimObject->mNext = p_mParkourSimObject;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 568
// RVA: 0x2E3240
void __fastcall AttackRightsTask::~AttackRightsTask(AttackRightsTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *p_mAttackRightsComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&AttackRightsTask::`vftable;
  p_mAttackRightsComponent = &this->mAttackRightsComponent;
  if ( this->mAttackRightsComponent.m_pPointer )
  {
    mPrev = p_mAttackRightsComponent->mPrev;
    mNext = p_mAttackRightsComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAttackRightsComponent->mPrev = p_mAttackRightsComponent;
    p_mAttackRightsComponent->mNext = p_mAttackRightsComponent;
  }
  p_mAttackRightsComponent->m_pPointer = 0i64;
  v5 = p_mAttackRightsComponent->mPrev;
  v6 = p_mAttackRightsComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mAttackRightsComponent->mPrev = p_mAttackRightsComponent;
  p_mAttackRightsComponent->mNext = p_mAttackRightsComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1039
// RVA: 0x29D810
void __fastcall ReticleSizeOverrideTask::~ReticleSizeOverrideTask(ReticleSizeOverrideTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AimingPlayerComponent> *p_m_AimingPlayerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&ReticleSizeOverrideTask::`vftable;
  p_m_AimingPlayerComponent = &this->m_AimingPlayerComponent;
  if ( this->m_AimingPlayerComponent.m_pPointer )
  {
    mPrev = p_m_AimingPlayerComponent->mPrev;
    mNext = p_m_AimingPlayerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_AimingPlayerComponent->mPrev = p_m_AimingPlayerComponent;
    p_m_AimingPlayerComponent->mNext = p_m_AimingPlayerComponent;
  }
  p_m_AimingPlayerComponent->m_pPointer = 0i64;
  v5 = p_m_AimingPlayerComponent->mPrev;
  v6 = p_m_AimingPlayerComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_AimingPlayerComponent->mPrev = p_m_AimingPlayerComponent;
  p_m_AimingPlayerComponent->mNext = p_m_AimingPlayerComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1111
// RVA: 0x29DDB0
void __fastcall SetStateFlagTask::~SetStateFlagTask(SetStateFlagTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *p_m_pSOCPC; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&SetStateFlagTask::`vftable;
  p_m_pSOCPC = &this->m_pSOCPC;
  if ( this->m_pSOCPC.m_pPointer )
  {
    mPrev = p_m_pSOCPC->mPrev;
    mNext = p_m_pSOCPC->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pSOCPC->mPrev = p_m_pSOCPC;
    p_m_pSOCPC->mNext = p_m_pSOCPC;
  }
  p_m_pSOCPC->m_pPointer = 0i64;
  v5 = p_m_pSOCPC->mPrev;
  v6 = p_m_pSOCPC->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pSOCPC->mPrev = p_m_pSOCPC;
  p_m_pSOCPC->mNext = p_m_pSOCPC;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

