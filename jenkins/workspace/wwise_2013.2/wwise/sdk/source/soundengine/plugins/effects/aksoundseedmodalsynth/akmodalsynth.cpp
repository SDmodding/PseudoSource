// File Line: 35
// RVA: 0xADF240
AK::IAkPlugin *__fastcall CreateAkSoundSeedImpactFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 80ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkPluginVtbl *)&CAkModalSynth::`vftable;
    result[1].vfptr = 0i64;
    result[3].vfptr = 0i64;
    result[4].vfptr = 0i64;
    result[7].vfptr = 0i64;
  }
  return result;
}

// File Line: 42
// RVA: 0xAE0030
float __fastcall EnforcePoleRadiusBounds<float>(float R, float theta)
{
  float v2; // xmm6_4
  float v3; // xmm8_4
  int v4; // ebx
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  bool v11; // cf
  float result; // xmm0_4

  v2 = R;
  v3 = theta;
  if ( R > 1.0 )
    v2 = *(float *)&FLOAT_1_0;
  v4 = `EnforcePoleRadiusBounds<float>::`4::`local static guard;
  if ( `EnforcePoleRadiusBounds<float>::`4::`local static guard & 1 )
  {
    v5 = `EnforcePoleRadiusBounds<float>::`4::theta1;
  }
  else
  {
    v4 = `EnforcePoleRadiusBounds<float>::`4::`local static guard | 1;
    `EnforcePoleRadiusBounds<float>::`4::`local static guard |= 1u;
    v5 = acosf(0.95999998);
    `EnforcePoleRadiusBounds<float>::`4::theta1 = v5;
  }
  if ( v4 & 2 )
  {
    v6 = `EnforcePoleRadiusBounds<float>::`4::theta2;
  }
  else
  {
    v4 |= 2u;
    `EnforcePoleRadiusBounds<float>::`4::`local static guard = v4;
    v6 = 3.1415927 - v5;
    `EnforcePoleRadiusBounds<float>::`4::theta2 = 3.1415927 - v5;
  }
  if ( v4 & 4 )
  {
    v7 = `EnforcePoleRadiusBounds<float>::`4::m1;
  }
  else
  {
    v4 |= 4u;
    `EnforcePoleRadiusBounds<float>::`4::`local static guard = v4;
    v7 = -0.25 / v5;
    `EnforcePoleRadiusBounds<float>::`4::m1 = -0.25 / v5;
  }
  if ( v4 & 8 )
  {
    v8 = `EnforcePoleRadiusBounds<float>::`4::m2;
  }
  else
  {
    v4 |= 8u;
    `EnforcePoleRadiusBounds<float>::`4::`local static guard = v4;
    v8 = 0.25 / (float)(3.1415927 - v6);
    `EnforcePoleRadiusBounds<float>::`4::m2 = 0.25 / (float)(3.1415927 - v6);
  }
  if ( v4 & 0x10 )
  {
    v9 = `EnforcePoleRadiusBounds<float>::`4::b2;
  }
  else
  {
    `EnforcePoleRadiusBounds<float>::`4::`local static guard = v4 | 0x10;
    v9 = 1.0 - (float)(v8 * 3.1415927);
    `EnforcePoleRadiusBounds<float>::`4::b2 = 1.0 - (float)(v8 * 3.1415927);
  }
  if ( v3 >= v5 )
  {
    if ( v3 <= v6 )
    {
      v10 = FLOAT_0_75;
      v11 = v2 < 0.75;
      if ( v2 <= 0.75 )
        goto LABEL_25;
      v10 = v2;
    }
    else
    {
      v10 = (float)(v8 * v3) + v9;
    }
  }
  else
  {
    v10 = (float)(v7 * v3) + 1.0;
  }
  v11 = v2 < v10;
LABEL_25:
  if ( v11 )
    result = v10;
  else
    result = v2;
  return result;
}

// File Line: 72
// RVA: 0xADFF10
void __fastcall CalcCoeffs<float>(float GlobalGain, float freq, float amp, float bw, float SAMPLE_RATE, float *out_pBCoef, float *out_pA1Coef, float *out_pA2Coef)
{
  float v8; // xmm6_4
  float v9; // xmm10_4
  float v10; // xmm0_4
  float v11; // xmm8_4
  float v12; // xmm7_4

  v8 = GlobalGain;
  v9 = (float)(freq * 6.2831855) * (float)(1.0 / SAMPLE_RATE);
  v10 = expf((float)(bw * -3.1415927) * (float)(1.0 / SAMPLE_RATE));
  v11 = EnforcePoleRadiusBounds<float>(v10, v9);
  v12 = powf(10.0, v8 * -0.050000001) * 0.5;
  *out_pBCoef = v12 * powf(10.0, amp * 0.050000001);
  *out_pA1Coef = cosf(v9) * (float)(v11 * 2.0);
  *(_DWORD *)out_pA2Coef = COERCE_UNSIGNED_INT(v11 * v11) ^ _xmm[0];
}

// File Line: 101
// RVA: 0xADF290
void __fastcall CAkModalSynth::CAkModalSynth(CAkModalSynth *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&CAkModalSynth::`vftable;
  this->m_pSharedParams = 0i64;
  this->m_pfAllocatedMem = 0i64;
  this->m_pfFiltCoefs = 0i64;
  this->m_pAllocator = 0i64;
}

// File Line: 106
// RVA: 0xADF2C0
void __fastcall CAkModalSynth::~CAkModalSynth(CAkModalSynth *this)
{
  float *v1; // rdx
  CAkModalSynth *v2; // rbx

  v1 = this->m_pfAllocatedMem;
  v2 = this;
  this->vfptr = (AK::IAkPluginVtbl *)&CAkModalSynth::`vftable;
  if ( v1 )
    ((void (*)(void))this->m_pAllocator->vfptr->Free)();
  if ( v2->m_pfFiltCoefs )
    ((void (*)(void))v2->m_pAllocator->vfptr->Free)();
  v2->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 120
// RVA: 0xADF310
signed __int64 __fastcall CAkModalSynth::Init(CAkModalSynth *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  AK::IAkPluginMemAlloc *v5; // rdi
  CAkModalSynth *v6; // rbx
  signed __int64 result; // rax
  unsigned int v8; // edx
  int i; // ecx
  signed int v10; // eax
  CAkModalSynthParams *v11; // rax
  unsigned int v12; // ecx
  signed int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // esi
  __int64 v16; // rax
  __int64 v17; // rax
  CAkModalSynthParams *v18; // rcx

  v5 = in_pAllocator;
  v6 = this;
  if ( (*((_DWORD *)in_rFormat + 1) & 0x3FFFF) != 4 )
    return 78i64;
  this->m_pAllocator = in_pAllocator;
  v8 = 0;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v8;
  v6->m_uNumProcessedChannels = v8;
  v10 = in_rFormat->uSampleRate;
  v6->m_pSharedParams = (CAkModalSynthParams *)in_pParams;
  v6->m_uSampleRate = v10;
  CAkModalSynthParams::DoModelTransforms((CAkModalSynthParams *)in_pParams, (float)v10);
  v11 = v6->m_pSharedParams;
  v12 = v6->m_uNumProcessedChannels;
  v13 = v11->m_cModes;
  v14 = (signed int)(float)((float)((float)((float)v13 * v11->m_Params.fModelQuality) * 0.0099999998) + 0.5);
  if ( v14 < v13 )
    v13 = v14;
  v6->m_cModes = v13;
  if ( v12 )
  {
    if ( v13 )
    {
      v15 = (v13 + 3) & 0xFFFFFFFC;
      v16 = (__int64)v5->vfptr->Malloc(v5, 8 * v15 * v12);
      v6->m_pfAllocatedMem = (float *)v16;
      if ( !v16 )
        return 52i64;
      v17 = (__int64)v5->vfptr->Malloc(v5, 12 * v15);
      v6->m_pfFiltCoefs = (float *)v17;
      if ( !v17 )
        return 52i64;
    }
  }
  CAkModalSynth::CalcAllModeCoefs(v6);
  v18 = v6->m_pSharedParams;
  v6->m_fCurResGain = v18->m_Params.fResidualLevel;
  v6->m_fCurOutGain = v18->m_Params.fOutputLevel;
  result = 1i64;
  v6->m_DCFiltInfo.fDCCoef = 1.0 - 125.6637061435917 / (double)(signed int)v6->m_uSampleRate;
  return result;
}

// File Line: 176
// RVA: 0xADF7B0
void __fastcall CAkModalSynth::CalcAllModeCoefs(CAkModalSynth *this)
{
  CAkModalSynth *v1; // rsi
  CAkModalSynthParams *v2; // rax
  float *out_pBCoef; // rbx
  AkModalSynthMode *v4; // rbp
  float v5; // xmm6_4
  unsigned int v6; // edi
  unsigned int v7; // ecx
  signed __int64 v8; // r14
  unsigned int v9; // eax
  __int64 v10; // r15
  unsigned int v11; // ecx
  _DWORD *v12; // rax
  __int64 v13; // rcx

  v1 = this;
  v2 = this->m_pSharedParams;
  out_pBCoef = this->m_pfFiltCoefs;
  v4 = v2->m_pModes;
  v5 = v2->m_fGlobalGain;
  v6 = 0;
  v7 = this->m_cModes & 0xFFFFFFFC;
  if ( v7 )
  {
    v8 = (signed __int64)&v4->fBW;
    v9 = ((v7 - 1) >> 2) + 1;
    v10 = v9;
    v6 = 4 * v9;
    do
    {
      CalcCoeffs<float>(
        v5,
        *(float *)(v8 - 8),
        *(float *)(v8 + 4),
        *(float *)v8,
        (float)(signed int)v1->m_uSampleRate,
        out_pBCoef,
        out_pBCoef + 4,
        out_pBCoef + 8);
      *(_DWORD *)(v8 - 8) = *(_DWORD *)(v8 + 8);
      *(_DWORD *)(v8 - 4) = *(_DWORD *)(v8 + 12);
      *(_DWORD *)v8 = *(_DWORD *)(v8 + 16);
      *(_DWORD *)(v8 + 4) = *(_DWORD *)(v8 + 20);
      CalcCoeffs<float>(
        v5,
        *(float *)(v8 - 8),
        *(float *)(v8 + 4),
        *(float *)v8,
        (float)(signed int)v1->m_uSampleRate,
        out_pBCoef + 1,
        out_pBCoef + 5,
        out_pBCoef + 9);
      *(_DWORD *)(v8 - 8) = *(_DWORD *)(v8 + 24);
      *(_DWORD *)(v8 - 4) = *(_DWORD *)(v8 + 28);
      *(_DWORD *)v8 = *(_DWORD *)(v8 + 32);
      *(_DWORD *)(v8 + 4) = *(_DWORD *)(v8 + 36);
      CalcCoeffs<float>(
        v5,
        *(float *)(v8 - 8),
        *(float *)(v8 + 4),
        *(float *)v8,
        (float)(signed int)v1->m_uSampleRate,
        out_pBCoef + 2,
        out_pBCoef + 6,
        out_pBCoef + 10);
      *(_DWORD *)(v8 - 8) = *(_DWORD *)(v8 + 40);
      *(_DWORD *)(v8 - 4) = *(_DWORD *)(v8 + 44);
      *(_DWORD *)v8 = *(_DWORD *)(v8 + 48);
      *(_DWORD *)(v8 + 4) = *(_DWORD *)(v8 + 52);
      CalcCoeffs<float>(
        v5,
        *(float *)(v8 - 8),
        *(float *)(v8 + 4),
        *(float *)v8,
        (float)(signed int)v1->m_uSampleRate,
        out_pBCoef + 3,
        out_pBCoef + 7,
        out_pBCoef + 11);
      out_pBCoef += 12;
      v8 += 64i64;
      --v10;
    }
    while ( v10 );
  }
  for ( ; v6 < v1->m_cModes; ++out_pBCoef )
  {
    CalcCoeffs<float>(
      v5,
      v4[v6].fFreq,
      v4[v6].fMagTrans,
      v4[v6].fBW,
      (float)(signed int)v1->m_uSampleRate,
      out_pBCoef,
      out_pBCoef + 4,
      out_pBCoef + 8);
    ++v6;
  }
  v11 = (v1->m_cModes + 3) & 0xFFFFFFFC;
  if ( v6 < v11 )
  {
    v12 = out_pBCoef + 8;
    v13 = v11 - v6;
    do
    {
      *(v12 - 8) = 0;
      *(v12 - 4) = 0;
      *v12 = 0;
      ++v12;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 218
// RVA: 0xADF480
signed __int64 __fastcall CAkModalSynth::Term(CAkModalSynth *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkModalSynth *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkPlugin *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 226
// RVA: 0xADF4C0
signed __int64 __fastcall CAkModalSynth::Reset(CAkModalSynth *this)
{
  CAkModalSynth *v1; // rbx
  float *v2; // rcx

  v1 = this;
  v2 = this->m_pfAllocatedMem;
  if ( v2 )
    memset(v2, 0, 8 * v1->m_uNumProcessedChannels * ((v1->m_cModes + 3) & 0xFFFFFFFC));
  *(_QWORD *)&v1->m_DCFiltInfo.fDCFwdMem = 0i64;
  return 1i64;
}

// File Line: 241
// RVA: 0xADF510
signed __int64 __fastcall CAkModalSynth::GetPluginInfo(CAkModalSynth *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 282
// RVA: 0xADF530
void __fastcall CAkModalSynth::Execute(CAkModalSynth *this, AkAudioBuffer *io_pBuffer)
{
  CAkModalSynth *v2; // rbx
  unsigned int v3; // ecx
  AkAudioBuffer *v4; // rdi
  CAkModalSynthParams *v5; // rax
  float v6; // xmm6_4
  float v7; // xmm7_4
  unsigned int v8; // esi
  void *v9; // rax
  void *v10; // rbp
  unsigned int v11; // er11
  unsigned int v12; // er10
  float v13; // xmm6_4
  signed int v14; // ecx
  float v15; // xmm4_4
  float v16; // xmm2_4
  __int64 v17; // rdx
  float v18; // xmm5_4
  float *v19; // r8
  float *v20; // rcx
  unsigned __int64 v21; // r9
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm1_4
  __int64 v35; // rax
  float v36; // xmm0_4

  v2 = this;
  v3 = this->m_uNumProcessedChannels;
  v4 = io_pBuffer;
  if ( v3 )
  {
    if ( v2->m_cModes )
    {
      v5 = v2->m_pSharedParams;
      v6 = v5->m_Params.fResidualLevel;
      v7 = v5->m_Params.fOutputLevel;
      v8 = 4 * v3 * io_pBuffer->uMaxFrames;
      v9 = v2->m_pAllocator->vfptr->Malloc(v2->m_pAllocator, v8);
      v10 = v9;
      if ( v9 )
      {
        memset(v9, 0, v8);
        AkAudioBuffer::ZeroPadToMaxFrames(v4);
        Process_0(v4, v10, v2->m_pfFiltCoefs, v2->m_pfAllocatedMem, v2->m_uNumProcessedChannels, v2->m_cModes);
        ScaleAndOutput(v4, (float *)v10, v6, &v2->m_fCurResGain, v7, &v2->m_fCurOutGain, v2->m_uNumProcessedChannels);
        if ( v4->eState == 17 )
        {
          v11 = v2->m_uNumProcessedChannels;
          v12 = 0;
          if ( v11 )
          {
            v13 = v2->m_DCFiltInfo.fDCCoef;
            LOWORD(v14) = v4->uMaxFrames;
            while ( 1 )
            {
              v15 = v2->m_DCFiltInfo.fDCFwdMem;
              v16 = v2->m_DCFiltInfo.fDCFbkMem;
              v17 = (unsigned __int16)v14;
              v18 = 0.0;
              v19 = (float *)((char *)v4->pData + 4 * (unsigned __int16)v14 * (unsigned __int64)v12);
              v20 = v19;
              v21 = (unsigned __int64)&v19[v17];
              if ( (unsigned __int64)v19 < v21 )
              {
                if ( (4 * v17 + 3) / 4 >= 4 )
                {
                  do
                  {
                    v22 = *v20;
                    v20 += 4;
                    v23 = v13 * v16;
                    v24 = *(v20 - 3);
                    v25 = (float)(v22 - v15) + v23;
                    v26 = *(v20 - 3) - v22;
                    v27 = *(v20 - 2);
                    v28 = v26 + (float)(v13 * v25);
                    *(v20 - 4) = v25;
                    *(v20 - 3) = v28;
                    v29 = v13 * v28;
                    v15 = *(v20 - 1);
                    v30 = (float)(v27 - v24) + v29;
                    v31 = *(v20 - 1);
                    *(v20 - 2) = v30;
                    v16 = (float)(v31 - v27) + (float)(v13 * v30);
                    *(v20 - 1) = v16;
                  }
                  while ( (signed __int64)v20 < (signed __int64)(v21 - 12) );
                }
                for ( ; (unsigned __int64)v20 < v21; v16 = v34 )
                {
                  v32 = *v20;
                  ++v20;
                  v33 = v32 - v15;
                  v15 = v32;
                  v34 = v33 + (float)(v13 * v16);
                  *(v20 - 1) = v34;
                }
              }
              v2->m_DCFiltInfo.fDCFwdMem = v15;
              v2->m_DCFiltInfo.fDCFbkMem = v16;
              v14 = v4->uMaxFrames;
              if ( v4->uMaxFrames )
              {
                v35 = v4->uMaxFrames;
                do
                {
                  v36 = *v19;
                  ++v19;
                  v18 = v18 + (float)(v36 * v36);
                  --v35;
                }
                while ( v35 );
              }
              if ( (float)(v18 / (float)v14) >= 0.000000063095733 )
                break;
              if ( ++v12 >= v11 )
                goto LABEL_19;
            }
            v4->eState = 45;
          }
        }
LABEL_19:
        v2->m_pAllocator->vfptr->Free(v2->m_pAllocator, v10);
      }
    }
  }
}

