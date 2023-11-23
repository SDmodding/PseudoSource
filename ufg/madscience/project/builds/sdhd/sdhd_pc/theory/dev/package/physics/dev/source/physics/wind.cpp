// File Line: 23
// RVA: 0x1458520
__int64 dynamic_initializer_for__UFG::WindAction::mWindBlow__()
{
  float v0; // xmm2_4
  __int64 result; // rax
  float v2; // xmm1_4

  v0 = 0.0;
  result = 6i64;
  v2 = *(float *)&FLOAT_1_0;
  LODWORD(UFG::WindAction::mWindBlow.tFrequency) = (unsigned int)FLOAT_1_0 & _xmm;
  do
  {
    v0 = v0 + v2;
    v2 = v2 * 0.5;
    --result;
  }
  while ( result );
  UFG::WindAction::mWindBlow.tAmplitude = 1.0 / v0;
  return result;
}

// File Line: 24
// RVA: 0x1458570
__int64 dynamic_initializer_for__UFG::WindAction::mWindTurbulance__()
{
  float v0; // xmm2_4
  __int64 result; // rax
  float v2; // xmm1_4

  v0 = 0.0;
  result = 6i64;
  v2 = *(float *)&FLOAT_1_0;
  LODWORD(UFG::WindAction::mWindTurbulance.tFrequency) = (unsigned int)FLOAT_1_0 & _xmm;
  do
  {
    v0 = v0 + v2;
    v2 = v2 * 0.5;
    --result;
  }
  while ( result );
  UFG::WindAction::mWindTurbulance.tAmplitude = 1.0 / v0;
  return result;
}

// File Line: 42
// RVA: 0x9A320
void __fastcall UFG::WindAction::WindAction(UFG::WindAction *this, hkpRigidBody *body, float windFactor)
{
  hkpUnaryAction::hkpUnaryAction(this, body, 0i64);
  this->vfptr = (hkBaseObjectVtbl *)&UFG::WindAction::`vftable;
  this->mWindFactor = windFactor;
  this->wforce = 0i64;
  this->wtorque = 0i64;
  this->mWindTicket = UFG::qRandom(6, &UFG::qDefaultSeed);
  this->mWindFactor = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) + 0.5) * this->mWindFactor;
}

// File Line: 59
// RVA: 0xB6360
void __fastcall UFG::WindAction::applyAction(UFG::WindAction *this, hkStepInfo *stepInfo, __int64 a3)
{
  hkpEntity *m_entity; // rsi
  int mWindTicket; // ecx
  __m128 m_quad; // xmm4
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  float v11; // xmm6_4
  float v12; // xmm8_4
  hkpShape *m_shape; // rcx
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  float v17; // xmm9_4
  float v18; // xmm13_4
  __m128 v19; // xmm0
  double v20; // xmm1_8
  hkVector4f v21; // xmm0
  bool v22; // cc
  float v23; // xmm12_4
  double v24; // xmm1_8
  hkVector4f v25; // xmm0
  bool v26; // cc
  float v27; // xmm6_4
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  __int64 v30; // rdx
  __int64 v31; // rdx
  __m128 v32[2]; // [rsp+20h] [rbp-88h] BYREF

  m_entity = this->m_entity;
  mWindTicket = this->mWindTicket;
  this->mWindTicket = mWindTicket + 1;
  if ( mWindTicket == 6 * (mWindTicket / 6) )
  {
    m_quad = UFG::WindAction::mWindPerp.m_quad;
    v7 = UFG::WindAction::mWindDirection.m_quad;
    v8 = m_entity->m_motion.m_motionState.m_transform.m_translation.m_quad;
    v9 = _mm_mul_ps(v8, UFG::WindAction::mWindDirection.m_quad);
    v10 = _mm_mul_ps(v8, UFG::WindAction::mWindPerp.m_quad);
    v11 = (float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0] + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
        + _mm_shuffle_ps(v10, v10, 170).m128_f32[0];
    v12 = (float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0] + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
        + _mm_shuffle_ps(v9, v9, 170).m128_f32[0];
    if ( m_entity == (hkpEntity *)-32i64 || (m_shape = m_entity->m_collidable.m_shape) == 0i64 )
    {
      v14 = (__m128)_xmm;
    }
    else
    {
      ((void (__fastcall *)(hkpShape *, hkMotionState *, __int64, __m128 *))m_shape->vfptr[2].__vecDelDtor)(
        m_shape,
        &m_entity->m_motion.m_motionState,
        a3,
        v32);
      m_quad = UFG::WindAction::mWindPerp.m_quad;
      v7 = UFG::WindAction::mWindDirection.m_quad;
      v14 = _mm_sub_ps(v32[1], v32[0]);
    }
    v15 = _mm_mul_ps(_mm_add_ps(_xmm, m_quad), v14);
    v16 = _mm_mul_ps(_mm_add_ps(_xmm, v7), v14);
    v17 = (float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0])
        + _mm_shuffle_ps(v16, v16, 170).m128_f32[0];
    v16.m128_u64[0] = LODWORD(UFG::WindAction::gWindStrengthFrequency);
    v19 = _mm_shuffle_ps(v15, v15, 0);
    v16.m128_f32[0] = (float)(UFG::WindAction::gWindStrengthFrequency * UFG::WindAction::mWindTicker)
                    + (float)(v12 * 0.1);
    v18 = (float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + v19.m128_f32[0])
        + _mm_shuffle_ps(v15, v15, 170).m128_f32[0];
    v19.m128_f32[0] = UFG::qNoise<float,float>::GetValue(&UFG::WindAction::mWindBlow, *(double *)v16.m128_u64);
    if ( v19.m128_f32[0] < 0.0 )
    {
      if ( v19.m128_f32[0] >= -0.5 )
      {
        v19.m128_f32[0] = v19.m128_f32[0] * 0.25;
        v19 = _mm_and_ps(v19, (__m128)_xmm);
      }
      else
      {
        v19 = 0i64;
      }
    }
    v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v17) * UFG::WindAction::mWindAmplitude) * this->mWindFactor;
    v21.m_quad = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), UFG::WindAction::mWindDirection.m_quad);
    this->wforce = (hkVector4f)v21.m_quad;
    *(_QWORD *)&v20 = LODWORD(UFG::WindAction::gWindTurbulenceFrequency);
    *(float *)&v20 = (float)(UFG::WindAction::gWindTurbulenceFrequency * UFG::WindAction::mWindTicker) + v11;
    v21.m_quad.m128_f32[0] = UFG::qNoise<float,float>::GetValue(&UFG::WindAction::mWindTurbulance, v20);
    v22 = v21.m_quad.m128_f32[0] <= 0.0;
    v23 = v21.m_quad.m128_f32[0];
    if ( v21.m_quad.m128_f32[0] < 0.0 )
    {
      if ( v21.m_quad.m128_f32[0] > -0.5 )
        goto LABEL_15;
      v22 = v21.m_quad.m128_f32[0] <= 0.0;
    }
    if ( v22 || v21.m_quad.m128_f32[0] >= 0.5 )
    {
LABEL_16:
      v21.m_quad.m128_f32[0] = (float)((float)(v21.m_quad.m128_f32[0] * v18) * UFG::WindAction::gWindTurbulenceAmplitude)
                             * this->mWindFactor;
      v25.m_quad = _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 0), UFG::WindAction::mWindPerp.m_quad),
                     this->wforce.m_quad);
      this->wforce = (hkVector4f)v25.m_quad;
      *(_QWORD *)&v24 = LODWORD(UFG::WindAction::gWindTurbulenceFrequency);
      *(float *)&v24 = (float)(UFG::WindAction::gWindTurbulenceFrequency * UFG::WindAction::mWindTicker) + 1000.0;
      v25.m_quad.m128_f32[0] = UFG::qNoise<float,float>::GetValue(&UFG::WindAction::mWindTurbulance, v24);
      v26 = v25.m_quad.m128_f32[0] <= 0.0;
      if ( v25.m_quad.m128_f32[0] < 0.0 )
      {
        if ( v25.m_quad.m128_f32[0] > -0.5 )
          goto LABEL_21;
        v26 = v25.m_quad.m128_f32[0] <= 0.0;
      }
      if ( v26 || v25.m_quad.m128_f32[0] >= 0.5 )
      {
        v27 = v25.m_quad.m128_f32[0] * 0.25;
        goto LABEL_23;
      }
LABEL_21:
      v27 = v25.m_quad.m128_f32[0] * 0.0099999998;
LABEL_23:
      v25.m_quad.m128_f32[0] = (float)((float)(hkpMotion::getMass(&m_entity->m_motion) * v27)
                                     * UFG::WindAction::mWindTorqueAmplitude)
                             * this->mWindFactor;
      v28 = v25.m_quad;
      v28.m128_f32[0] = v25.m_quad.m128_f32[0] * 0.2;
      v29 = v28;
      v28.m128_f32[0] = (float)(v25.m_quad.m128_f32[0] * 0.2) * v27;
      v29.m128_f32[0] = v29.m128_f32[0] * v23;
      this->wtorque.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v29, v25.m_quad), _mm_unpacklo_ps(v28, (__m128)0i64));
      goto LABEL_24;
    }
LABEL_15:
    v21.m_quad.m128_f32[0] = v21.m_quad.m128_f32[0] * 0.0099999998;
    goto LABEL_16;
  }
LABEL_24:
  hkpEntity::activate(m_entity);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))m_entity->m_motion.vfptr[13].__vecDelDtor)(
    &m_entity->m_motion,
    v30,
    &this->wforce);
  hkpEntity::activate(m_entity);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))m_entity->m_motion.vfptr[13].__first_virtual_table_function__)(
    &m_entity->m_motion,
    v31,
    &this->wtorque);
}

