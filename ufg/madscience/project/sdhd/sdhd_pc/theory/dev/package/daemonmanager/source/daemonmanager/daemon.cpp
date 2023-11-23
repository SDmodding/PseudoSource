// File Line: 9
// RVA: 0x1030B0
void __fastcall UFG::Daemon::Daemon(
        UFG::Daemon *this,
        UFG::DaemonType type,
        UFG::DaemonExecutionStage stage,
        unsigned int internalTypesCount)
{
  unsigned int m_internalTypesCount; // eax
  unsigned int size; // ecx
  int v7; // eax
  unsigned int v8; // edi
  unsigned int capacity; // edx
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int i; // edx

  this->vfptr = (UFG::DaemonVtbl *)&UFG::Daemon::`vftable;
  this->m_type = type;
  this->m_stage = stage;
  this->m_internalTypesCount = internalTypesCount;
  this->m_queryLookupTable.p = 0i64;
  *(_QWORD *)&this->m_queryLookupTable.size = 0i64;
  m_internalTypesCount = this->m_internalTypesCount;
  size = this->m_queryLookupTable.size;
  v7 = m_internalTypesCount - size;
  if ( v7 <= 0 )
  {
    v11 = -v7;
    if ( v11 )
    {
      if ( v11 < size )
        this->m_queryLookupTable.size = size - v11;
      else
        this->m_queryLookupTable.size = 0;
    }
  }
  else
  {
    v8 = size + v7;
    capacity = this->m_queryLookupTable.capacity;
    if ( size + v7 > capacity )
    {
      if ( capacity )
        v10 = 2 * capacity;
      else
        v10 = 1;
      for ( ; v10 < v8; v10 *= 2 )
        ;
      if ( v10 <= 2 )
        v10 = 2;
      if ( v10 - v8 > 0x10000 )
        v10 = v8 + 0x10000;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_queryLookupTable,
        v10,
        "Daemon");
    }
    this->m_queryLookupTable.size = v8;
  }
  for ( i = 0; i < this->m_internalTypesCount; ++i )
    this->m_queryLookupTable.p[i] = 0i64;
}

// File Line: 21
// RVA: 0x1031A0
void __fastcall UFG::Daemon::~Daemon(UFG::Daemon *this)
{
  UFG::qArray<UFG::DaemonQueryInput const *,0> **p; // rcx

  this->vfptr = (UFG::DaemonVtbl *)&UFG::Daemon::`vftable;
  p = this->m_queryLookupTable.p;
  if ( p )
    operator delete[](p);
  this->m_queryLookupTable.p = 0i64;
  *(_QWORD *)&this->m_queryLookupTable.size = 0i64;
}

// File Line: 26
// RVA: 0x103640
void __fastcall UFG::Daemon::RegisterQueueableQueryType(
        UFG::Daemon *this,
        unsigned int internalType,
        UFG::qArray<UFG::DaemonQueryInput const *,0> *queriesArray)
{
  UFG::qArray<UFG::DaemonQueryInput const *,0> **p; // rax

  if ( internalType < this->m_queryLookupTable.size )
  {
    p = this->m_queryLookupTable.p;
    if ( !p[internalType] )
      p[internalType] = queriesArray;
  }
}

// File Line: 43
// RVA: 0x103710
void __fastcall UFG::Daemon::SubmitQueueableQuery(UFG::Daemon *this, UFG::qReflectInventoryBase *input)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v3; // rdi
  unsigned int capacity; // edx
  __int64 size; // rbp
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **p; // rax

  if ( (unsigned int)(LODWORD(input->mBaseNode.mParent) - 1) <= 1 )
  {
    v3 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)this->m_queryLookupTable.p[HIDWORD(input->mBaseNode.mUID)];
    if ( v3 )
    {
      capacity = v3->capacity;
      size = v3->size;
      v6 = size + 1;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v7 = 2 * capacity;
        else
          v7 = 1;
        for ( ; v7 < v6; v7 *= 2 )
          ;
        if ( v7 <= 2 )
          v7 = 2;
        if ( v7 - v6 > 0x10000 )
          v7 = size + 65537;
        UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v3, v7, "Daemon::SubmitQueueableQuery()");
      }
      p = v3->p;
      v3->size = v6;
      p[size] = input;
    }
  }
}

