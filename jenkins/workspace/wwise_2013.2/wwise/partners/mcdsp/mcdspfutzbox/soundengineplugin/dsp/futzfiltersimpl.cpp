// File Line: 101
// RVA: 0xB05160
void __fastcall ProcessFutzFiltersChannel(FutzBoxFiltersMemoryMap *memoryMap, const float *inputBuf, float *outputBuf, unsigned int samplesRemaining)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm11_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm14_4
  float v14; // xmm15_4
  float v15; // xmm8_4
  float v16; // xmm9_4
  float v17; // xmm10_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  signed __int64 v20; // rdx
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // [rsp+0h] [rbp-108h]
  float v35; // [rsp+4h] [rbp-104h]
  float v36; // [rsp+8h] [rbp-100h]
  float v37; // [rsp+Ch] [rbp-FCh]
  float v38; // [rsp+10h] [rbp-F8h]
  float v39; // [rsp+14h] [rbp-F4h]
  float v40; // [rsp+18h] [rbp-F0h]
  float v41; // [rsp+1Ch] [rbp-ECh]
  float v42; // [rsp+20h] [rbp-E8h]
  float v43; // [rsp+24h] [rbp-E4h]
  float v44; // [rsp+28h] [rbp-E0h]
  float v45; // [rsp+2Ch] [rbp-DCh]
  float v46; // [rsp+30h] [rbp-D8h]
  float v47; // [rsp+34h] [rbp-D4h]
  float v48; // [rsp+38h] [rbp-D0h]
  float v49; // [rsp+3Ch] [rbp-CCh]
  float v50; // [rsp+40h] [rbp-C8h]
  float v51; // [rsp+44h] [rbp-C4h]
  float v52; // [rsp+48h] [rbp-C0h]
  float v53; // [rsp+4Ch] [rbp-BCh]
  float v54; // [rsp+50h] [rbp-B8h]
  float v55; // [rsp+110h] [rbp+8h]
  float v56; // [rsp+128h] [rbp+20h]

  v4 = memoryMap->YMemory[21];
  v5 = memoryMap->YMemory[0];
  v6 = memoryMap->YMemory[2];
  v7 = memoryMap->YMemory[6];
  v8 = memoryMap->YMemory[1];
  v9 = memoryMap->YMemory[8];
  v10 = memoryMap->YMemory[12];
  v11 = memoryMap->YMemory[3];
  v12 = memoryMap->YMemory[7];
  v13 = memoryMap->YMemory[9];
  v14 = memoryMap->YMemory[13];
  v15 = memoryMap->YMemory[14];
  v16 = memoryMap->YMemory[18];
  v17 = memoryMap->YMemory[20];
  v37 = memoryMap->XMemory[0];
  v45 = memoryMap->XMemory[1];
  v48 = memoryMap->XMemory[15];
  v53 = memoryMap->XMemory[2];
  v39 = memoryMap->XMemory[3];
  v46 = memoryMap->XMemory[16];
  v47 = memoryMap->XMemory[4];
  v51 = memoryMap->XMemory[5];
  v50 = memoryMap->XMemory[17];
  v41 = memoryMap->XMemory[6];
  v43 = memoryMap->XMemory[7];
  v52 = memoryMap->XMemory[18];
  v49 = memoryMap->XMemory[8];
  v35 = memoryMap->XMemory[9];
  v54 = memoryMap->XMemory[19];
  v18 = memoryMap->YMemory[19];
  v38 = memoryMap->XMemory[10];
  v36 = memoryMap->XMemory[11];
  v55 = memoryMap->YMemory[19];
  v40 = memoryMap->XMemory[12];
  v34 = memoryMap->YMemory[21];
  v42 = memoryMap->XMemory[13];
  v44 = memoryMap->XMemory[14];
  v19 = memoryMap->YMemory[15];
  v56 = memoryMap->YMemory[15];
  if ( samplesRemaining )
  {
    v20 = (char *)inputBuf - (char *)outputBuf;
    do
    {
      v21 = *(float *)((char *)outputBuf + v20);
      ++outputBuf;
      v22 = (float)((float)(v5 * v45) + (float)(v37 * v21)) + (float)(v8 * v53);
      v8 = v5;
      v5 = v21;
      v23 = (float)(v22 - (float)(v6 * v39)) - (float)(v11 * v47);
      v11 = v6;
      v6 = v23;
      v24 = (float)((float)(v7 * v41) + (float)(v51 * v23)) + (float)(v12 * v43);
      v12 = v7;
      v7 = v23;
      v25 = (float)(v24 - (float)(v9 * v49)) - (float)(v13 * v35);
      v13 = v9;
      v9 = v25;
      v26 = (float)((float)(v10 * v36) + (float)(v38 * v25)) + (float)(v14 * v40);
      v14 = v10;
      v10 = v25;
      v27 = v56 * v44;
      v56 = v15;
      v28 = (float)(v26 - (float)(v15 * v42)) - v27;
      v15 = v28;
      v29 = (float)(v16 * v46) + (float)(v48 * v28);
      v30 = v55;
      v55 = v16;
      v16 = v28;
      v4 = v17;
      v31 = (float)(v29 + (float)(v30 * v50)) - (float)(v17 * v52);
      v32 = v34;
      v34 = v17;
      v33 = v31 - (float)(v32 * v54);
      *(outputBuf - 1) = v33;
      v17 = v33;
      --samplesRemaining;
    }
    while ( samplesRemaining );
    v19 = v56;
    v18 = v55;
  }
  memoryMap->YMemory[12] = v10;
  memoryMap->YMemory[18] = v16;
  memoryMap->YMemory[0] = v5;
  memoryMap->YMemory[6] = v7;
  memoryMap->YMemory[1] = v8;
  memoryMap->YMemory[7] = v12;
  memoryMap->YMemory[13] = v14;
  memoryMap->YMemory[19] = v18;
  memoryMap->YMemory[8] = v9;
  memoryMap->YMemory[14] = v15;
  memoryMap->YMemory[20] = v17;
  memoryMap->YMemory[2] = v6;
  memoryMap->YMemory[3] = v11;
  memoryMap->YMemory[9] = v13;
  memoryMap->YMemory[15] = v19;
  memoryMap->YMemory[21] = v4;
}

// File Line: 140
// RVA: 0xB04C20
char *__fastcall ProcessFutzBoxFiltersWwise(char *memoryBlock, float *pfChannelIn, float *pfChannelOut, unsigned int uNumSamples)
{
  __int64 v4; // rcx

  ProcessFutzFiltersChannel((FutzBoxFiltersMemoryMap *)memoryBlock, pfChannelIn, pfChannelOut, uNumSamples);
  return (char *)(v4 + 192);
}

// File Line: 166
// RVA: 0xB04C40
void __fastcall FutzFiltersMemoryMapHelper::FutzFiltersMemoryMapHelper(FutzFiltersMemoryMapHelper *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->0);
}

// File Line: 172
// RVA: 0xB04C60
void __fastcall FutzFiltersMemoryMapHelper::~FutzFiltersMemoryMapHelper(FutzFiltersMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->0);
}

// File Line: 178
// RVA: 0xB04C70
signed __int64 __fastcall FutzFiltersMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 192i64 * numChannels;
}

// File Line: 187
// RVA: 0xB04C90
__int64 __fastcall FutzFiltersMemoryMapHelper::Init(FutzFiltersMemoryMapHelper *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzFiltersMemoryMapHelper *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  v4 = this;
  this->mSampleRate = sampleRate;
  v5 = 192i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0xC0ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->FutzBoxMemMapPtr = (FutzBoxFiltersMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 204
// RVA: 0xB04CF0
FutzBoxFiltersMemoryMap *__fastcall FutzFiltersMemoryMapHelper::GetMemoryMap(FutzFiltersMemoryMapHelper *this, unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 213
// RVA: 0xB04D10
void __fastcall FutzFiltersMemoryMapHelper::SetHighPassFilter(FutzFiltersMemoryMapHelper *this, FutzFilterParameters *hpfFilterParams)
{
  FutzFilterParameters *v2; // rbx
  FutzFiltersMemoryMapHelper *v3; // rdi
  __m128d v4; // xmm1
  double v5; // xmm6_8
  __int64 v6; // rsi
  SCoefs coefs; // [rsp+20h] [rbp-78h]
  SCoefs outCoefs; // [rsp+50h] [rbp-48h]

  v2 = hpfFilterParams;
  v3 = this;
  if ( hpfFilterParams->bypassed )
  {
    CoefficientCalculator::CalculateBypassed(&outCoefs);
    CoefficientCalculator::CalculateBypassed(&coefs);
  }
  else
  {
    v4 = (__m128d)*(unsigned __int64 *)&hpfFilterParams->peakPercent;
    v4.m128d_f64[0] = v4.m128d_f64[0] * 0.01;
    if ( v4.m128d_f64[0] > 0.0 )
      *(_QWORD *)&v4.m128d_f64[0] = (unsigned __int128)_mm_sqrt_pd(v4);
    v5 = (1.0 - v4.m128d_f64[0] * 0.8) * 1.414;
    CoefficientCalculator::CalculateSecondOrderHighPass(this->mSampleRate, hpfFilterParams->frequency, v5, &outCoefs);
    if ( v2->slope == 1 )
      CoefficientCalculator::CalculateSecondOrderHighPass(v3->mSampleRate, v2->frequency, v5, &coefs);
    else
      CoefficientCalculator::CalculateBypassed(&coefs);
  }
  v6 = 0i64;
  if ( v3->mNumChannels )
  {
    do
    {
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &outCoefs, v3->FutzBoxMemMapPtr[v6].XMemory, 0);
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &coefs, v3->FutzBoxMemMapPtr[v6].XMemory, 5);
      v6 = (unsigned int)(v6 + 1);
    }
    while ( (unsigned int)v6 < v3->mNumChannels );
  }
}

// File Line: 250
// RVA: 0xB04E30
void __fastcall FutzFiltersMemoryMapHelper::SetLowPassFilter(FutzFiltersMemoryMapHelper *this, FutzFilterParameters *lpfFilterParams)
{
  FutzFilterParameters *v2; // rbx
  FutzFiltersMemoryMapHelper *v3; // rdi
  __m128d v4; // xmm1
  double v5; // xmm6_8
  __int64 v6; // rsi
  SCoefs coefs; // [rsp+20h] [rbp-78h]
  SCoefs outCoefs; // [rsp+50h] [rbp-48h]

  v2 = lpfFilterParams;
  v3 = this;
  if ( lpfFilterParams->bypassed )
  {
    CoefficientCalculator::CalculateBypassed(&outCoefs);
    CoefficientCalculator::CalculateBypassed(&coefs);
  }
  else
  {
    v4 = (__m128d)*(unsigned __int64 *)&lpfFilterParams->peakPercent;
    v4.m128d_f64[0] = v4.m128d_f64[0] * 0.01;
    if ( v4.m128d_f64[0] > 0.0 )
      *(_QWORD *)&v4.m128d_f64[0] = (unsigned __int128)_mm_sqrt_pd(v4);
    v5 = (1.0 - v4.m128d_f64[0] * 0.8) * 1.414;
    CoefficientCalculator::CalculateSecondOrderLowPass(this->mSampleRate, lpfFilterParams->frequency, v5, &outCoefs);
    if ( v2->slope == 1 )
      CoefficientCalculator::CalculateSecondOrderLowPass(v3->mSampleRate, v2->frequency, v5, &coefs);
    else
      CoefficientCalculator::CalculateBypassed(&coefs);
  }
  v6 = 0i64;
  if ( v3->mNumChannels )
  {
    do
    {
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &outCoefs, v3->FutzBoxMemMapPtr[v6].XMemory, 10);
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &coefs, v3->FutzBoxMemMapPtr[v6].XMemory, 15);
      v6 = (unsigned int)(v6 + 1);
    }
    while ( (unsigned int)v6 < v3->mNumChannels );
  }
}

// File Line: 290
// RVA: 0xB04F50
void __fastcall FutzFiltersImpl::FutzFiltersImpl(FutzFiltersImpl *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper.0);
}

// File Line: 296
// RVA: 0xB04F70
void __fastcall FutzFiltersImpl::~FutzFiltersImpl(FutzFiltersImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper.0);
}

// File Line: 303
// RVA: 0xB04F80
signed __int64 __fastcall FutzFiltersImpl::GetMemoryMapSize(FutzFiltersImpl *this, unsigned int numChannels)
{
  return 192i64 * numChannels;
}

// File Line: 312
// RVA: 0xB04FA0
__int64 __fastcall FutzFiltersImpl::Init(FutzFiltersImpl *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzFiltersImpl *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->m_uNumTailFrames = 0;
  this->MemoryMapHelper.mNumChannels = numChannels;
  v4 = this;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 192i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0xC0ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxFiltersMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 321
// RVA: 0xB05040
void __fastcall FutzFiltersImpl::ComputeTailLength(FutzFiltersImpl *this, FutzBoxFiltersMemoryMap *memoryMap)
{
  FutzFiltersImpl *v2; // rbx
  float v3; // xmm6_4
  float v4; // xmm8_4
  float v5; // xmm7_4
  float v6; // xmm0_4
  BiquadCoefficients in_coeffs; // [rsp+18h] [rbp-39h]
  BiquadCoefficients v8; // [rsp+30h] [rbp-21h]
  BiquadCoefficients v9; // [rsp+48h] [rbp-9h]
  BiquadCoefficients v10; // [rsp+60h] [rbp+Fh]

  v2 = this;
  in_coeffs.a0 = memoryMap->XMemory[0];
  in_coeffs.a1 = memoryMap->XMemory[1];
  in_coeffs.a2 = memoryMap->XMemory[2];
  in_coeffs.b1 = memoryMap->XMemory[3];
  in_coeffs.b2 = memoryMap->XMemory[4];
  v8.a0 = memoryMap->XMemory[5];
  v8.a1 = memoryMap->XMemory[6];
  v8.a2 = memoryMap->XMemory[7];
  v8.b1 = memoryMap->XMemory[8];
  v8.b2 = memoryMap->XMemory[9];
  v9.a0 = memoryMap->XMemory[10];
  v9.a1 = memoryMap->XMemory[11];
  v9.a2 = memoryMap->XMemory[12];
  v9.b1 = memoryMap->XMemory[13];
  v9.b2 = memoryMap->XMemory[14];
  v10.a0 = memoryMap->XMemory[15];
  v10.a1 = memoryMap->XMemory[16];
  v10.a2 = memoryMap->XMemory[17];
  v10.b1 = memoryMap->XMemory[18];
  v10.b2 = memoryMap->XMemory[19];
  v3 = CoefficientCalculator::CalculateDecayTime((BiquadCoefficients *)((char *)&in_coeffs + 8));
  v4 = CoefficientCalculator::CalculateDecayTime(&v8);
  v5 = CoefficientCalculator::CalculateDecayTime(&v9);
  v6 = CoefficientCalculator::CalculateDecayTime(&v10);
  if ( v3 <= v5 )
    v3 = v5;
  if ( v3 == v4 || v3 == v6 )
    v3 = v3 * 1.6931472;
  v2->m_uNumTailFrames = (signed int)(v3 * 6.91);
}

// File Line: 346
// RVA: 0xB05000
void __fastcall FutzFiltersImpl::SetParameters(FutzFiltersImpl *this, FutzFilterParameters *hpfFilterParams, FutzFilterParameters *lpfFilterParams)
{
  FutzFilterParameters *v3; // rbx
  FutzFiltersImpl *v4; // rdi

  v3 = lpfFilterParams;
  v4 = this;
  FutzFiltersMemoryMapHelper::SetHighPassFilter(&this->MemoryMapHelper, hpfFilterParams);
  FutzFiltersMemoryMapHelper::SetLowPassFilter(&v4->MemoryMapHelper, v3);
  FutzFiltersImpl::ComputeTailLength(v4, v4->MemoryMapHelper.FutzBoxMemMapPtr);
}

