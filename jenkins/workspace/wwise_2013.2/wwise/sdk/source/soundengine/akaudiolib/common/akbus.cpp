// File Line: 80
// RVA: 0xA7AA20
void __fastcall CAkBus::CAkBus(CAkBus *this, unsigned int in_ulID)
{
  CAkBus *v2; // rbx

  v2 = this;
  CAkParameterNodeBase::CAkParameterNodeBase((CAkParameterNodeBase *)&this->vfptr, in_ulID);
  v2->m_mapChildId.m_pItems = 0i64;
  *(_QWORD *)&v2->m_mapChildId.m_uLength = 0i64;
  v2->vfptr = (CAkIndexableVtbl *)&CAkBus::`vftable;
  v2->m_mapBusChildId.m_pItems = 0i64;
  *(_QWORD *)&v2->m_mapBusChildId.m_uLength = 0i64;
  v2->m_RecoveryTime = 0;
  v2->m_uChannelConfig = 1599;
  v2->m_fMaxDuckVolume = -96.300003;
  *(_QWORD *)&v2->m_ToDuckList.m_ulMinNumListItems = 0i64;
  v2->m_ToDuckList.m_ulNumListItems = 0;
  *(_QWORD *)&v2->m_DuckedVolumeList.m_ulMinNumListItems = 0i64;
  v2->m_DuckedVolumeList.m_ulNumListItems = 0;
  *(_QWORD *)&v2->m_DuckedBusVolumeList.m_ulMinNumListItems = 0i64;
  v2->m_DuckedBusVolumeList.m_ulNumListItems = 0;
  *(_QWORD *)&v2->m_fEffectiveBusVolume = 0i64;
  *((_BYTE *)v2 + 304) = 96;
}

// File Line: 84
// RVA: 0xA7AAB0
void __fastcall CAkBus::~CAkBus(CAkBus *this)
{
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v1; // rbx
  CAkBus *v2; // rdi
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v3; // rdx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v4; // r8
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v5; // rdx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v6; // r8
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v7; // rbx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v8; // rdx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v10; // rdx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v11; // r8
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v12; // rdx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v13; // r8
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v14; // rbx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v15; // rdx
  CAkList2<MapStruct<unsigned long,CAkBus::AkDuckInfo>,MapStruct<unsigned long,CAkBus::AkDuckInfo> const &,1,ArrayPoolDefault>::ListItem *v16; // rdx
  CAkList2<MapStruct<unsigned long,CAkBus::AkDuckInfo>,MapStruct<unsigned long,CAkBus::AkDuckInfo> const &,1,ArrayPoolDefault>::ListItem *v17; // rcx
  CAkList2<MapStruct<unsigned long,CAkBus::AkDuckInfo>,MapStruct<unsigned long,CAkBus::AkDuckInfo> const &,1,ArrayPoolDefault>::ListItem *v18; // rdx
  CAkList2<MapStruct<unsigned long,CAkBus::AkDuckInfo>,MapStruct<unsigned long,CAkBus::AkDuckInfo> const &,1,ArrayPoolDefault>::ListItem *v19; // rcx
  CAkList2<MapStruct<unsigned long,CAkBus::AkDuckInfo>,MapStruct<unsigned long,CAkBus::AkDuckInfo> const &,1,ArrayPoolDefault>::ListItem *v20; // rbx
  CAkList2<MapStruct<unsigned long,CAkBus::AkDuckInfo>,MapStruct<unsigned long,CAkBus::AkDuckInfo> const &,1,ArrayPoolDefault>::ListItem *v21; // rdx
  CAkAudioLibIndex *v22; // rbx
  CAkAudioLibIndex *v23; // rbx
  CAkParameterNodeBase **v24; // rdx
  CAkParameterNodeBase **v25; // rdx

  v1 = this->m_DuckedVolumeList.m_pFirst;
  v2 = this;
  for ( this->vfptr = (CAkIndexableVtbl *)&CAkBus::`vftable; v1; v1 = v1->pNextListItem )
    CAkDuckItem::Term(&v1->Item.item);
  if ( v2->m_DuckedVolumeList.m_ulMaxNumListItems )
  {
    while ( 1 )
    {
      v3 = v2->m_DuckedVolumeList.m_pFirst;
      if ( !v3 )
        break;
      v2->m_DuckedVolumeList.m_pFirst = v3->pNextListItem;
      if ( v3 == v2->m_DuckedVolumeList.m_pLast )
        v2->m_DuckedVolumeList.m_pLast = 0i64;
      v4 = v2->m_DuckedVolumeList.m_pvMemStart;
      if ( v3 < v4 || v3 >= &v4[v2->m_DuckedVolumeList.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v3);
        --v2->m_DuckedVolumeList.m_ulNumListItems;
      }
      else
      {
        v3->pNextListItem = v2->m_DuckedVolumeList.m_pFree;
        --v2->m_DuckedVolumeList.m_ulNumListItems;
        v2->m_DuckedVolumeList.m_pFree = v3;
      }
    }
    v5 = v2->m_DuckedVolumeList.m_pFree;
    if ( v5 )
    {
      do
      {
        v6 = v2->m_DuckedVolumeList.m_pvMemStart;
        v7 = v5->pNextListItem;
        if ( v5 < v6 || v5 >= &v6[v2->m_DuckedVolumeList.m_ulMinNumListItems] )
          AK::MemoryMgr::Free(g_DefaultPoolId, v5);
        v5 = v7;
      }
      while ( v7 );
    }
    v8 = v2->m_DuckedVolumeList.m_pvMemStart;
    if ( v8 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v8);
    *(_QWORD *)&v2->m_DuckedVolumeList.m_ulMinNumListItems = 0i64;
    v2->m_DuckedVolumeList.m_pFirst = 0i64;
    v2->m_DuckedVolumeList.m_pLast = 0i64;
  }
  for ( i = v2->m_DuckedBusVolumeList.m_pFirst; i; i = i->pNextListItem )
    CAkDuckItem::Term(&i->Item.item);
  if ( v2->m_DuckedBusVolumeList.m_ulMaxNumListItems > 0 )
  {
    while ( 1 )
    {
      v10 = v2->m_DuckedBusVolumeList.m_pFirst;
      if ( !v10 )
        break;
      v2->m_DuckedBusVolumeList.m_pFirst = v10->pNextListItem;
      if ( v10 == v2->m_DuckedBusVolumeList.m_pLast )
        v2->m_DuckedBusVolumeList.m_pLast = 0i64;
      v11 = v2->m_DuckedBusVolumeList.m_pvMemStart;
      if ( v10 < v11 || v10 >= &v11[v2->m_DuckedBusVolumeList.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v10);
        --v2->m_DuckedBusVolumeList.m_ulNumListItems;
      }
      else
      {
        v10->pNextListItem = v2->m_DuckedBusVolumeList.m_pFree;
        --v2->m_DuckedBusVolumeList.m_ulNumListItems;
        v2->m_DuckedBusVolumeList.m_pFree = v10;
      }
    }
    v12 = v2->m_DuckedBusVolumeList.m_pFree;
    if ( v12 )
    {
      do
      {
        v13 = v2->m_DuckedBusVolumeList.m_pvMemStart;
        v14 = v12->pNextListItem;
        if ( v12 < v13 || v12 >= &v13[v2->m_DuckedBusVolumeList.m_ulMinNumListItems] )
          AK::MemoryMgr::Free(g_DefaultPoolId, v12);
        v12 = v14;
      }
      while ( v14 );
    }
    v15 = v2->m_DuckedBusVolumeList.m_pvMemStart;
    if ( v15 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v15);
    *(_QWORD *)&v2->m_DuckedBusVolumeList.m_ulMinNumListItems = 0i64;
    v2->m_DuckedBusVolumeList.m_pFirst = 0i64;
    v2->m_DuckedBusVolumeList.m_pLast = 0i64;
  }
  if ( v2->m_ToDuckList.m_ulMaxNumListItems > 0 )
  {
    while ( 1 )
    {
      v16 = v2->m_ToDuckList.m_pFirst;
      if ( !v16 )
        break;
      v2->m_ToDuckList.m_pFirst = v16->pNextListItem;
      if ( v16 == v2->m_ToDuckList.m_pLast )
        v2->m_ToDuckList.m_pLast = 0i64;
      v17 = v2->m_ToDuckList.m_pvMemStart;
      if ( v16 < v17 || v16 >= &v17[v2->m_ToDuckList.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v16);
        --v2->m_ToDuckList.m_ulNumListItems;
      }
      else
      {
        v16->pNextListItem = v2->m_ToDuckList.m_pFree;
        --v2->m_ToDuckList.m_ulNumListItems;
        v2->m_ToDuckList.m_pFree = v16;
      }
    }
    v18 = v2->m_ToDuckList.m_pFree;
    if ( v18 )
    {
      do
      {
        v19 = v2->m_ToDuckList.m_pvMemStart;
        v20 = v18->pNextListItem;
        if ( v18 < v19 || v18 >= &v19[v2->m_ToDuckList.m_ulMinNumListItems] )
          AK::MemoryMgr::Free(g_DefaultPoolId, v18);
        v18 = v20;
      }
      while ( v20 );
    }
    v21 = v2->m_ToDuckList.m_pvMemStart;
    if ( v21 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v21);
    *(_QWORD *)&v2->m_ToDuckList.m_ulMinNumListItems = 0i64;
    v2->m_ToDuckList.m_pFirst = 0i64;
    v2->m_ToDuckList.m_pLast = 0i64;
  }
  if ( g_MasterBusCtx.m_pBus == v2 )
  {
    v22 = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
    EnterCriticalSection(&v22->m_idxAudioNode.m_IndexLock.m_csLock);
    g_MasterBusCtx.m_pBus = 0i64;
    LeaveCriticalSection(&v22->m_idxAudioNode.m_IndexLock.m_csLock);
    if ( g_pBankManager )
      g_pBankManager->m_bIsFirstBusLoaded = 0;
    CAkBankMgr::SignalLastBankUnloaded();
  }
  else if ( g_SecondaryMasterBusCtx.m_pBus == v2 )
  {
    v23 = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
    EnterCriticalSection(&v23->m_idxAudioNode.m_IndexLock.m_csLock);
    g_SecondaryMasterBusCtx.m_pBus = 0i64;
    LeaveCriticalSection(&v23->m_idxAudioNode.m_IndexLock.m_csLock);
  }
  v24 = v2->m_mapBusChildId.m_pItems;
  if ( v24 )
  {
    v2->m_mapBusChildId.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v24);
    v2->m_mapBusChildId.m_pItems = 0i64;
    v2->m_mapBusChildId.m_ulReserved = 0;
  }
  v2->vfptr = (CAkIndexableVtbl *)&CAkParentNode<CAkParameterNodeBase>::`vftable;
  v25 = v2->m_mapChildId.m_pItems;
  if ( v25 )
  {
    v2->m_mapChildId.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v25);
    v2->m_mapChildId.m_pItems = 0i64;
    v2->m_mapChildId.m_ulReserved = 0;
  }
  CAkParameterNodeBase::~CAkParameterNodeBase((CAkParameterNodeBase *)&v2->vfptr);
}

// File Line: 123
// RVA: 0xA7C390
signed __int64 __fastcall CAkBus::Init(CAkBus *this)
{
  CAkBus *v1; // rbx
  unsigned int v2; // eax
  signed int v3; // ecx
  bool v4; // al

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[3].Release)();
  v4 = 0;
  if ( v2 <= 0xC )
  {
    v3 = 5121;
    if ( _bittest(&v3, v2) )
      v4 = 1;
  }
  *((_BYTE *)&v1->0 + 83) &= 0xFDu;
  *((_BYTE *)&v1->0 + 83) |= 2 * v4;
  CAkParameterNodeBase::AddToIndex((CAkParameterNodeBase *)&v1->vfptr);
  v1->m_ToDuckList.m_pFree = 0i64;
  v1->m_ToDuckList.m_pvMemStart = 0i64;
  v1->m_ToDuckList.m_pFirst = 0i64;
  v1->m_ToDuckList.m_pLast = 0i64;
  *(_QWORD *)&v1->m_ToDuckList.m_ulMaxNumListItems = 100i64;
  v1->m_DuckedVolumeList.m_pFree = 0i64;
  v1->m_DuckedVolumeList.m_pvMemStart = 0i64;
  v1->m_DuckedVolumeList.m_pFirst = 0i64;
  v1->m_DuckedVolumeList.m_pLast = 0i64;
  *(_QWORD *)&v1->m_DuckedVolumeList.m_ulMaxNumListItems = 100i64;
  v1->m_DuckedBusVolumeList.m_pFree = 0i64;
  v1->m_DuckedBusVolumeList.m_pvMemStart = 0i64;
  v1->m_DuckedBusVolumeList.m_pFirst = 0i64;
  v1->m_DuckedBusVolumeList.m_pLast = 0i64;
  *(_QWORD *)&v1->m_DuckedBusVolumeList.m_ulMaxNumListItems = 100i64;
  return 1i64;
}

// File Line: 141
// RVA: 0xA7B240
void __fastcall CAkBus::Create(unsigned int in_ulID)
{
  unsigned int v1; // ebx
  CAkBus *v2; // rax
  CAkBus *v3; // rax
  CAkBus *v4; // rbx

  v1 = in_ulID;
  v2 = (CAkBus *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x138ui64);
  if ( v2 )
  {
    CAkBus::CAkBus(v2, v1);
    v4 = v3;
    if ( v3 )
    {
      if ( CAkBus::Init(v3) != 1 )
        v4->vfptr->Release((CAkIndexable *)&v4->vfptr);
    }
  }
}

// File Line: 161
// RVA: 0xA7B4F0
signed __int64 __fastcall CAkBus::ExecuteAction(CAkBus *this, ActionParams *in_rAction)
{
  AkActivityChunk *v2; // rax
  ActionParams *v3; // rsi
  CAkBus *v4; // rdi
  unsigned int v5; // ebx
  CAkParameterNodeBase *v6; // rcx
  unsigned int v7; // ebx
  CAkParameterNodeBase *v8; // rcx

  v2 = this->m_pActivityChunk;
  v3 = in_rAction;
  v4 = this;
  if ( !v2 || !v2->m_PlayCount && (!v2 || !v2->m_uActivityCount) )
    return 1i64;
  if ( in_rAction->bIsMasterCall )
  {
    LOBYTE(in_rAction) = in_rAction->eType == 1;
    ((void (__fastcall *)(CAkBus *, ActionParams *))this->vfptr[10].Category)(this, in_rAction);
  }
  v3->bIsFromBus = 1;
  v5 = v4->m_mapChildId.m_uLength;
  while ( v5 )
  {
    v6 = v4->m_mapChildId.m_pItems[--v5];
    v6->vfptr[4].__vecDelDtor((CAkIndexable *)&v6->vfptr, (unsigned int)v3);
    if ( v5 > v4->m_mapChildId.m_uLength )
      v5 = v4->m_mapChildId.m_uLength;
  }
  v7 = v4->m_mapBusChildId.m_uLength;
  while ( v7 )
  {
    v8 = v4->m_mapBusChildId.m_pItems[--v7];
    v8->vfptr[4].__vecDelDtor((CAkIndexable *)&v8->vfptr, (unsigned int)v3);
    if ( v7 > v4->m_mapBusChildId.m_uLength )
      v7 = v4->m_mapBusChildId.m_uLength;
  }
  return 1i64;
}

// File Line: 209
// RVA: 0xA7B5D0
signed __int64 __fastcall CAkBus::ExecuteActionExcept(CAkBus *this, ActionParamsExcept *in_rAction)
{
  ActionParamsExcept *v2; // rsi
  CAkBus *v3; // rdi
  unsigned int v4; // ebx
  CAkParameterNodeBase **v5; // rax
  CAkParameterNodeBase *v6; // r14
  unsigned int v7; // ebx
  CAkParameterNodeBase **v8; // rax
  CAkParameterNodeBase *v9; // r14

  v2 = in_rAction;
  v3 = this;
  if ( !in_rAction->pGameObj )
  {
    LOBYTE(in_rAction) = in_rAction->eType == 1;
    ((void (__fastcall *)(CAkBus *, ActionParamsExcept *))this->vfptr[10].Category)(this, in_rAction);
  }
  v2->bIsFromBus = 1;
  v4 = v3->m_mapChildId.m_uLength;
  while ( v4 )
  {
    v5 = v3->m_mapChildId.m_pItems;
    v6 = v5[--v4];
    if ( !CAkParameterNodeBase::IsException(v5[v4], v2->pExeceptionList) )
      ((void (__fastcall *)(CAkParameterNodeBase *, ActionParamsExcept *))v6->vfptr[4].Release)(v6, v2);
    if ( v4 > v3->m_mapChildId.m_uLength )
      v4 = v3->m_mapChildId.m_uLength;
  }
  v7 = v3->m_mapBusChildId.m_uLength;
  while ( v7 )
  {
    v8 = v3->m_mapBusChildId.m_pItems;
    v9 = v8[--v7];
    if ( !CAkParameterNodeBase::IsException(v8[v7], v2->pExeceptionList) )
      ((void (__fastcall *)(CAkParameterNodeBase *, ActionParamsExcept *))v9->vfptr[4].Release)(v9, v2);
    if ( v7 > v3->m_mapBusChildId.m_uLength )
      v7 = v3->m_mapBusChildId.m_uLength;
  }
  return 1i64;
}

// File Line: 258
// RVA: 0xA7CBE0
__int64 __fastcall CAkBus::PlayToEnd(CAkBus *this, CAkRegisteredObj *in_pGameObj, CAkParameterNodeBase *in_NodePtr, unsigned int in_PlayingID)
{
  CAkParameterNodeBase **v4; // rbx
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *v5; // rdi
  CAkParameterNodeBase ***v6; // rsi
  unsigned int v7; // ebp
  CAkParameterNodeBase *v8; // r14
  CAkRegisteredObj *v9; // r15
  __int64 result; // rax

  v4 = this->m_mapBusChildId.m_pItems;
  v5 = &this->m_mapBusChildId;
  v6 = &this->m_mapChildId.m_pItems;
  v7 = in_PlayingID;
  v8 = in_NodePtr;
  v9 = in_pGameObj;
  if ( v4 == &v4[this->m_mapBusChildId.m_uLength]
    && v5 != (AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *)v6 )
  {
    v4 = *v6;
    v5 = &this->m_mapChildId;
  }
  if ( v4 == &v5->m_pItems[v5->m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))(*v4)->vfptr[4].Category)(
               *v4,
               v9,
               v8,
               v7);
    if ( (_DWORD)result != 1 )
      break;
    ++v4;
    if ( v4 == &v5->m_pItems[v5->m_uLength]
      && v5 != (AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *)v6 )
    {
      v4 = *v6;
      v5 = (AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *)v6;
    }
    if ( v4 == &v5->m_pItems[v5->m_uLength] )
      return (unsigned int)result;
  }
  return result;
}

// File Line: 315
// RVA: 0xA7CD70
void __fastcall CAkBus::PropagatePositioningNotification(CAkBus *this, float in_RTPCValue, AkRTPC_ParameterID in_ParameterID, CAkRegisteredObj *in_GameObj)
{
  if ( this->m_pBusOutputNode )
    CAkLEngine::PositioningChangeNotification(this->key, in_RTPCValue, in_ParameterID);
}

// File Line: 321
// RVA: 0xA7B6B0
signed __int64 __fastcall CAkBus::GetAudioParameters(CAkBus *this, AkSoundParamsEx *io_Parameters, unsigned int in_ulParamSelect, CAkKeyArray<AkMutedMapItem,float,2> *io_rMutedMap, CAkRegisteredObj *in_pGameObj, bool in_bIncludeRange, AkPBIModValues *io_Ranges)
{
  CAkKeyArray<AkMutedMapItem,float,2> *v7; // r14
  AkSoundParamsEx *v8; // rsi
  unsigned int v9; // ebp
  CAkBus *v10; // rdi
  int v11; // ebx
  char *v12; // r8
  unsigned int v13; // er9
  __int64 v14; // rcx
  __int64 v15; // rdx
  signed __int64 v16; // rdx
  float *v17; // rax
  unsigned __int64 v18; // rax
  char *v19; // r8
  unsigned int v20; // er9
  __int64 v21; // rcx
  __int64 v22; // rdx
  signed __int64 v23; // rdx
  float *v24; // rax
  unsigned __int64 v25; // rax
  CAkSIS *v26; // r8
  char *v27; // r8
  unsigned int v28; // er9
  int v29; // ecx
  __int64 v30; // rdx
  float *v31; // rdx
  char *v32; // r8
  unsigned int v33; // er9
  int v34; // ecx
  __int64 v35; // rdx
  float *v36; // rdx
  char *v37; // rdx
  unsigned int v38; // er8
  __int64 v39; // rcx
  float *v40; // rcx
  float v41; // xmm2_4
  CAkParameterNodeBase *v42; // rcx
  AkMutedMapItem v44; // [rsp+40h] [rbp-28h]
  float v45; // [rsp+80h] [rbp+18h]

  v7 = io_rMutedMap;
  v8 = io_Parameters;
  v9 = in_ulParamSelect & 0xFFFFFFF6;
  v10 = this;
  CAkParameterNodeBase::GetAudioStateParams(
    (CAkParameterNodeBase *)&this->vfptr,
    (AkSoundParams *)&io_Parameters->Volume,
    in_ulParamSelect & 0xFFFFFFF6);
  v11 = 0;
  if ( v9 & 2 )
  {
    v12 = v10->m_props.m_pProps;
    v45 = 0.0;
    if ( v12 )
    {
      v13 = (unsigned __int8)*v12;
      v14 = 0i64;
      while ( 1 )
      {
        v15 = (unsigned int)(v14 + 1);
        if ( v12[v15] == 2 )
          break;
        v14 = (unsigned int)v15;
        if ( (unsigned int)v15 >= v13 )
          goto LABEL_6;
      }
      v16 = (signed __int64)&v12[4 * v14 + ((v13 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_6:
      v16 = 0i64;
    }
    v17 = &v45;
    if ( v16 )
      v17 = (float *)v16;
    v45 = *v17;
    v8->Pitch = v45 + v8->Pitch;
    v18 = v10->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const signed __int64 *)&v18, 2ui64) )
      v8->Pitch = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v10, 2u, 0i64) + v8->Pitch;
  }
  if ( v9 & 4 )
  {
    v19 = v10->m_props.m_pProps;
    v45 = 0.0;
    if ( v19 )
    {
      v20 = (unsigned __int8)*v19;
      v21 = 0i64;
      while ( 1 )
      {
        v22 = (unsigned int)(v21 + 1);
        if ( v19[v22] == 3 )
          break;
        v21 = (unsigned int)v22;
        if ( (unsigned int)v22 >= v20 )
          goto LABEL_16;
      }
      v23 = (signed __int64)&v19[4 * v21 + ((v20 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_16:
      v23 = 0i64;
    }
    v24 = &v45;
    if ( v23 )
      v24 = (float *)v23;
    v45 = *v24;
    v8->LPF = v45 + v8->LPF;
    v25 = v10->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const signed __int64 *)&v25, 3ui64) )
      v8->LPF = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v10, 3u, 0i64) + v8->LPF;
  }
  v26 = v10->m_pGlobalSIS;
  if ( v26 )
  {
    v27 = v26->m_values.m_pProps;
    if ( v27 )
    {
      v28 = (unsigned __int8)*v27;
      v29 = 0;
      while ( 1 )
      {
        v30 = (unsigned int)(v29 + 1);
        if ( v27[v30] == 2 )
          break;
        v29 = v30;
        if ( (unsigned int)v30 >= v28 )
          goto LABEL_31;
      }
      v31 = (float *)&v27[16 * v29 + ((v28 + 4) & 0xFFFFFFFC)];
      if ( v31 )
        v8->Pitch = v8->Pitch + *v31;
    }
LABEL_31:
    v32 = v10->m_pGlobalSIS->m_values.m_pProps;
    if ( v32 )
    {
      v33 = (unsigned __int8)*v32;
      v34 = 0;
      while ( 1 )
      {
        v35 = (unsigned int)(v34 + 1);
        if ( v32[v35] == 3 )
          break;
        v34 = v35;
        if ( (unsigned int)v35 >= v33 )
          goto LABEL_38;
      }
      v36 = (float *)&v32[16 * v34 + ((v33 + 4) & 0xFFFFFFFC)];
      if ( v36 )
        v8->LPF = v8->LPF + *v36;
    }
LABEL_38:
    v37 = v10->m_pGlobalSIS->m_values.m_pProps;
    if ( v37 )
    {
      v38 = (unsigned __int8)*v37;
      while ( 1 )
      {
        v39 = (unsigned int)(v11 + 1);
        if ( v37[v39] == 10 )
          break;
        v11 = v39;
        if ( (unsigned int)v39 >= v38 )
          goto LABEL_46;
      }
      v40 = (float *)&v37[16 * v11 + ((v38 + 4) & 0xFFFFFFFC)];
      if ( v40 )
      {
        v41 = *v40;
        if ( *v40 != 1.0 )
        {
          v44.m_Identifier = v10;
          *((_DWORD *)&v44 + 2) = *((_DWORD *)&v44 + 2) & 0xFFFFFFFD | 1;
          _mm_store_si128((__m128i *)&v44, (__m128i)v44);
          CAkKeyArray<AkMutedMapItem,float,2>::Set(v7, &v44, v41);
        }
      }
    }
  }
LABEL_46:
  v42 = v10->m_pBusOutputNode;
  if ( v42 )
    ((void (__fastcall *)(CAkParameterNodeBase *, AkSoundParamsEx *, _QWORD, CAkKeyArray<AkMutedMapItem,float,2> *, CAkRegisteredObj *, bool, AkPBIModValues *, char))v42->vfptr[10].Release)(
      v42,
      v8,
      v9,
      v7,
      in_pGameObj,
      in_bIncludeRange,
      io_Ranges,
      1);
  return 1i64;
}

// File Line: 373
// RVA: 0xA7B9B0
float __fastcall CAkBus::GetBusEffectiveVolume(CAkBus *this, BusVolumeType in_VolumeType, AkPropID in_eProp)
{
  float v3; // xmm7_4
  __int64 v4; // rbx
  BusVolumeType v5; // ebp
  CAkBus *v6; // rdi
  float v7; // xmm6_4
  char *v8; // r8
  CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault> *v9; // rsi
  unsigned int v10; // er9
  __int64 v11; // rcx
  __int64 v12; // rdx
  signed __int64 v13; // rdx
  float *v14; // rax
  unsigned __int64 v15; // r8
  unsigned __int64 v16; // rax
  float v17; // xmm6_4
  CAkSIS *v18; // r8
  char *v19; // r8
  unsigned int v20; // er9
  int v21; // ecx
  __int64 v22; // rdx
  float *v23; // rdx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v24; // rax
  CAkBus *v25; // rcx
  float v26; // xmm6_4
  AkSoundParams io_Parameters; // [rsp+20h] [rbp-58h]
  float v29; // [rsp+90h] [rbp+18h]

  *((_BYTE *)&io_Parameters.normalization + 4) &= 0xFCu;
  *((_BYTE *)&io_Parameters.hdr + 4) &= 0xFCu;
  v3 = 0.0;
  v4 = in_eProp;
  v5 = in_VolumeType;
  v6 = this;
  LODWORD(io_Parameters.fFadeRatio) = (_DWORD)FLOAT_1_0;
  v7 = 0.0;
  io_Parameters.Volume = 0.0;
  *(_QWORD *)&io_Parameters.Pitch = 0i64;
  *(_QWORD *)&io_Parameters.BusVolume = 0i64;
  io_Parameters.hdr.fActiveRange = 0.0;
  if ( in_eProp )
  {
    if ( in_eProp == 4 )
    {
      CAkParameterNodeBase::GetAudioStateParams((CAkParameterNodeBase *)&this->vfptr, &io_Parameters, 8u);
      v7 = io_Parameters.BusVolume;
    }
  }
  else
  {
    CAkParameterNodeBase::GetAudioStateParams((CAkParameterNodeBase *)&this->vfptr, &io_Parameters, 1u);
    v7 = io_Parameters.Volume;
  }
  v8 = v6->m_props.m_pProps;
  v9 = 0i64;
  v29 = 0.0;
  if ( v8 )
  {
    v10 = (unsigned __int8)*v8;
    v11 = 0i64;
    while ( 1 )
    {
      v12 = (unsigned int)(v11 + 1);
      if ( v8[v12] == (_BYTE)v4 )
        break;
      v11 = (unsigned int)v12;
      if ( (unsigned int)v12 >= v10 )
        goto LABEL_9;
    }
    v13 = (signed __int64)&v8[4 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_9:
    v13 = 0i64;
  }
  v14 = &v29;
  v15 = (unsigned int)g_AkPropRTPCID[v4];
  if ( v13 )
    v14 = (float *)v13;
  v29 = *v14;
  v16 = v6->m_RTPCBitArray.m_iBitArray;
  v17 = v7 + v29;
  if ( _bittest64((const signed __int64 *)&v16, v15) )
    v17 = v17 + CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v6, v15, 0i64);
  v18 = v6->m_pGlobalSIS;
  if ( v18 )
  {
    v19 = v18->m_values.m_pProps;
    if ( v19 )
    {
      v20 = (unsigned __int8)*v19;
      v21 = 0;
      while ( 1 )
      {
        v22 = (unsigned int)(v21 + 1);
        if ( v19[v22] == (_BYTE)v4 )
          break;
        ++v21;
        if ( (unsigned int)v22 >= v20 )
          goto LABEL_23;
      }
      v23 = (float *)&v19[16 * v21 + ((v20 + 4) & 0xFFFFFFFC)];
      if ( v23 )
        v17 = v17 + *v23;
    }
  }
LABEL_23:
  if ( (_DWORD)v4 )
  {
    if ( (_DWORD)v4 == 4 )
      v9 = &v6->m_DuckedBusVolumeList;
  }
  else
  {
    v9 = &v6->m_DuckedVolumeList;
  }
  v24 = v9->m_pFirst;
  if ( v9->m_pFirst )
  {
    do
    {
      v3 = v3 + v24->Item.item.m_EffectiveVolumeOffset;
      v24 = v24->pNextListItem;
    }
    while ( v24 );
  }
  if ( v3 < v6->m_fMaxDuckVolume )
    v3 = v6->m_fMaxDuckVolume;
  v25 = (CAkBus *)v6->m_pBusOutputNode;
  v26 = v17 + v3;
  if ( v25 && (v5 == 1 || !CAkBus::IsMixingBus(v25)) )
    v26 = v26 + CAkBus::GetBusEffectiveVolume((CAkBus *)v6->m_pBusOutputNode, v5, (AkPropID)v4);
  return v26;
}

// File Line: 416
// RVA: 0xA7D310
void __fastcall CAkBus::SetAkProp(CAkBus *this, AkPropID in_eProp, float in_fValue, float in_fMin)
{
  __int64 v4; // rbx
  CAkBus *v5; // r10
  char *v6; // rdx
  AkPropBundle<AkPropValue> *v7; // rdi
  unsigned int v8; // er9
  int v9; // er8
  __int64 v10; // rcx
  signed __int64 v11; // rdx
  AkPropValue *v12; // rax
  char *v13; // r8
  unsigned int v14; // er9
  __int64 v15; // rcx
  __int64 v16; // rdx
  signed __int64 v17; // rdx
  AkPropValue *v18; // rax
  AkPropValue in_Value; // [rsp+58h] [rbp+10h]

  v4 = in_eProp;
  v5 = this;
  if ( (unsigned int)in_eProp > 4 )
  {
    if ( (unsigned int)(v4 - 11) > 2 )
    {
      CAkParameterNodeBase::SetAkProp((CAkParameterNodeBase *)&this->vfptr, in_eProp, in_fValue, in_fMin);
    }
    else
    {
      v13 = this->m_props.m_pProps;
      v7 = &this->m_props;
      in_Value.fValue = 0.0;
      if ( v13 )
      {
        v14 = (unsigned __int8)*v13;
        v15 = 0i64;
        while ( 1 )
        {
          v16 = (unsigned int)(v15 + 1);
          if ( v13[v16] == (_BYTE)v4 )
            break;
          v15 = (unsigned int)v16;
          if ( (unsigned int)v16 >= v14 )
            goto LABEL_17;
        }
        v17 = (signed __int64)&v13[4 * v15 + ((v14 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_17:
        v17 = 0i64;
      }
      v18 = &in_Value;
      if ( v17 )
        v18 = (AkPropValue *)v17;
      in_Value.fValue = v18->fValue;
      if ( (float)(in_fValue - in_Value.fValue) != 0.0 )
      {
        ((void (__fastcall *)(CAkBus *, CAkIndexableVtbl *, _QWORD, _QWORD, _QWORD))v5->vfptr[17].Release)(
          v5,
          v5->vfptr,
          (unsigned int)g_AkPropRTPCID[v4],
          0i64,
          0i64);
        goto LABEL_22;
      }
    }
  }
  else
  {
    v6 = this->m_props.m_pProps;
    v7 = &this->m_props;
    in_Value.fValue = 0.0;
    if ( v6 )
    {
      v8 = (unsigned __int8)*v6;
      v9 = 0;
      while ( 1 )
      {
        v10 = (unsigned int)(v9 + 1);
        if ( v6[v10] == (_BYTE)v4 )
          break;
        v9 = v10;
        if ( (unsigned int)v10 >= v8 )
          goto LABEL_6;
      }
      v11 = (signed __int64)&v6[4 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_6:
      v11 = 0i64;
    }
    v12 = &in_Value;
    if ( v11 )
      v12 = (AkPropValue *)v11;
    in_Value.fValue = v12->fValue;
    if ( (float)(in_fValue - in_Value.fValue) != 0.0 )
    {
      ((void (__fastcall *)(CAkBus *, _QWORD, CAkIndexableVtbl *, _QWORD, _QWORD))v5->vfptr[5].Release)(
        v5,
        (unsigned int)g_AkPropRTPCID[v4],
        v5->vfptr,
        0i64,
        0i64);
LABEL_22:
      AkPropBundle<AkPropValue>::SetAkProp(v7, v4, LODWORD(in_fValue));
      return;
    }
  }
}

// File Line: 447
// RVA: 0xA7C860
void __fastcall CAkBus::ParamNotification(CAkBus *this, NotifParams *in_rParams)
{
  bool v2; // zf
  NotifParams *v3; // r14
  CAkBus *v4; // rdi
  AkActivityChunk *v5; // rsi
  AkRTPC_ParameterID v6; // eax
  CAkParameterNodeBase **v7; // rbx
  AkActivityChunk *v8; // rax
  CAkParameterNodeBase **v9; // rbx
  AkActivityChunk *v10; // rax
  CAkParameterNodeBase **v11; // rbx
  AkActivityChunk *v12; // rax

  v2 = in_rParams->eType == 4;
  v3 = in_rParams;
  v4 = this;
  in_rParams->bIsFromBus = 1;
  if ( v2 && CAkBus::IsMixingBus(this) )
  {
    if ( v4->m_pBusOutputNode || *((_BYTE *)v4 + 304) >= 0 )
      CAkLEngine::SetBusVolume(v4->key, v3->fValue);
    else
      CAkLEngine::SetMasterBusVolume(*((_BYTE *)v4 + 304) >> 7, v3->fValue);
  }
  else
  {
    v5 = v4->m_pActivityChunk;
    if ( v5 && (v5->m_PlayCount || v5 && v5->m_uActivityCount) )
    {
      v6 = v3->eType;
      if ( v3->eType == 4 )
      {
        v7 = v4->m_mapBusChildId.m_pItems;
        v4->m_fEffectiveBusVolume = v3->fValue + v4->m_fEffectiveBusVolume;
        if ( v7 != &v7[v4->m_mapBusChildId.m_uLength] )
        {
          do
          {
            v8 = (*v7)->m_pActivityChunk;
            if ( v8 && (v8->m_PlayCount || v8 && v8->m_uActivityCount) )
              (*v7)->vfptr[5].__vecDelDtor((CAkIndexable *)&(*v7)->vfptr, (unsigned int)v3);
            ++v7;
          }
          while ( v7 != &v4->m_mapBusChildId.m_pItems[v4->m_mapBusChildId.m_uLength] );
        }
      }
      else if ( v6 )
      {
        if ( v6 == 33 )
        {
          *((_BYTE *)v4 + 304) |= 0x20u;
        }
        else if ( (v6 - 32) & 0xFFFFFFFD )
        {
          v11 = v5->m_ActiveChildren.m_pItems;
          if ( v11 != &v11[v5->m_ActiveChildren.m_uLength] )
          {
            do
            {
              v12 = (*v11)->m_pActivityChunk;
              if ( v12 && (v12->m_PlayCount || v12 && v12->m_uActivityCount) )
                (*v11)->vfptr[5].__vecDelDtor((CAkIndexable *)&(*v11)->vfptr, (unsigned int)v3);
              ++v11;
            }
            while ( v11 != &v5->m_ActiveChildren.m_pItems[v5->m_ActiveChildren.m_uLength] );
          }
        }
        else
        {
          *((_BYTE *)v4 + 304) |= 0x40u;
        }
      }
      else
      {
        v9 = v4->m_mapBusChildId.m_pItems;
        v4->m_fEffectiveVoiceVolume = v3->fValue + v4->m_fEffectiveVoiceVolume;
        if ( v9 != &v9[v4->m_mapBusChildId.m_uLength] )
        {
          do
          {
            v10 = (*v9)->m_pActivityChunk;
            if ( v10 && (v10->m_PlayCount || v10 && v10->m_uActivityCount) )
              (*v9)->vfptr[5].__vecDelDtor((CAkIndexable *)&(*v9)->vfptr, (unsigned int)v3);
            ++v9;
          }
          while ( v9 != &v4->m_mapBusChildId.m_pItems[v4->m_mapBusChildId.m_uLength] );
        }
      }
    }
  }
}

// File Line: 559
// RVA: 0xA7C5F0
void __usercall CAkBus::MuteNotification(CAkBus *this@<rcx>, float in_fMuteRatio@<xmm1>, AkMutedMapItem *in_rMutedItem@<r8>, __int64 in_bIsFromBus@<r9>, __int64 a5@<rdx>)
{
  AkActivityChunk *v5; // rdi
  AkMutedMapItem *v6; // rsi
  CAkParameterNodeBase **v7; // rbx
  AkActivityChunk *v8; // rax

  v5 = this->m_pActivityChunk;
  v6 = in_rMutedItem;
  if ( v5 )
  {
    v7 = v5->m_ActiveChildren.m_pItems;
    if ( v7 != &v7[v5->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v8 = (*v7)->m_pActivityChunk;
        if ( v8 )
        {
          if ( v8->m_PlayCount )
          {
            LOBYTE(in_bIsFromBus) = 1;
            ((void (__fastcall *)(CAkParameterNodeBase *, __int64, AkMutedMapItem *, __int64))(*v7)->vfptr[6].__vecDelDtor)(
              *v7,
              a5,
              v6,
              in_bIsFromBus);
          }
        }
        ++v7;
      }
      while ( v7 != &v5->m_ActiveChildren.m_pItems[v5->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 580
// RVA: 0xA7DC00
void __fastcall CAkBus::UpdateBusBypass(CAkBus *this, AkRTPC_ParameterID in_ParamID)
{
  CAkBus *v2; // rdi
  __int32 v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // edx
  CAkIndexableVtbl *v7; // rbx
  char v8; // al
  CAkIndexableVtbl *v9; // rbx
  bool v10; // al
  signed __int64 v11; // r8
  __int64 v12; // rdx
  bool v13; // al
  bool v14; // al
  bool v15; // al

  v2 = this;
  v3 = in_ParamID - 24;
  if ( !v3 )
  {
    v9 = this->vfptr;
    v15 = CAkBus::GetBypassFX(this, 0);
    v11 = 1i64;
    v12 = v15 != 0;
    goto LABEL_11;
  }
  v4 = v3 - 1;
  if ( !v4 )
  {
    v9 = this->vfptr;
    v14 = CAkBus::GetBypassFX(this, 1u);
    v11 = 2i64;
    v12 = 2 * (unsigned int)(v14 != 0);
    goto LABEL_11;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    v9 = this->vfptr;
    v13 = CAkBus::GetBypassFX(this, 2u);
    v11 = 4i64;
    v12 = 4 * (unsigned int)(v13 != 0);
    goto LABEL_11;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    v9 = this->vfptr;
    v10 = CAkBus::GetBypassFX(this, 3u);
    v11 = 8i64;
    v12 = 8 * (unsigned int)(v10 != 0);
LABEL_11:
    ((void (__fastcall *)(CAkBus *, __int64, signed __int64, _QWORD, _QWORD))v9[6].Category)(v2, v12, v11, 0i64, 0i64);
    return;
  }
  if ( v6 == 1 )
  {
    v7 = this->vfptr;
    v8 = ((__int64 (__fastcall *)(CAkBus *, _QWORD))this->vfptr[14].Release)(this, 0i64);
    ((void (__fastcall *)(CAkBus *, _QWORD, signed __int64))v7[6].Category)(v2, 16 * (unsigned int)(v8 != 0), 16i64);
  }
}

// File Line: 611
// RVA: 0xA7C680
void __fastcall CAkBus::NotifyBypass(CAkBus *this, unsigned int in_bitsFXBypass, unsigned int in_uTargetMask, CAkRegisteredObj *in_GameObj)
{
  if ( this->m_pBusOutputNode || *((_BYTE *)this + 304) >= 0 )
    CAkLEngine::BypassBusFx(this->key, in_bitsFXBypass, in_uTargetMask);
  else
    CAkLEngine::BypassMasterBusFx(in_bitsFXBypass, in_uTargetMask);
}

// File Line: 623
// RVA: 0xA7B0E0
signed __int64 __fastcall CAkBus::CanAddChild(CAkBus *this, CAkParameterNodeBase *in_pAudioNode)
{
  unsigned int v2; // ebx
  CAkBus *v3; // rdi
  signed __int64 result; // rax
  unsigned int v5; // esi

  v2 = 1;
  v3 = this;
  if ( in_pAudioNode->m_pBusOutputNode )
    return 21i64;
  if ( (*((_BYTE *)in_pAudioNode + 83) >> 1) & 1 )
  {
    v5 = in_pAudioNode->key;
    if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
           &this->m_mapBusChildId,
           in_pAudioNode->key) )
    {
      result = 5i64;
    }
    else
    {
      if ( v3->key == v5 )
        v2 = 23;
      result = v2;
    }
  }
  else if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
              &this->m_mapChildId,
              in_pAudioNode->key) )
  {
    result = 5i64;
  }
  else
  {
    result = 1i64;
  }
  return result;
}

// File Line: 648
// RVA: 0xA7B030
__int64 __fastcall CAkBus::AddChildInternal(CAkBus *this, CAkParameterNodeBase *pAudioNode)
{
  CAkParameterNodeBase *v2; // rbx
  CAkBus *v3; // rdi
  unsigned int v4; // esi
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *v5; // rcx
  CAkParameterNodeBase **v6; // rax

  v2 = pAudioNode;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr[20].__vecDelDtor)();
  if ( v4 == 1 )
  {
    v5 = &v3->m_mapBusChildId;
    if ( !(*((_BYTE *)v2 + 83) & 2) )
      v5 = &v3->m_mapChildId;
    v6 = AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::AddNoSetKey<unsigned long>(
           v5,
           v2->key);
    if ( v6 )
    {
      *v6 = v2;
      ((void (__fastcall *)(CAkParameterNodeBase *, CAkBus *))v2->vfptr[1].Category)(v2, v3);
      v3->vfptr->AddRef((CAkIndexable *)&v3->vfptr);
    }
    else
    {
      v4 = 2;
    }
  }
  v2->vfptr->Release((CAkIndexable *)&v2->vfptr);
  return v4;
}

// File Line: 679
// RVA: 0xA7AF70
__int64 __fastcall CAkBus::AddChild(CAkBus *this, WwiseObjectIDext in_ulID)
{
  CAkBus *v2; // rbx
  __int64 result; // rax
  CAkIndexable *v4; // rdx
  WwiseObjectIDext in_rIDext; // [rsp+38h] [rbp+10h]

  in_rIDext = in_ulID;
  v2 = this;
  if ( !in_ulID.id )
    return 14i64;
  v4 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &in_rIDext);
  if ( v4 )
    result = ((__int64 (__fastcall *)(CAkBus *, CAkIndexable *))v2->vfptr[2].AddRef)(v2, v4);
  else
    result = 15i64;
  return result;
}

// File Line: 693
// RVA: 0xA7CF20
void __fastcall CAkBus::RemoveChild(CAkBus *this, CAkParameterNodeBase *in_pChild)
{
  CAkParameterNodeBase *v2; // rdi
  CAkBus *v3; // rbx
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *v4; // rcx

  v2 = in_pChild;
  v3 = this;
  if ( (CAkBus *)in_pChild->m_pBusOutputNode == this )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))in_pChild->vfptr[1].Category)(in_pChild, 0i64);
    v4 = &v3->m_mapBusChildId;
    if ( !(*((_BYTE *)v2 + 83) & 2) )
      v4 = &v3->m_mapChildId;
    AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Unset<unsigned long>(
      v4,
      v2->key);
    v3->vfptr->Release((CAkIndexable *)&v3->vfptr);
  }
}

// File Line: 712
// RVA: 0xA7CF70
void __fastcall CAkBus::RemoveChild(CAkBus *this, WwiseObjectIDext in_ulID)
{
  CAkBus *v2; // rbx
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *v3; // rcx
  CAkParameterNodeBase **v4; // rdx

  v2 = this;
  if ( in_ulID.bIsBus )
    v3 = &this->m_mapBusChildId;
  else
    v3 = &this->m_mapChildId;
  v4 = AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         v3,
         in_ulID.id);
  if ( v4 )
    v2->vfptr[3].__vecDelDtor((CAkIndexable *)&v2->vfptr, (unsigned int)*v4);
}

// File Line: 830
// RVA: 0xA7B400
void __fastcall CAkBus::Duck(CAkBus *this, unsigned int in_BusID, float in_DuckVolume, int in_FadeOutTime, AkCurveInterpolation in_eFadeCurve, AkPropID in_PropID)
{
  CAkBus *v6; // rdi
  CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault> *v7; // rcx
  int in_lTransitionTime; // ebp
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v9; // rax
  CAkDuckItem *v10; // rbx
  CAkDuckItem *v11; // rax

  v6 = this;
  v7 = 0i64;
  in_lTransitionTime = in_FadeOutTime;
  if ( in_PropID )
  {
    if ( in_PropID == 4 )
      v7 = &v6->m_DuckedBusVolumeList;
  }
  else
  {
    v7 = &v6->m_DuckedVolumeList;
  }
  v9 = v7->m_pFirst;
  if ( !v7->m_pFirst )
    goto LABEL_10;
  while ( v9->Item.key != in_BusID )
  {
    v9 = v9->pNextListItem;
    if ( !v9 )
      goto LABEL_10;
  }
  v10 = &v9->Item.item;
  if ( v9 == (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)-16i64 )
  {
LABEL_10:
    v11 = CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault>::Set(v7, in_BusID);
    v10 = v11;
    if ( !v11 )
      return;
    CAkDuckItem::Init(v11, v6);
  }
  CAkBus::StartDuckTransitions(
    v6,
    v10,
    in_DuckVolume,
    AkValueMeaning_Offset,
    in_eFadeCurve,
    in_lTransitionTime,
    in_PropID);
}

// File Line: 897
// RVA: 0xA7CAD0
void __fastcall CAkBus::PauseDuck(CAkBus *this, unsigned int in_BusID, __int64 a3, __int64 a4)
{
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v4; // rax
  unsigned int v5; // ebx
  CAkBus *v6; // rdi
  CAkTransition *v7; // rdx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v8; // rax
  CAkTransition *v9; // rdx

  v4 = this->m_DuckedVolumeList.m_pFirst;
  v5 = in_BusID;
  v6 = this;
  if ( v4 )
  {
    while ( v4->Item.key != in_BusID )
    {
      v4 = v4->pNextListItem;
      if ( !v4 )
        goto LABEL_9;
    }
    if ( v4 != (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)-16i64 )
    {
      v7 = v4->Item.item.m_pvVolumeTransition;
      if ( v7 )
      {
        CAkTransitionManager::ChangeParameter(
          g_pTransitionManager,
          v7,
          0i64,
          v4->Item.item.m_EffectiveVolumeOffset,
          0,
          AkCurveInterpolation_Linear,
          AkValueMeaning_Independent);
      }
      else
      {
        LOBYTE(a4) = 1;
        ((void (__fastcall *)(CAkDuckItem *, _QWORD, __int64, __int64))v4->Item.item.vfptr->TransUpdateValue)(
          &v4->Item.item,
          0i64,
          a3,
          a4);
      }
    }
  }
LABEL_9:
  v8 = v6->m_DuckedBusVolumeList.m_pFirst;
  if ( v8 )
  {
    while ( v8->Item.key != v5 )
    {
      v8 = v8->pNextListItem;
      if ( !v8 )
        return;
    }
    if ( v8 != (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)-16i64 )
    {
      v9 = v8->Item.item.m_pvVolumeTransition;
      if ( v9 )
      {
        CAkTransitionManager::ChangeParameter(
          g_pTransitionManager,
          v9,
          4i64,
          v8->Item.item.m_EffectiveVolumeOffset,
          0,
          AkCurveInterpolation_Linear,
          AkValueMeaning_Independent);
      }
      else
      {
        LOBYTE(a4) = 1;
        ((void (__fastcall *)(CAkDuckItem *, signed __int64, __int64, __int64))v8->Item.item.vfptr->TransUpdateValue)(
          &v8->Item.item,
          4i64,
          a3,
          a4);
      }
    }
  }
}

// File Line: 918
// RVA: 0xA7D970
void __usercall CAkBus::StartDuckTransitions(CAkBus *this@<rcx>, CAkDuckItem *in_pDuckItem@<rdx>, float in_fTargetValue@<xmm2>, __int64 in_eValueMeaning@<r9>, __int64 a5@<r8>, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime, AkPropID in_ePropID)
{
  CAkDuckItem *v8; // rbx
  CAkTransition *v9; // rdx
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h]

  v8 = in_pDuckItem;
  v9 = in_pDuckItem->m_pvVolumeTransition;
  v10 = in_fTargetValue;
  if ( v9 )
  {
    CAkTransitionManager::ChangeParameter(
      g_pTransitionManager,
      v9,
      in_ePropID,
      in_fTargetValue,
      in_lTransitionTime,
      in_eFadeCurve,
      (AkValueMeaning)in_eValueMeaning);
  }
  else
  {
    v11 = v8->m_EffectiveVolumeOffset;
    v12 = 0.0;
    if ( (unsigned int)(in_eValueMeaning - 1) <= 1 )
      v12 = v10;
    if ( v11 != v12 && in_lTransitionTime )
    {
      in_Params.lDuration = in_lTransitionTime;
      in_Params.fStartValue = v11;
      in_Params.fTargetValue = v12;
      in_Params.eTarget = in_ePropID;
      LOBYTE(a5) = 1;
      in_Params.pUser = (ITransitionable *)&v8->vfptr;
      in_Params.eFadeCurve = in_eFadeCurve;
      *(_WORD *)&in_Params.bdBs = 257;
      v8->m_pvVolumeTransition = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, a5, 0i64);
    }
    else
    {
      LOBYTE(in_eValueMeaning) = 1;
      ((void (__fastcall *)(CAkDuckItem *, _QWORD, __int64, __int64))v8->vfptr->TransUpdateValue)(
        v8,
        in_ePropID,
        a5,
        in_eValueMeaning);
    }
  }
}

// File Line: 973
// RVA: 0xA7B0B0
void __fastcall CAkBus::ApplyMaxNumInstances(CAkBus *this, unsigned __int16 in_u16MaxNumInstance, CAkRegisteredObj *in_pGameObj, void *in_pExceptArray, bool in_bFromRTPC)
{
  AkActivityChunk *v5; // r8

  if ( !in_pGameObj && (!in_bFromRTPC || this->m_u16MaxNumInstance) )
  {
    v5 = this->m_pActivityChunk;
    if ( v5 )
      v5->m_Limiter.m_u16LimiterMax = in_u16MaxNumInstance;
    if ( !in_bFromRTPC )
      this->m_u16MaxNumInstance = in_u16MaxNumInstance;
  }
}

// File Line: 994
// RVA: 0xA7DA50
void __fastcall CAkBus::StopDucking(CAkBus *this)
{
  CAkBus *v1; // rbx

  v1 = this;
  if ( this->m_RecoveryTime && this->m_ToDuckList.m_ulNumListItems )
  {
    if ( (unsigned int)CAkBus::RequestDuckNotif(this) == 1 )
    {
      *((_BYTE *)v1 + 304) &= 0xF5u;
      *((_BYTE *)v1 + 304) |= 4u;
    }
    else
    {
      *((_BYTE *)v1 + 304) &= 0xF1u;
    }
    CAkBus::UpdateDuckedBus(v1);
  }
  else
  {
    *((_BYTE *)this + 304) &= 0xF1u;
    CAkBus::UpdateDuckedBus(this);
  }
}

// File Line: 1019
// RVA: 0xA7C220
__int64 __fastcall CAkBus::IncrementPlayCount(CAkBus *this, CounterParameters *io_params)
{
  CounterParameters *v2; // rsi
  CAkBus *v3; // rdi
  unsigned int v4; // eax
  unsigned int v5; // ebx
  CAkParameterNodeBase *v6; // rcx
  unsigned int v7; // eax
  CAkParameterNodeBase::AkFeedbackInfo *v8; // rax
  unsigned int v9; // eax
  AkActivityChunk *v10; // rax

  v2 = io_params;
  v3 = this;
  v4 = CAkParameterNodeBase::IncrementPlayCountValue(
         (CAkParameterNodeBase *)&this->vfptr,
         io_params->uiFlagForwardToBus);
  v5 = v4;
  if ( *((_BYTE *)&v3->0 + 82) & 8 || !v3->m_pBusOutputNode )
  {
    if ( !v2->bMaxConsidered && v4 == 1 )
      v5 = CAkParameterNodeBase::IncrementPlayCountGlobal(
             (CAkParameterNodeBase *)&v3->vfptr,
             v2->fPriority,
             &v2->ui16NumKicked,
             &v2->pBusLimiter);
    v2->bMaxConsidered = 1;
  }
  v6 = v3->m_pBusOutputNode;
  if ( v6 )
  {
    v7 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))v6->vfptr[8].Release)(v6, v2);
    if ( v7 != 1 )
    {
      if ( v7 == 80 )
      {
        if ( v5 == 1 )
          v5 = 80;
      }
      else
      {
        v5 = v7;
      }
    }
  }
  v8 = v3->m_pFeedbackInfo;
  if ( v8 )
  {
    if ( v8->m_pFeedbackBus )
    {
      v9 = ((__int64 (__fastcall *)(CAkFeedbackBus *, CounterParameters *))v8->m_pFeedbackBus->vfptr[8].Release)(
             v8->m_pFeedbackBus,
             v2);
      if ( v9 != 1 )
      {
        if ( v9 == 80 )
        {
          if ( v5 == 1 )
            v5 = 80;
        }
        else
        {
          v5 = v9;
        }
      }
    }
  }
  v10 = v3->m_pActivityChunk;
  if ( v10 && v10->m_PlayCount == 1 )
  {
    *((_BYTE *)v3 + 304) &= 0xF3u;
    *((_BYTE *)v3 + 304) |= 2u;
    CAkBus::UpdateDuckedBus(v3);
  }
  return v5;
}

// File Line: 1058
// RVA: 0xA7B2F0
void __fastcall CAkBus::DecrementPlayCount(CAkBus *this, CounterParameters *io_params)
{
  CounterParameters *v2; // rdi
  CAkBus *v3; // rbx
  CAkParameterNodeBase *v4; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *v5; // rax
  AkActivityChunk *v6; // rax

  v2 = io_params;
  v3 = this;
  CAkParameterNodeBase::DecrementPlayCountValue((CAkParameterNodeBase *)&this->vfptr);
  if ( (*((_BYTE *)&v3->0 + 82) & 8 || !v3->m_pBusOutputNode) && !v2->bMaxConsidered )
  {
    CAkParameterNodeBase::DecrementPlayCountGlobal((CAkParameterNodeBase *)&v3->vfptr);
    v2->bMaxConsidered = 1;
  }
  v4 = v3->m_pBusOutputNode;
  if ( v4 )
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))v4->vfptr[8].Category)(v4, v2);
  v5 = v3->m_pFeedbackInfo;
  if ( v5 && v5->m_pFeedbackBus )
    ((void (__fastcall *)(CAkFeedbackBus *, CounterParameters *))v5->m_pFeedbackBus->vfptr[8].Category)(
      v5->m_pFeedbackBus,
      v2);
  v6 = v3->m_pActivityChunk;
  if ( !v6 || !v6->m_PlayCount )
    CAkBus::StopDucking(v3);
}

// File Line: 1093
// RVA: 0xA7C320
void __fastcall CAkBus::IncrementVirtualCount(CAkBus *this, CounterParameters *io_params)
{
  CounterParameters *v2; // rdi
  CAkBus *v3; // rbx
  AkActivityChunk *v4; // rax
  CAkParameterNodeBase *v5; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *v6; // rcx
  CAkFeedbackBus *v7; // rcx

  v2 = io_params;
  v3 = this;
  if ( *((_BYTE *)&this->0 + 82) & 8 || !this->m_pBusOutputNode )
  {
    if ( !io_params->bMaxConsidered )
    {
      v4 = this->m_pActivityChunk;
      if ( v4 )
        ++v4->m_iVirtualCountValid;
    }
    io_params->bMaxConsidered = 1;
  }
  v5 = this->m_pBusOutputNode;
  if ( v5 )
    ((void (*)(void))v5->vfptr[9].__vecDelDtor)();
  v6 = v3->m_pFeedbackInfo;
  if ( v6 )
  {
    v7 = v6->m_pFeedbackBus;
    if ( v7 )
      v7->vfptr[9].__vecDelDtor((CAkIndexable *)&v7->vfptr, (unsigned int)v2);
  }
}

// File Line: 1119
// RVA: 0xA7B380
void __fastcall CAkBus::DecrementVirtualCount(CAkBus *this, CounterParameters *io_params)
{
  CounterParameters *v2; // rdi
  CAkBus *v3; // rbx
  CAkParameterNodeBase *v4; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *v5; // rcx
  CAkFeedbackBus *v6; // rcx

  v2 = io_params;
  v3 = this;
  if ( (*((_BYTE *)&this->0 + 82) & 8 || !this->m_pBusOutputNode) && !io_params->bMaxConsidered )
  {
    CAkParameterNodeBase::DecrementVirtualCountGlobal(
      (CAkParameterNodeBase *)&this->vfptr,
      &io_params->ui16NumKicked,
      io_params->bAllowKick);
    v2->bMaxConsidered = 1;
  }
  v4 = v3->m_pBusOutputNode;
  if ( v4 )
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))v4->vfptr[9].AddRef)(v4, v2);
  v5 = v3->m_pFeedbackInfo;
  if ( v5 )
  {
    v6 = v5->m_pFeedbackBus;
    if ( v6 )
      ((void (__fastcall *)(CAkFeedbackBus *, CounterParameters *))v6->vfptr[9].AddRef)(v6, v2);
  }
}

// File Line: 1143
// RVA: 0xA7C1B0
char __fastcall CAkBus::IncrementActivityCount(CAkBus *this, unsigned __int16 in_flagForwardToBus)
{
  CAkBus *v2; // rdi
  char v3; // al
  CAkParameterNodeBase *v4; // rcx
  char v5; // bl
  CAkParameterNodeBase::AkFeedbackInfo *v6; // rcx
  CAkFeedbackBus *v7; // rcx
  char result; // al

  v2 = this;
  v3 = CAkParameterNodeBase::IncrementActivityCountValue((CAkParameterNodeBase *)&this->vfptr, in_flagForwardToBus);
  v4 = v2->m_pBusOutputNode;
  v5 = v3;
  if ( v4 )
    v5 = (unsigned __int64)((__int64 (__fastcall *)(CAkParameterNodeBase *, signed __int64))v4->vfptr[9].Release)(
                             v4,
                             3i64) & v3;
  v6 = v2->m_pFeedbackInfo;
  if ( v6 && (v7 = v6->m_pFeedbackBus) != 0i64 )
    result = v5 & (unsigned __int64)((__int64 (__fastcall *)(CAkFeedbackBus *, signed __int64))v7->vfptr[9].Release)(
                                      v7,
                                      3i64);
  else
    result = v5;
  return result;
}

// File Line: 1162
// RVA: 0xA7B2A0
void __fastcall CAkBus::DecrementActivityCount(CAkBus *this, unsigned __int16 __formal)
{
  CAkBus *v2; // rbx
  CAkParameterNodeBase *v3; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *v4; // rcx
  CAkFeedbackBus *v5; // rcx

  v2 = this;
  CAkParameterNodeBase::DecrementActivityCountValue((CAkParameterNodeBase *)&this->vfptr);
  v3 = v2->m_pBusOutputNode;
  if ( v3 )
    ((void (__fastcall *)(CAkParameterNodeBase *, signed __int64))v3->vfptr[9].Category)(v3, 3i64);
  v4 = v2->m_pFeedbackInfo;
  if ( v4 )
  {
    v5 = v4->m_pFeedbackBus;
    if ( v5 )
      ((void (__fastcall *)(CAkFeedbackBus *, signed __int64))v5->vfptr[9].Category)(v5, 3i64);
  }
}

// File Line: 1179
// RVA: 0xA7C560
char __fastcall CAkBus::IsOrIsChildOf(CAkBus *this, CAkParameterNodeBase *in_pNodeToTest)
{
  if ( !this )
    return 0;
  while ( in_pNodeToTest != (CAkParameterNodeBase *)this )
  {
    this = (CAkBus *)this->m_pBusOutputNode;
    if ( !this )
      return 0;
  }
  return 1;
}

// File Line: 1191
// RVA: 0xA7B4D0
void __fastcall CAkBus::DuckNotif(CAkBus *this)
{
  char v1; // dl

  v1 = *((_BYTE *)this + 304);
  if ( (v1 & 0xE) == 4 )
  {
    *((_BYTE *)this + 304) = v1 & 0xF1;
    CAkBus::UpdateDuckedBus(this);
  }
}

// File Line: 1200
// RVA: 0xA7DD00
void __fastcall CAkBus::UpdateDuckedBus(CAkBus *this)
{
  CAkList2<MapStruct<unsigned long,CAkBus::AkDuckInfo>,MapStruct<unsigned long,CAkBus::AkDuckInfo> const &,1,ArrayPoolDefault>::ListItem *v1; // rbx
  CAkBus *i; // rsi
  CAkBus *v3; // rax
  __int64 v4; // r8
  __int64 v5; // r9
  CAkBus *v6; // rdi
  __int64 v7; // r8
  CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault> *v8; // rax
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v9; // rax

  v1 = this->m_ToDuckList.m_pFirst;
  for ( i = this; v1; v1 = v1->pNextListItem )
  {
    v3 = (CAkBus *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v1->Item.key, AkNodeType_Bus);
    v6 = v3;
    if ( v3 )
    {
      if ( ((unsigned int)*((unsigned __int8 *)i + 304) >> 1) & 7 )
      {
        if ( (((unsigned int)*((unsigned __int8 *)i + 304) >> 1) & 7) == 1 )
        {
          CAkBus::Duck(
            v3,
            i->key,
            v1->Item.item.DuckVolume,
            v1->Item.item.FadeOutTime,
            v1->Item.item.FadeCurve,
            v1->Item.item.TargetProp);
        }
        else if ( (((unsigned int)*((unsigned __int8 *)i + 304) >> 1) & 7) == 2 )
        {
          CAkBus::PauseDuck(v3, i->key, v4, v5);
        }
      }
      else
      {
        v7 = (unsigned int)v1->Item.item.TargetProp;
        v8 = 0i64;
        if ( (_DWORD)v7 )
        {
          if ( (_DWORD)v7 == 4 )
            v8 = &v6->m_DuckedBusVolumeList;
        }
        else
        {
          v8 = &v6->m_DuckedVolumeList;
        }
        v9 = v8->m_pFirst;
        if ( v9 )
        {
          while ( v9->Item.key != i->key )
          {
            v9 = v9->pNextListItem;
            if ( !v9 )
              goto LABEL_18;
          }
          if ( v9 != (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)-16i64 )
            CAkBus::StartDuckTransitions(
              v6,
              &v9->Item.item,
              0.0,
              0i64,
              v7,
              v1->Item.item.FadeCurve,
              v1->Item.item.FadeInTime,
              v1->Item.item.TargetProp);
        }
      }
LABEL_18:
      v6->vfptr->Release((CAkIndexable *)&v6->vfptr);
    }
  }
}

// File Line: 1230
// RVA: 0xA7CFB0
signed __int64 __fastcall CAkBus::RequestDuckNotif(CAkBus *this)
{
  CAkBus *v1; // rsi
  unsigned int v2; // edi
  CAkActionDuck *v3; // rax
  CAkAction *v4; // rax
  CAkAction *v5; // rbx
  int v6; // ST20_4
  AkPendingAction *v7; // rax
  AkPendingAction *v8; // rax
  __int64 v10; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = 2;
  v3 = (CAkActionDuck *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  if ( !v3 )
    return 2i64;
  CAkActionDuck::CAkActionDuck(v3, AkActionType_Duck, 0);
  v5 = v4;
  if ( v4 )
  {
    v6 = 0;
    if ( ((unsigned int (__fastcall *)(CAkAction *, signed __int64, _QWORD, _QWORD, int))v4->vfptr[1].Release)(
           v4,
           14i64,
           v1->m_RecoveryTime,
           0i64,
           v6) == 1 )
    {
      BYTE4(v10) = 1;
      LODWORD(v10) = v1->key;
      ((void (__fastcall *)(CAkAction *, __int64))v5->vfptr[1].AddRef)(v5, v10);
      v7 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
      if ( v7 )
      {
        AkPendingAction::AkPendingAction(v7, 0i64);
        if ( v8 )
        {
          v8->pAction = v5;
          CAkAudioMgr::EnqueueOrExecuteAction(g_pAudioMgr, v8);
          v2 = 1;
        }
      }
    }
    v5->vfptr->Release((CAkIndexable *)&v5->vfptr);
  }
  return v2;
}

// File Line: 1256
// RVA: 0xA7B190
void __fastcall CAkBus::CheckDuck(CAkBus *this)
{
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v1; // rax
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *i; // rax

  v1 = this->m_DuckedVolumeList.m_pFirst;
  if ( v1 )
  {
    while ( v1->Item.item.m_EffectiveVolumeOffset >= -0.0099999998 )
    {
      v1 = v1->pNextListItem;
      if ( !v1 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    for ( i = this->m_DuckedBusVolumeList.m_pFirst; i; i = i->pNextListItem )
    {
      if ( i->Item.item.m_EffectiveVolumeOffset < -0.0099999998 )
        break;
    }
  }
}

// File Line: 1287
// RVA: 0xA7BDA0
float __fastcall CAkBus::GetDuckedVolume(CAkBus *this, AkPropID in_eProp)
{
  CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault> *v2; // rax
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v3; // rax
  float result; // xmm0_4

  v2 = 0i64;
  if ( in_eProp )
  {
    if ( in_eProp == 4 )
      v2 = &this->m_DuckedBusVolumeList;
  }
  else
  {
    v2 = &this->m_DuckedVolumeList;
  }
  v3 = v2->m_pFirst;
  for ( result = 0.0; v3; v3 = v3->pNextListItem )
    result = result + v3->Item.item.m_EffectiveVolumeOffset;
  if ( result < this->m_fMaxDuckVolume )
    result = this->m_fMaxDuckVolume;
  return result;
}

// File Line: 1318
// RVA: 0xA7BF70
CAkBus *__fastcall CAkBus::GetMixingBus(CAkBus *this)
{
  CAkParameterNodeBase::FXChunk *v1; // rax
  CAkBus *v2; // rbx
  unsigned int v3; // edx
  unsigned int *v4; // rax
  char v5; // al

  v1 = this->m_pFXChunk;
  v2 = this;
  if ( v1 )
  {
    v3 = 0;
    v4 = &v1->aFX[0].id;
    while ( !*v4 )
    {
      ++v3;
      v4 += 2;
      if ( v3 >= 4 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    if ( ((unsigned int (*)(void))this->vfptr[3].Release)() != 12 && !v2->m_uChannelConfig )
    {
      v5 = *((_BYTE *)&v2->0 + 83);
      if ( !(v5 & 4) && v2->m_pBusOutputNode && !(v5 & 8) )
        return CAkParameterNodeBase::GetMixingBus((CAkParameterNodeBase *)&v2->vfptr);
    }
  }
  if ( v2 != g_MasterBusCtx.m_pBus )
    return v2;
  return CAkParameterNodeBase::GetMixingBus((CAkParameterNodeBase *)&v2->vfptr);
}

// File Line: 1327
// RVA: 0xA7BF60
CAkBus *__fastcall CAkBus::GetLimitingBus(CAkBus *this)
{
  CAkBus *result; // rax

  if ( *((_BYTE *)&this->0 + 82) & 8 )
    result = this;
  else
    result = CAkParameterNodeBase::GetLimitingBus((CAkParameterNodeBase *)&this->vfptr);
  return result;
}

// File Line: 1338
// RVA: 0xA7DE30
void __fastcall CAkBus::UpdateFx(CAkBus *this, unsigned int in_uFXIndex)
{
  if ( this->m_pBusOutputNode || *((_BYTE *)this + 304) >= 0 )
    CAkLEngine::UpdateMixBusFX(this->key, in_uFXIndex);
  else
    CAkLEngine::UpdateMasterBusFX(in_uFXIndex);
}

// File Line: 1358
// RVA: 0xA7C4F0
char __fastcall CAkBus::IsMixingBus(CAkBus *this)
{
  CAkParameterNodeBase::FXChunk *v1; // rax
  CAkBus *v2; // rbx
  unsigned int v3; // edx
  unsigned int *v4; // rax
  char v5; // cl

  v1 = this->m_pFXChunk;
  v2 = this;
  if ( v1 )
  {
    v3 = 0;
    v4 = &v1->aFX[0].id;
    while ( !*v4 )
    {
      ++v3;
      v4 += 2;
      if ( v3 >= 4 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    if ( ((unsigned int (*)(void))this->vfptr[3].Release)() != 12 && !v2->m_uChannelConfig )
    {
      v5 = *((_BYTE *)&v2->0 + 83);
      if ( !(v5 & 4) && v2->m_pBusOutputNode && !(v5 & 8) )
        return 0;
    }
  }
  return 1;
}

// File Line: 1375
// RVA: 0xA7C580
_BOOL8 __fastcall CAkBus::IsTopBus(CAkBus *this)
{
  return this->m_pBusOutputNode == 0i64;
}

// File Line: 1380
// RVA: 0xA7D5F0
signed __int64 __fastcall CAkBus::SetInitialParams(CAkBus *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  CAkBus *v3; // rdi
  char **v4; // rsi
  signed __int64 result; // rax
  char v6; // cl
  char v7; // cl
  char v8; // cl
  char *v9; // rax
  char v10; // bl
  unsigned __int16 v11; // cx
  __int16 v12; // cx

  v3 = this;
  v4 = io_rpData;
  result = AkPropBundle<AkPropValue>::SetInitialParams(&this->m_props, io_rpData, io_rulDataSize);
  if ( (_DWORD)result == 1 )
  {
    v6 = *(*v4)++;
    *((_BYTE *)&v3->0 + 83) &= 0xFBu;
    *((_BYTE *)&v3->0 + 83) |= 4 * (v6 != 0);
    v7 = *(*v4)++;
    *((_BYTE *)&v3->0 + 83) &= 0xDFu;
    *((_BYTE *)&v3->0 + 83) |= 32 * (v7 != 0);
    v8 = **v4;
    v9 = *v4 + 1;
    *v4 = v9;
    v10 = *v9;
    *v4 = v9 + 1;
    CAkParameterNodeBase::SetMaxReachedBehavior((CAkParameterNodeBase *)&v3->vfptr, v8 != 0);
    CAkParameterNodeBase::SetOverLimitBehavior((CAkParameterNodeBase *)&v3->vfptr, v10 != 0);
    v11 = *(_WORD *)*v4;
    *v4 += 2;
    v3->m_u16MaxNumInstance = v11;
    LOBYTE(v11) = *(*v4)++;
    *((_BYTE *)&v3->0 + 82) &= 0xF7u;
    *((_BYTE *)&v3->0 + 82) |= 8 * (v11 & 1);
    v12 = *(_WORD *)*v4;
    *v4 += 2;
    *((_BYTE *)&v3->0 + 82) |= 0x80u;
    v3->m_uChannelConfig = v12 & 0x63F;
    *v4 += 2;
    LOBYTE(v12) = *(*v4)++;
    *((_BYTE *)&v3->0 + 83) &= 0xF7u;
    *((_BYTE *)&v3->0 + 83) |= 8 * (v12 & 1);
    LOBYTE(v12) = *(*v4)++;
    *((_BYTE *)v3 + 304) &= 0xEFu;
    result = 1i64;
    *((_BYTE *)v3 + 304) |= 16 * (v12 & 1);
  }
  return result;
}

// File Line: 1427
// RVA: 0xA7D720
signed __int64 __fastcall CAkBus::SetInitialValues(CAkBus *this, char *in_pData, unsigned int in_ulDataSize)
{
  CAkBus *v3; // rbx
  unsigned int v4; // eax
  CAkIndexable *v5; // rdi
  unsigned int v6; // esi
  signed __int64 result; // rax
  int v8; // ecx
  char *v9; // r8
  unsigned int v10; // edi
  float v11; // xmm0_4
  char *v12; // r8
  unsigned int v13; // er13
  unsigned int v14; // edx
  char *v15; // r8
  float v16; // xmm6_4
  int v17; // esi
  int v18; // er14
  unsigned __int8 v19; // r15
  unsigned __int8 v20; // r12
  CAkBus::AkDuckInfo *v21; // rax
  char *io_rpData; // [rsp+78h] [rbp+30h]
  unsigned int io_rulDataSize; // [rsp+80h] [rbp+38h]

  io_rulDataSize = in_ulDataSize;
  v3 = this;
  io_rpData = in_pData + 4;
  v4 = *((_DWORD *)in_pData + 1);
  io_rpData = in_pData + 8;
  if ( v4 )
  {
    v5 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v4, AkNodeType_Bus);
    if ( !v5 )
      return 2i64;
    v3->vfptr->AddRef((CAkIndexable *)&v3->vfptr);
    v6 = ((__int64 (__fastcall *)(CAkIndexable *, CAkBus *))v5->vfptr[2].AddRef)(v5, v3);
    v5->vfptr->Release(v5);
    if ( v6 != 1 )
      return v6;
  }
  else if ( g_MasterBusCtx.m_pBus )
  {
    if ( !g_SecondaryMasterBusCtx.m_pBus && g_MasterBusCtx.m_pBus != this )
    {
      g_SecondaryMasterBusCtx.m_pBus = this;
      *((_BYTE *)this + 304) &= 0x7Fu;
    }
  }
  else
  {
    g_MasterBusCtx.m_pBus = this;
    *((_BYTE *)this + 304) |= 0x80u;
  }
  result = ((__int64 (__fastcall *)(CAkBus *, char **, unsigned int *))v3->vfptr[17].Category)(
             v3,
             &io_rpData,
             &io_rulDataSize);
  if ( (_DWORD)result == 1 )
  {
    v8 = *(_DWORD *)io_rpData;
    v9 = io_rpData + 4;
    io_rpData = v9;
    v9 += 4;
    v10 = 0;
    v3->m_RecoveryTime = v8 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
    v11 = *((float *)v9 - 1);
    io_rpData = v9;
    v12 = v9 + 4;
    v3->m_fMaxDuckVolume = v11;
    v13 = *((_DWORD *)v12 - 1);
    io_rpData = v12;
    if ( v13 )
    {
      while ( 1 )
      {
        v14 = *(_DWORD *)v12;
        v15 = v12 + 4;
        io_rpData = v15;
        v15 += 4;
        v16 = *((float *)v15 - 1);
        io_rpData = v15;
        v17 = *(_DWORD *)v15;
        v15 += 4;
        io_rpData = v15;
        v15 += 4;
        v18 = *((_DWORD *)v15 - 1);
        io_rpData = v15;
        v19 = *v15++;
        io_rpData = v15++;
        v20 = *(v15 - 1);
        io_rpData = v15;
        v21 = CAkKeyList<unsigned long,CAkBus::AkDuckInfo,1,ArrayPoolDefault>::Set(&v3->m_ToDuckList, v14);
        if ( !v21 )
          break;
        ++v10;
        v21->DuckVolume = v16;
        v21->FadeCurve = v19;
        v21->FadeInTime = v18;
        v21->FadeOutTime = v17;
        v21->TargetProp = v20;
        if ( v10 >= v13 )
          goto LABEL_17;
        v12 = io_rpData;
      }
      result = 2i64;
    }
    else
    {
LABEL_17:
      result = ((__int64 (__fastcall *)(CAkBus *, char **, unsigned int *, _QWORD))v3->vfptr[18].__vecDelDtor)(
                 v3,
                 &io_rpData,
                 &io_rulDataSize,
                 0i64);
      if ( (_DWORD)result == 1 )
      {
        result = CAkParameterNodeBase::SetInitialRTPC((CAkParameterNodeBase *)&v3->vfptr, &io_rpData, &io_rulDataSize);
        if ( (_DWORD)result == 1 )
        {
          result = CAkParameterNodeBase::ReadStateChunk((CAkParameterNodeBase *)&v3->vfptr, &io_rpData, &io_rulDataSize);
          if ( (_DWORD)result == 1 )
            result = CAkParameterNodeBase::ReadFeedbackInfo(
                       (CAkParameterNodeBase *)&v3->vfptr,
                       &io_rpData,
                       &io_rulDataSize);
        }
      }
    }
  }
  return result;
}

// File Line: 1523
// RVA: 0xA7D530
__int64 __fastcall CAkBus::SetInitialFxParams(CAkBus *this, char **io_rpData, unsigned int *io_rulDataSize, bool __formal)
{
  char **v4; // rdi
  CAkBus *v5; // r14
  unsigned int v6; // er8
  char *v7; // rax
  unsigned int v8; // ebp
  unsigned int v9; // esi
  char *v10; // rax
  unsigned int v11; // er15
  unsigned int v12; // ebx
  char *v13; // rax
  unsigned __int8 v14; // cl
  unsigned int v15; // er8
  char v16; // dl

  v4 = io_rpData;
  v5 = this;
  v6 = (unsigned __int8)**io_rpData;
  v7 = *io_rpData + 1;
  v8 = 1;
  *io_rpData = v7;
  v9 = v6;
  if ( (_BYTE)v6 )
  {
    v10 = v7 + 1;
    v11 = (unsigned __int8)*(v10 - 1);
    v12 = 0;
    *io_rpData = v10;
    if ( v6 )
    {
      do
      {
        v13 = *v4 + 1;
        v14 = **v4;
        *v4 = v13;
        v13 += 4;
        v15 = *((_DWORD *)v13 - 1);
        *v4 = v13;
        v16 = *v13;
        *v4 = v13 + 2;
        if ( v15 )
        {
          v8 = CAkParameterNodeBase::SetFX((CAkParameterNodeBase *)&v5->vfptr, v14, v15, v16 != 0);
          if ( v8 != 1 )
            break;
        }
        ++v12;
      }
      while ( v12 < v9 );
    }
    CAkParameterNodeBase::MainBypassFX((CAkParameterNodeBase *)&v5->vfptr, v11, 0xFFFFFFFF);
  }
  return v8;
}

// File Line: 1556
// RVA: 0xA7DEF0
void __fastcall CAkBus::_SetInMainHierarchy(CAkBus *this, bool in_bIsInMainHierarchy)
{
  CAkParameterNodeBase **v2; // rbx
  CAkBus *v3; // rdi
  bool v4; // si

  *((_BYTE *)this + 304) &= 0x7Fu;
  v2 = this->m_mapBusChildId.m_pItems;
  v3 = this;
  v4 = in_bIsInMainHierarchy;
  *((_BYTE *)this + 304) |= in_bIsInMainHierarchy << 7;
  if ( v2 != &v2[this->m_mapBusChildId.m_uLength] )
  {
    do
    {
      CAkBus::_SetInMainHierarchy((CAkBus *)*v2, v4);
      ++v2;
    }
    while ( v2 != &v3->m_mapBusChildId.m_pItems[v3->m_mapBusChildId.m_uLength] );
  }
}

// File Line: 1570
// RVA: 0xA7CA80
void __fastcall CAkBus::ParentBus(CAkBus *this, CAkParameterNodeBase *in_pParent)
{
  CAkParameterNodeBase *v2; // rdi
  CAkBus *v3; // rbx
  char v4; // dl

  v2 = in_pParent;
  v3 = this;
  FaceInteractionResultSetTrack::ResolveReferences((CAkParameterNodeBase *)&this->vfptr, in_pParent);
  if ( v2 )
  {
    v4 = LOBYTE(v2[2].m_pFeedbackInfo) >> 7;
    if ( *((_BYTE *)v3 + 304) >> 7 != v4 )
      CAkBus::_SetInMainHierarchy(v3, v4);
  }
}

// File Line: 1589
// RVA: 0xA7C150
char __fastcall CAkBus::GetStateSyncTypes(CAkBus *this, unsigned int in_stateGroupID, CAkParameterNodeBase::CAkStateSyncArray *io_pSyncTypes)
{
  CAkParameterNodeBase::CAkStateSyncArray *v3; // rdi
  unsigned int v4; // esi
  CAkBus *v5; // rbx

  v3 = io_pSyncTypes;
  v4 = in_stateGroupID;
  v5 = this;
  if ( CAkParameterNodeBase::CheckSyncTypes((CAkParameterNodeBase *)&this->vfptr, in_stateGroupID, io_pSyncTypes) )
    return 1;
  while ( 1 )
  {
    v5 = (CAkBus *)v5->m_pBusOutputNode;
    if ( !v5 )
      break;
    if ( CAkParameterNodeBase::CheckSyncTypes((CAkParameterNodeBase *)&v5->vfptr, v4, v3) )
      return 1;
  }
  return 0;
}

// File Line: 1608
// RVA: 0xA7BDF0
void __fastcall CAkBus::GetFX(CAkBus *this, __int64 in_uFXIndex, AkFXDesc *out_rFXInfo, CAkRegisteredObj *__formal)
{
  AkFXDesc *v4; // rbx
  CAkParameterNodeBase::FXChunk *v5; // r8
  __int64 v6; // rdi
  CAkBus *v7; // rsi
  unsigned int v8; // edx
  CAkIndexable *v9; // rax
  CAkFxBase *v10; // rcx
  CAkFxBase *v11; // rcx

  v4 = out_rFXInfo;
  v5 = this->m_pFXChunk;
  v6 = (unsigned int)in_uFXIndex;
  v7 = this;
  if ( v5 )
  {
    v8 = v5->aFX[(unsigned int)in_uFXIndex].id;
    if ( v8 )
    {
      if ( v5->aFX[v6].bShareSet )
        v9 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(&g_pIndex->m_idxFxShareSets, v8);
      else
        v9 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
               (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
               v8);
      v10 = v4->pFx.m_pT;
      v4->pFx.m_pT = (CAkFxBase *)v9;
    }
    else
    {
      v10 = v4->pFx.m_pT;
      v4->pFx.m_pT = 0i64;
    }
    if ( v10 )
      ((void (*)(void))v10->vfptr->Release)();
    v4->bIsBypassed = CAkBus::GetBypassFX(v7, v6);
  }
  else
  {
    v11 = v4->pFx.m_pT;
    v4->pFx.m_pT = 0i64;
    if ( v11 )
      ((void (__fastcall *)(CAkFxBase *, __int64, _QWORD, CAkRegisteredObj *))v11->vfptr->Release)(
        v11,
        in_uFXIndex,
        0i64,
        __formal);
    v4->bIsBypassed = 0;
  }
}

// File Line: 1640
// RVA: 0xA7BEB0
void __fastcall CAkBus::GetFXDataID(CAkBus *this, unsigned int in_uFXIndex, unsigned int in_uDataIndex, unsigned int *out_rDataID)
{
  unsigned int v4; // ebx
  CAkParameterNodeBase::FXChunk *v5; // r8
  unsigned int *v6; // rdi
  bool v7; // zf
  unsigned int v8; // edx
  CAkIndexable *v9; // rax
  unsigned int *v10; // rdx
  _DWORD *v11; // rax
  signed __int64 v12; // rcx
  unsigned int *v13; // rax
  unsigned int v14; // ecx

  v4 = in_uDataIndex;
  *out_rDataID = -1;
  v5 = this->m_pFXChunk;
  v6 = out_rDataID;
  if ( v5 )
  {
    v7 = v5->aFX[in_uFXIndex].bShareSet == 0;
    v8 = v5->aFX[in_uFXIndex].id;
    v9 = v7 ? CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
                v8) : CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(&g_pIndex->m_idxFxShareSets, v8);
    v10 = (unsigned int *)v9;
    if ( v9 )
    {
      v11 = *(_DWORD **)&v9[1].key;
      v12 = (signed __int64)&v11[2 * v10[12]];
      if ( v11 == (_DWORD *)v12 )
        goto LABEL_16;
      do
      {
        if ( *v11 == v4 )
          break;
        v11 += 2;
      }
      while ( v11 != (_DWORD *)v12 );
      if ( v11 != (_DWORD *)v12 && (v13 = v11 + 1) != 0i64 )
        v14 = *v13;
      else
LABEL_16:
        v14 = 0;
      *v6 = v14;
      (*(void (__fastcall **)(unsigned int *))(*(_QWORD *)v10 + 16i64))(v10);
    }
  }
}

// File Line: 1664
// RVA: 0xA7BC30
bool __fastcall CAkBus::GetBypassFX(CAkBus *this, unsigned int in_uFXIndex)
{
  CAkParameterNodeBase::FXChunk *v2; // r9
  __int64 v3; // r8
  _BOOL8 v4; // rax
  char v5; // dl
  unsigned __int64 v6; // rax
  CAkSIS *v7; // rax

  v2 = this->m_pFXChunk;
  v3 = in_uFXIndex;
  if ( v2 )
  {
    v5 = ((unsigned __int8)v2->bitsMainFXBypass >> in_uFXIndex) & 1;
    if ( v2->aFX[v3].id
      && (v6 = this->m_RTPCBitArray.m_iBitArray, _bittest64((const signed __int64 *)&v6, (unsigned __int8)(v3 + 24))) )
    {
      v4 = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, v3 + 24, 0i64) != 0.0;
    }
    else
    {
      v7 = this->m_pGlobalSIS;
      if ( v7 )
        v5 = ((unsigned __int8)v7->m_bitsFXBypass >> v3) & 1;
      LOBYTE(v4) = v5;
    }
  }
  else
  {
    LOBYTE(v4) = 0;
  }
  return v4;
}

// File Line: 1685
// RVA: 0xA7BBC0
bool __fastcall CAkBus::GetBypassAllFX(CAkBus *this, CAkRegisteredObj *__formal)
{
  CAkParameterNodeBase::FXChunk *v2; // rax
  bool v3; // dl
  bool result; // al
  CAkSIS *v5; // rax

  v2 = this->m_pFXChunk;
  v3 = v2 && v2->bitsMainFXBypass & 0x10;
  if ( ((unsigned __int64)LODWORD(this->m_RTPCBitArray.m_iBitArray) >> 28) & 1 )
    return CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x1Cu, 0i64) != 0.0;
  v5 = this->m_pGlobalSIS;
  if ( v5 )
    result = ((unsigned __int8)v5->m_bitsFXBypass >> 4) & 1;
  else
    result = v3;
  return result;
}

// File Line: 1705
// RVA: 0xA7D140
void __fastcall CAkBus::ResetFXBypass(CAkBus *this, unsigned int in_bitsFXBypass, unsigned int in_uTargetMask)
{
  CAkSIS *v3; // rax

  v3 = this->m_pGlobalSIS;
  if ( v3 )
    v3->m_bitsFXBypass = in_bitsFXBypass | v3->m_bitsFXBypass & ~(_BYTE)in_uTargetMask;
}

// File Line: 1720
// RVA: 0xA7D4C0
void __fastcall CAkBus::SetAkProp(CAkBus *this, AkPropID in_eProp, CAkRegisteredObj *in_pGameObj, AkValueMeaning in_eValueMeaning, float in_fTargetValue, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  AkPropID v7; // esi
  AkValueMeaning v8; // edi
  CAkBus *v9; // rbx
  CAkSIS *v10; // rax

  v7 = in_eProp;
  v8 = in_eValueMeaning;
  v9 = this;
  v10 = (CAkSIS *)((__int64 (__fastcall *)(CAkBus *, _QWORD, CAkRegisteredObj *))this->vfptr[19].__vecDelDtor)(
                    this,
                    0i64,
                    in_pGameObj);
  if ( v10 )
    CAkParameterNodeBase::StartSISTransition(
      (CAkParameterNodeBase *)&v9->vfptr,
      v10,
      v7,
      in_fTargetValue,
      v8,
      in_eFadeCurve,
      in_lTransitionTime);
}

// File Line: 1784
// RVA: 0xA7D0A0
void __fastcall CAkBus::ResetAkProp(CAkBus *this, __int64 in_eProp, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  CAkSIS *v4; // r11
  int v5; // edi
  CAkBus *v6; // rbx
  char *v7; // r11
  unsigned int v8; // er9
  int v9; // er10
  __int64 v10; // rcx
  float *v11; // rcx

  v4 = this->m_pGlobalSIS;
  v5 = in_lTransitionTime;
  v6 = this;
  if ( v4 )
  {
    v7 = v4->m_values.m_pProps;
    if ( v7 )
    {
      v8 = (unsigned __int8)*v7;
      v9 = 0;
      while ( 1 )
      {
        v10 = (unsigned int)(v9 + 1);
        if ( v7[v10] == (_BYTE)in_eProp )
          break;
        v9 = v10;
        if ( (unsigned int)v10 >= v8 )
          return;
      }
      v11 = (float *)&v7[16 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
      if ( v11 )
      {
        if ( *v11 != 0.0 )
          ((void (__fastcall *)(CAkBus *, __int64, _QWORD, _QWORD, _DWORD, AkCurveInterpolation, int))v6->vfptr[11].Release)(
            v6,
            in_eProp,
            0i64,
            0i64,
            0,
            in_eFadeCurve,
            v5);
      }
    }
  }
}

// File Line: 1800
// RVA: 0xA7C590
void __fastcall CAkBus::Mute(CAkBus *this, CAkRegisteredObj *in_pGameObj, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  int v4; // edi
  AkCurveInterpolation v5; // esi
  CAkBus *v6; // rbx
  CAkSIS *v7; // rax

  if ( !in_pGameObj )
  {
    v4 = in_lTransitionTime;
    v5 = in_eFadeCurve;
    v6 = this;
    v7 = (CAkSIS *)((__int64 (*)(void))this->vfptr[19].__vecDelDtor)();
    if ( v7 )
      CAkParameterNodeBase::StartSisMuteTransitions((CAkParameterNodeBase *)&v6->vfptr, v7, 0.0, (unsigned int)v5, v4);
  }
}

// File Line: 1818
// RVA: 0xA7DB10
void __fastcall CAkBus::Unmute(CAkBus *this, CAkRegisteredObj *in_pGameObj, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  CAkSIS *v4; // r10
  int v5; // edi
  AkCurveInterpolation v6; // esi
  CAkBus *v7; // rbx
  char *v8; // r10
  unsigned int v9; // er8
  int v10; // ecx
  __int64 v11; // rdx
  float *v12; // rdx

  if ( !in_pGameObj )
  {
    v4 = this->m_pGlobalSIS;
    v5 = in_lTransitionTime;
    v6 = in_eFadeCurve;
    v7 = this;
    if ( v4 )
    {
      v8 = v4->m_values.m_pProps;
      if ( v8 )
      {
        v9 = (unsigned __int8)*v8;
        v10 = 0;
        while ( 1 )
        {
          v11 = (unsigned int)(v10 + 1);
          if ( v8[v11] == 10 )
            break;
          ++v10;
          if ( (unsigned int)v11 >= v9 )
            return;
        }
        v12 = (float *)&v8[16 * v10 + ((v9 + 4) & 0xFFFFFFFC)];
        if ( v12 )
        {
          if ( 1.0 != *v12 )
          {
            CAkRegistryMgr::SetNodeIDAsModified(g_pRegistryMgr, (CAkParameterNodeBase *)&v7->vfptr);
            CAkParameterNodeBase::StartSisMuteTransitions(
              (CAkParameterNodeBase *)&v7->vfptr,
              v7->m_pGlobalSIS,
              1.0,
              (unsigned int)v6,
              v5);
          }
        }
      }
    }
  }
}

// File Line: 1837
// RVA: 0xA7DBE0
void __fastcall CAkBus::UnmuteAll(CAkBus *this, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  ((void (__fastcall *)(CAkBus *, _QWORD, _QWORD, _QWORD))this->vfptr[12].AddRef)(
    this,
    0i64,
    (unsigned int)in_eFadeCurve,
    (unsigned int)in_lTransitionTime);
}

// File Line: 1842
// RVA: 0xA7C040
CAkSIS *__fastcall CAkBus::GetSIS(CAkBus *this, CAkRegisteredObj *__formal)
{
  CAkBus *v2; // rdi
  char v3; // si
  unsigned int v4; // ebx
  bool v5; // al
  char v6; // cl
  CAkSIS *result; // rax

  v2 = this;
  CAkRegistryMgr::SetNodeIDAsModified(g_pRegistryMgr, (CAkParameterNodeBase *)&this->vfptr);
  if ( !v2->m_pGlobalSIS )
  {
    v3 = 0;
    v4 = 0;
    do
    {
      v5 = CAkBus::GetBypassFX(v2, v4);
      v6 = v4++;
      v3 |= (v5 != 0) << v6;
    }
    while ( v4 < 4 );
    result = (CAkSIS *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
    if ( result )
    {
      result->m_pParamNode = (CAkParameterNodeBase *)&v2->vfptr;
      result->m_pGameObj = 0i64;
      result->vfptr = (ITransitionableVtbl *)&CAkSIS::`vftable;
      result->m_values.m_pProps = 0i64;
      result->m_bitsFXBypass = v3;
      v2->m_pGlobalSIS = result;
      return result;
    }
    v2->m_pGlobalSIS = 0i64;
  }
  return v2->m_pGlobalSIS;
}

// File Line: 1857
// RVA: 0xA7CD90
void __fastcall CAkBus::RecalcNotification(CAkBus *this)
{
  CAkParameterNodeBase::FXChunk *v1; // rax
  CAkBus *v2; // rbx
  unsigned int v3; // ecx
  unsigned int *v4; // rax
  char v5; // al
  float v6; // xmm0_4
  AkActivityChunk *v7; // rdi
  CAkParameterNodeBase **v8; // rbx
  AkActivityChunk *v9; // rax

  v1 = this->m_pFXChunk;
  v2 = this;
  if ( v1 )
  {
    v3 = 0;
    v4 = &v1->aFX[0].id;
    while ( !*v4 )
    {
      ++v3;
      v4 += 2;
      if ( v3 >= 4 )
        goto LABEL_5;
    }
    goto LABEL_10;
  }
LABEL_5:
  if ( v2->vfptr[3].Release((CAkIndexable *)&v2->vfptr) == 12
    || v2->m_uChannelConfig
    || (v5 = *((_BYTE *)&v2->0 + 83), v5 & 4)
    || !v2->m_pBusOutputNode
    || v5 & 8 )
  {
LABEL_10:
    v6 = CAkBus::GetBusEffectiveVolume(v2, 0, AkPropID_BusVolume);
    *((_BYTE *)v2 + 304) |= 0x20u;
    if ( v2->m_pBusOutputNode )
      CAkLEngine::ResetBusVolume(v2->key, v6);
    else
      CAkLEngine::ResetMasterBusVolume(*((_BYTE *)v2 + 304) >> 7, v6);
  }
  *((_BYTE *)v2 + 304) &= 0xFEu;
  if ( !(*((_BYTE *)v2 + 304) & 1) )
    CAkBus::UpdateVoiceVolumes(v2);
  v7 = v2->m_pActivityChunk;
  if ( v7 )
  {
    v8 = v7->m_ActiveChildren.m_pItems;
    if ( v8 != &v8[v7->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v9 = (*v8)->m_pActivityChunk;
        if ( v9 && (v9->m_PlayCount || v9 && v9->m_uActivityCount) )
          ((void (*)(void))(*v8)->vfptr[12].Category)();
        ++v8;
      }
      while ( v8 != &v7->m_ActiveChildren.m_pItems[v7->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 1895
// RVA: 0xA7BFE0
CAkBus *__fastcall CAkBus::GetPrimaryMasterBusAndAddRef()
{
  CAkAudioLibIndex *v0; // rbx
  CAkBus *v1; // rdi

  v0 = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&v0->m_idxAudioNode.m_IndexLock.m_csLock);
  v1 = g_MasterBusCtx.m_pBus;
  if ( g_MasterBusCtx.m_pBus )
    g_MasterBusCtx.m_pBus->vfptr->AddRef((CAkIndexable *)g_MasterBusCtx.m_pBus);
  LeaveCriticalSection(&v0->m_idxAudioNode.m_IndexLock.m_csLock);
  return v1;
}

// File Line: 1905
// RVA: 0xA7C0F0
CAkBus *__fastcall CAkBus::GetSecondaryMasterBusAndAddRef()
{
  CAkAudioLibIndex *v0; // rbx
  CAkBus *v1; // rdi

  v0 = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&v0->m_idxAudioNode.m_IndexLock.m_csLock);
  v1 = g_SecondaryMasterBusCtx.m_pBus;
  if ( g_SecondaryMasterBusCtx.m_pBus )
    g_SecondaryMasterBusCtx.m_pBus->vfptr->AddRef((CAkIndexable *)g_SecondaryMasterBusCtx.m_pBus);
  LeaveCriticalSection(&v0->m_idxAudioNode.m_IndexLock.m_csLock);
  return v1;
}

// File Line: 1915
// RVA: 0xA7B1F0
void CAkBus::ClearMasterBus(void)
{
  CAkAudioLibIndex *v0; // rbx

  v0 = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&v0->m_idxAudioNode.m_IndexLock.m_csLock);
  g_MasterBusCtx.m_pBus = 0i64;
  g_SecondaryMasterBusCtx.m_pBus = 0i64;
  LeaveCriticalSection(&v0->m_idxAudioNode.m_IndexLock.m_csLock);
}

// File Line: 1922
// RVA: 0xA7DE50
void __fastcall CAkBus::UpdateVoiceVolumes(CAkBus *this)
{
  CAkParameterNodeBase::FXChunk *v1; // rax
  CAkBus *v2; // rbx
  unsigned int v3; // edx
  unsigned int *v4; // rax
  char v5; // al
  float v6; // xmm0_4

  v1 = this->m_pFXChunk;
  v2 = this;
  if ( v1 )
  {
    v3 = 0;
    v4 = &v1->aFX[0].id;
    while ( !*v4 )
    {
      ++v3;
      v4 += 2;
      if ( v3 >= 4 )
        goto LABEL_5;
    }
    goto LABEL_11;
  }
LABEL_5:
  if ( ((unsigned int (*)(void))this->vfptr[3].Release)() == 12
    || v2->m_uChannelConfig
    || (v5 = *((_BYTE *)&v2->0 + 83), v5 & 4)
    || !v2->m_pBusOutputNode
    || v5 & 8 )
  {
LABEL_11:
    v2->m_fEffectiveBusVolume = 0.0;
    goto LABEL_12;
  }
  v2->m_fEffectiveBusVolume = CAkBus::GetBusEffectiveVolume(v2, 0, AkPropID_BusVolume);
LABEL_12:
  v6 = CAkBus::GetBusEffectiveVolume(v2, BusVolumeType_IncludeEntireBusTree, 0);
  *((_BYTE *)v2 + 304) |= 1u;
  v2->m_fEffectiveVoiceVolume = v6;
}

// File Line: 1935
// RVA: 0xA7C6B0
void __fastcall CAkBus::NotifyHdrWindowTop(CAkBus *this, float in_fWindowTop)
{
  char *v2; // rdx
  signed __int64 v3; // r9
  unsigned int v4; // er10
  __int64 v5; // rcx
  __int64 v6; // r8
  signed __int64 v7; // r8
  unsigned int *v8; // rax
  unsigned int v9; // er11
  unsigned int v10; // er10
  __int64 v11; // rcx
  __int64 v12; // r8
  signed __int64 v13; // r8
  float *v14; // rax
  unsigned int v15; // er10
  __int64 v16; // rcx
  __int64 v17; // r8
  int v18; // xmm0_4
  int *v19; // rax
  float v20; // [rsp+40h] [rbp+8h]
  float v21; // [rsp+50h] [rbp+18h]
  TransParams in_transParams; // [rsp+58h] [rbp+20h]

  v2 = this->m_props.m_pProps;
  v3 = 0i64;
  v20 = 0.0;
  if ( v2 )
  {
    v4 = (unsigned __int8)*v2;
    v5 = 0i64;
    while ( 1 )
    {
      v6 = (unsigned int)(v5 + 1);
      if ( v2[v6] == 29 )
        break;
      v5 = (unsigned int)v6;
      if ( (unsigned int)v6 >= v4 )
        goto LABEL_5;
    }
    v7 = (signed __int64)&v2[4 * v5 + ((v4 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v7 = 0i64;
  }
  v8 = (unsigned int *)&v20;
  if ( v7 )
    v8 = (unsigned int *)v7;
  v9 = *v8;
  if ( *v8 )
  {
    in_transParams.TransitionTime = 0;
    in_transParams.eFadeCurve = 4;
    v20 = g_AkPropDefault[30].fValue;
    if ( v2 )
    {
      v10 = (unsigned __int8)*v2;
      v11 = 0i64;
      while ( 1 )
      {
        v12 = (unsigned int)(v11 + 1);
        if ( v2[v12] == 30 )
          break;
        v11 = (unsigned int)v12;
        if ( (unsigned int)v12 >= v10 )
          goto LABEL_13;
      }
      v13 = (signed __int64)&v2[4 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_13:
      v13 = 0i64;
    }
    v14 = &v20;
    if ( v13 )
      v14 = (float *)v13;
    v21 = *v14;
    v20 = g_AkPropDefault[31].fValue;
    if ( v2 )
    {
      v15 = (unsigned __int8)*v2;
      v16 = 0i64;
      while ( 1 )
      {
        v17 = (unsigned int)(v16 + 1);
        if ( v2[v17] == 31 )
          break;
        v16 = (unsigned int)v17;
        if ( (unsigned int)v17 >= v15 )
          goto LABEL_24;
      }
      v3 = (signed __int64)&v2[4 * v16 + ((v15 + 4) & 0xFFFFFFFC)];
    }
LABEL_24:
    v18 = LODWORD(v21);
    v19 = (int *)&v20;
    if ( v3 )
      v19 = (int *)v3;
    v20 = *(float *)v19;
    if ( in_fWindowTop < v21 || (v18 = LODWORD(v20), in_fWindowTop > v20) )
      in_fWindowTop = *(float *)&v18;
    CAkRTPCMgr::SetRTPCInternal(g_pRTPCMgr, v9, in_fWindowTop, 0i64, &in_transParams, AkValueMeaning_Independent);
  }
}

