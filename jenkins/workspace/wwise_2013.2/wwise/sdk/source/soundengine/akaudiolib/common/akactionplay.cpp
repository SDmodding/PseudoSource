// File Line: 33
// RVA: 0xA95460
void __fastcall CAkActionPlay::CAkActionPlay(CAkActionPlay *this, AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkAction::CAkAction(this, in_eActionType, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkActionPlay::`vftable;
  this->m_fileID = -1;
}

// File Line: 37
// RVA: 0xA95490
void __fastcall CAkActionPlay::~CAkActionPlay(CAkActionPlay *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkActionPlay::`vftable;
  CAkAction::~CAkAction(this);
}

// File Line: 42
// RVA: 0xA95560
__int64 __fastcall CAkActionPlay::Execute(CAkActionPlay *this, AkPendingAction *in_pAction)
{
  char *m_pProps; // r9
  unsigned int v5; // r10d
  int v6; // r8d
  __int64 v7; // rdx
  CAkParameterNode *v8; // rdi
  int TransitionTime; // eax
  char v10; // cl
  __int64 customParam; // rax
  AkExternalSourceArray *pExternalSrcs; // rax
  unsigned int v13; // eax
  unsigned int v14; // ebx
  float *v15; // rdi
  int v16; // ebx
  AkPBIParams in_rPBIParams; // [rsp+20h] [rbp-59h] BYREF
  int v19; // [rsp+E0h] [rbp+67h] BYREF
  int v20; // [rsp+E4h] [rbp+6Bh]

  m_pProps = this->m_props.m_pProps;
  if ( m_pProps )
  {
    v5 = (unsigned __int8)*m_pProps;
    v6 = 0;
    while ( 1 )
    {
      v7 = (unsigned int)(v6 + 1);
      if ( m_pProps[v7] == 16 )
        break;
      ++v6;
      if ( (unsigned int)v7 >= v5 )
        goto LABEL_5;
    }
    v15 = (float *)&m_pProps[4 * v6 + ((v5 + 4) & 0xFFFFFFFC)];
    if ( v15 )
    {
      if ( *v15 == 0.0 )
        return 1i64;
      v16 = rand() << 15;
      if ( (double)(rand() + v16) * 9.313225754828403e-10 * 100.0 > *v15 )
        return 1i64;
    }
  }
LABEL_5:
  v8 = (CAkParameterNode *)CAkAction::GetAndRefTarget(this);
  if ( v8 )
  {
    TransitionTime = CAkAction::GetTransitionTime(this);
    v10 = *((_BYTE *)&this->CAkAction + 54);
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
    v19 = TransitionTime;
    in_rPBIParams.userParams.m_PlayingID = in_pAction->UserParam.m_PlayingID;
    customParam = in_pAction->UserParam.m_CustomParam.customParam;
    v20 = v10 & 0x1F;
    in_rPBIParams.userParams.m_CustomParam.customParam = customParam;
    LODWORD(customParam) = in_pAction->UserParam.m_CustomParam.ui32Reserved;
    in_rPBIParams.playHistory.arrayIsContinuous.m_iBitArray = 0;
    in_rPBIParams.userParams.m_CustomParam.ui32Reserved = customParam;
    pExternalSrcs = in_pAction->UserParam.m_CustomParam.pExternalSrcs;
    in_rPBIParams.bSkipDelay = 0;
    in_rPBIParams.bTargetFeedback = 0;
    in_rPBIParams.playHistory.HistArray.uiArraySize = 0;
    in_rPBIParams.eType = PBI;
    in_rPBIParams.pInstigator = v8;
    if ( pExternalSrcs )
      ++pExternalSrcs->m_cRefCount;
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = pExternalSrcs;
    in_rPBIParams.uFrameOffset = in_pAction->LaunchFrameOffset;
    in_rPBIParams.pGameObj = in_pAction->pGameObj;
    in_rPBIParams.ePlaybackState = PB_Playing;
    in_rPBIParams.bIsFirst = 1;
    in_rPBIParams.pContinuousParams = 0i64;
    in_rPBIParams.sequenceID = 0;
    in_rPBIParams.pTransitionParameters = (TransParams *)&v19;
    v13 = CAkParameterNode::HandleInitialDelay(v8, &in_rPBIParams);
    v14 = v13;
    if ( v13 == 3 )
    {
      v14 = 1;
    }
    else if ( v13 == 1 )
    {
      v14 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))v8->vfptr[19].Category)(v8, &in_rPBIParams);
    }
    v8->vfptr->Release(v8);
    if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
      AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
  }
  else
  {
    return 15;
  }
  return v14;
}

// File Line: 93
// RVA: 0xA954E0
CAkActionPlay *__fastcall CAkActionPlay::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionPlay *result; // rax
  CAkActionPlay *v5; // rbx

  result = (CAkActionPlay *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction(result, in_eActionType, in_ulID);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionPlay::`vftable;
    v5->m_fileID = -1;
    CAkAction::AddToIndex(v5);
    return v5;
  }
  return result;
}

// File Line: 114
// RVA: 0xA95720
__int64 __fastcall CAkActionPlay::SetActionParams(CAkActionPlay *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char v3; // r8
  unsigned int v4; // r8d

  v3 = *(*io_rpData)++;
  *((_BYTE *)&this->CAkAction + 54) &= 0xE0u;
  *((_BYTE *)&this->CAkAction + 54) |= v3 & 0x1F;
  v4 = *(_DWORD *)*io_rpData;
  *io_rpData += 4;
  *((_BYTE *)&this->CAkAction + 54) |= 0x20u;
  this->m_fileID = v4;
  return 1i64;
}

