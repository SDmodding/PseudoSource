// File Line: 11
// RVA: 0xB8050
hkpRigidBody *__fastcall hkpGetRigidBody(hkpCollidable *collidable)
{
  hkpRigidBody *result; // rax

  if ( collidable->m_broadPhaseHandle.m_type == 1 )
    result = (hkpRigidBody *)((char *)collidable + collidable->m_ownerOffset);
  else
    result = 0i64;
  return result;
}

// File Line: 168
// RVA: 0xB66C0
void __fastcall hkpRigidBody::applyPointImpulse(hkpRigidBody *this, hkVector4f *imp, hkVector4f *p)
{
  hkVector4f *v3; // rdi
  hkVector4f *v4; // rsi
  hkpRigidBody *v5; // rbx

  v3 = p;
  v4 = imp;
  v5 = this;
  hkpEntity::activate((hkpEntity *)&this->vfptr);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkVector4f *))v5->m_motion.vfptr[11].__first_virtual_table_function__)(
    &v5->m_motion,
    v4,
    v3);
}

// File Line: 324
// RVA: 0xB8CE0
void __fastcall hkpRigidBody::setLinearVelocity(hkpRigidBody *this, hkVector4f *newVel)
{
  hkVector4f *v2; // rdi
  hkpRigidBody *v3; // rbx

  v2 = newVel;
  v3 = this;
  hkpEntity::activate((hkpEntity *)&this->vfptr);
  v3->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v3->m_motion.vfptr, (unsigned int)v2);
}

