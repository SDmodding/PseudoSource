// File Line: 120
// RVA: 0xAFCC30
void __fastcall McDSPLimiterProcessChannels(
        char *memoryMap,
        const float *inputBuf,
        float *outputBuf,
        unsigned int samplesRemaining)
{
  int v4; // edi
  int v5; // esi
  char *v9; // rdx
  __int64 v10; // r11
  int v11; // ebp
  int v12; // r10d
  __int64 v13; // r9
  int v14; // r13d
  int v15; // r14d
  float *v16; // rcx
  float v17; // xmm9_4
  float v18; // xmm5_4
  float *v19; // r8
  __int64 v20; // rcx
  int v21; // xmm2_4
  char *v22; // rcx
  int v23; // xmm0_4
  int v24; // r10d
  unsigned int v25; // eax
  __int64 v26; // r9
  __int64 v27; // r9
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm4_4
  float v31; // xmm4_4
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm4_4
  float v37; // xmm0_4
  int v38; // xmm5_4
  int v39; // xmm4_4
  int v40; // xmm0_4
  float v41; // xmm5_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm0_4
  __int64 v45; // rax
  __int64 v46; // rcx
  __int64 v47; // r9
  float v48; // xmm4_4
  __int64 v49; // rax
  float v50; // xmm5_4
  float v51; // xmm1_4
  int v52; // r10d
  __int64 v53; // rax
  float *v54; // rcx
  unsigned int v55; // eax
  __int64 v56; // r9
  float v57; // xmm4_4
  float *v58; // rcx
  __int64 v59; // r9
  float v60; // xmm2_4
  float v61; // xmm4_4
  float v62; // xmm5_4
  int v63; // xmm4_4
  float v64; // xmm2_4
  float v65; // xmm4_4
  float v66; // xmm2_4
  __int64 v67; // [rsp+0h] [rbp-B8h]
  __int64 v68; // [rsp+8h] [rbp-B0h]
  __int64 v69; // [rsp+10h] [rbp-A8h]
  __int64 v70; // [rsp+18h] [rbp-A0h]
  __int64 v71; // [rsp+C0h] [rbp+8h]
  int v73; // [rsp+D8h] [rbp+20h]

  v4 = (int)*((float *)memoryMap + 812);
  v5 = (int)*((float *)memoryMap + 1);
  v9 = memoryMap + 3240;
  v10 = (int)*((float *)memoryMap + 2);
  v70 = v10;
  v11 = (int)*((float *)memoryMap + 810);
  v12 = (int)*((float *)memoryMap + 10);
  v73 = (int)*((float *)memoryMap + 5);
  *(_QWORD *)(memoryMap + 52) = 0i64;
  *((_DWORD *)memoryMap + 17) = 0;
  v13 = v11;
  v68 = v12;
  v14 = (int)*((float *)memoryMap + 12);
  v15 = (int)*((float *)memoryMap + 11);
  v71 = v14;
  if ( samplesRemaining )
  {
    v16 = (float *)(memoryMap + 12);
    v67 = v12 + 1;
    v17 = kHeadRoomScaleFactor;
    do
    {
      --samplesRemaining;
      v18 = v17 * *inputBuf++;
      if ( v18 < 1.0 )
      {
        if ( v18 <= -1.0 )
          v18 = FLOAT_N1_0;
      }
      else
      {
        v18 = *(float *)&FLOAT_1_0;
      }
      ++v11;
      v19 = v16;
      v20 = v13 + 1;
      if ( v11 >= v5 )
      {
        v11 = 0;
        v20 = 0i64;
      }
      v69 = v20;
      v21 = 0;
      v22 = &memoryMap[4 * v10 + 3236];
      v23 = *(_DWORD *)&memoryMap[4 * v10 + 3236 + 4 * v13];
      *(float *)&memoryMap[4 * v10 + 3236 + 4 * v13] = v18;
      *((_DWORD *)v9 + 1) = v23;
      v24 = 0;
      if ( v5 >= 4 )
      {
        v25 = ((unsigned int)(v5 - 4) >> 2) + 1;
        v26 = v25;
        v24 = 4 * v25;
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v22 & _xmm) > COERCE_FLOAT(v21 & _xmm) )
            v21 = *(_DWORD *)v22;
          if ( COERCE_FLOAT(*((_DWORD *)v22 + 1) & _xmm) > COERCE_FLOAT(v21 & _xmm) )
            v21 = *((_DWORD *)v22 + 1);
          if ( COERCE_FLOAT(*((_DWORD *)v22 + 2) & _xmm) > COERCE_FLOAT(v21 & _xmm) )
            v21 = *((_DWORD *)v22 + 2);
          if ( COERCE_FLOAT(*((_DWORD *)v22 + 3) & _xmm) > COERCE_FLOAT(v21 & _xmm) )
            v21 = *((_DWORD *)v22 + 3);
          v22 += 16;
          --v26;
        }
        while ( v26 );
      }
      if ( v24 < v5 )
      {
        v27 = (unsigned int)(v5 - v24);
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v22 & _xmm) > COERCE_FLOAT(v21 & _xmm) )
            v21 = *(_DWORD *)v22;
          v22 += 4;
          --v27;
        }
        while ( v27 );
      }
      v28 = v19[1];
      LODWORD(v29) = LODWORD(v18) & _xmm;
      if ( v29 >= 1.0 )
        v29 = *(float *)&FLOAT_1_0;
      if ( COERCE_FLOAT(*(_DWORD *)v19 & _xmm) <= COERCE_FLOAT(LODWORD(v29) & _xmm) )
        v29 = *v19;
      v30 = *((float *)v9 + 3);
      if ( COERCE_FLOAT(LODWORD(v29) & _xmm) > COERCE_FLOAT(LODWORD(v30) & _xmm) )
      {
        v4 = v73;
        v30 = v29;
      }
      LODWORD(v31) = LODWORD(v30) & _xmm;
      *((float *)v9 + 3) = v31;
      v32 = v31 - v28;
      if ( COERCE_FLOAT(*((_DWORD *)v9 + 4) & _xmm) > COERCE_FLOAT(LODWORD(v32) & _xmm) )
        v32 = *((float *)v9 + 4);
      --v4;
      *((float *)v9 + 4) = v32;
      v33 = 0.0;
      if ( v4 < 0 )
        v4 = 0;
      v34 = v19[4];
      if ( v4 <= 0 )
      {
        v33 = v19[3];
        v34 = 0.0;
      }
      LODWORD(v35) = v21 & _xmm;
      v36 = (float)((float)(v32 * v34) + v19[1]) + (float)((float)(v35 - v19[1]) * v33);
      if ( COERCE_FLOAT(*((_DWORD *)v9 + 3) & _xmm) <= COERCE_FLOAT(LODWORD(v36) & _xmm) )
        v36 = *((float *)v9 + 3);
      v37 = *((float *)v9 + 4);
      if ( v4 <= 0 )
        v37 = (float)v4;
      *((float *)v9 + 4) = v37;
      v38 = *((_DWORD *)v9 + 1);
      if ( COERCE_FLOAT(v38 & _xmm) > COERCE_FLOAT(LODWORD(v36) & _xmm) )
        v36 = *((float *)v9 + 1);
      v39 = LODWORD(v36) & _xmm;
      *((_DWORD *)v19 + 1) = v39;
      v40 = *((_DWORD *)v9 + 3);
      if ( COERCE_FLOAT(v38 & _xmm) > COERCE_FLOAT(v39 & _xmm) )
        v40 = v38;
      *((_DWORD *)v9 + 3) = v40 & _xmm;
      v41 = v19[5];
      if ( COERCE_FLOAT(*((_DWORD *)v9 + 5) & _xmm) < COERCE_FLOAT(LODWORD(v35) & _xmm) )
        v41 = v19[6];
      v42 = v19[1];
      v43 = (float)((float)(v35 - *((float *)v9 + 5)) * v41) + *((float *)v9 + 5);
      *((float *)v9 + 5) = v43;
      if ( v42 > v43 )
        v43 = v42;
      v19[1] = v43;
      v44 = *((float *)v9 + 3);
      if ( v4 <= 0 )
        v44 = v43;
      v45 = v71;
      ++v14;
      v46 = v71 + 1;
      *((float *)v9 + 3) = v44;
      v47 = v71;
      if ( v71 + 1 >= v15 )
      {
        v46 = 0i64;
        v14 = 0;
      }
      v71 = v46;
      v48 = 0.0;
      v49 = v68 + v45;
      *(float *)&memoryMap[4 * v49 + 3236] = v43;
      v50 = *(float *)&memoryMap[4 * v68];
      v51 = *(float *)&memoryMap[4 * (v49 - v47) + 3236];
      v52 = 0;
      v53 = v67;
      if ( v15 >= 4 )
      {
        v54 = (float *)&memoryMap[4 * v67 + 3244];
        v55 = ((unsigned int)(v15 - 4) >> 2) + 1;
        v56 = v55;
        v52 = 4 * v55;
        v53 = v67 + 4i64 * v55;
        do
        {
          v54 += 4;
          v57 = (float)((float)((float)(v51 * v50) + v48) + (float)(v50 * *(v54 - 6))) + (float)(v50 * *(v54 - 5));
          v51 = *(v54 - 3);
          v48 = v57 + (float)(v50 * *(v54 - 4));
          --v56;
        }
        while ( v56 );
      }
      if ( v52 < v15 )
      {
        v58 = (float *)&memoryMap[4 * v53 + 3236];
        v59 = (unsigned int)(v15 - v52);
        do
        {
          ++v58;
          v48 = v48 + (float)(v51 * v50);
          v51 = *(v58 - 1);
          --v59;
        }
        while ( v59 );
      }
      v60 = (float)((float)((float)((float)(v48 * 2.0) - (float)(v48 * v48)) * 2.0)
                  - (float)((float)((float)(v48 * 2.0) - (float)(v48 * v48))
                          * (float)((float)(v48 * 2.0) - (float)(v48 * v48))))
          * 599.0;
      v61 = (float)((float)(*(float *)&v9[4 * (int)v60 + 32] - *(float *)&v9[4 * (int)v60 + 28])
                  * (float)(v60 - (float)(int)v60))
          + *(float *)&v9[4 * (int)v60 + 28];
      v62 = v61;
      if ( COERCE_FLOAT((_DWORD)v19[10] & _xmm) > COERCE_FLOAT(LODWORD(v61) & _xmm) )
        v61 = v19[10];
      v19[10] = v61;
      v63 = *((_DWORD *)v19 + 11);
      v64 = *((float *)v9 + 1);
      if ( COERCE_FLOAT(LODWORD(v64) & _xmm) > COERCE_FLOAT(v63 & _xmm) )
        v63 = *((_DWORD *)v9 + 1);
      *((_DWORD *)v19 + 11) = v63;
      v65 = v19[14];
      v66 = (float)(v64 * v62) * v19[12];
      if ( COERCE_FLOAT(LODWORD(v66) & _xmm) > COERCE_FLOAT(LODWORD(v65) & _xmm) )
        v65 = v66;
      v13 = v69;
      v10 = v70;
      v19[14] = v65;
      v9 = memoryMap + 3240;
      v16 = (float *)(memoryMap + 12);
      *outputBuf++ = v66;
    }
    while ( samplesRemaining );
    v9 = memoryMap + 3240;
  }
  *((float *)memoryMap + 812) = (float)v4;
  *(float *)v9 = (float)v11;
  *((float *)memoryMap + 12) = (float)v14;
}

// File Line: 557
// RVA: 0xAFD230
void __fastcall McDSPFillVUMetersDataMono(float *memoryMap, float *pMeteringData)
{
  *(_DWORD *)pMeteringData = 4;
  pMeteringData[1] = memoryMap[13];
  pMeteringData[2] = memoryMap[14] * 3.9810717;
  pMeteringData[3] = memoryMap[17];
}

// File Line: 628
// RVA: 0xAFD640
void __fastcall LimiterDSPMonoMemoryMapHelper::LimiterDSPMonoMemoryMapHelper(
        LimiterDSPMonoMemoryMapHelper *this,
        int sampleRate)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(this);
  LimiterUtilities::LimiterUtilities(&this->mLimiterUtilities, 0.00085000001, 0.000325);
}

// File Line: 634
// RVA: 0xAFD680
void __fastcall LimiterDSPMonoMemoryMapHelper::~LimiterDSPMonoMemoryMapHelper(LimiterDSPMonoMemoryMapHelper *this)
{
  LimiterUtilities::~LimiterUtilities(&this->mLimiterUtilities);
  DSPMemoryMapHelper::~DSPMemoryMapHelper(this);
}

// File Line: 639
// RVA: 0xAFD6B0
unsigned __int64 __fastcall LimiterDSPMonoMemoryMapHelper::GetMemoryMapSize(LimiterDSPMonoMemoryMapHelper *this)
{
  return 6472i64;
}

// File Line: 647
// RVA: 0xAFD6C0
__int64 __fastcall LimiterDSPMonoMemoryMapHelper::Init(
        LimiterDSPMonoMemoryMapHelper *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int sampleRate)
{
  char *v4; // rax

  this->mNumChannels = 1;
  this->mSampleRate = sampleRate;
  v4 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x1948ui64);
  this->LimiterMemMapPtr = (LimiterMonoMemoryMap *)v4;
  if ( !v4 )
    return 52i64;
  *((_DWORD *)v4 + 3) = 1065353216;
  return 1i64;
}

// File Line: 670
// RVA: 0xAFD710
LimiterMonoMemoryMap *__fastcall LimiterDSPMonoMemoryMapHelper::GetMemoryMap(LimiterDSPMonoMemoryMapHelper *this)
{
  return this->LimiterMemMapPtr;
}

// File Line: 677
// RVA: 0xAFD7A0
void __fastcall LimiterDSPMonoMemoryMapHelper::SetCeiling(
        LimiterDSPMonoMemoryMapHelper *this,
        long double ceiling,
        double threshold)
{
  float v4; // xmm1_4

  if ( threshold < 0.0 )
    ceiling = ceiling + -0.01;
  v4 = pow(10.0, ceiling * 0.05);
  this->LimiterMemMapPtr->XMemory[15] = v4;
}

// File Line: 693
// RVA: 0xAFD7F0
void __fastcall LimiterDSPMonoMemoryMapHelper::SetThreshold(
        LimiterDSPMonoMemoryMapHelper *this,
        double threshold,
        long double knee,
        long double ceiling)
{
  float v5; // xmm1_4

  if ( threshold < 0.0 )
    ceiling = ceiling - 0.01;
  v5 = pow(10.0, ceiling * 0.05);
  this->LimiterMemMapPtr->XMemory[15] = v5;
}

// File Line: 703
// RVA: 0xAFD840
void __fastcall LimiterDSPMonoMemoryMapHelper::SetKnee(
        LimiterDSPMonoMemoryMapHelper *this,
        long double knee,
        long double threshold)
{
  ;
}

// File Line: 713
// RVA: 0xAFD740
void __fastcall LimiterDSPMonoMemoryMapHelper::GenerateExpTable(
        LimiterDSPMonoMemoryMapHelper *this,
        long double knee,
        long double threshold)
{
  LimiterUtilities::GenerateExpTable(&this->LimiterMemMapPtr->YMemory[8], 600, threshold, knee);
}

// File Line: 721
// RVA: 0xAFD850
void __fastcall LimiterDSPMonoMemoryMapHelper::SetRelease(
        LimiterDSPMonoMemoryMapHelper *this,
        double release,
        LimiterCharacterType character)
{
  double v5; // xmm0_8
  double v6; // xmm1_8
  float v7; // xmm1_4
  double v8; // [rsp+30h] [rbp+8h]

  switch ( character )
  {
    case eCharacterMode_Clean:
      v5 = DOUBLE_3_0;
      v6 = 0.0;
      break;
    case eCharacterMode_Soft:
      v5 = DOUBLE_4_0;
      v6 = 0.0;
      break;
    case eCharacterMode_Smart:
      v5 = DOUBLE_5_0;
      v6 = 0.0;
      break;
    case eCharacterMode_Dynamic:
      v5 = DOUBLE_6_0;
      v6 = 0.0;
      break;
    case eCharacterMode_Loud:
      v5 = DOUBLE_10_0;
      v6 = 0.0;
      break;
    case eCharacterMode_Crush:
      v5 = DOUBLE_15_0;
      v6 = 0.0;
      break;
    default:
      v6 = v8;
      v5 = v8;
      break;
  }
  if ( release > v5 )
    release = v5;
  v7 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v6 + release);
  this->LimiterMemMapPtr->XMemory[6] = v7;
}

// File Line: 745
// RVA: 0xAFD920
void __fastcall LimiterDSPMonoMemoryMapHelper::SetCharacter(
        LimiterDSPMonoMemoryMapHelper *this,
        LimiterCharacterType character,
        long double release)
{
  long double v4; // xmm1_8
  double v5; // xmm6_8
  double v6; // xmm7_8
  double v7; // xmm8_8
  float v8; // xmm2_4
  float v9; // xmm1_4
  double attack; // [rsp+60h] [rbp+8h]

  switch ( character )
  {
    case eCharacterMode_Clean:
      v4 = DOUBLE_50_0;
      v5 = DOUBLE_800_0;
      v6 = DOUBLE_3_0;
      break;
    case eCharacterMode_Soft:
      v4 = DOUBLE_40_0;
      v5 = DOUBLE_600_0;
      v6 = DOUBLE_4_0;
      break;
    case eCharacterMode_Smart:
      v4 = DOUBLE_30_0;
      v5 = DOUBLE_400_0;
      v6 = DOUBLE_5_0;
      break;
    case eCharacterMode_Dynamic:
      v4 = DOUBLE_20_0;
      v5 = DOUBLE_200_0;
      v6 = DOUBLE_6_0;
      break;
    case eCharacterMode_Loud:
      v4 = DOUBLE_10_0;
      v5 = DOUBLE_100_0;
      v6 = DOUBLE_10_0;
      break;
    case eCharacterMode_Crush:
      v4 = DOUBLE_5_0;
      v5 = DOUBLE_50_0;
      v6 = DOUBLE_15_0;
      break;
    default:
      v4 = attack;
      v5 = attack;
      v6 = attack;
      break;
  }
  v7 = release - v6;
  v8 = DynamicsCalculator::CalculateAttackScalar(this->mSampleRate, v4);
  this->LimiterMemMapPtr->XMemory[9] = v8;
  if ( v7 < 0.0 )
    v7 = 0.0;
  v9 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v5 + v7);
  this->LimiterMemMapPtr->XMemory[8] = v9;
}

// File Line: 778
// RVA: 0xAFDA90
void __fastcall LimiterDSPMonoMemoryMapHelper::SetAttack(LimiterDSPMonoMemoryMapHelper *this)
{
  int LookAheadDelayLength; // eax
  float TCScalar; // xmm1_4

  LookAheadDelayLength = LimiterUtilities::GetLookAheadDelayLength(
                           &this->mLimiterUtilities,
                           (double)(int)this->mSampleRate);
  TCScalar = GetTCScalar((double)LookAheadDelayLength);
  this->LimiterMemMapPtr->XMemory[7] = TCScalar;
}

// File Line: 790
// RVA: 0xAFDAE0
void __fastcall LimiterDSPMonoMemoryMapHelper::SetHold(LimiterDSPMonoMemoryMapHelper *this)
{
  this->LimiterMemMapPtr->XMemory[5] = (float)(LimiterUtilities::GetTotalLookAheadDelayLength(
                                                 &this->mLimiterUtilities,
                                                 (double)(int)this->mSampleRate)
                                             + 1);
}

// File Line: 804
// RVA: 0xAFDB20
void __fastcall LimiterDSPMonoMemoryMapHelper::SetLookAhead(LimiterDSPMonoMemoryMapHelper *this)
{
  int FIRLength; // eax
  float *v3; // rdi
  __int64 v4; // rcx
  float v5; // eax

  this->LimiterMemMapPtr->XMemory[2] = 608.0;
  this->LimiterMemMapPtr->XMemory[1] = (float)LimiterUtilities::GetTotalLookAheadDelayLength(
                                                &this->mLimiterUtilities,
                                                (double)(int)this->mSampleRate);
  this->LimiterMemMapPtr->XMemory[10] = 759.0;
  this->LimiterMemMapPtr->XMemory[11] = (float)LimiterUtilities::GetFIRLength(
                                                 &this->mLimiterUtilities,
                                                 (double)(int)this->mSampleRate);
  FIRLength = LimiterUtilities::GetFIRLength(&this->mLimiterUtilities, (double)(int)this->mSampleRate);
  v3 = &this->LimiterMemMapPtr->XMemory[759];
  if ( FIRLength > 0 )
  {
    v4 = (unsigned int)FIRLength;
    v5 = 1.0 / (float)FIRLength;
    while ( v4 )
    {
      *v3++ = v5;
      --v4;
    }
  }
}

// File Line: 829
// RVA: 0xAFD720
int __fastcall LimiterDSPMonoMemoryMapHelper::GetTotalLookAheadDelayLength(
        LimiterDSPMonoMemoryMapHelper *this,
        unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(&this->mLimiterUtilities, (double)(int)this->mSampleRate);
}

// File Line: 836
// RVA: 0xAFD760
void __fastcall LimiterDSPMonoMemoryMapHelper::FillMeteringData(
        LimiterDSPMonoMemoryMapHelper *this,
        char *pMeteringData)
{
  LimiterMonoMemoryMap *LimiterMemMapPtr; // r8

  LimiterMemMapPtr = this->LimiterMemMapPtr;
  *(_DWORD *)pMeteringData = 4;
  *((_DWORD *)pMeteringData + 1) = LODWORD(LimiterMemMapPtr->XMemory[13]);
  *((float *)pMeteringData + 2) = LimiterMemMapPtr->XMemory[14] * 3.9810717;
  *((_DWORD *)pMeteringData + 3) = LODWORD(LimiterMemMapPtr->XMemory[17]);
}

// File Line: 848
// RVA: 0xAFD2E0
void __fastcall LimiterProcessMonoFloatImpl::LimiterProcessMonoFloatImpl(LimiterProcessMonoFloatImpl *this)
{
  this->mMemoryMapHelper = 0i64;
}

// File Line: 854
// RVA: 0xAFD300
void __fastcall LimiterProcessMonoFloatImpl::~LimiterProcessMonoFloatImpl(LimiterProcessMonoFloatImpl *this)
{
  ;
}

// File Line: 861
// RVA: 0xAFD310
unsigned __int64 __fastcall LimiterProcessMonoFloatImpl::GetMemoryMapSize(LimiterProcessMonoFloatImpl *this)
{
  return 6472i64;
}

// File Line: 871
// RVA: 0xAFD320
__int64 __fastcall LimiterProcessMonoFloatImpl::Init(
        LimiterProcessMonoFloatImpl *this,
        PooledMemoryAllocator *memoryMapAllocator,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int sampleRate)
{
  DSPMemoryMapHelper *v7; // rax
  LimiterDSPMonoMemoryMapHelper *v8; // rbx
  unsigned int v10; // edi
  char *v11; // rax

  v7 = (DSPMemoryMapHelper *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24i64);
  v8 = (LimiterDSPMonoMemoryMapHelper *)v7;
  if ( v7 )
  {
    DSPMemoryMapHelper::DSPMemoryMapHelper(v7);
    LimiterUtilities::LimiterUtilities(&v8->mLimiterUtilities, 0.00085000001, 0.000325);
  }
  else
  {
    v8 = 0i64;
  }
  this->mMemoryMapHelper = v8;
  if ( !v8 )
    return 52i64;
  v10 = 1;
  v8->mNumChannels = 1;
  v8->mSampleRate = sampleRate;
  v11 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x1948ui64);
  v8->LimiterMemMapPtr = (LimiterMonoMemoryMap *)v11;
  if ( v11 )
    *((_DWORD *)v11 + 3) = 1065353216;
  else
    return 52;
  return v10;
}

// File Line: 882
// RVA: 0xAFD3D0
void __fastcall LimiterProcessMonoFloatImpl::Term(
        LimiterProcessMonoFloatImpl *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  LimiterDSPMonoMemoryMapHelper *mMemoryMapHelper; // rdi

  mMemoryMapHelper = this->mMemoryMapHelper;
  if ( this->mMemoryMapHelper )
  {
    LimiterUtilities::~LimiterUtilities(&mMemoryMapHelper->mLimiterUtilities);
    DSPMemoryMapHelper::~DSPMemoryMapHelper(mMemoryMapHelper);
    in_pAllocator->vfptr->Free(in_pAllocator, mMemoryMapHelper);
    this->mMemoryMapHelper = 0i64;
  }
  else
  {
    this->mMemoryMapHelper = 0i64;
  }
}

// File Line: 890
// RVA: 0xAFD440
void __fastcall LimiterProcessMonoFloatImpl::SetParameters(
        LimiterProcessMonoFloatImpl *this,
        LimiterParameters *limiterParams)
{
  long double v4; // xmm6_8
  double ceiling; // xmm1_8
  LimiterDSPMonoMemoryMapHelper *mMemoryMapHelper; // rbx
  float v7; // xmm1_4
  double v8; // xmm1_8
  double v9; // xmm0_8
  LimiterMonoMemoryMap *LimiterMemMapPtr; // rax
  float v11; // xmm1_4
  LimiterDSPMonoMemoryMapHelper *v12; // rbx
  int LookAheadDelayLength; // eax
  long double TCScalar; // xmm0_8
  LimiterDSPMonoMemoryMapHelper *v15; // rcx
  float v16; // xmm1_4
  LimiterDSPMonoMemoryMapHelper *v17; // rbx
  int TotalLookAheadDelayLength; // eax
  LimiterDSPMonoMemoryMapHelper *v19; // rcx

  v4 = limiterParams->threshold - 12.0;
  if ( v4 < -36.0 )
    v4 = DOUBLE_N36_0;
  ceiling = limiterParams->ceiling;
  mMemoryMapHelper = this->mMemoryMapHelper;
  if ( v4 < 0.0 )
    ceiling = ceiling + -0.01;
  v7 = pow(10.0, ceiling * 0.05);
  mMemoryMapHelper->LimiterMemMapPtr->XMemory[15] = v7;
  v8 = limiterParams->ceiling;
  if ( v4 < 0.0 )
    v8 = v8 + -0.01;
  v9 = pow(10.0, v8 * 0.05);
  LimiterMemMapPtr = mMemoryMapHelper->LimiterMemMapPtr;
  v11 = v9;
  LimiterMemMapPtr->XMemory[15] = v11;
  LimiterUtilities::GenerateExpTable(&LimiterMemMapPtr->YMemory[8], 600, v4, limiterParams->knee);
  v12 = this->mMemoryMapHelper;
  LookAheadDelayLength = LimiterUtilities::GetLookAheadDelayLength(
                           &this->mMemoryMapHelper->mLimiterUtilities,
                           (double)this->mMemoryMapHelper->mSampleRate);
  TCScalar = GetTCScalar((double)LookAheadDelayLength);
  v15 = this->mMemoryMapHelper;
  v16 = TCScalar;
  v12->LimiterMemMapPtr->XMemory[7] = v16;
  LimiterDSPMonoMemoryMapHelper::SetRelease(v15, limiterParams->release, limiterParams->character);
  LimiterDSPMonoMemoryMapHelper::SetCharacter(this->mMemoryMapHelper, limiterParams->character, limiterParams->release);
  v17 = this->mMemoryMapHelper;
  TotalLookAheadDelayLength = LimiterUtilities::GetTotalLookAheadDelayLength(
                                &this->mMemoryMapHelper->mLimiterUtilities,
                                (double)this->mMemoryMapHelper->mSampleRate);
  v19 = this->mMemoryMapHelper;
  v17->LimiterMemMapPtr->XMemory[5] = (float)(TotalLookAheadDelayLength + 1);
  LimiterDSPMonoMemoryMapHelper::SetLookAhead(v19);
}

// File Line: 929
// RVA: 0xAFD5C0
void __fastcall LimiterProcessMonoFloatImpl::ProcessAudio(
        LimiterProcessMonoFloatImpl *this,
        char *memoryMap,
        AkAudioBuffer *inputBuffer,
        AkAudioBuffer *outputBuffer)
{
  McDSPLimiterProcessChannels(
    memoryMap,
    (const float *)inputBuffer->pData,
    (float *)outputBuffer->pData,
    inputBuffer->uValidFrames);
}

// File Line: 941
// RVA: 0xAFD5E0
int __fastcall LimiterProcessMonoFloatImpl::GetNumTailFrames(
        LimiterProcessMonoFloatImpl *this,
        unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(
           &this->mMemoryMapHelper->mLimiterUtilities,
           (double)this->mMemoryMapHelper->mSampleRate);
}

// File Line: 946
// RVA: 0xAFD600
void __fastcall LimiterProcessMonoFloatImpl::FillMeteringData(LimiterProcessMonoFloatImpl *this, char *pMeteringData)
{
  LimiterMonoMemoryMap *LimiterMemMapPtr; // rcx

  LimiterMemMapPtr = this->mMemoryMapHelper->LimiterMemMapPtr;
  *(_DWORD *)pMeteringData = 4;
  *((_DWORD *)pMeteringData + 1) = LODWORD(LimiterMemMapPtr->XMemory[13]);
  *((float *)pMeteringData + 2) = LimiterMemMapPtr->XMemory[14] * 3.9810717;
  *((_DWORD *)pMeteringData + 3) = LODWORD(LimiterMemMapPtr->XMemory[17]);
}

