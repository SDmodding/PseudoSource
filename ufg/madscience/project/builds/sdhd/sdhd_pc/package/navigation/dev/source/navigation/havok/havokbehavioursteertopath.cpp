// File Line: 31
// RVA: 0xE3BA0
void __fastcall UFG::HavokBehaviourSteerToPath::HavokBehaviourSteerToPath(
        UFG::HavokBehaviourSteerToPath *this,
        UFG::NavComponent *pNavComponent,
        hkaiCharacter *pCharacter,
        hkaiWorld *pWorld)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4

  hkaiSingleCharacterBehavior::hkaiSingleCharacterBehavior(this, pCharacter, pWorld);
  this->hkaiSingleCharacterBehavior::hkaiBehavior::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&UFG::HavokBehaviourSteerToPath::`vftable{for `hkReferencedObject};
  this->hkaiSingleCharacterBehavior::hkaiBehavior::hkaiPathRequestInfoOwner::vfptr = (hkaiPathRequestInfoOwnerVtbl *)&UFG::HavokBehaviourSteerToPath::`vftable{for `hkaiPathRequestInfoOwner};
  this->m_pNavComponent = pNavComponent;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_vVelocity.x = UFG::qVector3::msZero.x;
  this->m_vVelocity.y = y;
  this->m_vVelocity.z = z;
  this->m_fTurnVelocity = 0.0;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  this->m_vMyPreviousPos.x = UFG::qVector3::msZero.x;
  this->m_vMyPreviousPos.y = v8;
  this->m_vMyPreviousPos.z = v9;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  this->m_vActualVelocity.x = UFG::qVector3::msZero.x;
  this->m_vActualVelocity.y = v10;
  this->m_vActualVelocity.z = v11;
  v12 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  this->m_vDesiredVelocity.x = UFG::qVector3::msZero.x;
  this->m_vDesiredVelocity.y = v12;
  this->m_vDesiredVelocity.z = v13;
  this->m_fPreviousTimestep = 0.033;
  UFG::HavokBehaviourSteerToPath::ResetFacing(this);
}

// File Line: 35
// RVA: 0xF4160
__int64 __fastcall UFG::HavokBehaviourSteerToPath::calcVelocities(
        UFG::HavokBehaviourSteerToPath *this,
        float timestep,
        hkaiLocalSteeringInput *outputs,
        int outputsSize)
{
  UFG::NavComponent *m_pNavComponent; // rcx
  float x; // xmm9_4
  __m128 y_low; // xmm10
  float z; // xmm11_4
  UFG::NavModuleLocal *m_pNavModuleLocal; // rsi
  UFG::qVector4 *CurrentPosition; // rbp
  hkVector4f v12; // xmm3
  hkVector4f v13; // xmm3
  __m128 x_low; // xmm12
  __m128 v15; // xmm13
  __m128 z_low; // xmm14
  __m128 m_fTurnVelocity_low; // xmm15
  bool HasInput; // al
  bool m_bEnableAvoidance; // r14
  float m_fAdjustedSpeed; // xmm5_4
  float v21; // xmm3_4
  __m128 v22; // xmm8
  __m128 v23; // xmm1
  float v24; // xmm4_4
  float y; // xmm1_4
  __m128 v26; // xmm3
  float v27; // xmm4_4
  hkVector4f v28; // xmm8
  char v29; // al
  char v30; // dl
  float v31; // xmm2_4
  float v32; // xmm0_4
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm8
  __m128 v36; // xmm2
  float v37; // xmm6_4
  float v38; // xmm4_4
  __m128 v39; // xmm3
  float v40; // xmm5_4
  __m128 v41; // xmm2
  float v42; // xmm6_4
  __int64 result; // rax
  float v44; // [rsp+20h] [rbp-B8h]
  float v45; // [rsp+20h] [rbp-B8h]
  float v46; // [rsp+24h] [rbp-B4h]
  float v47; // [rsp+28h] [rbp-B0h]
  float v48; // [rsp+28h] [rbp-B0h]

  hkaiLocalSteeringInput::init(outputs, this->m_character.m_pntr);
  m_pNavComponent = this->m_pNavComponent;
  x = this->m_vCurrentForward.x;
  y_low = (__m128)LODWORD(this->m_vCurrentForward.y);
  z = this->m_vCurrentForward.z;
  m_pNavModuleLocal = m_pNavComponent->m_pNavModuleLocal;
  CurrentPosition = UFG::NavComponent::GetCurrentPosition(m_pNavComponent);
  v12.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)LODWORD(CurrentPosition->x), (__m128)LODWORD(CurrentPosition->z)),
                 _mm_unpacklo_ps((__m128)LODWORD(CurrentPosition->y), (__m128)(unsigned int)FLOAT_1_0));
  this->m_character.m_pntr->m_position = (hkVector4f)v12.m_quad;
  outputs->m_currentPosition = (hkVector4f)v12.m_quad;
  v13.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)LODWORD(this->m_vCurrentForward.x), (__m128)LODWORD(this->m_vCurrentForward.z)),
                 _mm_unpacklo_ps((__m128)LODWORD(this->m_vCurrentForward.y), (__m128)0i64));
  this->m_character.m_pntr->m_forward = (hkVector4f)v13.m_quad;
  outputs->m_currentForward = (hkVector4f)v13.m_quad;
  outputs->m_currentUp.m_quad = _xmm;
  x_low = (__m128)LODWORD(this->m_vVelocity.x);
  v15 = (__m128)LODWORD(this->m_vVelocity.y);
  z_low = (__m128)LODWORD(this->m_vVelocity.z);
  m_fTurnVelocity_low = (__m128)LODWORD(this->m_fTurnVelocity);
  HasInput = UFG::NavModuleLocal::HasInput(m_pNavModuleLocal);
  m_bEnableAvoidance = this->m_bEnableAvoidance;
  if ( HasInput )
  {
    v22 = (__m128)LODWORD(m_pNavModuleLocal->m_adjustedWaypoint.m_navPosition.m_vPosition.y);
    m_fAdjustedSpeed = m_pNavModuleLocal->m_fAdjustedSpeed;
    v21 = m_pNavModuleLocal->m_adjustedWaypoint.m_navPosition.m_vPosition.x - CurrentPosition->x;
    v22.m128_f32[0] = v22.m128_f32[0] - CurrentPosition->y;
    v23 = v22;
    v23.m128_f32[0] = (float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v21 * v21);
    v24 = _mm_sqrt_ps(v23).m128_f32[0];
    if ( v24 <= 0.0 )
    {
      y = UFG::qVector3::msZero.y;
      v44 = UFG::qVector3::msZero.x;
      v47 = UFG::qVector3::msZero.z;
    }
    else
    {
      v47 = (float)((float)(1.0 / v24) * 0.0) * m_fAdjustedSpeed;
      y = (float)((float)(1.0 / v24) * v22.m128_f32[0]) * m_fAdjustedSpeed;
      v44 = (float)((float)(1.0 / v24) * v21) * m_fAdjustedSpeed;
    }
    x = v44;
    y_low = (__m128)LODWORD(y);
    z = v47;
    v26 = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)LODWORD(v44), (__m128)LODWORD(v47)),
            _mm_unpacklo_ps((__m128)LODWORD(y), (__m128)0i64));
    outputs->m_desiredVelocity.m_quad = _mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, (__m128)0i64), 196);
    this->m_vDesiredVelocity.x = v44;
    this->m_vDesiredVelocity.y = y;
    this->m_vDesiredVelocity.z = v47;
    this->m_character.m_pntr->m_desiredSpeed = m_fAdjustedSpeed;
    this->m_character.m_pntr->m_state.m_storage = 1;
    outputs->m_distToLocalGoal = v24;
    if ( m_fAdjustedSpeed <= 0.0000099999997 )
      v27 = 0.0;
    else
      v27 = v24 / m_fAdjustedSpeed;
    outputs->m_timeToLocalGoal = v27;
    v28.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), _mm_unpacklo_ps(v15, m_fTurnVelocity_low));
    v29 = ((__int64 (__fastcall *)(UFG::HavokNavPosition *))this->m_pNavComponent->m_navPosition.vfptr->IsOnMesh)(&this->m_pNavComponent->m_navPosition);
    outputs->m_isLocalGoalLast.m_bool = 0;
    v30 = 0;
    if ( v29 )
      v30 = m_bEnableAvoidance;
    outputs->m_applyAvoidanceSteering.m_bool = v30;
  }
  else
  {
    outputs->m_desiredVelocity = 0i64;
    v31 = UFG::qVector3::msZero.z;
    v32 = UFG::qVector3::msZero.x;
    this->m_vDesiredVelocity.y = UFG::qVector3::msZero.y;
    this->m_vDesiredVelocity.z = v31;
    this->m_vDesiredVelocity.x = v32;
    *(_QWORD *)&outputs->m_distToLocalGoal = 0i64;
    this->m_character.m_pntr->m_desiredSpeed = 0.0;
    this->m_character.m_pntr->m_state.m_storage = 3;
    v33 = (__m128)LODWORD(this->m_vActualVelocity.z);
    v34 = (__m128)LODWORD(this->m_vActualVelocity.y);
    v35 = (__m128)LODWORD(this->m_vActualVelocity.x);
    outputs->m_isLocalGoalLast.m_bool = 1;
    outputs->m_applyAvoidanceSteering.m_bool = m_bEnableAvoidance;
    v28.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v35, v33), _mm_unpacklo_ps(v34, (__m128)0i64));
  }
  v36 = y_low;
  v36.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x)) + (float)(z * z);
  if ( v36.m128_f32[0] <= 0.0 )
  {
    v38 = this->m_vCurrentForward.y;
    v39 = (__m128)LODWORD(this->m_vCurrentForward.x);
    v40 = this->m_vCurrentForward.z;
    v41 = v39;
    v41.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v38 * v38)) + (float)(v40 * v40);
    if ( v41.m128_f32[0] == 0.0 )
      v42 = 0.0;
    else
      v42 = 1.0 / _mm_sqrt_ps(v41).m128_f32[0];
    v45 = v39.m128_f32[0] * v42;
    v46 = v38 * v42;
    v48 = v40 * v42;
  }
  else
  {
    v37 = 1.0 / _mm_sqrt_ps(v36).m128_f32[0];
    v45 = x * v37;
    v46 = y_low.m128_f32[0] * v37;
    v48 = z * v37;
  }
  result = 1i64;
  outputs->m_desiredFutureDir.m_quad = _mm_unpacklo_ps(
                                         _mm_unpacklo_ps((__m128)LODWORD(v45), (__m128)LODWORD(v48)),
                                         _mm_unpacklo_ps((__m128)LODWORD(v46), (__m128)0i64));
  this->m_character.m_pntr->m_velocity = (hkVector4f)v28.m_quad;
  outputs->m_currentVelocity = (hkVector4f)v28.m_quad;
  outputs->m_applyKinematicConstraints.m_bool = 1;
  return result;
}

// File Line: 152
// RVA: 0xF5A90
void __fastcall UFG::HavokBehaviourSteerToPath::update(UFG::HavokBehaviourSteerToPath *this, float timestep)
{
  float AngularVelocity; // xmm0_4
  float v5; // xmm0_4
  __m128 y_low; // xmm6
  float x; // xmm5_4
  __m128 v8; // xmm1
  float v9; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  hkVector4f v13; // xmm0
  float v14; // xmm1_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  UFG::qVector4 *CurrentPosition; // rax
  float v18; // xmm7_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qVector3 dest; // [rsp+20h] [rbp-48h] BYREF

  AngularVelocity = hkaiCharacter::getAngularVelocity(this->m_character.m_pntr);
  UFG::qRotateVectorZ(
    &dest,
    &this->m_vCurrentForward,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(AngularVelocity * timestep) ^ _xmm[0]));
  if ( (float)((float)(dest.y * dest.y) + (float)(dest.x * dest.x)) >= 0.0000000099999991
    && (float)((float)(this->m_vCurrentForward.y * this->m_vCurrentForward.y)
             + (float)(this->m_vCurrentForward.x * this->m_vCurrentForward.x)) >= 0.0000000099999991 )
  {
    v5 = UFG::qHeadingDifference2D(&this->m_vCurrentForward, &dest);
    dest.z = 0.0;
    y_low = (__m128)LODWORD(dest.y);
    x = dest.x;
    v8 = y_low;
    this->m_fTurnVelocity = v5 / timestep;
    v8.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
    if ( v8.m128_f32[0] >= 0.0000000099999991 )
    {
      if ( v8.m128_f32[0] == 0.0 )
        v9 = 0.0;
      else
        v9 = 1.0 / _mm_sqrt_ps(v8).m128_f32[0];
      v10 = x * v9;
      v11 = y_low.m128_f32[0] * v9;
      v12 = v9 * 0.0;
      this->m_vCurrentForward.z = v12;
      this->m_vCurrentForward.x = v10;
      this->m_vCurrentForward.y = v11;
      v13.m_quad = (__m128)this->m_character.m_pntr->m_velocity;
      v14 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 85).m128_f32[0];
      v15 = fsqrt((float)(v14 * v14) + (float)(v13.m_quad.m128_f32[0] * v13.m_quad.m128_f32[0]));
      if ( v15 <= 0.0 )
      {
        v15 = 0.0;
      }
      else
      {
        v16 = FLOAT_100_0;
        if ( v15 >= 100.0 )
          goto LABEL_12;
      }
      v16 = v15;
LABEL_12:
      this->m_vVelocity.x = v10 * v16;
      this->m_vVelocity.y = v11 * v16;
      this->m_vVelocity.z = v12 * v16;
      CurrentPosition = UFG::NavComponent::GetCurrentPosition(this->m_pNavComponent);
      v18 = 1.0 / this->m_fPreviousTimestep;
      v19 = CurrentPosition->y - this->m_vMyPreviousPos.y;
      v20 = CurrentPosition->x - this->m_vMyPreviousPos.x;
      this->m_vActualVelocity.z = 0.0;
      this->m_vActualVelocity.y = v18 * v19;
      this->m_vActualVelocity.x = v18 * v20;
      this->m_fPreviousTimestep = timestep;
      y = CurrentPosition->y;
      z = CurrentPosition->z;
      *(float *)&CurrentPosition = CurrentPosition->x;
      this->m_vMyPreviousPos.y = y;
      this->m_vMyPreviousPos.z = z;
      LODWORD(this->m_vMyPreviousPos.x) = (_DWORD)CurrentPosition;
    }
  }
}

// File Line: 200
// RVA: 0xF4AE0
void __fastcall UFG::HavokBehaviourSteerToPath::getApproximateFuturePositions(
        UFG::HavokBehaviourSteerToPath *this,
        int characterIndex,
        hkArray<hkVector4f,hkContainerTempAllocator> *positions)
{
  __m128 v5; // xmm6
  __int64 v6; // rbx
  char v7; // dl
  char v8; // cl
  char v9; // al

  if ( UFG::NavModuleLocal::HasInput(this->m_pNavComponent->m_pNavModuleLocal) )
  {
    v5 = _mm_unpacklo_ps(
           _mm_unpacklo_ps(
             (__m128)LODWORD(this->m_pNavComponent->m_pNavModuleLocal->m_adjustedWaypoint.m_navPosition.m_vPosition.x),
             (__m128)LODWORD(this->m_pNavComponent->m_pNavModuleLocal->m_adjustedWaypoint.m_navPosition.m_vPosition.z)),
           _mm_unpacklo_ps(
             (__m128)LODWORD(this->m_pNavComponent->m_pNavModuleLocal->m_adjustedWaypoint.m_navPosition.m_vPosition.y),
             (__m128)(unsigned int)FLOAT_1_0));
    v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v7 = ++*(_BYTE *)(v6 + 80);
    *(_DWORD *)(v6 + 4i64 * v7) = 1;
    *(_QWORD *)(v6 + 8i64 * v7 + 16) = "AI::HavokBehaviourSteerToPath::getApproximateFuturePositions";
    *(_QWORD *)(v6 + 8i64 * v7 + 48) = 0i64;
    v8 = *(_BYTE *)(v6 + 81);
    if ( v7 > v8 )
      v8 = v7;
    *(_BYTE *)(v6 + 81) = v8;
    if ( positions->m_size == (positions->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, positions, 16);
    positions->m_data[positions->m_size++].m_quad = v5;
    v9 = *(_BYTE *)(v6 + 80);
    if ( v9 > 0 )
    {
      *(_BYTE *)(v6 + 80) = v9 - 1;
    }
    else
    {
      *(_BYTE *)(v6 + 80) = 0;
      *(_DWORD *)v6 = 3;
      *(_QWORD *)(v6 + 16) = 0i64;
      *(_QWORD *)(v6 + 48) = 0i64;
    }
  }
}

// File Line: 216
// RVA: 0xF0DA0
void __fastcall UFG::HavokBehaviourSteerToPath::ResetFacing(UFG::HavokBehaviourSteerToPath *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float y; // xmm5_4
  float z; // xmm6_4
  float v6; // xmm2_4
  __m128 x_low; // xmm4
  __m128 v8; // xmm3

  m_pSimObject = this->m_pNavComponent->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v0.y;
  z = m_pTransformNodeComponent->mWorldTransform.v0.z;
  v6 = 0.0;
  this->m_vCurrentForward.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
  this->m_vCurrentForward.y = y;
  x_low = (__m128)LODWORD(this->m_vCurrentForward.x);
  this->m_vCurrentForward.z = z;
  v8 = x_low;
  v8.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
  if ( v8.m128_f32[0] != 0.0 )
    v6 = 1.0 / _mm_sqrt_ps(v8).m128_f32[0];
  this->m_vCurrentForward.x = x_low.m128_f32[0] * v6;
  this->m_vCurrentForward.z = v6 * z;
  this->m_vCurrentForward.y = v6 * y;
}

