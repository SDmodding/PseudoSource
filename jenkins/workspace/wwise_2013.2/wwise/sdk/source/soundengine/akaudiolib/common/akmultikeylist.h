// File Line: 31
// RVA: 0xA48280
__int64 __fastcall CAkMultiKeyList<unsigned long,AkPendingAction *,2>::Insert(
        CAkMultiKeyList<unsigned long,AkPendingAction *,2> *this,
        unsigned int in_Key,
        AkPendingAction **in_rItem)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v6; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rdx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v8; // rcx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v10; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFree; // r8

  if ( !this->m_pFree )
  {
    if ( this->m_ulNumListItems >= this->m_ulMaxNumListItems )
      return 2i64;
    v6 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
    if ( !v6 )
      return 2i64;
    v6->pNextListItem = this->m_pFree;
    this->m_pFree = v6;
  }
  this->m_pFree->Item.key = in_Key;
  this->m_pFree->Item.item = *in_rItem;
  m_pFirst = this->m_pFirst;
  if ( this->m_pFirst )
  {
    v10 = 0i64;
    do
    {
      if ( m_pFirst->Item.key > in_Key )
        break;
      v10 = m_pFirst;
      m_pFirst = m_pFirst->pNextListItem;
    }
    while ( m_pFirst );
    m_pFree = this->m_pFree;
    if ( !m_pFirst )
      this->m_pLast = m_pFree;
    if ( v10 )
      v10->pNextListItem = m_pFree;
    else
      this->m_pFirst = m_pFree;
    this->m_pFree = this->m_pFree->pNextListItem;
    m_pFree->pNextListItem = m_pFirst;
  }
  else
  {
    v8 = this->m_pFree;
    this->m_pLast = v8;
    this->m_pFree = v8->pNextListItem;
    v8->pNextListItem = 0i64;
    this->m_pFirst = this->m_pLast;
  }
  ++this->m_ulNumListItems;
  return 1i64;
}

