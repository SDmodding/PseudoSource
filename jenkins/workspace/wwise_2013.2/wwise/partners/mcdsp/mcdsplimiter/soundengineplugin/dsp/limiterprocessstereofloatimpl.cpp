// File Line: 134
// RVA: 0xAFDBE0
void __fastcall McDSPLimiterProcessChannels(
        float *memoryMap,
        const float *inputBufLeft,
        const float *inputBufRight,
        float *outputBufLeft,
        float *outputBufRight,
        unsigned int samplesRemaining)
{
  int v6; // edi
  int v7; // esi
  float *v10; // r8
  int v12; // edx
  int v13; // r11d
  __int64 v14; // r15
  int v15; // r12d
  int v16; // r9d
  int v17; // r13d
  unsigned int v18; // ecx
  signed __int64 v19; // r10
  __int64 v20; // rdx
  float v21; // xmm10_4
  float *v22; // rbp
  float v23; // xmm2_4
  float v24; // xmm4_4
  int v25; // ecx
  __int64 v26; // r8
  __int64 v27; // rax
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm6_4
  int v31; // xmm2_4
  int v32; // r10d
  char *v33; // rcx
  unsigned int v34; // eax
  __int64 v35; // r9
  __int64 v36; // r9
  float v37; // xmm5_4
  float v38; // xmm4_4
  float v39; // xmm4_4
  float v40; // xmm4_4
  float v41; // xmm5_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm4_4
  int v45; // xmm0_4
  int v46; // xmm5_4
  int v47; // xmm4_4
  int v48; // xmm0_4
  float v49; // xmm5_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm0_4
  __int64 v53; // rax
  __int64 v54; // rcx
  __int64 v55; // r9
  float v56; // xmm4_4
  __int64 v57; // rax
  float v58; // xmm5_4
  int v59; // r10d
  float v60; // xmm1_4
  __int64 v61; // rax
  float *v62; // rcx
  unsigned int v63; // eax
  __int64 v64; // r9
  float v65; // xmm4_4
  float *v66; // rcx
  __int64 v67; // r9
  float v68; // xmm2_4
  float v69; // xmm4_4
  float v70; // xmm5_4
  int v71; // xmm4_4
  float v72; // xmm2_4
  float v73; // xmm4_4
  float v74; // xmm2_4
  float *v75; // r10
  int v76; // xmm4_4
  float v77; // xmm2_4
  float v78; // xmm4_4
  float v79; // xmm2_4
  int v80; // [rsp+0h] [rbp-E8h]
  int v81; // [rsp+4h] [rbp-E4h]
  __int64 v82; // [rsp+8h] [rbp-E0h]
  __int64 v83; // [rsp+10h] [rbp-D8h]
  __int64 v84; // [rsp+18h] [rbp-D0h]
  __int64 v85; // [rsp+20h] [rbp-C8h]
  int v86; // [rsp+F0h] [rbp+8h]
  signed __int64 v87; // [rsp+F8h] [rbp+10h]
  unsigned int samplesRemaininga; // [rsp+118h] [rbp+30h]

  v6 = (int)memoryMap[968];
  v7 = (int)memoryMap[2];
  v10 = memoryMap + 964;
  v83 = (int)memoryMap[3];
  v12 = (int)memoryMap[4];
  v13 = (int)memoryMap[964];
  v81 = (int)memoryMap[7];
  *(_QWORD *)(memoryMap + 15) = 0i64;
  *(_QWORD *)(memoryMap + 19) = 0i64;
  memoryMap[23] = 0.0;
  v84 = v12;
  v80 = v12;
  v14 = v13;
  v15 = (int)memoryMap[14];
  v16 = (int)memoryMap[12];
  v17 = (int)memoryMap[13];
  v82 = v15;
  v18 = samplesRemaining;
  v85 = v16;
  if ( samplesRemaining )
  {
    v19 = (char *)inputBufLeft - (char *)inputBufRight;
    v20 = v16 + 1;
    v87 = v19;
    v21 = kHeadRoomScaleFactor_0;
    do
    {
      v22 = v10;
      ++inputBufRight;
      samplesRemaininga = v18 - 1;
      v23 = v21 * *(const float *)((char *)inputBufRight + v19 - 4);
      v24 = v21 * *(inputBufRight - 1);
      if ( v23 < 1.0 )
      {
        if ( v23 <= -1.0 )
          v23 = FLOAT_N1_0;
      }
      else
      {
        v23 = *(float *)&FLOAT_1_0;
      }
      if ( v24 < 1.0 )
      {
        if ( v24 <= -1.0 )
          v24 = FLOAT_N1_0;
      }
      else
      {
        v24 = *(float *)&FLOAT_1_0;
      }
      v25 = v13 + 1;
      v26 = v14 + 1;
      if ( v13 + 1 >= v7 )
      {
        v25 = 0;
        v26 = 0i64;
      }
      v86 = v25;
      v27 = v14 + v83;
      v28 = memoryMap[v14 + v83];
      memoryMap[v27] = v23;
      v29 = memoryMap[v14 + 962 + v83];
      memoryMap[v27 + 962] = v24;
      v22[1] = v28;
      v22[2] = v29;
      if ( COERCE_FLOAT(LODWORD(v28) & _xmm) > COERCE_FLOAT(LODWORD(v29) & _xmm) )
        v29 = v28;
      v22[3] = v29;
      LODWORD(v30) = LODWORD(v23) & _xmm;
      if ( COERCE_FLOAT(LODWORD(v24) & _xmm) > COERCE_FLOAT(LODWORD(v23) & _xmm) )
        v23 = v24;
      memoryMap[v14 + 962 + v84] = v23;
      v31 = 0;
      v32 = 0;
      v33 = (char *)&memoryMap[v80 + 962];
      if ( v7 >= 4 )
      {
        v34 = ((unsigned int)(v7 - 4) >> 2) + 1;
        v35 = v34;
        v32 = 4 * v34;
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v33 & _xmm) > COERCE_FLOAT(v31 & _xmm) )
            v31 = *(_DWORD *)v33;
          if ( COERCE_FLOAT(*((_DWORD *)v33 + 1) & _xmm) > COERCE_FLOAT(v31 & _xmm) )
            v31 = *((_DWORD *)v33 + 1);
          if ( COERCE_FLOAT(*((_DWORD *)v33 + 2) & _xmm) > COERCE_FLOAT(v31 & _xmm) )
            v31 = *((_DWORD *)v33 + 2);
          if ( COERCE_FLOAT(*((_DWORD *)v33 + 3) & _xmm) > COERCE_FLOAT(v31 & _xmm) )
            v31 = *((_DWORD *)v33 + 3);
          v33 += 16;
          --v35;
        }
        while ( v35 );
      }
      if ( v32 < v7 )
      {
        v36 = (unsigned int)(v7 - v32);
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v33 & _xmm) > COERCE_FLOAT(v31 & _xmm) )
            v31 = *(_DWORD *)v33;
          v33 += 4;
          --v36;
        }
        while ( v36 );
      }
      v37 = memoryMap[6];
      if ( COERCE_FLOAT(LODWORD(v24) & _xmm) > v30 )
        LODWORD(v30) = LODWORD(v24) & _xmm;
      if ( v30 >= 1.0 )
        v30 = *(float *)&FLOAT_1_0;
      if ( COERCE_FLOAT((_DWORD)memoryMap[5] & _xmm) <= COERCE_FLOAT(LODWORD(v30) & _xmm) )
        v30 = memoryMap[5];
      v38 = v22[5];
      if ( COERCE_FLOAT(LODWORD(v30) & _xmm) > COERCE_FLOAT(LODWORD(v38) & _xmm) )
      {
        v6 = v81;
        v38 = v30;
      }
      LODWORD(v39) = LODWORD(v38) & _xmm;
      v22[5] = v39;
      v40 = v39 - v37;
      if ( COERCE_FLOAT((_DWORD)v22[6] & _xmm) > COERCE_FLOAT(LODWORD(v40) & _xmm) )
        v40 = v22[6];
      --v6;
      v22[6] = v40;
      if ( v6 < 0 )
        v6 = 0;
      v41 = 0.0;
      v42 = memoryMap[9];
      if ( v6 <= 0 )
      {
        v41 = memoryMap[8];
        v42 = 0.0;
      }
      LODWORD(v43) = v31 & _xmm;
      v44 = (float)((float)(v40 * v42) + memoryMap[6]) + (float)((float)(v43 - memoryMap[6]) * v41);
      if ( COERCE_FLOAT((_DWORD)v22[5] & _xmm) <= COERCE_FLOAT(LODWORD(v44) & _xmm) )
        v44 = v22[5];
      v45 = *((_DWORD *)v22 + 6);
      if ( v6 <= 0 )
        v45 = 0;
      *((_DWORD *)v22 + 6) = v45;
      v46 = *((_DWORD *)v22 + 3);
      if ( COERCE_FLOAT(v46 & _xmm) > COERCE_FLOAT(LODWORD(v44) & _xmm) )
        v44 = v22[3];
      v47 = LODWORD(v44) & _xmm;
      *((_DWORD *)memoryMap + 6) = v47;
      v48 = *((_DWORD *)v22 + 5);
      if ( COERCE_FLOAT(v46 & _xmm) > COERCE_FLOAT(v47 & _xmm) )
        v48 = v46;
      *((_DWORD *)v22 + 5) = v48 & _xmm;
      v49 = memoryMap[10];
      if ( COERCE_FLOAT((_DWORD)v22[7] & _xmm) < COERCE_FLOAT(LODWORD(v43) & _xmm) )
        v49 = memoryMap[11];
      v50 = memoryMap[6];
      v51 = (float)((float)(v43 - v22[7]) * v49) + v22[7];
      v22[7] = v51;
      if ( v50 > v51 )
        v51 = v50;
      memoryMap[6] = v51;
      v52 = v22[5];
      if ( v6 <= 0 )
        v52 = v51;
      v53 = v82;
      ++v15;
      v54 = v82 + 1;
      v22[5] = v52;
      v55 = v82;
      if ( v82 + 1 >= v17 )
      {
        v15 = 0;
        v54 = 0i64;
      }
      v82 = v54;
      v56 = 0.0;
      v57 = v85 + v53;
      memoryMap[v57 + 962] = v51;
      v58 = memoryMap[v85];
      v59 = 0;
      v60 = memoryMap[v57 - v55 + 962];
      v61 = v20;
      if ( v17 >= 4 )
      {
        v62 = &memoryMap[v20 + 964];
        v63 = ((unsigned int)(v17 - 4) >> 2) + 1;
        v64 = v63;
        v59 = 4 * v63;
        v61 = v20 + 4i64 * v63;
        do
        {
          v62 += 4;
          v65 = (float)((float)((float)(v60 * v58) + v56) + (float)(v58 * *(v62 - 6))) + (float)(v58 * *(v62 - 5));
          v60 = *(v62 - 3);
          v56 = v65 + (float)(v58 * *(v62 - 4));
          --v64;
        }
        while ( v64 );
      }
      if ( v59 < v17 )
      {
        v66 = &memoryMap[v61 + 962];
        v67 = (unsigned int)(v17 - v59);
        do
        {
          ++v66;
          v56 = v56 + (float)(v60 * v58);
          v60 = *(v66 - 1);
          --v67;
        }
        while ( v67 );
      }
      v68 = (float)((float)((float)((float)(v56 * 2.0) - (float)(v56 * v56)) * 2.0)
                  - (float)((float)((float)(v56 * 2.0) - (float)(v56 * v56))
                          * (float)((float)(v56 * 2.0) - (float)(v56 * v56))))
          * 599.0;
      v69 = (float)((float)(v22[(int)v68 + 10] - v22[(int)v68 + 9]) * (float)(v68 - (float)(int)v68))
          + v22[(int)v68 + 9];
      v70 = v69;
      if ( COERCE_FLOAT((_DWORD)memoryMap[15] & _xmm) > COERCE_FLOAT(LODWORD(v69) & _xmm) )
        v69 = memoryMap[15];
      memoryMap[15] = v69;
      v71 = *((_DWORD *)memoryMap + 16);
      v72 = v22[1];
      if ( COERCE_FLOAT(LODWORD(v72) & _xmm) > COERCE_FLOAT(v71 & _xmm) )
        v71 = *((_DWORD *)v22 + 1);
      *((_DWORD *)memoryMap + 16) = v71;
      v73 = memoryMap[19];
      v74 = (float)(v72 * v70) * memoryMap[17];
      if ( COERCE_FLOAT(LODWORD(v74) & _xmm) > COERCE_FLOAT(LODWORD(v73) & _xmm) )
        v73 = v74;
      v75 = outputBufLeft;
      memoryMap[19] = v73;
      ++outputBufLeft;
      *v75 = v74;
      v76 = *((_DWORD *)memoryMap + 20);
      v77 = v22[2];
      if ( COERCE_FLOAT(LODWORD(v77) & _xmm) > COERCE_FLOAT(v76 & _xmm) )
        v76 = *((_DWORD *)v22 + 2);
      *((_DWORD *)memoryMap + 20) = v76;
      v78 = memoryMap[23];
      v79 = (float)(v77 * v70) * memoryMap[21];
      if ( COERCE_FLOAT(LODWORD(v79) & _xmm) > COERCE_FLOAT(LODWORD(v78) & _xmm) )
        v78 = v79;
      v18 = samplesRemaininga;
      v13 = v86;
      memoryMap[23] = v78;
      v14 = v26;
      v19 = v87;
      *outputBufRight = v79;
      v10 = memoryMap + 964;
      ++outputBufRight;
    }
    while ( samplesRemaininga );
    v10 = memoryMap + 964;
  }
  memoryMap[968] = (float)v6;
  *v10 = (float)v13;
  memoryMap[14] = (float)v15;
}

// File Line: 661
// RVA: 0xAFE2F0
void __fastcall McDSPFillVUMetersDataStereo(float *memoryMap, float *pMeteringData)
{
  *(_DWORD *)pMeteringData = 3;
  pMeteringData[1] = memoryMap[15];
  pMeteringData[2] = memoryMap[16] * 3.9810717;
  pMeteringData[3] = memoryMap[20] * 3.9810717;
  pMeteringData[4] = memoryMap[19];
  pMeteringData[5] = memoryMap[23];
}

// File Line: 736
// RVA: 0xAFE770
void __fastcall LimiterDSPStereoMemoryMapHelper::LimiterDSPStereoMemoryMapHelper(
        LimiterDSPStereoMemoryMapHelper *this,
        int sampleRate)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(this);
  LimiterUtilities::LimiterUtilities(&this->mLimiterUtilities, 0.00085000001, 0.000325);
}

// File Line: 742
// RVA: 0xAFE7B0
void __fastcall LimiterDSPStereoMemoryMapHelper::~LimiterDSPStereoMemoryMapHelper(
        LimiterDSPStereoMemoryMapHelper *this)
{
  LimiterUtilities::~LimiterUtilities(&this->mLimiterUtilities);
  DSPMemoryMapHelper::~DSPMemoryMapHelper(this);
}

// File Line: 748
// RVA: 0xAFE7E0
unsigned __int64 __fastcall LimiterDSPStereoMemoryMapHelper::GetMemoryMapSize(LimiterDSPStereoMemoryMapHelper *this)
{
  return 7696i64;
}

// File Line: 756
// RVA: 0xAFE7F0
__int64 __fastcall LimiterDSPStereoMemoryMapHelper::Init(
        LimiterDSPStereoMemoryMapHelper *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int sampleRate)
{
  char *v4; // rax

  this->mNumChannels = 2;
  this->mSampleRate = sampleRate;
  v4 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x1E10ui64);
  this->LimiterMemMapPtr = (LimiterStereoMemoryMap *)v4;
  if ( !v4 )
    return 52i64;
  *((_DWORD *)v4 + 5) = 1065353216;
  this->LimiterMemMapPtr->XMemory[4] = 762.0;
  return 1i64;
}

// File Line: 780
// RVA: 0xAFE850
LimiterStereoMemoryMap *__fastcall LimiterDSPStereoMemoryMapHelper::GetMemoryMap(LimiterDSPStereoMemoryMapHelper *this)
{
  return this->LimiterMemMapPtr;
}

// File Line: 787
// RVA: 0xAFE8F0
void __fastcall LimiterDSPStereoMemoryMapHelper::SetCeiling(
        LimiterDSPStereoMemoryMapHelper *this,
        long double ceiling,
        double threshold)
{
  double v4; // xmm0_8
  LimiterStereoMemoryMap *LimiterMemMapPtr; // rax
  float v6; // xmm1_4

  if ( threshold < 0.0 )
    ceiling = ceiling + -0.01;
  v4 = pow(10.0, ceiling * 0.05);
  LimiterMemMapPtr = this->LimiterMemMapPtr;
  v6 = v4;
  LimiterMemMapPtr->XMemory[21] = v6;
  LimiterMemMapPtr->XMemory[17] = v6;
}

// File Line: 803
// RVA: 0xAFE940
void __fastcall LimiterDSPStereoMemoryMapHelper::SetThreshold(
        LimiterDSPStereoMemoryMapHelper *this,
        double threshold,
        long double knee,
        long double ceiling)
{
  double v5; // xmm0_8
  LimiterStereoMemoryMap *LimiterMemMapPtr; // rax
  float v7; // xmm1_4

  if ( threshold < 0.0 )
    ceiling = ceiling - 0.01;
  v5 = pow(10.0, ceiling * 0.05);
  LimiterMemMapPtr = this->LimiterMemMapPtr;
  v7 = v5;
  LimiterMemMapPtr->XMemory[21] = v7;
  LimiterMemMapPtr->XMemory[17] = v7;
}

// File Line: 813
// RVA: 0xAFE9A0
void __fastcall LimiterDSPStereoMemoryMapHelper::SetKnee(
        LimiterDSPStereoMemoryMapHelper *this,
        long double knee,
        long double threshold)
{
  ;
}

// File Line: 823
// RVA: 0xAFE880
void __fastcall LimiterDSPStereoMemoryMapHelper::GenerateExpTable(
        LimiterDSPStereoMemoryMapHelper *this,
        long double knee,
        long double threshold)
{
  LimiterUtilities::GenerateExpTable(&this->LimiterMemMapPtr->YMemory[11], 600, threshold, knee);
}

// File Line: 831
// RVA: 0xAFE9B0
void __fastcall LimiterDSPStereoMemoryMapHelper::SetRelease(
        LimiterDSPStereoMemoryMapHelper *this,
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
  this->LimiterMemMapPtr->XMemory[8] = v7;
}

// File Line: 856
// RVA: 0xAFEA80
void __fastcall LimiterDSPStereoMemoryMapHelper::SetCharacter(
        LimiterDSPStereoMemoryMapHelper *this,
        LimiterCharacterType character,
        long double release)
{
  long double v4; // xmm1_8
  double v5; // xmm6_8
  double v6; // xmm7_8
  double v7; // xmm8_8
  float v8; // xmm2_4
  float v9; // xmm1_4
  double releasea; // [rsp+60h] [rbp+8h]

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
      v4 = releasea;
      v5 = releasea;
      v6 = releasea;
      break;
  }
  v7 = release - v6;
  v8 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v4);
  this->LimiterMemMapPtr->XMemory[11] = v8;
  if ( v7 < 0.0 )
    v7 = 0.0;
  v9 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v5 + v7);
  this->LimiterMemMapPtr->XMemory[10] = v9;
}

// File Line: 889
// RVA: 0xAFEBF0
void __fastcall LimiterDSPStereoMemoryMapHelper::SetAttack(LimiterDSPStereoMemoryMapHelper *this)
{
  int LookAheadDelayLength; // eax
  float TCScalar; // xmm1_4

  LookAheadDelayLength = LimiterUtilities::GetLookAheadDelayLength(
                           &this->mLimiterUtilities,
                           (double)(int)this->mSampleRate);
  TCScalar = GetTCScalar((double)LookAheadDelayLength);
  this->LimiterMemMapPtr->XMemory[9] = TCScalar;
}

// File Line: 901
// RVA: 0xAFEC40
void __fastcall LimiterDSPStereoMemoryMapHelper::SetHold(LimiterDSPStereoMemoryMapHelper *this)
{
  this->LimiterMemMapPtr->XMemory[7] = (float)(LimiterUtilities::GetTotalLookAheadDelayLength(
                                                 &this->mLimiterUtilities,
                                                 (double)(int)this->mSampleRate)
                                             + 1);
}

// File Line: 915
// RVA: 0xAFEC80
void __fastcall LimiterDSPStereoMemoryMapHelper::SetLookAhead(LimiterDSPStereoMemoryMapHelper *this)
{
  int FIRLength; // eax
  float *v3; // rdi
  __int64 v4; // rcx
  float v5; // eax

  this->LimiterMemMapPtr->XMemory[3] = 611.0;
  this->LimiterMemMapPtr->XMemory[2] = (float)LimiterUtilities::GetTotalLookAheadDelayLength(
                                                &this->mLimiterUtilities,
                                                (double)(int)this->mSampleRate);
  this->LimiterMemMapPtr->XMemory[12] = 913.0;
  this->LimiterMemMapPtr->XMemory[13] = (float)LimiterUtilities::GetFIRLength(
                                                 &this->mLimiterUtilities,
                                                 (double)(int)this->mSampleRate);
  FIRLength = LimiterUtilities::GetFIRLength(&this->mLimiterUtilities, (double)(int)this->mSampleRate);
  v3 = &this->LimiterMemMapPtr->XMemory[913];
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

// File Line: 940
// RVA: 0xAFE860
int __fastcall LimiterDSPStereoMemoryMapHelper::GetTotalLookAheadDelayLength(
        LimiterDSPStereoMemoryMapHelper *this,
        unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(&this->mLimiterUtilities, (double)(int)this->mSampleRate);
}

// File Line: 947
// RVA: 0xAFE8A0
void __fastcall LimiterDSPStereoMemoryMapHelper::FillMeteringData(
        LimiterDSPStereoMemoryMapHelper *this,
        char *pMeteringData)
{
  LimiterStereoMemoryMap *LimiterMemMapPtr; // r8

  LimiterMemMapPtr = this->LimiterMemMapPtr;
  *(_DWORD *)pMeteringData = 3;
  *((_DWORD *)pMeteringData + 1) = LODWORD(LimiterMemMapPtr->XMemory[15]);
  *((float *)pMeteringData + 2) = LimiterMemMapPtr->XMemory[16] * 3.9810717;
  *((float *)pMeteringData + 3) = LimiterMemMapPtr->XMemory[20] * 3.9810717;
  *((_DWORD *)pMeteringData + 4) = LODWORD(LimiterMemMapPtr->XMemory[19]);
  *((_DWORD *)pMeteringData + 5) = LODWORD(LimiterMemMapPtr->XMemory[23]);
}

// File Line: 958
// RVA: 0xAFE3C0
void __fastcall LimiterProcessStereoFloatImpl::LimiterProcessStereoFloatImpl(LimiterProcessStereoFloatImpl *this)
{
  this->mMemoryMapHelper = 0i64;
}

// File Line: 964
// RVA: 0xAFE3E0
void __fastcall LimiterProcessStereoFloatImpl::~LimiterProcessStereoFloatImpl(LimiterProcessStereoFloatImpl *this)
{
  ;
}

// File Line: 970
// RVA: 0xAFE3F0
unsigned __int64 __fastcall LimiterProcessStereoFloatImpl::GetMemoryMapSize(LimiterProcessStereoFloatImpl *this)
{
  return 7696i64;
}

// File Line: 980
// RVA: 0xAFE400
__int64 __fastcall LimiterProcessStereoFloatImpl::Init(
        LimiterProcessStereoFloatImpl *this,
        PooledMemoryAllocator *memoryMapAllocator,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int sampleRate)
{
  DSPMemoryMapHelper *v7; // rax
  LimiterDSPStereoMemoryMapHelper *v8; // rbx
  char *v9; // rax

  v7 = (DSPMemoryMapHelper *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24i64);
  v8 = (LimiterDSPStereoMemoryMapHelper *)v7;
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
  v8->mNumChannels = 2;
  v8->mSampleRate = sampleRate;
  v9 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x1E10ui64);
  v8->LimiterMemMapPtr = (LimiterStereoMemoryMap *)v9;
  if ( !v9 )
    return 52i64;
  *((_DWORD *)v9 + 5) = 1065353216;
  v8->LimiterMemMapPtr->XMemory[4] = 762.0;
  return 1i64;
}

// File Line: 991
// RVA: 0xAFE4C0
void __fastcall LimiterProcessStereoFloatImpl::Term(
        LimiterProcessStereoFloatImpl *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  LimiterDSPStereoMemoryMapHelper *mMemoryMapHelper; // rdi

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

// File Line: 999
// RVA: 0xAFE530
void __fastcall LimiterProcessStereoFloatImpl::SetParameters(
        LimiterProcessStereoFloatImpl *this,
        LimiterParameters *limiterParams)
{
  long double v4; // xmm6_8
  double ceiling; // xmm1_8
  LimiterDSPStereoMemoryMapHelper *mMemoryMapHelper; // rbx
  double v7; // xmm0_8
  LimiterStereoMemoryMap *LimiterMemMapPtr; // rax
  float v9; // xmm1_4
  double v10; // xmm1_8
  double v11; // xmm0_8
  float *XMemory; // rax
  float v13; // xmm1_4
  LimiterDSPStereoMemoryMapHelper *v14; // rbx
  int LookAheadDelayLength; // eax
  long double TCScalar; // xmm0_8
  LimiterDSPStereoMemoryMapHelper *v17; // rcx
  float v18; // xmm1_4
  LimiterDSPStereoMemoryMapHelper *v19; // rbx
  int TotalLookAheadDelayLength; // eax
  LimiterDSPStereoMemoryMapHelper *v21; // rcx

  v4 = limiterParams->threshold - 12.0;
  if ( v4 < -36.0 )
    v4 = DOUBLE_N36_0;
  ceiling = limiterParams->ceiling;
  mMemoryMapHelper = this->mMemoryMapHelper;
  if ( v4 < 0.0 )
    ceiling = ceiling + -0.01;
  v7 = pow(10.0, ceiling * 0.05);
  LimiterMemMapPtr = mMemoryMapHelper->LimiterMemMapPtr;
  v9 = v7;
  LimiterMemMapPtr->XMemory[21] = v9;
  LimiterMemMapPtr->XMemory[17] = v9;
  v10 = limiterParams->ceiling;
  if ( v4 < 0.0 )
    v10 = v10 + -0.01;
  v11 = pow(10.0, v10 * 0.05);
  XMemory = mMemoryMapHelper->LimiterMemMapPtr->XMemory;
  v13 = v11;
  XMemory[21] = v13;
  XMemory[17] = v13;
  LimiterUtilities::GenerateExpTable(XMemory + 973, 600, v4, limiterParams->knee);
  v14 = this->mMemoryMapHelper;
  LookAheadDelayLength = LimiterUtilities::GetLookAheadDelayLength(
                           &this->mMemoryMapHelper->mLimiterUtilities,
                           (double)this->mMemoryMapHelper->mSampleRate);
  TCScalar = GetTCScalar((double)LookAheadDelayLength);
  v17 = this->mMemoryMapHelper;
  v18 = TCScalar;
  v14->LimiterMemMapPtr->XMemory[9] = v18;
  LimiterDSPStereoMemoryMapHelper::SetRelease(v17, limiterParams->release, limiterParams->character);
  LimiterDSPStereoMemoryMapHelper::SetCharacter(
    this->mMemoryMapHelper,
    limiterParams->character,
    limiterParams->release);
  v19 = this->mMemoryMapHelper;
  TotalLookAheadDelayLength = LimiterUtilities::GetTotalLookAheadDelayLength(
                                &this->mMemoryMapHelper->mLimiterUtilities,
                                (double)this->mMemoryMapHelper->mSampleRate);
  v21 = this->mMemoryMapHelper;
  v19->LimiterMemMapPtr->XMemory[7] = (float)(TotalLookAheadDelayLength + 1);
  LimiterDSPStereoMemoryMapHelper::SetLookAhead(v21);
}

// File Line: 1040
// RVA: 0xAFE6B0
void __fastcall LimiterProcessStereoFloatImpl::ProcessAudio(
        LimiterProcessStereoFloatImpl *this,
        float *memoryMap,
        AkAudioBuffer *inputBuffer,
        AkAudioBuffer *outputBuffer)
{
  McDSPLimiterProcessChannels(
    memoryMap,
    (const float *)inputBuffer->pData,
    (const float *)inputBuffer->pData + inputBuffer->uMaxFrames,
    (float *)outputBuffer->pData,
    (float *)outputBuffer->pData + outputBuffer->uMaxFrames,
    inputBuffer->uValidFrames);
}

// File Line: 1054
// RVA: 0xAFE700
int __fastcall LimiterProcessStereoFloatImpl::GetNumTailFrames(
        LimiterProcessStereoFloatImpl *this,
        unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(
           &this->mMemoryMapHelper->mLimiterUtilities,
           (double)this->mMemoryMapHelper->mSampleRate);
}

// File Line: 1059
// RVA: 0xAFE720
void __fastcall LimiterProcessStereoFloatImpl::FillMeteringData(
        LimiterProcessStereoFloatImpl *this,
        char *pMeteringData)
{
  LimiterStereoMemoryMap *LimiterMemMapPtr; // rcx

  LimiterMemMapPtr = this->mMemoryMapHelper->LimiterMemMapPtr;
  *(_DWORD *)pMeteringData = 3;
  *((_DWORD *)pMeteringData + 1) = LODWORD(LimiterMemMapPtr->XMemory[15]);
  *((float *)pMeteringData + 2) = LimiterMemMapPtr->XMemory[16] * 3.9810717;
  *((float *)pMeteringData + 3) = LimiterMemMapPtr->XMemory[20] * 3.9810717;
  *((_DWORD *)pMeteringData + 4) = LODWORD(LimiterMemMapPtr->XMemory[19]);
  *((_DWORD *)pMeteringData + 5) = LODWORD(LimiterMemMapPtr->XMemory[23]);
}

