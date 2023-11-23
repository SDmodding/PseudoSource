// File Line: 38
// RVA: 0xA87FE0
CAkState *__fastcall CAkState::Create(unsigned int in_ulID)
{
  CAkState *result; // rax
  CAkState *v3; // rbx

  result = (CAkState *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
  v3 = result;
  if ( result )
  {
    CAkIndexable::CAkIndexable(result, in_ulID);
    v3->vfptr = (CAkIndexableVtbl *)&CAkState::`vftable;
    v3->m_props.m_pProps = 0i64;
    v3->m_pParentToNotify = 0i64;
    CAkState::AddToIndex(v3);
    return v3;
  }
  return result;
}

// File Line: 52
// RVA: 0xA880F0
__int64 __fastcall CAkState::SetInitialValues(CAkState *this, char *in_pData, unsigned int in_ulDataSize)
{
  unsigned __int8 v3; // bl
  char *v5; // rdi
  unsigned int v6; // esi
  char *v7; // rax
  char *v8; // r14

  v3 = in_pData[4];
  v5 = in_pData + 5;
  if ( v3 )
  {
    v6 = (v3 + 4) & 0xFFFFFFFC;
    v7 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v6 + 4 * v3);
    v8 = v7;
    if ( !v7 )
      return 52i64;
    *v7 = v3;
    memmove(v7 + 1, v5, v3);
    memmove(&v8[v6], &v5[v3], 4i64 * v3);
    this->m_props.m_pProps = v8;
  }
  return 1i64;
}

// File Line: 67
// RVA: 0xA87F70
void __fastcall CAkState::AddToIndex(CAkState *this)
{
  CAkIndexItem<CAkState *> *p_m_idxCustomStates; // rdi
  _RTL_CRITICAL_SECTION_DEBUG **v3; // rdx

  p_m_idxCustomStates = &g_pIndex->m_idxCustomStates;
  EnterCriticalSection(&g_pIndex->m_idxCustomStates.m_IndexLock.m_csLock);
  v3 = &p_m_idxCustomStates->m_IndexLock.m_csLock.DebugInfo + this->key % 0xC1;
  this->pNextItem = (CAkIndexable *)v3[5];
  v3[5] = (_RTL_CRITICAL_SECTION_DEBUG *)this;
  ++p_m_idxCustomStates->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&p_m_idxCustomStates->m_IndexLock.m_csLock);
}

// File Line: 77
// RVA: 0xA87F20
__int64 __fastcall CAkState::AddRef(CAkState *this)
{
  CAkAudioLibIndex *v1; // rbx
  unsigned int v3; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxCustomStates.m_IndexLock.m_csLock);
  v3 = this->m_lRef + 1;
  this->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxCustomStates.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 83
// RVA: 0xA88060
__int64 __fastcall CAkState::Release(CAkState *this)
{
  CAkAudioLibIndex *v1; // rbx
  bool v3; // zf
  unsigned int m_lRef; // ebp
  int v5; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxCustomStates.m_IndexLock.m_csLock);
  v3 = this->m_lRef-- == 1;
  m_lRef = this->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxCustomStates, this->key);
    v5 = g_DefaultPoolId;
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v5, this);
  }
  LeaveCriticalSection(&v1->m_idxCustomStates.m_IndexLock.m_csLock);
  return m_lRef;
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

