// File Line: 91
// RVA: 0xB09D10
void __fastcall ProcessFutzLoFiChannel(FutzBoxLoFiMemoryMap *memoryMap, const float *inputBuf, float *outputBuf, unsigned int samplesRemaining)
{
  float v4; // xmm6_4
  unsigned int v5; // esi
  float *v6; // rbp
  const float *v7; // rdi
  FutzBoxLoFiMemoryMap *v8; // rbx
  float v9; // xmm9_4
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm13_4
  float v13; // xmm10_4
  float v14; // xmm14_4
  float v15; // xmm15_4
  double v16; // xmm0_8
  signed int v17; // ecx
  float i; // xmm12_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  signed int v22; // edx
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // [rsp+E0h] [rbp+8h]
  float v28; // [rsp+F8h] [rbp+20h]

  v4 = memoryMap->XMemory[2];
  v5 = samplesRemaining;
  v6 = outputBuf;
  v7 = inputBuf;
  v8 = memoryMap;
  v9 = memoryMap->YMemory[4];
  v10 = memoryMap->YMemory[5];
  v11 = memoryMap->YMemory[7];
  v12 = memoryMap->XMemory[4];
  v13 = memoryMap->YMemory[6];
  v28 = memoryMap->XMemory[7];
  v14 = memoryMap->XMemory[5];
  v15 = memoryMap->XMemory[6];
  v27 = memoryMap->XMemory[8];
  v16 = pow(2.0, COERCE_FLOAT(LODWORD(v4) ^ _xmm[0]));
  v17 = (signed int)v4;
  for ( i = v16; v5; *(v6 - 1) = v26 * v8->YMemory[10] )
  {
    --v5;
    ++v7;
    v19 = v8->YMemory[0] * *(v7 - 1);
    v8->YMemory[1] = v19;
    v20 = (float)(v19 * 8388607.0) * i;
    if ( v20 <= 0.0 )
      v21 = v20 - 0.5;
    else
      v21 = v20 + 0.5;
    v22 = (signed int)v21;
    v23 = v8->YMemory[3] - 1.0;
    v24 = (float)(v22 << v17) * 0.0000001192093;
    if ( v23 <= 0.0 )
      v23 = v8->XMemory[3];
    else
      v24 = v8->YMemory[2];
    v8->YMemory[3] = v23;
    v8->YMemory[2] = v24;
    ++v6;
    v25 = (float)((float)(v9 * v14) + (float)(v12 * v24)) + (float)(v10 * v15);
    v10 = v9;
    v9 = v24;
    v26 = (float)(v25 - (float)(v13 * v28)) - (float)(v11 * v27);
    v11 = v13;
    v13 = v26;
  }
  v8->YMemory[4] = v9;
  v8->YMemory[5] = v10;
  v8->YMemory[6] = v13;
  v8->YMemory[7] = v11;
}

// File Line: 317
// RVA: 0xB09670
char *__fastcall ProcessFutzBoxLoFiWwise(char *memoryBlock, float *pfChannelIn, float *pfChannelOut, unsigned int uNumSamples)
{
  char *v4; // rbx

  v4 = memoryBlock;
  ProcessFutzLoFiChannel((FutzBoxLoFiMemoryMap *)memoryBlock, pfChannelIn, pfChannelOut, uNumSamples);
  return v4 + 100;
}

// File Line: 403
// RVA: 0xB09690
void __fastcall FutzBoxLoFiMemoryMapHelper::FutzBoxLoFiMemoryMapHelper(FutzBoxLoFiMemoryMapHelper *this)
{
  FutzBoxLoFiMemoryMapHelper *v1; // rbx

  v1 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->0);
  v1->FutzBoxMemMapPtr = 0i64;
}

// File Line: 409
// RVA: 0xB096C0
void __fastcall FutzBoxLoFiMemoryMapHelper::~FutzBoxLoFiMemoryMapHelper(FutzBoxLoFiMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->0);
}

// File Line: 415
// RVA: 0xB096D0
signed __int64 __fastcall FutzBoxLoFiMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 100i64 * numChannels;
}

// File Line: 424
// RVA: 0xB096E0
__int64 __fastcall FutzBoxLoFiMemoryMapHelper::Init(FutzBoxLoFiMemoryMapHelper *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzBoxLoFiMemoryMapHelper *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  v4 = this;
  this->mSampleRate = sampleRate;
  v5 = 100i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x64ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->FutzBoxMemMapPtr = (FutzBoxLoFiMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 443
// RVA: 0xB09740
FutzBoxLoFiMemoryMap *__fastcall FutzBoxLoFiMemoryMapHelper::GetMemoryMap(FutzBoxLoFiMemoryMapHelper *this, unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 452
// RVA: 0xB09760
void __fastcall FutzBoxLoFiMemoryMapHelper::SetBitDepth(FutzBoxLoFiMemoryMapHelper *this, FutzBitDepthType bitDepthType, bool bypassed)
{
  unsigned int v3; // ebx
  FutzBoxLoFiMemoryMapHelper *v4; // rdi
  int v5; // esi

  v3 = 0;
  v4 = this;
  v5 = 0;
  if ( !bypassed )
    v5 = 24 - sBitDepthMaskTable[bitDepthType];
  if ( this->mNumChannels > 0 )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v4->0, v5, v4->FutzBoxMemMapPtr[v3++].XMemory, 2);
    while ( v3 < v4->mNumChannels );
  }
}

// File Line: 467
// RVA: 0xB097D0
void __fastcall FutzBoxLoFiMemoryMapHelper::SetDownSampleHoldCount(FutzBoxLoFiMemoryMapHelper *this, unsigned int downSampleIndex, bool bypassed)
{
  unsigned int v3; // edi
  FutzBoxLoFiMemoryMapHelper *v4; // rbx
  int v5; // esi

  v3 = 0;
  v4 = this;
  v5 = 0;
  if ( !bypassed )
  {
    v5 = downSampleIndex;
    if ( this->mSampleRate > 0xBB80 )
      v5 = 2 * downSampleIndex;
  }
  if ( this->mNumChannels > 0 )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v4->0, v5, v4->FutzBoxMemMapPtr[v3++].XMemory, 3);
    while ( v3 < v4->mNumChannels );
  }
}

// File Line: 489
// RVA: 0xB09840
void __fastcall FutzBoxLoFiMemoryMapHelper::SetDCFilter(FutzBoxLoFiMemoryMapHelper *this, long double filter, bool bypassed)
{
  double v3; // xmm2_8
  FutzBoxLoFiMemoryMapHelper *v4; // rdi
  double v5; // xmm1_8
  unsigned int v6; // ebx
  SCoefs outCoefs; // [rsp+20h] [rbp-38h]

  v3 = DOUBLE_20000_0;
  v4 = this;
  if ( !bypassed )
  {
    v5 = filter * 0.01;
    if ( v5 > 0.0 )
      v5 = sqrt(v5);
    v3 = 20000.0 - v5 * 19000.0;
  }
  CoefficientCalculator::CalculateDualHPFAndLPF(this->mSampleRate, 20.0, v3, &outCoefs);
  v6 = 0;
  if ( v4->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetFilterCoefs(&v4->0, &outCoefs, v4->FutzBoxMemMapPtr[v6++].XMemory, 4);
    while ( v6 < v4->mNumChannels );
  }
}

// File Line: 518
// RVA: 0xB098E0
void __fastcall FutzBoxLoFiMemoryMapHelper::SetBalanceLevels(FutzBoxLoFiMemoryMapHelper *this, long double balance)
{
  unsigned int v2; // esi
  FutzBoxLoFiMemoryMapHelper *v3; // rdi
  signed __int64 v4; // rbx

  v2 = 0;
  v3 = this;
  if ( this->mNumChannels )
  {
    do
    {
      v4 = v2;
      DSPMemoryMapHelper::SetDoubleValue(&v3->0, balance * 0.01, v3->FutzBoxMemMapPtr[v4].YMemory, 11);
      DSPMemoryMapHelper::SetDoubleValue(&v3->0, 1.0 - balance * 0.01, v3->FutzBoxMemMapPtr[v4].YMemory, 12);
      ++v2;
    }
    while ( v2 < v3->mNumChannels );
  }
}

// File Line: 535
// RVA: 0xB09990
void __fastcall FutzBoxLoFiMemoryMapHelper::SetDrySignalAddress(FutzBoxLoFiMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzBoxLoFiMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v2->0, 1, v2->FutzBoxMemMapPtr[v1++].XMemory, 9);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 541
// RVA: 0xB099F0
void __fastcall FutzBoxLoFiMemoryMapHelper::SetInputGain(FutzBoxLoFiMemoryMapHelper *this, long double gain)
{
  FutzBoxLoFiMemoryMapHelper *v2; // rdi
  unsigned int v3; // ebx
  double v4; // xmm6_8

  v2 = this;
  v3 = 0;
  v4 = pow(10.0, gain * 0.05);
  if ( v2->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, v4, v2->FutzBoxMemMapPtr[v3++].YMemory, 0);
    while ( v3 < v2->mNumChannels );
  }
}

// File Line: 553
// RVA: 0xB09A70
void __fastcall FutzBoxLoFiMemoryMapHelper::SetOutputGain(FutzBoxLoFiMemoryMapHelper *this, long double gain)
{
  FutzBoxLoFiMemoryMapHelper *v2; // rdi
  unsigned int v3; // ebx
  double v4; // xmm6_8

  v2 = this;
  v3 = 0;
  v4 = pow(10.0, gain * 0.05);
  if ( v2->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, v4, v2->FutzBoxMemMapPtr[v3++].YMemory, 10);
    while ( v3 < v2->mNumChannels );
  }
}

// File Line: 568
// RVA: 0xB09AE0
void __fastcall FutzLoFiImpl::FutzLoFiImpl(FutzLoFiImpl *this)
{
  FutzLoFiImpl *v1; // rbx

  v1 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper.0);
  v1->MemoryMapHelper.FutzBoxMemMapPtr = 0i64;
}

// File Line: 574
// RVA: 0xB09B10
void __fastcall FutzLoFiImpl::~FutzLoFiImpl(FutzLoFiImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper.0);
}

// File Line: 581
// RVA: 0xB09B20
signed __int64 __fastcall FutzLoFiImpl::GetMemoryMapSize(FutzLoFiImpl *this, unsigned int numChannels)
{
  return 100i64 * numChannels;
}

// File Line: 590
// RVA: 0xB09B30
__int64 __fastcall FutzLoFiImpl::Init(FutzLoFiImpl *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzLoFiImpl *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->MemoryMapHelper.mNumChannels = numChannels;
  v4 = this;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 100i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x64ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxLoFiMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 598
// RVA: 0xB09B90
void __fastcall FutzLoFiImpl::SetParameters(FutzLoFiImpl *this, FutzLoFiParameters *lofiParams)
{
  unsigned int v2; // edi
  FutzLoFiParameters *v3; // r15
  FutzLoFiImpl *v4; // rbx
  int v5; // ebp
  unsigned int v6; // esi
  int v7; // er14
  unsigned int i; // esi
  unsigned int j; // esi
  double v10; // xmm6_8

  v2 = 0;
  v3 = lofiParams;
  v4 = this;
  v5 = 0;
  if ( !lofiParams->bypassed )
    v5 = 24 - sBitDepthMaskTable[lofiParams->bitDepthType];
  v6 = 0;
  if ( this->MemoryMapHelper.mNumChannels > 0 )
  {
    do
      DSPMemoryMapHelper::SetLongValue(
        &v4->MemoryMapHelper.0,
        v5,
        v4->MemoryMapHelper.FutzBoxMemMapPtr[v6++].XMemory,
        2);
    while ( v6 < v4->MemoryMapHelper.mNumChannels );
  }
  v7 = 0;
  if ( !v3->bypassed )
  {
    v7 = v3->downSampleIndex;
    if ( v4->MemoryMapHelper.mSampleRate > 0xBB80 )
      v7 *= 2;
  }
  for ( i = 0; i < v4->MemoryMapHelper.mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(&v4->MemoryMapHelper.0, v7, v4->MemoryMapHelper.FutzBoxMemMapPtr[i].XMemory, 3);
  FutzBoxLoFiMemoryMapHelper::SetDCFilter(&v4->MemoryMapHelper, v3->filter, v3->bypassed);
  FutzBoxLoFiMemoryMapHelper::SetBalanceLevels(&v4->MemoryMapHelper, 100.0);
  for ( j = 0; j < v4->MemoryMapHelper.mNumChannels; ++j )
    DSPMemoryMapHelper::SetLongValue(&v4->MemoryMapHelper.0, 1, v4->MemoryMapHelper.FutzBoxMemMapPtr[j].XMemory, 9);
  FutzBoxLoFiMemoryMapHelper::SetInputGain(&v4->MemoryMapHelper, 0.0);
  v10 = pow(10.0, 0.0);
  if ( v4->MemoryMapHelper.mNumChannels > 0 )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(
        &v4->MemoryMapHelper.0,
        v10,
        v4->MemoryMapHelper.FutzBoxMemMapPtr[v2++].YMemory,
        10);
    while ( v2 < v4->MemoryMapHelper.mNumChannels );
  }
}

