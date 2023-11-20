// File Line: 42
// RVA: 0xAE7380
signed __int64 __fastcall DSP::ERUnitDual::Init(DSP::ERUnitDual *this, AK::IAkPluginMemAlloc *in_pAllocator, float in_fRoomSizeScale, AkRoomVerb::TapInfo *in_pTapInfoLeft, AkRoomVerb::TapInfo *in_pTapInfoRight, unsigned int in_uNumTapsL, unsigned int in_uNumTapsR, unsigned int in_uSampleRate)
{
  AkRoomVerb::TapInfo *v8; // rsi
  AK::IAkPluginMemAlloc *v9; // rdi
  DSP::ERUnitDual *v10; // rbx
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm8_4
  unsigned int v17; // eax
  __int64 v18; // rdx
  __int64 v19; // rax
  signed int v21; // edi
  unsigned __int16 v22; // r8
  unsigned __int16 v23; // r11
  unsigned __int16 v24; // r9
  signed int v25; // edx
  unsigned int v26; // eax
  unsigned int v27; // ecx
  unsigned __int16 v28; // r11
  unsigned __int16 v29; // r8
  unsigned __int16 v30; // r9
  unsigned int v31; // eax
  unsigned int v32; // ecx

  v8 = in_pTapInfoLeft;
  v9 = in_pAllocator;
  v10 = this;
  if ( in_uNumTapsL - 1 > 0x3F || in_uNumTapsR - 1 > 0x3F )
    return 2i64;
  v11 = powf(2.0, in_fRoomSizeScale * 0.0099999998);
  v12 = v8->fTapTime;
  v13 = v11;
  if ( v8->fTapTime >= in_pTapInfoRight->fTapTime )
    v12 = in_pTapInfoRight->fTapTime;
  v14 = v12 * v11;
  v15 = v8[in_uNumTapsL - 1].fTapTime;
  if ( v15 <= in_pTapInfoRight[in_uNumTapsR - 1].fTapTime )
    v15 = in_pTapInfoRight[in_uNumTapsR - 1].fTapTime;
  v16 = (float)(signed int)in_uSampleRate;
  v17 = (signed int)(float)((float)((float)((float)(v15 * v13) - v14) * 0.001) * (float)(signed int)in_uSampleRate);
  if ( v17 >= 4 )
  {
    if ( v17 > 0xFFFF )
      return 2i64;
  }
  else
  {
    LOWORD(v17) = 4;
  }
  v18 = (unsigned __int16)v17 & 0xFFFC;
  v10->uDelayLineLength = v18;
  v19 = (__int64)v9->vfptr->Malloc(v9, 4 * v18);
  v10->pfDelay = (float *)v19;
  if ( !v19 )
    return 52i64;
  v21 = -1;
  v22 = 0;
  v23 = 0;
  v10->uIndexToNextWrappingTapL = 0;
  v24 = 0;
  v25 = -1;
  if ( in_uNumTapsL )
  {
    do
    {
      v26 = v10->uDelayLineLength;
      v27 = (signed int)(float)((float)((float)((float)(v13 * v8[v24].fTapTime) - v14) * 0.001) * v16) & 0xFFFFFFFC;
      if ( v27 >= v10->uDelayLineLength )
        v27 = v26 - 4;
      if ( v27 != v25 )
      {
        v10->uTapOffsetsL[v22] = v26 - v27;
        if ( !v27 )
          v10->uTapOffsetsL[v22] = 0;
        v10->fTapGainsL[v22] = v8[v24].fTapGain;
        if ( v10->uTapOffsetsL[v22] > v23 )
        {
          v23 = v10->uTapOffsetsL[v22];
          v10->uIndexToNextWrappingTapL = v22;
        }
        ++v22;
      }
      ++v24;
      v25 = v27;
    }
    while ( v24 < in_uNumTapsL );
  }
  v10->uNumTapsL = v22;
  v28 = 0;
  v10->uIndexToNextWrappingTapR = 0;
  v29 = 0;
  v30 = 0;
  if ( in_uNumTapsR )
  {
    do
    {
      v31 = v10->uDelayLineLength;
      v32 = (signed int)(float)((float)((float)((float)(v13 * in_pTapInfoRight[v30].fTapTime) - v14) * 0.001) * v16) & 0xFFFFFFFC;
      if ( v32 >= v10->uDelayLineLength )
        v32 = v31 - 4;
      if ( v32 != v21 )
      {
        v10->uTapOffsetsR[v29] = v31 - v32;
        if ( !v32 )
          v10->uTapOffsetsR[v29] = 0;
        v10->fTapGainsR[v29] = in_pTapInfoRight[v30].fTapGain;
        if ( v10->uTapOffsetsR[v29] > v28 )
        {
          v28 = v10->uTapOffsetsR[v29];
          v10->uIndexToNextWrappingTapR = v29;
        }
        ++v29;
      }
      ++v30;
      v21 = v32;
    }
    while ( v30 < in_uNumTapsR );
  }
  v10->uWriteOffset = 0;
  v10->uNumTapsR = v29;
  return 1i64;
}

// File Line: 136
// RVA: 0xAE7670
void __fastcall DSP::ERUnitDual::Term(DSP::ERUnitDual *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::ERUnitDual *v2; // rbx

  v2 = this;
  if ( this->pfDelay )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v2->pfDelay = 0i64;
    v2->uDelayLineLength = 0;
  }
  else
  {
    this->uDelayLineLength = 0;
  }
}

// File Line: 146
// RVA: 0xAE76B0
void __fastcall DSP::ERUnitDual::Reset(DSP::ERUnitDual *this)
{
  if ( this->pfDelay )
    memset(this->pfDelay, 0, 4i64 * this->uDelayLineLength);
}

// File Line: 331
// RVA: 0xAE76E0
void __fastcall DSP::ERUnitDual::ProcessBuffer(DSP::ERUnitDual *this, float *in_pfInput, float *out_pfEROutputL, float *out_pfEROutputR, unsigned int in_uNumFrames)
{
  unsigned __int16 v5; // r10
  unsigned int v6; // ebp
  float *v7; // r14
  float *v8; // r11
  float *v9; // rbx
  float *v10; // rdi
  int v11; // esi
  unsigned int v12; // er10
  unsigned __int64 v13; // r9
  __int64 v14; // rax
  __int128 v15; // xmm0
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  unsigned int v18; // ebp
  unsigned __int16 *v19; // r15
  unsigned int *v20; // r12
  unsigned int v21; // eax
  __int64 v22; // r13
  __int64 v23; // rdx
  __int64 v24; // r8
  __int64 v25; // r9
  __int64 v26; // r10
  __int64 v27; // r11
  __int64 v28; // rbx
  __int64 v29; // rdi
  __int64 v30; // rsi
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  unsigned int i; // er8
  __int64 v40; // rax
  __int64 v41; // rdx
  __m128 v42; // xmm0
  __m128 v43; // xmm1
  __int64 v44; // rax
  __int64 v45; // rdx
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  char *v48; // rdx
  char *v49; // rdx
  unsigned int v50; // [rsp+0h] [rbp-58h]
  unsigned __int64 v51; // [rsp+8h] [rbp-50h]
  int v52; // [rsp+60h] [rbp+8h]
  float *v53; // [rsp+68h] [rbp+10h]
  float *v54; // [rsp+70h] [rbp+18h]
  float *v55; // [rsp+78h] [rbp+20h]

  v55 = out_pfEROutputR;
  v54 = out_pfEROutputL;
  v5 = this->uNumTapsR;
  v6 = in_uNumFrames;
  v7 = this->pfDelay;
  v8 = out_pfEROutputR;
  if ( this->uNumTapsL < v5 )
    v5 = this->uNumTapsL;
  v9 = out_pfEROutputL;
  v10 = in_pfInput;
  v11 = v5 & 0xFFFC;
  v52 = v5 & 0xFFFC;
  if ( in_uNumFrames )
  {
    do
    {
      v12 = this->uDelayLineLength - this->uTapOffsetsR[this->uIndexToNextWrappingTapR];
      if ( this->uDelayLineLength - this->uTapOffsetsL[this->uIndexToNextWrappingTapL] < v12 )
        v12 = this->uDelayLineLength - this->uTapOffsetsL[this->uIndexToNextWrappingTapL];
      if ( this->uDelayLineLength - this->uWriteOffset < v12 )
        v12 = this->uDelayLineLength - this->uWriteOffset;
      if ( v6 < v12 )
        v12 = v6;
      v50 = v12;
      if ( v12 >= 4 )
      {
        v13 = (unsigned __int64)v12 >> 2;
        v51 = (unsigned __int64)v12 >> 2;
        do
        {
          v14 = this->uWriteOffset;
          v15 = *(_OWORD *)v10;
          v10 += 4;
          v16 = 0i64;
          v17 = 0i64;
          v18 = 0;
          v53 = v10;
          *(_OWORD *)&v7[v14] = v15;
          this->uWriteOffset = v14 + 4;
          if ( v11 )
          {
            v19 = &this->uTapOffsetsL[2];
            v20 = (unsigned int *)&this->fTapGainsL[2];
            v21 = ((unsigned int)(v11 - 1) >> 2) + 1;
            v22 = v21;
            v18 = 4 * v21;
            do
            {
              v23 = *(v19 - 2);
              v24 = *(v19 - 1);
              v25 = *v19;
              v26 = v19[1];
              v27 = v19[62];
              v28 = v19[63];
              v29 = v19[64];
              v30 = v19[65];
              v31 = _mm_add_ps(
                      _mm_add_ps(
                        v16,
                        _mm_mul_ps(*(__m128 *)&v7[v23], _mm_shuffle_ps((__m128)*(v20 - 2), (__m128)*(v20 - 2), 0))),
                      _mm_mul_ps(*(__m128 *)&v7[v24], _mm_shuffle_ps((__m128)*(v20 - 1), (__m128)*(v20 - 1), 0)));
              v32 = _mm_mul_ps(*(__m128 *)&v7[v25], _mm_shuffle_ps((__m128)*v20, (__m128)*v20, 0));
              v33 = _mm_shuffle_ps((__m128)v20[1], (__m128)v20[1], 0);
              v20 += 4;
              v19 += 4;
              v16 = _mm_add_ps(_mm_add_ps(v31, v32), _mm_mul_ps(*(__m128 *)&v7[v26], v33));
              v34 = _mm_add_ps(
                      _mm_add_ps(
                        v17,
                        _mm_mul_ps(*(__m128 *)&v7[v27], _mm_shuffle_ps((__m128)v20[58], (__m128)v20[58], 0))),
                      _mm_mul_ps(*(__m128 *)&v7[v28], _mm_shuffle_ps((__m128)v20[59], (__m128)v20[59], 0)));
              v35 = _mm_mul_ps(*(__m128 *)&v7[v29], _mm_shuffle_ps((__m128)v20[60], (__m128)v20[60], 0));
              v36 = (__m128)v20[61];
              *(v19 - 6) = v23 + 4;
              *(v19 - 5) = v24 + 4;
              *(v19 - 4) = v25 + 4;
              *(v19 - 3) = v26 + 4;
              v19[58] = v27 + 4;
              v19[59] = v28 + 4;
              v37 = _mm_add_ps(v34, v35);
              v38 = _mm_mul_ps(*(__m128 *)&v7[v30], _mm_shuffle_ps(v36, v36, 0));
              v19[60] = v29 + 4;
              v17 = _mm_add_ps(v37, v38);
              v19[61] = v30 + 4;
              --v22;
            }
            while ( v22 );
            v8 = v55;
            v9 = v54;
            v10 = v53;
            v13 = v51;
            v11 = v52;
          }
          for ( i = v18; i < this->uNumTapsL; v16 = _mm_add_ps(v16, _mm_mul_ps(v43, _mm_shuffle_ps(v42, v42, 0))) )
          {
            v40 = i++;
            v41 = this->uTapOffsetsL[v40];
            v42 = (__m128)LODWORD(this->fTapGainsL[v40]);
            v43 = *(__m128 *)&v7[v41];
            this->uTapOffsetsL[v40] = v41 + 4;
          }
          for ( ; v18 < this->uNumTapsR; v17 = _mm_add_ps(v17, _mm_mul_ps(v47, _mm_shuffle_ps(v46, v46, 0))) )
          {
            v44 = v18++;
            v45 = this->uTapOffsetsR[v44];
            v46 = (__m128)LODWORD(this->fTapGainsR[v44]);
            v47 = *(__m128 *)&v7[v45];
            this->uTapOffsetsR[v44] = v45 + 4;
          }
          *(__m128 *)v9 = v16;
          v9 += 4;
          *(__m128 *)v8 = v17;
          v8 += 4;
          --v13;
          v54 = v9;
          v51 = v13;
          v55 = v8;
        }
        while ( v13 );
        v12 = v50;
        v6 = in_uNumFrames;
      }
      v48 = (char *)this + 2 * this->uIndexToNextWrappingTapL;
      if ( *((unsigned __int16 *)v48 + 266) == this->uDelayLineLength )
      {
        *((_WORD *)v48 + 266) = 0;
        this->uIndexToNextWrappingTapL = (unsigned __int16)(this->uIndexToNextWrappingTapL + 1)
                                       % (signed int)this->uNumTapsL;
      }
      v49 = (char *)this + 2 * this->uIndexToNextWrappingTapR;
      if ( *((unsigned __int16 *)v49 + 330) == this->uDelayLineLength )
      {
        *((_WORD *)v49 + 330) = 0;
        this->uIndexToNextWrappingTapR = (unsigned __int16)(this->uIndexToNextWrappingTapR + 1)
                                       % (signed int)this->uNumTapsR;
      }
      if ( this->uWriteOffset == this->uDelayLineLength )
        this->uWriteOffset = 0;
      v6 -= v12;
      in_uNumFrames = v6;
    }
    while ( v6 );
  }
}

