// File Line: 120
// RVA: 0xAFCC30
void __fastcall McDSPLimiterProcessChannels(void *memoryMap, const float *inputBuf, float *outputBuf, unsigned int samplesRemaining)
{
  signed int v4; // edi
  signed int v5; // esi
  char *v6; // rbx
  unsigned int v7; // er15
  const float *v8; // r12
  char *v9; // rdx
  __int64 v10; // r11
  signed int v11; // ebp
  signed int v12; // er10
  signed __int64 v13; // r9
  signed int v14; // er13
  signed int v15; // er14
  float *v16; // rcx
  float v17; // xmm9_4
  float v18; // xmm5_4
  float *v19; // r8
  signed __int64 v20; // rcx
  int v21; // xmm2_4
  char *v22; // rcx
  int v23; // xmm0_4
  int v24; // er10
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
  float v39; // xmm1_4
  int v40; // xmm4_4
  int v41; // xmm0_4
  float v42; // xmm5_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  signed __int64 v46; // rax
  signed __int64 v47; // rcx
  signed __int64 v48; // r9
  float v49; // xmm4_4
  __int64 v50; // rax
  float v51; // xmm5_4
  float v52; // xmm1_4
  int v53; // er10
  signed __int64 v54; // rax
  signed __int64 v55; // rcx
  unsigned int v56; // eax
  __int64 v57; // r9
  float v58; // xmm4_4
  signed __int64 v59; // rcx
  __int64 v60; // r9
  float v61; // xmm2_4
  __int64 v62; // rax
  float v63; // xmm4_4
  float v64; // xmm5_4
  int v65; // xmm4_4
  float v66; // xmm2_4
  float v67; // xmm4_4
  float v68; // xmm2_4
  signed __int64 v69; // [rsp+0h] [rbp-B8h]
  __int64 v70; // [rsp+8h] [rbp-B0h]
  signed __int64 v71; // [rsp+10h] [rbp-A8h]
  __int64 v72; // [rsp+18h] [rbp-A0h]
  signed __int64 v73; // [rsp+C0h] [rbp+8h]
  float *v74; // [rsp+D0h] [rbp+18h]
  signed int v75; // [rsp+D8h] [rbp+20h]

  v74 = outputBuf;
  v4 = (signed int)*((float *)memoryMap + 812);
  v5 = (signed int)*((float *)memoryMap + 1);
  v6 = (char *)memoryMap;
  v7 = samplesRemaining;
  v8 = inputBuf;
  v9 = (char *)memoryMap + 3240;
  v10 = (signed int)*((float *)memoryMap + 2);
  v72 = (signed int)*((float *)memoryMap + 2);
  v11 = (signed int)*((float *)memoryMap + 810);
  v12 = (signed int)*((float *)memoryMap + 10);
  v75 = (signed int)*((float *)memoryMap + 5);
  *(_QWORD *)((char *)memoryMap + 52) = 0i64;
  *((_DWORD *)memoryMap + 17) = 0;
  v13 = v11;
  v70 = v12;
  v14 = (signed int)*((float *)memoryMap + 12);
  v15 = (signed int)*((float *)memoryMap + 11);
  v73 = v14;
  if ( v7 )
  {
    v16 = (float *)((char *)memoryMap + 12);
    v69 = v12 + 1;
    v17 = kHeadRoomScaleFactor;
    do
    {
      --v7;
      ++v8;
      v18 = v17 * *(v8 - 1);
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
      v71 = v20;
      v21 = 0;
      v22 = &v6[4 * v10 + 3236];
      v23 = *(_DWORD *)&v6[4 * (v10 + v13) + 3236];
      *(float *)&v6[4 * (v10 + v13) + 3236] = v18;
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
      if ( COERCE_FLOAT(LODWORD(v29) & _xmm) > COERCE_FLOAT(*((_DWORD *)v9 + 3) & _xmm) )
      {
        v4 = v75;
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
      LODWORD(v39) = *((_DWORD *)v9 + 1) & _xmm;
      if ( v39 > COERCE_FLOAT(LODWORD(v36) & _xmm) )
        v36 = *((float *)v9 + 1);
      v40 = LODWORD(v36) & _xmm;
      *((_DWORD *)v19 + 1) = v40;
      v41 = *((_DWORD *)v9 + 3);
      if ( v39 > COERCE_FLOAT(v40 & _xmm) )
        v41 = v38;
      *((_DWORD *)v9 + 3) = v41 & _xmm;
      v42 = v19[5];
      if ( COERCE_FLOAT(*((_DWORD *)v9 + 5) & _xmm) < COERCE_FLOAT(LODWORD(v35) & _xmm) )
        v42 = v19[6];
      v43 = v19[1];
      v44 = (float)((float)(v35 - *((float *)v9 + 5)) * v42) + *((float *)v9 + 5);
      *((float *)v9 + 5) = v44;
      if ( v43 > v44 )
        v44 = v43;
      v19[1] = v44;
      v45 = *((float *)v9 + 3);
      if ( v4 <= 0 )
        v45 = v44;
      v46 = v73;
      ++v14;
      v47 = v73 + 1;
      *((float *)v9 + 3) = v45;
      v48 = v73;
      if ( v73 + 1 >= v15 )
      {
        v47 = 0i64;
        v14 = 0;
      }
      v73 = v47;
      v49 = 0.0;
      v50 = v70 + v46;
      *(float *)&v6[4 * v50 + 3236] = v44;
      v51 = *(float *)&v6[4 * v70];
      v52 = *(float *)&v6[4 * (v50 - v48) + 3236];
      v53 = 0;
      v54 = v69;
      if ( v15 >= 4 )
      {
        v55 = (signed __int64)&v6[4 * (v69 + 811)];
        v56 = ((unsigned int)(v15 - 4) >> 2) + 1;
        v57 = v56;
        v53 = 4 * v56;
        v54 = v69 + 4i64 * v56;
        do
        {
          v55 += 16i64;
          v58 = (float)((float)((float)(v52 * v51) + v49) + (float)(v51 * *(float *)(v55 - 24)))
              + (float)(v51 * *(float *)(v55 - 20));
          v52 = *(float *)(v55 - 12);
          v49 = v58 + (float)(v51 * *(float *)(v55 - 16));
          --v57;
        }
        while ( v57 );
      }
      if ( v53 < v15 )
      {
        v59 = (signed __int64)&v6[4 * v54 + 3236];
        v60 = (unsigned int)(v15 - v53);
        do
        {
          v59 += 4i64;
          v49 = v49 + (float)(v52 * v51);
          v52 = *(float *)(v59 - 4);
          --v60;
        }
        while ( v60 );
      }
      v61 = (float)((float)((float)((float)(v49 * 2.0) - (float)(v49 * v49)) * 2.0)
                  - (float)((float)((float)(v49 * 2.0) - (float)(v49 * v49))
                          * (float)((float)(v49 * 2.0) - (float)(v49 * v49))))
          * 599.0;
      v62 = (signed int)v61;
      v63 = (float)((float)(*(float *)&v9[4 * v62 + 32] - *(float *)&v9[4 * v62 + 28])
                  * (float)(v61 - (float)(signed int)v61))
          + *(float *)&v9[4 * v62 + 28];
      v64 = (float)((float)(*(float *)&v9[4 * v62 + 32] - *(float *)&v9[4 * v62 + 28])
                  * (float)(v61 - (float)(signed int)v61))
          + *(float *)&v9[4 * v62 + 28];
      if ( COERCE_FLOAT((_DWORD)v19[10] & _xmm) > COERCE_FLOAT(LODWORD(v63) & _xmm) )
        v63 = v19[10];
      v19[10] = v63;
      v65 = *((_DWORD *)v19 + 11);
      v66 = *((float *)v9 + 1);
      if ( COERCE_FLOAT(*((_DWORD *)v9 + 1) & _xmm) > COERCE_FLOAT((_DWORD)v19[11] & _xmm) )
        v65 = *((_DWORD *)v9 + 1);
      *((_DWORD *)v19 + 11) = v65;
      v67 = v19[14];
      v68 = (float)(v66 * v64) * v19[12];
      if ( COERCE_FLOAT(LODWORD(v68) & _xmm) > COERCE_FLOAT((_DWORD)v19[14] & _xmm) )
        v67 = v68;
      v13 = v71;
      v10 = v72;
      v19[14] = v67;
      v9 = v6 + 3240;
      v16 = (float *)(v6 + 12);
      *v74 = v68;
      ++v74;
    }
    while ( v7 );
    v9 = v6 + 3240;
  }
  *((float *)v6 + 812) = (float)v4;
  *(float *)v9 = (float)v11;
  *((float *)v6 + 12) = (float)v14;
}

// File Line: 557
// RVA: 0xAFD230
void __fastcall McDSPFillVUMetersDataMono(void *memoryMap, char *pMeteringData)
{
  *(_DWORD *)pMeteringData = 4;
  *((_DWORD *)pMeteringData + 1) = *((_DWORD *)memoryMap + 13);
  *((float *)pMeteringData + 2) = *((float *)memoryMap + 14) * 3.9810717;
  *((_DWORD *)pMeteringData + 3) = *((_DWORD *)memoryMap + 17);
}

// File Line: 628
// RVA: 0xAFD640
void __fastcall LimiterDSPMonoMemoryMapHelper::LimiterDSPMonoMemoryMapHelper(LimiterDSPMonoMemoryMapHelper *this, int sampleRate)
{
  LimiterDSPMonoMemoryMapHelper *v2; // rbx

  v2 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->0);
  LimiterUtilities::LimiterUtilities(&v2->mLimiterUtilities, 0.00085000001, 0.000325);
}

// File Line: 634
// RVA: 0xAFD680
void __fastcall LimiterDSPMonoMemoryMapHelper::~LimiterDSPMonoMemoryMapHelper(LimiterDSPMonoMemoryMapHelper *this)
{
  LimiterDSPMonoMemoryMapHelper *v1; // rbx

  v1 = this;
  LimiterUtilities::~LimiterUtilities(&this->mLimiterUtilities);
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&v1->0);
}

// File Line: 639
// RVA: 0xAFD6B0
unsigned __int64 __fastcall LimiterDSPMonoMemoryMapHelper::GetMemoryMapSize(LimiterDSPMonoMemoryMapHelper *this)
{
  return 6472i64;
}

// File Line: 647
// RVA: 0xAFD6C0
signed __int64 __fastcall LimiterDSPMonoMemoryMapHelper::Init(LimiterDSPMonoMemoryMapHelper *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int sampleRate)
{
  LimiterDSPMonoMemoryMapHelper *v3; // rbx
  char *v4; // rax

  v3 = this;
  this->mNumChannels = 1;
  this->mSampleRate = sampleRate;
  v4 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x1948ui64);
  v3->LimiterMemMapPtr = (LimiterMonoMemoryMap *)v4;
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
void __fastcall LimiterDSPMonoMemoryMapHelper::SetCeiling(LimiterDSPMonoMemoryMapHelper *this, long double ceiling, long double threshold)
{
  LimiterDSPMonoMemoryMapHelper *v3; // rbx
  float v4; // xmm1_4

  v3 = this;
  if ( threshold < 0.0 )
    ceiling = ceiling + -0.01;
  v4 = pow(10.0, ceiling * 0.05);
  v3->LimiterMemMapPtr->XMemory[15] = v4;
}

// File Line: 693
// RVA: 0xAFD7F0
void __fastcall LimiterDSPMonoMemoryMapHelper::SetThreshold(LimiterDSPMonoMemoryMapHelper *this, long double threshold, long double knee, long double ceiling)
{
  LimiterDSPMonoMemoryMapHelper *v4; // rbx
  float v5; // xmm1_4

  v4 = this;
  if ( threshold < 0.0 )
    ceiling = ceiling - 0.01;
  v5 = pow(10.0, ceiling * 0.05);
  v4->LimiterMemMapPtr->XMemory[15] = v5;
}

// File Line: 703
// RVA: 0xAFD840
void __fastcall LimiterDSPMonoMemoryMapHelper::SetKnee(LimiterDSPMonoMemoryMapHelper *this, long double knee, long double threshold)
{
  ;
}

// File Line: 713
// RVA: 0xAFD740
void __fastcall LimiterDSPMonoMemoryMapHelper::GenerateExpTable(LimiterDSPMonoMemoryMapHelper *this, long double knee, long double threshold)
{
  LimiterUtilities::GenerateExpTable(&this->LimiterMemMapPtr->YMemory[8], 600, threshold, knee);
}

// File Line: 721
// RVA: 0xAFD850
void __fastcall LimiterDSPMonoMemoryMapHelper::SetRelease(LimiterDSPMonoMemoryMapHelper *this, long double release, LimiterCharacterType character)
{
  double v3; // xmm2_8
  LimiterDSPMonoMemoryMapHelper *v4; // rbx
  double v5; // xmm0_8
  double v6; // xmm1_8
  float v7; // xmm1_4
  double v8; // [rsp+30h] [rbp+8h]

  v3 = release;
  v4 = this;
  switch ( character )
  {
    case 0:
      v5 = DOUBLE_3_0;
      v6 = 0.0;
      break;
    case 1:
      v5 = DOUBLE_4_0;
      v6 = 0.0;
      break;
    case 2:
      v5 = DOUBLE_5_0;
      v6 = 0.0;
      break;
    case 3:
      v5 = DOUBLE_6_0;
      v6 = 0.0;
      break;
    case 4:
      v5 = DOUBLE_10_0;
      v6 = 0.0;
      break;
    case 5:
      v5 = DOUBLE_15_0;
      v6 = 0.0;
      break;
    default:
      v6 = v8;
      v5 = v8;
      break;
  }
  if ( v3 > v5 )
    v3 = v5;
  v7 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v6 + v3);
  v4->LimiterMemMapPtr->XMemory[6] = v7;
}

// File Line: 745
// RVA: 0xAFD920
void __fastcall LimiterDSPMonoMemoryMapHelper::SetCharacter(LimiterDSPMonoMemoryMapHelper *this, LimiterCharacterType character, long double release)
{
  LimiterDSPMonoMemoryMapHelper *v3; // rbx
  long double v4; // xmm1_8
  double v5; // xmm6_8
  double v6; // xmm7_8
  double v7; // xmm8_8
  float v8; // xmm2_4
  float v9; // xmm1_4
  double attack; // [rsp+60h] [rbp+8h]

  v3 = this;
  switch ( character )
  {
    case 0:
      v4 = DOUBLE_50_0;
      v5 = DOUBLE_800_0;
      v6 = DOUBLE_3_0;
      break;
    case 1:
      v4 = DOUBLE_40_0;
      v5 = DOUBLE_600_0;
      v6 = DOUBLE_4_0;
      break;
    case 2:
      v4 = DOUBLE_30_0;
      v5 = DOUBLE_400_0;
      v6 = DOUBLE_5_0;
      break;
    case 3:
      v4 = DOUBLE_20_0;
      v5 = DOUBLE_200_0;
      v6 = DOUBLE_6_0;
      break;
    case 4:
      v4 = DOUBLE_10_0;
      v5 = DOUBLE_100_0;
      v6 = DOUBLE_10_0;
      break;
    case 5:
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
  v3->LimiterMemMapPtr->XMemory[9] = v8;
  if ( v7 < 0.0 )
    v7 = 0.0;
  v9 = DynamicsCalculator::CalculateReleaseScalar(v3->mSampleRate, v5 + v7);
  v3->LimiterMemMapPtr->XMemory[8] = v9;
}

// File Line: 778
// RVA: 0xAFDA90
void __fastcall LimiterDSPMonoMemoryMapHelper::SetAttack(LimiterDSPMonoMemoryMapHelper *this)
{
  LimiterDSPMonoMemoryMapHelper *v1; // rbx
  signed int v2; // eax
  float v3; // xmm1_4

  v1 = this;
  v2 = LimiterUtilities::GetLookAheadDelayLength(&this->mLimiterUtilities, (double)(signed int)this->mSampleRate);
  v3 = GetTCScalar((double)v2);
  v1->LimiterMemMapPtr->XMemory[7] = v3;
}

// File Line: 790
// RVA: 0xAFDAE0
void __fastcall LimiterDSPMonoMemoryMapHelper::SetHold(LimiterDSPMonoMemoryMapHelper *this)
{
  this->LimiterMemMapPtr->XMemory[5] = (float)(LimiterUtilities::GetTotalLookAheadDelayLength(
                                                 &this->mLimiterUtilities,
                                                 (double)(signed int)this->mSampleRate)
                                             + 1);
}

// File Line: 804
// RVA: 0xAFDB20
void __fastcall LimiterDSPMonoMemoryMapHelper::SetLookAhead(LimiterDSPMonoMemoryMapHelper *this)
{
  LimiterDSPMonoMemoryMapHelper *v1; // rbx
  signed int v2; // eax
  float *v3; // rdi
  __int64 v4; // rcx
  float v5; // eax

  v1 = this;
  this->LimiterMemMapPtr->XMemory[2] = 608.0;
  this->LimiterMemMapPtr->XMemory[1] = (float)LimiterUtilities::GetTotalLookAheadDelayLength(
                                                &this->mLimiterUtilities,
                                                (double)(signed int)this->mSampleRate);
  v1->LimiterMemMapPtr->XMemory[10] = 759.0;
  v1->LimiterMemMapPtr->XMemory[11] = (float)LimiterUtilities::GetFIRLength(
                                               &v1->mLimiterUtilities,
                                               (double)(signed int)v1->mSampleRate);
  v2 = LimiterUtilities::GetFIRLength(&v1->mLimiterUtilities, (double)(signed int)v1->mSampleRate);
  v3 = &v1->LimiterMemMapPtr->XMemory[759];
  if ( v2 > 0 )
  {
    v4 = (unsigned int)v2;
    v5 = 1.0 / (float)v2;
    while ( v4 )
    {
      *v3 = v5;
      ++v3;
      --v4;
    }
  }
}

// File Line: 829
// RVA: 0xAFD720
int __fastcall LimiterDSPMonoMemoryMapHelper::GetTotalLookAheadDelayLength(LimiterDSPMonoMemoryMapHelper *this, unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(&this->mLimiterUtilities, (double)(signed int)this->mSampleRate);
}

// File Line: 836
// RVA: 0xAFD760
void __fastcall LimiterDSPMonoMemoryMapHelper::FillMeteringData(LimiterDSPMonoMemoryMapHelper *this, char *pMeteringData)
{
  LimiterMonoMemoryMap *v2; // r8

  v2 = this->LimiterMemMapPtr;
  *(_DWORD *)pMeteringData = 4;
  *((_DWORD *)pMeteringData + 1) = LODWORD(v2->XMemory[13]);
  *((float *)pMeteringData + 2) = v2->XMemory[14] * 3.9810717;
  *((_DWORD *)pMeteringData + 3) = LODWORD(v2->XMemory[17]);
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
signed __int64 __fastcall LimiterProcessMonoFloatImpl::Init(LimiterProcessMonoFloatImpl *this, PooledMemoryAllocator *memoryMapAllocator, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int sampleRate)
{
  PooledMemoryAllocator *v4; // rbp
  LimiterProcessMonoFloatImpl *v5; // rdi
  unsigned int v6; // esi
  DSPMemoryMapHelper *v7; // rax
  LimiterDSPMonoMemoryMapHelper *v8; // rbx
  unsigned int v10; // edi
  char *v11; // rax

  v4 = memoryMapAllocator;
  v5 = this;
  v6 = sampleRate;
  v7 = (DSPMemoryMapHelper *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24ui64);
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
  v5->mMemoryMapHelper = v8;
  if ( !v8 )
    return 52i64;
  v10 = 1;
  v8->mNumChannels = 1;
  v8->mSampleRate = v6;
  v11 = PooledMemoryAllocator::Malloc(v4, 0x1948ui64);
  v8->LimiterMemMapPtr = (LimiterMonoMemoryMap *)v11;
  if ( v11 )
    *((_DWORD *)v11 + 3) = 1065353216;
  else
    v10 = 52;
  return v10;
}

// File Line: 882
// RVA: 0xAFD3D0
void __fastcall LimiterProcessMonoFloatImpl::Term(LimiterProcessMonoFloatImpl *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  LimiterDSPMonoMemoryMapHelper *v2; // rdi
  AK::IAkPluginMemAlloc *v3; // rsi
  LimiterProcessMonoFloatImpl *v4; // rbx

  v2 = this->mMemoryMapHelper;
  v3 = in_pAllocator;
  v4 = this;
  if ( this->mMemoryMapHelper )
  {
    LimiterUtilities::~LimiterUtilities(&v2->mLimiterUtilities);
    DSPMemoryMapHelper::~DSPMemoryMapHelper(&v2->0);
    v3->vfptr->Free(v3, v2);
    v4->mMemoryMapHelper = 0i64;
  }
  else
  {
    this->mMemoryMapHelper = 0i64;
  }
}

// File Line: 890
// RVA: 0xAFD440
void __fastcall LimiterProcessMonoFloatImpl::SetParameters(LimiterProcessMonoFloatImpl *this, LimiterParameters *limiterParams)
{
  LimiterParameters *v2; // rdi
  LimiterProcessMonoFloatImpl *v3; // rsi
  long double v4; // xmm6_8
  double v5; // xmm1_8
  LimiterDSPMonoMemoryMapHelper *v6; // rbx
  float v7; // xmm1_4
  double v8; // xmm1_8
  double v9; // xmm0_8
  LimiterMonoMemoryMap *v10; // rax
  float v11; // xmm1_4
  LimiterUtilities *v12; // rbx
  signed int v13; // eax
  long double v14; // xmm0_8
  LimiterDSPMonoMemoryMapHelper *v15; // rcx
  float v16; // xmm1_4
  LimiterDSPMonoMemoryMapHelper *v17; // rbx
  int v18; // eax
  LimiterDSPMonoMemoryMapHelper *v19; // rcx

  v2 = limiterParams;
  v3 = this;
  v4 = limiterParams->threshold - 12.0;
  if ( v4 < -36.0 )
    v4 = DOUBLE_N36_0;
  v5 = limiterParams->ceiling;
  v6 = this->mMemoryMapHelper;
  if ( v4 < 0.0 )
    v5 = v5 + -0.01;
  v7 = pow(10.0, v5 * 0.05);
  v6->LimiterMemMapPtr->XMemory[15] = v7;
  v8 = v2->ceiling;
  if ( v4 < 0.0 )
    v8 = v8 + -0.01;
  v9 = pow(10.0, v8 * 0.05);
  v10 = v6->LimiterMemMapPtr;
  v11 = v9;
  v10->XMemory[15] = v11;
  LimiterUtilities::GenerateExpTable(&v10->YMemory[8], 600, v4, v2->knee);
  v12 = (LimiterUtilities *)v3->mMemoryMapHelper;
  v13 = LimiterUtilities::GetLookAheadDelayLength(
          &v3->mMemoryMapHelper->mLimiterUtilities,
          (double)v3->mMemoryMapHelper->mSampleRate);
  v14 = GetTCScalar((double)v13);
  v15 = v3->mMemoryMapHelper;
  v16 = v14;
  *(float *)(*(_QWORD *)&v12[1] + 28i64) = v16;
  LimiterDSPMonoMemoryMapHelper::SetRelease(v15, v2->release, v2->character);
  LimiterDSPMonoMemoryMapHelper::SetCharacter(v3->mMemoryMapHelper, v2->character, v2->release);
  v17 = v3->mMemoryMapHelper;
  v18 = LimiterUtilities::GetTotalLookAheadDelayLength(
          &v3->mMemoryMapHelper->mLimiterUtilities,
          (double)v3->mMemoryMapHelper->mSampleRate);
  v19 = v3->mMemoryMapHelper;
  v17->LimiterMemMapPtr->XMemory[5] = (float)(v18 + 1);
  LimiterDSPMonoMemoryMapHelper::SetLookAhead(v19);
}

// File Line: 929
// RVA: 0xAFD5C0
void __fastcall LimiterProcessMonoFloatImpl::ProcessAudio(LimiterProcessMonoFloatImpl *this, void *memoryMap, AkAudioBuffer *inputBuffer, AkAudioBuffer *outputBuffer)
{
  McDSPLimiterProcessChannels(
    memoryMap,
    (const float *)inputBuffer->pData,
    (float *)outputBuffer->pData,
    inputBuffer->uValidFrames);
}

// File Line: 941
// RVA: 0xAFD5E0
int __fastcall LimiterProcessMonoFloatImpl::GetNumTailFrames(LimiterProcessMonoFloatImpl *this, unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(
           &this->mMemoryMapHelper->mLimiterUtilities,
           (double)this->mMemoryMapHelper->mSampleRate);
}

// File Line: 946
// RVA: 0xAFD600
void __fastcall LimiterProcessMonoFloatImpl::FillMeteringData(LimiterProcessMonoFloatImpl *this, char *pMeteringData)
{
  LimiterMonoMemoryMap *v2; // rcx

  v2 = this->mMemoryMapHelper->LimiterMemMapPtr;
  *(_DWORD *)pMeteringData = 4;
  *((_DWORD *)pMeteringData + 1) = LODWORD(v2->XMemory[13]);
  *((float *)pMeteringData + 2) = v2->XMemory[14] * 3.9810717;
  *((_DWORD *)pMeteringData + 3) = LODWORD(v2->XMemory[17]);
}

