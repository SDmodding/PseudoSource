// File Line: 23
// RVA: 0x1458520
signed __int64 dynamic_initializer_for__UFG::WindAction::mWindBlow__()
{
  float v0; // xmm2_4
  signed __int64 result; // rax
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
signed __int64 dynamic_initializer_for__UFG::WindAction::mWindTurbulance__()
{
  float v0; // xmm2_4
  signed __int64 result; // rax
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
  UFG::WindAction *v3; // rbx

  v3 = this;
  hkpUnaryAction::hkpUnaryAction((hkpUnaryAction *)&this->vfptr, (hkpEntity *)&body->vfptr, 0i64);
  v3->vfptr = (hkBaseObjectVtbl *)&UFG::WindAction::`vftable';
  v3->mWindFactor = windFactor;
  v3->wforce = 0i64;
  v3->wtorque = 0i64;
  v3->mWindTicket = UFG::qRandom(6, &UFG::qDefaultSeed);
  v3->mWindFactor = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) + 0.5) * v3->mWindFactor;
}

// File Line: 59
// RVA: 0xB6360
void __fastcall UFG::WindAction::applyAction(UFG::WindAction *this, hkStepInfo *stepInfo, __int64 a3)
{
  hkpEntity *v3; // rsi
  hkStepInfo *v4; // rbp
  UFG::WindAction *v5; // rdi
  int v6; // ecx
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm5
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  float v13; // xmm6_4
  float v14; // xmm8_4
  hkpShape *v15; // rcx
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  float v19; // xmm9_4
  float v20; // xmm13_4
  __m128 v21; // xmm0
  __m128 v22; // xmm0
  bool v23; // cf
  bool v24; // zf
  float v25; // xmm12_4
  __m128 v26; // xmm0
  bool v27; // cf
  bool v28; // zf
  float v29; // xmm6_4
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  __int128 v32; // xmm6
  __int64 v33; // rdx
  __int128 v34; // xmm6
  __int64 v35; // rdx
  __m128 v36; // [rsp+20h] [rbp-88h]
  __m128 v37; // [rsp+30h] [rbp-78h]

  v3 = this->m_entity;
  v4 = stepInfo;
  v5 = this;
  v6 = this->mWindTicket;
  v5->mWindTicket = v6 + 1;
  if ( v6 == 6 * (v6 / 6) )
  {
    v7 = v3->m_motion.m_motionState.m_transform.m_translation.m_quad;
    v8 = UFG::WindAction::mWindPerp.m_quad;
    v9 = UFG::WindAction::mWindDirection.m_quad;
    v10 = v7;
    v11 = _mm_mul_ps(v7, UFG::WindAction::mWindDirection.m_quad);
    v12 = _mm_mul_ps(v10, UFG::WindAction::mWindPerp.m_quad);
    v13 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170));
    v14 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170));
    if ( v3 != (hkpEntity *)-32i64 && (v15 = v3->m_collidable.m_shape) != 0i64 )
    {
      ((void (__fastcall *)(hkpShape *, hkMotionState *, __int64, __m128 *))v15->vfptr[2].__vecDelDtor)(
        v15,
        &v3->m_motion.m_motionState,
        a3,
        &v36);
      v8 = UFG::WindAction::mWindPerp.m_quad;
      v9 = UFG::WindAction::mWindDirection.m_quad;
      v16 = _mm_sub_ps(v37, v36);
    }
    else
    {
      v16 = (__m128)_xmm;
    }
    v17 = _mm_mul_ps(_mm_add_ps(_xmm, v8), v16);
    v18 = _mm_mul_ps(_mm_add_ps(_xmm, v9), v16);
    v19 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170));
    v21 = _mm_shuffle_ps(v17, v17, 0);
    v20 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + v21.m128_f32[0])
        + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170));
    v21.m128_f32[0] = UFG::qNoise<float,float>::GetValue(
                        &UFG::WindAction::mWindBlow,
                        (float)(UFG::WindAction::gWindStrengthFrequency * UFG::WindAction::mWindTicker)
                      + (float)(v14 * 0.1));
    if ( v21.m128_f32[0] < 0.0 )
    {
      if ( v21.m128_f32[0] >= -0.5 )
      {
        v21.m128_f32[0] = v21.m128_f32[0] * 0.25;
        v21 = _mm_and_ps(v21, (__m128)_xmm);
      }
      else
      {
        v21 = 0i64;
      }
    }
    v21.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v19) * UFG::WindAction::mWindAmplitude) * v5->mWindFactor;
    v22 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), UFG::WindAction::mWindDirection.m_quad);
    v5->wforce.m_quad = v22;
    v22.m128_f32[0] = UFG::qNoise<float,float>::GetValue(
                        &UFG::WindAction::mWindTurbulance,
                        (float)(UFG::WindAction::gWindTurbulenceFrequency * UFG::WindAction::mWindTicker) + v13);
    v23 = v22.m128_f32[0] < 0.0;
    v24 = v22.m128_f32[0] == 0.0;
    v25 = v22.m128_f32[0];
    if ( v22.m128_f32[0] < 0.0 )
    {
      if ( v22.m128_f32[0] > -0.5 )
        goto LABEL_15;
      v23 = v22.m128_f32[0] < 0.0;
      v24 = v22.m128_f32[0] == 0.0;
    }
    if ( v23 || v24 || v22.m128_f32[0] >= 0.5 )
    {
LABEL_16:
      v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v20) * UFG::WindAction::gWindTurbulenceAmplitude)
                      * v5->mWindFactor;
      v26 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), UFG::WindAction::mWindPerp.m_quad), v5->wforce.m_quad);
      v5->wforce.m_quad = v26;
      v26.m128_f32[0] = UFG::qNoise<float,float>::GetValue(
                          &UFG::WindAction::mWindTurbulance,
                          (float)(UFG::WindAction::gWindTurbulenceFrequency * UFG::WindAction::mWindTicker) + 1000.0);
      v27 = v26.m128_f32[0] < 0.0;
      v28 = v26.m128_f32[0] == 0.0;
      if ( v26.m128_f32[0] < 0.0 )
      {
        if ( v26.m128_f32[0] > -0.5 )
          goto LABEL_21;
        v27 = v26.m128_f32[0] < 0.0;
        v28 = v26.m128_f32[0] == 0.0;
      }
      if ( v27 || v28 || v26.m128_f32[0] >= 0.5 )
      {
        v29 = v26.m128_f32[0] * 0.25;
        goto LABEL_23;
      }
LABEL_21:
      v29 = v26.m128_f32[0] * 0.0099999998;
LABEL_23:
      v26.m128_f32[0] = (float)((float)(hkpMotion::getMass((hkpMotion *)&v3->m_motion.vfptr) * v29)
                              * UFG::WindAction::mWindTorqueAmplitude)
                      * v5->mWindFactor;
      v30 = v26;
      v30.m128_f32[0] = v26.m128_f32[0] * 0.2;
      v31 = v30;
      v30.m128_f32[0] = (float)(v26.m128_f32[0] * 0.2) * v29;
      v31.m128_f32[0] = v31.m128_f32[0] * v25;
      v5->wtorque.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v31, v26), _mm_unpacklo_ps(v30, (__m128)0i64));
      goto LABEL_24;
    }
LABEL_15:
    v22.m128_f32[0] = v22.m128_f32[0] * 0.0099999998;
    goto LABEL_16;
  }
LABEL_24:
  v32 = LODWORD(v4->m_deltaTime.m_storage);
  hkpEntity::activate(v3);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))v3->m_motion.vfptr[13].__vecDelDtor)(
    &v3->m_motion,
    v33,
    &v5->wforce);
  v34 = LODWORD(v4->m_deltaTime.m_storage);
  hkpEntity::activate(v3);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))v3->m_motion.vfptr[13].__first_virtual_table_function__)(
    &v3->m_motion,
    v35,
    &v5->wtorque);
}

