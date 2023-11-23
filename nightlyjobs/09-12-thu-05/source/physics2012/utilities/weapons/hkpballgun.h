// File Line: 29
// RVA: 0xE0A230
void __fastcall hkpBallGun::hkpBallGun(hkpBallGun *this, hkFinishLoadedObjectFlag flag)
{
  hkStringPtr *p_m_name; // rcx
  hkQueue<hkpRigidBody *> *v4; // rdi
  _QWORD **Value; // rax
  hkQueue<hkpRigidBody *> *v6; // rax
  hkQueue<hkpRigidBody *> *v7; // rax
  int m_maxBulletsInWorld; // edx

  p_m_name = &this->m_name;
  p_m_name[-3].m_stringAndFlag = (const char *)&hkpFirstPersonGun::`vftable;
  hkStringPtr::hkStringPtr(p_m_name, flag);
  v4 = 0i64;
  this->m_listeners.m_capacityAndFlags = 0x80000000;
  this->m_listeners.m_data = 0i64;
  this->m_listeners.m_size = 0;
  if ( flag.m_finishing )
    this->m_type.m_storage = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBallGun::`vftable;
  if ( flag.m_finishing )
  {
    this->m_type.m_storage = 1;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkQueue<hkpRigidBody *> *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 24i64);
    if ( v6 )
    {
      hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(v6);
      v4 = v7;
    }
    m_maxBulletsInWorld = this->m_maxBulletsInWorld;
    this->m_addedBodies = v4;
    hkQueue<hkpRigidBody *>::setCapacity(v4, m_maxBulletsInWorld);
  }
}

