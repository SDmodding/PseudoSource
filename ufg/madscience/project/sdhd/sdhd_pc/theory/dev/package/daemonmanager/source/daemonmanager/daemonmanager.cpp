// File Line: 16
// RVA: 0x103450
void UFG::DaemonManager::Create(void)
{
  char *v0; // rax

  v0 = UFG::qMalloc(0x20ui64, "DaemonManager", 0i64);
  if ( v0 )
  {
    *((_QWORD *)v0 + 1) = 0i64;
    *(_QWORD *)v0 = 0i64;
    *((_QWORD *)v0 + 3) = 0i64;
    *((_QWORD *)v0 + 2) = 0i64;
    UFG::DaemonManager::m_spDaemonManager = (UFG::DaemonManager *)v0;
  }
  else
  {
    UFG::DaemonManager::m_spDaemonManager = 0i64;
  }
}

// File Line: 22
// RVA: 0x1035A0
UFG::DaemonManager *__fastcall UFG::DaemonManager::Instance()
{
  return UFG::DaemonManager::m_spDaemonManager;
}

// File Line: 31
// RVA: 0x1033D0
bool __fastcall UFG::CompareDaemonsByStage(UFG::Daemon *const *a, UFG::Daemon *const *b)
{
  return (*a)->m_stage > (*b)->m_stage;
}

// File Line: 54
// RVA: 0x103240
void __fastcall UFG::DaemonManager::BeginInitialization(UFG::DaemonManager *this)
{
  UFG::DaemonManager *v1; // rbx
  unsigned __int64 v2; // rax
  char *v3; // rax
  char *v4; // rdi
  signed __int64 v5; // r9
  signed __int64 v6; // r8

  v1 = this;
  if ( this->m_aDaemons.capacity < 1 && this->m_aDaemons.size != 1 )
  {
    v2 = 8i64;
    if ( !is_mul_ok(1ui64, 8ui64) )
      v2 = -1i64;
    v3 = UFG::qMalloc(v2, "DaemonManager", 0i64);
    v4 = v3;
    if ( v1->m_aDaemons.p )
    {
      v5 = 0i64;
      if ( v1->m_aDaemons.size )
      {
        do
        {
          v6 = v5;
          v5 = (unsigned int)(v5 + 1);
          *(_QWORD *)&v3[v6 * 8] = v1->m_aDaemons.p[v6];
        }
        while ( (unsigned int)v5 < v1->m_aDaemons.size );
      }
      operator delete[](v1->m_aDaemons.p);
    }
    v1->m_aDaemons.p = (UFG::Daemon **)v4;
    v1->m_aDaemons.capacity = 1;
  }
}

// File Line: 61
// RVA: 0x1035B0
void __fastcall UFG::DaemonManager::RegisterDaemon(UFG::RoadNetworkVisibleAreaEdgeManager *this, UFG::RoadNetworkVisibleAreaEdge *edge)
{
  __int64 v2; // rsi
  UFG::RoadNetworkVisibleAreaEdge *v3; // rbp
  unsigned int v4; // edx
  unsigned int v5; // ebx
  UFG::RoadNetworkVisibleAreaEdgeManager *v6; // rdi
  unsigned int v7; // edx
  UFG::RoadNetworkVisibleAreaEdge **v8; // rax

  v2 = this->mEdgeCollection.size;
  v3 = edge;
  v4 = this->mEdgeCollection.capacity;
  v5 = v2 + 1;
  v6 = this;
  if ( (signed int)v2 + 1 > v4 )
  {
    if ( v4 )
      v7 = 2 * v4;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v5 > 0x10000 )
      v7 = v2 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)this,
      v7,
      "qArray.Add");
  }
  v8 = v6->mEdgeCollection.p;
  v6->mEdgeCollection.size = v5;
  v8[v2] = v3;
}

// File Line: 68
// RVA: 0x1034A0
void __fastcall UFG::DaemonManager::EndInitialization(UFG::DaemonManager *this)
{
  UFG::qArray<unsigned long,0> *v1; // rsi
  unsigned int v2; // ecx
  __int64 v3; // rbp
  unsigned int v4; // edx
  unsigned int v5; // ebx
  unsigned int v6; // eax
  __int64 v7; // rcx
  __int64 v8; // rdx
  __int64 v9; // r8

  v1 = (UFG::qArray<unsigned long,0> *)this;
  UFG::qArray<UFG::Daemon *,0>::BubbleSortCorrect(&this->m_aDaemons, UFG::CompareDaemonsByStage);
  v2 = v1[1].size;
  v3 = v1->size;
  v4 = 1;
  v5 = 0;
  if ( (signed int)(1 - v2) <= 0 )
  {
    if ( v2 != 1 )
      v1[1].size = v2 - 1 < v2;
  }
  else
  {
    v6 = v1[1].capacity;
    if ( v6 < 1 )
    {
      if ( v6 )
        v4 = 2 * v6;
      for ( ; v4 < 1; v4 *= 2 )
        ;
      if ( v4 <= 4 )
        v4 = 4;
      if ( v4 - 1 > 0x10000 )
        v4 = 65537;
      UFG::qArray<long,0>::Reallocate(v1 + 1, v4, "DaemonManager");
    }
    v1[1].size = 1;
  }
  if ( (_DWORD)v3 )
  {
    v7 = 0i64;
    v8 = v3;
    do
    {
      ++v7;
      v1[1].p[v7 - 1] = -1;
      --v8;
    }
    while ( v8 );
    if ( (_DWORD)v3 )
    {
      v9 = 0i64;
      do
      {
        v9 += 2i64;
        v1[1].p[*(unsigned int *)(*(_QWORD *)&v1->p[v9 - 2] + 8i64)] = v5++;
      }
      while ( v5 < (unsigned int)v3 );
    }
  }
}

// File Line: 107
// RVA: 0x1036C0
void __fastcall UFG::DaemonManager::SubmitQuery(UFG::DaemonManager *this, UFG::DaemonQueryInput *input, UFG::DaemonQueryOutput *output)
{
  __int64 v3; // r9
  __int64 v4; // r10
  UFG::Daemon *v5; // rcx

  v3 = (unsigned int)input->m_daemonType;
  input->m_pOutput = output;
  v4 = this->m_aDaemonMappings.p[v3];
  if ( (_DWORD)v4 != -1 )
  {
    v5 = this->m_aDaemons.p[v4];
    if ( input->m_mode )
    {
      output->m_status = 1;
      UFG::Daemon::SubmitQueueableQuery(v5, input);
    }
    else
    {
      output->m_status = 0;
      ((void (*)(void))v5->vfptr->SubmitImmediateQuery)();
    }
  }
}

// File Line: 137
// RVA: 0x1033A0
void __fastcall UFG::DaemonManager::CancelQuery(UFG::DaemonManager *this, UFG::DaemonQueryInput *query)
{
  __int64 v2; // r9

  if ( query->m_mode )
  {
    v2 = this->m_aDaemonMappings.p[query->m_daemonType];
    if ( (_DWORD)v2 != -1 )
      ((void (*)(void))this->m_aDaemons.p[v2]->vfptr->CancelQueueableQuery)();
  }
}

// File Line: 165
// RVA: 0x103660
void __fastcall UFG::DaemonManager::StartUpdate(UFG::DaemonManager *this, float dt)
{
  UFG::DaemonManager *v2; // rsi
  __int64 v3; // rdi
  __int64 v4; // rbx

  v2 = this;
  if ( this->m_aDaemons.size )
  {
    v3 = this->m_aDaemons.size;
    v4 = 0i64;
    do
    {
      ((void (*)(void))v2->m_aDaemons.p[v4]->vfptr->StartUpdate)();
      ++v4;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 175
// RVA: 0x1033F0
void __fastcall UFG::DaemonManager::CompleteUpdate(UFG::DaemonManager *this, float dt)
{
  UFG::DaemonManager *v2; // rsi
  __int64 v3; // rdi
  __int64 v4; // rbx

  v2 = this;
  if ( this->m_aDaemons.size )
  {
    v3 = this->m_aDaemons.size;
    v4 = 0i64;
    do
    {
      ((void (*)(void))v2->m_aDaemons.p[v4]->vfptr->CompleteUpdate)();
      ++v4;
      --v3;
    }
    while ( v3 );
  }
}

