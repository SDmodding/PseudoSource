// File Line: 32
// RVA: 0xA98E10
void __fastcall CAkSrcBankPCM::CAkSrcBankPCM(CAkSrcBankPCM *this, CAkPBI *in_pCtx)
{
  CAkSrcBankPCM *v2; // rbx

  v2 = this;
  CAkSrcBaseEx::CAkSrcBaseEx((CAkSrcBaseEx *)&this->vfptr, in_pCtx);
  v2->vfptr = (CAkVPLNodeVtbl *)&CAkSrcBankPCM::`vftable;
}

// File Line: 55
// RVA: 0xA98F90
__int64 __fastcall CAkSrcBankPCM::StartStream(CAkSrcBankPCM *this)
{
  CAkPBI *v1; // rax
  CAkSrcBankPCM *v2; // rbx
  char *v3; // rsi
  unsigned int v4; // ebp
  __int64 result; // rax
  unsigned int *v6; // r12
  unsigned int *v7; // r13
  unsigned int *v8; // r14
  unsigned int *v9; // r15
  WaveFormatExtensible *v10; // rdi
  CAkPBI *v11; // rcx
  __int64 v12; // r9
  unsigned int v13; // er8
  bool v14; // zf
  CAkPBI *v15; // rax
  AkFileParser::AnalysisDataChunk out_pAnalysisData; // [rsp+50h] [rbp-48h]
  AkFileParser::FormatInfo out_pFormatInfo; // [rsp+60h] [rbp-38h]
  AkAudioFormat v18; // [rsp+A0h] [rbp+8h]

  v1 = this->m_pCtx;
  v2 = this;
  v3 = v1->m_pDataPtr;
  v4 = v1->m_uDataSize;
  if ( !v3 )
    return 2i64;
  v6 = &this->m_uDataOffset;
  v7 = &this->m_uDataSize;
  out_pAnalysisData.uDataSize = 0;
  out_pAnalysisData.pData = 0i64;
  v8 = &this->m_uPCMLoopEnd;
  v9 = &this->m_uPCMLoopStart;
  if ( AkFileParser::Parse(
         v3,
         v4,
         &out_pFormatInfo,
         &this->m_markers,
         &this->m_uPCMLoopStart,
         &this->m_uPCMLoopEnd,
         &this->m_uDataSize,
         &this->m_uDataOffset,
         &out_pAnalysisData,
         0i64) != 1 )
    return 7i64;
  v10 = out_pFormatInfo.pFormat;
  if ( out_pFormatInfo.pFormat->wFormatTag != -2 )
    return 7i64;
  v18.uSampleRate = out_pFormatInfo.pFormat->nSamplesPerSec;
  *((_DWORD *)&v18 + 1) = out_pFormatInfo.pFormat->dwChannelMask & 0x3FFFF | ((out_pFormatInfo.pFormat->wBitsPerSample & 0x3F | ((out_pFormatInfo.pFormat->nBlockAlign & 0x1F) << 6)) << 18);
  v11 = v2->m_pCtx;
  v11->m_sMediaFormat = v18;
  CAkPBI::InvalidateFeedbackParameters(v11);
  if ( out_pAnalysisData.uDataSize )
    v2->m_pAnalysisData = out_pAnalysisData.pData;
  v12 = *v6;
  v13 = *v7;
  v2->m_pucDataStart = &v3[v12];
  v14 = *v8 == 0;
  v2->m_uTotalSamples = v13 / v10->nBlockAlign;
  if ( v14 || v2->m_uLoopCnt == 1 )
    *v8 = v13 / v10->nBlockAlign - 1;
  if ( *v8 < *v9 || *v8 >= v2->m_uTotalSamples || v4 != v13 + (_DWORD)v12 )
    return 2i64;
  v15 = v2->m_pCtx;
  v2->m_uCurSample = 0;
  if ( *((_BYTE *)v15 + 375) & 2 )
    result = CAkSrcBankPCM::ChangeSourcePosition(v2);
  else
    result = 1i64;
  return result;
}

// File Line: 150
// RVA: 0xA98F30
signed __int64 __fastcall CAkSrcBankPCM::RelocateMedia(CAkSrcBankPCM *this, char *in_pNewMedia, char *in_pOldMedia)
{
  if ( this->m_pucDataStart )
    this->m_pucDataStart = &in_pNewMedia[this->m_uDataOffset];
  return 1i64;
}

// File Line: 159
// RVA: 0xA98E80
void __fastcall CAkSrcBankPCM::GetBuffer(CAkSrcBankPCM *this, AkVPLState *io_state)
{
  CAkPBI *v2; // r9
  unsigned __int16 v3; // r8
  AkVPLState *v4; // r11
  CAkSrcBankPCM *v5; // r10
  unsigned int v6; // ecx
  unsigned int v7; // edx

  v2 = this->m_pCtx;
  v3 = io_state->uMaxFrames;
  v4 = io_state;
  v5 = this;
  if ( this->m_uLoopCnt == 1 )
    v6 = this->m_uTotalSamples;
  else
    v6 = this->m_uPCMLoopEnd + 1;
  v7 = v5->m_uCurSample;
  if ( v7 + v3 > v6 )
    v3 = v6 - v7;
  CAkSrcBaseEx::SubmitBufferAndUpdate(
    (CAkSrcBaseEx *)&v5->vfptr,
    &v5->m_pucDataStart[((*((_DWORD *)&v2->m_sMediaFormat + 1) >> 24) & 0x1F) * v7],
    v3,
    v2->m_sMediaFormat.uSampleRate,
    *((_DWORD *)&v2->m_sMediaFormat + 1) & 0x3FFFF,
    v4);
}

// File Line: 177
// RVA: 0xA99160
signed __int64 __fastcall CAkSrcBankPCM::VirtualOff(CAkSrcBankPCM *this, AkVirtualQueueBehavior eBehavior, bool in_bUseSourceOffset)
{
  CAkSrcBankPCM *v3; // rbx
  CAkPBI *v4; // rax
  CAkPBI *v6; // rax

  v3 = this;
  if ( eBehavior == AkVirtualQueueBehavior_FromBeginning )
  {
    v4 = this->m_pCtx;
    this->m_uCurSample = 0;
    this->m_uLoopCnt = v4->m_LoopCount;
    return 1i64;
  }
  if ( !in_bUseSourceOffset || eBehavior != 1 )
    return 1i64;
  this->m_uCurSample = CAkSrcBaseEx::GetSourceOffset((CAkSrcBaseEx *)&this->vfptr);
  v6 = v3->m_pCtx;
  *((_BYTE *)v6 + 375) &= 0xF1u;
  v6->m_uSeekPosition = 0;
  return 2 - (unsigned int)(v3->m_uCurSample < v3->m_uTotalSamples);
}

// File Line: 205
// RVA: 0xA98F50
__int64 __fastcall CAkSrcBankPCM::ChangeSourcePosition(CAkSrcBankPCM *this)
{
  CAkSrcBankPCM *v1; // rbx
  CAkPBI *v2; // rax

  v1 = this;
  this->m_uCurSample = CAkSrcBaseEx::GetSourceOffset((CAkSrcBaseEx *)&this->vfptr);
  v2 = v1->m_pCtx;
  *((_BYTE *)v2 + 375) &= 0xF1u;
  v2->m_uSeekPosition = 0;
  return 2 - (unsigned int)(v1->m_uCurSample < v1->m_uTotalSamples);
}

