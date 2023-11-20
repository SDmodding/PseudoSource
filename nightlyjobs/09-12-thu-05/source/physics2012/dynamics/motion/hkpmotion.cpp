// File Line: 18
// RVA: 0xD60480
void __fastcall hkpMotion::hkpMotion(hkpMotion *this)
{
  hkpMotion *v1; // rbx
  hkMotionState *v2; // rcx
  hkQuaternionf rotation; // [rsp+20h] [rbp-38h]
  hkVector4f position; // [rsp+30h] [rbp-28h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMotion::`vftable';
  position.m_quad = 0i64;
  v2 = &this->m_motionState;
  v2[1].m_transform.m_rotation.m_col1 = 0i64;
  v2[1].m_transform.m_rotation.m_col2 = 0i64;
  rotation.m_vec.m_quad = qi.m_vec.m_quad;
  hkMotionState::initMotionState(v2, &position, &rotation);
  *(_DWORD *)&v1->m_motionState.m_linearDamping.m_value = 0;
  *(_DWORD *)&v1->m_type.m_storage = 65280;
  *(_QWORD *)v1->m_deactivationRefOrientation = 0i64;
  v1->m_deactivationRefPosition[0] = 0i64;
  v1->m_deactivationRefPosition[1] = 0i64;
  v1->m_deactivationNumInactiveFrames[1] = 0;
  v1->m_gravityFactor.m_value = 16256;
}

// File Line: 27
// RVA: 0xD60520
void __fastcall hkpMotion::hkpMotion(hkpMotion *this, hkVector4f *position, hkQuaternionf *rotation, bool wantDeactivation)
{
  hkpMotion *v4; // rdi
  bool v5; // bl
  hkVector4f *v6; // rsi

  v4 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMotion::`vftable';
  this->m_linearVelocity = 0i64;
  this->m_angularVelocity = 0i64;
  v5 = wantDeactivation;
  v6 = position;
  hkMotionState::initMotionState(&this->m_motionState, position, rotation);
  *(_DWORD *)&v4->m_motionState.m_linearDamping.m_value = 0;
  v4->m_type.m_storage = 0;
  if ( v5 )
    v4->m_deactivationIntegrateCounter = (signed int)v6->m_quad.m128_f32[0] & 0xF;
  else
    v4->m_deactivationIntegrateCounter = -1;
  v4->m_deactivationRefPosition[0] = 0i64;
  v4->m_deactivationRefPosition[1] = 0i64;
  *(_DWORD *)v4->m_deactivationNumInactiveFrames = 0;
  *(_QWORD *)v4->m_deactivationRefOrientation = 0i64;
  v4->m_gravityFactor.m_value = 16256;
}

// File Line: 69
// RVA: 0xD60610
void __fastcall hkpMotion::setMass(hkpMotion *this, float mass)
{
  ((void (*)(void))this->vfptr[3].__vecDelDtor)();
}

// File Line: 82
// RVA: 0xD60640
void __fastcall hkpMotion::setMass(hkpMotion *this, hkSimdFloat32 *mass)
{
  hkBaseObjectVtbl *v2; // rax
  __m128 v3; // xmm1
  __m128 v4; // [rsp+20h] [rbp-18h]

  v2 = this->vfptr;
  v3 = _mm_rcp_ps(mass->m_real);
  v4 = _mm_andnot_ps(
         _mm_cmpeqps(mass->m_real, (__m128)0i64),
         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(mass->m_real, v3)), v3));
  ((void (__fastcall *)(hkpMotion *, __m128 *))v2[2].__first_virtual_table_function__)(this, &v4);
}

// File Line: 89
// RVA: 0xD605D0
float __fastcall hkpMotion::getMass(hkpMotion *this)
{
  __m128 v1; // xmm2
  __m128 v2; // xmm3
  float result; // xmm0_4

  v1 = _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 255);
  v2 = _mm_rcp_ps(v1);
  LODWORD(result) = (unsigned __int128)_mm_andnot_ps(
                                         _mm_cmpeqps(v1, (__m128)0i64),
                                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v2, v1)), v2));
  return result;
}

// File Line: 97
// RVA: 0xD60690
void __fastcall hkpMotion::setMassInv(hkpMotion *this, float massInv)
{
  this->m_inertiaAndMassInv.m_quad.m128_f32[3] = massInv;
}

// File Line: 101
// RVA: 0xD606A0
void __fastcall hkpMotion::setMassInv(hkpMotion *this, hkSimdFloat32 *massInv)
{
  this->m_inertiaAndMassInv.m_quad = _mm_shuffle_ps(
                                       this->m_inertiaAndMassInv.m_quad,
                                       _mm_unpackhi_ps(this->m_inertiaAndMassInv.m_quad, massInv->m_real),
                                       196);
}

// File Line: 107
// RVA: 0xD606C0
void __fastcall hkpMotion::setCenterOfMassInLocal(hkpMotion *this, hkVector4f *centerOfMass)
{
  hkSweptTransformUtil::setCentreOfRotationLocal(centerOfMass, &this->m_motionState);
}

// File Line: 113
// RVA: 0xD606E0
void __fastcall hkpMotion::setPosition(hkpMotion *this, hkVector4f *position)
{
  hkSweptTransformUtil::warpToPosition(position, &this->m_motionState);
}

// File Line: 118
// RVA: 0xD60700
void __fastcall hkpMotion::setRotation(hkpMotion *this, hkQuaternionf *rotation)
{
  hkSweptTransformUtil::warpToRotation(rotation, &this->m_motionState);
}

// File Line: 123
// RVA: 0xD60720
void __fastcall hkpMotion::setPositionAndRotation(hkpMotion *this, hkVector4f *position, hkQuaternionf *rotation)
{
  hkSweptTransformUtil::warpTo(position, rotation, &this->m_motionState);
}

// File Line: 128
// RVA: 0xD60750
void __fastcall hkpMotion::setTransform(hkpMotion *this, hkTransformf *transform)
{
  hkSweptTransformUtil::warpTo(transform, &this->m_motionState);
}

// File Line: 133
// RVA: 0xD60740
void __fastcall hkpMotion::approxTransformAt(hkpMotion *this, float time, hkTransformf *transformOut)
{
  hkSweptTransformf::approxTransformAt(&this->m_motionState.m_sweptTransform, time, transformOut);
}

// File Line: 138
// RVA: 0xD60770
void __fastcall hkpMotion::setLinearVelocity(hkpMotion *this, hkVector4f *newVel)
{
  this->m_linearVelocity = (hkVector4f)newVel->m_quad;
}

// File Line: 144
// RVA: 0xD60790
void __fastcall hkpMotion::setAngularVelocity(hkpMotion *this, hkVector4f *newVel)
{
  this->m_angularVelocity = (hkVector4f)newVel->m_quad;
}

// File Line: 150
// RVA: 0xD607B0
void __fastcall hkpMotion::applyLinearImpulse(hkpMotion *this, hkVector4f *imp)
{
  this->m_linearVelocity.m_quad = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        this->m_inertiaAndMassInv.m_quad,
                                        this->m_inertiaAndMassInv.m_quad,
                                        255),
                                      imp->m_quad),
                                    this->m_linearVelocity.m_quad);
}

// File Line: 156
// RVA: 0xD607F0
void __fastcall hkpMotion::getMotionStateAndVelocitiesAndDeactivationType(hkpMotion *this, hkpMotion *motionOut)
{
  hkpMotion *v2; // rdi
  hkpMotion *v3; // rbx

  v2 = motionOut;
  v3 = this;
  hkMotionState::operator=(&motionOut->m_motionState, &this->m_motionState);
  v2->m_linearVelocity = v3->m_linearVelocity;
  v2->m_angularVelocity = v3->m_angularVelocity;
  v2->m_deactivationIntegrateCounter = v3->m_deactivationIntegrateCounter;
}

// File Line: 164
// RVA: 0xD607E0
void __fastcall hkpMotion::setDeactivationClass(hkpMotion *this, int deactivationClass)
{
  this->m_motionState.m_deactivationClass = deactivationClass;
}

// File Line: 170
// RVA: 0xD60850
void __fastcall hkpMotion::requestDeactivation(hkpMotion *this)
{
  hkVector4f v1; // xmm1
  hkpMotion *v2; // rbx
  hkQuaternionf *v3; // rcx
  __m128 v4; // xmm1
  unsigned int v5; // eax

  v1.m_quad = (__m128)this->m_motionState.m_transform.m_translation;
  v2 = this;
  v3 = &this->m_motionState.m_sweptTransform.m_rotation1;
  v3[7].m_vec = (hkVector4f)v1.m_quad;
  v4 = _mm_shuffle_ps(v1.m_quad, _mm_unpackhi_ps(v1.m_quad, (__m128)xmmword_141A712A0), 196);
  v3[7] = (hkQuaternionf)v4;
  v3[8] = (hkQuaternionf)v4;
  v5 = hkVector4UtilImpl<float>::packQuaternionIntoInt32(&v3->m_vec);
  v2->m_deactivationRefOrientation[0] = v5;
  v2->m_deactivationRefOrientation[1] = v5;
  v2->m_deactivationNumInactiveFrames[0] = v2->m_deactivationNumInactiveFrames[0] & 0xFF86 | 6;
  v2->m_deactivationNumInactiveFrames[1] = v2->m_deactivationNumInactiveFrames[1] & 0xFF86 | 6;
}

