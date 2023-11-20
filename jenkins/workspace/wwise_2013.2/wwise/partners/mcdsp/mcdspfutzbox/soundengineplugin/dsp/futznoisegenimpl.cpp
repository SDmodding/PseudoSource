// File Line: 102
// RVA: 0xB07940
void __fastcall ProcessFutzNoiseGenChannel(FutzBoxNoiseGenMemoryMap *memoryMap, const float *inputBuf, const float *randomBuf, float *outputBuf, unsigned int samplesRemaining)
{
  unsigned int v5; // er10
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
  signed int v20; // er8
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
  v43 = memoryMap->XMemory[6];
  v42 = memoryMap->XMemory[2];
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
char *__fastcall ProcessFutzBoxNoiseGenWwise(char *memoryBlock, float *pfChannelIn, float *pfChannelNoise, float *pfChannelOut, unsigned int uNumSamples)
{
  __int64 v5; // rcx

  ProcessFutzNoiseGenChannel(
    (FutzBoxNoiseGenMemoryMap *)memoryBlock,
    pfChannelIn,
    pfChannelNoise,
    pfChannelOut,
    uNumSamples);
  return (char *)(v5 + 168);
}

// File Line: 353
// RVA: 0xB07020
void __fastcall FutzBoxNoiseGenMemoryMapHelper::FutzBoxNoiseGenMemoryMapHelper(FutzBoxNoiseGenMemoryMapHelper *this)
{
  FutzBoxNoiseGenMemoryMapHelper *v1; // rbx

  v1 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->0);
  v1->FutzBoxMemMapPtr = 0i64;
}

// File Line: 359
// RVA: 0xB07050
void __fastcall FutzBoxNoiseGenMemoryMapHelper::~FutzBoxNoiseGenMemoryMapHelper(FutzBoxNoiseGenMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->0);
}

// File Line: 365
// RVA: 0xB07060
signed __int64 __fastcall FutzBoxNoiseGenMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 168i64 * numChannels;
}

// File Line: 374
// RVA: 0xB07070
__int64 __fastcall FutzBoxNoiseGenMemoryMapHelper::Init(FutzBoxNoiseGenMemoryMapHelper *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzBoxNoiseGenMemoryMapHelper *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  v4 = this;
  this->mSampleRate = sampleRate;
  v5 = 168i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0xA8ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->FutzBoxMemMapPtr = (FutzBoxNoiseGenMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 391
// RVA: 0xB070D0
FutzBoxNoiseGenMemoryMap *__fastcall FutzBoxNoiseGenMemoryMapHelper::GetMemoryMap(FutzBoxNoiseGenMemoryMapHelper *this, unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 400
// RVA: 0xB070F0
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseState(FutzBoxNoiseGenMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzBoxNoiseGenMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v2->0, 0, v2->FutzBoxMemMapPtr[v1++].XMemory, 0);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 418
// RVA: 0xB07140
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseLevel(FutzBoxNoiseGenMemoryMapHelper *this, long double level, bool bypassed)
{
  FutzBoxNoiseGenMemoryMapHelper *v3; // rdi
  double v4; // xmm6_8
  double v5; // xmm1_8
  unsigned int v6; // ebx

  v3 = this;
  v4 = 0.0;
  if ( !bypassed )
  {
    v5 = level - 6.0;
    if ( v5 >= -143.0 )
      v4 = pow(10.0, v5 * 0.05);
  }
  v6 = 0;
  if ( v3->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v3->0, v4, v3->FutzBoxMemMapPtr[v6++].YMemory, 1);
    while ( v6 < v3->mNumChannels );
  }
}

// File Line: 440
// RVA: 0xB071E0
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseLowFilter(FutzBoxNoiseGenMemoryMapHelper *this, long double frequency, bool bypassed)
{
  FutzBoxNoiseGenMemoryMapHelper *v3; // rdi
  bool v4; // bl
  unsigned int v5; // ebx
  SCoefs outCoefs; // [rsp+20h] [rbp-48h]

  v3 = this;
  v4 = bypassed;
  CoefficientCalculator::CalculateBypassed(&outCoefs);
  if ( !v4 )
    CoefficientCalculator::CalculateSecondOrderHighPass(v3->mSampleRate, frequency, 1.414, &outCoefs);
  v5 = 0;
  if ( v3->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &outCoefs, v3->FutzBoxMemMapPtr[v5++].XMemory, 1);
    while ( v5 < v3->mNumChannels );
  }
}

// File Line: 457
// RVA: 0xB07270
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseHighFilter(FutzBoxNoiseGenMemoryMapHelper *this, long double frequency, bool bypassed)
{
  FutzBoxNoiseGenMemoryMapHelper *v3; // rdi
  bool v4; // bl
  unsigned int v5; // ebx
  SCoefs outCoefs; // [rsp+20h] [rbp-48h]

  v3 = this;
  v4 = bypassed;
  CoefficientCalculator::CalculateBypassed(&outCoefs);
  if ( !v4 )
    CoefficientCalculator::CalculateSecondOrderLowPass(v3->mSampleRate, frequency, 1.414, &outCoefs);
  v5 = 0;
  if ( v3->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &outCoefs, v3->FutzBoxMemMapPtr[v5++].XMemory, 6);
    while ( v5 < v3->mNumChannels );
  }
}

// File Line: 474
// RVA: 0xB07300
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerInput(FutzBoxNoiseGenMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzBoxNoiseGenMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v2->0, 14, v2->FutzBoxMemMapPtr[v1++].XMemory, 18);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 482
// RVA: 0xB07360
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerKeyInput(FutzBoxNoiseGenMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzBoxNoiseGenMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v2->0, 0, v2->FutzBoxMemMapPtr[v1++].XMemory, 11);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 490
// RVA: 0xB073B0
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerThreshold(FutzBoxNoiseGenMemoryMapHelper *this, long double threshold)
{
  FutzBoxNoiseGenMemoryMapHelper *v2; // rdi
  unsigned int v3; // ebx
  double v4; // xmm6_8

  v2 = this;
  v3 = 0;
  v4 = pow(10.0, threshold * 0.05);
  if ( v2->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, v4, v2->FutzBoxMemMapPtr[v3++].XMemory, 12);
    while ( v3 < v2->mNumChannels );
  }
}

// File Line: 500
// RVA: 0xB07420
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerRange(FutzBoxNoiseGenMemoryMapHelper *this, long double range)
{
  FutzBoxNoiseGenMemoryMapHelper *v2; // rdi
  unsigned int v3; // ebx
  double v4; // xmm6_8

  v2 = this;
  v3 = 0;
  v4 = pow(10.0, range * 0.05);
  if ( v2->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, v4, v2->FutzBoxMemMapPtr[v3++].XMemory, 14);
    while ( v3 < v2->mNumChannels );
  }
}

// File Line: 510
// RVA: 0xB07490
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerPassingGain(FutzBoxNoiseGenMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzBoxNoiseGenMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, 1.0, v2->FutzBoxMemMapPtr[v1++].YMemory, 15);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 520
// RVA: 0xB07500
void __usercall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerAttack(FutzBoxNoiseGenMemoryMapHelper *this@<rcx>, long double recovery@<xmm1>, long double a3@<xmm0>)
{
  FutzBoxNoiseGenMemoryMapHelper *v3; // rdi
  unsigned int v4; // ebx

  v3 = this;
  DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, recovery);
  v4 = 0;
  if ( v3->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v3->0, a3, v3->FutzBoxMemMapPtr[v4++].XMemory, 17);
    while ( v4 < v3->mNumChannels );
  }
}

// File Line: 530
// RVA: 0xB07570
void __fastcall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerHold(FutzBoxNoiseGenMemoryMapHelper *this)
{
  FutzBoxNoiseGenMemoryMapHelper *v1; // rbx
  unsigned int v2; // edi
  int v3; // esi

  v1 = this;
  v2 = 0;
  v3 = DynamicsCalculator::CalculateHoldSamples(this->mSampleRate, 1.0);
  if ( v1->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v1->0, v3, v1->FutzBoxMemMapPtr[v2++].XMemory, 15);
    while ( v2 < v1->mNumChannels );
  }
}

// File Line: 541
// RVA: 0xB075E0
void __usercall FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerRelease(FutzBoxNoiseGenMemoryMapHelper *this@<rcx>, long double a2@<xmm0>)
{
  FutzBoxNoiseGenMemoryMapHelper *v2; // rbx
  unsigned int v3; // edi

  v2 = this;
  DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, 1.0);
  v3 = 0;
  if ( v2->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, a2, v2->FutzBoxMemMapPtr[v3++].XMemory, 16);
    while ( v3 < v2->mNumChannels );
  }
}

// File Line: 556
// RVA: 0xB07650
void __fastcall FutzNoiseGenImpl::FutzNoiseGenImpl(FutzNoiseGenImpl *this)
{
  FutzNoiseGenImpl *v1; // rbx

  v1 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper.0);
  v1->MemoryMapHelper.FutzBoxMemMapPtr = 0i64;
}

// File Line: 562
// RVA: 0xB07680
void __fastcall FutzNoiseGenImpl::~FutzNoiseGenImpl(FutzNoiseGenImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper.0);
}

// File Line: 571
// RVA: 0xB07690
signed __int64 __fastcall FutzNoiseGenImpl::GetMemoryMapSize(FutzNoiseGenImpl *this, unsigned int numChannels)
{
  return 168i64 * numChannels;
}

// File Line: 580
// RVA: 0xB076A0
__int64 __fastcall FutzNoiseGenImpl::Init(FutzNoiseGenImpl *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzNoiseGenImpl *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->MemoryMapHelper.mNumChannels = numChannels;
  v4 = this;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 168i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0xA8ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxNoiseGenMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 597
// RVA: 0xB07700
void __fastcall FutzNoiseGenImpl::SetParameters(FutzNoiseGenImpl *this, FutzNoiseParameters *noiseParams)
{
  unsigned int v2; // edi
  FutzNoiseParameters *v3; // rbp
  FutzNoiseGenImpl *v4; // rbx
  unsigned int v5; // esi
  unsigned int i; // esi
  unsigned int j; // esi
  unsigned int v8; // esi
  double k; // xmm6_8
  long double v10; // xmm0_8
  unsigned int l; // esi
  unsigned int m; // esi

  v2 = 0;
  v3 = noiseParams;
  v4 = this;
  v5 = 0;
  if ( this->MemoryMapHelper.mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v4->MemoryMapHelper.0, 0, v4->MemoryMapHelper.FutzBoxMemMapPtr[v5++].XMemory, 0);
    while ( v5 < v4->MemoryMapHelper.mNumChannels );
  }
  FutzBoxNoiseGenMemoryMapHelper::SetNoiseLevel(&v4->MemoryMapHelper, v3->level, v3->bypassed);
  FutzBoxNoiseGenMemoryMapHelper::SetNoiseLowFilter(&v4->MemoryMapHelper, v3->hpfFrequency, v3->bypassed);
  FutzBoxNoiseGenMemoryMapHelper::SetNoiseHighFilter(&v4->MemoryMapHelper, v3->lpfFrequency, v3->bypassed);
  for ( i = 0; i < v4->MemoryMapHelper.mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(&v4->MemoryMapHelper.0, 14, v4->MemoryMapHelper.FutzBoxMemMapPtr[i].XMemory, 18);
  for ( j = 0; j < v4->MemoryMapHelper.mNumChannels; ++j )
    DSPMemoryMapHelper::SetLongValue(&v4->MemoryMapHelper.0, 0, v4->MemoryMapHelper.FutzBoxMemMapPtr[j].XMemory, 11);
  v8 = 0;
  for ( k = pow(10.0, v3->threshold * 0.05); v8 < v4->MemoryMapHelper.mNumChannels; ++v8 )
    DSPMemoryMapHelper::SetDoubleValue(&v4->MemoryMapHelper.0, k, v4->MemoryMapHelper.FutzBoxMemMapPtr[v8].XMemory, 12);
  v10 = pow(10.0, v3->range * 0.05);
  for ( l = 0; l < v4->MemoryMapHelper.mNumChannels; ++l )
    DSPMemoryMapHelper::SetDoubleValue(&v4->MemoryMapHelper.0, v10, v4->MemoryMapHelper.FutzBoxMemMapPtr[l].XMemory, 14);
  for ( m = 0; m < v4->MemoryMapHelper.mNumChannels; ++m )
    DSPMemoryMapHelper::SetDoubleValue(&v4->MemoryMapHelper.0, 1.0, v4->MemoryMapHelper.FutzBoxMemMapPtr[m].YMemory, 15);
  DynamicsCalculator::CalculateAttackScalar(v4->MemoryMapHelper.mSampleRate, v3->recovery);
  if ( v4->MemoryMapHelper.mNumChannels > 0 )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(
        &v4->MemoryMapHelper.0,
        v10,
        v4->MemoryMapHelper.FutzBoxMemMapPtr[v2++].XMemory,
        17);
    while ( v2 < v4->MemoryMapHelper.mNumChannels );
  }
  FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerHold(&v4->MemoryMapHelper);
  FutzBoxNoiseGenMemoryMapHelper::SetNoiseDuckerRelease(&v4->MemoryMapHelper, v10);
}

