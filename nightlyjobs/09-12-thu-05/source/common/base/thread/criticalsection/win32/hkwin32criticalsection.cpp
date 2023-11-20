// File Line: 21
// RVA: 0xC754F0
void __fastcall hkCriticalSection::hkCriticalSection(hkCriticalSection *this, int spinCount)
{
  hkCriticalSection *v2; // rbx
  hkHardwareInfo info; // [rsp+38h] [rbp+10h]

  v2 = this;
  if ( !spinCount )
  {
    hkGetHardwareInfo(&info);
    spinCount = 1000 * info.m_numThreads;
  }
  InitializeCriticalSectionAndSpinCount(&v2->m_section, spinCount);
}

