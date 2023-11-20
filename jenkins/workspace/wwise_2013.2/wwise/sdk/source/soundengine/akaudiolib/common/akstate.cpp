// File Line: 38
// RVA: 0xA87FE0
CAkState *__fastcall CAkState::Create(unsigned int in_ulID)
{
  unsigned int v1; // edi
  CAkState *result; // rax
  CAkState *v3; // rbx

  v1 = in_ulID;
  result = (CAkState *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
  v3 = result;
  if ( result )
  {
    CAkIndexable::CAkIndexable((CAkIndexable *)&result->vfptr, v1);
    v3->vfptr = (CAkIndexableVtbl *)&CAkState::`vftable';
    v3->m_props.m_pProps = 0i64;
    v3->m_pParentToNotify = 0i64;
    CAkState::AddToIndex(v3);
    result = v3;
  }
  return result;
}

// File Line: 52
// RVA: 0xA880F0
signed __int64 __fastcall CAkState::SetInitialValues(CAkState *this, char *in_pData, unsigned int in_ulDataSize)
{
  __int64 v3; // rbx
  CAkState *v4; // rbp
  char *v5; // rdi
  unsigned int v6; // esi
  char *v7; // rax
  char *v8; // r14

  LOBYTE(v3) = in_pData[4];
  v4 = this;
  v5 = in_pData + 5;
  if ( (_BYTE)v3 )
  {
    v6 = ((unsigned __int8)v3 + 4) & 0xFFFFFFFC;
    v7 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v6 + 4 * (unsigned __int8)v3);
    v8 = v7;
    if ( !v7 )
      return 52i64;
    *v7 = v3;
    v3 = (unsigned __int8)v3;
    memmove(v7 + 1, v5, (unsigned __int8)v3);
    memmove(&v8[v6], &v5[v3], 4 * v3);
    v4->m_props.m_pProps = v8;
  }
  return 1i64;
}

// File Line: 67
// RVA: 0xA87F70
void __fastcall CAkState::AddToIndex(CAkState *this)
{
  CAkState *v1; // rbx
  CAkIndexItem<CAkState *> *v2; // rdi
  signed __int64 v3; // rdx

  v1 = this;
  v2 = &g_pIndex->m_idxCustomStates;
  EnterCriticalSection(&g_pIndex->m_idxCustomStates.m_IndexLock.m_csLock);
  v3 = (signed __int64)v2 + 8 * (v1->key % 0xC1);
  v1->pNextItem = *(CAkIndexable **)(v3 + 40);
  *(_QWORD *)(v3 + 40) = v1;
  ++v2->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&v2->m_IndexLock.m_csLock);
}

// File Line: 77
// RVA: 0xA87F20
__int64 __fastcall CAkState::AddRef(CAkState *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkState *v2; // rsi
  unsigned int v3; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxCustomStates.m_IndexLock.m_csLock);
  v3 = v2->m_lRef + 1;
  v2->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxCustomStates.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 83
// RVA: 0xA88060
__int64 __fastcall CAkState::Release(CAkState *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkState *v2; // rsi
  bool v3; // zf
  unsigned int v4; // ebp
  int v5; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxCustomStates.m_IndexLock.m_csLock);
  v3 = v2->m_lRef-- == 1;
  v4 = v2->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxCustomStates, v2->key);
    v5 = g_DefaultPoolId;
    v2->vfptr->__vecDelDtor((CAkIndexable *)&v2->vfptr, 0);
    AK::MemoryMgr::Free(v5, v2);
  }
  LeaveCriticalSection(&v1->m_idxCustomStates.m_IndexLock.m_csLock);
  return v4;
}

// File Line: 96
// RVA: 0xA88050
void __fastcall CAkState::InitNotificationSystem(CAkState *this, CAkParameterNodeBase *in_pNode)
{
  this->m_pParentToNotify = in_pNode;
}

// File Line: 101
// RVA: 0xA88190
void __fastcall CAkState::TermNotificationSystem(CAkState *this)
{
  this->m_pParentToNotify = 0i64;
}

