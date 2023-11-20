// File Line: 59
// RVA: 0xA83D10
void __fastcall CAkVPLSrcNode::CAkVPLSrcNode(CAkVPLSrcNode *this, CAkPBI *in_pCtx)
{
  *((_BYTE *)this + 32) &= 0xFCu;
  this->vfptr = (CAkVPLNodeVtbl *)&CAkVPLSrcNode::`vftable';
  this->m_pInput = 0i64;
  this->m_pAnalysisData = 0i64;
  this->m_pCtx = in_pCtx;
}

// File Line: 66
// RVA: 0xA83D70
IAkSoftwareCodec *__fastcall CAkVPLSrcNode::Create(CAkPBI *in_pCtx)
{
  CAkSource *v1; // rax
  IAkSoftwareCodec *v2; // rbx
  CAkPBI *v3; // rdi
  unsigned int v4; // er8
  int v5; // edx
  CAkSrcPhysModel *v6; // rax
  IAkSoftwareCodec *v7; // rax
  CAkSrcFileADPCM *v8; // rax
  CAkSrcBankADPCM *v9; // rax
  CAkSrcFilePCM *v10; // rax
  CAkSrcBankPCM *v11; // rax

  v1 = in_pCtx->m_pSource;
  v2 = 0i64;
  v3 = in_pCtx;
  v4 = v1->m_sSrcTypeInfo.dwID;
  v5 = (*((_DWORD *)&v1->m_sSrcTypeInfo.mediaInfo + 4) >> 2) & 0x1F;
  if ( v5 == 2 )
  {
    v6 = (CAkSrcPhysModel *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x88ui64);
    if ( v6 )
    {
      CAkSrcPhysModel::CAkSrcPhysModel(v6, v3);
      goto LABEL_21;
    }
LABEL_22:
    CAkPBI::Destroy(v3, CtxDestroyReasonPlayFailed);
    return v2;
  }
  if ( !v5 || !(v4 >> 16) )
    goto LABEL_22;
  if ( v4 >> 16 == 1 )
  {
    if ( v5 == 1 )
    {
      v10 = (CAkSrcFilePCM *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x90ui64);
      if ( !v10 )
        goto LABEL_22;
      CAkSrcFilePCM::CAkSrcFilePCM(v10, v3);
    }
    else
    {
      if ( v5 != 3 )
        goto LABEL_22;
      v11 = (CAkSrcBankPCM *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x60ui64);
      if ( !v11 )
        goto LABEL_22;
      CAkSrcBankPCM::CAkSrcBankPCM(v11, v3);
    }
  }
  else if ( v4 >> 16 == 2 )
  {
    if ( v5 == 1 )
    {
      v8 = (CAkSrcFileADPCM *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x1B8ui64);
      if ( !v8 )
        goto LABEL_22;
      CAkSrcFileADPCM::CAkSrcFileADPCM(v8, v3);
    }
    else
    {
      if ( v5 != 3 )
        goto LABEL_22;
      v9 = (CAkSrcBankADPCM *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x70ui64);
      if ( !v9 )
        goto LABEL_22;
      CAkSrcBankADPCM::CAkSrcBankADPCM(v9, v3);
    }
  }
  else
  {
    v7 = CAkEffectsMgr::AllocCodec(in_pCtx, v5, v4);
  }
LABEL_21:
  v2 = v7;
  if ( !v7 )
    goto LABEL_22;
  return v2;
}

// File Line: 169
// RVA: 0xA84060
void __fastcall CAkVPLSrcNode::Term(CAkVPLSrcNode *this, AkCtxDestroyReason in_eReason)
{
  CAkPBI *v2; // rax
  AkCtxDestroyReason v3; // edi
  CAkVPLSrcNode *v4; // rbx

  v2 = this->m_pCtx;
  v3 = in_eReason;
  v4 = this;
  if ( v2->m_uRegisteredNotif & 0x10000 )
    CAkPositionRepository::RemoveSource(g_pPositionRepository, v2->m_UserParams.m_PlayingID, this);
  CAkPBI::Destroy(v4->m_pCtx, v3);
  (*(void (__fastcall **)(CAkVPLSrcNode *))v4->vfptr[1].gap8)(v4);
}

// File Line: 186
// RVA: 0xA83F80
void __usercall CAkVPLSrcNode::Start(CAkVPLSrcNode *this@<rcx>, float a2@<xmm0>)
{
  float v2; // xmm7_4
  CAkVPLSrcNode *v3; // rdi
  CAkPBI *v4; // rcx
  CAkPBI *v5; // rbx
  float v6; // xmm6_4
  CAkPBI *v7; // rcx
  unsigned int in_idAudioNode; // eax
  CAkPBI *v9; // rax

  v2 = 0.0;
  v3 = this;
  if ( *((_BYTE *)this + 32) & 1 )
  {
    ((void (*)(void))this->vfptr[1].TimeSkip)();
    v2 = a2;
  }
  v4 = v3->m_pCtx;
  if ( !(*((_BYTE *)v4 + 372) & 0x20) )
    ((void (*)(void))v4->vfptr[7].~CAkTransportAware)();
  v5 = v3->m_pCtx;
  v6 = v2 / powf(2.0, v5->m_EffectiveParams.Pitch * 0.00083333335);
  CAkPBI::Play(v5, v6);
  v7 = v3->m_pCtx;
  LODWORD(v5) = v7->m_UserParams.m_PlayingID;
  in_idAudioNode = CAkPBI::GetSoundID(v7);
  CAkPlayingMgr::NotifyDuration(g_pPlayingMgr, (unsigned int)v5, v2, v6, in_idAudioNode);
  v9 = v3->m_pCtx;
  if ( v9->m_uRegisteredNotif & 0x10000 )
    CAkPositionRepository::AddSource(g_pPositionRepository, v9->m_UserParams.m_PlayingID, v3);
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
  CAkVPLSrcNode *v1; // rbx

  v1 = this;
  CAkPBI::Pause(this->m_pCtx);
  CAkPositionRepository::SetRate(g_pPositionRepository, v1->m_pCtx->m_UserParams.m_PlayingID, 0.0);
}

// File Line: 233
// RVA: 0xA83F20
void __fastcall CAkVPLSrcNode::Resume(CAkVPLSrcNode *this, float in_fOutputRate)
{
  CAkVPLSrcNode *v2; // rbx

  v2 = this;
  CAkPBI::Resume(this->m_pCtx);
  CAkPositionRepository::SetRate(g_pPositionRepository, v2->m_pCtx->m_UserParams.m_PlayingID, in_fOutputRate);
}

// File Line: 244
// RVA: 0xA83F60
__int64 __fastcall CAkVPLSrcNode::Seek(CAkVPLSrcNode *this)
{
  __int64 result; // rax

  if ( *((_BYTE *)this->m_pCtx + 375) & 2 )
    result = ((__int64 (*)(void))this->vfptr[2].ReleaseBuffer)();
  else
    result = 1i64;
  return result;
}

// File Line: 273
// RVA: 0xA840B0
__int64 __fastcall CAkVPLSrcNode::TimeSkip(CAkVPLSrcNode *this, unsigned int *io_uFrames)
{
  unsigned int *v2; // rdi
  CAkVPLNodeVtbl *v3; // rax
  CAkVPLSrcNode *v4; // rbx
  __int64 v6; // [rsp+20h] [rbp-48h]
  __int16 v7; // [rsp+30h] [rbp-38h]
  unsigned __int16 v8; // [rsp+32h] [rbp-36h]
  __int16 v9; // [rsp+38h] [rbp-30h]
  __int64 v10; // [rsp+40h] [rbp-28h]
  unsigned int v11; // [rsp+58h] [rbp-10h]

  v2 = io_uFrames;
  v7 = *(_WORD *)io_uFrames;
  v3 = this->vfptr;
  v4 = this;
  v6 = 0i64;
  v9 = 0;
  v10 = 0i64;
  ((void (__fastcall *)(CAkVPLSrcNode *, __int64 *))v3[1].ReleaseBuffer)(this, &v6);
  if ( v6 )
  {
    *v2 = v8;
    v4->vfptr->ReleaseBuffer((CAkVPLNode *)&v4->vfptr);
  }
  else
  {
    *v2 = 0;
  }
  return v11;
}

// File Line: 303
// RVA: 0xA83EB0
__int64 __fastcall CAkVPLSrcNode::FetchStreamedData(CAkVPLSrcNode *this)
{
  CAkVPLSrcNode *v1; // rbx
  __int64 result; // rax

  v1 = this;
  if ( *((_BYTE *)this + 32) & 1 )
    return 1i64;
  result = ((__int64 (*)(void))this->vfptr[1].__vecDelDtor)();
  if ( (_DWORD)result == 1 )
    *((_BYTE *)v1 + 32) |= 1u;
  return result;
}

