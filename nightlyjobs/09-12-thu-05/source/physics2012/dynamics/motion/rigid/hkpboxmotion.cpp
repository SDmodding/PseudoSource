// File Line: 18
// RVA: 0xD77DD0
void __fastcall hkpBoxMotion::hkpBoxMotion(hkpBoxMotion *this, hkVector4f *position, hkQuaternionf *rotation)
{
  hkpBoxMotion *v3; // rbx

  v3 = this;
  hkpMotion::hkpMotion((hkpMotion *)&this->vfptr, position, rotation, 0);
  v3->vfptr = (hkBaseObjectVtbl *)&hkpBoxMotion::`vftable;
  v3->m_type.m_storage = 3;
  v3->m_inertiaAndMassInv = (hkVector4f)query.m_quad;
}

// File Line: 24
// RVA: 0xD77E10
void __fastcall hkpBoxMotion::getInertiaLocal(hkpBoxMotion *this, hkMatrix3f *inertia)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm2
  __m128 v4; // xmm3

  v2 = _mm_max_ps(*(__m128 *)&epsilon, this->m_inertiaAndMassInv.m_quad);
  v3 = _mm_rcp_ps(v2);
  v4 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v3, v2)), v3);
  inertia->m_col0.m_quad = _mm_mul_ps(transform.m_quad, v4);
  inertia->m_col1.m_quad = _mm_mul_ps(direction.m_quad, v4);
  inertia->m_col2.m_quad = _mm_mul_ps(stru_141A71280.m_quad, v4);
}

// File Line: 33
// RVA: 0xD77EB0
void __fastcall hkpBoxMotion::setInertiaLocal(hkpBoxMotion *this, hkMatrix3f *inertia)
{
  __m128 v2; // xmm2
  __m128 v3; // xmm1
  __m128 v4; // xmm3

  v2 = _mm_or_ps(
         _mm_andnot_ps(
           (__m128)xmmword_141A9B260,
           _mm_or_ps(
             _mm_and_ps(inertia->m_col1.m_quad, (__m128)xmmword_141A9B240),
             _mm_andnot_ps((__m128)xmmword_141A9B240, inertia->m_col0.m_quad))),
         _mm_and_ps(inertia->m_col2.m_quad, (__m128)xmmword_141A9B260));
  v3 = _mm_rcp_ps(v2);
  v4 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v3, v2)), v3);
  this->m_inertiaAndMassInv.m_quad = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, this->m_inertiaAndMassInv.m_quad), 196);
}

// File Line: 44
// RVA: 0xD77FF0
void __fastcall hkpBoxMotion::getInertiaInvLocal(hkpBoxMotion *this, hkMatrix3f *inertiaInv)
{
  hkVector4f v2; // xmm2
  hkVector4f v3; // xmm0

  v2.m_quad = (__m128)this->m_inertiaAndMassInv;
  v3.m_quad = _mm_mul_ps(this->m_inertiaAndMassInv.m_quad, stru_141A71280.m_quad);
  inertiaInv->m_col0.m_quad = _mm_mul_ps(v2.m_quad, transform.m_quad);
  inertiaInv->m_col1.m_quad = _mm_mul_ps(v2.m_quad, direction.m_quad);
  inertiaInv->m_col2 = (hkVector4f)v3.m_quad;
}

// File Line: 49
// RVA: 0xD77FA0
void __fastcall hkpBoxMotion::setInertiaInvLocal(hkpBoxMotion *this, hkMatrix3f *inertiaInv)
{
  __m128 v2; // xmm3

  v2 = _mm_or_ps(
         _mm_andnot_ps(
           (__m128)xmmword_141A9B260,
           _mm_or_ps(
             _mm_and_ps(inertiaInv->m_col1.m_quad, (__m128)xmmword_141A9B240),
             _mm_andnot_ps((__m128)xmmword_141A9B240, inertiaInv->m_col0.m_quad))),
         _mm_and_ps(inertiaInv->m_col2.m_quad, (__m128)xmmword_141A9B260));
  this->m_inertiaAndMassInv.m_quad = _mm_shuffle_ps(v2, _mm_unpackhi_ps(v2, this->m_inertiaAndMassInv.m_quad), 196);
}

// File Line: 55
// RVA: 0xD78030
void __fastcall hkpBoxMotion::getInertiaInvWorld(hkpBoxMotion *this, hkMatrix3f *inertiaInv)
{
  hkVector4f v2; // xmm1
  hkVector4f v3; // xmm0
  hkMatrix3f aTb; // [rsp+20h] [rbp-38h]

  v2.m_quad = _mm_mul_ps(
                _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 170),
                this->m_motionState.m_transform.m_rotation.m_col2.m_quad);
  aTb.m_col0.m_quad = _mm_mul_ps(
                        _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 0),
                        this->m_motionState.m_transform.m_rotation.m_col0.m_quad);
  v3.m_quad = (__m128)this->m_inertiaAndMassInv;
  aTb.m_col2 = (hkVector4f)v2.m_quad;
  aTb.m_col1.m_quad = _mm_mul_ps(
                        _mm_shuffle_ps(v3.m_quad, v3.m_quad, 85),
                        this->m_motionState.m_transform.m_rotation.m_col1.m_quad);
  hkMatrix3f::setMulInverse(inertiaInv, &aTb, &this->m_motionState.m_transform.m_rotation);
}

// File Line: 67
// RVA: 0xD77E70
void __fastcall hkpBoxMotion::getInertiaWorld(hkpBoxMotion *this, hkMatrix3f *inertia)
{
  hkMatrix3f *v2; // rdi
  hkpBoxMotion *v3; // rbx

  v2 = inertia;
  v3 = this;
  ((void (*)(void))this->vfptr[3].__first_virtual_table_function__)();
  hkMatrix3f::changeBasis(v2, &v3->m_motionState.m_transform.m_rotation);
}

// File Line: 75
// RVA: 0xD77F10
void __fastcall hkpBoxMotion::setMass(hkpBoxMotion *this, float mass)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm0

  v2 = _mm_shuffle_ps((__m128)LODWORD(mass), (__m128)LODWORD(mass), 0);
  v3 = _mm_rcp_ps(v2);
  this->m_inertiaAndMassInv.m_quad = _mm_shuffle_ps(
                                       this->m_inertiaAndMassInv.m_quad,
                                       _mm_unpackhi_ps(
                                         this->m_inertiaAndMassInv.m_quad,
                                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v2, v3)), v3)),
                                       196);
}

// File Line: 81
// RVA: 0xD77F60
void __fastcall hkpBoxMotion::setMass(hkpBoxMotion *this, hkSimdFloat32 *mass)
{
  __m128 v2; // xmm1

  v2 = _mm_rcp_ps(mass->m_real);
  this->m_inertiaAndMassInv.m_quad = _mm_shuffle_ps(
                                       this->m_inertiaAndMassInv.m_quad,
                                       _mm_unpackhi_ps(
                                         this->m_inertiaAndMassInv.m_quad,
                                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(mass->m_real, v2)), v2)),
                                       196);
}

// File Line: 89
// RVA: 0xD78090
void __fastcall hkpBoxMotion::applyPointImpulse(hkpBoxMotion *this, hkVector4f *imp, hkVector4f *p)
{
  hkVector4f v3; // xmm3
  __m128 v4; // xmm1
  __m128 v5; // xmm0
  __m128 v6; // xmm6
  __m128 v7; // xmm1
  __m128 v8; // xmm6
  __m128 v9; // xmm2
  __m128 v10; // xmm6
  __m128 v11; // xmm5

  this->m_linearVelocity.m_quad = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        this->m_inertiaAndMassInv.m_quad,
                                        this->m_inertiaAndMassInv.m_quad,
                                        255),
                                      imp->m_quad),
                                    this->m_linearVelocity.m_quad);
  v3.m_quad = (__m128)this->m_motionState.m_transform.m_rotation.m_col2;
  v4 = _mm_sub_ps(p->m_quad, this->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v5 = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), imp->m_quad);
  v6 = _mm_mul_ps(_mm_shuffle_ps(imp->m_quad, imp->m_quad, 201), v4);
  v7 = _mm_unpacklo_ps(
         this->m_motionState.m_transform.m_rotation.m_col0.m_quad,
         this->m_motionState.m_transform.m_rotation.m_col1.m_quad);
  v8 = _mm_sub_ps(v6, v5);
  v9 = _mm_movelh_ps(v7, v3.m_quad);
  v10 = _mm_shuffle_ps(v8, v8, 201);
  v11 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(_mm_movehl_ps(v9, v7), v3.m_quad, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v9)),
            _mm_mul_ps(
              _mm_shuffle_ps(v10, v10, 170),
              _mm_shuffle_ps(
                _mm_unpackhi_ps(
                  this->m_motionState.m_transform.m_rotation.m_col0.m_quad,
                  this->m_motionState.m_transform.m_rotation.m_col1.m_quad),
                v3.m_quad,
                228))),
          this->m_inertiaAndMassInv.m_quad);
  this->m_angularVelocity.m_quad = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v11, v11, 85),
                                           this->m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v11, v11, 0),
                                           this->m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                       _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v3.m_quad)),
                                     this->m_angularVelocity.m_quad);
}

// File Line: 107
// RVA: 0xD78170
void __fastcall hkpBoxMotion::applyAngularImpulse(hkpBoxMotion *this, hkVector4f *imp)
{
  hkVector4f v2; // xmm3
  __m128 v3; // xmm1
  __m128 v4; // xmm0
  __m128 v5; // xmm5

  v2.m_quad = (__m128)this->m_motionState.m_transform.m_rotation.m_col2;
  v3 = _mm_unpacklo_ps(
         this->m_motionState.m_transform.m_rotation.m_col0.m_quad,
         this->m_motionState.m_transform.m_rotation.m_col1.m_quad);
  v4 = _mm_movelh_ps(v3, v2.m_quad);
  v5 = _mm_mul_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(imp->m_quad, imp->m_quad, 0), v4),
             _mm_mul_ps(
               _mm_shuffle_ps(imp->m_quad, imp->m_quad, 85),
               _mm_shuffle_ps(_mm_movehl_ps(v4, v3), v2.m_quad, 212))),
           _mm_mul_ps(
             _mm_shuffle_ps(imp->m_quad, imp->m_quad, 170),
             _mm_shuffle_ps(
               _mm_unpackhi_ps(
                 this->m_motionState.m_transform.m_rotation.m_col0.m_quad,
                 this->m_motionState.m_transform.m_rotation.m_col1.m_quad),
               v2.m_quad,
               228))),
         this->m_inertiaAndMassInv.m_quad);
  this->m_angularVelocity.m_quad = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v5, v5, 85),
                                           this->m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v5, v5, 0),
                                           this->m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                       _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), v2.m_quad)),
                                     this->m_angularVelocity.m_quad);
}

// File Line: 117
// RVA: 0xD78200
void __fastcall hkpBoxMotion::applyForce(hkpBoxMotion *this, const float deltaTime, hkVector4f *force)
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

// File Line: 123
// RVA: 0xD78240
void __fastcall hkpBoxMotion::applyForce(hkpBoxMotion *this, const float deltaTime, hkVector4f *force, hkVector4f *p)
{
  hkBaseObjectVtbl *v4; // rax
  __m128 v5; // [rsp+20h] [rbp-18h]

  v4 = this->vfptr;
  v5 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0), force->m_quad);
  ((void (__fastcall *)(hkpBoxMotion *, __m128 *, hkVector4f *))v4[11].__first_virtual_table_function__)(this, &v5, p);
}

// File Line: 130
// RVA: 0xD78280
void __fastcall hkpBoxMotion::applyTorque(hkpBoxMotion *this, const float deltaTime, hkVector4f *torque)
{
  hkBaseObjectVtbl *v3; // rax
  __m128 v4; // [rsp+20h] [rbp-18h]

  v3 = this->vfptr;
  v4 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0), torque->m_quad);
  v3[12].__vecDelDtor((hkBaseObject *)&this->vfptr, (unsigned int)&v4);
}

// File Line: 137
// RVA: 0xD782C0
void __fastcall hkpBoxMotion::getProjectedPointVelocity(hkpBoxMotion *this, hkVector4f *pos, hkVector4f *normal, float *velOut, float *invVirtMassOut)
{
  hkVector4f v5; // xmm4
  __m128 v6; // xmm0
  __m128 v7; // xmm8
  __m128 v8; // xmm6
  __m128 v9; // xmm1
  __m128 v10; // xmm6
  __m128 v11; // xmm2
  __m128 v12; // xmm7
  __m128 v13; // xmm3
  __m128 v14; // xmm1

  v5.m_quad = (__m128)this->m_motionState.m_transform.m_rotation.m_col2;
  v6 = _mm_sub_ps(pos->m_quad, this->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v7 = _mm_mul_ps(this->m_linearVelocity.m_quad, normal->m_quad);
  v8 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(normal->m_quad, normal->m_quad, 201), v6),
         _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), normal->m_quad));
  v9 = _mm_unpacklo_ps(
         this->m_motionState.m_transform.m_rotation.m_col0.m_quad,
         this->m_motionState.m_transform.m_rotation.m_col1.m_quad);
  v10 = _mm_shuffle_ps(v8, v8, 201);
  v11 = _mm_movelh_ps(v9, v5.m_quad);
  v12 = _mm_mul_ps(this->m_angularVelocity.m_quad, v10);
  v13 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(_mm_movehl_ps(v11, v9), v5.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v11)),
          _mm_mul_ps(
            _mm_shuffle_ps(v10, v10, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(
                this->m_motionState.m_transform.m_rotation.m_col0.m_quad,
                this->m_motionState.m_transform.m_rotation.m_col1.m_quad),
              v5.m_quad,
              228)));
  v14 = _mm_mul_ps(_mm_mul_ps(this->m_inertiaAndMassInv.m_quad, v13), v13);
  v13.m128_f32[0] = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 85))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0)))
                          + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 170)))
                  + COERCE_FLOAT(_mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 255));
  *velOut = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170)))
          + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 170)));
  *invVirtMassOut = v13.m128_f32[0];
}

// File Line: 152
// RVA: 0xD783F0
void __fastcall hkpBoxMotion::getProjectedPointVelocitySimd(hkpBoxMotion *this, hkVector4f *pos, hkVector4f *normal, hkSimdFloat32 *velOut, hkSimdFloat32 *invVirtMassOut)
{
  __m128 v5; // xmm0
  __m128 v6; // xmm3
  __m128 v7; // xmm6
  __m128 v8; // xmm6
  __m128 v9; // xmm1
  hkVector4f v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  __m128 v14; // xmm1

  v5 = _mm_sub_ps(pos->m_quad, this->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v6 = _mm_mul_ps(this->m_linearVelocity.m_quad, normal->m_quad);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(normal->m_quad, normal->m_quad, 201), v5),
         _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), normal->m_quad));
  v8 = _mm_shuffle_ps(v7, v7, 201);
  v9 = _mm_mul_ps(this->m_angularVelocity.m_quad, v8);
  velOut->m_real = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                       _mm_shuffle_ps(v9, v9, 170)),
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)),
                       _mm_shuffle_ps(v6, v6, 170)));
  v10.m_quad = (__m128)this->m_motionState.m_transform.m_rotation.m_col2;
  v11 = _mm_unpacklo_ps(
          this->m_motionState.m_transform.m_rotation.m_col0.m_quad,
          this->m_motionState.m_transform.m_rotation.m_col1.m_quad);
  v12 = _mm_movelh_ps(v11, v10.m_quad);
  v13 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(_mm_movehl_ps(v12, v11), v10.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v12)),
          _mm_mul_ps(
            _mm_shuffle_ps(v8, v8, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(
                this->m_motionState.m_transform.m_rotation.m_col0.m_quad,
                this->m_motionState.m_transform.m_rotation.m_col1.m_quad),
              v10.m_quad,
              228)));
  v14 = _mm_mul_ps(_mm_mul_ps(this->m_inertiaAndMassInv.m_quad, v13), v13);
  invVirtMassOut->m_real = _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                               _mm_shuffle_ps(v14, v14, 170)),
                             _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 255));
}

