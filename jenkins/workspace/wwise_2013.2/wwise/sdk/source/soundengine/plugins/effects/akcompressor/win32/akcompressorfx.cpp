// File Line: 37
// RVA: 0xAD0020
AK::IAkPlugin *__fastcall CreateCompressorFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 80ui64);
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
signed __int64 __fastcall CAkCompressorFX::Init(CAkCompressorFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  float v5; // xmm2_4
  CAkCompressorFX *v6; // rdi
  AK::IAkPluginMemAlloc *v7; // r14
  unsigned int v8; // ebx
  float v9; // xmm8_4
  float v10; // xmm9_4
  int v11; // ST20_4
  int v12; // ST24_4
  int i; // ecx
  signed int v14; // eax
  float v15; // xmm7_4
  float v16; // xmm0_4
  __int64 v17; // rax
  signed __int64 result; // rax
  float v19; // xmm0_4
  int v20; // [rsp+34h] [rbp-54h]

  this->m_pSharedParams = (CAkCompressorFXParams *)in_pParams;
  v5 = *(float *)&in_pParams[2].vfptr;
  v6 = this;
  v7 = in_pAllocator;
  v8 = 0;
  v9 = *(float *)&in_pParams[3].vfptr;
  v10 = *((float *)&in_pParams[2].vfptr + 1);
  v11 = (int)in_pParams[1].vfptr;
  v12 = HIDWORD(in_pParams[1].vfptr);
  v20 = HIDWORD(in_pParams[3].vfptr);
  this->m_bProcessLFE = v20;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v8;
  v6->m_uNumChannels = v8;
  v14 = in_rFormat->uSampleRate;
  v6->m_fCachedAttack = v5;
  v6->m_uSampleRate = v14;
  v15 = (float)v14;
  v16 = expf(-2.2 / (float)((float)v14 * v5));
  v6->m_fCachedRelease = v10;
  v6->m_fCachedAttackCoef = v16;
  v6->m_fCachedReleaseCoef = expf(-2.2 / (float)(v15 * v10));
  if ( BYTE1(v20) && v8 != 1 )
  {
    v6->m_fpPerformDSP = CAkCompressorFX::ProcessLinked;
    if ( *((_BYTE *)in_rFormat + 4) & 8 && !(_BYTE)v20 )
      --v8;
  }
  else
  {
    v6->m_fpPerformDSP = CAkCompressorFX::Process;
  }
  if ( BYTE1(v20) )
    v8 = 1;
  v6->m_uNumSideChain = v8;
  v17 = (__int64)v7->vfptr->Malloc(v7, 8i64 * v8);
  v6->m_pSideChain = (AkCompressorSideChain *)v17;
  if ( !v17 )
    return 52i64;
  v19 = expf(-1.0 / (float)((float)(signed int)v6->m_uSampleRate * 0.023220001));
  v6->m_fCurrentGain = v9;
  result = 1i64;
  v6->m_fRMSFilterCoef = v19;
  return result;
}

// File Line: 111
// RVA: 0xAD0270
signed __int64 __fastcall CAkCompressorFX::Term(CAkCompressorFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rbx
  CAkCompressorFX *v3; // rdi

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_pSideChain )
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
  v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v3->vfptr, 0);
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

// File Line: 120
// RVA: 0xAD02C0
signed __int64 __fastcall CAkCompressorFX::Reset(CAkCompressorFX *this)
{
  unsigned int v1; // er8
  __int64 v2; // rdx

  v1 = 0;
  if ( this->m_uNumSideChain )
  {
    do
    {
      v2 = v1++;
      this->m_pSideChain[v2].fGainDb = 0.0;
      this->m_pSideChain[v2].fMem = 0.0;
    }
    while ( v1 < this->m_uNumSideChain );
  }
  return 1i64;
}

// File Line: 132
// RVA: 0xAD0300
signed __int64 __fastcall CAkCompressorFX::GetPluginInfo(CAkCompressorFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 144
// RVA: 0xAD0320
void __fastcall CAkCompressorFX::Execute(CAkCompressorFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // rbx
  CAkCompressorFX *v3; // rdi
  CAkCompressorFXParams *v4; // rax
  float v5; // [rsp+20h] [rbp-28h]
  float v6; // [rsp+24h] [rbp-24h]
  float v7; // [rsp+28h] [rbp-20h]
  float v8; // [rsp+2Ch] [rbp-1Ch]
  float in_fTargetGain; // [rsp+30h] [rbp-18h]
  int v10; // [rsp+34h] [rbp-14h]

  v2 = io_pBuffer;
  v3 = this;
  if ( io_pBuffer->uValidFrames )
  {
    v4 = this->m_pSharedParams;
    v5 = v4->m_Params.fThreshold;
    v6 = v4->m_Params.fRatio;
    v7 = v4->m_Params.fAttack;
    v8 = v4->m_Params.fRelease;
    in_fTargetGain = v4->m_Params.fOutputLevel;
    v10 = *(_DWORD *)&v4->m_Params.bProcessLFE;
    this->m_fpPerformDSP(this, io_pBuffer, (AkCompressorFXParams *)&v5);
    AK::DSP::ApplyGain_2(v2, v3->m_fCurrentGain, in_fTargetGain, v3->m_bProcessLFE);
    v3->m_fCurrentGain = in_fTargetGain;
  }
}

// File Line: 165
// RVA: 0xAD03C0
void __fastcall CAkCompressorFX::Process(CAkCompressorFX *this, AkAudioBuffer *io_pBufferIn, AkCompressorFXParams *in_pParams)
{
  AkCompressorFXParams *v3; // rbx
  AkAudioBuffer *v4; // rsi
  CAkCompressorFX *v5; // rdi
  float v6; // xmm0_4
  float v7; // xmm11_4
  signed int v8; // eax
  float v9; // xmm0_4
  float v10; // xmm10_4
  signed int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm9_4
  unsigned int v14; // eax
  float v15; // xmm4_4
  __int64 v16; // r11
  __int64 v17; // rbp
  __int64 v18; // rbx
  float *v19; // r8
  unsigned __int64 v20; // r10
  AkCompressorSideChain *v21; // rax
  float v22; // xmm7_4
  float v23; // xmm2_4
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
  float v65; // [rsp+24h] [rbp-D4h]

  v3 = in_pParams;
  v4 = io_pBufferIn;
  v5 = this;
  v65 = in_pParams->fThreshold;
  v6 = in_pParams->fAttack;
  v7 = (float)(1.0 / in_pParams->fRatio) - 1.0;
  if ( v6 != this->m_fCachedAttack )
  {
    v8 = this->m_uSampleRate;
    this->m_fCachedAttack = v6;
    this->m_fCachedAttackCoef = expf(-2.2 / (float)((float)v8 * in_pParams->fAttack));
  }
  v9 = v3->fRelease;
  v10 = v5->m_fCachedAttackCoef;
  if ( v9 != v5->m_fCachedRelease )
  {
    v11 = v5->m_uSampleRate;
    v5->m_fCachedRelease = v9;
    v5->m_fCachedReleaseCoef = expf(-2.2 / (float)((float)v11 * v3->fRelease));
  }
  v12 = v5->m_fRMSFilterCoef;
  v13 = v5->m_fCachedReleaseCoef;
  v64 = v5->m_fRMSFilterCoef;
  if ( !(v4->uChannelMask & 8) || v5->m_bProcessLFE )
    v14 = v5->m_uNumChannels;
  else
    v14 = v5->m_uNumChannels - 1;
  if ( v14 )
  {
    v15 = FLOAT_1_0eN25;
    v16 = 0i64;
    v17 = v14;
    v18 = 0i64;
    do
    {
      v19 = (float *)((char *)v4->pData + 4 * v18 * v4->uMaxFrames);
      v20 = (unsigned __int64)&v19[v4->uValidFrames];
      v21 = v5->m_pSideChain;
      v22 = v21[v16].fMem;
      v23 = v21[v16].fGainDb;
      if ( (unsigned __int64)v19 < v20 )
      {
        v24 = *(float *)&`AkMath::FastPow10::`4::SCALE;
        v25 = `AkMath::FastPow10::`4::`local static guard;
        if ( (4i64 * v4->uValidFrames + 3) / 4 >= 4 )
        {
          do
          {
            v26 = *v19;
            v27 = (float)((float)(v22 - (float)((float)(v26 * v26) + v15)) * v12) + (float)((float)(v26 * v26) + v15);
            v28 = (float)(COERCE_FLOAT((LODWORD(v27) & 0x7FFFFF) + 1065353216) - 1.0)
                / (float)(COERCE_FLOAT((LODWORD(v27) & 0x7FFFFF) + 1065353216) + 1.0);
            v29 = (float)((float)((float)((float)((float)((float)((float)(v28 * v28) * 0.33333334) + 1.0)
                                                * (float)(v28 * 2.0))
                                        + (float)((float)((float)(unsigned __int8)(LODWORD(v27) >> 23) - 127.0)
                                                * 0.69314718))
                                * 0.43429449)
                        * 10.0)
                - v65;
            if ( v29 <= 0.0 )
              v29 = 0.0;
            if ( (float)(v29 - v23) < 0.0 )
              v30 = v13;
            else
              v30 = v10;
            v31 = (float)((float)(v23 - v29) * v30) + v29;
            v32 = (float)(v31 * v7) * 0.050000001;
            if ( v32 >= -37.0 )
            {
              if ( !(v25 & 1) )
              {
                v24 = FLOAT_2_7866352e7;
                v25 |= 1u;
                `AkMath::FastPow10::`4::`local static guard = v25;
                `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              }
              v33 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                      ((signed int)(float)((float)(v32 * v24) + 1065353200.0) & 0x7FFFFF)
                                                    + 1065353216)
                                                  * 0.32518977)
                                          + 0.020805772)
                                  * COERCE_FLOAT(((signed int)(float)((float)(v32 * v24) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                          + 0.65304345)
                  * COERCE_FLOAT((signed int)(float)((float)(v32 * v24) + 1065353200.0) & 0xFF800000);
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
                - v65;
            if ( v37 <= 0.0 )
              v37 = 0.0;
            if ( (float)(v37 - v31) < 0.0 )
              v38 = v13;
            else
              v38 = v10;
            v39 = (float)((float)(v31 - v37) * v38) + v37;
            v40 = (float)(v39 * v7) * 0.050000001;
            if ( v40 >= -37.0 )
            {
              if ( !(v25 & 1) )
              {
                v24 = FLOAT_2_7866352e7;
                v25 |= 1u;
                `AkMath::FastPow10::`4::`local static guard = v25;
                `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              }
              v41 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                      ((signed int)(float)((float)(v40 * v24) + 1065353200.0) & 0x7FFFFF)
                                                    + 1065353216)
                                                  * 0.32518977)
                                          + 0.020805772)
                                  * COERCE_FLOAT(((signed int)(float)((float)(v40 * v24) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                          + 0.65304345)
                  * COERCE_FLOAT((signed int)(float)((float)(v40 * v24) + 1065353200.0) & 0xFF800000);
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
                - v65;
            if ( v45 <= 0.0 )
              v45 = 0.0;
            if ( (float)(v45 - v39) < 0.0 )
              v46 = v13;
            else
              v46 = v10;
            v47 = (float)((float)(v39 - v45) * v46) + v45;
            v48 = (float)(v47 * v7) * 0.050000001;
            if ( v48 >= -37.0 )
            {
              if ( !(v25 & 1) )
              {
                v24 = FLOAT_2_7866352e7;
                v25 |= 1u;
                `AkMath::FastPow10::`4::`local static guard = v25;
                `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              }
              v49 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                      ((signed int)(float)((float)(v48 * v24) + 1065353200.0) & 0x7FFFFF)
                                                    + 1065353216)
                                                  * 0.32518977)
                                          + 0.020805772)
                                  * COERCE_FLOAT(((signed int)(float)((float)(v48 * v24) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                          + 0.65304345)
                  * COERCE_FLOAT((signed int)(float)((float)(v48 * v24) + 1065353200.0) & 0xFF800000);
            }
            else
            {
              v49 = 0.0;
            }
            v19[2] = v42 * v49;
            v50 = v19[3];
            v22 = (float)((float)(v43 - (float)((float)(v50 * v50) + 1.0e-25)) * v64)
                + (float)((float)(v50 * v50) + 1.0e-25);
            v51 = (float)(COERCE_FLOAT((LODWORD(v22) & 0x7FFFFF) + 1065353216) - 1.0)
                / (float)(COERCE_FLOAT((LODWORD(v22) & 0x7FFFFF) + 1065353216) + 1.0);
            v52 = (float)((float)((float)((float)((float)((float)((float)(v51 * v51) * 0.33333334) + 1.0)
                                                * (float)(v51 * 2.0))
                                        + (float)((float)((float)(unsigned __int8)(LODWORD(v22) >> 23) - 127.0)
                                                * 0.69314718))
                                * 0.43429449)
                        * 10.0)
                - v65;
            if ( v52 <= 0.0 )
              v52 = 0.0;
            if ( (float)(v52 - v47) < 0.0 )
              v53 = v13;
            else
              v53 = v10;
            v23 = (float)((float)(v47 - v52) * v53) + v52;
            v54 = (float)(v23 * v7) * 0.050000001;
            if ( v54 >= -37.0 )
            {
              if ( !(v25 & 1) )
              {
                v24 = FLOAT_2_7866352e7;
                v25 |= 1u;
                `AkMath::FastPow10::`4::`local static guard = v25;
                `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              }
              v55 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                      ((signed int)(float)((float)(v54 * v24) + 1065353200.0) & 0x7FFFFF)
                                                    + 1065353216)
                                                  * 0.32518977)
                                          + 0.020805772)
                                  * COERCE_FLOAT(((signed int)(float)((float)(v54 * v24) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                          + 0.65304345)
                  * COERCE_FLOAT((signed int)(float)((float)(v54 * v24) + 1065353200.0) & 0xFF800000);
            }
            else
            {
              v55 = 0.0;
            }
            v15 = FLOAT_1_0eN25;
            v56 = v50 * v55;
            v12 = v64;
            v19 += 4;
            *(v19 - 1) = v56;
          }
          while ( (signed __int64)v19 < (signed __int64)(v20 - 12) );
        }
        if ( (unsigned __int64)v19 < v20 )
        {
          do
          {
            v57 = *v19;
            v22 = (float)((float)(v22 - (float)((float)(v57 * v57) + v15)) * v12) + (float)((float)(v57 * v57) + v15);
            v58 = (float)(COERCE_FLOAT((LODWORD(v22) & 0x7FFFFF) + 1065353216) - 1.0)
                / (float)(COERCE_FLOAT((LODWORD(v22) & 0x7FFFFF) + 1065353216) + 1.0);
            v59 = (float)((float)((float)((float)((float)((float)((float)(v58 * v58) * 0.33333334) + 1.0)
                                                * (float)(v58 * 2.0))
                                        + (float)((float)((float)(unsigned __int8)(LODWORD(v22) >> 23) - 127.0)
                                                * 0.69314718))
                                * 0.43429449)
                        * 10.0)
                - v65;
            if ( v59 <= 0.0 )
              v59 = 0.0;
            if ( (float)(v59 - v23) < 0.0 )
              v60 = v13;
            else
              v60 = v10;
            v23 = (float)((float)(v23 - v59) * v60) + v59;
            v61 = (float)(v23 * v7) * 0.050000001;
            if ( v61 >= -37.0 )
            {
              if ( !(v25 & 1) )
              {
                v25 |= 1u;
                v24 = FLOAT_2_7866352e7;
              }
              v62 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                      ((signed int)(float)((float)(v61 * v24) + 1065353200.0) & 0x7FFFFF)
                                                    + 1065353216)
                                                  * 0.32518977)
                                          + 0.020805772)
                                  * COERCE_FLOAT(((signed int)(float)((float)(v61 * v24) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                          + 0.65304345)
                  * COERCE_FLOAT((signed int)(float)((float)(v61 * v24) + 1065353200.0) & 0xFF800000);
            }
            else
            {
              v62 = 0.0;
            }
            v15 = FLOAT_1_0eN25;
            v63 = v57 * v62;
            v12 = v64;
            ++v19;
            *(v19 - 1) = v63;
          }
          while ( (unsigned __int64)v19 < v20 );
          `AkMath::FastPow10::`4::SCALE = LODWORD(v24);
          `AkMath::FastPow10::`4::`local static guard = v25;
        }
      }
      v12 = v64;
      v15 = FLOAT_1_0eN25;
      ++v16;
      ++v18;
      *((float *)&v5->m_pSideChain[v16] - 1) = v22;
      v5->m_pSideChain[v16 - 1].fGainDb = v23;
      --v17;
    }
    while ( v17 );
  }
}

// File Line: 230
// RVA: 0xAD0E10
void __fastcall CAkCompressorFX::ProcessLinked(CAkCompressorFX *this, AkAudioBuffer *io_pBufferIn, AkCompressorFXParams *in_pParams)
{
  CAkCompressorFX *v3; // rbp
  AkCompressorFXParams *v4; // rdi
  AkAudioBuffer *v5; // rsi
  signed int v6; // ebx
  float v7; // xmm7_4
  float v8; // xmm0_4
  signed int v9; // eax
  float v10; // xmm0_4
  float v11; // xmm9_4
  signed int v12; // eax
  float *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm6_4
  float v16; // xmm5_4
  float v17; // xmm3_4
  char *v18; // rcx
  __int64 *v19; // rax
  signed __int64 v20; // r8
  __int64 v21; // rdx
  int i; // er9
  unsigned int v23; // er8
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
  signed int v37; // ecx
  unsigned int v38; // er8
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
  __int64 v49; // [rsp+10h] [rbp-128h]
  __int64 v50; // [rsp+18h] [rbp-120h]
  __int64 v51; // [rsp+20h] [rbp-118h]
  __int64 v52; // [rsp+28h] [rbp-110h]
  __int64 v53[8]; // [rsp+30h] [rbp-108h]
  float v54; // [rsp+148h] [rbp+10h]
  float v55; // [rsp+158h] [rbp+20h]

  v3 = this;
  v4 = in_pParams;
  v5 = io_pBufferIn;
  if ( !(io_pBufferIn->uChannelMask & 8) || this->m_bProcessLFE )
    v6 = this->m_uNumChannels;
  else
    v6 = this->m_uNumChannels - 1;
  v7 = (float)(1.0 / in_pParams->fRatio) - 1.0;
  v55 = in_pParams->fThreshold;
  v8 = in_pParams->fAttack;
  if ( v8 != this->m_fCachedAttack )
  {
    v9 = this->m_uSampleRate;
    this->m_fCachedAttack = v8;
    this->m_fCachedAttackCoef = expf(-2.2 / (float)((float)v9 * in_pParams->fAttack));
  }
  v10 = v4->fRelease;
  v11 = v3->m_fCachedAttackCoef;
  if ( v10 != v3->m_fCachedRelease )
  {
    v12 = v3->m_uSampleRate;
    v3->m_fCachedRelease = v10;
    v3->m_fCachedReleaseCoef = expf(-2.2 / (float)((float)v12 * v4->fRelease));
  }
  v13 = (float *)v3->m_pSideChain;
  v14 = v3->m_fRMSFilterCoef;
  v15 = v3->m_fCachedReleaseCoef;
  v16 = v13[1];
  v17 = *v13;
  v54 = v3->m_fRMSFilterCoef;
  if ( v6 )
  {
    v18 = (char *)v5->pData;
    v19 = v53;
    v20 = 4i64 * v5->uMaxFrames;
    v21 = (unsigned int)v6;
    do
    {
      *v19 = (__int64)v18;
      v18 += v20;
      ++v19;
      --v21;
    }
    while ( v21 );
  }
  for ( i = v5->uValidFrames - 1; i >= 0; v14 = v54 )
  {
    v23 = 0;
    v24 = 0i64;
    v25 = 0.0;
    if ( v6 >= 4 )
    {
      v26 = ((unsigned int)(v6 - 4) >> 2) + 1;
      v27 = v26;
      v23 = 4 * v26;
      do
      {
        v28 = (float *)v53[v24];
        v24 += 4i64;
        v25 = (float)((float)((float)(v25 + (float)(*v28 * *v28))
                            + (float)(*(float *)*(&v50 + v24) * *(float *)*(&v50 + v24)))
                    + (float)(*(float *)*(&v51 + v24) * *(float *)*(&v51 + v24)))
            + (float)(*(float *)*(&v52 + v24) * *(float *)*(&v52 + v24));
        --v27;
      }
      while ( v27 );
      v14 = v54;
    }
    if ( v23 < v6 )
    {
      v29 = (float **)&v53[v24];
      v30 = v6 - v23;
      do
      {
        v31 = *v29;
        ++v29;
        v25 = v25 + (float)(*v31 * *v31);
        --v30;
      }
      while ( v30 );
    }
    v16 = (float)((float)(v16 - (float)((float)(v25 * (float)(1.0 / (float)v6)) + 1.0e-25)) * v14)
        + (float)((float)(v25 * (float)(1.0 / (float)v6)) + 1.0e-25);
    v32 = (float)(COERCE_FLOAT((LODWORD(v16) & 0x7FFFFF) + 1065353216) - 1.0)
        / (float)(COERCE_FLOAT((LODWORD(v16) & 0x7FFFFF) + 1065353216) + 1.0);
    v33 = (float)((float)((float)((float)((float)((float)((float)(v32 * v32) * 0.33333334) + 1.0) * (float)(v32 * 2.0))
                                + (float)((float)((float)(unsigned __int8)(LODWORD(v16) >> 23) - 127.0) * 0.69314718))
                        * 0.43429449)
                * 10.0)
        - v55;
    if ( v33 <= 0.0 )
      v33 = 0.0;
    if ( (float)(v33 - v17) < 0.0 )
      v34 = v15;
    else
      v34 = v11;
    v17 = (float)((float)(v17 - v33) * v34) + v33;
    v35 = (float)(v17 * v7) * 0.050000001;
    if ( v35 >= -37.0 )
    {
      if ( !(`AkMath::FastPow10::`4::`local static guard & 1) )
      {
        `AkMath::FastPow10::`4::`local static guard |= 1u;
        `AkMath::FastPow10::`4::SCALE = 1272224376;
      }
      v37 = (signed int)(float)((float)(v35 * *(float *)&`AkMath::FastPow10::`4::SCALE) + 1065353200.0);
      LODWORD(v51) = (v37 & 0x7FFFFF) + 1065353216;
      HIDWORD(v51) = v37 & 0xFF800000;
      v36 = (float)((float)((float)((float)(*(float *)&v51 * 0.32518977) + 0.020805772) * *(float *)&v51) + 0.65304345)
          * COERCE_FLOAT(v37 & 0xFF800000);
    }
    else
    {
      v36 = 0.0;
    }
    v38 = 0;
    v39 = 0i64;
    if ( v6 >= 4 )
    {
      v40 = ((unsigned int)(v6 - 4) >> 2) + 1;
      v41 = v40;
      v38 = 4 * v40;
      do
      {
        v42 = v53[v39];
        v39 += 4i64;
        v42 += 4i64;
        *(&v49 + v39) = v42;
        *(float *)(v42 - 4) = v36 * *(float *)(v42 - 4);
        v43 = *(&v50 + v39) + 4;
        *(&v50 + v39) = v43;
        *(float *)(v43 - 4) = v36 * *(float *)(v43 - 4);
        v44 = *(&v51 + v39) + 4;
        *(&v51 + v39) = v44;
        *(float *)(v44 - 4) = v36 * *(float *)(v44 - 4);
        v45 = *(&v52 + v39) + 4;
        *(&v52 + v39) = v45;
        *(float *)(v45 - 4) = v36 * *(float *)(v45 - 4);
        --v41;
      }
      while ( v41 );
    }
    if ( v38 < v6 )
    {
      v46 = &v53[v39];
      v47 = v6 - v38;
      do
      {
        v48 = *v46;
        ++v46;
        v48 += 4i64;
        *(v46 - 1) = v48;
        *(float *)(v48 - 4) = v36 * *(float *)(v48 - 4);
        --v47;
      }
      while ( v47 );
    }
    --i;
  }
  v3->m_pSideChain->fMem = v16;
  v3->m_pSideChain->fGainDb = v17;
}

