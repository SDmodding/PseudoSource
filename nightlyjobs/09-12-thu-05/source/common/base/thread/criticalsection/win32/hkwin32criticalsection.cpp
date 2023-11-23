// File Line: 21
// RVA: 0xC754F0
void __fastcall hkCriticalSection::hkCriticalSection(hkCriticalSection *this, DWORD spinCount)
{
  hkHardwareInfo info; // [rsp+38h] [rbp+10h] BYREF

  if ( !spinCount )
  {
    hkGetHardwareInfo(&info);
    spinCount = 1000 * info.m_numThreads;
  }
  InitializeCriticalSectionAndSpinCount(&this->m_section, spinCount);
}

