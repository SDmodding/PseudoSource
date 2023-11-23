// File Line: 34
// RVA: 0xA924C0
void __fastcall CAkVPLFilterNodeOutOfPlace::GetBuffer(CAkVPLFilterNodeOutOfPlace *this, AkVPLState *io_state)
{
  bool v2; // zf

  v2 = !this->m_bLast;
  this->m_usRequestedFrames = io_state->uMaxFrames;
  if ( v2 )
  {
    if ( this->m_BufferIn.uValidFrames )
      ((void (__fastcall *)(CAkVPLFilterNodeOutOfPlace *))this->vfptr[1].VirtualOff)(this);
  }
  else
  {
    io_state->result = AK_NoMoreData;
    ((void (__fastcall *)(CAkVPLFilterNodeOutOfPlace *))this->vfptr[1].VirtualOff)(this);
  }
}

// File Line: 53
// RVA: 0xA92230
void __fastcall CAkVPLFilterNodeOutOfPlace::ConsumeBuffer(CAkVPLFilterNodeOutOfPlace *this, AkVPLState *io_state)
{
  __int64 v4; // rbp
  unsigned int uChannelMask; // ecx
  unsigned int i; // r8d
  void *v7; // rax
  unsigned int v8; // edx
  unsigned __int16 m_usRequestedFrames; // cx
  AK::IAkOutOfPlaceEffectPlugin *m_pEffect; // rcx
  __int64 m_uInOffset; // r8
  unsigned __int16 uMaxFrames; // cx
  unsigned int in_uOutputConfig; // r12d
  unsigned int v14; // eax
  bool v15; // cf
  unsigned int v16; // edx
  __int64 v17; // r13
  unsigned int j; // ecx
  __int64 v19; // r14
  bool v20; // zf
  AKRESULT v21; // ecx
  AkSIMDSpeakerVolumes in_volumes; // [rsp+40h] [rbp-128h] BYREF
  unsigned int in_uInputConfig; // [rsp+170h] [rbp+8h]

  if ( io_state->result == AK_NoMoreData )
    this->m_bLast = 1;
  v4 = 0i64;
  if ( !this->m_BufferIn.uValidFrames )
  {
    this->m_uInOffset = 0;
    this->m_BufferIn = io_state->AkPipelineBuffer;
    CAkVPLNode::CopyRelevantMarkers(io_state, &this->m_BufferIn, 0, io_state->uValidFrames);
  }
  this->m_BufferIn.eState = io_state->result;
  if ( !this->m_BufferOut.pData )
  {
    uChannelMask = this->m_BufferOut.uChannelMask;
    for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++i;
    v7 = AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 4 * i * (unsigned __int64)this->m_usRequestedFrames);
    if ( !v7 )
    {
      io_state->result = AK_Fail;
      return;
    }
    v8 = this->m_BufferOut.uChannelMask;
    m_usRequestedFrames = this->m_usRequestedFrames;
    this->m_BufferOut.pData = v7;
    this->m_BufferOut.uMaxFrames = m_usRequestedFrames;
    this->m_BufferOut.uChannelMask = v8;
    this->m_BufferOut.uValidFrames = 0;
  }
  this->m_InputFramesBeforeExec = this->m_BufferIn.uValidFrames;
  if ( this->m_bBypassed || (*((_BYTE *)this->m_pCtx + 375) & 1) != 0 )
  {
    if ( !this->m_LastBypassed )
      this->m_pEffect->vfptr->Reset(this->m_pEffect);
    uMaxFrames = this->m_BufferOut.uMaxFrames;
    in_uOutputConfig = this->m_BufferOut.uChannelMask;
    v14 = this->m_BufferIn.uChannelMask;
    v15 = this->m_BufferIn.uValidFrames < uMaxFrames;
    this->m_LastBypassed = 1;
    in_uInputConfig = v14;
    if ( v15 )
      uMaxFrames = this->m_BufferIn.uValidFrames;
    v16 = 0;
    v17 = uMaxFrames;
    for ( j = in_uOutputConfig; j; j &= j - 1 )
      ++v16;
    if ( v16 )
    {
      v19 = v16;
      do
      {
        memset((char *)this->m_BufferOut.pData + 4 * v4 * this->m_BufferOut.uMaxFrames, 0, 4 * v17);
        ++v4;
        --v19;
      }
      while ( v19 );
    }
    CAkSpeakerPan::GetSpeakerVolumes2DPan(0.0, 0.0, 1.0, 0, in_uInputConfig, in_uOutputConfig, &in_volumes);
    CAkMixer::DownMix(&this->m_BufferIn, &this->m_BufferOut, &in_volumes, v17);
    v20 = !this->m_bLast;
    this->m_BufferIn.uValidFrames = 0;
    if ( v20 )
    {
      v21 = AK_DataNeeded;
      if ( this->m_BufferOut.uValidFrames == this->m_BufferOut.uMaxFrames )
        v21 = AK_DataReady;
      this->m_BufferOut.eState = v21;
    }
    else
    {
      this->m_BufferOut.eState = AK_NoMoreData;
    }
  }
  else
  {
    m_pEffect = this->m_pEffect;
    m_uInOffset = this->m_uInOffset;
    this->m_LastBypassed = 0;
    ((void (__fastcall *)(AK::IAkOutOfPlaceEffectPlugin *, AkPipelineBuffer *, __int64, AkPipelineBuffer *))m_pEffect->vfptr[1].Term)(
      m_pEffect,
      &this->m_BufferIn,
      m_uInOffset,
      &this->m_BufferOut);
  }
  (*(void (__fastcall **)(CAkVPLFilterNodeOutOfPlace *, AkVPLState *))this->vfptr->gap8)(this, io_state);
}

// File Line: 147
// RVA: 0xA92610
void __fastcall CAkVPLFilterNodeOutOfPlace::ProcessDone(CAkVPLFilterNodeOutOfPlace *this, AkVPLState *io_state)
{
  AkPipelineBuffer *p_m_BufferOut; // r14
  unsigned int v3; // ebp
  AKRESULT eState; // eax
  signed int m_uConsumedSinceLastOutput; // eax
  float v8; // xmm1_4
  float v9; // xmm0_4
  unsigned int uValidFrames; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  __m128i v13; // xmm1
  unsigned int uSampleRate; // eax
  unsigned int m_uRequestedInputFrames; // eax
  AKRESULT v16; // eax

  p_m_BufferOut = &this->m_BufferOut;
  v3 = this->m_InputFramesBeforeExec - this->m_BufferIn.uValidFrames;
  CAkVPLNode::CopyRelevantMarkers(&this->m_BufferIn, &this->m_BufferOut, this->m_uInOffset, v3);
  if ( (this->m_pCtx->m_uRegisteredNotif & 0x10000) != 0 )
  {
    eState = this->m_BufferOut.eState;
    this->m_uConsumedSinceLastOutput += v3;
    if ( eState == AK_DataReady || eState == AK_NoMoreData )
    {
      m_uConsumedSinceLastOutput = this->m_uConsumedSinceLastOutput;
      v8 = this->m_fAveragedInput * 7.0;
      this->m_uConsumedSinceLastOutput = 0;
      v9 = (float)m_uConsumedSinceLastOutput;
      uValidFrames = this->m_BufferOut.uValidFrames;
      v11 = v8 + v9;
      v12 = this->m_fAveragedOutput * 7.0;
      this->m_fAveragedInput = v11 * 0.125;
      v13 = _mm_cvtsi32_si128(uValidFrames);
      uSampleRate = this->m_BufferIn.posInfo.uSampleRate;
      this->m_fAveragedOutput = (float)(_mm_cvtepi32_ps(v13).m128_f32[0] + v12) * 0.125;
      io_state->posInfo.uSampleRate = uSampleRate;
      io_state->posInfo.uStartPos = this->m_uInOffset + this->m_BufferIn.posInfo.uStartPos;
      io_state->posInfo.uFileEnd = this->m_BufferIn.posInfo.uFileEnd;
      io_state->posInfo.fLastRate = this->m_fAveragedInput / this->m_fAveragedOutput;
    }
  }
  this->m_uRequestedInputFrames += v3;
  m_uRequestedInputFrames = this->m_uRequestedInputFrames;
  this->m_uInOffset += v3;
  this->m_uConsumedInputFrames = m_uRequestedInputFrames;
  if ( !this->m_BufferIn.uValidFrames )
  {
    this->m_pInput->CAkVPLFilterNodeBase::CAkVPLNode::vfptr->ReleaseBuffer(this->m_pInput);
    AkPipelineBuffer::FreeMarkers(&this->m_BufferIn);
    this->m_BufferIn.pData = 0i64;
    *(_QWORD *)&this->m_BufferIn.eState = 43i64;
    this->m_BufferIn.posInfo.uStartPos = -1;
    this->m_BufferIn.posInfo.fLastRate = 1.0;
    this->m_BufferIn.posInfo.uFileEnd = -1;
    this->m_BufferIn.posInfo.uSampleRate = 1;
    io_state->pData = 0i64;
    io_state->uValidFrames = 0;
  }
  v16 = this->m_BufferOut.eState;
  if ( v16 == AK_DataReady || v16 == AK_NoMoreData )
  {
    this->m_BufferOut.posInfo.uStartPos = io_state->posInfo.uStartPos;
    this->m_BufferOut.posInfo.fLastRate = io_state->posInfo.fLastRate;
    this->m_BufferOut.posInfo.uFileEnd = io_state->posInfo.uFileEnd;
    this->m_BufferOut.posInfo.uSampleRate = io_state->posInfo.uSampleRate;
    io_state->pData = p_m_BufferOut->pData;
    *(_QWORD *)&io_state->uChannelMask = *(_QWORD *)&p_m_BufferOut->uChannelMask;
    *(_QWORD *)&io_state->uMaxFrames = *(_QWORD *)&p_m_BufferOut->uMaxFrames;
    *(_QWORD *)&io_state->uNumMarkers = *(_QWORD *)&p_m_BufferOut->uNumMarkers;
    io_state->pMarkers = p_m_BufferOut->pMarkers;
    *(_QWORD *)&io_state->posInfo.uStartPos = *(_QWORD *)&p_m_BufferOut->posInfo.uStartPos;
    *(_QWORD *)&io_state->posInfo.uFileEnd = *(_QWORD *)&p_m_BufferOut->posInfo.uFileEnd;
    v16 = this->m_BufferOut.eState;
  }
  io_state->result = v16;
}

// File Line: 209
// RVA: 0xA92810
void __fastcall CAkVPLFilterNodeOutOfPlace::ReleaseBuffer(CAkVPLFilterNodeOutOfPlace *this)
{
  void *pData; // rdx

  pData = this->m_BufferOut.pData;
  if ( pData )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, pData);
    this->m_BufferOut.pData = 0i64;
    *(_QWORD *)&this->m_BufferOut.eState = 43i64;
    this->m_BufferOut.uNumMarkers = 0;
    this->m_BufferOut.pMarkers = 0i64;
    this->m_BufferOut.posInfo.uStartPos = -1;
    this->m_BufferOut.posInfo.fLastRate = 1.0;
    this->m_BufferOut.posInfo.uFileEnd = -1;
    this->m_BufferOut.posInfo.uSampleRate = 1;
  }
}

// File Line: 221
// RVA: 0xA92910
__int64 __fastcall CAkVPLFilterNodeOutOfPlace::Seek(CAkVPLFilterNodeOutOfPlace *this)
{
  CAkVPLNode *m_pInput; // rcx

  this->m_pEffect->vfptr->Reset(this->m_pEffect);
  this->m_pInput->CAkVPLFilterNodeBase::CAkVPLNode::vfptr->ReleaseBuffer(this->m_pInput);
  AkPipelineBuffer::FreeMarkers(&this->m_BufferIn);
  *(_QWORD *)&this->m_BufferIn.eState = 43i64;
  this->m_BufferIn.pData = 0i64;
  this->m_BufferIn.posInfo.uStartPos = -1;
  this->m_BufferIn.posInfo.fLastRate = 1.0;
  this->m_BufferIn.posInfo.uFileEnd = -1;
  this->m_BufferIn.posInfo.uSampleRate = 1;
  m_pInput = this->m_pInput;
  this->m_bLast = 0;
  return ((__int64 (__fastcall *)(CAkVPLNode *))m_pInput->vfptr->Seek)(m_pInput);
}

// File Line: 236
// RVA: 0xA92A80
void __fastcall CAkVPLFilterNodeOutOfPlace::VirtualOn(
        CAkVPLFilterNodeOutOfPlace *this,
        AkVirtualQueueBehavior eBehavior)
{
  if ( eBehavior != AkVirtualQueueBehavior_Resume )
  {
    this->m_pEffect->vfptr->Reset(this->m_pEffect);
    ((void (__fastcall *)(CAkVPLFilterNodeOutOfPlace *))this->vfptr[1].TimeSkip)(this);
  }
  CAkVPLFilterNodeBase::VirtualOn(this, eBehavior);
}

// File Line: 252
// RVA: 0xA92500
__int64 __fastcall CAkVPLFilterNodeOutOfPlace::Init(
        CAkVPLFilterNodeOutOfPlace *this,
        AK::IAkOutOfPlaceEffectPlugin *in_pPlugin,
        AkFXDesc *in_fxDesc,
        unsigned int in_uFXIndex,
        CAkPBI *in_pCtx,
        AkAudioFormat *io_format)
{
  __int64 result; // rax
  AK::IAkOutOfPlaceEffectPlugin *m_pEffect; // rcx

  this->m_pEffect = in_pPlugin;
  *(_QWORD *)&this->m_BufferIn.eState = 43i64;
  this->m_BufferIn.pData = 0i64;
  this->m_BufferIn.uNumMarkers = 0;
  this->m_BufferIn.pMarkers = 0i64;
  this->m_BufferIn.posInfo.uStartPos = -1;
  this->m_BufferIn.posInfo.fLastRate = 1.0;
  this->m_BufferIn.posInfo.uFileEnd = -1;
  this->m_BufferIn.posInfo.uSampleRate = 1;
  this->m_BufferOut.pData = 0i64;
  this->m_BufferOut.uNumMarkers = 0;
  this->m_BufferOut.pMarkers = 0i64;
  *(_QWORD *)&this->m_BufferOut.eState = 43i64;
  this->m_BufferOut.posInfo.uStartPos = -1;
  this->m_BufferOut.posInfo.fLastRate = 1.0;
  this->m_BufferOut.posInfo.uFileEnd = -1;
  this->m_BufferOut.posInfo.uSampleRate = 1;
  *(_QWORD *)&this->m_uConsumedInputFrames = 0i64;
  this->m_fAveragedInput = 1.0;
  *(_QWORD *)&this->m_fAveragedOutput = 1065353216i64;
  result = CAkVPLFilterNodeBase::Init(this, in_pPlugin, in_fxDesc, in_uFXIndex, in_pCtx);
  if ( (_DWORD)result == 1 )
  {
    result = ((__int64 (__fastcall *)(AK::IAkOutOfPlaceEffectPlugin *, AkFXMemAlloc *, CAkInsertFXContext *, AK::IAkPluginParam *, AkAudioFormat *, AkAudioFormat *))this->m_pEffect->vfptr[1].__vecDelDtor)(
               this->m_pEffect,
               &AkFXMemAlloc::m_instanceLower,
               this->m_pInsertFXContext,
               this->m_pParam,
               io_format,
               io_format);
    if ( (_DWORD)result == 1 )
    {
      m_pEffect = this->m_pEffect;
      this->m_BufferOut.uChannelMask = *((_DWORD *)io_format + 1) & 0x3FFFF;
      return ((__int64 (__fastcall *)(AK::IAkOutOfPlaceEffectPlugin *))m_pEffect->vfptr->Reset)(m_pEffect);
    }
  }
  return result;
}

// File Line: 305
// RVA: 0xA92980
void __fastcall CAkVPLFilterNodeOutOfPlace::Term(CAkVPLFilterNodeOutOfPlace *this)
{
  AkPipelineBuffer *p_m_BufferOut; // rdi

  this->vfptr[1].ReleaseBuffer(this);
  CAkVPLFilterNodeBase::Term(this);
  p_m_BufferOut = &this->m_BufferOut;
  if ( this->m_BufferOut.pData )
  {
    AkPipelineBuffer::FreeMarkers(&this->m_BufferOut);
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, p_m_BufferOut->pData);
    p_m_BufferOut->pData = 0i64;
    *(_DWORD *)&this->m_BufferOut.uMaxFrames = 0;
  }
  AkPipelineBuffer::FreeMarkers(&this->m_BufferIn);
}

// File Line: 322
// RVA: 0xA928E0
void __fastcall CAkVPLFilterNodeOutOfPlace::ReleaseMemory(CAkVPLFilterNodeOutOfPlace *this)
{
  AK::IAkOutOfPlaceEffectPlugin *m_pEffect; // rcx

  m_pEffect = this->m_pEffect;
  if ( m_pEffect )
  {
    m_pEffect->vfptr->Term(m_pEffect, &AkFXMemAlloc::m_instanceLower);
    this->m_pEffect = 0i64;
  }
}

// File Line: 332
// RVA: 0xA929E0
__int64 __fastcall CAkVPLFilterNodeOutOfPlace::TimeSkip(CAkVPLFilterNodeOutOfPlace *this, unsigned int *io_uFrames)
{
  AK::IAkOutOfPlaceEffectPlugin *m_pEffect; // rcx
  AKRESULT v5; // eax
  AKRESULT v6; // edx
  CAkVPLNode *m_pInput; // rcx
  AKRESULT v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // [rsp+30h] [rbp+8h] BYREF
  int v13; // [rsp+40h] [rbp+18h] BYREF

  if ( this->m_bLast )
    return 17i64;
  m_pEffect = this->m_pEffect;
  v12 = *io_uFrames;
  v5 = ((unsigned int (__fastcall *)(AK::IAkOutOfPlaceEffectPlugin *, unsigned int *))m_pEffect->vfptr[1].Reset)(
         m_pEffect,
         &v12);
  this->m_uRequestedInputFrames += v12;
  v6 = v5;
  v12 = this->m_uRequestedInputFrames - this->m_uConsumedInputFrames;
  if ( v12 >= 0x400 )
  {
    do
    {
      if ( v6 != AK_DataReady )
        break;
      m_pInput = this->m_pInput;
      v13 = 1024;
      v8 = m_pInput->vfptr->TimeSkip(m_pInput, (unsigned int *)&v13);
      v9 = v12;
      v6 = v8;
      v10 = v13;
      this->m_uConsumedInputFrames += v13;
      v11 = v9 - v10;
      v12 = v11;
      this->m_bLast = v6 == AK_NoMoreData;
    }
    while ( v11 >= 0x400 );
  }
  return (unsigned int)v6;
}

// File Line: 367
// RVA: 0xA92880
__int64 __fastcall CAkVPLFilterNodeOutOfPlace::ReleaseInputBuffer(CAkVPLFilterNodeOutOfPlace *this)
{
  CAkVPLNode *m_pInput; // rcx
  __int64 result; // rax

  m_pInput = this->m_pInput;
  if ( m_pInput )
    m_pInput->vfptr->ReleaseBuffer(m_pInput);
  AkPipelineBuffer::FreeMarkers(&this->m_BufferIn);
  *(_QWORD *)&this->m_BufferIn.eState = 43i64;
  result = 1i64;
  this->m_BufferIn.pData = 0i64;
  this->m_BufferIn.posInfo.uStartPos = -1;
  this->m_BufferIn.posInfo.fLastRate = 1.0;
  this->m_BufferIn.posInfo.uFileEnd = -1;
  this->m_BufferIn.posInfo.uSampleRate = 1;
  return result;
}

// File Line: 377
// RVA: 0xA924F0
__int64 __fastcall UFG::UIList::getNumSlots(CAkVPLFilterNodeOutOfPlace *this)
{
  return this->m_BufferOut.uChannelMask;
}

