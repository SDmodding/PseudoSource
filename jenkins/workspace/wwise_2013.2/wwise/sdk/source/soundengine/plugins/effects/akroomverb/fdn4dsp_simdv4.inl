// File Line: 433
// RVA: 0xAE8480
void __fastcall DSP::FDN4::ProcessBufferAccum(
        DSP::FDN4 *this,
        float *in_pfInBuffer,
        __m128 *io_pfOutBuffer,
        unsigned int in_uNumFrames)
{
  __m128 v6; // xmm7
  __m128 v7; // xmm8
  unsigned int v8; // edx
  unsigned int v9; // r9d
  __int64 v10; // rdi
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm6
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // xmm5
  __m128 v27; // xmm4
  __m128 v28; // xmm6
  __m128 v29; // xmm1
  unsigned int v30; // r9d
  __int64 v31; // r9
  __m128 v32; // xmm1
  __m128 v33; // xmm1
  __m128 v34; // xmm1
  __m128 v35; // xmm1
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // [rsp+0h] [rbp-80h]
  __m128 v39; // [rsp+10h] [rbp-70h]
  __m128 v40; // [rsp+10h] [rbp-70h]
  __m128 v41; // [rsp+10h] [rbp-70h]
  __m128 v42; // [rsp+20h] [rbp-60h]

  v38.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fFFbk1);
  v38.m128_i32[1] = LODWORD(this->delayLowPassFilter[1].fFFbk1);
  v38.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fFFbk1);
  v39.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fB0);
  v38.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fFFbk1);
  v6 = v38;
  v39.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fB0);
  v42.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fA1) ^ _xmm[0];
  v39.m128_i32[1] = LODWORD(this->delayLowPassFilter[1].fB0);
  v42.m128_i32[1] = LODWORD(this->delayLowPassFilter[1].fA1) ^ _xmm[0];
  v39.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fB0);
  v42.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fA1) ^ _xmm[0];
  v7 = v39;
  v42.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fA1) ^ _xmm[0];
  do
  {
    v8 = in_uNumFrames;
    if ( in_uNumFrames >= this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset )
      v8 = this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset;
    if ( v8 >= this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset )
      v8 = this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset;
    if ( v8 >= this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset )
      v8 = this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset;
    if ( v8 >= this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset )
      v8 = this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset;
    v9 = v8 >> 2;
    if ( v8 >> 2 )
    {
      v10 = v9;
      do
      {
        ++io_pfOutBuffer;
        in_pfInBuffer += 4;
        v11 = *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset];
        v12 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset], v11, 68);
        v13 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset], v11, 238);
        v14 = *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset];
        v15 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v14, 68);
        v16 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v14, 238);
        v17 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v15, 136), v7), _mm_mul_ps(v42, v6));
        v18 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v15, 221), v7), _mm_mul_ps(v17, v42));
        v19 = _mm_shuffle_ps(v17, v18, 238);
        v20 = _mm_shuffle_ps(v17, v18, 68);
        v21 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v16, 136), v7), _mm_mul_ps(v18, v42));
        v6 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v16, 221), v7), _mm_mul_ps(v21, v42));
        v22 = v21;
        v23 = _mm_shuffle_ps(v21, v6, 238);
        v24 = _mm_shuffle_ps(v22, v6, 68);
        v25 = _mm_shuffle_ps(v19, v23, 136);
        v26 = _mm_shuffle_ps(v20, v24, 136);
        v27 = _mm_shuffle_ps(v20, v24, 221);
        v28 = _mm_shuffle_ps(v19, v23, 221);
        io_pfOutBuffer[-1] = _mm_sub_ps(_mm_add_ps(_mm_add_ps(v26, v25), io_pfOutBuffer[-1]), _mm_add_ps(v27, v28));
        v29 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(_mm_add_ps(_mm_add_ps(v26, v27), v25), v28),
                  (__m128)_xmm_bf000000bf000000bf000000bf000000),
                *(__m128 *)(in_pfInBuffer - 4));
        *(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset] = _mm_add_ps(v29, v27);
        this->FDNDelayLine[0].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset] = _mm_add_ps(v29, v25);
        this->FDNDelayLine[1].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset] = _mm_add_ps(v29, v28);
        this->FDNDelayLine[2].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset] = _mm_add_ps(v29, v26);
        this->FDNDelayLine[3].uCurOffset += 4;
        --v10;
      }
      while ( v10 );
      v38 = v6;
    }
    v30 = 4 * v9;
    if ( v30 < v8 )
    {
      v31 = v8 - v30;
      do
      {
        io_pfOutBuffer = (__m128 *)((char *)io_pfOutBuffer + 4);
        ++in_pfInBuffer;
        v40.m128_i32[0] = LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset]);
        v40.m128_i32[1] = LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset]);
        v40.m128_i32[2] = LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset]);
        v40.m128_i32[3] = LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset]);
        v6 = _mm_add_ps(_mm_mul_ps(v40, v7), _mm_mul_ps(v42, v6));
        v32 = _mm_mul_ps(_xmm_bf8000003f800000bf8000003f800000, v6);
        v33 = _mm_add_ps(v32, _mm_movehl_ps(v32, v32));
        io_pfOutBuffer[-1].m128_f32[3] = (float)(v33.m128_f32[0] + _mm_shuffle_ps(v33, v33, 85).m128_f32[0])
                                       + io_pfOutBuffer[-1].m128_f32[3];
        v34 = _mm_mul_ps((__m128)_xmm_bf000000bf000000bf000000bf000000, v6);
        v35 = _mm_add_ps(v34, _mm_movehl_ps(v34, v34));
        v36 = _mm_add_ps(v35, _mm_shuffle_ps(v35, v35, 85));
        v41 = _mm_add_ps(v6, _mm_shuffle_ps(v36, v36, 0));
        v37 = _mm_add_ps(
                _mm_shuffle_ps(v41, v41, 57),
                _mm_shuffle_ps(
                  (__m128)*((unsigned int *)in_pfInBuffer - 1),
                  (__m128)*((unsigned int *)in_pfInBuffer - 1),
                  0));
        LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset++]) = v37.m128_i32[0];
        LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset++]) = _mm_shuffle_ps(v37, v37, 85).m128_u32[0];
        LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset++]) = _mm_shuffle_ps(v37, v37, 170).m128_u32[0];
        LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset++]) = _mm_shuffle_ps(v37, v37, 255).m128_u32[0];
        --v31;
      }
      while ( v31 );
      v38 = v6;
    }
    if ( this->FDNDelayLine[0].uCurOffset == this->FDNDelayLine[0].uDelayLineLength )
      this->FDNDelayLine[0].uCurOffset = 0;
    if ( this->FDNDelayLine[1].uCurOffset == this->FDNDelayLine[1].uDelayLineLength )
      this->FDNDelayLine[1].uCurOffset = 0;
    if ( this->FDNDelayLine[2].uCurOffset == this->FDNDelayLine[2].uDelayLineLength )
      this->FDNDelayLine[2].uCurOffset = 0;
    if ( this->FDNDelayLine[3].uCurOffset == this->FDNDelayLine[3].uDelayLineLength )
      this->FDNDelayLine[3].uCurOffset = 0;
    in_uNumFrames -= v8;
  }
  while ( in_uNumFrames );
  LODWORD(this->delayLowPassFilter[0].fFFbk1) = v38.m128_i32[0];
  LODWORD(this->delayLowPassFilter[1].fFFbk1) = v38.m128_i32[1];
  LODWORD(this->delayLowPassFilter[2].fFFbk1) = v38.m128_i32[2];
  LODWORD(this->delayLowPassFilter[3].fFFbk1) = v38.m128_i32[3];
}r[1].fFFbk1) = v38.m128_i32[1];
  LODWORD(this->delayLowPassFilter[2].fFFbk1) = v38.m128_i32[2];
  LODWORD(this->delayLowPassFi

// File Line: 444
// RVA: 0xAE8920
void __fastcall DSP::FDN4::ProcessBufferAccum(
        DSP::FDN4 *this,
        float *in_pfInBuffer,
        float *io_pfOutBuffer1,
        __m128 *io_pfOutBuffer2)
{
  unsigned int v4; // edi
  float *v7; // r9
  __m128 v8; // xmm8
  __m128 v9; // xmm9
  unsigned int v10; // edx
  unsigned int v11; // r11d
  __int64 v12; // rsi
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm7
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm7
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm6
  __m128 v28; // xmm4
  __m128 v29; // xmm5
  __m128 v30; // xmm3
  __m128 v31; // xmm7
  __m128 v32; // xmm3
  unsigned int v33; // r11d
  __int64 v34; // r11
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm1
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // [rsp+0h] [rbp-51h]
  __m128 v44; // [rsp+10h] [rbp-41h]
  __m128 v45; // [rsp+10h] [rbp-41h]
  __m128 v46; // [rsp+10h] [rbp-41h]
  __m128 v48; // [rsp+20h] [rbp-31h]
  unsigned int v49; // [rsp+D0h] [rbp+7Fh]

  v4 = v49;
  v43.m128_i32[1] = LODWORD(this->delayLowPassFilter[1].fFFbk1);
  v43.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fFFbk1);
  v7 = io_pfOutBuffer1;
  v44.m128_i32[1] = LODWORD(this->delayLowPassFilter[1].fB0);
  v43.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fFFbk1);
  v44.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fB0);
  v43.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fFFbk1);
  v8 = v43;
  v44.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fB0);
  v48.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fA1) ^ _xmm[0];
  v44.m128_i32[2] = LODWORD(this->delayLowPassFilter[2].fB0);
  v9 = v44;
  v48.m128_i32[0] = LODWORD(this->delayLowPassFilter[0].fA1) ^ _xmm[0];
  v48.m128_i32[1] = LODWORD(this->delayLowPassFilter[1].fA1) ^ _xmm[0];
  v48.m128_i32[3] = LODWORD(this->delayLowPassFilter[3].fA1) ^ _xmm[0];
  do
  {
    v10 = v4;
    if ( v4 >= this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset )
      v10 = this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset;
    if ( v10 >= this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset )
      v10 = this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset;
    if ( v10 >= this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset )
      v10 = this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset;
    if ( v10 >= this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset )
      v10 = this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset;
    v11 = v10 >> 2;
    if ( v10 >> 2 )
    {
      v12 = v11;
      do
      {
        v7 += 4;
        ++io_pfOutBuffer2;
        in_pfInBuffer += 4;
        v13 = *(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset];
        v14 = *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset];
        v15 = _mm_shuffle_ps(v13, v14, 238);
        v16 = _mm_shuffle_ps(v13, v14, 68);
        v17 = *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset];
        v18 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v17, 68);
        v19 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v17, 238);
        v20 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v18, 136), v9), _mm_mul_ps(v48, v8));
        v21 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v18, 221), v9), _mm_mul_ps(v20, v48));
        v22 = _mm_shuffle_ps(v20, v21, 68);
        v23 = _mm_shuffle_ps(v20, v21, 238);
        v24 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v19, 136), v9), _mm_mul_ps(v21, v48));
        v8 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v19, 221), v9), _mm_mul_ps(v24, v48));
        v25 = _mm_shuffle_ps(v24, v8, 68);
        v26 = _mm_shuffle_ps(v24, v8, 238);
        v27 = _mm_shuffle_ps(v22, v25, 136);
        v28 = _mm_shuffle_ps(v23, v26, 136);
        v29 = _mm_shuffle_ps(v22, v25, 221);
        v30 = _mm_add_ps(v27, v29);
        v31 = _mm_shuffle_ps(v23, v26, 221);
        *((__m128 *)v7 - 1) = _mm_sub_ps(_mm_add_ps(_mm_add_ps(v27, v28), *(__m128 *)(v7 - 4)), _mm_add_ps(v29, v31));
        io_pfOutBuffer2[-1] = _mm_sub_ps(_mm_add_ps(io_pfOutBuffer2[-1], v30), _mm_add_ps(v28, v31));
        v32 = _mm_add_ps(
                _mm_mul_ps(_mm_add_ps(_mm_add_ps(v30, v28), v31), (__m128)_xmm_bf000000bf000000bf000000bf000000),
                *(__m128 *)(in_pfInBuffer - 4));
        *(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset] = _mm_add_ps(v32, v29);
        this->FDNDelayLine[0].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset] = _mm_add_ps(v32, v28);
        this->FDNDelayLine[1].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset] = _mm_add_ps(v32, v31);
        this->FDNDelayLine[2].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset] = _mm_add_ps(v32, v27);
        this->FDNDelayLine[3].uCurOffset += 4;
        --v12;
      }
      while ( v12 );
      v43 = v8;
    }
    v33 = 4 * v11;
    if ( v33 < v10 )
    {
      v34 = v10 - v33;
      do
      {
        ++v7;
        io_pfOutBuffer2 = (__m128 *)((char *)io_pfOutBuffer2 + 4);
        ++in_pfInBuffer;
        v45.m128_i32[0] = LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset]);
        v45.m128_i32[1] = LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset]);
        v45.m128_i32[2] = LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset]);
        v45.m128_i32[3] = LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset]);
        v8 = _mm_add_ps(_mm_mul_ps(v45, v9), _mm_mul_ps(v48, v8));
        v35 = _mm_mul_ps(_xmm_bf8000003f800000bf8000003f800000, v8);
        v36 = _mm_mul_ps((__m128)_xmm_bf800000bf8000003f8000003f800000, v8);
        v37 = _mm_add_ps(v35, _mm_movehl_ps(v35, v35));
        v38 = _mm_add_ps(v36, _mm_movehl_ps(v36, v36));
        *(v7 - 1) = (float)(v37.m128_f32[0] + _mm_shuffle_ps(v37, v37, 85).m128_f32[0]) + *(v7 - 1);
        v39 = _mm_mul_ps((__m128)_xmm_bf000000bf000000bf000000bf000000, v8);
        io_pfOutBuffer2[-1].m128_f32[3] = (float)(v38.m128_f32[0] + _mm_shuffle_ps(v38, v38, 85).m128_f32[0])
                                        + io_pfOutBuffer2[-1].m128_f32[3];
        v40 = _mm_add_ps(v39, _mm_movehl_ps(v39, v39));
        v41 = _mm_add_ps(v40, _mm_shuffle_ps(v40, v40, 85));
        v46 = _mm_add_ps(v8, _mm_shuffle_ps(v41, v41, 0));
        v42 = _mm_add_ps(
                _mm_shuffle_ps(v46, v46, 57),
                _mm_shuffle_ps(
                  (__m128)*((unsigned int *)in_pfInBuffer - 1),
                  (__m128)*((unsigned int *)in_pfInBuffer - 1),
                  0));
        LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset++]) = v42.m128_i32[0];
        LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset++]) = _mm_shuffle_ps(v42, v42, 85).m128_u32[0];
        LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset++]) = _mm_shuffle_ps(v42, v42, 170).m128_u32[0];
        LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset++]) = _mm_shuffle_ps(v42, v42, 255).m128_u32[0];
        --v34;
      }
      while ( v34 );
      v43 = v8;
    }
    if ( this->FDNDelayLine[0].uCurOffset == this->FDNDelayLine[0].uDelayLineLength )
      this->FDNDelayLine[0].uCurOffset = 0;
    if ( this->FDNDelayLine[1].uCurOffset == this->FDNDelayLine[1].uDelayLineLength )
      this->FDNDelayLine[1].uCurOffset = 0;
    if ( this->FDNDelayLine[2].uCurOffset == this->FDNDelayLine[2].uDelayLineLength )
      this->FDNDelayLine[2].uCurOffset = 0;
    if ( this->FDNDelayLine[3].uCurOffset == this->FDNDelayLine[3].uDelayLineLength )
      this->FDNDelayLine[3].uCurOffset = 0;
    v4 -= v10;
  }
  while ( v4 );
  LODWORD(this->delayLowPassFilter[0].fFFbk1) = v43.m128_i32[0];
  LODWORD(this->delayLowPassFilter[1].fFFbk1) = v43.m128_i32[1];
  LODWORD(this->delayLowPassFilter[2].fFFbk1) = v43.m128_i32[2];
  LODWORD(this->delayLowPassFilter[3].fFFbk1) = v43.m128_i32[3];
}

// File Line: 457
// RVA: 0xAE8E50
void __fastcall DSP::FDN4::ProcessBufferAccum(
        DSP::FDN4 *this,
        __m128 *in_pfInBuffer,
        float *io_pfOutBuffer1,
        __m128 *io_pfOutBuffer2)
{
  unsigned int v4; // esi
  float *v7; // rbx
  __int64 v8; // r9
  __m128 v9; // xmm8
  __m128 v10; // xmm9
  __m128 v11; // xmm10
  unsigned int v12; // edx
  unsigned int v13; // r8d
  __int64 v14; // r14
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm7
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm7
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm4
  __m128 v30; // xmm7
  __m128 v31; // xmm6
  __m128 v32; // xmm5
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  __m128 v35; // xmm3
  unsigned int v36; // r8d
  __int64 v37; // r8
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm1
  __m128 v44; // xmm1
  __m128 v45; // xmm1
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  float fFFbk1; // [rsp+0h] [rbp-7Dh]
  __m256i v49; // [rsp+4h] [rbp-79h]
  __m128 v50; // [rsp+4h] [rbp-79h]
  __m128 v51; // [rsp+4h] [rbp-79h]
  int v52; // [rsp+18h] [rbp-65h]
  __int64 v53; // [rsp+F4h] [rbp+77h]
  unsigned int v54; // [rsp+FCh] [rbp+7Fh]

  v4 = v54;
  v52 = HIDWORD(io_pfOutBuffer1);
  v7 = io_pfOutBuffer1;
  fFFbk1 = this->delayLowPassFilter[3].fFFbk1;
  v49.m256i_i32[1] = LODWORD(this->delayLowPassFilter[1].fB0);
  v49.m256i_i32[3] = LODWORD(this->delayLowPassFilter[3].fB0);
  v8 = v53;
  v49.m256i_i32[2] = LODWORD(this->delayLowPassFilter[0].fFFbk1);
  v49.m256i_i32[4] = LODWORD(this->delayLowPassFilter[2].fFFbk1);
  v49.m256i_i32[6] = LODWORD(this->delayLowPassFilter[2].fA1) ^ _xmm[0];
  v9 = *(__m128 *)&v49.m256i_u64[1];
  v49.m256i_i32[0] = LODWORD(this->delayLowPassFilter[0].fB0);
  v49.m256i_i32[2] = LODWORD(this->delayLowPassFilter[2].fB0);
  v10 = *(__m128 *)v49.m256i_i8;
  v49.m256i_i32[4] = LODWORD(this->delayLowPassFilter[0].fA1) ^ _xmm[0];
  v49.m256i_i32[5] = LODWORD(this->delayLowPassFilter[1].fA1) ^ _xmm[0];
  v49.m256i_i32[7] = LODWORD(this->delayLowPassFilter[3].fA1) ^ _xmm[0];
  v11 = *(__m128 *)&v49.m256i_u64[2];
  do
  {
    v12 = v4;
    if ( v4 >= this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset )
      v12 = this->FDNDelayLine[0].uDelayLineLength - this->FDNDelayLine[0].uCurOffset;
    if ( v12 >= this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset )
      v12 = this->FDNDelayLine[1].uDelayLineLength - this->FDNDelayLine[1].uCurOffset;
    if ( v12 >= this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset )
      v12 = this->FDNDelayLine[2].uDelayLineLength - this->FDNDelayLine[2].uCurOffset;
    if ( v12 >= this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset )
      v12 = this->FDNDelayLine[3].uDelayLineLength - this->FDNDelayLine[3].uCurOffset;
    v13 = v12 >> 2;
    if ( v12 >> 2 )
    {
      v14 = v13;
      do
      {
        v7 += 4;
        ++io_pfOutBuffer2;
        v8 += 16i64;
        v15 = *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset];
        v16 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset], v15, 68);
        v17 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset], v15, 238);
        v18 = *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset];
        v19 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v18, 68);
        v20 = _mm_shuffle_ps(*(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset], v18, 238);
        v21 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v19, 136), v10), _mm_mul_ps(v11, v9));
        v22 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v19, 221), v10), _mm_mul_ps(v21, v11));
        v23 = _mm_shuffle_ps(v21, v22, 68);
        v24 = _mm_shuffle_ps(v21, v22, 238);
        v25 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v20, 136), v10), _mm_mul_ps(v22, v11));
        v9 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v20, 221), v10), _mm_mul_ps(v25, v11));
        v26 = v25;
        v27 = _mm_shuffle_ps(v25, v9, 238);
        v28 = _mm_shuffle_ps(v26, v9, 68);
        v29 = _mm_shuffle_ps(v24, v27, 136);
        v30 = _mm_shuffle_ps(v24, v27, 221);
        v31 = _mm_shuffle_ps(v23, v28, 136);
        v32 = _mm_shuffle_ps(v23, v28, 221);
        v33 = _mm_add_ps(v31, v32);
        *((__m128 *)v7 - 1) = _mm_sub_ps(_mm_add_ps(_mm_add_ps(v31, v29), *(__m128 *)(v7 - 4)), _mm_add_ps(v32, v30));
        io_pfOutBuffer2[-1] = _mm_sub_ps(_mm_add_ps(io_pfOutBuffer2[-1], v33), _mm_add_ps(v29, v30));
        *(__m128 *)(v8 - 16) = _mm_sub_ps(_mm_add_ps(_mm_add_ps(v31, v30), *(__m128 *)(v8 - 16)), _mm_add_ps(v32, v29));
        v34 = *in_pfInBuffer++;
        v35 = _mm_add_ps(
                _mm_mul_ps(_mm_add_ps(_mm_add_ps(v33, v29), v30), (__m128)_xmm_bf000000bf000000bf000000bf000000),
                v34);
        *(__m128 *)&this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset] = _mm_add_ps(v35, v32);
        this->FDNDelayLine[0].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset] = _mm_add_ps(v35, v29);
        this->FDNDelayLine[1].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset] = _mm_add_ps(v35, v30);
        this->FDNDelayLine[2].uCurOffset += 4;
        *(__m128 *)&this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset] = _mm_add_ps(v35, v31);
        this->FDNDelayLine[3].uCurOffset += 4;
        --v14;
      }
      while ( v14 );
      *(__m128 *)&v49.m256i_u64[1] = v9;
    }
    v36 = 4 * v13;
    if ( v36 < v12 )
    {
      v37 = v12 - v36;
      do
      {
        ++v7;
        io_pfOutBuffer2 = (__m128 *)((char *)io_pfOutBuffer2 + 4);
        v8 += 4i64;
        v50.m128_i32[0] = LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset]);
        in_pfInBuffer = (__m128 *)((char *)in_pfInBuffer + 4);
        v50.m128_i32[1] = LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset]);
        v50.m128_i32[2] = LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset]);
        v50.m128_i32[3] = LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset]);
        v9 = _mm_add_ps(_mm_mul_ps(v50, v10), _mm_mul_ps(v11, v9));
        v38 = _mm_mul_ps(_xmm_bf8000003f800000bf8000003f800000, v9);
        v39 = _mm_mul_ps((__m128)_xmm_bf800000bf8000003f8000003f800000, v9);
        v40 = _mm_add_ps(v38, _mm_movehl_ps(v38, v38));
        v41 = _mm_add_ps(v39, _mm_movehl_ps(v39, v39));
        *(v7 - 1) = (float)(v40.m128_f32[0] + _mm_shuffle_ps(v40, v40, 85).m128_f32[0]) + *(v7 - 1);
        v42 = _mm_mul_ps((__m128)_xmm, v9);
        v43 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
        io_pfOutBuffer2[-1].m128_f32[3] = (float)(v41.m128_f32[0] + _mm_shuffle_ps(v41, v41, 85).m128_f32[0])
                                        + io_pfOutBuffer2[-1].m128_f32[3];
        *(float *)(v8 - 4) = (float)(v43.m128_f32[0] + _mm_shuffle_ps(v43, v43, 85).m128_f32[0]) + *(float *)(v8 - 4);
        v44 = _mm_mul_ps((__m128)_xmm_bf000000bf000000bf000000bf000000, v9);
        v45 = _mm_add_ps(v44, _mm_movehl_ps(v44, v44));
        v46 = _mm_add_ps(v45, _mm_shuffle_ps(v45, v45, 85));
        v51 = _mm_add_ps(v9, _mm_shuffle_ps(v46, v46, 0));
        v47 = _mm_add_ps(
                _mm_shuffle_ps(v51, v51, 57),
                _mm_shuffle_ps((__m128)in_pfInBuffer[-1].m128_u32[3], (__m128)in_pfInBuffer[-1].m128_u32[3], 0));
        LODWORD(this->FDNDelayLine[0].pfDelay[this->FDNDelayLine[0].uCurOffset++]) = v47.m128_i32[0];
        LODWORD(this->FDNDelayLine[1].pfDelay[this->FDNDelayLine[1].uCurOffset++]) = _mm_shuffle_ps(v47, v47, 85).m128_u32[0];
        LODWORD(this->FDNDelayLine[2].pfDelay[this->FDNDelayLine[2].uCurOffset++]) = _mm_shuffle_ps(v47, v47, 170).m128_u32[0];
        LODWORD(this->FDNDelayLine[3].pfDelay[this->FDNDelayLine[3].uCurOffset++]) = _mm_shuffle_ps(v47, v47, 255).m128_u32[0];
        --v37;
      }
      while ( v37 );
      *(__m128 *)&v49.m256i_u64[1] = v9;
    }
    if ( this->FDNDelayLine[0].uCurOffset == this->FDNDelayLine[0].uDelayLineLength )
      this->FDNDelayLine[0].uCurOffset = 0;
    if ( this->FDNDelayLine[1].uCurOffset == this->FDNDelayLine[1].uDelayLineLength )
      this->FDNDelayLine[1].uCurOffset = 0;
    if ( this->FDNDelayLine[2].uCurOffset == this->FDNDelayLine[2].uDelayLineLength )
      this->FDNDelayLine[2].uCurOffset = 0;
    if ( this->FDNDelayLine[3].uCurOffset == this->FDNDelayLine[3].uDelayLineLength )
      this->FDNDelayLine[3].uCurOffset = 0;
    v4 -= v12;
  }
  while ( v4 );
  LODWORD(this->delayLowPassFilter[0].fFFbk1) = v49.m256i_i32[2];
  LODWORD(this->delayLowPassFilter[1].fFFbk1) = v49.m256i_i32[3];
  LODWORD(this->delayLowPassFilter[2].fFFbk1) = v49.m256i_i32[4];
  this->delayLowPassFilter[3].fFFbk1 = fFFbk1;
}

