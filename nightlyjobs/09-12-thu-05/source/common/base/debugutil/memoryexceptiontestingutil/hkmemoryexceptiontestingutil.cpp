// File Line: 22
// RVA: 0x12FE390
void __fastcall hkSetOutOfMemoryState(hkMemoryAllocator::MemoryState state)
{
  hkOutOfMemoryState = state;
}

// File Line: 41
// RVA: 0x12FE3A0
void __fastcall hkMemoryExceptionTestingUtil::hkMemoryExceptionTestingUtil(hkMemoryExceptionTestingUtil *this)
{
  this->m_frameCounter = 0;
  this->m_outOfMemory = 0;
  this->m_allowMemoryExceptions = 0;
}

// File Line: 49
// RVA: 0x12FE3C0
void __fastcall hkMemoryExceptionTestingUtil::~hkMemoryExceptionTestingUtil(hkMemoryExceptionTestingUtil *this)
{
  ;
}

// File Line: 54
// RVA: 0x12FE3D0
void hkMemoryExceptionTestingUtil::create(void)
{
  hkMemoryExceptionTestingUtil *v0; // rbx
  _QWORD **Value; // rax
  _QWORD **v2; // rax
  hkMemoryExceptionTestingUtil *v3; // rax
  hkMemoryExceptionTestingUtil *v4; // rax

  v0 = hkMemoryExceptionTestingUtil::s_instance;
  if ( hkMemoryExceptionTestingUtil::s_instance )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkMemoryExceptionTestingUtil *, __int64))(*Value[11] + 16i64))(
      Value[11],
      v0,
      60i64);
  }
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkMemoryExceptionTestingUtil *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v2[11] + 8i64))(v2[11], 60i64);
  if ( v3 )
  {
    hkMemoryExceptionTestingUtil::hkMemoryExceptionTestingUtil(v3);
    hkMemoryExceptionTestingUtil::s_instance = v4;
  }
  else
  {
    hkMemoryExceptionTestingUtil::s_instance = 0i64;
  }
}

// File Line: 60
// RVA: 0x12FE450
void hkMemoryExceptionTestingUtil::destroy(void)
{
  hkMemoryExceptionTestingUtil *v0; // rbx
  _QWORD **Value; // rax

  v0 = hkMemoryExceptionTestingUtil::s_instance;
  if ( hkMemoryExceptionTestingUtil::s_instance )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkMemoryExceptionTestingUtil *, __int64))(*Value[11] + 16i64))(
      Value[11],
      v0,
      60i64);
  }
  hkMemoryExceptionTestingUtil::s_instance = 0i64;
}

// File Line: 66
// RVA: 0x12FE4A0
hkMemoryExceptionTestingUtil *__fastcall hkMemoryExceptionTestingUtil::getInstance()
{
  return hkMemoryExceptionTestingUtil::s_instance;
}

// File Line: 71
// RVA: 0x12FE4B0
void __fastcall hkMemoryExceptionTestingUtil::startNewDemoImpl(hkMemoryExceptionTestingUtil *this)
{
  this->m_frameCounter = 0;
  *(_QWORD *)this->m_wasCheckIdThrown = 0i64;
  *(_QWORD *)&this->m_wasCheckIdThrown[8] = 0i64;
  *(_QWORD *)&this->m_wasCheckIdThrown[16] = 0i64;
  *(_QWORD *)&this->m_wasCheckIdThrown[24] = 0i64;
  *(_QWORD *)&this->m_wasCheckIdThrown[32] = 0i64;
  *(_QWORD *)&this->m_wasCheckIdThrown[40] = 0i64;
  *(_WORD *)&this->m_wasCheckIdThrown[48] = 0;
}

// File Line: 83
// RVA: 0x12FE4E0
void __fastcall hkMemoryExceptionTestingUtil::startFrameImpl(hkMemoryExceptionTestingUtil *this)
{
  ++this->m_frameCounter;
  this->m_outOfMemory = 0;
}

// File Line: 92
// RVA: 0x12FE4F0
void __fastcall hkMemoryExceptionTestingUtil::endFrameImpl(hkMemoryExceptionTestingUtil *this)
{
  ;
}

// File Line: 97
// RVA: 0x12FE500
void __fastcall hkMemoryExceptionTestingUtil::allowMemoryExceptionsImpl(
        hkMemoryExceptionTestingUtil *this,
        bool allowMemExceptions)
{
  this->m_allowMemoryExceptions = allowMemExceptions;
}

// File Line: 102
// RVA: 0x12FE510
char __fastcall hkMemoryExceptionTestingUtil::isMemoryAvailableImpl(hkMemoryExceptionTestingUtil *this, int id)
{
  int m_frameCounter; // r8d

  if ( this->m_outOfMemory && this->m_allowMemoryExceptions )
    return 0;
  m_frameCounter = this->m_frameCounter;
  if ( m_frameCounter > 50
    && m_frameCounter == 3 * (m_frameCounter / 3)
    && this->m_allowMemoryExceptions
    && !this->m_wasCheckIdThrown[id] )
  {
    this->m_wasCheckIdThrown[id] = 1;
    this->m_outOfMemory = 1;
    return 0;
  }
  return 1;
}

