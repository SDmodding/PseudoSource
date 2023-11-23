// File Line: 154
// RVA: 0x29F660
void __fastcall VehicleOverrideWheelFrictionMultiplierTask::~VehicleOverrideWheelFrictionMultiplierTask(
        VehicleOverrideWheelFrictionMultiplierTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_mPhysicsMoverInterface; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&VehicleOverrideWheelFrictionMultiplierTask::`vftable;
  p_mPhysicsMoverInterface = &this->mPhysicsMoverInterface;
  if ( this->mPhysicsMoverInterface.m_pPointer )
  {
    mPrev = p_mPhysicsMoverInterface->mPrev;
    mNext = p_mPhysicsMoverInterface->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
    p_mPhysicsMoverInterface->mNext = p_mPhysicsMoverInterface;
  }
  p_mPhysicsMoverInterface->m_pPointer = 0i64;
  v5 = p_mPhysicsMoverInterface->mPrev;
  v6 = p_mPhysicsMoverInterface->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
  p_mPhysicsMoverInterface->mNext = p_mPhysicsMoverInterface;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 172
// RVA: 0x29F780
void __fastcall VehicleSetCollisionShouldTriggerExplosionTask::~VehicleSetCollisionShouldTriggerExplosionTask(
        VehicleSetCollisionShouldTriggerExplosionTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_mPhysicsMoverInterface; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&VehicleSetCollisionShouldTriggerExplosionTask::`vftable;
  p_mPhysicsMoverInterface = &this->mPhysicsMoverInterface;
  if ( this->mPhysicsMoverInterface.m_pPointer )
  {
    mPrev = p_mPhysicsMoverInterface->mPrev;
    mNext = p_mPhysicsMoverInterface->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
    p_mPhysicsMoverInterface->mNext = p_mPhysicsMoverInterface;
  }
  p_mPhysicsMoverInterface->m_pPointer = 0i64;
  v5 = p_mPhysicsMoverInterface->mPrev;
  v6 = p_mPhysicsMoverInterface->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
  p_mPhysicsMoverInterface->mNext = p_mPhysicsMoverInterface;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 192
// RVA: 0x29F540
void __fastcall VehicleLockHighLODTask::~VehicleLockHighLODTask(VehicleLockHighLODTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_mPhysicsMoverInterface; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&VehicleLockHighLODTask::`vftable;
  p_mPhysicsMoverInterface = &this->mPhysicsMoverInterface;
  if ( this->mPhysicsMoverInterface.m_pPointer )
  {
    mPrev = p_mPhysicsMoverInterface->mPrev;
    mNext = p_mPhysicsMoverInterface->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
    p_mPhysicsMoverInterface->mNext = p_mPhysicsMoverInterface;
  }
  p_mPhysicsMoverInterface->m_pPointer = 0i64;
  v5 = p_mPhysicsMoverInterface->mPrev;
  v6 = p_mPhysicsMoverInterface->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
  p_mPhysicsMoverInterface->mNext = p_mPhysicsMoverInterface;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 289
// RVA: 0x299EE0
void __fastcall BikePhysicsEnableConstraintTask::~BikePhysicsEnableConstraintTask(
        BikePhysicsEnableConstraintTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::BikePhysicsMoverComponent> *p_m_pBikePhysicsMoverComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&BikePhysicsEnableConstraintTask::`vftable;
  p_m_pBikePhysicsMoverComponent = &this->m_pBikePhysicsMoverComponent;
  if ( this->m_pBikePhysicsMoverComponent.m_pPointer )
  {
    mPrev = p_m_pBikePhysicsMoverComponent->mPrev;
    mNext = p_m_pBikePhysicsMoverComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pBikePhysicsMoverComponent->mPrev = p_m_pBikePhysicsMoverComponent;
    p_m_pBikePhysicsMoverComponent->mNext = p_m_pBikePhysicsMoverComponent;
  }
  p_m_pBikePhysicsMoverComponent->m_pPointer = 0i64;
  v5 = p_m_pBikePhysicsMoverComponent->mPrev;
  v6 = p_m_pBikePhysicsMoverComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pBikePhysicsMoverComponent->mPrev = p_m_pBikePhysicsMoverComponent;
  p_m_pBikePhysicsMoverComponent->mNext = p_m_pBikePhysicsMoverComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 328
// RVA: 0x29F6F0
void __fastcall VehiclePreventWheelieTask::~VehiclePreventWheelieTask(VehiclePreventWheelieTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_mPhysicsMoverInterface; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&VehiclePreventWheelieTask::`vftable;
  p_mPhysicsMoverInterface = &this->mPhysicsMoverInterface;
  if ( this->mPhysicsMoverInterface.m_pPointer )
  {
    mPrev = p_mPhysicsMoverInterface->mPrev;
    mNext = p_mPhysicsMoverInterface->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
    p_mPhysicsMoverInterface->mNext = p_mPhysicsMoverInterface;
  }
  p_mPhysicsMoverInterface->m_pPointer = 0i64;
  v5 = p_mPhysicsMoverInterface->mPrev;
  v6 = p_mPhysicsMoverInterface->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
  p_mPhysicsMoverInterface->mNext = p_mPhysicsMoverInterface;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 348
// RVA: 0x29F440
void __fastcall VehicleInteractTask::~VehicleInteractTask(VehicleInteractTask *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_mVehicleTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&VehicleInteractTask::`vftable;
  p_mVehicleTarget = &this->mVehicleTarget;
  if ( this->mVehicleTarget.m_pPointer )
  {
    mPrev = p_mVehicleTarget->mPrev;
    mNext = p_mVehicleTarget->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mVehicleTarget->mPrev = p_mVehicleTarget;
    p_mVehicleTarget->mNext = p_mVehicleTarget;
  }
  p_mVehicleTarget->m_pPointer = 0i64;
  v5 = p_mVehicleTarget->mPrev;
  v6 = p_mVehicleTarget->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mVehicleTarget->mPrev = p_mVehicleTarget;
  p_mVehicleTarget->mNext = p_mVehicleTarget;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 390
// RVA: 0x29F5D0
void __fastcall VehicleMassScaleForCollisionsTask::~VehicleMassScaleForCollisionsTask(
        VehicleMassScaleForCollisionsTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_m_PMI; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&VehicleMassScaleForCollisionsTask::`vftable;
  p_m_PMI = &this->m_PMI;
  if ( this->m_PMI.m_pPointer )
  {
    mPrev = p_m_PMI->mPrev;
    mNext = p_m_PMI->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_PMI->mPrev = p_m_PMI;
    p_m_PMI->mNext = p_m_PMI;
  }
  p_m_PMI->m_pPointer = 0i64;
  v5 = p_m_PMI->mPrev;
  v6 = p_m_PMI->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_PMI->mPrev = p_m_PMI;
  p_m_PMI->mNext = p_m_PMI;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

