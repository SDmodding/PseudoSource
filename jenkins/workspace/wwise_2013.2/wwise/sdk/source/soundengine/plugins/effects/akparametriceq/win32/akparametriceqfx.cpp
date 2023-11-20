// File Line: 45
// RVA: 0xACED70
AK::IAkPlugin *__fastcall CreateParametricEQFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 104ui64);
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
signed __int64 __fastcall CAkParametricEQFX::Init(CAkParametricEQFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  CAkParametricEQFX *v5; // rbx
  unsigned int v6; // er10
  __int64 v7; // r8
  unsigned int v8; // eax
  unsigned int v9; // eax
  __int64 v10; // rax
  signed __int64 result; // rax
  float v12; // xmm0_4

  v5 = this;
  v6 = 0;
  v7 = *((_DWORD *)in_rFormat + 1) & 0x3FFFF;
  if ( *((_DWORD *)in_rFormat + 1) & 0x3FFFF )
  {
    do
    {
      ++v6;
      v7 = ((_DWORD)v7 - 1) & (unsigned int)v7;
    }
    while ( (_DWORD)v7 );
  }
  this->m_uNumProcessedChannels = v6;
  v8 = in_rFormat->uSampleRate;
  this->m_pSharedParams = (CAkParameterEQFXParams *)in_pParams;
  this->m_uSampleRate = v8;
  if ( *((_BYTE *)in_rFormat + 4) & 8 && !LOBYTE(in_pParams[9].vfptr) )
    this->m_uNumProcessedChannels = v6 - 1;
  v9 = this->m_uNumProcessedChannels;
  if ( v9 )
  {
    v10 = ((__int64 (__fastcall *)(AK::IAkPluginMemAlloc *, _QWORD, __int64))in_pAllocator->vfptr->Malloc)(
            in_pAllocator,
            48 * v9,
            v7);
    v5->m_pfAllocatedMem = (float *)v10;
    if ( !v10 )
      return 52i64;
  }
  memset(v5->m_pfFiltCoefs, 0, 0x3Cui64);
  v5->m_pSharedParams->m_bBandDirty[0] = 1;
  v5->m_pSharedParams->m_bBandDirty[1] = 1;
  v5->m_pSharedParams->m_bBandDirty[2] = 1;
  v12 = powf(10.0, v5->m_pSharedParams->m_Params.fOutputLevel * 0.050000001);
  result = 1i64;
  v5->m_fCurrentGain = v12;
  return result;
}

// File Line: 114
// RVA: 0xACF170
signed __int64 __fastcall CAkParametricEQFX::Term(CAkParametricEQFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkParametricEQFX *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_pfAllocatedMem )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v3->m_pfAllocatedMem = 0i64;
  }
  v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v3->vfptr, 0);
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

// File Line: 129
// RVA: 0xACF1D0
signed __int64 __fastcall CAkParametricEQFX::Reset(CAkParametricEQFX *this)
{
  if ( this->m_pfAllocatedMem )
    memset(this->m_pfAllocatedMem, 0, 48 * this->m_uNumProcessedChannels);
  return 1i64;
}

// File Line: 144
// RVA: 0xACF210
signed __int64 __fastcall CAkParametricEQFX::GetPluginInfo(CAkParametricEQFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 226
// RVA: 0xACF230
void __fastcall CAkParametricEQFX::Execute(CAkParametricEQFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // rdi
  CAkParametricEQFX *v3; // rbx
  CAkParameterEQFXParams *v4; // rax
  bool v5; // r14
  CAkParameterEQFXParams *v6; // rax
  bool v7; // si
  CAkParameterEQFXParams *v8; // rax
  bool v9; // bp
  float v10; // xmm6_4

  v2 = io_pBuffer;
  v3 = this;
  if ( this->m_uNumProcessedChannels && io_pBuffer->uValidFrames )
  {
    v4 = this->m_pSharedParams;
    v5 = v4->m_Params.Band[0].bOnOff;
    if ( v4->m_bBandDirty[0] )
    {
      CAkParametricEQFX::ComputeBiquadCoefs(this, 0, v4->m_Params.Band);
      v3->m_pSharedParams->m_bBandDirty[0] = 0;
    }
    v6 = v3->m_pSharedParams;
    v7 = v6->m_Params.Band[1].bOnOff;
    if ( v6->m_bBandDirty[1] )
    {
      CAkParametricEQFX::ComputeBiquadCoefs(v3, BAND2, &v6->m_Params.Band[1]);
      v3->m_pSharedParams->m_bBandDirty[1] = 0;
    }
    v8 = v3->m_pSharedParams;
    v9 = v8->m_Params.Band[2].bOnOff;
    if ( v8->m_bBandDirty[2] )
    {
      CAkParametricEQFX::ComputeBiquadCoefs(v3, BAND3, &v8->m_Params.Band[2]);
      v3->m_pSharedParams->m_bBandDirty[2] = 0;
    }
    v10 = powf(10.0, v3->m_pSharedParams->m_Params.fOutputLevel * 0.050000001);
    if ( v5 )
      Process(v2, (float *)v3->m_pfFiltCoefs, v3->m_pfAllocatedMem, v3->m_uNumProcessedChannels);
    if ( v7 )
      Process(
        v2,
        v3->m_pfFiltCoefs[1],
        &v3->m_pfAllocatedMem[4 * v3->m_uNumProcessedChannels],
        v3->m_uNumProcessedChannels);
    if ( v9 )
      Process(
        v2,
        v3->m_pfFiltCoefs[2],
        &v3->m_pfAllocatedMem[8 * v3->m_uNumProcessedChannels],
        v3->m_uNumProcessedChannels);
    AK::DSP::ApplyGain_0(v2, v3->m_fCurrentGain, v10, v3->m_pSharedParams->m_Params.bProcessLFE);
    v3->m_fCurrentGain = v10;
  }
}

// File Line: 276
// RVA: 0xACF3A0
void __fastcall CAkParametricEQFX::ComputeBiquadCoefs(CAkParametricEQFX *this, AkBandNumber in_eBandNum, EQModuleParams *in_sModuleParams)
{
  EQModuleParams *v3; // rbx
  signed __int64 v4; // rsi
  CAkParametricEQFX *v5; // rdi
  float v6; // xmm6_4
  float v7; // xmm13_4
  int v8; // xmm10_4
  float v9; // xmm9_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm7_4
  float v15; // xmm14_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm15_4
  float v19; // xmm0_4
  float v20; // xmm13_4
  float v21; // xmm13_4
  float v22; // xmm6_4
  float v23; // xmm0_4
  float v24; // xmm13_4
  float v25; // xmm11_4
  __m128 v26; // xmm2
  float v27; // xmm7_4
  float v28; // xmm0_4
  float v29; // xmm4_4
  float v30; // xmm14_4
  float v31; // xmm8_4
  float v32; // xmm13_4
  float v33; // xmm9_4
  __m128 v34; // xmm2
  float v35; // xmm6_4
  float v36; // xmm8_4
  float v37; // xmm14_4
  float v38; // xmm1_4
  float v39; // xmm3_4
  float v40; // xmm0_4
  float v41; // xmm13_4
  float v42; // xmm6_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  signed __int64 v47; // rcx
  int v48; // [rsp+D8h] [rbp+10h]
  float v49; // [rsp+D8h] [rbp+10h]

  v3 = in_sModuleParams;
  v4 = in_eBandNum;
  v5 = this;
  v6 = (float)(signed int)this->m_uSampleRate;
  v7 = in_sModuleParams->fFrequency;
  if ( v7 >= (float)((float)(v6 * 0.5) * 0.89999998) )
    v7 = (float)(v6 * 0.5) * 0.89999998;
  v8 = _xmm[0];
  switch ( in_sModuleParams->eFilterType )
  {
    case 0:
      v9 = *(float *)&FLOAT_1_0;
      v10 = 1.0 / tanf((float)(v7 * 3.1415927) / v6);
      v11 = v10;
      v12 = v10 * v10;
      v13 = v11 * 1.4142135;
      v14 = 1.0 / (float)((float)(v12 + 1.0) + v13);
      v15 = (float)((float)(v12 + 1.0) - v13) * v14;
      v16 = 1.0 / (float)((float)(v12 + 1.0) + v13);
      v17 = v14 * 2.0;
      v18 = (float)(1.0 - v12) * (float)(v14 * 2.0);
      break;
    case 1:
      v19 = tanf((float)(v7 * 3.1415927) / v6);
      v9 = *(float *)&FLOAT_1_0;
      v14 = 1.0 / (float)((float)((float)(v19 * v19) + 1.0) + (float)(v19 * 1.4142135));
      v15 = (float)((float)((float)(v19 * v19) + 1.0) - (float)(v19 * 1.4142135)) * v14;
      v16 = 1.0 / (float)((float)((float)(v19 * v19) + 1.0) + (float)(v19 * 1.4142135));
      v17 = v14 * -2.0;
      LODWORD(v18) = COERCE_UNSIGNED_INT((float)((float)(v19 * v19) - 1.0) * (float)(v14 * -2.0)) ^ _xmm[0];
      break;
    case 2:
      v20 = (float)(v7 * 6.2831855) / v6;
      v14 = sinf(v20) / (float)(in_sModuleParams->fQFactor * 2.0);
      v9 = v14 + 1.0;
      v48 = LODWORD(v14) ^ _xmm[0];
      v15 = 1.0 - v14;
      v17 = 0.0;
      v18 = cosf(v20) * -2.0;
      goto LABEL_12;
    case 3:
      v21 = (float)(v7 * 6.2831855) / v6;
      v14 = *(float *)&FLOAT_1_0;
      v22 = sinf(v21) / (float)(in_sModuleParams->fQFactor * 2.0);
      v23 = cosf(v21);
      v16 = *(float *)&FLOAT_1_0;
      v9 = v22 + 1.0;
      v15 = 1.0 - v22;
      v17 = v23 * -2.0;
      v18 = v23 * -2.0;
      break;
    case 4:
      v24 = (float)(v7 * 6.2831855) / v6;
      v25 = powf(10.0, in_sModuleParams->fGain * 0.025);
      v26 = (__m128)(unsigned int)FLOAT_1_0;
      v27 = cosf(v24);
      v26.m128_f32[0] = (float)((float)((float)(1.0 / v25) + v25) * 0.0) + 2.0;
      v28 = sinf(v24);
      v29 = (float)(v25 + 1.0) - (float)((float)(v25 - 1.0) * v27);
      v30 = (float)((float)(v25 - 1.0) * v27) + (float)(v25 + 1.0);
      v8 = _xmm[0];
      v18 = (float)((float)((float)(v25 + 1.0) * v27) + (float)(v25 - 1.0)) * -2.0;
      v17 = (float)((float)(v25 - 1.0) - (float)((float)(v25 + 1.0) * v27)) * (float)(v25 * 2.0);
      v31 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v26)) * (float)(v28 * 0.5)) * (float)(fsqrt(v25) * 2.0);
      v9 = v30 + v31;
      v14 = (float)(v29 + v31) * v25;
      v16 = (float)(v29 - v31) * v25;
      v15 = v30 - v31;
      break;
    case 5:
      v32 = (float)(v7 * 6.2831855) / v6;
      v33 = powf(10.0, in_sModuleParams->fGain * 0.025);
      v34 = (__m128)(unsigned int)FLOAT_1_0;
      v35 = cosf(v32);
      v34.m128_f32[0] = (float)((float)((float)(1.0 / v33) + v33) * 0.0) + 2.0;
      v36 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v34)) * (float)(sinf(v32) * 0.5)) * (float)(fsqrt(v33) * 2.0);
      v37 = (float)(v33 + 1.0) - (float)((float)(v33 - 1.0) * v35);
      v38 = (float)(v33 + 1.0) * v35;
      v16 = (float)((float)((float)((float)(v33 - 1.0) * v35) + (float)(v33 + 1.0)) - v36) * v33;
      v39 = v38 + (float)(v33 - 1.0);
      v40 = v33;
      v18 = (float)((float)(v33 - 1.0) - v38) * 2.0;
      v14 = (float)((float)((float)((float)(v33 - 1.0) * v35) + (float)(v33 + 1.0)) + v36) * v33;
      v9 = v37 + v36;
      v15 = v37 - v36;
      v17 = v39 * (float)(v40 * -2.0);
      break;
    case 6:
      v41 = (float)(v7 * 6.2831855) / v6;
      v49 = cosf(v41);
      v42 = powf(10.0, v3->fGain * 0.025);
      v17 = v49 * -2.0;
      v18 = v49 * -2.0;
      v43 = sinf(v41) / (float)(v3->fQFactor * 2.0);
      v44 = v43;
      v45 = v43 / v42;
      v46 = v44 * v42;
      v15 = 1.0 - v45;
      v9 = v45 + 1.0;
      v16 = 1.0 - v46;
      v14 = v46 + 1.0;
      break;
    default:
      v14 = *(float *)&v48;
      v17 = *(float *)&v48;
      v9 = *(float *)&v48;
      v18 = *(float *)&v48;
      v15 = *(float *)&v48;
LABEL_12:
      v16 = *(float *)&v48;
      break;
  }
  v47 = v4;
  v5->m_pfFiltCoefs[v47][1] = (float)(1.0 / v9) * v17;
  v5->m_pfFiltCoefs[v47][0] = (float)(1.0 / v9) * v14;
  LODWORD(v5->m_pfFiltCoefs[v47][4]) = COERCE_UNSIGNED_INT((float)(1.0 / v9) * v15) ^ v8;
  v5->m_pfFiltCoefs[v47][2] = (float)(1.0 / v9) * v16;
  LODWORD(v5->m_pfFiltCoefs[v47][3]) = COERCE_UNSIGNED_INT((float)(1.0 / v9) * v18) ^ v8;
}

