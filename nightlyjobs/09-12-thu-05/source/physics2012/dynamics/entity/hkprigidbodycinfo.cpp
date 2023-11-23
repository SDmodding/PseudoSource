// File Line: 14
// RVA: 0xD61F90
void __fastcall hkpRigidBodyCinfo::hkpRigidBodyCinfo(hkpRigidBodyCinfo *this)
{
  this->m_position = 0i64;
  this->m_linearVelocity = 0i64;
  this->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  this->m_angularVelocity = 0i64;
  this->m_inertiaTensor.m_col0.m_quad = _mm_mul_ps(transform.m_quad, query.m_quad);
  this->m_inertiaTensor.m_col1.m_quad = _mm_mul_ps(direction.m_quad, query.m_quad);
  this->m_inertiaTensor.m_col2.m_quad = _mm_mul_ps(stru_141A71280.m_quad, query.m_quad);
  this->m_collisionFilterInfo = 0;
  this->m_shape = 0i64;
  this->m_localFrame = 0i64;
  *(_WORD *)&this->m_responseModifierFlags = 0;
  *(_QWORD *)&this->m_mass = 1065353216i64;
  this->m_angularDamping = 0.050000001;
  this->m_centerOfMass = 0i64;
  this->m_gravityFactor = 1.0;
  *(_QWORD *)&this->m_friction = 1056964608i64;
  this->m_restitution = 0.40000001;
  this->m_maxLinearVelocity = 200.0;
  this->m_maxAngularVelocity = 200.0;
  *(_WORD *)&this->m_motionType.m_storage = 257;
  this->m_solverDeactivation.m_storage = 2;
  this->m_timeFactor = 1.0;
  *(_DWORD *)&this->m_contactPointCallbackDelay = 0xFFFFFF;
  this->m_allowedPenetrationDepth = -1.0;
  this->m_collisionResponse.m_storage = 1;
  this->m_forceCollideOntoPpu.m_bool = 0;
}

// File Line: 49
// RVA: 0xD62090
void __fastcall hkpRigidBodyCinfo::setMassProperties(hkpRigidBodyCinfo *this, hkMassProperties *mp)
{
  this->m_mass = mp->m_mass;
  this->m_inertiaTensor = mp->m_inertiaTensor;
  this->m_centerOfMass = mp->m_centerOfMass;
}

// File Line: 56
// RVA: 0xD620D0
void __fastcall hkpRigidBodyCinfo::setTransform(hkpRigidBodyCinfo *this, hkTransformf *transform)
{
  hkQuaternionf *p_m_rotation; // rcx

  p_m_rotation = &this->m_rotation;
  p_m_rotation[-1] = (hkQuaternionf)transform->m_translation;
  hkQuaternionf::set(p_m_rotation, &transform->m_rotation);
}

