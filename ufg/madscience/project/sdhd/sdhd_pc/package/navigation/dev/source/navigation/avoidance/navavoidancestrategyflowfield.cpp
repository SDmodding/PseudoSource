// File Line: 14
// RVA: 0xFB4D0
void __fastcall UFG::NavAvoidanceStrategyFlowField::NavAvoidanceStrategyFlowField(
        UFG::NavAvoidanceStrategyFlowField *this)
{
  UFG::NavAvoidanceStrategy::NavAvoidanceStrategy(this);
  this->vfptr = (UFG::NavAvoidanceStrategyVtbl *)&UFG::NavAvoidanceStrategyFlowField::`vftable;
}

// File Line: 22
// RVA: 0x102B50
void __fastcall UFG::NavAvoidanceStrategyFlowField::Update(
        UFG::NavAvoidanceStrategyFlowField *this,
        UFG::UpdatePhase phase,
        float deltaTime)
{
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *i; // rax
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *j; // rbx
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *k; // rbx
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *m; // rbx

  if ( phase )
  {
    if ( phase == UPDATE_PHASE_PART3 )
    {
      if ( UFG::NavModuleLocalFlowField::mpTaskGroup )
      {
        UFG::qTaskManager::Sync(&UFG::gTaskManager, UFG::NavModuleLocalFlowField::mpTaskGroup);
        UFG::NavModuleLocalFlowField::mpTaskGroup = 0i64;
      }
      for ( i = UFG::NavComponent::s_NavComponentList.mNode.mNext - 4;
            i != (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)aVtstatisticsUf;
            i = i[4].mNext - 4 )
      {
        ;
      }
    }
  }
  else
  {
    for ( j = UFG::AIInterestComponent::s_AIInterestComponentList.mNode.mNext - 5;
          j != (UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *)(&UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mRequestedSPUEnabled
                                                                               + 1);
          j = j[5].mNext - 5 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *))j[4].mPrev->mNext)(&j[4]);
    }
    for ( k = UFG::AvoidanceController::s_AvoidanceControllerList.mNode.mNext - 5;
          k != (UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *)(&UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mRequestedSPUEnabled
                                                                               + 9);
          k = k[5].mNext - 5 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *))k[4].mPrev->mNext)(&k[4]);
    }
    for ( m = UFG::NavComponent::s_NavComponentList.mNode.mNext - 4;
          m != (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)aVtstatisticsUf;
          m = m[4].mNext - 4 )
    {
      UFG::NavModuleLocalFlowField::QueueFlowTask((UFG::NavModuleLocalFlowField *)m[9].mNext);
    }
    if ( UFG::NavModuleLocalFlowField::mpTaskGroup )
      UFG::qTaskManager::Queue(&UFG::gTaskManager, UFG::NavModuleLocalFlowField::mpTaskGroup);
  }
}

// File Line: 65
// RVA: 0x102460
void __fastcall UFG::NavAvoidanceStrategyFlowField::SetLocalModuleFor(
        UFG::NavAvoidanceStrategyFlowField *this,
        UFG::NavComponent *pNavComponent)
{
  UFG::NavComponent::SetLocalModule<UFG::NavModuleLocalFlowField>(pNavComponent);
}

