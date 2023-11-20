// File Line: 29
// RVA: 0xE0A230
void __fastcall hkpBallGun::hkpBallGun(hkpBallGun *this, hkFinishLoadedObjectFlag flag)
{
  hkpBallGun *v2; // rbx
  hkStringPtr *v3; // rcx
  hkQueue<hkpRigidBody *> *v4; // rdi
  _QWORD **v5; // rax
  hkQueue<hkpRigidBody *> *v6; // rax
  hkQueue<hkpRigidBody *> *v7; // rax
  int v8; // edx
  int v9; // [rsp+38h] [rbp+10h]

  v9 = flag.m_finishing;
  v2 = this;
  v3 = &this->m_name;
  v3[-3].m_stringAndFlag = (const char *)&hkpFirstPersonGun::`vftable';
  hkStringPtr::hkStringPtr(v3, flag);
  v4 = 0i64;
  v2->m_listeners.m_capacityAndFlags = 2147483648;
  v2->m_listeners.m_data = 0i64;
  v2->m_listeners.m_size = 0;
  if ( v9 )
    v2->m_type.m_storage = 0;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpBallGun::`vftable';
  if ( v9 )
  {
    v2->m_type.m_storage = 1;
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkQueue<hkpRigidBody *> *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(
                                      v5[11],
                                      24i64);
    if ( v6 )
    {
      hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(v6);
      v4 = v7;
    }
    v8 = v2->m_maxBulletsInWorld;
    v2->m_addedBodies = v4;
    hkQueue<hkpRigidBody *>::setCapacity(v4, v8);
  }
}

