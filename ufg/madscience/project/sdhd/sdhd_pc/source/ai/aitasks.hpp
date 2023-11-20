// File Line: 132
// RVA: 0x298840
void __fastcall PerformScriptCommandTask::PerformScriptCommandTask(PerformScriptCommandTask *this)
{
  PerformScriptCommandTask *v1; // rdx
  UFG::qNode<ITask,ITask> *v2; // rax
  IFinishUpdate *v3; // rcx
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v5; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::AIScriptInterfaceComponent> *v6; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TSActorComponent> *v7; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v8; // [rsp+28h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<PerformScriptCommandTrack>::`vftable;
  v3 = (IFinishUpdate *)&this->vfptr;
  v4 = (UFG::qNode<IFinishUpdate,IFinishUpdate> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (IFinishUpdateVtbl *)&IFinishUpdate::`vftable;
  v1->vfptr = (ITaskVtbl *)&PerformScriptCommandTask::`vftable{for `Task<PerformScriptCommandTrack>};
  v3->vfptr = (IFinishUpdateVtbl *)&PerformScriptCommandTask::`vftable{for `IFinishUpdate};
  v5 = &v1->m_pAIEntityComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v6 = &v1->m_pAIScriptInterfaceComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v1->m_pAIScriptInterfaceComponent.m_pPointer = 0i64;
  v7 = &v1->m_pActorComponent;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pActorComponent.m_pPointer = 0i64;
  v8 = &v1->m_pActionTreeComponent;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v1->m_pActionTreeComponent.m_pPointer = 0i64;
}

// File Line: 133
// RVA: 0x29D0C0
void __fastcall PerformScriptCommandTask::~PerformScriptCommandTask(PerformScriptCommandTask *this)
{
  PerformScriptCommandTask *v1; // r8
  IFinishUpdate *v2; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TSActorComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIScriptInterfaceComponent> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v23; // rdx
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v24; // rcx
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v25; // rax
  UFG::qNode<ITask,ITask> *v26; // rdx
  UFG::qNode<ITask,ITask> *v27; // rcx
  UFG::qNode<ITask,ITask> *v28; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&PerformScriptCommandTask::`vftable{for `Task<PerformScriptCommandTrack>};
  v2 = (IFinishUpdate *)&this->vfptr;
  this->vfptr = (IFinishUpdateVtbl *)&PerformScriptCommandTask::`vftable{for `IFinishUpdate};
  v3 = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  v6 = v3->mPrev;
  v7 = v3->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v8 = &v1->m_pActorComponent;
  if ( v1->m_pActorComponent.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v1->m_pActorComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v1->m_pActorComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pActorComponent.mPrev;
  }
  v1->m_pActorComponent.m_pPointer = 0i64;
  v11 = v8->mPrev;
  v12 = v1->m_pActorComponent.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v1->m_pActorComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pActorComponent.mPrev;
  v13 = &v1->m_pAIScriptInterfaceComponent;
  if ( v1->m_pAIScriptInterfaceComponent.m_pPointer )
  {
    v14 = v13->mPrev;
    v15 = v1->m_pAIScriptInterfaceComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v1->m_pAIScriptInterfaceComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIScriptInterfaceComponent.mPrev;
  }
  v1->m_pAIScriptInterfaceComponent.m_pPointer = 0i64;
  v16 = v13->mPrev;
  v17 = v1->m_pAIScriptInterfaceComponent.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v1->m_pAIScriptInterfaceComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIScriptInterfaceComponent.mPrev;
  v18 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v19 = v18->mPrev;
    v20 = v1->m_pAIEntityComponent.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v21 = v18->mPrev;
  v22 = v1->m_pAIEntityComponent.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v23 = (UFG::qNode<IFinishUpdate,IFinishUpdate> *)&v2->mPrev;
  v24 = v2->mPrev;
  v25 = v2->mNext;
  v24->mNext = v25;
  v25->mPrev = v24;
  v23->mPrev = v23;
  v23->mNext = v23;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v26 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v27 = v1->mPrev;
  v28 = v1->mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  v26->mPrev = v26;
  v26->mNext = v26;
}

// File Line: 1677
// RVA: 0x298B70
void __fastcall TestPathToTargetTask::TestPathToTargetTask(TestPathToTargetTask *this)
{
  TestPathToTargetTask *v1; // rbx
  UFG::qNode<ITask,ITask> *v2; // rax
  signed __int64 v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<TestPathToTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&TestPathToTargetTask::`vftable;
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::RebindingComponentHandle<UFG::NavComponent,0>(&this->m_navComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&v1->m_targetingSysComponent);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&v1->m_AIEntityComponent);
  UFG::FindPathDeferredQuery::FindPathDeferredQuery(&v1->m_PathQueryInput);
  v3 = (signed __int64)&v1->m_PathQueryOutput;
  *(_OWORD *)v3 = (unsigned __int64)&UFG::DaemonQueryOutput::`vftable;
  *(_DWORD *)(v3 + 16) = 0;
  *(_QWORD *)v3 = &UFG::FindPathOutput::`vftable;
  v1->m_PathQueryOutput.m_pPath.m_pNavPath = 0i64;
}

// File Line: 1678
// RVA: 0x29ED40
void __fastcall TestPathToTargetTask::~TestPathToTargetTask(TestPathToTargetTask *this)
{
  TestPathToTargetTask *v1; // rbx
  UFG::FindPathOutput *v2; // rdi
  UFG::NavPath *v3; // rcx
  bool v4; // zf
  UFG::qNode<ITask,ITask> *v5; // rdx
  UFG::qNode<ITask,ITask> *v6; // rcx
  UFG::qNode<ITask,ITask> *v7; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&TestPathToTargetTask::`vftable;
  v2 = &this->m_PathQueryOutput;
  v3 = this->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( v3 )
  {
    v4 = v3->m_uRefCount-- == 1;
    if ( v4 )
      v3->vfptr->__vecDelDtor(v3, 1u);
  }
  v2->vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  v1->m_PathQueryInput.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_AIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_targetingSysComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_navComponent);
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v5 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

