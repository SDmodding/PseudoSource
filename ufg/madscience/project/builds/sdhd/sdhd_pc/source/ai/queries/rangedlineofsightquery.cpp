// File Line: 48
// RVA: 0x32BBB0
void __fastcall UFG::AIRangedLineOfSightQuery::AIRangedLineOfSightQuery(UFG::AIRangedLineOfSightQuery *this)
{
  UFG::AIRangedLineOfSightQuery::QueryParameters *v1; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // [rsp+50h] [rbp+18h]

  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AIQuery::`vftable';
  this->m_bStateNeedsInit = 1;
  *(_QWORD *)&this->m_iRefCount = 0i64;
  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AIRangedLineOfSightQuery::`vftable';
  v1 = &this->m_queryParams;
  v1->pOwnerSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->pOwnerSimObject.mPrev;
  v1->pOwnerSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->pOwnerSimObject.mPrev;
  this->m_queryParams.pOwnerSimObject.m_pPointer = 0i64;
  v2 = &this->m_queryParams.pTargetSimObject;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->m_pPointer = 0i64;
  UFG::qFixedArray<UFG::AIRangedLineOfSightQuery::RangedPosition,32>::qFixedArray<UFG::AIRangedLineOfSightQuery::RangedPosition,32>(&this->m_aRangedPositions);
}

// File Line: 66
// RVA: 0x326570
void __fastcall UFG::AIRangedLineOfSightQuery::InitializeQuery(UFG::AIRangedLineOfSightQuery *this)
{
  UFG::AIRangedLineOfSightQuery *v1; // rbx
  __int64 v2; // rax

  v1 = this;
  UFG::GetDesiredRanges(
    this->m_queryParams.pOwnerSimObject.m_pPointer,
    &this->m_fMinDesiredRange,
    &this->m_fMaxDesiredRange,
    &this->m_fDesiredRange);
  UFG::ComputeObjectRaycastPosition(v1->m_queryParams.pTargetSimObject.m_pPointer, &v1->m_vTargetPosition);
  v2 = v1->m_uState;
  v1->m_aRangedPositions.size = 32;
  v1->m_iBestPositionIndex = -1;
  LODWORD(v2) = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[v2].m_NextLogicalState;
  v1->m_bStateNeedsInit = 1;
  v1->m_uState = v2;
}

// File Line: 84
// RVA: 0x3265D0
void __fastcall UFG::AIRangedLineOfSightQuery::SeedPoints(UFG::AIRangedLineOfSightQuery *this)
{
  UFG::SimObject *v1; // rdi
  signed int v2; // esi
  UFG::AIRangedLineOfSightQuery *v3; // rbx
  UFG::TransformNodeComponent *v4; // rdi
  float v5; // xmm8_4
  float v6; // xmm9_4
  float v7; // xmm10_4
  signed __int64 v8; // rdi
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  unsigned int v13; // eax

  v1 = this->m_queryParams.pTargetSimObject.m_pPointer;
  v2 = 0;
  v3 = this;
  if ( v1 )
    v4 = v1->m_pTransformNodeComponent;
  else
    v4 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  v5 = v4->mWorldTransform.v3.x;
  v6 = v4->mWorldTransform.v3.y;
  v7 = v4->mWorldTransform.v3.z;
  v8 = (signed __int64)&v3->m_aRangedPositions.p[0].vSeedPoint.z;
  do
  {
    v9 = (float)v2 * 0.19634955;
    v10 = cosf(v9);
    v11 = sinf(v9);
    ++v2;
    v8 += 144i64;
    v12 = UFG::qRandom(v3->m_queryParams.fMaxDistance - v3->m_queryParams.fMinDistance, &UFG::qDefaultSeed)
        + v3->m_queryParams.fMinDistance;
    *(float *)(v8 - 144) = (float)(v12 * 0.0) + v7;
    *(float *)(v8 - 152) = (float)(v10 * v12) + v5;
    *(float *)(v8 - 148) = (float)(v11 * v12) + v6;
    *(_BYTE *)(v8 - 40) = 0;
  }
  while ( (unsigned int)v2 < 0x20 );
  v13 = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[v3->m_uState].m_NextLogicalState;
  v3->m_bStateNeedsInit = 1;
  v3->m_uState = v13;
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
  UFG::AIRangedLineOfSightQuery *v1; // rdi
  UFG::SimObjectGame *v2; // rcx
  UFG::SimComponent *v3; // rax
  unsigned __int16 v4; // dx
  UFG::CombatRegion *v5; // rbp
  unsigned __int64 v6; // rax
  __int64 v7; // rax
  float v8; // xmm3_4
  float v9; // xmm6_4
  signed __int64 v10; // rbx
  char v11; // si
  float cast_distance_up; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  int v17; // xmm1_4
  int v18; // xmm0_4
  signed __int64 v19; // rsi
  unsigned __int64 v20; // kr00_8
  float v21; // xmm10_4
  unsigned int v22; // eax
  UFG::qVector3 out; // [rsp+30h] [rbp-C8h]
  hkVector4f hkvNewPosition; // [rsp+40h] [rbp-B8h]

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_queryParams.pOwnerSimObject.m_pPointer;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = v2->m_Components.p[22].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIEntityComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIEntityComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v3 = v2->m_Components.p[22].m_pComponent;
    }
  }
  else
  {
    v3 = 0i64;
  }
  v5 = *(UFG::CombatRegion **)&v3[15].m_TypeUID;
  while ( v1->m_bCanContinue )
  {
    v6 = UFG::qGetTicks();
    if ( UFG::qGetTickTime(v1->m_uStartTicks, v6) >= v1->m_fDuration )
      break;
    v7 = v1->m_uCurrentCulling;
    if ( (unsigned int)v7 >= 0x20 )
      break;
    v8 = FLOAT_6_0;
    v9 = FLOAT_3_4028235e38;
    v10 = (signed __int64)&v1->m_aRangedPositions.p[v7];
    v11 = 0;
    cast_distance_up = FLOAT_6_0;
    while ( UFG::PlaceOnGround(&out, (UFG::qVector3 *)v10, 0.0, v8, cast_distance_up) )
    {
      v13 = out.z;
      v11 = 1;
      v14 = out.z - *(float *)(v10 + 8);
      LODWORD(v15) = LODWORD(v14) & _xmm;
      if ( COERCE_FLOAT(LODWORD(v14) & _xmm) >= v9 )
        goto LABEL_23;
      cast_distance_up = v14 - 1.0;
      v9 = v15;
      v16 = out.x;
      *(float *)(v10 + 16) = out.y;
      *(float *)(v10 + 12) = v16;
      *(float *)(v10 + 20) = v13;
      if ( cast_distance_up < 0.0 || cast_distance_up <= -6.0 )
        goto LABEL_23;
      v8 = FLOAT_6_0;
    }
    if ( !v11 )
      goto LABEL_30;
LABEL_23:
    if ( !v5 || UFG::CombatRegion::IsHitPoint(v5, (UFG::qVector3 *)(v10 + 12)) )
    {
      v17 = *(_DWORD *)(v10 + 20);
      v18 = *(_DWORD *)(v10 + 16);
      v19 = v10 + 48;
      *(_DWORD *)(v19 + 8) = *(_DWORD *)(v10 + 12);
      *(_DWORD *)(v19 + 16) = v17;
      *(_DWORD *)(v19 + 12) = v18;
      *(_BYTE *)(v19 + 24) = 0;
      (**(void (__fastcall ***)(signed __int64))(v10 + 48))(v10 + 48);
      if ( (*(unsigned __int8 (__fastcall **)(signed __int64))(*(_QWORD *)(v10 + 48) + 32i64))(v10 + 48) )
      {
        if ( UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall((hkVector4f *)(v10 + 80), &hkvNewPosition, 0.25) )
        {
          v20 = hkvNewPosition.m_quad.m128_u64[0];
          v21 = hkvNewPosition.m_quad.m128_f32[2];
          *(_QWORD *)(v10 + 56) = hkvNewPosition.m_quad.m128_u64[0];
          *(float *)(v10 + 64) = v21;
          *(_BYTE *)(v10 + 72) = 0;
          (**(void (__fastcall ***)(signed __int64))v19)(v10 + 48);
          if ( !(*(unsigned __int8 (__fastcall **)(signed __int64))(*(_QWORD *)v19 + 32i64))(v10 + 48) )
            goto LABEL_30;
          *(_QWORD *)(v10 + 12) = v20;
          *(float *)(v10 + 20) = v21;
        }
        *(_BYTE *)(v10 + 112) = 1;
      }
    }
LABEL_30:
    ++v1->m_uCurrentCulling;
  }
  if ( v1->m_uCurrentCulling == 32 )
  {
    v22 = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[v1->m_uState].m_NextLogicalState;
    v1->m_bStateNeedsInit = 1;
    v1->m_uState = v22;
  }
}edLineOfSi

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
  UFG::AIRangedLineOfSightQuery *v1; // rbx
  float v2; // xmm7_4
  float v3; // xmm9_4
  float v4; // xmm8_4
  unsigned __int64 v5; // rax
  signed __int64 v6; // rax
  signed __int64 v7; // rsi
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  UFG::qVector3 *v11; // rdx
  UFG::SimObjectGame *v12; // rdi
  unsigned __int64 v13; // rcx
  __int64 v14; // rax
  UFG::VehicleOccupantComponent *v15; // rbp
  unsigned __int16 v16; // cx
  UFG::CharacterOccupantComponent *v17; // rax
  unsigned int v18; // eax
  UFG::RayCastData data; // [rsp+20h] [rbp-128h]

  v1 = this;
  v2 = UFG::qVector3::msDirUp.x * 1.2;
  v3 = UFG::qVector3::msDirUp.z * 1.2;
  v4 = UFG::qVector3::msDirUp.y * 1.2;
  while ( v1->m_bCanContinue )
  {
    v5 = UFG::qGetTicks();
    if ( UFG::qGetTickTime(v1->m_uStartTicks, v5) >= v1->m_fDuration )
      break;
    v6 = v1->m_uCurrentLOSTest;
    if ( (unsigned int)v6 >= 0x20 )
      break;
    v7 = v6;
    if ( !v1->m_aRangedPositions.p[v6].bValid )
      goto LABEL_27;
    v8 = v2 + v1->m_aRangedPositions.p[v7].vGroundPosition.x;
    v9 = v4 + v1->m_aRangedPositions.p[v7].vGroundPosition.y;
    v10 = v3 + v1->m_aRangedPositions.p[v7].vGroundPosition.z;
    v11 = &v1->m_aRangedPositions.p[v7].vFiringPosition;
    data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
    data.mInput.m_filterInfo = 0;
    data.mInput.m_userData = 0i64;
    data.mOutput.m_hitFraction = 1.0;
    v11->x = v8;
    v11->y = v9;
    v11->z = v10;
    v12 = (UFG::SimObjectGame *)v1->m_queryParams.pTargetSimObject.m_pPointer;
    data.mOutput.m_extraInfo = -1;
    data.mOutput.m_shapeKeyIndex = 0;
    data.mOutput.m_shapeKeys[0] = -1;
    data.mOutput.m_rootCollidable = 0i64;
    data.mDebugName = 0i64;
    data.mCollisionModelName.mUID = -1;
    UFG::RayCastData::Init(&data, v11, &v1->m_vTargetPosition, 0xCu);
    UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
    if ( !data.hit
      || data.mHavokRigidBody
      && (v13 = data.mHavokRigidBody->m_userData) != 0
      && ((v14 = *(_QWORD *)(v13 + 24)) == 0 ? (v15 = 0i64) : (v15 = *(UFG::VehicleOccupantComponent **)(v14 + 40)),
          v15 == (UFG::VehicleOccupantComponent *)v12
       || v12
       && ((v16 = v12->m_Flags, !((v16 >> 14) & 1)) ? ((v16 & 0x8000u) == 0 ? (!((v16 >> 13) & 1) ? (!((v16 >> 12) & 1) ? (v17 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v17 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CharacterOccupantComponent::_TypeUID))) : (v17 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CharacterOccupantComponent::_TypeUID))) : (v17 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CharacterOccupantComponent::_TypeUID))) : (v17 = (UFG::CharacterOccupantComponent *)v12->m_Components.p[44].m_pComponent),
           v17 && UFG::CharacterOccupantComponent::GetCurrentVehicle(v17) == v15)) )
    {
      LODWORD(v1->m_aRangedPositions.p[v7].fLineOfSightPriority) = (_DWORD)FLOAT_1_0;
LABEL_27:
      ++v1->m_uCurrentLOSTest;
    }
    else
    {
      v1->m_aRangedPositions.p[v7].fLineOfSightPriority = 0.0;
      ++v1->m_uCurrentLOSTest;
    }
  }
  if ( v1->m_uCurrentLOSTest == 32 )
  {
    v18 = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[v1->m_uState].m_NextLogicalState;
    v1->m_bStateNeedsInit = 1;
    v1->m_uState = v18;
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
  UFG::AIRangedLineOfSightQuery *i; // rbx
  unsigned __int64 v2; // rax
  __int64 v3; // rax
  __m128 v4; // xmm2
  float v5; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  unsigned int v9; // eax

  for ( i = this; i->m_bCanContinue; ++i->m_uCurrentPrioritizing )
  {
    v2 = UFG::qGetTicks();
    if ( UFG::qGetTickTime(i->m_uStartTicks, v2) >= i->m_fDuration )
      break;
    v3 = i->m_uCurrentPrioritizing;
    if ( (unsigned int)v3 >= 0x20 )
      break;
    if ( i->m_aRangedPositions.p[v3].bValid )
    {
      v4 = (__m128)LODWORD(i->m_aRangedPositions.p[v3].vFiringPosition.x);
      v5 = i->m_fDesiredRange;
      v4.m128_f32[0] = (float)((float)((float)(v4.m128_f32[0] - i->m_vTargetPosition.x)
                                     * (float)(v4.m128_f32[0] - i->m_vTargetPosition.x))
                             + (float)((float)(i->m_aRangedPositions.p[v3].vFiringPosition.y - i->m_vTargetPosition.y)
                                     * (float)(i->m_aRangedPositions.p[v3].vFiringPosition.y - i->m_vTargetPosition.y)))
                     + (float)((float)(i->m_aRangedPositions.p[v3].vFiringPosition.z - i->m_vTargetPosition.z)
                             * (float)(i->m_aRangedPositions.p[v3].vFiringPosition.z - i->m_vTargetPosition.z));
      LODWORD(v6) = (unsigned __int128)_mm_sqrt_ps(v4);
      if ( v6 >= v5 )
      {
        v8 = (float)(i->m_fMaxDesiredRange - v6) / (float)(i->m_fMaxDesiredRange - v5);
        if ( v8 <= 0.0 )
          v8 = 0.0;
        i->m_aRangedPositions.p[v3].fDistancePriority = v8;
      }
      else
      {
        v7 = (float)(v6 - i->m_fMinDesiredRange) / (float)(v5 - i->m_fMinDesiredRange);
        if ( v7 <= 0.0 )
          v7 = 0.0;
        i->m_aRangedPositions.p[v3].fDistancePriority = v7;
      }
      i->m_aRangedPositions.p[v3].fTotalPriority = (float)(i->m_aRangedPositions.p[v3].fLineOfSightPriority
                                                         * i->m_queryParams.fLineOfSightPriority)
                                                 + (float)(i->m_queryParams.fDistancePriority
                                                         * i->m_aRangedPositions.p[v3].fDistancePriority);
    }
  }
  if ( i->m_uCurrentPrioritizing == 32 )
  {
    v9 = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[i->m_uState].m_NextLogicalState;
    i->m_bStateNeedsInit = 1;
    i->m_uState = v9;
  }
}

// File Line: 294
// RVA: 0x326EF0
void __fastcall UFG::AIRangedLineOfSightQuery::TestDirectPath(UFG::AIRangedLineOfSightQuery *this)
{
  unsigned int v1; // eax

  v1 = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[this->m_uState].m_NextLogicalState;
  this->m_bStateNeedsInit = 1;
  this->m_uState = v1;
}

// File Line: 299
// RVA: 0x326F10
void __fastcall UFG::AIRangedLineOfSightQuery::PathTest(UFG::AIRangedLineOfSightQuery *this)
{
  UFG::AIRangedLineOfSightQuery *v1; // rdi
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rsi
  float v4; // xmm1_4
  UFG::DaemonType v5; // xmm2_4
  unsigned int v6; // esi
  unsigned int v7; // er14
  UFG::HavokNavPosition *v8; // rbx
  bool v9; // al
  UFG::DaemonManager *v10; // rax
  __int64 v11; // rdx
  __int64 v12; // r9
  __int64 v13; // r8
  float v14; // xmm0_4
  float v15; // xmm1_4
  __int64 v16; // rcx
  UFG::DaemonQueryOutput output; // [rsp+20h] [rbp-B8h]
  __int64 v18; // [rsp+38h] [rbp-A0h]
  void *mem; // [rsp+40h] [rbp-98h]
  UFG::NavPath *v20; // [rsp+48h] [rbp-90h]
  UFG::FindPathMultiDestPrioritizedImmediateQuery v21; // [rsp+50h] [rbp-88h]

  *(_QWORD *)(&v21.m_npFrom.m_aiMeshUid + 1) = -2i64;
  v1 = this;
  v2 = this->m_queryParams.pOwnerSimObject.m_pPointer;
  if ( v2 )
    v3 = UFG::SimObject::GetComponentOfType(v2, UFG::NavComponent::_TypeUID);
  else
    v3 = 0i64;
  *(_QWORD *)&v21.m_internalType = 1i64;
  v21.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FindPathMultiDestPrioritizedImmediateQuery::`vftable';
  v21.m_daemonType = LODWORD(UFG::qVector3::msZero.z);
  LOBYTE(v21.m_mode) = 0;
  *(hkVector4f *)&v21.m_pOutput = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&v21.m_npFrom.m_vPosition.x = -1i64;
  *(_QWORD *)&v21.m_npFrom.m_bValid = 0i64;
  v21.m_npFrom.m_hkvMeshPosition.m_quad.m128_i32[0] = -1;
  *(_QWORD *)&v21.m_npFrom.m_packedKey = 0i64;
  v21.m_npFrom.m_hkvMeshPosition.m_quad.m128_u64[1] = 0i64;
  output.m_id = 0;
  *(_QWORD *)&output.m_internalType = 1i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathMultiDestPrioritizedOutput::`vftable';
  mem = 0i64;
  v18 = 0i64;
  v20 = 0i64;
  ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))v3[1].m_SafePointerList.mNode.mNext->mPrev)(&v3[1].m_SafePointerList.mNode.mNext);
  v4 = *(float *)&v3[1].m_NameUID;
  v5 = *(_DWORD *)&v3[1].m_Flags;
  LODWORD(v21.m_npFrom.m_vPosition.x) = v3[1].m_TypeUID;
  v21.m_npFrom.m_vPosition.y = v4;
  v21.m_daemonType = v5;
  if ( LOBYTE(v3[1].m_pSimObject) )
  {
    LOBYTE(v21.m_mode) = v3[1].m_pSimObject;
    *(UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)&v21.m_pOutput = v3[1].m_BoundComponentHandles;
    v21.m_npFrom.m_vPosition.x = *(float *)&v3[2].vfptr;
    v21.m_npFrom.m_vPosition.y = *((float *)&v3[2].vfptr + 1);
  }
  else
  {
    LOBYTE(v21.m_mode) = 0;
  }
  *(_QWORD *)&v21.m_npFrom.m_bValid = (char *)v3 + 188;
  v6 = 0;
  v21.m_maxSearchIterations = 0;
  v7 = 0;
  v8 = &v1->m_aRangedPositions.p[0].navPos;
  do
  {
    if ( LOBYTE(v8[1].vfptr) )
    {
      ((void (__fastcall *)(UFG::HavokNavPosition *))v8->vfptr->Validate)(v8);
      v9 = v8->vfptr->IsMeshPositionValid((UFG::NavPositionBase *)&v8->vfptr);
      LOBYTE(v8[1].vfptr) = v9;
      if ( v9 )
      {
        *(&v21.m_maxSearchIterations + v6 + 1) = v7;
        v6 = v21.m_maxSearchIterations++ + 1;
        UFG::FindPathMultiDestPrioritizedImmediateQuery::AddDestination(
          &v21,
          v8,
          v8[1].m_vPosition.z / v1->m_queryParams.fPathPriority);
      }
    }
    ++v7;
    v8 = (UFG::HavokNavPosition *)((char *)v8 + 144);
  }
  while ( v7 < 0x20 );
  if ( v6 )
  {
    v10 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::SubmitQuery(v10, (UFG::DaemonQueryInput *)&v21.vfptr, &output);
    v1->m_fBestPositionScore = -3.4028235e38;
    if ( output.m_status == 3 )
    {
      if ( v6 )
      {
        v11 = 0i64;
        v12 = v6;
        do
        {
          v13 = *(unsigned int *)((char *)&v21.m_maxSearchIterations + v11 + 4);
          v14 = *(float *)((char *)mem + v11) * v1->m_queryParams.fPathPriority;
          v1->m_aRangedPositions.p[v13].fPathCost = v14;
          v15 = v1->m_aRangedPositions.p[v13].fTotalPriority - v14;
          if ( v15 > v1->m_fBestPositionScore )
          {
            v1->m_iBestPositionIndex = v13;
            v1->m_fBestPositionScore = v15;
          }
          v11 += 4i64;
          --v12;
        }
        while ( v12 );
      }
      v1->m_pFoundPath = v20;
    }
  }
  v1->m_uState = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[v1->m_uState].m_NextLogicalState;
  v1->m_bStateNeedsInit = 1;
  v21.m_maxSearchIterations = 0;
  v16 = (__int64)v20;
  if ( v20 )
  {
    --v20->m_uRefCount;
    if ( !*(_DWORD *)(v16 + 40) )
      (**(void (__fastcall ***)(__int64, signed __int64))v16)(v16, 1i64);
  }
  if ( mem )
    operator delete[](mem);
  mem = 0i64;
  v18 = 0i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable';
  if ( *(_QWORD *)&v21.m_npFrom.m_packedKey )
    operator delete[](*(void **)&v21.m_npFrom.m_packedKey);
}

// File Line: 364
// RVA: 0x327260
void __fastcall UFG::AIRangedLineOfSightQuery::ChooseBest(UFG::AIRangedLineOfSightQuery *this)
{
  __int64 v1; // rax
  float v2; // xmm0_4
  float v3; // xmm1_4
  unsigned int v4; // eax

  v1 = (unsigned int)this->m_iBestPositionIndex;
  if ( (signed int)v1 < 0 )
  {
    this->m_uState = 9;
  }
  else
  {
    v2 = this->m_aRangedPositions.p[v1].vGroundPosition.y;
    v3 = this->m_aRangedPositions.p[v1].vGroundPosition.z;
    this->m_vBestPosition.x = this->m_aRangedPositions.p[v1].vGroundPosition.x;
    this->m_vBestPosition.y = v2;
    this->m_vBestPosition.z = v3;
    v4 = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[this->m_uState].m_NextLogicalState;
    this->m_bStateNeedsInit = 1;
    this->m_uState = v4;
  }
}

