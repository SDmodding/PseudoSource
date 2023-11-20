// File Line: 40
// RVA: 0xA9F770
void __fastcall CAkSrcFileBase::CAkSrcFileBase(CAkSrcFileBase *this, CAkPBI *in_pCtx)
{
  CAkSrcFileBase *v2; // rbx

  v2 = this;
  CAkSrcBaseEx::CAkSrcBaseEx((CAkSrcBaseEx *)&this->vfptr, in_pCtx);
  v2->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFileBase::`vftable';
  *((_BYTE *)v2 + 126) &= 0xC0u;
  v2->m_pStream = 0i64;
  v2->m_pNextAddress = 0i64;
  *(_QWORD *)&v2->m_ulSizeLeft = 0i64;
  *(_QWORD *)&v2->m_uiCorrection = 0i64;
  v2->m_ulLoopEnd = 0;
  v2->m_uStreamLoopCntAhead = 0;
}

// File Line: 44
// RVA: 0xA9F7B0
void __fastcall CAkSrcFileBase::~CAkSrcFileBase(CAkSrcFileBase *this)
{
  bool v1; // zf
  CAkSrcFileBase *v2; // rbx
  AkFileParser::AnalysisData *v3; // rdx
  AK::IAkAutoStream *v4; // rcx

  v1 = (*((_BYTE *)this + 126) & 0x10) == 0;
  v2 = this;
  this->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFileBase::`vftable';
  if ( !v1 )
  {
    v3 = this->m_pAnalysisData;
    if ( v3 )
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v3);
  }
  v4 = v2->m_pStream;
  if ( v4 )
  {
    (*(void (**)(void))v4->vfptr->gap8)();
    v2->m_pStream = 0i64;
    CAkSrcBaseEx::StopStream((CAkSrcBaseEx *)&v2->vfptr);
  }
  CAkSrcBaseEx::~CAkSrcBaseEx((CAkSrcBaseEx *)&v2->vfptr);
}

// File Line: 58
// RVA: 0xAA0050
unsigned int __fastcall CAkSrcFileBase::StartStream(CAkSrcFileBase *this)
{
  CAkSrcFileBase *v1; // rbx
  unsigned int v2; // edx
  AK::IAkAutoStream *v3; // rcx
  unsigned int result; // eax
  AkAutoStmBufSettings in_bufSettings; // [rsp+20h] [rbp-18h]
  bool out_bUsePrefetchedData; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( *((_BYTE *)this + 126) & 4 )
  {
    if ( *((_BYTE *)&this->0 + 32) & 2 )
    {
      v2 = this->m_ulSizeLeft;
      v3 = this->m_pStream;
      goto LABEL_13;
    }
    return 1;
  }
  if ( this->m_pStream )
  {
LABEL_10:
    result = CAkSrcFileBase::ProcessFirstBuffer(this);
    if ( result != 1 )
      return result;
    if ( *((_BYTE *)&v1->0 + 32) & 2 )
    {
      v3 = v1->m_pStream;
      v2 = v1->m_ulSizeLeft;
LABEL_13:
      result = AK::SrcFileServices::IsPrebufferingReady(v3, v2);
      if ( result == 46 )
        return 63;
      if ( result == 45 )
        result = 1;
      return result;
    }
    return 1;
  }
  in_bufSettings.uBufferSize = 0;
  *(_QWORD *)&in_bufSettings.uMinBufferSize = 2048i64;
  result = CAkSrcFileBase::CreateStream(this, &in_bufSettings, 0);
  if ( result == 1 )
  {
    result = CAkSrcFileBase::HandlePrefetch(v1, &out_bUsePrefetchedData);
    if ( result == 1 )
    {
      result = ((__int64 (*)(void))v1->m_pStream->vfptr->Start)();
      if ( result == 1 && !out_bUsePrefetchedData )
      {
        this = v1;
        goto LABEL_10;
      }
    }
  }
  return result;
}

// File Line: 111
// RVA: 0xA9FE60
signed __int64 __fastcall CAkSrcFileBase::RelocateMedia(CAkSrcFileBase *this, char *in_pNewMedia, char *in_pOldMedia)
{
  signed __int64 result; // rax

  result = 1i64;
  if ( *((_BYTE *)this + 126) & 8 )
    this->m_pNextAddress += in_pNewMedia - in_pOldMedia;
  return result;
}

// File Line: 118
// RVA: 0xA9FBB0
bool __fastcall CAkSrcFileBase::MustRelocateAnalysisDataOnMediaRelocation(CAkSrcFileBase *this)
{
  return this->m_pAnalysisData && !(*((_BYTE *)this + 126) & 0x10);
}

// File Line: 127
// RVA: 0xA9F8F0
signed __int64 __fastcall CAkSrcFileBase::CreateStream(CAkSrcFileBase *this, AkAutoStmBufSettings *in_bufSettings, char in_uMinNumBuffers)
{
  CAkPBI *v3; // rax
  AkAutoStmBufSettings *v4; // rdi
  signed int v5; // er9
  CAkSource *v6; // rdx
  CAkSrcFileBase *v7; // r11
  signed int v9; // er8
  unsigned int v10; // er10
  char v11; // cl
  int v12; // eax
  unsigned int v13; // ebx
  AK::IAkStreamMgrVtbl *v14; // r10
  unsigned int v15; // eax
  bool v16; // [rsp+30h] [rbp-48h]
  int v17; // [rsp+40h] [rbp-38h]
  __int64 v18; // [rsp+44h] [rbp-34h]
  char v19; // [rsp+4Ch] [rbp-2Ch]
  char v20; // [rsp+4Dh] [rbp-2Bh]
  int v21; // [rsp+50h] [rbp-28h]
  int v22; // [rsp+54h] [rbp-24h]
  int v23; // [rsp+58h] [rbp-20h]
  __int64 v24; // [rsp+60h] [rbp-18h]
  char v25; // [rsp+68h] [rbp-10h]
  char v26; // [rsp+69h] [rbp-Fh]
  int v27; // [rsp+6Ch] [rbp-Ch]

  v3 = this->m_pCtx;
  v4 = in_bufSettings;
  v5 = -1;
  v6 = v3->m_pSource;
  v7 = this;
  if ( !v6->m_sSrcTypeInfo.pInMemoryMedia && v6->m_sSrcTypeInfo.mediaInfo.uFileID == -1 )
    return 2i64;
  v19 = in_uMinNumBuffers;
  v9 = 0;
  v17 = (signed int)FLOAT_1_0;
  v18 = 0i64;
  v20 = (signed int)v3->m_PriorityInfoCurrent.currentPriority.priority;
  v10 = *((_DWORD *)&v6->m_sSrcTypeInfo.mediaInfo + 4);
  if ( !_bittest((const signed int *)&v10, 8u) )
    v5 = v6->m_sSrcTypeInfo.mediaInfo.uFileID;
  v11 = *((_BYTE *)&v6->m_sSrcTypeInfo.mediaInfo + 16);
  v12 = HIWORD(v6->m_sSrcTypeInfo.dwID);
  v21 = 0;
  v22 = v12;
  v23 = 0;
  v24 = 0i64;
  v25 = v11 & 1;
  v27 = v5;
  v26 = (v10 >> 9) & 1;
  v13 = 1;
  if ( *((_DWORD *)&v6->m_sSrcTypeInfo.mediaInfo + 4) & 0x100 )
    v9 = 1;
  v16 = 0;
  v21 = v9;
  v14 = AK::IAkStreamMgr::m_pStreamMgr->vfptr;
  if ( (*((_DWORD *)&v6->m_sSrcTypeInfo.mediaInfo + 4) >> 10) & 1 )
    v15 = v14->CreateAuto(
            AK::IAkStreamMgr::m_pStreamMgr,
            v6->m_sSrcTypeInfo.pszFilename,
            (AkFileSystemFlags *)&v21,
            (AkAutoStmHeuristics *)&v17,
            v4,
            &v7->m_pStream,
            v16);
  else
    v15 = v14->CreateAuto(
            AK::IAkStreamMgr::m_pStreamMgr,
            v6->m_sSrcTypeInfo.mediaInfo.uFileID,
            (AkFileSystemFlags *)&v21,
            (AkAutoStmHeuristics *)&v17,
            v4,
            &v7->m_pStream,
            v16);
  if ( v15 != 1 )
    v13 = v15;
  return v13;
}

// File Line: 249
// RVA: 0xA9FAE0
unsigned int __fastcall CAkSrcFileBase::HandlePrefetch(CAkSrcFileBase *this, bool *out_bUsePrefetchedData)
{
  CAkSrcFileBase *v2; // rbx
  CAkPBI *v3; // rcx
  char *v4; // rdi
  unsigned int v5; // eax
  bool v6; // al
  unsigned int result; // eax
  __int64 v8; // rdx

  *out_bUsePrefetchedData = 0;
  v2 = this;
  v3 = this->m_pCtx;
  if ( !((*((_DWORD *)&v3->m_pSource->m_sSrcTypeInfo.mediaInfo + 4) >> 1) & 1) || *((_BYTE *)v3 + 375) & 2 )
    return 1;
  v4 = v3->m_pDataPtr;
  v5 = v3->m_uDataSize;
  v2->m_ulSizeLeft = v5;
  v6 = v4 && v5;
  *out_bUsePrefetchedData = v6;
  *((_BYTE *)v2 + 126) &= 0xFDu;
  *((_BYTE *)v2 + 126) |= 2 * v6;
  if ( !*out_bUsePrefetchedData )
    return 1;
  *((_BYTE *)v2 + 126) |= 0x20u;
  result = ((unsigned __int64 (__fastcall *)(CAkSrcFileBase *, char *))v2->vfptr[2].VirtualOff)(v2, v4);
  if ( result == 1 )
  {
    result = CAkSrcFileBase::ProcessStreamBuffer(v2, v4, 1);
    if ( result == 1 )
    {
      if ( v2->m_uStreamLoopCntAhead || (result = CAkSrcFileBase::SetStreamPosition(v2, v2->m_ulSizeLeft), result == 1) )
      {
        v8 = v2->m_uDataOffset;
        v2->m_pNextAddress += v8;
        v2->m_ulSizeLeft -= v8;
        return 1;
      }
    }
  }
  return result;
}

// File Line: 295
// RVA: 0xAA0160
void __fastcall CAkSrcFileBase::StopStream(CAkSrcFileBase *this)
{
  CAkSrcFileBase *v1; // rbx
  AK::IAkAutoStream *v2; // rcx

  v1 = this;
  v2 = this->m_pStream;
  if ( v2 )
  {
    (*(void (**)(void))v2->vfptr->gap8)();
    v1->m_pStream = 0i64;
  }
  CAkSrcBaseEx::StopStream((CAkSrcBaseEx *)&v1->vfptr);
}

// File Line: 307
// RVA: 0xAA0110
signed __int64 __fastcall CAkSrcFileBase::StopLooping(CAkSrcFileBase *this)
{
  CAkSrcFileBase *v1; // rbx
  AK::IAkAutoStream *v2; // rcx
  AK::IAkAutoStream *v3; // rcx
  char v5; // [rsp+20h] [rbp-18h]
  int v6; // [rsp+28h] [rbp-10h]

  v1 = this;
  this->m_uLoopCnt = this->m_uStreamLoopCntAhead + 1;
  v2 = this->m_pStream;
  if ( v2 )
  {
    v2->vfptr->GetHeuristics(v2, (AkAutoStmHeuristics *)&v5);
    v3 = v1->m_pStream;
    v6 = 0;
    v3->vfptr->SetHeuristics(v3, (AkAutoStmHeuristics *)&v5);
  }
  return 1i64;
}

// File Line: 326
// RVA: 0xA9FA20
unsigned int __fastcall CAkSrcFileBase::FetchStreamBuffer(CAkSrcFileBase *this)
{
  CAkSrcFileBase *v1; // rbx
  AK::IAkAutoStream *v2; // rcx
  unsigned int result; // eax
  char v4; // [rsp+20h] [rbp-18h]
  char v5; // [rsp+2Dh] [rbp-Bh]
  char *in_pBuffer; // [rsp+40h] [rbp+8h]

  this->m_pNextAddress = 0i64;
  v1 = this;
  this->m_pStream->vfptr->GetHeuristics(this->m_pStream, (AkAutoStmHeuristics *)&v4);
  v2 = v1->m_pStream;
  v5 = (signed int)v1->m_pCtx->m_PriorityInfoCurrent.currentPriority.priority;
  v2->vfptr->SetHeuristics(v2, (AkAutoStmHeuristics *)&v4);
  result = v1->m_pStream->vfptr->GetBuffer(v1->m_pStream, (void **)&in_pBuffer, &v1->m_ulSizeLeft, 0);
  if ( result == 45 || result == 17 )
  {
    if ( v1->m_ulSizeLeft )
    {
      result = CAkSrcFileBase::ProcessStreamBuffer(v1, in_pBuffer, 0);
      if ( result == 1 )
        result = 45;
    }
    else
    {
      result = 2;
    }
  }
  return result;
}

// File Line: 373
// RVA: 0xA9FD00
signed __int64 __fastcall CAkSrcFileBase::ProcessStreamBuffer(CAkSrcFileBase *this, char *in_pBuffer, bool in_bIsReadingPrefecth)
{
  unsigned int v3; // er10
  __int64 v4; // r9
  char *v5; // rax
  unsigned int v6; // er10
  CAkSrcFileBase *v7; // rbx
  unsigned __int16 v8; // r8
  char v9; // dl
  unsigned int v10; // eax
  unsigned int v11; // ecx
  signed __int64 result; // rax
  unsigned int v13; // edi
  unsigned int v14; // eax
  unsigned __int16 v15; // cx
  AK::IAkAutoStream *v16; // rcx
  char v17; // [rsp+20h] [rbp-18h]
  int v18; // [rsp+28h] [rbp-10h]
  __int64 v19; // [rsp+40h] [rbp+8h]

  v3 = this->m_ulSizeLeft;
  *((_BYTE *)this + 126) &= 0xF7u;
  v4 = this->m_uiCorrection;
  this->m_ulFileOffset += v3;
  v5 = &in_pBuffer[v4];
  v6 = v3 - v4;
  v7 = this;
  *((_BYTE *)this + 126) |= 8 * in_bIsReadingPrefecth;
  v8 = this->m_uLoopCnt;
  v9 = *((_BYTE *)this + 126);
  this->m_pNextAddress = v5;
  this->m_ulSizeLeft = v6;
  if ( v8 && v8 - this->m_uStreamLoopCntAhead == 1 )
    v10 = this->m_uDataSize + this->m_uDataOffset;
  else
    v10 = this->m_ulLoopEnd;
  v11 = this->m_ulFileOffset;
  if ( v11 < v10 )
  {
    v7->m_uiCorrection = 0;
  }
  else
  {
    v7->m_ulSizeLeft = v10 + v6 - v11;
    if ( v8 && v8 - v7->m_uStreamLoopCntAhead == 1 )
    {
      result = 1i64;
      *((_BYTE *)v7 + 126) = v9 | 1;
      return result;
    }
    v13 = v7->m_ulLoopStart;
    if ( v7->m_pStream->vfptr->SetPosition(v7->m_pStream, v7->m_ulLoopStart, 0i64, &v19) != 1 )
      return 2i64;
    v14 = v19;
    v15 = v7->m_uLoopCnt;
    ++v7->m_uStreamLoopCntAhead;
    v7->m_ulFileOffset = v14;
    v7->m_uiCorrection = v13 - v14;
    if ( v15 && v15 - v7->m_uStreamLoopCntAhead == 1 )
    {
      v7->m_pStream->vfptr->GetHeuristics(v7->m_pStream, (AkAutoStmHeuristics *)&v17);
      v16 = v7->m_pStream;
      v18 = 0;
      v16->vfptr->SetHeuristics(v16, (AkAutoStmHeuristics *)&v17);
      return 1i64;
    }
  }
  return 1i64;
}

// File Line: 439
// RVA: 0xA9FBD0
__int64 __fastcall CAkSrcFileBase::ProcessFirstBuffer(CAkSrcFileBase *this)
{
  CAkSrcFileBase *v1; // rdi
  AKRESULT v2; // eax
  __int64 result; // rax
  AKRESULT v4; // ebp
  char v5; // cl
  int v6; // ebx
  AKRESULT v7; // eax
  unsigned int v8; // ecx
  char *in_pBuffer; // [rsp+30h] [rbp+8h]

  v1 = this;
  *((_BYTE *)&this->0 + 32) ^= (*((_BYTE *)&this->0 + 32) ^ (*((_BYTE *)this->m_pCtx + 374) >> 4)) & 2;
  v2 = (unsigned int)this->m_pStream->vfptr->GetBuffer(this->m_pStream, (void **)&in_pBuffer, &this->m_ulSizeLeft, 0);
  if ( v2 == 46 )
    return 63i64;
  if ( v2 != 45 && v2 != 17 )
    return 2i64;
  result = ((__int64 (__fastcall *)(CAkSrcFileBase *, char *))v1->vfptr[2].VirtualOff)(v1, in_pBuffer);
  if ( (_DWORD)result == 1 )
  {
    if ( *((_BYTE *)v1->m_pCtx + 375) & 2 )
    {
      v4 = CAkSrcFileBase::SeekToSourceOffset(v1);
      if ( v1->m_ulSizeLeft )
      {
        v5 = *((_BYTE *)v1 + 126);
        if ( v5 & 2 )
        {
          v1->m_ulSizeLeft = 0;
          *((_BYTE *)v1 + 126) = v5 & 0xFD;
        }
        else
        {
          ((void (*)(void))v1->m_pStream->vfptr->ReleaseBuffer)();
          v1->m_ulSizeLeft = 0;
        }
      }
    }
    else
    {
      v6 = v1->m_uiCorrection + v1->m_pStream->vfptr->GetPosition(v1->m_pStream, 0i64);
      v7 = CAkSrcFileBase::ProcessStreamBuffer(v1, in_pBuffer, 0);
      v8 = v1->m_uDataOffset - v6;
      v4 = v7;
      v1->m_pNextAddress += v8;
      v1->m_ulSizeLeft -= v8;
    }
    *((_BYTE *)v1 + 126) |= 4u;
    result = (unsigned int)v4;
  }
  return result;
}

// File Line: 503
// RVA: 0xAA02C0
void __fastcall CAkSrcFileBase::VirtualOn(CAkSrcFileBase *this, AkVirtualQueueBehavior eBehavior)
{
  CAkSrcFileBase *v2; // rdi
  AkVirtualQueueBehavior v3; // ebx
  char v4; // al

  v2 = this;
  v3 = eBehavior;
  ((void (*)(void))this->m_pStream->vfptr->Stop)();
  if ( (unsigned int)v3 <= 1 && v2->m_ulSizeLeft )
  {
    v4 = *((_BYTE *)v2 + 126);
    if ( v4 & 2 )
      *((_BYTE *)v2 + 126) = v4 & 0xFD;
    else
      ((void (*)(void))v2->m_pStream->vfptr->ReleaseBuffer)();
    v2->m_pNextAddress = 0i64;
    v2->m_ulSizeLeft = 0;
  }
}

// File Line: 527
// RVA: 0xAA0210
signed __int64 __usercall CAkSrcFileBase::VirtualOff@<rax>(CAkSrcFileBase *this@<rcx>, __int64 eBehavior@<rdx>, bool in_bUseSourceOffset@<r8b>, float a4@<xmm0>)
{
  CAkSrcFileBase *v4; // rbx
  signed __int64 result; // rax
  CAkPBI *v6; // rax

  v4 = this;
  if ( (_DWORD)eBehavior == 1 )
  {
    if ( in_bUseSourceOffset )
    {
      result = CAkSrcFileBase::SeekToSourceOffset(this, a4);
    }
    else
    {
      if ( (unsigned int)CAkSrcFileBase::SeekStream(this, this->m_uCurSample, &this->m_uCurSample) == 1 )
        return ((__int64 (*)(void))v4->m_pStream->vfptr->Start)();
      result = CAkSrcFileBase::SeekStream(v4, 0i64, &v4->m_uCurSample);
    }
    if ( (_DWORD)result != 1 )
      return result;
    return ((__int64 (*)(void))v4->m_pStream->vfptr->Start)();
  }
  if ( (_DWORD)eBehavior )
  {
    if ( (_DWORD)eBehavior == 2 )
      *((_BYTE *)&this->0 + 32) ^= (*((_BYTE *)&this->0 + 32) ^ (*((_BYTE *)this->m_pCtx + 374) >> 4)) & 2;
    return ((__int64 (*)(void))v4->m_pStream->vfptr->Start)();
  }
  v6 = this->m_pCtx;
  this->m_uCurSample = 0;
  this->m_uLoopCnt = v6->m_LoopCount;
  result = CAkSrcFileBase::SeekStream(this, eBehavior, &this->m_uCurSample);
  if ( (_DWORD)result == 1 )
    return ((__int64 (*)(void))v4->m_pStream->vfptr->Start)();
  return result;
}

// File Line: 575
// RVA: 0xA9FF80
signed __int64 __usercall CAkSrcFileBase::SeekToSourceOffset@<rax>(CAkSrcFileBase *this@<rcx>, float a2@<xmm0>)
{
  CAkSrcFileBase *v2; // rdi
  unsigned int v3; // ebx
  CAkPBI *v5; // rax
  int v6; // ebx

  v2 = this;
  v3 = CAkSrcBaseEx::GetSourceOffset((CAkSrcBaseEx *)&this->vfptr, a2);
  if ( (unsigned int)CAkSrcFileBase::SeekStream(v2, v3, &v2->m_uCurSample) != 1 )
    return 2i64;
  v5 = v2->m_pCtx;
  v6 = v3 - v2->m_uCurSample;
  *((_BYTE *)v5 + 375) &= 0xF1u;
  v5->m_uSeekPosition = v6;
  return 1i64;
}

// File Line: 599
// RVA: 0xA9FEF0
signed __int64 __fastcall CAkSrcFileBase::SeekStream(CAkSrcFileBase *this, __int64 in_uDesiredSample, unsigned int *out_uSeekedSample)
{
  CAkSrcFileBase *v3; // rbx
  AK::IAkAutoStream *v5; // rcx
  unsigned int v6; // edi
  unsigned int v7; // edi
  __int64 v8; // [rsp+30h] [rbp+8h]
  unsigned int v9; // [rsp+38h] [rbp+10h]

  v3 = this;
  if ( (unsigned int)in_uDesiredSample >= this->m_uTotalSamples
    || ((unsigned int (__fastcall *)(CAkSrcFileBase *, __int64, unsigned int *, unsigned int *))this->vfptr[2].GetPitch)(
         this,
         in_uDesiredSample,
         out_uSeekedSample,
         &v9) != 1 )
  {
    return 2i64;
  }
  v5 = v3->m_pStream;
  v6 = v9;
  v3->m_uStreamLoopCntAhead = 0;
  if ( v5->vfptr->SetPosition(v5, v6, 0i64, &v8) != 1 )
    return 2i64;
  v7 = v6 - v8;
  v3->m_ulFileOffset = v8;
  v3->m_uiCorrection = v7;
  CAkSrcFileBase::ResetStreamingAfterSeek(v3);
  return 1i64;
}

// File Line: 645
// RVA: 0xA9FFF0
signed __int64 __fastcall CAkSrcFileBase::SetStreamPosition(CAkSrcFileBase *this, unsigned int in_uPosition)
{
  CAkSrcFileBase *v2; // rdi
  unsigned int v3; // ebx
  signed __int64 result; // rax
  unsigned int v5; // ebx
  __int64 v6; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = in_uPosition;
  if ( this->m_pStream->vfptr->SetPosition(this->m_pStream, in_uPosition, 0i64, &v6) != 1 )
    return 2i64;
  v5 = v3 - v6;
  v2->m_ulFileOffset = v6;
  result = 1i64;
  v2->m_uiCorrection = v5;
  return result;
}

// File Line: 665
// RVA: 0xA9FE80
void __fastcall CAkSrcFileBase::ResetStreamingAfterSeek(CAkSrcFileBase *this)
{
  CAkSrcFileBase *v1; // rbx
  char v2; // [rsp+20h] [rbp-18h]
  __int64 v3; // [rsp+24h] [rbp-14h]

  v1 = this;
  this->m_pStream->vfptr->GetHeuristics(this->m_pStream, (AkAutoStmHeuristics *)&v2);
  if ( v1->m_uLoopCnt == 1 )
    v3 = 0i64;
  else
    v3 = *(_QWORD *)&v1->m_ulLoopStart;
  v1->m_pStream->vfptr->SetHeuristics(v1->m_pStream, (AkAutoStmHeuristics *)&v2);
  *((_BYTE *)v1 + 126) &= 0xFEu;
  *((_BYTE *)&v1->0 + 32) ^= (*((_BYTE *)&v1->0 + 32) ^ (*((_BYTE *)v1->m_pCtx + 374) >> 4)) & 2;
}

// File Line: 682
// RVA: 0xA9F890
signed __int64 __fastcall CAkSrcFileBase::ChangeSourcePosition(CAkSrcFileBase *this)
{
  CAkSrcFileBase *v1; // rbx
  char v2; // al

  v1 = this;
  if ( CAkSrcFileBase::SeekToSourceOffset(this) != 1 )
    return 2i64;
  v2 = *((_BYTE *)v1 + 126);
  if ( v2 & 2 )
    *((_BYTE *)v1 + 126) = v2 & 0xFD;
  else
    ((void (*)(void))v1->m_pStream->vfptr->ReleaseBuffer)();
  v1->m_ulSizeLeft = 0;
  v1->m_pNextAddress = 0i64;
  return 1i64;
}

// File Line: 697
// RVA: 0xA9FAC0
void __fastcall CAkSrcFileBase::GetStreamLoopHeuristic(CAkSrcFileBase *this, bool in_bIsLooping, AkAutoStmHeuristics *io_heuristics)
{
  if ( in_bIsLooping )
  {
    io_heuristics->uLoopStart = this->m_ulLoopStart;
    io_heuristics->uLoopEnd = this->m_ulLoopEnd;
  }
  else
  {
    *(_QWORD *)&io_heuristics->uLoopStart = 0i64;
  }
}

// File Line: 713
// RVA: 0xAA0190
signed __int64 __fastcall CAkSrcFileBase::StoreAnalysisData(CAkSrcFileBase *this, AkFileParser::AnalysisDataChunk *in_analysisDataChunk)
{
  AkFileParser::AnalysisDataChunk *v2; // rdi
  CAkSrcFileBase *v3; // rbx
  AkFileParser::AnalysisData *v4; // rax
  signed __int64 result; // rax

  v2 = in_analysisDataChunk;
  v3 = this;
  if ( *((_BYTE *)this + 126) & 0x20 )
  {
    this->m_pAnalysisData = in_analysisDataChunk->pData;
    result = 1i64;
  }
  else
  {
    v4 = (AkFileParser::AnalysisData *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, in_analysisDataChunk->uDataSize);
    v3->m_pAnalysisData = v4;
    if ( v4 )
    {
      memmove(v4, v2->pData, v2->uDataSize);
      *((_BYTE *)v3 + 126) |= 0x10u;
      result = 1i64;
    }
    else
    {
      result = 52i64;
    }
  }
  return result;
}

