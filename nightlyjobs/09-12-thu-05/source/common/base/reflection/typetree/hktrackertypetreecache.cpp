// File Line: 14
// RVA: 0x1303BE0
void __fastcall hkTrackerTypeTreeCache::hkTrackerTypeTreeCache(hkTrackerTypeTreeCache *this)
{
  hkMemoryAllocator **Value; // rax
  int v3; // ebx
  hkTrackerTypeTreeNode **v4; // rdi
  hkTrackerTypeTreeNode *v5; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkTrackerTypeTreeCache::`vftable;
  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkFreeList::hkFreeList(&this->m_nodeFreeList, 0x30ui64, 8ui64, 0x400ui64, Value[11], 0i64);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_textMap.m_map,
    0);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_namedTypeMap.m_map,
    0);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_expressionTypeMap.m_map,
    0);
  hkString::memSet(this->m_builtInTypes, 0, 0xA8u);
  v3 = 4;
  v4 = &this->m_builtInTypes[4];
  do
  {
    hkTrackerTypeTreeCache::newNode(this, (hkTrackerTypeTreeNode::Type)v3++);
    *v4++ = v5;
  }
  while ( v3 <= 15 );
}

// File Line: 25
// RVA: 0x1303750
hkBool *__fastcall hkTrackerTypeTreeCache::getTypeExpressionTree(
        hkTrackerTypeTreeCache *this,
        hkBool *result,
        const char *name,
        hkTrackerTypeTreeNode **nodeOut)
{
  hkStringMap<hkTrackerTypeTreeNode const *,hkContainerHeapAllocator> *p_m_expressionTypeMap; // rsi
  Dummy *Key; // rbp
  hkTrackerTypeTreeNode *Value; // rax
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  p_m_expressionTypeMap = &this->m_expressionTypeMap;
  Key = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_expressionTypeMap,
          name);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_expressionTypeMap,
    &resulta,
    Key);
  if ( resulta.m_bool )
  {
    Value = (hkTrackerTypeTreeNode *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                       (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_expressionTypeMap,
                                       Key);
    result->m_bool = 1;
    *nodeOut = Value;
  }
  else
  {
    *nodeOut = 0i64;
    result->m_bool = 0;
  }
  return result;
}

// File Line: 41
// RVA: 0x13037E0
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeCache::getTypeExpressionTree(
        hkTrackerTypeTreeCache *this,
        const char *name)
{
  return (hkTrackerTypeTreeNode *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_expressionTypeMap,
                                    name,
                                    0i64);
}

// File Line: 46
// RVA: 0x1303800
void __fastcall hkTrackerTypeTreeCache::setTypeExpressionTree(
        hkTrackerTypeTreeCache *this,
        const char *name,
        hkTrackerTypeTreeNode *node)
{
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &this->m_expressionTypeMap.m_map,
    name,
    (unsigned __int64)node);
}

// File Line: 52
// RVA: 0x1303820
void __fastcall hkTrackerTypeTreeCache::newNode(hkTrackerTypeTreeCache *this, hkTrackerTypeTreeNode::Type type)
{
  hkFreeList *p_m_nodeFreeList; // r8
  char *m_free; // r9
  unsigned __int64 m_elementSize; // rcx

  p_m_nodeFreeList = &this->m_nodeFreeList;
  m_free = (char *)this->m_nodeFreeList.m_free;
  if ( m_free )
  {
    --this->m_nodeFreeList.m_numFreeElements;
    p_m_nodeFreeList->m_free = *(hkFreeList::Element **)m_free;
  }
  else
  {
    m_free = this->m_nodeFreeList.m_top;
    if ( m_free < this->m_nodeFreeList.m_blockEnd )
    {
      m_elementSize = this->m_nodeFreeList.m_elementSize;
      --p_m_nodeFreeList->m_numFreeElements;
      p_m_nodeFreeList->m_top = &m_free[m_elementSize];
    }
    else
    {
      m_free = hkFreeList::addSpace(&this->m_nodeFreeList);
    }
  }
  if ( m_free )
    hkTrackerTypeTreeNode::hkTrackerTypeTreeNode((hkTrackerTypeTreeNode *)m_free, type);
}

// File Line: 59
// RVA: 0x1303890
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeCache::newNamedNode(
        hkTrackerTypeTreeCache *this,
        hkTrackerTypeTreeNode::Type type,
        hkSubString *name,
        hkBool allocName)
{
  signed int v5; // ebx
  hkLifoAllocator *Value; // rax
  char *m_cur; // rdi
  int v10; // edx
  char *v11; // rcx
  hkTrackerTypeTreeNode *v12; // rsi
  signed int v13; // ebx
  hkLifoAllocator *v14; // rax
  int v15; // r8d

  v5 = LODWORD(name->m_end) - LODWORD(name->m_start);
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v10 = (v5 + 128) & 0xFFFFFF80;
  v11 = &m_cur[v10];
  if ( v10 > Value->m_slabSize || v11 > Value->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v10);
  else
    Value->m_cur = v11;
  hkString::strNcpy(m_cur, name->m_start, v5);
  m_cur[v5] = 0;
  v12 = hkTrackerTypeTreeCache::newNamedNode(this, type, m_cur, (hkBool)1);
  v13 = (v5 + 128) & 0xFFFFFF80;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (v13 + 15) & 0xFFFFFFF0;
  if ( v13 > v14->m_slabSize || &m_cur[v15] != v14->m_cur || v14->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v14, m_cur, v15);
  else
    v14->m_cur = m_cur;
  return v12;
}

// File Line: 70
// RVA: 0x1303980
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeCache::newNamedNode(
        hkTrackerTypeTreeCache *this,
        hkTrackerTypeTreeNode::Type type,
        const char *name,
        hkBool allocName)
{
  const char *v5; // rdi
  hkTrackerTypeTreeNode *result; // rax
  hkFreeList::Element **p_m_next; // r8
  unsigned __int64 m_elementSize; // rcx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rbx

  v5 = name;
  result = hkTrackerTypeTreeCache::getNamedNode(this, name);
  if ( !result || result->m_next )
  {
    p_m_next = &this->m_nodeFreeList.m_free->m_next;
    if ( p_m_next )
    {
      --this->m_nodeFreeList.m_numFreeElements;
      this->m_nodeFreeList.m_free = *p_m_next;
    }
    else
    {
      p_m_next = (hkFreeList::Element **)this->m_nodeFreeList.m_top;
      if ( (char *)p_m_next < this->m_nodeFreeList.m_blockEnd )
      {
        m_elementSize = this->m_nodeFreeList.m_elementSize;
        --this->m_nodeFreeList.m_numFreeElements;
        this->m_nodeFreeList.m_top = (char *)p_m_next + m_elementSize;
      }
      else
      {
        p_m_next = (hkFreeList::Element **)hkFreeList::addSpace(&this->m_nodeFreeList);
      }
    }
    if ( p_m_next )
    {
      hkTrackerTypeTreeNode::hkTrackerTypeTreeNode((hkTrackerTypeTreeNode *)p_m_next, type);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    if ( allocName.m_bool )
      v5 = hkTrackerTypeTreeCache::newText(this, v5);
    hkSubString::operator=((hkSubString *)(v11 + 8), v5);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&this->m_namedTypeMap.m_map, v5, v11);
    return (hkTrackerTypeTreeNode *)v11;
  }
  else if ( result->m_type != type && type != TYPE_ARRAY )
  {
    result->m_type = type;
  }
  return result;
}

// File Line: 108
// RVA: 0x1303A80
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeCache::getNamedNode(hkTrackerTypeTreeCache *this, const char *name)
{
  return (hkTrackerTypeTreeNode *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_namedTypeMap,
                                    name,
                                    0i64);
}

// File Line: 113
// RVA: 0x1303AA0
char *__fastcall hkTrackerTypeTreeCache::newText(hkTrackerTypeTreeCache *this, char *text)
{
  hkStorageStringMap<int,hkContainerHeapAllocator> *p_m_textMap; // rbx
  Dummy *Key; // rsi
  Dummy *v6; // rsi
  char *v7; // rdi
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  p_m_textMap = &this->m_textMap;
  Key = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_textMap,
          text);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_textMap,
    &result,
    Key);
  if ( result.m_bool )
  {
    return (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&p_m_textMap->m_map, Key);
  }
  else
  {
    v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_textMap,
           text);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_textMap,
      &result,
      v6);
    if ( result.m_bool )
    {
      v7 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&p_m_textMap->m_map, v6);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(&p_m_textMap->m_map, v6, 1ui64);
    }
    else
    {
      v7 = hkString::strDup(text, &hkContainerHeapAllocator::s_alloc);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&p_m_textMap->m_map, v7, 1ui64);
    }
    return v7;
  }
}

// File Line: 127
// RVA: 0x1303B90
void __fastcall hkTrackerTypeTreeCache::clear(hkTrackerTypeTreeCache *this)
{
  hkFreeList::freeAllMemory(&this->m_nodeFreeList);
  hkStorageStringMap<hkTrackerLayoutHandler *,hkContainerHeapAllocator>::clear(&this->m_textMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&this->m_expressionTypeMap.m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&this->m_namedTypeMap.m_map);
}

