// File Line: 20
// RVA: 0xD31930
void __fastcall hkpBroadPhase::hkpBroadPhase(
        hkpBroadPhase *this,
        hkpBroadPhase::BroadPhaseType type,
        unsigned __int16 size,
        unsigned int caps)
{
  hkMultiThreadCheck *p_m_multiThreadCheck; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type = type;
  this->m_size = size;
  this->m_caps = caps;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBroadPhase::`vftable;
  p_m_multiThreadCheck = &this->m_multiThreadCheck;
  p_m_multiThreadCheck->m_threadId = -15;
  p_m_multiThreadCheck->m_markCount = 0x8000;
  this->m_criticalSection = 0i64;
  hkMultiThreadCheck::disableChecks(p_m_multiThreadCheck);
}

// File Line: 26
// RVA: 0xD31A10
void __fastcall hkpBroadPhase::enableMultiThreading(hkpBroadPhase *this, DWORD spinCountForCriticalSection)
{
  _QWORD **Value; // rax
  hkCriticalSection *v5; // rax

  if ( !this->m_criticalSection )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
    if ( v5 )
      hkCriticalSection::hkCriticalSection(v5, spinCountForCriticalSection);
    this->m_criticalSection = v5;
    hkMultiThreadCheck::enableChecks(&this->m_multiThreadCheck);
  }
}

// File Line: 35
// RVA: 0xD31990
void __fastcall hkpBroadPhase::~hkpBroadPhase(hkpBroadPhase *this)
{
  hkCriticalSection *m_criticalSection; // rdi
  _QWORD **Value; // rax

  m_criticalSection = this->m_criticalSection;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBroadPhase::`vftable;
  if ( m_criticalSection )
  {
    DeleteCriticalSection(&m_criticalSection->m_section);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_criticalSection,
      40i64);
    this->m_criticalSection = 0i64;
    this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  }
  else
  {
    this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  }
}

// File Line: 44
// RVA: 0xD31A70
void __fastcall hkpBroadPhase::lockImplementation(hkpBroadPhase *this)
{
  EnterCriticalSection(&this->m_criticalSection->m_section);
}

// File Line: 50
// RVA: 0xD31A90
void __fastcall hkpBroadPhase::unlockImplementation(hkpBroadPhase *this)
{
  LeaveCriticalSection(&this->m_criticalSection->m_section);
}

