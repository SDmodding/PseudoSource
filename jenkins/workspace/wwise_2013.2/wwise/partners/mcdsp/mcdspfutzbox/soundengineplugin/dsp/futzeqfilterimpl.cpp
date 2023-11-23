// File Line: 61
// RVA: 0xB06ED0
void __fastcall ProcessFutzEQChannel(
        FutzBoxEQFilterMemoryMap *memoryMap,
        const float *inputBuf,
        float *outputBuf,
        unsigned int samplesRemaining)
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
      v14 = *(float *)((char *)outputBuf++ + v13);
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
char *__fastcall ProcessFutzBoxEQFilterWwise(
        FutzBoxEQFilterMemoryMap *memoryBlock,
        const float *pfChannelIn,
        float *pfChannelOut,
        unsigned int uNumSamples)
{
  __int64 v4; // rcx

  ProcessFutzEQChannel(memoryBlock, pfChannelIn, pfChannelOut, uNumSamples);
  return (char *)(v4 + 48);
}

// File Line: 109
// RVA: 0xB06B10
void __fastcall FutzEQFilterMemoryMapHelper::FutzEQFilterMemoryMapHelper(FutzEQFilterMemoryMapHelper *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(this);
  this->FutzBoxMemMapPtr = 0i64;
}

// File Line: 115
// RVA: 0xB06B40
// attributes: thunk
void __fastcall FutzEQFilterMemoryMapHelper::~FutzEQFilterMemoryMapHelper(FutzEQFilterMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(this);
}

// File Line: 121
// RVA: 0xB06B50
__int64 __fastcall FutzEQFilterMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 48i64 * numChannels;
}

// File Line: 131
// RVA: 0xB06B70
__int64 __fastcall FutzEQFilterMemoryMapHelper::Init(
        FutzEQFilterMemoryMapHelper *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  this->mSampleRate = sampleRate;
  v5 = 48i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x30ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->FutzBoxMemMapPtr = (FutzBoxEQFilterMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 148
// RVA: 0xB06BD0
FutzBoxEQFilterMemoryMap *__fastcall FutzEQFilterMemoryMapHelper::GetMemoryMap(
        FutzEQFilterMemoryMapHelper *this,
        unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 157
// RVA: 0xB06BF0
void __fastcall FutzEQFilterMemoryMapHelper::SetEQ(FutzEQFilterMemoryMapHelper *this, FutzEQParameters *eqParams)
{
  FutzEQType type; // ecx
  __int32 v5; // ecx
  __m128d v6; // xmm1
  __m128d v7; // xmm1
  __int64 i; // rdi
  SCoefs outCoefs; // [rsp+30h] [rbp-38h] BYREF

  CoefficientCalculator::CalculateBypassed(&outCoefs);
  if ( !eqParams->bypassed )
  {
    type = eqParams->type;
    if ( type )
    {
      v5 = type - 1;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          v6 = (__m128d)*(unsigned __int64 *)&eqParams->q;
          v6.m128d_f64[0] = v6.m128d_f64[0] * 0.01;
          if ( v6.m128d_f64[0] > 0.0 )
            *(_QWORD *)&v6.m128d_f64[0] = *(_OWORD *)&_mm_sqrt_pd(v6);
          CoefficientCalculator::CalculateSecondOrderLowPass(
            this->mSampleRate,
            eqParams->frequency,
            (1.0 - v6.m128d_f64[0] * 0.8) * 1.414,
            &outCoefs);
        }
      }
      else
      {
        CoefficientCalculator::CalculateParametric(
          this->mSampleRate,
          eqParams->frequency,
          eqParams->q * 0.01 * (eqParams->q * 0.01) * 9.0 + 1.0,
          eqParams->gain,
          &outCoefs);
      }
    }
    else
    {
      v7 = (__m128d)*(unsigned __int64 *)&eqParams->q;
      v7.m128d_f64[0] = v7.m128d_f64[0] * 0.01;
      if ( v7.m128d_f64[0] > 0.0 )
        *(_QWORD *)&v7.m128d_f64[0] = *(_OWORD *)&_mm_sqrt_pd(v7);
      CoefficientCalculator::CalculateSecondOrderHighPass(
        this->mSampleRate,
        eqParams->frequency,
        (1.0 - v7.m128d_f64[0] * 0.8) * 1.414,
        &outCoefs);
    }
  }
  for ( i = 0i64; (unsigned int)i < this->mNumChannels; i = (unsigned int)(i + 1) )
    DSPMemoryMapHelper::SetFilterCoefs(this, &outCoefs, this->FutzBoxMemMapPtr[i].XMemory, 0);
}

// File Line: 215
// RVA: 0xB06D40
void __fastcall FutzEQFilterImpl::FutzEQFilterImpl(FutzEQFilterImpl *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper);
  this->MemoryMapHelper.FutzBoxMemMapPtr = 0i64;
}

// File Line: 221
// RVA: 0xB06D70
// attributes: thunk
void __fastcall FutzEQFilterImpl::~FutzEQFilterImpl(FutzEQFilterImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper);
}

// File Line: 228
// RVA: 0xB06D80
__int64 __fastcall FutzEQFilterImpl::GetMemoryMapSize(FutzEQFilterImpl *this, unsigned int numChannels)
{
  return 48i64 * numChannels;
}

// File Line: 237
// RVA: 0xB06DA0
__int64 __fastcall FutzEQFilterImpl::Init(
        FutzEQFilterImpl *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->m_uNumTailFrames = 0;
  this->MemoryMapHelper.mNumChannels = numChannels;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 48i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x30ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxEQFilterMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 247
// RVA: 0xB06E70
void __fastcall FutzEQFilterImpl::ComputeTailLength(FutzEQFilterImpl *this, FutzBoxEQFilterMemoryMap *memoryMap)
{
  BiquadCoefficients in_coeffs; // [rsp+20h] [rbp-28h] BYREF

  in_coeffs.a0 = memoryMap->XMemory[0];
  in_coeffs.a1 = memoryMap->XMemory[1];
  in_coeffs.a2 = memoryMap->XMemory[2];
  in_coeffs.b1 = memoryMap->XMemory[3];
  in_coeffs.b2 = memoryMap->XMemory[4];
  this->m_uNumTailFrames = (int)(CoefficientCalculator::CalculateDecayTime(&in_coeffs) * 6.91);
}

// File Line: 259
// RVA: 0xB06E00
void __fastcall FutzEQFilterImpl::SetParameters(FutzEQFilterImpl *this, FutzEQParameters *eqParams)
{
  FutzBoxEQFilterMemoryMap *FutzBoxMemMapPtr; // rdx
  BiquadCoefficients in_coeffs; // [rsp+20h] [rbp-28h] BYREF

  FutzEQFilterMemoryMapHelper::SetEQ(&this->MemoryMapHelper, eqParams);
  FutzBoxMemMapPtr = this->MemoryMapHelper.FutzBoxMemMapPtr;
  in_coeffs.a0 = FutzBoxMemMapPtr->XMemory[0];
  in_coeffs.a1 = FutzBoxMemMapPtr->XMemory[1];
  in_coeffs.a2 = FutzBoxMemMapPtr->XMemory[2];
  in_coeffs.b1 = FutzBoxMemMapPtr->XMemory[3];
  in_coeffs.b2 = FutzBoxMemMapPtr->XMemory[4];
  this->m_uNumTailFrames = (int)(CoefficientCalculator::CalculateDecayTime(&in_coeffs) * 6.91);
}

