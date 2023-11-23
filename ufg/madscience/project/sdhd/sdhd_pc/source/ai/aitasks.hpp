// File Line: 132
// RVA: 0x298840
void __fastcall PerformScriptCommandTask::PerformScriptCommandTask(PerformScriptCommandTask *this)
{
  IFinishUpdate *v2; // rcx

  this->Task<PerformScriptCommandTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<PerformScriptCommandTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->Task<PerformScriptCommandTrack>::ITask::vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->Task<PerformScriptCommandTrack>::ITask::vfptr = (ITaskVtbl *)&Task<PerformScriptCommandTrack>::`vftable;
  v2 = &this->IFinishUpdate;
  v2->mPrev = &v2->UFG::qNode<IFinishUpdate,IFinishUpdate>;
  v2->mNext = &v2->UFG::qNode<IFinishUpdate,IFinishUpdate>;
  v2->vfptr = (IFinishUpdateVtbl *)&IFinishUpdate::`vftable;
  this->Task<PerformScriptCommandTrack>::ITask::vfptr = (ITaskVtbl *)&PerformScriptCommandTask::`vftable{for `Task<PerformScriptCommandTrack>};
  v2->vfptr = (IFinishUpdateVtbl *)&PerformScriptCommandTask::`vftable{for `IFinishUpdate};
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pAIScriptInterfaceComponent.mPrev = &this->m_pAIScriptInterfaceComponent;
  this->m_pAIScriptInterfaceComponent.mNext = &this->m_pAIScriptInterfaceComponent;
  this->m_pAIScriptInterfaceComponent.m_pPointer = 0i64;
  this->m_pActorComponent.mPrev = &this->m_pActorComponent;
  this->m_pActorComponent.mNext = &this->m_pActorComponent;
  this->m_pActorComponent.m_pPointer = 0i64;
  this->m_pActionTreeComponent.mPrev = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.m_pPointer = 0i64;
}

// File Line: 133
// RVA: 0x29D0C0
void __fastcall PerformScriptCommandTask::~PerformScriptCommandTask(PerformScriptCommandTask *this)
{
  IFinishUpdate *v2; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TSActorComponent> *p_m_pActorComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIScriptInterfaceComponent> *p_m_pAIScriptInterfaceComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v23; // rcx
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v24; // rax
  UFG::qNode<ITask,ITask> *v25; // rcx
  UFG::qNode<ITask,ITask> *v26; // rax

  this->Task<PerformScriptCommandTrack>::ITask::vfptr = (ITaskVtbl *)&PerformScriptCommandTask::`vftable{for `Task<PerformScriptCommandTrack>};
  v2 = &this->IFinishUpdate;
  this->IFinishUpdate::vfptr = (IFinishUpdateVtbl *)&PerformScriptCommandTask::`vftable{for `IFinishUpdate};
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pPointer )
  {
    mPrev = p_m_pActionTreeComponent->mPrev;
    mNext = p_m_pActionTreeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  }
  p_m_pActionTreeComponent->m_pPointer = 0i64;
  v6 = p_m_pActionTreeComponent->mPrev;
  v7 = p_m_pActionTreeComponent->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
  p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  p_m_pActorComponent = &this->m_pActorComponent;
  if ( this->m_pActorComponent.m_pPointer )
  {
    v9 = p_m_pActorComponent->mPrev;
    v10 = this->m_pActorComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    p_m_pActorComponent->mPrev = p_m_pActorComponent;
    this->m_pActorComponent.mNext = &this->m_pActorComponent;
  }
  this->m_pActorComponent.m_pPointer = 0i64;
  v11 = p_m_pActorComponent->mPrev;
  v12 = this->m_pActorComponent.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  p_m_pActorComponent->mPrev = p_m_pActorComponent;
  this->m_pActorComponent.mNext = &this->m_pActorComponent;
  p_m_pAIScriptInterfaceComponent = &this->m_pAIScriptInterfaceComponent;
  if ( this->m_pAIScriptInterfaceComponent.m_pPointer )
  {
    v14 = p_m_pAIScriptInterfaceComponent->mPrev;
    v15 = this->m_pAIScriptInterfaceComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    p_m_pAIScriptInterfaceComponent->mPrev = p_m_pAIScriptInterfaceComponent;
    this->m_pAIScriptInterfaceComponent.mNext = &this->m_pAIScriptInterfaceComponent;
  }
  this->m_pAIScriptInterfaceComponent.m_pPointer = 0i64;
  v16 = p_m_pAIScriptInterfaceComponent->mPrev;
  v17 = this->m_pAIScriptInterfaceComponent.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  p_m_pAIScriptInterfaceComponent->mPrev = p_m_pAIScriptInterfaceComponent;
  this->m_pAIScriptInterfaceComponent.mNext = &this->m_pAIScriptInterfaceComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v19 = p_m_pAIEntityComponent->mPrev;
    v20 = this->m_pAIEntityComponent.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v21 = p_m_pAIEntityComponent->mPrev;
  v22 = this->m_pAIEntityComponent.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  v23 = v2->mPrev;
  v24 = v2->mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  v2->mPrev = &v2->UFG::qNode<IFinishUpdate,IFinishUpdate>;
  v2->mNext = &v2->UFG::qNode<IFinishUpdate,IFinishUpdate>;
  this->Task<PerformScriptCommandTrack>::ITask::vfptr = (ITaskVtbl *)&ITask::`vftable;
  v25 = this->Task<PerformScriptCommandTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev;
  v26 = this->Task<PerformScriptCommandTrack>::ITask::UFG::qNode<ITask,ITask>::mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  this->Task<PerformScriptCommandTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<PerformScriptCommandTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1677
// RVA: 0x298B70
void __fastcall TestPathToTargetTask::TestPathToTargetTask(TestPathToTargetTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<TestPathToTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&TestPathToTargetTask::`vftable;
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::RebindingComponentHandle<UFG::NavComponent,0>(&this->m_navComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&this->m_targetingSysComponent);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&this->m_AIEntityComponent);
  UFG::FindPathDeferredQuery::FindPathDeferredQuery(&this->m_PathQueryInput);
  this->m_PathQueryOutput.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  *(_QWORD *)&this->m_PathQueryOutput.m_id = 0i64;
  this->m_PathQueryOutput.m_status = Status_Undefined;
  this->m_PathQueryOutput.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathOutput::`vftable;
  this->m_PathQueryOutput.m_pPath.m_pNavPath = 0i64;
}

// File Line: 1678
// RVA: 0x29ED40
void __fastcall TestPathToTargetTask::~TestPathToTargetTask(TestPathToTargetTask *this)
{
  UFG::FindPathOutput *p_m_PathQueryOutput; // rdi
  UFG::NavPath *m_pNavPath; // rcx
  UFG::qNode<ITask,ITask> *mPrev; // rcx
  UFG::qNode<ITask,ITask> *mNext; // rax

  this->vfptr = (ITaskVtbl *)&TestPathToTargetTask::`vftable;
  p_m_PathQueryOutput = &this->m_PathQueryOutput;
  m_pNavPath = this->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( m_pNavPath )
  {
    if ( m_pNavPath->m_uRefCount-- == 1 )
      m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
  }
  p_m_PathQueryOutput->vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  this->m_PathQueryInput.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_AIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_targetingSysComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_navComponent);
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

