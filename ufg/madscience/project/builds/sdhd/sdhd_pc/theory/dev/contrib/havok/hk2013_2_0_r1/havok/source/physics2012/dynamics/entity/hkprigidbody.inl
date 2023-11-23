// File Line: 11
// RVA: 0xB8050
hkpRigidBody *__fastcall hkpGetRigidBody(hkpCollidable *collidable)
{
  if ( collidable->m_broadPhaseHandle.m_type == 1 )
    return (hkpRigidBody *)((char *)collidable + collidable->m_ownerOffset);
  else
    return 0i64;
}

// File Line: 168
// RVA: 0xB66C0
void __fastcall hkpRigidBody::applyPointImpulse(hkpRigidBody *this, hkVector4f *imp, hkVector4f *p)
{
  hkpEntity::activate(this);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkVector4f *))this->m_motion.hkpEntity::vfptr[11].__first_virtual_table_function__)(
    &this->m_motion,
    imp,
    p);
}

// File Line: 324
// RVA: 0xB8CE0
void __fastcall hkpRigidBody::setLinearVelocity(hkpRigidBody *this, hkVector4f *newVel)
{
  hkpEntity::activate(this);
  this->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&this->m_motion, (unsigned int)newVel);
}

