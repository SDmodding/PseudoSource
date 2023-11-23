// File Line: 16
// RVA: 0xD8BD00
void __fastcall hkpCollisionCallbackUtil::performAttachments(hkpCollisionCallbackUtil *this, hkpWorld *world)
{
  hkpWorldPostSimulationListener *v2; // rdi
  hkpConstraintListener *v5; // rdx

  v2 = 0i64;
  v5 = &this->hkpConstraintListener;
  if ( !this )
    v5 = 0i64;
  hkpWorld::addConstraintListener(world, v5);
  if ( this != (hkpCollisionCallbackUtil *)-40i64 )
    v2 = &this->m_endOfStepCallbackUtil.hkpWorldPostSimulationListener;
  hkpWorld::addWorldPostSimulationListener(world, v2);
}

// File Line: 22
// RVA: 0xD8BD60
void __fastcall hkpCollisionCallbackUtil::performDetachments(hkpCollisionCallbackUtil *this, hkpWorld *world)
{
  hkpConstraintListener *v2; // rdi
  hkpWorldPostSimulationListener *v5; // rdx

  v2 = 0i64;
  v5 = &this->m_endOfStepCallbackUtil.hkpWorldPostSimulationListener;
  if ( this == (hkpCollisionCallbackUtil *)-40i64 )
    v5 = 0i64;
  hkpWorld::removeWorldPostSimulationListener(world, v5);
  if ( this )
    v2 = &this->hkpConstraintListener;
  hkpWorld::removeConstraintListener(world, v2);
}

// File Line: 28
// RVA: 0xD8BDC0
void __fastcall hkpCollisionCallbackUtil::constraintAddedCallback(
        hkpCollisionCallbackUtil *this,
        hkpConstraintInstance *constraint)
{
  unsigned __int64 v3; // rdx
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  hkpSimpleContactConstraintData *m_data; // rbx
  hkpSimpleConstraintContactMgr *SimpleConstraintContactMgr; // rax
  hkpRigidBody *v10; // rbx
  hkpRigidBody *v11; // rdi
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  hkpCollisionEvent event; // [rsp+20h] [rbp-28h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtCollLtUtil";
    v6 = __rdtsc();
    v3 = (unsigned __int64)HIDWORD(v6) << 32;
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  m_data = (hkpSimpleContactConstraintData *)constraint->m_data;
  if ( ((unsigned int (__fastcall *)(hkpSimpleContactConstraintData *, unsigned __int64, LPVOID))m_data->vfptr[1].__first_virtual_table_function__)(
         m_data,
         v3,
         Value) == 11 )
  {
    SimpleConstraintContactMgr = hkpSimpleContactConstraintData::getSimpleConstraintContactMgr(m_data);
    v10 = (hkpRigidBody *)constraint->m_entities[0];
    v11 = (hkpRigidBody *)constraint->m_entities[1];
    event.m_bodies[1] = v11;
    event.m_source = SOURCE_WORLD;
    event.m_contactMgr = SimpleConstraintContactMgr;
    event.m_bodies[0] = v10;
    hkpWorldCallbackUtil::fireContactConstraintAddedCallback(v10->m_world, &event);
    event.m_source = SOURCE_A;
    hkpEntityCallbackUtil::fireContactConstraintAddedCallback(v10, &event);
    event.m_source = SOURCE_B;
    hkpEntityCallbackUtil::fireContactConstraintAddedCallback(v11, &event);
  }
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "Et";
    v14 = __rdtsc();
    v15 = v13 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v12[1] = v15;
  }
}

// File Line: 51
// RVA: 0xD8BEC0
void __fastcall hkpCollisionCallbackUtil::constraintRemovedCallback(
        hkpCollisionCallbackUtil *this,
        hkpConstraintInstance *constraint)
{
  unsigned __int64 v3; // rdx
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  hkpSimpleContactConstraintData *m_data; // rbx
  hkpSimpleConstraintContactMgr *SimpleConstraintContactMgr; // rax
  hkpRigidBody *v10; // rbx
  hkpRigidBody *v11; // rdi
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  hkpCollisionEvent event; // [rsp+20h] [rbp-28h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtCollLfUtil";
    v6 = __rdtsc();
    v3 = (unsigned __int64)HIDWORD(v6) << 32;
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  m_data = (hkpSimpleContactConstraintData *)constraint->m_data;
  if ( ((unsigned int (__fastcall *)(hkpSimpleContactConstraintData *, unsigned __int64, LPVOID))m_data->vfptr[1].__first_virtual_table_function__)(
         m_data,
         v3,
         Value) == 11 )
  {
    SimpleConstraintContactMgr = hkpSimpleContactConstraintData::getSimpleConstraintContactMgr(m_data);
    v10 = (hkpRigidBody *)constraint->m_entities[0];
    v11 = (hkpRigidBody *)constraint->m_entities[1];
    event.m_bodies[1] = v11;
    event.m_source = SOURCE_WORLD;
    event.m_contactMgr = SimpleConstraintContactMgr;
    event.m_bodies[0] = v10;
    hkpWorldCallbackUtil::fireContactConstraintRemovedCallback(v10->m_world, &event);
    event.m_source = SOURCE_A;
    hkpEntityCallbackUtil::fireContactConstraintRemovedCallback(v10, &event);
    event.m_source = SOURCE_B;
    hkpEntityCallbackUtil::fireContactConstraintRemovedCallback(v11, &event);
  }
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "Et";
    v14 = __rdtsc();
    v15 = v13 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v12[1] = v15;
  }
}

