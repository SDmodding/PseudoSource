// File Line: 16
// RVA: 0xD77290
void __fastcall hkpKeyframedRigidMotion::hkpKeyframedRigidMotion(hkpKeyframedRigidMotion *this, hkVector4f *position, hkQuaternionf *rotation)
{
  hkpKeyframedRigidMotion *v3; // rbx

  v3 = this;
  hkpMotion::hkpMotion((hkpMotion *)&this->vfptr, position, rotation, 0);
  v3->m_type.m_storage = 4;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpKeyframedRigidMotion::`vftable;
  v3->m_inertiaAndMassInv = 0i64;
  v3->m_savedMotion = 0i64;
  v3->m_savedQualityTypeIndex = 0;
}

// File Line: 28
// RVA: 0xD772E0
void __fastcall hkpKeyframedRigidMotion::~hkpKeyframedRigidMotion(hkpKeyframedRigidMotion *this)
{
  hkpKeyframedRigidMotion *v1; // rbx
  hkpMaxSizeMotion *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpKeyframedRigidMotion::`vftable;
  v2 = this->m_savedMotion;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 36
// RVA: 0xD77320
void __fastcall hkpKeyframedRigidMotion::setMass(hkpKeyframedRigidMotion *this, float m)
{
  ;
}

// File Line: 40
// RVA: 0xD77330
void __fastcall hkpKeyframedRigidMotion::setMass(hkpKeyframedRigidMotion *this, hkSimdFloat32 *m)
{
  ;
}

// File Line: 45
// RVA: 0xD77340
void __fastcall hkpKeyframedRigidMotion::setMassInv(hkpKeyframedRigidMotion *this, float mInv)
{
  ;
}

// File Line: 49
// RVA: 0xD77350
void __fastcall hkpKeyframedRigidMotion::setMassInv(hkpKeyframedRigidMotion *this, hkSimdFloat32 *mInv)
{
  ;
}

// File Line: 54
// RVA: 0xD77360
void __fastcall hkpKeyframedRigidMotion::getInertiaLocal(hkpKeyframedRigidMotion *this, hkMatrix3f *inertia)
{
  inertia->m_col0 = 0i64;
  inertia->m_col1 = 0i64;
  inertia->m_col2 = 0i64;
}

// File Line: 62
// RVA: 0xD77390
void __fastcall hkpKeyframedRigidMotion::getInertiaWorld(hkpKeyframedRigidMotion *this, hkMatrix3f *inertia)
{
  inertia->m_col0 = 0i64;
  inertia->m_col1 = 0i64;
  inertia->m_col2 = 0i64;
}

// File Line: 70
// RVA: 0xD77380
void __fastcall hkpKeyframedRigidMotion::setInertiaLocal(hkpKeyframedRigidMotion *this, hkMatrix3f *inertia)
{
  ;
}

// File Line: 76
// RVA: 0xD773B0
void __fastcall hkpKeyframedRigidMotion::setInertiaInvLocal(hkpKeyframedRigidMotion *this, hkMatrix3f *inertiaInv)
{
  ;
}

// File Line: 81
// RVA: 0xD773C0
void __fastcall hkpKeyframedRigidMotion::getInertiaInvLocal(hkpKeyframedRigidMotion *this, hkMatrix3f *inertiaInv)
{
  inertiaInv->m_col0 = 0i64;
  inertiaInv->m_col1 = 0i64;
  inertiaInv->m_col2 = 0i64;
}

// File Line: 88
// RVA: 0xD773E0
void __fastcall hkpKeyframedRigidMotion::getInertiaInvWorld(hkpKeyframedRigidMotion *this, hkMatrix3f *inertiaInvOut)
{
  inertiaInvOut->m_col0 = 0i64;
  inertiaInvOut->m_col1 = 0i64;
  inertiaInvOut->m_col2 = 0i64;
}

// File Line: 95
// RVA: 0xD77500
void __fastcall hkpKeyframedRigidMotion::applyLinearImpulse(hkpKeyframedRigidMotion *this, hkVector4f *imp)
{
  ;
}

// File Line: 99
// RVA: 0xD77510
void __fastcall hkpKeyframedRigidMotion::applyPointImpulse(hkpKeyframedRigidMotion *this, hkVector4f *imp, hkVector4f *p)
{
  ;
}

// File Line: 103
// RVA: 0xD77520
void __fastcall hkpKeyframedRigidMotion::applyAngularImpulse(hkpKeyframedRigidMotion *this, hkVector4f *imp)
{
  ;
}

// File Line: 107
// RVA: 0xD77530
void __fastcall hkpKeyframedRigidMotion::applyForce(hkpKeyframedRigidMotion *this, const float deltaTime, hkVector4f *force)
{
  ;
}

// File Line: 111
// RVA: 0xD77540
void __fastcall hkpKeyframedRigidMotion::applyForce(hkpKeyframedRigidMotion *this, const float deltaTime, hkVector4f *force, hkVector4f *p)
{
  ;
}

// File Line: 115
// RVA: 0xD77550
void __fastcall hkpKeyframedRigidMotion::applyTorque(hkpKeyframedRigidMotion *this, const float deltaTime, hkVector4f *torque)
{
  ;
}

// File Line: 119
// RVA: 0xD77560
void __fastcall hkpKeyframedRigidMotion::setStepPosition(hkpKeyframedRigidMotion *this, float position, float timestep)
{
  ;
}

// File Line: 123
// RVA: 0xD77570
void __fastcall hkpKeyframedRigidMotion::setStoredMotion(hkpKeyframedRigidMotion *this, hkpMaxSizeMotion *savedMotion)
{
  hkpMaxSizeMotion *v2; // rbx
  hkpKeyframedRigidMotion *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = savedMotion;
  v3 = this;
  if ( savedMotion )
    hkReferencedObject::addReference((hkReferencedObject *)&savedMotion->vfptr);
  v4 = (hkReferencedObject *)&v3->m_savedMotion->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_savedMotion = v2;
}

// File Line: 136
// RVA: 0xD77400
void __fastcall hkpKeyframedRigidMotion::getProjectedPointVelocity(hkpKeyframedRigidMotion *this, hkVector4f *pos, hkVector4f *normal, float *velOut, float *invVirtMassOut)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm4

  v5 = _mm_sub_ps(pos->m_quad, this->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v6 = _mm_mul_ps(this->m_linearVelocity.m_quad, normal->m_quad);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), normal->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(normal->m_quad, normal->m_quad, 201), v5));
  v8 = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), this->m_angularVelocity.m_quad);
  *velOut = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 170)))
          + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 170)));
  *invVirtMassOut = 0.0;
}

// File Line: 147
// RVA: 0xD77480
void __fastcall hkpKeyframedRigidMotion::getProjectedPointVelocitySimd(hkpKeyframedRigidMotion *this, hkVector4f *pos, hkVector4f *normal, hkSimdFloat32 *velOut, hkSimdFloat32 *invVirtMassOut)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm4

  v5 = _mm_sub_ps(pos->m_quad, this->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v6 = _mm_mul_ps(this->m_linearVelocity.m_quad, normal->m_quad);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), normal->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(normal->m_quad, normal->m_quad, 201), v5));
  v8 = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), this->m_angularVelocity.m_quad);
  velOut->m_real = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                       _mm_shuffle_ps(v8, v8, 170)),
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)),
                       _mm_shuffle_ps(v6, v6, 170)));
  *invVirtMassOut = 0i64;
}

