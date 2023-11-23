// File Line: 21
// RVA: 0xD7A4A0
void __fastcall hkpSphereMotion::getInertiaLocal(hkpSphereMotion *this, hkMatrix3f *inertia)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm2
  __m128 v4; // xmm3

  v2 = _mm_max_ps(
         *(__m128 *)&epsilon,
         _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 0));
  v3 = _mm_rcp_ps(v2);
  v4 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v3, v2)), v3);
  inertia->m_col0.m_quad = _mm_mul_ps(transform.m_quad, v4);
  inertia->m_col1.m_quad = _mm_mul_ps(direction.m_quad, v4);
  inertia->m_col2.m_quad = _mm_mul_ps(stru_141A71280.m_quad, v4);
}

// File Line: 29
// RVA: 0xD7A500
void __fastcall hkpSphereMotion::getInertiaWorld(hkpSphereMotion *this, hkMatrix3f *inertia)
{
  ((void (__fastcall *)(hkpSphereMotion *, hkMatrix3f *))this->vfptr[3].__first_virtual_table_function__)(this, inertia);
}

// File Line: 36
// RVA: 0xD7A510
void __fastcall hkpSphereMotion::setInertiaLocal(hkpSphereMotion *this, hkMatrix3f *inertia)
{
  __m128 v2; // xmm4
  __m128 v3; // xmm4
  __m128 v4; // xmm2
  __m128 v5; // xmm3

  v2 = _mm_or_ps(
         _mm_andnot_ps(
           (__m128)xmmword_141A9B7E0,
           _mm_or_ps(
             _mm_and_ps(inertia->m_col1.m_quad, (__m128)xmmword_141A9B7C0),
             _mm_andnot_ps((__m128)xmmword_141A9B7C0, inertia->m_col0.m_quad))),
         _mm_and_ps(inertia->m_col2.m_quad, (__m128)xmmword_141A9B7E0));
  v3 = _mm_max_ps(_mm_shuffle_ps(v2, v2, 170), _mm_max_ps(_mm_shuffle_ps(v2, v2, 85), _mm_shuffle_ps(v2, v2, 0)));
  v4 = _mm_rcp_ps(v3);
  v5 = _mm_andnot_ps(_mm_cmpeq_ps(v3, (__m128)0i64), _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, v3)), v4));
  this->m_inertiaAndMassInv.m_quad = _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, this->m_inertiaAndMassInv.m_quad), 196);
}

// File Line: 50
// RVA: 0xD7A5A0
void __fastcall hkpSphereMotion::setInertiaInvLocal(hkpSphereMotion *this, hkMatrix3f *inertiaInv)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm3

  v2 = _mm_or_ps(
         _mm_andnot_ps(
           (__m128)xmmword_141A9B7E0,
           _mm_or_ps(
             _mm_and_ps(inertiaInv->m_col1.m_quad, (__m128)xmmword_141A9B7C0),
             _mm_andnot_ps((__m128)xmmword_141A9B7C0, inertiaInv->m_col0.m_quad))),
         _mm_and_ps(inertiaInv->m_col2.m_quad, (__m128)xmmword_141A9B7E0));
  v3 = _mm_min_ps(_mm_shuffle_ps(v2, v2, 170), _mm_min_ps(_mm_shuffle_ps(v2, v2, 85), _mm_shuffle_ps(v2, v2, 0)));
  this->m_inertiaAndMassInv.m_quad = _mm_shuffle_ps(v3, _mm_unpackhi_ps(v3, this->m_inertiaAndMassInv.m_quad), 196);
}

// File Line: 59
// RVA: 0xD7A600
void __fastcall hkpSphereMotion::getInertiaInvLocal(hkpSphereMotion *this, hkMatrix3f *inertiaInv)
{
  __m128 v2; // xmm3

  v2 = _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 0);
  inertiaInv->m_col1.m_quad = _mm_mul_ps(direction.m_quad, v2);
  inertiaInv->m_col2.m_quad = _mm_mul_ps(stru_141A71280.m_quad, v2);
  inertiaInv->m_col0.m_quad = _mm_mul_ps(transform.m_quad, v2);
}

// File Line: 66
// RVA: 0xD7A640
void __fastcall hkpSphereMotion::getInertiaInvWorld(hkpSphereMotion *this, hkMatrix3f *inertiaInv)
{
  __m128 v2; // xmm3

  v2 = _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 0);
  inertiaInv->m_col1.m_quad = _mm_mul_ps(direction.m_quad, v2);
  inertiaInv->m_col2.m_quad = _mm_mul_ps(stru_141A71280.m_quad, v2);
  inertiaInv->m_col0.m_quad = _mm_mul_ps(transform.m_quad, v2);
}

// File Line: 77
// RVA: 0xD7A800
void __fastcall hkpSphereMotion::applyPointImpulse(hkpSphereMotion *this, hkVector4f *imp, hkVector4f *p)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm2

  this->m_linearVelocity.m_quad = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        this->m_inertiaAndMassInv.m_quad,
                                        this->m_inertiaAndMassInv.m_quad,
                                        255),
                                      imp->m_quad),
                                    this->m_linearVelocity.m_quad);
  v3 = _mm_sub_ps(p->m_quad, this->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v4 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(imp->m_quad, imp->m_quad, 201), v3),
         _mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), imp->m_quad));
  this->m_angularVelocity.m_quad = _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), this->m_inertiaAndMassInv.m_quad),
                                     this->m_angularVelocity.m_quad);
}

// File Line: 92
// RVA: 0xD7A860
void __fastcall hkpSphereMotion::applyAngularImpulse(hkpSphereMotion *this, hkVector4f *imp)
{
  this->m_angularVelocity.m_quad = _mm_add_ps(
                                     _mm_mul_ps(this->m_inertiaAndMassInv.m_quad, imp->m_quad),
                                     this->m_angularVelocity.m_quad);
}

// File Line: 104
// RVA: 0xD7A880
void __fastcall hkpSphereMotion::applyForce(hkpSphereMotion *this, const float deltaTime, hkVector4f *force)
{
  this->m_linearVelocity.m_quad = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0),
                                        force->m_quad),
                                      _mm_shuffle_ps(
                                        this->m_inertiaAndMassInv.m_quad,
                                        this->m_inertiaAndMassInv.m_quad,
                                        255)),
                                    this->m_linearVelocity.m_quad);
}

// File Line: 110
// RVA: 0xD7A8C0
void __fastcall hkpSphereMotion::applyForce(
        hkpSphereMotion *this,
        const float deltaTime,
        hkVector4f *force,
        hkVector4f *p)
{
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v5; // [rsp+20h] [rbp-18h] BYREF

  vfptr = this->vfptr;
  v5 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0), force->m_quad);
  ((void (__fastcall *)(hkpSphereMotion *, __m128 *, hkVector4f *))vfptr[11].__first_virtual_table_function__)(
    this,
    &v5,
    p);
}

// File Line: 117
// RVA: 0xD7A900
void __fastcall hkpSphereMotion::applyTorque(hkpSphereMotion *this, const float deltaTime, hkVector4f *torque)
{
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v4; // [rsp+20h] [rbp-18h] BYREF

  vfptr = this->vfptr;
  v4 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0), torque->m_quad);
  vfptr[12].__vecDelDtor(this, (unsigned int)&v4);
}

// File Line: 124
// RVA: 0xD7A680
void __fastcall hkpSphereMotion::getProjectedPointVelocity(
        hkpSphereMotion *this,
        hkVector4f *pos,
        hkVector4f *normal,
        float *velOut,
        float *invVirtMassOut)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm4

  v5 = _mm_sub_ps(pos->m_quad, this->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v6 = _mm_mul_ps(this->m_linearVelocity.m_quad, normal->m_quad);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), normal->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(normal->m_quad, normal->m_quad, 201), v5));
  v8 = _mm_shuffle_ps(v7, v7, 201);
  v9 = _mm_mul_ps(this->m_angularVelocity.m_quad, v8);
  v10 = _mm_mul_ps(v8, v8);
  *velOut = (float)((float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0] + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
                  + _mm_shuffle_ps(v9, v9, 170).m128_f32[0])
          + (float)((float)(_mm_shuffle_ps(v6, v6, 85).m128_f32[0] + _mm_shuffle_ps(v6, v6, 0).m128_f32[0])
                  + _mm_shuffle_ps(v6, v6, 170).m128_f32[0]);
  *invVirtMassOut = (float)((float)((float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0]
                                          + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
                                  + _mm_shuffle_ps(v10, v10, 170).m128_f32[0])
                          * _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 0).m128_f32[0])
                  + _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 255).m128_f32[0];
}

// File Line: 135
// RVA: 0xD7A740
void __fastcall hkpSphereMotion::getProjectedPointVelocitySimd(
        hkpSphereMotion *this,
        hkVector4f *pos,
        hkVector4f *normal,
        hkSimdFloat32 *velOut,
        hkSimdFloat32 *invVirtMassOut)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm4

  v5 = _mm_sub_ps(pos->m_quad, this->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v6 = _mm_mul_ps(this->m_linearVelocity.m_quad, normal->m_quad);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), normal->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(normal->m_quad, normal->m_quad, 201), v5));
  v8 = _mm_shuffle_ps(v7, v7, 201);
  v9 = _mm_mul_ps(this->m_angularVelocity.m_quad, v8);
  v10 = _mm_mul_ps(v8, v8);
  velOut->m_real = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                       _mm_shuffle_ps(v9, v9, 170)),
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)),
                       _mm_shuffle_ps(v6, v6, 170)));
  invVirtMassOut->m_real = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                                 _mm_shuffle_ps(v10, v10, 170)),
                               _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 0)),
                             _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 255));
}

