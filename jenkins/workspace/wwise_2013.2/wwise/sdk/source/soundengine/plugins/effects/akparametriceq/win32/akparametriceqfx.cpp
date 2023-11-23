// File Line: 45
// RVA: 0xACED70
AK::IAkPlugin *__fastcall CreateParametricEQFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 104i64);
  if ( result )
  {
    result[9].vfptr = 0i64;
    result[11].vfptr = 0i64;
    result->vfptr = (AK::IAkPluginVtbl *)&CAkParametricEQFX::`vftable;
  }
  return result;
}

// File Line: 53
// RVA: 0xACF050
void __fastcall CAkParametricEQFX::CAkParametricEQFX(CAkParametricEQFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&CAkParametricEQFX::`vftable;
  this->m_pSharedParams = 0i64;
  this->m_pfAllocatedMem = 0i64;
}

// File Line: 60
// RVA: 0xACF070
void __fastcall CAkParametricEQFX::~CAkParametricEQFX(CAkParametricEQFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 70
// RVA: 0xACF090
__int64 __fastcall CAkParametricEQFX::Init(
        CAkParametricEQFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkParameterEQFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  unsigned int v6; // r10d
  int i; // r8d
  unsigned int uSampleRate; // eax
  unsigned int m_uNumProcessedChannels; // eax
  float *v10; // rax
  __int64 result; // rax
  float v12; // xmm0_4

  v6 = 0;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v6;
  this->m_uNumProcessedChannels = v6;
  uSampleRate = in_rFormat->uSampleRate;
  this->m_pSharedParams = in_pParams;
  this->m_uSampleRate = uSampleRate;
  if ( (*((_BYTE *)in_rFormat + 4) & 8) != 0 && !in_pParams->m_Params.bProcessLFE )
    this->m_uNumProcessedChannels = v6 - 1;
  m_uNumProcessedChannels = this->m_uNumProcessedChannels;
  if ( m_uNumProcessedChannels )
  {
    v10 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 48 * m_uNumProcessedChannels);
    this->m_pfAllocatedMem = v10;
    if ( !v10 )
      return 52i64;
  }
  memset(this->m_pfFiltCoefs, 0, sizeof(this->m_pfFiltCoefs));
  this->m_pSharedParams->m_bBandDirty[0] = 1;
  this->m_pSharedParams->m_bBandDirty[1] = 1;
  this->m_pSharedParams->m_bBandDirty[2] = 1;
  v12 = powf(10.0, this->m_pSharedParams->m_Params.fOutputLevel * 0.050000001);
  result = 1i64;
  this->m_fCurrentGain = v12;
  return result;
}

// File Line: 114
// RVA: 0xACF170
__int64 __fastcall CAkParametricEQFX::Term(CAkParametricEQFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->m_pfAllocatedMem )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->m_pfAllocatedMem = 0i64;
  }
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 129
// RVA: 0xACF1D0
__int64 __fastcall CAkParametricEQFX::Reset(CAkParametricEQFX *this)
{
  if ( this->m_pfAllocatedMem )
    memset(this->m_pfAllocatedMem, 0, 48 * this->m_uNumProcessedChannels);
  return 1i64;
}

// File Line: 144
// RVA: 0xACF210
__int64 __fastcall CAkParametricEQFX::GetPluginInfo(CAkParametricEQFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 226
// RVA: 0xACF230
void __fastcall CAkParametricEQFX::Execute(CAkParametricEQFX *this, AkAudioBuffer *io_pBuffer)
{
  CAkParameterEQFXParams *m_pSharedParams; // rax
  bool bOnOff; // r14
  CAkParameterEQFXParams *v6; // rax
  bool v7; // si
  CAkParameterEQFXParams *v8; // rax
  bool v9; // bp
  float v10; // xmm6_4

  if ( this->m_uNumProcessedChannels && io_pBuffer->uValidFrames )
  {
    m_pSharedParams = this->m_pSharedParams;
    bOnOff = m_pSharedParams->m_Params.Band[0].bOnOff;
    if ( m_pSharedParams->m_bBandDirty[0] )
    {
      CAkParametricEQFX::ComputeBiquadCoefs(this, BAND1, m_pSharedParams->m_Params.Band);
      this->m_pSharedParams->m_bBandDirty[0] = 0;
    }
    v6 = this->m_pSharedParams;
    v7 = v6->m_Params.Band[1].bOnOff;
    if ( v6->m_bBandDirty[1] )
    {
      CAkParametricEQFX::ComputeBiquadCoefs(this, BAND2, &v6->m_Params.Band[1]);
      this->m_pSharedParams->m_bBandDirty[1] = 0;
    }
    v8 = this->m_pSharedParams;
    v9 = v8->m_Params.Band[2].bOnOff;
    if ( v8->m_bBandDirty[2] )
    {
      CAkParametricEQFX::ComputeBiquadCoefs(this, BAND3, &v8->m_Params.Band[2]);
      this->m_pSharedParams->m_bBandDirty[2] = 0;
    }
    v10 = powf(10.0, this->m_pSharedParams->m_Params.fOutputLevel * 0.050000001);
    if ( bOnOff )
      Process(io_pBuffer, this->m_pfFiltCoefs[0], this->m_pfAllocatedMem, this->m_uNumProcessedChannels);
    if ( v7 )
      Process(
        io_pBuffer,
        this->m_pfFiltCoefs[1],
        &this->m_pfAllocatedMem[4 * this->m_uNumProcessedChannels],
        this->m_uNumProcessedChannels);
    if ( v9 )
      Process(
        io_pBuffer,
        this->m_pfFiltCoefs[2],
        &this->m_pfAllocatedMem[8 * this->m_uNumProcessedChannels],
        this->m_uNumProcessedChannels);
    AK::DSP::ApplyGain_0(io_pBuffer, this->m_fCurrentGain, v10, this->m_pSharedParams->m_Params.bProcessLFE);
    this->m_fCurrentGain = v10;
  }
}

// File Line: 276
// RVA: 0xACF3A0
void __fastcall CAkParametricEQFX::ComputeBiquadCoefs(
        CAkParametricEQFX *this,
        AkBandNumber in_eBandNum,
        EQModuleParams *in_sModuleParams)
{
  __int64 v4; // rsi
  float m_uSampleRate; // xmm6_4
  float fFrequency; // xmm13_4
  int v8; // xmm10_4
  float v9; // xmm0_4
  float v10; // xmm9_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm7_4
  float v14; // xmm14_4
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v17; // xmm15_4
  float v18; // xmm0_4
  float v19; // xmm13_4
  float v20; // xmm13_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm13_4
  float v24; // xmm11_4
  __m128 v25; // xmm2
  float v26; // xmm7_4
  float v27; // xmm0_4
  float v28; // xmm4_4
  float v29; // xmm14_4
  float v30; // xmm8_4
  float v31; // xmm13_4
  float v32; // xmm9_4
  __m128 v33; // xmm2
  float v34; // xmm6_4
  float v35; // xmm8_4
  float v36; // xmm14_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm13_4
  float v41; // xmm6_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  __int64 v45; // rcx
  int v46; // [rsp+D8h] [rbp+10h]
  float v47; // [rsp+D8h] [rbp+10h]

  v4 = in_eBandNum;
  m_uSampleRate = (float)(int)this->m_uSampleRate;
  fFrequency = in_sModuleParams->fFrequency;
  if ( fFrequency >= (float)((float)(m_uSampleRate * 0.5) * 0.89999998) )
    fFrequency = (float)(m_uSampleRate * 0.5) * 0.89999998;
  v8 = _xmm[0];
  switch ( in_sModuleParams->eFilterType )
  {
    case AKFILTERTYPE_LOWPASS:
      v9 = tanf((float)(fFrequency * 3.1415927) / m_uSampleRate);
      v10 = *(float *)&FLOAT_1_0;
      v11 = (float)(1.0 / v9) * (float)(1.0 / v9);
      v12 = (float)(1.0 / v9) * 1.4142135;
      v13 = 1.0 / (float)((float)(v11 + 1.0) + v12);
      v14 = (float)((float)(v11 + 1.0) - v12) * v13;
      v15 = v13;
      v16 = v13 * 2.0;
      v17 = (float)(1.0 - v11) * (float)(v13 * 2.0);
      break;
    case AKFILTERTYPE_HIPASS:
      v18 = tanf((float)(fFrequency * 3.1415927) / m_uSampleRate);
      v10 = *(float *)&FLOAT_1_0;
      v13 = 1.0 / (float)((float)((float)(v18 * v18) + 1.0) + (float)(v18 * 1.4142135));
      v14 = (float)((float)((float)(v18 * v18) + 1.0) - (float)(v18 * 1.4142135)) * v13;
      v15 = v13;
      v16 = v13 * -2.0;
      LODWORD(v17) = COERCE_UNSIGNED_INT((float)((float)(v18 * v18) - 1.0) * (float)(v13 * -2.0)) ^ _xmm[0];
      break;
    case AKFILTERTYPE_BANDPASS:
      v19 = (float)(fFrequency * 6.2831855) / m_uSampleRate;
      v13 = sinf(v19) / (float)(in_sModuleParams->fQFactor * 2.0);
      v10 = v13 + 1.0;
      v46 = LODWORD(v13) ^ _xmm[0];
      v14 = 1.0 - v13;
      v16 = 0.0;
      v17 = cosf(v19) * -2.0;
      goto LABEL_12;
    case AKFILTERTYPE_NOTCH:
      v20 = (float)(fFrequency * 6.2831855) / m_uSampleRate;
      v13 = *(float *)&FLOAT_1_0;
      v21 = sinf(v20) / (float)(in_sModuleParams->fQFactor * 2.0);
      v22 = cosf(v20);
      v15 = *(float *)&FLOAT_1_0;
      v10 = v21 + 1.0;
      v14 = 1.0 - v21;
      v16 = v22 * -2.0;
      v17 = v22 * -2.0;
      break;
    case AKFILTERTYPE_LOWSHELF:
      v23 = (float)(fFrequency * 6.2831855) / m_uSampleRate;
      v24 = powf(10.0, in_sModuleParams->fGain * 0.025);
      v25 = (__m128)(unsigned int)FLOAT_1_0;
      v26 = cosf(v23);
      v25.m128_f32[0] = (float)((float)((float)(1.0 / v24) + v24) * 0.0) + 2.0;
      v27 = sinf(v23);
      v28 = (float)(v24 + 1.0) - (float)((float)(v24 - 1.0) * v26);
      v29 = (float)((float)(v24 - 1.0) * v26) + (float)(v24 + 1.0);
      v8 = _xmm[0];
      v17 = (float)((float)((float)(v24 + 1.0) * v26) + (float)(v24 - 1.0)) * -2.0;
      v16 = (float)((float)(v24 - 1.0) - (float)((float)(v24 + 1.0) * v26)) * (float)(v24 * 2.0);
      v30 = (float)(_mm_sqrt_ps(v25).m128_f32[0] * (float)(v27 * 0.5)) * (float)(fsqrt(v24) * 2.0);
      v10 = v29 + v30;
      v13 = (float)(v28 + v30) * v24;
      v15 = (float)(v28 - v30) * v24;
      v14 = v29 - v30;
      break;
    case AKFILTERTYPE_HISHELF:
      v31 = (float)(fFrequency * 6.2831855) / m_uSampleRate;
      v32 = powf(10.0, in_sModuleParams->fGain * 0.025);
      v33 = (__m128)(unsigned int)FLOAT_1_0;
      v34 = cosf(v31);
      v33.m128_f32[0] = (float)((float)((float)(1.0 / v32) + v32) * 0.0) + 2.0;
      v35 = (float)(_mm_sqrt_ps(v33).m128_f32[0] * (float)(sinf(v31) * 0.5)) * (float)(fsqrt(v32) * 2.0);
      v36 = (float)(v32 + 1.0) - (float)((float)(v32 - 1.0) * v34);
      v37 = (float)(v32 + 1.0) * v34;
      v15 = (float)((float)((float)((float)(v32 - 1.0) * v34) + (float)(v32 + 1.0)) - v35) * v32;
      v38 = v37 + (float)(v32 - 1.0);
      v39 = v32;
      v17 = (float)((float)(v32 - 1.0) - v37) * 2.0;
      v13 = (float)((float)((float)((float)(v32 - 1.0) * v34) + (float)(v32 + 1.0)) + v35) * v32;
      v10 = v36 + v35;
      v14 = v36 - v35;
      v16 = v38 * (float)(v39 * -2.0);
      break;
    case AKFILTERTYPE_PEAKINGEQ:
      v40 = (float)(fFrequency * 6.2831855) / m_uSampleRate;
      v47 = cosf(v40);
      v41 = powf(10.0, in_sModuleParams->fGain * 0.025);
      v16 = v47 * -2.0;
      v17 = v47 * -2.0;
      v42 = sinf(v40) / (float)(in_sModuleParams->fQFactor * 2.0);
      v43 = v42 / v41;
      v44 = v42 * v41;
      v14 = 1.0 - v43;
      v10 = v43 + 1.0;
      v15 = 1.0 - v44;
      v13 = v44 + 1.0;
      break;
    default:
      v13 = *(float *)&v46;
      v16 = *(float *)&v46;
      v10 = *(float *)&v46;
      v17 = *(float *)&v46;
      v14 = *(float *)&v46;
LABEL_12:
      v15 = *(float *)&v46;
      break;
  }
  v45 = v4;
  this->m_pfFiltCoefs[v45][1] = (float)(1.0 / v10) * v16;
  this->m_pfFiltCoefs[v45][0] = (float)(1.0 / v10) * v13;
  LODWORD(this->m_pfFiltCoefs[v45][4]) = COERCE_UNSIGNED_INT((float)(1.0 / v10) * v14) ^ v8;
  this->m_pfFiltCoefs[v45][2] = (float)(1.0 / v10) * v15;
  LODWORD(this->m_pfFiltCoefs[v45][3]) = COERCE_UNSIGNED_INT((float)(1.0 / v10) * v17) ^ v8;
}

