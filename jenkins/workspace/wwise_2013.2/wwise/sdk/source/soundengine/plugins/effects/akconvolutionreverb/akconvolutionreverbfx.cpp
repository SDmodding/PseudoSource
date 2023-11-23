// File Line: 28
// RVA: 0xB166D0
void __fastcall CreateConvolutionReverbFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkConvolutionReverbFX *v1; // rax

  v1 = (CAkConvolutionReverbFX *)in_pAllocator->vfptr->Malloc(in_pAllocator, 608i64);
  if ( v1 )
    CAkConvolutionReverbFX::CAkConvolutionReverbFX(v1);
}

// File Line: 36
// RVA: 0xB16700
void __fastcall CAkConvolutionReverbFX::CAkConvolutionReverbFX(CAkConvolutionReverbFX *this)
{
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *p_m_ConvolutionEngine; // rcx

  p_m_ConvolutionEngine = &this->m_ConvolutionEngine;
  *(_QWORD *)&p_m_ConvolutionEngine[-1].m_uNumInputChannels = &CAkConvolutionReverbFX::`vftable;
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::CAkPartitionedConvolutionEngine(p_m_ConvolutionEngine);
  this->m_Params.fStereoWidth = 180.0;
  *(_QWORD *)&this->m_Params.fInputCenterLevel = 1065353216i64;
  this->m_Params.fFrontLevel = 1.0;
  this->m_Params.fRearLevel = 1.0;
  *(_QWORD *)&this->m_Params.fCenterLevel = 1065353216i64;
  this->m_Params.fDryLevel = 1.0;
  *(_QWORD *)&this->m_Params.fWetLevel = 1048576000i64;
  *(_QWORD *)&this->m_Params.fPreDelay = 0i64;
  *(_QWORD *)&this->m_PrevParams.fPreDelay = 0i64;
  this->m_PrevParams.fStereoWidth = 180.0;
  *(_QWORD *)&this->m_PrevParams.fInputCenterLevel = 1065353216i64;
  this->m_PrevParams.fFrontLevel = 1.0;
  this->m_PrevParams.fRearLevel = 1.0;
  *(_QWORD *)&this->m_PrevParams.fCenterLevel = 1065353216i64;
  this->m_PrevParams.fDryLevel = 1.0;
  *(_QWORD *)&this->m_PrevParams.fWetLevel = 1048576000i64;
  AkConvolutionReverbState::AkConvolutionReverbState(&this->m_ReverbState);
  this->m_pSharedParams = 0i64;
  this->m_pAllocator = 0i64;
}

// File Line: 42
// RVA: 0xB16800
void __fastcall CAkConvolutionReverbFX::~CAkConvolutionReverbFX(CAkConvolutionReverbFX *this)
{
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *p_m_ConvolutionEngine; // rcx

  p_m_ConvolutionEngine = &this->m_ConvolutionEngine;
  *(_QWORD *)&p_m_ConvolutionEngine[-1].m_uNumInputChannels = &CAkConvolutionReverbFX::`vftable;
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::~CAkPartitionedConvolutionEngine(p_m_ConvolutionEngine);
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 52
// RVA: 0xB16840
AKRESULT __fastcall CAkConvolutionReverbFX::Init(
        CAkConvolutionReverbFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkConvolutionReverbFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  AkConvolutionReverbFXParams *p_m_Params; // rdi
  AkAudioFormat *v9; // r14
  int v10; // ecx
  bool v11; // zf
  unsigned int uDownMixChannelMask; // eax
  AK::IAkPluginContextBaseVtbl *vfptr; // rax
  AK::IAkProcessorFeatures *in_pProcessorFeatures; // rax
  AKRESULT result; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  AkAudioFormat v21; // [rsp+50h] [rbp+8h] BYREF

  p_m_Params = &this->m_Params;
  this->m_pAllocator = in_pAllocator;
  this->m_pSharedParams = in_pParams;
  CAkConvolutionReverbFXParams::GetParams(in_pParams, &this->m_Params);
  v9 = in_rFormat;
  this->m_PrevParams = *p_m_Params;
  v10 = *((_DWORD *)v9 + 1) & 0x3FFFF;
  v11 = this->m_Params.eAlgoType == AKCONVALGOTYPE_DIRECT;
  this->m_ReverbState.uInputChannelMask = v10;
  if ( v11 )
  {
    this->m_ReverbState.uDownMixChannelMask = v10;
  }
  else
  {
    this->m_ReverbState.uDownMixChannelMask = 3;
    if ( ((v10 - 4) & 0xFFFFFFF3) == 0 )
    {
      uDownMixChannelMask = this->m_ReverbState.uDownMixChannelMask;
      if ( v10 != 16 )
        uDownMixChannelMask = 4;
      this->m_ReverbState.uDownMixChannelMask = uDownMixChannelMask;
    }
  }
  this->m_ReverbState.uSampleRate = v9->uSampleRate;
  this->m_ReverbState.bIsSentMode = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))in_pFXCtx->vfptr[1].__vecDelDtor)(in_pFXCtx);
  v21 = *v9;
  vfptr = in_pFXCtx->vfptr;
  *((_DWORD *)&v21 + 1) ^= (this->m_ReverbState.uDownMixChannelMask ^ *((_DWORD *)&v21 + 1)) & 0x3FFFF;
  in_pProcessorFeatures = vfptr->GetProcessorFeatures(in_pFXCtx);
  result = DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Init(
             &this->m_ConvolutionEngine,
             in_pAllocator,
             in_pFXCtx,
             &v21,
             in_pProcessorFeatures);
  if ( result == AK_Success )
  {
    this->m_ReverbState.uTailFrames = (int)(float)((float)((float)(this->m_Params.fFrontRearDelay + p_m_Params->fPreDelay)
                                                         * 0.001)
                                                 * (float)(int)this->m_ReverbState.uSampleRate)
                                    + this->m_ConvolutionEngine.m_FreqDataHeader.uBlockLength
                                    * this->m_ConvolutionEngine.m_FreqDataHeader.uNumCompressedPartition;
    result = CAkConvolutionReverbFX::SetupPreDelay(this);
    if ( result == AK_Success )
    {
      result = CAkConvolutionReverbFX::SetupFrontBackDelay(this);
      if ( result == AK_Success )
      {
        *(_QWORD *)this->m_ReverbState.uChannelIRMap = 0i64;
        if ( this->m_ConvolutionEngine.m_FreqDataHeader.uNumChannels > 1 )
        {
          v16 = *((_DWORD *)v9 + 1) & 0x3FFFF;
          if ( v16 <= 0x3B )
          {
            if ( v16 != 59 )
            {
              switch ( v16 )
              {
                case 3u:
                case 7u:
                case 0xBu:
                case 0xFu:
                  goto $LN6_178;
                case 0x33u:
                  goto $LN5_162;
                case 0x37u:
                  goto $LN4_164;
                default:
                  return 1;
              }
              return 1;
            }
$LN5_162:
            this->m_ReverbState.uChannelIRMap[3] = 1;
            goto $LN6_178;
          }
          v17 = v16 - 63;
          if ( !v17 )
            goto $LN4_164;
          v18 = v17 - 1524;
          if ( !v18 )
            goto LABEL_25;
          v19 = v18 - 4;
          if ( !v19 )
          {
LABEL_20:
            this->m_ReverbState.uChannelIRMap[6] = 1;
$LN4_164:
            this->m_ReverbState.uChannelIRMap[4] = 1;
$LN6_178:
            this->m_ReverbState.uChannelIRMap[1] = 1;
            return 1;
          }
          v20 = v19 - 4;
          if ( !v20 )
          {
LABEL_25:
            this->m_ReverbState.uChannelIRMap[3] = 1;
            this->m_ReverbState.uChannelIRMap[5] = 1;
            goto $LN6_178;
          }
          if ( v20 == 4 )
            goto LABEL_20;
        }
        return 1;
      }
    }
  }
  return result;
}

// File Line: 152
// RVA: 0xB17F60
__int64 __fastcall CAkConvolutionReverbFX::SetupPreDelay(CAkConvolutionReverbFX *this)
{
  unsigned int v2; // ebp
  unsigned int uDownMixChannelMask; // edx
  __int64 v4; // rbx
  unsigned int i; // edi
  __int64 result; // rax

  v2 = (int)(float)((float)(this->m_Params.fPreDelay * 0.001) * (float)(int)this->m_ReverbState.uSampleRate);
  if ( !v2 )
    return 1i64;
  uDownMixChannelMask = this->m_ReverbState.uDownMixChannelMask;
  v4 = 0i64;
  for ( i = 0; uDownMixChannelMask; uDownMixChannelMask &= uDownMixChannelMask - 1 )
    ++i;
  if ( !i )
    return 1i64;
  while ( 1 )
  {
    result = DSP::CDelayLight::Init(
               (DSP::CDelayLight *)((char *)this->m_ReverbState.PreDelay + 16 * v4 + 8 * v4),
               this->m_pAllocator,
               v2);
    if ( (_DWORD)result != 1 )
      break;
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= i )
      return 1i64;
  }
  return result;
}

// File Line: 168
// RVA: 0xB17E70
__int64 __fastcall CAkConvolutionReverbFX::SetupFrontBackDelay(CAkConvolutionReverbFX *this)
{
  unsigned int v2; // edx
  unsigned int v3; // edi
  __int64 result; // rax

  v2 = 1;
  v3 = (int)(float)((float)(this->m_Params.fFrontRearDelay * 0.001) * (float)(int)this->m_ReverbState.uSampleRate);
  if ( !v3 )
    return v2;
  if ( (this->m_ReverbState.uInputChannelMask & 0x10) == 0
    || (result = DSP::CDelayLight::Init(this->m_ReverbState.FrontBackDelay, this->m_pAllocator, v3),
        v2 = result,
        (_DWORD)result == 1) )
  {
    if ( (this->m_ReverbState.uInputChannelMask & 0x20) == 0
      || (result = DSP::CDelayLight::Init(&this->m_ReverbState.FrontBackDelay[1], this->m_pAllocator, v3),
          v2 = result,
          (_DWORD)result == 1) )
    {
      if ( (this->m_ReverbState.uInputChannelMask & 0x200) == 0
        || (result = DSP::CDelayLight::Init(&this->m_ReverbState.FrontBackDelay[2], this->m_pAllocator, v3),
            v2 = result,
            (_DWORD)result == 1) )
      {
        if ( (this->m_ReverbState.uInputChannelMask & 0x400) != 0 )
          return DSP::CDelayLight::Init(&this->m_ReverbState.FrontBackDelay[3], this->m_pAllocator, v3);
        return v2;
      }
    }
  }
  return result;
}

// File Line: 214
// RVA: 0xB16B00
__int64 __fastcall CAkConvolutionReverbFX::Term(CAkConvolutionReverbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Term(&this->m_ConvolutionEngine, in_pAllocator);
  CAkConvolutionReverbFX::TermPreDelay(this);
  DSP::CDelayLight::Term(this->m_ReverbState.FrontBackDelay, this->m_pAllocator);
  DSP::CDelayLight::Term(&this->m_ReverbState.FrontBackDelay[1], this->m_pAllocator);
  DSP::CDelayLight::Term(&this->m_ReverbState.FrontBackDelay[2], this->m_pAllocator);
  DSP::CDelayLight::Term(&this->m_ReverbState.FrontBackDelay[3], this->m_pAllocator);
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 225
// RVA: 0xB18060
void __fastcall CAkConvolutionReverbFX::TermPreDelay(CAkConvolutionReverbFX *this)
{
  unsigned int uDownMixChannelMask; // edx
  unsigned int i; // r8d
  __int64 v4; // rdi
  AkConvolutionReverbState *p_m_ReverbState; // rbx

  uDownMixChannelMask = this->m_ReverbState.uDownMixChannelMask;
  for ( i = 0; uDownMixChannelMask; uDownMixChannelMask &= uDownMixChannelMask - 1 )
    ++i;
  if ( i )
  {
    v4 = i;
    p_m_ReverbState = &this->m_ReverbState;
    do
    {
      DSP::CDelayLight::Term(p_m_ReverbState->PreDelay, this->m_pAllocator);
      p_m_ReverbState = (AkConvolutionReverbState *)((char *)p_m_ReverbState + 24);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 234
// RVA: 0xB18000
void __fastcall CAkConvolutionReverbFX::TermFrontBackDelay(CAkConvolutionReverbFX *this)
{
  DSP::CDelayLight::Term(this->m_ReverbState.FrontBackDelay, this->m_pAllocator);
  DSP::CDelayLight::Term(&this->m_ReverbState.FrontBackDelay[1], this->m_pAllocator);
  DSP::CDelayLight::Term(&this->m_ReverbState.FrontBackDelay[2], this->m_pAllocator);
  DSP::CDelayLight::Term(&this->m_ReverbState.FrontBackDelay[3], this->m_pAllocator);
}

// File Line: 253
// RVA: 0xB16BA0
__int64 __fastcall CAkConvolutionReverbFX::Reset(CAkConvolutionReverbFX *this)
{
  unsigned int uDownMixChannelMask; // edx
  unsigned int i; // r8d
  __int64 v4; // rdi
  AkConvolutionReverbState *p_m_ReverbState; // rbx

  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Reset(&this->m_ConvolutionEngine);
  uDownMixChannelMask = this->m_ReverbState.uDownMixChannelMask;
  for ( i = 0; uDownMixChannelMask; uDownMixChannelMask &= uDownMixChannelMask - 1 )
    ++i;
  if ( i )
  {
    v4 = i;
    p_m_ReverbState = &this->m_ReverbState;
    do
    {
      DSP::CDelayLight::Reset(p_m_ReverbState->PreDelay);
      p_m_ReverbState = (AkConvolutionReverbState *)((char *)p_m_ReverbState + 24);
      --v4;
    }
    while ( v4 );
  }
  DSP::CDelayLight::Reset(this->m_ReverbState.FrontBackDelay);
  DSP::CDelayLight::Reset(&this->m_ReverbState.FrontBackDelay[1]);
  DSP::CDelayLight::Reset(&this->m_ReverbState.FrontBackDelay[2]);
  DSP::CDelayLight::Reset(&this->m_ReverbState.FrontBackDelay[3]);
  return 1i64;
}

// File Line: 271
// RVA: 0xB17E30
void __fastcall CAkConvolutionReverbFX::ResetFrontBackDelay(CAkConvolutionReverbFX *this)
{
  DSP::CDelayLight::Reset(this->m_ReverbState.FrontBackDelay);
  DSP::CDelayLight::Reset(&this->m_ReverbState.FrontBackDelay[1]);
  DSP::CDelayLight::Reset(&this->m_ReverbState.FrontBackDelay[2]);
  DSP::CDelayLight::Reset(&this->m_ReverbState.FrontBackDelay[3]);
}

// File Line: 290
// RVA: 0xB16C40
__int64 __fastcall CAkConvolutionReverbFX::GetPluginInfo(CAkConvolutionReverbFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 302
// RVA: 0xB17550
void __fastcall CAkConvolutionReverbFX::SetDownMixChannelMask(
        CAkConvolutionReverbFX *this,
        unsigned int in_uInputChannelMask)
{
  unsigned int uDownMixChannelMask; // eax

  if ( this->m_Params.eAlgoType == AKCONVALGOTYPE_DIRECT )
  {
    this->m_ReverbState.uDownMixChannelMask = in_uInputChannelMask;
  }
  else
  {
    this->m_ReverbState.uDownMixChannelMask = 3;
    if ( ((in_uInputChannelMask - 4) & 0xFFFFFFF3) == 0 )
    {
      uDownMixChannelMask = this->m_ReverbState.uDownMixChannelMask;
      if ( in_uInputChannelMask != 16 )
        uDownMixChannelMask = 4;
      this->m_ReverbState.uDownMixChannelMask = uDownMixChannelMask;
    }
  }
}

// File Line: 350
// RVA: 0xB172F0
char __fastcall CAkConvolutionReverbFX::ParametersUpdate(CAkConvolutionReverbFX *this, unsigned int in_uMaxFrames)
{
  AkConvolutionAlgoType eAlgoType; // eax
  unsigned int uInputChannelMask; // ecx
  unsigned int uDownMixChannelMask; // eax
  unsigned int v6; // ecx
  unsigned int i; // r8d
  unsigned int v9; // ecx
  unsigned int j; // edx
  AkConvolutionReverbState *p_m_ReverbState; // rdi
  __int64 v12; // rsi
  unsigned int v13; // ecx
  unsigned int k; // edx
  AkConvolutionReverbState *v15; // rdi
  __int64 v16; // rsi

  CAkConvolutionReverbFXParams::GetParams(this->m_pSharedParams, &this->m_Params);
  eAlgoType = this->m_Params.eAlgoType;
  if ( this->m_PrevParams.eAlgoType != eAlgoType )
  {
    uInputChannelMask = this->m_ReverbState.uInputChannelMask;
    if ( eAlgoType == AKCONVALGOTYPE_DIRECT )
    {
      this->m_ReverbState.uDownMixChannelMask = uInputChannelMask;
    }
    else
    {
      this->m_ReverbState.uDownMixChannelMask = 3;
      if ( ((uInputChannelMask - 4) & 0xFFFFFFF3) == 0 )
      {
        uDownMixChannelMask = this->m_ReverbState.uDownMixChannelMask;
        if ( uInputChannelMask != 16 )
          uDownMixChannelMask = 4;
        this->m_ReverbState.uDownMixChannelMask = uDownMixChannelMask;
      }
    }
    v6 = this->m_ReverbState.uDownMixChannelMask;
    for ( i = 0; v6; v6 &= v6 - 1 )
      ++i;
    if ( DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::InitOLABuffer(
           &this->m_ConvolutionEngine,
           this->m_pAllocator,
           i) != AK_Success )
      return 0;
    DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Reset(&this->m_ConvolutionEngine);
  }
  if ( this->m_Params.fPreDelay != this->m_PrevParams.fPreDelay
    || this->m_PrevParams.eAlgoType != this->m_Params.eAlgoType )
  {
    v9 = this->m_ReverbState.uDownMixChannelMask;
    for ( j = 0; v9; v9 &= v9 - 1 )
      ++j;
    if ( j )
    {
      p_m_ReverbState = &this->m_ReverbState;
      v12 = j;
      do
      {
        DSP::CDelayLight::Term(p_m_ReverbState->PreDelay, this->m_pAllocator);
        p_m_ReverbState = (AkConvolutionReverbState *)((char *)p_m_ReverbState + 24);
        --v12;
      }
      while ( v12 );
    }
    if ( CAkConvolutionReverbFX::SetupPreDelay(this) != AK_Success )
      return 0;
    v13 = this->m_ReverbState.uDownMixChannelMask;
    for ( k = 0; v13; v13 &= v13 - 1 )
      ++k;
    if ( k )
    {
      v15 = &this->m_ReverbState;
      v16 = k;
      do
      {
        DSP::CDelayLight::Reset(v15->PreDelay);
        v15 = (AkConvolutionReverbState *)((char *)v15 + 24);
        --v16;
      }
      while ( v16 );
    }
    this->m_ReverbState.uTailFrames = this->m_ConvolutionEngine.m_FreqDataHeader.uBlockLength
                                    * this->m_ConvolutionEngine.m_FreqDataHeader.uNumCompressedPartition
                                    + (int)(float)((float)((float)(this->m_Params.fFrontRearDelay
                                                                 + this->m_Params.fPreDelay)
                                                         * 0.001)
                                                 * (float)(int)this->m_ReverbState.uSampleRate);
  }
  if ( this->m_Params.fFrontRearDelay != this->m_PrevParams.fFrontRearDelay )
  {
    CAkConvolutionReverbFX::TermFrontBackDelay(this);
    if ( CAkConvolutionReverbFX::SetupFrontBackDelay(this) != AK_Success )
      return 0;
    CAkConvolutionReverbFX::ResetFrontBackDelay(this);
    this->m_ReverbState.uTailFrames = this->m_ConvolutionEngine.m_FreqDataHeader.uBlockLength
                                    * this->m_ConvolutionEngine.m_FreqDataHeader.uNumCompressedPartition
                                    + (int)(float)((float)((float)(this->m_Params.fFrontRearDelay
                                                                 + this->m_Params.fPreDelay)
                                                         * 0.001)
                                                 * (float)(int)this->m_ReverbState.uSampleRate);
  }
  if ( this->m_ReverbState.bIsSentMode )
  {
    this->m_PrevParams.fDryLevel = 0.0;
    this->m_Params.fDryLevel = 0.0;
  }
  return 1;
}

// File Line: 399
// RVA: 0xB172A0
void __fastcall CAkConvolutionReverbFX::ComputeTailFrames(CAkConvolutionReverbFX *this)
{
  this->m_ReverbState.uTailFrames = this->m_ConvolutionEngine.m_FreqDataHeader.uBlockLength
                                  * this->m_ConvolutionEngine.m_FreqDataHeader.uNumCompressedPartition
                                  + (int)(float)((float)((float)(this->m_Params.fFrontRearDelay
                                                               + this->m_Params.fPreDelay)
                                                       * 0.001)
                                               * (float)(int)this->m_ReverbState.uSampleRate);
}

// File Line: 410
// RVA: 0xB16C60
void __fastcall CAkConvolutionReverbFX::Execute(CAkConvolutionReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // r14
  CAkConvolutionReverbFX *v3; // rdi
  unsigned int uTailFrames; // ecx
  unsigned int uTailFramesRemaining; // edx
  unsigned int uTotalTailFrames; // r8d
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ebx
  __int64 v10; // rsi
  __int64 v11; // rbx
  unsigned int uDownMixChannelMask; // edx
  unsigned int i; // r9d
  void *v14; // rax
  void *v15; // r13
  unsigned int v16; // esi
  unsigned int j; // ecx
  unsigned int uValidFrames; // r13d
  float in_fInputLFELevel; // xmm0_4
  float in_fPrevInputLFELevel; // xmm1_4
  float fInputCenterLevel; // xmm3_4
  float v22; // xmm2_4
  unsigned int in_uChannelIndex; // ebx
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *p_m_ConvolutionEngine; // r10
  __int64 v25; // r15
  AkConvolutionReverbState *p_m_ReverbState; // rbp
  DSP::CDelayLight *PreDelay; // r14
  unsigned int v28; // edi
  __int64 v29; // rcx
  float *v30; // r12
  unsigned int in_uIRChannelIndex; // eax
  unsigned int uChannelMask; // ecx
  unsigned int k; // r15d
  unsigned int uInputChannelMask; // eax
  unsigned int v35; // ebp
  unsigned __int8 v36; // r12
  unsigned int v37; // ebx
  size_t v38; // r8
  __int64 v39; // rdx
  char *v40; // rsi
  DSP::CDelayLight *FrontBackDelay; // rcx
  unsigned int m_uOLAIndex; // ecx
  unsigned __int8 v43; // [rsp+40h] [rbp-A8h]
  ak_fft_cpx *io_pfFFTBufferFD; // [rsp+48h] [rbp-A0h]
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *v45; // [rsp+50h] [rbp-98h]
  __int64 v46; // [rsp+50h] [rbp-98h]
  AkConvolutionReverbState *v47; // [rsp+58h] [rbp-90h]
  char *uChannelIRMap; // [rsp+60h] [rbp-88h]
  DSP::CDelayLight *v49; // [rsp+68h] [rbp-80h]
  float *io_pfFFTBufferTD; // [rsp+70h] [rbp-78h]
  AkAudioBuffer out_pDownMixBuffer; // [rsp+78h] [rbp-70h] BYREF
  size_t v52; // [rsp+90h] [rbp-58h]
  bool v55; // [rsp+F8h] [rbp+10h]
  bool v56; // [rsp+100h] [rbp+18h]
  void *v57; // [rsp+108h] [rbp+20h]
  bool v58; // [rsp+108h] [rbp+20h]

  v2 = io_pBuffer;
  v3 = this;
  if ( !CAkConvolutionReverbFX::ParametersUpdate(this, io_pBuffer->uMaxFrames) )
    return;
  uTailFrames = v3->m_ReverbState.uTailFrames;
  if ( v2->eState != AK_NoMoreData )
  {
    v3->m_ReverbState.FXTailHandler.uTailFramesRemaining = -1;
    goto LABEL_14;
  }
  uTailFramesRemaining = v3->m_ReverbState.FXTailHandler.uTailFramesRemaining;
  if ( !uTailFramesRemaining )
    goto LABEL_14;
  if ( uTailFramesRemaining == -1 )
  {
    v3->m_ReverbState.FXTailHandler.uTailFramesRemaining = uTailFrames;
LABEL_8:
    v3->m_ReverbState.FXTailHandler.uTotalTailFrames = uTailFrames;
    goto LABEL_9;
  }
  uTotalTailFrames = v3->m_ReverbState.FXTailHandler.uTotalTailFrames;
  if ( uTailFrames > uTotalTailFrames )
  {
    v3->m_ReverbState.FXTailHandler.uTailFramesRemaining = uTailFramesRemaining + uTailFrames - uTotalTailFrames;
    goto LABEL_8;
  }
LABEL_9:
  v7 = v2->uMaxFrames - v2->uValidFrames;
  v8 = v3->m_ReverbState.FXTailHandler.uTailFramesRemaining;
  if ( v8 < v7 )
    v7 = v3->m_ReverbState.FXTailHandler.uTailFramesRemaining;
  v3->m_ReverbState.FXTailHandler.uTailFramesRemaining = v8 - v7;
  AkAudioBuffer::ZeroPadToMaxFrames(v2);
  if ( v3->m_ReverbState.FXTailHandler.uTailFramesRemaining )
    v2->eState = AK_DataReady;
LABEL_14:
  if ( !v2->uValidFrames )
    return;
  v9 = 8 * (v3->m_ConvolutionEngine.m_FreqDataHeader.uFFTLength >> 1) + 8;
  v10 = (__int64)v3->m_pAllocator->vfptr->Malloc(v3->m_pAllocator, v9);
  io_pfFFTBufferFD = (ak_fft_cpx *)v10;
  v11 = (__int64)v3->m_pAllocator->vfptr->Malloc(v3->m_pAllocator, v9);
  io_pfFFTBufferTD = (float *)v11;
  if ( v3->m_Params.eAlgoType )
  {
    v14 = v3->m_pAllocator->vfptr->Malloc(v3->m_pAllocator, 4i64 * v2->uMaxFrames);
  }
  else
  {
    uDownMixChannelMask = v3->m_ReverbState.uDownMixChannelMask;
    for ( i = 0; uDownMixChannelMask; uDownMixChannelMask &= uDownMixChannelMask - 1 )
      ++i;
    v14 = v3->m_pAllocator->vfptr->Malloc(v3->m_pAllocator, 4 * i * (unsigned __int64)v2->uValidFrames);
  }
  v15 = v14;
  v57 = v14;
  if ( !v14 )
    goto $Cleanup;
  if ( v10 )
  {
    if ( !v11 )
    {
$Cleanup:
      if ( v10 )
        v3->m_pAllocator->vfptr->Free(v3->m_pAllocator, (void *)v10);
      goto LABEL_60;
    }
    if ( v3->m_Params.eAlgoType == AKCONVALGOTYPE_DOWNMIX )
    {
      v16 = 0;
      for ( j = v3->m_ReverbState.uDownMixChannelMask; j; j &= j - 1 )
        ++v16;
      uValidFrames = v2->uValidFrames;
      in_fInputLFELevel = v3->m_Params.fInputLFELevel;
      in_fPrevInputLFELevel = v3->m_PrevParams.fInputLFELevel;
      fInputCenterLevel = v3->m_Params.fInputCenterLevel;
      v22 = v3->m_PrevParams.fInputCenterLevel;
      out_pDownMixBuffer.uChannelMask = v3->m_ReverbState.uDownMixChannelMask;
      out_pDownMixBuffer.pData = v14;
      out_pDownMixBuffer.uMaxFrames = uValidFrames;
      out_pDownMixBuffer.uValidFrames = uValidFrames;
      DSP::AkDownMix(v2, &out_pDownMixBuffer, v22, fInputCenterLevel, in_fPrevInputLFELevel, in_fInputLFELevel);
      in_uChannelIndex = 0;
      if ( v16 )
      {
        p_m_ConvolutionEngine = &v3->m_ConvolutionEngine;
        v25 = 0i64;
        p_m_ReverbState = &v3->m_ReverbState;
        PreDelay = v3->m_ReverbState.PreDelay;
        v45 = &v3->m_ConvolutionEngine;
        v28 = v3->m_ConvolutionEngine.m_FreqDataHeader.uNumChannels - 1;
        do
        {
          v29 = v25 * out_pDownMixBuffer.uMaxFrames;
          v30 = (float *)((char *)out_pDownMixBuffer.pData + 4 * v29);
          in_uIRChannelIndex = v28;
          if ( in_uChannelIndex < v28 )
            in_uIRChannelIndex = in_uChannelIndex;
          DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::ExecuteChannelInPlace(
            p_m_ConvolutionEngine,
            (float *)out_pDownMixBuffer.pData + v29,
            uValidFrames,
            io_pfFFTBufferTD,
            io_pfFFTBufferFD,
            0i64,
            in_uChannelIndex,
            in_uIRChannelIndex);
          if ( p_m_ReverbState->PreDelay[0].m_uDelayLineLength )
            DSP::CDelayLight::ProcessBuffer(PreDelay, v30, uValidFrames);
          p_m_ConvolutionEngine = v45;
          ++in_uChannelIndex;
          ++v25;
          ++PreDelay;
          p_m_ReverbState = (AkConvolutionReverbState *)((char *)p_m_ReverbState + 24);
        }
        while ( in_uChannelIndex < v16 );
        v3 = this;
        v2 = io_pBuffer;
      }
      CAkConvolutionReverbFX::UpMix(v3, v2, &out_pDownMixBuffer);
      v15 = v57;
LABEL_54:
      v10 = (__int64)io_pfFFTBufferFD;
      goto LABEL_55;
    }
    uChannelMask = v2->uChannelMask;
    for ( k = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++k;
    uInputChannelMask = v3->m_ReverbState.uInputChannelMask;
    v35 = v2->uValidFrames;
    v56 = (uInputChannelMask & 0x30) != 0;
    v36 = ((uInputChannelMask & 4) != 0) | 2;
    v58 = (uInputChannelMask & 0x600) != 0;
    v55 = v3->m_ReverbState.FrontBackDelay[0].m_uDelayLineLength != 0;
    v43 = v36 + 2;
    v37 = 0;
    if ( !k )
    {
LABEL_55:
      ++v3->m_ConvolutionEngine.m_uOLAIndex;
      v11 = (__int64)io_pfFFTBufferTD;
      m_uOLAIndex = v3->m_ConvolutionEngine.m_uOLAIndex;
      if ( m_uOLAIndex >= v3->m_ConvolutionEngine.m_FreqDataHeader.uNumCompressedPartition )
        m_uOLAIndex = 0;
      v3->m_ConvolutionEngine.m_uOLAIndex = m_uOLAIndex;
      v3->m_PrevParams.fPreDelay = v3->m_Params.fPreDelay;
      v3->m_PrevParams.fFrontRearDelay = v3->m_Params.fFrontRearDelay;
      v3->m_PrevParams.fStereoWidth = v3->m_Params.fStereoWidth;
      v3->m_PrevParams.fInputCenterLevel = v3->m_Params.fInputCenterLevel;
      v3->m_PrevParams.fInputLFELevel = v3->m_Params.fInputLFELevel;
      v3->m_PrevParams.fFrontLevel = v3->m_Params.fFrontLevel;
      v3->m_PrevParams.fRearLevel = v3->m_Params.fRearLevel;
      v3->m_PrevParams.fCenterLevel = v3->m_Params.fCenterLevel;
      v3->m_PrevParams.fLFELevel = v3->m_Params.fLFELevel;
      v3->m_PrevParams.fDryLevel = v3->m_Params.fDryLevel;
      v3->m_PrevParams.fWetLevel = v3->m_Params.fWetLevel;
      v3->m_PrevParams.eAlgoType = v3->m_Params.eAlgoType;
      goto $Cleanup;
    }
    v38 = 4 * v35;
    v39 = 0i64;
    uChannelIRMap = v3->m_ReverbState.uChannelIRMap;
    v52 = v38;
    v47 = &v3->m_ReverbState;
    v49 = v3->m_ReverbState.PreDelay;
    v46 = 0i64;
    while ( 1 )
    {
      v40 = (char *)v2->pData + 4 * v39 * v2->uMaxFrames;
      memmove(v15, v40, v38);
      DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::ExecuteChannelInPlace(
        &v3->m_ConvolutionEngine,
        (float *)v40,
        v35,
        io_pfFFTBufferTD,
        io_pfFFTBufferFD,
        0i64,
        v37,
        (unsigned __int8)*uChannelIRMap);
      if ( v47->PreDelay[0].m_uDelayLineLength )
        DSP::CDelayLight::ProcessBuffer(v49, (float *)v40, v35);
      if ( !v55 )
        goto LABEL_53;
      if ( v56 )
      {
        if ( v37 == v36 )
        {
          FrontBackDelay = v3->m_ReverbState.FrontBackDelay;
LABEL_52:
          DSP::CDelayLight::ProcessBuffer(FrontBackDelay, (float *)v40, v35);
          goto LABEL_53;
        }
        if ( v37 == v36 + 1 )
        {
          FrontBackDelay = &v3->m_ReverbState.FrontBackDelay[1];
          goto LABEL_52;
        }
      }
      if ( v58 )
      {
        if ( v37 == v43 )
        {
          FrontBackDelay = &v3->m_ReverbState.FrontBackDelay[2];
          goto LABEL_52;
        }
        if ( v37 == v43 + 1 )
        {
          FrontBackDelay = &v3->m_ReverbState.FrontBackDelay[3];
          goto LABEL_52;
        }
      }
LABEL_53:
      DSP::Mix2Interp(
        (float *)v40,
        (float *)v15,
        COERCE_DOUBLE((unsigned __int64)LODWORD(v3->m_PrevParams.fWetLevel)),
        COERCE_DOUBLE((unsigned __int64)LODWORD(v3->m_Params.fWetLevel)),
        v3->m_PrevParams.fDryLevel,
        v3->m_Params.fDryLevel,
        v35);
      ++v49;
      ++uChannelIRMap;
      v47 = (AkConvolutionReverbState *)((char *)v47 + 24);
      v38 = v52;
      v39 = v46 + 1;
      ++v37;
      ++v46;
      if ( v37 >= k )
        goto LABEL_54;
    }
  }
LABEL_60:
  if ( v11 )
    v3->m_pAllocator->vfptr->Free(v3->m_pAllocator, (void *)v11);
  if ( v15 )
    v3->m_pAllocator->vfptr->Free(v3->m_pAllocator, v15);
}

// File Line: 608
// RVA: 0xB175A0
void __fastcall CAkConvolutionReverbFX::UpMix(
        CAkConvolutionReverbFX *this,
        AkAudioBuffer *io_pBuffer,
        AkAudioBuffer *in_rDownMixBuffer)
{
  __int64 in_uNumFrames; // rbp
  unsigned int uInputChannelMask; // ecx
  unsigned int v8; // ecx
  float *v9; // rsi
  unsigned int v10; // r9d
  unsigned int v11; // edx
  unsigned int i; // ebx
  __m128 *v13; // rax
  __m128 *v14; // r15
  float *pData; // rdx
  float *v16; // rcx
  float v17; // xmm1_4
  float *v18; // rbx
  unsigned int uChannelMask; // ecx
  float fLFELevel; // xmm0_4
  float fFrontLevel; // xmm1_4
  AkAudioBuffer in_upMixBuffer; // [rsp+40h] [rbp-58h] BYREF

  in_uNumFrames = io_pBuffer->uValidFrames;
  uInputChannelMask = this->m_ReverbState.uInputChannelMask;
  if ( ((uInputChannelMask - 4) & 0xFFFFFFFB) == 0 )
  {
    if ( uInputChannelMask == 8 )
    {
      fLFELevel = this->m_PrevParams.fLFELevel;
      fFrontLevel = this->m_Params.fLFELevel;
    }
    else
    {
      fLFELevel = this->m_PrevParams.fFrontLevel;
      fFrontLevel = this->m_Params.fFrontLevel;
    }
    DSP::Mix2Interp(
      (float *)io_pBuffer->pData,
      (float *)in_rDownMixBuffer->pData,
      COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_PrevParams.fDryLevel)),
      COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Params.fDryLevel)),
      fLFELevel * this->m_PrevParams.fWetLevel,
      fFrontLevel * this->m_Params.fWetLevel,
      in_uNumFrames);
    return;
  }
  v8 = uInputChannelMask & 0xFFFFFFF7;
  v9 = 0i64;
  v10 = v8;
  v11 = 0;
  if ( !v8 )
    goto LABEL_6;
  do
  {
    ++v11;
    v10 &= v10 - 1;
  }
  while ( v10 );
  if ( v11 > 2 )
  {
    i = 2;
  }
  else
  {
LABEL_6:
    for ( i = 0; v8; v8 &= v8 - 1 )
      ++i;
  }
  v13 = (__m128 *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 4 * in_uNumFrames * i);
  v14 = v13;
  if ( v13 )
  {
    in_upMixBuffer.pData = v13;
    in_upMixBuffer.uMaxFrames = in_uNumFrames;
    in_upMixBuffer.uValidFrames = in_uNumFrames;
    in_upMixBuffer.uChannelMask = (i != 2) + 3;
    if ( (this->m_ReverbState.uInputChannelMask & 7) == 3 )
    {
      v18 = &v13->m128_f32[in_uNumFrames];
      DSP::MixStereoWidth(
        (float *)in_rDownMixBuffer->pData,
        (float *)in_rDownMixBuffer->pData + in_rDownMixBuffer->uMaxFrames,
        v13->m128_f32,
        v18,
        in_uNumFrames,
        this->m_PrevParams.fStereoWidth,
        this->m_Params.fStereoWidth);
      DSP::Mix2Interp(
        (float *)io_pBuffer->pData,
        v14->m128_f32,
        COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_PrevParams.fDryLevel)),
        COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Params.fDryLevel)),
        this->m_PrevParams.fWetLevel * this->m_PrevParams.fFrontLevel,
        this->m_Params.fFrontLevel * this->m_Params.fWetLevel,
        in_uNumFrames);
      v16 = (float *)((char *)io_pBuffer->pData + 4 * io_pBuffer->uMaxFrames);
      pData = v18;
      v17 = this->m_Params.fFrontLevel * this->m_Params.fWetLevel;
    }
    else
    {
      if ( (this->m_ReverbState.uInputChannelMask & 7) != 4 )
      {
        if ( (this->m_ReverbState.uInputChannelMask & 7) == 7 )
        {
          DSP::Mix2Interp(
            (float *)in_rDownMixBuffer->pData,
            (float *)in_rDownMixBuffer->pData + in_rDownMixBuffer->uMaxFrames,
            v13,
            COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_45449999)),
            0.45449999,
            0.45449999,
            0.45449999,
            in_uNumFrames);
          DSP::Mix2Interp(
            (float *)io_pBuffer->pData + 2 * io_pBuffer->uMaxFrames,
            v14->m128_f32,
            COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_PrevParams.fDryLevel)),
            COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Params.fDryLevel)),
            this->m_PrevParams.fCenterLevel * this->m_PrevParams.fWetLevel,
            this->m_Params.fCenterLevel * this->m_Params.fWetLevel,
            in_uNumFrames);
          DSP::Mix2Interp(
            (float *)in_rDownMixBuffer->pData,
            (float *)in_rDownMixBuffer->pData + in_rDownMixBuffer->uMaxFrames,
            v14,
            COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_88300002)),
            0.88300002,
            -0.117,
            -0.117,
            in_uNumFrames);
          DSP::Mix2Interp(
            (float *)in_rDownMixBuffer->pData + in_rDownMixBuffer->uMaxFrames,
            (float *)in_rDownMixBuffer->pData,
            (__m128 *)((char *)v14 + 4 * in_uNumFrames),
            COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_88300002)),
            0.88300002,
            -0.117,
            -0.117,
            in_uNumFrames);
          DSP::MixStereoWidth(
            v14->m128_f32,
            &v14->m128_f32[in_uNumFrames],
            in_uNumFrames,
            this->m_PrevParams.fStereoWidth,
            this->m_Params.fStereoWidth);
          DSP::Mix2Interp(
            (float *)io_pBuffer->pData,
            v14->m128_f32,
            COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_PrevParams.fDryLevel)),
            COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Params.fDryLevel)),
            this->m_PrevParams.fWetLevel * this->m_PrevParams.fFrontLevel,
            this->m_Params.fFrontLevel * this->m_Params.fWetLevel,
            in_uNumFrames);
          DSP::Mix2Interp(
            (float *)io_pBuffer->pData + io_pBuffer->uMaxFrames,
            &v14->m128_f32[in_uNumFrames],
            COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_PrevParams.fDryLevel)),
            COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Params.fDryLevel)),
            this->m_PrevParams.fWetLevel * this->m_PrevParams.fFrontLevel,
            this->m_Params.fFrontLevel * this->m_Params.fWetLevel,
            in_uNumFrames);
        }
        goto LABEL_16;
      }
      pData = (float *)in_rDownMixBuffer->pData;
      v16 = (float *)io_pBuffer->pData;
      v17 = this->m_Params.fWetLevel * this->m_Params.fFrontLevel;
    }
    DSP::Mix2Interp(
      v16,
      pData,
      COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_PrevParams.fDryLevel)),
      COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Params.fDryLevel)),
      this->m_PrevParams.fWetLevel * this->m_PrevParams.fFrontLevel,
      v17,
      in_uNumFrames);
LABEL_16:
    if ( (this->m_ReverbState.uInputChannelMask & 0x30) != 0 )
    {
      memmove(v14, in_rDownMixBuffer->pData, (unsigned int)(4 * in_uNumFrames));
      memmove(
        &v14->m128_f32[in_uNumFrames],
        (char *)in_rDownMixBuffer->pData + 4 * in_rDownMixBuffer->uMaxFrames,
        (unsigned int)(4 * in_uNumFrames));
      CAkConvolutionReverbFX::ProcessSurroundChannels(this, io_pBuffer, &in_upMixBuffer, in_uNumFrames);
    }
    if ( (this->m_ReverbState.uInputChannelMask & 8) != 0 )
    {
      uChannelMask = io_pBuffer->uChannelMask;
      if ( (uChannelMask & 8) != 0 )
      {
        for ( ; uChannelMask; uChannelMask &= uChannelMask - 1 )
          LODWORD(v9) = (_DWORD)v9 + 1;
        v9 = (float *)((char *)io_pBuffer->pData
                     + 4 * io_pBuffer->uMaxFrames * (unsigned __int64)(unsigned int)((_DWORD)v9 - 1));
      }
      DSP::Mix2Interp(
        v9,
        (float *)in_rDownMixBuffer->pData,
        COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_PrevParams.fDryLevel)),
        COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Params.fDryLevel)),
        this->m_PrevParams.fWetLevel * this->m_PrevParams.fLFELevel,
        this->m_Params.fWetLevel * this->m_Params.fLFELevel,
        in_uNumFrames);
    }
    this->m_pAllocator->vfptr->Free(this->m_pAllocator, v14);
  }
}

// File Line: 766
// RVA: 0xB17AC0
void __fastcall CAkConvolutionReverbFX::ProcessSurroundChannels(
        CAkConvolutionReverbFX *this,
        AkAudioBuffer *io_pBuffer,
        AkAudioBuffer *in_upMixBuffer,
        unsigned int in_uNumFrames)
{
  DSP::CDelayLight *FrontBackDelay; // rcx
  unsigned __int8 v9; // bl
  unsigned __int8 v10; // bl

  FrontBackDelay = this->m_ReverbState.FrontBackDelay;
  if ( FrontBackDelay->m_uDelayLineLength )
    DSP::CDelayLight::ProcessBuffer(FrontBackDelay, (float *)in_upMixBuffer->pData, in_uNumFrames);
  if ( this->m_ReverbState.FrontBackDelay[1].m_uDelayLineLength )
    DSP::CDelayLight::ProcessBuffer(
      &this->m_ReverbState.FrontBackDelay[1],
      (float *)in_upMixBuffer->pData + in_upMixBuffer->uMaxFrames,
      in_uNumFrames);
  DSP::MixStereoWidth(
    (float *)in_upMixBuffer->pData,
    (float *)in_upMixBuffer->pData + in_upMixBuffer->uMaxFrames,
    in_uNumFrames,
    this->m_PrevParams.fStereoWidth,
    this->m_Params.fStereoWidth);
  v9 = ((this->m_ReverbState.uInputChannelMask & 4) != 0) | 2;
  DSP::Mix2Interp(
    (float *)io_pBuffer->pData + v9 * (unsigned __int64)io_pBuffer->uMaxFrames,
    (float *)in_upMixBuffer->pData,
    COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_PrevParams.fDryLevel)),
    COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Params.fDryLevel)),
    this->m_PrevParams.fRearLevel * this->m_PrevParams.fWetLevel,
    this->m_Params.fWetLevel * this->m_Params.fRearLevel,
    in_uNumFrames);
  DSP::Mix2Interp(
    (float *)io_pBuffer->pData + io_pBuffer->uMaxFrames * (unsigned __int64)((unsigned int)v9 + 1),
    (float *)in_upMixBuffer->pData + in_upMixBuffer->uMaxFrames,
    COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_PrevParams.fDryLevel)),
    COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Params.fDryLevel)),
    this->m_PrevParams.fRearLevel * this->m_PrevParams.fWetLevel,
    this->m_Params.fWetLevel * this->m_Params.fRearLevel,
    in_uNumFrames);
  if ( (this->m_ReverbState.uInputChannelMask & 0x600) != 0 )
  {
    v10 = ((this->m_ReverbState.uInputChannelMask & 4) != 0) | 4;
    DSP::Mix2Interp(
      (float *)io_pBuffer->pData + v10 * (unsigned __int64)io_pBuffer->uMaxFrames,
      (float *)in_upMixBuffer->pData,
      COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_PrevParams.fDryLevel)),
      COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Params.fDryLevel)),
      this->m_PrevParams.fRearLevel * this->m_PrevParams.fWetLevel,
      this->m_Params.fWetLevel * this->m_Params.fRearLevel,
      in_uNumFrames);
    DSP::Mix2Interp(
      (float *)io_pBuffer->pData + io_pBuffer->uMaxFrames * (unsigned __int64)((unsigned int)v10 + 1),
      (float *)in_upMixBuffer->pData + in_upMixBuffer->uMaxFrames,
      COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_PrevParams.fDryLevel)),
      COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Params.fDryLevel)),
      this->m_PrevParams.fRearLevel * this->m_PrevParams.fWetLevel,
      this->m_Params.fWetLevel * this->m_Params.fRearLevel,
      in_uNumFrames);
  }
}

// File Line: 819
// RVA: 0xB17280
char __fastcall CAkConvolutionReverbFX::SupportMediaRelocation(CAkConvolutionReverbFX *this)
{
  return 1;
}

// File Line: 824
// RVA: 0xB17290
AKRESULT __fastcall CAkConvolutionReverbFX::RelocateMedia(
        CAkConvolutionReverbFX *this,
        char *in_pNewMedia,
        char *in_pOldMedia)
{
  return DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::RelocateMedia(
           &this->m_ConvolutionEngine,
           in_pNewMedia,
           in_pOldMedia);
}

