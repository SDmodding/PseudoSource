// File Line: 13
// RVA: 0xEC3510
void __fastcall OSuite::ITransmitter::ITransmitter(OSuite::ITransmitter *this)
{
  OSuite::ITransmitter *v1; // rbx
  OSuite::ZClock *v2; // rcx
  unsigned __int64 clock; // [rsp+30h] [rbp+8h]

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ITransmitter::`vftable';
  v2 = &this->m_lastTransmitTime;
  v2[-3].m_clock = 0i64;
  v2[-2].m_clock = 0i64;
  LODWORD(v2[-1].m_clock) = 0;
  clock = 0i64;
  OSuite::ZClock::ZClock(v2, &clock);
  v1->m_bUsageTracking = 1;
}

// File Line: 18
// RVA: 0xEC3550
void __fastcall OSuite::ITransmitter::~ITransmitter(OSuite::ITransmitter *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ITransmitter::`vftable';
  OSuite::ZOEdmBase::CleanTempData((_DWORD)this + 32);
}

