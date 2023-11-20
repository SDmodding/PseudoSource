// File Line: 20
// RVA: 0xD31930
void __fastcall hkpBroadPhase::hkpBroadPhase(hkpBroadPhase *this, hkpBroadPhase::BroadPhaseType type, int size, int caps)
{
  hkpBroadPhase *v4; // rbx
  hkMultiThreadCheck *v5; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type = type;
  this->m_size = size;
  this->m_caps = caps;
  v4 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBroadPhase::`vftable;
  v5 = &this->m_multiThreadCheck;
  v5->m_threadId = -15;
  v5->m_markCount = -32768;
  v4->m_criticalSection = 0i64;
  hkMultiThreadCheck::disableChecks(v5);
}

// File Line: 26
// RVA: 0xD31A10
void __fastcall hkpBroadPhase::enableMultiThreading(hkpBroadPhase *this, int spinCountForCriticalSection)
{
  int v2; // edi
  hkpBroadPhase *v3; // rbx
  _QWORD **v4; // rax
  hkCriticalSection *v5; // rax

  v2 = spinCountForCriticalSection;
  v3 = this;
  if ( !this->m_criticalSection )
  {
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 40i64);
    if ( v5 )
      hkCriticalSection::hkCriticalSection(v5, v2);
    v3->m_criticalSection = v5;
    hkMultiThreadCheck::enableChecks(&v3->m_multiThreadCheck);
  }
}

// File Line: 35
// RVA: 0xD31990
void __fastcall hkpBroadPhase::~hkpBroadPhase(hkpBroadPhase *this)
{
  hkCriticalSection *v1; // rdi
  hkpBroadPhase *v2; // rbx
  _QWORD **v3; // rax

  v1 = this->m_criticalSection;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBroadPhase::`vftable;
  if ( v1 )
  {
    DeleteCriticalSection(&v1->m_section);
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, signed __int64))(*v3[11] + 16i64))(v3[11], v1, 40i64);
    v2->m_criticalSection = 0i64;
    v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
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

