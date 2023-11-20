// File Line: 71
// RVA: 0xA70740
signed __int64 __fastcall CAkLimiter::Add(CAkLimiter *this, CAkPBI *in_pPBI, AKVoiceLimiterType in_Type)
{
  CAkPBI *v3; // rbp
  AkPriorityStruct v4; // rdx
  bool v5; // r14
  AKVoiceLimiterType v6; // ebx
  CAkLimiter *v7; // rdi
  CAkPBI **v8; // rax
  CAkPBI **v9; // rsi
  int v10; // ebx

  v3 = in_pPBI;
  v4 = in_pPBI->m_PriorityInfoCurrent.currentPriority;
  v5 = this->m_sortedPBIList.m_uLength == 0;
  v6 = in_Type;
  v7 = this;
  if ( this->m_bDoesKillNewest )
    v8 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::AddNoSetKey<AkPriorityStruct_INC>(
           &this->m_sortedPBIList,
           (AkPriorityStruct_INC)v4);
  else
    v8 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::AddNoSetKey<AkPriorityStruct_DEC>(
           &this->m_sortedPBIList,
           (AkPriorityStruct_DEC)v4);
  v9 = v8;
  if ( !v8 )
    return 2i64;
  if ( v5 )
  {
    v10 = v6 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
      {
        CAkURenderer::AddBusLimiter(v7);
        *v9 = v3;
        return 1i64;
      }
    }
    else
    {
      CAkURenderer::AddAMLimiter(v7);
    }
  }
  *v9 = v3;
  return 1i64;
}

// File Line: 111
// RVA: 0xA734A0
void __fastcall CAkLimiter::Remove(CAkLimiter *this, CAkPBI *in_pPBI, AKVoiceLimiterType in_Type)
{
  AkPriorityStruct v3; // rdx
  AKVoiceLimiterType v4; // ebp
  CAkLimiter *v5; // rbx
  CAkPBI **v6; // rax
  unsigned __int64 v7; // rcx
  int v8; // ebp
  bool out_bFound; // [rsp+30h] [rbp+8h]

  v3 = in_pPBI->m_PriorityInfoCurrent.currentPriority;
  v4 = in_Type;
  v5 = this;
  if ( this->m_bDoesKillNewest )
    v6 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_INC>(
           &this->m_sortedPBIList,
           (AkPriorityStruct_INC)v3,
           &out_bFound);
  else
    v6 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_DEC>(
           &this->m_sortedPBIList,
           (AkPriorityStruct_DEC)v3,
           &out_bFound);
  if ( out_bFound )
  {
    v7 = (unsigned __int64)&v5->m_sortedPBIList.m_pItems[v5->m_sortedPBIList.m_uLength - 1];
    if ( (unsigned __int64)v6 < v7 )
      qmemcpy(v6, v6 + 1, 8 * (((v7 - (unsigned __int64)v6 - 1) >> 3) + 1));
    --v5->m_sortedPBIList.m_uLength;
  }
  if ( !v5->m_sortedPBIList.m_uLength )
  {
    v8 = v4 - 1;
    if ( v8 )
    {
      if ( v8 == 1 )
        CAkURenderer::RemoveBusLimiter(v5);
    }
    else
    {
      CAkURenderer::RemoveAMLimiter(v5);
    }
  }
}

// File Line: 141
// RVA: 0xA74C10
void __fastcall CAkLimiter::Update(CAkLimiter *this, float in_NewPriority, CAkPBI *in_pPBI)
{
  JUMPOUT(
    this->m_bDoesKillNewest != 0,
    AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::Reorder<AkPriorityStruct_INC>);
  AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::Reorder<AkPriorityStruct_DEC>(
    &this->m_sortedPBIList,
    (AkPriorityStruct_DEC)in_pPBI->m_PriorityInfoCurrent.currentPriority,
    (AkPriorityStruct_DEC)__PAIR__(in_pPBI->m_PriorityInfoCurrent.currentPriority.PBIID, LODWORD(in_NewPriority)),
    in_pPBI);
}

// File Line: 168
// RVA: 0xA74C50
void __fastcall CAkLimiter::UpdateFlags(CAkLimiter *this)
{
  unsigned __int16 v1; // ax
  CAkLimiter *v2; // rsi
  unsigned int v3; // er8
  __int64 v4; // rax
  CAkPBI **v5; // rbx
  CAkPBI **v6; // rdi
  unsigned int v7; // edx
  char v8; // al
  CAkPBI *v9; // rcx
  KickFrom v10; // edx

  v1 = this->m_u16LimiterMax;
  v2 = this;
  if ( v1 )
  {
    v3 = v1;
    v4 = this->m_sortedPBIList.m_uLength;
    if ( (unsigned int)v4 > v3 )
    {
      v5 = this->m_sortedPBIList.m_pItems;
      v6 = &this->m_sortedPBIList.m_pItems[v4];
      v7 = 0;
      if ( this->m_sortedPBIList.m_pItems != v6 )
      {
        while ( v7 < v3 )
        {
          v8 = *((_BYTE *)*v5 + 375);
          if ( (!(v8 & 0x40) || v8 & 0x20) && !(*((_BYTE *)*v5 + 374) & 1) && !(v8 & 0x10) )
            ++v7;
          ++v5;
          if ( v5 == v6 )
            return;
        }
        for ( ; v5 != v6; ++v5 )
        {
          v9 = *v5;
          if ( !(*((_BYTE *)*v5 + 374) & 1) )
          {
            v10 = 1;
            if ( v2 == &CAkURenderer::m_GlobalLimiter )
              v10 = 2;
            if ( v2->m_bAllowUseVirtualBehavior )
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
  CAkParameterNodeBase *v2; // rbx

  v2 = this;
  CAkIndexable::CAkIndexable((CAkIndexable *)&this->vfptr, in_ulID);
  v2->vfptr = (CAkIndexableVtbl *)&CAkParameterNodeBase::`vftable;
  v2->m_states.m_pFirst = 0i64;
  v2->m_pGlobalSIS = 0i64;
  v2->m_pFXChunk = 0i64;
  v2->m_pActivityChunk = 0i64;
  v2->m_pParentNode = 0i64;
  v2->m_pBusOutputNode = 0i64;
  v2->m_props.m_pProps = 0i64;
  *(_DWORD *)&v2->m_u16MaxNumInstance = 9437184;
  v2->m_RTPCBitArray.m_iBitArray = 0i64;
  v2->m_pFeedbackInfo = 0i64;
}

// File Line: 285
// RVA: 0xA705E0
void __fastcall CAkParameterNodeBase::~CAkParameterNodeBase(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase::FXChunk *v1; // rdx
  CAkParameterNodeBase *v2; // rbx
  unsigned int i; // esi
  CAkSIS *v4; // rsi
  int v5; // edi
  CAkParameterNodeBase::AkFeedbackInfo *v6; // rcx
  CAkFeedbackBus *v7; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *v8; // rdx
  char *v9; // rdx

  v1 = this->m_pFXChunk;
  *((_BYTE *)this + 83) |= 1u;
  v2 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkParameterNodeBase::`vftable;
  if ( v1 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
  for ( i = 0; v2->m_RTPCBitArray.m_iBitArray; ++i )
  {
    if ( (1i64 << i) & v2->m_RTPCBitArray.m_iBitArray )
    {
      CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, v2, i);
      v2->m_RTPCBitArray.m_iBitArray &= ~(1i64 << i);
    }
  }
  v4 = v2->m_pGlobalSIS;
  if ( v4 )
  {
    v5 = g_DefaultPoolId;
    CAkSIS::~CAkSIS(v2->m_pGlobalSIS);
    AK::MemoryMgr::Free(v5, v4);
  }
  if ( v2->m_states.m_pFirst )
  {
    CAkParameterNodeBase::FlushStateTransitions(v2);
    CAkParameterNodeBase::RemoveStateGroups(v2, 1);
  }
  v6 = v2->m_pFeedbackInfo;
  v2->m_states.m_pFirst = 0i64;
  if ( v6 )
  {
    v7 = v6->m_pFeedbackBus;
    if ( v7 )
      v7->vfptr[3].__vecDelDtor((CAkIndexable *)&v7->vfptr, (unsigned int)v2);
    v8 = v2->m_pFeedbackInfo;
    if ( v8 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v8);
  }
  if ( v2->m_pActivityChunk )
    CAkParameterNodeBase::DeleteActivityChunk(v2);
  v9 = v2->m_props.m_pProps;
  if ( v9 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v9);
  v2->m_props.m_pProps = 0i64;
  CAkPBIAware::~CAkPBIAware((CAkPBIAware *)&v2->vfptr);
}

// File Line: 333
// RVA: 0xA70DE0
void __fastcall CAkParameterNodeBase::AddToIndex(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase *v1; // rdi
  CAkAudioLibIndex *v2; // rbx
  __int64 v3; // rcx

  v1 = this;
  v2 = CAkAudioLibIndex::GetNodeLock(g_pIndex, (AkNodeType)(((*((_BYTE *)this + 83) >> 1) & 1) != 0));
  EnterCriticalSection(&v2->m_idxAudioNode.m_IndexLock.m_csLock);
  v3 = v1->key % 0xC1;
  v1->pNextItem = v2->m_idxAudioNode.m_mapIDToPtr.m_table[v3];
  v2->m_idxAudioNode.m_mapIDToPtr.m_table[v3] = (CAkIndexable *)&v1->vfptr;
  ++v2->m_idxAudioNode.m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&v2->m_idxAudioNode.m_IndexLock.m_csLock);
}

// File Line: 345
// RVA: 0xA70A80
__int64 __fastcall CAkParameterNodeBase::AddRef(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase *v1; // rsi
  CAkAudioLibIndex *v2; // rbx
  unsigned int v3; // edi

  v1 = this;
  v2 = CAkAudioLibIndex::GetNodeLock(g_pIndex, (AkNodeType)(((*((_BYTE *)this + 83) >> 1) & 1) != 0));
  EnterCriticalSection(&v2->m_idxAudioNode.m_IndexLock.m_csLock);
  v3 = v1->m_lRef + 1;
  v1->m_lRef = v3;
  LeaveCriticalSection(&v2->m_idxAudioNode.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 351
// RVA: 0xA733C0
__int64 __fastcall CAkParameterNodeBase::Release(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase *v1; // rsi
  AkNodeType v2; // er14
  CAkAudioLibIndex *v3; // rbx
  bool v4; // zf
  unsigned int v5; // ebp
  unsigned int v6; // edi
  CAkAudioLibIndex *v7; // rax
  CAkParameterNodeBase *v8; // rcx
  CAkParameterNodeBase *v9; // rcx
  int v10; // edi

  v1 = this;
  v2 = 0;
  v3 = CAkAudioLibIndex::GetNodeLock(g_pIndex, (AkNodeType)(((*((_BYTE *)this + 83) >> 1) & 1) != 0));
  EnterCriticalSection(&v3->m_idxAudioNode.m_IndexLock.m_csLock);
  v4 = v1->m_lRef-- == 1;
  v5 = v1->m_lRef;
  if ( v4 )
  {
    v6 = v1->key;
    LOBYTE(v2) = ((*((_BYTE *)v1 + 83) >> 1) & 1) != 0;
    v7 = CAkAudioLibIndex::GetNodeLock(g_pIndex, v2);
    CAkIndexItem<CAkEvent *>::RemoveID(&v7->m_idxAudioNode, v6);
    v1->vfptr[1].AddRef((CAkIndexable *)&v1->vfptr);
    v8 = v1->m_pParentNode;
    if ( v8 )
      v8->vfptr[3].__vecDelDtor((CAkIndexable *)&v8->vfptr, (unsigned int)v1);
    v9 = v1->m_pBusOutputNode;
    if ( v9 )
      v9->vfptr[3].__vecDelDtor((CAkIndexable *)&v9->vfptr, (unsigned int)v1);
    v10 = g_DefaultPoolId;
    v1->vfptr->__vecDelDtor((CAkIndexable *)&v1->vfptr, 0);
    AK::MemoryMgr::Free(v10, v1);
  }
  LeaveCriticalSection(&v3->m_idxAudioNode.m_IndexLock.m_csLock);
  return v5;
}

// File Line: 416
// RVA: 0xA748F0
__int64 __fastcall CAkParameterNodeBase::Stop(CAkParameterNodeBase *this, CAkRegisteredObj *in_pGameObj, unsigned int in_PlayingID, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve)
{
  CAkIndexableVtbl *v5; // rax
  int v7; // [rsp+20h] [rbp-38h]
  CAkRegisteredObj *v8; // [rsp+28h] [rbp-30h]
  unsigned int v9; // [rsp+30h] [rbp-28h]
  int v10; // [rsp+34h] [rbp-24h]
  AkCurveInterpolation v11; // [rsp+38h] [rbp-20h]
  __int16 v12; // [rsp+3Ch] [rbp-1Ch]
  char v13; // [rsp+3Eh] [rbp-1Ah]

  v8 = in_pGameObj;
  v11 = in_eFadeCurve;
  v5 = this->vfptr;
  v12 = 0;
  v13 = 0;
  v7 = 0;
  v9 = in_PlayingID;
  v10 = in_uTransitionDuration;
  return v5[4].__vecDelDtor((CAkIndexable *)&this->vfptr, (unsigned int)&v7);
}

// File Line: 434
// RVA: 0xA73040
__int64 __fastcall CAkParameterNodeBase::Pause(CAkParameterNodeBase *this, CAkRegisteredObj *in_pGameObj, unsigned int in_PlayingID, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve)
{
  CAkIndexableVtbl *v5; // rax
  int v7; // [rsp+20h] [rbp-38h]
  CAkRegisteredObj *v8; // [rsp+28h] [rbp-30h]
  unsigned int v9; // [rsp+30h] [rbp-28h]
  int v10; // [rsp+34h] [rbp-24h]
  AkCurveInterpolation v11; // [rsp+38h] [rbp-20h]
  __int16 v12; // [rsp+3Ch] [rbp-1Ch]
  char v13; // [rsp+3Eh] [rbp-1Ah]

  v8 = in_pGameObj;
  v11 = in_eFadeCurve;
  v5 = this->vfptr;
  v12 = 0;
  v13 = 0;
  v7 = 1;
  v9 = in_PlayingID;
  v10 = in_uTransitionDuration;
  return v5[4].__vecDelDtor((CAkIndexable *)&this->vfptr, (unsigned int)&v7);
}

// File Line: 452
// RVA: 0xA73890
__int64 __fastcall CAkParameterNodeBase::Resume(CAkParameterNodeBase *this, CAkRegisteredObj *in_pGameObj, unsigned int in_PlayingID, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve)
{
  CAkIndexableVtbl *v5; // rax
  int v7; // [rsp+20h] [rbp-38h]
  CAkRegisteredObj *v8; // [rsp+28h] [rbp-30h]
  unsigned int v9; // [rsp+30h] [rbp-28h]
  int v10; // [rsp+34h] [rbp-24h]
  AkCurveInterpolation v11; // [rsp+38h] [rbp-20h]
  __int16 v12; // [rsp+3Ch] [rbp-1Ch]
  char v13; // [rsp+3Eh] [rbp-1Ah]

  v8 = in_pGameObj;
  v11 = in_eFadeCurve;
  v5 = this->vfptr;
  v12 = 0;
  v13 = 0;
  v7 = 2;
  v9 = in_PlayingID;
  v10 = in_uTransitionDuration;
  return v5[4].__vecDelDtor((CAkIndexable *)&this->vfptr, (unsigned int)&v7);
}

// File Line: 471
// RVA: 0xA72C80
void __fastcall CAkParameterNodeBase::Notification(CAkParameterNodeBase *this, AkRTPC_ParameterID in_ParamID, float in_fValue, CAkRegisteredObj *in_pGameObj, void *in_pExceptArray)
{
  CAkRegisteredObj *v5; // rsi
  AkRTPC_ParameterID v6; // edi
  CAkParameterNodeBase *v7; // rbx
  CAkIndexableVtbl *v8; // rax
  AkRTPC_ParameterID v9; // [rsp+20h] [rbp-48h]
  CAkRegisteredObj *v10; // [rsp+28h] [rbp-40h]
  char v11; // [rsp+30h] [rbp-38h]
  void *v12; // [rsp+38h] [rbp-30h]
  float v13; // [rsp+40h] [rbp-28h]

  v5 = in_pGameObj;
  v6 = in_ParamID;
  v7 = this;
  if ( ((unsigned __int8 (*)(void))this->vfptr[15].Release)() )
  {
    v13 = in_fValue;
    v12 = in_pExceptArray;
    v8 = v7->vfptr;
    v9 = v6;
    v11 = 0;
    v10 = v5;
    v8[5].__vecDelDtor((CAkIndexable *)&v7->vfptr, (unsigned int)&v9);
  }
}

// File Line: 497
// RVA: 0xA731B0
void __fastcall CAkParameterNodeBase::PriorityNotification(CAkParameterNodeBase *this, NotifParams *in_rParams)
{
  this->vfptr[5].__vecDelDtor((CAkIndexable *)this, (unsigned int)in_rParams);
}

// File Line: 502
// RVA: 0xA72B50
bool __fastcall CAkParameterNodeBase::IsException(CAkParameterNodeBase *in_pNode, AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_rExceptionList)
{
  unsigned __int8 v2; // r8
  unsigned int v3; // er9
  WwiseObjectIDext *v4; // rcx
  WwiseObjectIDext *v5; // rdx
  char i; // r8
  WwiseObjectIDext *v7; // r8

  v2 = *((_BYTE *)in_pNode + 83);
  v3 = in_pNode->key;
  v4 = in_rExceptionList->m_pItems;
  v5 = &in_rExceptionList->m_pItems[in_rExceptionList->m_uLength];
  for ( i = (v2 >> 1) & 1; v4 != v5; ++v4 )
  {
    if ( v3 == v4->id && i == v4->bIsBus )
      break;
  }
  v7 = 0i64;
  if ( v4 != v5 )
    v7 = v4;
  return v7 != 0i64;
}

// File Line: 508
// RVA: 0xA721C0
CAkBus *__fastcall CAkParameterNodeBase::GetMixingBus(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase *v1; // rax
  CAkParameterNodeBase *v2; // rcx
  CAkBus *result; // rax

  v1 = this;
  v2 = this->m_pBusOutputNode;
  if ( v2 || (v2 = v1->m_pParentNode) != 0i64 )
    result = (CAkBus *)((__int64 (*)(void))v2->vfptr[7].Category)();
  else
    result = 0i64;
  return result;
}

// File Line: 527
// RVA: 0xA72190
CAkBus *__fastcall CAkParameterNodeBase::GetLimitingBus(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase *v1; // rax
  CAkParameterNodeBase *v2; // rcx
  CAkBus *result; // rax

  v1 = this;
  v2 = this->m_pBusOutputNode;
  if ( v2 || (v2 = v1->m_pParentNode) != 0i64 )
    result = (CAkBus *)((__int64 (*)(void))v2->vfptr[8].__vecDelDtor)();
  else
    result = 0i64;
  return result;
}

// File Line: 546
// RVA: 0xA71E20
CAkParameterNodeBase *__fastcall CAkParameterNodeBase::GetControlBus(CAkParameterNodeBase *this)
{
  if ( this->m_pBusOutputNode )
    return this->m_pBusOutputNode;
  while ( 1 )
  {
    this = this->m_pParentNode;
    if ( !this )
      break;
    if ( this->m_pBusOutputNode )
      return this->m_pBusOutputNode;
  }
  return 0i64;
}

// File Line: 565
// RVA: 0xA73150
__int64 __fastcall CAkParameterNodeBase::PrepareNodeData(unsigned int in_NodeID)
{
  CAkIndexable *v1; // rax
  CAkIndexable *v2; // rbx
  __int64 result; // rax
  unsigned int v4; // edi

  v1 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_NodeID, 0);
  v2 = v1;
  if ( !v1 )
    return 2i64;
  result = ((__int64 (__fastcall *)(CAkIndexable *))v1->vfptr[10].__vecDelDtor)(v1);
  v4 = result;
  if ( (_DWORD)result != 1 )
  {
    v2->vfptr->Release(v2);
    result = v4;
  }
  return result;
}

// File Line: 583
// RVA: 0xA749E0
void __fastcall CAkParameterNodeBase::UnPrepareNodeData(unsigned int in_NodeID)
{
  CAkIndexable *v1; // rax
  CAkIndexable *v2; // rbx

  v1 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_NodeID, 0);
  v2 = v1;
  if ( v1 )
  {
    v1->vfptr[10].AddRef(v1);
    v2->vfptr->Release(v2);
    v2->vfptr->Release(v2);
  }
}

// File Line: 595
// RVA: 0xA714D0
void __fastcall CAkParameterNodeBase::DeleteActivityChunk(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase *v1; // rbx
  CAkParameterNodeBase *v2; // r8
  AkActivityChunk *v3; // r8
  CAkParameterNodeBase **v4; // rax
  __int64 v5; // rdx
  signed __int64 v6; // rcx
  CAkParameterNodeBase *v7; // r8
  AkActivityChunk *v8; // r8
  CAkParameterNodeBase **v9; // rax
  __int64 v10; // rdx
  signed __int64 v11; // rcx
  CAkParameterNodeBase **v12; // rax
  AkActivityChunk *v13; // rdi
  int v14; // esi

  v1 = this;
  if ( this->m_pActivityChunk )
  {
    v2 = this->m_pParentNode;
    if ( v2 )
    {
      v3 = v2->m_pActivityChunk;
      if ( v3 )
      {
        v4 = v3->m_ActiveChildren.m_pItems;
        v5 = v3->m_ActiveChildren.m_uLength;
        v6 = (signed __int64)&v4[v5];
        if ( v4 != (CAkParameterNodeBase **)v6 )
        {
          do
          {
            if ( *v4 == v1 )
              break;
            ++v4;
          }
          while ( v4 != (CAkParameterNodeBase **)v6 );
          if ( v4 != (CAkParameterNodeBase **)v6 )
          {
            if ( (unsigned int)v5 > 1 )
              *v4 = *(CAkParameterNodeBase **)(v6 - 8);
            --v3->m_ActiveChildren.m_uLength;
          }
        }
      }
    }
    v7 = v1->m_pBusOutputNode;
    if ( v7 )
    {
      v8 = v7->m_pActivityChunk;
      if ( v8 )
      {
        v9 = v8->m_ActiveChildren.m_pItems;
        v10 = v8->m_ActiveChildren.m_uLength;
        v11 = (signed __int64)&v9[v10];
        if ( v9 != (CAkParameterNodeBase **)v11 )
        {
          do
          {
            if ( *v9 == v1 )
              break;
            ++v9;
          }
          while ( v9 != (CAkParameterNodeBase **)v11 );
          if ( v9 != (CAkParameterNodeBase **)v11 )
          {
            if ( (unsigned int)v10 > 1 )
              *v9 = *(CAkParameterNodeBase **)(v11 - 8);
            --v8->m_ActiveChildren.m_uLength;
          }
        }
      }
    }
    v12 = (CAkParameterNodeBase **)v1->m_pFeedbackInfo;
    if ( v12 && *v12 )
      CAkParameterNodeBase::UnsetFastActive(*v12, v1);
  }
  v13 = v1->m_pActivityChunk;
  v14 = g_DefaultPoolId;
  if ( v13 )
  {
    AkActivityChunk::~AkActivityChunk(v13);
    AK::MemoryMgr::Free(v14, v13);
  }
  v1->m_pActivityChunk = 0i64;
}

// File Line: 615
// RVA: 0xA718A0
void __fastcall CAkParameterNodeBase::FlushStateTransitions(CAkParameterNodeBase *this)
{
  AkStateGroupChunk *i; // rbx
  char *v2; // rcx
  signed __int64 v3; // rdx
  unsigned __int8 *v4; // rdi
  signed __int64 v5; // rsi
  CAkTransition **v6; // rdi
  signed __int64 v7; // rsi

  for ( i = this->m_states.m_pFirst; i; i = i->m_pNextInNode )
  {
    v2 = i->m_values.m_pProps;
    if ( v2 )
    {
      v3 = (signed __int64)(v2 + 1);
      v4 = (unsigned __int8 *)&v2[((unsigned __int8)*v2 + 4) & 0xFFFFFFFC];
    }
    else
    {
      v3 = 0i64;
      v4 = 0i64;
    }
    if ( v2 )
      v5 = (signed __int64)&v2[(unsigned __int8)*v2 + 1];
    else
      v5 = 0i64;
    if ( v3 != v5 )
    {
      v6 = (CAkTransition **)(v4 + 8);
      v7 = v5 - v3;
      do
      {
        if ( *v6 )
        {
          CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, *v6, (ITransitionable *)&i->vfptr);
          *v6 = 0i64;
          ((void (__fastcall *)(CAkParameterNodeBase *, signed __int64))i->m_pOwner->vfptr[9].Category)(
            i->m_pOwner,
            3i64);
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
__int64 __fastcall CAkParameterNodeBase::OnNewActivityChunk(CAkParameterNodeBase *this, unsigned __int16 in_flagForwardToBus)
{
  unsigned __int8 v2; // bl
  unsigned __int16 v3; // di
  CAkParameterNodeBase *v4; // rsi
  CAkParameterNodeBase *v5; // rbp
  char v6; // al
  AkActivityChunk *v7; // rcx
  CAkParameterNodeBase **v8; // rax
  CAkParameterNodeBase *v9; // rbp
  char v10; // cl
  AkActivityChunk *v11; // rax
  CAkParameterNodeBase *v12; // rbp
  char v13; // cl
  AkActivityChunk *v14; // rax
  __int64 result; // rax

  v2 = 1;
  v3 = in_flagForwardToBus;
  v4 = this;
  if ( in_flagForwardToBus & 1 )
  {
    v5 = this->m_pBusOutputNode;
    if ( v5 )
    {
      v6 = CAkParameterNodeBase::EnableActivityChunk(this->m_pBusOutputNode, 3u);
      v7 = v5->m_pActivityChunk;
      if ( v7 )
        v6 = AkArray<CAkParameterNodeBase *,CAkParameterNodeBase *,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(
               &v7->m_ActiveChildren,
               v4) != 0i64;
      v2 = 1;
      if ( !v6 )
        v2 = 0;
      v3 &= 0xFFFEu;
    }
  }
  if ( v3 & 2 )
  {
    v8 = (CAkParameterNodeBase **)v4->m_pFeedbackInfo;
    if ( v8 )
    {
      v9 = *v8;
      if ( *v8 )
      {
        v10 = CAkParameterNodeBase::EnableActivityChunk(*v8, 3u);
        v11 = v9->m_pActivityChunk;
        if ( v11 )
          v10 = AkArray<CAkParameterNodeBase *,CAkParameterNodeBase *,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(
                  &v11->m_ActiveChildren,
                  v4) != 0i64;
        if ( !v10 )
          v2 = 0;
        v3 &= 0xFFFDu;
      }
    }
  }
  v12 = v4->m_pParentNode;
  if ( !v12 )
    return v2;
  v13 = CAkParameterNodeBase::EnableActivityChunk(v4->m_pParentNode, v3);
  v14 = v12->m_pActivityChunk;
  if ( v14 )
    v13 = AkArray<CAkParameterNodeBase *,CAkParameterNodeBase *,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(
            &v14->m_ActiveChildren,
            v4) != 0i64;
  result = v2;
  if ( !v13 )
    result = 0i64;
  return result;
}

// File Line: 664
// RVA: 0xA74AB0
void __fastcall CAkParameterNodeBase::UnsetFastActive(CAkParameterNodeBase *this, CAkParameterNodeBase *in_pChild)
{
  AkActivityChunk *v2; // r8
  CAkParameterNodeBase **v3; // rax
  __int64 v4; // r9
  signed __int64 v5; // rcx

  v2 = this->m_pActivityChunk;
  if ( v2 )
  {
    v3 = v2->m_ActiveChildren.m_pItems;
    v4 = v2->m_ActiveChildren.m_uLength;
    v5 = (signed __int64)&v3[v4];
    if ( v3 != (CAkParameterNodeBase **)v5 )
    {
      do
      {
        if ( *v3 == in_pChild )
          break;
        ++v3;
      }
      while ( v3 != (CAkParameterNodeBase **)v5 );
      if ( v3 != (CAkParameterNodeBase **)v5 )
      {
        if ( (unsigned int)v4 > 1 )
          *v3 = *(CAkParameterNodeBase **)(v5 - 8);
        --v2->m_ActiveChildren.m_uLength;
      }
    }
  }
}

// File Line: 675
// RVA: 0xA73090
void __fastcall CAkParameterNodeBase::PauseTransitions(CAkParameterNodeBase *this, bool in_bPause)
{
  AkStateGroupChunk *v2; // rbx
  bool i; // bp
  char *v4; // rcx
  signed __int64 v5; // rdx
  unsigned __int8 *v6; // rdi
  signed __int64 v7; // rsi
  CAkTransition **v8; // rdi
  signed __int64 v9; // rsi
  CAkTransition *v10; // rdx

  v2 = this->m_states.m_pFirst;
  for ( i = in_bPause; v2; v2 = v2->m_pNextInNode )
  {
    v4 = v2->m_values.m_pProps;
    if ( v4 )
    {
      v5 = (signed __int64)(v4 + 1);
      v6 = (unsigned __int8 *)&v4[((unsigned __int8)*v4 + 4) & 0xFFFFFFFC];
    }
    else
    {
      v5 = 0i64;
      v6 = 0i64;
    }
    if ( v4 )
      v7 = (signed __int64)&v4[(unsigned __int8)*v4 + 1];
    else
      v7 = 0i64;
    if ( v5 != v7 )
    {
      v8 = (CAkTransition **)(v6 + 8);
      v9 = v7 - v5;
      do
      {
        v10 = *v8;
        if ( *v8 )
        {
          if ( i )
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
void __fastcall CAkParameterNodeBase::StartSISTransition(CAkParameterNodeBase *this, CAkSIS *in_pSIS, AkPropID in_ePropID, float in_fTargetValue, AkValueMeaning in_eValueMeaning, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  CAkParameterNodeBase *v7; // r15
  AkPropBundle<AkStateValue> *v8; // rcx
  __int64 v9; // rbx
  char *v10; // r8
  signed __int64 v11; // rsi
  float v12; // xmm6_4
  CAkSIS *v13; // rbp
  unsigned int v14; // er10
  int v15; // er9
  __int64 v16; // rdx
  signed __int64 v17; // rdi
  AkStateValue *v18; // rax
  CAkTransition *v19; // r11
  char *v20; // r8
  unsigned int v21; // er9
  __int64 v22; // rcx
  __int64 v23; // rdx
  int *v24; // rax
  float v25; // xmm0_4
  float v26; // xmm2_4
  unsigned int v27; // er9
  __int64 v28; // rcx
  __int64 v29; // rdx
  signed __int64 v30; // rdx
  int *v31; // rax
  char v32; // al
  TransitionParameters in_Params; // [rsp+40h] [rbp-68h]
  int v34; // [rsp+B8h] [rbp+10h]

  v7 = this;
  v8 = (AkPropBundle<AkStateValue> *)&in_pSIS->m_values;
  v9 = in_ePropID;
  v10 = in_pSIS->m_values.m_pProps;
  v11 = 0i64;
  v12 = in_fTargetValue;
  v13 = in_pSIS;
  if ( !v10 )
    goto LABEL_7;
  v14 = (unsigned __int8)*v10;
  v15 = 0;
  while ( 1 )
  {
    v16 = (unsigned int)(v15 + 1);
    if ( v10[v16] == (_BYTE)v9 )
      break;
    ++v15;
    if ( (unsigned int)v16 >= v14 )
      goto LABEL_7;
  }
  v17 = (signed __int64)&v10[16 * v15 + ((v14 + 4) & 0xFFFFFFFC)];
  if ( !v17 )
  {
LABEL_7:
    v18 = AkPropBundle<AkStateValue>::AddAkProp(v8, v9);
    v17 = (signed __int64)v18;
    if ( !v18 )
      return;
    v18->fValue = 0.0;
    v18->pTransition = 0i64;
  }
  v19 = *(CAkTransition **)(v17 + 8);
  if ( v19 )
  {
    if ( in_eValueMeaning == 1 )
    {
      v20 = v7->m_props.m_pProps;
      v34 = g_AkPropDefault[v9].iValue;
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
        v11 = (signed __int64)&v20[4 * v22 + ((v21 + 4) & 0xFFFFFFFC)];
      }
LABEL_17:
      v24 = &v34;
      if ( v11 )
        v24 = (int *)v11;
      v34 = *v24;
      v12 = in_fTargetValue - *(float *)&v34;
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
    if ( in_eValueMeaning == 1 )
    {
      v10 = v7->m_props.m_pProps;
      v34 = g_AkPropDefault[v9].iValue;
      if ( v10 )
      {
        v27 = (unsigned __int8)*v10;
        v28 = 0i64;
        while ( 1 )
        {
          v29 = (unsigned int)(v28 + 1);
          if ( v10[v29] == (_BYTE)v9 )
            break;
          v28 = (unsigned int)v29;
          if ( (unsigned int)v29 >= v27 )
            goto LABEL_28;
        }
        v30 = (signed __int64)&v10[4 * v28 + ((v27 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_28:
        v30 = 0i64;
      }
      v31 = &v34;
      if ( v30 )
        v31 = (int *)v30;
      v34 = *v31;
      v26 = in_fTargetValue - *(float *)&v34;
    }
    else if ( in_eValueMeaning == 2 )
    {
      v26 = v25 + in_fTargetValue;
    }
    if ( v25 != v26 && in_lTransitionTime )
    {
      in_Params.lDuration = in_lTransitionTime;
      in_Params.fStartValue = v25;
      in_Params.fTargetValue = v26;
      in_Params.eFadeCurve = in_eFadeCurve;
      v32 = *(_BYTE *)(v9 + 5396108840i64);
      LOBYTE(v10) = 1;
      in_Params.pUser = (ITransitionable *)&v13->vfptr;
      in_Params.bdBs = v32;
      in_Params.eTarget = v9;
      in_Params.bUseReciprocalCurve = 1;
      *(_QWORD *)(v17 + 8) = CAkTransitionManager::AddTransitionToList(
                               g_pTransitionManager,
                               &in_Params,
                               (__int64)v10,
                               0i64);
    }
    else
    {
      *(float *)v17 = v26;
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkIndexableVtbl *, CAkRegisteredObj *, _QWORD))v7->vfptr[5].Release)(
        v7,
        (unsigned int)g_AkPropRTPCID[v9],
        v7->vfptr,
        v13->m_pGameObj,
        0i64);
    }
  }
}

// File Line: 792
// RVA: 0xA747B0
void __fastcall CAkParameterNodeBase::StartSisMuteTransitions(CAkParameterNodeBase *this, CAkSIS *in_pSIS, float in_fTargetValue, __int64 in_eFadeCurve, int in_lTransitionTime)
{
  char *v5; // r10
  AkCurveInterpolation in_eCurveType; // ebp
  CAkSIS *v7; // rdi
  unsigned int v8; // er11
  int v9; // ecx
  __int64 v10; // r8
  signed __int64 v11; // rbx
  AkStateValue *v12; // rax
  CAkTransition *v13; // rdx
  float v14; // xmm0_4
  TransitionParameters in_Params; // [rsp+40h] [rbp-48h]

  v5 = in_pSIS->m_values.m_pProps;
  in_eCurveType = (signed int)in_eFadeCurve;
  v7 = in_pSIS;
  if ( !v5 )
    goto LABEL_7;
  v8 = (unsigned __int8)*v5;
  v9 = 0;
  while ( 1 )
  {
    v10 = (unsigned int)(v9 + 1);
    if ( v5[v10] == 10 )
      break;
    ++v9;
    if ( (unsigned int)v10 >= v8 )
      goto LABEL_7;
  }
  v11 = (signed __int64)&v5[16 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
  if ( !v11 )
  {
LABEL_7:
    v12 = AkPropBundle<AkStateValue>::AddAkProp((AkPropBundle<AkStateValue> *)&in_pSIS->m_values, 10);
    v11 = (signed __int64)v12;
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
      0);
  }
  else if ( in_lTransitionTime )
  {
    v14 = *(float *)v11;
    LOBYTE(v10) = 1;
    in_Params.fTargetValue = in_fTargetValue;
    in_Params.fStartValue = v14;
    in_Params.pUser = (ITransitionable *)&v7->vfptr;
    in_Params.eTarget = 10i64;
    in_Params.lDuration = in_lTransitionTime;
    in_Params.eFadeCurve = in_eCurveType;
    *(_WORD *)&in_Params.bdBs = 256;
    *(_QWORD *)(v11 + 8) = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, v10, 0i64);
  }
  else
  {
    LOBYTE(in_eFadeCurve) = 1;
    ((void (__fastcall *)(CAkSIS *, signed __int64, __int64, __int64))v7->vfptr->TransUpdateValue)(
      v7,
      10i64,
      v10,
      in_eFadeCurve);
  }
}

// File Line: 839
// RVA: 0xA73B10
signed __int64 __fastcall CAkParameterNodeBase::SetFX(CAkParameterNodeBase *this, unsigned int in_uFXIndex, unsigned int in_uID, bool in_bShareSet)
{
  bool v4; // bp
  unsigned int v5; // esi
  __int64 v6; // rdi
  CAkParameterNodeBase *v7; // rbx
  CAkParameterNodeBase::FXChunk *v9; // rcx
  CAkParameterNodeBase::FXChunk *v10; // rax

  v4 = in_bShareSet;
  v5 = in_uID;
  v6 = in_uFXIndex;
  v7 = this;
  if ( in_uFXIndex >= 4 )
    return 31i64;
  v9 = this->m_pFXChunk;
  if ( !v9 )
  {
    v10 = (CAkParameterNodeBase::FXChunk *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x24ui64);
    v7->m_pFXChunk = v10;
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
    v9 = v7->m_pFXChunk;
    if ( !v9 )
      return 52i64;
  }
  if ( v9->aFX[v6].bShareSet != v4 || v9->aFX[v6].id != v5 )
  {
    v9->aFX[v6].bShareSet = v4;
    v9->aFX[v6].id = v5;
    v7->vfptr[12].Category((CAkIndexable *)&v7->vfptr);
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))v7->vfptr[8].AddRef)(v7, (unsigned int)v6);
  }
  return 1i64;
}

// File Line: 880
// RVA: 0xA73550
signed __int64 __fastcall CAkParameterNodeBase::RemoveFX(CAkParameterNodeBase *this, unsigned int in_uFXIndex)
{
  unsigned int v2; // edi
  CAkParameterNodeBase *v3; // rbx
  CAkParameterNodeBase::FXChunk *v5; // rcx

  v2 = in_uFXIndex;
  v3 = this;
  if ( in_uFXIndex >= 4 )
    return 31i64;
  v5 = this->m_pFXChunk;
  if ( !v5 )
    return 2i64;
  if ( v5->aFX[in_uFXIndex].bShareSet || v5->aFX[in_uFXIndex].id )
  {
    v5->aFX[in_uFXIndex].bShareSet = 0;
    v5->aFX[in_uFXIndex].id = 0;
    v3->vfptr[12].Category((CAkIndexable *)&v3->vfptr);
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))v3->vfptr[8].AddRef)(v3, v2);
  }
  return 1i64;
}

// File Line: 988
// RVA: 0xA737A0
signed __int64 __fastcall CAkParameterNodeBase::RenderedFX(CAkParameterNodeBase *this, unsigned int in_uFXIndex, bool in_bRendered)
{
  CAkParameterNodeBase *v3; // rbx
  CAkParameterNodeBase::FXChunk *v4; // rcx
  bool v5; // di
  __int64 v6; // rsi
  CAkParameterNodeBase::FXChunk *v7; // rax

  v3 = this;
  v4 = this->m_pFXChunk;
  v5 = in_bRendered;
  v6 = in_uFXIndex;
  if ( v4 )
  {
LABEL_7:
    v4->aFX[v6].bRendered = v5;
    if ( v5 )
    {
      if ( v3->m_pFXChunk->aFX[v6].id )
        CAkParameterNodeBase::RemoveFX(v3, v6);
    }
    return 1i64;
  }
  if ( in_bRendered )
  {
    v7 = (CAkParameterNodeBase::FXChunk *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x24ui64);
    v3->m_pFXChunk = v7;
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
    v4 = v3->m_pFXChunk;
    if ( !v4 )
      return 52i64;
    goto LABEL_7;
  }
  return 1i64;
}

// File Line: 1019
// RVA: 0xA72BA0
signed __int64 __fastcall CAkParameterNodeBase::MainBypassFX(CAkParameterNodeBase *this, unsigned int in_bitsFXBypass, unsigned int in_uTargetMask)
{
  unsigned int v3; // esi
  unsigned int v4; // edi
  CAkParameterNodeBase *v5; // rbx
  CAkParameterNodeBase::FXChunk *v6; // rdx
  CAkParameterNodeBase::FXChunk *v7; // rax

  v3 = in_uTargetMask;
  v4 = in_bitsFXBypass;
  v5 = this;
  if ( ((unsigned int (*)(void))this->vfptr[3].Release)() )
    v5->vfptr[3].Release((CAkIndexable *)&v5->vfptr);
  v6 = v5->m_pFXChunk;
  if ( v6 )
  {
LABEL_9:
    v6->bitsMainFXBypass = v3 & v4 | v6->bitsMainFXBypass & ~(_BYTE)v3;
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD))v5->vfptr[13].Category)(v5, v4, v3);
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, _QWORD, _QWORD))v5->vfptr[6].Category)(
      v5,
      v4,
      v3,
      0i64,
      0i64);
    return 1i64;
  }
  if ( v4 )
  {
    v7 = (CAkParameterNodeBase::FXChunk *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x24ui64);
    v5->m_pFXChunk = v7;
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
    v6 = v5->m_pFXChunk;
    if ( !v6 )
      return 52i64;
    goto LABEL_9;
  }
  return 1i64;
}

// File Line: 1057
// RVA: 0xA70E60
void __fastcall CAkParameterNodeBase::BypassFX(CAkParameterNodeBase *this, unsigned int in_bitsFXBypass, unsigned int in_uTargetMask, CAkRegisteredObj *in_pGameObj, bool in_bIsFromReset)
{
  unsigned int v5; // esi
  CAkRegisteredObj *v6; // rbp
  unsigned int v7; // edi
  CAkParameterNodeBase *v8; // rbx
  _BYTE *v9; // rax

  v5 = in_bitsFXBypass;
  v6 = in_pGameObj;
  v7 = in_uTargetMask;
  v8 = this;
  v9 = (_BYTE *)this->vfptr[19].__vecDelDtor((CAkIndexable *)this, (unsigned int)in_pGameObj);
  if ( v9 )
    v9[32] = v7 & v5 | v9[32] & ~(_BYTE)v7;
  if ( v8->vfptr[3].Release((CAkIndexable *)&v8->vfptr) )
    v8->vfptr[3].Release((CAkIndexable *)&v8->vfptr);
  if ( !v6 )
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD))v8->vfptr[13].Category)(v8, v5, v7);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, CAkRegisteredObj *, _QWORD))v8->vfptr[6].Category)(
    v8,
    v5,
    v7,
    v6,
    0i64);
}

// File Line: 1091
// RVA: 0xA73860
void __fastcall CAkParameterNodeBase::ResetBypassFX(CAkParameterNodeBase *this, unsigned int in_uTargetMask, CAkRegisteredObj *in_pGameObj)
{
  CAkParameterNodeBase::FXChunk *v3; // rax
  unsigned int v4; // er10
  unsigned int v5; // edx

  v3 = this->m_pFXChunk;
  v4 = in_uTargetMask;
  if ( v3 )
    v5 = (unsigned __int8)v3->bitsMainFXBypass;
  else
    v5 = 0;
  CAkParameterNodeBase::BypassFX(this, v5, v4, in_pGameObj, 1);
}

// File Line: 1100
// RVA: 0xA70C80
AkStateGroupChunk *__fastcall CAkParameterNodeBase::AddStateGroup(CAkParameterNodeBase *this, unsigned int in_ulStateGroupID, bool in_bNotify)
{
  AkStateGroupChunk *result; // rax
  bool v4; // bp
  unsigned int v5; // esi
  CAkParameterNodeBase *v6; // rdi
  AkStateGroupChunk *v7; // rbx
  int v8; // edi
  MapStruct<unsigned long,AkStateLink> *v9; // rdx
  char *v10; // rdx
  AkStateGroupChunk *v11; // rax

  result = this->m_states.m_pFirst;
  v4 = in_bNotify;
  v5 = in_ulStateGroupID;
  v6 = this;
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
      result->m_pOwner = v6;
      result->m_pNextInGroup = 0i64;
      result->m_pNextInNode = 0i64;
      result->vfptr = (ITransitionableVtbl *)&AkStateGroupChunk::`vftable;
      result->m_values.m_pProps = 0i64;
      result->m_mapStates.m_pItems = 0i64;
      *(_QWORD *)&result->m_mapStates.m_uLength = 0i64;
      result->m_ulStateGroup = v5;
      result->m_ulActualState = 0;
      result->m_eStateSyncType = 0;
      if ( (unsigned int)CAkStateMgr::AddStateGroupMember(g_pStateMgr, v5, result) == 1 )
      {
        v11 = v6->m_states.m_pFirst;
        if ( v11 )
        {
          v7->m_pNextInNode = v11;
          v6->m_states.m_pFirst = v7;
        }
        else
        {
          v6->m_states.m_pFirst = v7;
          v7->m_pNextInNode = 0i64;
        }
        v7->m_ulActualState = CAkStateMgr::GetState(g_pStateMgr, v5);
        if ( v4 )
          ((void (__fastcall *)(CAkParameterNodeBase *))v6->vfptr[13].__vecDelDtor)(v6);
        result = v7;
      }
      else
      {
        v8 = g_DefaultPoolId;
        v7->vfptr = (ITransitionableVtbl *)&AkStateGroupChunk::`vftable;
        v9 = v7->m_mapStates.m_pItems;
        if ( v9 )
        {
          v7->m_mapStates.m_uLength = 0;
          AK::MemoryMgr::Free(g_DefaultPoolId, v9);
          v7->m_mapStates.m_pItems = 0i64;
          v7->m_mapStates.m_ulReserved = 0;
        }
        v10 = v7->m_values.m_pProps;
        if ( v10 )
          AK::MemoryMgr::Free(g_DefaultPoolId, v10);
        v7->m_values.m_pProps = 0i64;
        AK::MemoryMgr::Free(v8, v7);
        result = 0i64;
      }
    }
  }
  return result;
}

// File Line: 1151
// RVA: 0xA736A0
void __fastcall CAkParameterNodeBase::RemoveStateGroups(CAkParameterNodeBase *this, bool in_bNotify)
{
  AkStateGroupChunk *v2; // rbx
  bool v3; // bp
  CAkParameterNodeBase *v4; // rdi
  int v5; // esi
  MapStruct<unsigned long,AkStateLink> *v6; // rdx
  char *v7; // rdx

  v2 = this->m_states.m_pFirst;
  v3 = in_bNotify;
  v4 = this;
  if ( v2 )
  {
    if ( !v2 )
      goto LABEL_4;
    do
    {
      v4->m_states.m_pFirst = v2->m_pNextInNode;
LABEL_4:
      CAkStateMgr::RemoveStateGroupMember(g_pStateMgr, v2->m_ulStateGroup, v2);
      while ( v2->m_mapStates.m_uLength > 0 )
        AkStateGroupChunk::RemoveState(v2, v2->m_mapStates.m_pItems->key);
      v5 = g_DefaultPoolId;
      v2->vfptr = (ITransitionableVtbl *)&AkStateGroupChunk::`vftable;
      v6 = v2->m_mapStates.m_pItems;
      if ( v6 )
      {
        v2->m_mapStates.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v6);
        v2->m_mapStates.m_pItems = 0i64;
        v2->m_mapStates.m_ulReserved = 0;
      }
      v7 = v2->m_values.m_pProps;
      if ( v7 )
        AK::MemoryMgr::Free(g_DefaultPoolId, v7);
      v2->m_values.m_pProps = 0i64;
      AK::MemoryMgr::Free(v5, v2);
      v2 = v4->m_states.m_pFirst;
    }
    while ( v2 );
    if ( v3 )
      ((void (__fastcall *)(CAkParameterNodeBase *))v4->vfptr[13].__vecDelDtor)(v4);
  }
}

// File Line: 1191
// RVA: 0xA74D40
void __fastcall CAkParameterNodeBase::UseState(CAkParameterNodeBase *this, bool in_bUseState)
{
  CAkIndexableVtbl *v2; // rax

  *((_BYTE *)this + 82) &= 0x7Fu;
  v2 = this->vfptr;
  *((_BYTE *)this + 82) |= in_bUseState << 7;
  ((void (*)(void))v2[13].__vecDelDtor)();
}

// File Line: 1326
// RVA: 0xA72D00
void __fastcall CAkParameterNodeBase::NotifyStateParametersModified(CAkParameterNodeBase *this)
{
  AkStateGroupChunk *v1; // rbx
  CAkParameterNodeBase *i; // r15
  MapStruct<unsigned long,AkStateLink> *v3; // rax
  signed __int64 v4; // rcx
  signed __int64 v5; // rax
  unsigned __int8 *v6; // rcx
  char *v7; // rdi
  float *v8; // rsi
  signed __int64 v9; // rbp
  char *v10; // r8
  float v11; // xmm6_4
  unsigned int v12; // er9
  unsigned __int8 v13; // r10
  int v14; // ecx
  __int64 v15; // rdx
  AkStateValue *v16; // rax
  signed __int64 v17; // r9
  CAkTransition *v18; // rdx
  char *v19; // rdx
  signed __int64 v20; // r8
  unsigned __int8 *v21; // rcx
  signed __int64 v22; // rdx
  signed __int64 v23; // rdx

  v1 = this->m_states.m_pFirst;
  for ( i = this; v1; v1 = v1->m_pNextInNode )
  {
    v3 = v1->m_mapStates.m_pItems;
    v4 = (signed __int64)&v3[v1->m_mapStates.m_uLength];
    if ( v3 == (MapStruct<unsigned long,AkStateLink> *)v4 )
      goto LABEL_40;
    do
    {
      if ( v3->key == v1->m_ulActualState )
        break;
      ++v3;
    }
    while ( v3 != (MapStruct<unsigned long,AkStateLink> *)v4 );
    if ( v3 != (MapStruct<unsigned long,AkStateLink> *)v4 && (v5 = (signed __int64)&v3->item) != 0 && *(_QWORD *)v5 )
    {
      v6 = *(unsigned __int8 **)(*(_QWORD *)v5 + 24i64);
      if ( v6 )
      {
        v7 = (char *)(v6 + 1);
        v8 = (float *)&v6[(*v6 + 4) & 0xFFFFFFFC];
      }
      else
      {
        v7 = 0i64;
        v8 = 0i64;
      }
      if ( v6 )
        v9 = (signed __int64)&v6[*v6 + 1];
      else
        v9 = 0i64;
      for ( ; v7 != (char *)v9; ++v8 )
      {
        v10 = v1->m_values.m_pProps;
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
        v17 = (signed __int64)&v10[16 * v14 + ((v12 + 4) & 0xFFFFFFFC)];
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
              0);
          else
            *(float *)v17 = v11;
        }
        else
        {
LABEL_19:
          v16 = AkPropBundle<AkStateValue>::AddAkProp(&v1->m_values, *v7);
          if ( v16 )
          {
            v16->fValue = v11;
            v16->pTransition = 0i64;
          }
        }
        ++v7;
      }
    }
    else
    {
LABEL_40:
      AkStateGroupChunk::FlushStateTransitions(v1);
      v19 = v1->m_values.m_pProps;
      if ( v19 )
      {
        v20 = (signed __int64)(v19 + 1);
        v21 = (unsigned __int8 *)&v19[((unsigned __int8)*v19 + 4) & 0xFFFFFFFC];
      }
      else
      {
        v20 = 0i64;
        v21 = 0i64;
      }
      if ( v19 )
        v22 = (signed __int64)&v19[(unsigned __int8)*v19 + 1];
      else
        v22 = 0i64;
      if ( v20 != v22 )
      {
        v23 = v22 - v20;
        do
        {
          *(_DWORD *)v21 = 0;
          v21 += 16;
          --v23;
        }
        while ( v23 );
      }
    }
  }
  i->vfptr[12].Category((CAkIndexable *)&i->vfptr);
}

// File Line: 1380
// RVA: 0xA73D30
void __fastcall CAkParameterNodeBase::SetMaxReachedBehavior(CAkParameterNodeBase *this, bool in_bKillNewest)
{
  CAkParameterNodeBase *v2; // rdi
  char v3; // cl
  char v4; // al
  AkActivityChunk *v5; // rcx
  signed __int64 v6; // rcx
  bool v7; // al
  AkActivityChunk *v8; // rdx
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v9; // rbx
  CAkLimiter *v10; // rcx
  bool v11; // al

  v2 = this;
  v3 = *((_BYTE *)this + 82);
  if ( (v3 & 1) != in_bKillNewest )
  {
    v4 = v3 ^ (in_bKillNewest ^ v3) & 1;
    v5 = v2->m_pActivityChunk;
    *((_BYTE *)v2 + 82) = v4;
    if ( v5 )
    {
      v6 = (signed __int64)&v5->m_Limiter;
      v7 = *(_BYTE *)(v6 + 18) == 0;
      *(_BYTE *)(v6 + 18) = v7;
      if ( v7 )
        AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::ReSortArray<AkPriorityStruct_INC>((AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8> *)v6);
      else
        AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::ReSortArray<AkPriorityStruct_DEC>((AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8> *)v6);
      v8 = v2->m_pActivityChunk;
      v9 = v8->m_ListPlayCountPerObj.m_pItems;
      if ( v8->m_ListPlayCountPerObj.m_pItems != &v8->m_ListPlayCountPerObj.m_pItems[v8->m_ListPlayCountPerObj.m_uLength] )
      {
        do
        {
          v10 = v9->item.m_pLimiter;
          if ( v10 )
          {
            v11 = v10->m_bDoesKillNewest == 0;
            v10->m_bDoesKillNewest = v11;
            if ( v11 )
              AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::ReSortArray<AkPriorityStruct_INC>(&v10->m_sortedPBIList);
            else
              AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::ReSortArray<AkPriorityStruct_DEC>(&v10->m_sortedPBIList);
          }
          ++v9;
        }
        while ( v9 != &v2->m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[v2->m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] );
      }
    }
  }
}

// File Line: 1398
// RVA: 0xA74020
void __fastcall CAkParameterNodeBase::SetOverLimitBehavior(CAkParameterNodeBase *this, bool in_bUseVirtualBehavior)
{
  CAkParameterNodeBase *v2; // r10
  unsigned __int8 v3; // cl
  AkActivityChunk *v4; // rax
  AkActivityChunk *v5; // r8
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v6; // rax
  CAkLimiter *v7; // rcx

  v2 = this;
  v3 = *((_BYTE *)this + 82);
  if ( ((v3 >> 1) & 1) != in_bUseVirtualBehavior )
  {
    *((_BYTE *)v2 + 82) = v3 ^ (v3 ^ 2 * in_bUseVirtualBehavior) & 2;
    v4 = v2->m_pActivityChunk;
    if ( v4 )
    {
      v4->m_Limiter.m_bAllowUseVirtualBehavior = in_bUseVirtualBehavior;
      v5 = v2->m_pActivityChunk;
      v6 = v5->m_ListPlayCountPerObj.m_pItems;
      if ( v5->m_ListPlayCountPerObj.m_pItems != &v5->m_ListPlayCountPerObj.m_pItems[v5->m_ListPlayCountPerObj.m_uLength] )
      {
        do
        {
          v7 = v6->item.m_pLimiter;
          if ( v7 )
            v7->m_bAllowUseVirtualBehavior = in_bUseVirtualBehavior;
          ++v6;
        }
        while ( v6 != &v2->m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[v2->m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] );
      }
    }
  }
}

// File Line: 1429
// RVA: 0xA73D20
void __fastcall CAkParameterNodeBase::SetMaxNumInstOverrideParent(CAkParameterNodeBase *this, bool in_bOverride)
{
  *((_BYTE *)this + 82) &= 0xF7u;
  *((_BYTE *)this + 82) |= 8 * in_bOverride;
}

// File Line: 1434
// RVA: 0xA74510
void __fastcall CAkParameterNodeBase::SetVVoicesOptOverrideParent(CAkParameterNodeBase *this, bool in_bOverride)
{
  *((_BYTE *)this + 82) &= 0xFBu;
  *((_BYTE *)this + 82) |= 4 * in_bOverride;
}

// File Line: 1439
// RVA: 0xA721F0
PriorityInfo *__fastcall CAkParameterNodeBase::GetPriority(CAkParameterNodeBase *this, PriorityInfo *result, CAkRegisteredObj *in_GameObjPtr)
{
  CAkParameterNodeBase *v3; // rbx
  CAkParameterNodeBase *v4; // rcx
  PriorityInfo *v5; // rsi
  PriorityInfo *v6; // rax
  __int64 v7; // rax
  signed __int64 v8; // rdi
  char *v9; // r8
  unsigned int v10; // er9
  __int64 v11; // rcx
  __int64 v12; // rdx
  signed __int64 v13; // rdx
  int *v14; // rax
  char *v15; // r8
  unsigned int v16; // er9
  __int64 v17; // rcx
  __int64 v18; // rdx
  int *v19; // rax
  int v20; // [rsp+40h] [rbp+8h]
  PriorityInfo v21; // [rsp+58h] [rbp+20h]

  v3 = this;
  v4 = this->m_pParentNode;
  v5 = result;
  if ( !v4 || *((_BYTE *)v3 + 82) & 0x40 )
  {
    v7 = LODWORD(v3->m_RTPCBitArray.m_iBitArray);
    v8 = 0i64;
    v21 = (PriorityInfo)LODWORD(FLOAT_50_0);
    if ( _bittest64(&v7, 8u) )
    {
      v21.priority = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v3, 8u, in_GameObjPtr);
    }
    else
    {
      v9 = v3->m_props.m_pProps;
      v20 = g_AkPropDefault[5].iValue;
      if ( v9 )
      {
        v10 = (unsigned __int8)*v9;
        v11 = 0i64;
        while ( 1 )
        {
          v12 = (unsigned int)(v11 + 1);
          if ( v9[v12] == 5 )
            break;
          v11 = (unsigned int)v12;
          if ( (unsigned int)v12 >= v10 )
            goto LABEL_10;
        }
        v13 = (signed __int64)&v9[4 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_10:
        v13 = 0i64;
      }
      v14 = &v20;
      if ( v13 )
        v14 = (int *)v13;
      LODWORD(v21.priority) = *v14;
    }
    if ( *((_BYTE *)v3 + 82) & 0x20 )
    {
      v15 = v3->m_props.m_pProps;
      v20 = g_AkPropDefault[6].iValue;
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
        v8 = (signed __int64)&v15[4 * v17 + ((v16 + 4) & 0xFFFFFFFC)];
      }
LABEL_22:
      v19 = &v20;
      if ( v8 )
        v19 = (int *)v8;
      LODWORD(v21.distanceOffset) = *v19;
    }
    else
    {
      v21.distanceOffset = 0.0;
    }
    *v5 = v21;
    v6 = v5;
  }
  else
  {
    CAkParameterNodeBase::GetPriority(v4, result, in_GameObjPtr);
    v6 = v5;
  }
  return v6;
}

// File Line: 1452
// RVA: 0xA73A60
void __fastcall CAkParameterNodeBase::SetAkProp(CAkParameterNodeBase *this, AkPropID in_eProp, float in_fValue, float __formal)
{
  CAkParameterNodeBase *v4; // rbx
  char *v5; // r9
  signed __int64 v6; // r11
  unsigned int v7; // er10
  int v8; // er8
  __int64 v9; // rcx
  AkPropValue *v10; // rax
  AkPropValue in_Value; // [rsp+38h] [rbp+10h]

  v4 = this;
  v5 = this->m_props.m_pProps;
  v6 = 0i64;
  LODWORD(in_Value.fValue) = g_AkPropDefault[in_eProp];
  if ( v5 )
  {
    v7 = (unsigned __int8)*v5;
    v8 = 0;
    while ( 1 )
    {
      v9 = (unsigned int)(v8 + 1);
      if ( v5[v9] == (_BYTE)in_eProp )
        break;
      ++v8;
      if ( (unsigned int)v9 >= v7 )
        goto LABEL_7;
    }
    v6 = (signed __int64)&v5[4 * v8 + ((v7 + 4) & 0xFFFFFFFC)];
  }
LABEL_7:
  v10 = &in_Value;
  if ( v6 )
    v10 = (AkPropValue *)v6;
  in_Value.fValue = v10->fValue;
  if ( in_Value.fValue != in_fValue )
  {
    in_Value.fValue = in_fValue;
    AkPropBundle<AkPropValue>::SetAkProp(&v4->m_props, in_eProp, LODWORD(in_fValue));
    v4->vfptr[12].Category((CAkIndexable *)&v4->vfptr);
  }
}

// File Line: 1462
// RVA: 0xA739B0
void __fastcall CAkParameterNodeBase::SetAkProp(CAkParameterNodeBase *this, AkPropID in_eProp, int in_iValue, int __formal)
{
  CAkParameterNodeBase *v4; // rbx
  char *v5; // r10
  signed __int64 v6; // r11
  int v7; // edi
  unsigned int v8; // er8
  int v9; // er9
  __int64 v10; // rcx
  int *v11; // rax
  int v12; // [rsp+38h] [rbp+10h]

  v4 = this;
  v5 = this->m_props.m_pProps;
  v6 = 0i64;
  v12 = g_AkPropDefault[in_eProp].iValue;
  v7 = in_iValue;
  if ( v5 )
  {
    v8 = (unsigned __int8)*v5;
    v9 = 0;
    while ( 1 )
    {
      v10 = (unsigned int)(v9 + 1);
      if ( v5[v10] == (_BYTE)in_eProp )
        break;
      ++v9;
      if ( (unsigned int)v10 >= v8 )
        goto LABEL_7;
    }
    v6 = (signed __int64)&v5[4 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
  }
LABEL_7:
  v11 = &v12;
  if ( v6 )
    v11 = (int *)v6;
  if ( *v11 != v7 )
  {
    AkPropBundle<AkPropValue>::SetAkProp(&v4->m_props, in_eProp, (AkPropValue)v7);
    v4->vfptr[12].Category((CAkIndexable *)&v4->vfptr);
  }
}

// File Line: 1472
// RVA: 0xA717B0
AkPropValue *__fastcall CAkParameterNodeBase::FindCustomProp(CAkParameterNodeBase *this, unsigned int in_uPropID)
{
  char *v2; // r8
  unsigned int v3; // er10
  __int64 v4; // rcx
  char v5; // r9
  __int64 v6; // rdx

  v2 = this->m_props.m_pProps;
  if ( !v2 )
    return 0i64;
  v3 = (unsigned __int8)*v2;
  v4 = 0i64;
  v5 = in_uPropID + 45;
  while ( 1 )
  {
    v6 = (unsigned int)(v4 + 1);
    if ( v2[v6] == v5 )
      break;
    v4 = (unsigned int)v6;
    if ( (unsigned int)v6 >= v3 )
      return 0i64;
  }
  return (AkPropValue *)&v2[4 * v4 + ((v3 + 4) & 0xFFFFFFFC)];
}

// File Line: 1530
// RVA: 0xA732C0
signed __int64 __fastcall CAkParameterNodeBase::ReadStateChunk(CAkParameterNodeBase *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  int v3; // er14
  unsigned int **v4; // rdi
  unsigned int v5; // er15
  CAkParameterNodeBase *v6; // r12
  unsigned int v7; // edx
  AkStateGroupChunk *v8; // rax
  AkStateGroupChunk *v9; // rbp
  int v10; // ebx
  char v11; // dl
  unsigned int v12; // edx
  unsigned int v13; // esi
  unsigned int v14; // er8
  unsigned int *v15; // rax
  unsigned int v16; // edx
  signed __int64 result; // rax

  v3 = 0;
  v4 = (unsigned int **)io_rpData;
  v5 = *(_DWORD *)*io_rpData;
  v6 = this;
  *io_rpData += 4;
  if ( !v5 )
    return 1i64;
  while ( 1 )
  {
    v7 = **v4;
    ++*v4;
    v8 = CAkParameterNodeBase::AddStateGroup(v6, v7, 1);
    v9 = v8;
    if ( !v8 )
      return 2i64;
    v10 = 0;
    v11 = *(_BYTE *)*v4;
    *v4 = (unsigned int *)((char *)*v4 + 1);
    v8->m_eStateSyncType = v11;
    v12 = *(unsigned __int16 *)*v4;
    *v4 = (unsigned int *)((char *)*v4 + 2);
    v13 = v12;
    if ( v12 )
      break;
LABEL_6:
    if ( ++v3 >= v5 )
      return 1i64;
  }
  while ( 1 )
  {
    v14 = **v4;
    v15 = *v4 + 1;
    *v4 = v15;
    v16 = *v15;
    *v4 = v15 + 1;
    result = AkStateGroupChunk::AddState(v9, v16, v14, 1);
    if ( (_DWORD)result != 1 )
      return result;
    if ( ++v10 >= v13 )
      goto LABEL_6;
  }
}

// File Line: 1562
// RVA: 0xA73DF0
__int64 __fastcall CAkParameterNodeBase::SetNodeBaseParams(CAkParameterNodeBase *this, char **io_rpData, unsigned int *io_rulDataSize, bool in_bPartialLoadOnly)
{
  bool v4; // r14
  unsigned int *v5; // rbp
  unsigned int **v6; // rsi
  CAkParameterNodeBase *v7; // rdi
  __int64 result; // rax
  unsigned int v9; // ebx
  unsigned int v10; // edx
  CAkIndexable *v11; // r14
  unsigned int v12; // edx
  CAkParameterNodeBase *v13; // rax
  CAkParameterNodeBase *v14; // r14
  signed __int64 v15; // rax
  char v16; // cl
  char v17; // r14
  unsigned __int8 v18; // dl
  char v19; // cl
  CAkIndexableVtbl *v20; // rax
  unsigned __int8 v21; // dl
  CAkIndexableVtbl *v22; // rax

  v4 = in_bPartialLoadOnly;
  v5 = io_rulDataSize;
  v6 = (unsigned int **)io_rpData;
  v7 = this;
  result = ((__int64 (*)(void))this->vfptr[18].__vecDelDtor)();
  v9 = result;
  if ( (_DWORD)result == 1 && !v4 )
  {
    v10 = **v6;
    ++*v6;
    if ( v10 )
    {
      v11 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v10, AkNodeType_Bus);
      if ( v11 )
      {
        v7->vfptr->AddRef((CAkIndexable *)&v7->vfptr);
        v9 = ((__int64 (__fastcall *)(CAkIndexable *, CAkParameterNodeBase *))v11->vfptr[2].AddRef)(v11, v7);
        v11->vfptr->Release(v11);
        if ( v9 == 1 )
          goto LABEL_6;
      }
      else
      {
        v9 = 2;
      }
      return v9;
    }
LABEL_6:
    v12 = **v6;
    ++*v6;
    if ( !v12
      || (v13 = (CAkParameterNodeBase *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v12, 0), (v14 = v13) == 0i64)
      || (v9 = CAkParameterNodeBase::AddChildByPtr(v13, v7), v14->vfptr->Release((CAkIndexable *)&v14->vfptr), v9 == 1) )
    {
      v15 = (signed __int64)*v6 + 1;
      v16 = *(_BYTE *)*v6;
      *v6 = (unsigned int *)v15++;
      v17 = *(_BYTE *)(v15 - 1);
      *v6 = (unsigned int *)v15;
      v18 = *((_BYTE *)v7 + 82);
      v19 = v16 != 0;
      if ( ((v18 >> 6) & 1) != v19 )
      {
        v20 = v7->vfptr;
        *((_BYTE *)v7 + 82) = v18 ^ (v18 ^ (v19 << 6)) & 0x40;
        v20[12].Category((CAkIndexable *)&v7->vfptr);
      }
      v21 = *((_BYTE *)v7 + 82);
      if ( ((v21 >> 5) & 1) != (v17 != 0) )
      {
        v22 = v7->vfptr;
        *((_BYTE *)v7 + 82) = v21 ^ (v21 ^ 32 * (v17 != 0)) & 0x20;
        v22[12].Category((CAkIndexable *)&v7->vfptr);
      }
      if ( v9 == 1 )
      {
        v9 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, unsigned int **, unsigned int *))v7->vfptr[17].Category)(
               v7,
               v6,
               v5);
        if ( v9 == 1 )
        {
          v9 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, unsigned int **, unsigned int *))v7->vfptr[18].AddRef)(
                 v7,
                 v6,
                 v5);
          if ( v9 == 1 )
          {
            v9 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, unsigned int **, unsigned int *))v7->vfptr[18].Release)(
                   v7,
                   v6,
                   v5);
            if ( v9 == 1 )
            {
              v9 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, unsigned int **, unsigned int *))v7->vfptr[18].Category)(
                     v7,
                     v6,
                     v5);
              if ( v9 == 1 )
              {
                v9 = CAkParameterNodeBase::ReadStateChunk(v7, (char **)v6, v5);
                if ( v9 == 1 )
                {
                  v9 = CAkParameterNodeBase::SetInitialRTPC(v7, (char **)v6, v5);
                  if ( v9 == 1 )
                    v9 = CAkParameterNodeBase::ReadFeedbackInfo(v7, (char **)v6, v5);
                }
              }
            }
          }
        }
      }
    }
    return v9;
  }
  return result;
}

// File Line: 1657
// RVA: 0xA731C0
signed __int64 __fastcall CAkParameterNodeBase::ReadFeedbackInfo(CAkParameterNodeBase *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  CAkParameterNodeBase *v3; // rbx
  signed __int64 result; // rax
  unsigned int v5; // edi
  CAkParameterNodeBase::AkFeedbackInfo *v6; // rax
  unsigned int v7; // esi
  CAkIndexable *v8; // rdi

  v3 = this;
  if ( !g_pBankManager->m_bFeedbackInBank )
    return 1i64;
  v5 = *(_DWORD *)*io_rpData;
  *io_rpData += 4;
  if ( !v5 )
    goto LABEL_15;
  if ( !this->m_pFeedbackInfo )
  {
    v6 = (CAkParameterNodeBase::AkFeedbackInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8ui64);
    v3->m_pFeedbackInfo = v6;
    if ( v6 )
      v6->m_pFeedbackBus = 0i64;
    if ( !v3->m_pFeedbackInfo )
      return 52i64;
  }
  v7 = 2;
  v8 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v5, AkNodeType_Bus);
  if ( v8
    && (v3->vfptr->AddRef((CAkIndexable *)&v3->vfptr),
        v7 = ((__int64 (__fastcall *)(CAkIndexable *, CAkParameterNodeBase *))v8->vfptr[2].AddRef)(v8, v3),
        v8->vfptr->Release(v8),
        v7 == 1) )
  {
LABEL_15:
    result = 1i64;
  }
  else
  {
    result = v7;
  }
  return result;
}

// File Line: 1693
// RVA: 0xA73C50
signed __int64 __fastcall CAkParameterNodeBase::SetInitialRTPC(CAkParameterNodeBase *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char *v3; // rax
  unsigned int **v4; // rbx
  unsigned int *v5; // rbp
  unsigned int v6; // edx
  CAkParameterNodeBase *v7; // r14
  __int64 v8; // rsi
  unsigned __int16 *v9; // rax
  unsigned int v10; // edx
  AkRTPC_ParameterID v11; // er8
  unsigned int v12; // er9
  AkCurveScaling in_eScaling; // er11
  unsigned int in_ulConversionArraySize; // ST30_4
  __int64 v15; // rdi

  v3 = *io_rpData;
  v4 = (unsigned int **)io_rpData;
  v5 = io_rulDataSize;
  v6 = *(unsigned __int16 *)*io_rpData;
  v7 = this;
  *v4 = (unsigned int *)(v3 + 2);
  if ( v6 )
  {
    v8 = v6;
    do
    {
      v9 = (unsigned __int16 *)(*v4 + 1);
      v10 = **v4;
      *v4 = (unsigned int *)v9;
      v9 += 2;
      v11 = *((_DWORD *)v9 - 1);
      *v4 = (unsigned int *)v9;
      v12 = *(_DWORD *)v9;
      v9 += 2;
      *v4 = (unsigned int *)v9;
      v9 = (unsigned __int16 *)((char *)v9 + 1);
      in_eScaling = *((unsigned __int8 *)v9 - 1);
      *v4 = (unsigned int *)v9;
      in_ulConversionArraySize = *v9;
      v15 = *v9;
      *v4 = (unsigned int *)(v9 + 1);
      CAkParameterNodeBase::SetRTPC(
        v7,
        v10,
        v11,
        v12,
        in_eScaling,
        (AkRTPCGraphPointBase<float> *)(v9 + 1),
        in_ulConversionArraySize);
      *v4 += 3 * v15;
      *v5 += -12 * v15;
      --v8;
    }
    while ( v8 );
  }
  return 1i64;
}

// File Line: 1725
// RVA: 0xA740A0
signed __int64 __fastcall CAkParameterNodeBase::SetParamComplexFromRTPCManager(CAkParameterNodeBase *this, void *in_pToken, __int64 in_Param_id, __int64 in_RTPCid, float in_value, CAkRegisteredObj *in_GameObj, void *in_pGameObjExceptArray)
{
  unsigned int v7; // ebp
  CAkParameterNodeBase *v8; // rdi
  unsigned int v9; // esi
  float v10; // xmm2_4
  signed __int64 result; // rax
  CAkIndexableVtbl *v12; // rax
  char v13; // ST20_1
  int v14; // [rsp+30h] [rbp-38h]
  CAkRegisteredObj *v15; // [rsp+38h] [rbp-30h]
  char v16; // [rsp+40h] [rbp-28h]
  void *v17; // [rsp+48h] [rbp-20h]
  float v18; // [rsp+50h] [rbp-18h]

  v7 = in_Param_id;
  v8 = this;
  v9 = 1;
  switch ( (_DWORD)in_Param_id )
  {
    case 0:
    case 2:
    case 3:
    case 4:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x16:
    case 0x17:
    case 0x1D:
    case 0x1E:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
      v10 = in_value - CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, in_pToken, in_GameObj, in_RTPCid);
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkIndexableVtbl *, CAkRegisteredObj *, void *))v8->vfptr[5].Release)(
        v8,
        v7,
        v8->vfptr,
        in_GameObj,
        in_pGameObjExceptArray);
      return 1i64;
    case 6:
      goto $LN16_77;
    case 8:
      if ( !(*((_BYTE *)this + 82) & 0x40) && this->m_pParentNode )
        goto $LN16_77;
      v15 = in_GameObj;
      v18 = in_value;
      v17 = in_pGameObjExceptArray;
      v12 = this->vfptr;
      v14 = 8;
      v16 = 0;
      ((void (__fastcall *)(CAkParameterNodeBase *, int *, __int64, __int64))v12[5].AddRef)(
        this,
        &v14,
        in_Param_id,
        in_RTPCid);
      return 1i64;
    case 9:
      if ( !(*((_BYTE *)this + 82) & 8) && this->m_pParentNode )
        goto $LN16_77;
      v13 = 1;
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkRegisteredObj *, void *, char))this->vfptr[13].AddRef)(
        this,
        (unsigned int)(signed int)in_value,
        in_GameObj,
        in_pGameObjExceptArray,
        v13);
      result = 1i64;
      break;
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0x14:
    case 0x15:
    case 0x25:
    case 0x26:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
      ((void (__fastcall *)(CAkParameterNodeBase *, CAkIndexableVtbl *, _QWORD, CAkRegisteredObj *, void *))this->vfptr[17].Release)(
        this,
        this->vfptr,
        (unsigned int)in_Param_id,
        in_GameObj,
        in_pGameObjExceptArray);
      result = 1i64;
      break;
    case 0x18:
      ((void (__fastcall *)(CAkParameterNodeBase *, bool, signed __int64, CAkRegisteredObj *, void *))this->vfptr[6].Category)(
        this,
        in_value != 0.0,
        1i64,
        in_GameObj,
        in_pGameObjExceptArray);
      result = 1i64;
      break;
    case 0x19:
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, signed __int64, CAkRegisteredObj *, void *))this->vfptr[6].Category)(
        this,
        2 * (unsigned int)(in_value != 0.0),
        2i64,
        in_GameObj,
        in_pGameObjExceptArray);
      result = 1i64;
      break;
    case 0x1A:
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, signed __int64, CAkRegisteredObj *, void *))this->vfptr[6].Category)(
        this,
        4 * (unsigned int)(in_value != 0.0),
        4i64,
        in_GameObj,
        in_pGameObjExceptArray);
      result = 1i64;
      break;
    case 0x1B:
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, signed __int64, CAkRegisteredObj *, void *))this->vfptr[6].Category)(
        this,
        8 * (unsigned int)(in_value != 0.0),
        8i64,
        in_GameObj,
        in_pGameObjExceptArray);
      result = 1i64;
      break;
    case 0x1C:
      ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, signed __int64, CAkRegisteredObj *, void *))this->vfptr[6].Category)(
        this,
        16 * (unsigned int)(in_value != 0.0),
        16i64,
        in_GameObj,
        in_pGameObjExceptArray);
      result = 1i64;
      break;
    default:
      v9 = 2;
$LN16_77:
      result = v9;
      break;
  }
  return result;
}

// File Line: 1828
// RVA: 0xA74460
void __fastcall CAkParameterNodeBase::SetRTPC(CAkParameterNodeBase *this, unsigned int in_RTPC_ID, AkRTPC_ParameterID in_ParamID, unsigned int in_RTPCCurveID, AkCurveScaling in_eScaling, AkRTPCGraphPointBase<float> *in_pArrayConversion, unsigned int in_ulConversionArraySize)
{
  CAkParameterNodeBase *v7; // rbx
  unsigned int v8; // esi
  AkRTPC_ParameterID v9; // edi
  unsigned int v10; // ebp
  CAkRTPCMgr::SubscriberType in_eType; // eax

  v7 = this;
  v8 = in_RTPCCurveID;
  v9 = in_ParamID;
  v7->m_RTPCBitArray.m_iBitArray |= 1i64 << in_ParamID;
  v10 = in_RTPC_ID;
  if ( g_pRTPCMgr )
  {
    in_eType = this->vfptr[19].AddRef((CAkIndexable *)this);
    CAkRTPCMgr::SubscribeRTPC(
      g_pRTPCMgr,
      v7,
      v10,
      v9,
      v8,
      in_eScaling,
      in_pArrayConversion,
      in_ulConversionArraySize,
      0i64,
      in_eType);
    v7->vfptr[7].__vecDelDtor((CAkIndexable *)&v7->vfptr, v9);
  }
}

// File Line: 1854
// RVA: 0xA74B00
void __fastcall CAkParameterNodeBase::UnsetRTPC(CAkParameterNodeBase *this, AkRTPC_ParameterID in_ParamID, unsigned int in_RTPCCurveID)
{
  CAkParameterNodeBase *v3; // rbx
  AkRTPC_ParameterID v4; // edi
  signed __int64 v5; // rdx
  signed int v6; // er8
  char *v7; // r9
  unsigned int v8; // er10
  __int64 v9; // rcx
  __int64 v10; // rdx
  int *v11; // rax
  int v12; // [rsp+40h] [rbp+8h]
  bool out_bMoreCurvesRemaining; // [rsp+48h] [rbp+10h]

  v3 = this;
  v4 = in_ParamID;
  out_bMoreCurvesRemaining = 0;
  if ( !g_pRTPCMgr
    || (CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, this, in_ParamID, in_RTPCCurveID, &out_bMoreCurvesRemaining),
        !out_bMoreCurvesRemaining) )
  {
    v3->m_RTPCBitArray.m_iBitArray &= ~(1i64 << v4);
  }
  v3->vfptr[12].Category((CAkIndexable *)&v3->vfptr);
  if ( v4 == 20 )
  {
    v6 = 11;
  }
  else
  {
    if ( v4 != 21 )
    {
      if ( (unsigned int)(v4 - 37) > 1 )
        return;
      goto LABEL_18;
    }
    v6 = 12;
  }
  v7 = v3->m_props.m_pProps;
  v12 = g_AkPropDefault[v6].iValue;
  if ( v7 )
  {
    v8 = (unsigned __int8)*v7;
    v9 = 0i64;
    while ( 1 )
    {
      v10 = (unsigned int)(v9 + 1);
      if ( v7[v10] == (_BYTE)v6 )
        break;
      v9 = (unsigned int)v10;
      if ( (unsigned int)v10 >= v8 )
        goto LABEL_14;
    }
    v5 = (signed __int64)&v7[4 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_14:
    v5 = 0i64;
  }
  v11 = &v12;
  if ( v5 )
    v11 = (int *)v5;
  v12 = *v11;
LABEL_18:
  ((void (__fastcall *)(CAkParameterNodeBase *, signed __int64, _QWORD, _QWORD, _QWORD))v3->vfptr[17].Release)(
    v3,
    v5,
    (unsigned int)v4,
    0i64,
    0i64);
}

// File Line: 1910
// RVA: 0xA72380
char __fastcall CAkParameterNodeBase::GetStateSyncTypes(CAkParameterNodeBase *this, unsigned int in_stateGroupID, CAkParameterNodeBase::CAkStateSyncArray *io_pSyncTypes, bool in_bBusChecked)
{
  bool v4; // di
  CAkParameterNodeBase::CAkStateSyncArray *v5; // rsi
  unsigned int v6; // ebp
  CAkParameterNodeBase *v7; // rbx
  CAkBus *v8; // rcx

  v4 = in_bBusChecked;
  v5 = io_pSyncTypes;
  v6 = in_stateGroupID;
  v7 = this;
  if ( !CAkParameterNodeBase::CheckSyncTypes(this, in_stateGroupID, io_pSyncTypes) )
  {
    do
    {
      if ( !v4 )
      {
        v8 = (CAkBus *)v7->m_pBusOutputNode;
        if ( v8 )
        {
          v4 = 1;
          if ( CAkBus::GetStateSyncTypes(v8, v6, v5) )
            break;
        }
      }
      v7 = v7->m_pParentNode;
      if ( !v7 )
        return 0;
    }
    while ( !CAkParameterNodeBase::CheckSyncTypes(v7, v6, v5) );
  }
  return 1;
}

// File Line: 1930
// RVA: 0xA70F10
bool __fastcall CAkParameterNodeBase::CheckSyncTypes(CAkParameterNodeBase *this, unsigned int in_stateGroupID, CAkParameterNodeBase::CAkStateSyncArray *io_pSyncTypes)
{
  AkStateGroupChunk *v3; // rax
  unsigned int v4; // ebx
  unsigned int *v5; // rax
  AkSyncType *v6; // rax
  AkSyncType *v7; // rdx
  unsigned int *v8; // rax

  v3 = this->m_states.m_pFirst;
  if ( !v3 )
  {
LABEL_14:
    LOBYTE(v3) = 0;
    return (char)v3;
  }
  while ( v3->m_ulStateGroup != in_stateGroupID )
  {
    v3 = v3->m_pNextInNode;
    if ( !v3 )
      return (char)v3;
  }
  v4 = (unsigned __int8)v3->m_eStateSyncType;
  if ( v3->m_eStateSyncType )
  {
    v6 = io_pSyncTypes->m_StateSyncArray.m_pItems;
    v7 = &io_pSyncTypes->m_StateSyncArray.m_pItems[io_pSyncTypes->m_StateSyncArray.m_uLength];
    if ( io_pSyncTypes->m_StateSyncArray.m_pItems == v7 )
    {
LABEL_12:
      v8 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast((AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *)io_pSyncTypes);
      if ( v8 )
        *v8 = v4;
    }
    else
    {
      while ( *v6 != v4 )
      {
        ++v6;
        if ( v6 == v7 )
          goto LABEL_12;
      }
    }
    goto LABEL_14;
  }
  io_pSyncTypes->m_StateSyncArray.m_uLength = v4;
  v5 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast((AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *)io_pSyncTypes);
  if ( v5 )
    *v5 = v4;
  LOBYTE(v3) = 1;
  return (char)v3;
}

// File Line: 1974
// RVA: 0xA73BE0
void __fastcall CAkParameterNodeBase::SetFeedbackVolume(CAkParameterNodeBase *this, CAkRegisteredObj *in_GameObjPtr, AkValueMeaning in_eValueMeaning, float in_fTargetValue, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  AkValueMeaning v6; // edi
  CAkParameterNodeBase *v7; // rbx
  CAkSIS *v8; // rax

  v6 = in_eValueMeaning;
  v7 = this;
  v8 = (CAkSIS *)this->vfptr[19].__vecDelDtor((CAkIndexable *)this, (unsigned int)in_GameObjPtr);
  if ( v8 )
    CAkParameterNodeBase::StartSISTransition(
      v7,
      v8,
      AkPropID_FeedbackVolume,
      in_fTargetValue,
      v6,
      in_eFadeCurve,
      in_lTransitionTime);
}

// File Line: 1993
// RVA: 0xA71750
void __fastcall CAkParameterNodeBase::FeedbackParentBus(CAkParameterNodeBase *this, CAkFeedbackBus *in_pParent)
{
  CAkFeedbackBus *v2; // rdi
  CAkParameterNodeBase *v3; // rbx
  CAkParameterNodeBase::AkFeedbackInfo *v4; // rax
  CAkParameterNodeBase::AkFeedbackInfo *v5; // rax

  v2 = in_pParent;
  v3 = this;
  if ( in_pParent || this->m_pFeedbackInfo )
  {
    v4 = this->m_pFeedbackInfo;
    if ( v4 )
      goto LABEL_10;
    v5 = (CAkParameterNodeBase::AkFeedbackInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8ui64);
    v3->m_pFeedbackInfo = v5;
    if ( v5 )
      v5->m_pFeedbackBus = 0i64;
    v4 = v3->m_pFeedbackInfo;
    if ( v4 )
LABEL_10:
      v4->m_pFeedbackBus = v2;
  }
}

// File Line: 2009
// RVA: 0xA71740
CAkFeedbackBus *__fastcall CAkParameterNodeBase::FeedbackParentBus(CAkParameterNodeBase *this)
{
  CAkFeedbackBus *result; // rax

  result = (CAkFeedbackBus *)this->m_pFeedbackInfo;
  if ( result )
    result = (CAkFeedbackBus *)result->vfptr;
  return result;
}

// File Line: 2017
// RVA: 0xA72130
CAkFeedbackBus *__fastcall CAkParameterNodeBase::GetFeedbackParentBusOrDefault(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase *v1; // rdi
  CAkFeedbackBus *result; // rax
  CAkFeedbackBus *v3; // rbx

  v1 = this;
  result = (CAkFeedbackBus *)((__int64 (*)(void))this->vfptr[16].Release)();
  if ( !result )
  {
    result = CAkFeedbackBus::GetMasterMotionBusAndAddRef();
    v3 = result;
    if ( result )
    {
      v1->vfptr->AddRef((CAkIndexable *)&v1->vfptr);
      ((void (__fastcall *)(CAkFeedbackBus *, CAkParameterNodeBase *))v3->vfptr[2].AddRef)(v3, v1);
      v3->vfptr->Release((CAkIndexable *)&v3->vfptr);
      result = v3;
    }
  }
  return result;
}

// File Line: 2040
// RVA: 0xA71F80
signed __int64 __usercall CAkParameterNodeBase::GetFeedbackParameters@<rax>(CAkParameterNodeBase *this@<rcx>, AkFeedbackParams *io_Params@<rdx>, CAkSource *in_pSource@<r8>, CAkRegisteredObj *in_GameObjPtr@<r9>, float a5@<xmm0>, bool in_bDoBusCheck)
{
  bool v6; // di
  CAkRegisteredObj *v7; // rbp
  CAkSource *v8; // r14
  AkFeedbackParams *v9; // rbx
  CAkParameterNodeBase *v10; // rsi
  float v11; // xmm6_4
  CAkFeedbackBus *v12; // rcx
  CAkParameterNodeBase *v13; // rax
  CAkParameterNodeBase *v14; // r9
  CAkParameterNodeBase::FXChunk *v15; // rdx
  char *v16; // r8
  unsigned int v17; // er10
  __int64 v18; // rcx
  __int64 v19; // rdx
  signed __int64 v20; // rdx
  float *v21; // rax
  float v22; // xmm0_4
  CAkParameterNodeBase *v23; // rcx
  __int64 v25[2]; // [rsp+20h] [rbp-38h]
  float v26; // [rsp+60h] [rbp+8h]

  v6 = io_Params->m_usPluginID == 0;
  v7 = in_GameObjPtr;
  v8 = in_pSource;
  v9 = io_Params;
  v10 = this;
  if ( this->m_pFeedbackInfo )
  {
    this->vfptr[17].__vecDelDtor((CAkIndexable *)this, (unsigned int)in_GameObjPtr);
    v11 = a5;
    ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *))v10->vfptr[17].AddRef)(v10, v7);
    if ( in_bDoBusCheck )
    {
      v12 = v10->m_pFeedbackInfo->m_pFeedbackBus;
      v9->m_NewVolume = a5;
      v9->m_LPF = a5;
      if ( v6 )
      {
        v9->m_pOutput = v12;
        v9->m_usPluginID = -1;
      }
      ((void (__fastcall *)(CAkFeedbackBus *, AkFeedbackParams *, CAkSource *, CAkRegisteredObj *, _BYTE))v12->vfptr[16].__vecDelDtor)(
        v12,
        v9,
        v8,
        v7,
        0);
      v13 = v10;
      while ( 1 )
      {
        v14 = v13->m_pBusOutputNode;
        v13 = v13->m_pParentNode;
        if ( v14 )
          break;
        if ( !v13 )
          goto LABEL_22;
      }
      do
      {
        v15 = v14->m_pFXChunk;
        if ( v15 && (v15->aFX[0].id != 0 || v15->aFX[1].id != 0 || v15->aFX[2].id != 0 || v15->aFX[3].id != 0) )
          break;
        v16 = v14->m_props.m_pProps;
        v26 = 0.0;
        if ( v16 )
        {
          v17 = (unsigned __int8)*v16;
          v18 = 0i64;
          while ( 1 )
          {
            v19 = (unsigned int)(v18 + 1);
            if ( !v16[v19] )
              break;
            v18 = (unsigned int)v19;
            if ( (unsigned int)v19 >= v17 )
              goto LABEL_15;
          }
          v20 = (signed __int64)&v16[4 * v18 + ((v17 + 4) & 0xFFFFFFFC)];
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
        v9->m_AudioBusVolume = v26 + v9->m_AudioBusVolume;
        v14 = v14->m_pBusOutputNode;
      }
      while ( v14 );
    }
    else
    {
      v22 = a5 + v9->m_LPF;
      v9->m_NewVolume = v11 + v9->m_NewVolume;
      v9->m_LPF = v22;
    }
  }
LABEL_22:
  v23 = v10->m_pParentNode;
  if ( v23 )
  {
    LOBYTE(v25[0]) = 0;
    ((void (__fastcall *)(CAkParameterNodeBase *, AkFeedbackParams *, CAkSource *, CAkRegisteredObj *, __int64))v23->vfptr[16].__vecDelDtor)(
      v23,
      v9,
      v8,
      v7,
      v25[0]);
  }
  return 1i64;
}

// File Line: 2117
// RVA: 0xA71EF0
void __fastcall CAkParameterNodeBase::GetEffectiveFeedbackVolume(CAkParameterNodeBase *this, CAkRegisteredObj *in_GameObjPtr)
{
  __int64 v2; // rax
  char *v3; // r8
  signed __int64 v4; // r10
  unsigned int v5; // er9
  __int64 v6; // rcx
  __int64 v7; // rdx
  int *v8; // rax
  int v9; // [rsp+8h] [rbp+8h]

  v2 = LODWORD(this->m_RTPCBitArray.m_iBitArray);
  if ( _bittest64(&v2, 0x1Du) )
  {
    CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x1Du, in_GameObjPtr);
  }
  else
  {
    v3 = this->m_props.m_pProps;
    v4 = 0i64;
    v9 = g_AkPropDefault[8].iValue;
    if ( v3 )
    {
      v5 = (unsigned __int8)*v3;
      v6 = 0i64;
      while ( 1 )
      {
        v7 = (unsigned int)(v6 + 1);
        if ( v3[v7] == 8 )
          break;
        v6 = (unsigned int)v7;
        if ( (unsigned int)v7 >= v5 )
          goto LABEL_9;
      }
      v4 = (signed __int64)&v3[4 * v6 + ((v5 + 4) & 0xFFFFFFFC)];
    }
LABEL_9:
    v8 = &v9;
    if ( v4 )
      v8 = (int *)v4;
    v9 = *v8;
  }
}

// File Line: 2125
// RVA: 0xA71E40
float __fastcall CAkParameterNodeBase::GetEffectiveFeedbackLPF(CAkParameterNodeBase *this, CAkRegisteredObj *in_GameObjPtr)
{
  char *v2; // r9
  signed __int64 v3; // r11
  CAkRegisteredObj *v4; // rbx
  unsigned int *v5; // rdx
  unsigned int v6; // er10
  int v7; // er8
  __int64 v8; // rcx
  int *v9; // rax
  __int64 v10; // rax
  float v11; // xmm6_4
  float v13; // [rsp+40h] [rbp+8h]

  v2 = this->m_props.m_pProps;
  v3 = 0i64;
  v4 = in_GameObjPtr;
  v5 = (unsigned int *)this;
  v13 = 0.0;
  if ( v2 )
  {
    v6 = (unsigned __int8)*v2;
    v7 = 0;
    while ( 1 )
    {
      v8 = (unsigned int)(v7 + 1);
      if ( v2[v8] == 9 )
        break;
      ++v7;
      if ( (unsigned int)v8 >= v6 )
        goto LABEL_7;
    }
    v3 = (signed __int64)&v2[4 * v7 + ((v6 + 4) & 0xFFFFFFFC)];
  }
LABEL_7:
  v9 = (int *)&v13;
  if ( v3 )
    v9 = (int *)v3;
  v13 = *(float *)v9;
  v10 = v5[22];
  v11 = v13;
  if ( _bittest64(&v10, 0x1Eu) )
    v11 = v11 + CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v5, 0x1Eu, v4);
  return v11;
}

// File Line: 2134
// RVA: 0xA72590
bool __fastcall CAkParameterNodeBase::IncrementActivityCount(CAkParameterNodeBase *this, unsigned __int16 in_flagForwardToBus)
{
  unsigned __int16 v2; // di
  CAkParameterNodeBase *v3; // rsi
  __int64 v4; // rbx
  AkActivityChunk *v5; // rax
  CAkParameterNodeBase *v6; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *v7; // rax
  CAkParameterNodeBase *v8; // rcx
  bool result; // al

  v2 = in_flagForwardToBus;
  v3 = this;
  LOBYTE(v4) = CAkParameterNodeBase::EnableActivityChunk(this, in_flagForwardToBus);
  v5 = v3->m_pActivityChunk;
  if ( v5 )
    ++v5->m_uActivityCount;
  if ( v2 & 1 )
  {
    v6 = v3->m_pBusOutputNode;
    if ( v6 )
    {
      v2 &= 0xFFFEu;
      v4 = (unsigned __int8)(v4 & ((__int64 (__fastcall *)(CAkParameterNodeBase *, signed __int64))v6->vfptr[9].Release)(
                                    v6,
                                    3i64));
    }
  }
  if ( v2 & 2 )
  {
    v7 = v3->m_pFeedbackInfo;
    if ( v7 )
    {
      if ( v7->m_pFeedbackBus )
      {
        v2 &= 0xFFFDu;
        LOBYTE(v4) = ((__int64 (__fastcall *)(CAkFeedbackBus *, signed __int64))v7->m_pFeedbackBus->vfptr[9].Release)(
                       v7->m_pFeedbackBus,
                       3i64) & v4;
      }
    }
  }
  v8 = v3->m_pParentNode;
  if ( v8 )
    result = v4 & ((__int64 (__fastcall *)(CAkParameterNodeBase *, _QWORD))v8->vfptr[9].Release)(v8, v2);
  else
    result = v4;
  return result;
}

// File Line: 2168
// RVA: 0xA70F90
void __fastcall CAkParameterNodeBase::DecrementActivityCount(CAkParameterNodeBase *this, unsigned __int16 in_flagForwardToBus)
{
  AkActivityChunk *v2; // rax
  unsigned __int16 v3; // di
  CAkParameterNodeBase *v4; // rbx
  AkActivityChunk *v5; // rax
  CAkParameterNodeBase *v6; // rcx
  CAkParameterNodeBase::AkFeedbackInfo *v7; // rax
  CAkParameterNodeBase *v8; // rcx

  v2 = this->m_pActivityChunk;
  v3 = in_flagForwardToBus;
  v4 = this;
  if ( v2 )
  {
    --v2->m_uActivityCount;
    v5 = this->m_pActivityChunk;
    if ( !v5->m_PlayCount
      && !v5->m_uActivityCount
      && !v5->m_iPlayCountValid
      && !v5->m_iVirtualCountValid
      && !v5->m_listPBI.m_pFirst
      && !v5->m_ListPlayCountPerObj.m_uLength )
    {
      CAkParameterNodeBase::DeleteActivityChunk(this);
    }
  }
  if ( v3 & 1 )
  {
    v6 = v4->m_pBusOutputNode;
    if ( v6 )
    {
      v3 &= 0xFFFEu;
      ((void (__fastcall *)(CAkParameterNodeBase *, signed __int64))v6->vfptr[9].Category)(v6, 3i64);
    }
  }
  if ( v3 & 2 )
  {
    v7 = v4->m_pFeedbackInfo;
    if ( v7 )
    {
      if ( v7->m_pFeedbackBus )
      {
        v3 &= 0xFFFDu;
        ((void (__fastcall *)(CAkFeedbackBus *, signed __int64))v7->m_pFeedbackBus->vfptr[9].Category)(
          v7->m_pFeedbackBus,
          3i64);
      }
    }
  }
  v8 = v4->m_pParentNode;
  if ( v8 )
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))v8->vfptr[9].Category)(v8, v3);
}

// File Line: 2198
// RVA: 0xA71C70
void __fastcall CAkParameterNodeBase::GetAudioStateParams(CAkParameterNodeBase *this, AkSoundParams *io_Parameters, unsigned int in_uParamSelect)
{
  AkSoundParams *v3; // r11
  AkStateGroupChunk *v4; // rax
  unsigned int v5; // edi
  unsigned int v6; // esi
  unsigned int v7; // ebp
  unsigned int v8; // ebx
  char *v9; // r9
  unsigned int v10; // er10
  int v11; // edx
  __int64 v12; // r8
  float *v13; // r8
  char *v14; // r9
  unsigned int v15; // er10
  int v16; // edx
  __int64 v17; // r8
  float *v18; // r8
  char *v19; // r9
  unsigned int v20; // er10
  int v21; // edx
  __int64 v22; // r8
  float *v23; // r8
  char *v24; // r9
  unsigned int v25; // er10
  int v26; // edx
  __int64 v27; // r8
  float *v28; // r8

  v3 = io_Parameters;
  if ( *((_BYTE *)this + 82) < 0 )
  {
    v4 = this->m_states.m_pFirst;
    if ( v4 )
    {
      v5 = in_uParamSelect & 1;
      v6 = in_uParamSelect & 2;
      v7 = in_uParamSelect & 4;
      v8 = in_uParamSelect & 8;
      do
      {
        if ( v5 )
        {
          v9 = v4->m_values.m_pProps;
          if ( v9 )
          {
            v10 = (unsigned __int8)*v9;
            v11 = 0;
            while ( 1 )
            {
              v12 = (unsigned int)(v11 + 1);
              if ( !v9[v12] )
                break;
              ++v11;
              if ( (unsigned int)v12 >= v10 )
                goto LABEL_12;
            }
            v13 = (float *)&v9[16 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
            if ( v13 )
              v3->Volume = *v13 + v3->Volume;
          }
        }
LABEL_12:
        if ( v6 )
        {
          v14 = v4->m_values.m_pProps;
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
              v3->Pitch = v3->Pitch + *v18;
          }
        }
LABEL_20:
        if ( v7 )
        {
          v19 = v4->m_values.m_pProps;
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
              v3->LPF = v3->LPF + *v23;
          }
        }
LABEL_28:
        if ( v8 )
        {
          v24 = v4->m_values.m_pProps;
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
              v3->BusVolume = v3->BusVolume + *v28;
          }
        }
LABEL_36:
        v4 = v4->m_pNextInNode;
      }
      while ( v4 );
    }
  }
}

// File Line: 2249
// RVA: 0xA72930
signed __int64 __fastcall CAkParameterNodeBase::IncrementPlayCountGlobal(CAkParameterNodeBase *this, float in_fPriority, unsigned __int16 *io_ui16NumKickedOrRevived, CAkLimiter **io_pLimiter)
{
  AkActivityChunk *v4; // rax
  CAkLimiter **v5; // rdi
  unsigned __int16 *v6; // rsi
  CAkParameterNodeBase *v7; // rbx
  signed int v8; // edx
  CAkLimiter *v9; // r10
  AkActivityChunk *v10; // rax
  unsigned __int16 v11; // r8
  unsigned __int16 v12; // cx
  unsigned __int8 v13; // r8
  signed __int64 result; // rax
  CAkParameterNodeBase *out_pKicked; // [rsp+60h] [rbp+8h]

  v4 = this->m_pActivityChunk;
  v5 = io_pLimiter;
  v6 = io_ui16NumKickedOrRevived;
  v7 = this;
  if ( v4 )
    ++v4->m_iPlayCountValid;
  LOWORD(v8) = this->m_u16MaxNumInstance;
  if ( ((unsigned __int64)LODWORD(this->m_RTPCBitArray.m_iBitArray) >> 9) & 1 )
  {
    if ( !(_WORD)v8 )
      return 1i64;
    v8 = (signed int)CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 9u, 0i64);
  }
  if ( (_WORD)v8 )
  {
    v9 = &v7->m_pActivityChunk->m_Limiter;
    *v5 = v9;
    if ( !*v6 )
    {
      v10 = v7->m_pActivityChunk;
      v11 = v10 ? v10->m_iPlayCountValid : 0;
      v12 = v10 ? v10->m_iVirtualCountValid : 0;
      if ( v11 - v12 > (unsigned __int16)v8 )
      {
        v13 = *((_BYTE *)v7 + 82);
        out_pKicked = 0i64;
        result = CAkURenderer::Kick(
                   v9,
                   v8,
                   in_fPriority,
                   0i64,
                   v13 & 1,
                   (v13 >> 1) & 1,
                   &out_pKicked,
                   KickFrom_OverNodeLimit);
        ++*v6;
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
  AkActivityChunk *v1; // rax
  AkActivityChunk *v2; // rax

  v1 = this->m_pActivityChunk;
  if ( v1 )
  {
    --v1->m_iPlayCountValid;
    v2 = this->m_pActivityChunk;
    if ( !v2->m_PlayCount
      && !v2->m_uActivityCount
      && !v2->m_iPlayCountValid
      && !v2->m_iVirtualCountValid
      && !v2->m_listPBI.m_pFirst )
    {
      JUMPOUT(v2->m_ListPlayCountPerObj.m_uLength, 0, CAkParameterNodeBase::DeleteActivityChunk);
    }
  }
}

// File Line: 2282
// RVA: 0xA71390
void __fastcall CAkParameterNodeBase::DecrementVirtualCountGlobal(CAkParameterNodeBase *this, unsigned __int16 *io_ui16NumKickedOrRevived, bool in_bAllowKick)
{
  AkActivityChunk *v3; // rax
  unsigned __int16 *v4; // rdi
  CAkParameterNodeBase *v5; // rbx
  signed int v6; // er10
  AkActivityChunk *v7; // rdx
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // r8
  unsigned __int8 v10; // r8
  AkActivityChunk *v11; // rax
  CAkParameterNodeBase *out_pKicked; // [rsp+50h] [rbp+8h]

  v3 = this->m_pActivityChunk;
  v4 = io_ui16NumKickedOrRevived;
  v5 = this;
  if ( !v3 )
    return;
  --v3->m_iVirtualCountValid;
  if ( in_bAllowKick )
  {
    LOWORD(v6) = this->m_u16MaxNumInstance;
    if ( !(((unsigned __int64)LODWORD(this->m_RTPCBitArray.m_iBitArray) >> 9) & 1) )
    {
LABEL_6:
      if ( (_WORD)v6 )
      {
        v7 = v5->m_pActivityChunk;
        v8 = v7 ? v7->m_iPlayCountValid : 0;
        v9 = v7 ? v7->m_iVirtualCountValid : 0;
        if ( v8 - *v4 - v9 > (unsigned __int16)v6 )
        {
          v10 = *((_BYTE *)v5 + 82);
          out_pKicked = 0i64;
          CAkURenderer::Kick(
            &v7->m_Limiter,
            v6,
            101.0,
            0i64,
            v10 & 1,
            (v10 >> 1) & 1,
            &out_pKicked,
            KickFrom_OverNodeLimit);
          ++*v4;
        }
      }
      goto LABEL_15;
    }
    if ( (_WORD)v6 )
    {
      v6 = (signed int)CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 9u, 0i64);
      goto LABEL_6;
    }
  }
LABEL_15:
  v11 = v5->m_pActivityChunk;
  if ( !v11->m_PlayCount
    && !v11->m_uActivityCount
    && !v11->m_iPlayCountValid
    && !v11->m_iVirtualCountValid
    && !v11->m_listPBI.m_pFirst
    && !v11->m_ListPlayCountPerObj.m_uLength )
  {
    CAkParameterNodeBase::DeleteActivityChunk(v5);
  }
}

// File Line: 2307
// RVA: 0xA72680
__int64 __fastcall CAkParameterNodeBase::IncrementPlayCountGameObject(CAkParameterNodeBase *this, float in_fPriority, unsigned __int16 *io_ui16NumKickedOrRevived, CAkRegisteredObj *in_pGameObj, CAkLimiter **io_pLimiter)
{
  AkActivityChunk *v5; // rdx
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v6; // rax
  CAkRegisteredObj *v7; // rbp
  unsigned __int16 *v8; // r12
  signed __int64 v9; // rdx
  CAkParameterNodeBase *v10; // r14
  unsigned int i; // er15
  signed __int64 v12; // rdi
  CAkLimiter *v13; // r8
  unsigned __int16 v14; // r13
  unsigned __int8 v15; // dl
  __int64 v16; // rbx
  signed int v17; // edi
  char v18; // r12
  _QWORD *v19; // rax
  _BYTE *v20; // rbx
  char v21; // al
  AkActivityChunk *v22; // r8
  CAkRegisteredObj **v23; // rax
  signed __int64 v24; // rcx
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v25; // rax
  void *v26; // rdx
  __int64 v28; // [rsp+48h] [rbp-30h]
  CAkParameterNodeBase *out_pKicked; // [rsp+80h] [rbp+8h]

  v5 = this->m_pActivityChunk;
  v6 = v5->m_ListPlayCountPerObj.m_pItems;
  v7 = in_pGameObj;
  v8 = io_ui16NumKickedOrRevived;
  v9 = (signed __int64)&v5->m_ListPlayCountPerObj.m_pItems[v5->m_ListPlayCountPerObj.m_uLength];
  v10 = this;
  for ( i = 1; v6 != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v9; ++v6 )
  {
    if ( v6->key == in_pGameObj )
      break;
  }
  if ( v6 == (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v9
    || (v12 = (signed __int64)&v6->item, v6 == (MapStruct<CAkRegisteredObj *,StructMaxInst> *)-8i64) )
  {
    LOWORD(v17) = this->m_u16MaxNumInstance;
    if ( ((unsigned __int64)LODWORD(this->m_RTPCBitArray.m_iBitArray) >> 9) & 1 && (_WORD)v17 )
      v17 = (signed int)CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 9u, in_pGameObj);
    v14 = v17;
    LODWORD(v28) = 1;
    v18 = (*((_BYTE *)v10 + 82) >> 1) & 1;
    LOBYTE(out_pKicked) = *((_BYTE *)v10 + 82) & 1;
    v19 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
    v20 = v19;
    if ( v19 )
    {
      *v19 = 0i64;
      v19[1] = 0i64;
      *((_WORD *)v19 + 8) = v17;
      v21 = (char)out_pKicked;
      v20[19] = v18;
      v20[18] = v21;
    }
    else
    {
      v20 = 0i64;
    }
    v22 = v10->m_pActivityChunk;
    v23 = &v22->m_ListPlayCountPerObj.m_pItems->key;
    v24 = (signed __int64)&v22->m_ListPlayCountPerObj.m_pItems[v22->m_ListPlayCountPerObj.m_uLength];
    if ( v22->m_ListPlayCountPerObj.m_pItems == (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v24 )
      goto LABEL_45;
    do
    {
      if ( *v23 == v7 )
        break;
      v23 += 3;
    }
    while ( v23 != (CAkRegisteredObj **)v24 );
    if ( v23 == (CAkRegisteredObj **)v24 )
    {
LABEL_45:
      v12 = 0i64;
    }
    else
    {
      v12 = (signed __int64)(v23 + 1);
      if ( v23 != (CAkRegisteredObj **)-8i64 )
        goto LABEL_30;
    }
    v25 = AkArray<MapStruct<CAkRegisteredObj *,StructMaxInst>,MapStruct<CAkRegisteredObj *,StructMaxInst> const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<CAkRegisteredObj *,StructMaxInst>,MapStruct<CAkRegisteredObj *,StructMaxInst> const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *)&v10->m_pActivityChunk->m_ListPlayCountPerObj.m_pItems);
    if ( !v25 )
      goto LABEL_31;
    v25->key = v7;
    v12 = (signed __int64)&v25->item;
LABEL_30:
    *(_QWORD *)v12 = v20;
    *(_QWORD *)(v12 + 8) = v28;
LABEL_31:
    if ( v12 )
    {
      if ( v20 )
        goto LABEL_39;
    }
    else if ( v20 )
    {
      v26 = *(void **)v20;
      if ( *(_QWORD *)v20 )
      {
        *((_DWORD *)v20 + 2) = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v26);
        *(_QWORD *)v20 = 0i64;
        *((_DWORD *)v20 + 3) = 0;
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, v20);
    }
    i = 2;
    goto LABEL_39;
  }
  v13 = *(CAkLimiter **)v12;
  ++v6->item.u16Current;
  if ( v13 )
    v14 = v13->m_u16LimiterMax;
  else
    v14 = 0;
  if ( v13 )
  {
    if ( v13->m_u16LimiterMax )
    {
      if ( v6->item.u16Current - v6->item.u16CurrentVirtual - *v8 > v14 )
      {
        v15 = *((_BYTE *)this + 82);
        out_pKicked = 0i64;
        i = CAkURenderer::Kick(
              v13,
              v14,
              in_fPriority,
              in_pGameObj,
              v15 & 1,
              (v15 >> 1) & 1,
              &out_pKicked,
              KickFrom_OverNodeLimit);
        if ( !out_pKicked
          || (v16 = ((__int64 (*)(void))out_pKicked->vfptr[8].__vecDelDtor)(),
              v16 == ((__int64 (__fastcall *)(CAkParameterNodeBase *))v10->vfptr[8].__vecDelDtor)(v10)) )
        {
          ++*v8;
        }
      }
    }
  }
LABEL_39:
  if ( v12 && v14 )
    *io_pLimiter = *(CAkLimiter **)v12;
  return i;
}

// File Line: 2355
// RVA: 0xA710B0
void __fastcall CAkParameterNodeBase::DecrementPlayCountGameObject(CAkParameterNodeBase *this, CAkRegisteredObj *in_pGameObj)
{
  AkActivityChunk *v2; // r8
  CAkRegisteredObj *v3; // rbx
  CAkParameterNodeBase *v4; // rdi
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v5; // rax
  signed __int64 v6; // r8
  bool v7; // zf
  AkActivityChunk *v8; // rax

  v2 = this->m_pActivityChunk;
  v3 = in_pGameObj;
  v4 = this;
  v5 = v2->m_ListPlayCountPerObj.m_pItems;
  v6 = (signed __int64)&v2->m_ListPlayCountPerObj.m_pItems[v2->m_ListPlayCountPerObj.m_uLength];
  if ( v5 != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v6 )
  {
    do
    {
      if ( v5->key == in_pGameObj )
        break;
      ++v5;
    }
    while ( v5 != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v6 );
    if ( v5 != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v6
      && v5 != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)-8i64 )
    {
      v7 = v5->item.u16Current-- == 1;
      if ( v7 && !v5->item.u16CurrentVirtual )
      {
        StructMaxInst::DisableLimiter(&v5->item);
        CAkKeyArray<CAkRegisteredObj *,StructMaxInst,2>::Unset(&v4->m_pActivityChunk->m_ListPlayCountPerObj, v3);
      }
      v8 = v4->m_pActivityChunk;
      if ( !v8->m_PlayCount
        && !v8->m_uActivityCount
        && !v8->m_iPlayCountValid
        && !v8->m_iVirtualCountValid
        && !v8->m_listPBI.m_pFirst
        && !v8->m_ListPlayCountPerObj.m_uLength )
      {
        CAkParameterNodeBase::DeleteActivityChunk(v4);
      }
    }
  }
}

// File Line: 2375
// RVA: 0xA72A70
void __fastcall CAkParameterNodeBase::IncrementVirtualCountGameObject(CAkParameterNodeBase *this, CAkRegisteredObj *in_pGameObj)
{
  AkActivityChunk *v2; // r8
  CAkRegisteredObj **v3; // rax
  signed __int64 v4; // rcx
  signed __int64 v5; // rax

  v2 = this->m_pActivityChunk;
  v3 = &v2->m_ListPlayCountPerObj.m_pItems->key;
  v4 = (signed __int64)&v2->m_ListPlayCountPerObj.m_pItems[v2->m_ListPlayCountPerObj.m_uLength];
  if ( v2->m_ListPlayCountPerObj.m_pItems != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v4 )
  {
    do
    {
      if ( *v3 == in_pGameObj )
        break;
      v3 += 3;
    }
    while ( v3 != (CAkRegisteredObj **)v4 );
    if ( v3 != (CAkRegisteredObj **)v4 )
    {
      v5 = (signed __int64)(v3 + 1);
      if ( v5 )
        ++*(_WORD *)(v5 + 10);
    }
  }
}

// File Line: 2384
// RVA: 0xA71200
void __fastcall CAkParameterNodeBase::DecrementVirtualCountGameObject(CAkParameterNodeBase *this, unsigned __int16 *io_ui16NumKickedOrRevived, bool in_bAllowKick, CAkRegisteredObj *in_pGameObj)
{
  AkActivityChunk *v4; // r10
  CAkRegisteredObj *v5; // rsi
  unsigned __int16 *v6; // rbp
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v7; // rax
  CAkParameterNodeBase *v8; // r14
  signed __int64 v9; // r10
  StructMaxInst *v10; // rdi
  CAkLimiter *v11; // r10
  unsigned __int16 v12; // dx
  unsigned __int8 v13; // r8
  __int64 v14; // rbx
  AkActivityChunk *v15; // rax
  CAkParameterNodeBase *out_pKicked; // [rsp+60h] [rbp+8h]

  v4 = this->m_pActivityChunk;
  v5 = in_pGameObj;
  v6 = io_ui16NumKickedOrRevived;
  v7 = v4->m_ListPlayCountPerObj.m_pItems;
  v8 = this;
  v9 = (signed __int64)&v4->m_ListPlayCountPerObj.m_pItems[v4->m_ListPlayCountPerObj.m_uLength];
  if ( v7 != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v9 )
  {
    do
    {
      if ( v7->key == in_pGameObj )
        break;
      ++v7;
    }
    while ( v7 != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v9 );
    if ( v7 != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)v9 )
    {
      v10 = &v7->item;
      if ( v7 != (MapStruct<CAkRegisteredObj *,StructMaxInst> *)-8i64 )
      {
        --v7->item.u16CurrentVirtual;
        if ( in_bAllowKick )
        {
          v11 = v10->m_pLimiter;
          v12 = v10->m_pLimiter ? v11->m_u16LimiterMax : 0;
          if ( v11 )
          {
            if ( v11->m_u16LimiterMax )
            {
              if ( v7->item.u16Current - *v6 - v7->item.u16CurrentVirtual > v12 )
              {
                v13 = *((_BYTE *)this + 82);
                out_pKicked = 0i64;
                CAkURenderer::Kick(
                  v11,
                  v12,
                  101.0,
                  in_pGameObj,
                  v13 & 1,
                  (v13 >> 1) & 1,
                  &out_pKicked,
                  KickFrom_OverNodeLimit);
                if ( !out_pKicked
                  || (v14 = ((__int64 (*)(void))out_pKicked->vfptr[8].__vecDelDtor)(),
                      v14 == ((__int64 (__fastcall *)(CAkParameterNodeBase *))v8->vfptr[8].__vecDelDtor)(v8)) )
                {
                  ++*v6;
                }
              }
            }
          }
        }
        if ( !v10->u16Current && !v10->u16CurrentVirtual )
        {
          StructMaxInst::DisableLimiter(v10);
          CAkKeyArray<CAkRegisteredObj *,StructMaxInst,2>::Unset(&v8->m_pActivityChunk->m_ListPlayCountPerObj, v5);
          v15 = v8->m_pActivityChunk;
          if ( !v15->m_PlayCount
            && !v15->m_uActivityCount
            && !v15->m_iPlayCountValid
            && !v15->m_iVirtualCountValid
            && !v15->m_listPBI.m_pFirst
            && !v15->m_ListPlayCountPerObj.m_uLength )
          {
            CAkParameterNodeBase::DeleteActivityChunk(v8);
          }
        }
      }
    }
  }
}

// File Line: 2417
// RVA: 0xA72A40
__int64 __fastcall CAkParameterNodeBase::IncrementPlayCountValue(CAkParameterNodeBase *this, unsigned __int16 in_flagForwardToBus)
{
  CAkParameterNodeBase *v2; // rbx
  char v3; // al
  AkActivityChunk *v4; // rcx

  v2 = this;
  v3 = CAkParameterNodeBase::EnableActivityChunk(this, in_flagForwardToBus);
  v4 = v2->m_pActivityChunk;
  if ( v4 )
    ++v4->m_PlayCount;
  return 2 - (unsigned int)(v3 != 0);
}

// File Line: 2427
// RVA: 0xA711B0
void __fastcall CAkParameterNodeBase::DecrementPlayCountValue(CAkParameterNodeBase *this)
{
  AkActivityChunk *v1; // rax
  AkActivityChunk *v2; // rax

  v1 = this->m_pActivityChunk;
  if ( v1 )
  {
    --v1->m_PlayCount;
    v2 = this->m_pActivityChunk;
    if ( !v2->m_PlayCount
      && !v2->m_uActivityCount
      && !v2->m_iPlayCountValid
      && !v2->m_iVirtualCountValid
      && !v2->m_listPBI.m_pFirst )
    {
      JUMPOUT(v2->m_ListPlayCountPerObj.m_uLength, 0, CAkParameterNodeBase::DeleteActivityChunk);
    }
  }
}

// File Line: 2439
// RVA: 0xA72650
char __fastcall CAkParameterNodeBase::IncrementActivityCountValue(CAkParameterNodeBase *this, unsigned __int16 in_flagForwardToBus)
{
  CAkParameterNodeBase *v2; // rbx
  char result; // al
  AkActivityChunk *v4; // rcx

  v2 = this;
  result = CAkParameterNodeBase::EnableActivityChunk(this, in_flagForwardToBus);
  v4 = v2->m_pActivityChunk;
  if ( v4 )
    ++v4->m_uActivityCount;
  return result;
}

// File Line: 2449
// RVA: 0xA71060
void __fastcall CAkParameterNodeBase::DecrementActivityCountValue(CAkParameterNodeBase *this)
{
  AkActivityChunk *v1; // rax
  AkActivityChunk *v2; // rax

  v1 = this->m_pActivityChunk;
  if ( v1 )
  {
    --v1->m_uActivityCount;
    v2 = this->m_pActivityChunk;
    if ( !v2->m_PlayCount
      && !v2->m_uActivityCount
      && !v2->m_iPlayCountValid
      && !v2->m_iVirtualCountValid
      && !v2->m_listPBI.m_pFirst )
    {
      JUMPOUT(v2->m_ListPlayCountPerObj.m_uLength, 0, CAkParameterNodeBase::DeleteActivityChunk);
    }
  }
}

// File Line: 2461
// RVA: 0xA71970
__int64 __fastcall CAkParameterNodeBase::Get2DParams(CAkParameterNodeBase *this, CAkRegisteredObj *in_GameObj, BaseGenParams *out_pBasePosParams)
{
  unsigned __int64 v3; // r14
  signed __int64 v4; // rbx
  BaseGenParams *v5; // rsi
  unsigned __int64 v6; // r15
  CAkRegisteredObj *v7; // rdi
  unsigned __int8 v8; // r14
  CAkParameterNodeBase *v9; // rbp
  unsigned __int8 v10; // r15
  float v11; // xmm0_4
  char *v12; // r8
  unsigned int v13; // er9
  __int64 v14; // rcx
  __int64 v15; // rdx
  signed __int64 v16; // rdx
  int *v17; // rax
  int v18; // eax
  char *v19; // r8
  unsigned int v20; // er9
  __int64 v21; // rcx
  __int64 v22; // rdx
  signed __int64 v23; // rdx
  int *v24; // rax
  char *v25; // r8
  unsigned int v26; // er9
  __int64 v27; // rcx
  __int64 v28; // rdx
  int *v29; // rax
  float v31; // [rsp+50h] [rbp+8h]

  v3 = this->m_RTPCBitArray.m_iBitArray;
  v4 = 0i64;
  v5 = out_pBasePosParams;
  v6 = v3;
  v7 = in_GameObj;
  v8 = (v3 >> 21) & 1;
  v9 = this;
  v10 = (v6 >> 20) & 1;
  if ( v10 | v8 )
  {
    if ( v10 )
      out_pBasePosParams->m_fPAN_X_2D = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x14u, in_GameObj);
    else
      out_pBasePosParams->m_fPAN_X_2D = 0.0;
    if ( !v8 )
    {
      v5->m_fPAN_Y_2D = 0.0;
      goto LABEL_24;
    }
    v11 = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v9, 0x15u, v7);
  }
  else
  {
    v12 = this->m_props.m_pProps;
    v31 = 0.0;
    if ( v12 )
    {
      v13 = (unsigned __int8)*v12;
      v14 = 0i64;
      while ( 1 )
      {
        v15 = (unsigned int)(v14 + 1);
        if ( v12[v15] == 11 )
          break;
        v14 = (unsigned int)v15;
        if ( (unsigned int)v15 >= v13 )
          goto LABEL_12;
      }
      v16 = (signed __int64)&v12[4 * v14 + ((v13 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_12:
      v16 = 0i64;
    }
    v17 = (int *)&v31;
    if ( v16 )
      v17 = (int *)v16;
    v18 = *v17;
    v31 = 0.0;
    LODWORD(v5->m_fPAN_X_2D) = v18;
    v19 = v9->m_props.m_pProps;
    if ( v19 )
    {
      v20 = (unsigned __int8)*v19;
      v21 = 0i64;
      while ( 1 )
      {
        v22 = (unsigned int)(v21 + 1);
        if ( v19[v22] == 12 )
          break;
        v21 = (unsigned int)v22;
        if ( (unsigned int)v22 >= v20 )
          goto LABEL_19;
      }
      v23 = (signed __int64)&v19[4 * v21 + ((v20 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_19:
      v23 = 0i64;
    }
    v24 = (int *)&v31;
    if ( v23 )
      v24 = (int *)v23;
    v31 = *(float *)v24;
    v11 = v31;
  }
  v5->m_fPAN_Y_2D = v11;
LABEL_24:
  v25 = v9->m_props.m_pProps;
  v31 = 0.0;
  if ( v25 )
  {
    v26 = (unsigned __int8)*v25;
    v27 = 0i64;
    while ( 1 )
    {
      v28 = (unsigned int)(v27 + 1);
      if ( v25[v28] == 13 )
        break;
      v27 = (unsigned int)v28;
      if ( (unsigned int)v28 >= v26 )
        goto LABEL_32;
    }
    v4 = (signed __int64)&v25[4 * v27 + ((v26 + 4) & 0xFFFFFFFC)];
  }
LABEL_32:
  v29 = (int *)&v31;
  if ( v4 )
    v29 = (int *)v4;
  v31 = *(float *)v29;
  v5->m_fCenterPCT = v31;
  v5->bIsPannerEnabled = (*((_BYTE *)v9 + 83) >> 5) & 1;
  return v10 | (unsigned int)v8;
}

// File Line: 2501
// RVA: 0xA71B40
__int64 __fastcall CAkParameterNodeBase::Get3DPanning(CAkParameterNodeBase *this, CAkRegisteredObj *in_GameObj, AkVector *out_posPan)
{
  unsigned __int64 v3; // rdi
  AkVector *v4; // rbx
  unsigned __int64 v5; // rsi
  CAkRegisteredObj *v6; // rbp
  unsigned __int8 v7; // di
  CAkParameterNodeBase *v8; // r14
  unsigned __int8 v9; // si
  float v10; // xmm0_4
  float v11; // xmm1_4
  bool v12; // zf
  float v14; // [rsp+50h] [rbp+8h]

  v3 = this->m_RTPCBitArray.m_iBitArray;
  v4 = out_posPan;
  v5 = v3;
  v6 = in_GameObj;
  v7 = (v3 >> 38) & 1;
  v8 = this;
  v9 = (v5 >> 37) & 1;
  v14 = 0.0;
  if ( v9 | v7 )
  {
    if ( v9 )
    {
      out_posPan->X = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x25u, in_GameObj);
      if ( ((unsigned __int8 (__fastcall *)(CAkParameterNodeBase *, float *))v8->vfptr[7].Release)(v8, &v14) )
        v4->X = (float)(v14 * 0.0099999998) * v4->X;
    }
    else
    {
      out_posPan->X = 0.0;
    }
    v4->Y = 0.0;
    if ( !v7 )
    {
      v4->Z = 1.0;
      return v9 | (unsigned int)v7;
    }
    v10 = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v8, 0x26u, v6);
    v11 = v14;
    v12 = v14 == 0.0;
    v4->Z = v10;
    if ( !v12 )
      goto LABEL_10;
    if ( ((unsigned __int8 (__fastcall *)(CAkParameterNodeBase *, float *))v8->vfptr[7].Release)(v8, &v14) )
    {
      v11 = v14;
LABEL_10:
      v4->Z = (float)(v11 * 0.0099999998) * v4->Z;
      return v9 | (unsigned int)v7;
    }
  }
  return v9 | (unsigned int)v7;
}

// File Line: 2611
// RVA: 0xA72340
CAkState *__fastcall AkStateGroupChunk::GetState(AkStateGroupChunk *this, unsigned int in_StateTypeID)
{
  MapStruct<unsigned long,AkStateLink> *v2; // rax
  signed __int64 v3; // rcx
  CAkState **v4; // rax
  CAkState *result; // rax

  v2 = this->m_mapStates.m_pItems;
  v3 = (signed __int64)&v2[this->m_mapStates.m_uLength];
  if ( v2 == (MapStruct<unsigned long,AkStateLink> *)v3 )
    goto LABEL_10;
  do
  {
    if ( v2->key == in_StateTypeID )
      break;
    ++v2;
  }
  while ( v2 != (MapStruct<unsigned long,AkStateLink> *)v3 );
  if ( v2 != (MapStruct<unsigned long,AkStateLink> *)v3 && (v4 = &v2->item.pState) != 0i64 )
    result = *v4;
  else
LABEL_10:
    result = 0i64;
  return result;
}

// File Line: 2622
// RVA: 0xA70AE0
signed __int64 __fastcall AkStateGroupChunk::AddState(AkStateGroupChunk *this, unsigned int in_ulStateInstanceID, unsigned int in_ulStateID, bool in_bNotify)
{
  AkStateGroupChunk *v4; // r15
  bool v5; // r13
  unsigned int v6; // ebp
  unsigned int v7; // er12
  CAkIndexable *v8; // rax
  MapStruct<unsigned long,AkStateLink> *v9; // rdi
  CAkState *v10; // rbx
  signed __int64 v11; // rsi
  CAkState **v12; // rdi
  signed __int64 result; // rax
  MapStruct<unsigned long,AkStateLink> *v14; // rdi
  signed __int64 v15; // rax
  AkStateLink v16; // [rsp+20h] [rbp-38h]

  v4 = this;
  v5 = in_bNotify;
  v6 = in_ulStateID;
  v7 = in_ulStateInstanceID;
  v8 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
         (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxCustomStates,
         in_ulStateInstanceID);
  v9 = v4->m_mapStates.m_pItems;
  v10 = (CAkState *)v8;
  v11 = (signed __int64)&v9[v4->m_mapStates.m_uLength];
  if ( v9 != (MapStruct<unsigned long,AkStateLink> *)v11 )
  {
    do
    {
      if ( v9->key == v6 )
        break;
      ++v9;
    }
    while ( v9 != (MapStruct<unsigned long,AkStateLink> *)v11 );
    if ( v9 != (MapStruct<unsigned long,AkStateLink> *)v11 )
    {
      v12 = &v9->item.pState;
      if ( v12 )
      {
        if ( v8 == (CAkIndexable *)*v12 )
        {
          if ( v8 )
            v8->vfptr->Release(v8);
          return 1i64;
        }
        CAkState::TermNotificationSystem(*v12);
        ((void (*)(void))(*v12)->vfptr->Release)();
        v14 = v4->m_mapStates.m_pItems;
        v15 = (signed __int64)&v14[v4->m_mapStates.m_uLength];
        if ( v14 != (MapStruct<unsigned long,AkStateLink> *)v15 )
        {
          do
          {
            if ( v14->key == v6 )
              break;
            ++v14;
          }
          while ( v14 != (MapStruct<unsigned long,AkStateLink> *)v15 );
          if ( v14 != (MapStruct<unsigned long,AkStateLink> *)v15 )
          {
            if ( (unsigned __int64)v14 < v15 - 24 )
              qmemcpy(
                v14,
                &v14[1],
                24
              * (((unsigned __int64)((unsigned __int64)(v15 - 24 - (_QWORD)v14 - 1)
                                   * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 4)
               + 1));
            --v4->m_mapStates.m_uLength;
          }
        }
      }
    }
  }
  if ( !v10 )
    return 16i64;
  v16.pState = v10;
  v16.ulStateID = v7;
  _mm_store_si128((__m128i *)&v16, (__m128i)v16);
  if ( CAkKeyArray<unsigned long,AkStateLink,2>::Set(&v4->m_mapStates, v6, &v16) )
  {
    CAkState::InitNotificationSystem(v10, v4->m_pOwner);
    if ( !v5 )
      return 1i64;
    ((void (*)(void))v4->m_pOwner->vfptr[13].__vecDelDtor)();
    result = 1i64;
  }
  else
  {
    v10->vfptr->Release((CAkIndexable *)&v10->vfptr);
    result = 52i64;
  }
  return result;
}

// File Line: 2673
// RVA: 0xA735D0
void __fastcall AkStateGroupChunk::RemoveState(AkStateGroupChunk *this, unsigned int in_ulStateID)
{
  MapStruct<unsigned long,AkStateLink> *v2; // rax
  unsigned int v3; // esi
  AkStateGroupChunk *v4; // rbx
  signed __int64 v5; // rdi
  CAkState **v6; // rdi
  MapStruct<unsigned long,AkStateLink> *v7; // rdi
  signed __int64 v8; // rax

  v2 = this->m_mapStates.m_pItems;
  v3 = in_ulStateID;
  v4 = this;
  v5 = (signed __int64)&v2[this->m_mapStates.m_uLength];
  if ( v2 != (MapStruct<unsigned long,AkStateLink> *)v5 )
  {
    do
    {
      if ( v2->key == in_ulStateID )
        break;
      ++v2;
    }
    while ( v2 != (MapStruct<unsigned long,AkStateLink> *)v5 );
    if ( v2 != (MapStruct<unsigned long,AkStateLink> *)v5 )
    {
      v6 = &v2->item.pState;
      if ( v2 != (MapStruct<unsigned long,AkStateLink> *)-8i64 )
      {
        CAkState::TermNotificationSystem(*v6);
        ((void (*)(void))(*v6)->vfptr->Release)();
        v7 = v4->m_mapStates.m_pItems;
        v8 = (signed __int64)&v7[v4->m_mapStates.m_uLength];
        if ( v7 != (MapStruct<unsigned long,AkStateLink> *)v8 )
        {
          do
          {
            if ( v7->key == v3 )
              break;
            ++v7;
          }
          while ( v7 != (MapStruct<unsigned long,AkStateLink> *)v8 );
          if ( v7 != (MapStruct<unsigned long,AkStateLink> *)v8 )
          {
            if ( (unsigned __int64)v7 < v8 - 24 )
              qmemcpy(
                v7,
                &v7[1],
                24
              * (((unsigned __int64)((unsigned __int64)(v8 - 24 - (_QWORD)v7 - 1)
                                   * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 4)
               + 1));
            --v4->m_mapStates.m_uLength;
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
  char *v1; // rdx
  AkStateGroupChunk *v2; // rsi
  signed __int64 v3; // rcx
  char *v4; // rbx
  signed __int64 v5; // rdi
  CAkTransition **v6; // rbx
  signed __int64 v7; // rdi

  v1 = this->m_values.m_pProps;
  v2 = this;
  if ( v1 )
  {
    v3 = (signed __int64)(v1 + 1);
    v4 = &v1[((unsigned __int8)*v1 + 4) & 0xFFFFFFFC];
  }
  else
  {
    v3 = 0i64;
    v4 = 0i64;
  }
  if ( v1 )
    v5 = (signed __int64)&v1[(unsigned __int8)*v1 + 1];
  else
    v5 = 0i64;
  if ( v3 != v5 )
  {
    v6 = (CAkTransition **)(v4 + 8);
    v7 = v5 - v3;
    do
    {
      if ( *v6 )
      {
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, *v6, (ITransitionable *)&v2->vfptr);
        *v6 = 0i64;
        ((void (__fastcall *)(CAkParameterNodeBase *, signed __int64))v2->m_pOwner->vfptr[9].Category)(
          v2->m_pOwner,
          3i64);
      }
      v6 += 2;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 2701
// RVA: 0xA74940
void __fastcall AkStateGroupChunk::TransUpdateValue(AkStateGroupChunk *this, __int64 in_eTarget, float in_fValue, bool in_bIsTerminated)
{
  char *v4; // r10
  bool v5; // si
  AkStateGroupChunk *v6; // rdi
  unsigned int v7; // er11
  int v8; // er8
  __int64 v9; // r9
  signed __int64 v10; // rbx

  v4 = this->m_values.m_pProps;
  v5 = in_bIsTerminated;
  v6 = this;
  if ( v4 )
  {
    v7 = (unsigned __int8)*v4;
    v8 = 0;
    while ( 1 )
    {
      v9 = (unsigned int)(v8 + 1);
      if ( v4[v9] == (_BYTE)in_eTarget )
        break;
      ++v8;
      if ( (unsigned int)v9 >= v7 )
        goto LABEL_5;
    }
    v10 = (signed __int64)&v4[16 * v8 + ((v7 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v10 = 0i64;
  }
  *(float *)v10 = in_fValue;
  if ( v5 )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, signed __int64))this->m_pOwner->vfptr[9].Category)(
      this->m_pOwner,
      3i64);
    *(_QWORD *)(v10 + 8) = 0i64;
  }
  ((void (__fastcall *)(CAkParameterNodeBase *, __int64))v6->m_pOwner->vfptr[12].Category)(v6->m_pOwner, in_eTarget);
}

