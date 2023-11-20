// File Line: 28
// RVA: 0xC7DE60
void __fastcall hkMemorySnapshot::hkMemorySnapshot(hkMemorySnapshot *this, hkMemoryAllocator *a)
{
  this->m_mem = a;
  this->m_allocations.m_capacityAndFlags = 2147483648;
  this->m_allocations.m_data = 0i64;
  this->m_allocations.m_size = 0;
  this->m_providers.m_data = 0i64;
  this->m_providers.m_size = 0;
  this->m_providers.m_capacityAndFlags = 2147483648;
  this->m_callTree.m_nodes.m_data = 0i64;
  this->m_callTree.m_nodes.m_size = 0;
  this->m_callTree.m_nodes.m_capacityAndFlags = 2147483648;
  this->m_callTree.m_allocator = a;
  *(_QWORD *)&this->m_callTree.m_rootNode = -1i64;
}

// File Line: 33
// RVA: 0xC7DEB0
void __fastcall hkMemorySnapshot::hkMemorySnapshot(hkMemorySnapshot *this, hkMemorySnapshot *rhs)
{
  hkMemorySnapshot *v2; // r14
  hkMemorySnapshot *v3; // rsi
  int v4; // ebp
  __int64 v5; // r15
  signed __int64 v6; // rax
  __int64 v7; // rcx
  signed __int64 v8; // rbx

  v2 = rhs;
  this->m_mem = rhs->m_mem;
  this->m_allocations.m_data = 0i64;
  this->m_allocations.m_size = 0;
  this->m_allocations.m_capacityAndFlags = 2147483648;
  v3 = this;
  this->m_providers.m_data = 0i64;
  this->m_providers.m_size = 0;
  this->m_providers.m_capacityAndFlags = 2147483648;
  hkStackTracer::CallTree::CallTree(&this->m_callTree, &rhs->m_callTree);
  hkArrayBase<hkMemorySnapshot::Allocation>::_append(
    &v3->m_allocations,
    v3->m_mem,
    v2->m_allocations.m_data,
    v2->m_allocations.m_size);
  v4 = 0;
  if ( v2->m_providers.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      if ( v3->m_providers.m_size == (v3->m_providers.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(v3->m_mem, &v3->m_providers, 48);
      v6 = (signed __int64)v3->m_providers.m_data[v3->m_providers.m_size].m_name;
      if ( v6 )
      {
        *(_QWORD *)(v6 + 32) = 0i64;
        *(_DWORD *)(v6 + 40) = 0;
        *(_DWORD *)(v6 + 44) = 2147483648;
      }
      v7 = v3->m_providers.m_size;
      v3->m_providers.m_size = v7 + 1;
      v8 = (signed __int64)v3->m_providers.m_data[v7].m_name;
      hkString::strNcpy((char *)v8, v2->m_providers.m_data[v4].m_name, 32);
      hkArrayBase<unsigned int>::_append(
        (hkArrayBase<unsigned int> *)(v8 + 32),
        v3->m_mem,
        (const unsigned int *)v2->m_providers.m_data[v5].m_parentIndices.m_data,
        v2->m_providers.m_data[v5].m_parentIndices.m_size);
      ++v4;
      ++v5;
    }
    while ( v4 < v2->m_providers.m_size );
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
  hkMemorySnapshot *v2; // rbx
  hkMemorySnapshot::Allocation *v3; // rax
  int v4; // er9
  int v5; // er8
  hkMemorySnapshot::Provider *v6; // rax
  hkMemorySnapshot *v7; // rdi
  int v8; // ecx

  v2 = m;
  this->m_mem = m->m_mem;
  v3 = m->m_allocations.m_data;
  v4 = m->m_allocations.m_capacityAndFlags;
  v5 = m->m_allocations.m_size;
  m->m_mem = 0i64;
  this->m_allocations.m_data = v3;
  this->m_allocations.m_capacityAndFlags = v4;
  this->m_allocations.m_size = v5;
  m->m_allocations.m_data = 0i64;
  m->m_allocations.m_size = 0;
  m->m_allocations.m_capacityAndFlags = 2147483648;
  v6 = m->m_providers.m_data;
  v7 = this;
  v8 = m->m_providers.m_size;
  v7->m_providers.m_capacityAndFlags = m->m_providers.m_capacityAndFlags;
  v7->m_providers.m_size = v8;
  v7->m_providers.m_data = v6;
  m->m_providers.m_data = 0i64;
  m->m_providers.m_size = 0;
  m->m_providers.m_capacityAndFlags = 2147483648;
  hkStackTracer::CallTree::swap(&v7->m_callTree, &m->m_callTree);
  hkString::memCpy(v7->m_routerWiring, v2->m_routerWiring, 20);
}

// File Line: 61
// RVA: 0xC7E0B0
void __fastcall hkMemorySnapshot::clear(hkMemorySnapshot *this)
{
  hkMemorySnapshot *v1; // rbx
  hkMemoryAllocator *v2; // rcx
  int v3; // edx
  int v4; // esi
  __int64 v5; // rbp
  hkMemoryAllocator *v6; // rcx
  hkMemorySnapshot::Provider *v7; // rdi
  int v8; // er8
  int v9; // er8
  hkMemoryAllocator *v10; // rcx

  v1 = this;
  v2 = this->m_mem;
  v3 = v1->m_allocations.m_capacityAndFlags;
  v1->m_allocations.m_size = 0;
  if ( v3 >= 0 )
    v2->vfptr->bufFree(v2, v1->m_allocations.m_data, 24 * (v3 & 0x3FFFFFFF));
  v1->m_allocations.m_data = 0i64;
  v1->m_allocations.m_capacityAndFlags = 2147483648;
  v4 = 0;
  if ( v1->m_providers.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v1->m_mem;
      v7 = &v1->m_providers.m_data[v5];
      v8 = v7->m_parentIndices.m_capacityAndFlags;
      v7->m_parentIndices.m_size = 0;
      if ( v8 >= 0 )
        v6->vfptr->bufFree(v6, v7->m_parentIndices.m_data, 4 * v8);
      ++v4;
      v7->m_parentIndices.m_data = 0i64;
      v7->m_parentIndices.m_capacityAndFlags = 2147483648;
      ++v5;
    }
    while ( v4 < v1->m_providers.m_size );
  }
  v9 = v1->m_providers.m_capacityAndFlags;
  v10 = v1->m_mem;
  v1->m_providers.m_size = 0;
  if ( v9 >= 0 )
    v10->vfptr->bufFree(v10, v1->m_providers.m_data, 48 * (v9 & 0x3FFFFFFF));
  v1->m_providers.m_capacityAndFlags = 2147483648;
  v1->m_providers.m_data = 0i64;
}

// File Line: 71
// RVA: 0xC7E1B0
void __fastcall hkMemorySnapshot::~hkMemorySnapshot(hkMemorySnapshot *this)
{
  hkMemorySnapshot *v1; // rbx

  v1 = this;
  hkMemorySnapshot::clear(this);
  hkStackTracer::CallTree::~CallTree(&v1->m_callTree);
}

// File Line: 76
// RVA: 0xC7E1E0
__int64 __fastcall hkMemorySnapshot::addProvider(hkMemorySnapshot *this, const char *name, int parent)
{
  unsigned int v3; // ebp
  int v4; // er14
  const char *v5; // r15
  hkMemorySnapshot *v6; // rdi
  signed __int64 v7; // rcx
  __int64 v8; // rcx
  signed __int64 v9; // rsi

  v3 = this->m_providers.m_size;
  v4 = parent;
  v5 = name;
  v6 = this;
  if ( v3 == (this->m_providers.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_mem, &this->m_providers, 48);
  v7 = (signed __int64)v6->m_providers.m_data[v6->m_providers.m_size].m_name;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 44) = 2147483648;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_DWORD *)(v7 + 40) = 0;
  }
  v8 = v6->m_providers.m_size;
  v6->m_providers.m_size = v8 + 1;
  v9 = (signed __int64)v6->m_providers.m_data[v8].m_name;
  hkString::strNcpy((char *)v9, v5, 31);
  *(_BYTE *)(v9 + 31) = 0;
  if ( v4 != -1 )
  {
    if ( *(_DWORD *)(v9 + 40) == (*(_DWORD *)(v9 + 44) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(v6->m_mem, (void *)(v9 + 32), 4);
    *(_DWORD *)(*(_QWORD *)(v9 + 32) + 4i64 * (signed int)(*(_DWORD *)(v9 + 40))++) = v4;
  }
  return v3;
}

// File Line: 87
// RVA: 0xC7E2D0
void __fastcall hkMemorySnapshot::addParentProvider(hkMemorySnapshot *this, int provider, int parent)
{
  int v3; // edi
  hkMemorySnapshot::Provider *v4; // rbx

  v3 = parent;
  v4 = &this->m_providers.m_data[provider];
  if ( v4->m_parentIndices.m_size == (v4->m_parentIndices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_mem, &v4->m_parentIndices, 4);
  v4->m_parentIndices.m_data[v4->m_parentIndices.m_size++] = v3;
}

// File Line: 93
// RVA: 0xC7E330
__int64 __fastcall hkMemorySnapshot::addItem(hkMemorySnapshot *this, int id, hkEnum<enum hkMemorySnapshot::StatusBits,signed char> status, const void *address, int size)
{
  unsigned int v5; // ebp
  signed int *v6; // rbx
  const void *v7; // rdi
  int v8; // esi
  __int64 v9; // r8
  __int64 result; // rax
  signed __int64 v11; // r9
  char v12; // [rsp+40h] [rbp+18h]

  v12 = status.m_storage;
  v5 = this->m_allocations.m_size;
  v6 = (signed int *)&this->m_allocations;
  v7 = address;
  v8 = id;
  if ( this->m_allocations.m_size == (this->m_allocations.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_mem, v6, 24);
  v9 = v6[2];
  result = v5;
  v11 = *(_QWORD *)v6 + 24 * v9;
  v6[2] = v9 + 1;
  *(_DWORD *)(v11 + 12) = v8;
  *(_DWORD *)(v11 + 8) = size;
  *(_QWORD *)v11 = v7;
  *(_DWORD *)(v11 + 16) = -1;
  *(_BYTE *)(v11 + 20) = v12;
  return result;
}

// File Line: 105
// RVA: 0xC7E3F0
void __fastcall hkMemorySnapshot::setCallStack(hkMemorySnapshot *this, int id, const unsigned __int64 *addresses, int numAddresses)
{
  hkStackTracer::CallTree *v4; // rcx
  signed __int64 v5; // rbx

  v4 = &this->m_callTree;
  v5 = *(_QWORD *)&v4[-2].m_nodes.m_size + 24i64 * id;
  *(_DWORD *)(v5 + 16) = hkStackTracer::CallTree::insertCallStack(v4, addresses, numAddresses);
}

// File Line: 110
// RVA: 0xC7E3D0
void __fastcall hkMemorySnapshot::setRouterWiring(hkMemorySnapshot *this, int stack, int temp, int heap, int debug, int solver)
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
  int v1; // er8

  v1 = this->m_allocations.m_size;
  if ( v1 > 1 )
    hkAlgorithm::quickSortRecursive<hkMemorySnapshot::Allocation,unsigned int (*)(hkMemorySnapshot::Allocation const &,hkMemorySnapshot::Allocation const &)>(
      this->m_allocations.m_data,
      0,
      v1 - 1,
      compareAllocations);
}

// File Line: 130
// RVA: 0xC7E460
void __fastcall hkMemorySnapshot::allocationDiff(hkMemorySnapshot *snapA, hkMemorySnapshot *snapB, hkArray<hkMemorySnapshot::Allocation,hkContainerHeapAllocator> *onlyInA, hkArray<hkMemorySnapshot::Allocation,hkContainerHeapAllocator> *onlyInB)
{
  hkArray<hkMemorySnapshot::Allocation,hkContainerHeapAllocator> *v4; // rsi
  hkArray<hkMemorySnapshot::Allocation,hkContainerHeapAllocator> *v5; // r14
  hkMemorySnapshot::Allocation *v6; // rdi
  hkMemorySnapshot::Allocation *v7; // rbx
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // r15
  const void *v10; // rcx
  const void *v11; // rdx
  bool v12; // cf
  hkMemorySnapshot::Allocation *v13; // rdx
  hkMemorySnapshot::Allocation *v14; // rdx
  hkMemorySnapshot::Allocation *v15; // rdx
  hkMemorySnapshot::Allocation *v16; // rdx
  hkMemorySnapshot::Allocation *v17; // rdx
  hkMemorySnapshot::Allocation *v18; // rdx

  v4 = onlyInB;
  v5 = onlyInA;
  onlyInA->m_size = 0;
  onlyInB->m_size = 0;
  v6 = snapA->m_allocations.m_data;
  v7 = snapB->m_allocations.m_data;
  v8 = (unsigned __int64)&v6[snapA->m_allocations.m_size];
  v9 = (unsigned __int64)&v7[snapB->m_allocations.m_size];
  if ( (unsigned __int64)v6 >= v8 )
    goto LABEL_38;
  while ( (unsigned __int64)v7 < v9 )
  {
    v10 = v6->m_start;
    v11 = v7->m_start;
    v12 = v6->m_start < v7->m_start;
    if ( v6->m_start != v7->m_start )
      goto LABEL_18;
    if ( v6->m_size != v7->m_size
      || v6->m_sourceId != v7->m_sourceId
      || v6->m_status.m_storage != v7->m_status.m_storage )
    {
      v12 = v10 < v11;
      if ( v10 == v11 )
      {
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 24);
        v13 = &v5->m_data[v5->m_size];
        if ( v13 )
        {
          v13->m_start = v6->m_start;
          *(_QWORD *)&v13->m_size = *(_QWORD *)&v6->m_size;
          *(_QWORD *)&v13->m_traceId = *(_QWORD *)&v6->m_traceId;
        }
        ++v5->m_size;
        if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 24);
        v14 = &v4->m_data[v4->m_size];
        if ( v14 )
        {
          v14->m_start = v7->m_start;
          *(_QWORD *)&v14->m_size = *(_QWORD *)&v7->m_size;
          *(_QWORD *)&v14->m_traceId = *(_QWORD *)&v7->m_traceId;
        }
        ++v6;
      }
      else
      {
LABEL_18:
        if ( v12 )
        {
          if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 24);
          v15 = &v5->m_data[v5->m_size];
          if ( v15 )
          {
            v15->m_start = v6->m_start;
            *(_QWORD *)&v15->m_size = *(_QWORD *)&v6->m_size;
            *(_QWORD *)&v15->m_traceId = *(_QWORD *)&v6->m_traceId;
          }
          ++v5->m_size;
          ++v6;
          goto LABEL_30;
        }
        if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 24);
        v16 = &v4->m_data[v4->m_size];
        if ( v16 )
        {
          v16->m_start = v7->m_start;
          *(_QWORD *)&v16->m_size = *(_QWORD *)&v7->m_size;
          *(_QWORD *)&v16->m_traceId = *(_QWORD *)&v7->m_traceId;
        }
      }
      ++v4->m_size;
      goto LABEL_29;
    }
    ++v6;
LABEL_29:
    ++v7;
LABEL_30:
    if ( (unsigned __int64)v6 >= v8 )
      goto LABEL_38;
  }
  for ( ; (unsigned __int64)v6 < v8; ++v6 )
  {
    if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 24);
    v17 = &v5->m_data[v5->m_size];
    if ( v17 )
    {
      v17->m_start = v6->m_start;
      *(_QWORD *)&v17->m_size = *(_QWORD *)&v6->m_size;
      *(_QWORD *)&v17->m_traceId = *(_QWORD *)&v6->m_traceId;
    }
    ++v5->m_size;
  }
LABEL_38:
  while ( (unsigned __int64)v7 < v9 )
  {
    if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 24);
    v18 = &v4->m_data[v4->m_size];
    if ( v18 )
    {
      v18->m_start = v7->m_start;
      *(_QWORD *)&v18->m_size = *(_QWORD *)&v7->m_size;
      *(_QWORD *)&v18->m_traceId = *(_QWORD *)&v7->m_traceId;
    }
    ++v4->m_size;
    ++v7;
  }
}

// File Line: 185
// RVA: 0xC7E740
void __fastcall hkMemorySnapshot::dumpAllocation(hkMemorySnapshot *this, hkMemorySnapshot::Allocation *alloc, hkOstream *stream)
{
  hkMemorySnapshot::Allocation *v3; // rdi
  hkMemorySnapshot *v4; // rbp
  hkOstream *v5; // rsi
  int v6; // eax
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  int v10; // eax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  int v14; // eax
  const char *v15; // rbx
  hkOstream *v16; // rax
  hkOstream *v17; // rax
  hkOstream *v18; // rax

  v3 = alloc;
  v4 = this;
  v5 = stream;
  v6 = (unsigned __int64)hkOstream::operator<<(stream, "Alloc: ");
  v7 = hkOstream::operator<<(v5, v3->m_start, v6);
  v8 = hkOstream::operator<<(v7, " Size: ");
  v9 = hkOstream::operator<<(v8, v3->m_size, (int)v8);
  v10 = (unsigned __int64)hkOstream::operator<<(v9, "\n");
  v11 = hkOstream::operator<<(v5, v3->m_start, v10);
  v12 = hkOstream::operator<<(v11, " Provider: ");
  v13 = hkOstream::operator<<(v12, v3->m_sourceId, (int)v12);
  hkOstream::operator<<(v13, "\n");
  v14 = (unsigned __int8)v3->m_status.m_storage;
  if ( (_BYTE)v14 )
  {
    v15 = "used";
    if ( (_BYTE)v14 != 1 )
      v15 = "unused";
  }
  else
  {
    v15 = "overhead";
  }
  v16 = hkOstream::operator<<(v5, v3->m_start, v14);
  v17 = hkOstream::operator<<(v16, " Status: ");
  v18 = hkOstream::operator<<(v17, v15);
  hkOstream::operator<<(v18, "\n");
  hkStackTracer::CallTree::dumpTrace(&v4->m_callTree, v3->m_traceId, v5);
}

