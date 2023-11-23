// File Line: 24
// RVA: 0xA931D0
void __fastcall SafeContinuationList::SafeContinuationList(
        SafeContinuationList *this,
        AkPBIParams *in_rPBIParams,
        CAkMultiPlayNode *in_pMultiPlayNode)
{
  ContParams *pContinuousParams; // rax
  CAkContinuationList *m_pT; // rdi
  CAkContinuationList *v7; // rcx
  CAkContinuationList *v8; // rsi
  CAkMultiPlayNode::ContParam *v9; // rax
  CAkMultiPlayNode::ContParam *v10; // rdi

  this->m_spBackupContinuationList.m_pT = 0i64;
  if ( in_rPBIParams->eType )
  {
    pContinuousParams = in_rPBIParams->pContinuousParams;
    m_pT = pContinuousParams->spContList.m_pT;
    if ( m_pT )
    {
      CAkContinuationList::AddRef(pContinuousParams->spContList.m_pT);
      v7 = this->m_spBackupContinuationList.m_pT;
      this->m_spBackupContinuationList.m_pT = m_pT;
      if ( v7 )
        CAkContinuationList::Release(v7);
      v8 = this->m_spBackupContinuationList.m_pT;
      v9 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Set<CAkContinuationList *>(
             &in_pMultiPlayNode->m_listContParameters,
             this->m_spBackupContinuationList.m_pT);
      v10 = v9;
      if ( v9 )
      {
        if ( !v9->uRefCount )
          CAkContinuationList::AddRef(v8);
        ++v10->uRefCount;
      }
    }
  }
}

// File Line: 39
// RVA: 0xA93120
void __fastcall AkContParamsAndPath::AkContParamsAndPath(AkContParamsAndPath *this, ContParams *in_pFrom)
{
  CAkPath *pPBPath; // rdx

  this->m_continuousParams.pPlayStopTransition = in_pFrom->pPlayStopTransition;
  this->m_continuousParams.pPauseResumeTransition = in_pFrom->pPauseResumeTransition;
  this->m_continuousParams.pPathInfo = in_pFrom->pPathInfo;
  this->m_continuousParams.bIsPlayStopTransitionFading = in_pFrom->bIsPlayStopTransitionFading;
  this->m_continuousParams.bIsPauseResumeTransitionFading = in_pFrom->bIsPauseResumeTransitionFading;
  this->m_continuousParams.spContList.m_pT = 0i64;
  this->m_continuousParams.ulPauseCount = in_pFrom->ulPauseCount;
  if ( g_pPathManager )
  {
    pPBPath = this->m_continuousParams.pPathInfo->pPBPath;
    if ( pPBPath )
      CAkPathManager::AddPotentialUser(g_pPathManager, pPBPath);
  }
}

// File Line: 50
// RVA: 0xA93290
void __fastcall AkContParamsAndPath::~AkContParamsAndPath(AkContParamsAndPath *this)
{
  CAkPath *pPBPath; // rdx
  CAkContinuationList *m_pT; // rcx

  if ( g_pPathManager )
  {
    pPBPath = this->m_continuousParams.pPathInfo->pPBPath;
    if ( pPBPath )
      CAkPathManager::RemovePotentialUser(g_pPathManager, pPBPath);
  }
  m_pT = this->m_continuousParams.spContList.m_pT;
  if ( m_pT )
  {
    CAkContinuationList::Release(m_pT);
    this->m_continuousParams.spContList.m_pT = 0i64;
  }
}

// File Line: 63
// RVA: 0xA93190
void __fastcall CAkMultiPlayNode::CAkMultiPlayNode(CAkMultiPlayNode *this, unsigned int in_ulID)
{
  CAkContainerBase::CAkContainerBase(this, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkMultiPlayNode::`vftable;
  this->m_listContParameters.m_pItems = 0i64;
  *(_QWORD *)&this->m_listContParameters.m_uLength = 0i64;
}

// File Line: 67
// RVA: 0xA932E0
void __fastcall CAkMultiPlayNode::~CAkMultiPlayNode(CAkMultiPlayNode *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkMultiPlayNode::`vftable;
  CAkContainerBase::~CAkContainerBase(this);
}

// File Line: 78
// RVA: 0xA93730
__int64 __fastcall CAkMultiPlayNode::Init(CAkMultiPlayNode *this)
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
  return 1i64;
}

// File Line: 84
// RVA: 0xA93960
void __fastcall CAkMultiPlayNode::Term(CAkMultiPlayNode *this)
{
  CAkMultiPlayNode::ContParam *m_pItems; // rdx

  m_pItems = this->m_listContParameters.m_pItems;
  if ( m_pItems )
  {
    this->m_listContParameters.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_listContParameters.m_pItems = 0i64;
    this->m_listContParameters.m_ulReserved = 0;
  }
}

// File Line: 89
// RVA: 0xA93590
__int64 __fastcall CAkMultiPlayNode::ContRefList(CAkMultiPlayNode *this, CAkContinuationList *in_pList)
{
  CAkMultiPlayNode::ContParam *v3; // rax
  CAkMultiPlayNode::ContParam *v4; // rbx

  v3 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Set<CAkContinuationList *>(
         &this->m_listContParameters,
         in_pList);
  v4 = v3;
  if ( !v3 )
    return 2i64;
  if ( !v3->uRefCount )
    CAkContinuationList::AddRef(in_pList);
  ++v4->uRefCount;
  return 1i64;
}

// File Line: 103
// RVA: 0xA934B0
void __fastcall CAkMultiPlayNode::ContGetList(
        CAkMultiPlayNode *this,
        CAkRegisteredObj *in_pList,
        CAkSmartPtr<CAkContinuationList> *io_spList)
{
  AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1> *p_m_listContParameters; // rbx
  CAkRTPCMgr::AkRTPCValue *v6; // rax
  CAkRTPCMgr::AkRTPCValue *v7; // rdi
  unsigned int fValue_low; // eax
  CAkContinuationList *pGameObj; // rsi
  CAkContinuationList *m_pT; // rcx
  unsigned __int64 v11; // rcx

  p_m_listContParameters = &this->m_listContParameters;
  v6 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_listContParameters,
         in_pList);
  v7 = v6;
  if ( v6 )
  {
    fValue_low = LODWORD(v6->fValue);
    if ( fValue_low > 1 )
    {
      LODWORD(v7->fValue) = fValue_low - 1;
    }
    else
    {
      if ( !((unsigned __int8 (__fastcall *)(CAkMultiPlayNode *))this->vfptr[21].__vecDelDtor)(this) )
      {
        pGameObj = (CAkContinuationList *)v7->pGameObj;
        if ( v7->pGameObj )
          CAkContinuationList::AddRef((CAkContinuationList *)v7->pGameObj);
        m_pT = io_spList->m_pT;
        io_spList->m_pT = pGameObj;
        if ( m_pT )
          CAkContinuationList::Release(m_pT);
      }
      CAkContinuationList::Release((CAkContinuationList *)v7->pGameObj);
      v11 = (unsigned __int64)&p_m_listContParameters->m_pItems[p_m_listContParameters->m_uLength - 1];
      if ( (unsigned __int64)v7 < v11 )
        qmemcpy(
          v7,
          &v7[1],
          8 * (((((v11 - (unsigned __int64)v7 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
      --p_m_listContParameters->m_uLength;
    }
  }
}

// File Line: 126
// RVA: 0xA935E0
__int64 __fastcall CAkMultiPlayNode::ContUnrefList(CAkMultiPlayNode *this, CAkRegisteredObj *in_pList)
{
  AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1> *p_m_listContParameters; // rbx
  CAkRTPCMgr::AkRTPCValue *v3; // rax
  CAkRTPCMgr::AkRTPCValue *v4; // rdi
  unsigned int fValue_low; // eax
  unsigned __int64 v6; // rcx

  p_m_listContParameters = &this->m_listContParameters;
  v3 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_listContParameters,
         in_pList);
  v4 = v3;
  if ( !v3 )
    return 1i64;
  fValue_low = LODWORD(v3->fValue);
  if ( fValue_low > 1 )
  {
    LODWORD(v4->fValue) = fValue_low - 1;
    return 1i64;
  }
  CAkContinuationList::Release((CAkContinuationList *)v4->pGameObj);
  v6 = (unsigned __int64)&p_m_listContParameters->m_pItems[p_m_listContParameters->m_uLength - 1];
  if ( (unsigned __int64)v4 < v6 )
    qmemcpy(
      v4,
      &v4[1],
      8 * (((((v6 - (unsigned __int64)v4 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
  --p_m_listContParameters->m_uLength;
  return 1i64;
}

// File Line: 148
// RVA: 0xA933A0
__int64 __fastcall CAkMultiPlayNode::AddMultiplayItem(
        CAkMultiPlayNode *this,
        AkContParamsAndPath *in_rContParams,
        AkPBIParams *in_rParams,
        SafeContinuationList *in_rSafeContList)
{
  CAkContinueListItem *v8; // rbx
  CAkMultiPlayNode *m_pT; // rcx
  CAkContinuationList *v10; // rax
  CAkContinuationList *m_pAlternateContList; // rdx
  CAkContinuationList *v13; // rcx

  v8 = AkArray<CAkContinueListItem,CAkContinueListItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(&in_rContParams->m_continuousParams.spContList.m_pT->m_listItems);
  if ( !v8 )
    goto LABEL_15;
  if ( !in_rParams->pContinuousParams->spContList.m_pT )
    Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)L"Playback failed, known issue WG-15729. Multiple s"
                                                                        "imultaneous playback in multiple continuous mode"
                                                                        " currently unsupported.");
  if ( in_rParams->pContinuousParams->spContList.m_pT )
  {
    v8->m_pAlternateContList = in_rSafeContList->m_spBackupContinuationList.m_pT;
    if ( this )
      this->vfptr->AddRef(this);
    m_pT = v8->m_pMultiPlayNode.m_pT;
    v8->m_pMultiPlayNode.m_pT = this;
    if ( m_pT )
      m_pT->vfptr->Release(m_pT);
    v10 = in_rParams->pContinuousParams->spContList.m_pT;
    if ( v10->m_listItems.m_uLength )
    {
      v8->m_LoopingInfo = v10->m_listItems.m_pItems->m_LoopingInfo;
    }
    else
    {
      *((_BYTE *)&v8->m_LoopingInfo + 2) &= 0xFCu;
      v8->m_LoopingInfo.lLoopCount = 1;
    }
    m_pAlternateContList = v8->m_pAlternateContList;
    if ( m_pAlternateContList )
      CAkMultiPlayNode::ContRefList(this, m_pAlternateContList);
    return 1i64;
  }
  else
  {
LABEL_15:
    v13 = in_rContParams->m_continuousParams.spContList.m_pT;
    in_rContParams->m_continuousParams.spContList.m_pT = 0i64;
    if ( v13 )
      CAkContinuationList::Release(v13);
    return 52i64;
  }
}

// File Line: 198
// RVA: 0xA93850
__int64 __fastcall CAkMultiPlayNode::PlayAndContinueAlternateMultiPlay(
        CAkMultiPlayNode *this,
        AkPBIParams *in_rPBIParams)
{
  ContParams *pContinuousParams; // r8
  unsigned int v5; // ebx
  CAkPath **p_pPBPath; // rdx
  char bIsPauseResumeTransitionFading; // al
  CAkPath *v8; // rdx
  CAkContinuationList *m_pT; // rcx
  unsigned int v10; // eax
  __int64 v12[2]; // [rsp+20h] [rbp-38h] BYREF
  CAkPath **v13; // [rsp+30h] [rbp-28h]
  bool bIsPlayStopTransitionFading; // [rsp+38h] [rbp-20h]
  char v15; // [rsp+39h] [rbp-1Fh]
  CAkSmartPtr<CAkContinuationList> io_spList; // [rsp+40h] [rbp-18h] BYREF
  unsigned int ulPauseCount; // [rsp+48h] [rbp-10h]

  pContinuousParams = in_rPBIParams->pContinuousParams;
  v5 = 2;
  v12[0] = (__int64)pContinuousParams->pPlayStopTransition;
  v12[1] = (__int64)pContinuousParams->pPauseResumeTransition;
  p_pPBPath = &pContinuousParams->pPathInfo->pPBPath;
  v13 = p_pPBPath;
  bIsPlayStopTransitionFading = pContinuousParams->bIsPlayStopTransitionFading;
  bIsPauseResumeTransitionFading = pContinuousParams->bIsPauseResumeTransitionFading;
  io_spList.m_pT = 0i64;
  v15 = bIsPauseResumeTransitionFading;
  ulPauseCount = pContinuousParams->ulPauseCount;
  if ( g_pPathManager )
  {
    v8 = *p_pPBPath;
    if ( v8 )
      CAkPathManager::AddPotentialUser(g_pPathManager, v8);
  }
  CAkMultiPlayNode::ContGetList(this, (CAkRegisteredObj *)in_rPBIParams->pContinuousParams->spContList.m_pT, &io_spList);
  m_pT = io_spList.m_pT;
  if ( io_spList.m_pT )
  {
    in_rPBIParams->pContinuousParams = (ContParams *)v12;
    v10 = ((__int64 (__fastcall *)(CAkMultiPlayNode *, AkPBIParams *))this->vfptr[20].AddRef)(this, in_rPBIParams);
    m_pT = io_spList.m_pT;
    v5 = v10;
    if ( v10 == 3 )
      v5 = 1;
  }
  if ( g_pPathManager && *v13 )
  {
    CAkPathManager::RemovePotentialUser(g_pPathManager, *v13);
    m_pT = io_spList.m_pT;
  }
  if ( m_pT )
    CAkContinuationList::Release(m_pT);
  return v5;
}

