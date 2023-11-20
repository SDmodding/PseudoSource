// File Line: 9
// RVA: 0x1030B0
void __fastcall UFG::Daemon::Daemon(UFG::Daemon *this, UFG::DaemonType type, UFG::DaemonExecutionStage stage, unsigned int internalTypesCount)
{
  UFG::Daemon *v4; // rbx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // edx
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int i; // edx

  v4 = this;
  this->vfptr = (UFG::DaemonVtbl *)&UFG::Daemon::`vftable;
  this->m_type = type;
  this->m_stage = stage;
  this->m_internalTypesCount = internalTypesCount;
  this->m_queryLookupTable.p = 0i64;
  *(_QWORD *)&this->m_queryLookupTable.size = 0i64;
  v5 = this->m_internalTypesCount;
  v6 = this->m_queryLookupTable.size;
  v7 = v5 - v6;
  if ( v7 <= 0 )
  {
    v11 = -v7;
    if ( v11 )
    {
      if ( v11 < v6 )
        v4->m_queryLookupTable.size = v6 - v11;
      else
        v4->m_queryLookupTable.size = 0;
    }
  }
  else
  {
    v8 = v6 + v7;
    v9 = v4->m_queryLookupTable.capacity;
    if ( v6 + v7 > v9 )
    {
      if ( v9 )
        v10 = 2 * v9;
      else
        v10 = 1;
      for ( ; v10 < v8; v10 *= 2 )
        ;
      if ( v10 <= 2 )
        v10 = 2;
      if ( v10 - v8 > 0x10000 )
        v10 = v8 + 0x10000;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v4->m_queryLookupTable,
        v10,
        "Daemon");
    }
    v4->m_queryLookupTable.size = v8;
  }
  for ( i = 0; i < v4->m_internalTypesCount; ++i )
    v4->m_queryLookupTable.p[i] = 0i64;
}

// File Line: 21
// RVA: 0x1031A0
void __fastcall UFG::Daemon::~Daemon(UFG::Daemon *this)
{
  UFG::Daemon *v1; // rbx
  UFG::qArray<UFG::DaemonQueryInput const *,0> **v2; // rcx

  v1 = this;
  this->vfptr = (UFG::DaemonVtbl *)&UFG::Daemon::`vftable;
  v2 = this->m_queryLookupTable.p;
  if ( v2 )
    operator delete[](v2);
  v1->m_queryLookupTable.p = 0i64;
  *(_QWORD *)&v1->m_queryLookupTable.size = 0i64;
}

// File Line: 26
// RVA: 0x103640
void __fastcall UFG::Daemon::RegisterQueueableQueryType(UFG::Daemon *this, __int64 internalType, UFG::qArray<UFG::DaemonQueryInput const *,0> *queriesArray)
{
  UFG::qArray<UFG::DaemonQueryInput const *,0> **v3; // rax

  if ( (unsigned int)internalType < this->m_queryLookupTable.size )
  {
    v3 = this->m_queryLookupTable.p;
    internalType = (unsigned int)internalType;
    if ( !v3[(unsigned int)internalType] )
      v3[internalType] = queriesArray;
  }
}

// File Line: 43
// RVA: 0x103710
void __fastcall UFG::Daemon::SubmitQueueableQuery(UFG::Daemon *this, UFG::DaemonQueryInput *input)
{
  UFG::DaemonQueryInput *v2; // rsi
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v3; // rdi
  unsigned int v4; // edx
  __int64 v5; // rbp
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **v8; // rax

  v2 = input;
  if ( (unsigned int)(input->m_mode - 1) <= 1 )
  {
    v3 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)this->m_queryLookupTable.p[input->m_internalType];
    if ( v3 )
    {
      v4 = v3->capacity;
      v5 = v3->size;
      v6 = v5 + 1;
      if ( (signed int)v5 + 1 > v4 )
      {
        if ( v4 )
          v7 = 2 * v4;
        else
          v7 = 1;
        for ( ; v7 < v6; v7 *= 2 )
          ;
        if ( v7 <= 2 )
          v7 = 2;
        if ( v7 - v6 > 0x10000 )
          v7 = v5 + 65537;
        UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v3, v7, "Daemon::SubmitQueueableQuery()");
      }
      v8 = v3->p;
      v3->size = v6;
      v8[v5] = (UFG::qReflectInventoryBase *)v2;
    }
  }
}

