// File Line: 275
// RVA: 0xA4BF80
signed __int64 __fastcall CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::Term(CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault> *this)
{
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault> *v1; // rbx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v2; // rcx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v3; // rdx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v4; // r8
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v5; // rdi
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v6; // rdx

  v1 = this;
  if ( this->m_ulMaxNumListItems )
  {
    while ( 1 )
    {
      v2 = v1->m_pFirst;
      if ( !v1->m_pFirst )
        break;
      v1->m_pFirst = v2->pNextListItem;
      if ( v2 == v1->m_pLast )
        v1->m_pLast = 0i64;
      v2->pNextListItem = v1->m_pFree;
      --v1->m_ulNumListItems;
      v1->m_pFree = v2;
    }
    v3 = v1->m_pFree;
    if ( v3 )
    {
      do
      {
        v4 = v1->m_pvMemStart;
        v5 = v3->pNextListItem;
        if ( v3 < v4 || v3 >= &v4[v1->m_ulMinNumListItems] )
          AK::MemoryMgr::Free(g_DefaultPoolId, v3);
        v3 = v5;
      }
      while ( v5 );
    }
    v6 = v1->m_pvMemStart;
    if ( v6 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v6);
    *(_QWORD *)&v1->m_ulMinNumListItems = 0i64;
    v1->m_pFirst = 0i64;
    v1->m_pLast = 0i64;
  }
  return 1i64;
}

// File Line: 321
// RVA: 0xA8A600
signed __int64 __fastcall CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::Reserve(CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault> *this, unsigned int in_cItems)
{
  unsigned int v2; // edi
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault> *v3; // rbx
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v5; // r8
  unsigned int v7; // edx
  signed __int64 v8; // rax

  v2 = in_cItems;
  v3 = this;
  if ( in_cItems )
  {
    v4 = (CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 32i64 * in_cItems);
    v5 = v4;
    v3->m_pvMemStart = v4;
    if ( !v4 )
      return 52i64;
    v3->m_ulMinNumListItems = v2;
    v3->m_pFree = v4;
    v7 = 0;
    if ( v2 )
    {
      v8 = (signed __int64)&v4->Item.item.m_list.m_ulReserved;
      do
      {
        if ( v8 != 20 )
        {
          *(_QWORD *)(v8 - 12) = 0i64;
          *(_QWORD *)(v8 - 4) = 0i64;
        }
        ++v7;
        ++v5;
        v5[-1].pNextListItem = (CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *)(v8 + 4);
        v8 += 32i64;
      }
      while ( v7 < v3->m_ulMinNumListItems );
    }
    v5[-1].pNextListItem = 0i64;
  }
  return 1i64;
}

// File Line: 382
// RVA: 0xA54900
CAkSwitchAware **__fastcall CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::AddLast(CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault> *this, CAkSwitchAware *in_rItem)
{
  CAkSwitchAware *v2; // rdi
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault> *v3; // rbx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v5; // rcx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v6; // rax
  CAkSwitchAware **result; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v8; // rcx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v9; // rax

  v2 = in_rItem;
  v3 = this;
  if ( !this->m_pFree )
  {
    if ( this->m_ulNumListItems >= this->m_ulMaxNumListItems )
      return 0i64;
    v4 = (CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                       g_DefaultPoolId,
                                                                                       0x10ui64);
    if ( !v4 )
      return 0i64;
    v4->pNextListItem = v3->m_pFree;
    v3->m_pFree = v4;
  }
  v5 = v3->m_pLast;
  v6 = v3->m_pFree;
  if ( v5 )
    v5->pNextListItem = v6;
  else
    v3->m_pFirst = v6;
  v8 = v3->m_pFree;
  v3->m_pLast = v8;
  v3->m_pFree = v8->pNextListItem;
  v8->pNextListItem = 0i64;
  v9 = v3->m_pLast;
  ++v3->m_ulNumListItems;
  result = &v9->Item;
  *result = v2;
  return result;
}

// File Line: 397
// RVA: 0xA621F0
CAkURenderer::ContextNotif *__fastcall CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::AddLast(CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault> *this)
{
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault> *v1; // rbx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v2; // rax
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v3; // rcx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v6; // rcx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v7; // rax

  v1 = this;
  if ( !this->m_pFree )
  {
    if ( this->m_ulNumListItems >= this->m_ulMaxNumListItems )
      return 0i64;
    v2 = (CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
    if ( !v2 )
      return 0i64;
    v2->pNextListItem = v1->m_pFree;
    v1->m_pFree = v2;
  }
  v3 = v1->m_pLast;
  v4 = v1->m_pFree;
  if ( v3 )
    v3->pNextListItem = v4;
  else
    v1->m_pFirst = v4;
  v6 = v1->m_pFree;
  v1->m_pLast = v6;
  v1->m_pFree = v6->pNextListItem;
  v6->pNextListItem = 0i64;
  v7 = v1->m_pLast;
  ++v1->m_ulNumListItems;
  return &v7->Item;
}

// File Line: 494
// RVA: 0xA46AE0
void __fastcall CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::RemoveAll(CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault> *this)
{
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault> *v1; // rbx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v2; // rdx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v3; // rcx

  v1 = this;
  while ( 1 )
  {
    v2 = v1->m_pFirst;
    if ( !v1->m_pFirst )
      break;
    v1->m_pFirst = v2->pNextListItem;
    if ( v2 == v1->m_pLast )
      v1->m_pLast = 0i64;
    v3 = v1->m_pvMemStart;
    if ( v2 < v3 || v2 >= &v3[v1->m_ulMinNumListItems] )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, v2);
      --v1->m_ulNumListItems;
    }
    else
    {
      v2->pNextListItem = v1->m_pFree;
      --v1->m_ulNumListItems;
      v1->m_pFree = v2;
    }
  }
}

// File Line: 742
// RVA: 0xA893E0
char __fastcall CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::CanAddOne(CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault> *this)
{
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault> *v1; // rbx
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v2; // rax

  v1 = this;
  if ( this->m_pFree )
    return 1;
  if ( this->m_ulNumListItems < this->m_ulMaxNumListItems )
  {
    v2 = (CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x80ui64);
    if ( v2 )
    {
      if ( v2 != (CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *)-8i64 )
      {
        v2->Item.UserParameters.m_PlayingID = 0;
        v2->Item.UserParameters.m_CustomParam.customParam = 0i64;
        v2->Item.UserParameters.m_CustomParam.ui32Reserved = 0;
        v2->Item.UserParameters.m_CustomParam.pExternalSrcs = 0i64;
        v2->Item.PlayHist.arrayIsContinuous.m_iBitArray = 0;
      }
      v2->pNextListItem = v1->m_pFree;
      v1->m_pFree = v2;
      return 1;
    }
  }
  return 0;
}

