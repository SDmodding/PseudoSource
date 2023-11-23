// File Line: 106
// RVA: 0xB065E0
void __fastcall ProcessFutzDistortionChannel(
        FutzBoxDistortionMemoryMap *memoryMap,
        const float *inputBuf,
        float *outputBuf,
        unsigned int samplesRemaining)
{
  float v7; // xmm6_4
  float v8; // xmm3_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  __m128 v14; // xmm5
  float v15; // xmm1_4
  int v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm4_4
  float v25; // xmm4_4
  float v26; // xmm4_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm0_4
  float v30; // xmm4_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm4_4

  for ( ;
        samplesRemaining;
        *(outputBuf - 1) = (float)(v7 * memoryMap->YMemory[17])
                         + (float)(memoryMap->YMemory[16] * (float)(v33 * memoryMap->YMemory[15])) )
  {
    --samplesRemaining;
    v7 = memoryMap->YMemory[0] * *inputBuf++;
    memoryMap->YMemory[1] = v7;
    LODWORD(v8) = LODWORD(v7) & _xmm;
    if ( COERCE_FLOAT(LODWORD(v7) & _xmm) >= 1.0 )
      v8 = *(float *)&FLOAT_1_0;
    v9 = v8 - memoryMap->XMemory[2];
    if ( v9 <= 0.0 )
      v9 = 0.0;
    v14 = (__m128)LODWORD(memoryMap->YMemory[2]);
    v10 = memoryMap->XMemory[6];
    v11 = v9;
    v12 = v9 * memoryMap->XMemory[4];
    v14.m128_f32[0] = v14.m128_f32[0] * memoryMap->XMemory[5];
    memoryMap->YMemory[2] = v11;
    v14.m128_f32[0] = (float)((float)(v14.m128_f32[0] + v12) * 0.5) - (float)(v10 * memoryMap->YMemory[3]);
    LODWORD(memoryMap->YMemory[3]) = v14.m128_i32[0];
    v13 = v14.m128_f32[0];
    v14.m128_f32[0] = v14.m128_f32[0] * 255.0;
    v15 = v14.m128_f32[0];
    v16 = (int)v14.m128_f32[0];
    if ( (int)v14.m128_f32[0] != 0x80000000 && (float)v16 != v14.m128_f32[0] )
      v15 = (float)(v16 - (_mm_movemask_ps(_mm_unpacklo_ps(v14, v14)) & 1));
    v17 = memoryMap->YMemory[5];
    v18 = memoryMap->XMemory[7];
    v19 = (float)((float)((float)(v14.m128_f32[0] - v15) * memoryMap->YMemory[(int)v14.m128_f32[0] + 19])
                - (float)((float)((float)(v14.m128_f32[0] - v15) - memoryMap->YMemory[4])
                        * memoryMap->YMemory[(int)v14.m128_f32[0] + 18]))
        - v17;
    if ( v19 < 0.0 )
      v18 = memoryMap->XMemory[8];
    v20 = (float)(v13 * memoryMap->XMemory[9]) + v18;
    v21 = 0.0;
    v22 = v20 * v19;
    v23 = memoryMap->XMemory[11];
    v24 = v22 + v17;
    memoryMap->YMemory[5] = v24;
    v25 = (float)(v24 * v7) * memoryMap->YMemory[7];
    if ( v23 > v25 )
      v21 = memoryMap->YMemory[8];
    v26 = v25 + (float)(v21 * v25);
    if ( v26 < 1.0 )
    {
      if ( v26 <= -1.0 )
        v26 = FLOAT_N1_0;
    }
    else
    {
      v26 = *(float *)&FLOAT_1_0;
    }
    v27 = memoryMap->YMemory[9];
    memoryMap->YMemory[9] = v26;
    ++outputBuf;
    v28 = (float)(v26 * memoryMap->XMemory[12]) + (float)(v27 * memoryMap->XMemory[13]);
    v29 = memoryMap->YMemory[10];
    memoryMap->YMemory[10] = v27;
    v30 = v28 + (float)(v29 * memoryMap->XMemory[14]);
    v31 = memoryMap->YMemory[12] * memoryMap->XMemory[16];
    v32 = memoryMap->YMemory[11] * memoryMap->XMemory[15];
    memoryMap->YMemory[12] = memoryMap->YMemory[11];
    v33 = (float)(v30 - v32) - v31;
    memoryMap->YMemory[11] = v33;
  }
}

// File Line: 370
// RVA: 0xB055B0
FutzBoxDistortionMemoryMap *__fastcall ProcessFutzBoxDistortionWwise(
        FutzBoxDistortionMemoryMap *memoryBlock,
        const float *pfChannelIn,
        float *pfChannelOut,
        unsigned int uNumSamples)
{
  ProcessFutzDistortionChannel(memoryBlock, pfChannelIn, pfChannelOut, uNumSamples);
  return memoryBlock + 1;
}

// File Line: 406
// RVA: 0xB06890
void __fastcall GenerateDistortionTable(long double amount, bool bypassed, long double *compTable, int compTableSize)
{
  double v6; // xmm7_8
  double v8; // xmm10_8
  double v9; // xmm12_8
  signed int v10; // edi
  __m128d v11; // xmm9
  __m128i si128; // xmm14
  __m128d v13; // xmm11
  __m128d v14; // xmm0
  __int64 v15; // rbx
  __m128d v16; // xmm0
  long double *v17; // rbx
  double v18; // xmm0_8
  double v19; // [rsp+28h] [rbp-B0h]

  v19 = DOUBLE_1_0;
  v6 = DOUBLE_1_0;
  v8 = 1.0 / (double)compTableSize;
  v9 = DOUBLE_1_0;
  if ( !bypassed )
  {
    v19 = pow(10.0, -2.4);
    v9 = v19;
    v6 = amount * 0.01 * 9.0 + 1.0;
  }
  v10 = 0;
  if ( compTableSize >= 4 )
  {
    v11 = _mm_unpacklo_pd((__m128d)*(unsigned __int64 *)&v8, (__m128d)*(unsigned __int64 *)&v8);
    si128 = _mm_load_si128((const __m128i *)&_xmm);
    v13 = _mm_unpacklo_pd((__m128d)*(unsigned __int64 *)&v19, (__m128d)*(unsigned __int64 *)&v19);
    do
    {
      v14 = _mm_add_pd(
              _mm_div_pd(
                _mm_mul_pd(_mm_cvtepi32_pd(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v10), 0), si128)), v11),
                v13),
              *(__m128d *)_xmm);
      v14.m128d_f64[0] = _vdecl_pow2();
      *(__m128d *)&compTable[v10] = v14;
      v15 = v10 + 2;
      v16 = _mm_add_pd(
              _mm_div_pd(
                _mm_mul_pd(_mm_cvtepi32_pd(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v10 + 2), 0), si128)), v11),
                v13),
              *(__m128d *)_xmm);
      v16.m128d_f64[0] = _vdecl_pow2();
      v10 += 4;
      *(__m128d *)&compTable[v15] = v16;
    }
    while ( v10 < (int)(compTableSize - (compTableSize & 0x80000003)) );
  }
  if ( v10 < compTableSize )
  {
    v17 = &compTable[v10];
    do
    {
      v18 = pow((double)v10++ * v8 * (1.0 / v9) + 1.0, 1.0 / v6 - 1.0);
      *v17++ = v18;
    }
    while ( v10 < compTableSize );
  }
}

// File Line: 442
// RVA: 0xB055E0
void __fastcall FutzDistortionDSPMemoryMapHelper::FutzDistortionDSPMemoryMapHelper(
        FutzDistortionDSPMemoryMapHelper *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(this);
  this->FutzBoxMemMapPtr = 0i64;
}

// File Line: 448
// RVA: 0xB05610
// attributes: thunk
void __fastcall FutzDistortionDSPMemoryMapHelper::~FutzDistortionDSPMemoryMapHelper(
        FutzDistortionDSPMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(this);
}

// File Line: 454
// RVA: 0xB05620
__int64 __fastcall FutzDistortionDSPMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 1176i64 * numChannels;
}

// File Line: 464
// RVA: 0xB05630
__int64 __fastcall FutzDistortionDSPMemoryMapHelper::Init(
        FutzDistortionDSPMemoryMapHelper *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  this->mSampleRate = sampleRate;
  v5 = 1176i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x498ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->FutzBoxMemMapPtr = (FutzBoxDistortionMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 481
// RVA: 0xB05690
FutzBoxDistortionMemoryMap *__fastcall FutzDistortionDSPMemoryMapHelper::GetMemoryMap(
        FutzDistortionDSPMemoryMapHelper *this,
        unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 490
// RVA: 0xB056B0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistPassingGain(FutzDistortionDSPMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetDoubleValue(this, 1.0, this->FutzBoxMemMapPtr[i].YMemory, 4);
}

// File Line: 500
// RVA: 0xB05720
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistTable(
        FutzDistortionDSPMemoryMapHelper *this,
        long double amount,
        bool bypassed)
{
  unsigned int i; // ebx

  GenerateDistortionTable(amount, bypassed, sDist_Table, 256);
  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetTableValues(this, sDist_Table, 256, this->FutzBoxMemMapPtr[i].YMemory, 18);
}

// File Line: 510
// RVA: 0xB057A0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistTableAddress(FutzDistortionDSPMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(this, 18, this->FutzBoxMemMapPtr[i].XMemory, 3);
}

// File Line: 518
// RVA: 0xB05800
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistAmount(
        FutzDistortionDSPMemoryMapHelper *this,
        long double amount,
        bool bypassed)
{
  double v3; // xmm6_8
  unsigned int i; // ebx

  v3 = DOUBLE_1_0;
  if ( !bypassed )
    v3 = pow(10.0, -2.4);
  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetDoubleValue(this, v3, this->FutzBoxMemMapPtr[i].XMemory, 2);
}

// File Line: 538
// RVA: 0xB05880
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistMakeupGain(
        FutzDistortionDSPMemoryMapHelper *this,
        long double amount,
        FutzDistortionMode mode,
        bool bypassed)
{
  __int64 v4; // rbx
  double v6; // xmm10_8
  double v7; // xmm2_8
  double v8; // xmm9_8
  int v9; // edi
  double v10; // xmm6_8
  double v11; // xmm0_8
  double v12; // xmm1_8
  unsigned int v13; // ebx
  double i; // xmm6_8

  v4 = mode;
  v6 = 0.0;
  v7 = DOUBLE_1_0;
  v8 = 0.0;
  if ( !bypassed )
  {
    v8 = amount * 0.01;
    v7 = pow(10.0, -2.4);
    v6 = amount * 0.01 * sTemp_Makeup_Adjustments[v4];
  }
  v9 = (int)(v8 * 20.0);
  v10 = sTempTable[v9];
  v11 = pow((1.0 - v7) / v7 + 1.0, 1.0 / (v8 * 9.0 + 1.0) - 1.0);
  v12 = (log10(((1.0 / v11 - 1.0) * v8 + 1.0) * ((qword_142100C28[v9] - v10) * (v8 * 20.0 - (double)v9) + v10)) * 20.0
       + v6)
      * 0.05;
  v13 = 0;
  for ( i = pow(10.0, v12); v13 < this->mNumChannels; ++v13 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v13].YMemory, 7);
}

// File Line: 598
// RVA: 0xB05A40
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistTimes(
        FutzDistortionDSPMemoryMapHelper *this,
        long double amount,
        FutzDistortionMode mode)
{
  double v4; // xmm7_8
  long double v5; // xmm8_8
  long double v6; // xmm6_8
  long double v7; // xmm6_8
  long double v8; // xmm6_8
  long double v9; // xmm6_8
  long double v10; // xmm6_8
  unsigned int v11; // esi
  long double i; // xmm7_8
  __int64 v13; // rbx
  double v14; // [rsp+60h] [rbp+8h]

  v4 = amount * 0.01;
  if ( amount * 0.01 > 0.0 )
    v4 = sqrt(v4);
  switch ( mode )
  {
    case eFutzDistMode_Sat1:
      v5 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v4 * 7.800000000000001 + 4.35);
      v6 = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, 0.85 - v4 * 0.5);
      break;
    case eFutzDistMode_Sat2:
      v5 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v4 * 17.1 + 1.15);
      v6 = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, 0.25 - v4 * 0.15);
      break;
    case eFutzDistMode_Fuzz:
      v5 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, 2.35 - v4 * 0.9500000000000002);
      v6 = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, 0.35 - v4 * 0.09999999999999998);
      break;
    case eFutzDistMode_LoFi:
      v5 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, 0.95 - v4 * 0.2);
      v6 = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, 0.25 - v4 * 0.15);
      break;
    case eFutzDistMode_Soft:
      v5 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, 8.25 - v4 * 7.9);
      v6 = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, v4 * 0.0 + 0.25);
      break;
    case eFutzDistMode_Stun:
      v5 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, 2.15 - v4 * 1.9);
      v6 = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, 0.5 - v4 * 0.3);
      break;
    case eFutzDistMode_Ouch:
      v7 = 0.7 - v4 * 0.5499999999999999;
      v5 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v7);
      v6 = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, v7);
      break;
    case eFutzDistMode_Hard:
      v8 = 0.35 - v4 * 0.25;
      v5 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v8);
      v6 = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, v8);
      break;
    case eFutzDistMode_Nuke:
      v9 = 0.25 - v4 * 0.2;
      v5 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v9);
      v6 = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, v9);
      break;
    case eFutzDistMode_Clip:
      v10 = 0.1 - v4 * 0.09000000000000001;
      v5 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v10);
      v6 = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, v10);
      break;
    default:
      v5 = v14;
      v6 = v14;
      break;
  }
  v11 = 0;
  for ( i = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, 0.01) - v6; v11 < this->mNumChannels; ++v11 )
  {
    v13 = v11;
    DSPMemoryMapHelper::SetDoubleValue(this, v6, this->FutzBoxMemMapPtr[v13].XMemory, 8);
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v13].XMemory, 9);
    DSPMemoryMapHelper::SetDoubleValue(this, v5, this->FutzBoxMemMapPtr[v13].XMemory, 7);
  }
}

// File Line: 691
// RVA: 0xB05DD0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistKeyFilter(
        FutzDistortionDSPMemoryMapHelper *this,
        long double amount,
        long double intensity,
        FutzDistortionMode mode)
{
  double v5; // xmm4_8
  double v6; // xmm3_8
  double v7; // xmm0_8
  double v8; // xmm2_8
  double v9; // xmm1_8
  unsigned int i; // ebx
  double v11; // [rsp+30h] [rbp+8h]

  v5 = amount * 0.01;
  v6 = intensity * 0.01;
  switch ( mode )
  {
    case eFutzDistMode_Sat1:
      v7 = DOUBLE_100_0;
      v8 = DOUBLE_150_0;
      v9 = DOUBLE_17500_0;
      break;
    case eFutzDistMode_Sat2:
      v7 = DOUBLE_100_0;
      v8 = DOUBLE_300_0;
      v9 = DOUBLE_20000_0;
      break;
    case eFutzDistMode_Fuzz:
      v7 = DOUBLE_300_0;
      v9 = DOUBLE_10000_0;
      v8 = DOUBLE_300_0;
      break;
    case eFutzDistMode_LoFi:
      v7 = DOUBLE_150_0;
      v8 = DOUBLE_300_0;
      v9 = DOUBLE_12000_0;
      break;
    case eFutzDistMode_Soft:
      v7 = DOUBLE_100_0;
      v8 = DOUBLE_200_0;
      v9 = DOUBLE_14000_0;
      break;
    case eFutzDistMode_Stun:
      v7 = DOUBLE_150_0;
      v8 = DOUBLE_300_0;
      v9 = DOUBLE_16000_0;
      break;
    case eFutzDistMode_Ouch:
      v7 = DOUBLE_200_0;
      v8 = DOUBLE_400_0;
      v9 = DOUBLE_18000_0;
      break;
    case eFutzDistMode_Hard:
      v7 = DOUBLE_100_0;
      v8 = DOUBLE_1000_0;
      v9 = DOUBLE_20000_0;
      break;
    case eFutzDistMode_Nuke:
      v7 = DOUBLE_200_0;
      v8 = DOUBLE_2000_0;
      v9 = DOUBLE_20000_0;
      break;
    case eFutzDistMode_Clip:
      v7 = DOUBLE_150_0;
      v8 = DOUBLE_1500_0;
      v9 = DOUBLE_20000_0;
      break;
    default:
      v7 = v11;
      v8 = v11;
      v9 = v11;
      break;
  }
  CoefficientCalculator::CalculateFirstOrderLowPass(
    this->mSampleRate,
    ((v9 - v8) * v6 + v8 - v7) * v5 + v7,
    &sDist_Key_Coefs);
  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetFirstOrderFilterCoefs(this, &sDist_Key_Coefs, this->FutzBoxMemMapPtr[i].XMemory, 4);
}

// File Line: 730
// RVA: 0xB05FD0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetHarmonicsThreshold(FutzDistortionDSPMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetDoubleValue(this, 0.0, this->FutzBoxMemMapPtr[i].XMemory, 11);
}

// File Line: 740
// RVA: 0xB06030
void __fastcall FutzDistortionDSPMemoryMapHelper::SetHarmonicsOffset(
        FutzDistortionDSPMemoryMapHelper *this,
        long double rectify)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetDoubleValue(this, rectify * 0.01 * -2.0, this->FutzBoxMemMapPtr[i].YMemory, 8);
}

// File Line: 754
// RVA: 0xB060B0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDCFilter(FutzDistortionDSPMemoryMapHelper *this)
{
  unsigned int i; // edi
  SCoefs outCoefs; // [rsp+20h] [rbp-38h] BYREF

  CoefficientCalculator::CalculateFirstOrderHighPass(this->mSampleRate, 20.0, &outCoefs);
  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetFilterCoefs(this, &outCoefs, this->FutzBoxMemMapPtr[i].XMemory, 12);
}

// File Line: 768
// RVA: 0xB06120
void __fastcall FutzDistortionDSPMemoryMapHelper::SetBalanceLevels(
        FutzDistortionDSPMemoryMapHelper *this,
        long double balance)
{
  unsigned int i; // esi
  __int64 v4; // rbx

  for ( i = 0; i < this->mNumChannels; ++i )
  {
    v4 = i;
    DSPMemoryMapHelper::SetDoubleValue(this, balance * 0.01, this->FutzBoxMemMapPtr[v4].YMemory, 16);
    DSPMemoryMapHelper::SetDoubleValue(this, 1.0 - balance * 0.01, this->FutzBoxMemMapPtr[v4].YMemory, 17);
  }
}

// File Line: 785
// RVA: 0xB061D0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDrySignalAddress(FutzDistortionDSPMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(this, 1, this->FutzBoxMemMapPtr[i].XMemory, 17);
}

// File Line: 793
// RVA: 0xB06230
void __fastcall FutzDistortionDSPMemoryMapHelper::SetInputGain(
        FutzDistortionDSPMemoryMapHelper *this,
        long double gain)
{
  unsigned int v3; // ebx
  double i; // xmm6_8

  v3 = 0;
  for ( i = pow(10.0, gain * 0.05); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].YMemory, 0);
}

// File Line: 805
// RVA: 0xB062B0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetOutputGain(
        FutzDistortionDSPMemoryMapHelper *this,
        long double gain)
{
  unsigned int v3; // ebx
  double i; // xmm6_8

  v3 = 0;
  for ( i = pow(10.0, gain * 0.05); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].YMemory, 15);
}

// File Line: 819
// RVA: 0xB06330
void __fastcall FutzDistortionImpl::FutzDistortionImpl(FutzDistortionImpl *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper);
  this->MemoryMapHelper.FutzBoxMemMapPtr = 0i64;
}

// File Line: 825
// RVA: 0xB06360
// attributes: thunk
void __fastcall FutzDistortionImpl::~FutzDistortionImpl(FutzDistortionImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper);
}

// File Line: 832
// RVA: 0xB06370
__int64 __fastcall FutzDistortionImpl::GetMemoryMapSize(FutzDistortionImpl *this, unsigned int numChannels)
{
  return 1176i64 * numChannels;
}

// File Line: 841
// RVA: 0xB06380
__int64 __fastcall FutzDistortionImpl::Init(
        FutzDistortionImpl *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->MemoryMapHelper.mNumChannels = numChannels;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 1176i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x498ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxDistortionMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 849
// RVA: 0xB063E0
void __fastcall FutzDistortionImpl::SetParameters(FutzDistortionImpl *this, FutzDistortionParameters *distortionParams)
{
  unsigned int v2; // edi
  unsigned int i; // esi
  unsigned int j; // esi
  unsigned int k; // esi
  unsigned int m; // esi
  double v9; // xmm6_8

  v2 = 0;
  for ( i = 0; i < this->MemoryMapHelper.mNumChannels; ++i )
    DSPMemoryMapHelper::SetDoubleValue(
      &this->MemoryMapHelper,
      1.0,
      this->MemoryMapHelper.FutzBoxMemMapPtr[i].YMemory,
      4);
  FutzDistortionDSPMemoryMapHelper::SetDistTable(
    &this->MemoryMapHelper,
    distortionParams->amount,
    distortionParams->bypassed);
  for ( j = 0; j < this->MemoryMapHelper.mNumChannels; ++j )
    DSPMemoryMapHelper::SetLongValue(&this->MemoryMapHelper, 18, this->MemoryMapHelper.FutzBoxMemMapPtr[j].XMemory, 3);
  FutzDistortionDSPMemoryMapHelper::SetDistAmount(
    &this->MemoryMapHelper,
    distortionParams->amount,
    distortionParams->bypassed);
  FutzDistortionDSPMemoryMapHelper::SetDistMakeupGain(
    &this->MemoryMapHelper,
    distortionParams->amount,
    distortionParams->mode,
    distortionParams->bypassed);
  FutzDistortionDSPMemoryMapHelper::SetDistTimes(
    &this->MemoryMapHelper,
    distortionParams->amount,
    distortionParams->mode);
  FutzDistortionDSPMemoryMapHelper::SetDistKeyFilter(
    &this->MemoryMapHelper,
    distortionParams->amount,
    distortionParams->intensity,
    distortionParams->mode);
  for ( k = 0; k < this->MemoryMapHelper.mNumChannels; ++k )
    DSPMemoryMapHelper::SetDoubleValue(
      &this->MemoryMapHelper,
      0.0,
      this->MemoryMapHelper.FutzBoxMemMapPtr[k].XMemory,
      11);
  FutzDistortionDSPMemoryMapHelper::SetHarmonicsOffset(&this->MemoryMapHelper, distortionParams->rectify);
  FutzDistortionDSPMemoryMapHelper::SetDCFilter(&this->MemoryMapHelper);
  FutzDistortionDSPMemoryMapHelper::SetBalanceLevels(&this->MemoryMapHelper, 100.0);
  for ( m = 0; m < this->MemoryMapHelper.mNumChannels; ++m )
    DSPMemoryMapHelper::SetLongValue(&this->MemoryMapHelper, 1, this->MemoryMapHelper.FutzBoxMemMapPtr[m].XMemory, 17);
  FutzDistortionDSPMemoryMapHelper::SetInputGain(&this->MemoryMapHelper, 0.0);
  v9 = pow(10.0, 0.0);
  if ( this->MemoryMapHelper.mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(
        &this->MemoryMapHelper,
        v9,
        this->MemoryMapHelper.FutzBoxMemMapPtr[v2++].YMemory,
        15);
    while ( v2 < this->MemoryMapHelper.mNumChannels );
  }
}

