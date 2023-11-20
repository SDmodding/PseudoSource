// File Line: 24
// RVA: 0xA58C20
CAkDialogueEvent *__fastcall CAkDialogueEvent::Create(unsigned int in_ulID)
{
  unsigned int v1; // edi
  CAkIndexable *v2; // rax
  CAkDialogueEvent *v3; // rbx

  v1 = in_ulID;
  v2 = (CAkIndexable *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
  v3 = (CAkDialogueEvent *)v2;
  if ( !v2 )
    return 0i64;
  CAkIndexable::CAkIndexable(v2, v1);
  v3->vfptr = (CAkIndexableVtbl *)&CAkDialogueEvent::`vftable';
  AkDecisionTree::AkDecisionTree(&v3->m_decisionTree);
  if ( CAkDialogueEvent::Init(v3) != 1 )
  {
    v3->vfptr->Release((CAkIndexable *)&v3->vfptr);
    return 0i64;
  }
  return v3;
}

// File Line: 37
// RVA: 0xA58BD0
__int64 __fastcall CAkDialogueEvent::AddRef(CAkDialogueEvent *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkDialogueEvent *v2; // rsi
  unsigned int v3; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxDialogueEvents.m_IndexLock.m_csLock);
  v3 = v2->m_lRef + 1;
  v2->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxDialogueEvents.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 43
// RVA: 0xA58D10
__int64 __fastcall CAkDialogueEvent::Release(CAkDialogueEvent *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkDialogueEvent *v2; // rsi
  bool v3; // zf
  unsigned int v4; // ebp
  int v5; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxDialogueEvents.m_IndexLock.m_csLock);
  v3 = v2->m_lRef-- == 1;
  v4 = v2->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxDialogueEvents, v2->key);
    v5 = g_DefaultPoolId;
    v2->vfptr->__vecDelDtor((CAkIndexable *)&v2->vfptr, 0);
    AK::MemoryMgr::Free(v5, v2);
  }
  LeaveCriticalSection(&v1->m_idxDialogueEvents.m_IndexLock.m_csLock);
  return v4;
}

// File Line: 57
// RVA: 0xA58DA0
__int64 __fastcall CAkDialogueEvent::SetInitialValues(CAkDialogueEvent *this, char *in_pData, unsigned int in_ulDataSize)
{
  unsigned __int16 v3; // r10
  unsigned int v4; // er9
  AkDecisionTree *v5; // rcx
  char *v6; // rdx
  unsigned int v7; // er8
  unsigned int v8; // eax
  unsigned int v9; // ecx

  v3 = (unsigned __int8)in_pData[4];
  v4 = *(_DWORD *)(in_pData + 5);
  v5 = &this->m_decisionTree;
  v6 = &in_pData[5 * v4 + 14];
  v7 = *(_DWORD *)(v6 - 5);
  v5->m_uProbability = v3;
  v5->m_uMode = *(v6 - 1);
  v8 = AkDecisionTree::SetTree(v5, v6, v7, v4);
  v9 = 1;
  if ( v8 != 1 )
    v9 = v8;
  return v9;
}

// File Line: 177
// RVA: 0xA58CA0
signed __int64 __fastcall CAkDialogueEvent::Init(CAkDialogueEvent *this)
{
  CAkDialogueEvent *v1; // rbx
  CAkIndexItem<CAkDialogueEvent *> *v2; // rdi
  signed __int64 v3; // rdx

  v1 = this;
  v2 = &g_pIndex->m_idxDialogueEvents;
  EnterCriticalSection(&g_pIndex->m_idxDialogueEvents.m_IndexLock.m_csLock);
  v3 = (signed __int64)v2 + 8 * (v1->key % 0xC1);
  v1->pNextItem = *(CAkIndexable **)(v3 + 40);
  *(_QWORD *)(v3 + 40) = v1;
  ++v2->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&v2->m_IndexLock.m_csLock);
  return 1i64;
}

