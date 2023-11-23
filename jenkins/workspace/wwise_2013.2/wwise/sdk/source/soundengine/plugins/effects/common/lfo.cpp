// File Line: 36
// RVA: 0xAF5020
void __fastcall DSP::LFO::MultiChannel::ComputeInitialPhase(
        unsigned int in_uChannelMask,
        DSP::LFO::MultiChannel::PhaseParams *in_phaseParams,
        float *out_uChannelPhase)
{
  unsigned int v3; // r15d
  unsigned int v6; // edi
  int i; // ebp
  DSP::LFO::MultiChannel::PhaseMode ePhaseMode; // ecx
  __int32 v9; // ecx
  __int32 v10; // ecx
  unsigned int v11; // ecx
  unsigned int j; // edi
  float *v13; // rdi
  __int64 v14; // r14
  unsigned int v15; // edx
  __int64 v16; // rax
  __int64 v17; // rdx
  int v18; // edx
  __int64 v19; // rdx
  int v20; // edx
  __int64 v21; // rax
  float *v22; // rcx
  unsigned int v23; // eax
  __int64 v24; // rdx
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float *v29; // rax
  __int64 v30; // rcx

  v3 = 0;
  v6 = in_uChannelMask;
  for ( i = 0; in_uChannelMask; in_uChannelMask &= in_uChannelMask - 1 )
    ++i;
  memset(out_uChannelPhase, 0, 4i64 * (unsigned int)i);
  ePhaseMode = in_phaseParams->ePhaseMode;
  if ( ePhaseMode )
  {
    v9 = ePhaseMode - 1;
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
            v13 = out_uChannelPhase + 1;
            v14 = v11 - 1;
            do
            {
              *v13++ = (float)((double)rand() * 0.00003051850947599719) * in_phaseParams->fPhaseSpread;
              --v14;
            }
            while ( v14 );
          }
        }
      }
      else if ( (v6 & 0x30) != 0 )
      {
        v15 = 2;
        out_uChannelPhase[1] = in_phaseParams->fPhaseSpread * 0.5;
        if ( (v6 & 4) != 0 )
        {
          v15 = 3;
          out_uChannelPhase[2] = in_phaseParams->fPhaseSpread * 0.25;
        }
        v16 = v15;
        v17 = v15 + 1;
        out_uChannelPhase[v16] = in_phaseParams->fPhaseSpread * 0.5;
        out_uChannelPhase[v17] = in_phaseParams->fPhaseSpread;
        if ( (v6 & 0x600) != 0 )
        {
          v18 = v17 + 1;
          out_uChannelPhase[v18] = in_phaseParams->fPhaseSpread * 0.25;
          out_uChannelPhase[v18 + 1] = (float)(in_phaseParams->fPhaseSpread * 3.0) * 0.25;
        }
      }
      else if ( (v6 & 3) != 0 )
      {
        out_uChannelPhase[1] = in_phaseParams->fPhaseSpread;
        if ( (v6 & 4) != 0 )
          out_uChannelPhase[2] = in_phaseParams->fPhaseSpread * 0.5;
      }
    }
    else if ( (v6 & 0x10) != 0 )
    {
      v19 = (v6 & 4 | 8) >> 2;
      out_uChannelPhase[v19] = in_phaseParams->fPhaseSpread;
      out_uChannelPhase[(unsigned int)(v19 + 1)] = in_phaseParams->fPhaseSpread;
      if ( (v6 & 0x200) != 0 )
      {
        out_uChannelPhase[(unsigned int)(v19 + 2)] = in_phaseParams->fPhaseSpread * 0.5;
        out_uChannelPhase[(unsigned int)(v19 + 3)] = in_phaseParams->fPhaseSpread * 0.5;
      }
    }
  }
  else
  {
    v20 = 0;
    if ( (v6 & 2) != 0 )
    {
      v20 = 2;
      out_uChannelPhase[1] = in_phaseParams->fPhaseSpread;
      if ( (v6 & 4) != 0 )
      {
        v20 = 3;
        out_uChannelPhase[2] = in_phaseParams->fPhaseSpread * 0.5;
      }
    }
    if ( (v6 & 0x10) != 0 )
    {
      out_uChannelPhase[v20] = 0.0;
      out_uChannelPhase[v20 + 1] = in_phaseParams->fPhaseSpread;
      if ( (v6 & 0x200) != 0 )
      {
        out_uChannelPhase[v20 + 2] = 0.0;
        out_uChannelPhase[v20 + 3] = in_phaseParams->fPhaseSpread;
      }
    }
  }
  v21 = 0i64;
  if ( i >= 4 )
  {
    v22 = out_uChannelPhase + 2;
    v23 = ((unsigned int)(i - 4) >> 2) + 1;
    v24 = v23;
    v3 = 4 * v23;
    v21 = 4i64 * v23;
    do
    {
      v25 = *(v22 - 2);
      v26 = *(v22 - 1);
      v22 += 4;
      *(v22 - 6) = v25 + in_phaseParams->fPhaseOffset;
      v27 = *(v22 - 4);
      *(v22 - 5) = v26 + in_phaseParams->fPhaseOffset;
      v28 = *(v22 - 3);
      *(v22 - 4) = v27 + in_phaseParams->fPhaseOffset;
      *(v22 - 3) = v28 + in_phaseParams->fPhaseOffset;
      --v24;
    }
    while ( v24 );
  }
  if ( v3 < i )
  {
    v29 = &out_uChannelPhase[v21];
    v30 = i - v3;
    do
    {
      ++v29;
      *(v29 - 1) = in_phaseParams->fPhaseOffset + *(v29 - 1);
      --v30;
    }
    while ( v30 );
  }
}

