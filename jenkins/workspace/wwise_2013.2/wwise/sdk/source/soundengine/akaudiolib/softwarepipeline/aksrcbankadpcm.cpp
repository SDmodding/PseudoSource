// File Line: 29
// RVA: 0xA9A6C0
void __fastcall CAkSrcBankADPCM::CAkSrcBankADPCM(CAkSrcBankADPCM *this, CAkPBI *in_pCtx)
{
  CAkSrcBaseEx::CAkSrcBaseEx(this, in_pCtx);
  this->vfptr = (CAkVPLNodeVtbl *)&CAkSrcBankADPCM::`vftable;
  this->m_pucData = 0i64;
  this->m_pOutBuffer = 0i64;
}

// File Line: 38
// RVA: 0xA9A9C0
__int64 __fastcall CAkSrcBankADPCM::StartStream(CAkSrcBankADPCM *this)
{
  CAkPBI *m_pCtx; // rax
  char *m_pDataPtr; // rsi
  unsigned int m_uDataSize; // r12d
  unsigned int *p_m_uDataOffset; // r15
  unsigned int *p_m_uPCMLoopEnd; // r14
  unsigned int *p_m_uPCMLoopStart; // r13
  AKRESULT v9; // edi
  WaveFormatExtensible *pFormat; // rbp
  CAkPBI *v11; // rcx
  unsigned int nBlockAlign; // ecx
  unsigned int v13; // r8d
  int v14; // eax
  bool v15; // zf
  __int64 v16; // rax
  AkFileParser::AnalysisDataChunk out_pAnalysisData; // [rsp+50h] [rbp-48h] BYREF
  AkFileParser::FormatInfo out_pFormatInfo; // [rsp+60h] [rbp-38h] BYREF
  AkAudioFormat v19; // [rsp+A0h] [rbp+8h]

  m_pCtx = this->m_pCtx;
  m_pDataPtr = m_pCtx->m_pDataPtr;
  m_uDataSize = m_pCtx->m_uDataSize;
  if ( !m_pDataPtr )
    return 2i64;
  out_pAnalysisData.uDataSize = 0;
  out_pAnalysisData.pData = 0i64;
  p_m_uDataOffset = &this->m_uDataOffset;
  p_m_uPCMLoopEnd = &this->m_uPCMLoopEnd;
  p_m_uPCMLoopStart = &this->m_uPCMLoopStart;
  v9 = AkFileParser::Parse(
         m_pDataPtr,
         m_uDataSize,
         &out_pFormatInfo,
         &this->m_markers,
         &this->m_uPCMLoopStart,
         &this->m_uPCMLoopEnd,
         &this->m_uDataSize,
         &this->m_uDataOffset,
         &out_pAnalysisData,
         0i64);
  if ( v9 != AK_Success )
    return 7i64;
  pFormat = out_pFormatInfo.pFormat;
  if ( out_pFormatInfo.pFormat->wFormatTag != 2 )
    return 7i64;
  v19.uSampleRate = out_pFormatInfo.pFormat->nSamplesPerSec;
  *((_DWORD *)&v19 + 1) = out_pFormatInfo.pFormat->dwChannelMask & 0x3FFFF | (out_pFormatInfo.pFormat->nChannels << 25) & 0x1F000000 | 0x400000;
  v11 = this->m_pCtx;
  v11->m_sMediaFormat = v19;
  CAkPBI::InvalidateFeedbackParameters(v11);
  if ( out_pAnalysisData.uDataSize )
    this->m_pAnalysisData = out_pAnalysisData.pData;
  nBlockAlign = pFormat->nBlockAlign;
  v13 = this->m_uDataSize;
  this->m_uInputBlockSize = nBlockAlign;
  v14 = (v13 << 6) / nBlockAlign;
  v15 = *p_m_uPCMLoopEnd == 0;
  this->m_uTotalSamples = v14;
  if ( v15 || this->m_uLoopCnt == 1 )
    *p_m_uPCMLoopEnd = v14 - 1;
  if ( *p_m_uPCMLoopEnd < *p_m_uPCMLoopStart
    || *p_m_uPCMLoopEnd >= this->m_uTotalSamples
    || m_uDataSize != v13 + *p_m_uDataOffset )
  {
    v9 = AK_Fail;
  }
  v16 = *p_m_uDataOffset;
  this->m_uCurSample = 0;
  this->m_pucData = &m_pDataPtr[v16];
  if ( (*((_BYTE *)this->m_pCtx + 375) & 2) != 0 )
    return CAkSrcBankADPCM::SeekToSourceOffset(this);
  else
    return (unsigned int)v9;
}

// File Line: 131
// RVA: 0xA9A930
__int64 __fastcall CAkSrcBankADPCM::RelocateMedia(CAkSrcBankADPCM *this, char *in_pNewMedia, char *in_pOldMedia)
{
  __int64 result; // rax

  result = 1i64;
  this->m_pucData += in_pNewMedia - in_pOldMedia;
  return result;
}

// File Line: 145
// RVA: 0xA9AB80
void __fastcall CAkSrcBankADPCM::StopStream(CAkSrcBankADPCM *this)
{
  this->vfptr->ReleaseBuffer(this);
  CAkSrcBaseEx::StopStream(this);
}

// File Line: 151
// RVA: 0xA9A8D0
void __fastcall CAkSrcBankADPCM::ReleaseBuffer(CAkSrcBankADPCM *this)
{
  char *m_pOutBuffer; // rdx
  CAkPBI *m_pCtx; // rax
  int v4; // ecx
  int i; // eax

  m_pOutBuffer = this->m_pOutBuffer;
  if ( m_pOutBuffer )
  {
    m_pCtx = this->m_pCtx;
    v4 = 0;
    for ( i = *((_DWORD *)&m_pCtx->m_sMediaFormat + 1) & 0x3FFFF; i; i &= i - 1 )
      ++v4;
    CAkLEngine::ReleaseCachedAudioBuffer(v4 << 11, m_pOutBuffer);
    this->m_pOutBuffer = 0i64;
  }
}

// File Line: 161
// RVA: 0xA9A740
void __fastcall CAkSrcBankADPCM::GetBuffer(CAkSrcBankADPCM *this, AkVPLState *io_state)
{
  CAkPBI *m_pCtx; // r12
  __int64 v3; // r14
  unsigned int nChannels; // ebx
  int i; // r8d
  char *CachedAudioBuffer; // rsi
  unsigned __int16 uMaxFrames; // dx
  unsigned int m_uTotalSamples; // ecx
  int v11; // ebp
  __int64 v12; // r15
  char *m_pOutBuffer; // rdx
  unsigned __int16 v14; // [rsp+70h] [rbp+8h]
  int in_channelMask; // [rsp+80h] [rbp+18h]

  m_pCtx = this->m_pCtx;
  v3 = 0i64;
  nChannels = 0;
  in_channelMask = *((_DWORD *)&m_pCtx->m_sMediaFormat + 1) & 0x3FFFF;
  for ( i = in_channelMask; i; i &= i - 1 )
    ++nChannels;
  CachedAudioBuffer = (char *)CAkLEngine::GetCachedAudioBuffer(nChannels << 11);
  this->m_pOutBuffer = CachedAudioBuffer;
  if ( CachedAudioBuffer )
  {
    uMaxFrames = io_state->uMaxFrames;
    if ( this->m_uLoopCnt == 1 )
      m_uTotalSamples = this->m_uTotalSamples;
    else
      m_uTotalSamples = this->m_uPCMLoopEnd + 1;
    if ( this->m_uCurSample + uMaxFrames > m_uTotalSamples )
      uMaxFrames = m_uTotalSamples - LOWORD(this->m_uCurSample);
    v11 = uMaxFrames >> 6;
    v14 = uMaxFrames >> 6 << 6;
    if ( nChannels )
    {
      v12 = nChannels;
      do
      {
        CAkADPCMCodec::Decode(&this->m_pucData[v3], CachedAudioBuffer, v11, this->m_uInputBlockSize, nChannels);
        CachedAudioBuffer += 2;
        v3 += 36i64;
        --v12;
      }
      while ( v12 );
    }
    m_pOutBuffer = this->m_pOutBuffer;
    this->m_pucData += v11 * (unsigned int)this->m_uInputBlockSize;
    CAkSrcBaseEx::SubmitBufferAndUpdate(
      this,
      m_pOutBuffer,
      v14,
      m_pCtx->m_sMediaFormat.uSampleRate,
      in_channelMask,
      io_state);
  }
  else
  {
    io_state->result = AK_Fail;
  }
}

// File Line: 208
// RVA: 0xA9A880
__int64 __fastcall CAkSrcBankADPCM::OnLoopComplete(CAkSrcBankADPCM *this, bool in_bEndOfFile)
{
  unsigned __int16 m_uLoopCnt; // ax
  __int64 result; // rax

  m_uLoopCnt = this->m_uLoopCnt;
  this->m_pucData = &this->m_pCtx->m_pDataPtr[(this->m_uCurSample >> 6) * this->m_uInputBlockSize + this->m_uDataOffset];
  if ( m_uLoopCnt > 1u )
    this->m_uLoopCnt = m_uLoopCnt - 1;
  result = 45i64;
  if ( in_bEndOfFile )
    return 17i64;
  return result;
}

// File Line: 215
// RVA: 0xA9ABA0
__int64 __fastcall CAkSrcBankADPCM::VirtualOff(
        CAkSrcBankADPCM *this,
        AkVirtualQueueBehavior eBehavior,
        bool in_bUseSourceOffset)
{
  __int64 m_uDataOffset; // rax
  CAkPBI *m_pCtx; // rdx

  if ( eBehavior == AkVirtualQueueBehavior_FromBeginning )
  {
    m_uDataOffset = this->m_uDataOffset;
    this->m_uCurSample = 0;
    m_pCtx = this->m_pCtx;
    this->m_pucData = &m_pCtx->m_pDataPtr[m_uDataOffset];
    this->m_uLoopCnt = m_pCtx->m_LoopCount;
    return 1i64;
  }
  if ( eBehavior != AkVirtualQueueBehavior_FromElapsedTime )
    return 1i64;
  if ( !in_bUseSourceOffset )
  {
    this->m_pucData = &this->m_pCtx->m_pDataPtr[(this->m_uCurSample >> 6) * this->m_uInputBlockSize
                                              + this->m_uDataOffset];
    return 1i64;
  }
  return CAkSrcBankADPCM::SeekToSourceOffset(this);
}

// File Line: 233
// RVA: 0xA9A940
__int64 __fastcall CAkSrcBankADPCM::SeekToSourceOffset(CAkSrcBankADPCM *this)
{
  unsigned int SourceOffset; // eax
  CAkPBI *m_pCtx; // rcx
  unsigned int m_uCurSample; // ecx

  if ( (*((_BYTE *)this->m_pCtx + 375) & 2) == 0 )
    return 1i64;
  SourceOffset = CAkSrcBaseEx::GetSourceOffset(this);
  m_pCtx = this->m_pCtx;
  this->m_uCurSample = SourceOffset & 0xFFFFFFC0;
  *((_BYTE *)m_pCtx + 375) &= 0xF1u;
  m_pCtx->m_uSeekPosition = SourceOffset - (SourceOffset & 0xFFFFFFC0);
  m_uCurSample = this->m_uCurSample;
  if ( m_uCurSample < this->m_uTotalSamples )
  {
    this->m_pucData = &this->m_pCtx->m_pDataPtr[this->m_uDataOffset
                                              + (unsigned __int64)(this->m_uInputBlockSize * (m_uCurSample >> 6))];
    return 1i64;
  }
  return 2i64;
}

// File Line: 259
// RVA: 0xA9A730
// attributes: thunk
AKRESULT __fastcall CAkSrcBankADPCM::ChangeSourcePosition(CAkSrcBankADPCM *this)
{
  return CAkSrcBankADPCM::SeekToSourceOffset(this);
}

