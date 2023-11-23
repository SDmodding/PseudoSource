// File Line: 22
// RVA: 0x12FEC30
void __fastcall hkVtableClassRegistry::registerVtable(
        hkVtableClassRegistry *this,
        unsigned __int64 vtable,
        hkClass *klass)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_map.m_map,
    &hkContainerHeapAllocator::s_alloc,
    vtable,
    (unsigned __int64)klass);
}

// File Line: 40
// RVA: 0x12FEC50
void __fastcall hkVtableClassRegistry::registerList(
        hkVtableClassRegistry *this,
        hkTypeInfo *const *infos,
        hkClass *const *classes)
{
  hkTypeInfo *const *v3; // rbx
  signed __int64 v5; // rdi

  v3 = infos;
  if ( *infos )
  {
    v5 = (char *)classes - (char *)infos;
    do
    {
      if ( !*(hkTypeInfo *const *)((char *)v3 + v5) )
        break;
      if ( (*v3)->m_vtable )
        this->vfptr[1].__first_virtual_table_function__(this);
      ++v3;
    }
    while ( *v3 );
  }
}

// File Line: 55
// RVA: 0x12FECB0
void __fastcall hkVtableClassRegistry::merge(hkVtableClassRegistry *this, hkVtableClassRegistry *mergeFrom)
{
  int v2; // r9d
  __int64 m_hashMod; // rdx
  __int64 v5; // r8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v7; // ebx
  hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *p_m_map; // rsi
  __int64 v9; // r8
  int v10; // edx
  __int64 v11; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v12; // rax

  v2 = 0;
  m_hashMod = mergeFrom->m_map.m_map.m_hashMod;
  v5 = 0i64;
  if ( m_hashMod >= 0 )
  {
    m_elem = mergeFrom->m_map.m_map.m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v5;
      ++v2;
      ++m_elem;
    }
    while ( v5 <= m_hashMod );
  }
  v7 = v2;
  if ( v2 <= mergeFrom->m_map.m_map.m_hashMod )
  {
    p_m_map = &this->m_map;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &p_m_map->m_map,
        &hkContainerHeapAllocator::s_alloc,
        mergeFrom->m_map.m_map.m_elem[v7].key,
        mergeFrom->m_map.m_map.m_elem[v7].val);
      v9 = mergeFrom->m_map.m_map.m_hashMod;
      v10 = v7 + 1;
      v11 = v7 + 1;
      if ( v11 <= v9 )
      {
        v12 = &mergeFrom->m_map.m_map.m_elem[v10];
        do
        {
          if ( v12->key != -1i64 )
            break;
          ++v11;
          ++v10;
          ++v12;
        }
        while ( v11 <= v9 );
      }
      v7 = v10;
    }
    while ( v10 <= mergeFrom->m_map.m_map.m_hashMod );
  }
}

// File Line: 68
// RVA: 0x12FED80
hkReferencedObject *__fastcall hkVtableClassRegistrycreate()
{
  _QWORD **Value; // rax
  hkReferencedObject *result; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkVtableClassRegistry::`vftable;
    result[1].vfptr = 0i64;
    *(_DWORD *)&result[1].m_memSizeAndFlags = 0;
    *(_DWORD *)(&result[1].m_referenceCount + 1) = -1;
  }
  return result;
}

