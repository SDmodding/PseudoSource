// File Line: 43
// RVA: 0xA7F470
signed __int64 __fastcall CAkVPLFinalMixNode::Init(CAkVPLFinalMixNode *this, unsigned int in_uChannelMask)
{
  unsigned int v2; // esi
  CAkVPLFinalMixNode *v3; // rbx
  unsigned int v4; // ecx
  int v5; // edx
  unsigned __int64 v6; // rdx
  void *v7; // rax
  void *v8; // rdi

  v2 = in_uChannelMask;
  v3 = this;
  CAkBusVolumes::InitPan((CAkBusVolumes *)this->m_PanningVolumes, 0i64, in_uChannelMask, in_uChannelMask);
  v3->m_Mixer.m_fOneOverNumFrames = 0.0009765625;
  v4 = v2;
  v5 = 0;
  v3->m_Mixer.m_usMaxFrames = 1024;
  *((_BYTE *)v3->m_aFX + 32) &= 0xFCu;
  v3->m_aFX[0].id = -1;
  v3->m_aFX[1].id = -1;
  v3->m_aFX[0].pParam = 0i64;
  v3->m_aFX[0].pEffect = 0i64;
  v3->m_aFX[0].pBusFXContext = 0i64;
  v3->m_aFX[1].pParam = 0i64;
  v3->m_aFX[1].pEffect = 0i64;
  v3->m_aFX[1].pBusFXContext = 0i64;
  *((_BYTE *)&v3->m_aFX[1] + 32) &= 0xFCu;
  v3->m_aFX[2].id = -1;
  v3->m_aFX[2].pParam = 0i64;
  v3->m_aFX[2].pEffect = 0i64;
  v3->m_aFX[2].pBusFXContext = 0i64;
  *((_BYTE *)&v3->m_aFX[2] + 32) &= 0xFCu;
  v3->m_aFX[3].id = -1;
  v3->m_aFX[3].pParam = 0i64;
  v3->m_aFX[3].pEffect = 0i64;
  v3->m_aFX[3].pBusFXContext = 0i64;
  *((_BYTE *)&v3->m_aFX[3] + 32) &= 0xFCu;
  *((_BYTE *)&v3->0 + 1312) &= 0xFCu;
  v3->m_fPreviousVolume = 1.0;
  v3->m_fNextVolume = 1.0;
  *(_QWORD *)&v3->m_fNextVolumedB = 0i64;
  v3->m_eState = 2;
  v3->m_BufferOut.pData = 0i64;
  *(_QWORD *)&v3->m_BufferOut.eState = 43i64;
  v3->m_BufferOut.eState = 17;
  if ( v2 )
  {
    do
    {
      ++v5;
      v4 &= v4 - 1;
    }
    while ( v4 );
  }
  v6 = (unsigned int)(v5 << 12);
  v3->m_ulBufferOutSize = v6;
  v7 = AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, v6, 0x10u);
  v8 = v7;
  if ( !v7 )
    return 52i64;
  memset(v7, 0, v3->m_ulBufferOutSize);
  v3->m_BufferOut.pData = v8;
  *(_DWORD *)&v3->m_BufferOut.uMaxFrames = 1024;
  v3->m_BufferOut.uChannelMask = v2;
  return 1i64;
}

// File Line: 107
// RVA: 0xA7F700
signed __int64 __fastcall CAkVPLFinalMixNode::Term(CAkVPLFinalMixNode *this)
{
  void *v1; // rdx
  CAkVPLFinalMixNode *v2; // rbx

  v1 = this->m_BufferOut.pData;
  v2 = this;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
    v2->m_BufferOut.pData = 0i64;
  }
  CAkBusFX::DropFx((CAkBusFX *)v2->m_PanningVolumes);
  return 1i64;
}

// File Line: 131
// RVA: 0xA7F620
signed __int64 __fastcall CAkVPLFinalMixNode::ReleaseBuffer(CAkVPLFinalMixNode *this)
{
  bool v1; // zf

  v1 = this->m_BufferOut.eState == 17;
  this->m_BufferOut.eState = 17;
  this->m_BufferOut.uValidFrames = 0;
  this->m_eState = v1 + 1;
  if ( this->m_BufferOut.pData )
    memset(this->m_BufferOut.pData, 0, this->m_ulBufferOutSize);
  return 1i64;
}

// File Line: 164
// RVA: 0xA7F200
void __fastcall CAkVPLFinalMixNode::Connect(CAkVPLFinalMixNode *this, CAkVPLMixBusNode *in_pInput)
{
  CAkVPLFinalMixNode *v2; // rbx
  AkDevice *v3; // r8
  __int64 v4; // rax
  unsigned __int64 *v5; // rdx
  float v6; // xmm0_4

  v2 = this;
  if ( this->m_eState != 1 )
  {
    v3 = 0i64;
    v4 = 0i64;
    if ( CAkOutputMgr::m_Devices.m_uLength )
    {
      v5 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
      while ( *v5 )
      {
        v4 = (unsigned int)(v4 + 1);
        v5 += 10;
        if ( (unsigned int)v4 >= CAkOutputMgr::m_Devices.m_uLength )
          goto LABEL_8;
      }
      v3 = &CAkOutputMgr::m_Devices.m_pItems[v4];
    }
LABEL_8:
    if ( v3->pFinalMix == this )
    {
      v6 = AK::CAkBusCtx::GetVolume(&g_MasterBusCtx, 0);
      CAkBusVolumes::SetNextVolume((CAkBusVolumes *)v2->m_PanningVolumes, v6);
      v2->m_fPreviousVolume = v2->m_fNextVolume;
      v2->m_fPreviousVolumedB = v2->m_fNextVolumedB;
    }
  }
}

// File Line: 199
// RVA: 0xA7F290
signed __int64 __fastcall CAkVPLFinalMixNode::ConsumeBuffer(CAkVPLFinalMixNode *this, AkAudioBufferBus *io_rpBuffer, bool in_bPan, AkAudioMix *in_PanMix)
{
  AkAudioMix *v4; // rsi
  bool v5; // bp
  AkAudioBufferBus *v6; // rdi
  CAkVPLFinalMixNode *v7; // rbx
  bool v8; // zf

  v4 = in_PanMix;
  v5 = in_bPan;
  v6 = io_rpBuffer;
  v7 = this;
  if ( io_rpBuffer->uValidFrames )
  {
    v8 = this->m_eState == 2;
    this->m_BufferOut.eState = 45;
    if ( v8 )
      CAkVPLFinalMixNode::SetAllInsertFx(this);
    v7->m_eState = 1;
    CAkMixer::Mix(&v7->m_Mixer, v6, (AkPipelineBufferBase *)&v7->m_BufferOut.pData, v5, v4);
  }
  return 1i64;
}

// File Line: 251
// RVA: 0xA7F320
void __fastcall CAkVPLFinalMixNode::GetResultingBuffer(CAkVPLFinalMixNode *this, AkPipelineBufferBase *io_rBuffer)
{
  AkPipelineBufferBase *v2; // rbp
  CAkVPLFinalMixNode *v3; // rbx
  _BYTE *v4; // rdi
  signed __int64 v5; // rsi
  __int64 v6; // rcx
  char v7; // al
  unsigned __int16 v8; // ax
  unsigned int v9; // eax

  v2 = io_rBuffer;
  v3 = this;
  if ( this->m_eState == 1 )
  {
    v4 = (char *)this->m_aFX + 32;
    v5 = 4i64;
    do
    {
      v6 = *((_QWORD *)v4 - 2);
      if ( v6 )
      {
        v7 = *v4 | *((_BYTE *)&v3->0 + 1312);
        if ( v7 & 1 )
        {
          if ( !(v7 & 2) )
            (*(void (**)(void))(*(_QWORD *)v6 + 16i64))();
        }
        else
        {
          (*(void (__fastcall **)(__int64, AkAudioBufferBus *))(*(_QWORD *)v6 + 56i64))(v6, &v3->m_BufferOut);
        }
        *v4 ^= (*v4 ^ 2 * *v4) & 2;
      }
      v4 += 40;
      --v5;
    }
    while ( v5 );
    v8 = v3->m_BufferOut.uMaxFrames;
    *((_BYTE *)&v3->0 + 1312) ^= (*((_BYTE *)&v3->0 + 1312) ^ 2 * *((_BYTE *)&v3->0 + 1312)) & 2;
    v2->uValidFrames = v8;
  }
  v3->m_BufferOut.m_fNextVolume = v3->m_fNextVolume;
  v3->m_BufferOut.m_fPreviousVolume = v3->m_fPreviousVolume;
  v9 = v3->m_BufferOut.uChannelMask;
  switch ( v9 )
  {
    case 3u:
      CAkMixer::MixFinalStereo(&v3->m_Mixer, &v3->m_BufferOut, v2);
      break;
    case 0x3Fu:
      CAkMixer::MixFinal51(&v3->m_Mixer, &v3->m_BufferOut, v2);
      break;
    case 0x63Fu:
      CAkMixer::MixFinal71(&v3->m_Mixer, &v3->m_BufferOut, v2);
      break;
  }
  v3->m_fPreviousVolume = v3->m_fNextVolume;
  v3->m_fPreviousVolumedB = v3->m_fNextVolumedB;
}

// File Line: 383
// RVA: 0xA7F670
__int64 __fastcall CAkVPLFinalMixNode::SetAllInsertFx(CAkVPLFinalMixNode *this)
{
  unsigned int v1; // ebx
  CAkVPLFinalMixNode *v2; // rdi
  __int64 v3; // rax
  unsigned __int64 *v4; // rdx
  AkDevice *v5; // rcx
  __int64 result; // rax

  v1 = 0;
  v2 = this;
  v3 = 0i64;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    v4 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
    while ( *v4 )
    {
      v3 = (unsigned int)(v3 + 1);
      v4 += 10;
      if ( (unsigned int)v3 >= CAkOutputMgr::m_Devices.m_uLength )
        goto LABEL_5;
    }
    v5 = &CAkOutputMgr::m_Devices.m_pItems[v3];
  }
  else
  {
LABEL_5:
    v5 = 0i64;
  }
  if ( v5->pFinalMix != v2 )
    return 1i64;
  do
    result = CAkBusFX::SetInsertFx((CAkBusFX *)v2->m_PanningVolumes, &g_MasterBusCtx, v1++);
  while ( v1 < 4 );
  return result;
}

