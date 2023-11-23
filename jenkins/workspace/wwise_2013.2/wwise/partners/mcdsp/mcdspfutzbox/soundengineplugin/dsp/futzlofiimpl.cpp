// File Line: 91
// RVA: 0xB09D10
void __fastcall ProcessFutzLoFiChannel(
        FutzBoxLoFiMemoryMap *memoryMap,
        const float *inputBuf,
        float *outputBuf,
        unsigned int samplesRemaining)
{
  float v4; // xmm6_4
  float v9; // xmm9_4
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm13_4
  float v13; // xmm10_4
  float v14; // xmm14_4
  float v15; // xmm15_4
  float i; // xmm12_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  int v20; // edx
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float v25; // [rsp+E0h] [rbp+8h]
  float v26; // [rsp+F8h] [rbp+20h]

  v4 = memoryMap->XMemory[2];
  v9 = memoryMap->YMemory[4];
  v10 = memoryMap->YMemory[5];
  v11 = memoryMap->YMemory[7];
  v12 = memoryMap->XMemory[4];
  v13 = memoryMap->YMemory[6];
  v26 = memoryMap->XMemory[7];
  v14 = memoryMap->XMemory[5];
  v15 = memoryMap->XMemory[6];
  v25 = memoryMap->XMemory[8];
  for ( i = pow(2.0, COERCE_FLOAT(LODWORD(v4) ^ _xmm[0])); samplesRemaining; *(outputBuf - 1) = v24
                                                                                              * memoryMap->YMemory[10] )
  {
    --samplesRemaining;
    v17 = memoryMap->YMemory[0] * *inputBuf++;
    memoryMap->YMemory[1] = v17;
    v18 = (float)(v17 * 8388607.0) * i;
    if ( v18 <= 0.0 )
      v19 = v18 - 0.5;
    else
      v19 = v18 + 0.5;
    v20 = (int)v19;
    v21 = memoryMap->YMemory[3] - 1.0;
    v22 = (float)(v20 << (int)v4) * 0.0000001192093;
    if ( v21 <= 0.0 )
      v21 = memoryMap->XMemory[3];
    else
      v22 = memoryMap->YMemory[2];
    memoryMap->YMemory[3] = v21;
    memoryMap->YMemory[2] = v22;
    ++outputBuf;
    v23 = (float)((float)(v9 * v14) + (float)(v12 * v22)) + (float)(v10 * v15);
    v10 = v9;
    v9 = v22;
    v24 = (float)(v23 - (float)(v13 * v26)) - (float)(v11 * v25);
    v11 = v13;
    v13 = v24;
  }
  memoryMap->YMemory[4] = v9;
  memoryMap->YMemory[5] = v10;
  memoryMap->YMemory[6] = v13;
  memoryMap->YMemory[7] = v11;
}

// File Line: 317
// RVA: 0xB09670
FutzBoxLoFiMemoryMap *__fastcall ProcessFutzBoxLoFiWwise(
        FutzBoxLoFiMemoryMap *memoryBlock,
        const float *pfChannelIn,
        float *pfChannelOut,
        unsigned int uNumSamples)
{
  ProcessFutzLoFiChannel(memoryBlock, pfChannelIn, pfChannelOut, uNumSamples);
  return memoryBlock + 1;
}

// File Line: 403
// RVA: 0xB09690
void __fastcall FutzBoxLoFiMemoryMapHelper::FutzBoxLoFiMemoryMapHelper(FutzBoxLoFiMemoryMapHelper *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(this);
  this->FutzBoxMemMapPtr = 0i64;
}

// File Line: 409
// RVA: 0xB096C0
// attributes: thunk
void __fastcall FutzBoxLoFiMemoryMapHelper::~FutzBoxLoFiMemoryMapHelper(FutzBoxLoFiMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(this);
}

// File Line: 415
// RVA: 0xB096D0
__int64 __fastcall FutzBoxLoFiMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 100i64 * numChannels;
}

// File Line: 424
// RVA: 0xB096E0
__int64 __fastcall FutzBoxLoFiMemoryMapHelper::Init(
        FutzBoxLoFiMemoryMapHelper *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  this->mSampleRate = sampleRate;
  v5 = 100i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x64ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->FutzBoxMemMapPtr = (FutzBoxLoFiMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 443
// RVA: 0xB09740
FutzBoxLoFiMemoryMap *__fastcall FutzBoxLoFiMemoryMapHelper::GetMemoryMap(
        FutzBoxLoFiMemoryMapHelper *this,
        unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 452
// RVA: 0xB09760
void __fastcall FutzBoxLoFiMemoryMapHelper::SetBitDepth(
        FutzBoxLoFiMemoryMapHelper *this,
        FutzBitDepthType bitDepthType,
        bool bypassed)
{
  unsigned int v3; // ebx
  int v5; // esi

  v3 = 0;
  v5 = 0;
  if ( !bypassed )
    v5 = 24 - sBitDepthMaskTable[bitDepthType];
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(this, v5, this->FutzBoxMemMapPtr[v3++].XMemory, 2);
    while ( v3 < this->mNumChannels );
  }
}

// File Line: 467
// RVA: 0xB097D0
void __fastcall FutzBoxLoFiMemoryMapHelper::SetDownSampleHoldCount(
        FutzBoxLoFiMemoryMapHelper *this,
        int downSampleIndex,
        bool bypassed)
{
  unsigned int v3; // edi
  int v5; // esi

  v3 = 0;
  v5 = 0;
  if ( !bypassed )
  {
    v5 = downSampleIndex;
    if ( this->mSampleRate > 0xBB80 )
      v5 = 2 * downSampleIndex;
  }
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(this, v5, this->FutzBoxMemMapPtr[v3++].XMemory, 3);
    while ( v3 < this->mNumChannels );
  }
}

// File Line: 489
// RVA: 0xB09840
void __fastcall FutzBoxLoFiMemoryMapHelper::SetDCFilter(
        FutzBoxLoFiMemoryMapHelper *this,
        long double filter,
        bool bypassed)
{
  double v3; // xmm2_8
  double v5; // xmm1_8
  unsigned int i; // ebx
  SCoefs outCoefs; // [rsp+20h] [rbp-38h] BYREF

  v3 = DOUBLE_20000_0;
  if ( !bypassed )
  {
    v5 = filter * 0.01;
    if ( v5 > 0.0 )
      v5 = sqrt(v5);
    v3 = 20000.0 - v5 * 19000.0;
  }
  CoefficientCalculator::CalculateDualHPFAndLPF(this->mSampleRate, 20.0, v3, &outCoefs);
  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetFilterCoefs(this, &outCoefs, this->FutzBoxMemMapPtr[i].XMemory, 4);
}

// File Line: 518
// RVA: 0xB098E0
void __fastcall FutzBoxLoFiMemoryMapHelper::SetBalanceLevels(FutzBoxLoFiMemoryMapHelper *this, long double balance)
{
  unsigned int i; // esi
  __int64 v4; // rbx

  for ( i = 0; i < this->mNumChannels; ++i )
  {
    v4 = i;
    DSPMemoryMapHelper::SetDoubleValue(this, balance * 0.01, this->FutzBoxMemMapPtr[v4].YMemory, 11);
    DSPMemoryMapHelper::SetDoubleValue(this, 1.0 - balance * 0.01, this->FutzBoxMemMapPtr[v4].YMemory, 12);
  }
}

// File Line: 535
// RVA: 0xB09990
void __fastcall FutzBoxLoFiMemoryMapHelper::SetDrySignalAddress(FutzBoxLoFiMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(this, 1, this->FutzBoxMemMapPtr[i].XMemory, 9);
}

// File Line: 541
// RVA: 0xB099F0
void __fastcall FutzBoxLoFiMemoryMapHelper::SetInputGain(FutzBoxLoFiMemoryMapHelper *this, long double gain)
{
  unsigned int v3; // ebx
  double i; // xmm6_8

  v3 = 0;
  for ( i = pow(10.0, gain * 0.05); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].YMemory, 0);
}

// File Line: 553
// RVA: 0xB09A70
void __fastcall FutzBoxLoFiMemoryMapHelper::SetOutputGain(FutzBoxLoFiMemoryMapHelper *this, long double gain)
{
  unsigned int v3; // ebx
  double i; // xmm6_8

  v3 = 0;
  for ( i = pow(10.0, gain * 0.05); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].YMemory, 10);
}

// File Line: 568
// RVA: 0xB09AE0
void __fastcall FutzLoFiImpl::FutzLoFiImpl(FutzLoFiImpl *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper);
  this->MemoryMapHelper.FutzBoxMemMapPtr = 0i64;
}

// File Line: 574
// RVA: 0xB09B10
// attributes: thunk
void __fastcall FutzLoFiImpl::~FutzLoFiImpl(FutzLoFiImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper);
}

// File Line: 581
// RVA: 0xB09B20
__int64 __fastcall FutzLoFiImpl::GetMemoryMapSize(FutzLoFiImpl *this, unsigned int numChannels)
{
  return 100i64 * numChannels;
}

// File Line: 590
// RVA: 0xB09B30
__int64 __fastcall FutzLoFiImpl::Init(
        FutzLoFiImpl *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->MemoryMapHelper.mNumChannels = numChannels;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 100i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x64ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxLoFiMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 598
// RVA: 0xB09B90
void __fastcall FutzLoFiImpl::SetParameters(FutzLoFiImpl *this, FutzLoFiParameters *lofiParams)
{
  unsigned int v2; // edi
  int v5; // ebp
  unsigned int i; // esi
  int downSampleIndex; // r14d
  unsigned int j; // esi
  unsigned int k; // esi
  double v10; // xmm6_8

  v2 = 0;
  v5 = 0;
  if ( !lofiParams->bypassed )
    v5 = 24 - sBitDepthMaskTable[lofiParams->bitDepthType];
  for ( i = 0; i < this->MemoryMapHelper.mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(&this->MemoryMapHelper, v5, this->MemoryMapHelper.FutzBoxMemMapPtr[i].XMemory, 2);
  downSampleIndex = 0;
  if ( !lofiParams->bypassed )
  {
    downSampleIndex = lofiParams->downSampleIndex;
    if ( this->MemoryMapHelper.mSampleRate > 0xBB80 )
      downSampleIndex *= 2;
  }
  for ( j = 0; j < this->MemoryMapHelper.mNumChannels; ++j )
    DSPMemoryMapHelper::SetLongValue(
      &this->MemoryMapHelper,
      downSampleIndex,
      this->MemoryMapHelper.FutzBoxMemMapPtr[j].XMemory,
      3);
  FutzBoxLoFiMemoryMapHelper::SetDCFilter(&this->MemoryMapHelper, lofiParams->filter, lofiParams->bypassed);
  FutzBoxLoFiMemoryMapHelper::SetBalanceLevels(&this->MemoryMapHelper, 100.0);
  for ( k = 0; k < this->MemoryMapHelper.mNumChannels; ++k )
    DSPMemoryMapHelper::SetLongValue(&this->MemoryMapHelper, 1, this->MemoryMapHelper.FutzBoxMemMapPtr[k].XMemory, 9);
  FutzBoxLoFiMemoryMapHelper::SetInputGain(&this->MemoryMapHelper, 0.0);
  v10 = pow(10.0, 0.0);
  if ( this->MemoryMapHelper.mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(
        &this->MemoryMapHelper,
        v10,
        this->MemoryMapHelper.FutzBoxMemMapPtr[v2++].YMemory,
        10);
    while ( v2 < this->MemoryMapHelper.mNumChannels );
  }
}

