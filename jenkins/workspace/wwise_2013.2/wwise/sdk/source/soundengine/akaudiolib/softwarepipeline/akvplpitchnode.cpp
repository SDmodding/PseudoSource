// File Line: 27
// RVA: 0xA844B0
void __usercall CAkVPLPitchNode::GetBuffer(CAkVPLPitchNode *this@<rcx>, AkVPLState *io_state@<rdx>, float a3@<xmm0>)
{
  unsigned int v3; // eax
  CAkVPLPitchNode *v4; // rbx
  AkVPLState *v5; // rdi

  v3 = io_state->uMaxFrames;
  this->m_bStartPosInfoUpdated = 0;
  v4 = this;
  this->m_Pitch.m_InternalPitchState.uRequestedFrames = v3;
  v5 = io_state;
  ((void (*)(void))this->m_pInput->vfptr->GetPitch)();
  CAkResampler::SetPitch(&v4->m_Pitch, a3);
  if ( v4->m_BufferIn.uValidFrames )
  {
    CAkVPLPitchNode::ConsumeBuffer(v4, v5);
  }
  else if ( v4->m_bLast )
  {
    v5->result = 17;
  }
}

// File Line: 63
// RVA: 0xA841B0
void __fastcall CAkVPLPitchNode::ConsumeBuffer(CAkVPLPitchNode *this, AkVPLState *io_state)
{
  AkVPLState *v2; // r14
  CAkVPLPitchNode *v3; // rsi
  AkPipelineBuffer *v4; // r15
  CAkPBI *v5; // rax
  int v6; // ebx
  signed int v7; // ebx
  CAkPBI *v8; // rax
  signed int v9; // ecx
  int v10; // edx
  unsigned __int16 v11; // bx
  unsigned int v12; // er13
  AKRESULT v13; // ebp
  unsigned int v14; // ecx
  float v15; // eax
  float v16; // xmm0_4
  bool v17; // zf
  signed int v18; // eax

  v2 = io_state;
  v3 = this;
  if ( io_state->result == 17 )
    this->m_bLast = 1;
  if ( !this->m_BufferIn.uValidFrames )
  {
    if ( !io_state->uValidFrames && io_state->result == 45 )
    {
      io_state->result = 43;
      return;
    }
    this->m_BufferIn.pData = io_state->pData;
    *(_QWORD *)&this->m_BufferIn.uChannelMask = *(_QWORD *)&io_state->uChannelMask;
    *(_QWORD *)&this->m_BufferIn.uMaxFrames = *(_QWORD *)&io_state->uMaxFrames;
    *(_QWORD *)&this->m_BufferIn.uNumMarkers = *(_QWORD *)&io_state->uNumMarkers;
    this->m_BufferIn.pMarkers = io_state->pMarkers;
    *(_QWORD *)&this->m_BufferIn.posInfo.uStartPos = *(_QWORD *)&io_state->posInfo.uStartPos;
    *(_QWORD *)&this->m_BufferIn.posInfo.uFileEnd = *(_QWORD *)&io_state->posInfo.uFileEnd;
  }
  v4 = &this->m_BufferOut;
  if ( !this->m_BufferOut.pData )
  {
    if ( (unsigned int)AkPipelineBufferBase::GetCachedBuffer(
                         (AkPipelineBufferBase *)&this->m_BufferOut.pData,
                         this->m_Pitch.m_InternalPitchState.uRequestedFrames,
                         this->m_BufferIn.uChannelMask) != 1 )
    {
      v2->result = 2;
      return;
    }
    if ( v3->m_bPadFrameOffset )
    {
      v5 = v3->m_pPBI;
      v6 = v5->m_iFrameOffset;
      if ( *((_BYTE *)v5 + 374) < 0 )
        v7 = v6 + 8;
      else
        v7 = v6 + 1024;
      if ( v7 > 0 )
      {
        if ( CAkResampler::IsPostDeInterleaveRequired(&v3->m_Pitch) )
          ZeroPrePadBufferInterleaved((AkAudioBuffer *)&v4->pData, v7);
        else
          ZeroPrePadBuffer((AkAudioBuffer *)&v4->pData, v7);
        v3->m_Pitch.m_InternalPitchState.uOutFrameOffset = v7;
      }
      v3->m_bPadFrameOffset = 0;
    }
  }
  v8 = v3->m_pPBI;
  if ( *((_BYTE *)v8 + 375) & 2 || (v9 = v8->m_uSeekPosition) == 0 )
  {
LABEL_24:
    v11 = v3->m_BufferIn.uValidFrames;
    v12 = v3->m_Pitch.m_InternalPitchState.uInFrameOffset;
    v13 = CAkResampler::Execute(&v3->m_Pitch, (AkAudioBuffer *)&v3->m_BufferIn.pData, (AkAudioBuffer *)&v4->pData);
    CAkVPLNode::CopyRelevantMarkers(&v3->m_BufferIn, v4, v12, (unsigned __int16)(v11 - v3->m_BufferIn.uValidFrames));
    v14 = v3->m_BufferIn.posInfo.uStartPos;
    if ( v14 != -1 && !v3->m_bStartPosInfoUpdated )
    {
      v15 = v3->m_BufferIn.posInfo.fLastRate;
      v3->m_bStartPosInfoUpdated = 1;
      v3->m_BufferOut.posInfo.fLastRate = v15;
      v3->m_BufferOut.posInfo.uFileEnd = v3->m_BufferIn.posInfo.uFileEnd;
      v3->m_BufferOut.posInfo.uSampleRate = v3->m_BufferIn.posInfo.uSampleRate;
      v3->m_BufferOut.posInfo.uStartPos = v14 + v12;
    }
    v16 = CAkResampler::GetLastRate(&v3->m_Pitch);
    v17 = v3->m_BufferIn.uValidFrames == 0;
    v3->m_BufferOut.posInfo.fLastRate = v16;
    if ( v17 )
    {
      CAkVPLPitchNode::ReleaseInputBuffer(v3, (AkPipelineBuffer *)&v2->pData);
      if ( v3->m_bLast == 1 )
      {
        if ( !v3->m_pCbx->m_pSources[1] )
        {
          v13 = 17;
          goto LABEL_33;
        }
        v13 = CAkVPLPitchNode::SwitchToNextSrc(v3);
      }
    }
    if ( v13 != 45 && v13 != 17 )
    {
LABEL_36:
      v2->result = v13;
      return;
    }
LABEL_33:
    if ( CAkResampler::IsPostDeInterleaveRequired(&v3->m_Pitch) )
      CAkResampler::DeinterleaveAndSwapOutput(&v3->m_Pitch, (AkAudioBuffer *)&v4->pData);
    v2->pData = v4->pData;
    *(_QWORD *)&v2->uChannelMask = *(_QWORD *)&v4->uChannelMask;
    *(_QWORD *)&v2->uMaxFrames = *(_QWORD *)&v4->uMaxFrames;
    *(_QWORD *)&v2->uNumMarkers = *(_QWORD *)&v4->uNumMarkers;
    v2->pMarkers = v4->pMarkers;
    *(_QWORD *)&v2->posInfo.uStartPos = *(_QWORD *)&v4->posInfo.uStartPos;
    *(_QWORD *)&v2->posInfo.uFileEnd = *(_QWORD *)&v4->posInfo.uFileEnd;
    goto LABEL_36;
  }
  v10 = v3->m_BufferIn.uValidFrames;
  if ( v10 > v9 )
  {
    v3->m_Pitch.m_InternalPitchState.uInFrameOffset = v9;
    v3->m_BufferIn.uValidFrames = v10 - v9;
    *((_BYTE *)v8 + 375) &= 0xF1u;
    v8->m_uSeekPosition = 0;
    goto LABEL_24;
  }
  *((_BYTE *)v8 + 375) &= 0xF1u;
  v8->m_uSeekPosition = v9 - v10;
  v3->m_BufferIn.uValidFrames = 0;
  v2->uValidFrames = 0;
  CAkVPLPitchNode::ReleaseInputBuffer(v3, (AkPipelineBuffer *)&v2->pData);
  v18 = 43;
  if ( v3->m_bLast )
    v18 = 17;
  v2->result = v18;
}

// File Line: 278
// RVA: 0xA846D0
signed __int64 __usercall CAkVPLPitchNode::SwitchToNextSrc@<rax>(CAkVPLPitchNode *this@<rcx>, float a2@<xmm0>)
{
  CAkVPLSrcCbxNode *v2; // rax
  CAkVPLPitchNode *v3; // rsi
  CAkPBI *v4; // rbx
  int v5; // ecx
  int v6; // eax
  signed __int64 result; // rax
  int v8; // eax
  AkAudioFormat v9; // rax
  CAkVPLSrcCbxNode *v10; // rax
  unsigned int in_uSampleRate; // edi
  bool v12; // zf
  AkAudioFormat in_fmt; // [rsp+40h] [rbp+8h]

  v2 = this->m_pCbx;
  v3 = this;
  v4 = v2->m_pSources[1]->m_pCtx;
  v5 = v4->m_iFrameOffset;
  if ( v5 > 0 )
  {
    if ( v5 >= 0 )
    {
      v6 = v4->m_iFrameOffset;
      if ( v3->m_BufferOut.uMaxFrames - v3->m_BufferOut.uValidFrames < v5 )
        v6 = v3->m_BufferOut.uMaxFrames - v3->m_BufferOut.uValidFrames;
      v4->m_iFrameOffset = v5 - v6;
    }
    return 17i64;
  }
  v8 = CAkVPLSrcNode::FetchStreamedData(v2->m_pSources[1]);
  if ( v8 == 63 )
    return 17i64;
  if ( v8 != 1 )
    return 2i64;
  v9 = v3->m_pPBI->m_sMediaFormat;
  in_fmt = v4->m_sMediaFormat;
  if ( (*((_DWORD *)&v9 + 1) ^ *((_DWORD *)&in_fmt + 1)) & 0x3FFFF )
    return 17i64;
  CAkVPLSrcCbxNode::SwitchToNextSrc(v3->m_pCbx);
  v10 = v3->m_pCbx;
  v3->m_pPBI = v4;
  v3->m_pInput = (CAkVPLNode *)&v10->m_pSources[0]->vfptr;
  if ( !(*((_BYTE *)v4 + 372) & 0x20) )
    v4->vfptr[7].~CAkTransportAware((CAkTransportAware *)&v4->vfptr);
  in_uSampleRate = v3->m_pCbx->m_uSampleRate;
  ((void (*)(void))v3->m_pInput->vfptr->GetPitch)();
  CAkResampler::SwitchTo(&v3->m_Pitch, &in_fmt, a2, (AkAudioBuffer *)&v3->m_BufferOut.pData, in_uSampleRate);
  v12 = v3->m_BufferOut.uValidFrames == v3->m_Pitch.m_InternalPitchState.uRequestedFrames;
  result = 45i64;
  v3->m_bLast = 0;
  if ( !v12 )
    result = 43i64;
  return result;
}

// File Line: 330
// RVA: 0xA84550
void __fastcall CAkVPLPitchNode::ReleaseBuffer(CAkVPLPitchNode *this)
{
  AkPipelineBuffer *v1; // rbx
  CAkVPLPitchNode *v2; // rdi

  v1 = &this->m_BufferOut;
  v2 = this;
  if ( this->m_BufferOut.pData )
  {
    AkPipelineBufferBase::ReleaseCachedBuffer((AkPipelineBufferBase *)&this->m_BufferOut.pData);
    *(_QWORD *)&v1->eState = 43i64;
    v1->pData = 0i64;
    v1->uNumMarkers = 0;
    v1->pMarkers = 0i64;
    v1->posInfo.uStartPos = -1;
    v1->posInfo.fLastRate = 1.0;
    v1->posInfo.uFileEnd = -1;
    v1->posInfo.uSampleRate = 1;
    v2->m_Pitch.m_InternalPitchState.uOutFrameOffset = 0;
  }
}

// File Line: 351
// RVA: 0xA845C0
void __fastcall CAkVPLPitchNode::ReleaseInputBuffer(CAkVPLPitchNode *this, AkPipelineBuffer *io_buffer)
{
  CAkVPLPitchNode *v2; // rbx
  AkPipelineBuffer *v3; // rdi

  v2 = this;
  v3 = io_buffer;
  ((void (*)(void))this->m_pInput->vfptr->ReleaseBuffer)();
  AkPipelineBuffer::FreeMarkers(&v2->m_BufferIn);
  *(_QWORD *)&v2->m_BufferIn.eState = 43i64;
  v2->m_BufferIn.pData = 0i64;
  v2->m_BufferIn.posInfo.uStartPos = -1;
  v2->m_BufferIn.posInfo.fLastRate = 1.0;
  v2->m_BufferIn.posInfo.uFileEnd = -1;
  v2->m_BufferIn.posInfo.uSampleRate = 1;
  v3->pData = 0i64;
  v3->uNumMarkers = 0;
  v3->pMarkers = 0i64;
}

// File Line: 366
// RVA: 0xA84880
__int64 __usercall CAkVPLPitchNode::TimeSkip@<rax>(CAkVPLPitchNode *this@<rcx>, unsigned int *io_uFrames@<rdx>, float a3@<xmm0>)
{
  CAkVPLPitchNode *v3; // rbx
  unsigned int *v4; // r14
  signed int v5; // esi
  unsigned int v6; // ebp
  unsigned int v7; // edi
  CAkVPLNode *v8; // rcx
  __int64 result; // rax
  CAkPBI *v10; // rdx
  unsigned int v11; // ecx
  int v12; // er8
  unsigned int v13; // er8
  unsigned int v14; // eax
  bool v15; // zf
  unsigned int v16; // [rsp+40h] [rbp+8h]

  v3 = this;
  v4 = io_uFrames;
  ((void (*)(void))this->m_pInput->vfptr->GetPitch)();
  CAkResampler::SetPitchForTimeSkip(&v3->m_Pitch, a3);
  v5 = 0;
  v6 = 45;
  v7 = (signed int)(float)((float)((float)((float)(signed int)v3->m_Pitch.m_InternalPitchState.uCurrentFrameSkip
                                         * 0.000015258789)
                                 * (float)(signed int)*v4)
                         + 0.5);
  if ( v7 )
  {
    while ( 1 )
    {
      if ( !v3->m_BufferIn.uValidFrames && !v3->m_bLast )
      {
        v8 = v3->m_pInput;
        v16 = *v4;
        result = v8->vfptr->TimeSkip(v8, &v16);
        if ( (_DWORD)result != 45 )
        {
          if ( (_DWORD)result != 17 )
            return result;
          v3->m_bLast = 1;
        }
        v10 = v3->m_pPBI;
        if ( *((_BYTE *)v10 + 375) & 2 )
          v11 = 0;
        else
          v11 = v10->m_uSeekPosition;
        v12 = 0;
        if ( v11 > v16 )
        {
          v13 = v11;
          v11 = v16;
          v12 = v13 - v16;
        }
        v16 -= v11;
        *((_BYTE *)v10 + 375) &= 0xF1u;
        v10->m_uSeekPosition = v12;
        v3->m_BufferIn.uValidFrames = v16;
      }
      v14 = v3->m_BufferIn.uValidFrames;
      if ( v7 < v14 )
        v14 = v7;
      v5 += v14;
      v7 -= v14;
      v15 = v3->m_BufferIn.uValidFrames == (_WORD)v14;
      v3->m_BufferIn.uValidFrames -= v14;
      if ( v15 )
      {
        if ( v3->m_bLast )
          break;
      }
      if ( !v7 )
        goto LABEL_20;
    }
    v6 = 17;
  }
LABEL_20:
  result = v6;
  *v4 = (signed int)(float)((float)((float)v5
                                  / (float)((float)(signed int)v3->m_Pitch.m_InternalPitchState.uCurrentFrameSkip
                                          * 0.000015258789))
                          + 0.5);
  return result;
}

// File Line: 444
// RVA: 0xA84A20
void __fastcall CAkVPLPitchNode::VirtualOn(CAkVPLPitchNode *this, AkVirtualQueueBehavior eBehavior)
{
  AkVirtualQueueBehavior v2; // esi
  CAkVPLPitchNode *v3; // rbx

  v2 = eBehavior;
  v3 = this;
  if ( eBehavior != 2 )
  {
    if ( this->m_BufferIn.pData )
      ((void (*)(void))this->m_pInput->vfptr->ReleaseBuffer)();
    AkPipelineBuffer::FreeMarkers(&v3->m_BufferIn);
    *(_QWORD *)&v3->m_BufferIn.eState = 43i64;
    v3->m_BufferIn.pData = 0i64;
    v3->m_BufferIn.posInfo.uStartPos = -1;
    v3->m_BufferIn.posInfo.fLastRate = 1.0;
    v3->m_BufferIn.posInfo.uFileEnd = -1;
    v3->m_BufferIn.posInfo.uSampleRate = 1;
    CAkResampler::ResetOffsets(&v3->m_Pitch);
  }
  if ( v2 == AkVirtualQueueBehavior_FromBeginning )
    v3->m_bLast = 0;
  if ( !v3->m_bLast )
    v3->m_pInput->vfptr->VirtualOn(v3->m_pInput, v2);
}

// File Line: 471
// RVA: 0xA849F0
signed __int64 __fastcall CAkVPLPitchNode::VirtualOff(CAkVPLPitchNode *this, __int64 eBehavior, __int64 in_bUseSourceOffset)
{
  signed __int64 result; // rax

  if ( (_DWORD)eBehavior == 1 )
    this->m_BufferIn.uValidFrames = 0;
  if ( this->m_bLast )
    result = 1i64;
  else
    result = this->m_pInput->vfptr->VirtualOff(this->m_pInput, (AkVirtualQueueBehavior)eBehavior, in_bUseSourceOffset);
  return result;
}

// File Line: 485
// RVA: 0xA84650
__int64 __fastcall CAkVPLPitchNode::Seek(CAkVPLPitchNode *this)
{
  CAkVPLPitchNode *v1; // rdi
  CAkVPLNode *v2; // rcx

  v1 = this;
  ((void (*)(void))this->m_pInput->vfptr->ReleaseBuffer)();
  AkPipelineBuffer::FreeMarkers(&v1->m_BufferIn);
  *(_QWORD *)&v1->m_BufferIn.eState = 43i64;
  v1->m_BufferIn.pData = 0i64;
  v1->m_BufferIn.posInfo.uStartPos = -1;
  v1->m_BufferIn.posInfo.fLastRate = 1.0;
  v1->m_BufferIn.posInfo.uFileEnd = -1;
  v1->m_BufferIn.posInfo.uSampleRate = 1;
  CAkResampler::ResetOffsets(&v1->m_Pitch);
  v2 = v1->m_pInput;
  v1->m_bLast = 0;
  return ((__int64 (*)(void))v2->vfptr->Seek)();
}

// File Line: 512
// RVA: 0xA84520
void __fastcall CAkVPLPitchNode::Init(CAkVPLPitchNode *this, AkAudioFormat *io_pFormat, CAkPBI *in_pPBI, unsigned int in_usSampleRate)
{
  this->m_pPBI = in_pPBI;
  this->m_bLast = 0;
  this->m_bPadFrameOffset = 1;
  CAkResampler::Init(&this->m_Pitch, io_pFormat, in_usSampleRate);
}

// File Line: 531
// RVA: 0xA84820
void __fastcall CAkVPLPitchNode::Term(CAkVPLPitchNode *this)
{
  CAkVPLPitchNode *v1; // rbx

  v1 = this;
  if ( this->m_BufferOut.pData )
  {
    AkPipelineBuffer::FreeMarkers(&this->m_BufferOut);
    AkPipelineBufferBase::ReleaseCachedBuffer((AkPipelineBufferBase *)&v1->m_BufferOut.pData);
  }
  AkPipelineBuffer::FreeMarkers(&v1->m_BufferIn);
  v1->m_pPBI = 0i64;
  _((AMD_HD3D *)&v1->m_Pitch);
}

// File Line: 554
// RVA: 0xA84630
void __fastcall CAkVPLPitchNode::RelocateMedia(CAkVPLPitchNode *this, char *in_pNewMedia, char *in_pOldMedia)
{
  _BYTE *v3; // rax

  v3 = this->m_BufferIn.pData;
  if ( v3 )
    this->m_BufferIn.pData = &in_pNewMedia[v3 - in_pOldMedia];
}

