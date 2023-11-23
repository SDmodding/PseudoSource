// File Line: 28
// RVA: 0xC7DE60
void __fastcall hkMemorySnapshot::hkMemorySnapshot(hkMemorySnapshot *this, hkMemoryAllocator *a)
{
  this->m_mem = a;
  this->m_allocations.m_capacityAndFlags = 0x80000000;
  this->m_allocations.m_data = 0i64;
  this->m_allocations.m_size = 0;
  this->m_providers.m_data = 0i64;
  this->m_providers.m_size = 0;
  this->m_providers.m_capacityAndFlags = 0x80000000;
  this->m_callTree.m_nodes.m_data = 0i64;
  this->m_callTree.m_nodes.m_size = 0;
  this->m_callTree.m_nodes.m_capacityAndFlags = 0x80000000;
  this->m_callTree.m_allocator = a;
  *(_QWORD *)&this->m_callTree.m_rootNode = -1i64;
}

// File Line: 33
// RVA: 0xC7DEB0
void __fastcall hkMemorySnapshot::hkMemorySnapshot(hkMemorySnapshot *this, hkMemorySnapshot *rhs)
{
  int v4; // ebp
  __int64 v5; // r15
  hkMemorySnapshot::Provider *v6; // rax
  __int64 m_size; // rcx
  hkMemorySnapshot::Provider *v8; // rbx

  this->m_mem = rhs->m_mem;
  this->m_allocations.m_data = 0i64;
  this->m_allocations.m_size = 0;
  this->m_allocations.m_capacityAndFlags = 0x80000000;
  this->m_providers.m_data = 0i64;
  this->m_providers.m_size = 0;
  this->m_providers.m_capacityAndFlags = 0x80000000;
  hkStackTracer::CallTree::CallTree(&this->m_callTree, &rhs->m_callTree);
  hkArrayBase<hkMemorySnapshot::Allocation>::_append(
    &this->m_allocations,
    this->m_mem,
    rhs->m_allocations.m_data,
    rhs->m_allocations.m_size);
  v4 = 0;
  if ( rhs->m_providers.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      if ( this->m_providers.m_size == (this->m_providers.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(this->m_mem, (const void **)&this->m_providers.m_data, 48);
      v6 = &this->m_providers.m_data[this->m_providers.m_size];
      if ( v6 )
      {
        v6->m_parentIndices.m_data = 0i64;
        v6->m_parentIndices.m_size = 0;
        v6->m_parentIndices.m_capacityAndFlags = 0x80000000;
      }
      m_size = this->m_providers.m_size;
      this->m_providers.m_size = m_size + 1;
      v8 = &this->m_providers.m_data[m_size];
      hkString::strNcpy(v8->m_name, rhs->m_providers.m_data[v4].m_name, 0x20u);
      hkArrayBase<unsigned int>::_append(
        (hkArrayBase<unsigned int> *)&v8->m_parentIndices,
        this->m_mem,
        (char *)rhs->m_providers.m_data[v5].m_parentIndices.m_data,
        rhs->m_providers.m_data[v5].m_parentIndices.m_size);
      ++v4;
      ++v5;
    }
    while ( v4 < rhs->m_providers.m_size );
  }
}

// File Line: 44
// RVA: 0xC7E000
void __fastcall hkMemorySnapshot::setAllocator(hkMemorySnapshot *this, hkMemoryAllocator *a)
{
  this->m_mem = a;
  this->m_callTree.m_allocator = a;
}

// File Line: 50
// RVA: 0xC7E010
void __fastcall hkMemorySnapshot::swap(hkMemorySnapshot *this, hkMemorySnapshot *m)
{
  hkMemorySnapshot::Allocation *m_data; // rax
  int m_capacityAndFlags; // r9d
  int m_size; // r8d
  hkMemorySnapshot::Provider *v6; // rax
  int v8; // ecx

  this->m_mem = m->m_mem;
  m_data = m->m_allocations.m_data;
  m_capacityAndFlags = m->m_allocations.m_capacityAndFlags;
  m_size = m->m_allocations.m_size;
  m->m_mem = 0i64;
  this->m_allocations.m_data = m_data;
  this->m_allocations.m_capacityAndFlags = m_capacityAndFlags;
  this->m_allocations.m_size = m_size;
  m->m_allocations.m_data = 0i64;
  m->m_allocations.m_size = 0;
  m->m_allocations.m_capacityAndFlags = 0x80000000;
  v6 = m->m_providers.m_data;
  v8 = m->m_providers.m_size;
  this->m_providers.m_capacityAndFlags = m->m_providers.m_capacityAndFlags;
  this->m_providers.m_size = v8;
  this->m_providers.m_data = v6;
  m->m_providers.m_data = 0i64;
  m->m_providers.m_size = 0;
  m->m_providers.m_capacityAndFlags = 0x80000000;
  hkStackTracer::CallTree::swap(&this->m_callTree, &m->m_callTree);
  hkString::memCpy(this->m_routerWiring, m->m_routerWiring, 0x14u);
}

// File Line: 61
// RVA: 0xC7E0B0
void __fastcall hkMemorySnapshot::clear(hkMemorySnapshot *this)
{
  hkMemoryAllocator *m_mem; // rcx
  int m_capacityAndFlags; // edx
  int v4; // esi
  __int64 v5; // rbp
  hkMemoryAllocator *v6; // rcx
  hkMemorySnapshot::Provider *v7; // rdi
  int v8; // r8d
  int v9; // r8d
  hkMemoryAllocator *v10; // rcx

  m_mem = this->m_mem;
  m_capacityAndFlags = this->m_allocations.m_capacityAndFlags;
  this->m_allocations.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_mem->vfptr->bufFree(m_mem, this->m_allocations.m_data, 24 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_allocations.m_data = 0i64;
  this->m_allocations.m_capacityAndFlags = 0x80000000;
  v4 = 0;
  if ( this->m_providers.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = this->m_mem;
      v7 = &this->m_providers.m_data[v5];
      v8 = v7->m_parentIndices.m_capacityAndFlags;
      v7->m_parentIndices.m_size = 0;
      if ( v8 >= 0 )
        v6->vfptr->bufFree(v6, v7->m_parentIndices.m_data, 4 * v8);
      ++v4;
      v7->m_parentIndices.m_data = 0i64;
      v7->m_parentIndices.m_capacityAndFlags = 0x80000000;
      ++v5;
    }
    while ( v4 < this->m_providers.m_size );
  }
  v9 = this->m_providers.m_capacityAndFlags;
  v10 = this->m_mem;
  this->m_providers.m_size = 0;
  if ( v9 >= 0 )
    v10->vfptr->bufFree(v10, this->m_providers.m_data, 48 * (v9 & 0x3FFFFFFF));
  this->m_providers.m_capacityAndFlags = 0x80000000;
  this->m_providers.m_data = 0i64;
}

// File Line: 71
// RVA: 0xC7E1B0
void __fastcall hkMemorySnapshot::~hkMemorySnapshot(hkMemorySnapshot *this)
{
  hkMemorySnapshot::clear(this);
  hkStackTracer::CallTree::~CallTree(&this->m_callTree);
}

// File Line: 76
// RVA: 0xC7E1E0
__int64 __fastcall hkMemorySnapshot::addProvider(hkMemorySnapshot *this, const char *name, int parent)
{
  unsigned int m_size; // ebp
  hkMemorySnapshot::Provider *v7; // rcx
  __int64 v8; // rcx
  hkMemorySnapshot::Provider *v9; // rsi

  m_size = this->m_providers.m_size;
  if ( m_size == (this->m_providers.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_mem, (const void **)&this->m_providers.m_data, 48);
  v7 = &this->m_providers.m_data[this->m_providers.m_size];
  if ( v7 )
  {
    v7->m_parentIndices.m_capacityAndFlags = 0x80000000;
    v7->m_parentIndices.m_data = 0i64;
    v7->m_parentIndices.m_size = 0;
  }
  v8 = this->m_providers.m_size;
  this->m_providers.m_size = v8 + 1;
  v9 = &this->m_providers.m_data[v8];
  hkString::strNcpy(v9->m_name, name, 0x1Fu);
  v9->m_name[31] = 0;
  if ( parent != -1 )
  {
    if ( v9->m_parentIndices.m_size == (v9->m_parentIndices.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(this->m_mem, (const void **)&v9->m_parentIndices.m_data, 4);
    v9->m_parentIndices.m_data[v9->m_parentIndices.m_size++] = parent;
  }
  return m_size;
}

// File Line: 87
// RVA: 0xC7E2D0
void __fastcall hkMemorySnapshot::addParentProvider(hkMemorySnapshot *this, int provider, int parent)
{
  hkMemorySnapshot::Provider *v4; // rbx

  v4 = &this->m_providers.m_data[provider];
  if ( v4->m_parentIndices.m_size == (v4->m_parentIndices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_mem, (const void **)&v4->m_parentIndices.m_data, 4);
  v4->m_parentIndices.m_data[v4->m_parentIndices.m_size++] = parent;
}

// File Line: 93
// RVA: 0xC7E330
__int64 __fastcall hkMemorySnapshot::addItem(
        hkMemorySnapshot *this,
        int id,
        hkEnum<enum hkMemorySnapshot::StatusBits,signed char> status,
        const void *address,
        int size)
{
  unsigned int m_size; // ebp
  hkArrayBase<hkMemorySnapshot::Allocation> *p_m_allocations; // rbx
  __int64 v9; // r8
  __int64 result; // rax
  __int64 v11; // r9

  m_size = this->m_allocations.m_size;
  p_m_allocations = &this->m_allocations;
  if ( m_size == (this->m_allocations.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_mem, (const void **)&p_m_allocations->m_data, 24);
  v9 = p_m_allocations->m_size;
  result = m_size;
  v11 = (__int64)&p_m_allocations->m_data[v9];
  p_m_allocations->m_size = v9 + 1;
  *(_DWORD *)(v11 + 12) = id;
  *(_DWORD *)(v11 + 8) = size;
  *(_QWORD *)v11 = address;
  *(_DWORD *)(v11 + 16) = -1;
  *(hkEnum<enum hkMemorySnapshot::StatusBits,signed char> *)(v11 + 20) = status;
  return result;
}

// File Line: 105
// RVA: 0xC7E3F0
void __fastcall hkMemorySnapshot::setCallStack(
        hkMemorySnapshot *this,
        int id,
        const unsigned __int64 *addresses,
        int numAddresses)
{
  hkStackTracer::CallTree *p_m_callTree; // rcx
  __int64 v5; // rbx

  p_m_callTree = &this->m_callTree;
  v5 = *(_QWORD *)&p_m_callTree[-2].m_nodes.m_size + 24i64 * id;
  *(_DWORD *)(v5 + 16) = hkStackTracer::CallTree::insertCallStack(p_m_callTree, addresses, numAddresses);
}

// File Line: 110
// RVA: 0xC7E3D0
void __fastcall hkMemorySnapshot::setRouterWiring(
        hkMemorySnapshot *this,
        int stack,
        int temp,
        int heap,
        int debug,
        int solver)
{
  this->m_routerWiring[0] = stack;
  this->m_routerWiring[1] = temp;
  this->m_routerWiring[3] = debug;
  this->m_routerWiring[2] = heap;
  this->m_routerWiring[4] = solver;
}

// File Line: 119
// RVA: 0xC7E860
_BOOL8 __fastcall compareAllocations(hkMemorySnapshot::Allocation *a, hkMemorySnapshot::Allocation *b)
{
  return a->m_start < b->m_start || a->m_start == b->m_start && a->m_size > b->m_size;
}

// File Line: 125
// RVA: 0xC7E430
void __fastcall hkMemorySnapshot::sort(hkMemorySnapshot *this)
{
  int m_size; // r8d

  m_size = this->m_allocations.m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkMemorySnapshot::Allocation,unsigned int (*)(hkMemorySnapshot::Allocation const &,hkMemorySnapshot::Allocation const &)>(
      this->m_allocations.m_data,
      0,
      m_size - 1,
      compareAllocations);
}

// File Line: 130
// RVA: 0xC7E460
void __fastcall hkMemorySnapshot::allocationDiff(
        hkMemorySnapshot *snapA,
        hkMemorySnapshot *snapB,
        hkArray<hkMemorySnapshot::Allocation,hkContainerHeapAllocator> *onlyInA,
        hkArray<hkMemorySnapshot::Allocation,hkContainerHeapAllocator> *onlyInB)
{
  hkMemorySnapshot::Allocation *m_data; // rdi
  hkMemorySnapshot::Allocation *v7; // rbx
  hkMemorySnapshot::Allocation *v8; // rbp
  hkMemorySnapshot::Allocation *v9; // r15
  const void *m_start; // rcx
  const void *v11; // rdx
  bool v12; // cf
  hkMemorySnapshot::Allocation *v13; // rdx
  hkMemorySnapshot::Allocation *v14; // rdx
  hkMemorySnapshot::Allocation *v15; // rdx
  hkMemorySnapshot::Allocation *v16; // rdx
  hkMemorySnapshot::Allocation *v17; // rdx
  hkMemorySnapshot::Allocation *v18; // rdx

  onlyInA->m_size = 0;
  onlyInB->m_size = 0;
  m_data = snapA->m_allocations.m_data;
  v7 = snapB->m_allocations.m_data;
  v8 = &m_data[snapA->m_allocations.m_size];
  v9 = &v7[snapB->m_allocations.m_size];
  if ( m_data >= v8 )
    goto LABEL_38;
  while ( v7 < v9 )
  {
    m_start = m_data->m_start;
    v11 = v7->m_start;
    v12 = m_data->m_start < v7->m_start;
    if ( m_data->m_start != v7->m_start )
      goto LABEL_18;
    if ( m_data->m_size != v7->m_size
      || m_data->m_sourceId != v7->m_sourceId
      || m_data->m_status.m_storage != v7->m_status.m_storage )
    {
      v12 = m_start < v11;
      if ( m_start == v11 )
      {
        if ( onlyInA->m_size == (onlyInA->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&onlyInA->m_data, 24);
        v13 = &onlyInA->m_data[onlyInA->m_size];
        if ( v13 )
        {
          v13->m_start = m_data->m_start;
          *(_QWORD *)&v13->m_size = *(_QWORD *)&m_data->m_size;
          *(_QWORD *)&v13->m_traceId = *(_QWORD *)&m_data->m_traceId;
        }
        ++onlyInA->m_size;
        if ( onlyInB->m_size == (onlyInB->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&onlyInB->m_data, 24);
        v14 = &onlyInB->m_data[onlyInB->m_size];
        if ( v14 )
        {
          v14->m_start = v7->m_start;
          *(_QWORD *)&v14->m_size = *(_QWORD *)&v7->m_size;
          *(_QWORD *)&v14->m_traceId = *(_QWORD *)&v7->m_traceId;
        }
        ++m_data;
      }
      else
      {
LABEL_18:
        if ( v12 )
        {
          if ( onlyInA->m_size == (onlyInA->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&onlyInA->m_data, 24);
          v15 = &onlyInA->m_data[onlyInA->m_size];
          if ( v15 )
          {
            v15->m_start = m_data->m_start;
            *(_QWORD *)&v15->m_size = *(_QWORD *)&m_data->m_size;
            *(_QWORD *)&v15->m_traceId = *(_QWORD *)&m_data->m_traceId;
          }
          ++onlyInA->m_size;
          ++m_data;
          goto LABEL_30;
        }
        if ( onlyInB->m_size == (onlyInB->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&onlyInB->m_data, 24);
        v16 = &onlyInB->m_data[onlyInB->m_size];
        if ( v16 )
        {
          v16->m_start = v7->m_start;
          *(_QWORD *)&v16->m_size = *(_QWORD *)&v7->m_size;
          *(_QWORD *)&v16->m_traceId = *(_QWORD *)&v7->m_traceId;
        }
      }
      ++onlyInB->m_size;
      goto LABEL_29;
    }
    ++m_data;
LABEL_29:
    ++v7;
LABEL_30:
    if ( m_data >= v8 )
      goto LABEL_38;
  }
  for ( ; m_data < v8; ++m_data )
  {
    if ( onlyInA->m_size == (onlyInA->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&onlyInA->m_data, 24);
    v17 = &onlyInA->m_data[onlyInA->m_size];
    if ( v17 )
    {
      v17->m_start = m_data->m_start;
      *(_QWORD *)&v17->m_size = *(_QWORD *)&m_data->m_size;
      *(_QWORD *)&v17->m_traceId = *(_QWORD *)&m_data->m_traceId;
    }
    ++onlyInA->m_size;
  }
LABEL_38:
  while ( v7 < v9 )
  {
    if ( onlyInB->m_size == (onlyInB->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&onlyInB->m_data, 24);
    v18 = &onlyInB->m_data[onlyInB->m_size];
    if ( v18 )
    {
      v18->m_start = v7->m_start;
      *(_QWORD *)&v18->m_size = *(_QWORD *)&v7->m_size;
      *(_QWORD *)&v18->m_traceId = *(_QWORD *)&v7->m_traceId;
    }
    ++onlyInB->m_size;
    ++v7;
  }
}

// File Line: 185
// RVA: 0xC7E740
void __fastcall hkMemorySnapshot::dumpAllocation(
        hkMemorySnapshot *this,
        hkMemorySnapshot::Allocation *alloc,
        hkOstream *stream)
{
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  char m_storage; // al
  const char *v13; // rbx
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkOstream *v16; // rax

  hkOstream::operator<<(stream, "Alloc: ");
  v6 = hkOstream::operator<<(stream, alloc->m_start);
  v7 = hkOstream::operator<<(v6, " Size: ");
  v8 = hkOstream::operator<<(v7, alloc->m_size);
  hkOstream::operator<<(v8, "\n");
  v9 = hkOstream::operator<<(stream, alloc->m_start);
  v10 = hkOstream::operator<<(v9, " Provider: ");
  v11 = hkOstream::operator<<(v10, alloc->m_sourceId);
  hkOstream::operator<<(v11, "\n");
  m_storage = alloc->m_status.m_storage;
  if ( m_storage )
  {
    v13 = "used";
    if ( m_storage != 1 )
      v13 = "unused";
  }
  else
  {
    v13 = "overhead";
  }
  v14 = hkOstream::operator<<(stream, alloc->m_start);
  v15 = hkOstream::operator<<(v14, " Status: ");
  v16 = hkOstream::operator<<(v15, v13);
  hkOstream::operator<<(v16, "\n");
  hkStackTracer::CallTree::dumpTrace(&this->m_callTree, alloc->m_traceId, stream);
}

