// File Line: 32
// RVA: 0xA9F060
void __fastcall CAkSrcBaseEx::CAkSrcBaseEx(CAkSrcBaseEx *this, CAkPBI *in_pCtx)
{
  CAkSrcBaseEx *v2; // rbx
  CAkPBI *v3; // rax

  v2 = this;
  CAkVPLSrcNode::CAkVPLSrcNode((CAkVPLSrcNode *)&this->vfptr, in_pCtx);
  *(_QWORD *)&v2->m_uTotalSamples = 0i64;
  *(_QWORD *)&v2->m_uDataSize = 0i64;
  *(_QWORD *)&v2->m_uPCMLoopStart = 0i64;
  v2->vfptr = (CAkVPLNodeVtbl *)&CAkSrcBaseEx::`vftable;
  CAkMarkers::CAkMarkers(&v2->m_markers);
  v3 = v2->m_pCtx;
  v2->m_uLastEnvelopePtIdx = 0;
  v2->m_uLoopCnt = v3->m_LoopCount;
}

// File Line: 37
// RVA: 0xA9F0C0
void __fastcall CAkSrcBaseEx::~CAkSrcBaseEx(CAkSrcBaseEx *this)
{
  CAkSrcBaseEx *v1; // rbx
  AMD_HD3D *v2; // rcx

  v1 = this;
  v2 = (AMD_HD3D *)&this->m_markers;
  *(_QWORD *)&v2[-2].mEnableStereo = &CAkSrcBaseEx::`vftable;
  _(v2);
  v1->vfptr = (CAkVPLNodeVtbl *)&CAkVPLNode::`vftable;
}

// File Line: 41
// RVA: 0xA9F590
void __fastcall CAkSrcBaseEx::StopStream(CAkSrcBaseEx *this)
{
  CAkMarkers::Free(&this->m_markers);
}

// File Line: 46
// RVA: 0xA9F580
signed __int64 __fastcall CAkSrcBaseEx::StopLooping(CAkSrcBaseEx *this)
{
  signed __int64 result; // rax

  result = 1i64;
  this->m_uLoopCnt = 1;
  return result;
}

// File Line: 52
// RVA: 0xA9F670
__int64 __fastcall CAkSrcBaseEx::TimeSkip(CAkSrcBaseEx *this, unsigned int *io_uFrames)
{
  unsigned int v2; // er11
  CAkSrcBaseEx *v3; // r10
  unsigned int v4; // er8
  unsigned __int16 v5; // ax
  unsigned int v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // ecx

  v2 = this->m_uCurSample;
  v3 = this;
  v4 = *io_uFrames + v2;
  v5 = this->m_uLoopCnt;
  v6 = 45;
  this->m_uCurSample = v4;
  if ( v5 == 1 )
  {
    v7 = this->m_uTotalSamples;
    if ( v4 >= v7 )
    {
      v6 = 17;
      *io_uFrames = v7 - v2;
    }
  }
  else
  {
    v8 = this->m_uPCMLoopEnd;
    if ( v4 > v8 )
    {
      if ( v5 )
        v3->m_uLoopCnt = v5 - 1;
      *io_uFrames = v8 - v2 + 1;
      v3->m_uCurSample = v3->m_uPCMLoopStart;
    }
  }
  CAkSrcBaseEx::TimeSkipMarkersAndPosition(v3, v2, *io_uFrames, v3->m_uTotalSamples);
  return v6;
}

// File Line: 101
// RVA: 0xA9F500
signed __int64 __fastcall CAkSrcBaseEx::Seek(CAkSrcBaseEx *this)
{
  CAkSrcBaseEx *v1; // rbx
  unsigned int v2; // eax
  CAkPBI *v3; // rdx
  unsigned int v4; // edi
  unsigned int v5; // ecx
  AkBufferPosInformation in_pPosInfo; // [rsp+20h] [rbp-18h]

  v1 = this;
  if ( !(*((_BYTE *)this->m_pCtx + 375) & 2) )
    return 1i64;
  v2 = CAkVPLSrcNode::Seek((CAkVPLSrcNode *)&this->vfptr);
  v3 = v1->m_pCtx;
  v4 = v2;
  if ( v3->m_uRegisteredNotif & 0x10000 )
  {
    in_pPosInfo.uSampleRate = v3->m_sMediaFormat.uSampleRate;
    v5 = v1->m_uCurSample;
    in_pPosInfo.fLastRate = 0.0;
    in_pPosInfo.uStartPos = v5;
    in_pPosInfo.uFileEnd = v1->m_uTotalSamples;
    CAkPositionRepository::UpdatePositionInfo(g_pPositionRepository, v3->m_UserParams.m_PlayingID, &in_pPosInfo, v1);
  }
  return v4;
}

// File Line: 151
// RVA: 0xA9F280
float __fastcall CAkSrcBaseEx::GetDuration(CAkSrcBaseEx *this)
{
  CAkPBI *v1; // rdx
  float result; // xmm0_4
  unsigned __int16 v3; // r8

  v1 = this->m_pCtx;
  result = 0.0;
  v3 = v1->m_LoopCount;
  if ( v3 )
    result = (float)((float)((float)((float)(this->m_uPCMLoopEnd - this->m_uPCMLoopStart + 1) * (float)(v3 - 1))
                           + (float)(signed int)this->m_uTotalSamples)
                   * 1000.0)
           / (float)(signed int)v1->m_sMediaFormat.uSampleRate;
  return result;
}

// File Line: 170
// RVA: 0xA9F140
float __fastcall CAkSrcBaseEx::GetAnalyzedEnvelope(CAkSrcBaseEx *this, unsigned int in_uBufferedFrames)
{
  AkFileParser::AnalysisData *v2; // rsi
  unsigned int v3; // er8
  CAkSrcBaseEx *v4; // rbp
  unsigned int v5; // ebx
  __int64 v6; // r10
  unsigned int v7; // er9
  unsigned int v8; // edx
  signed __int64 v9; // rax
  unsigned int v10; // er11
  unsigned __int16 v11; // di
  signed __int64 v12; // rax
  unsigned int v13; // er9
  signed __int64 v14; // rcx
  unsigned int v15; // er8
  float v16; // xmm0_4

  v2 = this->m_pAnalysisData;
  v3 = in_uBufferedFrames;
  v4 = this;
  if ( !v2 )
    return 0.0;
  v5 = v2->uNumEnvelopePoints;
  if ( !v5 )
    return 0.0;
  v6 = this->m_uLastEnvelopePtIdx;
  v7 = this->m_uCurSample;
  v8 = v6 + 1;
  v9 = v6 + 2 * (v6 + 4);
  v10 = *(_DWORD *)((char *)&v2->fLoudnessNormalizationGain + 2 * v9);
  v11 = *((_WORD *)&v2->fDownmixNormalizationGain + v9);
  v12 = (signed __int64)v2 + 2 * v9;
  if ( v3 > v7 )
    v13 = 0;
  else
    v13 = v7 - v3;
  while ( v8 >= v5 )
  {
LABEL_11:
    if ( v13 >= *(_DWORD *)v12 )
    {
      v4->m_uLastEnvelopePtIdx = v6;
      v16 = (float)*(unsigned __int16 *)(v12 + 4);
      return COERCE_FLOAT(LODWORD(v16) ^ _xmm[0]) - v2->fEnvelopePeak;
    }
    v10 = v2->arEnvelope[0].uPosition;
    v11 = v2->arEnvelope[0].uAttenuation;
    v12 = (signed __int64)v2->arEnvelope;
    LODWORD(v6) = 0;
    v8 = 1;
  }
  v14 = (signed __int64)v2 + 2 * (3i64 * v8 + 8);
  while ( 1 )
  {
    v15 = *(_DWORD *)v14;
    v12 = v14;
    if ( v13 >= v10 && v13 < v15 )
      break;
    v11 = *(_WORD *)(v14 + 4);
    ++v8;
    LODWORD(v6) = v6 + 1;
    v14 += 6i64;
    v10 = v15;
    if ( v8 >= v5 )
      goto LABEL_11;
  }
  v4->m_uLastEnvelopePtIdx = v6;
  v16 = (float)((float)((float)((float)*(unsigned __int16 *)(v14 + 4) - (float)v11) * (float)(signed int)(v13 - v10))
              / (float)(signed int)(v15 - v10))
      + (float)v11;
  return COERCE_FLOAT(LODWORD(v16) ^ _xmm[0]) - v2->fEnvelopePeak;
}

// File Line: 248
// RVA: 0xA9F5A0
void __fastcall CAkSrcBaseEx::SubmitBufferAndUpdate(CAkSrcBaseEx *this, void *in_pData, unsigned __int16 in_uNumSamplesProduced, unsigned int in_uSampleRate, unsigned int in_channelMask, AkVPLState *io_state)
{
  unsigned int v6; // ebp
  unsigned __int16 v7; // si
  CAkSrcBaseEx *v8; // rbx
  __int64 v9; // rdx
  unsigned int v10; // ecx
  AKRESULT v11; // eax

  v6 = in_uSampleRate;
  v7 = in_uNumSamplesProduced;
  v8 = this;
  if ( !in_uNumSamplesProduced )
  {
    io_state->uValidFrames = 0;
    io_state->result = 46;
    return;
  }
  io_state->pData = in_pData;
  io_state->uMaxFrames = in_uNumSamplesProduced;
  io_state->uValidFrames = in_uNumSamplesProduced;
  io_state->uChannelMask = in_channelMask;
  CAkMarkers::CopyRelevantMarkers(
    &this->m_markers,
    this->m_pCtx,
    (AkPipelineBuffer *)&io_state->pData,
    this->m_uCurSample);
  io_state->posInfo.uSampleRate = v6;
  io_state->posInfo.uStartPos = v8->m_uCurSample;
  io_state->posInfo.uFileEnd = v8->m_uTotalSamples;
  v8->m_uCurSample += v7;
  v10 = v8->m_uCurSample;
  v11 = 45;
  if ( v8->m_uLoopCnt == 1 )
  {
    if ( v10 >= v8->m_uTotalSamples )
    {
      LOBYTE(v9) = 1;
LABEL_8:
      v11 = ((unsigned int (__fastcall *)(CAkSrcBaseEx *, __int64))v8->vfptr[2].VirtualOn)(v8, v9);
      goto LABEL_9;
    }
  }
  else if ( v10 > v8->m_uPCMLoopEnd )
  {
    v9 = 0i64;
    v8->m_uCurSample = v8->m_uPCMLoopStart;
    goto LABEL_8;
  }
LABEL_9:
  io_state->result = v11;
}

// File Line: 339
// RVA: 0xA9F6F0
void __fastcall CAkSrcBaseEx::TimeSkipMarkersAndPosition(CAkSrcBaseEx *this, unsigned int in_ulCurrSampleOffset, unsigned int in_uSkippedSamples, unsigned int in_uFileEnd)
{
  CAkSrcBaseEx *v4; // rbx
  unsigned int v5; // esi
  unsigned int v6; // edi
  CAkPBI *v7; // rdx
  unsigned int v8; // eax
  AkBufferPosInformation in_pPosInfo; // [rsp+20h] [rbp-18h]

  v4 = this;
  v5 = in_uFileEnd;
  v6 = in_ulCurrSampleOffset;
  CAkMarkers::NotifyRelevantMarkers(
    &this->m_markers,
    this->m_pCtx,
    in_ulCurrSampleOffset,
    in_ulCurrSampleOffset + in_uSkippedSamples);
  v7 = v4->m_pCtx;
  if ( v7->m_uRegisteredNotif & 0x10000 )
  {
    v8 = v7->m_sMediaFormat.uSampleRate;
    in_pPosInfo.uStartPos = v6;
    in_pPosInfo.uFileEnd = v5;
    in_pPosInfo.uSampleRate = v8;
    LODWORD(in_pPosInfo.fLastRate) = (_DWORD)FLOAT_1_0;
    CAkPositionRepository::UpdatePositionInfo(g_pPositionRepository, v7->m_UserParams.m_PlayingID, &in_pPosInfo, v4);
  }
}

// File Line: 348
// RVA: 0xA9F2E0
__int64 __usercall CAkSrcBaseEx::GetSourceOffset@<rax>(CAkSrcBaseEx *this@<rcx>, float a2@<xmm0>)
{
  CAkPBI *v2; // r9
  CAkSrcBaseEx *v3; // rbx
  float v4; // xmm1_4
  char v5; // r10
  unsigned int v6; // edi
  unsigned __int64 v7; // rcx
  unsigned __int16 v8; // r11
  unsigned int v9; // er8
  unsigned int v10; // er9
  unsigned __int16 v11; // si
  unsigned int v12; // er8
  unsigned int v13; // eax
  unsigned __int16 v14; // cx
  AkAudioMarker *v15; // rax
  unsigned __int16 v16; // r9
  unsigned int v17; // er8
  unsigned int v18; // er10
  unsigned int v19; // ecx
  unsigned int v20; // er8
  unsigned int v21; // eax

  v2 = this->m_pCtx;
  v3 = this;
  if ( *((_BYTE *)v2 + 375) & 4 )
  {
    if ( v2->m_LoopCount )
    {
      ((void (*)(void))this->vfptr[1].TimeSkip)();
      v4 = a2;
    }
    else
    {
      v4 = (float)((float)(signed int)this->m_uTotalSamples * 1000.0)
         / (float)(signed int)v2->m_sMediaFormat.uSampleRate;
    }
    v2 = v3->m_pCtx;
    v5 = (*((_BYTE *)v2 + 375) >> 3) & 1;
    v6 = (signed int)(float)((float)((float)(v4 * v2->m_fSeekPercent) * (float)(signed int)v2->m_sMediaFormat.uSampleRate)
                           * 0.001);
  }
  else
  {
    v5 = (*((_BYTE *)v2 + 375) >> 3) & 1;
    if ( *((_BYTE *)v2 + 374) >= 0 )
      v7 = AkAudioLibSettings::g_pipelineCoreFrequency;
    else
      v7 = (unsigned __int16)(signed int)(float)((float)((float)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency
                                                       * 0.0009765625)
                                               * 8.0);
    v6 = v2->m_uSeekPosition * (unsigned __int64)v2->m_sMediaFormat.uSampleRate / v7;
  }
  v8 = v2->m_LoopCount;
  v9 = v3->m_uPCMLoopEnd;
  v10 = v3->m_uPCMLoopStart;
  v11 = 0;
  v3->m_uLoopCnt = v8;
  if ( v8 != 1 && v6 > v9 && v9 > v10 )
  {
    v12 = v9 - v10 + 1;
    v13 = (v6 - v10) / v12;
    if ( v13 < v8 )
    {
      if ( v8 )
      {
        v14 = v8 - v13;
        goto LABEL_19;
      }
    }
    else if ( v8 )
    {
      v3->m_uLoopCnt = 1;
      v6 -= v12 * (v8 - 1);
      goto LABEL_20;
    }
    v14 = 0;
LABEL_19:
    v3->m_uLoopCnt = v14;
    v6 = (v6 - v10) % v12 + v10;
  }
LABEL_20:
  if ( !v5 )
    return v6;
  v15 = CAkMarkers::GetClosestMarker(&v3->m_markers, v6);
  if ( !v15 )
    return v6;
  v16 = v3->m_uLoopCnt;
  v17 = v3->m_uPCMLoopEnd;
  v18 = v3->m_uPCMLoopStart;
  v19 = v15->dwPosition;
  v3->m_uLoopCnt = v16;
  if ( v16 == 1 || v19 <= v17 || v17 <= v18 )
    return v19;
  v20 = v17 - v18 + 1;
  v21 = (v19 - v18) / v20;
  if ( v21 < v16 )
  {
    if ( v16 )
      v11 = v16 - v21;
  }
  else if ( v16 )
  {
    v3->m_uLoopCnt = 1;
    v19 -= v20 * (v16 - 1);
    return v19;
  }
  v3->m_uLoopCnt = v11;
  return (v19 - v18) % v20 + v18;
}

