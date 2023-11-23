// File Line: 58
// RVA: 0xA580E0
void __fastcall CAkRTPCMgr::CAkRTPCTransition::TransUpdateValue(
        CAkRTPCMgr::CAkRTPCTransition *this,
        __int64 __formal,
        float in_unionValue,
        bool in_bIsTerminated)
{
  bool in_bUnsetValue; // bp
  CAkRTPCMgr::AkRTPCEntry *m_pOwner; // rdi
  CAkRTPCMgr::AkRTPCValue *v8; // rax
  CAkRTPCMgr::AkRTPCEntry *v9; // rdx
  CAkRTPCMgr::CAkRTPCTransition *v10; // rcx
  CAkRTPCMgr::CAkRTPCTransition *m_pFirst; // r8
  CAkRTPCMgr::CAkRTPCTransition *v12; // rax
  bool v13; // zf
  CAkRTPCMgr::CAkRTPCTransition *pNextLightItem; // rax
  int v15; // ecx

  in_bUnsetValue = this->m_bRemoveEntryWhenDone && in_bIsTerminated;
  m_pOwner = this->m_pOwner;
  v8 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         &m_pOwner->values,
         this->m_pGameObject);
  CAkRTPCMgr::AkRTPCEntry::ApplyRTPCValue(m_pOwner, v8, in_unionValue, this->m_pGameObject, in_bUnsetValue);
  if ( in_bIsTerminated )
  {
    v9 = this->m_pOwner;
    v10 = 0i64;
    m_pFirst = v9->transitions.m_pFirst;
    v12 = m_pFirst;
    if ( m_pFirst )
    {
      while ( v12 != this )
      {
        v10 = v12;
        v12 = v12->pNextLightItem;
        if ( !v12 )
          goto LABEL_14;
      }
      if ( v12 )
      {
        v13 = v12 == m_pFirst;
        pNextLightItem = v12->pNextLightItem;
        if ( v13 )
          v9->transitions.m_pFirst = pNextLightItem;
        else
          v10->pNextLightItem = pNextLightItem;
      }
    }
LABEL_14:
    this->m_pTransition = 0i64;
    v15 = g_DefaultPoolId;
    this->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
    AK::MemoryMgr::Free(v15, this);
  }
}

// File Line: 80
// RVA: 0xA57770
__int64 __fastcall CAkRTPCMgr::CAkRTPCTransition::Start(
        CAkRTPCMgr::CAkRTPCTransition *this,
        float in_fStartValue,
        float in_fTargetValue,
        TransParams *in_transParams,
        bool in_bRemoveEntryWhenDone)
{
  int TransitionTime; // eax
  CAkTransition *v7; // rax
  TransitionParameters in_Params; // [rsp+20h] [rbp-38h] BYREF

  TransitionTime = in_transParams->TransitionTime;
  in_Params.pUser = this;
  in_Params.fStartValue = in_fStartValue;
  in_Params.fTargetValue = in_fTargetValue;
  in_Params.lDuration = TransitionTime;
  in_Params.eFadeCurve = in_transParams->eFadeCurve;
  this->m_bRemoveEntryWhenDone = in_bRemoveEntryWhenDone;
  in_Params.eTarget = 0x10000000i64;
  *(_WORD *)&in_Params.bdBs = 0;
  v7 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, 1, TC_Fade);
  this->m_pTransition = v7;
  return 2 - (unsigned int)(v7 != 0i64);
}

// File Line: 126
// RVA: 0xA54700
void __fastcall CAkRTPCMgr::AkRTPCEntry::~AkRTPCEntry(CAkRTPCMgr::AkRTPCEntry *this)
{
  CAkRTPCMgr::CAkRTPCTransition *m_pFirst; // rbx
  CAkTransition *m_pTransition; // rdx
  int v4; // esi
  CAkRTPCMgr::AkRTPCValue *m_pItems; // rdx
  CAkRTPCMgr::AkRTPCSubscription **v6; // rdx

  m_pFirst = this->transitions.m_pFirst;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      if ( m_pFirst == this->transitions.m_pFirst )
        this->transitions.m_pFirst = m_pFirst->pNextLightItem;
      else
        MEMORY[8] = m_pFirst->pNextLightItem;
      m_pTransition = m_pFirst->m_pTransition;
      v4 = g_DefaultPoolId;
      m_pFirst->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
      if ( m_pTransition )
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, m_pTransition, m_pFirst);
      AK::MemoryMgr::Free(v4, m_pFirst);
    }
  }
  m_pItems = this->values.m_pItems;
  this->values.m_uLength = 0;
  if ( m_pItems )
  {
    this->values.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->values.m_pItems = 0i64;
    this->values.m_ulReserved = 0;
  }
  v6 = this->subscriptions.m_pItems;
  if ( v6 )
  {
    this->subscriptions.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v6);
    this->subscriptions.m_pItems = 0i64;
    this->subscriptions.m_ulReserved = 0;
  }
}

// File Line: 136
// RVA: 0xA56CE0
void __fastcall CAkRTPCMgr::AkRTPCEntry::RemoveGameObject(CAkRTPCMgr::AkRTPCEntry *this, CAkRegisteredObj *in_pGameObj)
{
  CAkRTPCMgr::CAkRTPCTransition *v4; // rbx
  CAkTransition *v5; // rdx
  int v6; // esi
  CAkRTPCMgr::CAkRTPCTransition *m_pFirst; // rax
  CAkRTPCMgr::CAkRTPCTransition *v8; // rcx
  CAkRTPCMgr::CAkRTPCTransition *v9; // rbx
  bool v10; // zf
  CAkRTPCMgr::CAkRTPCTransition *pNextLightItem; // rax
  CAkTransition *m_pTransition; // rdx
  int v13; // r14d

  if ( in_pGameObj )
  {
    m_pFirst = this->transitions.m_pFirst;
    if ( m_pFirst )
    {
      v8 = 0i64;
      v9 = m_pFirst;
      while ( v9->m_pGameObject != in_pGameObj )
      {
        v8 = v9;
        v9 = v9->pNextLightItem;
        if ( !v9 )
          goto LABEL_21;
      }
      v10 = v9 == m_pFirst;
      pNextLightItem = v9->pNextLightItem;
      if ( v10 )
        this->transitions.m_pFirst = pNextLightItem;
      else
        v8->pNextLightItem = pNextLightItem;
      m_pTransition = v9->m_pTransition;
      v13 = g_DefaultPoolId;
      v9->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
      if ( m_pTransition )
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, m_pTransition, v9);
      AK::MemoryMgr::Free(v13, v9);
    }
LABEL_21:
    AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8>::Unset<CAkRegisteredObj *>(
      &this->values,
      in_pGameObj);
  }
  else
  {
    v4 = this->transitions.m_pFirst;
    if ( v4 )
    {
      while ( 1 )
      {
        if ( v4 == this->transitions.m_pFirst )
          this->transitions.m_pFirst = v4->pNextLightItem;
        else
          MEMORY[8] = v4->pNextLightItem;
        v5 = v4->m_pTransition;
        v6 = g_DefaultPoolId;
        v4->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
        if ( v5 )
          CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v5, v4);
        AK::MemoryMgr::Free(v6, v4);
      }
    }
    this->values.m_uLength = 0;
  }
}

// File Line: 174
// RVA: 0xA55CD0
void __fastcall CAkRTPCMgr::AkRTPCEntry::GetRTPCExceptions(
        CAkRTPCMgr::AkRTPCEntry *this,
        AkArray<CAkRegisteredObj *,CAkRegisteredObj *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *io_ExceptArrayObj)
{
  unsigned int m_uLength; // ebx
  CAkRegisteredObj **v5; // rax
  CAkRTPCMgr::AkRTPCValue *m_pItems; // rbx
  CAkRTPCMgr::AkRTPCValue *v7; // rdi
  CAkRegisteredObj *pGameObj; // rbp
  unsigned __int64 v9; // r15
  unsigned __int64 m_ulReserved; // rax
  unsigned int v11; // r12d
  CAkRegisteredObj **v12; // r14
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // rdx
  __int64 v15; // rcx
  CAkRegisteredObj **v16; // rdx

  m_uLength = this->values.m_uLength;
  if ( m_uLength )
  {
    v5 = (CAkRegisteredObj **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * m_uLength);
    io_ExceptArrayObj->m_pItems = v5;
    if ( v5 )
      io_ExceptArrayObj->m_ulReserved = m_uLength;
  }
  m_pItems = this->values.m_pItems;
  v7 = &m_pItems[this->values.m_uLength];
  if ( m_pItems != v7 )
  {
    while ( 1 )
    {
      pGameObj = m_pItems->pGameObj;
      if ( m_pItems->pGameObj )
      {
        v9 = io_ExceptArrayObj->m_uLength;
        m_ulReserved = io_ExceptArrayObj->m_ulReserved;
        if ( v9 < m_ulReserved )
          goto LABEL_13;
        v11 = m_ulReserved + 8;
        v12 = (CAkRegisteredObj **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(m_ulReserved + 8));
        if ( v12 )
          break;
      }
LABEL_16:
      if ( ++m_pItems == v7 )
        return;
    }
    v13 = io_ExceptArrayObj->m_uLength;
    if ( io_ExceptArrayObj->m_pItems )
    {
      v14 = 0i64;
      if ( io_ExceptArrayObj->m_uLength )
      {
        do
        {
          ++v14;
          v12[v14 - 1] = io_ExceptArrayObj->m_pItems[v14 - 1];
        }
        while ( v14 < v13 );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, io_ExceptArrayObj->m_pItems);
    }
    io_ExceptArrayObj->m_pItems = v12;
    io_ExceptArrayObj->m_ulReserved = v11;
LABEL_13:
    if ( v9 < io_ExceptArrayObj->m_ulReserved )
    {
      v15 = io_ExceptArrayObj->m_uLength;
      v16 = &io_ExceptArrayObj->m_pItems[v15];
      io_ExceptArrayObj->m_uLength = v15 + 1;
      if ( v16 )
        *v16 = pGameObj;
    }
    goto LABEL_16;
  }
}

// File Line: 184
// RVA: 0xA546C0
void __fastcall CAkRTPCMgr::CAkRTPCMgr(CAkRTPCMgr *this)
{
  this->m_RTPCEntries.m_uiSize = 0;
  this->m_SwitchEntries.m_uiSize = 0;
  this->m_SwitchEntries.m_MemPoolId = -1;
  this->m_RTPCSubscribers.m_uiSize = 0;
  *(_QWORD *)&this->m_listSwitchSubscribers.m_ulMinNumListItems = 0i64;
  this->m_listSwitchSubscribers.m_ulNumListItems = 0;
  *(_QWORD *)&this->m_listRTPCSwitch.m_ulMinNumListItems = 0i64;
  this->m_listRTPCSwitch.m_ulNumListItems = 0;
}

// File Line: 192
// RVA: 0xA56140
__int64 __fastcall CAkRTPCMgr::Init(CAkRTPCMgr *this)
{
  AkHashList<AkSwitchKey,unsigned long,193>::Item **m_table; // rax
  __int64 v3; // rcx
  __int64 v4; // rdx
  __int64 v5; // rdx
  CAkRTPCMgr *v6; // rax
  AkHashListBare<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription,193,AkDefaultHashListBarePolicy<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription> > *p_m_RTPCSubscribers; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v8; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v9; // rcx
  unsigned int v10; // edi
  unsigned int v11; // edx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v12; // rax

  this->m_SwitchEntries.m_MemPoolId = g_DefaultPoolId;
  m_table = this->m_SwitchEntries.m_table;
  this->m_SwitchEntries.m_uiSize = 0;
  v3 = 24i64;
  v4 = 24i64;
  do
  {
    *m_table = 0i64;
    m_table[1] = 0i64;
    m_table[2] = 0i64;
    m_table += 8;
    *(m_table - 5) = 0i64;
    *(m_table - 4) = 0i64;
    *(m_table - 3) = 0i64;
    *(m_table - 2) = 0i64;
    *(m_table - 1) = 0i64;
    --v4;
  }
  while ( v4 );
  *m_table = 0i64;
  v5 = 24i64;
  this->m_RTPCEntries.m_uiSize = 0;
  v6 = this;
  do
  {
    v6->m_RTPCEntries.m_table[0] = 0i64;
    v6->m_RTPCEntries.m_table[1] = 0i64;
    v6->m_RTPCEntries.m_table[2] = 0i64;
    v6 = (CAkRTPCMgr *)((char *)v6 + 64);
    v6[-1].m_listRTPCSwitch.m_pLast = 0i64;
    v6[-1].m_listRTPCSwitch.m_pFree = 0i64;
    *(_QWORD *)&v6[-1].m_listRTPCSwitch.m_ulMinNumListItems = 0i64;
    *(_QWORD *)&v6[-1].m_listRTPCSwitch.m_ulNumListItems = 0i64;
    v6[-1].m_listRTPCSwitch.m_pvMemStart = 0i64;
    --v5;
  }
  while ( v5 );
  v6->m_RTPCEntries.m_table[0] = 0i64;
  p_m_RTPCSubscribers = &this->m_RTPCSubscribers;
  this->m_RTPCSubscribers.m_uiSize = 0;
  do
  {
    p_m_RTPCSubscribers->m_table[0] = 0i64;
    p_m_RTPCSubscribers->m_table[1] = 0i64;
    p_m_RTPCSubscribers->m_table[2] = 0i64;
    p_m_RTPCSubscribers = (AkHashListBare<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription,193,AkDefaultHashListBarePolicy<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription> > *)((char *)p_m_RTPCSubscribers + 64);
    p_m_RTPCSubscribers[-1].m_table[189] = 0i64;
    p_m_RTPCSubscribers[-1].m_table[190] = 0i64;
    p_m_RTPCSubscribers[-1].m_table[191] = 0i64;
    p_m_RTPCSubscribers[-1].m_table[192] = 0i64;
    *(_QWORD *)&p_m_RTPCSubscribers[-1].m_uiSize = 0i64;
    --v3;
  }
  while ( v3 );
  p_m_RTPCSubscribers->m_table[0] = 0i64;
  this->m_listSwitchSubscribers.m_ulNumListItems = 0;
  this->m_listSwitchSubscribers.m_ulMaxNumListItems = -1;
  this->m_listSwitchSubscribers.m_pFree = 0i64;
  v8 = (CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x180ui64);
  v9 = v8;
  this->m_listSwitchSubscribers.m_pvMemStart = v8;
  if ( v8 )
  {
    this->m_listSwitchSubscribers.m_ulMinNumListItems = 16;
    this->m_listSwitchSubscribers.m_pFree = v8;
    v11 = 0;
    do
    {
      v12 = v9 + 1;
      ++v11;
      v9->pNextListItem = v9 + 1;
      ++v9;
    }
    while ( v11 < this->m_listSwitchSubscribers.m_ulMinNumListItems );
    v12[-1].pNextListItem = 0i64;
    v10 = 1;
  }
  else
  {
    v10 = 52;
  }
  this->m_listSwitchSubscribers.m_pFirst = 0i64;
  this->m_listSwitchSubscribers.m_pLast = 0i64;
  if ( v10 == 1 )
  {
    this->m_listRTPCSwitch.m_ulNumListItems = 0;
    this->m_listRTPCSwitch.m_ulMaxNumListItems = -1;
    this->m_listRTPCSwitch.m_pFree = 0i64;
    this->m_listRTPCSwitch.m_pvMemStart = 0i64;
    this->m_listRTPCSwitch.m_pFirst = 0i64;
    this->m_listRTPCSwitch.m_pLast = 0i64;
    return 1i64;
  }
  else
  {
    CAkRTPCMgr::Term(this);
    return v10;
  }
}

// File Line: 213
// RVA: 0xA57E60
__int64 __fastcall CAkRTPCMgr::Term(CAkRTPCMgr *this)
{
  CAkRTPCMgr::AkRTPCEntry *v1; // rdi
  __int64 v3; // rdx
  __int64 v4; // rbp
  CAkRTPCMgr::AkRTPCEntry *pNextItem; // r9
  CAkRTPCMgr::AkRTPCEntry *v6; // r15
  __int64 v7; // rcx
  __int64 v8; // r8
  int v9; // ebx
  AkHashListBare<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription,193,AkDefaultHashListBarePolicy<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription> > *p_m_RTPCSubscribers; // r15
  __int64 v11; // rdx
  __int64 v12; // rbp
  CAkRTPCMgr::AkRTPCSubscription *v13; // rbx
  CAkRTPCMgr::AkRTPCSubscription *v14; // r9
  CAkRTPCMgr::AkRTPCSubscription *v15; // rdi
  __int64 v16; // rcx
  __int64 v17; // r8
  CAkRTPCMgr::RTPCCurve *m_pItems; // rdx
  int v19; // r12d
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *i; // rbx
  AkRTPCGraphPointBase<unsigned long> *m_pArrayGraphPoints; // rdx
  int v23; // [rsp+28h] [rbp-60h]
  int v24; // [rsp+28h] [rbp-60h]

  v1 = this->m_RTPCEntries.m_table[0];
  LODWORD(v3) = 0;
  v4 = 0i64;
  if ( this->m_RTPCEntries.m_table[0] )
    goto LABEL_35;
  while ( 1 )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= 0xC1 )
      break;
    v1 = this->m_RTPCEntries.m_table[v3];
    if ( v1 )
      goto LABEL_6;
  }
  if ( v1 )
  {
LABEL_35:
    while ( 1 )
    {
LABEL_6:
      pNextItem = v1->pNextItem;
      v6 = v1;
      LODWORD(v7) = v3;
      v23 = v3;
      v8 = v4;
      v1 = pNextItem;
      if ( !pNextItem )
      {
        do
        {
          v7 = (unsigned int)(v7 + 1);
          if ( (unsigned int)v7 >= 0xC1 )
            break;
          v1 = this->m_RTPCEntries.m_table[v7];
          v8 = 0i64;
        }
        while ( !v1 );
        v23 = v7;
      }
      this->m_RTPCEntries.m_table[(unsigned int)v3] = pNextItem;
      --this->m_RTPCEntries.m_uiSize;
      v9 = g_DefaultPoolId;
      v4 = v8;
      CAkRTPCMgr::AkRTPCEntry::~AkRTPCEntry(v6);
      AK::MemoryMgr::Free(v9, v6);
      if ( !v1 )
        break;
      LODWORD(v3) = v23;
    }
  }
  p_m_RTPCSubscribers = &this->m_RTPCSubscribers;
  LODWORD(v11) = 0;
  v12 = 0i64;
  v13 = this->m_RTPCSubscribers.m_table[0];
  if ( v13 )
  {
    while ( 1 )
    {
LABEL_17:
      v14 = v13->pNextItem;
      v15 = v13;
      LODWORD(v16) = v11;
      v24 = v11;
      v17 = v12;
      v13 = v14;
      if ( !v14 )
      {
        do
        {
          v16 = (unsigned int)(v16 + 1);
          if ( (unsigned int)v16 >= 0xC1 )
            break;
          v13 = p_m_RTPCSubscribers->m_table[v16];
          v17 = 0i64;
        }
        while ( !v13 );
        v24 = v16;
      }
      p_m_RTPCSubscribers->m_table[(unsigned int)v11] = v14;
      --this->m_RTPCSubscribers.m_uiSize;
      v12 = v17;
      CAkRTPCMgr::RemoveReferencesToSubscription(this, v15);
      m_pItems = v15->Curves.m_pItems;
      v19 = g_DefaultPoolId;
      if ( m_pItems )
      {
        v15->Curves.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
        v15->Curves.m_pItems = 0i64;
        v15->Curves.m_ulReserved = 0;
      }
      AK::MemoryMgr::Free(v19, v15);
      if ( !v13 )
        break;
      LODWORD(v11) = v24;
    }
  }
  else
  {
    while ( 1 )
    {
      v11 = (unsigned int)(v11 + 1);
      if ( (unsigned int)v11 >= 0xC1 )
        break;
      v13 = p_m_RTPCSubscribers->m_table[v11];
      if ( v13 )
        goto LABEL_17;
    }
  }
  if ( this->m_listRTPCSwitch.m_ulMaxNumListItems )
  {
    for ( i = this->m_listRTPCSwitch.m_pFirst; i; i = i->pNextListItem )
    {
      CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::Term(&i->Item.listRTPCSwitchSubscribers);
      m_pArrayGraphPoints = i->Item.ConversionTable.m_pArrayGraphPoints;
      if ( m_pArrayGraphPoints )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayGraphPoints);
        i->Item.ConversionTable.m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&i->Item.ConversionTable.m_ulArraySize = 0i64;
    }
  }
  if ( this->m_SwitchEntries.m_MemPoolId != -1 )
  {
    AkHashList<AkSwitchKey,unsigned long,193>::RemoveAll(&this->m_SwitchEntries);
    this->m_SwitchEntries.m_MemPoolId = -1;
  }
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::Term((CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault> *)&this->m_listSwitchSubscribers);
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::Term(&this->m_listRTPCSwitch);
  return 1i64;
}

// File Line: 255
// RVA: 0xA54990
AKRESULT __fastcall CAkRTPCMgr::AddSwitchRTPC(
        CAkRTPCMgr *this,
        unsigned int in_switchGroup,
        unsigned int in_RTPC_ID,
        AkRTPCGraphPointBase<float> *in_pArrayConversion,
        unsigned int in_ulConversionArraySize)
{
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v10; // rax
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *m_pFree; // rax
  CAkConversionTable<AkRTPCGraphPointBase<unsigned long>,unsigned long> *p_ConversionTable; // rbx
  AkRTPCGraphPointBase<unsigned long> *m_pArrayGraphPoints; // rdx
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v16; // rcx
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v17; // rbx
  CAkRTPCMgr::AkRTPCSwitchAssociation *p_Item; // rbx
  AKRESULT v19; // r15d
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v20; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v21; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rdx
  CAkSwitchAware *pSwitch; // r14
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v24; // rbx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v25; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v26; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v27; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v28; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v29; // rcx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v30; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v31; // rcx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v32; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v33; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v34; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v35; // [rsp+30h] [rbp-38h]
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v36; // [rsp+38h] [rbp-30h]
  __int64 v37; // [rsp+48h] [rbp-20h]

  m_pFirst = this->m_listRTPCSwitch.m_pFirst;
  if ( !m_pFirst )
  {
LABEL_4:
    if ( !this->m_listRTPCSwitch.m_pFree )
    {
      if ( this->m_listRTPCSwitch.m_ulNumListItems >= this->m_listRTPCSwitch.m_ulMaxNumListItems )
        goto LABEL_20;
      v10 = (CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
      if ( !v10 )
        goto LABEL_20;
      if ( v10 != (CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *)-8i64 )
      {
        v10->Item.ConversionTable.m_pArrayGraphPoints = 0i64;
        *(_QWORD *)&v10->Item.ConversionTable.m_ulArraySize = 0i64;
        *(_QWORD *)&v10->Item.listRTPCSwitchSubscribers.m_ulMinNumListItems = 0i64;
        v10->Item.listRTPCSwitchSubscribers.m_ulNumListItems = 0;
      }
      v10->pNextListItem = this->m_listRTPCSwitch.m_pFree;
      this->m_listRTPCSwitch.m_pFree = v10;
    }
    m_pLast = this->m_listRTPCSwitch.m_pLast;
    m_pFree = this->m_listRTPCSwitch.m_pFree;
    if ( m_pLast )
      m_pLast->pNextListItem = m_pFree;
    else
      this->m_listRTPCSwitch.m_pFirst = m_pFree;
    v16 = this->m_listRTPCSwitch.m_pFree;
    this->m_listRTPCSwitch.m_pLast = v16;
    this->m_listRTPCSwitch.m_pFree = v16->pNextListItem;
    v16->pNextListItem = 0i64;
    v17 = this->m_listRTPCSwitch.m_pLast;
    ++this->m_listRTPCSwitch.m_ulNumListItems;
    p_Item = &v17->Item;
    if ( p_Item )
    {
      p_Item->switchGroup = in_switchGroup;
      p_Item->RTPC_ID = in_RTPC_ID;
      v19 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
              (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)&p_Item->ConversionTable,
              in_pArrayConversion,
              in_ulConversionArraySize,
              AkCurveScaling_None);
      if ( v19 == AK_Success )
      {
        p_Item->listRTPCSwitchSubscribers.m_ulNumListItems = 0;
        p_Item->listRTPCSwitchSubscribers.m_ulMaxNumListItems = -1;
        p_Item->listRTPCSwitchSubscribers.m_pFree = 0i64;
        p_Item->listRTPCSwitchSubscribers.m_pvMemStart = 0i64;
        p_Item->listRTPCSwitchSubscribers.m_pFirst = 0i64;
        p_Item->listRTPCSwitchSubscribers.m_pLast = 0i64;
      }
      else
      {
        CAkRTPCMgr::RemoveSwitchRTPC(this, in_switchGroup);
      }
LABEL_21:
      v20 = this->m_listSwitchSubscribers.m_pFirst;
      v21 = 0i64;
      if ( !v20 )
        return v19;
      while ( 1 )
      {
        if ( v20->Item.switchGroup != in_switchGroup )
        {
          v21 = v20;
          v20 = v20->pNextListItem;
          goto LABEL_50;
        }
        pNextListItem = v20->pNextListItem;
        pSwitch = v20->Item.pSwitch;
        v36 = v21;
        v35 = v20->pNextListItem;
        if ( v20 == this->m_listSwitchSubscribers.m_pFirst )
          this->m_listSwitchSubscribers.m_pFirst = pNextListItem;
        else
          v21->pNextListItem = pNextListItem;
        if ( v20 == this->m_listSwitchSubscribers.m_pLast )
          this->m_listSwitchSubscribers.m_pLast = v21;
        v20->pNextListItem = this->m_listSwitchSubscribers.m_pFree;
        --this->m_listSwitchSubscribers.m_ulNumListItems;
        this->m_listSwitchSubscribers.m_pFree = v20;
        v24 = this->m_listRTPCSwitch.m_pFirst;
        if ( v24 )
        {
          while ( v24->Item.switchGroup != in_switchGroup )
          {
            v24 = v24->pNextListItem;
            if ( !v24 )
              goto LABEL_31;
          }
          if ( v24->Item.listRTPCSwitchSubscribers.m_pFree )
            goto LABEL_42;
          if ( v24->Item.listRTPCSwitchSubscribers.m_ulNumListItems < v24->Item.listRTPCSwitchSubscribers.m_ulMaxNumListItems )
          {
            v28 = (CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                                g_DefaultPoolId,
                                                                                                0x10ui64);
            if ( v28 )
            {
              v28->pNextListItem = v24->Item.listRTPCSwitchSubscribers.m_pFree;
              v24->Item.listRTPCSwitchSubscribers.m_pFree = v28;
LABEL_42:
              v29 = v24->Item.listRTPCSwitchSubscribers.m_pLast;
              v30 = v24->Item.listRTPCSwitchSubscribers.m_pFree;
              if ( v29 )
                v29->pNextListItem = v30;
              else
                v24->Item.listRTPCSwitchSubscribers.m_pFirst = v30;
              v31 = v24->Item.listRTPCSwitchSubscribers.m_pFree;
              v24->Item.listRTPCSwitchSubscribers.m_pLast = v31;
              v24->Item.listRTPCSwitchSubscribers.m_pFree = v31->pNextListItem;
              v31->pNextListItem = 0i64;
              v32 = v24->Item.listRTPCSwitchSubscribers.m_pLast;
              ++v24->Item.listRTPCSwitchSubscribers.m_ulNumListItems;
              v20 = v35;
              v32->Item = pSwitch;
              v21 = v36;
              goto LABEL_50;
            }
          }
          goto LABEL_48;
        }
LABEL_31:
        if ( pSwitch )
        {
          CAkRTPCMgr::UnSubscribeSwitch(this, pSwitch);
          LODWORD(v37) = in_switchGroup;
          if ( this->m_listSwitchSubscribers.m_pFree )
            goto LABEL_36;
          if ( this->m_listSwitchSubscribers.m_ulNumListItems < this->m_listSwitchSubscribers.m_ulMaxNumListItems )
          {
            v25 = (CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
            if ( v25 )
              break;
          }
        }
LABEL_48:
        v21 = v36;
        v20 = v35;
LABEL_50:
        if ( !v20 )
          return v19;
      }
      v25->pNextListItem = this->m_listSwitchSubscribers.m_pFree;
      this->m_listSwitchSubscribers.m_pFree = v25;
LABEL_36:
      v26 = this->m_listSwitchSubscribers.m_pLast;
      v27 = this->m_listSwitchSubscribers.m_pFree;
      if ( v26 )
        v26->pNextListItem = v27;
      else
        this->m_listSwitchSubscribers.m_pFirst = v27;
      v33 = this->m_listSwitchSubscribers.m_pFree;
      this->m_listSwitchSubscribers.m_pLast = v33;
      this->m_listSwitchSubscribers.m_pFree = v33->pNextListItem;
      v33->pNextListItem = 0i64;
      v34 = this->m_listSwitchSubscribers.m_pLast;
      ++this->m_listSwitchSubscribers.m_ulNumListItems;
      v34->Item.pSwitch = pSwitch;
      *(_QWORD *)&v34->Item.switchGroup = v37;
      goto LABEL_48;
    }
LABEL_20:
    v19 = AK_Fail;
    goto LABEL_21;
  }
  while ( m_pFirst->Item.switchGroup != in_switchGroup )
  {
    m_pFirst = m_pFirst->pNextListItem;
    if ( !m_pFirst )
      goto LABEL_4;
  }
  p_ConversionTable = &m_pFirst->Item.ConversionTable;
  m_pFirst->Item.RTPC_ID = in_RTPC_ID;
  m_pArrayGraphPoints = m_pFirst->Item.ConversionTable.m_pArrayGraphPoints;
  if ( m_pArrayGraphPoints )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayGraphPoints);
    p_ConversionTable->m_pArrayGraphPoints = 0i64;
  }
  *(_QWORD *)&p_ConversionTable->m_ulArraySize = 0i64;
  return CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
           (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)p_ConversionTable,
           in_pArrayConversion,
           in_ulConversionArraySize,
           AkCurveScaling_None);
}

// File Line: 320
// RVA: 0xA56CA0
AKRESULT __fastcall CAkRTPCMgr::RegisterLayer(CAkRTPCMgr *this, CAkLayer *in_pLayer, unsigned int in_rtpcID)
{
  return CAkRTPCMgr::SubscribeRTPC(
           this,
           in_pLayer,
           in_rtpcID,
           RTPC_MaxNumRTPC,
           0,
           AkCurveScaling_None,
           0i64,
           0,
           0i64,
           SubscriberType_CAkLayer);
}

// File Line: 325
// RVA: 0xA58A20
void __fastcall CAkRTPCMgr::UnregisterLayer(CAkRTPCMgr *this, CAkLayer *in_pLayer, unsigned int in_rtpcID)
{
  CAkRTPCMgr::UnSubscribeRTPC(this, in_pLayer, 0x40u);
}

// File Line: 330
// RVA: 0xA56FD0
void __fastcall CAkRTPCMgr::RemoveSwitchRTPC(CAkRTPCMgr *this, unsigned int in_switchGroup)
{
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rsi
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v5; // r15
  AkRTPCGraphPointBase<unsigned long> *m_pArrayGraphPoints; // rdx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v7; // rbx
  CAkSwitchAware *Item; // rbp
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v9; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *m_pFree; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v12; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v13; // rdx
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  __int64 v15; // [rsp+28h] [rbp-30h]

  m_pFirst = this->m_listRTPCSwitch.m_pFirst;
  v5 = 0i64;
  if ( m_pFirst )
  {
    while ( m_pFirst->Item.switchGroup != in_switchGroup )
    {
      v5 = m_pFirst;
      m_pFirst = m_pFirst->pNextListItem;
      if ( !m_pFirst )
        return;
    }
    m_pArrayGraphPoints = m_pFirst->Item.ConversionTable.m_pArrayGraphPoints;
    if ( m_pArrayGraphPoints )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayGraphPoints);
      m_pFirst->Item.ConversionTable.m_pArrayGraphPoints = 0i64;
    }
    *(_QWORD *)&m_pFirst->Item.ConversionTable.m_ulArraySize = 0i64;
    v7 = m_pFirst->Item.listRTPCSwitchSubscribers.m_pFirst;
    if ( v7 )
    {
      while ( 1 )
      {
        Item = v7->Item;
        if ( Item )
        {
          CAkRTPCMgr::UnSubscribeSwitch(this, v7->Item);
          LODWORD(v15) = in_switchGroup;
          if ( this->m_listSwitchSubscribers.m_pFree )
            goto LABEL_13;
          if ( this->m_listSwitchSubscribers.m_ulNumListItems < this->m_listSwitchSubscribers.m_ulMaxNumListItems )
          {
            v9 = (CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
            if ( v9 )
              break;
          }
        }
LABEL_17:
        v7 = v7->pNextListItem;
        if ( !v7 )
          goto LABEL_18;
      }
      v9->pNextListItem = this->m_listSwitchSubscribers.m_pFree;
      this->m_listSwitchSubscribers.m_pFree = v9;
LABEL_13:
      m_pLast = this->m_listSwitchSubscribers.m_pLast;
      m_pFree = this->m_listSwitchSubscribers.m_pFree;
      if ( m_pLast )
        m_pLast->pNextListItem = m_pFree;
      else
        this->m_listSwitchSubscribers.m_pFirst = m_pFree;
      v12 = this->m_listSwitchSubscribers.m_pFree;
      this->m_listSwitchSubscribers.m_pLast = v12;
      this->m_listSwitchSubscribers.m_pFree = v12->pNextListItem;
      v12->pNextListItem = 0i64;
      v13 = this->m_listSwitchSubscribers.m_pLast;
      ++this->m_listSwitchSubscribers.m_ulNumListItems;
      v13->Item.pSwitch = Item;
      *(_QWORD *)&v13->Item.switchGroup = v15;
      goto LABEL_17;
    }
LABEL_18:
    CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::Term(&m_pFirst->Item.listRTPCSwitchSubscribers);
    pNextListItem = m_pFirst->pNextListItem;
    if ( m_pFirst == this->m_listRTPCSwitch.m_pFirst )
      this->m_listRTPCSwitch.m_pFirst = pNextListItem;
    else
      v5->pNextListItem = pNextListItem;
    if ( m_pFirst == this->m_listRTPCSwitch.m_pLast )
      this->m_listRTPCSwitch.m_pLast = v5;
    m_pFirst->pNextListItem = this->m_listRTPCSwitch.m_pFree;
    --this->m_listRTPCSwitch.m_ulNumListItems;
    this->m_listRTPCSwitch.m_pFree = m_pFirst;
  }
}

// File Line: 357
// RVA: 0xA575A0
__int64 __fastcall CAkRTPCMgr::SetRTPCInternal(
        CAkRTPCMgr *this,
        unsigned int in_RTPCid,
        float in_Value,
        CAkRegisteredObj *in_GameObj,
        TransParams *in_transParams,
        AkValueMeaning in_eValueMeaning)
{
  CAkRTPCMgr::AkRTPCValue *v7; // rdi
  float v10; // xmm6_4
  CAkRTPCMgr::AkRTPCEntry *v11; // rbx
  CAkRTPCMgr::AkRTPCEntry *v12; // rax
  __int64 v13; // rcx

  v7 = 0i64;
  v10 = in_Value;
  v11 = this->m_RTPCEntries.m_table[in_RTPCid % 0xC1];
  if ( v11 )
  {
    while ( v11->key != in_RTPCid )
    {
      v11 = v11->pNextItem;
      if ( !v11 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v11 = 0i64;
  }
  if ( v11 )
  {
    v7 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
           &v11->values,
           in_GameObj);
  }
  else
  {
    v12 = (CAkRTPCMgr::AkRTPCEntry *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
    v11 = v12;
    if ( !v12 )
      return 2i64;
    v12->key = in_RTPCid;
    v12->fDefaultValue = 0.0;
    v12->values.m_pItems = 0i64;
    *(_QWORD *)&v12->values.m_uLength = 0i64;
    v12->transitions.m_pFirst = 0i64;
    v12->subscriptions.m_pItems = 0i64;
    *(_QWORD *)&v12->subscriptions.m_uLength = 0i64;
    v13 = v12->key % 0xC1;
    v12->pNextItem = this->m_RTPCEntries.m_table[v13];
    this->m_RTPCEntries.m_table[v13] = v12;
    ++this->m_RTPCEntries.m_uiSize;
  }
  if ( in_eValueMeaning == AkValueMeaning_Offset )
    v10 = in_Value + CAkRTPCMgr::AkRTPCEntry::GetCurrentTargetValue(v11, v7);
  return CAkRTPCMgr::AkRTPCEntry::SetRTPC(v11, v7, v10, in_GameObj, in_transParams, 0);
}

// File Line: 393
// RVA: 0xA57420
__int64 __fastcall CAkRTPCMgr::AkRTPCEntry::SetRTPC(
        CAkRTPCMgr::AkRTPCEntry *this,
        CAkRTPCMgr::AkRTPCValue *in_pValueEntry,
        float in_Value,
        CAkRegisteredObj *in_GameObj,
        TransParams *in_transParams,
        bool in_bUnsetWhenDone)
{
  bool v10; // r14
  float fValue; // xmm2_4
  CAkRTPCMgr::AkRTPCValue *v12; // rax
  CAkRTPCMgr::CAkRTPCTransition *m_pFirst; // rax
  CAkRTPCMgr::CAkRTPCTransition *v15; // rcx
  CAkRTPCMgr::CAkRTPCTransition *v16; // rbx
  bool v17; // zf
  CAkRTPCMgr::CAkRTPCTransition *pNextLightItem; // rax
  CAkTransition *m_pTransition; // rdx
  int v20; // r15d

  v10 = !in_pValueEntry || in_Value != in_pValueEntry->fValue;
  if ( in_transParams->TransitionTime > 0 && v10 )
  {
    if ( in_pValueEntry )
    {
      fValue = in_pValueEntry->fValue;
    }
    else
    {
      v12 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
              &this->values,
              0i64);
      if ( v12 )
        fValue = v12->fValue;
      else
        fValue = this->fDefaultValue;
    }
    if ( CAkRTPCMgr::AkRTPCEntry::CreateOrModifyTransition(
           this,
           in_GameObj,
           fValue,
           in_Value,
           in_transParams,
           in_bUnsetWhenDone) )
    {
      return 1i64;
    }
  }
  else
  {
    m_pFirst = this->transitions.m_pFirst;
    if ( m_pFirst )
    {
      v15 = 0i64;
      v16 = m_pFirst;
      while ( v16->m_pGameObject != in_GameObj )
      {
        v15 = v16;
        v16 = v16->pNextLightItem;
        if ( !v16 )
          goto LABEL_25;
      }
      v17 = v16 == m_pFirst;
      pNextLightItem = v16->pNextLightItem;
      if ( v17 )
        this->transitions.m_pFirst = pNextLightItem;
      else
        v15->pNextLightItem = pNextLightItem;
      m_pTransition = v16->m_pTransition;
      v20 = g_DefaultPoolId;
      v16->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
      if ( m_pTransition )
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, m_pTransition, v16);
      AK::MemoryMgr::Free(v20, v16);
    }
  }
LABEL_25:
  if ( !v10 && !in_bUnsetWhenDone )
    return 1i64;
  return CAkRTPCMgr::AkRTPCEntry::ApplyRTPCValue(this, in_pValueEntry, in_Value, in_GameObj, in_bUnsetWhenDone);
}

// File Line: 433
// RVA: 0xA55720
float __fastcall CAkRTPCMgr::AkRTPCEntry::GetCurrentTargetValue(
        CAkRTPCMgr::AkRTPCEntry *this,
        CAkRTPCMgr::AkRTPCValue *in_pValueEntry)
{
  CAkRTPCMgr::CAkRTPCTransition *m_pFirst; // rax
  CAkRTPCMgr::AkRTPCValue *v5; // rax

  if ( in_pValueEntry )
  {
    if ( this->transitions.m_pFirst )
    {
      m_pFirst = this->transitions.m_pFirst;
      while ( m_pFirst->m_pGameObject != in_pValueEntry->pGameObj )
      {
        m_pFirst = m_pFirst->pNextLightItem;
        if ( !m_pFirst )
          return in_pValueEntry->fValue;
      }
      return m_pFirst->m_pTransition->m_fTargetValue;
    }
    else
    {
      return in_pValueEntry->fValue;
    }
  }
  else
  {
    v5 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
           &this->values,
           0i64);
    if ( v5 )
      return v5->fValue;
    else
      return this->fDefaultValue;
  }
}

// File Line: 475
// RVA: 0xA55560
bool __fastcall CAkRTPCMgr::AkRTPCEntry::CreateOrModifyTransition(
        CAkRTPCMgr::AkRTPCEntry *this,
        CAkRegisteredObj *in_pGameObj,
        float in_fStartValue,
        float in_fTargetValue,
        TransParams *in_transParams,
        bool in_bRemoveEntryWhenDone)
{
  CAkRTPCMgr::CAkRTPCTransition *v8; // rcx
  CAkRTPCMgr::CAkRTPCTransition *v9; // rbx
  CAkRTPCMgr::CAkRTPCTransition *v10; // rbx
  CAkRTPCMgr::CAkRTPCTransition *m_pFirst; // rax
  bool result; // al
  CAkRTPCMgr::CAkRTPCTransition *pNextLightItem; // rax
  CAkTransition *m_pTransition; // rdx
  int v15; // edi
  CAkRTPCMgr::CAkRTPCTransition *in_pUser; // [rsp+40h] [rbp-38h]

  in_pUser = this->transitions.m_pFirst;
  if ( in_pUser )
  {
    v8 = 0i64;
    v9 = in_pUser;
    while ( v9->m_pGameObject != in_pGameObj )
    {
      v8 = v9;
      v9 = v9->pNextLightItem;
      if ( !v9 )
        goto LABEL_5;
    }
    if ( in_fStartValue != in_fTargetValue )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        v9->m_pTransition,
        0x10000000i64,
        in_fTargetValue,
        in_transParams->TransitionTime,
        in_transParams->eFadeCurve,
        AkValueMeaning_Default);
      v9->m_bRemoveEntryWhenDone = in_bRemoveEntryWhenDone;
      return 1;
    }
    pNextLightItem = v9->pNextLightItem;
    if ( v9 == in_pUser )
      this->transitions.m_pFirst = pNextLightItem;
    else
      v8->pNextLightItem = pNextLightItem;
    m_pTransition = v9->m_pTransition;
    v15 = g_DefaultPoolId;
    v9->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
    if ( m_pTransition )
      CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, m_pTransition, v9);
    AK::MemoryMgr::Free(v15, v9);
    return 0;
  }
LABEL_5:
  if ( in_fStartValue == in_fTargetValue )
    return 0;
  v10 = (CAkRTPCMgr::CAkRTPCTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
  if ( !v10 )
    return 0;
  v10->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
  v10->m_pTransition = 0i64;
  v10->m_pOwner = this;
  v10->m_pGameObject = in_pGameObj;
  v10->m_bRemoveEntryWhenDone = 0;
  if ( CAkRTPCMgr::CAkRTPCTransition::Start(
         v10,
         in_fStartValue,
         in_fTargetValue,
         in_transParams,
         in_bRemoveEntryWhenDone) != AK_Success )
    return 0;
  m_pFirst = this->transitions.m_pFirst;
  if ( m_pFirst )
  {
    v10->pNextLightItem = m_pFirst;
    this->transitions.m_pFirst = v10;
    return 1;
  }
  else
  {
    this->transitions.m_pFirst = v10;
    result = 1;
    v10->pNextLightItem = 0i64;
  }
  return result;
}

// File Line: 535
// RVA: 0xA54D10
__int64 __fastcall CAkRTPCMgr::AkRTPCEntry::ApplyRTPCValue(
        CAkRTPCMgr::AkRTPCEntry *this,
        CAkRTPCMgr::AkRTPCValue *in_pValueEntry,
        float in_NewValue,
        CAkRegisteredObj *in_GameObj,
        bool in_bUnsetValue)
{
  CAkRTPCMgr::AkRTPCValue *v9; // rax

  CAkRTPCMgr::AkRTPCEntry::NotifyRTPCChange(this, in_pValueEntry, in_NewValue, in_GameObj);
  if ( in_bUnsetValue )
  {
    if ( in_pValueEntry )
      AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8>::Unset<CAkRegisteredObj *>(
        &this->values,
        in_GameObj);
    return 1i64;
  }
  else if ( in_pValueEntry )
  {
    in_pValueEntry->fValue = in_NewValue;
    return 1i64;
  }
  else
  {
    v9 = AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8>::Set<CAkRegisteredObj *>(
           &this->values,
           in_GameObj);
    if ( v9 )
    {
      v9->fValue = in_NewValue;
      return 1i64;
    }
    else
    {
      return 2i64;
    }
  }
}

// File Line: 571
// RVA: 0xA56870
void __fastcall CAkRTPCMgr::AkRTPCEntry::NotifyRTPCChange(
        CAkRTPCMgr::AkRTPCEntry *this,
        CAkRTPCMgr::AkRTPCValue *in_pValueEntry,
        float in_NewValue,
        CAkRegisteredObj *in_GameObj)
{
  unsigned int key; // r12d
  CAkRTPCMgr::AkRTPCEntry *v5; // r14
  CAkRTPCMgr::AkRTPCSubscription **m_pItems; // rbx
  char v7; // r8
  CAkRTPCMgr::AkRTPCSubscription **v8; // rdi
  CAkRTPCMgr::AkRTPCSubscription *v10; // rcx
  int v11; // r9d
  CAkRTPCMgr::AkRTPCSubscription *v12; // rsi
  CAkRegisteredObj *TargetGameObject; // rdx
  CAkRTPCMgr::SubscriberType eType; // ecx
  float v15; // xmm6_4
  float v16; // xmm0_4
  void *v17; // rcx
  __int64 ParamID_low; // rdx
  CAkRTPCMgr::RTPCCurve *v19; // rax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v20; // r14
  CAkLayer *v21; // r15
  __int64 v22; // rax
  __int64 v23; // rcx
  CAkRTPCMgr::RTPCCurve *v24; // rax
  float v25; // xmm6_4
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v26; // r14
  AkRTPC_ParameterID v27; // r8d
  __int64 *pSubscriber; // r15
  __int64 v29; // rax
  unsigned int ParamID; // eax
  CAkRTPCMgr::RTPCCurve *v31; // rax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *p_ConversionTable; // r14
  AkArray<CAkRegisteredObj *,CAkRegisteredObj *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *p_io_ExceptArrayObj; // rcx
  __int64 v34; // rax
  __int64 v35; // r8
  char v36; // [rsp+8h] [rbp-29h]
  float in_pParam; // [rsp+Ch] [rbp-25h] BYREF
  unsigned int out_index[4]; // [rsp+10h] [rbp-21h] BYREF
  AkArray<CAkRegisteredObj *,CAkRegisteredObj *,ArrayPoolDefault,8,AkArrayAllocatorDefault> io_ExceptArrayObj; // [rsp+20h] [rbp-11h] BYREF
  void *in_pGameObjExceptArray; // [rsp+30h] [rbp-1h]
  CAkRTPCMgr::AkRTPCEntry *v41; // [rsp+98h] [rbp+67h]
  CAkRTPCMgr::AkRTPCValue *in_pValueEntrya; // [rsp+A0h] [rbp+6Fh]

  key = this->key;
  v5 = this;
  m_pItems = this->subscriptions.m_pItems;
  v7 = 0;
  v8 = &m_pItems[this->subscriptions.m_uLength];
  io_ExceptArrayObj.m_pItems = 0i64;
  *(_QWORD *)&io_ExceptArrayObj.m_uLength = 0i64;
  v36 = 0;
  v10 = 0i64;
  if ( m_pItems == v8 )
    goto LABEL_65;
  v11 = 523241489;
  do
  {
    v12 = *m_pItems;
    if ( *m_pItems != v10 )
    {
      TargetGameObject = v12->TargetGameObject;
      v10 = *m_pItems;
      if ( in_GameObj == TargetGameObject || !in_GameObj || !TargetGameObject )
      {
        eType = v12->eType;
        v15 = 0.0;
        in_pParam = 0.0;
        if ( (unsigned int)(eType - 1) <= 1 )
        {
          if ( in_GameObj && eType == SubscriberType_CAkBus )
            goto LABEL_61;
          pSubscriber = (__int64 *)v12->key.pSubscriber;
          v29 = *((_QWORD *)v12->key.pSubscriber + 6);
          if ( !v29 || !*(_WORD *)(v29 + 72) && !*(_WORD *)(v29 + 74) )
          {
            if ( eType != SubscriberType_CAkBus )
              goto LABEL_61;
            ParamID = v12->key.ParamID;
            if ( ParamID > 0x1C || !_bittest(&v11, ParamID) )
              goto LABEL_61;
          }
          v31 = v12->Curves.m_pItems;
          if ( v31 != &v31[v12->Curves.m_uLength] )
          {
            p_ConversionTable = &v31->ConversionTable;
            do
            {
              if ( p_ConversionTable[-1].m_eScaling == key )
              {
                v15 = v15
                    + CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                        p_ConversionTable,
                        in_NewValue,
                        0,
                        out_index);
                in_pParam = v15;
              }
              p_ConversionTable = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)((char *)p_ConversionTable
                                                                                          + 24);
            }
            while ( &p_ConversionTable[-1].m_ulArraySize != (unsigned int *)&v12->Curves.m_pItems[v12->Curves.m_uLength] );
            v5 = v41;
            v7 = v36;
          }
          p_io_ExceptArrayObj = 0i64;
          if ( !in_GameObj && v12->eType != SubscriberType_CAkBus )
          {
            if ( !v7 )
            {
              CAkRTPCMgr::AkRTPCEntry::GetRTPCExceptions(v5, &io_ExceptArrayObj);
              v15 = in_pParam;
            }
            p_io_ExceptArrayObj = &io_ExceptArrayObj;
          }
          v34 = *pSubscriber;
          v35 = (unsigned int)v12->key.ParamID;
          in_pGameObjExceptArray = p_io_ExceptArrayObj;
          *(_QWORD *)&io_ExceptArrayObj.m_uLength = in_GameObj;
          *(float *)&io_ExceptArrayObj.m_pItems = v15;
          (*(void (__fastcall **)(__int64 *, CAkRTPCMgr::AkRTPCSubscription *, __int64, _QWORD))(v34 + 472))(
            pSubscriber,
            v12,
            v35,
            key);
          goto LABEL_60;
        }
        if ( eType == SubscriberType_IAkRTPCSubscriber )
        {
          if ( in_GameObj == TargetGameObject )
            goto LABEL_12;
          if ( !in_GameObj )
          {
            if ( AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                   &v5->values,
                   TargetGameObject) )
            {
LABEL_60:
              v7 = v36;
              v11 = 523241489;
              goto LABEL_61;
            }
LABEL_12:
            v16 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                    &v12->Curves.m_pItems->ConversionTable,
                    in_NewValue,
                    0,
                    out_index);
            v17 = v12->key.pSubscriber;
            ParamID_low = LOWORD(v12->key.ParamID);
            in_pParam = v16;
            (*(void (__fastcall **)(void *, __int64, float *, __int64))(*(_QWORD *)v17 + 8i64))(
              v17,
              ParamID_low,
              &in_pParam,
              4i64);
            goto LABEL_60;
          }
LABEL_61:
          v10 = v12;
          goto LABEL_62;
        }
        if ( eType != SubscriberType_PBI )
        {
          v21 = (CAkLayer *)v12->key.pSubscriber;
          v22 = *((_QWORD *)v12->key.pSubscriber + 6);
          if ( !v22 )
            goto LABEL_61;
          v23 = *(_QWORD *)(v22 + 48);
          if ( !v23 || !*(_WORD *)(v23 + 72) )
            goto LABEL_61;
          if ( CAkLayer::IsPlaying((CAkLayer *)v12->key.pSubscriber) )
          {
            v24 = v12->Curves.m_pItems;
            v25 = in_pParam;
            if ( v24 != &v24[v12->Curves.m_uLength] )
            {
              v26 = &v24->ConversionTable;
              do
              {
                if ( v26[-1].m_eScaling == key )
                {
                  v25 = v25
                      + CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                          v26,
                          in_NewValue,
                          0,
                          out_index);
                  in_pParam = v25;
                }
                v26 = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)((char *)v26 + 24);
              }
              while ( &v26[-1].m_ulArraySize != (unsigned int *)&v12->Curves.m_pItems[v12->Curves.m_uLength] );
              v5 = v41;
            }
            if ( !in_GameObj && !v36 )
            {
              CAkRTPCMgr::AkRTPCEntry::GetRTPCExceptions(v5, &io_ExceptArrayObj);
              v25 = in_pParam;
            }
            v27 = v12->key.ParamID;
            if ( v27 == RTPC_MaxNumRTPC )
              CAkLayer::OnRTPCChanged(v21, in_GameObj, in_NewValue);
            else
              CAkLayer::SetParamComplexFromRTPCManager(v21, v12, v27, key, v25, in_GameObj, &io_ExceptArrayObj);
          }
          goto LABEL_60;
        }
        if ( in_GameObj != TargetGameObject )
        {
          if ( in_GameObj )
            goto LABEL_61;
          if ( AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                 &v5->values,
                 TargetGameObject) )
          {
            goto LABEL_60;
          }
        }
        v19 = v12->Curves.m_pItems;
        if ( v19 != &v19[v12->Curves.m_uLength] )
        {
          v20 = &v19->ConversionTable;
          do
          {
            if ( v20[-1].m_eScaling == key )
            {
              v15 = v15
                  + CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                      v20,
                      in_NewValue,
                      0,
                      out_index);
              in_pParam = v15;
            }
            v20 = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)((char *)v20 + 24);
          }
          while ( &v20[-1].m_ulArraySize != (unsigned int *)&v12->Curves.m_pItems[v12->Curves.m_uLength] );
          v5 = v41;
        }
        CAkPBI::SetParam((CAkPBI *)v12->key.pSubscriber, v12->key.ParamID, &in_pParam, 4u);
        goto LABEL_60;
      }
    }
LABEL_62:
    ++m_pItems;
  }
  while ( m_pItems != v8 );
  if ( io_ExceptArrayObj.m_pItems )
  {
    io_ExceptArrayObj.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, io_ExceptArrayObj.m_pItems);
    io_ExceptArrayObj.m_pItems = 0i64;
    io_ExceptArrayObj.m_ulReserved = 0;
  }
LABEL_65:
  CAkRTPCMgr::NotifyClientRTPCChange(g_pRTPCMgr, key, in_pValueEntrya, in_NewValue, in_GameObj);
}

// File Line: 761
// RVA: 0xA567A0
void __fastcall CAkRTPCMgr::NotifyClientRTPCChange(
        CAkRTPCMgr *this,
        unsigned int in_idRTPC,
        CAkRTPCMgr::AkRTPCValue *in_pValueEntry,
        float in_NewValue,
        CAkRegisteredObj *in_GameObj)
{
  CAkRegisteredObj *v5; // rbp
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *i; // rdi
  unsigned int v9; // esi
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *j; // rbx

  v5 = in_GameObj;
  if ( in_GameObj )
  {
    for ( i = this->m_listRTPCSwitch.m_pFirst; i; i = i->pNextListItem )
    {
      if ( i->Item.RTPC_ID == in_idRTPC )
      {
        v9 = CAkConversionTable<AkRTPCGraphPointBase<unsigned long>,unsigned long>::ConvertInternal(
               &i->Item.ConversionTable,
               in_NewValue,
               0,
               (unsigned int *)&in_GameObj);
        if ( !in_pValueEntry
          || (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<unsigned long>,unsigned long>::ConvertInternal(
                             &i->Item.ConversionTable,
                             in_pValueEntry->fValue,
                             0,
                             (unsigned int *)&in_GameObj) != v9 )
        {
          for ( j = i->Item.listRTPCSwitchSubscribers.m_pFirst; j; j = j->pNextListItem )
            j->Item->vfptr->SetSwitch(j->Item, v9, v5);
        }
      }
    }
  }
}

// File Line: 791
// RVA: 0xA56E20
void __fastcall CAkRTPCMgr::RemoveReferencesToSubscription(
        CAkRTPCMgr *this,
        CAkRTPCMgr::AkRTPCSubscription *in_pSubscription)
{
  CAkRTPCMgr::RTPCCurve *m_pItems; // rax
  char v3; // bp
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *p_ConversionTable; // rdi
  AkCurveScaling m_eScaling; // esi
  CAkRTPCMgr::AkRTPCEntry *v8; // rcx
  CAkRTPCMgr::AkRTPCEntry *v9; // r9
  __int64 v10; // r8
  __int64 m_uLength; // r11
  int v12; // edi
  int v13; // esi
  CAkRTPCMgr::AkRTPCSubscription **v14; // r10
  int v15; // eax
  unsigned __int64 v16; // rdx
  CAkRTPCMgr::AkRTPCSubscription **v17; // rcx
  CAkRTPCMgr::AkRTPCSubscription **v18; // rdi

  m_pItems = in_pSubscription->Curves.m_pItems;
  v3 = 0;
  if ( m_pItems != &m_pItems[in_pSubscription->Curves.m_uLength] )
  {
    p_ConversionTable = &m_pItems->ConversionTable;
    do
    {
      m_eScaling = p_ConversionTable[-1].m_eScaling;
      v8 = this->m_RTPCEntries.m_table[m_eScaling % 0xC1u];
      if ( v8 )
      {
        while ( v8->key != m_eScaling )
        {
          v8 = v8->pNextItem;
          if ( !v8 )
            goto LABEL_8;
        }
        AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::Unset<CAkRTPCMgr::AkRTPCSubscription *>(
          &v8->subscriptions,
          in_pSubscription);
        v3 = 1;
      }
LABEL_8:
      if ( p_ConversionTable->m_pArrayGraphPoints )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, p_ConversionTable->m_pArrayGraphPoints);
        p_ConversionTable->m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&p_ConversionTable->m_ulArraySize = 0i64;
      p_ConversionTable = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)((char *)p_ConversionTable + 24);
    }
    while ( &p_ConversionTable[-1].m_ulArraySize != (unsigned int *)&in_pSubscription->Curves.m_pItems[in_pSubscription->Curves.m_uLength] );
  }
  in_pSubscription->Curves.m_uLength = 0;
  if ( v3 )
    return;
  v9 = this->m_RTPCEntries.m_table[0];
  for ( LODWORD(v10) = 0; !v9; v9 = this->m_RTPCEntries.m_table[v10] )
  {
    v10 = (unsigned int)(v10 + 1);
    if ( (unsigned int)v10 >= 0xC1 )
      return;
  }
  do
  {
LABEL_17:
    m_uLength = v9->subscriptions.m_uLength;
    v12 = 0;
    v13 = m_uLength - 1;
    if ( (int)m_uLength - 1 < 0 )
      goto LABEL_28;
    v14 = v9->subscriptions.m_pItems;
    while ( 1 )
    {
      v15 = v12 + (v13 - v12) / 2;
      v16 = (unsigned __int64)v14[v15];
      if ( (unsigned __int64)in_pSubscription >= v16 )
        break;
      v13 = v15 - 1;
LABEL_23:
      if ( v12 > v13 )
        goto LABEL_28;
    }
    if ( (unsigned __int64)in_pSubscription > v16 )
    {
      v12 = v15 + 1;
      goto LABEL_23;
    }
    v17 = &v14[m_uLength - 1];
    v18 = &v14[v15];
    if ( v18 < v17 )
      qmemcpy(v18, v18 + 1, 8 * (((unsigned __int64)((char *)v17 - (char *)v18 - 1) >> 3) + 1));
    --v9->subscriptions.m_uLength;
LABEL_28:
    v9 = v9->pNextItem;
  }
  while ( v9 );
  while ( 1 )
  {
    v10 = (unsigned int)(v10 + 1);
    if ( (unsigned int)v10 >= 0xC1 )
      break;
    v9 = this->m_RTPCEntries.m_table[v10];
    if ( v9 )
      goto LABEL_17;
  }
}

// File Line: 818
// RVA: 0xA576D0
__int64 __fastcall CAkRTPCMgr::SetSwitchInternal(
        CAkRTPCMgr *this,
        int in_SwitchGroup,
        unsigned int in_SwitchState,
        CAkRegisteredObj *in_GameObj)
{
  unsigned int *v8; // rax
  unsigned int v9; // esi
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *i; // rbx
  __m128i v12; // [rsp+20h] [rbp-18h] BYREF

  v12.m128i_i32[0] = in_SwitchGroup;
  v12.m128i_i64[1] = (__int64)in_GameObj;
  v8 = AkHashList<AkSwitchKey,unsigned long,193>::Set(&this->m_SwitchEntries, &v12);
  if ( v8 )
  {
    *v8 = in_SwitchState;
    v9 = 1;
  }
  else
  {
    v9 = 2;
  }
  for ( i = this->m_listSwitchSubscribers.m_pFirst; i; i = i->pNextListItem )
  {
    if ( i->Item.switchGroup == in_SwitchGroup )
      i->Item.pSwitch->vfptr->SetSwitch(i->Item.pSwitch, in_SwitchState, in_GameObj);
  }
  return v9;
}

// File Line: 848
// RVA: 0xA55ED0
__int64 __fastcall CAkRTPCMgr::GetSwitch(CAkRTPCMgr *this, unsigned int in_SwitchGroup, CAkRegisteredObj *in_GameObj)
{
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v6; // rax
  unsigned int v7; // ecx
  unsigned int *p_item; // rax
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v9; // rax
  unsigned int RTPC_ID; // edi
  CAkRTPCMgr::AkRTPCEntry *v12; // rcx
  AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *p_values; // rbp
  CAkRTPCMgr::AkRTPCValue *v14; // rax
  float fValue; // xmm1_4
  CAkRTPCMgr::AkRTPCEntry *v16; // rcx
  unsigned int out_index; // [rsp+40h] [rbp+8h] BYREF

  m_pFirst = this->m_listRTPCSwitch.m_pFirst;
  if ( m_pFirst )
  {
    while ( m_pFirst->Item.switchGroup != in_SwitchGroup )
    {
      m_pFirst = m_pFirst->pNextListItem;
      if ( !m_pFirst )
        goto LABEL_4;
    }
    RTPC_ID = m_pFirst->Item.RTPC_ID;
    v12 = this->m_RTPCEntries.m_table[RTPC_ID % 0xC1];
    if ( !v12 )
      goto LABEL_24;
    while ( v12->key != RTPC_ID )
    {
      v12 = v12->pNextItem;
      if ( !v12 )
        goto LABEL_24;
    }
    p_values = &v12->values;
    v14 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
            &v12->values,
            in_GameObj);
    if ( v14
      || in_GameObj
      && (v14 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                  p_values,
                  0i64)) != 0i64 )
    {
      fValue = v14->fValue;
    }
    else
    {
LABEL_24:
      v16 = this->m_RTPCEntries.m_table[RTPC_ID % 0xC1];
      if ( v16 )
      {
        while ( v16->key != RTPC_ID )
        {
          v16 = v16->pNextItem;
          if ( !v16 )
            goto LABEL_27;
        }
        fValue = v16->fDefaultValue;
      }
      else
      {
LABEL_27:
        fValue = 0.0;
      }
    }
    return CAkConversionTable<AkRTPCGraphPointBase<unsigned long>,unsigned long>::ConvertInternal(
             &m_pFirst->Item.ConversionTable,
             fValue,
             0,
             &out_index);
  }
  else
  {
LABEL_4:
    v6 = this->m_SwitchEntries.m_table[((unsigned __int64)in_GameObj + in_SwitchGroup) % 0xC1];
    v7 = 0;
    if ( v6 )
    {
      while ( v6->Assoc.key.m_SwitchGroup != in_SwitchGroup || v6->Assoc.key.m_pGameObj != in_GameObj )
      {
        v6 = v6->pNextItem;
        if ( !v6 )
          goto LABEL_8;
      }
      p_item = &v6->Assoc.item;
    }
    else
    {
LABEL_8:
      p_item = 0i64;
    }
    if ( p_item )
      return *p_item;
    if ( in_GameObj )
    {
      v9 = this->m_SwitchEntries.m_table[in_SwitchGroup % 0xC1ui64];
      if ( v9 )
      {
        while ( v9->Assoc.key.m_SwitchGroup != in_SwitchGroup || v9->Assoc.key.m_pGameObj )
        {
          v9 = v9->pNextItem;
          if ( !v9 )
            return 0i64;
        }
        p_item = &v9->Assoc.item;
        if ( p_item )
          return *p_item;
      }
    }
    return v7;
  }
}

// File Line: 891
// RVA: 0xA559B0
float __fastcall CAkRTPCMgr::GetRTPCConvertedValue(
        CAkRTPCMgr *this,
        _QWORD *in_pToken,
        CAkRegisteredObj *in_GameObj,
        unsigned int in_RTPCid)
{
  CAkRTPCMgr::AkRTPCEntry *v8; // rcx
  float fValue; // xmm6_4
  char v10; // r12
  __int64 v11; // rax
  float v12; // xmm7_4
  int *i; // r14
  unsigned int v14; // ebx
  CAkRTPCMgr::AkRTPCEntry *v15; // rcx
  CAkRTPCMgr::AkRTPCEntry *v16; // rcx
  AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *p_values; // rbx
  CAkRTPCMgr::AkRTPCValue *v19; // rax
  AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *v20; // rdi
  CAkRTPCMgr::AkRTPCValue *v21; // rax
  CAkRTPCMgr::AkRTPCValue *v22; // rax
  float in_valueToConvert; // [rsp+88h] [rbp+20h] BYREF

  if ( !in_RTPCid )
    goto LABEL_5;
  v8 = this->m_RTPCEntries.m_table[in_RTPCid % 0xC1];
  if ( !v8 )
    goto LABEL_5;
  while ( v8->key != in_RTPCid )
  {
    v8 = v8->pNextItem;
    if ( !v8 )
      goto LABEL_5;
  }
  p_values = &v8->values;
  v19 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
          &v8->values,
          in_GameObj);
  if ( v19
    || in_GameObj
    && (v19 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                p_values,
                0i64)) != 0i64 )
  {
    fValue = v19->fValue;
    v10 = 1;
  }
  else
  {
LABEL_5:
    fValue = in_valueToConvert;
    v10 = 0;
  }
  v11 = in_pToken[5];
  v12 = 0.0;
  if ( v11 != v11 + 24i64 * *((unsigned int *)in_pToken + 12) )
  {
    for ( i = (int *)(v11 + 4); i - 1 != (int *)(in_pToken[5] + 24i64 * *((unsigned int *)in_pToken + 12)); i += 6 )
    {
      if ( in_RTPCid && *i != in_RTPCid )
        continue;
      if ( !v10 )
      {
        if ( in_RTPCid )
        {
          v16 = this->m_RTPCEntries.m_table[*i % 0xC1u];
          if ( v16 )
          {
            while ( v16->key != *i )
            {
              v16 = v16->pNextItem;
              if ( !v16 )
                goto LABEL_18;
            }
            goto LABEL_35;
          }
        }
        else
        {
          v14 = *i;
          v15 = this->m_RTPCEntries.m_table[*i % 0xC1u];
          if ( v15 )
          {
            while ( v15->key != v14 )
            {
              v15 = v15->pNextItem;
              if ( !v15 )
                goto LABEL_15;
            }
            v20 = &v15->values;
            v21 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                    &v15->values,
                    in_GameObj);
            if ( v21 )
            {
              fValue = v21->fValue;
              goto LABEL_19;
            }
            if ( in_GameObj )
            {
              v22 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                      v20,
                      0i64);
              if ( v22 )
              {
                fValue = v22->fValue;
                goto LABEL_19;
              }
            }
          }
LABEL_15:
          v16 = this->m_RTPCEntries.m_table[v14 % 0xC1];
          if ( v16 )
          {
            while ( v16->key != v14 )
            {
              v16 = v16->pNextItem;
              if ( !v16 )
                goto LABEL_18;
            }
LABEL_35:
            fValue = v16->fDefaultValue;
            goto LABEL_19;
          }
        }
LABEL_18:
        fValue = 0.0;
      }
LABEL_19:
      v12 = v12
          + CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
              (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(i + 1),
              fValue,
              0,
              (unsigned int *)&in_valueToConvert);
    }
  }
  return v12;
}

// File Line: 926
// RVA: 0xA55800
float __fastcall CAkRTPCMgr::GetRTPCConvertedValue(
        CAkRTPCMgr *this,
        void *in_pSubscriber,
        unsigned int in_ParamID,
        CAkRegisteredObj *in_GameObj)
{
  CAkRTPCMgr::AkRTPCSubscription *v6; // rdi
  CAkRTPCMgr::RTPCCurve *m_pItems; // rax
  float v9; // xmm6_4
  unsigned int *p_RTPC_ID; // r14
  unsigned int v11; // ebx
  CAkRTPCMgr::AkRTPCEntry *v12; // rcx
  CAkRTPCMgr::AkRTPCEntry *v13; // rcx
  float fValue; // xmm1_4
  float v15; // xmm0_4
  AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *p_values; // rsi
  CAkRTPCMgr::AkRTPCValue *v17; // rax
  CAkRTPCMgr::AkRTPCValue *v18; // rax
  unsigned int out_index; // [rsp+60h] [rbp+18h] BYREF

  v6 = this->m_RTPCSubscribers.m_table[((unsigned int)in_pSubscriber + in_ParamID) % 0xC1];
  if ( !v6 )
    return 0.0;
  while ( v6->key.pSubscriber != in_pSubscriber || v6->key.ParamID != in_ParamID )
  {
    v6 = v6->pNextItem;
    if ( !v6 )
      return 0.0;
  }
  m_pItems = v6->Curves.m_pItems;
  v9 = 0.0;
  if ( m_pItems != &m_pItems[v6->Curves.m_uLength] )
  {
    p_RTPC_ID = &m_pItems->RTPC_ID;
    while ( 1 )
    {
      v11 = *p_RTPC_ID;
      v12 = this->m_RTPCEntries.m_table[*p_RTPC_ID % 0xC1];
      if ( !v12 )
        break;
      while ( v12->key != v11 )
      {
        v12 = v12->pNextItem;
        if ( !v12 )
          goto LABEL_11;
      }
      p_values = &v12->values;
      v17 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
              &v12->values,
              in_GameObj);
      if ( v17 )
      {
        fValue = v17->fValue;
      }
      else
      {
        if ( !in_GameObj )
          break;
        v18 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                p_values,
                0i64);
        if ( !v18 )
          break;
        fValue = v18->fValue;
      }
LABEL_15:
      v15 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
              (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(p_RTPC_ID + 1),
              fValue,
              0,
              &out_index);
      p_RTPC_ID += 6;
      v9 = v9 + v15;
      if ( p_RTPC_ID - 1 == &v6->Curves.m_pItems[v6->Curves.m_uLength].RTPCCurveID )
        return v9;
    }
LABEL_11:
    v13 = this->m_RTPCEntries.m_table[v11 % 0xC1];
    if ( v13 )
    {
      while ( v13->key != v11 )
      {
        v13 = v13->pNextItem;
        if ( !v13 )
          goto LABEL_14;
      }
      fValue = v13->fDefaultValue;
    }
    else
    {
LABEL_14:
      fValue = 0.0;
    }
    goto LABEL_15;
  }
  return v9;
}

// File Line: 944
// RVA: 0xA55E00
char __fastcall CAkRTPCMgr::GetRTPCValue(
        CAkRTPCMgr *this,
        unsigned int in_RTPC_ID,
        CAkRegisteredObj *in_GameObj,
        float *out_value,
        bool *out_bGameObjectSpecificValue)
{
  CAkRTPCMgr::AkRTPCEntry *v7; // r10
  AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *p_values; // rdi
  CAkRTPCMgr::AkRTPCValue *v10; // rax
  CAkRTPCMgr::AkRTPCValue *v11; // rax

  v7 = this->m_RTPCEntries.m_table[in_RTPC_ID % 0xC1];
  if ( !v7 )
    return 0;
  while ( v7->key != in_RTPC_ID )
  {
    v7 = v7->pNextItem;
    if ( !v7 )
      return 0;
  }
  p_values = &v7->values;
  v10 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
          &v7->values,
          in_GameObj);
  if ( v10 )
  {
    *out_value = v10->fValue;
    *out_bGameObjectSpecificValue = in_GameObj != 0i64;
    return 1;
  }
  if ( !in_GameObj )
    return 0;
  *out_bGameObjectSpecificValue = 0;
  v11 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
          p_values,
          0i64);
  if ( !v11 )
    return 0;
  *out_value = v11->fValue;
  return 1;
}

// File Line: 985
// RVA: 0xA577E0
int __fastcall CAkRTPCMgr::SubscribeRTPC(
        CAkRTPCMgr *this,
        void *in_pSubscriber,
        unsigned int in_RTPC_ID,
        AkRTPC_ParameterID in_ParamID,
        unsigned int in_RTPCCurveID,
        AkCurveScaling in_eScaling,
        AkRTPCGraphPointBase<float> *in_pArrayConversion,
        unsigned int in_ulConversionArraySize,
        CAkRegisteredObj *in_TargetGameObject,
        CAkRTPCMgr::SubscriberType in_eType)
{
  int v13; // ebp
  CAkRTPCMgr::AkRTPCSubscription *v14; // rbx
  CAkRTPCMgr::RTPCCurve *m_pItems; // rdi
  AkArray<CAkRTPCMgr::RTPCCurve,CAkRTPCMgr::RTPCCurve const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *p_Curves; // r14
  CAkRTPCMgr::RTPCCurve *v17; // rax
  CAkRTPCMgr::SubscriberType v18; // r8d
  CAkRTPCMgr::RTPCCurve *v19; // rax
  CAkRTPCMgr *v20; // rdi
  CAkRTPCMgr::AkRTPCEntry **v21; // rdx
  CAkRTPCMgr::AkRTPCEntry *v22; // rcx
  CAkRTPCMgr::AkRTPCEntry *v23; // rax
  unsigned int RTPC_ID; // esi
  CAkRTPCMgr::AkRTPCEntry *v25; // rcx
  AkRTPCGraphPointBase<float> *m_pArrayGraphPoints; // rdx
  unsigned __int64 v27; // rdx
  CAkRTPCMgr::AkRTPCSubscription *v28; // rax
  __m128i key; // xmm0
  CAkRTPCMgr::AkRTPCEntry **v30; // rcx
  CAkRTPCMgr::AkRTPCEntry *RTPCEntry; // rax
  CAkRTPCMgr::AkRTPCSubscription **v32; // rax
  CAkRTPCMgr::AkRTPCEntry *v34; // rax
  CAkRTPCMgr::RTPCCurve *v35; // rdx
  int v36; // edi
  unsigned __int32 v38; // [rsp+68h] [rbp+10h]

  v13 = 31;
  if ( !in_pSubscriber )
    return 31;
  v14 = this->m_RTPCSubscribers.m_table[((int)in_pSubscriber + in_ParamID) % 0xC1u];
  v38 = ((int)in_pSubscriber + in_ParamID) % 0xC1u;
  if ( v14 )
  {
    while ( v14->key.pSubscriber != in_pSubscriber || v14->key.ParamID != in_ParamID )
    {
      v14 = v14->pNextItem;
      if ( !v14 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v14 = 0i64;
  }
  if ( v14 )
  {
    m_pItems = v14->Curves.m_pItems;
    p_Curves = &v14->Curves;
    v17 = &m_pItems[v14->Curves.m_uLength];
    if ( m_pItems != v17 )
    {
      while ( m_pItems->RTPCCurveID != in_RTPCCurveID )
      {
        if ( ++m_pItems == v17 )
          goto LABEL_11;
      }
      RTPC_ID = m_pItems->RTPC_ID;
      v25 = this->m_RTPCEntries.m_table[RTPC_ID % 0xC1];
      if ( v25 )
      {
        while ( v25->key != RTPC_ID )
        {
          v25 = v25->pNextItem;
          if ( !v25 )
            goto LABEL_28;
        }
        AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::Unset<CAkRTPCMgr::AkRTPCSubscription *>(
          &v25->subscriptions,
          v14);
      }
LABEL_28:
      m_pArrayGraphPoints = m_pItems->ConversionTable.m_pArrayGraphPoints;
      if ( m_pArrayGraphPoints )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayGraphPoints);
        m_pItems->ConversionTable.m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&m_pItems->ConversionTable.m_ulArraySize = 0i64;
      v27 = (unsigned __int64)&v14->Curves.m_pItems[v14->Curves.m_uLength - 1];
      if ( (unsigned __int64)m_pItems < v27 )
        qmemcpy(m_pItems, &m_pItems[1], 24 * ((v27 - (unsigned __int64)m_pItems - 1) / 0x18 + 1));
      --v14->Curves.m_uLength;
    }
LABEL_11:
    v18 = in_eType;
  }
  else
  {
    v28 = (CAkRTPCMgr::AkRTPCSubscription *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
    v14 = v28;
    if ( !v28 )
      return 52;
    v18 = in_eType;
    p_Curves = &v28->Curves;
    v28->Curves.m_pItems = 0i64;
    *(_QWORD *)&v28->Curves.m_uLength = 0i64;
    v28->key.pSubscriber = in_pSubscriber;
    v28->key.ParamID = in_ParamID;
    v28->eType = in_eType;
    key = (__m128i)v28->key;
    v28->TargetGameObject = in_TargetGameObject;
    v30 = &this->m_RTPCEntries.m_table[(_mm_cvtsi128_si32(_mm_srli_si128(key, 8)) + key.m128i_i32[0]) % 0xC1u];
    v28->pNextItem = (CAkRTPCMgr::AkRTPCSubscription *)v30[389];
    v30[389] = (CAkRTPCMgr::AkRTPCEntry *)v28;
    ++this->m_RTPCSubscribers.m_uiSize;
  }
  if ( in_pArrayConversion && in_ulConversionArraySize )
  {
    v19 = AkArray<CAkRTPCMgr::RTPCCurve,CAkRTPCMgr::RTPCCurve const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(p_Curves);
    if ( !v19 )
    {
      v13 = 52;
LABEL_16:
      v20 = this;
      goto LABEL_17;
    }
    v19->RTPC_ID = in_RTPC_ID;
    v19->RTPCCurveID = in_RTPCCurveID;
    v13 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
            &v19->ConversionTable,
            in_pArrayConversion,
            in_ulConversionArraySize,
            in_eScaling);
    if ( v13 != 1 )
    {
      --p_Curves->m_uLength;
      goto LABEL_16;
    }
  }
  else if ( v18 != SubscriberType_CAkLayer || in_ParamID != RTPC_MaxNumRTPC )
  {
    goto LABEL_16;
  }
  v20 = this;
  RTPCEntry = CAkRTPCMgr::GetRTPCEntry(this, in_RTPC_ID);
  if ( RTPCEntry )
  {
    v32 = AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::AddNoSetKey<CAkRTPCMgr::AkRTPCSubscription *>(
            &RTPCEntry->subscriptions,
            v14);
    if ( v32 )
      *v32 = v14;
    return CAkRTPCMgr::UpdateRTPCSubscriberInfo(this, in_pSubscriber);
  }
  v13 = 52;
LABEL_17:
  if ( !v14->Curves.m_uLength )
  {
    v21 = &v20->m_RTPCEntries.m_table[v38];
    v22 = 0i64;
    v23 = v21[389];
    if ( v23 )
    {
      while ( *(void **)&v23->key != in_pSubscriber || LODWORD(v23->pNextItem) != in_ParamID )
      {
        v22 = v23;
        v23 = *(CAkRTPCMgr::AkRTPCEntry **)&v23->fDefaultValue;
        if ( !v23 )
          goto LABEL_48;
      }
      v34 = *(CAkRTPCMgr::AkRTPCEntry **)&v23->fDefaultValue;
      if ( v22 )
        *(_QWORD *)&v22->fDefaultValue = v34;
      else
        v21[389] = v34;
      --v20->m_RTPCSubscribers.m_uiSize;
    }
LABEL_48:
    CAkRTPCMgr::RemoveReferencesToSubscription(v20, v14);
    v35 = p_Curves->m_pItems;
    v36 = g_DefaultPoolId;
    if ( p_Curves->m_pItems )
    {
      p_Curves->m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v35);
      p_Curves->m_pItems = 0i64;
      p_Curves->m_ulReserved = 0;
    }
    AK::MemoryMgr::Free(v36, v14);
  }
  return v13;
}

// File Line: 1084
// RVA: 0xA57BA0
__int64 __fastcall CAkRTPCMgr::SubscribeSwitch(
        CAkRTPCMgr *this,
        CAkSwitchAware *in_pSwitch,
        unsigned int in_switchGroup,
        bool in_bForceNoRTPC)
{
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rcx
  __int64 result; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v9; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *m_pFree; // rax
  bool v12; // cf
  CAkRTPCMgr::AkSwitchSubscription *p_Item; // rdx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v14; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v15; // rdx
  __int64 v16; // [rsp+28h] [rbp-10h]

  if ( !in_bForceNoRTPC )
  {
    m_pFirst = this->m_listRTPCSwitch.m_pFirst;
    if ( m_pFirst )
    {
      while ( m_pFirst->Item.switchGroup != in_switchGroup )
      {
        m_pFirst = m_pFirst->pNextListItem;
        if ( !m_pFirst )
          goto LABEL_5;
      }
      v12 = CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::AddLast(
              &m_pFirst->Item.listRTPCSwitchSubscribers,
              in_pSwitch) != 0i64;
      return 2 - (unsigned int)v12;
    }
  }
LABEL_5:
  result = 31i64;
  if ( !in_pSwitch )
    return result;
  CAkRTPCMgr::UnSubscribeSwitch(this, in_pSwitch);
  LODWORD(v16) = in_switchGroup;
  if ( this->m_listSwitchSubscribers.m_pFree )
    goto LABEL_10;
  if ( this->m_listSwitchSubscribers.m_ulNumListItems < this->m_listSwitchSubscribers.m_ulMaxNumListItems )
  {
    v9 = (CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
    if ( v9 )
    {
      v9->pNextListItem = this->m_listSwitchSubscribers.m_pFree;
      this->m_listSwitchSubscribers.m_pFree = v9;
LABEL_10:
      m_pLast = this->m_listSwitchSubscribers.m_pLast;
      m_pFree = this->m_listSwitchSubscribers.m_pFree;
      if ( m_pLast )
        m_pLast->pNextListItem = m_pFree;
      else
        this->m_listSwitchSubscribers.m_pFirst = m_pFree;
      v14 = this->m_listSwitchSubscribers.m_pFree;
      this->m_listSwitchSubscribers.m_pLast = v14;
      this->m_listSwitchSubscribers.m_pFree = v14->pNextListItem;
      v14->pNextListItem = 0i64;
      v15 = this->m_listSwitchSubscribers.m_pLast;
      ++this->m_listSwitchSubscribers.m_ulNumListItems;
      v15->Item.pSwitch = in_pSwitch;
      p_Item = &v15->Item;
      *(_QWORD *)&p_Item->switchGroup = v16;
      goto LABEL_16;
    }
  }
  p_Item = 0i64;
LABEL_16:
  v12 = p_Item != 0i64;
  return 2 - (unsigned int)v12;
}

// File Line: 1117
// RVA: 0xA58430
void __fastcall CAkRTPCMgr::UnSubscribeRTPC(
        CAkRTPCMgr *this,
        void *in_pSubscriber,
        unsigned int in_ParamID,
        unsigned int in_RTPCCurveID,
        bool *out_bMoreCurvesRemaining)
{
  __int64 v8; // r13
  CAkRTPCMgr::AkRTPCSubscription *v9; // rbx
  CAkRTPCMgr::RTPCCurve *m_pItems; // rdi
  CAkRTPCMgr::RTPCCurve *v11; // rax
  unsigned int RTPC_ID; // esi
  CAkRTPCMgr::AkRTPCEntry *v13; // rcx
  AkRTPCGraphPointBase<float> *m_pArrayGraphPoints; // rdx
  unsigned __int64 v15; // rdx
  CAkRTPCMgr::AkRTPCEntry **v16; // rdx
  CAkRTPCMgr::AkRTPCEntry *v17; // rcx
  CAkRTPCMgr::AkRTPCEntry *v18; // rax
  CAkRTPCMgr::AkRTPCEntry *v19; // rax
  CAkRTPCMgr::RTPCCurve *v20; // rdx
  int v21; // edi

  v8 = ((unsigned int)in_pSubscriber + in_ParamID) % 0xC1;
  v9 = this->m_RTPCSubscribers.m_table[v8];
  if ( v9 )
  {
    while ( v9->key.pSubscriber != in_pSubscriber || v9->key.ParamID != in_ParamID )
    {
      v9 = v9->pNextItem;
      if ( !v9 )
        goto LABEL_5;
    }
    if ( out_bMoreCurvesRemaining )
      *out_bMoreCurvesRemaining = v9->Curves.m_uLength != 0;
    m_pItems = v9->Curves.m_pItems;
    v11 = &m_pItems[v9->Curves.m_uLength];
    if ( m_pItems != v11 )
    {
      while ( m_pItems->RTPCCurveID != in_RTPCCurveID )
      {
        if ( ++m_pItems == v11 )
          return;
      }
      RTPC_ID = m_pItems->RTPC_ID;
      v13 = this->m_RTPCEntries.m_table[RTPC_ID % 0xC1];
      if ( v13 )
      {
        while ( v13->key != RTPC_ID )
        {
          v13 = v13->pNextItem;
          if ( !v13 )
            goto LABEL_18;
        }
        AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::Unset<CAkRTPCMgr::AkRTPCSubscription *>(
          &v13->subscriptions,
          v9);
      }
LABEL_18:
      m_pArrayGraphPoints = m_pItems->ConversionTable.m_pArrayGraphPoints;
      if ( m_pArrayGraphPoints )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayGraphPoints);
        m_pItems->ConversionTable.m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&m_pItems->ConversionTable.m_ulArraySize = 0i64;
      v15 = (unsigned __int64)&v9->Curves.m_pItems[v9->Curves.m_uLength - 1];
      if ( (unsigned __int64)m_pItems < v15 )
        qmemcpy(m_pItems, &m_pItems[1], 24 * ((v15 - (unsigned __int64)m_pItems - 1) / 0x18 + 1));
      if ( !--v9->Curves.m_uLength )
      {
        if ( out_bMoreCurvesRemaining )
          *out_bMoreCurvesRemaining = 0;
        v16 = &this->m_RTPCEntries.m_table[v8];
        v17 = 0i64;
        v18 = v16[389];
        if ( v18 )
        {
          while ( *(void **)&v18->key != in_pSubscriber || LODWORD(v18->pNextItem) != in_ParamID )
          {
            v17 = v18;
            v18 = *(CAkRTPCMgr::AkRTPCEntry **)&v18->fDefaultValue;
            if ( !v18 )
              goto LABEL_34;
          }
          v19 = *(CAkRTPCMgr::AkRTPCEntry **)&v18->fDefaultValue;
          if ( v17 )
            *(_QWORD *)&v17->fDefaultValue = v19;
          else
            v16[389] = v19;
          --this->m_RTPCSubscribers.m_uiSize;
        }
LABEL_34:
        v20 = v9->Curves.m_pItems;
        v21 = g_DefaultPoolId;
        if ( v20 )
        {
          v9->Curves.m_uLength = 0;
          AK::MemoryMgr::Free(g_DefaultPoolId, v20);
          v9->Curves.m_pItems = 0i64;
          v9->Curves.m_ulReserved = 0;
        }
        AK::MemoryMgr::Free(v21, v9);
      }
    }
  }
  else
  {
LABEL_5:
    if ( out_bMoreCurvesRemaining )
      *out_bMoreCurvesRemaining = 0;
  }
}

// File Line: 1162
// RVA: 0xA58330
void __fastcall CAkRTPCMgr::UnSubscribeRTPC(CAkRTPCMgr *this, void *in_pSubscriber, unsigned int in_ParamID)
{
  __int64 v5; // r9
  CAkRTPCMgr::AkRTPCSubscription *v6; // rbx
  CAkRTPCMgr::AkRTPCEntry **v7; // rdx
  CAkRTPCMgr::AkRTPCEntry *v8; // rcx
  CAkRTPCMgr::AkRTPCEntry *v9; // rax
  CAkRTPCMgr::AkRTPCEntry *v10; // rax
  CAkRTPCMgr::RTPCCurve *m_pItems; // rdx
  int v12; // edi

  v5 = ((unsigned int)in_pSubscriber + in_ParamID) % 0xC1;
  v6 = this->m_RTPCSubscribers.m_table[v5];
  if ( v6 )
  {
    while ( v6->key.pSubscriber != in_pSubscriber || v6->key.ParamID != in_ParamID )
    {
      v6 = v6->pNextItem;
      if ( !v6 )
        return;
    }
    v7 = &this->m_RTPCEntries.m_table[v5];
    v8 = 0i64;
    v9 = v7[389];
    if ( v9 )
    {
      while ( *(void **)&v9->key != in_pSubscriber || LODWORD(v9->pNextItem) != in_ParamID )
      {
        v8 = v9;
        v9 = *(CAkRTPCMgr::AkRTPCEntry **)&v9->fDefaultValue;
        if ( !v9 )
          goto LABEL_15;
      }
      v10 = *(CAkRTPCMgr::AkRTPCEntry **)&v9->fDefaultValue;
      if ( v8 )
        *(_QWORD *)&v8->fDefaultValue = v10;
      else
        v7[389] = v10;
      --this->m_RTPCSubscribers.m_uiSize;
    }
LABEL_15:
    CAkRTPCMgr::RemoveReferencesToSubscription(this, v6);
    m_pItems = v6->Curves.m_pItems;
    v12 = g_DefaultPoolId;
    if ( m_pItems )
    {
      v6->Curves.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
      v6->Curves.m_pItems = 0i64;
      v6->Curves.m_ulReserved = 0;
    }
    AK::MemoryMgr::Free(v12, v6);
  }
}

// File Line: 1177
// RVA: 0xA581C0
void __fastcall CAkRTPCMgr::UnSubscribeRTPC(CAkRTPCMgr *this, void *in_pSubscriber)
{
  AkHashListBare<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription,193,AkDefaultHashListBarePolicy<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription> > *p_m_RTPCSubscribers; // r15
  __int64 v3; // r8
  CAkRTPCMgr::AkRTPCSubscription *v4; // rdi
  CAkRTPCMgr::AkRTPCSubscription *v5; // rbx
  CAkRTPCMgr::AkRTPCSubscription *v8; // rbp
  CAkRTPCMgr::AkRTPCSubscription *pNextItem; // r9
  __int64 v10; // rcx
  CAkRTPCMgr::AkRTPCSubscription *v11; // rdx
  CAkRTPCMgr::RTPCCurve *m_pItems; // rdx
  int v13; // r14d
  int v14; // [rsp+28h] [rbp-60h]

  p_m_RTPCSubscribers = &this->m_RTPCSubscribers;
  LODWORD(v3) = 0;
  v4 = 0i64;
  v5 = this->m_RTPCSubscribers.m_table[0];
  if ( v5 )
  {
    while ( 1 )
    {
LABEL_6:
      while ( 1 )
      {
        v8 = v5;
        if ( v5->key.pSubscriber != in_pSubscriber )
          break;
        pNextItem = v5->pNextItem;
        LODWORD(v10) = v3;
        v11 = v4;
        v14 = v3;
        v5 = pNextItem;
        if ( !pNextItem )
        {
          do
          {
            v10 = (unsigned int)(v10 + 1);
            if ( (unsigned int)v10 >= 0xC1 )
              break;
            v5 = p_m_RTPCSubscribers->m_table[v10];
            v11 = 0i64;
          }
          while ( !v5 );
          v14 = v10;
        }
        if ( v4 )
          v4->pNextItem = pNextItem;
        else
          p_m_RTPCSubscribers->m_table[(unsigned int)v3] = pNextItem;
        --p_m_RTPCSubscribers->m_uiSize;
        v4 = v11;
        CAkRTPCMgr::RemoveReferencesToSubscription(this, v8);
        m_pItems = v8->Curves.m_pItems;
        v13 = g_DefaultPoolId;
        if ( m_pItems )
        {
          v8->Curves.m_uLength = 0;
          AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
          v8->Curves.m_pItems = 0i64;
          v8->Curves.m_ulReserved = 0;
        }
        AK::MemoryMgr::Free(v13, v8);
        LODWORD(v3) = v14;
LABEL_17:
        if ( !v5 )
          return;
      }
      v4 = v5;
      v5 = v5->pNextItem;
      if ( !v5 )
      {
        while ( 1 )
        {
          v3 = (unsigned int)(v3 + 1);
          if ( (unsigned int)v3 >= 0xC1 )
            goto LABEL_17;
          v5 = p_m_RTPCSubscribers->m_table[v3];
          v4 = 0i64;
          if ( v5 )
            goto LABEL_6;
        }
      }
    }
  }
  while ( 1 )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= 0xC1 )
      break;
    v5 = p_m_RTPCSubscribers->m_table[v3];
    if ( v5 )
      goto LABEL_6;
  }
}

// File Line: 1197
// RVA: 0xA58650
void __fastcall CAkRTPCMgr::UnSubscribeSwitch(CAkRTPCMgr *this, CAkSwitchAware *in_pSwitch)
{
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v4; // rdx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v5; // r8
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *i; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v7; // rdx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v8; // r8
  bool v9; // zf
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v11; // rcx

  m_pFirst = this->m_listSwitchSubscribers.m_pFirst;
  v4 = 0i64;
  v5 = m_pFirst;
  if ( m_pFirst )
  {
    while ( v5->Item.pSwitch != in_pSwitch )
    {
      v4 = v5;
      v5 = v5->pNextListItem;
      if ( !v5 )
        goto LABEL_4;
    }
    v9 = v5 == m_pFirst;
    pNextListItem = v5->pNextListItem;
    if ( v9 )
      this->m_listSwitchSubscribers.m_pFirst = pNextListItem;
    else
      v4->pNextListItem = pNextListItem;
    if ( v5 == this->m_listSwitchSubscribers.m_pLast )
      this->m_listSwitchSubscribers.m_pLast = v4;
    v5->pNextListItem = this->m_listSwitchSubscribers.m_pFree;
    --this->m_listSwitchSubscribers.m_ulNumListItems;
    this->m_listSwitchSubscribers.m_pFree = v5;
  }
  else
  {
LABEL_4:
    for ( i = this->m_listRTPCSwitch.m_pFirst; i; i = i->pNextListItem )
    {
      v7 = i->Item.listRTPCSwitchSubscribers.m_pFirst;
      v8 = 0i64;
      if ( v7 )
      {
        while ( v7->Item != in_pSwitch )
        {
          v8 = v7;
          v7 = v7->pNextListItem;
          if ( !v7 )
            goto LABEL_9;
        }
        v11 = v7->pNextListItem;
        if ( v7 == i->Item.listRTPCSwitchSubscribers.m_pFirst )
          i->Item.listRTPCSwitchSubscribers.m_pFirst = v11;
        else
          v8->pNextListItem = v11;
        if ( v7 == i->Item.listRTPCSwitchSubscribers.m_pLast )
          i->Item.listRTPCSwitchSubscribers.m_pLast = v8;
        v7->pNextListItem = i->Item.listRTPCSwitchSubscribers.m_pFree;
        --i->Item.listRTPCSwitchSubscribers.m_ulNumListItems;
        i->Item.listRTPCSwitchSubscribers.m_pFree = v7;
        return;
      }
LABEL_9:
      ;
    }
  }
}

// File Line: 1234
// RVA: 0xA58710
void __fastcall CAkRTPCMgr::UnregisterGameObject(CAkRTPCMgr *this, CAkRegisteredObj *in_GameObj)
{
  __int64 v2; // rbx
  AkHashListBare<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription,193,AkDefaultHashListBarePolicy<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription> > *p_m_RTPCSubscribers; // r13
  CAkRegisteredObj *v4; // r10
  CAkRTPCMgr::AkRTPCSubscription *v6; // rdi
  __int64 v7; // r8
  CAkRTPCMgr::AkRTPCSubscription *v8; // rsi
  CAkRTPCMgr::AkRTPCSubscription *v9; // rbp
  CAkRTPCMgr::AkRTPCSubscription *pNextItem; // r9
  __int64 v11; // rcx
  CAkRTPCMgr::AkRTPCSubscription *v12; // rdx
  CAkRTPCMgr::RTPCCurve *m_pItems; // rdx
  int v14; // r12d
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v15; // rdx
  __int64 v16; // rcx
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v17; // r9
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v18; // r10
  __int64 v19; // r8
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v20; // rdi
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v21; // rbp
  CAkRTPCMgr::AkRTPCEntry *v22; // rdi
  int v23; // [rsp+28h] [rbp-60h]
  int v24; // [rsp+28h] [rbp-60h]

  if ( in_GameObj )
  {
    LODWORD(v2) = 0;
    p_m_RTPCSubscribers = &this->m_RTPCSubscribers;
    v4 = in_GameObj;
    v6 = this->m_RTPCSubscribers.m_table[0];
    LODWORD(v7) = 0;
    v8 = 0i64;
    if ( v6 )
      goto LABEL_7;
    while ( 1 )
    {
      v7 = (unsigned int)(v7 + 1);
      if ( (unsigned int)v7 >= 0xC1 )
        break;
      v6 = p_m_RTPCSubscribers->m_table[v7];
      if ( v6 )
      {
        while ( 1 )
        {
LABEL_7:
          while ( 1 )
          {
            v9 = v6;
            if ( v6->TargetGameObject != v4 )
              break;
            pNextItem = v6->pNextItem;
            LODWORD(v11) = v7;
            v12 = v8;
            v23 = v7;
            v6 = pNextItem;
            if ( !pNextItem )
            {
              do
              {
                v11 = (unsigned int)(v11 + 1);
                if ( (unsigned int)v11 >= 0xC1 )
                  break;
                v6 = p_m_RTPCSubscribers->m_table[v11];
                v12 = 0i64;
              }
              while ( !v6 );
              v23 = v11;
            }
            if ( v8 )
              v8->pNextItem = pNextItem;
            else
              p_m_RTPCSubscribers->m_table[(unsigned int)v7] = pNextItem;
            --p_m_RTPCSubscribers->m_uiSize;
            v8 = v12;
            CAkRTPCMgr::RemoveReferencesToSubscription(this, v9);
            m_pItems = v9->Curves.m_pItems;
            v14 = g_DefaultPoolId;
            if ( m_pItems )
            {
              v9->Curves.m_uLength = 0;
              AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
              v9->Curves.m_pItems = 0i64;
              v9->Curves.m_ulReserved = 0;
            }
            AK::MemoryMgr::Free(v14, v9);
            LODWORD(v7) = v23;
            v4 = in_GameObj;
LABEL_18:
            if ( !v6 )
              goto LABEL_19;
          }
          v8 = v6;
          v6 = v6->pNextItem;
          if ( !v6 )
          {
            while ( 1 )
            {
              v7 = (unsigned int)(v7 + 1);
              if ( (unsigned int)v7 >= 0xC1 )
                goto LABEL_18;
              v6 = p_m_RTPCSubscribers->m_table[v7];
              v8 = 0i64;
              if ( v6 )
                goto LABEL_7;
            }
          }
        }
      }
    }
LABEL_19:
    v15 = this->m_SwitchEntries.m_table[0];
    LODWORD(v16) = 0;
    v17 = 0i64;
    if ( v15 )
      goto LABEL_28;
    while ( 1 )
    {
      v16 = (unsigned int)(v16 + 1);
      if ( (unsigned int)v16 >= 0xC1 )
        break;
      v15 = this->m_SwitchEntries.m_table[v16];
      if ( v15 )
      {
        while ( 1 )
        {
LABEL_28:
          while ( v15->Assoc.key.m_pGameObj == v4 )
          {
            v18 = v15->pNextItem;
            LODWORD(v19) = v16;
            v24 = v16;
            v20 = v15->pNextItem;
            v21 = v17;
            if ( !v15->pNextItem )
            {
              do
              {
                v19 = (unsigned int)(v19 + 1);
                if ( (unsigned int)v19 >= 0xC1 )
                  break;
                v20 = this->m_SwitchEntries.m_table[v19];
                v21 = 0i64;
              }
              while ( !v20 );
              v24 = v19;
            }
            if ( v17 )
              v17->pNextItem = v18;
            else
              this->m_SwitchEntries.m_table[(unsigned int)v16] = v18;
            AK::MemoryMgr::Free(this->m_SwitchEntries.m_MemPoolId, v15);
            --this->m_SwitchEntries.m_uiSize;
            v4 = in_GameObj;
            LODWORD(v16) = v24;
            v15 = v20;
            v17 = v21;
LABEL_37:
            if ( !v15 )
              goto LABEL_38;
          }
          v17 = v15;
          v15 = v15->pNextItem;
          if ( !v15 )
          {
            while ( 1 )
            {
              v16 = (unsigned int)(v16 + 1);
              if ( (unsigned int)v16 >= 0xC1 )
                goto LABEL_37;
              v15 = this->m_SwitchEntries.m_table[v16];
              v17 = 0i64;
              if ( v15 )
                goto LABEL_28;
            }
          }
        }
      }
    }
LABEL_38:
    v22 = this->m_RTPCEntries.m_table[0];
    if ( this->m_RTPCEntries.m_table[0] )
      goto LABEL_53;
    while ( 1 )
    {
      v2 = (unsigned int)(v2 + 1);
      if ( (unsigned int)v2 >= 0xC1 )
        break;
      v22 = this->m_RTPCEntries.m_table[v2];
      if ( v22 )
        goto LABEL_47;
    }
    if ( v22 )
    {
LABEL_53:
      do
      {
LABEL_47:
        CAkRTPCMgr::AkRTPCEntry::RemoveGameObject(v22, v4);
        v22 = v22->pNextItem;
        v4 = in_GameObj;
      }
      while ( v22 );
      while ( 1 )
      {
        v2 = (unsigned int)(v2 + 1);
        if ( (unsigned int)v2 >= 0xC1 )
          break;
        v22 = this->m_RTPCEntries.m_table[v2];
        if ( v22 )
        {
          v4 = in_GameObj;
          goto LABEL_47;
        }
      }
    }
  }
}

// File Line: 1282
// RVA: 0xA58A30
__int64 __fastcall CAkRTPCMgr::UpdateRTPCSubscriberInfo(CAkRTPCMgr *this, void *in_pSubscriber)
{
  CAkRTPCMgr::AkRTPCSubscription *v2; // rdi
  __int64 v3; // rbx

  v2 = this->m_RTPCSubscribers.m_table[0];
  LODWORD(v3) = 0;
  if ( v2 )
  {
    do
    {
LABEL_4:
      if ( v2->key.pSubscriber == in_pSubscriber )
        CAkRTPCMgr::UpdateSubscription(this, v2);
      v2 = v2->pNextItem;
    }
    while ( v2 );
    while ( 1 )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (unsigned int)v3 >= 0xC1 )
        break;
      v2 = this->m_RTPCSubscribers.m_table[v3];
      if ( v2 )
        goto LABEL_4;
    }
  }
  else
  {
    while ( 1 )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (unsigned int)v3 >= 0xC1 )
        break;
      v2 = this->m_RTPCSubscribers.m_table[v3];
      if ( v2 )
        goto LABEL_4;
    }
  }
  return 1i64;
}

// File Line: 1302
// RVA: 0xA58AD0
void __fastcall CAkRTPCMgr::UpdateSubscription(CAkRTPCMgr *this, CAkRTPCMgr::AkRTPCSubscription *in_rSubscription)
{
  CAkRTPCMgr::SubscriberType eType; // edx
  float v4; // xmm0_4
  void *v5; // rcx
  __int64 ParamID_low; // rdx
  float RTPCConvertedValue; // xmm0_4
  __int16 ParamID; // dx
  CAkPBI *pSubscriber; // rcx
  float in_pParam; // [rsp+38h] [rbp+10h] BYREF

  eType = in_rSubscription->eType;
  if ( (unsigned int)(eType - 1) <= 1 )
  {
    (*(void (__fastcall **)(void *))(*(_QWORD *)in_rSubscription->key.pSubscriber + 408i64))(in_rSubscription->key.pSubscriber);
  }
  else if ( eType )
  {
    if ( eType == SubscriberType_PBI )
    {
      RTPCConvertedValue = CAkRTPCMgr::GetRTPCConvertedValue(
                             this,
                             in_rSubscription,
                             in_rSubscription->TargetGameObject,
                             0);
      ParamID = in_rSubscription->key.ParamID;
      pSubscriber = (CAkPBI *)in_rSubscription->key.pSubscriber;
      in_pParam = RTPCConvertedValue;
      CAkPBI::SetParam(pSubscriber, ParamID, &in_pParam, 4u);
    }
    else
    {
      CAkLayer::RecalcNotification((CAkLayer *)in_rSubscription->key.pSubscriber);
    }
  }
  else
  {
    v4 = CAkRTPCMgr::GetRTPCConvertedValue(this, in_rSubscription, in_rSubscription->TargetGameObject, 0);
    v5 = in_rSubscription->key.pSubscriber;
    ParamID_low = LOWORD(in_rSubscription->key.ParamID);
    in_pParam = v4;
    (*(void (__fastcall **)(void *, __int64, float *, __int64))(*(_QWORD *)v5 + 8i64))(
      v5,
      ParamID_low,
      &in_pParam,
      4i64);
  }
}

// File Line: 1388
// RVA: 0xA55C10
CAkRTPCMgr::AkRTPCEntry *__fastcall CAkRTPCMgr::GetRTPCEntry(CAkRTPCMgr *this, unsigned int in_RTPCid)
{
  CAkRTPCMgr::AkRTPCEntry *result; // rax
  __int64 v5; // rcx

  result = this->m_RTPCEntries.m_table[in_RTPCid % 0xC1];
  if ( result )
  {
    while ( result->key != in_RTPCid )
    {
      result = result->pNextItem;
      if ( !result )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    result = (CAkRTPCMgr::AkRTPCEntry *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
    if ( result )
    {
      result->key = in_RTPCid;
      result->fDefaultValue = 0.0;
      result->values.m_pItems = 0i64;
      *(_QWORD *)&result->values.m_uLength = 0i64;
      result->transitions.m_pFirst = 0i64;
      result->subscriptions.m_pItems = 0i64;
      *(_QWORD *)&result->subscriptions.m_uLength = 0i64;
      v5 = result->key % 0xC1;
      result->pNextItem = this->m_RTPCEntries.m_table[v5];
      this->m_RTPCEntries.m_table[v5] = result;
      ++this->m_RTPCEntries.m_uiSize;
    }
  }
  return result;
}

// File Line: 1403
// RVA: 0xA573F0
void __fastcall CAkRTPCMgr::SetDefaultParamValue(CAkRTPCMgr *this, unsigned int in_RTPCid, float in_fValue)
{
  CAkRTPCMgr::AkRTPCEntry *RTPCEntry; // rax

  RTPCEntry = CAkRTPCMgr::GetRTPCEntry(this, in_RTPCid);
  if ( RTPCEntry )
    RTPCEntry->fDefaultValue = in_fValue;
}

// File Line: 1410
// RVA: 0xA557B0
float __fastcall CAkRTPCMgr::GetDefaultValue(CAkRTPCMgr *this, unsigned int in_RTPCid, bool *out_pbWasFound)
{
  CAkRTPCMgr::AkRTPCEntry *v3; // r9

  v3 = this->m_RTPCEntries.m_table[in_RTPCid % 0xC1];
  if ( v3 )
  {
    while ( v3->key != in_RTPCid )
    {
      v3 = v3->pNextItem;
      if ( !v3 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v3 = 0i64;
  }
  if ( out_pbWasFound )
    *out_pbWasFound = v3 != 0i64;
  if ( v3 )
    return v3->fDefaultValue;
  else
    return 0.0;
}

// File Line: 1420
// RVA: 0xA57180
void __fastcall CAkRTPCMgr::ResetRTPCValue(
        CAkRTPCMgr *this,
        unsigned int in_RTPCid,
        CAkRegisteredObj *in_GameObj,
        TransParams *in_transParams)
{
  CAkRTPCMgr::AkRTPCEntry *v6; // rbx
  CAkRTPCMgr::AkRTPCValue *v7; // rax
  CAkRTPCMgr::AkRTPCValue *v8; // rdi
  float fValue; // xmm2_4

  v6 = this->m_RTPCEntries.m_table[in_RTPCid % 0xC1];
  if ( v6 )
  {
    while ( v6->key != in_RTPCid )
    {
      v6 = v6->pNextItem;
      if ( !v6 )
        return;
    }
    v7 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
           &v6->values,
           0i64);
    v8 = v7;
    if ( in_GameObj )
    {
      v7 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
             &v6->values,
             in_GameObj);
      if ( !v7 )
        return;
      if ( v8 )
      {
        fValue = v8->fValue;
LABEL_11:
        CAkRTPCMgr::AkRTPCEntry::SetRTPC(v6, v7, fValue, in_GameObj, in_transParams, 1);
        return;
      }
    }
    else if ( !v7 )
    {
      return;
    }
    fValue = v6->fDefaultValue;
    goto LABEL_11;
  }
}

