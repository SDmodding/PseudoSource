// File Line: 24
// RVA: 0xA991D0
void __fastcall CAkSrcFilePCM::CAkSrcFilePCM(CAkSrcFilePCM *this, CAkPBI *in_pCtx)
{
  CAkSrcFilePCM *v2; // rbx

  v2 = this;
  CAkSrcFileBase::CAkSrcFileBase((CAkSrcFileBase *)&this->vfptr, in_pCtx);
  v2->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFilePCM::`vftable;
  v2->m_pStitchBuffer = 0i64;
  *(_QWORD *)&v2->m_uNumBytesBuffered = 0i64;
}

// File Line: 32
// RVA: 0xA997F0
void __fastcall CAkSrcFilePCM::StopStream(CAkSrcFilePCM *this)
{
  char *v1; // rdx
  CAkSrcFilePCM *v2; // rbx

  v1 = this->m_pStitchBuffer;
  v2 = this;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
    v2->m_pStitchBuffer = 0i64;
    v2->m_uNumBytesBuffered = 0;
  }
  CAkSrcFileBase::StopStream((CAkSrcFileBase *)&v2->vfptr);
}

// File Line: 44
// RVA: 0xA99300
void __fastcall CAkSrcFilePCM::GetBuffer(CAkSrcFilePCM *this, AkVPLState *io_state)
{
  AkVPLState *v2; // rdi
  CAkSrcFilePCM *v3; // rbx
  AKRESULT v4; // eax
  unsigned __int16 v5; // ax
  unsigned int v6; // ecx
  unsigned __int16 v7; // r13
  unsigned int v8; // esi
  unsigned int v9; // ebp
  unsigned int v10; // eax
  CAkPBI *v11; // r15
  __int64 v12; // rax
  char *v13; // rdx
  char *v14; // r12
  int v15; // eax
  unsigned int v16; // er14
  char *v17; // rax
  char *v18; // rdx
  unsigned int v19; // esi

  v2 = io_state;
  v3 = this;
  if ( *((_BYTE *)&this->0 + 32) & 2 )
  {
    v4 = AK::SrcFileServices::IsPrebufferingReady(this->m_pStream, this->m_ulSizeLeft);
    if ( v4 != 45 )
    {
LABEL_9:
      v2->result = v4;
      return;
    }
    *((_BYTE *)&v3->0 + 32) &= 0xFDu;
  }
  if ( !v3->m_ulSizeLeft )
  {
    v4 = CAkSrcFileBase::FetchStreamBuffer((CAkSrcFileBase *)&v3->vfptr);
    if ( v4 != 45 )
      goto LABEL_9;
  }
  v5 = ((__int64 (__fastcall *)(CAkSrcFilePCM *))v3->vfptr[2].Connect)(v3);
  v6 = v3->m_ulSizeLeft;
  v7 = v5;
  v8 = v5;
  v9 = v3->m_ulSizeLeft / v5;
  if ( !v6 && *((_BYTE *)&v3->0 + 126) & 1 )
  {
    v2->result = 2;
    return;
  }
  v10 = v2->uMaxFrames;
  v11 = v3->m_pCtx;
  if ( v10 < v9 )
    LOWORD(v9) = v2->uMaxFrames;
  v12 = v3->m_uNumBytesBuffered;
  if ( (_DWORD)v12 )
  {
    v19 = v8 - v12;
    if ( v19 <= v6 )
    {
      memmove(&v3->m_pStitchBuffer[v12], v3->m_pNextAddress, v19);
      v14 = v3->m_pStitchBuffer;
      v3->m_uSizeToRelease = (unsigned __int16)v19;
      LOWORD(v9) = 1;
      v3->m_uNumBytesBuffered = 0;
      goto LABEL_22;
    }
LABEL_20:
    v2->result = 2;
    return;
  }
  v13 = v3->m_pStitchBuffer;
  if ( v13 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v13);
    v3->m_pStitchBuffer = 0i64;
  }
  v14 = v3->m_pNextAddress;
  v15 = v8 * (unsigned __int16)v9;
  v16 = v3->m_ulSizeLeft - v15;
  v3->m_uSizeToRelease = v15;
  if ( v16 >= v8 || !v16 )
    goto LABEL_22;
  v17 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, v7);
  v3->m_pStitchBuffer = v17;
  if ( !v17 )
    goto LABEL_20;
  v18 = &v3->m_pNextAddress[v3->m_uSizeToRelease];
  v3->m_uNumBytesBuffered = (unsigned __int16)v16;
  memmove(v17, v18, (unsigned __int16)v16);
  v3->m_uSizeToRelease += v3->m_uNumBytesBuffered;
LABEL_22:
  CAkSrcBaseEx::SubmitBufferAndUpdate(
    (CAkSrcBaseEx *)&v3->vfptr,
    v14,
    v9,
    v11->m_sMediaFormat.uSampleRate,
    *((_DWORD *)&v11->m_sMediaFormat + 1) & 0x3FFFF,
    v2);
}

// File Line: 162
// RVA: 0xA997B0
void __fastcall CAkSrcFilePCM::ReleaseBuffer(CAkSrcFilePCM *this)
{
  __int64 v1; // rax
  char v2; // al

  v1 = this->m_uSizeToRelease;
  this->m_uSizeToRelease = 0;
  this->m_ulSizeLeft -= v1;
  this->m_pNextAddress += v1;
  if ( !this->m_ulSizeLeft )
  {
    v2 = *((_BYTE *)&this->0 + 126);
    if ( v2 & 2 )
      *((_BYTE *)&this->0 + 126) = v2 & 0xFD;
    else
      ((void (*)(void))this->m_pStream->vfptr->ReleaseBuffer)();
  }
}

// File Line: 175
// RVA: 0xA99830
void __fastcall CAkSrcFilePCM::VirtualOn(CAkSrcFilePCM *this, AkVirtualQueueBehavior eBehavior)
{
  AkVirtualQueueBehavior v2; // edi
  char *v3; // rdx
  CAkSrcFilePCM *v4; // rbx

  v2 = eBehavior;
  v3 = this->m_pStitchBuffer;
  v4 = this;
  if ( v3 && (unsigned int)v2 <= 1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v3);
    v4->m_pStitchBuffer = 0i64;
    v4->m_uNumBytesBuffered = 0;
  }
  CAkSrcFileBase::VirtualOn((CAkSrcFileBase *)&v4->vfptr, v2);
}

// File Line: 194
// RVA: 0xA995B0
unsigned int __fastcall CAkSrcFilePCM::ParseHeader(CAkSrcFilePCM *this, char *in_pBuffer)
{
  CAkSrcFilePCM *v2; // rbx
  char *v3; // rax
  unsigned int v4; // edx
  unsigned int *v5; // r14
  unsigned int *v6; // r15
  unsigned int *v7; // rsi
  unsigned int *v8; // rbp
  unsigned int result; // eax
  __int64 v10; // rdi
  CAkPBI *v11; // rcx
  unsigned int v12; // er10
  unsigned int v13; // er11
  unsigned int v14; // er9
  int v15; // ecx
  int v16; // er8
  unsigned int v17; // ecx
  unsigned int v18; // er8
  bool v19; // zf
  float v20; // [rsp+50h] [rbp-48h]
  unsigned int v21; // [rsp+54h] [rbp-44h]
  unsigned int v22; // [rsp+58h] [rbp-40h]
  char v23; // [rsp+5Dh] [rbp-3Bh]
  AkFileParser::AnalysisDataChunk in_analysisDataChunk; // [rsp+60h] [rbp-38h]
  __int64 v25; // [rsp+70h] [rbp-28h]
  __int64 v26; // [rsp+78h] [rbp-20h]
  AkAudioFormat v27; // [rsp+A0h] [rbp+8h]

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
             (AkFileParser::FormatInfo *)&v25,
             &this->m_markers,
             &this->m_uPCMLoopStart,
             &this->m_uPCMLoopEnd,
             &this->m_uDataSize,
             &this->m_uDataOffset,
             &in_analysisDataChunk,
             0i64);
  if ( result == 1 )
  {
    v10 = v26;
    if ( *(_WORD *)v26 != -2 )
      return 7;
    v27.uSampleRate = *(_DWORD *)(v26 + 4);
    *((_DWORD *)&v27 + 1) = *(_DWORD *)(v26 + 20) & 0x3FFFF | ((*(_WORD *)(v26 + 14) & 0x3F | ((*(_WORD *)(v26 + 12) & 0x1F) << 6)) << 18);
    v11 = v2->m_pCtx;
    v11->m_sMediaFormat = v27;
    CAkPBI::InvalidateFeedbackParameters(v11);
    if ( in_analysisDataChunk.uDataSize )
      CAkSrcFileBase::StoreAnalysisData((CAkSrcFileBase *)&v2->vfptr, &in_analysisDataChunk);
    v12 = *v5;
    v13 = *v7;
    v14 = *v5 + *v6;
    v2->m_uTotalSamples = *v6 / *(unsigned __int16 *)(v10 + 12);
    if ( v13 && v2->m_uLoopCnt != 1 )
    {
      v15 = *(unsigned __int16 *)(v10 + 12);
      v16 = v15 * *v8;
      v17 = v12 + (v13 + 1) * v15;
      v18 = v12 + v16;
      v2->m_ulLoopEnd = v17;
      v2->m_ulLoopStart = v18;
      if ( v13 < *v8 || v18 > v14 || v17 > v14 )
        return 7;
    }
    else
    {
      v2->m_ulLoopEnd = v14;
      v2->m_ulLoopStart = v12;
      *v7 = (v14 - v12) / *(unsigned __int16 *)(v10 + 12) - 1;
    }
    v2->m_pStream->vfptr->GetHeuristics(v2->m_pStream, (AkAutoStmHeuristics *)&v20);
    v19 = v2->m_uLoopCnt == 1;
    v20 = (float)(*(_DWORD *)(v10 + 4) * *(unsigned __int16 *)(v10 + 12)) * 0.001;
    if ( !v19 )
    {
      v21 = v2->m_ulLoopStart;
      v22 = v2->m_ulLoopEnd;
    }
    v23 = (signed int)v2->m_pCtx->m_PriorityInfoCurrent.currentPriority.priority;
    v2->m_pStream->vfptr->SetHeuristics(v2->m_pStream, (AkAutoStmHeuristics *)&v20);
    result = v2->m_pStream->vfptr->SetMinimalBufferSize(v2->m_pStream, *(unsigned __int16 *)(v10 + 12));
  }
  return result;
}

// File Line: 311
// RVA: 0xA994E0
float __fastcall CAkSrcFilePCM::GetThroughput(CAkSrcFilePCM *this, AkAudioFormat *in_rFormat)
{
  return (float)(in_rFormat->uSampleRate * ((unsigned __int16 (*)(void))this->vfptr[2].Connect)()) * 0.001;
}

// File Line: 323
// RVA: 0xA992A0
signed __int64 __fastcall CAkSrcFilePCM::FindClosestFileOffset(CAkSrcFilePCM *this, unsigned int in_uDesiredSample, unsigned int *out_uSeekedSample, unsigned int *out_uFileOffset)
{
  *out_uSeekedSample = in_uDesiredSample;
  *out_uFileOffset = this->m_uDataOffset + in_uDesiredSample * ((unsigned __int16 (*)(void))this->vfptr[2].Connect)();
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
  char *v1; // rdx
  CAkSrcFilePCM *v2; // rbx

  v1 = this->m_pStitchBuffer;
  v2 = this;
  this->m_uSizeToRelease = 0;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
    v2->m_pStitchBuffer = 0i64;
    v2->m_uNumBytesBuffered = 0;
  }
  return CAkSrcFileBase::ChangeSourcePosition((CAkSrcFileBase *)&v2->vfptr);
}

// File Line: 351
// RVA: 0xA99570
bool __fastcall CAkSrcFilePCM::MustRelocatePitchInputBufferOnMediaRelocation(CAkSrcFilePCM *this)
{
  return (*((_BYTE *)&this->0 + 126) >> 3) & 1;
}

