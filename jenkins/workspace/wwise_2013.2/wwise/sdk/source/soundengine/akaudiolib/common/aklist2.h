// File Line: 275
// RVA: 0xA4BF80
__int64 __fastcall CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::Term(
        CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault> *this)
{
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rcx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *m_pFree; // rdx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *m_pvMemStart; // r8
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rdi
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v6; // rdx

  if ( this->m_ulMaxNumListItems )
  {
    while ( 1 )
    {
      m_pFirst = this->m_pFirst;
      if ( !this->m_pFirst )
        break;
      this->m_pFirst = m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_pLast )
        this->m_pLast = 0i64;
      m_pFirst->pNextListItem = this->m_pFree;
      --this->m_ulNumListItems;
      this->m_pFree = m_pFirst;
    }
    m_pFree = this->m_pFree;
    if ( m_pFree )
    {
      do
      {
        m_pvMemStart = this->m_pvMemStart;
        pNextListItem = m_pFree->pNextListItem;
        if ( m_pFree < m_pvMemStart || m_pFree >= &m_pvMemStart[this->m_ulMinNumListItems] )
          AK::MemoryMgr::Free(g_DefaultPoolId, m_pFree);
        m_pFree = pNextListItem;
      }
      while ( pNextListItem );
    }
    v6 = this->m_pvMemStart;
    if ( v6 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v6);
    *(_QWORD *)&this->m_ulMinNumListItems = 0i64;
    this->m_pFirst = 0i64;
    this->m_pLast = 0i64;
  }
  return 1i64;
}

// File Line: 321
// RVA: 0xA8A600
__int64 __fastcall CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::Reserve(
        CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault> *this,
        unsigned int in_cItems)
{
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v5; // r8
  unsigned int v7; // edx
  unsigned int *p_m_ulReserved; // rax

  if ( in_cItems )
  {
    v4 = (CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 32i64 * in_cItems);
    v5 = v4;
    this->m_pvMemStart = v4;
    if ( !v4 )
      return 52i64;
    this->m_ulMinNumListItems = in_cItems;
    this->m_pFree = v4;
    v7 = 0;
    if ( in_cItems )
    {
      p_m_ulReserved = &v4->Item.item.m_list.m_ulReserved;
      do
      {
        if ( p_m_ulReserved != (unsigned int *)20 )
        {
          *(_QWORD *)(p_m_ulReserved - 3) = 0i64;
          *(_QWORD *)(p_m_ulReserved - 1) = 0i64;
        }
        ++v7;
        ++v5;
        v5[-1].pNextListItem = (CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *)(p_m_ulReserved + 1);
        p_m_ulReserved += 8;
      }
      while ( v7 < this->m_ulMinNumListItems );
    }
    v5[-1].pNextListItem = 0i64;
  }
  return 1i64;
}

// File Line: 382
// RVA: 0xA54900
CAkSwitchAware **__fastcall CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::AddLast(
        CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault> *this,
        CAkSwitchAware *in_rItem)
{
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *m_pFree; // rax
  CAkSwitchAware **result; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v8; // rcx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v9; // rax

  if ( !this->m_pFree )
  {
    if ( this->m_ulNumListItems >= this->m_ulMaxNumListItems )
      return 0i64;
    v4 = (CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                       g_DefaultPoolId,
                                                                                       0x10ui64);
    if ( !v4 )
      return 0i64;
    v4->pNextListItem = this->m_pFree;
    this->m_pFree = v4;
  }
  m_pLast = this->m_pLast;
  m_pFree = this->m_pFree;
  if ( m_pLast )
    m_pLast->pNextListItem = m_pFree;
  else
    this->m_pFirst = m_pFree;
  v8 = this->m_pFree;
  this->m_pLast = v8;
  this->m_pFree = v8->pNextListItem;
  v8->pNextListItem = 0i64;
  v9 = this->m_pLast;
  ++this->m_ulNumListItems;
  result = &v9->Item;
  *result = in_rItem;
  return result;
}

// File Line: 397
// RVA: 0xA621F0
CAkURenderer::ContextNotif *__fastcall CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::AddLast(
        CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault> *this)
{
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v2; // rax
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *m_pFree; // rax
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v6; // rcx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v7; // rax

  if ( !this->m_pFree )
  {
    if ( this->m_ulNumListItems >= this->m_ulMaxNumListItems )
      return 0i64;
    v2 = (CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
    if ( !v2 )
      return 0i64;
    v2->pNextListItem = this->m_pFree;
    this->m_pFree = v2;
  }
  m_pLast = this->m_pLast;
  m_pFree = this->m_pFree;
  if ( m_pLast )
    m_pLast->pNextListItem = m_pFree;
  else
    this->m_pFirst = m_pFree;
  v6 = this->m_pFree;
  this->m_pLast = v6;
  this->m_pFree = v6->pNextListItem;
  v6->pNextListItem = 0i64;
  v7 = this->m_pLast;
  ++this->m_ulNumListItems;
  return &v7->Item;
}

// File Line: 494
// RVA: 0xA46AE0
void __fastcall CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::RemoveAll(
        CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault> *this)
{
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rdx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *m_pvMemStart; // rcx

  while ( 1 )
  {
    m_pFirst = this->m_pFirst;
    if ( !this->m_pFirst )
      break;
    this->m_pFirst = m_pFirst->pNextListItem;
    if ( m_pFirst == this->m_pLast )
      this->m_pLast = 0i64;
    m_pvMemStart = this->m_pvMemStart;
    if ( m_pFirst < m_pvMemStart || m_pFirst >= &m_pvMemStart[this->m_ulMinNumListItems] )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
      --this->m_ulNumListItems;
    }
    else
    {
      m_pFirst->pNextListItem = this->m_pFree;
      --this->m_ulNumListItems;
      this->m_pFree = m_pFirst;
    }
  }
}

// File Line: 742
// RVA: 0xA893E0
char __fastcall CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::CanAddOne(
        CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault> *this)
{
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v2; // rax

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
      v2->pNextListItem = this->m_pFree;
      this->m_pFree = v2;
      return 1;
    }
  }
  return 0;
}

