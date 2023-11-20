// File Line: 134
// RVA: 0xAFDBE0
void __fastcall McDSPLimiterProcessChannels(void *memoryMap, const float *inputBufLeft, const float *inputBufRight, float *outputBufLeft, float *outputBufRight, unsigned int samplesRemaining)
{
  signed int v6; // edi
  int v7; // esi
  float *v8; // rbx
  const float *v9; // r14
  float *v10; // r8
  const float *v11; // r10
  signed int v12; // edx
  signed int v13; // er11
  signed __int64 v14; // r15
  signed int v15; // er12
  signed int v16; // er9
  signed int v17; // er13
  unsigned int v18; // ecx
  signed __int64 v19; // r10
  signed __int64 v20; // rdx
  float v21; // xmm10_4
  float *v22; // rbp
  float v23; // xmm2_4
  float v24; // xmm4_4
  int v25; // ecx
  signed __int64 v26; // r8
  signed __int64 v27; // rax
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm6_4
  int v32; // xmm2_4
  int v33; // er10
  char *v34; // rcx
  unsigned int v35; // eax
  __int64 v36; // r9
  __int64 v37; // r9
  float v38; // xmm5_4
  float v39; // xmm4_4
  float v40; // xmm4_4
  float v41; // xmm4_4
  float v42; // xmm5_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm4_4
  int v46; // xmm0_4
  int v47; // xmm5_4
  float v48; // xmm1_4
  int v49; // xmm4_4
  int v50; // xmm0_4
  float v51; // xmm5_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  signed __int64 v55; // rax
  signed __int64 v56; // rcx
  signed __int64 v57; // r9
  float v58; // xmm4_4
  __int64 v59; // rax
  float v60; // xmm5_4
  int v61; // er10
  float v62; // xmm1_4
  signed __int64 v63; // rax
  signed __int64 v64; // rcx
  unsigned int v65; // eax
  __int64 v66; // r9
  float v67; // xmm4_4
  signed __int64 v68; // rcx
  __int64 v69; // r9
  float v70; // xmm2_4
  float v71; // xmm4_4
  float v72; // xmm5_4
  int v73; // xmm4_4
  float v74; // xmm2_4
  float v75; // xmm4_4
  float v76; // xmm2_4
  int v77; // xmm4_4
  float v78; // xmm2_4
  float v79; // xmm4_4
  float v80; // xmm2_4
  signed int v81; // [rsp+0h] [rbp-E8h]
  signed int v82; // [rsp+4h] [rbp-E4h]
  signed __int64 v83; // [rsp+8h] [rbp-E0h]
  __int64 v84; // [rsp+10h] [rbp-D8h]
  __int64 v85; // [rsp+18h] [rbp-D0h]
  __int64 v86; // [rsp+20h] [rbp-C8h]
  int v87; // [rsp+F0h] [rbp+8h]
  signed __int64 v88; // [rsp+F8h] [rbp+10h]
  float *v89; // [rsp+108h] [rbp+20h]
  unsigned int samplesRemaininga; // [rsp+118h] [rbp+30h]

  v89 = outputBufLeft;
  v6 = (signed int)*((float *)memoryMap + 968);
  v7 = (signed int)*((float *)memoryMap + 2);
  v8 = (float *)memoryMap;
  v9 = inputBufRight;
  v10 = (float *)((char *)memoryMap + 3856);
  v11 = inputBufLeft;
  v84 = (signed int)*((float *)memoryMap + 3);
  v12 = (signed int)*((float *)memoryMap + 4);
  v13 = (signed int)*((float *)memoryMap + 964);
  v82 = (signed int)*((float *)memoryMap + 7);
  *(_QWORD *)((char *)memoryMap + 60) = 0i64;
  *(_QWORD *)((char *)memoryMap + 76) = 0i64;
  *((_DWORD *)memoryMap + 23) = 0;
  v85 = v12;
  v81 = v12;
  v14 = v13;
  v15 = (signed int)*((float *)memoryMap + 14);
  v16 = (signed int)*((float *)memoryMap + 12);
  v17 = (signed int)*((float *)memoryMap + 13);
  v83 = v15;
  v18 = samplesRemaining;
  v86 = v16;
  if ( samplesRemaining )
  {
    v19 = (char *)v11 - (char *)v9;
    v20 = v16 + 1;
    v88 = v19;
    v21 = kHeadRoomScaleFactor_0;
    do
    {
      v22 = v10;
      ++v9;
      samplesRemaininga = v18 - 1;
      v23 = v21 * *(const float *)((char *)v9 + v19 - 4);
      v24 = v21 * *(v9 - 1);
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
      v87 = v25;
      v27 = v14 + v84;
      v28 = v8[v14 + v84];
      v8[v27] = v23;
      v29 = v8[v14 + 962 + v84];
      v30 = v8[v14 + 962 + v84];
      v8[v27 + 962] = v24;
      v22[1] = v28;
      v22[2] = v29;
      if ( COERCE_FLOAT(LODWORD(v28) & _xmm) > COERCE_FLOAT(LODWORD(v30) & _xmm) )
        v29 = v28;
      v22[3] = v29;
      LODWORD(v31) = LODWORD(v23) & _xmm;
      if ( COERCE_FLOAT(LODWORD(v24) & _xmm) > COERCE_FLOAT(LODWORD(v23) & _xmm) )
        v23 = v24;
      v8[v14 + 962 + v85] = v23;
      v32 = 0;
      v33 = 0;
      v34 = (char *)&v8[v81 + 962i64];
      if ( v7 >= 4 )
      {
        v35 = ((unsigned int)(v7 - 4) >> 2) + 1;
        v36 = v35;
        v33 = 4 * v35;
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v34 & _xmm) > COERCE_FLOAT(v32 & _xmm) )
            v32 = *(_DWORD *)v34;
          if ( COERCE_FLOAT(*((_DWORD *)v34 + 1) & _xmm) > COERCE_FLOAT(v32 & _xmm) )
            v32 = *((_DWORD *)v34 + 1);
          if ( COERCE_FLOAT(*((_DWORD *)v34 + 2) & _xmm) > COERCE_FLOAT(v32 & _xmm) )
            v32 = *((_DWORD *)v34 + 2);
          if ( COERCE_FLOAT(*((_DWORD *)v34 + 3) & _xmm) > COERCE_FLOAT(v32 & _xmm) )
            v32 = *((_DWORD *)v34 + 3);
          v34 += 16;
          --v36;
        }
        while ( v36 );
      }
      if ( v33 < v7 )
      {
        v37 = (unsigned int)(v7 - v33);
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v34 & _xmm) > COERCE_FLOAT(v32 & _xmm) )
            v32 = *(_DWORD *)v34;
          v34 += 4;
          --v37;
        }
        while ( v37 );
      }
      v38 = v8[6];
      if ( COERCE_FLOAT(LODWORD(v24) & _xmm) > v31 )
        LODWORD(v31) = LODWORD(v24) & _xmm;
      if ( v31 >= 1.0 )
        v31 = *(float *)&FLOAT_1_0;
      if ( COERCE_FLOAT((_DWORD)v8[5] & _xmm) <= COERCE_FLOAT(LODWORD(v31) & _xmm) )
        v31 = v8[5];
      v39 = v22[5];
      if ( COERCE_FLOAT(LODWORD(v31) & _xmm) > COERCE_FLOAT((_DWORD)v22[5] & _xmm) )
      {
        v6 = v82;
        v39 = v31;
      }
      LODWORD(v40) = LODWORD(v39) & _xmm;
      v22[5] = v40;
      v41 = v40 - v38;
      if ( COERCE_FLOAT((_DWORD)v22[6] & _xmm) > COERCE_FLOAT(LODWORD(v41) & _xmm) )
        v41 = v22[6];
      --v6;
      v22[6] = v41;
      if ( v6 < 0 )
        v6 = 0;
      v42 = 0.0;
      v43 = v8[9];
      if ( v6 <= 0 )
      {
        v42 = v8[8];
        v43 = 0.0;
      }
      LODWORD(v44) = v32 & _xmm;
      v45 = (float)((float)(v41 * v43) + v8[6]) + (float)((float)(v44 - v8[6]) * v42);
      if ( COERCE_FLOAT((_DWORD)v22[5] & _xmm) <= COERCE_FLOAT(LODWORD(v45) & _xmm) )
        v45 = v22[5];
      v46 = *((_DWORD *)v22 + 6);
      if ( v6 <= 0 )
        v46 = 0;
      *((_DWORD *)v22 + 6) = v46;
      v47 = *((_DWORD *)v22 + 3);
      LODWORD(v48) = (_DWORD)v22[3] & _xmm;
      if ( v48 > COERCE_FLOAT(LODWORD(v45) & _xmm) )
        v45 = v22[3];
      v49 = LODWORD(v45) & _xmm;
      *((_DWORD *)v8 + 6) = v49;
      v50 = *((_DWORD *)v22 + 5);
      if ( v48 > COERCE_FLOAT(v49 & _xmm) )
        v50 = v47;
      *((_DWORD *)v22 + 5) = v50 & _xmm;
      v51 = v8[10];
      if ( COERCE_FLOAT((_DWORD)v22[7] & _xmm) < COERCE_FLOAT(LODWORD(v44) & _xmm) )
        v51 = v8[11];
      v52 = v8[6];
      v53 = (float)((float)(v44 - v22[7]) * v51) + v22[7];
      v22[7] = v53;
      if ( v52 > v53 )
        v53 = v52;
      v8[6] = v53;
      v54 = v22[5];
      if ( v6 <= 0 )
        v54 = v53;
      v55 = v83;
      ++v15;
      v56 = v83 + 1;
      v22[5] = v54;
      v57 = v83;
      if ( v83 + 1 >= v17 )
      {
        v15 = 0;
        v56 = 0i64;
      }
      v83 = v56;
      v58 = 0.0;
      v59 = v86 + v55;
      v8[v59 + 962] = v53;
      v60 = v8[v86];
      v61 = 0;
      v62 = v8[v59 - v57 + 962];
      v63 = v20;
      if ( v17 >= 4 )
      {
        v64 = (signed __int64)&v8[v20 + 964];
        v65 = ((unsigned int)(v17 - 4) >> 2) + 1;
        v66 = v65;
        v61 = 4 * v65;
        v63 = v20 + 4i64 * v65;
        do
        {
          v64 += 16i64;
          v67 = (float)((float)((float)(v62 * v60) + v58) + (float)(v60 * *(float *)(v64 - 24)))
              + (float)(v60 * *(float *)(v64 - 20));
          v62 = *(float *)(v64 - 12);
          v58 = v67 + (float)(v60 * *(float *)(v64 - 16));
          --v66;
        }
        while ( v66 );
      }
      if ( v61 < v17 )
      {
        v68 = (signed __int64)&v8[v63 + 962];
        v69 = (unsigned int)(v17 - v61);
        do
        {
          v68 += 4i64;
          v58 = v58 + (float)(v62 * v60);
          v62 = *(float *)(v68 - 4);
          --v69;
        }
        while ( v69 );
      }
      v70 = (float)((float)((float)((float)(v58 * 2.0) - (float)(v58 * v58)) * 2.0)
                  - (float)((float)((float)(v58 * 2.0) - (float)(v58 * v58))
                          * (float)((float)(v58 * 2.0) - (float)(v58 * v58))))
          * 599.0;
      v71 = (float)((float)(v22[(signed int)v70 + 10] - v22[(signed int)v70 + 9]) * (float)(v70 - (float)(signed int)v70))
          + v22[(signed int)v70 + 9];
      v72 = (float)((float)(v22[(signed int)v70 + 10] - v22[(signed int)v70 + 9]) * (float)(v70 - (float)(signed int)v70))
          + v22[(signed int)v70 + 9];
      if ( COERCE_FLOAT((_DWORD)v8[15] & _xmm) > COERCE_FLOAT(LODWORD(v71) & _xmm) )
        v71 = v8[15];
      v8[15] = v71;
      v73 = *((_DWORD *)v8 + 16);
      v74 = v22[1];
      if ( COERCE_FLOAT((_DWORD)v22[1] & _xmm) > COERCE_FLOAT((_DWORD)v8[16] & _xmm) )
        v73 = *((_DWORD *)v22 + 1);
      *((_DWORD *)v8 + 16) = v73;
      v75 = v8[19];
      v76 = (float)(v74 * v72) * v8[17];
      if ( COERCE_FLOAT(LODWORD(v76) & _xmm) > COERCE_FLOAT((_DWORD)v8[19] & _xmm) )
        v75 = v76;
      v8[19] = v75;
      ++v89;
      *(v89 - 1) = v76;
      v77 = *((_DWORD *)v8 + 20);
      v78 = v22[2];
      if ( COERCE_FLOAT((_DWORD)v22[2] & _xmm) > COERCE_FLOAT((_DWORD)v8[20] & _xmm) )
        v77 = *((_DWORD *)v22 + 2);
      *((_DWORD *)v8 + 20) = v77;
      v79 = v8[23];
      v80 = (float)(v78 * v72) * v8[21];
      if ( COERCE_FLOAT(LODWORD(v80) & _xmm) > COERCE_FLOAT((_DWORD)v8[23] & _xmm) )
        v79 = v80;
      v18 = samplesRemaininga;
      v13 = v87;
      v8[23] = v79;
      v14 = v26;
      v19 = v88;
      *outputBufRight = v80;
      v10 = v8 + 964;
      ++outputBufRight;
    }
    while ( samplesRemaininga );
    v10 = v8 + 964;
  }
  v8[968] = (float)v6;
  *v10 = (float)v13;
  v8[14] = (float)v15;
}

// File Line: 661
// RVA: 0xAFE2F0
void __fastcall McDSPFillVUMetersDataStereo(void *memoryMap, char *pMeteringData)
{
  *(_DWORD *)pMeteringData = 3;
  *((_DWORD *)pMeteringData + 1) = *((_DWORD *)memoryMap + 15);
  *((float *)pMeteringData + 2) = *((float *)memoryMap + 16) * 3.9810717;
  *((float *)pMeteringData + 3) = *((float *)memoryMap + 20) * 3.9810717;
  *((_DWORD *)pMeteringData + 4) = *((_DWORD *)memoryMap + 19);
  *((_DWORD *)pMeteringData + 5) = *((_DWORD *)memoryMap + 23);
}

// File Line: 736
// RVA: 0xAFE770
void __fastcall LimiterDSPStereoMemoryMapHelper::LimiterDSPStereoMemoryMapHelper(LimiterDSPStereoMemoryMapHelper *this, int sampleRate)
{
  LimiterDSPStereoMemoryMapHelper *v2; // rbx

  v2 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->0);
  LimiterUtilities::LimiterUtilities(&v2->mLimiterUtilities, 0.00085000001, 0.000325);
}

// File Line: 742
// RVA: 0xAFE7B0
void __fastcall LimiterDSPStereoMemoryMapHelper::~LimiterDSPStereoMemoryMapHelper(LimiterDSPStereoMemoryMapHelper *this)
{
  LimiterDSPStereoMemoryMapHelper *v1; // rbx

  v1 = this;
  LimiterUtilities::~LimiterUtilities(&this->mLimiterUtilities);
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&v1->0);
}

// File Line: 748
// RVA: 0xAFE7E0
unsigned __int64 __fastcall LimiterDSPStereoMemoryMapHelper::GetMemoryMapSize(LimiterDSPStereoMemoryMapHelper *this)
{
  return 7696i64;
}

// File Line: 756
// RVA: 0xAFE7F0
signed __int64 __fastcall LimiterDSPStereoMemoryMapHelper::Init(LimiterDSPStereoMemoryMapHelper *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int sampleRate)
{
  LimiterDSPStereoMemoryMapHelper *v3; // rbx
  char *v4; // rax

  v3 = this;
  this->mNumChannels = 2;
  this->mSampleRate = sampleRate;
  v4 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x1E10ui64);
  v3->LimiterMemMapPtr = (LimiterStereoMemoryMap *)v4;
  if ( !v4 )
    return 52i64;
  *((_DWORD *)v4 + 5) = 1065353216;
  v3->LimiterMemMapPtr->XMemory[4] = 762.0;
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
void __fastcall LimiterDSPStereoMemoryMapHelper::SetCeiling(LimiterDSPStereoMemoryMapHelper *this, long double ceiling, long double threshold)
{
  LimiterDSPStereoMemoryMapHelper *v3; // rbx
  double v4; // xmm0_8
  LimiterStereoMemoryMap *v5; // rax
  float v6; // xmm1_4

  v3 = this;
  if ( threshold < 0.0 )
    ceiling = ceiling + -0.01;
  v4 = pow(10.0, ceiling * 0.05);
  v5 = v3->LimiterMemMapPtr;
  v6 = v4;
  v5->XMemory[21] = v6;
  v5->XMemory[17] = v6;
}

// File Line: 803
// RVA: 0xAFE940
void __fastcall LimiterDSPStereoMemoryMapHelper::SetThreshold(LimiterDSPStereoMemoryMapHelper *this, long double threshold, long double knee, long double ceiling)
{
  LimiterDSPStereoMemoryMapHelper *v4; // rbx
  double v5; // xmm0_8
  LimiterStereoMemoryMap *v6; // rax
  float v7; // xmm1_4

  v4 = this;
  if ( threshold < 0.0 )
    ceiling = ceiling - 0.01;
  v5 = pow(10.0, ceiling * 0.05);
  v6 = v4->LimiterMemMapPtr;
  v7 = v5;
  v6->XMemory[21] = v7;
  v6->XMemory[17] = v7;
}

// File Line: 813
// RVA: 0xAFE9A0
void __fastcall LimiterDSPStereoMemoryMapHelper::SetKnee(LimiterDSPStereoMemoryMapHelper *this, long double knee, long double threshold)
{
  ;
}

// File Line: 823
// RVA: 0xAFE880
void __fastcall LimiterDSPStereoMemoryMapHelper::GenerateExpTable(LimiterDSPStereoMemoryMapHelper *this, long double knee, long double threshold)
{
  LimiterUtilities::GenerateExpTable(&this->LimiterMemMapPtr->YMemory[11], 600, threshold, knee);
}

// File Line: 831
// RVA: 0xAFE9B0
void __fastcall LimiterDSPStereoMemoryMapHelper::SetRelease(LimiterDSPStereoMemoryMapHelper *this, long double release, LimiterCharacterType character)
{
  double v3; // xmm2_8
  LimiterDSPStereoMemoryMapHelper *v4; // rbx
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
  v4->LimiterMemMapPtr->XMemory[8] = v7;
}

// File Line: 856
// RVA: 0xAFEA80
void __fastcall LimiterDSPStereoMemoryMapHelper::SetCharacter(LimiterDSPStereoMemoryMapHelper *this, LimiterCharacterType character, long double release)
{
  LimiterDSPStereoMemoryMapHelper *v3; // rbx
  long double v4; // xmm1_8
  double v5; // xmm6_8
  double v6; // xmm7_8
  double v7; // xmm8_8
  float v8; // xmm2_4
  float v9; // xmm1_4
  double releasea; // [rsp+60h] [rbp+8h]

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
      v4 = releasea;
      v5 = releasea;
      v6 = releasea;
      break;
  }
  v7 = release - v6;
  v8 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v4);
  v3->LimiterMemMapPtr->XMemory[11] = v8;
  if ( v7 < 0.0 )
    v7 = 0.0;
  v9 = DynamicsCalculator::CalculateReleaseScalar(v3->mSampleRate, v5 + v7);
  v3->LimiterMemMapPtr->XMemory[10] = v9;
}

// File Line: 889
// RVA: 0xAFEBF0
void __fastcall LimiterDSPStereoMemoryMapHelper::SetAttack(LimiterDSPStereoMemoryMapHelper *this)
{
  LimiterDSPStereoMemoryMapHelper *v1; // rbx
  signed int v2; // eax
  float v3; // xmm1_4

  v1 = this;
  v2 = LimiterUtilities::GetLookAheadDelayLength(&this->mLimiterUtilities, (double)(signed int)this->mSampleRate);
  v3 = GetTCScalar((double)v2);
  v1->LimiterMemMapPtr->XMemory[9] = v3;
}

// File Line: 901
// RVA: 0xAFEC40
void __fastcall LimiterDSPStereoMemoryMapHelper::SetHold(LimiterDSPStereoMemoryMapHelper *this)
{
  this->LimiterMemMapPtr->XMemory[7] = (float)(LimiterUtilities::GetTotalLookAheadDelayLength(
                                                 &this->mLimiterUtilities,
                                                 (double)(signed int)this->mSampleRate)
                                             + 1);
}

// File Line: 915
// RVA: 0xAFEC80
void __fastcall LimiterDSPStereoMemoryMapHelper::SetLookAhead(LimiterDSPStereoMemoryMapHelper *this)
{
  LimiterDSPStereoMemoryMapHelper *v1; // rbx
  signed int v2; // eax
  float *v3; // rdi
  __int64 v4; // rcx
  float v5; // eax

  v1 = this;
  this->LimiterMemMapPtr->XMemory[3] = 611.0;
  this->LimiterMemMapPtr->XMemory[2] = (float)LimiterUtilities::GetTotalLookAheadDelayLength(
                                                &this->mLimiterUtilities,
                                                (double)(signed int)this->mSampleRate);
  v1->LimiterMemMapPtr->XMemory[12] = 913.0;
  v1->LimiterMemMapPtr->XMemory[13] = (float)LimiterUtilities::GetFIRLength(
                                               &v1->mLimiterUtilities,
                                               (double)(signed int)v1->mSampleRate);
  v2 = LimiterUtilities::GetFIRLength(&v1->mLimiterUtilities, (double)(signed int)v1->mSampleRate);
  v3 = &v1->LimiterMemMapPtr->XMemory[913];
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

// File Line: 940
// RVA: 0xAFE860
int __fastcall LimiterDSPStereoMemoryMapHelper::GetTotalLookAheadDelayLength(LimiterDSPStereoMemoryMapHelper *this, unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(&this->mLimiterUtilities, (double)(signed int)this->mSampleRate);
}

// File Line: 947
// RVA: 0xAFE8A0
void __fastcall LimiterDSPStereoMemoryMapHelper::FillMeteringData(LimiterDSPStereoMemoryMapHelper *this, char *pMeteringData)
{
  LimiterStereoMemoryMap *v2; // r8

  v2 = this->LimiterMemMapPtr;
  *(_DWORD *)pMeteringData = 3;
  *((_DWORD *)pMeteringData + 1) = LODWORD(v2->XMemory[15]);
  *((float *)pMeteringData + 2) = v2->XMemory[16] * 3.9810717;
  *((float *)pMeteringData + 3) = v2->XMemory[20] * 3.9810717;
  *((_DWORD *)pMeteringData + 4) = LODWORD(v2->XMemory[19]);
  *((_DWORD *)pMeteringData + 5) = LODWORD(v2->XMemory[23]);
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
signed __int64 __fastcall LimiterProcessStereoFloatImpl::Init(LimiterProcessStereoFloatImpl *this, PooledMemoryAllocator *memoryMapAllocator, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int sampleRate)
{
  PooledMemoryAllocator *v4; // rbp
  LimiterProcessStereoFloatImpl *v5; // rdi
  unsigned int v6; // esi
  DSPMemoryMapHelper *v7; // rax
  LimiterDSPStereoMemoryMapHelper *v8; // rbx
  char *v9; // rax

  v4 = memoryMapAllocator;
  v5 = this;
  v6 = sampleRate;
  v7 = (DSPMemoryMapHelper *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24ui64);
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
  v5->mMemoryMapHelper = v8;
  if ( !v8 )
    return 52i64;
  v8->mNumChannels = 2;
  v8->mSampleRate = v6;
  v9 = PooledMemoryAllocator::Malloc(v4, 0x1E10ui64);
  v8->LimiterMemMapPtr = (LimiterStereoMemoryMap *)v9;
  if ( !v9 )
    return 52i64;
  *((_DWORD *)v9 + 5) = 1065353216;
  v8->LimiterMemMapPtr->XMemory[4] = 762.0;
  return 1i64;
}

// File Line: 991
// RVA: 0xAFE4C0
void __fastcall LimiterProcessStereoFloatImpl::Term(LimiterProcessStereoFloatImpl *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  LimiterDSPStereoMemoryMapHelper *v2; // rdi
  AK::IAkPluginMemAlloc *v3; // rsi
  LimiterProcessStereoFloatImpl *v4; // rbx

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

// File Line: 999
// RVA: 0xAFE530
void __fastcall LimiterProcessStereoFloatImpl::SetParameters(LimiterProcessStereoFloatImpl *this, LimiterParameters *limiterParams)
{
  LimiterParameters *v2; // rdi
  LimiterProcessStereoFloatImpl *v3; // rsi
  long double v4; // xmm6_8
  double v5; // xmm1_8
  LimiterDSPStereoMemoryMapHelper *v6; // rbx
  double v7; // xmm0_8
  LimiterStereoMemoryMap *v8; // rax
  float v9; // xmm1_4
  double v10; // xmm1_8
  double v11; // xmm0_8
  float *v12; // rax
  float v13; // xmm1_4
  LimiterUtilities *v14; // rbx
  signed int v15; // eax
  long double v16; // xmm0_8
  LimiterDSPStereoMemoryMapHelper *v17; // rcx
  float v18; // xmm1_4
  LimiterDSPStereoMemoryMapHelper *v19; // rbx
  int v20; // eax
  LimiterDSPStereoMemoryMapHelper *v21; // rcx

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
  v8 = v6->LimiterMemMapPtr;
  v9 = v7;
  v8->XMemory[21] = v9;
  v8->XMemory[17] = v9;
  v10 = v2->ceiling;
  if ( v4 < 0.0 )
    v10 = v10 + -0.01;
  v11 = pow(10.0, v10 * 0.05);
  v12 = v6->LimiterMemMapPtr->XMemory;
  v13 = v11;
  v12[21] = v13;
  v12[17] = v13;
  LimiterUtilities::GenerateExpTable(v12 + 973, 600, v4, v2->knee);
  v14 = (LimiterUtilities *)v3->mMemoryMapHelper;
  v15 = LimiterUtilities::GetLookAheadDelayLength(
          &v3->mMemoryMapHelper->mLimiterUtilities,
          (double)v3->mMemoryMapHelper->mSampleRate);
  v16 = GetTCScalar((double)v15);
  v17 = v3->mMemoryMapHelper;
  v18 = v16;
  *(float *)(*(_QWORD *)&v14[1] + 36i64) = v18;
  LimiterDSPStereoMemoryMapHelper::SetRelease(v17, v2->release, v2->character);
  LimiterDSPStereoMemoryMapHelper::SetCharacter(v3->mMemoryMapHelper, v2->character, v2->release);
  v19 = v3->mMemoryMapHelper;
  v20 = LimiterUtilities::GetTotalLookAheadDelayLength(
          &v3->mMemoryMapHelper->mLimiterUtilities,
          (double)v3->mMemoryMapHelper->mSampleRate);
  v21 = v3->mMemoryMapHelper;
  v19->LimiterMemMapPtr->XMemory[7] = (float)(v20 + 1);
  LimiterDSPStereoMemoryMapHelper::SetLookAhead(v21);
}

// File Line: 1040
// RVA: 0xAFE6B0
void __fastcall LimiterProcessStereoFloatImpl::ProcessAudio(LimiterProcessStereoFloatImpl *this, void *memoryMap, AkAudioBuffer *inputBuffer, AkAudioBuffer *outputBuffer)
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
int __fastcall LimiterProcessStereoFloatImpl::GetNumTailFrames(LimiterProcessStereoFloatImpl *this, unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(
           &this->mMemoryMapHelper->mLimiterUtilities,
           (double)this->mMemoryMapHelper->mSampleRate);
}

// File Line: 1059
// RVA: 0xAFE720
void __fastcall LimiterProcessStereoFloatImpl::FillMeteringData(LimiterProcessStereoFloatImpl *this, char *pMeteringData)
{
  LimiterStereoMemoryMap *v2; // rcx

  v2 = this->mMemoryMapHelper->LimiterMemMapPtr;
  *(_DWORD *)pMeteringData = 3;
  *((_DWORD *)pMeteringData + 1) = LODWORD(v2->XMemory[15]);
  *((float *)pMeteringData + 2) = v2->XMemory[16] * 3.9810717;
  *((float *)pMeteringData + 3) = v2->XMemory[20] * 3.9810717;
  *((_DWORD *)pMeteringData + 4) = LODWORD(v2->XMemory[19]);
  *((_DWORD *)pMeteringData + 5) = LODWORD(v2->XMemory[23]);
}

