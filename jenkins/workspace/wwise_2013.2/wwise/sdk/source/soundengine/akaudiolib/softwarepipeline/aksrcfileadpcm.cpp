// File Line: 24
// RVA: 0xA9A000
void __fastcall CAkSrcFileADPCM::CAkSrcFileADPCM(CAkSrcFileADPCM *this, CAkPBI *in_pCtx)
{
  CAkSrcFileADPCM *v2; // rbx

  v2 = this;
  CAkSrcFileBase::CAkSrcFileBase((CAkSrcFileBase *)&this->vfptr, in_pCtx);
  v2->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFileADPCM::`vftable';
  v2->m_pOutBuffer = 0i64;
  v2->m_wExtraSize = 0;
}

// File Line: 33
// RVA: 0xA9A0E0
void __fastcall CAkSrcFileADPCM::GetBuffer(CAkSrcFileADPCM *this, AkVPLState *io_state)
{
  AkVPLState *v2; // r13
  CAkSrcFileADPCM *v3; // rbx
  AKRESULT v4; // eax
  unsigned int v5; // eax
  __int64 v6; // r14
  unsigned int nChannels; // edi
  unsigned int v8; // er12
  int v9; // ecx
  unsigned __int16 v10; // bp
  char *v11; // rsi
  unsigned __int16 v12; // dx
  char *v13; // rbp
  __int64 v14; // r15
  unsigned int v15; // ecx
  unsigned int v16; // ebp
  __int64 v17; // r15
  unsigned int v18; // er9
  __int128 v19; // ax
  unsigned int v20; // er8
  __int64 v21; // rdi
  size_t v22; // r8
  char *v23; // rdx
  char v24; // al
  unsigned int *v25; // [rsp+30h] [rbp-48h]
  unsigned int v26; // [rsp+80h] [rbp+8h]
  int in_channelMask; // [rsp+90h] [rbp+18h]
  char *v28; // [rsp+98h] [rbp+20h]

  v2 = io_state;
  v3 = this;
  if ( *((_BYTE *)&this->0 + 32) & 2 )
  {
    v4 = (unsigned int)AK::SrcFileServices::IsPrebufferingReady(this->m_pStream, this->m_ulSizeLeft);
    if ( v4 != 45 )
    {
LABEL_10:
      v2->result = v4;
      return;
    }
    *((_BYTE *)&v3->0 + 32) &= 0xFDu;
  }
  if ( !v3->m_ulSizeLeft )
  {
    v4 = CAkSrcFileBase::FetchStreamBuffer((CAkSrcFileBase *)&v3->vfptr);
    if ( v4 != 45 )
      goto LABEL_10;
  }
  v25 = (unsigned int *)&v3->m_pCtx->m_sMediaFormat;
  v5 = *((_DWORD *)&v3->m_pCtx->m_sMediaFormat + 1);
  v6 = 0i64;
  nChannels = 0;
  v8 = (v5 >> 24) & 0x1F;
  in_channelMask = v5 & 0x3FFFF;
  v9 = v5 & 0x3FFFF;
  if ( v5 & 0x3FFFF )
  {
    do
    {
      ++nChannels;
      v9 &= v9 - 1;
    }
    while ( v9 );
  }
  v10 = 1024;
  v11 = (char *)CAkLEngine::GetCachedAudioBuffer(v8 << 10);
  v28 = v11;
  v3->m_pOutBuffer = v11;
  if ( v11 )
  {
    v12 = v3->m_wExtraSize;
    v26 = v8 << 6;
    if ( v12 )
    {
      memmove(&v3->m_ExtraBlock[v12], v3->m_pNextAddress, v3->m_uInputBlockSize - v12);
      if ( nChannels )
      {
        v13 = v3->m_ExtraBlock;
        v14 = nChannels;
        do
        {
          CAkADPCMCodec::Decode(v13, v11, 1u, v3->m_uInputBlockSize, nChannels);
          v11 += 2;
          v13 += 36;
          --v14;
        }
        while ( v14 );
        v11 = v28;
      }
      v10 = 960;
      v15 = v3->m_uInputBlockSize - v3->m_wExtraSize;
      v3->m_wExtraSize = 0;
      v3->m_ulSizeLeft -= v15;
      v3->m_pNextAddress += v15;
      v11 += v26;
      v28 = v11;
    }
    v16 = (unsigned int)v10 >> 6;
    if ( (unsigned int)(v3->m_ulSizeLeft / v3->m_uInputBlockSize) < v16 )
      v16 = v3->m_ulSizeLeft / v3->m_uInputBlockSize;
    if ( nChannels )
    {
      v17 = nChannels;
      do
      {
        CAkADPCMCodec::Decode(&v3->m_pNextAddress[v6], v11, v16, v3->m_uInputBlockSize, nChannels);
        v11 += 2;
        v6 += 36i64;
        --v17;
      }
      while ( v17 );
      v11 = v28;
    }
    v18 = v3->m_uInputBlockSize;
    v19 = (signed __int64)&v11[v26 * v16 - (unsigned __int64)v3->m_pOutBuffer];
    v20 = v16 * v3->m_uInputBlockSize;
    v3->m_ulSizeLeft -= v20;
    v3->m_pNextAddress += v20;
    v21 = v19 / v8;
    if ( v3->m_ulSizeLeft < v18 )
    {
      v22 = LOWORD(v3->m_ulSizeLeft);
      v23 = v3->m_pNextAddress;
      v3->m_wExtraSize = v22;
      memmove(v3->m_ExtraBlock, v23, v22);
      v3->m_pNextAddress += v3->m_ulSizeLeft;
      v24 = *((_BYTE *)&v3->0 + 126);
      v3->m_ulSizeLeft = 0;
      if ( v24 & 2 )
        *((_BYTE *)&v3->0 + 126) = v24 & 0xFD;
      else
        ((void (*)(void))v3->m_pStream->vfptr->ReleaseBuffer)();
    }
    CAkSrcBaseEx::SubmitBufferAndUpdate((CAkSrcBaseEx *)&v3->vfptr, v3->m_pOutBuffer, v21, *v25, in_channelMask, v2);
  }
  else
  {
    v2->result = 2;
  }
}

// File Line: 133
// RVA: 0xA9A670
void __fastcall CAkSrcFileADPCM::StopStream(CAkSrcFileADPCM *this)
{
  CAkSrcFileADPCM *v1; // rbx

  v1 = this;
  ((void (*)(void))this->vfptr->ReleaseBuffer)();
  CAkSrcFileBase::StopStream((CAkSrcFileBase *)&v1->vfptr);
}

// File Line: 140
// RVA: 0xA9A630
void __fastcall CAkSrcFileADPCM::ReleaseBuffer(CAkSrcFileADPCM *this)
{
  char *v1; // rdx
  CAkSrcFileADPCM *v2; // rbx

  v1 = this->m_pOutBuffer;
  v2 = this;
  if ( v1 )
  {
    CAkLEngine::ReleaseCachedAudioBuffer((*((_BYTE *)&this->m_pCtx->m_sMediaFormat + 7) & 0x1F) << 10, v1);
    v2->m_pOutBuffer = 0i64;
  }
}

// File Line: 150
// RVA: 0xA9A690
void __fastcall CAkSrcFileADPCM::VirtualOn(CAkSrcFileADPCM *this, AkVirtualQueueBehavior eBehavior)
{
  AkVirtualQueueBehavior v2; // ebx
  CAkSrcFileADPCM *v3; // rdi

  v2 = eBehavior;
  v3 = this;
  CAkSrcFileBase::VirtualOn((CAkSrcFileBase *)&this->vfptr, eBehavior);
  if ( (unsigned int)v2 <= 1 )
    v3->m_wExtraSize = 0;
}

// File Line: 165
// RVA: 0xA9A400
unsigned int __fastcall CAkSrcFileADPCM::ParseHeader(CAkSrcFileADPCM *this, char *in_pBuffer)
{
  CAkSrcFileADPCM *v2; // rbx
  char *v3; // rax
  unsigned int v4; // edx
  unsigned int *v5; // r15
  unsigned int *v6; // rbp
  unsigned int *v7; // rsi
  unsigned int *v8; // r14
  unsigned int result; // eax
  __int64 v10; // rdi
  CAkPBI *v11; // rcx
  unsigned int v12; // er10
  unsigned int v13; // er9
  unsigned int v14; // er8
  unsigned int v15; // er11
  unsigned int v16; // edx
  int v17; // er9
  unsigned int v18; // er10
  unsigned int v19; // er9
  unsigned int v20; // eax
  bool v21; // zf
  float v22; // [rsp+50h] [rbp-48h]
  unsigned int v23; // [rsp+54h] [rbp-44h]
  unsigned int v24; // [rsp+58h] [rbp-40h]
  char v25; // [rsp+5Dh] [rbp-3Bh]
  AkFileParser::AnalysisDataChunk in_analysisDataChunk; // [rsp+60h] [rbp-38h]
  __int64 v27; // [rsp+70h] [rbp-28h]
  __int64 v28; // [rsp+78h] [rbp-20h]
  AkAudioFormat v29; // [rsp+A0h] [rbp+8h]

  v2 = this;
  v3 = in_pBuffer;
  v4 = this->m_ulSizeLeft;
  in_analysisDataChunk.uDataSize = 0;
  in_analysisDataChunk.pData = 0i64;
  v5 = &this->m_uDataOffset;
  v6 = &this->m_uDataSize;
  v7 = &this->m_uPCMLoopEnd;
  v8 = &this->m_uPCMLoopStart;
  result = AkFileParser::Parse(
             v3,
             v4,
             (AkFileParser::FormatInfo *)&v27,
             &this->m_markers,
             &this->m_uPCMLoopStart,
             &this->m_uPCMLoopEnd,
             &this->m_uDataSize,
             &this->m_uDataOffset,
             &in_analysisDataChunk,
             0i64);
  if ( result == 1 )
  {
    v10 = v28;
    if ( *(_WORD *)v28 != 2 )
      return 7;
    v29.uSampleRate = *(_DWORD *)(v28 + 4);
    *((_DWORD *)&v29 + 1) = *(_DWORD *)(v28 + 20) & 0x3FFFF | (*(unsigned __int16 *)(v28 + 2) << 25) & 0x1F000000 | 0x400000;
    v11 = v2->m_pCtx;
    v11->m_sMediaFormat = v29;
    CAkPBI::InvalidateFeedbackParameters(v11);
    if ( in_analysisDataChunk.uDataSize )
      CAkSrcFileBase::StoreAnalysisData((CAkSrcFileBase *)&v2->vfptr, &in_analysisDataChunk);
    v12 = *(unsigned __int16 *)(v10 + 12);
    v13 = *v6;
    v14 = *v5;
    v15 = *v7;
    v2->m_uInputBlockSize = v12;
    v16 = v14 + v13;
    v2->m_uTotalSamples = (v13 << 6) / *(unsigned __int16 *)(v10 + 12);
    if ( v15 && v2->m_uLoopCnt != 1 )
    {
      v17 = v12 * (*v8 >> 6);
      v18 = v14 + ((v15 + 1) >> 6) * v12;
      v19 = v14 + v17;
      v2->m_ulLoopEnd = v18;
      v2->m_ulLoopStart = v19;
      if ( v15 < *v8 || v19 > v16 || v18 > v16 )
        return 7;
    }
    else
    {
      v2->m_ulLoopEnd = v16;
      v2->m_ulLoopStart = v14;
      *v7 = (v13 / v12 << 6) - 1;
    }
    v2->m_pStream->vfptr->GetHeuristics(v2->m_pStream, (AkAutoStmHeuristics *)&v22);
    if ( *v7 <= *v8 || (v20 = v2->m_uTotalSamples, *v8 > v20) || *v7 >= v20 )
    {
      result = 2;
    }
    else
    {
      v21 = v2->m_uLoopCnt == 1;
      v22 = (float)((float)*(unsigned __int16 *)(v10 + 12) * (float)*(signed int *)(v10 + 4)) * 0.000015625001;
      if ( !v21 )
      {
        v23 = v2->m_ulLoopStart;
        v24 = v2->m_ulLoopEnd;
      }
      v25 = (signed int)v2->m_pCtx->m_PriorityInfoCurrent.currentPriority.priority;
      v2->m_pStream->vfptr->SetHeuristics(v2->m_pStream, (AkAutoStmHeuristics *)&v22);
      result = v2->m_pStream->vfptr->SetMinimalBufferSize(v2->m_pStream, 36 * *(unsigned __int16 *)(v10 + 2));
    }
  }
  return result;
}

// File Line: 290
// RVA: 0xA9A3C0
float __fastcall CAkSrcFileADPCM::GetThroughput(CAkSrcFileADPCM *this, AkAudioFormat *in_rFormat)
{
  int v2; // er8
  int i; // ecx

  v2 = 0;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v2;
  return (float)(36 * v2 * in_rFormat->uSampleRate) * 0.000015625001;
}

// File Line: 302
// RVA: 0xA9A0C0
signed __int64 __fastcall CAkSrcFileADPCM::FindClosestFileOffset(CAkSrcFileADPCM *this, unsigned int in_uDesiredSample, unsigned int *out_uSeekedSample, unsigned int *out_uFileOffset)
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
  return CAkSrcFileBase::ChangeSourcePosition((CAkSrcFileBase *)&this->vfptr);
}

