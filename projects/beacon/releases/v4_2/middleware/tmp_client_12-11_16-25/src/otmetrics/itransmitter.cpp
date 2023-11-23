// File Line: 13
// RVA: 0xEC3510
void __fastcall OSuite::ITransmitter::ITransmitter(OSuite::ITransmitter *this)
{
  OSuite::ZClock *p_m_lastTransmitTime; // rcx
  unsigned __int64 clock; // [rsp+30h] [rbp+8h] BYREF

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ITransmitter::`vftable;
  p_m_lastTransmitTime = &this->m_lastTransmitTime;
  p_m_lastTransmitTime[-3].m_clock = 0i64;
  p_m_lastTransmitTime[-2].m_clock = 0i64;
  LODWORD(p_m_lastTransmitTime[-1].m_clock) = 0;
  clock = 0i64;
  OSuite::ZClock::ZClock(p_m_lastTransmitTime, &clock);
  this->m_bUsageTracking = 1;
}

// File Line: 18
// RVA: 0xEC3550
void __fastcall OSuite::ITransmitter::~ITransmitter(OSuite::ITransmitter *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ITransmitter::`vftable;
  OSuite::ZOEdmBase::CleanTempData((_DWORD)this + 32);
}

