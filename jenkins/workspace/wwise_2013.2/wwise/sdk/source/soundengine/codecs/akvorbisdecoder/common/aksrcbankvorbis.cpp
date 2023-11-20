// File Line: 23
// RVA: 0xABA6D0
CAkSrcBaseEx *__fastcall CreateVorbisBankPlugin(void *in_pCtx)
{
  CAkPBI *v1; // rdi
  CAkSrcBaseEx *result; // rax
  IAkSoftwareCodec *v3; // rbx

  v1 = (CAkPBI *)in_pCtx;
  result = (CAkSrcBaseEx *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x190ui64);
  v3 = (IAkSoftwareCodec *)&result->vfptr;
  if ( result )
  {
    CAkSrcBaseEx::CAkSrcBaseEx(result, v1);
    v3->vfptr = (CAkVPLNodeVtbl *)&CAkSrcBankVorbis::`vftable';
    v3[24].vfptr = 0i64;
    v3[24].m_pInput = 0i64;
    memset(&v3[5].m_pInput, 0, 0x128ui64);
    result = (CAkSrcBaseEx *)v3;
  }
  return result;
}

// File Line: 48
// RVA: 0xABA850
void __fastcall CAkSrcBankVorbis::GetBuffer(CAkSrcBankVorbis *this, AkVPLState *io_state)
{
  AkVPLState *v2; // rdi
  CAkSrcBankVorbis *v3; // rbx
  char *v4; // rax
  bool v5; // zf
  int v6; // eax
  int v7; // eax
  __int16 *v8; // r9
  char *v9; // r8
  unsigned __int16 v10; // dx
  AKRESULT v11; // eax
  unsigned int v12; // er9
  unsigned __int16 v13; // r8

  v2 = io_state;
  v3 = this;
  if ( this->m_VorbisState.TremorInfo.pucData
    || (v4 = (char *)CAkLEngine::GetCachedAudioBuffer(this->m_VorbisState.TremorInfo.VorbisDSPState.channels << 11),
        v3->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced = 0,
        (v3->m_VorbisState.TremorInfo.pucData = v4) != 0i64) )
  {
    v5 = v3->m_uLoopCnt == 1;
    v3->m_VorbisState.TremorInfo.uRequestedFrames = v2->uMaxFrames;
    v6 = (int)v3->m_pucDataStart;
    if ( v5 )
      v7 = v3->m_uDataSize + v6;
    else
      v7 = v3->m_VorbisState.VorbisInfo.LoopInfo.dwLoopEndPacketOffset
         + v3->m_VorbisState.VorbisInfo.dwSeekTableSize
         + v6;
    v8 = (__int16 *)v3->m_VorbisState.TremorInfo.pucData;
    v9 = v3->m_pucData;
    v10 = v3->m_VorbisState.VorbisInfo.uMaxPacketSize;
    v3->m_VorbisState.TremorInfo.uInputDataSize = v7 - LODWORD(v3->m_pucData);
    v3->m_VorbisState.TremorInfo.bNoMoreInputPackets = 1;
    DecodeVorbis(&v3->m_VorbisState.TremorInfo, v10, v9, v8);
    v11 = v3->m_VorbisState.TremorInfo.ReturnInfo.eDecoderStatus;
    v2->result = v11;
    if ( v11 != 2 )
    {
      v12 = v3->m_VorbisState.uSampleRate;
      v13 = v3->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced;
      v3->m_pucData += v3->m_VorbisState.TremorInfo.ReturnInfo.uInputBytesConsumed;
      CAkSrcBaseEx::SubmitBufferAndUpdate(
        (CAkSrcBaseEx *)&v3->vfptr,
        v3->m_VorbisState.TremorInfo.pucData,
        v13,
        v12,
        v3->m_VorbisState.TremorInfo.uChannelMask,
        v2);
    }
  }
  else
  {
    v2->result = 2;
  }
}

// File Line: 95
// RVA: 0xABA9E0
void __fastcall CAkSrcBankVorbis::ReleaseBuffer(CAkSrcBankVorbis *this)
{
  char *v1; // rdx
  CAkSrcBankVorbis *v2; // rbx
  unsigned int v3; // er8
  int i; // ecx

  v1 = this->m_VorbisState.TremorInfo.pucData;
  v2 = this;
  if ( v1 )
  {
    v3 = this->m_VorbisState.TremorInfo.uChannelMask;
    for ( i = 0; v3; v3 &= v3 - 1 )
      ++i;
    CAkLEngine::ReleaseCachedAudioBuffer(i << 11, v1);
    v2->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced = 0;
    v2->m_VorbisState.TremorInfo.pucData = 0i64;
  }
}

// File Line: 106
// RVA: 0xABAB50
AKRESULT __usercall CAkSrcBankVorbis::StartStream@<eax>(CAkSrcBankVorbis *this@<rcx>, float a2@<xmm0>)
{
  CAkPBI *v2; // rax
  CAkSrcBankVorbis *v3; // rbx
  char *v4; // rsi
  unsigned int v5; // ebp
  AKRESULT result; // eax
  unsigned int *v7; // r13
  unsigned int *v8; // r12
  unsigned int *v9; // r14
  unsigned int *v10; // r15
  WaveFormatExtensible *v11; // rdi
  CAkPBI *v12; // rcx
  __int64 v13; // rdx
  signed __int64 v14; // rcx
  bool v15; // zf
  CAkPBI *v16; // rax
  AKRESULT v17; // edi
  unsigned int v18; // edx
  CAkPBI *v19; // rax
  AkFileParser::AnalysisDataChunk out_pAnalysisData; // [rsp+50h] [rbp-48h]
  AkFileParser::FormatInfo out_pFormatInfo; // [rsp+60h] [rbp-38h]
  AkAudioFormat v22; // [rsp+A0h] [rbp+8h]

  v2 = this->m_pCtx;
  v3 = this;
  v4 = v2->m_pDataPtr;
  v5 = v2->m_uDataSize;
  if ( !v4 )
    return 2;
  v7 = &this->m_uDataSize;
  v8 = &this->m_uPCMLoopStart;
  out_pAnalysisData.uDataSize = 0;
  out_pAnalysisData.pData = 0i64;
  v9 = &this->m_uPCMLoopEnd;
  v10 = &this->m_uDataOffset;
  result = AkFileParser::Parse(
             v4,
             v5,
             &out_pFormatInfo,
             &this->m_markers,
             &this->m_uPCMLoopStart,
             &this->m_uPCMLoopEnd,
             &this->m_uDataSize,
             &this->m_uDataOffset,
             &out_pAnalysisData,
             0i64);
  if ( result == 1 )
  {
    v11 = out_pFormatInfo.pFormat;
    if ( out_pFormatInfo.pFormat->wFormatTag == -1 )
    {
      v22.uSampleRate = out_pFormatInfo.pFormat->nSamplesPerSec;
      *((_DWORD *)&v22 + 1) = out_pFormatInfo.pFormat->dwChannelMask & 0x3FFFF | (out_pFormatInfo.pFormat->nChannels << 25) & 0x1F000000 | 0x400000;
      v12 = v3->m_pCtx;
      v12->m_sMediaFormat = v22;
      CAkPBI::InvalidateFeedbackParameters(v12);
      if ( out_pAnalysisData.uDataSize )
        v3->m_pAnalysisData = out_pAnalysisData.pData;
      v13 = *v10;
      v14 = (signed __int64)&v11[1];
      v3->m_pucDataStart = &v4[v13];
      v3->m_uTotalSamples = *(_DWORD *)&v11[1].wFormatTag;
      if ( v11 != (WaveFormatExtensible *)-24i64 )
        v14 = (signed __int64)&v11[1].nSamplesPerSec;
      v15 = *v9 == 0;
      *(_QWORD *)&v3->m_VorbisState.VorbisInfo.LoopInfo.dwLoopStartPacketOffset = *(_QWORD *)v14;
      *(_QWORD *)&v3->m_VorbisState.VorbisInfo.LoopInfo.uLoopBeginExtra = *(_QWORD *)(v14 + 8);
      *(_QWORD *)&v3->m_VorbisState.VorbisInfo.dwVorbisDataOffset = *(_QWORD *)(v14 + 16);
      *(_QWORD *)&v3->m_VorbisState.VorbisInfo.dwDecodeAllocSize = *(_QWORD *)(v14 + 24);
      v3->m_VorbisState.VorbisInfo.uHashCodebook = *(_DWORD *)(v14 + 32);
      *(_WORD *)v3->m_VorbisState.VorbisInfo.uBlockSizes = *(_WORD *)(v14 + 36);
      v3->m_VorbisState.uSampleRate = v11->nSamplesPerSec;
      v3->m_VorbisState.TremorInfo.uChannelMask = v11->dwChannelMask;
      if ( v15 )
        *v9 = v3->m_uTotalSamples - 1;
      if ( *v9 < *v8 || *v9 >= v3->m_uTotalSamples || v5 != (_DWORD)v13 + *v7 )
      {
        result = 2;
      }
      else
      {
        v16 = v3->m_pCtx;
        v3->m_pucData = &v4[v13];
        v3->m_uCurSample = 0;
        v3->m_uLoopCnt = v16->m_LoopCount;
        v17 = (unsigned int)CAkSrcBankVorbis::DecodeVorbisHeader(v3);
        if ( v17 == 1 )
        {
          LOWORD(v18) = 0;
          if ( *((_BYTE *)v3->m_pCtx + 375) & 2 )
          {
            v17 = (unsigned int)CAkSrcBankVorbis::SeekToNativeOffset(v3, a2);
            v19 = v3->m_pCtx;
            if ( *((_BYTE *)v19 + 375) & 2 )
              v18 = 0;
            else
              v18 = v19->m_uSeekPosition;
            *((_BYTE *)v19 + 375) &= 0xF1u;
            v19->m_uSeekPosition = 0;
            v3->m_uCurSample += v18;
          }
          CAkSrcBankVorbis::VorbisDSPRestart(v3, v18);
        }
        result = v17;
      }
    }
    else
    {
      result = 7;
    }
  }
  return result;
}

// File Line: 216
// RVA: 0xABAA30
signed __int64 __fastcall CAkSrcBankVorbis::RelocateMedia(CAkSrcBankVorbis *this, char *in_pNewMedia, char *in_pOldMedia)
{
  signed __int64 v3; // rdx
  signed __int64 result; // rax

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
  CAkSrcBankVorbis *v1; // rbx
  AkVorbisSeekTableItem *v2; // rdx

  v1 = this;
  vorbis_dsp_clear(&this->m_VorbisState.TremorInfo.VorbisDSPState);
  v1->vfptr->ReleaseBuffer((CAkVPLNode *)&v1->vfptr);
  v2 = v1->m_VorbisState.pSeekTable;
  if ( v2 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v2);
    v1->m_VorbisState.pSeekTable = 0i64;
  }
  CAkSrcBaseEx::StopStream((CAkSrcBaseEx *)&v1->vfptr);
}

// File Line: 240
// RVA: 0xABADC0
signed __int64 __fastcall CAkSrcBankVorbis::StopLooping(CAkSrcBankVorbis *this)
{
  this->m_VorbisState.TremorInfo.VorbisDSPState.state.extra_samples_end = this->m_VorbisState.VorbisInfo.uLastGranuleExtra;
  return CAkSrcBaseEx::StopLooping((CAkSrcBaseEx *)&this->vfptr);
}

// File Line: 247
// RVA: 0xABAE30
__int64 __usercall CAkSrcBankVorbis::VirtualOff@<rax>(CAkSrcBankVorbis *this@<rcx>, AkVirtualQueueBehavior eBehavior@<edx>, bool in_bUseSourceOffset@<r8b>, float a4@<xmm0>)
{
  AkVirtualQueueBehavior v4; // eax
  unsigned int v5; // edi
  CAkSrcBankVorbis *v6; // rbx
  AKRESULT v7; // eax
  CAkPBI *v8; // rax
  __int64 v9; // rax
  unsigned __int16 v10; // r8
  unsigned int out_uFileOffset; // [rsp+38h] [rbp+10h]

  v4 = eBehavior;
  v5 = 1;
  LOWORD(eBehavior) = 0;
  v6 = this;
  if ( v4 == 1 )
  {
    if ( in_bUseSourceOffset )
    {
      v7 = (unsigned int)CAkSrcBankVorbis::SeekToNativeOffset(this, a4);
    }
    else
    {
      if ( VorbisSeek(&this->m_VorbisState, this->m_uCurSample, &this->m_uCurSample, &out_uFileOffset) == 1 )
      {
        v6->m_pucData = &v6->m_pucDataStart[out_uFileOffset];
LABEL_8:
        v8 = v6->m_pCtx;
        if ( *((_BYTE *)v8 + 375) & 2 )
          eBehavior = 0;
        else
          eBehavior = v8->m_uSeekPosition;
        *((_BYTE *)v8 + 375) &= 0xF1u;
        v8->m_uSeekPosition = 0;
        v6->m_uCurSample += eBehavior;
        goto LABEL_14;
      }
      v6->m_uCurSample = 0;
      v7 = CAkSrcBankVorbis::VirtualSeek(v6, &v6->m_uCurSample);
    }
    v5 = v7;
    goto LABEL_8;
  }
  if ( v4 )
    return v5;
  v9 = this->m_VorbisState.VorbisInfo.dwVorbisDataOffset;
  this->m_uCurSample = 0;
  this->m_pucData = &this->m_pucDataStart[v9];
  this->m_uLoopCnt = this->m_pCtx->m_LoopCount;
LABEL_14:
  if ( v6->m_uLoopCnt == 1 )
    v10 = v6->m_VorbisState.VorbisInfo.uLastGranuleExtra;
  else
    v10 = v6->m_VorbisState.VorbisInfo.LoopInfo.uLoopEndExtra;
  vorbis_dsp_restart(&v6->m_VorbisState.TremorInfo.VorbisDSPState, eBehavior, v10);
  v6->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
  return v5;
}

// File Line: 295
// RVA: 0xABAF40
signed __int64 __fastcall CAkSrcBankVorbis::VirtualSeek(CAkSrcBankVorbis *this, unsigned int *io_uSeekPosition)
{
  CAkSrcBankVorbis *v2; // rbx
  unsigned int out_uFileOffset; // [rsp+30h] [rbp+8h]

  v2 = this;
  if ( VorbisSeek(&this->m_VorbisState, *io_uSeekPosition, io_uSeekPosition, &out_uFileOffset) != 1 )
    return 2i64;
  v2->m_pucData = &v2->m_pucDataStart[out_uFileOffset];
  return 1i64;
}

// File Line: 313
// RVA: 0xABA750
signed __int64 __fastcall CAkSrcBankVorbis::DecodeVorbisHeader(CAkSrcBankVorbis *this)
{
  unsigned int v1; // eax
  CAkSrcBankVorbis *v2; // rbx
  AkVorbisSeekTableItem *v3; // rax
  unsigned int v5; // eax
  unsigned __int16 *v6; // rdx
  CAkPBI *v7; // r8
  unsigned int v8; // ecx
  CAkVorbisAllocator *v9; // rax
  unsigned int v10; // ecx
  int v11; // edx
  ogg_packet op; // [rsp+20h] [rbp-28h]

  v1 = this->m_VorbisState.VorbisInfo.dwSeekTableSize;
  v2 = this;
  if ( v1 )
  {
    v3 = (AkVorbisSeekTableItem *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, v1);
    v2->m_VorbisState.pSeekTable = v3;
    if ( !v3 )
      return 52i64;
  }
  v5 = v2->m_VorbisState.VorbisInfo.dwSeekTableSize;
  v2->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 1;
  if ( v5 )
  {
    memmove(v2->m_VorbisState.pSeekTable, v2->m_pucData, v5);
    v2->m_pucData += v2->m_VorbisState.VorbisInfo.dwSeekTableSize;
  }
  v6 = (unsigned __int16 *)v2->m_pucData;
  v7 = v2->m_pCtx;
  v8 = *v6;
  op.e_o_s = 0;
  op.buffer.size = v8;
  op.buffer.data = (char *)(v6 + 1);
  v2->m_pucData = (char *)v6 + v8 + 2;
  v9 = AkVorbisCodebookMgr::Decodebook(&g_VorbisCodebookMgr, &v2->m_VorbisState, v7, &op);
  if ( !v9 )
    return 2i64;
  v10 = v2->m_VorbisState.TremorInfo.uChannelMask;
  v11 = 0;
  for ( v2->m_VorbisState.TremorInfo.VorbisDSPState.csi = (codec_setup_info *)v9->pStartAddress; v10; v10 &= v10 - 1 )
    ++v11;
  if ( vorbis_dsp_init(&v2->m_VorbisState.TremorInfo.VorbisDSPState, v11) )
    return 2i64;
  v2->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
  return 1i64;
}

// File Line: 409
// RVA: 0xABAA50
signed __int64 __usercall CAkSrcBankVorbis::SeekToNativeOffset@<rax>(CAkSrcBankVorbis *this@<rcx>, float a2@<xmm0>)
{
  CAkSrcBankVorbis *v2; // rbx
  unsigned __int64 v4; // r9
  unsigned int v5; // ecx
  unsigned int v6; // er8
  AkVorbisSeekTableItem *v7; // rdx
  unsigned int v8; // er11
  int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // er10
  unsigned int v12; // ecx
  int v13; // eax
  CAkPBI *v14; // rax

  v2 = this;
  if ( !this->m_VorbisState.pSeekTable )
    return 2i64;
  v4 = (unsigned int)CAkSrcBaseEx::GetSourceOffset((CAkSrcBaseEx *)&this->vfptr, a2);
  if ( v4 >= v2->m_uTotalSamples )
    return 2i64;
  if ( !(_DWORD)v4 )
  {
    v5 = v2->m_VorbisState.VorbisInfo.dwVorbisDataOffset;
    v6 = 0;
LABEL_14:
    v2->m_uCurSample = v6;
    v2->m_pucData = &v2->m_pucDataStart[v5];
    v14 = v2->m_pCtx;
    *((_BYTE *)v14 + 375) &= 0xF1u;
    v14->m_uSeekPosition = v4 - v6;
    return 1i64;
  }
  v7 = v2->m_VorbisState.pSeekTable;
  v8 = v2->m_VorbisState.VorbisInfo.dwSeekTableSize >> 2;
  if ( v7 && v8 )
  {
    v6 = 0;
    v9 = 0;
    v10 = 0;
    v11 = 0;
    if ( !v8 )
      goto LABEL_18;
    do
    {
      v12 = v10 + v7->uPacketFrameOffset;
      if ( v12 > (unsigned int)v4 )
        break;
      v13 = v7->uPacketFileOffset;
      ++v11;
      ++v7;
      v9 += v13;
      v10 = v12;
    }
    while ( v11 < v8 );
    if ( v11 )
    {
      v5 = v2->m_VorbisState.VorbisInfo.dwSeekTableSize + v9;
      v6 = v10;
    }
    else
    {
LABEL_18:
      v5 = v2->m_VorbisState.VorbisInfo.dwVorbisDataOffset;
    }
    goto LABEL_14;
  }
  return 2i64;
}

// File Line: 440
// RVA: 0xABA650
__int64 __fastcall CAkSrcBankVorbis::ChangeSourcePosition(CAkSrcBankVorbis *this)
{
  CAkSrcBankVorbis *v1; // rbx
  AKRESULT v2; // eax
  CAkPBI *v3; // rcx
  AKRESULT v4; // edi
  unsigned int v5; // edx
  unsigned __int16 v6; // r8

  v1 = this;
  v2 = CAkSrcBankVorbis::SeekToNativeOffset(this);
  v3 = v1->m_pCtx;
  v4 = v2;
  if ( *((_BYTE *)v3 + 375) & 2 )
    v5 = 0;
  else
    v5 = v3->m_uSeekPosition;
  *((_BYTE *)v3 + 375) &= 0xF1u;
  v3->m_uSeekPosition = 0;
  v1->m_uCurSample += v5;
  if ( v1->m_uLoopCnt == 1 )
    v6 = v1->m_VorbisState.VorbisInfo.uLastGranuleExtra;
  else
    v6 = v1->m_VorbisState.VorbisInfo.LoopInfo.uLoopEndExtra;
  vorbis_dsp_restart(&v1->m_VorbisState.TremorInfo.VorbisDSPState, v5, v6);
  v1->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
  return (unsigned int)v4;
}

// File Line: 461
// RVA: 0xABA950
__int64 __fastcall CAkSrcBankVorbis::OnLoopComplete(CAkSrcBankVorbis *this, bool in_bEndOfFile)
{
  unsigned __int16 v2; // ax
  CAkSrcBankVorbis *v3; // rbx
  unsigned int v4; // edi
  bool v5; // zf
  unsigned __int16 v6; // r8

  v2 = this->m_uLoopCnt;
  v3 = this;
  if ( v2 > 1u )
    this->m_uLoopCnt = v2 - 1;
  v4 = 45;
  if ( in_bEndOfFile )
    v4 = 17;
  if ( !in_bEndOfFile )
  {
    v5 = this->m_uLoopCnt == 1;
    this->m_pucData = &this->m_pucDataStart[this->m_VorbisState.VorbisInfo.LoopInfo.dwLoopStartPacketOffset
                                          + (unsigned __int64)this->m_VorbisState.VorbisInfo.dwSeekTableSize];
    if ( v5 )
      v6 = this->m_VorbisState.VorbisInfo.uLastGranuleExtra;
    else
      v6 = this->m_VorbisState.VorbisInfo.LoopInfo.uLoopEndExtra;
    vorbis_dsp_restart(
      &this->m_VorbisState.TremorInfo.VorbisDSPState,
      this->m_VorbisState.VorbisInfo.LoopInfo.uLoopBeginExtra,
      v6);
    v3->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
    v3->m_VorbisState.TremorInfo.ReturnInfo.eDecoderStatus = 45;
  }
  return v4;
}

