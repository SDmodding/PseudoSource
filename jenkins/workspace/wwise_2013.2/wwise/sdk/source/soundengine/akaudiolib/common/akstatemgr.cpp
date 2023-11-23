// File Line: 35
// RVA: 0xA472E0
void __fastcall AkStateGroupInfo::Term(AkStateGroupInfo *this)
{
  MapStruct<AkStateTransition,long> *m_pItems; // rdx

  m_pItems = this->mapTransitions.m_pItems;
  if ( m_pItems )
  {
    this->mapTransitions.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->mapTransitions.m_pItems = 0i64;
    this->mapTransitions.m_ulReserved = 0;
    this->members.m_pFirst = 0i64;
  }
  else
  {
    this->members.m_pFirst = 0i64;
  }
}

// File Line: 41
// RVA: 0xA46740
__int64 __fastcall CAkStateMgr::PreparationStateItem::Notify(
        CAkStateMgr::PreparationStateItem *this,
        unsigned int in_GameSyncID,
        bool in_bIsActive)
{
  CAkPreparationAware *m_pFirst; // rbx
  __int64 result; // rax
  unsigned int v8; // esi
  CAkPreparationAware *v9; // rdi

  m_pFirst = this->m_PreparationList.m_pFirst;
  if ( !m_pFirst )
    return 1i64;
  while ( 1 )
  {
    result = m_pFirst->vfptr->ModifyActiveState(m_pFirst, in_GameSyncID, in_bIsActive);
    v8 = result;
    if ( (_DWORD)result != 1 )
      break;
    m_pFirst = m_pFirst->pNextItemPrepare;
    if ( !m_pFirst )
      return result;
  }
  if ( in_bIsActive )
  {
    v9 = this->m_PreparationList.m_pFirst;
    if ( m_pFirst != v9 )
    {
      do
      {
        v9->vfptr->ModifyActiveState(v9, in_GameSyncID, 0);
        v9 = v9->pNextItemPrepare;
      }
      while ( m_pFirst != v9 );
      return v8;
    }
  }
  return result;
}

// File Line: 67
// RVA: 0xA46200
void __fastcall CAkStateMgr::CAkStateMgr(CAkStateMgr *this)
{
  CAkLock *p_m_PrepareGameSyncLock; // rcx

  p_m_PrepareGameSyncLock = &this->m_PrepareGameSyncLock;
  *(_QWORD *)&p_m_PrepareGameSyncLock[-3].m_csLock.LockCount = 0i64;
  p_m_PrepareGameSyncLock[-3].m_csLock.OwningThread = 0i64;
  *(_QWORD *)&p_m_PrepareGameSyncLock[-2].m_csLock.LockCount = 0i64;
  LODWORD(p_m_PrepareGameSyncLock[-2].m_csLock.OwningThread) = 0;
  p_m_PrepareGameSyncLock[-1].m_csLock.OwningThread = 0i64;
  LODWORD(p_m_PrepareGameSyncLock[-1].m_csLock.LockSemaphore) = 0;
  InitializeCriticalSection(&p_m_PrepareGameSyncLock->m_csLock);
  this->m_PreparationGroupsStates.m_pFirst = 0i64;
  this->m_PreparationGroupsStates.m_pLast = 0i64;
  this->m_PreparationGroupsSwitches.m_pFirst = 0i64;
  this->m_PreparationGroupsSwitches.m_pLast = 0i64;
}

// File Line: 71
// RVA: 0xA46260
void __fastcall CAkStateMgr::~CAkStateMgr(CAkStateMgr *this)
{
  DeleteCriticalSection(&this->m_PrepareGameSyncLock.m_csLock);
}

// File Line: 75
// RVA: 0xA46640
__int64 __fastcall CAkStateMgr::Init(CAkStateMgr *this)
{
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v2; // rax
  unsigned int v3; // edi
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v4; // rcx
  __int64 result; // rax
  unsigned int v6; // edx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v7; // rax
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v8; // rax
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v9; // rcx
  unsigned int v10; // edx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v11; // rax

  this->m_listRegisteredSwitch.m_ulMaxNumListItems = -1;
  this->m_listRegisteredSwitch.m_ulNumListItems = 0;
  this->m_listRegisteredSwitch.m_pFree = 0i64;
  v2 = (CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC0ui64);
  v3 = 52;
  v4 = v2;
  this->m_listRegisteredSwitch.m_pvMemStart = v2;
  if ( v2 )
  {
    this->m_listRegisteredSwitch.m_ulMinNumListItems = 8;
    this->m_listRegisteredSwitch.m_pFree = v2;
    v6 = 0;
    do
    {
      v7 = v4 + 1;
      ++v6;
      v4->pNextListItem = v4 + 1;
      ++v4;
    }
    while ( v6 < this->m_listRegisteredSwitch.m_ulMinNumListItems );
    v7[-1].pNextListItem = 0i64;
    result = 1i64;
  }
  else
  {
    result = 52i64;
  }
  this->m_listRegisteredSwitch.m_pFirst = 0i64;
  this->m_listRegisteredSwitch.m_pLast = 0i64;
  if ( (_DWORD)result == 1 )
  {
    this->m_listRegisteredTrigger.m_ulNumListItems = 0;
    this->m_listRegisteredTrigger.m_ulMaxNumListItems = -1;
    this->m_listRegisteredTrigger.m_pFree = 0i64;
    v8 = (CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x100ui64);
    v9 = v8;
    this->m_listRegisteredTrigger.m_pvMemStart = v8;
    if ( v8 )
    {
      this->m_listRegisteredTrigger.m_ulMinNumListItems = 8;
      this->m_listRegisteredTrigger.m_pFree = v8;
      v10 = 0;
      do
      {
        v11 = v9 + 1;
        ++v10;
        v9->pNextListItem = v9 + 1;
        ++v9;
      }
      while ( v10 < this->m_listRegisteredTrigger.m_ulMinNumListItems );
      v11[-1].pNextListItem = 0i64;
      v3 = 1;
    }
    this->m_listRegisteredTrigger.m_pFirst = 0i64;
    this->m_listRegisteredTrigger.m_pLast = 0i64;
    return v3;
  }
  return result;
}

// File Line: 87
// RVA: 0xA47330
void __fastcall CAkStateMgr::Term(CAkStateMgr *this)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *i; // rbx
  AkStateGroupInfo *item; // rsi
  MapStruct<AkStateTransition,long> *m_pItems; // rdx
  unsigned int m_uLength; // eax
  MapStruct<unsigned long,AkStateGroupInfo *> *v6; // rcx
  MapStruct<unsigned long,AkStateGroupInfo *> *v7; // rdx

  for ( i = this->m_StateGroups.m_pItems;
        i != &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
        --this->m_StateGroups.m_uLength )
  {
    item = i->item;
    m_pItems = item->mapTransitions.m_pItems;
    if ( m_pItems )
    {
      item->mapTransitions.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
      item->mapTransitions.m_pItems = 0i64;
      item->mapTransitions.m_ulReserved = 0;
    }
    item->members.m_pFirst = 0i64;
    AK::MemoryMgr::Free(g_DefaultPoolId, item);
    m_uLength = this->m_StateGroups.m_uLength;
    if ( m_uLength > 1 )
    {
      v6 = &this->m_StateGroups.m_pItems[m_uLength];
      *(_QWORD *)&i->key = *(_QWORD *)&v6[-1].key;
      i->item = v6[-1].item;
    }
  }
  v7 = this->m_StateGroups.m_pItems;
  if ( this->m_StateGroups.m_pItems )
  {
    this->m_StateGroups.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v7);
    this->m_StateGroups.m_pItems = 0i64;
    this->m_StateGroups.m_ulReserved = 0;
  }
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::Term(&this->m_listRegisteredSwitch);
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::Term(&this->m_listRegisteredTrigger);
  CAkStateMgr::TermPreparationGroup(this, &this->m_PreparationGroupsStates);
  CAkStateMgr::TermPreparationGroup(this, &this->m_PreparationGroupsSwitches);
}

// File Line: 99
// RVA: 0xA47430
void __fastcall CAkStateMgr::TermPreparationGroup(
        CAkStateMgr *this,
        AkListBare<CAkStateMgr::PreparationStateItem,AkListBareNextItem<CAkStateMgr::PreparationStateItem>,AkCountPolicyNoCount> *in_rGroup)
{
  CAkStateMgr::PreparationStateItem *m_pFirst; // rbx
  CAkStateMgr::PreparationStateItem *v4; // rax
  CAkStateMgr::PreparationStateItem *pNextItem; // rsi
  int v6; // ebp
  unsigned int *m_pItems; // rdx
  CAkStateMgr::PreparationStateItem *v8; // [rsp+20h] [rbp-28h]
  CAkStateMgr::PreparationStateItem *v9; // [rsp+28h] [rbp-20h]

  m_pFirst = in_rGroup->m_pFirst;
  v4 = 0i64;
  if ( in_rGroup->m_pFirst )
  {
    while ( 1 )
    {
      pNextItem = m_pFirst->pNextItem;
      v9 = v4;
      v8 = m_pFirst->pNextItem;
      if ( m_pFirst == in_rGroup->m_pFirst )
        in_rGroup->m_pFirst = pNextItem;
      else
        v4->pNextItem = pNextItem;
      if ( m_pFirst == in_rGroup->m_pLast )
        in_rGroup->m_pLast = v4;
      v6 = g_DefaultPoolId;
      m_pFirst->m_PreparationList.m_pFirst = 0i64;
      m_pFirst->m_PreparationList.m_pLast = 0i64;
      m_pItems = m_pFirst->m_PreparedContent.m_PreparableContentList.m_pItems;
      if ( m_pItems )
      {
        m_pFirst->m_PreparedContent.m_PreparableContentList.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
        m_pFirst->m_PreparedContent.m_PreparableContentList.m_pItems = 0i64;
        m_pFirst->m_PreparedContent.m_PreparableContentList.m_ulReserved = 0;
      }
      AK::MemoryMgr::Free(v6, m_pFirst);
      if ( !pNextItem )
        break;
      v4 = v9;
      m_pFirst = v8;
    }
    in_rGroup->m_pFirst = 0i64;
    in_rGroup->m_pLast = 0i64;
  }
  else
  {
    in_rGroup->m_pFirst = 0i64;
    in_rGroup->m_pLast = 0i64;
  }
}

// File Line: 111
// RVA: 0xA46320
__int64 __fastcall CAkStateMgr::AddStateGroup(CAkStateMgr *this, unsigned int in_ulStateGroupID)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *m_pItems; // rax
  unsigned int v5; // edi
  MapStruct<unsigned long,AkStateGroupInfo *> *v6; // r8
  CAkSplitterBus *v8; // rbx

  m_pItems = this->m_StateGroups.m_pItems;
  v5 = 1;
  v6 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( this->m_StateGroups.m_pItems != v6 )
  {
    do
    {
      if ( m_pItems->key == in_ulStateGroupID )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v6 );
    if ( m_pItems != v6 && m_pItems != (MapStruct<unsigned long,AkStateGroupInfo *> *)-8i64 )
      return 1i64;
  }
  v8 = (CAkSplitterBus *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
  if ( !v8 )
    return 2i64;
  v8->m_aBusses.m_pItems = 0i64;
  *(_QWORD *)&v8->m_aBusses.m_uLength = 0i64;
  *(_QWORD *)&v8->m_iMaxPlayers = 0i64;
  v8[1].m_aBusses.m_pItems = 0i64;
  if ( !CAkKeyArray<unsigned long,AkStateGroupInfo *,4>::Set(
          (CAkKeyArray<unsigned long,CAkSplitterBus *,4> *)this,
          in_ulStateGroupID,
          v8) )
  {
    v5 = 2;
    AkStateGroupInfo::Term((AkStateGroupInfo *)v8);
    AK::MemoryMgr::Free(g_DefaultPoolId, v8);
  }
  return v5;
}

// File Line: 141
// RVA: 0xA46400
__int64 __fastcall CAkStateMgr::AddStateGroupMember(
        CAkStateMgr *this,
        unsigned int in_ulStateGroupID,
        AkStateGroupChunk *in_pMember)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *m_pItems; // rax
  MapStruct<unsigned long,AkStateGroupInfo *> *v4; // rcx
  AkStateGroupInfo **p_item; // rax
  AkStateGroupInfo *v6; // rax
  AkStateGroupChunk *m_pFirst; // rcx

  m_pItems = this->m_StateGroups.m_pItems;
  v4 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( m_pItems == v4 )
    return 20i64;
  do
  {
    if ( m_pItems->key == in_ulStateGroupID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v4 );
  if ( m_pItems == v4 )
    return 20i64;
  p_item = &m_pItems->item;
  if ( !p_item )
    return 20i64;
  v6 = *p_item;
  m_pFirst = v6->members.m_pFirst;
  if ( m_pFirst )
  {
    in_pMember->m_pNextInGroup = m_pFirst;
    v6->members.m_pFirst = in_pMember;
  }
  else
  {
    v6->members.m_pFirst = in_pMember;
    in_pMember->m_pNextInGroup = 0i64;
  }
  return 1i64;
}

// File Line: 156
// RVA: 0xA47180
__int64 __fastcall CAkStateMgr::SetdefaultTransitionTime(
        CAkStateMgr *this,
        unsigned int in_ulStateGroupID,
        int lTransitionTime)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *m_pItems; // rax
  MapStruct<unsigned long,AkStateGroupInfo *> *v4; // rcx
  AkStateGroupInfo **p_item; // rax

  m_pItems = this->m_StateGroups.m_pItems;
  v4 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( m_pItems == v4 )
    return 20i64;
  do
  {
    if ( m_pItems->key == in_ulStateGroupID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v4 );
  if ( m_pItems == v4 )
    return 20i64;
  p_item = &m_pItems->item;
  if ( !p_item )
    return 20i64;
  (*p_item)->lDefaultTransitionTime = lTransitionTime;
  return 1i64;
}

// File Line: 198
// RVA: 0xA46C30
__int64 __fastcall CAkStateMgr::RemoveStateGroupMember(
        CAkStateMgr *this,
        unsigned int in_ulStateGroupID,
        AkStateGroupChunk *in_pMember)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *m_pItems; // rax
  MapStruct<unsigned long,AkStateGroupInfo *> *v5; // rcx
  AkStateGroupInfo *item; // r8
  AkStateGroupChunk *v7; // rdx
  AkStateGroupChunk *m_pFirst; // rcx
  AkStateGroupChunk *v9; // rax
  bool v11; // zf
  AkStateGroupChunk *m_pNextInGroup; // rcx

  m_pItems = this->m_StateGroups.m_pItems;
  v5 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( m_pItems == v5 )
    return 20i64;
  do
  {
    if ( m_pItems->key == in_ulStateGroupID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v5 );
  if ( m_pItems == v5 || m_pItems == (MapStruct<unsigned long,AkStateGroupInfo *> *)-8i64 )
    return 20i64;
  item = m_pItems->item;
  v7 = 0i64;
  m_pFirst = item->members.m_pFirst;
  v9 = m_pFirst;
  if ( m_pFirst )
  {
    while ( v9 != in_pMember )
    {
      v7 = v9;
      v9 = v9->m_pNextInGroup;
      if ( !v9 )
        return 1i64;
    }
    if ( v9 )
    {
      v11 = v9 == m_pFirst;
      m_pNextInGroup = v9->m_pNextInGroup;
      if ( v11 )
      {
        item->members.m_pFirst = m_pNextInGroup;
        return 1i64;
      }
      v7->m_pNextInGroup = m_pNextInGroup;
    }
  }
  return 1i64;
}

// File Line: 214
// RVA: 0xA46460
__int64 __fastcall CAkStateMgr::AddStateTransition(
        CAkStateMgr *this,
        unsigned int in_ulStateGroupID,
        unsigned int in_ulStateID1,
        unsigned int in_ulStateID2,
        int lTransitionTime,
        bool in_bIsShared)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *m_pItems; // rax
  MapStruct<unsigned long,AkStateGroupInfo *> *i; // rcx
  CAkKeyArray<AkStateTransition,long,5> **p_item; // rbx

  m_pItems = this->m_StateGroups.m_pItems;
  for ( i = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength]; m_pItems != i; ++m_pItems )
  {
    if ( m_pItems->key == in_ulStateGroupID )
      break;
  }
  if ( m_pItems == i )
    return 20i64;
  p_item = (CAkKeyArray<AkStateTransition,long,5> **)&m_pItems->item;
  if ( m_pItems == (MapStruct<unsigned long,AkStateGroupInfo *> *)-8i64 )
    return 20i64;
  if ( CAkKeyArray<AkStateTransition,long,5>::Set(
         *p_item + 1,
         (AkStateTransition)__PAIR64__(in_ulStateID2, in_ulStateID1),
         lTransitionTime)
    && (!in_bIsShared
     || CAkKeyArray<AkStateTransition,long,5>::Set(
          *p_item + 1,
          (AkStateTransition)__PAIR64__(in_ulStateID1, in_ulStateID2),
          lTransitionTime)) )
  {
    return 1i64;
  }
  return 2i64;
}

// File Line: 284
// RVA: 0xA46DF0
void __fastcall CAkStateMgr::SetStateInternal(
        CAkStateMgr *this,
        unsigned int in_ulStateGroupID,
        unsigned int in_ulStateID,
        bool in_bSkipTransitionTime,
        bool in_bSkipExtension)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *m_pItems; // rax
  unsigned int v7; // ebp
  MapStruct<unsigned long,AkStateGroupInfo *> *v9; // r10
  __int64 *p_item; // rax
  __int64 v11; // r14
  int in_NewDuration; // esi
  _DWORD *v13; // rax
  _DWORD *v14; // rcx
  int *v15; // rax
  AkStateGroupChunk *v16; // rbx
  CAkState *State; // rax
  __int64 *p_m_props; // r13
  unsigned __int8 v19; // bp
  const bool *v20; // r15
  char *m_pProps; // r8
  unsigned int v22; // r9d
  int v23; // ecx
  __int64 v24; // rdx
  AkStateValue *v25; // rdi
  unsigned __int8 *v26; // r8
  unsigned int v27; // r9d
  __int64 v28; // rcx
  __int64 v29; // rdx
  float v30; // xmm6_4
  CAkTransition *pTransition; // rdx
  float *v32; // rdx
  float fValue; // xmm0_4
  bool v34; // al
  CAkTransition *v35; // rsi
  char v36; // di
  __int64 v37; // r8
  __int64 v38; // r9
  int v39; // [rsp+40h] [rbp-88h]
  __int64 v40; // [rsp+48h] [rbp-80h] BYREF
  __int64 v41; // [rsp+50h] [rbp-78h]
  TransitionParameters in_Params; // [rsp+58h] [rbp-70h] BYREF
  char v43; // [rsp+D0h] [rbp+8h]

  m_pItems = this->m_StateGroups.m_pItems;
  v7 = in_ulStateID;
  v9 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( this->m_StateGroups.m_pItems != v9 )
  {
    do
    {
      if ( m_pItems->key == in_ulStateGroupID )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v9 );
    if ( m_pItems != v9 )
    {
      p_item = (__int64 *)&m_pItems->item;
      if ( p_item )
      {
        v11 = *p_item;
        v41 = *p_item;
        if ( in_bSkipExtension
          || (CAkStateMgr::UpdateSwitches(this, in_ulStateGroupID, *(_DWORD *)(v11 + 4), in_ulStateID),
              !g_pExternalStateHandler)
          || in_bSkipTransitionTime
          || !g_pExternalStateHandler(in_ulStateGroupID, v7) )
        {
          in_NewDuration = 0;
          v39 = 0;
          if ( !in_bSkipTransitionTime )
          {
            v13 = *(_DWORD **)(v11 + 16);
            v14 = &v13[3 * *(unsigned int *)(v11 + 24)];
            if ( v13 == v14 )
              goto LABEL_18;
            do
            {
              if ( *v13 == *(_DWORD *)(v11 + 4) && v13[1] == v7 )
                break;
              v13 += 3;
            }
            while ( v13 != v14 );
            if ( v13 == v14 || (v15 = v13 + 2) == 0i64 )
LABEL_18:
              in_NewDuration = *(_DWORD *)v11;
            else
              in_NewDuration = *v15;
            v39 = in_NewDuration;
          }
          v16 = *(AkStateGroupChunk **)(v11 + 8);
          if ( v16 )
          {
            v40 = 0i64;
            while ( 1 )
            {
              v43 = 0;
              v16->m_ulActualState = v7;
              State = AkStateGroupChunk::GetState(v16, v7);
              p_m_props = (__int64 *)&State->m_props;
              if ( !State )
                p_m_props = &v40;
              v19 = 0;
              v20 = g_AkPropDecibel;
              do
              {
                m_pProps = v16->m_values.m_pProps;
                if ( m_pProps )
                {
                  v22 = (unsigned __int8)*m_pProps;
                  v23 = 0;
                  while ( 1 )
                  {
                    v24 = (unsigned int)(v23 + 1);
                    if ( m_pProps[v24] == v19 )
                      break;
                    ++v23;
                    if ( (unsigned int)v24 >= v22 )
                      goto LABEL_29;
                  }
                  v25 = (AkStateValue *)&m_pProps[16 * v23 + ((v22 + 4) & 0xFFFFFFFC)];
                }
                else
                {
LABEL_29:
                  v25 = 0i64;
                }
                v26 = (unsigned __int8 *)*p_m_props;
                if ( !*p_m_props )
                  goto LABEL_34;
                v27 = *v26;
                v28 = 0i64;
                while ( 1 )
                {
                  v29 = (unsigned int)(v28 + 1);
                  if ( v26[v29] == v19 )
                    break;
                  v28 = (unsigned int)v29;
                  if ( (unsigned int)v29 >= v27 )
                    goto LABEL_34;
                }
                v32 = (float *)&v26[4 * v28 + ((v27 + 4) & 0xFFFFFFFC)];
                if ( v32 )
                  v30 = *v32;
                else
LABEL_34:
                  v30 = 0.0;
                if ( v25 )
                {
                  pTransition = v25->pTransition;
                  if ( pTransition )
                  {
                    CAkTransitionManager::ChangeParameter(
                      g_pTransitionManager,
                      pTransition,
                      v19,
                      v30,
                      in_NewDuration,
                      AkCurveInterpolation_Linear,
                      AkValueMeaning_Default);
                    goto LABEL_48;
                  }
                  fValue = v25->fValue;
                }
                else
                {
                  fValue = 0.0;
                }
                if ( fValue == v30 )
                  goto LABEL_48;
                v34 = *v20;
                in_Params.fStartValue = fValue;
                in_Params.fTargetValue = v30;
                in_Params.pUser = v16;
                in_Params.bdBs = v34;
                in_Params.eTarget = v19;
                in_Params.lDuration = in_NewDuration;
                in_Params.eFadeCurve = AkCurveInterpolation_Linear;
                in_Params.bUseReciprocalCurve = 1;
                v35 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, 1, TC_State);
                if ( !v25 )
                {
                  v25 = AkPropBundle<AkStateValue>::AddAkProp(&v16->m_values, v19);
                  if ( !v25 )
                  {
                    if ( v35 )
                      goto LABEL_47;
                    goto LABEL_48;
                  }
                }
                v25->pTransition = v35;
                if ( v35 )
                {
                  if ( !((unsigned __int8 (__fastcall *)(CAkParameterNodeBase *, __int64))v16->m_pOwner->vfptr[9].Release)(
                          v16->m_pOwner,
                          3i64) )
                  {
                    LOBYTE(v38) = 1;
                    ((void (__fastcall *)(AkStateGroupChunk *, _QWORD, __int64, __int64))v16->vfptr->TransUpdateValue)(
                      v16,
                      v19,
                      v37,
                      v38);
LABEL_47:
                    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v35, v16);
                  }
LABEL_48:
                  v36 = v43;
                  goto LABEL_49;
                }
                v25->fValue = v30;
                v36 = 1;
                v43 = 1;
LABEL_49:
                in_NewDuration = v39;
                ++v19;
                ++v20;
              }
              while ( v19 < 5u );
              if ( v36 )
                v16->m_pOwner->vfptr[12].Category(v16->m_pOwner);
              v16 = v16->m_pNextInGroup;
              v7 = in_ulStateID;
              if ( !v16 )
              {
                v11 = v41;
                break;
              }
            }
          }
          *(_DWORD *)(v11 + 4) = v7;
        }
      }
    }
  }
}

// File Line: 427
// RVA: 0xA46600
__int64 __fastcall CAkStateMgr::GetState(CAkStateMgr *this, unsigned int in_ulStateGroupID)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *m_pItems; // rax
  MapStruct<unsigned long,AkStateGroupInfo *> *v3; // rcx
  AkStateGroupInfo **p_item; // rax

  m_pItems = this->m_StateGroups.m_pItems;
  v3 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( m_pItems == v3 )
    return 0i64;
  do
  {
    if ( m_pItems->key == in_ulStateGroupID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v3 );
  if ( m_pItems == v3 )
    return 0i64;
  p_item = &m_pItems->item;
  if ( !p_item )
    return 0i64;
  else
    return (*p_item)->ActualState;
}

// File Line: 486
// RVA: 0xA46B50
__int64 __fastcall CAkStateMgr::RemoveAllStateGroups(CAkStateMgr *this, bool in_bIsFromClearBanks)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *m_pItems; // rbx
  AkStateGroupInfo *item; // rdi
  MapStruct<AkStateTransition,long> *v6; // rdx
  unsigned int m_uLength; // eax
  MapStruct<unsigned long,AkStateGroupInfo *> *v8; // rcx

  m_pItems = this->m_StateGroups.m_pItems;
  while ( m_pItems != &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength] )
  {
    item = m_pItems->item;
    if ( in_bIsFromClearBanks && item->members.m_pFirst )
    {
      ++m_pItems;
    }
    else
    {
      v6 = item->mapTransitions.m_pItems;
      if ( v6 )
      {
        item->mapTransitions.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v6);
        item->mapTransitions.m_pItems = 0i64;
        item->mapTransitions.m_ulReserved = 0;
      }
      item->members.m_pFirst = 0i64;
      AK::MemoryMgr::Free(g_DefaultPoolId, item);
      m_uLength = this->m_StateGroups.m_uLength;
      if ( m_uLength > 1 )
      {
        v8 = &this->m_StateGroups.m_pItems[m_uLength];
        *(_QWORD *)&m_pItems->key = *(_QWORD *)&v8[-1].key;
        m_pItems->item = v8[-1].item;
      }
      --this->m_StateGroups.m_uLength;
    }
  }
  return 1i64;
}

// File Line: 506
// RVA: 0xA468F0
__int64 __fastcall CAkStateMgr::RegisterSwitch(
        CAkStateMgr *this,
        CAkSwitchAware *in_pSwitchCntr,
        unsigned int in_ulStateGroup)
{
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v5; // rcx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *m_pFree; // rax
  __int64 result; // rax
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v9; // rdx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v10; // rdx
  __int64 v11; // [rsp+28h] [rbp-10h]

  if ( !in_pSwitchCntr )
    return 31i64;
  LODWORD(v11) = in_ulStateGroup;
  if ( !this->m_listRegisteredSwitch.m_pFree )
  {
    if ( this->m_listRegisteredSwitch.m_ulNumListItems >= this->m_listRegisteredSwitch.m_ulMaxNumListItems )
      return 2i64;
    v5 = (CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
    if ( !v5 )
      return 2i64;
    v5->pNextListItem = this->m_listRegisteredSwitch.m_pFree;
    this->m_listRegisteredSwitch.m_pFree = v5;
  }
  m_pLast = this->m_listRegisteredSwitch.m_pLast;
  m_pFree = this->m_listRegisteredSwitch.m_pFree;
  if ( m_pLast )
    m_pLast->pNextListItem = m_pFree;
  else
    this->m_listRegisteredSwitch.m_pFirst = m_pFree;
  v9 = this->m_listRegisteredSwitch.m_pFree;
  result = 1i64;
  this->m_listRegisteredSwitch.m_pLast = v9;
  this->m_listRegisteredSwitch.m_pFree = v9->pNextListItem;
  v9->pNextListItem = 0i64;
  v10 = this->m_listRegisteredSwitch.m_pLast;
  ++this->m_listRegisteredSwitch.m_ulNumListItems;
  v10->Item.pSwitch = in_pSwitchCntr;
  *(_QWORD *)&v10->Item.ulStateGroup = v11;
  return result;
}

// File Line: 528
// RVA: 0xA47580
__int64 __fastcall CAkStateMgr::UnregisterSwitch(CAkStateMgr *this, CAkSwitchAware *in_pSwitchCntr)
{
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rdx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *pNextListItem; // rcx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *m_pvMemStart; // r8
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v9; // [rsp+20h] [rbp-28h]
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v10; // [rsp+28h] [rbp-20h]

  m_pFirst = this->m_listRegisteredSwitch.m_pFirst;
  v4 = 0i64;
  while ( m_pFirst )
  {
    if ( m_pFirst->Item.pSwitch == in_pSwitchCntr )
    {
      pNextListItem = m_pFirst->pNextListItem;
      v10 = v4;
      v9 = m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_listRegisteredSwitch.m_pFirst )
        this->m_listRegisteredSwitch.m_pFirst = pNextListItem;
      else
        v4->pNextListItem = pNextListItem;
      if ( m_pFirst == this->m_listRegisteredSwitch.m_pLast )
        this->m_listRegisteredSwitch.m_pLast = v4;
      m_pvMemStart = this->m_listRegisteredSwitch.m_pvMemStart;
      if ( m_pFirst < m_pvMemStart || m_pFirst >= &m_pvMemStart[this->m_listRegisteredSwitch.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
      }
      else
      {
        m_pFirst->pNextListItem = this->m_listRegisteredSwitch.m_pFree;
        this->m_listRegisteredSwitch.m_pFree = m_pFirst;
      }
      --this->m_listRegisteredSwitch.m_ulNumListItems;
      v4 = v10;
      m_pFirst = v9;
    }
    else
    {
      v4 = m_pFirst;
      m_pFirst = m_pFirst->pNextListItem;
    }
  }
  return 1i64;
}

// File Line: 548
// RVA: 0xA46540
CAkStateMgr::PreparationStateItem *__fastcall CAkStateMgr::GetPreparationItem(
        CAkStateMgr *this,
        unsigned int in_ulGroup,
        AkGroupType in_eGroupType)
{
  CAkLock *p_m_PrepareGameSyncLock; // rbx
  AkListBare<CAkStateMgr::PreparationStateItem,AkListBareNextItem<CAkStateMgr::PreparationStateItem>,AkCountPolicyNoCount> *p_m_PreparationGroupsStates; // rsi
  CAkStateMgr::PreparationStateItem *m_pFirst; // rdi
  CAkStateMgr::PreparationStateItem *v9; // rax

  p_m_PrepareGameSyncLock = &this->m_PrepareGameSyncLock;
  EnterCriticalSection(&this->m_PrepareGameSyncLock.m_csLock);
  if ( in_eGroupType == AkGroupType_State )
    p_m_PreparationGroupsStates = &this->m_PreparationGroupsStates;
  else
    p_m_PreparationGroupsStates = &this->m_PreparationGroupsSwitches;
  m_pFirst = p_m_PreparationGroupsStates->m_pFirst;
  if ( p_m_PreparationGroupsStates->m_pFirst )
  {
    while ( in_ulGroup != m_pFirst->m_GroupID )
    {
      m_pFirst = m_pFirst->pNextItem;
      if ( !m_pFirst )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v9 = (CAkStateMgr::PreparationStateItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
    m_pFirst = v9;
    if ( v9 )
    {
      v9->pNextItem = 0i64;
      v9->m_PreparedContent.m_PreparableContentList.m_pItems = 0i64;
      *(_QWORD *)&v9->m_PreparedContent.m_PreparableContentList.m_uLength = 0i64;
      v9->m_GroupID = in_ulGroup;
      v9->m_PreparationList.m_pFirst = 0i64;
      v9->m_PreparationList.m_pLast = 0i64;
      if ( p_m_PreparationGroupsStates->m_pFirst )
      {
        v9->pNextItem = p_m_PreparationGroupsStates->m_pFirst;
        p_m_PreparationGroupsStates->m_pFirst = v9;
      }
      else
      {
        p_m_PreparationGroupsStates->m_pLast = v9;
        p_m_PreparationGroupsStates->m_pFirst = v9;
        v9->pNextItem = 0i64;
      }
    }
  }
  LeaveCriticalSection(&p_m_PrepareGameSyncLock->m_csLock);
  return m_pFirst;
}

// File Line: 587
// RVA: 0xA467F0
__int64 __fastcall CAkStateMgr::PrepareGameSync(
        CAkStateMgr *this,
        AkGroupType in_eGroupType,
        unsigned int in_uGroupID,
        unsigned int in_uGameSyncID,
        bool in_bIsActive)
{
  CAkStateMgr::PreparationStateItem *PreparationItem; // rax
  CAkStateMgr::PreparationStateItem *v7; // r14
  __int64 result; // rax
  __int64 m_uLength; // rcx
  unsigned int *m_pItems; // rbx
  unsigned int *i; // rax
  unsigned int *v12; // rax
  unsigned int v13; // ecx

  PreparationItem = CAkStateMgr::GetPreparationItem(this, in_uGroupID, in_eGroupType);
  v7 = PreparationItem;
  if ( !PreparationItem )
  {
    result = 1i64;
    if ( in_bIsActive )
      return 52i64;
    return result;
  }
  m_uLength = PreparationItem->m_PreparedContent.m_PreparableContentList.m_uLength;
  m_pItems = PreparationItem->m_PreparedContent.m_PreparableContentList.m_pItems;
  for ( i = &m_pItems[m_uLength]; m_pItems != i; ++m_pItems )
  {
    if ( *m_pItems == in_uGameSyncID )
      break;
  }
  if ( m_pItems == i )
  {
    if ( in_bIsActive )
    {
      v12 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(&v7->m_PreparedContent.m_PreparableContentList);
      if ( v12 )
        *v12 = in_uGameSyncID;
      goto LABEL_17;
    }
    return 1i64;
  }
  if ( in_bIsActive )
    return 1i64;
  if ( (unsigned int)m_uLength > 1 )
    *m_pItems = *(i - 1);
  --v7->m_PreparedContent.m_PreparableContentList.m_uLength;
LABEL_17:
  result = CAkStateMgr::PreparationStateItem::Notify(v7, in_uGameSyncID, in_bIsActive);
  if ( (_DWORD)result != 1 )
  {
    v13 = v7->m_PreparedContent.m_PreparableContentList.m_uLength;
    if ( v13 > 1 )
      *m_pItems = v7->m_PreparedContent.m_PreparableContentList.m_pItems[v13 - 1];
    --v7->m_PreparedContent.m_PreparableContentList.m_uLength;
  }
  return result;
}

// File Line: 631
// RVA: 0xA47700
__int64 __fastcall CAkStateMgr::UpdateSwitches(
        CAkStateMgr *this,
        unsigned int in_ulStateGroup,
        unsigned int in_StateFrom,
        unsigned int in_StateTo)
{
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *i; // rbx

  if ( in_StateFrom == in_StateTo )
    return 1i64;
  for ( i = this->m_listRegisteredSwitch.m_pFirst; i; i = i->pNextListItem )
  {
    if ( i->Item.ulStateGroup == in_ulStateGroup )
      i->Item.pSwitch->vfptr->SetSwitch(i->Item.pSwitch, in_StateTo, 0i64);
  }
  return 1i64;
}

// File Line: 685
// RVA: 0xA469B0
__int64 __fastcall CAkStateMgr::RegisterTrigger(
        CAkStateMgr *this,
        IAkTriggerAware *in_pTrigerAware,
        CAkRegisteredObj *in_GameObj)
{
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v6; // rax
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *m_pFree; // rax
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v10; // rcx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v11; // rcx
  __int64 v12; // [rsp+28h] [rbp-20h]

  LODWORD(v12) = 0;
  if ( !this->m_listRegisteredTrigger.m_pFree )
  {
    if ( this->m_listRegisteredTrigger.m_ulNumListItems >= this->m_listRegisteredTrigger.m_ulMaxNumListItems )
      return 2i64;
    v6 = (CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
    if ( !v6 )
      return 2i64;
    v6->pNextListItem = this->m_listRegisteredTrigger.m_pFree;
    this->m_listRegisteredTrigger.m_pFree = v6;
  }
  m_pLast = this->m_listRegisteredTrigger.m_pLast;
  m_pFree = this->m_listRegisteredTrigger.m_pFree;
  if ( m_pLast )
    m_pLast->pNextListItem = m_pFree;
  else
    this->m_listRegisteredTrigger.m_pFirst = m_pFree;
  v10 = this->m_listRegisteredTrigger.m_pFree;
  this->m_listRegisteredTrigger.m_pLast = v10;
  this->m_listRegisteredTrigger.m_pFree = v10->pNextListItem;
  v10->pNextListItem = 0i64;
  v11 = this->m_listRegisteredTrigger.m_pLast;
  ++this->m_listRegisteredTrigger.m_ulNumListItems;
  v11->Item.pTriggerAware = in_pTrigerAware;
  *(_QWORD *)&v11->Item.triggerID = v12;
  v11->Item.gameObj = in_GameObj;
  return 1i64;
}

// File Line: 700
// RVA: 0xA47640
__int64 __fastcall CAkStateMgr::UnregisterTrigger(CAkStateMgr *this, IAkTriggerAware *in_pTrigerAware)
{
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rcx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *pNextListItem; // rdx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *m_pvMemStart; // rdx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v9; // [rsp+20h] [rbp-28h]
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v10; // [rsp+28h] [rbp-20h]

  m_pFirst = this->m_listRegisteredTrigger.m_pFirst;
  v4 = 0i64;
  while ( m_pFirst )
  {
    if ( m_pFirst->Item.pTriggerAware == in_pTrigerAware )
    {
      pNextListItem = m_pFirst->pNextListItem;
      v10 = v4;
      v9 = m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_listRegisteredTrigger.m_pFirst )
        this->m_listRegisteredTrigger.m_pFirst = pNextListItem;
      else
        v4->pNextListItem = pNextListItem;
      if ( m_pFirst == this->m_listRegisteredTrigger.m_pLast )
        this->m_listRegisteredTrigger.m_pLast = v4;
      m_pvMemStart = this->m_listRegisteredTrigger.m_pvMemStart;
      if ( m_pFirst < m_pvMemStart || m_pFirst >= &m_pvMemStart[this->m_listRegisteredTrigger.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
      }
      else
      {
        m_pFirst->pNextListItem = this->m_listRegisteredTrigger.m_pFree;
        this->m_listRegisteredTrigger.m_pFree = m_pFirst;
      }
      --this->m_listRegisteredTrigger.m_ulNumListItems;
      v4 = v10;
      m_pFirst = v9;
    }
    else
    {
      v4 = m_pFirst;
      m_pFirst = m_pFirst->pNextListItem;
    }
  }
  return 1i64;
}

// File Line: 718
// RVA: 0xA47520
void __fastcall CAkStateMgr::Trigger(CAkStateMgr *this, unsigned int in_Trigger, CAkRegisteredObj *in_GameObj)
{
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  unsigned int triggerID; // eax

  for ( i = this->m_listRegisteredTrigger.m_pFirst; i; i = i->pNextListItem )
  {
    triggerID = i->Item.triggerID;
    if ( (!triggerID || triggerID == in_Trigger) && (!in_GameObj || i->Item.gameObj == in_GameObj) )
      i->Item.pTriggerAware->vfptr->Trigger(i->Item.pTriggerAware, in_Trigger);
  }
}

