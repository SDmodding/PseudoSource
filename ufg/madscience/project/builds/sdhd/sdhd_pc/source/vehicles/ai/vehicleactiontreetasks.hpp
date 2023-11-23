// File Line: 56
// RVA: 0x66C6C0
void __fastcall CarStopTask::~CarStopTask(CarStopTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&CarStopTask::`vftable;
  p_m_pAIComponent = &this->m_pAIComponent;
  if ( this->m_pAIComponent.m_pPointer )
  {
    mPrev = p_m_pAIComponent->mPrev;
    mNext = p_m_pAIComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIComponent->mPrev = p_m_pAIComponent;
    p_m_pAIComponent->mNext = p_m_pAIComponent;
  }
  p_m_pAIComponent->m_pPointer = 0i64;
  v5 = p_m_pAIComponent->mPrev;
  v6 = p_m_pAIComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIComponent->mPrev = p_m_pAIComponent;
  p_m_pAIComponent->mNext = p_m_pAIComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 74
// RVA: 0x66C5F0
void __fastcall CarRaceTask::~CarRaceTask(CarRaceTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *p_m_pRoadSpaceComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&CarRaceTask::`vftable;
  p_m_pRoadSpaceComponent = &this->m_pRoadSpaceComponent;
  if ( this->m_pRoadSpaceComponent.m_pPointer )
  {
    mPrev = p_m_pRoadSpaceComponent->mPrev;
    mNext = p_m_pRoadSpaceComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pRoadSpaceComponent->mPrev = p_m_pRoadSpaceComponent;
    p_m_pRoadSpaceComponent->mNext = p_m_pRoadSpaceComponent;
  }
  p_m_pRoadSpaceComponent->m_pPointer = 0i64;
  v5 = p_m_pRoadSpaceComponent->mPrev;
  v6 = p_m_pRoadSpaceComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pRoadSpaceComponent->mPrev = p_m_pRoadSpaceComponent;
  p_m_pRoadSpaceComponent->mNext = p_m_pRoadSpaceComponent;
  p_m_pAIComponent = &this->m_pAIComponent;
  if ( this->m_pAIComponent.m_pPointer )
  {
    v8 = p_m_pAIComponent->mPrev;
    v9 = this->m_pAIComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pAIComponent->mPrev = p_m_pAIComponent;
    this->m_pAIComponent.mNext = &this->m_pAIComponent;
  }
  this->m_pAIComponent.m_pPointer = 0i64;
  v10 = p_m_pAIComponent->mPrev;
  v11 = this->m_pAIComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pAIComponent->mPrev = p_m_pAIComponent;
  this->m_pAIComponent.mNext = &this->m_pAIComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 225
// RVA: 0x66C3B0
void __fastcall CarNoDestinationTask::~CarNoDestinationTask(CarNoDestinationTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&CarNoDestinationTask::`vftable;
  p_m_pAIComponent = &this->m_pAIComponent;
  if ( this->m_pAIComponent.m_pPointer )
  {
    mPrev = p_m_pAIComponent->mPrev;
    mNext = p_m_pAIComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIComponent->mPrev = p_m_pAIComponent;
    p_m_pAIComponent->mNext = p_m_pAIComponent;
  }
  p_m_pAIComponent->m_pPointer = 0i64;
  v5 = p_m_pAIComponent->mPrev;
  v6 = p_m_pAIComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIComponent->mPrev = p_m_pAIComponent;
  p_m_pAIComponent->mNext = p_m_pAIComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 296
// RVA: 0x66C4D0
void __fastcall CarOffsetDriveTask::~CarOffsetDriveTask(CarOffsetDriveTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&CarOffsetDriveTask::`vftable;
  p_m_pAIComponent = &this->m_pAIComponent;
  if ( this->m_pAIComponent.m_pPointer )
  {
    mPrev = p_m_pAIComponent->mPrev;
    mNext = p_m_pAIComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIComponent->mPrev = p_m_pAIComponent;
    p_m_pAIComponent->mNext = p_m_pAIComponent;
  }
  p_m_pAIComponent->m_pPointer = 0i64;
  v5 = p_m_pAIComponent->mPrev;
  v6 = p_m_pAIComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIComponent->mPrev = p_m_pAIComponent;
  p_m_pAIComponent->mNext = p_m_pAIComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 314
// RVA: 0x66C290
void __fastcall CarFormationDriveTask::~CarFormationDriveTask(CarFormationDriveTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&CarFormationDriveTask::`vftable;
  p_m_pAIComponent = &this->m_pAIComponent;
  if ( this->m_pAIComponent.m_pPointer )
  {
    mPrev = p_m_pAIComponent->mPrev;
    mNext = p_m_pAIComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIComponent->mPrev = p_m_pAIComponent;
    p_m_pAIComponent->mNext = p_m_pAIComponent;
  }
  p_m_pAIComponent->m_pPointer = 0i64;
  v5 = p_m_pAIComponent->mPrev;
  v6 = p_m_pAIComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIComponent->mPrev = p_m_pAIComponent;
  p_m_pAIComponent->mNext = p_m_pAIComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 332
// RVA: 0x66C440
void __fastcall CarOccupantAimTask::~CarOccupantAimTask(CarOccupantAimTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pActiveAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&CarOccupantAimTask::`vftable;
  p_m_pActiveAIEntityComponent = &this->m_pActiveAIEntityComponent;
  if ( this->m_pActiveAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pActiveAIEntityComponent->mPrev;
    mNext = p_m_pActiveAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pActiveAIEntityComponent->mPrev = p_m_pActiveAIEntityComponent;
    p_m_pActiveAIEntityComponent->mNext = p_m_pActiveAIEntityComponent;
  }
  p_m_pActiveAIEntityComponent->m_pPointer = 0i64;
  v5 = p_m_pActiveAIEntityComponent->mPrev;
  v6 = p_m_pActiveAIEntityComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pActiveAIEntityComponent->mPrev = p_m_pActiveAIEntityComponent;
  p_m_pActiveAIEntityComponent->mNext = p_m_pActiveAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

