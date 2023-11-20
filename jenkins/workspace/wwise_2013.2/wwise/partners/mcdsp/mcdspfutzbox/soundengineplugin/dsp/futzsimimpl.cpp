// File Line: 162
// RVA: 0xB08E20
void __fastcall ProcessFutzSIMChannel(FutzBoxSIMMemoryMap *memoryMap, const float *inputBuf, float *outputBuf, unsigned int samplesRemaining)
{
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm10_4
  float v12; // xmm11_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  float v15; // xmm14_4
  float v16; // xmm15_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  signed __int64 v20; // rdx
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  float v48; // [rsp+0h] [rbp-178h]
  float v49; // [rsp+4h] [rbp-174h]
  float v50; // [rsp+8h] [rbp-170h]
  float v51; // [rsp+Ch] [rbp-16Ch]
  float v52; // [rsp+10h] [rbp-168h]
  float v53; // [rsp+14h] [rbp-164h]
  float v54; // [rsp+18h] [rbp-160h]
  float v55; // [rsp+1Ch] [rbp-15Ch]
  float v56; // [rsp+20h] [rbp-158h]
  float v57; // [rsp+24h] [rbp-154h]
  float v58; // [rsp+28h] [rbp-150h]
  float v59; // [rsp+2Ch] [rbp-14Ch]
  float v60; // [rsp+30h] [rbp-148h]
  float v61; // [rsp+34h] [rbp-144h]
  float v62; // [rsp+38h] [rbp-140h]
  float v63; // [rsp+3Ch] [rbp-13Ch]
  float v64; // [rsp+40h] [rbp-138h]
  float v65; // [rsp+44h] [rbp-134h]
  float v66; // [rsp+48h] [rbp-130h]
  float v67; // [rsp+4Ch] [rbp-12Ch]
  float v68; // [rsp+50h] [rbp-128h]
  float v69; // [rsp+54h] [rbp-124h]
  float v70; // [rsp+58h] [rbp-120h]
  float v71; // [rsp+5Ch] [rbp-11Ch]
  float v72; // [rsp+60h] [rbp-118h]
  float v73; // [rsp+64h] [rbp-114h]
  float v74; // [rsp+68h] [rbp-110h]
  float v75; // [rsp+6Ch] [rbp-10Ch]
  float v76; // [rsp+70h] [rbp-108h]
  float v77; // [rsp+74h] [rbp-104h]
  float v78; // [rsp+78h] [rbp-100h]
  float v79; // [rsp+7Ch] [rbp-FCh]
  float v80; // [rsp+80h] [rbp-F8h]
  float v81; // [rsp+84h] [rbp-F4h]
  float v82; // [rsp+88h] [rbp-F0h]
  float v83; // [rsp+8Ch] [rbp-ECh]
  float v84; // [rsp+90h] [rbp-E8h]
  float v85; // [rsp+94h] [rbp-E4h]
  float v86; // [rsp+98h] [rbp-E0h]
  float v87; // [rsp+9Ch] [rbp-DCh]
  float v88; // [rsp+A0h] [rbp-D8h]
  float v89; // [rsp+A4h] [rbp-D4h]
  float v90; // [rsp+A8h] [rbp-D0h]
  float v91; // [rsp+ACh] [rbp-CCh]
  float v92; // [rsp+B0h] [rbp-C8h]
  float v93; // [rsp+B4h] [rbp-C4h]
  float v94; // [rsp+B8h] [rbp-C0h]
  float v95; // [rsp+BCh] [rbp-BCh]
  float v96; // [rsp+C0h] [rbp-B8h]
  float v97; // [rsp+C4h] [rbp-B4h]
  float v98; // [rsp+C8h] [rbp-B0h]
  float v99; // [rsp+180h] [rbp+8h]
  float v100; // [rsp+198h] [rbp+20h]

  v4 = memoryMap->YMemory[5];
  v81 = memoryMap->XMemory[2];
  v5 = memoryMap->YMemory[2];
  v95 = memoryMap->XMemory[3];
  v6 = memoryMap->YMemory[4];
  v7 = memoryMap->YMemory[8];
  v8 = memoryMap->YMemory[10];
  v9 = memoryMap->YMemory[14];
  v10 = memoryMap->YMemory[16];
  v11 = memoryMap->YMemory[20];
  v12 = memoryMap->YMemory[22];
  v65 = memoryMap->XMemory[4];
  v100 = memoryMap->YMemory[3];
  v97 = memoryMap->XMemory[5];
  v50 = memoryMap->YMemory[5];
  v67 = memoryMap->XMemory[6];
  v69 = memoryMap->XMemory[7];
  v83 = memoryMap->XMemory[8];
  v91 = memoryMap->XMemory[9];
  v71 = memoryMap->XMemory[10];
  v85 = memoryMap->XMemory[11];
  v56 = memoryMap->YMemory[9];
  v52 = memoryMap->YMemory[11];
  v62 = memoryMap->XMemory[12];
  v73 = memoryMap->XMemory[13];
  v75 = memoryMap->XMemory[14];
  v87 = memoryMap->XMemory[15];
  v77 = memoryMap->XMemory[16];
  v60 = memoryMap->YMemory[15];
  v54 = memoryMap->YMemory[17];
  v79 = memoryMap->XMemory[17];
  v93 = memoryMap->XMemory[18];
  v89 = memoryMap->XMemory[19];
  v63 = memoryMap->XMemory[20];
  v64 = memoryMap->XMemory[21];
  v48 = memoryMap->YMemory[21];
  v49 = memoryMap->YMemory[23];
  v68 = memoryMap->XMemory[22];
  v66 = memoryMap->XMemory[23];
  v70 = memoryMap->XMemory[24];
  v13 = memoryMap->YMemory[26];
  v14 = memoryMap->YMemory[28];
  v15 = memoryMap->YMemory[32];
  v16 = memoryMap->YMemory[34];
  v72 = memoryMap->XMemory[25];
  v61 = memoryMap->YMemory[41];
  v74 = memoryMap->XMemory[26];
  v51 = memoryMap->YMemory[27];
  v96 = memoryMap->XMemory[38];
  v53 = memoryMap->YMemory[29];
  v78 = memoryMap->XMemory[27];
  v59 = memoryMap->YMemory[39];
  v17 = memoryMap->YMemory[40];
  v76 = memoryMap->XMemory[28];
  v80 = memoryMap->XMemory[29];
  v98 = memoryMap->XMemory[39];
  v18 = memoryMap->YMemory[3];
  v82 = memoryMap->XMemory[30];
  v84 = memoryMap->XMemory[31];
  v58 = memoryMap->YMemory[40];
  v55 = memoryMap->YMemory[33];
  v57 = memoryMap->YMemory[35];
  v88 = memoryMap->XMemory[32];
  v86 = memoryMap->XMemory[33];
  v90 = memoryMap->XMemory[34];
  v92 = memoryMap->XMemory[35];
  v94 = memoryMap->XMemory[36];
  v19 = memoryMap->YMemory[38];
  v99 = memoryMap->YMemory[38];
  if ( samplesRemaining )
  {
    v20 = (char *)inputBuf - (char *)outputBuf;
    do
    {
      v21 = *(float *)((char *)outputBuf + v20);
      v22 = (float)(v5 * v95) + (float)(v81 * v21);
      v23 = v100;
      v100 = v5;
      v5 = *(float *)((char *)outputBuf + v20);
      v24 = (float)(v22 + (float)(v23 * v65)) - (float)(v6 * v97);
      v25 = v50;
      v50 = v6;
      v6 = v24 - (float)(v25 * v67);
      v26 = (float)(v7 * v83) + (float)(v69 * v6);
      v27 = v56;
      v56 = v7;
      v7 = v6;
      v28 = (float)(v26 + (float)(v27 * v91)) - (float)(v8 * v71);
      v29 = v52;
      v52 = v8;
      v30 = v28 - (float)(v29 * v85);
      v8 = v30;
      v31 = (float)(v9 * v73) + (float)(v62 * v30);
      v32 = v60;
      v60 = v9;
      v9 = v30;
      v33 = (float)(v31 + (float)(v32 * v75)) - (float)(v10 * v87);
      v34 = v54;
      v54 = v10;
      v10 = v33 - (float)(v34 * v77);
      v35 = (float)(v11 * v93) + (float)(v79 * v10);
      v36 = v48;
      v48 = v11;
      v11 = v10;
      v37 = (float)(v35 + (float)(v36 * v89)) - (float)(v12 * v63);
      v38 = v49;
      v49 = v12;
      v39 = v37 - (float)(v38 * v64);
      v12 = v39;
      v40 = (float)((float)(v13 * v66) + (float)(v68 * v39)) + (float)(v51 * v70);
      v51 = v13;
      v13 = v39;
      ++outputBuf;
      v41 = v53;
      v53 = v14;
      v14 = (float)(v40 - (float)(v14 * v72)) - (float)(v41 * v74);
      v42 = (float)(v15 * v76) + (float)(v78 * v14);
      v43 = v55;
      v55 = v15;
      v15 = v14;
      v44 = (float)(v42 + (float)(v43 * v80)) - (float)(v16 * v82);
      v45 = v57;
      v57 = v16;
      v46 = v44 - (float)(v45 * v84);
      v16 = v46;
      v47 = (float)((float)((float)((float)(v99 * v86) + (float)(v88 * v46)) + (float)(v59 * v90)) - (float)(v58 * v92))
          - (float)(v61 * v94);
      v59 = v99;
      v19 = v46;
      v99 = v46;
      v61 = v58;
      v17 = v47;
      v58 = v47;
      *(outputBuf - 1) = (float)(v47 * v96) + (float)(v21 * v98);
      --samplesRemaining;
    }
    while ( samplesRemaining );
    v18 = v100;
    v4 = v50;
  }
  memoryMap->YMemory[8] = v7;
  memoryMap->YMemory[38] = v19;
  memoryMap->YMemory[14] = v9;
  memoryMap->YMemory[20] = v11;
  memoryMap->YMemory[2] = v5;
  memoryMap->YMemory[3] = v18;
  memoryMap->YMemory[9] = v56;
  memoryMap->YMemory[26] = v13;
  memoryMap->YMemory[32] = v15;
  memoryMap->YMemory[10] = v8;
  memoryMap->YMemory[11] = v52;
  memoryMap->YMemory[39] = v59;
  memoryMap->YMemory[15] = v60;
  memoryMap->YMemory[16] = v10;
  memoryMap->YMemory[17] = v54;
  memoryMap->YMemory[4] = v6;
  memoryMap->YMemory[21] = v48;
  memoryMap->YMemory[22] = v12;
  memoryMap->YMemory[23] = v49;
  memoryMap->YMemory[40] = v17;
  memoryMap->YMemory[27] = v51;
  memoryMap->YMemory[28] = v14;
  memoryMap->YMemory[29] = v53;
  memoryMap->YMemory[5] = v4;
  memoryMap->YMemory[33] = v55;
  memoryMap->YMemory[34] = v16;
  memoryMap->YMemory[35] = v57;
  memoryMap->YMemory[41] = v61;
}

// File Line: 244
// RVA: 0xB08490
char *__fastcall ProcessFutzBoxSIMWwise(char *memoryBlock, float *pfChannelIn, float *pfChannelOut, unsigned int uNumSamples)
{
  __int64 v4; // rcx

  ProcessFutzSIMChannel((FutzBoxSIMMemoryMap *)memoryBlock, pfChannelIn, pfChannelOut, uNumSamples);
  return (char *)(v4 + 360);
}

// File Line: 267
// RVA: 0xB084B0
void __fastcall FutzBoxSIMMemoryMapHelper::FutzBoxSIMMemoryMapHelper(FutzBoxSIMMemoryMapHelper *this)
{
  FutzBoxSIMMemoryMapHelper *v1; // rbx

  v1 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->0);
  v1->FutzBoxMemMapPtr = 0i64;
}

// File Line: 273
// RVA: 0xB084E0
void __fastcall FutzBoxSIMMemoryMapHelper::~FutzBoxSIMMemoryMapHelper(FutzBoxSIMMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->0);
}

// File Line: 279
// RVA: 0xB084F0
signed __int64 __fastcall FutzBoxSIMMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 360i64 * numChannels;
}

// File Line: 288
// RVA: 0xB08500
__int64 __fastcall FutzBoxSIMMemoryMapHelper::Init(FutzBoxSIMMemoryMapHelper *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzBoxSIMMemoryMapHelper *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  v4 = this;
  this->mSampleRate = sampleRate;
  v5 = 360i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x168ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->FutzBoxMemMapPtr = (FutzBoxSIMMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 307
// RVA: 0xB08560
FutzBoxSIMMemoryMap *__fastcall FutzBoxSIMMemoryMapHelper::GetMemoryMap(FutzBoxSIMMemoryMapHelper *this, unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 316
// RVA: 0xB08580
void __fastcall FutzBoxSIMMemoryMapHelper::SetSIMPreset(FutzBoxSIMMemoryMapHelper *this, FutzSIMType type, long double tuning)
{
  FutzBoxSIMMemoryMapHelper *v3; // rdi
  unsigned int v4; // esi
  signed __int64 v5; // rbx
  SCoefs coefs3; // [rsp+50h] [rbp-158h]
  SCoefs coefs; // [rsp+80h] [rbp-128h]
  SCoefs coefs4; // [rsp+B0h] [rbp-F8h]
  SCoefs coefs2; // [rsp+E0h] [rbp-C8h]
  SCoefs coefs5; // [rsp+110h] [rbp-98h]
  SCoefs coefs1; // [rsp+140h] [rbp-68h]
  SCoefs lpfCoefs; // [rsp+170h] [rbp-38h]

  v3 = this;
  SIMCalculator::CalculateSIMCoefficients(
    this->mSampleRate,
    type,
    tuning * 0.01,
    &coefs,
    &coefs1,
    &coefs2,
    &coefs3,
    &coefs4,
    &coefs5,
    &lpfCoefs);
  v4 = 0;
  if ( v3->mNumChannels )
  {
    do
    {
      v5 = v4;
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &coefs, v3->FutzBoxMemMapPtr[v5].XMemory, 2);
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &coefs1, v3->FutzBoxMemMapPtr[v5].XMemory, 7);
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &coefs2, v3->FutzBoxMemMapPtr[v5].XMemory, 12);
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &coefs3, v3->FutzBoxMemMapPtr[v5].XMemory, 17);
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &coefs4, v3->FutzBoxMemMapPtr[v5].XMemory, 22);
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &coefs5, v3->FutzBoxMemMapPtr[v5].XMemory, 27);
      DSPMemoryMapHelper::SetFilterCoefs(&v3->0, &lpfCoefs, v3->FutzBoxMemMapPtr[v5].XMemory, 32);
      ++v4;
    }
    while ( v4 < v3->mNumChannels );
  }
}

// File Line: 345
// RVA: 0xB08700
void __fastcall FutzBoxSIMMemoryMapHelper::SetSIMOriginalInput(FutzBoxSIMMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzBoxSIMMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v2->0, 1, v2->FutzBoxMemMapPtr[v1++].XMemory, 37);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 353
// RVA: 0xB08760
void __fastcall FutzBoxSIMMemoryMapHelper::SetSIMMix(FutzBoxSIMMemoryMapHelper *this, FutzSIMType type, bool bypassed)
{
  long double v3; // xmm8_8
  FutzBoxSIMMemoryMapHelper *v4; // rdi
  double v5; // xmm6_8
  double v6; // xmm0_8
  unsigned int v7; // esi
  signed __int64 v8; // rbx

  v3 = DOUBLE_1_0;
  v4 = this;
  v5 = 0.0;
  if ( !bypassed )
  {
    v3 = 0.0;
    v6 = SIMCalculator::GetSIMMixValue(type);
    v5 = v6;
    if ( v6 < 0.0 )
      v5 = pow(10.0, v6 * 0.05);
  }
  v7 = 0;
  if ( v4->mNumChannels )
  {
    do
    {
      v8 = v7;
      DSPMemoryMapHelper::SetDoubleValue(&v4->0, v5, v4->FutzBoxMemMapPtr[v8].XMemory, 38);
      DSPMemoryMapHelper::SetDoubleValue(&v4->0, v3, v4->FutzBoxMemMapPtr[v8].XMemory, 39);
      ++v7;
    }
    while ( v7 < v4->mNumChannels );
  }
}

// File Line: 388
// RVA: 0xB08840
void __fastcall FutzBoxSIMMemoryMapHelper::SetBalanceLevels(FutzBoxSIMMemoryMapHelper *this, long double balance)
{
  unsigned int v2; // esi
  FutzBoxSIMMemoryMapHelper *v3; // rdi
  signed __int64 v4; // rbx

  v2 = 0;
  v3 = this;
  if ( this->mNumChannels )
  {
    do
    {
      v4 = v2;
      DSPMemoryMapHelper::SetDoubleValue(&v3->0, balance * 0.01, v3->FutzBoxMemMapPtr[v4].YMemory, 45);
      DSPMemoryMapHelper::SetDoubleValue(&v3->0, 1.0 - balance * 0.01, v3->FutzBoxMemMapPtr[v4].YMemory, 46);
      ++v2;
    }
    while ( v2 < v3->mNumChannels );
  }
}

// File Line: 405
// RVA: 0xB088F0
void __fastcall FutzBoxSIMMemoryMapHelper::SetDrySignalAddress(FutzBoxSIMMemoryMapHelper *this)
{
  unsigned int v1; // ebx
  FutzBoxSIMMemoryMapHelper *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(&v2->0, 1, v2->FutzBoxMemMapPtr[v1++].XMemory, 40);
    while ( v1 < v2->mNumChannels );
  }
}

// File Line: 411
// RVA: 0xB08950
void __fastcall FutzBoxSIMMemoryMapHelper::SetInputGain(FutzBoxSIMMemoryMapHelper *this, long double gain)
{
  FutzBoxSIMMemoryMapHelper *v2; // rdi
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

// File Line: 423
// RVA: 0xB089E0
void __fastcall FutzBoxSIMMemoryMapHelper::SetOutputGain(FutzBoxSIMMemoryMapHelper *this, long double gain)
{
  FutzBoxSIMMemoryMapHelper *v2; // rdi
  unsigned int v3; // ebx
  double v4; // xmm6_8

  v2 = this;
  v3 = 0;
  v4 = pow(10.0, gain * 0.05);
  if ( v2->mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetDoubleValue(&v2->0, v4, v2->FutzBoxMemMapPtr[v3++].YMemory, 44);
    while ( v3 < v2->mNumChannels );
  }
}

// File Line: 437
// RVA: 0xB08A70
void __fastcall FutzSIMImpl::FutzSIMImpl(FutzSIMImpl *this)
{
  FutzSIMImpl *v1; // rbx

  v1 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper.0);
  v1->MemoryMapHelper.FutzBoxMemMapPtr = 0i64;
}

// File Line: 443
// RVA: 0xB08AA0
void __fastcall FutzSIMImpl::~FutzSIMImpl(FutzSIMImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper.0);
}

// File Line: 450
// RVA: 0xB08AB0
signed __int64 __fastcall FutzSIMImpl::GetMemoryMapSize(FutzSIMImpl *this, unsigned int numChannels)
{
  return 360i64 * numChannels;
}

// File Line: 459
// RVA: 0xB08AC0
__int64 __fastcall FutzSIMImpl::Init(FutzSIMImpl *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int numChannels, unsigned int sampleRate)
{
  FutzSIMImpl *v4; // rbx
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->m_uNumTailFrames = 0;
  this->MemoryMapHelper.mNumChannels = numChannels;
  v4 = this;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 360i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x168ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  v4->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxSIMMemoryMap *)v6;
  if ( !v6 )
    v7 = 52;
  return v7;
}

// File Line: 469
// RVA: 0xB08C10
void __fastcall FutzSIMImpl::ComputeTailLength(FutzSIMImpl *this, FutzBoxSIMMemoryMap *memoryMap)
{
  FutzSIMImpl *v2; // rbx
  float v3; // xmm6_4
  float v4; // xmm11_4
  float v5; // xmm10_4
  float v6; // xmm9_4
  float v7; // xmm8_4
  float v8; // xmm7_4
  float v9; // xmm0_4
  BiquadCoefficients v10; // [rsp+20h] [rbp-D8h]
  BiquadCoefficients in_coeffs; // [rsp+38h] [rbp-C0h]
  BiquadCoefficients v12; // [rsp+50h] [rbp-A8h]
  BiquadCoefficients v13; // [rsp+68h] [rbp-90h]
  float v14; // [rsp+7Ch] [rbp-7Ch]
  float v15; // [rsp+80h] [rbp-78h]
  float v16; // [rsp+84h] [rbp-74h]
  float v17; // [rsp+88h] [rbp-70h]
  BiquadCoefficients v18; // [rsp+90h] [rbp-68h]
  BiquadCoefficients v19; // [rsp+A8h] [rbp-50h]

  v2 = this;
  in_coeffs.a0 = memoryMap->XMemory[2];
  in_coeffs.a1 = memoryMap->XMemory[3];
  in_coeffs.a2 = memoryMap->XMemory[4];
  in_coeffs.b1 = memoryMap->XMemory[5];
  in_coeffs.b2 = memoryMap->XMemory[6];
  v18.a0 = memoryMap->XMemory[7];
  v18.a1 = memoryMap->XMemory[8];
  v18.a2 = memoryMap->XMemory[9];
  v18.b1 = memoryMap->XMemory[10];
  v18.b2 = memoryMap->XMemory[11];
  v13.a0 = memoryMap->XMemory[12];
  v13.a1 = memoryMap->XMemory[13];
  v13.a2 = memoryMap->XMemory[14];
  v13.b1 = memoryMap->XMemory[15];
  v13.b2 = memoryMap->XMemory[16];
  v10.a0 = memoryMap->XMemory[17];
  v10.a1 = memoryMap->XMemory[18];
  v10.a2 = memoryMap->XMemory[19];
  v10.b1 = memoryMap->XMemory[20];
  v10.b2 = memoryMap->XMemory[21];
  v12.a0 = memoryMap->XMemory[22];
  v12.a1 = memoryMap->XMemory[23];
  v12.a2 = memoryMap->XMemory[24];
  v12.b1 = memoryMap->XMemory[25];
  v12.b2 = memoryMap->XMemory[26];
  v13.b2 = memoryMap->XMemory[27];
  v14 = memoryMap->XMemory[28];
  v15 = memoryMap->XMemory[29];
  v16 = memoryMap->XMemory[30];
  v17 = memoryMap->XMemory[31];
  v19.a0 = memoryMap->XMemory[32];
  v19.a1 = memoryMap->XMemory[33];
  v19.a2 = memoryMap->XMemory[34];
  v19.b1 = memoryMap->XMemory[35];
  v19.b2 = memoryMap->XMemory[36];
  v3 = SIMCalculator::CalculateDecayTime(&in_coeffs);
  v4 = SIMCalculator::CalculateDecayTime(&v18);
  v5 = SIMCalculator::CalculateDecayTime(&v13);
  v6 = SIMCalculator::CalculateDecayTime(&v10);
  v7 = SIMCalculator::CalculateDecayTime(&v12);
  v8 = SIMCalculator::CalculateDecayTime((BiquadCoefficients *)((char *)&v13 + 16));
  v9 = SIMCalculator::CalculateDecayTime(&v19);
  if ( v3 <= v4 )
    v3 = v4;
  if ( v3 <= v5 )
    v3 = v5;
  if ( v3 <= v6 )
    v3 = v6;
  if ( v3 <= v7 )
    v3 = v7;
  if ( v3 <= v8 )
    v3 = v8;
  if ( v3 <= v9 )
    v3 = v9;
  v2->m_uNumTailFrames = (signed int)(v3 * 6.91);
}

// File Line: 500
// RVA: 0xB08B20
void __fastcall FutzSIMImpl::SetParameters(FutzSIMImpl *this, FutzSIMParameters *simParams)
{
  FutzSIMParameters *v2; // r14
  FutzSIMImpl *v3; // rbx
  unsigned int v4; // edi
  unsigned int v5; // esi

  v2 = simParams;
  v3 = this;
  FutzBoxSIMMemoryMapHelper::SetSIMPreset(&this->MemoryMapHelper, simParams->type, simParams->tuning);
  v4 = 0;
  v5 = 0;
  if ( v3->MemoryMapHelper.mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(
        &v3->MemoryMapHelper.0,
        1,
        v3->MemoryMapHelper.FutzBoxMemMapPtr[v5++].XMemory,
        37);
    while ( v5 < v3->MemoryMapHelper.mNumChannels );
  }
  FutzBoxSIMMemoryMapHelper::SetSIMMix(&v3->MemoryMapHelper, v2->type, v2->bypassed);
  FutzBoxSIMMemoryMapHelper::SetBalanceLevels(&v3->MemoryMapHelper, 100.0);
  if ( v3->MemoryMapHelper.mNumChannels > 0 )
  {
    do
      DSPMemoryMapHelper::SetLongValue(
        &v3->MemoryMapHelper.0,
        1,
        v3->MemoryMapHelper.FutzBoxMemMapPtr[v4++].XMemory,
        40);
    while ( v4 < v3->MemoryMapHelper.mNumChannels );
  }
  FutzBoxSIMMemoryMapHelper::SetInputGain(&v3->MemoryMapHelper, 0.0);
  FutzBoxSIMMemoryMapHelper::SetOutputGain(&v3->MemoryMapHelper, 0.0);
  FutzSIMImpl::ComputeTailLength(v3, v3->MemoryMapHelper.FutzBoxMemMapPtr);
}

