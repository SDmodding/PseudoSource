// File Line: 24
// RVA: 0xA991D0
void __fastcall CAkSrcFilePCM::CAkSrcFilePCM(CAkSrcFilePCM *this, CAkPBI *in_pCtx)
{
  CAkSrcFileBase::CAkSrcFileBase(this, in_pCtx);
  this->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFilePCM::`vftable;
  this->m_pStitchBuffer = 0i64;
  *(_QWORD *)&this->m_uNumBytesBuffered = 0i64;
}

// File Line: 32
// RVA: 0xA997F0
void __fastcall CAkSrcFilePCM::StopStream(CAkSrcFilePCM *this)
{
  char *m_pStitchBuffer; // rdx

  m_pStitchBuffer = this->m_pStitchBuffer;
  if ( m_pStitchBuffer )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pStitchBuffer);
    this->m_pStitchBuffer = 0i64;
    this->m_uNumBytesBuffered = 0;
  }
  CAkSrcFileBase::StopStream(this);
}

// File Line: 44
// RVA: 0xA99300
void __fastcall CAkSrcFilePCM::GetBuffer(CAkSrcFilePCM *this, AkVPLState *io_state)
{
  AKRESULT StreamBuffer; // eax
  unsigned __int16 v5; // ax
  unsigned int m_ulSizeLeft; // ecx
  unsigned __int16 v7; // r13
  unsigned int v8; // esi
  unsigned int v9; // ebp
  CAkPBI *m_pCtx; // r15
  __int64 m_uNumBytesBuffered; // rax
  char *v12; // rdx
  char *m_pStitchBuffer; // r12
  int v14; // eax
  unsigned int v15; // r14d
  char *v16; // rax
  char *v17; // rdx
  unsigned int v18; // esi

  if ( (*((_BYTE *)&this->CAkVPLSrcNode + 32) & 2) != 0 )
  {
    StreamBuffer = AK::SrcFileServices::IsPrebufferingReady(this->m_pStream, this->m_ulSizeLeft);
    if ( StreamBuffer != AK_DataReady )
    {
LABEL_9:
      io_state->result = StreamBuffer;
      return;
    }
    *((_BYTE *)&this->CAkVPLSrcNode + 32) &= ~2u;
  }
  if ( !this->m_ulSizeLeft )
  {
    StreamBuffer = CAkSrcFileBase::FetchStreamBuffer(this);
    if ( StreamBuffer != AK_DataReady )
      goto LABEL_9;
  }
  v5 = ((__int64 (__fastcall *)(CAkSrcFilePCM *))this->vfptr[2].Connect)(this);
  m_ulSizeLeft = this->m_ulSizeLeft;
  v7 = v5;
  v8 = v5;
  v9 = m_ulSizeLeft / v5;
  if ( !m_ulSizeLeft && (*((_BYTE *)&this->CAkSrcFileBase + 126) & 1) != 0 )
  {
    io_state->result = AK_Fail;
    return;
  }
  m_pCtx = this->m_pCtx;
  if ( io_state->uMaxFrames < v9 )
    LOWORD(v9) = io_state->uMaxFrames;
  m_uNumBytesBuffered = this->m_uNumBytesBuffered;
  if ( (_DWORD)m_uNumBytesBuffered )
  {
    v18 = v8 - m_uNumBytesBuffered;
    if ( v18 <= m_ulSizeLeft )
    {
      memmove(&this->m_pStitchBuffer[m_uNumBytesBuffered], this->m_pNextAddress, v18);
      m_pStitchBuffer = this->m_pStitchBuffer;
      this->m_uSizeToRelease = (unsigned __int16)v18;
      LOWORD(v9) = 1;
      this->m_uNumBytesBuffered = 0;
      goto LABEL_22;
    }
LABEL_20:
    io_state->result = AK_Fail;
    return;
  }
  v12 = this->m_pStitchBuffer;
  if ( v12 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v12);
    this->m_pStitchBuffer = 0i64;
  }
  m_pStitchBuffer = this->m_pNextAddress;
  v14 = v8 * (unsigned __int16)v9;
  v15 = this->m_ulSizeLeft - v14;
  this->m_uSizeToRelease = v14;
  if ( v15 >= v8 || !v15 )
    goto LABEL_22;
  v16 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, v7);
  this->m_pStitchBuffer = v16;
  if ( !v16 )
    goto LABEL_20;
  v17 = &this->m_pNextAddress[this->m_uSizeToRelease];
  this->m_uNumBytesBuffered = (unsigned __int16)v15;
  memmove(v16, v17, (unsigned __int16)v15);
  this->m_uSizeToRelease += this->m_uNumBytesBuffered;
LABEL_22:
  CAkSrcBaseEx::SubmitBufferAndUpdate(
    this,
    m_pStitchBuffer,
    v9,
    m_pCtx->m_sMediaFormat.uSampleRate,
    *((_DWORD *)&m_pCtx->m_sMediaFormat + 1) & 0x3FFFF,
    io_state);
}

// File Line: 162
// RVA: 0xA997B0
void __fastcall CAkSrcFilePCM::ReleaseBuffer(CAkSrcFilePCM *this)
{
  __int64 m_uSizeToRelease; // rax
  char v2; // al

  m_uSizeToRelease = this->m_uSizeToRelease;
  this->m_uSizeToRelease = 0;
  this->m_ulSizeLeft -= m_uSizeToRelease;
  this->m_pNextAddress += m_uSizeToRelease;
  if ( !this->m_ulSizeLeft )
  {
    v2 = *((_BYTE *)&this->CAkSrcFileBase + 126);
    if ( (v2 & 2) != 0 )
      *((_BYTE *)&this->CAkSrcFileBase + 126) = v2 & 0xFD;
    else
      this->m_pStream->CAkSrcFileBase::vfptr->ReleaseBuffer(this->m_pStream);
  }
}

// File Line: 175
// RVA: 0xA99830
void __fastcall CAkSrcFilePCM::VirtualOn(CAkSrcFilePCM *this, AkVirtualQueueBehavior eBehavior)
{
  char *m_pStitchBuffer; // rdx

  m_pStitchBuffer = this->m_pStitchBuffer;
  if ( m_pStitchBuffer && (unsigned int)eBehavior <= AkVirtualQueueBehavior_FromElapsedTime )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pStitchBuffer);
    this->m_pStitchBuffer = 0i64;
    this->m_uNumBytesBuffered = 0;
  }
  CAkSrcFileBase::VirtualOn(this, eBehavior);
}

// File Line: 194
// RVA: 0xA995B0
AKRESULT __fastcall CAkSrcFilePCM::ParseHeader(CAkSrcFilePCM *this, char *in_pBuffer)
{
  unsigned int m_ulSizeLeft; // edx
  unsigned int *p_m_uDataOffset; // r14
  unsigned int *p_m_uDataSize; // r15
  unsigned int *p_m_uPCMLoopEnd; // rsi
  unsigned int *p_m_uPCMLoopStart; // rbp
  AKRESULT result; // eax
  WaveFormatExtensible *pFormat; // rdi
  CAkPBI *m_pCtx; // rcx
  unsigned int v12; // r10d
  unsigned int v13; // r11d
  unsigned int v14; // r9d
  int nBlockAlign; // ecx
  int v16; // r8d
  unsigned int v17; // ecx
  unsigned int v18; // r8d
  bool v19; // zf
  int v20[3]; // [rsp+50h] [rbp-48h] BYREF
  char priority; // [rsp+5Dh] [rbp-3Bh]
  AkFileParser::AnalysisDataChunk in_analysisDataChunk; // [rsp+60h] [rbp-38h] BYREF
  AkFileParser::FormatInfo v23; // [rsp+70h] [rbp-28h] BYREF
  AkAudioFormat v24; // [rsp+A0h] [rbp+8h]

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
             &v23,
             &this->m_markers,
             &this->m_uPCMLoopStart,
             &this->m_uPCMLoopEnd,
             &this->m_uDataSize,
             &this->m_uDataOffset,
             &in_analysisDataChunk,
             0i64);
  if ( result == AK_Success )
  {
    pFormat = v23.pFormat;
    if ( v23.pFormat->wFormatTag != 0xFFFE )
      return 7;
    v24.uSampleRate = v23.pFormat->nSamplesPerSec;
    *((_DWORD *)&v24 + 1) = v23.pFormat->dwChannelMask & 0x3FFFF | ((v23.pFormat->wBitsPerSample & 0x3F | ((v23.pFormat->nBlockAlign & 0x1F) << 6)) << 18);
    m_pCtx = this->m_pCtx;
    m_pCtx->m_sMediaFormat = v24;
    CAkPBI::InvalidateFeedbackParameters(m_pCtx);
    if ( in_analysisDataChunk.uDataSize )
      CAkSrcFileBase::StoreAnalysisData(this, &in_analysisDataChunk);
    v12 = *p_m_uDataOffset;
    v13 = *p_m_uPCMLoopEnd;
    v14 = *p_m_uDataOffset + *p_m_uDataSize;
    this->m_uTotalSamples = *p_m_uDataSize / pFormat->nBlockAlign;
    if ( !v13 || this->m_uLoopCnt == 1 )
    {
      this->m_ulLoopEnd = v14;
      this->m_ulLoopStart = v12;
      *p_m_uPCMLoopEnd = (v14 - v12) / pFormat->nBlockAlign - 1;
    }
    else
    {
      nBlockAlign = pFormat->nBlockAlign;
      v16 = nBlockAlign * *p_m_uPCMLoopStart;
      v17 = v12 + (v13 + 1) * nBlockAlign;
      v18 = v12 + v16;
      this->m_ulLoopEnd = v17;
      this->m_ulLoopStart = v18;
      if ( v13 < *p_m_uPCMLoopStart || v18 > v14 || v17 > v14 )
        return 7;
    }
    this->m_pStream->CAkSrcFileBase::vfptr->GetHeuristics(this->m_pStream, (AkAutoStmHeuristics *)v20);
    v19 = this->m_uLoopCnt == 1;
    *(float *)v20 = (float)(pFormat->nSamplesPerSec * pFormat->nBlockAlign) * 0.001;
    if ( !v19 )
    {
      v20[1] = this->m_ulLoopStart;
      v20[2] = this->m_ulLoopEnd;
    }
    priority = (int)this->m_pCtx->m_PriorityInfoCurrent.currentPriority.priority;
    this->m_pStream->CAkSrcFileBase::vfptr->SetHeuristics(this->m_pStream, (AkAutoStmHeuristics *)v20);
    return this->m_pStream->CAkSrcFileBase::vfptr->SetMinimalBufferSize(this->m_pStream, pFormat->nBlockAlign);
  }
  return result;
}

// File Line: 311
// RVA: 0xA994E0
float __fastcall CAkSrcFilePCM::GetThroughput(CAkSrcFilePCM *this, AkAudioFormat *in_rFormat)
{
  return (float)(in_rFormat->uSampleRate
               * ((unsigned __int16 (__fastcall *)(CAkSrcFilePCM *))this->vfptr[2].Connect)(this))
       * 0.001;
}

// File Line: 323
// RVA: 0xA992A0
__int64 __fastcall CAkSrcFilePCM::FindClosestFileOffset(
        CAkSrcFilePCM *this,
        unsigned int in_uDesiredSample,
        unsigned int *out_uSeekedSample,
        unsigned int *out_uFileOffset)
{
  *out_uSeekedSample = in_uDesiredSample;
  *out_uFileOffset = this->m_uDataOffset
                   + in_uDesiredSample
                   * ((unsigned __int16 (__fastcall *)(CAkSrcFilePCM *))this->vfptr[2].Connect)(this);
  return 1i64;
}

// File Line: 333
// RVA: 0xA992F0
__int64 __fastcall CAkSrcFilePCM::GetBlockAlign(CAkSrcFilePCM *this)
{
  return *((_BYTE *)&this->m_pCtx->m_sMediaFormat + 7) & 0x1F;
}

// File Line: 339
// RVA: 0xA99250
AKRESULT __fastcall CAkSrcFilePCM::ChangeSourcePosition(CAkSrcFilePCM *this)
{
  char *m_pStitchBuffer; // rdx

  m_pStitchBuffer = this->m_pStitchBuffer;
  this->m_uSizeToRelease = 0;
  if ( m_pStitchBuffer )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pStitchBuffer);
    this->m_pStitchBuffer = 0i64;
    this->m_uNumBytesBuffered = 0;
  }
  return CAkSrcFileBase::ChangeSourcePosition(this);
}

// File Line: 351
// RVA: 0xA99570
bool __fastcall CAkSrcFilePCM::MustRelocatePitchInputBufferOnMediaRelocation(CAkSrcFilePCM *this)
{
  return (*((_BYTE *)&this->CAkSrcFileBase + 126) & 8) != 0;
}

