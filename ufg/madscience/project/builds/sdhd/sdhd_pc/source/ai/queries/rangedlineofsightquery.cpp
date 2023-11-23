// File Line: 48
// RVA: 0x32BBB0
void __fastcall UFG::AIRangedLineOfSightQuery::AIRangedLineOfSightQuery(UFG::AIRangedLineOfSightQuery *this)
{
  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AIQuery::`vftable;
  this->m_bStateNeedsInit = 1;
  *(_QWORD *)&this->m_iRefCount = 0i64;
  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AIRangedLineOfSightQuery::`vftable;
  this->m_queryParams.pOwnerSimObject.mPrev = &this->m_queryParams.pOwnerSimObject;
  this->m_queryParams.pOwnerSimObject.mNext = &this->m_queryParams.pOwnerSimObject;
  this->m_queryParams.pOwnerSimObject.m_pPointer = 0i64;
  this->m_queryParams.pTargetSimObject.mPrev = &this->m_queryParams.pTargetSimObject;
  this->m_queryParams.pTargetSimObject.mNext = &this->m_queryParams.pTargetSimObject;
  this->m_queryParams.pTargetSimObject.m_pPointer = 0i64;
  UFG::qFixedArray<UFG::AIRangedLineOfSightQuery::RangedPosition,32>::qFixedArray<UFG::AIRangedLineOfSightQuery::RangedPosition,32>(&this->m_aRangedPositions);
}

// File Line: 66
// RVA: 0x326570
void __fastcall UFG::AIRangedLineOfSightQuery::InitializeQuery(UFG::AIRangedLineOfSightQuery *this)
{
  __int64 m_uState; // rax

  UFG::GetDesiredRanges(
    this->m_queryParams.pOwnerSimObject.m_pPointer,
    &this->m_fMinDesiredRange,
    &this->m_fMaxDesiredRange,
    &this->m_fDesiredRange);
  UFG::ComputeObjectRaycastPosition(this->m_queryParams.pTargetSimObject.m_pPointer, &this->m_vTargetPosition);
  m_uState = this->m_uState;
  this->m_aRangedPositions.size = 32;
  this->m_iBestPositionIndex = -1;
  LODWORD(m_uState) = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[m_uState].m_NextLogicalState;
  this->m_bStateNeedsInit = 1;
  this->m_uState = m_uState;
}

// File Line: 84
// RVA: 0x3265D0
void __fastcall UFG::AIRangedLineOfSightQuery::SeedPoints(UFG::AIRangedLineOfSightQuery *this)
{
  UFG::SimObject *m_pPointer; // rdi
  int v2; // esi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float x; // xmm8_4
  float y; // xmm9_4
  float z; // xmm10_4
  float *p_z; // rdi
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  unsigned int m_NextLogicalState; // eax

  m_pPointer = this->m_queryParams.pTargetSimObject.m_pPointer;
  v2 = 0;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  p_z = &this->m_aRangedPositions.p[0].vSeedPoint.z;
  do
  {
    v9 = (float)v2 * 0.19634955;
    v10 = cosf(v9);
    v11 = sinf(v9);
    ++v2;
    p_z += 36;
    v12 = UFG::qRandom(
            this->m_queryParams.fMaxDistance - this->m_queryParams.fMinDistance,
            (unsigned int *)&UFG::qDefaultSeed)
        + this->m_queryParams.fMinDistance;
    *(p_z - 36) = (float)(v12 * 0.0) + z;
    *(p_z - 38) = (float)(v10 * v12) + x;
    *(p_z - 37) = (float)(v11 * v12) + y;
    *((_BYTE *)p_z - 40) = 0;
  }
  while ( (unsigned int)v2 < 0x20 );
  m_NextLogicalState = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[this->m_uState].m_NextLogicalState;
  this->m_bStateNeedsInit = 1;
  this->m_uState = m_NextLogicalState;
}

// File Line: 110
// RVA: 0x326730
void __fastcall UFG::AIRangedLineOfSightQuery::InitCullInvalid(UFG::AIRangedLineOfSightQuery *this)
{
  this->m_uCurrentCulling = 0;
}

// File Line: 115
// RVA: 0x326740
void __fastcall UFG::AIRangedLineOfSightQuery::CullInvalid(UFG::AIRangedLineOfSightQuery *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  UFG::CombatRegion *v5; // rbp
  unsigned __int64 Ticks; // rax
  __int64 m_uCurrentCulling; // rax
  float v8; // xmm3_4
  float v9; // xmm6_4
  UFG::AIRangedLineOfSightQuery::RangedPosition *v10; // rbx
  char v11; // si
  float cast_distance_up; // xmm2_4
  float z; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float x; // xmm0_4
  float v17; // xmm1_4
  float y; // xmm0_4
  UFG::HavokNavPosition *p_navPos; // rsi
  int v20; // xmm6_4
  int v21; // xmm9_4
  int v22; // xmm10_4
  unsigned int m_NextLogicalState; // eax
  UFG::qVector3 out; // [rsp+30h] [rbp-C8h] BYREF
  hkVector4f hkvNewPosition; // [rsp+40h] [rbp-B8h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->m_queryParams.pOwnerSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIEntityComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIEntityComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v5 = *(UFG::CombatRegion **)&m_pComponent[15].m_TypeUID;
  while ( this->m_bCanContinue )
  {
    Ticks = UFG::qGetTicks();
    if ( UFG::qGetTickTime(this->m_uStartTicks, Ticks) >= this->m_fDuration )
      break;
    m_uCurrentCulling = this->m_uCurrentCulling;
    if ( (unsigned int)m_uCurrentCulling >= 0x20 )
      break;
    v8 = FLOAT_6_0;
    v9 = FLOAT_3_4028235e38;
    v10 = &this->m_aRangedPositions.p[m_uCurrentCulling];
    v11 = 0;
    cast_distance_up = FLOAT_6_0;
    while ( UFG::PlaceOnGround(&out, &v10->vSeedPoint, 0.0, v8, cast_distance_up) )
    {
      z = out.z;
      v11 = 1;
      v14 = out.z - v10->vSeedPoint.z;
      LODWORD(v15) = LODWORD(v14) & _xmm;
      if ( COERCE_FLOAT(LODWORD(v14) & _xmm) >= v9 )
        goto LABEL_22;
      cast_distance_up = v14 - 1.0;
      v9 = v15;
      x = out.x;
      v10->vGroundPosition.y = out.y;
      v10->vGroundPosition.x = x;
      v10->vGroundPosition.z = z;
      if ( cast_distance_up < 0.0 || cast_distance_up <= -6.0 )
        goto LABEL_22;
      v8 = FLOAT_6_0;
    }
    if ( !v11 )
      goto LABEL_29;
LABEL_22:
    if ( !v5 || UFG::CombatRegion::IsHitPoint(v5, &v10->vGroundPosition) )
    {
      v17 = v10->vGroundPosition.z;
      y = v10->vGroundPosition.y;
      p_navPos = &v10->navPos;
      v10->navPos.m_vPosition.x = v10->vGroundPosition.x;
      v10->navPos.m_vPosition.z = v17;
      v10->navPos.m_vPosition.y = y;
      v10->navPos.m_bValid = 0;
      ((void (__fastcall *)(UFG::HavokNavPosition *))v10->navPos.vfptr->Validate)(&v10->navPos);
      if ( v10->navPos.vfptr->IsMeshPositionValid(&v10->navPos) )
      {
        if ( UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(
               &v10->navPos.m_hkvMeshPosition,
               &hkvNewPosition,
               COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_25))) )
        {
          v20 = hkvNewPosition.m_quad.m128_i32[0];
          v21 = hkvNewPosition.m_quad.m128_i32[1];
          v22 = hkvNewPosition.m_quad.m128_i32[2];
          LODWORD(v10->navPos.m_vPosition.x) = hkvNewPosition.m_quad.m128_i32[0];
          LODWORD(v10->navPos.m_vPosition.y) = v21;
          LODWORD(v10->navPos.m_vPosition.z) = v22;
          v10->navPos.m_bValid = 0;
          ((void (__fastcall *)(UFG::HavokNavPosition *))p_navPos->vfptr->Validate)(&v10->navPos);
          if ( !p_navPos->vfptr->IsMeshPositionValid(&v10->navPos) )
            goto LABEL_29;
          LODWORD(v10->vGroundPosition.x) = v20;
          LODWORD(v10->vGroundPosition.y) = v21;
          LODWORD(v10->vGroundPosition.z) = v22;
        }
        v10->bValid = 1;
      }
    }
LABEL_29:
    ++this->m_uCurrentCulling;
  }
  if ( this->m_uCurrentCulling == 32 )
  {
    m_NextLogicalState = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[this->m_uState].m_NextLogicalState;
    this->m_bStateNeedsInit = 1;
    this->m_uState = m_NextLogicalState;
  }
}

// File Line: 219
// RVA: 0x326AA0
void __fastcall UFG::AIRangedLineOfSightQuery::InitTestLineOfSight(UFG::AIRangedLineOfSightQuery *this)
{
  this->m_uCurrentLOSTest = 0;
}

// File Line: 224
// RVA: 0x326AB0
void __fastcall UFG::AIRangedLineOfSightQuery::TestLineOfSight(UFG::AIRangedLineOfSightQuery *this)
{
  float v2; // xmm7_4
  float v3; // xmm9_4
  float v4; // xmm8_4
  unsigned __int64 Ticks; // rax
  __int64 m_uCurrentLOSTest; // rax
  __int64 v7; // rsi
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  UFG::qVector3 *p_vFiringPosition; // rdx
  UFG::SimObjectGame *m_pPointer; // rdi
  unsigned __int64 m_userData; // rcx
  __int64 v14; // rax
  UFG::VehicleOccupantComponent *v15; // rbp
  __int16 m_Flags; // cx
  UFG::CharacterOccupantComponent *ComponentOfType; // rax
  unsigned int m_NextLogicalState; // eax
  UFG::RayCastData data; // [rsp+20h] [rbp-128h] BYREF

  v2 = UFG::qVector3::msDirUp.x * 1.2;
  v3 = UFG::qVector3::msDirUp.z * 1.2;
  v4 = UFG::qVector3::msDirUp.y * 1.2;
  while ( this->m_bCanContinue )
  {
    Ticks = UFG::qGetTicks();
    if ( UFG::qGetTickTime(this->m_uStartTicks, Ticks) >= this->m_fDuration )
      break;
    m_uCurrentLOSTest = this->m_uCurrentLOSTest;
    if ( (unsigned int)m_uCurrentLOSTest >= 0x20 )
      break;
    v7 = m_uCurrentLOSTest;
    if ( !this->m_aRangedPositions.p[m_uCurrentLOSTest].bValid )
      goto LABEL_26;
    v8 = v2 + this->m_aRangedPositions.p[v7].vGroundPosition.x;
    v9 = v4 + this->m_aRangedPositions.p[v7].vGroundPosition.y;
    v10 = v3 + this->m_aRangedPositions.p[v7].vGroundPosition.z;
    p_vFiringPosition = &this->m_aRangedPositions.p[v7].vFiringPosition;
    data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
    data.mInput.m_filterInfo = 0;
    data.mInput.m_userData = 0i64;
    data.mOutput.m_hitFraction = 1.0;
    p_vFiringPosition->x = v8;
    p_vFiringPosition->y = v9;
    p_vFiringPosition->z = v10;
    m_pPointer = (UFG::SimObjectGame *)this->m_queryParams.pTargetSimObject.m_pPointer;
    data.mOutput.m_extraInfo = -1;
    data.mOutput.m_shapeKeyIndex = 0;
    data.mOutput.m_shapeKeys[0] = -1;
    data.mOutput.m_rootCollidable = 0i64;
    data.mDebugName = 0i64;
    data.mCollisionModelName.mUID = -1;
    UFG::RayCastData::Init(&data, p_vFiringPosition, &this->m_vTargetPosition, 0xCu);
    UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
    if ( !data.hit
      || data.mHavokRigidBody
      && (m_userData = data.mHavokRigidBody->m_userData) != 0
      && (((v14 = *(_QWORD *)(m_userData + 24)) == 0
         ? (v15 = 0i64)
         : (v15 = *(UFG::VehicleOccupantComponent **)(v14 + 40)),
           v15 == (UFG::VehicleOccupantComponent *)m_pPointer)
       || m_pPointer
       && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
         ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
          ? (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                    m_pPointer,
                                                                    UFG::CharacterOccupantComponent::_TypeUID))
          : (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    m_pPointer,
                                                                    UFG::CharacterOccupantComponent::_TypeUID)))
         : (ComponentOfType = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent),
           ComponentOfType && UFG::CharacterOccupantComponent::GetCurrentVehicle(ComponentOfType) == v15)) )
    {
      LODWORD(this->m_aRangedPositions.p[v7].fLineOfSightPriority) = (_DWORD)FLOAT_1_0;
LABEL_26:
      ++this->m_uCurrentLOSTest;
    }
    else
    {
      this->m_aRangedPositions.p[v7].fLineOfSightPriority = 0.0;
      ++this->m_uCurrentLOSTest;
    }
  }
  if ( this->m_uCurrentLOSTest == 32 )
  {
    m_NextLogicalState = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[this->m_uState].m_NextLogicalState;
    this->m_bStateNeedsInit = 1;
    this->m_uState = m_NextLogicalState;
  }
}

// File Line: 257
// RVA: 0x326D90
void __fastcall UFG::AIRangedLineOfSightQuery::InitPrioritize(UFG::AIRangedLineOfSightQuery *this)
{
  this->m_uCurrentPrioritizing = 0;
}

// File Line: 262
// RVA: 0x326DA0
void __fastcall UFG::AIRangedLineOfSightQuery::Prioritize(UFG::AIRangedLineOfSightQuery *this)
{
  unsigned __int64 Ticks; // rax
  __int64 m_uCurrentPrioritizing; // rax
  __m128 x_low; // xmm2
  float m_fDesiredRange; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  unsigned int m_NextLogicalState; // eax

  while ( this->m_bCanContinue )
  {
    Ticks = UFG::qGetTicks();
    if ( UFG::qGetTickTime(this->m_uStartTicks, Ticks) >= this->m_fDuration )
      break;
    m_uCurrentPrioritizing = this->m_uCurrentPrioritizing;
    if ( (unsigned int)m_uCurrentPrioritizing >= 0x20 )
      break;
    if ( this->m_aRangedPositions.p[m_uCurrentPrioritizing].bValid )
    {
      x_low = (__m128)LODWORD(this->m_aRangedPositions.p[m_uCurrentPrioritizing].vFiringPosition.x);
      m_fDesiredRange = this->m_fDesiredRange;
      x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - this->m_vTargetPosition.x)
                                        * (float)(x_low.m128_f32[0] - this->m_vTargetPosition.x))
                                + (float)((float)(this->m_aRangedPositions.p[m_uCurrentPrioritizing].vFiringPosition.y
                                                - this->m_vTargetPosition.y)
                                        * (float)(this->m_aRangedPositions.p[m_uCurrentPrioritizing].vFiringPosition.y
                                                - this->m_vTargetPosition.y)))
                        + (float)((float)(this->m_aRangedPositions.p[m_uCurrentPrioritizing].vFiringPosition.z
                                        - this->m_vTargetPosition.z)
                                * (float)(this->m_aRangedPositions.p[m_uCurrentPrioritizing].vFiringPosition.z
                                        - this->m_vTargetPosition.z));
      v6 = _mm_sqrt_ps(x_low).m128_f32[0];
      if ( v6 >= m_fDesiredRange )
      {
        v8 = (float)(this->m_fMaxDesiredRange - v6) / (float)(this->m_fMaxDesiredRange - m_fDesiredRange);
        if ( v8 <= 0.0 )
          v8 = 0.0;
        this->m_aRangedPositions.p[m_uCurrentPrioritizing].fDistancePriority = v8;
      }
      else
      {
        v7 = (float)(v6 - this->m_fMinDesiredRange) / (float)(m_fDesiredRange - this->m_fMinDesiredRange);
        if ( v7 <= 0.0 )
          v7 = 0.0;
        this->m_aRangedPositions.p[m_uCurrentPrioritizing].fDistancePriority = v7;
      }
      this->m_aRangedPositions.p[m_uCurrentPrioritizing].fTotalPriority = (float)(this->m_aRangedPositions.p[m_uCurrentPrioritizing].fLineOfSightPriority
                                                                                * this->m_queryParams.fLineOfSightPriority)
                                                                        + (float)(this->m_queryParams.fDistancePriority
                                                                                * this->m_aRangedPositions.p[m_uCurrentPrioritizing].fDistancePriority);
    }
    ++this->m_uCurrentPrioritizing;
  }
  if ( this->m_uCurrentPrioritizing == 32 )
  {
    m_NextLogicalState = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[this->m_uState].m_NextLogicalState;
    this->m_bStateNeedsInit = 1;
    this->m_uState = m_NextLogicalState;
  }
}

// File Line: 294
// RVA: 0x326EF0
void __fastcall UFG::AIRangedLineOfSightQuery::TestDirectPath(UFG::AIRangedLineOfSightQuery *this)
{
  unsigned int m_NextLogicalState; // eax

  m_NextLogicalState = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[this->m_uState].m_NextLogicalState;
  this->m_bStateNeedsInit = 1;
  this->m_uState = m_NextLogicalState;
}

// File Line: 299
// RVA: 0x326F10
void __fastcall UFG::AIRangedLineOfSightQuery::PathTest(UFG::AIRangedLineOfSightQuery *this)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfType; // rsi
  float v4; // xmm1_4
  UFG::DaemonType v5; // xmm2_4
  unsigned int v6; // esi
  unsigned int v7; // r14d
  UFG::HavokNavPosition *p_navPos; // rbx
  bool v9; // al
  UFG::DaemonManager *v10; // rax
  __int64 v11; // rdx
  __int64 v12; // r9
  __int64 v13; // r8
  float v14; // xmm0_4
  float v15; // xmm1_4
  UFG::NavPath *v16; // rcx
  UFG::DaemonQueryOutput output; // [rsp+20h] [rbp-B8h] BYREF
  __int64 v18; // [rsp+38h] [rbp-A0h]
  void *mem; // [rsp+40h] [rbp-98h]
  UFG::NavPath *v20; // [rsp+48h] [rbp-90h]
  UFG::FindPathMultiDestPrioritizedImmediateQuery v21; // [rsp+50h] [rbp-88h] BYREF

  *(_QWORD *)(&v21.m_npFrom.m_aiMeshUid + 1) = -2i64;
  m_pPointer = this->m_queryParams.pOwnerSimObject.m_pPointer;
  if ( m_pPointer )
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  *(_QWORD *)&v21.m_internalType = 1i64;
  v21.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FindPathMultiDestPrioritizedImmediateQuery::`vftable;
  v21.m_daemonType = LODWORD(UFG::qVector3::msZero.z);
  *(hkVector4f *)&v21.m_pOutput = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&v21.m_npFrom.m_vPosition.x = -1i64;
  *(_QWORD *)&v21.m_npFrom.m_bValid = 0i64;
  v21.m_npFrom.m_hkvMeshPosition.m_quad.m128_i32[0] = -1;
  *(_QWORD *)&v21.m_npFrom.m_packedKey = 0i64;
  v21.m_npFrom.m_hkvMeshPosition.m_quad.m128_u64[1] = 0i64;
  output.m_id = DaemonType_Navigation;
  *(_QWORD *)&output.m_internalType = 1i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathMultiDestPrioritizedOutput::`vftable;
  mem = 0i64;
  v18 = 0i64;
  v20 = 0i64;
  ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))ComponentOfType[1].m_SafePointerList.mNode.mNext->mPrev)(&ComponentOfType[1].m_SafePointerList.mNode.mNext);
  v4 = *(float *)&ComponentOfType[1].m_NameUID;
  v5 = *(_DWORD *)&ComponentOfType[1].m_Flags;
  LODWORD(v21.m_npFrom.m_vPosition.x) = ComponentOfType[1].m_TypeUID;
  v21.m_npFrom.m_vPosition.y = v4;
  v21.m_daemonType = v5;
  if ( LOBYTE(ComponentOfType[1].m_pSimObject) )
  {
    LOBYTE(v21.m_mode) = ComponentOfType[1].m_pSimObject;
    *(UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)&v21.m_pOutput = ComponentOfType[1].m_BoundComponentHandles;
    v21.m_npFrom.m_vPosition.x = *(float *)&ComponentOfType[2].vfptr;
    v21.m_npFrom.m_vPosition.y = *((float *)&ComponentOfType[2].vfptr + 1);
  }
  else
  {
    LOBYTE(v21.m_mode) = 0;
  }
  *(_QWORD *)&v21.m_npFrom.m_bValid = (char *)ComponentOfType + 188;
  v6 = 0;
  v21.m_maxSearchIterations = 0;
  v7 = 0;
  p_navPos = &this->m_aRangedPositions.p[0].navPos;
  do
  {
    if ( LOBYTE(p_navPos[1].vfptr) )
    {
      ((void (__fastcall *)(UFG::HavokNavPosition *))p_navPos->vfptr->Validate)(p_navPos);
      v9 = p_navPos->vfptr->IsMeshPositionValid(p_navPos);
      LOBYTE(p_navPos[1].vfptr) = v9;
      if ( v9 )
      {
        *(&v21.m_maxSearchIterations + v6 + 1) = v7;
        v6 = ++v21.m_maxSearchIterations;
        UFG::FindPathMultiDestPrioritizedImmediateQuery::AddDestination(
          &v21,
          p_navPos,
          p_navPos[1].m_vPosition.z / this->m_queryParams.fPathPriority);
      }
    }
    ++v7;
    p_navPos = (UFG::HavokNavPosition *)((char *)p_navPos + 144);
  }
  while ( v7 < 0x20 );
  if ( v6 )
  {
    v10 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::SubmitQuery(v10, &v21, &output);
    this->m_fBestPositionScore = -3.4028235e38;
    if ( output.m_status == Status_Completed )
    {
      v11 = 0i64;
      v12 = v6;
      do
      {
        v13 = *(unsigned int *)((char *)&v21.m_maxSearchIterations + v11 + 4);
        v14 = *(float *)((char *)mem + v11) * this->m_queryParams.fPathPriority;
        this->m_aRangedPositions.p[v13].fPathCost = v14;
        v15 = this->m_aRangedPositions.p[v13].fTotalPriority - v14;
        if ( v15 > this->m_fBestPositionScore )
        {
          this->m_iBestPositionIndex = v13;
          this->m_fBestPositionScore = v15;
        }
        v11 += 4i64;
        --v12;
      }
      while ( v12 );
      this->m_pFoundPath = v20;
    }
  }
  this->m_uState = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[this->m_uState].m_NextLogicalState;
  this->m_bStateNeedsInit = 1;
  v21.m_maxSearchIterations = 0;
  v16 = v20;
  if ( v20 )
  {
    --v20->m_uRefCount;
    if ( !v16->m_uRefCount )
      v16->vfptr->__vecDelDtor(v16, 1u);
  }
  if ( mem )
    operator delete[](mem);
  mem = 0i64;
  v18 = 0i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  if ( *(_QWORD *)&v21.m_npFrom.m_packedKey )
    operator delete[](*(void **)&v21.m_npFrom.m_packedKey);
}

// File Line: 364
// RVA: 0x327260
void __fastcall UFG::AIRangedLineOfSightQuery::ChooseBest(UFG::AIRangedLineOfSightQuery *this)
{
  __int64 m_iBestPositionIndex; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  unsigned int m_NextLogicalState; // eax

  m_iBestPositionIndex = (unsigned int)this->m_iBestPositionIndex;
  if ( (int)m_iBestPositionIndex < 0 )
  {
    this->m_uState = 9;
  }
  else
  {
    y = this->m_aRangedPositions.p[m_iBestPositionIndex].vGroundPosition.y;
    z = this->m_aRangedPositions.p[m_iBestPositionIndex].vGroundPosition.z;
    this->m_vBestPosition.x = this->m_aRangedPositions.p[m_iBestPositionIndex].vGroundPosition.x;
    this->m_vBestPosition.y = y;
    this->m_vBestPosition.z = z;
    m_NextLogicalState = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[this->m_uState].m_NextLogicalState;
    this->m_bStateNeedsInit = 1;
    this->m_uState = m_NextLogicalState;
  }
}

