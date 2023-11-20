// File Line: 61
// RVA: 0xB06ED0
void __fastcall ProcessFutzEQChannel(FutzBoxEQFilterMemoryMap *memoryMap, const float *inputBuf, float *outputBuf, unsigned int samplesRemaining)
{
  float v4; // xmm5_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm7_4
  float v8; // xmm8_4
  float v9; // xmm6_4
  float v10; // xmm11_4
  float v11; // xmm9_4
  float v12; // xmm10_4
  signed __int64 v13; // rdx
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm2_4

  v4 = memoryMap->YMemory[0];
  v5 = memoryMap->YMemory[1];
  v6 = memoryMap->YMemory[3];
  v7 = memoryMap->XMemory[0];
  v8 = memoryMap->XMemory[1];
  v9 = memoryMap->YMemory[2];
  v10 = memoryMap->XMemory[4];
  v11 = memoryMap->XMemory[2];
  v12 = memoryMap->XMemory[3];
  if ( samplesRemaining )
  {
    v13 = (char *)inputBuf - (char *)outputBuf;
    do
    {
      v14 = *(float *)((char *)outputBuf + v13);
      ++outputBuf;
      v15 = (float)((float)(v4 * v8) + (float)(v7 * v14)) + (float)(v5 * v11);
      v5 = v4;
      v4 = v14;
      v16 = (float)(v15 - (float)(v9 * v12)) - (float)(v6 * v10);
      v6 = v9;
      *(outputBuf - 1) = v16;
      v9 = v16;
      --samplesRemaining;
    }
    while ( samplesRemaining );
  }
  memoryMap->YMemory[0] = v4;
  memoryMap->YMemory[1] = v5;
  memoryMap->YMemory[2] = v9;
  memoryMap->YMemory[3] = v6;
}

// File Line: 84
// RVA: 0xB06AF0
char *__fastcall ProcessFutzBoxEQFilterWwise(char *memoryBlock, float *pfChannelIn, float *pfChannelOut, unsigned int uNumSamples)
{
  __int64 v4; // rcx

  ProcessFutzEQChannel((FutzBoxEQFilterMemoryMap *)memoryBlock, pfChannelIn, pfChannelOut, uNumSamples);
  return (char *)(v4 + 48);
}

// File Line: 109
// RVA: 0xB06B10
void __fastcall FutzEQFilterMemoryMapHelper::FutzEQFilterMemoryMapHelper(FutzEQFilterMemoryMapHelper *this)
{
  FutzEQFilterMemoryMapHelper *v1; // rbx

  v1 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->0);
  v1->FutzBoxMemMapPtr = 0i64;
}

// File Line: 115
// RVA: 0xB06B40
void __fastcall FutzEQFilterMemoryMapHelper::~FutzEQFilterMemoryMapHelper(FutzEQFilterMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->0);
}

// File Line: 121
// RVA: 0xB06B50
signed __int64 __fastcall FutzEQFilterMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 48i64 * numChannels;
}

// File Line: 131
// RVA: 0xB06B70
__int64 __fastcall FutzEQFilterMemoryMapHelper::Init(FutzEQFilterMemoryMapHelper *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzEQFilterMemoryMapHelper *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  v4 = this;
  this->mSampleRate = sampleRate;
  v5 = 48i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x30ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->FutzBoxMemMapPtr = (FutzBoxEQFilterMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 148
// RVA: 0xB06BD0
FutzBoxEQFilterMemoryMap *__fastcall FutzEQFilterMemoryMapHelper::GetMemoryMap(FutzEQFilterMemoryMapHelper *this, unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 157
// RVA: 0xB06BF0
void __fastcall FutzEQFilterMemoryMapHelper::SetEQ(FutzEQFilterMemoryMapHelper *this, FutzEQParameters *eqParams)
{
  FutzEQFilterMemoryMapHelper *v2; // rbx
  FutzEQParameters *v3; // rdi
  FutzEQType v4; // ecx
  int v5; // ecx
  __m128d v6; // xmm1
  __m128d v7; // xmm1
  __int64 v8; // rdi
  SCoefs outCoefs; // [rsp+30h] [rbp-38h]

  v2 = this;
  v3 = eqParams;
  CoefficientCalculator::CalculateBypassed(&outCoefs);
  if ( !v3->bypassed )
  {
    v4 = v3->type;
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          v6 = (__m128d)*(unsigned __int64 *)&v3->q;
          v6.m128d_f64[0] = v6.m128d_f64[0] * 0.01;
          if ( v6.m128d_f64[0] > 0.0 )
            *(_QWORD *)&v6.m128d_f64[0] = (unsigned __int128)_mm_sqrt_pd(v6);
          CoefficientCalculator::CalculateSecondOrderLowPass(
            v2->mSampleRate,
            v3->frequency,
            (1.0 - v6.m128d_f64[0] * 0.8) * 1.414,
            &outCoefs);
        }
      }
      else
      {
        CoefficientCalculator::CalculateParametric(
          v2->mSampleRate,
          v3->frequency,
          v3->q * 0.01 * (v3->q * 0.01) * 9.0 + 1.0,
          v3->gain,
          &outCoefs);
      }
    }
    else
    {
      v7 = (__m128d)*(unsigned __int64 *)&v3->q;
      v7.m128d_f64[0] = v7.m128d_f64[0] * 0.01;
      if ( v7.m128d_f64[0] > 0.0 )
        *(_QWORD *)&v7.m128d_f64[0] = (unsigned __int128)_mm_sqrt_pd(v7);
      CoefficientCalculator::CalculateSecondOrderHighPass(
        v2->mSampleRate,
        v3->frequency,
        (1.0 - v7.m128d_f64[0] * 0.8) * 1.414,
        &outCoefs);
    }
  }
  v8 = 0i64;
  if ( v2->mNumChannels )
  {
    do
    {
      DSPMemoryMapHelper::SetFilterCoefs(&v2->0, &outCoefs, v2->FutzBoxMemMapPtr[v8].XMemory, 0);
      v8 = (unsigned int)(v8 + 1);
    }
    while ( (unsigned int)v8 < v2->mNumChannels );
  }
}

// File Line: 215
// RVA: 0xB06D40
void __fastcall FutzEQFilterImpl::FutzEQFilterImpl(FutzEQFilterImpl *this)
{
  FutzEQFilterImpl *v1; // rbx

  v1 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper.0);
  v1->MemoryMapHelper.FutzBoxMemMapPtr = 0i64;
}

// File Line: 221
// RVA: 0xB06D70
void __fastcall FutzEQFilterImpl::~FutzEQFilterImpl(FutzEQFilterImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper.0);
}

// File Line: 228
// RVA: 0xB06D80
signed __int64 __fastcall FutzEQFilterImpl::GetMemoryMapSize(FutzEQFilterImpl *this, unsigned int numChannels)
{
  return 48i64 * numChannels;
}

// File Line: 237
// RVA: 0xB06DA0
__int64 __fastcall FutzEQFilterImpl::Init(FutzEQFilterImpl *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzEQFilterImpl *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->m_uNumTailFrames = 0;
  this->MemoryMapHelper.mNumChannels = numChannels;
  v4 = this;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 48i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x30ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxEQFilterMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 247
// RVA: 0xB06E70
void __fastcall FutzEQFilterImpl::ComputeTailLength(FutzEQFilterImpl *this, FutzBoxEQFilterMemoryMap *memoryMap)
{
  BiquadCoefficients in_coeffs; // [rsp+20h] [rbp-28h]

  in_coeffs.a0 = memoryMap->XMemory[0];
  in_coeffs.a1 = memoryMap->XMemory[1];
  in_coeffs.a2 = memoryMap->XMemory[2];
  in_coeffs.b1 = memoryMap->XMemory[3];
  in_coeffs.b2 = memoryMap->XMemory[4];
  this->m_uNumTailFrames = (signed int)(CoefficientCalculator::CalculateDecayTime(&in_coeffs) * 6.91);
}

// File Line: 259
// RVA: 0xB06E00
void __fastcall FutzEQFilterImpl::SetParameters(FutzEQFilterImpl *this, FutzEQParameters *eqParams)
{
  FutzEQFilterImpl *v2; // rbx
  float *v3; // rdx
  BiquadCoefficients in_coeffs; // [rsp+20h] [rbp-28h]

  v2 = this;
  FutzEQFilterMemoryMapHelper::SetEQ(&this->MemoryMapHelper, eqParams);
  v3 = v2->MemoryMapHelper.FutzBoxMemMapPtr->XMemory;
  in_coeffs.a0 = *v3;
  in_coeffs.a1 = v3[1];
  in_coeffs.a2 = v3[2];
  in_coeffs.b1 = v3[3];
  in_coeffs.b2 = v3[4];
  v2->m_uNumTailFrames = (signed int)(CoefficientCalculator::CalculateDecayTime(&in_coeffs) * 6.91);
}

