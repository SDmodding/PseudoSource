// File Line: 17
// RVA: 0xB022E0
void __fastcall DSPMemoryMapHelper::DSPMemoryMapHelper(DSPMemoryMapHelper *this)
{
  this->mSampleRate = 44100;
  this->mNumChannels = 1;
}

// File Line: 23
// RVA: 0xB02300
void __fastcall DSPMemoryMapHelper::~DSPMemoryMapHelper(DSPMemoryMapHelper *this)
{
  ;
}

// File Line: 29
// RVA: 0xB02310
void __fastcall DSPMemoryMapHelper::Init(DSPMemoryMapHelper *this, unsigned int numChannels, unsigned int sampleRate)
{
  this->mNumChannels = numChannels;
  this->mSampleRate = sampleRate;
}

// File Line: 37
// RVA: 0xB02320
void __fastcall DSPMemoryMapHelper::SetDoubleValue(DSPMemoryMapHelper *this, long double value, float *memory, int offset)
{
  float v4; // xmm0_4

  v4 = value;
  memory[offset] = v4;
}

// File Line: 44
// RVA: 0xB02340
void __fastcall DSPMemoryMapHelper::SetLongValue(DSPMemoryMapHelper *this, int value, float *memory, int offset)
{
  memory[offset] = (float)value;
}

// File Line: 51
// RVA: 0xB02360
void __fastcall DSPMemoryMapHelper::SetTableValues(DSPMemoryMapHelper *this, long double *table, int tableSize, float *memory, int offset)
{
  int v5; // er11
  float *v6; // rbx
  long double *v7; // r10
  int v8; // er9
  __int64 v9; // rcx
  int v10; // eax
  __int64 v11; // rdx
  signed __int64 v12; // rcx
  signed __int64 v13; // r9
  signed __int64 v14; // r8
  signed __int64 v15; // rdx
  unsigned __int64 v16; // rax
  double v17; // xmm0_8
  float v18; // xmm1_4
  float *v19; // rdx
  double v20; // xmm0_8

  v5 = 0;
  v6 = memory;
  v7 = table;
  if ( tableSize > 0
    && (unsigned int)tableSize >= 4
    && (&memory[offset] > (float *)&table[tableSize - 1] || &memory[tableSize - 1 + offset] < (float *)table) )
  {
    v8 = offset + 2;
    do
    {
      v9 = v5;
      v5 += 4;
      v10 = v8 - offset;
      *(_QWORD *)&v6[v8 - 2] = *(_OWORD *)&v7[v9];
      v11 = v8;
      v8 += 4;
      *(_QWORD *)&v6[v11] = *(_OWORD *)&v7[v10];
    }
    while ( v5 < tableSize - tableSize % 4 );
  }
  v12 = v5;
  v13 = tableSize;
  if ( v5 < (signed __int64)tableSize )
  {
    if ( tableSize - (signed __int64)v5 >= 4 )
    {
      v14 = (signed __int64)&v6[v5 + (signed __int64)offset];
      v15 = (signed __int64)&v7[v5 + 2];
      v16 = ((unsigned __int64)(v13 - v5 - 4) >> 2) + 1;
      v12 = v5 + 4 * v16;
      do
      {
        v17 = *(double *)(v15 - 16);
        v14 += 16i64;
        v15 += 32i64;
        *(float *)&v17 = v17;
        *(_DWORD *)(v14 - 16) = LODWORD(v17);
        v18 = *(double *)(v15 - 40);
        *(float *)(v14 - 12) = v18;
        *(float *)(v14 - 8) = *(double *)(v15 - 32);
        *(float *)(v14 - 4) = *(double *)(v15 - 24);
        --v16;
      }
      while ( v16 );
    }
    if ( v12 < v13 )
    {
      v19 = &v6[v12 + offset];
      do
      {
        v20 = v7[v12++];
        ++v19;
        *(v19 - 1) = v20;
      }
      while ( v12 < v13 );
    }
  }
}

// File Line: 62
// RVA: 0xB024F0
void __fastcall DSPMemoryMapHelper::SetFilterCoefs(DSPMemoryMapHelper *this, SCoefs *coefs, float *memory, int offset)
{
  __int64 v4; // rax
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4

  v4 = offset;
  v5 = coefs->a0;
  memory[v4] = v5;
  v6 = coefs->a1;
  memory[v4 + 1] = v6;
  v7 = coefs->a2;
  memory[v4 + 2] = v7;
  memory[v4 + 3] = coefs->b1;
  memory[v4 + 4] = coefs->b2;
}

// File Line: 76
// RVA: 0xB02550
void __fastcall DSPMemoryMapHelper::SetFirstOrderFilterCoefs(DSPMemoryMapHelper *this, SCoefs *coefs, float *memory, int offset)
{
  __int64 v4; // rax
  float v5; // xmm0_4

  v4 = offset;
  v5 = coefs->a0;
  memory[v4] = v5;
  memory[v4 + 1] = coefs->a1;
  memory[v4 + 2] = coefs->b1;
}

