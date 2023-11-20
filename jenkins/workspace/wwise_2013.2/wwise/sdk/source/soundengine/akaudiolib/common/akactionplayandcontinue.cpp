// File Line: 50
// RVA: 0xA78090
void __fastcall CAkActionPlayAndContinue::CAkActionPlayAndContinue(CAkActionPlayAndContinue *this, AkActionType in_eActionType, unsigned int in_ulID, CAkSmartPtr<CAkContinuationList> *in_spContList)
{
  CAkSmartPtr<CAkContinuationList> *v4; // rbx
  CAkActionPlayAndContinue *v5; // rdi
  CAkContinuationList *v6; // rcx

  v4 = in_spContList;
  v5 = this;
  CAkActionPlay::CAkActionPlay((CAkActionPlay *)&this->vfptr, in_eActionType, in_ulID);
  v5->vfptr = (CAkIndexableVtbl *)&CAkActionPlayAndContinue::`vftable;
  *((_BYTE *)&v5->m_PBTrans + 16) &= 0xFCu;
  v5->m_PBTrans.pvPSTrans = 0i64;
  v5->m_PBTrans.pvPRTrans = 0i64;
  v6 = v4->m_pT;
  v5->m_spContList = (CAkSmartPtr<CAkContinuationList>)v4->m_pT;
  if ( v6 )
    CAkContinuationList::AddRef(v6);
  v5->m_PlayHistory.arrayIsContinuous.m_iBitArray = 0;
  v5->m_pPreviousPBI = 0i64;
  *(_QWORD *)&v5->m_FadeOutTimeForLast = 0i64;
  v5->m_SA_PBIID = 0;
  v5->m_bSkipDelay = 0;
  v5->m_pTransitionOwner = 0i64;
  v5->m_pInstigator = 0i64;
  v5->m_ulPauseCount = 0;
  v5->m_pPathOwner = 0i64;
  v5->m_PlayHistory.HistArray.uiArraySize = 0;
  v5->m_PathInfo.pPBPath = 0i64;
  v5->m_PathInfo.PathOwnerID = 0;
  *(_WORD *)&v5->m_bNeedNotifyDelay = 1;
  v5->m_ePBIType = 1;
}

// File Line: 57
// RVA: 0xA78140
void __fastcall CAkActionPlayAndContinue::~CAkActionPlayAndContinue(CAkActionPlayAndContinue *this)
{
  CAkTransition *v1; // rdx
  CAkActionPlayAndContinue *v2; // rbx
  AkPendingAction *v3; // r8
  CAkTransition *v4; // rdx
  ITransitionable *v5; // r8
  CAkPath *v6; // rdx
  CAkParameterNodeBase *v7; // rcx
  CAkPBIAware *v8; // rcx
  CAkContinuationList *v9; // rcx

  v1 = this->m_PBTrans.pvPSTrans;
  v2 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkActionPlayAndContinue::`vftable;
  if ( v1 )
  {
    v3 = this->m_pTransitionOwner;
    if ( v3 )
      CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v1, (ITransitionable *)&v3->vfptr);
  }
  v4 = v2->m_PBTrans.pvPRTrans;
  *((_BYTE *)&v2->m_PBTrans + 16) &= 0xFEu;
  v2->m_PBTrans.pvPSTrans = 0i64;
  if ( v4 )
  {
    v5 = (ITransitionable *)&v2->m_pTransitionOwner->vfptr;
    if ( v5 )
      CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v4, v5);
  }
  v6 = v2->m_PathInfo.pPBPath;
  *((_BYTE *)&v2->m_PBTrans + 16) &= 0xFDu;
  v2->m_PBTrans.pvPRTrans = 0i64;
  if ( v6 )
    CAkPathManager::RemovePotentialUser(g_pPathManager, v6);
  v7 = v2->m_pPathOwner;
  if ( v7 )
  {
    ((void (*)(void))v7->vfptr->Release)();
    v2->m_pPathOwner = 0i64;
  }
  v8 = v2->m_pInstigator;
  if ( v8 )
    ((void (*)(void))v8->vfptr->Release)();
  v9 = v2->m_spContList.m_pT;
  if ( v9 )
  {
    CAkContinuationList::Release(v9);
    v2->m_spContList.m_pT = 0i64;
  }
  CAkActionPlay::~CAkActionPlay((CAkActionPlay *)&v2->vfptr);
}

// File Line: 77
// RVA: 0xA78420
void __fastcall CAkActionPlayAndContinue::Create(AkActionType in_eActionType, unsigned int in_ulID, CAkSmartPtr<CAkContinuationList> *in_spContList)
{
  AkActionType v3; // esi
  unsigned int v4; // edi
  CAkSmartPtr<CAkContinuationList> *v5; // rbx
  CAkActionPlayAndContinue *v6; // rax
  CAkAction *v7; // rax

  v3 = in_eActionType;
  v4 = in_ulID;
  v5 = in_spContList;
  v6 = (CAkActionPlayAndContinue *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xF8ui64);
  if ( v6 )
  {
    CAkActionPlayAndContinue::CAkActionPlayAndContinue(v6, v3, v4, v5);
    if ( v7 )
      CAkAction::AddToIndex(v7);
  }
}

// File Line: 92
// RVA: 0xA78490
signed __int64 __fastcall CAkActionPlayAndContinue::Execute(CAkActionPlayAndContinue *this, AkPendingAction *in_pAction)
{
  int v2; // eax
  AkCurveInterpolation v3; // er8
  CAkActionPlayAndContinue *v4; // rbx
  CAkContinuousPBI *v5; // rcx
  AkPendingAction *v6; // r13
  unsigned int v7; // esi
  CAkParameterNode *v8; // rdi
  unsigned __int8 v9; // cl
  CAkContinuationList *v10; // r14
  CAkPath **v11; // r15
  CAkContinuationList *v12; // rdx
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  AkPBIParams::ePBIType v15; // eax
  CAkPBIAware *v16; // rax
  __int128 v17; // xmm0
  __int128 v18; // xmm1
  CAkRegisteredObj *v19; // rax
  AkExternalSourceArray *v20; // rax
  unsigned int v21; // eax
  __int64 v22; // r8
  __int64 v23; // r9
  CAkContinuationList *v24; // rcx
  CAkPath *v25; // rdx
  CAkParameterNodeBase *v26; // rcx
  CAkTransition *v28; // [rsp+20h] [rbp-99h]
  CAkTransition *v29; // [rsp+28h] [rbp-91h]
  AkPathInfo *v30; // [rsp+30h] [rbp-89h]
  char v31; // [rsp+38h] [rbp-81h]
  char v32; // [rsp+39h] [rbp-80h]
  CAkContinuationList *v33; // [rsp+40h] [rbp-79h]
  unsigned int v34; // [rsp+48h] [rbp-71h]
  AkPBIParams in_rPBIParams; // [rsp+50h] [rbp-69h]
  TransParams in_transParams; // [rsp+120h] [rbp+67h]

  v2 = this->m_FadeOutTimeForLast;
  v3 = 4;
  v4 = this;
  v5 = this->m_pPreviousPBI;
  v6 = in_pAction;
  in_transParams.TransitionTime = v2;
  in_transParams.eFadeCurve = 4;
  v7 = 1;
  if ( v5 )
  {
    if ( (*((_BYTE *)v5 + 632) & 0xF) == 2 )
      v3 = 1;
    in_transParams.eFadeCurve = v3;
    CAkPBI::_Stop((CAkPBI *)&v5->vfptr, &in_transParams, 1);
  }
  v8 = (CAkParameterNode *)CAkAction::GetAndRefTarget((CAkAction *)&v4->vfptr);
  if ( !v8 )
    return 15i64;
  v9 = *((_BYTE *)&v4->m_PBTrans + 16);
  v28 = v4->m_PBTrans.pvPSTrans;
  v10 = v4->m_spContList.m_pT;
  v29 = v4->m_PBTrans.pvPRTrans;
  v34 = v4->m_ulPauseCount;
  v11 = &v4->m_PathInfo.pPBPath;
  v12 = 0i64;
  v32 = (v9 >> 1) & 1;
  v33 = 0i64;
  v30 = &v4->m_PathInfo;
  v31 = v9 & 1;
  if ( v10 )
  {
    CAkContinuationList::AddRef(v10);
    v12 = v33;
  }
  v33 = v10;
  if ( v12 )
    CAkContinuationList::Release(v12);
  v13 = *(_OWORD *)&v4->m_PlayHistory.HistArray.uiArraySize;
  v14 = *(_OWORD *)&v4->m_PlayHistory.HistArray.aCntrHist[6];
  in_rPBIParams.bSkipDelay = v4->m_bSkipDelay;
  v15 = v4->m_ePBIType;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.uiArraySize = v13;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[6] = v14;
  in_rPBIParams.eType = v15;
  v16 = v4->m_pInstigator;
  in_rPBIParams.bTargetFeedback = 0;
  v17 = *(_OWORD *)&v4->m_PlayHistory.HistArray.aCntrHist[14];
  v18 = *(_OWORD *)&v4->m_PlayHistory.HistArray.aCntrHist[22];
  in_rPBIParams.pInstigator = v16;
  v19 = v6->pGameObj;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[14] = v17;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[22] = v18;
  *(_QWORD *)&v17 = *(_QWORD *)&v4->m_PlayHistory.HistArray.aCntrHist[30];
  in_rPBIParams.pGameObj = v19;
  LODWORD(v19) = v6->UserParam.m_PlayingID;
  *(_QWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[30] = v17;
  in_rPBIParams.userParams.m_PlayingID = (unsigned int)v19;
  in_rPBIParams.userParams.m_CustomParam.customParam = v6->UserParam.m_CustomParam.customParam;
  in_rPBIParams.userParams.m_CustomParam.ui32Reserved = v6->UserParam.m_CustomParam.ui32Reserved;
  v20 = v6->UserParam.m_CustomParam.pExternalSrcs;
  if ( v20 )
    ++v20->m_cRefCount;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = v20;
  in_rPBIParams.ePlaybackState = v4->m_InitialPlaybackState;
  in_rPBIParams.uFrameOffset = v6->LaunchFrameOffset;
  in_rPBIParams.bIsFirst = v4->m_bIsfirstPlay;
  in_rPBIParams.sequenceID = v4->m_SA_PBIID;
  in_rPBIParams.pContinuousParams = (ContParams *)&v28;
  in_rPBIParams.pTransitionParameters = &in_transParams;
  v21 = CAkParameterNode::HandleInitialDelay(v8, &in_rPBIParams);
  if ( v21 != 3 )
  {
    if ( v21 == 1 )
      v21 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))v8->vfptr[19].Category)(v8, &in_rPBIParams);
    v7 = v21;
  }
  ++CAkLEngineCmds::m_ulPlayEventID;
  v24 = v4->m_spContList.m_pT;
  v4->m_spContList.m_pT = 0i64;
  if ( v24 )
    CAkContinuationList::Release(v24);
  v25 = *v11;
  if ( *v11 )
  {
    CAkPathManager::RemovePotentialUser(g_pPathManager, v25);
    *v11 = 0i64;
    v4->m_PathInfo.PathOwnerID = 0;
  }
  v26 = v4->m_pPathOwner;
  if ( v26 )
  {
    ((void (__cdecl *)(CAkParameterNodeBase *, CAkPath *, __int64, __int64))v26->vfptr->Release)(v26, v25, v22, v23);
    v4->m_pPathOwner = 0i64;
  }
  v8->vfptr->Release((CAkIndexable *)&v8->vfptr);
  if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
    AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
  if ( v33 )
    CAkContinuationList::Release(v33);
  return v7;
}

// File Line: 178
// RVA: 0xA78A40
signed __int64 __fastcall CAkActionPlayAndContinue::SetPlayStopTransition(CAkActionPlayAndContinue *this, CAkTransition *in_pTransition, bool in_bTransitionFading, AkPendingAction *in_pTransitionOwner)
{
  CAkTransition *v4; // rsi
  CAkTransition *v5; // rdx
  bool v6; // di
  CAkActionPlayAndContinue *v7; // rbx
  signed __int64 result; // rax

  v4 = in_pTransition;
  v5 = this->m_PBTrans.pvPSTrans;
  v6 = in_bTransitionFading;
  v7 = this;
  this->m_pTransitionOwner = in_pTransitionOwner;
  if ( v5 && in_pTransitionOwner )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v5, (ITransitionable *)&in_pTransitionOwner->vfptr);
  *((_BYTE *)&v7->m_PBTrans + 16) &= 0xFEu;
  v7->m_PBTrans.pvPSTrans = 0i64;
  if ( !v4
    || (result = CAkTransitionManager::AddTransitionUser(
                   g_pTransitionManager,
                   v4,
                   (ITransitionable *)&v7->m_pTransitionOwner->vfptr),
        (_DWORD)result == 1) )
  {
    *((_BYTE *)&v7->m_PBTrans + 16) &= 0xFEu;
    v7->m_PBTrans.pvPSTrans = v4;
    *((_BYTE *)&v7->m_PBTrans + 16) |= v6;
    result = 1i64;
  }
  return result;
}

// File Line: 197
// RVA: 0xA789A0
signed __int64 __fastcall CAkActionPlayAndContinue::SetPauseResumeTransition(CAkActionPlayAndContinue *this, CAkTransition *in_pTransition, bool in_bTransitionFading, AkPendingAction *in_pTransitionOwner)
{
  CAkTransition *v4; // rsi
  CAkTransition *v5; // rdx
  bool v6; // di
  CAkActionPlayAndContinue *v7; // rbx
  signed __int64 result; // rax

  v4 = in_pTransition;
  v5 = this->m_PBTrans.pvPRTrans;
  v6 = in_bTransitionFading;
  v7 = this;
  this->m_pTransitionOwner = in_pTransitionOwner;
  if ( v5 && in_pTransitionOwner )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v5, (ITransitionable *)&in_pTransitionOwner->vfptr);
  *((_BYTE *)&v7->m_PBTrans + 16) &= 0xFDu;
  v7->m_PBTrans.pvPRTrans = 0i64;
  if ( !v4
    || (result = CAkTransitionManager::AddTransitionUser(
                   g_pTransitionManager,
                   v4,
                   (ITransitionable *)&v7->m_pTransitionOwner->vfptr),
        (_DWORD)result == 1) )
  {
    *((_BYTE *)&v7->m_PBTrans + 16) &= 0xFDu;
    v7->m_PBTrans.pvPRTrans = v4;
    result = 1i64;
    *((_BYTE *)&v7->m_PBTrans + 16) |= 2 * v6;
  }
  return result;
}

// File Line: 236
// RVA: 0xA78910
void __fastcall CAkActionPlayAndContinue::SetPathInfo(CAkActionPlayAndContinue *this, AkPathInfo *in_pPathInfo)
{
  AkPathInfo *v2; // rdi
  CAkPath *v3; // rdx
  CAkActionPlayAndContinue *v4; // rbx
  CAkParameterNodeBase *v5; // rcx

  v2 = in_pPathInfo;
  this->m_PathInfo.pPBPath = 0i64;
  this->m_PathInfo.PathOwnerID = 0;
  v3 = in_pPathInfo->pPBPath;
  v4 = this;
  if ( v3 )
    CAkPathManager::AddPotentialUser(g_pPathManager, v3);
  v5 = v4->m_pPathOwner;
  v4->m_PathInfo.pPBPath = v2->pPBPath;
  v4->m_PathInfo.PathOwnerID = v2->PathOwnerID;
  if ( v5 )
  {
    ((void (*)(void))v5->vfptr->Release)();
    v4->m_pPathOwner = 0i64;
  }
  v4->m_pPathOwner = (CAkParameterNodeBase *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v2->PathOwnerID, 0);
}

// File Line: 276
// RVA: 0xA78720
void __fastcall CAkActionPlayAndContinue::GetHistArray(CAkActionPlayAndContinue *this, AkCntrHistArray *out_rHistArray)
{
  out_rHistArray->uiArraySize = this->m_PlayHistory.HistArray.uiArraySize;
  *(_DWORD *)out_rHistArray->aCntrHist = *(_DWORD *)this->m_PlayHistory.HistArray.aCntrHist;
  *(_DWORD *)&out_rHistArray->aCntrHist[2] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[2];
  *(_DWORD *)&out_rHistArray->aCntrHist[4] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[4];
  *(_DWORD *)&out_rHistArray->aCntrHist[6] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[6];
  *(_DWORD *)&out_rHistArray->aCntrHist[8] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[8];
  *(_DWORD *)&out_rHistArray->aCntrHist[10] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[10];
  *(_DWORD *)&out_rHistArray->aCntrHist[12] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[12];
  *(_DWORD *)&out_rHistArray->aCntrHist[14] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[14];
  *(_DWORD *)&out_rHistArray->aCntrHist[16] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[16];
  *(_DWORD *)&out_rHistArray->aCntrHist[18] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[18];
  *(_DWORD *)&out_rHistArray->aCntrHist[20] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[20];
  *(_DWORD *)&out_rHistArray->aCntrHist[22] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[22];
  *(_DWORD *)&out_rHistArray->aCntrHist[24] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[24];
  *(_DWORD *)&out_rHistArray->aCntrHist[26] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[26];
  *(_DWORD *)&out_rHistArray->aCntrHist[28] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[28];
  *(_DWORD *)&out_rHistArray->aCntrHist[30] = *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[30];
}

// File Line: 281
// RVA: 0xA78830
void __fastcall CAkActionPlayAndContinue::SetHistory(CAkActionPlayAndContinue *this, PlayHistory *in_rPlayHistory)
{
  this->m_PlayHistory.HistArray.uiArraySize = in_rPlayHistory->HistArray.uiArraySize;
  *(_DWORD *)this->m_PlayHistory.HistArray.aCntrHist = *(_DWORD *)in_rPlayHistory->HistArray.aCntrHist;
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[2] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[2];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[4] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[4];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[6] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[6];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[8] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[8];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[10] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[10];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[12] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[12];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[14] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[14];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[16] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[16];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[18] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[18];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[20] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[20];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[22] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[22];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[24] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[24];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[26] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[26];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[28] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[28];
  *(_DWORD *)&this->m_PlayHistory.HistArray.aCntrHist[30] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[30];
  this->m_PlayHistory.arrayIsContinuous.m_iBitArray = in_rPlayHistory->arrayIsContinuous.m_iBitArray;
}

// File Line: 286
// RVA: 0xA788D0
void __fastcall CAkActionPlayAndContinue::SetInitialPlaybackState(CAkActionPlayAndContinue *this, AkPlaybackState in_eInitialPlaybackState)
{
  this->m_InitialPlaybackState = in_eInitialPlaybackState;
}

// File Line: 291
// RVA: 0xA788E0
void __fastcall CAkActionPlayAndContinue::SetInstigator(CAkActionPlayAndContinue *this, CAkPBIAware *in_pInstigator)
{
  this->m_pInstigator = in_pInstigator;
  in_pInstigator->vfptr->AddRef((CAkIndexable *)in_pInstigator);
}

// File Line: 298
// RVA: 0xA787B0
_BOOL8 __fastcall CAkActionPlayAndContinue::NeedNotifyDelay(CAkActionPlayAndContinue *this)
{
  return this->m_bNeedNotifyDelay;
}

// File Line: 303
// RVA: 0xA78900
void __fastcall CAkActionPlayAndContinue::SetIsFirstPlay(CAkActionPlayAndContinue *this, bool in_bIsFirstPlay)
{
  this->m_bIsfirstPlay = in_bIsFirstPlay;
}

// File Line: 313
// RVA: 0xA78810
void __fastcall CAkActionPlayAndContinue::SetFadeBack(CAkActionPlayAndContinue *this, CAkContinuousPBI *in_pPBIToNotify, int in_CrossFadeTime)
{
  this->m_pPreviousPBI = in_pPBIToNotify;
  this->m_FadeOutTimeForLast = in_CrossFadeTime;
  this->m_bNeedNotifyDelay = 0;
}

// File Line: 320
// RVA: 0xA78AD0
void __fastcall CAkActionPlayAndContinue::SetSAInfo(CAkActionPlayAndContinue *this, unsigned int in_seqID)
{
  this->m_SA_PBIID = in_seqID;
}

// File Line: 325
// RVA: 0xA78AF0
void __fastcall CAkActionPlayAndContinue::UnsetFadeBack(CAkActionPlayAndContinue *this, CAkContinuousPBI *in_pPBIToCheck)
{
  if ( in_pPBIToCheck == this->m_pPreviousPBI )
    this->m_pPreviousPBI = 0i64;
}

// File Line: 334
// RVA: 0xA78AE0
void __fastcall CAkActionPlayAndContinue::StartAsPaused(CAkActionPlayAndContinue *this)
{
  this->m_InitialPlaybackState = 1;
}

// File Line: 339
// RVA: 0xA787C0
void __fastcall CAkActionPlayAndContinue::Resume(CAkActionPlayAndContinue *this)
{
  CAkActionPlayAndContinue *v1; // rbx
  CAkTransition *v2; // rdx
  AkPendingAction *v3; // r8

  v1 = this;
  if ( *((_BYTE *)&this->m_PBTrans + 16) & 2 )
  {
    v2 = this->m_PBTrans.pvPRTrans;
    if ( v2 )
    {
      v3 = this->m_pTransitionOwner;
      if ( v3 )
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v2, (ITransitionable *)&v3->vfptr);
      *((_BYTE *)&v1->m_PBTrans + 16) &= 0xFDu;
      v1->m_PBTrans.pvPRTrans = 0i64;
    }
  }
}

// File Line: 348
// RVA: 0xA78240
char __fastcall CAkActionPlayAndContinue::BreakToNode(CAkActionPlayAndContinue *this, CAkParameterNodeBase *in_pNodeToTest, CAkRegisteredObj *in_pGameObj, AkPendingAction *in_pPendingAction)
{
  CAkContinuationList *v4; // rax
  CAkRegisteredObj *v5; // rbp
  CAkParameterNodeBase *v6; // rsi
  CAkActionPlayAndContinue *v7; // rbx
  signed __int64 v8; // rdi
  CAkMultiPlayNode *v9; // rcx
  bool v10; // zf
  unsigned int v11; // edx
  __int64 v12; // rcx
  CAkContinuationList *v13; // rdi
  CAkContinuationList *v14; // rdx
  CAkContinuationList *v15; // rdi
  CAkContinuationList *v16; // rdi
  CAkContinuationList *v17; // rcx
  CAkContinuationList *v18; // rcx
  CAkParameterNodeBase *v20; // rax
  CAkContinuationList *v21; // rcx
  unsigned int out_uSelectedNodeID; // [rsp+30h] [rbp-28h]
  CAkSmartPtr<CAkContinuationList> io_spList; // [rsp+60h] [rbp+8h]

  v4 = this->m_spContList.m_pT;
  v5 = in_pGameObj;
  v6 = in_pNodeToTest;
  v7 = this;
  if ( !v4 )
    return 1;
  if ( v4->m_listItems.m_uLength )
  {
    do
    {
      v8 = (signed __int64)&v7->m_spContList.m_pT->m_listItems.m_pItems[v7->m_spContList.m_pT->m_listItems.m_uLength];
      v9 = *(CAkMultiPlayNode **)(v8 - 16);
      if ( v9 )
      {
        v14 = *(CAkContinuationList **)(v8 - 8);
        io_spList.m_pT = 0i64;
        CAkMultiPlayNode::ContGetList(v9, v14, &io_spList);
        v15 = v7->m_spContList.m_pT;
        CAkContinueListItem::~CAkContinueListItem((CAkContinueListItem *)((char *)v15->m_listItems.m_pItems
                                                                        + 8 * (5i64 * v15->m_listItems.m_uLength - 5)));
        --v15->m_listItems.m_uLength;
        v16 = io_spList.m_pT;
        if ( !io_spList.m_pT )
        {
          v21 = v7->m_spContList.m_pT;
          v7->m_spContList.m_pT = 0i64;
          if ( !v21 )
            return 1;
          CAkContinuationList::Release(v21);
          v18 = io_spList.m_pT;
LABEL_18:
          if ( v18 )
            CAkContinuationList::Release(v18);
          return 1;
        }
        CAkContinuationList::AddRef(io_spList.m_pT);
        v17 = v7->m_spContList.m_pT;
        v7->m_spContList.m_pT = v16;
        if ( v17 )
          CAkContinuationList::Release(v17);
        if ( io_spList.m_pT )
          CAkContinuationList::Release(io_spList.m_pT);
      }
      else
      {
        if ( !CAkParameterNode::IsOrIsChildOf(*(CAkParameterNode **)(v8 - 40), v6, 0) )
        {
          v20 = CAkRanSeqCntr::GetNextToPlayContinuous(
                  *(CAkRanSeqCntr **)(v8 - 40),
                  v5,
                  (unsigned __int16 *)&io_spList,
                  &out_uSelectedNodeID,
                  (CAkContainerBaseInfo **)(v8 - 32),
                  (AkLoop *)(v8 - 24));
          if ( !v20 )
            break;
          v7->m_PlayHistory.HistArray.aCntrHist[v7->m_PlayHistory.HistArray.uiArraySize - 1] = (unsigned __int16)io_spList.m_pT;
          v7->m_ulElementID = v20->key;
          v20->vfptr->Release((CAkIndexable *)&v20->vfptr);
          return 0;
        }
        v10 = v7->m_PlayHistory.HistArray.uiArraySize-- == 1;
        if ( !v10 )
        {
          do
          {
            v11 = v7->m_PlayHistory.HistArray.uiArraySize - 1;
            if ( v11 < 0x20 )
            {
              v12 = v7->m_PlayHistory.arrayIsContinuous.m_iBitArray;
              if ( _bittest64(&v12, v11) )
                break;
            }
            v7->m_PlayHistory.HistArray.uiArraySize = v11;
          }
          while ( v11 );
        }
        v13 = v7->m_spContList.m_pT;
        CAkContinueListItem::~CAkContinueListItem((CAkContinueListItem *)((char *)v13->m_listItems.m_pItems
                                                                        + 8 * (5i64 * v13->m_listItems.m_uLength - 5)));
        --v13->m_listItems.m_uLength;
      }
    }
    while ( v7->m_spContList.m_pT->m_listItems.m_uLength );
  }
  v18 = v7->m_spContList.m_pT;
  if ( !v18->m_listItems.m_uLength )
  {
    v7->m_spContList.m_pT = 0i64;
    goto LABEL_18;
  }
  return 1;
}f ( !v18->m_listItems.m_uLength )
  

