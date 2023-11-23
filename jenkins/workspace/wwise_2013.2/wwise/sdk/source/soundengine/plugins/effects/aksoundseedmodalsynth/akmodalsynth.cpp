// File Line: 35
// RVA: 0xADF240
AK::IAkPlugin *__fastcall CreateAkSoundSeedImpactFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 80i64);
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
  int v4; // ebx
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  bool v11; // cf

  v2 = R;
  if ( R > 1.0 )
    v2 = *(float *)&FLOAT_1_0;
  v4 = `EnforcePoleRadiusBounds<float>::`4::`local static guard;
  if ( (`EnforcePoleRadiusBounds<float>::`4::`local static guard & 1) != 0 )
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
  if ( (v4 & 2) != 0 )
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
  if ( (v4 & 4) != 0 )
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
  if ( (v4 & 8) != 0 )
  {
    v8 = `EnforcePoleRadiusBounds<float>::`4::m2;
  }
  else
  {
    v4 |= 8u;
    `EnforcePoleRadiusBounds<float>::`4::`local static guard = v4;
    v8 = 0.25 / (float)(3.1415927 - v6);
    `EnforcePoleRadiusBounds<float>::`4::m2 = v8;
  }
  if ( (v4 & 0x10) != 0 )
  {
    v9 = `EnforcePoleRadiusBounds<float>::`4::b2;
  }
  else
  {
    `EnforcePoleRadiusBounds<float>::`4::`local static guard = v4 | 0x10;
    v9 = 1.0 - (float)(v8 * 3.1415927);
    `EnforcePoleRadiusBounds<float>::`4::b2 = v9;
  }
  if ( theta >= v5 )
  {
    if ( theta <= v6 )
    {
      v10 = FLOAT_0_75;
      v11 = v2 < 0.75;
      if ( v2 <= 0.75 )
        goto LABEL_25;
      v10 = v2;
    }
    else
    {
      v10 = (float)(v8 * theta) + v9;
    }
  }
  else
  {
    v10 = (float)(v7 * theta) + 1.0;
  }
  v11 = v2 < v10;
LABEL_25:
  if ( v11 )
    return v10;
  else
    return v2;
}

// File Line: 72
// RVA: 0xADFF10
void __fastcall CalcCoeffs<float>(
        float GlobalGain,
        float freq,
        float amp,
        float bw,
        float SAMPLE_RATE,
        float *out_pBCoef,
        float *out_pA1Coef,
        float *out_pA2Coef)
{
  float v9; // xmm10_4
  float v10; // xmm0_4
  float v11; // xmm8_4
  float v12; // xmm7_4

  v9 = (float)(freq * 6.2831855) * (float)(1.0 / SAMPLE_RATE);
  v10 = expf((float)(bw * -3.1415927) * (float)(1.0 / SAMPLE_RATE));
  v11 = EnforcePoleRadiusBounds<float>(v10, v9);
  v12 = powf(10.0, GlobalGain * -0.050000001) * 0.5;
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
  float *m_pfAllocatedMem; // rdx

  m_pfAllocatedMem = this->m_pfAllocatedMem;
  this->vfptr = (AK::IAkPluginVtbl *)&CAkModalSynth::`vftable;
  if ( m_pfAllocatedMem )
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
  if ( this->m_pfFiltCoefs )
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 120
// RVA: 0xADF310
__int64 __fastcall CAkModalSynth::Init(
        CAkModalSynth *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkModalSynthParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  __int64 result; // rax
  unsigned int v8; // edx
  int i; // ecx
  int uSampleRate; // eax
  CAkModalSynthParams *m_pSharedParams; // rax
  unsigned int m_uNumProcessedChannels; // ecx
  unsigned int m_cModes; // edx
  unsigned int v14; // eax
  unsigned int v15; // esi
  float *v16; // rax
  float *v17; // rax
  CAkModalSynthParams *v18; // rcx

  if ( (*((_DWORD *)in_rFormat + 1) & 0x3FFFF) != 4 )
    return 78i64;
  this->m_pAllocator = in_pAllocator;
  v8 = 0;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v8;
  this->m_uNumProcessedChannels = v8;
  uSampleRate = in_rFormat->uSampleRate;
  this->m_pSharedParams = in_pParams;
  this->m_uSampleRate = uSampleRate;
  CAkModalSynthParams::DoModelTransforms(in_pParams, (float)uSampleRate);
  m_pSharedParams = this->m_pSharedParams;
  m_uNumProcessedChannels = this->m_uNumProcessedChannels;
  m_cModes = m_pSharedParams->m_cModes;
  v14 = (int)(float)((float)((float)((float)(int)m_cModes * m_pSharedParams->m_Params.fModelQuality) * 0.0099999998)
                   + 0.5);
  if ( v14 < m_cModes )
    m_cModes = v14;
  this->m_cModes = m_cModes;
  if ( m_uNumProcessedChannels )
  {
    if ( m_cModes )
    {
      v15 = (m_cModes + 3) & 0xFFFFFFFC;
      v16 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8 * v15 * m_uNumProcessedChannels);
      this->m_pfAllocatedMem = v16;
      if ( !v16 )
        return 52i64;
      v17 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 12 * v15);
      this->m_pfFiltCoefs = v17;
      if ( !v17 )
        return 52i64;
    }
  }
  CAkModalSynth::CalcAllModeCoefs(this);
  v18 = this->m_pSharedParams;
  this->m_fCurResGain = v18->m_Params.fResidualLevel;
  this->m_fCurOutGain = v18->m_Params.fOutputLevel;
  result = 1i64;
  this->m_DCFiltInfo.fDCCoef = 1.0 - 125.6637061435917 / (double)(int)this->m_uSampleRate;
  return result;
}

// File Line: 176
// RVA: 0xADF7B0
void __fastcall CAkModalSynth::CalcAllModeCoefs(CAkModalSynth *this)
{
  CAkModalSynthParams *m_pSharedParams; // rax
  float *out_pBCoef; // rbx
  AkModalSynthMode *m_pModes; // rbp
  float m_fGlobalGain; // xmm6_4
  unsigned int v6; // edi
  unsigned int v7; // ecx
  float *p_fBW; // r14
  unsigned int v9; // eax
  __int64 v10; // r15
  unsigned int v11; // ecx
  _DWORD *v12; // rax
  __int64 v13; // rcx

  m_pSharedParams = this->m_pSharedParams;
  out_pBCoef = this->m_pfFiltCoefs;
  m_pModes = m_pSharedParams->m_pModes;
  m_fGlobalGain = m_pSharedParams->m_fGlobalGain;
  v6 = 0;
  v7 = this->m_cModes & 0xFFFFFFFC;
  if ( v7 )
  {
    p_fBW = &m_pModes->fBW;
    v9 = ((v7 - 1) >> 2) + 1;
    v10 = v9;
    v6 = 4 * v9;
    do
    {
      CalcCoeffs<float>(
        m_fGlobalGain,
        *(p_fBW - 2),
        p_fBW[1],
        *p_fBW,
        (float)(int)this->m_uSampleRate,
        out_pBCoef,
        out_pBCoef + 4,
        out_pBCoef + 8);
      *(p_fBW - 2) = p_fBW[2];
      *(p_fBW - 1) = p_fBW[3];
      *p_fBW = p_fBW[4];
      p_fBW[1] = p_fBW[5];
      CalcCoeffs<float>(
        m_fGlobalGain,
        *(p_fBW - 2),
        p_fBW[1],
        *p_fBW,
        (float)(int)this->m_uSampleRate,
        out_pBCoef + 1,
        out_pBCoef + 5,
        out_pBCoef + 9);
      *(p_fBW - 2) = p_fBW[6];
      *(p_fBW - 1) = p_fBW[7];
      *p_fBW = p_fBW[8];
      p_fBW[1] = p_fBW[9];
      CalcCoeffs<float>(
        m_fGlobalGain,
        *(p_fBW - 2),
        p_fBW[1],
        *p_fBW,
        (float)(int)this->m_uSampleRate,
        out_pBCoef + 2,
        out_pBCoef + 6,
        out_pBCoef + 10);
      *(p_fBW - 2) = p_fBW[10];
      *(p_fBW - 1) = p_fBW[11];
      *p_fBW = p_fBW[12];
      p_fBW[1] = p_fBW[13];
      CalcCoeffs<float>(
        m_fGlobalGain,
        *(p_fBW - 2),
        p_fBW[1],
        *p_fBW,
        (float)(int)this->m_uSampleRate,
        out_pBCoef + 3,
        out_pBCoef + 7,
        out_pBCoef + 11);
      out_pBCoef += 12;
      p_fBW += 16;
      --v10;
    }
    while ( v10 );
  }
  for ( ; v6 < this->m_cModes; ++out_pBCoef )
  {
    CalcCoeffs<float>(
      m_fGlobalGain,
      m_pModes[v6].fFreq,
      m_pModes[v6].fMagTrans,
      m_pModes[v6].fBW,
      (float)(int)this->m_uSampleRate,
      out_pBCoef,
      out_pBCoef + 4,
      out_pBCoef + 8);
    ++v6;
  }
  v11 = (this->m_cModes + 3) & 0xFFFFFFFC;
  if ( v6 < v11 )
  {
    v12 = out_pBCoef + 8;
    v13 = v11 - v6;
    do
    {
      *(v12 - 8) = 0;
      *(v12 - 4) = 0;
      *v12++ = 0;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 218
// RVA: 0xADF480
__int64 __fastcall CAkModalSynth::Term(CAkModalSynth *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 226
// RVA: 0xADF4C0
__int64 __fastcall CAkModalSynth::Reset(CAkModalSynth *this)
{
  float *m_pfAllocatedMem; // rcx

  m_pfAllocatedMem = this->m_pfAllocatedMem;
  if ( m_pfAllocatedMem )
    memset(m_pfAllocatedMem, 0, 8 * this->m_uNumProcessedChannels * ((this->m_cModes + 3) & 0xFFFFFFFC));
  *(_QWORD *)&this->m_DCFiltInfo.fDCFwdMem = 0i64;
  return 1i64;
}

// File Line: 241
// RVA: 0xADF510
__int64 __fastcall CAkModalSynth::GetPluginInfo(CAkModalSynth *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 282
// RVA: 0xADF530
void __fastcall CAkModalSynth::Execute(CAkModalSynth *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int m_uNumProcessedChannels; // ecx
  CAkModalSynthParams *m_pSharedParams; // rax
  float fResidualLevel; // xmm6_4
  float fOutputLevel; // xmm7_4
  unsigned int v8; // esi
  void *v9; // rax
  void *v10; // rbp
  unsigned int v11; // r11d
  unsigned int v12; // r10d
  float fDCCoef; // xmm6_4
  int uMaxFrames; // ecx
  float fDCFwdMem; // xmm4_4
  float fDCFbkMem; // xmm2_4
  __int64 v17; // rdx
  float v18; // xmm5_4
  float *v19; // r8
  float *v20; // rcx
  float *v21; // r9
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  __int64 v34; // rax
  float v35; // xmm0_4

  m_uNumProcessedChannels = this->m_uNumProcessedChannels;
  if ( m_uNumProcessedChannels )
  {
    if ( this->m_cModes )
    {
      m_pSharedParams = this->m_pSharedParams;
      fResidualLevel = m_pSharedParams->m_Params.fResidualLevel;
      fOutputLevel = m_pSharedParams->m_Params.fOutputLevel;
      v8 = 4 * m_uNumProcessedChannels * io_pBuffer->uMaxFrames;
      v9 = this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, v8);
      v10 = v9;
      if ( v9 )
      {
        memset(v9, 0, v8);
        AkAudioBuffer::ZeroPadToMaxFrames(io_pBuffer);
        Process_0(
          io_pBuffer,
          v10,
          this->m_pfFiltCoefs,
          this->m_pfAllocatedMem,
          this->m_uNumProcessedChannels,
          this->m_cModes);
        ScaleAndOutput(
          io_pBuffer,
          (float *)v10,
          fResidualLevel,
          &this->m_fCurResGain,
          fOutputLevel,
          &this->m_fCurOutGain,
          this->m_uNumProcessedChannels);
        if ( io_pBuffer->eState == AK_NoMoreData )
        {
          v11 = this->m_uNumProcessedChannels;
          v12 = 0;
          if ( v11 )
          {
            fDCCoef = this->m_DCFiltInfo.fDCCoef;
            LOWORD(uMaxFrames) = io_pBuffer->uMaxFrames;
            while ( 1 )
            {
              fDCFwdMem = this->m_DCFiltInfo.fDCFwdMem;
              fDCFbkMem = this->m_DCFiltInfo.fDCFbkMem;
              v17 = (unsigned __int16)uMaxFrames;
              v18 = 0.0;
              v19 = (float *)((char *)io_pBuffer->pData + 4 * (unsigned __int16)uMaxFrames * (unsigned __int64)v12);
              v20 = v19;
              v21 = &v19[v17];
              if ( v19 < v21 )
              {
                if ( (4 * v17 + 3) / 4 >= 4 )
                {
                  do
                  {
                    v22 = *v20;
                    v20 += 4;
                    v23 = fDCCoef * fDCFbkMem;
                    v24 = *(v20 - 3);
                    v25 = (float)(v22 - fDCFwdMem) + v23;
                    v26 = v24 - v22;
                    v27 = *(v20 - 2);
                    v28 = v26 + (float)(fDCCoef * v25);
                    *(v20 - 4) = v25;
                    *(v20 - 3) = v28;
                    v29 = fDCCoef * v28;
                    fDCFwdMem = *(v20 - 1);
                    v30 = (float)(v27 - v24) + v29;
                    *(v20 - 2) = v30;
                    fDCFbkMem = (float)(fDCFwdMem - v27) + (float)(fDCCoef * v30);
                    *(v20 - 1) = fDCFbkMem;
                  }
                  while ( (__int64)v20 < (__int64)(v21 - 3) );
                }
                for ( ; v20 < v21; fDCFbkMem = v33 )
                {
                  v31 = *v20++;
                  v32 = v31 - fDCFwdMem;
                  fDCFwdMem = v31;
                  v33 = v32 + (float)(fDCCoef * fDCFbkMem);
                  *(v20 - 1) = v33;
                }
              }
              this->m_DCFiltInfo.fDCFwdMem = fDCFwdMem;
              this->m_DCFiltInfo.fDCFbkMem = fDCFbkMem;
              uMaxFrames = io_pBuffer->uMaxFrames;
              if ( io_pBuffer->uMaxFrames )
              {
                v34 = io_pBuffer->uMaxFrames;
                do
                {
                  v35 = *v19++;
                  v18 = v18 + (float)(v35 * v35);
                  --v34;
                }
                while ( v34 );
              }
              if ( (float)(v18 / (float)uMaxFrames) >= 0.000000063095733 )
                break;
              if ( ++v12 >= v11 )
                goto LABEL_19;
            }
            io_pBuffer->eState = AK_DataReady;
          }
        }
LABEL_19:
        this->m_pAllocator->vfptr->Free(this->m_pAllocator, v10);
      }
    }
  }
}

