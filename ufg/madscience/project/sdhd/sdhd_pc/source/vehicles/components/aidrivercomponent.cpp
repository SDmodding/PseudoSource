// File Line: 91
// RVA: 0x1573920
__int64 dynamic_initializer_for__UFG::AiDriverComponent::s_AiDriverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AiDriverComponent::s_AiDriverComponentList__);
}

// File Line: 92
// RVA: 0x15737C0
__int64 dynamic_initializer_for__UFG::AiDriverComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::AiDriverComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::AiDriverComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::AiDriverComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::AiDriverComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 335
// RVA: 0x15738B0
__int64 dynamic_initializer_for__UFG::AiDriverComponent::mNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TrafficAI", 0xFFFFFFFF);
  UFG::AiDriverComponent::mNameUID = result;
  return result;
}

// File Line: 413
// RVA: 0x644E10
void UFG::AiDriverComponent::AddTweakables(void)
{
  UFG::AiDriverComponent::m_pLowLODSteering.m_P_Coefficient = 1.0;
  UFG::AiDriverComponent::m_pHighLODSteering.m_P_Coefficient = 1.0;
  UFG::AiDriverComponent::m_pHighLODSteering.m_D_Coefficient = 0.039999999;
  UFG::AiDriverComponent::m_Throttle.m_I_Coefficient = 0.0;
  UFG::AiDriverComponent::m_pHighLODSteering.m_I_Coefficient = FLOAT_0_0099999998;
  UFG::AiDriverComponent::m_pBoatSteering.m_P_Coefficient = FLOAT_1_2;
  UFG::AiDriverComponent::m_BoatThrottle.m_D_Coefficient = 0.039999999;
  UFG::AiDriverComponent::m_BoatThrottle.m_I_Coefficient = 0.0;
  UFG::AiDriverComponent::m_pBoatSteering.m_D_Coefficient = FLOAT_0_80000001;
  UFG::AiDriverComponent::m_pBoatSteering.m_I_Coefficient = FLOAT_0_2;
  UFG::AiDriverComponent::m_Throttle.m_P_Coefficient = FLOAT_0_029999999;
  UFG::AiDriverComponent::m_Throttle.m_D_Coefficient = FLOAT_0_02;
  UFG::AiDriverComponent::m_BoatThrottle.m_P_Coefficient = FLOAT_0_079999998;
  UFG::AiDriverComponent::m_CatchupParams.m_P_Coefficient = UFG::AiDriverComponent::m_Catchup_P;
  UFG::AiDriverComponent::m_CatchupParams.m_I_Coefficient = UFG::AiDriverComponent::m_Catchup_I;
  UFG::AiDriverComponent::m_CatchupParams.m_D_Coefficient = UFG::AiDriverComponent::m_Catchup_D;
}

// File Line: 773
// RVA: 0x642500
void __fastcall UFG::AiDriverComponent::AiDriverComponent(UFG::AiDriverComponent *this, bool isAmbient)
{
  bool v2; // di
  UFG::AiDriverComponent *v3; // r14
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *v4; // rsi
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::SensorPhantom *v13; // rax
  signed __int64 v14; // rbx
  char v15; // dl
  __int64 v16; // rax
  char v17; // cl
  _QWORD **v18; // rax
  hkpSphereShape *v19; // rax
  hkpSphereShape *v20; // rax
  char v21; // al
  char v22; // dl
  __int64 v23; // rax
  char v24; // cl
  _QWORD **v25; // rax
  hkpSimpleShapePhantom *v26; // rax
  hkpSimpleShapePhantom *v27; // rax
  char v28; // al
  hkAabb aabb; // [rsp+40h] [rbp-88h]
  hkTransformf transform; // [rsp+60h] [rbp-68h]
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *v31; // [rsp+E0h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *v32; // [rsp+E0h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *v33; // [rsp+E0h] [rbp+18h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v34; // [rsp+E0h] [rbp+18h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v35; // [rsp+E0h] [rbp+18h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v36; // [rsp+E0h] [rbp+18h]

  v2 = isAmbient;
  v3 = this;
  UFG::VehicleDriverInterface::VehicleDriverInterface(
    (UFG::VehicleDriverInterface *)&this->vfptr,
    UFG::AiDriverComponent::mNameUID);
  v4 = (UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AiDriverComponent::`vftable{for `UFG::SimComponent};
  v3->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AiDriverComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0>::RebindingComponentHandle<UFG::RoadSpaceComponent,0>(&v3->m_pRoadSpace);
  UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>(&v3->m_pVehicleSubject);
  v31 = &v3->m_pChaseVehicleSubject;
  v31->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v31->mPrev;
  v31->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v31->mPrev;
  v3->m_pChaseVehicleSubject.m_pPointer = 0i64;
  v32 = &v3->m_pEscortEnemyVehicleSubject;
  v32->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v32->mPrev;
  v32->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v32->mPrev;
  v3->m_pEscortEnemyVehicleSubject.m_pPointer = 0i64;
  v33 = &v3->m_pEscortObjectiveVehicleSubject;
  v33->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v33->mPrev;
  v33->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v33->mPrev;
  v3->m_pEscortObjectiveVehicleSubject.m_pPointer = 0i64;
  UFG::qPidControllerCore::qPidControllerCore(&v3->m_SteeringPid);
  UFG::qPidControllerCore::qPidControllerCore(&v3->m_ThrottlePid);
  UFG::DrivingTargetOffsetMover::DrivingTargetOffsetMover(&v3->m_OffsetMover);
  v3->m_DriveToCoroutine.i_obj_p = 0i64;
  v3->m_DriveToCoroutine.i_ptr_id = 0;
  *(_QWORD *)&v3->m_DrivingMode = 0i64;
  v34 = &v3->m_CatchupTarget;
  v34->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v34->mPrev;
  v34->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v34->mPrev;
  v3->m_CatchupTarget.m_pPointer = 0i64;
  UFG::qPidControllerCore::qPidControllerCore(&v3->m_CatchupPid);
  v3->m_CatchupRangeBehind = 10.0;
  *(_QWORD *)&v3->m_CatchupRangeAhead = 1092616192i64;
  *(_QWORD *)&v3->m_CatchupMaxSlowDown = 0i64;
  *(_QWORD *)&v3->m_fDesiredSpeed = 0i64;
  v3->m_fPreviousGasBrakes = 0.0;
  v3->m_RoadSpeedLimit = -1.0;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  v3->m_vSteerToPosition.x = UFG::qVector3::msZero.x;
  v3->m_vSteerToPosition.y = v5;
  v3->m_vSteerToPosition.z = v6;
  v3->m_fSteeringScale = 1.0;
  *(_WORD *)&v3->m_FollowDebug = 0;
  *(_QWORD *)&v3->m_DesiredOffset = 0i64;
  *(_QWORD *)&v3->m_vFollowOffsetActual.x = 0i64;
  v3->m_vFollowOffsetActual.z = 0.0;
  v7 = UFG::AiDriverComponent::mCombatCarOffsets[v3->m_DesiredOffset].y;
  v8 = UFG::AiDriverComponent::mCombatCarOffsets[v3->m_DesiredOffset].z;
  v3->m_vFollowOffsetDesired.x = UFG::AiDriverComponent::mCombatCarOffsets[v3->m_DesiredOffset].x;
  v3->m_vFollowOffsetDesired.y = v7;
  v3->m_vFollowOffsetDesired.z = v8;
  *(_QWORD *)&v3->m_fFollowOffsetBlend = 0i64;
  *(_QWORD *)&v3->m_fFollowDistance = 0i64;
  v3->m_fAttackTime = 0.0;
  v3->m_iLastHighSpeedCollisionTimestamp = 0i64;
  UFG::qNoise<float,float>::qNoise<float,float>(&v3->m_SteeringNoise);
  v3->mModeSteeringLockEnabled = 0;
  v3->mModeSteeringLock = 0.0;
  v3->mModeGasBrakeLockEnabled = 0;
  v3->mModeGasBrakeLock = 0.0;
  v3->m_bSteeringLock = 0;
  v3->m_fSteeringLock = 0.0;
  v3->m_bGasBrakeLock = 0;
  *(_QWORD *)&v3->m_fGasBrakeLock = 0i64;
  UFG::RingBuffer<UFG::HistoryItem<UFG::qVector2>>::RingBuffer<UFG::HistoryItem<UFG::qVector2>>(
    &v3->m_SteeringGasBrakeHistory.mRingBuffer,
    20);
  *(_QWORD *)&v3->m_SteeringGasBrakeHistory.fDuration = 0x40000000i64;
  v3->m_fAvoidSteerLimit = -1.0;
  *(_QWORD *)&v3->m_fAvoidStopTimer = 0i64;
  *(_QWORD *)&v3->m_fStuckTimer = 0i64;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v3->m_vStuckPosition.x = UFG::qVector3::msZero.x;
  v3->m_vStuckPosition.y = v9;
  v3->m_vStuckPosition.z = v10;
  v3->m_GettingUnstuckTimer = -1.0;
  v3->m_BeenUnstuckTimer = -1.0;
  *(_QWORD *)&v3->m_fPassingTimer = 0i64;
  v3->m_NumAvoidableOverlaps = 0;
  v35 = &v3->m_CurrentAvoidable;
  v35->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v35->mPrev;
  v35->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v35->mPrev;
  v3->m_CurrentAvoidable.m_pPointer = 0i64;
  v3->m_BlockedByAvoidable = 0;
  UFG::VehicleCombatStats::VehicleCombatStats(&v3->m_CombatStats);
  v3->m_EscortInfo.eEscortMode = 1;
  v3->m_EscortInfo.fDistanceSqrEnemyToObjectiveEnterAttackMode = 400.0;
  v3->m_EscortInfo.fDistanceSqrEnemyToObjectiveEnterEscortMode = 625.0;
  *(_DWORD *)&v3->m_bAvoidPeds = 16842753;
  *(_DWORD *)&v3->m_ObeyTrafficLights = 65537;
  *(_WORD *)&v3->m_RoadRuleFlagsLocked = 256;
  v3->m_AiScriptControlled = 0;
  v3->m_TempPassLaneChangeDirectionCode = 0;
  *(_WORD *)&v3->m_bIgnoreArrivalDirection = 0;
  v3->m_IsAmbient = v2;
  v3->m_AmbientDriverType = v2 != 0;
  *(_QWORD *)&v3->m_fSearchTimer = 0i64;
  v3->m_RoadSpeedLimitScale = -1.0;
  v3->m_DesiredSpeedLimit = -1.0;
  *(_DWORD *)&v3->m_AvoidObjectsEnabled = 16777473;
  v36 = &v3->m_PathingTarget;
  v36->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v36->mPrev;
  v36->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v36->mPrev;
  v3->m_PathingTarget.m_pPointer = 0i64;
  v3->m_StopAtDist = 20.0;
  v3->m_StopAtUseDestinationDirection = 0;
  *(_QWORD *)&v3->m_StopInfo.eStopStyle = 0i64;
  *((_BYTE *)&v3->m_StopInfo + 8) &= 0xFEu;
  *(_QWORD *)&v3->m_StopDist = 1065353216i64;
  v3->m_ResetStopDistOnStop = 1;
  v3->m_fChaseSpeedLimit = -1.0;
  v3->m_fRaceSpeedLimit = -1.0;
  *(_DWORD *)&v3->m_RaceWanderAtEnd = 0;
  v3->m_CappingSpeedForNextGuide = 0;
  v11 = UFG::AiDriverComponent::s_AiDriverComponentList.mNode.mPrev;
  UFG::AiDriverComponent::s_AiDriverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *)&v3->mPrev;
  v4->mPrev = v11;
  v3->mNext = (UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *)&UFG::AiDriverComponent::s_AiDriverComponentList;
  UFG::AiDriverComponent::s_AiDriverComponentList.mNode.mPrev = (UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::AiDriverComponent::_AiDriverComponentTypeUID,
    "AiDriverComponent");
  aabb.m_min = (hkVector4f)_xmm;
  aabb.m_max = (hkVector4f)_xmm;
  v12 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x18ui64, "SensorPhantom", 0i64, 1u);
  if ( v12 )
    UFG::SensorPhantom::SensorPhantom((UFG::SensorPhantom *)v12, &aabb, 0x18u, "AvoidableSensor");
  else
    v13 = 0i64;
  v3->m_AvoidableSensor = v13;
  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_translation = 0i64;
  v14 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v15 = ++*(_BYTE *)(v14 + 80);
  v16 = v15;
  *(_DWORD *)(v14 + 4 * v16) = 3;
  *(_QWORD *)(v14 + 8 * v16 + 16) = "hkpSphereShape";
  *(_QWORD *)(v14 + 8 * v16 + 48) = 0i64;
  v17 = *(_BYTE *)(v14 + 81);
  if ( v15 > v17 )
    v17 = v15;
  *(_BYTE *)(v14 + 81) = v17;
  v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(v18[11], 56i64);
  if ( v19 )
    hkpSphereShape::hkpSphereShape(v19, UFG::AiDriverComponent::m_fAvoidanceCastingRadius);
  else
    v20 = 0i64;
  v3->m_pCastingSphere = v20;
  v21 = *(_BYTE *)(v14 + 80);
  if ( v21 > 0 )
  {
    *(_BYTE *)(v14 + 80) = v21 - 1;
  }
  else
  {
    *(_BYTE *)(v14 + 80) = 0;
    *(_DWORD *)v14 = 3;
    *(_QWORD *)(v14 + 16) = 0i64;
    *(_QWORD *)(v14 + 48) = 0i64;
  }
  v22 = ++*(_BYTE *)(v14 + 80);
  v23 = v22;
  *(_DWORD *)(v14 + 4 * v23) = 3;
  *(_QWORD *)(v14 + 8 * v23 + 16) = "hkpSimpleShapePhantom";
  *(_QWORD *)(v14 + 8 * v23 + 48) = 0i64;
  v24 = *(_BYTE *)(v14 + 81);
  if ( v22 > v24 )
    v24 = v22;
  *(_BYTE *)(v14 + 81) = v24;
  v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (hkpSimpleShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v25[11] + 8i64))(
                                   v25[11],
                                   448i64);
  if ( v26 )
    hkpSimpleShapePhantom::hkpSimpleShapePhantom(v26, (hkpShape *)&v3->m_pCastingSphere->vfptr, &transform, 0x17u);
  else
    v27 = 0i64;
  v3->m_pCastingPhantom = v27;
  v28 = *(_BYTE *)(v14 + 80);
  if ( v28 > 0 )
  {
    *(_BYTE *)(v14 + 80) = v28 - 1;
  }
  else
  {
    *(_BYTE *)(v14 + 80) = 0;
    *(_DWORD *)v14 = 3;
    *(_QWORD *)(v14 + 16) = 0i64;
    *(_QWORD *)(v14 + 48) = 0i64;
  }
  v3->m_FacingTargetAngle = 0.52359879;
  v3->m_CurrentAttack = 7;
  *(_QWORD *)&v3->m_fSteeringNoiseTimer = 0i64;
  v3->m_fSteeringNoiseAmplitudeMin = 0.0;
  UFG::qNoise<float,float>::SetParameters(
    &v3->m_SteeringNoise,
    UFG::AiDriverComponent::m_nSteeringNoiseOctaves,
    UFG::AiDriverComponent::m_fSteeringNoiseFrequency,
    UFG::AiDriverComponent::m_fSteeringNoiseOctaveDecay,
    -1.0,
    1.0);
  v3->m_DriverProfile = 0i64;
}

// File Line: 818
// RVA: 0x6439E0
void __fastcall UFG::AiDriverComponent::~AiDriverComponent(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // rbx
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *v2; // rdi
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *v3; // rcx
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *v4; // rax
  UFG::SensorPhantom *v5; // rcx
  hkpPhantom *v6; // rdx
  hkpSimpleShapePhantom *v7; // rcx
  hkpSphereShape *v8; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v19; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *v29; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *v34; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *v39; // rcx
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *v40; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AiDriverComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AiDriverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this->m_DriverProfile )
    this->m_DriverProfile = 0i64;
  if ( this == UFG::AiDriverComponent::s_AiDriverComponentpCurrentIterator )
    UFG::AiDriverComponent::s_AiDriverComponentpCurrentIterator = (UFG::AiDriverComponent *)&this->mPrev[-19];
  v2 = (UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->m_AvoidableSensor;
  if ( v5 )
    v5->vfptr->__vecDelDtor(v5, 1u);
  v6 = (hkpPhantom *)&v1->m_pCastingPhantom->vfptr;
  if ( v6->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, v6, 0i64);
  v7 = v1->m_pCastingPhantom;
  if ( v7 )
    v7->vfptr->__vecDelDtor((hkBaseObject *)&v7->vfptr, 1u);
  v8 = v1->m_pCastingSphere;
  if ( v8 )
    v8->vfptr->__vecDelDtor((hkBaseObject *)&v8->vfptr, 1u);
  v9 = &v1->m_PathingTarget;
  if ( v1->m_PathingTarget.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v1->m_PathingTarget.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v1->m_PathingTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_PathingTarget.mPrev;
  }
  v1->m_PathingTarget.m_pPointer = 0i64;
  v12 = v9->mPrev;
  v13 = v1->m_PathingTarget.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v1->m_PathingTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_PathingTarget.mPrev;
  v14 = &v1->m_CurrentAvoidable;
  if ( v1->m_CurrentAvoidable.m_pPointer )
  {
    v15 = v14->mPrev;
    v16 = v1->m_CurrentAvoidable.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
    v1->m_CurrentAvoidable.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_CurrentAvoidable.mPrev;
  }
  v1->m_CurrentAvoidable.m_pPointer = 0i64;
  v17 = v14->mPrev;
  v18 = v1->m_CurrentAvoidable.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v1->m_CurrentAvoidable.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_CurrentAvoidable.mPrev;
  operator delete[](v1->m_SteeringGasBrakeHistory.mRingBuffer.mData);
  UFG::qPidControllerCore::~qPidControllerCore(&v1->m_CatchupPid);
  v19 = &v1->m_CatchupTarget;
  if ( v1->m_CatchupTarget.m_pPointer )
  {
    v20 = v19->mPrev;
    v21 = v1->m_CatchupTarget.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
    v1->m_CatchupTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_CatchupTarget.mPrev;
  }
  v1->m_CatchupTarget.m_pPointer = 0i64;
  v22 = v19->mPrev;
  v23 = v1->m_CatchupTarget.mNext;
  v22->mNext = v23;
  v23->mPrev = v22;
  v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
  v1->m_CatchupTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_CatchupTarget.mPrev;
  UFG::qPidControllerCore::~qPidControllerCore(&v1->m_ThrottlePid);
  UFG::qPidControllerCore::~qPidControllerCore(&v1->m_SteeringPid);
  v24 = &v1->m_pEscortObjectiveVehicleSubject;
  if ( v1->m_pEscortObjectiveVehicleSubject.m_pPointer )
  {
    v25 = v24->mPrev;
    v26 = v1->m_pEscortObjectiveVehicleSubject.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    v1->m_pEscortObjectiveVehicleSubject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pEscortObjectiveVehicleSubject.mPrev;
  }
  v1->m_pEscortObjectiveVehicleSubject.m_pPointer = 0i64;
  v27 = v24->mPrev;
  v28 = v1->m_pEscortObjectiveVehicleSubject.mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
  v1->m_pEscortObjectiveVehicleSubject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pEscortObjectiveVehicleSubject.mPrev;
  v29 = &v1->m_pEscortEnemyVehicleSubject;
  if ( v1->m_pEscortEnemyVehicleSubject.m_pPointer )
  {
    v30 = v29->mPrev;
    v31 = v1->m_pEscortEnemyVehicleSubject.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    v29->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v29->mPrev;
    v1->m_pEscortEnemyVehicleSubject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pEscortEnemyVehicleSubject.mPrev;
  }
  v1->m_pEscortEnemyVehicleSubject.m_pPointer = 0i64;
  v32 = v29->mPrev;
  v33 = v1->m_pEscortEnemyVehicleSubject.mNext;
  v32->mNext = v33;
  v33->mPrev = v32;
  v29->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v29->mPrev;
  v1->m_pEscortEnemyVehicleSubject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pEscortEnemyVehicleSubject.mPrev;
  v34 = &v1->m_pChaseVehicleSubject;
  if ( v1->m_pChaseVehicleSubject.m_pPointer )
  {
    v35 = v34->mPrev;
    v36 = v1->m_pChaseVehicleSubject.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    v34->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v34->mPrev;
    v1->m_pChaseVehicleSubject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pChaseVehicleSubject.mPrev;
  }
  v1->m_pChaseVehicleSubject.m_pPointer = 0i64;
  v37 = v34->mPrev;
  v38 = v1->m_pChaseVehicleSubject.mNext;
  v37->mNext = v38;
  v38->mPrev = v37;
  v34->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v34->mPrev;
  v1->m_pChaseVehicleSubject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pChaseVehicleSubject.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pVehicleSubject);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pRoadSpace);
  v39 = v2->mPrev;
  v40 = v2->mNext;
  v39->mNext = v40;
  v40->mPrev = v39;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::VehicleDriverInterface::~VehicleDriverInterface((UFG::VehicleDriverInterface *)&v1->vfptr);
}

// File Line: 836
// RVA: 0x64DAB0
UFG::qPropertySet *__fastcall UFG::AiDriverComponent::GetDriverProfile(UFG::AiDriverComponent *this)
{
  return this->m_DriverProfile;
}

// File Line: 841
// RVA: 0x64DAC0
unsigned int *__fastcall UFG::AiDriverComponent::GetDriverProfileType(UFG::AiDriverComponent *this)
{
  UFG::qPropertySet *v1; // rcx
  unsigned int *result; // rax

  v1 = this->m_DriverProfile;
  if ( v1 )
    result = UFG::qPropertySet::Get<unsigned long>(v1, (UFG::qSymbol *)&qSymbol_DriverProfileType.mUID, DEPTH_RECURSE);
  else
    result = 0i64;
  return result;
}

// File Line: 859
// RVA: 0x651B70
bool __fastcall UFG::AiDriverComponent::IsInTrafficJam(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *v1; // rdi
  UFG::AiDriverComponent *v2; // rbp
  UFG::RoadNetworkGuide *v3; // rdi
  UFG::RoadNetworkLane *v5; // rcx
  UFG::RoadNetworkLane *v6; // rdx
  UFG::RoadNetworkGuide *v7; // rsi
  UFG::RoadNetworkLane *v8; // rbx
  UFG::SimObject *v9; // r8
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  bool v12; // zf
  UFG::SimObjectGame *v13; // rcx

  v1 = this->m_pRoadSpace.m_pSimComponent;
  v2 = this;
  if ( !v1 )
    return 0;
  v3 = (UFG::RoadNetworkGuide *)&v1[5].m_BoundComponentHandles.mNode.mNext;
  if ( !v3 )
    return 0;
  if ( !v3->m_Attached )
    return 0;
  v5 = v3->m_NextLane;
  if ( !v5 )
    return 0;
  v6 = v5->mNode.mOffset ? (UFG::RoadNetworkLane *)((char *)v5 + v5->mNode.mOffset) : 0i64;
  if ( LOWORD(v6->mNode.mOffset) != 1 || (unsigned int)UFG::RoadNetworkLane::GetStatus(v5) != 2 )
    return 0;
  v7 = v3->m_NextGuide.m_pPointer;
  if ( !v7 )
    return 0;
  v8 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v3->m_NextGuide.m_pPointer)->m_CurrentLane;
  if ( v8 != Scaleform::GFx::AS3::Instances::fl::XML::GetName(v3)->m_CurrentLane )
    return 0;
  v9 = v7->m_SimObj;
  if ( !v9 )
    return 0;
  v10 = v9->m_Flags;
  if ( (v10 >> 14) & 1 )
    return 0;
  if ( (v10 & 0x8000u) == 0 )
  {
    if ( (v10 >> 13) & 1 )
      return 0;
    v12 = ((v10 >> 12) & 1) == 0;
    v13 = (UFG::SimObjectGame *)v7->m_SimObj;
    if ( v12 )
      v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v11 = v9->m_Components.p[34].m_pComponent;
  }
  if ( v11 && *((float *)&v11[10].m_BoundComponentHandles.mNode.mPrev + 1) <= 0.0099999998 )
    return 0.0099999998 >= *((float *)&v2->mMoverComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1);
  return 0;
}

// File Line: 901
// RVA: 0x651A50
char __fastcall UFG::AiDriverComponent::IsBlockedByAvoidable(UFG::AiDriverComponent *this, int avoidableSet)
{
  int v2; // ebx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rcx
  UFG::SimComponent *v6; // rax

  v2 = avoidableSet;
  if ( !this->m_BlockedByAvoidable )
    return 0;
  v3 = (UFG::SimObjectGame *)this->m_CurrentAvoidable.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[37].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CameraSubject::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CameraSubject::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CameraSubject::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[31].m_pComponent;
  }
  if ( !v5 )
    return 0;
  if ( v2 == 1 )
  {
    if ( ((unsigned __int8 (*)(void))v5->vfptr[30].__vecDelDtor)() )
      return 0;
  }
  else if ( v2 )
  {
    return 0;
  }
  return 1;
}

// File Line: 934
// RVA: 0x658C90
void __fastcall UFG::AiDriverComponent::SetDrivingRole(UFG::AiDriverComponent *this, unsigned int role)
{
  bool v2; // al

  if ( this->m_DrivingRole != role )
  {
    this->m_DrivingRole = role;
    switch ( role )
    {
      case 1u:
        if ( this->m_RoadRuleFlagsLocked )
          goto LABEL_20;
        this->m_bAvoidPeds = 0;
        this->m_fAvoidStopTimer = 0.0;
        this->m_bAllowedToPass = 1;
        this->m_bStayOffSidewalk = 0;
        this->m_bRespectSpeedLimit = 0;
        this->m_bCanTurnAround = 0;
        this->m_bSavedAvoidPeds = 0;
        return;
      case 2u:
        if ( this->m_RoadRuleFlagsLocked )
          goto LABEL_20;
        this->m_bAvoidPeds = 0;
        this->m_fAvoidStopTimer = 0.0;
        goto LABEL_7;
      case 3u:
      case 5u:
        if ( this->m_RoadRuleFlagsLocked )
          goto LABEL_20;
        this->m_bAvoidPeds = 1;
LABEL_7:
        v2 = this->m_bAvoidPeds;
        this->m_bAllowedToPass = 1;
        this->m_bStayOffSidewalk = 1;
        this->m_bRespectSpeedLimit = 0;
        this->m_bCanTurnAround = 1;
        this->m_bSavedAvoidPeds = v2;
        return;
      case 4u:
        if ( this->m_RoadRuleFlagsLocked )
          goto LABEL_20;
        this->m_bAllowedToPass = 1;
        goto LABEL_18;
      case 7u:
        if ( this->m_RoadRuleFlagsLocked )
          goto LABEL_20;
        this->m_bAvoidPeds = 0;
        this->m_fAvoidStopTimer = 0.0;
        this->m_bAllowedToPass = 0;
        this->m_bStayOffSidewalk = 0;
        goto LABEL_19;
      case 9u:
        if ( this->m_RoadRuleFlagsLocked )
          goto LABEL_20;
        this->m_bAvoidPeds = 0;
        this->m_fAvoidStopTimer = 0.0;
        this->m_bAllowedToPass = 1;
        this->m_bStayOffSidewalk = 0;
        goto LABEL_19;
      default:
        if ( !this->m_RoadRuleFlagsLocked )
        {
          this->m_bAllowedToPass = 0;
LABEL_18:
          this->m_bAvoidPeds = 1;
          this->m_bStayOffSidewalk = 1;
LABEL_19:
          this->m_bRespectSpeedLimit = 1;
          this->m_bCanTurnAround = 0;
        }
LABEL_20:
        this->m_bSavedAvoidPeds = this->m_bAvoidPeds;
        break;
    }
  }
}

// File Line: 1020
// RVA: 0x658B90
void __fastcall UFG::AiDriverComponent::SetDrivingMode(UFG::AiDriverComponent *this, unsigned int mode)
{
  UFG::RoadSpaceComponent *v2; // rax

  if ( this->m_DrivingMode != mode )
  {
    this->m_DrivingMode = mode;
    this->m_fReactionTime = 0.0;
    this->m_fDelayedStopDecel = 0.0;
    this->mModeSteeringLockEnabled = 0;
    this->mModeGasBrakeLockEnabled = 0;
    this->m_bIgnoreArrivalDirection = 0;
    switch ( 0x40000000 )
    {
      case 0:
        if ( this->m_ResetStopDistOnStop )
          this->m_StopDist = 1.0;
        break;
      case 1:
      case 6:
        return;
      case 2:
        v2 = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
        if ( !v2
          || (float)((float)((float)(v2->mDestinationDirection.x * v2->mDestinationDirection.x)
                           + (float)(v2->mDestinationDirection.y * v2->mDestinationDirection.y))
                   + (float)(v2->mDestinationDirection.z * v2->mDestinationDirection.z)) < 0.0000010000001 )
        {
          goto $LN7_67;
        }
        break;
      case 3:
        this->m_bIgnoreArrivalDirection = 1;
        goto $LN2_63;
      case 4:
$LN7_67:
        this->m_bIgnoreArrivalDirection = 1;
        break;
      case 5:
        UFG::AiDriverComponent::SetupStopAt(this);
        break;
      case 7:
$LN2_63:
        UFG::VehicleCombatStats::Reset(&this->m_CombatStats);
        break;
      default:
        UFG::AiDriverComponent::SetChaseTarget(this, 0i64);
        break;
    }
  }
}

// File Line: 1090
// RVA: 0x659B10
void __fastcall UFG::AiDriverComponent::SetupStopAt(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // rbx
  bool v2; // zf

  v1 = this;
  if ( this->m_StopInfo.eStopStyle == 1 )
    UFG::VehicleDriverInterface::SetDesiredState((UFG::VehicleDriverInterface *)&this->vfptr, (UFG::VehicleState)3);
  if ( v1->m_DrivingRole - 6 <= 2 )
  {
    v2 = v1->m_RoadRuleFlagsLocked == 0;
    v1->m_bSavedAvoidPeds = v1->m_bAvoidPeds;
    if ( v2 )
    {
      v1->m_bAvoidPeds = 0;
      v1->m_fAvoidStopTimer = 0.0;
    }
  }
}

// File Line: 1105
// RVA: 0x6587A0
void __fastcall UFG::AiDriverComponent::SetChaseTarget(UFG::AiDriverComponent *this, UFG::SimObject *target)
{
  UFG::AiDriverComponent *v2; // rdi
  UFG::RoadSpaceComponent *v3; // rcx
  UFG::SimObjectVehicle *v4; // rbx
  UFG::SimComponent *v5; // rax
  UFG::VehicleSubjectComponent *v6; // r8
  unsigned __int16 v7; // cx
  UFG::VehicleSubjectComponent *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax

  v2 = this;
  v3 = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
  v4 = (UFG::SimObjectVehicle *)target;
  if ( v3 )
    UFG::RoadSpaceComponent::SetChaseTarget(v3, target);
  v5 = v2->m_pChaseVehicleSubject.m_pPointer;
  if ( !v5 || (UFG::SimObjectVehicle *)v5->m_pSimObject != v4 )
  {
    if ( v4 )
    {
      v7 = v4->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v4->vfptr,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::VehicleSubjectComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::VehicleSubjectComponent::_TypeUID);
        }
        else
        {
          v8 = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v4->vfptr,
                                                 UFG::VehicleSubjectComponent::_TypeUID);
        }
      }
      else
      {
        v8 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v4);
      }
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    v9 = &v2->m_pChaseVehicleSubject;
    if ( v2->m_pChaseVehicleSubject.m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v2->m_pChaseVehicleSubject.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v2->m_pChaseVehicleSubject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pChaseVehicleSubject.mPrev;
    }
    v2->m_pChaseVehicleSubject.m_pPointer = (UFG::SimComponent *)&v6->vfptr;
    if ( v6 )
    {
      v12 = v6->m_SafePointerList.mNode.mPrev;
      v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v9->mPrev = v12;
      v2->m_pChaseVehicleSubject.mNext = &v6->m_SafePointerList.mNode;
      v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    }
    v2->m_fReactionTime = 0.0;
  }
}

// File Line: 1117
// RVA: 0x659040
void __fastcall UFG::AiDriverComponent::SetEscortEnemy(UFG::AiDriverComponent *this, UFG::SimObject *enemy)
{
  UFG::SimObject *v2; // r8
  UFG::AiDriverComponent *v3; // rbx
  unsigned __int16 v4; // cx
  UFG::VehicleSubjectComponent *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = enemy;
  v3 = this;
  if ( enemy )
  {
    v4 = enemy->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)enemy,
                                             UFG::VehicleSubjectComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)enemy,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)enemy,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                               enemy,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>((UFG::SimObjectVehicle *)enemy);
    }
    v2 = (UFG::SimObject *)v5;
  }
  v6 = &v3->m_pEscortEnemyVehicleSubject;
  if ( v3->m_pEscortEnemyVehicleSubject.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v3->m_pEscortEnemyVehicleSubject.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v3->m_pEscortEnemyVehicleSubject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pEscortEnemyVehicleSubject.mPrev;
  }
  v3->m_pEscortEnemyVehicleSubject.m_pPointer = (UFG::SimComponent *)v2;
  v3->m_fReactionTime = 0.0;
  if ( v2 )
  {
    v9 = v2->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v6;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v9;
    v3->m_pEscortEnemyVehicleSubject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_SafePointerList;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v6;
  }
}

// File Line: 1123
// RVA: 0x64E740
UFG::SimObject *__fastcall UFG::AiDriverComponent::GetEscortEnemy(UFG::AiDriverComponent *this)
{
  UFG::SimObject *result; // rax

  result = (UFG::SimObject *)this->m_pEscortEnemyVehicleSubject.m_pPointer;
  if ( result )
    result = (UFG::SimObject *)result->mNode.mParent;
  return result;
}

// File Line: 1132
// RVA: 0x659110
void __fastcall UFG::AiDriverComponent::SetEscortObjective(UFG::AiDriverComponent *this, UFG::SimObject *enemy)
{
  UFG::SimObject *v2; // r8
  UFG::AiDriverComponent *v3; // rbx
  unsigned __int16 v4; // cx
  UFG::VehicleSubjectComponent *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = enemy;
  v3 = this;
  if ( enemy )
  {
    v4 = enemy->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)enemy,
                                             UFG::VehicleSubjectComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)enemy,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)enemy,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                               enemy,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>((UFG::SimObjectVehicle *)enemy);
    }
    v2 = (UFG::SimObject *)v5;
  }
  v6 = &v3->m_pEscortObjectiveVehicleSubject;
  if ( v3->m_pEscortObjectiveVehicleSubject.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v3->m_pEscortObjectiveVehicleSubject.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v3->m_pEscortObjectiveVehicleSubject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pEscortObjectiveVehicleSubject.mPrev;
  }
  v3->m_pEscortObjectiveVehicleSubject.m_pPointer = (UFG::SimComponent *)v2;
  v3->m_fReactionTime = 0.0;
  if ( v2 )
  {
    v9 = v2->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v6;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v9;
    v3->m_pEscortObjectiveVehicleSubject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_SafePointerList;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v6;
  }
}

// File Line: 1145
// RVA: 0x662000
void __fastcall UFG::AiDriverComponent::UpdateEscortOffset(UFG::AiDriverComponent *this, float seconds)
{
  UFG::AiDriverComponent *v2; // rdi
  UFG::SimComponent *v3; // rcx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::RoadSpaceComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  UFG::qVector3 *v8; // rax
  UFG::qVector3 *v9; // rax
  __m128 v10; // xmm4
  float v11; // xmm2_4
  __m128 v12; // xmm3
  float v13; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  v2 = this;
  if ( this->m_EscortInfo.eEscortMode == 1 && !this->m_bCreepingTowardEscortEnemy )
  {
    v3 = this->m_pChaseVehicleSubject.m_pPointer;
    if ( v3 )
    {
      if ( v2->m_pEscortEnemyVehicleSubject.m_pPointer )
      {
        v4 = (UFG::SimObjectGame *)v3->m_pSimObject;
        if ( v4 )
        {
          v5 = v4->m_Flags;
          if ( (v5 >> 14) & 1 )
          {
            v6 = (UFG::RoadSpaceComponent *)v4->m_Components.p[24].m_pComponent;
          }
          else if ( (v5 & 0x8000u) == 0 )
          {
            if ( (v5 >> 13) & 1 )
            {
              v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RoadSpaceComponent::_TypeUID);
            }
            else if ( (v5 >> 12) & 1 )
            {
              v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RoadSpaceComponent::_TypeUID);
            }
            else
            {
              v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::RoadSpaceComponent::_TypeUID);
            }
            v6 = (UFG::RoadSpaceComponent *)v7;
          }
          else
          {
            v6 = (UFG::RoadSpaceComponent *)v4->m_Components.p[24].m_pComponent;
          }
          if ( v6 )
          {
            v8 = (UFG::qVector3 *)((__int64 (*)(void))v2->m_pEscortEnemyVehicleSubject.m_pPointer->vfptr[17].__vecDelDtor)();
            v9 = UFG::RoadSpaceComponent::WorldToChase(v6, &result, v8);
            v10 = (__m128)LODWORD(v9->x);
            v11 = v9->y;
            v12 = v10;
            v12.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v11 * v11))
                            + (float)(v9->z * v9->z);
            LODWORD(v13) = (unsigned __int128)_mm_sqrt_ps(v12);
            UFG::AiDriverComponent::SetFollowOffset(
              v2,
              (float)(v10.m128_f32[0] * (float)(8.0 / v13)) * 0.5,
              v11 * (float)(8.0 / v13),
              2.0);
          }
        }
      }
    }
  }
}

// File Line: 1170
// RVA: 0x661D50
void __fastcall UFG::AiDriverComponent::UpdateEscortMode(UFG::AiDriverComponent *this, float seconds)
{
  UFG::SimObject *v2; // rsi
  UFG::AiDriverComponent *v3; // rbx
  UFG::SimObjectGame *v4; // rdi
  CarAI::EEscortMode v5; // ecx
  float v6; // xmm7_4
  float v7; // xmm0_4
  unsigned __int16 v8; // cx
  UFG::RoadSpaceComponent *v9; // rax
  float v10; // xmm8_4
  float v11; // xmm6_4
  float v12; // xmm9_4
  float v13; // xmm10_4
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  __m128 v17; // xmm7
  __m128 v18; // xmm3
  float v19; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-98h]
  UFG::qVector3 v21; // [rsp+30h] [rbp-88h]
  UFG::qVector3 v22; // [rsp+40h] [rbp-78h]
  UFG::qVector3 v23; // [rsp+50h] [rbp-68h]

  v2 = (UFG::SimObject *)this->m_pEscortEnemyVehicleSubject.m_pPointer;
  v3 = this;
  if ( v2 )
    v2 = (UFG::SimObject *)v2->mNode.mParent;
  UFG::GetPosition(&result, v2);
  v4 = (UFG::SimObjectGame *)v3->m_pEscortObjectiveVehicleSubject.m_pPointer;
  if ( v4 )
    v4 = (UFG::SimObjectGame *)v4->mNode.mParent;
  UFG::GetPosition(&v21, (UFG::SimObject *)&v4->vfptr);
  UFG::GetPosition(&v22, v3->m_pSimObject);
  v5 = v3->m_EscortInfo.eEscortMode;
  v3->m_bCreepingTowardEscortEnemy = 0;
  v6 = (float)((float)((float)(v22.y - result.y) * (float)(v22.y - result.y))
             + (float)((float)(v22.x - result.x) * (float)(v22.x - result.x)))
     + (float)((float)(v22.z - result.z) * (float)(v22.z - result.z));
  if ( v5 == 1 )
  {
    if ( v6 >= 100.0 )
    {
      v7 = v3->m_EscortInfo.fDistanceSqrEnemyToObjectiveEnterAttackMode;
      if ( (float)((float)((float)((float)(v21.y - result.y) * (float)(v21.y - result.y))
                         + (float)((float)(v21.x - result.x) * (float)(v21.x - result.x)))
                 + (float)((float)(v21.z - result.z) * (float)(v21.z - result.z))) <= v7
        || v6 <= v7 )
      {
        if ( v4 )
        {
          v8 = v4->m_Flags;
          if ( (v8 >> 14) & 1 )
          {
            v9 = (UFG::RoadSpaceComponent *)v4->m_Components.p[24].m_pComponent;
          }
          else if ( (v8 & 0x8000u) == 0 )
          {
            if ( (v8 >> 13) & 1 )
              v9 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v4,
                                                UFG::RoadSpaceComponent::_TypeUID);
            else
              v9 = (UFG::RoadSpaceComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v4,
                                                                  UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::RoadSpaceComponent::_TypeUID));
          }
          else
          {
            v9 = (UFG::RoadSpaceComponent *)v4->m_Components.p[24].m_pComponent;
          }
          if ( v9 )
          {
            v10 = seconds * 10.0;
            v11 = v3->m_vFollowOffsetDesired.z;
            v12 = v3->m_vFollowOffsetDesired.x;
            v13 = v3->m_vFollowOffsetDesired.y;
            UFG::RoadSpaceComponent::WorldToChase(v9, &v23, &result);
            v14 = v23.x;
            v15 = v23.y;
            v17 = (__m128)LODWORD(v23.y);
            v16 = v23.x - v12;
            v17.m128_f32[0] = v23.y - v13;
            v18 = v17;
            v18.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16))
                            + (float)((float)(v23.z - v11) * (float)(v23.z - v11));
            if ( v18.m128_f32[0] > (float)(v10 * v10) )
            {
              LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v18);
              v15 = (float)((float)(v10 / v19) * v17.m128_f32[0]) + v13;
              v14 = (float)((float)(v10 / v19) * v16) + v12;
            }
            UFG::AiDriverComponent::SetFollowOffset(v3, v14, v15, 5.0);
            v3->m_bCreepingTowardEscortEnemy = 1;
          }
        }
      }
    }
    else
    {
      v3->m_EscortInfo.eEscortMode = 0;
      UFG::VehicleCombatStats::Reset(&v3->m_CombatStats);
      UFG::AiDriverComponent::SetChaseTarget(v3, v2);
    }
  }
}

// File Line: 1485
// RVA: 0x665EB0
char __fastcall UFG::AiDriverComponent::WarpToDestination(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // r14
  float v2; // xmm2_4
  float v3; // xmm1_4
  UFG::RoadNetworkSegment *v5; // rdi
  UFG::RoadNetworkSubSegment *v6; // rsi
  UFG::RoadNetworkSubSegment *v7; // rbx
  bool v8; // al
  unsigned int v9; // edx
  float v10; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  UFG::WheeledVehicleManager *v13; // rbx
  UFG::RoadNetworkLane *v14; // rax
  UFG::RoadSpaceComponent *v15; // rbx
  UFG::RoadNetworkLocation *v16; // rax
  UFG::qVector3 v17; // [rsp+30h] [rbp-19h]
  UFG::qVector3 pos; // [rsp+40h] [rbp-9h]
  UFG::qVector3 v19; // [rsp+50h] [rbp+7h]
  UFG::qVector3 result; // [rsp+60h] [rbp+17h]
  float nearestT; // [rsp+B0h] [rbp+67h]
  UFG::RoadNetworkLane *nearestLane; // [rsp+B8h] [rbp+6Fh]

  v1 = this;
  this->m_fAvoidStopTimer = 0.0;
  v2 = *((float *)&this->m_pRoadSpace.m_pSimComponent[25].m_BoundComponentHandles.mNode.mPrev + 1);
  v3 = *(float *)&this->m_pRoadSpace.m_pSimComponent[25].m_BoundComponentHandles.mNode.mNext;
  pos.x = *(float *)&this->m_pRoadSpace.m_pSimComponent[25].m_BoundComponentHandles.mNode.mPrev;
  pos.y = v2;
  pos.z = v3;
  if ( pos.x == UFG::qVector3::msZero.x && v2 == UFG::qVector3::msZero.y && v3 == UFG::qVector3::msZero.z )
    return 0;
  v5 = UFG::RoadNetworkResource::GetClosestSegment(UFG::gpRoadNetworkResource, &pos, 0i64, 0);
  nearestLane = 0i64;
  nearestT = 0.0;
  UFG::RoadNetworkNode::GetNearestPos((UFG::RoadNetworkNode *)&v5->mType, &result, &pos, &nearestLane, &nearestT);
  v6 = UFG::RoadNetworkSegment::GetClosestSubSegment(v5, &pos);
  if ( UFG::RoadNetworkLane::IsReversedInNode(nearestLane) )
    v7 = (UFG::RoadNetworkSubSegment *)v6->mNext;
  else
    v7 = (UFG::RoadNetworkSubSegment *)v6->mPrev;
  if ( !v7 || v7 == (UFG::RoadNetworkSubSegment *)&v5->mSubSegmentCollection )
    v7 = v6;
  v8 = UFG::RoadNetworkLane::IsReversedInNode(nearestLane);
  v9 = nearestLane->mLaneIndex;
  if ( v8 )
    v10 = UFG::RoadNetworkSubSegment::GetEndT(v7, v9);
  else
    v10 = UFG::RoadNetworkSubSegment::GetBeginT(v7, v9);
  v11 = v10;
  if ( v10 == 0.0 )
  {
    v12 = UFG::RoadNetworkSegment::GetTFromDistance(v5, nearestLane, 2.5, 0.0, 1);
LABEL_18:
    v11 = v12;
    goto LABEL_19;
  }
  if ( v10 == 1.0 )
  {
    v12 = UFG::RoadNetworkSegment::GetTFromDistance(v5, nearestLane, 2.5, v10, 0);
    goto LABEL_18;
  }
LABEL_19:
  UFG::RoadNetworkLane::GetPos(nearestLane, &v17, v11);
  v13 = UFG::WheeledVehicleManager::m_Instance;
  v19 = v17;
  UFG::WheeledVehicleManager::DestroyTrafficVehiclesInRange(UFG::WheeledVehicleManager::m_Instance, &v19, 25.0);
  v19 = v17;
  UFG::WheeledVehicleManager::DestroyParkedVehiclesInRange(v13, &v19, 25.0);
  v14 = nearestLane;
  v1->m_IsAmbient = 0;
  UFG::RoadNetworkGuide::AttachToNetwork(
    (UFG::RoadNetworkGuide *)&v1->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext,
    v1->m_pRoadSpace.m_pSimComponent->m_pSimObject,
    (UFG::RoadNetworkNode *)&v5->mType,
    v14->mLaneIndex,
    v11);
  UFG::RoadNetworkGuide::RemoveFromNetwork((UFG::RoadNetworkGuide *)&v1->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext);
  v15 = (UFG::RoadSpaceComponent *)v1->m_pRoadSpace.m_pSimComponent;
  v16 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(&v15->mGuide);
  UFG::RoadSpaceComponent::MoveCarToRoadNetworkPosition(v15, v16, 0);
  return 1;
}

// File Line: 1565
// RVA: 0x666130
void __fastcall UFG::AiDriverComponent::WarpToGotoDestination(UFG::AiDriverComponent *this)
{
  float *v1; // r15
  UFG::qVector3 *v2; // r14
  UFG::AiDriverComponent *v3; // rbp
  UFG::VehicleWayFinderClient *v4; // r15
  UFG::SimComponent *v5; // r12
  UFG::WheeledVehicleNavigationData *v6; // rsi
  unsigned int v7; // eax
  UFG::WayFinderClientVtbl *v8; // rdi
  __int64 v9; // rbx
  __int64 v10; // rax
  UFG::WayFinder *v11; // rbx
  unsigned int v12; // er13
  UFG::SimComponent *v13; // r12
  __int64 v14; // rbx
  UFG::RoadNetworkSegment *v15; // rdi
  UFG::RoadNetworkSubSegment *v16; // r14
  UFG::RoadNetworkLane *v17; // rsi
  UFG::RoadNetworkSubSegment *v18; // rbx
  bool v19; // al
  unsigned int v20; // edx
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  UFG::RoadSpaceComponent *v24; // rbx
  UFG::RoadNetworkLocation *v25; // rax

  this->m_fAvoidStopTimer = 0.0;
  v1 = (float *)this->m_pRoadSpace.m_pSimComponent;
  v2 = (UFG::qVector3 *)(v1 + 412);
  v3 = this;
  if ( UFG::qVector3::msZero.x != v1[412] || UFG::qVector3::msZero.y != v1[413] || UFG::qVector3::msZero.z != v1[414] )
  {
    v4 = (UFG::VehicleWayFinderClient *)(v1 + 138);
    if ( v4 )
    {
      v5 = this->m_pVehicleSubject.m_pSimComponent;
      if ( v5 )
      {
        v6 = UFG::WheeledVehicleManager::m_Instance->m_NavigationData;
        v7 = v4->m_RoadNetworkType;
        if ( v7 )
        {
          switch ( v7 )
          {
            case 1u:
              v6 = (UFG::WheeledVehicleNavigationData *)((char *)v6 + 64);
              break;
            case 2u:
              v6 = (UFG::WheeledVehicleNavigationData *)((char *)v6 + 96);
              break;
            case 3u:
              v6 = (UFG::WheeledVehicleNavigationData *)((char *)v6 + 128);
              break;
          }
        }
        else
        {
          v6 = (UFG::WheeledVehicleNavigationData *)((char *)v6 + 32);
        }
        if ( v6 )
        {
          v8 = v4->vfptr;
          v9 = ((__int64 (__fastcall *)(UFG::SimComponent *))v5->vfptr[16].__vecDelDtor)(v5);
          v10 = ((__int64 (__fastcall *)(UFG::SimComponent *))v5->vfptr[17].__vecDelDtor)(v5);
          v8->SetPosition(
            (UFG::WayFinderClient *)&v4->vfptr,
            (UFG::WayGraph *)&v6->m_RoadNetworkGraph.vfptr,
            (UFG::qVector3 *)v10,
            (UFG::qVector3 *)v9);
          v11 = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
                  UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                  v4);
          UFG::WayFinder::FindWay(v11, (UFG::WayFinderClient *)&v4->vfptr, v2, 0i64);
          UFG::WayFinder::Service(v11, 0.0);
          v12 = v4->m_NumWayEdges;
          if ( v4->m_NumWayEdges )
          {
            v13 = v3->m_pRoadSpace.m_pSimComponent;
            v14 = v12 - 1;
            v15 = UFG::RoadNetworkResource::GetSegment(UFG::gpRoadNetworkResource, v4->m_WayEdges[v14]);
            v16 = UFG::RoadNetworkSegment::GetClosestSubSegment(v15, v2);
            v17 = UFG::AiDriverComponent::GetLaneAtEdgeNum(v3, v14);
            if ( UFG::RoadNetworkLane::IsReversedInNode(v17) )
              v18 = (UFG::RoadNetworkSubSegment *)v16->mNext;
            else
              v18 = (UFG::RoadNetworkSubSegment *)v16->mPrev;
            if ( &v15->mSubSegmentCollection == (UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *)v18 )
            {
              if ( v12 < 2 )
                return;
              v15 = UFG::RoadNetworkResource::GetSegment(UFG::gpRoadNetworkResource, v4->m_WayEdges[v12 - 2]);
              if ( UFG::RoadNetworkLane::IsReversedInNode(v17) )
                v18 = (UFG::RoadNetworkSubSegment *)v15->mSubSegmentCollection.mNode.mNext;
              else
                v18 = (UFG::RoadNetworkSubSegment *)v15->mSubSegmentCollection.mNode.mPrev;
            }
            UFG::WheeledVehicleManager::DestroyTrafficVehiclesOnSubSegment(
              UFG::WheeledVehicleManager::m_Instance,
              v18,
              1,
              v17);
            UFG::WheeledVehicleManager::DestroyParkedCarsOnSubSegment(UFG::WheeledVehicleManager::m_Instance, v18);
            v19 = UFG::RoadNetworkLane::IsReversedInNode(v17);
            v20 = v17->mLaneIndex;
            if ( v19 )
            {
              v21 = UFG::RoadNetworkSubSegment::GetEndT(v18, v20);
              v22 = UFG::RoadNetworkSegment::GetTFromDistance(v15, v17, 3.0, v21, 0);
            }
            else
            {
              v23 = UFG::RoadNetworkSubSegment::GetBeginT(v18, v20);
              v22 = UFG::RoadNetworkSegment::GetTFromDistance(v15, v17, 3.0, v23, 1);
            }
            v3->m_IsAmbient = 0;
            UFG::RoadNetworkGuide::AttachToNetwork(
              (UFG::RoadNetworkGuide *)&v3->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext,
              v3->m_pRoadSpace.m_pSimComponent->m_pSimObject,
              (UFG::RoadNetworkNode *)&v15->mType,
              v17->mLaneIndex,
              v22);
            UFG::RoadNetworkGuide::RemoveFromNetwork((UFG::RoadNetworkGuide *)&v3->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext);
            v24 = (UFG::RoadSpaceComponent *)v3->m_pRoadSpace.m_pSimComponent;
            v25 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v13[5].m_BoundComponentHandles.mNode.mNext);
            UFG::RoadSpaceComponent::MoveCarToRoadNetworkPosition(v24, v25, 0);
          }
        }
      }
    }
  }
}

// File Line: 1676
// RVA: 0x64C030
void __fastcall UFG::AiDriverComponent::EmergencyFixupForGround(UFG::AiDriverComponent *this, UFG::qMatrix44 *local_world)
{
  UFG::qMatrix44 *v2; // rdi
  UFG::SimComponent *v3; // rcx
  UFG::RoadNetworkLocation *v4; // rbx
  float v5; // xmm7_4
  float v6; // xmm8_4
  float v7; // xmm11_4
  float v8; // xmm2_4
  float v9; // xmm12_4
  float v10; // xmm9_4
  float v11; // xmm3_4
  __m128 v12; // xmm4
  float v13; // xmm5_4
  __m128 v14; // xmm6
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rbx
  UFG::RacePoint *v19; // rbx
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm8_4
  float v23; // xmm9_4
  float v24; // xmm4_4
  __m128 v25; // xmm5
  float v26; // xmm3_4
  float v27; // xmm2_4
  __m128 v28; // xmm6
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  UFG::SimObjectGame *v34; // rcx
  UFG::SimComponent *v35; // rbp
  unsigned __int16 v36; // dx
  UFG::SimComponent *v37; // rax
  int v38; // er15
  float v39; // xmm13_4
  float v40; // xmm14_4
  float v41; // xmm15_4
  float v42; // xmm6_4
  int v43; // ebx
  float *v44; // r14
  float v45; // xmm8_4
  float v46; // xmm7_4
  int v47; // eax
  int v48; // ecx
  int v49; // eax
  float *v50; // rcx
  float v51; // xmm9_4
  float v52; // xmm10_4
  float v53; // xmm11_4
  float v54; // xmm12_4
  float v55; // xmm4_4
  float v56; // xmm5_4
  float v57; // xmm2_4
  float v58; // xmm2_4
  float v59; // xmm1_4
  float v60; // xmm11_4
  float v61; // xmm12_4
  float v62; // xmm7_4
  float v63; // xmm9_4
  float v64; // xmm10_4
  float v65; // xmm4_4
  float v66; // xmm3_4
  __m128 v67; // xmm5
  __m128 v68; // xmm2
  float v69; // xmm1_4
  float v70; // xmm2_4
  UFG::qVector3 v71; // [rsp+20h] [rbp-D8h]
  UFG::qVector3 result; // [rsp+30h] [rbp-C8h]

  v2 = local_world;
  if ( this->m_pRoadSpace.m_pSimComponent )
  {
    v3 = this->m_pRoadSpace.m_pSimComponent;
    if ( LOBYTE(v3[8].m_Flags) )
    {
      v4 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v3[5].m_BoundComponentHandles.mNode.mNext);
      UFG::RoadNetworkLocation::GetPos(v4, &result);
      UFG::RoadNetworkLocation::GetTangent(v4, &v71);
      v5 = v71.z;
      v6 = v71.y;
      v7 = UFG::qVector3::msAxisZ.y;
      v8 = 0.0;
      v9 = UFG::qVector3::msAxisZ.z;
      v10 = v71.x;
      v12 = (__m128)LODWORD(v71.x);
      v11 = (float)(v71.z * UFG::qVector3::msAxisZ.y) - (float)(v71.y * UFG::qVector3::msAxisZ.z);
      v12.m128_f32[0] = (float)(v71.x * UFG::qVector3::msAxisZ.z) - (float)(v71.z * UFG::qVector3::msAxisZ.x);
      v14 = v12;
      v13 = (float)(v71.y * UFG::qVector3::msAxisZ.x) - (float)(v71.x * UFG::qVector3::msAxisZ.y);
      v14.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
      if ( v14.m128_f32[0] != 0.0 )
        v8 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
      v15 = result.x;
      v16 = result.y;
      v2->v2.x = UFG::qVector3::msAxisZ.x;
      v2->v2.w = 0.0;
      v2->v2.y = v7;
      v2->v2.z = v9;
      v2->v1.x = v11 * v8;
      v2->v1.w = 0.0;
      v2->v1.y = v12.m128_f32[0] * v8;
      v2->v1.z = v13 * v8;
      v2->v0.x = v10;
      v2->v0.w = 0.0;
      v2->v0.y = v6;
      v2->v0.z = v5;
      v2->v3.x = v15;
      v2->v3.w = 1.0;
      v17 = result.z;
      v2->v3.y = v16;
      v2->v3.z = v17;
    }
    else
    {
      v18 = v3[26].m_SafePointerList.mNode.mNext;
      if ( !v18 )
        v18 = v3[26].m_SafePointerList.mNode.mPrev;
      if ( v18 )
        v19 = (UFG::RacePoint *)v18[1].mNext;
      else
        v19 = 0i64;
      if ( v19 )
      {
        v20 = local_world->v3.y;
        result.x = local_world->v3.x;
        v21 = local_world->v3.z;
        result.y = v20;
        result.z = v21;
        UFG::RacePoint::GetSegmentPosition(v19, &v71, &result);
        v22 = UFG::qVector3::msAxisZ.y;
        v23 = UFG::qVector3::msAxisZ.z;
        v25 = (__m128)LODWORD(v19->vDirection.x);
        v24 = (float)(v19->vDirection.z * UFG::qVector3::msAxisZ.y)
            - (float)(v19->vDirection.y * UFG::qVector3::msAxisZ.z);
        v25.m128_f32[0] = (float)(v25.m128_f32[0] * UFG::qVector3::msAxisZ.z)
                        - (float)(v19->vDirection.z * UFG::qVector3::msAxisZ.x);
        v26 = (float)(v19->vDirection.y * UFG::qVector3::msAxisZ.x)
            - (float)(v19->vDirection.x * UFG::qVector3::msAxisZ.y);
        v27 = 0.0;
        v28 = v25;
        v28.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24)) + (float)(v26 * v26);
        if ( v28.m128_f32[0] != 0.0 )
          v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v28));
        v2->v2.x = UFG::qVector3::msAxisZ.x;
        v2->v2.y = v22;
        v2->v2.z = v23;
        v2->v2.w = 0.0;
        v2->v1.w = 0.0;
        v2->v1.x = v24 * v27;
        v2->v1.y = v25.m128_f32[0] * v27;
        v2->v1.z = v26 * v27;
        v29 = v19->vDirection.y;
        v30 = v19->vDirection.z;
        v2->v0.x = v19->vDirection.x;
        v2->v0.w = 0.0;
        v31 = v71.x;
        v2->v0.y = v29;
        v32 = v71.y;
        v2->v0.z = v30;
        v2->v3.x = v31;
        v33 = v71.z;
        v2->v3.w = 1.0;
        v2->v3.z = v33;
        v2->v3.y = v32;
      }
      else
      {
        v34 = (UFG::SimObjectGame *)v3[26].m_pSimObject;
        if ( v34 )
        {
          v36 = v34->m_Flags;
          if ( (v36 >> 14) & 1 )
          {
            v35 = v34->m_Components.p[24].m_pComponent;
          }
          else if ( (v36 & 0x8000u) == 0 )
          {
            if ( (v36 >> 13) & 1 )
            {
              v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v34, UFG::RoadSpaceComponent::_TypeUID);
            }
            else if ( (v36 >> 12) & 1 )
            {
              v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v34, UFG::RoadSpaceComponent::_TypeUID);
            }
            else
            {
              v37 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v34->vfptr, UFG::RoadSpaceComponent::_TypeUID);
            }
            v35 = v37;
          }
          else
          {
            v35 = v34->m_Components.p[24].m_pComponent;
          }
        }
        else
        {
          v35 = 0i64;
        }
        if ( v35 )
        {
          v38 = HIDWORD(v35[29].m_BoundComponentHandles.mNode.mNext);
          v39 = v2->v3.x;
          v40 = v2->v3.y;
          v41 = v2->v3.z;
          if ( v38 > 0 )
          {
            v42 = 0.0;
            v43 = 0;
            v44 = 0i64;
            v45 = 0.0;
            v46 = 0.0;
            do
            {
              v47 = HIDWORD(v35[29].m_BoundComponentHandles.mNode.mNext);
              v48 = 0;
              if ( v43 > 0 )
                v48 = v43;
              if ( v48 < v47 )
                v47 = v48;
              v49 = UFG::qSignedMod(LODWORD(v35[29].m_BoundComponentHandles.mNode.mNext) - v47, (int)v35[30].vfptr);
              v50 = (float *)&v35[30].m_SafePointerList.mNode.mPrev[2 * v49];
              v52 = v50[1];
              v53 = v50[2];
              v54 = v50[5];
              v55 = v50[4];
              v56 = v50[6];
              v57 = (float)((float)((float)(v39 - *v50) * v55) + (float)((float)(v40 - v52) * v54))
                  + (float)((float)(v41 - v53) * v56);
              if ( v57 <= 0.0 )
                v57 = 0.0;
              if ( v57 >= v50[3] )
                v57 = v50[3];
              v51 = *v50;
              if ( !v43
                || (float)((float)((float)((float)(v40 - (float)((float)(v57 * v54) + v52))
                                         * (float)(v40 - (float)((float)(v57 * v54) + v52)))
                                 + (float)((float)(v39 - (float)((float)(v55 * v57) + v51))
                                         * (float)(v39 - (float)((float)(v55 * v57) + v51))))
                         + (float)((float)(v41 - (float)((float)(v56 * v57) + v53))
                                 * (float)(v41 - (float)((float)(v56 * v57) + v53)))) < v46 )
              {
                v46 = (float)((float)((float)(v40 - (float)((float)(v57 * v54) + v52))
                                    * (float)(v40 - (float)((float)(v57 * v54) + v52)))
                            + (float)((float)(v39 - (float)((float)(v55 * v57) + v51))
                                    * (float)(v39 - (float)((float)(v55 * v57) + v51))))
                    + (float)((float)(v41 - (float)((float)(v56 * v57) + v53))
                            * (float)(v41 - (float)((float)(v56 * v57) + v53)));
                v44 = (float *)&v35[30].m_SafePointerList.mNode.mPrev[2 * v49];
                v45 = v57;
              }
              ++v43;
            }
            while ( v43 < v38 );
            v58 = v44[4];
            v59 = v44[6];
            v67 = (__m128)*((unsigned int *)v44 + 4);
            v60 = UFG::qVector3::msAxisZ.y;
            v61 = UFG::qVector3::msAxisZ.z;
            v62 = (float)(v58 * v45) + *v44;
            v63 = (float)(v44[5] * v45) + v44[1];
            v64 = (float)(v44[6] * v45) + v44[2];
            v65 = (float)(v59 * UFG::qVector3::msAxisZ.y) - (float)(v44[5] * UFG::qVector3::msAxisZ.z);
            v66 = (float)(v44[5] * UFG::qVector3::msAxisZ.x) - (float)(v58 * UFG::qVector3::msAxisZ.y);
            v67.m128_f32[0] = (float)(v67.m128_f32[0] * UFG::qVector3::msAxisZ.z)
                            - (float)(v59 * UFG::qVector3::msAxisZ.x);
            v68 = v67;
            v68.m128_f32[0] = (float)((float)(v67.m128_f32[0] * v67.m128_f32[0]) + (float)(v65 * v65))
                            + (float)(v66 * v66);
            if ( v68.m128_f32[0] != 0.0 )
              v42 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v68));
            v2->v2.x = UFG::qVector3::msAxisZ.x;
            v2->v2.y = v60;
            v2->v2.z = v61;
            v2->v2.w = 0.0;
            v2->v1.w = 0.0;
            v2->v1.x = v65 * v42;
            v2->v1.y = v67.m128_f32[0] * v42;
            v2->v1.z = v66 * v42;
            v69 = v44[5];
            v70 = v44[6];
            v2->v0.x = v44[4];
            v2->v0.w = 0.0;
            v2->v0.y = v69;
            v2->v0.z = v70;
            v2->v3.x = v62;
            v2->v3.w = 1.0;
            v2->v3.y = v63;
            v2->v3.z = v64;
          }
        }
      }
    }
  }
}

// File Line: 1764
// RVA: 0x64E7B0
UFG::RoadNetworkLane *__fastcall UFG::AiDriverComponent::GetLaneAtEdgeNum(UFG::AiDriverComponent *this, unsigned int endEdgeIndex)
{
  UFG::SimComponent *v2; // rbx
  unsigned int v3; // edi
  UFG::RoadNetworkLane *v4; // r15
  UFG::RoadNetworkResource *v5; // rax
  unsigned __int16 *v6; // r12
  __int64 v7; // r13
  UFG::RoadNetworkSegment *v8; // rax
  UFG::RoadNetworkConnection *v9; // rcx
  UFG::RoadNetworkSegment *v10; // rbp
  _WORD **v11; // rax
  _WORD *v12; // rdx
  UFG::RoadNetworkNode *v13; // r14
  unsigned int v14; // esi
  UFG::RoadNetworkLane *v15; // rax
  __int64 v16; // rcx
  UFG::RoadNetworkConnection *v17; // rdi
  unsigned int v18; // ebx
  UFG::RoadNetworkLane *v19; // rax
  UFG::RoadNetworkLane *v20; // r8
  __int64 v21; // rcx
  signed __int64 v22; // rdx
  UFG::RoadNetworkSegment **v23; // rax
  UFG::RoadNetworkSegment *v24; // rcx
  __int64 v25; // rax
  UFG::RoadNetworkResource *v27; // [rsp+50h] [rbp+8h]

  v2 = this->m_pRoadSpace.m_pSimComponent;
  v3 = endEdgeIndex;
  v4 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v2[5].m_BoundComponentHandles.mNode.mNext)->m_CurrentLane;
  if ( WORD2(v2[9].m_SafePointerList.mNode.mPrev) )
  {
    v5 = UFG::gpRoadNetworkResource;
    v27 = UFG::gpRoadNetworkResource;
    if ( v3 )
    {
      v6 = (unsigned __int16 *)((char *)&v2[9].m_SafePointerList.mNode.mPrev + 6);
      v7 = v3;
      do
      {
        v8 = UFG::RoadNetworkResource::GetSegment(v5, *v6);
        v9 = (UFG::RoadNetworkConnection *)v4->mNextConnection.mOffset;
        v10 = v8;
        if ( v9 )
          v9 = (UFG::RoadNetworkConnection *)((char *)v9 + (_QWORD)v4 + 104);
        v11 = (_WORD **)v9->mGate.mOffset;
        if ( v11 )
          v11 = (_WORD **)((char *)v11 + (_QWORD)v9 + 24);
        v12 = *v11;
        if ( *v11 )
          v12 = (_WORD *)((char *)v12 + (_QWORD)v11);
        if ( *v12 == 1 )
        {
          if ( v4->mNode.mOffset )
            v13 = (UFG::RoadNetworkNode *)((char *)v4 + v4->mNode.mOffset);
          else
            v13 = 0i64;
          v14 = 0;
          if ( !v13->mNumLanes )
            goto LABEL_35;
          while ( 1 )
          {
            v15 = UFG::RoadNetworkNode::GetLane(v13, v14);
            v16 = v15->mNextConnection.mOffset;
            v17 = (UFG::RoadNetworkConnection *)(v16 ? (UFG::qOffset64<UFG::RoadNetworkConnection *> *)((char *)&v15->mNextConnection + v16) : 0i64);
            v18 = 0;
            if ( v17->mNumLanes )
              break;
LABEL_29:
            if ( ++v14 >= (unsigned __int8)v13->mNumLanes )
              goto LABEL_35;
          }
          while ( 1 )
          {
            v19 = UFG::qBezierPathCollectionMemImaged::GetPath(v17, v18);
            v20 = v19;
            if ( v19 )
            {
              v21 = v19->mNextConnection.mOffset;
              if ( v21 )
                v22 = (signed __int64)&v19->mNextConnection + v21;
              else
                v22 = 0i64;
              v23 = *(UFG::RoadNetworkSegment ***)(v22 + 24);
              if ( v23 )
                v23 = (UFG::RoadNetworkSegment **)((char *)v23 + v22 + 24);
              v24 = *v23;
              if ( *v23 )
                v24 = (UFG::RoadNetworkSegment *)((char *)v24 + (_QWORD)v23);
              if ( v24 == v10 )
                break;
            }
            if ( ++v18 >= v17->mNumLanes )
              goto LABEL_29;
          }
          v25 = v20->mNextConnection.mOffset;
          if ( v25 )
            v9 = (UFG::RoadNetworkConnection *)((char *)&v20->mNextConnection + v25);
          else
            v9 = 0i64;
        }
        v4 = UFG::qBezierPathCollectionMemImaged::GetPath(v9, 0);
LABEL_35:
        v5 = v27;
        ++v6;
        --v7;
      }
      while ( v7 );
    }
  }
  return v4;
}

// File Line: 1826
// RVA: 0x647B00
void __fastcall UFG::AiDriverComponent::ChangeLane(UFG::AiDriverComponent *this, UFG::RoadNetworkLane::LaneChangeDirection direction)
{
  UFG::AiDriverComponent *v2; // rbx
  UFG::RoadNetworkGuide *v3; // rsi
  unsigned int v4; // edi
  UFG::RoadNetworkLocation *v5; // rax
  bool v6; // bp
  UFG::RoadNetworkLocation *v7; // rax
  float v8; // xmm0_4
  UFG::DrivingTargetOffsetMover *v9; // rbx
  float v10; // xmm6_4
  UFG::RoadNetworkLocation *v11; // rax
  float v12; // xmm6_4

  if ( direction )
  {
    v2 = this;
    v3 = (UFG::RoadNetworkGuide *)&this->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext;
    v4 = direction;
    v5 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v3);
    v6 = UFG::RoadNetworkLane::IsReversedInNode(v5->m_CurrentLane);
    v7 = (UFG::RoadNetworkLocation *)UFG::RoadNetworkGuide::GetTargetLocation((UFG::RippleGenerator *)v3);
    v8 = UFG::RoadNetworkLocation::GetLaneOffset(v7);
    v9 = &v2->m_OffsetMover;
    if ( v6 )
      v10 = v8 - v9->m_CurrentLateralOffset;
    else
      v10 = v8 + v9->m_CurrentLateralOffset;
    UFG::RoadNetworkGuide::ChangeLane(v3, v4);
    v11 = (UFG::RoadNetworkLocation *)UFG::RoadNetworkGuide::GetTargetLocation((UFG::RippleGenerator *)v3);
    v12 = v10 - UFG::RoadNetworkLocation::GetLaneOffset(v11);
    if ( v6 )
      LODWORD(v12) ^= _xmm[0];
    v9->m_CurrentLateralOffset = v12;
    UFG::DrivingTargetOffsetMover::SetNewTarget(v9, 0.0, 2.0);
  }
}

// File Line: 1851
// RVA: 0x656620
void __fastcall UFG::AiDriverComponent::OnAttach(UFG::AiDriverComponent *this, UFG::SimObject *_object)
{
  UFG::SimObjectVehicle *v2; // rsi
  UFG::AiDriverComponent *v3; // rbx
  UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0> *v4; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::VehicleSubjectComponent *v9; // rcx
  bool v10; // di
  UFG::qPidParameterBlock *v11; // rdx
  UFG::PhysicsMoverInterface *v12; // rcx
  float v13; // xmm1_4
  UFG::qPidParameterBlock *v14; // rdx

  v2 = (UFG::SimObjectVehicle *)_object;
  v3 = this;
  UFG::VehicleDriverInterface::OnAttach((UFG::VehicleDriverInterface *)&this->vfptr, _object);
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0>::Bind<UFG::SimObjectVehicle>(&v3->m_pRoadSpace, v2);
  v4 = &v3->m_pVehicleSubject;
  if ( v3->m_pVehicleSubject.m_pSimComponent )
  {
    v5 = v4->mPrev;
    v6 = v3->m_pVehicleSubject.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->m_pVehicleSubject.m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pVehicleSubject.m_pSimObject = 0i64;
    v3->m_pVehicleSubject.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pVehicleSubject.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pVehicleSubject.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0> *)v3->m_pVehicleSubject.mNext != &v3->m_pVehicleSubject) )
  {
    v7 = v4->mPrev;
    v8 = v3->m_pVehicleSubject.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_pVehicleSubject.m_Changed = 1;
  v3->m_pVehicleSubject.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->m_pVehicleSubject.m_TypeUID = UFG::VehicleSubjectComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>::BindInternal<UFG::SimObjectVehicle>(
    &v3->m_pVehicleSubject,
    v2);
  UFG::PhysicsMoverInterface::Reload((UFG::PhysicsMoverInterface *)v3->mMoverComponent.m_pSimComponent, 0);
  UFG::AiDriverComponent::SetDrivingRoleByClassType(v3);
  v9 = (UFG::VehicleSubjectComponent *)v3->m_pVehicleSubject.m_pSimComponent;
  v10 = v9 && UFG::VehicleSubjectComponent::IsBoat(v9);
  if ( !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v3->vfptr[16].__vecDelDtor)(v3) || v10 )
  {
    v11 = &UFG::AiDriverComponent::m_pHighLODSteering;
    if ( v10 )
      v11 = &UFG::AiDriverComponent::m_pBoatSteering;
  }
  else
  {
    v11 = &UFG::AiDriverComponent::m_pLowLODSteering;
  }
  UFG::qPidControllerCore::SetParameters(&v3->m_SteeringPid, v11);
  v12 = (UFG::PhysicsMoverInterface *)v3->mMoverComponent.m_pSimComponent;
  v3->m_fSteeringScale = 1.0;
  if ( v12 )
  {
    v13 = UFG::PhysicsMoverInterface::GetHalfSteeringRange(v12);
    if ( v13 <= 0.017453292 )
      v13 = FLOAT_0_017453292;
    v3->m_fSteeringScale = 0.78539819 / v13;
  }
  *(_QWORD *)&v3->m_CatchupMaxSpeedUp = 0i64;
  UFG::qPidControllerCore::SetParameters(&v3->m_CatchupPid, &UFG::AiDriverComponent::m_CatchupParams);
  v14 = &UFG::AiDriverComponent::m_Throttle;
  if ( v10 )
    v14 = &UFG::AiDriverComponent::m_BoatThrottle;
  UFG::qPidControllerCore::SetParameters(&v3->m_ThrottlePid, v14);
  v3->m_BrakingGraph = (UFG::LinearGraph<float> *)&unk_142091418;
  v3->m_CarGapGraph = &stru_142091488;
  v3->m_fPreviousGasBrakes = 0.0;
  UFG::VehicleDriverInterface::SetDesiredState((UFG::VehicleDriverInterface *)&v3->vfptr, (UFG::VehicleState)2);
  UFG::AiDriverComponent::AttachDriverProfile(v3, v2);
}

// File Line: 1886
// RVA: 0x6569A0
void __fastcall UFG::AiDriverComponent::OnDetach(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // rbx
  UFG::SimObject *v2; // rax
  hkSimpleLocalFrame *v3; // rcx
  UFG::SimObject *v4; // rdi
  UFG::SimComponent *v5; // rax
  UFG::VehicleState v6; // edx
  UFG::SimObject *v7; // rax
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0> *v13; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax

  v1 = this;
  if ( (LOBYTE(this->m_pSimObject->m_Flags) >> 1) & 1
    && ((unsigned __int8 (*)(void))this->vfptr[16].__vecDelDtor)()
    && v1->m_AmbientDriverType == 2 )
  {
    v2 = v1->m_pSimObject;
    if ( v2 )
      v3 = (hkSimpleLocalFrame *)v2->m_Components.p[30].m_pComponent;
    else
      v3 = 0i64;
    v4 = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v3);
    if ( v4 )
    {
      UFG::PedSpawnManager::GetInstance();
      UFG::Simulation::DestroySimObject(&UFG::gSim, v4);
    }
    v1->m_AmbientDriverType = 1;
  }
  v5 = v1->mMoverComponent.m_pSimComponent;
  if ( !v5 || (v6 = 5, (float)(3.5999999 * *((float *)&v5[10].m_BoundComponentHandles.mNode.mPrev + 1)) <= 30.0) )
    v6 = 1;
  UFG::VehicleDriverInterface::SetDesiredState((UFG::VehicleDriverInterface *)&v1->vfptr, v6);
  v7 = UFG::AiDriverComponent::m_CurrentDebugCar;
  v8 = &v1->m_pRoadSpace;
  if ( v1->m_pSimObject == UFG::AiDriverComponent::m_CurrentDebugCar )
    v7 = 0i64;
  UFG::AiDriverComponent::m_CurrentDebugCar = v7;
  if ( v1->m_pRoadSpace.m_pSimComponent )
  {
    v9 = v8->mPrev;
    v10 = v1->m_pRoadSpace.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v1->m_pRoadSpace.m_pSimComponent = 0i64;
LABEL_21:
    v1->m_pRoadSpace.m_pSimObject = 0i64;
    v1->m_pRoadSpace.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pRoadSpace.mPrev;
    v8->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v8->mPrev;
    goto LABEL_22;
  }
  if ( v1->m_pRoadSpace.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0> *)v8->mPrev != v8
     || (UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0> *)v1->m_pRoadSpace.mNext != &v1->m_pRoadSpace) )
  {
    v11 = v8->mPrev;
    v12 = v1->m_pRoadSpace.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    goto LABEL_21;
  }
LABEL_22:
  v1->m_pRoadSpace.m_Changed = 1;
  v13 = &v1->m_pVehicleSubject;
  if ( v1->m_pVehicleSubject.m_pSimComponent )
  {
    v14 = v13->mPrev;
    v15 = v1->m_pVehicleSubject.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v1->m_pVehicleSubject.m_pSimComponent = 0i64;
LABEL_28:
    v1->m_pVehicleSubject.m_pSimObject = 0i64;
    v1->m_pVehicleSubject.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pVehicleSubject.mPrev;
    v13->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v13->mPrev;
    goto LABEL_29;
  }
  if ( v1->m_pVehicleSubject.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0> *)v13->mPrev != v13
     || (UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0> *)v1->m_pVehicleSubject.mNext != &v1->m_pVehicleSubject) )
  {
    v16 = v13->mPrev;
    v17 = v1->m_pVehicleSubject.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    goto LABEL_28;
  }
LABEL_29:
  v1->m_pVehicleSubject.m_Changed = 1;
  UFG::VehicleDriverInterface::OnDetach((UFG::VehicleDriverInterface *)&v1->vfptr);
}

// File Line: 1919
// RVA: 0x645140
void __fastcall UFG::AiDriverComponent::AttachDriverProfile(UFG::AiDriverComponent *this, UFG::SimObjectVehicle *sim_object_vehicle)
{
  UFG::SceneObjectProperties *v2; // rax
  UFG::AiDriverComponent *v3; // rdi
  UFG::SimObjectVehicle *v4; // rbx
  UFG::qPropertySet *v5; // rcx
  UFG::qPropertySet *v6; // rax
  bool *v7; // rax
  char *v8; // rcx
  char v9; // al
  UFG::qPropertySet *v10; // rcx
  float *v11; // rdi
  UFG::qPropertySet *v12; // rax
  char v13; // [rsp+30h] [rbp+8h]

  v2 = sim_object_vehicle->m_pSceneObj;
  v3 = this;
  v4 = sim_object_vehicle;
  v5 = v2->mpWritableProperties;
  if ( !v5 )
    v5 = v2->mpConstProperties;
  v6 = UFG::SimObjectUtility::FindDriverProfile(v5);
  v3->m_DriverProfile = v6;
  if ( v6 )
  {
    v13 = 0;
    v7 = UFG::qPropertySet::Get<bool>(v6, (UFG::qSymbol *)&qSymbol_DeniesHijack.mUID, DEPTH_RECURSE);
    v8 = &v13;
    if ( v7 )
      v8 = (char *)v7;
    v9 = *v8;
    v10 = v3->m_DriverProfile;
    v3->m_bDeniesHijack = v9;
    v11 = UFG::qPropertySet::Get<float>(v10, (UFG::qSymbol *)&qSymbol_RadioStation.mUID, DEPTH_RECURSE);
    if ( v11 )
    {
      v12 = UFG::SceneObjectProperties::GetWritableProperties(v4->m_pSceneObj);
      UFG::qPropertySet::Set<float>(v12, (UFG::qSymbol *)&qSymbol_RadioStation.mUID, *v11);
    }
  }
}

// File Line: 1935
// RVA: 0x6592E0
void __fastcall UFG::AiDriverComponent::SetFollowOffset(UFG::AiDriverComponent *this, CarCombat::Side side, CarCombat::Position position, float tolerance)
{
  UFG::AiDriverComponent *v4; // rsi
  UFG::VehicleSubjectComponent *v5; // rcx
  __int64 v6; // rbx
  CarCombat::Side v7; // edi
  signed __int64 v8; // rax
  float v9; // xmm1_4
  float v10; // xmm0_4
  UFG::qVector3 customOffset; // [rsp+30h] [rbp-28h]

  v4 = this;
  v5 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  v6 = position;
  v7 = side;
  if ( v5 && UFG::VehicleSubjectComponent::IsBoat(v5) )
    v8 = 12 * v6 + 5402855584i64;
  else
    v8 = 12 * v6 + 5402855488i64;
  v9 = *(float *)(v8 + 4);
  customOffset.x = *(float *)v8;
  v10 = *(float *)(v8 + 8);
  customOffset.y = v9;
  customOffset.z = v10;
  if ( v7 == 1 )
    LODWORD(customOffset.y) = LODWORD(v9) ^ _xmm[0];
  UFG::AiDriverComponent::SetFollowOffsetCustom(v4, v7, (CarCombat::Position)v6, &customOffset, tolerance);
}

// File Line: 1941
// RVA: 0x6593B0
void __fastcall UFG::AiDriverComponent::SetFollowOffsetCustom(UFG::AiDriverComponent *this, CarCombat::Side side, CarCombat::Position position, UFG::qVector3 *customOffset, float tolerance)
{
  UFG::qVector3 *v5; // rdi
  CarCombat::Position v6; // esi
  UFG::AiDriverComponent *v7; // rbx
  float v8; // xmm0_4
  float v9; // xmm1_4

  v5 = customOffset;
  v6 = position;
  v7 = this;
  if ( __PAIR__(side, position) != *(_QWORD *)&this->m_DesiredOffset || tolerance < this->m_fFollowOffsetTolerance )
  {
    if ( side == 2 || side == 3 )
      this->m_Side = (signed int)UFG::qRandom(100, &UFG::qDefaultSeed) <= 50;
    else
      this->m_Side = side;
    v7->m_DesiredOffset = v6;
    v8 = v5->y;
    v9 = v5->z;
    v7->m_vFollowOffsetDesired.x = v5->x;
    v7->m_vFollowOffsetDesired.y = v8;
    v7->m_vFollowOffsetDesired.z = v9;
    v7->m_fTimeNearOffset = 0.0;
  }
  if ( v6 == Follow )
    v7->m_vFollowOffsetDesired.x = v7->m_fFollowDistance * v5->x;
  if ( tolerance <= 5.0 )
    v7->m_fFollowOffsetTolerance = tolerance;
  else
    v7->m_fFollowOffsetTolerance = FLOAT_5_0;
}

// File Line: 1978
// RVA: 0x650F90
float __fastcall UFG::AiDriverComponent::GetTimeAtOffset(UFG::AiDriverComponent *this, CarCombat::Position position)
{
  float result; // xmm0_4

  if ( this->m_DesiredOffset == position )
    result = this->m_fTimeNearOffset;
  else
    result = 0.0;
  return result;
}

// File Line: 1985
// RVA: 0x657F50
void __fastcall UFG::AiDriverComponent::RemoveFromRace(UFG::AiDriverComponent *this, bool hideBlip)
{
  bool v2; // di
  UFG::AiDriverComponent *v3; // rbx
  UFG::RoadSpaceComponent *v4; // rcx
  UFG::SimObjectGame *v5; // rcx
  UFG::HudComponent *v6; // rax
  UFG::qBaseTreeRB *v7; // rax

  v2 = hideBlip;
  v3 = this;
  if ( this->m_DrivingMode )
  {
    this->m_DrivingMode = 0;
    this->m_fReactionTime = 0.0;
    this->m_fDelayedStopDecel = 0.0;
    this->mModeSteeringLockEnabled = 0;
    this->mModeGasBrakeLockEnabled = 0;
    this->m_bIgnoreArrivalDirection = 0;
    if ( this->m_ResetStopDistOnStop )
      this->m_StopDist = 1.0;
  }
  v4 = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
  if ( v4 )
    UFG::RoadSpaceComponent::SetRaceTrail(v4, 0i64);
  if ( v2 )
  {
    v5 = (UFG::SimObjectGame *)v3->m_pSimObject;
    if ( v5 )
    {
      v6 = (UFG::HudComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::HudComponent::_TypeUID);
      if ( v6 )
      {
        v7 = UFG::HudComponent::GetIcon(v6);
        if ( v7 )
          UFG::UIMapBlip::SetVisible((UFG::UIMapBlip *)v7, 0);
      }
    }
  }
}

// File Line: 2000
// RVA: 0x662EE0
void __fastcall UFG::AiDriverComponent::UpdateRace(UFG::AiDriverComponent *this, float seconds)
{
  UFG::AiDriverComponent *v2; // rbx
  bool v3; // al
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rsi
  bool v5; // bp
  bool v6; // di
  UFG::PhysicsMoverInterface *v7; // rcx
  bool v8; // al
  bool v9; // dl
  UFG::RoadSpaceComponent *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::RoadSpaceComponent *v12; // rax
  UFG::RacePosition *v13; // rcx
  float v14; // xmm6_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm6_4
  float v18; // xmm0_4

  v2 = this;
  if ( !this->m_pRoadSpace.m_pSimComponent )
    return;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v3 = UFG::RoadSpaceComponent::CleanupOnRaceDeleted((UFG::RoadSpaceComponent *)v2->m_pRoadSpace.m_pSimComponent);
  v4 = v2->m_pRoadSpace.m_pSimComponent[26].m_SafePointerList.mNode.mPrev;
  v5 = v3;
  if ( v4 )
    v6 = 100.0 < *((float *)&v4[3].mPrev + 1);
  else
    v6 = 0;
  v7 = (UFG::PhysicsMoverInterface *)v2->mMoverComponent.m_pSimComponent;
  v8 = v7 && UFG::PhysicsMoverInterface::GetEngineDamage(v7) >= 1.0;
  if ( v6 || v8 )
  {
    v9 = 1;
    if ( v6 || v8 )
      goto LABEL_40;
  }
  else
  {
    v9 = 0;
  }
  if ( v5 )
  {
LABEL_40:
    UFG::AiDriverComponent::RemoveFromRace(v2, v9);
    return;
  }
  v10 = (UFG::RoadSpaceComponent *)v2->m_pRoadSpace.m_pSimComponent[26].m_pSimObject;
  if ( v10
    && ((v11 = WORD2(v10->mNext), !((v11 >> 14) & 1)) ? ((v11 & 0x8000u) == 0 ? (!((v11 >> 13) & 1) ? (!((v11 >> 12) & 1) ? (v12 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)v10, UFG::RoadSpaceComponent::_TypeUID)) : (v12 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v10, UFG::RoadSpaceComponent::_TypeUID))) : (v12 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v10, UFG::RoadSpaceComponent::_TypeUID))) : (v12 = *(UFG::RoadSpaceComponent **)(*(_QWORD *)&v10->m_NavGuide.m_PathQueryState + 384i64))) : (v12 = *(UFG::RoadSpaceComponent **)(*(_QWORD *)&v10->m_NavGuide.m_PathQueryState + 384i64)),
        v12) )
  {
    v13 = v12->m_pRacePosition;
  }
  else
  {
    v13 = 0i64;
  }
  if ( v4 && v13 )
  {
    v14 = *(float *)&v4[3].mPrev - (float)(v2->m_CatchupOffset + v13->fRaceDistance);
    UFG::qPidControllerCore::Record(&v2->m_CatchupPid, v14, seconds, 0i64);
    v15 = v2->m_CatchupRangeBehind;
    if ( v14 > 0.0 )
      v15 = v2->m_CatchupRangeAhead;
    UFG::AiDriverComponent::m_CatchupParams.m_P_Coefficient = -1.0 / v15;
    if ( v15 >= 50.0 )
      v15 = FLOAT_50_0;
    v16 = FLOAT_3_1415927;
    v17 = (float)(v14 * 3.1415927) / v15;
    if ( v17 <= -3.1415927 )
    {
      v17 = FLOAT_N3_1415927;
    }
    else if ( v17 >= 3.1415927 )
    {
      goto LABEL_39;
    }
    v16 = v17;
LABEL_39:
    v18 = (float)(cosf(v16) + 1.0) * 0.5;
    UFG::AiDriverComponent::m_CatchupParams.m_I_Coefficient = (float)(1.0 - v18) * UFG::AiDriverComponent::m_Catchup_I;
    UFG::AiDriverComponent::m_CatchupParams.m_D_Coefficient = UFG::AiDriverComponent::m_Catchup_D * v18;
    UFG::qPidControllerCore::SetParameters(&v2->m_CatchupPid, &UFG::AiDriverComponent::m_CatchupParams);
  }
}

// File Line: 2099
// RVA: 0x64D830
float __fastcall UFG::AiDriverComponent::GetCatchupBoost(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // rbx
  float result; // xmm0_4
  UFG::SimComponent *v3; // rax

  v1 = this;
  if ( this->m_DrivingMode != 6 )
    return 0.0;
  v3 = this->m_pRoadSpace.m_pSimComponent;
  if ( !v3 || !v3[26].m_pSimObject )
    return 0.0;
  result = UFG::qPidControllerCore::GetOutput(&this->m_CatchupPid);
  if ( result <= COERCE_FLOAT(LODWORD(v1->m_CatchupMaxSlowDown) ^ _xmm[0]) )
    LODWORD(result) = LODWORD(v1->m_CatchupMaxSlowDown) ^ _xmm[0];
  if ( result >= v1->m_CatchupMaxSpeedUp )
    result = v1->m_CatchupMaxSpeedUp;
  if ( result < -1.0 )
    result = FLOAT_N1_0;
  return result;
}

// File Line: 2142
// RVA: 0x648080
void __fastcall UFG::AiDriverComponent::CheckForGround(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // rbx
  unsigned int v2; // ecx
  UFG::SimObject *v3; // rax
  UFG::SimComponentHolder *v4; // rax
  UFG::SimComponent *v5; // rdi

  v1 = this;
  v2 = this->m_DrivingMode;
  if ( !((v2 - 3) & 0xFFFFFFFC) && v2 != 5 )
  {
    v3 = v1->m_pSimObject;
    if ( v3 )
    {
      v4 = v3->m_Components.p;
      v5 = v4[2].m_pComponent;
      if ( v5 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4[2].m_pComponent);
        if ( *(float *)&v5[2].m_BoundComponentHandles.mNode.mNext < -20.0 )
        {
          if ( v1->m_DrivingMode == 6 )
            UFG::AiDriverComponent::RemoveFromRace(v1, 1);
          if ( v1->m_DrivingMode )
          {
            v1->m_DrivingMode = 0;
            v1->m_fReactionTime = 0.0;
            v1->m_fDelayedStopDecel = 0.0;
            v1->mModeSteeringLockEnabled = 0;
            v1->mModeGasBrakeLockEnabled = 0;
            v1->m_bIgnoreArrivalDirection = 0;
            if ( v1->m_ResetStopDistOnStop )
              v1->m_StopDist = 1.0;
          }
        }
      }
    }
  }
}

// File Line: 2185
// RVA: 0x648140
void __fastcall UFG::AiDriverComponent::CheckForReattach(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *v1; // rax
  UFG::AiDriverComponent *v2; // rbx
  UFG::RoadNetworkGuide *v3; // rdi
  UFG::VehicleWayFinderClient *v4; // rsi
  UFG::RoadNetworkLocation *v5; // rbp
  UFG::RoadNetworkGraph *v6; // rax
  UFG::RoadNetworkResource *v7; // rbp
  UFG::SimComponent *v8; // rdi
  float v9; // xmm6_4
  unsigned int v10; // ebx
  UFG::RoadNetworkNode *v11; // rax
  bool v12; // zf
  UFG::qVector3 result; // [rsp+30h] [rbp-48h]
  UFG::qVector3 v14; // [rsp+40h] [rbp-38h]
  UFG::RoadNetworkLocation v15; // [rsp+50h] [rbp-28h]

  v1 = this->m_pRoadSpace.m_pSimComponent;
  v2 = this;
  if ( v1 )
  {
    v3 = (UFG::RoadNetworkGuide *)&v1[5].m_BoundComponentHandles.mNode.mNext;
    if ( v1 != (UFG::SimComponent *)-376i64 )
    {
      if ( LOBYTE(v1[8].m_Flags) )
      {
        v4 = (UFG::VehicleWayFinderClient *)&v1[8].m_pSimObject;
        if ( v1 != (UFG::SimComponent *)-552i64 )
        {
          if ( ((unsigned __int8 (*)(void))this->vfptr[16].__vecDelDtor)() )
          {
            if ( !UFG::AiDriverComponent::IsBoat(v2) )
            {
              v5 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v3);
              if ( (unsigned __int8)UFG::RoadNetworkLocation::IsValid(v5) )
              {
                UFG::RoadNetworkLocation::GetPos(v5, &result);
                if ( (float)((float)((float)((float)(v3->m_Position.y - result.y) * (float)(v3->m_Position.y - result.y))
                                   + (float)((float)(v3->m_Position.x - result.x) * (float)(v3->m_Position.x - result.x)))
                           + (float)((float)(v3->m_Position.z - result.z) * (float)(v3->m_Position.z - result.z))) >= 3600.0 )
                {
                  v6 = UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(
                         UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                         v4);
                  if ( v6 )
                  {
                    v7 = v6->pRoadNetworkResource;
                    if ( v7 )
                    {
                      Scaleform::GFx::AS3::Value::Value(&v15);
                      UFG::RoadNetworkLocation::AttachToNetwork(&v15, v7, &v3->m_Position, 0i64, v4->m_RoadNetworkType);
                      if ( (unsigned __int8)UFG::RoadNetworkLocation::IsValid(&v15)
                        && (UFG::RoadNetworkLocation::GetPos(&v15, &v14),
                            (float)((float)((float)((float)(v3->m_Position.y - v14.y) * (float)(v3->m_Position.y - v14.y))
                                          + (float)((float)(v3->m_Position.x - v14.x) * (float)(v3->m_Position.x - v14.x)))
                                  + (float)((float)(v3->m_Position.z - v14.z) * (float)(v3->m_Position.z - v14.z))) < 3025.0) )
                      {
                        v8 = v2->m_pRoadSpace.m_pSimComponent;
                        v9 = v15.m_LaneT;
                        v10 = v15.m_CurrentLane->mLaneIndex;
                        v11 = UFG::RoadNetworkLocation::GetRoadNetworkNode(&v15);
                        UFG::RoadNetworkGuide::AttachToNetwork(
                          (UFG::RoadNetworkGuide *)&v8[5].m_BoundComponentHandles.mNode.mNext,
                          v8->m_pSimObject,
                          v11,
                          v10,
                          v9);
                      }
                      else
                      {
                        v12 = v2->m_DrivingMode == 0;
                        v2->m_IsAmbient = 0;
                        if ( !v12 )
                        {
                          v2->m_DrivingMode = 0;
                          v2->m_fReactionTime = 0.0;
                          v2->m_fDelayedStopDecel = 0.0;
                          v2->mModeSteeringLockEnabled = 0;
                          v2->mModeGasBrakeLockEnabled = 0;
                          v2->m_bIgnoreArrivalDirection = 0;
                          if ( v2->m_ResetStopDistOnStop )
                            v2->m_StopDist = 1.0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 2245
// RVA: 0x665430
char __fastcall UFG::AiDriverComponent::UpdateVehicleOccupants(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // rsi
  UFG::SimObject *v3; // rax
  int v4; // edi
  UFG::TransformNodeComponent *v5; // rbx
  UFG::BaseCameraComponent *v6; // rcx
  float *v7; // rcx
  char v8; // r15
  float v9; // xmm6_4
  float v10; // xmm1_4
  UFG::AiDriverComponent::AmbientDriverType v11; // eax
  UFG::SimObject *v13; // rax
  UFG::SimComponentHolder *v14; // rax
  UFG::VehicleOccupantComponent *v15; // r14
  int v16; // ebp
  UFG::SimObjectCharacter *v17; // rbx
  UFG::SimObject *v18; // rax
  UFG::VehicleOccupantComponent *v19; // rcx
  UFG::SimObject *v20; // rax
  hkSimpleLocalFrame *v21; // rcx

  v1 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[16].__vecDelDtor)()
    && !UFG::SimObjectUtility::IsClassType(v1->m_pSimObject, (UFG::qSymbol *)&qSymbol_Taxi.mUID)
    || v1->m_AmbientDriverType == AmbientDriverType_None )
  {
    return 0;
  }
  v3 = v1->m_pSimObject;
  v4 = 0;
  if ( v3 )
    v5 = (UFG::TransformNodeComponent *)v3->m_Components.p[2].m_pComponent;
  else
    v5 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v6 = UFG::Director::Get()->mCurrentCamera;
  if ( v6 )
    v7 = &v6->mCamera.mFOVOffset;
  else
    v7 = 0i64;
  v8 = 0;
  v9 = (float)((float)((float)(v7[45] - v5->mWorldTransform.v3.y) * (float)(v7[45] - v5->mWorldTransform.v3.y))
             + (float)((float)(v7[44] - v5->mWorldTransform.v3.x) * (float)(v7[44] - v5->mWorldTransform.v3.x)))
     + (float)((float)(v7[46] - v5->mWorldTransform.v3.z) * (float)(v7[46] - v5->mWorldTransform.v3.z));
  if ( UFG::VehicleSubjectComponent::IsBike((UFG::VehicleSubjectComponent *)v1->m_pVehicleSubject.m_pSimComponent) )
    v10 = UFG::AiDriverComponent::m_AmbientBikeDriverPopInDistanceSquared;
  else
    v10 = UFG::AiDriverComponent::m_AmbientDriverPopInDistanceSquared;
  v11 = v1->m_AmbientDriverType;
  if ( v11 == 1 && v9 < (float)(v10 - 5.0) )
    return UFG::AiDriverComponent::PopulateVehicleOccupants(v1);
  if ( v11 == 2 )
  {
    if ( v9 >= (float)(v10 + 5.0) )
    {
      v13 = v1->m_pSimObject;
      if ( v13
        && (v14 = v13->m_Components.p, (v15 = (UFG::VehicleOccupantComponent *)v14[30].m_pComponent) != 0i64)
        && (v16 = UFG::VehicleOccupantComponent::GetNumberOfOccupants((UFG::VehicleOccupantComponent *)v14[30].m_pComponent),
            v16 > 0) )
      {
        while ( 1 )
        {
          v17 = (UFG::SimObjectCharacter *)UFG::VehicleOccupantComponent::GetPassenger(v15, v4, 0);
          if ( v17 == UFG::GetLocalPlayer() )
            break;
          if ( ++v4 >= v16 )
            goto LABEL_24;
        }
      }
      else
      {
LABEL_24:
        v18 = v1->m_pSimObject;
        v8 = 0;
        v1->m_AmbientDriverType = 1;
        if ( v18 )
        {
          v19 = (UFG::VehicleOccupantComponent *)v18->m_Components.p[30].m_pComponent;
          if ( v19 )
          {
            UFG::VehicleOccupantComponent::DeleteAllOccupants(v19);
            v8 = 1;
          }
        }
      }
      return v8;
    }
    v20 = v1->m_pSimObject;
    if ( v20 )
    {
      v21 = (hkSimpleLocalFrame *)v20->m_Components.p[30].m_pComponent;
      if ( v21 )
      {
        if ( !Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v21) )
          return UFG::AiDriverComponent::DepopulateVehicleOccupants(v1);
      }
    }
  }
  return v8;
}

// File Line: 2299
// RVA: 0x65EDD0
void __fastcall UFG::AiDriverComponent::Update(UFG::AiDriverComponent *this, float seconds)
{
  float v2; // xmm6_4
  UFG::AiDriverComponent *v3; // rbx
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rsi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rdx
  UFG::PhysicsWheeledVehicle *v10; // rcx
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  bool v14; // si
  UFG::qPidParameterBlock *v15; // rdx
  UFG::qPidParameterBlock *v16; // rdx
  int v17; // eax
  float v18; // xmm1_4
  __int64 v19; // rax
  __int64 v20; // r14
  UFG::SimObjectGame *v21; // rcx
  unsigned __int16 v22; // dx
  UFG::RoadSpaceComponent *v23; // rsi
  UFG::SimComponent *v24; // rax
  UFG::qVector3 *v25; // rax
  float v26; // xmm1_4
  float v27; // xmm2_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  bool v29; // dl
  __int64 v30; // rcx
  __int64 v31; // rax
  bool v32; // al
  UFG::qVector3 **v33; // rcx
  UFG::qVector3 *v34; // rax
  UFG::allocator::free_link *v35; // rax
  __int64 v36; // rcx
  _QWORD *v37; // rax
  __int64 v38; // rcx
  _QWORD *v39; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rdi
  float v41; // xmm2_4
  unsigned __int16 v42; // dx
  UFG::AiDriverComponent *v43; // rax
  UFG::qVector3 result; // [rsp+28h] [rbp-38h]
  __int64 v45; // [rsp+38h] [rbp-28h]
  UFG::qVector2 value; // [rsp+80h] [rbp+20h]

  v2 = seconds;
  v3 = this;
  v4 = *(_QWORD *)&this[-1].m_ResetStopDistOnStop;
  if ( !v4 || !((*(_WORD *)(v4 + 76) >> 10) & 1) )
  {
    UFG::AiDriverComponent::m_InUpdateScope = 1;
    UFG::AiDriverComponent::CheckForGround((UFG::AiDriverComponent *)((char *)this - 64));
    if ( *(_BYTE *)(*(_QWORD *)&v3->mForceDock + 1940i64) )
    {
      v5 = *(_QWORD *)&v3[-1].m_ResetStopDistOnStop;
      if ( v5 )
      {
        v6 = *(_QWORD *)(v5 + 104);
        v7 = *(_QWORD *)(v6 + 32);
        if ( v7 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v6 + 32));
          UFG::NavGuide::UpdatePathPosition(
            (UFG::NavGuide *)(*(_QWORD *)&v3->mForceDock + 80i64),
            (UFG::qVector3 *)(v7 + 176));
        }
      }
    }
    UFG::AiDriverComponent::CheckForReattach((UFG::AiDriverComponent *)((char *)v3 - 64));
    if ( v3->m_BoundComponentHandles.mNode.mPrev )
    {
      v8 = v3->m_BoundComponentHandles.mNode.mPrev;
      v9 = v8[40].mNext;
      if ( v9 )
      {
        v10 = 0i64;
        if ( BYTE4(v9[37].mNext) & 7 )
          v10 = (UFG::PhysicsWheeledVehicle *)v8[40].mNext;
        if ( v10 )
          UFG::PhysicsWheeledVehicle::ClearSteeringDeadZone(v10);
      }
    }
    UFG::VehicleDriverInterface::Update((UFG::VehicleDriverInterface *)&v3->vfptr, seconds);
    v11 = *(float *)&v3->m_CombatStats.mNumAttacks[1];
    if ( v11 > 0.0 )
    {
      v12 = v11 - seconds;
      if ( v12 < 0.0 )
        v12 = 0.0;
      *(float *)&v3->m_CombatStats.mNumAttacks[1] = v12;
    }
    v13 = *(float *)&v3->m_CombatStats.mNumAttacks[2];
    if ( v13 > 0.0 )
    {
      v13 = v13 - seconds;
      if ( v13 < 0.0 )
        v13 = 0.0;
      *(float *)&v3->m_CombatStats.mNumAttacks[2] = v13;
    }
    v14 = v3->m_pRoadSpace.mNext
       && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)v3->m_pRoadSpace.mNext);
    v15 = &UFG::AiDriverComponent::m_Throttle;
    if ( v14 )
      v15 = &UFG::AiDriverComponent::m_BoatThrottle;
    UFG::qPidControllerCore::SetParameters((UFG::qPidControllerCore *)((char *)&v3->m_SteeringPid + 88), v15);
    if ( !((unsigned __int8 (__fastcall *)(UFG::SimObject **))v3[-1].m_PathingTarget.m_pPointer[1].vfptr)(&v3[-1].m_PathingTarget.m_pPointer)
      || v14 )
    {
      v16 = &UFG::AiDriverComponent::m_pHighLODSteering;
      if ( v14 )
        v16 = &UFG::AiDriverComponent::m_pBoatSteering;
    }
    else
    {
      v16 = &UFG::AiDriverComponent::m_pLowLODSteering;
    }
    UFG::qPidControllerCore::SetParameters((UFG::qPidControllerCore *)&v3->m_pChaseVehicleSubject.mNext, v16);
    UFG::qPidControllerCore::SetParameters(
      (UFG::qPidControllerCore *)&v3->m_CarGapGraph,
      &UFG::AiDriverComponent::m_CatchupParams);
    v17 = v3->m_ThrottlePid.m_D_Term.m_EndIndex;
    if ( v17 == 3 || v17 == 7 && !HIDWORD(v3->m_pCastingPhantom) )
      UFG::VehicleCombatStats::Tick((UFG::VehicleCombatStats *)&v3->m_AvoidableSensor, seconds);
    if ( v3->m_ThrottlePid.m_D_Term.m_EndIndex == 6 )
      UFG::AiDriverComponent::UpdateRace((UFG::AiDriverComponent *)((char *)v3 - 64), seconds);
    if ( v3->m_BoundComponentHandles.mNode.mPrev )
    {
      v18 = UFG::PhysicsMoverInterface::GetHalfSteeringRange((UFG::PhysicsMoverInterface *)v3->m_BoundComponentHandles.mNode.mPrev);
      if ( v18 <= 0.017453292 )
        v18 = FLOAT_0_017453292;
      v13 = 0.78539819 / v18;
      *(float *)&v3->m_CatchupPid.m_D_Term.m_EndIndex = 0.78539819 / v18;
    }
    v19 = *(_QWORD *)&v3[-1].m_ResetStopDistOnStop;
    if ( v19 )
      v20 = *(_QWORD *)(*(_QWORD *)(v19 + 104) + 32i64);
    else
      v20 = 0i64;
    if ( v3->m_BoundComponentHandles.mNode.mPrev && v3->m_pRoadSpace.mNext && v20 )
    {
      if ( UFG::AiDriverComponent::UpdateVehicleOccupants((UFG::AiDriverComponent *)((char *)v3 - 64)) )
      {
LABEL_96:
        UFG::AiDriverComponent::m_InUpdateScope = 0;
        return;
      }
      v21 = *(UFG::SimObjectGame **)(*(_QWORD *)&v3->mForceDock + 1704i64);
      if ( v21 )
      {
        v22 = v21->m_Flags;
        if ( (v22 >> 14) & 1 )
        {
          v23 = (UFG::RoadSpaceComponent *)v21->m_Components.p[24].m_pComponent;
        }
        else if ( (v22 & 0x8000u) == 0 )
        {
          if ( (v22 >> 13) & 1 )
            v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::RoadSpaceComponent::_TypeUID);
          else
            v24 = (v22 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v21->vfptr, UFG::RoadSpaceComponent::_TypeUID);
          v23 = (UFG::RoadSpaceComponent *)v24;
        }
        else
        {
          v23 = (UFG::RoadSpaceComponent *)v21->m_Components.p[24].m_pComponent;
        }
        if ( v23 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v20);
          v25 = UFG::RoadSpaceComponent::WorldToChase(v23, &result, (UFG::qVector3 *)(v20 + 176));
          v13 = v25->x;
          v26 = v25->y;
          v27 = v25->z;
          v3->m_CatchupRangeBehind = v25->x;
          v3->m_CatchupRangeAhead = v26;
          v3->m_CatchupMaxSpeedUp = v27;
        }
      }
      UFG::AiDriverComponent::UpdateAvoidableSensor((UFG::AiDriverComponent *)((char *)v3 - 64), v2, v13);
      UFG::AiDriverComponent::UpdateDesiredSpeed((UFG::AiDriverComponent *)((char *)v3 - 64), v2);
      UFG::AiDriverComponent::UpdateSteering((UFG::AiDriverComponent *)((char *)v3 - 64), v2);
      UFG::AiDriverComponent::UpdateSpeed((UFG::AiDriverComponent *)((char *)v3 - 64), v2);
    }
    if ( *(float *)&v3->m_bSteeringLock > 0.5
      && UFG::Metrics::msInstance.mSimTimeMSec - *(_QWORD *)&v3->m_fSteeringScale < UFG::gLastValidHighSpeedCollisionDuration )
    {
      v28 = v3->m_pVehicleSubject.mPrev;
      v29 = v28
         && ((unsigned __int8 (__cdecl *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))v28->mPrev[23].mPrev)(v28);
      v30 = *(_QWORD *)&v3[-1].m_ResetStopDistOnStop;
      v31 = v30 ? *(_QWORD *)(*(_QWORD *)(v30 + 104) + 256i64) : 0i64;
      v32 = v31 != 0;
      if ( v29 && v32 )
      {
        *(_QWORD *)&result.x = &result;
        *(_QWORD *)&result.z = &result;
        v45 = v30;
        if ( v30 )
        {
          v33 = (UFG::qVector3 **)(v30 + 8);
          v34 = *v33;
          *(_QWORD *)&v34->z = &result;
          *(_QWORD *)&result.x = v34;
          *(_QWORD *)&result.z = v33;
          *v33 = &result;
        }
        v35 = UFG::qMalloc(0x50ui64, "AiDriverComponent::VehicleDisabledEvent", 0i64);
        value = (UFG::qVector2)v35;
        if ( v35 )
          UFG::AnimatedEvent::AnimatedEvent(
            (UFG::AnimatedEvent *)v35,
            UFG::gVehicleDisabledChannel.mName,
            (UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *)&result);
        UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v35);
        if ( v45 )
        {
          v36 = *(_QWORD *)&result.x;
          v37 = *(_QWORD **)&result.z;
          *(_QWORD *)(*(_QWORD *)&result.x + 8i64) = *(_QWORD *)&result.z;
          *v37 = v36;
          *(_QWORD *)&result.x = &result;
          *(_QWORD *)&result.z = &result;
        }
        v45 = 0i64;
        v38 = *(_QWORD *)&result.x;
        v39 = *(_QWORD **)&result.z;
        *(_QWORD *)(*(_QWORD *)&result.x + 8i64) = *(_QWORD *)&result.z;
        *v39 = v38;
        *(_QWORD *)&result.x = &result;
        *(_QWORD *)&result.z = &result;
      }
    }
    value.x = (float)(v2 * 4294967300.0) / v3->m_SteeringNoise.tFrequency;
    LODWORD(v3->m_SteeringNoise.tOffset) += (signed int)value.x;
    v40 = v3->m_BoundComponentHandles.mNode.mPrev;
    LODWORD(v40[6].mNext) |= 0x400u;
    value.x = *(float *)&v40[5].mNext;
    value.y = *(float *)&v40[6].mPrev;
    UFG::HistoryBuffer<UFG::qVector2>::Record(
      (UFG::HistoryBuffer<UFG::qVector2> *)&v3->m_SteeringNoise.tFrequency,
      &value);
    v41 = v3->m_SteeringNoise.tAmplitude;
    if ( v41 > 0.0 )
    {
      UFG::HistoryBuffer<UFG::qVector2>::GetValue(
        (UFG::HistoryBuffer<UFG::qVector2> *)&v3->m_SteeringNoise.tFrequency,
        &value,
        v41);
      *(float *)&v40[6].mPrev = value.y;
      *(float *)&v40[5].mNext = value.x;
    }
    if ( UFG::AiDriverComponent::m_CurrentDebugCar )
    {
      v42 = UFG::AiDriverComponent::m_CurrentDebugCar->m_Flags;
      if ( (v42 >> 14) & 1 )
      {
        v43 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)UFG::AiDriverComponent::m_CurrentDebugCar);
      }
      else if ( (v42 & 0x8000u) == 0 )
      {
        if ( (v42 >> 13) & 1 )
        {
          v43 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)UFG::AiDriverComponent::m_CurrentDebugCar,
                                            UFG::AiDriverComponent::_TypeUID);
        }
        else if ( (v42 >> 12) & 1 )
        {
          v43 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)UFG::AiDriverComponent::m_CurrentDebugCar,
                                            UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v43 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                            UFG::AiDriverComponent::m_CurrentDebugCar,
                                            UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        v43 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)UFG::AiDriverComponent::m_CurrentDebugCar);
      }
      if ( v43 )
      {
        if ( LOBYTE(v43->m_pRoadSpace.m_pSimComponent[8].m_Flags) )
          Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v43->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext);
      }
    }
    goto LABEL_96;
  }
}

// File Line: 2701
// RVA: 0x6579C0
bool __fastcall UFG::AiDriverComponent::PopulateVehicleOccupants(UFG::AiDriverComponent *this)
{
  UFG::SimObjectCharacter *v1; // rax
  UFG::AiDriverComponent *v2; // rbp
  UFG::SimObjectVehicle *v3; // rsi
  UFG::SceneObjectProperties *v4; // rax
  UFG::qPropertySet *v5; // rbx
  UFG::qPropertyList *v6; // r14
  UFG::qPropertyList *v7; // r15
  UFG::PedSpawnManager *v8; // rax
  UFG::qPropertySet *v9; // rax
  unsigned int *v10; // rax
  unsigned int v11; // ebx
  unsigned int v12; // edi
  UFG::SimObject *v13; // rax
  UFG::VehicleOccupantComponent *v14; // rbp
  UFG::PedSpawnManager *v15; // rax
  UFG::SimObjectCharacter *v16; // rax

  LOBYTE(v1) = UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame;
  v2 = this;
  if ( UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame )
  {
    --UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame;
    v3 = (UFG::SimObjectVehicle *)this->m_pSimObject;
    v4 = v3->m_pSceneObj;
    v5 = v4->mpWritableProperties;
    if ( !v5 )
      v5 = v4->mpConstProperties;
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           v5,
           (UFG::qSymbol *)&qSymbol_VehiclePriorityClassList.mUID,
           DEPTH_RECURSE);
    v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           v5,
           (UFG::qSymbol *)&qSymbol_VehicleExclusionClassList.mUID,
           DEPTH_RECURSE);
    v8 = UFG::PedSpawnManager::GetInstance();
    v1 = (UFG::SimObjectCharacter *)UFG::PedSpawnManager::GetAmbientPedForVehicle(v8, v6, v7, 0i64);
    if ( v1 )
    {
      v2->m_AmbientDriverType = 2;
      UFG::VehicleUtility::PlaceCharacterInVehicle(v1, v3, eTARGET_TYPE_VEHICLE_DRIVER, 0, 1, 0);
      v9 = UFG::SceneObjectProperties::GetWritableProperties(v3->m_pSceneObj);
      v10 = UFG::qPropertySet::Get<unsigned long>(
              v9,
              (UFG::qSymbol *)&qSymbol_AmbientPassengerCount.mUID,
              DEPTH_RECURSE);
      v11 = 0;
      v12 = 0;
      if ( v10 )
      {
        v12 = *v10;
        v13 = v2->m_pSimObject;
        v14 = (UFG::VehicleOccupantComponent *)(v13 ? v13->m_Components.p[30].m_pComponent : 0i64);
        if ( v12 > (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfSeats(v14) - 1 )
          v12 = (unsigned __int64)UFG::VehicleOccupantComponent::GetNumberOfSeats(v14) - 1;
      }
      if ( v12 )
      {
        do
        {
          v15 = UFG::PedSpawnManager::GetInstance();
          v16 = (UFG::SimObjectCharacter *)UFG::PedSpawnManager::GetAmbientPedForVehicle(v15, v6, v7, 0i64);
          if ( !v16 )
            break;
          UFG::VehicleUtility::PlaceCharacterInVehicle(v16, v3, (UFG::eTargetTypeEnum)(v11++ + 5), 0, 1, 0);
        }
        while ( v11 < v12 );
      }
      LOBYTE(v1) = 1;
    }
  }
  return (char)v1;
}

// File Line: 2782
// RVA: 0x64AAD0
char __fastcall UFG::AiDriverComponent::DepopulateVehicleOccupants(UFG::AiDriverComponent *this)
{
  UFG::SimObject *v1; // rax
  UFG::VehicleOccupantComponent *v2; // rcx

  v1 = this->m_pSimObject;
  this->m_AmbientDriverType = 1;
  if ( !v1 )
    return 0;
  v2 = (UFG::VehicleOccupantComponent *)v1->m_Components.p[30].m_pComponent;
  if ( !v2 )
    return 0;
  UFG::VehicleOccupantComponent::DeleteAllOccupants(v2);
  return 1;
}

// File Line: 2817
// RVA: 0x64F570
float __fastcall UFG::AiDriverComponent::GetSpeedForNextGuide(UFG::AiDriverComponent *this, float desiredSpeed)
{
  UFG::SimComponent *v2; // rbx
  float v3; // xmm6_4
  UFG::AiDriverComponent *v4; // rsi
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **v5; // rdi
  UFG::RoadNetworkLane *v6; // rcx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **v7; // rax
  float v8; // xmm8_4
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v9; // r8
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  bool v12; // zf
  UFG::SimObjectGame *v13; // rcx
  float v14; // xmm7_4
  float v15; // xmm0_4
  UFG::LinearGraph<float> *v16; // rcx
  float v17; // xmm8_4
  float v18; // xmm0_4
  float v19; // xmm7_4

  v2 = this->m_pRoadSpace.m_pSimComponent;
  v3 = FLOAT_3_4028235e38;
  v4 = this;
  if ( LOBYTE(v2[8].m_Flags) )
  {
    v5 = *(UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> ***)&v2[8].m_TypeUID;
    if ( v5 )
    {
      v8 = *(float *)&v2[7].m_BoundComponentHandles.mNode.mNext;
    }
    else
    {
      v6 = (UFG::RoadNetworkLane *)v2[7].m_SafePointerList.mNode.mPrev;
      if ( !v6 )
        return v3;
      v7 = UFG::RoadNetworkLane::GetClosestCarToStart(v6);
      v5 = v7;
      if ( !v7 )
        return v3;
      v8 = UFG::RoadNetworkGuide::GetGap(
             (UFG::RoadNetworkGuide *)&v2[5].m_BoundComponentHandles.mNode.mNext,
             (UFG::RoadNetworkGuide *)v7);
    }
    v9 = v5[9];
    if ( v9 )
    {
      v10 = WORD2(v9[4].mNext);
      if ( !((v10 >> 14) & 1) )
      {
        if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
            return v3;
          v12 = ((v10 >> 12) & 1) == 0;
          v13 = (UFG::SimObjectGame *)v5[9];
          if ( v12 )
            v11 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v13->vfptr,
                    UFG::PhysicsMoverInterface::_TypeUID);
          else
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::PhysicsMoverInterface::_TypeUID);
        }
        else
        {
          v11 = (UFG::SimComponent *)v9[6].mNext[34].mPrev;
        }
        if ( v11 )
        {
          v14 = *((float *)&v11[10].m_BoundComponentHandles.mNode.mPrev + 1);
          if ( v14 <= desiredSpeed
            || *((float *)&v4->mMoverComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1) == 0.0
            && v14 < 0.001 )
          {
            v15 = UFG::LinearGraph<float>::GetValue(v4->m_CarGapGraph, v14);
            v16 = v4->m_BrakingGraph;
            v17 = v8 - v15;
            if ( v17 < v16->fDomain[v16->nData - 1] )
            {
              v18 = UFG::LinearGraph<float>::GetValue(v16, v17);
              v19 = v14 - 5.0;
              if ( v18 <= v19 )
                v18 = v19;
              if ( v18 < desiredSpeed )
                v3 = v18;
            }
          }
        }
      }
    }
  }
  return v3;
}

// File Line: 2879
// RVA: 0x64F710
float __fastcall UFG::AiDriverComponent::GetSpeedForStopPoint(UFG::AiDriverComponent *this, float desiredSpeed)
{
  UFG::SimComponent *v2; // rbx
  float v3; // xmm6_4
  UFG::AiDriverComponent *v4; // rdi
  float v5; // xmm7_4
  float result; // xmm0_4
  float v7; // xmm1_4
  UFG::LinearGraph<float> *v8; // rcx
  float v9; // xmm0_4

  v2 = this->m_pRoadSpace.m_pSimComponent;
  v3 = FLOAT_3_4028235e38;
  v4 = this;
  v5 = desiredSpeed;
  if ( !LOBYTE(v2[8].m_Flags)
    || !UFG::RoadNetworkGuide::GetNextConnection((UFG::RoadNetworkGuide *)&v2[5].m_BoundComponentHandles.mNode.mNext) )
  {
    return v3;
  }
  result = 0.0;
  if ( v2[7].m_SafePointerList.mNode.mPrev )
  {
    v7 = *((float *)&v2[7].m_BoundComponentHandles.mNode.mNext + 1);
    if ( v7 >= 0.0 )
    {
      v8 = v4->m_BrakingGraph;
      if ( v7 < v8->fDomain[v8->nData - 1] )
      {
        v9 = UFG::LinearGraph<float>::GetValue(v8, v7);
        if ( v9 < v5 )
          v3 = v9;
      }
      return v3;
    }
  }
  return result;
}

// File Line: 2933
// RVA: 0x660D10
void __fastcall UFG::AiDriverComponent::UpdateDesiredSpeed(UFG::AiDriverComponent *this, float seconds)
{
  UFG::SimComponent *v2; // rdx
  float v3; // xmm3_4
  float v4; // xmm7_4
  UFG::AiDriverComponent *v5; // rdi
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm6_4
  int v10; // xmm0_4
  float v11; // xmm0_4
  char v12; // bl
  char v13; // al
  float v14; // xmm1_4
  float v15; // xmm0_4
  __int64 v16; // rax
  UFG::SimComponent *v17; // rcx
  UFG::SimObject *v18; // rbx
  float v19; // xmm1_4
  __m128 v20; // xmm0
  float v21; // xmm2_4
  float *v22; // rsi
  UFG::TransformNodeComponent *v23; // rbx
  float v24; // xmm7_4
  UFG::VehicleSubjectComponent *v25; // rcx
  float v26; // xmm8_4
  bool v27; // al
  UFG::SimComponent *v28; // rax
  float *v29; // rcx
  bool v30; // zf
  float *v31; // rax
  UFG::SimComponent *v32; // rcx
  __m128 v33; // xmm2
  float v34; // xmm8_4
  UFG::VehicleSubjectComponent *v35; // rcx
  float v36; // xmm7_4
  bool v37; // al
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v38; // rax
  float v39; // xmm1_4
  float v40; // xmm0_4

  v2 = this->m_pRoadSpace.m_pSimComponent;
  v3 = this->m_fDesiredSpeed;
  v4 = FLOAT_16_6;
  v5 = this;
  this->m_fDesiredSpeed = 0.0;
  this->m_RoadSpeedLimit = -1.0;
  v6 = seconds;
  if ( v2 && v2 != (UFG::SimComponent *)-376i64 && LOBYTE(v2[8].m_Flags) )
    v4 = *(float *)(&v2[7].m_SimObjIndex + 1);
  v7 = FLOAT_35_0;
  if ( !this->m_bRespectSpeedLimit )
    v4 = FLOAT_35_0;
  v8 = this->m_RoadSpeedLimitScale;
  v9 = 0.0;
  if ( v8 >= 0.0 )
    v4 = v4 * v8;
  v10 = SLODWORD(this->m_fDelayedStopDecel);
  if ( *(float *)&v10 >= 0.0 )
  {
    switch ( this->m_DrivingMode )
    {
      case 1u:
        v12 = UFG::SimObjectUtility::IsClassType(this->m_pSimObject, (UFG::qSymbol *)&qSymbol_Taxi.mUID);
        v13 = UFG::VehicleUtility::IsPlayerPassengerOfVehicle(v5->m_pSimObject);
        if ( v12 && v13 )
          goto $LN3_62;
        v5->m_RoadSpeedLimit = v4;
        v14 = v4;
        goto LABEL_21;
      case 2u:
        this->m_RoadSpeedLimit = v4;
        this->m_fDesiredSpeed = UFG::AiDriverComponent::GetSpeedFromRoad(this, v4);
        if ( v5->m_GoToSlowDownForDestination )
        {
          v16 = ((__int64 (*)(void))v5->m_pVehicleSubject.m_pSimComponent->vfptr[17].__vecDelDtor)();
          v17 = v5->m_pRoadSpace.m_pSimComponent;
          v18 = v5->m_PathingTarget.m_pPointer;
          v19 = *(float *)&v17[25].m_BoundComponentHandles.mNode.mPrev;
          v20 = (__m128)HIDWORD(v17[25].m_BoundComponentHandles.mNode.mPrev);
          v21 = *(float *)&v17[25].m_BoundComponentHandles.mNode.mNext;
          v22 = (float *)v16;
          if ( v18 )
          {
            v23 = v18->m_pTransformNodeComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform(v23);
            v19 = v23->mWorldTransform.v3.x;
            v20 = (__m128)LODWORD(v23->mWorldTransform.v3.y);
            v21 = v23->mWorldTransform.v3.z;
          }
          v20.m128_f32[0] = (float)((float)((float)(v20.m128_f32[0] - v22[1]) * (float)(v20.m128_f32[0] - v22[1]))
                                  + (float)((float)(v19 - *v22) * (float)(v19 - *v22)))
                          + (float)((float)(v21 - v22[2]) * (float)(v21 - v22[2]));
          v24 = COERCE_FLOAT(_mm_sqrt_ps(v20)) - v5->m_StopDist;
          if ( v24 < 0.0 )
            v24 = 0.0;
          v25 = (UFG::VehicleSubjectComponent *)v5->m_pVehicleSubject.m_pSimComponent;
          if ( v25 )
            v26 = UFG::VehicleSubjectComponent::GetMass(v25);
          else
            v26 = FLOAT_2000_0;
          v27 = UFG::AiDriverComponent::IsBoat(v5);
          v5->m_fDesiredSpeed = UFG::GetBrakingSpeedLimit(v24, v5->m_fDesiredSpeed, v26, v27);
        }
        break;
      case 3u:
      case 4u:
      case 7u:
        v15 = UFG::AiDriverComponent::UpdateChaseSpeed(this, v6, v10);
        v28 = v5->m_pRoadSpace.m_pSimComponent;
        if ( BYTE4(v28[30].m_SafePointerList.mNode.mNext) && *((_BYTE *)&v28[1].m_SimObjIndex + 2)
          || LOBYTE(v28[8].m_Flags) )
        {
          v29 = (float *)&UFG::AiDriverComponent::m_TopSpeed;
          v5->m_RoadSpeedLimit = v4;
          if ( v5->m_fChaseSpeedLimit >= 0.0 )
            v29 = &v5->m_fChaseSpeedLimit;
          if ( v15 <= *v29 )
            v15 = *v29;
          v14 = v15;
LABEL_21:
          v15 = UFG::AiDriverComponent::GetSpeedFromRoad(v5, v14);
        }
        v5->m_fDesiredSpeed = v15;
        break;
      case 5u:
        v30 = this->m_StopInfo.eStopStyle == 1;
        this->m_fDesiredSpeed = 35.0;
        if ( !v30 )
        {
          v31 = (float *)((__int64 (*)(void))this->m_pVehicleSubject.m_pSimComponent->vfptr[17].__vecDelDtor)();
          v32 = v5->m_pRoadSpace.m_pSimComponent;
          v33 = (__m128)HIDWORD(v32[25].m_BoundComponentHandles.mNode.mPrev);
          v33.m128_f32[0] = (float)((float)((float)(v33.m128_f32[0] - v31[1]) * (float)(v33.m128_f32[0] - v31[1]))
                                  + (float)((float)(*(float *)&v32[25].m_BoundComponentHandles.mNode.mPrev - *v31)
                                          * (float)(*(float *)&v32[25].m_BoundComponentHandles.mNode.mPrev - *v31)))
                          + (float)((float)(*(float *)&v32[25].m_BoundComponentHandles.mNode.mNext - v31[2])
                                  * (float)(*(float *)&v32[25].m_BoundComponentHandles.mNode.mNext - v31[2]));
          v34 = COERCE_FLOAT(_mm_sqrt_ps(v33)) - v5->m_StopDist;
          if ( v34 < 0.0 )
            v34 = 0.0;
          v35 = (UFG::VehicleSubjectComponent *)v5->m_pVehicleSubject.m_pSimComponent;
          if ( v35 )
            v36 = UFG::VehicleSubjectComponent::GetMass(v35);
          else
            v36 = FLOAT_2000_0;
          v37 = UFG::AiDriverComponent::IsBoat(v5);
          v5->m_fDesiredSpeed = UFG::GetBrakingSpeedLimit(v34, v5->m_fDesiredSpeed, v36, v37);
        }
        break;
      case 6u:
        if ( v2 )
        {
          v38 = v2[26].m_SafePointerList.mNode.mNext;
          if ( v38 || (v38 = v2[26].m_SafePointerList.mNode.mPrev) != 0i64 )
          {
            if ( v38[1].mPrev )
            {
              if ( this->m_fRaceSpeedLimit >= 0.0 )
                v7 = this->m_fRaceSpeedLimit;
              this->m_fDesiredSpeed = v7;
            }
          }
        }
        this->m_fDesiredSpeed = (float)(UFG::AiDriverComponent::GetCatchupBoost(this) + 1.0) * this->m_fDesiredSpeed;
        break;
      default:
$LN3_62:
        v5->m_fDesiredSpeed = 0.0;
        break;
    }
    v39 = v5->m_DesiredSpeedLimit;
    if ( v39 >= 0.0 )
    {
      v40 = v5->m_fDesiredSpeed;
      if ( v40 >= v39 )
        v40 = v5->m_DesiredSpeedLimit;
      v5->m_fDesiredSpeed = v40;
    }
  }
  else
  {
    v11 = (float)(*(float *)&v10 * v6) + v3;
    if ( v11 >= 0.0 )
      v9 = v11;
    this->m_fDesiredSpeed = v9;
    if ( v9 < 1.0 )
    {
      if ( this->m_DrivingMode )
      {
        this->m_DrivingMode = 0;
        this->m_fReactionTime = 0.0;
        this->m_fDelayedStopDecel = 0.0;
        this->mModeSteeringLockEnabled = 0;
        this->mModeGasBrakeLockEnabled = 0;
        this->m_bIgnoreArrivalDirection = 0;
        if ( this->m_ResetStopDistOnStop )
          this->m_StopDist = 1.0;
      }
      this->m_fDelayedStopDecel = 0.0;
      this->m_fDesiredSpeed = 0.0;
    }
  }
}

// File Line: 3093
// RVA: 0x64F7B0
float __fastcall UFG::AiDriverComponent::GetSpeedFromRoad(UFG::AiDriverComponent *this, float speedLimit)
{
  UFG::SimComponent *v2; // rdi
  UFG::AiDriverComponent *v3; // rbx
  float v4; // xmm6_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4

  v2 = this->m_pRoadSpace.m_pSimComponent;
  v3 = this;
  v4 = speedLimit;
  *(_WORD *)&this->m_CappingSpeedForStopPoint = 0;
  if ( !v2 )
    return 0.0;
  if ( BYTE4(v2[30].m_SafePointerList.mNode.mNext) && *((_BYTE *)&v2[1].m_SimObjIndex + 2) )
  {
    v6 = v2[4].m_BoundComponentHandles.mNode.mNext;
    if ( !v6 || !LODWORD(v6->mNext) )
      return 0.0;
  }
  else if ( LOBYTE(v2[8].m_Flags) )
  {
    v7 = UFG::AiDriverComponent::GetRoadHolding(this);
    v8 = UFG::GetSpeedLimitForCurvature(*(float *)&v2[7].m_pSimObject, speedLimit, v7);
    v4 = v8;
    if ( v3->m_bRespectSpeedLimit )
    {
      if ( v3->m_ObeyTrafficLights )
      {
        v9 = UFG::AiDriverComponent::GetSpeedForStopPoint(v3, v8);
        if ( v9 < v4 )
        {
          v4 = v9;
          v3->m_CappingSpeedForStopPoint = 1;
        }
      }
      if ( !v3->m_bAllowedToPass && !v3->m_bTemporaryAllowedToPass )
      {
        v10 = UFG::AiDriverComponent::GetSpeedForNextGuide(v3, v4);
        if ( v10 < v4 )
        {
          v4 = v10;
          v3->m_CappingSpeedForNextGuide = 1;
        }
      }
    }
  }
  return v4;
}

// File Line: 3169
// RVA: 0x6639E0
void __fastcall UFG::AiDriverComponent::UpdateSpeed(UFG::AiDriverComponent *this, float seconds)
{
  UFG::AiDriverComponent *v2; // rsi
  float v3; // xmm7_4
  UFG::PhysicsMoverInterface *v4; // r14
  UFG::VehicleSubjectComponent *v5; // rcx
  bool v6; // r15
  UFG::PhysicsVehicle::Lod v7; // eax
  float v8; // xmm0_4
  bool v9; // bp
  float v10; // xmm10_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  UFG::SimComponent *v14; // rdi
  float *v15; // rbx
  float v16; // xmm0_4
  float v17; // xmm6_4
  UFG::SimComponent *v18; // rcx
  float *v19; // rax
  int v20; // eax
  bool v21; // bl
  float v22; // xmm0_4
  UFG::SimComponent *v23; // rcx
  float *v24; // rax
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  char v28; // dl
  float v29; // xmm3_4
  float v30; // xmm0_4
  int v31; // xmm0_4
  float v32; // xmm1_4
  int v33; // eax
  float v34; // xmm0_4
  UFG::RoadSpaceComponent *v35; // rax
  bool v36; // r10
  bool v37; // r8
  bool v38; // dl
  UFG::RoadNetworkLane *v39; // rax
  float v40; // xmm6_4
  int v41; // eax
  bool v42; // cl
  int v43; // eax

  v2 = this;
  v3 = seconds;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v4 = (UFG::PhysicsMoverInterface *)v2->mMoverComponent.m_pSimComponent;
  *((_DWORD *)&v4->mInput + 4) &= 0xFFFFFFFB;
  v5 = (UFG::VehicleSubjectComponent *)v2->m_pVehicleSubject.m_pSimComponent;
  v6 = v5 && UFG::VehicleSubjectComponent::IsBoat(v5);
  v7 = UFG::PhysicsMoverInterface::GetLOD((UFG::PhysicsMoverInterface *)v2->mMoverComponent.m_pSimComponent);
  v8 = v2->m_GettingUnstuckTimer;
  v9 = v7 != 3;
  v10 = *((float *)&v2->mMoverComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1);
  v2->m_fCurrentForwardSpeed = v10;
  if ( v8 >= 0.0 )
    v2->m_GettingUnstuckTimer = v8 + seconds;
  v11 = v2->m_BeenUnstuckTimer;
  if ( v11 >= 0.0 )
    v2->m_BeenUnstuckTimer = v11 + seconds;
  v12 = v2->m_fAvoidStopTimer;
  if ( v12 > 0.0 )
  {
    v2->m_fDesiredSpeed = 0.0;
    v2->m_fAvoidStopTimer = v12 - seconds;
    goto LABEL_38;
  }
  v13 = v2->m_fReverseTimer;
  if ( v13 > 0.0 )
  {
    v2->m_fReverseTimer = v13 - seconds;
    v14 = v2->m_pVehicleSubject.m_pSimComponent;
    v15 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v14->vfptr[24].__vecDelDtor)(v14);
    v16 = (float)(*v15 - *(float *)((__int64 (__fastcall *)(UFG::SimComponent *))v14->vfptr[23].__vecDelDtor)(v14))
        * 0.80000001;
    if ( v16 <= 2.0 )
    {
      v16 = FLOAT_2_0;
    }
    else
    {
      v17 = FLOAT_8_0;
      if ( v16 >= 8.0 )
      {
LABEL_17:
        v18 = v2->m_pVehicleSubject.m_pSimComponent;
        if ( v18
          && (v19 = (float *)((__int64 (*)(void))v18->vfptr[17].__vecDelDtor)(),
              (float)(v17 * v17) < (float)((float)((float)((float)(v2->m_vStuckPosition.y - v19[1])
                                                         * (float)(v2->m_vStuckPosition.y - v19[1]))
                                                 + (float)((float)(v2->m_vStuckPosition.x - *v19)
                                                         * (float)(v2->m_vStuckPosition.x - *v19)))
                                         + (float)((float)(v2->m_vStuckPosition.z - v19[2])
                                                 * (float)(v2->m_vStuckPosition.z - v19[2]))))
          || v2->m_fReverseTimer <= 0.0 )
        {
          *((_DWORD *)&v4->mInput + 4) &= 0xFFFFFFFE;
          *(_QWORD *)&v2->m_fSteeringNoiseAmplitude = 0i64;
          v2->m_fReverseTimer = 0.0;
        }
        else
        {
          v20 = *((_DWORD *)&v4->mInput + 4);
          v4->mInput.mSteering = 0.0;
          *((_DWORD *)&v4->mInput + 4) = v20 & 0xFFFFFFDF | 1;
          v2->m_fDesiredSpeed = -10.0;
        }
        goto LABEL_38;
      }
    }
    v17 = v16;
    goto LABEL_17;
  }
  v21 = v2->m_bAllowedToPass || v2->m_bTemporaryAllowedToPass;
  if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v2->vfptr[16].__vecDelDtor)(v2) && !v21
    || v2->m_bGasBrakeLock
    || v2->mModeGasBrakeLockEnabled
    || v2->m_fDesiredSpeed <= 1.0
    || v10 >= 0.2 )
  {
    v2->m_fStuckTimer = 0.0;
  }
  else
  {
    v22 = seconds + v2->m_fStuckTimer;
    v2->m_fStuckTimer = v22;
    if ( v22 > 3.0 )
    {
      v2->m_fStuckTimer = 0.0;
      v2->m_fReverseTimer = 3.0;
      UFG::AiDriverComponent::AddSteeringNoise(v2, UFG::AiDriverComponent::m_fSteeringNoiseReverse);
      v23 = v2->m_pVehicleSubject.m_pSimComponent;
      if ( v23 )
      {
        v24 = (float *)((__int64 (*)(void))v23->vfptr[17].__vecDelDtor)();
        v25 = v24[1];
        v26 = v24[2];
        v2->m_vStuckPosition.x = *v24;
        v2->m_vStuckPosition.y = v25;
        v2->m_vStuckPosition.z = v26;
      }
      v2->m_BeenUnstuckTimer = 0.0;
      if ( v2->m_GettingUnstuckTimer < 0.0 )
        v2->m_GettingUnstuckTimer = 0.0;
    }
  }
LABEL_38:
  if ( v2->m_BeenUnstuckTimer >= 9.0 )
  {
    v2->m_GettingUnstuckTimer = -1.0;
    v2->m_BeenUnstuckTimer = -1.0;
  }
  UFG::qPidControllerCore::Record(&v2->m_ThrottlePid, v2->m_fDesiredSpeed - v10, v3, 0i64);
  v27 = UFG::qPidControllerCore::GetOutput(&v2->m_ThrottlePid);
  v28 = 0;
  v29 = v3 * 10.0;
  if ( !v2->m_bGasBrakeLock )
  {
    if ( v2->mModeGasBrakeLockEnabled )
    {
      v4->mInput.mGasBrakes = v2->mModeGasBrakeLock;
      goto LABEL_90;
    }
    if ( v9 )
    {
      v30 = v27 * -0.5;
      if ( v30 <= -1.0 )
      {
        v30 = FLOAT_N1_0;
      }
      else if ( v30 >= 1.0 )
      {
        LODWORD(v4->mInput.mGasBrakes) = (_DWORD)FLOAT_1_0;
        goto LABEL_90;
      }
      v4->mInput.mGasBrakes = v30;
      goto LABEL_90;
    }
    v31 = LODWORD(v27) ^ _xmm[0];
    if ( *(float *)&v31 <= COERCE_FLOAT(LODWORD(v29) ^ _xmm[0]) )
      v31 = LODWORD(v29) ^ _xmm[0];
    if ( *(float *)&v31 >= v29 )
      *(float *)&v31 = v3 * 10.0;
    v32 = v2->m_fPreviousGasBrakes + *(float *)&v31;
    if ( v32 <= -1.0 )
    {
      v32 = FLOAT_N1_0;
    }
    else if ( v32 >= 1.0 )
    {
      v32 = *(float *)&FLOAT_1_0;
    }
    v33 = *((_DWORD *)&v4->mInput + 4);
    if ( v33 & 1 )
      v32 = v32 * -1.0;
    if ( v33 & 0x20 )
      v32 = FLOAT_N1_0;
    if ( v32 <= COERCE_FLOAT(COERCE_UNSIGNED_INT(1.0 - (float)((float)(v4->mInput.mSteering * v4->mInput.mSteering) * 0.2)) ^ _xmm[0]) )
      LODWORD(v32) = COERCE_UNSIGNED_INT(1.0 - (float)((float)(v4->mInput.mSteering * v4->mInput.mSteering) * 0.2)) ^ _xmm[0];
    LODWORD(v34) = LODWORD(v2->m_fDesiredSpeed) & _xmm;
    if ( v34 < 0.0099999998 && v32 <= 0.0 )
      v32 = 0.0;
    v35 = (UFG::RoadSpaceComponent *)v2->m_pRoadSpace.m_pSimComponent;
    v36 = v35->mGuide.m_Attached;
    v37 = v2->m_CappingSpeedForStopPoint || v2->m_CappingSpeedForNextGuide;
    v38 = v34 < 1.5 && COERCE_FLOAT(LODWORD(v10) & _xmm) < 1.5;
    v39 = v35->mGuide.m_CurrentLocation.m_CurrentLane;
    if ( v39 )
    {
      if ( v39->mNode.mOffset )
        LOBYTE(v39) = *(_WORD *)((char *)&v39->mNode.mOffset + v39->mNode.mOffset) == 1;
      else
        LOBYTE(v39) = (_WORD)MEMORY[0] == 1;
    }
    if ( !v6 && v36 && v37 && v38 && !(_BYTE)v39 )
    {
      v28 = 1;
      v32 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v28 = 0;
      if ( v6 )
      {
LABEL_89:
        v4->mInput.mGasBrakes = v32;
        goto LABEL_90;
      }
    }
    if ( v34 < 0.0099999998 && COERCE_FLOAT(LODWORD(v10) & _xmm) < 0.69999999 )
      v32 = *(float *)&FLOAT_1_0;
    goto LABEL_89;
  }
  v4->mInput.mGasBrakes = v2->m_fGasBrakeLock;
LABEL_90:
  if ( !v2->m_DrivingMode && v2->m_StopInfo.eStopStyle == 1 )
    *((_DWORD *)&v4->mInput + 4) |= 4u;
  v40 = v4->mInput.mGasBrakes;
  if ( *((_BYTE *)&v4->mInput + 16) & 4 || v40 > 0.99000001 )
    v2->m_fBrakeTimer = v3 + v2->m_fBrakeTimer;
  else
    v2->m_fBrakeTimer = 0.0;
  v41 = *((_DWORD *)&v4->mInput + 4);
  v42 = !(v41 & 0x20)
     && v2->m_fBrakeTimer > 1.0
     && COERCE_FLOAT(LODWORD(v2->m_fDesiredSpeed) & _xmm) < 0.1
     && COERCE_FLOAT(LODWORD(v10) & _xmm) < 2.0;
  if ( !(v41 & 4) && !v6 && v42 )
    *((_DWORD *)&v4->mInput + 4) = v41 | 4;
  if ( COERCE_FLOAT(LODWORD(v2->m_fDesiredSpeed) & _xmm) < 0.090000004 || v28 )
    v28 = 1;
  v43 = *((_DWORD *)&v4->mInput + 4);
  if ( !(v43 & 4) && v28 && v10 < 0.090000004 )
    *((_DWORD *)&v4->mInput + 4) = v43 | 4;
  if ( v42 )
  {
    *((_BYTE *)&v2->m_StopInfo + 8) &= 0xFEu;
    *(_QWORD *)&v2->m_StopInfo.eStopStyle = 0i64;
  }
  if ( v2->mRenderComponent.m_pSimComponent )
  {
    if ( v40 > 0.1
      || v2->m_fDesiredSpeed < 0.1
      || UFG::VehicleSubjectComponent::IsBike((UFG::VehicleSubjectComponent *)v2->m_pVehicleSubject.m_pSimComponent)
      && *((_BYTE *)&v4->mInput + 16) & 4 )
    {
      UFG::VehicleEffectsComponent::TurnOnBrakelights((UFG::VehicleEffectsComponent *)v2->mRenderComponent.m_pSimComponent);
    }
    else
    {
      UFG::VehicleEffectsComponent::TurnOffBrakelights((UFG::VehicleEffectsComponent *)v2->mRenderComponent.m_pSimComponent);
    }
  }
  if ( *((_BYTE *)&v4->mInput + 16) & 1 )
    v40 = v40 * -1.0;
  v2->m_fPreviousGasBrakes = v40;
}

// File Line: 3439
// RVA: 0x651020
bool __fastcall UFG::AiDriverComponent::GetUnstuckFailed(UFG::AiDriverComponent *this)
{
  return 22.0 < this->m_GettingUnstuckTimer;
}

// File Line: 3444
// RVA: 0x659970
void __fastcall UFG::AiDriverComponent::SetSteeringNoiseMin(UFG::AiDriverComponent *this, float min_amplitude)
{
  float v2; // xmm0_4

  this->m_fSteeringNoiseAmplitudeMin = min_amplitude;
  v2 = this->m_fSteeringNoiseAmplitude;
  if ( v2 <= min_amplitude )
    this->m_fSteeringNoiseAmplitude = min_amplitude;
  else
    this->m_fSteeringNoiseAmplitude = v2;
}

// File Line: 3450
// RVA: 0x644D90
void __fastcall UFG::AiDriverComponent::AddSteeringNoise(UFG::AiDriverComponent *this, float amplitude)
{
  float v2; // xmm0_4
  UFG::AiDriverComponent *v3; // rbx

  v2 = this->m_fSteeringNoiseAmplitude;
  v3 = this;
  if ( v2 < amplitude )
  {
    if ( v2 <= 0.0 )
    {
      this->m_fSteeringNoiseTimer = UFG::qRandom(511.0, &UFG::qDefaultSeed);
      UFG::qNoise<float,float>::SetFrequency(
        &v3->m_SteeringNoise,
        UFG::AiDriverComponent::m_fSteeringNoiseFrequency,
        0.0);
    }
    v3->m_fSteeringNoiseAmplitude = amplitude;
  }
}

// File Line: 3465
// RVA: 0x649950
void __fastcall UFG::AiDriverComponent::ClearSteeringNoise(UFG::AiDriverComponent *this)
{
  *(_QWORD *)&this->m_fSteeringNoiseAmplitude = 0i64;
}

// File Line: 3493
// RVA: 0x649940
void __fastcall UFG::AiDriverComponent::ClearSteeringLock(UFG::AiDriverComponent *this)
{
  this->m_bSteeringLock = 0;
}

// File Line: 3498
// RVA: 0x659930
void __fastcall UFG::AiDriverComponent::SetSteeringLock(UFG::AiDriverComponent *this, float steering_lock)
{
  this->m_bSteeringLock = 1;
  if ( steering_lock <= -1.0 )
  {
    steering_lock = FLOAT_N1_0;
  }
  else if ( steering_lock >= 1.0 )
  {
    LODWORD(this->m_fSteeringLock) = (_DWORD)FLOAT_1_0;
    return;
  }
  this->m_fSteeringLock = steering_lock;
}

// File Line: 3504
// RVA: 0x6498C0
void __fastcall UFG::AiDriverComponent::ClearGasBrakeLock(UFG::AiDriverComponent *this)
{
  this->m_bGasBrakeLock = 0;
}

// File Line: 3509
// RVA: 0x6594A0
void __fastcall UFG::AiDriverComponent::SetGasBrakeLock(UFG::AiDriverComponent *this, float gas_brake_lock)
{
  this->m_bGasBrakeLock = 1;
  if ( gas_brake_lock <= -1.0 )
  {
    gas_brake_lock = FLOAT_N1_0;
  }
  else if ( gas_brake_lock >= 1.0 )
  {
    LODWORD(this->m_fGasBrakeLock) = (_DWORD)FLOAT_1_0;
    return;
  }
  this->m_fGasBrakeLock = gas_brake_lock;
}

// File Line: 3515
// RVA: 0x658590
void __fastcall UFG::AiDriverComponent::SetAllowedToPass(UFG::AiDriverComponent *this, bool allowed_to_pass)
{
  if ( !this->m_RoadRuleFlagsLocked )
    this->m_bAllowedToPass = allowed_to_pass;
}

// File Line: 3523
// RVA: 0x659910
void __fastcall UFG::AiDriverComponent::SetStayOffSidewalk(UFG::AiDriverComponent *this, bool stay_off_sidewalk)
{
  if ( !this->m_RoadRuleFlagsLocked )
    this->m_bStayOffSidewalk = stay_off_sidewalk;
}

// File Line: 3531
// RVA: 0x6598E0
void __fastcall UFG::AiDriverComponent::SetRespectSpeedLimit(UFG::AiDriverComponent *this, bool respect_speed_limit)
{
  if ( !this->m_RoadRuleFlagsLocked )
    this->m_bRespectSpeedLimit = respect_speed_limit;
}

// File Line: 3539
// RVA: 0x659600
void __fastcall UFG::AiDriverComponent::SetObeyTrafficLights(UFG::AiDriverComponent *this, bool obeyTrafficLights)
{
  if ( !this->m_RoadRuleFlagsLocked )
    this->m_ObeyTrafficLights = obeyTrafficLights;
}

// File Line: 3547
// RVA: 0x6585B0
void __fastcall UFG::AiDriverComponent::SetAvoidPeds(UFG::AiDriverComponent *this, bool avoid_peds)
{
  if ( !this->m_RoadRuleFlagsLocked )
  {
    this->m_bAvoidPeds = avoid_peds;
    if ( !avoid_peds )
      this->m_fAvoidStopTimer = 0.0;
  }
}

// File Line: 3557
// RVA: 0x6585D0
void __fastcall UFG::AiDriverComponent::SetCanTurnAround(UFG::AiDriverComponent *this, bool can_turn_around)
{
  if ( !this->m_RoadRuleFlagsLocked )
    this->m_bCanTurnAround = can_turn_around;
}

// File Line: 3565
// RVA: 0x64C6E0
void __fastcall UFG::AiDriverComponent::EnableTemporaryPassing(UFG::AiDriverComponent *this)
{
  if ( !this->m_RoadRuleFlagsLocked )
    this->m_bTemporaryAllowedToPass = 1;
}

// File Line: 3576
// RVA: 0x6640C0
void __fastcall UFG::AiDriverComponent::UpdateSteering(UFG::AiDriverComponent *this, float seconds)
{
  UFG::qVector3 *v2; // rsi
  UFG::AiDriverComponent *v3; // rdi
  float v4; // xmm12_4
  Render::DebugDrawContext *v5; // r15
  float v6; // xmm0_4
  char v7; // r12
  float v8; // xmm0_4
  float v9; // xmm0_4
  UFG::VehicleSubjectComponent *v10; // rcx
  float v11; // xmm8_4
  bool v12; // r14
  bool v13; // bl
  float steer_to_distance; // xmm7_4
  UFG::qVector4 *v15; // rax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  UFG::SimObject *v28; // rax
  UFG::TransformNodeComponent *v29; // rbx
  float v30; // xmm13_4
  float v31; // xmm14_4
  float v32; // xmm9_4
  float *v33; // rax
  float v34; // xmm5_4
  __m128 v35; // xmm4
  float v36; // xmm6_4
  unsigned int v37; // eax
  __m128 v38; // xmm2
  float v39; // xmm3_4
  UFG::qVector3 *v40; // rax
  float v41; // xmm1_4
  float v42; // xmm0_4
  unsigned int v43; // ecx
  float v44; // xmm9_4
  float v45; // xmm10_4
  bool v46; // r13
  float v47; // xmm11_4
  UFG::SimComponent *v48; // rax
  bool v49; // al
  UFG::VehicleSubjectComponent *v50; // rcx
  bool v51; // bl
  UFG::VehicleSubjectComponent *v52; // rcx
  float v53; // xmm0_4
  UFG::qVector3 *v54; // rax
  float v55; // xmm1_4
  float v56; // xmm2_4
  bool v57; // zf
  UFG::VehicleSubjectComponent *v58; // rcx
  bool v59; // r9
  UFG::qVector3 *v60; // rax
  float v61; // xmm1_4
  float v62; // xmm2_4
  UFG::SimComponent *v63; // rcx
  bool v64; // r14
  bool v65; // r15
  bool v66; // bl
  bool v67; // si
  UFG::SimComponent *v68; // rcx
  bool v69; // cl
  bool v70; // al
  float v71; // xmm0_4
  UFG::qVector3 *v72; // rax
  float v73; // xmm1_4
  float v74; // xmm2_4
  Render::DebugDrawContext *v75; // rbx
  char v76; // si
  float v77; // xmm11_4
  char v78; // bl
  float v79; // xmm3_4
  float v80; // xmm4_4
  float v81; // xmm5_4
  char v82; // al
  bool v83; // dl
  bool v84; // cl
  float v85; // xmm1_4
  float v86; // xmm2_4
  float v87; // xmm1_4
  float v88; // xmm0_4
  UFG::PhysicsMoverInterface *v89; // rcx
  float v90; // xmm0_4
  float v91; // xmm7_4
  float v92; // xmm0_4
  float v93; // xmm9_4
  UFG::SimComponent *v94; // rbx
  float v95; // xmm0_4
  bool v96; // si
  __int64 v97; // rdx
  float v98; // xmm1_4
  float v99; // xmm0_4
  float v100; // xmm4_4
  float v101; // xmm3_4
  float v102; // xmm2_4
  float v103; // xmm6_4
  int v104; // ecx
  float v105; // xmm1_4
  float v106; // xmm0_4
  bool v107; // dl
  unsigned int v108; // er8
  char v109; // r9
  bool v110; // al
  char v111; // r8
  float v112; // xmm1_4
  float v113; // xmm2_4
  float v114; // xmm3_4
  float v115; // xmm0_4
  float v116; // xmm8_4
  UFG::SimComponent *v117; // rax
  float v118; // xmm6_4
  float v119; // xmm2_4
  float v120; // xmm0_4
  UFG::qVector3 v121; // [rsp+40h] [rbp-80h]
  float v122; // [rsp+4Ch] [rbp-74h]
  UFG::qVector3 result; // [rsp+50h] [rbp-70h]
  UFG::qVector3 p1; // [rsp+60h] [rbp-60h]
  UFG::qVector3 p0; // [rsp+70h] [rbp-50h]
  float speed_limit; // [rsp+140h] [rbp+80h]
  float constrained_by_road[2]; // [rsp+148h] [rbp+88h]
  bool v128; // [rsp+150h] [rbp+90h]
  Render::DebugDrawContext *v129; // [rsp+158h] [rbp+98h]

  v2 = (UFG::qVector3 *)&this->m_OffsetMover;
  v3 = this;
  v4 = seconds;
  UFG::DrivingTargetOffsetMover::Update(&this->m_OffsetMover, seconds);
  v5 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  v129 = v5;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v6 = v3->m_fPassingTimer;
  v7 = 0;
  if ( v6 > 0.0 )
  {
    v8 = v6 - seconds;
    v3->m_fPassingTimer = v8;
    if ( v8 <= 0.0 )
      v3->m_fPassingBias = 0.0;
  }
  v9 = v3->m_fSteeringNoiseAmplitudeMin;
  if ( v9 <= (float)((float)(1.0 - (float)(UFG::AiDriverComponent::m_fSteeringNoiseAmplitudeDecay * seconds))
                   * v3->m_fSteeringNoiseAmplitude) )
    v9 = (float)(1.0 - (float)(UFG::AiDriverComponent::m_fSteeringNoiseAmplitudeDecay * seconds))
       * v3->m_fSteeringNoiseAmplitude;
  v3->m_fSteeringNoiseAmplitude = v9;
  if ( v9 <= 0.001 )
  {
    v3->m_fSteeringNoiseAmplitude = 0.0;
  }
  else
  {
    v9 = seconds + v3->m_fSteeringNoiseTimer;
    v3->m_fSteeringNoiseTimer = v9;
  }
  v10 = (UFG::VehicleSubjectComponent *)v3->m_pVehicleSubject.m_pSimComponent;
  v11 = *((float *)&v3->mMoverComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1);
  v12 = v3->m_CurrentAttack != 7;
  LOBYTE(constrained_by_road[0]) = v3->m_CurrentAttack != 7;
  v13 = v10 && UFG::VehicleSubjectComponent::IsBoat(v10);
  steer_to_distance = FLOAT_5_0;
  if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v3->vfptr[16].__vecDelDtor)(v3) )
  {
    if ( v13 )
    {
      ((void (*)(void))v3->m_pVehicleSubject.m_pSimComponent->vfptr[21].__vecDelDtor)();
      if ( UFG::AiDriverComponent::m_SteerDistanceRampBoat.z >= UFG::AiDriverComponent::m_SteerDistanceRampBoat.w )
        v22 = UFG::AiDriverComponent::m_SteerDistanceRampBoat.w;
      else
        v22 = UFG::AiDriverComponent::m_SteerDistanceRampBoat.z;
      if ( UFG::AiDriverComponent::m_SteerDistanceRampBoat.z <= UFG::AiDriverComponent::m_SteerDistanceRampBoat.w )
        v23 = UFG::AiDriverComponent::m_SteerDistanceRampBoat.w;
      else
        v23 = UFG::AiDriverComponent::m_SteerDistanceRampBoat.z;
      v24 = FLOAT_0_000099999997;
      if ( (float)(UFG::AiDriverComponent::m_SteerDistanceRampBoat.y - UFG::AiDriverComponent::m_SteerDistanceRampBoat.x) >= 0.000099999997 )
        v24 = UFG::AiDriverComponent::m_SteerDistanceRampBoat.y - UFG::AiDriverComponent::m_SteerDistanceRampBoat.x;
      v25 = (float)((float)(v11 - UFG::AiDriverComponent::m_SteerDistanceRampBoat.x)
                  * (float)((float)(UFG::AiDriverComponent::m_SteerDistanceRampBoat.w
                                  - UFG::AiDriverComponent::m_SteerDistanceRampBoat.z)
                          / v24))
          + UFG::AiDriverComponent::m_SteerDistanceRampBoat.z;
      if ( v25 <= v22 )
        v25 = v22;
      if ( v25 >= v23 )
        v25 = v23;
      steer_to_distance = v25 + v9;
    }
  }
  else if ( v12 )
  {
    if ( v13 )
      steer_to_distance = FLOAT_10_0;
    else
      steer_to_distance = FLOAT_6_0;
  }
  else
  {
    v15 = &UFG::AiDriverComponent::m_SteerDistanceRamp;
    if ( v13 )
      v15 = &UFG::AiDriverComponent::m_SteerDistanceRampBoat;
    v16 = v15->w;
    v17 = v15->z;
    v18 = v15->x;
    if ( v17 >= v16 )
      v19 = v15->w;
    else
      v19 = v15->z;
    if ( v17 <= v16 )
      v20 = v15->w;
    else
      v20 = v15->z;
    v21 = FLOAT_0_000099999997;
    if ( (float)(v15->y - v18) >= 0.000099999997 )
      v21 = v15->y - v18;
    steer_to_distance = (float)((float)(v11 - v18) * (float)((float)(v16 - v17) / v21)) + v17;
    if ( steer_to_distance <= v19 )
      steer_to_distance = v19;
    if ( steer_to_distance >= v20 )
      steer_to_distance = v20;
  }
  v26 = *(float *)&FLOAT_1_0;
  if ( steer_to_distance <= 1.0 || (v27 = FLOAT_100_0, v26 = steer_to_distance, steer_to_distance < 100.0) )
    v27 = v26;
  *(float *)&v3->m_pRoadSpace.m_pSimComponent[8].vfptr = v27;
  v3->m_fAvoidSteerLimit = 0.0;
  if ( v3->m_bTemporaryAllowedToPass )
  {
    if ( v13 )
      v3->m_fAvoidSteerLimit = FLOAT_N1_0;
    else
      v3->m_fAvoidSteerLimit = UFG::AiDriverComponent::m_AvoidTemporaryLimit;
  }
  else if ( v3->m_bAllowedToPass )
  {
    v3->m_fAvoidSteerLimit = -1.0;
  }
  v28 = v3->m_pSimObject;
  if ( v28 )
    v29 = (UFG::TransformNodeComponent *)v28->m_Components.p[2].m_pComponent;
  else
    v29 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v29);
  v30 = v29->mWorldTransform.v3.x;
  v31 = v29->mWorldTransform.v3.y;
  v32 = v29->mWorldTransform.v3.z;
  v33 = (float *)((__int64 (*)(void))v3->m_pVehicleSubject.m_pSimComponent->vfptr[16].__vecDelDtor)();
  v34 = v33[1];
  v35 = (__m128)*(unsigned int *)v33;
  v36 = v33[2];
  v37 = v3->m_DrivingMode;
  v38 = v35;
  v38.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(v34 * v34)) + (float)(v36 * v36);
  v39 = steer_to_distance / COERCE_FLOAT(_mm_sqrt_ps(v38));
  result.x = (float)(v35.m128_f32[0] * v39) + v30;
  result.y = (float)(v34 * v39) + v31;
  result.z = (float)(v36 * v39) + v32;
  if ( v37 )
  {
    if ( v37 <= 4 )
    {
LABEL_63:
      v40 = UFG::RoadSpaceComponent::GetSteerTo(
              (UFG::RoadSpaceComponent *)v3->m_pRoadSpace.m_pSimComponent,
              &result,
              &result,
              v2->x,
              steer_to_distance);
LABEL_64:
      v41 = v40->y;
      v42 = v40->x;
      result.z = v40->z;
      result.y = v41;
      result.x = v42;
      goto LABEL_65;
    }
    if ( v37 == 5 )
    {
      v58 = (UFG::VehicleSubjectComponent *)v3->m_pVehicleSubject.m_pSimComponent;
      v59 = v58 && UFG::VehicleSubjectComponent::IsBoat(v58);
      v40 = UFG::RoadSpaceComponent::GetSteerToDestination(
              (UFG::RoadSpaceComponent *)v3->m_pRoadSpace.m_pSimComponent,
              &p1,
              steer_to_distance,
              v59,
              v3->m_StopAtUseDestinationDirection);
      goto LABEL_64;
    }
    if ( v37 != 6 )
    {
      if ( v37 != 7 )
        goto LABEL_65;
      goto LABEL_63;
    }
    v50 = (UFG::VehicleSubjectComponent *)v3->m_pVehicleSubject.m_pSimComponent;
    speed_limit = v3->m_fDesiredSpeed;
    v51 = v50 && UFG::VehicleSubjectComponent::IsBoat(v50);
    v52 = (UFG::VehicleSubjectComponent *)v3->m_pVehicleSubject.m_pSimComponent;
    if ( v52 )
      v53 = UFG::VehicleSubjectComponent::GetMass(v52);
    else
      v53 = FLOAT_2000_0;
    v54 = UFG::RoadSpaceComponent::GetSteerToRace(
            (UFG::RoadSpaceComponent *)v3->m_pRoadSpace.m_pSimComponent,
            &p0,
            steer_to_distance,
            &speed_limit,
            v53,
            v51);
    v55 = v54->y;
    v56 = v54->z;
    result.x = v54->x;
    result.y = v55;
    v57 = speed_limit == v3->m_fDesiredSpeed;
    result.z = v56;
    if ( !v57 )
      v3->m_fDesiredSpeed = speed_limit;
  }
LABEL_65:
  if ( v3->m_AvoidanceDebug )
  {
    p1.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + result.x;
    p1.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + result.z;
    p1.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + result.y;
    p0.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + v30;
    p0.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + v31;
    p0.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + v32;
    Render::DebugDrawContext::DrawLine(v5, &p0, &p1, &UFG::qColour::Yellow, &UFG::qMatrix44::msIdentity, 0i64, 0);
    p0.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + result.z;
    p0.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + result.x;
    p0.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + result.y;
    Render::DebugDrawContext::DrawSphere(v5, &p0, 0.5, &UFG::qColour::Yellow, &UFG::qMatrix44::msIdentity, 0i64);
  }
  v43 = v3->m_DrivingMode;
  v44 = result.x;
  v45 = result.y;
  v3->m_fFollowOffsetBlend = 0.0;
  v46 = v43 == 1;
  v47 = result.z;
  v128 = v43 == 2;
  if ( !((v43 - 3) & 0xFFFFFFFA) && v43 != 8 )
    v7 = 1;
  v48 = v3->m_pRoadSpace.m_pSimComponent;
  LOBYTE(speed_limit) = v43 == 6;
  v49 = BYTE4(v48[30].m_SafePointerList.mNode.mNext) && *((_BYTE *)&v48[1].m_SimObjIndex + 2) || LOBYTE(v48[8].m_Flags);
  if ( !v7 || v49 )
  {
    v3->m_fTimeNearOffset = 0.0;
  }
  else
  {
    v60 = UFG::AiDriverComponent::SteerToFollowOffset(v3, &result, v4, steer_to_distance, v2, &result);
    v61 = v60->y;
    v62 = v60->z;
    result.x = v60->x;
    result.y = v61;
    result.z = v62;
  }
  v63 = v3->m_pVehicleSubject.m_pSimComponent;
  v64 = v3->m_DrivingRole == 2;
  v65 = v3->m_pEscortEnemyVehicleSubject.m_pPointer != 0i64;
  v66 = v63 && ((unsigned __int8 (*)(void))v63->vfptr[30].__vecDelDtor)();
  v67 = v3->m_fFollowOffsetBlend > 0.0 && UFG::AiDriverComponent::m_fReactionTimeStart < v3->m_fTimeNearOffset;
  v68 = v3->m_pChaseVehicleSubject.m_pPointer;
  v69 = v68 && ((unsigned __int8 (*)(void))v68->vfptr[46].__vecDelDtor)();
  v70 = v3->m_DrivingMode == 3 && v3->m_DesiredOffset == 1;
  if ( (v66 || v64) && v69 && !v70 && !v65 && !LOBYTE(constrained_by_road[0]) && v67 )
  {
    v71 = v4 + v3->m_fReactionTime;
    if ( v71 >= UFG::AiDriverComponent::m_fReactionTimeMax )
      v71 = UFG::AiDriverComponent::m_fReactionTimeMax;
  }
  else
  {
    v71 = 0.0;
  }
  v3->m_fReactionTime = v71;
  if ( v46 )
  {
    v72 = UFG::AiDriverComponent::SteerToBetterLane(v3, &result, &result);
    v73 = v72->y;
    v74 = v72->z;
    result.x = v72->x;
    result.y = v73;
    result.z = v74;
  }
  if ( v3->m_AvoidanceDebug )
  {
    v75 = v129;
    p0.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + result.x;
    p0.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + result.z;
    p0.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + result.y;
    p1.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + v44;
    p1.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + v45;
    p1.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + v47;
    Render::DebugDrawContext::DrawLine(v129, &p1, &p0, &UFG::qColour::Lime, &UFG::qMatrix44::msIdentity, 0i64, 0);
    p0.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + result.z;
    p0.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + result.x;
    p0.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + result.y;
    Render::DebugDrawContext::DrawSphere(v75, &p0, 0.44999999, &UFG::qColour::Lime, &UFG::qMatrix44::msIdentity, 0i64);
  }
  v76 = 0;
  v57 = v3->m_DrivingMode == 3;
  v77 = steer_to_distance;
  LOBYTE(constrained_by_road[0]) = 0;
  *(float *)&v129 = steer_to_distance;
  if ( v57 )
  {
    UFG::AiDriverComponent::SteerToWithinRoad(v3, &p0, (bool *)constrained_by_road, &result);
    v76 = LOBYTE(constrained_by_road[0]);
    result = p0;
  }
  v78 = 0;
  if ( v3->m_AvoidObjectsEnabled )
  {
    constrained_by_road[0] = v3->m_fDesiredSpeed;
    UFG::AiDriverComponent::SteerToAvoidObjects(v3, &p0, &result, steer_to_distance);
    v79 = p0.x;
    v80 = p0.y;
    v81 = p0.z;
    if ( (float)((float)((float)((float)(result.y - p0.y) * (float)(result.y - p0.y))
                       + (float)((float)(result.x - p0.x) * (float)(result.x - p0.x)))
               + (float)((float)(result.z - p0.z) * (float)(result.z - p0.z))) > 0.010000001
      || constrained_by_road[0] != v3->m_fDesiredSpeed )
    {
      v78 = 1;
      if ( constrained_by_road[0] != v3->m_fDesiredSpeed )
        v3->m_fDesiredSpeed = constrained_by_road[0];
    }
    else
    {
      v78 = 0;
    }
    v77 = *(float *)&v129;
    result.x = v79;
    result.y = v80;
    result.z = v81;
  }
  v82 = 0;
  v83 = 0;
  if ( v7 )
    v82 = 1;
  if ( LOBYTE(speed_limit) )
    v82 = 1;
  v84 = v3->m_bAllowedToPass || v3->m_bTemporaryAllowedToPass;
  if ( (v46 || v128) && v84 )
    v82 = 1;
  if ( v3->m_AvoidGeoEnabled && v82 )
  {
    UFG::AiDriverComponent::SteerToAvoidGeometry(v3, &p0, &result, steer_to_distance);
    v77 = *(float *)&v129;
    v85 = (float)(result.x - p0.x) * (float)(result.x - p0.x);
    result = p0;
    v83 = (float)((float)((float)((float)(result.y - p0.y) * (float)(result.y - p0.y)) + v85)
                + (float)((float)(result.z - p0.z) * (float)(result.z - p0.z))) > 0.010000001;
  }
  if ( v78 || v83 || v76 )
    v3->m_fReactionTime = 0.0;
  v86 = result.x;
  v87 = result.y;
  v88 = result.z;
  v89 = (UFG::PhysicsMoverInterface *)v3->mMoverComponent.m_pSimComponent;
  v3->m_vSteerToPosition.x = result.x;
  v3->m_vSteerToPosition.y = v87;
  v121.z = v86 - v30;
  v3->m_vSteerToPosition.z = v88;
  v122 = v87 - v31;
  UFG::PhysicsMoverInterface::GetFacingDirection(v89, &v121);
  v90 = UFG::qAngleBetween((UFG::qVector2 *)&v121.z, (UFG::qVector2 *)&v121);
  v91 = v90;
  if ( v90 < -3.1415927 )
    v91 = v90 + 6.2831855;
  if ( v91 > 3.1415927 )
    v91 = v91 + -6.2831855;
  UFG::qPidControllerCore::Record(&v3->m_SteeringPid, v91, v4, 0i64);
  v92 = UFG::qPidControllerCore::GetOutput(&v3->m_SteeringPid);
  v93 = v92;
  if ( v3->m_fReverseTimer > 0.0 )
    v93 = v92 * -0.80000001;
  v94 = v3->mMoverComponent.m_pSimComponent;
  LODWORD(v94[1].m_pSimObject) &= 0xFFFFFFDF;
  if ( v3->m_bSteeringLock )
  {
    v94[1].m_TypeUID = LODWORD(v3->m_fSteeringLock);
    return;
  }
  if ( v3->mModeSteeringLockEnabled )
  {
    v94[1].m_TypeUID = LODWORD(v3->mModeSteeringLock);
    return;
  }
  if ( v3->m_DrivingMode || !(*((_BYTE *)&v3->m_StopInfo + 8) & 1) )
  {
    v96 = UFG::PhysicsMoverInterface::GetLOD((UFG::PhysicsMoverInterface *)v3->mMoverComponent.m_pSimComponent) == 3;
    ((void (__cdecl *)(UFG::SimComponent *, __int64))v3->m_pVehicleSubject.m_pSimComponent->vfptr[28].__vecDelDtor)(
      v3->m_pVehicleSubject.m_pSimComponent,
      v97);
    if ( v96 )
    {
      if ( v92 <= 0.30000001 && v3->m_fDesiredSpeed <= 0.30000001 )
        return;
    }
    else if ( v92 <= 0.30000001 )
    {
      return;
    }
    v98 = v3->m_fSteeringNoiseAmplitude;
    v99 = 0.0;
    if ( v98 <= 0.0 )
      v100 = v3->m_fSteeringNoiseAmplitude;
    else
      v100 = 0.0;
    if ( v98 >= 0.0 )
      v101 = v3->m_fSteeringNoiseAmplitude;
    else
      v101 = 0.0;
    v102 = *(float *)&FLOAT_1_0;
    v103 = (float)(COERCE_FLOAT(LODWORD(v11) & _xmm) - 1.0) * (float)(v98 * 0.25);
    if ( v103 <= v100 )
      v103 = v100;
    if ( v103 >= v101 )
      v103 = v101;
    if ( v103 != 0.0 )
    {
      v102 = *(float *)&FLOAT_1_0;
      v99 = UFG::qNoise<float,float>::GetValue(&v3->m_SteeringNoise, v3->m_fSteeringNoiseTimer) * v103;
    }
    v104 = (int)v94[1].m_pSimObject;
    if ( (v104 & 0x80u) != 0 )
      goto LABEL_195;
    if ( v96 )
      v105 = v3->m_fSteeringScale;
    else
      v105 = v102;
    v106 = (float)(v99 + v93) * v105;
    if ( v106 <= -1.0 )
    {
      v106 = FLOAT_N1_0;
    }
    else if ( v106 >= v102 )
    {
      goto LABEL_194;
    }
    v102 = v106;
LABEL_194:
    *(float *)&v94[1].m_TypeUID = v102;
LABEL_195:
    v107 = v3->m_bAllowedToPass || v3->m_bTemporaryAllowedToPass;
    v108 = v3->m_DrivingRole;
    v109 = 1;
    if ( v108 - 1 <= 2 || v108 == 5 )
      v107 = 1;
    else
      v109 = 0;
    v110 = v3->m_DrivingMode == 2 && v3->m_PathingTarget.m_pPointer;
    v111 = 0;
    v112 = (float)(UFG::AiDriverComponent::m_fBurnoutAngleFast * 3.1415927) * 0.0055555557;
    v113 = (float)(UFG::AiDriverComponent::m_fBurnoutAngleSlow * 3.1415927) * 0.0055555557;
    if ( v113 >= v112 )
      v114 = (float)(UFG::AiDriverComponent::m_fBurnoutAngleFast * 3.1415927) * 0.0055555557;
    else
      v114 = (float)(UFG::AiDriverComponent::m_fBurnoutAngleSlow * 3.1415927) * 0.0055555557;
    if ( v113 <= v112 )
      v115 = (float)(UFG::AiDriverComponent::m_fBurnoutAngleFast * 3.1415927) * 0.0055555557;
    else
      v115 = (float)(UFG::AiDriverComponent::m_fBurnoutAngleSlow * 3.1415927) * 0.0055555557;
    v116 = (float)((float)(v11 - 5.0) * (float)((float)(v112 - v113) * 0.06666667)) + v113;
    if ( v116 <= v114 )
      v116 = v114;
    if ( v116 >= v115 )
      v116 = v115;
    if ( v91 < COERCE_FLOAT(LODWORD(v116) ^ _xmm[0]) || v91 > v116 )
      v111 = 1;
    if ( v110 )
      v117 = v3->m_pRoadSpace.m_pSimComponent;
    if ( v109 && v111 )
      LODWORD(v94[1].m_pSimObject) = v104 | 0x20;
    if ( v107 )
    {
      v118 = FLOAT_2_0;
      if ( v77 >= 2.0 )
        v118 = v77;
      v119 = UFG::AiDriverComponent::GetRoadHolding(v3);
      v120 = UFG::GetSpeedLimitForCurvature(v91 / v118, v3->m_fDesiredSpeed, v119);
      if ( v120 != v3->m_fDesiredSpeed )
        v3->m_fDesiredSpeed = v120;
    }
    return;
  }
  v95 = v3->m_StopInfo.fSteeringOverride;
  if ( v95 <= -1.0 )
  {
    v95 = FLOAT_N1_0;
  }
  else if ( v95 >= 1.0 )
  {
    v94[1].m_TypeUID = (unsigned int)FLOAT_1_0;
    return;
  }
  *(float *)&v94[1].m_TypeUID = v95;
}m_pSimObject) = v104 | 0x20;
    if ( v107 )
    {
      v118 = FLOAT_2_0;
      if ( v77 >= 2.0 )
        v118 = v77;
      v119 = UFG::AiDriverComponent::GetRoadHolding(v3);
      v120 = UFG::GetSpeedLimitForCurvature(v91 / v118, v3->m_fDesiredSpeed, v119);
      if ( v120 != v3->m_fDesiredSpeed )
        v3->m_fDesiredSpeed = v120;
    }
    return;
  }
  v95

// File Line: 4008
// RVA: 0x65E5E0
UFG::qVector3 *__fastcall UFG::AiDriverComponent::SteerToWithinRoad(UFG::AiDriverComponent *this, UFG::qVector3 *result, bool *constrained_by_road, UFG::qVector3 *steer_to_position)
{
  UFG::qVector3 *v4; // r12
  UFG::qVector3 *v5; // rbx
  UFG::AiDriverComponent *v6; // r15
  UFG::SimObjectGame *v7; // rdi
  unsigned __int16 v8; // cx
  UFG::RoadSpaceComponent *v9; // rsi
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rcx
  unsigned int v12; // eax
  signed __int64 v13; // rcx
  char *v14; // rbp
  __int64 v15; // r13
  __int64 v16; // r14
  UFG::SimObject *v17; // rax
  UFG::TransformNodeComponent *v18; // rbp
  __int64 v19; // rdx
  UFG::RoadSpaceComponent *v20; // rcx
  float v21; // xmm1_4
  float v22; // xmm2_4
  unsigned __int16 v23; // cx
  UFG::SimComponent *v24; // rcx
  UFG::SimComponent *v25; // rax
  __int64 v26; // rax
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::qVector3 *v29; // rax
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  float v33; // xmm2_4
  UFG::qVector3 targetPos; // [rsp+20h] [rbp-48h]
  UFG::qVector3 resulta; // [rsp+30h] [rbp-38h]
  bool *v37; // [rsp+80h] [rbp+18h]

  v37 = constrained_by_road;
  *constrained_by_road = 0;
  v4 = steer_to_position;
  result->x = steer_to_position->x;
  v5 = result;
  result->y = steer_to_position->y;
  v6 = this;
  result->z = steer_to_position->z;
  v7 = (UFG::SimObjectGame *)this->m_pRoadSpace.m_pSimComponent[26].m_pSimObject;
  if ( !v7 )
    return result;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = (UFG::RoadSpaceComponent *)v7->m_Components.p[24].m_pComponent;
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RoadSpaceComponent::_TypeUID);
    }
    else if ( (v8 >> 12) & 1 )
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RoadSpaceComponent::_TypeUID);
    }
    else
    {
      v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RoadSpaceComponent::_TypeUID);
    }
    v9 = (UFG::RoadSpaceComponent *)v10;
  }
  else
  {
    v9 = (UFG::RoadSpaceComponent *)v7->m_Components.p[24].m_pComponent;
  }
  if ( !v9 )
    return v5;
  v11 = v6->m_pRoadSpace.m_pSimComponent;
  v12 = v11[25].m_TypeUID;
  v13 = (signed __int64)&v11[8].m_pSimObject;
  if ( v12 != v9->mWayClient.m_RoadNetworkType || v12 )
    return v5;
  v14 = (char *)&UFG::WheeledVehicleManager::m_Instance->m_NavigationData->m_TrafficGraph;
  if ( UFG::WheeledVehicleManager::m_Instance->m_NavigationData != (UFG::WheeledVehicleNavigationData *)-32i64 )
  {
    v15 = (*(unsigned __int16 (__fastcall **)(signed __int64, char *))(*(_QWORD *)v13 + 56i64))(v13, v14);
    v16 = v9->mWayClient.vfptr->GetWayEdge((UFG::WayFinderClient *)&v9->mWayClient.vfptr, (UFG::WayGraph *)v14);
    v17 = v6->m_pSimObject;
    if ( v17 )
      v18 = (UFG::TransformNodeComponent *)v17->m_Components.p[2].m_pComponent;
    else
      v18 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v18);
    v20 = (UFG::RoadSpaceComponent *)v6->m_pRoadSpace.m_pSimComponent;
    v21 = v18->mWorldTransform.v3.y;
    v22 = v18->mWorldTransform.v3.z;
    targetPos.x = v18->mWorldTransform.v3.x;
    targetPos.y = v21;
    targetPos.z = v22;
    if ( (_WORD)v15 == (_WORD)v16 )
    {
      v23 = v7->m_Flags;
      if ( (v23 >> 14) & 1 )
      {
        v24 = v7->m_Components.p[37].m_pComponent;
      }
      else if ( (v23 & 0x8000u) == 0 )
      {
        if ( (v23 >> 13) & 1 )
        {
          v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CameraSubject::_TypeUID);
        }
        else if ( (v23 >> 12) & 1 )
        {
          v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CameraSubject::_TypeUID);
        }
        else
        {
          v25 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::CameraSubject::_TypeUID);
        }
        v24 = v25;
      }
      else
      {
        v24 = v7->m_Components.p[31].m_pComponent;
      }
      v26 = ((__int64 (__cdecl *)(UFG::SimComponent *, __int64))v24->vfptr[17].__vecDelDtor)(v24, v19);
      v20 = v9;
      v27 = *(float *)(v26 + 4);
      v28 = *(float *)(v26 + 8);
      targetPos.x = *(float *)v26;
      targetPos.y = v27;
      targetPos.z = v28;
    }
    v29 = UFG::RoadSpaceComponent::ClampToRoad(v20, &resulta, v4, &targetPos);
    v30 = v29->x;
    v31 = v29->y;
    v32 = v29->z;
    v33 = (float)((float)((float)(v4->y - v31) * (float)(v4->y - v31))
                + (float)((float)(v4->x - v30) * (float)(v4->x - v30)))
        + (float)((float)(v4->z - v32) * (float)(v4->z - v32));
    if ( v33 >= 0.010000001 && v33 <= 64.0 )
    {
      v5->x = v30;
      v5->y = v31;
      v5->z = v32;
      *v37 = 1;
    }
  }
  return v5;
}

// File Line: 4073
// RVA: 0x65A280
char __fastcall UFG::AiDriverComponent::ShouldWaitForTarget(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // rbx
  float *v2; // rax
  float v3; // xmm15_4
  __int64 v4; // rax
  float v5; // xmm3_4
  __m128 v6; // xmm4
  float v7; // xmm5_4
  __m128 v8; // xmm2
  float v9; // xmm1_4
  int *v10; // rax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  float v15; // xmm14_4
  float *v16; // rax
  float v17; // xmm10_4
  float v18; // xmm8_4
  float v19; // xmm11_4
  __int64 v20; // rax
  float v21; // xmm3_4
  __m128 v22; // xmm4
  float v23; // xmm5_4
  __m128 v24; // xmm2
  float v25; // xmm6_4
  int *v26; // rax
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm8_4
  float v30; // xmm11_4
  float v31; // xmm2_4
  float v32; // xmm10_4
  float v33; // xmm8_4
  bool v34; // al
  char result; // al
  float v36; // [rsp+20h] [rbp-A8h]
  float v37; // [rsp+24h] [rbp-A4h]
  float v38; // [rsp+28h] [rbp-A0h]
  float v39; // [rsp+D0h] [rbp+8h]
  float v40; // [rsp+D8h] [rbp+10h]

  v1 = this;
  if ( !this->m_pVehicleSubject.m_pSimComponent || !this->m_pChaseVehicleSubject.m_pPointer )
    goto LABEL_26;
  v2 = (float *)((__int64 (*)(void))this->m_pVehicleSubject.m_pSimComponent->vfptr[17].__vecDelDtor)();
  v3 = *v2;
  v39 = v2[1];
  v40 = v2[2];
  v4 = ((__int64 (*)(void))v1->m_pVehicleSubject.m_pSimComponent->vfptr[20].__vecDelDtor)();
  v5 = *(float *)v4;
  v6 = (__m128)*(unsigned int *)(v4 + 4);
  v7 = *(float *)(v4 + 8);
  v8 = v6;
  v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
  if ( v8.m128_f32[0] <= 0.090000004 )
  {
    v10 = (int *)((__int64 (*)(void))v1->m_pVehicleSubject.m_pSimComponent->vfptr[16].__vecDelDtor)();
    v11 = *((float *)v10 + 1);
    v36 = *(float *)v10;
    v12 = *((float *)v10 + 2);
    v37 = v11;
    v38 = v12;
  }
  else
  {
    v9 = v8.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v8));
    v36 = v5 * v9;
    v37 = v6.m128_f32[0] * v9;
    v38 = v7 * v9;
  }
  v13 = v36;
  v14 = v37;
  v15 = v38;
  v16 = (float *)((__int64 (*)(void))v1->m_pChaseVehicleSubject.m_pPointer->vfptr[17].__vecDelDtor)();
  v17 = *v16;
  v18 = v16[1];
  v19 = v16[2];
  v20 = ((__int64 (*)(void))v1->m_pChaseVehicleSubject.m_pPointer->vfptr[20].__vecDelDtor)();
  v21 = *(float *)v20;
  v22 = (__m128)*(unsigned int *)(v20 + 4);
  v23 = *(float *)(v20 + 8);
  v24 = v22;
  v24.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v21 * v21)) + (float)(v23 * v23);
  if ( v24.m128_f32[0] <= 0.090000004 )
  {
    v26 = (int *)((__int64 (*)(void))v1->m_pChaseVehicleSubject.m_pPointer->vfptr[16].__vecDelDtor)();
    v27 = *((float *)v26 + 1);
    v36 = *(float *)v26;
    v28 = *((float *)v26 + 2);
    v37 = v27;
    v38 = v28;
  }
  else
  {
    v25 = v24.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
    v36 = v21 * v25;
    v37 = v22.m128_f32[0] * v25;
    v38 = v23 * v25;
  }
  v29 = v18 - v39;
  v30 = v19 - v40;
  v31 = v29 * v14;
  v32 = v17 - v3;
  v33 = (float)((float)(v29 * v29) + (float)(v32 * v32)) + (float)(v30 * v30);
  v34 = v33 >= 400.0 && v33 <= 6400.0;
  if ( (float)((float)(v31 + (float)(v32 * v13)) + (float)(v30 * v15)) < 0.0
    && (float)((float)((float)(v37 * v14) + (float)(v36 * v13)) + (float)(v38 * v15)) > 0.0
    && v34 )
  {
    result = 1;
  }
  else
  {
LABEL_26:
    result = 0;
  }
  return result;
}

// File Line: 4109
// RVA: 0x662150
void __fastcall UFG::AiDriverComponent::UpdateFollowingNavigation(UFG::AiDriverComponent *this, float delta_seconds)
{
  UFG::AiDriverComponent *v2; // r14
  UFG::SimObject *v3; // rax
  UFG::TransformNodeComponent *v4; // rcx
  char v5; // bl
  UFG::VehicleWayFinderClient *v6; // r15
  float v7; // xmm0_4
  UFG::SimComponent *v8; // rcx
  UFG::SimObjectGame *v9; // rbx
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // r13
  UFG::SimComponent *v12; // rax
  UFG::RoadSpaceComponent *v13; // rdi
  unsigned __int16 v14; // cx
  UFG::SimComponent *v15; // rcx
  UFG::SimComponent *v16; // rax
  float *v17; // rax
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float *v21; // rax
  char v22; // r12
  UFG::SimObject *v23; // rsi
  UFG::TransformNodeComponent *v24; // rsi
  unsigned __int16 v25; // cx
  __int64 v26; // rbx
  UFG::WayFinder *v27; // rax
  int v28; // eax
  UFG::SimComponent *v29; // rax
  UFG::SimComponent *v30; // rcx
  UFG::qVector3 *v31; // rbp
  UFG::qVector3 *v32; // rsi
  UFG::qVector3 *v33; // rdi
  UFG::qVector3 *v34; // rax
  float v35; // xmm2_4
  float v36; // xmm0_4
  float *v37; // rax
  int v38; // xmm1_4
  UFG::qVector3 *v39; // rdi
  float v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm5_4
  int v43; // xmm0_4
  float *v44; // rax
  int *v45; // rax
  UFG::SimComponent *v46; // rcx
  int v47; // xmm0_4
  int v48; // xmm2_4
  UFG::WayFinder *v49; // rbx
  int v50; // [rsp+30h] [rbp-68h]
  int v51; // [rsp+34h] [rbp-64h]
  int v52; // [rsp+38h] [rbp-60h]
  UFG::qVector3 goal_position; // [rsp+40h] [rbp-58h]
  bool v54; // [rsp+A0h] [rbp+8h]
  float closing_speed; // [rsp+B0h] [rbp+18h]
  __int64 v56; // [rsp+B8h] [rbp+20h]

  v2 = this;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v3 = v2->m_pSimObject;
  if ( v3 )
    v4 = (UFG::TransformNodeComponent *)v3->m_Components.p[2].m_pComponent;
  else
    v4 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  if ( UFG::AiDriverComponent::ShouldWaitForTarget(v2) )
  {
    v5 = 1;
    v2->mModeGasBrakeLock = 1.0;
    v2->mModeSteeringLock = 0.0;
  }
  else
  {
    v5 = 0;
  }
  v2->mModeSteeringLockEnabled = v5;
  v2->mModeGasBrakeLockEnabled = v5;
  v6 = (UFG::VehicleWayFinderClient *)&v2->m_pRoadSpace.m_pSimComponent[8].m_pSimObject;
  if ( v2->m_pVehicleSubject.m_pSimComponent
    && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)v2->m_pVehicleSubject.m_pSimComponent) )
  {
    v7 = FLOAT_100_0;
  }
  else
  {
    v7 = FLOAT_25_0;
  }
  v8 = v2->m_pRoadSpace.m_pSimComponent;
  if ( v7 < *((float *)&v8[29].m_pSimObject + 1) && !v5 )
  {
    v9 = (UFG::SimObjectGame *)v8[26].m_pSimObject;
    if ( !v9 )
      return;
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = v9->m_Components.p[24].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RoadSpaceComponent::_TypeUID);
      else
        v12 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::RoadSpaceComponent::_TypeUID);
      v11 = v12;
    }
    else
    {
      v11 = v9->m_Components.p[24].m_pComponent;
    }
    if ( !v11 )
      return;
    v13 = (UFG::RoadSpaceComponent *)v2->m_pRoadSpace.m_pSimComponent;
    if ( v13->m_NavGuideEnabled )
    {
      if ( !v13->m_NavGuide.m_Active )
        v13->m_NavGuide.m_Active = 1;
      v14 = v9->m_Flags;
      if ( (v14 >> 14) & 1 )
      {
        v15 = v9->m_Components.p[37].m_pComponent;
      }
      else if ( (v14 & 0x8000u) == 0 )
      {
        if ( (v14 >> 13) & 1 )
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CameraSubject::_TypeUID);
        }
        else if ( (v14 >> 12) & 1 )
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CameraSubject::_TypeUID);
        }
        else
        {
          v16 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::CameraSubject::_TypeUID);
        }
        v15 = v16;
      }
      else
      {
        v15 = v9->m_Components.p[31].m_pComponent;
      }
      v17 = (float *)((__int64 (*)(void))v15->vfptr[17].__vecDelDtor)();
      v18 = *v17;
      v19 = v17[1];
      v20 = v17[2];
      v21 = (float *)v2->m_pRoadSpace.m_pSimComponent;
      if ( (float)((float)((float)((float)(v21[413] - v19) * (float)(v21[413] - v19))
                         + (float)((float)(v21[412] - v18) * (float)(v21[412] - v18)))
                 + (float)((float)(v21[414] - v20) * (float)(v21[414] - v20))) > 9.0 )
      {
        v21[412] = v18;
        v21[413] = v19;
        v21[414] = v20;
        UFG::AiDriverComponent::BeginPathingNavigation(v2);
      }
      UFG::AiDriverComponent::UpdatePathingNavigation(v2);
      return;
    }
    v22 = 1;
    if ( v13->mGuide.m_Attached )
    {
      if ( 0 != v6->m_NumWayEdges )
      {
        v27 = UFG::GetWayFinder();
        if ( UFG::WayFinderClient::OnWay((UFG::WayFinderClient *)&v6->vfptr, v27->m_WayGraph) )
        {
          v28 = v6->m_NumWayEdges - 1;
          if ( v28 >= 0
            && v6 != (UFG::VehicleWayFinderClient *)-38i64
            && v6->m_WayEdges[v28] == LOWORD(v11[8].m_BoundComponentHandles.mNode.mPrev) )
          {
            v22 = 0;
LABEL_48:
            v54 = v2->m_fSearchTimer <= 0.0;
            if ( v22 && v2->m_fSearchTimer > 0.0 )
              v22 = 0;
            v25 = v9->m_Flags;
            if ( (v25 >> 14) & 1 )
            {
              v26 = (__int64)v9->m_Components.p[37].m_pComponent;
            }
            else if ( (v25 & 0x8000u) == 0 )
            {
              if ( (v25 >> 13) & 1 )
              {
                v29 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CameraSubject::_TypeUID);
              }
              else if ( (v25 >> 12) & 1 )
              {
                v29 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CameraSubject::_TypeUID);
              }
              else
              {
                v29 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::CameraSubject::_TypeUID);
              }
              v26 = (__int64)v29;
            }
            else
            {
              v26 = (__int64)v9->m_Components.p[31].m_pComponent;
            }
            v56 = v26;
            if ( v22 )
            {
              if ( !v2->m_pChaseVehicleSubject.m_pPointer )
                goto LABEL_98;
              if ( !((unsigned __int8 (*)(void))v2->m_pVehicleSubject.m_pSimComponent->vfptr[30].__vecDelDtor)() )
                goto LABEL_98;
              v30 = v2->m_pVehicleSubject.m_pSimComponent;
              closing_speed = 0.0;
              v31 = (UFG::qVector3 *)((__int64 (*)(void))v30->vfptr[17].__vecDelDtor)();
              v32 = (UFG::qVector3 *)((__int64 (*)(void))v2->m_pVehicleSubject.m_pSimComponent->vfptr[20].__vecDelDtor)();
              v33 = (UFG::qVector3 *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 136i64))(v26);
              v34 = (UFG::qVector3 *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 160i64))(v26);
              v35 = (float)((float)((float)(v33->y - v31->y)
                                  * *((float *)&v2->m_pRoadSpace.m_pSimComponent[27].m_pSimObject + 1))
                          + (float)((float)(v33->x - v31->x)
                                  * *(float *)&v2->m_pRoadSpace.m_pSimComponent[27].m_pSimObject))
                  + (float)((float)(v33->z - v31->z)
                          * *(float *)&v2->m_pRoadSpace.m_pSimComponent[27].m_BoundComponentHandles.mNode.mPrev);
              v36 = UFG::SoonestCloserThan(v31, v32, v33, v34, 30.0, &closing_speed);
              if ( v35 >= 0.0 )
                goto LABEL_98;
              if ( closing_speed < 0.0 && v36 >= 0.0 && v36 <= 6.0 )
              {
                v22 = 0;
              }
              else
              {
LABEL_98:
                if ( v54 )
                  v2->m_fSearchTimer = 0.5;
              }
            }
            v37 = (float *)(*(__int64 (**)(void))(*(_QWORD *)v56 + 136i64))();
            v38 = HIDWORD(v11[27].m_pSimObject);
            v39 = (UFG::qVector3 *)&v50;
            v40 = v37[1];
            v41 = v37[2];
            v42 = *v37;
            if ( v2->m_bIgnoreArrivalDirection )
              v39 = 0i64;
            v50 = (int)v11[27].m_pSimObject;
            v43 = (int)v11[27].m_BoundComponentHandles.mNode.mPrev;
            goal_position.x = v42;
            v52 = v43;
            goal_position.y = v40;
            goal_position.z = v41;
            v51 = v38;
            if ( v22
              || (v44 = (float *)v2->m_pRoadSpace.m_pSimComponent,
                  (float)((float)((float)((float)(v42 - v44[412]) * (float)(v42 - v44[412]))
                                + (float)((float)(v40 - v44[413]) * (float)(v40 - v44[413])))
                        + (float)((float)(v41 - v44[414]) * (float)(v41 - v44[414]))) > 9.0) )
            {
              v45 = &v50;
              if ( !v39 )
                v45 = (int *)&UFG::qVector3::msZero;
              v46 = v2->m_pRoadSpace.m_pSimComponent;
              *(float *)&v46[25].m_BoundComponentHandles.mNode.mPrev = v42;
              *((float *)&v46[25].m_BoundComponentHandles.mNode.mPrev + 1) = v40;
              *(float *)&v46[25].m_BoundComponentHandles.mNode.mNext = v41;
              v47 = v45[1];
              v48 = v45[2];
              HIDWORD(v46[25].m_BoundComponentHandles.mNode.mNext) = *v45;
              LODWORD(v46[26].vfptr) = v47;
              HIDWORD(v46[26].vfptr) = v48;
              if ( v22 )
              {
                v49 = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
                        UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                        v6);
                UFG::WayFinder::FindWay(v49, (UFG::WayFinderClient *)&v6->vfptr, &goal_position, v39);
                UFG::WayFinder::Service(v49, 0.0);
                if ( 0 != v6->m_NumWayEdges )
                  UFG::VehicleOccupantComponent::SetParkingSpot(
                    (UFG::RoadNetworkGuide *)&v2->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext,
                    0i64);
              }
            }
            if ( v6->m_NumWayEdges )
              UFG::AiDriverComponent::UpdateWayfindingNavigation(v2);
            else
              UFG::AiDriverComponent::UpdateWanderingNavigation(v2);
            return;
          }
        }
      }
    }
    else
    {
      v23 = v13->m_pSimObject;
      if ( v23 )
        v24 = v23->m_pTransformNodeComponent;
      else
        v24 = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v24);
      UFG::RoadSpaceComponent::AttachToRoadNetwork(v13, (UFG::qVector3 *)&v24->mWorldTransform.v3, 0i64);
    }
    v6->vfptr->ResetWay((UFG::WayFinderClient *)&v6->vfptr);
    goto LABEL_48;
  }
  if ( BYTE4(v8[30].m_SafePointerList.mNode.mNext) )
  {
    v2->m_fSearchTimer = 0.0;
    if ( v8 )
    {
      if ( *((_BYTE *)&v8[1].m_SimObjIndex + 2) )
        *((_BYTE *)&v8[1].m_SimObjIndex + 2) = 0;
      UFG::NavGuide::ClearPath((UFG::NavGuide *)&v2->m_pRoadSpace.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
    }
  }
  else if ( LOBYTE(v8[8].m_Flags) )
  {
    UFG::RoadNetworkGuide::RemoveFromNetwork((UFG::RoadNetworkGuide *)&v8[5].m_BoundComponentHandles.mNode.mNext);
    v2->m_fSearchTimer = 0.0;
    v6->vfptr->ResetWay((UFG::WayFinderClient *)&v6->vfptr);
  }
}

// File Line: 4294
// RVA: 0x645690
void __fastcall UFG::AiDriverComponent::BeginPathingNavigation(UFG::AiDriverComponent *this)
{
  UFG::RoadSpaceComponent *v1; // rax
  UFG::AiDriverComponent *v2; // rsi
  UFG::SimComponent *v3; // rbx
  UFG::SimObject *v4; // rdi

  v1 = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
  v2 = this;
  if ( !v1->m_NavGuide.m_Active )
    v1->m_NavGuide.m_Active = 1;
  v3 = this->m_pRoadSpace.m_pSimComponent;
  v4 = v3->m_pSimObject;
  if ( v4 )
    v4 = (UFG::SimObject *)v4->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
  UFG::NavGuide::FindPath(
    (UFG::NavGuide *)&v3[1].m_SafePointerList.mNode.mNext,
    (UFG::qVector3 *)v4[1].mNode.mChild,
    (UFG::qVector3 *)&v3[25].m_BoundComponentHandles,
    *(float *)&v3[5].m_SafePointerList.mNode.mNext);
  v2->m_fSearchTimer = 0.5;
}

// File Line: 4303
// RVA: 0x662D80
bool __fastcall UFG::AiDriverComponent::UpdatePathingNavigation(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *v1; // rbp
  UFG::AiDriverComponent *v2; // rdi
  UFG::NavGuide *v3; // rsi
  unsigned int v4; // eax
  bool v5; // cf
  bool v6; // zf
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::TransformNodeComponent *v8; // rbx
  int v9; // eax
  UFG::SimObject *v10; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  v1 = this->m_pRoadSpace.m_pSimComponent;
  v2 = this;
  v3 = (UFG::NavGuide *)&v1[1].m_SafePointerList.mNode.mNext;
  v4 = LODWORD(v1[1].m_pSimObject) - 1;
  v5 = v4 < 1;
  v6 = v4 == 1;
  v7 = v1[4].m_BoundComponentHandles.mNode.mNext;
  v8 = 0i64;
  if ( v7 )
    v9 = (int)v7->mNext;
  else
    v9 = 0;
  if ( !v5 && !v6 )
  {
    if ( !v9 )
      goto LABEL_16;
    v10 = this->m_pSimObject;
    if ( v10 )
      v8 = (UFG::TransformNodeComponent *)v10->m_Components.p[2].m_pComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v8);
    v1 = v2->m_pRoadSpace.m_pSimComponent;
    if ( (float)((float)((float)((float)(v8->mWorldTransform.v3.y
                                       - *((float *)&v1[25].m_BoundComponentHandles.mNode.mPrev + 1))
                               * (float)(v8->mWorldTransform.v3.y
                                       - *((float *)&v1[25].m_BoundComponentHandles.mNode.mPrev + 1)))
                       + (float)((float)(v8->mWorldTransform.v3.x - *(float *)&v1[25].m_BoundComponentHandles.mNode.mPrev)
                               * (float)(v8->mWorldTransform.v3.x - *(float *)&v1[25].m_BoundComponentHandles.mNode.mPrev)))
               + (float)((float)(v8->mWorldTransform.v3.z - *(float *)&v1[25].m_BoundComponentHandles.mNode.mNext)
                       * (float)(v8->mWorldTransform.v3.z - *(float *)&v1[25].m_BoundComponentHandles.mNode.mNext))) < (float)(v2->m_StopAtDist * v2->m_StopAtDist) )
      return v2->m_GoToStopAtEnabled;
    UFG::NavGuide::GetPathSegmentPos(v3, &result, v3->m_CurrPathPointIndex, &v3->m_Pos);
    if ( (float)((float)((float)((float)(v3->m_Pos.y - result.y) * (float)(v3->m_Pos.y - result.y))
                       + (float)((float)(v3->m_Pos.x - result.x) * (float)(v3->m_Pos.x - result.x)))
               + (float)((float)(v3->m_Pos.z - result.z) * (float)(v3->m_Pos.z - result.z))) >= 900.0 )
    {
LABEL_16:
      if ( v2->m_fSearchTimer <= 0.0 )
      {
        UFG::RoadSpaceComponent::FindPath((UFG::RoadSpaceComponent *)v1);
        v2->m_fSearchTimer = 0.5;
      }
    }
  }
  return 0;
}

// File Line: 4352
// RVA: 0x64C8E0
void __fastcall UFG::AiDriverComponent::EndPathingNavigation(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->m_pRoadSpace.m_pSimComponent;
  this->m_fSearchTimer = 0.0;
  if ( v1 )
  {
    if ( *((_BYTE *)&v1[1].m_SimObjIndex + 2) )
      *((_BYTE *)&v1[1].m_SimObjIndex + 2) = 0;
    UFG::NavGuide::ClearPath((UFG::NavGuide *)&this->m_pRoadSpace.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
  }
}

// File Line: 4365
// RVA: 0x665A60
void __fastcall UFG::AiDriverComponent::UpdateWayfindingNavigation(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // rsi
  UFG::SimObject *v2; // rax
  UFG::RoadNetworkGate *v3; // rdi
  UFG::TransformNodeComponent *v4; // rcx
  UFG::RoadNetworkGuide *v5; // rbp
  UFG::RoadNetworkLocation *v6; // r13
  UFG::RoadNetworkLane *v7; // rbx
  char *v8; // r14
  UFG::RoadSpaceComponent *v9; // r15
  int v10; // ecx
  UFG::VehicleWayFinderClient *v11; // r15
  float v12; // xmm0_4
  float *v13; // rax
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm0_4
  float *v20; // rax
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm8_4
  unsigned int v24; // edx
  unsigned int v25; // er13
  __int64 v26; // rax
  unsigned int v27; // edx
  UFG::RoadNetworkSegment *v28; // rax
  UFG::RoadNetworkNode *v29; // r12
  UFG::RoadNetworkLane *v30; // rax
  UFG::RoadNetworkLane *v31; // r14
  __int64 v32; // rax
  UFG::RoadNetworkConnection *v33; // r8
  __int64 v34; // rax
  _WORD *v35; // rcx
  UFG::RoadNetworkLane *v36; // rax
  UFG::RoadNetworkNode *v37; // rcx
  UFG::RoadNetworkSegment *v38; // rax
  UFG::RoadNetworkNode *v39; // rbx
  UFG::RoadNetworkLane *v40; // rax
  __int64 v41; // rax
  UFG::RoadNetworkLane *v42; // rax
  __int64 v43; // rax
  UFG::RoadNetworkGate *v44; // rcx
  UFG::RoadNetworkLane *v45; // rax
  __int64 v46; // rax
  UFG::RoadNetworkGate *v47; // rcx
  __int64 v48; // rcx
  UFG::RoadNetworkLane::LaneChangeDirection v49; // er14
  signed __int64 v50; // rcx
  __int64 v51; // rdx
  UFG::qVector3 pos; // [rsp+20h] [rbp-88h]
  UFG::qVector3 result; // [rsp+30h] [rbp-78h]
  float laneT; // [rsp+B0h] [rbp+8h]

  v1 = this;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v2 = v1->m_pSimObject;
  v3 = 0i64;
  if ( v2 )
    v4 = (UFG::TransformNodeComponent *)v2->m_Components.p[2].m_pComponent;
  else
    v4 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  v5 = (UFG::RoadNetworkGuide *)&v1->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext;
  v6 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v5);
  v7 = v6->m_CurrentLane;
  v8 = (char *)v7 + v7->mNode.mOffset;
  if ( !v7->mNode.mOffset )
    v8 = 0i64;
  v9 = (UFG::RoadSpaceComponent *)v1->m_pRoadSpace.m_pSimComponent;
  v10 = v9->mWayClient.m_CurrEdgeIndex;
  v11 = &v9->mWayClient;
  if ( v10 + 1 < v11->m_NumWayEdges )
  {
    if ( (unsigned __int8)UFG::RoadNetworkGuide::NavigationInfoNeeded(v5) )
    {
      UFG::RoadNetworkGuide::SetLaneAfterNext(v5, 0i64);
      v24 = v11->m_CurrEdgeIndex;
      v25 = v11->m_NumWayEdges - 1;
      if ( *((_DWORD *)v8 + 6) != v11->m_WayEdges[v24 + 1]
        || (v24 = (unsigned __int16)(v24 + 1), v11->m_CurrEdgeIndex = v24, v24 < v25) )
      {
        v26 = v24 + 1;
        v27 = v11->m_WayEdges[v26];
        laneT = *(float *)&v26;
        v28 = UFG::RoadNetworkResource::GetSegment(UFG::gpRoadNetworkResource, v27);
        v29 = (UFG::RoadNetworkNode *)&v28->mType;
        v30 = UFG::AiDriverComponent::FindNextWayfindLane(v1, v7, (UFG::RoadNetworkNode *)&v28->mType);
        v31 = v30;
        if ( v30 )
        {
          UFG::VehicleOccupantComponent::SetParkingSpot(v5, v30);
          v32 = v31->mNextConnection.mOffset;
          if ( v32 )
          {
            v33 = (UFG::RoadNetworkConnection *)((char *)&v31->mNextConnection + v32);
            if ( v33 )
            {
              v34 = v31->mNode.mOffset;
              v35 = (_WORD *)((char *)v31 + v31->mNode.mOffset);
              if ( !v31->mNode.mOffset )
                v35 = 0i64;
              if ( *v35 == 1 )
              {
                v36 = UFG::qBezierPathCollectionMemImaged::GetPath(v33, 0);
                if ( v36 )
                  UFG::RoadNetworkGuide::SetLaneAfterNext(v5, v36);
              }
              else
              {
                v37 = (UFG::RoadNetworkNode *)((char *)v31 + v34);
                if ( !v34 )
                  v37 = 0i64;
                if ( v37 == v29 && LODWORD(laneT) < v25 )
                {
                  v38 = UFG::RoadNetworkResource::GetSegment(
                          UFG::gpRoadNetworkResource,
                          v11->m_WayEdges[LODWORD(laneT) + 1]);
                  v39 = (UFG::RoadNetworkNode *)&v38->mType;
                  v40 = UFG::AiDriverComponent::FindNextWayfindLane(v1, v31, (UFG::RoadNetworkNode *)&v38->mType);
                  if ( v40 )
                    goto LABEL_59;
                  v41 = v31->mEndGate.mOffset;
                  if ( v41 )
                    v3 = (UFG::RoadNetworkGate *)((char *)&v31->mEndGate + v41);
                  v42 = UFG::RoadNetworkGate::GetFirstOutgoingLaneLeadingToNode(v3, v39);
                  if ( v42 )
                  {
                    v40 = UFG::AiDriverComponent::FindNextWayfindLane(v1, v42, v39);
                    if ( v40 )
LABEL_59:
                      UFG::RoadNetworkGuide::SetLaneAfterNext(v5, v40);
                  }
                }
              }
            }
          }
        }
        else
        {
          v43 = v7->mEndGate.mOffset;
          if ( v43 )
            v44 = (UFG::RoadNetworkGate *)((char *)&v7->mEndGate + v43);
          else
            v44 = 0i64;
          v45 = UFG::RoadNetworkGate::GetFirstOutgoingLaneLeadingToNode(v44, v29);
          if ( !v45 )
          {
            v46 = v7->mStartGate.mOffset;
            if ( v46 )
              v47 = (UFG::RoadNetworkGate *)((char *)&v7->mStartGate + v46);
            else
              v47 = 0i64;
            v45 = UFG::RoadNetworkGate::GetFirstOutgoingLaneLeadingToNode(v47, v29);
          }
          v48 = v45->mStartGate.mOffset;
          v49 = 1;
          if ( v48 )
            v50 = (signed __int64)&v45->mStartGate + v48;
          else
            v50 = 0i64;
          v51 = v7->mStartGate.mOffset;
          if ( v51 )
            v3 = (UFG::RoadNetworkGate *)((char *)&v7->mStartGate + v51);
          if ( (UFG::RoadNetworkGate *)v50 == v3 )
            v49 = (unsigned int)UFG::RoadNetworkLane::GetLaneDirection(v7, v45);
          UFG::AiDriverComponent::ChangeLane(v1, v49);
        }
      }
    }
  }
  else
  {
    v12 = UFG::RoadNetworkLane::GetLength(v7);
    v13 = (float *)v1->m_pRoadSpace.m_pSimComponent;
    v14 = v13[413];
    v15 = v13[414];
    v16 = v13[412];
    v17 = v12;
    v18 = v12 * v6->m_LaneT;
    laneT = 0.0;
    pos.x = v16;
    pos.y = v14;
    pos.z = v15;
    UFG::RoadNetworkLane::GetNearestPoint(v7, &result, &pos, &laneT);
    v19 = (float)(laneT * v12) + 8.0;
    if ( v19 >= v17 )
      v19 = v17;
    if ( v18 > v19 )
    {
      v20 = (float *)v1->m_pRoadSpace.m_pSimComponent;
      v21 = v20[415];
      v22 = v20[416];
      v23 = v20[417];
      if ( v1->m_bIgnoreArrivalDirection
        || v21 == UFG::qVector3::msZero.x && v22 == UFG::qVector3::msZero.y && v23 == UFG::qVector3::msZero.z )
      {
        goto LABEL_60;
      }
      if ( v7->mNode.mOffset )
        v3 = (UFG::RoadNetworkGate *)((char *)v7 + v7->mNode.mOffset);
      UFG::RoadNetworkNode::GetTangent((UFG::RoadNetworkNode *)v3, &result, v7->mLaneIndex, laneT);
      if ( (float)((float)((float)(result.y * v22) + (float)(result.x * v21)) + (float)(result.z * v23)) <= 0.0 )
      {
LABEL_60:
        if ( UFG::RoadNetworkGuide::CanChangeLane(v5, 1u) )
          UFG::AiDriverComponent::ChangeLane(v1, RightLane);
      }
    }
    UFG::AiDriverComponent::UpdateWanderingNavigation(v1);
  }
}

// File Line: 4502
// RVA: 0x64D1D0
UFG::RoadNetworkLane *__fastcall UFG::AiDriverComponent::FindNextWayfindLane(UFG::AiDriverComponent *this, UFG::RoadNetworkLane *currLane, UFG::RoadNetworkNode *nextPathSegment)
{
  __int64 v3; // rax
  UFG::RoadNetworkNode *v4; // rbp
  UFG::RoadNetworkConnection *v5; // rdi
  _WORD *v6; // rax
  __int64 v7; // rax
  UFG::RoadNetworkNode **v8; // rcx
  UFG::RoadNetworkNode *v9; // rdx
  signed __int64 v10; // rcx
  _WORD *v11; // rax
  unsigned int v12; // esi
  unsigned int v13; // ebx
  UFG::RoadNetworkLane *v14; // rax
  UFG::RoadNetworkLane *v15; // rdx
  __int64 v16; // rcx
  UFG::RoadNetworkNode **v17; // rax
  UFG::RoadNetworkNode *v18; // rcx

  v3 = currLane->mNextConnection.mOffset;
  v4 = nextPathSegment;
  if ( v3 )
    v5 = (UFG::RoadNetworkConnection *)((char *)&currLane->mNextConnection + v3);
  else
    v5 = 0i64;
  v6 = (_WORD *)currLane->mNode.mOffset;
  if ( currLane->mNode.mOffset )
    v6 = (_WORD *)((char *)v6 + (_QWORD)currLane);
  if ( *v6 == 1 )
    return UFG::qBezierPathCollectionMemImaged::GetPath(v5, 0);
  if ( !v5 )
    return 0i64;
  v7 = v5->mGate.mOffset;
  if ( v7 )
    v8 = (UFG::RoadNetworkNode **)((char *)&v5->mGate + v7);
  else
    v8 = 0i64;
  v9 = *v8;
  if ( *v8 )
    v9 = (UFG::RoadNetworkNode *)((char *)v9 + (_QWORD)v8);
  if ( v9 == nextPathSegment )
    return UFG::qBezierPathCollectionMemImaged::GetPath(v5, 0);
  if ( v7 )
    v10 = (signed __int64)&v5->mGate + v7;
  else
    v10 = 0i64;
  v11 = *(_WORD **)v10;
  if ( *(_QWORD *)v10 )
    v11 = (_WORD *)((char *)v11 + v10);
  if ( *v11 != 1 )
    return 0i64;
  v12 = v5->mNumLanes;
  v13 = 0;
  if ( !v5->mNumLanes )
    return 0i64;
  while ( 1 )
  {
    v14 = UFG::qBezierPathCollectionMemImaged::GetPath(v5, v13);
    v15 = v14;
    v16 = v14->mNextConnection.mOffset;
    if ( v16 )
      v16 += (__int64)&v14->mNextConnection;
    v17 = *(UFG::RoadNetworkNode ***)(v16 + 24);
    if ( v17 )
      v17 = (UFG::RoadNetworkNode **)((char *)v17 + v16 + 24);
    v18 = *v17;
    if ( *v17 )
      v18 = (UFG::RoadNetworkNode *)((char *)v18 + (_QWORD)v17);
    if ( v18 == v4 )
      break;
    if ( ++v13 >= v12 )
      return 0i64;
  }
  return v15;
}

// File Line: 4529
// RVA: 0x662950
void __fastcall UFG::AiDriverComponent::UpdateNavWandering(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *v1; // rbx
  UFG::AiDriverComponent *v2; // rdi
  float v3; // xmm7_4
  float *v4; // rax
  float v5; // xmm0_4
  float v6; // xmm8_4
  float v7; // xmm6_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::qVector3 dest; // [rsp+20h] [rbp-48h]

  v1 = this->m_pRoadSpace.m_pSimComponent;
  v2 = this;
  if ( *((_BYTE *)&v1[5].m_SimObjIndex + 2) )
  {
    v3 = (float)((float)((float)(*(float *)&v1[5].m_pSimObject - *((float *)&v1[5].m_SafePointerList.mNode.mNext + 1))
                       * (float)(*(float *)&v1[5].m_pSimObject - *((float *)&v1[5].m_SafePointerList.mNode.mNext + 1)))
               + (float)((float)(*((float *)&v1[5].m_pSimObject + 1) - *(float *)&v1[5].m_TypeUID)
                       * (float)(*((float *)&v1[5].m_pSimObject + 1) - *(float *)&v1[5].m_TypeUID)))
       + (float)((float)(*(float *)&v1[5].m_BoundComponentHandles.mNode.mPrev - *(float *)&v1[5].m_NameUID)
               * (float)(*(float *)&v1[5].m_BoundComponentHandles.mNode.mPrev - *(float *)&v1[5].m_NameUID));
    v4 = (float *)((__int64 (*)(void))this->m_pVehicleSubject.m_pSimComponent->vfptr[17].__vecDelDtor)();
    v5 = (float)(v4[2] - *(float *)&v1[5].m_NameUID) * (float)(v4[2] - *(float *)&v1[5].m_NameUID);
    v6 = *(float *)&v2->m_pRoadSpace.m_pSimComponent[5].m_Flags;
    v7 = (float)((float)((float)(v4[1] - *(float *)&v1[5].m_TypeUID) * (float)(v4[1] - *(float *)&v1[5].m_TypeUID))
               + (float)((float)(*v4 - *((float *)&v1[5].m_SafePointerList.mNode.mNext + 1))
                       * (float)(*v4 - *((float *)&v1[5].m_SafePointerList.mNode.mNext + 1))))
       + v5;
    ((void (*)(void))v2->m_pVehicleSubject.m_pSimComponent->vfptr[21].__vecDelDtor)();
    v8 = v5;
    v9 = FLOAT_2_0;
    v10 = v8 * 0.69999999;
    if ( v10 >= 2.0 )
      v9 = v10;
    if ( v3 >= (float)((float)(v6 + 0.1) * (float)(v6 + 0.1)) || v7 <= (float)(v9 * v9) )
    {
      v11 = UFG::qRandom(v6, &UFG::qDefaultSeed);
      v12 = UFG::qRandom(360.0, &UFG::qDefaultSeed);
      dest = UFG::qVector3::msDirFront;
      UFG::qRotateVectorZ(&dest, &UFG::qVector3::msDirFront, (float)(v12 * 3.1415927) * 0.0055555557);
      v13 = (float *)v2->m_pRoadSpace.m_pSimComponent;
      v14 = (float)(dest.y * v11) + *((float *)&v1[5].m_pSimObject + 1);
      v15 = (float)(dest.z * v11) + *(float *)&v1[5].m_BoundComponentHandles.mNode.mPrev;
      v13[85] = (float)(dest.x * v11) + *(float *)&v1[5].m_pSimObject;
      v13[86] = v14;
      v13[87] = v15;
    }
  }
}

// File Line: 4557
// RVA: 0x665640
void __fastcall UFG::AiDriverComponent::UpdateWanderingNavigation(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // r13
  UFG::SimObject *v2; // rax
  unsigned int v3; // er15
  UFG::TransformNodeComponent *v4; // rcx
  UFG::SimComponent *v5; // rax
  UFG::RoadNetworkGuide *v6; // rbx
  UFG::RoadNetworkConnection *v7; // rax
  UFG::RoadNetworkConnection *v8; // r12
  unsigned int *v9; // rsi
  unsigned int v10; // er14
  unsigned int v11; // ebx
  unsigned int v12; // edi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  unsigned int *v16; // rcx
  __int64 v17; // r8
  unsigned int v18; // eax
  UFG::RoadNetworkLane *v19; // rsi
  __int64 v20; // rax
  UFG::RoadNetworkConnection *v21; // rax
  _WORD *v22; // rdx
  UFG::RoadNetworkLane *v23; // rdx
  UFG::RoadNetworkGuide *v24; // rcx
  UFG::RoadNetworkLane *v25; // rax
  UFG::RoadNetworkLane *v26; // rdi
  __int64 v27; // rax
  UFG::RoadNetworkGate *v28; // r14
  unsigned int v29; // er15
  unsigned int v30; // ebx
  UFG::RoadNetworkConnection *v31; // rax
  UFG::RoadNetworkConnection *v32; // rcx
  __int64 v33; // rcx
  UFG::RoadNetworkConnection *v34; // rdx
  UFG::RoadNetworkLane *v35; // rax
  UFG::RoadNetworkGuide *v36; // [rsp+20h] [rbp-28h]
  UFG::qArray<unsigned long,0> laneIDs; // [rsp+30h] [rbp-18h]
  UFG::AiDriverComponent *v38; // [rsp+90h] [rbp+48h]
  unsigned int whichLanes; // [rsp+98h] [rbp+50h]
  unsigned int v40; // [rsp+A0h] [rbp+58h]
  UFG::RoadNetworkConnection *v41; // [rsp+A8h] [rbp+60h]

  v38 = this;
  v1 = this;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v2 = v1->m_pSimObject;
  v3 = 0;
  if ( v2 )
    v4 = (UFG::TransformNodeComponent *)v2->m_Components.p[2].m_pComponent;
  else
    v4 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  v5 = v1->m_pRoadSpace.m_pSimComponent;
  if ( BYTE4(v5[30].m_SafePointerList.mNode.mNext) )
  {
    if ( !*((_BYTE *)&v5[1].m_SimObjIndex + 2) )
      *((_BYTE *)&v5[1].m_SimObjIndex + 2) = 1;
    UFG::AiDriverComponent::UpdateNavWandering(v1);
    return;
  }
  v6 = (UFG::RoadNetworkGuide *)&v5[5].m_BoundComponentHandles.mNode.mNext;
  v36 = (UFG::RoadNetworkGuide *)&v5[5].m_BoundComponentHandles.mNode.mNext;
  if ( !LOBYTE(v5[8].m_Flags) )
    return;
  if ( !(unsigned __int8)UFG::RoadNetworkGuide::NavigationInfoNeeded((UFG::RoadNetworkGuide *)&v5[5].m_BoundComponentHandles.mNode.mNext) )
    return;
  UFG::RoadNetworkGuide::SetLaneAfterNext(v6, 0i64);
  v7 = UFG::RoadNetworkGuide::GetNextConnection(v6);
  v8 = v7;
  v41 = v7;
  if ( !v7 )
    return;
  laneIDs.p = 0i64;
  *(_QWORD *)&laneIDs.size = 0i64;
  UFG::RoadNetworkConnection::GetValidLanes(
    v7,
    (unsigned int)v1->m_pRoadSpace.m_pSimComponent[30].m_SafePointerList.mNode.mNext,
    &laneIDs);
  if ( !laneIDs.size )
  {
    if ( UFG::PhysicsMoverInterface::GetLOD((UFG::PhysicsMoverInterface *)v1->mMoverComponent.m_pSimComponent) == 1 )
      goto LABEL_80;
    whichLanes = 3;
    if ( !UFG::RoadNetworkGuide::LaneChangeAvailable(v6, &whichLanes)
      || !UFG::RoadNetworkGuide::ChangeLaneIfRoom(v6, whichLanes) )
    {
      goto LABEL_80;
    }
    v8 = UFG::RoadNetworkGuide::GetNextConnection(v6);
    v41 = v8;
    if ( !v8 )
      goto LABEL_75;
    if ( laneIDs.p )
      operator delete[](laneIDs.p);
    laneIDs.p = 0i64;
    *(_QWORD *)&laneIDs.size = 0i64;
    UFG::RoadNetworkConnection::GetValidLanes(
      v8,
      (unsigned int)v1->m_pRoadSpace.m_pSimComponent[30].m_SafePointerList.mNode.mNext,
      &laneIDs);
    if ( !laneIDs.size )
    {
LABEL_80:
      if ( laneIDs.p )
        operator delete[](laneIDs.p);
      laneIDs.p = 0i64;
      *(_QWORD *)&laneIDs.size = 0i64;
      UFG::RoadNetworkConnection::GetValidLanes(v8, 8u, &laneIDs);
      if ( !laneIDs.size )
      {
        if ( laneIDs.p )
          operator delete[](laneIDs.p);
        v9 = 0i64;
        laneIDs.p = 0i64;
        v10 = 0;
        laneIDs.size = 0;
        v11 = 0;
        laneIDs.capacity = 0;
        v40 = v8->mNumLanes;
        if ( !v40 )
          goto LABEL_79;
        while ( 1 )
        {
          v12 = v10 + 1;
          if ( v10 + 1 > v11 )
          {
            if ( v11 )
              v13 = 2 * v11;
            else
              v13 = 1;
            for ( ; v13 < v12; v13 *= 2 )
              ;
            if ( v13 <= 4 )
              v13 = 4;
            if ( v13 - v12 > 0x10000 )
              v13 = v10 + 65537;
            if ( v13 != v10 )
            {
              v14 = 4i64 * v13;
              if ( !is_mul_ok(v13, 4ui64) )
                v14 = -1i64;
              v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
              v9 = (unsigned int *)v15;
              v16 = laneIDs.p;
              if ( laneIDs.p )
              {
                v17 = 0i64;
                if ( laneIDs.size )
                {
                  do
                  {
                    *((_DWORD *)&v15->mNext + v17) = v16[v17];
                    v17 = (unsigned int)(v17 + 1);
                    v16 = laneIDs.p;
                  }
                  while ( (unsigned int)v17 < laneIDs.size );
                }
                operator delete[](v16);
              }
              laneIDs.p = v9;
              laneIDs.capacity = v13;
            }
          }
          laneIDs.size = v10 + 1;
          v9[v10] = v3++;
          if ( v3 >= v40 )
            break;
          v9 = laneIDs.p;
          v11 = laneIDs.capacity;
          v10 = laneIDs.size;
        }
        v1 = v38;
        v8 = v41;
        if ( !laneIDs.size )
        {
LABEL_79:
          v1->m_fDesiredSpeed = 0.0;
          goto LABEL_75;
        }
        v6 = v36;
      }
    }
  }
  v18 = UFG::AiDriverComponent::ChooseNextLane(v1, v8, &laneIDs);
  v19 = UFG::qBezierPathCollectionMemImaged::GetPath(v8, v18);
  UFG::VehicleOccupantComponent::SetParkingSpot(v6, v19);
  v20 = v19->mNextConnection.mOffset;
  if ( v20 )
    v21 = (UFG::RoadNetworkConnection *)((char *)&v19->mNextConnection + v20);
  else
    v21 = 0i64;
  v22 = (_WORD *)((char *)v19 + v19->mNode.mOffset);
  if ( !v19->mNode.mOffset )
    v22 = 0i64;
  if ( *v22 != 1 )
  {
    v25 = UFG::AiDriverComponent::FindWanderLaneAfterNext(v1, v21);
    v26 = v25;
    if ( v25 )
    {
      v23 = v25;
      v24 = v6;
    }
    else
    {
      v27 = v19->mEndGate.mOffset;
      if ( v27 )
        v28 = (UFG::RoadNetworkGate *)((char *)&v19->mEndGate + v27);
      else
        v28 = 0i64;
      v29 = v28->mNumOutgoingConnections;
      v30 = 0;
      if ( !v29 )
        goto LABEL_75;
      do
      {
        v31 = UFG::RoadNetworkGate::GetOutgoingConnection(v28, v30);
        v32 = (UFG::RoadNetworkConnection *)v19->mEndConnection.mOffset;
        if ( v32 )
          v32 = (UFG::RoadNetworkConnection *)((char *)v32 + (_QWORD)v19 + 96);
        if ( v31 != v32 )
        {
          v33 = v31->mConnection.mOffset;
          v34 = (UFG::RoadNetworkConnection *)(v33 ? (UFG::qOffset64<UFG::RoadNetworkConnection *> *)((char *)&v31->mConnection + v33) : 0i64);
          v35 = UFG::AiDriverComponent::FindWanderLaneAfterNext(v1, v34);
          v26 = v35;
          if ( v35 )
          {
            if ( (unsigned int)UFG::RoadNetworkLane::GetTurnDirection(v35) == 1 )
              break;
          }
        }
        ++v30;
      }
      while ( v30 < v29 );
      if ( !v26 )
        goto LABEL_75;
      v23 = v26;
      v24 = v36;
    }
    goto LABEL_74;
  }
  if ( v21 && v21->mNumLanes )
  {
    v23 = UFG::qBezierPathCollectionMemImaged::GetPath(v21, 0);
    v24 = v6;
LABEL_74:
    UFG::RoadNetworkGuide::SetLaneAfterNext(v24, v23);
  }
LABEL_75:
  if ( laneIDs.p )
    operator delete[](laneIDs.p);
}

// File Line: 4698
// RVA: 0x64D580
UFG::RoadNetworkLane *__fastcall UFG::AiDriverComponent::FindWanderLaneAfterNext(UFG::AiDriverComponent *this, UFG::RoadNetworkConnection *roadConn)
{
  unsigned int v2; // er14
  UFG::RoadNetworkLane *v3; // rbx
  char v4; // bp
  UFG::RoadNetworkConnection *v5; // r15
  UFG::AiDriverComponent *v6; // r13
  unsigned int v7; // esi
  UFG::RoadNetworkLane *v8; // rdi
  int v9; // eax

  v2 = roadConn->mNumLanes;
  v3 = 0i64;
  v4 = 0;
  v5 = roadConn;
  v6 = this;
  v7 = 0;
  if ( !roadConn->mNumLanes )
    return v3;
  while ( 1 )
  {
    v8 = UFG::qBezierPathCollectionMemImaged::GetPath(v5, v7);
    if ( UFG::RoadNetworkLane::IsFlagMatch(
           v8,
           (unsigned int)v6->m_pRoadSpace.m_pSimComponent[30].m_SafePointerList.mNode.mNext) )
    {
      break;
    }
LABEL_8:
    if ( ++v7 >= v2 )
      return v3;
  }
  v9 = UFG::RoadNetworkLane::GetTurnDirection(v8);
  if ( v9 != 1 )
  {
    if ( v9 == 2 )
    {
      v3 = v8;
      v4 = 1;
    }
    else if ( !v4 )
    {
      v3 = v8;
    }
    goto LABEL_8;
  }
  return v8;
}

// File Line: 4729
// RVA: 0x648A40
__int64 __fastcall UFG::AiDriverComponent::ChooseNextLane(UFG::AiDriverComponent *this, UFG::RoadNetworkConnection *roadConnection, UFG::qArray<unsigned long,0> *validLanes)
{
  UFG::qArray<unsigned long,0> *v3; // rax
  UFG::RoadNetworkConnection *v4; // rdi
  UFG::AiDriverComponent *v5; // r14
  unsigned __int64 v6; // rbx
  void *v8; // rsi
  unsigned int v9; // er13
  unsigned int v10; // er12
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  unsigned int v13; // er15
  __int64 v14; // rcx
  UFG::RoadNetworkLane *v15; // rax
  UFG::RoadNetworkLane *v16; // rbx
  __int64 v17; // rax
  UFG::RoadNetworkConnection *v18; // rcx
  UFG::RoadNetworkLane *v19; // rax
  UFG::RoadNetworkLane *v20; // rbx
  float v21; // xmm0_4
  unsigned int v22; // edx
  _WORD *v23; // rcx
  __int64 v24; // rax
  UFG::RoadNetworkConnection *v25; // rsi
  unsigned __int64 v26; // rdi
  unsigned __int64 v27; // rax
  UFG::allocator::free_link *v28; // rax
  unsigned int *v29; // rbx
  unsigned int *v30; // rcx
  __int64 v31; // r8
  UFG::RoadNetworkLane *v32; // rax
  UFG::RoadNetworkConnection *v33; // rcx
  UFG::RoadNetworkLane *v34; // rbx
  float v35; // xmm0_4
  unsigned int v36; // edx
  __int64 v37; // r14
  unsigned int v38; // edi
  unsigned int v39; // ebx
  unsigned __int64 v40; // rax
  UFG::allocator::free_link *v41; // rax
  void *v42; // rcx
  UFG::allocator::free_link *v43; // rdx
  char *v44; // r9
  __int64 v45; // r8
  UFG::qArray<unsigned long,0> *v46; // rdx
  unsigned int v47; // ebx
  UFG::qArray<unsigned long,0> laneIDs; // [rsp+28h] [rbp-30h]
  __int64 v49; // [rsp+38h] [rbp-20h]
  void *mem; // [rsp+40h] [rbp-18h]
  UFG::AiDriverComponent *v51; // [rsp+A0h] [rbp+48h]
  UFG::RoadNetworkConnection *v52; // [rsp+A8h] [rbp+50h]
  UFG::qArray<unsigned long,0> *v53; // [rsp+B0h] [rbp+58h]
  unsigned int v54; // [rsp+B8h] [rbp+60h]

  v53 = validLanes;
  v52 = roadConnection;
  v51 = this;
  v3 = validLanes;
  v4 = roadConnection;
  v5 = this;
  v6 = validLanes->size;
  if ( (_DWORD)v6 == 1 )
    return *validLanes->p;
  v8 = 0i64;
  mem = 0i64;
  v9 = 0;
  v49 = 0i64;
  v10 = 0;
  if ( (_DWORD)v6 )
  {
    v11 = 4 * v6;
    if ( !is_mul_ok(v6, 4ui64) )
      v11 = -1i64;
    v12 = UFG::qMalloc(v11, "AiDriverComponent", 0i64);
    v8 = v12;
    mem = v12;
    v10 = v6;
    HIDWORD(v49) = v6;
    v3 = v53;
  }
  v54 = v4->mNumLanes;
  v13 = 0;
  if ( !v4->mNumLanes )
  {
LABEL_74:
    v46 = v3;
    goto LABEL_75;
  }
  do
  {
    v14 = 0i64;
    if ( !v3->size )
      goto LABEL_72;
    while ( v13 != v3->p[v14] )
    {
      v14 = (unsigned int)(v14 + 1);
      if ( (unsigned int)v14 >= v3->size )
        goto LABEL_71;
    }
    if ( (_DWORD)v14 != -1 )
    {
      v15 = UFG::qBezierPathCollectionMemImaged::GetPath(v4, v13);
      v16 = v15;
      if ( v15 )
      {
        if ( !UFG::AiDriverComponent::IsJammed(v15, 1u) )
        {
          v17 = v16->mNextConnection.mOffset;
          if ( v17 )
          {
            v18 = (UFG::RoadNetworkConnection *)((char *)&v16->mNextConnection + v17);
            if ( v18 )
            {
              if ( v18->mNumLanes )
              {
                v19 = UFG::qBezierPathCollectionMemImaged::GetPath(v18, 0);
                v20 = v19;
                if ( v19 )
                {
                  v21 = UFG::RoadNetworkLane::GetLength(v19);
                  v22 = 1;
                  if ( v21 > 20.0 )
                    v22 = 3;
                  if ( !UFG::AiDriverComponent::IsJammed(v20, v22) )
                  {
                    if ( v20->mNode.mOffset )
                      v23 = (_WORD *)((char *)v20 + v20->mNode.mOffset);
                    else
                      v23 = 0i64;
                    if ( !*v23 )
                    {
                      v24 = v20->mNextConnection.mOffset;
                      if ( v24 )
                        v25 = (UFG::RoadNetworkConnection *)((char *)&v20->mNextConnection + v24);
                      else
                        v25 = 0i64;
                      laneIDs.p = 0i64;
                      *(_QWORD *)&laneIDs.size = 0i64;
                      v26 = v25->mNumLanes;
                      if ( (unsigned int)v26 > 0 && (_DWORD)v26 != laneIDs.size )
                      {
                        v27 = 4i64 * v25->mNumLanes;
                        if ( !is_mul_ok(v26, 4ui64) )
                          v27 = -1i64;
                        v28 = UFG::qMalloc(v27, "qArray.Reallocate(Reserve)", 0i64);
                        v29 = (unsigned int *)v28;
                        v30 = laneIDs.p;
                        if ( laneIDs.p )
                        {
                          v31 = 0i64;
                          if ( laneIDs.size )
                          {
                            do
                            {
                              *((_DWORD *)&v28->mNext + v31) = v30[v31];
                              v31 = (unsigned int)(v31 + 1);
                              v30 = laneIDs.p;
                            }
                            while ( (unsigned int)v31 < laneIDs.size );
                          }
                          operator delete[](v30);
                        }
                        laneIDs.p = v29;
                        laneIDs.capacity = v26;
                      }
                      UFG::RoadNetworkConnection::GetValidLanes(
                        v25,
                        (unsigned int)v5->m_pRoadSpace.m_pSimComponent[30].m_SafePointerList.mNode.mNext,
                        &laneIDs);
                      if ( laneIDs.size == 1 )
                      {
                        v32 = UFG::qBezierPathCollectionMemImaged::GetPath(v25, *laneIDs.p);
                        v33 = (UFG::RoadNetworkConnection *)v32->mNextConnection.mOffset;
                        if ( v33 )
                          v33 = (UFG::RoadNetworkConnection *)((char *)v33 + (_QWORD)v32 + 104);
                        v34 = UFG::qBezierPathCollectionMemImaged::GetPath(v33, 0);
                        v35 = UFG::RoadNetworkLane::GetLength(v34);
                        v36 = 1;
                        if ( v35 > 20.0 )
                          v36 = 3;
                        if ( UFG::AiDriverComponent::IsJammed(v34, v36) )
                        {
                          if ( laneIDs.p )
                            operator delete[](laneIDs.p);
                          laneIDs.p = 0i64;
                          *(_QWORD *)&laneIDs.size = 0i64;
                          v8 = mem;
LABEL_70:
                          v4 = v52;
                          goto LABEL_71;
                        }
                      }
                      if ( laneIDs.p )
                        operator delete[](laneIDs.p);
                      laneIDs.p = 0i64;
                      *(_QWORD *)&laneIDs.size = 0i64;
                    }
                    v37 = v9;
                    v38 = v9 + 1;
                    if ( v9 + 1 <= v10 )
                      goto LABEL_80;
                    v39 = 1;
                    if ( v10 )
                      v39 = 2 * v10;
                    for ( ; v39 < v38; v39 *= 2 )
                      ;
                    if ( v39 <= 4 )
                      v39 = 4;
                    if ( v39 - v38 > 0x10000 )
                      v39 = v9 + 65537;
                    if ( v39 == v9 )
                    {
LABEL_80:
                      v8 = mem;
                    }
                    else
                    {
                      v40 = 4i64 * v39;
                      if ( !is_mul_ok(v39, 4ui64) )
                        v40 = -1i64;
                      v41 = UFG::qMalloc(v40, "qArray.Add", 0i64);
                      v8 = v41;
                      v42 = mem;
                      if ( mem )
                      {
                        if ( v9 )
                        {
                          v43 = v41;
                          v44 = (char *)((_BYTE *)mem - (_BYTE *)v41);
                          v45 = v9;
                          do
                          {
                            LODWORD(v43->mNext) = *(_DWORD *)((char *)&v43->mNext + (_QWORD)v44);
                            v43 = (UFG::allocator::free_link *)((char *)v43 + 4);
                            --v45;
                          }
                          while ( v45 );
                        }
                        operator delete[](v42);
                      }
                      mem = v8;
                      v10 = v39;
                      HIDWORD(v49) = v39;
                    }
                    ++v9;
                    LODWORD(v49) = v38;
                    *((_DWORD *)v8 + v37) = v13;
                    v5 = v51;
                    goto LABEL_70;
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_71:
    v3 = v53;
LABEL_72:
    ++v13;
  }
  while ( v13 < v54 );
  v46 = (UFG::qArray<unsigned long,0> *)&v49;
  if ( !v9 )
    goto LABEL_74;
LABEL_75:
  v47 = UFG::AiDriverComponent::ChooseLane(v4, v46);
  if ( v8 )
    operator delete[](v8);
  return v47;
}

// File Line: 4813
// RVA: 0x6486A0
__int64 __fastcall UFG::AiDriverComponent::ChooseLane(UFG::RoadNetworkConnection *roadConn, UFG::qArray<unsigned long,0> *allowedLanes)
{
  UFG::qArray<unsigned long,0> *v2; // rdi
  unsigned __int64 v3; // rbx
  UFG::allocator::free_link *v4; // r12
  unsigned int v5; // er14
  unsigned int v6; // er15
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rsi
  unsigned int v9; // ebp
  unsigned int v10; // er13
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rdi
  signed __int64 v13; // rcx
  UFG::RoadNetworkLane *v14; // rax
  unsigned int v15; // ecx
  unsigned int v16; // edi
  unsigned int v17; // ebx
  unsigned __int64 v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rsi
  UFG::allocator::free_link *v21; // rcx
  __int64 v22; // rdx
  unsigned int v23; // ecx
  unsigned int v24; // edi
  unsigned int v25; // ebx
  unsigned __int64 v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::allocator::free_link *v28; // rdx
  __int64 v29; // r8
  unsigned int v30; // ebx
  unsigned __int64 v32; // [rsp+20h] [rbp-88h]
  __int64 v33; // [rsp+28h] [rbp-80h]
  UFG::allocator::free_link *mem; // [rsp+50h] [rbp-58h]
  UFG::RoadNetworkConnection *v35; // [rsp+B0h] [rbp+8h]
  UFG::qArray<unsigned long,0> *v36; // [rsp+B8h] [rbp+10h]
  int v37; // [rsp+C0h] [rbp+18h]

  v36 = allowedLanes;
  v35 = roadConn;
  v2 = allowedLanes;
  v3 = allowedLanes->size;
  v4 = 0i64;
  v5 = 0;
  v6 = 0;
  if ( (_DWORD)v3 )
  {
    v7 = 4 * v3;
    if ( !is_mul_ok(v3, 4ui64) )
      v7 = -1i64;
    v4 = UFG::qMalloc(v7, "AiDriverComponent", 0i64);
    v6 = v3;
  }
  v8 = 0i64;
  mem = 0i64;
  v9 = 0;
  v10 = 0;
  if ( (unsigned int)v3 > v6 )
  {
    if ( !(_DWORD)v3 )
      goto LABEL_60;
    v11 = 4 * v3;
    if ( !is_mul_ok(v3, 4ui64) )
      v11 = -1i64;
    v12 = UFG::qMalloc(v11, "AiDriverComponent", 0i64);
    if ( v4 )
      operator delete[](v4);
    v4 = v12;
    v6 = v3;
    v2 = v36;
  }
  if ( (_DWORD)v3 )
  {
    v13 = 0i64;
    v33 = 0i64;
    v32 = v3;
    do
    {
      v37 = *(unsigned int *)((char *)v2->p + v13);
      v14 = UFG::qBezierPathCollectionMemImaged::GetPath(v35, *(unsigned int *)((char *)v2->p + v13));
      if ( UFG::RoadNetworkLane::IsPermissive(v14, 0) )
      {
        v15 = v5;
        v16 = v5 + 1;
        if ( v5 + 1 > v6 )
        {
          v17 = 1;
          if ( v6 )
            v17 = 2 * v6;
          for ( ; v17 < v16; v17 *= 2 )
            ;
          if ( v17 <= 4 )
            v17 = 4;
          if ( v17 - v16 > 0x10000 )
            v17 = v5 + 65537;
          if ( v17 != v5 )
          {
            v18 = 4i64 * v17;
            if ( !is_mul_ok(v17, 4ui64) )
              v18 = -1i64;
            v19 = UFG::qMalloc(v18, "qArray.Add", 0i64);
            v20 = v19;
            if ( v4 )
            {
              if ( v5 )
              {
                v21 = v19;
                v22 = v5;
                do
                {
                  LODWORD(v21->mNext) = *(_DWORD *)((char *)&v21->mNext + (char *)v4 - (char *)v19);
                  v21 = (UFG::allocator::free_link *)((char *)v21 + 4);
                  --v22;
                }
                while ( v22 );
              }
              operator delete[](v4);
            }
            v4 = v20;
            v6 = v17;
            v8 = mem;
            v15 = v5;
          }
          v3 = v32;
        }
        ++v5;
        *((_DWORD *)&v4->mNext + v15) = v37;
      }
      else
      {
        v23 = v9;
        v24 = v9 + 1;
        if ( v9 + 1 > v10 )
        {
          v25 = 1;
          if ( v10 )
            v25 = 2 * v10;
          for ( ; v25 < v24; v25 *= 2 )
            ;
          if ( v25 <= 4 )
            v25 = 4;
          if ( v25 - v24 > 0x10000 )
            v25 = v9 + 65537;
          if ( v25 != v9 )
          {
            v26 = 4i64 * v25;
            if ( !is_mul_ok(v25, 4ui64) )
              v26 = -1i64;
            v27 = UFG::qMalloc(v26, "qArray.Add", 0i64);
            v8 = v27;
            if ( mem )
            {
              if ( v9 )
              {
                v28 = v27;
                v29 = v9;
                do
                {
                  LODWORD(v28->mNext) = *(_DWORD *)((char *)&v28->mNext + (char *)mem - (char *)v27);
                  v28 = (UFG::allocator::free_link *)((char *)v28 + 4);
                  --v29;
                }
                while ( v29 );
              }
              operator delete[](mem);
            }
            mem = v8;
            v10 = v25;
            v23 = v9;
          }
          v3 = v32;
        }
        ++v9;
        *((_DWORD *)&v8->mNext + v23) = v37;
      }
      v13 = v33 + 4;
      v33 += 4i64;
      v32 = --v3;
      v2 = v36;
    }
    while ( v3 );
    if ( v5 && (!v9 || UFG::qRandom(1.0, &UFG::qDefaultSeed) < 0.14285715) )
    {
      ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
      v30 = *((_DWORD *)&v4->mNext + (v5 * (ARandom::c_gen.i_seed >> 16) >> 16));
      goto LABEL_61;
    }
  }
LABEL_60:
  ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
  v30 = *((_DWORD *)&v8->mNext + (v9 * (ARandom::c_gen.i_seed >> 16) >> 16));
LABEL_61:
  if ( v8 )
    operator delete[](v8);
  if ( v4 )
    operator delete[](v4);
  return v30;
}

// File Line: 4850
// RVA: 0x651CC0
bool __fastcall UFG::AiDriverComponent::IsJammed(UFG::RoadNetworkLane *roadLane, unsigned int numCarsForJam)
{
  UFG::qOffset64<UFG::RoadNetworkConnection *> *v2; // rsi
  unsigned int v3; // edi
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **v4; // rbx
  unsigned int v5; // ebp
  UFG::SimObjectCVBase *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::AiDriverComponent *v8; // rax

  v2 = &roadLane->mStartConnection;
  v3 = 0;
  v4 = &roadLane->mCars.mNode.mNext[-2].mNext;
  v5 = numCarsForJam;
  if ( v4 != (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **)&roadLane->mStartConnection )
  {
    do
    {
      v6 = (UFG::SimObjectCVBase *)v4[9];
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 >> 14) & 1 )
        {
          v8 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v6);
        }
        else if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
          {
            v8 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v6->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
          else if ( (v7 >> 12) & 1 )
          {
            v8 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v6->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
          else
          {
            v8 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v6->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
        }
        else
        {
          v8 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v6);
        }
        if ( v8 && v8->m_fCurrentForwardSpeed < 1.0 )
          ++v3;
      }
      v4 = &v4[4][-2].mNext;
    }
    while ( v4 != (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **)v2 );
  }
  return v3 >= v5;
}

// File Line: 4875
// RVA: 0x645600
void __fastcall UFG::AiDriverComponent::BeginAttack(UFG::AiDriverComponent *this, CarCombat::Attack attack)
{
  if ( !((attack - 4) & 0xFFFFFFFD) )
  {
    switch ( this->m_DesiredOffset )
    {
      case 0:
      case 1:
      case 2:
      case 5:
        attack = 0;
        break;
      case 3:
        attack = 2;
        break;
      case 4:
        attack = 1;
        break;
      case 6:
        attack = 3;
        break;
      default:
        break;
    }
  }
  this->m_CurrentAttack = attack;
  if ( attack == Ram )
    goto LABEL_16;
  if ( (signed int)attack > 0 )
  {
    if ( (signed int)attack <= 2 )
    {
      this->m_vFollowOffsetDesired.y = 0.0;
      return;
    }
    if ( attack == 3 )
LABEL_16:
      this->m_vFollowOffsetDesired.x = 0.0;
  }
}

// File Line: 4917
// RVA: 0x64C7E0
void __fastcall UFG::AiDriverComponent::EndAttack(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // rbx
  UFG::VehicleSubjectComponent *v2; // rcx
  bool v3; // al
  float *v4; // rax
  float v5; // xmm0_4
  float v6; // xmm2_4
  UFG::RoadSpaceComponent *v7; // rcx

  v1 = this;
  UFG::VehicleCombatStats::AttackOccured(&this->m_CombatStats, this->m_CurrentAttack);
  v2 = (UFG::VehicleSubjectComponent *)v1->m_pVehicleSubject.m_pSimComponent;
  if ( v2 )
    v3 = UFG::VehicleSubjectComponent::IsBoat(v2);
  else
    v3 = 0;
  if ( v3 )
    v4 = (float *)(12i64 * (signed int)v1->m_DesiredOffset + 5402855584i64);
  else
    v4 = (float *)(12i64 * (signed int)v1->m_DesiredOffset + 5402855488i64);
  v5 = v4[1];
  v6 = v4[2];
  if ( v1->m_Side == 1 )
    LODWORD(v5) ^= _xmm[0];
  v1->m_vFollowOffsetDesired.x = *v4;
  v1->m_vFollowOffsetDesired.y = v5;
  v1->m_vFollowOffsetDesired.z = v6;
  v7 = (UFG::RoadSpaceComponent *)v1->m_pRoadSpace.m_pSimComponent;
  v1->m_CurrentAttack = 7;
  if ( v7 && v7->m_pRacePosition && !UFG::RoadSpaceComponent::CleanupOnRaceDeleted(v7) && v1->m_DrivingMode != 6 )
  {
    v1->m_DrivingMode = 6;
    v1->m_fReactionTime = 0.0;
    v1->m_fDelayedStopDecel = 0.0;
    v1->mModeSteeringLockEnabled = 0;
    v1->mModeGasBrakeLockEnabled = 0;
    v1->m_bIgnoreArrivalDirection = 0;
  }
}

// File Line: 4930
// RVA: 0x65EB60
char __fastcall UFG::AiDriverComponent::TimeWindowCloserThan(UFG::AiDriverComponent *this, UFG::qVector3 *p0, UFG::qVector3 *v0, UFG::qVector3 *p1, UFG::qVector3 *v1, float distance, UFG::AiDriverComponent::TimeWindowResult *result)
{
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  __m128 v11; // xmm8
  __m128 v12; // xmm7
  float v13; // xmm1_4
  __m128 v14; // xmm6
  float v15; // xmm0_4
  float v16; // xmm1_4
  __m128 v17; // xmm2
  float v19; // xmm0_4
  float v20; // xmm7_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm0_4

  v14 = (__m128)LODWORD(v1->y);
  v11 = (__m128)LODWORD(p1->y);
  v14.m128_f32[0] = v14.m128_f32[0] - v0->y;
  v11.m128_f32[0] = v11.m128_f32[0] - p0->y;
  v7 = v1->x - v0->x;
  v12 = v14;
  v12.m128_f32[0] = v14.m128_f32[0] * v14.m128_f32[0];
  v14.m128_f32[0] = v14.m128_f32[0] * v11.m128_f32[0];
  v8 = p1->x - p0->x;
  v9 = p1->z - p0->z;
  v10 = v1->z - v0->z;
  v11.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v8 * v8)) + (float)(v9 * v9);
  v12.m128_f32[0] = (float)(v12.m128_f32[0] + (float)(v7 * v7)) + (float)(v10 * v10);
  LODWORD(v13) = (unsigned __int128)_mm_sqrt_ps(v11);
  v14.m128_f32[0] = (float)(v14.m128_f32[0] + (float)(v7 * v8)) + (float)(v10 * v9);
  if ( v13 >= 0.00000011920929 )
    v15 = v14.m128_f32[0] / v13;
  else
    LODWORD(v15) = (unsigned __int128)_mm_sqrt_ps(v12);
  v16 = 0.0;
  v14.m128_f32[0] = v14.m128_f32[0] * 2.0;
  result->fClosingSpeed = v15;
  v17 = v14;
  v17.m128_f32[0] = (float)(v14.m128_f32[0] * v14.m128_f32[0])
                  - (float)((float)(v11.m128_f32[0] - (float)(distance * distance)) * (float)(v12.m128_f32[0] * 4.0));
  if ( v17.m128_f32[0] < 0.0 )
  {
    *(_QWORD *)&result->fEarliest = 0i64;
    return 0;
  }
  LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v17);
  v20 = v12.m128_f32[0] * 2.0;
  v21 = v19 - v14.m128_f32[0];
  v22 = COERCE_FLOAT(v14.m128_i32[0] ^ _xmm[0]) - v19;
  v23 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v19 - v14.m128_f32[0]) & _xmm) * 0.001;
  if ( v20 > v23 )
    v23 = v20;
  if ( v20 <= (float)(COERCE_FLOAT(LODWORD(v22) & _xmm) * 0.001) )
    v20 = COERCE_FLOAT(LODWORD(v22) & _xmm) * 0.001;
  v24 = *(float *)&FLOAT_1_0;
  if ( v23 >= 0.00000011920929 )
  {
    v25 = v21 / v23;
  }
  else if ( v14.m128_f32[0] <= 0.0 )
  {
    if ( v14.m128_f32[0] >= 0.0 )
      v25 = 0.0 * -1000.0;
    else
      v25 = -1.0 * -1000.0;
  }
  else
  {
    v25 = 1.0 * -1000.0;
  }
  if ( v25 < 0.0 )
    v25 = 0.0;
  result->fLatest = v25;
  if ( v20 >= 0.00000011920929 )
  {
    v26 = v22 / v20;
    goto LABEL_26;
  }
  if ( v14.m128_f32[0] > 0.0 )
    goto LABEL_24;
  if ( v14.m128_f32[0] >= 0.0 )
  {
    v24 = 0.0;
LABEL_24:
    v26 = v24 * -1000.0;
    goto LABEL_26;
  }
  v26 = -1.0 * -1000.0;
LABEL_26:
  if ( v26 >= 0.0 )
    v16 = v26;
  result->fEarliest = v16;
  return 1;
}

// File Line: 4968
// RVA: 0x64D960
UFG::qVector3 *__fastcall UFG::AiDriverComponent::GetCombatOffset(UFG::qVector3 *result, int side, int index, bool isBoat)
{
  UFG::qVector3 *v4; // r10
  UFG::qVector3 *v5; // rcx
  float v6; // xmm0_4
  float v7; // eax
  UFG::qVector3 *v8; // rax

  v4 = result;
  if ( isBoat )
    v5 = &UFG::AiDriverComponent::mCombatBoatOffsets[index];
  else
    v5 = (UFG::qVector3 *)(12i64 * index + 5402855488i64);
  v6 = v5->y;
  v4->x = v5->x;
  v7 = v5->z;
  v4->y = v6;
  v4->z = v7;
  v8 = v4;
  if ( side == 1 )
    LODWORD(v4->y) = LODWORD(v6) ^ _xmm[0];
  return v8;
}

// File Line: 4978
// RVA: 0x64D710
float __fastcall UFG::AiDriverComponent::GetAvoidanceFutureTime(UFG::AiDriverComponent *this)
{
  float result; // xmm0_4

  if ( this->m_bAllowedToPass )
    result = *(float *)&FLOAT_1_0;
  else
    result = FLOAT_2_0;
  return result;
}

// File Line: 4987
// RVA: 0x64D730
float __fastcall UFG::AiDriverComponent::GetBumperGap(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // rbx
  UFG::VehicleSubjectComponent *v2; // rcx
  float result; // xmm0_4
  char v4; // al

  v1 = this;
  v2 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  if ( v2 && UFG::VehicleSubjectComponent::IsBoat(v2) )
  {
    result = FLOAT_80_0;
    v4 = 1;
  }
  else
  {
    result = FLOAT_6_0;
    v4 = 0;
  }
  if ( v1->m_bAllowedToPass )
  {
    if ( v4 )
      result = FLOAT_60_0;
    else
      result = 0.0;
  }
  if ( v1->m_bTemporaryAllowedToPass )
  {
    if ( v4 )
      result = FLOAT_60_0;
    else
      result = 0.0;
  }
  return result;
}

// File Line: 5010
// RVA: 0x649960
void __fastcall UFG::AiDriverComponent::ComputeAvoidanceLimits(UFG::AiDriverComponent *this, UFG::qVector3 *my_position, UFG::qVector3 *avoid_hull, UFG::qVector3 *left_limit, UFG::qVector3 *right_limit, UFG::qVector3 *close_limit)
{
  UFG::qVector3 *v6; // r10
  int v7; // er11
  UFG::qVector3 *v8; // r13
  signed __int64 v9; // rsi
  signed __int64 v10; // r14
  signed __int64 v11; // r15
  signed __int64 v12; // r12
  float v13; // xmm4_4
  int v14; // ebx
  int v15; // edi
  char *v16; // r9
  char *v17; // r8
  signed int v18; // ecx
  float *v19; // rdx
  signed __int64 v20; // rbp
  float v21; // xmm2_4
  float v22; // xmm6_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float v25; // xmm5_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // eax

  v6 = avoid_hull;
  v7 = 0;
  v8 = left_limit;
  v9 = -8i64 - (_QWORD)avoid_hull;
  v10 = 4i64 - (_QWORD)avoid_hull;
  v11 = 16i64 - (_QWORD)avoid_hull;
  v12 = 28i64 - (_QWORD)avoid_hull;
  v13 = (float)((float)(avoid_hull->x * avoid_hull->x) + (float)(avoid_hull->y * avoid_hull->y))
      + (float)(avoid_hull->z * avoid_hull->z);
  v14 = 0;
  v15 = 0;
  v16 = 0i64;
  v17 = 0i64;
  v18 = 3;
  v19 = &v6[2].z;
  v20 = -20i64 - (_QWORD)v6;
  do
  {
    v21 = *(v19 - 4);
    v22 = *(v19 - 5);
    v23 = (float)((float)(v22 * v22) + (float)(v21 * v21)) + (float)(*(v19 - 3) * *(v19 - 3));
    v24 = (float)(v22 * *(float *)((char *)&v6->y + (_QWORD)v16))
        - (float)(v21 * *(float *)((char *)&v6->x + (_QWORD)v16));
    if ( v23 < v13 )
    {
      v13 = v23;
      v15 = v18 - 2;
    }
    if ( v24 > 0.0 )
    {
      v7 = v18 - 2;
      v16 = (char *)v19 + v20;
    }
    if ( (float)((float)(*(v19 - 5) * *(float *)((char *)&v6->y + (_QWORD)v17))
               - (float)(*(v19 - 4) * *(float *)((char *)&v6->x + (_QWORD)v17))) < 0.0 )
    {
      v14 = v18 - 2;
      v17 = (char *)v19 + v20;
    }
    v25 = *(v19 - 2);
    v26 = (float)((float)(*(v19 - 1) * *(v19 - 1)) + (float)(*(v19 - 2) * v25)) + (float)(*v19 * *v19);
    v27 = *(v19 - 1);
    v28 = (float)(v25 * *(float *)((char *)&v6->y + (_QWORD)v16))
        - (float)(v27 * *(float *)((char *)&v6->x + (_QWORD)v16));
    if ( v26 < v13 )
    {
      v13 = v26;
      v15 = v18 - 1;
    }
    if ( v28 > 0.0 )
    {
      v7 = v18 - 1;
      v16 = (char *)v19 + v9;
    }
    if ( (float)((float)(*(v19 - 2) * *(float *)((char *)&v6->y + (_QWORD)v17))
               - (float)(v27 * *(float *)((char *)&v6->x + (_QWORD)v17))) < 0.0 )
    {
      v14 = v18 - 1;
      v17 = (char *)v19 + v9;
    }
    v29 = v19[2];
    if ( (float)((float)((float)(v19[2] * v19[2]) + (float)(v19[1] * v19[1])) + (float)(v19[3] * v19[3])) < v13 )
    {
      v13 = (float)((float)(v19[2] * v19[2]) + (float)(v19[1] * v19[1])) + (float)(v19[3] * v19[3]);
      v15 = v18;
    }
    if ( (float)((float)(v19[1] * *(float *)((char *)&v6->y + (_QWORD)v16))
               - (float)(v29 * *(float *)((char *)&v6->x + (_QWORD)v16))) > 0.0 )
    {
      v7 = v18;
      v16 = (char *)v19 + v10;
    }
    if ( (float)((float)(v19[1] * *(float *)((char *)&v6->y + (_QWORD)v17))
               - (float)(v29 * *(float *)((char *)&v6->x + (_QWORD)v17))) < 0.0 )
    {
      v14 = v18;
      v17 = (char *)v19 + v10;
    }
    v30 = v19[5];
    if ( (float)((float)((float)(v19[5] * v19[5]) + (float)(v19[4] * v19[4])) + (float)(v19[6] * v19[6])) < v13 )
    {
      v13 = (float)((float)(v19[5] * v19[5]) + (float)(v19[4] * v19[4])) + (float)(v19[6] * v19[6]);
      v15 = v18 + 1;
    }
    if ( (float)((float)(v19[4] * *(float *)((char *)&v6->y + (_QWORD)v16))
               - (float)(v30 * *(float *)((char *)&v6->x + (_QWORD)v16))) > 0.0 )
    {
      v7 = v18 + 1;
      v16 = (char *)v19 + v11;
    }
    if ( (float)((float)(v19[4] * *(float *)((char *)&v6->y + (_QWORD)v17))
               - (float)(v30 * *(float *)((char *)&v6->x + (_QWORD)v17))) < 0.0 )
    {
      v14 = v18 + 1;
      v17 = (char *)v19 + v11;
    }
    v31 = v19[8];
    if ( (float)((float)((float)(v19[7] * v19[7]) + (float)(v19[8] * v19[8])) + (float)(v19[9] * v19[9])) < v13 )
    {
      v13 = (float)((float)(v19[7] * v19[7]) + (float)(v19[8] * v19[8])) + (float)(v19[9] * v19[9]);
      v15 = v18 + 2;
    }
    if ( (float)((float)(v19[7] * *(float *)((char *)&v6->y + (_QWORD)v16))
               - (float)(v31 * *(float *)((char *)&v6->x + (_QWORD)v16))) > 0.0 )
    {
      v7 = v18 + 2;
      v16 = (char *)v19 + v12;
    }
    if ( (float)((float)(v19[7] * *(float *)((char *)&v6->y + (_QWORD)v17))
               - (float)(v31 * *(float *)((char *)&v6->x + (_QWORD)v17))) < 0.0 )
    {
      v14 = v18 + 2;
      v17 = (char *)v19 + v12;
    }
    v18 += 5;
    v19 += 15;
  }
  while ( v18 - 2 < 16 );
  v32 = v6[v7].y;
  v33 = v6[v7].z;
  right_limit->x = v6[v7].x;
  right_limit->y = v32;
  right_limit->z = v33;
  v34 = v6[v14].y;
  v35 = v6[v14].z;
  v8->x = v6[v14].x;
  v8->y = v34;
  v8->z = v35;
  v36 = v6[v15].z;
  v37 = v6[v15].x;
  close_limit->y = v6[v15].y;
  close_limit->z = v36;
  close_limit->x = v37;
}

// File Line: 5082
// RVA: 0x65B0B0
UFG::qVector3 *__fastcall UFG::AiDriverComponent::SteerToAvoidGeometry(UFG::AiDriverComponent *this, UFG::qVector3 *result, UFG::qVector3 *steer_to_position, float steer_to_distance)
{
  float v4; // xmm6_4
  UFG::qVector3 *v5; // rdi
  UFG::qVector3 *v6; // rbx
  UFG::AiDriverComponent *v7; // r15
  Render::DebugDrawContext *v8; // r12
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm13_4
  UFG::SimComponent *v12; // r14
  hkpPhantom *v13; // rdx
  UFG::qVector3 *v14; // rsi
  float v15; // xmm10_4
  float v16; // xmm5_4
  float v17; // xmm11_4
  float v18; // xmm4_4
  float v19; // xmm12_4
  __m128 v20; // xmm7
  __m128 v21; // xmm2
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  UFG::SimComponent *v25; // rax
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  __m128 v30; // xmm10
  float v31; // xmm12_4
  float v32; // xmm11_4
  float v33; // xmm13_4
  __m128 v34; // xmm2
  float v35; // xmm7_4
  float v36; // xmm9_4
  float v37; // xmm8_4
  float v38; // xmm7_4
  float v39; // xmm14_4
  float v40; // xmm15_4
  float v41; // xmm6_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  UFG::qVector3 *v46; // rax
  float v47; // xmm6_4
  float v48; // xmm0_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  __int128 p1; // [rsp+40h] [rbp-88h]
  float v53; // [rsp+50h] [rbp-78h]
  float v54; // [rsp+54h] [rbp-74h]
  float v55; // [rsp+58h] [rbp-70h]
  float v56; // [rsp+5Ch] [rbp-6Ch]
  float v57; // [rsp+60h] [rbp-68h]
  float v58; // [rsp+64h] [rbp-64h]
  __m128 v59; // [rsp+68h] [rbp-60h]
  void **v60; // [rsp+78h] [rbp-50h]
  int v61; // [rsp+80h] [rbp-48h]
  char v62; // [rsp+88h] [rbp-40h]
  unsigned __int64 v63; // [rsp+98h] [rbp-30h]
  float v64; // [rsp+A0h] [rbp-28h]
  __m128 v65; // [rsp+A8h] [rbp-20h]
  __m128 v66; // [rsp+B8h] [rbp-10h]
  int v67; // [rsp+C8h] [rbp+0h]
  int v68; // [rsp+CCh] [rbp+4h]
  __int64 v69; // [rsp+D8h] [rbp+10h]
  float v70; // [rsp+1C8h] [rbp+100h]
  float v71; // [rsp+1D8h] [rbp+110h]
  float radius; // [rsp+1E0h] [rbp+118h]
  float *v73; // [rsp+1E8h] [rbp+120h]

  v69 = -2i64;
  v4 = steer_to_distance;
  v5 = steer_to_position;
  v6 = result;
  v7 = this;
  v8 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  v9 = v5->x;
  v56 = v5->x;
  v10 = v5->y;
  v55 = v5->y;
  v11 = v5->z;
  v57 = v5->z;
  v12 = v7->m_pVehicleSubject.m_pSimComponent;
  if ( v12 )
  {
    v13 = (hkpPhantom *)&v7->m_pCastingPhantom->vfptr;
    if ( !v13->m_world )
      UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, v13, 0);
    v14 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *))v12->vfptr[17].__vecDelDtor)(v12);
    v15 = v14->z;
    v16 = v5->z - v15;
    v17 = v14->y;
    v18 = v5->y - v17;
    v19 = v14->x;
    v20 = (__m128)LODWORD(v5->x);
    v20.m128_f32[0] = v20.m128_f32[0] - v14->x;
    v21 = v20;
    v21.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v18 * v18)) + (float)(v16 * v16);
    LODWORD(v22) = (unsigned __int128)_mm_sqrt_ps(v21);
    v23 = FLOAT_0_000099999997;
    if ( v22 >= 0.000099999997 )
      v23 = v22;
    if ( v4 < v23 )
    {
      v20.m128_f32[0] = v20.m128_f32[0] * (float)(v4 / v23);
      v18 = (float)(v4 / v23) * v18;
      v16 = (float)(v4 / v23) * v16;
    }
    v24 = fsqrt((float)((float)(v18 * v18) + (float)(v20.m128_f32[0] * v20.m128_f32[0])) + (float)(v16 * v16));
    v25 = v7->m_pRoadSpace.m_pSimComponent;
    v26 = v17
        + (float)((float)(v24 * *((float *)&v25[27].m_pSimObject + 1))
                + (float)((float)(v18 - (float)(v24 * *((float *)&v25[27].m_pSimObject + 1))) * 0.25));
    v27 = v19
        + (float)((float)((float)(v20.m128_f32[0] - (float)(v24 * *(float *)&v25[27].m_pSimObject)) * 0.25)
                + (float)(v24 * *(float *)&v25[27].m_pSimObject));
    v28 = UFG::qVector3::msDirUp.y * (float)(UFG::AiDriverComponent::m_fAvoidanceCastingRadius + 0.40000001);
    v29 = UFG::qVector3::msDirUp.x * (float)(UFG::AiDriverComponent::m_fAvoidanceCastingRadius + 0.40000001);
    v53 = v19 + v29;
    v54 = v17 + v28;
    v55 = v15
        + (float)(UFG::qVector3::msDirUp.z * (float)(UFG::AiDriverComponent::m_fAvoidanceCastingRadius + 0.40000001));
    v57 = v29 + v27;
    v58 = v28 + v26;
    v60 = &hkpSimpleClosestContactCollector::`vftable;
    v62 = 0;
    v65 = _mm_shuffle_ps(v65, _mm_unpackhi_ps(v65, (__m128)xmmword_141A712A0), 196);
    v61 = 2139095022;
    v67 = 872415232;
    v68 = 872415232;
    v59 = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT(v19 + v29), (__m128)LODWORD(v55)),
            _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT(v17 + v28), (__m128)(unsigned int)FLOAT_1_0));
    v66 = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT(v29 + v27), (__m128)v59.m128_u32[0]),
            _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT(v28 + v26), (__m128)(unsigned int)FLOAT_1_0));
    ((void (__fastcall *)(hkpSimpleShapePhantom *, __m128 *, __m128 *, void ***, void ***))v7->m_pCastingPhantom->vfptr[7].__first_virtual_table_function__)(
      v7->m_pCastingPhantom,
      &v59,
      &v66,
      &v60,
      &v60);
    if ( v62 )
    {
      v30 = (__m128)(unsigned int)v63;
      v59.m128_u64[0] = v63;
      v31 = *((float *)&v63 + 1);
      v32 = v64;
      v59.m128_f32[2] = v64;
      v71 = v55 - *(float *)&v63;
      v33 = v54 - v58;
      v70 = v53 - v57;
      *((_QWORD *)&p1 + 1) = v63;
      v53 = v64;
      v34 = (__m128)v65.m128_u32[1];
      v34.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v65.m128_f32[0] * v65.m128_f32[0]))
                      + (float)(v65.m128_f32[2] * v65.m128_f32[2]);
      if ( v34.m128_f32[0] == 0.0 )
        v35 = 0.0;
      else
        v35 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v34));
      v36 = v35 * v65.m128_f32[2];
      v37 = v35 * v65.m128_f32[1];
      v38 = v35 * v65.m128_f32[0];
      v39 = UFG::qVector3::msDirUp.x;
      v40 = UFG::qVector3::msDirUp.y;
      v41 = (float)((float)(UFG::qVector3::msDirUp.x * v38) + (float)(v37 * UFG::qVector3::msDirUp.y))
          + (float)(v36 * UFG::qVector3::msDirUp.z);
      if ( v41 > cosf(1.0471976) )
      {
        v9 = v56;
        v10 = v55;
        v11 = v57;
      }
      else
      {
        *(_QWORD *)&p1 = __PAIR__(LODWORD(v37), LODWORD(v38));
        *((float *)&p1 + 2) = v36;
        if ( (float)((float)((float)(v38 * v70) + (float)(v37 * v33)) + (float)(v36 * v71)) > 0.0 )
        {
          if ( (float)((float)(v37 * v70) - (float)(v33 * v38)) <= 0.0 )
          {
            v42 = (float)(v40 * v38) - (float)(v37 * v39);
            v43 = (float)(v36 * v39) - (float)(UFG::qVector3::msDirUp.z * v38);
            v44 = v37 * UFG::qVector3::msDirUp.z;
            v45 = v36 * v40;
          }
          else
          {
            v42 = (float)(v37 * v39) - (float)(v40 * v38);
            v43 = (float)(UFG::qVector3::msDirUp.z * v38) - (float)(v36 * v39);
            v44 = v36 * v40;
            v45 = v37 * UFG::qVector3::msDirUp.z;
          }
          *(_QWORD *)((char *)&p1 + 4) = __PAIR__(LODWORD(v42), LODWORD(v43));
          *(float *)&p1 = v44 - v45;
        }
        *((float *)&p1 + 2) = (float)(v38 * 1.5) + v30.m128_f32[0];
        *((float *)&p1 + 3) = (float)(v37 * 1.5) + v31;
        v53 = (float)(v36 * 1.5) + v32;
        v46 = UFG::RoadSpaceComponent::SteerTo(
                (UFG::qVector3 *)&v59.m128_u16[4],
                v14,
                radius,
                (UFG::qVector3 *)((char *)&p1 + 8),
                (UFG::qVector3 *)&p1);
        v9 = v46->x;
        v10 = v46->y;
        v11 = v46->z;
        v30.m128_f32[0] = (float)((float)((float)(v30.m128_f32[0] - v14->x) * (float)(v30.m128_f32[0] - v14->x))
                                + (float)((float)(v31 - v14->y) * (float)(v31 - v14->y)))
                        + (float)((float)(v32 - v14->z) * (float)(v32 - v14->z));
        v47 = COERCE_FLOAT(_mm_sqrt_ps(v30))
            - *(float *)((__int64 (__fastcall *)(UFG::SimComponent *))v12->vfptr[24].__vecDelDtor)(v12);
        v48 = *v73;
        if ( *v73 >= v47 )
          v48 = v47;
        *v73 = v48;
        if ( v7->m_AvoidanceDebug )
        {
          Render::DebugDrawContext::DrawPillar(
            v8,
            v5,
            0.17,
            0.17,
            &UFG::qColour::DodgerBlue,
            &UFG::qMatrix44::msIdentity,
            0i64);
          *(float *)&p1 = v9 + (float)(UFG::qVector3::msDirUp.x * 0.69999999);
          *((float *)&p1 + 1) = v10 + (float)(UFG::qVector3::msDirUp.y * 0.69999999);
          *((float *)&p1 + 2) = v11 + (float)(UFG::qVector3::msDirUp.z * 0.69999999);
          v49 = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + v5->z;
          v50 = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + v5->y;
          v59.m128_f32[2] = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + v5->x;
          v59.m128_f32[3] = v50;
          *(float *)&v60 = v49;
          Render::DebugDrawContext::DrawLine(
            v8,
            (UFG::qVector3 *)&v59.m128_u16[4],
            (UFG::qVector3 *)&p1,
            &UFG::qColour::DodgerBlue,
            &UFG::qMatrix44::msIdentity,
            0i64,
            0);
          v59.m128_f32[2] = v9 + (float)(UFG::qVector3::msDirUp.x * 0.69999999);
          v59.m128_f32[3] = v10 + (float)(UFG::qVector3::msDirUp.y * 0.69999999);
          *(float *)&v60 = v11 + (float)(UFG::qVector3::msDirUp.z * 0.69999999);
          Render::DebugDrawContext::DrawSphere(
            v8,
            (UFG::qVector3 *)&v59.m128_u16[4],
            0.69999999,
            &UFG::qColour::DodgerBlue,
            &UFG::qMatrix44::msIdentity,
            0i64);
        }
      }
    }
    v6->x = v9;
    v6->y = v10;
    v6->z = v11;
    v60 = &hkpCdPointCollector::`vftable;
  }
  else
  {
    v6->x = v9;
    v6->y = v10;
    v6->z = v11;
  }
  return v6;
}

// File Line: 5371
// RVA: 0x652500
bool __fastcall UFG::AiDriverComponent::LaneContainsPlayer(UFG::AiDriverComponent *this, UFG::RoadNetworkGuide *guide)
{
  UFG::RoadNetworkGuide *v2; // rbx
  unsigned __int16 v3; // r8
  UFG::CharacterOccupantComponent *v4; // rax
  UFG::SimObjectGame *v5; // rax
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  bool result; // al

  v2 = guide;
  if ( LocalPlayer
    && ((v3 = LocalPlayer->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v4 = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent),
        v4
     && (v5 = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v4)) != 0i64
     && ((v6 = v5->m_Flags, !((v6 >> 14) & 1)) ? ((v6 & 0x8000u) == 0 ? (!((v6 >> 13) & 1) ? (!((v6 >> 12) & 1) ? (v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RoadSpaceComponent::_TypeUID))) : (v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RoadSpaceComponent::_TypeUID))) : (v7 = v5->m_Components.p[24].m_pComponent)) : (v7 = v5->m_Components.p[24].m_pComponent),
         v7 && v7 != (UFG::SimComponent *)-376i64)) )
  {
    result = v2->m_CurrentLocation.m_CurrentLane == (UFG::RoadNetworkLane *)v7[6].m_BoundComponentHandles.mNode.mNext;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 5396
// RVA: 0x65DCB0
UFG::qVector3 *__fastcall UFG::AiDriverComponent::SteerToBetterLane(UFG::AiDriverComponent *this, UFG::qVector3 *result, UFG::qVector3 *steer_to_position)
{
  UFG::SimComponent *v3; // rsi
  float v4; // xmm6_4
  float v5; // xmm7_4
  UFG::qVector3 *v6; // rdi
  UFG::AiDriverComponent *v7; // rbp
  float v8; // xmm8_4
  UFG::RoadNetworkGuide *v10; // rsi
  UFG::RoadNetworkGuide *v11; // rcx
  UFG::SimObjectVehicle *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::CarPhysicsMoverComponent *v14; // rax
  UFG::RoadNetworkLane *v15; // rbx
  bool v16; // cl
  UFG::RoadNetworkNode *v17; // r14
  signed int v18; // er15
  unsigned int v19; // er12
  UFG::RoadNetworkLane *v20; // r14
  UFG::RoadNetworkLocation *v21; // rax
  float v22; // xmm0_4
  unsigned int v23; // ebx
  UFG::RoadNetworkLocation *v24; // rax
  float v25; // xmm0_4
  UFG::RoadNetworkLocation *v26; // rax
  float v27; // xmm1_4
  float v28; // xmm0_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-68h]
  unsigned int whichLanes; // [rsp+90h] [rbp+8h]

  v3 = this->m_pRoadSpace.m_pSimComponent;
  v4 = steer_to_position->x;
  v5 = steer_to_position->y;
  v6 = result;
  v7 = this;
  v8 = steer_to_position->z;
  if ( !v3
    || (v10 = (UFG::RoadNetworkGuide *)&v3[5].m_BoundComponentHandles.mNode.mNext, !v10->m_Attached)
    || (v11 = v10->m_NextGuide.m_pPointer) == 0i64 )
  {
    result->x = v4;
    result->y = v5;
    result->z = v8;
    return result;
  }
  v12 = (UFG::SimObjectVehicle *)v11->m_SimObj;
  if ( !v12
    || (v13 = v12->m_Flags, (v13 >> 14) & 1)
    || ((v13 & 0x8000u) == 0 ? (!((v13 >> 13) & 1) ? (!((v13 >> 12) & 1) ? (v14 = (UFG::CarPhysicsMoverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::CarPhysicsMoverComponent::_TypeUID)) : (v14 = (UFG::CarPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v12->vfptr, UFG::CarPhysicsMoverComponent::_TypeUID))) : (v14 = (UFG::CarPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v12->vfptr, UFG::CarPhysicsMoverComponent::_TypeUID))) : (v14 = UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>(v12)),
        !v14) )
  {
    v6->x = v4;
    v6->y = v5;
    v6->z = v8;
    return v6;
  }
  if ( v14->mForwardSpeed >= 0.0049999999 )
    goto LABEL_34;
  whichLanes = -1;
  v15 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v10)->m_CurrentLane;
  if ( UFG::PhysicsMoverInterface::GetLOD((UFG::PhysicsMoverInterface *)v7->mMoverComponent.m_pSimComponent) != 1
    && UFG::RoadNetworkGuide::LaneChangeAvailable(v10, &whichLanes) )
  {
    v16 = UFG::AiDriverComponent::LaneContainsPlayer(v7, v10) == 0;
  }
  else
  {
    v16 = 0;
  }
  v17 = (UFG::RoadNetworkNode *)(v15->mNode.mOffset ? (UFG::RoadNetworkLane *)((char *)v15 + v15->mNode.mOffset) : 0i64);
  if ( !v16 )
    goto LABEL_34;
  if ( whichLanes == 2 )
  {
    v18 = 2;
  }
  else
  {
    if ( whichLanes != 1 )
    {
LABEL_34:
      v6->x = v4;
      v6->y = v5;
      v6->z = v8;
      return v6;
    }
    v18 = 1;
  }
  v19 = UFG::RoadNetworkGuide::GetChangeLaneIndex(v10, v18);
  v20 = UFG::RoadNetworkNode::GetLane(v17, v19);
  v21 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v10);
  v22 = UFG::RoadNetworkLocation::GetDistanceAlongSpline(v21);
  v23 = UFG::RoadNetworkLane::GetNumberOfCarsInLaneAheadOfDistance(v15, v22);
  v24 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v10);
  v25 = UFG::RoadNetworkLocation::GetDistanceAlongSpline(v24);
  if ( (unsigned int)UFG::RoadNetworkLane::GetNumberOfCarsInLaneAheadOfDistance(v20, v25) >= v23
    || !UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(v10, v20)
    || !UFG::RoadNetworkGuide::TryGetPossibleSharedDestination(
          v10,
          v19,
          (unsigned int)v7->m_pRoadSpace.m_pSimComponent[30].m_SafePointerList.mNode.mNext) )
  {
    goto LABEL_34;
  }
  UFG::AiDriverComponent::ChangeLane(v7, (UFG::RoadNetworkLane::LaneChangeDirection)v18);
  v26 = (UFG::RoadNetworkLocation *)UFG::RoadNetworkGuide::GetTargetLocation((UFG::RippleGenerator *)v10);
  UFG::RoadNetworkLocation::GetPos(v26, &resulta);
  v27 = resulta.y;
  v6->x = resulta.x;
  v28 = resulta.z;
  v6->y = v27;
  v6->z = v28;
  return v6;
}

// File Line: 5491
// RVA: 0x652630
char __fastcall UFG::AiDriverComponent::AvoidableOverlap::MergeLimits(UFG::AiDriverComponent::AvoidableOverlap *this, UFG::AiDriverComponent::AvoidableOverlap *overlap)
{
  float v2; // xmm5_4
  float v3; // xmm3_4
  char result; // al
  float v5; // xmm7_4
  float v6; // xmm8_4
  float v7; // xmm4_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm6_4
  float v18; // xmm4_4
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm5_4
  float v22; // xmm9_4
  bool v23; // r8

  v2 = overlap->m_LeftRay.y;
  v3 = overlap->m_LeftRay.x;
  result = 0;
  v5 = this->m_LeftRay.x;
  v6 = this->m_LeftRay.y;
  v7 = overlap->m_LeftRay.x * v6;
  v8 = this->m_LeftRay.x * v2;
  if ( (float)(v8 - v7) > 0.0
    && (float)((float)(v5 * overlap->m_RightRay.y) - (float)(v6 * overlap->m_RightRay.x)) < 0.0 )
  {
    v9 = overlap->m_LeftRay.z;
    this->m_LeftRay.x = v3;
    this->m_LeftRay.y = v2;
    this->m_LeftRay.z = v9;
LABEL_7:
    result = 1;
    goto LABEL_8;
  }
  if ( (float)(v7 - v8) > 0.0 && (float)((float)(v3 * this->m_RightRay.y) - (float)(v2 * this->m_RightRay.x)) < 0.0 )
  {
    v10 = this->m_LeftRay.z;
    overlap->m_LeftRay.x = v5;
    overlap->m_LeftRay.y = v6;
    overlap->m_LeftRay.z = v10;
    goto LABEL_7;
  }
LABEL_8:
  v11 = this->m_RightRay.x;
  v12 = this->m_RightRay.y;
  if ( (float)((float)(this->m_RightRay.x * overlap->m_LeftRay.y) - (float)(this->m_RightRay.y * overlap->m_LeftRay.x)) <= 0.0
    || (v13 = overlap->m_RightRay.y, v14 = overlap->m_RightRay.x,
                                     (float)((float)(v11 * v13) - (float)(v12 * v14)) >= 0.0) )
  {
    if ( (float)((float)(overlap->m_RightRay.x * this->m_LeftRay.y) - (float)(overlap->m_RightRay.y * this->m_LeftRay.x)) <= 0.0
      || (float)((float)(overlap->m_RightRay.x * v12) - (float)(overlap->m_RightRay.y * v11)) >= 0.0 )
    {
      if ( !result )
        return result;
    }
    else
    {
      v16 = this->m_RightRay.z;
      overlap->m_RightRay.x = v11;
      result = 1;
      overlap->m_RightRay.z = v16;
      overlap->m_RightRay.y = v12;
    }
  }
  else
  {
    v15 = overlap->m_RightRay.z;
    this->m_RightRay.x = v14;
    result = 1;
    this->m_RightRay.z = v15;
    this->m_RightRay.y = v13;
  }
  v17 = this->m_CloseLimit.y;
  v18 = this->m_CloseLimit.x;
  v19 = this->m_CloseLimit.z;
  v20 = overlap->m_CloseLimit.y;
  v21 = overlap->m_CloseLimit.x;
  v22 = overlap->m_CloseLimit.z;
  if ( (float)((float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(v19 * v19)) >= (float)((float)((float)(v21 * v21) + (float)(v20 * v20))
                                                                                               + (float)(v22 * v22)) )
  {
    this->m_CloseLimit.x = v21;
    this->m_CloseLimit.y = v20;
    this->m_CloseLimit.z = v22;
  }
  else
  {
    overlap->m_CloseLimit.x = v18;
    overlap->m_CloseLimit.y = v17;
    overlap->m_CloseLimit.z = v19;
  }
  v23 = this->m_CoChaser && overlap->m_CoChaser;
  overlap->m_CoChaser = v23;
  this->m_CoChaser = v23;
  ++overlap->m_Generation;
  ++this->m_Generation;
  return result;
}

// File Line: 5553
// RVA: 0x644800
void __fastcall UFG::AiDriverComponent::AddAvoidableOverlap(UFG::AiDriverComponent *this, UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> *list, UFG::CameraSubject *avoidable_subject, UFG::AiDriverComponent::TimeWindowResult *time_window, bool co_chaser)
{
  UFG::AiDriverComponent::TimeWindowResult *v5; // rdi
  UFG::CameraSubject *v6; // rsi
  UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // r10
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v10; // rcx
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v12; // rax

  v5 = time_window;
  v6 = avoidable_subject;
  v7 = list;
  v8 = UFG::qMalloc(0x58ui64, "AvoidableOverlap", 0i64);
  v9 = v8;
  if ( v8 )
  {
    v8->mNext = v8;
    v8[1].mNext = v8;
    HIDWORD(v8[2].mNext) = 0;
    LOBYTE(v8[2].mNext) = co_chaser;
    *(float *)&v8[3].mNext = v5->fClosingSpeed;
    HIDWORD(v8[3].mNext) = LODWORD(v5->fEarliest);
    *(float *)&v8[4].mNext = v5->fLatest;
    v8[5].mNext = (UFG::allocator::free_link *)v6;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = v7->mNode.mNext;
  if ( v10 == (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)v7 )
    goto LABEL_9;
  while ( v5->fEarliest <= *((float *)&v10[1].mNext + 1) )
  {
    v10 = v10->mNext;
    if ( v10 == (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)v7 )
      goto LABEL_9;
  }
  v11 = (UFG::allocator::free_link *)v10->mPrev;
  v11[1].mNext = v9;
  v9->mNext = v11;
  v9[1].mNext = (UFG::allocator::free_link *)v10;
  v10->mPrev = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)v9;
  if ( v10 == (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)v7 )
  {
LABEL_9:
    v12 = v7->mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)v9;
    v9->mNext = (UFG::allocator::free_link *)v12;
    v9[1].mNext = (UFG::allocator::free_link *)v7;
    v7->mNode.mPrev = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)v9;
  }
}

// File Line: 5570
// RVA: 0x651330
void __usercall UFG::AiDriverComponent::HandleCollision(UFG::AiDriverComponent *this@<rcx>, UFG::SimObject *pAttackerSimObject@<rdx>, float damage@<xmm2>, __int64 dt@<r9>, __int64 a5@<r8>)
{
  UFG::SimComponent *v5; // rax
  UFG::AiDriverComponent *v6; // rdi
  UFG::SimComponent *v7; // rcx
  bool v8; // dl
  UFG::SimObject *v9; // rcx
  UFG::TransformNodeComponent *v10; // rsi
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rbx
  float *v13; // rax

  v5 = this->mMoverComponent.m_pSimComponent;
  v6 = this;
  if ( v5
    && (float)(3.5999999 * *((float *)&v5[10].m_BoundComponentHandles.mNode.mPrev + 1)) > UFG::gHighSpeedCollisionThreshold )
  {
    v7 = this->m_pChaseVehicleSubject.m_pPointer;
    v8 = v7
      && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *, UFG::SimObject *, __int64, __int64))v7->vfptr[46].__vecDelDtor)(
           v7,
           pAttackerSimObject,
           a5,
           dt);
    v9 = v6->m_pSimObject;
    v10 = 0i64;
    v11 = v9 ? v9->m_Components.p[16].m_pComponent : 0i64;
    if ( v8 && v11 )
    {
      if ( v9 )
        v10 = (UFG::TransformNodeComponent *)v9->m_Components.p[2].m_pComponent;
      v12 = v6->m_pChaseVehicleSubject.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform(v10);
      v13 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v12->vfptr[17].__vecDelDtor)(v12);
      if ( (float)((float)((float)(v13[1] - v10->mWorldTransform.v3.y) * (float)(v13[1] - v10->mWorldTransform.v3.y))
                 + (float)((float)(*v13 - v10->mWorldTransform.v3.x) * (float)(*v13 - v10->mWorldTransform.v3.x))) < UFG::gHighSpeedCollisionDistanceSqToChaseeThreshold )
        v6->m_iLastHighSpeedCollisionTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    }
  }
}

// File Line: 5591
// RVA: 0x659B70
char __fastcall UFG::AiDriverComponent::ShouldAvoid(UFG::AiDriverComponent *this, UFG::VehicleSubjectComponent *my_subject, UFG::CameraSubject *avoidable_subject, bool *co_chaser)
{
  bool *v4; // r15
  UFG::CameraSubject *v5; // rdi
  UFG::VehicleSubjectComponent *v6; // r14
  UFG::AiDriverComponent *v7; // rsi
  char result; // al
  bool v9; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v10; // rax
  bool v11; // bp
  __int64 v12; // r15
  bool v13; // bl
  float *v14; // rax
  float v15; // xmm6_4
  float v16; // xmm12_4
  float v17; // xmm7_4
  float *v18; // rax
  float v19; // xmm9_4
  float v20; // xmm10_4
  float v21; // xmm12_4
  float *v22; // rax
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm8_4
  float *v26; // rax
  UFG::SimObjectCVBase *v27; // rbp
  _WORD *v28; // r12
  hkLocalFrameGroup *v29; // rbx
  UFG::SimComponent *v30; // rax
  unsigned __int16 v31; // cx
  UFG::SimObjectCVBase *v32; // rbx
  UFG::SimObject *v33; // rbx
  char v34; // cl
  unsigned __int16 v35; // cx
  UFG::AiDriverComponent *v36; // rax
  UFG::SimComponent *v37; // rcx
  char v38; // al
  signed __int64 v39; // rbx
  UFG::RoadNetworkLane *v40; // rcx
  __int64 v41; // rcx

  v4 = co_chaser;
  v5 = avoidable_subject;
  v6 = my_subject;
  v7 = this;
  if ( !avoidable_subject )
    return 0;
  *co_chaser = 0;
  v9 = ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[41].__vecDelDtor)(avoidable_subject) == 0;
  v10 = v5->vfptr;
  if ( v9 )
  {
    if ( ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))v10[37].__vecDelDtor)(v5) )
    {
      v27 = (UFG::SimObjectCVBase *)v5->m_pSimObject;
      v28 = 0i64;
      if ( v7->m_DrivingMode == 2 )
      {
        v29 = (hkLocalFrameGroup *)v7->m_PathingTarget.m_pPointer;
        if ( v29 )
        {
          if ( v27 == (UFG::SimObjectCVBase *)v29 )
            goto LABEL_106;
          if ( v27 )
          {
            v31 = v27->m_Flags;
            if ( (v31 >> 14) & 1 )
            {
              v30 = UFG::SimObjectGame::GetComponentOfTypeHK(
                      (UFG::SimObjectGame *)&v27->vfptr,
                      UFG::VehicleOccupantComponent::_TypeUID);
            }
            else if ( (v31 & 0x8000u) == 0 )
            {
              if ( (v31 >> 13) & 1 )
                v30 = UFG::SimObjectGame::GetComponentOfTypeHK(
                        (UFG::SimObjectGame *)&v27->vfptr,
                        UFG::VehicleOccupantComponent::_TypeUID);
              else
                v30 = (v31 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v27->vfptr,
                                          UFG::VehicleOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v27->vfptr,
                                                                                       UFG::VehicleOccupantComponent::_TypeUID);
            }
            else
            {
              v30 = v27->m_Components.p[30].m_pComponent;
            }
          }
          else
          {
            v30 = 0i64;
          }
          if ( Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v30) == v29 )
            goto LABEL_106;
        }
      }
      v32 = (UFG::SimObjectCVBase *)v7->m_pRoadSpace.m_pSimComponent[26].m_pSimObject;
      if ( v32 )
      {
        if ( v32 == v27 )
        {
          *v4 = 1;
          if ( v7->m_DrivingMode == 3 && v7->m_DesiredOffset == 1 )
            goto LABEL_106;
          if ( v7->m_fTimeNearOffset > 0.0 || v7->m_CurrentAttack != 7 )
            goto LABEL_106;
        }
        if ( v32 == (UFG::SimObjectCVBase *)((__int64 (__fastcall *)(UFG::CameraSubject *))v5->vfptr[25].__vecDelDtor)(v5) )
        {
          *v4 = 1;
          if ( v7->m_CurrentAttack != 7
            || ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))v5->vfptr[40].__vecDelDtor)(v5) )
          {
            goto LABEL_106;
          }
        }
        if ( v5 == (UFG::CameraSubject *)v7->m_pEscortEnemyVehicleSubject.m_pPointer )
          goto LABEL_106;
      }
      if ( ((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))v6->vfptr[46].__vecDelDtor)(v6) )
      {
        v33 = v6->m_pSimObject;
        if ( v33 == (UFG::SimObject *)((__int64 (__fastcall *)(UFG::CameraSubject *))v5->vfptr[25].__vecDelDtor)(v5) )
          goto LABEL_106;
      }
      v34 = v7->m_bAllowedToPass || v7->m_bTemporaryAllowedToPass ? 1 : 0;
      if ( !LOBYTE(v7->m_pRoadSpace.m_pSimComponent[8].m_Flags) || v34 || UFG::VehicleSubjectComponent::IsBoat(v6) )
        goto LABEL_107;
      if ( ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))v5->vfptr[33].__vecDelDtor)(v5) )
        goto LABEL_106;
      if ( !v27 )
        goto LABEL_107;
      v35 = v27->m_Flags;
      if ( (v35 >> 14) & 1 )
      {
        v36 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v27);
      }
      else if ( (v35 & 0x8000u) == 0 )
      {
        if ( (v35 >> 13) & 1 )
          v36 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v27->vfptr,
                                            UFG::AiDriverComponent::_TypeUID);
        else
          v36 = (UFG::AiDriverComponent *)((v35 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v27->vfptr,
                                                               UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v27->vfptr,
                                                                                                     UFG::AiDriverComponent::_TypeUID));
      }
      else
      {
        v36 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v27);
      }
      if ( !v36 )
        goto LABEL_107;
      v37 = v36->m_pRoadSpace.m_pSimComponent;
      if ( !v37 )
        goto LABEL_107;
      v38 = v36->m_bAllowedToPass || v36->m_bTemporaryAllowedToPass ? 1 : 0;
      if ( !LOBYTE(v37[8].m_Flags) || v38 )
        goto LABEL_107;
      v39 = (signed __int64)&v37[5].m_BoundComponentHandles.mNode.mNext;
      if ( v37 == (UFG::SimComponent *)-376i64 )
        goto LABEL_106;
      v40 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v37[5].m_BoundComponentHandles.mNode.mNext)->m_CurrentLane;
      if ( !v40 )
        goto LABEL_106;
      if ( v40->mNode.mOffset )
        v28 = (_WORD *)((char *)v40 + v40->mNode.mOffset);
      if ( *v28 != 1 || (v41 = *(_QWORD *)&v7->m_pRoadSpace.m_pSimComponent[8].m_TypeUID) != 0 && v41 == v39 )
LABEL_106:
        result = 0;
      else
LABEL_107:
        result = 1;
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    if ( ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))v10[42].__vecDelDtor)(v5) )
      return 0;
    v11 = v7->m_fAvoidStopTimer > 0.0;
    v12 = ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))v5->vfptr[48].__vecDelDtor)(v5);
    v13 = ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v7->vfptr[16].__vecDelDtor)(v7)
       && ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))v5->vfptr[47].__vecDelDtor)(v5);
    if ( (_BYTE)v12 || v13 || v11 )
    {
      ((void (__fastcall *)(UFG::CameraSubject *))v5->vfptr[21].__vecDelDtor)(v5);
      v14 = (float *)((__int64 (__fastcall *)(UFG::CameraSubject *))v5->vfptr[17].__vecDelDtor)(v5);
      v15 = *v14;
      v16 = v14[1];
      v17 = v14[2];
      v18 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v6->vfptr[19].__vecDelDtor)(v6);
      v19 = (float)((float)((float)(v16 * v18[4]) + (float)(v15 * *v18)) + (float)(v17 * v18[8])) + v18[12];
      v20 = (float)((float)((float)(v16 * v18[5]) + (float)(v15 * v18[1])) + (float)(v17 * v18[9])) + v18[13];
      v21 = (float)((float)((float)(v16 * v18[6]) + (float)(v15 * v18[2])) + (float)(v17 * v18[10])) + v18[14];
      v22 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v6->vfptr[23].__vecDelDtor)(v6);
      v23 = *v22 - 0.0;
      v24 = v22[1] - 0.0;
      v25 = v22[2] - 0.0;
      v26 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v6->vfptr[24].__vecDelDtor)(v6);
      if ( v21 > v25 )
        v25 = v21;
      if ( v25 >= (float)(v26[2] + 0.0) )
        v25 = v26[2] + 0.0;
      if ( v20 > v24 )
        v24 = v20;
      if ( v24 >= (float)(v26[1] + 0.0) )
        v24 = v26[1] + 0.0;
      if ( v19 > v23 )
        v23 = v19;
      if ( v23 >= (float)(*v26 + 0.0) )
        v23 = *v26 + 0.0;
      if ( v19 == v23 && v20 == v24 && v21 == v25 )
      {
        if ( (_BYTE)v12 )
          UFG::AiDriverComponent::AddSteeringNoise(v7, UFG::AiDriverComponent::m_fSteeringNoiseActionHijack);
        if ( v13 || v11 )
          v7->m_fAvoidStopTimer = 3.0;
        return 0;
      }
    }
    if ( v7->m_bAvoidPeds )
      goto LABEL_108;
    if ( !((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))v6->vfptr[30].__vecDelDtor)(v6) )
      return 0;
    if ( ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))v5->vfptr[32].__vecDelDtor)(v5) )
LABEL_108:
      result = 1;
    else
      result = ((__int64 (__fastcall *)(UFG::CameraSubject *))v5->vfptr[30].__vecDelDtor)(v5);
  }
  return result;
}

// File Line: 5773
// RVA: 0x64CBB0
UFG::qVector3 *__usercall UFG::AiDriverComponent::ExtrapolateWithCurvature@<rax>(UFG::AiDriverComponent *this@<rcx>, UFG::qVector3 *result@<rdx>, float time@<xmm2>, UFG::CameraSubject *subject@<r9>, float a5@<xmm0>, UFG::RoadSpaceComponent *road_space, UFG::qVector3 *new_velocity)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v7; // rax
  UFG::CameraSubject *v8; // rbx
  UFG::qVector3 *v9; // rdi
  float *v10; // rax
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  float *v14; // rax
  float v15; // xmm8_4
  float v16; // xmm6_4
  float v17; // xmm6_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  UFG::qVector3 position; // [rsp+20h] [rbp-68h]
  UFG::qVector3 resulta; // [rsp+30h] [rbp-58h]

  v7 = subject->vfptr;
  v8 = subject;
  v9 = result;
  if ( road_space )
  {
    ((void (__fastcall *)(UFG::CameraSubject *))v7[28].__vecDelDtor)(subject);
    v17 = a5;
    if ( a5 < 0.1 )
      v17 = 0.0;
    position.x = v17 * time;
    *(_QWORD *)&position.y = 0i64;
    UFG::RoadSpaceComponent::ChaseToWorld(road_space, &resulta, &position, new_velocity);
    if ( new_velocity )
    {
      v18 = v17 * new_velocity->x;
      v19 = v17 * new_velocity->y;
      new_velocity->z = v17 * new_velocity->z;
      new_velocity->x = v18;
      new_velocity->y = v19;
    }
    v20 = resulta.y;
    v9->x = resulta.x;
    v21 = resulta.z;
    v9->y = v20;
    v9->z = v21;
  }
  else
  {
    v10 = (float *)((__int64 (__fastcall *)(UFG::CameraSubject *))v7[20].__vecDelDtor)(subject);
    v11 = *v10;
    v12 = v10[1];
    v13 = v10[2];
    if ( (float)((float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v13 * v13)) < 0.010000001 )
    {
      v11 = UFG::qVector3::msZero.x;
      v12 = UFG::qVector3::msZero.y;
      v13 = UFG::qVector3::msZero.z;
    }
    if ( new_velocity )
    {
      new_velocity->x = v11;
      new_velocity->y = v12;
      new_velocity->z = v13;
    }
    v14 = (float *)((__int64 (__fastcall *)(UFG::CameraSubject *))v8->vfptr[17].__vecDelDtor)(v8);
    v15 = (float)(v13 * time) + v14[2];
    v16 = (float)(v11 * time) + *v14;
    v9->y = (float)(v12 * time) + v14[1];
    v9->z = v15;
    v9->x = v16;
  }
  return v9;
}

// File Line: 5801
// RVA: 0x65B8A0
UFG::qVector3 *__fastcall UFG::AiDriverComponent::SteerToAvoidObjects(UFG::AiDriverComponent *this, UFG::qVector3 *result, UFG::qVector3 *steerToPos, float steerToDist)
{
  UFG::qVector3 *v4; // rbx
  UFG::AiDriverComponent *v5; // r14
  float v6; // xmm7_4
  float v7; // xmm9_4
  float v8; // xmm8_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // r12
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::VehicleSubjectComponent *v12; // r15
  UFG::qVector3 *v13; // rax
  UFG::SimObjectGame *v14; // rsi
  UFG::qVector3 *v15; // r13
  float v16; // xmm6_4
  float v17; // xmm10_4
  bool v18; // al
  float v19; // xmm0_4
  float v20; // xmm12_4
  float v21; // xmm11_4
  float v22; // xmm11_4
  float v23; // xmm5_4
  float v24; // xmm13_4
  __int128 v25; // xmm14
  __m128 v26; // xmm3
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm15_4
  float v33; // xmm12_4
  float v34; // xmm11_4
  float *v35; // rax
  float v36; // xmm1_4
  float v37; // xmm2_4
  int v38; // xmm15_4
  int v39; // xmm12_4
  float v40; // xmm11_4
  float v41; // xmm2_4
  float v42; // xmm0_4
  __int64 v43; // rdi
  __int64 v44; // rdi
  bool v45; // r12
  UFG::SimObjectGame *v46; // rax
  __int64 v47; // rcx
  unsigned __int16 v48; // cx
  UFG::CameraSubject *v49; // rbx
  UFG::SimComponent *v50; // rax
  float v51; // xmm6_4
  float distance; // xmm6_4
  UFG::qVector3 *v53; // rsi
  float *v54; // rbx
  __int64 v55; // rax
  float v56; // xmm0_4
  float *v57; // rbx
  __int64 v58; // rax
  float v59; // xmm0_4
  float v60; // xmm0_4
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v61; // rdi
  UFG::CameraSubject *v62; // rbx
  float v63; // xmm2_4
  UFG::SimObjectGame *v64; // rcx
  UFG::RoadSpaceComponent *v65; // rsi
  unsigned __int16 v66; // dx
  UFG::SimComponent *v67; // rax
  float v68; // xmm14_4
  float v69; // xmm13_4
  float v70; // xmm15_4
  float v71; // xmm12_4
  float v72; // xmm10_4
  float v73; // xmm9_4
  float v74; // xmm8_4
  float v75; // xmm11_4
  float v76; // xmm7_4
  float v77; // xmm6_4
  float v78; // xmm0_4
  float v79; // xmm6_4
  float v80; // xmm0_4
  float v81; // xmm2_4
  UFG::qVector3 *v82; // rax
  float v83; // ST44_4
  UFG::qVector3 *v84; // rax
  float *v85; // rcx
  float *v86; // rax
  float v87; // xmm13_4
  float v88; // xmm11_4
  float v89; // xmm9_4
  float v90; // xmm14_4
  float v91; // xmm15_4
  float v92; // xmm7_4
  float v93; // xmm8_4
  float v94; // xmm10_4
  float v95; // xmm12_4
  float v96; // xmm6_4
  float v97; // xmm4_4
  float v98; // xmm5_4
  float v99; // xmm6_4
  float v100; // xmm4_4
  float v101; // xmm5_4
  float v102; // xmm6_4
  float v103; // xmm4_4
  float v104; // xmm5_4
  float v105; // xmm6_4
  float v106; // xmm4_4
  float v107; // xmm5_4
  float v108; // xmm6_4
  float v109; // xmm4_4
  float v110; // xmm5_4
  float v111; // xmm6_4
  float v112; // xmm4_4
  float v113; // xmm5_4
  float v114; // xmm6_4
  float v115; // xmm4_4
  float v116; // xmm5_4
  float v117; // xmm5_4
  float v118; // xmm4_4
  float v119; // xmm6_4
  float v120; // xmm11_4
  float v121; // xmm10_4
  float v122; // xmm9_4
  float v123; // xmm2_4
  float v124; // xmm8_4
  float v125; // xmm7_4
  __m128 v126; // xmm6
  __m128 v127; // xmm3
  float v128; // xmm0_4
  float v129; // xmm9_4
  float v130; // xmm10_4
  float v131; // xmm11_4
  float v132; // xmm12_4
  float v133; // xmm13_4
  float v134; // xmm14_4
  float v135; // xmm3_4
  float v136; // xmm7_4
  float v137; // xmm2_4
  float v138; // xmm8_4
  __m128 v139; // xmm6
  __m128 v140; // xmm4
  float v141; // xmm0_4
  float v142; // xmm6_4
  float v143; // xmm8_4
  float v144; // xmm7_4
  int v145; // eax
  char v146; // si
  UFG::AiDriverComponent::AvoidableOverlap *v147; // rbx
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v148; // rbx
  float v149; // xmm11_4
  __m128 v150; // xmm12
  __m128 v151; // xmm2
  float v152; // xmm1_4
  float v153; // xmm11_4
  float v154; // xmm12_4
  float v155; // xmm8_4
  __int128 v156; // xmm9
  __m128 v157; // xmm2
  float v158; // xmm4_4
  float v159; // xmm8_4
  bool v160; // cl
  float v161; // xmm14_4
  __m128 v162; // xmm15
  float v163; // xmm3_4
  float v164; // xmm0_4
  float v165; // xmm6_4
  __m128 v166; // xmm2
  float v167; // xmm10_4
  float v168; // xmm7_4
  float v169; // xmm13_4
  float v170; // xmm6_4
  float v171; // xmm7_4
  float v172; // xmm8_4
  __m128 v173; // xmm1
  float v174; // xmm4_4
  float v175; // xmm1_4
  float v176; // xmm11_4
  float v177; // xmm8_4
  char v178; // si
  unsigned __int8 v179; // al
  float *v180; // rax
  float v181; // xmm6_4
  float v182; // xmm4_4
  float v183; // xmm2_4
  bool v184; // al
  int v185; // xmm0_4
  UFG::qVector3 *v186; // rax
  float v187; // xmm8_4
  __m128 v188; // xmm9
  float v189; // xmm7_4
  char v190; // al
  float v191; // xmm3_4
  __m128 v192; // xmm2
  float v193; // xmm0_4
  float v194; // xmm3_4
  float *v195; // rax
  __m128 v196; // xmm6
  float v197; // xmm11_4
  float v198; // xmm6_4
  __int128 v199; // xmm12
  char v200; // al
  float v201; // xmm0_4
  float v202; // xmm10_4
  float v203; // xmm6_4
  bool v204; // si
  float v205; // xmm2_4
  float v206; // xmm0_4
  float v207; // xmm6_4
  float v208; // xmm0_4
  UFG::SimObject *v209; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v210; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v211; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v212; // rax
  char v213; // si
  UFG::SimObjectGame *v214; // rcx
  unsigned __int16 v215; // dx
  UFG::SimComponent *v216; // rax
  bool v217; // al
  int v218; // xmm0_4
  float v219; // xmm6_4
  float v220; // xmm0_4
  float v221; // xmm1_4
  float v222; // xmm5_4
  float v223; // xmm4_4
  float v224; // xmm8_4
  float v225; // xmm9_4
  UFG::qVector3 *v226; // rax
  float v227; // xmm1_4
  float v228; // xmm2_4
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *i; // rcx
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v230; // rdx
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v231; // rax
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v232; // rdx
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v233; // rax
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v234; // rcx
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v235; // rax
  float v236; // [rsp+40h] [rbp-80h]
  UFG::qVector3 close_limit; // [rsp+48h] [rbp-78h]
  float v238; // [rsp+54h] [rbp-6Ch]
  UFG::AiDriverComponent::TimeWindowResult time_window; // [rsp+58h] [rbp-68h]
  float v240; // [rsp+64h] [rbp-5Ch]
  float v241; // [rsp+68h] [rbp-58h]
  UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> list; // [rsp+70h] [rbp-50h]
  UFG::qVector3 right_limit; // [rsp+80h] [rbp-40h]
  float v244; // [rsp+90h] [rbp-30h]
  float v245; // [rsp+94h] [rbp-2Ch]
  float v246; // [rsp+98h] [rbp-28h]
  float v247; // [rsp+9Ch] [rbp-24h]
  UFG::qVector3 v248; // [rsp+A0h] [rbp-20h]
  float v249; // [rsp+ACh] [rbp-14h]
  UFG::qVector3 v0; // [rsp+B0h] [rbp-10h]
  float v251; // [rsp+C0h] [rbp+0h]
  float v252; // [rsp+C4h] [rbp+4h]
  float v253; // [rsp+C8h] [rbp+8h]
  UFG::qVector3 v254; // [rsp+D0h] [rbp+10h]
  UFG::qVector3 v255; // [rsp+E0h] [rbp+20h]
  UFG::qVector3 *v1; // [rsp+F0h] [rbp+30h]
  UFG::qVector3 v257; // [rsp+F8h] [rbp+38h]
  UFG::qVector3 point; // [rsp+108h] [rbp+48h]
  float v259; // [rsp+118h] [rbp+58h]
  float v260; // [rsp+11Ch] [rbp+5Ch]
  float v261; // [rsp+120h] [rbp+60h]
  float v262; // [rsp+124h] [rbp+64h]
  float v263; // [rsp+128h] [rbp+68h]
  float v264; // [rsp+12Ch] [rbp+6Ch]
  Render::DebugDrawContext *v265; // [rsp+130h] [rbp+70h]
  UFG::qVector3 world_direction; // [rsp+138h] [rbp+78h]
  UFG::qVector3 v267; // [rsp+148h] [rbp+88h]
  UFG::qVector3 local_corners; // [rsp+160h] [rbp+A0h]
  float v269; // [rsp+16Ch] [rbp+ACh]
  float v270; // [rsp+170h] [rbp+B0h]
  float v271; // [rsp+174h] [rbp+B4h]
  float v272; // [rsp+178h] [rbp+B8h]
  float v273; // [rsp+17Ch] [rbp+BCh]
  float v274; // [rsp+180h] [rbp+C0h]
  float v275; // [rsp+184h] [rbp+C4h]
  float v276; // [rsp+188h] [rbp+C8h]
  float v277; // [rsp+18Ch] [rbp+CCh]
  float v278; // [rsp+190h] [rbp+D0h]
  float v279; // [rsp+194h] [rbp+D4h]
  float v280; // [rsp+198h] [rbp+D8h]
  float v281; // [rsp+19Ch] [rbp+DCh]
  float v282; // [rsp+1A0h] [rbp+E0h]
  float v283; // [rsp+1A4h] [rbp+E4h]
  float v284; // [rsp+1A8h] [rbp+E8h]
  float v285; // [rsp+1ACh] [rbp+ECh]
  float v286; // [rsp+1B0h] [rbp+F0h]
  float v287; // [rsp+1B4h] [rbp+F4h]
  float v288; // [rsp+1B8h] [rbp+F8h]
  float v289; // [rsp+1BCh] [rbp+FCh]
  UFG::qVector3 avoid_hull; // [rsp+1C0h] [rbp+100h]
  float v291; // [rsp+1CCh] [rbp+10Ch]
  float v292; // [rsp+1D0h] [rbp+110h]
  float v293; // [rsp+1D4h] [rbp+114h]
  float v294; // [rsp+1D8h] [rbp+118h]
  float v295; // [rsp+1DCh] [rbp+11Ch]
  float v296; // [rsp+1E0h] [rbp+120h]
  float v297; // [rsp+1E4h] [rbp+124h]
  float v298; // [rsp+1E8h] [rbp+128h]
  float v299; // [rsp+1ECh] [rbp+12Ch]
  float v300; // [rsp+1F0h] [rbp+130h]
  float v301; // [rsp+1F4h] [rbp+134h]
  float v302; // [rsp+1F8h] [rbp+138h]
  float v303; // [rsp+1FCh] [rbp+13Ch]
  float v304; // [rsp+200h] [rbp+140h]
  float v305; // [rsp+204h] [rbp+144h]
  float v306; // [rsp+208h] [rbp+148h]
  float v307; // [rsp+20Ch] [rbp+14Ch]
  float v308; // [rsp+210h] [rbp+150h]
  float v309; // [rsp+214h] [rbp+154h]
  float v310; // [rsp+218h] [rbp+158h]
  float v311; // [rsp+21Ch] [rbp+15Ch]
  float v312; // [rsp+220h] [rbp+160h]
  float v313; // [rsp+224h] [rbp+164h]
  float v314; // [rsp+228h] [rbp+168h]
  float v315; // [rsp+22Ch] [rbp+16Ch]
  float v316; // [rsp+230h] [rbp+170h]
  float v317; // [rsp+234h] [rbp+174h]
  float v318; // [rsp+238h] [rbp+178h]
  float v319; // [rsp+23Ch] [rbp+17Ch]
  float v320; // [rsp+240h] [rbp+180h]
  float v321; // [rsp+244h] [rbp+184h]
  float v322; // [rsp+248h] [rbp+188h]
  float v323; // [rsp+24Ch] [rbp+18Ch]
  float v324; // [rsp+250h] [rbp+190h]
  float v325; // [rsp+254h] [rbp+194h]
  float v326; // [rsp+258h] [rbp+198h]
  float v327; // [rsp+25Ch] [rbp+19Ch]
  float v328; // [rsp+260h] [rbp+1A0h]
  float v329; // [rsp+264h] [rbp+1A4h]
  float v330; // [rsp+268h] [rbp+1A8h]
  float v331; // [rsp+26Ch] [rbp+1ACh]
  float v332; // [rsp+270h] [rbp+1B0h]
  float v333; // [rsp+274h] [rbp+1B4h]
  float v334; // [rsp+278h] [rbp+1B8h]
  float v335; // [rsp+27Ch] [rbp+1BCh]
  UFG::SensorPhantomIterator v336; // [rsp+280h] [rbp+1C0h]
  UFG::qVector3 new_velocity; // [rsp+298h] [rbp+1D8h]
  UFG::qVector3 v338; // [rsp+2A8h] [rbp+1E8h]
  UFG::qVector3 v339; // [rsp+2B8h] [rbp+1F8h]
  UFG::qVector3 v340; // [rsp+2C8h] [rbp+208h]
  UFG::qVector3 p1; // [rsp+2D8h] [rbp+218h]
  UFG::qVector3 v342; // [rsp+2E8h] [rbp+228h]
  UFG::qVector3 v343; // [rsp+2F8h] [rbp+238h]
  UFG::qVector3 p0; // [rsp+308h] [rbp+248h]
  UFG::qVector3 v345; // [rsp+318h] [rbp+258h]
  __int64 v346; // [rsp+328h] [rbp+268h]
  UFG::qVector3 v347; // [rsp+330h] [rbp+270h]
  UFG::qVector3 verts; // [rsp+340h] [rbp+280h]
  __int64 v349[129]; // [rsp+3A0h] [rbp+2E0h]
  bool co_chaser[8]; // [rsp+7B0h] [rbp+6F0h]
  _DWORD *v351; // [rsp+7B8h] [rbp+6F8h]
  float *v352; // [rsp+7C0h] [rbp+700h]
  float radius; // [rsp+7C8h] [rbp+708h]
  float *v354; // [rsp+7D0h] [rbp+710h]
  float *v355; // [rsp+7D8h] [rbp+718h]

  v346 = -2i64;
  v4 = steerToPos;
  v5 = this;
  v6 = steerToPos->x;
  v245 = v6;
  v7 = steerToPos->y;
  v249 = v7;
  v8 = steerToPos->z;
  v244 = v8;
  point.x = v6;
  point.y = v7;
  point.z = v8;
  v9 = &this->m_CurrentAvoidable;
  if ( this->m_CurrentAvoidable.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v9->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  v9->m_pPointer = 0i64;
  v5->m_BlockedByAvoidable = 0;
  v12 = (UFG::VehicleSubjectComponent *)v5->m_pVehicleSubject.m_pSimComponent;
  if ( v12 )
  {
    v265 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    v14 = (UFG::SimObjectGame *)v5->m_pSimObject;
    *(_QWORD *)&time_window.fClosingSpeed = v5->m_pSimObject;
    v15 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[17].__vecDelDtor)(v12);
    v16 = FLOAT_0_2;
    v17 = FLOAT_0_2;
    v236 = FLOAT_0_2;
    v18 = v5->m_bAllowedToPass;
    if ( v18 )
    {
      v17 = FLOAT_0_40000001;
      v236 = FLOAT_0_40000001;
    }
    if ( v5->m_bTemporaryAllowedToPass )
    {
      v17 = FLOAT_0_2;
      v236 = FLOAT_0_2;
    }
    if ( v18 )
      v16 = FLOAT_0_1;
    v19 = UFG::VehicleSubjectComponent::GetMass(v12);
    v20 = v19;
    ((void (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[28].__vecDelDtor)(v12);
    v259 = v19;
    v21 = UFG::AiDriverComponent::m_fMaxBrakingForce;
    if ( v5->m_pVehicleSubject.m_pSimComponent
      && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)v5->m_pVehicleSubject.m_pSimComponent) )
    {
      v21 = UFG::AiDriverComponent::m_fBoatMaxBrakingForce;
    }
    if ( v19 < 100.0 )
      v20 = FLOAT_100_0;
    v22 = v21 / v20;
    v23 = v4->z - v15->z;
    v247 = v23;
    v24 = v4->y - v15->y;
    v241 = v24;
    v25 = LODWORD(v4->x);
    *(float *)&v25 = *(float *)&v25 - v15->x;
    v246 = *(float *)&v25;
    v26 = (__m128)v25;
    v26.m128_f32[0] = (float)((float)(*(float *)&v25 * *(float *)&v25) + (float)(v24 * v24)) + (float)(v23 * v23);
    LODWORD(v263) = (unsigned __int128)_mm_sqrt_ps(v26);
    v27 = 0.0;
    if ( v263 <= 0.0 )
    {
      LODWORD(time_window.fClosingSpeed) = v25;
      time_window.fEarliest = v24;
      time_window.fLatest = v23;
    }
    else
    {
      if ( v26.m128_f32[0] != 0.0 )
        v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
      time_window.fClosingSpeed = v27 * *(float *)&v25;
      time_window.fEarliest = v27 * v24;
      time_window.fLatest = v27 * v23;
    }
    v28 = FLOAT_2_0;
    if ( v5->m_bAllowedToPass )
      v28 = *(float *)&FLOAT_1_0;
    v29 = v19 - (float)(v28 * v22);
    v30 = (float)(v28 * UFG::AiDriverComponent::m_fMaxForwardAccel) + v19;
    v31 = *v355;
    if ( *v355 <= v29 )
      v31 = v29;
    if ( v31 >= v30 )
      v31 = v30;
    v32 = (float)(time_window.fLatest * v31) * v16;
    v33 = (float)(time_window.fEarliest * v31) * v16;
    v34 = (float)(time_window.fClosingSpeed * v31) * v16;
    v35 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[20].__vecDelDtor)(v12);
    v36 = (float)(1.0 - v16) * v35[1];
    v37 = (float)(1.0 - v16) * *v35;
    *(float *)&v38 = v32 + (float)((float)(1.0 - v16) * v35[2]);
    v251 = *(float *)&v38;
    *(float *)&v39 = v33 + v36;
    v252 = *(float *)&v39;
    v40 = v34 + v37;
    v253 = v40;
    time_window.fLatest = v40;
    v240 = *(float *)&v39;
    v241 = *(float *)&v38;
    v0.x = v40;
    LODWORD(v0.y) = v39;
    LODWORD(v0.z) = v38;
    if ( v5->m_bAllowedToPass || (v41 = v5->m_RoadSpeedLimit, v41 <= 0.0) )
    {
      co_chaser[0] = 0;
    }
    else
    {
      co_chaser[0] = 1;
      v0.x = v41 * time_window.fClosingSpeed;
      v0.y = v41 * time_window.fEarliest;
      v0.z = v41 * time_window.fLatest;
    }
    v42 = v40 * v40;
    v260 = (float)((float)(*(float *)&v39 * *(float *)&v39) + (float)(v40 * v40))
         + (float)(*(float *)&v38 * *(float *)&v38);
    if ( v260 > 0.0 )
    {
      v5->m_NumAvoidableOverlaps = 0;
      list.mNode.mPrev = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list;
      list.mNode.mNext = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list;
      UFG::SensorPhantomIterator::SensorPhantomIterator(&v336, v5->m_AvoidableSensor, 0);
      v44 = 0i64;
      if ( UFG::SensorPhantomIterator::operator*(&v336) )
      {
        v45 = co_chaser[0];
        do
        {
          v46 = (UFG::SimObjectGame *)UFG::SensorPhantomIterator::operator*(&v336);
          if ( v46 != v14 )
          {
            v47 = 0i64;
            if ( v44 )
            {
              while ( (UFG::SimObjectGame *)v349[v47] != v46 )
              {
                if ( ++v47 == v44 )
                  goto LABEL_39;
              }
            }
            else
            {
LABEL_39:
              if ( v44 != 100 )
                v349[v44++] = (__int64)v46;
              co_chaser[0] = 0;
              if ( v46 )
              {
                v48 = v46->m_Flags;
                if ( (v48 >> 14) & 1 )
                {
                  v49 = (UFG::CameraSubject *)v46->m_Components.p[37].m_pComponent;
                }
                else if ( (v48 & 0x8000u) == 0 )
                {
                  if ( (v48 >> 13) & 1 )
                    v50 = UFG::SimObjectGame::GetComponentOfTypeHK(v46, UFG::CameraSubject::_TypeUID);
                  else
                    v50 = (v48 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v46, UFG::CameraSubject::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v46->vfptr, UFG::CameraSubject::_TypeUID);
                  v49 = (UFG::CameraSubject *)v50;
                }
                else
                {
                  v49 = (UFG::CameraSubject *)v46->m_Components.p[31].m_pComponent;
                }
                if ( v49 && UFG::AiDriverComponent::ShouldAvoid(v5, v12, v49, co_chaser) )
                {
                  ((void (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[21].__vecDelDtor)(v12);
                  ((void (__fastcall *)(UFG::CameraSubject *))v49->vfptr[21].__vecDelDtor)(v49);
                  v51 = v17;
                  if ( v5->m_DrivingMode == 2 )
                  {
                    if ( v5->m_PathingTarget.m_pPointer )
                    {
                      if ( (float)(v42 + 0.2) > v42 )
                      {
                        v51 = v42 * 0.5;
                        if ( v17 > (float)(v42 * 0.5) )
                          v51 = v17;
                      }
                    }
                  }
                  distance = (float)(v51 + v42) + v42;
                  v53 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::CameraSubject *))v49->vfptr[17].__vecDelDtor)(v49);
                  v1 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::CameraSubject *))v49->vfptr[20].__vecDelDtor)(v49);
                  if ( UFG::AiDriverComponent::TimeWindowCloserThan(v5, v15, &v0, v53, v1, distance, &time_window) )
                  {
                    v42 = UFG::AiDriverComponent::GetAvoidanceFutureTime(v5);
                    if ( v42 > time_window.fEarliest )
                    {
                      if ( v45 )
                        UFG::AiDriverComponent::TimeWindowCloserThan(
                          v5,
                          v15,
                          (UFG::qVector3 *)&time_window.fLatest,
                          v53,
                          v1,
                          distance,
                          &time_window);
                      UFG::AiDriverComponent::AddAvoidableOverlap(v5, &list, v49, &time_window, co_chaser[0]);
                      ++v5->m_NumAvoidableOverlaps;
                    }
                  }
                  v14 = *(UFG::SimObjectGame **)&time_window.fClosingSpeed;
                }
              }
            }
          }
          UFG::SensorPhantomIterator::operator++(&v336);
        }
        while ( UFG::SensorPhantomIterator::operator*(&v336) );
        v9 = &v5->m_CurrentAvoidable;
      }
      UFG::SensorPhantomIterator::~SensorPhantomIterator(&v336);
      UFG::CameraSubject::GetBoxVerts((UFG::CameraSubject *)&v12->vfptr, &verts, 0.0);
      if ( (UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> *)list.mNode.mNext == &list )
      {
        v5->m_bTemporaryAllowedToPass = 0;
        v5->m_TempPassLaneChangeDirectionCode = 0;
      }
      v54 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[15].__vecDelDtor)(v12);
      v55 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[24].__vecDelDtor)(v12);
      v56 = *(float *)(v55 + 4);
      v0.x = *(float *)(v55 + 4) * v54[2];
      *(float *)&v1 = v56 * v54[1];
      time_window.fClosingSpeed = v56 * *v54;
      v57 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[15].__vecDelDtor)(v12);
      v58 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[23].__vecDelDtor)(v12);
      v59 = *(float *)(v58 + 4);
      v262 = *(float *)(v58 + 4) * v57[2];
      v261 = v59 * v57[1];
      v60 = v59 * *v57;
      v264 = v60;
      v61 = list.mNode.mNext;
      if ( (UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> *)list.mNode.mNext != &list )
      {
        do
        {
          v62 = (UFG::CameraSubject *)v61[2].mNext;
          *(_QWORD *)co_chaser = ((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v62->vfptr[17].__vecDelDtor)(v61[2].mNext);
          ((void (__fastcall *)(UFG::CameraSubject *))v62->vfptr[20].__vecDelDtor)(v62);
          ((void (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[21].__vecDelDtor)(v12);
          ((void (__fastcall *)(UFG::CameraSubject *))v62->vfptr[21].__vecDelDtor)(v62);
          v63 = v17;
          if ( v5->m_DrivingMode == 2 )
          {
            if ( v5->m_PathingTarget.m_pPointer )
            {
              if ( (float)(v60 + 0.2) > v60 )
              {
                v63 = v60 * 0.5;
                if ( v17 > (float)(v60 * 0.5) )
                  v63 = v17;
              }
            }
          }
          UFG::CameraSubject::GetBoxVerts(v62, &local_corners, v63);
          v64 = (UFG::SimObjectGame *)v62->m_pSimObject;
          if ( v64 )
          {
            v66 = v64->m_Flags;
            if ( (v66 >> 14) & 1 )
            {
              v65 = (UFG::RoadSpaceComponent *)v64->m_Components.p[24].m_pComponent;
            }
            else if ( (v66 & 0x8000u) == 0 )
            {
              if ( (v66 >> 13) & 1 )
              {
                v67 = UFG::SimObjectGame::GetComponentOfTypeHK(v64, UFG::RoadSpaceComponent::_TypeUID);
              }
              else if ( (v66 >> 12) & 1 )
              {
                v67 = UFG::SimObjectGame::GetComponentOfTypeHK(v64, UFG::RoadSpaceComponent::_TypeUID);
              }
              else
              {
                v67 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)&v64->vfptr,
                        UFG::RoadSpaceComponent::_TypeUID);
              }
              v65 = (UFG::RoadSpaceComponent *)v67;
            }
            else
            {
              v65 = (UFG::RoadSpaceComponent *)v64->m_Components.p[24].m_pComponent;
            }
          }
          else
          {
            v65 = 0i64;
          }
          UFG::AiDriverComponent::ExtrapolateWithCurvature(
            v5,
            (UFG::qVector3 *)&time_window.fLatest,
            *(float *)&v61[2].mPrev,
            (UFG::CameraSubject *)&v12->vfptr,
            v60,
            (UFG::RoadSpaceComponent *)v5->m_pRoadSpace.m_pSimComponent,
            &new_velocity);
          UFG::AiDriverComponent::ExtrapolateWithCurvature(
            v5,
            (UFG::qVector3 *)&time_window,
            *((float *)&v61[1].mNext + 1),
            (UFG::CameraSubject *)&v12->vfptr,
            v60,
            (UFG::RoadSpaceComponent *)v5->m_pRoadSpace.m_pSimComponent,
            &v343);
          UFG::AiDriverComponent::ExtrapolateWithCurvature(v5, &v267, *(float *)&v61[2].mPrev, v62, v60, v65, &v339);
          UFG::AiDriverComponent::ExtrapolateWithCurvature(
            v5,
            &v257,
            *((float *)&v61[1].mNext + 1),
            v62,
            v60,
            v65,
            &v345);
          v68 = v267.z;
          v69 = v267.y;
          v70 = v240;
          v71 = v267.x;
          v72 = time_window.fLatest;
          world_direction.x = v267.x - time_window.fLatest;
          world_direction.y = v267.y - v240;
          world_direction.z = v267.z - v241;
          UFG::CameraSubject::GetExtentInDirection((UFG::CameraSubject *)&v12->vfptr, &p0, &world_direction, &verts);
          v73 = v257.z;
          v74 = v257.y;
          v75 = time_window.fEarliest;
          v76 = v257.x;
          v77 = time_window.fClosingSpeed;
          v255.x = v257.x - time_window.fClosingSpeed;
          v255.y = v257.y - time_window.fEarliest;
          v255.z = v257.z - time_window.fLatest;
          UFG::CameraSubject::GetExtentInDirection((UFG::CameraSubject *)&v12->vfptr, &v342, &v255, &verts);
          v254.x = v72 - v71;
          v254.y = v70 - v69;
          v254.z = v241 - v68;
          UFG::CameraSubject::GetExtentInDirection(v62, &p1, &v254, &local_corners);
          v248.x = v77 - v76;
          v248.y = v75 - v74;
          v248.z = time_window.fLatest - v73;
          UFG::CameraSubject::GetExtentInDirection(v62, &v340, &v248, &local_corners);
          v78 = UFG::ClosingTime(&p0, &new_velocity, &p1, &v339, 0i64);
          v79 = 0.0;
          if ( v78 >= 0.0 )
            v79 = v78;
          v80 = UFG::ClosingTime(&v342, &v343, &v340, &v345, 0i64);
          v81 = 0.0;
          if ( v80 >= 0.0 )
            v81 = v80;
          v82 = UFG::AiDriverComponent::ExtrapolateWithCurvature(v5, &v347, v81, v62, v80, v65, 0i64);
          v83 = v82->z - *(float *)(*(_QWORD *)co_chaser + 8i64);
          close_limit.x = v82->y - *(float *)(*(_QWORD *)co_chaser + 4i64);
          close_limit.z = v82->x - **(float **)co_chaser;
          v84 = UFG::AiDriverComponent::ExtrapolateWithCurvature(v5, &v338, v79, v62, close_limit.z, v65, 0i64);
          v85 = *(float **)co_chaser;
          *(float *)co_chaser = v84->z - *(float *)(*(_QWORD *)co_chaser + 8i64);
          v238 = v84->y - v85[1];
          close_limit.y = v84->x - *v85;
          v86 = (float *)((__int64 (__fastcall *)(UFG::CameraSubject *))v62->vfptr[18].__vecDelDtor)(v62);
          v87 = *v86;
          v88 = v86[5];
          v89 = v86[1];
          v90 = v86[9];
          v91 = v86[13];
          v92 = v86[6];
          v93 = v86[2];
          v94 = v86[10];
          v95 = v86[14];
          v96 = (float)((float)((float)((float)(local_corners.x * *v86) + (float)(local_corners.y * v86[4]))
                              + (float)(local_corners.z * v86[8]))
                      + v86[12])
              - v15->x;
          v97 = (float)((float)((float)((float)(local_corners.x * v89) + (float)(local_corners.y * v88))
                              + (float)(local_corners.z * v90))
                      + v91)
              - v15->y;
          v98 = (float)((float)((float)((float)(local_corners.x * v93) + (float)(local_corners.y * v92))
                              + (float)(local_corners.z * v94))
                      + v95)
              - v15->z;
          v312 = v96 + close_limit.y;
          v313 = v238 + v97;
          v314 = *(float *)co_chaser + v98;
          avoid_hull.x = v96 + close_limit.z;
          avoid_hull.y = close_limit.x + v97;
          avoid_hull.z = v83 + v98;
          v99 = (float)((float)((float)((float)(v269 * v87) + (float)(v270 * v86[4])) + (float)(v271 * v86[8])) + v86[12])
              - v15->x;
          v100 = (float)((float)((float)((float)(v269 * v89) + (float)(v270 * v88)) + (float)(v271 * v90)) + v91)
               - v15->y;
          v101 = (float)((float)((float)((float)(v269 * v93) + (float)(v270 * v92)) + (float)(v271 * v94)) + v95)
               - v15->z;
          v315 = v99 + close_limit.y;
          v316 = v238 + v100;
          v317 = *(float *)co_chaser + v101;
          v291 = v99 + close_limit.z;
          v292 = close_limit.x + v100;
          v293 = v83 + v101;
          v102 = (float)((float)((float)((float)(v272 * v87) + (float)(v273 * v86[4])) + (float)(v274 * v86[8]))
                       + v86[12])
               - v15->x;
          v103 = (float)((float)((float)((float)(v272 * v89) + (float)(v273 * v88)) + (float)(v274 * v90)) + v91)
               - v15->y;
          v104 = (float)((float)((float)((float)(v272 * v93) + (float)(v273 * v92)) + (float)(v274 * v94)) + v95)
               - v15->z;
          v318 = v102 + close_limit.y;
          v319 = v238 + v103;
          v320 = *(float *)co_chaser + v104;
          v294 = v102 + close_limit.z;
          v295 = close_limit.x + v103;
          v296 = v83 + v104;
          v105 = (float)((float)((float)((float)(v276 * v86[4]) + (float)(v275 * v87)) + (float)(v277 * v86[8]))
                       + v86[12])
               - v15->x;
          v106 = (float)((float)((float)((float)(v276 * v88) + (float)(v275 * v89)) + (float)(v277 * v90)) + v91)
               - v15->y;
          v107 = (float)((float)((float)((float)(v276 * v92) + (float)(v275 * v93)) + (float)(v277 * v94)) + v95)
               - v15->z;
          v321 = v105 + close_limit.y;
          v322 = v238 + v106;
          v323 = *(float *)co_chaser + v107;
          v297 = v105 + close_limit.z;
          v298 = close_limit.x + v106;
          v299 = v83 + v107;
          v108 = (float)((float)((float)((float)(v278 * v87) + (float)(v279 * v86[4])) + (float)(v280 * v86[8]))
                       + v86[12])
               - v15->x;
          v109 = (float)((float)((float)((float)(v278 * v89) + (float)(v279 * v88)) + (float)(v280 * v90)) + v91)
               - v15->y;
          v110 = (float)((float)((float)((float)(v278 * v93) + (float)(v279 * v92)) + (float)(v280 * v94)) + v95)
               - v15->z;
          v324 = v108 + close_limit.y;
          v325 = v238 + v109;
          v326 = *(float *)co_chaser + v110;
          v300 = v108 + close_limit.z;
          v301 = close_limit.x + v109;
          v302 = v83 + v110;
          v111 = (float)((float)((float)((float)(v281 * v87) + (float)(v282 * v86[4])) + (float)(v283 * v86[8]))
                       + v86[12])
               - v15->x;
          v112 = (float)((float)((float)((float)(v281 * v89) + (float)(v282 * v88)) + (float)(v283 * v90)) + v91)
               - v15->y;
          v113 = (float)((float)((float)((float)(v281 * v93) + (float)(v282 * v92)) + (float)(v283 * v94)) + v95)
               - v15->z;
          v327 = v111 + close_limit.y;
          v328 = v238 + v112;
          v329 = *(float *)co_chaser + v113;
          v303 = v111 + close_limit.z;
          v304 = close_limit.x + v112;
          v305 = v83 + v113;
          v114 = (float)((float)((float)((float)(v284 * v87) + (float)(v285 * v86[4])) + (float)(v286 * v86[8]))
                       + v86[12])
               - v15->x;
          v115 = (float)((float)((float)((float)(v284 * v89) + (float)(v285 * v88)) + (float)(v286 * v90)) + v91)
               - v15->y;
          v116 = (float)((float)((float)((float)(v284 * v93) + (float)(v285 * v92)) + (float)(v286 * v94)) + v95)
               - v15->z;
          v330 = v114 + close_limit.y;
          v331 = v238 + v115;
          v332 = *(float *)co_chaser + v116;
          v306 = v114 + close_limit.z;
          v307 = close_limit.x + v115;
          v308 = v83 + v116;
          v117 = (float)((float)((float)((float)(v288 * v92) + (float)(v287 * v93)) + (float)(v289 * v94)) + v95)
               - v15->z;
          v118 = (float)((float)((float)((float)(v287 * v89) + (float)(v288 * v88)) + (float)(v289 * v90)) + v91)
               - v15->y;
          v119 = (float)((float)((float)((float)(v287 * v87) + (float)(v288 * v86[4])) + (float)(v289 * v86[8]))
                       + v86[12])
               - v15->x;
          v333 = v119 + close_limit.y;
          v334 = v238 + v118;
          v335 = *(float *)co_chaser + v117;
          v309 = v119 + close_limit.z;
          v310 = close_limit.x + v118;
          v311 = v83 + v117;
          UFG::AiDriverComponent::ComputeAvoidanceLimits(
            v5,
            v15,
            &avoid_hull,
            (UFG::qVector3 *)&list,
            &right_limit,
            &close_limit);
          v120 = *(float *)&list.mNode.mNext;
          v126 = (__m128)LODWORD(list.mNode.mNext);
          v121 = *((float *)&list.mNode.mPrev + 1);
          v122 = *(float *)&list.mNode.mPrev;
          v123 = 0.0;
          v124 = (float)((float)(*((float *)&list.mNode.mPrev + 1) - v261) * 0.0)
               - (float)((float)(*(float *)&list.mNode.mPrev - v264) * 0.0);
          v126.m128_f32[0] = (float)(*(float *)&list.mNode.mNext - v262) * 0.0;
          v125 = (float)(*(float *)&list.mNode.mPrev - v264) - v126.m128_f32[0];
          v126.m128_f32[0] = v126.m128_f32[0] - (float)(*((float *)&list.mNode.mPrev + 1) - v261);
          v127 = v126;
          v127.m128_f32[0] = (float)((float)(v126.m128_f32[0] * v126.m128_f32[0]) + (float)(v125 * v125))
                           + (float)(v124 * v124);
          if ( v127.m128_f32[0] != 0.0 )
            v123 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v127));
          v128 = *(float *)(((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[23].__vecDelDtor)(v12)
                          + 4);
          v129 = v122 - (float)((float)(v126.m128_f32[0] * v123) * v128);
          v130 = v121 - (float)((float)(v125 * v123) * v128);
          v131 = v120 - (float)((float)(v124 * v123) * v128);
          list.mNode.mPrev = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)__PAIR__(LODWORD(v130), LODWORD(v129));
          *(float *)&list.mNode.mNext = v131;
          v132 = right_limit.z;
          v133 = right_limit.y;
          v139 = (__m128)LODWORD(right_limit.y);
          v134 = right_limit.x;
          v135 = 0.0;
          v136 = (float)((float)(right_limit.x - time_window.fClosingSpeed) * 0.0)
               - (float)((float)(right_limit.y - *(float *)&v1) * 0.0);
          v137 = (float)(right_limit.z - v0.x) * 0.0;
          v138 = v137 - (float)(right_limit.x - time_window.fClosingSpeed);
          v139.m128_f32[0] = (float)(right_limit.y - *(float *)&v1) - v137;
          v140 = v139;
          v140.m128_f32[0] = (float)((float)(v139.m128_f32[0] * v139.m128_f32[0]) + (float)(v138 * v138))
                           + (float)(v136 * v136);
          if ( v140.m128_f32[0] != 0.0 )
            v135 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v140));
          v141 = *(float *)(((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[24].__vecDelDtor)(v12)
                          + 4);
          v142 = (float)((float)(v139.m128_f32[0] * v135) * v141) + v134;
          v143 = (float)((float)(v138 * v135) * v141) + v133;
          v144 = (float)((float)(v136 * v135) * v141) + v132;
          right_limit.x = v142;
          right_limit.y = v143;
          right_limit.z = v144;
          *(float *)&v61[3].mPrev = close_limit.x;
          HIDWORD(v61[3].mPrev) = LODWORD(close_limit.y);
          v60 = close_limit.z;
          *(float *)&v61[3].mNext = close_limit.z;
          *((float *)&v61[3].mNext + 1) = v142;
          *(float *)&v61[4].mPrev = v143;
          *((float *)&v61[4].mPrev + 1) = v144;
          *(float *)&v61[4].mNext = v129;
          *((float *)&v61[4].mNext + 1) = v130;
          *(float *)&v61[5].mPrev = v131;
          v61 = v61->mNext;
          v17 = v236;
        }
        while ( v61 != (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list );
        v61 = list.mNode.mNext;
        v6 = v245;
        v8 = v244;
        v7 = v249;
        v24 = v241;
        *(float *)&v25 = v246;
        v9 = &v5->m_CurrentAvoidable;
      }
      v145 = 0;
      *(_DWORD *)co_chaser = 0;
      do
      {
        if ( v145 >= v5->m_NumAvoidableOverlaps )
          break;
        v146 = 0;
        if ( v61 != (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list )
        {
          do
          {
            if ( SHIDWORD(v61[1].mPrev) <= v145 )
            {
              v147 = (UFG::AiDriverComponent::AvoidableOverlap *)v61->mNext;
              if ( v147 != (UFG::AiDriverComponent::AvoidableOverlap *)&list )
              {
                do
                {
                  v146 |= UFG::AiDriverComponent::AvoidableOverlap::MergeLimits(
                            (UFG::AiDriverComponent::AvoidableOverlap *)v61,
                            v147);
                  v147 = (UFG::AiDriverComponent::AvoidableOverlap *)v147->mNext;
                }
                while ( v147 != (UFG::AiDriverComponent::AvoidableOverlap *)&list );
                v145 = *(_DWORD *)co_chaser;
              }
            }
            v61 = v61->mNext;
          }
          while ( v61 != (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list );
          v61 = list.mNode.mNext;
        }
        *(_DWORD *)co_chaser = ++v145;
      }
      while ( v146 );
      if ( v61 != (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list )
      {
        v254.z = 0.0;
        v255.z = 0.0;
        do
        {
          v148 = v61[2].mNext;
          *(_QWORD *)&v0.x = ((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v148->mPrev[8].mNext)(v61[2].mNext);
          ((void (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v148->mPrev[10].mPrev)(v148);
          v149 = *((float *)&v61[4].mNext + 1);
          v150 = (__m128)LODWORD(v61[4].mNext);
          v151 = v150;
          v151.m128_f32[0] = (float)((float)(v150.m128_f32[0] * v150.m128_f32[0]) + (float)(v149 * v149))
                           + (float)(*(float *)&v61[5].mPrev * *(float *)&v61[5].mPrev);
          if ( v151.m128_f32[0] == 0.0 )
            v152 = 0.0;
          else
            v152 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v151));
          v153 = v149 * v152;
          v154 = v150.m128_f32[0] * v152;
          v254.x = v154;
          v254.y = v153;
          v155 = *(float *)&v61[4].mPrev;
          v156 = HIDWORD(v61[3].mNext);
          v157 = (__m128)v156;
          v157.m128_f32[0] = (float)((float)(*(float *)&v156 * *(float *)&v156) + (float)(v155 * v155))
                           + (float)(*((float *)&v61[4].mPrev + 1) * *((float *)&v61[4].mPrev + 1));
          if ( v157.m128_f32[0] == 0.0 )
            v158 = 0.0;
          else
            v158 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v157));
          v159 = v155 * v158;
          *(float *)&v156 = *(float *)&v156 * v158;
          LODWORD(v255.x) = v156;
          v255.y = v159;
          v160 = (float)((float)(v153 * *(float *)&v25) - (float)(v24 * v154)) > 0.0
              && (float)((float)(v159 * *(float *)&v25) - (float)(v24 * *(float *)&v156)) < 0.0;
          co_chaser[0] = v160;
          v161 = *(float *)&v61[3].mPrev;
          v162 = (__m128)HIDWORD(v61[3].mPrev);
          v163 = *(float *)&v61[3].mNext;
          v236 = v163;
          v164 = v15->z + v163;
          v165 = v15->y + v162.m128_f32[0];
          time_window.fClosingSpeed = v15->x;
          v257.x = time_window.fClosingSpeed + v161;
          v257.y = v165;
          v257.z = v164;
          LODWORD(v1) = v160 != 0;
          if ( v160 )
          {
            v166 = v162;
            v166.m128_f32[0] = (float)((float)(v162.m128_f32[0] * v162.m128_f32[0]) + (float)(v161 * v161))
                             + (float)(v163 * v163);
            LODWORD(time_window.fClosingSpeed) = (unsigned __int128)_mm_sqrt_ps(v166);
            v167 = 1.0
                 - (float)((float)((float)(time_window.fClosingSpeed
                                         - *(float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[24].__vecDelDtor)(v12))
                                 - 5.0)
                         * 0.1);
            if ( v167 <= 0.5 )
            {
              v167 = FLOAT_0_5;
            }
            else if ( v167 >= 1.0 )
            {
              v167 = *(float *)&FLOAT_1_0;
            }
            *(float *)co_chaser = 1.0 - v167;
            if ( v260 == 0.0 )
              v168 = 0.0;
            else
              v168 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps((__m128)LODWORD(v260)));
            v169 = v168 * v251;
            v170 = v168 * v252;
            v171 = v168 * v253;
            v172 = v159 + v153;
            *(float *)&v156 = *(float *)&v156 + v154;
            v173 = (__m128)v156;
            v173.m128_f32[0] = (float)(*(float *)&v156 * *(float *)&v156) + (float)(v172 * v172);
            if ( v173.m128_f32[0] == 0.0 )
              v174 = 0.0;
            else
              v174 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v173));
            v175 = v174 * v172;
            v176 = v246;
            v177 = *(float *)co_chaser;
            v178 = (float)((float)((float)((float)((float)(v171 * v175) - (float)(v170 * (float)(v174 * *(float *)&v156)))
                                         * v167)
                                 + (float)((float)((float)(v175 * v246) - (float)(v241 * (float)(v174 * *(float *)&v156)))
                                         * *(float *)co_chaser))
                         + v5->m_fPassingBias) < 0.0;
            if ( v5->m_bStayOffSidewalk
              && ((LOBYTE(v236) = ((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v148->mPrev[16].mNext)(v148),
                   co_chaser[0] = ((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v148->mPrev[21].mNext)(v148),
                   v179 = ((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v148->mPrev[22].mPrev)(v148),
                   LOBYTE(v236))
               || co_chaser[0] ^ v179) )
            {
              v180 = (float *)((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v148->mPrev[8].mPrev)(v148);
              v181 = (float)((float)((float)(v170 * v180[1]) + (float)(v171 * *v180)) + (float)(v169 * v180[2])) * v167;
              v24 = v241;
              v182 = v247;
              v183 = (float)((float)((float)((float)(v241 * v180[1]) + (float)(v176 * *v180)) + (float)(v247 * v180[2]))
                           * v177)
                   + v181;
              v184 = co_chaser[0];
              if ( LOBYTE(v236) )
                v184 = 0;
              v178 = v184 ^ (v183 < 0.0);
            }
            else
            {
              v182 = v247;
              v24 = v241;
            }
            v185 = LODWORD(UFG::AiDriverComponent::m_fAvoidancePassingBias);
            if ( v178 )
              v185 = LODWORD(UFG::AiDriverComponent::m_fAvoidancePassingBias) ^ _xmm[0];
            LODWORD(v5->m_fPassingBias) = v185;
            v5->m_fPassingTimer = 0.25;
            v186 = &v254;
            if ( !v178 )
              v186 = &v255;
            v188 = (__m128)LODWORD(v263);
            v187 = (float)(v263 * v186->z) - v182;
            v188.m128_f32[0] = (float)(v263 * v186->y) - v24;
            v189 = (float)(v263 * v186->x) - v176;
            if ( !((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[38].__vecDelDtor)(v12)
              || !((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v148->mPrev[23].mPrev)(v148)
              || (v190 = ((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v148->mPrev[18].mNext)(v148),
                  co_chaser[0] = 1,
                  !v190) )
            {
              co_chaser[0] = 0;
            }
            v191 = v5->m_fAvoidSteerLimit;
            if ( v191 <= -1.0
              || (v192 = v188,
                  v192.m128_f32[0] = (float)((float)(v188.m128_f32[0] * v188.m128_f32[0]) + (float)(v189 * v189))
                                   + (float)(v187 * v187),
                  LODWORD(v193) = (unsigned __int128)_mm_sqrt_ps(v192),
                  v193 <= v191) )
            {
              if ( !LOBYTE(v61[1].mPrev) )
              {
                v218 = LODWORD(v61[1].mNext) ^ _xmm[0];
                if ( *(float *)&v218 > 0.0099999998 )
                {
                  v219 = time_window.fClosingSpeed / *(float *)&v218;
                  ((void (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[28].__vecDelDtor)(v12);
                  v220 = *(float *)&v218 * v219;
                  v221 = *v354;
                  if ( *v354 >= v220 )
                    v221 = v220;
                  *v354 = v221;
                }
              }
            }
            else
            {
              if ( v193 < 0.001 )
                v193 = FLOAT_0_001;
              v194 = v191 / v193;
              v189 = v189 * v194;
              v188.m128_f32[0] = v188.m128_f32[0] * v194;
              v187 = v187 * v194;
              if ( (float)((float)((float)(v162.m128_f32[0] * v252) + (float)(v161 * v253)) + (float)(v236 * v251)) > 0.0 )
              {
                v195 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[16].__vecDelDtor)(v12);
                v196 = (__m128)*(unsigned int *)v195;
                v196.m128_f32[0] = (float)((float)(v196.m128_f32[0] * v161) + (float)(v195[1] * v162.m128_f32[0]))
                                 + (float)(v195[2] * v236);
                v197 = v259 + *(float *)&v61[1].mNext;
                v196.m128_f32[0] = (float)((float)((float)(v196.m128_f32[0] * *v195) * (float)(v196.m128_f32[0] * *v195))
                                         + (float)((float)(v196.m128_f32[0] * v195[1])
                                                 * (float)(v196.m128_f32[0] * v195[1])))
                                 + (float)((float)(v196.m128_f32[0] * v195[2]) * (float)(v196.m128_f32[0] * v195[2]));
                LODWORD(v198) = (unsigned __int128)_mm_sqrt_ps(v196);
                v199 = *(unsigned int *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[24].__vecDelDtor)(v12);
                if ( v5->m_pVehicleSubject.m_pSimComponent
                  && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)v5->m_pVehicleSubject.m_pSimComponent) )
                {
                  v200 = 1;
                  v201 = FLOAT_80_0;
                }
                else
                {
                  v200 = 0;
                  v201 = FLOAT_6_0;
                }
                v202 = 0.0;
                if ( v5->m_bAllowedToPass )
                {
                  if ( v200 )
                    v201 = FLOAT_60_0;
                  else
                    v201 = 0.0;
                }
                if ( v5->m_bTemporaryAllowedToPass )
                {
                  if ( v200 )
                    v201 = FLOAT_60_0;
                  else
                    v201 = 0.0;
                }
                v203 = (float)(v198 - *(float *)&v199) - v201;
                if ( v203 >= 0.0 )
                  v202 = v203;
                v204 = v5->m_pVehicleSubject.m_pSimComponent
                    && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)v5->m_pVehicleSubject.m_pSimComponent);
                v205 = UFG::VehicleSubjectComponent::GetMass(v12);
                v206 = UFG::GetBrakingSpeedLimit(v202, 100.0, v205, v204) + v197;
                v207 = 0.0;
                if ( v206 >= 0.0 )
                  v207 = v206;
                v208 = *v355;
                if ( *v355 >= v207 )
                  v208 = v207;
                *v355 = v208;
                v209 = (UFG::SimObject *)v148[2].mNext;
                if ( v9->m_pPointer )
                {
                  v210 = v9->mPrev;
                  v211 = v9->mNext;
                  v210->mNext = v211;
                  v211->mPrev = v210;
                  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
                  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
                }
                v9->m_pPointer = v209;
                if ( v209 )
                {
                  v212 = v209->m_SafePointerList.mNode.mPrev;
                  v212->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
                  v9->mPrev = v212;
                  v9->mNext = &v209->m_SafePointerList.mNode;
                  v209->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
                }
                v213 = 0;
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v148->mPrev[18].mNext)(v148) )
                {
                  v214 = (UFG::SimObjectGame *)v148[2].mNext;
                  if ( v214 )
                  {
                    v215 = v214->m_Flags;
                    if ( (v215 >> 14) & 1 )
                    {
                      v216 = v214->m_Components.p[24].m_pComponent;
                    }
                    else if ( (v215 & 0x8000u) == 0 )
                    {
                      if ( (v215 >> 13) & 1 )
                        v216 = UFG::SimObjectGame::GetComponentOfTypeHK(v214, UFG::RoadSpaceComponent::_TypeUID);
                      else
                        v216 = (v215 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v214,
                                                    UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                           (UFG::SimObject *)&v214->vfptr,
                                                                                           UFG::RoadSpaceComponent::_TypeUID);
                    }
                    else
                    {
                      v216 = v214->m_Components.p[24].m_pComponent;
                    }
                    if ( v216 )
                      v213 = v216[8].m_Flags;
                  }
                }
                v217 = (v5->m_pVehicleSubject.m_pSimComponent
                     && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)v5->m_pVehicleSubject.m_pSimComponent)
                     || !co_chaser[0])
                    && !v213;
                v5->m_BlockedByAvoidable = v217;
                if ( v207 < 1.0
                  && ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v148->mPrev[20].mNext)(v148) )
                {
                  v5->m_fAvoidStopTimer = 3.0;
                }
              }
            }
            v8 = v187 + v352[2];
            v244 = v8;
            v7 = v188.m128_f32[0] + v352[1];
            v249 = v7;
            v6 = v189 + *v352;
            v245 = v6;
            point.x = v6;
            point.y = v7;
            point.z = v8;
            LOBYTE(v236) = 1;
          }
          else
          {
            v6 = v245;
            v8 = v244;
            v7 = v249;
            v24 = v241;
          }
          v61 = v61->mNext;
          *(float *)&v25 = v246;
        }
        while ( v61 != (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list );
      }
      if ( v5->m_AvoidanceDebug && LOBYTE(v236) )
      {
        close_limit.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + v6;
        close_limit.y = v7 + (float)(UFG::qVector3::msDirUp.y * 0.69999999);
        close_limit.z = v8 + (float)(UFG::qVector3::msDirUp.z * 0.69999999);
        v222 = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + v352[2];
        v223 = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + v352[1];
        v248.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + *v352;
        v248.y = v223;
        v248.z = v222;
        Render::DebugDrawContext::DrawLine(
          v265,
          &v248,
          &close_limit,
          &UFG::qColour::Blue,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        close_limit.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + v6;
        close_limit.y = v7 + (float)(UFG::qVector3::msDirUp.y * 0.69999999);
        close_limit.z = v8 + (float)(UFG::qVector3::msDirUp.z * 0.69999999);
        Render::DebugDrawContext::DrawSphere(
          v265,
          &close_limit,
          0.60000002,
          &UFG::qColour::Blue,
          &UFG::qMatrix44::msIdentity,
          0i64);
      }
      v224 = v8 - v15->z;
      v225 = v7 - v15->y;
      close_limit.x = v6 - v15->x;
      close_limit.y = v225;
      close_limit.z = v224;
      v226 = UFG::RoadSpaceComponent::SteerTo(&v338, v15, radius, &point, &close_limit);
      v227 = v226->y;
      v228 = v226->z;
      v43 = (__int64)v351;
      *v351 = LODWORD(v226->x);
      *(float *)(v43 + 4) = v227;
      *(float *)(v43 + 8) = v228;
      for ( i = list.mNode.mNext;
            (UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> *)list.mNode.mNext != &list;
            i = list.mNode.mNext )
      {
        v230 = i->mPrev;
        v231 = i->mNext;
        v230->mNext = v231;
        v231->mPrev = v230;
        i->mPrev = i;
        i->mNext = i;
        v352 = (float *)i;
        v232 = i->mPrev;
        v233 = i->mNext;
        v232->mNext = v233;
        v233->mPrev = v232;
        i->mPrev = i;
        i->mNext = i;
        operator delete[](i);
      }
      v234 = list.mNode.mPrev;
      v235 = list.mNode.mNext;
      list.mNode.mPrev->mNext = list.mNode.mNext;
      v235->mPrev = v234;
      list.mNode.mPrev = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list;
      list.mNode.mNext = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list;
    }
    else
    {
      v43 = (__int64)v351;
      *v351 = LODWORD(v4->x);
      *(float *)(v43 + 4) = v4->y;
      *(float *)(v43 + 8) = v4->z;
    }
    v13 = (UFG::qVector3 *)v43;
  }
  else
  {
    result->x = steerToPos->x;
    result->y = steerToPos->y;
    result->z = steerToPos->z;
    v13 = result;
  }
  return v13;
}Pos->x;
    result->y = steerToPos->y;
    result->z = steerToPos->z;
    v13 = result;
  }
  return v13;
}

// File Line: 6256
// RVA: 0x65FE50
void __usercall UFG::AiDriverComponent::UpdateAvoidableSensor(UFG::AiDriverComponent *this@<rcx>, float delta_seconds@<xmm1>, float a3@<xmm0>)
{
  UFG::SimComponent *v3; // rbx
  UFG::AiDriverComponent *v4; // rdi
  float v5; // xmm7_4
  float v6; // xmm3_4
  int v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  int v10; // xmm3_4
  __int64 v11; // rax
  float v12; // xmm0_4
  float v13; // xmm8_4
  __m128 v14; // xmm11
  float v15; // xmm12_4
  float v16; // xmm13_4
  float v17; // xmm9_4
  float v18; // xmm10_4
  float *v19; // rax
  float v20; // xmm6_4
  float v21; // xmm15_4
  __m128 v22; // xmm2
  float v23; // xmm1_4
  float v24; // xmm8_4
  float v25; // xmm12_4
  float v26; // xmm0_4
  bool v27; // al
  float v28; // xmm11_4
  bool v29; // cl
  float v30; // xmm11_4
  float v31; // xmm9_4
  float v32; // xmm10_4
  float v33; // xmm13_4
  float v34; // xmm8_4
  int v35; // xmm3_4
  float v36; // xmm8_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  int v40; // xmm7_4
  float v41; // xmm13_4
  float v42; // xmm9_4
  float v43; // xmm10_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  float *v46; // rax
  float v47; // xmm5_4
  __m128 v48; // xmm3
  float v49; // xmm4_4
  __m128 v50; // xmm2
  float v51; // xmm5_4
  int v52; // xmm0_4
  float v53; // xmm3_4
  float v54; // xmm4_4
  float v55; // xmm0_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm5_4
  float v59; // xmm3_4
  float v60; // xmm4_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm1_4
  UFG::qMatrix44 *v64; // rax
  float v65; // [rsp+18h] [rbp-79h]
  float v66; // [rsp+18h] [rbp-79h]
  float v67; // [rsp+1Ch] [rbp-75h]
  float v68; // [rsp+1Ch] [rbp-75h]
  float v69; // [rsp+20h] [rbp-71h]
  float v70; // [rsp+20h] [rbp-71h]
  float buf; // [rsp+28h] [rbp-69h]
  float v72; // [rsp+2Ch] [rbp-65h]
  float v73; // [rsp+30h] [rbp-61h]
  int nbytes; // [rsp+34h] [rbp-5Dh]
  float v75; // [rsp+38h] [rbp-59h]
  float v76; // [rsp+3Ch] [rbp-55h]
  float retaddr; // [rsp+F8h] [rbp+67h]
  float v78; // [rsp+108h] [rbp+77h]

  v3 = this->m_pVehicleSubject.m_pSimComponent;
  v4 = this;
  if ( v3 )
  {
    ((void (__fastcall *)(UFG::SimComponent *))v3->vfptr[21].__vecDelDtor)(v3);
    v5 = a3;
    if ( a3 >= 5.0 )
      v5 = FLOAT_5_0;
    v6 = (float)(v5 * 2.0) * 0.5;
    *(float *)&v7 = UFG::qVector3::msZero.x + v6;
    v8 = UFG::qVector3::msZero.y + v6;
    v9 = UFG::qVector3::msZero.z + v6;
    v10 = LODWORD(v6) ^ _xmm[0];
    buf = UFG::qVector3::msZero.x + *(float *)&v10;
    v72 = UFG::qVector3::msZero.y + *(float *)&v10;
    v73 = UFG::qVector3::msZero.z + *(float *)&v10;
    nbytes = v7;
    v75 = v8;
    v76 = v9;
    v11 = ((__int64 (__fastcall *)(UFG::SimComponent *))v3->vfptr[20].__vecDelDtor)(v3);
    v12 = FLOAT_2_0;
    v13 = *(float *)v11;
    v14 = (__m128)*(unsigned int *)(v11 + 4);
    v15 = *(float *)(v11 + 8);
    if ( v4->m_bAllowedToPass )
      v12 = *(float *)&FLOAT_1_0;
    v16 = v13 * v12;
    v17 = v14.m128_f32[0] * v12;
    v18 = v15 * v12;
    v19 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v3->vfptr[16].__vecDelDtor)(v3);
    v22 = v14;
    v20 = 0.0;
    v21 = *v19;
    retaddr = v19[1];
    v78 = v19[2];
    v22.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v13 * v13)) + (float)(v15 * v15);
    if ( v22.m128_f32[0] >= 1.0 )
    {
      if ( v22.m128_f32[0] == 0.0 )
        v23 = 0.0;
      else
        v23 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v22));
      v65 = v13 * v23;
      v67 = v14.m128_f32[0] * v23;
      v69 = v15 * v23;
    }
    else
    {
      v65 = *v19;
      v67 = v19[1];
      v69 = v19[2];
    }
    v24 = v65;
    v25 = v67;
    v26 = UFG::AiDriverComponent::GetBumperGap(v4);
    v27 = v4->m_bAllowedToPass;
    v28 = FLOAT_0_2;
    if ( v27 )
      v28 = FLOAT_0_40000001;
    v29 = v4->m_bTemporaryAllowedToPass;
    if ( v29 )
      v28 = FLOAT_0_2;
    v30 = v28 + v26;
    v31 = v17 + (float)(v25 * v30);
    v32 = v18 + (float)(v69 * v30);
    v33 = v16 + (float)(v24 * v30);
    if ( v29 || v27 )
      v34 = FLOAT_4_0;
    else
      v34 = FLOAT_3_0;
    v35 = nbytes;
    v36 = v34 * v5;
    if ( *(float *)&nbytes <= (float)(v33 + v36) )
      *(float *)&v35 = v33 + v36;
    v37 = v75;
    nbytes = v35;
    if ( v75 <= (float)(v31 + v36) )
      v37 = v31 + v36;
    v38 = v76;
    v75 = v37;
    if ( v76 <= (float)(v32 + v36) )
      v38 = v32 + v36;
    v76 = v38;
    v39 = buf;
    v40 = LODWORD(v36) ^ _xmm[0];
    v41 = v33 + COERCE_FLOAT(LODWORD(v36) ^ _xmm[0]);
    v42 = v31 + COERCE_FLOAT(LODWORD(v36) ^ _xmm[0]);
    v43 = v32 + COERCE_FLOAT(LODWORD(v36) ^ _xmm[0]);
    if ( buf >= v41 )
      v39 = v41;
    buf = v39;
    v44 = v72;
    if ( v72 >= v42 )
      v44 = v42;
    v45 = v73;
    v72 = v44;
    if ( v73 >= v43 )
      v45 = v43;
    v73 = v45;
    v46 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v3->vfptr[17].__vecDelDtor)(v3);
    v48 = (__m128)LODWORD(v4->m_vSteerToPosition.y);
    v47 = v4->m_vSteerToPosition.x - *v46;
    v48.m128_f32[0] = v48.m128_f32[0] - v46[1];
    v49 = v4->m_vSteerToPosition.z - v46[2];
    v50 = v48;
    v50.m128_f32[0] = (float)((float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(v47 * v47)) + (float)(v49 * v49);
    if ( v50.m128_f32[0] >= 0.010000001 )
    {
      if ( v50.m128_f32[0] != 0.0 )
        v20 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v50));
      v66 = v47 * v20;
      v68 = v48.m128_f32[0] * v20;
      v70 = v49 * v20;
    }
    else
    {
      v66 = v21;
      v68 = retaddr;
      v70 = v78;
    }
    v51 = v47 + (float)(v66 * v30);
    v52 = nbytes;
    v53 = v48.m128_f32[0] + (float)(v68 * v30);
    v54 = v49 + (float)(v70 * v30);
    if ( *(float *)&nbytes <= (float)(v51 + v36) )
      *(float *)&v52 = v51 + v36;
    nbytes = v52;
    v55 = v75;
    if ( v75 <= (float)(v53 + v36) )
      v55 = v53 + v36;
    v75 = v55;
    v56 = v76;
    if ( v76 <= (float)(v54 + v36) )
      v56 = v54 + v36;
    v57 = buf;
    v58 = v51 + *(float *)&v40;
    v59 = v53 + *(float *)&v40;
    v60 = v54 + *(float *)&v40;
    v76 = v56;
    if ( buf >= v58 )
      v57 = v58;
    buf = v57;
    v61 = v72;
    if ( v72 >= v59 )
      v61 = v59;
    v62 = v73;
    v72 = v61;
    if ( v73 >= v60 )
      v62 = v60;
    v73 = v62;
    v63 = (float)(v62 + v56) * 0.5;
    if ( (float)((float)(v56 - v62) * 0.5) > 3.5 )
    {
      v76 = v63 + 3.5;
      v73 = v63 - 3.5;
    }
    Scaleform::Render::WrapperImageSource::GetFormat(
      (hkSubStreamWriter *)v4->m_AvoidableSensor,
      &buf,
      (unsigned __int64)&nbytes);
    v64 = (UFG::qMatrix44 *)((__int64 (__fastcall *)(UFG::SimComponent *))v3->vfptr[18].__vecDelDtor)(v3);
    UFG::SensorPhantom::SetTransform(v4->m_AvoidableSensor, v64);
  }
}

// File Line: 6344
// RVA: 0x64F220
float __fastcall UFG::AiDriverComponent::GetRoadHolding(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *v1; // rax
  UFG::AiDriverComponent *v2; // rbx
  float v3; // xmm6_4
  UFG::VehicleSubjectComponent *v4; // rcx
  float result; // xmm0_4

  v1 = this->mMoverComponent.m_pSimComponent;
  v2 = this;
  if ( v1 )
    v3 = *((float *)&v1[11].m_pSimObject + 1);
  else
    v3 = *(float *)&FLOAT_1_0;
  if ( ((unsigned __int8 (*)(void))this->vfptr[16].__vecDelDtor)()
    && (v4 = (UFG::VehicleSubjectComponent *)v2->m_pVehicleSubject.m_pSimComponent) != 0i64
    && UFG::VehicleSubjectComponent::IsBoat(v4) )
  {
    result = FLOAT_0_1;
  }
  else
  {
    result = v3;
  }
  return result;
}

// File Line: 6353
// RVA: 0x660A30
float __usercall UFG::AiDriverComponent::UpdateChaseSpeed@<xmm0>(UFG::AiDriverComponent *this@<rcx>, float seconds@<xmm1>, int a3@<xmm0>)
{
  UFG::AiDriverComponent *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rax
  float v8; // xmm10_4
  float v9; // xmm12_4
  UFG::SimComponent *v10; // rax
  float v11; // xmm11_4
  float v12; // xmm1_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  float v15; // xmm6_4
  float v16; // xmm8_4
  float v17; // xmm2_4
  float v18; // xmm10_4
  float v19; // xmm11_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  UFG::VehicleSubjectComponent *v23; // rcx
  float v24; // xmm6_4
  bool v25; // di
  UFG::VehicleSubjectComponent *v26; // rcx
  float v27; // xmm0_4
  float v28; // xmm6_4
  float result; // xmm0_4

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->m_pRoadSpace.m_pSimComponent[26].m_pSimObject;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = (UFG::SimObjectGame *)v4->m_Components.p[37].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CameraSubject::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CameraSubject::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::CameraSubject::_TypeUID);
      }
      v4 = (UFG::SimObjectGame *)v6;
    }
    else
    {
      v4 = (UFG::SimObjectGame *)v4->m_Components.p[31].m_pComponent;
    }
  }
  v7 = v3->m_pSimObject;
  if ( !v7 || !v7->m_Components.p[2].m_pComponent || !v3->m_pRoadSpace.m_pSimComponent || !v4 )
    return 0.0;
  v8 = v3->m_vFollowOffsetDesired.x;
  v9 = v3->m_fFollowOffsetBlend;
  ((void (*)(void))v4->vfptr[28].__vecDelDtor)();
  v10 = v3->m_pRoadSpace.m_pSimComponent;
  v11 = *(float *)&v10[29].m_BoundComponentHandles.mNode.mPrev;
  LODWORD(v12) = a3 & _xmm;
  v13 = 1.0 - (float)(*(float *)&v10[29].m_BoundComponentHandles.mNode.mPrev * v3->m_vFollowOffsetActual.y);
  if ( v13 < 0.0 )
    v13 = 0.0;
  v14 = v3->m_fChaseSpeedLimit;
  v15 = (float)((float)(v3->m_vFollowOffsetActual.x - COERCE_FLOAT(LODWORD(v10[29].m_pSimObject) ^ _xmm[0])) * v9)
      + COERCE_FLOAT(LODWORD(v10[29].m_pSimObject) ^ _xmm[0]);
  v16 = (float)((float)((float)(v13 - 1.0) * v9) + 1.0) * v12;
  if ( v14 < 0.0 )
    v14 = FLOAT_35_0;
  if ( v14 <= (float)(UFG::AiDriverComponent::m_fChaseFasterThanTarget + v12) )
    v14 = UFG::AiDriverComponent::m_fChaseFasterThanTarget + v12;
  v17 = UFG::AiDriverComponent::GetRoadHolding(v3);
  v18 = v8 - v15;
  v19 = UFG::GetSpeedLimitForCurvature(v11, v14, v17);
  if ( v18 <= -5.0 )
  {
    v21 = FLOAT_N5_0;
  }
  else
  {
    v20 = FLOAT_5_0;
    v21 = v18;
    if ( v18 >= 5.0 )
      goto LABEL_27;
  }
  v20 = v21;
LABEL_27:
  v22 = sinf((float)(v20 - -5.0) * 0.15707964);
  v23 = (UFG::VehicleSubjectComponent *)v3->m_pVehicleSubject.m_pSimComponent;
  v24 = (float)((float)(v22 * v22) * 20.0) - 10.0;
  v25 = v23 && UFG::VehicleSubjectComponent::IsBoat(v23);
  v26 = (UFG::VehicleSubjectComponent *)v3->m_pVehicleSubject.m_pSimComponent;
  if ( v26 )
    v27 = UFG::VehicleSubjectComponent::GetMass(v26);
  else
    v27 = FLOAT_2000_0;
  v28 = (float)((float)((float)(v24 + v16) - v19) * v9) + v19;
  result = UFG::GetBrakingSpeedLimit(v18, v14, v27, v25) + v16;
  if ( result >= v28 )
    result = v28;
  if ( result <= 0.0 )
    return 0.0;
  return result;
}

// File Line: 6395
// RVA: 0x6582E0
UFG::qVector3 *__fastcall UFG::AiDriverComponent::RotateSteerTo(UFG::AiDriverComponent *this, UFG::qVector3 *result, UFG::qVector3 *steer_to, float steer_to_distance, float radians)
{
  UFG::qVector3 *v5; // rsi
  UFG::qVector3 *v6; // rdi
  UFG::SimObject *v7; // rax
  UFG::TransformNodeComponent *v8; // rbx
  float v9; // xmm11_4
  float v10; // xmm10_4
  float v11; // xmm9_4
  float v12; // xmm8_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm0_4
  UFG::qVector3 *v16; // rax

  v5 = steer_to;
  v6 = result;
  v7 = this->m_pSimObject;
  if ( v7 )
    v8 = (UFG::TransformNodeComponent *)v7->m_Components.p[2].m_pComponent;
  else
    v8 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  v9 = v8->mWorldTransform.v3.x;
  v10 = v8->mWorldTransform.v3.y;
  v11 = v8->mWorldTransform.v3.z;
  v12 = v5->z - v11;
  v13 = atan2f(v5->y - v10, v5->x - v9) + radians;
  v14 = cosf(v13);
  v15 = sinf(v13);
  v6->x = v9 + (float)(v14 * steer_to_distance);
  v6->z = v11 + v12;
  v16 = v6;
  v6->y = v10 + (float)(v15 * steer_to_distance);
  return v16;
}

// File Line: 6408
// RVA: 0x65DF70
UFG::qVector3 *__usercall UFG::AiDriverComponent::SteerToFollowOffset@<rax>(UFG::AiDriverComponent *this@<rcx>, UFG::qVector3 *result@<rdx>, float delta_seconds@<xmm2>, float steer_to_distance@<xmm3>, UFG::qVector3 *a5@<rsi>, UFG::qVector3 *steer_to)
{
  UFG::SimObject *v6; // rax
  UFG::qVector3 *v7; // rbx
  UFG::AiDriverComponent *v8; // rdi
  UFG::SimComponent *v9; // r13
  UFG::SimObjectGame *v10; // rcx
  UFG::TransformNodeComponent *v12; // r14
  unsigned __int16 v13; // dx
  UFG::RoadSpaceComponent *v14; // rsi
  UFG::SimComponent *v15; // rax
  Render::DebugDrawContext *v16; // r15
  __m128 v17; // xmm1
  float v18; // xmm9_4
  float v19; // xmm6_4
  bool v20; // zf
  __m128 v21; // xmm2
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm6_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm12_4
  float v29; // xmm7_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm6_4
  UFG::qVector3 *v33; // rax
  float v34; // xmm0_4
  float v35; // xmm5_4
  float v36; // xmm6_4
  float v37; // xmm4_4
  float v38; // xmm4_4
  float v39; // xmm5_4
  float v40; // xmm4_4
  float v41; // xmm6_4
  float v42; // xmm5_4
  float v43; // xmm1_4
  UFG::qColour *v44; // r9
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm2_4
  float ray_4; // [rsp+24h] [rbp-7Dh]
  float pre_draw_callback; // [rsp+28h] [rbp-79h]
  UFG::qVector3 resulta; // [rsp+30h] [rbp-71h]
  UFG::qVector3 p1; // [rsp+40h] [rbp-61h]
  UFG::qColour ray; // [rsp+50h] [rbp-51h]
  UFG::qVector3 *p0; // [rsp+120h] [rbp+7Fh]
  UFG::qVector3 *p0a; // [rsp+120h] [rbp+7Fh]

  v6 = this->m_pSimObject;
  v7 = result;
  v8 = this;
  if ( !v6
    || (v9 = v6->m_Components.p[2].m_pComponent) == 0i64
    || (v10 = (UFG::SimObjectGame *)this->m_pRoadSpace.m_pSimComponent[26].m_pSimObject) == 0i64 )
  {
    result->x = p0->x;
    result->y = p0->y;
    result->z = p0->z;
    return result;
  }
  v12 = v10->m_pTransformNodeComponent;
  if ( !v12 )
  {
    result->x = p0->x;
    result->y = p0->y;
    result->z = p0->z;
    return result;
  }
  v13 = v10->m_Flags;
  p0a = a5;
  if ( (v13 >> 14) & 1 )
  {
    v14 = (UFG::RoadSpaceComponent *)v10->m_Components.p[24].m_pComponent;
  }
  else if ( (v13 & 0x8000u) == 0 )
  {
    if ( (v13 >> 13) & 1 )
    {
      v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RoadSpaceComponent::_TypeUID);
    }
    else if ( (v13 >> 12) & 1 )
    {
      v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RoadSpaceComponent::_TypeUID);
    }
    else
    {
      v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::RoadSpaceComponent::_TypeUID);
    }
    v14 = (UFG::RoadSpaceComponent *)v15;
  }
  else
  {
    v14 = (UFG::RoadSpaceComponent *)v10->m_Components.p[24].m_pComponent;
  }
  if ( v14 )
  {
    v16 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    if ( v8->m_FollowDebug )
    {
      ray = UFG::qColour::Yellow;
      UFG::CrumbTrail::DebugDraw(&v14->m_PositionTrail, &ray, -1);
    }
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
    UFG::TransformNodeComponent::UpdateWorldTransform(v12);
    v17 = (__m128)LODWORD(v8->m_vFollowOffsetActual.y);
    v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] - v8->m_vFollowOffsetDesired.y)
                            * (float)(v17.m128_f32[0] - v8->m_vFollowOffsetDesired.y))
                    + (float)((float)(v8->m_vFollowOffsetActual.x - v8->m_vFollowOffsetDesired.x)
                            * (float)(v8->m_vFollowOffsetActual.x - v8->m_vFollowOffsetDesired.x));
    LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v17);
    if ( v18 >= v8->m_fFollowOffsetTolerance )
      v19 = 0.0;
    else
      v19 = delta_seconds + v8->m_fTimeNearOffset;
    v20 = v8->m_CurrentAttack == 7;
    v8->m_fTimeNearOffset = v19;
    v21 = (__m128)LODWORD(v12->mWorldTransform.v3.y);
    v22 = v12->mWorldTransform.v3.x - *(float *)&v9[2].m_BoundComponentHandles.mNode.mPrev;
    v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0]
                                            - *((float *)&v9[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                    * (float)(v21.m128_f32[0]
                                            - *((float *)&v9[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                            + (float)(v22 * v22))
                    + (float)((float)(v12->mWorldTransform.v3.z - *(float *)&v9[2].m_BoundComponentHandles.mNode.mNext)
                            * (float)(v12->mWorldTransform.v3.z - *(float *)&v9[2].m_BoundComponentHandles.mNode.mNext));
    LODWORD(v23) = (unsigned __int128)_mm_sqrt_ps(v21);
    if ( v18 < v23 )
      v23 = v18;
    if ( v20 )
    {
      v26 = FLOAT_0_000099999997;
      if ( (float)((float)(steer_to_distance + 5.0) - steer_to_distance) >= 0.000099999997 )
        v26 = (float)(steer_to_distance + 5.0) - steer_to_distance;
      v24 = *(float *)&FLOAT_1_0;
      v25 = (float)((float)(v23 - steer_to_distance) * (float)(-1.0 / v26)) + 1.0;
      if ( v25 <= 0.0 )
      {
        v25 = 0.0;
      }
      else if ( v25 >= 1.0 )
      {
        v25 = *(float *)&FLOAT_1_0;
      }
    }
    else
    {
      v24 = *(float *)&FLOAT_1_0;
      v25 = *(float *)&FLOAT_1_0;
    }
    v8->m_fFollowOffsetBlend = v25;
    v27 = p0a->y;
    p1.x = p0a->x;
    ray_4 = v27;
    pre_draw_callback = p0a->z;
    UFG::RoadSpaceComponent::ChaseToWorld(v14, &resulta, &v8->m_vFollowOffsetDesired, (UFG::qVector3 *)&ray);
    v28 = v8->m_fFollowOffsetBlend;
    if ( v28 <= 0.0 )
      goto LABEL_49;
    if ( v8->mMoverComponent.m_pSimComponent )
      v29 = *((float *)&v8->mMoverComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1);
    else
      v29 = 0.0;
    v30 = (float)(v29 - 2.0) * 0.33333334;
    if ( v30 <= 0.0 )
    {
      v30 = 0.0;
    }
    else if ( v30 >= v24 )
    {
      v30 = v24;
    }
    v31 = (float)(v8->m_vFollowOffsetDesired.y - v8->m_vFollowOffsetActual.y) / (float)(v18 + steer_to_distance);
    if ( v31 <= -1.0 )
    {
      v31 = FLOAT_N1_0;
    }
    else if ( v31 >= v24 )
    {
LABEL_47:
      v32 = sinf((float)(v24 - -1.0) * 0.78539819);
      UFG::RoadSpaceComponent::SteerTo(
        &p1,
        (UFG::qVector3 *)&v9[2].m_BoundComponentHandles,
        steer_to_distance,
        &resulta,
        (UFG::qVector3 *)&ray);
      v33 = UFG::AiDriverComponent::RotateSteerTo(
              v8,
              (UFG::qVector3 *)&ray,
              &p1,
              steer_to_distance,
              (float)((float)((float)(v32 * v32) * 0.69813174) - 0.34906587) * (float)(v28 * v30));
      v34 = v8->m_fFollowOffsetBlend;
      v35 = v33->y;
      v36 = v33->z;
      v37 = v33->x;
      p1.x = v37;
      v38 = v37 - p0a->x;
      p1.y = v35;
      v39 = v35 - p0a->y;
      v40 = (float)(v38 * v34) + p0a->x;
      p1.z = v36;
      v41 = v36 - p0a->z;
      v42 = (float)(v39 * v34) + p0a->y;
      p1.x = v40;
      ray_4 = v42;
      pre_draw_callback = (float)(v41 * v34) + p0a->z;
      if ( v8->m_FollowDebug )
      {
        Render::DebugDrawContext::DrawLine(v16, p0a, &p1, &UFG::qColour::Cyan, &UFG::qMatrix44::msIdentity, 0i64, 0);
        Render::DebugDrawContext::DrawSphere(
          v16,
          &p1,
          0.60000002,
          &UFG::qColour::Cyan,
          &UFG::qMatrix44::msIdentity,
          0i64);
        Render::DebugDrawContext::DrawSphere(v16, &p1, 0.2, &UFG::qColour::Red, &UFG::qMatrix44::msIdentity, 0i64);
      }
LABEL_49:
      if ( v8->m_FollowDebug )
      {
        if ( v8->m_fTimeNearOffset <= 0.0 )
        {
          UFG::RoadSpaceComponent::ChaseToWorld(v14, (UFG::qVector3 *)&ray, &v8->m_vFollowOffsetActual, 0i64);
          v46 = v8->m_fFollowOffsetTolerance;
          p1.x = resulta.x;
          p1.y = resulta.y;
          p1.z = resulta.z + 0.5;
          Render::DebugDrawContext::DrawCircle(v16, &p1, v46, &UFG::qColour::Yellow, &UFG::qMatrix44::msIdentity, 0i64);
          v43 = ray.g;
          v44 = &UFG::qColour::Blue;
          p1.x = ray.r;
          v45 = ray.b;
        }
        else
        {
          v43 = resulta.y;
          v44 = &UFG::qColour::Green;
          p1.x = resulta.x;
          v45 = resulta.z;
        }
        v47 = v8->m_fFollowOffsetTolerance;
        p1.z = v45 + 0.5;
        p1.y = v43;
        Render::DebugDrawContext::DrawCircle(v16, &p1, v47, v44, &UFG::qMatrix44::msIdentity, 0i64);
      }
      v7->x = p1.x;
      v7->y = ray_4;
      v7->z = pre_draw_callback;
      return v7;
    }
    v24 = v31;
    goto LABEL_47;
  }
  v7->x = p0a->x;
  v7->y = p0a->y;
  v7->z = p0a->z;
  return v7;
}

// File Line: 6482
// RVA: 0x659210
void __fastcall UFG::AiDriverComponent::SetFollowOffset(UFG::AiDriverComponent *this, float x, float y, float tolerance)
{
  if ( this->m_DesiredOffset == Follow
    && (float)((float)((float)((float)(this->m_vFollowOffsetDesired.y - y) * (float)(this->m_vFollowOffsetDesired.y - y))
                     + (float)((float)(this->m_vFollowOffsetDesired.x - x) * (float)(this->m_vFollowOffsetDesired.x - x)))
             + (float)(this->m_vFollowOffsetDesired.z * this->m_vFollowOffsetDesired.z)) >= (float)(this->m_fFollowOffsetTolerance
                                                                                                  * this->m_fFollowOffsetTolerance) )
  {
    this->m_fTimeNearOffset = 0.0;
  }
  this->m_DesiredOffset = 0;
  LODWORD(this->m_fFollowDistance) = LODWORD(x) ^ _xmm[0];
  this->m_Side = y >= 0.0;
  this->m_vFollowOffsetDesired.z = 0.0;
  this->m_vFollowOffsetDesired.x = x;
  this->m_vFollowOffsetDesired.y = y;
  if ( tolerance <= 5.0 )
    this->m_fFollowOffsetTolerance = tolerance;
  else
    this->m_fFollowOffsetTolerance = FLOAT_5_0;
}

// File Line: 6498
// RVA: 0x6591E0
void __fastcall UFG::AiDriverComponent::SetFollowDistance(UFG::AiDriverComponent *this, float distance)
{
  this->m_fFollowDistance = distance;
  *(_QWORD *)&this->m_vFollowOffsetDesired.y = 0i64;
  LODWORD(this->m_vFollowOffsetDesired.x) = LODWORD(distance) ^ _xmm[0];
}

// File Line: 6561
// RVA: 0x6520F0
char __fastcall UFG::AiDriverComponent::IsTaxi(UFG::AiDriverComponent *this)
{
  return UFG::SimObjectUtility::IsClassType(this->m_pSimObject, (UFG::qSymbol *)&qSymbol_Taxi.mUID);
}

// File Line: 6567
// RVA: 0x659620
void __fastcall UFG::AiDriverComponent::SetParked(UFG::AiDriverComponent *this, bool parked)
{
  UFG::AiDriverComponent *v2; // rbx
  UFG::SimComponent *v3; // rsi
  UFG::RoadNetworkLane *v4; // rdi
  UFG::RoadNetworkGuide *v5; // rcx
  UFG::RoadNetworkLocation *v6; // rax
  float v7; // xmm6_4
  float v8; // xmm0_4
  UFG::RoadNetworkLocation *v9; // rax
  UFG::RoadNetworkSegment *v10; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-28h]

  v2 = this;
  if ( this->m_bIsParked != parked )
  {
    this->m_bIsParked = parked;
    v3 = this->m_pRoadSpace.m_pSimComponent;
    v4 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v3[5].m_BoundComponentHandles.mNode.mNext)->m_CurrentLane;
    v5 = (UFG::RoadNetworkGuide *)&v2->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext;
    if ( v2->m_bIsParked )
    {
      v6 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v5);
      UFG::RoadNetworkLocation::GetPos(v6, &result);
      UFG::RoadNetworkGuide::Park((UFG::RoadNetworkGuide *)&v3[5].m_BoundComponentHandles.mNode.mNext);
      if ( v2->m_DrivingMode )
      {
        v2->m_DrivingMode = 0;
        v2->m_fReactionTime = 0.0;
        v2->m_fDelayedStopDecel = 0.0;
        v2->mModeSteeringLockEnabled = 0;
        v2->mModeGasBrakeLockEnabled = 0;
        v2->m_bIgnoreArrivalDirection = 0;
        if ( v2->m_ResetStopDistOnStop )
          v2->m_StopDist = 1.0;
      }
      v7 = v4->mOffset;
      v8 = UFG::RoadNetworkLane::CalculateParkingOffset(v4, &result);
      if ( v8 <= v7 )
        v8 = v7;
      v4->mOffset = v8;
    }
    else
    {
      v9 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v5);
      v10 = (UFG::RoadNetworkSegment *)UFG::RoadNetworkLocation::GetRoadNetworkNode(v9);
      UFG::RoadNetworkSegment::RecalculateLaneOffset(v10, v4->mLaneIndex);
    }
  }
}

// File Line: 6597
// RVA: 0x658E30
void __fastcall UFG::AiDriverComponent::SetDrivingRoleByClassType(UFG::AiDriverComponent *this)
{
  UFG::AiDriverComponent *v1; // rbx
  UFG::SceneObjectProperties *v2; // rcx
  UFG::qPropertySet *v3; // rdi
  unsigned int v4; // eax
  unsigned int v5; // edi
  char *v6; // r11
  int v7; // er10
  char ptr; // [rsp+40h] [rbp-48h]

  v1 = this;
  v2 = this->m_pSimObject->m_pSceneObj;
  v3 = v2->mpWritableProperties;
  if ( v3 || (v3 = v2->mpConstProperties) != 0i64 )
  {
    `eh vector constructor iterator(&ptr, 4ui64, 16, (void (__fastcall *)(void *))BackInfo::BackInfo);
    v4 = UFG::SimObjectUtility::GetClassTypes(v3, (UFG::qSymbol *)&ptr, 0x10u);
    v5 = 0;
    if ( v4 )
    {
      v6 = &ptr;
      while ( 1 )
      {
        v7 = *(_DWORD *)v6;
        if ( *(_DWORD *)v6 == qSymbol_Ferry.mUID )
        {
          if ( v1->m_DrivingRole == 8 )
            goto LABEL_27;
          v1->m_DrivingRole = 8;
LABEL_23:
          if ( !v1->m_RoadRuleFlagsLocked )
          {
            v1->m_bStayOffSidewalk = 1;
            v1->m_bAllowedToPass = 0;
            v1->m_bAvoidPeds = 1;
LABEL_25:
            v1->m_bRespectSpeedLimit = 1;
            v1->m_bCanTurnAround = 0;
          }
LABEL_26:
          v1->m_bSavedAvoidPeds = v1->m_bAvoidPeds;
          goto LABEL_27;
        }
        if ( v7 == qSymbol_Tram.mUID )
          break;
        if ( v7 == qSymbol_Minibus.mUID )
        {
          if ( v1->m_DrivingRole == 6 )
            goto LABEL_27;
          v1->m_DrivingRole = 6;
          goto LABEL_23;
        }
        if ( v7 == qSymbol_Boat_21.mUID )
        {
          if ( v1->m_DrivingRole == 9 )
            goto LABEL_27;
          v1->m_DrivingRole = 9;
          if ( !v1->m_RoadRuleFlagsLocked )
          {
            v1->m_bAvoidPeds = 0;
            v1->m_fAvoidStopTimer = 0.0;
            v1->m_bAllowedToPass = 1;
            v1->m_bStayOffSidewalk = 0;
            goto LABEL_25;
          }
          goto LABEL_26;
        }
        ++v5;
        v6 += 4;
        if ( v5 >= v4 )
          goto LABEL_27;
      }
      if ( v1->m_DrivingRole != 7 )
      {
        v1->m_DrivingRole = 7;
        if ( !v1->m_RoadRuleFlagsLocked )
        {
          v1->m_bAvoidPeds = 0;
          v1->m_fAvoidStopTimer = 0.0;
          v1->m_bAllowedToPass = 0;
          v1->m_bStayOffSidewalk = 0;
          v1->m_bRespectSpeedLimit = 1;
          v1->m_bCanTurnAround = 0;
        }
        v1->m_bSavedAvoidPeds = v1->m_bAvoidPeds;
      }
      v1->m_RoadRuleFlagsLocked = 1;
    }
LABEL_27:
    `eh vector destructor iterator(&ptr, 4ui64, 16, (void (__fastcall *)(void *))_);
  }
}

// File Line: 6654
// RVA: 0x651B20
bool __fastcall UFG::AiDriverComponent::IsBoat(UFG::AiDriverComponent *this)
{
  UFG::VehicleSubjectComponent *v1; // rcx

  v1 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  return v1 && UFG::VehicleSubjectComponent::IsBoat(v1);
}

// File Line: 6661
// RVA: 0x652100
bool __fastcall UFG::AiDriverComponent::IsTransit(UFG::AiDriverComponent *this)
{
  return this->m_DrivingRole - 6 <= 2;
}

