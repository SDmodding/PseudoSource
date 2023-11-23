// File Line: 32
// RVA: 0xAEFAD0
__int64 __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::Alloc(
        DSP::AkFFTAllButterflies::CAkFreqWindow *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uFFTSize)
{
  ak_fft_cpx *v4; // rax
  unsigned int v5; // ecx

  this->m_uFFTSize = in_uFFTSize;
  v4 = (ak_fft_cpx *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8i64 * ((in_uFFTSize >> 1) + 1));
  v5 = 1;
  this->m_pfFreqData = v4;
  if ( !v4 )
    return 52;
  return v5;
}

// File Line: 42
// RVA: 0xAEFB20
void __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::Free(
        DSP::AkFFTAllButterflies::CAkFreqWindow *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->m_pfFreqData )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->m_pfFreqData = 0i64;
    this->m_bReady = 0;
  }
  else
  {
    this->m_bReady = 0;
  }
}

// File Line: 54
// RVA: 0xAEFC10
void __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::CartToPol(DSP::AkFFTAllButterflies::CAkFreqWindow *this)
{
  DSP::AkFFTAllButterflies::CAkFreqWindow::CartToPol(this, this->m_pfFreqData);
}

// File Line: 59
// RVA: 0xAEFC20
void __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::PolToCart(DSP::AkFFTAllButterflies::CAkFreqWindow *this)
{
  DSP::AkFFTAllButterflies::CAkFreqWindow::PolToCart(this, (DSP::AkPolar *)this->m_pfFreqData);
}

// File Line: 64
// RVA: 0xAEFB60
void __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::Compute(
        DSP::AkFFTAllButterflies::CAkFreqWindow *this,
        ak_fft_cpx *in_pfTimeDomainWindow,
        unsigned int in_uNumFrames,
        ak_fftr_state *in_pFFTState)
{
  DSP::AkFFTAllButterflies::ak_fftr(in_pFFTState, in_pfTimeDomainWindow, this->m_pfFreqData);
  *(_WORD *)&this->m_bReady = 1;
}

// File Line: 69
// RVA: 0xAEFB90
void __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::ConvertToTimeDomain(
        DSP::AkFFTAllButterflies::CAkFreqWindow *this,
        ak_fft_cpx *out_pfTimeDomainBuffer,
        unsigned int in_uNumFrames,
        ak_fftr_state *in_pIFFTState)
{
  ak_fft_cpx *m_pfFreqData; // rdi

  m_pfFreqData = this->m_pfFreqData;
  if ( this->m_bPolar )
    DSP::AkFFTAllButterflies::CAkFreqWindow::PolToCart(this, (DSP::AkPolar *)m_pfFreqData);
  DSP::AkFFTAllButterflies::ak_fftri(in_pIFFTState, m_pfFreqData, out_pfTimeDomainBuffer);
  AK::DSP::ApplyGain_7((float *)out_pfTimeDomainBuffer, 1.0 / (float)(int)this->m_uFFTSize, this->m_uFFTSize);
}

// File Line: 80
// RVA: 0xAEFC30
void __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::ComputeVocoderSpectrum(
        DSP::AkFFTAllButterflies::CAkFreqWindow *this,
        DSP::AkPolar *in_pPreviousFrame,
        DSP::AkPolar *in_pNextFrame,
        float *io_pPreviousSynthPhases,
        unsigned int in_uHopSize,
        float in_fInterpLoc,
        bool in_bInitPhases)
{
  DSP::AkFFTAllButterflies::CAkFreqWindow::ComputeVocoderSpectrum(
    this,
    in_pPreviousFrame,
    in_pNextFrame,
    io_pPreviousSynthPhases,
    in_uHopSize,
    in_fInterpLoc,
    in_bInitPhases,
    (DSP::AkPolar *)this->m_pfFreqData);
}

// File Line: 108
// RVA: 0xAF07A0
void __fastcall DSP::AkFFTAllButterflies::PolarToCart(float *in_pPol, unsigned int in_uPoints)
{
  float *v2; // r8
  float *v3; // rax
  __m128 v4; // xmm3
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  __m128 v8; // xmm1

  v2 = in_pPol;
  v3 = &in_pPol[2 * in_uPoints];
  if ( in_pPol < v3 )
  {
    do
    {
      v4 = *(__m128 *)v2;
      v2 += 4;
      v5 = _mm_xor_ps(_mm_shuffle_ps(v4, v4, 245), *(__m128 *)_xmm);
      v6 = _mm_cmple_ps(*(__m128 *)_xmm, _mm_sub_ps(v5, (__m128)_xmm));
      v7 = _mm_add_ps(v5, _mm_or_ps(_mm_and_ps(v6, (__m128)_xmm), _mm_andnot_ps(v6, (__m128)_xmm)));
      v8 = _mm_mul_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_andnot_ps(*(__m128 *)_xmm, v7), (__m128)_xmm_becf817abecf817abecf817abecf817a),
               *(__m128 *)_xmm),
             v7);
      *((__m128 *)v2 - 1) = _mm_mul_ps(
                              _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps(_mm_mul_ps(_mm_andnot_ps(*(__m128 *)_xmm, v8), v8), v8),
                                  *(__m128 *)_xmm),
                                v8),
                              _mm_shuffle_ps(v4, v4, 160));
    }
    while ( v2 < v3 );
  }
}

// File Line: 236
// RVA: 0xAF0890
void __fastcall DSP::AkFFTAllButterflies::PairedCartToPol(float *in_pCart, unsigned int in_uPoints)
{
  float *v2; // r8
  float *v3; // rdx
  __m128 v4; // xmm9
  __m128 v5; // xmm1
  __m128 v6; // xmm7
  __m128 v7; // xmm5
  __m128 v8; // xmm9
  __m128 v9; // xmm8
  __m128 v10; // xmm8
  __m128 v11; // xmm7
  __m128 v12; // xmm4
  __m128 v13; // xmm6
  __m128 v14; // xmm1
  __m128 v15; // xmm7
  __m128 v16; // xmm0
  __m128 v17; // xmm1

  v2 = in_pCart;
  v3 = &in_pCart[2 * in_uPoints];
  if ( in_pCart < v3 )
  {
    do
    {
      v4 = *(__m128 *)v2;
      v2 += 8;
      v5 = _mm_shuffle_ps(v4, *(__m128 *)(v2 - 4), 136);
      v6 = _mm_shuffle_ps(v4, *(__m128 *)(v2 - 4), 221);
      v7 = _mm_cmple_ps((__m128)0i64, v6);
      v8 = _mm_mul_ps(v6, v6);
      v9 = _mm_cmpeq_ps(v5, (__m128)0i64);
      v10 = _mm_or_ps(_mm_andnot_ps(v9, v5), _mm_and_ps(v9, (__m128)_xmm));
      v11 = _mm_div_ps(v6, v10);
      v12 = _mm_cmple_ps((__m128)0i64, v10);
      v13 = _mm_cmple_ps(_mm_andnot_ps((__m128)0i64, v11), *(__m128 *)_xmm);
      v14 = _mm_sqrt_ps(_mm_add_ps(v8, _mm_mul_ps(v10, v10)));
      v15 = _mm_xor_ps(
              _mm_add_ps(
                _mm_div_ps(
                  v11,
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_or_ps(_mm_and_ps(v13, (__m128)_xmm), _mm_andnot_ps(v13, (__m128)_xmm)),
                      _mm_mul_ps(v11, v11)),
                    _mm_or_ps(
                      _mm_and_ps(v13, (__m128)_xmm),
                      _mm_andnot_ps(v13, *(__m128 *)_xmm_bf800000bf800000bf800000bf800000)))),
                _mm_mul_ps(
                  _mm_or_ps(
                    _mm_and_ps(_mm_or_ps(_mm_andnot_ps(v12, *(__m128 *)_xmm), _mm_and_ps(v12, (__m128)0i64)), v13),
                    _mm_andnot_ps(v13, *(__m128 *)_xmm)),
                  _mm_or_ps(
                    _mm_and_ps(v7, *(__m128 *)_xmm),
                    _mm_andnot_ps(v7, *(__m128 *)_xmm_bf800000bf800000bf800000bf800000)))),
              (__m128)0i64);
      v16 = _mm_shuffle_ps(v14, v15, 68);
      v17 = _mm_shuffle_ps(v14, v15, 238);
      *((__m128 *)v2 - 2) = _mm_shuffle_ps(v16, v16, 216);
      *((__m128 *)v2 - 1) = _mm_shuffle_ps(v17, v17, 216);
    }
    while ( v2 < v3 );
  }
}

// File Line: 472
// RVA: 0xAEFD10
void __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::CartToPol(
        DSP::AkFFTAllButterflies::CAkFreqWindow *this,
        ak_fft_cpx *io_pfFreqData)
{
  float v2; // xmm3_4
  unsigned int v3; // r8d
  ak_fft_cpx *v6; // rcx
  __int64 v7; // rdx
  float v8; // xmm6_4
  __m128 v9; // xmm5
  __m128 v10; // xmm1
  float v11; // xmm2_4
  float v12; // xmm2_4
  __m128 v13; // xmm1
  float v14; // xmm2_4
  float v15; // xmm2_4
  __m128 i_low; // xmm1
  float v17; // xmm3_4
  __int64 v18; // [rsp+88h] [rbp+10h]
  ak_fft_cpx v19; // [rsp+90h] [rbp+18h]

  v2 = FLOAT_N1_5707964;
  v3 = this->m_uFFTSize >> 1;
  v18 = (__int64)*io_pfFreqData;
  v19 = io_pfFreqData[v3];
  if ( v3 > 1 )
  {
    v6 = io_pfFreqData + 1;
    v7 = v3 - 1;
    do
    {
      v8 = COERCE_FLOAT(*v6);
      v9 = (__m128)HIDWORD(*(unsigned __int64 *)v6);
      v10 = v9;
      v10.m128_f32[0] = (float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8);
      LODWORD(v6->r) = _mm_sqrt_ps(v10).m128_u32[0];
      if ( v8 == 0.0 )
      {
        if ( v9.m128_f32[0] <= 0.0 )
        {
          if ( v9.m128_f32[0] == 0.0 )
            v12 = 0.0;
          else
            v12 = FLOAT_N1_5707964;
        }
        else
        {
          v12 = FLOAT_1_5707964;
        }
      }
      else
      {
        v11 = v9.m128_f32[0] / v8;
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v9.m128_f32[0] / v8) & _xmm) >= 1.0 )
        {
          v12 = 1.5707964 - (float)((float)(v9.m128_f32[0] / v8) / (float)((float)(v11 * v11) + 0.28));
          if ( v9.m128_f32[0] < 0.0 )
            v12 = v12 - 3.1415927;
        }
        else
        {
          v12 = v11 / (float)((float)((float)(v11 * 0.28) * v11) + 1.0);
          if ( v8 < 0.0 )
          {
            if ( v9.m128_f32[0] >= 0.0 )
              v12 = v12 + 3.1415927;
            else
              v12 = v12 - 3.1415927;
          }
        }
      }
      ++v6;
      LODWORD(v6[-1].i) = LODWORD(v12) ^ _xmm[0];
      --v7;
    }
    while ( v7 );
  }
  v13 = (__m128)HIDWORD(v18);
  v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(*(float *)&v18 * *(float *)&v18);
  LODWORD(io_pfFreqData->r) = _mm_sqrt_ps(v13).m128_u32[0];
  if ( *(float *)&v18 == 0.0 )
  {
    if ( *((float *)&v18 + 1) <= 0.0 )
    {
      if ( *((float *)&v18 + 1) == 0.0 )
        v15 = 0.0;
      else
        v15 = FLOAT_N1_5707964;
    }
    else
    {
      v15 = FLOAT_1_5707964;
    }
  }
  else
  {
    v14 = *((float *)&v18 + 1) / *(float *)&v18;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*((float *)&v18 + 1) / *(float *)&v18) & _xmm) >= 1.0 )
    {
      v15 = 1.5707964 - (float)((float)(*((float *)&v18 + 1) / *(float *)&v18) / (float)((float)(v14 * v14) + 0.28));
      if ( *((float *)&v18 + 1) < 0.0 )
        v15 = v15 - 3.1415927;
    }
    else
    {
      v15 = v14 / (float)((float)((float)(v14 * 0.28) * v14) + 1.0);
      if ( *(float *)&v18 < 0.0 )
      {
        if ( *((float *)&v18 + 1) >= 0.0 )
          v15 = v15 + 3.1415927;
        else
          v15 = v15 - 3.1415927;
      }
    }
  }
  io_pfFreqData->i = v15;
  i_low = (__m128)LODWORD(v19.i);
  i_low.m128_f32[0] = (float)(i_low.m128_f32[0] * i_low.m128_f32[0]) + (float)(v19.r * v19.r);
  LODWORD(io_pfFreqData[v3].r) = _mm_sqrt_ps(i_low).m128_u32[0];
  if ( v19.r == 0.0 )
  {
    if ( v19.i <= 0.0 )
    {
      if ( v19.i == 0.0 )
        v2 = 0.0;
    }
    else
    {
      v2 = FLOAT_1_5707964;
    }
  }
  else
  {
    v17 = v19.i / v19.r;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v19.i / v19.r) & _xmm) >= 1.0 )
    {
      v2 = 1.5707964 - (float)(v17 / (float)((float)(v17 * v17) + 0.28));
      if ( v19.i >= 0.0 )
        goto LABEL_41;
      goto LABEL_36;
    }
    v2 = v17 / (float)((float)((float)(v17 * 0.28) * v17) + 1.0);
    if ( v19.r < 0.0 )
    {
      if ( v19.i >= 0.0 )
      {
        v2 = v2 + 3.1415927;
        goto LABEL_41;
      }
LABEL_36:
      v2 = v2 - 3.1415927;
    }
  }
LABEL_41:
  io_pfFreqData[v3].i = v2;
  this->m_bPolar = 1;
}15927;
        goto LABEL_41;
      }
LABEL_36:
      v2 = v2 - 3.1415927;
    }
  }

// File Line: 516
// RVA: 0xAF0010
void __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::PolToCart(
        DSP::AkFFTAllButterflies::CAkFreqWindow *this,
        DSP::AkPolar *io_pfFreqData)
{
  unsigned int v3; // edx
  __int64 v5; // rdi
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm2_4
  __int64 v12; // [rsp+70h] [rbp+8h]
  DSP::AkPolar v13; // [rsp+78h] [rbp+10h]

  v3 = this->m_uFFTSize >> 1;
  v12 = (__int64)*io_pfFreqData;
  v5 = v3;
  v13 = io_pfFreqData[v3];
  DSP::AkFFTAllButterflies::PolarToCart((float *)io_pfFreqData, v3);
  v6 = *((float *)&v12 + 1) + 1.5707964;
  if ( (float)(*((float *)&v12 + 1) + 1.5707964) > 3.1415927 )
    v6 = v6 + -6.2831855;
  v7 = (float)(v6 * 1.2732395) - (float)(COERCE_FLOAT(LODWORD(v6) & _xmm) * (float)(v6 * 0.4052847));
  v8 = v13.fPhase + 1.5707964;
  io_pfFreqData->fMag = (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(v7) & _xmm) * v7) - v7) * 0.22499999) + v7)
                      * *(float *)&v12;
  v9 = (float)(*((float *)&v12 + 1) * 1.2732395)
     - (float)(COERCE_FLOAT(HIDWORD(v12) & _xmm) * (float)(*((float *)&v12 + 1) * 0.4052847));
  io_pfFreqData->fPhase = (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(v9) & _xmm) * v9) - v9) * 0.22499999) + v9)
                        * *(float *)&v12;
  if ( (float)(v13.fPhase + 1.5707964) > 3.1415927 )
    v8 = v8 + -6.2831855;
  this->m_bPolar = 0;
  v10 = (float)(v8 * 1.2732395) - (float)(COERCE_FLOAT(LODWORD(v8) & _xmm) * (float)(v8 * 0.4052847));
  io_pfFreqData[v5].fMag = (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(v10) & _xmm) * v10) - v10) * 0.22499999)
                                 + v10)
                         * v13.fMag;
  v11 = (float)(v13.fPhase * 1.2732395)
      - (float)(COERCE_FLOAT(LODWORD(v13.fPhase) & _xmm) * (float)(v13.fPhase * 0.4052847));
  io_pfFreqData[v5].fPhase = (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(v11) & _xmm) * v11) - v11) * 0.22499999)
                                   + v11)
                           * v13.fMag;
}

// File Line: 567
// RVA: 0xAEFC70
void __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::Compute(
        DSP::AkFFTAllButterflies::CAkFreqWindow *this,
        ak_fft_cpx *in_pfTimeDomainWindow,
        unsigned int in_uNumFrames,
        ak_fftr_state *in_pFFTState,
        ak_fft_cpx *io_pfFreqData)
{
  DSP::AkFFTAllButterflies::ak_fftr(in_pFFTState, in_pfTimeDomainWindow, io_pfFreqData);
  *(_WORD *)&this->m_bReady = 1;
}

// File Line: 582
// RVA: 0xAEFCA0
void __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::ConvertToTimeDomain(
        DSP::AkFFTAllButterflies::CAkFreqWindow *this,
        ak_fft_cpx *out_pfTimeDomainBuffer,
        unsigned int in_uNumFrames,
        ak_fftr_state *in_pIFFTState,
        ak_fft_cpx *io_pfFreqData)
{
  if ( this->m_bPolar )
    DSP::AkFFTAllButterflies::CAkFreqWindow::PolToCart(this, (DSP::AkPolar *)io_pfFreqData);
  DSP::AkFFTAllButterflies::ak_fftri(in_pIFFTState, io_pfFreqData, out_pfTimeDomainBuffer);
  AK::DSP::ApplyGain_7((float *)out_pfTimeDomainBuffer, 1.0 / (float)(int)this->m_uFFTSize, this->m_uFFTSize);
}

// File Line: 600
// RVA: 0xAF01F0
void __fastcall DSP::AkFFTAllButterflies::CAkFreqWindow::ComputeVocoderSpectrum(
        DSP::AkFFTAllButterflies::CAkFreqWindow *this,
        DSP::AkPolar *in_pPreviousFrame,
        DSP::AkPolar *in_pNextFrame,
        float *io_pPreviousSynthPhases,
        signed int in_uHopSize,
        float in_fInterpLoc,
        bool in_bInitPhases,
        DSP::AkPolar *io_pfFreqData)
{
  unsigned int m_uFFTSize; // r11d
  unsigned int v9; // edi
  int v12; // ebx
  unsigned int v15; // r10d
  __int64 v16; // rax
  signed __int64 v17; // rdx
  DSP::AkPolar *v18; // rcx
  float v19; // xmm5_4
  signed __int64 v20; // r8
  unsigned int v21; // eax
  __int64 v22; // r9
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  __int64 v26; // rdx
  DSP::AkPolar *v27; // rcx
  unsigned int v28; // r9d
  __int64 v29; // r10
  float *v30; // rcx
  char *p_fPhase; // rdx
  unsigned int v32; // eax
  __int64 v33; // r8
  int v34; // eax
  float *v35; // rcx
  float *v36; // rdx
  __int64 v37; // r8
  int v38; // eax
  float v39; // xmm1_4
  float v40; // xmm5_4
  float v41; // xmm0_4
  __int64 v42; // r11
  float v43; // xmm5_4
  signed __int64 v44; // r8
  signed __int64 v45; // r9
  unsigned int v46; // eax
  float *v47; // rcx
  float *v48; // rdx
  __int64 v49; // r10
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm2_4
  float v60; // xmm2_4
  float v61; // xmm1_4
  float v62; // xmm0_4
  float v63; // xmm2_4
  float v64; // xmm2_4
  signed __int64 v65; // rsi
  float *v66; // rax
  float *v67; // rcx
  __int64 v68; // rdx
  float v69; // xmm0_4
  float v70; // xmm2_4
  float v71; // xmm2_4

  m_uFFTSize = this->m_uFFTSize;
  v9 = 0;
  v12 = (m_uFFTSize >> 1) + 1;
  v15 = 0;
  v16 = 0i64;
  if ( v12 >= 4 )
  {
    v17 = (char *)in_pPreviousFrame - (char *)in_pNextFrame;
    v18 = in_pNextFrame + 1;
    v19 = 1.0 - in_fInterpLoc;
    v20 = (char *)io_pfFreqData - (char *)in_pNextFrame;
    v21 = (((m_uFFTSize >> 1) - 3) >> 2) + 1;
    v15 = 4 * v21;
    v22 = v21;
    v16 = 4i64 * v21;
    do
    {
      v18 += 4;
      v23 = v19 * *(float *)((char *)&v18[-4].fMag + v17);
      *(float *)((char *)&v18[-5].fMag + v20) = (float)(v19 * *(float *)((char *)&v18[-5].fMag + v17))
                                              + (float)(in_fInterpLoc * v18[-5].fMag);
      v24 = v19 * *(float *)((char *)&v18[-3].fMag + v17);
      *(float *)((char *)&v18[-4].fMag + v20) = v23 + (float)(in_fInterpLoc * v18[-4].fMag);
      v25 = v19 * *(float *)((char *)&v18[-2].fMag + v17);
      *(float *)((char *)&v18[-3].fMag + v20) = v24 + (float)(in_fInterpLoc * v18[-3].fMag);
      *(float *)((char *)&v18[-2].fMag + v20) = v25 + (float)(in_fInterpLoc * v18[-2].fMag);
      --v22;
    }
    while ( v22 );
  }
  if ( v15 < v12 )
  {
    v26 = v12 - v15;
    v27 = &in_pNextFrame[v16];
    do
    {
      ++v27;
      *(float *)((char *)&v27[-1].fMag + (char *)io_pfFreqData - (char *)in_pNextFrame) = (float)((float)(1.0 - in_fInterpLoc)
                                                                                                * *(float *)((char *)&v27[-1].fMag + (char *)in_pPreviousFrame - (char *)in_pNextFrame))
                                                                                        + (float)(in_fInterpLoc
                                                                                                * v27[-1].fMag);
      --v26;
    }
    while ( v26 );
  }
  if ( in_bInitPhases )
  {
    v28 = 0;
    v29 = 0i64;
    if ( v12 >= 4 )
    {
      v30 = io_pPreviousSynthPhases + 2;
      p_fPhase = (char *)&in_pPreviousFrame[1].fPhase;
      v32 = (((m_uFFTSize >> 1) - 3) >> 2) + 1;
      v33 = v32;
      v28 = 4 * v32;
      v29 = 4i64 * v32;
      do
      {
        v34 = *((_DWORD *)p_fPhase - 2);
        v30 += 4;
        p_fPhase += 32;
        *((_DWORD *)v30 - 6) = v34;
        *(v30 - 5) = *((float *)p_fPhase - 8);
        *(v30 - 4) = *((float *)p_fPhase - 6);
        *(v30 - 3) = *((float *)p_fPhase - 4);
        --v33;
      }
      while ( v33 );
    }
    if ( v28 < v12 )
    {
      v35 = &io_pPreviousSynthPhases[v29];
      v36 = &in_pPreviousFrame[v29].fPhase;
      v37 = v12 - v28;
      do
      {
        v38 = *(_DWORD *)v36;
        ++v35;
        v36 += 2;
        *((_DWORD *)v35 - 1) = v38;
        --v37;
      }
      while ( v37 );
    }
  }
  v39 = 0.0;
  v40 = (double)in_uHopSize * 6.283185482025146;
  v41 = (float)(int)m_uFFTSize;
  v42 = 0i64;
  v43 = v40 / v41;
  if ( v12 >= 4 )
  {
    v44 = (char *)io_pfFreqData - (char *)in_pNextFrame;
    v45 = (char *)in_pPreviousFrame - (char *)in_pNextFrame;
    v46 = ((unsigned int)(v12 - 4) >> 2) + 1;
    v47 = io_pPreviousSynthPhases + 2;
    v48 = &in_pNextFrame->fPhase;
    v9 = 4 * v46;
    v42 = 4i64 * v46;
    v49 = v46;
    do
    {
      v50 = *(v47 - 2);
      v51 = *v48 - *(float *)((char *)v48 + v45);
      *(float *)((char *)v48 + v44) = v50;
      v52 = (float)((float)(v51 - v39) + v39) + v50;
      *(v47 - 2) = v52;
      if ( v52 >= 3.1415927 )
      {
        v52 = v52 + -6.2831855;
        *(v47 - 2) = v52;
      }
      if ( v52 < -3.1415927 )
        *(v47 - 2) = v52 + 6.2831855;
      v53 = v39 + v43;
      if ( v53 >= 6.2831855 )
        v53 = v53 + -6.2831855;
      v54 = *(v47 - 1);
      v55 = v48[2] - *(float *)((char *)v48 + v45 + 8);
      *(float *)((char *)v48 + v44 + 8) = v54;
      v56 = (float)((float)(v55 - v53) + v53) + v54;
      *(v47 - 1) = v56;
      if ( v56 >= 3.1415927 )
      {
        v56 = v56 + -6.2831855;
        *(v47 - 1) = v56;
      }
      if ( v56 < -3.1415927 )
        *(v47 - 1) = v56 + 6.2831855;
      v57 = v53 + v43;
      if ( v57 >= 6.2831855 )
        v57 = v57 + -6.2831855;
      v58 = *v47;
      v59 = v48[4] - *(float *)((char *)v48 + v45 + 16);
      *(float *)((char *)v48 + v44 + 16) = *v47;
      v60 = (float)((float)(v59 - v57) + v57) + v58;
      *v47 = v60;
      if ( v60 >= 3.1415927 )
      {
        v60 = v60 + -6.2831855;
        *v47 = v60;
      }
      if ( v60 < -3.1415927 )
        *v47 = v60 + 6.2831855;
      v61 = v57 + v43;
      if ( v61 >= 6.2831855 )
        v61 = v61 + -6.2831855;
      v62 = v47[1];
      v63 = v48[6] - *(float *)((char *)v48 + v45 + 24);
      *(float *)((char *)v48 + v44 + 24) = v62;
      v64 = (float)((float)(v63 - v61) + v61) + v62;
      v47[1] = v64;
      if ( v64 >= 3.1415927 )
      {
        v64 = v64 + -6.2831855;
        v47[1] = v64;
      }
      if ( v64 < -3.1415927 )
        v47[1] = v64 + 6.2831855;
      v39 = v61 + v43;
      if ( v39 >= 6.2831855 )
        v39 = v39 + -6.2831855;
      v47 += 4;
      v48 += 8;
      --v49;
    }
    while ( v49 );
  }
  if ( v9 < v12 )
  {
    v65 = (char *)in_pPreviousFrame - (char *)in_pNextFrame;
    v66 = &io_pPreviousSynthPhases[v42];
    v67 = &in_pNextFrame[v42].fPhase;
    v68 = v12 - v9;
    do
    {
      v69 = *v66;
      v70 = *v67 - *(float *)((char *)v67 + v65);
      *(float *)((char *)v67 + (char *)io_pfFreqData - (char *)in_pNextFrame) = *v66;
      v71 = (float)((float)(v70 - v39) + v39) + v69;
      *v66 = v71;
      if ( v71 >= 3.1415927 )
      {
        v71 = v71 + -6.2831855;
        *v66 = v71;
      }
      if ( v71 < -3.1415927 )
        *v66 = v71 + 6.2831855;
      v39 = v39 + v43;
      if ( v39 >= 6.2831855 )
        v39 = v39 + -6.2831855;
      v67 += 2;
      ++v66;
      --v68;
    }
    while ( v68 );
  }
  *(_WORD *)&this->m_bReady = 257;
}

