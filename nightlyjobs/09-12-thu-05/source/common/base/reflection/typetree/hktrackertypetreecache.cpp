// File Line: 14
// RVA: 0x1303BE0
void __fastcall hkTrackerTypeTreeCache::hkTrackerTypeTreeCache(hkTrackerTypeTreeCache *this)
{
  hkTrackerTypeTreeCache *v1; // rsi
  hkMemoryAllocator **v2; // rax
  hkTrackerTypeTreeNode::Type v3; // ebx
  signed __int64 v4; // rdi
  __int64 v5; // rax

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkTrackerTypeTreeCache::`vftable;
  v2 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkFreeList::hkFreeList(&v1->m_nodeFreeList, 0x30ui64, 8ui64, 0x400ui64, v2[11], 0i64);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v1->m_textMap.m_map,
    0);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v1->m_namedTypeMap.m_map,
    0);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v1->m_expressionTypeMap.m_map,
    0);
  hkString::memSet(v1->m_builtInTypes, 0, 168);
  v3 = 4;
  v4 = (signed __int64)&v1->m_builtInTypes[4];
  do
  {
    hkTrackerTypeTreeCache::newNode(v1, v3++);
    v4 += 8i64;
    *(_QWORD *)(v4 - 8) = v5;
  }
  while ( (signed int)v3 <= 15 );
}

// File Line: 25
// RVA: 0x1303750
hkBool *__fastcall hkTrackerTypeTreeCache::getTypeExpressionTree(hkTrackerTypeTreeCache *this, hkBool *result, const char *name, hkTrackerTypeTreeNode **nodeOut)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v4; // rsi
  hkBool *v5; // rbx
  hkTrackerTypeTreeNode **v6; // rdi
  Dummy *v7; // rbp
  unsigned __int64 v8; // rax
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v4 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_expressionTypeMap;
  v5 = result;
  v6 = nodeOut;
  v7 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_expressionTypeMap,
         (unsigned __int64)name);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v4, &resulta, v7);
  if ( resulta.m_bool )
  {
    v8 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(v4, v7);
    v5->m_bool = 1;
    *v6 = (hkTrackerTypeTreeNode *)v8;
  }
  else
  {
    *v6 = 0i64;
    v5->m_bool = 0;
  }
  return v5;
}

// File Line: 41
// RVA: 0x13037E0
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeCache::getTypeExpressionTree(hkTrackerTypeTreeCache *this, const char *name)
{
  return (hkTrackerTypeTreeNode *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_expressionTypeMap,
                                    (unsigned __int64)name,
                                    0i64);
}

// File Line: 46
// RVA: 0x1303800
void __fastcall hkTrackerTypeTreeCache::setTypeExpressionTree(hkTrackerTypeTreeCache *this, const char *name, hkTrackerTypeTreeNode *node)
{
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &this->m_expressionTypeMap.m_map,
    (unsigned __int64)name,
    (unsigned __int64)node);
}

// File Line: 52
// RVA: 0x1303820
void __fastcall hkTrackerTypeTreeCache::newNode(hkTrackerTypeTreeCache *this, hkTrackerTypeTreeNode::Type type)
{
  hkFreeList *v2; // r8
  hkTrackerTypeTreeNode::Type v3; // ebx
  char *v4; // r9
  unsigned __int64 v5; // rcx

  v2 = &this->m_nodeFreeList;
  v3 = type;
  v4 = (char *)this->m_nodeFreeList.m_free;
  if ( v4 )
  {
    --this->m_nodeFreeList.m_numFreeElements;
    v2->m_free = *(hkFreeList::Element **)v4;
  }
  else
  {
    v4 = this->m_nodeFreeList.m_top;
    if ( v4 < this->m_nodeFreeList.m_blockEnd )
    {
      v5 = this->m_nodeFreeList.m_elementSize;
      --v2->m_numFreeElements;
      v2->m_top = &v4[v5];
    }
    else
    {
      v4 = hkFreeList::addSpace(&this->m_nodeFreeList);
    }
  }
  if ( v4 )
    hkTrackerTypeTreeNode::hkTrackerTypeTreeNode((hkTrackerTypeTreeNode *)v4, v3);
}

// File Line: 59
// RVA: 0x1303890
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeCache::newNamedNode(hkTrackerTypeTreeCache *this, hkTrackerTypeTreeNode::Type type, hkSubString *name, hkBool allocName)
{
  hkTrackerTypeTreeCache *v4; // r15
  int v5; // ebx
  hkSubString *v6; // rsi
  hkTrackerTypeTreeNode::Type v7; // er14
  hkLifoAllocator *v8; // rax
  char *v9; // rdi
  int v10; // edx
  char *v11; // rcx
  hkTrackerTypeTreeNode *v12; // rsi
  signed int v13; // ebx
  hkLifoAllocator *v14; // rax
  int v15; // er8

  v4 = this;
  v5 = LODWORD(name->m_end) - LODWORD(name->m_start);
  v6 = name;
  v7 = type;
  v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (char *)v8->m_cur;
  v10 = (v5 + 128) & 0xFFFFFF80;
  v11 = &v9[v10];
  if ( v10 > v8->m_slabSize || v11 > v8->m_end )
    v9 = (char *)hkLifoAllocator::allocateFromNewSlab(v8, v10);
  else
    v8->m_cur = v11;
  hkString::strNcpy(v9, v6->m_start, v5);
  v9[v5] = 0;
  v12 = hkTrackerTypeTreeCache::newNamedNode(v4, v7, v9, (hkBool)1);
  v13 = (v5 + 128) & 0xFFFFFF80;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (v13 + 15) & 0xFFFFFFF0;
  if ( v13 > v14->m_slabSize || &v9[v15] != v14->m_cur || v14->m_firstNonLifoEnd == v9 )
    hkLifoAllocator::slowBlockFree(v14, v9, v15);
  else
    v14->m_cur = v9;
  return v12;
}

// File Line: 70
// RVA: 0x1303980
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeCache::newNamedNode(hkTrackerTypeTreeCache *this, hkTrackerTypeTreeNode::Type type, const char *name, hkBool allocName)
{
  hkTrackerTypeTreeNode::Type v4; // ebx
  const char *v5; // rdi
  hkTrackerTypeTreeCache *v6; // rsi
  hkTrackerTypeTreeNode *result; // rax
  hkTrackerTypeTreeNode *v8; // r8
  unsigned __int64 v9; // rcx
  hkTrackerTypeTreeNode *v10; // rax
  hkTrackerTypeTreeNode *v11; // rbx
  char v12; // [rsp+48h] [rbp+20h]

  v12 = allocName.m_bool;
  v4 = type;
  v5 = name;
  v6 = this;
  result = hkTrackerTypeTreeCache::getNamedNode(this, name);
  if ( !result || result->m_next )
  {
    v8 = (hkTrackerTypeTreeNode *)v6->m_nodeFreeList.m_free;
    if ( v8 )
    {
      --v6->m_nodeFreeList.m_numFreeElements;
      v6->m_nodeFreeList.m_free = *(hkFreeList::Element **)&v8->m_type;
    }
    else
    {
      v8 = (hkTrackerTypeTreeNode *)v6->m_nodeFreeList.m_top;
      if ( (char *)v8 < v6->m_nodeFreeList.m_blockEnd )
      {
        v9 = v6->m_nodeFreeList.m_elementSize;
        --v6->m_nodeFreeList.m_numFreeElements;
        v6->m_nodeFreeList.m_top = (char *)v8 + v9;
      }
      else
      {
        v8 = (hkTrackerTypeTreeNode *)hkFreeList::addSpace(&v6->m_nodeFreeList);
      }
    }
    if ( v8 )
    {
      hkTrackerTypeTreeNode::hkTrackerTypeTreeNode(v8, v4);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    if ( v12 )
      v5 = hkTrackerTypeTreeCache::newText(v6, v5);
    hkSubString::operator=(&v11->m_name, v5);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &v6->m_namedTypeMap.m_map,
      (unsigned __int64)v5,
      (unsigned __int64)v11);
    result = v11;
  }
  else if ( result->m_type != v4 && v4 != 16 )
  {
    result->m_type = v4;
  }
  return result;
}

// File Line: 108
// RVA: 0x1303A80
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeCache::getNamedNode(hkTrackerTypeTreeCache *this, const char *name)
{
  return (hkTrackerTypeTreeNode *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_namedTypeMap,
                                    (unsigned __int64)name,
                                    0i64);
}

// File Line: 113
// RVA: 0x1303AA0
char *__fastcall hkTrackerTypeTreeCache::newText(hkTrackerTypeTreeCache *this, const char *text)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v2; // rbx
  const char *v3; // rdi
  Dummy *v4; // rsi
  Dummy *v6; // rsi
  char *v7; // rdi
  hkBool result; // [rsp+30h] [rbp+8h]

  v2 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_textMap;
  v3 = text;
  v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_textMap,
         (unsigned __int64)text);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v2, &result, v4);
  if ( result.m_bool )
    return (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
                     (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v2,
                     v4);
  v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(v2, (unsigned __int64)v3);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v2, &result, v6);
  if ( result.m_bool )
  {
    v7 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
                   (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v2,
                   v6);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v2,
      v6,
      1ui64);
  }
  else
  {
    v7 = hkString::strDup(v3, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v2,
      (unsigned __int64)v7,
      1ui64);
  }
  return v7;
}

// File Line: 127
// RVA: 0x1303B90
void __fastcall hkTrackerTypeTreeCache::clear(hkTrackerTypeTreeCache *this)
{
  hkTrackerTypeTreeCache *v1; // rbx

  v1 = this;
  hkFreeList::freeAllMemory(&this->m_nodeFreeList);
  hkStorageStringMap<hkTrackerLayoutHandler *,hkContainerHeapAllocator>::clear(&v1->m_textMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&v1->m_expressionTypeMap.m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&v1->m_namedTypeMap.m_map);
}

