// File Line: 25
// RVA: 0xD76040
void __fastcall hkpAddModifierUtil::setInvMassScalingForContact(hkpContactPointEvent *event, hkpRigidBody *bodyA, hkpRigidBody *bodyB, hkVector4f *factorA, hkVector4f *factorB)
{
  hkVector4f *v5; // r12
  hkpRigidBody *v6; // r13
  hkpSimulationIsland *v7; // r15
  hkpContactPointEvent *v8; // rbp
  unsigned int v9; // ebx
  int v10; // esi
  int v11; // edi
  hkpRigidBody *bodyAa; // [rsp+68h] [rbp+10h]

  bodyAa = bodyA;
  v5 = factorA;
  v6 = bodyB;
  v7 = event->m_bodies[0]->m_simulationIsland;
  v8 = event;
  if ( v7->m_storageIndex == -1 )
    v7 = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    v9 = v7->m_multiThreadCheck.m_threadId;
    v10 = *(_DWORD *)&v7->m_multiThreadCheck.m_markCount;
    v11 = v7->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&v7->m_multiThreadCheck);
    hkpResponseModifier::setInvMassScalingForContact(
      (hkpDynamicsContactMgr *)&v8->m_contactMgr->vfptr,
      bodyAa,
      v6,
      (hkpConstraintOwner *)&v7->vfptr,
      v5,
      factorB);
    v7->m_multiThreadCheck.m_threadId = v9;
    v7->m_multiThreadCheck.m_stackTraceId = v11;
    *(_DWORD *)&v7->m_multiThreadCheck.m_markCount = v10;
  }
  else
  {
    hkpResponseModifier::setInvMassScalingForContact(
      (hkpDynamicsContactMgr *)&event->m_contactMgr->vfptr,
      bodyA,
      bodyB,
      (hkpConstraintOwner *)&v7->vfptr,
      factorA,
      factorB);
  }
}

// File Line: 45
// RVA: 0xD76130
void __fastcall hkpAddModifierUtil::setInvMassScalingForContact(hkpContactPointEvent *event, hkpRigidBody *body, hkVector4f *factor)
{
  hkVector4f *v3; // r12
  hkpRigidBody *v4; // r13
  hkpSimulationIsland *v5; // r15
  hkpContactPointEvent *v6; // rbp
  unsigned int v7; // ebx
  int v8; // esi
  int v9; // edi

  v3 = factor;
  v4 = body;
  v5 = event->m_bodies[0]->m_simulationIsland;
  v6 = event;
  if ( v5->m_storageIndex == -1 )
    v5 = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    v7 = v5->m_multiThreadCheck.m_threadId;
    v8 = *(_DWORD *)&v5->m_multiThreadCheck.m_markCount;
    v9 = v5->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&v5->m_multiThreadCheck);
    hkpResponseModifier::setInvMassScalingForContact(
      (hkpDynamicsContactMgr *)&v6->m_contactMgr->vfptr,
      v4,
      (hkpConstraintOwner *)&v5->vfptr,
      v3);
    v5->m_multiThreadCheck.m_threadId = v7;
    v5->m_multiThreadCheck.m_stackTraceId = v9;
    *(_DWORD *)&v5->m_multiThreadCheck.m_markCount = v8;
  }
  else
  {
    hkpResponseModifier::setInvMassScalingForContact(
      (hkpDynamicsContactMgr *)&event->m_contactMgr->vfptr,
      body,
      (hkpConstraintOwner *)&v5->vfptr,
      factor);
  }
}

// File Line: 65
// RVA: 0xD76200
void __fastcall hkpAddModifierUtil::setCenterOfMassDisplacementForContact(hkpContactPointEvent *event, hkpRigidBody *bodyA, hkpRigidBody *bodyB, hkVector4f *displacementA, hkVector4f *displacementB)
{
  hkVector4f *v5; // r12
  hkpRigidBody *v6; // r13
  hkpSimulationIsland *v7; // r15
  hkpContactPointEvent *v8; // rbp
  unsigned int v9; // ebx
  int v10; // esi
  int v11; // edi
  hkpRigidBody *bodyAa; // [rsp+68h] [rbp+10h]

  bodyAa = bodyA;
  v5 = displacementA;
  v6 = bodyB;
  v7 = event->m_bodies[0]->m_simulationIsland;
  v8 = event;
  if ( v7->m_storageIndex == -1 )
    v7 = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    v9 = v7->m_multiThreadCheck.m_threadId;
    v10 = *(_DWORD *)&v7->m_multiThreadCheck.m_markCount;
    v11 = v7->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&v7->m_multiThreadCheck);
    hkpResponseModifier::setCenterOfMassDisplacementForContact(
      (hkpDynamicsContactMgr *)&v8->m_contactMgr->vfptr,
      bodyAa,
      v6,
      (hkpConstraintOwner *)&v7->vfptr,
      v5,
      displacementB);
    v7->m_multiThreadCheck.m_threadId = v9;
    v7->m_multiThreadCheck.m_stackTraceId = v11;
    *(_DWORD *)&v7->m_multiThreadCheck.m_markCount = v10;
  }
  else
  {
    hkpResponseModifier::setCenterOfMassDisplacementForContact(
      (hkpDynamicsContactMgr *)&event->m_contactMgr->vfptr,
      bodyA,
      bodyB,
      (hkpConstraintOwner *)&v7->vfptr,
      displacementA,
      displacementB);
  }
}

// File Line: 85
// RVA: 0xD762F0
void __fastcall hkpAddModifierUtil::setImpulseScalingForContact(hkpContactPointEvent *event, hkpRigidBody *bodyA, hkpRigidBody *bodyB, float usedImpulseFraction, float maxAcceleration)
{
  hkpRigidBody *v5; // r12
  hkpSimulationIsland *v6; // r15
  hkpRigidBody *v7; // r13
  hkpContactPointEvent *v8; // rbp
  unsigned int v9; // ebx
  int v10; // esi
  int v11; // edi

  v5 = bodyB;
  v6 = event->m_bodies[0]->m_simulationIsland;
  v7 = bodyA;
  v8 = event;
  if ( v6->m_storageIndex == -1 )
    v6 = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    v9 = v6->m_multiThreadCheck.m_threadId;
    v10 = *(_DWORD *)&v6->m_multiThreadCheck.m_markCount;
    v11 = v6->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&v6->m_multiThreadCheck);
    hkpResponseModifier::setImpulseScalingForContact(
      (hkpDynamicsContactMgr *)&v8->m_contactMgr->vfptr,
      v7,
      v5,
      (hkpConstraintOwner *)&v6->vfptr,
      usedImpulseFraction,
      maxAcceleration);
    v6->m_multiThreadCheck.m_threadId = v9;
    v6->m_multiThreadCheck.m_stackTraceId = v11;
    *(_DWORD *)&v6->m_multiThreadCheck.m_markCount = v10;
  }
  else
  {
    hkpResponseModifier::setImpulseScalingForContact(
      (hkpDynamicsContactMgr *)&event->m_contactMgr->vfptr,
      bodyA,
      bodyB,
      (hkpConstraintOwner *)&v6->vfptr,
      usedImpulseFraction,
      maxAcceleration);
  }
}

// File Line: 104
// RVA: 0xD76400
void __fastcall hkpAddModifierUtil::setSurfaceVelocity(hkpContactPointEvent *event, hkpRigidBody *body, hkVector4f *velWorld)
{
  hkVector4f *v3; // r12
  hkpRigidBody *v4; // r13
  hkpSimulationIsland *v5; // r15
  hkpContactPointEvent *v6; // rbp
  unsigned int v7; // ebx
  int v8; // esi
  int v9; // edi

  v3 = velWorld;
  v4 = body;
  v5 = event->m_bodies[0]->m_simulationIsland;
  v6 = event;
  if ( v5->m_storageIndex == -1 )
    v5 = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    v7 = v5->m_multiThreadCheck.m_threadId;
    v8 = *(_DWORD *)&v5->m_multiThreadCheck.m_markCount;
    v9 = v5->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&v5->m_multiThreadCheck);
    hkpResponseModifier::setSurfaceVelocity(
      (hkpDynamicsContactMgr *)&v6->m_contactMgr->vfptr,
      v4,
      (hkpConstraintOwner *)&v5->vfptr,
      v3);
    v5->m_multiThreadCheck.m_threadId = v7;
    v5->m_multiThreadCheck.m_stackTraceId = v9;
    *(_DWORD *)&v5->m_multiThreadCheck.m_markCount = v8;
  }
  else
  {
    hkpResponseModifier::setSurfaceVelocity(
      (hkpDynamicsContactMgr *)&event->m_contactMgr->vfptr,
      body,
      (hkpConstraintOwner *)&v5->vfptr,
      velWorld);
  }
}

// File Line: 124
// RVA: 0xD764D0
void __fastcall hkpAddModifierUtil::clearSurfaceVelocity(hkpContactPointEvent *event, hkpRigidBody *body)
{
  hkpRigidBody *v2; // r12
  hkpContactPointEvent *v3; // rbp
  hkpSimulationIsland *v4; // r15
  unsigned int v5; // ebx
  int v6; // esi
  int v7; // edi

  v2 = body;
  v3 = event;
  v4 = event->m_bodies[0]->m_simulationIsland;
  if ( v4->m_storageIndex == -1 )
    v4 = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    v5 = v4->m_multiThreadCheck.m_threadId;
    v6 = *(_DWORD *)&v4->m_multiThreadCheck.m_markCount;
    v7 = v4->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&v4->m_multiThreadCheck);
    hkpResponseModifier::clearSurfaceVelocity(
      (hkpDynamicsContactMgr *)&v3->m_contactMgr->vfptr,
      (hkpConstraintOwner *)&v4->vfptr,
      v2);
    v4->m_multiThreadCheck.m_threadId = v5;
    v4->m_multiThreadCheck.m_stackTraceId = v7;
    *(_DWORD *)&v4->m_multiThreadCheck.m_markCount = v6;
  }
  else
  {
    hkpResponseModifier::clearSurfaceVelocity(
      (hkpDynamicsContactMgr *)&event->m_contactMgr->vfptr,
      (hkpConstraintOwner *)&v4->vfptr,
      body);
  }
}

// File Line: 144
// RVA: 0xD76590
void __fastcall hkpAddModifierUtil::setLowSurfaceViscosity(hkpContactPointEvent *event)
{
  hkpContactPointEvent *v1; // rbp
  hkpSimulationIsland *v2; // r15
  unsigned int v3; // ebx
  int v4; // esi
  int v5; // edi

  v1 = event;
  v2 = event->m_bodies[0]->m_simulationIsland;
  if ( v2->m_storageIndex == -1 )
    v2 = event->m_bodies[1]->m_simulationIsland;
  if ( event->m_type == 2 )
  {
    v3 = v2->m_multiThreadCheck.m_threadId;
    v4 = *(_DWORD *)&v2->m_multiThreadCheck.m_markCount;
    v5 = v2->m_multiThreadCheck.m_stackTraceId;
    hkMultiThreadCheck::disableChecks(&v2->m_multiThreadCheck);
    hkpResponseModifier::setLowSurfaceViscosity(
      (hkpDynamicsContactMgr *)&v1->m_contactMgr->vfptr,
      (hkpConstraintOwner *)&v2->vfptr);
    v2->m_multiThreadCheck.m_threadId = v3;
    v2->m_multiThreadCheck.m_stackTraceId = v5;
    *(_DWORD *)&v2->m_multiThreadCheck.m_markCount = v4;
  }
  else
  {
    hkpResponseModifier::setLowSurfaceViscosity(
      (hkpDynamicsContactMgr *)&event->m_contactMgr->vfptr,
      (hkpConstraintOwner *)&v2->vfptr);
  }
}

