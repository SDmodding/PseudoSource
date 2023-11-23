// File Line: 63
// RVA: 0xA78F80
void __fastcall CAkIndexItem<CAkEvent *>::RemoveID(CAkIndexItem<CAkParameterNodeBase *> *this, unsigned int in_ID)
{
  _RTL_CRITICAL_SECTION_DEBUG *v4; // rdx
  _RTL_CRITICAL_SECTION_DEBUG **v5; // r8
  _RTL_CRITICAL_SECTION_DEBUG *v6; // rax
  _RTL_CRITICAL_SECTION_DEBUG *CriticalSection; // rcx

  EnterCriticalSection(&this->m_IndexLock.m_csLock);
  v4 = 0i64;
  v5 = &this->m_IndexLock.m_csLock.DebugInfo + in_ID % 0xC1;
  v6 = v5[5];
  if ( v6 )
  {
    while ( LODWORD(v6->ProcessLocksList.Flink) != in_ID )
    {
      v4 = v6;
      v6 = (_RTL_CRITICAL_SECTION_DEBUG *)v6->CriticalSection;
      if ( !v6 )
        goto LABEL_9;
    }
    CriticalSection = (_RTL_CRITICAL_SECTION_DEBUG *)v6->CriticalSection;
    if ( v4 )
      v4->CriticalSection = (_RTL_CRITICAL_SECTION *)CriticalSection;
    else
      v5[5] = CriticalSection;
    --this->m_mapIDToPtr.m_uiSize;
  }
LABEL_9:
  LeaveCriticalSection(&this->m_IndexLock.m_csLock);
}

// File Line: 69
// RVA: 0xA5D770
CAkIndexable *__fastcall CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
        CAkIndexItem<CAkFxShareSet *> *this,
        unsigned int in_ID)
{
  CAkIndexable *v4; // rbx

  EnterCriticalSection(&this->m_IndexLock.m_csLock);
  v4 = this->m_mapIDToPtr.m_table[in_ID % 193];
  if ( v4 )
  {
    while ( v4->key != in_ID )
    {
      v4 = v4->pNextItem;
      if ( !v4 )
        goto LABEL_4;
    }
    ++v4->m_lRef;
  }
  else
  {
LABEL_4:
    v4 = 0i64;
  }
  LeaveCriticalSection(&this->m_IndexLock.m_csLock);
  return v4;
}

