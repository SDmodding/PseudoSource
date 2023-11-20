// File Line: 16
// RVA: 0xC00AD0
signed __int64 __fastcall hkaiSearchStateUtils::getPath(hkaiHashSearchState *state, unsigned int endKeyIn, hkaiSearchStateUtils::GetPathOptions options, hkArray<unsigned int,hkContainerHeapAllocator> *statesOut, int maxSize)
{
  hkArray<unsigned int,hkContainerHeapAllocator> *v5; // r14
  hkaiSearchStateUtils::GetPathOptions v6; // ebp
  unsigned int v7; // edi
  hkaiHashSearchState *v8; // r15
  hkaiSearchStateNode *v9; // rax
  __int16 v10; // cx
  signed __int64 v11; // rbx
  int v12; // ecx
  int v13; // ecx
  int v14; // er9
  unsigned int *v15; // rcx
  signed __int64 v16; // rax
  int v17; // edi
  __int16 v18; // cx
  int v19; // esi
  BOOL v20; // er12
  int v21; // eax
  int v22; // eax
  int v23; // er9
  int v24; // edi
  signed __int64 i; // rax
  __int16 v26; // cx
  hkResult result; // [rsp+30h] [rbp-28h]

  v5 = statesOut;
  v6 = options;
  v7 = endKeyIn;
  v8 = state;
  v9 = hkaiHashSearchState::getNodeStateRO(state, endKeyIn);
  v10 = v9->m_flags.m_storage;
  v11 = (signed __int64)v9;
  if ( v10 & 4 )
  {
    if ( v6 )
    {
      v16 = 1i64;
    }
    else if ( maxSize < 1 )
    {
      v16 = 0i64;
    }
    else
    {
      v12 = v5->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v12 < 1 )
      {
        v13 = 2 * v12;
        v14 = 1;
        if ( v13 > 1 )
          v14 = v13;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, v14, 4);
      }
      v15 = v5->m_data;
      v5->m_size = 1;
      v16 = 1i64;
      *v15 = v7;
    }
  }
  else
  {
    v17 = 0;
    if ( v6 == GET_PATH_PRESERVE_ALL && v10 & 8 )
      v17 = 1;
    do
    {
      v18 = v9->m_parentIndex;
      if ( v18 == -1 )
        v9 = 0i64;
      else
        v9 = &v8->m_nodes[v18];
      ++v17;
    }
    while ( !(v9->m_flags.m_storage & 4) );
    if ( v6 )
      --v17;
    v19 = maxSize;
    if ( v17 < maxSize )
      v19 = v17;
    v20 = v19 == v17;
    v21 = v5->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v21 < v19 )
    {
      v22 = 2 * v21;
      v23 = v19;
      if ( v19 < v22 )
        v23 = v22;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, v23, 4);
    }
    v24 = v17 - 1;
    v5->m_size = v19;
    if ( v6 == GET_PATH_PRESERVE_ALL && *(_BYTE *)(v11 + 14) & 8 )
    {
      if ( v24 < v19 )
        v5->m_data[v24] = *(_DWORD *)(v11 + 8);
      --v24;
    }
    for ( i = v24; !(*(_BYTE *)(v11 + 14) & 4); --i )
    {
      v26 = *(_WORD *)(v11 + 12);
      if ( v26 == -1 )
        v11 = 0i64;
      else
        v11 = (signed __int64)&v8->m_nodes[v26];
      if ( i < v19 && (v6 == GET_PATH_PRESERVE_ALL || !(*(_BYTE *)(v11 + 14) & 4)) )
        v5->m_data[i] = *(_DWORD *)(v11 + 8);
    }
    v16 = (unsigned int)v20;
  }
  return v16;
}

