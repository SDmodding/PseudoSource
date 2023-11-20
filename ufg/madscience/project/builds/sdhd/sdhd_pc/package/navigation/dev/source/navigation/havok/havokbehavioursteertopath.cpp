// File Line: 31
// RVA: 0xE3BA0
void __fastcall UFG::HavokBehaviourSteerToPath::HavokBehaviourSteerToPath(UFG::HavokBehaviourSteerToPath *this, UFG::NavComponent *pNavComponent, hkaiCharacter *pCharacter, hkaiWorld *pWorld)
{
  UFG::NavComponent *v4; // rbx
  UFG::HavokBehaviourSteerToPath *v5; // rdi
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4

  v4 = pNavComponent;
  v5 = this;
  hkaiSingleCharacterBehavior::hkaiSingleCharacterBehavior(
    (hkaiSingleCharacterBehavior *)&this->vfptr,
    pCharacter,
    pWorld);
  v5->vfptr = (hkBaseObjectVtbl *)&UFG::HavokBehaviourSteerToPath::`vftable{for `hkReferencedObject};
  v5->vfptr = (hkaiPathRequestInfoOwnerVtbl *)&UFG::HavokBehaviourSteerToPath::`vftable{for `hkaiPathRequestInfoOwner};
  v5->m_pNavComponent = v4;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  v5->m_vVelocity.x = UFG::qVector3::msZero.x;
  v5->m_vVelocity.y = v6;
  v5->m_vVelocity.z = v7;
  v5->m_fTurnVelocity = 0.0;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v5->m_vMyPreviousPos.x = UFG::qVector3::msZero.x;
  v5->m_vMyPreviousPos.y = v8;
  v5->m_vMyPreviousPos.z = v9;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  v5->m_vActualVelocity.x = UFG::qVector3::msZero.x;
  v5->m_vActualVelocity.y = v10;
  v5->m_vActualVelocity.z = v11;
  v12 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  v5->m_vDesiredVelocity.x = UFG::qVector3::msZero.x;
  v5->m_vDesiredVelocity.y = v12;
  v5->m_vDesiredVelocity.z = v13;
  v5->m_fPreviousTimestep = 0.033;
  UFG::HavokBehaviourSteerToPath::ResetFacing(v5);
}

// File Line: 35
// RVA: 0xF4160
signed __int64 __fastcall UFG::HavokBehaviourSteerToPath::calcVelocities(UFG::HavokBehaviourSteerToPath *this, float timestep, hkaiLocalSteeringInput *outputs, int outputsSize)
{
  UFG::HavokBehaviourSteerToPath *v4; // rbx
  hkaiLocalSteeringInput *v5; // rdi
  UFG::NavComponent *v6; // rcx
  float v7; // xmm9_4
  __m128 v8; // xmm10
  float v9; // xmm11_4
  UFG::NavModuleLocal *v10; // rsi
  UFG::qVector4 *v11; // rbp
  __m128 v12; // xmm3
  __m128 v13; // xmm3
  __m128 v14; // xmm12
  __m128 v15; // xmm13
  __m128 v16; // xmm14
  __m128 v17; // xmm15
  bool v18; // al
  bool v19; // r14
  float v20; // xmm5_4
  float v21; // xmm3_4
  __m128 v22; // xmm8
  __m128 v23; // xmm1
  float v24; // xmm4_4
  float v25; // xmm1_4
  __m128 v26; // xmm3
  float v27; // xmm4_4
  __m128 v28; // xmm8
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
  signed __int64 result; // rax
  float v44; // [rsp+20h] [rbp-B8h]
  float v45; // [rsp+20h] [rbp-B8h]
  float v46; // [rsp+24h] [rbp-B4h]
  float v47; // [rsp+28h] [rbp-B0h]
  float v48; // [rsp+28h] [rbp-B0h]

  v4 = this;
  v5 = outputs;
  hkaiLocalSteeringInput::init(outputs, this->m_character.m_pntr);
  v6 = v4->m_pNavComponent;
  v7 = v4->m_vCurrentForward.x;
  v8 = (__m128)LODWORD(v4->m_vCurrentForward.y);
  v9 = v4->m_vCurrentForward.z;
  v10 = v6->m_pNavModuleLocal;
  v11 = UFG::NavComponent::GetCurrentPosition(v6);
  v12 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v11->x), (__m128)LODWORD(v11->z)),
          _mm_unpacklo_ps((__m128)LODWORD(v11->y), (__m128)(unsigned int)FLOAT_1_0));
  v4->m_character.m_pntr->m_position.m_quad = v12;
  v5->m_currentPosition.m_quad = v12;
  v13 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v4->m_vCurrentForward.x), (__m128)LODWORD(v4->m_vCurrentForward.z)),
          _mm_unpacklo_ps((__m128)LODWORD(v4->m_vCurrentForward.y), (__m128)0i64));
  v4->m_character.m_pntr->m_forward.m_quad = v13;
  v5->m_currentForward.m_quad = v13;
  v5->m_currentUp.m_quad = _xmm;
  v14 = (__m128)LODWORD(v4->m_vVelocity.x);
  v15 = (__m128)LODWORD(v4->m_vVelocity.y);
  v16 = (__m128)LODWORD(v4->m_vVelocity.z);
  v17 = (__m128)LODWORD(v4->m_fTurnVelocity);
  v18 = UFG::NavModuleLocal::HasInput(v10);
  v19 = v4->m_bEnableAvoidance;
  if ( v18 )
  {
    v22 = (__m128)LODWORD(v10->m_adjustedWaypoint.m_navPosition.m_vPosition.y);
    v20 = v10->m_fAdjustedSpeed;
    v21 = v10->m_adjustedWaypoint.m_navPosition.m_vPosition.x - v11->x;
    v22.m128_f32[0] = v22.m128_f32[0] - v11->y;
    v23 = v22;
    v23.m128_f32[0] = (float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v21 * v21);
    LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v23);
    if ( v24 <= 0.0 )
    {
      v25 = UFG::qVector3::msZero.y;
      v44 = UFG::qVector3::msZero.x;
      v47 = UFG::qVector3::msZero.z;
    }
    else
    {
      v47 = (float)((float)(1.0 / v24) * 0.0) * v20;
      v25 = (float)((float)(1.0 / v24) * v22.m128_f32[0]) * v20;
      v44 = (float)((float)(1.0 / v24) * v21) * v20;
    }
    v7 = v44;
    v8 = (__m128)LODWORD(v25);
    v9 = v47;
    v26 = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)LODWORD(v44), (__m128)LODWORD(v47)),
            _mm_unpacklo_ps((__m128)LODWORD(v25), (__m128)0i64));
    v5->m_desiredVelocity.m_quad = _mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, (__m128)0i64), 196);
    v4->m_vDesiredVelocity.x = v44;
    v4->m_vDesiredVelocity.y = v25;
    v4->m_vDesiredVelocity.z = v47;
    v4->m_character.m_pntr->m_desiredSpeed = v20;
    v4->m_character.m_pntr->m_state.m_storage = 1;
    v5->m_distToLocalGoal = v24;
    if ( v20 <= 0.0000099999997 )
      v27 = 0.0;
    else
      v27 = v24 / v20;
    v5->m_timeToLocalGoal = v27;
    v28 = _mm_unpacklo_ps(_mm_unpacklo_ps(v14, v16), _mm_unpacklo_ps(v15, v17));
    v29 = ((__int64 (__fastcall *)(UFG::HavokNavPosition *))v4->m_pNavComponent->m_navPosition.vfptr->IsOnMesh)(&v4->m_pNavComponent->m_navPosition);
    v5->m_isLocalGoalLast.m_bool = 0;
    v30 = 0;
    if ( v29 )
      v30 = v19;
    v5->m_applyAvoidanceSteering.m_bool = v30;
  }
  else
  {
    v5->m_desiredVelocity = 0i64;
    v31 = UFG::qVector3::msZero.z;
    v32 = UFG::qVector3::msZero.x;
    v4->m_vDesiredVelocity.y = UFG::qVector3::msZero.y;
    v4->m_vDesiredVelocity.z = v31;
    v4->m_vDesiredVelocity.x = v32;
    *(_QWORD *)&v5->m_distToLocalGoal = 0i64;
    v4->m_character.m_pntr->m_desiredSpeed = 0.0;
    v4->m_character.m_pntr->m_state.m_storage = 3;
    v33 = (__m128)LODWORD(v4->m_vActualVelocity.z);
    v34 = (__m128)LODWORD(v4->m_vActualVelocity.y);
    v35 = (__m128)LODWORD(v4->m_vActualVelocity.x);
    v5->m_isLocalGoalLast.m_bool = 1;
    v5->m_applyAvoidanceSteering.m_bool = v19;
    v28 = _mm_unpacklo_ps(_mm_unpacklo_ps(v35, v33), _mm_unpacklo_ps(v34, (__m128)0i64));
  }
  v36 = v8;
  v36.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v36.m128_f32[0] <= 0.0 )
  {
    v38 = v4->m_vCurrentForward.y;
    v39 = (__m128)LODWORD(v4->m_vCurrentForward.x);
    v40 = v4->m_vCurrentForward.z;
    v41 = v39;
    v41.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v38 * v38)) + (float)(v40 * v40);
    if ( v41.m128_f32[0] == 0.0 )
      v42 = 0.0;
    else
      v42 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v41));
    v45 = v39.m128_f32[0] * v42;
    v46 = v38 * v42;
    v48 = v40 * v42;
  }
  else
  {
    if ( v36.m128_f32[0] == 0.0 )
      v37 = 0.0;
    else
      v37 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v36));
    v45 = v7 * v37;
    v46 = v8.m128_f32[0] * v37;
    v48 = v9 * v37;
  }
  result = 1i64;
  v5->m_desiredFutureDir.m_quad = _mm_unpacklo_ps(
                                    _mm_unpacklo_ps((__m128)LODWORD(v45), (__m128)LODWORD(v48)),
                                    _mm_unpacklo_ps((__m128)LODWORD(v46), (__m128)0i64));
  v4->m_character.m_pntr->m_velocity.m_quad = v28;
  v5->m_currentVelocity.m_quad = v28;
  v5->m_applyKinematicConstraints.m_bool = 1;
  return result;
}

// File Line: 152
// RVA: 0xF5A90
void __fastcall UFG::HavokBehaviourSteerToPath::update(UFG::HavokBehaviourSteerToPath *this, float timestep)
{
  UFG::HavokBehaviourSteerToPath *v2; // rdi
  float v3; // xmm8_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  __m128 v6; // xmm6
  float v7; // xmm5_4
  __m128 v8; // xmm1
  float v9; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  __m128 v13; // xmm0
  float v14; // xmm1_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  UFG::qVector4 *v17; // rax
  float v18; // xmm7_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  UFG::qVector3 dest; // [rsp+20h] [rbp-48h]

  v2 = this;
  v3 = timestep;
  v4 = hkaiCharacter::getAngularVelocity(this->m_character.m_pntr);
  UFG::qRotateVectorZ(&dest, &v2->m_vCurrentForward, COERCE_FLOAT(COERCE_UNSIGNED_INT(v4 * timestep) ^ _xmm[0]));
  if ( (float)((float)(dest.y * dest.y) + (float)(dest.x * dest.x)) >= 0.0000000099999991
    && (float)((float)(v2->m_vCurrentForward.y * v2->m_vCurrentForward.y)
             + (float)(v2->m_vCurrentForward.x * v2->m_vCurrentForward.x)) >= 0.0000000099999991 )
  {
    v5 = UFG::qHeadingDifference2D(&v2->m_vCurrentForward, &dest);
    dest.z = 0.0;
    v6 = (__m128)LODWORD(dest.y);
    v7 = dest.x;
    v8 = v6;
    v2->m_fTurnVelocity = v5 / v3;
    v8.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v7 * v7);
    if ( v8.m128_f32[0] >= 0.0000000099999991 )
    {
      if ( v8.m128_f32[0] == 0.0 )
        v9 = 0.0;
      else
        v9 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v8));
      v10 = v7 * v9;
      v11 = v6.m128_f32[0] * v9;
      v12 = v9 * 0.0;
      v2->m_vCurrentForward.z = v12;
      v2->m_vCurrentForward.x = v10;
      v2->m_vCurrentForward.y = v11;
      v13 = v2->m_character.m_pntr->m_velocity.m_quad;
      LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(v13, v13, 85);
      v15 = fsqrt((float)(v14 * v14) + (float)(v13.m128_f32[0] * v13.m128_f32[0]));
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
      v2->m_vVelocity.x = v10 * v16;
      v2->m_vVelocity.y = v11 * v16;
      v2->m_vVelocity.z = v12 * v16;
      v17 = UFG::NavComponent::GetCurrentPosition(v2->m_pNavComponent);
      v18 = 1.0 / v2->m_fPreviousTimestep;
      v19 = v17->y - v2->m_vMyPreviousPos.y;
      v20 = v17->x - v2->m_vMyPreviousPos.x;
      v2->m_vActualVelocity.z = 0.0;
      v2->m_vActualVelocity.y = v18 * v19;
      v2->m_vActualVelocity.x = v18 * v20;
      v2->m_fPreviousTimestep = v3;
      v21 = v17->y;
      v22 = v17->z;
      *(float *)&v17 = v17->x;
      v2->m_vMyPreviousPos.y = v21;
      v2->m_vMyPreviousPos.z = v22;
      LODWORD(v2->m_vMyPreviousPos.x) = (_DWORD)v17;
      return;
    }
  }
}

// File Line: 200
// RVA: 0xF4AE0
void __fastcall UFG::HavokBehaviourSteerToPath::getApproximateFuturePositions(UFG::HavokBehaviourSteerToPath *this, int characterIndex, hkArray<hkVector4f,hkContainerTempAllocator> *positions)
{
  UFG::HavokBehaviourSteerToPath *v3; // rbx
  hkArray<hkVector4f,hkContainerTempAllocator> *v4; // rdi
  __m128 v5; // xmm6
  signed __int64 v6; // rbx
  char v7; // dl
  __int64 v8; // rax
  char v9; // cl
  char v10; // al

  v3 = this;
  v4 = positions;
  if ( UFG::NavModuleLocal::HasInput(this->m_pNavComponent->m_pNavModuleLocal) )
  {
    v5 = _mm_unpacklo_ps(
           _mm_unpacklo_ps(
             (__m128)LODWORD(v3->m_pNavComponent->m_pNavModuleLocal->m_adjustedWaypoint.m_navPosition.m_vPosition.x),
             (__m128)LODWORD(v3->m_pNavComponent->m_pNavModuleLocal->m_adjustedWaypoint.m_navPosition.m_vPosition.z)),
           _mm_unpacklo_ps(
             (__m128)LODWORD(v3->m_pNavComponent->m_pNavModuleLocal->m_adjustedWaypoint.m_navPosition.m_vPosition.y),
             (__m128)(unsigned int)FLOAT_1_0));
    v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v7 = ++*(_BYTE *)(v6 + 80);
    v8 = v7;
    *(_DWORD *)(v6 + 4 * v8) = 1;
    *(_QWORD *)(v6 + 8 * v8 + 16) = "AI::HavokBehaviourSteerToPath::getApproximateFuturePositions";
    *(_QWORD *)(v6 + 8 * v8 + 48) = 0i64;
    v9 = *(_BYTE *)(v6 + 81);
    if ( v7 > v9 )
      v9 = v7;
    *(_BYTE *)(v6 + 81) = v9;
    if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 16);
    v4->m_data[v4->m_size++].m_quad = v5;
    v10 = *(_BYTE *)(v6 + 80);
    if ( v10 > 0 )
    {
      *(_BYTE *)(v6 + 80) = v10 - 1;
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
  UFG::HavokBehaviourSteerToPath *v1; // rbx
  UFG::SimObject *v2; // rcx
  UFG::TransformNodeComponent *v3; // rdi
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm2_4
  __m128 v7; // xmm4
  __m128 v8; // xmm3

  v1 = this;
  v2 = this->m_pNavComponent->m_pSimObject;
  if ( v2 )
    v3 = v2->m_pTransformNodeComponent;
  else
    v3 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  v4 = v3->mWorldTransform.v0.y;
  v5 = v3->mWorldTransform.v0.z;
  v6 = 0.0;
  v1->m_vCurrentForward.x = v3->mWorldTransform.v0.x;
  v1->m_vCurrentForward.y = v4;
  v7 = (__m128)LODWORD(v1->m_vCurrentForward.x);
  v1->m_vCurrentForward.z = v5;
  v8 = v7;
  v8.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v4 * v4)) + (float)(v5 * v5);
  if ( v8.m128_f32[0] != 0.0 )
    v6 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v8));
  v1->m_vCurrentForward.x = v7.m128_f32[0] * v6;
  v1->m_vCurrentForward.z = v6 * v5;
  v1->m_vCurrentForward.y = v6 * v4;
}

