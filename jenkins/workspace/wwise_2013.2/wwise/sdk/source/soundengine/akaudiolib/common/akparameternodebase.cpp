// File Line: 71
// RVA: 0xA70740
__int64 __fastcall CAkLimiter::Add(CAkLimiter *this, CAkPBI *in_pPBI, AKVoiceLimiterType in_Type)
{
  AkPriorityStruct currentPriority; // rdx
  bool v5; // r14
  CAkPBI **v8; // rax
  CAkPBI **v9; // rsi
  int v10; // ebx

  currentPriority = in_pPBI->m_PriorityInfoCurrent.currentPriority;
  v5 = this->m_sortedPBIList.m_uLength == 0;
  if ( this->m_bDoesKillNewest )
    v8 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::AddNoSetKey<AkPriorityStruct_INC>(
           &this->m_sortedPBIList,
           (AkPriorityStruct_INC)currentPriority);
  else
    v8 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::AddNoSetKey<AkPriorityStruct_DEC>(
           &this->m_sortedPBIList,
           (AkPriorityStruct_DEC)currentPriority);
  v9 = v8;
  if ( !v8 )
    return 2i64;
  if ( v5 )
  {
    v10 = in_Type - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
      {
        CAkURenderer::AddBusLimiter(this);
        *v9 = in_pPBI;
        return 1i64;
      }
    }
    else
    {
      CAkURenderer::AddAMLimiter(this);
    }
  }
  *v9 = in_pPBI;
  return 1i64;
}

// File Line: 111
// RVA: 0xA734A0
void __fastcall CAkLimiter::Remove(CAkLimiter *this, CAkPBI *in_pPBI, AKVoiceLimiterType in_Type)
{
  AkPriorityStruct currentPriority; // rdx
  CAkPBI **v6; // rax
  CAkPBI **v7; // rcx
  int v8; // ebp
  bool out_bFound; // [rsp+30h] [rbp+8h] BYREF

  currentPriority = in_pPBI->m_PriorityInfoCurrent.currentPriority;
  if ( this->m_bDoesKillNewest )
    v6 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_INC>(
           &this->m_sortedPBIList,
           (AkPriorityStruct_INC)currentPriority,
           &out_bFound);
  else
    v6 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_DEC>(
           &this->m_sortedPBIList,
           (AkPriorityStruct_DEC)currentPriority,
           &out_bFound);
  if ( out_bFound )
  {
    v7 = &this->m_sortedPBIList.m_pItems[this->m_sortedPBIList.m_uLength - 1];
    if ( v6 < v7 )
      qmemcpy(v6, v6 + 1, 8 * (((unsigned __int64)((char *)v7 - (char *)v6 - 1) >> 3) + 1));
    --this->m_sortedPBIList.m_uLength;
  }
  if ( !this->m_sortedPBIList.m_uLength )
  {
    v8 = in_Type - 1;
    if ( v8 )
    {
      if ( v8 == 1 )
        CAkURenderer::RemoveBusLimiter(this);
    }
    else
    {
      CAkURenderer::RemoveAMLimiter(this);
    }
  }
}

// File Line: 141
// RVA: 0xA74C10
void __fastcall CAkLimiter::Update(CAkLimiter *this, float in_NewPriority, CAkPBI *in_pPBI)
{
  AkPriorityStruct currentPriority; // rdx
  AkPriorityStruct_INC v5; // r8

  currentPriority = in_pPBI->m_PriorityInfoCurrent.currentPriority;
  v5 = (AkPriorityStruct_INC)__PAIR64__(in_pPBI->m_PriorityInfoCurrent.currentPriority.PBIID, LODWORD(in_NewPriority));
  if ( this->m_bDoesKillNewest )
    AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::Reorder<AkPriorityStruct_INC>(
      &this->m_sortedPBIList,
      (AkPriorityStruct_INC)currentPriority,
      v5,
      in_pPBI);
  else
    AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::Reorder<AkPriorityStruct_DEC>(
      &this->m_sortedPBIList,
      (AkPriorityStruct_DEC)currentPriority,
      (AkPriorityStruct_DEC)v5,
      in_pPBI);
}

// File Line: 168
// RVA: 0xA74C50
void __fastcall CAkLimiter::UpdateFlags(CAkLimiter *this)
{
  unsigned __int16 m_u16LimiterMax; // ax
  unsigned int v3; // r8d
  __int64 m_uLength; // rax
  CAkPBI **m_pItems; // rbx
  CAkPBI **v6; // rdi
  unsigned int v7; // edx
  char v8; // al
  CAkPBI *v9; // rcx
  KickFrom v10; // edx

  m_u16LimiterMax = this->m_u16LimiterMax;
  if ( m_u16LimiterMax )
  {
    v3 = m_u16LimiterMax;
    m_uLength = this->m_sortedPBIList.m_uLength;
    if ( (unsigned int)m_uLength > v3 )
    {
      m_pItems = this->m_sortedPBIList.m_pItems;
      v6 = &this->m_sortedPBIList.m_pItems[m_uLength];
      v7 = 0;
      if ( this->m_sortedPBIList.m_pItems != v6 )
      {
        while ( v7 < v3 )
        {
          v8 = *((_BYTE *)*m_pItems + 375);
          if ( ((v8 & 0x40) == 0 || (v8 & 0x20) != 0) && (*((_BYTE *)*m_pItems + 374) & 1) == 0 && (v8 & 0x10) == 0 )
            ++v7;
          if ( ++m_pItems == v6 )
            return;
        }
        for ( ; m_pItems != v6; ++m_pItems )
        {
          v9 = *m_pItems;
          if ( (*((_BYTE *)*m_pItems + 374) & 1) == 0 )
          {
            v10 = KickFrom_OverNodeLimit;
            if ( this == &CAkURenderer::m_GlobalLimiter )
              v10 = KickFrom_OverGlobalLimit;
            if ( this->m_bAllowUseVirtualBehavior )
              CAkPBI::ForceVirtualize(v9, v10);
            else
              CAkPBI::Kick(v9, v10);
          }
        }
      }
    }
  }
}

// File Line: 280
// RVA: 0xA70510
void __fastcall CAkParameterNodeBase::CAkParameterNodeBase(CAkParameterNodeBase *this, unsigned int in_ulID)
{
  CAkIndexable::CAkIndexable(this, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkParameterNodeBase::`vftable;
  this->m_states.m_pFirst = 0i64;
  this->m_pGlobalSIS = 0i64;
  this->m_pFXChunk = 0i64;
  this->m_pActivityChunk = 0i64;
  this->m_pParentNode = 0i64;
  this->m_pBusOutputNode = 0i64;
  this->m_props.m_pProps = 0i64;
  *(_DWORD *)&this->m_u16MaxNumInstance = 9437184;
  this->m_RTPCBitArray.m_iBitArray = 0i64;
  this->m_pFeedbackInfo = 0i64;
}

// File Line: 285
// RVA: 0xA705E0
void __fastcall CAkParameterNodeBase::~CAkParameterNodeBase(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rdx
  unsigned int i; // esi
  CAkSIS *m_pGlobalSIS; // rsi
  int v5; // edi
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rcx
  CAkFeedbackBus *m_pFeedbackBus; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *v8; // rdx
  char *m_pProps; // rdx

  m_pFXChunk = this->m_pFXChunk;
  *((_BYTE *)this + 83) |= 1u;
  this->vfptr = (CAkIndexableVtbl *)&CAkParameterNodeBase::`vftable;
  if ( m_pFXChunk )
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pFXChunk);
  for ( i = 0; this->m_RTPCBitArray.m_iBitArray; ++i )
  {
    if ( ((1i64 << i) & this->m_RTPCBitArray.m_iBitArray) != 0 )
    {
      CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, this, i);
      this->m_RTPCBitArray.m_iBitArray &= ~(1i64 << i);
    }
  }
  m_pGlobalSIS = this->m_pGlobalSIS;
  if ( m_pGlobalSIS )
  {
    v5 = g_DefaultPoolId;
    CAkSIS::~CAkSIS(this->m_pGlobalSIS);
    AK::MemoryMgr::Free(v5, m_pGlobalSIS);
  }
  if ( this->m_states.m_pFirst )
  {
    CAkParameterNodeBase::FlushStateTransitions(this);
    CAkParameterNodeBase::RemoveStateGroups(this, 1);
  }
  m_pFeedbackInfo = this->m_pFeedbackInfo;
  this->m_states.m_pFirst = 0i64;
  if ( m_pFeedbackInfo )
  {
    m_pFeedbackBus = m_pFeedbackInfo->m_pFeedbackBus;
    if ( m_pFeedbackBus )
      m_pFeedbackBus->vfptr[3].__vecDelDtor(m_pFeedbackBus, (unsigned int)this);
    v8 = this->m_pFeedbackInfo;
    if ( v8 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v8);
  }
  if ( this->m_pActivityChunk )
    CAkParameterNodeBase::DeleteActivityChunk(this);
  m_pProps = this->m_props.m_pProps;
  if ( m_pProps )
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pProps);
  this->m_props.m_pProps = 0i64;
  CAkPBIAware::~CAkPBIAware(this);
}

// File Line: 333
// RVA: 0xA70DE0
void __fastcall CAkParameterNodeBase::AddToIndex(CAkParameterNodeBase *this)
{
  CAkAudioLibIndex *NodeLock; // rbx
  __int64 v3; // rcx

  NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, (AkNodeType)((*((_BYTE *)this + 83) & 2) != 0));
  EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  v3 = this->key % 0xC1;
  this->pNextItem = NodeLock->m_idxAudioNode.m_mapIDToPtr.m_table[v3];
  NodeLock->m_idxAudioNode.m_mapIDToPtr.m_table[v3] = this;
  ++NodeLock->m_idxAudioNode.m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
}

// File Line: 345
// RVA: 0xA70A80
__int64 __fastcall CAkParameterNodeBase::AddRef(CAkParameterNodeBase *this)
{
  CAkAudioLibIndex *NodeLock; // rbx
  unsigned int v3; // edi

  NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, (AkNodeType)((*((_BYTE *)this + 83) & 2) != 0));
  EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  v3 = this->m_lRef + 1;
  this->m_lRef = v3;
  LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 351
// RVA: 0xA733C0
__int64 __fastcall CAkParameterNodeBase::Release(CAkParameterNodeBase *this)
{
  AkNodeType v2; // r14d
  CAkAudioLibIndex *NodeLock; // rbx
  bool v4; // zf
  unsigned int m_lRef; // ebp
  unsigned int key; // edi
  CAkAudioLibIndex *v7; // rax
  CAkParameterNodeBase *m_pParentNode; // rcx
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  int v10; // edi

  v2 = AkNodeType_Default;
  NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, (AkNodeType)((*((_BYTE *)this + 83) & 2) != 0));
  EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  v4 = this->m_lRef-- == 1;
  m_lRef = this->m_lRef;
  if ( v4 )
  {
    key = this->key;
    LOBYTE(v2) = (*((_BYTE *)this + 83) & 2) != 0;
    v7 = CAkAudioLibIndex::GetNodeLock(g_pIndex, v2);
    CAkIndexItem<CAkEvent *>::RemoveID(&v7->m_idxAudioNode, key);
    this->vfptr[1].AddRef(this);
    m_pParentNode = this->m_pParentNode;
    if ( m_pParentNode )
      m_pParentNode->vfptr[3].__vecDelDtor(m_pParentNode, (unsigned int)this);
    m_pBusOutputNode = this->m_pBusOutputNode;
    if ( m_pBusOutputNode )
      m_pBusOutputNode->vfptr[3].__vecDelDtor(m_pBusOutputNode, (unsigned int)this);
    v10 = g_DefaultPoolId;
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v10, this);
  }
  LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  return m_lRef;
}

// File Line: 416
// RVA: 0xA748F0
__int64 __fastcall CAkParameterNodeBase::Stop(
        CAkParameterNodeBase *this,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_PlayingID,
        int in_uTransitionDuration,
        AkCurveInterpolation in_eFadeCurve)
{
  CAkIndexableVtbl *vfptr; // rax
  int v7; // [rsp+20h] [rbp-38h] BYREF
  CAkRegisteredObj *v8; // [rsp+28h] [rbp-30h]
  unsigned int v9; // [rsp+30h] [rbp-28h]
  int v10; // [rsp+34h] [rbp-24h]
  AkCurveInterpolation v11; // [rsp+38h] [rbp-20h]
  __int16 v12; // [rsp+3Ch] [rbp-1Ch]
  char v13; // [rsp+3Eh] [rbp-1Ah]

  v8 = in_pGameObj;
  v11 = in_eFadeCurve;
  vfptr = this->vfptr;
  v12 = 0;
  v13 = 0;
  v7 = 0;
  v9 = in_PlayingID;
  v10 = in_uTransitionDuration;
  return (__int64)vfptr[4].__vecDelDtor(this, (unsigned int)&v7);
}

// File Line: 434
// RVA: 0xA73040
__int64 __fastcall CAkParameterNodeBase::Pause(
        CAkParameterNodeBase *this,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_PlayingID,
        int in_uTransitionDuration,
        AkCurveInterpolation in_eFadeCurve)
{
  CAkIndexableVtbl *vfptr; // rax
  int v7; // [rsp+20h] [rbp-38h] BYREF
  CAkRegisteredObj *v8; // [rsp+28h] [rbp-30h]
  unsigned int v9; // [rsp+30h] [rbp-28h]
  int v10; // [rsp+34h] [rbp-24h]
  AkCurveInterpolation v11; // [rsp+38h] [rbp-20h]
  __int16 v12; // [rsp+3Ch] [rbp-1Ch]
  char v13; // [rsp+3Eh] [rbp-1Ah]

  v8 = in_pGameObj;
  v11 = in_eFadeCurve;
  vfptr = this->vfptr;
  v12 = 0;
  v13 = 0;
  v7 = 1;
  v9 = in_PlayingID;
  v10 = in_uTransitionDuration;
  return (__int64)vfptr[4].__vecDelDtor(this, (unsigned int)&v7);
}

// File Line: 452
// RVA: 0xA73890
__int64 __fastcall CAkParameterNodeBase::Resume(
        CAkParameterNodeBase *this,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_PlayingID,
        int in_uTransitionDuration,
        AkCurveInterpolation in_eFadeCurve)
{
  CAkIndexableVtbl *vfptr; // rax
  int v7; // [rsp+20h] [rbp-38h] BYREF
  CAkRegisteredObj *v8; // [rsp+28h] [rbp-30h]
  unsigned int v9; // [rsp+30h] [rbp-28h]
  int v10; // [rsp+34h] [rbp-24h]
  AkCurveInterpolation v11; // [rsp+38h] [rbp-20h]
  __int16 v12; // [rsp+3Ch] [rbp-1Ch]
  char v13; // [rsp+3Eh] [rbp-1Ah]

  v8 = in_pGameObj;
  v11 = in_eFadeCurve;
  vfptr = this->vfptr;
  v12 = 0;
  v13 = 0;
  v7 = 2;
  v9 = in_PlayingID;
  v10 = in_uTransitionDuration;
  return (__int64)vfptr[4].__vecDelDtor(this, (unsigned int)&v7);
}

// File Line: 471
// RVA: 0xA72C80
void __fastcall CAkParameterNodeBase::Notification(
        CAkParameterNodeBase *this,
        AkRTPC_ParameterID in_ParamID,
        float in_fValue,
        CAkRegisteredObj *in_pGameObj,
        void *in_pExceptArray)
{
  CAkIndexableVtbl *vfptr; // rax
  AkRTPC_ParameterID v9; // [rsp+20h] [rbp-48h] BYREF
  CAkRegisteredObj *v10; // [rsp+28h] [rbp-40h]
  char v11; // [rsp+30h] [rbp-38h]
  void *v12; // [rsp+38h] [rbp-30h]
  float v13; // [rsp+40h] [rbp-28h]

  if ( (unsigned __int8)this->vfptr[15].Release(this) )
  {
    v13 = in_fValue;
    v12 = in_pExceptArray;
    vfptr = this->vfptr;
    v9 = in_ParamID;
    v11 = 0;
    v10 = in_pGameObj;
    vfptr[5].__vecDelDtor(this, (unsigned int)&v9);
  }
}

// File Line: 497
// RVA: 0xA731B0
void __fastcall CAkParameterNodeBase::PriorityNotification(CAkParameterNodeBase *this, NotifParams *in_rParams)
{
  this->vfptr[5].__vecDelDtor(this, (unsigned int)in_rParams);
}

// File Line: 502
// RVA: 0xA72B50
bool __fastcall CAkParameterNodeBase::IsException(
        CAkParameterNodeBase *in_pNode,
        AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_rExceptionList)
{
  char v2; // r8
  unsigned int key; // r9d
  WwiseObjectIDext *m_pItems; // rcx
  WwiseObjectIDext *v5; // rdx
  bool i; // r8
  WwiseObjectIDext *v7; // r8

  v2 = *((_BYTE *)in_pNode + 83);
  key = in_pNode->key;
  m_pItems = in_rExceptionList->m_pItems;
  v5 = &in_rExceptionList->m_pItems[in_rExceptionList->m_uLength];
  for ( i = (v2 & 2) != 0; m_pItems != v5; ++m_pItems )
  {
    if ( key == m_pItems->id && i == m_pItems->bIsBus )
      break;
  }
  v7 = 0i64;
  if ( m_pItems != v5 )
    v7 = m_pItems;
  return v7 != 0i64;
}

// File Line: 508
// RVA: 0xA721C0
CAkBus *__fastcall CAkParameterNodeBase::GetMixingBus(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase *m_pBusOutputNode; // rcx

  m_pBusOutputNode = this->m_pBusOutputNode;
  if ( m_pBusOutputNode )
    return (CAkBus *)((__int64 (__fastcall *)(CAkParameterNodeBase *))m_pBusOutputNode->vfptr[7].Category)(m_pBusOutputNode);
  m_pBusOutputNode = this->m_pParentNode;
  if ( m_pBusOutputNode )
    return (CAkBus *)((__int64 (__fastcall *)(CAkParameterNodeBase *))m_pBusOutputNode->vfptr[7].Category)(m_pBusOutputNode);
  else
    return 0i64;
}

// File Line: 527
// RVA: 0xA72190
CAkBus *__fastcall CAkParameterNodeBase::GetLimitingBus(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase *m_pBusOutputNode; // rcx

  m_pBusOutputNode = this->m_pBusOutputNode;
  if ( m_pBusOutputNode )
    return (CAkBus *)((__int64 (__fastcall *)(CAkParameterNodeBase *))m_pBusOutputNode->vfptr[8].__vecDelDtor)(m_pBusOutputNode);
  m_pBusOutputNode = this->m_pParentNode;
  if ( m_pBusOutputNode )
    return (CAkBus *)((__int64 (__fastcall *)(CAkParameterNodeBase *))m_pBusOutputNode->vfptr[8].__vecDelDtor)(m_pBusOutputNode);
  else
    return 0i64;
}

// File Line: 546
// RVA: 0xA71E20
CAkBus *__fastcall CAkParameterNodeBase::GetControlBus(CAkParameterNodeBase *this)
{
  if ( this->m_pBusOutputNode )
    return (CAkBus *)this->m_pBusOutputNode;
  while ( 1 )
  {
    this = this->m_pParentNode;
    if ( !this )
      break;
    if ( this->m_pBusOutputNode )
      return (CAkBus *)this->m_pBusOutputNode;
  }
  return 0i64;
}

// File Line: 565
// RVA: 0xA73150
__int64 __fastcall CAkParameterNodeBase::PrepareNodeData(unsigned int in_NodeID)
{
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v2; // rbx
  __int64 result; // rax
  unsigned int v4; // edi

  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_NodeID, AkNodeType_Default);
  v2 = NodePtrAndAddRef;
  if ( !NodePtrAndAddRef )
    return 2i64;
  result = ((__int64 (__fastcall *)(CAkParameterNodeBase *))NodePtrAndAddRef->vfptr[10].__vecDelDtor)(NodePtrAndAddRef);
  v4 = result;
  if ( (_DWORD)result != 1 )
  {
    v2->vfptr->Release(v2);
    return v4;
  }
  return result;
}

// File Line: 583
// RVA: 0xA749E0
void __fastcall CAkParameterNodeBase::UnPrepareNodeData(unsigned int in_NodeID)
{
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v2; // rbx

  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_NodeID, AkNodeType_Default);
  v2 = NodePtrAndAddRef;
  if ( NodePtrAndAddRef )
  {
    NodePtrAndAddRef->vfptr[10].AddRef(NodePtrAndAddRef);
    v2->vfptr->Release(v2);
    v2->vfptr->Release(v2);
  }
}

// File Line: 595
// RVA: 0xA714D0
void __fastcall CAkParameterNodeBase::DeleteActivityChunk(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase *m_pParentNode; // r8
  AkActivityChunk *m_pActivityChunk; // r8
  CAkParameterNodeBase **m_pItems; // rax
  __int64 m_uLength; // rdx
  CAkParameterNodeBase **v6; // rcx
  CAkParameterNodeBase *m_pBusOutputNode; // r8
  AkActivityChunk *v8; // r8
  CAkParameterNodeBase **v9; // rax
  __int64 v10; // rdx
  CAkParameterNodeBase **v11; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rax
  AkActivityChunk *v13; // rdi
  int v14; // esi

  if ( this->m_pActivityChunk )
  {
    m_pParentNode = this->m_pParentNode;
    if ( m_pParentNode )
    {
      m_pActivityChunk = m_pParentNode->m_pActivityChunk;
      if ( m_pActivityChunk )
      {
        m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
        m_uLength = m_pActivityChunk->m_ActiveChildren.m_uLength;
        v6 = &m_pItems[m_uLength];
        if ( m_pItems != v6 )
        {
          do
          {
            if ( *m_pItems == this )
              break;
            ++m_pItems;
          }
          while ( m_pItems != v6 );
          if ( m_pItems != v6 )
          {
            if ( (unsigned int)m_uLength > 1 )
              *m_pItems = *(v6 - 1);
            --m_pActivityChunk->m_ActiveChildren.m_uLength;
          }
        }
      }
    }
    m_pBusOutputNode = this->m_pBusOutputNode;
    if ( m_pBusOutputNode )
    {
      v8 = m_pBusOutputNode->m_pActivityChunk;
      if ( v8 )
      {
        v9 = v8->m_ActiveChildren.m_pItems;
        v10 = v8->m_ActiveChildren.m_uLength;
        v11 = &v9[v10];
        if ( v9 != v11 )
        {
          do
          {
            if ( *v9 == this )
              break;
            ++v9;
          }
          while ( v9 != v11 );
          if ( v9 != v11 )
          {
            if ( (unsigned int)v10 > 1 )
              *v9 = *(v11 - 1);
            --v8->m_ActiveChildren.m_uLength;
          }
        }
      }
    }
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo && m_pFeedbackInfo->m_pFeedbackBus )
      CAkParameterNodeBase::UnsetFastActive(m_pFeedbackInfo->m_pFeedbackBus, this);
  }
  v13 = this->m_pActivityChunk;
  v14 = g_DefaultPoolId;
  if ( v13 )
  {
    AkActivityChunk::~AkActivityChunk(v13);
    AK::MemoryMgr::Free(v14, v13);
  }
  this->m_pActivityChunk = 0i64;
}

// File Line: 615
// RVA: 0xA718A0
void __fastcall CAkParameterNodeBase::FlushStateTransitions(CAkParameterNodeBase *this)
{
  AkStateGroupChunk *i; // rbx
  char *m_pProps; // rcx
  unsigned __int8 *v3; // rdx
  unsigned __int8 *v4; // rdi
  __int64 v5; // rsi
  CAkTransition **v6; // rdi
  __int64 v7; // rsi

  for ( i = this->m_states.m_pFirst; i; i = i->m_pNextInNode )
  {
    m_pProps = i->m_values.m_pProps;
    if ( m_pProps )
    {
      v3 = (unsigned __int8 *)(m_pProps + 1);
      v4 = (unsigned __int8 *)&m_pProps[((unsigned __int8)*m_pProps + 4) & 0xFFFFFFFC];
    }
    else
    {
      v3 = 0i64;
      v4 = 0i64;
    }
    if ( m_pProps )
      v5 = (__int64)&m_pProps[(unsigned __int8)*m_pProps + 1];
    else
      v5 = 0i64;
    if ( v3 != (unsigned __int8 *)v5 )
    {
      v6 = (CAkTransition **)(v4 + 8);
      v7 = v5 - (_QWORD)v3;
      do
      {
        if ( *v6 )
        {
          CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, *v6, i);
          *v6 = 0i64;
          ((void (__fastcall *)(CAkParameterNodeBase *, __int64))i->m_pOwner->vfptr[9].Category)(i->m_pOwner, 3i64);
        }
        v6 += 2;
        --v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 621
// RVA: 0xA72F20
_BOOL8 __fastcall CAkParameterNodeBase::OnNewActivityChunk(
        CAkParameterNodeBase *this,
        unsigned __int16 in_flagForwardToBus)
{
  bool v2; // bl
  unsigned __int16 v3; // di
  CAkParameterNodeBase *m_pBusOutputNode; // rbp
  char v6; // al
  AkActivityChunk *m_pActivityChunk; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rax
  CAkParameterNodeBase *m_pFeedbackBus; // rbp
  char v10; // cl
  AkActivityChunk *v11; // rax
  CAkParameterNodeBase *m_pParentNode; // rbp
  char v13; // cl
  AkActivityChunk *v14; // rax
  _BOOL8 result; // rax

  v2 = 1;
  v3 = in_flagForwardToBus;
  if ( (in_flagForwardToBus & 1) != 0 )
  {
    m_pBusOutputNode = this->m_pBusOutputNode;
    if ( m_pBusOutputNode )
    {
      v6 = CAkParameterNodeBase::EnableActivityChunk(this->m_pBusOutputNode, 3u);
      m_pActivityChunk = m_pBusOutputNode->m_pActivityChunk;
      if ( m_pActivityChunk )
        v6 = AkArray<CAkParameterNodeBase *,CAkParameterNodeBase *,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(
               &m_pActivityChunk->m_ActiveChildren,
               this) != 0i64;
      v2 = v6 != 0;
      v3 &= ~1u;
    }
  }
  if ( (v3 & 2) != 0 )
  {
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
    {
      m_pFeedbackBus = m_pFeedbackInfo->m_pFeedbackBus;
      if ( m_pFeedbackInfo->m_pFeedbackBus )
      {
        v10 = CAkParameterNodeBase::EnableActivityChunk(m_pFeedbackInfo->m_pFeedbackBus, 3u);
        v11 = m_pFeedbackBus->m_pActivityChunk;
        if ( v11 )
          v10 = AkArray<CAkParameterNodeBase *,CAkParameterNodeBase *,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(
                  &v11->m_ActiveChildren,
                  this) != 0i64;
        if ( !v10 )
          v2 = 0;
        v3 &= ~2u;
      }
    }
  }
  m_pParentNode = this->m_pParentNode;
  if ( !m_pParentNode )
    return v2;
  v13 = CAkParameterNodeBase::EnableActivityChunk(this->m_pParentNode, v3);
  v14 = m_pParentNode->m_pActivityChunk;
  if ( v14 )
    v13 = AkArray<CAkParameterNodeBase *,CAkParameterNodeBase *,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(
            &v14->m_ActiveChildren,
            this) != 0i64;
  result = v2;
  if ( !v13 )
    return 0i64;
  return result;
}

// File Line: 664
// RVA: 0xA74AB0
void __fastcall CAkParameterNodeBase::UnsetFastActive(CAkParameterNodeBase *this, CAkParameterNodeBase *in_pChild)
{
  AkActivityChunk *m_pActivityChunk; // r8
  CAkParameterNodeBase **m_pItems; // rax
  __int64 m_uLength; // r9
  CAkParameterNodeBase **v5; // rcx

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    m_uLength = m_pActivityChunk->m_ActiveChildren.m_uLength;
    v5 = &m_pItems[m_uLength];
    if ( m_pItems != v5 )
    {
      do
      {
        if ( *m_pItems == in_pChild )
          break;
        ++m_pItems;
      }
      while ( m_pItems != v5 );
      if ( m_pItems != v5 )
      {
        if ( (unsigned int)m_uLength > 1 )
          *m_pItems = *(v5 - 1);
        --m_pActivityChunk->m_ActiveChildren.m_uLength;
      }
    }
  }
}

// File Line: 675
// RVA: 0xA73090
void __fastcall CAkParameterNodeBase::PauseTransitions(CAkParameterNodeBase *this, bool in_bPause)
{
  AkStateGroupChunk *i; // rbx
  char *m_pProps; // rcx
  unsigned __int8 *v5; // rdx
  unsigned __int8 *v6; // rdi
  __int64 v7; // rsi
  CAkTransition **v8; // rdi
  __int64 v9; // rsi
  CAkTransition *v10; // rdx

  for ( i = this->m_states.m_pFirst; i; i = i->m_pNextInNode )
  {
    m_pProps = i->m_values.m_pProps;
    if ( m_pProps )
    {
      v5 = (unsigned __int8 *)(m_pProps + 1);
      v6 = (unsigned __int8 *)&m_pProps[((unsigned __int8)*m_pProps + 4) & 0xFFFFFFFC];
    }
    else
    {
      v5 = 0i64;
      v6 = 0i64;
    }
    if ( m_pProps )
      v7 = (__int64)&m_pProps[(unsigned __int8)*m_pProps + 1];
    else
      v7 = 0i64;
    if ( v5 != (unsigned __int8 *)v7 )
    {
      v8 = (CAkTransition **)(v6 + 8);
      v9 = v7 - (_QWORD)v5;
      do
      {
        v10 = *v8;
        if ( *v8 )
        {
          if ( in_bPause )
            CAkTransitionManager::Pause(g_pTransitionManager, v10);
          else
            CAkTransitionManager::Resume(g_pTransitionManager, v10);
        }
        v8 += 2;
        --v9;
      }
      while ( v9 );
    }
  }
}

// File Line: 717
// RVA: 0xA74520
void __fastcall CAkParameterNodeBase::StartSISTransition(
        CAkParameterNodeBase *this,
        CAkSIS *in_pSIS,
        AkPropID in_ePropID,
        float in_fTargetValue,
        AkValueMeaning in_eValueMeaning,
        AkCurveInterpolation in_eFadeCurve,
        int in_lTransitionTime)
{
  AkPropBundle<AkStateValue> *p_m_values; // rcx
  __int64 v9; // rbx
  char *m_pProps; // r8
  __int64 v11; // rsi
  float v12; // xmm6_4
  unsigned int v14; // r10d
  int v15; // r9d
  __int64 v16; // rdx
  __int64 v17; // rdi
  AkStateValue *v18; // rax
  CAkTransition *v19; // r11
  char *v20; // r8
  unsigned int v21; // r9d
  __int64 v22; // rcx
  __int64 v23; // rdx
  int *p_iValue; // rax
  float v25; // xmm0_4
  float v26; // xmm2_4
  unsigned int v27; // r9d
  __int64 v28; // rcx
  __int64 v29; // rdx
  __int64 v30; // rdx
  int *v31; // rax
  bool v32; // al
  TransitionParameters in_Params; // [rsp+40h] [rbp-68h] BYREF
  int iValue; // [rsp+B8h] [rbp+10h] BYREF

  p_m_values = (AkPropBundle<AkStateValue> *)&in_pSIS->m_values;
  v9 = in_ePropID;
  m_pProps = in_pSIS->m_values.m_pProps;
  v11 = 0i64;
  v12 = in_fTargetValue;
  if ( !m_pProps )
    goto LABEL_7;
  v14 = (unsigned __int8)*m_pProps;
  v15 = 0;
  while ( 1 )
  {
    v16 = (unsigned int)(v15 + 1);
    if ( m_pProps[v16] == (_BYTE)v9 )
      break;
    ++v15;
    if ( (unsigned int)v16 >= v14 )
      goto LABEL_7;
  }
  v17 = (__int64)&m_pProps[16 * v15 + ((v14 + 4) & 0xFFFFFFFC)];
  if ( !v17 )
  {
LABEL_7:
    v18 = AkPropBundle<AkStateValue>::AddAkProp(p_m_values, v9);
    v17 = (__int64)v18;
    if ( !v18 )
      return;
    v18->fValue = 0.0;
    v18->pTransition = 0i64;
  }
  v19 = *(CAkTransition **)(v17 + 8);
  if ( v19 )
  {
    if ( in_eValueMeaning == AkValueMeaning_Independent )
    {
      v20 = this->m_props.m_pProps;
      iValue = g_AkPropDefault[v9].iValue;
      if ( v20 )
      {
        v21 = (unsigned __int8)*v20;
        v22 = 0i64;
        while ( 1 )
        {
          v23 = (unsigned int)(v22 + 1);
          if ( v20[v23] == (_BYTE)v9 )
            break;
          v22 = (unsigned int)v23;
          if ( (unsigned int)v23 >= v21 )
            goto LABEL_17;
        }
        v11 = (__int64)&v20[4 * v22 + ((v21 + 4) & 0xFFFFFFFC)];
      }
LABEL_17:
      p_iValue = &iValue;
      if ( v11 )
        p_iValue = (int *)v11;
      iValue = *p_iValue;
      v12 = in_fTargetValue - *(float *)&iValue;
    }
    CAkTransitionManager::ChangeParameter(
      g_pTransitionManager,
      v19,
      v9,
      v12,
      in_lTransitionTime,
      in_eFadeCurve,
      in_eValueMeaning);
  }
  else
  {
    v25 = *(float *)v17;
    v26 = 0.0;
    if ( in_eValueMeaning == AkValueMeaning_Independent )
    {
      m_pProps = this->m_props.m_pProps;
      iValue = g_AkPropDefault[v9].iValue;
      if ( m_pProps )
      {
        v27 = (unsigned __int8)*m_pProps;
        v28 = 0i64;
        while ( 1 )
        {
          v29 = (unsigned int)(v28 + 1);
          if ( m_pProps[v29] == (_BYTE)v9 )
            break;
          v28 = (unsigned int)v29;
          if ( (unsigned int)v29 >= v27 )
            goto LABEL_28;
        }
        v30 = (__int64)&m_pProps[4 * v28 + ((v27 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_28:
        v30 = 0i64;
      }
      v31 = &iValue;
      if ( v30 )
        v31 = (int *)v30;
      iValue = *v31;
      v26 = in_fTargetValue - *(float *)&iValue;
    }
    else if ( in_eValueMeaning == AkValueMeaning_Offset )
    {
      v26 = v25 + in_fTargetValue;
    }
    if ( v25 == v26 || !in_lTransitionTime )
    {
      *(float *)v17 = v26;
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkIndexableVtbl *, CAkRegisteredObj *, _QWORD))this->vfptr[5].Release)(
        this,
        (unsigned int)g_AkPropRTPCID[v9],
        this->vfptr,
        in_pSIS->m_pGameObj,
        0i64);
    }
    else
    {
      in_Params.lDuration = in_lTransitionTime;
      in_Params.fStartValue = v25;
      in_Params.fTargetValue = v26;
      in_Params.eFadeCurve = in_eFadeCurve;
      v32 = g_AkPropDecibel[v9];
      LOBYTE(m_pProps) = 1;
      in_Params.pUser = in_pSIS;
      in_Params.bdBs = v32;
      in_Params.eTarget = v9;
      in_Params.bUseReciprocalCurve = 1;
      *(_QWORD *)(v17 + 8) = CAkTransitionManager::AddTransitionToList(
                               g_pTransitionManager,
                               &in_Params,
                               (CAkTransition **)m_pProps,
                               0i64);
    }
  }
}

// File Line: 792
// RVA: 0xA747B0
void __fastcall CAkParameterNodeBase::StartSisMuteTransitions(
        CAkParameterNodeBase *this,
        CAkSIS *in_pSIS,
        float in_fTargetValue,
        __int64 in_eFadeCurve,
        int in_lTransitionTime)
{
  char *m_pProps; // r10
  AkCurveInterpolation in_eCurveType; // ebp
  unsigned int v8; // r11d
  int v9; // ecx
  CAkTransition **v10; // r8
  __int64 v11; // rbx
  AkStateValue *v12; // rax
  CAkTransition *v13; // rdx
  float v14; // xmm0_4
  TransitionParameters in_Params; // [rsp+40h] [rbp-48h] BYREF

  m_pProps = in_pSIS->m_values.m_pProps;
  in_eCurveType = (int)in_eFadeCurve;
  if ( !m_pProps )
    goto LABEL_7;
  v8 = (unsigned __int8)*m_pProps;
  v9 = 0;
  while ( 1 )
  {
    v10 = (CAkTransition **)(unsigned int)(v9 + 1);
    if ( m_pProps[(_QWORD)v10] == 10 )
      break;
    ++v9;
    if ( (unsigned int)v10 >= v8 )
      goto LABEL_7;
  }
  v11 = (__int64)&m_pProps[16 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
  if ( !v11 )
  {
LABEL_7:
    v12 = AkPropBundle<AkStateValue>::AddAkProp((AkPropBundle<AkStateValue> *)&in_pSIS->m_values, 10);
    v11 = (__int64)v12;
    if ( !v12 )
      return;
    v12->fValue = 1.0;
    v12->pTransition = 0i64;
  }
  v13 = *(CAkTransition **)(v11 + 8);
  if ( v13 )
  {
    CAkTransitionManager::ChangeParameter(
      g_pTransitionManager,
      v13,
      10i64,
      in_fTargetValue,
      in_lTransitionTime,
      in_eCurveType,
      AkValueMeaning_Default);
  }
  else if ( in_lTransitionTime )
  {
    v14 = *(float *)v11;
    LOBYTE(v10) = 1;
    in_Params.fTargetValue = in_fTargetValue;
    in_Params.fStartValue = v14;
    in_Params.pUser = in_pSIS;
    in_Params.eTarget = 10i64;
    in_Params.lDuration = in_lTransitionTime;
    in_Params.eFadeCurve = in_eCurveType;
    *(_WORD *)&in_Params.bdBs = 256;
    *(_QWORD *)(v11 + 8) = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, v10, 0i64);
  }
  else
  {
    LOBYTE(in_eFadeCurve) = 1;
    ((void (__fastcall *)(CAkSIS *, __int64, CAkTransition **, __int64))in_pSIS->vfptr->TransUpdateValue)(
      in_pSIS,
      10i64,
      v10,
      in_eFadeCurve);
  }
}

// File Line: 839
// RVA: 0xA73B10
__int64 __fastcall CAkParameterNodeBase::SetFX(
        CAkParameterNodeBase *this,
        unsigned int in_uFXIndex,
        unsigned int in_uID,
        bool in_bShareSet)
{
  __int64 v6; // rdi
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rcx
  CAkParameterNodeBase::FXChunk *v10; // rax

  v6 = in_uFXIndex;
  if ( in_uFXIndex >= 4 )
    return 31i64;
  m_pFXChunk = this->m_pFXChunk;
  if ( !m_pFXChunk )
  {
    v10 = (CAkParameterNodeBase::FXChunk *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x24ui64);
    this->m_pFXChunk = v10;
    if ( v10 )
    {
      *(_WORD *)&v10->aFX[0].bRendered = 0;
      v10->aFX[0].id = 0;
      *(_WORD *)&v10->aFX[1].bRendered = 0;
      v10->aFX[1].id = 0;
      *(_WORD *)&v10->aFX[2].bRendered = 0;
      v10->aFX[2].id = 0;
      *(_WORD *)&v10->aFX[3].bRendered = 0;
      v10->aFX[3].id = 0;
      v10->bitsMainFXBypass = 0;
    }
    m_pFXChunk = this->m_pFXChunk;
    if ( !m_pFXChunk )
      return 52i64;
  }
  if ( m_pFXChunk->aFX[v6].bShareSet != in_bShareSet || m_pFXChunk->aFX[v6].id != in_uID )
  {
    m_pFXChunk->aFX[v6].bShareSet = in_bShareSet;
    m_pFXChunk->aFX[v6].id = in_uID;
    this->vfptr[12].Category(this);
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))this->vfptr[8].AddRef)(this, (unsigned int)v6);
  }
  return 1i64;
}

// File Line: 880
// RVA: 0xA73550
__int64 __fastcall CAkParameterNodeBase::RemoveFX(CAkParameterNodeBase *this, unsigned int in_uFXIndex)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rcx

  if ( in_uFXIndex >= 4 )
    return 31i64;
  m_pFXChunk = this->m_pFXChunk;
  if ( !m_pFXChunk )
    return 2i64;
  if ( m_pFXChunk->aFX[in_uFXIndex].bShareSet || m_pFXChunk->aFX[in_uFXIndex].id )
  {
    m_pFXChunk->aFX[in_uFXIndex].bShareSet = 0;
    m_pFXChunk->aFX[in_uFXIndex].id = 0;
    this->vfptr[12].Category(this);
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))this->vfptr[8].AddRef)(this, in_uFXIndex);
  }
  return 1i64;
}

// File Line: 988
// RVA: 0xA737A0
__int64 __fastcall CAkParameterNodeBase::RenderedFX(
        CAkParameterNodeBase *this,
        unsigned int in_uFXIndex,
        bool in_bRendered)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rcx
  __int64 v6; // rsi
  CAkParameterNodeBase::FXChunk *v7; // rax

  m_pFXChunk = this->m_pFXChunk;
  v6 = in_uFXIndex;
  if ( m_pFXChunk )
  {
LABEL_7:
    m_pFXChunk->aFX[v6].bRendered = in_bRendered;
    if ( in_bRendered )
    {
      if ( this->m_pFXChunk->aFX[v6].id )
        CAkParameterNodeBase::RemoveFX(this, v6);
    }
    return 1i64;
  }
  if ( in_bRendered )
  {
    v7 = (CAkParameterNodeBase::FXChunk *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x24ui64);
    this->m_pFXChunk = v7;
    if ( v7 )
    {
      *(_WORD *)&v7->aFX[0].bRendered = 0;
      v7->aFX[0].id = 0;
      *(_WORD *)&v7->aFX[1].bRendered = 0;
      v7->aFX[1].id = 0;
      *(_WORD *)&v7->aFX[2].bRendered = 0;
      v7->aFX[2].id = 0;
      *(_WORD *)&v7->aFX[3].bRendered = 0;
      v7->aFX[3].id = 0;
      v7->bitsMainFXBypass = 0;
    }
    m_pFXChunk = this->m_pFXChunk;
    if ( !m_pFXChunk )
      return 52i64;
    goto LABEL_7;
  }
  return 1i64;
}

// File Line: 1019
// RVA: 0xA72BA0
__int64 __fastcall CAkParameterNodeBase::MainBypassFX(
        CAkParameterNodeBase *this,
        unsigned int in_bitsFXBypass,
        unsigned int in_uTargetMask)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rdx
  CAkParameterNodeBase::FXChunk *v7; // rax

  if ( this->vfptr[3].Release(this) )
    this->vfptr[3].Release(this);
  m_pFXChunk = this->m_pFXChunk;
  if ( m_pFXChunk )
  {
LABEL_9:
    m_pFXChunk->bitsMainFXBypass = in_uTargetMask & in_bitsFXBypass | m_pFXChunk->bitsMainFXBypass & ~(_BYTE)in_uTargetMask;
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD))this->vfptr[13].Category)(
      this,
      in_bitsFXBypass,
      in_uTargetMask);
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, _QWORD, _QWORD))this->vfptr[6].Category)(
      this,
      in_bitsFXBypass,
      in_uTargetMask,
      0i64,
      0i64);
    return 1i64;
  }
  if ( in_bitsFXBypass )
  {
    v7 = (CAkParameterNodeBase::FXChunk *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x24ui64);
    this->m_pFXChunk = v7;
    if ( v7 )
    {
      *(_WORD *)&v7->aFX[0].bRendered = 0;
      v7->aFX[0].id = 0;
      *(_WORD *)&v7->aFX[1].bRendered = 0;
      v7->aFX[1].id = 0;
      *(_WORD *)&v7->aFX[2].bRendered = 0;
      v7->aFX[2].id = 0;
      *(_WORD *)&v7->aFX[3].bRendered = 0;
      v7->aFX[3].id = 0;
      v7->bitsMainFXBypass = 0;
    }
    m_pFXChunk = this->m_pFXChunk;
    if ( !m_pFXChunk )
      return 52i64;
    goto LABEL_9;
  }
  return 1i64;
}

// File Line: 1057
// RVA: 0xA70E60
void __fastcall CAkParameterNodeBase::BypassFX(
        CAkParameterNodeBase *this,
        unsigned int in_bitsFXBypass,
        unsigned int in_uTargetMask,
        CAkRegisteredObj *in_pGameObj,
        bool in_bIsFromReset)
{
  _BYTE *v9; // rax

  v9 = this->vfptr[19].__vecDelDtor(this, in_pGameObj);
  if ( v9 )
    v9[32] = in_uTargetMask & in_bitsFXBypass | v9[32] & ~(_BYTE)in_uTargetMask;
  if ( this->vfptr[3].Release(this) )
    this->vfptr[3].Release(this);
  if ( !in_pGameObj )
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD))this->vfptr[13].Category)(
      this,
      in_bitsFXBypass,
      in_uTargetMask);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, CAkRegisteredObj *, _QWORD))this->vfptr[6].Category)(
    this,
    in_bitsFXBypass,
    in_uTargetMask,
    in_pGameObj,
    0i64);
}

// File Line: 1091
// RVA: 0xA73860
void __fastcall CAkParameterNodeBase::ResetBypassFX(
        CAkParameterNodeBase *this,
        unsigned int in_uTargetMask,
        CAkRegisteredObj *in_pGameObj)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rax
  unsigned int bitsMainFXBypass; // edx

  m_pFXChunk = this->m_pFXChunk;
  if ( m_pFXChunk )
    bitsMainFXBypass = (unsigned __int8)m_pFXChunk->bitsMainFXBypass;
  else
    bitsMainFXBypass = 0;
  CAkParameterNodeBase::BypassFX(this, bitsMainFXBypass, in_uTargetMask, in_pGameObj, 1);
}

// File Line: 1100
// RVA: 0xA70C80
AkStateGroupChunk *__fastcall CAkParameterNodeBase::AddStateGroup(
        CAkParameterNodeBase *this,
        unsigned int in_ulStateGroupID,
        bool in_bNotify)
{
  AkStateGroupChunk *result; // rax
  AkStateGroupChunk *v7; // rbx
  int v8; // edi
  MapStruct<unsigned long,AkStateLink> *m_pItems; // rdx
  char *m_pProps; // rdx
  AkStateGroupChunk *m_pFirst; // rax

  result = this->m_states.m_pFirst;
  if ( result )
  {
    while ( result->m_ulStateGroup != in_ulStateGroupID )
    {
      result = result->m_pNextInNode;
      if ( !result )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = (AkStateGroupChunk *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64);
    v7 = result;
    if ( result )
    {
      result->m_pOwner = this;
      result->m_pNextInGroup = 0i64;
      result->m_pNextInNode = 0i64;
      result->vfptr = (ITransitionableVtbl *)&AkStateGroupChunk::`vftable;
      result->m_values.m_pProps = 0i64;
      result->m_mapStates.m_pItems = 0i64;
      *(_QWORD *)&result->m_mapStates.m_uLength = 0i64;
      result->m_ulStateGroup = in_ulStateGroupID;
      result->m_ulActualState = 0;
      result->m_eStateSyncType = 0;
      if ( (unsigned int)CAkStateMgr::AddStateGroupMember(g_pStateMgr, in_ulStateGroupID, result) == 1 )
      {
        m_pFirst = this->m_states.m_pFirst;
        if ( m_pFirst )
        {
          v7->m_pNextInNode = m_pFirst;
          this->m_states.m_pFirst = v7;
        }
        else
        {
          this->m_states.m_pFirst = v7;
          v7->m_pNextInNode = 0i64;
        }
        v7->m_ulActualState = CAkStateMgr::GetState(g_pStateMgr, in_ulStateGroupID);
        if ( in_bNotify )
          ((void (__fastcall *)(CAkParameterNodeBase *))this->vfptr[13].__vecDelDtor)(this);
        return v7;
      }
      else
      {
        v8 = g_DefaultPoolId;
        v7->vfptr = (ITransitionableVtbl *)&AkStateGroupChunk::`vftable;
        m_pItems = v7->m_mapStates.m_pItems;
        if ( m_pItems )
        {
          v7->m_mapStates.m_uLength = 0;
          AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
          v7->m_mapStates.m_pItems = 0i64;
          v7->m_mapStates.m_ulReserved = 0;
        }
        m_pProps = v7->m_values.m_pProps;
        if ( m_pProps )
          AK::MemoryMgr::Free(g_DefaultPoolId, m_pProps);
        v7->m_values.m_pProps = 0i64;
        AK::MemoryMgr::Free(v8, v7);
        return 0i64;
      }
    }
  }
  return result;
}

// File Line: 1151
// RVA: 0xA736A0
void __fastcall CAkParameterNodeBase::RemoveStateGroups(CAkParameterNodeBase *this, bool in_bNotify)
{
  AkStateGroupChunk *m_pFirst; // rbx
  int v5; // esi
  MapStruct<unsigned long,AkStateLink> *m_pItems; // rdx
  char *m_pProps; // rdx

  m_pFirst = this->m_states.m_pFirst;
  if ( m_pFirst )
  {
    do
    {
      this->m_states.m_pFirst = m_pFirst->m_pNextInNode;
      CAkStateMgr::RemoveStateGroupMember(g_pStateMgr, m_pFirst->m_ulStateGroup, m_pFirst);
      while ( m_pFirst->m_mapStates.m_uLength )
        AkStateGroupChunk::RemoveState(m_pFirst, m_pFirst->m_mapStates.m_pItems->key);
      v5 = g_DefaultPoolId;
      m_pFirst->vfptr = (ITransitionableVtbl *)&AkStateGroupChunk::`vftable;
      m_pItems = m_pFirst->m_mapStates.m_pItems;
      if ( m_pItems )
      {
        m_pFirst->m_mapStates.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
        m_pFirst->m_mapStates.m_pItems = 0i64;
        m_pFirst->m_mapStates.m_ulReserved = 0;
      }
      m_pProps = m_pFirst->m_values.m_pProps;
      if ( m_pProps )
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pProps);
      m_pFirst->m_values.m_pProps = 0i64;
      AK::MemoryMgr::Free(v5, m_pFirst);
      m_pFirst = this->m_states.m_pFirst;
    }
    while ( m_pFirst );
    if ( in_bNotify )
      ((void (__fastcall *)(CAkParameterNodeBase *))this->vfptr[13].__vecDelDtor)(this);
  }
}

// File Line: 1191
// RVA: 0xA74D40
void __fastcall CAkParameterNodeBase::UseState(CAkParameterNodeBase *this, bool in_bUseState)
{
  CAkIndexableVtbl *vfptr; // rax

  *((_BYTE *)this + 82) &= ~0x80u;
  vfptr = this->vfptr;
  *((_BYTE *)this + 82) |= in_bUseState << 7;
  ((void (*)(void))vfptr[13].__vecDelDtor)();
}

// File Line: 1326
// RVA: 0xA72D00
void __fastcall CAkParameterNodeBase::NotifyStateParametersModified(CAkParameterNodeBase *this)
{
  AkStateGroupChunk *i; // rbx
  MapStruct<unsigned long,AkStateLink> *m_pItems; // rax
  MapStruct<unsigned long,AkStateLink> *v4; // rcx
  AkStateLink *p_item; // rax
  char *v6; // rcx
  char *v7; // rdi
  float *v8; // rsi
  __int64 v9; // rbp
  char *v10; // r8
  float v11; // xmm6_4
  unsigned int v12; // r9d
  unsigned __int8 v13; // r10
  int v14; // ecx
  __int64 v15; // rdx
  AkStateValue *v16; // rax
  __int64 v17; // r9
  CAkTransition *v18; // rdx
  char *m_pProps; // rdx
  unsigned __int8 *v20; // r8
  unsigned __int8 *v21; // rcx
  __int64 v22; // rdx
  __int64 v23; // rdx

  for ( i = this->m_states.m_pFirst; i; i = i->m_pNextInNode )
  {
    m_pItems = i->m_mapStates.m_pItems;
    v4 = &m_pItems[i->m_mapStates.m_uLength];
    if ( m_pItems == v4 )
      goto LABEL_27;
    do
    {
      if ( m_pItems->key == i->m_ulActualState )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v4 );
    if ( m_pItems == v4 || (p_item = &m_pItems->item) == 0i64 || !p_item->pState )
    {
LABEL_27:
      AkStateGroupChunk::FlushStateTransitions(i);
      m_pProps = i->m_values.m_pProps;
      if ( m_pProps )
      {
        v20 = (unsigned __int8 *)(m_pProps + 1);
        v21 = (unsigned __int8 *)&m_pProps[((unsigned __int8)*m_pProps + 4) & 0xFFFFFFFC];
      }
      else
      {
        v20 = 0i64;
        v21 = 0i64;
      }
      if ( m_pProps )
        v22 = (__int64)&m_pProps[(unsigned __int8)*m_pProps + 1];
      else
        v22 = 0i64;
      if ( v20 != (unsigned __int8 *)v22 )
      {
        v23 = v22 - (_QWORD)v20;
        do
        {
          *(_DWORD *)v21 = 0;
          v21 += 16;
          --v23;
        }
        while ( v23 );
      }
    }
    else
    {
      v6 = p_item->pState->m_props.m_pProps;
      if ( v6 )
      {
        v7 = v6 + 1;
        v8 = (float *)&v6[((unsigned __int8)*v6 + 4) & 0xFFFFFFFC];
      }
      else
      {
        v7 = 0i64;
        v8 = 0i64;
      }
      if ( v6 )
        v9 = (__int64)&v6[(unsigned __int8)*v6 + 1];
      else
        v9 = 0i64;
      for ( ; v7 != (char *)v9; ++v8 )
      {
        v10 = i->m_values.m_pProps;
        v11 = *v8;
        if ( !v10 )
          goto LABEL_19;
        v12 = (unsigned __int8)*v10;
        v13 = *v7;
        v14 = 0;
        while ( 1 )
        {
          v15 = (unsigned int)(v14 + 1);
          if ( v10[v15] == v13 )
            break;
          ++v14;
          if ( (unsigned int)v15 >= v12 )
            goto LABEL_19;
        }
        v17 = (__int64)&v10[16 * v14 + ((v12 + 4) & 0xFFFFFFFC)];
        if ( v17 )
        {
          v18 = *(CAkTransition **)(v17 + 8);
          if ( v18 )
            CAkTransitionManager::ChangeParameter(
              g_pTransitionManager,
              v18,
              v13,
              v11,
              0,
              AkCurveInterpolation_Linear,
              AkValueMeaning_Default);
          else
            *(float *)v17 = v11;
        }
        else
        {
LABEL_19:
          v16 = AkPropBundle<AkStateValue>::AddAkProp(&i->m_values, *v7);
          if ( v16 )
          {
            v16->fValue = v11;
            v16->pTransition = 0i64;
          }
        }
        ++v7;
      }
    }
  }
  this->vfptr[12].Category(this);
}

// File Line: 1380
// RVA: 0xA73D30
void __fastcall CAkParameterNodeBase::SetMaxReachedBehavior(CAkParameterNodeBase *this, bool in_bKillNewest)
{
  char v3; // cl
  char v4; // al
  AkActivityChunk *m_pActivityChunk; // rcx
  CAkLimiter *p_m_Limiter; // rcx
  bool v7; // al
  AkActivityChunk *v8; // rdx
  MapStruct<CAkRegisteredObj *,StructMaxInst> *m_pItems; // rbx
  CAkLimiter *m_pLimiter; // rcx
  bool v11; // al

  v3 = *((_BYTE *)this + 82);
  if ( (v3 & 1) != in_bKillNewest )
  {
    v4 = v3 ^ (in_bKillNewest ^ v3) & 1;
    m_pActivityChunk = this->m_pActivityChunk;
    *((_BYTE *)this + 82) = v4;
    if ( m_pActivityChunk )
    {
      p_m_Limiter = &m_pActivityChunk->m_Limiter;
      v7 = !p_m_Limiter->m_bDoesKillNewest;
      p_m_Limiter->m_bDoesKillNewest = v7;
      if ( v7 )
        AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::ReSortArray<AkPriorityStruct_INC>(&p_m_Limiter->m_sortedPBIList);
      else
        AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::ReSortArray<AkPriorityStruct_DEC>(&p_m_Limiter->m_sortedPBIList);
      v8 = this->m_pActivityChunk;
      m_pItems = v8->m_ListPlayCountPerObj.m_pItems;
      if ( v8->m_ListPlayCountPerObj.m_pItems != &v8->m_ListPlayCountPerObj.m_pItems[v8->m_ListPlayCountPerObj.m_uLength] )
      {
        do
        {
          m_pLimiter = m_pItems->item.m_pLimiter;
          if ( m_pLimiter )
          {
            v11 = !m_pLimiter->m_bDoesKillNewest;
            m_pLimiter->m_bDoesKillNewest = v11;
            if ( v11 )
              AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::ReSortArray<AkPriorityStruct_INC>(&m_pLimiter->m_sortedPBIList);
            else
              AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::ReSortArray<AkPriorityStruct_DEC>(&m_pLimiter->m_sortedPBIList);
          }
          ++m_pItems;
        }
        while ( m_pItems != &this->m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[this->m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] );
      }
    }
  }
}

// File Line: 1398
// RVA: 0xA74020
void __fastcall CAkParameterNodeBase::SetOverLimitBehavior(CAkParameterNodeBase *this, bool in_bUseVirtualBehavior)
{
  char v3; // cl
  AkActivityChunk *m_pActivityChunk; // rax
  AkActivityChunk *v5; // r8
  MapStruct<CAkRegisteredObj *,StructMaxInst> *m_pItems; // rax
  CAkLimiter *m_pLimiter; // rcx

  v3 = *((_BYTE *)this + 82);
  if ( ((v3 & 2) != 0) != in_bUseVirtualBehavior )
  {
    *((_BYTE *)this + 82) = v3 ^ (v3 ^ (2 * in_bUseVirtualBehavior)) & 2;
    m_pActivityChunk = this->m_pActivityChunk;
    if ( m_pActivityChunk )
    {
      m_pActivityChunk->m_Limiter.m_bAllowUseVirtualBehavior = in_bUseVirtualBehavior;
      v5 = this->m_pActivityChunk;
      m_pItems = v5->m_ListPlayCountPerObj.m_pItems;
      if ( v5->m_ListPlayCountPerObj.m_pItems != &v5->m_ListPlayCountPerObj.m_pItems[v5->m_ListPlayCountPerObj.m_uLength] )
      {
        do
        {
          m_pLimiter = m_pItems->item.m_pLimiter;
          if ( m_pLimiter )
            m_pLimiter->m_bAllowUseVirtualBehavior = in_bUseVirtualBehavior;
          ++m_pItems;
        }
        while ( m_pItems != &this->m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[this->m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] );
      }
    }
  }
}

// File Line: 1429
// RVA: 0xA73D20
void __fastcall CAkParameterNodeBase::SetMaxNumInstOverrideParent(CAkParameterNodeBase *this, bool in_bOverride)
{
  *((_BYTE *)this + 82) &= ~8u;
  *((_BYTE *)this + 82) |= 8 * in_bOverride;
}

// File Line: 1434
// RVA: 0xA74510
void __fastcall CAkParameterNodeBase::SetVVoicesOptOverrideParent(CAkParameterNodeBase *this, bool in_bOverride)
{
  *((_BYTE *)this + 82) &= ~4u;
  *((_BYTE *)this + 82) |= 4 * in_bOverride;
}

// File Line: 1439
// RVA: 0xA721F0
PriorityInfo *__fastcall CAkParameterNodeBase::GetPriority(
        CAkParameterNodeBase *this,
        PriorityInfo *result,
        CAkRegisteredObj *in_GameObjPtr)
{
  CAkParameterNodeBase *m_pParentNode; // rcx
  int m_iBitArray; // eax
  __int64 v8; // rdi
  char *m_pProps; // r8
  unsigned int v10; // r9d
  __int64 v11; // rcx
  __int64 v12; // rdx
  __int64 v13; // rdx
  int *p_iValue; // rax
  char *v15; // r8
  unsigned int v16; // r9d
  __int64 v17; // rcx
  __int64 v18; // rdx
  int *v19; // rax
  int iValue; // [rsp+40h] [rbp+8h] BYREF
  PriorityInfo v21; // [rsp+58h] [rbp+20h]

  m_pParentNode = this->m_pParentNode;
  if ( !m_pParentNode || (*((_BYTE *)this + 82) & 0x40) != 0 )
  {
    m_iBitArray = this->m_RTPCBitArray.m_iBitArray;
    v8 = 0i64;
    v21 = (PriorityInfo)LODWORD(FLOAT_50_0);
    if ( (m_iBitArray & 0x100) != 0 )
    {
      v21.priority = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 8u, in_GameObjPtr);
    }
    else
    {
      m_pProps = this->m_props.m_pProps;
      iValue = g_AkPropDefault[5].iValue;
      if ( m_pProps )
      {
        v10 = (unsigned __int8)*m_pProps;
        v11 = 0i64;
        while ( 1 )
        {
          v12 = (unsigned int)(v11 + 1);
          if ( m_pProps[v12] == 5 )
            break;
          v11 = (unsigned int)v12;
          if ( (unsigned int)v12 >= v10 )
            goto LABEL_10;
        }
        v13 = (__int64)&m_pProps[4 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_10:
        v13 = 0i64;
      }
      p_iValue = &iValue;
      if ( v13 )
        p_iValue = (int *)v13;
      LODWORD(v21.priority) = *p_iValue;
    }
    if ( (*((_BYTE *)this + 82) & 0x20) != 0 )
    {
      v15 = this->m_props.m_pProps;
      iValue = g_AkPropDefault[6].iValue;
      if ( v15 )
      {
        v16 = (unsigned __int8)*v15;
        v17 = 0i64;
        while ( 1 )
        {
          v18 = (unsigned int)(v17 + 1);
          if ( v15[v18] == 6 )
            break;
          v17 = (unsigned int)v18;
          if ( (unsigned int)v18 >= v16 )
            goto LABEL_22;
        }
        v8 = (__int64)&v15[4 * v17 + ((v16 + 4) & 0xFFFFFFFC)];
      }
LABEL_22:
      v19 = &iValue;
      if ( v8 )
        v19 = (int *)v8;
      LODWORD(v21.distanceOffset) = *v19;
    }
    else
    {
      v21.distanceOffset = 0.0;
    }
    *result = v21;
    return result;
  }
  else
  {
    CAkParameterNodeBase::GetPriority(m_pParentNode, result, in_GameObjPtr);
    return result;
  }
}

// File Line: 1452
// RVA: 0xA73A60
void __fastcall CAkParameterNodeBase::SetAkProp(
        CAkParameterNodeBase *this,
        AkPropID in_eProp,
        float in_fValue,
        float __formal)
{
  char *m_pProps; // r9
  __int64 v6; // r11
  unsigned int v7; // r10d
  int v8; // r8d
  __int64 v9; // rcx
  AkPropValue *p_in_Value; // rax
  AkPropValue in_Value; // [rsp+38h] [rbp+10h] BYREF

  m_pProps = this->m_props.m_pProps;
  v6 = 0i64;
  LODWORD(in_Value.fValue) = g_AkPropDefault[in_eProp];
  if ( m_pProps )
  {
    v7 = (unsigned __int8)*m_pProps;
    v8 = 0;
    while ( 1 )
    {
      v9 = (unsigned int)(v8 + 1);
      if ( m_pProps[v9] == (_BYTE)in_eProp )
        break;
      ++v8;
      if ( (unsigned int)v9 >= v7 )
        goto LABEL_7;
    }
    v6 = (__int64)&m_pProps[4 * v8 + ((v7 + 4) & 0xFFFFFFFC)];
  }
LABEL_7:
  p_in_Value = &in_Value;
  if ( v6 )
    p_in_Value = (AkPropValue *)v6;
  in_Value.fValue = p_in_Value->fValue;
  if ( in_Value.fValue != in_fValue )
  {
    in_Value.fValue = in_fValue;
    AkPropBundle<AkPropValue>::SetAkProp(&this->m_props, in_eProp, LODWORD(in_fValue));
    this->vfptr[12].Category(this);
  }
}

// File Line: 1462
// RVA: 0xA739B0
void __fastcall CAkParameterNodeBase::SetAkProp(
        CAkParameterNodeBase *this,
        AkPropID in_eProp,
        AkPropValue in_iValue,
        int __formal)
{
  char *m_pProps; // r10
  __int64 v6; // r11
  unsigned int v8; // r8d
  int v9; // r9d
  __int64 v10; // rcx
  int *p_iValue; // rax
  int iValue; // [rsp+38h] [rbp+10h] BYREF

  m_pProps = this->m_props.m_pProps;
  v6 = 0i64;
  iValue = g_AkPropDefault[in_eProp].iValue;
  if ( m_pProps )
  {
    v8 = (unsigned __int8)*m_pProps;
    v9 = 0;
    while ( 1 )
    {
      v10 = (unsigned int)(v9 + 1);
      if ( m_pProps[v10] == (_BYTE)in_eProp )
        break;
      ++v9;
      if ( (unsigned int)v10 >= v8 )
        goto LABEL_7;
    }
    v6 = (__int64)&m_pProps[4 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
  }
LABEL_7:
  p_iValue = &iValue;
  if ( v6 )
    p_iValue = (int *)v6;
  if ( *p_iValue != LODWORD(in_iValue.fValue) )
  {
    AkPropBundle<AkPropValue>::SetAkProp(&this->m_props, in_eProp, in_iValue);
    this->vfptr[12].Category(this);
  }
}

// File Line: 1472
// RVA: 0xA717B0
AkPropValue *__fastcall CAkParameterNodeBase::FindCustomProp(CAkParameterNodeBase *this, char in_uPropID)
{
  char *m_pProps; // r8
  unsigned int v3; // r10d
  __int64 v4; // rcx
  char v5; // r9
  __int64 v6; // rdx

  m_pProps = this->m_props.m_pProps;
  if ( !m_pProps )
    return 0i64;
  v3 = (unsigned __int8)*m_pProps;
  v4 = 0i64;
  v5 = in_uPropID + 45;
  while ( 1 )
  {
    v6 = (unsigned int)(v4 + 1);
    if ( m_pProps[v6] == v5 )
      break;
    v4 = (unsigned int)v6;
    if ( (unsigned int)v6 >= v3 )
      return 0i64;
  }
  return (AkPropValue *)&m_pProps[4 * v4 + ((v3 + 4) & 0xFFFFFFFC)];
}

// File Line: 1530
// RVA: 0xA732C0
__int64 __fastcall CAkParameterNodeBase::ReadStateChunk(
        CAkParameterNodeBase *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  int v3; // r14d
  unsigned int v5; // r15d
  unsigned int v7; // edx
  AkStateGroupChunk *v8; // rax
  AkStateGroupChunk *v9; // rbp
  int v10; // ebx
  char v11; // dl
  unsigned int v12; // edx
  unsigned int v13; // esi
  unsigned int v14; // r8d
  char *v15; // rax
  unsigned int v16; // edx
  __int64 result; // rax

  v3 = 0;
  v5 = *(_DWORD *)*io_rpData;
  *io_rpData += 4;
  if ( !v5 )
    return 1i64;
  while ( 1 )
  {
    v7 = *(_DWORD *)*io_rpData;
    *io_rpData += 4;
    v8 = CAkParameterNodeBase::AddStateGroup(this, v7, 1);
    v9 = v8;
    if ( !v8 )
      return 2i64;
    v10 = 0;
    v11 = *(*io_rpData)++;
    v8->m_eStateSyncType = v11;
    v12 = *(unsigned __int16 *)*io_rpData;
    *io_rpData += 2;
    v13 = v12;
    if ( v12 )
      break;
LABEL_6:
    if ( ++v3 >= v5 )
      return 1i64;
  }
  while ( 1 )
  {
    v14 = *(_DWORD *)*io_rpData;
    v15 = *io_rpData + 4;
    *io_rpData = v15;
    v16 = *(_DWORD *)v15;
    *io_rpData = v15 + 4;
    result = AkStateGroupChunk::AddState(v9, v16, v14, 1);
    if ( (_DWORD)result != 1 )
      return result;
    if ( ++v10 >= v13 )
      goto LABEL_6;
  }
}

// File Line: 1562
// RVA: 0xA73DF0
__int64 __fastcall CAkParameterNodeBase::SetNodeBaseParams(
        CAkParameterNodeBase *this,
        char **io_rpData,
        unsigned int *io_rulDataSize,
        bool in_bPartialLoadOnly)
{
  __int64 result; // rax
  unsigned int v9; // edx
  CAkParameterNodeBase *NodePtrAndAddRef; // r14
  unsigned int StateChunk; // ebx
  unsigned int v12; // edx
  CAkParameterNodeBase *v13; // rax
  CAkParameterNodeBase *v14; // r14
  char *v15; // rax
  char v16; // cl
  char v17; // r14
  char v18; // dl
  char v19; // cl
  CAkIndexableVtbl *vfptr; // rax
  char v21; // dl
  CAkIndexableVtbl *v22; // rax

  result = ((__int64 (__fastcall *)(CAkParameterNodeBase *))this->vfptr[18].__vecDelDtor)(this);
  if ( (_DWORD)result == 1 && !in_bPartialLoadOnly )
  {
    v9 = *(_DWORD *)*io_rpData;
    *io_rpData += 4;
    if ( v9 )
    {
      NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v9, AkNodeType_Bus);
      if ( NodePtrAndAddRef )
      {
        this->vfptr->AddRef(this);
        StateChunk = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkParameterNodeBase *))NodePtrAndAddRef->vfptr[2].AddRef)(
                       NodePtrAndAddRef,
                       this);
        NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
        if ( StateChunk == 1 )
          goto LABEL_6;
      }
      else
      {
        return 2;
      }
      return StateChunk;
    }
LABEL_6:
    v12 = *(_DWORD *)*io_rpData;
    *io_rpData += 4;
    if ( !v12
      || (v13 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v12, AkNodeType_Default), (v14 = v13) == 0i64)
      || (StateChunk = CAkParameterNodeBase::AddChildByPtr(v13, this), v14->vfptr->Release(v14), StateChunk == 1) )
    {
      v15 = *io_rpData + 1;
      v16 = **io_rpData;
      *io_rpData = v15++;
      v17 = *(v15 - 1);
      *io_rpData = v15;
      v18 = *((_BYTE *)this + 82);
      v19 = v16 != 0;
      if ( ((v18 & 0x40) != 0) != v19 )
      {
        vfptr = this->vfptr;
        *((_BYTE *)this + 82) = v18 ^ (v18 ^ (v19 << 6)) & 0x40;
        vfptr[12].Category(this);
      }
      v21 = *((_BYTE *)this + 82);
      if ( ((v21 & 0x20) != 0) != (v17 != 0) )
      {
        v22 = this->vfptr;
        *((_BYTE *)this + 82) = v21 ^ (v21 ^ (32 * (v17 != 0))) & 0x20;
        v22[12].Category(this);
      }
      StateChunk = ((__int64 (__fastcall *)(CAkParameterNodeBase *, char **, unsigned int *))this->vfptr[17].Category)(
                     this,
                     io_rpData,
                     io_rulDataSize);
      if ( StateChunk == 1 )
      {
        StateChunk = ((__int64 (__fastcall *)(CAkParameterNodeBase *, char **, unsigned int *))this->vfptr[18].AddRef)(
                       this,
                       io_rpData,
                       io_rulDataSize);
        if ( StateChunk == 1 )
        {
          StateChunk = ((__int64 (__fastcall *)(CAkParameterNodeBase *, char **, unsigned int *))this->vfptr[18].Release)(
                         this,
                         io_rpData,
                         io_rulDataSize);
          if ( StateChunk == 1 )
          {
            StateChunk = ((__int64 (__fastcall *)(CAkParameterNodeBase *, char **, unsigned int *))this->vfptr[18].Category)(
                           this,
                           io_rpData,
                           io_rulDataSize);
            if ( StateChunk == 1 )
            {
              StateChunk = CAkParameterNodeBase::ReadStateChunk(this, io_rpData, io_rulDataSize);
              if ( StateChunk == 1 )
              {
                StateChunk = CAkParameterNodeBase::SetInitialRTPC(this, io_rpData, io_rulDataSize);
                if ( StateChunk == 1 )
                  return (unsigned int)CAkParameterNodeBase::ReadFeedbackInfo(this, io_rpData, io_rulDataSize);
              }
            }
          }
        }
      }
    }
    return StateChunk;
  }
  return result;
}

// File Line: 1657
// RVA: 0xA731C0
__int64 __fastcall CAkParameterNodeBase::ReadFeedbackInfo(
        CAkParameterNodeBase *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  unsigned int v5; // edi
  CAkParameterNodeBase::AkFeedbackInfo *v6; // rax
  unsigned int v7; // esi
  CAkParameterNodeBase *NodePtrAndAddRef; // rdi

  if ( !g_pBankManager->m_bFeedbackInBank )
    return 1i64;
  v5 = *(_DWORD *)*io_rpData;
  *io_rpData += 4;
  if ( !v5 )
    return 1i64;
  if ( !this->m_pFeedbackInfo )
  {
    v6 = (CAkParameterNodeBase::AkFeedbackInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8ui64);
    this->m_pFeedbackInfo = v6;
    if ( v6 )
      v6->m_pFeedbackBus = 0i64;
    if ( !this->m_pFeedbackInfo )
      return 52i64;
  }
  v7 = 2;
  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v5, AkNodeType_Bus);
  if ( NodePtrAndAddRef
    && (this->vfptr->AddRef(this),
        v7 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkParameterNodeBase *))NodePtrAndAddRef->vfptr[2].AddRef)(
               NodePtrAndAddRef,
               this),
        NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef),
        v7 == 1) )
  {
    return 1i64;
  }
  else
  {
    return v7;
  }
}

// File Line: 1693
// RVA: 0xA73C50
__int64 __fastcall CAkParameterNodeBase::SetInitialRTPC(
        CAkParameterNodeBase *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  unsigned int *v3; // rax
  unsigned int v6; // edx
  __int64 v8; // rsi
  char *v9; // rax
  unsigned int v10; // edx
  AkRTPC_ParameterID v11; // r8d
  unsigned int v12; // r9d
  AkCurveScaling in_eScaling; // r11d
  __int64 v14; // rdi
  unsigned int in_ulConversionArraySize; // [rsp+30h] [rbp-18h]

  v3 = (unsigned int *)*io_rpData;
  v6 = *(unsigned __int16 *)*io_rpData;
  *io_rpData = (char *)v3 + 2;
  if ( v6 )
  {
    v8 = v6;
    do
    {
      v9 = *io_rpData + 4;
      v10 = *(_DWORD *)*io_rpData;
      *io_rpData = v9;
      v9 += 4;
      v11 = *((_DWORD *)v9 - 1);
      *io_rpData = v9;
      v12 = *(_DWORD *)v9;
      v9 += 4;
      *io_rpData = v9++;
      in_eScaling = (unsigned __int8)*(v9 - 1);
      *io_rpData = v9;
      in_ulConversionArraySize = *(unsigned __int16 *)v9;
      v14 = *(unsigned __int16 *)v9;
      *io_rpData = v9 + 2;
      CAkParameterNodeBase::SetRTPC(
        this,
        v10,
        v11,
        v12,
        in_eScaling,
        (AkRTPCGraphPointBase<float> *)(v9 + 2),
        in_ulConversionArraySize);
      *io_rpData += 12 * v14;
      *io_rulDataSize += -12 * v14;
      --v8;
    }
    while ( v8 );
  }
  return 1i64;
}

// File Line: 1725
// RVA: 0xA740A0
__int64 __fastcall CAkParameterNodeBase::SetParamComplexFromRTPCManager(
        CAkParameterNodeBase *this,
        _QWORD *in_pToken,
        __int64 in_Param_id,
        __int64 in_RTPCid,
        float in_value,
        CAkRegisteredObj *in_GameObj,
        void *in_pGameObjExceptArray)
{
  unsigned int v7; // ebp
  unsigned int v9; // esi
  __int64 result; // rax
  CAkIndexableVtbl *vfptr; // rax
  char v12; // [rsp+20h] [rbp-48h]
  int v13; // [rsp+30h] [rbp-38h] BYREF
  CAkRegisteredObj *v14; // [rsp+38h] [rbp-30h]
  char v15; // [rsp+40h] [rbp-28h]
  void *v16; // [rsp+48h] [rbp-20h]
  float v17; // [rsp+50h] [rbp-18h]

  v7 = in_Param_id;
  v9 = 1;
  switch ( (int)in_Param_id )
  {
    case 0:
    case 2:
    case 3:
    case 4:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 22:
    case 23:
    case 29:
    case 30:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
      CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, in_pToken, in_GameObj, in_RTPCid);
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkIndexableVtbl *, CAkRegisteredObj *, void *))this->vfptr[5].Release)(
        this,
        v7,
        this->vfptr,
        in_GameObj,
        in_pGameObjExceptArray);
      return 1i64;
    case 6:
      goto $LN16_77;
    case 8:
      if ( (*((_BYTE *)this + 82) & 0x40) == 0 && this->m_pParentNode )
        goto $LN16_77;
      v14 = in_GameObj;
      v17 = in_value;
      v16 = in_pGameObjExceptArray;
      vfptr = this->vfptr;
      v13 = 8;
      v15 = 0;
      ((void (__fastcall *)(CAkParameterNodeBase *, int *, __int64, __int64))vfptr[5].AddRef)(
        this,
        &v13,
        in_Param_id,
        in_RTPCid);
      result = 1i64;
      break;
    case 9:
      if ( (*((_BYTE *)this + 82) & 8) == 0 && this->m_pParentNode )
        goto $LN16_77;
      v12 = 1;
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkRegisteredObj *, void *, char))this->vfptr[13].AddRef)(
        this,
        (unsigned int)(int)in_value,
        in_GameObj,
        in_pGameObjExceptArray,
        v12);
      result = 1i64;
      break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 20:
    case 21:
    case 37:
    case 38:
    case 65:
    case 66:
    case 67:
    case 68:
      ((void (__fastcall *)(CAkParameterNodeBase *, CAkIndexableVtbl *, _QWORD, CAkRegisteredObj *, void *))this->vfptr[17].Release)(
        this,
        this->vfptr,
        (unsigned int)in_Param_id,
        in_GameObj,
        in_pGameObjExceptArray);
      return 1i64;
    case 24:
      ((void (__fastcall *)(CAkParameterNodeBase *, bool, __int64, CAkRegisteredObj *, void *))this->vfptr[6].Category)(
        this,
        in_value != 0.0,
        1i64,
        in_GameObj,
        in_pGameObjExceptArray);
      return 1i64;
    case 25:
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, __int64, CAkRegisteredObj *, void *))this->vfptr[6].Category)(
        this,
        2 * (unsigned int)(in_value != 0.0),
        2i64,
        in_GameObj,
        in_pGameObjExceptArray);
      return 1i64;
    case 26:
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, __int64, CAkRegisteredObj *, void *))this->vfptr[6].Category)(
        this,
        4 * (unsigned int)(in_value != 0.0),
        4i64,
        in_GameObj,
        in_pGameObjExceptArray);
      return 1i64;
    case 27:
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, __int64, CAkRegisteredObj *, void *))this->vfptr[6].Category)(
        this,
        8 * (unsigned int)(in_value != 0.0),
        8i64,
        in_GameObj,
        in_pGameObjExceptArray);
      return 1i64;
    case 28:
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, __int64, CAkRegisteredObj *, void *))this->vfptr[6].Category)(
        this,
        16 * (unsigned int)(in_value != 0.0),
        16i64,
        in_GameObj,
        in_pGameObjExceptArray);
      return 1i64;
    default:
      v9 = 2;
$LN16_77:
      result = v9;
      break;
  }
  return result;
}   in_pGameObjExceptArray);
      retur

// File Line: 1828
// RVA: 0xA74460
void __fastcall CAkParameterNodeBase::SetRTPC(
        CAkParameterNodeBase *this,
        unsigned int in_RTPC_ID,
        unsigned __int32 in_ParamID,
        unsigned int in_RTPCCurveID,
        AkCurveScaling in_eScaling,
        AkRTPCGraphPointBase<float> *in_pArrayConversion,
        unsigned int in_ulConversionArraySize)
{
  CAkRTPCMgr::SubscriberType in_eType; // eax

  this->m_RTPCBitArray.m_iBitArray |= 1i64 << in_ParamID;
  if ( g_pRTPCMgr )
  {
    in_eType = this->vfptr[19].AddRef(this);
    CAkRTPCMgr::SubscribeRTPC(
      g_pRTPCMgr,
      this,
      in_RTPC_ID,
      (AkRTPC_ParameterID)in_ParamID,
      in_RTPCCurveID,
      in_eScaling,
      in_pArrayConversion,
      in_ulConversionArraySize,
      0i64,
      in_eType);
    this->vfptr[7].__vecDelDtor(this, in_ParamID);
  }
}

// File Line: 1854
// RVA: 0xA74B00
void __fastcall CAkParameterNodeBase::UnsetRTPC(
        CAkParameterNodeBase *this,
        unsigned int in_ParamID,
        unsigned int in_RTPCCurveID)
{
  __int64 v5; // rdx
  int v6; // r8d
  char *m_pProps; // r9
  unsigned int v8; // r10d
  __int64 v9; // rcx
  __int64 v10; // rdx
  int *p_iValue; // rax
  int iValue; // [rsp+40h] [rbp+8h] BYREF
  bool out_bMoreCurvesRemaining; // [rsp+48h] [rbp+10h] BYREF

  out_bMoreCurvesRemaining = 0;
  if ( !g_pRTPCMgr
    || (CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, this, in_ParamID, in_RTPCCurveID, &out_bMoreCurvesRemaining),
        !out_bMoreCurvesRemaining) )
  {
    this->m_RTPCBitArray.m_iBitArray &= ~(1i64 << in_ParamID);
  }
  this->vfptr[12].Category(this);
  if ( in_ParamID == 20 )
  {
    v6 = 11;
  }
  else
  {
    if ( in_ParamID != 21 )
    {
      if ( in_ParamID - 37 > 1 )
        return;
      goto LABEL_18;
    }
    v6 = 12;
  }
  m_pProps = this->m_props.m_pProps;
  iValue = g_AkPropDefault[v6].iValue;
  if ( m_pProps )
  {
    v8 = (unsigned __int8)*m_pProps;
    v9 = 0i64;
    while ( 1 )
    {
      v10 = (unsigned int)(v9 + 1);
      if ( m_pProps[v10] == (_BYTE)v6 )
        break;
      v9 = (unsigned int)v10;
      if ( (unsigned int)v10 >= v8 )
        goto LABEL_14;
    }
    v5 = (__int64)&m_pProps[4 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_14:
    v5 = 0i64;
  }
  p_iValue = &iValue;
  if ( v5 )
    p_iValue = (int *)v5;
  iValue = *p_iValue;
LABEL_18:
  ((void (__fastcall *)(CAkParameterNodeBase *, __int64, _QWORD, _QWORD, _QWORD))this->vfptr[17].Release)(
    this,
    v5,
    in_ParamID,
    0i64,
    0i64);
}

// File Line: 1910
// RVA: 0xA72380
char __fastcall CAkParameterNodeBase::GetStateSyncTypes(
        CAkParameterNodeBase *this,
        unsigned int in_stateGroupID,
        CAkParameterNodeBase::CAkStateSyncArray *io_pSyncTypes,
        char in_bBusChecked)
{
  CAkParameterNodeBase *v7; // rbx
  CAkBus *m_pBusOutputNode; // rcx

  v7 = this;
  while ( !CAkParameterNodeBase::CheckSyncTypes(
             v7,
             in_stateGroupID,
             (AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *)io_pSyncTypes) )
  {
    if ( !in_bBusChecked )
    {
      m_pBusOutputNode = (CAkBus *)v7->m_pBusOutputNode;
      if ( m_pBusOutputNode )
      {
        in_bBusChecked = 1;
        if ( CAkBus::GetStateSyncTypes(m_pBusOutputNode, in_stateGroupID, io_pSyncTypes) )
          break;
      }
    }
    v7 = v7->m_pParentNode;
    if ( !v7 )
      return 0;
  }
  return 1;
}

// File Line: 1930
// RVA: 0xA70F10
bool __fastcall CAkParameterNodeBase::CheckSyncTypes(
        CAkParameterNodeBase *this,
        unsigned int in_stateGroupID,
        AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *io_pSyncTypes)
{
  AkStateGroupChunk *m_pFirst; // rax
  unsigned int m_eStateSyncType; // ebx
  unsigned int *v5; // rax
  AkSyncType *m_pItems; // rax
  AkSyncType *v7; // rdx
  unsigned int *v8; // rax

  m_pFirst = this->m_states.m_pFirst;
  if ( !m_pFirst )
  {
LABEL_14:
    LOBYTE(m_pFirst) = 0;
    return (char)m_pFirst;
  }
  while ( m_pFirst->m_ulStateGroup != in_stateGroupID )
  {
    m_pFirst = m_pFirst->m_pNextInNode;
    if ( !m_pFirst )
      return (char)m_pFirst;
  }
  m_eStateSyncType = (unsigned __int8)m_pFirst->m_eStateSyncType;
  if ( m_pFirst->m_eStateSyncType )
  {
    m_pItems = (AkSyncType *)io_pSyncTypes->m_pItems;
    v7 = (AkSyncType *)&io_pSyncTypes->m_pItems[io_pSyncTypes->m_uLength];
    if ( (AkSyncType *)io_pSyncTypes->m_pItems == v7 )
    {
LABEL_12:
      v8 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast(io_pSyncTypes);
      if ( v8 )
        *v8 = m_eStateSyncType;
    }
    else
    {
      while ( *m_pItems != m_eStateSyncType )
      {
        if ( ++m_pItems == v7 )
          goto LABEL_12;
      }
    }
    goto LABEL_14;
  }
  io_pSyncTypes->m_uLength = m_eStateSyncType;
  v5 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast(io_pSyncTypes);
  if ( v5 )
    *v5 = m_eStateSyncType;
  LOBYTE(m_pFirst) = 1;
  return (char)m_pFirst;
}

// File Line: 1974
// RVA: 0xA73BE0
void __fastcall CAkParameterNodeBase::SetFeedbackVolume(
        CAkParameterNodeBase *this,
        CAkRegisteredObj *in_GameObjPtr,
        AkValueMeaning in_eValueMeaning,
        float in_fTargetValue,
        AkCurveInterpolation in_eFadeCurve,
        int in_lTransitionTime)
{
  CAkSIS *v8; // rax

  v8 = (CAkSIS *)this->vfptr[19].__vecDelDtor(this, in_GameObjPtr);
  if ( v8 )
    CAkParameterNodeBase::StartSISTransition(
      this,
      v8,
      AkPropID_FeedbackVolume,
      in_fTargetValue,
      in_eValueMeaning,
      in_eFadeCurve,
      in_lTransitionTime);
}

// File Line: 1993
// RVA: 0xA71750
void __fastcall CAkParameterNodeBase::FeedbackParentBus(CAkParameterNodeBase *this, CAkFeedbackBus *in_pParent)
{
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rax
  CAkParameterNodeBase::AkFeedbackInfo *v5; // rax

  if ( in_pParent || this->m_pFeedbackInfo )
  {
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
      goto LABEL_7;
    v5 = (CAkParameterNodeBase::AkFeedbackInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8ui64);
    this->m_pFeedbackInfo = v5;
    if ( v5 )
      v5->m_pFeedbackBus = 0i64;
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
LABEL_7:
      m_pFeedbackInfo->m_pFeedbackBus = in_pParent;
  }
}

// File Line: 2009
// RVA: 0xA71740
CAkIndexableVtbl *__fastcall CAkParameterNodeBase::FeedbackParentBus(CAkParameterNodeBase *this)
{
  CAkIndexableVtbl *result; // rax

  result = (CAkIndexableVtbl *)this->m_pFeedbackInfo;
  if ( result )
    return (CAkIndexableVtbl *)result->__vecDelDtor;
  return result;
}

// File Line: 2017
// RVA: 0xA72130
CAkFeedbackBus *__fastcall CAkParameterNodeBase::GetFeedbackParentBusOrDefault(CAkParameterNodeBase *this)
{
  CAkFeedbackBus *result; // rax
  CAkFeedbackBus *v3; // rbx

  result = (CAkFeedbackBus *)((__int64 (__fastcall *)(CAkParameterNodeBase *))this->vfptr[16].Release)(this);
  if ( !result )
  {
    result = CAkFeedbackBus::GetMasterMotionBusAndAddRef();
    v3 = result;
    if ( result )
    {
      this->vfptr->AddRef(this);
      ((void (__fastcall *)(CAkFeedbackBus *, CAkParameterNodeBase *))v3->vfptr[2].AddRef)(v3, this);
      v3->vfptr->Release(v3);
      return v3;
    }
  }
  return result;
}

// File Line: 2040
// RVA: 0xA71F80
__int64 __fastcall CAkParameterNodeBase::GetFeedbackParameters(
        CAkParameterNodeBase *this,
        AkFeedbackParams *io_Params,
        CAkSource *in_pSource,
        CAkRegisteredObj *in_GameObjPtr,
        bool in_bDoBusCheck)
{
  bool v5; // di
  double v10; // xmm0_8
  float v11; // xmm6_4
  CAkFeedbackBus *m_pFeedbackBus; // rcx
  CAkParameterNodeBase *v13; // rax
  CAkParameterNodeBase *m_pBusOutputNode; // r9
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rdx
  char *m_pProps; // r8
  unsigned int v17; // r10d
  __int64 v18; // rcx
  __int64 v19; // rdx
  __int64 v20; // rdx
  float *v21; // rax
  float v22; // xmm0_4
  CAkParameterNodeBase *m_pParentNode; // rcx
  int v25; // [rsp+20h] [rbp-38h]
  float v26; // [rsp+60h] [rbp+8h] BYREF

  v5 = io_Params->m_usPluginID == 0;
  if ( this->m_pFeedbackInfo )
  {
    v10 = ((double (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *))this->vfptr[17].__vecDelDtor)(
            this,
            in_GameObjPtr);
    v11 = *(float *)&v10;
    ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *))this->vfptr[17].AddRef)(this, in_GameObjPtr);
    if ( in_bDoBusCheck )
    {
      m_pFeedbackBus = this->m_pFeedbackInfo->m_pFeedbackBus;
      io_Params->m_NewVolume = *(float *)&v10;
      io_Params->m_LPF = *(float *)&v10;
      if ( v5 )
      {
        io_Params->m_pOutput = m_pFeedbackBus;
        io_Params->m_usPluginID = -1;
      }
      ((void (__fastcall *)(CAkFeedbackBus *, AkFeedbackParams *, CAkSource *, CAkRegisteredObj *, _BYTE))m_pFeedbackBus->vfptr[16].__vecDelDtor)(
        m_pFeedbackBus,
        io_Params,
        in_pSource,
        in_GameObjPtr,
        0);
      v13 = this;
      while ( 1 )
      {
        m_pBusOutputNode = v13->m_pBusOutputNode;
        v13 = v13->m_pParentNode;
        if ( m_pBusOutputNode )
          break;
        if ( !v13 )
          goto LABEL_22;
      }
      do
      {
        m_pFXChunk = m_pBusOutputNode->m_pFXChunk;
        if ( m_pFXChunk
          && (m_pFXChunk->aFX[0].id != 0
           || m_pFXChunk->aFX[1].id != 0
           || m_pFXChunk->aFX[2].id != 0
           || m_pFXChunk->aFX[3].id != 0) )
        {
          break;
        }
        m_pProps = m_pBusOutputNode->m_props.m_pProps;
        v26 = 0.0;
        if ( m_pProps )
        {
          v17 = (unsigned __int8)*m_pProps;
          v18 = 0i64;
          while ( 1 )
          {
            v19 = (unsigned int)(v18 + 1);
            if ( !m_pProps[v19] )
              break;
            v18 = (unsigned int)v19;
            if ( (unsigned int)v19 >= v17 )
              goto LABEL_15;
          }
          v20 = (__int64)&m_pProps[4 * v18 + ((v17 + 4) & 0xFFFFFFFC)];
        }
        else
        {
LABEL_15:
          v20 = 0i64;
        }
        v21 = &v26;
        if ( v20 )
          v21 = (float *)v20;
        v26 = *v21;
        io_Params->m_AudioBusVolume = v26 + io_Params->m_AudioBusVolume;
        m_pBusOutputNode = m_pBusOutputNode->m_pBusOutputNode;
      }
      while ( m_pBusOutputNode );
    }
    else
    {
      v22 = *(float *)&v10 + io_Params->m_LPF;
      io_Params->m_NewVolume = v11 + io_Params->m_NewVolume;
      io_Params->m_LPF = v22;
    }
  }
LABEL_22:
  m_pParentNode = this->m_pParentNode;
  if ( m_pParentNode )
  {
    LOBYTE(v25) = 0;
    ((void (__fastcall *)(CAkParameterNodeBase *, AkFeedbackParams *, CAkSource *, CAkRegisteredObj *, int))m_pParentNode->vfptr[16].__vecDelDtor)(
      m_pParentNode,
      io_Params,
      in_pSource,
      in_GameObjPtr,
      v25);
  }
  return 1i64;
}

// File Line: 2117
// RVA: 0xA71EF0
double __fastcall CAkParameterNodeBase::GetEffectiveFeedbackVolume(
        CAkParameterNodeBase *this,
        CAkRegisteredObj *in_GameObjPtr)
{
  double result; // xmm0_8
  char *m_pProps; // r8
  __int64 v4; // r10
  unsigned int v5; // r9d
  __int64 v6; // rcx
  __int64 v7; // rdx
  unsigned int *p_iValue; // rax
  unsigned int iValue; // [rsp+8h] [rbp+8h] BYREF

  if ( (this->m_RTPCBitArray.m_iBitArray & 0x20000000) != 0 )
  {
    *(float *)&result = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x1Du, in_GameObjPtr);
  }
  else
  {
    m_pProps = this->m_props.m_pProps;
    v4 = 0i64;
    iValue = g_AkPropDefault[8].iValue;
    if ( m_pProps )
    {
      v5 = (unsigned __int8)*m_pProps;
      v6 = 0i64;
      while ( 1 )
      {
        v7 = (unsigned int)(v6 + 1);
        if ( m_pProps[v7] == 8 )
          break;
        v6 = (unsigned int)v7;
        if ( (unsigned int)v7 >= v5 )
          goto LABEL_9;
      }
      v4 = (__int64)&m_pProps[4 * v6 + ((v5 + 4) & 0xFFFFFFFC)];
    }
LABEL_9:
    p_iValue = &iValue;
    if ( v4 )
      p_iValue = (unsigned int *)v4;
    iValue = *p_iValue;
    *(_QWORD *)&result = iValue;
  }
  return result;
}

// File Line: 2125
// RVA: 0xA71E40
float __fastcall CAkParameterNodeBase::GetEffectiveFeedbackLPF(
        CAkParameterNodeBase *this,
        CAkRegisteredObj *in_GameObjPtr)
{
  char *m_pProps; // r9
  __int64 v3; // r11
  unsigned int v6; // r10d
  int v7; // r8d
  __int64 v8; // rcx
  int *v9; // rax
  float v10; // xmm6_4
  float v12; // [rsp+40h] [rbp+8h] BYREF

  m_pProps = this->m_props.m_pProps;
  v3 = 0i64;
  v12 = 0.0;
  if ( m_pProps )
  {
    v6 = (unsigned __int8)*m_pProps;
    v7 = 0;
    while ( 1 )
    {
      v8 = (unsigned int)(v7 + 1);
      if ( m_pProps[v8] == 9 )
        break;
      ++v7;
      if ( (unsigned int)v8 >= v6 )
        goto LABEL_7;
    }
    v3 = (__int64)&m_pProps[4 * v7 + ((v6 + 4) & 0xFFFFFFFC)];
  }
LABEL_7:
  v9 = (int *)&v12;
  if ( v3 )
    v9 = (int *)v3;
  v12 = *(float *)v9;
  v10 = v12;
  if ( (this->m_RTPCBitArray.m_iBitArray & 0x40000000) != 0 )
    return v10 + CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x1Eu, in_GameObjPtr);
  return v10;
}

// File Line: 2134
// RVA: 0xA72590
char __fastcall CAkParameterNodeBase::IncrementActivityCount(
        CAkParameterNodeBase *this,
        unsigned __int16 in_flagForwardToBus)
{
  unsigned __int16 v2; // di
  char v4; // bl
  AkActivityChunk *m_pActivityChunk; // rax
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rax
  CAkParameterNodeBase *m_pParentNode; // rcx

  v2 = in_flagForwardToBus;
  v4 = CAkParameterNodeBase::EnableActivityChunk(this, in_flagForwardToBus);
  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
    ++m_pActivityChunk->m_uActivityCount;
  if ( (v2 & 1) != 0 )
  {
    m_pBusOutputNode = this->m_pBusOutputNode;
    if ( m_pBusOutputNode )
    {
      v2 &= ~1u;
      v4 &= ((__int64 (__fastcall *)(CAkParameterNodeBase *, __int64))m_pBusOutputNode->vfptr[9].Release)(
              m_pBusOutputNode,
              3i64);
    }
  }
  if ( (v2 & 2) != 0 )
  {
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
    {
      if ( m_pFeedbackInfo->m_pFeedbackBus )
      {
        v2 &= ~2u;
        v4 &= ((__int64 (__fastcall *)(CAkFeedbackBus *, __int64))m_pFeedbackInfo->m_pFeedbackBus->vfptr[9].Release)(
                m_pFeedbackInfo->m_pFeedbackBus,
                3i64);
      }
    }
  }
  m_pParentNode = this->m_pParentNode;
  if ( m_pParentNode )
    return v4 & ((__int64 (__fastcall *)(CAkParameterNodeBase *, _QWORD))m_pParentNode->vfptr[9].Release)(
                  m_pParentNode,
                  v2);
  else
    return v4;
}

// File Line: 2168
// RVA: 0xA70F90
void __fastcall CAkParameterNodeBase::DecrementActivityCount(
        CAkParameterNodeBase *this,
        unsigned __int16 in_flagForwardToBus)
{
  AkActivityChunk *m_pActivityChunk; // rax
  AkActivityChunk *v5; // rax
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rax
  CAkParameterNodeBase *m_pParentNode; // rcx

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    --m_pActivityChunk->m_uActivityCount;
    v5 = this->m_pActivityChunk;
    if ( !*(_DWORD *)&v5->m_PlayCount
      && !v5->m_iPlayCountValid
      && !v5->m_iVirtualCountValid
      && !v5->m_listPBI.m_pFirst
      && !v5->m_ListPlayCountPerObj.m_uLength )
    {
      CAkParameterNodeBase::DeleteActivityChunk(this);
    }
  }
  if ( (in_flagForwardToBus & 1) != 0 )
  {
    m_pBusOutputNode = this->m_pBusOutputNode;
    if ( m_pBusOutputNode )
    {
      in_flagForwardToBus &= ~1u;
      ((void (__fastcall *)(CAkParameterNodeBase *, __int64))m_pBusOutputNode->vfptr[9].Category)(
        m_pBusOutputNode,
        3i64);
    }
  }
  if ( (in_flagForwardToBus & 2) != 0 )
  {
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
    {
      if ( m_pFeedbackInfo->m_pFeedbackBus )
      {
        in_flagForwardToBus &= ~2u;
        ((void (__fastcall *)(CAkFeedbackBus *, __int64))m_pFeedbackInfo->m_pFeedbackBus->vfptr[9].Category)(
          m_pFeedbackInfo->m_pFeedbackBus,
          3i64);
      }
    }
  }
  m_pParentNode = this->m_pParentNode;
  if ( m_pParentNode )
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))m_pParentNode->vfptr[9].Category)(
      m_pParentNode,
      in_flagForwardToBus);
}

// File Line: 2198
// RVA: 0xA71C70
void __fastcall CAkParameterNodeBase::GetAudioStateParams(
        CAkParameterNodeBase *this,
        AkSoundParams *io_Parameters,
        char in_uParamSelect)
{
  AkStateGroupChunk *m_pFirst; // rax
  int v5; // edi
  int v6; // esi
  int v7; // ebp
  int v8; // ebx
  char *m_pProps; // r9
  unsigned int v10; // r10d
  int v11; // edx
  __int64 v12; // r8
  float *v13; // r8
  char *v14; // r9
  unsigned int v15; // r10d
  int v16; // edx
  __int64 v17; // r8
  float *v18; // r8
  char *v19; // r9
  unsigned int v20; // r10d
  int v21; // edx
  __int64 v22; // r8
  float *v23; // r8
  char *v24; // r9
  unsigned int v25; // r10d
  int v26; // edx
  __int64 v27; // r8
  float *v28; // r8

  if ( *((char *)this + 82) < 0 )
  {
    m_pFirst = this->m_states.m_pFirst;
    if ( m_pFirst )
    {
      v5 = in_uParamSelect & 1;
      v6 = in_uParamSelect & 2;
      v7 = in_uParamSelect & 4;
      v8 = in_uParamSelect & 8;
      do
      {
        if ( v5 )
        {
          m_pProps = m_pFirst->m_values.m_pProps;
          if ( m_pProps )
          {
            v10 = (unsigned __int8)*m_pProps;
            v11 = 0;
            while ( 1 )
            {
              v12 = (unsigned int)(v11 + 1);
              if ( !m_pProps[v12] )
                break;
              ++v11;
              if ( (unsigned int)v12 >= v10 )
                goto LABEL_12;
            }
            v13 = (float *)&m_pProps[16 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
            if ( v13 )
              io_Parameters->Volume = *v13 + io_Parameters->Volume;
          }
        }
LABEL_12:
        if ( v6 )
        {
          v14 = m_pFirst->m_values.m_pProps;
          if ( v14 )
          {
            v15 = (unsigned __int8)*v14;
            v16 = 0;
            while ( 1 )
            {
              v17 = (unsigned int)(v16 + 1);
              if ( v14[v17] == 2 )
                break;
              ++v16;
              if ( (unsigned int)v17 >= v15 )
                goto LABEL_20;
            }
            v18 = (float *)&v14[16 * v16 + ((v15 + 4) & 0xFFFFFFFC)];
            if ( v18 )
              io_Parameters->Pitch = io_Parameters->Pitch + *v18;
          }
        }
LABEL_20:
        if ( v7 )
        {
          v19 = m_pFirst->m_values.m_pProps;
          if ( v19 )
          {
            v20 = (unsigned __int8)*v19;
            v21 = 0;
            while ( 1 )
            {
              v22 = (unsigned int)(v21 + 1);
              if ( v19[v22] == 3 )
                break;
              ++v21;
              if ( (unsigned int)v22 >= v20 )
                goto LABEL_28;
            }
            v23 = (float *)&v19[16 * v21 + ((v20 + 4) & 0xFFFFFFFC)];
            if ( v23 )
              io_Parameters->LPF = io_Parameters->LPF + *v23;
          }
        }
LABEL_28:
        if ( v8 )
        {
          v24 = m_pFirst->m_values.m_pProps;
          if ( v24 )
          {
            v25 = (unsigned __int8)*v24;
            v26 = 0;
            while ( 1 )
            {
              v27 = (unsigned int)(v26 + 1);
              if ( v24[v27] == 4 )
                break;
              ++v26;
              if ( (unsigned int)v27 >= v25 )
                goto LABEL_36;
            }
            v28 = (float *)&v24[16 * v26 + ((v25 + 4) & 0xFFFFFFFC)];
            if ( v28 )
              io_Parameters->BusVolume = io_Parameters->BusVolume + *v28;
          }
        }
LABEL_36:
        m_pFirst = m_pFirst->m_pNextInNode;
      }
      while ( m_pFirst );
    }
  }
}

// File Line: 2249
// RVA: 0xA72930
__int64 __fastcall CAkParameterNodeBase::IncrementPlayCountGlobal(
        CAkParameterNodeBase *this,
        float in_fPriority,
        unsigned __int16 *io_ui16NumKickedOrRevived,
        CAkLimiter **io_pLimiter)
{
  AkActivityChunk *m_pActivityChunk; // rax
  int RTPCConvertedValue; // edx
  CAkLimiter *p_m_Limiter; // r10
  AkActivityChunk *v10; // rax
  unsigned __int16 v11; // r8
  unsigned __int16 v12; // cx
  char v13; // al
  __int64 result; // rax
  CAkParameterNodeBase *out_pKicked; // [rsp+60h] [rbp+8h] BYREF

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
    ++m_pActivityChunk->m_iPlayCountValid;
  LOWORD(RTPCConvertedValue) = this->m_u16MaxNumInstance;
  if ( (this->m_RTPCBitArray.m_iBitArray & 0x200) != 0 )
  {
    if ( !(_WORD)RTPCConvertedValue )
      return 1i64;
    RTPCConvertedValue = (int)CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 9u, 0i64);
  }
  if ( (_WORD)RTPCConvertedValue )
  {
    p_m_Limiter = &this->m_pActivityChunk->m_Limiter;
    *io_pLimiter = p_m_Limiter;
    if ( !*io_ui16NumKickedOrRevived )
    {
      v10 = this->m_pActivityChunk;
      v11 = v10 ? v10->m_iPlayCountValid : 0;
      v12 = v10 ? v10->m_iVirtualCountValid : 0;
      if ( v11 - v12 > (unsigned __int16)RTPCConvertedValue )
      {
        v13 = *((_BYTE *)this + 82);
        out_pKicked = 0i64;
        result = CAkURenderer::Kick(
                   p_m_Limiter,
                   RTPCConvertedValue,
                   in_fPriority,
                   0i64,
                   v13 & 1,
                   (v13 & 2) != 0,
                   &out_pKicked,
                   KickFrom_OverNodeLimit);
        ++*io_ui16NumKickedOrRevived;
        return result;
      }
    }
  }
  return 1i64;
}

// File Line: 2269
// RVA: 0xA71160
void __fastcall CAkParameterNodeBase::DecrementPlayCountGlobal(CAkParameterNodeBase *this)
{
  AkActivityChunk *m_pActivityChunk; // rax
  AkActivityChunk *v2; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    --m_pActivityChunk->m_iPlayCountValid;
    v2 = this->m_pActivityChunk;
    if ( !*(_DWORD *)&v2->m_PlayCount
      && !v2->m_iPlayCountValid
      && !v2->m_iVirtualCountValid
      && !v2->m_listPBI.m_pFirst
      && !v2->m_ListPlayCountPerObj.m_uLength )
    {
      CAkParameterNodeBase::DeleteActivityChunk(this);
    }
  }
}

// File Line: 2282
// RVA: 0xA71390
void __fastcall CAkParameterNodeBase::DecrementVirtualCountGlobal(
        CAkParameterNodeBase *this,
        unsigned __int16 *io_ui16NumKickedOrRevived,
        bool in_bAllowKick)
{
  AkActivityChunk *m_pActivityChunk; // rax
  int RTPCConvertedValue; // r10d
  AkActivityChunk *v7; // rdx
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // r8
  char v10; // r8
  AkActivityChunk *v11; // rax
  CAkParameterNodeBase *out_pKicked; // [rsp+50h] [rbp+8h] BYREF

  m_pActivityChunk = this->m_pActivityChunk;
  if ( !m_pActivityChunk )
    return;
  --m_pActivityChunk->m_iVirtualCountValid;
  if ( in_bAllowKick )
  {
    LOWORD(RTPCConvertedValue) = this->m_u16MaxNumInstance;
    if ( (this->m_RTPCBitArray.m_iBitArray & 0x200) == 0 )
    {
LABEL_6:
      if ( (_WORD)RTPCConvertedValue )
      {
        v7 = this->m_pActivityChunk;
        v8 = v7 ? v7->m_iPlayCountValid : 0;
        v9 = v7 ? v7->m_iVirtualCountValid : 0;
        if ( v8 - *io_ui16NumKickedOrRevived - v9 > (unsigned __int16)RTPCConvertedValue )
        {
          v10 = *((_BYTE *)this + 82);
          out_pKicked = 0i64;
          CAkURenderer::Kick(
            &v7->m_Limiter,
            RTPCConvertedValue,
            101.0,
            0i64,
            v10 & 1,
            (v10 & 2) != 0,
            &out_pKicked,
            KickFrom_OverNodeLimit);
          ++*io_ui16NumKickedOrRevived;
        }
      }
      goto LABEL_15;
    }
    if ( (_WORD)RTPCConvertedValue )
    {
      RTPCConvertedValue = (int)CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 9u, 0i64);
      goto LABEL_6;
    }
  }
LABEL_15:
  v11 = this->m_pActivityChunk;
  if ( !v11->m_PlayCount
    && !v11->m_uActivityCount
    && !v11->m_iPlayCountValid
    && !v11->m_iVirtualCountValid
    && !v11->m_listPBI.m_pFirst
    && !v11->m_ListPlayCountPerObj.m_uLength )
  {
    CAkParameterNodeBase::DeleteActivityChunk(this);
  }
}

// File Line: 2307
// RVA: 0xA72680
__int64 __fastcall CAkParameterNodeBase::IncrementPlayCountGameObject(
        CAkParameterNodeBase *this,
        float in_fPriority,
        unsigned __int16 *io_ui16NumKickedOrRevived,
        CAkRegisteredObj *in_pGameObj,
        CAkLimiter **io_pLimiter)
{
  AkActivityChunk *m_pActivityChunk; // rdx
  MapStruct<CAkRegisteredObj *,StructMaxInst> *m_pItems; // rax
  __int64 v9; // rdx
  unsigned int i; // r15d
  StructMaxInst *p_item; // rdi
  CAkLimiter *m_pLimiter; // r8
  unsigned __int16 m_u16LimiterMax; // r13
  char v15; // dl
  __int64 v16; // rbx
  int RTPCConvertedValue; // edi
  bool v18; // r12
  CAkLimiter *v19; // rax
  CAkLimiter *v20; // rbx
  char v21; // al
  AkActivityChunk *v22; // r8
  CAkRegisteredObj **p_key; // rax
  __int64 v24; // rcx
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v25; // rax
  CAkPBI **v26; // rdx
  __int64 v28; // [rsp+48h] [rbp-30h]
  CAkParameterNodeBase *out_pKicked; // [rsp+80h] [rbp+8h] BYREF

  m_pActivityChunk = this->m_pActivityChunk;
  m_pItems = m_pActivityChunk->m_ListPlayCountPerObj.m_pItems;
  v9 = (__int64)&m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[m_pActivityChunk->m_ListPlayCountPerObj.m_uLength];
  for ( i = 1; m_pItems != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v9; ++m_pItems )
  {
    if ( m_pItems->key == in_pGameObj )
      break;
  }
  if ( m_pItems == (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v9
    || (p_item = &m_pItems->item, m_pItems == (MapStruct<CAkRegisteredObj *,StructMaxInst> *)-8i64) )
  {
    LOWORD(RTPCConvertedValue) = this->m_u16MaxNumInstance;
    if ( (this->m_RTPCBitArray.m_iBitArray & 0x200) != 0 && (_WORD)RTPCConvertedValue )
      RTPCConvertedValue = (int)CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 9u, in_pGameObj);
    m_u16LimiterMax = RTPCConvertedValue;
    LODWORD(v28) = 1;
    v18 = (*((_BYTE *)this + 82) & 2) != 0;
    LOBYTE(out_pKicked) = *((_BYTE *)this + 82) & 1;
    v19 = (CAkLimiter *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
    v20 = v19;
    if ( v19 )
    {
      v19->m_sortedPBIList.m_pItems = 0i64;
      *(_QWORD *)&v19->m_sortedPBIList.m_uLength = 0i64;
      v19->m_u16LimiterMax = RTPCConvertedValue;
      v21 = (char)out_pKicked;
      v20->m_bAllowUseVirtualBehavior = v18;
      v20->m_bDoesKillNewest = v21;
    }
    else
    {
      v20 = 0i64;
    }
    v22 = this->m_pActivityChunk;
    p_key = &v22->m_ListPlayCountPerObj.m_pItems->key;
    v24 = (__int64)&v22->m_ListPlayCountPerObj.m_pItems[v22->m_ListPlayCountPerObj.m_uLength];
    if ( v22->m_ListPlayCountPerObj.m_pItems == (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v24 )
      goto LABEL_27;
    do
    {
      if ( *p_key == in_pGameObj )
        break;
      p_key += 3;
    }
    while ( p_key != (CAkRegisteredObj **)v24 );
    if ( p_key == (CAkRegisteredObj **)v24 )
    {
LABEL_27:
      p_item = 0i64;
    }
    else
    {
      p_item = (StructMaxInst *)(p_key + 1);
      if ( p_key != (CAkRegisteredObj **)-8i64 )
        goto LABEL_30;
    }
    v25 = AkArray<MapStruct<CAkRegisteredObj *,StructMaxInst>,MapStruct<CAkRegisteredObj *,StructMaxInst> const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(&this->m_pActivityChunk->m_ListPlayCountPerObj);
    if ( !v25 )
      goto LABEL_31;
    v25->key = in_pGameObj;
    p_item = &v25->item;
LABEL_30:
    p_item->m_pLimiter = v20;
    *(_QWORD *)&p_item->u16Current = v28;
LABEL_31:
    if ( p_item )
    {
      if ( v20 )
        goto LABEL_39;
    }
    else if ( v20 )
    {
      v26 = v20->m_sortedPBIList.m_pItems;
      if ( v20->m_sortedPBIList.m_pItems )
      {
        v20->m_sortedPBIList.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v26);
        v20->m_sortedPBIList.m_pItems = 0i64;
        v20->m_sortedPBIList.m_ulReserved = 0;
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, v20);
    }
    i = 2;
    goto LABEL_39;
  }
  m_pLimiter = p_item->m_pLimiter;
  ++m_pItems->item.u16Current;
  if ( m_pLimiter )
    m_u16LimiterMax = m_pLimiter->m_u16LimiterMax;
  else
    m_u16LimiterMax = 0;
  if ( m_pLimiter )
  {
    if ( m_pLimiter->m_u16LimiterMax )
    {
      if ( m_pItems->item.u16Current - m_pItems->item.u16CurrentVirtual - *io_ui16NumKickedOrRevived > m_u16LimiterMax )
      {
        v15 = *((_BYTE *)this + 82);
        out_pKicked = 0i64;
        i = CAkURenderer::Kick(
              m_pLimiter,
              m_u16LimiterMax,
              in_fPriority,
              in_pGameObj,
              v15 & 1,
              (v15 & 2) != 0,
              &out_pKicked,
              KickFrom_OverNodeLimit);
        if ( !out_pKicked
          || (v16 = ((__int64 (__fastcall *)(CAkParameterNodeBase *))out_pKicked->vfptr[8].__vecDelDtor)(out_pKicked),
              v16 == ((__int64 (__fastcall *)(CAkParameterNodeBase *))this->vfptr[8].__vecDelDtor)(this)) )
        {
          ++*io_ui16NumKickedOrRevived;
        }
      }
    }
  }
LABEL_39:
  if ( p_item && m_u16LimiterMax )
    *io_pLimiter = p_item->m_pLimiter;
  return i;
}

// File Line: 2355
// RVA: 0xA710B0
void __fastcall CAkParameterNodeBase::DecrementPlayCountGameObject(
        CAkParameterNodeBase *this,
        CAkRegisteredObj *in_pGameObj)
{
  AkActivityChunk *m_pActivityChunk; // r8
  MapStruct<CAkRegisteredObj *,StructMaxInst> *m_pItems; // rax
  __int64 v6; // r8
  bool v7; // zf
  AkActivityChunk *v8; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  m_pItems = m_pActivityChunk->m_ListPlayCountPerObj.m_pItems;
  v6 = (__int64)&m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[m_pActivityChunk->m_ListPlayCountPerObj.m_uLength];
  if ( m_pItems != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v6 )
  {
    do
    {
      if ( m_pItems->key == in_pGameObj )
        break;
      ++m_pItems;
    }
    while ( m_pItems != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v6 );
    if ( m_pItems != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v6
      && m_pItems != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)-8i64 )
    {
      v7 = m_pItems->item.u16Current-- == 1;
      if ( v7 && !m_pItems->item.u16CurrentVirtual )
      {
        StructMaxInst::DisableLimiter(&m_pItems->item);
        CAkKeyArray<CAkRegisteredObj *,StructMaxInst,2>::Unset(
          &this->m_pActivityChunk->m_ListPlayCountPerObj,
          in_pGameObj);
      }
      v8 = this->m_pActivityChunk;
      if ( !v8->m_PlayCount
        && !v8->m_uActivityCount
        && !v8->m_iPlayCountValid
        && !v8->m_iVirtualCountValid
        && !v8->m_listPBI.m_pFirst
        && !v8->m_ListPlayCountPerObj.m_uLength )
      {
        CAkParameterNodeBase::DeleteActivityChunk(this);
      }
    }
  }
}

// File Line: 2375
// RVA: 0xA72A70
void __fastcall CAkParameterNodeBase::IncrementVirtualCountGameObject(
        CAkParameterNodeBase *this,
        CAkRegisteredObj *in_pGameObj)
{
  AkActivityChunk *m_pActivityChunk; // r8
  CAkRegisteredObj **p_key; // rax
  __int64 v4; // rcx
  CAkRegisteredObj **v5; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  p_key = &m_pActivityChunk->m_ListPlayCountPerObj.m_pItems->key;
  v4 = (__int64)&m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[m_pActivityChunk->m_ListPlayCountPerObj.m_uLength];
  if ( m_pActivityChunk->m_ListPlayCountPerObj.m_pItems != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v4 )
  {
    do
    {
      if ( *p_key == in_pGameObj )
        break;
      p_key += 3;
    }
    while ( p_key != (CAkRegisteredObj **)v4 );
    if ( p_key != (CAkRegisteredObj **)v4 )
    {
      v5 = p_key + 1;
      if ( v5 )
        ++*((_WORD *)v5 + 5);
    }
  }
}

// File Line: 2384
// RVA: 0xA71200
void __fastcall CAkParameterNodeBase::DecrementVirtualCountGameObject(
        CAkParameterNodeBase *this,
        unsigned __int16 *io_ui16NumKickedOrRevived,
        bool in_bAllowKick,
        CAkRegisteredObj *in_pGameObj)
{
  AkActivityChunk *m_pActivityChunk; // r10
  MapStruct<CAkRegisteredObj *,StructMaxInst> *m_pItems; // rax
  __int64 v9; // r10
  StructMaxInst *p_item; // rdi
  CAkLimiter *m_pLimiter; // r10
  unsigned __int16 v12; // dx
  char v13; // al
  __int64 v14; // rbx
  AkActivityChunk *v15; // rax
  CAkParameterNodeBase *out_pKicked; // [rsp+60h] [rbp+8h] BYREF

  m_pActivityChunk = this->m_pActivityChunk;
  m_pItems = m_pActivityChunk->m_ListPlayCountPerObj.m_pItems;
  v9 = (__int64)&m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[m_pActivityChunk->m_ListPlayCountPerObj.m_uLength];
  if ( m_pItems != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v9 )
  {
    do
    {
      if ( m_pItems->key == in_pGameObj )
        break;
      ++m_pItems;
    }
    while ( m_pItems != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v9 );
    if ( m_pItems != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v9 )
    {
      p_item = &m_pItems->item;
      if ( m_pItems != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)-8i64 )
      {
        --m_pItems->item.u16CurrentVirtual;
        if ( in_bAllowKick )
        {
          m_pLimiter = p_item->m_pLimiter;
          v12 = p_item->m_pLimiter ? m_pLimiter->m_u16LimiterMax : 0;
          if ( m_pLimiter )
          {
            if ( m_pLimiter->m_u16LimiterMax )
            {
              if ( m_pItems->item.u16Current - *io_ui16NumKickedOrRevived - m_pItems->item.u16CurrentVirtual > v12 )
              {
                v13 = *((_BYTE *)this + 82);
                out_pKicked = 0i64;
                CAkURenderer::Kick(
                  m_pLimiter,
                  v12,
                  101.0,
                  in_pGameObj,
                  v13 & 1,
                  (v13 & 2) != 0,
                  &out_pKicked,
                  KickFrom_OverNodeLimit);
                if ( !out_pKicked
                  || (v14 = ((__int64 (*)(void))out_pKicked->vfptr[8].__vecDelDtor)(),
                      v14 == ((__int64 (__fastcall *)(CAkParameterNodeBase *))this->vfptr[8].__vecDelDtor)(this)) )
                {
                  ++*io_ui16NumKickedOrRevived;
                }
              }
            }
          }
        }
        if ( !p_item->u16Current && !p_item->u16CurrentVirtual )
        {
          StructMaxInst::DisableLimiter(p_item);
          CAkKeyArray<CAkRegisteredObj *,StructMaxInst,2>::Unset(
            &this->m_pActivityChunk->m_ListPlayCountPerObj,
            in_pGameObj);
          v15 = this->m_pActivityChunk;
          if ( !v15->m_PlayCount
            && !v15->m_uActivityCount
            && !v15->m_iPlayCountValid
            && !v15->m_iVirtualCountValid
            && !v15->m_listPBI.m_pFirst
            && !v15->m_ListPlayCountPerObj.m_uLength )
          {
            CAkParameterNodeBase::DeleteActivityChunk(this);
          }
        }
      }
    }
  }
}

// File Line: 2417
// RVA: 0xA72A40
__int64 __fastcall CAkParameterNodeBase::IncrementPlayCountValue(
        CAkParameterNodeBase *this,
        unsigned __int16 in_flagForwardToBus)
{
  char v3; // al
  AkActivityChunk *m_pActivityChunk; // rcx

  v3 = CAkParameterNodeBase::EnableActivityChunk(this, in_flagForwardToBus);
  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
    ++m_pActivityChunk->m_PlayCount;
  return 2 - (unsigned int)(v3 != 0);
}

// File Line: 2427
// RVA: 0xA711B0
void __fastcall CAkParameterNodeBase::DecrementPlayCountValue(CAkParameterNodeBase *this)
{
  AkActivityChunk *m_pActivityChunk; // rax
  AkActivityChunk *v2; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    --m_pActivityChunk->m_PlayCount;
    v2 = this->m_pActivityChunk;
    if ( !*(_DWORD *)&v2->m_PlayCount
      && !v2->m_iPlayCountValid
      && !v2->m_iVirtualCountValid
      && !v2->m_listPBI.m_pFirst
      && !v2->m_ListPlayCountPerObj.m_uLength )
    {
      CAkParameterNodeBase::DeleteActivityChunk(this);
    }
  }
}

// File Line: 2439
// RVA: 0xA72650
char __fastcall CAkParameterNodeBase::IncrementActivityCountValue(
        CAkParameterNodeBase *this,
        unsigned __int16 in_flagForwardToBus)
{
  char result; // al
  AkActivityChunk *m_pActivityChunk; // rcx

  result = CAkParameterNodeBase::EnableActivityChunk(this, in_flagForwardToBus);
  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
    ++m_pActivityChunk->m_uActivityCount;
  return result;
}

// File Line: 2449
// RVA: 0xA71060
void __fastcall CAkParameterNodeBase::DecrementActivityCountValue(CAkParameterNodeBase *this)
{
  AkActivityChunk *m_pActivityChunk; // rax
  AkActivityChunk *v2; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    --m_pActivityChunk->m_uActivityCount;
    v2 = this->m_pActivityChunk;
    if ( !*(_DWORD *)&v2->m_PlayCount
      && !v2->m_iPlayCountValid
      && !v2->m_iVirtualCountValid
      && !v2->m_listPBI.m_pFirst
      && !v2->m_ListPlayCountPerObj.m_uLength )
    {
      CAkParameterNodeBase::DeleteActivityChunk(this);
    }
  }
}

// File Line: 2461
// RVA: 0xA71970
__int64 __fastcall CAkParameterNodeBase::Get2DParams(
        CAkParameterNodeBase *this,
        CAkRegisteredObj *in_GameObj,
        BaseGenParams *out_pBasePosParams)
{
  __int64 v3; // rbx
  unsigned __int64 m_iBitArray; // r15
  bool v7; // r14
  bool v9; // r15
  float RTPCConvertedValue; // xmm0_4
  char *m_pProps; // r8
  unsigned int v12; // r9d
  __int64 v13; // rcx
  __int64 v14; // rdx
  __int64 v15; // rdx
  float *v16; // rax
  float v17; // eax
  char *v18; // r8
  unsigned int v19; // r9d
  __int64 v20; // rcx
  __int64 v21; // rdx
  __int64 v22; // rdx
  float *v23; // rax
  char *v24; // r8
  unsigned int v25; // r9d
  __int64 v26; // rcx
  __int64 v27; // rdx
  float *v28; // rax
  float v30; // [rsp+50h] [rbp+8h] BYREF

  v3 = 0i64;
  m_iBitArray = this->m_RTPCBitArray.m_iBitArray;
  v7 = (m_iBitArray & 0x200000) != 0;
  v9 = (m_iBitArray & 0x100000) != 0;
  if ( v9 || v7 )
  {
    if ( v9 )
      out_pBasePosParams->m_fPAN_X_2D = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x14u, in_GameObj);
    else
      out_pBasePosParams->m_fPAN_X_2D = 0.0;
    if ( !v7 )
    {
      out_pBasePosParams->m_fPAN_Y_2D = 0.0;
      goto LABEL_24;
    }
    RTPCConvertedValue = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x15u, in_GameObj);
  }
  else
  {
    m_pProps = this->m_props.m_pProps;
    v30 = 0.0;
    if ( m_pProps )
    {
      v12 = (unsigned __int8)*m_pProps;
      v13 = 0i64;
      while ( 1 )
      {
        v14 = (unsigned int)(v13 + 1);
        if ( m_pProps[v14] == 11 )
          break;
        v13 = (unsigned int)v14;
        if ( (unsigned int)v14 >= v12 )
          goto LABEL_12;
      }
      v15 = (__int64)&m_pProps[4 * v13 + ((v12 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_12:
      v15 = 0i64;
    }
    v16 = &v30;
    if ( v15 )
      v16 = (float *)v15;
    v17 = *v16;
    v30 = 0.0;
    out_pBasePosParams->m_fPAN_X_2D = v17;
    v18 = this->m_props.m_pProps;
    if ( v18 )
    {
      v19 = (unsigned __int8)*v18;
      v20 = 0i64;
      while ( 1 )
      {
        v21 = (unsigned int)(v20 + 1);
        if ( v18[v21] == 12 )
          break;
        v20 = (unsigned int)v21;
        if ( (unsigned int)v21 >= v19 )
          goto LABEL_19;
      }
      v22 = (__int64)&v18[4 * v20 + ((v19 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_19:
      v22 = 0i64;
    }
    v23 = &v30;
    if ( v22 )
      v23 = (float *)v22;
    v30 = *v23;
    RTPCConvertedValue = v30;
  }
  out_pBasePosParams->m_fPAN_Y_2D = RTPCConvertedValue;
LABEL_24:
  v24 = this->m_props.m_pProps;
  v30 = 0.0;
  if ( v24 )
  {
    v25 = (unsigned __int8)*v24;
    v26 = 0i64;
    while ( 1 )
    {
      v27 = (unsigned int)(v26 + 1);
      if ( v24[v27] == 13 )
        break;
      v26 = (unsigned int)v27;
      if ( (unsigned int)v27 >= v25 )
        goto LABEL_32;
    }
    v3 = (__int64)&v24[4 * v26 + ((v25 + 4) & 0xFFFFFFFC)];
  }
LABEL_32:
  v28 = &v30;
  if ( v3 )
    v28 = (float *)v3;
  v30 = *v28;
  out_pBasePosParams->m_fCenterPCT = v30;
  out_pBasePosParams->bIsPannerEnabled = (*((_BYTE *)this + 83) & 0x20) != 0;
  return v9 | (unsigned int)v7;
}

// File Line: 2501
// RVA: 0xA71B40
__int64 __fastcall CAkParameterNodeBase::Get3DPanning(
        CAkParameterNodeBase *this,
        CAkRegisteredObj *in_GameObj,
        AkVector *out_posPan)
{
  unsigned __int64 m_iBitArray; // rsi
  bool v6; // di
  bool v8; // si
  float RTPCConvertedValue; // xmm0_4
  float v10; // xmm1_4
  bool v11; // zf
  float v13; // [rsp+50h] [rbp+8h] BYREF

  m_iBitArray = this->m_RTPCBitArray.m_iBitArray;
  v6 = (m_iBitArray & 0x4000000000i64) != 0;
  v8 = (m_iBitArray & 0x2000000000i64) != 0;
  v13 = 0.0;
  if ( v8 || v6 )
  {
    if ( v8 )
    {
      out_posPan->X = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x25u, in_GameObj);
      if ( ((unsigned __int8 (__fastcall *)(CAkParameterNodeBase *, float *))this->vfptr[7].Release)(this, &v13) )
        out_posPan->X = (float)(v13 * 0.0099999998) * out_posPan->X;
    }
    else
    {
      out_posPan->X = 0.0;
    }
    out_posPan->Y = 0.0;
    if ( !v6 )
    {
      out_posPan->Z = 1.0;
      return v8 | (unsigned int)v6;
    }
    RTPCConvertedValue = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x26u, in_GameObj);
    v10 = v13;
    v11 = v13 == 0.0;
    out_posPan->Z = RTPCConvertedValue;
    if ( !v11 )
      goto LABEL_10;
    if ( ((unsigned __int8 (__fastcall *)(CAkParameterNodeBase *, float *))this->vfptr[7].Release)(this, &v13) )
    {
      v10 = v13;
LABEL_10:
      out_posPan->Z = (float)(v10 * 0.0099999998) * out_posPan->Z;
    }
  }
  return v8 | (unsigned int)v6;
}

// File Line: 2611
// RVA: 0xA72340
CAkState *__fastcall AkStateGroupChunk::GetState(AkStateGroupChunk *this, unsigned int in_StateTypeID)
{
  MapStruct<unsigned long,AkStateLink> *m_pItems; // rax
  MapStruct<unsigned long,AkStateLink> *v3; // rcx
  AkStateLink *p_item; // rax

  m_pItems = this->m_mapStates.m_pItems;
  v3 = &m_pItems[this->m_mapStates.m_uLength];
  if ( m_pItems == v3 )
    return 0i64;
  do
  {
    if ( m_pItems->key == in_StateTypeID )
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
    return p_item->pState;
}

// File Line: 2622
// RVA: 0xA70AE0
__int64 __fastcall AkStateGroupChunk::AddState(
        AkStateGroupChunk *this,
        unsigned int in_ulStateInstanceID,
        unsigned int in_ulStateID,
        bool in_bNotify)
{
  CAkIndexable *PtrAndAddRef; // rax
  MapStruct<unsigned long,AkStateLink> *m_pItems; // rdi
  CAkState *v10; // rbx
  MapStruct<unsigned long,AkStateLink> *v11; // rsi
  CAkState **p_pState; // rdi
  MapStruct<unsigned long,AkStateLink> *v14; // rdi
  MapStruct<unsigned long,AkStateLink> *v15; // rax
  AkStateLink v16; // [rsp+20h] [rbp-38h] BYREF

  PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                   (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxCustomStates,
                   in_ulStateInstanceID);
  m_pItems = this->m_mapStates.m_pItems;
  v10 = (CAkState *)PtrAndAddRef;
  v11 = &m_pItems[this->m_mapStates.m_uLength];
  if ( m_pItems != v11 )
  {
    do
    {
      if ( m_pItems->key == in_ulStateID )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v11 );
    if ( m_pItems != v11 )
    {
      p_pState = &m_pItems->item.pState;
      if ( p_pState )
      {
        if ( PtrAndAddRef == *p_pState )
        {
          if ( PtrAndAddRef )
            PtrAndAddRef->vfptr->Release(PtrAndAddRef);
          return 1i64;
        }
        CAkState::TermNotificationSystem(*p_pState);
        (*p_pState)->vfptr->Release(*p_pState);
        v14 = this->m_mapStates.m_pItems;
        v15 = &v14[this->m_mapStates.m_uLength];
        if ( v14 != v15 )
        {
          do
          {
            if ( v14->key == in_ulStateID )
              break;
            ++v14;
          }
          while ( v14 != v15 );
          if ( v14 != v15 )
          {
            if ( v14 < &v15[-1] )
              qmemcpy(v14, &v14[1], 24 * (((char *)&v15[-1] - (char *)v14 - 1) / 0x18ui64 + 1));
            --this->m_mapStates.m_uLength;
          }
        }
      }
    }
  }
  if ( !v10 )
    return 16i64;
  v16.pState = v10;
  v16.ulStateID = in_ulStateInstanceID;
  if ( CAkKeyArray<unsigned long,AkStateLink,2>::Set(&this->m_mapStates, in_ulStateID, &v16) )
  {
    CAkState::InitNotificationSystem(v10, this->m_pOwner);
    if ( !in_bNotify )
      return 1i64;
    ((void (__fastcall *)(CAkParameterNodeBase *))this->m_pOwner->vfptr[13].__vecDelDtor)(this->m_pOwner);
    return 1i64;
  }
  else
  {
    v10->vfptr->Release(v10);
    return 52i64;
  }
}

// File Line: 2673
// RVA: 0xA735D0
void __fastcall AkStateGroupChunk::RemoveState(AkStateGroupChunk *this, unsigned int in_ulStateID)
{
  MapStruct<unsigned long,AkStateLink> *m_pItems; // rax
  MapStruct<unsigned long,AkStateLink> *v5; // rdi
  CAkState **p_pState; // rdi
  MapStruct<unsigned long,AkStateLink> *v7; // rdi
  MapStruct<unsigned long,AkStateLink> *v8; // rax

  m_pItems = this->m_mapStates.m_pItems;
  v5 = &m_pItems[this->m_mapStates.m_uLength];
  if ( m_pItems != v5 )
  {
    do
    {
      if ( m_pItems->key == in_ulStateID )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v5 );
    if ( m_pItems != v5 )
    {
      p_pState = &m_pItems->item.pState;
      if ( m_pItems != (MapStruct<unsigned long,AkStateLink> *)-8i64 )
      {
        CAkState::TermNotificationSystem(*p_pState);
        (*p_pState)->vfptr->Release(*p_pState);
        v7 = this->m_mapStates.m_pItems;
        v8 = &v7[this->m_mapStates.m_uLength];
        if ( v7 != v8 )
        {
          do
          {
            if ( v7->key == in_ulStateID )
              break;
            ++v7;
          }
          while ( v7 != v8 );
          if ( v7 != v8 )
          {
            if ( v7 < &v8[-1] )
              qmemcpy(v7, &v7[1], 24 * (((char *)&v8[-1] - (char *)v7 - 1) / 0x18ui64 + 1));
            --this->m_mapStates.m_uLength;
          }
        }
      }
    }
  }
}

// File Line: 2685
// RVA: 0xA717F0
void __fastcall AkStateGroupChunk::FlushStateTransitions(AkStateGroupChunk *this)
{
  char *m_pProps; // rdx
  char *v3; // rcx
  char *v4; // rbx
  __int64 v5; // rdi
  CAkTransition **v6; // rbx
  __int64 v7; // rdi

  m_pProps = this->m_values.m_pProps;
  if ( m_pProps )
  {
    v3 = m_pProps + 1;
    v4 = &m_pProps[((unsigned __int8)*m_pProps + 4) & 0xFFFFFFFC];
  }
  else
  {
    v3 = 0i64;
    v4 = 0i64;
  }
  if ( m_pProps )
    v5 = (__int64)&m_pProps[(unsigned __int8)*m_pProps + 1];
  else
    v5 = 0i64;
  if ( v3 != (char *)v5 )
  {
    v6 = (CAkTransition **)(v4 + 8);
    v7 = v5 - (_QWORD)v3;
    do
    {
      if ( *v6 )
      {
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, *v6, this);
        *v6 = 0i64;
        ((void (__fastcall *)(CAkParameterNodeBase *, __int64))this->m_pOwner->vfptr[9].Category)(this->m_pOwner, 3i64);
      }
      v6 += 2;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 2701
// RVA: 0xA74940
void __fastcall AkStateGroupChunk::TransUpdateValue(
        AkStateGroupChunk *this,
        __int64 in_eTarget,
        float in_fValue,
        bool in_bIsTerminated)
{
  char *m_pProps; // r10
  unsigned int v7; // r11d
  int v8; // r8d
  __int64 v9; // r9
  __int64 v10; // rbx

  m_pProps = this->m_values.m_pProps;
  if ( m_pProps )
  {
    v7 = (unsigned __int8)*m_pProps;
    v8 = 0;
    while ( 1 )
    {
      v9 = (unsigned int)(v8 + 1);
      if ( m_pProps[v9] == (_BYTE)in_eTarget )
        break;
      ++v8;
      if ( (unsigned int)v9 >= v7 )
        goto LABEL_5;
    }
    v10 = (__int64)&m_pProps[16 * v8 + ((v7 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v10 = 0i64;
  }
  *(float *)v10 = in_fValue;
  if ( in_bIsTerminated )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, __int64))this->m_pOwner->vfptr[9].Category)(this->m_pOwner, 3i64);
    *(_QWORD *)(v10 + 8) = 0i64;
  }
  ((void (__fastcall *)(CAkParameterNodeBase *, __int64))this->m_pOwner->vfptr[12].Category)(this->m_pOwner, in_eTarget);
}

