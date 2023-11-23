// File Line: 24
// RVA: 0xB02840
long double __fastcall DynamicsCalculator::CalculateAttackScalar(int sampleRate, long double attack)
{
  return GetTCScalar(attack * 0.001 * (double)sampleRate);
}

// File Line: 33
// RVA: 0xB02870
long double __fastcall DynamicsCalculator::CalculateReleaseScalar(int sampleRate, long double release)
{
  return GetTCScalar(release * 0.001 * (double)sampleRate);
}

// File Line: 42
// RVA: 0xB028A0
__int64 __fastcall DynamicsCalculator::CalculateHoldSamples(int sampleRate, long double hold)
{
  return (unsigned int)(int)(hold * 0.001 * (double)sampleRate);
}

