// File Line: 44
// RVA: 0xAE9490
float __fastcall DSP::FDN4::ComputeMaxStableHFRatio(unsigned int in_uDelayLineLength, float in_fDecayTime, float in_fHFDecayRatio, unsigned int in_uSampleRate)
{
  __m128d v4; // xmm8
  double v5; // xmm7_8
  double v6; // xmm0_8
  double v7; // xmm9_8
  double v8; // xmm9_8

  v4 = (__m128d)*(unsigned __int64 *)&DOUBLE_1_0;
  v5 = 1.0 - in_fHFDecayRatio * in_fHFDecayRatio;
  v6 = pow(10.0, (double)(signed int)in_uDelayLineLength * -3.0 / (in_fDecayTime * (double)(signed int)in_uSampleRate));
  v7 = log10(v6) * 20.0;
  v8 = v7 * log(10.0) * 0.0125;
  if ( v8 * v5 > 1.0 )
    v5 = v4.m128d_f64[0] / v8;
  v4.m128d_f64[0] = 1.0 - v5;
  return COERCE_DOUBLE(_mm_sqrt_pd(v4));
}

// File Line: 74
// RVA: 0xAE93E0
void __fastcall DSP::FDN4::ChangeDecay(DSP::FDN4 *this, float in_fDecayTime, float in_fHFDecayRatio, unsigned int in_uSampleRate)
{
  DSP::FDN4 *v4; // rbx
  unsigned int v5; // edi
  float v6; // xmm6_4

  v4 = this;
  v5 = in_uSampleRate;
  v6 = DSP::FDN4::ComputeMaxStableHFRatio(
         this->FDNDelayLine[3].uDelayLineLength,
         in_fDecayTime,
         in_fHFDecayRatio,
         in_uSampleRate);
  FDNLPFilter::ComputeFDNLPCoefs(v4->delayLowPassFilter, in_fDecayTime, v6, v5, v4->FDNDelayLine[0].uDelayLineLength);
  FDNLPFilter::ComputeFDNLPCoefs(
    &v4->delayLowPassFilter[1],
    in_fDecayTime,
    v6,
    v5,
    v4->FDNDelayLine[1].uDelayLineLength);
  FDNLPFilter::ComputeFDNLPCoefs(
    &v4->delayLowPassFilter[2],
    in_fDecayTime,
    v6,
    v5,
    v4->FDNDelayLine[2].uDelayLineLength);
  FDNLPFilter::ComputeFDNLPCoefs(
    &v4->delayLowPassFilter[3],
    in_fDecayTime,
    v6,
    v5,
    v4->FDNDelayLine[3].uDelayLineLength);
}

// File Line: 90
// RVA: 0xAE82A0
signed __int64 __fastcall DSP::FDN4::Init(DSP::FDN4 *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int *in_uDelayLineLength, float in_fDecayTime, float in_fHFDecayRatio, unsigned int in_uSampleRate)
{
  DSP::FDN4 *v6; // rdi
  unsigned int *v7; // rbx
  AK::IAkPluginMemAlloc *v8; // rsi
  float v9; // xmm7_4
  signed __int64 result; // rax

  v6 = this;
  v7 = in_uDelayLineLength;
  v8 = in_pAllocator;
  v9 = DSP::FDN4::ComputeMaxStableHFRatio(in_uDelayLineLength[3], in_fDecayTime, in_fHFDecayRatio, in_uSampleRate);
  result = DSP::DelayLine::Init(v6->FDNDelayLine, v8, *v7);
  if ( (_DWORD)result == 1 )
  {
    result = DSP::DelayLine::Init(&v6->FDNDelayLine[1], v8, v7[1]);
    if ( (_DWORD)result == 1 )
    {
      result = DSP::DelayLine::Init(&v6->FDNDelayLine[2], v8, v7[2]);
      if ( (_DWORD)result == 1 )
      {
        result = DSP::DelayLine::Init(&v6->FDNDelayLine[3], v8, v7[3]);
        if ( (_DWORD)result == 1 )
        {
          FDNLPFilter::ComputeFDNLPCoefs(v6->delayLowPassFilter, in_fDecayTime, v9, in_uSampleRate, *v7);
          FDNLPFilter::ComputeFDNLPCoefs(&v6->delayLowPassFilter[1], in_fDecayTime, v9, in_uSampleRate, v7[1]);
          FDNLPFilter::ComputeFDNLPCoefs(&v6->delayLowPassFilter[2], in_fDecayTime, v9, in_uSampleRate, v7[2]);
          FDNLPFilter::ComputeFDNLPCoefs(&v6->delayLowPassFilter[3], in_fDecayTime, v9, in_uSampleRate, v7[3]);
          result = 1i64;
        }
      }
    }
  }
  return result;
}

// File Line: 115
// RVA: 0xAE83E0
void __fastcall DSP::FDN4::Term(DSP::FDN4 *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  DSP::FDN4 *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  DSP::DelayLine::Term(this->FDNDelayLine, in_pAllocator);
  DSP::DelayLine::Term(&v3->FDNDelayLine[1], v2);
  DSP::DelayLine::Term(&v3->FDNDelayLine[2], v2);
  DSP::DelayLine::Term(&v3->FDNDelayLine[3], v2);
}

// File Line: 123
// RVA: 0xAE8430
void __fastcall DSP::FDN4::Reset(DSP::FDN4 *this)
{
  DSP::FDN4 *v1; // rbx

  v1 = this;
  DSP::DelayLine::Reset(this->FDNDelayLine);
  DSP::DelayLine::Reset(&v1->FDNDelayLine[1]);
  DSP::DelayLine::Reset(&v1->FDNDelayLine[2]);
  DSP::DelayLine::Reset(&v1->FDNDelayLine[3]);
  v1->delayLowPassFilter[0].fFFbk1 = 0.0;
  v1->delayLowPassFilter[1].fFFbk1 = 0.0;
  v1->delayLowPassFilter[2].fFFbk1 = 0.0;
  v1->delayLowPassFilter[3].fFFbk1 = 0.0;
}

