// File Line: 31
// RVA: 0xE389F0
hkClass *__fastcall hkVtableClassRegistry::getClassFromVtable(hkVtableClassRegistry *this, unsigned __int64 vtable)
{
  return (hkClass *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                      &this->m_map.m_map,
                      vtable,
                      0i64);
}

// File Line: 41
// RVA: 0xE389E0
hkClass *__fastcall hkVtableClassRegistry::getClassFromVirtualInstance(
        hkVtableClassRegistry *this,
        unsigned __int64 *obj)
{
  return (hkClass *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                      &this->m_map.m_map,
                      *obj,
                      0i64);
}

// File Line: 59
// RVA: 0xE38AD0
void __fastcall hkVtableClassRegistry::getClasses(
        hkVtableClassRegistry *this,
        hkArray<hkClass const *,hkContainerHeapAllocator> *classes)
{
  int v2; // r9d
  __int64 m_hashMod; // rcx
  __int64 v6; // r8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v8; // ebx
  hkClass *val; // rbp
  int v10; // edx
  __int64 v11; // r8
  __int64 v12; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v13; // rax

  v2 = 0;
  m_hashMod = this->m_map.m_map.m_hashMod;
  v6 = 0i64;
  if ( m_hashMod >= 0 )
  {
    m_elem = this->m_map.m_map.m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v6;
      ++v2;
      ++m_elem;
    }
    while ( v6 <= m_hashMod );
  }
  v8 = v2;
  if ( v2 <= this->m_map.m_map.m_hashMod )
  {
    do
    {
      val = (hkClass *)this->m_map.m_map.m_elem[v8].val;
      if ( classes->m_size == (classes->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&classes->m_data, 8);
      v10 = v8 + 1;
      classes->m_data[classes->m_size++] = val;
      v11 = this->m_map.m_map.m_hashMod;
      v12 = v8 + 1;
      if ( v12 <= v11 )
      {
        v13 = &this->m_map.m_map.m_elem[v10];
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
    while ( v10 <= this->m_map.m_map.m_hashMod );
  }
}

