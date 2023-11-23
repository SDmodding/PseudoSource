// File Line: 24
// RVA: 0xA9A000
void __fastcall CAkSrcFileADPCM::CAkSrcFileADPCM(CAkSrcFileADPCM *this, CAkPBI *in_pCtx)
{
  CAkSrcFileBase::CAkSrcFileBase(this, in_pCtx);
  this->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFileADPCM::`vftable;
  this->m_pOutBuffer = 0i64;
  this->m_wExtraSize = 0;
}

// File Line: 33
// RVA: 0xA9A0E0
void __fastcall CAkSrcFileADPCM::GetBuffer(CAkSrcFileADPCM *this, AkVPLState *io_state)
{
  AKRESULT IsPrebufferingReady; // eax
  CAkPBI *m_pCtx; // rax
  __int64 v6; // r14
  unsigned int nChannels; // edi
  unsigned int v8; // r12d
  unsigned int v9; // ecx
  unsigned __int16 v10; // bp
  char *CachedAudioBuffer; // rsi
  unsigned __int16 m_wExtraSize; // dx
  char *m_ExtraBlock; // rbp
  __int64 v14; // r15
  unsigned int v15; // ecx
  unsigned int v16; // ebp
  __int64 v17; // r15
  unsigned int m_uInputBlockSize; // r9d
  __int128 v19; // rax
  __int64 v20; // rdi
  size_t m_ulSizeLeft_low; // r8
  char *m_pNextAddress; // rdx
  char v23; // al
  unsigned int *p_m_sMediaFormat; // [rsp+30h] [rbp-48h]
  unsigned int v25; // [rsp+80h] [rbp+8h]
  unsigned int in_channelMask; // [rsp+90h] [rbp+18h]
  char *v27; // [rsp+98h] [rbp+20h]

  if ( (*((_BYTE *)&this->CAkVPLSrcNode + 32) & 2) != 0 )
  {
    IsPrebufferingReady = (unsigned int)AK::SrcFileServices::IsPrebufferingReady(this->m_pStream, this->m_ulSizeLeft);
    if ( IsPrebufferingReady != AK_DataReady )
    {
LABEL_10:
      io_state->result = IsPrebufferingReady;
      return;
    }
    *((_BYTE *)&this->CAkVPLSrcNode + 32) &= ~2u;
  }
  if ( !this->m_ulSizeLeft )
  {
    IsPrebufferingReady = CAkSrcFileBase::FetchStreamBuffer(this);
    if ( IsPrebufferingReady != AK_DataReady )
      goto LABEL_10;
  }
  m_pCtx = this->m_pCtx;
  p_m_sMediaFormat = (unsigned int *)&m_pCtx->m_sMediaFormat;
  LODWORD(m_pCtx) = *((_DWORD *)&m_pCtx->m_sMediaFormat + 1);
  v6 = 0i64;
  nChannels = 0;
  v8 = ((unsigned int)m_pCtx >> 24) & 0x1F;
  in_channelMask = (unsigned int)m_pCtx & 0x3FFFF;
  v9 = (unsigned int)m_pCtx & 0x3FFFF;
  if ( ((unsigned int)m_pCtx & 0x3FFFF) != 0 )
  {
    do
    {
      ++nChannels;
      v9 &= v9 - 1;
    }
    while ( v9 );
  }
  v10 = 1024;
  CachedAudioBuffer = (char *)CAkLEngine::GetCachedAudioBuffer(v8 << 10);
  v27 = CachedAudioBuffer;
  this->m_pOutBuffer = CachedAudioBuffer;
  if ( CachedAudioBuffer )
  {
    m_wExtraSize = this->m_wExtraSize;
    v25 = v8 << 6;
    if ( m_wExtraSize )
    {
      memmove(&this->m_ExtraBlock[m_wExtraSize], this->m_pNextAddress, this->m_uInputBlockSize - m_wExtraSize);
      if ( nChannels )
      {
        m_ExtraBlock = this->m_ExtraBlock;
        v14 = nChannels;
        do
        {
          CAkADPCMCodec::Decode(m_ExtraBlock, CachedAudioBuffer, 1u, this->m_uInputBlockSize, nChannels);
          CachedAudioBuffer += 2;
          m_ExtraBlock += 36;
          --v14;
        }
        while ( v14 );
        CachedAudioBuffer = v27;
      }
      v10 = 960;
      v15 = this->m_uInputBlockSize - this->m_wExtraSize;
      this->m_wExtraSize = 0;
      this->m_ulSizeLeft -= v15;
      this->m_pNextAddress += v15;
      CachedAudioBuffer += v25;
      v27 = CachedAudioBuffer;
    }
    v16 = v10 >> 6;
    if ( (unsigned int)(this->m_ulSizeLeft / this->m_uInputBlockSize) < v16 )
      v16 = this->m_ulSizeLeft / this->m_uInputBlockSize;
    if ( nChannels )
    {
      v17 = nChannels;
      do
      {
        CAkADPCMCodec::Decode(&this->m_pNextAddress[v6], CachedAudioBuffer, v16, this->m_uInputBlockSize, nChannels);
        CachedAudioBuffer += 2;
        v6 += 36i64;
        --v17;
      }
      while ( v17 );
      CachedAudioBuffer = v27;
    }
    m_uInputBlockSize = this->m_uInputBlockSize;
    v19 = (__int64)&CachedAudioBuffer[v25 * v16 - (unsigned __int64)this->m_pOutBuffer];
    this->m_ulSizeLeft -= v16 * m_uInputBlockSize;
    this->m_pNextAddress += v16 * m_uInputBlockSize;
    v20 = v19 / v8;
    if ( this->m_ulSizeLeft < m_uInputBlockSize )
    {
      m_ulSizeLeft_low = LOWORD(this->m_ulSizeLeft);
      m_pNextAddress = this->m_pNextAddress;
      this->m_wExtraSize = m_ulSizeLeft_low;
      memmove(this->m_ExtraBlock, m_pNextAddress, m_ulSizeLeft_low);
      this->m_pNextAddress += this->m_ulSizeLeft;
      v23 = *((_BYTE *)&this->CAkSrcFileBase + 126);
      this->m_ulSizeLeft = 0;
      if ( (v23 & 2) != 0 )
        *((_BYTE *)&this->CAkSrcFileBase + 126) = v23 & 0xFD;
      else
        this->m_pStream->CAkSrcFileBase::vfptr->ReleaseBuffer(this->m_pStream);
    }
    CAkSrcBaseEx::SubmitBufferAndUpdate(this, this->m_pOutBuffer, v20, *p_m_sMediaFormat, in_channelMask, io_state);
  }
  else
  {
    io_state->result = AK_Fail;
  }
}

// File Line: 133
// RVA: 0xA9A670
void __fastcall CAkSrcFileADPCM::StopStream(CAkSrcFileADPCM *this)
{
  this->vfptr->ReleaseBuffer(this);
  CAkSrcFileBase::StopStream(this);
}

// File Line: 140
// RVA: 0xA9A630
void __fastcall CAkSrcFileADPCM::ReleaseBuffer(CAkSrcFileADPCM *this)
{
  char *m_pOutBuffer; // rdx

  m_pOutBuffer = this->m_pOutBuffer;
  if ( m_pOutBuffer )
  {
    CAkLEngine::ReleaseCachedAudioBuffer((*((_BYTE *)&this->m_pCtx->m_sMediaFormat + 7) & 0x1F) << 10, m_pOutBuffer);
    this->m_pOutBuffer = 0i64;
  }
}

// File Line: 150
// RVA: 0xA9A690
void __fastcall CAkSrcFileADPCM::VirtualOn(CAkSrcFileADPCM *this, AkVirtualQueueBehavior eBehavior)
{
  CAkSrcFileBase::VirtualOn(this, eBehavior);
  if ( (unsigned int)eBehavior <= AkVirtualQueueBehavior_FromElapsedTime )
    this->m_wExtraSize = 0;
}

// File Line: 165
// RVA: 0xA9A400
AKRESULT __fastcall CAkSrcFileADPCM::ParseHeader(CAkSrcFileADPCM *this, char *in_pBuffer)
{
  unsigned int m_ulSizeLeft; // edx
  unsigned int *p_m_uDataOffset; // r15
  unsigned int *p_m_uDataSize; // rbp
  unsigned int *p_m_uPCMLoopEnd; // rsi
  unsigned int *p_m_uPCMLoopStart; // r14
  AKRESULT result; // eax
  WaveFormatExtensible *pFormat; // rdi
  CAkPBI *m_pCtx; // rcx
  unsigned int nBlockAlign; // r10d
  unsigned int v13; // r9d
  unsigned int v14; // r8d
  unsigned int v15; // r11d
  unsigned int v16; // edx
  int v17; // r9d
  unsigned int v18; // r10d
  unsigned int v19; // r9d
  unsigned int m_uTotalSamples; // eax
  bool v21; // zf
  int v22[3]; // [rsp+50h] [rbp-48h] BYREF
  char priority; // [rsp+5Dh] [rbp-3Bh]
  AkFileParser::AnalysisDataChunk in_analysisDataChunk; // [rsp+60h] [rbp-38h] BYREF
  AkFileParser::FormatInfo v25; // [rsp+70h] [rbp-28h] BYREF
  AkAudioFormat v26; // [rsp+A0h] [rbp+8h]

  m_ulSizeLeft = this->m_ulSizeLeft;
  in_analysisDataChunk.uDataSize = 0;
  in_analysisDataChunk.pData = 0i64;
  p_m_uDataOffset = &this->m_uDataOffset;
  p_m_uDataSize = &this->m_uDataSize;
  p_m_uPCMLoopEnd = &this->m_uPCMLoopEnd;
  p_m_uPCMLoopStart = &this->m_uPCMLoopStart;
  result = AkFileParser::Parse(
             in_pBuffer,
             m_ulSizeLeft,
             &v25,
             &this->m_markers,
             &this->m_uPCMLoopStart,
             &this->m_uPCMLoopEnd,
             &this->m_uDataSize,
             &this->m_uDataOffset,
             &in_analysisDataChunk,
             0i64);
  if ( result == AK_Success )
  {
    pFormat = v25.pFormat;
    if ( v25.pFormat->wFormatTag != 2 )
      return 7;
    v26.uSampleRate = v25.pFormat->nSamplesPerSec;
    *((_DWORD *)&v26 + 1) = v25.pFormat->dwChannelMask & 0x3FFFF | (v25.pFormat->nChannels << 25) & 0x1F000000 | 0x400000;
    m_pCtx = this->m_pCtx;
    m_pCtx->m_sMediaFormat = v26;
    CAkPBI::InvalidateFeedbackParameters(m_pCtx);
    if ( in_analysisDataChunk.uDataSize )
      CAkSrcFileBase::StoreAnalysisData(this, &in_analysisDataChunk);
    nBlockAlign = pFormat->nBlockAlign;
    v13 = *p_m_uDataSize;
    v14 = *p_m_uDataOffset;
    v15 = *p_m_uPCMLoopEnd;
    this->m_uInputBlockSize = nBlockAlign;
    v16 = v14 + v13;
    this->m_uTotalSamples = (v13 << 6) / pFormat->nBlockAlign;
    if ( !v15 || this->m_uLoopCnt == 1 )
    {
      this->m_ulLoopEnd = v16;
      this->m_ulLoopStart = v14;
      *p_m_uPCMLoopEnd = ((v13 / nBlockAlign) << 6) - 1;
    }
    else
    {
      v17 = nBlockAlign * (*p_m_uPCMLoopStart >> 6);
      v18 = v14 + ((v15 + 1) >> 6) * nBlockAlign;
      v19 = v14 + v17;
      this->m_ulLoopEnd = v18;
      this->m_ulLoopStart = v19;
      if ( v15 < *p_m_uPCMLoopStart || v19 > v16 || v18 > v16 )
        return 7;
    }
    this->m_pStream->CAkSrcFileBase::vfptr->GetHeuristics(this->m_pStream, (AkAutoStmHeuristics *)v22);
    if ( *p_m_uPCMLoopEnd <= *p_m_uPCMLoopStart )
      return 2;
    m_uTotalSamples = this->m_uTotalSamples;
    if ( *p_m_uPCMLoopStart > m_uTotalSamples || *p_m_uPCMLoopEnd >= m_uTotalSamples )
    {
      return 2;
    }
    else
    {
      v21 = this->m_uLoopCnt == 1;
      *(float *)v22 = (float)((float)pFormat->nBlockAlign * (float)(int)pFormat->nSamplesPerSec) * 0.000015625001;
      if ( !v21 )
      {
        v22[1] = this->m_ulLoopStart;
        v22[2] = this->m_ulLoopEnd;
      }
      priority = (int)this->m_pCtx->m_PriorityInfoCurrent.currentPriority.priority;
      this->m_pStream->CAkSrcFileBase::vfptr->SetHeuristics(this->m_pStream, (AkAutoStmHeuristics *)v22);
      return this->m_pStream->CAkSrcFileBase::vfptr->SetMinimalBufferSize(this->m_pStream, 36 * pFormat->nChannels);
    }
  }
  return result;
}

// File Line: 290
// RVA: 0xA9A3C0
float __fastcall CAkSrcFileADPCM::GetThroughput(CAkSrcFileADPCM *this, AkAudioFormat *in_rFormat)
{
  int v2; // r8d
  int i; // ecx

  v2 = 0;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v2;
  return (float)(36 * v2 * in_rFormat->uSampleRate) * 0.000015625001;
}

// File Line: 302
// RVA: 0xA9A0C0
__int64 __fastcall CAkSrcFileADPCM::FindClosestFileOffset(
        CAkSrcFileADPCM *this,
        unsigned int in_uDesiredSample,
        unsigned int *out_uSeekedSample,
        unsigned int *out_uFileOffset)
{
  unsigned int v4; // edx

  v4 = in_uDesiredSample >> 6;
  *out_uSeekedSample = v4 << 6;
  *out_uFileOffset = this->m_uDataOffset + v4 * this->m_uInputBlockSize;
  return 1i64;
}

// File Line: 311
// RVA: 0xA9A0B0
AKRESULT __fastcall CAkSrcFileADPCM::ChangeSourcePosition(CAkSrcFileADPCM *this)
{
  this->m_wExtraSize = 0;
  return CAkSrcFileBase::ChangeSourcePosition(this);
}

