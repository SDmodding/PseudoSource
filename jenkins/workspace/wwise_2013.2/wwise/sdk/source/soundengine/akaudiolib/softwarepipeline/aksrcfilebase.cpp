// File Line: 40
// RVA: 0xA9F770
void __fastcall CAkSrcFileBase::CAkSrcFileBase(CAkSrcFileBase *this, CAkPBI *in_pCtx)
{
  CAkSrcBaseEx::CAkSrcBaseEx(this, in_pCtx);
  this->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFileBase::`vftable;
  *((_BYTE *)this + 126) &= 0xC0u;
  this->m_pStream = 0i64;
  this->m_pNextAddress = 0i64;
  *(_QWORD *)&this->m_ulSizeLeft = 0i64;
  *(_QWORD *)&this->m_uiCorrection = 0i64;
  this->m_ulLoopEnd = 0;
  this->m_uStreamLoopCntAhead = 0;
}

// File Line: 44
// RVA: 0xA9F7B0
void __fastcall CAkSrcFileBase::~CAkSrcFileBase(CAkSrcFileBase *this)
{
  bool v1; // zf
  AkFileParser::AnalysisData *m_pAnalysisData; // rdx
  AK::IAkAutoStream *m_pStream; // rcx

  v1 = (*((_BYTE *)this + 126) & 0x10) == 0;
  this->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFileBase::`vftable;
  if ( !v1 )
  {
    m_pAnalysisData = this->m_pAnalysisData;
    if ( m_pAnalysisData )
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pAnalysisData);
  }
  m_pStream = this->m_pStream;
  if ( m_pStream )
  {
    (*(void (__fastcall **)(AK::IAkAutoStream *))m_pStream->vfptr->gap8)(m_pStream);
    this->m_pStream = 0i64;
    CAkSrcBaseEx::StopStream(this);
  }
  CAkSrcBaseEx::~CAkSrcBaseEx(this);
}

// File Line: 58
// RVA: 0xAA0050
unsigned int __fastcall CAkSrcFileBase::StartStream(CAkSrcFileBase *this)
{
  CAkSrcFileBase *v1; // rbx
  unsigned int m_ulSizeLeft; // edx
  AK::IAkAutoStream *m_pStream; // rcx
  unsigned int result; // eax
  AkAutoStmBufSettings in_bufSettings; // [rsp+20h] [rbp-18h] BYREF
  bool out_bUsePrefetchedData; // [rsp+40h] [rbp+8h] BYREF

  v1 = this;
  if ( (*((_BYTE *)this + 126) & 4) != 0 )
  {
    if ( (*((_BYTE *)&this->CAkVPLSrcNode + 32) & 2) != 0 )
    {
      m_ulSizeLeft = this->m_ulSizeLeft;
      m_pStream = this->m_pStream;
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
    if ( (*((_BYTE *)&v1->CAkVPLSrcNode + 32) & 2) != 0 )
    {
      m_pStream = v1->m_pStream;
      m_ulSizeLeft = v1->m_ulSizeLeft;
LABEL_13:
      result = AK::SrcFileServices::IsPrebufferingReady(m_pStream, m_ulSizeLeft);
      if ( result == 46 )
        return 63;
      if ( result == 45 )
        return 1;
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
      result = v1->m_pStream->vfptr->Start(v1->m_pStream);
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
__int64 __fastcall CAkSrcFileBase::RelocateMedia(CAkSrcFileBase *this, char *in_pNewMedia, char *in_pOldMedia)
{
  __int64 result; // rax

  result = 1i64;
  if ( (*((_BYTE *)this + 126) & 8) != 0 )
    this->m_pNextAddress += in_pNewMedia - in_pOldMedia;
  return result;
}

// File Line: 118
// RVA: 0xA9FBB0
bool __fastcall CAkSrcFileBase::MustRelocateAnalysisDataOnMediaRelocation(CAkSrcFileBase *this)
{
  return this->m_pAnalysisData && (*((_BYTE *)this + 126) & 0x10) == 0;
}

// File Line: 127
// RVA: 0xA9F8F0
__int64 __fastcall CAkSrcFileBase::CreateStream(
        CAkSrcFileBase *this,
        AkAutoStmBufSettings *in_bufSettings,
        char in_uMinNumBuffers)
{
  CAkPBI *m_pCtx; // rax
  int uFileID; // r9d
  CAkSource *m_pSource; // rdx
  int v9; // r8d
  int v10; // r10d
  char v11; // cl
  int dwID_high; // eax
  unsigned int v13; // ebx
  AK::IAkStreamMgrVtbl *vfptr; // r10
  unsigned int v15; // eax
  int v16; // [rsp+40h] [rbp-38h] BYREF
  __int64 v17; // [rsp+44h] [rbp-34h]
  char v18; // [rsp+4Ch] [rbp-2Ch]
  char priority; // [rsp+4Dh] [rbp-2Bh]
  int v20[4]; // [rsp+50h] [rbp-28h] BYREF
  __int64 v21; // [rsp+60h] [rbp-18h]
  char v22; // [rsp+68h] [rbp-10h]
  bool v23; // [rsp+69h] [rbp-Fh]
  int v24; // [rsp+6Ch] [rbp-Ch]

  m_pCtx = this->m_pCtx;
  uFileID = -1;
  m_pSource = m_pCtx->m_pSource;
  if ( !m_pSource->m_sSrcTypeInfo.pInMemoryMedia && m_pSource->m_sSrcTypeInfo.mediaInfo.uFileID == -1 )
    return 2i64;
  v18 = in_uMinNumBuffers;
  v9 = 0;
  v16 = (int)FLOAT_1_0;
  v17 = 0i64;
  priority = (int)m_pCtx->m_PriorityInfoCurrent.currentPriority.priority;
  v10 = *((_DWORD *)&m_pSource->m_sSrcTypeInfo.mediaInfo + 4);
  if ( (v10 & 0x100) == 0 )
    uFileID = m_pSource->m_sSrcTypeInfo.mediaInfo.uFileID;
  v11 = *((_BYTE *)&m_pSource->m_sSrcTypeInfo.mediaInfo + 16);
  dwID_high = HIWORD(m_pSource->m_sSrcTypeInfo.dwID);
  v20[0] = 0;
  v20[1] = dwID_high;
  v20[2] = 0;
  v21 = 0i64;
  v22 = v11 & 1;
  v24 = uFileID;
  v23 = (v10 & 0x200) != 0;
  v13 = 1;
  if ( (*((_DWORD *)&m_pSource->m_sSrcTypeInfo.mediaInfo + 4) & 0x100) != 0 )
    v9 = 1;
  v20[0] = v9;
  vfptr = AK::IAkStreamMgr::m_pStreamMgr->vfptr;
  if ( (*((_DWORD *)&m_pSource->m_sSrcTypeInfo.mediaInfo + 4) & 0x400) != 0 )
    v15 = vfptr->CreateAuto(
            AK::IAkStreamMgr::m_pStreamMgr,
            m_pSource->m_sSrcTypeInfo.pszFilename,
            (AkFileSystemFlags *)v20,
            (AkAutoStmHeuristics *)&v16,
            in_bufSettings,
            &this->m_pStream,
            0);
  else
    v15 = vfptr->CreateAuto(
            AK::IAkStreamMgr::m_pStreamMgr,
            m_pSource->m_sSrcTypeInfo.mediaInfo.uFileID,
            (AkFileSystemFlags *)v20,
            (AkAutoStmHeuristics *)&v16,
            in_bufSettings,
            &this->m_pStream,
            0);
  if ( v15 != 1 )
    return v15;
  return v13;
}

// File Line: 249
// RVA: 0xA9FAE0
unsigned int __fastcall CAkSrcFileBase::HandlePrefetch(CAkSrcFileBase *this, bool *out_bUsePrefetchedData)
{
  CAkPBI *m_pCtx; // rcx
  char *m_pDataPtr; // rdi
  unsigned int m_uDataSize; // eax
  bool v6; // al
  unsigned int result; // eax
  __int64 m_uDataOffset; // rdx

  *out_bUsePrefetchedData = 0;
  m_pCtx = this->m_pCtx;
  if ( (*((_DWORD *)&m_pCtx->m_pSource->m_sSrcTypeInfo.mediaInfo + 4) & 2) == 0 || (*((_BYTE *)m_pCtx + 375) & 2) != 0 )
    return 1;
  m_pDataPtr = m_pCtx->m_pDataPtr;
  m_uDataSize = m_pCtx->m_uDataSize;
  this->m_ulSizeLeft = m_uDataSize;
  v6 = m_pDataPtr && m_uDataSize;
  *out_bUsePrefetchedData = v6;
  *((_BYTE *)this + 126) &= ~2u;
  *((_BYTE *)this + 126) |= 2 * v6;
  if ( !*out_bUsePrefetchedData )
    return 1;
  *((_BYTE *)this + 126) |= 0x20u;
  result = ((__int64 (__fastcall *)(CAkSrcFileBase *, char *))this->vfptr[2].VirtualOff)(this, m_pDataPtr);
  if ( result == 1 )
  {
    result = CAkSrcFileBase::ProcessStreamBuffer(this, m_pDataPtr, 1);
    if ( result == 1 )
    {
      if ( this->m_uStreamLoopCntAhead
        || (result = CAkSrcFileBase::SetStreamPosition(this, this->m_ulSizeLeft), result == 1) )
      {
        m_uDataOffset = this->m_uDataOffset;
        this->m_pNextAddress += m_uDataOffset;
        this->m_ulSizeLeft -= m_uDataOffset;
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
  AK::IAkAutoStream *m_pStream; // rcx

  m_pStream = this->m_pStream;
  if ( m_pStream )
  {
    (*(void (__fastcall **)(AK::IAkAutoStream *))m_pStream->vfptr->gap8)(m_pStream);
    this->m_pStream = 0i64;
  }
  CAkSrcBaseEx::StopStream(this);
}

// File Line: 307
// RVA: 0xAA0110
__int64 __fastcall CAkSrcFileBase::StopLooping(CAkSrcFileBase *this)
{
  AK::IAkAutoStream *m_pStream; // rcx
  AK::IAkAutoStream *v3; // rcx
  char v5; // [rsp+20h] [rbp-18h] BYREF
  int v6; // [rsp+28h] [rbp-10h]

  this->m_uLoopCnt = this->m_uStreamLoopCntAhead + 1;
  m_pStream = this->m_pStream;
  if ( m_pStream )
  {
    m_pStream->vfptr->GetHeuristics(m_pStream, (AkAutoStmHeuristics *)&v5);
    v3 = this->m_pStream;
    v6 = 0;
    v3->vfptr->SetHeuristics(v3, (AkAutoStmHeuristics *)&v5);
  }
  return 1i64;
}

// File Line: 326
// RVA: 0xA9FA20
AKRESULT __fastcall CAkSrcFileBase::FetchStreamBuffer(CAkSrcFileBase *this)
{
  AK::IAkAutoStream *m_pStream; // rcx
  AKRESULT result; // eax
  char v4[24]; // [rsp+20h] [rbp-18h] BYREF
  char *in_pBuffer; // [rsp+40h] [rbp+8h] BYREF

  this->m_pNextAddress = 0i64;
  this->m_pStream->vfptr->GetHeuristics(this->m_pStream, (AkAutoStmHeuristics *)v4);
  m_pStream = this->m_pStream;
  v4[13] = (int)this->m_pCtx->m_PriorityInfoCurrent.currentPriority.priority;
  m_pStream->vfptr->SetHeuristics(m_pStream, (AkAutoStmHeuristics *)v4);
  result = this->m_pStream->vfptr->GetBuffer(this->m_pStream, (void **)&in_pBuffer, &this->m_ulSizeLeft, 0);
  if ( result == AK_DataReady || result == AK_NoMoreData )
  {
    if ( this->m_ulSizeLeft )
    {
      result = CAkSrcFileBase::ProcessStreamBuffer(this, in_pBuffer, 0);
      if ( result == AK_Success )
        return 45;
    }
    else
    {
      return 2;
    }
  }
  return result;
}

// File Line: 373
// RVA: 0xA9FD00
__int64 __fastcall CAkSrcFileBase::ProcessStreamBuffer(
        CAkSrcFileBase *this,
        char *in_pBuffer,
        bool in_bIsReadingPrefecth)
{
  unsigned int m_ulSizeLeft; // r10d
  __int64 m_uiCorrection; // r9
  char *v5; // rax
  unsigned int v6; // r10d
  unsigned __int16 m_uLoopCnt; // r8
  char v9; // dl
  unsigned int m_ulLoopEnd; // eax
  unsigned int m_ulFileOffset; // ecx
  __int64 result; // rax
  unsigned int m_ulLoopStart; // edi
  unsigned int v14; // eax
  unsigned __int16 v15; // cx
  AK::IAkAutoStream *m_pStream; // rcx
  char v17; // [rsp+20h] [rbp-18h] BYREF
  int v18; // [rsp+28h] [rbp-10h]
  __int64 v19; // [rsp+40h] [rbp+8h] BYREF

  m_ulSizeLeft = this->m_ulSizeLeft;
  *((_BYTE *)this + 126) &= ~8u;
  m_uiCorrection = this->m_uiCorrection;
  this->m_ulFileOffset += m_ulSizeLeft;
  v5 = &in_pBuffer[m_uiCorrection];
  v6 = m_ulSizeLeft - m_uiCorrection;
  *((_BYTE *)this + 126) |= 8 * in_bIsReadingPrefecth;
  m_uLoopCnt = this->m_uLoopCnt;
  v9 = *((_BYTE *)this + 126);
  this->m_pNextAddress = v5;
  this->m_ulSizeLeft = v6;
  if ( m_uLoopCnt && m_uLoopCnt - this->m_uStreamLoopCntAhead == 1 )
    m_ulLoopEnd = this->m_uDataSize + this->m_uDataOffset;
  else
    m_ulLoopEnd = this->m_ulLoopEnd;
  m_ulFileOffset = this->m_ulFileOffset;
  if ( m_ulFileOffset < m_ulLoopEnd )
  {
    this->m_uiCorrection = 0;
  }
  else
  {
    this->m_ulSizeLeft = m_ulLoopEnd + v6 - m_ulFileOffset;
    if ( m_uLoopCnt && m_uLoopCnt - this->m_uStreamLoopCntAhead == 1 )
    {
      result = 1i64;
      *((_BYTE *)this + 126) = v9 | 1;
      return result;
    }
    m_ulLoopStart = this->m_ulLoopStart;
    if ( this->m_pStream->vfptr->SetPosition(this->m_pStream, m_ulLoopStart, AK_MoveBegin, &v19) != AK_Success )
      return 2i64;
    v14 = v19;
    v15 = this->m_uLoopCnt;
    ++this->m_uStreamLoopCntAhead;
    this->m_ulFileOffset = v14;
    this->m_uiCorrection = m_ulLoopStart - v14;
    if ( v15 && v15 - this->m_uStreamLoopCntAhead == 1 )
    {
      this->m_pStream->vfptr->GetHeuristics(this->m_pStream, (AkAutoStmHeuristics *)&v17);
      m_pStream = this->m_pStream;
      v18 = 0;
      m_pStream->vfptr->SetHeuristics(m_pStream, (AkAutoStmHeuristics *)&v17);
      return 1i64;
    }
  }
  return 1i64;
}

// File Line: 439
// RVA: 0xA9FBD0
__int64 __fastcall CAkSrcFileBase::ProcessFirstBuffer(CAkSrcFileBase *this)
{
  AKRESULT v2; // eax
  __int64 result; // rax
  AKRESULT v4; // ebp
  char v5; // cl
  int v6; // ebx
  AKRESULT v7; // eax
  unsigned int v8; // ecx
  char *in_pBuffer; // [rsp+30h] [rbp+8h] BYREF

  *((_BYTE *)&this->CAkVPLSrcNode + 32) ^= (*((_BYTE *)&this->CAkVPLSrcNode + 32) ^ (*((_BYTE *)this->m_pCtx + 374) >> 4)) & 2;
  v2 = this->m_pStream->vfptr->GetBuffer(this->m_pStream, (void **)&in_pBuffer, &this->m_ulSizeLeft, 0);
  if ( v2 == AK_NoDataReady )
    return 63i64;
  if ( v2 != AK_DataReady && v2 != AK_NoMoreData )
    return 2i64;
  result = ((__int64 (__fastcall *)(CAkSrcFileBase *, char *))this->vfptr[2].VirtualOff)(this, in_pBuffer);
  if ( (_DWORD)result == 1 )
  {
    if ( (*((_BYTE *)this->m_pCtx + 375) & 2) != 0 )
    {
      v4 = CAkSrcFileBase::SeekToSourceOffset(this);
      if ( this->m_ulSizeLeft )
      {
        v5 = *((_BYTE *)this + 126);
        if ( (v5 & 2) != 0 )
        {
          this->m_ulSizeLeft = 0;
          *((_BYTE *)this + 126) = v5 & 0xFD;
        }
        else
        {
          this->m_pStream->vfptr->ReleaseBuffer(this->m_pStream);
          this->m_ulSizeLeft = 0;
        }
      }
    }
    else
    {
      v6 = this->m_uiCorrection + (__int64)this->m_pStream->vfptr->GetPosition(this->m_pStream, 0i64);
      v7 = CAkSrcFileBase::ProcessStreamBuffer(this, in_pBuffer, 0);
      v8 = this->m_uDataOffset - v6;
      v4 = v7;
      this->m_pNextAddress += v8;
      this->m_ulSizeLeft -= v8;
    }
    *((_BYTE *)this + 126) |= 4u;
    return (unsigned int)v4;
  }
  return result;
}

// File Line: 503
// RVA: 0xAA02C0
void __fastcall CAkSrcFileBase::VirtualOn(CAkSrcFileBase *this, unsigned int eBehavior)
{
  char v4; // al

  this->m_pStream->vfptr->Stop(this->m_pStream);
  if ( eBehavior <= 1 && this->m_ulSizeLeft )
  {
    v4 = *((_BYTE *)this + 126);
    if ( (v4 & 2) != 0 )
      *((_BYTE *)this + 126) = v4 & 0xFD;
    else
      this->m_pStream->vfptr->ReleaseBuffer(this->m_pStream);
    this->m_pNextAddress = 0i64;
    this->m_ulSizeLeft = 0;
  }
}

// File Line: 527
// RVA: 0xAA0210
__int64 __fastcall CAkSrcFileBase::VirtualOff(CAkSrcFileBase *this, __int64 eBehavior, bool in_bUseSourceOffset)
{
  __int64 result; // rax
  CAkPBI *m_pCtx; // rax

  if ( (_DWORD)eBehavior == 1 )
  {
    if ( in_bUseSourceOffset )
    {
      result = CAkSrcFileBase::SeekToSourceOffset(this);
    }
    else
    {
      if ( (unsigned int)CAkSrcFileBase::SeekStream(this, this->m_uCurSample, &this->m_uCurSample) == 1 )
        return ((__int64 (__fastcall *)(AK::IAkAutoStream *))this->m_pStream->vfptr->Start)(this->m_pStream);
      result = CAkSrcFileBase::SeekStream(this, 0i64, &this->m_uCurSample);
    }
    if ( (_DWORD)result != 1 )
      return result;
    return ((__int64 (__fastcall *)(AK::IAkAutoStream *))this->m_pStream->vfptr->Start)(this->m_pStream);
  }
  if ( (_DWORD)eBehavior )
  {
    if ( (_DWORD)eBehavior == 2 )
      *((_BYTE *)&this->CAkVPLSrcNode + 32) ^= (*((_BYTE *)&this->CAkVPLSrcNode + 32) ^ (*((_BYTE *)this->m_pCtx + 374) >> 4)) & 2;
    return ((__int64 (__fastcall *)(_QWORD))this->m_pStream->vfptr->Start)(this->m_pStream);
  }
  m_pCtx = this->m_pCtx;
  this->m_uCurSample = 0;
  this->m_uLoopCnt = m_pCtx->m_LoopCount;
  result = CAkSrcFileBase::SeekStream(this, eBehavior, &this->m_uCurSample);
  if ( (_DWORD)result == 1 )
    return ((__int64 (__fastcall *)(_QWORD))this->m_pStream->vfptr->Start)(this->m_pStream);
  return result;
}

// File Line: 575
// RVA: 0xA9FF80
__int64 __fastcall CAkSrcFileBase::SeekToSourceOffset(CAkSrcFileBase *this)
{
  unsigned int SourceOffset; // ebx
  CAkPBI *m_pCtx; // rax
  unsigned int v5; // ebx

  SourceOffset = CAkSrcBaseEx::GetSourceOffset(this);
  if ( (unsigned int)CAkSrcFileBase::SeekStream(this, SourceOffset, &this->m_uCurSample) != 1 )
    return 2i64;
  m_pCtx = this->m_pCtx;
  v5 = SourceOffset - this->m_uCurSample;
  *((_BYTE *)m_pCtx + 375) &= 0xF1u;
  m_pCtx->m_uSeekPosition = v5;
  return 1i64;
}

// File Line: 599
// RVA: 0xA9FEF0
__int64 __fastcall CAkSrcFileBase::SeekStream(
        CAkSrcFileBase *this,
        __int64 in_uDesiredSample,
        unsigned int *out_uSeekedSample)
{
  AK::IAkAutoStream *m_pStream; // rcx
  unsigned int v6; // edi
  unsigned int v7; // edi
  __int64 v8; // [rsp+30h] [rbp+8h] BYREF
  unsigned int v9; // [rsp+38h] [rbp+10h] BYREF

  if ( (unsigned int)in_uDesiredSample >= this->m_uTotalSamples
    || ((unsigned int (__fastcall *)(CAkSrcFileBase *, __int64, unsigned int *, unsigned int *))this->vfptr[2].GetPitch)(
         this,
         in_uDesiredSample,
         out_uSeekedSample,
         &v9) != 1 )
  {
    return 2i64;
  }
  m_pStream = this->m_pStream;
  v6 = v9;
  this->m_uStreamLoopCntAhead = 0;
  if ( m_pStream->vfptr->SetPosition(m_pStream, v6, AK_MoveBegin, &v8) != AK_Success )
    return 2i64;
  v7 = v6 - v8;
  this->m_ulFileOffset = v8;
  this->m_uiCorrection = v7;
  CAkSrcFileBase::ResetStreamingAfterSeek(this);
  return 1i64;
}

// File Line: 645
// RVA: 0xA9FFF0
__int64 __fastcall CAkSrcFileBase::SetStreamPosition(CAkSrcFileBase *this, unsigned int in_uPosition)
{
  __int64 result; // rax
  unsigned int v5; // ebx
  __int64 v6; // [rsp+30h] [rbp+8h] BYREF

  if ( this->m_pStream->vfptr->SetPosition(this->m_pStream, in_uPosition, AK_MoveBegin, &v6) != AK_Success )
    return 2i64;
  v5 = in_uPosition - v6;
  this->m_ulFileOffset = v6;
  result = 1i64;
  this->m_uiCorrection = v5;
  return result;
}

// File Line: 665
// RVA: 0xA9FE80
void __fastcall CAkSrcFileBase::ResetStreamingAfterSeek(CAkSrcFileBase *this)
{
  char v2[4]; // [rsp+20h] [rbp-18h] BYREF
  __int64 v3; // [rsp+24h] [rbp-14h]

  this->m_pStream->vfptr->GetHeuristics(this->m_pStream, (AkAutoStmHeuristics *)v2);
  if ( this->m_uLoopCnt == 1 )
    v3 = 0i64;
  else
    v3 = *(_QWORD *)&this->m_ulLoopStart;
  this->m_pStream->vfptr->SetHeuristics(this->m_pStream, (AkAutoStmHeuristics *)v2);
  *((_BYTE *)this + 126) &= ~1u;
  *((_BYTE *)&this->CAkVPLSrcNode + 32) ^= (*((_BYTE *)&this->CAkVPLSrcNode + 32) ^ (*((_BYTE *)this->m_pCtx + 374) >> 4)) & 2;
}

// File Line: 682
// RVA: 0xA9F890
__int64 __fastcall CAkSrcFileBase::ChangeSourcePosition(CAkSrcFileBase *this)
{
  char v2; // al

  if ( CAkSrcFileBase::SeekToSourceOffset(this) != AK_Success )
    return 2i64;
  v2 = *((_BYTE *)this + 126);
  if ( (v2 & 2) != 0 )
    *((_BYTE *)this + 126) = v2 & 0xFD;
  else
    this->m_pStream->vfptr->ReleaseBuffer(this->m_pStream);
  this->m_ulSizeLeft = 0;
  this->m_pNextAddress = 0i64;
  return 1i64;
}

// File Line: 697
// RVA: 0xA9FAC0
void __fastcall CAkSrcFileBase::GetStreamLoopHeuristic(
        CAkSrcFileBase *this,
        bool in_bIsLooping,
        AkAutoStmHeuristics *io_heuristics)
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
__int64 __fastcall CAkSrcFileBase::StoreAnalysisData(
        CAkSrcFileBase *this,
        AkFileParser::AnalysisDataChunk *in_analysisDataChunk)
{
  AkFileParser::AnalysisData *v4; // rax

  if ( (*((_BYTE *)this + 126) & 0x20) != 0 )
  {
    this->m_pAnalysisData = in_analysisDataChunk->pData;
    return 1i64;
  }
  else
  {
    v4 = (AkFileParser::AnalysisData *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, in_analysisDataChunk->uDataSize);
    this->m_pAnalysisData = v4;
    if ( v4 )
    {
      memmove(v4, in_analysisDataChunk->pData, in_analysisDataChunk->uDataSize);
      *((_BYTE *)this + 126) |= 0x10u;
      return 1i64;
    }
    else
    {
      return 52i64;
    }
  }
}

