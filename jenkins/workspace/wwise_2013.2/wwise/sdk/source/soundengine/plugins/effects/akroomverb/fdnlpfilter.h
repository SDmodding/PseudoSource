// File Line: 30
// RVA: 0xAE9570
void __fastcall FDNLPFilter::ComputeFDNLPCoefs(
        FDNLPFilter *this,
        float in_fDecayTime,
        float in_fHFDecayRatio,
        int in_uSampleRate,
        signed int in_uFDNDelayLength)
{
  double v6; // xmm9_8
  double v7; // xmm8_8
  double v8; // xmm8_8
  float v9; // xmm0_4
  float v10; // xmm0_4

  v6 = pow(10.0, (double)in_uFDNDelayLength * -3.0 / (in_fDecayTime * (double)in_uSampleRate));
  v7 = log10(v6) * 20.0;
  v8 = v7 * log(10.0) * 0.0125 * (1.0 - in_fHFDecayRatio * in_fHFDecayRatio);
  if ( v8 > 0.999 )
    v8 = DOUBLE_0_999;
  v9 = (1.0 - v8) * v6;
  this->fB0 = v9;
  v10 = -v8;
  this->fA1 = v10;
}

