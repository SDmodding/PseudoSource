// File Line: 24
// RVA: 0xA931D0
void __fastcall SafeContinuationList::SafeContinuationList(SafeContinuationList *this, AkPBIParams *in_rPBIParams, CAkMultiPlayNode *in_pMultiPlayNode)
{
  CAkMultiPlayNode *v3; // rbp
  SafeContinuationList *v4; // rbx
  ContParams *v5; // rax
  CAkContinuationList *v6; // rdi
  CAkContinuationList *v7; // rcx
  CAkContinuationList *v8; // rsi
  CAkMultiPlayNode::ContParam *v9; // rax
  CAkMultiPlayNode::ContParam *v10; // rdi

  this->m_spBackupContinuationList.m_pT = 0i64;
  v3 = in_pMultiPlayNode;
  v4 = this;
  if ( in_rPBIParams->eType )
  {
    v5 = in_rPBIParams->pContinuousParams;
    v6 = v5->spContList.m_pT;
    if ( v6 )
    {
      CAkContinuationList::AddRef(v5->spContList.m_pT);
      v7 = v4->m_spBackupContinuationList.m_pT;
      v4->m_spBackupContinuationList.m_pT = v6;
      if ( v7 )
        CAkContinuationList::Release(v7);
      v8 = v4->m_spBackupContinuationList.m_pT;
      v9 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Set<CAkContinuationList *>(
             &v3->m_listContParameters,
             v4->m_spBackupContinuationList.m_pT);
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
  CAkPath *v2; // rdx

  this->m_continuousParams.pPlayStopTransition = in_pFrom->pPlayStopTransition;
  this->m_continuousParams.pPauseResumeTransition = in_pFrom->pPauseResumeTransition;
  this->m_continuousParams.pPathInfo = in_pFrom->pPathInfo;
  this->m_continuousParams.bIsPlayStopTransitionFading = in_pFrom->bIsPlayStopTransitionFading;
  this->m_continuousParams.bIsPauseResumeTransitionFading = in_pFrom->bIsPauseResumeTransitionFading;
  this->m_continuousParams.spContList.m_pT = 0i64;
  this->m_continuousParams.ulPauseCount = in_pFrom->ulPauseCount;
  if ( g_pPathManager )
  {
    v2 = this->m_continuousParams.pPathInfo->pPBPath;
    if ( v2 )
      CAkPathManager::AddPotentialUser(g_pPathManager, v2);
  }
}

// File Line: 50
// RVA: 0xA93290
void __fastcall AkContParamsAndPath::~AkContParamsAndPath(AkContParamsAndPath *this)
{
  AkContParamsAndPath *v1; // rbx
  CAkPath *v2; // rdx
  CAkContinuationList *v3; // rcx

  v1 = this;
  if ( g_pPathManager )
  {
    v2 = this->m_continuousParams.pPathInfo->pPBPath;
    if ( v2 )
      CAkPathManager::RemovePotentialUser(g_pPathManager, v2);
  }
  v3 = v1->m_continuousParams.spContList.m_pT;
  if ( v3 )
  {
    CAkContinuationList::Release(v3);
    v1->m_continuousParams.spContList.m_pT = 0i64;
  }
}

// File Line: 63
// RVA: 0xA93190
void __fastcall CAkMultiPlayNode::CAkMultiPlayNode(CAkMultiPlayNode *this, unsigned int in_ulID)
{
  CAkMultiPlayNode *v2; // rbx

  v2 = this;
  CAkContainerBase::CAkContainerBase((CAkContainerBase *)&this->vfptr, in_ulID);
  v2->vfptr = (CAkIndexableVtbl *)&CAkMultiPlayNode::`vftable;
  v2->m_listContParameters.m_pItems = 0i64;
  *(_QWORD *)&v2->m_listContParameters.m_uLength = 0i64;
}

// File Line: 67
// RVA: 0xA932E0
void __fastcall CAkMultiPlayNode::~CAkMultiPlayNode(CAkMultiPlayNode *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkMultiPlayNode::`vftable;
  CAkContainerBase::~CAkContainerBase((CAkContainerBase *)&this->vfptr);
}

// File Line: 78
// RVA: 0xA93730
signed __int64 __fastcall CAkMultiPlayNode::Init(CAkMultiPlayNode *this)
{
  CAkMultiPlayNode *v1; // rbx
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
  return 1i64;
}

// File Line: 84
// RVA: 0xA93960
void __fastcall CAkMultiPlayNode::Term(CAkMultiPlayNode *this)
{
  CAkMultiPlayNode::ContParam *v1; // rdx
  CAkMultiPlayNode *v2; // rbx

  v1 = this->m_listContParameters.m_pItems;
  v2 = this;
  if ( v1 )
  {
    this->m_listContParameters.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_listContParameters.m_pItems = 0i64;
    v2->m_listContParameters.m_ulReserved = 0;
  }
}

// File Line: 89
// RVA: 0xA93590
signed __int64 __fastcall CAkMultiPlayNode::ContRefList(CAkMultiPlayNode *this, CAkContinuationList *in_pList)
{
  CAkContinuationList *v2; // rdi
  CAkMultiPlayNode::ContParam *v3; // rax
  CAkMultiPlayNode::ContParam *v4; // rbx

  v2 = in_pList;
  v3 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Set<CAkContinuationList *>(
         &this->m_listContParameters,
         in_pList);
  v4 = v3;
  if ( !v3 )
    return 2i64;
  if ( !v3->uRefCount )
    CAkContinuationList::AddRef(v2);
  ++v4->uRefCount;
  return 1i64;
}

// File Line: 103
// RVA: 0xA934B0
void __fastcall CAkMultiPlayNode::ContGetList(CAkMultiPlayNode *this, CAkContinuationList *in_pList, CAkSmartPtr<CAkContinuationList> *io_spList)
{
  AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1> *v3; // rbx
  CAkMultiPlayNode *v4; // rsi
  CAkSmartPtr<CAkContinuationList> *v5; // r14
  CAkRTPCMgr::AkRTPCValue *v6; // rax
  CAkRTPCMgr::AkRTPCValue *v7; // rdi
  unsigned int v8; // eax
  CAkContinuationList *v9; // rsi
  CAkContinuationList *v10; // rcx
  unsigned __int64 v11; // rcx

  v3 = &this->m_listContParameters;
  v4 = this;
  v5 = io_spList;
  v6 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_listContParameters,
         (CAkRegisteredObj *)in_pList);
  v7 = v6;
  if ( v6 )
  {
    v8 = LODWORD(v6->fValue);
    if ( v8 > 1 )
    {
      LODWORD(v7->fValue) = v8 - 1;
    }
    else
    {
      if ( !((unsigned __int8 (__fastcall *)(CAkMultiPlayNode *))v4->vfptr[21].__vecDelDtor)(v4) )
      {
        v9 = (CAkContinuationList *)v7->pGameObj;
        if ( v7->pGameObj )
          CAkContinuationList::AddRef((CAkContinuationList *)v7->pGameObj);
        v10 = v5->m_pT;
        v5->m_pT = v9;
        if ( v10 )
          CAkContinuationList::Release(v10);
      }
      CAkContinuationList::Release((CAkContinuationList *)v7->pGameObj);
      v11 = (unsigned __int64)&v3->m_pItems[v3->m_uLength - 1];
      if ( (unsigned __int64)v7 < v11 )
        qmemcpy(
          v7,
          &v7[1],
          8 * (((((v11 - (unsigned __int64)v7 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
      --v3->m_uLength;
    }
  }
}

// File Line: 126
// RVA: 0xA935E0
signed __int64 __fastcall CAkMultiPlayNode::ContUnrefList(CAkMultiPlayNode *this, CAkContinuationList *in_pList)
{
  AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1> *v2; // rbx
  CAkRTPCMgr::AkRTPCValue *v3; // rax
  CAkRTPCMgr::AkRTPCValue *v4; // rdi
  unsigned int v5; // eax
  unsigned __int64 v6; // rcx

  v2 = &this->m_listContParameters;
  v3 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_listContParameters,
         (CAkRegisteredObj *)in_pList);
  v4 = v3;
  if ( !v3 )
    return 1i64;
  v5 = LODWORD(v3->fValue);
  if ( v5 > 1 )
  {
    LODWORD(v4->fValue) = v5 - 1;
    return 1i64;
  }
  CAkContinuationList::Release((CAkContinuationList *)v4->pGameObj);
  v6 = (unsigned __int64)&v2->m_pItems[v2->m_uLength - 1];
  if ( (unsigned __int64)v4 < v6 )
    qmemcpy(
      v4,
      &v4[1],
      8 * (((((v6 - (unsigned __int64)v4 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
  --v2->m_uLength;
  return 1i64;
}

// File Line: 148
// RVA: 0xA933A0
signed __int64 __fastcall CAkMultiPlayNode::AddMultiplayItem(CAkMultiPlayNode *this, AkContParamsAndPath *in_rContParams, AkPBIParams *in_rParams, SafeContinuationList *in_rSafeContList)
{
  CAkMultiPlayNode *v4; // rdi
  SafeContinuationList *v5; // r14
  AkPBIParams *v6; // rbp
  AkContParamsAndPath *v7; // rsi
  CAkContinueListItem *v8; // rbx
  CAkMultiPlayNode *v9; // rcx
  CAkContinuationList *v10; // rax
  CAkContinuationList *v11; // rdx
  signed __int64 result; // rax
  CAkContinuationList *v13; // rcx

  v4 = this;
  v5 = in_rSafeContList;
  v6 = in_rParams;
  v7 = in_rContParams;
  v8 = AkArray<CAkContinueListItem,CAkContinueListItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(&in_rContParams->m_continuousParams.spContList.m_pT->m_listItems);
  if ( !v8 )
    goto LABEL_20;
  if ( !v6->pContinuousParams->spContList.m_pT )
    Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)L"Playback failed, known issue WG-15729. Multiple s"
                                                                        "imultaneous playback in multiple continuous mode"
                                                                        " currently unsupported.");
  if ( v6->pContinuousParams->spContList.m_pT )
  {
    v8->m_pAlternateContList = v5->m_spBackupContinuationList.m_pT;
    if ( v4 )
      v4->vfptr->AddRef((CAkIndexable *)&v4->vfptr);
    v9 = v8->m_pMultiPlayNode.m_pT;
    v8->m_pMultiPlayNode.m_pT = v4;
    if ( v9 )
      ((void (*)(void))v9->vfptr->Release)();
    v10 = v6->pContinuousParams->spContList.m_pT;
    if ( v10->m_listItems.m_uLength )
    {
      v8->m_LoopingInfo = v10->m_listItems.m_pItems->m_LoopingInfo;
    }
    else
    {
      *((_BYTE *)&v8->m_LoopingInfo + 2) &= 0xFCu;
      v8->m_LoopingInfo.lLoopCount = 1;
    }
    v11 = v8->m_pAlternateContList;
    if ( v11 )
      CAkMultiPlayNode::ContRefList(v4, v11);
    result = 1i64;
  }
  else
  {
LABEL_20:
    v13 = v7->m_continuousParams.spContList.m_pT;
    v7->m_continuousParams.spContList.m_pT = 0i64;
    if ( v13 )
      CAkContinuationList::Release(v13);
    result = 52i64;
  }
  return result;
}

// File Line: 198
// RVA: 0xA93850
__int64 __fastcall CAkMultiPlayNode::PlayAndContinueAlternateMultiPlay(CAkMultiPlayNode *this, AkPBIParams *in_rPBIParams)
{
  ContParams *v2; // r8
  AkPBIParams *v3; // rdi
  CAkMultiPlayNode *v4; // rsi
  unsigned int v5; // ebx
  CAkPath **v6; // rdx
  char v7; // al
  CAkPath *v8; // rdx
  CAkContinuationList *v9; // rcx
  unsigned int v10; // eax
  CAkTransition *v12; // [rsp+20h] [rbp-38h]
  CAkTransition *v13; // [rsp+28h] [rbp-30h]
  CAkPath **v14; // [rsp+30h] [rbp-28h]
  bool v15; // [rsp+38h] [rbp-20h]
  char v16; // [rsp+39h] [rbp-1Fh]
  CAkSmartPtr<CAkContinuationList> io_spList; // [rsp+40h] [rbp-18h]
  unsigned int v18; // [rsp+48h] [rbp-10h]

  v2 = in_rPBIParams->pContinuousParams;
  v3 = in_rPBIParams;
  v4 = this;
  v5 = 2;
  v12 = v2->pPlayStopTransition;
  v13 = v2->pPauseResumeTransition;
  v6 = &v2->pPathInfo->pPBPath;
  v14 = &v2->pPathInfo->pPBPath;
  v15 = v2->bIsPlayStopTransitionFading;
  v7 = v2->bIsPauseResumeTransitionFading;
  io_spList.m_pT = 0i64;
  v16 = v7;
  v18 = v2->ulPauseCount;
  if ( g_pPathManager )
  {
    v8 = *v6;
    if ( v8 )
      CAkPathManager::AddPotentialUser(g_pPathManager, v8);
  }
  CAkMultiPlayNode::ContGetList(v4, v3->pContinuousParams->spContList.m_pT, &io_spList);
  v9 = io_spList.m_pT;
  if ( io_spList.m_pT )
  {
    v3->pContinuousParams = (ContParams *)&v12;
    v10 = ((__int64 (__fastcall *)(CAkMultiPlayNode *, AkPBIParams *))v4->vfptr[20].AddRef)(v4, v3);
    v9 = io_spList.m_pT;
    v5 = v10;
    if ( v10 == 3 )
      v5 = 1;
  }
  if ( g_pPathManager && *v14 )
  {
    CAkPathManager::RemovePotentialUser(g_pPathManager, *v14);
    v9 = io_spList.m_pT;
  }
  if ( v9 )
    CAkContinuationList::Release(v9);
  return v5;
}

