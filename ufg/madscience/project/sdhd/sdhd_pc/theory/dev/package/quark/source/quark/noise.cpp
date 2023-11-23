// File Line: 15
// RVA: 0x15F790
float __fastcall UFG::NoiseRandom<float>(int n)
{
  return 1.0
       - (float)((float)(((n ^ (n << 13)) * (15731 * (n ^ (n << 13)) * (n ^ (n << 13)) + 789221) - 771171059) & 0x7FFFFFFF)
               * 9.3132257e-10);
}

// File Line: 28
// RVA: 0x15F7E0
UFG::qVector3 *__fastcall UFG::NoiseRandom<UFG::qVector3>(UFG::qVector3 *result, int n)
{
  signed int v2; // r8d
  unsigned int v3; // r11d
  signed int v4; // r9d
  unsigned int v5; // r10d
  unsigned int v6; // edx
  UFG::qVector3 *v7; // rax

  v2 = n ^ 0x1D872B41 ^ n ^ 0x1D872B41 ^ ((n ^ 0x1D872B41u) >> 5) ^ ((n ^ 0x1D872B41 ^ ((n ^ 0x1D872B41u) >> 5)) << 27);
  v3 = ((n % 0x7FFFFFFF + 0x7FFFFFFF) % 0x7FFFFFFFu) ^ (((n % 0x7FFFFFFF + 0x7FFFFFFF) % 0x7FFFFFFFu) << 13);
  v4 = v2 ^ 0x1D872B41 ^ v2 ^ 0x1D872B41 ^ ((v2 ^ 0x1D872B41u) >> 5) ^ ((v2 ^ 0x1D872B41 ^ ((v2 ^ 0x1D872B41u) >> 5)) << 27);
  v5 = ((v2 % 0x7FFFFFFF + 0x7FFFFFFF) % 0x7FFFFFFFu) ^ (((v2 % 0x7FFFFFFF + 0x7FFFFFFF) % 0x7FFFFFFFu) << 13);
  v6 = ((v4 + 0x7FFFFFFF * (1 - v4 / 0x7FFFFFFF)) % 0x7FFFFFFFu) ^ (((v4 + 0x7FFFFFFF * (1 - v4 / 0x7FFFFFFF))
                                                                   % 0x7FFFFFFFu) << 13);
  result->x = 1.0 - (float)((float)((v3 * (15731 * v3 * v3 + 789221) - 771171059) & 0x7FFFFFFF) * 9.3132257e-10);
  result->y = 1.0 - (float)((float)((v5 * (15731 * v5 * v5 + 789221) - 771171059) & 0x7FFFFFFF) * 9.3132257e-10);
  v7 = result;
  result->z = 1.0 - (float)((float)((v6 * (15731 * v6 * v6 + 789221) - 771171059) & 0x7FFFFFFF) * 9.3132257e-10);
  return v7;
}

// File Line: 47
// RVA: 0x15F9B0
__int64 __fastcall UFG::NoiseSeed<float>(const float *x)
{
  return (unsigned int)(int)*x;
}

// File Line: 60
// RVA: 0x15F9C0
__int64 __fastcall UFG::NoiseSeed<UFG::qVector3>(UFG::qVector3 *v)
{
  return (unsigned int)((int)v->x * (int)v->y * (int)v->z - 1);
}

