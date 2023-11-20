// File Line: 30
// RVA: 0xA7F820
void __fastcall AkPipelineBuffer::FreeMarkers(AkPipelineBuffer *this)
{
  AkBufferMarker *v1; // rdx
  AkPipelineBuffer *v2; // rbx

  v1 = this->pMarkers;
  v2 = this;
  if ( v1 )
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
  v2->uNumMarkers = 0;
  v2->pMarkers = 0i64;
}

// File Line: 49
// RVA: 0xA7F850
signed __int64 __fastcall AkPipelineBufferBase::GetCachedBuffer(AkPipelineBufferBase *this, unsigned __int16 in_uMaxFrames, unsigned int in_uChannelMask)
{
  unsigned int v3; // edi
  unsigned __int16 v4; // si
  AkPipelineBufferBase *v5; // rbx
  unsigned int v6; // er9
  int i; // er10
  void *v8; // rax
  signed __int64 result; // rax

  v3 = in_uChannelMask;
  v4 = in_uMaxFrames;
  v5 = this;
  v6 = in_uChannelMask;
  for ( i = 0; v6; v6 &= v6 - 1 )
    ++i;
  v8 = CAkLEngine::GetCachedAudioBuffer(4 * i * (unsigned int)in_uMaxFrames);
  if ( !v8 )
    return 52i64;
  v5->pData = v8;
  v5->uMaxFrames = v4;
  v5->uChannelMask = v3;
  result = 1i64;
  v5->uValidFrames = 0;
  return result;
}

// File Line: 66
// RVA: 0xA7F8E0
void __fastcall AkPipelineBufferBase::ReleaseCachedBuffer(AkPipelineBufferBase *this)
{
  unsigned int v1; // eax
  AkPipelineBufferBase *v2; // rbx
  int i; // er8

  v1 = this->uChannelMask;
  v2 = this;
  for ( i = 0; v1; v1 &= v1 - 1 )
    ++i;
  CAkLEngine::ReleaseCachedAudioBuffer(4 * i * this->uMaxFrames, this->pData);
  v2->pData = 0i64;
  v2->uMaxFrames = 0;
}

// File Line: 76
// RVA: 0xA7F740
void __fastcall AkDeviceInfo::AkDeviceInfo(AkDeviceInfo *this, AkVPL *in_pOutputBus, unsigned __int64 in_uDeviceID, bool in_bCrossDeviceSend)
{
  AkDeviceInfo *v4; // rbx

  this->pMixBus = in_pOutputBus;
  this->uDeviceID = in_uDeviceID;
  this->vfptr = (AkDeviceInfoVtbl *)&AkDeviceInfo::`vftable';
  v4 = this;
  this->bCrossDeviceSend = in_bCrossDeviceSend;
  *(_QWORD *)&this->fLPF = 0i64;
  memset(this->mxDirect, 0, 0x200ui64);
  v4->mxAttenuations.dry = 0i64;
  *((_QWORD *)&v4->mxAttenuations.dry + 1) = 0i64;
  v4->mxAttenuations.userDef = 0i64;
  *((_QWORD *)&v4->mxAttenuations.userDef + 1) = 0i64;
  v4->mxAttenuations.gameDef = 0i64;
  *((_QWORD *)&v4->mxAttenuations.gameDef + 1) = 0i64;
  CAkVPLMixBusNode::Connect(&v4->pMixBus->m_MixBus);
}

// File Line: 95
// RVA: 0xA7F8D0
__int64 __fastcall AkDeviceInfo::GetOutputConfig(AkDeviceInfo *this)
{
  return this->pMixBus->m_MixBus.m_BufferOut.uChannelMask;
}

