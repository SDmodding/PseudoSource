// File Line: 25
// RVA: 0xD76040
void __fastcall hkpAddModifierUtil::setInvMassScalingForContact(
        hkpContactPointEvent *event,
        hkpRigidBody *bodyA,
        hkpRigidBody *bodyB,
        hkVector4f *factorA,
        hkVector4f *factorB)
{
  hkpSimulationIsland *m_simulationIsland; // r15
  unsigned int m_threadId; // ebx
  int v10; // esi
  int m_stackTraceId; // edi

  m_simulationIsland = event->m_bodies[0]->m_simulationIsland;
  if ( m_simulationIsland->m_storageIndex == 0xFFFF )
    m_simulationIsland = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    m_threadId = m_simulationIsland->m_multiThreadCheck.m_threadId;
    v10 = *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount;
    m_stackTraceId = m_simulationIsland->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&m_simulationIsland->m_multiThreadCheck);
    hkpResponseModifier::setInvMassScalingForContact(
      event->m_contactMgr,
      bodyA,
      bodyB,
      m_simulationIsland,
      factorA,
      factorB);
    m_simulationIsland->m_multiThreadCheck.m_threadId = m_threadId;
    m_simulationIsland->m_multiThreadCheck.m_stackTraceId = m_stackTraceId;
    *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount = v10;
  }
  else
  {
    hkpResponseModifier::setInvMassScalingForContact(
      event->m_contactMgr,
      bodyA,
      bodyB,
      m_simulationIsland,
      factorA,
      factorB);
  }
}

// File Line: 45
// RVA: 0xD76130
void __fastcall hkpAddModifierUtil::setInvMassScalingForContact(
        hkpContactPointEvent *event,
        hkpRigidBody *body,
        hkVector4f *factor)
{
  hkpSimulationIsland *m_simulationIsland; // r15
  unsigned int m_threadId; // ebx
  int v8; // esi
  int m_stackTraceId; // edi

  m_simulationIsland = event->m_bodies[0]->m_simulationIsland;
  if ( m_simulationIsland->m_storageIndex == 0xFFFF )
    m_simulationIsland = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    m_threadId = m_simulationIsland->m_multiThreadCheck.m_threadId;
    v8 = *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount;
    m_stackTraceId = m_simulationIsland->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&m_simulationIsland->m_multiThreadCheck);
    hkpResponseModifier::setInvMassScalingForContact(event->m_contactMgr, body, m_simulationIsland, factor);
    m_simulationIsland->m_multiThreadCheck.m_threadId = m_threadId;
    m_simulationIsland->m_multiThreadCheck.m_stackTraceId = m_stackTraceId;
    *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount = v8;
  }
  else
  {
    hkpResponseModifier::setInvMassScalingForContact(event->m_contactMgr, body, m_simulationIsland, factor);
  }
}

// File Line: 65
// RVA: 0xD76200
void __fastcall hkpAddModifierUtil::setCenterOfMassDisplacementForContact(
        hkpContactPointEvent *event,
        hkpRigidBody *bodyA,
        hkpRigidBody *bodyB,
        hkVector4f *displacementA,
        hkVector4f *displacementB)
{
  hkpSimulationIsland *m_simulationIsland; // r15
  unsigned int m_threadId; // ebx
  int v10; // esi
  int m_stackTraceId; // edi

  m_simulationIsland = event->m_bodies[0]->m_simulationIsland;
  if ( m_simulationIsland->m_storageIndex == 0xFFFF )
    m_simulationIsland = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    m_threadId = m_simulationIsland->m_multiThreadCheck.m_threadId;
    v10 = *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount;
    m_stackTraceId = m_simulationIsland->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&m_simulationIsland->m_multiThreadCheck);
    hkpResponseModifier::setCenterOfMassDisplacementForContact(
      event->m_contactMgr,
      bodyA,
      bodyB,
      m_simulationIsland,
      displacementA,
      displacementB);
    m_simulationIsland->m_multiThreadCheck.m_threadId = m_threadId;
    m_simulationIsland->m_multiThreadCheck.m_stackTraceId = m_stackTraceId;
    *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount = v10;
  }
  else
  {
    hkpResponseModifier::setCenterOfMassDisplacementForContact(
      event->m_contactMgr,
      bodyA,
      bodyB,
      m_simulationIsland,
      displacementA,
      displacementB);
  }
}

// File Line: 85
// RVA: 0xD762F0
void __fastcall hkpAddModifierUtil::setImpulseScalingForContact(
        hkpContactPointEvent *event,
        hkpRigidBody *bodyA,
        hkpRigidBody *bodyB,
        float usedImpulseFraction,
        float maxAcceleration)
{
  hkpSimulationIsland *m_simulationIsland; // r15
  unsigned int m_threadId; // ebx
  int v10; // esi
  int m_stackTraceId; // edi

  m_simulationIsland = event->m_bodies[0]->m_simulationIsland;
  if ( m_simulationIsland->m_storageIndex == 0xFFFF )
    m_simulationIsland = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    m_threadId = m_simulationIsland->m_multiThreadCheck.m_threadId;
    v10 = *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount;
    m_stackTraceId = m_simulationIsland->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&m_simulationIsland->m_multiThreadCheck);
    hkpResponseModifier::setImpulseScalingForContact(
      event->m_contactMgr,
      bodyA,
      bodyB,
      m_simulationIsland,
      usedImpulseFraction,
      maxAcceleration);
    m_simulationIsland->m_multiThreadCheck.m_threadId = m_threadId;
    m_simulationIsland->m_multiThreadCheck.m_stackTraceId = m_stackTraceId;
    *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount = v10;
  }
  else
  {
    hkpResponseModifier::setImpulseScalingForContact(
      event->m_contactMgr,
      bodyA,
      bodyB,
      m_simulationIsland,
      usedImpulseFraction,
      maxAcceleration);
  }
}

// File Line: 104
// RVA: 0xD76400
void __fastcall hkpAddModifierUtil::setSurfaceVelocity(
        hkpContactPointEvent *event,
        hkpRigidBody *body,
        hkVector4f *velWorld)
{
  hkpSimulationIsland *m_simulationIsland; // r15
  unsigned int m_threadId; // ebx
  int v8; // esi
  int m_stackTraceId; // edi

  m_simulationIsland = event->m_bodies[0]->m_simulationIsland;
  if ( m_simulationIsland->m_storageIndex == 0xFFFF )
    m_simulationIsland = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    m_threadId = m_simulationIsland->m_multiThreadCheck.m_threadId;
    v8 = *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount;
    m_stackTraceId = m_simulationIsland->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&m_simulationIsland->m_multiThreadCheck);
    hkpResponseModifier::setSurfaceVelocity(event->m_contactMgr, body, m_simulationIsland, velWorld);
    m_simulationIsland->m_multiThreadCheck.m_threadId = m_threadId;
    m_simulationIsland->m_multiThreadCheck.m_stackTraceId = m_stackTraceId;
    *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount = v8;
  }
  else
  {
    hkpResponseModifier::setSurfaceVelocity(event->m_contactMgr, body, m_simulationIsland, velWorld);
  }
}

// File Line: 124
// RVA: 0xD764D0
void __fastcall hkpAddModifierUtil::clearSurfaceVelocity(hkpContactPointEvent *event, hkpRigidBody *body)
{
  hkpSimulationIsland *m_simulationIsland; // r15
  unsigned int m_threadId; // ebx
  int v6; // esi
  int m_stackTraceId; // edi

  m_simulationIsland = event->m_bodies[0]->m_simulationIsland;
  if ( m_simulationIsland->m_storageIndex == 0xFFFF )
    m_simulationIsland = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    m_threadId = m_simulationIsland->m_multiThreadCheck.m_threadId;
    v6 = *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount;
    m_stackTraceId = m_simulationIsland->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&m_simulationIsland->m_multiThreadCheck);
    hkpResponseModifier::clearSurfaceVelocity(event->m_contactMgr, m_simulationIsland, body);
    m_simulationIsland->m_multiThreadCheck.m_threadId = m_threadId;
    m_simulationIsland->m_multiThreadCheck.m_stackTraceId = m_stackTraceId;
    *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount = v6;
  }
  else
  {
    hkpResponseModifier::clearSurfaceVelocity(event->m_contactMgr, m_simulationIsland, body);
  }
}

// File Line: 144
// RVA: 0xD76590
void __fastcall hkpAddModifierUtil::setLowSurfaceViscosity(hkpContactPointEvent *event)
{
  hkpSimulationIsland *m_simulationIsland; // r15
  unsigned int m_threadId; // ebx
  int v4; // esi
  int m_stackTraceId; // edi

  m_simulationIsland = event->m_bodies[0]->m_simulationIsland;
  if ( m_simulationIsland->m_storageIndex == 0xFFFF )
    m_simulationIsland = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    m_threadId = m_simulationIsland->m_multiThreadCheck.m_threadId;
    v4 = *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount;
    m_stackTraceId = m_simulationIsland->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&m_simulationIsland->m_multiThreadCheck);
    hkpResponseModifier::setLowSurfaceViscosity(event->m_contactMgr, m_simulationIsland);
    m_simulationIsland->m_multiThreadCheck.m_threadId = m_threadId;
    m_simulationIsland->m_multiThreadCheck.m_stackTraceId = m_stackTraceId;
    *(_DWORD *)&m_simulationIsland->m_multiThreadCheck.m_markCount = v4;
  }
  else
  {
    hkpResponseModifier::setLowSurfaceViscosity(event->m_contactMgr, m_simulationIsland);
  }
}

