// File Line: 22
// RVA: 0x12FEC30
void __fastcall hkVtableClassRegistry::registerVtable(hkVtableClassRegistry *this, const void *vtable, hkClass *klass)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_map.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)vtable,
    (unsigned __int64)klass);
}

// File Line: 40
// RVA: 0x12FEC50
void __fastcall hkVtableClassRegistry::registerList(hkVtableClassRegistry *this, hkTypeInfo *const *infos, hkClass *const *classes)
{
  hkTypeInfo *const *v3; // rbx
  hkVtableClassRegistry *v4; // rsi
  signed __int64 v5; // rdi

  v3 = infos;
  v4 = this;
  if ( *infos )
  {
    v5 = (char *)classes - (char *)infos;
    do
    {
      if ( !*(hkTypeInfo *const *)((char *)v3 + v5) )
        break;
      if ( (*v3)->m_vtable )
        v4->vfptr[1].__first_virtual_table_function__((hkBaseObject *)&v4->vfptr);
      ++v3;
    }
    while ( *v3 );
  }
}

// File Line: 55
// RVA: 0x12FECB0
void __fastcall hkVtableClassRegistry::merge(hkVtableClassRegistry *this, hkVtableClassRegistry *mergeFrom)
{
  int v2; // er9
  hkVtableClassRegistry *v3; // rdi
  __int64 v4; // rdx
  __int64 v5; // r8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v6; // rax
  int v7; // ebx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v8; // rsi
  __int64 v9; // r8
  int v10; // edx
  __int64 v11; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v12; // rax

  v2 = 0;
  v3 = mergeFrom;
  v4 = mergeFrom->m_map.m_map.m_hashMod;
  v5 = 0i64;
  if ( v4 >= 0 )
  {
    v6 = v3->m_map.m_map.m_elem;
    do
    {
      if ( v6->key != -1i64 )
        break;
      ++v5;
      ++v2;
      ++v6;
    }
    while ( v5 <= v4 );
  }
  v7 = v2;
  if ( v2 <= v3->m_map.m_map.m_hashMod )
  {
    v8 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_map.m_map.m_elem;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        v8,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v3->m_map.m_map.m_elem[v7].key,
        v3->m_map.m_map.m_elem[v7].val);
      v9 = v3->m_map.m_map.m_hashMod;
      v10 = v7 + 1;
      v11 = v7 + 1;
      if ( v11 <= v9 )
      {
        v12 = &v3->m_map.m_map.m_elem[v10];
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
    while ( v10 <= v3->m_map.m_map.m_hashMod );
  }
}

// File Line: 68
// RVA: 0x12FED80
hkReferencedObject *__fastcall hkVtableClassRegistrycreate()
{
  _QWORD **v0; // rax
  hkReferencedObject *result; // rax

  v0 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v0[11] + 8i64))(v0[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkVtableClassRegistry::`vftable';
    result[1].vfptr = 0i64;
    *(_DWORD *)&result[1].m_memSizeAndFlags = 0;
    *(_DWORD *)(&result[1].m_referenceCount + 1) = -1;
  }
  return result;
}

