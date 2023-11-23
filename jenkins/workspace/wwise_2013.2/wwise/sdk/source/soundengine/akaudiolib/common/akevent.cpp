// File Line: 50
// RVA: 0xA6A710
CAkEvent *__fastcall CAkEvent::CreateNoIndex(unsigned int in_ulID)
{
  CAkEvent *result; // rax
  CAkEvent *v3; // rbx

  result = (CAkEvent *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
  v3 = result;
  if ( result )
  {
    CAkIndexable::CAkIndexable(result, in_ulID);
    v3->vfptr = (CAkIndexableVtbl *)&CAkEvent::`vftable;
    v3->m_actions.m_pFirst = 0i64;
    v3->m_iPreparationCount = 0;
    return v3;
  }
  return result;
}

// File Line: 55
// RVA: 0xA6A6A0
void __fastcall CAkEvent::AddToIndex(CAkEvent *this)
{
  CAkIndexItem<CAkEvent *> *p_m_idxEvents; // rdi
  _RTL_CRITICAL_SECTION_DEBUG **v3; // rdx

  p_m_idxEvents = &g_pIndex->m_idxEvents;
  EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
  v3 = &p_m_idxEvents->m_IndexLock.m_csLock.DebugInfo + this->key % 0xC1;
  this->pNextItem = (CAkIndexable *)v3[5];
  v3[5] = (_RTL_CRITICAL_SECTION_DEBUG *)this;
  ++p_m_idxEvents->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&p_m_idxEvents->m_IndexLock.m_csLock);
}

// File Line: 69
// RVA: 0xA6A650
__int64 __fastcall CAkEvent::AddRef(CAkEvent *this)
{
  CAkAudioLibIndex *v1; // rbx
  unsigned int v3; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
  v3 = this->m_lRef + 1;
  this->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxEvents.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 75
// RVA: 0xA6A770
__int64 __fastcall CAkEvent::Release(CAkEvent *this)
{
  CAkAudioLibIndex *v1; // rbx
  bool v3; // zf
  unsigned int m_lRef; // ebp
  int v5; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
  v3 = this->m_lRef-- == 1;
  m_lRef = this->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxEvents, this->key);
    v5 = g_DefaultPoolId;
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v5, this);
  }
  LeaveCriticalSection(&v1->m_idxEvents.m_IndexLock.m_csLock);
  return m_lRef;
}

// File Line: 138
// RVA: 0xA6A800
__int64 __fastcall CAkEvent::SetInitialValues(CAkEvent *this, char *in_pData, unsigned int in_ulDataSize)
{
  unsigned int v3; // r12d
  CAkAction *v4; // rbp
  unsigned int v5; // r14d
  char *v7; // rsi
  unsigned int v8; // edi
  CAkIndexItem<CAkAction *> *p_m_idxActions; // r15
  CAkAction *pNextItem; // rbx

  v3 = *((_DWORD *)in_pData + 1);
  v4 = 0i64;
  v5 = 0;
  v7 = in_pData + 8;
  if ( !v3 )
    return 1i64;
  while ( 1 )
  {
    v8 = *(_DWORD *)v7;
    v7 += 4;
    if ( !v8 )
      return 14i64;
    p_m_idxActions = &g_pIndex->m_idxActions;
    EnterCriticalSection(&g_pIndex->m_idxActions.m_IndexLock.m_csLock);
    pNextItem = (CAkAction *)p_m_idxActions->m_mapIDToPtr.m_table[v8 % 0xC1];
    if ( !pNextItem )
    {
LABEL_6:
      LeaveCriticalSection(&p_m_idxActions->m_IndexLock.m_csLock);
      return 2i64;
    }
    while ( pNextItem->key != v8 )
    {
      pNextItem = (CAkAction *)pNextItem->pNextItem;
      if ( !pNextItem )
        goto LABEL_6;
    }
    ++pNextItem->m_lRef;
    LeaveCriticalSection(&p_m_idxActions->m_IndexLock.m_csLock);
    pNextItem->pNextLightItem = 0i64;
    if ( v4 )
      v4->pNextLightItem = pNextItem;
    else
      this->m_actions.m_pFirst = pNextItem;
    ++v5;
    v4 = pNextItem;
    if ( v5 >= v3 )
      return 1i64;
  }
}

