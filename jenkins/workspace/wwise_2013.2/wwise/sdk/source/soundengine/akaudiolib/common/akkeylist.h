// File Line: 58
// RVA: 0xA8A690
AkSwitchNodeParams *__fastcall CAkKeyList<unsigned long,AkSwitchNodeParams,2,ArrayPoolDefault>::Set(
        CAkKeyList<unsigned long,AkSwitchNodeParams,2,ArrayPoolDefault> *this,
        unsigned int in_Key,
        AkSwitchNodeParams *in_Item)
{
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  AkSwitchNodeParams *p_item; // rdi
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v8; // rax
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *m_pFree; // rax
  AkSwitchNodeParams *result; // rax
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v12; // rcx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v13; // rax
  MapStruct<unsigned long,AkSwitchNodeParams> *v14; // rax

  m_pFirst = this->m_pFirst;
  if ( this->m_pFirst )
  {
    while ( m_pFirst->Item.key != in_Key )
    {
      m_pFirst = m_pFirst->pNextListItem;
      if ( !m_pFirst )
        goto LABEL_4;
    }
    p_item = &m_pFirst->Item.item;
    if ( m_pFirst != (CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *)-12i64 )
    {
      p_item->FadeOutTime = in_Item->FadeOutTime;
      m_pFirst->Item.item.FadeInTime = in_Item->FadeInTime;
      *((_DWORD *)&m_pFirst->Item.item + 2) = *((_DWORD *)in_Item + 2);
      return p_item;
    }
  }
  else
  {
LABEL_4:
    p_item = 0i64;
  }
  if ( !this->m_pFree )
  {
    if ( this->m_ulNumListItems >= this->m_ulMaxNumListItems )
      return p_item;
    v8 = (CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
    if ( !v8 )
      return p_item;
    v8->pNextListItem = this->m_pFree;
    this->m_pFree = v8;
  }
  m_pLast = this->m_pLast;
  m_pFree = this->m_pFree;
  if ( m_pLast )
    m_pLast->pNextListItem = m_pFree;
  else
    this->m_pFirst = m_pFree;
  v12 = this->m_pFree;
  this->m_pLast = v12;
  this->m_pFree = v12->pNextListItem;
  v12->pNextListItem = 0i64;
  v13 = this->m_pLast;
  ++this->m_ulNumListItems;
  v14 = &v13->Item;
  if ( !v14 )
    return p_item;
  v14->key = in_Key;
  result = &v14->item;
  result->FadeOutTime = in_Item->FadeOutTime;
  result->FadeInTime = in_Item->FadeInTime;
  *((_DWORD *)result + 2) = *((_DWORD *)in_Item + 2);
  return result;
}

// File Line: 79
// RVA: 0xA7D230
CAkDuckItem *__fastcall CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault>::Set(
        CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault> *this,
        unsigned int in_Key)
{
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  CAkDuckItem *p_item; // rdi
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v6; // rax
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *m_pFree; // rax
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v10; // rcx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v11; // rax
  MapStruct<unsigned long,CAkDuckItem> *v12; // rax

  m_pFirst = this->m_pFirst;
  if ( this->m_pFirst )
  {
    while ( m_pFirst->Item.key != in_Key )
    {
      m_pFirst = m_pFirst->pNextListItem;
      if ( !m_pFirst )
        goto LABEL_4;
    }
    p_item = &m_pFirst->Item.item;
    if ( m_pFirst != (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)-16i64 )
      return p_item;
  }
  else
  {
LABEL_4:
    p_item = 0i64;
  }
  if ( !this->m_pFree )
  {
    if ( this->m_ulNumListItems >= this->m_ulMaxNumListItems )
      return p_item;
    v6 = (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
    if ( !v6 )
      return p_item;
    if ( v6 != (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)-8i64 )
      v6->Item.item.vfptr = (ITransitionableVtbl *)&CAkDuckItem::`vftable;
    v6->pNextListItem = this->m_pFree;
    this->m_pFree = v6;
  }
  m_pLast = this->m_pLast;
  m_pFree = this->m_pFree;
  if ( m_pLast )
    m_pLast->pNextListItem = m_pFree;
  else
    this->m_pFirst = m_pFree;
  v10 = this->m_pFree;
  this->m_pLast = v10;
  this->m_pFree = v10->pNextListItem;
  v10->pNextListItem = 0i64;
  v11 = this->m_pLast;
  ++this->m_ulNumListItems;
  v12 = &v11->Item;
  if ( !v12 )
    return p_item;
  v12->key = in_Key;
  return &v12->item;
}

