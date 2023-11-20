// File Line: 34
// RVA: 0xA924C0
void __fastcall CAkVPLFilterNodeOutOfPlace::GetBuffer(CAkVPLFilterNodeOutOfPlace *this, AkVPLState *io_state)
{
  bool v2; // zf

  v2 = this->m_bLast == 0;
  this->m_usRequestedFrames = io_state->uMaxFrames;
  if ( v2 )
  {
    if ( this->m_BufferIn.uValidFrames )
      ((void (*)(void))this->vfptr[1].VirtualOff)();
  }
  else
  {
    io_state->result = 17;
    ((void (*)(void))this->vfptr[1].VirtualOff)();
  }
}

// File Line: 53
// RVA: 0xA92230
void __fastcall CAkVPLFilterNodeOutOfPlace::ConsumeBuffer(CAkVPLFilterNodeOutOfPlace *this, AkVPLState *io_state)
{
  AkVPLState *v2; // rsi
  CAkVPLFilterNodeOutOfPlace *v3; // rbx
  __int64 v4; // rbp
  AkPipelineBuffer *v5; // rdx
  unsigned int v6; // ecx
  unsigned int i; // er8
  void *v8; // rax
  unsigned int v9; // edx
  unsigned __int16 v10; // cx
  AK::IAkOutOfPlaceEffectPlugin *v11; // rcx
  __int64 v12; // r8
  unsigned __int16 v13; // cx
  unsigned int in_uOutputConfig; // er12
  unsigned int v15; // eax
  bool v16; // cf
  unsigned int v17; // edx
  __int64 v18; // r13
  unsigned int j; // ecx
  __int64 v20; // r14
  bool v21; // zf
  signed int v22; // ecx
  AkSIMDSpeakerVolumes in_volumes; // [rsp+40h] [rbp-128h]
  unsigned int in_uInputConfig; // [rsp+170h] [rbp+8h]

  v2 = io_state;
  v3 = this;
  if ( io_state->result == 17 )
    this->m_bLast = 1;
  v4 = 0i64;
  if ( !this->m_BufferIn.uValidFrames )
  {
    this->m_uInOffset = 0;
    v5 = &this->m_BufferIn;
    v5->pData = v2->pData;
    *(_QWORD *)&v5->uChannelMask = *(_QWORD *)&v2->uChannelMask;
    *(_QWORD *)&v5->uMaxFrames = *(_QWORD *)&v2->uMaxFrames;
    *(_QWORD *)&v5->uNumMarkers = *(_QWORD *)&v2->uNumMarkers;
    v5->pMarkers = v2->pMarkers;
    *(_QWORD *)&v5->posInfo.uStartPos = *(_QWORD *)&v2->posInfo.uStartPos;
    *(_QWORD *)&v5->posInfo.uFileEnd = *(_QWORD *)&v2->posInfo.uFileEnd;
    CAkVPLNode::CopyRelevantMarkers((AkPipelineBuffer *)&v2->pData, &this->m_BufferIn, 0, v2->uValidFrames);
  }
  v3->m_BufferIn.eState = v2->result;
  if ( !v3->m_BufferOut.pData )
  {
    v6 = v3->m_BufferOut.uChannelMask;
    for ( i = 0; v6; v6 &= v6 - 1 )
      ++i;
    v8 = AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 4 * i * (unsigned __int64)v3->m_usRequestedFrames);
    if ( !v8 )
    {
      v2->result = 2;
      return;
    }
    v9 = v3->m_BufferOut.uChannelMask;
    v10 = v3->m_usRequestedFrames;
    v3->m_BufferOut.pData = v8;
    v3->m_BufferOut.uMaxFrames = v10;
    v3->m_BufferOut.uChannelMask = v9;
    v3->m_BufferOut.uValidFrames = 0;
  }
  v3->m_InputFramesBeforeExec = v3->m_BufferIn.uValidFrames;
  if ( v3->m_bBypassed || *((_BYTE *)v3->m_pCtx + 375) & 1 )
  {
    if ( !v3->m_LastBypassed )
      ((void (*)(void))v3->m_pEffect->vfptr->Reset)();
    v13 = v3->m_BufferOut.uMaxFrames;
    in_uOutputConfig = v3->m_BufferOut.uChannelMask;
    v15 = v3->m_BufferIn.uChannelMask;
    v16 = v3->m_BufferIn.uValidFrames < v13;
    v3->m_LastBypassed = 1;
    in_uInputConfig = v15;
    if ( v16 )
      v13 = v3->m_BufferIn.uValidFrames;
    v17 = 0;
    v18 = v13;
    for ( j = in_uOutputConfig; j; j &= j - 1 )
      ++v17;
    if ( v17 )
    {
      v20 = v17;
      do
      {
        memset((char *)v3->m_BufferOut.pData + 4 * v4++ * v3->m_BufferOut.uMaxFrames, 0, 4 * v18);
        --v20;
      }
      while ( v20 );
      LOWORD(v4) = 0;
    }
    CAkSpeakerPan::GetSpeakerVolumes2DPan(0.0, 0.0, 1.0, 0, in_uInputConfig, in_uOutputConfig, &in_volumes);
    CAkMixer::DownMix(
      (AkPipelineBufferBase *)&v3->m_BufferIn.pData,
      (AkPipelineBufferBase *)&v3->m_BufferOut.pData,
      &in_volumes,
      v18);
    v21 = v3->m_bLast == 0;
    v3->m_BufferIn.uValidFrames = v4;
    if ( v21 )
    {
      v22 = 43;
      if ( v3->m_BufferOut.uValidFrames == v3->m_BufferOut.uMaxFrames )
        v22 = 45;
      v3->m_BufferOut.eState = v22;
    }
    else
    {
      v3->m_BufferOut.eState = 17;
    }
  }
  else
  {
    v11 = v3->m_pEffect;
    v12 = v3->m_uInOffset;
    v3->m_LastBypassed = 0;
    ((void (__fastcall *)(AK::IAkOutOfPlaceEffectPlugin *, AkPipelineBuffer *, __int64, AkPipelineBuffer *))v11->vfptr[1].Term)(
      v11,
      &v3->m_BufferIn,
      v12,
      &v3->m_BufferOut);
  }
  (*(void (__fastcall **)(CAkVPLFilterNodeOutOfPlace *, AkVPLState *))v3->vfptr->gap8)(v3, v2);
}

// File Line: 147
// RVA: 0xA92610
void __fastcall CAkVPLFilterNodeOutOfPlace::ProcessDone(CAkVPLFilterNodeOutOfPlace *this, AkVPLState *io_state)
{
  int v2; // eax
  AkPipelineBuffer *v3; // r14
  unsigned int v4; // ebp
  AkVPLState *v5; // rdi
  CAkVPLFilterNodeOutOfPlace *v6; // rbx
  AKRESULT v7; // eax
  signed int v8; // eax
  float v9; // xmm1_4
  float v10; // xmm0_4
  unsigned int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  __m128i v14; // xmm1
  unsigned int v15; // eax
  unsigned int v16; // eax
  AKRESULT v17; // eax

  v2 = this->m_BufferIn.uValidFrames;
  v3 = &this->m_BufferOut;
  v4 = this->m_InputFramesBeforeExec - v2;
  v5 = io_state;
  v6 = this;
  CAkVPLNode::CopyRelevantMarkers(&this->m_BufferIn, &this->m_BufferOut, this->m_uInOffset, v4);
  if ( v6->m_pCtx->m_uRegisteredNotif & 0x10000 )
  {
    v7 = v6->m_BufferOut.eState;
    v6->m_uConsumedSinceLastOutput += v4;
    if ( v7 == 45 || v7 == 17 )
    {
      v8 = v6->m_uConsumedSinceLastOutput;
      v9 = v6->m_fAveragedInput * 7.0;
      v6->m_uConsumedSinceLastOutput = 0;
      v10 = (float)v8;
      v11 = v6->m_BufferOut.uValidFrames;
      v12 = v9 + v10;
      v13 = v6->m_fAveragedOutput * 7.0;
      v6->m_fAveragedInput = v12 * 0.125;
      v14 = _mm_cvtsi32_si128(v11);
      v15 = v6->m_BufferIn.posInfo.uSampleRate;
      v6->m_fAveragedOutput = (float)(COERCE_FLOAT(_mm_cvtepi32_ps(v14)) + v13) * 0.125;
      v5->posInfo.uSampleRate = v15;
      v5->posInfo.uStartPos = v6->m_uInOffset + v6->m_BufferIn.posInfo.uStartPos;
      v5->posInfo.uFileEnd = v6->m_BufferIn.posInfo.uFileEnd;
      v5->posInfo.fLastRate = v6->m_fAveragedInput / v6->m_fAveragedOutput;
    }
  }
  v6->m_uRequestedInputFrames += v4;
  v16 = v6->m_uRequestedInputFrames;
  v6->m_uInOffset += v4;
  v6->m_uConsumedInputFrames = v16;
  if ( !v6->m_BufferIn.uValidFrames )
  {
    ((void (*)(void))v6->m_pInput->vfptr->ReleaseBuffer)();
    AkPipelineBuffer::FreeMarkers(&v6->m_BufferIn);
    v6->m_BufferIn.pData = 0i64;
    *(_QWORD *)&v6->m_BufferIn.eState = 43i64;
    v6->m_BufferIn.posInfo.uStartPos = -1;
    v6->m_BufferIn.posInfo.fLastRate = 1.0;
    v6->m_BufferIn.posInfo.uFileEnd = -1;
    v6->m_BufferIn.posInfo.uSampleRate = 1;
    v5->pData = 0i64;
    v5->uValidFrames = 0;
  }
  v17 = v6->m_BufferOut.eState;
  if ( v17 == 45 || v17 == 17 )
  {
    v6->m_BufferOut.posInfo.uStartPos = v5->posInfo.uStartPos;
    v6->m_BufferOut.posInfo.fLastRate = v5->posInfo.fLastRate;
    v6->m_BufferOut.posInfo.uFileEnd = v5->posInfo.uFileEnd;
    v6->m_BufferOut.posInfo.uSampleRate = v5->posInfo.uSampleRate;
    v5->pData = v3->pData;
    *(_QWORD *)&v5->uChannelMask = *(_QWORD *)&v3->uChannelMask;
    *(_QWORD *)&v5->uMaxFrames = *(_QWORD *)&v3->uMaxFrames;
    *(_QWORD *)&v5->uNumMarkers = *(_QWORD *)&v3->uNumMarkers;
    v5->pMarkers = v3->pMarkers;
    *(_QWORD *)&v5->posInfo.uStartPos = *(_QWORD *)&v3->posInfo.uStartPos;
    *(_QWORD *)&v5->posInfo.uFileEnd = *(_QWORD *)&v3->posInfo.uFileEnd;
    v17 = v6->m_BufferOut.eState;
  }
  v5->result = v17;
}

// File Line: 209
// RVA: 0xA92810
void __fastcall CAkVPLFilterNodeOutOfPlace::ReleaseBuffer(CAkVPLFilterNodeOutOfPlace *this)
{
  void *v1; // rdx
  CAkVPLFilterNodeOutOfPlace *v2; // rbx

  v1 = this->m_BufferOut.pData;
  v2 = this;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
    v2->m_BufferOut.pData = 0i64;
    *(_QWORD *)&v2->m_BufferOut.eState = 43i64;
    v2->m_BufferOut.uNumMarkers = 0;
    v2->m_BufferOut.pMarkers = 0i64;
    v2->m_BufferOut.posInfo.uStartPos = -1;
    v2->m_BufferOut.posInfo.fLastRate = 1.0;
    v2->m_BufferOut.posInfo.uFileEnd = -1;
    v2->m_BufferOut.posInfo.uSampleRate = 1;
  }
}

// File Line: 221
// RVA: 0xA92910
__int64 __fastcall CAkVPLFilterNodeOutOfPlace::Seek(CAkVPLFilterNodeOutOfPlace *this)
{
  CAkVPLFilterNodeOutOfPlace *v1; // rdi
  CAkVPLNode *v2; // rcx

  v1 = this;
  ((void (*)(void))this->m_pEffect->vfptr->Reset)();
  ((void (*)(void))v1->m_pInput->vfptr->ReleaseBuffer)();
  AkPipelineBuffer::FreeMarkers(&v1->m_BufferIn);
  *(_QWORD *)&v1->m_BufferIn.eState = 43i64;
  v1->m_BufferIn.pData = 0i64;
  v1->m_BufferIn.posInfo.uStartPos = -1;
  v1->m_BufferIn.posInfo.fLastRate = 1.0;
  v1->m_BufferIn.posInfo.uFileEnd = -1;
  v1->m_BufferIn.posInfo.uSampleRate = 1;
  v2 = v1->m_pInput;
  v1->m_bLast = 0;
  return ((__int64 (*)(void))v2->vfptr->Seek)();
}

// File Line: 236
// RVA: 0xA92A80
void __fastcall CAkVPLFilterNodeOutOfPlace::VirtualOn(CAkVPLFilterNodeOutOfPlace *this, AkVirtualQueueBehavior eBehavior)
{
  AkVirtualQueueBehavior v2; // edi
  CAkVPLFilterNodeOutOfPlace *v3; // rbx

  v2 = eBehavior;
  v3 = this;
  if ( eBehavior != 2 )
  {
    ((void (*)(void))this->m_pEffect->vfptr->Reset)();
    ((void (__fastcall *)(CAkVPLFilterNodeOutOfPlace *))v3->vfptr[1].TimeSkip)(v3);
  }
  CAkVPLFilterNodeBase::VirtualOn((CAkVPLFilterNodeBase *)&v3->vfptr, v2);
}

// File Line: 252
// RVA: 0xA92500
signed __int64 __fastcall CAkVPLFilterNodeOutOfPlace::Init(CAkVPLFilterNodeOutOfPlace *this, AK::IAkPlugin *in_pPlugin, AkFXDesc *in_fxDesc, unsigned int in_uFXIndex, CAkPBI *in_pCtx, AkAudioFormat *io_format)
{
  CAkVPLFilterNodeOutOfPlace *v6; // rbx
  signed __int64 result; // rax
  AK::IAkOutOfPlaceEffectPlugin *v8; // rcx

  this->m_pEffect = (AK::IAkOutOfPlaceEffectPlugin *)in_pPlugin;
  *(_QWORD *)&this->m_BufferIn.eState = 43i64;
  v6 = this;
  this->m_BufferIn.pData = 0i64;
  this->m_BufferIn.uNumMarkers = 0;
  this->m_BufferIn.pMarkers = 0i64;
  this->m_BufferIn.posInfo.uStartPos = -1;
  this->m_BufferIn.posInfo.fLastRate = 1.0;
  this->m_BufferIn.posInfo.uFileEnd = -1;
  this->m_BufferIn.posInfo.uSampleRate = 1;
  this->m_BufferOut.pData = 0i64;
  this->m_BufferOut.uNumMarkers = 0;
  this->m_BufferOut.pMarkers = 0i64;
  *(_QWORD *)&this->m_BufferOut.eState = 43i64;
  this->m_BufferOut.posInfo.uStartPos = -1;
  this->m_BufferOut.posInfo.fLastRate = 1.0;
  this->m_BufferOut.posInfo.uFileEnd = -1;
  this->m_BufferOut.posInfo.uSampleRate = 1;
  *(_QWORD *)&this->m_uConsumedInputFrames = 0i64;
  this->m_fAveragedInput = 1.0;
  *(_QWORD *)&this->m_fAveragedOutput = 1065353216i64;
  result = CAkVPLFilterNodeBase::Init((CAkVPLFilterNodeBase *)&this->vfptr, in_pPlugin, in_fxDesc, in_uFXIndex, in_pCtx);
  if ( (_DWORD)result == 1 )
  {
    result = ((__int64 (__fastcall *)(AK::IAkOutOfPlaceEffectPlugin *, AkFXMemAlloc *, CAkInsertFXContext *, AK::IAkPluginParam *, AkAudioFormat *, AkAudioFormat *))v6->m_pEffect->vfptr[1].__vecDelDtor)(
               v6->m_pEffect,
               &AkFXMemAlloc::m_instanceLower,
               v6->m_pInsertFXContext,
               v6->m_pParam,
               io_format,
               io_format);
    if ( (_DWORD)result == 1 )
    {
      v8 = v6->m_pEffect;
      v6->m_BufferOut.uChannelMask = *((_DWORD *)io_format + 1) & 0x3FFFF;
      result = ((__int64 (*)(void))v8->vfptr->Reset)();
    }
  }
  return result;
}

// File Line: 305
// RVA: 0xA92980
void __fastcall CAkVPLFilterNodeOutOfPlace::Term(CAkVPLFilterNodeOutOfPlace *this)
{
  CAkVPLFilterNodeOutOfPlace *v1; // rbx
  void **v2; // rdi

  v1 = this;
  ((void (*)(void))this->vfptr[1].ReleaseBuffer)();
  CAkVPLFilterNodeBase::Term((CAkVPLFilterNodeBase *)&v1->vfptr);
  v2 = &v1->m_BufferOut.pData;
  if ( v1->m_BufferOut.pData )
  {
    AkPipelineBuffer::FreeMarkers(&v1->m_BufferOut);
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, *v2);
    *v2 = 0i64;
    *(_DWORD *)&v1->m_BufferOut.uMaxFrames = 0;
  }
  AkPipelineBuffer::FreeMarkers(&v1->m_BufferIn);
}

// File Line: 322
// RVA: 0xA928E0
void __fastcall CAkVPLFilterNodeOutOfPlace::ReleaseMemory(CAkVPLFilterNodeOutOfPlace *this)
{
  CAkVPLFilterNodeOutOfPlace *v1; // rbx
  AK::IAkOutOfPlaceEffectPlugin *v2; // rcx

  v1 = this;
  v2 = this->m_pEffect;
  if ( v2 )
  {
    v2->vfptr->Term((AK::IAkPlugin *)&v2->vfptr, (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower.vfptr);
    v1->m_pEffect = 0i64;
  }
}

// File Line: 332
// RVA: 0xA929E0
signed __int64 __fastcall CAkVPLFilterNodeOutOfPlace::TimeSkip(CAkVPLFilterNodeOutOfPlace *this, unsigned int *io_uFrames)
{
  CAkVPLFilterNodeOutOfPlace *v2; // rbx
  AK::IAkOutOfPlaceEffectPlugin *v4; // rcx
  AKRESULT v5; // eax
  AKRESULT v6; // edx
  CAkVPLNode *v7; // rcx
  AKRESULT v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // [rsp+30h] [rbp+8h]
  int v13; // [rsp+40h] [rbp+18h]

  v2 = this;
  if ( this->m_bLast )
    return 17i64;
  v4 = this->m_pEffect;
  v12 = *io_uFrames;
  v5 = ((unsigned int (__fastcall *)(AK::IAkOutOfPlaceEffectPlugin *, unsigned int *))v4->vfptr[1].Reset)(v4, &v12);
  v2->m_uRequestedInputFrames += v12;
  v6 = v5;
  v12 = v2->m_uRequestedInputFrames - v2->m_uConsumedInputFrames;
  if ( v12 >= 0x400 )
  {
    do
    {
      if ( v6 != 45 )
        break;
      v7 = v2->m_pInput;
      v13 = 1024;
      v8 = (unsigned int)v7->vfptr->TimeSkip(v7, (unsigned int *)&v13);
      v9 = v12;
      v6 = v8;
      v10 = v13;
      v2->m_uConsumedInputFrames += v13;
      v11 = v9 - v10;
      v12 = v11;
      v2->m_bLast = v6 == 17;
    }
    while ( v11 >= 0x400 );
  }
  return (unsigned int)v6;
}

// File Line: 367
// RVA: 0xA92880
signed __int64 __fastcall CAkVPLFilterNodeOutOfPlace::ReleaseInputBuffer(CAkVPLFilterNodeOutOfPlace *this)
{
  CAkVPLFilterNodeOutOfPlace *v1; // rbx
  CAkVPLNode *v2; // rcx
  signed __int64 result; // rax

  v1 = this;
  v2 = this->m_pInput;
  if ( v2 )
    ((void (*)(void))v2->vfptr->ReleaseBuffer)();
  AkPipelineBuffer::FreeMarkers(&v1->m_BufferIn);
  *(_QWORD *)&v1->m_BufferIn.eState = 43i64;
  result = 1i64;
  v1->m_BufferIn.pData = 0i64;
  v1->m_BufferIn.posInfo.uStartPos = -1;
  v1->m_BufferIn.posInfo.fLastRate = 1.0;
  v1->m_BufferIn.posInfo.uFileEnd = -1;
  v1->m_BufferIn.posInfo.uSampleRate = 1;
  return result;
}

// File Line: 377
// RVA: 0xA924F0
__int64 __fastcall UFG::UIList::getNumSlots(CAkVPLFilterNodeOutOfPlace *this)
{
  return this->m_BufferOut.uChannelMask;
}

