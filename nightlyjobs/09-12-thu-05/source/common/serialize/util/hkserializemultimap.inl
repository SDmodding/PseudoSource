// File Line: 10
// RVA: 0xE44340
__int64 __fastcall hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFreeIndex(hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *this)
{
  __int64 result; // rax
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *v2; // rbx
  unsigned int v3; // edi

  result = this->m_freeChainStart;
  v2 = this;
  if ( (_DWORD)result == -1 )
  {
    v3 = this->m_valueChain.m_size;
    if ( v3 == (this->m_valueChain.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, 16);
    ++v2->m_valueChain.m_size;
    result = v3;
  }
  else
  {
    this->m_freeChainStart = this->m_valueChain.m_data[result].next;
  }
  return result;
}

// File Line: 27
// RVA: 0xE5CA90
unsigned __int64 __fastcall hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *this, unsigned __int64 k)
{
  return hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_indexMap.m_map.m_elem,
           k,
           0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 33
// RVA: 0xE5CC40
__int64 __fastcall hkSerializeMultiMap<char const *,int,hkPointerMap<char const *,int,hkContainerHeapAllocator>>::insert(hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> > *this, const void *k, const int *value)
{
  const int *v3; // rsi
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> > *v4; // rdi
  const void *v5; // r14
  int v6; // ebx
  int v7; // eax
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> >::Value *v8; // r8
  __int64 v9; // r9

  v3 = value;
  v4 = this;
  v5 = k;
  v6 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_indexMap.m_map.m_elem,
         (unsigned __int64)k,
         0xFFFFFFFFFFFFFFFFui64);
  v7 = hkSerializeMultiMap<char const *,int,hkPointerMap<char const *,int,hkContainerHeapAllocator>>::getFreeIndex(v4);
  v8 = v4->m_valueChain.m_data;
  v9 = v7;
  v8[v9].value = *v3;
  v8[v9].next = v6;
  return hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_indexMap.m_map.m_elem,
           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
           (unsigned __int64)v5,
           v7);
}

// File Line: 68
// RVA: 0xE4A020
void __fastcall hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::clear(hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> > *this)
{
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> > *v1; // rbx

  v1 = this;
  this->m_valueChain.m_size = 0;
  hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::clear((hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_indexMap);
  v1->m_freeChainStart = -1;
}

// File Line: 76
// RVA: 0xE44D30
__int64 __fastcall hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByIndex(hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *this, hkDataClassDict *key, int removeIndex)
{
  int v3; // esi
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *v4; // rdi
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v5; // rcx
  signed __int64 v6; // r14
  signed __int64 v7; // r8
  unsigned int v8; // ebp
  __int64 v9; // r9
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v10; // rcx
  signed __int64 v11; // rdx
  __int64 v12; // rax
  __int64 result; // rax

  v3 = removeIndex;
  v4 = this;
  v5 = this->m_valueChain.m_data;
  v6 = removeIndex;
  v7 = (signed __int64)&v5[removeIndex];
  v8 = *(_DWORD *)(v7 + 8);
  LODWORD(v9) = v8;
  if ( v8 == -1 )
  {
    v11 = (signed __int64)&v4->m_indexMap.m_map.m_elem[(signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                                                     (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_indexMap.m_map.m_elem,
                                                                     (unsigned __int64)key)];
    v9 = *(signed int *)(v11 + 8);
    if ( (_DWORD)v9 == v3 )
    {
      *(_QWORD *)(v11 + 8) = -1i64;
      LODWORD(v9) = v3;
    }
    else
    {
      v12 = v4->m_valueChain.m_data[v9].next;
      if ( (_DWORD)v12 == v3 )
      {
        v4->m_valueChain.m_data[v9].next = -1;
        LODWORD(v9) = v3;
      }
      else
      {
        *(_QWORD *)(v11 + 8) = v12;
        v4->m_valueChain.m_data[v6].value = v4->m_valueChain.m_data[v9].value;
      }
    }
  }
  else
  {
    v8 = v3;
    v10 = &v5[*(signed int *)(v7 + 8)];
    *(_QWORD *)v7 = v10->value;
    *(_QWORD *)(v7 + 8) = *(_QWORD *)&v10->next;
  }
  result = v8;
  v4->m_valueChain.m_data[(signed int)v9].next = v4->m_freeChainStart;
  v4->m_freeChainStart = v9;
  return result;
}

// File Line: 131
// RVA: 0xE44E10
void __fastcall hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByValue(hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *this, hkDataClassDict *key, hkDataClassDict *const *v)
{
  hkDataClassDict *const *v3; // rdi
  hkDataClassDict *v4; // rsi
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *v5; // rbx
  int v6; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v7; // r9

  v3 = v;
  v4 = key;
  v5 = (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)this;
  v6 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
         (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)this,
         (unsigned __int64)key);
  if ( v6 != -1 )
  {
    v7 = v5->m_valueChain.m_data;
    while ( v7[v6].value != (hkDataObjectDict *)*v3 )
    {
      v6 = v7[v6].next;
      if ( v6 == -1 )
        return;
    }
    hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByIndex(
      v5,
      v4,
      v6);
  }
}

// File Line: 147
// RVA: 0xE4B100
void __fastcall hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::removeKey(hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> > *this, hkDataObject_Handle *key)
{
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> > *v2; // rsi
  Dummy *v3; // rax
  __int64 v4; // rdi
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> >::Value *v5; // r8
  int v6; // edx
  int i; // eax
  hkDataObject_Handle v8; // [rsp+20h] [rbp-18h]

  v2 = this;
  v8 = *key;
  v3 = hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::findKey(
         (hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle> > *)&this->m_indexMap.m_elem,
         &v8);
  v4 = v2->m_indexMap.m_elem[(signed int)v3].val;
  hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::remove(
    (hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle> > *)&v2->m_indexMap.m_elem,
    v3);
  if ( (_DWORD)v4 != -1 )
  {
    v5 = v2->m_valueChain.m_data;
    v6 = v4;
    for ( i = v2->m_valueChain.m_data[v4].next; i != -1; i = v5[i].next )
      v6 = i;
    v5[v6].next = v2->m_freeChainStart;
    v2->m_freeChainStart = v4;
  }
}

