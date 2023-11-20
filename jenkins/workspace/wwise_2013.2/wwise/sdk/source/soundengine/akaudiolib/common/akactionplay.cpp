// File Line: 33
// RVA: 0xA95460
void __fastcall CAkActionPlay::CAkActionPlay(CAkActionPlay *this, AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionPlay *v3; // rbx

  v3 = this;
  CAkAction::CAkAction((CAkAction *)&this->vfptr, in_eActionType, in_ulID);
  v3->vfptr = (CAkIndexableVtbl *)&CAkActionPlay::`vftable;
  v3->m_fileID = -1;
}

// File Line: 37
// RVA: 0xA95490
void __fastcall CAkActionPlay::~CAkActionPlay(CAkActionPlay *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkActionPlay::`vftable;
  CAkAction::~CAkAction((CAkAction *)&this->vfptr);
}

// File Line: 42
// RVA: 0xA95560
signed __int64 __fastcall CAkActionPlay::Execute(CAkActionPlay *this, AkPendingAction *in_pAction)
{
  char *v2; // r9
  AkPendingAction *v3; // r14
  CAkActionPlay *v4; // rsi
  unsigned int v5; // er10
  int v6; // er8
  __int64 v7; // rdx
  CAkParameterNode *v8; // rdi
  int v9; // eax
  char v10; // cl
  __int64 v11; // rax
  AkExternalSourceArray *v12; // rax
  unsigned int v13; // eax
  unsigned int v14; // ebx
  float *v15; // rdi
  int v16; // ebx
  AkPBIParams in_rPBIParams; // [rsp+20h] [rbp-59h]
  int v19; // [rsp+E0h] [rbp+67h]
  int v20; // [rsp+E4h] [rbp+6Bh]

  v2 = this->m_props.m_pProps;
  v3 = in_pAction;
  v4 = this;
  if ( v2 )
  {
    v5 = (unsigned __int8)*v2;
    v6 = 0;
    while ( 1 )
    {
      v7 = (unsigned int)(v6 + 1);
      if ( v2[v7] == 16 )
        break;
      ++v6;
      if ( (unsigned int)v7 >= v5 )
        goto LABEL_5;
    }
    v15 = (float *)&v2[4 * v6 + ((v5 + 4) & 0xFFFFFFFC)];
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
  v8 = (CAkParameterNode *)CAkAction::GetAndRefTarget((CAkAction *)&v4->vfptr);
  if ( v8 )
  {
    v9 = CAkAction::GetTransitionTime((CAkAction *)&v4->vfptr);
    v10 = *((_BYTE *)&v4->0 + 54);
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
    v19 = v9;
    in_rPBIParams.userParams.m_PlayingID = v3->UserParam.m_PlayingID;
    v11 = v3->UserParam.m_CustomParam.customParam;
    v20 = v10 & 0x1F;
    in_rPBIParams.userParams.m_CustomParam.customParam = v11;
    LODWORD(v11) = v3->UserParam.m_CustomParam.ui32Reserved;
    in_rPBIParams.playHistory.arrayIsContinuous.m_iBitArray = 0;
    in_rPBIParams.userParams.m_CustomParam.ui32Reserved = v11;
    v12 = v3->UserParam.m_CustomParam.pExternalSrcs;
    in_rPBIParams.bSkipDelay = 0;
    in_rPBIParams.bTargetFeedback = 0;
    in_rPBIParams.playHistory.HistArray.uiArraySize = 0;
    in_rPBIParams.eType = 0;
    in_rPBIParams.pInstigator = (CAkPBIAware *)&v8->vfptr;
    if ( v12 )
      ++v12->m_cRefCount;
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = v12;
    in_rPBIParams.uFrameOffset = v3->LaunchFrameOffset;
    in_rPBIParams.pGameObj = v3->pGameObj;
    in_rPBIParams.ePlaybackState = 0;
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
    v8->vfptr->Release((CAkIndexable *)&v8->vfptr);
    if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
      AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
  }
  else
  {
    v14 = 15;
  }
  return v14;
}

// File Line: 93
// RVA: 0xA954E0
CAkActionPlay *__fastcall CAkActionPlay::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionPlay *result; // rax
  CAkActionPlay *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionPlay *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction((CAkAction *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionPlay::`vftable;
    v5->m_fileID = -1;
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

// File Line: 114
// RVA: 0xA95720
signed __int64 __fastcall CAkActionPlay::SetActionParams(CAkActionPlay *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char v3; // r8
  unsigned int v4; // er8

  v3 = *(*io_rpData)++;
  *((_BYTE *)&this->0 + 54) &= 0xE0u;
  *((_BYTE *)&this->0 + 54) |= v3 & 0x1F;
  v4 = *(_DWORD *)*io_rpData;
  *io_rpData += 4;
  *((_BYTE *)&this->0 + 54) |= 0x20u;
  this->m_fileID = v4;
  return 1i64;
}

