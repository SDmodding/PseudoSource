// File Line: 43
// RVA: 0xA7F470
__int64 __fastcall CAkVPLFinalMixNode::Init(CAkVPLFinalMixNode *this, unsigned int in_uChannelMask)
{
  unsigned int v4; // ecx
  int v5; // edx
  unsigned __int64 v6; // rdx
  void *v7; // rax
  void *v8; // rdi

  CAkBusVolumes::InitPan(this, 0i64, in_uChannelMask, in_uChannelMask);
  this->m_Mixer.m_fOneOverNumFrames = 0.0009765625;
  v4 = in_uChannelMask;
  v5 = 0;
  this->m_Mixer.m_usMaxFrames = 1024;
  *((_BYTE *)this->m_aFX + 32) &= 0xFCu;
  this->m_aFX[0].id = -1;
  this->m_aFX[1].id = -1;
  this->m_aFX[0].pParam = 0i64;
  this->m_aFX[0].pEffect = 0i64;
  this->m_aFX[0].pBusFXContext = 0i64;
  this->m_aFX[1].pParam = 0i64;
  this->m_aFX[1].pEffect = 0i64;
  this->m_aFX[1].pBusFXContext = 0i64;
  *((_BYTE *)&this->m_aFX[1] + 32) &= 0xFCu;
  this->m_aFX[2].id = -1;
  this->m_aFX[2].pParam = 0i64;
  this->m_aFX[2].pEffect = 0i64;
  this->m_aFX[2].pBusFXContext = 0i64;
  *((_BYTE *)&this->m_aFX[2] + 32) &= 0xFCu;
  this->m_aFX[3].id = -1;
  this->m_aFX[3].pParam = 0i64;
  this->m_aFX[3].pEffect = 0i64;
  this->m_aFX[3].pBusFXContext = 0i64;
  *((_BYTE *)&this->m_aFX[3] + 32) &= 0xFCu;
  *((_BYTE *)&this->CAkBusFX + 1312) &= 0xFCu;
  this->m_fPreviousVolume = 1.0;
  this->m_fNextVolume = 1.0;
  *(_QWORD *)&this->m_fNextVolumedB = 0i64;
  this->m_eState = NodeStateStop;
  this->m_BufferOut.pData = 0i64;
  *(_QWORD *)&this->m_BufferOut.eState = 43i64;
  this->m_BufferOut.eState = AK_NoMoreData;
  if ( in_uChannelMask )
  {
    do
    {
      ++v5;
      v4 &= v4 - 1;
    }
    while ( v4 );
  }
  v6 = (unsigned int)(v5 << 12);
  this->m_ulBufferOutSize = v6;
  v7 = AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, v6, 0x10u);
  v8 = v7;
  if ( !v7 )
    return 52i64;
  memset(v7, 0, this->m_ulBufferOutSize);
  this->m_BufferOut.pData = v8;
  *(_DWORD *)&this->m_BufferOut.uMaxFrames = 1024;
  this->m_BufferOut.uChannelMask = in_uChannelMask;
  return 1i64;
}

// File Line: 107
// RVA: 0xA7F700
__int64 __fastcall CAkVPLFinalMixNode::Term(CAkVPLFinalMixNode *this)
{
  void *pData; // rdx

  pData = this->m_BufferOut.pData;
  if ( pData )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, pData);
    this->m_BufferOut.pData = 0i64;
  }
  CAkBusFX::DropFx(this);
  return 1i64;
}

// File Line: 131
// RVA: 0xA7F620
__int64 __fastcall CAkVPLFinalMixNode::ReleaseBuffer(CAkVPLFinalMixNode *this)
{
  bool v1; // zf

  v1 = this->m_BufferOut.eState == AK_NoMoreData;
  this->m_BufferOut.eState = AK_NoMoreData;
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
  AkDevice *v3; // r8
  __int64 v4; // rax
  unsigned __int64 *p_uDeviceID; // rdx
  float Volume; // xmm0_4

  if ( this->m_eState != NodeStatePlay )
  {
    v3 = 0i64;
    v4 = 0i64;
    if ( CAkOutputMgr::m_Devices.m_uLength )
    {
      p_uDeviceID = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
      while ( *p_uDeviceID )
      {
        v4 = (unsigned int)(v4 + 1);
        p_uDeviceID += 10;
        if ( (unsigned int)v4 >= CAkOutputMgr::m_Devices.m_uLength )
          goto LABEL_8;
      }
      v3 = &CAkOutputMgr::m_Devices.m_pItems[v4];
    }
LABEL_8:
    if ( v3->pFinalMix == this )
    {
      Volume = AK::CAkBusCtx::GetVolume(&g_MasterBusCtx, BusVolumeType_ToNextBusWithEffect);
      CAkBusVolumes::SetNextVolume(this, Volume);
      this->m_fPreviousVolume = this->m_fNextVolume;
      this->m_fPreviousVolumedB = this->m_fNextVolumedB;
    }
  }
}

// File Line: 199
// RVA: 0xA7F290
__int64 __fastcall CAkVPLFinalMixNode::ConsumeBuffer(
        CAkVPLFinalMixNode *this,
        AkAudioBufferBus *io_rpBuffer,
        bool in_bPan,
        AkAudioMix *in_PanMix)
{
  bool v8; // zf

  if ( io_rpBuffer->uValidFrames )
  {
    v8 = this->m_eState == NodeStateStop;
    this->m_BufferOut.eState = AK_DataReady;
    if ( v8 )
      CAkVPLFinalMixNode::SetAllInsertFx(this);
    this->m_eState = NodeStatePlay;
    CAkMixer::Mix(&this->m_Mixer, io_rpBuffer, &this->m_BufferOut, in_bPan, in_PanMix);
  }
  return 1i64;
}

// File Line: 251
// RVA: 0xA7F320
void __fastcall CAkVPLFinalMixNode::GetResultingBuffer(CAkVPLFinalMixNode *this, AkPipelineBufferBase *io_rBuffer)
{
  _BYTE *v4; // rdi
  __int64 v5; // rsi
  __int64 v6; // rcx
  char v7; // al
  unsigned __int16 uMaxFrames; // ax
  unsigned int uChannelMask; // eax

  if ( this->m_eState == NodeStatePlay )
  {
    v4 = (char *)this->m_aFX + 32;
    v5 = 4i64;
    do
    {
      v6 = *((_QWORD *)v4 - 2);
      if ( v6 )
      {
        v7 = *v4 | *((_BYTE *)&this->CAkBusFX + 1312);
        if ( (v7 & 1) != 0 )
        {
          if ( (v7 & 2) == 0 )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6);
        }
        else
        {
          (*(void (__fastcall **)(__int64, AkAudioBufferBus *))(*(_QWORD *)v6 + 56i64))(v6, &this->m_BufferOut);
        }
        *v4 ^= (*v4 ^ (2 * *v4)) & 2;
      }
      v4 += 40;
      --v5;
    }
    while ( v5 );
    uMaxFrames = this->m_BufferOut.uMaxFrames;
    *((_BYTE *)&this->CAkBusFX + 1312) ^= (*((_BYTE *)&this->CAkBusFX + 1312) ^ (2 * *((_BYTE *)&this->CAkBusFX + 1312))) & 2;
    io_rBuffer->uValidFrames = uMaxFrames;
  }
  this->m_BufferOut.m_fNextVolume = this->m_fNextVolume;
  this->m_BufferOut.m_fPreviousVolume = this->m_fPreviousVolume;
  uChannelMask = this->m_BufferOut.uChannelMask;
  switch ( uChannelMask )
  {
    case 3u:
      CAkMixer::MixFinalStereo(&this->m_Mixer, &this->m_BufferOut, io_rBuffer);
      break;
    case 0x3Fu:
      CAkMixer::MixFinal51(&this->m_Mixer, &this->m_BufferOut, io_rBuffer);
      break;
    case 0x63Fu:
      CAkMixer::MixFinal71(&this->m_Mixer, &this->m_BufferOut, io_rBuffer);
      break;
  }
  this->m_fPreviousVolume = this->m_fNextVolume;
  this->m_fPreviousVolumedB = this->m_fNextVolumedB;
}

// File Line: 383
// RVA: 0xA7F670
__int64 __fastcall CAkVPLFinalMixNode::SetAllInsertFx(CAkVPLFinalMixNode *this)
{
  unsigned int v1; // ebx
  __int64 v3; // rax
  unsigned __int64 *p_uDeviceID; // rdx
  AkDevice *v5; // rcx
  __int64 result; // rax

  v1 = 0;
  v3 = 0i64;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    p_uDeviceID = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
    while ( *p_uDeviceID )
    {
      v3 = (unsigned int)(v3 + 1);
      p_uDeviceID += 10;
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
  if ( v5->pFinalMix != this )
    return 1i64;
  do
    result = CAkBusFX::SetInsertFx(this, &g_MasterBusCtx, v1++);
  while ( v1 < 4 );
  return result;
}

