// File Line: 22
// RVA: 0x159CD20
void Scaleform::Alg::_dynamic_initializer_for__Generator_1__()
{
  unsigned int Time; // eax
  unsigned int v1; // edx

  Time = timeGetTime();
  v1 = Time;
  if ( TimerOverrideInstance )
    v1 = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, Time);
  Scaleform::Alg::Random::Generator::SeedRandom(&Generator_1, v1);
}

// File Line: 25
// RVA: 0x99C4D0
__int64 __fastcall Scaleform::Alg::Random::NextRandom()
{
  __int64 v0; // rax
  unsigned int *v1; // r8
  unsigned int v2; // ecx
  unsigned __int64 v3; // rax
  int v4; // edx
  __int64 result; // rax

  v0 = (LOBYTE(Generator_1.I) + 1) & 7;
  Generator_1.I = (LOBYTE(Generator_1.I) + 1) & 7;
  v1 = &Generator_1.Q[v0];
  v2 = Generator_1.C + 716514398 * *v1;
  v3 = (Generator_1.C + 716514398 * (unsigned __int64)*v1) >> 32;
  Generator_1.C = v3;
  v4 = v3 + v2;
  if ( (unsigned int)v3 + v2 < (unsigned int)v3 )
  {
    ++v4;
    Generator_1.C = v3 + 1;
  }
  result = (unsigned int)(-2 - v4);
  *v1 = result;
  return result;
}

// File Line: 84
// RVA: 0x9ADC80
void __fastcall Scaleform::Alg::Random::Generator::SeedRandom(
        Scaleform::Alg::Random::Generator *this,
        unsigned int seed)
{
  unsigned int v2; // r8d
  unsigned int v3; // r8d
  int v4; // r8d
  unsigned int v5; // r8d
  int v6; // r8d
  unsigned int v7; // r8d
  int v8; // r8d
  unsigned int v9; // r8d
  int v10; // r8d
  unsigned int v11; // r8d
  int v12; // r8d
  unsigned int v13; // r8d
  int v14; // r8d
  unsigned int v15; // r8d

  v2 = (32 * (((seed ^ (seed << 13)) >> 17) ^ seed ^ (seed << 13))) ^ ((seed ^ (seed << 13)) >> 17) ^ seed ^ (seed << 13);
  this->Q[0] = v2;
  v3 = (((v2 << 13) ^ v2) >> 17) ^ (v2 << 13) ^ v2;
  v4 = (32 * v3) ^ v3;
  this->Q[1] = v4;
  v5 = (((v4 << 13) ^ (unsigned int)v4) >> 17) ^ (v4 << 13) ^ v4;
  v6 = (32 * v5) ^ v5;
  this->Q[2] = v6;
  v7 = (((v6 << 13) ^ (unsigned int)v6) >> 17) ^ (v6 << 13) ^ v6;
  v8 = (32 * v7) ^ v7;
  this->Q[3] = v8;
  v9 = (((v8 << 13) ^ (unsigned int)v8) >> 17) ^ (v8 << 13) ^ v8;
  v10 = (32 * v9) ^ v9;
  this->Q[4] = v10;
  v11 = (((v10 << 13) ^ (unsigned int)v10) >> 17) ^ (v10 << 13) ^ v10;
  v12 = (32 * v11) ^ v11;
  this->Q[5] = v12;
  v13 = (((v12 << 13) ^ (unsigned int)v12) >> 17) ^ (v12 << 13) ^ v12;
  v14 = (32 * v13) ^ v13;
  this->Q[6] = v14;
  v15 = (((v14 << 13) ^ (unsigned int)v14) >> 17) ^ (v14 << 13) ^ v14;
  this->Q[7] = v15 ^ (32 * v15);
  this->C = 362436;
  this->I = 7;
}

