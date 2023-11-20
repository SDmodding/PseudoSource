// File Line: 17
// RVA: 0x15CC930
__int64 dynamic_initializer_for__hkNullAgentInstance__()
{
  hkpNullAgent::hkpNullAgent(&hkNullAgentInstance);
  return atexit(dynamic_atexit_destructor_for__hkNullAgentInstance__);
}

// File Line: 21
// RVA: 0xD095F0
void __fastcall hkpNullAgent::hkpNullAgent(hkpNullAgent *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_contactMgr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpNullAgent::`vftable;
}

// File Line: 25
// RVA: 0xD09620
void __fastcall hkpNullAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  ;
}

// File Line: 33
// RVA: 0xD09630
void __fastcall hkpNullAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  ;
}

// File Line: 41
// RVA: 0xD09640
void __fastcall hkpNullAgent::staticLinearCast(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector)
{
  ;
}

// File Line: 50
// RVA: 0xD09650
hkpNullAgent *__fastcall hkpNullAgent::createNullAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  return &hkNullAgentInstance;
}

// File Line: 59
// RVA: 0xD09660
hkpNullAgent *__fastcall hkpNullAgent::getNullAgent()
{
  return &hkNullAgentInstance;
}

