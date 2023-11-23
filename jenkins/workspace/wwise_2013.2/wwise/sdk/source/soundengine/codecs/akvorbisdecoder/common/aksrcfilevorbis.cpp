// File Line: 26
// RVA: 0xABB230
CAkSrcFileBase *__fastcall CreateVorbisFilePlugin(CAkPBI *in_pCtx)
{
  CAkSrcFileBase *result; // rax
  CAkSrcFileBase *v3; // rbx

  result = (CAkSrcFileBase *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x1C8ui64);
  v3 = result;
  if ( result )
  {
    CAkSrcFileBase::CAkSrcFileBase(result, in_pCtx);
    v3->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFileVorbis::`vftable;
    *(_QWORD *)&v3[3].m_uTotalSamples = 0i64;
    *(_QWORD *)&v3[3].m_uDataSize = 0i64;
    *(_QWORD *)&v3[3].m_uPCMLoopStart = 0i64;
    *(_QWORD *)&v3[3].m_markers.m_hdrMarkers.uNumMarkers = 0i64;
    memset(&v3[1], 0, 0x128ui64);
    return v3;
  }
  return result;
}

// File Line: 48
// RVA: 0xABB0B0
void __fastcall CAkSrcFileVorbis::~CAkSrcFileVorbis(CAkSrcFileVorbis *this)
{
  char *pucData; // rdx
  unsigned int uChannelMask; // r8d
  int i; // ecx

  pucData = this->m_VorbisState.TremorInfo.pucData;
  this->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFileVorbis::`vftable;
  if ( pucData )
  {
    uChannelMask = this->m_VorbisState.TremorInfo.uChannelMask;
    for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++i;
    CAkLEngine::ReleaseCachedAudioBuffer(i << 11, pucData);
    this->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced = 0;
    this->m_VorbisState.TremorInfo.pucData = 0i64;
  }
  if ( this->m_VorbisState.TremorInfo.VorbisDSPState.csi )
    AkVorbisCodebookMgr::ReleaseCodebook(&g_VorbisCodebookMgr, &this->m_VorbisState);
  CAkSrcFileBase::~CAkSrcFileBase(this);
}

// File Line: 56
// RVA: 0xABB4A0
void __fastcall CAkSrcFileVorbis::GetBuffer(CAkSrcFileVorbis *this, AkVPLState *io_state)
{
  AKRESULT IsPrebufferingReady; // eax
  __int64 uMaxPacketSize; // rdx
  unsigned __int64 m_ulSizeLeft; // rcx
  char *v7; // rcx
  unsigned __int16 v8; // ax
  size_t v9; // r8
  char *m_pNextAddress; // rdx
  char v11; // al
  AKRESULT StreamBuffer; // eax
  char *m_pStitchStreamBuffer; // rdx
  __int64 v14; // rcx
  unsigned __int64 v15; // rdi
  char *CachedAudioBuffer; // rax
  bool v17; // dl
  bool v18; // al
  char *v19; // r9
  unsigned int m_uStitchBufferLeft; // ecx
  int m_uStitchBufferValidDataSize; // eax
  unsigned __int16 v22; // dx
  unsigned __int16 v23; // cx
  unsigned __int16 v24; // cx
  unsigned __int16 m_uStitchBufferEndOffset; // ax
  unsigned int v26; // ecx
  __int16 *pucData; // r9
  char *v28; // r8
  unsigned __int16 v29; // dx
  __int64 uInputBytesConsumed; // rcx

  if ( (*((_BYTE *)&this->CAkVPLSrcNode + 32) & 2) != 0 )
  {
    IsPrebufferingReady = (unsigned int)AK::SrcFileServices::IsPrebufferingReady(this->m_pStream, this->m_ulSizeLeft);
    if ( IsPrebufferingReady != AK_DataReady )
    {
      io_state->result = IsPrebufferingReady;
      return;
    }
    *((_BYTE *)&this->CAkVPLSrcNode + 32) &= ~2u;
  }
  uMaxPacketSize = this->m_VorbisState.VorbisInfo.uMaxPacketSize;
  m_ulSizeLeft = this->m_ulSizeLeft;
  this->m_VorbisState.TremorInfo.uRequestedFrames = io_state->uMaxFrames;
  if ( m_ulSizeLeft < uMaxPacketSize + 2 && (*((_BYTE *)&this->CAkSrcFileBase + 126) & 1) == 0 )
  {
    if ( (_DWORD)m_ulSizeLeft && !this->m_pStitchStreamBuffer && !this->m_uStreamLoopCntAhead )
    {
      v7 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, m_ulSizeLeft + uMaxPacketSize + 2);
      this->m_pStitchStreamBuffer = v7;
      if ( !v7 )
      {
LABEL_10:
        io_state->result = AK_Fail;
        return;
      }
      v8 = this->m_ulSizeLeft;
      v9 = this->m_ulSizeLeft;
      m_pNextAddress = this->m_pNextAddress;
      this->m_uStitchBufferEndOffset = v8;
      this->m_uStitchBufferLeft = v8;
      this->m_uStitchBufferValidDataSize = v8;
      memmove(v7, m_pNextAddress, v9);
      this->m_pNextAddress = 0i64;
      this->m_ulSizeLeft = 0;
    }
    if ( !this->m_ulSizeLeft )
    {
      v11 = *((_BYTE *)&this->CAkSrcFileBase + 126);
      if ( (v11 & 2) != 0 )
        *((_BYTE *)&this->CAkSrcFileBase + 126) = v11 & 0xFD;
      else
        this->m_pStream->CAkSrcFileBase::vfptr->ReleaseBuffer(this->m_pStream);
      StreamBuffer = CAkSrcFileBase::FetchStreamBuffer(this);
      io_state->result = StreamBuffer;
      if ( StreamBuffer == AK_Fail )
        return;
      if ( StreamBuffer == AK_DataReady )
      {
        m_pStitchStreamBuffer = this->m_pStitchStreamBuffer;
        if ( m_pStitchStreamBuffer )
        {
          v14 = this->m_VorbisState.VorbisInfo.uMaxPacketSize;
          v15 = this->m_ulSizeLeft;
          if ( v14 + 2 < v15 )
            LODWORD(v15) = v14 + 2;
          memmove(&m_pStitchStreamBuffer[this->m_uStitchBufferEndOffset], this->m_pNextAddress, (unsigned int)v15);
          this->m_uStitchBufferLeft += v15;
          this->m_uStitchBufferValidDataSize += v15;
        }
      }
    }
  }
  if ( !this->m_VorbisState.TremorInfo.pucData )
  {
    CachedAudioBuffer = (char *)CAkLEngine::GetCachedAudioBuffer(this->m_VorbisState.TremorInfo.VorbisDSPState.channels << 11);
    this->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced = 0;
    this->m_VorbisState.TremorInfo.pucData = CachedAudioBuffer;
    if ( !CachedAudioBuffer )
      goto LABEL_10;
  }
  v17 = 1;
  v18 = this->m_uStreamLoopCntAhead || (*((_BYTE *)&this->CAkSrcFileBase + 126) & 1) != 0;
  v19 = this->m_pStitchStreamBuffer;
  this->m_VorbisState.TremorInfo.bNoMoreInputPackets = v18;
  if ( v19 )
  {
    if ( !v18 || this->m_ulSizeLeft + this->m_uStitchBufferEndOffset - this->m_uStitchBufferValidDataSize )
      v17 = 0;
    m_uStitchBufferLeft = this->m_uStitchBufferLeft;
    m_uStitchBufferValidDataSize = this->m_uStitchBufferValidDataSize;
    this->m_VorbisState.TremorInfo.bNoMoreInputPackets = v17;
    v22 = this->m_VorbisState.VorbisInfo.uMaxPacketSize;
    this->m_VorbisState.TremorInfo.uInputDataSize = m_uStitchBufferLeft;
    DecodeVorbis(
      &this->m_VorbisState.TremorInfo,
      v22,
      &v19[m_uStitchBufferValidDataSize - m_uStitchBufferLeft],
      (__int16 *)this->m_VorbisState.TremorInfo.pucData);
    v23 = this->m_uStitchBufferValidDataSize;
    this->m_uStitchBufferLeft -= LOWORD(this->m_VorbisState.TremorInfo.ReturnInfo.uInputBytesConsumed);
    v24 = v23 - this->m_uStitchBufferLeft;
    m_uStitchBufferEndOffset = this->m_uStitchBufferEndOffset;
    if ( v24 >= m_uStitchBufferEndOffset )
    {
      v26 = v24 - m_uStitchBufferEndOffset;
      this->m_ulSizeLeft -= v26;
      this->m_pNextAddress += v26;
      CAkSrcFileVorbis::FreeStitchBuffer(this);
    }
  }
  else
  {
    pucData = (__int16 *)this->m_VorbisState.TremorInfo.pucData;
    v28 = this->m_pNextAddress;
    v29 = this->m_VorbisState.VorbisInfo.uMaxPacketSize;
    this->m_VorbisState.TremorInfo.uInputDataSize = this->m_ulSizeLeft;
    DecodeVorbis(&this->m_VorbisState.TremorInfo, v29, v28, pucData);
    uInputBytesConsumed = this->m_VorbisState.TremorInfo.ReturnInfo.uInputBytesConsumed;
    this->m_pNextAddress += uInputBytesConsumed;
    this->m_ulSizeLeft -= uInputBytesConsumed;
  }
  CAkSrcFileVorbis::SubmitBufferAndUpdateVorbis(this, io_state);
}

// File Line: 170
// RVA: 0xABC040
void __fastcall CAkSrcFileVorbis::SubmitBufferAndUpdateVorbis(CAkSrcFileVorbis *this, AkVPLState *io_state)
{
  AKRESULT eDecoderStatus; // eax
  AKRESULT v5; // eax

  eDecoderStatus = this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderStatus;
  io_state->result = eDecoderStatus;
  if ( eDecoderStatus != AK_Fail )
  {
    CAkSrcBaseEx::SubmitBufferAndUpdate(
      this,
      this->m_VorbisState.TremorInfo.pucData,
      this->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced,
      this->m_VorbisState.uSampleRate,
      this->m_VorbisState.TremorInfo.uChannelMask,
      io_state);
    if ( io_state->result == AK_NoDataReady )
    {
      if ( this->m_pNextAddress )
      {
        v5 = AK_Fail;
        if ( this->m_VorbisState.TremorInfo.ReturnInfo.uInputBytesConsumed )
          v5 = AK_DataReady;
        io_state->result = v5;
      }
    }
  }
}

// File Line: 216
// RVA: 0xABB920
__int64 __fastcall CAkSrcFileVorbis::OnLoopComplete(CAkSrcFileVorbis *this, bool in_bEndOfFile)
{
  unsigned __int16 m_uLoopCnt; // ax
  unsigned int v4; // edi
  unsigned __int16 uLastGranuleExtra; // r8

  if ( !in_bEndOfFile )
    --this->m_uStreamLoopCntAhead;
  m_uLoopCnt = this->m_uLoopCnt;
  if ( m_uLoopCnt > 1u )
    this->m_uLoopCnt = m_uLoopCnt - 1;
  v4 = 45;
  if ( in_bEndOfFile )
    v4 = 17;
  if ( !in_bEndOfFile )
  {
    if ( this->m_uLoopCnt == 1 )
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

// File Line: 232
// RVA: 0xABBDE0
void __fastcall CAkSrcFileVorbis::ReleaseBuffer(CAkSrcFileVorbis *this)
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

// File Line: 243
// RVA: 0xABBE40
__int64 __fastcall CAkSrcFileVorbis::StartStream(CAkSrcFileVorbis *this)
{
  CAkSrcFileVorbis *v1; // rdi
  unsigned int m_ulSizeLeft; // edx
  AK::IAkAutoStream *m_pStream; // rcx
  __int64 result; // rax
  unsigned int Buffer; // ebx
  unsigned int IsPrebufferingReady; // ebx
  CAkPBI *m_pCtx; // rax
  AkAutoStmBufSettings in_bufSettings; // [rsp+20h] [rbp-18h] BYREF
  bool out_bUsePrefetchedData; // [rsp+40h] [rbp+8h] BYREF

  v1 = this;
  if ( (*((_BYTE *)&this->CAkSrcFileBase + 126) & 4) != 0 )
  {
    if ( (*((_BYTE *)&this->CAkVPLSrcNode + 32) & 2) != 0 )
    {
      m_ulSizeLeft = this->m_ulSizeLeft;
      m_pStream = this->m_pStream;
      goto LABEL_14;
    }
    return 1i64;
  }
  if ( !this->m_pStream || this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState >= 3 )
  {
    in_bufSettings.uBufferSize = 0;
    *(_QWORD *)&in_bufSettings.uMinBufferSize = 2048i64;
    result = CAkSrcFileBase::CreateStream(this, &in_bufSettings, 0);
    if ( (_DWORD)result != 1 )
      return result;
    Buffer = CAkSrcFileBase::HandlePrefetch(v1, &out_bUsePrefetchedData);
    if ( Buffer != 1 )
      return Buffer;
    result = ((__int64 (__fastcall *)(AK::IAkAutoStream *))v1->m_pStream->CAkSrcFileBase::vfptr->Start)(v1->m_pStream);
    if ( (_DWORD)result != 1 )
      return result;
    if ( out_bUsePrefetchedData )
    {
      m_pCtx = v1->m_pCtx;
      v1->m_uCurSample = 0;
      v1->m_uLoopCnt = m_pCtx->m_LoopCount;
      result = CAkSrcFileVorbis::DecodeVorbisHeader(v1);
      Buffer = result;
      if ( (_DWORD)result != 1 )
        return result;
      CAkSrcFileVorbis::VorbisDSPRestart(v1, 0);
      return Buffer;
    }
    this = v1;
  }
  Buffer = CAkSrcFileVorbis::ProcessFirstBuffer(this);
  if ( Buffer != 1 )
    return Buffer;
  if ( (*((_BYTE *)&v1->CAkVPLSrcNode + 32) & 2) == 0 )
    return 1i64;
  m_ulSizeLeft = v1->m_ulSizeLeft;
  m_pStream = v1->m_pStream;
LABEL_14:
  IsPrebufferingReady = AK::SrcFileServices::IsPrebufferingReady(m_pStream, m_ulSizeLeft);
  if ( IsPrebufferingReady == 46 )
    return 63i64;
  if ( IsPrebufferingReady == 45 )
    return 1;
  return IsPrebufferingReady;
}

// File Line: 306
// RVA: 0xABBFA0
void __fastcall CAkSrcFileVorbis::StopStream(CAkSrcFileVorbis *this)
{
  AkVorbisSeekTableItem *pSeekTable; // rdx
  char *m_pStitchStreamBuffer; // rdx
  char *m_pOggPacketData; // rdx

  vorbis_dsp_clear(&this->m_VorbisState.TremorInfo.VorbisDSPState);
  this->vfptr->ReleaseBuffer(this);
  pSeekTable = this->m_VorbisState.pSeekTable;
  if ( pSeekTable )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, pSeekTable);
    this->m_VorbisState.pSeekTable = 0i64;
  }
  m_pStitchStreamBuffer = this->m_pStitchStreamBuffer;
  if ( m_pStitchStreamBuffer )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pStitchStreamBuffer);
    this->m_pStitchStreamBuffer = 0i64;
    *(_DWORD *)&this->m_uStitchBufferEndOffset = 0;
    this->m_uStitchBufferLeft = 0;
  }
  m_pOggPacketData = this->m_pOggPacketData;
  if ( m_pOggPacketData )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pOggPacketData);
    this->m_pOggPacketData = 0i64;
  }
  CAkSrcFileBase::StopStream(this);
}

// File Line: 336
// RVA: 0xABBF80
__int64 __fastcall CAkSrcFileVorbis::StopLooping(CAkSrcFileVorbis *this)
{
  if ( !this->m_uStreamLoopCntAhead )
    this->m_VorbisState.TremorInfo.VorbisDSPState.state.extra_samples_end = this->m_VorbisState.VorbisInfo.uLastGranuleExtra;
  return CAkSrcFileBase::StopLooping(this);
}

// File Line: 348
// RVA: 0xABC150
void __fastcall CAkSrcFileVorbis::VirtualOn(CAkSrcFileVorbis *this, unsigned int eBehavior)
{
  char *m_pStitchStreamBuffer; // rdx

  CAkSrcFileBase::VirtualOn(this, eBehavior);
  if ( eBehavior <= 1 )
  {
    m_pStitchStreamBuffer = this->m_pStitchStreamBuffer;
    if ( m_pStitchStreamBuffer )
    {
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pStitchStreamBuffer);
      this->m_pStitchStreamBuffer = 0i64;
      *(_DWORD *)&this->m_uStitchBufferEndOffset = 0;
      this->m_uStitchBufferLeft = 0;
    }
  }
}

// File Line: 359
// RVA: 0xABC0C0
__int64 __fastcall CAkSrcFileVorbis::VirtualOff(CAkSrcFileVorbis *this, __int64 eBehavior, bool in_bUseSourceOffset)
{
  unsigned int v3; // ebx
  __int64 result; // rax
  unsigned int v6; // esi
  CAkPBI *m_pCtx; // rcx
  unsigned int m_uSeekPosition; // edx
  unsigned __int16 uLastGranuleExtra; // r8

  v3 = eBehavior;
  result = CAkSrcFileBase::VirtualOff(this, eBehavior, in_bUseSourceOffset);
  v6 = result;
  if ( v3 <= 1 )
  {
    m_pCtx = this->m_pCtx;
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
    return v6;
  }
  return result;
}

// File Line: 380
// RVA: 0xABB2C0
__int64 __fastcall CAkSrcFileVorbis::DecodeVorbisHeader(CAkSrcFileVorbis *this)
{
  AkVorbisDecoderState eDecoderState; // eax
  unsigned int m_ulSizeLeft; // ecx
  unsigned int uSeekTableSizeRead; // eax
  unsigned int dwSeekTableSize; // esi
  unsigned int v6; // esi
  unsigned int uChannelMask; // r8d
  int v8; // edi
  int i; // edx
  AKRESULT NextPacket; // eax
  codec_setup_info **v12; // rax
  codec_setup_info *v13; // rax
  ogg_packet out_OggPacket; // [rsp+20h] [rbp-28h] BYREF

  eDecoderState = this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState;
  if ( eDecoderState >= 3 )
  {
LABEL_11:
    uChannelMask = this->m_VorbisState.TremorInfo.uChannelMask;
    v8 = 0;
    for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++i;
    LOBYTE(v8) = vorbis_dsp_init(&this->m_VorbisState.TremorInfo.VorbisDSPState, i) != 0;
    return (unsigned int)(v8 + 1);
  }
  else
  {
    while ( 1 )
    {
      m_ulSizeLeft = this->m_ulSizeLeft;
      if ( !m_ulSizeLeft )
        return 63i64;
      if ( eDecoderState < 2 )
      {
        uSeekTableSizeRead = this->m_VorbisState.uSeekTableSizeRead;
        dwSeekTableSize = this->m_VorbisState.VorbisInfo.dwSeekTableSize;
        if ( uSeekTableSizeRead < dwSeekTableSize )
        {
          v6 = dwSeekTableSize - uSeekTableSizeRead;
          if ( m_ulSizeLeft < v6 )
            v6 = this->m_ulSizeLeft;
          memmove((char *)this->m_VorbisState.pSeekTable + uSeekTableSizeRead, this->m_pNextAddress, v6);
          this->m_VorbisState.uSeekTableSizeRead += v6;
          this->m_pNextAddress += v6;
          this->m_ulSizeLeft -= v6;
        }
        if ( this->m_VorbisState.uSeekTableSizeRead == this->m_VorbisState.VorbisInfo.dwSeekTableSize )
          break;
      }
      eDecoderState = this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState;
      if ( eDecoderState == 2 )
        goto LABEL_15;
      if ( eDecoderState >= 3 )
        goto LABEL_11;
    }
    this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 2;
LABEL_15:
    NextPacket = CAkSrcFileVorbis::GetNextPacket(this, &out_OggPacket);
    if ( NextPacket == AK_NoDataReady )
      return 63i64;
    if ( NextPacket != AK_Fail && NextPacket != AK_NoMoreData && NextPacket != AK_InsufficientMemory )
    {
      v12 = (codec_setup_info **)AkVorbisCodebookMgr::Decodebook(
                                   &g_VorbisCodebookMgr,
                                   &this->m_VorbisState,
                                   this->m_pCtx,
                                   &out_OggPacket);
      if ( v12 )
      {
        v13 = *v12;
        this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
        this->m_VorbisState.TremorInfo.VorbisDSPState.csi = v13;
        goto LABEL_11;
      }
    }
    return 2i64;
  }
}

// File Line: 483
// RVA: 0xABBC20
__int64 __fastcall CAkSrcFileVorbis::ProcessFirstBuffer(CAkSrcFileVorbis *this)
{
  AKRESULT v2; // eax
  __int64 result; // rax
  CAkPBI *m_pCtx; // rax
  char *v5; // rdx
  __int64 m_uDataOffset; // rcx
  unsigned int v7; // eax
  unsigned int v8; // edi
  char v9; // al
  unsigned int m_uSeekPosition; // ecx
  char v11; // al
  CAkPBI *v12; // rax
  char *in_pBuffer; // [rsp+30h] [rbp+8h] BYREF

  *((_BYTE *)&this->CAkVPLSrcNode + 32) ^= (*((_BYTE *)&this->CAkVPLSrcNode + 32) ^ (*((_BYTE *)this->m_pCtx + 374) >> 4)) & 2;
  v2 = this->m_pStream->CAkSrcFileBase::vfptr->GetBuffer(this->m_pStream, (void **)&in_pBuffer, &this->m_ulSizeLeft, 0);
  if ( v2 == AK_NoDataReady )
    return 63i64;
  if ( v2 != AK_DataReady && v2 != AK_NoMoreData )
    return 2i64;
  if ( this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState )
  {
    result = CAkSrcFileBase::ProcessStreamBuffer(this, in_pBuffer, 0);
    if ( (_DWORD)result != 1 )
      return result;
  }
  else
  {
    result = ((__int64 (__fastcall *)(CAkSrcFileVorbis *, char *))this->vfptr[2].VirtualOff)(this, in_pBuffer);
    if ( (_DWORD)result != 1 )
      return result;
    m_pCtx = this->m_pCtx;
    v5 = in_pBuffer;
    this->m_uCurSample = 0;
    this->m_uLoopCnt = m_pCtx->m_LoopCount;
    result = CAkSrcFileBase::ProcessStreamBuffer(this, v5, 0);
    if ( (_DWORD)result != 1 )
      return result;
    m_uDataOffset = this->m_uDataOffset;
    this->m_pNextAddress += m_uDataOffset;
    this->m_ulSizeLeft -= m_uDataOffset;
  }
  v7 = CAkSrcFileVorbis::DecodeVorbisHeader(this);
  v8 = v7;
  if ( v7 == 1 )
  {
    LOWORD(m_uSeekPosition) = 0;
    if ( (*((_BYTE *)this->m_pCtx + 375) & 2) != 0 )
    {
      v8 = CAkSrcFileBase::SeekToSourceOffset(this);
      if ( this->m_ulSizeLeft )
      {
        v11 = *((_BYTE *)&this->CAkSrcFileBase + 126);
        if ( (v11 & 2) != 0 )
          *((_BYTE *)&this->CAkSrcFileBase + 126) = v11 & 0xFD;
        else
          this->m_pStream->CAkSrcFileBase::vfptr->ReleaseBuffer(this->m_pStream);
        this->m_pNextAddress = 0i64;
        this->m_ulSizeLeft = 0;
      }
      v12 = this->m_pCtx;
      if ( (*((_BYTE *)v12 + 375) & 2) != 0 )
        m_uSeekPosition = 0;
      else
        m_uSeekPosition = v12->m_uSeekPosition;
      *((_BYTE *)v12 + 375) &= 0xF1u;
      v12->m_uSeekPosition = 0;
      this->m_uCurSample += m_uSeekPosition;
    }
    CAkSrcFileVorbis::VorbisDSPRestart(this, m_uSeekPosition);
    *((_BYTE *)&this->CAkSrcFileBase + 126) |= 4u;
  }
  else if ( v7 == 63 && !this->m_ulSizeLeft )
  {
    v9 = *((_BYTE *)&this->CAkSrcFileBase + 126);
    if ( (v9 & 2) != 0 )
    {
      this->m_pNextAddress = 0i64;
      *((_BYTE *)&this->CAkSrcFileBase + 126) = v9 & 0xFD;
    }
    else
    {
      this->m_pStream->CAkSrcFileBase::vfptr->ReleaseBuffer(this->m_pStream);
      this->m_pNextAddress = 0i64;
    }
  }
  return v8;
}

// File Line: 577
// RVA: 0xABB9B0
AKRESULT __fastcall CAkSrcFileVorbis::ParseHeader(CAkSrcFileVorbis *this, char *in_pBuffer)
{
  unsigned int *p_m_uDataOffset; // r15
  unsigned int *p_m_uDataSize; // rbp
  unsigned int *p_m_uPCMLoopEnd; // r14
  unsigned int *p_m_uPCMLoopStart; // r12
  unsigned int *p_nSamplesPerSec; // rsi
  unsigned int m_ulSizeLeft; // edx
  AKRESULT result; // eax
  WaveFormatExtensible *pFormat; // rdi
  CAkPBI *m_pCtx; // rcx
  bool v13; // zf
  unsigned int dwSeekTableSize; // edx
  unsigned int v15; // ecx
  CAkPBI *v16; // rax
  unsigned int v17; // eax
  AkVorbisSeekTableItem *v18; // rax
  AK::IAkAutoStream *m_pStream; // rcx
  int uMaxPacketSize; // edx
  AkFileParser::AnalysisDataChunk in_analysisDataChunk; // [rsp+50h] [rbp-58h] BYREF
  AkAutoStmHeuristics io_heuristics; // [rsp+60h] [rbp-48h] BYREF
  AkFileParser::FormatInfo v23; // [rsp+70h] [rbp-38h] BYREF
  AkAudioFormat v24; // [rsp+B0h] [rbp+8h]

  p_m_uDataOffset = &this->m_uDataOffset;
  p_m_uDataSize = &this->m_uDataSize;
  p_m_uPCMLoopEnd = &this->m_uPCMLoopEnd;
  p_m_uPCMLoopStart = &this->m_uPCMLoopStart;
  p_nSamplesPerSec = 0i64;
  m_ulSizeLeft = this->m_ulSizeLeft;
  in_analysisDataChunk.uDataSize = 0;
  in_analysisDataChunk.pData = 0i64;
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
    if ( v23.pFormat->wFormatTag == 0xFFFF )
    {
      v24.uSampleRate = v23.pFormat->nSamplesPerSec;
      *((_DWORD *)&v24 + 1) = v23.pFormat->dwChannelMask & 0x3FFFF | (v23.pFormat->nChannels << 25) & 0x1F000000 | 0x400000;
      m_pCtx = this->m_pCtx;
      m_pCtx->m_sMediaFormat = v24;
      CAkPBI::InvalidateFeedbackParameters(m_pCtx);
      if ( in_analysisDataChunk.uDataSize )
        CAkSrcFileBase::StoreAnalysisData(this, &in_analysisDataChunk);
      this->m_uTotalSamples = *(_DWORD *)&pFormat[1].wFormatTag;
      if ( pFormat != (WaveFormatExtensible *)-24i64 )
        p_nSamplesPerSec = &pFormat[1].nSamplesPerSec;
      v13 = *p_m_uPCMLoopStart == 0;
      *(_QWORD *)&this->m_VorbisState.VorbisInfo.LoopInfo.dwLoopStartPacketOffset = *(_QWORD *)p_nSamplesPerSec;
      *(_QWORD *)&this->m_VorbisState.VorbisInfo.LoopInfo.uLoopBeginExtra = *((_QWORD *)p_nSamplesPerSec + 1);
      *(_QWORD *)&this->m_VorbisState.VorbisInfo.dwVorbisDataOffset = *((_QWORD *)p_nSamplesPerSec + 2);
      *(_QWORD *)&this->m_VorbisState.VorbisInfo.dwDecodeAllocSize = *((_QWORD *)p_nSamplesPerSec + 3);
      this->m_VorbisState.VorbisInfo.uHashCodebook = p_nSamplesPerSec[8];
      *(_WORD *)this->m_VorbisState.VorbisInfo.uBlockSizes = *((_WORD *)p_nSamplesPerSec + 18);
      this->m_VorbisState.TremorInfo.uChannelMask = pFormat->dwChannelMask;
      this->m_VorbisState.uSampleRate = pFormat->nSamplesPerSec;
      if ( v13 && !*p_m_uPCMLoopEnd )
        *p_m_uPCMLoopEnd = this->m_uTotalSamples - 1;
      if ( this->m_uLoopCnt == 1 )
      {
        this->m_ulLoopStart = *p_m_uDataOffset + this->m_VorbisState.VorbisInfo.dwVorbisDataOffset;
        this->m_ulLoopEnd = *p_m_uDataOffset + *p_m_uDataSize;
      }
      else
      {
        dwSeekTableSize = this->m_VorbisState.VorbisInfo.dwSeekTableSize;
        v15 = *p_m_uDataOffset;
        this->m_ulLoopStart = this->m_VorbisState.VorbisInfo.LoopInfo.dwLoopStartPacketOffset
                            + *p_m_uDataOffset
                            + dwSeekTableSize;
        this->m_ulLoopEnd = dwSeekTableSize + v15 + this->m_VorbisState.VorbisInfo.LoopInfo.dwLoopEndPacketOffset;
      }
      this->m_pStream->CAkSrcFileBase::vfptr->GetHeuristics(this->m_pStream, &io_heuristics);
      CAkSrcFileBase::GetStreamLoopHeuristic(this, this->m_uLoopCnt != 1, &io_heuristics);
      v16 = this->m_pCtx;
      io_heuristics.fThroughput = (float)(int)pFormat->nAvgBytesPerSec * 0.001;
      io_heuristics.priority = (int)v16->m_PriorityInfoCurrent.currentPriority.priority;
      this->m_pStream->CAkSrcFileBase::vfptr->SetHeuristics(this->m_pStream, &io_heuristics);
      v17 = this->m_VorbisState.VorbisInfo.dwSeekTableSize;
      if ( !v17
        || (v18 = (AkVorbisSeekTableItem *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, v17),
            (this->m_VorbisState.pSeekTable = v18) != 0i64) )
      {
        m_pStream = this->m_pStream;
        uMaxPacketSize = this->m_VorbisState.VorbisInfo.uMaxPacketSize;
        this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 1;
        return m_pStream->vfptr->SetMinimalBufferSize(m_pStream, 2 * uMaxPacketSize);
      }
      else
      {
        return 52;
      }
    }
    else
    {
      return 7;
    }
  }
  return result;
}

// File Line: 679
// RVA: 0xABB420
__int64 __fastcall CAkSrcFileVorbis::FindClosestFileOffset(
        CAkSrcFileVorbis *this,
        unsigned int in_uDesiredSample,
        unsigned int *out_uSeekedSample,
        unsigned int *out_uFileOffset)
{
  __int64 result; // rax

  result = VorbisSeek(&this->m_VorbisState, in_uDesiredSample, out_uSeekedSample, out_uFileOffset);
  if ( (_DWORD)result != 2 )
  {
    *out_uFileOffset += this->m_uDataOffset;
    return 1i64;
  }
  return result;
}

// File Line: 693
// RVA: 0xABB460
void __fastcall CAkSrcFileVorbis::FreeStitchBuffer(CAkSrcFileVorbis *this)
{
  char *m_pStitchStreamBuffer; // rdx

  m_pStitchStreamBuffer = this->m_pStitchStreamBuffer;
  if ( m_pStitchStreamBuffer )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pStitchStreamBuffer);
    this->m_pStitchStreamBuffer = 0i64;
    *(_DWORD *)&this->m_uStitchBufferEndOffset = 0;
    this->m_uStitchBufferLeft = 0;
  }
}

// File Line: 707
// RVA: 0xABB760
AKRESULT __fastcall CAkSrcFileVorbis::GetNextPacket(CAkSrcFileVorbis *this, ogg_packet *out_OggPacket)
{
  char v4; // al
  AKRESULT result; // eax
  __int64 m_uPacketHeaderGathered; // rdx
  unsigned __int64 m_ulSizeLeft; // rsi
  char *v8; // rdx
  char *v9; // rax
  unsigned int v10; // esi
  unsigned int m_uPacketDataGathered; // eax
  unsigned int v12; // ecx
  unsigned int v13; // esi
  char *m_pOggPacketData; // rax
  int uPacketSize; // ecx

  while ( 1 )
  {
    if ( !this->m_ulSizeLeft )
    {
      v4 = *((_BYTE *)&this->CAkSrcFileBase + 126);
      if ( (v4 & 1) != 0 )
        return 17;
      if ( (v4 & 2) != 0 )
        *((_BYTE *)&this->CAkSrcFileBase + 126) = v4 & 0xFD;
      else
        this->m_pStream->CAkSrcFileBase::vfptr->ReleaseBuffer(this->m_pStream);
      result = CAkSrcFileBase::FetchStreamBuffer(this);
      if ( result != AK_DataReady )
        return result;
    }
    m_uPacketHeaderGathered = this->m_uPacketHeaderGathered;
    if ( (unsigned int)m_uPacketHeaderGathered >= 2 )
      break;
    m_ulSizeLeft = this->m_ulSizeLeft;
    if ( (_DWORD)m_ulSizeLeft )
    {
      if ( m_ulSizeLeft >= 2 - m_uPacketHeaderGathered )
        LODWORD(m_ulSizeLeft) = 2 - m_uPacketHeaderGathered;
      memmove(
        (char *)&this->m_OggPacketHeader + this->m_uPacketHeaderGathered,
        this->m_pNextAddress,
        (unsigned int)m_ulSizeLeft);
      this->m_uPacketHeaderGathered += m_ulSizeLeft;
      this->m_pNextAddress += (unsigned int)m_ulSizeLeft;
      this->m_ulSizeLeft -= m_ulSizeLeft;
      if ( this->m_uPacketHeaderGathered == 2 )
        break;
    }
    else
    {
LABEL_21:
      if ( this->m_uPacketHeaderGathered == 2 && this->m_uPacketDataGathered == this->m_OggPacketHeader.uPacketSize )
      {
        m_pOggPacketData = this->m_pOggPacketData;
        uPacketSize = this->m_OggPacketHeader.uPacketSize;
        out_OggPacket->e_o_s = 0;
        out_OggPacket->buffer.data = m_pOggPacketData;
        out_OggPacket->buffer.size = uPacketSize;
        *(_QWORD *)&this->m_uPacketDataGathered = 0i64;
        return 45;
      }
    }
  }
  if ( this->m_uPacketDataGathered )
    goto LABEL_16;
  v8 = this->m_pOggPacketData;
  if ( v8 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v8);
    this->m_pOggPacketData = 0i64;
  }
  v9 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, this->m_OggPacketHeader.uPacketSize);
  this->m_pOggPacketData = v9;
  if ( v9 )
  {
LABEL_16:
    v10 = this->m_OggPacketHeader.uPacketSize;
    m_uPacketDataGathered = this->m_uPacketDataGathered;
    if ( m_uPacketDataGathered < v10 )
    {
      v12 = this->m_ulSizeLeft;
      if ( v12 )
      {
        v13 = v10 - m_uPacketDataGathered;
        if ( v12 < v13 )
          v13 = this->m_ulSizeLeft;
        memmove(&this->m_pOggPacketData[m_uPacketDataGathered], this->m_pNextAddress, v13);
        this->m_uPacketDataGathered += v13;
        this->m_pNextAddress += v13;
        this->m_ulSizeLeft -= v13;
      }
    }
    goto LABEL_21;
  }
  return 52;
}

// File Line: 800
// RVA: 0xABB170
__int64 __fastcall CAkSrcFileVorbis::ChangeSourcePosition(CAkSrcFileVorbis *this)
{
  __int64 result; // rax
  char *m_pStitchStreamBuffer; // rdx
  CAkPBI *m_pCtx; // rax
  unsigned int m_uSeekPosition; // edx
  unsigned __int16 uLastGranuleExtra; // r8

  result = CAkSrcFileBase::ChangeSourcePosition(this);
  if ( (_DWORD)result == 1 )
  {
    m_pStitchStreamBuffer = this->m_pStitchStreamBuffer;
    if ( m_pStitchStreamBuffer )
    {
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pStitchStreamBuffer);
      this->m_pStitchStreamBuffer = 0i64;
      *(_DWORD *)&this->m_uStitchBufferEndOffset = 0;
      this->m_uStitchBufferLeft = 0;
    }
    m_pCtx = this->m_pCtx;
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
    return 1i64;
  }
  return result;
}

