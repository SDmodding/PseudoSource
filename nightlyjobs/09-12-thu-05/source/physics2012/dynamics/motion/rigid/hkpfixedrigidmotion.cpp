// File Line: 16
// RVA: 0xD79F50
void __fastcall hkpFixedRigidMotion::hkpFixedRigidMotion(
        hkpFixedRigidMotion *this,
        hkVector4f *position,
        hkQuaternionf *rotation)
{
  hkpKeyframedRigidMotion::hkpKeyframedRigidMotion(this, position, rotation);
  this->vfptr = (hkBaseObjectVtbl *)&hkpFixedRigidMotion::`vftable;
  this->m_type.m_storage = 5;
}

// File Line: 23
// RVA: 0xD79FC0
void __fastcall hkpFixedRigidMotion::setStepPosition(hkpFixedRigidMotion *this, float position, float timestep)
{
  ;
}

// File Line: 29
// RVA: 0xD79F80
void __fastcall hkpFixedRigidMotion::getPositionAndVelocities(hkpFixedRigidMotion *this, hkpMotion *motionOut)
{
  hkMotionState::operator=(&motionOut->m_motionState, &this->m_motionState);
  motionOut->m_linearVelocity = 0i64;
  motionOut->m_angularVelocity = 0i64;
}

// File Line: 36
// RVA: 0xD79FD0
void __fastcall hkpFixedRigidMotion::setLinearVelocity(hkpFixedRigidMotion *this, hkVector4f *newVel)
{
  ;
}

// File Line: 41
// RVA: 0xD79FE0
void __fastcall hkpFixedRigidMotion::setAngularVelocity(hkpFixedRigidMotion *this, hkVector4f *newVel)
{
  ;
}

