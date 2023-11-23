// File Line: 35
// RVA: 0xACEDB0
void __fastcall Process(
        AkAudioBuffer *io_pBuffer,
        float *in_pfCoefs,
        float *io_pfMems,
        unsigned int in_uNumProcessedChannels)
{
  float v4; // xmm7_4
  float v5; // xmm8_4
  float v9; // xmm9_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  int v12; // r9d
  float *v13; // r10
  __int64 v14; // rsi
  __int64 v15; // rdi
  float v16; // xmm5_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  float *v20; // r8
  __int64 uValidFrames; // rax
  float *v22; // rcx
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm2_4
  float v31; // xmm5_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm2_4
  float v36; // xmm2_4
  float v37; // xmm2_4
  __int64 v38; // rax

  v4 = *in_pfCoefs;
  v5 = in_pfCoefs[1];
  v9 = in_pfCoefs[2];
  v10 = in_pfCoefs[3];
  v11 = in_pfCoefs[4];
  if ( in_uNumProcessedChannels )
  {
    v12 = 0;
    v13 = io_pfMems + 2;
    v14 = in_uNumProcessedChannels;
    v15 = 0i64;
    do
    {
      v16 = *(v13 - 2);
      v17 = *(v13 - 1);
      v18 = *v13;
      v19 = v13[1];
      v20 = (float *)((char *)io_pBuffer->pData + 4 * v15 * io_pBuffer->uMaxFrames);
      uValidFrames = io_pBuffer->uValidFrames;
      v22 = &v20[uValidFrames];
      if ( v20 < v22 )
      {
        if ( (4 * uValidFrames + 3) / 4 >= 4 )
        {
          do
          {
            v23 = *v20;
            v24 = v18;
            v20 += 4;
            v25 = (float)((float)((float)(v17 * v9) + (float)(v23 * v4)) + (float)(v16 * v5)) + (float)(v19 * v11);
            v26 = v23;
            v27 = v25 + (float)(v18 * v10);
            v28 = *(v20 - 3);
            *(v20 - 4) = v27;
            v29 = (float)((float)(v16 * v9) + (float)(v28 * v4)) + (float)(v23 * v5);
            v30 = v27 * v11;
            v31 = (float)(v29 + (float)(v24 * v11)) + (float)(v27 * v10);
            v17 = *(v20 - 2);
            *(v20 - 3) = v31;
            v32 = v31 * v11;
            v19 = (float)((float)((float)((float)(v26 * v9) + (float)(v17 * v4)) + (float)(v28 * v5)) + v30)
                + (float)(v31 * v10);
            v16 = *(v20 - 1);
            *(v20 - 2) = v19;
            v18 = (float)((float)((float)((float)(v28 * v9) + (float)(v16 * v4)) + (float)(v17 * v5)) + v32)
                + (float)(v19 * v10);
            *(v20 - 1) = v18;
          }
          while ( (__int64)v20 < (__int64)(v22 - 3) );
        }
        for ( ; v20 < v22; v18 = v37 )
        {
          v33 = *v20++;
          v34 = (float)(v17 * v9) + (float)(v33 * v4);
          v17 = v16;
          v35 = v34 + (float)(v16 * v5);
          v16 = v33;
          v36 = v35 + (float)(v19 * v11);
          v19 = v18;
          v37 = v36 + (float)(v18 * v10);
          *(v20 - 1) = v37;
        }
      }
      ++v15;
      v13 += 4;
      io_pfMems[v12] = v16;
      io_pfMems[v12 + 1] = v17;
      io_pfMems[v12 + 2] = v18;
      v38 = (unsigned int)(v12 + 3);
      v12 += 4;
      io_pfMems[v38] = v19;
      --v14;
    }
    while ( v14 );
  }
}

