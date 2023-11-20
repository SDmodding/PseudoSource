// File Line: 35
// RVA: 0xA472E0
void __fastcall AkStateGroupInfo::Term(AkStateGroupInfo *this)
{
  MapStruct<AkStateTransition,long> *v1; // rdx
  AkStateGroupInfo *v2; // rbx

  v1 = this->mapTransitions.m_pItems;
  v2 = this;
  if ( v1 )
  {
    this->mapTransitions.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->mapTransitions.m_pItems = 0i64;
    v2->mapTransitions.m_ulReserved = 0;
    v2->members.m_pFirst = 0i64;
  }
  else
  {
    this->members.m_pFirst = 0i64;
  }
}

// File Line: 41
// RVA: 0xA46740
__int64 __fastcall CAkStateMgr::PreparationStateItem::Notify(CAkStateMgr::PreparationStateItem *this, unsigned int in_GameSyncID, bool in_bIsActive)
{
  CAkPreparationAware *v3; // rbx
  bool v4; // di
  unsigned int v5; // ebp
  CAkStateMgr::PreparationStateItem *v6; // r14
  __int64 result; // rax
  unsigned int v8; // esi
  CAkPreparationAware *v9; // rdi

  v3 = this->m_PreparationList.m_pFirst;
  v4 = in_bIsActive;
  v5 = in_GameSyncID;
  v6 = this;
  if ( !v3 )
    return 1i64;
  while ( 1 )
  {
    result = v3->vfptr->ModifyActiveState(v3, v5, v4);
    v8 = result;
    if ( (_DWORD)result != 1 )
      break;
    v3 = v3->pNextItemPrepare;
    if ( !v3 )
      return result;
  }
  if ( v4 )
  {
    v9 = v6->m_PreparationList.m_pFirst;
    if ( v3 != v9 )
    {
      do
      {
        v9->vfptr->ModifyActiveState(v9, v5, 0);
        v9 = v9->pNextItemPrepare;
      }
      while ( v3 != v9 );
      result = v8;
    }
  }
  return result;
}

// File Line: 67
// RVA: 0xA46200
void __fastcall CAkStateMgr::CAkStateMgr(CAkStateMgr *this)
{
  CAkStateMgr *v1; // rbx
  _RTL_CRITICAL_SECTION *v2; // rcx

  v1 = this;
  v2 = &this->m_PrepareGameSyncLock.m_csLock;
  *(_QWORD *)&v2[-3].LockCount = 0i64;
  v2[-3].OwningThread = 0i64;
  *(_QWORD *)&v2[-2].LockCount = 0i64;
  LODWORD(v2[-2].OwningThread) = 0;
  v2[-1].OwningThread = 0i64;
  LODWORD(v2[-1].LockSemaphore) = 0;
  InitializeCriticalSection(v2);
  v1->m_PreparationGroupsStates.m_pFirst = 0i64;
  v1->m_PreparationGroupsStates.m_pLast = 0i64;
  v1->m_PreparationGroupsSwitches.m_pFirst = 0i64;
  v1->m_PreparationGroupsSwitches.m_pLast = 0i64;
}

// File Line: 71
// RVA: 0xA46260
void __fastcall CAkStateMgr::~CAkStateMgr(CAkStateMgr *this)
{
  DeleteCriticalSection(&this->m_PrepareGameSyncLock.m_csLock);
}

// File Line: 75
// RVA: 0xA46640
signed __int64 __fastcall CAkStateMgr::Init(CAkStateMgr *this)
{
  CAkStateMgr *v1; // rbx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v2; // rax
  unsigned int v3; // edi
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v4; // rcx
  signed __int64 result; // rax
  unsigned int v6; // edx
  signed __int64 v7; // rax
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v8; // rax
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v9; // rcx
  unsigned int v10; // edx
  signed __int64 v11; // rax

  v1 = this;
  this->m_listRegisteredSwitch.m_ulMaxNumListItems = -1;
  this->m_listRegisteredSwitch.m_ulNumListItems = 0;
  this->m_listRegisteredSwitch.m_pFree = 0i64;
  v2 = (CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC0ui64);
  v3 = 52;
  v4 = v2;
  v1->m_listRegisteredSwitch.m_pvMemStart = v2;
  if ( v2 )
  {
    v1->m_listRegisteredSwitch.m_ulMinNumListItems = 8;
    v1->m_listRegisteredSwitch.m_pFree = v2;
    v6 = 0;
    do
    {
      v7 = (signed __int64)&v4[1];
      ++v6;
      v4->pNextListItem = v4 + 1;
      ++v4;
    }
    while ( v6 < v1->m_listRegisteredSwitch.m_ulMinNumListItems );
    *(_QWORD *)(v7 - 24) = 0i64;
    result = 1i64;
  }
  else
  {
    result = 52i64;
  }
  v1->m_listRegisteredSwitch.m_pFirst = 0i64;
  v1->m_listRegisteredSwitch.m_pLast = 0i64;
  if ( (_DWORD)result == 1 )
  {
    v1->m_listRegisteredTrigger.m_ulNumListItems = 0;
    v1->m_listRegisteredTrigger.m_ulMaxNumListItems = -1;
    v1->m_listRegisteredTrigger.m_pFree = 0i64;
    v8 = (CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x100ui64);
    v9 = v8;
    v1->m_listRegisteredTrigger.m_pvMemStart = v8;
    if ( v8 )
    {
      v1->m_listRegisteredTrigger.m_ulMinNumListItems = 8;
      v1->m_listRegisteredTrigger.m_pFree = v8;
      v10 = 0;
      do
      {
        v11 = (signed __int64)&v9[1];
        ++v10;
        v9->pNextListItem = v9 + 1;
        ++v9;
      }
      while ( v10 < v1->m_listRegisteredTrigger.m_ulMinNumListItems );
      *(_QWORD *)(v11 - 32) = 0i64;
      v3 = 1;
    }
    v1->m_listRegisteredTrigger.m_pFirst = 0i64;
    v1->m_listRegisteredTrigger.m_pLast = 0i64;
    result = v3;
  }
  return result;
}

// File Line: 87
// RVA: 0xA47330
void __fastcall CAkStateMgr::Term(CAkStateMgr *this)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *v1; // rbx
  CAkStateMgr *i; // rdi
  AkStateGroupInfo *v3; // rsi
  MapStruct<AkStateTransition,long> *v4; // rdx
  unsigned int v5; // eax
  signed __int64 v6; // rcx
  MapStruct<unsigned long,AkStateGroupInfo *> *v7; // rdx

  v1 = this->m_StateGroups.m_pItems;
  for ( i = this; v1 != &i->m_StateGroups.m_pItems[i->m_StateGroups.m_uLength]; --i->m_StateGroups.m_uLength )
  {
    v3 = v1->item;
    v4 = v3->mapTransitions.m_pItems;
    if ( v4 )
    {
      v3->mapTransitions.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v4);
      v3->mapTransitions.m_pItems = 0i64;
      v3->mapTransitions.m_ulReserved = 0;
    }
    v3->members.m_pFirst = 0i64;
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
    v5 = i->m_StateGroups.m_uLength;
    if ( v5 > 1 )
    {
      v6 = (signed __int64)&i->m_StateGroups.m_pItems[v5];
      *(_QWORD *)&v1->key = *(_QWORD *)(v6 - 16);
      v1->item = *(AkStateGroupInfo **)(v6 - 8);
    }
  }
  v7 = i->m_StateGroups.m_pItems;
  if ( i->m_StateGroups.m_pItems )
  {
    i->m_StateGroups.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v7);
    i->m_StateGroups.m_pItems = 0i64;
    i->m_StateGroups.m_ulReserved = 0;
  }
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::Term(&i->m_listRegisteredSwitch);
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::Term(&i->m_listRegisteredTrigger);
  CAkStateMgr::TermPreparationGroup(i, &i->m_PreparationGroupsStates);
  CAkStateMgr::TermPreparationGroup(i, &i->m_PreparationGroupsSwitches);
}

// File Line: 99
// RVA: 0xA47430
void __fastcall CAkStateMgr::TermPreparationGroup(CAkStateMgr *this, AkListBare<CAkStateMgr::PreparationStateItem,AkListBareNextItem<CAkStateMgr::PreparationStateItem>,AkCountPolicyNoCount> *in_rGroup)
{
  CAkStateMgr::PreparationStateItem *v2; // rbx
  AkListBare<CAkStateMgr::PreparationStateItem,AkListBareNextItem<CAkStateMgr::PreparationStateItem>,AkCountPolicyNoCount> *v3; // rdi
  CAkStateMgr::PreparationStateItem *v4; // rax
  CAkStateMgr::PreparationStateItem *v5; // rsi
  int v6; // ebp
  unsigned int *v7; // rdx
  __m128i v8; // [rsp+20h] [rbp-28h]
  __m128i v9; // [rsp+30h] [rbp-18h]

  v2 = in_rGroup->m_pFirst;
  v3 = in_rGroup;
  v4 = 0i64;
  if ( in_rGroup->m_pFirst )
  {
    while ( 1 )
    {
      v5 = v2->pNextItem;
      v8.m128i_i64[1] = (__int64)v4;
      v8.m128i_i64[0] = (__int64)v2->pNextItem;
      if ( v2 == v3->m_pFirst )
        v3->m_pFirst = v5;
      else
        v4->pNextItem = v5;
      if ( v2 == v3->m_pLast )
        v3->m_pLast = v4;
      v6 = g_DefaultPoolId;
      v2->m_PreparationList.m_pFirst = 0i64;
      v2->m_PreparationList.m_pLast = 0i64;
      v7 = v2->m_PreparedContent.m_PreparableContentList.m_pItems;
      _mm_store_si128(&v9, v8);
      if ( v7 )
      {
        v2->m_PreparedContent.m_PreparableContentList.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v7);
        v2->m_PreparedContent.m_PreparableContentList.m_pItems = 0i64;
        v2->m_PreparedContent.m_PreparableContentList.m_ulReserved = 0;
      }
      AK::MemoryMgr::Free(v6, v2);
      if ( !v5 )
        break;
      v4 = (CAkStateMgr::PreparationStateItem *)v9.m128i_i64[1];
      v2 = (CAkStateMgr::PreparationStateItem *)v9.m128i_i64[0];
    }
    v3->m_pFirst = 0i64;
    v3->m_pLast = 0i64;
  }
  else
  {
    in_rGroup->m_pFirst = 0i64;
    in_rGroup->m_pLast = 0i64;
  }
}

// File Line: 111
// RVA: 0xA46320
signed __int64 __fastcall CAkStateMgr::AddStateGroup(CAkStateMgr *this, unsigned int in_ulStateGroupID)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *v2; // rax
  unsigned int v3; // esi
  CAkStateMgr *v4; // r14
  unsigned int v5; // edi
  MapStruct<unsigned long,AkStateGroupInfo *> *v6; // r8
  CAkSplitterBus *v8; // rbx

  v2 = this->m_StateGroups.m_pItems;
  v3 = in_ulStateGroupID;
  v4 = this;
  v5 = 1;
  v6 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( this->m_StateGroups.m_pItems != v6 )
  {
    do
    {
      if ( v2->key == in_ulStateGroupID )
        break;
      ++v2;
    }
    while ( v2 != v6 );
    if ( v2 != v6 && v2 != (MapStruct<unsigned long,AkStateGroupInfo *> *)-8i64 )
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
          (CAkKeyArray<unsigned long,CAkSplitterBus *,4> *)v4,
          v3,
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
signed __int64 __fastcall CAkStateMgr::AddStateGroupMember(CAkStateMgr *this, unsigned int in_ulStateGroupID, AkStateGroupChunk *in_pMember)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *v3; // rax
  MapStruct<unsigned long,AkStateGroupInfo *> *v4; // rcx
  AkStateGroupInfo **v5; // rax
  AkStateGroupInfo *v6; // rax
  AkStateGroupChunk *v7; // rcx

  v3 = this->m_StateGroups.m_pItems;
  v4 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( v3 == v4 )
    return 20i64;
  do
  {
    if ( v3->key == in_ulStateGroupID )
      break;
    ++v3;
  }
  while ( v3 != v4 );
  if ( v3 == v4 )
    return 20i64;
  v5 = &v3->item;
  if ( !v5 )
    return 20i64;
  v6 = *v5;
  v7 = v6->members.m_pFirst;
  if ( v7 )
  {
    in_pMember->m_pNextInGroup = v7;
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
signed __int64 __fastcall CAkStateMgr::SetdefaultTransitionTime(CAkStateMgr *this, unsigned int in_ulStateGroupID, int lTransitionTime)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *v3; // rax
  MapStruct<unsigned long,AkStateGroupInfo *> *v4; // rcx
  _DWORD **v5; // rax

  v3 = this->m_StateGroups.m_pItems;
  v4 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( v3 == v4 )
    return 20i64;
  do
  {
    if ( v3->key == in_ulStateGroupID )
      break;
    ++v3;
  }
  while ( v3 != v4 );
  if ( v3 == v4 )
    return 20i64;
  v5 = (_DWORD **)&v3->item;
  if ( !v5 )
    return 20i64;
  **v5 = lTransitionTime;
  return 1i64;
}

// File Line: 198
// RVA: 0xA46C30
signed __int64 __fastcall CAkStateMgr::RemoveStateGroupMember(CAkStateMgr *this, unsigned int in_ulStateGroupID, AkStateGroupChunk *in_pMember)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *v3; // rax
  AkStateGroupChunk *v4; // r9
  MapStruct<unsigned long,AkStateGroupInfo *> *v5; // rcx
  AkStateGroupInfo *v6; // r8
  AkStateGroupChunk *v7; // rdx
  AkStateGroupChunk *v8; // rcx
  AkStateGroupChunk *v9; // rax
  bool v11; // zf
  AkStateGroupChunk *v12; // rcx

  v3 = this->m_StateGroups.m_pItems;
  v4 = in_pMember;
  v5 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( v3 == v5 )
    return 20i64;
  do
  {
    if ( v3->key == in_ulStateGroupID )
      break;
    ++v3;
  }
  while ( v3 != v5 );
  if ( v3 == v5 || v3 == (MapStruct<unsigned long,AkStateGroupInfo *> *)-8i64 )
    return 20i64;
  v6 = v3->item;
  v7 = 0i64;
  v8 = v6->members.m_pFirst;
  v9 = v8;
  if ( v8 )
  {
    while ( v9 != v4 )
    {
      v7 = v9;
      v9 = v9->m_pNextInGroup;
      if ( !v9 )
        return 1i64;
    }
    if ( v9 )
    {
      v11 = v9 == v8;
      v12 = v9->m_pNextInGroup;
      if ( v11 )
      {
        v6->members.m_pFirst = v12;
        return 1i64;
      }
      v7->m_pNextInGroup = v12;
    }
  }
  return 1i64;
}

// File Line: 214
// RVA: 0xA46460
signed __int64 __fastcall CAkStateMgr::AddStateTransition(CAkStateMgr *this, unsigned int in_ulStateGroupID, unsigned int in_ulStateID1, unsigned int in_ulStateID2, int lTransitionTime, bool in_bIsShared)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *v6; // rax
  unsigned int v7; // esi
  unsigned int v8; // ebp
  MapStruct<unsigned long,AkStateGroupInfo *> *i; // rcx
  CAkKeyArray<AkStateTransition,long,5> **v10; // rbx

  v6 = this->m_StateGroups.m_pItems;
  v7 = in_ulStateID2;
  v8 = in_ulStateID1;
  for ( i = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength]; v6 != i; ++v6 )
  {
    if ( v6->key == in_ulStateGroupID )
      break;
  }
  if ( v6 == i )
    return 20i64;
  v10 = (CAkKeyArray<AkStateTransition,long,5> **)&v6->item;
  if ( v6 == (MapStruct<unsigned long,AkStateGroupInfo *> *)-8i64 )
    return 20i64;
  if ( CAkKeyArray<AkStateTransition,long,5>::Set(
         *v10 + 1,
         (AkStateTransition)__PAIR__(in_ulStateID2, in_ulStateID1),
         lTransitionTime)
    && (!in_bIsShared
     || CAkKeyArray<AkStateTransition,long,5>::Set(*v10 + 1, (AkStateTransition)__PAIR__(v8, v7), lTransitionTime)) )
  {
    return 1i64;
  }
  return 2i64;
}

// File Line: 284
// RVA: 0xA46DF0
void __fastcall CAkStateMgr::SetStateInternal(CAkStateMgr *this, unsigned int in_ulStateGroupID, unsigned int in_ulStateID, bool in_bSkipTransitionTime, bool in_bSkipExtension)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *v5; // rax
  bool v6; // di
  unsigned int v7; // ebp
  unsigned int v8; // ebx
  MapStruct<unsigned long,AkStateGroupInfo *> *v9; // r10
  __int64 *v10; // rax
  __int64 v11; // r14
  int in_NewDuration; // esi
  _DWORD *v13; // rax
  signed __int64 v14; // rcx
  int *v15; // rax
  __int64 v16; // rbx
  CAkState *v17; // rax
  __int64 *v18; // r13
  unsigned __int8 v19; // bp
  const bool *v20; // r15
  unsigned __int8 *v21; // r8
  unsigned int v22; // er9
  int v23; // ecx
  __int64 v24; // rdx
  AkStateValue *v25; // rdi
  unsigned __int8 *v26; // r8
  unsigned int v27; // er9
  __int64 v28; // rcx
  __int64 v29; // rdx
  float v30; // xmm6_4
  CAkTransition *v31; // rdx
  float *v32; // rdx
  float v33; // xmm0_4
  bool v34; // al
  CAkTransition *v35; // rsi
  char v36; // di
  __int64 v37; // r8
  __int64 v38; // r9
  int v39; // [rsp+40h] [rbp-88h]
  __int64 v40; // [rsp+48h] [rbp-80h]
  __int64 v41; // [rsp+50h] [rbp-78h]
  TransitionParameters in_Params; // [rsp+58h] [rbp-70h]
  char v43; // [rsp+D0h] [rbp+8h]
  unsigned int v44; // [rsp+E0h] [rbp+18h]

  v44 = in_ulStateID;
  v5 = this->m_StateGroups.m_pItems;
  v6 = in_bSkipTransitionTime;
  v7 = in_ulStateID;
  v8 = in_ulStateGroupID;
  v9 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( this->m_StateGroups.m_pItems != v9 )
  {
    do
    {
      if ( v5->key == in_ulStateGroupID )
        break;
      ++v5;
    }
    while ( v5 != v9 );
    if ( v5 != v9 )
    {
      v10 = (__int64 *)&v5->item;
      if ( v10 )
      {
        v11 = *v10;
        v41 = *v10;
        if ( in_bSkipExtension
          || (CAkStateMgr::UpdateSwitches(this, in_ulStateGroupID, *(_DWORD *)(v11 + 4), in_ulStateID),
              !g_pExternalStateHandler)
          || v6
          || !g_pExternalStateHandler(v8, v7) )
        {
          in_NewDuration = 0;
          v39 = 0;
          if ( !v6 )
          {
            v13 = *(_DWORD **)(v11 + 16);
            v14 = (signed __int64)&v13[3 * *(unsigned int *)(v11 + 24)];
            if ( v13 == (_DWORD *)v14 )
              goto LABEL_62;
            do
            {
              if ( *v13 == *(_DWORD *)(v11 + 4) && v13[1] == v7 )
                break;
              v13 += 3;
            }
            while ( v13 != (_DWORD *)v14 );
            if ( v13 != (_DWORD *)v14 && (v15 = v13 + 2) != 0i64 )
              in_NewDuration = *v15;
            else
LABEL_62:
              in_NewDuration = *(_DWORD *)v11;
            v39 = in_NewDuration;
          }
          v16 = *(_QWORD *)(v11 + 8);
          if ( v16 )
          {
            v40 = 0i64;
            while ( 1 )
            {
              v43 = 0;
              *(_DWORD *)(v16 + 60) = v7;
              v17 = AkStateGroupChunk::GetState((AkStateGroupChunk *)v16, v7);
              v18 = (__int64 *)&v17->m_props;
              if ( !v17 )
                v18 = &v40;
              v19 = 0;
              v20 = g_AkPropDecibel;
              do
              {
                v21 = *(unsigned __int8 **)(v16 + 32);
                if ( v21 )
                {
                  v22 = *v21;
                  v23 = 0;
                  while ( 1 )
                  {
                    v24 = (unsigned int)(v23 + 1);
                    if ( v21[v24] == v19 )
                      break;
                    ++v23;
                    if ( (unsigned int)v24 >= v22 )
                      goto LABEL_29;
                  }
                  v25 = (AkStateValue *)&v21[16 * v23 + ((v22 + 4) & 0xFFFFFFFC)];
                }
                else
                {
LABEL_29:
                  v25 = 0i64;
                }
                v26 = (unsigned __int8 *)*v18;
                if ( !*v18 )
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
                  v31 = v25->pTransition;
                  if ( v31 )
                  {
                    CAkTransitionManager::ChangeParameter(
                      g_pTransitionManager,
                      v31,
                      v19,
                      v30,
                      in_NewDuration,
                      AkCurveInterpolation_Linear,
                      0);
                    goto LABEL_48;
                  }
                  v33 = v25->fValue;
                }
                else
                {
                  v33 = 0.0;
                }
                if ( v33 == v30 )
                  goto LABEL_48;
                v34 = *v20;
                in_Params.fStartValue = v33;
                in_Params.fTargetValue = v30;
                in_Params.pUser = (ITransitionable *)v16;
                in_Params.bdBs = v34;
                in_Params.eTarget = v19;
                in_Params.lDuration = in_NewDuration;
                in_Params.eFadeCurve = 4;
                in_Params.bUseReciprocalCurve = 1;
                v35 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, 1, TC_State);
                if ( !v25 )
                {
                  v25 = AkPropBundle<AkStateValue>::AddAkProp((AkPropBundle<AkStateValue> *)(v16 + 32), v19);
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
                  if ( !(*(unsigned __int8 (__fastcall **)(_QWORD, signed __int64))(**(_QWORD **)(v16 + 24) + 304i64))(
                          *(_QWORD *)(v16 + 24),
                          3i64) )
                  {
                    LOBYTE(v38) = 1;
                    (**(void (__fastcall ***)(__int64, _QWORD, __int64, __int64))v16)(v16, v19, v37, v38);
LABEL_47:
                    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v35, (ITransitionable *)v16);
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
                (*(void (**)(void))(**(_QWORD **)(v16 + 24) + 408i64))();
              v16 = *(_QWORD *)(v16 + 8);
              v7 = v44;
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
  MapStruct<unsigned long,AkStateGroupInfo *> *v2; // rax
  MapStruct<unsigned long,AkStateGroupInfo *> *v3; // rcx
  signed __int64 v4; // rax
  __int64 result; // rax

  v2 = this->m_StateGroups.m_pItems;
  v3 = &this->m_StateGroups.m_pItems[this->m_StateGroups.m_uLength];
  if ( v2 == v3 )
    goto LABEL_10;
  do
  {
    if ( v2->key == in_ulStateGroupID )
      break;
    ++v2;
  }
  while ( v2 != v3 );
  if ( v2 != v3 && (v4 = (signed __int64)&v2->item) != 0 )
    result = *(unsigned int *)(*(_QWORD *)v4 + 4i64);
  else
LABEL_10:
    result = 0i64;
  return result;
}

// File Line: 486
// RVA: 0xA46B50
signed __int64 __fastcall CAkStateMgr::RemoveAllStateGroups(CAkStateMgr *this, bool in_bIsFromClearBanks)
{
  MapStruct<unsigned long,AkStateGroupInfo *> *v2; // rbx
  bool v3; // bp
  CAkStateMgr *v4; // rsi
  AkStateGroupInfo *v5; // rdi
  MapStruct<AkStateTransition,long> *v6; // rdx
  unsigned int v7; // eax
  signed __int64 v8; // rcx

  v2 = this->m_StateGroups.m_pItems;
  v3 = in_bIsFromClearBanks;
  v4 = this;
  while ( v2 != &v4->m_StateGroups.m_pItems[v4->m_StateGroups.m_uLength] )
  {
    v5 = v2->item;
    if ( v3 && v5->members.m_pFirst )
    {
      ++v2;
    }
    else
    {
      v6 = v5->mapTransitions.m_pItems;
      if ( v6 )
      {
        v5->mapTransitions.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v6);
        v5->mapTransitions.m_pItems = 0i64;
        v5->mapTransitions.m_ulReserved = 0;
      }
      v5->members.m_pFirst = 0i64;
      AK::MemoryMgr::Free(g_DefaultPoolId, v5);
      v7 = v4->m_StateGroups.m_uLength;
      if ( v7 > 1 )
      {
        v8 = (signed __int64)&v4->m_StateGroups.m_pItems[v7];
        *(_QWORD *)&v2->key = *(_QWORD *)(v8 - 16);
        v2->item = *(AkStateGroupInfo **)(v8 - 8);
      }
      --v4->m_StateGroups.m_uLength;
    }
  }
  return 1i64;
}

// File Line: 506
// RVA: 0xA468F0
signed __int64 __fastcall CAkStateMgr::RegisterSwitch(CAkStateMgr *this, CAkSwitchAware *in_pSwitchCntr, unsigned int in_ulStateGroup)
{
  CAkSwitchAware *v3; // rdi
  CAkStateMgr *v4; // rbx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v5; // rcx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v6; // rcx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v7; // rax
  signed __int64 result; // rax
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v9; // rdx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v10; // rdx
  __int64 v11; // [rsp+28h] [rbp-10h]

  v3 = in_pSwitchCntr;
  v4 = this;
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
    v5->pNextListItem = v4->m_listRegisteredSwitch.m_pFree;
    v4->m_listRegisteredSwitch.m_pFree = v5;
  }
  v6 = v4->m_listRegisteredSwitch.m_pLast;
  v7 = v4->m_listRegisteredSwitch.m_pFree;
  if ( v6 )
    v6->pNextListItem = v7;
  else
    v4->m_listRegisteredSwitch.m_pFirst = v7;
  v9 = v4->m_listRegisteredSwitch.m_pFree;
  result = 1i64;
  v4->m_listRegisteredSwitch.m_pLast = v9;
  v4->m_listRegisteredSwitch.m_pFree = v9->pNextListItem;
  v9->pNextListItem = 0i64;
  v10 = v4->m_listRegisteredSwitch.m_pLast;
  ++v4->m_listRegisteredSwitch.m_ulNumListItems;
  v10->Item.pSwitch = v3;
  *(_QWORD *)&v10->Item.ulStateGroup = v11;
  return result;
}

// File Line: 528
// RVA: 0xA47580
signed __int64 __fastcall CAkStateMgr::UnregisterSwitch(CAkStateMgr *this, CAkSwitchAware *in_pSwitchCntr)
{
  CAkSwitchAware *v2; // rdi
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v3; // rdx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v4; // rax
  CAkStateMgr *v5; // rbx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v6; // rcx
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *v7; // r8
  __m128i v9; // [rsp+20h] [rbp-28h]
  __m128i v10; // [rsp+30h] [rbp-18h]

  v2 = in_pSwitchCntr;
  v3 = this->m_listRegisteredSwitch.m_pFirst;
  v4 = 0i64;
  v5 = this;
  while ( v3 )
  {
    if ( v3->Item.pSwitch == v2 )
    {
      v6 = v3->pNextListItem;
      v9.m128i_i64[1] = (__int64)v4;
      v9.m128i_i64[0] = (__int64)v3->pNextListItem;
      if ( v3 == v5->m_listRegisteredSwitch.m_pFirst )
        v5->m_listRegisteredSwitch.m_pFirst = v6;
      else
        v4->pNextListItem = v6;
      if ( v3 == v5->m_listRegisteredSwitch.m_pLast )
        v5->m_listRegisteredSwitch.m_pLast = v4;
      v7 = v5->m_listRegisteredSwitch.m_pvMemStart;
      if ( v3 < v7 || v3 >= &v7[v5->m_listRegisteredSwitch.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v3);
      }
      else
      {
        v3->pNextListItem = v5->m_listRegisteredSwitch.m_pFree;
        v5->m_listRegisteredSwitch.m_pFree = v3;
      }
      --v5->m_listRegisteredSwitch.m_ulNumListItems;
      _mm_store_si128(&v10, v9);
      v4 = (CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *)v10.m128i_i64[1];
      v3 = (CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *)v10.m128i_i64[0];
    }
    else
    {
      v4 = v3;
      v3 = v3->pNextListItem;
    }
  }
  return 1i64;
}

// File Line: 548
// RVA: 0xA46540
CAkStateMgr::PreparationStateItem *__fastcall CAkStateMgr::GetPreparationItem(CAkStateMgr *this, unsigned int in_ulGroup, AkGroupType in_eGroupType)
{
  _RTL_CRITICAL_SECTION *v3; // rbx
  CAkStateMgr *v4; // rsi
  AkGroupType v5; // edi
  unsigned int v6; // ebp
  AkListBare<CAkStateMgr::PreparationStateItem,AkListBareNextItem<CAkStateMgr::PreparationStateItem>,AkCountPolicyNoCount> *v7; // rsi
  CAkStateMgr::PreparationStateItem *v8; // rdi
  CAkStateMgr::PreparationStateItem *v9; // rax

  v3 = &this->m_PrepareGameSyncLock.m_csLock;
  v4 = this;
  v5 = in_eGroupType;
  v6 = in_ulGroup;
  EnterCriticalSection(&this->m_PrepareGameSyncLock.m_csLock);
  if ( v5 == 1 )
    v7 = &v4->m_PreparationGroupsStates;
  else
    v7 = &v4->m_PreparationGroupsSwitches;
  v8 = v7->m_pFirst;
  if ( v7->m_pFirst )
  {
    while ( v6 != v8->m_GroupID )
    {
      v8 = v8->pNextItem;
      if ( !v8 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v9 = (CAkStateMgr::PreparationStateItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
    v8 = v9;
    if ( v9 )
    {
      v9->pNextItem = 0i64;
      v9->m_PreparedContent.m_PreparableContentList.m_pItems = 0i64;
      *(_QWORD *)&v9->m_PreparedContent.m_PreparableContentList.m_uLength = 0i64;
      v9->m_GroupID = v6;
      v9->m_PreparationList.m_pFirst = 0i64;
      v9->m_PreparationList.m_pLast = 0i64;
      if ( v7->m_pFirst )
      {
        v9->pNextItem = v7->m_pFirst;
        v7->m_pFirst = v9;
      }
      else
      {
        v7->m_pLast = v9;
        v7->m_pFirst = v9;
        v9->pNextItem = 0i64;
      }
    }
  }
  LeaveCriticalSection(v3);
  return v8;
}

// File Line: 587
// RVA: 0xA467F0
__int64 __fastcall CAkStateMgr::PrepareGameSync(CAkStateMgr *this, AkGroupType in_eGroupType, unsigned int in_uGroupID, unsigned int in_uGameSyncID, bool in_bIsActive)
{
  unsigned int v5; // esi
  CAkStateMgr::PreparationStateItem *v6; // rax
  CAkStateMgr::PreparationStateItem *v7; // r14
  __int64 result; // rax
  __int64 v9; // rcx
  unsigned int *v10; // rbx
  signed __int64 i; // rax
  unsigned int *v12; // rax
  unsigned int v13; // ecx

  v5 = in_uGameSyncID;
  v6 = CAkStateMgr::GetPreparationItem(this, in_uGroupID, in_eGroupType);
  v7 = v6;
  if ( !v6 )
  {
    result = 1i64;
    if ( in_bIsActive != (_BYTE)v7 )
      result = 52i64;
    return result;
  }
  v9 = v6->m_PreparedContent.m_PreparableContentList.m_uLength;
  v10 = v6->m_PreparedContent.m_PreparableContentList.m_pItems;
  for ( i = (signed __int64)&v10[v9]; v10 != (unsigned int *)i; ++v10 )
  {
    if ( *v10 == v5 )
      break;
  }
  if ( v10 == (unsigned int *)i )
  {
    if ( in_bIsActive )
    {
      v12 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(&v7->m_PreparedContent.m_PreparableContentList);
      if ( v12 )
        *v12 = v5;
      goto LABEL_17;
    }
    return 1i64;
  }
  if ( in_bIsActive )
    return 1i64;
  if ( (unsigned int)v9 > 1 )
    *v10 = *(_DWORD *)(i - 4);
  --v7->m_PreparedContent.m_PreparableContentList.m_uLength;
LABEL_17:
  result = CAkStateMgr::PreparationStateItem::Notify(v7, v5, in_bIsActive);
  if ( (_DWORD)result != 1 )
  {
    v13 = v7->m_PreparedContent.m_PreparableContentList.m_uLength;
    if ( v13 > 1 )
      *v10 = v7->m_PreparedContent.m_PreparableContentList.m_pItems[v13 - 1];
    --v7->m_PreparedContent.m_PreparableContentList.m_uLength;
  }
  return result;
}

// File Line: 631
// RVA: 0xA47700
signed __int64 __fastcall CAkStateMgr::UpdateSwitches(CAkStateMgr *this, unsigned int in_ulStateGroup, unsigned int in_StateFrom, unsigned int in_StateTo)
{
  unsigned int v4; // esi
  unsigned int v5; // edi
  CAkList2<CAkStateMgr::RegisteredSwitch,CAkStateMgr::RegisteredSwitch const &,1,ArrayPoolDefault>::ListItem *i; // rbx

  v4 = in_StateTo;
  v5 = in_ulStateGroup;
  if ( in_StateFrom == in_StateTo )
    return 1i64;
  for ( i = this->m_listRegisteredSwitch.m_pFirst; i; i = i->pNextListItem )
  {
    if ( i->Item.ulStateGroup == v5 )
      i->Item.pSwitch->vfptr->SetSwitch(i->Item.pSwitch, v4, 0i64);
  }
  return 1i64;
}

// File Line: 685
// RVA: 0xA469B0
signed __int64 __fastcall CAkStateMgr::RegisterTrigger(CAkStateMgr *this, IAkTriggerAware *in_pTrigerAware, CAkRegisteredObj *in_GameObj)
{
  CAkRegisteredObj *v3; // rsi
  IAkTriggerAware *v4; // rdi
  CAkStateMgr *v5; // rbx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v6; // rax
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v7; // rcx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v8; // rax
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v10; // rcx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v11; // rcx
  __int64 v12; // [rsp+28h] [rbp-20h]

  v3 = in_GameObj;
  v4 = in_pTrigerAware;
  v5 = this;
  LODWORD(v12) = 0;
  if ( !this->m_listRegisteredTrigger.m_pFree )
  {
    if ( this->m_listRegisteredTrigger.m_ulNumListItems >= this->m_listRegisteredTrigger.m_ulMaxNumListItems )
      return 2i64;
    v6 = (CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
    if ( !v6 )
      return 2i64;
    v6->pNextListItem = v5->m_listRegisteredTrigger.m_pFree;
    v5->m_listRegisteredTrigger.m_pFree = v6;
  }
  v7 = v5->m_listRegisteredTrigger.m_pLast;
  v8 = v5->m_listRegisteredTrigger.m_pFree;
  if ( v7 )
    v7->pNextListItem = v8;
  else
    v5->m_listRegisteredTrigger.m_pFirst = v8;
  v10 = v5->m_listRegisteredTrigger.m_pFree;
  v5->m_listRegisteredTrigger.m_pLast = v10;
  v5->m_listRegisteredTrigger.m_pFree = v10->pNextListItem;
  v10->pNextListItem = 0i64;
  v11 = v5->m_listRegisteredTrigger.m_pLast;
  ++v5->m_listRegisteredTrigger.m_ulNumListItems;
  v11->Item.pTriggerAware = v4;
  *(_QWORD *)&v11->Item.triggerID = v12;
  v11->Item.gameObj = v3;
  return 1i64;
}

// File Line: 700
// RVA: 0xA47640
signed __int64 __fastcall CAkStateMgr::UnregisterTrigger(CAkStateMgr *this, IAkTriggerAware *in_pTrigerAware)
{
  CAkStateMgr *v2; // rbx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v3; // rcx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v4; // rax
  IAkTriggerAware *v5; // rdi
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v6; // rdx
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v7; // rdx
  __m128i v9; // [rsp+20h] [rbp-28h]
  __m128i v10; // [rsp+30h] [rbp-18h]

  v2 = this;
  v3 = this->m_listRegisteredTrigger.m_pFirst;
  v4 = 0i64;
  v5 = in_pTrigerAware;
  while ( v3 )
  {
    if ( v3->Item.pTriggerAware == v5 )
    {
      v6 = v3->pNextListItem;
      v9.m128i_i64[1] = (__int64)v4;
      v9.m128i_i64[0] = (__int64)v3->pNextListItem;
      if ( v3 == v2->m_listRegisteredTrigger.m_pFirst )
        v2->m_listRegisteredTrigger.m_pFirst = v6;
      else
        v4->pNextListItem = v6;
      if ( v3 == v2->m_listRegisteredTrigger.m_pLast )
        v2->m_listRegisteredTrigger.m_pLast = v4;
      v7 = v2->m_listRegisteredTrigger.m_pvMemStart;
      if ( v3 < v7 || v3 >= &v7[v2->m_listRegisteredTrigger.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v3);
      }
      else
      {
        v3->pNextListItem = v2->m_listRegisteredTrigger.m_pFree;
        v2->m_listRegisteredTrigger.m_pFree = v3;
      }
      --v2->m_listRegisteredTrigger.m_ulNumListItems;
      _mm_store_si128(&v10, v9);
      v4 = (CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *)v10.m128i_i64[1];
      v3 = (CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *)v10.m128i_i64[0];
    }
    else
    {
      v4 = v3;
      v3 = v3->pNextListItem;
    }
  }
  return 1i64;
}

// File Line: 718
// RVA: 0xA47520
void __fastcall CAkStateMgr::Trigger(CAkStateMgr *this, unsigned int in_Trigger, CAkRegisteredObj *in_GameObj)
{
  CAkList2<CAkStateMgr::RegisteredTrigger,CAkStateMgr::RegisteredTrigger const &,1,ArrayPoolDefault>::ListItem *v3; // rbx
  CAkRegisteredObj *v4; // rdi
  unsigned int i; // esi
  unsigned int v6; // eax

  v3 = this->m_listRegisteredTrigger.m_pFirst;
  v4 = in_GameObj;
  for ( i = in_Trigger; v3; v3 = v3->pNextListItem )
  {
    v6 = v3->Item.triggerID;
    if ( (!v6 || v6 == i) && (!v4 || v3->Item.gameObj == v4) )
      v3->Item.pTriggerAware->vfptr->Trigger(v3->Item.pTriggerAware, i);
  }
}

