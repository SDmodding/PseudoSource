// File Line: 44
// RVA: 0xAE9490
float __fastcall DSP::FDN4::ComputeMaxStableHFRatio(
        int in_uDelayLineLength,
        float in_fDecayTime,
        float in_fHFDecayRatio,
        int in_uSampleRate)
{
  __m128d v4; // xmm8
  double v5; // xmm7_8
  double v6; // xmm0_8
  double v7; // xmm9_8
  double v8; // xmm9_8

  v4 = (__m128d)*(unsigned __int64 *)&DOUBLE_1_0;
  v5 = 1.0 - in_fHFDecayRatio * in_fHFDecayRatio;
  v6 = pow(10.0, (double)in_uDelayLineLength * -3.0 / (in_fDecayTime * (double)in_uSampleRate));
  v7 = log10(v6) * 20.0;
  v8 = v7 * log(10.0) * 0.0125;
  if ( v8 * v5 > 1.0 )
    v5 = 1.0 / v8;
  v4.m128d_f64[0] = 1.0 - v5;
  return _mm_sqrt_pd(v4).m128d_f64[0];
}

// File Line: 74
// RVA: 0xAE93E0
void __fastcall DSP::FDN4::ChangeDecay(
        DSP::FDN4 *this,
        float in_fDecayTime,
        float in_fHFDecayRatio,
        unsigned int in_uSampleRate)
{
  float v6; // xmm6_4

  v6 = DSP::FDN4::ComputeMaxStableHFRatio(
         this->FDNDelayLine[3].uDelayLineLength,
         in_fDecayTime,
         in_fHFDecayRatio,
         in_uSampleRate);
  FDNLPFilter::ComputeFDNLPCoefs(
    this->delayLowPassFilter,
    in_fDecayTime,
    v6,
    in_uSampleRate,
    this->FDNDelayLine[0].uDelayLineLength);
  FDNLPFilter::ComputeFDNLPCoefs(
    &this->delayLowPassFilter[1],
    in_fDecayTime,
    v6,
    in_uSampleRate,
    this->FDNDelayLine[1].uDelayLineLength);
  FDNLPFilter::ComputeFDNLPCoefs(
    &this->delayLowPassFilter[2],
    in_fDecayTime,
    v6,
    in_uSampleRate,
    this->FDNDelayLine[2].uDelayLineLength);
  FDNLPFilter::ComputeFDNLPCoefs(
    &this->delayLowPassFilter[3],
    in_fDecayTime,
    v6,
    in_uSampleRate,
    this->FDNDelayLine[3].uDelayLineLength);
}

// File Line: 90
// RVA: 0xAE82A0
__int64 __fastcall DSP::FDN4::Init(
        DSP::FDN4 *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int *in_uDelayLineLength,
        float in_fDecayTime,
        float in_fHFDecayRatio,
        unsigned int in_uSampleRate)
{
  float v9; // xmm0_4
  __int64 result; // rax

  v9 = DSP::FDN4::ComputeMaxStableHFRatio(in_uDelayLineLength[3], in_fDecayTime, in_fHFDecayRatio, in_uSampleRate);
  result = DSP::DelayLine::Init(this->FDNDelayLine, in_pAllocator, *in_uDelayLineLength);
  if ( (_DWORD)result == 1 )
  {
    result = DSP::DelayLine::Init(&this->FDNDelayLine[1], in_pAllocator, in_uDelayLineLength[1]);
    if ( (_DWORD)result == 1 )
    {
      result = DSP::DelayLine::Init(&this->FDNDelayLine[2], in_pAllocator, in_uDelayLineLength[2]);
      if ( (_DWORD)result == 1 )
      {
        result = DSP::DelayLine::Init(&this->FDNDelayLine[3], in_pAllocator, in_uDelayLineLength[3]);
        if ( (_DWORD)result == 1 )
        {
          FDNLPFilter::ComputeFDNLPCoefs(
            this->delayLowPassFilter,
            in_fDecayTime,
            v9,
            in_uSampleRate,
            *in_uDelayLineLength);
          FDNLPFilter::ComputeFDNLPCoefs(
            &this->delayLowPassFilter[1],
            in_fDecayTime,
            v9,
            in_uSampleRate,
            in_uDelayLineLength[1]);
          FDNLPFilter::ComputeFDNLPCoefs(
            &this->delayLowPassFilter[2],
            in_fDecayTime,
            v9,
            in_uSampleRate,
            in_uDelayLineLength[2]);
          FDNLPFilter::ComputeFDNLPCoefs(
            &this->delayLowPassFilter[3],
            in_fDecayTime,
            v9,
            in_uSampleRate,
            in_uDelayLineLength[3]);
          return 1i64;
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
  DSP::DelayLine::Term(this->FDNDelayLine, in_pAllocator);
  DSP::DelayLine::Term(&this->FDNDelayLine[1], in_pAllocator);
  DSP::DelayLine::Term(&this->FDNDelayLine[2], in_pAllocator);
  DSP::DelayLine::Term(&this->FDNDelayLine[3], in_pAllocator);
}

// File Line: 123
// RVA: 0xAE8430
void __fastcall DSP::FDN4::Reset(DSP::FDN4 *this)
{
  DSP::DelayLine::Reset(this->FDNDelayLine);
  DSP::DelayLine::Reset(&this->FDNDelayLine[1]);
  DSP::DelayLine::Reset(&this->FDNDelayLine[2]);
  DSP::DelayLine::Reset(&this->FDNDelayLine[3]);
  this->delayLowPassFilter[0].fFFbk1 = 0.0;
  this->delayLowPassFilter[1].fFFbk1 = 0.0;
  this->delayLowPassFilter[2].fFFbk1 = 0.0;
  this->delayLowPassFilter[3].fFFbk1 = 0.0;
}

