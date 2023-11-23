// File Line: 23
// RVA: 0xABA6D0
CAkSrcBaseEx *__fastcall CreateVorbisBankPlugin(CAkPBI *in_pCtx)
{
  CAkSrcBaseEx *result; // rax
  CAkSrcBaseEx *v3; // rbx

  result = (CAkSrcBaseEx *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x190ui64);
  v3 = result;
  if ( result )
  {
    CAkSrcBaseEx::CAkSrcBaseEx(result, in_pCtx);
    v3->vfptr = (CAkVPLNodeVtbl *)&CAkSrcBankVorbis::`vftable;
    *((_QWORD *)&v3[4].CAkVPLSrcNode + 4) = 0i64;
    *(_QWORD *)&v3[4].m_uTotalSamples = 0i64;
    memset(&v3[1], 0, 0x128ui64);
    return v3;
  }
  return result;
}

// File Line: 48
// RVA: 0xABA850
void __fastcall CAkSrcBankVorbis::GetBuffer(CAkSrcBankVorbis *this, AkVPLState *io_state)
{
  char *CachedAudioBuffer; // rax
  bool v5; // zf
  int m_pucDataStart; // eax
  unsigned int v7; // eax
  __int16 *pucData; // r9
  char *m_pucData; // r8
  unsigned __int16 uMaxPacketSize; // dx
  AKRESULT eDecoderStatus; // eax
  unsigned int uSampleRate; // r9d
  unsigned __int16 uFramesProduced; // r8

  if ( this->m_VorbisState.TremorInfo.pucData
    || (CachedAudioBuffer = (char *)CAkLEngine::GetCachedAudioBuffer(this->m_VorbisState.TremorInfo.VorbisDSPState.channels << 11),
        this->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced = 0,
        (this->m_VorbisState.TremorInfo.pucData = CachedAudioBuffer) != 0i64) )
  {
    v5 = this->m_uLoopCnt == 1;
    this->m_VorbisState.TremorInfo.uRequestedFrames = io_state->uMaxFrames;
    m_pucDataStart = (int)this->m_pucDataStart;
    if ( v5 )
      v7 = this->m_uDataSize + m_pucDataStart;
    else
      v7 = this->m_VorbisState.VorbisInfo.LoopInfo.dwLoopEndPacketOffset
         + this->m_VorbisState.VorbisInfo.dwSeekTableSize
         + m_pucDataStart;
    pucData = (__int16 *)this->m_VorbisState.TremorInfo.pucData;
    m_pucData = this->m_pucData;
    uMaxPacketSize = this->m_VorbisState.VorbisInfo.uMaxPacketSize;
    this->m_VorbisState.TremorInfo.uInputDataSize = v7 - LODWORD(this->m_pucData);
    this->m_VorbisState.TremorInfo.bNoMoreInputPackets = 1;
    DecodeVorbis(&this->m_VorbisState.TremorInfo, uMaxPacketSize, m_pucData, pucData);
    eDecoderStatus = this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderStatus;
    io_state->result = eDecoderStatus;
    if ( eDecoderStatus != AK_Fail )
    {
      uSampleRate = this->m_VorbisState.uSampleRate;
      uFramesProduced = this->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced;
      this->m_pucData += this->m_VorbisState.TremorInfo.ReturnInfo.uInputBytesConsumed;
      CAkSrcBaseEx::SubmitBufferAndUpdate(
        this,
        this->m_VorbisState.TremorInfo.pucData,
        uFramesProduced,
        uSampleRate,
        this->m_VorbisState.TremorInfo.uChannelMask,
        io_state);
    }
  }
  else
  {
    io_state->result = AK_Fail;
  }
}

// File Line: 95
// RVA: 0xABA9E0
void __fastcall CAkSrcBankVorbis::ReleaseBuffer(CAkSrcBankVorbis *this)
{
  char *pucData; // rdx
  unsigned int uChannelMask; // r8d
  int i; // ecx

  pucData = this->m_VorbisState.TremorInfo.pucData;
  if ( pucData )
  {
    uChannelMask = this->m_VorbisState.TremorInfo.uChannelMask;
    for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++i;
    CAkLEngine::ReleaseCachedAudioBuffer(i << 11, pucData);
    this->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced = 0;
    this->m_VorbisState.TremorInfo.pucData = 0i64;
  }
}

// File Line: 106
// RVA: 0xABAB50
AKRESULT __fastcall CAkSrcBankVorbis::StartStream(CAkSrcBankVorbis *this)
{
  CAkPBI *m_pCtx; // rax
  _DWORD *m_pDataPtr; // rsi
  unsigned int m_uDataSize; // ebp
  AKRESULT result; // eax
  unsigned int *p_m_uDataSize; // r13
  unsigned int *p_m_uPCMLoopStart; // r12
  unsigned int *p_m_uPCMLoopEnd; // r14
  unsigned int *p_m_uDataOffset; // r15
  unsigned int *p_wFormatTag; // rdi
  CAkPBI *v11; // rcx
  __int64 v12; // rdx
  unsigned int *v13; // rcx
  bool v14; // zf
  CAkPBI *v15; // rax
  int v16; // edi
  unsigned int m_uSeekPosition; // edx
  CAkPBI *v18; // rax
  AkFileParser::AnalysisDataChunk out_pAnalysisData; // [rsp+50h] [rbp-48h] BYREF
  AkFileParser::FormatInfo out_pFormatInfo; // [rsp+60h] [rbp-38h] BYREF
  AkAudioFormat v21; // [rsp+A0h] [rbp+8h]

  m_pCtx = this->m_pCtx;
  m_pDataPtr = m_pCtx->m_pDataPtr;
  m_uDataSize = m_pCtx->m_uDataSize;
  if ( !m_pDataPtr )
    return 2;
  p_m_uDataSize = &this->m_uDataSize;
  p_m_uPCMLoopStart = &this->m_uPCMLoopStart;
  out_pAnalysisData.uDataSize = 0;
  out_pAnalysisData.pData = 0i64;
  p_m_uPCMLoopEnd = &this->m_uPCMLoopEnd;
  p_m_uDataOffset = &this->m_uDataOffset;
  result = AkFileParser::Parse(
             m_pDataPtr,
             m_uDataSize,
             &out_pFormatInfo,
             &this->m_markers,
             &this->m_uPCMLoopStart,
             &this->m_uPCMLoopEnd,
             &this->m_uDataSize,
             &this->m_uDataOffset,
             &out_pAnalysisData,
             0i64);
  if ( result == AK_Success )
  {
    p_wFormatTag = (unsigned int *)&out_pFormatInfo.pFormat->wFormatTag;
    if ( out_pFormatInfo.pFormat->wFormatTag == 0xFFFF )
    {
      v21.uSampleRate = out_pFormatInfo.pFormat->nSamplesPerSec;
      *((_DWORD *)&v21 + 1) = out_pFormatInfo.pFormat->dwChannelMask & 0x3FFFF | (out_pFormatInfo.pFormat->nChannels << 25) & 0x1F000000 | 0x400000;
      v11 = this->m_pCtx;
      v11->m_sMediaFormat = v21;
      CAkPBI::InvalidateFeedbackParameters(v11);
      if ( out_pAnalysisData.uDataSize )
        this->m_pAnalysisData = out_pAnalysisData.pData;
      v12 = *p_m_uDataOffset;
      v13 = p_wFormatTag + 6;
      this->m_pucDataStart = (char *)m_pDataPtr + v12;
      this->m_uTotalSamples = p_wFormatTag[6];
      if ( p_wFormatTag != (unsigned int *)-24i64 )
        v13 = p_wFormatTag + 7;
      v14 = *p_m_uPCMLoopEnd == 0;
      *(_QWORD *)&this->m_VorbisState.VorbisInfo.LoopInfo.dwLoopStartPacketOffset = *(_QWORD *)v13;
      *(_QWORD *)&this->m_VorbisState.VorbisInfo.LoopInfo.uLoopBeginExtra = *((_QWORD *)v13 + 1);
      *(_QWORD *)&this->m_VorbisState.VorbisInfo.dwVorbisDataOffset = *((_QWORD *)v13 + 2);
      *(_QWORD *)&this->m_VorbisState.VorbisInfo.dwDecodeAllocSize = *((_QWORD *)v13 + 3);
      this->m_VorbisState.VorbisInfo.uHashCodebook = v13[8];
      *(_WORD *)this->m_VorbisState.VorbisInfo.uBlockSizes = *((_WORD *)v13 + 18);
      this->m_VorbisState.uSampleRate = p_wFormatTag[1];
      this->m_VorbisState.TremorInfo.uChannelMask = p_wFormatTag[5];
      if ( v14 )
        *p_m_uPCMLoopEnd = this->m_uTotalSamples - 1;
      if ( *p_m_uPCMLoopEnd >= *p_m_uPCMLoopStart
        && *p_m_uPCMLoopEnd < this->m_uTotalSamples
        && m_uDataSize == (_DWORD)v12 + *p_m_uDataSize )
      {
        v15 = this->m_pCtx;
        this->m_pucData = (char *)m_pDataPtr + v12;
        this->m_uCurSample = 0;
        this->m_uLoopCnt = v15->m_LoopCount;
        v16 = CAkSrcBankVorbis::DecodeVorbisHeader(this);
        if ( v16 == 1 )
        {
          LOWORD(m_uSeekPosition) = 0;
          if ( (*((_BYTE *)this->m_pCtx + 375) & 2) != 0 )
          {
            v16 = CAkSrcBankVorbis::SeekToNativeOffset(this);
            v18 = this->m_pCtx;
            if ( (*((_BYTE *)v18 + 375) & 2) != 0 )
              m_uSeekPosition = 0;
            else
              m_uSeekPosition = v18->m_uSeekPosition;
            *((_BYTE *)v18 + 375) &= 0xF1u;
            v18->m_uSeekPosition = 0;
            this->m_uCurSample += m_uSeekPosition;
          }
          CAkSrcBankVorbis::VorbisDSPRestart(this, m_uSeekPosition);
        }
        return v16;
      }
      else
      {
        return 2;
      }
    }
    else
    {
      return 7;
    }
  }
  return result;
}

// File Line: 216
// RVA: 0xABAA30
__int64 __fastcall CAkSrcBankVorbis::RelocateMedia(CAkSrcBankVorbis *this, char *in_pNewMedia, char *in_pOldMedia)
{
  __int64 v3; // rdx
  __int64 result; // rax

  v3 = in_pNewMedia - in_pOldMedia;
  result = 1i64;
  this->m_pucData += v3;
  this->m_pucDataStart += v3;
  return result;
}

// File Line: 226
// RVA: 0xABADE0
void __fastcall CAkSrcBankVorbis::StopStream(CAkSrcBankVorbis *this)
{
  AkVorbisSeekTableItem *pSeekTable; // rdx

  vorbis_dsp_clear(&this->m_VorbisState.TremorInfo.VorbisDSPState);
  this->vfptr->ReleaseBuffer(this);
  pSeekTable = this->m_VorbisState.pSeekTable;
  if ( pSeekTable )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, pSeekTable);
    this->m_VorbisState.pSeekTable = 0i64;
  }
  CAkSrcBaseEx::StopStream(this);
}

// File Line: 240
// RVA: 0xABADC0
__int64 __fastcall CAkSrcBankVorbis::StopLooping(CAkSrcBankVorbis *this)
{
  this->m_VorbisState.TremorInfo.VorbisDSPState.state.extra_samples_end = this->m_VorbisState.VorbisInfo.uLastGranuleExtra;
  return CAkSrcBaseEx::StopLooping(this);
}

// File Line: 247
// RVA: 0xABAE30
__int64 __fastcall CAkSrcBankVorbis::VirtualOff(
        CAkSrcBankVorbis *this,
        unsigned int eBehavior,
        bool in_bUseSourceOffset)
{
  AkVirtualQueueBehavior v3; // eax
  unsigned int v4; // edi
  AKRESULT v6; // eax
  CAkPBI *m_pCtx; // rax
  __int64 dwVorbisDataOffset; // rax
  unsigned __int16 uLastGranuleExtra; // r8
  unsigned int out_uFileOffset; // [rsp+38h] [rbp+10h] BYREF

  v3 = eBehavior;
  v4 = 1;
  LOWORD(eBehavior) = 0;
  if ( v3 == AkVirtualQueueBehavior_FromElapsedTime )
  {
    if ( in_bUseSourceOffset )
    {
      v6 = (unsigned int)CAkSrcBankVorbis::SeekToNativeOffset(this);
    }
    else
    {
      if ( VorbisSeek(&this->m_VorbisState, this->m_uCurSample, &this->m_uCurSample, &out_uFileOffset) == AK_Success )
      {
        this->m_pucData = &this->m_pucDataStart[out_uFileOffset];
LABEL_8:
        m_pCtx = this->m_pCtx;
        if ( (*((_BYTE *)m_pCtx + 375) & 2) != 0 )
          eBehavior = 0;
        else
          eBehavior = m_pCtx->m_uSeekPosition;
        *((_BYTE *)m_pCtx + 375) &= 0xF1u;
        m_pCtx->m_uSeekPosition = 0;
        this->m_uCurSample += eBehavior;
        goto LABEL_14;
      }
      this->m_uCurSample = 0;
      v6 = CAkSrcBankVorbis::VirtualSeek(this, &this->m_uCurSample);
    }
    v4 = v6;
    goto LABEL_8;
  }
  if ( v3 )
    return v4;
  dwVorbisDataOffset = this->m_VorbisState.VorbisInfo.dwVorbisDataOffset;
  this->m_uCurSample = 0;
  this->m_pucData = &this->m_pucDataStart[dwVorbisDataOffset];
  this->m_uLoopCnt = this->m_pCtx->m_LoopCount;
LABEL_14:
  if ( this->m_uLoopCnt == 1 )
    uLastGranuleExtra = this->m_VorbisState.VorbisInfo.uLastGranuleExtra;
  else
    uLastGranuleExtra = this->m_VorbisState.VorbisInfo.LoopInfo.uLoopEndExtra;
  vorbis_dsp_restart(&this->m_VorbisState.TremorInfo.VorbisDSPState, eBehavior, uLastGranuleExtra);
  this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
  return v4;
}

// File Line: 295
// RVA: 0xABAF40
__int64 __fastcall CAkSrcBankVorbis::VirtualSeek(CAkSrcBankVorbis *this, unsigned int *io_uSeekPosition)
{
  unsigned int out_uFileOffset; // [rsp+30h] [rbp+8h] BYREF

  if ( VorbisSeek(&this->m_VorbisState, *io_uSeekPosition, io_uSeekPosition, &out_uFileOffset) != AK_Success )
    return 2i64;
  this->m_pucData = &this->m_pucDataStart[out_uFileOffset];
  return 1i64;
}

// File Line: 313
// RVA: 0xABA750
__int64 __fastcall CAkSrcBankVorbis::DecodeVorbisHeader(CAkSrcBankVorbis *this)
{
  unsigned int dwSeekTableSize; // eax
  AkVorbisSeekTableItem *v3; // rax
  unsigned int v5; // eax
  char *m_pucData; // rdx
  CAkPBI *m_pCtx; // r8
  unsigned int v8; // ecx
  codec_setup_info **v9; // rax
  unsigned int uChannelMask; // ecx
  int v11; // edx
  ogg_packet op; // [rsp+20h] [rbp-28h] BYREF

  dwSeekTableSize = this->m_VorbisState.VorbisInfo.dwSeekTableSize;
  if ( dwSeekTableSize )
  {
    v3 = (AkVorbisSeekTableItem *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, dwSeekTableSize);
    this->m_VorbisState.pSeekTable = v3;
    if ( !v3 )
      return 52i64;
  }
  v5 = this->m_VorbisState.VorbisInfo.dwSeekTableSize;
  this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 1;
  if ( v5 )
  {
    memmove(this->m_VorbisState.pSeekTable, this->m_pucData, v5);
    this->m_pucData += this->m_VorbisState.VorbisInfo.dwSeekTableSize;
  }
  m_pucData = this->m_pucData;
  m_pCtx = this->m_pCtx;
  v8 = *(unsigned __int16 *)m_pucData;
  op.e_o_s = 0;
  op.buffer.size = v8;
  op.buffer.data = m_pucData + 2;
  this->m_pucData = &m_pucData[v8 + 2];
  v9 = (codec_setup_info **)AkVorbisCodebookMgr::Decodebook(&g_VorbisCodebookMgr, &this->m_VorbisState, m_pCtx, &op);
  if ( !v9 )
    return 2i64;
  uChannelMask = this->m_VorbisState.TremorInfo.uChannelMask;
  v11 = 0;
  for ( this->m_VorbisState.TremorInfo.VorbisDSPState.csi = *v9; uChannelMask; uChannelMask &= uChannelMask - 1 )
    ++v11;
  if ( vorbis_dsp_init(&this->m_VorbisState.TremorInfo.VorbisDSPState, v11) )
    return 2i64;
  this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
  return 1i64;
}

// File Line: 409
// RVA: 0xABAA50
__int64 __fastcall CAkSrcBankVorbis::SeekToNativeOffset(CAkSrcBankVorbis *this)
{
  unsigned __int64 SourceOffset; // r9
  unsigned int dwVorbisDataOffset; // ecx
  unsigned int v5; // r8d
  AkVorbisSeekTableItem *pSeekTable; // rdx
  unsigned int v7; // r11d
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // r10d
  unsigned int v11; // ecx
  int uPacketFileOffset; // eax
  CAkPBI *m_pCtx; // rax

  if ( !this->m_VorbisState.pSeekTable )
    return 2i64;
  SourceOffset = (unsigned int)CAkSrcBaseEx::GetSourceOffset(this);
  if ( SourceOffset >= this->m_uTotalSamples )
    return 2i64;
  if ( !(_DWORD)SourceOffset )
  {
    dwVorbisDataOffset = this->m_VorbisState.VorbisInfo.dwVorbisDataOffset;
    v5 = 0;
LABEL_14:
    this->m_uCurSample = v5;
    this->m_pucData = &this->m_pucDataStart[dwVorbisDataOffset];
    m_pCtx = this->m_pCtx;
    *((_BYTE *)m_pCtx + 375) &= 0xF1u;
    m_pCtx->m_uSeekPosition = SourceOffset - v5;
    return 1i64;
  }
  pSeekTable = this->m_VorbisState.pSeekTable;
  v7 = this->m_VorbisState.VorbisInfo.dwSeekTableSize >> 2;
  if ( pSeekTable && v7 )
  {
    v5 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    do
    {
      v11 = v9 + pSeekTable->uPacketFrameOffset;
      if ( v11 > (unsigned int)SourceOffset )
        break;
      uPacketFileOffset = pSeekTable->uPacketFileOffset;
      ++v10;
      ++pSeekTable;
      v8 += uPacketFileOffset;
      v9 = v11;
    }
    while ( v10 < v7 );
    if ( v10 )
    {
      dwVorbisDataOffset = this->m_VorbisState.VorbisInfo.dwSeekTableSize + v8;
      v5 = v9;
    }
    else
    {
      dwVorbisDataOffset = this->m_VorbisState.VorbisInfo.dwVorbisDataOffset;
    }
    goto LABEL_14;
  }
  return 2i64;
}

// File Line: 440
// RVA: 0xABA650
__int64 __fastcall CAkSrcBankVorbis::ChangeSourcePosition(CAkSrcBankVorbis *this)
{
  AKRESULT v2; // eax
  CAkPBI *m_pCtx; // rcx
  AKRESULT v4; // edi
  unsigned int m_uSeekPosition; // edx
  unsigned __int16 uLastGranuleExtra; // r8

  v2 = CAkSrcBankVorbis::SeekToNativeOffset(this);
  m_pCtx = this->m_pCtx;
  v4 = v2;
  if ( (*((_BYTE *)m_pCtx + 375) & 2) != 0 )
    m_uSeekPosition = 0;
  else
    m_uSeekPosition = m_pCtx->m_uSeekPosition;
  *((_BYTE *)m_pCtx + 375) &= 0xF1u;
  m_pCtx->m_uSeekPosition = 0;
  this->m_uCurSample += m_uSeekPosition;
  if ( this->m_uLoopCnt == 1 )
    uLastGranuleExtra = this->m_VorbisState.VorbisInfo.uLastGranuleExtra;
  else
    uLastGranuleExtra = this->m_VorbisState.VorbisInfo.LoopInfo.uLoopEndExtra;
  vorbis_dsp_restart(&this->m_VorbisState.TremorInfo.VorbisDSPState, m_uSeekPosition, uLastGranuleExtra);
  this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
  return (unsigned int)v4;
}

// File Line: 461
// RVA: 0xABA950
__int64 __fastcall CAkSrcBankVorbis::OnLoopComplete(CAkSrcBankVorbis *this, bool in_bEndOfFile)
{
  unsigned __int16 m_uLoopCnt; // ax
  unsigned int v4; // edi
  bool v5; // zf
  unsigned __int16 uLastGranuleExtra; // r8

  m_uLoopCnt = this->m_uLoopCnt;
  if ( m_uLoopCnt > 1u )
    this->m_uLoopCnt = m_uLoopCnt - 1;
  v4 = 45;
  if ( in_bEndOfFile )
    v4 = 17;
  if ( !in_bEndOfFile )
  {
    v5 = this->m_uLoopCnt == 1;
    this->m_pucData = &this->m_pucDataStart[this->m_VorbisState.VorbisInfo.LoopInfo.dwLoopStartPacketOffset
                                          + (unsigned __int64)this->m_VorbisState.VorbisInfo.dwSeekTableSize];
    if ( v5 )
      uLastGranuleExtra = this->m_VorbisState.VorbisInfo.uLastGranuleExtra;
    else
      uLastGranuleExtra = this->m_VorbisState.VorbisInfo.LoopInfo.uLoopEndExtra;
    vorbis_dsp_restart(
      &this->m_VorbisState.TremorInfo.VorbisDSPState,
      this->m_VorbisState.VorbisInfo.LoopInfo.uLoopBeginExtra,
      uLastGranuleExtra);
    this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
    this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderStatus = AK_DataReady;
  }
  return v4;
}

