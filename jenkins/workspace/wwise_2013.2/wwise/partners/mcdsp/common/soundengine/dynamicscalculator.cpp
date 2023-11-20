// File Line: 24
// RVA: 0xB02840
void __fastcall DynamicsCalculator::CalculateAttackScalar(unsigned int sampleRate, long double attack)
{
  GetTCScalar(attack * 0.001 * (double)(signed int)sampleRate);
}

// File Line: 33
// RVA: 0xB02870
void __fastcall DynamicsCalculator::CalculateReleaseScalar(unsigned int sampleRate, long double release)
{
  GetTCScalar(release * 0.001 * (double)(signed int)sampleRate);
}

// File Line: 42
// RVA: 0xB028A0
__int64 __fastcall DynamicsCalculator::CalculateHoldSamples(unsigned int sampleRate, long double hold)
{
  return (unsigned int)(signed int)(hold * 0.001 * (double)(signed int)sampleRate);
}

