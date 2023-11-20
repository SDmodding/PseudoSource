// File Line: 58
// RVA: 0xA8A690
AkSwitchNodeParams *__fastcall CAkKeyList<unsigned long,AkSwitchNodeParams,2,ArrayPoolDefault>::Set(CAkKeyList<unsigned long,AkSwitchNodeParams,2,ArrayPoolDefault> *this, unsigned int in_Key, AkSwitchNodeParams *in_Item)
{
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v3; // rax
  int *v4; // r14
  unsigned int v5; // esi
  CAkKeyList<unsigned long,AkSwitchNodeParams,2,ArrayPoolDefault> *v6; // rbx
  AkSwitchNodeParams *v7; // rdi
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v8; // rax
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v9; // rcx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v10; // rax
  AkSwitchNodeParams *result; // rax
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v12; // rcx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v13; // rax
  signed __int64 v14; // rax

  v3 = this->m_pFirst;
  v4 = &in_Item->FadeOutTime;
  v5 = in_Key;
  v6 = this;
  if ( this->m_pFirst )
  {
    while ( v3->Item.key != in_Key )
    {
      v3 = v3->pNextListItem;
      if ( !v3 )
        goto LABEL_4;
    }
    v7 = &v3->Item.item;
    if ( v3 != (CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *)-12i64 )
    {
      v7->FadeOutTime = in_Item->FadeOutTime;
      v3->Item.item.FadeInTime = in_Item->FadeInTime;
      *((_DWORD *)&v3->Item.item + 2) = *((_DWORD *)in_Item + 2);
      return v7;
    }
  }
  else
  {
LABEL_4:
    v7 = 0i64;
  }
  if ( !this->m_pFree )
  {
    if ( this->m_ulNumListItems >= this->m_ulMaxNumListItems )
      return v7;
    v8 = (CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
    if ( !v8 )
      return v7;
    v8->pNextListItem = v6->m_pFree;
    v6->m_pFree = v8;
  }
  v9 = v6->m_pLast;
  v10 = v6->m_pFree;
  if ( v9 )
    v9->pNextListItem = v10;
  else
    v6->m_pFirst = v10;
  v12 = v6->m_pFree;
  v6->m_pLast = v12;
  v6->m_pFree = v12->pNextListItem;
  v12->pNextListItem = 0i64;
  v13 = v6->m_pLast;
  ++v6->m_ulNumListItems;
  v14 = (signed __int64)&v13->Item;
  if ( !v14 )
    return v7;
  *(_DWORD *)v14 = v5;
  result = (AkSwitchNodeParams *)(v14 + 4);
  result->FadeOutTime = *v4;
  result->FadeInTime = v4[1];
  *((_DWORD *)result + 2) = v4[2];
  return result;
}

// File Line: 79
// RVA: 0xA7D230
CAkDuckItem *__fastcall CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault>::Set(CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault> *this, unsigned int in_Key)
{
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v2; // rax
  unsigned int v3; // esi
  CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault> *v4; // rbx
  signed __int64 v5; // rdi
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v6; // rax
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v7; // rcx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v8; // rax
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v10; // rcx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v11; // rax
  unsigned int *v12; // rax

  v2 = this->m_pFirst;
  v3 = in_Key;
  v4 = this;
  if ( this->m_pFirst )
  {
    while ( v2->Item.key != in_Key )
    {
      v2 = v2->pNextListItem;
      if ( !v2 )
        goto LABEL_4;
    }
    v5 = (signed __int64)&v2->Item.item;
    if ( v2 != (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)-16i64 )
      return (CAkDuckItem *)v5;
  }
  else
  {
LABEL_4:
    v5 = 0i64;
  }
  if ( !this->m_pFree )
  {
    if ( this->m_ulNumListItems >= this->m_ulMaxNumListItems )
      return (CAkDuckItem *)v5;
    v6 = (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
    if ( !v6 )
      return (CAkDuckItem *)v5;
    if ( v6 != (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)-8i64 )
      v6->Item.item.vfptr = (ITransitionableVtbl *)&CAkDuckItem::`vftable';
    v6->pNextListItem = v4->m_pFree;
    v4->m_pFree = v6;
  }
  v7 = v4->m_pLast;
  v8 = v4->m_pFree;
  if ( v7 )
    v7->pNextListItem = v8;
  else
    v4->m_pFirst = v8;
  v10 = v4->m_pFree;
  v4->m_pLast = v10;
  v4->m_pFree = v10->pNextListItem;
  v10->pNextListItem = 0i64;
  v11 = v4->m_pLast;
  ++v4->m_ulNumListItems;
  v12 = &v11->Item.key;
  if ( !v12 )
    return (CAkDuckItem *)v5;
  *v12 = v3;
  return (CAkDuckItem *)(v12 + 2);
}

