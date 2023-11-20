// File Line: 26
// RVA: 0xABB230
CAkSrcFileBase *__fastcall CreateVorbisFilePlugin(void *in_pCtx)
{
  CAkPBI *v1; // rdi
  CAkSrcFileBase *result; // rax
  IAkSoftwareCodec *v3; // rbx

  v1 = (CAkPBI *)in_pCtx;
  result = (CAkSrcFileBase *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x1C8ui64);
  v3 = (IAkSoftwareCodec *)&result->vfptr;
  if ( result )
  {
    CAkSrcFileBase::CAkSrcFileBase(result, v1);
    v3->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFileVorbis::`vftable';
    v3[26].m_pInput = 0i64;
    v3[27].vfptr = 0i64;
    v3[27].m_pInput = 0i64;
    v3[28].vfptr = 0i64;
    memset(&v3[8], 0, 0x128ui64);
    result = (CAkSrcFileBase *)v3;
  }
  return result;
}

// File Line: 48
// RVA: 0xABB0B0
void __fastcall CAkSrcFileVorbis::~CAkSrcFileVorbis(CAkSrcFileVorbis *this)
{
  char *v1; // rdx
  CAkSrcFileVorbis *v2; // rbx
  unsigned int v3; // er8
  int i; // ecx

  v1 = this->m_VorbisState.TremorInfo.pucData;
  v2 = this;
  this->vfptr = (CAkVPLNodeVtbl *)&CAkSrcFileVorbis::`vftable';
  if ( v1 )
  {
    v3 = this->m_VorbisState.TremorInfo.uChannelMask;
    for ( i = 0; v3; v3 &= v3 - 1 )
      ++i;
    CAkLEngine::ReleaseCachedAudioBuffer(i << 11, v1);
    v2->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced = 0;
    v2->m_VorbisState.TremorInfo.pucData = 0i64;
  }
  if ( v2->m_VorbisState.TremorInfo.VorbisDSPState.csi )
    AkVorbisCodebookMgr::ReleaseCodebook(&g_VorbisCodebookMgr, &v2->m_VorbisState);
  CAkSrcFileBase::~CAkSrcFileBase((CAkSrcFileBase *)&v2->vfptr);
}

// File Line: 56
// RVA: 0xABB4A0
void __fastcall CAkSrcFileVorbis::GetBuffer(CAkSrcFileVorbis *this, AkVPLState *io_state)
{
  AkVPLState *v2; // rsi
  CAkSrcFileVorbis *v3; // rbx
  AKRESULT v4; // eax
  __int64 v5; // rdx
  unsigned __int64 v6; // rcx
  char *v7; // rcx
  unsigned __int16 v8; // ax
  size_t v9; // r8
  char *v10; // rdx
  unsigned int v11; // et1
  char v12; // al
  unsigned int v13; // eax
  char *v14; // rdx
  __int64 v15; // rcx
  unsigned __int64 v16; // rdi
  char *v17; // rax
  char v18; // dl
  bool v19; // al
  char *v20; // r9
  unsigned int v21; // ecx
  int v22; // eax
  unsigned __int16 v23; // dx
  unsigned __int16 v24; // cx
  unsigned __int16 v25; // cx
  unsigned __int16 v26; // ax
  unsigned int v27; // ecx
  __int16 *v28; // r9
  char *v29; // r8
  unsigned __int16 v30; // dx
  __int64 v31; // rcx

  v2 = io_state;
  v3 = this;
  if ( *((_BYTE *)&this->0 + 32) & 2 )
  {
    v4 = (unsigned int)AK::SrcFileServices::IsPrebufferingReady(this->m_pStream, this->m_ulSizeLeft);
    if ( v4 != 45 )
    {
      v2->result = v4;
      return;
    }
    *((_BYTE *)&v3->0 + 32) &= 0xFDu;
  }
  v5 = v3->m_VorbisState.VorbisInfo.uMaxPacketSize;
  v6 = v3->m_ulSizeLeft;
  v3->m_VorbisState.TremorInfo.uRequestedFrames = v2->uMaxFrames;
  if ( v6 < v5 + 2 && !(*((_BYTE *)&v3->0 + 126) & 1) )
  {
    if ( (_DWORD)v6 && !v3->m_pStitchStreamBuffer && !v3->m_uStreamLoopCntAhead )
    {
      v7 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, v6 + v5 + 2);
      v3->m_pStitchStreamBuffer = v7;
      if ( !v7 )
      {
LABEL_10:
        v2->result = 2;
        return;
      }
      v8 = v3->m_ulSizeLeft;
      v9 = v3->m_ulSizeLeft;
      v10 = v3->m_pNextAddress;
      v3->m_uStitchBufferEndOffset = v8;
      v3->m_uStitchBufferLeft = v8;
      v3->m_uStitchBufferValidDataSize = v8;
      memmove(v7, v10, v9);
      v11 = v3->m_ulSizeLeft;
      v3->m_pNextAddress = 0i64;
      v3->m_ulSizeLeft = 0;
    }
    if ( !v3->m_ulSizeLeft )
    {
      v12 = *((_BYTE *)&v3->0 + 126);
      if ( v12 & 2 )
        *((_BYTE *)&v3->0 + 126) = v12 & 0xFD;
      else
        ((void (*)(void))v3->m_pStream->vfptr->ReleaseBuffer)();
      v13 = CAkSrcFileBase::FetchStreamBuffer((CAkSrcFileBase *)&v3->vfptr);
      v2->result = v13;
      if ( v13 == 2 )
        return;
      if ( v13 == 45 )
      {
        v14 = v3->m_pStitchStreamBuffer;
        if ( v14 )
        {
          v15 = v3->m_VorbisState.VorbisInfo.uMaxPacketSize;
          v16 = v3->m_ulSizeLeft;
          if ( v15 + 2 < v16 )
            LODWORD(v16) = v15 + 2;
          memmove(&v14[v3->m_uStitchBufferEndOffset], v3->m_pNextAddress, (unsigned int)v16);
          v3->m_uStitchBufferLeft += v16;
          v3->m_uStitchBufferValidDataSize += v16;
        }
      }
    }
  }
  if ( !v3->m_VorbisState.TremorInfo.pucData )
  {
    v17 = (char *)CAkLEngine::GetCachedAudioBuffer(v3->m_VorbisState.TremorInfo.VorbisDSPState.channels << 11);
    v3->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced = 0;
    v3->m_VorbisState.TremorInfo.pucData = v17;
    if ( !v17 )
      goto LABEL_10;
  }
  v18 = 1;
  v19 = v3->m_uStreamLoopCntAhead || *((_BYTE *)&v3->0 + 126) & 1;
  v20 = v3->m_pStitchStreamBuffer;
  v3->m_VorbisState.TremorInfo.bNoMoreInputPackets = v19;
  if ( v20 )
  {
    if ( !v19 || v3->m_ulSizeLeft + v3->m_uStitchBufferEndOffset - v3->m_uStitchBufferValidDataSize )
      v18 = 0;
    v21 = v3->m_uStitchBufferLeft;
    v22 = v3->m_uStitchBufferValidDataSize;
    v3->m_VorbisState.TremorInfo.bNoMoreInputPackets = v18;
    v23 = v3->m_VorbisState.VorbisInfo.uMaxPacketSize;
    v3->m_VorbisState.TremorInfo.uInputDataSize = v21;
    DecodeVorbis(&v3->m_VorbisState.TremorInfo, v23, &v20[v22 - v21], (__int16 *)v3->m_VorbisState.TremorInfo.pucData);
    v24 = v3->m_uStitchBufferValidDataSize;
    v3->m_uStitchBufferLeft -= LOWORD(v3->m_VorbisState.TremorInfo.ReturnInfo.uInputBytesConsumed);
    v25 = v24 - v3->m_uStitchBufferLeft;
    v26 = v3->m_uStitchBufferEndOffset;
    if ( v25 >= v26 )
    {
      v27 = v25 - v26;
      v3->m_ulSizeLeft -= v27;
      v3->m_pNextAddress += v27;
      CAkSrcFileVorbis::FreeStitchBuffer(v3);
    }
  }
  else
  {
    v28 = (__int16 *)v3->m_VorbisState.TremorInfo.pucData;
    v29 = v3->m_pNextAddress;
    v30 = v3->m_VorbisState.VorbisInfo.uMaxPacketSize;
    v3->m_VorbisState.TremorInfo.uInputDataSize = v3->m_ulSizeLeft;
    DecodeVorbis(&v3->m_VorbisState.TremorInfo, v30, v29, v28);
    v31 = v3->m_VorbisState.TremorInfo.ReturnInfo.uInputBytesConsumed;
    v3->m_pNextAddress += v31;
    v3->m_ulSizeLeft -= v31;
  }
  CAkSrcFileVorbis::SubmitBufferAndUpdateVorbis(v3, v2);
}

// File Line: 170
// RVA: 0xABC040
void __fastcall CAkSrcFileVorbis::SubmitBufferAndUpdateVorbis(CAkSrcFileVorbis *this, AkVPLState *io_state)
{
  AKRESULT v2; // eax
  AkVPLState *v3; // rdi
  CAkSrcFileVorbis *v4; // rbx
  signed int v5; // eax

  v2 = this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderStatus;
  v3 = io_state;
  v4 = this;
  io_state->result = v2;
  if ( v2 != 2 )
  {
    CAkSrcBaseEx::SubmitBufferAndUpdate(
      (CAkSrcBaseEx *)&this->vfptr,
      this->m_VorbisState.TremorInfo.pucData,
      this->m_VorbisState.TremorInfo.ReturnInfo.uFramesProduced,
      this->m_VorbisState.uSampleRate,
      this->m_VorbisState.TremorInfo.uChannelMask,
      io_state);
    if ( v3->result == 46 )
    {
      if ( v4->m_pNextAddress )
      {
        v5 = 2;
        if ( v4->m_VorbisState.TremorInfo.ReturnInfo.uInputBytesConsumed )
          v5 = 45;
        v3->result = v5;
      }
    }
  }
}

// File Line: 216
// RVA: 0xABB920
__int64 __fastcall CAkSrcFileVorbis::OnLoopComplete(CAkSrcFileVorbis *this, bool in_bEndOfFile)
{
  CAkSrcFileVorbis *v2; // rbx
  unsigned __int16 v3; // ax
  unsigned int v4; // edi
  unsigned __int16 v5; // r8

  v2 = this;
  if ( !in_bEndOfFile )
    --this->m_uStreamLoopCntAhead;
  v3 = this->m_uLoopCnt;
  if ( v3 > 1u )
    this->m_uLoopCnt = v3 - 1;
  v4 = 45;
  if ( in_bEndOfFile )
    v4 = 17;
  if ( !in_bEndOfFile )
  {
    if ( this->m_uLoopCnt == 1 )
      v5 = this->m_VorbisState.VorbisInfo.uLastGranuleExtra;
    else
      v5 = this->m_VorbisState.VorbisInfo.LoopInfo.uLoopEndExtra;
    vorbis_dsp_restart(
      &this->m_VorbisState.TremorInfo.VorbisDSPState,
      this->m_VorbisState.VorbisInfo.LoopInfo.uLoopBeginExtra,
      v5);
    v2->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
    v2->m_VorbisState.TremorInfo.ReturnInfo.eDecoderStatus = 45;
  }
  return v4;
}

// File Line: 232
// RVA: 0xABBDE0
void __fastcall CAkSrcFileVorbis::ReleaseBuffer(CAkSrcFileVorbis *this)
{
  char *v1; // rdx
  CAkSrcFileVorbis *v2; // rbx
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

// File Line: 243
// RVA: 0xABBE40
signed __int64 __usercall CAkSrcFileVorbis::StartStream@<rax>(CAkSrcFileVorbis *this@<rcx>, float a2@<xmm0>)
{
  CAkSrcFileVorbis *v2; // rdi
  unsigned int v3; // edx
  AK::IAkAutoStream *v4; // rcx
  signed __int64 result; // rax
  unsigned int v6; // ebx
  unsigned int v7; // ebx
  CAkPBI *v8; // rax
  AkAutoStmBufSettings in_bufSettings; // [rsp+20h] [rbp-18h]
  bool out_bUsePrefetchedData; // [rsp+40h] [rbp+8h]

  v2 = this;
  if ( *((_BYTE *)&this->0 + 126) & 4 )
  {
    if ( *((_BYTE *)&this->0 + 32) & 2 )
    {
      v3 = this->m_ulSizeLeft;
      v4 = this->m_pStream;
      goto LABEL_14;
    }
    return 1i64;
  }
  if ( !this->m_pStream || this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState >= 3 )
  {
    in_bufSettings.uBufferSize = 0;
    *(_QWORD *)&in_bufSettings.uMinBufferSize = 2048i64;
    result = CAkSrcFileBase::CreateStream((CAkSrcFileBase *)&this->vfptr, &in_bufSettings, 0);
    if ( (_DWORD)result != 1 )
      return result;
    v6 = CAkSrcFileBase::HandlePrefetch((CAkSrcFileBase *)&v2->vfptr, &out_bUsePrefetchedData);
    if ( v6 != 1 )
      return v6;
    result = ((__int64 (*)(void))v2->m_pStream->vfptr->Start)();
    if ( (_DWORD)result != 1 )
      return result;
    if ( out_bUsePrefetchedData )
    {
      v8 = v2->m_pCtx;
      v2->m_uCurSample = 0;
      v2->m_uLoopCnt = v8->m_LoopCount;
      result = CAkSrcFileVorbis::DecodeVorbisHeader(v2);
      v6 = result;
      if ( (_DWORD)result != 1 )
        return result;
      CAkSrcFileVorbis::VorbisDSPRestart(v2, 0);
      return v6;
    }
    this = v2;
  }
  v6 = CAkSrcFileVorbis::ProcessFirstBuffer(this, a2);
  if ( v6 != 1 )
    return v6;
  if ( !(*((_BYTE *)&v2->0 + 32) & 2) )
    return 1i64;
  v3 = v2->m_ulSizeLeft;
  v4 = v2->m_pStream;
LABEL_14:
  v7 = AK::SrcFileServices::IsPrebufferingReady(v4, v3);
  if ( v7 == 46 )
    return 63i64;
  if ( v7 == 45 )
    v7 = 1;
  return v7;
}

// File Line: 306
// RVA: 0xABBFA0
void __fastcall CAkSrcFileVorbis::StopStream(CAkSrcFileVorbis *this)
{
  CAkSrcFileVorbis *v1; // rbx
  AkVorbisSeekTableItem *v2; // rdx
  char *v3; // rdx
  char *v4; // rdx

  v1 = this;
  vorbis_dsp_clear(&this->m_VorbisState.TremorInfo.VorbisDSPState);
  v1->vfptr->ReleaseBuffer((CAkVPLNode *)&v1->vfptr);
  v2 = v1->m_VorbisState.pSeekTable;
  if ( v2 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v2);
    v1->m_VorbisState.pSeekTable = 0i64;
  }
  v3 = v1->m_pStitchStreamBuffer;
  if ( v3 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v3);
    v1->m_pStitchStreamBuffer = 0i64;
    *(_DWORD *)&v1->m_uStitchBufferEndOffset = 0;
    v1->m_uStitchBufferLeft = 0;
  }
  v4 = v1->m_pOggPacketData;
  if ( v4 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v4);
    v1->m_pOggPacketData = 0i64;
  }
  CAkSrcFileBase::StopStream((CAkSrcFileBase *)&v1->vfptr);
}

// File Line: 336
// RVA: 0xABBF80
signed __int64 __fastcall CAkSrcFileVorbis::StopLooping(CAkSrcFileVorbis *this)
{
  if ( !this->m_uStreamLoopCntAhead )
    this->m_VorbisState.TremorInfo.VorbisDSPState.state.extra_samples_end = this->m_VorbisState.VorbisInfo.uLastGranuleExtra;
  return CAkSrcFileBase::StopLooping((CAkSrcFileBase *)&this->vfptr);
}

// File Line: 348
// RVA: 0xABC150
void __fastcall CAkSrcFileVorbis::VirtualOn(CAkSrcFileVorbis *this, AkVirtualQueueBehavior eBehavior)
{
  AkVirtualQueueBehavior v2; // ebx
  CAkSrcFileVorbis *v3; // rdi
  char *v4; // rdx

  v2 = eBehavior;
  v3 = this;
  CAkSrcFileBase::VirtualOn((CAkSrcFileBase *)&this->vfptr, eBehavior);
  if ( (unsigned int)v2 <= 1 )
  {
    v4 = v3->m_pStitchStreamBuffer;
    if ( v4 )
    {
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v4);
      v3->m_pStitchStreamBuffer = 0i64;
      *(_DWORD *)&v3->m_uStitchBufferEndOffset = 0;
      v3->m_uStitchBufferLeft = 0;
    }
  }
}

// File Line: 359
// RVA: 0xABC0C0
signed __int64 __usercall CAkSrcFileVorbis::VirtualOff@<rax>(CAkSrcFileVorbis *this@<rcx>, __int64 eBehavior@<rdx>, bool in_bUseSourceOffset@<r8b>, float a4@<xmm0>)
{
  unsigned int v4; // ebx
  CAkSrcFileVorbis *v5; // rdi
  signed __int64 result; // rax
  unsigned int v7; // esi
  CAkPBI *v8; // rcx
  unsigned int v9; // edx
  unsigned __int16 v10; // r8

  v4 = eBehavior;
  v5 = this;
  result = CAkSrcFileBase::VirtualOff((CAkSrcFileBase *)&this->vfptr, eBehavior, in_bUseSourceOffset, a4);
  v7 = result;
  if ( v4 <= 1 )
  {
    v8 = v5->m_pCtx;
    if ( *((_BYTE *)v8 + 375) & 2 )
      v9 = 0;
    else
      v9 = v8->m_uSeekPosition;
    *((_BYTE *)v8 + 375) &= 0xF1u;
    v8->m_uSeekPosition = 0;
    v5->m_uCurSample += v9;
    if ( v5->m_uLoopCnt == 1 )
      v10 = v5->m_VorbisState.VorbisInfo.uLastGranuleExtra;
    else
      v10 = v5->m_VorbisState.VorbisInfo.LoopInfo.uLoopEndExtra;
    vorbis_dsp_restart(&v5->m_VorbisState.TremorInfo.VorbisDSPState, v9, v10);
    v5->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
    result = v7;
  }
  return result;
}

// File Line: 380
// RVA: 0xABB2C0
signed __int64 __fastcall CAkSrcFileVorbis::DecodeVorbisHeader(CAkSrcFileVorbis *this)
{
  AkVorbisDecoderState v1; // eax
  CAkSrcFileVorbis *v2; // rbx
  unsigned int v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // esi
  unsigned int v6; // esi
  unsigned int v7; // er8
  int v8; // edi
  int i; // edx
  signed __int64 result; // rax
  AKRESULT v11; // eax
  CAkVorbisAllocator *v12; // rax
  char *v13; // rax
  ogg_packet out_OggPacket; // [rsp+20h] [rbp-28h]

  v1 = this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState;
  v2 = this;
  if ( (signed int)v1 >= 3 )
  {
LABEL_11:
    v7 = v2->m_VorbisState.TremorInfo.uChannelMask;
    v8 = 0;
    for ( i = 0; v7; v7 &= v7 - 1 )
      ++i;
    LOBYTE(v8) = vorbis_dsp_init(&v2->m_VorbisState.TremorInfo.VorbisDSPState, i) != 0;
    result = (unsigned int)(v8 + 1);
  }
  else
  {
    while ( 1 )
    {
      v3 = v2->m_ulSizeLeft;
      if ( !v3 )
        return 63i64;
      if ( (signed int)v1 < 2 )
      {
        v4 = v2->m_VorbisState.uSeekTableSizeRead;
        v5 = v2->m_VorbisState.VorbisInfo.dwSeekTableSize;
        if ( v4 < v5 )
        {
          v6 = v5 - v4;
          if ( v3 < v6 )
            v6 = v2->m_ulSizeLeft;
          memmove((char *)v2->m_VorbisState.pSeekTable + v4, v2->m_pNextAddress, v6);
          v2->m_VorbisState.uSeekTableSizeRead += v6;
          v2->m_pNextAddress += v6;
          v2->m_ulSizeLeft -= v6;
        }
        if ( v2->m_VorbisState.uSeekTableSizeRead == v2->m_VorbisState.VorbisInfo.dwSeekTableSize )
          break;
      }
      v1 = v2->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState;
      if ( v1 == 2 )
        goto LABEL_15;
      if ( (signed int)v1 >= 3 )
        goto LABEL_11;
    }
    v2->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 2;
LABEL_15:
    v11 = CAkSrcFileVorbis::GetNextPacket(v2, &out_OggPacket);
    if ( v11 == 46 )
      return 63i64;
    if ( v11 != 2 && v11 != 17 && v11 != 52 )
    {
      v12 = AkVorbisCodebookMgr::Decodebook(&g_VorbisCodebookMgr, &v2->m_VorbisState, v2->m_pCtx, &out_OggPacket);
      if ( v12 )
      {
        v13 = v12->pStartAddress;
        v2->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
        v2->m_VorbisState.TremorInfo.VorbisDSPState.csi = (codec_setup_info *)v13;
        goto LABEL_11;
      }
    }
    result = 2i64;
  }
  return result;
}

// File Line: 483
// RVA: 0xABBC20
signed __int64 __usercall CAkSrcFileVorbis::ProcessFirstBuffer@<rax>(CAkSrcFileVorbis *this@<rcx>, float a2@<xmm0>)
{
  CAkSrcFileVorbis *v2; // rbx
  AKRESULT v3; // eax
  signed __int64 result; // rax
  CAkPBI *v5; // rax
  char *v6; // rdx
  __int64 v7; // rcx
  unsigned int v8; // eax
  unsigned int v9; // edi
  char v10; // al
  unsigned int v11; // ecx
  char v12; // al
  CAkPBI *v13; // rax
  char *in_pBuffer; // [rsp+30h] [rbp+8h]

  v2 = this;
  *((_BYTE *)&this->0 + 32) ^= (*((_BYTE *)&this->0 + 32) ^ (*((_BYTE *)this->m_pCtx + 374) >> 4)) & 2;
  v3 = (unsigned int)this->m_pStream->vfptr->GetBuffer(this->m_pStream, (void **)&in_pBuffer, &this->m_ulSizeLeft, 0);
  if ( v3 == 46 )
    return 63i64;
  if ( v3 != 45 && v3 != 17 )
    return 2i64;
  if ( v2->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState )
  {
    result = CAkSrcFileBase::ProcessStreamBuffer((CAkSrcFileBase *)&v2->vfptr, in_pBuffer, 0);
    if ( (_DWORD)result != 1 )
      return result;
  }
  else
  {
    result = ((__int64 (__fastcall *)(CAkSrcFileVorbis *, char *))v2->vfptr[2].VirtualOff)(v2, in_pBuffer);
    if ( (_DWORD)result != 1 )
      return result;
    v5 = v2->m_pCtx;
    v6 = in_pBuffer;
    v2->m_uCurSample = 0;
    v2->m_uLoopCnt = v5->m_LoopCount;
    result = CAkSrcFileBase::ProcessStreamBuffer((CAkSrcFileBase *)&v2->vfptr, v6, 0);
    if ( (_DWORD)result != 1 )
      return result;
    v7 = v2->m_uDataOffset;
    v2->m_pNextAddress += v7;
    v2->m_ulSizeLeft -= v7;
  }
  v8 = CAkSrcFileVorbis::DecodeVorbisHeader(v2);
  v9 = v8;
  if ( v8 == 1 )
  {
    LOWORD(v11) = 0;
    if ( *((_BYTE *)v2->m_pCtx + 375) & 2 )
    {
      v9 = CAkSrcFileBase::SeekToSourceOffset((CAkSrcFileBase *)&v2->vfptr, a2);
      if ( v2->m_ulSizeLeft )
      {
        v12 = *((_BYTE *)&v2->0 + 126);
        if ( v12 & 2 )
          *((_BYTE *)&v2->0 + 126) = v12 & 0xFD;
        else
          ((void (*)(void))v2->m_pStream->vfptr->ReleaseBuffer)();
        v2->m_pNextAddress = 0i64;
        v2->m_ulSizeLeft = 0;
      }
      v13 = v2->m_pCtx;
      if ( *((_BYTE *)v13 + 375) & 2 )
        v11 = 0;
      else
        v11 = v13->m_uSeekPosition;
      *((_BYTE *)v13 + 375) &= 0xF1u;
      v13->m_uSeekPosition = 0;
      v2->m_uCurSample += v11;
    }
    CAkSrcFileVorbis::VorbisDSPRestart(v2, v11);
    *((_BYTE *)&v2->0 + 126) |= 4u;
  }
  else if ( v8 == 63 && !v2->m_ulSizeLeft )
  {
    v10 = *((_BYTE *)&v2->0 + 126);
    if ( v10 & 2 )
    {
      v2->m_pNextAddress = 0i64;
      *((_BYTE *)&v2->0 + 126) = v10 & 0xFD;
    }
    else
    {
      ((void (*)(void))v2->m_pStream->vfptr->ReleaseBuffer)();
      v2->m_pNextAddress = 0i64;
    }
  }
  return v9;
}

// File Line: 577
// RVA: 0xABB9B0
unsigned int __fastcall CAkSrcFileVorbis::ParseHeader(CAkSrcFileVorbis *this, char *in_pBuffer)
{
  CAkSrcFileVorbis *v2; // rbx
  unsigned int *v3; // r15
  unsigned int *v4; // rbp
  unsigned int *v5; // r14
  unsigned int *v6; // r12
  signed __int64 v7; // rsi
  char *v8; // rax
  unsigned int v9; // edx
  unsigned int result; // eax
  _DWORD *v11; // rdi
  CAkPBI *v12; // rcx
  bool v13; // zf
  unsigned int v14; // edx
  unsigned int v15; // ecx
  CAkPBI *v16; // rax
  unsigned int v17; // eax
  AkVorbisSeekTableItem *v18; // rax
  AK::IAkAutoStream *v19; // rcx
  int v20; // edx
  AkFileParser::AnalysisDataChunk in_analysisDataChunk; // [rsp+50h] [rbp-58h]
  AkAutoStmHeuristics io_heuristics; // [rsp+60h] [rbp-48h]
  __int64 v23; // [rsp+70h] [rbp-38h]
  __int64 v24; // [rsp+78h] [rbp-30h]
  AkAudioFormat v25; // [rsp+B0h] [rbp+8h]

  v2 = this;
  v3 = &this->m_uDataOffset;
  v4 = &this->m_uDataSize;
  v5 = &this->m_uPCMLoopEnd;
  v6 = &this->m_uPCMLoopStart;
  v7 = 0i64;
  v8 = in_pBuffer;
  v9 = this->m_ulSizeLeft;
  in_analysisDataChunk.uDataSize = 0;
  in_analysisDataChunk.pData = 0i64;
  result = AkFileParser::Parse(
             v8,
             v9,
             (AkFileParser::FormatInfo *)&v23,
             &this->m_markers,
             &this->m_uPCMLoopStart,
             &this->m_uPCMLoopEnd,
             &this->m_uDataSize,
             &this->m_uDataOffset,
             &in_analysisDataChunk,
             0i64);
  if ( result == 1 )
  {
    v11 = (_DWORD *)v24;
    if ( *(_WORD *)v24 == -1 )
    {
      v25.uSampleRate = *(_DWORD *)(v24 + 4);
      *((_DWORD *)&v25 + 1) = *(_DWORD *)(v24 + 20) & 0x3FFFF | (*(unsigned __int16 *)(v24 + 2) << 25) & 0x1F000000 | 0x400000;
      v12 = v2->m_pCtx;
      v12->m_sMediaFormat = v25;
      CAkPBI::InvalidateFeedbackParameters(v12);
      if ( in_analysisDataChunk.uDataSize > 0 )
        CAkSrcFileBase::StoreAnalysisData((CAkSrcFileBase *)&v2->vfptr, &in_analysisDataChunk);
      v2->m_uTotalSamples = v11[6];
      if ( v11 != (_DWORD *)-24i64 )
        v7 = (signed __int64)(v11 + 7);
      v13 = *v6 == 0;
      *(_QWORD *)&v2->m_VorbisState.VorbisInfo.LoopInfo.dwLoopStartPacketOffset = *(_QWORD *)v7;
      *(_QWORD *)&v2->m_VorbisState.VorbisInfo.LoopInfo.uLoopBeginExtra = *(_QWORD *)(v7 + 8);
      *(_QWORD *)&v2->m_VorbisState.VorbisInfo.dwVorbisDataOffset = *(_QWORD *)(v7 + 16);
      *(_QWORD *)&v2->m_VorbisState.VorbisInfo.dwDecodeAllocSize = *(_QWORD *)(v7 + 24);
      v2->m_VorbisState.VorbisInfo.uHashCodebook = *(_DWORD *)(v7 + 32);
      *(_WORD *)v2->m_VorbisState.VorbisInfo.uBlockSizes = *(_WORD *)(v7 + 36);
      v2->m_VorbisState.TremorInfo.uChannelMask = v11[5];
      v2->m_VorbisState.uSampleRate = v11[1];
      if ( v13 && !*v5 )
        *v5 = v2->m_uTotalSamples - 1;
      if ( v2->m_uLoopCnt == 1 )
      {
        v2->m_ulLoopStart = *v3 + v2->m_VorbisState.VorbisInfo.dwVorbisDataOffset;
        v2->m_ulLoopEnd = *v3 + *v4;
      }
      else
      {
        v14 = v2->m_VorbisState.VorbisInfo.dwSeekTableSize;
        v15 = *v3;
        v2->m_ulLoopStart = v2->m_VorbisState.VorbisInfo.LoopInfo.dwLoopStartPacketOffset + *v3 + v14;
        v2->m_ulLoopEnd = v14 + v15 + v2->m_VorbisState.VorbisInfo.LoopInfo.dwLoopEndPacketOffset;
      }
      v2->m_pStream->vfptr->GetHeuristics(v2->m_pStream, &io_heuristics);
      CAkSrcFileBase::GetStreamLoopHeuristic((CAkSrcFileBase *)&v2->vfptr, v2->m_uLoopCnt != 1, &io_heuristics);
      v16 = v2->m_pCtx;
      io_heuristics.fThroughput = (float)(signed int)v11[2] * 0.001;
      io_heuristics.priority = (signed int)v16->m_PriorityInfoCurrent.currentPriority.priority;
      v2->m_pStream->vfptr->SetHeuristics(v2->m_pStream, &io_heuristics);
      v17 = v2->m_VorbisState.VorbisInfo.dwSeekTableSize;
      if ( !v17
        || (v18 = (AkVorbisSeekTableItem *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, v17),
            (v2->m_VorbisState.pSeekTable = v18) != 0i64) )
      {
        v19 = v2->m_pStream;
        v20 = v2->m_VorbisState.VorbisInfo.uMaxPacketSize;
        v2->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 1;
        result = v19->vfptr->SetMinimalBufferSize(v19, 2 * v20);
      }
      else
      {
        result = 52;
      }
    }
    else
    {
      result = 7;
    }
  }
  return result;
}

// File Line: 679
// RVA: 0xABB420
signed __int64 __fastcall CAkSrcFileVorbis::FindClosestFileOffset(CAkSrcFileVorbis *this, unsigned int in_uDesiredSample, unsigned int *out_uSeekedSample, unsigned int *out_uFileOffset)
{
  CAkSrcFileVorbis *v4; // rdi
  unsigned int *v5; // rbx
  signed __int64 result; // rax

  v4 = this;
  v5 = out_uFileOffset;
  result = VorbisSeek(&this->m_VorbisState, in_uDesiredSample, out_uSeekedSample, out_uFileOffset);
  if ( (_DWORD)result != 2 )
  {
    *v5 += v4->m_uDataOffset;
    result = 1i64;
  }
  return result;
}

// File Line: 693
// RVA: 0xABB460
void __fastcall CAkSrcFileVorbis::FreeStitchBuffer(CAkSrcFileVorbis *this)
{
  char *v1; // rdx
  CAkSrcFileVorbis *v2; // rbx

  v1 = this->m_pStitchStreamBuffer;
  v2 = this;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
    v2->m_pStitchStreamBuffer = 0i64;
    *(_DWORD *)&v2->m_uStitchBufferEndOffset = 0;
    v2->m_uStitchBufferLeft = 0;
  }
}

// File Line: 707
// RVA: 0xABB760
unsigned int __fastcall CAkSrcFileVorbis::GetNextPacket(CAkSrcFileVorbis *this, ogg_packet *out_OggPacket)
{
  ogg_packet *v2; // r14
  CAkSrcFileVorbis *v3; // rbx
  char v4; // al
  unsigned int result; // eax
  __int64 v6; // rdx
  unsigned __int64 v7; // rsi
  char *v8; // rdx
  char *v9; // rax
  unsigned int v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // esi
  char *v14; // rax
  int v15; // ecx

  v2 = out_OggPacket;
  v3 = this;
  while ( 1 )
  {
    if ( !v3->m_ulSizeLeft )
    {
      v4 = *((_BYTE *)&v3->0 + 126);
      if ( v4 & 1 )
        return 17;
      if ( v4 & 2 )
        *((_BYTE *)&v3->0 + 126) = v4 & 0xFD;
      else
        ((void (*)(void))v3->m_pStream->vfptr->ReleaseBuffer)();
      result = CAkSrcFileBase::FetchStreamBuffer((CAkSrcFileBase *)&v3->vfptr);
      if ( result != 45 )
        return result;
    }
    v6 = v3->m_uPacketHeaderGathered;
    if ( (unsigned int)v6 >= 2 )
      break;
    v7 = v3->m_ulSizeLeft;
    if ( (_DWORD)v7 )
    {
      if ( v7 >= 2 - v6 )
        LODWORD(v7) = 2 - v6;
      memmove((char *)&v3->m_OggPacketHeader + v3->m_uPacketHeaderGathered, v3->m_pNextAddress, (unsigned int)v7);
      v3->m_uPacketHeaderGathered += v7;
      v3->m_pNextAddress += (unsigned int)v7;
      v3->m_ulSizeLeft -= v7;
      if ( v3->m_uPacketHeaderGathered == 2 )
        break;
    }
    else
    {
LABEL_22:
      if ( v3->m_uPacketHeaderGathered == 2 && v3->m_uPacketDataGathered == v3->m_OggPacketHeader.uPacketSize )
      {
        v14 = v3->m_pOggPacketData;
        v15 = v3->m_OggPacketHeader.uPacketSize;
        v2->e_o_s = 0;
        v2->buffer.data = v14;
        v2->buffer.size = v15;
        *(_QWORD *)&v3->m_uPacketDataGathered = 0i64;
        return 45;
      }
    }
  }
  if ( v3->m_uPacketDataGathered )
    goto LABEL_30;
  v8 = v3->m_pOggPacketData;
  if ( v8 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v8);
    v3->m_pOggPacketData = 0i64;
  }
  v9 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, v3->m_OggPacketHeader.uPacketSize);
  v3->m_pOggPacketData = v9;
  if ( v9 )
  {
LABEL_30:
    v10 = v3->m_OggPacketHeader.uPacketSize;
    v11 = v3->m_uPacketDataGathered;
    if ( v11 < v10 )
    {
      v12 = v3->m_ulSizeLeft;
      if ( v12 )
      {
        v13 = v10 - v11;
        if ( v12 < v13 )
          v13 = v3->m_ulSizeLeft;
        memmove(&v3->m_pOggPacketData[v11], v3->m_pNextAddress, v13);
        v3->m_uPacketDataGathered += v13;
        v3->m_pNextAddress += v13;
        v3->m_ulSizeLeft -= v13;
      }
    }
    goto LABEL_22;
  }
  return 52;
}

// File Line: 800
// RVA: 0xABB170
signed __int64 __fastcall CAkSrcFileVorbis::ChangeSourcePosition(CAkSrcFileVorbis *this)
{
  CAkSrcFileVorbis *v1; // rbx
  signed __int64 result; // rax
  unsigned int v3; // edi
  char *v4; // rdx
  CAkPBI *v5; // rax
  unsigned int v6; // edx
  unsigned __int16 v7; // r8

  v1 = this;
  result = CAkSrcFileBase::ChangeSourcePosition((CAkSrcFileBase *)&this->vfptr);
  v3 = result;
  if ( (_DWORD)result == 1 )
  {
    v4 = v1->m_pStitchStreamBuffer;
    if ( v4 )
    {
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v4);
      v1->m_pStitchStreamBuffer = 0i64;
      *(_DWORD *)&v1->m_uStitchBufferEndOffset = 0;
      v1->m_uStitchBufferLeft = 0;
    }
    v5 = v1->m_pCtx;
    if ( *((_BYTE *)v5 + 375) & 2 )
      v6 = 0;
    else
      v6 = v5->m_uSeekPosition;
    *((_BYTE *)v5 + 375) &= 0xF1u;
    v5->m_uSeekPosition = 0;
    v1->m_uCurSample += v6;
    if ( v1->m_uLoopCnt == 1 )
      v7 = v1->m_VorbisState.VorbisInfo.uLastGranuleExtra;
    else
      v7 = v1->m_VorbisState.VorbisInfo.LoopInfo.uLoopEndExtra;
    vorbis_dsp_restart(&v1->m_VorbisState.TremorInfo.VorbisDSPState, v6, v7);
    v1->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
    result = v3;
  }
  return result;
}

