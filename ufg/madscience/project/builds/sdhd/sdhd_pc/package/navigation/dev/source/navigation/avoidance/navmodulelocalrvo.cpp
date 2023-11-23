// File Line: 42
// RVA: 0x1460B50
__int64 dynamic_initializer_for__UFG::NavModuleLocalRVO::ms_aCharacters__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::NavModuleLocalRVO::ms_aCharacters__);
}

// File Line: 43
// RVA: 0x1460B40
__int64 dynamic_initializer_for__UFG::NavModuleLocalRVO::ms_aBehaviors__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::NavModuleLocalRVO::ms_aBehaviors__);
}

// File Line: 50
// RVA: 0xE4EB0
void __fastcall UFG::NavModuleLocalRVO::NavModuleLocalRVO(UFG::NavModuleLocalRVO *this, UFG::NavComponent *parent)
{
  UFG::NavModuleLocal::NavModuleLocal(this, parent);
  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocalRVO::`vftable;
  this->m_phkaiCharacter = 0i64;
  this->m_phkaiBehaviour = 0i64;
  hkaiAvoidanceProperties::hkaiAvoidanceProperties(&this->m_AvoidanceProperties);
  this->m_bStopped = 1;
  UFG::NavModuleLocalRVO::InitCharacter(this);
  UFG::NavModuleLocalRVO::InitBehaviour(this);
}

// File Line: 77
// RVA: 0xF0E90
void __fastcall UFG::NavModuleLocalRVO::Shutdown(UFG::NavModuleLocalRVO *this)
{
  hkaiBehavior *m_phkaiBehaviour; // rdx
  int v3; // r8d
  __int64 v4; // rax
  int v5; // ecx
  hkaiBehavior *v6; // rcx
  hkaiCharacter *m_phkaiCharacter; // r8
  hkaiCharacter **m_data; // r9
  int v9; // ecx
  __int64 v10; // rax
  int v11; // edx
  hkaiCharacter *v12; // rcx

  m_phkaiBehaviour = this->m_phkaiBehaviour;
  if ( m_phkaiBehaviour )
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
      while ( UFG::NavModuleLocalRVO::ms_aBehaviors.m_data[v4] != m_phkaiBehaviour )
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
    v6 = this->m_phkaiBehaviour;
    if ( v6 )
      v6->hkReferencedObject::hkBaseObject::vfptr->__vecDelDtor(v6, 1u);
    this->m_phkaiBehaviour = 0i64;
  }
  m_phkaiCharacter = this->m_phkaiCharacter;
  if ( m_phkaiCharacter )
  {
    m_data = UFG::NavModuleLocalRVO::ms_aCharacters.m_data;
    v9 = 0;
    v10 = 0i64;
    if ( UFG::NavModuleLocalRVO::ms_aCharacters.m_size <= 0 )
    {
LABEL_15:
      v9 = -1;
    }
    else
    {
      while ( UFG::NavModuleLocalRVO::ms_aCharacters.m_data[v10] != m_phkaiCharacter )
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
      m_phkaiCharacter = (hkaiCharacter *)&UFG::NavModuleLocalRVO::ms_aCharacters.m_data[v11];
      UFG::NavModuleLocalRVO::ms_aCharacters.m_data[v9] = (hkaiCharacter *)m_phkaiCharacter->vfptr;
    }
    v12 = this->m_phkaiCharacter;
    if ( v12 )
      ((void (__fastcall *)(hkaiCharacter *, __int64, hkaiCharacter *, hkaiCharacter **))v12->vfptr->__vecDelDtor)(
        v12,
        1i64,
        m_phkaiCharacter,
        m_data);
    this->m_phkaiCharacter = 0i64;
  }
}

// File Line: 100
// RVA: 0xEF1D0
void __fastcall UFG::NavModuleLocalRVO::InitCharacter(UFG::NavModuleLocalRVO *this)
{
  UFG::qVector4 *CurrentPosition; // rax
  UFG::SimObject *m_pSimObject; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __m128 y_low; // xmm4
  __m128 x_low; // xmm5
  __m128 z_low; // xmm3
  __m128 v8; // xmm2
  float v9; // xmm1_4
  UFG::SimObjectCharacter *v10; // rbx
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __int64 v13; // rbx
  char v14; // dl
  char v15; // cl
  _QWORD **Value; // rax
  hkaiCharacter *v17; // rax
  hkaiCharacter *v18; // rax
  int m_size; // ecx
  char v20; // al
  hkaiCharacter::Cinfo cinfo; // [rsp+30h] [rbp-78h] BYREF

  hkaiCharacter::Cinfo::Cinfo(&cinfo);
  CurrentPosition = UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  cinfo.m_initialPosition.m_quad = _mm_unpacklo_ps(
                                     _mm_unpacklo_ps(
                                       (__m128)LODWORD(CurrentPosition->x),
                                       (__m128)LODWORD(CurrentPosition->z)),
                                     _mm_unpacklo_ps(
                                       (__m128)LODWORD(CurrentPosition->y),
                                       (__m128)(unsigned int)FLOAT_1_0));
  m_pSimObject = this->m_navComponent->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.y);
  x_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.x);
  z_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.z);
  v8 = x_low;
  v8.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                         + (float)(y_low.m128_f32[0] * y_low.m128_f32[0]))
                 + (float)(z_low.m128_f32[0] * z_low.m128_f32[0]);
  if ( v8.m128_f32[0] == 0.0 )
    v9 = 0.0;
  else
    v9 = 1.0 / _mm_sqrt_ps(v8).m128_f32[0];
  z_low.m128_f32[0] = z_low.m128_f32[0] * v9;
  y_low.m128_f32[0] = y_low.m128_f32[0] * v9;
  x_low.m128_f32[0] = x_low.m128_f32[0] * v9;
  cinfo.m_initialForward.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), _mm_unpacklo_ps(y_low, (__m128)0i64));
  cinfo.m_desiredSpeed = 0.0;
  v10 = (UFG::SimObjectCharacter *)this->m_navComponent->m_pSimObject;
  if ( v10 == UFG::GetLocalPlayer() )
    v11 = (__m128)LODWORD(kfPlayerSensorHalfSize);
  else
    v11 = (__m128)LODWORD(kfOtherSensorHalfSize);
  v12 = _mm_xor_ps(v11, *(__m128 *)_xmm);
  this->m_AvoidanceProperties.m_localSensorAabb.m_min.m_quad = _mm_unpacklo_ps(
                                                                 _mm_unpacklo_ps(v12, (__m128)LODWORD(FLOAT_N0_75)),
                                                                 _mm_unpacklo_ps(v12, (__m128)(unsigned int)FLOAT_1_0));
  this->m_AvoidanceProperties.m_localSensorAabb.m_max.m_quad = _mm_unpacklo_ps(
                                                                 _mm_unpacklo_ps(v11, (__m128)LODWORD(FLOAT_0_75)),
                                                                 _mm_unpacklo_ps(v11, (__m128)(unsigned int)FLOAT_1_0));
  cinfo.m_initialPosition = 0i64;
  cinfo.m_initialForward = (hkVector4f)_xmm;
  cinfo.m_up.m_quad = _xmm;
  cinfo.m_desiredSpeed = 0.0;
  this->m_AvoidanceProperties.m_avoidanceSolverType.m_storage = UFG::NavAvoidanceStrategyRVO::msAvoidanceSolverType;
  cinfo.m_avoidanceProperties = &this->m_AvoidanceProperties;
  UFG::NavModuleLocalRVO::UpdateAvoidanceProperties(this);
  cinfo.m_radius = UFG::NavComponent::GetAvoidanceRadius(this->m_navComponent);
  cinfo.m_userData = 0i64;
  v13 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v14 = ++*(_BYTE *)(v13 + 80);
  *(_DWORD *)(v13 + 4i64 * v14) = 1;
  *(_QWORD *)(v13 + 8i64 * v14 + 16) = "AI::hkaiCharacter";
  *(_QWORD *)(v13 + 8i64 * v14 + 48) = 0i64;
  v15 = *(_BYTE *)(v13 + 81);
  if ( v14 > v15 )
    v15 = v14;
  *(_BYTE *)(v13 + 81) = v15;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkaiCharacter *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 192i64);
  if ( v17 )
    hkaiCharacter::hkaiCharacter(v17, &cinfo);
  else
    v18 = 0i64;
  this->m_phkaiCharacter = v18;
  m_size = UFG::NavModuleLocalRVO::ms_aCharacters.m_size;
  if ( UFG::NavModuleLocalRVO::ms_aCharacters.m_size == (UFG::NavModuleLocalRVO::ms_aCharacters.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &UFG::NavModuleLocalRVO::ms_aCharacters, 8);
    m_size = UFG::NavModuleLocalRVO::ms_aCharacters.m_size;
  }
  UFG::NavModuleLocalRVO::ms_aCharacters.m_data[m_size] = this->m_phkaiCharacter;
  ++UFG::NavModuleLocalRVO::ms_aCharacters.m_size;
  v20 = *(_BYTE *)(v13 + 80);
  if ( v20 > 0 )
  {
    *(_BYTE *)(v13 + 80) = v20 - 1;
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
  UFG::NavModuleLocal::Reset(this);
  if ( !this->m_phkaiCharacter )
  {
    UFG::NavModuleLocalRVO::InitCharacter(this);
    UFG::NavModuleLocalRVO::InitBehaviour(this);
  }
  UFG::HavokBehaviourSteerToPath::ResetFacing((UFG::HavokBehaviourSteerToPath *)this->m_phkaiBehaviour);
  this->m_bStopped = 1;
  this->m_bAvoidingBackwardsPause = 0;
  this->m_fAvoidingBackwardsTimer = 0.0;
}

// File Line: 178
// RVA: 0xF3340
void __fastcall UFG::NavModuleLocalRVO::UpdateAvoidanceProperties(UFG::NavModuleLocalRVO *this)
{
  unsigned int v2; // eax
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  bool v4; // di
  UFG::AICharacterControllerBaseComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  unsigned __int8 v11; // al
  float m_fAdjustedSpeed; // xmm2_4
  float v13; // xmm1_4
  UFG::qVector4 *CurrentPosition; // rax
  __m128 y_low; // xmm2
  float v16; // xmm1_4
  UFG::NavComponent *m_navComponent; // rdi
  hkaiBehavior *m_phkaiBehaviour; // rdi

  v2 = _S9_1;
  if ( (_S9_1 & 1) == 0 )
  {
    v2 = _S9_1 | 1;
    _S9_1 |= 1u;
    kfMaxTurnVelocity = kfMaxVelocity * 0.80000001;
  }
  if ( (v2 & 2) == 0 )
  {
    _S9_1 = v2 | 2;
    kfPenaltyLimitBoundaryDistance = UFG::NavComponent::GetAvoidanceRadius(this->m_navComponent) * 5.0;
  }
  m_pSimObject = (UFG::SimObjectCVBase *)this->m_navComponent->m_pSimObject;
  v4 = 0;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pSimObject);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pSimObject,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       m_pSimObject,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    v5 = ComponentOfTypeHK;
  }
  else
  {
    v5 = 0i64;
  }
  v8 = v5->m_Intention.mActionRequests.mBits[(__int64)(int)gActionRequest_StrafeFacing.m_EnumValue >> 6];
  if ( _bittest64((const __int64 *)&v8, gActionRequest_StrafeFacing.m_EnumValue & 0x3F)
    || (v9 = v5->m_Intention.mActionRequests.mBits[(__int64)(int)gActionRequest_Focus.m_EnumValue >> 6],
        _bittest64((const __int64 *)&v9, gActionRequest_Focus.m_EnumValue & 0x3F)) )
  {
    v4 = 1;
  }
  this->m_bStrafing = v4;
  v10 = v5->m_Intention.mActionRequests.mBits[(__int64)(int)gActionRequest_AIAvoidanceStrafe.m_EnumValue >> 6];
  v11 = _bittest64((const __int64 *)&v10, gActionRequest_AIAvoidanceStrafe.m_EnumValue & 0x3F);
  this->m_bAvoidanceStrafe = v11;
  if ( this->m_bStopped || (m_fAdjustedSpeed = this->m_fAdjustedSpeed, m_fAdjustedSpeed <= 0.0) )
  {
    this->m_AvoidanceProperties.m_movementProperties.m_maxAcceleration = kfMaxAcceleration * 1000.0;
    this->m_AvoidanceProperties.m_movementProperties.m_maxDeceleration = kfMaxDeceleration * 1000.0;
    this->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity = 188.49556;
    this->m_AvoidanceProperties.m_movementProperties.m_minVelocity = kfMinVelocity;
    v13 = kfMaxVelocity;
    this->m_AvoidanceProperties.m_movementProperties.m_maxTurnVelocity = kfMaxTurnVelocity;
  }
  else
  {
    this->m_AvoidanceProperties.m_movementProperties.m_maxAcceleration = kfMaxAcceleration;
    this->m_AvoidanceProperties.m_movementProperties.m_maxDeceleration = kfMaxDeceleration;
    if ( v4 )
    {
      this->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity = kfMaxAngularVelocityStrafing;
    }
    else if ( v11 )
    {
      this->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity = kfMaxAngularVelocity;
    }
    else
    {
      this->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity = this->m_navComponent->m_fMaxAngularVelocity;
    }
    this->m_AvoidanceProperties.m_movementProperties.m_minVelocity = m_fAdjustedSpeed * kfMinVelocityRatio;
    v13 = m_fAdjustedSpeed * kfMaxVelocityRatio;
    this->m_AvoidanceProperties.m_movementProperties.m_maxTurnVelocity = m_fAdjustedSpeed * 0.80000001;
  }
  this->m_AvoidanceProperties.m_movementProperties.m_maxVelocity = v13;
  this->m_AvoidanceProperties.m_agentLimitTime = kfPenaltyAgentLimitTime;
  this->m_AvoidanceProperties.m_obstacleLimitTime = kfPenaltyObstacleLimitTime;
  this->m_AvoidanceProperties.m_boundaryLimitTime = kfPenaltyBoundaryLimitTime;
  this->m_AvoidanceProperties.m_limitObstacleDistance = kfPenaltyLimitObstacleDistance;
  this->m_AvoidanceProperties.m_limitObstacleVelocity = kfPenaltyLimitObstacleVelocity;
  CurrentPosition = UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  y_low = (__m128)LODWORD(CurrentPosition->y);
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->m_adjustedWaypoint.m_navPosition.m_vPosition.y)
                                    * (float)(y_low.m128_f32[0] - this->m_adjustedWaypoint.m_navPosition.m_vPosition.y))
                            + (float)((float)(CurrentPosition->x - this->m_adjustedWaypoint.m_navPosition.m_vPosition.x)
                                    * (float)(CurrentPosition->x - this->m_adjustedWaypoint.m_navPosition.m_vPosition.x)))
                    + (float)((float)(CurrentPosition->z - this->m_adjustedWaypoint.m_navPosition.m_vPosition.z)
                            * (float)(CurrentPosition->z - this->m_adjustedWaypoint.m_navPosition.m_vPosition.z));
  v16 = _mm_sqrt_ps(y_low).m128_f32[0];
  if ( v16 >= kfPenaltyLimitBoundaryDistance )
    v16 = kfPenaltyLimitBoundaryDistance;
  this->m_AvoidanceProperties.m_limitBoundaryDistance = v16;
  this->m_AvoidanceProperties.m_avoidanceSolverType.m_storage = UFG::NavAvoidanceStrategyRVO::msAvoidanceSolverType;
  if ( !(_BYTE)UFG::NavAvoidanceStrategyRVO::msAvoidanceSolverType )
  {
    this->m_AvoidanceProperties.m_collisionPenalty = kfSamplingCollisionPenalty;
    this->m_AvoidanceProperties.m_penetrationPenalty = kfSamplingPenetrationPenalty;
    this->m_AvoidanceProperties.m_wallFollowingAngle = kfSamplingWallFollowingAngle;
    this->m_AvoidanceProperties.m_velocityHysteresis = kfSamplingVelocityHystersis;
    this->m_AvoidanceProperties.m_sidednessChangingPenalty = kfSamplingSidednessChangingPenalty;
  }
  if ( this->m_phkaiCharacter )
  {
    m_navComponent = this->m_navComponent;
    if ( m_navComponent->m_navPosition.vfptr->IsMeshPositionValid(&m_navComponent->m_navPosition) )
      this->m_phkaiCharacter->m_currentNavMeshFace = m_navComponent->m_navPosition.m_packedKey;
    else
      this->m_phkaiCharacter->m_currentNavMeshFace = -1;
  }
  m_phkaiBehaviour = this->m_phkaiBehaviour;
  if ( m_phkaiBehaviour )
  {
    BYTE4(m_phkaiBehaviour[3].m_world.m_pntr) = UFG::NavModuleLocal::IsAvoidanceEnabled(this);
    if ( this->m_phkaiCharacter )
      this->m_phkaiCharacter->m_radius = UFG::NavComponent::GetAvoidanceRadius(this->m_navComponent);
  }
}

// File Line: 321
// RVA: 0xEF090
void __fastcall UFG::NavModuleLocalRVO::InitBehaviour(UFG::NavModuleLocalRVO *this)
{
  __int64 v2; // rbx
  char v3; // dl
  char v4; // cl
  _QWORD **Value; // rax
  UFG::HavokBehaviourSteerToPath *v6; // rax
  int m_size; // ecx
  char v8; // al

  v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v3 = ++*(_BYTE *)(v2 + 80);
  *(_DWORD *)(v2 + 4i64 * v3) = 1;
  *(_QWORD *)(v2 + 8i64 * v3 + 16) = "AI::addBehavior";
  *(_QWORD *)(v2 + 8i64 * v3 + 48) = 0i64;
  v4 = *(_BYTE *)(v2 + 81);
  if ( v3 > v4 )
    v4 = v3;
  *(_BYTE *)(v2 + 81) = v4;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (UFG::HavokBehaviourSteerToPath *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                           Value[11],
                                           128i64);
  if ( v6 )
    UFG::HavokBehaviourSteerToPath::HavokBehaviourSteerToPath(
      v6,
      this->m_navComponent,
      this->m_phkaiCharacter,
      (hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  this->m_phkaiBehaviour = v6;
  m_size = UFG::NavModuleLocalRVO::ms_aBehaviors.m_size;
  if ( UFG::NavModuleLocalRVO::ms_aBehaviors.m_size == (UFG::NavModuleLocalRVO::ms_aBehaviors.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &UFG::NavModuleLocalRVO::ms_aBehaviors, 8);
    m_size = UFG::NavModuleLocalRVO::ms_aBehaviors.m_size;
  }
  UFG::NavModuleLocalRVO::ms_aBehaviors.m_data[m_size] = this->m_phkaiBehaviour;
  ++UFG::NavModuleLocalRVO::ms_aBehaviors.m_size;
  v8 = *(_BYTE *)(v2 + 80);
  if ( v8 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v8 - 1;
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
  hkaiBehavior *m_phkaiBehaviour; // rax
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
  __m128 vfptr_high; // xmm2
  float v18; // xmm1_4
  float m_minVelocity; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm8_4

  if ( this->m_phkaiCharacter )
  {
    m_phkaiBehaviour = this->m_phkaiBehaviour;
    v5 = *(float *)&m_phkaiBehaviour[3].hkaiPathRequestInfoOwner::vfptr;
    v6 = (__m128)*(unsigned int *)(&m_phkaiBehaviour[3].m_referenceCount + 1);
    v7 = *((float *)&m_phkaiBehaviour[3].hkaiPathRequestInfoOwner::vfptr + 1);
    v8 = v6;
    v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
    if ( v8.m128_f32[0] == 0.0 )
      v9 = 0.0;
    else
      v9 = 1.0 / _mm_sqrt_ps(v8).m128_f32[0];
    v10 = *(float *)&m_phkaiBehaviour[1].m_world.m_pntr;
    v11 = *((float *)&m_phkaiBehaviour[1].m_world.m_pntr + 1);
    v12 = *(float *)&m_phkaiBehaviour[2].hkReferencedObject::hkBaseObject::vfptr;
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
      v16 = *(float *)&m_phkaiBehaviour[2].m_memSizeAndFlags;
      vfptr_high = (__m128)HIDWORD(m_phkaiBehaviour[2].hkReferencedObject::hkBaseObject::vfptr);
      v18 = *(float *)(&m_phkaiBehaviour[2].m_referenceCount + 1);
      this->m_bStopped = 0;
      vfptr_high.m128_f32[0] = (float)((float)(vfptr_high.m128_f32[0] * vfptr_high.m128_f32[0]) + (float)(v16 * v16))
                             + (float)(v18 * v18);
      m_minVelocity = _mm_sqrt_ps(vfptr_high).m128_f32[0];
      this->m_steerData.m_fLocalSpeed = m_minVelocity;
      if ( m_minVelocity <= this->m_AvoidanceProperties.m_movementProperties.m_minVelocity )
        m_minVelocity = this->m_AvoidanceProperties.m_movementProperties.m_minVelocity;
      if ( m_minVelocity >= this->m_AvoidanceProperties.m_movementProperties.m_maxVelocity )
        m_minVelocity = this->m_AvoidanceProperties.m_movementProperties.m_maxVelocity;
      this->m_steerData.m_fLocalSpeed = m_minVelocity;
    }
    if ( this->m_bAvoidingBackwardsPause )
    {
      v20 = this->m_fAvoidingBackwardsTimer - dt;
      if ( v20 <= 0.0 )
        v20 = 0.0;
      this->m_fAvoidingBackwardsTimer = v20;
      if ( v20 <= 0.0 )
        this->m_bAvoidingBackwardsPause = 0;
      if ( (float)((float)((float)(v11 * v14) + (float)(v10 * v13)) + (float)(v12 * v15)) > cosf(0.78539819) )
        this->m_bAvoidingBackwardsPause = 0;
      this->m_steerData.m_vDesiredDirection.x = v13;
      this->m_steerData.m_vDesiredDirection.y = v14;
      this->m_steerData.m_vDesiredDirection.z = v15;
      this->m_steerData.m_vClampedDirection.x = v13;
      this->m_steerData.m_vClampedDirection.y = v14;
      this->m_steerData.m_vClampedDirection.z = v15;
      this->m_steerData.m_vLocalDirection.x = v13;
      this->m_steerData.m_vLocalDirection.y = v14;
      this->m_steerData.m_vLocalDirection.z = v15;
      this->m_steerData.m_fLocalSpeed = 0.0;
      this->m_bStopped = 1;
    }
    else if ( this->m_fAdjustedSpeed <= 0.0
           || (v21 = (float)((float)(v11 * v14) + (float)(v10 * v13)) + (float)(v12 * v15), v21 >= 0.0) )
    {
      this->m_fAvoidingBackwardsTimer = 0.0;
    }
    else
    {
      v22 = dt + this->m_fAvoidingBackwardsTimer;
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
  float v3; // xmm6_4
  hkaiBehavior *m_phkaiBehaviour; // rdi
  UFG::qVector4 *CurrentPosition; // rax
  __m128 x_low; // xmm2
  float v7; // xmm3_4
  __m128 v8; // xmm1
  float v9; // xmm0_4

  if ( this->m_phkaiCharacter )
  {
    UFG::NavModuleLocalRVO::UpdateAvoidanceProperties(this);
    UFG::NavModuleLocal::UpdateAdjustedWaypointAndSpeed(this, dt);
    if ( this->m_bStopped )
    {
      v3 = 0.0;
      if ( this->m_fAdjustedSpeed > 0.0 )
      {
        m_phkaiBehaviour = this->m_phkaiBehaviour;
        CurrentPosition = UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
        x_low = (__m128)LODWORD(this->m_adjustedWaypoint.m_navPosition.m_vPosition.x);
        x_low.m128_f32[0] = x_low.m128_f32[0] - CurrentPosition->x;
        v7 = this->m_adjustedWaypoint.m_navPosition.m_vPosition.y - CurrentPosition->y;
        v8 = x_low;
        v8.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v7 * v7);
        v9 = v8.m128_f32[0];
        if ( v8.m128_f32[0] < 0.0 )
          LODWORD(v9) = v8.m128_i32[0] ^ _xmm[0];
        if ( v9 < 0.001 )
        {
          UFG::HavokBehaviourSteerToPath::ResetFacing((UFG::HavokBehaviourSteerToPath *)m_phkaiBehaviour);
        }
        else
        {
          if ( v8.m128_f32[0] != 0.0 )
            v3 = 1.0 / _mm_sqrt_ps(v8).m128_f32[0];
          LODWORD(m_phkaiBehaviour[2].hkReferencedObject::hkBaseObject::vfptr) = 0;
          *((float *)&m_phkaiBehaviour[1].m_world.m_pntr + 1) = v3 * v7;
          *(float *)&m_phkaiBehaviour[1].m_world.m_pntr = x_low.m128_f32[0] * v3;
        }
      }
    }
  }
}

// File Line: 452
// RVA: 0xED660
float __fastcall UFG::NavModuleLocalRVO::GetTurningRadius(UFG::NavModuleLocalRVO *this, float fSpeed)
{
  float m_maxAngularVelocity; // xmm0_4

  m_maxAngularVelocity = this->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity;
  if ( m_maxAngularVelocity <= 0.0099999998 )
    m_maxAngularVelocity = FLOAT_0_0099999998;
  return fSpeed / m_maxAngularVelocity;
}

// File Line: 461
// RVA: 0xECF90
float __fastcall UFG::NavModuleLocalRVO::GetMaxSpeedForRadius(UFG::NavModuleLocalRVO *this, float fRadius)
{
  float m_maxAngularVelocity; // xmm0_4

  m_maxAngularVelocity = this->m_AvoidanceProperties.m_movementProperties.m_maxAngularVelocity;
  if ( m_maxAngularVelocity <= 0.0099999998 )
    m_maxAngularVelocity = FLOAT_0_0099999998;
  return m_maxAngularVelocity * fRadius;
}

