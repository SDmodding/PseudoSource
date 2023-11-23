// File Line: 162
// RVA: 0xB08E20
void __fastcall ProcessFutzSIMChannel(
        FutzBoxSIMMemoryMap *memoryMap,
        const float *inputBuf,
        float *outputBuf,
        unsigned int samplesRemaining)
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
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // [rsp+0h] [rbp-178h]
  float v46; // [rsp+4h] [rbp-174h]
  float v47; // [rsp+8h] [rbp-170h]
  float v48; // [rsp+Ch] [rbp-16Ch]
  float v49; // [rsp+10h] [rbp-168h]
  float v50; // [rsp+14h] [rbp-164h]
  float v51; // [rsp+18h] [rbp-160h]
  float v52; // [rsp+1Ch] [rbp-15Ch]
  float v53; // [rsp+20h] [rbp-158h]
  float v54; // [rsp+24h] [rbp-154h]
  float v55; // [rsp+28h] [rbp-150h]
  float v56; // [rsp+2Ch] [rbp-14Ch]
  float v57; // [rsp+30h] [rbp-148h]
  float v58; // [rsp+34h] [rbp-144h]
  float v59; // [rsp+38h] [rbp-140h]
  float v60; // [rsp+3Ch] [rbp-13Ch]
  float v61; // [rsp+40h] [rbp-138h]
  float v62; // [rsp+44h] [rbp-134h]
  float v63; // [rsp+48h] [rbp-130h]
  float v64; // [rsp+4Ch] [rbp-12Ch]
  float v65; // [rsp+50h] [rbp-128h]
  float v66; // [rsp+54h] [rbp-124h]
  float v67; // [rsp+58h] [rbp-120h]
  float v68; // [rsp+5Ch] [rbp-11Ch]
  float v69; // [rsp+60h] [rbp-118h]
  float v70; // [rsp+64h] [rbp-114h]
  float v71; // [rsp+68h] [rbp-110h]
  float v72; // [rsp+6Ch] [rbp-10Ch]
  float v73; // [rsp+70h] [rbp-108h]
  float v74; // [rsp+74h] [rbp-104h]
  float v75; // [rsp+78h] [rbp-100h]
  float v76; // [rsp+7Ch] [rbp-FCh]
  float v77; // [rsp+80h] [rbp-F8h]
  float v78; // [rsp+84h] [rbp-F4h]
  float v79; // [rsp+88h] [rbp-F0h]
  float v80; // [rsp+8Ch] [rbp-ECh]
  float v81; // [rsp+90h] [rbp-E8h]
  float v82; // [rsp+94h] [rbp-E4h]
  float v83; // [rsp+98h] [rbp-E0h]
  float v84; // [rsp+9Ch] [rbp-DCh]
  float v85; // [rsp+A0h] [rbp-D8h]
  float v86; // [rsp+A4h] [rbp-D4h]
  float v87; // [rsp+A8h] [rbp-D0h]
  float v88; // [rsp+ACh] [rbp-CCh]
  float v89; // [rsp+B0h] [rbp-C8h]
  float v90; // [rsp+B4h] [rbp-C4h]
  float v91; // [rsp+B8h] [rbp-C0h]
  float v92; // [rsp+BCh] [rbp-BCh]
  float v93; // [rsp+C0h] [rbp-B8h]
  float v94; // [rsp+C4h] [rbp-B4h]
  float v95; // [rsp+C8h] [rbp-B0h]
  float v96; // [rsp+180h] [rbp+8h]
  float v97; // [rsp+198h] [rbp+20h]

  v4 = memoryMap->YMemory[5];
  v78 = memoryMap->XMemory[2];
  v5 = memoryMap->YMemory[2];
  v92 = memoryMap->XMemory[3];
  v6 = memoryMap->YMemory[4];
  v7 = memoryMap->YMemory[8];
  v8 = memoryMap->YMemory[10];
  v9 = memoryMap->YMemory[14];
  v10 = memoryMap->YMemory[16];
  v11 = memoryMap->YMemory[20];
  v12 = memoryMap->YMemory[22];
  v62 = memoryMap->XMemory[4];
  v97 = memoryMap->YMemory[3];
  v94 = memoryMap->XMemory[5];
  v47 = v4;
  v64 = memoryMap->XMemory[6];
  v66 = memoryMap->XMemory[7];
  v80 = memoryMap->XMemory[8];
  v88 = memoryMap->XMemory[9];
  v68 = memoryMap->XMemory[10];
  v82 = memoryMap->XMemory[11];
  v53 = memoryMap->YMemory[9];
  v49 = memoryMap->YMemory[11];
  v59 = memoryMap->XMemory[12];
  v70 = memoryMap->XMemory[13];
  v72 = memoryMap->XMemory[14];
  v84 = memoryMap->XMemory[15];
  v74 = memoryMap->XMemory[16];
  v57 = memoryMap->YMemory[15];
  v51 = memoryMap->YMemory[17];
  v76 = memoryMap->XMemory[17];
  v90 = memoryMap->XMemory[18];
  v86 = memoryMap->XMemory[19];
  v60 = memoryMap->XMemory[20];
  v61 = memoryMap->XMemory[21];
  v45 = memoryMap->YMemory[21];
  v46 = memoryMap->YMemory[23];
  v65 = memoryMap->XMemory[22];
  v63 = memoryMap->XMemory[23];
  v67 = memoryMap->XMemory[24];
  v13 = memoryMap->YMemory[26];
  v14 = memoryMap->YMemory[28];
  v15 = memoryMap->YMemory[32];
  v16 = memoryMap->YMemory[34];
  v69 = memoryMap->XMemory[25];
  v58 = memoryMap->YMemory[41];
  v71 = memoryMap->XMemory[26];
  v48 = memoryMap->YMemory[27];
  v93 = memoryMap->XMemory[38];
  v50 = memoryMap->YMemory[29];
  v75 = memoryMap->XMemory[27];
  v56 = memoryMap->YMemory[39];
  v17 = memoryMap->YMemory[40];
  v73 = memoryMap->XMemory[28];
  v77 = memoryMap->XMemory[29];
  v95 = memoryMap->XMemory[39];
  v18 = v97;
  v79 = memoryMap->XMemory[30];
  v81 = memoryMap->XMemory[31];
  v55 = v17;
  v52 = memoryMap->YMemory[33];
  v54 = memoryMap->YMemory[35];
  v85 = memoryMap->XMemory[32];
  v83 = memoryMap->XMemory[33];
  v87 = memoryMap->XMemory[34];
  v89 = memoryMap->XMemory[35];
  v91 = memoryMap->XMemory[36];
  v19 = memoryMap->YMemory[38];
  v96 = v19;
  if ( samplesRemaining )
  {
    v20 = (char *)inputBuf - (char *)outputBuf;
    do
    {
      v21 = *(float *)((char *)outputBuf + v20);
      v22 = (float)(v5 * v92) + (float)(v78 * v21);
      v23 = v97;
      v97 = v5;
      v5 = v21;
      v24 = (float)(v22 + (float)(v23 * v62)) - (float)(v6 * v94);
      v25 = v47;
      v47 = v6;
      v6 = v24 - (float)(v25 * v64);
      v26 = (float)(v7 * v80) + (float)(v66 * v6);
      v27 = v53;
      v53 = v7;
      v7 = v6;
      v28 = (float)(v26 + (float)(v27 * v88)) - (float)(v8 * v68);
      v29 = v49;
      v49 = v8;
      v8 = v28 - (float)(v29 * v82);
      v30 = (float)(v9 * v70) + (float)(v59 * v8);
      v31 = v57;
      v57 = v9;
      v9 = v8;
      v32 = (float)(v30 + (float)(v31 * v72)) - (float)(v10 * v84);
      v33 = v51;
      v51 = v10;
      v10 = v32 - (float)(v33 * v74);
      v34 = (float)(v11 * v90) + (float)(v76 * v10);
      v35 = v45;
      v45 = v11;
      v11 = v10;
      v36 = (float)(v34 + (float)(v35 * v86)) - (float)(v12 * v60);
      v37 = v46;
      v46 = v12;
      v12 = v36 - (float)(v37 * v61);
      v38 = (float)((float)(v13 * v63) + (float)(v65 * v12)) + (float)(v48 * v67);
      v48 = v13;
      v13 = v12;
      ++outputBuf;
      v39 = v50;
      v50 = v14;
      v14 = (float)(v38 - (float)(v14 * v69)) - (float)(v39 * v71);
      v40 = (float)(v15 * v73) + (float)(v75 * v14);
      v41 = v52;
      v52 = v15;
      v15 = v14;
      v42 = (float)(v40 + (float)(v41 * v77)) - (float)(v16 * v79);
      v43 = v54;
      v54 = v16;
      v16 = v42 - (float)(v43 * v81);
      v44 = (float)((float)((float)((float)(v96 * v83) + (float)(v85 * v16)) + (float)(v56 * v87)) - (float)(v55 * v89))
          - (float)(v58 * v91);
      v56 = v96;
      v19 = v16;
      v96 = v16;
      v58 = v55;
      v17 = v44;
      v55 = v44;
      *(outputBuf - 1) = (float)(v44 * v93) + (float)(v21 * v95);
      --samplesRemaining;
    }
    while ( samplesRemaining );
    v18 = v97;
    v4 = v47;
  }
  memoryMap->YMemory[8] = v7;
  memoryMap->YMemory[38] = v19;
  memoryMap->YMemory[14] = v9;
  memoryMap->YMemory[20] = v11;
  memoryMap->YMemory[2] = v5;
  memoryMap->YMemory[3] = v18;
  memoryMap->YMemory[9] = v53;
  memoryMap->YMemory[26] = v13;
  memoryMap->YMemory[32] = v15;
  memoryMap->YMemory[10] = v8;
  memoryMap->YMemory[11] = v49;
  memoryMap->YMemory[39] = v56;
  memoryMap->YMemory[15] = v57;
  memoryMap->YMemory[16] = v10;
  memoryMap->YMemory[17] = v51;
  memoryMap->YMemory[4] = v6;
  memoryMap->YMemory[21] = v45;
  memoryMap->YMemory[22] = v12;
  memoryMap->YMemory[23] = v46;
  memoryMap->YMemory[40] = v17;
  memoryMap->YMemory[27] = v48;
  memoryMap->YMemory[28] = v14;
  memoryMap->YMemory[29] = v50;
  memoryMap->YMemory[5] = v4;
  memoryMap->YMemory[33] = v52;
  memoryMap->YMemory[34] = v16;
  memoryMap->YMemory[35] = v54;
  memoryMap->YMemory[41] = v58;
};
  memoryMap->YMemory[27] = v48;
  memoryMap->YMemory[28] = v14;
  memoryMap->YMemory[29] = v50;
  memoryMap->YMemory[5] = v4;
  m

// File Line: 244
// RVA: 0xB08490
char *__fastcall ProcessFutzBoxSIMWwise(
        FutzBoxSIMMemoryMap *memoryBlock,
        const float *pfChannelIn,
        float *pfChannelOut,
        unsigned int uNumSamples)
{
  __int64 v4; // rcx

  ProcessFutzSIMChannel(memoryBlock, pfChannelIn, pfChannelOut, uNumSamples);
  return (char *)(v4 + 360);
}

// File Line: 267
// RVA: 0xB084B0
void __fastcall FutzBoxSIMMemoryMapHelper::FutzBoxSIMMemoryMapHelper(FutzBoxSIMMemoryMapHelper *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(this);
  this->FutzBoxMemMapPtr = 0i64;
}

// File Line: 273
// RVA: 0xB084E0
// attributes: thunk
void __fastcall FutzBoxSIMMemoryMapHelper::~FutzBoxSIMMemoryMapHelper(FutzBoxSIMMemoryMapHelper *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(this);
}

// File Line: 279
// RVA: 0xB084F0
__int64 __fastcall FutzBoxSIMMemoryMapHelper::GetMemoryMapSize(unsigned int numChannels)
{
  return 360i64 * numChannels;
}

// File Line: 288
// RVA: 0xB08500
__int64 __fastcall FutzBoxSIMMemoryMapHelper::Init(
        FutzBoxSIMMemoryMapHelper *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->mNumChannels = numChannels;
  this->mSampleRate = sampleRate;
  v5 = 360i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x168ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->FutzBoxMemMapPtr = (FutzBoxSIMMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 307
// RVA: 0xB08560
FutzBoxSIMMemoryMap *__fastcall FutzBoxSIMMemoryMapHelper::GetMemoryMap(
        FutzBoxSIMMemoryMapHelper *this,
        unsigned int channelIndex)
{
  return &this->FutzBoxMemMapPtr[channelIndex];
}

// File Line: 316
// RVA: 0xB08580
void __fastcall FutzBoxSIMMemoryMapHelper::SetSIMPreset(
        FutzBoxSIMMemoryMapHelper *this,
        FutzSIMType type,
        long double tuning)
{
  unsigned int i; // esi
  __int64 v5; // rbx
  SCoefs coefs3; // [rsp+50h] [rbp-158h] BYREF
  SCoefs coefs; // [rsp+80h] [rbp-128h] BYREF
  SCoefs coefs4; // [rsp+B0h] [rbp-F8h] BYREF
  SCoefs coefs2; // [rsp+E0h] [rbp-C8h] BYREF
  SCoefs coefs5; // [rsp+110h] [rbp-98h] BYREF
  SCoefs coefs1; // [rsp+140h] [rbp-68h] BYREF
  SCoefs lpfCoefs; // [rsp+170h] [rbp-38h] BYREF

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
  for ( i = 0; i < this->mNumChannels; ++i )
  {
    v5 = i;
    DSPMemoryMapHelper::SetFilterCoefs(this, &coefs, this->FutzBoxMemMapPtr[v5].XMemory, 2);
    DSPMemoryMapHelper::SetFilterCoefs(this, &coefs1, this->FutzBoxMemMapPtr[v5].XMemory, 7);
    DSPMemoryMapHelper::SetFilterCoefs(this, &coefs2, this->FutzBoxMemMapPtr[v5].XMemory, 12);
    DSPMemoryMapHelper::SetFilterCoefs(this, &coefs3, this->FutzBoxMemMapPtr[v5].XMemory, 17);
    DSPMemoryMapHelper::SetFilterCoefs(this, &coefs4, this->FutzBoxMemMapPtr[v5].XMemory, 22);
    DSPMemoryMapHelper::SetFilterCoefs(this, &coefs5, this->FutzBoxMemMapPtr[v5].XMemory, 27);
    DSPMemoryMapHelper::SetFilterCoefs(this, &lpfCoefs, this->FutzBoxMemMapPtr[v5].XMemory, 32);
  }
}

// File Line: 345
// RVA: 0xB08700
void __fastcall FutzBoxSIMMemoryMapHelper::SetSIMOriginalInput(FutzBoxSIMMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(this, 1, this->FutzBoxMemMapPtr[i].XMemory, 37);
}

// File Line: 353
// RVA: 0xB08760
void __fastcall FutzBoxSIMMemoryMapHelper::SetSIMMix(FutzBoxSIMMemoryMapHelper *this, FutzSIMType type, bool bypassed)
{
  long double v3; // xmm8_8
  double v5; // xmm6_8
  double SIMMixValue; // xmm0_8
  unsigned int i; // esi
  __int64 v8; // rbx

  v3 = DOUBLE_1_0;
  v5 = 0.0;
  if ( !bypassed )
  {
    v3 = 0.0;
    SIMMixValue = SIMCalculator::GetSIMMixValue(type);
    v5 = SIMMixValue;
    if ( SIMMixValue < 0.0 )
      v5 = pow(10.0, SIMMixValue * 0.05);
  }
  for ( i = 0; i < this->mNumChannels; ++i )
  {
    v8 = i;
    DSPMemoryMapHelper::SetDoubleValue(this, v5, this->FutzBoxMemMapPtr[v8].XMemory, 38);
    DSPMemoryMapHelper::SetDoubleValue(this, v3, this->FutzBoxMemMapPtr[v8].XMemory, 39);
  }
}

// File Line: 388
// RVA: 0xB08840
void __fastcall FutzBoxSIMMemoryMapHelper::SetBalanceLevels(FutzBoxSIMMemoryMapHelper *this, long double balance)
{
  unsigned int i; // esi
  __int64 v4; // rbx

  for ( i = 0; i < this->mNumChannels; ++i )
  {
    v4 = i;
    DSPMemoryMapHelper::SetDoubleValue(this, balance * 0.01, this->FutzBoxMemMapPtr[v4].YMemory, 45);
    DSPMemoryMapHelper::SetDoubleValue(this, 1.0 - balance * 0.01, this->FutzBoxMemMapPtr[v4].YMemory, 46);
  }
}

// File Line: 405
// RVA: 0xB088F0
void __fastcall FutzBoxSIMMemoryMapHelper::SetDrySignalAddress(FutzBoxSIMMemoryMapHelper *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(this, 1, this->FutzBoxMemMapPtr[i].XMemory, 40);
}

// File Line: 411
// RVA: 0xB08950
void __fastcall FutzBoxSIMMemoryMapHelper::SetInputGain(FutzBoxSIMMemoryMapHelper *this, long double gain)
{
  unsigned int v3; // ebx
  double i; // xmm6_8

  v3 = 0;
  for ( i = pow(10.0, gain * 0.05); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].YMemory, 0);
}

// File Line: 423
// RVA: 0xB089E0
void __fastcall FutzBoxSIMMemoryMapHelper::SetOutputGain(FutzBoxSIMMemoryMapHelper *this, long double gain)
{
  unsigned int v3; // ebx
  double i; // xmm6_8

  v3 = 0;
  for ( i = pow(10.0, gain * 0.05); v3 < this->mNumChannels; ++v3 )
    DSPMemoryMapHelper::SetDoubleValue(this, i, this->FutzBoxMemMapPtr[v3].YMemory, 44);
}

// File Line: 437
// RVA: 0xB08A70
void __fastcall FutzSIMImpl::FutzSIMImpl(FutzSIMImpl *this)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->MemoryMapHelper);
  this->MemoryMapHelper.FutzBoxMemMapPtr = 0i64;
}

// File Line: 443
// RVA: 0xB08AA0
// attributes: thunk
void __fastcall FutzSIMImpl::~FutzSIMImpl(FutzSIMImpl *this)
{
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&this->MemoryMapHelper);
}

// File Line: 450
// RVA: 0xB08AB0
__int64 __fastcall FutzSIMImpl::GetMemoryMapSize(FutzSIMImpl *this, unsigned int numChannels)
{
  return 360i64 * numChannels;
}

// File Line: 459
// RVA: 0xB08AC0
__int64 __fastcall FutzSIMImpl::Init(
        FutzSIMImpl *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int numChannels,
        unsigned int sampleRate)
{
  unsigned __int64 v5; // rax
  char *v6; // rax
  unsigned int v7; // ecx

  this->m_uNumTailFrames = 0;
  this->MemoryMapHelper.mNumChannels = numChannels;
  this->MemoryMapHelper.mSampleRate = sampleRate;
  v5 = 360i64 * numChannels;
  if ( !is_mul_ok(numChannels, 0x168ui64) )
    v5 = -1i64;
  v6 = PooledMemoryAllocator::Malloc(memoryMapAllocator, v5);
  v7 = 1;
  this->MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxSIMMemoryMap *)v6;
  if ( !v6 )
    return 52;
  return v7;
}

// File Line: 469
// RVA: 0xB08C10
void __fastcall FutzSIMImpl::ComputeTailLength(FutzSIMImpl *this, FutzBoxSIMMemoryMap *memoryMap)
{
  float v3; // xmm6_4
  float v4; // xmm11_4
  float v5; // xmm10_4
  float v6; // xmm9_4
  float v7; // xmm8_4
  float v8; // xmm7_4
  float v9; // xmm0_4
  BiquadCoefficients v10; // [rsp+20h] [rbp-D8h] BYREF
  BiquadCoefficients in_coeffs; // [rsp+38h] [rbp-C0h] BYREF
  BiquadCoefficients v12; // [rsp+50h] [rbp-A8h] BYREF
  BiquadCoefficients v13; // [rsp+68h] [rbp-90h] BYREF
  float v14; // [rsp+7Ch] [rbp-7Ch]
  float v15; // [rsp+80h] [rbp-78h]
  float v16; // [rsp+84h] [rbp-74h]
  float v17; // [rsp+88h] [rbp-70h]
  BiquadCoefficients v18; // [rsp+90h] [rbp-68h] BYREF
  BiquadCoefficients v19; // [rsp+A8h] [rbp-50h] BYREF

  in_coeffs = *(BiquadCoefficients *)&memoryMap->XMemory[2];
  v18 = *(BiquadCoefficients *)&memoryMap->XMemory[7];
  v13 = *(BiquadCoefficients *)&memoryMap->XMemory[12];
  v10 = *(BiquadCoefficients *)&memoryMap->XMemory[17];
  v12 = *(BiquadCoefficients *)&memoryMap->XMemory[22];
  v13.b2 = memoryMap->XMemory[27];
  v14 = memoryMap->XMemory[28];
  v15 = memoryMap->XMemory[29];
  v16 = memoryMap->XMemory[30];
  v17 = memoryMap->XMemory[31];
  v19 = *(BiquadCoefficients *)&memoryMap->XMemory[32];
  v3 = SIMCalculator::CalculateDecayTime(&in_coeffs);
  v4 = SIMCalculator::CalculateDecayTime(&v18);
  v5 = SIMCalculator::CalculateDecayTime(&v13);
  v6 = SIMCalculator::CalculateDecayTime(&v10);
  v7 = SIMCalculator::CalculateDecayTime(&v12);
  v8 = SIMCalculator::CalculateDecayTime((BiquadCoefficients *)&v13.b2);
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
  this->m_uNumTailFrames = (int)(v3 * 6.91);
}

// File Line: 500
// RVA: 0xB08B20
void __fastcall FutzSIMImpl::SetParameters(FutzSIMImpl *this, FutzSIMParameters *simParams)
{
  unsigned int v4; // edi
  unsigned int i; // esi

  FutzBoxSIMMemoryMapHelper::SetSIMPreset(&this->MemoryMapHelper, simParams->type, simParams->tuning);
  v4 = 0;
  for ( i = 0; i < this->MemoryMapHelper.mNumChannels; ++i )
    DSPMemoryMapHelper::SetLongValue(&this->MemoryMapHelper, 1, this->MemoryMapHelper.FutzBoxMemMapPtr[i].XMemory, 37);
  FutzBoxSIMMemoryMapHelper::SetSIMMix(&this->MemoryMapHelper, simParams->type, simParams->bypassed);
  FutzBoxSIMMemoryMapHelper::SetBalanceLevels(&this->MemoryMapHelper, 100.0);
  if ( this->MemoryMapHelper.mNumChannels )
  {
    do
      DSPMemoryMapHelper::SetLongValue(
        &this->MemoryMapHelper,
        1,
        this->MemoryMapHelper.FutzBoxMemMapPtr[v4++].XMemory,
        40);
    while ( v4 < this->MemoryMapHelper.mNumChannels );
  }
  FutzBoxSIMMemoryMapHelper::SetInputGain(&this->MemoryMapHelper, 0.0);
  FutzBoxSIMMemoryMapHelper::SetOutputGain(&this->MemoryMapHelper, 0.0);
  FutzSIMImpl::ComputeTailLength(this, this->MemoryMapHelper.FutzBoxMemMapPtr);
}

