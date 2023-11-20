// File Line: 58
// RVA: 0xA580E0
void __fastcall CAkRTPCMgr::CAkRTPCTransition::TransUpdateValue(CAkRTPCMgr::CAkRTPCTransition *this, __int64 __formal, float in_unionValue, bool in_bIsTerminated)
{
  bool v4; // r14
  CAkRTPCMgr::CAkRTPCTransition *v5; // rsi
  bool in_bUnsetValue; // bp
  CAkRTPCMgr::AkRTPCEntry *v7; // rdi
  CAkRTPCMgr::AkRTPCValue *v8; // rax
  CAkRTPCMgr::AkRTPCEntry *v9; // rdx
  CAkRTPCMgr::CAkRTPCTransition *v10; // rcx
  CAkRTPCMgr::CAkRTPCTransition *v11; // r8
  CAkRTPCMgr::CAkRTPCTransition *v12; // rax
  bool v13; // zf
  CAkRTPCMgr::CAkRTPCTransition *v14; // rax
  int v15; // ecx

  v4 = in_bIsTerminated;
  v5 = this;
  in_bUnsetValue = this->m_bRemoveEntryWhenDone && in_bIsTerminated;
  v7 = this->m_pOwner;
  v8 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         &v7->values,
         this->m_pGameObject);
  CAkRTPCMgr::AkRTPCEntry::ApplyRTPCValue(v7, v8, in_unionValue, v5->m_pGameObject, in_bUnsetValue);
  if ( v4 )
  {
    v9 = v5->m_pOwner;
    v10 = 0i64;
    v11 = v9->transitions.m_pFirst;
    v12 = v11;
    if ( v11 )
    {
      while ( v12 != v5 )
      {
        v10 = v12;
        v12 = v12->pNextLightItem;
        if ( !v12 )
          goto LABEL_14;
      }
      if ( v12 )
      {
        v13 = v12 == v11;
        v14 = v12->pNextLightItem;
        if ( v13 )
          v9->transitions.m_pFirst = v14;
        else
          v10->pNextLightItem = v14;
      }
    }
LABEL_14:
    v5->m_pTransition = 0i64;
    v15 = g_DefaultPoolId;
    v5->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
    AK::MemoryMgr::Free(v15, v5);
  }
}

// File Line: 80
// RVA: 0xA57770
__int64 __fastcall CAkRTPCMgr::CAkRTPCTransition::Start(CAkRTPCMgr::CAkRTPCTransition *this, float in_fStartValue, float in_fTargetValue, TransParams *in_transParams, bool in_bRemoveEntryWhenDone)
{
  int v5; // eax
  CAkRTPCMgr::CAkRTPCTransition *v6; // rbx
  CAkTransition *v7; // rax
  TransitionParameters in_Params; // [rsp+20h] [rbp-38h]

  v5 = in_transParams->TransitionTime;
  v6 = this;
  in_Params.pUser = (ITransitionable *)&this->vfptr;
  in_Params.fStartValue = in_fStartValue;
  in_Params.fTargetValue = in_fTargetValue;
  in_Params.lDuration = v5;
  in_Params.eFadeCurve = in_transParams->eFadeCurve;
  this->m_bRemoveEntryWhenDone = in_bRemoveEntryWhenDone;
  in_Params.eTarget = 0x10000000i64;
  *(_WORD *)&in_Params.bdBs = 0;
  v7 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, 1, 0);
  v6->m_pTransition = v7;
  return 2 - (unsigned int)(v7 != 0i64);
}

// File Line: 126
// RVA: 0xA54700
void __fastcall CAkRTPCMgr::AkRTPCEntry::~AkRTPCEntry(CAkRTPCMgr::AkRTPCEntry *this)
{
  CAkRTPCMgr::CAkRTPCTransition *v1; // rbx
  CAkRTPCMgr::AkRTPCEntry *v2; // rdi
  CAkTransition *v3; // rdx
  int v4; // esi
  CAkRTPCMgr::AkRTPCValue *v5; // rdx
  CAkRTPCMgr::AkRTPCSubscription **v6; // rdx

  v1 = this->transitions.m_pFirst;
  v2 = this;
  if ( v1 != 0i64 )
  {
    while ( 1 )
    {
      if ( v1 == v2->transitions.m_pFirst )
        v2->transitions.m_pFirst = v1->pNextLightItem;
      else
        MEMORY[8] = v1->pNextLightItem;
      v3 = v1->m_pTransition;
      v4 = g_DefaultPoolId;
      v1->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
      if ( v3 )
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v3, (ITransitionable *)&v1->vfptr);
      AK::MemoryMgr::Free(v4, v1);
    }
  }
  v5 = this->values.m_pItems;
  this->values.m_uLength = 0;
  if ( v5 )
  {
    this->values.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v5);
    v2->values.m_pItems = 0i64;
    v2->values.m_ulReserved = 0;
  }
  v6 = v2->subscriptions.m_pItems;
  if ( v6 )
  {
    v2->subscriptions.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v6);
    v2->subscriptions.m_pItems = 0i64;
    v2->subscriptions.m_ulReserved = 0;
  }
}

// File Line: 136
// RVA: 0xA56CE0
void __fastcall CAkRTPCMgr::AkRTPCEntry::RemoveGameObject(CAkRTPCMgr::AkRTPCEntry *this, CAkRegisteredObj *in_pGameObj)
{
  CAkRegisteredObj *v2; // rsi
  CAkRTPCMgr::AkRTPCEntry *v3; // rdi
  CAkRTPCMgr::CAkRTPCTransition *v4; // rbx
  CAkTransition *v5; // rdx
  int v6; // esi
  CAkRTPCMgr::CAkRTPCTransition *v7; // rax
  ITransitionable *v8; // rcx
  ITransitionable *v9; // rbx
  bool v10; // zf
  ITransitionableVtbl *v11; // rax
  CAkTransition *v12; // rdx
  int v13; // er14
  ITransitionable *in_pUser[2]; // [rsp+20h] [rbp-18h]

  v2 = in_pGameObj;
  v3 = this;
  if ( in_pGameObj )
  {
    v7 = this->transitions.m_pFirst;
    in_pUser[1] = 0i64;
    in_pUser[0] = (ITransitionable *)&v7->vfptr;
    _mm_store_si128((__m128i *)in_pUser, (__m128i)(unsigned __int64)v7);
    if ( v7 )
    {
      v8 = in_pUser[1];
      v9 = in_pUser[0];
      while ( (CAkRegisteredObj *)v9[4].vfptr != in_pGameObj )
      {
        v8 = v9;
        v9 = (ITransitionable *)v9[1].vfptr;
        if ( !v9 )
          goto LABEL_21;
      }
      v10 = v9 == (ITransitionable *)v7;
      v11 = v9[1].vfptr;
      if ( v10 )
        v3->transitions.m_pFirst = (CAkRTPCMgr::CAkRTPCTransition *)v11;
      else
        v8[1].vfptr = v11;
      v12 = (CAkTransition *)v9[2].vfptr;
      v13 = g_DefaultPoolId;
      v9->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
      if ( v12 )
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v12, v9);
      AK::MemoryMgr::Free(v13, v9);
    }
LABEL_21:
    AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8>::Unset<CAkRegisteredObj *>(
      &v3->values,
      v2);
  }
  else
  {
    v4 = this->transitions.m_pFirst;
    if ( v4 )
    {
      while ( 1 )
      {
        if ( v4 == v3->transitions.m_pFirst )
          v3->transitions.m_pFirst = v4->pNextLightItem;
        else
          MEMORY[8] = v4->pNextLightItem;
        v5 = v4->m_pTransition;
        v6 = g_DefaultPoolId;
        v4->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
        if ( v5 )
          CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v5, (ITransitionable *)&v4->vfptr);
        AK::MemoryMgr::Free(v6, v4);
      }
    }
    this->values.m_uLength = 0;
  }
}

// File Line: 174
// RVA: 0xA55CD0
void __fastcall CAkRTPCMgr::AkRTPCEntry::GetRTPCExceptions(CAkRTPCMgr::AkRTPCEntry *this, AkArray<CAkRegisteredObj *,CAkRegisteredObj *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *io_ExceptArrayObj)
{
  unsigned int v2; // ebx
  AkArray<CAkRegisteredObj *,CAkRegisteredObj *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *v3; // rsi
  CAkRTPCMgr::AkRTPCEntry *v4; // rdi
  CAkRegisteredObj **v5; // rax
  CAkRTPCMgr::AkRTPCValue *v6; // rbx
  signed __int64 v7; // rdi
  CAkRegisteredObj *v8; // rbp
  unsigned __int64 v9; // r15
  unsigned __int64 v10; // rax
  unsigned int v11; // er12
  CAkRegisteredObj **v12; // r14
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // rdx
  __int64 v15; // rcx
  CAkRegisteredObj **v16; // rdx

  v2 = this->values.m_uLength;
  v3 = io_ExceptArrayObj;
  v4 = this;
  if ( v2 )
  {
    v5 = (CAkRegisteredObj **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v2);
    v3->m_pItems = v5;
    if ( v5 )
      v3->m_ulReserved = v2;
  }
  v6 = v4->values.m_pItems;
  v7 = (signed __int64)&v6[v4->values.m_uLength];
  if ( v6 != (CAkRTPCMgr::AkRTPCValue *)v7 )
  {
    while ( 1 )
    {
      v8 = v6->pGameObj;
      if ( v6->pGameObj )
      {
        v9 = v3->m_uLength;
        v10 = v3->m_ulReserved;
        if ( v9 < v10 )
          goto LABEL_13;
        v11 = v10 + 8;
        v12 = (CAkRegisteredObj **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(v10 + 8));
        if ( v12 )
          break;
      }
LABEL_16:
      ++v6;
      if ( v6 == (CAkRTPCMgr::AkRTPCValue *)v7 )
        return;
    }
    v13 = v3->m_uLength;
    if ( v3->m_pItems )
    {
      v14 = 0i64;
      if ( v3->m_uLength )
      {
        do
        {
          ++v14;
          v12[v14 - 1] = v3->m_pItems[v14 - 1];
        }
        while ( v14 < v13 );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, v3->m_pItems);
    }
    v3->m_pItems = v12;
    v3->m_ulReserved = v11;
LABEL_13:
    if ( v9 < v3->m_ulReserved )
    {
      v15 = v3->m_uLength;
      v16 = &v3->m_pItems[v15];
      v3->m_uLength = v15 + 1;
      if ( v16 )
        *v16 = v8;
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
signed __int64 __fastcall CAkRTPCMgr::Init(CAkRTPCMgr *this)
{
  CAkRTPCMgr *v1; // rbx
  AkHashList<AkSwitchKey,unsigned long,193>::Item **v2; // rax
  signed __int64 v3; // rcx
  signed __int64 v4; // rdx
  signed __int64 v5; // rdx
  CAkRTPCMgr *v6; // rax
  AkHashListBare<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription,193,AkDefaultHashListBarePolicy<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription> > *v7; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v8; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v9; // rcx
  unsigned int v10; // edi
  unsigned int v11; // edx
  signed __int64 v12; // rax
  signed __int64 result; // rax

  v1 = this;
  this->m_SwitchEntries.m_MemPoolId = g_DefaultPoolId;
  v2 = this->m_SwitchEntries.m_table;
  this->m_SwitchEntries.m_uiSize = 0;
  v3 = 24i64;
  v4 = 24i64;
  do
  {
    *v2 = 0i64;
    v2[1] = 0i64;
    v2[2] = 0i64;
    v2 += 8;
    *(v2 - 5) = 0i64;
    *(v2 - 4) = 0i64;
    *(v2 - 3) = 0i64;
    *(v2 - 2) = 0i64;
    *(v2 - 1) = 0i64;
    --v4;
  }
  while ( v4 );
  *v2 = 0i64;
  v5 = 24i64;
  v1->m_RTPCEntries.m_uiSize = 0;
  v6 = v1;
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
  v7 = &v1->m_RTPCSubscribers;
  v1->m_RTPCSubscribers.m_uiSize = 0;
  do
  {
    v7->m_table[0] = 0i64;
    v7->m_table[1] = 0i64;
    v7->m_table[2] = 0i64;
    v7 = (AkHashListBare<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription,193,AkDefaultHashListBarePolicy<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription> > *)((char *)v7 + 64);
    v7[-1].m_table[189] = 0i64;
    v7[-1].m_table[190] = 0i64;
    v7[-1].m_table[191] = 0i64;
    v7[-1].m_table[192] = 0i64;
    *(_QWORD *)&v7[-1].m_uiSize = 0i64;
    --v3;
  }
  while ( v3 );
  v7->m_table[0] = 0i64;
  v1->m_listSwitchSubscribers.m_ulNumListItems = 0;
  v1->m_listSwitchSubscribers.m_ulMaxNumListItems = -1;
  v1->m_listSwitchSubscribers.m_pFree = 0i64;
  v8 = (CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x180ui64);
  v9 = v8;
  v1->m_listSwitchSubscribers.m_pvMemStart = v8;
  if ( v8 )
  {
    v1->m_listSwitchSubscribers.m_ulMinNumListItems = 16;
    v1->m_listSwitchSubscribers.m_pFree = v8;
    v11 = 0;
    do
    {
      v12 = (signed __int64)&v9[1];
      ++v11;
      v9->pNextListItem = v9 + 1;
      ++v9;
    }
    while ( v11 < v1->m_listSwitchSubscribers.m_ulMinNumListItems );
    *(_QWORD *)(v12 - 24) = 0i64;
    v10 = 1;
  }
  else
  {
    v10 = 52;
  }
  v1->m_listSwitchSubscribers.m_pFirst = 0i64;
  v1->m_listSwitchSubscribers.m_pLast = 0i64;
  if ( v10 == 1 )
  {
    v1->m_listRTPCSwitch.m_ulNumListItems = 0;
    v1->m_listRTPCSwitch.m_ulMaxNumListItems = -1;
    v1->m_listRTPCSwitch.m_pFree = 0i64;
    v1->m_listRTPCSwitch.m_pvMemStart = 0i64;
    v1->m_listRTPCSwitch.m_pFirst = 0i64;
    v1->m_listRTPCSwitch.m_pLast = 0i64;
    result = 1i64;
  }
  else
  {
    CAkRTPCMgr::Term(v1);
    result = v10;
  }
  return result;
}

// File Line: 213
// RVA: 0xA57E60
signed __int64 __fastcall CAkRTPCMgr::Term(CAkRTPCMgr *this)
{
  CAkRTPCMgr::AkRTPCEntry *v1; // rdi
  CAkRTPCMgr *v2; // r14
  __int64 v3; // rdx
  __int64 v4; // rbp
  CAkRTPCMgr::AkRTPCEntry *v5; // r9
  CAkRTPCMgr::AkRTPCEntry *v6; // r15
  __int64 v7; // rcx
  __int64 v8; // r8
  int v9; // ebx
  signed __int64 v10; // r15
  __int64 v11; // rdx
  __int64 v12; // rbp
  CAkRTPCMgr::AkRTPCSubscription *v13; // rbx
  CAkRTPCMgr::AkRTPCSubscription *v14; // r9
  CAkRTPCMgr::AkRTPCSubscription *v15; // rdi
  __int64 v16; // rcx
  __int64 v17; // r8
  CAkRTPCMgr::RTPCCurve *v18; // rdx
  int v19; // er12
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *i; // rbx
  AkRTPCGraphPointBase<unsigned long> *v21; // rdx
  int v23; // [rsp+28h] [rbp-60h]
  int v24; // [rsp+28h] [rbp-60h]

  v1 = this->m_RTPCEntries.m_table[0];
  v2 = this;
  LODWORD(v3) = 0;
  v4 = 0i64;
  if ( this->m_RTPCEntries.m_table[0] )
    goto LABEL_41;
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
LABEL_41:
    while ( 1 )
    {
LABEL_6:
      v5 = v1->pNextItem;
      v6 = v1;
      LODWORD(v7) = v3;
      v23 = v3;
      v8 = v4;
      v1 = v5;
      if ( !v5 )
      {
        do
        {
          v7 = (unsigned int)(v7 + 1);
          if ( (unsigned int)v7 >= 0xC1 )
            break;
          v1 = v2->m_RTPCEntries.m_table[v7];
          v8 = 0i64;
        }
        while ( !v1 );
        v23 = v7;
      }
      if ( v4 )
        *(_QWORD *)(v4 + 8) = v5;
      else
        v2->m_RTPCEntries.m_table[(unsigned int)v3] = v5;
      --v2->m_RTPCEntries.m_uiSize;
      v9 = g_DefaultPoolId;
      v4 = v8;
      CAkRTPCMgr::AkRTPCEntry::~AkRTPCEntry(v6);
      AK::MemoryMgr::Free(v9, v6);
      if ( !v1 )
        break;
      LODWORD(v3) = v23;
    }
  }
  v10 = (signed __int64)&v2->m_RTPCSubscribers;
  LODWORD(v11) = 0;
  v12 = 0i64;
  v13 = v2->m_RTPCSubscribers.m_table[0];
  if ( v13 )
    goto LABEL_42;
  while ( 1 )
  {
    v11 = (unsigned int)(v11 + 1);
    if ( (unsigned int)v11 >= 0xC1 )
      break;
    v13 = *(CAkRTPCMgr::AkRTPCSubscription **)(v10 + 8 * v11);
    if ( v13 )
      goto LABEL_20;
  }
  if ( v13 )
  {
LABEL_42:
    while ( 1 )
    {
LABEL_20:
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
          v13 = *(CAkRTPCMgr::AkRTPCSubscription **)(v10 + 8 * v16);
          v17 = 0i64;
        }
        while ( !v13 );
        v24 = v16;
      }
      if ( v12 )
        *(_QWORD *)(v12 + 16) = v14;
      else
        *(_QWORD *)(v10 + 8i64 * (unsigned int)v11) = v14;
      --v2->m_RTPCSubscribers.m_uiSize;
      v12 = v17;
      CAkRTPCMgr::RemoveReferencesToSubscription(v2, v15);
      v18 = v15->Curves.m_pItems;
      v19 = g_DefaultPoolId;
      if ( v18 )
      {
        v15->Curves.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v18);
        v15->Curves.m_pItems = 0i64;
        v15->Curves.m_ulReserved = 0;
      }
      AK::MemoryMgr::Free(v19, v15);
      if ( !v13 )
        break;
      LODWORD(v11) = v24;
    }
  }
  if ( v2->m_listRTPCSwitch.m_ulMaxNumListItems > 0 )
  {
    for ( i = v2->m_listRTPCSwitch.m_pFirst; i; i = i->pNextListItem )
    {
      CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::Term(&i->Item.listRTPCSwitchSubscribers);
      v21 = i->Item.ConversionTable.m_pArrayGraphPoints;
      if ( v21 )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v21);
        i->Item.ConversionTable.m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&i->Item.ConversionTable.m_ulArraySize = 0i64;
    }
  }
  if ( v2->m_SwitchEntries.m_MemPoolId != -1 )
  {
    AkHashList<AkSwitchKey,unsigned long,193>::RemoveAll(&v2->m_SwitchEntries);
    v2->m_SwitchEntries.m_MemPoolId = -1;
  }
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::Term((CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault> *)&v2->m_listSwitchSubscribers);
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::Term(&v2->m_listRTPCSwitch);
  return 1i64;
}

// File Line: 255
// RVA: 0xA54990
AKRESULT __fastcall CAkRTPCMgr::AddSwitchRTPC(CAkRTPCMgr *this, unsigned int in_switchGroup, unsigned int in_RTPC_ID, AkRTPCGraphPointBase<unsigned long> *in_pArrayConversion, unsigned int in_ulConversionArraySize)
{
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v5; // rax
  AkRTPCGraphPointBase<float> *v6; // r15
  unsigned int v7; // er14
  unsigned int v8; // esi
  CAkRTPCMgr *v9; // rdi
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v10; // rax
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v11; // rcx
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v12; // rax
  signed __int64 v13; // rbx
  AkRTPCGraphPointBase<unsigned long> *v14; // rdx
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v16; // rcx
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v17; // rbx
  signed __int64 v18; // rbx
  AKRESULT v19; // er15
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v20; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v21; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v22; // rdx
  CAkSwitchAware *v23; // r14
  __m128i v24; // xmm0
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v25; // rbx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v26; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v27; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v28; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v29; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v30; // rcx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v31; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v32; // rcx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v33; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v34; // rcx
  __int64 v35; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v36; // rcx
  __int128 v37; // [rsp+20h] [rbp-48h]
  __m128i v38; // [rsp+30h] [rbp-38h]
  __int64 v39; // [rsp+48h] [rbp-20h]

  v5 = this->m_listRTPCSwitch.m_pFirst;
  v6 = (AkRTPCGraphPointBase<float> *)in_pArrayConversion;
  v7 = in_RTPC_ID;
  v8 = in_switchGroup;
  v9 = this;
  if ( !v5 )
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
      v10->pNextListItem = v9->m_listRTPCSwitch.m_pFree;
      v9->m_listRTPCSwitch.m_pFree = v10;
    }
    v11 = v9->m_listRTPCSwitch.m_pLast;
    v12 = v9->m_listRTPCSwitch.m_pFree;
    if ( v11 )
      v11->pNextListItem = v12;
    else
      v9->m_listRTPCSwitch.m_pFirst = v12;
    v16 = v9->m_listRTPCSwitch.m_pFree;
    v9->m_listRTPCSwitch.m_pLast = v16;
    v9->m_listRTPCSwitch.m_pFree = v16->pNextListItem;
    v16->pNextListItem = 0i64;
    v17 = v9->m_listRTPCSwitch.m_pLast;
    ++v9->m_listRTPCSwitch.m_ulNumListItems;
    v18 = (signed __int64)&v17->Item;
    if ( v18 )
    {
      *(_DWORD *)v18 = v8;
      *(_DWORD *)(v18 + 4) = v7;
      v19 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
              (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(v18 + 8),
              v6,
              in_ulConversionArraySize,
              0);
      if ( v19 == 1 )
      {
        *(_DWORD *)(v18 + 56) = 0;
        *(_DWORD *)(v18 + 52) = -1;
        *(_QWORD *)(v18 + 40) = 0i64;
        *(_QWORD *)(v18 + 64) = 0i64;
        *(_QWORD *)(v18 + 24) = 0i64;
        *(_QWORD *)(v18 + 32) = 0i64;
      }
      else
      {
        CAkRTPCMgr::RemoveSwitchRTPC(v9, v8);
      }
LABEL_21:
      v20 = v9->m_listSwitchSubscribers.m_pFirst;
      v21 = 0i64;
      if ( !v20 )
        return v19;
      while ( 1 )
      {
        if ( v20->Item.switchGroup != v8 )
        {
          v21 = v20;
          v20 = v20->pNextListItem;
          goto LABEL_50;
        }
        v22 = v20->pNextListItem;
        v23 = v20->Item.pSwitch;
        v38.m128i_i64[1] = (__int64)v21;
        v38.m128i_i64[0] = (__int64)v22;
        if ( v20 == v9->m_listSwitchSubscribers.m_pFirst )
          v9->m_listSwitchSubscribers.m_pFirst = v22;
        else
          v21->pNextListItem = v22;
        if ( v20 == v9->m_listSwitchSubscribers.m_pLast )
          v9->m_listSwitchSubscribers.m_pLast = v21;
        v24 = v38;
        v20->pNextListItem = v9->m_listSwitchSubscribers.m_pFree;
        --v9->m_listSwitchSubscribers.m_ulNumListItems;
        v9->m_listSwitchSubscribers.m_pFree = v20;
        _mm_store_si128((__m128i *)&v37, v24);
        v25 = v9->m_listRTPCSwitch.m_pFirst;
        if ( v25 )
        {
          while ( v25->Item.switchGroup != v8 )
          {
            v25 = v25->pNextListItem;
            if ( !v25 )
              goto LABEL_31;
          }
          if ( v25->Item.listRTPCSwitchSubscribers.m_pFree )
            goto LABEL_42;
          if ( v25->Item.listRTPCSwitchSubscribers.m_ulNumListItems < v25->Item.listRTPCSwitchSubscribers.m_ulMaxNumListItems )
          {
            v29 = (CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                                g_DefaultPoolId,
                                                                                                0x10ui64);
            if ( v29 )
            {
              v29->pNextListItem = v25->Item.listRTPCSwitchSubscribers.m_pFree;
              v25->Item.listRTPCSwitchSubscribers.m_pFree = v29;
LABEL_42:
              v30 = v25->Item.listRTPCSwitchSubscribers.m_pLast;
              v31 = v25->Item.listRTPCSwitchSubscribers.m_pFree;
              if ( v30 )
                v30->pNextListItem = v31;
              else
                v25->Item.listRTPCSwitchSubscribers.m_pFirst = v31;
              v32 = v25->Item.listRTPCSwitchSubscribers.m_pFree;
              v25->Item.listRTPCSwitchSubscribers.m_pLast = v32;
              v25->Item.listRTPCSwitchSubscribers.m_pFree = v32->pNextListItem;
              v32->pNextListItem = 0i64;
              v33 = v25->Item.listRTPCSwitchSubscribers.m_pLast;
              ++v25->Item.listRTPCSwitchSubscribers.m_ulNumListItems;
              v20 = (CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *)v37;
              v33->Item = v23;
              v21 = (CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *)*((_QWORD *)&v37 + 1);
              goto LABEL_50;
            }
          }
          goto LABEL_48;
        }
LABEL_31:
        if ( v23 )
        {
          CAkRTPCMgr::UnSubscribeSwitch(v9, v23);
          LODWORD(v39) = v8;
          if ( v9->m_listSwitchSubscribers.m_pFree )
            goto LABEL_36;
          if ( v9->m_listSwitchSubscribers.m_ulNumListItems < v9->m_listSwitchSubscribers.m_ulMaxNumListItems )
          {
            v26 = (CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
            if ( v26 )
              break;
          }
        }
LABEL_48:
        v21 = (CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *)*((_QWORD *)&v37 + 1);
        v20 = (CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *)v37;
LABEL_50:
        if ( !v20 )
          return v19;
      }
      v26->pNextListItem = v9->m_listSwitchSubscribers.m_pFree;
      v9->m_listSwitchSubscribers.m_pFree = v26;
LABEL_36:
      v27 = v9->m_listSwitchSubscribers.m_pLast;
      v28 = v9->m_listSwitchSubscribers.m_pFree;
      if ( v27 )
        v27->pNextListItem = v28;
      else
        v9->m_listSwitchSubscribers.m_pFirst = v28;
      v34 = v9->m_listSwitchSubscribers.m_pFree;
      v9->m_listSwitchSubscribers.m_pLast = v34;
      v9->m_listSwitchSubscribers.m_pFree = v34->pNextListItem;
      v35 = v39;
      v34->pNextListItem = 0i64;
      v36 = v9->m_listSwitchSubscribers.m_pLast;
      ++v9->m_listSwitchSubscribers.m_ulNumListItems;
      v36->Item.pSwitch = v23;
      *(_QWORD *)&v36->Item.switchGroup = v35;
      goto LABEL_48;
    }
LABEL_20:
    v19 = 2;
    goto LABEL_21;
  }
  while ( v5->Item.switchGroup != in_switchGroup )
  {
    v5 = v5->pNextListItem;
    if ( !v5 )
      goto LABEL_4;
  }
  v13 = (signed __int64)&v5->Item.ConversionTable;
  v5->Item.RTPC_ID = in_RTPC_ID;
  v14 = v5->Item.ConversionTable.m_pArrayGraphPoints;
  if ( v14 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v14);
    *(_QWORD *)v13 = 0i64;
  }
  *(_QWORD *)(v13 + 8) = 0i64;
  return CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
           (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)v13,
           v6,
           in_ulConversionArraySize,
           0);
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
           0,
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
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v2; // rsi
  unsigned int v3; // er14
  CAkRTPCMgr *v4; // rdi
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v5; // r15
  AkRTPCGraphPointBase<unsigned long> *v6; // rdx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v7; // rbx
  CAkSwitchAware *v8; // rbp
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v9; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v10; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v11; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v12; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v13; // rdx
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v14; // rax
  __int64 v15; // [rsp+28h] [rbp-30h]

  v2 = this->m_listRTPCSwitch.m_pFirst;
  v3 = in_switchGroup;
  v4 = this;
  v5 = 0i64;
  if ( v2 )
  {
    while ( v2->Item.switchGroup != in_switchGroup )
    {
      v5 = v2;
      v2 = v2->pNextListItem;
      if ( !v2 )
        return;
    }
    v6 = v2->Item.ConversionTable.m_pArrayGraphPoints;
    if ( v6 )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, v6);
      v2->Item.ConversionTable.m_pArrayGraphPoints = 0i64;
    }
    *(_QWORD *)&v2->Item.ConversionTable.m_ulArraySize = 0i64;
    v7 = v2->Item.listRTPCSwitchSubscribers.m_pFirst;
    if ( v7 )
    {
      while ( 1 )
      {
        v8 = v7->Item;
        if ( v8 )
        {
          CAkRTPCMgr::UnSubscribeSwitch(v4, v7->Item);
          LODWORD(v15) = v3;
          if ( v4->m_listSwitchSubscribers.m_pFree )
            goto LABEL_13;
          if ( v4->m_listSwitchSubscribers.m_ulNumListItems < v4->m_listSwitchSubscribers.m_ulMaxNumListItems )
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
      v9->pNextListItem = v4->m_listSwitchSubscribers.m_pFree;
      v4->m_listSwitchSubscribers.m_pFree = v9;
LABEL_13:
      v10 = v4->m_listSwitchSubscribers.m_pLast;
      v11 = v4->m_listSwitchSubscribers.m_pFree;
      if ( v10 )
        v10->pNextListItem = v11;
      else
        v4->m_listSwitchSubscribers.m_pFirst = v11;
      v12 = v4->m_listSwitchSubscribers.m_pFree;
      v4->m_listSwitchSubscribers.m_pLast = v12;
      v4->m_listSwitchSubscribers.m_pFree = v12->pNextListItem;
      v12->pNextListItem = 0i64;
      v13 = v4->m_listSwitchSubscribers.m_pLast;
      ++v4->m_listSwitchSubscribers.m_ulNumListItems;
      v13->Item.pSwitch = v8;
      *(_QWORD *)&v13->Item.switchGroup = v15;
      goto LABEL_17;
    }
LABEL_18:
    CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::Term(&v2->Item.listRTPCSwitchSubscribers);
    v14 = v2->pNextListItem;
    if ( v2 == v4->m_listRTPCSwitch.m_pFirst )
      v4->m_listRTPCSwitch.m_pFirst = v14;
    else
      v5->pNextListItem = v14;
    if ( v2 == v4->m_listRTPCSwitch.m_pLast )
      v4->m_listRTPCSwitch.m_pLast = v5;
    v2->pNextListItem = v4->m_listRTPCSwitch.m_pFree;
    --v4->m_listRTPCSwitch.m_ulNumListItems;
    v4->m_listRTPCSwitch.m_pFree = v2;
  }
}

// File Line: 357
// RVA: 0xA575A0
signed __int64 __fastcall CAkRTPCMgr::SetRTPCInternal(CAkRTPCMgr *this, unsigned int in_RTPCid, float in_Value, CAkRegisteredObj *in_GameObj, TransParams *in_transParams, AkValueMeaning in_eValueMeaning)
{
  unsigned int v6; // esi
  CAkRTPCMgr::AkRTPCValue *v7; // rdi
  CAkRegisteredObj *v8; // rbp
  CAkRTPCMgr *v9; // r14
  float v10; // xmm6_4
  CAkRTPCMgr::AkRTPCEntry *v11; // rbx
  CAkRTPCMgr::AkRTPCEntry *v12; // rax
  __int64 v13; // rcx

  v6 = in_RTPCid;
  v7 = 0i64;
  v8 = in_GameObj;
  v9 = this;
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
    v12->key = v6;
    v12->fDefaultValue = 0.0;
    v12->values.m_pItems = 0i64;
    *(_QWORD *)&v12->values.m_uLength = 0i64;
    v12->transitions.m_pFirst = 0i64;
    v12->subscriptions.m_pItems = 0i64;
    *(_QWORD *)&v12->subscriptions.m_uLength = 0i64;
    v13 = v12->key % 0xC1;
    v12->pNextItem = v9->m_RTPCEntries.m_table[v13];
    v9->m_RTPCEntries.m_table[v13] = v12;
    ++v9->m_RTPCEntries.m_uiSize;
  }
  if ( in_eValueMeaning == 2 )
    v10 = in_Value + CAkRTPCMgr::AkRTPCEntry::GetCurrentTargetValue(v11, v7);
  return CAkRTPCMgr::AkRTPCEntry::SetRTPC(v11, v7, v10, v8, in_transParams, 0);
}

// File Line: 393
// RVA: 0xA57420
signed __int64 __fastcall CAkRTPCMgr::AkRTPCEntry::SetRTPC(CAkRTPCMgr::AkRTPCEntry *this, CAkRTPCMgr::AkRTPCValue *in_pValueEntry, float in_Value, CAkRegisteredObj *in_GameObj, TransParams *in_transParams, bool in_bUnsetWhenDone)
{
  CAkRegisteredObj *v6; // rbp
  CAkRTPCMgr::AkRTPCValue *v7; // rdi
  float v8; // xmm6_4
  CAkRTPCMgr::AkRTPCEntry *v9; // rsi
  bool v10; // r14
  float v11; // xmm2_4
  CAkRTPCMgr::AkRTPCValue *v12; // rax
  CAkRTPCMgr::CAkRTPCTransition *v14; // rax
  ITransitionable *v15; // rcx
  ITransitionable *v16; // rbx
  bool v17; // zf
  ITransitionableVtbl *v18; // rax
  CAkTransition *v19; // rdx
  int v20; // er15
  ITransitionable *in_pUser[2]; // [rsp+30h] [rbp-38h]

  v6 = in_GameObj;
  v7 = in_pValueEntry;
  v8 = in_Value;
  v9 = this;
  v10 = !in_pValueEntry || in_Value != in_pValueEntry->fValue;
  if ( in_transParams->TransitionTime > 0 && v10 )
  {
    if ( in_pValueEntry )
    {
      v11 = in_pValueEntry->fValue;
    }
    else
    {
      v12 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
              &this->values,
              0i64);
      if ( v12 )
        v11 = v12->fValue;
      else
        v11 = v9->fDefaultValue;
    }
    if ( CAkRTPCMgr::AkRTPCEntry::CreateOrModifyTransition(v9, v6, v11, v8, in_transParams, in_bUnsetWhenDone) )
      return 1i64;
  }
  else
  {
    v14 = this->transitions.m_pFirst;
    in_pUser[1] = 0i64;
    in_pUser[0] = (ITransitionable *)&v14->vfptr;
    _mm_store_si128((__m128i *)in_pUser, (__m128i)(unsigned __int64)v14);
    if ( v14 )
    {
      v15 = in_pUser[1];
      v16 = in_pUser[0];
      while ( (CAkRegisteredObj *)v16[4].vfptr != in_GameObj )
      {
        v15 = v16;
        v16 = (ITransitionable *)v16[1].vfptr;
        if ( !v16 )
          goto LABEL_25;
      }
      v17 = v16 == (ITransitionable *)v14;
      v18 = v16[1].vfptr;
      if ( v17 )
        v9->transitions.m_pFirst = (CAkRTPCMgr::CAkRTPCTransition *)v18;
      else
        v15[1].vfptr = v18;
      v19 = (CAkTransition *)v16[2].vfptr;
      v20 = g_DefaultPoolId;
      v16->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
      if ( v19 )
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v19, v16);
      AK::MemoryMgr::Free(v20, v16);
    }
  }
LABEL_25:
  if ( !v10 && !in_bUnsetWhenDone )
    return 1i64;
  return CAkRTPCMgr::AkRTPCEntry::ApplyRTPCValue(v9, v7, v8, v6, in_bUnsetWhenDone);
}

// File Line: 433
// RVA: 0xA55720
float __fastcall CAkRTPCMgr::AkRTPCEntry::GetCurrentTargetValue(CAkRTPCMgr::AkRTPCEntry *this, CAkRTPCMgr::AkRTPCValue *in_pValueEntry)
{
  CAkRTPCMgr::AkRTPCEntry *v2; // rbx
  CAkRTPCMgr::CAkRTPCTransition *v3; // rax
  CAkRegisteredObj *v4; // r8
  _QWORD *v5; // rax
  float result; // xmm0_4
  CAkRTPCMgr::AkRTPCValue *v7; // rax
  __int128 v8; // [rsp+20h] [rbp-18h]

  v2 = this;
  if ( in_pValueEntry )
  {
    v3 = this->transitions.m_pFirst;
    v4 = in_pValueEntry->pGameObj;
    v8 = (unsigned __int64)v3;
    _mm_store_si128((__m128i *)&v8, (__m128i)(unsigned __int64)v3);
    if ( v3 )
    {
      v5 = (_QWORD *)v8;
      while ( (CAkRegisteredObj *)v5[4] != v4 )
      {
        v5 = (_QWORD *)v5[1];
        if ( !v5 )
          goto LABEL_6;
      }
      result = *(float *)(v5[2] + 12i64);
    }
    else
    {
LABEL_6:
      result = in_pValueEntry->fValue;
    }
  }
  else
  {
    v7 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
           &this->values,
           0i64);
    if ( v7 )
      result = v7->fValue;
    else
      result = v2->fDefaultValue;
  }
  return result;
}

// File Line: 475
// RVA: 0xA55560
bool __fastcall CAkRTPCMgr::AkRTPCEntry::CreateOrModifyTransition(CAkRTPCMgr::AkRTPCEntry *this, CAkRegisteredObj *in_pGameObj, float in_fStartValue, float in_fTargetValue, TransParams *in_transParams, bool in_bRemoveEntryWhenDone)
{
  CAkRegisteredObj *v6; // rsi
  CAkRTPCMgr::AkRTPCEntry *v7; // rdi
  ITransitionable *v8; // rdx
  ITransitionable *v9; // rcx
  ITransitionable *v10; // rbx
  CAkRTPCMgr::CAkRTPCTransition *v11; // rbx
  CAkRTPCMgr::CAkRTPCTransition *v12; // rax
  bool result; // al
  ITransitionableVtbl *v14; // rax
  CAkTransition *v15; // rdx
  int v16; // edi
  ITransitionable *in_pUser[2]; // [rsp+40h] [rbp-38h]

  v6 = in_pGameObj;
  v7 = this;
  in_pUser[0] = (ITransitionable *)&this->transitions.m_pFirst->vfptr;
  v8 = in_pUser[0];
  in_pUser[1] = 0i64;
  _mm_store_si128((__m128i *)in_pUser, (__m128i)(unsigned __int64)in_pUser[0]);
  if ( v8 )
  {
    v9 = in_pUser[1];
    v10 = in_pUser[0];
    while ( (CAkRegisteredObj *)v10[4].vfptr != v6 )
    {
      v9 = v10;
      v10 = (ITransitionable *)v10[1].vfptr;
      if ( !v10 )
        goto LABEL_5;
    }
    if ( in_fStartValue != in_fTargetValue )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        (CAkTransition *)v10[2].vfptr,
        0x10000000i64,
        in_fTargetValue,
        in_transParams->TransitionTime,
        in_transParams->eFadeCurve,
        0);
      LOBYTE(v10[5].vfptr) = in_bRemoveEntryWhenDone;
      return 1;
    }
    v14 = v10[1].vfptr;
    if ( v10 == v8 )
      v7->transitions.m_pFirst = (CAkRTPCMgr::CAkRTPCTransition *)v14;
    else
      v9[1].vfptr = v14;
    v15 = (CAkTransition *)v10[2].vfptr;
    v16 = g_DefaultPoolId;
    v10->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
    if ( v15 )
      CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v15, v10);
    AK::MemoryMgr::Free(v16, v10);
    return 0;
  }
LABEL_5:
  if ( in_fStartValue == in_fTargetValue )
    return 0;
  v11 = (CAkRTPCMgr::CAkRTPCTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
  if ( !v11 )
    return 0;
  v11->vfptr = (ITransitionableVtbl *)&CAkRTPCMgr::CAkRTPCTransition::`vftable;
  v11->m_pTransition = 0i64;
  v11->m_pOwner = v7;
  v11->m_pGameObject = v6;
  v11->m_bRemoveEntryWhenDone = 0;
  if ( CAkRTPCMgr::CAkRTPCTransition::Start(
         v11,
         in_fStartValue,
         in_fTargetValue,
         in_transParams,
         in_bRemoveEntryWhenDone) != 1 )
    return 0;
  v12 = v7->transitions.m_pFirst;
  if ( v12 )
  {
    v11->pNextLightItem = v12;
    v7->transitions.m_pFirst = v11;
    result = 1;
  }
  else
  {
    v7->transitions.m_pFirst = v11;
    result = 1;
    v11->pNextLightItem = 0i64;
  }
  return result;
}

// File Line: 535
// RVA: 0xA54D10
signed __int64 __fastcall CAkRTPCMgr::AkRTPCEntry::ApplyRTPCValue(CAkRTPCMgr::AkRTPCEntry *this, CAkRTPCMgr::AkRTPCValue *in_pValueEntry, float in_NewValue, CAkRegisteredObj *in_GameObj, bool in_bUnsetValue)
{
  CAkRegisteredObj *v5; // rdi
  CAkRTPCMgr::AkRTPCValue *v6; // rbx
  CAkRTPCMgr::AkRTPCEntry *v7; // rsi
  signed __int64 result; // rax
  CAkRTPCMgr::AkRTPCValue *v9; // rax

  v5 = in_GameObj;
  v6 = in_pValueEntry;
  v7 = this;
  CAkRTPCMgr::AkRTPCEntry::NotifyRTPCChange(this, in_pValueEntry, in_NewValue, in_GameObj);
  if ( in_bUnsetValue )
  {
    if ( v6 )
      AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8>::Unset<CAkRegisteredObj *>(
        &v7->values,
        v5);
    result = 1i64;
  }
  else if ( v6 )
  {
    v6->fValue = in_NewValue;
    result = 1i64;
  }
  else
  {
    v9 = AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8>::Set<CAkRegisteredObj *>(
           &v7->values,
           v5);
    if ( v9 )
    {
      v9->fValue = in_NewValue;
      result = 1i64;
    }
    else
    {
      result = 2i64;
    }
  }
  return result;
}

// File Line: 571
// RVA: 0xA56870
void __fastcall CAkRTPCMgr::AkRTPCEntry::NotifyRTPCChange(CAkRTPCMgr::AkRTPCEntry *this, CAkRTPCMgr::AkRTPCValue *in_pValueEntry, float in_NewValue, CAkRegisteredObj *in_GameObj)
{
  unsigned int v4; // er12
  CAkRTPCMgr::AkRTPCEntry *v5; // r14
  CAkRTPCMgr::AkRTPCSubscription **v6; // rbx
  char v7; // r8
  signed __int64 v8; // rdi
  CAkRegisteredObj *v9; // r13
  CAkRTPCMgr::AkRTPCSubscription *v10; // rcx
  signed int v11; // er9
  CAkRTPCMgr::AkRTPCSubscription *v12; // rsi
  CAkRegisteredObj *v13; // rdx
  CAkRTPCMgr::SubscriberType v14; // ecx
  float v15; // xmm6_4
  float v16; // xmm0_4
  void *v17; // rcx
  __int64 v18; // rdx
  CAkRTPCMgr::RTPCCurve *v19; // rax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v20; // r14
  CAkLayer *v21; // r15
  __int64 v22; // rax
  __int64 v23; // rcx
  CAkRTPCMgr::RTPCCurve *v24; // rax
  float v25; // xmm6_4
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v26; // r14
  AkRTPC_ParameterID v27; // er8
  __int64 *v28; // r15
  __int64 v29; // rax
  unsigned int v30; // eax
  CAkRTPCMgr::RTPCCurve *v31; // rax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v32; // r14
  AkArray<CAkRegisteredObj *,CAkRegisteredObj *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *v33; // rcx
  __int64 v34; // rax
  __int64 v35; // r8
  char v36; // [rsp+8h] [rbp-29h]
  float in_pParam; // [rsp+Ch] [rbp-25h]
  unsigned int out_index; // [rsp+10h] [rbp-21h]
  AkArray<CAkRegisteredObj *,CAkRegisteredObj *,ArrayPoolDefault,8,AkArrayAllocatorDefault> io_ExceptArrayObj; // [rsp+20h] [rbp-11h]
  void *in_pGameObjExceptArray; // [rsp+30h] [rbp-1h]
  CAkRTPCMgr::AkRTPCEntry *v41; // [rsp+98h] [rbp+67h]
  CAkRTPCMgr::AkRTPCValue *in_pValueEntrya; // [rsp+A0h] [rbp+6Fh]

  v4 = this->key;
  v5 = this;
  v6 = this->subscriptions.m_pItems;
  v7 = 0;
  v8 = (signed __int64)&v6[this->subscriptions.m_uLength];
  v9 = in_GameObj;
  io_ExceptArrayObj.m_pItems = 0i64;
  *(_QWORD *)&io_ExceptArrayObj.m_uLength = 0i64;
  v36 = 0;
  v10 = 0i64;
  if ( v6 == (CAkRTPCMgr::AkRTPCSubscription **)v8 )
    goto LABEL_66;
  v11 = 523241489;
  do
  {
    v12 = *v6;
    if ( *v6 != v10 )
    {
      v13 = v12->TargetGameObject;
      v10 = *v6;
      if ( v9 == v13 || !v9 || !v13 )
      {
        v14 = v12->eType;
        v15 = 0.0;
        in_pParam = 0.0;
        if ( (unsigned int)(v14 - 1) <= 1 )
        {
          if ( v9 && v14 == 1 )
            goto LABEL_62;
          v28 = (__int64 *)v12->key.pSubscriber;
          v29 = *((_QWORD *)v12->key.pSubscriber + 6);
          if ( !v29 || !*(_WORD *)(v29 + 72) && (!v29 || !*(_WORD *)(v29 + 74)) )
          {
            if ( v14 != 1 )
              goto LABEL_62;
            v30 = v12->key.ParamID;
            if ( v30 > 0x1C || !_bittest(&v11, v30) )
              goto LABEL_62;
          }
          v31 = v12->Curves.m_pItems;
          if ( v31 != &v31[v12->Curves.m_uLength] )
          {
            v32 = &v31->ConversionTable;
            do
            {
              if ( v32[-1].m_eScaling == v4 )
              {
                v15 = v15
                    + CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                        v32,
                        in_NewValue,
                        0,
                        &out_index);
                in_pParam = v15;
              }
              v32 = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)((char *)v32 + 24);
            }
            while ( &v32[-1].m_ulArraySize != (unsigned int *)&v12->Curves.m_pItems[v12->Curves.m_uLength] );
            v5 = v41;
            v7 = v36;
          }
          v33 = 0i64;
          if ( !v9 && v12->eType != 1 )
          {
            if ( !v7 )
            {
              CAkRTPCMgr::AkRTPCEntry::GetRTPCExceptions(v5, &io_ExceptArrayObj);
              v15 = in_pParam;
            }
            v33 = &io_ExceptArrayObj;
          }
          v34 = *v28;
          v35 = (unsigned int)v12->key.ParamID;
          in_pGameObjExceptArray = v33;
          *(_QWORD *)&io_ExceptArrayObj.m_uLength = v9;
          *(float *)&io_ExceptArrayObj.m_pItems = v15;
          (*(void (__fastcall **)(__int64 *, CAkRTPCMgr::AkRTPCSubscription *, __int64, _QWORD))(v34 + 472))(
            v28,
            v12,
            v35,
            v4);
          goto LABEL_61;
        }
        if ( v14 == SubscriberType_IAkRTPCSubscriber )
        {
          if ( v9 == v13 )
            goto LABEL_12;
          if ( !v9 )
          {
            if ( AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                   &v5->values,
                   v13) )
            {
LABEL_61:
              v7 = v36;
              v11 = 523241489;
              goto LABEL_62;
            }
LABEL_12:
            v16 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                    &v12->Curves.m_pItems->ConversionTable,
                    in_NewValue,
                    0,
                    &out_index);
            v17 = v12->key.pSubscriber;
            v18 = LOWORD(v12->key.ParamID);
            in_pParam = v16;
            (*(void (__fastcall **)(void *, __int64, float *, signed __int64))(*(_QWORD *)v17 + 8i64))(
              v17,
              v18,
              &in_pParam,
              4i64);
            goto LABEL_61;
          }
LABEL_62:
          v10 = v12;
          goto LABEL_63;
        }
        if ( v14 != 4 )
        {
          v21 = (CAkLayer *)v12->key.pSubscriber;
          v22 = *((_QWORD *)v12->key.pSubscriber + 6);
          if ( !v22 )
            goto LABEL_62;
          v23 = *(_QWORD *)(v22 + 48);
          if ( !v23 || !*(_WORD *)(v23 + 72) )
            goto LABEL_62;
          if ( CAkLayer::IsPlaying((CAkLayer *)v12->key.pSubscriber) )
          {
            v24 = v12->Curves.m_pItems;
            v25 = in_pParam;
            if ( v24 != &v24[v12->Curves.m_uLength] )
            {
              v26 = &v24->ConversionTable;
              do
              {
                if ( v26[-1].m_eScaling == v4 )
                {
                  v25 = v25
                      + CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                          v26,
                          in_NewValue,
                          0,
                          &out_index);
                  in_pParam = v25;
                }
                v26 = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)((char *)v26 + 24);
              }
              while ( &v26[-1].m_ulArraySize != (unsigned int *)&v12->Curves.m_pItems[v12->Curves.m_uLength] );
              v5 = v41;
            }
            if ( !v9 && !v36 )
            {
              CAkRTPCMgr::AkRTPCEntry::GetRTPCExceptions(v5, &io_ExceptArrayObj);
              v25 = in_pParam;
            }
            v27 = v12->key.ParamID;
            if ( v27 == 64 )
              CAkLayer::OnRTPCChanged(v21, v9, in_NewValue);
            else
              CAkLayer::SetParamComplexFromRTPCManager(v21, v12, v27, v4, v25, v9, &io_ExceptArrayObj);
          }
          goto LABEL_61;
        }
        if ( v9 != v13 )
        {
          if ( v9 )
            goto LABEL_62;
          if ( AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                 &v5->values,
                 v13) )
          {
            goto LABEL_61;
          }
        }
        v19 = v12->Curves.m_pItems;
        if ( v19 != &v19[v12->Curves.m_uLength] )
        {
          v20 = &v19->ConversionTable;
          do
          {
            if ( v20[-1].m_eScaling == v4 )
            {
              v15 = v15
                  + CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                      v20,
                      in_NewValue,
                      0,
                      &out_index);
              in_pParam = v15;
            }
            v20 = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)((char *)v20 + 24);
          }
          while ( &v20[-1].m_ulArraySize != (unsigned int *)&v12->Curves.m_pItems[v12->Curves.m_uLength] );
          v5 = v41;
        }
        CAkPBI::SetParam((CAkPBI *)v12->key.pSubscriber, v12->key.ParamID, &in_pParam, 4u);
        goto LABEL_61;
      }
    }
LABEL_63:
    ++v6;
  }
  while ( v6 != (CAkRTPCMgr::AkRTPCSubscription **)v8 );
  if ( io_ExceptArrayObj.m_pItems )
  {
    io_ExceptArrayObj.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, io_ExceptArrayObj.m_pItems);
    io_ExceptArrayObj.m_pItems = 0i64;
    io_ExceptArrayObj.m_ulReserved = 0;
  }
LABEL_66:
  CAkRTPCMgr::NotifyClientRTPCChange(g_pRTPCMgr, v4, in_pValueEntrya, in_NewValue, v9);
}

// File Line: 761
// RVA: 0xA567A0
void __fastcall CAkRTPCMgr::NotifyClientRTPCChange(CAkRTPCMgr *this, unsigned int in_idRTPC, CAkRTPCMgr::AkRTPCValue *in_pValueEntry, float in_NewValue, CAkRegisteredObj *in_GameObj)
{
  CAkRegisteredObj *v5; // rbp
  CAkRTPCMgr::AkRTPCValue *v6; // r15
  unsigned int v7; // er14
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *i; // rdi
  unsigned int v9; // esi
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *j; // rbx

  v5 = in_GameObj;
  v6 = in_pValueEntry;
  v7 = in_idRTPC;
  if ( in_GameObj )
  {
    for ( i = this->m_listRTPCSwitch.m_pFirst; i; i = i->pNextListItem )
    {
      if ( i->Item.RTPC_ID == v7 )
      {
        v9 = CAkConversionTable<AkRTPCGraphPointBase<unsigned long>,unsigned long>::ConvertInternal(
               &i->Item.ConversionTable,
               in_NewValue,
               0,
               (unsigned int *)&in_GameObj);
        if ( !v6
          || (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<unsigned long>,unsigned long>::ConvertInternal(
                             &i->Item.ConversionTable,
                             v6->fValue,
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
void __fastcall CAkRTPCMgr::RemoveReferencesToSubscription(CAkRTPCMgr *this, CAkRTPCMgr::AkRTPCSubscription *in_pSubscription)
{
  CAkRTPCMgr::RTPCCurve *v2; // rax
  char v3; // bp
  CAkRTPCMgr::AkRTPCSubscription *v4; // rbx
  CAkRTPCMgr *v5; // r14
  signed __int64 v6; // rdi
  CAkRTPCMgr::AkRTPCEntry *v7; // rcx
  CAkRTPCMgr::AkRTPCEntry *v8; // r9
  __int64 v9; // r8
  __int64 v10; // r11
  int v11; // edi
  int v12; // esi
  CAkRTPCMgr::AkRTPCSubscription **v13; // r10
  int v14; // eax
  unsigned __int64 v15; // rdx
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // rdi

  v2 = in_pSubscription->Curves.m_pItems;
  v3 = 0;
  v4 = in_pSubscription;
  v5 = this;
  if ( v2 != &v2[in_pSubscription->Curves.m_uLength] )
  {
    v6 = (signed __int64)&v2->ConversionTable;
    do
    {
      v7 = v5->m_RTPCEntries.m_table[*(_DWORD *)(v6 - 4) % 0xC1u];
      if ( v7 )
      {
        while ( v7->key != *(_DWORD *)(v6 - 4) )
        {
          v7 = v7->pNextItem;
          if ( !v7 )
            goto LABEL_9;
        }
        if ( v7 )
        {
          AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::Unset<CAkRTPCMgr::AkRTPCSubscription *>(
            &v7->subscriptions,
            v4);
          v3 = 1;
        }
      }
LABEL_9:
      if ( *(_QWORD *)v6 )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, *(void **)v6);
        *(_QWORD *)v6 = 0i64;
      }
      *(_QWORD *)(v6 + 8) = 0i64;
      v6 += 24i64;
    }
    while ( (CAkRTPCMgr::RTPCCurve *)(v6 - 8) != &v4->Curves.m_pItems[v4->Curves.m_uLength] );
  }
  v4->Curves.m_uLength = 0;
  if ( !v3 )
  {
    v8 = v5->m_RTPCEntries.m_table[0];
    LODWORD(v9) = 0;
    if ( v5->m_RTPCEntries.m_table[0] )
      goto LABEL_36;
    while ( 1 )
    {
      v9 = (unsigned int)(v9 + 1);
      if ( (unsigned int)v9 >= 0xC1 )
        break;
      v8 = v5->m_RTPCEntries.m_table[v9];
      if ( v8 )
        goto LABEL_18;
    }
    if ( v8 )
    {
LABEL_36:
      while ( 1 )
      {
LABEL_18:
        v10 = v8->subscriptions.m_uLength;
        v11 = 0;
        v12 = v10 - 1;
        if ( (signed int)v10 - 1 >= 0 )
        {
          v13 = v8->subscriptions.m_pItems;
          do
          {
            v14 = v11 + (v12 - v11) / 2;
            v15 = (unsigned __int64)v13[v14];
            if ( (unsigned __int64)v4 >= v15 )
            {
              if ( (unsigned __int64)v4 <= v15 )
              {
                v16 = (unsigned __int64)&v13[v10 - 1];
                v17 = (unsigned __int64)&v13[v14];
                if ( v17 < v16 )
                  qmemcpy((void *)v17, (const void *)(v17 + 8), 8 * (((v16 - v17 - 1) >> 3) + 1));
                --v8->subscriptions.m_uLength;
                break;
              }
              v11 = v14 + 1;
            }
            else
            {
              v12 = v14 - 1;
            }
          }
          while ( v11 <= v12 );
        }
        v8 = v8->pNextItem;
        if ( !v8 )
        {
          while ( 1 )
          {
            v9 = (unsigned int)(v9 + 1);
            if ( (unsigned int)v9 >= 0xC1 )
              break;
            v8 = v5->m_RTPCEntries.m_table[v9];
            if ( v8 )
              goto LABEL_18;
          }
          if ( !v8 )
            break;
        }
      }
    }
  }
}

// File Line: 818
// RVA: 0xA576D0
__int64 __fastcall CAkRTPCMgr::SetSwitchInternal(CAkRTPCMgr *this, unsigned int in_SwitchGroup, unsigned int in_SwitchState, CAkRegisteredObj *in_GameObj)
{
  unsigned int v4; // edi
  CAkRTPCMgr *v5; // rbx
  CAkRegisteredObj *v6; // r14
  unsigned int v7; // ebp
  unsigned int *v8; // rax
  unsigned int v9; // esi
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *i; // rbx
  unsigned int v12; // [rsp+20h] [rbp-18h]
  CAkRegisteredObj *v13; // [rsp+28h] [rbp-10h]

  v12 = in_SwitchGroup;
  v13 = in_GameObj;
  v4 = in_SwitchGroup;
  v5 = this;
  _mm_store_si128((__m128i *)&v12, *(__m128i *)&v12);
  v6 = in_GameObj;
  v7 = in_SwitchState;
  v8 = AkHashList<AkSwitchKey,unsigned long,193>::Set(&this->m_SwitchEntries, (AkSwitchKey *)&v12);
  if ( v8 )
  {
    *v8 = v7;
    v9 = 1;
  }
  else
  {
    v9 = 2;
  }
  for ( i = v5->m_listSwitchSubscribers.m_pFirst; i; i = i->pNextListItem )
  {
    if ( i->Item.switchGroup == v4 )
      i->Item.pSwitch->vfptr->SetSwitch(i->Item.pSwitch, v7, v6);
  }
  return v9;
}

// File Line: 848
// RVA: 0xA55ED0
__int64 __fastcall CAkRTPCMgr::GetSwitch(CAkRTPCMgr *this, unsigned int in_SwitchGroup, CAkRegisteredObj *in_GameObj)
{
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v3; // rbx
  CAkRegisteredObj *v4; // rsi
  CAkRTPCMgr *v5; // r14
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v6; // rax
  unsigned int v7; // ecx
  unsigned int *v8; // rax
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v9; // rax
  __int64 result; // rax
  unsigned int v11; // edi
  CAkRTPCMgr::AkRTPCEntry *v12; // rcx
  AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *v13; // rbp
  CAkRTPCMgr::AkRTPCValue *v14; // rax
  float v15; // xmm1_4
  CAkRTPCMgr::AkRTPCEntry *v16; // rcx
  unsigned int out_index; // [rsp+40h] [rbp+8h]

  v3 = this->m_listRTPCSwitch.m_pFirst;
  v4 = in_GameObj;
  v5 = this;
  if ( v3 )
  {
    while ( v3->Item.switchGroup != in_SwitchGroup )
    {
      v3 = v3->pNextListItem;
      if ( !v3 )
        goto LABEL_4;
    }
    v11 = v3->Item.RTPC_ID;
    v12 = this->m_RTPCEntries.m_table[v3->Item.RTPC_ID % 0xC1];
    if ( !v12 )
      goto LABEL_25;
    while ( v12->key != v11 )
    {
      v12 = v12->pNextItem;
      if ( !v12 )
        goto LABEL_25;
    }
    if ( v12
      && ((v13 = &v12->values,
           (v14 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                    &v12->values,
                    in_GameObj)) != 0i64)
       || v4
       && (v14 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                   v13,
                   0i64)) != 0i64) )
    {
      v15 = v14->fValue;
    }
    else
    {
LABEL_25:
      v16 = v5->m_RTPCEntries.m_table[v11 % 0xC1];
      if ( !v16 )
        goto LABEL_28;
      while ( v16->key != v11 )
      {
        v16 = v16->pNextItem;
        if ( !v16 )
          goto LABEL_28;
      }
      if ( v16 )
        v15 = v16->fDefaultValue;
      else
LABEL_28:
        v15 = 0.0;
    }
    result = CAkConversionTable<AkRTPCGraphPointBase<unsigned long>,unsigned long>::ConvertInternal(
               &v3->Item.ConversionTable,
               v15,
               0,
               &out_index);
  }
  else
  {
LABEL_4:
    v6 = this->m_SwitchEntries.m_table[(_QWORD)in_GameObj
                                     + in_SwitchGroup
                                     + -193
                                     * ((unsigned __int64)(((unsigned __int64)in_GameObj + in_SwitchGroup)
                                                         * (unsigned __int128)0x15390948F40FEAC7ui64 >> 64) >> 4)];
    v7 = 0;
    if ( v6 )
    {
      while ( v6->Assoc.key.m_SwitchGroup != in_SwitchGroup || v6->Assoc.key.m_pGameObj != in_GameObj )
      {
        v6 = v6->pNextItem;
        if ( !v6 )
          goto LABEL_8;
      }
      v8 = &v6->Assoc.item;
    }
    else
    {
LABEL_8:
      v8 = 0i64;
    }
    if ( v8 )
      goto LABEL_38;
    if ( in_GameObj )
    {
      v9 = v5->m_SwitchEntries.m_table[in_SwitchGroup
                                     - 193
                                     * ((unsigned __int64)(in_SwitchGroup * (unsigned __int128)0x15390948F40FEAC7ui64 >> 64) >> 4)];
      if ( v9 )
      {
        while ( v9->Assoc.key.m_SwitchGroup != in_SwitchGroup || v9->Assoc.key.m_pGameObj )
        {
          v9 = v9->pNextItem;
          if ( !v9 )
            return 0i64;
        }
        v8 = &v9->Assoc.item;
        if ( v8 )
LABEL_38:
          v7 = *v8;
      }
    }
    result = v7;
  }
  return result;
}

// File Line: 891
// RVA: 0xA559B0
float __fastcall CAkRTPCMgr::GetRTPCConvertedValue(CAkRTPCMgr *this, void *in_pToken, CAkRegisteredObj *in_GameObj, unsigned int in_RTPCid)
{
  unsigned int v4; // esi
  CAkRegisteredObj *v5; // rbp
  _QWORD *v6; // r13
  CAkRTPCMgr *v7; // r15
  CAkRTPCMgr::AkRTPCEntry *v8; // rcx
  float v9; // xmm6_4
  char v10; // r12
  __int64 v11; // rax
  float v12; // xmm7_4
  signed __int64 v13; // r14
  unsigned int v14; // ebx
  CAkRTPCMgr::AkRTPCEntry *v15; // rcx
  CAkRTPCMgr::AkRTPCEntry *v16; // rcx
  AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *v18; // rbx
  CAkRTPCMgr::AkRTPCValue *v19; // rax
  AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *v20; // rdi
  CAkRTPCMgr::AkRTPCValue *v21; // rax
  CAkRTPCMgr::AkRTPCValue *v22; // rax
  float in_valueToConvert; // [rsp+88h] [rbp+20h]

  v4 = in_RTPCid;
  v5 = in_GameObj;
  v6 = in_pToken;
  v7 = this;
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
  if ( v8
    && ((v18 = &v8->values,
         (v19 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                  &v8->values,
                  in_GameObj)) != 0i64)
     || v5
     && (v19 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                 v18,
                 0i64)) != 0i64) )
  {
    v9 = v19->fValue;
    v10 = 1;
  }
  else
  {
LABEL_5:
    v9 = in_valueToConvert;
    v10 = 0;
  }
  v11 = v6[5];
  v12 = 0.0;
  if ( v11 != v11 + 24i64 * *((unsigned int *)v6 + 12) )
  {
    v13 = v11 + 4;
    while ( 1 )
    {
      if ( v4 && *(_DWORD *)v13 != v4 )
        goto LABEL_20;
      if ( !v10 )
        break;
LABEL_19:
      v12 = v12
          + CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
              (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(v13 + 4),
              v9,
              0,
              (unsigned int *)&in_valueToConvert);
LABEL_20:
      v13 += 24i64;
      if ( v13 - 4 == v6[5] + 24i64 * *((unsigned int *)v6 + 12) )
        return v12;
    }
    if ( v4 )
    {
      v16 = v7->m_RTPCEntries.m_table[*(_DWORD *)v13 % 0xC1u];
      if ( !v16 )
      {
LABEL_18:
        v9 = 0.0;
        goto LABEL_19;
      }
      while ( v16->key != *(_DWORD *)v13 )
      {
        v16 = v16->pNextItem;
        if ( !v16 )
          goto LABEL_18;
      }
    }
    else
    {
      v14 = *(_DWORD *)v13;
      v15 = v7->m_RTPCEntries.m_table[*(_DWORD *)v13 % 0xC1u];
      if ( v15 )
      {
        while ( v15->key != v14 )
        {
          v15 = v15->pNextItem;
          if ( !v15 )
            goto LABEL_15;
        }
        if ( v15 )
        {
          v20 = &v15->values;
          v21 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                  &v15->values,
                  v5);
          if ( v21 )
          {
            v9 = v21->fValue;
            goto LABEL_19;
          }
          if ( v5 )
          {
            v22 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                    v20,
                    0i64);
            if ( v22 )
            {
              v9 = v22->fValue;
              goto LABEL_19;
            }
          }
        }
      }
LABEL_15:
      v16 = v7->m_RTPCEntries.m_table[v14 % 0xC1];
      if ( !v16 )
        goto LABEL_18;
      while ( v16->key != v14 )
      {
        v16 = v16->pNextItem;
        if ( !v16 )
          goto LABEL_18;
      }
    }
    if ( v16 )
    {
      v9 = v16->fDefaultValue;
      goto LABEL_19;
    }
    goto LABEL_18;
  }
  return v12;
}

// File Line: 926
// RVA: 0xA55800
float __fastcall CAkRTPCMgr::GetRTPCConvertedValue(CAkRTPCMgr *this, void *in_pSubscriber, unsigned int in_ParamID, CAkRegisteredObj *in_GameObj)
{
  CAkRegisteredObj *v4; // rbp
  CAkRTPCMgr *v5; // r15
  CAkRTPCMgr::AkRTPCSubscription *v6; // rdi
  CAkRTPCMgr::RTPCCurve *v8; // rax
  float v9; // xmm6_4
  signed __int64 v10; // r14
  unsigned int v11; // ebx
  CAkRTPCMgr::AkRTPCEntry *v12; // rcx
  CAkRTPCMgr::AkRTPCEntry *v13; // rcx
  float v14; // xmm1_4
  float v15; // xmm0_4
  AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *v16; // rsi
  CAkRTPCMgr::AkRTPCValue *v17; // rax
  CAkRTPCMgr::AkRTPCValue *v18; // rax
  unsigned int out_index; // [rsp+60h] [rbp+18h]

  v4 = in_GameObj;
  v5 = this;
  v6 = this->m_RTPCSubscribers.m_table[((unsigned int)in_pSubscriber + in_ParamID) % 0xC1];
  if ( !v6 )
    return 0.0;
  while ( v6->key.pSubscriber != in_pSubscriber || v6->key.ParamID != in_ParamID )
  {
    v6 = v6->pNextItem;
    if ( !v6 )
      return 0.0;
  }
  if ( !v6 )
    return 0.0;
  v8 = v6->Curves.m_pItems;
  v9 = 0.0;
  if ( v8 != &v8[v6->Curves.m_uLength] )
  {
    v10 = (signed __int64)&v8->RTPC_ID;
    while ( 1 )
    {
      v11 = *(_DWORD *)v10;
      v12 = v5->m_RTPCEntries.m_table[*(_DWORD *)v10 % 0xC1u];
      if ( !v12 )
        break;
      while ( v12->key != v11 )
      {
        v12 = v12->pNextItem;
        if ( !v12 )
          goto LABEL_12;
      }
      if ( !v12 )
        break;
      v16 = &v12->values;
      v17 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
              &v12->values,
              v4);
      if ( v17 )
      {
        v14 = v17->fValue;
      }
      else
      {
        if ( !v4 )
          break;
        v18 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                v16,
                0i64);
        if ( !v18 )
          break;
        v14 = v18->fValue;
      }
LABEL_16:
      v15 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
              (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(v10 + 4),
              v14,
              0,
              &out_index);
      v10 += 24i64;
      v9 = v9 + v15;
      if ( (CAkRTPCMgr::RTPCCurve *)(v10 - 4) == &v6->Curves.m_pItems[v6->Curves.m_uLength] )
        return v9;
    }
LABEL_12:
    v13 = v5->m_RTPCEntries.m_table[v11 % 0xC1];
    if ( !v13 )
      goto LABEL_15;
    while ( v13->key != v11 )
    {
      v13 = v13->pNextItem;
      if ( !v13 )
        goto LABEL_15;
    }
    if ( v13 )
      v14 = v13->fDefaultValue;
    else
LABEL_15:
      v14 = 0.0;
    goto LABEL_16;
  }
  return v9;
}

// File Line: 944
// RVA: 0xA55E00
char __fastcall CAkRTPCMgr::GetRTPCValue(CAkRTPCMgr *this, unsigned int in_RTPC_ID, CAkRegisteredObj *in_GameObj, float *out_value, bool *out_bGameObjectSpecificValue)
{
  float *v5; // rsi
  CAkRegisteredObj *v6; // rbx
  CAkRTPCMgr::AkRTPCEntry *v7; // r10
  AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *v9; // rdi
  CAkRTPCMgr::AkRTPCValue *v10; // rax
  CAkRTPCMgr::AkRTPCValue *v11; // rax

  v5 = out_value;
  v6 = in_GameObj;
  v7 = this->m_RTPCEntries.m_table[in_RTPC_ID % 0xC1];
  if ( !v7 )
    return 0;
  while ( v7->key != in_RTPC_ID )
  {
    v7 = v7->pNextItem;
    if ( !v7 )
      return 0;
  }
  if ( !v7 )
    return 0;
  v9 = &v7->values;
  v10 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
          &v7->values,
          in_GameObj);
  if ( v10 )
  {
    *v5 = v10->fValue;
    *out_bGameObjectSpecificValue = v6 != 0i64;
    return 1;
  }
  if ( !v6 )
    return 0;
  *out_bGameObjectSpecificValue = 0;
  v11 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
          v9,
          0i64);
  if ( !v11 )
    return 0;
  *v5 = v11->fValue;
  return 1;
}

// File Line: 985
// RVA: 0xA577E0
signed int __fastcall CAkRTPCMgr::SubscribeRTPC(CAkRTPCMgr *this, void *in_pSubscriber, unsigned int in_RTPC_ID, AkRTPC_ParameterID in_ParamID, unsigned int in_RTPCCurveID, AkCurveScaling in_eScaling, AkRTPCGraphPointBase<float> *in_pArrayConversion, unsigned int in_ulConversionArraySize, CAkRegisteredObj *in_TargetGameObject, CAkRTPCMgr::SubscriberType in_eType)
{
  AkRTPC_ParameterID v10; // er12
  void *v11; // r15
  CAkRTPCMgr *v12; // rsi
  signed int v13; // ebp
  __int64 v14; // rdi
  CAkRTPCMgr::AkRTPCSubscription *v15; // rbx
  CAkRTPCMgr::RTPCCurve *v16; // rdi
  signed __int64 v17; // r14
  signed __int64 v18; // rax
  CAkRTPCMgr::SubscriberType v19; // er8
  CAkRTPCMgr::RTPCCurve *v20; // rax
  CAkRTPCMgr *v21; // rdi
  signed __int64 v22; // rdx
  __int64 v23; // rcx
  __int64 v24; // rax
  CAkRTPCMgr::AkRTPCEntry *v25; // rcx
  AkRTPCGraphPointBase<float> *v26; // rdx
  unsigned __int64 v27; // rdx
  CAkRTPCMgr::AkRTPCSubscription *v28; // rax
  __m128i v29; // xmm0
  signed __int64 v30; // rcx
  CAkRTPCMgr::AkRTPCEntry *v31; // rax
  CAkRTPCMgr::AkRTPCSubscription **v32; // rax
  __int64 v34; // rax
  void *v35; // rdx
  int v36; // edi
  CAkRTPCMgr *v37; // [rsp+60h] [rbp+8h]
  __int64 v38; // [rsp+68h] [rbp+10h]
  unsigned int in_RTPCid; // [rsp+70h] [rbp+18h]

  in_RTPCid = in_RTPC_ID;
  v37 = this;
  v10 = in_ParamID;
  v11 = in_pSubscriber;
  v12 = this;
  v13 = 31;
  if ( !in_pSubscriber )
    return 31;
  v14 = ((signed int)in_pSubscriber + in_ParamID) % 0xC1u;
  v15 = this->m_RTPCSubscribers.m_table[v14];
  v38 = (unsigned int)v14;
  if ( v15 )
  {
    while ( v15->key.pSubscriber != in_pSubscriber || v15->key.ParamID != in_ParamID )
    {
      v15 = v15->pNextItem;
      if ( !v15 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v15 = 0i64;
  }
  if ( v15 )
  {
    v16 = v15->Curves.m_pItems;
    v17 = (signed __int64)&v15->Curves;
    v18 = (signed __int64)&v16[v15->Curves.m_uLength];
    if ( v16 != (CAkRTPCMgr::RTPCCurve *)v18 )
    {
      while ( v16->RTPCCurveID != in_RTPCCurveID )
      {
        ++v16;
        if ( v16 == (CAkRTPCMgr::RTPCCurve *)v18 )
          goto LABEL_11;
      }
      v25 = this->m_RTPCEntries.m_table[v16->RTPC_ID % 0xC1];
      if ( v25 )
      {
        while ( v25->key != v16->RTPC_ID )
        {
          v25 = v25->pNextItem;
          if ( !v25 )
            goto LABEL_29;
        }
        if ( v25 )
          AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::Unset<CAkRTPCMgr::AkRTPCSubscription *>(
            &v25->subscriptions,
            v15);
      }
LABEL_29:
      v26 = v16->ConversionTable.m_pArrayGraphPoints;
      if ( v26 )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v26);
        v16->ConversionTable.m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&v16->ConversionTable.m_ulArraySize = 0i64;
      v27 = (unsigned __int64)v15->Curves.m_pItems + 8 * (3i64 * v15->Curves.m_uLength - 3);
      if ( (unsigned __int64)v16 < v27 )
        qmemcpy(
          v16,
          &v16[1],
          24
        * (((unsigned __int64)((v27 - (unsigned __int64)v16 - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 4)
         + 1));
      --v15->Curves.m_uLength;
    }
LABEL_11:
    v19 = in_eType;
  }
  else
  {
    v28 = (CAkRTPCMgr::AkRTPCSubscription *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
    v15 = v28;
    if ( !v28 )
      return 52;
    v19 = in_eType;
    v17 = (signed __int64)&v28->Curves;
    *(_QWORD *)v17 = 0i64;
    *(_QWORD *)(v17 + 8) = 0i64;
    v28->key.pSubscriber = v11;
    v28->key.ParamID = v10;
    v28->eType = in_eType;
    v29 = (__m128i)v28->key;
    v28->TargetGameObject = in_TargetGameObject;
    v30 = (signed __int64)v12 + 8 * ((_mm_cvtsi128_si32(_mm_srli_si128(v29, 8)) + v29.m128i_i32[0]) % 0xC1u);
    v28->pNextItem = *(CAkRTPCMgr::AkRTPCSubscription **)(v30 + 3112);
    *(_QWORD *)(v30 + 3112) = v28;
    ++v12->m_RTPCSubscribers.m_uiSize;
  }
  if ( !in_pArrayConversion || !in_ulConversionArraySize )
  {
    if ( v19 != 3 || v10 != 64 )
      goto LABEL_16;
    v13 = 1;
    goto LABEL_41;
  }
  v20 = AkArray<CAkRTPCMgr::RTPCCurve,CAkRTPCMgr::RTPCCurve const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast((AkArray<CAkRTPCMgr::RTPCCurve,CAkRTPCMgr::RTPCCurve const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)v17);
  if ( v20 )
  {
    v20->RTPC_ID = in_RTPCid;
    v20->RTPCCurveID = in_RTPCCurveID;
    v13 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
            &v20->ConversionTable,
            in_pArrayConversion,
            in_ulConversionArraySize,
            in_eScaling);
    if ( v13 != 1 )
    {
      --*(_DWORD *)(v17 + 8);
      goto LABEL_16;
    }
LABEL_41:
    v21 = v37;
    v31 = CAkRTPCMgr::GetRTPCEntry(v37, in_RTPCid);
    if ( v31 )
    {
      v32 = AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::AddNoSetKey<CAkRTPCMgr::AkRTPCSubscription *>(
              &v31->subscriptions,
              v15);
      if ( v32 )
        *v32 = v15;
      if ( v13 == 1 )
        return CAkRTPCMgr::UpdateRTPCSubscriberInfo(v37, v11);
    }
    else
    {
      v13 = 52;
    }
    goto LABEL_17;
  }
  v13 = 52;
LABEL_16:
  v21 = v37;
LABEL_17:
  if ( !v15->Curves.m_uLength )
  {
    v22 = (signed __int64)v21 + 8 * (unsigned int)v38;
    v23 = 0i64;
    v24 = *(_QWORD *)(v22 + 3112);
    if ( v24 )
    {
      while ( *(void **)v24 != v11 || *(_DWORD *)(v24 + 8) != v10 )
      {
        v23 = v24;
        v24 = *(_QWORD *)(v24 + 16);
        if ( !v24 )
          goto LABEL_52;
      }
      v34 = *(_QWORD *)(v24 + 16);
      if ( v23 )
        *(_QWORD *)(v23 + 16) = v34;
      else
        *(_QWORD *)(v22 + 3112) = v34;
      --v21->m_RTPCSubscribers.m_uiSize;
    }
LABEL_52:
    CAkRTPCMgr::RemoveReferencesToSubscription(v21, v15);
    v35 = *(void **)v17;
    v36 = g_DefaultPoolId;
    if ( *(_QWORD *)v17 )
    {
      *(_DWORD *)(v17 + 8) = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v35);
      *(_QWORD *)v17 = 0i64;
      *(_DWORD *)(v17 + 12) = 0;
    }
    AK::MemoryMgr::Free(v36, v15);
  }
  return v13;
}

// File Line: 1084
// RVA: 0xA57BA0
signed __int64 __fastcall CAkRTPCMgr::SubscribeSwitch(CAkRTPCMgr *this, CAkSwitchAware *in_pSwitch, unsigned int in_switchGroup, bool in_bForceNoRTPC)
{
  unsigned int v4; // edi
  CAkSwitchAware *v5; // rsi
  CAkRTPCMgr *v6; // rbx
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *v7; // rcx
  signed __int64 result; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v9; // rax
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v10; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v11; // rax
  bool v12; // cf
  signed __int64 v13; // rdx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v14; // rcx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v15; // rdx
  __int64 v16; // [rsp+28h] [rbp-10h]

  v4 = in_switchGroup;
  v5 = in_pSwitch;
  v6 = this;
  if ( !in_bForceNoRTPC )
  {
    v7 = this->m_listRTPCSwitch.m_pFirst;
    if ( v7 )
    {
      while ( v7->Item.switchGroup != in_switchGroup )
      {
        v7 = v7->pNextListItem;
        if ( !v7 )
          goto LABEL_5;
      }
      v12 = CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::AddLast(
              &v7->Item.listRTPCSwitchSubscribers,
              in_pSwitch) != 0i64;
      return 2 - (unsigned int)v12;
    }
  }
LABEL_5:
  result = 31i64;
  if ( !in_pSwitch )
    return result;
  CAkRTPCMgr::UnSubscribeSwitch(v6, in_pSwitch);
  LODWORD(v16) = v4;
  if ( v6->m_listSwitchSubscribers.m_pFree )
    goto LABEL_10;
  if ( v6->m_listSwitchSubscribers.m_ulNumListItems < v6->m_listSwitchSubscribers.m_ulMaxNumListItems )
  {
    v9 = (CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
    if ( v9 )
    {
      v9->pNextListItem = v6->m_listSwitchSubscribers.m_pFree;
      v6->m_listSwitchSubscribers.m_pFree = v9;
LABEL_10:
      v10 = v6->m_listSwitchSubscribers.m_pLast;
      v11 = v6->m_listSwitchSubscribers.m_pFree;
      if ( v10 )
        v10->pNextListItem = v11;
      else
        v6->m_listSwitchSubscribers.m_pFirst = v11;
      v14 = v6->m_listSwitchSubscribers.m_pFree;
      v6->m_listSwitchSubscribers.m_pLast = v14;
      v6->m_listSwitchSubscribers.m_pFree = v14->pNextListItem;
      v14->pNextListItem = 0i64;
      v15 = v6->m_listSwitchSubscribers.m_pLast;
      ++v6->m_listSwitchSubscribers.m_ulNumListItems;
      v15->Item.pSwitch = v5;
      v13 = (signed __int64)&v15->Item;
      *(_QWORD *)(v13 + 8) = v16;
      goto LABEL_16;
    }
  }
  v13 = 0i64;
LABEL_16:
  v12 = v13 != 0;
  return 2 - (unsigned int)v12;
}

// File Line: 1117
// RVA: 0xA58430
void __fastcall CAkRTPCMgr::UnSubscribeRTPC(CAkRTPCMgr *this, void *in_pSubscriber, unsigned int in_ParamID, unsigned int in_RTPCCurveID, bool *out_bMoreCurvesRemaining)
{
  void *v5; // r14
  unsigned int v6; // ebp
  CAkRTPCMgr *v7; // r12
  __int64 v8; // rdi
  __int64 v9; // r13
  CAkRTPCMgr::AkRTPCSubscription *v10; // rbx
  CAkRTPCMgr::RTPCCurve *v11; // rdi
  signed __int64 v12; // rax
  CAkRTPCMgr::AkRTPCEntry *v13; // rcx
  AkRTPCGraphPointBase<float> *v14; // rdx
  unsigned __int64 v15; // rdx
  signed __int64 v16; // rdx
  __int64 v17; // rcx
  __int64 v18; // rax
  __int64 v19; // rax
  CAkRTPCMgr::RTPCCurve *v20; // rdx
  int v21; // edi

  v5 = in_pSubscriber;
  v6 = in_ParamID;
  v7 = this;
  v8 = ((unsigned int)in_pSubscriber + in_ParamID) % 0xC1;
  v9 = (unsigned int)v8;
  v10 = this->m_RTPCSubscribers.m_table[v8];
  if ( !v10 )
    goto LABEL_5;
  while ( v10->key.pSubscriber != in_pSubscriber || v10->key.ParamID != in_ParamID )
  {
    v10 = v10->pNextItem;
    if ( !v10 )
      goto LABEL_5;
  }
  if ( v10 )
  {
    if ( out_bMoreCurvesRemaining )
      *out_bMoreCurvesRemaining = v10->Curves.m_uLength != 0;
    v11 = v10->Curves.m_pItems;
    v12 = (signed __int64)&v11[v10->Curves.m_uLength];
    if ( v11 != (CAkRTPCMgr::RTPCCurve *)v12 )
    {
      while ( v11->RTPCCurveID != in_RTPCCurveID )
      {
        ++v11;
        if ( v11 == (CAkRTPCMgr::RTPCCurve *)v12 )
          return;
      }
      v13 = this->m_RTPCEntries.m_table[v11->RTPC_ID % 0xC1];
      if ( v13 )
      {
        while ( v13->key != v11->RTPC_ID )
        {
          v13 = v13->pNextItem;
          if ( !v13 )
            goto LABEL_20;
        }
        if ( v13 )
          AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::Unset<CAkRTPCMgr::AkRTPCSubscription *>(
            &v13->subscriptions,
            v10);
      }
LABEL_20:
      v14 = v11->ConversionTable.m_pArrayGraphPoints;
      if ( v14 )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v14);
        v11->ConversionTable.m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&v11->ConversionTable.m_ulArraySize = 0i64;
      v15 = (unsigned __int64)v10->Curves.m_pItems + 8 * (3i64 * v10->Curves.m_uLength - 3);
      if ( (unsigned __int64)v11 < v15 )
        qmemcpy(
          v11,
          &v11[1],
          24
        * (((unsigned __int64)((v15 - (unsigned __int64)v11 - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 4)
         + 1));
      if ( !--v10->Curves.m_uLength )
      {
        if ( out_bMoreCurvesRemaining )
          *out_bMoreCurvesRemaining = 0;
        v16 = (signed __int64)v7 + 8 * v9;
        v17 = 0i64;
        v18 = *(_QWORD *)(v16 + 3112);
        if ( v18 )
        {
          while ( *(void **)v18 != v5 || *(_DWORD *)(v18 + 8) != v6 )
          {
            v17 = v18;
            v18 = *(_QWORD *)(v18 + 16);
            if ( !v18 )
              goto LABEL_36;
          }
          v19 = *(_QWORD *)(v18 + 16);
          if ( v17 )
            *(_QWORD *)(v17 + 16) = v19;
          else
            *(_QWORD *)(v16 + 3112) = v19;
          --v7->m_RTPCSubscribers.m_uiSize;
        }
LABEL_36:
        v20 = v10->Curves.m_pItems;
        v21 = g_DefaultPoolId;
        if ( v20 )
        {
          v10->Curves.m_uLength = 0;
          AK::MemoryMgr::Free(g_DefaultPoolId, v20);
          v10->Curves.m_pItems = 0i64;
          v10->Curves.m_ulReserved = 0;
        }
        AK::MemoryMgr::Free(v21, v10);
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
  void *v3; // r10
  CAkRTPCMgr *v4; // r11
  __int64 v5; // r9
  CAkRTPCMgr::AkRTPCSubscription *v6; // rbx
  CAkRTPCMgr::AkRTPCEntry **v7; // rdx
  CAkRTPCMgr::AkRTPCEntry *v8; // rcx
  CAkRTPCMgr::AkRTPCEntry *v9; // rax
  CAkRTPCMgr::AkRTPCEntry *v10; // rax
  CAkRTPCMgr::RTPCCurve *v11; // rdx
  int v12; // edi

  v3 = in_pSubscriber;
  v4 = this;
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
    if ( v6 )
    {
      v7 = &this->m_RTPCEntries.m_table[v5];
      v8 = 0i64;
      v9 = v7[389];
      if ( v9 )
      {
        while ( *(void **)&v9->key != v3 || LODWORD(v9->pNextItem) != in_ParamID )
        {
          v8 = v9;
          v9 = *(CAkRTPCMgr::AkRTPCEntry **)&v9->fDefaultValue;
          if ( !v9 )
            goto LABEL_16;
        }
        v10 = *(CAkRTPCMgr::AkRTPCEntry **)&v9->fDefaultValue;
        if ( v8 )
          *(_QWORD *)&v8->fDefaultValue = v10;
        else
          v7[389] = v10;
        --v4->m_RTPCSubscribers.m_uiSize;
      }
LABEL_16:
      CAkRTPCMgr::RemoveReferencesToSubscription(v4, v6);
      v11 = v6->Curves.m_pItems;
      v12 = g_DefaultPoolId;
      if ( v11 )
      {
        v6->Curves.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v11);
        v6->Curves.m_pItems = 0i64;
        v6->Curves.m_ulReserved = 0;
      }
      AK::MemoryMgr::Free(v12, v6);
    }
  }
}

// File Line: 1177
// RVA: 0xA581C0
void __fastcall CAkRTPCMgr::UnSubscribeRTPC(CAkRTPCMgr *this, void *in_pSubscriber)
{
  AkHashListBare<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription,193,AkDefaultHashListBarePolicy<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription> > *v2; // r15
  __int64 v3; // r8
  CAkRTPCMgr::AkRTPCSubscription *v4; // rdi
  CAkRTPCMgr::AkRTPCSubscription *v5; // rbx
  void *v6; // r12
  CAkRTPCMgr *v7; // r13
  CAkRTPCMgr::AkRTPCSubscription *v8; // rbp
  CAkRTPCMgr::AkRTPCSubscription *v9; // r9
  __int64 v10; // rcx
  CAkRTPCMgr::AkRTPCSubscription *v11; // rdx
  CAkRTPCMgr::RTPCCurve *v12; // rdx
  int v13; // er14
  int v14; // [rsp+28h] [rbp-60h]

  v2 = &this->m_RTPCSubscribers;
  LODWORD(v3) = 0;
  v4 = 0i64;
  v5 = this->m_RTPCSubscribers.m_table[0];
  v6 = in_pSubscriber;
  v7 = this;
  if ( v5 )
  {
    while ( 1 )
    {
LABEL_6:
      while ( 1 )
      {
        v8 = v5;
        if ( v5->key.pSubscriber != v6 )
          break;
        v9 = v5->pNextItem;
        LODWORD(v10) = v3;
        v11 = v4;
        v14 = v3;
        v5 = v9;
        if ( !v9 )
        {
          do
          {
            v10 = (unsigned int)(v10 + 1);
            if ( (unsigned int)v10 >= 0xC1 )
              break;
            v5 = v2->m_table[v10];
            v11 = 0i64;
          }
          while ( !v5 );
          v14 = v10;
        }
        if ( v4 )
          v4->pNextItem = v9;
        else
          v2->m_table[(unsigned int)v3] = v9;
        --v2->m_uiSize;
        v4 = v11;
        CAkRTPCMgr::RemoveReferencesToSubscription(v7, v8);
        v12 = v8->Curves.m_pItems;
        v13 = g_DefaultPoolId;
        if ( v12 )
        {
          v8->Curves.m_uLength = 0;
          AK::MemoryMgr::Free(g_DefaultPoolId, v12);
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
          v5 = v2->m_table[v3];
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
    v5 = v2->m_table[v3];
    if ( v5 )
      goto LABEL_6;
  }
  if ( v5 )
    goto LABEL_6;
}

// File Line: 1197
// RVA: 0xA58650
void __fastcall CAkRTPCMgr::UnSubscribeSwitch(CAkRTPCMgr *this, CAkSwitchAware *in_pSwitch)
{
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v2; // rax
  CAkSwitchAware *v3; // r9
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v4; // rdx
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v5; // r8
  CAkList2<CAkRTPCMgr::AkRTPCSwitchAssociation,CAkRTPCMgr::AkRTPCSwitchAssociation const &,2,ArrayPoolDefault>::ListItem *i; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v7; // rdx
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v8; // r8
  bool v9; // zf
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::ListItem *v10; // rax
  CAkList2<CAkSwitchAware *,CAkSwitchAware *,2,ArrayPoolDefault>::ListItem *v11; // rcx

  v2 = this->m_listSwitchSubscribers.m_pFirst;
  v3 = in_pSwitch;
  v4 = 0i64;
  v5 = v2;
  if ( v2 )
  {
    while ( v5->Item.pSwitch != v3 )
    {
      v4 = v5;
      v5 = v5->pNextListItem;
      if ( !v5 )
        goto LABEL_4;
    }
    v9 = v5 == v2;
    v10 = v5->pNextListItem;
    if ( v9 )
      this->m_listSwitchSubscribers.m_pFirst = v10;
    else
      v4->pNextListItem = v10;
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
        while ( v7->Item != v3 )
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
  AkHashListBare<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription,193,AkDefaultHashListBarePolicy<AkRTPCSubscriptionKey,CAkRTPCMgr::AkRTPCSubscription> > *v3; // r13
  CAkRegisteredObj *v4; // r10
  CAkRTPCMgr *v5; // r15
  CAkRTPCMgr::AkRTPCSubscription *v6; // rdi
  __int64 v7; // r8
  CAkRTPCMgr::AkRTPCSubscription *v8; // rsi
  CAkRTPCMgr::AkRTPCSubscription *v9; // rbp
  CAkRTPCMgr::AkRTPCSubscription *v10; // r9
  __int64 v11; // rcx
  CAkRTPCMgr::AkRTPCSubscription *v12; // rdx
  CAkRTPCMgr::RTPCCurve *v13; // rdx
  int v14; // er12
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
  CAkRegisteredObj *v25; // [rsp+98h] [rbp+10h]

  if ( in_GameObj )
  {
    v25 = in_GameObj;
    LODWORD(v2) = 0;
    v3 = &this->m_RTPCSubscribers;
    v4 = in_GameObj;
    v5 = this;
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
      v6 = v3->m_table[v7];
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
            v10 = v6->pNextItem;
            LODWORD(v11) = v7;
            v12 = v8;
            v23 = v7;
            v6 = v10;
            if ( !v10 )
            {
              do
              {
                v11 = (unsigned int)(v11 + 1);
                if ( (unsigned int)v11 >= 0xC1 )
                  break;
                v6 = v3->m_table[v11];
                v12 = 0i64;
              }
              while ( !v6 );
              v23 = v11;
            }
            if ( v8 )
              v8->pNextItem = v10;
            else
              v3->m_table[(unsigned int)v7] = v10;
            --v3->m_uiSize;
            v8 = v12;
            CAkRTPCMgr::RemoveReferencesToSubscription(v5, v9);
            v13 = v9->Curves.m_pItems;
            v14 = g_DefaultPoolId;
            if ( v13 )
            {
              v9->Curves.m_uLength = 0;
              AK::MemoryMgr::Free(g_DefaultPoolId, v13);
              v9->Curves.m_pItems = 0i64;
              v9->Curves.m_ulReserved = 0;
            }
            AK::MemoryMgr::Free(v14, v9);
            LODWORD(v7) = v23;
            v4 = v25;
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
              v6 = v3->m_table[v7];
              v8 = 0i64;
              if ( v6 )
                goto LABEL_7;
            }
          }
        }
      }
    }
    if ( v6 )
      goto LABEL_7;
LABEL_19:
    v15 = v5->m_SwitchEntries.m_table[0];
    LODWORD(v16) = 0;
    v17 = 0i64;
    if ( v15 )
      goto LABEL_28;
    while ( 1 )
    {
      v16 = (unsigned int)(v16 + 1);
      if ( (unsigned int)v16 >= 0xC1 )
        break;
      v15 = v5->m_SwitchEntries.m_table[v16];
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
                v20 = v5->m_SwitchEntries.m_table[v19];
                v21 = 0i64;
              }
              while ( !v20 );
              v24 = v19;
            }
            if ( v17 )
              v17->pNextItem = v18;
            else
              v5->m_SwitchEntries.m_table[(unsigned int)v16] = v18;
            AK::MemoryMgr::Free(v5->m_SwitchEntries.m_MemPoolId, v15);
            --v5->m_SwitchEntries.m_uiSize;
            v4 = v25;
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
              v15 = v5->m_SwitchEntries.m_table[v16];
              v17 = 0i64;
              if ( v15 )
                goto LABEL_28;
            }
          }
        }
      }
    }
    if ( v15 )
      goto LABEL_28;
LABEL_38:
    v22 = v5->m_RTPCEntries.m_table[0];
    if ( v5->m_RTPCEntries.m_table[0] )
      goto LABEL_54;
    while ( 1 )
    {
      v2 = (unsigned int)(v2 + 1);
      if ( (unsigned int)v2 >= 0xC1 )
        break;
      v22 = v5->m_RTPCEntries.m_table[v2];
      if ( v22 )
        goto LABEL_47;
    }
    if ( v22 )
    {
LABEL_54:
      do
      {
        do
        {
LABEL_47:
          CAkRTPCMgr::AkRTPCEntry::RemoveGameObject(v22, v4);
          v22 = v22->pNextItem;
          v4 = v25;
        }
        while ( v22 );
        while ( 1 )
        {
          v2 = (unsigned int)(v2 + 1);
          if ( (unsigned int)v2 >= 0xC1 )
            break;
          v22 = v5->m_RTPCEntries.m_table[v2];
          if ( v22 )
          {
            v4 = v25;
            goto LABEL_47;
          }
        }
        v4 = v25;
      }
      while ( v22 );
    }
  }
}

// File Line: 1282
// RVA: 0xA58A30
signed __int64 __fastcall CAkRTPCMgr::UpdateRTPCSubscriberInfo(CAkRTPCMgr *this, void *in_pSubscriber)
{
  CAkRTPCMgr::AkRTPCSubscription *v2; // rdi
  __int64 v3; // rbx
  void *v4; // rsi
  CAkRTPCMgr *i; // rbp

  v2 = this->m_RTPCSubscribers.m_table[0];
  LODWORD(v3) = 0;
  v4 = in_pSubscriber;
  for ( i = this; !v2; v2 = this->m_RTPCSubscribers.m_table[v3] )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= 0xC1 )
      goto LABEL_10;
  }
  do
  {
    do
    {
LABEL_4:
      if ( v2->key.pSubscriber == v4 )
        CAkRTPCMgr::UpdateSubscription(i, v2);
      v2 = v2->pNextItem;
    }
    while ( v2 );
    while ( 1 )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (unsigned int)v3 >= 0xC1 )
        break;
      v2 = i->m_RTPCSubscribers.m_table[v3];
      if ( v2 )
        goto LABEL_4;
    }
LABEL_10:
    ;
  }
  while ( v2 );
  return 1i64;
}

// File Line: 1302
// RVA: 0xA58AD0
void __fastcall CAkRTPCMgr::UpdateSubscription(CAkRTPCMgr *this, CAkRTPCMgr::AkRTPCSubscription *in_rSubscription)
{
  CAkRTPCMgr::AkRTPCSubscription *v2; // rbx
  CAkRTPCMgr::SubscriberType v3; // edx
  float v4; // xmm0_4
  void *v5; // rcx
  __int64 v6; // rdx
  float v7; // xmm0_4
  __int16 v8; // dx
  CAkPBI *v9; // rcx
  float in_pParam; // [rsp+38h] [rbp+10h]

  v2 = in_rSubscription;
  v3 = in_rSubscription->eType;
  if ( (unsigned int)(v3 - 1) <= 1 )
  {
    (*(void (**)(void))(*(_QWORD *)v2->key.pSubscriber + 408i64))();
  }
  else if ( v3 )
  {
    if ( v3 == 4 )
    {
      v7 = CAkRTPCMgr::GetRTPCConvertedValue(this, v2, v2->TargetGameObject, 0);
      v8 = v2->key.ParamID;
      v9 = (CAkPBI *)v2->key.pSubscriber;
      in_pParam = v7;
      CAkPBI::SetParam(v9, v8, &in_pParam, 4u);
    }
    else
    {
      CAkLayer::RecalcNotification((CAkLayer *)v2->key.pSubscriber);
    }
  }
  else
  {
    v4 = CAkRTPCMgr::GetRTPCConvertedValue(this, v2, v2->TargetGameObject, 0);
    v5 = v2->key.pSubscriber;
    v6 = LOWORD(v2->key.ParamID);
    in_pParam = v4;
    (*(void (__fastcall **)(void *, __int64, float *, signed __int64))(*(_QWORD *)v5 + 8i64))(v5, v6, &in_pParam, 4i64);
  }
}

// File Line: 1388
// RVA: 0xA55C10
CAkRTPCMgr::AkRTPCEntry *__fastcall CAkRTPCMgr::GetRTPCEntry(CAkRTPCMgr *this, unsigned int in_RTPCid)
{
  unsigned int v2; // ebx
  CAkRTPCMgr *v3; // rdi
  CAkRTPCMgr::AkRTPCEntry *result; // rax
  __int64 v5; // rcx

  v2 = in_RTPCid;
  v3 = this;
  result = this->m_RTPCEntries.m_table[in_RTPCid % 0xC1];
  if ( !result )
    goto LABEL_6;
  while ( result->key != in_RTPCid )
  {
    result = result->pNextItem;
    if ( !result )
      goto LABEL_6;
  }
  if ( !result )
  {
LABEL_6:
    result = (CAkRTPCMgr::AkRTPCEntry *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
    if ( result )
    {
      result->key = v2;
      result->fDefaultValue = 0.0;
      result->values.m_pItems = 0i64;
      *(_QWORD *)&result->values.m_uLength = 0i64;
      result->transitions.m_pFirst = 0i64;
      result->subscriptions.m_pItems = 0i64;
      *(_QWORD *)&result->subscriptions.m_uLength = 0i64;
      v5 = result->key % 0xC1;
      result->pNextItem = v3->m_RTPCEntries.m_table[v5];
      v3->m_RTPCEntries.m_table[v5] = result;
      ++v3->m_RTPCEntries.m_uiSize;
    }
  }
  return result;
}

// File Line: 1403
// RVA: 0xA573F0
void __fastcall CAkRTPCMgr::SetDefaultParamValue(CAkRTPCMgr *this, unsigned int in_RTPCid, float in_fValue)
{
  CAkRTPCMgr::AkRTPCEntry *v3; // rax

  v3 = CAkRTPCMgr::GetRTPCEntry(this, in_RTPCid);
  if ( v3 )
    v3->fDefaultValue = in_fValue;
}

// File Line: 1410
// RVA: 0xA557B0
float __fastcall CAkRTPCMgr::GetDefaultValue(CAkRTPCMgr *this, unsigned int in_RTPCid, bool *out_pbWasFound)
{
  CAkRTPCMgr::AkRTPCEntry *v3; // r9
  float result; // xmm0_4

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
    result = v3->fDefaultValue;
  else
    result = 0.0;
  return result;
}

// File Line: 1420
// RVA: 0xA57180
void __fastcall CAkRTPCMgr::ResetRTPCValue(CAkRTPCMgr *this, unsigned int in_RTPCid, CAkRegisteredObj *in_GameObj, TransParams *in_transParams)
{
  TransParams *v4; // r14
  CAkRegisteredObj *v5; // rbp
  CAkRTPCMgr::AkRTPCEntry *v6; // rbx
  CAkRTPCMgr::AkRTPCValue *v7; // rax
  CAkRTPCMgr::AkRTPCValue *v8; // rdi
  float v9; // xmm2_4

  v4 = in_transParams;
  v5 = in_GameObj;
  v6 = this->m_RTPCEntries.m_table[in_RTPCid % 0xC1];
  if ( v6 )
  {
    while ( v6->key != in_RTPCid )
    {
      v6 = v6->pNextItem;
      if ( !v6 )
        return;
    }
    if ( v6 )
    {
      v7 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
             &v6->values,
             0i64);
      v8 = v7;
      if ( v5 )
      {
        v7 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
               &v6->values,
               v5);
        if ( !v7 )
          return;
        if ( v8 )
        {
          v9 = v8->fValue;
LABEL_12:
          CAkRTPCMgr::AkRTPCEntry::SetRTPC(v6, v7, v9, v5, v4, 1);
          return;
        }
      }
      else if ( !v7 )
      {
        return;
      }
      v9 = v6->fDefaultValue;
      goto LABEL_12;
    }
  }
}

