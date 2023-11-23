// File Line: 102
// RVA: 0xB07940
void __fastcall ProcessFutzNoiseGenChannel(
        FutzBoxNoiseGenMemoryMap *memoryMap,
        const float *inputBuf,
        const float *randomBuf,
        float *outputBuf,
        unsigned int samplesRemaining)
{
  unsigned int v5; // r10d
  const float *v6; // rbx
  float v7; // xmm4_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm8_4
  float v13; // xmm15_4
  float v14; // xmm12_4
  float v15; // xmm9_4
  float v16; // xmm13_4
  float v17; // xmm0_4
  float *v18; // r11
  signed __int64 v19; // rdi
  int v20; // r8d
  float v21; // xmm1_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  float v36; // [rsp+0h] [rbp-C8h]
  float v37; // [rsp+4h] [rbp-C4h]
  float v38; // [rsp+8h] [rbp-C0h]
  float v39; // [rsp+Ch] [rbp-BCh]
  float v40; // [rsp+10h] [rbp-B8h]
  float v41; // [rsp+14h] [rbp-B4h]
  float v42; // [rsp+18h] [rbp-B0h]
  float v43; // [rsp+1Ch] [rbp-ACh]
  float v44; // [rsp+D0h] [rbp+8h]

  v5 = samplesRemaining;
  v6 = randomBuf;
  v7 = memoryMap->XMemory[2];
  v8 = memoryMap->YMemory[2];
  v9 = memoryMap->YMemory[4];
  v10 = memoryMap->YMemory[3];
  v11 = memoryMap->YMemory[5];
  v12 = memoryMap->YMemory[8];
  v13 = memoryMap->XMemory[1];
  v14 = memoryMap->YMemory[9];
  v15 = memoryMap->YMemory[10];
  v16 = memoryMap->YMemory[11];
  v39 = memoryMap->XMemory[3];
  v44 = memoryMap->XMemory[7];
  v40 = memoryMap->XMemory[4];
  v36 = memoryMap->XMemory[8];
  v41 = memoryMap->XMemory[5];
  v17 = memoryMap->XMemory[6];
  v37 = memoryMap->XMemory[9];
  v43 = v17;
  v42 = v7;
  v38 = memoryMap->XMemory[10];
  if ( samplesRemaining )
  {
    v18 = &memoryMap->YMemory[14];
    v19 = (char *)inputBuf - (char *)randomBuf;
    do
    {
      memoryMap->YMemory[0] = *(const float *)((char *)v6 + v19);
      --v5;
      ++v6;
      v20 = 0;
      v21 = *(v6 - 1);
      memoryMap->XMemory[0] = v21;
      v22 = v21 * memoryMap->YMemory[1];
      v23 = (float)((float)(v12 * v44) + (float)(v17 * v22)) + (float)(v14 * v36);
      v14 = v12;
      v12 = v22;
      v24 = (float)(v23 - (float)(v15 * v37)) - (float)(v16 * v38);
      v16 = v15;
      v15 = v24;
      v25 = (float)((float)(v8 * v7) + (float)(v13 * v24)) + (float)(v10 * v39);
      v10 = v8;
      v8 = v24;
      v26 = (float)(v25 - (float)(v9 * v40)) - (float)(v11 * v41);
      v11 = v9;
      *v18 = v26;
      v27 = memoryMap->YMemory[15];
      v9 = v26;
      if ( COERCE_FLOAT(LODWORD(memoryMap->XMemory[12]) & _xmm) < COERCE_FLOAT(LODWORD(memoryMap->YMemory[0]) & _xmm) )
      {
        v27 = memoryMap->XMemory[14];
        v20 = 1;
      }
      v28 = memoryMap->YMemory[16];
      if ( v20 > 0 )
        v28 = memoryMap->XMemory[15];
      v29 = v28 + -1.0;
      if ( v29 > 0.0 )
        v27 = memoryMap->XMemory[14];
      else
        v29 = 0.0;
      memoryMap->YMemory[16] = v29;
      v30 = memoryMap->YMemory[17];
      v31 = memoryMap->XMemory[16];
      v32 = v27 - v30;
      if ( v32 > 0.0 )
        v31 = memoryMap->XMemory[17];
      v7 = v42;
      ++outputBuf;
      v33 = (float)(v31 * v32) + v30;
      memoryMap->YMemory[17] = v33;
      v34 = v33 * *v18;
      memoryMap->YMemory[19] = v34;
      v35 = v34 + memoryMap->YMemory[0];
      memoryMap->YMemory[20] = v35;
      *(outputBuf - 1) = v35;
      v17 = v43;
    }
    while ( v5 );
  }
  memoryMap->YMemory[2] = v8;
  memoryMap->YMemory[8] = v12;
  memoryMap->YMemory[3] = v10;
  memoryMap->YMemory[9] = v14;
  memoryMap->YMemory[4] = v9;
  memoryMap->YMemory[10] = v15;
  memoryMap->YMemory[5] = v11;
  memoryMap->YMemory[11] = v16;
}

// File Line: 271
// RVA: 0xB06FF0
char *__fastcall ProcessFutzBoxNoiseGenWwise(
        FutzBoxNoiseGenMemoryMap *memoryBlock,
        const float *pfChannelIn,
        const float *pfChannelNoise,
        float *pfChannelOut,
        unsigned int uNumSamples)
{
  __int64 v5; // rcx

  ProcessFutzNoiseGenChannel(memoryBlock, pfChannelIn, pfChannelNoise, pfChannelOut, uNumSamples);
  return (char *)(v5 + 168);
}

// File Line: 353
// RVA: 0xB07020
void __fastcall FutzBoxNoiseGenMemoryMapHelper::FutzBoxNoiseGenMemoryMapHelper(FutzBoxNoiseGenMemoryMapHelper *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(this);
  this->FutzBoxMemMapPtr = 0i64;
}

// File Line: 359
// RVA: 0xB07050
// attributes: thunk
void __fastcall FutzBoxNoiseGenMemoryMapHelper::~FutzBoxNoiseGenMemoryMapHelper(FutzBoxNoiseGenMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(this);
}

// File Line: 365
// RVA: 0xB07060
__int64 __fastcall FutzBoxNoiseGenMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 168i64 * numChannels;
}

// File Line: 374
// RVA: 0xB07070
__int64 __fastcall FutzBoxNoiseGenMemoryMapHelper::Init(
        FutzBoxNoiseGenMemoryMapHelper *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  this->mSampleRate = sampleRate;
  v5 = 168i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0xA8ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->FutzBoxMemMapPtr = (FutzBoxNoiseGenMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 391
// RVA: 0xB070D0
FutzBoxNoiseGenMemoryMap *__fastcall FutzBoxNoiseGenMemoryMapHelper::GetMemoryMap(
        FutzBoxNoiseGenMemoryMapHelper *this,
        unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 400
// RVA: 0xB070F0
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseState(FutzBoxNoiseGenMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(this, 0, this->FutzBoxMemMapPtr[i].XMemory, 0);
}

// File Line: 418
// RVA: 0xB07140
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseLevel(
        FutzBoxNoiseGenMemoryMapHelper *this,
        long double level,
        bool bypassed)
{
  double v4; // xmm6_8
  double v5; // xmm1_8
  unsigned int i; // ebx

  v4 = 0.0;
  if ( !bypassed )
  {
    v5 = level - 6.0;
    if ( v5 >= -143.0 )
      v4 = pow(10.0, v5 * 0.05);
  }
  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetDoubleValue(this, v4, this->FutzBoxMemMapPtr[i].YMemory, 1);
}

// File Line: 440
// RVA: 0xB071E0
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseLowFilter(
        FutzBoxNoiseGenMemoryMapHelper *this,
        long double frequency,
        bool bypassed)
{
  unsigned int i; // ebx
  SCoefs outCoefs; // [rsp+20h] [rbp-48h] BYREF

  CoefficientCalculator::CalculateBypassed(&outCoefs);
  if ( !bypassed )
    CoefficientCalculator::CalculateSecondOrderHighPass(this->mSampleRate, frequency, 1.414, &outCoefs);
  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetFilterCoefs(this, &outCoefs, this->FutzBoxMemMapPtr[i].XMemory, 1);
}

// File Line: 457
// RVA: 0xB07270
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseHighFilter(
        FutzBoxNoiseGenMemoryMapHelper *this,
        long double frequency,
        bool bypassed)
{
  unsigned int i; // ebx
  SCoefs outCoefs; // [rsp+20h] [rbp-48h] BYREF

  CoefficientCalculator::CalculateBypassed(&outCoefs);
  if ( !bypassed )
    CoefficientCalculator::CalculateSecondOrderLowPass(this->mSampleRate, frequency, 1.414, &outCoefs);
  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetFilterCoefs(this, &outCoefs, this->FutzBoxMemMapPtr[i].XMemory, 6);
}

// File Line: 474
// RVA: 0xB07300
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerInput(FutzBoxNoiseGenMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(this, 14, this->FutzBoxMemMapPtr[i].XMemory, 18);
}

// File Line: 482
// RVA: 0xB07360
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerKeyInput(FutzBoxNoiseGenMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(this, 0, this->FutzBoxMemMapPtr[i].XMemory, 11);
}

// File Line: 490
// RVA: 0xB073B0
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerThreshold(
        FutzBoxNoiseGenMemoryMapHelper *this,
        long double threshold)
{
  unsigned int v3; // ebx
  double i; // xmm6_8

  v3 = 0;
  for ( i = pow(10.0, threshold * 0.05); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].XMemory, 12);
}

// File Line: 500
// RVA: 0xB07420
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerRange(
        FutzBoxNoiseGenMemoryMapHelper *this,
        long double range)
{
  unsigned int v3; // ebx
  double i; // xmm6_8

  v3 = 0;
  for ( i = pow(10.0, range * 0.05); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].XMemory, 14);
}

// File Line: 510
// RVA: 0xB07490
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerPassingGain(FutzBoxNoiseGenMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetDoubleValue(this, 1.0, this->FutzBoxMemMapPtr[i].YMemory, 15);
}

// File Line: 520
// RVA: 0xB07500
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerAttack(
        FutzBoxNoiseGenMemoryMapHelper *this,
        long double recovery)
{
  unsigned int v3; // ebx
  long double i; // xmm6_8

  v3 = 0;
  for ( i = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, recovery); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].XMemory, 17);
}

// File Line: 530
// RVA: 0xB07570
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerHold(FutzBoxNoiseGenMemoryMapHelper *this)
{
  unsigned int v2; // edi
  int i; // esi

  v2 = 0;
  for ( i = DynamicsCalculator::CalculateHoldSamples(this->mSampleRate, 1.0); v2 < this->mNumChannels; ++v2 )
    DSPMemoryMapHelper::SetLongValue(this, i, this->FutzBoxMemMapPtr[v2].XMemory, 15);
}

// File Line: 541
// RVA: 0xB075E0
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerRelease(FutzBoxNoiseGenMemoryMapHelper *this)
{
  unsigned int v2; // edi
  long double i; // xmm6_8

  v2 = 0;
  for ( i = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, 1.0); v2 < this->mNumChannels; ++v2 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v2].XMemory, 16);
}

// File Line: 556
// RVA: 0xB07650
void __fastcall FutzNoiseGenImpl::FutzNoiseGenImpl(FutzNoiseGenImpl *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper);
  this->MemoryMapHelper.FutzBoxMemMapPtr = 0i64;
}

// File Line: 562
// RVA: 0xB07680
// attributes: thunk
void __fastcall FutzNoiseGenImpl::~FutzNoiseGenImpl(FutzNoiseGenImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper);
}

// File Line: 571
// RVA: 0xB07690
__int64 __fastcall FutzNoiseGenImpl::GetMemoryMapSize(FutzNoiseGenImpl *this, unsigned int numChannels)
{
  return 168i64 * numChannels;
}

// File Line: 580
// RVA: 0xB076A0
__int64 __fastcall FutzNoiseGenImpl::Init(
        FutzNoiseGenImpl *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->MemoryMapHelper.mNumChannels = numChannels;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 168i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0xA8ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxNoiseGenMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 597
// RVA: 0xB07700
void __fastcall FutzNoiseGenImpl::SetParameters(FutzNoiseGenImpl *this, FutzNoiseParameters *noiseParams)
{
  unsigned int v2; // edi
  unsigned int i; // esi
  unsigned int j; // esi
  unsigned int k; // esi
  unsigned int v8; // esi
  double m; // xmm6_8
  unsigned int v10; // esi
  double n; // xmm6_8
  unsigned int ii; // esi
  long double v13; // xmm6_8

  v2 = 0;
  for ( i = 0; i < this->MemoryMapHelper.mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(&this->MemoryMapHelper, 0, this->MemoryMapHelper.FutzBoxMemMapPtr[i].XMemory, 0);
  FutzBoxNoiseGenMemoryMapHelper::SetNoiseLevel(&this->MemoryMapHelper, noiseParams->level, noiseParams->bypassed);
  FutzBoxNoiseGenMemoryMapHelper::SetNoiseLowFilter(
    &this->MemoryMapHelper,
    noiseParams->hpfFrequency,
    noiseParams->bypassed);
  FutzBoxNoiseGenMemoryMapHelper::SetNoiseHighFilter(
    &this->MemoryMapHelper,
    noiseParams->lpfFrequency,
    noiseParams->bypassed);
  for ( j = 0; j < this->MemoryMapHelper.mNumChannels; ++j )
    DSPMemoryMapHelper::SetLongValue(&this->MemoryMapHelper, 14, this->MemoryMapHelper.FutzBoxMemMapPtr[j].XMemory, 18);
  for ( k = 0; k < this->MemoryMapHelper.mNumChannels; ++k )
    DSPMemoryMapHelper::SetLongValue(&this->MemoryMapHelper, 0, this->MemoryMapHelper.FutzBoxMemMapPtr[k].XMemory, 11);
  v8 = 0;
  for ( m = pow(10.0, noiseParams->threshold * 0.05); v8 < this->MemoryMapHelper.mNumChannels; ++v8 )
    DSPMemoryMapHelper::SetDoubleValue(
      &this->MemoryMapHelper,
      m,
      this->MemoryMapHelper.FutzBoxMemMapPtr[v8].XMemory,
      12);
  v10 = 0;
  for ( n = pow(10.0, noiseParams->range * 0.05); v10 < this->MemoryMapHelper.mNumChannels; ++v10 )
    DSPMemoryMapHelper::SetDoubleValue(
      &this->MemoryMapHelper,
      n,
      this->MemoryMapHelper.FutzBoxMemMapPtr[v10].XMemory,
      14);
  for ( ii = 0; ii < this->MemoryMapHelper.mNumChannels; ++ii )
    DSPMemoryMapHelper::SetDoubleValue(
      &this->MemoryMapHelper,
      1.0,
      this->MemoryMapHelper.FutzBoxMemMapPtr[ii].YMemory,
      15);
  v13 = DynamicsCalculator::CalculateAttackScalar(this->MemoryMapHelper.mSampleRate, noiseParams->recovery);
  if ( this->MemoryMapHelper.mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(
        &this->MemoryMapHelper,
        v13,
        this->MemoryMapHelper.FutzBoxMemMapPtr[v2++].XMemory,
        17);
    while ( v2 < this->MemoryMapHelper.mNumChannels );
  }
  FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerHold(&this->MemoryMapHelper);
  FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerRelease(&this->MemoryMapHelper);
}

