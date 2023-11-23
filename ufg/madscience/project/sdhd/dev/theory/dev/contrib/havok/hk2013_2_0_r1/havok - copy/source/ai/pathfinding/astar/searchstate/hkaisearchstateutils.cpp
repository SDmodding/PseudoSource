// File Line: 16
// RVA: 0xC00AD0
__int64 __fastcall hkaiSearchStateUtils::getPath(
        hkaiHashSearchState *state,
        unsigned int endKeyIn,
        hkaiSearchStateUtils::GetPathOptions options,
        hkArray<unsigned int,hkContainerHeapAllocator> *statesOut,
        int maxSize)
{
  hkaiSearchStateNode *NodeStateRO; // rax
  __int16 m_storage; // cx
  hkaiSearchStateNode *v11; // rbx
  unsigned int *m_data; // rcx
  __int64 v13; // rax
  int v14; // edi
  __int16 m_parentIndex; // cx
  int v16; // esi
  BOOL v17; // r12d
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  int v21; // edi
  __int64 i; // rax
  __int16 v23; // cx
  hkResult result; // [rsp+30h] [rbp-28h] BYREF

  NodeStateRO = hkaiHashSearchState::getNodeStateRO(state, endKeyIn);
  m_storage = NodeStateRO->m_flags.m_storage;
  v11 = NodeStateRO;
  if ( (m_storage & 4) != 0 )
  {
    if ( options )
    {
      return 1i64;
    }
    else if ( maxSize < 1 )
    {
      return 0i64;
    }
    else
    {
      if ( (statesOut->m_capacityAndFlags & 0x3FFFFFFF) == 0 )
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, statesOut, 1, 4);
      m_data = statesOut->m_data;
      statesOut->m_size = 1;
      v13 = 1i64;
      *m_data = endKeyIn;
    }
  }
  else
  {
    v14 = 0;
    if ( options == GET_PATH_PRESERVE_ALL && (m_storage & 8) != 0 )
      v14 = 1;
    do
    {
      m_parentIndex = NodeStateRO->m_parentIndex;
      if ( m_parentIndex == -1 )
        NodeStateRO = 0i64;
      else
        NodeStateRO = &state->m_nodes[m_parentIndex];
      ++v14;
    }
    while ( (NodeStateRO->m_flags.m_storage & 4) == 0 );
    if ( options )
      --v14;
    v16 = maxSize;
    if ( v14 < maxSize )
      v16 = v14;
    v17 = v16 == v14;
    v18 = statesOut->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v18 < v16 )
    {
      v19 = 2 * v18;
      v20 = v16;
      if ( v16 < v19 )
        v20 = v19;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, statesOut, v20, 4);
    }
    v21 = v14 - 1;
    statesOut->m_size = v16;
    if ( options == GET_PATH_PRESERVE_ALL && (v11->m_flags.m_storage & 8) != 0 )
    {
      if ( v21 < v16 )
        statesOut->m_data[v21] = v11->m_index;
      --v21;
    }
    for ( i = v21; (v11->m_flags.m_storage & 4) == 0; --i )
    {
      v23 = v11->m_parentIndex;
      if ( v23 == -1 )
        v11 = 0i64;
      else
        v11 = &state->m_nodes[v23];
      if ( i < v16 && (options == GET_PATH_PRESERVE_ALL || (v11->m_flags.m_storage & 4) == 0) )
        statesOut->m_data[i] = v11->m_index;
    }
    return v17;
  }
  return v13;
}

