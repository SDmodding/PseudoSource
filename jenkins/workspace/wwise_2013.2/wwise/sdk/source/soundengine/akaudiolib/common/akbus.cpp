// File Line: 80
// RVA: 0xA7AA20
void __fastcall CAkBus::CAkBus(CAkBus *this, unsigned int in_ulID)
{
  CAkParameterNodeBase::CAkParameterNodeBase(this, in_ulID);
  this->m_mapChildId.m_pItems = 0i64;
  *(_QWORD *)&this->m_mapChildId.m_uLength = 0i64;
  this->vfptr = (CAkIndexableVtbl *)&CAkBus::`vftable;
  this->m_mapBusChildId.m_pItems = 0i64;
  *(_QWORD *)&this->m_mapBusChildId.m_uLength = 0i64;
  this->m_RecoveryTime = 0;
  this->m_uChannelConfig = 1599;
  this->m_fMaxDuckVolume = -96.300003;
  *(_QWORD *)&this->m_ToDuckList.m_ulMinNumListItems = 0i64;
  this->m_ToDuckList.m_ulNumListItems = 0;
  *(_QWORD *)&this->m_DuckedVolumeList.m_ulMinNumListItems = 0i64;
  this->m_DuckedVolumeList.m_ulNumListItems = 0;
  *(_QWORD *)&this->m_DuckedBusVolumeList.m_ulMinNumListItems = 0i64;
  this->m_DuckedBusVolumeList.m_ulNumListItems = 0;
  *(_QWORD *)&this->m_fEffectiveBusVolume = 0i64;
  *((_BYTE *)this + 304) = 96;
}

// File Line: 84
// RVA: 0xA7AAB0
void __fastcall CAkBus::~CAkBus(CAkBus *this)
{
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v3; // rdx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *m_pvMemStart; // r8
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *m_pFree; // rdx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v6; // r8
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *pNextListItem; // rbx
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
  CAkAudioLibIndex *NodeLock; // rbx
  CAkAudioLibIndex *v23; // rbx
  CAkParameterNodeBase **m_pItems; // rdx
  CAkParameterNodeBase **v25; // rdx

  m_pFirst = this->m_DuckedVolumeList.m_pFirst;
  for ( this->vfptr = (CAkIndexableVtbl *)&CAkBus::`vftable; m_pFirst; m_pFirst = m_pFirst->pNextListItem )
    CAkDuckItem::Term(&m_pFirst->Item.item);
  if ( this->m_DuckedVolumeList.m_ulMaxNumListItems )
  {
    while ( 1 )
    {
      v3 = this->m_DuckedVolumeList.m_pFirst;
      if ( !v3 )
        break;
      this->m_DuckedVolumeList.m_pFirst = v3->pNextListItem;
      if ( v3 == this->m_DuckedVolumeList.m_pLast )
        this->m_DuckedVolumeList.m_pLast = 0i64;
      m_pvMemStart = this->m_DuckedVolumeList.m_pvMemStart;
      if ( v3 < m_pvMemStart || v3 >= &m_pvMemStart[this->m_DuckedVolumeList.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v3);
        --this->m_DuckedVolumeList.m_ulNumListItems;
      }
      else
      {
        v3->pNextListItem = this->m_DuckedVolumeList.m_pFree;
        --this->m_DuckedVolumeList.m_ulNumListItems;
        this->m_DuckedVolumeList.m_pFree = v3;
      }
    }
    m_pFree = this->m_DuckedVolumeList.m_pFree;
    if ( m_pFree )
    {
      do
      {
        v6 = this->m_DuckedVolumeList.m_pvMemStart;
        pNextListItem = m_pFree->pNextListItem;
        if ( m_pFree < v6 || m_pFree >= &v6[this->m_DuckedVolumeList.m_ulMinNumListItems] )
          AK::MemoryMgr::Free(g_DefaultPoolId, m_pFree);
        m_pFree = pNextListItem;
      }
      while ( pNextListItem );
    }
    v8 = this->m_DuckedVolumeList.m_pvMemStart;
    if ( v8 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v8);
    *(_QWORD *)&this->m_DuckedVolumeList.m_ulMinNumListItems = 0i64;
    this->m_DuckedVolumeList.m_pFirst = 0i64;
    this->m_DuckedVolumeList.m_pLast = 0i64;
  }
  for ( i = this->m_DuckedBusVolumeList.m_pFirst; i; i = i->pNextListItem )
    CAkDuckItem::Term(&i->Item.item);
  if ( this->m_DuckedBusVolumeList.m_ulMaxNumListItems )
  {
    while ( 1 )
    {
      v10 = this->m_DuckedBusVolumeList.m_pFirst;
      if ( !v10 )
        break;
      this->m_DuckedBusVolumeList.m_pFirst = v10->pNextListItem;
      if ( v10 == this->m_DuckedBusVolumeList.m_pLast )
        this->m_DuckedBusVolumeList.m_pLast = 0i64;
      v11 = this->m_DuckedBusVolumeList.m_pvMemStart;
      if ( v10 < v11 || v10 >= &v11[this->m_DuckedBusVolumeList.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v10);
        --this->m_DuckedBusVolumeList.m_ulNumListItems;
      }
      else
      {
        v10->pNextListItem = this->m_DuckedBusVolumeList.m_pFree;
        --this->m_DuckedBusVolumeList.m_ulNumListItems;
        this->m_DuckedBusVolumeList.m_pFree = v10;
      }
    }
    v12 = this->m_DuckedBusVolumeList.m_pFree;
    if ( v12 )
    {
      do
      {
        v13 = this->m_DuckedBusVolumeList.m_pvMemStart;
        v14 = v12->pNextListItem;
        if ( v12 < v13 || v12 >= &v13[this->m_DuckedBusVolumeList.m_ulMinNumListItems] )
          AK::MemoryMgr::Free(g_DefaultPoolId, v12);
        v12 = v14;
      }
      while ( v14 );
    }
    v15 = this->m_DuckedBusVolumeList.m_pvMemStart;
    if ( v15 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v15);
    *(_QWORD *)&this->m_DuckedBusVolumeList.m_ulMinNumListItems = 0i64;
    this->m_DuckedBusVolumeList.m_pFirst = 0i64;
    this->m_DuckedBusVolumeList.m_pLast = 0i64;
  }
  if ( this->m_ToDuckList.m_ulMaxNumListItems )
  {
    while ( 1 )
    {
      v16 = this->m_ToDuckList.m_pFirst;
      if ( !v16 )
        break;
      this->m_ToDuckList.m_pFirst = v16->pNextListItem;
      if ( v16 == this->m_ToDuckList.m_pLast )
        this->m_ToDuckList.m_pLast = 0i64;
      v17 = this->m_ToDuckList.m_pvMemStart;
      if ( v16 < v17 || v16 >= &v17[this->m_ToDuckList.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v16);
        --this->m_ToDuckList.m_ulNumListItems;
      }
      else
      {
        v16->pNextListItem = this->m_ToDuckList.m_pFree;
        --this->m_ToDuckList.m_ulNumListItems;
        this->m_ToDuckList.m_pFree = v16;
      }
    }
    v18 = this->m_ToDuckList.m_pFree;
    if ( v18 )
    {
      do
      {
        v19 = this->m_ToDuckList.m_pvMemStart;
        v20 = v18->pNextListItem;
        if ( v18 < v19 || v18 >= &v19[this->m_ToDuckList.m_ulMinNumListItems] )
          AK::MemoryMgr::Free(g_DefaultPoolId, v18);
        v18 = v20;
      }
      while ( v20 );
    }
    v21 = this->m_ToDuckList.m_pvMemStart;
    if ( v21 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v21);
    *(_QWORD *)&this->m_ToDuckList.m_ulMinNumListItems = 0i64;
    this->m_ToDuckList.m_pFirst = 0i64;
    this->m_ToDuckList.m_pLast = 0i64;
  }
  if ( g_MasterBusCtx.m_pBus == this )
  {
    NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
    EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
    g_MasterBusCtx.m_pBus = 0i64;
    LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
    if ( g_pBankManager )
      g_pBankManager->m_bIsFirstBusLoaded = 0;
    CAkBankMgr::SignalLastBankUnloaded();
  }
  else if ( g_SecondaryMasterBusCtx.m_pBus == this )
  {
    v23 = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
    EnterCriticalSection(&v23->m_idxAudioNode.m_IndexLock.m_csLock);
    g_SecondaryMasterBusCtx.m_pBus = 0i64;
    LeaveCriticalSection(&v23->m_idxAudioNode.m_IndexLock.m_csLock);
  }
  m_pItems = this->m_mapBusChildId.m_pItems;
  if ( m_pItems )
  {
    this->m_mapBusChildId.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_mapBusChildId.m_pItems = 0i64;
    this->m_mapBusChildId.m_ulReserved = 0;
  }
  this->vfptr = (CAkIndexableVtbl *)&CAkParentNode<CAkParameterNodeBase>::`vftable;
  v25 = this->m_mapChildId.m_pItems;
  if ( v25 )
  {
    this->m_mapChildId.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v25);
    this->m_mapChildId.m_pItems = 0i64;
    this->m_mapChildId.m_ulReserved = 0;
  }
  CAkParameterNodeBase::~CAkParameterNodeBase(this);
}

// File Line: 123
// RVA: 0xA7C390
__int64 __fastcall CAkBus::Init(CAkBus *this)
{
  unsigned int v2; // eax
  int v3; // ecx
  bool v4; // al

  v2 = this->vfptr[3].Release(this);
  v4 = 0;
  if ( v2 <= 0xC )
  {
    v3 = 5121;
    if ( _bittest(&v3, v2) )
      v4 = 1;
  }
  *((_BYTE *)&this->CAkParameterNodeBase + 83) &= ~2u;
  *((_BYTE *)&this->CAkParameterNodeBase + 83) |= 2 * v4;
  CAkParameterNodeBase::AddToIndex(this);
  this->m_ToDuckList.m_pFree = 0i64;
  this->m_ToDuckList.m_pvMemStart = 0i64;
  this->m_ToDuckList.m_pFirst = 0i64;
  this->m_ToDuckList.m_pLast = 0i64;
  *(_QWORD *)&this->m_ToDuckList.m_ulMaxNumListItems = 100i64;
  this->m_DuckedVolumeList.m_pFree = 0i64;
  this->m_DuckedVolumeList.m_pvMemStart = 0i64;
  this->m_DuckedVolumeList.m_pFirst = 0i64;
  this->m_DuckedVolumeList.m_pLast = 0i64;
  *(_QWORD *)&this->m_DuckedVolumeList.m_ulMaxNumListItems = 100i64;
  this->m_DuckedBusVolumeList.m_pFree = 0i64;
  this->m_DuckedBusVolumeList.m_pvMemStart = 0i64;
  this->m_DuckedBusVolumeList.m_pFirst = 0i64;
  this->m_DuckedBusVolumeList.m_pLast = 0i64;
  *(_QWORD *)&this->m_DuckedBusVolumeList.m_ulMaxNumListItems = 100i64;
  return 1i64;
}

// File Line: 141
// RVA: 0xA7B240
void __fastcall CAkBus::Create(unsigned int in_ulID)
{
  CAkBus *v2; // rax
  CAkBus *v3; // rax
  CAkBus *v4; // rbx

  v2 = (CAkBus *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x138ui64);
  if ( v2 )
  {
    CAkBus::CAkBus(v2, in_ulID);
    v4 = v3;
    if ( v3 )
    {
      if ( CAkBus::Init(v3) != AK_Success )
        v4->vfptr->Release(v4);
    }
  }
}

// File Line: 161
// RVA: 0xA7B4F0
__int64 __fastcall CAkBus::ExecuteAction(CAkBus *this, ActionParams *in_rAction)
{
  AkActivityChunk *m_pActivityChunk; // rax
  ActionParams *v3; // rsi
  unsigned int m_uLength; // ebx
  CAkParameterNodeBase *v6; // rcx
  unsigned int v7; // ebx
  CAkParameterNodeBase *v8; // rcx

  m_pActivityChunk = this->m_pActivityChunk;
  v3 = in_rAction;
  if ( !m_pActivityChunk || !m_pActivityChunk->m_PlayCount && !m_pActivityChunk->m_uActivityCount )
    return 1i64;
  if ( in_rAction->bIsMasterCall )
  {
    LOBYTE(in_rAction) = in_rAction->eType == ActionParamType_Pause;
    ((void (__fastcall *)(CAkBus *, ActionParams *))this->vfptr[10].Category)(this, in_rAction);
  }
  v3->bIsFromBus = 1;
  m_uLength = this->m_mapChildId.m_uLength;
  while ( m_uLength )
  {
    v6 = this->m_mapChildId.m_pItems[--m_uLength];
    v6->vfptr[4].__vecDelDtor(v6, (unsigned int)v3);
    if ( m_uLength > this->m_mapChildId.m_uLength )
      m_uLength = this->m_mapChildId.m_uLength;
  }
  v7 = this->m_mapBusChildId.m_uLength;
  while ( v7 )
  {
    v8 = this->m_mapBusChildId.m_pItems[--v7];
    v8->vfptr[4].__vecDelDtor(v8, (unsigned int)v3);
    if ( v7 > this->m_mapBusChildId.m_uLength )
      v7 = this->m_mapBusChildId.m_uLength;
  }
  return 1i64;
}

// File Line: 209
// RVA: 0xA7B5D0
__int64 __fastcall CAkBus::ExecuteActionExcept(CAkBus *this, ActionParamsExcept *in_rAction)
{
  ActionParamsExcept *v2; // rsi
  unsigned int m_uLength; // ebx
  CAkParameterNodeBase *v5; // r14
  unsigned int v6; // ebx
  CAkParameterNodeBase *v7; // r14

  v2 = in_rAction;
  if ( !in_rAction->pGameObj )
  {
    LOBYTE(in_rAction) = in_rAction->eType == ActionParamType_Pause;
    ((void (__fastcall *)(CAkBus *, ActionParamsExcept *))this->vfptr[10].Category)(this, in_rAction);
  }
  v2->bIsFromBus = 1;
  m_uLength = this->m_mapChildId.m_uLength;
  while ( m_uLength )
  {
    v5 = this->m_mapChildId.m_pItems[--m_uLength];
    if ( !CAkParameterNodeBase::IsException(v5, v2->pExeceptionList) )
      ((void (__fastcall *)(CAkParameterNodeBase *, ActionParamsExcept *))v5->vfptr[4].Release)(v5, v2);
    if ( m_uLength > this->m_mapChildId.m_uLength )
      m_uLength = this->m_mapChildId.m_uLength;
  }
  v6 = this->m_mapBusChildId.m_uLength;
  while ( v6 )
  {
    v7 = this->m_mapBusChildId.m_pItems[--v6];
    if ( !CAkParameterNodeBase::IsException(v7, v2->pExeceptionList) )
      ((void (__fastcall *)(CAkParameterNodeBase *, ActionParamsExcept *))v7->vfptr[4].Release)(v7, v2);
    if ( v6 > this->m_mapBusChildId.m_uLength )
      v6 = this->m_mapBusChildId.m_uLength;
  }
  return 1i64;
}

// File Line: 258
// RVA: 0xA7CBE0
__int64 __fastcall CAkBus::PlayToEnd(
        CAkBus *this,
        CAkRegisteredObj *in_pGameObj,
        CAkParameterNodeBase *in_NodePtr,
        unsigned int in_PlayingID)
{
  CAkParameterNodeBase **m_pItems; // rbx
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *p_m_mapBusChildId; // rdi
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *p_m_mapChildId; // rsi
  __int64 result; // rax

  m_pItems = this->m_mapBusChildId.m_pItems;
  p_m_mapBusChildId = &this->m_mapBusChildId;
  p_m_mapChildId = &this->m_mapChildId;
  if ( m_pItems == &m_pItems[this->m_mapBusChildId.m_uLength] && p_m_mapBusChildId != p_m_mapChildId )
  {
    m_pItems = p_m_mapChildId->m_pItems;
    p_m_mapBusChildId = &this->m_mapChildId;
  }
  if ( m_pItems == &p_m_mapBusChildId->m_pItems[p_m_mapBusChildId->m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))(*m_pItems)->vfptr[4].Category)(
               *m_pItems,
               in_pGameObj,
               in_NodePtr,
               in_PlayingID);
    if ( (_DWORD)result != 1 )
      break;
    if ( ++m_pItems == &p_m_mapBusChildId->m_pItems[p_m_mapBusChildId->m_uLength] && p_m_mapBusChildId != p_m_mapChildId )
    {
      m_pItems = p_m_mapChildId->m_pItems;
      p_m_mapBusChildId = p_m_mapChildId;
    }
    if ( m_pItems == &p_m_mapBusChildId->m_pItems[p_m_mapBusChildId->m_uLength] )
      return 1i64;
  }
  return result;
}

// File Line: 315
// RVA: 0xA7CD70
void __fastcall CAkBus::PropagatePositioningNotification(
        CAkBus *this,
        float in_RTPCValue,
        AkRTPC_ParameterID in_ParameterID,
        CAkRegisteredObj *in_GameObj)
{
  if ( this->m_pBusOutputNode )
    CAkLEngine::PositioningChangeNotification(this->key, in_RTPCValue, in_ParameterID);
}

// File Line: 321
// RVA: 0xA7B6B0
__int64 __fastcall CAkBus::GetAudioParameters(
        CAkBus *this,
        AkSoundParamsEx *io_Parameters,
        unsigned int in_ulParamSelect,
        CAkKeyArray<AkMutedMapItem,float,2> *io_rMutedMap,
        CAkRegisteredObj *in_pGameObj,
        bool in_bIncludeRange,
        AkPBIModValues *io_Ranges)
{
  unsigned int v9; // ebp
  int v11; // ebx
  char *m_pProps; // r8
  unsigned int v13; // r9d
  __int64 v14; // rcx
  __int64 v15; // rdx
  __int64 v16; // rdx
  float *v17; // rax
  char *v18; // r8
  unsigned int v19; // r9d
  __int64 v20; // rcx
  __int64 v21; // rdx
  __int64 v22; // rdx
  float *v23; // rax
  CAkSIS *m_pGlobalSIS; // r8
  char *v25; // r8
  unsigned int v26; // r9d
  int v27; // ecx
  __int64 v28; // rdx
  float *v29; // rdx
  char *v30; // r8
  unsigned int v31; // r9d
  int v32; // ecx
  __int64 v33; // rdx
  float *v34; // rdx
  char *v35; // rdx
  unsigned int v36; // r8d
  __int64 v37; // rcx
  float *v38; // rcx
  float v39; // xmm2_4
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  AkMutedMapItem v42; // [rsp+40h] [rbp-28h] BYREF
  float v43; // [rsp+80h] [rbp+18h] BYREF

  v9 = in_ulParamSelect & 0xFFFFFFF6;
  CAkParameterNodeBase::GetAudioStateParams(this, io_Parameters, in_ulParamSelect & 0xF6);
  v11 = 0;
  if ( (v9 & 2) != 0 )
  {
    m_pProps = this->m_props.m_pProps;
    v43 = 0.0;
    if ( m_pProps )
    {
      v13 = (unsigned __int8)*m_pProps;
      v14 = 0i64;
      while ( 1 )
      {
        v15 = (unsigned int)(v14 + 1);
        if ( m_pProps[v15] == 2 )
          break;
        v14 = (unsigned int)v15;
        if ( (unsigned int)v15 >= v13 )
          goto LABEL_6;
      }
      v16 = (__int64)&m_pProps[4 * v14 + ((v13 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_6:
      v16 = 0i64;
    }
    v17 = &v43;
    if ( v16 )
      v17 = (float *)v16;
    v43 = *v17;
    io_Parameters->Pitch = v43 + io_Parameters->Pitch;
    if ( (this->m_RTPCBitArray.m_iBitArray & 4) != 0 )
      io_Parameters->Pitch = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 2u, 0i64) + io_Parameters->Pitch;
  }
  if ( (v9 & 4) != 0 )
  {
    v18 = this->m_props.m_pProps;
    v43 = 0.0;
    if ( v18 )
    {
      v19 = (unsigned __int8)*v18;
      v20 = 0i64;
      while ( 1 )
      {
        v21 = (unsigned int)(v20 + 1);
        if ( v18[v21] == 3 )
          break;
        v20 = (unsigned int)v21;
        if ( (unsigned int)v21 >= v19 )
          goto LABEL_16;
      }
      v22 = (__int64)&v18[4 * v20 + ((v19 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_16:
      v22 = 0i64;
    }
    v23 = &v43;
    if ( v22 )
      v23 = (float *)v22;
    v43 = *v23;
    io_Parameters->LPF = v43 + io_Parameters->LPF;
    if ( (this->m_RTPCBitArray.m_iBitArray & 8) != 0 )
      io_Parameters->LPF = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 3u, 0i64) + io_Parameters->LPF;
  }
  m_pGlobalSIS = this->m_pGlobalSIS;
  if ( m_pGlobalSIS )
  {
    v25 = m_pGlobalSIS->m_values.m_pProps;
    if ( v25 )
    {
      v26 = (unsigned __int8)*v25;
      v27 = 0;
      while ( 1 )
      {
        v28 = (unsigned int)(v27 + 1);
        if ( v25[v28] == 2 )
          break;
        ++v27;
        if ( (unsigned int)v28 >= v26 )
          goto LABEL_31;
      }
      v29 = (float *)&v25[16 * v27 + ((v26 + 4) & 0xFFFFFFFC)];
      if ( v29 )
        io_Parameters->Pitch = io_Parameters->Pitch + *v29;
    }
LABEL_31:
    v30 = this->m_pGlobalSIS->m_values.m_pProps;
    if ( v30 )
    {
      v31 = (unsigned __int8)*v30;
      v32 = 0;
      while ( 1 )
      {
        v33 = (unsigned int)(v32 + 1);
        if ( v30[v33] == 3 )
          break;
        ++v32;
        if ( (unsigned int)v33 >= v31 )
          goto LABEL_38;
      }
      v34 = (float *)&v30[16 * v32 + ((v31 + 4) & 0xFFFFFFFC)];
      if ( v34 )
        io_Parameters->LPF = io_Parameters->LPF + *v34;
    }
LABEL_38:
    v35 = this->m_pGlobalSIS->m_values.m_pProps;
    if ( v35 )
    {
      v36 = (unsigned __int8)*v35;
      while ( 1 )
      {
        v37 = (unsigned int)(v11 + 1);
        if ( v35[v37] == 10 )
          break;
        ++v11;
        if ( (unsigned int)v37 >= v36 )
          goto LABEL_46;
      }
      v38 = (float *)&v35[16 * v11 + ((v36 + 4) & 0xFFFFFFFC)];
      if ( v38 )
      {
        v39 = *v38;
        if ( *v38 != 1.0 )
        {
          v42.m_Identifier = this;
          *((_DWORD *)&v42 + 2) = *((_DWORD *)&v42 + 2) & 0xFFFFFFFC | 1;
          CAkKeyArray<AkMutedMapItem,float,2>::Set(io_rMutedMap, &v42, v39);
        }
      }
    }
  }
LABEL_46:
  m_pBusOutputNode = this->m_pBusOutputNode;
  if ( m_pBusOutputNode )
    ((void (__fastcall *)(CAkParameterNodeBase *, AkSoundParamsEx *, _QWORD, CAkKeyArray<AkMutedMapItem,float,2> *, CAkRegisteredObj *, bool, AkPBIModValues *, char))m_pBusOutputNode->vfptr[10].Release)(
      m_pBusOutputNode,
      io_Parameters,
      v9,
      io_rMutedMap,
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
  float m_fMaxDuckVolume; // xmm7_4
  __int64 v4; // rbx
  float BusVolume; // xmm6_4
  char *m_pProps; // r8
  CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault> *p_m_DuckedBusVolumeList; // rsi
  unsigned int v10; // r9d
  __int64 v11; // rcx
  __int64 v12; // rdx
  __int64 v13; // rdx
  float *v14; // rax
  unsigned __int64 v15; // r8
  unsigned __int64 m_iBitArray; // rax
  float v17; // xmm6_4
  CAkSIS *m_pGlobalSIS; // r8
  char *v19; // r8
  unsigned int v20; // r9d
  int v21; // ecx
  __int64 v22; // rdx
  float *v23; // rdx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *i; // rax
  CAkBus *m_pBusOutputNode; // rcx
  float v26; // xmm6_4
  AkSoundParams io_Parameters; // [rsp+20h] [rbp-58h] BYREF
  float v29; // [rsp+90h] [rbp+18h] BYREF

  *((_BYTE *)&io_Parameters.normalization + 4) &= 0xFCu;
  *((_BYTE *)&io_Parameters.hdr + 4) &= 0xFCu;
  m_fMaxDuckVolume = 0.0;
  v4 = in_eProp;
  LODWORD(io_Parameters.fFadeRatio) = (_DWORD)FLOAT_1_0;
  BusVolume = 0.0;
  io_Parameters.Volume = 0.0;
  *(_QWORD *)&io_Parameters.Pitch = 0i64;
  *(_QWORD *)&io_Parameters.BusVolume = 0i64;
  io_Parameters.hdr.fActiveRange = 0.0;
  if ( in_eProp )
  {
    if ( in_eProp == AkPropID_BusVolume )
    {
      CAkParameterNodeBase::GetAudioStateParams(this, &io_Parameters, 8);
      BusVolume = io_Parameters.BusVolume;
    }
  }
  else
  {
    CAkParameterNodeBase::GetAudioStateParams(this, &io_Parameters, 1);
    BusVolume = io_Parameters.Volume;
  }
  m_pProps = this->m_props.m_pProps;
  p_m_DuckedBusVolumeList = 0i64;
  v29 = 0.0;
  if ( m_pProps )
  {
    v10 = (unsigned __int8)*m_pProps;
    v11 = 0i64;
    while ( 1 )
    {
      v12 = (unsigned int)(v11 + 1);
      if ( m_pProps[v12] == (_BYTE)v4 )
        break;
      v11 = (unsigned int)v12;
      if ( (unsigned int)v12 >= v10 )
        goto LABEL_9;
    }
    v13 = (__int64)&m_pProps[4 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
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
  m_iBitArray = this->m_RTPCBitArray.m_iBitArray;
  v17 = BusVolume + v29;
  if ( _bittest64((const __int64 *)&m_iBitArray, v15) )
    v17 = v17 + CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, v15, 0i64);
  m_pGlobalSIS = this->m_pGlobalSIS;
  if ( m_pGlobalSIS )
  {
    v19 = m_pGlobalSIS->m_values.m_pProps;
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
      p_m_DuckedBusVolumeList = &this->m_DuckedBusVolumeList;
  }
  else
  {
    p_m_DuckedBusVolumeList = &this->m_DuckedVolumeList;
  }
  for ( i = p_m_DuckedBusVolumeList->m_pFirst; i; i = i->pNextListItem )
    m_fMaxDuckVolume = m_fMaxDuckVolume + i->Item.item.m_EffectiveVolumeOffset;
  if ( m_fMaxDuckVolume < this->m_fMaxDuckVolume )
    m_fMaxDuckVolume = this->m_fMaxDuckVolume;
  m_pBusOutputNode = (CAkBus *)this->m_pBusOutputNode;
  v26 = v17 + m_fMaxDuckVolume;
  if ( m_pBusOutputNode
    && (in_VolumeType == BusVolumeType_IncludeEntireBusTree || !CAkBus::IsMixingBus(m_pBusOutputNode)) )
  {
    return v26 + CAkBus::GetBusEffectiveVolume((CAkBus *)this->m_pBusOutputNode, in_VolumeType, (AkPropID)v4);
  }
  return v26;
}

// File Line: 416
// RVA: 0xA7D310
void __fastcall CAkBus::SetAkProp(CAkBus *this, AkPropID in_eProp, float in_fValue, float in_fMin)
{
  __int64 v4; // rbx
  char *v6; // rdx
  AkPropBundle<AkPropValue> *p_m_props; // rdi
  unsigned int v8; // r9d
  int v9; // r8d
  __int64 v10; // rcx
  __int64 v11; // rdx
  AkPropValue *v12; // rax
  char *m_pProps; // r8
  unsigned int v14; // r9d
  __int64 v15; // rcx
  __int64 v16; // rdx
  __int64 v17; // rdx
  AkPropValue *p_in_Value; // rax
  AkPropValue in_Value; // [rsp+58h] [rbp+10h] BYREF

  v4 = in_eProp;
  if ( (unsigned int)in_eProp > AkPropID_BusVolume )
  {
    if ( (unsigned int)(in_eProp - 11) > 2 )
    {
      CAkParameterNodeBase::SetAkProp(this, in_eProp, in_fValue, in_fMin);
    }
    else
    {
      m_pProps = this->m_props.m_pProps;
      p_m_props = &this->m_props;
      in_Value.fValue = 0.0;
      if ( m_pProps )
      {
        v14 = (unsigned __int8)*m_pProps;
        v15 = 0i64;
        while ( 1 )
        {
          v16 = (unsigned int)(v15 + 1);
          if ( m_pProps[v16] == (_BYTE)v4 )
            break;
          v15 = (unsigned int)v16;
          if ( (unsigned int)v16 >= v14 )
            goto LABEL_17;
        }
        v17 = (__int64)&m_pProps[4 * v15 + ((v14 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_17:
        v17 = 0i64;
      }
      p_in_Value = &in_Value;
      if ( v17 )
        p_in_Value = (AkPropValue *)v17;
      in_Value.fValue = p_in_Value->fValue;
      if ( (float)(in_fValue - in_Value.fValue) != 0.0 )
      {
        ((void (__fastcall *)(CAkBus *, CAkIndexableVtbl *, _QWORD, _QWORD, _QWORD))this->vfptr[17].Release)(
          this,
          this->vfptr,
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
    p_m_props = &this->m_props;
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
        ++v9;
        if ( (unsigned int)v10 >= v8 )
          goto LABEL_6;
      }
      v11 = (__int64)&v6[4 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
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
      ((void (__fastcall *)(CAkBus *, _QWORD, CAkIndexableVtbl *, _QWORD, _QWORD))this->vfptr[5].Release)(
        this,
        (unsigned int)g_AkPropRTPCID[v4],
        this->vfptr,
        0i64,
        0i64);
LABEL_22:
      AkPropBundle<AkPropValue>::SetAkProp(p_m_props, v4, LODWORD(in_fValue));
    }
  }
}

// File Line: 447
// RVA: 0xA7C860
void __fastcall CAkBus::ParamNotification(CAkBus *this, NotifParams *in_rParams)
{
  bool v2; // zf
  AkActivityChunk *m_pActivityChunk; // rsi
  AkRTPC_ParameterID eType; // eax
  CAkParameterNodeBase **m_pItems; // rbx
  AkActivityChunk *v8; // rax
  CAkParameterNodeBase **v9; // rbx
  AkActivityChunk *v10; // rax
  CAkParameterNodeBase **v11; // rbx
  AkActivityChunk *v12; // rax

  v2 = in_rParams->eType == RTPC_BusVolume;
  in_rParams->bIsFromBus = 1;
  if ( v2 && CAkBus::IsMixingBus(this) )
  {
    if ( this->m_pBusOutputNode || *((char *)this + 304) >= 0 )
      CAkLEngine::SetBusVolume(this->key, in_rParams->fValue);
    else
      CAkLEngine::SetMasterBusVolume(*((_BYTE *)this + 304) >> 7, in_rParams->fValue);
  }
  else
  {
    m_pActivityChunk = this->m_pActivityChunk;
    if ( m_pActivityChunk && (m_pActivityChunk->m_PlayCount || m_pActivityChunk->m_uActivityCount) )
    {
      eType = in_rParams->eType;
      if ( in_rParams->eType == RTPC_BusVolume )
      {
        m_pItems = this->m_mapBusChildId.m_pItems;
        this->m_fEffectiveBusVolume = in_rParams->fValue + this->m_fEffectiveBusVolume;
        if ( m_pItems != &m_pItems[this->m_mapBusChildId.m_uLength] )
        {
          do
          {
            v8 = (*m_pItems)->m_pActivityChunk;
            if ( v8 && (v8->m_PlayCount || v8->m_uActivityCount) )
              (*m_pItems)->vfptr[5].__vecDelDtor(*m_pItems, (unsigned int)in_rParams);
            ++m_pItems;
          }
          while ( m_pItems != &this->m_mapBusChildId.m_pItems[this->m_mapBusChildId.m_uLength] );
        }
      }
      else if ( eType )
      {
        if ( eType == RTPC_HDRBusReleaseTime )
        {
          *((_BYTE *)this + 304) |= 0x20u;
        }
        else if ( ((eType - 32) & 0xFFFFFFFD) != 0 )
        {
          v11 = m_pActivityChunk->m_ActiveChildren.m_pItems;
          if ( v11 != &v11[m_pActivityChunk->m_ActiveChildren.m_uLength] )
          {
            do
            {
              v12 = (*v11)->m_pActivityChunk;
              if ( v12 && (v12->m_PlayCount || v12->m_uActivityCount) )
                (*v11)->vfptr[5].__vecDelDtor(*v11, (unsigned int)in_rParams);
              ++v11;
            }
            while ( v11 != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
          }
        }
        else
        {
          *((_BYTE *)this + 304) |= 0x40u;
        }
      }
      else
      {
        v9 = this->m_mapBusChildId.m_pItems;
        this->m_fEffectiveVoiceVolume = in_rParams->fValue + this->m_fEffectiveVoiceVolume;
        if ( v9 != &v9[this->m_mapBusChildId.m_uLength] )
        {
          do
          {
            v10 = (*v9)->m_pActivityChunk;
            if ( v10 && (v10->m_PlayCount || v10->m_uActivityCount) )
              (*v9)->vfptr[5].__vecDelDtor(*v9, (unsigned int)in_rParams);
            ++v9;
          }
          while ( v9 != &this->m_mapBusChildId.m_pItems[this->m_mapBusChildId.m_uLength] );
        }
      }
    }
  }
}

// File Line: 559
// RVA: 0xA7C5F0
void __fastcall CAkBus::MuteNotification(
        CAkBus *this,
        float in_fMuteRatio,
        AkMutedMapItem *in_rMutedItem,
        __int64 in_bIsFromBus)
{
  __int64 v4; // rdx
  AkActivityChunk *m_pActivityChunk; // rdi
  CAkParameterNodeBase **m_pItems; // rbx
  AkActivityChunk *v8; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    if ( m_pItems != &m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v8 = (*m_pItems)->m_pActivityChunk;
        if ( v8 )
        {
          if ( v8->m_PlayCount )
          {
            LOBYTE(in_bIsFromBus) = 1;
            ((void (__fastcall *)(CAkParameterNodeBase *, __int64, AkMutedMapItem *, __int64))(*m_pItems)->vfptr[6].__vecDelDtor)(
              *m_pItems,
              v4,
              in_rMutedItem,
              in_bIsFromBus);
          }
        }
        ++m_pItems;
      }
      while ( m_pItems != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 580
// RVA: 0xA7DC00
void __fastcall CAkBus::UpdateBusBypass(CAkBus *this, AkRTPC_ParameterID in_ParamID)
{
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // edx
  CAkIndexableVtbl *v7; // rbx
  char v8; // al
  CAkIndexableVtbl *vfptr; // rbx
  char v10; // al
  __int64 v11; // r8
  __int64 v12; // rdx
  char v13; // al
  char v14; // al
  char BypassFX; // al

  v3 = in_ParamID - 24;
  if ( !v3 )
  {
    vfptr = this->vfptr;
    BypassFX = CAkBus::GetBypassFX(this, 0);
    v11 = 1i64;
    v12 = BypassFX != 0;
    goto LABEL_11;
  }
  v4 = v3 - 1;
  if ( !v4 )
  {
    vfptr = this->vfptr;
    v14 = CAkBus::GetBypassFX(this, 1u);
    v11 = 2i64;
    v12 = 2 * (unsigned int)(v14 != 0);
    goto LABEL_11;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    vfptr = this->vfptr;
    v13 = CAkBus::GetBypassFX(this, 2u);
    v11 = 4i64;
    v12 = 4 * (unsigned int)(v13 != 0);
    goto LABEL_11;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    vfptr = this->vfptr;
    v10 = CAkBus::GetBypassFX(this, 3u);
    v11 = 8i64;
    v12 = 8 * (unsigned int)(v10 != 0);
LABEL_11:
    ((void (__fastcall *)(CAkBus *, __int64, __int64, _QWORD, _QWORD))vfptr[6].Category)(this, v12, v11, 0i64, 0i64);
    return;
  }
  if ( v6 == 1 )
  {
    v7 = this->vfptr;
    v8 = ((__int64 (__fastcall *)(CAkBus *, _QWORD))this->vfptr[14].Release)(this, 0i64);
    ((void (__fastcall *)(CAkBus *, _QWORD, __int64))v7[6].Category)(this, 16 * (unsigned int)(v8 != 0), 16i64);
  }
}

// File Line: 611
// RVA: 0xA7C680
void __fastcall CAkBus::NotifyBypass(
        CAkBus *this,
        unsigned int in_bitsFXBypass,
        unsigned int in_uTargetMask,
        CAkRegisteredObj *in_GameObj)
{
  if ( this->m_pBusOutputNode || *((char *)this + 304) >= 0 )
    CAkLEngine::BypassBusFx(this->key, in_bitsFXBypass, in_uTargetMask);
  else
    CAkLEngine::BypassMasterBusFx(in_bitsFXBypass, in_uTargetMask);
}

// File Line: 623
// RVA: 0xA7B0E0
__int64 __fastcall CAkBus::CanAddChild(CAkBus *this, CAkParameterNodeBase *in_pAudioNode)
{
  unsigned int v2; // ebx
  unsigned int key; // esi

  v2 = 1;
  if ( in_pAudioNode->m_pBusOutputNode )
    return 21i64;
  if ( (*((_BYTE *)in_pAudioNode + 83) & 2) != 0 )
  {
    key = in_pAudioNode->key;
    if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
           &this->m_mapBusChildId,
           key) )
    {
      return 5i64;
    }
    else
    {
      if ( this->key == key )
        return 23;
      return v2;
    }
  }
  else if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
              &this->m_mapChildId,
              in_pAudioNode->key) )
  {
    return 5i64;
  }
  else
  {
    return 1i64;
  }
}

// File Line: 648
// RVA: 0xA7B030
__int64 __fastcall CAkBus::AddChildInternal(CAkBus *this, CAkParameterNodeBase *pAudioNode)
{
  unsigned int v4; // esi
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *p_m_mapBusChildId; // rcx
  CAkParameterNodeBase **v6; // rax

  v4 = ((__int64 (__fastcall *)(CAkBus *))this->vfptr[20].__vecDelDtor)(this);
  if ( v4 == 1 )
  {
    p_m_mapBusChildId = &this->m_mapBusChildId;
    if ( (*((_BYTE *)pAudioNode + 83) & 2) == 0 )
      p_m_mapBusChildId = &this->m_mapChildId;
    v6 = AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::AddNoSetKey<unsigned long>(
           p_m_mapBusChildId,
           pAudioNode->key);
    if ( v6 )
    {
      *v6 = pAudioNode;
      ((void (__fastcall *)(CAkParameterNodeBase *, CAkBus *))pAudioNode->vfptr[1].Category)(pAudioNode, this);
      this->vfptr->AddRef(this);
    }
    else
    {
      v4 = 2;
    }
  }
  pAudioNode->vfptr->Release(pAudioNode);
  return v4;
}

// File Line: 679
// RVA: 0xA7AF70
__int64 __fastcall CAkBus::AddChild(CAkBus *this, WwiseObjectIDext in_ulID)
{
  CAkParameterNodeBase *NodePtrAndAddRef; // rdx
  WwiseObjectIDext in_rIDext; // [rsp+38h] [rbp+10h] BYREF

  in_rIDext = in_ulID;
  if ( !in_ulID.id )
    return 14i64;
  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &in_rIDext);
  if ( NodePtrAndAddRef )
    return ((__int64 (__fastcall *)(CAkBus *, CAkParameterNodeBase *))this->vfptr[2].AddRef)(this, NodePtrAndAddRef);
  else
    return 15i64;
}

// File Line: 693
// RVA: 0xA7CF20
void __fastcall CAkBus::RemoveChild(CAkBus *this, CAkParameterNodeBase *in_pChild)
{
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *p_m_mapBusChildId; // rcx

  if ( in_pChild->m_pBusOutputNode == this )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))in_pChild->vfptr[1].Category)(in_pChild, 0i64);
    p_m_mapBusChildId = &this->m_mapBusChildId;
    if ( (*((_BYTE *)in_pChild + 83) & 2) == 0 )
      p_m_mapBusChildId = &this->m_mapChildId;
    AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Unset<unsigned long>(
      p_m_mapBusChildId,
      in_pChild->key);
    this->vfptr->Release(this);
  }
}

// File Line: 712
// RVA: 0xA7CF70
void __fastcall CAkBus::RemoveChild(CAkBus *this, WwiseObjectIDext in_ulID)
{
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *p_m_mapBusChildId; // rcx
  CAkParameterNodeBase **v4; // rdx

  if ( in_ulID.bIsBus )
    p_m_mapBusChildId = &this->m_mapBusChildId;
  else
    p_m_mapBusChildId = &this->m_mapChildId;
  v4 = AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         p_m_mapBusChildId,
         in_ulID.id);
  if ( v4 )
    this->vfptr[3].__vecDelDtor(this, (unsigned int)*v4);
}

// File Line: 830
// RVA: 0xA7B400
void __fastcall CAkBus::Duck(
        CAkBus *this,
        unsigned int in_BusID,
        float in_DuckVolume,
        int in_FadeOutTime,
        AkCurveInterpolation in_eFadeCurve,
        AkPropID in_PropID)
{
  CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault> *p_m_DuckedBusVolumeList; // rcx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  CAkDuckItem *p_item; // rbx
  CAkDuckItem *v11; // rax

  p_m_DuckedBusVolumeList = 0i64;
  if ( in_PropID )
  {
    if ( in_PropID == AkPropID_BusVolume )
      p_m_DuckedBusVolumeList = &this->m_DuckedBusVolumeList;
  }
  else
  {
    p_m_DuckedBusVolumeList = &this->m_DuckedVolumeList;
  }
  m_pFirst = p_m_DuckedBusVolumeList->m_pFirst;
  if ( !p_m_DuckedBusVolumeList->m_pFirst )
    goto LABEL_10;
  while ( m_pFirst->Item.key != in_BusID )
  {
    m_pFirst = m_pFirst->pNextListItem;
    if ( !m_pFirst )
      goto LABEL_10;
  }
  p_item = &m_pFirst->Item.item;
  if ( m_pFirst == (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)-16i64 )
  {
LABEL_10:
    v11 = CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault>::Set(p_m_DuckedBusVolumeList, in_BusID);
    p_item = v11;
    if ( !v11 )
      return;
    CAkDuckItem::Init(v11, this);
  }
  CAkBus::StartDuckTransitions(
    this,
    p_item,
    in_DuckVolume,
    AkValueMeaning_Offset,
    in_eFadeCurve,
    in_FadeOutTime,
    in_PropID);
}

// File Line: 897
// RVA: 0xA7CAD0
void __fastcall CAkBus::PauseDuck(CAkBus *this, unsigned int in_BusID, __int64 a3, __int64 a4)
{
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  CAkTransition *m_pvVolumeTransition; // rdx
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *v8; // rax
  CAkTransition *v9; // rdx

  m_pFirst = this->m_DuckedVolumeList.m_pFirst;
  if ( m_pFirst )
  {
    while ( m_pFirst->Item.key != in_BusID )
    {
      m_pFirst = m_pFirst->pNextListItem;
      if ( !m_pFirst )
        goto LABEL_9;
    }
    if ( m_pFirst != (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)-16i64 )
    {
      m_pvVolumeTransition = m_pFirst->Item.item.m_pvVolumeTransition;
      if ( m_pvVolumeTransition )
      {
        CAkTransitionManager::ChangeParameter(
          g_pTransitionManager,
          m_pvVolumeTransition,
          0i64,
          m_pFirst->Item.item.m_EffectiveVolumeOffset,
          0,
          AkCurveInterpolation_Linear,
          AkValueMeaning_Independent);
      }
      else
      {
        LOBYTE(a4) = 1;
        ((void (__fastcall *)(CAkDuckItem *, _QWORD, __int64, __int64))m_pFirst->Item.item.vfptr->TransUpdateValue)(
          &m_pFirst->Item.item,
          0i64,
          a3,
          a4);
      }
    }
  }
LABEL_9:
  v8 = this->m_DuckedBusVolumeList.m_pFirst;
  if ( v8 )
  {
    while ( v8->Item.key != in_BusID )
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
        ((void (__fastcall *)(CAkDuckItem *, __int64, __int64, __int64))v8->Item.item.vfptr->TransUpdateValue)(
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
void __fastcall CAkBus::StartDuckTransitions(
        CAkBus *this,
        CAkDuckItem *in_pDuckItem,
        float in_fTargetValue,
        __int64 in_eValueMeaning,
        AkCurveInterpolation in_eFadeCurve,
        int in_lTransitionTime,
        AkPropID in_ePropID)
{
  CAkTransition **v7; // r8
  CAkTransition *m_pvVolumeTransition; // rdx
  float m_EffectiveVolumeOffset; // xmm1_4
  float v12; // xmm2_4
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h] BYREF

  m_pvVolumeTransition = in_pDuckItem->m_pvVolumeTransition;
  if ( m_pvVolumeTransition )
  {
    CAkTransitionManager::ChangeParameter(
      g_pTransitionManager,
      m_pvVolumeTransition,
      in_ePropID,
      in_fTargetValue,
      in_lTransitionTime,
      in_eFadeCurve,
      (AkValueMeaning)in_eValueMeaning);
  }
  else
  {
    m_EffectiveVolumeOffset = in_pDuckItem->m_EffectiveVolumeOffset;
    v12 = 0.0;
    if ( (unsigned int)(in_eValueMeaning - 1) <= 1 )
      v12 = in_fTargetValue;
    if ( m_EffectiveVolumeOffset == v12 || !in_lTransitionTime )
    {
      LOBYTE(in_eValueMeaning) = 1;
      ((void (__fastcall *)(CAkDuckItem *, _QWORD, CAkTransition **, __int64))in_pDuckItem->vfptr->TransUpdateValue)(
        in_pDuckItem,
        in_ePropID,
        v7,
        in_eValueMeaning);
    }
    else
    {
      in_Params.lDuration = in_lTransitionTime;
      in_Params.fStartValue = m_EffectiveVolumeOffset;
      in_Params.fTargetValue = v12;
      in_Params.eTarget = in_ePropID;
      LOBYTE(v7) = 1;
      in_Params.pUser = in_pDuckItem;
      in_Params.eFadeCurve = in_eFadeCurve;
      *(_WORD *)&in_Params.bdBs = 257;
      in_pDuckItem->m_pvVolumeTransition = CAkTransitionManager::AddTransitionToList(
                                             g_pTransitionManager,
                                             &in_Params,
                                             v7,
                                             0i64);
    }
  }
}

// File Line: 973
// RVA: 0xA7B0B0
void __fastcall CAkBus::ApplyMaxNumInstances(
        CAkBus *this,
        unsigned __int16 in_u16MaxNumInstance,
        CAkRegisteredObj *in_pGameObj,
        void *in_pExceptArray,
        bool in_bFromRTPC)
{
  AkActivityChunk *m_pActivityChunk; // r8

  if ( !in_pGameObj && (!in_bFromRTPC || this->m_u16MaxNumInstance) )
  {
    m_pActivityChunk = this->m_pActivityChunk;
    if ( m_pActivityChunk )
      m_pActivityChunk->m_Limiter.m_u16LimiterMax = in_u16MaxNumInstance;
    if ( !in_bFromRTPC )
      this->m_u16MaxNumInstance = in_u16MaxNumInstance;
  }
}

// File Line: 994
// RVA: 0xA7DA50
void __fastcall CAkBus::StopDucking(CAkBus *this)
{
  if ( this->m_RecoveryTime && this->m_ToDuckList.m_ulNumListItems )
  {
    if ( (unsigned int)CAkBus::RequestDuckNotif(this) == 1 )
    {
      *((_BYTE *)this + 304) &= 0xF5u;
      *((_BYTE *)this + 304) |= 4u;
    }
    else
    {
      *((_BYTE *)this + 304) &= 0xF1u;
    }
    CAkBus::UpdateDuckedBus(this);
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
  unsigned int v4; // eax
  unsigned int v5; // ebx
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  unsigned int v7; // eax
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rax
  unsigned int v9; // eax
  AkActivityChunk *m_pActivityChunk; // rax

  v4 = CAkParameterNodeBase::IncrementPlayCountValue(this, io_params->uiFlagForwardToBus);
  v5 = v4;
  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 82) & 8) != 0 || !this->m_pBusOutputNode )
  {
    if ( !io_params->bMaxConsidered && v4 == 1 )
      v5 = CAkParameterNodeBase::IncrementPlayCountGlobal(
             this,
             io_params->fPriority,
             &io_params->ui16NumKicked,
             &io_params->pBusLimiter);
    io_params->bMaxConsidered = 1;
  }
  m_pBusOutputNode = this->m_pBusOutputNode;
  if ( m_pBusOutputNode )
  {
    v7 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))m_pBusOutputNode->vfptr[8].Release)(
           m_pBusOutputNode,
           io_params);
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
  m_pFeedbackInfo = this->m_pFeedbackInfo;
  if ( m_pFeedbackInfo )
  {
    if ( m_pFeedbackInfo->m_pFeedbackBus )
    {
      v9 = ((__int64 (__fastcall *)(CAkFeedbackBus *, CounterParameters *))m_pFeedbackInfo->m_pFeedbackBus->vfptr[8].Release)(
             m_pFeedbackInfo->m_pFeedbackBus,
             io_params);
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
  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk && m_pActivityChunk->m_PlayCount == 1 )
  {
    *((_BYTE *)this + 304) &= 0xF3u;
    *((_BYTE *)this + 304) |= 2u;
    CAkBus::UpdateDuckedBus(this);
  }
  return v5;
}

// File Line: 1058
// RVA: 0xA7B2F0
void __fastcall CAkBus::DecrementPlayCount(CAkBus *this, CounterParameters *io_params)
{
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rax
  AkActivityChunk *m_pActivityChunk; // rax

  CAkParameterNodeBase::DecrementPlayCountValue(this);
  if ( ((*((_BYTE *)&this->CAkParameterNodeBase + 82) & 8) != 0 || !this->m_pBusOutputNode)
    && !io_params->bMaxConsidered )
  {
    CAkParameterNodeBase::DecrementPlayCountGlobal(this);
    io_params->bMaxConsidered = 1;
  }
  m_pBusOutputNode = this->m_pBusOutputNode;
  if ( m_pBusOutputNode )
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))m_pBusOutputNode->vfptr[8].Category)(
      m_pBusOutputNode,
      io_params);
  m_pFeedbackInfo = this->m_pFeedbackInfo;
  if ( m_pFeedbackInfo && m_pFeedbackInfo->m_pFeedbackBus )
    ((void (__fastcall *)(CAkFeedbackBus *, CounterParameters *))m_pFeedbackInfo->m_pFeedbackBus->vfptr[8].Category)(
      m_pFeedbackInfo->m_pFeedbackBus,
      io_params);
  m_pActivityChunk = this->m_pActivityChunk;
  if ( !m_pActivityChunk || !m_pActivityChunk->m_PlayCount )
    CAkBus::StopDucking(this);
}

// File Line: 1093
// RVA: 0xA7C320
void __fastcall CAkBus::IncrementVirtualCount(CAkBus *this, CounterParameters *io_params)
{
  AkActivityChunk *m_pActivityChunk; // rax
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rcx
  CAkFeedbackBus *m_pFeedbackBus; // rcx

  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 82) & 8) != 0 || !this->m_pBusOutputNode )
  {
    if ( !io_params->bMaxConsidered )
    {
      m_pActivityChunk = this->m_pActivityChunk;
      if ( m_pActivityChunk )
        ++m_pActivityChunk->m_iVirtualCountValid;
    }
    io_params->bMaxConsidered = 1;
  }
  m_pBusOutputNode = this->m_pBusOutputNode;
  if ( m_pBusOutputNode )
    ((void (__fastcall *)(CAkParameterNodeBase *))m_pBusOutputNode->vfptr[9].__vecDelDtor)(m_pBusOutputNode);
  m_pFeedbackInfo = this->m_pFeedbackInfo;
  if ( m_pFeedbackInfo )
  {
    m_pFeedbackBus = m_pFeedbackInfo->m_pFeedbackBus;
    if ( m_pFeedbackBus )
      m_pFeedbackBus->vfptr[9].__vecDelDtor(m_pFeedbackBus, (unsigned int)io_params);
  }
}

// File Line: 1119
// RVA: 0xA7B380
void __fastcall CAkBus::DecrementVirtualCount(CAkBus *this, CounterParameters *io_params)
{
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rcx
  CAkFeedbackBus *m_pFeedbackBus; // rcx

  if ( ((*((_BYTE *)&this->CAkParameterNodeBase + 82) & 8) != 0 || !this->m_pBusOutputNode)
    && !io_params->bMaxConsidered )
  {
    CAkParameterNodeBase::DecrementVirtualCountGlobal(this, &io_params->ui16NumKicked, io_params->bAllowKick);
    io_params->bMaxConsidered = 1;
  }
  m_pBusOutputNode = this->m_pBusOutputNode;
  if ( m_pBusOutputNode )
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))m_pBusOutputNode->vfptr[9].AddRef)(
      m_pBusOutputNode,
      io_params);
  m_pFeedbackInfo = this->m_pFeedbackInfo;
  if ( m_pFeedbackInfo )
  {
    m_pFeedbackBus = m_pFeedbackInfo->m_pFeedbackBus;
    if ( m_pFeedbackBus )
      ((void (__fastcall *)(CAkFeedbackBus *, CounterParameters *))m_pFeedbackBus->vfptr[9].AddRef)(
        m_pFeedbackBus,
        io_params);
  }
}

// File Line: 1143
// RVA: 0xA7C1B0
char __fastcall CAkBus::IncrementActivityCount(CAkBus *this, unsigned __int16 in_flagForwardToBus)
{
  char v3; // al
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  char v5; // bl
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rcx
  CAkFeedbackBus *m_pFeedbackBus; // rcx

  v3 = CAkParameterNodeBase::IncrementActivityCountValue(this, in_flagForwardToBus);
  m_pBusOutputNode = this->m_pBusOutputNode;
  v5 = v3;
  if ( m_pBusOutputNode )
    v5 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, __int64))m_pBusOutputNode->vfptr[9].Release)(
           m_pBusOutputNode,
           3i64) & v3;
  m_pFeedbackInfo = this->m_pFeedbackInfo;
  if ( m_pFeedbackInfo && (m_pFeedbackBus = m_pFeedbackInfo->m_pFeedbackBus) != 0i64 )
    return v5 & ((__int64 (__fastcall *)(CAkFeedbackBus *, __int64))m_pFeedbackBus->vfptr[9].Release)(
                  m_pFeedbackBus,
                  3i64);
  else
    return v5;
}

// File Line: 1162
// RVA: 0xA7B2A0
void __fastcall CAkBus::DecrementActivityCount(CAkBus *this, unsigned __int16 __formal)
{
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rcx
  CAkFeedbackBus *m_pFeedbackBus; // rcx

  CAkParameterNodeBase::DecrementActivityCountValue(this);
  m_pBusOutputNode = this->m_pBusOutputNode;
  if ( m_pBusOutputNode )
    ((void (__fastcall *)(CAkParameterNodeBase *, __int64))m_pBusOutputNode->vfptr[9].Category)(m_pBusOutputNode, 3i64);
  m_pFeedbackInfo = this->m_pFeedbackInfo;
  if ( m_pFeedbackInfo )
  {
    m_pFeedbackBus = m_pFeedbackInfo->m_pFeedbackBus;
    if ( m_pFeedbackBus )
      ((void (__fastcall *)(CAkFeedbackBus *, __int64))m_pFeedbackBus->vfptr[9].Category)(m_pFeedbackBus, 3i64);
  }
}

// File Line: 1179
// RVA: 0xA7C560
char __fastcall CAkBus::IsOrIsChildOf(CAkBus *this, CAkBus *in_pNodeToTest)
{
  if ( !this )
    return 0;
  while ( in_pNodeToTest != this )
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
  CAkList2<MapStruct<unsigned long,CAkBus::AkDuckInfo>,MapStruct<unsigned long,CAkBus::AkDuckInfo> const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkBus *NodePtrAndAddRef; // rax
  __int64 v4; // r8
  __int64 v5; // r9
  CAkBus *v6; // rdi
  AkPropID TargetProp; // r8d
  CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault> *p_m_DuckedBusVolumeList; // rax
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rax

  for ( i = this->m_ToDuckList.m_pFirst; i; i = i->pNextListItem )
  {
    NodePtrAndAddRef = (CAkBus *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, i->Item.key, AkNodeType_Bus);
    v6 = NodePtrAndAddRef;
    if ( NodePtrAndAddRef )
    {
      if ( ((*((unsigned __int8 *)this + 304) >> 1) & 7) != 0 )
      {
        if ( ((*((unsigned __int8 *)this + 304) >> 1) & 7) == 1 )
        {
          CAkBus::Duck(
            NodePtrAndAddRef,
            this->key,
            i->Item.item.DuckVolume,
            i->Item.item.FadeOutTime,
            i->Item.item.FadeCurve,
            i->Item.item.TargetProp);
        }
        else if ( ((*((unsigned __int8 *)this + 304) >> 1) & 7) == 2 )
        {
          CAkBus::PauseDuck(NodePtrAndAddRef, this->key, v4, v5);
        }
      }
      else
      {
        TargetProp = i->Item.item.TargetProp;
        p_m_DuckedBusVolumeList = 0i64;
        if ( TargetProp )
        {
          if ( TargetProp == AkPropID_BusVolume )
            p_m_DuckedBusVolumeList = &v6->m_DuckedBusVolumeList;
        }
        else
        {
          p_m_DuckedBusVolumeList = &v6->m_DuckedVolumeList;
        }
        m_pFirst = p_m_DuckedBusVolumeList->m_pFirst;
        if ( m_pFirst )
        {
          while ( m_pFirst->Item.key != this->key )
          {
            m_pFirst = m_pFirst->pNextListItem;
            if ( !m_pFirst )
              goto LABEL_18;
          }
          if ( m_pFirst != (CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *)-16i64 )
            CAkBus::StartDuckTransitions(
              v6,
              &m_pFirst->Item.item,
              0.0,
              0i64,
              i->Item.item.FadeCurve,
              i->Item.item.FadeInTime,
              i->Item.item.TargetProp);
        }
      }
LABEL_18:
      v6->vfptr->Release(v6);
    }
  }
}

// File Line: 1230
// RVA: 0xA7CFB0
__int64 __fastcall CAkBus::RequestDuckNotif(CAkBus *this)
{
  unsigned int v2; // edi
  CAkActionDuck *v3; // rax
  CAkAction *v4; // rax
  CAkAction *v5; // rbx
  AkPendingAction *v6; // rax
  AkPendingAction *v7; // rax
  __int64 v9; // [rsp+48h] [rbp+10h]

  v2 = 2;
  v3 = (CAkActionDuck *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  if ( !v3 )
    return 2i64;
  CAkActionDuck::CAkActionDuck(v3, AkActionType_Duck, 0);
  v5 = v4;
  if ( v4 )
  {
    if ( ((unsigned int (__fastcall *)(CAkAction *, __int64, _QWORD, _QWORD, _DWORD))v4->vfptr[1].Release)(
           v4,
           14i64,
           this->m_RecoveryTime,
           0i64,
           0) == 1 )
    {
      BYTE4(v9) = 1;
      LODWORD(v9) = this->key;
      ((void (__fastcall *)(CAkAction *, __int64))v5->vfptr[1].AddRef)(v5, v9);
      v6 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
      if ( v6 )
      {
        AkPendingAction::AkPendingAction(v6, 0i64);
        if ( v7 )
        {
          v7->pAction = v5;
          CAkAudioMgr::EnqueueOrExecuteAction(g_pAudioMgr, v7);
          v2 = 1;
        }
      }
    }
    v5->vfptr->Release(v5);
  }
  return v2;
}

// File Line: 1256
// RVA: 0xA7B190
void __fastcall CAkBus::CheckDuck(CAkBus *this)
{
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *i; // rax

  m_pFirst = this->m_DuckedVolumeList.m_pFirst;
  if ( m_pFirst )
  {
    while ( m_pFirst->Item.item.m_EffectiveVolumeOffset >= -0.0099999998 )
    {
      m_pFirst = m_pFirst->pNextListItem;
      if ( !m_pFirst )
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
  CAkKeyList<unsigned long,CAkDuckItem,1,ArrayPoolDefault> *p_m_DuckedBusVolumeList; // rax
  CAkList2<MapStruct<unsigned long,CAkDuckItem>,MapStruct<unsigned long,CAkDuckItem> const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  float result; // xmm0_4

  p_m_DuckedBusVolumeList = 0i64;
  if ( in_eProp )
  {
    if ( in_eProp == AkPropID_BusVolume )
      p_m_DuckedBusVolumeList = &this->m_DuckedBusVolumeList;
  }
  else
  {
    p_m_DuckedBusVolumeList = &this->m_DuckedVolumeList;
  }
  m_pFirst = p_m_DuckedBusVolumeList->m_pFirst;
  for ( result = 0.0; m_pFirst; m_pFirst = m_pFirst->pNextListItem )
    result = result + m_pFirst->Item.item.m_EffectiveVolumeOffset;
  if ( result < this->m_fMaxDuckVolume )
    return this->m_fMaxDuckVolume;
  return result;
}

// File Line: 1318
// RVA: 0xA7BF70
CAkBus *__fastcall CAkBus::GetMixingBus(CAkBus *this)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rax
  unsigned int v3; // edx
  unsigned int *p_id; // rax
  char v5; // al

  m_pFXChunk = this->m_pFXChunk;
  if ( m_pFXChunk )
  {
    v3 = 0;
    p_id = &m_pFXChunk->aFX[0].id;
    while ( !*p_id )
    {
      ++v3;
      p_id += 2;
      if ( v3 >= 4 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    if ( this->vfptr[3].Release(this) != 12 && !this->m_uChannelConfig )
    {
      v5 = *((_BYTE *)&this->CAkParameterNodeBase + 83);
      if ( (v5 & 4) == 0 && this->m_pBusOutputNode && (v5 & 8) == 0 )
        return CAkParameterNodeBase::GetMixingBus(this);
    }
  }
  if ( this != g_MasterBusCtx.m_pBus )
    return this;
  return CAkParameterNodeBase::GetMixingBus(this);
}

// File Line: 1327
// RVA: 0xA7BF60
CAkBus *__fastcall CAkBus::GetLimitingBus(CAkBus *this)
{
  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 82) & 8) != 0 )
    return this;
  else
    return CAkParameterNodeBase::GetLimitingBus(this);
}

// File Line: 1338
// RVA: 0xA7DE30
void __fastcall CAkBus::UpdateFx(CAkBus *this, unsigned int in_uFXIndex)
{
  if ( this->m_pBusOutputNode || *((char *)this + 304) >= 0 )
    CAkLEngine::UpdateMixBusFX(this->key, in_uFXIndex);
  else
    CAkLEngine::UpdateMasterBusFX(in_uFXIndex);
}

// File Line: 1358
// RVA: 0xA7C4F0
char __fastcall CAkBus::IsMixingBus(CAkBus *this)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rax
  unsigned int v3; // edx
  unsigned int *p_id; // rax
  char v5; // cl

  m_pFXChunk = this->m_pFXChunk;
  if ( m_pFXChunk )
  {
    v3 = 0;
    p_id = &m_pFXChunk->aFX[0].id;
    while ( !*p_id )
    {
      ++v3;
      p_id += 2;
      if ( v3 >= 4 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    if ( this->vfptr[3].Release(this) != 12 && !this->m_uChannelConfig )
    {
      v5 = *((_BYTE *)&this->CAkParameterNodeBase + 83);
      if ( (v5 & 4) == 0 && this->m_pBusOutputNode && (v5 & 8) == 0 )
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
__int64 __fastcall CAkBus::SetInitialParams(CAkBus *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  __int64 result; // rax
  char v6; // cl
  char v7; // cl
  char v8; // cl
  char *v9; // rax
  char v10; // bl
  unsigned __int16 v11; // cx
  __int16 v12; // cx

  result = AkPropBundle<AkPropValue>::SetInitialParams(&this->m_props, io_rpData, io_rulDataSize);
  if ( (_DWORD)result == 1 )
  {
    v6 = *(*io_rpData)++;
    *((_BYTE *)&this->CAkParameterNodeBase + 83) &= ~4u;
    *((_BYTE *)&this->CAkParameterNodeBase + 83) |= 4 * (v6 != 0);
    v7 = *(*io_rpData)++;
    *((_BYTE *)&this->CAkParameterNodeBase + 83) &= ~0x20u;
    *((_BYTE *)&this->CAkParameterNodeBase + 83) |= 32 * (v7 != 0);
    v8 = **io_rpData;
    v9 = *io_rpData + 1;
    *io_rpData = v9;
    v10 = *v9;
    *io_rpData = v9 + 1;
    CAkParameterNodeBase::SetMaxReachedBehavior(this, v8 != 0);
    CAkParameterNodeBase::SetOverLimitBehavior(this, v10 != 0);
    v11 = *(_WORD *)*io_rpData;
    *io_rpData += 2;
    this->m_u16MaxNumInstance = v11;
    LOBYTE(v11) = *(*io_rpData)++;
    *((_BYTE *)&this->CAkParameterNodeBase + 82) &= ~8u;
    *((_BYTE *)&this->CAkParameterNodeBase + 82) |= 8 * (v11 & 1);
    v12 = *(_WORD *)*io_rpData;
    *io_rpData += 2;
    *((_BYTE *)&this->CAkParameterNodeBase + 82) |= 0x80u;
    this->m_uChannelConfig = v12 & 0x63F;
    *io_rpData += 2;
    LOBYTE(v12) = *(*io_rpData)++;
    *((_BYTE *)&this->CAkParameterNodeBase + 83) &= ~8u;
    *((_BYTE *)&this->CAkParameterNodeBase + 83) |= 8 * (v12 & 1);
    LOBYTE(v12) = *(*io_rpData)++;
    *((_BYTE *)this + 304) &= ~0x10u;
    result = 1i64;
    *((_BYTE *)this + 304) |= 16 * (v12 & 1);
  }
  return result;
}

// File Line: 1427
// RVA: 0xA7D720
__int64 __fastcall CAkBus::SetInitialValues(CAkBus *this, char *in_pData, unsigned int in_ulDataSize)
{
  unsigned int v4; // eax
  CAkParameterNodeBase *NodePtrAndAddRef; // rdi
  unsigned int v6; // esi
  __int64 result; // rax
  char *v8; // r8
  int v9; // ecx
  unsigned int v10; // edi
  float v11; // xmm0_4
  char *v12; // r8
  unsigned int v13; // r13d
  unsigned int v14; // edx
  char *v15; // r8
  float v16; // xmm6_4
  int v17; // esi
  int v18; // r14d
  unsigned __int8 v19; // r15
  unsigned __int8 v20; // r12
  CAkBus::AkDuckInfo *v21; // rax
  char *io_rpData; // [rsp+78h] [rbp+30h] BYREF
  unsigned int io_rulDataSize; // [rsp+80h] [rbp+38h] BYREF

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData + 4;
  v4 = *((_DWORD *)in_pData + 1);
  io_rpData = in_pData + 8;
  if ( v4 )
  {
    NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v4, AkNodeType_Bus);
    if ( !NodePtrAndAddRef )
      return 2i64;
    this->vfptr->AddRef(this);
    v6 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkBus *))NodePtrAndAddRef->vfptr[2].AddRef)(
           NodePtrAndAddRef,
           this);
    NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
    if ( v6 != 1 )
      return v6;
  }
  else if ( g_MasterBusCtx.m_pBus )
  {
    if ( !g_SecondaryMasterBusCtx.m_pBus && g_MasterBusCtx.m_pBus != this )
    {
      g_SecondaryMasterBusCtx.m_pBus = this;
      *((_BYTE *)this + 304) &= ~0x80u;
    }
  }
  else
  {
    g_MasterBusCtx.m_pBus = this;
    *((_BYTE *)this + 304) |= 0x80u;
  }
  result = ((__int64 (__fastcall *)(CAkBus *, char **, unsigned int *))this->vfptr[17].Category)(
             this,
             &io_rpData,
             &io_rulDataSize);
  if ( (_DWORD)result == 1 )
  {
    v8 = io_rpData;
    v9 = *(_DWORD *)io_rpData;
    io_rpData += 4;
    v8 += 8;
    v10 = 0;
    this->m_RecoveryTime = v9 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
    v11 = *((float *)v8 - 1);
    io_rpData = v8;
    v12 = v8 + 4;
    this->m_fMaxDuckVolume = v11;
    v13 = *((_DWORD *)v12 - 1);
    io_rpData = v12;
    if ( v13 )
    {
      while ( 1 )
      {
        v14 = *(_DWORD *)v12;
        io_rpData = v12 + 4;
        v15 = v12 + 8;
        v16 = *((float *)v15 - 1);
        io_rpData = v15;
        v17 = *(_DWORD *)v15;
        io_rpData = v15 + 4;
        v15 += 8;
        v18 = *((_DWORD *)v15 - 1);
        io_rpData = v15;
        v19 = *v15;
        io_rpData = v15 + 1;
        v15 += 2;
        v20 = *(v15 - 1);
        io_rpData = v15;
        v21 = CAkKeyList<unsigned long,CAkBus::AkDuckInfo,1,ArrayPoolDefault>::Set(&this->m_ToDuckList, v14);
        if ( !v21 )
          return 2i64;
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
    }
    else
    {
LABEL_17:
      result = ((__int64 (__fastcall *)(CAkBus *, char **, unsigned int *, _QWORD))this->vfptr[18].__vecDelDtor)(
                 this,
                 &io_rpData,
                 &io_rulDataSize,
                 0i64);
      if ( (_DWORD)result == 1 )
      {
        result = CAkParameterNodeBase::SetInitialRTPC(this, &io_rpData, &io_rulDataSize);
        if ( (_DWORD)result == 1 )
        {
          result = CAkParameterNodeBase::ReadStateChunk(this, &io_rpData, &io_rulDataSize);
          if ( (_DWORD)result == 1 )
            return CAkParameterNodeBase::ReadFeedbackInfo(this, &io_rpData, &io_rulDataSize);
        }
      }
    }
  }
  return result;
}

// File Line: 1523
// RVA: 0xA7D530
__int64 __fastcall CAkBus::SetInitialFxParams(
        CAkBus *this,
        char **io_rpData,
        unsigned int *io_rulDataSize,
        bool __formal)
{
  unsigned int v6; // r8d
  char *v7; // rax
  unsigned int v8; // ebp
  unsigned int v9; // esi
  char *v10; // rax
  unsigned int v11; // r15d
  unsigned int v12; // ebx
  char *v13; // rax
  unsigned __int8 v14; // cl
  unsigned int v15; // r8d
  char v16; // dl

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
    do
    {
      v13 = *io_rpData + 1;
      v14 = **io_rpData;
      *io_rpData = v13;
      v13 += 4;
      v15 = *((_DWORD *)v13 - 1);
      *io_rpData = v13;
      v16 = *v13;
      *io_rpData = v13 + 2;
      if ( v15 )
      {
        v8 = CAkParameterNodeBase::SetFX(this, v14, v15, v16 != 0);
        if ( v8 != 1 )
          break;
      }
      ++v12;
    }
    while ( v12 < v9 );
    CAkParameterNodeBase::MainBypassFX(this, v11, 0xFFFFFFFF);
  }
  return v8;
}

// File Line: 1556
// RVA: 0xA7DEF0
void __fastcall CAkBus::_SetInMainHierarchy(CAkBus *this, bool in_bIsInMainHierarchy)
{
  CAkParameterNodeBase **m_pItems; // rbx

  *((_BYTE *)this + 304) &= ~0x80u;
  m_pItems = this->m_mapBusChildId.m_pItems;
  *((_BYTE *)this + 304) |= in_bIsInMainHierarchy << 7;
  if ( m_pItems != &m_pItems[this->m_mapBusChildId.m_uLength] )
  {
    do
      CAkBus::_SetInMainHierarchy((CAkBus *)*m_pItems++, in_bIsInMainHierarchy);
    while ( m_pItems != &this->m_mapBusChildId.m_pItems[this->m_mapBusChildId.m_uLength] );
  }
}

// File Line: 1570
// RVA: 0xA7CA80
void __fastcall CAkBus::ParentBus(CAkBus *this, CAkParameterNodeBase *in_pParent)
{
  char v4; // dl

  FaceInteractionResultSetTrack::ResolveReferences(this, in_pParent);
  if ( in_pParent )
  {
    v4 = LOBYTE(in_pParent[2].m_pFeedbackInfo) >> 7;
    if ( *((_BYTE *)this + 304) >> 7 != v4 )
      CAkBus::_SetInMainHierarchy(this, v4);
  }
}

// File Line: 1589
// RVA: 0xA7C150
char __fastcall CAkBus::GetStateSyncTypes(
        CAkBus *this,
        unsigned int in_stateGroupID,
        AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *io_pSyncTypes)
{
  CAkBus *m_pBusOutputNode; // rbx

  m_pBusOutputNode = this;
  if ( CAkParameterNodeBase::CheckSyncTypes(this, in_stateGroupID, io_pSyncTypes) )
    return 1;
  while ( 1 )
  {
    m_pBusOutputNode = (CAkBus *)m_pBusOutputNode->m_pBusOutputNode;
    if ( !m_pBusOutputNode )
      break;
    if ( CAkParameterNodeBase::CheckSyncTypes(m_pBusOutputNode, in_stateGroupID, io_pSyncTypes) )
      return 1;
  }
  return 0;
}

// File Line: 1608
// RVA: 0xA7BDF0
void __fastcall CAkBus::GetFX(CAkBus *this, __int64 in_uFXIndex, AkFXDesc *out_rFXInfo, CAkRegisteredObj *__formal)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // r8
  __int64 v6; // rdi
  unsigned int id; // edx
  CAkFxBase *PtrAndAddRef; // rax
  CAkFxBase *m_pT; // rcx
  CAkFxBase *v11; // rcx

  m_pFXChunk = this->m_pFXChunk;
  v6 = (unsigned int)in_uFXIndex;
  if ( m_pFXChunk )
  {
    id = m_pFXChunk->aFX[(unsigned int)in_uFXIndex].id;
    if ( id )
    {
      if ( m_pFXChunk->aFX[v6].bShareSet )
        PtrAndAddRef = (CAkFxBase *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(&g_pIndex->m_idxFxShareSets, id);
      else
        PtrAndAddRef = (CAkFxBase *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                      (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
                                      id);
      m_pT = out_rFXInfo->pFx.m_pT;
      out_rFXInfo->pFx.m_pT = PtrAndAddRef;
    }
    else
    {
      m_pT = out_rFXInfo->pFx.m_pT;
      out_rFXInfo->pFx.m_pT = 0i64;
    }
    if ( m_pT )
      m_pT->vfptr->Release(m_pT);
    out_rFXInfo->bIsBypassed = CAkBus::GetBypassFX(this, v6);
  }
  else
  {
    v11 = out_rFXInfo->pFx.m_pT;
    out_rFXInfo->pFx.m_pT = 0i64;
    if ( v11 )
      ((void (__fastcall *)(CAkFxBase *, __int64, _QWORD, CAkRegisteredObj *))v11->vfptr->Release)(
        v11,
        in_uFXIndex,
        0i64,
        __formal);
    out_rFXInfo->bIsBypassed = 0;
  }
}

// File Line: 1640
// RVA: 0xA7BEB0
void __fastcall CAkBus::GetFXDataID(
        CAkBus *this,
        unsigned int in_uFXIndex,
        unsigned int in_uDataIndex,
        unsigned int *out_rDataID)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // r8
  bool v7; // zf
  unsigned int id; // edx
  CAkIndexable *v9; // rax
  unsigned int *v10; // rdx
  _DWORD *v11; // rax
  _DWORD *v12; // rcx
  unsigned int *v13; // rax
  unsigned int v14; // ecx

  *out_rDataID = -1;
  m_pFXChunk = this->m_pFXChunk;
  if ( m_pFXChunk )
  {
    v7 = !m_pFXChunk->aFX[in_uFXIndex].bShareSet;
    id = m_pFXChunk->aFX[in_uFXIndex].id;
    v9 = v7
       ? CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef((CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom, id)
       : CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(&g_pIndex->m_idxFxShareSets, id);
    v10 = (unsigned int *)v9;
    if ( v9 )
    {
      v11 = *(_DWORD **)&v9[1].key;
      v12 = &v11[2 * v10[12]];
      if ( v11 == v12 )
        goto LABEL_12;
      do
      {
        if ( *v11 == in_uDataIndex )
          break;
        v11 += 2;
      }
      while ( v11 != v12 );
      if ( v11 == v12 || (v13 = v11 + 1) == 0i64 )
LABEL_12:
        v14 = 0;
      else
        v14 = *v13;
      *out_rDataID = v14;
      (*(void (__fastcall **)(unsigned int *))(*(_QWORD *)v10 + 16i64))(v10);
    }
  }
}

// File Line: 1664
// RVA: 0xA7BC30
char __fastcall CAkBus::GetBypassFX(CAkBus *this, unsigned int in_uFXIndex)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // r9
  __int64 v3; // r8
  char v5; // dl
  unsigned __int64 m_iBitArray; // rax
  CAkSIS *m_pGlobalSIS; // rax

  m_pFXChunk = this->m_pFXChunk;
  v3 = in_uFXIndex;
  if ( !m_pFXChunk )
    return 0;
  v5 = ((unsigned __int8)m_pFXChunk->bitsMainFXBypass >> in_uFXIndex) & 1;
  if ( m_pFXChunk->aFX[v3].id )
  {
    m_iBitArray = this->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const __int64 *)&m_iBitArray, (unsigned __int8)(v3 + 24)) )
      return CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, v3 + 24, 0i64) != 0.0;
  }
  m_pGlobalSIS = this->m_pGlobalSIS;
  if ( m_pGlobalSIS )
    return ((unsigned __int8)m_pGlobalSIS->m_bitsFXBypass >> v3) & 1;
  return v5;
}

// File Line: 1685
// RVA: 0xA7BBC0
bool __fastcall CAkBus::GetBypassAllFX(CAkBus *this, CAkRegisteredObj *__formal)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rax
  bool v3; // dl
  CAkSIS *m_pGlobalSIS; // rax

  m_pFXChunk = this->m_pFXChunk;
  v3 = m_pFXChunk && (m_pFXChunk->bitsMainFXBypass & 0x10) != 0;
  if ( (this->m_RTPCBitArray.m_iBitArray & 0x10000000) != 0 )
    return CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x1Cu, 0i64) != 0.0;
  m_pGlobalSIS = this->m_pGlobalSIS;
  if ( m_pGlobalSIS )
    return (m_pGlobalSIS->m_bitsFXBypass & 0x10) != 0;
  else
    return v3;
}

// File Line: 1705
// RVA: 0xA7D140
void __fastcall CAkBus::ResetFXBypass(CAkBus *this, char in_bitsFXBypass, char in_uTargetMask)
{
  CAkSIS *m_pGlobalSIS; // rax

  m_pGlobalSIS = this->m_pGlobalSIS;
  if ( m_pGlobalSIS )
    m_pGlobalSIS->m_bitsFXBypass = in_bitsFXBypass | m_pGlobalSIS->m_bitsFXBypass & ~in_uTargetMask;
}

// File Line: 1720
// RVA: 0xA7D4C0
void __fastcall CAkBus::SetAkProp(
        CAkBus *this,
        AkPropID in_eProp,
        CAkRegisteredObj *in_pGameObj,
        AkValueMeaning in_eValueMeaning,
        float in_fTargetValue,
        AkCurveInterpolation in_eFadeCurve,
        int in_lTransitionTime)
{
  CAkSIS *v10; // rax

  v10 = (CAkSIS *)((__int64 (__fastcall *)(CAkBus *, _QWORD, CAkRegisteredObj *))this->vfptr[19].__vecDelDtor)(
                    this,
                    0i64,
                    in_pGameObj);
  if ( v10 )
    CAkParameterNodeBase::StartSISTransition(
      this,
      v10,
      in_eProp,
      in_fTargetValue,
      in_eValueMeaning,
      in_eFadeCurve,
      in_lTransitionTime);
}

// File Line: 1784
// RVA: 0xA7D0A0
void __fastcall CAkBus::ResetAkProp(
        CAkBus *this,
        __int64 in_eProp,
        AkCurveInterpolation in_eFadeCurve,
        int in_lTransitionTime)
{
  CAkSIS *m_pGlobalSIS; // r11
  char *m_pProps; // r11
  unsigned int v8; // r9d
  int i; // r10d
  __int64 v10; // rcx
  float *v11; // rcx

  m_pGlobalSIS = this->m_pGlobalSIS;
  if ( m_pGlobalSIS )
  {
    m_pProps = m_pGlobalSIS->m_values.m_pProps;
    if ( m_pProps )
    {
      v8 = (unsigned __int8)*m_pProps;
      for ( i = 0; ; ++i )
      {
        v10 = (unsigned int)(i + 1);
        if ( m_pProps[v10] == (_BYTE)in_eProp )
          break;
        if ( (unsigned int)v10 >= v8 )
          return;
      }
      v11 = (float *)&m_pProps[16 * i + ((v8 + 4) & 0xFFFFFFFC)];
      if ( v11 )
      {
        if ( *v11 != 0.0 )
          ((void (__fastcall *)(CAkBus *, __int64, _QWORD, _QWORD, _DWORD, AkCurveInterpolation, int))this->vfptr[11].Release)(
            this,
            in_eProp,
            0i64,
            0i64,
            0,
            in_eFadeCurve,
            in_lTransitionTime);
      }
    }
  }
}

// File Line: 1800
// RVA: 0xA7C590
void __fastcall CAkBus::Mute(
        CAkBus *this,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_eFadeCurve,
        int in_lTransitionTime)
{
  CAkSIS *v7; // rax

  if ( !in_pGameObj )
  {
    v7 = (CAkSIS *)((__int64 (__fastcall *)(CAkBus *))this->vfptr[19].__vecDelDtor)(this);
    if ( v7 )
      CAkParameterNodeBase::StartSisMuteTransitions(this, v7, 0.0, in_eFadeCurve, in_lTransitionTime);
  }
}

// File Line: 1818
// RVA: 0xA7DB10
void __fastcall CAkBus::Unmute(
        CAkBus *this,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_eFadeCurve,
        int in_lTransitionTime)
{
  CAkSIS *m_pGlobalSIS; // r10
  char *m_pProps; // r10
  unsigned int v9; // r8d
  int i; // ecx
  __int64 v11; // rdx
  float *v12; // rdx

  if ( !in_pGameObj )
  {
    m_pGlobalSIS = this->m_pGlobalSIS;
    if ( m_pGlobalSIS )
    {
      m_pProps = m_pGlobalSIS->m_values.m_pProps;
      if ( m_pProps )
      {
        v9 = (unsigned __int8)*m_pProps;
        for ( i = 0; ; ++i )
        {
          v11 = (unsigned int)(i + 1);
          if ( m_pProps[v11] == 10 )
            break;
          if ( (unsigned int)v11 >= v9 )
            return;
        }
        v12 = (float *)&m_pProps[16 * i + ((v9 + 4) & 0xFFFFFFFC)];
        if ( v12 )
        {
          if ( 1.0 != *v12 )
          {
            CAkRegistryMgr::SetNodeIDAsModified(g_pRegistryMgr, this);
            CAkParameterNodeBase::StartSisMuteTransitions(
              this,
              this->m_pGlobalSIS,
              1.0,
              in_eFadeCurve,
              in_lTransitionTime);
          }
        }
      }
    }
  }
}

// File Line: 1837
// RVA: 0xA7DBE0
void __fastcall CAkBus::UnmuteAll(CAkBus *this, unsigned int in_eFadeCurve, unsigned int in_lTransitionTime)
{
  ((void (__fastcall *)(CAkBus *, _QWORD, _QWORD, _QWORD))this->vfptr[12].AddRef)(
    this,
    0i64,
    in_eFadeCurve,
    in_lTransitionTime);
}

// File Line: 1842
// RVA: 0xA7C040
CAkSIS *__fastcall CAkBus::GetSIS(CAkBus *this, CAkRegisteredObj *__formal)
{
  char v3; // si
  unsigned int i; // ebx
  char BypassFX; // al
  char v6; // cl
  CAkSIS *result; // rax

  CAkRegistryMgr::SetNodeIDAsModified(g_pRegistryMgr, this);
  if ( !this->m_pGlobalSIS )
  {
    v3 = 0;
    for ( i = 0; i < 4; ++i )
    {
      BypassFX = CAkBus::GetBypassFX(this, i);
      v6 = i;
      v3 |= (BypassFX != 0) << v6;
    }
    result = (CAkSIS *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
    if ( result )
    {
      result->m_pParamNode = this;
      result->m_pGameObj = 0i64;
      result->vfptr = (ITransitionableVtbl *)&CAkSIS::`vftable;
      result->m_values.m_pProps = 0i64;
      result->m_bitsFXBypass = v3;
      this->m_pGlobalSIS = result;
      return result;
    }
    this->m_pGlobalSIS = 0i64;
  }
  return this->m_pGlobalSIS;
}

// File Line: 1857
// RVA: 0xA7CD90
void __fastcall CAkBus::RecalcNotification(CAkBus *this)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rax
  unsigned int v3; // ecx
  unsigned int *p_id; // rax
  char v5; // al
  float BusEffectiveVolume; // xmm0_4
  AkActivityChunk *m_pActivityChunk; // rdi
  CAkParameterNodeBase **m_pItems; // rbx
  AkActivityChunk *v9; // rax

  m_pFXChunk = this->m_pFXChunk;
  if ( m_pFXChunk )
  {
    v3 = 0;
    p_id = &m_pFXChunk->aFX[0].id;
    while ( !*p_id )
    {
      ++v3;
      p_id += 2;
      if ( v3 >= 4 )
        goto LABEL_5;
    }
    goto LABEL_10;
  }
LABEL_5:
  if ( this->vfptr[3].Release(this) == 12
    || this->m_uChannelConfig
    || (v5 = *((_BYTE *)&this->CAkParameterNodeBase + 83), (v5 & 4) != 0)
    || !this->m_pBusOutputNode
    || (v5 & 8) != 0 )
  {
LABEL_10:
    BusEffectiveVolume = CAkBus::GetBusEffectiveVolume(this, BusVolumeType_ToNextBusWithEffect, AkPropID_BusVolume);
    *((_BYTE *)this + 304) |= 0x20u;
    if ( this->m_pBusOutputNode )
      CAkLEngine::ResetBusVolume(this->key, BusEffectiveVolume);
    else
      CAkLEngine::ResetMasterBusVolume(*((_BYTE *)this + 304) >> 7, BusEffectiveVolume);
  }
  *((_BYTE *)this + 304) &= ~1u;
  if ( (*((_BYTE *)this + 304) & 1) == 0 )
    CAkBus::UpdateVoiceVolumes(this);
  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    if ( m_pItems != &m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v9 = (*m_pItems)->m_pActivityChunk;
        if ( v9 && (v9->m_PlayCount || v9->m_uActivityCount) )
          (*m_pItems)->vfptr[12].Category(*m_pItems);
        ++m_pItems;
      }
      while ( m_pItems != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 1895
// RVA: 0xA7BFE0
CAkBus *__fastcall CAkBus::GetPrimaryMasterBusAndAddRef()
{
  CAkAudioLibIndex *NodeLock; // rbx
  CAkBus *m_pBus; // rdi

  NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  m_pBus = g_MasterBusCtx.m_pBus;
  if ( g_MasterBusCtx.m_pBus )
    g_MasterBusCtx.m_pBus->vfptr->AddRef(g_MasterBusCtx.m_pBus);
  LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  return m_pBus;
}

// File Line: 1905
// RVA: 0xA7C0F0
CAkBus *__fastcall CAkBus::GetSecondaryMasterBusAndAddRef()
{
  CAkAudioLibIndex *NodeLock; // rbx
  CAkBus *m_pBus; // rdi

  NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  m_pBus = g_SecondaryMasterBusCtx.m_pBus;
  if ( g_SecondaryMasterBusCtx.m_pBus )
    g_SecondaryMasterBusCtx.m_pBus->vfptr->AddRef(g_SecondaryMasterBusCtx.m_pBus);
  LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  return m_pBus;
}

// File Line: 1915
// RVA: 0xA7B1F0
void CAkBus::ClearMasterBus(void)
{
  CAkAudioLibIndex *NodeLock; // rbx

  NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  g_MasterBusCtx.m_pBus = 0i64;
  g_SecondaryMasterBusCtx.m_pBus = 0i64;
  LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
}

// File Line: 1922
// RVA: 0xA7DE50
void __fastcall CAkBus::UpdateVoiceVolumes(CAkBus *this)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rax
  unsigned int v3; // edx
  unsigned int *p_id; // rax
  char v5; // al
  float BusEffectiveVolume; // xmm0_4

  m_pFXChunk = this->m_pFXChunk;
  if ( m_pFXChunk )
  {
    v3 = 0;
    p_id = &m_pFXChunk->aFX[0].id;
    while ( !*p_id )
    {
      ++v3;
      p_id += 2;
      if ( v3 >= 4 )
        goto LABEL_5;
    }
    goto LABEL_11;
  }
LABEL_5:
  if ( this->vfptr[3].Release(this) == 12
    || this->m_uChannelConfig
    || (v5 = *((_BYTE *)&this->CAkParameterNodeBase + 83), (v5 & 4) != 0)
    || !this->m_pBusOutputNode
    || (v5 & 8) != 0 )
  {
LABEL_11:
    this->m_fEffectiveBusVolume = 0.0;
    goto LABEL_12;
  }
  this->m_fEffectiveBusVolume = CAkBus::GetBusEffectiveVolume(
                                  this,
                                  BusVolumeType_ToNextBusWithEffect,
                                  AkPropID_BusVolume);
LABEL_12:
  BusEffectiveVolume = CAkBus::GetBusEffectiveVolume(this, BusVolumeType_IncludeEntireBusTree, AkPropID_Volume);
  *((_BYTE *)this + 304) |= 1u;
  this->m_fEffectiveVoiceVolume = BusEffectiveVolume;
}

// File Line: 1935
// RVA: 0xA7C6B0
void __fastcall CAkBus::NotifyHdrWindowTop(CAkBus *this, float in_fWindowTop)
{
  char *m_pProps; // rdx
  __int64 v3; // r9
  unsigned int v4; // r10d
  __int64 v5; // rcx
  __int64 v6; // r8
  __int64 v7; // r8
  unsigned int *v8; // rax
  unsigned int v9; // r11d
  unsigned int v10; // r10d
  __int64 v11; // rcx
  __int64 v12; // r8
  __int64 v13; // r8
  float *p_fValue; // rax
  unsigned int v15; // r10d
  __int64 v16; // rcx
  __int64 v17; // r8
  float v18; // xmm0_4
  int *v19; // rax
  float fValue; // [rsp+40h] [rbp+8h] BYREF
  float v21; // [rsp+50h] [rbp+18h]
  TransParams in_transParams; // [rsp+58h] [rbp+20h] BYREF

  m_pProps = this->m_props.m_pProps;
  v3 = 0i64;
  fValue = 0.0;
  if ( m_pProps )
  {
    v4 = (unsigned __int8)*m_pProps;
    v5 = 0i64;
    while ( 1 )
    {
      v6 = (unsigned int)(v5 + 1);
      if ( m_pProps[v6] == 29 )
        break;
      v5 = (unsigned int)v6;
      if ( (unsigned int)v6 >= v4 )
        goto LABEL_5;
    }
    v7 = (__int64)&m_pProps[4 * v5 + ((v4 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v7 = 0i64;
  }
  v8 = (unsigned int *)&fValue;
  if ( v7 )
    v8 = (unsigned int *)v7;
  v9 = *v8;
  if ( *v8 )
  {
    in_transParams.TransitionTime = 0;
    in_transParams.eFadeCurve = AkCurveInterpolation_Linear;
    fValue = g_AkPropDefault[30].fValue;
    if ( m_pProps )
    {
      v10 = (unsigned __int8)*m_pProps;
      v11 = 0i64;
      while ( 1 )
      {
        v12 = (unsigned int)(v11 + 1);
        if ( m_pProps[v12] == 30 )
          break;
        v11 = (unsigned int)v12;
        if ( (unsigned int)v12 >= v10 )
          goto LABEL_13;
      }
      v13 = (__int64)&m_pProps[4 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_13:
      v13 = 0i64;
    }
    p_fValue = &fValue;
    if ( v13 )
      p_fValue = (float *)v13;
    v21 = *p_fValue;
    fValue = g_AkPropDefault[31].fValue;
    if ( m_pProps )
    {
      v15 = (unsigned __int8)*m_pProps;
      v16 = 0i64;
      while ( 1 )
      {
        v17 = (unsigned int)(v16 + 1);
        if ( m_pProps[v17] == 31 )
          break;
        v16 = (unsigned int)v17;
        if ( (unsigned int)v17 >= v15 )
          goto LABEL_24;
      }
      v3 = (__int64)&m_pProps[4 * v16 + ((v15 + 4) & 0xFFFFFFFC)];
    }
LABEL_24:
    v18 = v21;
    v19 = (int *)&fValue;
    if ( v3 )
      v19 = (int *)v3;
    fValue = *(float *)v19;
    if ( in_fWindowTop < v21 || (v18 = fValue, in_fWindowTop > fValue) )
      in_fWindowTop = v18;
    CAkRTPCMgr::SetRTPCInternal(g_pRTPCMgr, v9, in_fWindowTop, 0i64, &in_transParams, AkValueMeaning_Independent);
  }
}

