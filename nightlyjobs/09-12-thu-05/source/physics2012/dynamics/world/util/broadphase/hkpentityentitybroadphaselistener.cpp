// File Line: 24
// RVA: 0xD7D5F0
void __fastcall hkpEntityEntityBroadPhaseListener::hkpEntityEntityBroadPhaseListener(
        hkpEntityEntityBroadPhaseListener *this,
        hkpWorld *world)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_world = world;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpEntityEntityBroadPhaseListener::`vftable{for `hkReferencedObject};
  this->hkpBroadPhaseListener::vfptr = (hkpBroadPhaseListenerVtbl *)&hkpEntityEntityBroadPhaseListener::`vftable{for `hkpBroadPhaseListener};
}

// File Line: 29
// RVA: 0xD7D620
void __fastcall hkpEntityEntityBroadPhaseListener::addCollisionPair(
        hkpEntityEntityBroadPhaseListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  hkpLinkedCollidable *v2; // r11
  hkpLinkedCollidable *v3; // rdx
  hkpProcessCollisionInput *v4; // r8
  char v5; // al

  v2 = (hkpLinkedCollidable *)((char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  v3 = (hkpLinkedCollidable *)((char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  v4 = *(hkpProcessCollisionInput **)(*(_QWORD *)&this->m_memSizeAndFlags + 184i64);
  v5 = v4->m_dispatcher.m_storage->m_collisionQualityTable[v2->m_broadPhaseHandle.m_objectQualityType][v3->m_broadPhaseHandle.m_objectQualityType];
  if ( v5 )
  {
    v4->m_createPredictiveAgents.m_storage = v4->m_dispatcher.m_storage->m_collisionQualityInfo[(__int64)v5].m_useContinuousPhysics.m_storage;
    hkpWorldAgentUtil::addAgent(v2, v3, v4);
  }
}

// File Line: 64
// RVA: 0xD7D690
void __fastcall hkpEntityEntityBroadPhaseListener::removeCollisionPair(
        hkpEntityEntityBroadPhaseListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  hkpAgentNnEntry *Agent; // rax

  Agent = hkAgentNnMachine_FindAgent(
            (hkpLinkedCollidable *)((char *)pair->m_a + SBYTE1(pair->m_a[1].m_id)),
            (hkpLinkedCollidable *)((char *)pair->m_b + SBYTE1(pair->m_b[1].m_id)));
  if ( Agent )
    hkpWorldAgentUtil::removeAgent(Agent);
}

