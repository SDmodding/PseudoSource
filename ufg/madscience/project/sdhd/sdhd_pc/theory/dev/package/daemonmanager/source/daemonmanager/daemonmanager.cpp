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
  unsigned __int64 v2; // rax
  char *v3; // rax
  UFG::Daemon **v4; // rdi
  __int64 i; // r9
  __int64 v6; // r8

  if ( !this->m_aDaemons.capacity && this->m_aDaemons.size != 1 )
  {
    v2 = 8i64;
    if ( !is_mul_ok(1ui64, 8ui64) )
      v2 = -1i64;
    v3 = UFG::qMalloc(v2, "DaemonManager", 0i64);
    v4 = (UFG::Daemon **)v3;
    if ( this->m_aDaemons.p )
    {
      for ( i = 0i64; (unsigned int)i < this->m_aDaemons.size; *(_QWORD *)&v3[v6 * 8] = this->m_aDaemons.p[v6] )
      {
        v6 = i;
        i = (unsigned int)(i + 1);
      }
      operator delete[](this->m_aDaemons.p);
    }
    this->m_aDaemons.p = v4;
    this->m_aDaemons.capacity = 1;
  }
}

// File Line: 61
// RVA: 0x1035B0
void __fastcall UFG::DaemonManager::RegisterDaemon(
        UFG::RoadNetworkVisibleAreaEdgeManager *this,
        UFG::RoadNetworkVisibleAreaEdge *edge)
{
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v5; // ebx
  unsigned int v7; // edx
  UFG::RoadNetworkVisibleAreaEdge **p; // rax

  size = this->mEdgeCollection.size;
  capacity = this->mEdgeCollection.capacity;
  v5 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v5 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)this,
      v7,
      "qArray.Add");
  }
  p = this->mEdgeCollection.p;
  this->mEdgeCollection.size = v5;
  p[size] = edge;
}

// File Line: 68
// RVA: 0x1034A0
void __fastcall UFG::DaemonManager::EndInitialization(UFG::DaemonManager *this)
{
  unsigned int size; // ecx
  __int64 v3; // rbp
  unsigned int v4; // ebx
  __int64 v5; // rcx
  __int64 v6; // rdx
  __int64 v7; // r8

  UFG::qArray<UFG::Daemon *,0>::BubbleSortCorrect(&this->m_aDaemons, UFG::CompareDaemonsByStage);
  size = this->m_aDaemonMappings.size;
  v3 = this->m_aDaemons.size;
  v4 = 0;
  if ( (int)(1 - size) <= 0 )
  {
    if ( size != 1 )
      this->m_aDaemonMappings.size = size - 1 < size;
  }
  else
  {
    if ( !this->m_aDaemonMappings.capacity )
      UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&this->m_aDaemonMappings, 4u, "DaemonManager");
    this->m_aDaemonMappings.size = 1;
  }
  if ( (_DWORD)v3 )
  {
    v5 = 0i64;
    v6 = v3;
    do
    {
      this->m_aDaemonMappings.p[v5++] = -1;
      --v6;
    }
    while ( v6 );
    v7 = 0i64;
    do
      this->m_aDaemonMappings.p[this->m_aDaemons.p[v7++]->m_type] = v4++;
    while ( v4 < (unsigned int)v3 );
  }
}

// File Line: 107
// RVA: 0x1036C0
void __fastcall UFG::DaemonManager::SubmitQuery(
        UFG::DaemonManager *this,
        UFG::DaemonQueryInput *input,
        UFG::DaemonQueryOutput *output)
{
  __int64 m_daemonType; // r9
  __int64 v4; // r10
  UFG::Daemon *v5; // rcx

  m_daemonType = (unsigned int)input->m_daemonType;
  input->m_pOutput = output;
  v4 = this->m_aDaemonMappings.p[m_daemonType];
  if ( (_DWORD)v4 != -1 )
  {
    v5 = this->m_aDaemons.p[v4];
    if ( input->m_mode )
    {
      output->m_status = Status_Submitted;
      UFG::Daemon::SubmitQueueableQuery(v5, input);
    }
    else
    {
      output->m_status = Status_Undefined;
      ((void (__fastcall *)(UFG::Daemon *))v5->vfptr->SubmitImmediateQuery)(v5);
    }
  }
}

// File Line: 137
// RVA: 0x1033A0
void __fastcall UFG::DaemonManager::CancelQuery(UFG::DaemonManager *this, UFG::DaemonQueryInput *query)
{
  __int64 v2; // r9
  UFG::Daemon *v3; // rcx

  if ( query->m_mode )
  {
    v2 = this->m_aDaemonMappings.p[query->m_daemonType];
    if ( (_DWORD)v2 != -1 )
    {
      v3 = this->m_aDaemons.p[v2];
      ((void (__fastcall *)(UFG::Daemon *))v3->vfptr->CancelQueueableQuery)(v3);
    }
  }
}

// File Line: 165
// RVA: 0x103660
void __fastcall UFG::DaemonManager::StartUpdate(UFG::DaemonManager *this, float dt)
{
  __int64 size; // rdi
  __int64 v4; // rbx

  if ( this->m_aDaemons.size )
  {
    size = this->m_aDaemons.size;
    v4 = 0i64;
    do
    {
      ((void (__fastcall *)(UFG::Daemon *))this->m_aDaemons.p[v4]->vfptr->StartUpdate)(this->m_aDaemons.p[v4]);
      ++v4;
      --size;
    }
    while ( size );
  }
}

// File Line: 175
// RVA: 0x1033F0
void __fastcall UFG::DaemonManager::CompleteUpdate(UFG::DaemonManager *this, float dt)
{
  __int64 size; // rdi
  __int64 v4; // rbx

  if ( this->m_aDaemons.size )
  {
    size = this->m_aDaemons.size;
    v4 = 0i64;
    do
    {
      ((void (__fastcall *)(UFG::Daemon *))this->m_aDaemons.p[v4]->vfptr->CompleteUpdate)(this->m_aDaemons.p[v4]);
      ++v4;
      --size;
    }
    while ( size );
  }
}

