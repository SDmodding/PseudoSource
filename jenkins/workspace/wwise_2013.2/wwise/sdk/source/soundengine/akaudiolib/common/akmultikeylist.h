// File Line: 31
// RVA: 0xA48280
signed __int64 __fastcall CAkMultiKeyList<unsigned long,AkPendingAction *,2>::Insert(CAkMultiKeyList<unsigned long,AkPendingAction *,2> *this, unsigned int in_Key, AkPendingAction **in_rItem)
{
  AkPendingAction **v3; // rsi
  unsigned int v4; // edi
  CAkMultiKeyList<unsigned long,AkPendingAction *,2> *v5; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v6; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v7; // rdx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v8; // rcx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v10; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v11; // r8

  v3 = in_rItem;
  v4 = in_Key;
  v5 = this;
  if ( !this->m_pFree )
  {
    if ( this->m_ulNumListItems >= this->m_ulMaxNumListItems )
      return 2i64;
    v6 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
    if ( !v6 )
      return 2i64;
    v6->pNextListItem = v5->m_pFree;
    v5->m_pFree = v6;
  }
  v5->m_pFree->Item.key = v4;
  v5->m_pFree->Item.item = *v3;
  v7 = v5->m_pFirst;
  if ( v5->m_pFirst )
  {
    v10 = 0i64;
    do
    {
      if ( v7->Item.key > v4 )
        break;
      v10 = v7;
      v7 = v7->pNextListItem;
    }
    while ( v7 );
    v11 = v5->m_pFree;
    if ( !v7 )
      v5->m_pLast = v11;
    if ( v10 )
      v10->pNextListItem = v11;
    else
      v5->m_pFirst = v11;
    v5->m_pFree = v5->m_pFree->pNextListItem;
    v11->pNextListItem = v7;
  }
  else
  {
    v8 = v5->m_pFree;
    v5->m_pLast = v8;
    v5->m_pFree = v8->pNextListItem;
    v8->pNextListItem = 0i64;
    v5->m_pFirst = v5->m_pLast;
  }
  ++v5->m_ulNumListItems;
  return 1i64;
}

