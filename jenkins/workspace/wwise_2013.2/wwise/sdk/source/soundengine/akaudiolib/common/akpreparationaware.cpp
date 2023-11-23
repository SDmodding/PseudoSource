// File Line: 30
// RVA: 0xA9AEF0
CAkStateMgr::PreparationStateItem *__fastcall CAkPreparationAware::GetPreparedContent(
        CAkPreparationAware *this,
        unsigned int in_ulGroup,
        AkGroupType in_eGroupType)
{
  CAkStateMgr::PreparationStateItem *result; // rax

  result = CAkStateMgr::GetPreparationItem(g_pStateMgr, in_ulGroup, in_eGroupType);
  if ( result )
    return (CAkStateMgr::PreparationStateItem *)((char *)result + 8);
  return result;
}

// File Line: 42
// RVA: 0xA9AF20
__int64 __fastcall CAkPreparationAware::SubscribePrepare(
        CAkPreparationAware *this,
        unsigned int in_ulGroup,
        AkGroupType in_eGroupType)
{
  CAkStateMgr::PreparationStateItem *PreparationItem; // rax
  CAkPreparationAware *m_pFirst; // rcx

  PreparationItem = CAkStateMgr::GetPreparationItem(g_pStateMgr, in_ulGroup, in_eGroupType);
  if ( !PreparationItem )
    return 2i64;
  m_pFirst = PreparationItem->m_PreparationList.m_pFirst;
  if ( m_pFirst )
  {
    this->pNextItemPrepare = m_pFirst;
    PreparationItem->m_PreparationList.m_pFirst = this;
  }
  else
  {
    PreparationItem->m_PreparationList.m_pLast = this;
    PreparationItem->m_PreparationList.m_pFirst = this;
    this->pNextItemPrepare = 0i64;
  }
  return 1i64;
}

// File Line: 60
// RVA: 0xA9AF80
void __fastcall CAkPreparationAware::UnsubscribePrepare(
        CAkPreparationAware *this,
        unsigned int in_ulGroup,
        AkGroupType in_eGroupType)
{
  CAkStateMgr::PreparationStateItem *PreparationItem; // rax
  CAkStateMgr::PreparationStateItem *v5; // r9
  CAkPreparationAware *m_pFirst; // rax
  CAkPreparationAware *v7; // r8
  CAkPreparationAware *v8; // rdx
  bool v9; // zf
  CAkPreparationAware *pNextItemPrepare; // rax

  PreparationItem = CAkStateMgr::GetPreparationItem(g_pStateMgr, in_ulGroup, in_eGroupType);
  v5 = PreparationItem;
  if ( PreparationItem )
  {
    m_pFirst = PreparationItem->m_PreparationList.m_pFirst;
    v7 = 0i64;
    v8 = m_pFirst;
    if ( m_pFirst )
    {
      while ( v8 != this )
      {
        v7 = v8;
        v8 = v8->pNextItemPrepare;
        if ( !v8 )
          return;
      }
      if ( v8 )
      {
        v9 = v8 == m_pFirst;
        pNextItemPrepare = v8->pNextItemPrepare;
        if ( v9 )
          v5->m_PreparationList.m_pFirst = pNextItemPrepare;
        else
          v7->pNextItemPrepare = pNextItemPrepare;
        if ( v8 == v5->m_PreparationList.m_pLast )
          v5->m_PreparationList.m_pLast = v7;
      }
    }
  }
}

