// File Line: 36
// RVA: 0xAF5020
void __fastcall DSP::LFO::MultiChannel::ComputeInitialPhase(unsigned int in_uChannelMask, DSP::LFO::MultiChannel::PhaseParams *in_phaseParams, float *out_uChannelPhase)
{
  unsigned int v3; // er15
  float *v4; // rsi
  DSP::LFO::MultiChannel::PhaseParams *v5; // rbx
  unsigned int v6; // edi
  unsigned int i; // ebp
  DSP::LFO::MultiChannel::PhaseMode v8; // ecx
  int v9; // ecx
  int v10; // ecx
  unsigned int v11; // ecx
  unsigned int j; // edi
  signed __int64 v13; // rdi
  __int64 v14; // r14
  unsigned int v15; // edx
  __int64 v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rdx
  __int64 v19; // rdx
  unsigned int v20; // edx
  signed __int64 v21; // rax
  signed __int64 v22; // rcx
  unsigned int v23; // eax
  __int64 v24; // rdx
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  signed __int64 v29; // rax
  __int64 v30; // rcx

  v3 = 0;
  v4 = out_uChannelPhase;
  v5 = in_phaseParams;
  v6 = in_uChannelMask;
  for ( i = 0; in_uChannelMask; in_uChannelMask &= in_uChannelMask - 1 )
    ++i;
  memset(out_uChannelPhase, 0, 4i64 * i);
  v8 = v5->ePhaseMode;
  if ( v8 )
  {
    v9 = v8 - 1;
    if ( v9 )
    {
      v10 = v9 - 1;
      if ( v10 )
      {
        if ( v10 == 1 )
        {
          v11 = 0;
          for ( j = v6 & 0xFFFFFFF7; j; j &= j - 1 )
            ++v11;
          if ( v11 > 1 )
          {
            v13 = (signed __int64)(v4 + 1);
            v14 = v11 - 1;
            do
            {
              v13 += 4i64;
              *(float *)(v13 - 4) = (float)((double)rand() * 0.00003051850947599719) * v5->fPhaseSpread;
              --v14;
            }
            while ( v14 );
          }
        }
      }
      else if ( v6 & 0x30 )
      {
        v15 = 2;
        v4[1] = v5->fPhaseSpread * 0.5;
        if ( v6 & 4 )
        {
          v15 = 3;
          v4[2] = v5->fPhaseSpread * 0.25;
        }
        v16 = v15;
        v17 = v15 + 1;
        v4[v16] = v5->fPhaseSpread * 0.5;
        v4[v17] = v5->fPhaseSpread;
        if ( v6 & 0x600 )
        {
          v18 = (unsigned int)(v17 + 1);
          v4[v18] = v5->fPhaseSpread * 0.25;
          v4[v18] = (float)(v5->fPhaseSpread * 3.0) * 0.25;
        }
      }
      else if ( v6 & 3 )
      {
        v4[1] = v5->fPhaseSpread;
        if ( v6 & 4 )
          v4[2] = v5->fPhaseSpread * 0.5;
      }
    }
    else if ( v6 & 0x10 )
    {
      v19 = (v6 & 4 | 8) >> 2;
      v4[v19] = v5->fPhaseSpread;
      v4[(unsigned int)(v19 + 1)] = v5->fPhaseSpread;
      if ( _bittest((const signed int *)&v6, 9u) )
      {
        v4[(unsigned int)(v19 + 2)] = v5->fPhaseSpread * 0.5;
        v4[(unsigned int)(v19 + 3)] = v5->fPhaseSpread * 0.5;
      }
    }
  }
  else
  {
    v20 = 0;
    if ( v6 & 2 )
    {
      v20 = 2;
      v4[1] = v5->fPhaseSpread;
      if ( v6 & 4 )
      {
        v20 = 3;
        v4[2] = v5->fPhaseSpread * 0.5;
      }
    }
    if ( v6 & 0x10 )
    {
      v4[v20] = 0.0;
      v4[v20 + 1] = v5->fPhaseSpread;
      if ( _bittest((const signed int *)&v6, 9u) )
      {
        v4[v20 + 2] = 0.0;
        v4[v20 + 3] = v5->fPhaseSpread;
      }
    }
  }
  v21 = 0i64;
  if ( (signed int)i >= 4 )
  {
    v22 = (signed __int64)(v4 + 2);
    v23 = ((i - 4) >> 2) + 1;
    v24 = v23;
    v3 = 4 * v23;
    v21 = 4i64 * v23;
    do
    {
      v25 = *(float *)(v22 - 8);
      v26 = *(float *)(v22 - 4);
      v22 += 16i64;
      *(float *)(v22 - 24) = v25 + v5->fPhaseOffset;
      v27 = *(float *)(v22 - 16);
      *(float *)(v22 - 20) = v26 + v5->fPhaseOffset;
      v28 = *(float *)(v22 - 12);
      *(float *)(v22 - 16) = v27 + v5->fPhaseOffset;
      *(float *)(v22 - 12) = v28 + v5->fPhaseOffset;
      --v24;
    }
    while ( v24 );
  }
  if ( v3 < i )
  {
    v29 = (signed __int64)&v4[v21];
    v30 = i - v3;
    do
    {
      v29 += 4i64;
      *(float *)(v29 - 4) = v5->fPhaseOffset + *(float *)(v29 - 4);
      --v30;
    }
    while ( v30 );
  }
}0 = i - v3;
    do
    {
      v29 += 4i64;
      *(float *)(v29 - 4) = v5->fPhaseOffset + *(float *)(v29 - 4);
      --v30;
    }
    

