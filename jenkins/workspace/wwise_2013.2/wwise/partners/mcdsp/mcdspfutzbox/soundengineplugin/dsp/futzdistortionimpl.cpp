// File Line: 106
// RVA: 0xB065E0
void __fastcall ProcessFutzDistortionChannel(FutzBoxDistortionMemoryMap *memoryMap, const float *inputBuf, float *outputBuf, unsigned int samplesRemaining)
{
  float *v4; // rsi
  const float *v5; // r10
  FutzBoxDistortionMemoryMap *v6; // r11
  float v7; // xmm6_4
  float v8; // xmm3_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  __m128 v14; // xmm5
  float v15; // xmm1_4
  signed int v16; // ecx
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

  if ( samplesRemaining )
  {
    v4 = outputBuf;
    v5 = inputBuf;
    v6 = memoryMap;
    do
    {
      --samplesRemaining;
      ++v5;
      v7 = v6->YMemory[0] * *(v5 - 1);
      v6->YMemory[1] = v7;
      LODWORD(v8) = LODWORD(v7) & _xmm;
      if ( COERCE_FLOAT(LODWORD(v7) & _xmm) >= 1.0 )
        v8 = *(float *)&FLOAT_1_0;
      v9 = v8 - v6->XMemory[2];
      if ( v9 <= 0.0 )
        v9 = 0.0;
      v14 = (__m128)LODWORD(v6->YMemory[2]);
      v10 = v6->XMemory[6];
      v11 = v9;
      v12 = v9 * v6->XMemory[4];
      v14.m128_f32[0] = v14.m128_f32[0] * v6->XMemory[5];
      v6->YMemory[2] = v11;
      v14.m128_f32[0] = (float)((float)(v14.m128_f32[0] + v12) * 0.5) - (float)(v10 * v6->YMemory[3]);
      LODWORD(v6->YMemory[3]) = v14.m128_i32[0];
      v13 = v14.m128_f32[0];
      v14.m128_f32[0] = v14.m128_f32[0] * 255.0;
      v15 = v14.m128_f32[0];
      v16 = (signed int)v14.m128_f32[0];
      if ( (signed int)v14.m128_f32[0] != 0x80000000 && (float)v16 != v14.m128_f32[0] )
        v15 = (float)(v16 - (_mm_movemask_ps(_mm_unpacklo_ps(v14, v14)) & 1));
      v17 = v6->YMemory[5];
      v18 = v6->XMemory[7];
      v19 = (float)((float)((float)(v14.m128_f32[0] - v15) * v6->YMemory[(signed int)v14.m128_f32[0] + 19])
                  - (float)((float)((float)(v14.m128_f32[0] - v15) - v6->YMemory[4])
                          * v6->YMemory[(signed int)v14.m128_f32[0] + 18]))
          - v17;
      if ( v19 < 0.0 )
        v18 = v6->XMemory[8];
      v20 = (float)(v13 * v6->XMemory[9]) + v18;
      v21 = 0.0;
      v22 = v20 * v19;
      v23 = v6->XMemory[11];
      v24 = v22 + v17;
      v6->YMemory[5] = v24;
      v25 = (float)(v24 * v7) * v6->YMemory[7];
      if ( v23 > v25 )
        v21 = v6->YMemory[8];
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
      v27 = v6->YMemory[9];
      v6->YMemory[9] = v26;
      ++v4;
      v28 = (float)(v26 * v6->XMemory[12]) + (float)(v27 * v6->XMemory[13]);
      v29 = v6->YMemory[10];
      v6->YMemory[10] = v27;
      v30 = v28 + (float)(v29 * v6->XMemory[14]);
      v31 = v6->YMemory[12] * v6->XMemory[16];
      v32 = v6->YMemory[11] * v6->XMemory[15];
      v6->YMemory[12] = v6->YMemory[11];
      v33 = (float)(v30 - v32) - v31;
      v6->YMemory[11] = v33;
      *(v4 - 1) = (float)(v7 * v6->YMemory[17]) + (float)(v6->YMemory[16] * (float)(v33 * v6->YMemory[15]));
    }
    while ( samplesRemaining );
  }
}

// File Line: 370
// RVA: 0xB055B0
char *__fastcall ProcessFutzBoxDistortionWwise(char *memoryBlock, float *pfChannelIn, float *pfChannelOut, unsigned int uNumSamples)
{
  char *v4; // rbx

  v4 = memoryBlock;
  ProcessFutzDistortionChannel((FutzBoxDistortionMemoryMap *)memoryBlock, pfChannelIn, pfChannelOut, uNumSamples);
  return v4 + 1176;
}

// File Line: 406
// RVA: 0xB06890
void __fastcall GenerateDistortionTable(long double amount, bool bypassed, long double *compTable, int compTableSize)
{
  int v4; // esi
  long double *v5; // r14
  double v6; // xmm7_8
  double v7; // xmm8_8
  double v8; // xmm10_8
  double v9; // xmm12_8
  signed int v10; // edi
  __m128d v11; // xmm9
  __m128i v12; // xmm14
  __m128d v13; // xmm11
  __int64 v14; // rbx
  __m128d v15; // xmm0
  signed __int64 v16; // rbx
  double v17; // xmm0_8
  double v18; // [rsp+28h] [rbp-B0h]
  double v19; // [rsp+30h] [rbp-A8h]

  v4 = compTableSize;
  v5 = compTable;
  v18 = DOUBLE_1_0;
  v6 = DOUBLE_1_0;
  v7 = amount;
  v8 = 1.0 / (double)compTableSize;
  v9 = DOUBLE_1_0;
  v19 = 1.0 / (double)compTableSize;
  if ( !bypassed )
  {
    v18 = pow(10.0, -2.4);
    v9 = v18;
    v6 = v7 * 0.01 * 9.0 + 1.0;
  }
  v10 = 0;
  if ( v4 > 0 && (unsigned int)v4 >= 4 )
  {
    v11 = _mm_unpckl_pd((__m128d)*(unsigned __int64 *)&v19, (__m128d)*(unsigned __int64 *)&v19);
    v12 = _mm_load_si128((const __m128i *)&_xmm);
    v13 = _mm_unpckl_pd((__m128d)*(unsigned __int64 *)&v18, (__m128d)*(unsigned __int64 *)&v18);
    do
    {
      _vdecl_pow2();
      *(__m128d *)&v5[v10] = _mm_add_pd(
                               _mm_div_pd(
                                 _mm_mul_pd(
                                   _mm_cvtepi32_pd(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v10), 0), v12)),
                                   v11),
                                 v13),
                               *(__m128d *)_xmm);
      v14 = v10 + 2;
      v15 = _mm_add_pd(
              _mm_div_pd(
                _mm_mul_pd(_mm_cvtepi32_pd(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v10 + 2), 0), v12)), v11),
                v13),
              *(__m128d *)_xmm);
      _vdecl_pow2();
      v10 += 4;
      *(__m128d *)&v5[v14] = v15;
    }
    while ( v10 < v4 - v4 % 4 );
  }
  if ( v10 < v4 )
  {
    v16 = (signed __int64)&v5[v10];
    do
    {
      v17 = pow((double)v10++ * v8 * (1.0 / v9) + 1.0, 1.0 / v6 - 1.0);
      v16 += 8i64;
      *(double *)(v16 - 8) = v17;
    }
    while ( v10 < v4 );
  }
}

// File Line: 442
// RVA: 0xB055E0
void __fastcall FutzDistortionDSPMemoryMapHelper::FutzDistortionDSPMemoryMapHelper(FutzDistortionDSPMemoryMapHelper *this)
{
  FutzDistortionDSPMemoryMapHelper *v1; // rbx

  v1 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->0);
  v1->FutzBoxMemMapPtr = 0i64;
}

// File Line: 448
// RVA: 0xB05610
void __fastcall FutzDistortionDSPMemoryMapHelper::~FutzDistortionDSPMemoryMapHelper(FutzDistortionDSPMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->0);
}

// File Line: 454
// RVA: 0xB05620
signed __int64 __fastcall FutzDistortionDSPMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 1176i64 * numChannels;
}

// File Line: 464
// RVA: 0xB05630
__int64 __fastcall FutzDistortionDSPMemoryMapHelper::Init(FutzDistortionDSPMemoryMapHelper *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzDistortionDSPMemoryMapHelper *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  v4 = this;
  this->mSampleRate = sampleRate;
  v5 = 1176i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x498ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->FutzBoxMemMapPtr = (FutzBoxDistortionMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 481
// RVA: 0xB05690
FutzBoxDistortionMemoryMap *__fastcall FutzDistortionDSPMemoryMapHelper::GetMemoryMap(FutzDistortionDSPMemoryMapHelper *this, unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 490
// RVA: 0xB056B0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistPassingGain(FutzDistortionDSPMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzDistortionDSPMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, 1.0, v2->FutzBoxMemMapPtr[v1++].YMemory, 4);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 500
// RVA: 0xB05720
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistTable(FutzDistortionDSPMemoryMapHelper *this, long double amount, bool bypassed)
{
  FutzDistortionDSPMemoryMapHelper *v3; // rdi
  unsigned int v4; // ebx

  v3 = this;
  GenerateDistortionTable(amount, bypassed, sDist_Table, 256);
  v4 = 0;
  if ( v3->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetTableValues(&v3->0, sDist_Table, 256, v3->FutzBoxMemMapPtr[v4++].YMemory, 18);
    while ( v4 < v3->mNumChannels );
  }
}

// File Line: 510
// RVA: 0xB057A0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistTableAddress(FutzDistortionDSPMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzDistortionDSPMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v2->0, 18, v2->FutzBoxMemMapPtr[v1++].XMemory, 3);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 518
// RVA: 0xB05800
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistAmount(FutzDistortionDSPMemoryMapHelper *this, long double amount, bool bypassed)
{
  double v3; // xmm6_8
  FutzDistortionDSPMemoryMapHelper *v4; // rdi
  unsigned int v5; // ebx

  v3 = DOUBLE_1_0;
  v4 = this;
  if ( !bypassed )
    v3 = pow(10.0, -2.4);
  v5 = 0;
  if ( v4->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v4->0, v3, v4->FutzBoxMemMapPtr[v5++].XMemory, 2);
    while ( v5 < v4->mNumChannels );
  }
}

// File Line: 538
// RVA: 0xB05880
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistMakeupGain(FutzDistortionDSPMemoryMapHelper *this, long double amount, FutzDistortionMode mode, bool bypassed)
{
  __int64 v4; // rbx
  FutzDistortionDSPMemoryMapHelper *v5; // rsi
  double v6; // xmm10_8
  double v7; // xmm2_8
  double v8; // xmm9_8
  signed int v9; // edi
  double v10; // xmm6_8
  double v11; // xmm0_8
  double v12; // xmm1_8
  unsigned int v13; // ebx
  double v14; // xmm6_8

  v4 = mode;
  v5 = this;
  v6 = 0.0;
  v7 = DOUBLE_1_0;
  v8 = 0.0;
  if ( !bypassed )
  {
    v8 = amount * 0.01;
    v7 = pow(10.0, -2.4);
    v6 = amount * 0.01 * sTemp_Makeup_Adjustments[v4];
  }
  v9 = (signed int)(v8 * 20.0);
  v10 = sTempTable[v9];
  v11 = pow((1.0 - v7) / v7 + 1.0, 1.0 / (v8 * 9.0 + 1.0) - 1.0);
  v12 = (log10(((1.0 / v11 - 1.0) * v8 + 1.0) * ((qword_142100C28[v9] - v10) * (v8 * 20.0 - (double)v9) + v10)) * 20.0
       + v6)
      * 0.05;
  v13 = 0;
  v14 = pow(10.0, v12);
  if ( v5->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v5->0, v14, v5->FutzBoxMemMapPtr[v13++].YMemory, 7);
    while ( v13 < v5->mNumChannels );
  }
}

// File Line: 598
// RVA: 0xB05A40
void __usercall FutzDistortionDSPMemoryMapHelper::SetDistTimes(FutzDistortionDSPMemoryMapHelper *this@<rcx>, long double amount@<xmm1>, FutzDistortionMode mode@<r8d>, double a4@<xmm0>)
{
  FutzDistortionDSPMemoryMapHelper *v4; // rdi
  double v5; // xmm7_8
  double v6; // xmm8_8
  double v7; // xmm6_8
  long double v8; // xmm6_8
  long double v9; // xmm6_8
  long double v10; // xmm6_8
  long double v11; // xmm6_8
  unsigned int v12; // esi
  signed __int64 v13; // rbx
  double v14; // [rsp+60h] [rbp+8h]

  v4 = this;
  v5 = amount * 0.01;
  if ( amount * 0.01 > 0.0 )
    v5 = sqrt(v5);
  switch ( mode )
  {
    case 0:
      DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v5 * 7.800000000000001 + 4.35);
      v6 = a4;
      DynamicsCalculator::CalculateAttackScalar(v4->mSampleRate, 0.85 - v5 * 0.5);
      v7 = a4;
      break;
    case 1:
      DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v5 * 17.1 + 1.15);
      v6 = a4;
      DynamicsCalculator::CalculateAttackScalar(v4->mSampleRate, 0.25 - v5 * 0.15);
      v7 = a4;
      break;
    case 2:
      a4 = v5 * 0.9500000000000002;
      DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, 2.35 - v5 * 0.9500000000000002);
      v6 = v5 * 0.9500000000000002;
      DynamicsCalculator::CalculateAttackScalar(v4->mSampleRate, 0.35 - v5 * 0.09999999999999998);
      v7 = v5 * 0.9500000000000002;
      break;
    case 3:
      a4 = v5 * 0.2;
      DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, 0.95 - v5 * 0.2);
      v6 = v5 * 0.2;
      DynamicsCalculator::CalculateAttackScalar(v4->mSampleRate, 0.25 - v5 * 0.15);
      v7 = v5 * 0.2;
      break;
    case 4:
      a4 = v5 * 7.9;
      DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, 8.25 - v5 * 7.9);
      v6 = v5 * 7.9;
      DynamicsCalculator::CalculateAttackScalar(v4->mSampleRate, v5 * 0.0 + 0.25);
      v7 = v5 * 7.9;
      break;
    case 5:
      a4 = v5 * 1.9;
      DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, 2.15 - v5 * 1.9);
      v6 = v5 * 1.9;
      DynamicsCalculator::CalculateAttackScalar(v4->mSampleRate, 0.5 - v5 * 0.3);
      v7 = v5 * 1.9;
      break;
    case 6:
      v8 = 0.7 - v5 * 0.5499999999999999;
      DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v8);
      v6 = a4;
      DynamicsCalculator::CalculateAttackScalar(v4->mSampleRate, v8);
      v7 = a4;
      break;
    case 7:
      v9 = 0.35 - v5 * 0.25;
      DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v9);
      v6 = a4;
      DynamicsCalculator::CalculateAttackScalar(v4->mSampleRate, v9);
      v7 = a4;
      break;
    case 8:
      v10 = 0.25 - v5 * 0.2;
      DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v10);
      v6 = a4;
      DynamicsCalculator::CalculateAttackScalar(v4->mSampleRate, v10);
      v7 = a4;
      break;
    case 9:
      v11 = 0.1 - v5 * 0.09000000000000001;
      DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v11);
      v6 = a4;
      DynamicsCalculator::CalculateAttackScalar(v4->mSampleRate, v11);
      v7 = a4;
      break;
    default:
      v6 = v14;
      v7 = v14;
      break;
  }
  DynamicsCalculator::CalculateAttackScalar(v4->mSampleRate, 0.01);
  v12 = 0;
  if ( v4->mNumChannels )
  {
    do
    {
      v13 = v12;
      DSPMemoryMapHelper::SetDoubleValue(&v4->0, v7, v4->FutzBoxMemMapPtr[v13].XMemory, 8);
      DSPMemoryMapHelper::SetDoubleValue(&v4->0, a4 - v7, v4->FutzBoxMemMapPtr[v13].XMemory, 9);
      DSPMemoryMapHelper::SetDoubleValue(&v4->0, v6, v4->FutzBoxMemMapPtr[v13].XMemory, 7);
      ++v12;
    }
    while ( v12 < v4->mNumChannels );
  }
}

// File Line: 691
// RVA: 0xB05DD0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDistKeyFilter(FutzDistortionDSPMemoryMapHelper *this, long double amount, long double intensity, FutzDistortionMode mode)
{
  FutzDistortionDSPMemoryMapHelper *v4; // rdi
  double v5; // xmm4_8
  double v6; // xmm3_8
  double v7; // xmm0_8
  double v8; // xmm2_8
  double v9; // xmm1_8
  unsigned int v10; // ebx
  double v11; // [rsp+30h] [rbp+8h]

  v4 = this;
  v5 = amount * 0.01;
  v6 = intensity * 0.01;
  switch ( mode )
  {
    case 0:
      v7 = DOUBLE_100_0;
      v8 = DOUBLE_150_0;
      v9 = DOUBLE_17500_0;
      break;
    case 1:
      v7 = DOUBLE_100_0;
      v8 = DOUBLE_300_0;
      v9 = DOUBLE_20000_0;
      break;
    case 2:
      v7 = DOUBLE_300_0;
      v9 = DOUBLE_10000_0;
      v8 = DOUBLE_300_0;
      break;
    case 3:
      v7 = DOUBLE_150_0;
      v8 = DOUBLE_300_0;
      v9 = DOUBLE_12000_0;
      break;
    case 4:
      v7 = DOUBLE_100_0;
      v8 = DOUBLE_200_0;
      v9 = DOUBLE_14000_0;
      break;
    case 5:
      v7 = DOUBLE_150_0;
      v8 = DOUBLE_300_0;
      v9 = DOUBLE_16000_0;
      break;
    case 6:
      v7 = DOUBLE_200_0;
      v8 = DOUBLE_400_0;
      v9 = DOUBLE_18000_0;
      break;
    case 7:
      v7 = DOUBLE_100_0;
      v8 = DOUBLE_1000_0;
      v9 = DOUBLE_20000_0;
      break;
    case 8:
      v7 = DOUBLE_200_0;
      v8 = DOUBLE_2000_0;
      v9 = DOUBLE_20000_0;
      break;
    case 9:
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
  v10 = 0;
  if ( v4->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetFirstOrderFilterCoefs(&v4->0, &sDist_Key_Coefs, v4->FutzBoxMemMapPtr[v10++].XMemory, 4);
    while ( v10 < v4->mNumChannels );
  }
}

// File Line: 730
// RVA: 0xB05FD0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetHarmonicsThreshold(FutzDistortionDSPMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzDistortionDSPMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, 0.0, v2->FutzBoxMemMapPtr[v1++].XMemory, 11);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 740
// RVA: 0xB06030
void __fastcall FutzDistortionDSPMemoryMapHelper::SetHarmonicsOffset(FutzDistortionDSPMemoryMapHelper *this, long double rectify)
{
  unsigned int v2; // ebx
  FutzDistortionDSPMemoryMapHelper *v3; // rdi

  v2 = 0;
  v3 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v3->0, rectify * 0.01 * -2.0, v3->FutzBoxMemMapPtr[v2++].YMemory, 8);
    while ( v2 < v3->mNumChannels );
  }
}

// File Line: 754
// RVA: 0xB060B0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDCFilter(FutzDistortionDSPMemoryMapHelper *this)
{
  FutzDistortionDSPMemoryMapHelper *v1; // rbx
  unsigned int v2; // edi
  SCoefs outCoefs; // [rsp+20h] [rbp-38h]

  v1 = this;
  CoefficientCalculator::CalculateFirstOrderHighPass(this->mSampleRate, 20.0, &outCoefs);
  v2 = 0;
  if ( v1->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetFilterCoefs(&v1->0, &outCoefs, v1->FutzBoxMemMapPtr[v2++].XMemory, 12);
    while ( v2 < v1->mNumChannels );
  }
}

// File Line: 768
// RVA: 0xB06120
void __fastcall FutzDistortionDSPMemoryMapHelper::SetBalanceLevels(FutzDistortionDSPMemoryMapHelper *this, long double balance)
{
  unsigned int v2; // esi
  FutzDistortionDSPMemoryMapHelper *v3; // rdi
  signed __int64 v4; // rbx

  v2 = 0;
  v3 = this;
  if ( this->mNumChannels )
  {
    do
    {
      v4 = v2;
      DSPMemoryMapHelper::SetDoubleValue(&v3->0, balance * 0.01, v3->FutzBoxMemMapPtr[v4].YMemory, 16);
      DSPMemoryMapHelper::SetDoubleValue(&v3->0, 1.0 - balance * 0.01, v3->FutzBoxMemMapPtr[v4].YMemory, 17);
      ++v2;
    }
    while ( v2 < v3->mNumChannels );
  }
}

// File Line: 785
// RVA: 0xB061D0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetDrySignalAddress(FutzDistortionDSPMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzDistortionDSPMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v2->0, 1, v2->FutzBoxMemMapPtr[v1++].XMemory, 17);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 793
// RVA: 0xB06230
void __fastcall FutzDistortionDSPMemoryMapHelper::SetInputGain(FutzDistortionDSPMemoryMapHelper *this, long double gain)
{
  FutzDistortionDSPMemoryMapHelper *v2; // rdi
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

// File Line: 805
// RVA: 0xB062B0
void __fastcall FutzDistortionDSPMemoryMapHelper::SetOutputGain(FutzDistortionDSPMemoryMapHelper *this, long double gain)
{
  FutzDistortionDSPMemoryMapHelper *v2; // rdi
  unsigned int v3; // ebx
  double v4; // xmm6_8

  v2 = this;
  v3 = 0;
  v4 = pow(10.0, gain * 0.05);
  if ( v2->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, v4, v2->FutzBoxMemMapPtr[v3++].YMemory, 15);
    while ( v3 < v2->mNumChannels );
  }
}

// File Line: 819
// RVA: 0xB06330
void __fastcall FutzDistortionImpl::FutzDistortionImpl(FutzDistortionImpl *this)
{
  FutzDistortionImpl *v1; // rbx

  v1 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper.0);
  v1->MemoryMapHelper.FutzBoxMemMapPtr = 0i64;
}

// File Line: 825
// RVA: 0xB06360
void __fastcall FutzDistortionImpl::~FutzDistortionImpl(FutzDistortionImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper.0);
}

// File Line: 832
// RVA: 0xB06370
signed __int64 __fastcall FutzDistortionImpl::GetMemoryMapSize(FutzDistortionImpl *this, unsigned int numChannels)
{
  return 1176i64 * numChannels;
}

// File Line: 841
// RVA: 0xB06380
__int64 __fastcall FutzDistortionImpl::Init(FutzDistortionImpl *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzDistortionImpl *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->MemoryMapHelper.mNumChannels = numChannels;
  v4 = this;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 1176i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x498ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxDistortionMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 849
// RVA: 0xB063E0
void __usercall FutzDistortionImpl::SetParameters(FutzDistortionImpl *this@<rcx>, FutzDistortionParameters *distortionParams@<rdx>, double a3@<xmm0>)
{
  unsigned int v3; // edi
  FutzDistortionParameters *v4; // rbp
  FutzDistortionImpl *v5; // rbx
  unsigned int v6; // esi
  unsigned int i; // esi
  unsigned int j; // esi
  unsigned int k; // esi
  double v10; // xmm6_8

  v3 = 0;
  v4 = distortionParams;
  v5 = this;
  v6 = 0;
  if ( this->MemoryMapHelper.mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(
        &v5->MemoryMapHelper.0,
        1.0,
        v5->MemoryMapHelper.FutzBoxMemMapPtr[v6++].YMemory,
        4);
    while ( v6 < v5->MemoryMapHelper.mNumChannels );
  }
  FutzDistortionDSPMemoryMapHelper::SetDistTable(&v5->MemoryMapHelper, v4->amount, v4->bypassed);
  for ( i = 0; i < v5->MemoryMapHelper.mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(&v5->MemoryMapHelper.0, 18, v5->MemoryMapHelper.FutzBoxMemMapPtr[i].XMemory, 3);
  FutzDistortionDSPMemoryMapHelper::SetDistAmount(&v5->MemoryMapHelper, v4->amount, v4->bypassed);
  FutzDistortionDSPMemoryMapHelper::SetDistMakeupGain(&v5->MemoryMapHelper, v4->amount, v4->mode, v4->bypassed);
  FutzDistortionDSPMemoryMapHelper::SetDistTimes(&v5->MemoryMapHelper, v4->amount, v4->mode, a3);
  FutzDistortionDSPMemoryMapHelper::SetDistKeyFilter(&v5->MemoryMapHelper, v4->amount, v4->intensity, v4->mode);
  for ( j = 0; j < v5->MemoryMapHelper.mNumChannels; ++j )
    DSPMemoryMapHelper::SetDoubleValue(&v5->MemoryMapHelper.0, 0.0, v5->MemoryMapHelper.FutzBoxMemMapPtr[j].XMemory, 11);
  FutzDistortionDSPMemoryMapHelper::SetHarmonicsOffset(&v5->MemoryMapHelper, v4->rectify);
  FutzDistortionDSPMemoryMapHelper::SetDCFilter(&v5->MemoryMapHelper);
  FutzDistortionDSPMemoryMapHelper::SetBalanceLevels(&v5->MemoryMapHelper, 100.0);
  for ( k = 0; k < v5->MemoryMapHelper.mNumChannels; ++k )
    DSPMemoryMapHelper::SetLongValue(&v5->MemoryMapHelper.0, 1, v5->MemoryMapHelper.FutzBoxMemMapPtr[k].XMemory, 17);
  FutzDistortionDSPMemoryMapHelper::SetInputGain(&v5->MemoryMapHelper, 0.0);
  v10 = pow(10.0, 0.0);
  if ( v5->MemoryMapHelper.mNumChannels > 0 )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(
        &v5->MemoryMapHelper.0,
        v10,
        v5->MemoryMapHelper.FutzBoxMemMapPtr[v3++].YMemory,
        15);
    while ( v3 < v5->MemoryMapHelper.mNumChannels );
  }
}

