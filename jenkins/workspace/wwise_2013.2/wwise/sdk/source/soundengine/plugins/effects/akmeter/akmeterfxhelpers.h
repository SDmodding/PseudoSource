// File Line: 24
// RVA: 0xAF58A0
float __fastcall AkMeterGetValue(AkAudioBuffer *in_pBuffer, AkMeterFXParams *in_pParams, float *in_pfInChannel)
{
  unsigned int uChannelMask; // r9d
  __int64 v4; // rbp
  unsigned int i; // edi
  float v9; // xmm9_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  float *v12; // rbx
  __int64 v13; // rsi
  float v14; // xmm7_4
  float v15; // xmm6_4
  float *v16; // rcx
  __int64 v17; // rax
  float *v18; // rdi
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm7_4
  float *v24; // rbx
  __int64 v25; // rsi
  __int64 uValidFrames; // r8
  float v27; // xmm6_4
  float *v28; // rcx
  float *v29; // rdi
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  __int64 v36; // rcx
  float *v37; // rdi
  float result; // xmm0_4

  uChannelMask = in_pBuffer->uChannelMask;
  v4 = 0i64;
  for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
    ++i;
  v9 = 0.0;
  if ( in_pBuffer->uValidFrames )
  {
    if ( in_pParams->NonRTPC.eMode )
    {
      v23 = FLOAT_N2_1474836e9;
      if ( i )
      {
        v24 = in_pfInChannel;
        v25 = i;
        do
        {
          uValidFrames = in_pBuffer->uValidFrames;
          v27 = 0.0;
          v28 = (float *)((char *)in_pBuffer->pData + 4 * v4 * in_pBuffer->uMaxFrames);
          v29 = &v28[uValidFrames];
          if ( v28 < v29 )
          {
            if ( (4 * uValidFrames + 3) / 4 >= 4 )
            {
              do
              {
                v30 = v28[1] * v28[1];
                v31 = v28[2] * v28[2];
                v32 = v28[3];
                v33 = (float)(*v28 * *v28) + v27;
                v28 += 4;
                v27 = (float)((float)(v33 + v30) + v31) + (float)(v32 * v32);
              }
              while ( (__int64)v28 < (__int64)(v29 - 3) );
            }
            for ( ; v28 < v29; v27 = v27 + (float)(v34 * v34) )
              v34 = *v28++;
          }
          v35 = v27 / (float)(int)uValidFrames;
          if ( in_pfInChannel )
            *v24 = log10f(v35) * 10.0;
          if ( v23 <= v35 )
            v23 = v35;
          ++v4;
          ++v24;
          --v25;
        }
        while ( v25 );
      }
      v9 = fsqrt(v23);
    }
    else
    {
      v10 = FLOAT_2_1474836e9;
      v11 = FLOAT_N2_1474836e9;
      if ( i )
      {
        v12 = in_pfInChannel;
        v13 = i;
        do
        {
          v14 = FLOAT_2_1474836e9;
          v15 = FLOAT_N2_1474836e9;
          v16 = (float *)((char *)in_pBuffer->pData + 4 * v4 * in_pBuffer->uMaxFrames);
          v17 = in_pBuffer->uValidFrames;
          v18 = &v16[v17];
          if ( v16 < v18 )
          {
            if ( (4 * v17 + 3) / 4 >= 4 )
            {
              do
              {
                if ( v14 >= *v16 )
                  v14 = *v16;
                if ( v15 <= *v16 )
                  v15 = *v16;
                v19 = v16[1];
                if ( v14 >= v19 )
                  v14 = v16[1];
                if ( v15 <= v19 )
                  v15 = v16[1];
                v20 = v16[2];
                if ( v14 >= v20 )
                  v14 = v16[2];
                if ( v15 <= v20 )
                  v15 = v16[2];
                v21 = v16[3];
                if ( v14 >= v21 )
                  v14 = v16[3];
                if ( v15 <= v21 )
                  v15 = v16[3];
                v16 += 4;
              }
              while ( (__int64)v16 < (__int64)(v18 - 3) );
            }
            for ( ; v16 < v18; ++v16 )
            {
              if ( v14 >= *v16 )
                v14 = *v16;
              if ( v15 <= *v16 )
                v15 = *v16;
            }
          }
          if ( in_pfInChannel )
          {
            LODWORD(v22) = LODWORD(v14) & _xmm;
            if ( COERCE_FLOAT(LODWORD(v14) & _xmm) <= v15 )
              v22 = v15;
            *v12 = log10f(v22) * 20.0;
          }
          if ( v10 >= v14 )
            v10 = v14;
          if ( v11 <= v15 )
            v11 = v15;
          ++v4;
          ++v12;
          --v13;
        }
        while ( v13 );
      }
      LODWORD(v9) = LODWORD(v10) & _xmm;
      if ( v9 <= v11 )
        v9 = v11;
    }
  }
  else if ( in_pfInChannel && i )
  {
    v36 = i;
    v37 = in_pfInChannel;
    while ( v36 )
    {
      *v37++ = -96.300003;
      --v36;
    }
  }
  result = log10f(v9) * 20.0;
  if ( in_pParams->RTPC.fMin > result )
    result = in_pParams->RTPC.fMin;
  if ( in_pParams->RTPC.fMax < result )
    return in_pParams->RTPC.fMax;
  return result;
}

// File Line: 106
// RVA: 0xAF5C70
void __fastcall AkMeterApplyBallistics(
        float in_fValue,
        int in_uElapsed,
        AkMeterFXParams *in_pParams,
        AkMeterState *in_pState)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float fHold; // xmm3_4
  float *fHoldMemory; // rcx
  int v9; // esi
  int v10; // edx
  __int64 v11; // r12
  __int64 v12; // rdi
  __int64 v13; // rbx
  __int64 v14; // r14
  __int64 v15; // r15
  unsigned __int64 v16; // rdx
  float v17; // eax
  __int64 v18; // rbx
  float *v19; // rcx
  float *v20; // rdx
  int v21; // eax
  __int64 v22; // rdx
  float *v23; // rcx
  unsigned __int64 v24; // r11
  __int64 v25; // r10
  float *v26; // rcx
  int v27; // eax
  float fRelease; // xmm1_4
  float v29; // xmm2_4
  float fReleaseTarget; // xmm1_4

  v4 = in_fValue;
  if ( in_fValue > in_pState->fLastValue )
  {
    in_pState->fHoldTime = 0.0;
    in_pState->fHoldMemory[0] = in_pParams->RTPC.fMin;
    in_pState->fHoldMemory[1] = in_pParams->RTPC.fMin;
    in_pState->fHoldMemory[2] = in_pParams->RTPC.fMin;
    in_pState->fHoldMemory[3] = in_pParams->RTPC.fMin;
    in_pState->fHoldMemory[4] = in_pParams->RTPC.fMin;
    in_pState->fHoldMemory[5] = in_pParams->RTPC.fMin;
    in_pState->fHoldMemory[6] = in_pParams->RTPC.fMin;
    in_pState->fHoldMemory[7] = in_pParams->RTPC.fMin;
    if ( in_pParams->RTPC.fAttack != 0.0
      && in_fValue >= (float)((float)((float)((float)((float)in_uElapsed / (float)(int)in_pState->uSampleRate)
                                            / in_pParams->RTPC.fAttack)
                                    * 10.0)
                            + in_pState->fLastValue) )
    {
      v4 = (float)((float)((float)((float)in_uElapsed / (float)(int)in_pState->uSampleRate) / in_pParams->RTPC.fAttack)
                 * 10.0)
         + in_pState->fLastValue;
    }
    in_pState->fLastValue = v4;
    in_pState->fReleaseTarget = in_pState->fLastValue;
    return;
  }
  v5 = (float)in_uElapsed / (float)(int)in_pState->uSampleRate;
  v6 = v5 + in_pState->fHoldTime;
  in_pState->fHoldTime = v6;
  fHold = in_pParams->RTPC.fHold;
  if ( v6 < fHold )
  {
    v27 = (int)(float)((float)((float)(v6 / fHold) * 8.0) + 0.5) - 1;
    if ( v27 >= 0 && v4 > in_pState->fHoldMemory[v27] )
      in_pState->fHoldMemory[v27] = v4;
    if ( v4 <= in_pState->fReleaseTarget )
      goto LABEL_43;
  }
  else
  {
    fHoldMemory = in_pState->fHoldMemory;
    v9 = 0;
    v10 = 8;
    if ( in_pState->fHoldMemory[0] >= v4 )
    {
      v4 = in_pState->fHoldMemory[0];
      v10 = 0;
    }
    if ( in_pState->fHoldMemory[1] >= v4 )
    {
      v4 = in_pState->fHoldMemory[1];
      v10 = 1;
    }
    if ( in_pState->fHoldMemory[2] >= v4 )
    {
      v4 = in_pState->fHoldMemory[2];
      v10 = 2;
    }
    if ( in_pState->fHoldMemory[3] >= v4 )
    {
      v4 = in_pState->fHoldMemory[3];
      v10 = 3;
    }
    if ( in_pState->fHoldMemory[4] >= v4 )
    {
      v4 = in_pState->fHoldMemory[4];
      v10 = 4;
    }
    if ( in_pState->fHoldMemory[5] >= v4 )
    {
      v4 = in_pState->fHoldMemory[5];
      v10 = 5;
    }
    if ( in_pState->fHoldMemory[6] >= v4 )
    {
      v4 = in_pState->fHoldMemory[6];
      v10 = 6;
    }
    if ( in_pState->fHoldMemory[7] >= v4 )
    {
      v4 = in_pState->fHoldMemory[7];
      v10 = 7;
    }
    v11 = 0i64;
    v12 = v10 + 1;
    in_pState->fHoldTime = (float)(8 - v10) * (float)(fHold * 0.11111111);
    if ( v12 < 8 )
    {
      if ( 8 - v12 >= 4 )
      {
        v13 = v12;
        v14 = 4 * v12 + 8;
        v15 = 4 * v12 + 12;
        v16 = ((unsigned __int64)(4 - v12) >> 2) + 1;
        v11 = 4 * v16;
        v9 = 4 * v16;
        v12 += 4 * v16;
        do
        {
          v17 = fHoldMemory[v13];
          fHoldMemory += 4;
          *(fHoldMemory - 4) = v17;
          *(fHoldMemory - 3) = fHoldMemory[v13 - 3];
          *(fHoldMemory - 2) = *(float *)((char *)fHoldMemory + v14 - 16);
          *(fHoldMemory - 1) = *(float *)((char *)fHoldMemory + v15 - 16);
          --v16;
        }
        while ( v16 );
      }
      if ( v12 < 8 )
      {
        v18 = 8 - v12;
        v19 = &in_pState->fHoldMemory[v12];
        v20 = &in_pState->fHoldMemory[v11];
        v9 += 8 - v12;
        do
        {
          v21 = *(_DWORD *)v19;
          ++v20;
          ++v19;
          *((_DWORD *)v20 - 1) = v21;
          --v18;
        }
        while ( v18 );
      }
    }
    v22 = v9;
    if ( v9 < 8i64 )
    {
      if ( 8i64 - v9 >= 4 )
      {
        v23 = &in_pState->fHoldMemory[v9 + 1];
        v24 = ((unsigned __int64)(4i64 - v9) >> 2) + 1;
        v22 = v9 + 4 * v24;
        do
        {
          v23 += 4;
          *(v23 - 5) = in_pParams->RTPC.fMin;
          *(v23 - 4) = in_pParams->RTPC.fMin;
          *(v23 - 3) = in_pParams->RTPC.fMin;
          *(v23 - 2) = in_pParams->RTPC.fMin;
          --v24;
        }
        while ( v24 );
      }
      if ( v22 < 8 )
      {
        v25 = 8 - v22;
        v26 = &in_pState->fHoldMemory[v22];
        do
        {
          *v26++ = in_pParams->RTPC.fMin;
          --v25;
        }
        while ( v25 );
      }
    }
  }
  in_pState->fReleaseTarget = v4;
LABEL_43:
  fRelease = in_pParams->RTPC.fRelease;
  if ( fRelease == 0.0 )
  {
    in_pState->fLastValue = in_pState->fReleaseTarget;
  }
  else
  {
    v29 = v5 / fRelease;
    fReleaseTarget = in_pState->fReleaseTarget;
    if ( fReleaseTarget <= (float)(in_pState->fLastValue - (float)(v29 * 10.0)) )
      fReleaseTarget = in_pState->fLastValue - (float)(v29 * 10.0);
    in_pState->fLastValue = fReleaseTarget;
  }
}

