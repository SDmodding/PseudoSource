// File Line: 29
// RVA: 0xA9A6C0
void __fastcall CAkSrcBankADPCM::CAkSrcBankADPCM(CAkSrcBankADPCM *this, CAkPBI *in_pCtx)
{
  CAkSrcBankADPCM *v2; // rbx

  v2 = this;
  CAkSrcBaseEx::CAkSrcBaseEx((CAkSrcBaseEx *)&this->vfptr, in_pCtx);
  v2->vfptr = (CAkVPLNodeVtbl *)&CAkSrcBankADPCM::`vftable;
  v2->m_pucData = 0i64;
  v2->m_pOutBuffer = 0i64;
}

// File Line: 38
// RVA: 0xA9A9C0
signed __int64 __fastcall CAkSrcBankADPCM::StartStream(CAkSrcBankADPCM *this)
{
  CAkPBI *v1; // rax
  CAkSrcBankADPCM *v2; // rbx
  char *v3; // rsi
  unsigned int v4; // er12
  signed __int64 result; // rax
  unsigned int *v6; // r15
  unsigned int *v7; // r14
  unsigned int *v8; // r13
  AKRESULT v9; // edi
  WaveFormatExtensible *v10; // rbp
  CAkPBI *v11; // rcx
  unsigned int v12; // ecx
  unsigned int v13; // er8
  unsigned int v14; // eax
  int v15; // eax
  bool v16; // zf
  __int64 v17; // rax
  AkFileParser::AnalysisDataChunk out_pAnalysisData; // [rsp+50h] [rbp-48h]
  AkFileParser::FormatInfo out_pFormatInfo; // [rsp+60h] [rbp-38h]
  AkAudioFormat v20; // [rsp+A0h] [rbp+8h]

  v1 = this->m_pCtx;
  v2 = this;
  v3 = v1->m_pDataPtr;
  v4 = v1->m_uDataSize;
  if ( !v3 )
    return 2i64;
  out_pAnalysisData.uDataSize = 0;
  out_pAnalysisData.pData = 0i64;
  v6 = &this->m_uDataOffset;
  v7 = &this->m_uPCMLoopEnd;
  v8 = &this->m_uPCMLoopStart;
  v9 = AkFileParser::Parse(
         v3,
         v4,
         &out_pFormatInfo,
         &this->m_markers,
         &this->m_uPCMLoopStart,
         &this->m_uPCMLoopEnd,
         &this->m_uDataSize,
         &this->m_uDataOffset,
         &out_pAnalysisData,
         0i64);
  if ( v9 != 1 )
    return 7i64;
  v10 = out_pFormatInfo.pFormat;
  if ( out_pFormatInfo.pFormat->wFormatTag != 2 )
    return 7i64;
  v20.uSampleRate = out_pFormatInfo.pFormat->nSamplesPerSec;
  *((_DWORD *)&v20 + 1) = out_pFormatInfo.pFormat->dwChannelMask & 0x3FFFF | (out_pFormatInfo.pFormat->nChannels << 25) & 0x1F000000 | 0x400000;
  v11 = v2->m_pCtx;
  v11->m_sMediaFormat = v20;
  CAkPBI::InvalidateFeedbackParameters(v11);
  if ( out_pAnalysisData.uDataSize )
    v2->m_pAnalysisData = out_pAnalysisData.pData;
  v12 = v10->nBlockAlign;
  v13 = v2->m_uDataSize;
  v14 = v2->m_uDataSize;
  v2->m_uInputBlockSize = v12;
  v15 = (v14 << 6) / v12;
  v16 = *v7 == 0;
  v2->m_uTotalSamples = v15;
  if ( v16 || v2->m_uLoopCnt == 1 )
    *v7 = v15 - 1;
  if ( *v7 < *v8 || *v7 >= v2->m_uTotalSamples || v4 != v13 + *v6 )
    v9 = 2;
  v17 = *v6;
  v2->m_uCurSample = 0;
  v2->m_pucData = &v3[v17];
  if ( *((_BYTE *)v2->m_pCtx + 375) & 2 )
    result = CAkSrcBankADPCM::SeekToSourceOffset(v2);
  else
    result = (unsigned int)v9;
  return result;
}

// File Line: 131
// RVA: 0xA9A930
signed __int64 __fastcall CAkSrcBankADPCM::RelocateMedia(CAkSrcBankADPCM *this, char *in_pNewMedia, char *in_pOldMedia)
{
  signed __int64 result; // rax

  result = 1i64;
  this->m_pucData += in_pNewMedia - in_pOldMedia;
  return result;
}

// File Line: 145
// RVA: 0xA9AB80
void __fastcall CAkSrcBankADPCM::StopStream(CAkSrcBankADPCM *this)
{
  CAkSrcBankADPCM *v1; // rbx

  v1 = this;
  ((void (*)(void))this->vfptr->ReleaseBuffer)();
  CAkSrcBaseEx::StopStream((CAkSrcBaseEx *)&v1->vfptr);
}

// File Line: 151
// RVA: 0xA9A8D0
void __fastcall CAkSrcBankADPCM::ReleaseBuffer(CAkSrcBankADPCM *this)
{
  char *v1; // rdx
  CAkSrcBankADPCM *v2; // rbx
  CAkPBI *v3; // rax
  int v4; // ecx
  int i; // eax

  v1 = this->m_pOutBuffer;
  v2 = this;
  if ( v1 )
  {
    v3 = this->m_pCtx;
    v4 = 0;
    for ( i = *((_DWORD *)&v3->m_sMediaFormat + 1) & 0x3FFFF; i; i &= i - 1 )
      ++v4;
    CAkLEngine::ReleaseCachedAudioBuffer(v4 << 11, v1);
    v2->m_pOutBuffer = 0i64;
  }
}

// File Line: 161
// RVA: 0xA9A740
void __fastcall CAkSrcBankADPCM::GetBuffer(CAkSrcBankADPCM *this, AkVPLState *io_state)
{
  CAkPBI *v2; // r12
  __int64 v3; // r14
  AkVPLState *v4; // r13
  CAkSrcBankADPCM *v5; // rdi
  unsigned int nChannels; // ebx
  int v7; // er8
  char *v8; // rsi
  unsigned __int16 v9; // dx
  unsigned int v10; // ecx
  unsigned int v11; // ebp
  __int64 v12; // r15
  char *v13; // rdx
  unsigned __int16 v14; // [rsp+70h] [rbp+8h]
  int in_channelMask; // [rsp+80h] [rbp+18h]

  v2 = this->m_pCtx;
  v3 = 0i64;
  v4 = io_state;
  v5 = this;
  nChannels = 0;
  in_channelMask = *((_DWORD *)&v2->m_sMediaFormat + 1) & 0x3FFFF;
  v7 = *((_DWORD *)&v2->m_sMediaFormat + 1) & 0x3FFFF;
  if ( in_channelMask )
  {
    do
    {
      ++nChannels;
      v7 &= v7 - 1;
    }
    while ( v7 );
  }
  v8 = (char *)CAkLEngine::GetCachedAudioBuffer(nChannels << 11);
  v5->m_pOutBuffer = v8;
  if ( v8 )
  {
    v9 = v4->uMaxFrames;
    if ( v5->m_uLoopCnt == 1 )
      v10 = v5->m_uTotalSamples;
    else
      v10 = v5->m_uPCMLoopEnd + 1;
    if ( v5->m_uCurSample + v9 > v10 )
      v9 = v10 - LOWORD(v5->m_uCurSample);
    v11 = (unsigned int)v9 >> 6;
    v14 = v9 >> 6 << 6;
    if ( nChannels )
    {
      v12 = nChannels;
      do
      {
        CAkADPCMCodec::Decode(&v5->m_pucData[v3], v8, v11, v5->m_uInputBlockSize, nChannels);
        v8 += 2;
        v3 += 36i64;
        --v12;
      }
      while ( v12 );
    }
    v13 = v5->m_pOutBuffer;
    v5->m_pucData += v11 * v5->m_uInputBlockSize;
    CAkSrcBaseEx::SubmitBufferAndUpdate(
      (CAkSrcBaseEx *)&v5->vfptr,
      v13,
      v14,
      v2->m_sMediaFormat.uSampleRate,
      in_channelMask,
      v4);
  }
  else
  {
    v4->result = 2;
  }
}

// File Line: 208
// RVA: 0xA9A880
signed __int64 __fastcall CAkSrcBankADPCM::OnLoopComplete(CAkSrcBankADPCM *this, bool in_bEndOfFile)
{
  unsigned __int16 v2; // ax
  signed __int64 result; // rax

  v2 = this->m_uLoopCnt;
  this->m_pucData = &this->m_pCtx->m_pDataPtr[(this->m_uCurSample >> 6) * this->m_uInputBlockSize + this->m_uDataOffset];
  if ( v2 > 1u )
    this->m_uLoopCnt = v2 - 1;
  result = 45i64;
  if ( in_bEndOfFile )
    result = 17i64;
  return result;
}

// File Line: 215
// RVA: 0xA9ABA0
signed __int64 __fastcall CAkSrcBankADPCM::VirtualOff(CAkSrcBankADPCM *this, AkVirtualQueueBehavior eBehavior, bool in_bUseSourceOffset)
{
  __int64 v3; // rax
  CAkPBI *v4; // rdx
  signed __int64 result; // rax

  if ( eBehavior )
  {
    if ( eBehavior == 1 )
    {
      JUMPOUT(in_bUseSourceOffset, 0, CAkSrcBankADPCM::SeekToSourceOffset);
      this->m_pucData = &this->m_pCtx->m_pDataPtr[(this->m_uCurSample >> 6) * this->m_uInputBlockSize
                                                + this->m_uDataOffset];
    }
    result = 1i64;
  }
  else
  {
    v3 = this->m_uDataOffset;
    this->m_uCurSample = 0;
    v4 = this->m_pCtx;
    this->m_pucData = &v4->m_pDataPtr[v3];
    this->m_uLoopCnt = v4->m_LoopCount;
    result = 1i64;
  }
  return result;
}

// File Line: 233
// RVA: 0xA9A940
signed __int64 __fastcall CAkSrcBankADPCM::SeekToSourceOffset(CAkSrcBankADPCM *this)
{
  CAkSrcBankADPCM *v1; // rbx
  unsigned int v2; // eax
  CAkPBI *v3; // rcx
  unsigned int v4; // ecx

  v1 = this;
  if ( !(*((_BYTE *)this->m_pCtx + 375) & 2) )
    return 1i64;
  v2 = CAkSrcBaseEx::GetSourceOffset((CAkSrcBaseEx *)&this->vfptr);
  v3 = v1->m_pCtx;
  v1->m_uCurSample = v2 & 0xFFFFFFC0;
  *((_BYTE *)v3 + 375) &= 0xF1u;
  v3->m_uSeekPosition = v2 - (v2 & 0xFFFFFFC0);
  v4 = v1->m_uCurSample;
  if ( v4 < v1->m_uTotalSamples )
  {
    v1->m_pucData = &v1->m_pCtx->m_pDataPtr[v1->m_uDataOffset + (unsigned __int64)(v1->m_uInputBlockSize * (v4 >> 6))];
    return 1i64;
  }
  return 2i64;
}

// File Line: 259
// RVA: 0xA9A730
AKRESULT __fastcall CAkSrcBankADPCM::ChangeSourcePosition(CAkSrcBankADPCM *this)
{
  return CAkSrcBankADPCM::SeekToSourceOffset(this);
}

