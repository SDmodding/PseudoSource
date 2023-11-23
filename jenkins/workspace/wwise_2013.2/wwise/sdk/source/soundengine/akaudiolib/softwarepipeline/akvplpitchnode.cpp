// File Line: 27
// RVA: 0xA844B0
void __fastcall CAkVPLPitchNode::GetBuffer(CAkVPLPitchNode *this, AkVPLState *io_state)
{
  unsigned int uMaxFrames; // eax
  float v5; // xmm0_4

  uMaxFrames = io_state->uMaxFrames;
  this->m_bStartPosInfoUpdated = 0;
  this->m_Pitch.m_InternalPitchState.uRequestedFrames = uMaxFrames;
  v5 = this->m_pInput->CAkVPLNode::vfptr->GetPitch(this->m_pInput);
  CAkResampler::SetPitch(&this->m_Pitch, v5);
  if ( this->m_BufferIn.uValidFrames )
  {
    CAkVPLPitchNode::ConsumeBuffer(this, io_state);
  }
  else if ( this->m_bLast )
  {
    io_state->result = AK_NoMoreData;
  }
}

// File Line: 63
// RVA: 0xA841B0
void __fastcall CAkVPLPitchNode::ConsumeBuffer(CAkVPLPitchNode *this, AkVPLState *io_state)
{
  AkPipelineBuffer *p_m_BufferOut; // r15
  CAkPBI *m_pPBI; // rax
  int m_iFrameOffset; // ebx
  signed int v7; // ebx
  CAkPBI *v8; // rax
  signed int m_uSeekPosition; // ecx
  int v10; // edx
  unsigned __int16 uValidFrames; // bx
  unsigned int uInFrameOffset; // r13d
  AKRESULT Src; // ebp
  unsigned int uStartPos; // ecx
  float fLastRate; // eax
  float LastRate; // xmm0_4
  bool v17; // zf
  AKRESULT v18; // eax

  if ( io_state->result == AK_NoMoreData )
    this->m_bLast = 1;
  if ( !this->m_BufferIn.uValidFrames )
  {
    if ( !io_state->uValidFrames && io_state->result == AK_DataReady )
    {
      io_state->result = AK_DataNeeded;
      return;
    }
    this->m_BufferIn = io_state->AkPipelineBuffer;
  }
  p_m_BufferOut = &this->m_BufferOut;
  if ( !this->m_BufferOut.pData )
  {
    if ( (unsigned int)AkPipelineBufferBase::GetCachedBuffer(
                         &this->m_BufferOut,
                         this->m_Pitch.m_InternalPitchState.uRequestedFrames,
                         this->m_BufferIn.uChannelMask) != 1 )
    {
      io_state->result = AK_Fail;
      return;
    }
    if ( this->m_bPadFrameOffset )
    {
      m_pPBI = this->m_pPBI;
      m_iFrameOffset = m_pPBI->m_iFrameOffset;
      if ( *((char *)m_pPBI + 374) < 0 )
        v7 = m_iFrameOffset + 8;
      else
        v7 = m_iFrameOffset + 1024;
      if ( v7 > 0 )
      {
        if ( CAkResampler::IsPostDeInterleaveRequired(&this->m_Pitch) )
          ZeroPrePadBufferInterleaved(p_m_BufferOut, v7);
        else
          ZeroPrePadBuffer(p_m_BufferOut, v7);
        this->m_Pitch.m_InternalPitchState.uOutFrameOffset = v7;
      }
      this->m_bPadFrameOffset = 0;
    }
  }
  v8 = this->m_pPBI;
  if ( (*((_BYTE *)v8 + 375) & 2) != 0 || (m_uSeekPosition = v8->m_uSeekPosition) == 0 )
  {
LABEL_24:
    uValidFrames = this->m_BufferIn.uValidFrames;
    uInFrameOffset = this->m_Pitch.m_InternalPitchState.uInFrameOffset;
    Src = CAkResampler::Execute(&this->m_Pitch, &this->m_BufferIn, p_m_BufferOut);
    CAkVPLNode::CopyRelevantMarkers(
      &this->m_BufferIn,
      p_m_BufferOut,
      uInFrameOffset,
      (unsigned __int16)(uValidFrames - this->m_BufferIn.uValidFrames));
    uStartPos = this->m_BufferIn.posInfo.uStartPos;
    if ( uStartPos != -1 && !this->m_bStartPosInfoUpdated )
    {
      fLastRate = this->m_BufferIn.posInfo.fLastRate;
      this->m_bStartPosInfoUpdated = 1;
      this->m_BufferOut.posInfo.fLastRate = fLastRate;
      this->m_BufferOut.posInfo.uFileEnd = this->m_BufferIn.posInfo.uFileEnd;
      this->m_BufferOut.posInfo.uSampleRate = this->m_BufferIn.posInfo.uSampleRate;
      this->m_BufferOut.posInfo.uStartPos = uStartPos + uInFrameOffset;
    }
    LastRate = CAkResampler::GetLastRate(&this->m_Pitch);
    v17 = this->m_BufferIn.uValidFrames == 0;
    this->m_BufferOut.posInfo.fLastRate = LastRate;
    if ( v17 )
    {
      CAkVPLPitchNode::ReleaseInputBuffer(this, io_state);
      if ( this->m_bLast )
      {
        if ( !this->m_pCbx->m_pSources[1] )
        {
          Src = AK_NoMoreData;
          goto LABEL_33;
        }
        Src = CAkVPLPitchNode::SwitchToNextSrc(this);
      }
    }
    if ( Src != AK_DataReady && Src != AK_NoMoreData )
    {
LABEL_36:
      io_state->result = Src;
      return;
    }
LABEL_33:
    if ( CAkResampler::IsPostDeInterleaveRequired(&this->m_Pitch) )
      CAkResampler::DeinterleaveAndSwapOutput(&this->m_Pitch, p_m_BufferOut);
    io_state->pData = p_m_BufferOut->pData;
    *(_QWORD *)&io_state->uChannelMask = *(_QWORD *)&p_m_BufferOut->uChannelMask;
    *(_QWORD *)&io_state->uMaxFrames = *(_QWORD *)&p_m_BufferOut->uMaxFrames;
    *(_QWORD *)&io_state->uNumMarkers = *(_QWORD *)&p_m_BufferOut->uNumMarkers;
    io_state->pMarkers = p_m_BufferOut->pMarkers;
    *(_QWORD *)&io_state->posInfo.uStartPos = *(_QWORD *)&p_m_BufferOut->posInfo.uStartPos;
    *(_QWORD *)&io_state->posInfo.uFileEnd = *(_QWORD *)&p_m_BufferOut->posInfo.uFileEnd;
    goto LABEL_36;
  }
  v10 = this->m_BufferIn.uValidFrames;
  if ( v10 > m_uSeekPosition )
  {
    this->m_Pitch.m_InternalPitchState.uInFrameOffset = m_uSeekPosition;
    this->m_BufferIn.uValidFrames = v10 - m_uSeekPosition;
    *((_BYTE *)v8 + 375) &= 0xF1u;
    v8->m_uSeekPosition = 0;
    goto LABEL_24;
  }
  *((_BYTE *)v8 + 375) &= 0xF1u;
  v8->m_uSeekPosition = m_uSeekPosition - v10;
  this->m_BufferIn.uValidFrames = 0;
  io_state->uValidFrames = 0;
  CAkVPLPitchNode::ReleaseInputBuffer(this, io_state);
  v18 = AK_DataNeeded;
  if ( this->m_bLast )
    v18 = AK_NoMoreData;
  io_state->result = v18;
}

// File Line: 278
// RVA: 0xA846D0
__int64 __fastcall CAkVPLPitchNode::SwitchToNextSrc(CAkVPLPitchNode *this)
{
  CAkVPLSrcCbxNode *m_pCbx; // rax
  CAkPBI *m_pCtx; // rbx
  int m_iFrameOffset; // ecx
  int v5; // eax
  __int64 result; // rax
  int StreamedData; // eax
  AkAudioFormat m_sMediaFormat; // rax
  CAkVPLSrcCbxNode *v9; // rax
  unsigned int in_uSampleRate; // edi
  float v11; // xmm0_4
  bool v12; // zf
  AkAudioFormat in_fmt; // [rsp+40h] [rbp+8h] BYREF

  m_pCbx = this->m_pCbx;
  m_pCtx = m_pCbx->m_pSources[1]->m_pCtx;
  m_iFrameOffset = m_pCtx->m_iFrameOffset;
  if ( m_iFrameOffset > 0 )
  {
    v5 = m_pCtx->m_iFrameOffset;
    if ( this->m_BufferOut.uMaxFrames - this->m_BufferOut.uValidFrames < m_iFrameOffset )
      v5 = this->m_BufferOut.uMaxFrames - this->m_BufferOut.uValidFrames;
    m_pCtx->m_iFrameOffset = m_iFrameOffset - v5;
    return 17i64;
  }
  StreamedData = CAkVPLSrcNode::FetchStreamedData(m_pCbx->m_pSources[1]);
  if ( StreamedData == 63 )
    return 17i64;
  if ( StreamedData != 1 )
    return 2i64;
  m_sMediaFormat = this->m_pPBI->m_sMediaFormat;
  in_fmt = m_pCtx->m_sMediaFormat;
  if ( ((*((_DWORD *)&m_sMediaFormat + 1) ^ *((_DWORD *)&in_fmt + 1)) & 0x3FFFF) != 0 )
    return 17i64;
  CAkVPLSrcCbxNode::SwitchToNextSrc(this->m_pCbx);
  v9 = this->m_pCbx;
  this->m_pPBI = m_pCtx;
  this->m_pInput = v9->m_pSources[0];
  if ( (*((_BYTE *)m_pCtx + 372) & 0x20) == 0 )
    m_pCtx->CAkTransportAware::vfptr[7].~CAkTransportAware(m_pCtx);
  in_uSampleRate = this->m_pCbx->m_uSampleRate;
  v11 = this->m_pInput->CAkVPLNode::vfptr->GetPitch(this->m_pInput);
  CAkResampler::SwitchTo(&this->m_Pitch, &in_fmt, v11, &this->m_BufferOut, in_uSampleRate);
  v12 = this->m_BufferOut.uValidFrames == this->m_Pitch.m_InternalPitchState.uRequestedFrames;
  result = 45i64;
  this->m_bLast = 0;
  if ( !v12 )
    return 43i64;
  return result;
}

// File Line: 330
// RVA: 0xA84550
void __fastcall CAkVPLPitchNode::ReleaseBuffer(CAkVPLPitchNode *this)
{
  AkPipelineBuffer *p_m_BufferOut; // rbx

  p_m_BufferOut = &this->m_BufferOut;
  if ( this->m_BufferOut.pData )
  {
    AkPipelineBufferBase::ReleaseCachedBuffer(&this->m_BufferOut);
    *(_QWORD *)&p_m_BufferOut->eState = 43i64;
    p_m_BufferOut->pData = 0i64;
    p_m_BufferOut->uNumMarkers = 0;
    p_m_BufferOut->pMarkers = 0i64;
    p_m_BufferOut->posInfo.uStartPos = -1;
    p_m_BufferOut->posInfo.fLastRate = 1.0;
    p_m_BufferOut->posInfo.uFileEnd = -1;
    p_m_BufferOut->posInfo.uSampleRate = 1;
    this->m_Pitch.m_InternalPitchState.uOutFrameOffset = 0;
  }
}

// File Line: 351
// RVA: 0xA845C0
void __fastcall CAkVPLPitchNode::ReleaseInputBuffer(CAkVPLPitchNode *this, AkPipelineBuffer *io_buffer)
{
  this->m_pInput->CAkVPLNode::vfptr->ReleaseBuffer(this->m_pInput);
  AkPipelineBuffer::FreeMarkers(&this->m_BufferIn);
  *(_QWORD *)&this->m_BufferIn.eState = 43i64;
  this->m_BufferIn.pData = 0i64;
  this->m_BufferIn.posInfo.uStartPos = -1;
  this->m_BufferIn.posInfo.fLastRate = 1.0;
  this->m_BufferIn.posInfo.uFileEnd = -1;
  this->m_BufferIn.posInfo.uSampleRate = 1;
  io_buffer->pData = 0i64;
  io_buffer->uNumMarkers = 0;
  io_buffer->pMarkers = 0i64;
}

// File Line: 366
// RVA: 0xA84880
__int64 __fastcall CAkVPLPitchNode::TimeSkip(CAkVPLPitchNode *this, unsigned int *io_uFrames)
{
  float v4; // xmm0_4
  int v5; // esi
  unsigned int v6; // ebp
  unsigned int v7; // edi
  CAkVPLNode *m_pInput; // rcx
  __int64 result; // rax
  CAkPBI *m_pPBI; // rdx
  unsigned int m_uSeekPosition; // ecx
  unsigned int v12; // r8d
  unsigned int v13; // r8d
  unsigned int uValidFrames; // eax
  bool v15; // zf
  unsigned int v16; // [rsp+40h] [rbp+8h] BYREF

  v4 = this->m_pInput->CAkVPLNode::vfptr->GetPitch(this->m_pInput);
  CAkResampler::SetPitchForTimeSkip(&this->m_Pitch, v4);
  v5 = 0;
  v6 = 45;
  v7 = (int)(float)((float)((float)((float)(int)this->m_Pitch.m_InternalPitchState.uCurrentFrameSkip * 0.000015258789)
                          * (float)(int)*io_uFrames)
                  + 0.5);
  if ( v7 )
  {
    while ( 1 )
    {
      if ( !this->m_BufferIn.uValidFrames && !this->m_bLast )
      {
        m_pInput = this->m_pInput;
        v16 = *io_uFrames;
        result = ((__int64 (__fastcall *)(CAkVPLNode *, unsigned int *))m_pInput->vfptr->TimeSkip)(m_pInput, &v16);
        if ( (_DWORD)result != 45 )
        {
          if ( (_DWORD)result != 17 )
            return result;
          this->m_bLast = 1;
        }
        m_pPBI = this->m_pPBI;
        if ( (*((_BYTE *)m_pPBI + 375) & 2) != 0 )
          m_uSeekPosition = 0;
        else
          m_uSeekPosition = m_pPBI->m_uSeekPosition;
        v12 = 0;
        if ( m_uSeekPosition > v16 )
        {
          v13 = m_uSeekPosition;
          m_uSeekPosition = v16;
          v12 = v13 - v16;
        }
        v16 -= m_uSeekPosition;
        *((_BYTE *)m_pPBI + 375) &= 0xF1u;
        m_pPBI->m_uSeekPosition = v12;
        this->m_BufferIn.uValidFrames = v16;
      }
      uValidFrames = this->m_BufferIn.uValidFrames;
      if ( v7 < uValidFrames )
        uValidFrames = v7;
      v5 += uValidFrames;
      v7 -= uValidFrames;
      v15 = this->m_BufferIn.uValidFrames == (unsigned __int16)uValidFrames;
      this->m_BufferIn.uValidFrames -= uValidFrames;
      if ( v15 && this->m_bLast )
        break;
      if ( !v7 )
        goto LABEL_20;
    }
    v6 = 17;
  }
LABEL_20:
  result = v6;
  *io_uFrames = (int)(float)((float)((float)v5
                                   / (float)((float)(int)this->m_Pitch.m_InternalPitchState.uCurrentFrameSkip
                                           * 0.000015258789))
                           + 0.5);
  return result;
}

// File Line: 444
// RVA: 0xA84A20
void __fastcall CAkVPLPitchNode::VirtualOn(CAkVPLPitchNode *this, AkVirtualQueueBehavior eBehavior)
{
  if ( eBehavior != AkVirtualQueueBehavior_Resume )
  {
    if ( this->m_BufferIn.pData )
      this->m_pInput->CAkVPLNode::vfptr->ReleaseBuffer(this->m_pInput);
    AkPipelineBuffer::FreeMarkers(&this->m_BufferIn);
    *(_QWORD *)&this->m_BufferIn.eState = 43i64;
    this->m_BufferIn.pData = 0i64;
    this->m_BufferIn.posInfo.uStartPos = -1;
    this->m_BufferIn.posInfo.fLastRate = 1.0;
    this->m_BufferIn.posInfo.uFileEnd = -1;
    this->m_BufferIn.posInfo.uSampleRate = 1;
    CAkResampler::ResetOffsets(&this->m_Pitch);
  }
  if ( eBehavior == AkVirtualQueueBehavior_FromBeginning )
    this->m_bLast = 0;
  if ( !this->m_bLast )
    this->m_pInput->CAkVPLNode::vfptr->VirtualOn(this->m_pInput, eBehavior);
}

// File Line: 471
// RVA: 0xA849F0
__int64 __fastcall CAkVPLPitchNode::VirtualOff(CAkVPLPitchNode *this, __int64 eBehavior, __int64 in_bUseSourceOffset)
{
  if ( (_DWORD)eBehavior == 1 )
    this->m_BufferIn.uValidFrames = 0;
  if ( this->m_bLast )
    return 1i64;
  else
    return ((__int64 (__fastcall *)(CAkVPLNode *, __int64, __int64))this->m_pInput->CAkVPLNode::vfptr->VirtualOff)(
             this->m_pInput,
             eBehavior,
             in_bUseSourceOffset);
}

// File Line: 485
// RVA: 0xA84650
__int64 __fastcall CAkVPLPitchNode::Seek(CAkVPLPitchNode *this)
{
  CAkVPLNode *m_pInput; // rcx

  this->m_pInput->CAkVPLNode::vfptr->ReleaseBuffer(this->m_pInput);
  AkPipelineBuffer::FreeMarkers(&this->m_BufferIn);
  *(_QWORD *)&this->m_BufferIn.eState = 43i64;
  this->m_BufferIn.pData = 0i64;
  this->m_BufferIn.posInfo.uStartPos = -1;
  this->m_BufferIn.posInfo.fLastRate = 1.0;
  this->m_BufferIn.posInfo.uFileEnd = -1;
  this->m_BufferIn.posInfo.uSampleRate = 1;
  CAkResampler::ResetOffsets(&this->m_Pitch);
  m_pInput = this->m_pInput;
  this->m_bLast = 0;
  return ((__int64 (__fastcall *)(CAkVPLNode *))m_pInput->vfptr->Seek)(m_pInput);
}

// File Line: 512
// RVA: 0xA84520
void __fastcall CAkVPLPitchNode::Init(
        CAkVPLPitchNode *this,
        AkAudioFormat *io_pFormat,
        CAkPBI *in_pPBI,
        unsigned int in_usSampleRate)
{
  this->m_pPBI = in_pPBI;
  this->m_bLast = 0;
  this->m_bPadFrameOffset = 1;
  CAkResampler::Init(&this->m_Pitch, io_pFormat, in_usSampleRate);
}

// File Line: 531
// RVA: 0xA84820
void __fastcall CAkVPLPitchNode::Term(CAkVPLPitchNode *this)
{
  if ( this->m_BufferOut.pData )
  {
    AkPipelineBuffer::FreeMarkers(&this->m_BufferOut);
    AkPipelineBufferBase::ReleaseCachedBuffer(&this->m_BufferOut);
  }
  AkPipelineBuffer::FreeMarkers(&this->m_BufferIn);
  this->m_pPBI = 0i64;
  _((AMD_HD3D *)&this->m_Pitch);
}

// File Line: 554
// RVA: 0xA84630
void __fastcall CAkVPLPitchNode::RelocateMedia(CAkVPLPitchNode *this, char *in_pNewMedia, char *in_pOldMedia)
{
  _BYTE *pData; // rax

  pData = this->m_BufferIn.pData;
  if ( pData )
    this->m_BufferIn.pData = &in_pNewMedia[pData - in_pOldMedia];
}

