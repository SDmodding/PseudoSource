// File Line: 31
// RVA: 0xE389F0
hkClass *__fastcall hkVtableClassRegistry::getClassFromVtable(hkVtableClassRegistry *this, const void *vtable)
{
  return (hkClass *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_map.m_map.m_elem,
                      (unsigned __int64)vtable,
                      0i64);
}

// File Line: 41
// RVA: 0xE389E0
hkClass *__fastcall hkVtableClassRegistry::getClassFromVirtualInstance(hkVtableClassRegistry *this, const void *obj)
{
  return (hkClass *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_map.m_map.m_elem,
                      *(_QWORD *)obj,
                      0i64);
}

// File Line: 59
// RVA: 0xE38AD0
void __fastcall hkVtableClassRegistry::getClasses(hkVtableClassRegistry *this, hkArray<hkClass const *,hkContainerHeapAllocator> *classes)
{
  int v2; // er9
  hkVtableClassRegistry *v3; // rdi
  __int64 v4; // rcx
  hkArray<hkClass const *,hkContainerHeapAllocator> *v5; // rsi
  __int64 v6; // r8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v7; // rax
  int v8; // ebx
  hkClass *v9; // rbp
  int v10; // edx
  __int64 v11; // r8
  __int64 v12; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v13; // rax

  v2 = 0;
  v3 = this;
  v4 = this->m_map.m_map.m_hashMod;
  v5 = classes;
  v6 = 0i64;
  if ( v4 >= 0 )
  {
    v7 = v3->m_map.m_map.m_elem;
    do
    {
      if ( v7->key != -1i64 )
        break;
      ++v6;
      ++v2;
      ++v7;
    }
    while ( v6 <= v4 );
  }
  v8 = v2;
  if ( v2 <= v3->m_map.m_map.m_hashMod )
  {
    do
    {
      v9 = (hkClass *)v3->m_map.m_map.m_elem[v8].val;
      if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
      v10 = v8 + 1;
      v5->m_data[v5->m_size++] = v9;
      v11 = v3->m_map.m_map.m_hashMod;
      v12 = v8 + 1;
      if ( v12 <= v11 )
      {
        v13 = &v3->m_map.m_map.m_elem[v10];
        do
        {
          if ( v13->key != -1i64 )
            break;
          ++v12;
          ++v10;
          ++v13;
        }
        while ( v12 <= v11 );
      }
      v8 = v10;
    }
    while ( v10 <= v3->m_map.m_map.m_hashMod );
  }
}

