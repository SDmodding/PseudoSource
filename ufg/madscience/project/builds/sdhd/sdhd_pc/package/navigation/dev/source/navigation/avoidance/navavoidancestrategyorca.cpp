// File Line: 13
// RVA: 0xF6190
void __fastcall UFG::NavAvoidanceStrategyORCA::NavAvoidanceStrategyORCA(UFG::NavAvoidanceStrategyORCA *this)
{
  UFG::NavAvoidanceStrategyORCA *v1; // rsi
  signed int v2; // ebx
  char *v3; // rax
  _DWORD *v4; // rdi
  RVO::Vector2 position; // [rsp+68h] [rbp+10h]

  v1 = this;
  UFG::NavAvoidanceStrategy::NavAvoidanceStrategy((UFG::NavAvoidanceStrategy *)&this->vfptr);
  v1->vfptr = (UFG::NavAvoidanceStrategyVtbl *)&UFG::NavAvoidanceStrategyORCA::`vftable';
  v2 = 0;
  v1->mNumActiveIndexes = 0;
  v3 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  position = (RVO::Vector2)v3;
  if ( v3 )
  {
    *(_QWORD *)v3 = 0i64;
    *((_QWORD *)v3 + 1) = 0i64;
    *((_QWORD *)v3 + 2) = 0i64;
    *((_QWORD *)v3 + 3) = 0i64;
    *((_DWORD *)v3 + 8) = 0;
    *((_QWORD *)v3 + 5) = 0i64;
    *((_QWORD *)v3 + 6) = 0i64;
    *((_QWORD *)v3 + 7) = 0i64;
    *((_DWORD *)v3 + 16) = 1065353216;
  }
  else
  {
    v3 = 0i64;
  }
  v1->mpSimulator = (RVO::RVOSimulator *)v3;
  position = 0i64;
  RVO::RVOSimulator::setAgentDefaults((RVO::RVOSimulator *)v3, 20.0, 0xAui64, 10.0, 10.0, 0.0, 2.0, &position);
  position = 0i64;
  v4 = v1->mIndexes;
  do
  {
    *v4 = v2;
    RVO::RVOSimulator::addAgent(v1->mpSimulator, &position);
    ++v2;
    ++v4;
  }
  while ( v2 < 500 );
}

// File Line: 32
// RVA: 0xF6E20
void __fastcall UFG::NavAvoidanceStrategyORCA::Update(UFG::NavAvoidanceStrategyORCA *this, UFG::UpdatePhase phase, float deltaTime)
{
  __int32 v3; // edx
  RVO::RVOSimulator *v4; // rcx
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *i; // rbx

  if ( phase )
  {
    v3 = phase - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        v4 = this->mpSimulator;
        v4->timeStep_ = deltaTime;
        RVO::RVOSimulator::doStep(v4);
      }
    }
    else
    {
      UFG::TicketBoothManager::UpdateBooth(
        UFG::TicketBoothManager::mpSingleton,
        TICKETBOOTH_NAVLOCAL_GATHEROBSTACLE,
        deltaTime);
    }
  }
  else
  {
    for ( i = UFG::NavComponent::s_NavComponentList.mNode.mNext - 4;
          i != (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)(&UFG::NavComponent::s_NavComponentList - 4);
          i = i[4].mNext - 4 )
    {
      ((void (*)(void))i[9].mNext->mPrev[5].mNext)();
    }
  }
}

// File Line: 61
// RVA: 0xF6DE0
void __fastcall UFG::NavAvoidanceStrategyORCA::SetLocalModuleFor(UFG::NavAvoidanceStrategyORCA *this, UFG::NavComponent *pNavComponent)
{
  UFG::NavAvoidanceStrategyORCA *v2; // rbx
  UFG::NavComponent *v3; // rdi

  v2 = this;
  v3 = pNavComponent;
  UFG::NavComponent::SetLocalModule<UFG::NavModuleLocalORCA>(pNavComponent);
  UFG::NavModuleLocalORCA::Init((UFG::NavModuleLocalORCA *)v3->m_pNavModuleLocal, v2);
}

// File Line: 78
// RVA: 0xF6D50
void __fastcall UFG::NavAvoidanceStrategyORCA::ReturnAgentIndex(UFG::NavAvoidanceStrategyORCA *this, unsigned int index)
{
  __int64 v2; // r11
  UFG::NavAvoidanceStrategyORCA *v3; // r10
  __int64 v4; // rdx
  unsigned int v5; // ecx
  __int64 v6; // rax

  v2 = index;
  v3 = this;
  this->mpSimulator->agents_._Myfirst[index]->enabled = 0;
  this->mpSimulator->agents_._Myfirst[index]->position_ = 0i64;
  v4 = 0i64;
  this->mpSimulator->agents_._Myfirst[v2]->radius_ = 0.0;
  v5 = this->mNumActiveIndexes;
  if ( v5 )
  {
    while ( v3->mIndexes[v4] != (_DWORD)v2 )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= v5 )
        return;
    }
    v6 = v5 - 1;
    v3->mNumActiveIndexes = v6;
    v3->mIndexes[v4] = v3->mIndexes[v6];
    v3->mIndexes[v3->mNumActiveIndexes] = v2;
  }
}

