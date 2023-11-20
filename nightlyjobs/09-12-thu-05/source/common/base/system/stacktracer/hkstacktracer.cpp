// File Line: 14
// RVA: 0xC7C380
void __fastcall hkStackTracer::CallTree::~CallTree(hkStackTracer::CallTree *this)
{
  hkStackTracer::CallTree::quit(this);
}

// File Line: 19
// RVA: 0xC7C390
void __fastcall hkStackTracer::CallTree::quit(hkStackTracer::CallTree *this)
{
  hkStackTracer::CallTree *v1; // rbx
  hkMemoryAllocator *v2; // rcx
  int v3; // edx

  v1 = this;
  v2 = this->m_allocator;
  if ( v2 )
  {
    v3 = v1->m_nodes.m_capacityAndFlags;
    v1->m_nodes.m_size = 0;
    if ( v3 >= 0 )
      v2->vfptr->bufFree(v2, v1->m_nodes.m_data, 24 * (v3 & 0x3FFFFFFF));
    v1->m_nodes.m_data = 0i64;
    v1->m_nodes.m_capacityAndFlags = 2147483648;
    v1->m_allocator = 0i64;
    *(_QWORD *)&v1->m_rootNode = -1i64;
  }
}

// File Line: 30
// RVA: 0xC7C460
__int64 __fastcall hkStackTracer::CallTree::insertCallStack(hkStackTracer::CallTree *this, const unsigned __int64 *addrs, int numAddrs)
{
  int v3; // ebx
  const unsigned __int64 *v4; // r15
  hkStackTracer::CallTree *v5; // rdi
  int v6; // ebp
  __int64 i; // rsi
  hkStackTracer::CallTree::Node *v8; // r8
  unsigned __int64 v9; // rbx
  int v10; // eax
  signed __int64 v11; // r14
  signed __int64 v12; // r8
  __int64 result; // rax

  v3 = numAddrs;
  v4 = addrs;
  v5 = this;
  if ( this->m_rootNode == -1 )
    this->m_rootNode = hkStackTracer::CallTree::getFreeNode(this);
  v6 = v5->m_rootNode;
  for ( i = v3 - 1; i >= 0; v6 = v10 )
  {
    v8 = v5->m_nodes.m_data;
    v9 = v4[i];
    v10 = v5->m_nodes.m_data[v6].m_firstChild;
    v11 = v6;
    if ( v10 <= 0 )
      goto LABEL_9;
    while ( v8[v10].m_value != v9 )
    {
      v10 = v8[v10].m_next;
      if ( v10 <= 0 )
        goto LABEL_9;
    }
    if ( v10 == -1 )
    {
LABEL_9:
      v10 = hkStackTracer::CallTree::getFreeNode(v5);
      v12 = (signed __int64)&v5->m_nodes.m_data[v10];
      *(_QWORD *)v12 = v9;
      *(_DWORD *)(v12 + 8) = v6;
      *(_DWORD *)(v12 + 12) = -1;
      *(_DWORD *)(v12 + 16) = v5->m_nodes.m_data[v11].m_firstChild;
      v5->m_nodes.m_data[v11].m_firstChild = v10;
    }
    --i;
  }
  result = (unsigned int)v6;
  ++v5->m_nodes.m_data[v6].m_usageCount;
  return result;
}

// File Line: 67
// RVA: 0xC7C600
void __fastcall hkStackTracer::CallTree::getTraces(hkStackTracer::CallTree *this, hkArray<unsigned __int64,hkContainerHeapAllocator> *addrs, hkArray<int,hkContainerHeapAllocator> *parents)
{
  signed __int64 v3; // rbx
  hkArray<int,hkContainerHeapAllocator> *v4; // rdi
  int v5; // eax
  hkArray<unsigned __int64,hkContainerHeapAllocator> *v6; // rsi
  hkStackTracer::CallTree *v7; // r14
  int v8; // eax
  int v9; // er9
  int v10; // eax
  int v11; // eax
  int v12; // er9
  signed __int64 v13; // r8
  signed __int64 v14; // r9
  hkStackTracer::CallTree::Node *v15; // rdx
  unsigned __int64 v16; // rax
  hkResult result; // [rsp+40h] [rbp+8h]

  v3 = this->m_nodes.m_size;
  v4 = parents;
  v5 = addrs->m_capacityAndFlags & 0x3FFFFFFF;
  v6 = addrs;
  v7 = this;
  if ( v5 < (signed int)v3 )
  {
    v8 = 2 * v5;
    v9 = v3;
    if ( (signed int)v3 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, addrs, v9, 8);
  }
  v6->m_size = v3;
  v10 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < (signed int)v3 )
  {
    v11 = 2 * v10;
    v12 = v3;
    if ( (signed int)v3 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v12, 4);
  }
  v4->m_size = v3;
  if ( (_DWORD)v3 )
  {
    v13 = 1i64;
    *v6->m_data = 0i64;
    *v4->m_data = -1;
    if ( v3 > 1 )
    {
      v14 = 1i64;
      do
      {
        v15 = v7->m_nodes.m_data;
        ++v13;
        v16 = v7->m_nodes.m_data[v14].m_value;
        ++v14;
        v6->m_data[v13 - 1] = v16;
        v4->m_data[v13 - 1] = *((_DWORD *)&v15[v14] - 4);
      }
      while ( v13 < v3 );
    }
  }
}

// File Line: 92
// RVA: 0xC7CD60
signed __int64 __fastcall capacityOrFlag(int cap)
{
  signed __int64 result; // rax

  result = 0x80000000i64;
  if ( cap )
    result = (unsigned int)cap;
  return result;
}

// File Line: 97
// RVA: 0xC7C780
void __fastcall hkStackTracer::CallTree::swap(hkStackTracer::CallTree *this, hkStackTracer::CallTree *rhs)
{
  int v2; // er9
  hkStackTracer::CallTree::Node *v3; // r11
  __int64 v4; // r10
  __int64 v5; // r8
  hkStackTracer::CallTree *v6; // rbx
  hkStackTracer::CallTree *v7; // rdi
  int v8; // eax
  hkStackTracer::CallTree::Node **v9; // rdx
  int v10; // er8
  hkStackTracer::CallTree::Node *v11; // r11
  int v12; // er10
  int v13; // er9
  int v14; // ecx
  int v15; // ecx
  hkMemoryAllocator *v16; // rcx

  v2 = this->m_nodes.m_capacityAndFlags;
  v3 = this->m_nodes.m_data;
  v4 = (unsigned int)this->m_nodes.m_size;
  v5 = (unsigned int)rhs->m_nodes.m_size;
  v6 = this;
  v7 = rhs;
  v8 = capacityOrFlag(rhs->m_nodes.m_capacityAndFlags & 0x3FFFFFFF);
  v6->m_nodes.m_data = *v9;
  v6->m_nodes.m_capacityAndFlags = v8;
  v6->m_nodes.m_size = v10;
  v7->m_nodes.m_data = v11;
  v7->m_nodes.m_size = v12;
  v7->m_nodes.m_capacityAndFlags = capacityOrFlag(v13);
  v14 = v6->m_rootNode;
  v6->m_rootNode = v7->m_rootNode;
  v7->m_rootNode = v14;
  v15 = v6->m_firstFreeNode;
  v6->m_firstFreeNode = v7->m_firstFreeNode;
  v7->m_firstFreeNode = v15;
  v16 = v6->m_allocator;
  v6->m_allocator = v7->m_allocator;
  v7->m_allocator = v16;
}

// File Line: 115
// RVA: 0xC7C290
void __fastcall hkStackTracer::CallTree::CallTree(hkStackTracer::CallTree *this, hkStackTracer::CallTree *rhs)
{
  hkStackTracer::CallTree *v2; // rbx
  hkMemoryAllocator *v3; // rdx
  hkStackTracer::CallTree *v4; // rdi

  this->m_nodes.m_capacityAndFlags = 2147483648;
  v2 = rhs;
  this->m_nodes.m_data = 0i64;
  this->m_nodes.m_size = 0;
  v3 = rhs->m_allocator;
  this->m_allocator = v3;
  v4 = this;
  hkArrayBase<hkStackTracer::CallTree::Node>::_insertAt(&this->m_nodes, v3, 0, v2->m_nodes.m_data, v2->m_nodes.m_size);
  v4->m_rootNode = v2->m_rootNode;
  v4->m_firstFreeNode = v2->m_firstFreeNode;
}

// File Line: 122
// RVA: 0xC7C2F0
void __fastcall hkStackTracer::CallTree::operator=(hkStackTracer::CallTree *this, hkStackTracer::CallTree *rhs)
{
  hkStackTracer::CallTree *v2; // rbx
  hkMemoryAllocator *v3; // rcx
  hkStackTracer::CallTree *v4; // rdi
  int v5; // er8
  hkMemoryAllocator *v6; // rdx

  v2 = this;
  v3 = this->m_allocator;
  v4 = rhs;
  v5 = v2->m_nodes.m_capacityAndFlags;
  v2->m_nodes.m_size = 0;
  if ( v5 >= 0 )
    v3->vfptr->bufFree(v3, v2->m_nodes.m_data, 24 * (v5 & 0x3FFFFFFF));
  v2->m_nodes.m_data = 0i64;
  v2->m_nodes.m_capacityAndFlags = 2147483648;
  v6 = v4->m_allocator;
  v2->m_allocator = v6;
  hkArrayBase<hkStackTracer::CallTree::Node>::_insertAt(&v2->m_nodes, v6, 0, v4->m_nodes.m_data, v4->m_nodes.m_size);
  v2->m_rootNode = v4->m_rootNode;
  v2->m_firstFreeNode = v4->m_firstFreeNode;
}

// File Line: 133
// RVA: 0xC7C570
__int64 __fastcall hkStackTracer::CallTree::getCallStack(hkStackTracer::CallTree *this, int id, unsigned __int64 *addrs, __int64 maxAddrs)
{
  __int64 result; // rax
  unsigned __int64 *v5; // rbx
  __int64 i; // r10
  __int64 v7; // r8

  result = 0i64;
  maxAddrs = (signed int)maxAddrs;
  v5 = addrs;
  for ( i = 0i64; i < maxAddrs; id = this->m_nodes.m_data[v7].m_parent )
  {
    if ( id <= 0 )
      break;
    ++i;
    result = (unsigned int)(result + 1);
    v7 = id;
    v5[i - 1] = this->m_nodes.m_data[v7].m_value;
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
void __fastcall dumpStackTrace(const char *text, void *context)
{
  hkOstream::operator<<((hkOstream *)context, text);
}

// File Line: 165
// RVA: 0xC7C710
void __fastcall hkStackTracer::CallTree::dumpTrace(hkStackTracer::CallTree *this, int id, hkOstream *stream)
{
  hkOstream *context; // rbx
  int v4; // eax
  unsigned __int64 addrs; // [rsp+30h] [rbp-88h]
  hkStackTracer v6; // [rsp+D8h] [rbp+20h]

  context = stream;
  if ( id < 0 )
  {
    hkOstream::operator<<(stream, "No stack trace\n");
  }
  else
  {
    v4 = hkStackTracer::CallTree::getCallStack(this, id, &addrs, 16i64);
    hkStackTracer::dumpStackTrace(&v6, &addrs, v4, dumpStackTrace, context);
  }
}

// File Line: 183
// RVA: 0xC7C400
int __fastcall hkStackTracer::CallTree::insertCallStack(hkStackTracer::CallTree *this, hkStackTracer *tracer)
{
  hkStackTracer::CallTree *v2; // rbx
  int v3; // eax
  int result; // eax
  unsigned __int64 trace; // [rsp+20h] [rbp-408h]
  unsigned __int64 addrs; // [rsp+28h] [rbp-400h]

  v2 = this;
  v3 = hkStackTracer::getStackTrace(tracer, &trace, 128, 0);
  if ( v3 <= 0 )
    result = -1;
  else
    result = hkStackTracer::CallTree::insertCallStack(v2, &addrs, v3 - 1);
  return result;
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
  hkStackTracer::CallTree::Node *v2; // r9
  int v3; // edi
  hkStackTracer::CallTree *v4; // rsi
  hkStackTracer::CallTree::Node *v5; // rbx
  __int64 v6; // rax
  int *v7; // rdx
  signed __int64 v8; // rdx
  bool v9; // zf

  v2 = this->m_nodes.m_data;
  v3 = id;
  v4 = this;
  v5 = &this->m_nodes.m_data[id];
  if ( !v5->m_usageCount && v5->m_firstChild == -1 )
  {
    v6 = v5->m_parent;
    if ( (_DWORD)v6 == -1 )
    {
      this->m_rootNode = -1;
    }
    else
    {
      v7 = &v2[v6].m_firstChild;
      if ( *v7 != v3 )
      {
        do
        {
          v8 = *v7 + 2 * (*v7 + 1i64);
          v9 = *((_DWORD *)&v2->m_value + 2 * v8) == v3;
          v7 = (int *)(&v2->m_value + v8);
        }
        while ( !v9 );
      }
      *v7 = v5->m_next;
      hkStackTracer::CallTree::removeNodeIfUnused(this, v5->m_parent);
    }
    v5->m_next = v4->m_firstFreeNode;
    v4->m_firstFreeNode = v3;
  }
}

// File Line: 233
// RVA: 0xC7C830
__int64 __fastcall hkStackTracer::CallTree::getFreeNode(hkStackTracer::CallTree *this)
{
  __int64 v1; // r10
  hkStackTracer::CallTree *v2; // rbx
  hkStackTracer::CallTree::Node *v3; // r8
  __int64 v4; // r9
  __int64 result; // rax
  signed __int64 v6; // rdi
  signed __int64 v7; // rdx

  v1 = this->m_firstFreeNode;
  v2 = this;
  if ( (_DWORD)v1 == -1 )
  {
    v6 = this->m_nodes.m_size;
    if ( (_DWORD)v6 == (this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(this->m_allocator, this, 24);
    ++v2->m_nodes.m_size;
    v7 = v6;
    v2->m_nodes.m_data[v7].m_value = 0i64;
    v2->m_nodes.m_data[v7].m_parent = -1;
    v2->m_nodes.m_data[v7].m_firstChild = -1;
    v2->m_nodes.m_data[v7].m_next = -1;
    v2->m_nodes.m_data[v7].m_usageCount = 0;
    result = (unsigned int)v6;
  }
  else
  {
    v3 = this->m_nodes.m_data;
    v4 = v1;
    this->m_firstFreeNode = this->m_nodes.m_data[v1].m_next;
    v3[v4].m_value = 0i64;
    this->m_nodes.m_data[v4].m_parent = -1;
    this->m_nodes.m_data[v4].m_firstChild = -1;
    this->m_nodes.m_data[v4].m_next = -1;
    this->m_nodes.m_data[v4].m_usageCount = 0;
    result = (unsigned int)v1;
  }
  return result;
}

// File Line: 260
// RVA: 0xC7C810
hkBool *__fastcall hkStackTracer::CallTree::isEmpty(hkStackTracer::CallTree *this, hkBool *result)
{
  result->m_bool = this->m_rootNode == -1;
  return result;
}

