// File Line: 14
// RVA: 0xC7C380
// attributes: thunk
void __fastcall hkStackTracer::CallTree::~CallTree(hkStackTracer::CallTree *this)
{
  hkStackTracer::CallTree::quit(this);
}

// File Line: 19
// RVA: 0xC7C390
void __fastcall hkStackTracer::CallTree::quit(hkStackTracer::CallTree *this)
{
  hkMemoryAllocator *m_allocator; // rcx
  int m_capacityAndFlags; // edx

  m_allocator = this->m_allocator;
  if ( m_allocator )
  {
    m_capacityAndFlags = this->m_nodes.m_capacityAndFlags;
    this->m_nodes.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      m_allocator->vfptr->bufFree(m_allocator, this->m_nodes.m_data, 24 * (m_capacityAndFlags & 0x3FFFFFFF));
    this->m_nodes.m_data = 0i64;
    this->m_nodes.m_capacityAndFlags = 0x80000000;
    this->m_allocator = 0i64;
    *(_QWORD *)&this->m_rootNode = -1i64;
  }
}

// File Line: 30
// RVA: 0xC7C460
__int64 __fastcall hkStackTracer::CallTree::insertCallStack(
        hkStackTracer::CallTree *this,
        const unsigned __int64 *addrs,
        int numAddrs)
{
  int m_rootNode; // ebp
  __int64 i; // rsi
  hkStackTracer::CallTree::Node *m_data; // r8
  unsigned __int64 v9; // rbx
  int m_firstChild; // eax
  __int64 v11; // r14
  hkStackTracer::CallTree::Node *v12; // r8
  __int64 result; // rax

  if ( this->m_rootNode == -1 )
    this->m_rootNode = hkStackTracer::CallTree::getFreeNode(this);
  m_rootNode = this->m_rootNode;
  for ( i = numAddrs - 1; i >= 0; m_rootNode = m_firstChild )
  {
    m_data = this->m_nodes.m_data;
    v9 = addrs[i];
    m_firstChild = this->m_nodes.m_data[m_rootNode].m_firstChild;
    v11 = m_rootNode;
    if ( m_firstChild <= 0 )
    {
LABEL_9:
      m_firstChild = hkStackTracer::CallTree::getFreeNode(this);
      v12 = &this->m_nodes.m_data[m_firstChild];
      v12->m_value = v9;
      v12->m_parent = m_rootNode;
      v12->m_firstChild = -1;
      v12->m_next = this->m_nodes.m_data[v11].m_firstChild;
      this->m_nodes.m_data[v11].m_firstChild = m_firstChild;
    }
    else
    {
      while ( m_data[m_firstChild].m_value != v9 )
      {
        m_firstChild = m_data[m_firstChild].m_next;
        if ( m_firstChild <= 0 )
          goto LABEL_9;
      }
    }
    --i;
  }
  result = (unsigned int)m_rootNode;
  ++this->m_nodes.m_data[m_rootNode].m_usageCount;
  return result;
}

// File Line: 67
// RVA: 0xC7C600
void __fastcall hkStackTracer::CallTree::getTraces(
        hkStackTracer::CallTree *this,
        hkArray<unsigned __int64,hkContainerHeapAllocator> *addrs,
        hkArray<int,hkContainerHeapAllocator> *parents)
{
  __int64 m_size; // rbx
  int v5; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // eax
  int v11; // eax
  int v12; // r9d
  __int64 v13; // r8
  __int64 v14; // r9
  hkStackTracer::CallTree::Node *m_data; // rdx
  unsigned __int64 m_value; // rax
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  m_size = this->m_nodes.m_size;
  v5 = addrs->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < (int)m_size )
  {
    v8 = 2 * v5;
    v9 = this->m_nodes.m_size;
    if ( (int)m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&addrs->m_data, v9, 8);
  }
  addrs->m_size = m_size;
  v10 = parents->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < (int)m_size )
  {
    v11 = 2 * v10;
    v12 = m_size;
    if ( (int)m_size < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&parents->m_data, v12, 4);
  }
  parents->m_size = m_size;
  if ( (_DWORD)m_size )
  {
    v13 = 1i64;
    *addrs->m_data = 0i64;
    *parents->m_data = -1;
    if ( m_size > 1 )
    {
      v14 = 1i64;
      do
      {
        m_data = this->m_nodes.m_data;
        ++v13;
        m_value = this->m_nodes.m_data[v14++].m_value;
        addrs->m_data[v13 - 1] = m_value;
        parents->m_data[v13 - 1] = m_data[v14 - 1].m_parent;
      }
      while ( v13 < m_size );
    }
  }
}

// File Line: 92
// RVA: 0xC7CD60
__int64 __fastcall capacityOrFlag(unsigned int cap)
{
  __int64 result; // rax

  result = 0x80000000i64;
  if ( cap )
    return cap;
  return result;
}

// File Line: 97
// RVA: 0xC7C780
void __fastcall hkStackTracer::CallTree::swap(hkStackTracer::CallTree *this, hkStackTracer::CallTree *rhs)
{
  int v4; // eax
  hkStackTracer::CallTree::Node **v5; // rdx
  int v6; // r8d
  hkStackTracer::CallTree::Node *v7; // r11
  int v8; // r10d
  int v9; // r9d
  int m_rootNode; // ecx
  int m_firstFreeNode; // ecx
  hkMemoryAllocator *m_allocator; // rcx

  v4 = capacityOrFlag(rhs->m_nodes.m_capacityAndFlags & 0x3FFFFFFF);
  this->m_nodes.m_data = *v5;
  this->m_nodes.m_capacityAndFlags = v4;
  this->m_nodes.m_size = v6;
  rhs->m_nodes.m_data = v7;
  rhs->m_nodes.m_size = v8;
  rhs->m_nodes.m_capacityAndFlags = capacityOrFlag(v9);
  m_rootNode = this->m_rootNode;
  this->m_rootNode = rhs->m_rootNode;
  rhs->m_rootNode = m_rootNode;
  m_firstFreeNode = this->m_firstFreeNode;
  this->m_firstFreeNode = rhs->m_firstFreeNode;
  rhs->m_firstFreeNode = m_firstFreeNode;
  m_allocator = this->m_allocator;
  this->m_allocator = rhs->m_allocator;
  rhs->m_allocator = m_allocator;
}

// File Line: 115
// RVA: 0xC7C290
void __fastcall hkStackTracer::CallTree::CallTree(hkStackTracer::CallTree *this, hkStackTracer::CallTree *rhs)
{
  hkMemoryAllocator *m_allocator; // rdx

  this->m_nodes.m_capacityAndFlags = 0x80000000;
  this->m_nodes.m_data = 0i64;
  this->m_nodes.m_size = 0;
  m_allocator = rhs->m_allocator;
  this->m_allocator = m_allocator;
  hkArrayBase<hkStackTracer::CallTree::Node>::_insertAt(
    &this->m_nodes,
    m_allocator,
    0,
    rhs->m_nodes.m_data,
    rhs->m_nodes.m_size);
  this->m_rootNode = rhs->m_rootNode;
  this->m_firstFreeNode = rhs->m_firstFreeNode;
}

// File Line: 122
// RVA: 0xC7C2F0
void __fastcall hkStackTracer::CallTree::operator=(hkStackTracer::CallTree *this, hkStackTracer::CallTree *rhs)
{
  hkMemoryAllocator *m_allocator; // rcx
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *v6; // rdx

  m_allocator = this->m_allocator;
  m_capacityAndFlags = this->m_nodes.m_capacityAndFlags;
  this->m_nodes.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_nodes.m_data, 24 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_nodes.m_data = 0i64;
  this->m_nodes.m_capacityAndFlags = 0x80000000;
  v6 = rhs->m_allocator;
  this->m_allocator = v6;
  hkArrayBase<hkStackTracer::CallTree::Node>::_insertAt(&this->m_nodes, v6, 0, rhs->m_nodes.m_data, rhs->m_nodes.m_size);
  this->m_rootNode = rhs->m_rootNode;
  this->m_firstFreeNode = rhs->m_firstFreeNode;
}

// File Line: 133
// RVA: 0xC7C570
__int64 __fastcall hkStackTracer::CallTree::getCallStack(
        hkStackTracer::CallTree *this,
        int id,
        unsigned __int64 *addrs,
        int maxAddrs)
{
  __int64 result; // rax
  __int64 i; // r10
  __int64 v7; // r8

  result = 0i64;
  for ( i = 0i64; i < maxAddrs; id = this->m_nodes.m_data[v7].m_parent )
  {
    if ( id <= 0 )
      break;
    ++i;
    result = (unsigned int)(result + 1);
    v7 = id;
    addrs[i - 1] = this->m_nodes.m_data[v7].m_value;
  }
  return result;
}

// File Line: 145
// RVA: 0xC7C5D0
__int64 __fastcall hkStackTracer::CallTree::getCallStackSize(hkStackTracer::CallTree *this, int id)
{
  __int64 result; // rax

  for ( result = 0i64; id > 0; id = this->m_nodes.m_data[id].m_parent )
    result = (unsigned int)(result + 1);
  return result;
}

// File Line: 159
// RVA: 0xC7CD80
void __fastcall dumpStackTrace(const char *text, hkOstream *context)
{
  hkOstream::operator<<(context, text);
}

// File Line: 165
// RVA: 0xC7C710
void __fastcall hkStackTracer::CallTree::dumpTrace(hkStackTracer::CallTree *this, int id, hkOstream *stream)
{
  int v4; // eax
  unsigned __int64 addrs[17]; // [rsp+30h] [rbp-88h] BYREF
  hkStackTracer v6; // [rsp+D8h] [rbp+20h] BYREF

  if ( id < 0 )
  {
    hkOstream::operator<<(stream, "No stack trace\n");
  }
  else
  {
    v4 = hkStackTracer::CallTree::getCallStack(this, id, addrs, 16);
    hkStackTracer::dumpStackTrace(&v6, addrs, v4, dumpStackTrace, stream);
  }
}

// File Line: 183
// RVA: 0xC7C400
int __fastcall hkStackTracer::CallTree::insertCallStack(hkStackTracer::CallTree *this, hkStackTracer *tracer)
{
  int StackTrace; // eax
  unsigned __int64 trace; // [rsp+20h] [rbp-408h] BYREF
  unsigned __int64 addrs[128]; // [rsp+28h] [rbp-400h] BYREF

  StackTrace = hkStackTracer::getStackTrace(tracer, &trace, 128, 0);
  if ( StackTrace <= 0 )
    return -1;
  else
    return hkStackTracer::CallTree::insertCallStack(this, addrs, StackTrace - 1);
}

// File Line: 194
// RVA: 0xC7C550
void __fastcall hkStackTracer::CallTree::releaseCallStack(hkStackTracer::CallTree *this, int id)
{
  if ( id >= 0 )
  {
    --this->m_nodes.m_data[id].m_usageCount;
    hkStackTracer::CallTree::removeNodeIfUnused(this, id);
  }
}

// File Line: 203
// RVA: 0xC7C910
void __fastcall hkStackTracer::CallTree::removeNodeIfUnused(hkStackTracer::CallTree *this, int id)
{
  hkStackTracer::CallTree::Node *m_data; // r9
  hkStackTracer::CallTree::Node *v5; // rbx
  __int64 m_parent; // rax
  int *p_m_firstChild; // rdx
  __int64 v8; // rdx
  bool v9; // zf

  m_data = this->m_nodes.m_data;
  v5 = &this->m_nodes.m_data[id];
  if ( !v5->m_usageCount && v5->m_firstChild == -1 )
  {
    m_parent = v5->m_parent;
    if ( (_DWORD)m_parent == -1 )
    {
      this->m_rootNode = -1;
    }
    else
    {
      p_m_firstChild = &m_data[m_parent].m_firstChild;
      if ( *p_m_firstChild != id )
      {
        do
        {
          v8 = *p_m_firstChild + 2 * (*p_m_firstChild + 1i64);
          v9 = *((_DWORD *)&m_data->m_value + 2 * v8) == id;
          p_m_firstChild = (int *)(&m_data->m_value + v8);
        }
        while ( !v9 );
      }
      *p_m_firstChild = v5->m_next;
      hkStackTracer::CallTree::removeNodeIfUnused(this, v5->m_parent);
    }
    v5->m_next = this->m_firstFreeNode;
    this->m_firstFreeNode = id;
  }
}

// File Line: 233
// RVA: 0xC7C830
__int64 __fastcall hkStackTracer::CallTree::getFreeNode(hkStackTracer::CallTree *this)
{
  __int64 m_firstFreeNode; // r10
  hkStackTracer::CallTree::Node *m_data; // r8
  __int64 v4; // r9
  __int64 m_size; // rdi
  __int64 v7; // rdx

  m_firstFreeNode = this->m_firstFreeNode;
  if ( (_DWORD)m_firstFreeNode == -1 )
  {
    m_size = this->m_nodes.m_size;
    if ( (_DWORD)m_size == (this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(this->m_allocator, (const void **)&this->m_nodes.m_data, 24);
    ++this->m_nodes.m_size;
    v7 = m_size;
    this->m_nodes.m_data[v7].m_value = 0i64;
    this->m_nodes.m_data[v7].m_parent = -1;
    this->m_nodes.m_data[v7].m_firstChild = -1;
    this->m_nodes.m_data[v7].m_next = -1;
    this->m_nodes.m_data[v7].m_usageCount = 0;
    return (unsigned int)m_size;
  }
  else
  {
    m_data = this->m_nodes.m_data;
    v4 = m_firstFreeNode;
    this->m_firstFreeNode = this->m_nodes.m_data[m_firstFreeNode].m_next;
    m_data[v4].m_value = 0i64;
    this->m_nodes.m_data[v4].m_parent = -1;
    this->m_nodes.m_data[v4].m_firstChild = -1;
    this->m_nodes.m_data[v4].m_next = -1;
    this->m_nodes.m_data[v4].m_usageCount = 0;
    return (unsigned int)m_firstFreeNode;
  }
}

// File Line: 260
// RVA: 0xC7C810
hkBool *__fastcall hkStackTracer::CallTree::isEmpty(hkStackTracer::CallTree *this, hkBool *result)
{
  result->m_bool = this->m_rootNode == -1;
  return result;
}

