// File Line: 92
// RVA: 0x29ACF0
void __fastcall CarWanderTask::~CarWanderTask(CarWanderTask *this)
{
  CarWanderTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&CarWanderTask::`vftable';
  v2 = &this->m_pAIComponent;
  if ( this->m_pAIComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 109
// RVA: 0x29A220
void __fastcall CarFollowTask::~CarFollowTask(CarFollowTask *this)
{
  CarFollowTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&CarFollowTask::`vftable';
  v2 = &this->m_pAIComponent;
  if ( this->m_pAIComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 126
// RVA: 0x29A120
void __fastcall CarEscortTask::~CarEscortTask(CarEscortTask *this)
{
  CarEscortTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&CarEscortTask::`vftable';
  v2 = &this->m_pAIComponent;
  if ( this->m_pAIComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 143
// RVA: 0x29A470
void __fastcall CarGoToTask::~CarGoToTask(CarGoToTask *this)
{
  CarGoToTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&CarGoToTask::`vftable';
  v2 = &this->m_pRoadSpaceComponent;
  if ( this->m_pRoadSpaceComponent.m_pPointer )
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
  v7 = &v1->m_pAIComponent;
  if ( v1->m_pAIComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pAIComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIComponent.mPrev;
  }
  v1->m_pAIComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pAIComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 163
// RVA: 0x29AA00
void __fastcall CarStopAtTask::~CarStopAtTask(CarStopAtTask *this)
{
  CarStopAtTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&CarStopAtTask::`vftable';
  v2 = &this->m_pAiDriver;
  if ( this->m_pAiDriver.m_pPointer )
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
  v7 = &v1->m_pRoadSpace;
  if ( v1->m_pRoadSpace.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pRoadSpace.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pRoadSpace.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pRoadSpace.mPrev;
  }
  v1->m_pRoadSpace.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pRoadSpace.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pRoadSpace.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pRoadSpace.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 182
// RVA: 0x29ABB0
void __fastcall CarWaitTask::~CarWaitTask(CarWaitTask *this)
{
  CarWaitTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&CarWaitTask::`vftable';
  v2 = &this->m_pAiDriver;
  if ( this->m_pAiDriver.m_pPointer )
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
  v7 = &v1->m_pRoadSpace;
  if ( v1->m_pRoadSpace.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pRoadSpace.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pRoadSpace.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pRoadSpace.mPrev;
  }
  v1->m_pRoadSpace.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pRoadSpace.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pRoadSpace.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pRoadSpace.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 204
// RVA: 0x29A8C0
void __fastcall CarStopAtStimulusTask::~CarStopAtStimulusTask(CarStopAtStimulusTask *this)
{
  CarStopAtStimulusTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&CarStopAtStimulusTask::`vftable';
  v2 = &this->m_pAiDriver;
  if ( this->m_pAiDriver.m_pPointer )
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
  v7 = &v1->m_pRoadSpace;
  if ( v1->m_pRoadSpace.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pRoadSpace.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pRoadSpace.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pRoadSpace.mPrev;
  }
  v1->m_pRoadSpace.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pRoadSpace.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pRoadSpace.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pRoadSpace.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 447
// RVA: 0x29AB40
void __fastcall CarStopTrack::~CarStopTrack(CarStopTrack *this)
{
  CarStopTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarStopTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 450
// RVA: 0x2BE0E0
__int64 __fastcall CarStopTrack::GetClassNameUID(CarStopTrack *this)
{
  return CarStopTrack::sClassNameUID;
}

// File Line: 460
// RVA: 0x29A850
void __fastcall CarRaceTrack::~CarRaceTrack(CarRaceTrack *this)
{
  CarRaceTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarRaceTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 463
// RVA: 0x316E40
CarRaceTrack *__fastcall CarRaceTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::CarRaceTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, CarRaceTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<CarRaceTask>::`vftable';
  *(_QWORD *)v1 = &CarRaceTrack::`vftable';
  return (CarRaceTrack *)v1;
}

// File Line: 475
// RVA: 0x29A990
void __fastcall CarStopAtStimulusTrack::~CarStopAtStimulusTrack(CarStopAtStimulusTrack *this)
{
  CarStopAtStimulusTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarStopAtStimulusTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 478
// RVA: 0x2BE0C0
__int64 __fastcall CarStopAtStimulusTrack::GetClassNameUID(CarStopAtStimulusTrack *this)
{
  return CarStopAtStimulusTrack::sClassNameUID;
}

// File Line: 492
// RVA: 0x29AC80
void __fastcall CarWaitTrack::~CarWaitTrack(CarWaitTrack *this)
{
  CarWaitTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarWaitTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 494
// RVA: 0x2C0D90
const char *__fastcall CarWaitTrack::GetClassname(CarWaitTrack *this)
{
  return CarWaitTrack::sClassName;
}

// File Line: 505
// RVA: 0x29AAD0
void __fastcall CarStopAtTrack::~CarStopAtTrack(CarStopAtTrack *this)
{
  CarStopAtTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarStopAtTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 508
// RVA: 0x2C0D70
const char *__fastcall CarStopAtTrack::GetClassname(CarStopAtTrack *this)
{
  return CarStopAtTrack::sClassName;
}

// File Line: 518
// RVA: 0x29AD80
void __fastcall CarWanderTrack::~CarWanderTrack(CarWanderTrack *this)
{
  CarWanderTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarWanderTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 521
// RVA: 0x2C0DA0
const char *__fastcall CarWanderTrack::GetClassname(CarWanderTrack *this)
{
  return CarWanderTrack::sClassName;
}

// File Line: 531
// RVA: 0x29A2B0
void __fastcall CarFollowTrack::~CarFollowTrack(CarFollowTrack *this)
{
  CarFollowTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFollowTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 534
// RVA: 0x2BDF00
__int64 __fastcall CarFollowTrack::GetClassNameUID(CarFollowTrack *this)
{
  return CarFollowTrack::sClassNameUID;
}

// File Line: 544
// RVA: 0x29A1B0
void __fastcall CarEscortTrack::~CarEscortTrack(CarEscortTrack *this)
{
  CarEscortTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarEscortTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 547
// RVA: 0x2BDEF0
__int64 __fastcall CarEscortTrack::GetClassNameUID(CarEscortTrack *this)
{
  return CarEscortTrack::sClassNameUID;
}

// File Line: 557
// RVA: 0x29A540
void __fastcall CarGoToTrack::~CarGoToTrack(CarGoToTrack *this)
{
  CarGoToTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarGoToTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 560
// RVA: 0x3168F0
CarGoToTrack *__fastcall CarGoToTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::CarGoToTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, CarGoToTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<CarGoToTask>::`vftable';
  *(_QWORD *)v1 = &CarGoToTrack::`vftable';
  return (CarGoToTrack *)v1;
}

// File Line: 570
// RVA: 0x29A5B0
void __fastcall CarNoDestinationTrack::~CarNoDestinationTrack(CarNoDestinationTrack *this)
{
  CarNoDestinationTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarNoDestinationTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 573
// RVA: 0x2C0CA0
const char *__fastcall CarNoDestinationTrack::GetClassname(CarNoDestinationTrack *this)
{
  return CarNoDestinationTrack::sClassName;
}

// File Line: 584
// RVA: 0x29A0B0
void __fastcall CarAttackTrack::~CarAttackTrack(CarAttackTrack *this)
{
  CarAttackTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarAttackTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 587
// RVA: 0x2BDEB0
__int64 __fastcall CarAttackTrack::GetClassNameUID(CarAttackTrack *this)
{
  return CarAttackTrack::sClassNameUID;
}

// File Line: 607
// RVA: 0x29A320
void __fastcall CarFormationAttackTrack::~CarFormationAttackTrack(CarFormationAttackTrack *this)
{
  CarFormationAttackTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationAttackTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 610
// RVA: 0x2BDF30
__int64 __fastcall CarFormationAttackTrack::GetClassNameUID(CarFormationAttackTrack *this)
{
  return CarFormationAttackTrack::sClassNameUID;
}

// File Line: 630
// RVA: 0x29A400
void __fastcall CarFormationTrack::~CarFormationTrack(CarFormationTrack *this)
{
  CarFormationTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 633
// RVA: 0x2BDFA0
__int64 __fastcall CarFormationTrack::GetClassNameUID(CarFormationTrack *this)
{
  return CarFormationTrack::sClassNameUID;
}

// File Line: 661
// RVA: 0x29A7E0
void __fastcall CarOffsetDriveTrack::~CarOffsetDriveTrack(CarOffsetDriveTrack *this)
{
  CarOffsetDriveTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarOffsetDriveTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 664
// RVA: 0x2BE080
__int64 __fastcall CarOffsetDriveTrack::GetClassNameUID(CarOffsetDriveTrack *this)
{
  return CarOffsetDriveTrack::sClassNameUID;
}

// File Line: 685
// RVA: 0x29A390
void __fastcall CarFormationDriveTrack::~CarFormationDriveTrack(CarFormationDriveTrack *this)
{
  CarFormationDriveTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationDriveTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 688
// RVA: 0x2BDF50
__int64 __fastcall CarFormationDriveTrack::GetClassNameUID(CarFormationDriveTrack *this)
{
  return CarFormationDriveTrack::sClassNameUID;
}

// File Line: 701
// RVA: 0x29A620
void __fastcall CarOccupantAimTrack::~CarOccupantAimTrack(CarOccupantAimTrack *this)
{
  CarOccupantAimTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarOccupantAimTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 704
// RVA: 0x2C0CB0
const char *__fastcall CarOccupantAimTrack::GetClassname(CarOccupantAimTrack *this)
{
  return CarOccupantAimTrack::sClassName;
}

// File Line: 719
// RVA: 0x29A700
void __fastcall CarOccupantShootTrack::~CarOccupantShootTrack(CarOccupantShootTrack *this)
{
  CarOccupantShootTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarOccupantShootTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 722
// RVA: 0x2BE050
__int64 __fastcall CarOccupantShootTrack::GetClassNameUID(CarOccupantShootTrack *this)
{
  return CarOccupantShootTrack::sClassNameUID;
}

// File Line: 737
// RVA: 0x29A690
void __fastcall CarOccupantIntentionTrack::~CarOccupantIntentionTrack(CarOccupantIntentionTrack *this)
{
  CarOccupantIntentionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarOccupantIntentionTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 740
// RVA: 0x2BE040
__int64 __fastcall CarOccupantIntentionTrack::GetClassNameUID(CarOccupantIntentionTrack *this)
{
  return CarOccupantIntentionTrack::sClassNameUID;
}

// File Line: 759
// RVA: 0x29A770
void __fastcall CarOccupantsActionTrack::~CarOccupantsActionTrack(CarOccupantsActionTrack *this)
{
  CarOccupantsActionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarOccupantsActionTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 762
// RVA: 0x2C0D10
const char *__fastcall CarOccupantsActionTrack::GetClassname(CarOccupantsActionTrack *this)
{
  return CarOccupantsActionTrack::sClassName;
}

// File Line: 777
// RVA: 0x29DB10
void __fastcall SetCarModeTrack::~SetCarModeTrack(SetCarModeTrack *this)
{
  SetCarModeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetCarModeTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 780
// RVA: 0x2BF650
__int64 __fastcall SetCarModeTrack::GetClassNameUID(SetCarModeTrack *this)
{
  return SetCarModeTrack::sClassNameUID;
}

// File Line: 794
// RVA: 0x2BFF50
__int64 __fastcall VehicleAudioEventTrack::GetClassNameUID(VehicleAudioEventTrack *this)
{
  return VehicleAudioEventTrack::sClassNameUID;
}

// File Line: 821
// RVA: 0x324E70
VehicleEffectTrack *__fastcall VehicleEffectTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::VehicleEffectTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, VehicleEffectTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<VehicleEffectTask>::`vftable';
  *(_QWORD *)v1 = &VehicleEffectTrack::`vftable';
  *((_DWORD *)v1 + 15) = 0;
  return (VehicleEffectTrack *)v1;
}

// File Line: 840
// RVA: 0x2C2EF0
const char *__fastcall VehicleQueueHeadlightFlashesTrack::GetClassname(VehicleQueueHeadlightFlashesTrack *this)
{
  return VehicleQueueHeadlightFlashesTrack::sClassName;
}

// File Line: 859
// RVA: 0x2C0200
__int64 __fastcall VehicleOnDeadDriverStopTrack::GetClassNameUID(VehicleOnDeadDriverStopTrack *this)
{
  return VehicleOnDeadDriverStopTrack::sClassNameUID;
}

// File Line: 867
// RVA: 0x2C2CF0
const char *__fastcall VehicleEnableTemporaryPassTrack::GetClassname(VehicleEnableTemporaryPassTrack *this)
{
  return VehicleEnableTemporaryPassTrack::sClassName;
}

