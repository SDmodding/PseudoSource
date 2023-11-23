// File Line: 37
// RVA: 0xAD0020
AK::IAkPlugin *__fastcall CreateCompressorFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 80i64);
  if ( result )
  {
    result->vfptr = (AK::IAkPluginVtbl *)&CAkCompressorFX::`vftable;
    result[1].vfptr = 0i64;
    result[2].vfptr = 0i64;
    result[6].vfptr = 0i64;
  }
  return result;
}

// File Line: 44
// RVA: 0xAD0070
void __fastcall CAkCompressorFX::CAkCompressorFX(CAkCompressorFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&CAkCompressorFX::`vftable;
  this->m_pSharedParams = 0i64;
  this->m_fpPerformDSP = 0i64;
  this->m_pSideChain = 0i64;
}

// File Line: 52
// RVA: 0xAD00A0
void __fastcall CAkCompressorFX::~CAkCompressorFX(CAkCompressorFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 62
// RVA: 0xAD00C0
__int64 __fastcall CAkCompressorFX::Init(
        CAkCompressorFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkCompressorFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  float fAttack; // xmm2_4
  unsigned int v8; // ebx
  float fOutputLevel; // xmm8_4
  float fRelease; // xmm9_4
  int i; // ecx
  int uSampleRate; // eax
  float v13; // xmm7_4
  float v14; // xmm0_4
  AkCompressorSideChain *v15; // rax
  __int64 result; // rax
  float v17; // xmm0_4
  int v18; // [rsp+34h] [rbp-54h]

  this->m_pSharedParams = in_pParams;
  fAttack = in_pParams->m_Params.fAttack;
  v8 = 0;
  fOutputLevel = in_pParams->m_Params.fOutputLevel;
  fRelease = in_pParams->m_Params.fRelease;
  v18 = *(_DWORD *)&in_pParams->m_Params.bProcessLFE;
  this->m_bProcessLFE = v18;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v8;
  this->m_uNumChannels = v8;
  uSampleRate = in_rFormat->uSampleRate;
  this->m_fCachedAttack = fAttack;
  this->m_uSampleRate = uSampleRate;
  v13 = (float)uSampleRate;
  v14 = expf(-2.2 / (float)((float)uSampleRate * fAttack));
  this->m_fCachedRelease = fRelease;
  this->m_fCachedAttackCoef = v14;
  this->m_fCachedReleaseCoef = expf(-2.2 / (float)(v13 * fRelease));
  if ( !BYTE1(v18) || v8 == 1 )
  {
    this->m_fpPerformDSP = CAkCompressorFX::Process;
  }
  else
  {
    this->m_fpPerformDSP = CAkCompressorFX::ProcessLinked;
    if ( (*((_BYTE *)in_rFormat + 4) & 8) != 0 && !(_BYTE)v18 )
      --v8;
  }
  if ( BYTE1(v18) )
    v8 = 1;
  this->m_uNumSideChain = v8;
  v15 = (AkCompressorSideChain *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8i64 * v8);
  this->m_pSideChain = v15;
  if ( !v15 )
    return 52i64;
  v17 = expf(-1.0 / (float)((float)(int)this->m_uSampleRate * 0.023220001));
  this->m_fCurrentGain = fOutputLevel;
  result = 1i64;
  this->m_fRMSFilterCoef = v17;
  return result;
}

// File Line: 111
// RVA: 0xAD0270
__int64 __fastcall CAkCompressorFX::Term(CAkCompressorFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->m_pSideChain )
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 120
// RVA: 0xAD02C0
__int64 __fastcall CAkCompressorFX::Reset(CAkCompressorFX *this)
{
  unsigned int i; // r8d
  __int64 v2; // rdx

  for ( i = 0; i < this->m_uNumSideChain; this->m_pSideChain[v2].fMem = 0.0 )
  {
    v2 = i++;
    this->m_pSideChain[v2].fGainDb = 0.0;
  }
  return 1i64;
}

// File Line: 132
// RVA: 0xAD0300
__int64 __fastcall CAkCompressorFX::GetPluginInfo(CAkCompressorFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 144
// RVA: 0xAD0320
void __fastcall CAkCompressorFX::Execute(CAkCompressorFX *this, AkAudioBuffer *io_pBuffer)
{
  CAkCompressorFXParams *m_pSharedParams; // rax
  int v5[4]; // [rsp+20h] [rbp-28h] BYREF
  float in_fTargetGain; // [rsp+30h] [rbp-18h]
  int v7; // [rsp+34h] [rbp-14h]

  if ( io_pBuffer->uValidFrames )
  {
    m_pSharedParams = this->m_pSharedParams;
    v5[0] = LODWORD(m_pSharedParams->m_Params.fThreshold);
    v5[1] = LODWORD(m_pSharedParams->m_Params.fRatio);
    v5[2] = LODWORD(m_pSharedParams->m_Params.fAttack);
    v5[3] = LODWORD(m_pSharedParams->m_Params.fRelease);
    in_fTargetGain = m_pSharedParams->m_Params.fOutputLevel;
    v7 = *(_DWORD *)&m_pSharedParams->m_Params.bProcessLFE;
    this->m_fpPerformDSP(this, io_pBuffer, (AkCompressorFXParams *)v5);
    AK::DSP::ApplyGain_2(io_pBuffer, this->m_fCurrentGain, in_fTargetGain, this->m_bProcessLFE);
    this->m_fCurrentGain = in_fTargetGain;
  }
}

// File Line: 165
// RVA: 0xAD03C0
void __fastcall CAkCompressorFX::Process(
        CAkCompressorFX *this,
        AkAudioBuffer *io_pBufferIn,
        AkCompressorFXParams *in_pParams)
{
  float fAttack; // xmm0_4
  float v7; // xmm11_4
  signed int m_uSampleRate; // eax
  float fRelease; // xmm0_4
  float m_fCachedAttackCoef; // xmm10_4
  signed int v11; // eax
  float m_fRMSFilterCoef; // xmm1_4
  float m_fCachedReleaseCoef; // xmm9_4
  unsigned int m_uNumChannels; // eax
  float v15; // xmm4_4
  __int64 v16; // r11
  __int64 v17; // rbp
  __int64 v18; // rbx
  float *v19; // r8
  float *v20; // r10
  AkCompressorSideChain *m_pSideChain; // rax
  float fMem; // xmm7_4
  float fGainDb; // xmm2_4
  float v24; // xmm5_4
  int v25; // edx
  float v26; // xmm6_4
  float v27; // xmm7_4
  float v28; // xmm1_4
  float v29; // xmm4_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm6_4
  float v35; // xmm7_4
  float v36; // xmm1_4
  float v37; // xmm4_4
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm1_4
  float v45; // xmm4_4
  float v46; // xmm0_4
  float v47; // xmm2_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm6_4
  float v51; // xmm1_4
  float v52; // xmm4_4
  float v53; // xmm0_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm6_4
  float v57; // xmm6_4
  float v58; // xmm1_4
  float v59; // xmm4_4
  float v60; // xmm0_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // xmm6_4
  float v64; // [rsp+20h] [rbp-D8h]
  float fThreshold; // [rsp+24h] [rbp-D4h]

  fThreshold = in_pParams->fThreshold;
  fAttack = in_pParams->fAttack;
  v7 = (float)(1.0 / in_pParams->fRatio) - 1.0;
  if ( fAttack != this->m_fCachedAttack )
  {
    m_uSampleRate = this->m_uSampleRate;
    this->m_fCachedAttack = fAttack;
    this->m_fCachedAttackCoef = expf(-2.2 / (float)((float)m_uSampleRate * in_pParams->fAttack));
  }
  fRelease = in_pParams->fRelease;
  m_fCachedAttackCoef = this->m_fCachedAttackCoef;
  if ( fRelease != this->m_fCachedRelease )
  {
    v11 = this->m_uSampleRate;
    this->m_fCachedRelease = fRelease;
    this->m_fCachedReleaseCoef = expf(-2.2 / (float)((float)v11 * in_pParams->fRelease));
  }
  m_fRMSFilterCoef = this->m_fRMSFilterCoef;
  m_fCachedReleaseCoef = this->m_fCachedReleaseCoef;
  v64 = m_fRMSFilterCoef;
  if ( (io_pBufferIn->uChannelMask & 8) == 0 || this->m_bProcessLFE )
    m_uNumChannels = this->m_uNumChannels;
  else
    m_uNumChannels = this->m_uNumChannels - 1;
  if ( m_uNumChannels )
  {
    v15 = FLOAT_1_0eN25;
    v16 = 0i64;
    v17 = m_uNumChannels;
    v18 = 0i64;
    do
    {
      v19 = (float *)((char *)io_pBufferIn->pData + 4 * v18 * io_pBufferIn->uMaxFrames);
      v20 = &v19[io_pBufferIn->uValidFrames];
      m_pSideChain = this->m_pSideChain;
      fMem = m_pSideChain[v16].fMem;
      fGainDb = m_pSideChain[v16].fGainDb;
      if ( v19 < v20 )
      {
        v24 = *(float *)&`AkMath::FastPow10::`4::SCALE;
        v25 = `AkMath::FastPow10::`4::`local static guard;
        if ( (4i64 * io_pBufferIn->uValidFrames + 3) / 4 >= 4 )
        {
          do
          {
            v26 = *v19;
            v27 = (float)((float)(fMem - (float)((float)(v26 * v26) + v15)) * m_fRMSFilterCoef)
                + (float)((float)(v26 * v26) + v15);
            v28 = (float)(COERCE_FLOAT((LODWORD(v27) & 0x7FFFFF) + 1065353216) - 1.0)
                / (float)(COERCE_FLOAT((LODWORD(v27) & 0x7FFFFF) + 1065353216) + 1.0);
            v29 = (float)((float)((float)((float)((float)((float)((float)(v28 * v28) * 0.33333334) + 1.0)
                                                * (float)(v28 * 2.0))
                                        + (float)((float)((float)(unsigned __int8)(LODWORD(v27) >> 23) - 127.0)
                                                * 0.69314718))
                                * 0.43429449)
                        * 10.0)
                - fThreshold;
            if ( v29 <= 0.0 )
              v29 = 0.0;
            if ( (float)(v29 - fGainDb) < 0.0 )
              v30 = m_fCachedReleaseCoef;
            else
              v30 = m_fCachedAttackCoef;
            v31 = (float)((float)(fGainDb - v29) * v30) + v29;
            v32 = (float)(v31 * v7) * 0.050000001;
            if ( v32 >= -37.0 )
            {
              if ( (v25 & 1) == 0 )
              {
                v24 = FLOAT_2_7866352e7;
                v25 |= 1u;
                `AkMath::FastPow10::`4::`local static guard = v25;
                `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              }
              v33 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                      ((int)(float)((float)(v32 * v24) + 1065353200.0) & 0x7FFFFF)
                                                    + 1065353216)
                                                  * 0.32518977)
                                          + 0.020805772)
                                  * COERCE_FLOAT(((int)(float)((float)(v32 * v24) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                          + 0.65304345)
                  * COERCE_FLOAT((int)(float)((float)(v32 * v24) + 1065353200.0) & 0xFF800000);
            }
            else
            {
              v33 = 0.0;
            }
            *v19 = v26 * v33;
            v34 = v19[1];
            v35 = (float)((float)(v27 - (float)((float)(v34 * v34) + 1.0e-25)) * v64)
                + (float)((float)(v34 * v34) + 1.0e-25);
            v36 = (float)(COERCE_FLOAT((LODWORD(v35) & 0x7FFFFF) + 1065353216) - 1.0)
                / (float)(COERCE_FLOAT((LODWORD(v35) & 0x7FFFFF) + 1065353216) + 1.0);
            v37 = (float)((float)((float)((float)((float)((float)((float)(v36 * v36) * 0.33333334) + 1.0)
                                                * (float)(v36 * 2.0))
                                        + (float)((float)((float)(unsigned __int8)(LODWORD(v35) >> 23) - 127.0)
                                                * 0.69314718))
                                * 0.43429449)
                        * 10.0)
                - fThreshold;
            if ( v37 <= 0.0 )
              v37 = 0.0;
            if ( (float)(v37 - v31) < 0.0 )
              v38 = m_fCachedReleaseCoef;
            else
              v38 = m_fCachedAttackCoef;
            v39 = (float)((float)(v31 - v37) * v38) + v37;
            v40 = (float)(v39 * v7) * 0.050000001;
            if ( v40 >= -37.0 )
            {
              if ( (v25 & 1) == 0 )
              {
                v24 = FLOAT_2_7866352e7;
                v25 |= 1u;
                `AkMath::FastPow10::`4::`local static guard = v25;
                `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              }
              v41 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                      ((int)(float)((float)(v40 * v24) + 1065353200.0) & 0x7FFFFF)
                                                    + 1065353216)
                                                  * 0.32518977)
                                          + 0.020805772)
                                  * COERCE_FLOAT(((int)(float)((float)(v40 * v24) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                          + 0.65304345)
                  * COERCE_FLOAT((int)(float)((float)(v40 * v24) + 1065353200.0) & 0xFF800000);
            }
            else
            {
              v41 = 0.0;
            }
            v19[1] = v34 * v41;
            v42 = v19[2];
            v43 = (float)((float)(v35 - (float)((float)(v42 * v42) + 1.0e-25)) * v64)
                + (float)((float)(v42 * v42) + 1.0e-25);
            v44 = (float)(COERCE_FLOAT((LODWORD(v43) & 0x7FFFFF) + 1065353216) - 1.0)
                / (float)(COERCE_FLOAT((LODWORD(v43) & 0x7FFFFF) + 1065353216) + 1.0);
            v45 = (float)((float)((float)((float)((float)((float)((float)(v44 * v44) * 0.33333334) + 1.0)
                                                * (float)(v44 * 2.0))
                                        + (float)((float)((float)(unsigned __int8)(LODWORD(v43) >> 23) - 127.0)
                                                * 0.69314718))
                                * 0.43429449)
                        * 10.0)
                - fThreshold;
            if ( v45 <= 0.0 )
              v45 = 0.0;
            if ( (float)(v45 - v39) < 0.0 )
              v46 = m_fCachedReleaseCoef;
            else
              v46 = m_fCachedAttackCoef;
            v47 = (float)((float)(v39 - v45) * v46) + v45;
            v48 = (float)(v47 * v7) * 0.050000001;
            if ( v48 >= -37.0 )
            {
              if ( (v25 & 1) == 0 )
              {
                v24 = FLOAT_2_7866352e7;
                v25 |= 1u;
                `AkMath::FastPow10::`4::`local static guard = v25;
                `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              }
              v49 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                      ((int)(float)((float)(v48 * v24) + 1065353200.0) & 0x7FFFFF)
                                                    + 1065353216)
                                                  * 0.32518977)
                                          + 0.020805772)
                                  * COERCE_FLOAT(((int)(float)((float)(v48 * v24) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                          + 0.65304345)
                  * COERCE_FLOAT((int)(float)((float)(v48 * v24) + 1065353200.0) & 0xFF800000);
            }
            else
            {
              v49 = 0.0;
            }
            v19[2] = v42 * v49;
            v50 = v19[3];
            fMem = (float)((float)(v43 - (float)((float)(v50 * v50) + 1.0e-25)) * v64)
                 + (float)((float)(v50 * v50) + 1.0e-25);
            v51 = (float)(COERCE_FLOAT((LODWORD(fMem) & 0x7FFFFF) + 1065353216) - 1.0)
                / (float)(COERCE_FLOAT((LODWORD(fMem) & 0x7FFFFF) + 1065353216) + 1.0);
            v52 = (float)((float)((float)((float)((float)((float)((float)(v51 * v51) * 0.33333334) + 1.0)
                                                * (float)(v51 * 2.0))
                                        + (float)((float)((float)(unsigned __int8)(LODWORD(fMem) >> 23) - 127.0)
                                                * 0.69314718))
                                * 0.43429449)
                        * 10.0)
                - fThreshold;
            if ( v52 <= 0.0 )
              v52 = 0.0;
            if ( (float)(v52 - v47) < 0.0 )
              v53 = m_fCachedReleaseCoef;
            else
              v53 = m_fCachedAttackCoef;
            fGainDb = (float)((float)(v47 - v52) * v53) + v52;
            v54 = (float)(fGainDb * v7) * 0.050000001;
            if ( v54 >= -37.0 )
            {
              if ( (v25 & 1) == 0 )
              {
                v24 = FLOAT_2_7866352e7;
                v25 |= 1u;
                `AkMath::FastPow10::`4::`local static guard = v25;
                `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              }
              v55 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                      ((int)(float)((float)(v54 * v24) + 1065353200.0) & 0x7FFFFF)
                                                    + 1065353216)
                                                  * 0.32518977)
                                          + 0.020805772)
                                  * COERCE_FLOAT(((int)(float)((float)(v54 * v24) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                          + 0.65304345)
                  * COERCE_FLOAT((int)(float)((float)(v54 * v24) + 1065353200.0) & 0xFF800000);
            }
            else
            {
              v55 = 0.0;
            }
            v15 = FLOAT_1_0eN25;
            v56 = v50 * v55;
            m_fRMSFilterCoef = v64;
            v19 += 4;
            *(v19 - 1) = v56;
          }
          while ( (__int64)v19 < (__int64)(v20 - 3) );
        }
        if ( v19 < v20 )
        {
          do
          {
            v57 = *v19;
            fMem = (float)((float)(fMem - (float)((float)(v57 * v57) + v15)) * m_fRMSFilterCoef)
                 + (float)((float)(v57 * v57) + v15);
            v58 = (float)(COERCE_FLOAT((LODWORD(fMem) & 0x7FFFFF) + 1065353216) - 1.0)
                / (float)(COERCE_FLOAT((LODWORD(fMem) & 0x7FFFFF) + 1065353216) + 1.0);
            v59 = (float)((float)((float)((float)((float)((float)((float)(v58 * v58) * 0.33333334) + 1.0)
                                                * (float)(v58 * 2.0))
                                        + (float)((float)((float)(unsigned __int8)(LODWORD(fMem) >> 23) - 127.0)
                                                * 0.69314718))
                                * 0.43429449)
                        * 10.0)
                - fThreshold;
            if ( v59 <= 0.0 )
              v59 = 0.0;
            if ( (float)(v59 - fGainDb) < 0.0 )
              v60 = m_fCachedReleaseCoef;
            else
              v60 = m_fCachedAttackCoef;
            fGainDb = (float)((float)(fGainDb - v59) * v60) + v59;
            v61 = (float)(fGainDb * v7) * 0.050000001;
            if ( v61 >= -37.0 )
            {
              if ( (v25 & 1) == 0 )
              {
                v25 |= 1u;
                v24 = FLOAT_2_7866352e7;
              }
              v62 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                      ((int)(float)((float)(v61 * v24) + 1065353200.0) & 0x7FFFFF)
                                                    + 1065353216)
                                                  * 0.32518977)
                                          + 0.020805772)
                                  * COERCE_FLOAT(((int)(float)((float)(v61 * v24) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                          + 0.65304345)
                  * COERCE_FLOAT((int)(float)((float)(v61 * v24) + 1065353200.0) & 0xFF800000);
            }
            else
            {
              v62 = 0.0;
            }
            v15 = FLOAT_1_0eN25;
            v63 = v57 * v62;
            m_fRMSFilterCoef = v64;
            *v19++ = v63;
          }
          while ( v19 < v20 );
          `AkMath::FastPow10::`4::SCALE = LODWORD(v24);
          `AkMath::FastPow10::`4::`local static guard = v25;
        }
      }
      m_fRMSFilterCoef = v64;
      v15 = FLOAT_1_0eN25;
      ++v16;
      ++v18;
      this->m_pSideChain[v16 - 1].fMem = fMem;
      this->m_pSideChain[v16 - 1].fGainDb = fGainDb;
      --v17;
    }
    while ( v17 );
  }
}

// File Line: 230
// RVA: 0xAD0E10
void __fastcall CAkCompressorFX::ProcessLinked(
        CAkCompressorFX *this,
        AkAudioBuffer *io_pBufferIn,
        AkCompressorFXParams *in_pParams)
{
  signed int m_uNumChannels; // ebx
  float v7; // xmm7_4
  float fAttack; // xmm0_4
  signed int m_uSampleRate; // eax
  float fRelease; // xmm0_4
  float m_fCachedAttackCoef; // xmm9_4
  signed int v12; // eax
  AkCompressorSideChain *m_pSideChain; // rax
  float m_fRMSFilterCoef; // xmm1_4
  float m_fCachedReleaseCoef; // xmm6_4
  float fMem; // xmm5_4
  float fGainDb; // xmm3_4
  char *pData; // rcx
  __int64 *v19; // rax
  __int64 v20; // r8
  __int64 v21; // rdx
  int i; // r9d
  unsigned int v23; // r8d
  __int64 v24; // rcx
  float v25; // xmm2_4
  unsigned int v26; // eax
  __int64 v27; // rdx
  float *v28; // rax
  float **v29; // rdx
  __int64 v30; // rcx
  float *v31; // rax
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  int v37; // eax
  unsigned int v38; // r8d
  __int64 v39; // rcx
  unsigned int v40; // eax
  __int64 v41; // rdx
  __int64 v42; // rax
  __int64 v43; // rax
  __int64 v44; // rax
  __int64 v45; // rax
  __int64 *v46; // rdx
  __int64 v47; // rcx
  __int64 v48; // rax
  __int64 v49[2]; // [rsp+10h] [rbp-128h]
  float v50[4]; // [rsp+20h] [rbp-118h]
  __int64 v51[8]; // [rsp+30h] [rbp-108h] BYREF
  float v52; // [rsp+148h] [rbp+10h]
  float fThreshold; // [rsp+158h] [rbp+20h]

  if ( (io_pBufferIn->uChannelMask & 8) == 0 || this->m_bProcessLFE )
    m_uNumChannels = this->m_uNumChannels;
  else
    m_uNumChannels = this->m_uNumChannels - 1;
  v7 = (float)(1.0 / in_pParams->fRatio) - 1.0;
  fThreshold = in_pParams->fThreshold;
  fAttack = in_pParams->fAttack;
  if ( fAttack != this->m_fCachedAttack )
  {
    m_uSampleRate = this->m_uSampleRate;
    this->m_fCachedAttack = fAttack;
    this->m_fCachedAttackCoef = expf(-2.2 / (float)((float)m_uSampleRate * in_pParams->fAttack));
  }
  fRelease = in_pParams->fRelease;
  m_fCachedAttackCoef = this->m_fCachedAttackCoef;
  if ( fRelease != this->m_fCachedRelease )
  {
    v12 = this->m_uSampleRate;
    this->m_fCachedRelease = fRelease;
    this->m_fCachedReleaseCoef = expf(-2.2 / (float)((float)v12 * in_pParams->fRelease));
  }
  m_pSideChain = this->m_pSideChain;
  m_fRMSFilterCoef = this->m_fRMSFilterCoef;
  m_fCachedReleaseCoef = this->m_fCachedReleaseCoef;
  fMem = m_pSideChain->fMem;
  fGainDb = m_pSideChain->fGainDb;
  v52 = m_fRMSFilterCoef;
  if ( m_uNumChannels )
  {
    pData = (char *)io_pBufferIn->pData;
    v19 = v51;
    v20 = 4i64 * io_pBufferIn->uMaxFrames;
    v21 = (unsigned int)m_uNumChannels;
    do
    {
      *v19 = (__int64)pData;
      pData += v20;
      ++v19;
      --v21;
    }
    while ( v21 );
  }
  for ( i = io_pBufferIn->uValidFrames - 1; i >= 0; m_fRMSFilterCoef = v52 )
  {
    v23 = 0;
    v24 = 0i64;
    v25 = 0.0;
    if ( m_uNumChannels >= 4 )
    {
      v26 = ((unsigned int)(m_uNumChannels - 4) >> 2) + 1;
      v27 = v26;
      v23 = 4 * v26;
      do
      {
        v28 = (float *)v51[v24];
        v24 += 4i64;
        v25 = (float)((float)((float)(v25 + (float)(*v28 * *v28))
                            + (float)(*(float *)v49[v24 + 1] * *(float *)v49[v24 + 1]))
                    + (float)(**(float **)&v50[2 * v24] * **(float **)&v50[2 * v24]))
            + (float)(**(float **)&v50[2 * v24 + 2] * **(float **)&v50[2 * v24 + 2]);
        --v27;
      }
      while ( v27 );
      m_fRMSFilterCoef = v52;
    }
    if ( v23 < m_uNumChannels )
    {
      v29 = (float **)&v51[v24];
      v30 = m_uNumChannels - v23;
      do
      {
        v31 = *v29++;
        v25 = v25 + (float)(*v31 * *v31);
        --v30;
      }
      while ( v30 );
    }
    fMem = (float)((float)(fMem - (float)((float)(v25 * (float)(1.0 / (float)m_uNumChannels)) + 1.0e-25))
                 * m_fRMSFilterCoef)
         + (float)((float)(v25 * (float)(1.0 / (float)m_uNumChannels)) + 1.0e-25);
    v32 = (float)(COERCE_FLOAT((LODWORD(fMem) & 0x7FFFFF) + 1065353216) - 1.0)
        / (float)(COERCE_FLOAT((LODWORD(fMem) & 0x7FFFFF) + 1065353216) + 1.0);
    v33 = (float)((float)((float)((float)((float)((float)((float)(v32 * v32) * 0.33333334) + 1.0) * (float)(v32 * 2.0))
                                + (float)((float)((float)(unsigned __int8)(LODWORD(fMem) >> 23) - 127.0) * 0.69314718))
                        * 0.43429449)
                * 10.0)
        - fThreshold;
    if ( v33 <= 0.0 )
      v33 = 0.0;
    if ( (float)(v33 - fGainDb) < 0.0 )
      v34 = m_fCachedReleaseCoef;
    else
      v34 = m_fCachedAttackCoef;
    fGainDb = (float)((float)(fGainDb - v33) * v34) + v33;
    v35 = (float)(fGainDb * v7) * 0.050000001;
    if ( v35 >= -37.0 )
    {
      if ( (`AkMath::FastPow10::`4::`local static guard & 1) == 0 )
      {
        `AkMath::FastPow10::`4::`local static guard |= 1u;
        `AkMath::FastPow10::`4::SCALE = 1272224376;
      }
      v37 = (int)(float)((float)(v35 * *(float *)&`AkMath::FastPow10::`4::SCALE) + 1065353200.0);
      LODWORD(v50[0]) = (v37 & 0x7FFFFF) + 1065353216;
      LODWORD(v50[1]) = v37 & 0xFF800000;
      v36 = (float)((float)((float)((float)(v50[0] * 0.32518977) + 0.020805772) * v50[0]) + 0.65304345)
          * COERCE_FLOAT(v37 & 0xFF800000);
    }
    else
    {
      v36 = 0.0;
    }
    v38 = 0;
    v39 = 0i64;
    if ( m_uNumChannels >= 4 )
    {
      v40 = ((unsigned int)(m_uNumChannels - 4) >> 2) + 1;
      v41 = v40;
      v38 = 4 * v40;
      do
      {
        v42 = v51[v39];
        v39 += 4i64;
        v42 += 4i64;
        v49[v39] = v42;
        *(float *)(v42 - 4) = v36 * *(float *)(v42 - 4);
        v43 = v49[v39 + 1] + 4;
        v49[v39 + 1] = v43;
        *(float *)(v43 - 4) = v36 * *(float *)(v43 - 4);
        v44 = *(_QWORD *)&v50[2 * v39] + 4i64;
        *(_QWORD *)&v50[2 * v39] = v44;
        *(float *)(v44 - 4) = v36 * *(float *)(v44 - 4);
        v45 = *(_QWORD *)&v50[2 * v39 + 2] + 4i64;
        *(_QWORD *)&v50[2 * v39 + 2] = v45;
        *(float *)(v45 - 4) = v36 * *(float *)(v45 - 4);
        --v41;
      }
      while ( v41 );
    }
    if ( v38 < m_uNumChannels )
    {
      v46 = &v51[v39];
      v47 = m_uNumChannels - v38;
      do
      {
        v48 = *v46++;
        v48 += 4i64;
        *(v46 - 1) = v48;
        *(float *)(v48 - 4) = v36 * *(float *)(v48 - 4);
        --v47;
      }
      while ( v47 );
    }
    --i;
  }
  this->m_pSideChain->fMem = fMem;
  this->m_pSideChain->fGainDb = fGainDb;
}

