// File Line: 24
// RVA: 0xA58C20
CAkDialogueEvent *__fastcall CAkDialogueEvent::Create(unsigned int in_ulID)
{
  CAkIndexable *v2; // rax
  CAkDialogueEvent *v3; // rbx

  v2 = (CAkIndexable *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
  v3 = (CAkDialogueEvent *)v2;
  if ( !v2 )
    return 0i64;
  CAkIndexable::CAkIndexable(v2, in_ulID);
  v3->vfptr = (CAkIndexableVtbl *)&CAkDialogueEvent::`vftable;
  AkDecisionTree::AkDecisionTree(&v3->m_decisionTree);
  if ( CAkDialogueEvent::Init(v3) != AK_Success )
  {
    v3->vfptr->Release(v3);
    return 0i64;
  }
  return v3;
}

// File Line: 37
// RVA: 0xA58BD0
__int64 __fastcall CAkDialogueEvent::AddRef(CAkDialogueEvent *this)
{
  CAkAudioLibIndex *v1; // rbx
  unsigned int v3; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxDialogueEvents.m_IndexLock.m_csLock);
  v3 = this->m_lRef + 1;
  this->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxDialogueEvents.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 43
// RVA: 0xA58D10
__int64 __fastcall CAkDialogueEvent::Release(CAkDialogueEvent *this)
{
  CAkAudioLibIndex *v1; // rbx
  bool v3; // zf
  unsigned int m_lRef; // ebp
  int v5; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxDialogueEvents.m_IndexLock.m_csLock);
  v3 = this->m_lRef-- == 1;
  m_lRef = this->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID(
      (CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxDialogueEvents,
      this->key);
    v5 = g_DefaultPoolId;
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v5, this);
  }
  LeaveCriticalSection(&v1->m_idxDialogueEvents.m_IndexLock.m_csLock);
  return m_lRef;
}

// File Line: 57
// RVA: 0xA58DA0
__int64 __fastcall CAkDialogueEvent::SetInitialValues(
        CAkDialogueEvent *this,
        char *in_pData,
        unsigned int in_ulDataSize)
{
  unsigned __int16 v3; // r10
  unsigned int v4; // r9d
  AkDecisionTree *p_m_decisionTree; // rcx
  char *v6; // rdx
  unsigned int v7; // r8d
  unsigned int v8; // eax
  unsigned int v9; // ecx

  v3 = (unsigned __int8)in_pData[4];
  v4 = *(_DWORD *)(in_pData + 5);
  p_m_decisionTree = &this->m_decisionTree;
  v6 = &in_pData[5 * v4 + 14];
  v7 = *(_DWORD *)(v6 - 5);
  p_m_decisionTree->m_uProbability = v3;
  p_m_decisionTree->m_uMode = *(v6 - 1);
  v8 = AkDecisionTree::SetTree(p_m_decisionTree, v6, v7, v4);
  v9 = 1;
  if ( v8 != 1 )
    return v8;
  return v9;
}

// File Line: 177
// RVA: 0xA58CA0
__int64 __fastcall CAkDialogueEvent::Init(CAkDialogueEvent *this)
{
  CAkIndexItem<CAkDialogueEvent *> *p_m_idxDialogueEvents; // rdi
  _RTL_CRITICAL_SECTION_DEBUG **v3; // rdx

  p_m_idxDialogueEvents = &g_pIndex->m_idxDialogueEvents;
  EnterCriticalSection(&g_pIndex->m_idxDialogueEvents.m_IndexLock.m_csLock);
  v3 = &p_m_idxDialogueEvents->m_IndexLock.m_csLock.DebugInfo + this->key % 0xC1;
  this->pNextItem = (CAkIndexable *)v3[5];
  v3[5] = (_RTL_CRITICAL_SECTION_DEBUG *)this;
  ++p_m_idxDialogueEvents->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&p_m_idxDialogueEvents->m_IndexLock.m_csLock);
  return 1i64;
}

