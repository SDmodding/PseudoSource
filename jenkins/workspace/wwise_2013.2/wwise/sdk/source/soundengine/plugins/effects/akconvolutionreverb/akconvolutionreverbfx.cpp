// File Line: 28
// RVA: 0xB166D0
void __fastcall CreateConvolutionReverbFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkConvolutionReverbFX *v1; // rax

  v1 = (CAkConvolutionReverbFX *)in_pAllocator->vfptr->Malloc(in_pAllocator, 608ui64);
  if ( v1 )
    CAkConvolutionReverbFX::CAkConvolutionReverbFX(v1);
}

// File Line: 36
// RVA: 0xB16700
void __fastcall CAkConvolutionReverbFX::CAkConvolutionReverbFX(CAkConvolutionReverbFX *this)
{
  CAkConvolutionReverbFX *v1; // rbx
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *v2; // rcx

  v1 = this;
  v2 = &this->m_ConvolutionEngine;
  *(_QWORD *)&v2[-1].m_uNumInputChannels = &CAkConvolutionReverbFX::`vftable';
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::CAkPartitionedConvolutionEngine(v2);
  v1->m_Params.fStereoWidth = 180.0;
  *(_QWORD *)&v1->m_Params.fInputCenterLevel = 1065353216i64;
  v1->m_Params.fFrontLevel = 1.0;
  v1->m_Params.fRearLevel = 1.0;
  *(_QWORD *)&v1->m_Params.fCenterLevel = 1065353216i64;
  v1->m_Params.fDryLevel = 1.0;
  *(_QWORD *)&v1->m_Params.fWetLevel = 1048576000i64;
  *(_QWORD *)&v1->m_Params.fPreDelay = 0i64;
  *(_QWORD *)&v1->m_PrevParams.fPreDelay = 0i64;
  v1->m_PrevParams.fStereoWidth = 180.0;
  *(_QWORD *)&v1->m_PrevParams.fInputCenterLevel = 1065353216i64;
  v1->m_PrevParams.fFrontLevel = 1.0;
  v1->m_PrevParams.fRearLevel = 1.0;
  *(_QWORD *)&v1->m_PrevParams.fCenterLevel = 1065353216i64;
  v1->m_PrevParams.fDryLevel = 1.0;
  *(_QWORD *)&v1->m_PrevParams.fWetLevel = 1048576000i64;
  AkConvolutionReverbState::AkConvolutionReverbState(&v1->m_ReverbState);
  v1->m_pSharedParams = 0i64;
  v1->m_pAllocator = 0i64;
}

// File Line: 42
// RVA: 0xB16800
void __fastcall CAkConvolutionReverbFX::~CAkConvolutionReverbFX(CAkConvolutionReverbFX *this)
{
  CAkConvolutionReverbFX *v1; // rbx
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *v2; // rcx

  v1 = this;
  v2 = &this->m_ConvolutionEngine;
  *(_QWORD *)&v2[-1].m_uNumInputChannels = &CAkConvolutionReverbFX::`vftable';
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::~CAkPartitionedConvolutionEngine(v2);
  v1->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

// File Line: 52
// RVA: 0xB16840
AKRESULT __fastcall CAkConvolutionReverbFX::Init(CAkConvolutionReverbFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  float *v5; // rdi
  AK::IAkPluginMemAlloc *v6; // rbp
  CAkConvolutionReverbFX *v7; // rbx
  AK::IAkEffectPluginContext *v8; // r15
  AkAudioFormat *v9; // r14
  int v10; // ecx
  bool v11; // zf
  signed int v12; // eax
  AK::IAkPluginContextBaseVtbl *v13; // rax
  AK::IAkProcessorFeatures *in_pProcessorFeatures; // rax
  AKRESULT result; // eax
  unsigned int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  AkAudioFormat v21; // [rsp+50h] [rbp+8h]

  v5 = &this->m_Params.fPreDelay;
  this->m_pAllocator = in_pAllocator;
  v6 = in_pAllocator;
  v7 = this;
  this->m_pSharedParams = (CAkConvolutionReverbFXParams *)in_pParams;
  v8 = in_pFXCtx;
  CAkConvolutionReverbFXParams::GetParams((CAkConvolutionReverbFXParams *)in_pParams, &this->m_Params);
  v9 = in_rFormat;
  v7->m_PrevParams.fPreDelay = *v5;
  v7->m_PrevParams.fFrontRearDelay = v5[1];
  v7->m_PrevParams.fStereoWidth = v5[2];
  v7->m_PrevParams.fInputCenterLevel = v5[3];
  v7->m_PrevParams.fInputLFELevel = v5[4];
  v7->m_PrevParams.fFrontLevel = v5[5];
  v7->m_PrevParams.fRearLevel = v5[6];
  v7->m_PrevParams.fCenterLevel = v5[7];
  v7->m_PrevParams.fLFELevel = v5[8];
  v7->m_PrevParams.fDryLevel = v5[9];
  v7->m_PrevParams.fWetLevel = v5[10];
  v7->m_PrevParams.eAlgoType = (AkConvolutionAlgoType)v5[11];
  v10 = *((_DWORD *)v9 + 1) & 0x3FFFF;
  v11 = v7->m_Params.eAlgoType == 1;
  v7->m_ReverbState.uInputChannelMask = v10;
  if ( v11 )
  {
    v7->m_ReverbState.uDownMixChannelMask = v10;
  }
  else
  {
    v7->m_ReverbState.uDownMixChannelMask = 3;
    if ( !((v10 - 4) & 0xFFFFFFF3) )
    {
      v12 = v7->m_ReverbState.uDownMixChannelMask;
      if ( v10 != 16 )
        v12 = 4;
      v7->m_ReverbState.uDownMixChannelMask = v12;
    }
  }
  v7->m_ReverbState.uSampleRate = v9->uSampleRate;
  v7->m_ReverbState.bIsSentMode = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))v8->vfptr[1].__vecDelDtor)(v8);
  v21 = *v9;
  v13 = v8->vfptr;
  *((_DWORD *)&v21 + 1) ^= (v7->m_ReverbState.uDownMixChannelMask ^ *((_DWORD *)&v21 + 1)) & 0x3FFFF;
  in_pProcessorFeatures = v13->GetProcessorFeatures((AK::IAkPluginContextBase *)&v8->vfptr);
  result = DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Init(
             &v7->m_ConvolutionEngine,
             v6,
             v8,
             &v21,
             in_pProcessorFeatures);
  if ( result == 1 )
  {
    v7->m_ReverbState.uTailFrames = (signed int)(float)((float)((float)(v7->m_Params.fFrontRearDelay + *v5) * 0.001)
                                                      * (float)(signed int)v7->m_ReverbState.uSampleRate)
                                  + v7->m_ConvolutionEngine.m_FreqDataHeader.uBlockLength
                                  * v7->m_ConvolutionEngine.m_FreqDataHeader.uNumCompressedPartition;
    result = CAkConvolutionReverbFX::SetupPreDelay(v7);
    if ( result == 1 )
    {
      result = CAkConvolutionReverbFX::SetupFrontBackDelay(v7);
      if ( result == 1 )
      {
        *(_QWORD *)v7->m_ReverbState.uChannelIRMap = 0i64;
        if ( v7->m_ConvolutionEngine.m_FreqDataHeader.uNumChannels > 1 )
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
            v7->m_ReverbState.uChannelIRMap[3] = 1;
            goto $LN6_178;
          }
          v17 = v16 - 63;
          if ( !v17 )
            goto $LN4_164;
          v18 = v17 - 1524;
          if ( !v18 )
            goto LABEL_28;
          v19 = v18 - 4;
          if ( !v19 )
          {
LABEL_20:
            v7->m_ReverbState.uChannelIRMap[6] = 1;
$LN4_164:
            v7->m_ReverbState.uChannelIRMap[4] = 1;
$LN6_178:
            v7->m_ReverbState.uChannelIRMap[1] = 1;
            return 1;
          }
          v20 = v19 - 4;
          if ( !v20 )
          {
LABEL_28:
            v7->m_ReverbState.uChannelIRMap[3] = 1;
            v7->m_ReverbState.uChannelIRMap[5] = 1;
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
signed __int64 __fastcall CAkConvolutionReverbFX::SetupPreDelay(CAkConvolutionReverbFX *this)
{
  CAkConvolutionReverbFX *v1; // rsi
  unsigned int v2; // ebp
  unsigned int v3; // edx
  __int64 v4; // rbx
  unsigned int i; // edi
  signed __int64 result; // rax

  v1 = this;
  v2 = (signed int)(float)((float)(this->m_Params.fPreDelay * 0.001) * (float)(signed int)this->m_ReverbState.uSampleRate);
  if ( !v2 )
    return 1i64;
  v3 = this->m_ReverbState.uDownMixChannelMask;
  v4 = 0i64;
  for ( i = 0; v3; v3 &= v3 - 1 )
    ++i;
  if ( !i )
    return 1i64;
  while ( 1 )
  {
    result = DSP::CDelayLight::Init((DSP::CDelayLight *)(&v1->vfptr + v4 + 2 * (v4 + 16)), v1->m_pAllocator, v2);
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
signed __int64 __fastcall CAkConvolutionReverbFX::SetupFrontBackDelay(CAkConvolutionReverbFX *this)
{
  CAkConvolutionReverbFX *v1; // rbx
  unsigned int v2; // edx
  unsigned int v3; // edi
  signed __int64 result; // rax

  v1 = this;
  v2 = 1;
  v3 = (signed int)(float)((float)(this->m_Params.fFrontRearDelay * 0.001)
                         * (float)(signed int)this->m_ReverbState.uSampleRate);
  if ( !v3 )
    return v2;
  if ( !(this->m_ReverbState.uInputChannelMask & 0x10)
    || (result = DSP::CDelayLight::Init(this->m_ReverbState.FrontBackDelay, this->m_pAllocator, v3),
        v2 = result,
        (_DWORD)result == 1) )
  {
    if ( !(v1->m_ReverbState.uInputChannelMask & 0x20)
      || (result = DSP::CDelayLight::Init(&v1->m_ReverbState.FrontBackDelay[1], v1->m_pAllocator, v3),
          v2 = result,
          (_DWORD)result == 1) )
    {
      if ( !(v1->m_ReverbState.uInputChannelMask & 0x200)
        || (result = DSP::CDelayLight::Init(&v1->m_ReverbState.FrontBackDelay[2], v1->m_pAllocator, v3),
            v2 = result,
            (_DWORD)result == 1) )
      {
        if ( v1->m_ReverbState.uInputChannelMask & 0x400 )
          return DSP::CDelayLight::Init(&v1->m_ReverbState.FrontBackDelay[3], v1->m_pAllocator, v3);
        return v2;
      }
    }
  }
  return result;
}

// File Line: 214
// RVA: 0xB16B00
signed __int64 __fastcall CAkConvolutionReverbFX::Term(CAkConvolutionReverbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkConvolutionReverbFX *v2; // rbx
  AK::IAkPluginMemAlloc *v3; // rdi

  v2 = this;
  v3 = in_pAllocator;
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Term(&this->m_ConvolutionEngine, in_pAllocator);
  CAkConvolutionReverbFX::TermPreDelay(v2);
  DSP::CDelayLight::Term(v2->m_ReverbState.FrontBackDelay, v2->m_pAllocator);
  DSP::CDelayLight::Term(&v2->m_ReverbState.FrontBackDelay[1], v2->m_pAllocator);
  DSP::CDelayLight::Term(&v2->m_ReverbState.FrontBackDelay[2], v2->m_pAllocator);
  DSP::CDelayLight::Term(&v2->m_ReverbState.FrontBackDelay[3], v2->m_pAllocator);
  v2->vfptr->__vecDelDtor((AK::IAkPlugin *)&v2->vfptr, 0);
  v3->vfptr->Free(v3, v2);
  return 1i64;
}

// File Line: 225
// RVA: 0xB18060
void __fastcall CAkConvolutionReverbFX::TermPreDelay(CAkConvolutionReverbFX *this)
{
  unsigned int v1; // edx
  unsigned int v2; // er8
  CAkConvolutionReverbFX *i; // rsi
  __int64 v4; // rdi
  DSP::CDelayLight *v5; // rbx

  v1 = this->m_ReverbState.uDownMixChannelMask;
  v2 = 0;
  for ( i = this; v1; v1 &= v1 - 1 )
    ++v2;
  if ( v2 )
  {
    v4 = v2;
    v5 = this->m_ReverbState.PreDelay;
    do
    {
      DSP::CDelayLight::Term(v5, i->m_pAllocator);
      ++v5;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 234
// RVA: 0xB18000
void __fastcall CAkConvolutionReverbFX::TermFrontBackDelay(CAkConvolutionReverbFX *this)
{
  CAkConvolutionReverbFX *v1; // rbx

  v1 = this;
  DSP::CDelayLight::Term(this->m_ReverbState.FrontBackDelay, this->m_pAllocator);
  DSP::CDelayLight::Term(&v1->m_ReverbState.FrontBackDelay[1], v1->m_pAllocator);
  DSP::CDelayLight::Term(&v1->m_ReverbState.FrontBackDelay[2], v1->m_pAllocator);
  DSP::CDelayLight::Term(&v1->m_ReverbState.FrontBackDelay[3], v1->m_pAllocator);
}

// File Line: 253
// RVA: 0xB16BA0
signed __int64 __fastcall CAkConvolutionReverbFX::Reset(CAkConvolutionReverbFX *this)
{
  CAkConvolutionReverbFX *v1; // rsi
  unsigned int v2; // edx
  unsigned int i; // er8
  __int64 v4; // rdi
  DSP::CDelayLight *v5; // rbx

  v1 = this;
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Reset(&this->m_ConvolutionEngine);
  v2 = v1->m_ReverbState.uDownMixChannelMask;
  for ( i = 0; v2; v2 &= v2 - 1 )
    ++i;
  if ( i )
  {
    v4 = i;
    v5 = v1->m_ReverbState.PreDelay;
    do
    {
      DSP::CDelayLight::Reset(v5);
      ++v5;
      --v4;
    }
    while ( v4 );
  }
  DSP::CDelayLight::Reset(v1->m_ReverbState.FrontBackDelay);
  DSP::CDelayLight::Reset(&v1->m_ReverbState.FrontBackDelay[1]);
  DSP::CDelayLight::Reset(&v1->m_ReverbState.FrontBackDelay[2]);
  DSP::CDelayLight::Reset(&v1->m_ReverbState.FrontBackDelay[3]);
  return 1i64;
}

// File Line: 271
// RVA: 0xB17E30
void __fastcall CAkConvolutionReverbFX::ResetFrontBackDelay(CAkConvolutionReverbFX *this)
{
  CAkConvolutionReverbFX *v1; // rbx

  v1 = this;
  DSP::CDelayLight::Reset(this->m_ReverbState.FrontBackDelay);
  DSP::CDelayLight::Reset(&v1->m_ReverbState.FrontBackDelay[1]);
  DSP::CDelayLight::Reset(&v1->m_ReverbState.FrontBackDelay[2]);
  DSP::CDelayLight::Reset(&v1->m_ReverbState.FrontBackDelay[3]);
}

// File Line: 290
// RVA: 0xB16C40
signed __int64 __fastcall CAkConvolutionReverbFX::GetPluginInfo(CAkConvolutionReverbFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 302
// RVA: 0xB17550
void __fastcall CAkConvolutionReverbFX::SetDownMixChannelMask(CAkConvolutionReverbFX *this, unsigned int in_uInputChannelMask)
{
  signed int v2; // eax

  if ( this->m_Params.eAlgoType == 1 )
  {
    this->m_ReverbState.uDownMixChannelMask = in_uInputChannelMask;
  }
  else
  {
    this->m_ReverbState.uDownMixChannelMask = 3;
    if ( !((in_uInputChannelMask - 4) & 0xFFFFFFF3) )
    {
      v2 = this->m_ReverbState.uDownMixChannelMask;
      if ( in_uInputChannelMask != 16 )
        v2 = 4;
      this->m_ReverbState.uDownMixChannelMask = v2;
    }
  }
}

// File Line: 350
// RVA: 0xB172F0
char __fastcall CAkConvolutionReverbFX::ParametersUpdate(CAkConvolutionReverbFX *this, unsigned int in_uMaxFrames)
{
  CAkConvolutionReverbFX *v2; // rbx
  AkConvolutionAlgoType v3; // eax
  unsigned int v4; // ecx
  signed int v5; // eax
  unsigned int v6; // ecx
  unsigned int i; // er8
  unsigned int v9; // ecx
  unsigned int j; // edx
  DSP::CDelayLight *v11; // rdi
  __int64 v12; // rsi
  unsigned int v13; // ecx
  unsigned int k; // edx
  DSP::CDelayLight *v15; // rdi
  __int64 v16; // rsi

  v2 = this;
  CAkConvolutionReverbFXParams::GetParams(this->m_pSharedParams, &this->m_Params);
  v3 = v2->m_Params.eAlgoType;
  if ( v2->m_PrevParams.eAlgoType != v3 )
  {
    v4 = v2->m_ReverbState.uInputChannelMask;
    if ( v3 == 1 )
    {
      v2->m_ReverbState.uDownMixChannelMask = v4;
    }
    else
    {
      v2->m_ReverbState.uDownMixChannelMask = 3;
      if ( !((v4 - 4) & 0xFFFFFFF3) )
      {
        v5 = v2->m_ReverbState.uDownMixChannelMask;
        if ( v4 != 16 )
          v5 = 4;
        v2->m_ReverbState.uDownMixChannelMask = v5;
      }
    }
    v6 = v2->m_ReverbState.uDownMixChannelMask;
    for ( i = 0; v6; v6 &= v6 - 1 )
      ++i;
    if ( DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::InitOLABuffer(
           &v2->m_ConvolutionEngine,
           v2->m_pAllocator,
           i) != 1 )
      return 0;
    DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Reset(&v2->m_ConvolutionEngine);
  }
  if ( v2->m_Params.fPreDelay != v2->m_PrevParams.fPreDelay || v2->m_PrevParams.eAlgoType != v2->m_Params.eAlgoType )
  {
    v9 = v2->m_ReverbState.uDownMixChannelMask;
    for ( j = 0; v9; v9 &= v9 - 1 )
      ++j;
    if ( j )
    {
      v11 = v2->m_ReverbState.PreDelay;
      v12 = j;
      do
      {
        DSP::CDelayLight::Term(v11, v2->m_pAllocator);
        ++v11;
        --v12;
      }
      while ( v12 );
    }
    if ( CAkConvolutionReverbFX::SetupPreDelay(v2) != 1 )
      return 0;
    v13 = v2->m_ReverbState.uDownMixChannelMask;
    for ( k = 0; v13; v13 &= v13 - 1 )
      ++k;
    if ( k )
    {
      v15 = v2->m_ReverbState.PreDelay;
      v16 = k;
      do
      {
        DSP::CDelayLight::Reset(v15);
        ++v15;
        --v16;
      }
      while ( v16 );
    }
    v2->m_ReverbState.uTailFrames = v2->m_ConvolutionEngine.m_FreqDataHeader.uBlockLength
                                  * v2->m_ConvolutionEngine.m_FreqDataHeader.uNumCompressedPartition
                                  + (signed int)(float)((float)((float)(v2->m_Params.fFrontRearDelay
                                                                      + v2->m_Params.fPreDelay)
                                                              * 0.001)
                                                      * (float)(signed int)v2->m_ReverbState.uSampleRate);
  }
  if ( v2->m_Params.fFrontRearDelay != v2->m_PrevParams.fFrontRearDelay )
  {
    CAkConvolutionReverbFX::TermFrontBackDelay(v2);
    if ( CAkConvolutionReverbFX::SetupFrontBackDelay(v2) != 1 )
      return 0;
    CAkConvolutionReverbFX::ResetFrontBackDelay(v2);
    v2->m_ReverbState.uTailFrames = v2->m_ConvolutionEngine.m_FreqDataHeader.uBlockLength
                                  * v2->m_ConvolutionEngine.m_FreqDataHeader.uNumCompressedPartition
                                  + (signed int)(float)((float)((float)(v2->m_Params.fFrontRearDelay
                                                                      + v2->m_Params.fPreDelay)
                                                              * 0.001)
                                                      * (float)(signed int)v2->m_ReverbState.uSampleRate);
  }
  if ( v2->m_ReverbState.bIsSentMode )
  {
    v2->m_PrevParams.fDryLevel = 0.0;
    v2->m_Params.fDryLevel = 0.0;
  }
  return 1;
}

// File Line: 399
// RVA: 0xB172A0
void __fastcall CAkConvolutionReverbFX::ComputeTailFrames(CAkConvolutionReverbFX *this)
{
  this->m_ReverbState.uTailFrames = this->m_ConvolutionEngine.m_FreqDataHeader.uBlockLength
                                  * this->m_ConvolutionEngine.m_FreqDataHeader.uNumCompressedPartition
                                  + (signed int)(float)((float)((float)(this->m_Params.fFrontRearDelay
                                                                      + this->m_Params.fPreDelay)
                                                              * 0.001)
                                                      * (float)(signed int)this->m_ReverbState.uSampleRate);
}

// File Line: 410
// RVA: 0xB16C60
void __fastcall CAkConvolutionReverbFX::Execute(CAkConvolutionReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // r14
  CAkConvolutionReverbFX *v3; // rdi
  unsigned int v4; // ecx
  unsigned int v5; // edx
  unsigned int v6; // er8
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ebx
  __int64 v10; // rsi
  __int64 v11; // rbx
  unsigned int v12; // edx
  unsigned int i; // er9
  void *v14; // rax
  void *v15; // r13
  unsigned int v16; // esi
  unsigned int j; // ecx
  unsigned int v18; // er13
  float in_fInputLFELevel; // xmm0_4
  float in_fPrevInputLFELevel; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  unsigned int in_uChannelIndex; // ebx
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *v24; // r10
  __int64 v25; // r15
  AkConvolutionReverbState *v26; // rbp
  DSP::CDelayLight *v27; // r14
  unsigned int v28; // edi
  __int64 v29; // rcx
  float *v30; // r12
  unsigned int in_uIRChannelIndex; // eax
  unsigned int v32; // ecx
  unsigned int k; // er15
  unsigned int v34; // ebp
  unsigned __int8 v35; // r12
  unsigned int v36; // ebx
  size_t v37; // r8
  signed __int64 v38; // rdx
  char *v39; // rsi
  DSP::CDelayLight *v40; // rcx
  unsigned int v41; // ecx
  unsigned __int8 v42; // [rsp+40h] [rbp-A8h]
  ak_fft_cpx *io_pfFFTBufferFD; // [rsp+48h] [rbp-A0h]
  signed __int64 v44; // [rsp+50h] [rbp-98h]
  __int64 v45; // [rsp+50h] [rbp-98h]
  AkConvolutionReverbState *v46; // [rsp+58h] [rbp-90h]
  char *v47; // [rsp+60h] [rbp-88h]
  DSP::CDelayLight *v48; // [rsp+68h] [rbp-80h]
  float *io_pfFFTBufferTD; // [rsp+70h] [rbp-78h]
  AkAudioBuffer out_pDownMixBuffer; // [rsp+78h] [rbp-70h]
  size_t v51; // [rsp+90h] [rbp-58h]
  CAkConvolutionReverbFX *v52; // [rsp+F0h] [rbp+8h]
  AkAudioBuffer *v53; // [rsp+F8h] [rbp+10h]
  bool v54; // [rsp+F8h] [rbp+10h]
  bool v55; // [rsp+100h] [rbp+18h]
  void *v56; // [rsp+108h] [rbp+20h]
  bool v57; // [rsp+108h] [rbp+20h]

  v53 = io_pBuffer;
  v52 = this;
  v2 = io_pBuffer;
  v3 = this;
  if ( !CAkConvolutionReverbFX::ParametersUpdate(this, io_pBuffer->uMaxFrames) )
    return;
  v4 = v3->m_ReverbState.uTailFrames;
  if ( v2->eState != 17 )
  {
    v3->m_ReverbState.FXTailHandler.uTailFramesRemaining = -1;
    goto LABEL_14;
  }
  v5 = v3->m_ReverbState.FXTailHandler.uTailFramesRemaining;
  if ( !v5 )
    goto LABEL_14;
  if ( v5 == -1 )
  {
    v3->m_ReverbState.FXTailHandler.uTailFramesRemaining = v4;
LABEL_8:
    v3->m_ReverbState.FXTailHandler.uTotalTailFrames = v4;
    goto LABEL_9;
  }
  v6 = v3->m_ReverbState.FXTailHandler.uTotalTailFrames;
  if ( v4 > v6 )
  {
    v3->m_ReverbState.FXTailHandler.uTailFramesRemaining = v5 + v4 - v6;
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
    v2->eState = 45;
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
    v12 = v3->m_ReverbState.uDownMixChannelMask;
    for ( i = 0; v12; v12 &= v12 - 1 )
      ++i;
    v14 = v3->m_pAllocator->vfptr->Malloc(v3->m_pAllocator, 4 * i * (unsigned __int64)v2->uValidFrames);
  }
  v15 = v14;
  v56 = v14;
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
      v18 = v2->uValidFrames;
      in_fInputLFELevel = v3->m_Params.fInputLFELevel;
      in_fPrevInputLFELevel = v3->m_PrevParams.fInputLFELevel;
      v21 = v3->m_Params.fInputCenterLevel;
      v22 = v3->m_PrevParams.fInputCenterLevel;
      out_pDownMixBuffer.uChannelMask = v3->m_ReverbState.uDownMixChannelMask;
      out_pDownMixBuffer.pData = v14;
      out_pDownMixBuffer.uMaxFrames = v18;
      out_pDownMixBuffer.uValidFrames = v18;
      DSP::AkDownMix(v2, &out_pDownMixBuffer, v22, v21, in_fPrevInputLFELevel, in_fInputLFELevel);
      in_uChannelIndex = 0;
      if ( v16 )
      {
        v24 = &v3->m_ConvolutionEngine;
        v25 = 0i64;
        v26 = &v3->m_ReverbState;
        v27 = v3->m_ReverbState.PreDelay;
        v44 = (signed __int64)&v3->m_ConvolutionEngine;
        v28 = v3->m_ConvolutionEngine.m_FreqDataHeader.uNumChannels - 1;
        do
        {
          v29 = v25 * out_pDownMixBuffer.uMaxFrames;
          v30 = (float *)((char *)out_pDownMixBuffer.pData + 4 * v29);
          in_uIRChannelIndex = v28;
          if ( in_uChannelIndex < v28 )
            in_uIRChannelIndex = in_uChannelIndex;
          DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::ExecuteChannelInPlace(
            v24,
            (float *)out_pDownMixBuffer.pData + v29,
            v18,
            io_pfFFTBufferTD,
            io_pfFFTBufferFD,
            0i64,
            in_uChannelIndex,
            in_uIRChannelIndex);
          if ( v26->PreDelay[0].m_uDelayLineLength )
            DSP::CDelayLight::ProcessBuffer(v27, v30, v18);
          v24 = (DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *)v44;
          ++in_uChannelIndex;
          ++v25;
          ++v27;
          v26 = (AkConvolutionReverbState *)((char *)v26 + 24);
        }
        while ( in_uChannelIndex < v16 );
        v3 = v52;
        v2 = v53;
      }
      CAkConvolutionReverbFX::UpMix(v3, v2, &out_pDownMixBuffer);
      v15 = v56;
LABEL_54:
      v10 = (__int64)io_pfFFTBufferFD;
      goto LABEL_55;
    }
    v32 = v2->uChannelMask;
    for ( k = 0; v32; v32 &= v32 - 1 )
      ++k;
    v34 = v2->uValidFrames;
    v55 = (v3->m_ReverbState.uInputChannelMask & 0x30) != 0;
    v35 = (v3->m_ReverbState.uInputChannelMask >> 2) & 1 | 2;
    v57 = (v3->m_ReverbState.uInputChannelMask & 0x600) != 0;
    v54 = v3->m_ReverbState.FrontBackDelay[0].m_uDelayLineLength != 0;
    v42 = v35 + 2;
    v36 = 0;
    if ( !k )
    {
LABEL_55:
      ++v3->m_ConvolutionEngine.m_uOLAIndex;
      v11 = (__int64)io_pfFFTBufferTD;
      v41 = v3->m_ConvolutionEngine.m_uOLAIndex;
      if ( v3->m_ConvolutionEngine.m_uOLAIndex >= v3->m_ConvolutionEngine.m_FreqDataHeader.uNumCompressedPartition )
        v41 = 0;
      v3->m_ConvolutionEngine.m_uOLAIndex = v41;
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
    v37 = 4 * v34;
    v38 = 0i64;
    v47 = v3->m_ReverbState.uChannelIRMap;
    v51 = 4 * v34;
    v46 = &v3->m_ReverbState;
    v48 = v3->m_ReverbState.PreDelay;
    v45 = 0i64;
    while ( 1 )
    {
      v39 = (char *)v2->pData + 4 * v38 * v2->uMaxFrames;
      memmove(v15, v39, v37);
      DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::ExecuteChannelInPlace(
        &v3->m_ConvolutionEngine,
        (float *)v39,
        v34,
        io_pfFFTBufferTD,
        io_pfFFTBufferFD,
        0i64,
        v36,
        (unsigned __int8)*v47);
      if ( v46->PreDelay[0].m_uDelayLineLength )
        DSP::CDelayLight::ProcessBuffer(v48, (float *)v39, v34);
      if ( !v54 )
        goto LABEL_53;
      if ( v55 )
      {
        if ( v36 == v35 )
        {
          v40 = v3->m_ReverbState.FrontBackDelay;
LABEL_52:
          DSP::CDelayLight::ProcessBuffer(v40, (float *)v39, v34);
          goto LABEL_53;
        }
        if ( v36 == v35 + 1 )
        {
          v40 = &v3->m_ReverbState.FrontBackDelay[1];
          goto LABEL_52;
        }
      }
      if ( v57 )
      {
        if ( v36 == v42 )
        {
          v40 = &v3->m_ReverbState.FrontBackDelay[2];
          goto LABEL_52;
        }
        if ( v36 == v42 + 1 )
        {
          v40 = &v3->m_ReverbState.FrontBackDelay[3];
          goto LABEL_52;
        }
      }
LABEL_53:
      DSP::Mix2Interp(
        (float *)v39,
        (float *)v15,
        v3->m_PrevParams.fWetLevel,
        v3->m_Params.fWetLevel,
        v3->m_PrevParams.fDryLevel,
        v3->m_Params.fDryLevel,
        v34);
      ++v48;
      ++v47;
      v46 = (AkConvolutionReverbState *)((char *)v46 + 24);
      v37 = v51;
      v38 = v45 + 1;
      ++v36;
      ++v45;
      if ( v36 >= k )
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
void __fastcall CAkConvolutionReverbFX::UpMix(CAkConvolutionReverbFX *this, AkAudioBuffer *io_pBuffer, AkAudioBuffer *in_rDownMixBuffer)
{
  __int64 in_uNumFrames; // rbp
  CAkConvolutionReverbFX *v4; // rdi
  unsigned int v5; // ecx
  AkAudioBuffer *v6; // r12
  AkAudioBuffer *v7; // r14
  unsigned int v8; // ecx
  float *v9; // rsi
  unsigned int v10; // er9
  unsigned int v11; // edx
  unsigned int i; // ebx
  float *v13; // rax
  float *v14; // r15
  float *v15; // rdx
  float *v16; // rcx
  float v17; // xmm1_4
  signed __int64 v18; // rbx
  unsigned int v19; // ecx
  float v20; // xmm0_4
  float v21; // xmm1_4
  AkAudioBuffer in_upMixBuffer; // [rsp+40h] [rbp-58h]

  in_uNumFrames = io_pBuffer->uValidFrames;
  v4 = this;
  v5 = this->m_ReverbState.uInputChannelMask;
  v6 = in_rDownMixBuffer;
  v7 = io_pBuffer;
  if ( !((v5 - 4) & 0xFFFFFFFB) )
  {
    if ( v5 == 8 )
    {
      v20 = v4->m_PrevParams.fLFELevel;
      v21 = v4->m_Params.fLFELevel;
    }
    else
    {
      v20 = v4->m_PrevParams.fFrontLevel;
      v21 = v4->m_Params.fFrontLevel;
    }
    DSP::Mix2Interp(
      (float *)io_pBuffer->pData,
      (float *)in_rDownMixBuffer->pData,
      v4->m_PrevParams.fDryLevel,
      v4->m_Params.fDryLevel,
      v20 * v4->m_PrevParams.fWetLevel,
      v21 * v4->m_Params.fWetLevel,
      in_uNumFrames);
    return;
  }
  v8 = v5 & 0xFFFFFFF7;
  v9 = 0i64;
  v10 = v8;
  v11 = 0;
  if ( !v8 )
    goto LABEL_32;
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
LABEL_32:
    for ( i = 0; v8; v8 &= v8 - 1 )
      ++i;
  }
  v13 = (float *)v4->m_pAllocator->vfptr->Malloc(v4->m_pAllocator, 4 * in_uNumFrames * i);
  v14 = v13;
  if ( v13 )
  {
    in_upMixBuffer.pData = v13;
    in_upMixBuffer.uMaxFrames = in_uNumFrames;
    in_upMixBuffer.uValidFrames = in_uNumFrames;
    in_upMixBuffer.uChannelMask = (i != 2) + 3;
    if ( (v4->m_ReverbState.uInputChannelMask & 7) == 3 )
    {
      v18 = (signed __int64)&v13[in_uNumFrames];
      DSP::MixStereoWidth(
        (float *)v6->pData,
        (float *)v6->pData + v6->uMaxFrames,
        v13,
        &v13[in_uNumFrames],
        in_uNumFrames,
        v4->m_PrevParams.fStereoWidth,
        v4->m_Params.fStereoWidth);
      DSP::Mix2Interp(
        (float *)v7->pData,
        v14,
        v4->m_PrevParams.fDryLevel,
        v4->m_Params.fDryLevel,
        v4->m_PrevParams.fWetLevel * v4->m_PrevParams.fFrontLevel,
        v4->m_Params.fFrontLevel * v4->m_Params.fWetLevel,
        in_uNumFrames);
      v16 = (float *)((char *)v7->pData + 4 * v7->uMaxFrames);
      v15 = (float *)v18;
      v17 = v4->m_Params.fFrontLevel * v4->m_Params.fWetLevel;
    }
    else
    {
      if ( (v4->m_ReverbState.uInputChannelMask & 7) != 4 )
      {
        if ( (v4->m_ReverbState.uInputChannelMask & 7) == 7 )
        {
          DSP::Mix2Interp(
            (float *)v6->pData,
            (float *)v6->pData + v6->uMaxFrames,
            v13,
            0.45449999,
            0.45449999,
            0.45449999,
            0.45449999,
            in_uNumFrames);
          DSP::Mix2Interp(
            (float *)v7->pData + 2 * v7->uMaxFrames,
            v14,
            v4->m_PrevParams.fDryLevel,
            v4->m_Params.fDryLevel,
            v4->m_PrevParams.fCenterLevel * v4->m_PrevParams.fWetLevel,
            v4->m_Params.fCenterLevel * v4->m_Params.fWetLevel,
            in_uNumFrames);
          DSP::Mix2Interp(
            (float *)v6->pData,
            (float *)v6->pData + v6->uMaxFrames,
            v14,
            0.88300002,
            0.88300002,
            -0.117,
            -0.117,
            in_uNumFrames);
          DSP::Mix2Interp(
            (float *)v6->pData + v6->uMaxFrames,
            (float *)v6->pData,
            &v14[in_uNumFrames],
            0.88300002,
            0.88300002,
            -0.117,
            -0.117,
            in_uNumFrames);
          DSP::MixStereoWidth(
            v14,
            &v14[in_uNumFrames],
            in_uNumFrames,
            v4->m_PrevParams.fStereoWidth,
            v4->m_Params.fStereoWidth);
          DSP::Mix2Interp(
            (float *)v7->pData,
            v14,
            v4->m_PrevParams.fDryLevel,
            v4->m_Params.fDryLevel,
            v4->m_PrevParams.fWetLevel * v4->m_PrevParams.fFrontLevel,
            v4->m_Params.fFrontLevel * v4->m_Params.fWetLevel,
            in_uNumFrames);
          DSP::Mix2Interp(
            (float *)v7->pData + v7->uMaxFrames,
            &v14[in_uNumFrames],
            v4->m_PrevParams.fDryLevel,
            v4->m_Params.fDryLevel,
            v4->m_PrevParams.fWetLevel * v4->m_PrevParams.fFrontLevel,
            v4->m_Params.fFrontLevel * v4->m_Params.fWetLevel,
            in_uNumFrames);
        }
        goto LABEL_16;
      }
      v15 = (float *)v6->pData;
      v16 = (float *)v7->pData;
      v17 = v4->m_Params.fWetLevel * v4->m_Params.fFrontLevel;
    }
    DSP::Mix2Interp(
      v16,
      v15,
      v4->m_PrevParams.fDryLevel,
      v4->m_Params.fDryLevel,
      v4->m_PrevParams.fWetLevel * v4->m_PrevParams.fFrontLevel,
      v17,
      in_uNumFrames);
LABEL_16:
    if ( v4->m_ReverbState.uInputChannelMask & 0x30 )
    {
      memmove(v14, v6->pData, (unsigned int)(4 * in_uNumFrames));
      memmove(&v14[in_uNumFrames], (char *)v6->pData + 4 * v6->uMaxFrames, (unsigned int)(4 * in_uNumFrames));
      CAkConvolutionReverbFX::ProcessSurroundChannels(v4, v7, &in_upMixBuffer, in_uNumFrames);
    }
    if ( v4->m_ReverbState.uInputChannelMask & 8 )
    {
      v19 = v7->uChannelMask;
      if ( v19 & 8 )
      {
        for ( ; v19; v19 &= v19 - 1 )
          LODWORD(v9) = (_DWORD)v9 + 1;
        v9 = (float *)((char *)v7->pData + 4 * v7->uMaxFrames * (unsigned __int64)(unsigned int)((_DWORD)v9 - 1));
      }
      DSP::Mix2Interp(
        v9,
        (float *)v6->pData,
        v4->m_PrevParams.fDryLevel,
        v4->m_Params.fDryLevel,
        v4->m_PrevParams.fWetLevel * v4->m_PrevParams.fLFELevel,
        v4->m_Params.fWetLevel * v4->m_Params.fLFELevel,
        in_uNumFrames);
    }
    v4->m_pAllocator->vfptr->Free(v4->m_pAllocator, v14);
  }
}

// File Line: 766
// RVA: 0xB17AC0
void __fastcall CAkConvolutionReverbFX::ProcessSurroundChannels(CAkConvolutionReverbFX *this, AkAudioBuffer *io_pBuffer, AkAudioBuffer *in_upMixBuffer, unsigned int in_uNumFrames)
{
  CAkConvolutionReverbFX *v4; // rdi
  DSP::CDelayLight *v5; // rcx
  unsigned int v6; // ebp
  AkAudioBuffer *v7; // rsi
  AkAudioBuffer *v8; // r14
  unsigned __int8 v9; // bl
  unsigned int v10; // ebx
  unsigned __int8 v11; // bl

  v4 = this;
  v5 = this->m_ReverbState.FrontBackDelay;
  v6 = in_uNumFrames;
  v7 = in_upMixBuffer;
  v8 = io_pBuffer;
  if ( v5->m_uDelayLineLength )
    DSP::CDelayLight::ProcessBuffer(v5, (float *)in_upMixBuffer->pData, in_uNumFrames);
  if ( v4->m_ReverbState.FrontBackDelay[1].m_uDelayLineLength )
    DSP::CDelayLight::ProcessBuffer(&v4->m_ReverbState.FrontBackDelay[1], (float *)v7->pData + v7->uMaxFrames, v6);
  DSP::MixStereoWidth(
    (float *)v7->pData,
    (float *)v7->pData + v7->uMaxFrames,
    v6,
    v4->m_PrevParams.fStereoWidth,
    v4->m_Params.fStereoWidth);
  v9 = (v4->m_ReverbState.uInputChannelMask >> 2) & 1 | 2;
  DSP::Mix2Interp(
    (float *)v8->pData + v9 * (unsigned __int64)v8->uMaxFrames,
    (float *)v7->pData,
    v4->m_PrevParams.fDryLevel,
    v4->m_Params.fDryLevel,
    v4->m_PrevParams.fRearLevel * v4->m_PrevParams.fWetLevel,
    v4->m_Params.fWetLevel * v4->m_Params.fRearLevel,
    v6);
  DSP::Mix2Interp(
    (float *)v8->pData + v8->uMaxFrames * (unsigned __int64)((unsigned int)v9 + 1),
    (float *)v7->pData + v7->uMaxFrames,
    v4->m_PrevParams.fDryLevel,
    v4->m_Params.fDryLevel,
    v4->m_PrevParams.fRearLevel * v4->m_PrevParams.fWetLevel,
    v4->m_Params.fWetLevel * v4->m_Params.fRearLevel,
    v6);
  v10 = v4->m_ReverbState.uInputChannelMask;
  if ( v10 & 0x600 )
  {
    v11 = (v10 >> 2) & 1 | 4;
    DSP::Mix2Interp(
      (float *)v8->pData + v11 * (unsigned __int64)v8->uMaxFrames,
      (float *)v7->pData,
      v4->m_PrevParams.fDryLevel,
      v4->m_Params.fDryLevel,
      v4->m_PrevParams.fRearLevel * v4->m_PrevParams.fWetLevel,
      v4->m_Params.fWetLevel * v4->m_Params.fRearLevel,
      v6);
    DSP::Mix2Interp(
      (float *)v8->pData + v8->uMaxFrames * (unsigned __int64)((unsigned int)v11 + 1),
      (float *)v7->pData + v7->uMaxFrames,
      v4->m_PrevParams.fDryLevel,
      v4->m_Params.fDryLevel,
      v4->m_PrevParams.fRearLevel * v4->m_PrevParams.fWetLevel,
      v4->m_Params.fWetLevel * v4->m_Params.fRearLevel,
      v6);
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
AKRESULT __fastcall CAkConvolutionReverbFX::RelocateMedia(CAkConvolutionReverbFX *this, char *in_pNewMedia, char *in_pOldMedia)
{
  return DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::RelocateMedia(
           &this->m_ConvolutionEngine,
           in_pNewMedia,
           in_pOldMedia);
}

