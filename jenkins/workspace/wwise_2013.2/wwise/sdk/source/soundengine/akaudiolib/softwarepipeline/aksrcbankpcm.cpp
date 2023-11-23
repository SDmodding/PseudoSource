// File Line: 32
// RVA: 0xA98E10
void __fastcall CAkSrcBankPCM::CAkSrcBankPCM(CAkSrcBankPCM *this, CAkPBI *in_pCtx)
{
  CAkSrcBaseEx::CAkSrcBaseEx(this, in_pCtx);
  this->vfptr = (CAkVPLNodeVtbl *)&CAkSrcBankPCM::`vftable;
}

// File Line: 55
// RVA: 0xA98F90
__int64 __fastcall CAkSrcBankPCM::StartStream(CAkSrcBankPCM *this)
{
  CAkPBI *m_pCtx; // rax
  char *m_pDataPtr; // rsi
  unsigned int m_uDataSize; // ebp
  unsigned int *p_m_uDataOffset; // r12
  unsigned int *p_m_uDataSize; // r13
  unsigned int *p_m_uPCMLoopEnd; // r14
  unsigned int *p_m_uPCMLoopStart; // r15
  WaveFormatExtensible *pFormat; // rdi
  CAkPBI *v11; // rcx
  __int64 v12; // r9
  unsigned int v13; // r8d
  bool v14; // zf
  CAkPBI *v15; // rax
  AkFileParser::AnalysisDataChunk out_pAnalysisData; // [rsp+50h] [rbp-48h] BYREF
  AkFileParser::FormatInfo out_pFormatInfo; // [rsp+60h] [rbp-38h] BYREF
  AkAudioFormat v18; // [rsp+A0h] [rbp+8h]

  m_pCtx = this->m_pCtx;
  m_pDataPtr = m_pCtx->m_pDataPtr;
  m_uDataSize = m_pCtx->m_uDataSize;
  if ( !m_pDataPtr )
    return 2i64;
  p_m_uDataOffset = &this->m_uDataOffset;
  p_m_uDataSize = &this->m_uDataSize;
  out_pAnalysisData.uDataSize = 0;
  out_pAnalysisData.pData = 0i64;
  p_m_uPCMLoopEnd = &this->m_uPCMLoopEnd;
  p_m_uPCMLoopStart = &this->m_uPCMLoopStart;
  if ( AkFileParser::Parse(
         m_pDataPtr,
         m_uDataSize,
         &out_pFormatInfo,
         &this->m_markers,
         &this->m_uPCMLoopStart,
         &this->m_uPCMLoopEnd,
         &this->m_uDataSize,
         &this->m_uDataOffset,
         &out_pAnalysisData,
         0i64) != AK_Success )
    return 7i64;
  pFormat = out_pFormatInfo.pFormat;
  if ( out_pFormatInfo.pFormat->wFormatTag != 0xFFFE )
    return 7i64;
  v18.uSampleRate = out_pFormatInfo.pFormat->nSamplesPerSec;
  *((_DWORD *)&v18 + 1) = out_pFormatInfo.pFormat->dwChannelMask & 0x3FFFF | ((out_pFormatInfo.pFormat->wBitsPerSample & 0x3F | ((out_pFormatInfo.pFormat->nBlockAlign & 0x1F) << 6)) << 18);
  v11 = this->m_pCtx;
  v11->m_sMediaFormat = v18;
  CAkPBI::InvalidateFeedbackParameters(v11);
  if ( out_pAnalysisData.uDataSize )
    this->m_pAnalysisData = out_pAnalysisData.pData;
  v12 = *p_m_uDataOffset;
  v13 = *p_m_uDataSize;
  this->m_pucDataStart = &m_pDataPtr[v12];
  v14 = *p_m_uPCMLoopEnd == 0;
  this->m_uTotalSamples = v13 / pFormat->nBlockAlign;
  if ( v14 || this->m_uLoopCnt == 1 )
    *p_m_uPCMLoopEnd = v13 / pFormat->nBlockAlign - 1;
  if ( *p_m_uPCMLoopEnd < *p_m_uPCMLoopStart
    || *p_m_uPCMLoopEnd >= this->m_uTotalSamples
    || m_uDataSize != v13 + (_DWORD)v12 )
  {
    return 2i64;
  }
  v15 = this->m_pCtx;
  this->m_uCurSample = 0;
  if ( (*((_BYTE *)v15 + 375) & 2) != 0 )
    return CAkSrcBankPCM::ChangeSourcePosition(this);
  else
    return 1i64;
}

// File Line: 150
// RVA: 0xA98F30
__int64 __fastcall CAkSrcBankPCM::RelocateMedia(CAkSrcBankPCM *this, char *in_pNewMedia, char *in_pOldMedia)
{
  if ( this->m_pucDataStart )
    this->m_pucDataStart = &in_pNewMedia[this->m_uDataOffset];
  return 1i64;
}

// File Line: 159
// RVA: 0xA98E80
void __fastcall CAkSrcBankPCM::GetBuffer(CAkSrcBankPCM *this, AkVPLState *io_state)
{
  CAkPBI *m_pCtx; // r9
  unsigned __int16 uMaxFrames; // r8
  unsigned int m_uTotalSamples; // ecx
  unsigned int m_uCurSample; // edx

  m_pCtx = this->m_pCtx;
  uMaxFrames = io_state->uMaxFrames;
  if ( this->m_uLoopCnt == 1 )
    m_uTotalSamples = this->m_uTotalSamples;
  else
    m_uTotalSamples = this->m_uPCMLoopEnd + 1;
  m_uCurSample = this->m_uCurSample;
  if ( m_uCurSample + uMaxFrames > m_uTotalSamples )
    uMaxFrames = m_uTotalSamples - m_uCurSample;
  CAkSrcBaseEx::SubmitBufferAndUpdate(
    this,
    &this->m_pucDataStart[(HIBYTE(*((_DWORD *)&m_pCtx->m_sMediaFormat + 1)) & 0x1F) * m_uCurSample],
    uMaxFrames,
    m_pCtx->m_sMediaFormat.uSampleRate,
    *((_DWORD *)&m_pCtx->m_sMediaFormat + 1) & 0x3FFFF,
    io_state);
}

// File Line: 177
// RVA: 0xA99160
__int64 __fastcall CAkSrcBankPCM::VirtualOff(
        CAkSrcBankPCM *this,
        AkVirtualQueueBehavior eBehavior,
        bool in_bUseSourceOffset)
{
  CAkPBI *m_pCtx; // rax
  CAkPBI *v6; // rax

  if ( eBehavior == AkVirtualQueueBehavior_FromBeginning )
  {
    m_pCtx = this->m_pCtx;
    this->m_uCurSample = 0;
    this->m_uLoopCnt = m_pCtx->m_LoopCount;
    return 1i64;
  }
  if ( !in_bUseSourceOffset || eBehavior != AkVirtualQueueBehavior_FromElapsedTime )
    return 1i64;
  this->m_uCurSample = CAkSrcBaseEx::GetSourceOffset(this);
  v6 = this->m_pCtx;
  *((_BYTE *)v6 + 375) &= 0xF1u;
  v6->m_uSeekPosition = 0;
  return 2 - (unsigned int)(this->m_uCurSample < this->m_uTotalSamples);
}

// File Line: 205
// RVA: 0xA98F50
__int64 __fastcall CAkSrcBankPCM::ChangeSourcePosition(CAkSrcBankPCM *this)
{
  CAkPBI *m_pCtx; // rax

  this->m_uCurSample = CAkSrcBaseEx::GetSourceOffset(this);
  m_pCtx = this->m_pCtx;
  *((_BYTE *)m_pCtx + 375) &= 0xF1u;
  m_pCtx->m_uSeekPosition = 0;
  return 2 - (unsigned int)(this->m_uCurSample < this->m_uTotalSamples);
}

