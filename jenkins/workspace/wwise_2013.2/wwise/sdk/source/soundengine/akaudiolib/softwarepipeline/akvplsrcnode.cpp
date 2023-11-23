// File Line: 59
// RVA: 0xA83D10
void __fastcall CAkVPLSrcNode::CAkVPLSrcNode(CAkVPLSrcNode *this, CAkPBI *in_pCtx)
{
  *((_BYTE *)this + 32) &= 0xFCu;
  this->vfptr = (CAkVPLNodeVtbl *)&CAkVPLSrcNode::`vftable;
  this->m_pInput = 0i64;
  this->m_pAnalysisData = 0i64;
  this->m_pCtx = in_pCtx;
}

// File Line: 66
// RVA: 0xA83D70
CAkVPLSrcNode *__fastcall CAkVPLSrcNode::Create(CAkPBI *in_pCtx)
{
  CAkSource *m_pSource; // rax
  IAkSoftwareCodec *v2; // rbx
  unsigned int dwID; // r8d
  int v5; // edx
  CAkSrcPhysModel *v6; // rax
  IAkSoftwareCodec *v7; // rax
  CAkSrcFileADPCM *v8; // rax
  CAkSrcBankADPCM *v9; // rax
  CAkSrcFilePCM *v10; // rax
  CAkSrcBankPCM *v11; // rax

  m_pSource = in_pCtx->m_pSource;
  v2 = 0i64;
  dwID = m_pSource->m_sSrcTypeInfo.dwID;
  v5 = (*((_DWORD *)&m_pSource->m_sSrcTypeInfo.mediaInfo + 4) >> 2) & 0x1F;
  if ( v5 == 2 )
  {
    v6 = (CAkSrcPhysModel *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x88ui64);
    if ( v6 )
    {
      CAkSrcPhysModel::CAkSrcPhysModel(v6, in_pCtx);
      goto LABEL_21;
    }
LABEL_22:
    CAkPBI::Destroy(in_pCtx, CtxDestroyReasonPlayFailed);
    return (CAkVPLSrcNode *)v2;
  }
  if ( !v5 || !HIWORD(dwID) )
    goto LABEL_22;
  if ( HIWORD(dwID) == 1 )
  {
    if ( v5 == 1 )
    {
      v10 = (CAkSrcFilePCM *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x90ui64);
      if ( !v10 )
        goto LABEL_22;
      CAkSrcFilePCM::CAkSrcFilePCM(v10, in_pCtx);
    }
    else
    {
      if ( v5 != 3 )
        goto LABEL_22;
      v11 = (CAkSrcBankPCM *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x60ui64);
      if ( !v11 )
        goto LABEL_22;
      CAkSrcBankPCM::CAkSrcBankPCM(v11, in_pCtx);
    }
  }
  else if ( HIWORD(dwID) == 2 )
  {
    if ( v5 == 1 )
    {
      v8 = (CAkSrcFileADPCM *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x1B8ui64);
      if ( !v8 )
        goto LABEL_22;
      CAkSrcFileADPCM::CAkSrcFileADPCM(v8, in_pCtx);
    }
    else
    {
      if ( v5 != 3 )
        goto LABEL_22;
      v9 = (CAkSrcBankADPCM *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x70ui64);
      if ( !v9 )
        goto LABEL_22;
      CAkSrcBankADPCM::CAkSrcBankADPCM(v9, in_pCtx);
    }
  }
  else
  {
    v7 = CAkEffectsMgr::AllocCodec(in_pCtx, v5, dwID);
  }
LABEL_21:
  v2 = v7;
  if ( !v7 )
    goto LABEL_22;
  return (CAkVPLSrcNode *)v2;
}

// File Line: 169
// RVA: 0xA84060
void __fastcall CAkVPLSrcNode::Term(CAkVPLSrcNode *this, AkCtxDestroyReason in_eReason)
{
  CAkPBI *m_pCtx; // rax

  m_pCtx = this->m_pCtx;
  if ( (m_pCtx->m_uRegisteredNotif & 0x10000) != 0 )
    CAkPositionRepository::RemoveSource(g_pPositionRepository, m_pCtx->m_UserParams.m_PlayingID, this);
  CAkPBI::Destroy(this->m_pCtx, in_eReason);
  (*(void (__fastcall **)(CAkVPLSrcNode *))this->vfptr[1].gap8)(this);
}

// File Line: 186
// RVA: 0xA83F80
void __fastcall CAkVPLSrcNode::Start(CAkVPLSrcNode *this)
{
  float v1; // xmm7_4
  double v3; // xmm0_8
  CAkPBI *m_pCtx; // rcx
  CAkPBI *v5; // rbx
  float v6; // xmm6_4
  CAkPBI *v7; // rcx
  unsigned int in_idAudioNode; // eax
  CAkPBI *v9; // rax

  v1 = 0.0;
  if ( (*((_BYTE *)this + 32) & 1) != 0 )
  {
    v3 = ((double (__fastcall *)(CAkVPLSrcNode *))this->vfptr[1].TimeSkip)(this);
    v1 = *(float *)&v3;
  }
  m_pCtx = this->m_pCtx;
  if ( (*((_BYTE *)m_pCtx + 372) & 0x20) == 0 )
    m_pCtx->CAkTransportAware::vfptr[7].~CAkTransportAware(m_pCtx);
  v5 = this->m_pCtx;
  v6 = v1 / powf(2.0, v5->m_EffectiveParams.Pitch * 0.00083333335);
  CAkPBI::Play(v5, v6);
  v7 = this->m_pCtx;
  LODWORD(v5) = v7->m_UserParams.m_PlayingID;
  in_idAudioNode = CAkPBI::GetSoundID(v7);
  CAkPlayingMgr::NotifyDuration(g_pPlayingMgr, (unsigned int)v5, v1, v6, in_idAudioNode);
  v9 = this->m_pCtx;
  if ( (v9->m_uRegisteredNotif & 0x10000) != 0 )
    CAkPositionRepository::AddSource(g_pPositionRepository, v9->m_UserParams.m_PlayingID, this);
}

// File Line: 214
// RVA: 0xA84050
void __fastcall CAkVPLSrcNode::Stop(CAkVPLSrcNode *this)
{
  CAkPBI::Stop(this->m_pCtx);
}

// File Line: 223
// RVA: 0xA83EF0
void __fastcall CAkVPLSrcNode::Pause(CAkVPLSrcNode *this)
{
  CAkPBI::Pause(this->m_pCtx);
  CAkPositionRepository::SetRate(g_pPositionRepository, this->m_pCtx->m_UserParams.m_PlayingID, 0.0);
}

// File Line: 233
// RVA: 0xA83F20
void __fastcall CAkVPLSrcNode::Resume(CAkVPLSrcNode *this, float in_fOutputRate)
{
  CAkPBI::Resume(this->m_pCtx);
  CAkPositionRepository::SetRate(g_pPositionRepository, this->m_pCtx->m_UserParams.m_PlayingID, in_fOutputRate);
}

// File Line: 244
// RVA: 0xA83F60
__int64 __fastcall CAkVPLSrcNode::Seek(CAkVPLSrcNode *this)
{
  if ( (*((_BYTE *)this->m_pCtx + 375) & 2) != 0 )
    return ((__int64 (__fastcall *)(CAkVPLSrcNode *))this->vfptr[2].ReleaseBuffer)(this);
  else
    return 1i64;
}

// File Line: 273
// RVA: 0xA840B0
__int64 __fastcall CAkVPLSrcNode::TimeSkip(CAkVPLSrcNode *this, unsigned int *io_uFrames)
{
  CAkVPLNodeVtbl *vfptr; // rax
  __int64 v6; // [rsp+20h] [rbp-48h] BYREF
  __int16 v7; // [rsp+30h] [rbp-38h]
  unsigned __int16 v8; // [rsp+32h] [rbp-36h]
  __int16 v9; // [rsp+38h] [rbp-30h]
  __int64 v10; // [rsp+40h] [rbp-28h]
  unsigned int v11; // [rsp+58h] [rbp-10h]

  v7 = *(_WORD *)io_uFrames;
  vfptr = this->vfptr;
  v6 = 0i64;
  v9 = 0;
  v10 = 0i64;
  ((void (__fastcall *)(CAkVPLSrcNode *, __int64 *))vfptr[1].ReleaseBuffer)(this, &v6);
  if ( v6 )
  {
    *io_uFrames = v8;
    this->vfptr->ReleaseBuffer(this);
  }
  else
  {
    *io_uFrames = 0;
  }
  return v11;
}

// File Line: 303
// RVA: 0xA83EB0
__int64 __fastcall CAkVPLSrcNode::FetchStreamedData(CAkVPLSrcNode *this)
{
  __int64 result; // rax

  if ( (*((_BYTE *)this + 32) & 1) != 0 )
    return 1i64;
  result = ((__int64 (__fastcall *)(CAkVPLSrcNode *))this->vfptr[1].__vecDelDtor)(this);
  if ( (_DWORD)result == 1 )
    *((_BYTE *)this + 32) |= 1u;
  return result;
}

