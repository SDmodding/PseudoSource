// File Line: 13
// RVA: 0xF6190
void __fastcall UFG::NavAvoidanceStrategyORCA::NavAvoidanceStrategyORCA(UFG::NavAvoidanceStrategyORCA *this)
{
  int v2; // ebx
  char *v3; // rax
  unsigned int *mIndexes; // rdi
  RVO::Vector2 position; // [rsp+68h] [rbp+10h] BYREF

  UFG::NavAvoidanceStrategy::NavAvoidanceStrategy(this);
  this->vfptr = (UFG::NavAvoidanceStrategyVtbl *)&UFG::NavAvoidanceStrategyORCA::`vftable;
  v2 = 0;
  this->mNumActiveIndexes = 0;
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
  this->mpSimulator = (RVO::RVOSimulator *)v3;
  position = 0i64;
  RVO::RVOSimulator::setAgentDefaults((RVO::RVOSimulator *)v3, 20.0, 0xAui64, 10.0, 10.0, 0.0, 2.0, &position);
  position = 0i64;
  mIndexes = this->mIndexes;
  do
  {
    *mIndexes = v2;
    RVO::RVOSimulator::addAgent(this->mpSimulator, &position);
    ++v2;
    ++mIndexes;
  }
  while ( v2 < 500 );
}

// File Line: 32
// RVA: 0xF6E20
void __fastcall UFG::NavAvoidanceStrategyORCA::Update(
        UFG::NavAvoidanceStrategyORCA *this,
        UFG::UpdatePhase phase,
        float deltaTime)
{
  int v3; // edx
  RVO::RVOSimulator *mpSimulator; // rcx
  UFG::qList<UFG::NavComponent,UFG::NavComponent,1,0> *i; // rbx

  if ( phase )
  {
    v3 = phase - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        mpSimulator = this->mpSimulator;
        mpSimulator->timeStep_ = deltaTime;
        RVO::RVOSimulator::doStep(mpSimulator);
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
    for ( i = (UFG::qList<UFG::NavComponent,UFG::NavComponent,1,0> *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
          i != &UFG::NavComponent::s_NavComponentList - 4;
          i = (UFG::qList<UFG::NavComponent,UFG::NavComponent,1,0> *)&i[4].mNode.mNext[-4] )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::NavComponent,UFG::NavComponent> *))i[9].mNode.mNext->mPrev[5].mNext)(i[9].mNode.mNext);
    }
  }
}

// File Line: 61
// RVA: 0xF6DE0
void __fastcall UFG::NavAvoidanceStrategyORCA::SetLocalModuleFor(
        UFG::NavAvoidanceStrategyORCA *this,
        UFG::NavComponent *pNavComponent)
{
  UFG::NavComponent::SetLocalModule<UFG::NavModuleLocalORCA>(pNavComponent);
  UFG::NavModuleLocalORCA::Init((UFG::NavModuleLocalORCA *)pNavComponent->m_pNavModuleLocal, this);
}

// File Line: 78
// RVA: 0xF6D50
void __fastcall UFG::NavAvoidanceStrategyORCA::ReturnAgentIndex(
        UFG::NavAvoidanceStrategyORCA *this,
        unsigned int index)
{
  __int64 v2; // r11
  __int64 v4; // rdx
  unsigned int mNumActiveIndexes; // ecx
  __int64 v6; // rax

  v2 = index;
  this->mpSimulator->agents_._Myfirst[index]->enabled = 0;
  this->mpSimulator->agents_._Myfirst[index]->position_ = 0i64;
  v4 = 0i64;
  this->mpSimulator->agents_._Myfirst[v2]->radius_ = 0.0;
  mNumActiveIndexes = this->mNumActiveIndexes;
  if ( mNumActiveIndexes )
  {
    while ( this->mIndexes[v4] != (_DWORD)v2 )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= mNumActiveIndexes )
        return;
    }
    v6 = mNumActiveIndexes - 1;
    this->mNumActiveIndexes = v6;
    this->mIndexes[v4] = this->mIndexes[v6];
    this->mIndexes[this->mNumActiveIndexes] = v2;
  }
}

