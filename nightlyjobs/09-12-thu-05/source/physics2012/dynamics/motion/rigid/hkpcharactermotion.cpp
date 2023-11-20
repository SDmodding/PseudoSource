// File Line: 22
// RVA: 0xD78510
void __fastcall hkpCharacterMotion::getInertiaLocal(hkpCharacterMotion *this, hkMatrix3f *inertia)
{
  __m128 v2; // xmm2
  __m128 v3; // xmm1
  __m128 v4; // xmm3

  v2 = _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 0);
  if ( v2.m128_f32[0] == 0.0 )
  {
    inertia->m_col0 = 0i64;
    inertia->m_col1 = 0i64;
    inertia->m_col2 = 0i64;
    inertia->m_col0.m_quad.m128_i32[0] = 1602224112;
    inertia->m_col1.m_quad.m128_i32[1] = 1602224112;
    inertia->m_col2.m_quad.m128_i32[2] = 1602224112;
  }
  else
  {
    v3 = _mm_rcp_ps(v2);
    v4 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v3, v2)), v3);
    inertia->m_col0.m_quad = _mm_mul_ps(transform.m_quad, v4);
    inertia->m_col1.m_quad = _mm_mul_ps(direction.m_quad, v4);
    inertia->m_col2.m_quad = _mm_mul_ps(stru_141A71280.m_quad, v4);
  }
}

// File Line: 37
// RVA: 0xD78590
void __fastcall hkpCharacterMotion::getInertiaWorld(hkpCharacterMotion *this, hkMatrix3f *inertia)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm2
  __m128 v4; // xmm3

  v2 = _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 0);
  v3 = _mm_rcp_ps(v2);
  v4 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v3, v2)), v3);
  inertia->m_col0.m_quad = _mm_mul_ps(transform.m_quad, v4);
  inertia->m_col1.m_quad = _mm_mul_ps(direction.m_quad, v4);
  inertia->m_col2.m_quad = _mm_mul_ps(stru_141A71280.m_quad, v4);
}

// File Line: 51
// RVA: 0xD785F0
void __fastcall hkpCharacterMotion::setInertiaLocal(hkpCharacterMotion *this, hkMatrix3f *inertia)
{
  __m128 v2; // xmm4
  __m128 v3; // xmm4
  __m128 v4; // xmm2
  __m128 v5; // xmm3

  v2 = _mm_or_ps(
         _mm_andnot_ps(
           (__m128)xmmword_141A9B360,
           _mm_or_ps(
             _mm_and_ps(inertia->m_col1.m_quad, (__m128)xmmword_141A9B340),
             _mm_andnot_ps((__m128)xmmword_141A9B340, inertia->m_col0.m_quad))),
         _mm_and_ps(inertia->m_col2.m_quad, (__m128)xmmword_141A9B360));
  v3 = _mm_max_ps(_mm_shuffle_ps(v2, v2, 170), _mm_max_ps(_mm_shuffle_ps(v2, v2, 85), _mm_shuffle_ps(v2, v2, 0)));
  v4 = _mm_rcp_ps(v3);
  v5 = _mm_andnot_ps(_mm_cmpeqps(v3, (__m128)0i64), _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, v3)), v4));
  this->m_inertiaAndMassInv.m_quad = _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, this->m_inertiaAndMassInv.m_quad), 196);
}

// File Line: 65
// RVA: 0xD78680
void __fastcall hkpCharacterMotion::setInertiaInvLocal(hkpCharacterMotion *this, hkMatrix3f *inertiaInv)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm3

  v2 = _mm_or_ps(
         _mm_andnot_ps(
           (__m128)xmmword_141A9B360,
           _mm_or_ps(
             _mm_and_ps(inertiaInv->m_col1.m_quad, (__m128)xmmword_141A9B340),
             _mm_andnot_ps((__m128)xmmword_141A9B340, inertiaInv->m_col0.m_quad))),
         _mm_and_ps(inertiaInv->m_col2.m_quad, (__m128)xmmword_141A9B360));
  v3 = _mm_min_ps(_mm_shuffle_ps(v2, v2, 170), _mm_min_ps(_mm_shuffle_ps(v2, v2, 85), _mm_shuffle_ps(v2, v2, 0)));
  this->m_inertiaAndMassInv.m_quad = _mm_shuffle_ps(v3, _mm_unpackhi_ps(v3, this->m_inertiaAndMassInv.m_quad), 196);
}

// File Line: 74
// RVA: 0xD786E0
void __fastcall hkpCharacterMotion::getInertiaInvLocal(hkpCharacterMotion *this, hkMatrix3f *inertiaInv)
{
  __m128 v2; // xmm3

  v2 = _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 0);
  inertiaInv->m_col1.m_quad = _mm_mul_ps(direction.m_quad, v2);
  inertiaInv->m_col2.m_quad = _mm_mul_ps(stru_141A71280.m_quad, v2);
  inertiaInv->m_col0.m_quad = _mm_mul_ps(transform.m_quad, v2);
}

// File Line: 81
// RVA: 0xD78720
void __fastcall hkpCharacterMotion::getInertiaInvWorld(hkpCharacterMotion *this, hkMatrix3f *inertiaInv)
{
  __m128 v2; // xmm3

  v2 = _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 0);
  inertiaInv->m_col1.m_quad = _mm_mul_ps(direction.m_quad, v2);
  inertiaInv->m_col2.m_quad = _mm_mul_ps(stru_141A71280.m_quad, v2);
  inertiaInv->m_col0.m_quad = _mm_mul_ps(transform.m_quad, v2);
}

// File Line: 92
// RVA: 0xD78880
void __fastcall hkpCharacterMotion::applyPointImpulse(hkpCharacterMotion *this, hkVector4f *imp, hkVector4f *p)
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

// File Line: 107
// RVA: 0xD788E0
void __fastcall hkpCharacterMotion::applyAngularImpulse(hkpCharacterMotion *this, hkVector4f *imp)
{
  this->m_angularVelocity.m_quad = _mm_add_ps(
                                     _mm_mul_ps(this->m_inertiaAndMassInv.m_quad, imp->m_quad),
                                     this->m_angularVelocity.m_quad);
}

// File Line: 119
// RVA: 0xD78900
void __fastcall hkpCharacterMotion::applyForce(hkpCharacterMotion *this, const float deltaTime, hkVector4f *force)
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

// File Line: 125
// RVA: 0xD78940
void __fastcall hkpCharacterMotion::applyForce(hkpCharacterMotion *this, const float deltaTime, hkVector4f *force, hkVector4f *p)
{
  hkBaseObjectVtbl *v4; // rax
  __m128 v5; // [rsp+20h] [rbp-18h]

  v4 = this->vfptr;
  v5 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0), force->m_quad);
  ((void (__fastcall *)(hkpCharacterMotion *, __m128 *, hkVector4f *))v4[11].__first_virtual_table_function__)(
    this,
    &v5,
    p);
}

// File Line: 132
// RVA: 0xD78980
void __fastcall hkpCharacterMotion::applyTorque(hkpCharacterMotion *this, const float deltaTime, hkVector4f *torque)
{
  hkBaseObjectVtbl *v3; // rax
  __m128 v4; // [rsp+20h] [rbp-18h]

  v3 = this->vfptr;
  v4 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0), torque->m_quad);
  v3[12].__vecDelDtor((hkBaseObject *)&this->vfptr, (unsigned int)&v4);
}

// File Line: 139
// RVA: 0xD78760
void __fastcall hkpCharacterMotion::getProjectedPointVelocity(hkpCharacterMotion *this, hkVector4f *pos, hkVector4f *normal, float *velOut, float *invVirtMassOut)
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
  *invVirtMassOut = this->m_inertiaAndMassInv.m_quad.m128_f32[3];
}

// File Line: 150
// RVA: 0xD787F0
void __fastcall hkpCharacterMotion::getProjectedPointVelocitySimd(hkpCharacterMotion *this, hkVector4f *pos, hkVector4f *normal, hkSimdFloat32 *velOut, hkSimdFloat32 *invVirtMassOut)
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
  invVirtMassOut->m_real = _mm_shuffle_ps(this->m_inertiaAndMassInv.m_quad, this->m_inertiaAndMassInv.m_quad, 255);
}

