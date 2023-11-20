// File Line: 77
// RVA: 0xB08370
void __fastcall ProcessFutzGateChannel(FutzBoxGateMemoryMap *memoryMap, const float *inputBuf, float *outputBuf, unsigned int samplesRemaining)
{
  const float *i; // r11
  float v5; // xmm0_4
  signed int v6; // edx
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm0_4

  for ( i = inputBuf; samplesRemaining; *(outputBuf - 1) = v14 )
  {
    v5 = *i;
    --samplesRemaining;
    v6 = 0;
    memoryMap->YMemory[0] = *i;
    v7 = memoryMap->YMemory[1];
    ++i;
    if ( COERCE_FLOAT(LODWORD(memoryMap->XMemory[3]) & _xmm) > COERCE_FLOAT(LODWORD(v5) & _xmm) )
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
char *__fastcall ProcessFutzBoxGateWwise(char *memoryBlock, float *pfChannelIn, float *pfChannelOut, unsigned int uNumSamples)
{
  __int64 v4; // rcx

  ProcessFutzGateChannel((FutzBoxGateMemoryMap *)memoryBlock, pfChannelIn, pfChannelOut, uNumSamples);
  return (char *)(v4 + 76);
}

// File Line: 252
// RVA: 0xB07CB0
void __fastcall FutzGateMemoryMapHelper::FutzGateMemoryMapHelper(FutzGateMemoryMapHelper *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->0);
}

// File Line: 258
// RVA: 0xB07CD0
void __fastcall FutzGateMemoryMapHelper::~FutzGateMemoryMapHelper(FutzGateMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->0);
}

// File Line: 264
// RVA: 0xB07CE0
signed __int64 __fastcall FutzGateMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 76i64 * numChannels;
}

// File Line: 273
// RVA: 0xB07CF0
__int64 __fastcall FutzGateMemoryMapHelper::Init(FutzGateMemoryMapHelper *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzGateMemoryMapHelper *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  v4 = this;
  this->mSampleRate = sampleRate;
  v5 = 76i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x4Cui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->FutzBoxMemMapPtr = (FutzBoxGateMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 292
// RVA: 0xB07D50
FutzBoxGateMemoryMap *__fastcall FutzGateMemoryMapHelper::GetMemoryMap(FutzGateMemoryMapHelper *this, unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 301
// RVA: 0xB07D70
void __fastcall FutzGateMemoryMapHelper::SetGateInput(FutzGateMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzGateMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v2->0, 0, v2->FutzBoxMemMapPtr[v1++].XMemory, 9);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 309
// RVA: 0xB07DD0
void __fastcall FutzGateMemoryMapHelper::SetGateKeyInput(FutzGateMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzGateMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v2->0, 0, v2->FutzBoxMemMapPtr[v1++].XMemory, 2);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 317
// RVA: 0xB07E30
void __fastcall FutzGateMemoryMapHelper::SetGateThreshold(FutzGateMemoryMapHelper *this, long double threshold)
{
  FutzGateMemoryMapHelper *v2; // rdi
  unsigned int v3; // ebx
  double v4; // xmm6_8

  v2 = this;
  v3 = 0;
  v4 = pow(10.0, threshold * 0.05);
  if ( v2->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, v4, v2->FutzBoxMemMapPtr[v3++].XMemory, 3);
    while ( v3 < v2->mNumChannels );
  }
}

// File Line: 329
// RVA: 0xB07EA0
void __fastcall FutzGateMemoryMapHelper::SetGateRange(FutzGateMemoryMapHelper *this, long double range, bool bypassed)
{
  double v3; // xmm6_8
  FutzGateMemoryMapHelper *v4; // rdi
  unsigned int v5; // ebx

  v3 = DOUBLE_1_0;
  v4 = this;
  if ( !bypassed )
    v3 = pow(10.0, range * 0.05);
  v5 = 0;
  if ( v4->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v4->0, v3, v4->FutzBoxMemMapPtr[v5++].XMemory, 5);
    while ( v5 < v4->mNumChannels );
  }
}

// File Line: 344
// RVA: 0xB07F20
void __fastcall FutzGateMemoryMapHelper::SetGatePassingGain(FutzGateMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzGateMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, 1.0, v2->FutzBoxMemMapPtr[v1++].YMemory, 1);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 354
// RVA: 0xB07F80
void __usercall FutzGateMemoryMapHelper::SetGateAttack(FutzGateMemoryMapHelper *this@<rcx>, long double attack@<xmm1>, long double a3@<xmm0>)
{
  FutzGateMemoryMapHelper *v3; // rdi
  unsigned int v4; // ebx

  v3 = this;
  DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, attack);
  v4 = 0;
  if ( v3->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v3->0, a3, v3->FutzBoxMemMapPtr[v4++].XMemory, 8);
    while ( v4 < v3->mNumChannels );
  }
}

// File Line: 364
// RVA: 0xB07FF0
void __fastcall FutzGateMemoryMapHelper::SetGateHold(FutzGateMemoryMapHelper *this, long double hold)
{
  FutzGateMemoryMapHelper *v2; // rdi
  unsigned int v3; // ebx
  int v4; // esi

  v2 = this;
  v3 = 0;
  v4 = DynamicsCalculator::CalculateHoldSamples(this->mSampleRate, hold);
  if ( v2->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v2->0, v4, v2->FutzBoxMemMapPtr[v3++].XMemory, 6);
    while ( v3 < v2->mNumChannels );
  }
}

// File Line: 374
// RVA: 0xB08050
void __usercall FutzGateMemoryMapHelper::SetGateRelease(FutzGateMemoryMapHelper *this@<rcx>, long double release@<xmm1>, long double a3@<xmm0>)
{
  FutzGateMemoryMapHelper *v3; // rdi
  unsigned int v4; // ebx

  v3 = this;
  DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, release);
  v4 = 0;
  if ( v3->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v3->0, a3, v3->FutzBoxMemMapPtr[v4++].XMemory, 7);
    while ( v4 < v3->mNumChannels );
  }
}

// File Line: 387
// RVA: 0xB080C0
void __fastcall FutzGateImpl::FutzGateImpl(FutzGateImpl *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper.0);
}

// File Line: 393
// RVA: 0xB080E0
void __fastcall FutzGateImpl::~FutzGateImpl(FutzGateImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper.0);
}

// File Line: 400
// RVA: 0xB080F0
signed __int64 __fastcall FutzGateImpl::GetMemoryMapSize(FutzGateImpl *this, unsigned int numChannels)
{
  return 76i64 * numChannels;
}

// File Line: 409
// RVA: 0xB08100
__int64 __fastcall FutzGateImpl::Init(FutzGateImpl *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzGateImpl *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->MemoryMapHelper.mNumChannels = numChannels;
  v4 = this;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 76i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x4Cui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxGateMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 417
// RVA: 0xB08160
void __fastcall FutzGateImpl::SetParameters(FutzGateImpl *this, FutzGateParameters *gateParams)
{
  unsigned int v2; // edi
  FutzGateParameters *v3; // r14
  FutzGateImpl *v4; // rbx
  unsigned int v5; // esi
  unsigned int i; // esi
  long double v7; // xmm0_8
  unsigned int j; // esi
  unsigned int k; // esi
  unsigned int l; // esi
  unsigned int v11; // esi
  int m; // ebp

  v2 = 0;
  v3 = gateParams;
  v4 = this;
  v5 = 0;
  if ( this->MemoryMapHelper.mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v4->MemoryMapHelper.0, 0, v4->MemoryMapHelper.FutzBoxMemMapPtr[v5++].XMemory, 9);
    while ( v5 < v4->MemoryMapHelper.mNumChannels );
  }
  for ( i = 0; i < v4->MemoryMapHelper.mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(&v4->MemoryMapHelper.0, 0, v4->MemoryMapHelper.FutzBoxMemMapPtr[i].XMemory, 2);
  v7 = pow(10.0, v3->threshold * 0.05);
  for ( j = 0; j < v4->MemoryMapHelper.mNumChannels; ++j )
    DSPMemoryMapHelper::SetDoubleValue(&v4->MemoryMapHelper.0, v7, v4->MemoryMapHelper.FutzBoxMemMapPtr[j].XMemory, 3);
  FutzGateMemoryMapHelper::SetGateRange(&v4->MemoryMapHelper, v3->range, v3->bypassed);
  for ( k = 0; k < v4->MemoryMapHelper.mNumChannels; ++k )
    DSPMemoryMapHelper::SetDoubleValue(&v4->MemoryMapHelper.0, 1.0, v4->MemoryMapHelper.FutzBoxMemMapPtr[k].YMemory, 1);
  DynamicsCalculator::CalculateAttackScalar(v4->MemoryMapHelper.mSampleRate, v3->attack);
  for ( l = 0; l < v4->MemoryMapHelper.mNumChannels; ++l )
    DSPMemoryMapHelper::SetDoubleValue(&v4->MemoryMapHelper.0, v7, v4->MemoryMapHelper.FutzBoxMemMapPtr[l].XMemory, 8);
  v11 = 0;
  for ( m = DynamicsCalculator::CalculateHoldSamples(v4->MemoryMapHelper.mSampleRate, v3->hold);
        v11 < v4->MemoryMapHelper.mNumChannels;
        ++v11 )
  {
    DSPMemoryMapHelper::SetLongValue(&v4->MemoryMapHelper.0, m, v4->MemoryMapHelper.FutzBoxMemMapPtr[v11].XMemory, 6);
  }
  DynamicsCalculator::CalculateReleaseScalar(v4->MemoryMapHelper.mSampleRate, v3->release);
  if ( v4->MemoryMapHelper.mNumChannels > 0 )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(
        &v4->MemoryMapHelper.0,
        v7,
        v4->MemoryMapHelper.FutzBoxMemMapPtr[v2++].XMemory,
        7);
    while ( v2 < v4->MemoryMapHelper.mNumChannels );
  }
}

