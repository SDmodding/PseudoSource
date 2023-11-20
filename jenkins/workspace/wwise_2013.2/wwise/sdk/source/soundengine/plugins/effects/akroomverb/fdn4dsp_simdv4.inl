// File Line: 433
// RVA: 0xAE8480
void __fastcall DSP::FDN4::ProcessBufferAccum(DSP::FDN4 *this, float *in_pfInBuffer, float *io_pfOutBuffer, unsigned int in_uNumFrames)
{
  unsigned int v4; // ebx
  float *v5; // r11
  __m128 v6; // ST10_16
  __m128 v7; // xmm7
  __m128 v8; // xmm8
  unsigned int v9; // edx
  unsigned int v10; // er9
  __int64 v11; // rdi
  __m128 v12; // xmm1
  __m128 v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm3
  __m128 v27; // xmm5
  __m128 v28; // xmm4
  __m128 v29; // xmm6
  __m128 v30; // xmm1
  unsigned int v31; // er9
  __int64 v32; // r9
  __m128 v33; // ST10_16
  __m128 v34; // xmm1
  __m128 v35; // xmm1
  __m128 v36; // xmm1
  __m128 v37; // xmm1
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm2
  __m128 v41; // [rsp+0h] [rbp-80h]
  __m128 v42; // [rsp+20h] [rbp-60h]

  v4 = in_uNumFrames;
  v5 = in_pfInBuffer;
  v41.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fFFbk1);
  v41.m128_i32[1] = LODWORD(this->delayLowPassFilter[1].fFFbk1);
  v41.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fFFbk1);
  v6.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fB0);
  v41.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fFFbk1);
  v7 = v41;
  v6.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fB0);
  v42.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fA1) ^ _xmm[0];
  v6.m128_i32[1] = LODWORD(this->delayLowPassFilter[1].fB0);
  v42.m128_i32[1] = LODWORD(this->delayLowPassFilter[1].fA1) ^ _xmm[0];
  v6.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fB0);
  v42.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fA1) ^ _xmm[0];
  v8 = v6;
  v42.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fA1) ^ _xmm[0];
  do
  {
    v9 = v4;
    if ( v4 >= this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset )
      v9 = this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset;
    if ( v9 >= this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset )
      v9 = this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset;
    if ( v9 >= this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset )
      v9 = this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset;
    if ( v9 >= this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset )
      v9 = this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset;
    v10 = v9 >> 2;
    if ( v9 >> 2 )
    {
      v11 = v10;
      do
      {
        io_pfOutBuffer += 4;
        v5 += 4;
        v12 = *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset];
        v13 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset], v12, 68);
        v14 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset], v12, 238);
        v15 = *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset];
        v16 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v15, 68);
        v17 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v15, 238);
        v18 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v16, 136), v8), _mm_mul_ps(v42, v7));
        v19 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v16, 221), v8), _mm_mul_ps(v18, v42));
        v20 = _mm_shuffle_ps(v18, v19, 238);
        v21 = _mm_shuffle_ps(v18, v19, 68);
        v22 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v17, 136), v8), _mm_mul_ps(v19, v42));
        v7 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v17, 221), v8), _mm_mul_ps(v22, v42));
        v23 = v22;
        v24 = _mm_shuffle_ps(v22, v7, 238);
        v25 = _mm_shuffle_ps(v23, v7, 68);
        v26 = _mm_shuffle_ps(v20, v24, 136);
        v27 = _mm_shuffle_ps(v21, v25, 136);
        v28 = _mm_shuffle_ps(v21, v25, 221);
        v29 = _mm_shuffle_ps(v20, v24, 221);
        *((__m128 *)io_pfOutBuffer - 1) = _mm_sub_ps(
                                            _mm_add_ps(_mm_add_ps(v27, v26), *(__m128 *)((char *)io_pfOutBuffer - 16)),
                                            _mm_add_ps(v28, v29));
        v30 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(_mm_add_ps(_mm_add_ps(v27, v28), v26), v29),
                  (__m128)_xmm_bf000000bf000000bf000000bf000000),
                *(__m128 *)((char *)v5 - 16));
        *(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset] = _mm_add_ps(v30, v28);
        this->FDNDelayLine[0].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset] = _mm_add_ps(v30, v26);
        this->FDNDelayLine[1].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset] = _mm_add_ps(v30, v29);
        this->FDNDelayLine[2].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset] = _mm_add_ps(v30, v27);
        this->FDNDelayLine[3].uCurOffset += 4;
        --v11;
      }
      while ( v11 );
      v41 = v7;
    }
    v31 = 4 * v10;
    if ( v31 < v9 )
    {
      v32 = v9 - v31;
      do
      {
        ++io_pfOutBuffer;
        ++v5;
        v33.m128_i32[0] = LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset]);
        v33.m128_i32[1] = LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset]);
        v33.m128_i32[2] = LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset]);
        v33.m128_i32[3] = LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset]);
        v7 = _mm_add_ps(_mm_mul_ps(v33, v8), _mm_mul_ps(v42, v7));
        v34 = _mm_mul_ps(_xmm_bf8000003f800000bf8000003f800000, v7);
        v35 = _mm_add_ps(v34, _mm_movehl_ps(v34, v34));
        *(io_pfOutBuffer - 1) = (float)(v35.m128_f32[0] + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 85)))
                              + *(io_pfOutBuffer - 1);
        v36 = _mm_mul_ps((__m128)_xmm_bf000000bf000000bf000000bf000000, v7);
        v37 = _mm_add_ps(v36, _mm_movehl_ps(v36, v36));
        v38 = _mm_add_ps(v37, _mm_shuffle_ps(v37, v37, 85));
        v39 = _mm_add_ps(v7, _mm_shuffle_ps(v38, v38, 0));
        v40 = _mm_add_ps(
                _mm_shuffle_ps(v39, v39, 57),
                _mm_shuffle_ps((__m128)*((unsigned int *)v5 - 1), (__m128)*((unsigned int *)v5 - 1), 0));
        LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset++]) = v40.m128_i32[0];
        LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset++]) = (unsigned __int128)_mm_shuffle_ps(v40, v40, 85);
        LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset++]) = (unsigned __int128)_mm_shuffle_ps(v40, v40, 170);
        LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset++]) = (unsigned __int128)_mm_shuffle_ps(v40, v40, 255);
        --v32;
      }
      while ( v32 );
      v41 = v7;
    }
    if ( this->FDNDelayLine[0].uCurOffset == this->FDNDelayLine[0].uDelayLineLength )
      this->FDNDelayLine[0].uCurOffset = 0;
    if ( this->FDNDelayLine[1].uCurOffset == this->FDNDelayLine[1].uDelayLineLength )
      this->FDNDelayLine[1].uCurOffset = 0;
    if ( this->FDNDelayLine[2].uCurOffset == this->FDNDelayLine[2].uDelayLineLength )
      this->FDNDelayLine[2].uCurOffset = 0;
    if ( this->FDNDelayLine[3].uCurOffset == this->FDNDelayLine[3].uDelayLineLength )
      this->FDNDelayLine[3].uCurOffset = 0;
    v4 -= v9;
  }
  while ( v4 );
  LODWORD(this->delayLowPassFilter[0].fFFbk1) = v41.m128_i32[0];
  this->delayLowPassFilter[1].fFFbk1 = v41.m128_f32[1];
  this->delayLowPassFilter[2].fFFbk1 = v41.m128_f32[2];
  this->delayLowPassFilter[3].fFFbk1 = v41.m128_f32[3];
}.m128_f32[2];
  this->delayLowPassFilter[3].fFFbk1 = v41.m128_f32[3];
}

// File Line: 444
// RVA: 0xAE8920
void __fastcall DSP::FDN4::ProcessBufferAccum(DSP::FDN4 *this, float *in_pfInBuffer, float *io_pfOutBuffer1, float *io_pfOutBuffer2)
{
  unsigned int v4; // edi
  __m128i v5; // ST20_16
  float *v6; // rbx
  float v7; // xmm1_4
  __int64 v8; // r8
  __int64 v9; // r9
  __m128 v10; // ST10_16
  __m128 v11; // xmm8
  __m128 v12; // xmm9
  unsigned int v13; // edx
  unsigned int v14; // er11
  __int64 v15; // rsi
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm7
  __m128 v25; // xmm4
  __m128 v26; // xmm5
  __m128 v27; // xmm7
  __m128 v28; // xmm1
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  __m128 v31; // xmm6
  __m128 v32; // xmm4
  __m128 v33; // xmm5
  __m128 v34; // xmm3
  __m128 v35; // xmm7
  __m128 v36; // xmm3
  unsigned int v37; // er11
  __int64 v38; // r11
  __m128 v39; // ST10_16
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm1
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm2
  __m128 v49; // [rsp+0h] [rbp-51h]
  __m128 v50; // [rsp+20h] [rbp-31h]
  __int128 v51; // [rsp+30h] [rbp-21h]
  unsigned int v52; // [rsp+D0h] [rbp+7Fh]

  v4 = v52;
  v5.m128i_i64[0] = (__int64)io_pfOutBuffer1;
  v5.m128i_i64[1] = (__int64)io_pfOutBuffer2;
  v49.m128_i32[1] = LODWORD(this->delayLowPassFilter[1].fFFbk1);
  v6 = in_pfInBuffer;
  v49.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fFFbk1);
  v7 = this->delayLowPassFilter[1].fB0;
  _mm_store_si128((__m128i *)((char *)&v51 + 8), v5);
  v8 = *((_QWORD *)&v51 + 1);
  v9 = v51;
  v10.m128_f32[1] = v7;
  v49.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fFFbk1);
  v10.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fB0);
  v49.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fFFbk1);
  v11 = v49;
  v10.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fB0);
  v50.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fA1) ^ _xmm[0];
  v10.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fB0);
  v12 = v10;
  v50.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fA1) ^ _xmm[0];
  v50.m128_i32[1] = LODWORD(this->delayLowPassFilter[1].fA1) ^ _xmm[0];
  v50.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fA1) ^ _xmm[0];
  do
  {
    v13 = v4;
    if ( v4 >= this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset )
      v13 = this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset;
    if ( v13 >= this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset )
      v13 = this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset;
    if ( v13 >= this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset )
      v13 = this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset;
    if ( v13 >= this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset )
      v13 = this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset;
    v14 = v13 >> 2;
    if ( v13 >> 2 )
    {
      v15 = v14;
      do
      {
        v9 += 16i64;
        v8 += 16i64;
        v6 += 4;
        v16 = *(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset];
        v17 = v16;
        v18 = *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset];
        v19 = _mm_shuffle_ps(v16, v18, 238);
        v20 = _mm_shuffle_ps(v17, v18, 68);
        v21 = *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset];
        v22 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v21, 68);
        v23 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v21, 238);
        v24 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v22, 136), v12), _mm_mul_ps(v50, v11));
        v25 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v22, 221), v12), _mm_mul_ps(v24, v50));
        v26 = _mm_shuffle_ps(v24, v25, 68);
        v27 = _mm_shuffle_ps(v24, v25, 238);
        v28 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v23, 136), v12), _mm_mul_ps(v25, v50));
        v11 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v23, 221), v12), _mm_mul_ps(v28, v50));
        v29 = _mm_shuffle_ps(v28, v11, 68);
        v30 = _mm_shuffle_ps(v28, v11, 238);
        v31 = _mm_shuffle_ps(v26, v29, 136);
        v32 = _mm_shuffle_ps(v27, v30, 136);
        v33 = _mm_shuffle_ps(v26, v29, 221);
        v34 = _mm_add_ps(v31, v33);
        v35 = _mm_shuffle_ps(v27, v30, 221);
        *(__m128 *)(v9 - 16) = _mm_sub_ps(_mm_add_ps(_mm_add_ps(v31, v32), *(__m128 *)(v9 - 16)), _mm_add_ps(v33, v35));
        *(__m128 *)(v8 - 16) = _mm_sub_ps(_mm_add_ps(*(__m128 *)(v8 - 16), v34), _mm_add_ps(v32, v35));
        v36 = _mm_add_ps(
                _mm_mul_ps(_mm_add_ps(_mm_add_ps(v34, v32), v35), (__m128)_xmm_bf000000bf000000bf000000bf000000),
                *(__m128 *)((char *)v6 - 16));
        *(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset] = _mm_add_ps(v36, v33);
        this->FDNDelayLine[0].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset] = _mm_add_ps(v36, v32);
        this->FDNDelayLine[1].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset] = _mm_add_ps(v36, v35);
        this->FDNDelayLine[2].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset] = _mm_add_ps(v36, v31);
        this->FDNDelayLine[3].uCurOffset += 4;
        --v15;
      }
      while ( v15 );
      v49 = v11;
    }
    v37 = 4 * v14;
    if ( v37 < v13 )
    {
      v38 = v13 - v37;
      do
      {
        v9 += 4i64;
        v8 += 4i64;
        ++v6;
        v39.m128_i32[0] = LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset]);
        v39.m128_i32[1] = LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset]);
        v39.m128_i32[2] = LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset]);
        v39.m128_i32[3] = LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset]);
        v11 = _mm_add_ps(_mm_mul_ps(v39, v12), _mm_mul_ps(v50, v11));
        v40 = _mm_mul_ps(_xmm_bf8000003f800000bf8000003f800000, v11);
        v41 = _mm_mul_ps((__m128)_xmm_bf800000bf8000003f8000003f800000, v11);
        v42 = _mm_add_ps(v40, _mm_movehl_ps(v40, v40));
        v43 = _mm_add_ps(v41, _mm_movehl_ps(v41, v41));
        *(float *)(v9 - 4) = (float)(v42.m128_f32[0] + COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 85))) + *(float *)(v9 - 4);
        v44 = _mm_mul_ps((__m128)_xmm_bf000000bf000000bf000000bf000000, v11);
        *(float *)(v8 - 4) = (float)(v43.m128_f32[0] + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 85))) + *(float *)(v8 - 4);
        v45 = _mm_add_ps(v44, _mm_movehl_ps(v44, v44));
        v46 = _mm_add_ps(v45, _mm_shuffle_ps(v45, v45, 85));
        v47 = _mm_add_ps(v11, _mm_shuffle_ps(v46, v46, 0));
        v48 = _mm_add_ps(
                _mm_shuffle_ps(v47, v47, 57),
                _mm_shuffle_ps((__m128)*((unsigned int *)v6 - 1), (__m128)*((unsigned int *)v6 - 1), 0));
        LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset++]) = v48.m128_i32[0];
        LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset++]) = (unsigned __int128)_mm_shuffle_ps(v48, v48, 85);
        LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset++]) = (unsigned __int128)_mm_shuffle_ps(v48, v48, 170);
        LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset++]) = (unsigned __int128)_mm_shuffle_ps(v48, v48, 255);
        --v38;
      }
      while ( v38 );
      v49 = v11;
    }
    if ( this->FDNDelayLine[0].uCurOffset == this->FDNDelayLine[0].uDelayLineLength )
      this->FDNDelayLine[0].uCurOffset = 0;
    if ( this->FDNDelayLine[1].uCurOffset == this->FDNDelayLine[1].uDelayLineLength )
      this->FDNDelayLine[1].uCurOffset = 0;
    if ( this->FDNDelayLine[2].uCurOffset == this->FDNDelayLine[2].uDelayLineLength )
      this->FDNDelayLine[2].uCurOffset = 0;
    if ( this->FDNDelayLine[3].uCurOffset == this->FDNDelayLine[3].uDelayLineLength )
      this->FDNDelayLine[3].uCurOffset = 0;
    v4 -= v13;
  }
  while ( v4 );
  LODWORD(this->delayLowPassFilter[0].fFFbk1) = v49.m128_i32[0];
  this->delayLowPassFilter[1].fFFbk1 = v49.m128_f32[1];
  this->delayLowPassFilter[2].fFFbk1 = v49.m128_f32[2];
  this->delayLowPassFilter[3].fFFbk1 = v49.m128_f32[3];
}

// File Line: 457
// RVA: 0xAE8E50
void __fastcall DSP::FDN4::ProcessBufferAccum(DSP::FDN4 *this, float *in_pfInBuffer, float *io_pfOutBuffer1, float *io_pfOutBuffer2)
{
  unsigned int v4; // esi
  int v5; // ST1C_4
  float *v6; // rdi
  float v7; // xmm1_4
  float *v8; // r11
  float *v9; // rbx
  __int64 v10; // r9
  __m128 v11; // xmm8
  __m128 v12; // xmm9
  __m128 v13; // xmm10
  unsigned int v14; // edx
  unsigned int v15; // er8
  __int64 v16; // r14
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm7
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm7
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm0
  __m128 v31; // xmm4
  __m128 v32; // xmm7
  __m128 v33; // xmm6
  __m128 v34; // xmm5
  __m128 v35; // xmm3
  __m128 v36; // xmm0
  __m128 v37; // xmm3
  unsigned int v38; // er8
  __int64 v39; // r8
  __m128 v40; // ST08_16
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm1
  __m128 v47; // xmm1
  __m128 v48; // xmm1
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  float v52; // [rsp+0h] [rbp-7Dh]
  __m256i v53; // [rsp+4h] [rbp-79h]
  __int64 v54; // [rsp+F4h] [rbp+77h]
  unsigned int v55; // [rsp+FCh] [rbp+7Fh]

  v4 = v55;
  v5 = HIDWORD(io_pfOutBuffer1);
  v6 = in_pfInBuffer;
  v7 = this->delayLowPassFilter[1].fFFbk1;
  v8 = io_pfOutBuffer2;
  v9 = io_pfOutBuffer1;
  v52 = this->delayLowPassFilter[3].fFFbk1;
  v53.m256i_i32[1] = LODWORD(this->delayLowPassFilter[1].fB0);
  v53.m256i_i32[3] = LODWORD(this->delayLowPassFilter[3].fB0);
  v10 = v54;
  v53.m256i_i32[2] = LODWORD(this->delayLowPassFilter[0].fFFbk1);
  v53.m256i_i32[4] = LODWORD(this->delayLowPassFilter[2].fFFbk1);
  v53.m256i_i32[6] = LODWORD(this->delayLowPassFilter[2].fA1) ^ _xmm[0];
  v11 = *(__m128 *)&v53.m256i_u64[1];
  v53.m256i_i32[0] = LODWORD(this->delayLowPassFilter[0].fB0);
  v53.m256i_i32[2] = LODWORD(this->delayLowPassFilter[2].fB0);
  v12 = *(__m128 *)v53.m256i_i8;
  v53.m256i_i32[4] = LODWORD(this->delayLowPassFilter[0].fA1) ^ _xmm[0];
  v53.m256i_i32[5] = LODWORD(this->delayLowPassFilter[1].fA1) ^ _xmm[0];
  v53.m256i_i32[7] = LODWORD(this->delayLowPassFilter[3].fA1) ^ _xmm[0];
  v13 = *(__m128 *)&v53.m256i_u64[2];
  do
  {
    v14 = v4;
    if ( v4 >= this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset )
      v14 = this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset;
    if ( v14 >= this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset )
      v14 = this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset;
    if ( v14 >= this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset )
      v14 = this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset;
    if ( v14 >= this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset )
      v14 = this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset;
    v15 = v14 >> 2;
    if ( v14 >> 2 )
    {
      v16 = v15;
      do
      {
        v9 += 4;
        v8 += 4;
        v10 += 16i64;
        v17 = *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset];
        v18 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset], v17, 68);
        v19 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset], v17, 238);
        v20 = *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset];
        v21 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v20, 68);
        v22 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v20, 238);
        v23 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v21, 136), v12), _mm_mul_ps(v13, v11));
        v24 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v21, 221), v12), _mm_mul_ps(v23, v13));
        v25 = _mm_shuffle_ps(v23, v24, 68);
        v26 = _mm_shuffle_ps(v23, v24, 238);
        v27 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v22, 136), v12), _mm_mul_ps(v24, v13));
        v11 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v22, 221), v12), _mm_mul_ps(v27, v13));
        v28 = v27;
        v29 = _mm_shuffle_ps(v27, v11, 238);
        v30 = _mm_shuffle_ps(v28, v11, 68);
        v31 = _mm_shuffle_ps(v26, v29, 136);
        v32 = _mm_shuffle_ps(v26, v29, 221);
        v33 = _mm_shuffle_ps(v25, v30, 136);
        v34 = _mm_shuffle_ps(v25, v30, 221);
        v35 = _mm_add_ps(v33, v34);
        *((__m128 *)v9 - 1) = _mm_sub_ps(
                                _mm_add_ps(_mm_add_ps(v33, v31), *(__m128 *)((char *)v9 - 16)),
                                _mm_add_ps(v34, v32));
        *((__m128 *)v8 - 1) = _mm_sub_ps(_mm_add_ps(*(__m128 *)((char *)v8 - 16), v35), _mm_add_ps(v31, v32));
        *(__m128 *)(v10 - 16) = _mm_sub_ps(
                                  _mm_add_ps(_mm_add_ps(v33, v32), *(__m128 *)(v10 - 16)),
                                  _mm_add_ps(v34, v31));
        v36 = *(__m128 *)v6;
        v6 += 4;
        v37 = _mm_add_ps(
                _mm_mul_ps(_mm_add_ps(_mm_add_ps(v35, v31), v32), (__m128)_xmm_bf000000bf000000bf000000bf000000),
                v36);
        *(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset] = _mm_add_ps(v37, v34);
        this->FDNDelayLine[0].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset] = _mm_add_ps(v37, v31);
        this->FDNDelayLine[1].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset] = _mm_add_ps(v37, v32);
        this->FDNDelayLine[2].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset] = _mm_add_ps(v37, v33);
        this->FDNDelayLine[3].uCurOffset += 4;
        --v16;
      }
      while ( v16 );
      *(__m128 *)&v53.m256i_u64[1] = v11;
    }
    v38 = 4 * v15;
    if ( v38 < v14 )
    {
      v39 = v14 - v38;
      do
      {
        ++v9;
        ++v8;
        v10 += 4i64;
        v40.m128_i32[0] = LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset]);
        ++v6;
        v40.m128_i32[1] = LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset]);
        v40.m128_i32[2] = LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset]);
        v40.m128_i32[3] = LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset]);
        v11 = _mm_add_ps(_mm_mul_ps(v40, v12), _mm_mul_ps(v13, v11));
        v41 = _mm_mul_ps(_xmm_bf8000003f800000bf8000003f800000, v11);
        v42 = _mm_mul_ps((__m128)_xmm_bf800000bf8000003f8000003f800000, v11);
        v43 = _mm_add_ps(v41, _mm_movehl_ps(v41, v41));
        v44 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
        *(v9 - 1) = (float)(v43.m128_f32[0] + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 85))) + *(v9 - 1);
        v45 = _mm_mul_ps((__m128)_xmm, v11);
        v46 = _mm_add_ps(v45, _mm_movehl_ps(v45, v45));
        *(v8 - 1) = (float)(v44.m128_f32[0] + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85))) + *(v8 - 1);
        *(float *)(v10 - 4) = (float)(v46.m128_f32[0] + COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 85)))
                            + *(float *)(v10 - 4);
        v47 = _mm_mul_ps((__m128)_xmm_bf000000bf000000bf000000bf000000, v11);
        v48 = _mm_add_ps(v47, _mm_movehl_ps(v47, v47));
        v49 = _mm_add_ps(v48, _mm_shuffle_ps(v48, v48, 85));
        v50 = _mm_add_ps(v11, _mm_shuffle_ps(v49, v49, 0));
        v51 = _mm_add_ps(
                _mm_shuffle_ps(v50, v50, 57),
                _mm_shuffle_ps((__m128)*((unsigned int *)v6 - 1), (__m128)*((unsigned int *)v6 - 1), 0));
        LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset++]) = v51.m128_i32[0];
        LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset++]) = (unsigned __int128)_mm_shuffle_ps(v51, v51, 85);
        LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset++]) = (unsigned __int128)_mm_shuffle_ps(v51, v51, 170);
        LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset++]) = (unsigned __int128)_mm_shuffle_ps(v51, v51, 255);
        --v39;
      }
      while ( v39 );
      *(__m128 *)&v53.m256i_u64[1] = v11;
    }
    if ( this->FDNDelayLine[0].uCurOffset == this->FDNDelayLine[0].uDelayLineLength )
      this->FDNDelayLine[0].uCurOffset = 0;
    if ( this->FDNDelayLine[1].uCurOffset == this->FDNDelayLine[1].uDelayLineLength )
      this->FDNDelayLine[1].uCurOffset = 0;
    if ( this->FDNDelayLine[2].uCurOffset == this->FDNDelayLine[2].uDelayLineLength )
      this->FDNDelayLine[2].uCurOffset = 0;
    if ( this->FDNDelayLine[3].uCurOffset == this->FDNDelayLine[3].uDelayLineLength )
      this->FDNDelayLine[3].uCurOffset = 0;
    v4 -= v14;
  }
  while ( v4 );
  LODWORD(this->delayLowPassFilter[0].fFFbk1) = v53.m256i_i32[2];
  LODWORD(this->delayLowPassFilter[1].fFFbk1) = v53.m256i_i32[3];
  LODWORD(this->delayLowPassFilter[2].fFFbk1) = v53.m256i_i32[4];
  this->delayLowPassFilter[3].fFFbk1 = v52;
}

