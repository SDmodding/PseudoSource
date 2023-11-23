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
void __fastcall DSPMemoryMapHelper::SetDoubleValue(
        DSPMemoryMapHelper *this,
        long double value,
        float *memory,
        int offset)
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
void __fastcall DSPMemoryMapHelper::SetTableValues(
        DSPMemoryMapHelper *this,
        long double *table,
        int tableSize,
        float *memory,
        int offset)
{
  int v5; // r11d
  int v8; // r9d
  __int64 v9; // rcx
  int v10; // eax
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // r9
  float *v14; // r8
  long double *v15; // rdx
  unsigned __int64 v16; // rax
  double v17; // xmm0_8
  float v18; // xmm1_4
  float *v19; // rdx
  double v20; // xmm0_8

  v5 = 0;
  if ( tableSize >= 4
    && (&memory[offset] > (float *)&table[tableSize - 1] || &memory[tableSize - 1 + offset] < (float *)table) )
  {
    v8 = offset + 2;
    do
    {
      v9 = v5;
      v5 += 4;
      v10 = v8 - offset;
      *(long double *)&memory[v8 - 2] = table[v9];
      v11 = v8;
      v8 += 4;
      *(long double *)&memory[v11] = table[v10];
    }
    while ( v5 < tableSize - (tableSize & 3) );
  }
  v12 = v5;
  v13 = tableSize;
  if ( v5 < (__int64)tableSize )
  {
    if ( tableSize - (__int64)v5 >= 4 )
    {
      v14 = &memory[v5 + (__int64)offset];
      v15 = &table[v5 + 2];
      v16 = ((unsigned __int64)(v13 - v5 - 4) >> 2) + 1;
      v12 = v5 + 4 * v16;
      do
      {
        v17 = *(v15 - 2);
        v14 += 4;
        v15 += 4;
        *(float *)&v17 = v17;
        *(v14 - 4) = *(float *)&v17;
        v18 = *(v15 - 5);
        *(v14 - 3) = v18;
        *(v14 - 2) = *(v15 - 4);
        *(v14 - 1) = *(v15 - 3);
        --v16;
      }
      while ( v16 );
    }
    if ( v12 < v13 )
    {
      v19 = &memory[v12 + offset];
      do
      {
        v20 = table[v12++];
        *v19++ = v20;
      }
      while ( v12 < v13 );
    }
  }
}

// File Line: 62
// RVA: 0xB024F0
void __fastcall DSPMemoryMapHelper::SetFilterCoefs(DSPMemoryMapHelper *this, SCoefs *coefs, float *memory, int offset)
{
  float a0; // xmm0_4
  float a1; // xmm1_4
  float a2; // xmm0_4

  a0 = coefs->a0;
  memory[offset] = a0;
  a1 = coefs->a1;
  memory[offset + 1] = a1;
  a2 = coefs->a2;
  memory[offset + 2] = a2;
  memory[offset + 3] = coefs->b1;
  memory[offset + 4] = coefs->b2;
}

// File Line: 76
// RVA: 0xB02550
void __fastcall DSPMemoryMapHelper::SetFirstOrderFilterCoefs(
        DSPMemoryMapHelper *this,
        SCoefs *coefs,
        float *memory,
        int offset)
{
  float a0; // xmm0_4

  a0 = coefs->a0;
  memory[offset] = a0;
  memory[offset + 1] = coefs->a1;
  memory[offset + 2] = coefs->b1;
}

