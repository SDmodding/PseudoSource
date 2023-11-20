// File Line: 16
// RVA: 0xD8BD00
void __fastcall hkpCollisionCallbackUtil::performAttachments(hkpCollisionCallbackUtil *this, hkpWorld *world)
{
  hkpWorldPostSimulationListener *v2; // rdi
  hkpWorld *v3; // rsi
  hkpCollisionCallbackUtil *v4; // rbx
  hkpConstraintListener *v5; // rdx

  v2 = 0i64;
  v3 = world;
  v4 = this;
  v5 = (hkpConstraintListener *)&this->vfptr;
  if ( !this )
    v5 = 0i64;
  hkpWorld::addConstraintListener(v3, v5);
  if ( v4 != (hkpCollisionCallbackUtil *)-40i64 )
    v2 = (hkpWorldPostSimulationListener *)&v4->m_endOfStepCallbackUtil.vfptr;
  hkpWorld::addWorldPostSimulationListener(v3, v2);
}

// File Line: 22
// RVA: 0xD8BD60
void __fastcall hkpCollisionCallbackUtil::performDetachments(hkpCollisionCallbackUtil *this, hkpWorld *world)
{
  hkpConstraintListener *v2; // rdi
  hkpWorld *v3; // rsi
  hkpCollisionCallbackUtil *v4; // rbx
  hkpWorldPostSimulationListener *v5; // rdx

  v2 = 0i64;
  v3 = world;
  v4 = this;
  v5 = (hkpWorldPostSimulationListener *)&this->m_endOfStepCallbackUtil.vfptr;
  if ( this == (hkpCollisionCallbackUtil *)-40i64 )
    v5 = 0i64;
  hkpWorld::removeWorldPostSimulationListener(v3, v5);
  if ( v4 )
    v2 = (hkpConstraintListener *)&v4->vfptr;
  hkpWorld::removeConstraintListener(v3, v2);
}

// File Line: 28
// RVA: 0xD8BDC0
void __fastcall hkpCollisionCallbackUtil::constraintAddedCallback(hkpCollisionCallbackUtil *this, hkpConstraintInstance *constraint)
{
  hkpConstraintInstance *v2; // rdi
  unsigned __int64 v3; // rdx
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  hkpSimpleContactConstraintData *v8; // rbx
  hkpSimpleConstraintContactMgr *v9; // rax
  hkpRigidBody *v10; // rbx
  hkpRigidBody *v11; // rdi
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  hkpCollisionEvent event; // [rsp+20h] [rbp-28h]

  v2 = constraint;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtCollLtUtil";
    v6 = __rdtsc();
    v3 = (unsigned __int64)HIDWORD(v6) << 32;
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = (hkpSimpleContactConstraintData *)v2->m_data;
  if ( ((unsigned int (__fastcall *)(hkpSimpleContactConstraintData *, unsigned __int64, LPVOID))v8->vfptr[1].__first_virtual_table_function__)(
         v8,
         v3,
         v4) == 11 )
  {
    v9 = hkpSimpleContactConstraintData::getSimpleConstraintContactMgr(v8);
    v10 = (hkpRigidBody *)v2->m_entities[0];
    v11 = (hkpRigidBody *)v2->m_entities[1];
    event.m_bodies[1] = v11;
    event.m_source = 2;
    event.m_contactMgr = v9;
    event.m_bodies[0] = v10;
    hkpWorldCallbackUtil::fireContactConstraintAddedCallback(v10->m_world, &event);
    event.m_source = 0;
    hkpEntityCallbackUtil::fireContactConstraintAddedCallback((hkpEntity *)&v10->vfptr, &event);
    event.m_source = 1;
    hkpEntityCallbackUtil::fireContactConstraintAddedCallback((hkpEntity *)&v11->vfptr, &event);
  }
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "Et";
    v14 = __rdtsc();
    v15 = (signed __int64)(v13 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v12[1] = v15;
  }
}

// File Line: 51
// RVA: 0xD8BEC0
void __fastcall hkpCollisionCallbackUtil::constraintRemovedCallback(hkpCollisionCallbackUtil *this, hkpConstraintInstance *constraint)
{
  hkpConstraintInstance *v2; // rdi
  unsigned __int64 v3; // rdx
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  hkpSimpleContactConstraintData *v8; // rbx
  hkpSimpleConstraintContactMgr *v9; // rax
  hkpRigidBody *v10; // rbx
  hkpRigidBody *v11; // rdi
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  hkpCollisionEvent event; // [rsp+20h] [rbp-28h]

  v2 = constraint;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtCollLfUtil";
    v6 = __rdtsc();
    v3 = (unsigned __int64)HIDWORD(v6) << 32;
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = (hkpSimpleContactConstraintData *)v2->m_data;
  if ( ((unsigned int (__fastcall *)(hkpSimpleContactConstraintData *, unsigned __int64, LPVOID))v8->vfptr[1].__first_virtual_table_function__)(
         v8,
         v3,
         v4) == 11 )
  {
    v9 = hkpSimpleContactConstraintData::getSimpleConstraintContactMgr(v8);
    v10 = (hkpRigidBody *)v2->m_entities[0];
    v11 = (hkpRigidBody *)v2->m_entities[1];
    event.m_bodies[1] = v11;
    event.m_source = 2;
    event.m_contactMgr = v9;
    event.m_bodies[0] = v10;
    hkpWorldCallbackUtil::fireContactConstraintRemovedCallback(v10->m_world, &event);
    event.m_source = 0;
    hkpEntityCallbackUtil::fireContactConstraintRemovedCallback((hkpEntity *)&v10->vfptr, &event);
    event.m_source = 1;
    hkpEntityCallbackUtil::fireContactConstraintRemovedCallback((hkpEntity *)&v11->vfptr, &event);
  }
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "Et";
    v14 = __rdtsc();
    v15 = (signed __int64)(v13 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v12[1] = v15;
  }
}

