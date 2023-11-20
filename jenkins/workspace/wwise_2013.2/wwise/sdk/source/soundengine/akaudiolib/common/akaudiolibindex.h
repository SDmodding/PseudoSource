// File Line: 63
// RVA: 0xA78F80
void __fastcall CAkIndexItem<CAkEvent *>::RemoveID(CAkIndexItem<CAkParameterNodeBase *> *this, unsigned int in_ID)
{
  unsigned int v2; // ebx
  CAkIndexItem<CAkParameterNodeBase *> *v3; // rdi
  __int64 v4; // rax
  CAkIndexable *v5; // rdx
  signed __int64 v6; // r8
  CAkIndexable *v7; // rax
  CAkIndexable *v8; // rcx

  v2 = in_ID;
  v3 = this;
  EnterCriticalSection(&this->m_IndexLock.m_csLock);
  v4 = v2 % 0xC1;
  v5 = 0i64;
  v6 = (signed __int64)v3 + 8 * v4;
  v7 = v3->m_mapIDToPtr.m_table[v4];
  if ( v7 )
  {
    while ( v7->key != v2 )
    {
      v5 = v7;
      v7 = v7->pNextItem;
      if ( !v7 )
        goto LABEL_9;
    }
    v8 = v7->pNextItem;
    if ( v5 )
      v5->pNextItem = v8;
    else
      *(_QWORD *)(v6 + 40) = v8;
    --v3->m_mapIDToPtr.m_uiSize;
  }
LABEL_9:
  LeaveCriticalSection(&v3->m_IndexLock.m_csLock);
}

// File Line: 69
// RVA: 0xA5D770
CAkIndexable *__fastcall CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(CAkIndexItem<CAkFxShareSet *> *this, unsigned int in_ID)
{
  unsigned int v2; // edi
  CAkIndexItem<CAkFxShareSet *> *v3; // rsi
  CAkIndexable *v4; // rbx

  v2 = in_ID;
  v3 = this;
  EnterCriticalSection(&this->m_IndexLock.m_csLock);
  v4 = v3->m_mapIDToPtr.m_table[v2 % 193];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->key != v2 )
  {
    v4 = v4->pNextItem;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
    ++v4->m_lRef;
  else
LABEL_4:
    v4 = 0i64;
  LeaveCriticalSection(&v3->m_IndexLock.m_csLock);
  return v4;
}

