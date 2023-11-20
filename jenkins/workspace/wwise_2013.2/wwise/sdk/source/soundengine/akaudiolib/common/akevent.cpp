// File Line: 50
// RVA: 0xA6A710
CAkEvent *__fastcall CAkEvent::CreateNoIndex(unsigned int in_ulID)
{
  unsigned int v1; // edi
  CAkEvent *result; // rax
  CAkEvent *v3; // rbx

  v1 = in_ulID;
  result = (CAkEvent *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
  v3 = result;
  if ( result )
  {
    CAkIndexable::CAkIndexable((CAkIndexable *)&result->vfptr, v1);
    v3->vfptr = (CAkIndexableVtbl *)&CAkEvent::`vftable;
    v3->m_actions.m_pFirst = 0i64;
    v3->m_iPreparationCount = 0;
    result = v3;
  }
  return result;
}

// File Line: 55
// RVA: 0xA6A6A0
void __fastcall CAkEvent::AddToIndex(CAkEvent *this)
{
  CAkEvent *v1; // rbx
  CAkIndexItem<CAkEvent *> *v2; // rdi
  signed __int64 v3; // rdx

  v1 = this;
  v2 = &g_pIndex->m_idxEvents;
  EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
  v3 = (signed __int64)v2 + 8 * (v1->key % 0xC1);
  v1->pNextItem = *(CAkIndexable **)(v3 + 40);
  *(_QWORD *)(v3 + 40) = v1;
  ++v2->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&v2->m_IndexLock.m_csLock);
}

// File Line: 69
// RVA: 0xA6A650
__int64 __fastcall CAkEvent::AddRef(CAkEvent *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkEvent *v2; // rsi
  unsigned int v3; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
  v3 = v2->m_lRef + 1;
  v2->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxEvents.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 75
// RVA: 0xA6A770
__int64 __fastcall CAkEvent::Release(CAkEvent *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkEvent *v2; // rsi
  bool v3; // zf
  unsigned int v4; // ebp
  int v5; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
  v3 = v2->m_lRef-- == 1;
  v4 = v2->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxEvents, v2->key);
    v5 = g_DefaultPoolId;
    v2->vfptr->__vecDelDtor((CAkIndexable *)&v2->vfptr, 0);
    AK::MemoryMgr::Free(v5, v2);
  }
  LeaveCriticalSection(&v1->m_idxEvents.m_IndexLock.m_csLock);
  return v4;
}

// File Line: 138
// RVA: 0xA6A800
signed __int64 __fastcall CAkEvent::SetInitialValues(CAkEvent *this, char *in_pData, unsigned int in_ulDataSize)
{
  unsigned int v3; // er12
  CAkAction *v4; // rbp
  unsigned int v5; // er14
  CAkEvent *v6; // r13
  char *v7; // rsi
  unsigned int v8; // edi
  _RTL_CRITICAL_SECTION *v9; // r15
  CAkAction *v10; // rbx

  v3 = *((_DWORD *)in_pData + 1);
  v4 = 0i64;
  v5 = 0;
  v6 = this;
  v7 = in_pData + 8;
  if ( !v3 )
    return 1i64;
  while ( 1 )
  {
    v8 = *(_DWORD *)v7;
    v7 += 4;
    if ( !v8 )
      return 14i64;
    v9 = &g_pIndex->m_idxActions.m_IndexLock.m_csLock;
    EnterCriticalSection(&g_pIndex->m_idxActions.m_IndexLock.m_csLock);
    v10 = (CAkAction *)*((_QWORD *)&v9[1].DebugInfo + v8 % 0xC1);
    if ( !v10 )
      goto LABEL_6;
    while ( v10->key != v8 )
    {
      v10 = (CAkAction *)v10->pNextItem;
      if ( !v10 )
        goto LABEL_6;
    }
    if ( !v10 )
    {
LABEL_6:
      LeaveCriticalSection(v9);
      return 2i64;
    }
    ++v10->m_lRef;
    LeaveCriticalSection(v9);
    v10->pNextLightItem = 0i64;
    if ( v4 )
      v4->pNextLightItem = v10;
    else
      v6->m_actions.m_pFirst = v10;
    ++v5;
    v4 = v10;
    if ( v5 >= v3 )
      return 1i64;
  }
}

