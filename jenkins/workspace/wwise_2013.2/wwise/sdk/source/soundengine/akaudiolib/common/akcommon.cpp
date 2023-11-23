// File Line: 30
// RVA: 0xA7F820
void __fastcall AkPipelineBuffer::FreeMarkers(AkPipelineBuffer *this)
{
  AkBufferMarker *pMarkers; // rdx

  pMarkers = this->pMarkers;
  if ( pMarkers )
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, pMarkers);
  this->uNumMarkers = 0;
  this->pMarkers = 0i64;
}

// File Line: 49
// RVA: 0xA7F850
__int64 __fastcall AkPipelineBufferBase::GetCachedBuffer(
        AkPipelineBufferBase *this,
        unsigned __int16 in_uMaxFrames,
        unsigned int in_uChannelMask)
{
  unsigned int v6; // r9d
  int i; // r10d
  void *CachedAudioBuffer; // rax
  __int64 result; // rax

  v6 = in_uChannelMask;
  for ( i = 0; v6; v6 &= v6 - 1 )
    ++i;
  CachedAudioBuffer = CAkLEngine::GetCachedAudioBuffer(4 * i * (unsigned int)in_uMaxFrames);
  if ( !CachedAudioBuffer )
    return 52i64;
  this->pData = CachedAudioBuffer;
  this->uMaxFrames = in_uMaxFrames;
  this->uChannelMask = in_uChannelMask;
  result = 1i64;
  this->uValidFrames = 0;
  return result;
}

// File Line: 66
// RVA: 0xA7F8E0
void __fastcall AkPipelineBufferBase::ReleaseCachedBuffer(AkPipelineBufferBase *this)
{
  unsigned int uChannelMask; // eax
  int i; // r8d

  uChannelMask = this->uChannelMask;
  for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
    ++i;
  CAkLEngine::ReleaseCachedAudioBuffer(4 * i * this->uMaxFrames, this->pData);
  this->pData = 0i64;
  this->uMaxFrames = 0;
}

// File Line: 76
// RVA: 0xA7F740
void __fastcall AkDeviceInfo::AkDeviceInfo(
        AkDeviceInfo *this,
        AkVPL *in_pOutputBus,
        unsigned __int64 in_uDeviceID,
        bool in_bCrossDeviceSend)
{
  this->pMixBus = in_pOutputBus;
  this->uDeviceID = in_uDeviceID;
  this->vfptr = (AkDeviceInfoVtbl *)&AkDeviceInfo::`vftable;
  this->bCrossDeviceSend = in_bCrossDeviceSend;
  *(_QWORD *)&this->fLPF = 0i64;
  memset(this->mxDirect, 0, sizeof(this->mxDirect));
  this->mxAttenuations.dry = 0i64;
  *((_QWORD *)&this->mxAttenuations.dry + 1) = 0i64;
  this->mxAttenuations.userDef = 0i64;
  *((_QWORD *)&this->mxAttenuations.userDef + 1) = 0i64;
  this->mxAttenuations.gameDef = 0i64;
  *((_QWORD *)&this->mxAttenuations.gameDef + 1) = 0i64;
  CAkVPLMixBusNode::Connect(&this->pMixBus->m_MixBus);
}

// File Line: 95
// RVA: 0xA7F8D0
__int64 __fastcall AkDeviceInfo::GetOutputConfig(AkDeviceInfo *this)
{
  return this->pMixBus->m_MixBus.m_BufferOut.uChannelMask;
}

