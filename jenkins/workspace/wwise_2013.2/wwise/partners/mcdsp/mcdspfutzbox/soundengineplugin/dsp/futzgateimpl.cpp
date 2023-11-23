// File Line: 77
// RVA: 0xB08370
void __fastcall ProcessFutzGateChannel(
        FutzBoxGateMemoryMap *memoryMap,
        const float *inputBuf,
        float *outputBuf,
        unsigned int samplesRemaining)
{
  int v5; // xmm0_4
  int v6; // edx
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm0_4

  for ( ; samplesRemaining; *(outputBuf - 1) = v14 )
  {
    v5 = *(_DWORD *)inputBuf;
    --samplesRemaining;
    v6 = 0;
    memoryMap->YMemory[0] = *inputBuf;
    v7 = memoryMap->YMemory[1];
    ++inputBuf;
    if ( COERCE_FLOAT(LODWORD(memoryMap->XMemory[3]) & _xmm) > COERCE_FLOAT(v5 & _xmm) )
    {
      v7 = memoryMap->XMemory[5];
      v6 = 1;
    }
    v8 = memoryMap->YMemory[2];
    if ( v6 < 1 )
      v8 = memoryMap->XMemory[6];
    v9 = v8 + -1.0;
    if ( v9 >= 0.0 )
    {
      if ( v9 > 0.0 )
        v7 = memoryMap->YMemory[1];
    }
    else
    {
      v9 = 0.0;
    }
    memoryMap->YMemory[2] = v9;
    v10 = memoryMap->YMemory[3];
    v11 = memoryMap->XMemory[7];
    v12 = v7 - v10;
    if ( v12 > 0.0 )
      v11 = memoryMap->XMemory[8];
    ++outputBuf;
    v13 = (float)(v11 * v12) + v10;
    memoryMap->YMemory[3] = v13;
    memoryMap->XMemory[10] = v13;
    v14 = v13 * memoryMap->YMemory[0];
    memoryMap->YMemory[5] = v14;
  }
}

// File Line: 231
// RVA: 0xB07C90
char *__fastcall ProcessFutzBoxGateWwise(
        FutzBoxGateMemoryMap *memoryBlock,
        const float *pfChannelIn,
        float *pfChannelOut,
        unsigned int uNumSamples)
{
  __int64 v4; // rcx

  ProcessFutzGateChannel(memoryBlock, pfChannelIn, pfChannelOut, uNumSamples);
  return (char *)(v4 + 76);
}

// File Line: 252
// RVA: 0xB07CB0
void __fastcall FutzGateMemoryMapHelper::FutzGateMemoryMapHelper(FutzGateMemoryMapHelper *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(this);
}

// File Line: 258
// RVA: 0xB07CD0
// attributes: thunk
void __fastcall FutzGateMemoryMapHelper::~FutzGateMemoryMapHelper(FutzGateMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(this);
}

// File Line: 264
// RVA: 0xB07CE0
__int64 __fastcall FutzGateMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 76i64 * numChannels;
}

// File Line: 273
// RVA: 0xB07CF0
__int64 __fastcall FutzGateMemoryMapHelper::Init(
        FutzGateMemoryMapHelper *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  this->mSampleRate = sampleRate;
  v5 = 76i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x4Cui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->FutzBoxMemMapPtr = (FutzBoxGateMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 292
// RVA: 0xB07D50
FutzBoxGateMemoryMap *__fastcall FutzGateMemoryMapHelper::GetMemoryMap(
        FutzGateMemoryMapHelper *this,
        unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 301
// RVA: 0xB07D70
void __fastcall FutzGateMemoryMapHelper::SetGateInput(FutzGateMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(this, 0, this->FutzBoxMemMapPtr[i].XMemory, 9);
}

// File Line: 309
// RVA: 0xB07DD0
void __fastcall FutzGateMemoryMapHelper::SetGateKeyInput(FutzGateMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(this, 0, this->FutzBoxMemMapPtr[i].XMemory, 2);
}

// File Line: 317
// RVA: 0xB07E30
void __fastcall FutzGateMemoryMapHelper::SetGateThreshold(FutzGateMemoryMapHelper *this, long double threshold)
{
  unsigned int v3; // ebx
  double i; // xmm6_8

  v3 = 0;
  for ( i = pow(10.0, threshold * 0.05); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].XMemory, 3);
}

// File Line: 329
// RVA: 0xB07EA0
void __fastcall FutzGateMemoryMapHelper::SetGateRange(FutzGateMemoryMapHelper *this, long double range, bool bypassed)
{
  double v3; // xmm6_8
  unsigned int i; // ebx

  v3 = DOUBLE_1_0;
  if ( !bypassed )
    v3 = pow(10.0, range * 0.05);
  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetDoubleValue(this, v3, this->FutzBoxMemMapPtr[i].XMemory, 5);
}

// File Line: 344
// RVA: 0xB07F20
void __fastcall FutzGateMemoryMapHelper::SetGatePassingGain(FutzGateMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetDoubleValue(this, 1.0, this->FutzBoxMemMapPtr[i].YMemory, 1);
}

// File Line: 354
// RVA: 0xB07F80
void __fastcall FutzGateMemoryMapHelper::SetGateAttack(FutzGateMemoryMapHelper *this, long double attack)
{
  unsigned int v3; // ebx
  long double i; // xmm6_8

  v3 = 0;
  for ( i = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, attack); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].XMemory, 8);
}

// File Line: 364
// RVA: 0xB07FF0
void __fastcall FutzGateMemoryMapHelper::SetGateHold(FutzGateMemoryMapHelper *this, long double hold)
{
  unsigned int v3; // ebx
  int i; // esi

  v3 = 0;
  for ( i = DynamicsCalculator::CalculateHoldSamples(this->mSampleRate, hold); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetLongValue(this, i, this->FutzBoxMemMapPtr[v3].XMemory, 6);
}

// File Line: 374
// RVA: 0xB08050
void __fastcall FutzGateMemoryMapHelper::SetGateRelease(FutzGateMemoryMapHelper *this, long double release)
{
  unsigned int v3; // ebx
  long double i; // xmm6_8

  v3 = 0;
  for ( i = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, release); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].XMemory, 7);
}

// File Line: 387
// RVA: 0xB080C0
void __fastcall FutzGateImpl::FutzGateImpl(FutzGateImpl *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper);
}

// File Line: 393
// RVA: 0xB080E0
// attributes: thunk
void __fastcall FutzGateImpl::~FutzGateImpl(FutzGateImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper);
}

// File Line: 400
// RVA: 0xB080F0
__int64 __fastcall FutzGateImpl::GetMemoryMapSize(FutzGateImpl *this, unsigned int numChannels)
{
  return 76i64 * numChannels;
}

// File Line: 409
// RVA: 0xB08100
__int64 __fastcall FutzGateImpl::Init(
        FutzGateImpl *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->MemoryMapHelper.mNumChannels = numChannels;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 76i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x4Cui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxGateMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 417
// RVA: 0xB08160
void __fastcall FutzGateImpl::SetParameters(FutzGateImpl *this, FutzGateParameters *gateParams)
{
  unsigned int v2; // edi
  unsigned int i; // esi
  unsigned int j; // esi
  unsigned int v7; // esi
  double k; // xmm6_8
  unsigned int m; // esi
  unsigned int v10; // esi
  long double n; // xmm6_8
  unsigned int v12; // esi
  int ii; // ebp
  long double v14; // xmm6_8

  v2 = 0;
  for ( i = 0; i < this->MemoryMapHelper.mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(&this->MemoryMapHelper, 0, this->MemoryMapHelper.FutzBoxMemMapPtr[i].XMemory, 9);
  for ( j = 0; j < this->MemoryMapHelper.mNumChannels; ++j )
    DSPMemoryMapHelper::SetLongValue(&this->MemoryMapHelper, 0, this->MemoryMapHelper.FutzBoxMemMapPtr[j].XMemory, 2);
  v7 = 0;
  for ( k = pow(10.0, gateParams->threshold * 0.05); v7 < this->MemoryMapHelper.mNumChannels; ++v7 )
    DSPMemoryMapHelper::SetDoubleValue(&this->MemoryMapHelper, k, this->MemoryMapHelper.FutzBoxMemMapPtr[v7].XMemory, 3);
  FutzGateMemoryMapHelper::SetGateRange(&this->MemoryMapHelper, gateParams->range, gateParams->bypassed);
  for ( m = 0; m < this->MemoryMapHelper.mNumChannels; ++m )
    DSPMemoryMapHelper::SetDoubleValue(
      &this->MemoryMapHelper,
      1.0,
      this->MemoryMapHelper.FutzBoxMemMapPtr[m].YMemory,
      1);
  v10 = 0;
  for ( n = DynamicsCalculator::CalculateAttackScalar(this->MemoryMapHelper.mSampleRate, gateParams->attack);
        v10 < this->MemoryMapHelper.mNumChannels;
        ++v10 )
  {
    DSPMemoryMapHelper::SetDoubleValue(
      &this->MemoryMapHelper,
      n,
      this->MemoryMapHelper.FutzBoxMemMapPtr[v10].XMemory,
      8);
  }
  v12 = 0;
  for ( ii = DynamicsCalculator::CalculateHoldSamples(this->MemoryMapHelper.mSampleRate, gateParams->hold);
        v12 < this->MemoryMapHelper.mNumChannels;
        ++v12 )
  {
    DSPMemoryMapHelper::SetLongValue(&this->MemoryMapHelper, ii, this->MemoryMapHelper.FutzBoxMemMapPtr[v12].XMemory, 6);
  }
  v14 = DynamicsCalculator::CalculateReleaseScalar(this->MemoryMapHelper.mSampleRate, gateParams->release);
  if ( this->MemoryMapHelper.mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(
        &this->MemoryMapHelper,
        v14,
        this->MemoryMapHelper.FutzBoxMemMapPtr[v2++].XMemory,
        7);
    while ( v2 < this->MemoryMapHelper.mNumChannels );
  }
}

