// File Line: 24
// RVA: 0xAF58A0
float __fastcall AkMeterGetValue(AkAudioBuffer *in_pBuffer, AkMeterFXParams *in_pParams, float *in_pfInChannel)
{
  unsigned int v3; // er9
  __int64 v4; // rbp
  float *v5; // r15
  AkMeterFXParams *v6; // r12
  AkAudioBuffer *v7; // r14
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
  unsigned __int64 v18; // rdi
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm7_4
  float *v24; // rbx
  __int64 v25; // rsi
  __int64 v26; // r8
  float v27; // xmm6_4
  float *v28; // rcx
  unsigned __int64 v29; // rdi
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  __int64 v36; // rcx
  float *v37; // rdi
  float result; // xmm0_4

  v3 = in_pBuffer->uChannelMask;
  v4 = 0i64;
  v5 = in_pfInChannel;
  v6 = in_pParams;
  v7 = in_pBuffer;
  for ( i = 0; v3; v3 &= v3 - 1 )
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
          v26 = v7->uValidFrames;
          v27 = 0.0;
          v28 = (float *)((char *)v7->pData + 4 * v4 * v7->uMaxFrames);
          v29 = (unsigned __int64)&v28[v26];
          if ( (unsigned __int64)v28 < v29 )
          {
            if ( (4 * v26 + 3) / 4 >= 4 )
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
              while ( (signed __int64)v28 < (signed __int64)(v29 - 12) );
            }
            for ( ; (unsigned __int64)v28 < v29; v27 = v27 + (float)(v34 * v34) )
            {
              v34 = *v28;
              ++v28;
            }
          }
          v35 = v27 / (float)(signed int)v26;
          if ( v5 )
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
          v16 = (float *)((char *)v7->pData + 4 * v4 * v7->uMaxFrames);
          v17 = v7->uValidFrames;
          v18 = (unsigned __int64)&v16[v17];
          if ( (unsigned __int64)v16 < v18 )
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
              while ( (signed __int64)v16 < (signed __int64)(v18 - 12) );
            }
            for ( ; (unsigned __int64)v16 < v18; ++v16 )
            {
              if ( v14 >= *v16 )
                v14 = *v16;
              if ( v15 <= *v16 )
                v15 = *v16;
            }
          }
          if ( v5 )
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
      *v37 = -96.300003;
      ++v37;
      --v36;
    }
  }
  result = log10f(v9) * 20.0;
  if ( v6->RTPC.fMin > result )
    result = v6->RTPC.fMin;
  if ( v6->RTPC.fMax < result )
    result = v6->RTPC.fMax;
  return result;
}

// File Line: 106
// RVA: 0xAF5C70
void __fastcall AkMeterApplyBallistics(float in_fValue, unsigned int in_uElapsed, AkMeterFXParams *in_pParams, AkMeterState *in_pState)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  char *v8; // rcx
  int v9; // esi
  signed int v10; // edx
  signed __int64 v11; // r12
  signed __int64 v12; // rdi
  signed __int64 v13; // rbx
  signed __int64 v14; // r14
  signed __int64 v15; // r15
  unsigned __int64 v16; // rdx
  int v17; // eax
  signed __int64 v18; // rbx
  int *v19; // rcx
  char *v20; // rdx
  int v21; // eax
  signed __int64 v22; // rdx
  char *v23; // rcx
  unsigned __int64 v24; // r11
  signed __int64 v25; // r10
  char *v26; // rcx
  int v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4

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
      && in_fValue >= (float)((float)((float)((float)((float)(signed int)in_uElapsed
                                                    / (float)(signed int)in_pState->uSampleRate)
                                            / in_pParams->RTPC.fAttack)
                                    * 10.0)
                            + in_pState->fLastValue) )
    {
      v4 = (float)((float)((float)((float)(signed int)in_uElapsed / (float)(signed int)in_pState->uSampleRate)
                         / in_pParams->RTPC.fAttack)
                 * 10.0)
         + in_pState->fLastValue;
    }
    in_pState->fLastValue = v4;
    in_pState->fReleaseTarget = in_pState->fLastValue;
    return;
  }
  v5 = (float)(signed int)in_uElapsed / (float)(signed int)in_pState->uSampleRate;
  v6 = v5 + in_pState->fHoldTime;
  in_pState->fHoldTime = v6;
  v7 = in_pParams->RTPC.fHold;
  if ( v6 < v7 )
  {
    v27 = (signed int)(float)((float)((float)(v6 / v7) * 8.0) + 0.5) - 1;
    if ( v27 >= 0 && v4 > in_pState->fHoldMemory[v27] )
      in_pState->fHoldMemory[v27] = v4;
    if ( v4 <= in_pState->fReleaseTarget )
      goto LABEL_43;
  }
  else
  {
    v8 = (char *)in_pState->fHoldMemory;
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
    in_pState->fHoldTime = (float)(8 - v10) * (float)(v7 * 0.11111111);
    if ( v12 < 8 )
    {
      if ( 8 - v12 >= 4 )
      {
        v13 = 4 * v12;
        v14 = 4 * v12 + 8;
        v15 = 4 * v12 + 12;
        v16 = ((unsigned __int64)(4 - v12) >> 2) + 1;
        v11 = 4 * v16;
        v9 = 4 * v16;
        v12 += 4 * v16;
        do
        {
          v17 = *(_DWORD *)&v8[v13];
          v8 += 16;
          *((_DWORD *)v8 - 4) = v17;
          *((_DWORD *)v8 - 3) = *(_DWORD *)&v8[v13 - 12];
          *((_DWORD *)v8 - 2) = *(_DWORD *)&v8[v14 - 16];
          *((_DWORD *)v8 - 1) = *(_DWORD *)&v8[v15 - 16];
          --v16;
        }
        while ( v16 );
      }
      if ( v12 < 8 )
      {
        v18 = 8 - v12;
        v19 = (int *)&in_pState->fHoldMemory[v12];
        v20 = (char *)&in_pState->fHoldMemory[v11];
        v9 += 8 - v12;
        do
        {
          v21 = *v19;
          v20 += 4;
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
        v23 = (char *)&in_pState->fHoldMemory[v9 + 1];
        v24 = ((unsigned __int64)(4i64 - v9) >> 2) + 1;
        v22 = v9 + 4 * v24;
        do
        {
          v23 += 16;
          *((_DWORD *)v23 - 5) = LODWORD(in_pParams->RTPC.fMin);
          *((_DWORD *)v23 - 4) = LODWORD(in_pParams->RTPC.fMin);
          *((_DWORD *)v23 - 3) = LODWORD(in_pParams->RTPC.fMin);
          *((_DWORD *)v23 - 2) = LODWORD(in_pParams->RTPC.fMin);
          --v24;
        }
        while ( v24 );
      }
      if ( v22 < 8 )
      {
        v25 = 8 - v22;
        v26 = (char *)&in_pState->fHoldMemory[v22];
        do
        {
          v26 += 4;
          *((_DWORD *)v26 - 1) = LODWORD(in_pParams->RTPC.fMin);
          --v25;
        }
        while ( v25 );
      }
    }
  }
  in_pState->fReleaseTarget = v4;
LABEL_43:
  v28 = in_pParams->RTPC.fRelease;
  if ( v28 == 0.0 )
  {
    in_pState->fLastValue = in_pState->fReleaseTarget;
  }
  else
  {
    v29 = v5 / v28;
    v30 = in_pState->fReleaseTarget;
    if ( v30 <= (float)(in_pState->fLastValue - (float)(v29 * 10.0)) )
      v30 = in_pState->fLastValue - (float)(v29 * 10.0);
    in_pState->fLastValue = v30;
  }
}

