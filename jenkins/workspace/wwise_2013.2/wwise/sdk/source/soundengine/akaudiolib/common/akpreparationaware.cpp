// File Line: 30
// RVA: 0xA9AEF0
CAkStateMgr::PreparationStateItem *__fastcall CAkPreparationAware::GetPreparedContent(CAkPreparationAware *this, unsigned int in_ulGroup, AkGroupType in_eGroupType)
{
  CAkStateMgr::PreparationStateItem *result; // rax

  result = CAkStateMgr::GetPreparationItem(g_pStateMgr, in_ulGroup, in_eGroupType);
  if ( result )
    result = (CAkStateMgr::PreparationStateItem *)((char *)result + 8);
  return result;
}

// File Line: 42
// RVA: 0xA9AF20
signed __int64 __fastcall CAkPreparationAware::SubscribePrepare(CAkPreparationAware *this, unsigned int in_ulGroup, AkGroupType in_eGroupType)
{
  CAkPreparationAware *v3; // rbx
  CAkStateMgr::PreparationStateItem *v4; // rax
  CAkPreparationAware *v5; // rcx

  v3 = this;
  v4 = CAkStateMgr::GetPreparationItem(g_pStateMgr, in_ulGroup, in_eGroupType);
  if ( !v4 )
    return 2i64;
  v5 = v4->m_PreparationList.m_pFirst;
  if ( v5 )
  {
    v3->pNextItemPrepare = v5;
    v4->m_PreparationList.m_pFirst = v3;
  }
  else
  {
    v4->m_PreparationList.m_pLast = v3;
    v4->m_PreparationList.m_pFirst = v3;
    v3->pNextItemPrepare = 0i64;
  }
  return 1i64;
}

// File Line: 60
// RVA: 0xA9AF80
void __fastcall CAkPreparationAware::UnsubscribePrepare(CAkPreparationAware *this, unsigned int in_ulGroup, AkGroupType in_eGroupType)
{
  CAkPreparationAware *v3; // rbx
  CAkStateMgr::PreparationStateItem *v4; // rax
  CAkStateMgr::PreparationStateItem *v5; // r9
  CAkPreparationAware *v6; // rax
  CAkPreparationAware *v7; // r8
  CAkPreparationAware *v8; // rdx
  bool v9; // zf
  CAkPreparationAware *v10; // rax

  v3 = this;
  v4 = CAkStateMgr::GetPreparationItem(g_pStateMgr, in_ulGroup, in_eGroupType);
  v5 = v4;
  if ( v4 )
  {
    v6 = v4->m_PreparationList.m_pFirst;
    v7 = 0i64;
    v8 = v6;
    if ( v6 )
    {
      while ( v8 != v3 )
      {
        v7 = v8;
        v8 = v8->pNextItemPrepare;
        if ( !v8 )
          return;
      }
      if ( v8 )
      {
        v9 = v8 == v6;
        v10 = v8->pNextItemPrepare;
        if ( v9 )
          v5->m_PreparationList.m_pFirst = v10;
        else
          v7->pNextItemPrepare = v10;
        if ( v8 == v5->m_PreparationList.m_pLast )
          v5->m_PreparationList.m_pLast = v7;
      }
    }
  }
}

