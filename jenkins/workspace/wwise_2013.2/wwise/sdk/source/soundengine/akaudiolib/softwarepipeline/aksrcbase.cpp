// File Line: 32
// RVA: 0xA9F060
void __fastcall CAkSrcBaseEx::CAkSrcBaseEx(CAkSrcBaseEx *this, CAkPBI *in_pCtx)
{
  CAkPBI *m_pCtx; // rax

  CAkVPLSrcNode::CAkVPLSrcNode(this, in_pCtx);
  *(_QWORD *)&this->m_uTotalSamples = 0i64;
  *(_QWORD *)&this->m_uDataSize = 0i64;
  *(_QWORD *)&this->m_uPCMLoopStart = 0i64;
  this->vfptr = (CAkVPLNodeVtbl *)&CAkSrcBaseEx::`vftable;
  CAkMarkers::CAkMarkers(&this->m_markers);
  m_pCtx = this->m_pCtx;
  this->m_uLastEnvelopePtIdx = 0;
  this->m_uLoopCnt = m_pCtx->m_LoopCount;
}

// File Line: 37
// RVA: 0xA9F0C0
void __fastcall CAkSrcBaseEx::~CAkSrcBaseEx(CAkSrcBaseEx *this)
{
  AMD_HD3D *p_m_markers; // rcx

  p_m_markers = (AMD_HD3D *)&this->m_markers;
  *(_QWORD *)&p_m_markers[-2].mEnableStereo = &CAkSrcBaseEx::`vftable;
  _(p_m_markers);
  this->vfptr = (CAkVPLNodeVtbl *)&CAkVPLNode::`vftable;
}

// File Line: 41
// RVA: 0xA9F590
void __fastcall CAkSrcBaseEx::StopStream(CAkSrcBaseEx *this)
{
  CAkMarkers::Free(&this->m_markers);
}

// File Line: 46
// RVA: 0xA9F580
__int64 __fastcall CAkSrcBaseEx::StopLooping(CAkSrcBaseEx *this)
{
  __int64 result; // rax

  result = 1i64;
  this->m_uLoopCnt = 1;
  return result;
}

// File Line: 52
// RVA: 0xA9F670
__int64 __fastcall CAkSrcBaseEx::TimeSkip(CAkSrcBaseEx *this, unsigned int *io_uFrames)
{
  unsigned int m_uCurSample; // r11d
  unsigned int v4; // r8d
  unsigned __int16 m_uLoopCnt; // ax
  unsigned int v6; // ebx
  unsigned int m_uTotalSamples; // eax
  unsigned int m_uPCMLoopEnd; // ecx

  m_uCurSample = this->m_uCurSample;
  v4 = *io_uFrames + m_uCurSample;
  m_uLoopCnt = this->m_uLoopCnt;
  v6 = 45;
  this->m_uCurSample = v4;
  if ( m_uLoopCnt == 1 )
  {
    m_uTotalSamples = this->m_uTotalSamples;
    if ( v4 >= m_uTotalSamples )
    {
      v6 = 17;
      *io_uFrames = m_uTotalSamples - m_uCurSample;
    }
  }
  else
  {
    m_uPCMLoopEnd = this->m_uPCMLoopEnd;
    if ( v4 > m_uPCMLoopEnd )
    {
      if ( m_uLoopCnt )
        this->m_uLoopCnt = m_uLoopCnt - 1;
      *io_uFrames = m_uPCMLoopEnd - m_uCurSample + 1;
      this->m_uCurSample = this->m_uPCMLoopStart;
    }
  }
  CAkSrcBaseEx::TimeSkipMarkersAndPosition(this, m_uCurSample, *io_uFrames, this->m_uTotalSamples);
  return v6;
}

// File Line: 101
// RVA: 0xA9F500
__int64 __fastcall CAkSrcBaseEx::Seek(CAkSrcBaseEx *this)
{
  unsigned int v2; // eax
  CAkPBI *m_pCtx; // rdx
  unsigned int v4; // edi
  unsigned int m_uCurSample; // ecx
  AkBufferPosInformation in_pPosInfo; // [rsp+20h] [rbp-18h] BYREF

  if ( (*((_BYTE *)this->m_pCtx + 375) & 2) == 0 )
    return 1i64;
  v2 = CAkVPLSrcNode::Seek(this);
  m_pCtx = this->m_pCtx;
  v4 = v2;
  if ( (m_pCtx->m_uRegisteredNotif & 0x10000) != 0 )
  {
    in_pPosInfo.uSampleRate = m_pCtx->m_sMediaFormat.uSampleRate;
    m_uCurSample = this->m_uCurSample;
    in_pPosInfo.fLastRate = 0.0;
    in_pPosInfo.uStartPos = m_uCurSample;
    in_pPosInfo.uFileEnd = this->m_uTotalSamples;
    CAkPositionRepository::UpdatePositionInfo(
      g_pPositionRepository,
      m_pCtx->m_UserParams.m_PlayingID,
      &in_pPosInfo,
      this);
  }
  return v4;
}

// File Line: 151
// RVA: 0xA9F280
float __fastcall CAkSrcBaseEx::GetDuration(CAkSrcBaseEx *this)
{
  CAkPBI *m_pCtx; // rdx
  float result; // xmm0_4
  unsigned __int16 m_LoopCount; // r8

  m_pCtx = this->m_pCtx;
  result = 0.0;
  m_LoopCount = m_pCtx->m_LoopCount;
  if ( m_LoopCount )
    return (float)((float)((float)((float)(this->m_uPCMLoopEnd - this->m_uPCMLoopStart + 1) * (float)(m_LoopCount - 1))
                         + (float)(int)this->m_uTotalSamples)
                 * 1000.0)
         / (float)(int)m_pCtx->m_sMediaFormat.uSampleRate;
  return result;
}

// File Line: 170
// RVA: 0xA9F140
float __fastcall CAkSrcBaseEx::GetAnalyzedEnvelope(CAkSrcBaseEx *this, unsigned int in_uBufferedFrames)
{
  AkFileParser::AnalysisData *m_pAnalysisData; // rsi
  unsigned int uNumEnvelopePoints; // ebx
  __int64 m_uLastEnvelopePtIdx; // r10
  unsigned int m_uCurSample; // r9d
  unsigned int v8; // edx
  __int64 v9; // rax
  unsigned int uPosition; // r11d
  unsigned __int16 v11; // di
  AkFileParser::EnvelopePoint *arEnvelope; // rax
  unsigned int v13; // r9d
  AkFileParser::EnvelopePoint *v14; // rcx
  unsigned int v15; // r8d
  float uAttenuation; // xmm0_4

  m_pAnalysisData = this->m_pAnalysisData;
  if ( !m_pAnalysisData )
    return 0.0;
  uNumEnvelopePoints = m_pAnalysisData->uNumEnvelopePoints;
  if ( !uNumEnvelopePoints )
    return 0.0;
  m_uLastEnvelopePtIdx = this->m_uLastEnvelopePtIdx;
  m_uCurSample = this->m_uCurSample;
  v8 = m_uLastEnvelopePtIdx + 1;
  v9 = m_uLastEnvelopePtIdx + 2 * (m_uLastEnvelopePtIdx + 4);
  uPosition = *(_DWORD *)((char *)&m_pAnalysisData->fLoudnessNormalizationGain + 2 * v9);
  v11 = *((_WORD *)&m_pAnalysisData->fDownmixNormalizationGain + v9);
  arEnvelope = (AkFileParser::EnvelopePoint *)((char *)m_pAnalysisData + 2 * v9);
  if ( in_uBufferedFrames > m_uCurSample )
    v13 = 0;
  else
    v13 = m_uCurSample - in_uBufferedFrames;
  while ( v8 >= uNumEnvelopePoints )
  {
LABEL_11:
    if ( v13 >= arEnvelope->uPosition )
    {
      this->m_uLastEnvelopePtIdx = m_uLastEnvelopePtIdx;
      uAttenuation = (float)arEnvelope->uAttenuation;
      return COERCE_FLOAT(LODWORD(uAttenuation) ^ _xmm[0]) - m_pAnalysisData->fEnvelopePeak;
    }
    uPosition = m_pAnalysisData->arEnvelope[0].uPosition;
    v11 = m_pAnalysisData->arEnvelope[0].uAttenuation;
    arEnvelope = m_pAnalysisData->arEnvelope;
    LODWORD(m_uLastEnvelopePtIdx) = 0;
    v8 = 1;
  }
  v14 = &m_pAnalysisData->arEnvelope[v8];
  while ( 1 )
  {
    v15 = v14->uPosition;
    arEnvelope = v14;
    if ( v13 >= uPosition && v13 < v15 )
      break;
    v11 = v14->uAttenuation;
    ++v8;
    LODWORD(m_uLastEnvelopePtIdx) = m_uLastEnvelopePtIdx + 1;
    ++v14;
    uPosition = v15;
    if ( v8 >= uNumEnvelopePoints )
      goto LABEL_11;
  }
  this->m_uLastEnvelopePtIdx = m_uLastEnvelopePtIdx;
  uAttenuation = (float)((float)((float)((float)v14->uAttenuation - (float)v11) * (float)(int)(v13 - uPosition))
                       / (float)(int)(v15 - uPosition))
               + (float)v11;
  return COERCE_FLOAT(LODWORD(uAttenuation) ^ _xmm[0]) - m_pAnalysisData->fEnvelopePeak;
}

// File Line: 248
// RVA: 0xA9F5A0
void __fastcall CAkSrcBaseEx::SubmitBufferAndUpdate(
        CAkSrcBaseEx *this,
        void *in_pData,
        unsigned __int16 in_uNumSamplesProduced,
        unsigned int in_uSampleRate,
        unsigned int in_channelMask,
        AkVPLState *io_state)
{
  __int64 v9; // rdx
  unsigned int m_uCurSample; // ecx
  AKRESULT v11; // eax

  if ( !in_uNumSamplesProduced )
  {
    io_state->uValidFrames = 0;
    io_state->result = AK_NoDataReady;
    return;
  }
  io_state->pData = in_pData;
  io_state->uMaxFrames = in_uNumSamplesProduced;
  io_state->uValidFrames = in_uNumSamplesProduced;
  io_state->uChannelMask = in_channelMask;
  CAkMarkers::CopyRelevantMarkers(&this->m_markers, this->m_pCtx, io_state, this->m_uCurSample);
  io_state->posInfo.uSampleRate = in_uSampleRate;
  io_state->posInfo.uStartPos = this->m_uCurSample;
  io_state->posInfo.uFileEnd = this->m_uTotalSamples;
  this->m_uCurSample += in_uNumSamplesProduced;
  m_uCurSample = this->m_uCurSample;
  v11 = AK_DataReady;
  if ( this->m_uLoopCnt == 1 )
  {
    if ( m_uCurSample >= this->m_uTotalSamples )
    {
      LOBYTE(v9) = 1;
LABEL_8:
      v11 = ((unsigned int (__fastcall *)(CAkSrcBaseEx *, __int64))this->vfptr[2].VirtualOn)(this, v9);
    }
  }
  else if ( m_uCurSample > this->m_uPCMLoopEnd )
  {
    v9 = 0i64;
    this->m_uCurSample = this->m_uPCMLoopStart;
    goto LABEL_8;
  }
  io_state->result = v11;
}

// File Line: 339
// RVA: 0xA9F6F0
void __fastcall CAkSrcBaseEx::TimeSkipMarkersAndPosition(
        CAkSrcBaseEx *this,
        unsigned int in_ulCurrSampleOffset,
        unsigned int in_uSkippedSamples,
        unsigned int in_uFileEnd)
{
  CAkPBI *m_pCtx; // rdx
  unsigned int uSampleRate; // eax
  AkBufferPosInformation in_pPosInfo; // [rsp+20h] [rbp-18h] BYREF

  CAkMarkers::NotifyRelevantMarkers(
    &this->m_markers,
    this->m_pCtx,
    in_ulCurrSampleOffset,
    in_ulCurrSampleOffset + in_uSkippedSamples);
  m_pCtx = this->m_pCtx;
  if ( (m_pCtx->m_uRegisteredNotif & 0x10000) != 0 )
  {
    uSampleRate = m_pCtx->m_sMediaFormat.uSampleRate;
    in_pPosInfo.uStartPos = in_ulCurrSampleOffset;
    in_pPosInfo.uFileEnd = in_uFileEnd;
    in_pPosInfo.uSampleRate = uSampleRate;
    LODWORD(in_pPosInfo.fLastRate) = (_DWORD)FLOAT_1_0;
    CAkPositionRepository::UpdatePositionInfo(
      g_pPositionRepository,
      m_pCtx->m_UserParams.m_PlayingID,
      &in_pPosInfo,
      this);
  }
}

// File Line: 348
// RVA: 0xA9F2E0
__int64 __fastcall CAkSrcBaseEx::GetSourceOffset(CAkSrcBaseEx *this)
{
  CAkPBI *m_pCtx; // r9
  double v3; // xmm0_8
  float v4; // xmm1_4
  bool v5; // r10
  unsigned int v6; // edi
  unsigned __int64 v7; // rcx
  unsigned __int16 m_LoopCount; // r11
  unsigned int m_uPCMLoopEnd; // r8d
  unsigned int m_uPCMLoopStart; // r9d
  unsigned __int16 v11; // si
  unsigned int v12; // r8d
  unsigned int v13; // eax
  unsigned __int16 v14; // cx
  AkAudioMarker *ClosestMarker; // rax
  unsigned __int16 m_uLoopCnt; // r9
  unsigned int v17; // r8d
  unsigned int v18; // r10d
  unsigned int dwPosition; // ecx
  unsigned int v20; // r8d
  unsigned int v21; // eax

  m_pCtx = this->m_pCtx;
  if ( (*((_BYTE *)m_pCtx + 375) & 4) != 0 )
  {
    if ( m_pCtx->m_LoopCount )
    {
      v3 = ((double (__fastcall *)(CAkSrcBaseEx *))this->vfptr[1].TimeSkip)(this);
      v4 = *(float *)&v3;
    }
    else
    {
      v4 = (float)((float)(int)this->m_uTotalSamples * 1000.0) / (float)(int)m_pCtx->m_sMediaFormat.uSampleRate;
    }
    m_pCtx = this->m_pCtx;
    v5 = (*((_BYTE *)m_pCtx + 375) & 8) != 0;
    v6 = (int)(float)((float)((float)(v4 * m_pCtx->m_fSeekPercent) * (float)(int)m_pCtx->m_sMediaFormat.uSampleRate)
                    * 0.001);
  }
  else
  {
    v5 = (*((_BYTE *)m_pCtx + 375) & 8) != 0;
    if ( *((char *)m_pCtx + 374) >= 0 )
      v7 = AkAudioLibSettings::g_pipelineCoreFrequency;
    else
      v7 = (unsigned __int16)(int)(float)((float)((float)(int)AkAudioLibSettings::g_pipelineCoreFrequency * 0.0009765625)
                                        * 8.0);
    v6 = m_pCtx->m_uSeekPosition * (unsigned __int64)m_pCtx->m_sMediaFormat.uSampleRate / v7;
  }
  m_LoopCount = m_pCtx->m_LoopCount;
  m_uPCMLoopEnd = this->m_uPCMLoopEnd;
  m_uPCMLoopStart = this->m_uPCMLoopStart;
  v11 = 0;
  this->m_uLoopCnt = m_LoopCount;
  if ( m_LoopCount != 1 && v6 > m_uPCMLoopEnd && m_uPCMLoopEnd > m_uPCMLoopStart )
  {
    v12 = m_uPCMLoopEnd - m_uPCMLoopStart + 1;
    v13 = (v6 - m_uPCMLoopStart) / v12;
    if ( v13 < m_LoopCount )
    {
      if ( m_LoopCount )
      {
        v14 = m_LoopCount - v13;
        goto LABEL_19;
      }
    }
    else if ( m_LoopCount )
    {
      this->m_uLoopCnt = 1;
      v6 -= v12 * (m_LoopCount - 1);
      goto LABEL_20;
    }
    v14 = 0;
LABEL_19:
    this->m_uLoopCnt = v14;
    v6 = (v6 - m_uPCMLoopStart) % v12 + m_uPCMLoopStart;
  }
LABEL_20:
  if ( !v5 )
    return v6;
  ClosestMarker = CAkMarkers::GetClosestMarker(&this->m_markers, v6);
  if ( !ClosestMarker )
    return v6;
  m_uLoopCnt = this->m_uLoopCnt;
  v17 = this->m_uPCMLoopEnd;
  v18 = this->m_uPCMLoopStart;
  dwPosition = ClosestMarker->dwPosition;
  this->m_uLoopCnt = m_uLoopCnt;
  if ( m_uLoopCnt == 1 || dwPosition <= v17 || v17 <= v18 )
    return dwPosition;
  v20 = v17 - v18 + 1;
  v21 = (dwPosition - v18) / v20;
  if ( v21 < m_uLoopCnt )
  {
    if ( m_uLoopCnt )
      v11 = m_uLoopCnt - v21;
  }
  else if ( m_uLoopCnt )
  {
    this->m_uLoopCnt = 1;
    dwPosition -= v20 * (m_uLoopCnt - 1);
    return dwPosition;
  }
  this->m_uLoopCnt = v11;
  return (dwPosition - v18) % v20 + v18;
}

