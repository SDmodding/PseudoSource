// File Line: 42
// RVA: 0x1460B50
__int64 dynamic_initializer_for__UFG::NavModuleLocalRVO::ms_aCharacters__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::NavModuleLocalRVO::ms_aCharacters__);
}

// File Line: 43
// RVA: 0x1460B40
__int64 dynamic_initializer_for__UFG::NavModuleLocalRVO::ms_aBehaviors__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::NavModuleLocalRVO::ms_aBehaviors__);
}

// File Line: 50
// RVA: 0xE4EB0
void __fastcall UFG::NavModuleLocalRVO::NavModuleLocalRVO(UFG::NavModuleLocalRVO *this, UFG::NavComponent *parent)
{
  UFG::NavModuleLocalRVO *v2; // rbx

  v2 = this;
  UFG::NavModuleLocal::NavModuleLocal((UFG::NavModuleLocal *)&this->vfptr, parent);
  v2->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocalRVO::`vftable;
  v2->m_phkaiCharacter = 0i64;
  v2->m_phkaiBehaviour = 0i64;
  hkaiAvoidanceProperties::hkaiAvoidanceProperties(&v2->m_AvoidanceProperties);
  v2->m_bStopped = 1;
  UFG::NavModuleLocalRVO::InitCharacter(v2);
  UFG::NavModuleLocalRVO::InitBehaviour(v2);
}

// File Line: 77
// RVA: 0xF0E90
void __fastcall UFG::NavModuleLocalRVO::Shutdown(UFG::NavModuleLocalRVO *this)
{
  hkaiBehavior *v1; // rdx
  UFG::NavModuleLocalRVO *v2; // rbx
  signed int v3; // er8
  signed __int64 v4; // rax
  int v5; // ecx
  hkaiBehavior *v6; // rcx
  hkaiCharacter *v7; // r8
  hkaiCharacter **v8; // r9
  signed int v9; // ecx
  signed __int64 v10; // rax
  int v11; // edx
  hkaiCharacter *v12; // rcx

  v1 = this->m_phkaiBehaviour;
  v2 = this;
  if ( v1 )
  {
    v3 = 0;
    v4 = 0i64;
    if ( UFG::NavModuleLocalRVO::ms_aBehaviors.m_size <= 0 )
    {
LABEL_5:
      v3 = -1;
    }
    else
    {
      while ( UFG::NavModuleLocalRVO::ms_aBehaviors.m_data[v4] != v1 )
      {
        ++v4;
        ++v3;
        if ( v4 >= UFG::NavModuleLocalRVO::ms_aBehaviors.m_size )
          goto LABEL_5;
      }
    }
    v5 = UFG::NavModuleLocalRVO::ms_aBehaviors.m_size - 1;
    UFG::NavModuleLocalRVO::ms_aBehaviors.m_size = v5;
    if ( v5 != v3 )
      UFG::NavModuleLocalRVO::ms_aBehaviors.m_data[v3] = UFG::NavModuleLocalRVO::ms_aBehaviors.m_data[v5];
    v6 = v2->m_phkaiBehaviour;
    if ( v6 )
      v6->vfptr->__vecDelDtor((hkBaseObject *)&v6->vfptr, 1u);
    v2->m_phkaiBehaviour = 0i64;
  }
  v7 = v2->m_phkaiCharacter;
  if ( v7 )
  {
    v8 = UFG::NavModuleLocalRVO::ms_aCharacters.m_data;
    v9 = 0;
    v10 = 0i64;
    if ( UFG::NavModuleLocalRVO::ms_aCharacters.m_size <= 0 )
    {
LABEL_15:
      v9 = -1;
    }
    else
    {
      while ( UFG::NavModuleLocalRVO::ms_aCharacters.m_data[v10] != v7 )
      {
        ++v10;
        ++v9;
        if ( v10 >= UFG::NavModuleLocalRVO::ms_aCharacters.m_size )
          goto LABEL_15;
      }
    }
    v11 = UFG::NavModuleLocalRVO::ms_aCharacters.m_size - 1;
    UFG::NavModuleLocalRVO::ms_aCharacters.m_size = v11;
    if ( v11 != v9 )
    {
      v7 = (hkaiCharacter *)&UFG::NavModuleLocalRVO::ms_aCharacters.m_data[v11];
      UFG::NavModuleLocalRVO::ms_aCharacters.m_data[v9] = (hkaiCharacter *)v7->vfptr;
    }
    v12 = v2->m_phkaiCharacter;
    if ( v12 )
      ((void (__fastcall *)(hkaiCharacter *, signed __int64, hkaiCharacter *, hkaiCharacter **))v12->vfptr->__vecDelDtor)(
        v12,
        1i64,
        v7,
        v8);
    v2->m_phkaiCharacter = 0i64;
  }
}

// File Line: 100
// RVA: 0xEF1D0
void __fastcall UFG::NavModuleLocalRVO::InitCharacter(UFG::NavModuleLocalRVO *this)
{
  UFG::NavModuleLocalRVO *v1; // rdi
  UFG::qVector4 *v2; // rax
  UFG::SimObject *v3; // rbx
  UFG::TransformNodeComponent *v4; // rbx
  __m128 v5; // xmm4
  __m128 v6; // xmm5
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  float v9; // xmm1_4
  UFG::SimObjectCharacter *v10; // rbx
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  signed __int64 v13; // rbx
  char v14; // dl
  __int64 v15; // rax
  char v16; // cl
  _QWORD **v17; // rax
  hkaiCharacter *v18; // rax
  hkaiCharacter *v19; // rax
  int v20; // ecx
  char v21; // al
  hkaiCharacter::Cinfo cinfo; // [rsp+30h] [rbp-78h]

  v1 = this;
  hkaiCharacter::Cinfo::Cinfo(&cinfo);
  v2 = UFG::NavComponent::GetCurrentPosition(v1->m_navComponent);
  cinfo.m_initialPosition.m_quad = _mm_unpacklo_ps(
                                     _mm_unpacklo_ps((__m128)LODWORD(v2->x), (__m128)LODWORD(v2->z)),
                                     _mm_unpacklo_ps((__m128)LODWORD(v2->y), (__m128)(unsigned int)FLOAT_1_0));
  v3 = v1->m_navComponent->m_pSimObject;
  if ( v3 )
    v4 = v3->m_pTransformNodeComponent;
  else
    v4 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  v5 = (__m128)LODWORD(v4->mWorldTransform.v0.y);
  v6 = (__m128)LODWORD(v4->mWorldTransform.v0.x);
  v7 = (__m128)LODWORD(v4->mWorldTransform.v0.z);
  v8 = v6;
  v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5.m128_f32[0] * v5.m128_f32[0]))
                 + (float)(v7.m128_f32[0] * v7.m128_f32[0]);
  if ( v8.m128_f32[0] == 0.0 )
    v9 = 0.0;
  else
    v9 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v8));
  v7.m128_f32[0] = v7.m128_f32[0] * v9;
  v5.m128_f32[0] = v5.m128_f32[0] * v9;
  v6.m128_f32[0] = v6.m128_f32[0] * v9;
  cinfo.m_initialForward.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v6, v7), _mm_unpacklo_ps(v5, (__m128)0i64));
  cinfo.m_desiredSpeed = 0.0;
  v10 = (UFG::SimObjectCharacter *)v1->m_navComponent->m_pSimObject;
  if ( v10 == UFG::GetLocalPlayer() )
    v11 = (__m128)LODWORD(kfPlayerSensorHalfSize);
  else
    v11 = (__m128)LODWORD(kfOtherSensorHalfSize);
  v12 = _mm_xor_ps(v11, *(__m128 *)_xmm);
  v1->m_AvoidanceProperties.m_localSensorAabb.m_min.m_quad = _mm_unpacklo_ps(
                                                               _mm_unpacklo_ps(v12, (__m128)LODWORD(FLOAT_N0_75)),
                                                               _mm_unpacklo_ps(v12, (__m128)(unsigned int)FLOAT_1_0));
  v1->m_AvoidanceProperties.m_localSensorAabb.m_max.m_quad = _mm_unpacklo_ps(
                                                               _mm_unpacklo_ps(v11, (__m128)LODWORD(FLOAT_0_75)),
                                                               _mm_unpacklo_ps(v11, (__m128)(unsigned int)FLOAT_1_0));
  cinfo.m_initialPosition = 0i64;
  cinfo.m_initialForward = (hkVector4f)_xmm;
  cinfo.m_up.m_quad = _xmm;
  cinfo.m_desiredSpeed = 0.0;
  v1->m_AvoidanceProperties.m_avoidanceSolverType.m_storage = UFG::NavAvoidanceStrategyRVO::msAvoidanceSolverType;
  cinfo.m_avoidanceProperties = &v1->m_AvoidanceProperties;
  UFG::NavModuleLocalRVO::UpdateAvoidanceProperties(v1);
  cinfo.m_radius = UFG::NavComponent::GetAvoidanceRadius(v1->m_navComponent);
  cinfo.m_userData = 0i64;
  v13 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v14 = ++*(_BYTE *)(v13 + 80);
  v15 = v14;
  *(_DWORD *)(v13 + 4 * v15) = 1;
  *(_QWORD *)(v13 + 8 * v15 + 16) = "AI::hkaiCharacter";
  *(_QWORD *)(v13 + 8 * v15 + 48) = 0i64;
  v16 = *(_BYTE *)(v13 + 81);
  if ( v14 > v16 )
    v16 = v14;
  *(_BYTE *)(v13 + 81) = v16;
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (hkaiCharacter *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(v17[11], 192i64);
  if ( v18 )
    hkaiCharacter::hkaiCharacter(v18, &cinfo);
  else
    v19 = 0i64;
  v1->m_phkaiCharacter = v19;
  v20 = UFG::NavModuleLocalRVO::ms_aCharacters.m_size;
  if ( UFG::NavModuleLocalRVO::ms_aCharacters.m_size == (UFG::NavModuleLocalRVO::ms_aCharacters.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &UFG::NavModuleLocalRVO::ms_aCharacters,
      8);
    v20 = UFG::NavModuleLocalRVO::ms_aCharacters.m_size;
  }
  UFG::NavModuleLocalRVO::ms_aCharacters.m_data[v20] = v1->m_phkaiCharacter;
  ++UFG::NavModuleLocalRVO::ms_aCharacters.m_size;
  v21 = *(_BYTE *)(v13 + 80);
  if ( v21 > 0 )
  {
    *(_BYTE *)(v13 + 80) = v21 - 1;
  }
  else
  {
    *(_BYTE *)(v13 + 80) = 0;
    *(_DWORD *)v13 = 3;
    *(_QWORD *)(v13 + 16) = 0i64;
    *(_QWORD *)(v13 + 48) = 0i64;
  }
}

// File Line: 159
// RVA: 0xF0D40
void __fastcall UFG::NavModuleLocalRVO::Reset(UFG::NavModuleLocalRVO *this)
{
  UFG::NavModuleLocalRVO *v1; // rbx

  v1 = this;
  UFG::NavModuleLocal::Reset((UFG::NavModuleLocal *)&this->vfptr);
  if ( !v1->m_phkaiCharacter )
  {
    UFG::NavModuleLocalRVO::InitCharacter(v1);
    UFG::NavModuleLocalRVO::InitBehaviour(v1);
  }
  UFG::HavokBehaviourSteerToPath::ResetFacing((UFG::HavokBehaviourSteerToPath *)v1->m_phkaiBehaviour);
  v1->m_bStopped = 1;
  v1->m_bAvoidingBackwardsPause = 0;
  v1->m_fAvoidingBackwardsTimer = 0.0;
}

// File Line: 178
// RVA: 0xF3340
void __fastcall UFG::NavModuleLocalRVO::UpdateAvoidanceProperties(UFG::NavModuleLocalRVO *this)
{
  UFG::NavModuleLocalRVO *v1; // rbx
  unsigned int v2; // eax
  UFG::SimObjectCVBase *v3; // rcx
  char v4; // di
  UFG::AICharacterControllerBaseComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::AICharacterControllerBaseComponent *v7; // rax
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  unsigned __int8 v11; // al
  float v12; // xmm2_4
  float v13; // xmm1_4
  UFG::qVector4 *v14; // rax
  __m128 v15; // xmm2
  float v16; // xmm1_4
  UFG::NavComponent *v17; // rdi
  hkaiBehavior *v18; // rdi

  v1 = this;
  v2 = _S9_1;
  if ( !(_S9_1 & 1) )
  {
    v2 = _S9_1 | 1;
    _S9_1 |= 1u;
    kfMaxTurnVelocity = kfMaxVelocity * 0.80000001;
  }
  if ( !(v2 & 2) )
  {
    _S9_1 = v2 | 2;
    kfPenaltyLimitBoundaryDistance = UFG::NavComponent::GetAvoidanceRadius(this->m_navComponent) * 5.0;
  }
  v3 = (UFG::SimObjectCVBase *)v1->m_navComponent->m_pSimObject;
  v4 = 0;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
    v5 = v7;
  }
  else
  {
    v5 = 0i64;
  }
  v8 = v5->m_Intention.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_StrafeFacing.m_EnumValue >> 6];
  if ( _bittest64((const signed __int64 *)&v8, gActionRequest_StrafeFacing.m_EnumValue & 0x3F)
    || (v9 = v5->m_Intention.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Focus.m_EnumValue >> 6],
        _bittest64((const signed __int64 *)&v9, gActionRequest_Focus.m_EnumValue & 0x3F)) )
  {
    v4 = 1;
  }
  v1->m_bStrafing = v4;
  v10 = v5->m_Intention.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_AIAvoidanceStrafe.m_EnumValue >> 6];
  v11 = _bittest64((const signed __int64 *)&v10, gActionRequest_AIAvoidanceStrafe.m_EnumValue & 0x3F);
  v1->m_bAvoidanceStrafe = v11;
  if ( v1->m_bStopped || (v12 = v1->m_fAdjustedSpeed, v12 <= 0.0) )
  {
    v1->m_AvoidanceProperties.m_movementProperties.m_maxAcceleration = kfMaxAcceleration * 1000.0;
    v1->m_AvoidanceProperties.m_movementProperties.m_maxDeceleration = kfMaxDeceleration * 1000.0;
    v1->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity = 188.49556;
    v1->m_AvoidanceProperties.m_movementProperties.m_minVelocity = kfMinVelocity;
    v13 = kfMaxVelocity;
    v1->m_AvoidanceProperties.m_movementProperties.m_maxTurnVelocity = kfMaxTurnVelocity;
  }
  else
  {
    v1->m_AvoidanceProperties.m_movementProperties.m_maxAcceleration = kfMaxAcceleration;
    v1->m_AvoidanceProperties.m_movementProperties.m_maxDeceleration = kfMaxDeceleration;
    if ( v4 )
    {
      v1->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity = kfMaxAngularVelocityStrafing;
    }
    else if ( v11 )
    {
      v1->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity = kfMaxAngularVelocity;
    }
    else
    {
      v1->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity = v1->m_navComponent->m_fMaxAngularVelocity;
    }
    v1->m_AvoidanceProperties.m_movementProperties.m_minVelocity = v12 * kfMinVelocityRatio;
    v13 = v12 * kfMaxVelocityRatio;
    v1->m_AvoidanceProperties.m_movementProperties.m_maxTurnVelocity = v12 * 0.80000001;
  }
  v1->m_AvoidanceProperties.m_movementProperties.m_maxVelocity = v13;
  v1->m_AvoidanceProperties.m_agentLimitTime = kfPenaltyAgentLimitTime;
  v1->m_AvoidanceProperties.m_obstacleLimitTime = kfPenaltyObstacleLimitTime;
  v1->m_AvoidanceProperties.m_boundaryLimitTime = kfPenaltyBoundaryLimitTime;
  v1->m_AvoidanceProperties.m_limitObstacleDistance = kfPenaltyLimitObstacleDistance;
  v1->m_AvoidanceProperties.m_limitObstacleVelocity = kfPenaltyLimitObstacleVelocity;
  v14 = UFG::NavComponent::GetCurrentPosition(v1->m_navComponent);
  v15 = (__m128)LODWORD(v14->y);
  v15.m128_f32[0] = (float)((float)((float)(v15.m128_f32[0] - v1->m_adjustedWaypoint.m_navPosition.m_vPosition.y)
                                  * (float)(v15.m128_f32[0] - v1->m_adjustedWaypoint.m_navPosition.m_vPosition.y))
                          + (float)((float)(v14->x - v1->m_adjustedWaypoint.m_navPosition.m_vPosition.x)
                                  * (float)(v14->x - v1->m_adjustedWaypoint.m_navPosition.m_vPosition.x)))
                  + (float)((float)(v14->z - v1->m_adjustedWaypoint.m_navPosition.m_vPosition.z)
                          * (float)(v14->z - v1->m_adjustedWaypoint.m_navPosition.m_vPosition.z));
  LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v15);
  if ( v16 >= kfPenaltyLimitBoundaryDistance )
    v16 = kfPenaltyLimitBoundaryDistance;
  v1->m_AvoidanceProperties.m_limitBoundaryDistance = v16;
  v1->m_AvoidanceProperties.m_avoidanceSolverType.m_storage = UFG::NavAvoidanceStrategyRVO::msAvoidanceSolverType;
  if ( !(_BYTE)UFG::NavAvoidanceStrategyRVO::msAvoidanceSolverType )
  {
    v1->m_AvoidanceProperties.m_collisionPenalty = kfSamplingCollisionPenalty;
    v1->m_AvoidanceProperties.m_penetrationPenalty = kfSamplingPenetrationPenalty;
    v1->m_AvoidanceProperties.m_wallFollowingAngle = kfSamplingWallFollowingAngle;
    v1->m_AvoidanceProperties.m_velocityHysteresis = kfSamplingVelocityHystersis;
    v1->m_AvoidanceProperties.m_sidednessChangingPenalty = kfSamplingSidednessChangingPenalty;
  }
  if ( v1->m_phkaiCharacter )
  {
    v17 = v1->m_navComponent;
    if ( v17->m_navPosition.vfptr->IsMeshPositionValid((UFG::NavPositionBase *)&v17->m_navPosition.vfptr) )
      v1->m_phkaiCharacter->m_currentNavMeshFace = v17->m_navPosition.m_packedKey;
    else
      v1->m_phkaiCharacter->m_currentNavMeshFace = -1;
  }
  v18 = v1->m_phkaiBehaviour;
  if ( v18 )
  {
    BYTE4(v18[3].m_world.m_pntr) = UFG::NavModuleLocal::IsAvoidanceEnabled((UFG::NavModuleLocal *)&v1->vfptr);
    if ( v1->m_phkaiCharacter )
      v1->m_phkaiCharacter->m_radius = UFG::NavComponent::GetAvoidanceRadius(v1->m_navComponent);
  }
}

// File Line: 321
// RVA: 0xEF090
void __fastcall UFG::NavModuleLocalRVO::InitBehaviour(UFG::NavModuleLocalRVO *this)
{
  UFG::NavModuleLocalRVO *v1; // rdi
  signed __int64 v2; // rbx
  char v3; // dl
  __int64 v4; // rax
  char v5; // cl
  _QWORD **v6; // rax
  UFG::HavokBehaviourSteerToPath *v7; // rax
  int v8; // ecx
  char v9; // al

  v1 = this;
  v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v3 = ++*(_BYTE *)(v2 + 80);
  v4 = v3;
  *(_DWORD *)(v2 + 4 * v4) = 1;
  *(_QWORD *)(v2 + 8 * v4 + 16) = "AI::addBehavior";
  *(_QWORD *)(v2 + 8 * v4 + 48) = 0i64;
  v5 = *(_BYTE *)(v2 + 81);
  if ( v3 > v5 )
    v5 = v3;
  *(_BYTE *)(v2 + 81) = v5;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (UFG::HavokBehaviourSteerToPath *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(
                                           v6[11],
                                           128i64);
  if ( v7 )
    UFG::HavokBehaviourSteerToPath::HavokBehaviourSteerToPath(
      v7,
      v1->m_navComponent,
      v1->m_phkaiCharacter,
      (hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  v1->m_phkaiBehaviour = (hkaiBehavior *)&v7->vfptr;
  v8 = UFG::NavModuleLocalRVO::ms_aBehaviors.m_size;
  if ( UFG::NavModuleLocalRVO::ms_aBehaviors.m_size == (UFG::NavModuleLocalRVO::ms_aBehaviors.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &UFG::NavModuleLocalRVO::ms_aBehaviors,
      8);
    v8 = UFG::NavModuleLocalRVO::ms_aBehaviors.m_size;
  }
  UFG::NavModuleLocalRVO::ms_aBehaviors.m_data[v8] = v1->m_phkaiBehaviour;
  ++UFG::NavModuleLocalRVO::ms_aBehaviors.m_size;
  v9 = *(_BYTE *)(v2 + 80);
  if ( v9 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v9 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
}

// File Line: 329
// RVA: 0xF2980
void __fastcall UFG::NavModuleLocalRVO::Update(UFG::NavModuleLocalRVO *this, float dt)
{
  float v2; // xmm4_4
  UFG::NavModuleLocalRVO *v3; // rbx
  hkaiBehavior *v4; // rax
  float v5; // xmm6_4
  __m128 v6; // xmm7
  float v7; // xmm8_4
  __m128 v8; // xmm2
  float v9; // xmm1_4
  float v10; // xmm5_4
  float v11; // xmm9_4
  float v12; // xmm10_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm8_4
  float v16; // xmm0_4
  __m128 v17; // xmm2
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm8_4

  v2 = dt;
  v3 = this;
  if ( this->m_phkaiCharacter )
  {
    v4 = this->m_phkaiBehaviour;
    v5 = *(float *)&v4[3].vfptr;
    v6 = (__m128)*(unsigned int *)(&v4[3].m_referenceCount + 1);
    v7 = *((float *)&v4[3].vfptr + 1);
    v8 = v6;
    v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
    if ( v8.m128_f32[0] == 0.0 )
      v9 = 0.0;
    else
      v9 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v8));
    v10 = *(float *)&v4[1].m_world.m_pntr;
    v11 = *((float *)&v4[1].m_world.m_pntr + 1);
    v12 = *(float *)&v4[2].vfptr;
    v13 = v6.m128_f32[0] * v9;
    v14 = v5 * v9;
    v15 = v7 * v9;
    if ( this->m_fAdjustedSpeed <= 0.0 )
    {
      this->m_steerData.m_fLocalSpeed = 0.0;
      this->m_bStopped = 1;
    }
    else
    {
      this->m_steerData.m_vDesiredDirection.x = v13;
      this->m_steerData.m_vDesiredDirection.y = v14;
      this->m_steerData.m_vDesiredDirection.z = v15;
      this->m_steerData.m_vClampedDirection.x = v10;
      this->m_steerData.m_vClampedDirection.y = v11;
      this->m_steerData.m_vClampedDirection.z = v12;
      this->m_steerData.m_vLocalDirection.x = v10;
      this->m_steerData.m_vLocalDirection.y = v11;
      this->m_steerData.m_vLocalDirection.z = v12;
      v16 = *(float *)&v4[2].m_memSizeAndFlags;
      v17 = (__m128)HIDWORD(v4[2].vfptr);
      v18 = *(float *)(&v4[2].m_referenceCount + 1);
      this->m_bStopped = 0;
      v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16)) + (float)(v18 * v18);
      LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v17);
      this->m_steerData.m_fLocalSpeed = v19;
      if ( v19 <= this->m_AvoidanceProperties.m_movementProperties.m_minVelocity )
        v19 = this->m_AvoidanceProperties.m_movementProperties.m_minVelocity;
      if ( v19 >= this->m_AvoidanceProperties.m_movementProperties.m_maxVelocity )
        v19 = this->m_AvoidanceProperties.m_movementProperties.m_maxVelocity;
      this->m_steerData.m_fLocalSpeed = v19;
    }
    if ( this->m_bAvoidingBackwardsPause )
    {
      v20 = this->m_fAvoidingBackwardsTimer - v2;
      if ( v20 <= 0.0 )
        v20 = 0.0;
      this->m_fAvoidingBackwardsTimer = v20;
      if ( v20 <= 0.0 )
        this->m_bAvoidingBackwardsPause = 0;
      if ( (float)((float)((float)(v11 * v14) + (float)(v10 * v13)) + (float)(v12 * v15)) > cosf(0.78539819) )
        v3->m_bAvoidingBackwardsPause = 0;
      v3->m_steerData.m_vDesiredDirection.x = v13;
      v3->m_steerData.m_vDesiredDirection.y = v14;
      v3->m_steerData.m_vDesiredDirection.z = v15;
      v3->m_steerData.m_vClampedDirection.x = v13;
      v3->m_steerData.m_vClampedDirection.y = v14;
      v3->m_steerData.m_vClampedDirection.z = v15;
      v3->m_steerData.m_vLocalDirection.x = v13;
      v3->m_steerData.m_vLocalDirection.y = v14;
      v3->m_steerData.m_vLocalDirection.z = v15;
      v3->m_steerData.m_fLocalSpeed = 0.0;
      v3->m_bStopped = 1;
    }
    else if ( this->m_fAdjustedSpeed <= 0.0
           || (v21 = (float)((float)(v11 * v14) + (float)(v10 * v13)) + (float)(v12 * v15), v21 >= 0.0) )
    {
      this->m_fAvoidingBackwardsTimer = 0.0;
    }
    else
    {
      v22 = v2 + this->m_fAvoidingBackwardsTimer;
      this->m_fAvoidingBackwardsTimer = v22;
      if ( this->m_bAvoidanceStrafe )
      {
        v23 = (float)(COERCE_FLOAT(LODWORD(v14) ^ _xmm[0]) * v21) + v11;
        v24 = (float)(COERCE_FLOAT(LODWORD(v13) ^ _xmm[0]) * v21) + v10;
        v25 = (float)(COERCE_FLOAT(LODWORD(v15) ^ _xmm[0]) * v21) + v12;
        this->m_steerData.m_vClampedDirection.y = v23;
        this->m_steerData.m_vClampedDirection.x = v24;
        this->m_steerData.m_vClampedDirection.z = v25;
        this->m_steerData.m_fLocalSpeed = fsqrt((float)((float)(v23 * v23) + (float)(v24 * v24)) + (float)(v25 * v25));
      }
      if ( v22 > 3.0 )
      {
        this->m_fAvoidingBackwardsTimer = 4.0;
        this->m_bAvoidingBackwardsPause = 1;
      }
    }
  }
}

// File Line: 421
// RVA: 0xF3BB0
void __fastcall UFG::NavModuleLocalRVO::UpdateSteering(UFG::NavModuleLocalRVO *this, float dt)
{
  UFG::NavModuleLocalRVO *v2; // rbx
  float v3; // xmm6_4
  hkaiBehavior *v4; // rdi
  UFG::qVector4 *v5; // rax
  __m128 v6; // xmm2
  float v7; // xmm3_4
  __m128 v8; // xmm1
  float v9; // xmm0_4

  v2 = this;
  if ( this->m_phkaiCharacter )
  {
    UFG::NavModuleLocalRVO::UpdateAvoidanceProperties(this);
    UFG::NavModuleLocal::UpdateAdjustedWaypointAndSpeed((UFG::NavModuleLocal *)&v2->vfptr, dt);
    if ( v2->m_bStopped )
    {
      v3 = 0.0;
      if ( v2->m_fAdjustedSpeed > 0.0 )
      {
        v4 = v2->m_phkaiBehaviour;
        v5 = UFG::NavComponent::GetCurrentPosition(v2->m_navComponent);
        v6 = (__m128)LODWORD(v2->m_adjustedWaypoint.m_navPosition.m_vPosition.x);
        v6.m128_f32[0] = v6.m128_f32[0] - v5->x;
        v7 = v2->m_adjustedWaypoint.m_navPosition.m_vPosition.y - v5->y;
        v8 = v6;
        v8.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v7 * v7);
        v9 = v8.m128_f32[0];
        if ( v8.m128_f32[0] < 0.0 )
          LODWORD(v9) = v8.m128_i32[0] ^ _xmm[0];
        if ( v9 < 0.001 )
        {
          UFG::HavokBehaviourSteerToPath::ResetFacing((UFG::HavokBehaviourSteerToPath *)v4);
        }
        else
        {
          if ( v8.m128_f32[0] != 0.0 )
            v3 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v8));
          LODWORD(v4[2].vfptr) = 0;
          *((float *)&v4[1].m_world.m_pntr + 1) = v3 * v7;
          *(float *)&v4[1].m_world.m_pntr = v6.m128_f32[0] * v3;
        }
      }
    }
  }
}

// File Line: 452
// RVA: 0xED660
float __fastcall UFG::NavModuleLocalRVO::GetTurningRadius(UFG::NavModuleLocalRVO *this, float fSpeed)
{
  float v2; // xmm0_4

  v2 = this->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity;
  if ( v2 <= 0.0099999998 )
    v2 = FLOAT_0_0099999998;
  return fSpeed / v2;
}

// File Line: 461
// RVA: 0xECF90
float __fastcall UFG::NavModuleLocalRVO::GetMaxSpeedForRadius(UFG::NavModuleLocalRVO *this, float fRadius)
{
  float v2; // xmm0_4

  v2 = this->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity;
  if ( v2 <= 0.0099999998 )
    v2 = FLOAT_0_0099999998;
  return v2 * fRadius;
}

