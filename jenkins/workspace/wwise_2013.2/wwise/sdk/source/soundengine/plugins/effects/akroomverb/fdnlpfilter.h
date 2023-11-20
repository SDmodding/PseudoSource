// File Line: 30
// RVA: 0xAE9570
void __fastcall FDNLPFilter::ComputeFDNLPCoefs(FDNLPFilter *this, float in_fDecayTime, float in_fHFDecayRatio, unsigned int in_uSampleRate, unsigned int in_uFDNDelayLength)
{
  FDNLPFilter *v5; // rbx
  double v6; // xmm9_8
  double v7; // xmm8_8
  double v8; // xmm8_8
  float v9; // xmm0_4
  float v10; // xmm0_4

  v5 = this;
  v6 = pow(10.0, (double)(signed int)in_uFDNDelayLength * -3.0 / (in_fDecayTime * (double)(signed int)in_uSampleRate));
  v7 = log10(v6) * 20.0;
  v8 = v7 * log(10.0) * 0.0125 * (1.0 - in_fHFDecayRatio * in_fHFDecayRatio);
  if ( v8 > 0.999 )
    v8 = DOUBLE_0_999;
  v9 = (1.0 - v8) * v6;
  v5->fB0 = v9;
  v10 = -v8;
  v5->fA1 = v10;
}

