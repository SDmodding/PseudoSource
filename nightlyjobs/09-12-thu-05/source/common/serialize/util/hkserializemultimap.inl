// File Line: 10
// RVA: 0xE44340
__int64 __fastcall hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFreeIndex(
        hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *this)
{
  __int64 result; // rax
  unsigned int m_size; // edi

  result = this->m_freeChainStart;
  if ( (_DWORD)result == -1 )
  {
    m_size = this->m_valueChain.m_size;
    if ( m_size == (this->m_valueChain.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_valueChain.m_data, 16);
    ++this->m_valueChain.m_size;
    return m_size;
  }
  else
  {
    this->m_freeChainStart = this->m_valueChain.m_data[result].next;
  }
  return result;
}

// File Line: 27
// RVA: 0xE5CA90
unsigned __int64 __fastcall hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
        hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *this,
        unsigned __int64 k)
{
  return hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           &this->m_indexMap.m_map,
           k,
           0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 33
// RVA: 0xE5CC40
__int64 __fastcall hkSerializeMultiMap<char const *,int,hkPointerMap<char const *,int,hkContainerHeapAllocator>>::insert(
        hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> > *this,
        unsigned __int64 k,
        int *value)
{
  int v6; // ebx
  int FreeIndex; // eax
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> >::Value *m_data; // r8

  v6 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         &this->m_indexMap.m_map,
         k,
         0xFFFFFFFFFFFFFFFFui64);
  FreeIndex = hkSerializeMultiMap<char const *,int,hkPointerMap<char const *,int,hkContainerHeapAllocator>>::getFreeIndex(this);
  m_data = this->m_valueChain.m_data;
  m_data[FreeIndex].value = *value;
  m_data[FreeIndex].next = v6;
  return hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
           &this->m_indexMap.m_map,
           &hkContainerHeapAllocator::s_alloc,
           k,
           FreeIndex);
}

// File Line: 68
// RVA: 0xE4A020
void __fastcall hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::clear(
        hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> > *this)
{
  this->m_valueChain.m_size = 0;
  hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::clear((hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_indexMap);
  this->m_freeChainStart = -1;
}

// File Line: 76
// RVA: 0xE44D30
__int64 __fastcall hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByIndex(
        hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *this,
        hkDataClassDict *key,
        unsigned int removeIndex)
{
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *m_data; // rcx
  __int64 v6; // r14
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v7; // r8
  unsigned int next; // ebp
  __int64 val_low; // r9
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v10; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v11; // rdx
  unsigned __int64 v12; // rax
  __int64 result; // rax

  m_data = this->m_valueChain.m_data;
  v6 = (int)removeIndex;
  v7 = &m_data[removeIndex];
  next = v7->next;
  LODWORD(val_low) = next;
  if ( next == -1 )
  {
    v11 = &this->m_indexMap.m_map.m_elem[(int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                                &this->m_indexMap.m_map,
                                                (unsigned __int64)key)];
    val_low = SLODWORD(v11->val);
    if ( (_DWORD)val_low == removeIndex )
    {
      v11->val = -1i64;
      LODWORD(val_low) = removeIndex;
    }
    else
    {
      v12 = this->m_valueChain.m_data[val_low].next;
      if ( (_DWORD)v12 == removeIndex )
      {
        this->m_valueChain.m_data[val_low].next = -1;
        LODWORD(val_low) = removeIndex;
      }
      else
      {
        v11->val = v12;
        this->m_valueChain.m_data[v6].value = this->m_valueChain.m_data[val_low].value;
      }
    }
  }
  else
  {
    next = removeIndex;
    v10 = &m_data[v7->next];
    v7->value = v10->value;
    *(_QWORD *)&v7->next = *(_QWORD *)&v10->next;
  }
  result = next;
  this->m_valueChain.m_data[(int)val_low].next = this->m_freeChainStart;
  this->m_freeChainStart = val_low;
  return result;
}

// File Line: 131
// RVA: 0xE44E10
void __fastcall hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByValue(
        hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *this,
        hkDataClassDict *key,
        hkDataClassDict **v)
{
  signed int FirstIndex; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *m_data; // r9

  FirstIndex = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                 (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)this,
                 (unsigned __int64)key);
  if ( FirstIndex != -1 )
  {
    m_data = this->m_valueChain.m_data;
    while ( m_data[FirstIndex].value != *v )
    {
      FirstIndex = m_data[FirstIndex].next;
      if ( FirstIndex == -1 )
        return;
    }
    hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByIndex(
      (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)this,
      key,
      FirstIndex);
  }
}

// File Line: 147
// RVA: 0xE4B100
void __fastcall hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::removeKey(
        hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> > *this,
        hkDataObject_Handle *key)
{
  __int64 v3; // rax
  __int64 val; // rdi
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> >::Value *m_data; // r8
  int v6; // edx
  int i; // eax
  hkDataObject_Handle v8; // [rsp+20h] [rbp-18h] BYREF

  v8 = *key;
  v3 = (__int64)hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::findKey(&this->m_indexMap, &v8);
  val = this->m_indexMap.m_elem[(int)v3].val;
  hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::remove(&this->m_indexMap, v3);
  if ( (_DWORD)val != -1 )
  {
    m_data = this->m_valueChain.m_data;
    v6 = val;
    for ( i = this->m_valueChain.m_data[val].next; i != -1; i = m_data[i].next )
      v6 = i;
    m_data[v6].next = this->m_freeChainStart;
    this->m_freeChainStart = val;
  }
}

