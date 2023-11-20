// File Line: 41
// RVA: 0xEE9AE8
void __fastcall OSuite::ZEvent::ZEvent(OSuite::ZEvent *this, bool bManualReset)
{
  this->m_bManualReset = bManualReset;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZEvent::`vftable';
  this->m_event = CreateEventA(0i64, bManualReset != 0, 0, 0i64);
}

// File Line: 75
// RVA: 0xEE9B24
void __fastcall OSuite::ZEvent::~ZEvent(OSuite::ZEvent *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZEvent::`vftable';
  CloseHandle(this->m_event);
}

// File Line: 96
// RVA: 0xEE9B7C
void __fastcall OSuite::ZEvent::Signal(OSuite::ZEvent *this)
{
  SetEvent(this->m_event);
}

// File Line: 144
// RVA: 0xEE9B88
void __fastcall OSuite::ZEvent::Wait(OSuite::ZEvent *this, int nTimeoutInUsec)
{
  int v2; // edx

  if ( nTimeoutInUsec )
    v2 = nTimeoutInUsec / 1000;
  else
    v2 = -1;
  WaitForSingleObject(this->m_event, v2);
}

