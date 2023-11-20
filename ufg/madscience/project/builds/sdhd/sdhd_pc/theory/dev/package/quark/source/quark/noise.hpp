// File Line: 199
// RVA: 0x96610
void __fastcall UFG::qNoise<float,float>::qNoise<float,float>(UFG::qNoise<float,float> *this)
{
  signed __int64 v1; // rax
  float v2; // xmm1_4
  float v3; // xmm0_4

  v1 = 6i64;
  this->bCircular = 0;
  this->tDecay = 0.5;
  this->tOffset = 0.0;
  v2 = 0.0;
  this->nOctaves = 6;
  this->tRangeMin = -1.0;
  this->tRangeMax = 1.0;
  LODWORD(this->tFrequency) = (unsigned int)FLOAT_1_0 & _xmm;
  v3 = *(float *)&FLOAT_1_0;
  do
  {
    v2 = v2 + v3;
    v3 = v3 * 0.5;
    --v1;
  }
  while ( v1 );
  this->tAmplitude = 1.0 / v2;
}

// File Line: 213
// RVA: 0xB1C10
void __fastcall UFG::qNoise<float,float>::SetParameters(UFG::qNoise<float,float> *this, int octaves, float frequency, float decay, float min, float max)
{
  float v6; // xmm1_4
  float v7; // xmm0_4
  int v8; // eax
  float v9; // xmm5_4
  float v10; // xmm0_4

  v6 = 0.0;
  if ( decay <= 0.0 )
  {
    decay = 0.0;
  }
  else if ( decay >= 1.0 )
  {
    decay = *(float *)&FLOAT_1_0;
  }
  this->tDecay = decay;
  if ( octaves <= 1 )
  {
    octaves = 1;
  }
  else if ( octaves >= 31 )
  {
    octaves = 31;
  }
  v7 = min;
  v8 = 0;
  this->nOctaves = octaves;
  this->tOffset = 0.0;
  LODWORD(this->tFrequency) = LODWORD(frequency) & _xmm;
  if ( min >= max )
    v9 = max;
  else
    v9 = min;
  this->tRangeMin = v9;
  if ( min <= max )
    v7 = max;
  this->tRangeMax = v7;
  v10 = *(float *)&FLOAT_1_0;
  if ( octaves > 0 )
  {
    do
    {
      ++v8;
      v6 = v6 + v10;
      v10 = v10 * decay;
    }
    while ( v8 < octaves );
  }
  this->tAmplitude = 1.0 / v6;
}

// File Line: 256
// RVA: 0xAB7A0
int UFG::qNoise<float,float>::GetValue(...)
{
  int v2; // edi
  UFG::qNoise<float,float> *v3; // rbx
  float v4; // xmm9_4
  float v5; // xmm13_4
  float v6; // xmm11_4
  __m128 i; // xmm12
  __m128 v8; // xmm7
  float v9; // xmm1_4
  signed int v10; // ecx
  bool v11; // zf
  float v12; // xmm8_4
  float v13; // xmm7_4
  float v14; // xmm0_4
  int v15; // eax
  float v16; // xmm6_4
  int v17; // eax
  float v18; // xmm0_4
  float x; // [rsp+D0h] [rbp+8h]
  float v21; // [rsp+E0h] [rbp+18h]

  v2 = 0;
  v3 = this;
  v4 = 0.0;
  v5 = this->tAmplitude;
  v6 = this->tFrequency;
  for ( i = (__m128)t; v2 < v3->nOctaves; v4 = v4 + v18 )
  {
    v8 = i;
    v8.m128_f32[0] = (float)(i.m128_f32[0] + v3->tOffset) * v6;
    v9 = v8.m128_f32[0];
    v10 = (signed int)v8.m128_f32[0];
    if ( (signed int)v8.m128_f32[0] != 0x80000000 && (float)v10 != v8.m128_f32[0] )
      v9 = (float)(v10 - (_mm_movemask_ps(_mm_unpacklo_ps(v8, v8)) & 1));
    v11 = v3->bCircular == 0;
    x = v9;
    v21 = v9 + 1.0;
    v12 = (float)(v9 + 1.0) - v8.m128_f32[0];
    v13 = v8.m128_f32[0] - v9;
    if ( !v11 )
    {
      v14 = sinf(v13 * 1.5707964);
      v13 = v14 * v14;
      v12 = 1.0 - (float)(v14 * v14);
    }
    v15 = UFG::NoiseSeed<float>(&x);
    v16 = UFG::NoiseRandom<float>(v15);
    v17 = UFG::NoiseSeed<float>(&v21);
    ++v2;
    v6 = v6 * 2.0;
    v18 = (float)((float)(UFG::NoiseRandom<float>(v17) * v13) + (float)(v16 * v12)) * v5;
    v5 = v5 * v3->tDecay;
  }
  return (float)((float)(v3->tRangeMax - v3->tRangeMin) * (float)((float)(v4 + 1.0) * 0.5)) + v3->tRangeMin;
}

