// File Line: 91
// RVA: 0x1573920
__int64 dynamic_initializer_for__UFG::AiDriverComponent::s_AiDriverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AiDriverComponent::s_AiDriverComponentList__);
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
  float y; // xmm1_4
  float z; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *mPrev; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::SensorPhantom *v12; // rax
  __int64 v13; // rbx
  char v14; // dl
  char v15; // cl
  _QWORD **Value; // rax
  hkpSphereShape *v17; // rax
  hkpSphereShape *v18; // rax
  char v19; // al
  char v20; // dl
  char v21; // cl
  _QWORD **v22; // rax
  hkpSimpleShapePhantom *v23; // rax
  hkpSimpleShapePhantom *v24; // rax
  char v25; // al
  hkAabb aabb; // [rsp+40h] [rbp-88h] BYREF
  hkTransformf transform; // [rsp+60h] [rbp-68h] BYREF

  UFG::VehicleDriverInterface::VehicleDriverInterface(this, UFG::AiDriverComponent::mNameUID);
  this->UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent>::mPrev = &this->UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent>;
  this->UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent>::mNext = &this->UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent>;
  this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AiDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AiDriverComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0>::RebindingComponentHandle<UFG::RoadSpaceComponent,0>(&this->m_pRoadSpace);
  UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>(&this->m_pVehicleSubject);
  this->m_pChaseVehicleSubject.mPrev = &this->m_pChaseVehicleSubject;
  this->m_pChaseVehicleSubject.mNext = &this->m_pChaseVehicleSubject;
  this->m_pChaseVehicleSubject.m_pPointer = 0i64;
  this->m_pEscortEnemyVehicleSubject.mPrev = &this->m_pEscortEnemyVehicleSubject;
  this->m_pEscortEnemyVehicleSubject.mNext = &this->m_pEscortEnemyVehicleSubject;
  this->m_pEscortEnemyVehicleSubject.m_pPointer = 0i64;
  this->m_pEscortObjectiveVehicleSubject.mPrev = &this->m_pEscortObjectiveVehicleSubject;
  this->m_pEscortObjectiveVehicleSubject.mNext = &this->m_pEscortObjectiveVehicleSubject;
  this->m_pEscortObjectiveVehicleSubject.m_pPointer = 0i64;
  UFG::qPidControllerCore::qPidControllerCore(&this->m_SteeringPid);
  UFG::qPidControllerCore::qPidControllerCore(&this->m_ThrottlePid);
  UFG::DrivingTargetOffsetMover::DrivingTargetOffsetMover(&this->m_OffsetMover);
  this->m_DriveToCoroutine.i_obj_p = 0i64;
  this->m_DriveToCoroutine.i_ptr_id = 0;
  *(_QWORD *)&this->m_DrivingMode = 0i64;
  this->m_CatchupTarget.mPrev = &this->m_CatchupTarget;
  this->m_CatchupTarget.mNext = &this->m_CatchupTarget;
  this->m_CatchupTarget.m_pPointer = 0i64;
  UFG::qPidControllerCore::qPidControllerCore(&this->m_CatchupPid);
  this->m_CatchupRangeBehind = 10.0;
  *(_QWORD *)&this->m_CatchupRangeAhead = 1092616192i64;
  *(_QWORD *)&this->m_CatchupMaxSlowDown = 0i64;
  *(_QWORD *)&this->m_fDesiredSpeed = 0i64;
  this->m_fPreviousGasBrakes = 0.0;
  this->m_RoadSpeedLimit = -1.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_vSteerToPosition.x = UFG::qVector3::msZero.x;
  this->m_vSteerToPosition.y = y;
  this->m_vSteerToPosition.z = z;
  this->m_fSteeringScale = 1.0;
  *(_WORD *)&this->m_FollowDebug = 0;
  *(_QWORD *)&this->m_DesiredOffset = 0i64;
  *(_QWORD *)&this->m_vFollowOffsetActual.x = 0i64;
  this->m_vFollowOffsetActual.z = 0.0;
  v6 = UFG::AiDriverComponent::mCombatCarOffsets[this->m_DesiredOffset].y;
  v7 = UFG::AiDriverComponent::mCombatCarOffsets[this->m_DesiredOffset].z;
  this->m_vFollowOffsetDesired.x = UFG::AiDriverComponent::mCombatCarOffsets[this->m_DesiredOffset].x;
  this->m_vFollowOffsetDesired.y = v6;
  this->m_vFollowOffsetDesired.z = v7;
  *(_QWORD *)&this->m_fFollowOffsetBlend = 0i64;
  *(_QWORD *)&this->m_fFollowDistance = 0i64;
  this->m_fAttackTime = 0.0;
  this->m_iLastHighSpeedCollisionTimestamp = 0i64;
  UFG::qNoise<float,float>::qNoise<float,float>(&this->m_SteeringNoise);
  this->mModeSteeringLockEnabled = 0;
  this->mModeSteeringLock = 0.0;
  this->mModeGasBrakeLockEnabled = 0;
  this->mModeGasBrakeLock = 0.0;
  this->m_bSteeringLock = 0;
  this->m_fSteeringLock = 0.0;
  this->m_bGasBrakeLock = 0;
  *(_QWORD *)&this->m_fGasBrakeLock = 0i64;
  UFG::RingBuffer<UFG::HistoryItem<UFG::qVector2>>::RingBuffer<UFG::HistoryItem<UFG::qVector2>>(
    &this->m_SteeringGasBrakeHistory.mRingBuffer,
    20);
  *(_QWORD *)&this->m_SteeringGasBrakeHistory.fDuration = 0x40000000i64;
  this->m_fAvoidSteerLimit = -1.0;
  *(_QWORD *)&this->m_fAvoidStopTimer = 0i64;
  *(_QWORD *)&this->m_fStuckTimer = 0i64;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  this->m_vStuckPosition.x = UFG::qVector3::msZero.x;
  this->m_vStuckPosition.y = v8;
  this->m_vStuckPosition.z = v9;
  this->m_GettingUnstuckTimer = -1.0;
  this->m_BeenUnstuckTimer = -1.0;
  *(_QWORD *)&this->m_fPassingTimer = 0i64;
  this->m_NumAvoidableOverlaps = 0;
  this->m_CurrentAvoidable.mPrev = &this->m_CurrentAvoidable;
  this->m_CurrentAvoidable.mNext = &this->m_CurrentAvoidable;
  this->m_CurrentAvoidable.m_pPointer = 0i64;
  this->m_BlockedByAvoidable = 0;
  UFG::VehicleCombatStats::VehicleCombatStats(&this->m_CombatStats);
  this->m_EscortInfo.eEscortMode = EscortObjective;
  this->m_EscortInfo.fDistanceSqrEnemyToObjectiveEnterAttackMode = 400.0;
  this->m_EscortInfo.fDistanceSqrEnemyToObjectiveEnterEscortMode = 625.0;
  *(_DWORD *)&this->m_bAvoidPeds = 16842753;
  *(_DWORD *)&this->m_ObeyTrafficLights = 65537;
  *(_WORD *)&this->m_RoadRuleFlagsLocked = 256;
  this->m_AiScriptControlled = 0;
  this->m_TempPassLaneChangeDirectionCode = 0;
  *(_WORD *)&this->m_bIgnoreArrivalDirection = 0;
  this->m_IsAmbient = isAmbient;
  this->m_AmbientDriverType = isAmbient;
  *(_QWORD *)&this->m_fSearchTimer = 0i64;
  this->m_RoadSpeedLimitScale = -1.0;
  this->m_DesiredSpeedLimit = -1.0;
  *(_DWORD *)&this->m_AvoidObjectsEnabled = 16777473;
  this->m_PathingTarget.mPrev = &this->m_PathingTarget;
  this->m_PathingTarget.mNext = &this->m_PathingTarget;
  this->m_PathingTarget.m_pPointer = 0i64;
  this->m_StopAtDist = 20.0;
  this->m_StopAtUseDestinationDirection = 0;
  *(_QWORD *)&this->m_StopInfo.eStopStyle = 0i64;
  *((_BYTE *)&this->m_StopInfo + 8) &= ~1u;
  *(_QWORD *)&this->m_StopDist = 1065353216i64;
  this->m_ResetStopDistOnStop = 1;
  this->m_fChaseSpeedLimit = -1.0;
  this->m_fRaceSpeedLimit = -1.0;
  *(_DWORD *)&this->m_RaceWanderAtEnd = 0;
  this->m_CappingSpeedForNextGuide = 0;
  mPrev = UFG::AiDriverComponent::s_AiDriverComponentList.mNode.mPrev;
  UFG::AiDriverComponent::s_AiDriverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent>;
  this->UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent>::mNext = (UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *)&UFG::AiDriverComponent::s_AiDriverComponentList;
  UFG::AiDriverComponent::s_AiDriverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent>;
  UFG::SimComponent::AddType(this, UFG::AiDriverComponent::_AiDriverComponentTypeUID, "AiDriverComponent");
  aabb.m_min = (hkVector4f)_xmm;
  aabb.m_max = (hkVector4f)_xmm;
  v11 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x18ui64, "SensorPhantom", 0i64, 1u);
  if ( v11 )
    UFG::SensorPhantom::SensorPhantom((UFG::SensorPhantom *)v11, &aabb, 0x18u, "AvoidableSensor");
  else
    v12 = 0i64;
  this->m_AvoidableSensor = v12;
  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_translation = 0i64;
  v13 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v14 = ++*(_BYTE *)(v13 + 80);
  *(_DWORD *)(v13 + 4i64 * v14) = 3;
  *(_QWORD *)(v13 + 8i64 * v14 + 16) = "hkpSphereShape";
  *(_QWORD *)(v13 + 8i64 * v14 + 48) = 0i64;
  v15 = *(_BYTE *)(v13 + 81);
  if ( v14 > v15 )
    v15 = v14;
  *(_BYTE *)(v13 + 81) = v15;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  if ( v17 )
    hkpSphereShape::hkpSphereShape(v17, UFG::AiDriverComponent::m_fAvoidanceCastingRadius);
  else
    v18 = 0i64;
  this->m_pCastingSphere = v18;
  v19 = *(_BYTE *)(v13 + 80);
  if ( v19 > 0 )
  {
    *(_BYTE *)(v13 + 80) = v19 - 1;
  }
  else
  {
    *(_BYTE *)(v13 + 80) = 0;
    *(_DWORD *)v13 = 3;
    *(_QWORD *)(v13 + 16) = 0i64;
    *(_QWORD *)(v13 + 48) = 0i64;
  }
  v20 = ++*(_BYTE *)(v13 + 80);
  *(_DWORD *)(v13 + 4i64 * v20) = 3;
  *(_QWORD *)(v13 + 8i64 * v20 + 16) = "hkpSimpleShapePhantom";
  *(_QWORD *)(v13 + 8i64 * v20 + 48) = 0i64;
  v21 = *(_BYTE *)(v13 + 81);
  if ( v20 > v21 )
    v21 = v20;
  *(_BYTE *)(v13 + 81) = v21;
  v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (hkpSimpleShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v22[11] + 8i64))(v22[11], 448i64);
  if ( v23 )
    hkpSimpleShapePhantom::hkpSimpleShapePhantom(v23, this->m_pCastingSphere, &transform, 0x17u);
  else
    v24 = 0i64;
  this->m_pCastingPhantom = v24;
  v25 = *(_BYTE *)(v13 + 80);
  if ( v25 > 0 )
  {
    *(_BYTE *)(v13 + 80) = v25 - 1;
  }
  else
  {
    *(_BYTE *)(v13 + 80) = 0;
    *(_DWORD *)v13 = 3;
    *(_QWORD *)(v13 + 16) = 0i64;
    *(_QWORD *)(v13 + 48) = 0i64;
  }
  this->m_FacingTargetAngle = 0.52359879;
  this->m_CurrentAttack = NumAttacks;
  *(_QWORD *)&this->m_fSteeringNoiseTimer = 0i64;
  this->m_fSteeringNoiseAmplitudeMin = 0.0;
  UFG::qNoise<float,float>::SetParameters(
    &this->m_SteeringNoise,
    UFG::AiDriverComponent::m_nSteeringNoiseOctaves,
    UFG::AiDriverComponent::m_fSteeringNoiseFrequency,
    UFG::AiDriverComponent::m_fSteeringNoiseOctaveDecay,
    -1.0,
    1.0);
  this->m_DriverProfile = 0i64;
}

// File Line: 818
// RVA: 0x6439E0
void __fastcall UFG::AiDriverComponent::~AiDriverComponent(UFG::AiDriverComponent *this)
{
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *v2; // rdi
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *mPrev; // rcx
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *mNext; // rax
  UFG::SensorPhantom *m_AvoidableSensor; // rcx
  hkpSimpleShapePhantom *m_pCastingPhantom; // rdx
  hkpSimpleShapePhantom *v7; // rcx
  hkpSphereShape *m_pCastingSphere; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_PathingTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_CurrentAvoidable; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_CatchupTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *p_m_pEscortObjectiveVehicleSubject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *p_m_pEscortEnemyVehicleSubject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *p_m_pChaseVehicleSubject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *v39; // rcx
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *v40; // rax

  this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AiDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AiDriverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this->m_DriverProfile )
    this->m_DriverProfile = 0i64;
  if ( this == UFG::AiDriverComponent::s_AiDriverComponentpCurrentIterator )
    UFG::AiDriverComponent::s_AiDriverComponentpCurrentIterator = (UFG::AiDriverComponent *)&this->UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent>::mPrev[-19];
  v2 = &this->UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent>;
  mPrev = this->UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  m_AvoidableSensor = this->m_AvoidableSensor;
  if ( m_AvoidableSensor )
    m_AvoidableSensor->vfptr->__vecDelDtor(m_AvoidableSensor, 1u);
  m_pCastingPhantom = this->m_pCastingPhantom;
  if ( m_pCastingPhantom->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, m_pCastingPhantom, 0);
  v7 = this->m_pCastingPhantom;
  if ( v7 )
    v7->vfptr->__vecDelDtor(v7, 1u);
  m_pCastingSphere = this->m_pCastingSphere;
  if ( m_pCastingSphere )
    m_pCastingSphere->vfptr->__vecDelDtor(m_pCastingSphere, 1u);
  p_m_PathingTarget = &this->m_PathingTarget;
  if ( this->m_PathingTarget.m_pPointer )
  {
    v10 = p_m_PathingTarget->mPrev;
    v11 = this->m_PathingTarget.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    p_m_PathingTarget->mPrev = p_m_PathingTarget;
    this->m_PathingTarget.mNext = &this->m_PathingTarget;
  }
  this->m_PathingTarget.m_pPointer = 0i64;
  v12 = p_m_PathingTarget->mPrev;
  v13 = this->m_PathingTarget.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  p_m_PathingTarget->mPrev = p_m_PathingTarget;
  this->m_PathingTarget.mNext = &this->m_PathingTarget;
  p_m_CurrentAvoidable = &this->m_CurrentAvoidable;
  if ( this->m_CurrentAvoidable.m_pPointer )
  {
    v15 = p_m_CurrentAvoidable->mPrev;
    v16 = this->m_CurrentAvoidable.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    p_m_CurrentAvoidable->mPrev = p_m_CurrentAvoidable;
    this->m_CurrentAvoidable.mNext = &this->m_CurrentAvoidable;
  }
  this->m_CurrentAvoidable.m_pPointer = 0i64;
  v17 = p_m_CurrentAvoidable->mPrev;
  v18 = this->m_CurrentAvoidable.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  p_m_CurrentAvoidable->mPrev = p_m_CurrentAvoidable;
  this->m_CurrentAvoidable.mNext = &this->m_CurrentAvoidable;
  operator delete[](this->m_SteeringGasBrakeHistory.mRingBuffer.mData);
  UFG::qPidControllerCore::~qPidControllerCore(&this->m_CatchupPid);
  p_m_CatchupTarget = &this->m_CatchupTarget;
  if ( this->m_CatchupTarget.m_pPointer )
  {
    v20 = p_m_CatchupTarget->mPrev;
    v21 = this->m_CatchupTarget.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    p_m_CatchupTarget->mPrev = p_m_CatchupTarget;
    this->m_CatchupTarget.mNext = &this->m_CatchupTarget;
  }
  this->m_CatchupTarget.m_pPointer = 0i64;
  v22 = p_m_CatchupTarget->mPrev;
  v23 = this->m_CatchupTarget.mNext;
  v22->mNext = v23;
  v23->mPrev = v22;
  p_m_CatchupTarget->mPrev = p_m_CatchupTarget;
  this->m_CatchupTarget.mNext = &this->m_CatchupTarget;
  UFG::qPidControllerCore::~qPidControllerCore(&this->m_ThrottlePid);
  UFG::qPidControllerCore::~qPidControllerCore(&this->m_SteeringPid);
  p_m_pEscortObjectiveVehicleSubject = &this->m_pEscortObjectiveVehicleSubject;
  if ( this->m_pEscortObjectiveVehicleSubject.m_pPointer )
  {
    v25 = p_m_pEscortObjectiveVehicleSubject->mPrev;
    v26 = this->m_pEscortObjectiveVehicleSubject.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    p_m_pEscortObjectiveVehicleSubject->mPrev = p_m_pEscortObjectiveVehicleSubject;
    this->m_pEscortObjectiveVehicleSubject.mNext = &this->m_pEscortObjectiveVehicleSubject;
  }
  this->m_pEscortObjectiveVehicleSubject.m_pPointer = 0i64;
  v27 = p_m_pEscortObjectiveVehicleSubject->mPrev;
  v28 = this->m_pEscortObjectiveVehicleSubject.mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  p_m_pEscortObjectiveVehicleSubject->mPrev = p_m_pEscortObjectiveVehicleSubject;
  this->m_pEscortObjectiveVehicleSubject.mNext = &this->m_pEscortObjectiveVehicleSubject;
  p_m_pEscortEnemyVehicleSubject = &this->m_pEscortEnemyVehicleSubject;
  if ( this->m_pEscortEnemyVehicleSubject.m_pPointer )
  {
    v30 = p_m_pEscortEnemyVehicleSubject->mPrev;
    v31 = this->m_pEscortEnemyVehicleSubject.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    p_m_pEscortEnemyVehicleSubject->mPrev = p_m_pEscortEnemyVehicleSubject;
    this->m_pEscortEnemyVehicleSubject.mNext = &this->m_pEscortEnemyVehicleSubject;
  }
  this->m_pEscortEnemyVehicleSubject.m_pPointer = 0i64;
  v32 = p_m_pEscortEnemyVehicleSubject->mPrev;
  v33 = this->m_pEscortEnemyVehicleSubject.mNext;
  v32->mNext = v33;
  v33->mPrev = v32;
  p_m_pEscortEnemyVehicleSubject->mPrev = p_m_pEscortEnemyVehicleSubject;
  this->m_pEscortEnemyVehicleSubject.mNext = &this->m_pEscortEnemyVehicleSubject;
  p_m_pChaseVehicleSubject = &this->m_pChaseVehicleSubject;
  if ( this->m_pChaseVehicleSubject.m_pPointer )
  {
    v35 = p_m_pChaseVehicleSubject->mPrev;
    v36 = this->m_pChaseVehicleSubject.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    p_m_pChaseVehicleSubject->mPrev = p_m_pChaseVehicleSubject;
    this->m_pChaseVehicleSubject.mNext = &this->m_pChaseVehicleSubject;
  }
  this->m_pChaseVehicleSubject.m_pPointer = 0i64;
  v37 = p_m_pChaseVehicleSubject->mPrev;
  v38 = this->m_pChaseVehicleSubject.mNext;
  v37->mNext = v38;
  v38->mPrev = v37;
  p_m_pChaseVehicleSubject->mPrev = p_m_pChaseVehicleSubject;
  this->m_pChaseVehicleSubject.mNext = &this->m_pChaseVehicleSubject;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pVehicleSubject);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pRoadSpace);
  v39 = v2->mPrev;
  v40 = v2->mNext;
  v39->mNext = v40;
  v40->mPrev = v39;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::VehicleDriverInterface::~VehicleDriverInterface(this);
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
  UFG::qPropertySet *m_DriverProfile; // rcx

  m_DriverProfile = this->m_DriverProfile;
  if ( m_DriverProfile )
    return UFG::qPropertySet::Get<unsigned long>(
             m_DriverProfile,
             (UFG::qArray<unsigned long,0> *)&qSymbol_DriverProfileType,
             DEPTH_RECURSE);
  else
    return 0i64;
}

// File Line: 859
// RVA: 0x651B70
bool __fastcall UFG::AiDriverComponent::IsInTrafficJam(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rdi
  UFG::RoadNetworkGuide *p_mNext; // rdi
  UFG::RoadNetworkLane *m_NextLane; // rcx
  UFG::RoadNetworkLane *v6; // rdx
  UFG::RoadNetworkGuide *m_pPointer; // rsi
  UFG::RoadNetworkLane *m_CurrentLane; // rbx
  UFG::SimObject *m_SimObj; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfType; // rax
  bool v12; // zf
  UFG::SimObjectGame *v13; // rcx

  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  if ( !m_pSimComponent )
    return 0;
  p_mNext = (UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext;
  if ( !p_mNext )
    return 0;
  if ( !p_mNext->m_Attached )
    return 0;
  m_NextLane = p_mNext->m_NextLane;
  if ( !m_NextLane )
    return 0;
  v6 = m_NextLane->mNode.mOffset ? (UFG::RoadNetworkLane *)((char *)m_NextLane + m_NextLane->mNode.mOffset) : 0i64;
  if ( LOWORD(v6->mNode.mOffset) != 1 || (unsigned int)UFG::RoadNetworkLane::GetStatus(m_NextLane) != 2 )
    return 0;
  m_pPointer = p_mNext->m_NextGuide.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_CurrentLane = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext->m_NextGuide.m_pPointer)->m_CurrentLane;
  if ( m_CurrentLane != Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext)->m_CurrentLane )
    return 0;
  m_SimObj = m_pPointer->m_SimObj;
  if ( !m_SimObj )
    return 0;
  m_Flags = m_SimObj->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    v12 = (m_Flags & 0x1000) == 0;
    v13 = (UFG::SimObjectGame *)m_pPointer->m_SimObj;
    if ( v12 )
      ComponentOfType = UFG::SimObject::GetComponentOfType(v13, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfType = m_SimObj->m_Components.p[34].m_pComponent;
  }
  if ( ComponentOfType && *((float *)&ComponentOfType[10].m_BoundComponentHandles.mNode.mPrev + 1) <= 0.0099999998 )
    return *((float *)&this->mMoverComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1) <= 0.0099999998;
  return 0;
}

// File Line: 901
// RVA: 0x651A50
char __fastcall UFG::AiDriverComponent::IsBlockedByAvoidable(UFG::AiDriverComponent *this, int avoidableSet)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *v6; // rax

  if ( !this->m_BlockedByAvoidable )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)this->m_CurrentAvoidable.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[37].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CameraSubject::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CameraSubject::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[31].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  if ( avoidableSet == 1 )
  {
    if ( ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[30].__vecDelDtor)(m_pComponent) )
      return 0;
  }
  else if ( avoidableSet )
  {
    return 0;
  }
  return 1;
}

// File Line: 934
// RVA: 0x658C90
void __fastcall UFG::AiDriverComponent::SetDrivingRole(UFG::AiDriverComponent *this, unsigned int role)
{
  bool m_bAvoidPeds; // al

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
        m_bAvoidPeds = this->m_bAvoidPeds;
        this->m_bAllowedToPass = 1;
        this->m_bStayOffSidewalk = 1;
        this->m_bRespectSpeedLimit = 0;
        this->m_bCanTurnAround = 1;
        this->m_bSavedAvoidPeds = m_bAvoidPeds;
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
        if ( this->m_RoadRuleFlagsLocked )
          goto LABEL_20;
        this->m_bAllowedToPass = 0;
LABEL_18:
        this->m_bAvoidPeds = 1;
        this->m_bStayOffSidewalk = 1;
LABEL_19:
        this->m_bRespectSpeedLimit = 1;
        this->m_bCanTurnAround = 0;
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
  UFG::RoadSpaceComponent *m_pSimComponent; // rax

  if ( this->m_DrivingMode != mode )
  {
    this->m_DrivingMode = mode;
    this->m_fReactionTime = 0.0;
    this->m_fDelayedStopDecel = 0.0;
    this->mModeSteeringLockEnabled = 0;
    this->mModeGasBrakeLockEnabled = 0;
    this->m_bIgnoreArrivalDirection = 0;
    switch ( mode )
    {
      case 0u:
        if ( this->m_ResetStopDistOnStop )
          this->m_StopDist = 1.0;
        break;
      case 1u:
      case 6u:
        return;
      case 2u:
        m_pSimComponent = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
        if ( !m_pSimComponent
          || (float)((float)((float)(m_pSimComponent->mDestinationDirection.x * m_pSimComponent->mDestinationDirection.x)
                           + (float)(m_pSimComponent->mDestinationDirection.y * m_pSimComponent->mDestinationDirection.y))
                   + (float)(m_pSimComponent->mDestinationDirection.z * m_pSimComponent->mDestinationDirection.z)) < 0.0000010000001 )
        {
          goto $LN7_67;
        }
        break;
      case 3u:
        this->m_bIgnoreArrivalDirection = 1;
        goto $LN2_63;
      case 4u:
$LN7_67:
        this->m_bIgnoreArrivalDirection = 1;
        break;
      case 5u:
        UFG::AiDriverComponent::SetupStopAt(this);
        break;
      case 7u:
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
  bool v2; // zf

  if ( this->m_StopInfo.eStopStyle == EStopStyle_Powerslide )
    UFG::VehicleDriverInterface::SetDesiredState(this, (UFG::VehicleState)3);
  if ( this->m_DrivingRole - 6 <= 2 )
  {
    v2 = !this->m_RoadRuleFlagsLocked;
    this->m_bSavedAvoidPeds = this->m_bAvoidPeds;
    if ( v2 )
    {
      this->m_bAvoidPeds = 0;
      this->m_fAvoidStopTimer = 0.0;
    }
  }
}

// File Line: 1105
// RVA: 0x6587A0
void __fastcall UFG::AiDriverComponent::SetChaseTarget(UFG::AiDriverComponent *this, UFG::SimObjectVehicle *target)
{
  UFG::RoadSpaceComponent *m_pSimComponent; // rcx
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimComponent *v6; // r8
  signed __int16 m_Flags; // cx
  UFG::VehicleSubjectComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *p_m_pChaseVehicleSubject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax

  m_pSimComponent = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::RoadSpaceComponent::SetChaseTarget(m_pSimComponent, target);
  m_pPointer = this->m_pChaseVehicleSubject.m_pPointer;
  if ( !m_pPointer || m_pPointer->m_pSimObject != target )
  {
    if ( !target )
    {
      v6 = 0i64;
LABEL_16:
      p_m_pChaseVehicleSubject = &this->m_pChaseVehicleSubject;
      if ( this->m_pChaseVehicleSubject.m_pPointer )
      {
        mPrev = p_m_pChaseVehicleSubject->mPrev;
        mNext = this->m_pChaseVehicleSubject.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_m_pChaseVehicleSubject->mPrev = p_m_pChaseVehicleSubject;
        this->m_pChaseVehicleSubject.mNext = &this->m_pChaseVehicleSubject;
      }
      this->m_pChaseVehicleSubject.m_pPointer = v6;
      if ( v6 )
      {
        v12 = v6->m_SafePointerList.mNode.mPrev;
        v12->mNext = p_m_pChaseVehicleSubject;
        p_m_pChaseVehicleSubject->mPrev = v12;
        this->m_pChaseVehicleSubject.mNext = &v6->m_SafePointerList.mNode;
        v6->m_SafePointerList.mNode.mPrev = p_m_pChaseVehicleSubject;
      }
      this->m_fReactionTime = 0.0;
      return;
    }
    m_Flags = target->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags < 0 )
      {
        ComponentOfType = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(target);
LABEL_15:
        v6 = ComponentOfType;
        goto LABEL_16;
      }
      if ( (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0 )
      {
        ComponentOfType = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                            target,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
        goto LABEL_15;
      }
    }
    ComponentOfType = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        target,
                                                        UFG::VehicleSubjectComponent::_TypeUID);
    goto LABEL_15;
  }
}

// File Line: 1117
// RVA: 0x659040
void __fastcall UFG::AiDriverComponent::SetEscortEnemy(UFG::AiDriverComponent *this, UFG::SimObjectVehicle *enemy)
{
  UFG::SimComponent *v2; // r8
  signed __int16 m_Flags; // cx
  UFG::VehicleSubjectComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *p_m_pEscortEnemyVehicleSubject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = (UFG::SimComponent *)enemy;
  if ( enemy )
  {
    m_Flags = enemy->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags < 0 )
      {
        ComponentOfType = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(enemy);
        goto LABEL_10;
      }
      if ( (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0 )
      {
        ComponentOfType = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                            enemy,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
        goto LABEL_10;
      }
    }
    ComponentOfType = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        enemy,
                                                        UFG::VehicleSubjectComponent::_TypeUID);
LABEL_10:
    v2 = ComponentOfType;
  }
  p_m_pEscortEnemyVehicleSubject = &this->m_pEscortEnemyVehicleSubject;
  if ( this->m_pEscortEnemyVehicleSubject.m_pPointer )
  {
    mPrev = p_m_pEscortEnemyVehicleSubject->mPrev;
    mNext = this->m_pEscortEnemyVehicleSubject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pEscortEnemyVehicleSubject->mPrev = p_m_pEscortEnemyVehicleSubject;
    this->m_pEscortEnemyVehicleSubject.mNext = &this->m_pEscortEnemyVehicleSubject;
  }
  this->m_pEscortEnemyVehicleSubject.m_pPointer = v2;
  this->m_fReactionTime = 0.0;
  if ( v2 )
  {
    v9 = v2->m_SafePointerList.mNode.mPrev;
    v9->mNext = p_m_pEscortEnemyVehicleSubject;
    p_m_pEscortEnemyVehicleSubject->mPrev = v9;
    this->m_pEscortEnemyVehicleSubject.mNext = &v2->m_SafePointerList.mNode;
    v2->m_SafePointerList.mNode.mPrev = p_m_pEscortEnemyVehicleSubject;
  }
}

// File Line: 1123
// RVA: 0x64E740
UFG::qBaseNodeRB *__fastcall UFG::AiDriverComponent::GetEscortEnemy(UFG::AiDriverComponent *this)
{
  UFG::qBaseNodeRB *result; // rax

  result = (UFG::qBaseNodeRB *)this->m_pEscortEnemyVehicleSubject.m_pPointer;
  if ( result )
    return result[1].mChild[0];
  return result;
}

// File Line: 1132
// RVA: 0x659110
void __fastcall UFG::AiDriverComponent::SetEscortObjective(UFG::AiDriverComponent *this, UFG::SimObjectVehicle *enemy)
{
  UFG::SimComponent *v2; // r8
  signed __int16 m_Flags; // cx
  UFG::VehicleSubjectComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::VehicleSubjectComponent> *p_m_pEscortObjectiveVehicleSubject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = (UFG::SimComponent *)enemy;
  if ( enemy )
  {
    m_Flags = enemy->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags < 0 )
      {
        ComponentOfType = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(enemy);
        goto LABEL_10;
      }
      if ( (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0 )
      {
        ComponentOfType = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                            enemy,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
        goto LABEL_10;
      }
    }
    ComponentOfType = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        enemy,
                                                        UFG::VehicleSubjectComponent::_TypeUID);
LABEL_10:
    v2 = ComponentOfType;
  }
  p_m_pEscortObjectiveVehicleSubject = &this->m_pEscortObjectiveVehicleSubject;
  if ( this->m_pEscortObjectiveVehicleSubject.m_pPointer )
  {
    mPrev = p_m_pEscortObjectiveVehicleSubject->mPrev;
    mNext = this->m_pEscortObjectiveVehicleSubject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pEscortObjectiveVehicleSubject->mPrev = p_m_pEscortObjectiveVehicleSubject;
    this->m_pEscortObjectiveVehicleSubject.mNext = &this->m_pEscortObjectiveVehicleSubject;
  }
  this->m_pEscortObjectiveVehicleSubject.m_pPointer = v2;
  this->m_fReactionTime = 0.0;
  if ( v2 )
  {
    v9 = v2->m_SafePointerList.mNode.mPrev;
    v9->mNext = p_m_pEscortObjectiveVehicleSubject;
    p_m_pEscortObjectiveVehicleSubject->mPrev = v9;
    this->m_pEscortObjectiveVehicleSubject.mNext = &v2->m_SafePointerList.mNode;
    v2->m_SafePointerList.mNode.mPrev = p_m_pEscortObjectiveVehicleSubject;
  }
}

// File Line: 1145
// RVA: 0x662000
void __fastcall UFG::AiDriverComponent::UpdateEscortOffset(UFG::AiDriverComponent *this, float seconds)
{
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qVector3 *v8; // rax
  UFG::qVector3 *v9; // rax
  __m128 x_low; // xmm4
  float y; // xmm2_4
  __m128 v12; // xmm3
  float v13; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  if ( this->m_EscortInfo.eEscortMode == EscortObjective && !this->m_bCreepingTowardEscortEnemy )
  {
    m_pPointer = this->m_pChaseVehicleSubject.m_pPointer;
    if ( m_pPointer )
    {
      if ( this->m_pEscortEnemyVehicleSubject.m_pPointer )
      {
        m_pSimObject = (UFG::SimObjectGame *)m_pPointer->m_pSimObject;
        if ( m_pSimObject )
        {
          m_Flags = m_pSimObject->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = (UFG::RoadSpaceComponent *)m_pSimObject->m_Components.p[24].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    m_pSimObject,
                                    UFG::RoadSpaceComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::RoadSpaceComponent::_TypeUID);
            m_pComponent = (UFG::RoadSpaceComponent *)ComponentOfTypeHK;
          }
          else
          {
            m_pComponent = (UFG::RoadSpaceComponent *)m_pSimObject->m_Components.p[24].m_pComponent;
          }
          if ( m_pComponent )
          {
            v8 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pEscortEnemyVehicleSubject.m_pPointer->vfptr[17].__vecDelDtor)(this->m_pEscortEnemyVehicleSubject.m_pPointer);
            v9 = UFG::RoadSpaceComponent::WorldToChase(m_pComponent, &result, v8);
            x_low = (__m128)LODWORD(v9->x);
            y = v9->y;
            v12 = x_low;
            v12.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y))
                            + (float)(v9->z * v9->z);
            v13 = _mm_sqrt_ps(v12).m128_f32[0];
            UFG::AiDriverComponent::SetFollowOffset(
              this,
              (float)(x_low.m128_f32[0] * (float)(8.0 / v13)) * 0.5,
              y * (float)(8.0 / v13),
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
  UFG::SimObjectVehicle *m_pPointer; // rsi
  UFG::SimObjectGame *mParent; // rdi
  CarAI::EEscortMode eEscortMode; // ecx
  float v6; // xmm7_4
  float fDistanceSqrEnemyToObjectiveEnterAttackMode; // xmm0_4
  __int16 m_Flags; // cx
  UFG::RoadSpaceComponent *m_pComponent; // rax
  float v10; // xmm8_4
  float z; // xmm6_4
  float x; // xmm9_4
  float y; // xmm10_4
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  __m128 y_low; // xmm7
  __m128 v18; // xmm3
  float v19; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-98h] BYREF
  UFG::qVector3 v21; // [rsp+30h] [rbp-88h] BYREF
  UFG::qVector3 v22; // [rsp+40h] [rbp-78h] BYREF
  UFG::qVector3 v23; // [rsp+50h] [rbp-68h] BYREF

  m_pPointer = (UFG::SimObjectVehicle *)this->m_pEscortEnemyVehicleSubject.m_pPointer;
  if ( m_pPointer )
    m_pPointer = (UFG::SimObjectVehicle *)m_pPointer->mNode.mParent;
  UFG::GetPosition(&result, m_pPointer);
  mParent = (UFG::SimObjectGame *)this->m_pEscortObjectiveVehicleSubject.m_pPointer;
  if ( mParent )
    mParent = (UFG::SimObjectGame *)mParent->mNode.mParent;
  UFG::GetPosition(&v21, mParent);
  UFG::GetPosition(&v22, (UFG::SimObjectGame *)this->m_pSimObject);
  eEscortMode = this->m_EscortInfo.eEscortMode;
  this->m_bCreepingTowardEscortEnemy = 0;
  v6 = (float)((float)((float)(v22.y - result.y) * (float)(v22.y - result.y))
             + (float)((float)(v22.x - result.x) * (float)(v22.x - result.x)))
     + (float)((float)(v22.z - result.z) * (float)(v22.z - result.z));
  if ( eEscortMode == EscortObjective )
  {
    if ( v6 >= 100.0 )
    {
      fDistanceSqrEnemyToObjectiveEnterAttackMode = this->m_EscortInfo.fDistanceSqrEnemyToObjectiveEnterAttackMode;
      if ( ((float)((float)((float)((float)(v21.y - result.y) * (float)(v21.y - result.y))
                          + (float)((float)(v21.x - result.x) * (float)(v21.x - result.x)))
                  + (float)((float)(v21.z - result.z) * (float)(v21.z - result.z))) <= fDistanceSqrEnemyToObjectiveEnterAttackMode
         || v6 <= fDistanceSqrEnemyToObjectiveEnterAttackMode)
        && mParent )
      {
        m_Flags = mParent->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::RoadSpaceComponent *)mParent->m_Components.p[24].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            m_pComponent = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        mParent,
                                                        UFG::RoadSpaceComponent::_TypeUID);
          else
            m_pComponent = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                        mParent,
                                                        UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::RoadSpaceComponent *)mParent->m_Components.p[24].m_pComponent;
        }
        if ( m_pComponent )
        {
          v10 = seconds * 10.0;
          z = this->m_vFollowOffsetDesired.z;
          x = this->m_vFollowOffsetDesired.x;
          y = this->m_vFollowOffsetDesired.y;
          UFG::RoadSpaceComponent::WorldToChase(m_pComponent, &v23, &result);
          v14 = v23.x;
          v15 = v23.y;
          y_low = (__m128)LODWORD(v23.y);
          v16 = v23.x - x;
          y_low.m128_f32[0] = v23.y - y;
          v18 = y_low;
          v18.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v16 * v16))
                          + (float)((float)(v23.z - z) * (float)(v23.z - z));
          if ( v18.m128_f32[0] > (float)(v10 * v10) )
          {
            v19 = _mm_sqrt_ps(v18).m128_f32[0];
            v15 = (float)((float)(v10 / v19) * y_low.m128_f32[0]) + y;
            v14 = (float)((float)(v10 / v19) * v16) + x;
          }
          UFG::AiDriverComponent::SetFollowOffset(this, v14, v15, 5.0);
          this->m_bCreepingTowardEscortEnemy = 1;
        }
      }
    }
    else
    {
      this->m_EscortInfo.eEscortMode = AttackEnemy;
      UFG::VehicleCombatStats::Reset(&this->m_CombatStats);
      UFG::AiDriverComponent::SetChaseTarget(this, m_pPointer);
    }
  }
}

// File Line: 1485
// RVA: 0x665EB0
char __fastcall UFG::AiDriverComponent::WarpToDestination(UFG::AiDriverComponent *this)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  UFG::RoadNetworkSegment *ClosestSegment; // rdi
  UFG::RoadNetworkSubSegment *ClosestSubSegment; // rsi
  UFG::RoadNetworkSubSegment *mNext; // rbx
  bool IsReversedInNode; // al
  unsigned int mLaneIndex; // edx
  float EndT; // xmm0_4
  float v11; // xmm6_4
  float TFromDistance; // xmm0_4
  UFG::WheeledVehicleManager *v13; // rbx
  UFG::RoadNetworkLane *v14; // rax
  UFG::RoadSpaceComponent *m_pSimComponent; // rbx
  UFG::RoadNetworkLocation *Name; // rax
  UFG::qVector3 v17; // [rsp+30h] [rbp-19h] BYREF
  UFG::qVector3 pos; // [rsp+40h] [rbp-9h] BYREF
  UFG::qVector3 v19; // [rsp+50h] [rbp+7h] BYREF
  UFG::qVector3 result; // [rsp+60h] [rbp+17h] BYREF
  float nearestT; // [rsp+B0h] [rbp+67h] BYREF
  UFG::RoadNetworkLane *nearestLane; // [rsp+B8h] [rbp+6Fh] BYREF

  this->m_fAvoidStopTimer = 0.0;
  v2 = *((float *)&this->m_pRoadSpace.m_pSimComponent[25].m_BoundComponentHandles.mNode.mPrev + 1);
  v3 = *(float *)&this->m_pRoadSpace.m_pSimComponent[25].m_BoundComponentHandles.mNode.mNext;
  pos.x = *(float *)&this->m_pRoadSpace.m_pSimComponent[25].m_BoundComponentHandles.mNode.mPrev;
  pos.y = v2;
  pos.z = v3;
  if ( pos.x == UFG::qVector3::msZero.x && v2 == UFG::qVector3::msZero.y && v3 == UFG::qVector3::msZero.z )
    return 0;
  ClosestSegment = UFG::RoadNetworkResource::GetClosestSegment(UFG::gpRoadNetworkResource, &pos, 0i64, 0);
  nearestLane = 0i64;
  nearestT = 0.0;
  UFG::RoadNetworkNode::GetNearestPos(ClosestSegment, &result, &pos, &nearestLane, &nearestT);
  ClosestSubSegment = UFG::RoadNetworkSegment::GetClosestSubSegment(ClosestSegment, &pos);
  if ( UFG::RoadNetworkLane::IsReversedInNode(nearestLane) )
    mNext = (UFG::RoadNetworkSubSegment *)ClosestSubSegment->mNext;
  else
    mNext = (UFG::RoadNetworkSubSegment *)ClosestSubSegment->mPrev;
  if ( !mNext || mNext == (UFG::RoadNetworkSubSegment *)&ClosestSegment->mSubSegmentCollection )
    mNext = ClosestSubSegment;
  IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(nearestLane);
  mLaneIndex = nearestLane->mLaneIndex;
  if ( IsReversedInNode )
    EndT = UFG::RoadNetworkSubSegment::GetEndT(mNext, mLaneIndex);
  else
    EndT = UFG::RoadNetworkSubSegment::GetBeginT(mNext, mLaneIndex);
  v11 = EndT;
  if ( EndT == 0.0 )
  {
    TFromDistance = UFG::RoadNetworkSegment::GetTFromDistance(ClosestSegment, nearestLane, 2.5, 0.0, 1);
LABEL_18:
    v11 = TFromDistance;
    goto LABEL_19;
  }
  if ( EndT == 1.0 )
  {
    TFromDistance = UFG::RoadNetworkSegment::GetTFromDistance(ClosestSegment, nearestLane, 2.5, EndT, 0);
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
  this->m_IsAmbient = 0;
  UFG::RoadNetworkGuide::AttachToNetwork(
    (UFG::RoadNetworkGuide *)&this->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext,
    this->m_pRoadSpace.m_pSimComponent->m_pSimObject,
    ClosestSegment,
    v14->mLaneIndex,
    v11);
  UFG::RoadNetworkGuide::RemoveFromNetwork((UFG::RoadNetworkGuide *)&this->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext);
  m_pSimComponent = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
  Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(&m_pSimComponent->mGuide);
  UFG::RoadSpaceComponent::MoveCarToRoadNetworkPosition(m_pSimComponent, Name, 0);
  return 1;
}

// File Line: 1565
// RVA: 0x666130
void __fastcall UFG::AiDriverComponent::WarpToGotoDestination(UFG::AiDriverComponent *this)
{
  float *m_pSimComponent; // r15
  UFG::qVector3 *v2; // r14
  UFG::VehicleWayFinderClient *v4; // r15
  UFG::SimComponent *v5; // r12
  UFG::WheeledVehicleNavigationData *m_NavigationData; // rsi
  unsigned int m_RoadNetworkType; // eax
  UFG::WayFinderClientVtbl *vfptr; // rdi
  __int64 v9; // rbx
  __int64 v10; // rax
  UFG::WayFinder *RoadWayFinder; // rbx
  unsigned int m_NumWayEdges; // r13d
  UFG::SimComponent *v13; // r12
  __int64 v14; // rbx
  UFG::RoadNetworkSegment *Segment; // rdi
  UFG::RoadNetworkSubSegment *ClosestSubSegment; // r14
  UFG::RoadNetworkLane *LaneAtEdgeNum; // rsi
  UFG::RoadNetworkSubSegment *mNext; // rbx
  bool IsReversedInNode; // al
  unsigned int mLaneIndex; // edx
  float EndT; // xmm0_4
  float TFromDistance; // xmm0_4
  float BeginT; // xmm0_4
  UFG::RoadSpaceComponent *v24; // rbx
  UFG::RoadNetworkLocation *Name; // rax

  this->m_fAvoidStopTimer = 0.0;
  m_pSimComponent = (float *)this->m_pRoadSpace.m_pSimComponent;
  v2 = (UFG::qVector3 *)(m_pSimComponent + 412);
  if ( UFG::qVector3::msZero.x != m_pSimComponent[412]
    || UFG::qVector3::msZero.y != m_pSimComponent[413]
    || UFG::qVector3::msZero.z != m_pSimComponent[414] )
  {
    v4 = (UFG::VehicleWayFinderClient *)(m_pSimComponent + 138);
    if ( v4 )
    {
      v5 = this->m_pVehicleSubject.m_pSimComponent;
      if ( v5 )
      {
        m_NavigationData = UFG::WheeledVehicleManager::m_Instance->m_NavigationData;
        m_RoadNetworkType = v4->m_RoadNetworkType;
        if ( m_RoadNetworkType )
        {
          switch ( m_RoadNetworkType )
          {
            case 1u:
              m_NavigationData = (UFG::WheeledVehicleNavigationData *)((char *)m_NavigationData + 64);
              break;
            case 2u:
              m_NavigationData = (UFG::WheeledVehicleNavigationData *)((char *)m_NavigationData + 96);
              break;
            case 3u:
              m_NavigationData = (UFG::WheeledVehicleNavigationData *)((char *)m_NavigationData + 128);
              break;
          }
        }
        else
        {
          m_NavigationData = (UFG::WheeledVehicleNavigationData *)((char *)m_NavigationData + 32);
        }
        if ( m_NavigationData )
        {
          vfptr = v4->vfptr;
          v9 = ((__int64 (__fastcall *)(UFG::SimComponent *))v5->vfptr[16].__vecDelDtor)(v5);
          v10 = ((__int64 (__fastcall *)(UFG::SimComponent *))v5->vfptr[17].__vecDelDtor)(v5);
          vfptr->SetPosition(v4, &m_NavigationData->m_RoadNetworkGraph, (UFG::qVector3 *)v10, (UFG::qVector3 *)v9);
          RoadWayFinder = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
                            UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                            v4);
          UFG::WayFinder::FindWay(RoadWayFinder, v4, v2, 0i64);
          UFG::WayFinder::Service(RoadWayFinder, 0.0);
          m_NumWayEdges = v4->m_NumWayEdges;
          if ( v4->m_NumWayEdges )
          {
            v13 = this->m_pRoadSpace.m_pSimComponent;
            v14 = m_NumWayEdges - 1;
            Segment = UFG::RoadNetworkResource::GetSegment(UFG::gpRoadNetworkResource, v4->m_WayEdges[v14]);
            ClosestSubSegment = UFG::RoadNetworkSegment::GetClosestSubSegment(Segment, v2);
            LaneAtEdgeNum = UFG::AiDriverComponent::GetLaneAtEdgeNum(this, v14);
            if ( UFG::RoadNetworkLane::IsReversedInNode(LaneAtEdgeNum) )
              mNext = (UFG::RoadNetworkSubSegment *)ClosestSubSegment->mNext;
            else
              mNext = (UFG::RoadNetworkSubSegment *)ClosestSubSegment->mPrev;
            if ( &Segment->mSubSegmentCollection == (UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *)mNext )
            {
              if ( m_NumWayEdges < 2 )
                return;
              Segment = UFG::RoadNetworkResource::GetSegment(
                          UFG::gpRoadNetworkResource,
                          *((unsigned __int16 *)&v4->m_CurrDir.z + m_NumWayEdges + 1));
              if ( UFG::RoadNetworkLane::IsReversedInNode(LaneAtEdgeNum) )
                mNext = (UFG::RoadNetworkSubSegment *)Segment->mSubSegmentCollection.mNode.mNext;
              else
                mNext = (UFG::RoadNetworkSubSegment *)Segment->mSubSegmentCollection.mNode.mPrev;
            }
            UFG::WheeledVehicleManager::DestroyTrafficVehiclesOnSubSegment(
              UFG::WheeledVehicleManager::m_Instance,
              mNext,
              1,
              LaneAtEdgeNum);
            UFG::WheeledVehicleManager::DestroyParkedCarsOnSubSegment(UFG::WheeledVehicleManager::m_Instance, mNext);
            IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(LaneAtEdgeNum);
            mLaneIndex = LaneAtEdgeNum->mLaneIndex;
            if ( IsReversedInNode )
            {
              EndT = UFG::RoadNetworkSubSegment::GetEndT(mNext, mLaneIndex);
              TFromDistance = UFG::RoadNetworkSegment::GetTFromDistance(Segment, LaneAtEdgeNum, 3.0, EndT, 0);
            }
            else
            {
              BeginT = UFG::RoadNetworkSubSegment::GetBeginT(mNext, mLaneIndex);
              TFromDistance = UFG::RoadNetworkSegment::GetTFromDistance(Segment, LaneAtEdgeNum, 3.0, BeginT, 1);
            }
            this->m_IsAmbient = 0;
            UFG::RoadNetworkGuide::AttachToNetwork(
              (UFG::RoadNetworkGuide *)&this->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext,
              this->m_pRoadSpace.m_pSimComponent->m_pSimObject,
              Segment,
              LaneAtEdgeNum->mLaneIndex,
              TFromDistance);
            UFG::RoadNetworkGuide::RemoveFromNetwork((UFG::RoadNetworkGuide *)&this->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext);
            v24 = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
            Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v13[5].m_BoundComponentHandles.mNode.mNext);
            UFG::RoadSpaceComponent::MoveCarToRoadNetworkPosition(v24, Name, 0);
          }
        }
      }
    }
  }
}

// File Line: 1676
// RVA: 0x64C030
void __fastcall UFG::AiDriverComponent::EmergencyFixupForGround(
        UFG::AiDriverComponent *this,
        UFG::qMatrix44 *local_world)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::RoadNetworkLocation *Name; // rbx
  float z; // xmm7_4
  float y; // xmm8_4
  float v7; // xmm11_4
  float v8; // xmm2_4
  float v9; // xmm12_4
  float x; // xmm9_4
  float v11; // xmm3_4
  __m128 x_low; // xmm4
  float v13; // xmm5_4
  __m128 v14; // xmm6
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rbx
  UFG::RacePoint *v19; // rbx
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm8_4
  float v23; // xmm9_4
  float v24; // xmm1_4
  float v25; // xmm4_4
  __m128 v26; // xmm5
  float v27; // xmm3_4
  float v28; // xmm2_4
  __m128 v29; // xmm6
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::SimComponent *m_pComponent; // rbp
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int mNext_high; // r15d
  float v40; // xmm13_4
  float v41; // xmm14_4
  float v42; // xmm15_4
  float v43; // xmm6_4
  int v44; // ebx
  float *v45; // r14
  float v46; // xmm8_4
  float v47; // xmm7_4
  int v48; // eax
  int v49; // ecx
  int v50; // eax
  float *v51; // rcx
  float v52; // xmm9_4
  float v53; // xmm10_4
  float v54; // xmm11_4
  float v55; // xmm12_4
  float v56; // xmm4_4
  float v57; // xmm5_4
  float v58; // xmm2_4
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // xmm11_4
  float v62; // xmm12_4
  float v63; // xmm7_4
  float v64; // xmm9_4
  float v65; // xmm10_4
  float v66; // xmm4_4
  float v67; // xmm3_4
  __m128 v68; // xmm5
  __m128 v69; // xmm2
  float v70; // xmm1_4
  float v71; // xmm2_4
  UFG::qVector3 v72; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qVector3 result; // [rsp+30h] [rbp-C8h] BYREF

  if ( this->m_pRoadSpace.m_pSimComponent )
  {
    m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
    if ( LOBYTE(m_pSimComponent[8].m_Flags) )
    {
      Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext);
      UFG::RoadNetworkLocation::GetPos(Name, &result);
      UFG::RoadNetworkLocation::GetTangent(Name, &v72);
      z = v72.z;
      y = v72.y;
      v7 = UFG::qVector3::msAxisZ.y;
      v8 = 0.0;
      v9 = UFG::qVector3::msAxisZ.z;
      x = v72.x;
      x_low = (__m128)LODWORD(v72.x);
      v11 = (float)(v72.z * UFG::qVector3::msAxisZ.y) - (float)(v72.y * UFG::qVector3::msAxisZ.z);
      x_low.m128_f32[0] = (float)(v72.x * UFG::qVector3::msAxisZ.z) - (float)(v72.z * UFG::qVector3::msAxisZ.x);
      v14 = x_low;
      v13 = (float)(v72.y * UFG::qVector3::msAxisZ.x) - (float)(v72.x * UFG::qVector3::msAxisZ.y);
      v14.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v11 * v11))
                      + (float)(v13 * v13);
      if ( v14.m128_f32[0] != 0.0 )
        v8 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
      v15 = result.x;
      v16 = result.y;
      local_world->v2.x = UFG::qVector3::msAxisZ.x;
      local_world->v2.w = 0.0;
      local_world->v2.y = v7;
      local_world->v2.z = v9;
      local_world->v1.x = v11 * v8;
      local_world->v1.w = 0.0;
      local_world->v1.y = x_low.m128_f32[0] * v8;
      local_world->v1.z = v13 * v8;
      local_world->v0.x = x;
      local_world->v0.w = 0.0;
      local_world->v0.y = y;
      local_world->v0.z = z;
      local_world->v3.x = v15;
      local_world->v3.w = 1.0;
      v17 = result.z;
      local_world->v3.y = v16;
      local_world->v3.z = v17;
    }
    else
    {
      mNext = m_pSimComponent[26].m_SafePointerList.mNode.mNext;
      if ( !mNext )
        mNext = m_pSimComponent[26].m_SafePointerList.mNode.mPrev;
      if ( mNext )
        v19 = (UFG::RacePoint *)mNext[1].mNext;
      else
        v19 = 0i64;
      if ( v19 )
      {
        v20 = local_world->v3.y;
        result.x = local_world->v3.x;
        v21 = local_world->v3.z;
        result.y = v20;
        result.z = v21;
        UFG::RacePoint::GetSegmentPosition(v19, &v72, &result);
        v22 = UFG::qVector3::msAxisZ.y;
        v23 = UFG::qVector3::msAxisZ.z;
        v26 = (__m128)LODWORD(v19->vDirection.x);
        v24 = v26.m128_f32[0] * UFG::qVector3::msAxisZ.y;
        v25 = (float)(v19->vDirection.z * UFG::qVector3::msAxisZ.y)
            - (float)(v19->vDirection.y * UFG::qVector3::msAxisZ.z);
        v26.m128_f32[0] = (float)(v26.m128_f32[0] * UFG::qVector3::msAxisZ.z)
                        - (float)(v19->vDirection.z * UFG::qVector3::msAxisZ.x);
        v27 = (float)(v19->vDirection.y * UFG::qVector3::msAxisZ.x) - v24;
        v28 = 0.0;
        v29 = v26;
        v29.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v27 * v27);
        if ( v29.m128_f32[0] != 0.0 )
          v28 = 1.0 / _mm_sqrt_ps(v29).m128_f32[0];
        local_world->v2.x = UFG::qVector3::msAxisZ.x;
        local_world->v2.y = v22;
        local_world->v2.z = v23;
        local_world->v2.w = 0.0;
        local_world->v1.w = 0.0;
        local_world->v1.x = v25 * v28;
        local_world->v1.y = v26.m128_f32[0] * v28;
        local_world->v1.z = v27 * v28;
        v30 = v19->vDirection.y;
        v31 = v19->vDirection.z;
        local_world->v0.x = v19->vDirection.x;
        local_world->v0.w = 0.0;
        v32 = v72.x;
        local_world->v0.y = v30;
        v33 = v72.y;
        local_world->v0.z = v31;
        local_world->v3.x = v32;
        v34 = v72.z;
        local_world->v3.w = 1.0;
        local_world->v3.z = v34;
        local_world->v3.y = v33;
      }
      else
      {
        m_pSimObject = (UFG::SimObjectGame *)m_pSimComponent[26].m_pSimObject;
        if ( m_pSimObject )
        {
          m_Flags = m_pSimObject->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = m_pSimObject->m_Components.p[24].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    m_pSimObject,
                                    UFG::RoadSpaceComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::RoadSpaceComponent::_TypeUID);
            m_pComponent = ComponentOfTypeHK;
          }
          else
          {
            m_pComponent = m_pSimObject->m_Components.p[24].m_pComponent;
          }
        }
        else
        {
          m_pComponent = 0i64;
        }
        if ( m_pComponent )
        {
          mNext_high = HIDWORD(m_pComponent[29].m_BoundComponentHandles.mNode.mNext);
          v40 = local_world->v3.x;
          v41 = local_world->v3.y;
          v42 = local_world->v3.z;
          if ( mNext_high > 0 )
          {
            v43 = 0.0;
            v44 = 0;
            v45 = 0i64;
            v46 = 0.0;
            v47 = 0.0;
            do
            {
              v48 = HIDWORD(m_pComponent[29].m_BoundComponentHandles.mNode.mNext);
              v49 = 0;
              if ( v44 > 0 )
                v49 = v44;
              if ( v49 < v48 )
                v48 = v49;
              v50 = UFG::qSignedMod(
                      LODWORD(m_pComponent[29].m_BoundComponentHandles.mNode.mNext) - v48,
                      (int)m_pComponent[30].vfptr);
              v51 = (float *)&m_pComponent[30].m_SafePointerList.mNode.mPrev[2 * v50];
              v53 = v51[1];
              v54 = v51[2];
              v55 = v51[5];
              v56 = v51[4];
              v57 = v51[6];
              v58 = (float)((float)((float)(v40 - *v51) * v56) + (float)((float)(v41 - v53) * v55))
                  + (float)((float)(v42 - v54) * v57);
              if ( v58 <= 0.0 )
                v58 = 0.0;
              if ( v58 >= v51[3] )
                v58 = v51[3];
              v52 = *v51;
              if ( !v44
                || (float)((float)((float)((float)(v41 - (float)((float)(v58 * v55) + v53))
                                         * (float)(v41 - (float)((float)(v58 * v55) + v53)))
                                 + (float)((float)(v40 - (float)((float)(v56 * v58) + v52))
                                         * (float)(v40 - (float)((float)(v56 * v58) + v52))))
                         + (float)((float)(v42 - (float)((float)(v57 * v58) + v54))
                                 * (float)(v42 - (float)((float)(v57 * v58) + v54)))) < v47 )
              {
                v47 = (float)((float)((float)(v41 - (float)((float)(v58 * v55) + v53))
                                    * (float)(v41 - (float)((float)(v58 * v55) + v53)))
                            + (float)((float)(v40 - (float)((float)(v56 * v58) + v52))
                                    * (float)(v40 - (float)((float)(v56 * v58) + v52))))
                    + (float)((float)(v42 - (float)((float)(v57 * v58) + v54))
                            * (float)(v42 - (float)((float)(v57 * v58) + v54)));
                v45 = (float *)&m_pComponent[30].m_SafePointerList.mNode.mPrev[2 * v50];
                v46 = v58;
              }
              ++v44;
            }
            while ( v44 < mNext_high );
            v59 = v45[4];
            v60 = v45[6];
            v68 = (__m128)LODWORD(v59);
            v61 = UFG::qVector3::msAxisZ.y;
            v62 = UFG::qVector3::msAxisZ.z;
            v63 = (float)(v59 * v46) + *v45;
            v64 = (float)(v45[5] * v46) + v45[1];
            v65 = (float)(v60 * v46) + v45[2];
            v66 = (float)(v60 * UFG::qVector3::msAxisZ.y) - (float)(v45[5] * UFG::qVector3::msAxisZ.z);
            v67 = (float)(v45[5] * UFG::qVector3::msAxisZ.x) - (float)(v59 * UFG::qVector3::msAxisZ.y);
            v68.m128_f32[0] = (float)(v59 * UFG::qVector3::msAxisZ.z) - (float)(v60 * UFG::qVector3::msAxisZ.x);
            v69 = v68;
            v69.m128_f32[0] = (float)((float)(v68.m128_f32[0] * v68.m128_f32[0]) + (float)(v66 * v66))
                            + (float)(v67 * v67);
            if ( v69.m128_f32[0] != 0.0 )
              v43 = 1.0 / _mm_sqrt_ps(v69).m128_f32[0];
            local_world->v2.x = UFG::qVector3::msAxisZ.x;
            local_world->v2.y = v61;
            local_world->v2.z = v62;
            local_world->v2.w = 0.0;
            local_world->v1.w = 0.0;
            local_world->v1.x = v66 * v43;
            local_world->v1.y = v68.m128_f32[0] * v43;
            local_world->v1.z = v67 * v43;
            v70 = v45[5];
            v71 = v45[6];
            local_world->v0.x = v45[4];
            local_world->v0.w = 0.0;
            local_world->v0.y = v70;
            local_world->v0.z = v71;
            local_world->v3.x = v63;
            local_world->v3.w = 1.0;
            local_world->v3.y = v64;
            local_world->v3.z = v65;
          }
        }
      }
    }
  }
}

// File Line: 1764
// RVA: 0x64E7B0
UFG::RoadNetworkLane *__fastcall UFG::AiDriverComponent::GetLaneAtEdgeNum(
        UFG::AiDriverComponent *this,
        unsigned int endEdgeIndex)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  UFG::RoadNetworkLane *m_CurrentLane; // r15
  UFG::RoadNetworkResource *v5; // rax
  unsigned __int16 *v6; // r12
  __int64 i; // r13
  UFG::RoadNetworkSegment *Segment; // rax
  UFG::RoadNetworkConnection *mOffset; // rcx
  UFG::RoadNetworkSegment *v10; // rbp
  _WORD **v11; // rax
  _WORD *v12; // rdx
  UFG::RoadNetworkNode *v13; // r14
  unsigned int v14; // esi
  UFG::RoadNetworkLane *Lane; // rax
  __int64 v16; // rcx
  UFG::RoadNetworkConnection *v17; // rdi
  unsigned int v18; // ebx
  UFG::RoadNetworkLane *Path; // rax
  UFG::RoadNetworkLane *v20; // r8
  __int64 v21; // rcx
  char *v22; // rdx
  UFG::RoadNetworkSegment **v23; // rax
  UFG::RoadNetworkSegment *v24; // rcx
  __int64 v25; // rax
  UFG::RoadNetworkResource *v27; // [rsp+50h] [rbp+8h]

  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  m_CurrentLane = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext)->m_CurrentLane;
  if ( WORD2(m_pSimComponent[9].m_SafePointerList.mNode.mPrev) )
  {
    v5 = UFG::gpRoadNetworkResource;
    v27 = UFG::gpRoadNetworkResource;
    if ( endEdgeIndex )
    {
      v6 = (unsigned __int16 *)&m_pSimComponent[9].m_SafePointerList.mNode.mPrev + 3;
      for ( i = endEdgeIndex; i; --i )
      {
        Segment = UFG::RoadNetworkResource::GetSegment(v5, *v6);
        mOffset = (UFG::RoadNetworkConnection *)m_CurrentLane->mNextConnection.mOffset;
        v10 = Segment;
        if ( mOffset )
          mOffset = (UFG::RoadNetworkConnection *)((char *)mOffset + (_QWORD)m_CurrentLane + 104);
        v11 = (_WORD **)mOffset->mGate.mOffset;
        if ( v11 )
          v11 = (_WORD **)((char *)v11 + (_QWORD)mOffset + 24);
        v12 = *v11;
        if ( *v11 )
          v12 = (_WORD *)((char *)v12 + (_QWORD)v11);
        if ( *v12 == 1 )
        {
          if ( m_CurrentLane->mNode.mOffset )
            v13 = (UFG::RoadNetworkNode *)((char *)m_CurrentLane + m_CurrentLane->mNode.mOffset);
          else
            v13 = 0i64;
          v14 = 0;
          if ( !v13->mNumLanes )
            goto LABEL_35;
          while ( 1 )
          {
            Lane = UFG::RoadNetworkNode::GetLane(v13, v14);
            v16 = Lane->mNextConnection.mOffset;
            v17 = v16 ? (UFG::RoadNetworkConnection *)((char *)&Lane->mNextConnection + v16) : 0i64;
            v18 = 0;
            if ( v17->mNumLanes )
              break;
LABEL_29:
            if ( ++v14 >= (unsigned __int8)v13->mNumLanes )
              goto LABEL_35;
          }
          while ( 1 )
          {
            Path = UFG::qBezierPathCollectionMemImaged::GetPath(v17, v18);
            v20 = Path;
            if ( Path )
            {
              v21 = Path->mNextConnection.mOffset;
              if ( v21 )
                v22 = (char *)&Path->mNextConnection + v21;
              else
                v22 = 0i64;
              v23 = (UFG::RoadNetworkSegment **)*((_QWORD *)v22 + 3);
              if ( v23 )
                v23 = (UFG::RoadNetworkSegment **)((char *)v23 + (_QWORD)v22 + 24);
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
            mOffset = (UFG::RoadNetworkConnection *)((char *)&v20->mNextConnection + v25);
          else
            mOffset = 0i64;
        }
        m_CurrentLane = UFG::qBezierPathCollectionMemImaged::GetPath(mOffset, 0);
LABEL_35:
        v5 = v27;
        ++v6;
      }
    }
  }
  return m_CurrentLane;
}

// File Line: 1826
// RVA: 0x647B00
void __fastcall UFG::AiDriverComponent::ChangeLane(UFG::AiDriverComponent *this, unsigned int direction)
{
  UFG::RoadNetworkGuide *p_mNext; // rsi
  UFG::RoadNetworkLocation *Name; // rax
  bool IsReversedInNode; // bp
  UFG::RoadNetworkLocation *TargetLocation; // rax
  float LaneOffset; // xmm0_4
  UFG::DrivingTargetOffsetMover *p_m_OffsetMover; // rbx
  float v10; // xmm6_4
  UFG::RoadNetworkLocation *v11; // rax
  float v12; // xmm6_4

  if ( direction )
  {
    p_mNext = (UFG::RoadNetworkGuide *)&this->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext;
    Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
    IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(Name->m_CurrentLane);
    TargetLocation = (UFG::RoadNetworkLocation *)UFG::RoadNetworkGuide::GetTargetLocation((UFG::RippleGenerator *)p_mNext);
    LaneOffset = UFG::RoadNetworkLocation::GetLaneOffset(TargetLocation);
    p_m_OffsetMover = &this->m_OffsetMover;
    if ( IsReversedInNode )
      v10 = LaneOffset - p_m_OffsetMover->m_CurrentLateralOffset;
    else
      v10 = LaneOffset + p_m_OffsetMover->m_CurrentLateralOffset;
    UFG::RoadNetworkGuide::ChangeLane(p_mNext, direction);
    v11 = (UFG::RoadNetworkLocation *)UFG::RoadNetworkGuide::GetTargetLocation((UFG::RippleGenerator *)p_mNext);
    v12 = v10 - UFG::RoadNetworkLocation::GetLaneOffset(v11);
    if ( IsReversedInNode )
      LODWORD(v12) ^= _xmm[0];
    p_m_OffsetMover->m_CurrentLateralOffset = v12;
    UFG::DrivingTargetOffsetMover::SetNewTarget(p_m_OffsetMover, 0.0, 2.0);
  }
}

// File Line: 1851
// RVA: 0x656620
void __fastcall UFG::AiDriverComponent::OnAttach(UFG::AiDriverComponent *this, UFG::SimObjectVehicle *_object)
{
  UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0> *p_m_pVehicleSubject; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::VehicleSubjectComponent *m_pSimComponent; // rcx
  bool v10; // di
  UFG::qPidParameterBlock *v11; // rdx
  UFG::PhysicsMoverInterface *v12; // rcx
  float HalfSteeringRange; // xmm1_4
  UFG::qPidParameterBlock *v14; // rdx

  UFG::VehicleDriverInterface::OnAttach(this, _object);
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0>::Bind<UFG::SimObjectVehicle>(&this->m_pRoadSpace, _object);
  p_m_pVehicleSubject = &this->m_pVehicleSubject;
  if ( this->m_pVehicleSubject.m_pSimComponent )
  {
    mPrev = p_m_pVehicleSubject->mPrev;
    mNext = this->m_pVehicleSubject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pVehicleSubject.m_pSimComponent = 0i64;
LABEL_7:
    this->m_pVehicleSubject.m_pSimObject = 0i64;
    this->m_pVehicleSubject.mNext = &this->m_pVehicleSubject;
    p_m_pVehicleSubject->mPrev = p_m_pVehicleSubject;
    goto LABEL_8;
  }
  if ( this->m_pVehicleSubject.m_pSimObject
    && (p_m_pVehicleSubject->mPrev != p_m_pVehicleSubject || this->m_pVehicleSubject.mNext != &this->m_pVehicleSubject) )
  {
    v7 = p_m_pVehicleSubject->mPrev;
    v8 = this->m_pVehicleSubject.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  this->m_pVehicleSubject.m_Changed = 1;
  this->m_pVehicleSubject.m_pSimObject = _object;
  this->m_pVehicleSubject.m_TypeUID = UFG::VehicleSubjectComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>::BindInternal<UFG::SimObjectVehicle>(
    &this->m_pVehicleSubject,
    _object);
  UFG::PhysicsMoverInterface::Reload((UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent, RELOAD_AI);
  UFG::AiDriverComponent::SetDrivingRoleByClassType(this);
  m_pSimComponent = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  v10 = m_pSimComponent && UFG::VehicleSubjectComponent::IsBoat(m_pSimComponent);
  if ( !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this)
    || v10 )
  {
    v11 = &UFG::AiDriverComponent::m_pHighLODSteering;
    if ( v10 )
      v11 = &UFG::AiDriverComponent::m_pBoatSteering;
  }
  else
  {
    v11 = &UFG::AiDriverComponent::m_pLowLODSteering;
  }
  UFG::qPidControllerCore::SetParameters(&this->m_SteeringPid, v11);
  v12 = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  this->m_fSteeringScale = 1.0;
  if ( v12 )
  {
    HalfSteeringRange = UFG::PhysicsMoverInterface::GetHalfSteeringRange(v12);
    if ( HalfSteeringRange <= 0.017453292 )
      HalfSteeringRange = FLOAT_0_017453292;
    this->m_fSteeringScale = 0.78539819 / HalfSteeringRange;
  }
  *(_QWORD *)&this->m_CatchupMaxSpeedUp = 0i64;
  UFG::qPidControllerCore::SetParameters(&this->m_CatchupPid, &UFG::AiDriverComponent::m_CatchupParams);
  v14 = &UFG::AiDriverComponent::m_Throttle;
  if ( v10 )
    v14 = &UFG::AiDriverComponent::m_BoatThrottle;
  UFG::qPidControllerCore::SetParameters(&this->m_ThrottlePid, v14);
  this->m_BrakingGraph = (UFG::LinearGraph<float> *)&unk_142091418;
  this->m_CarGapGraph = &stru_142091488;
  this->m_fPreviousGasBrakes = 0.0;
  UFG::VehicleDriverInterface::SetDesiredState(this, (UFG::VehicleState)2);
  UFG::AiDriverComponent::AttachDriverProfile(this, _object);
}

// File Line: 1886
// RVA: 0x6569A0
void __fastcall UFG::AiDriverComponent::OnDetach(UFG::AiDriverComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  hkSimpleLocalFrame *m_pComponent; // rcx
  UFG::SimObject *Texture; // rdi
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::VehicleState v6; // edx
  UFG::SimObject *v7; // rax
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0> *p_m_pRoadSpace; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0> *p_m_pVehicleSubject; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax

  if ( (this->m_pSimObject->m_Flags & 2) != 0
    && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this)
    && this->m_AmbientDriverType == AmbientDriverType_Real )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      m_pComponent = (hkSimpleLocalFrame *)m_pSimObject->m_Components.p[30].m_pComponent;
    else
      m_pComponent = 0i64;
    Texture = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(m_pComponent);
    if ( Texture )
    {
      UFG::PedSpawnManager::GetInstance();
      UFG::Simulation::DestroySimObject(&UFG::gSim, Texture);
    }
    this->m_AmbientDriverType = AmbientDriverType_Placement;
  }
  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( !m_pSimComponent
    || (v6 = 5, (float)(3.5999999 * *((float *)&m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1)) <= 30.0) )
  {
    v6 = 1;
  }
  UFG::VehicleDriverInterface::SetDesiredState(this, v6);
  v7 = UFG::AiDriverComponent::m_CurrentDebugCar;
  p_m_pRoadSpace = &this->m_pRoadSpace;
  if ( this->m_pSimObject == UFG::AiDriverComponent::m_CurrentDebugCar )
    v7 = 0i64;
  UFG::AiDriverComponent::m_CurrentDebugCar = v7;
  if ( this->m_pRoadSpace.m_pSimComponent )
  {
    mPrev = p_m_pRoadSpace->mPrev;
    mNext = this->m_pRoadSpace.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pRoadSpace.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pRoadSpace.m_pSimObject = 0i64;
    this->m_pRoadSpace.mNext = &this->m_pRoadSpace;
    p_m_pRoadSpace->mPrev = p_m_pRoadSpace;
    goto LABEL_22;
  }
  if ( this->m_pRoadSpace.m_pSimObject
    && (p_m_pRoadSpace->mPrev != p_m_pRoadSpace || this->m_pRoadSpace.mNext != &this->m_pRoadSpace) )
  {
    v11 = p_m_pRoadSpace->mPrev;
    v12 = this->m_pRoadSpace.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pRoadSpace.m_Changed = 1;
  p_m_pVehicleSubject = &this->m_pVehicleSubject;
  if ( this->m_pVehicleSubject.m_pSimComponent )
  {
    v14 = p_m_pVehicleSubject->mPrev;
    v15 = this->m_pVehicleSubject.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    this->m_pVehicleSubject.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pVehicleSubject.m_pSimObject = 0i64;
    this->m_pVehicleSubject.mNext = &this->m_pVehicleSubject;
    p_m_pVehicleSubject->mPrev = p_m_pVehicleSubject;
    goto LABEL_29;
  }
  if ( this->m_pVehicleSubject.m_pSimObject
    && (p_m_pVehicleSubject->mPrev != p_m_pVehicleSubject || this->m_pVehicleSubject.mNext != &this->m_pVehicleSubject) )
  {
    v16 = p_m_pVehicleSubject->mPrev;
    v17 = this->m_pVehicleSubject.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pVehicleSubject.m_Changed = 1;
  UFG::VehicleDriverInterface::OnDetach(this);
}

// File Line: 1919
// RVA: 0x645140
void __fastcall UFG::AiDriverComponent::AttachDriverProfile(
        UFG::AiDriverComponent *this,
        UFG::SimObjectVehicle *sim_object_vehicle)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *DriverProfile; // rax
  bool *v7; // rax
  char *v8; // rcx
  char v9; // al
  UFG::qPropertySet *m_DriverProfile; // rcx
  float *v11; // rdi
  UFG::qPropertySet *WritableProperties; // rax
  char v13; // [rsp+30h] [rbp+8h] BYREF

  m_pSceneObj = sim_object_vehicle->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  DriverProfile = UFG::SimObjectUtility::FindDriverProfile(mpWritableProperties);
  this->m_DriverProfile = DriverProfile;
  if ( DriverProfile )
  {
    v13 = 0;
    v7 = UFG::qPropertySet::Get<bool>(
           DriverProfile,
           (UFG::qArray<unsigned long,0> *)&qSymbol_DeniesHijack,
           DEPTH_RECURSE);
    v8 = &v13;
    if ( v7 )
      v8 = (char *)v7;
    v9 = *v8;
    m_DriverProfile = this->m_DriverProfile;
    this->m_bDeniesHijack = v9;
    v11 = UFG::qPropertySet::Get<float>(
            m_DriverProfile,
            (UFG::qArray<unsigned long,0> *)&qSymbol_RadioStation,
            DEPTH_RECURSE);
    if ( v11 )
    {
      WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(sim_object_vehicle->m_pSceneObj);
      UFG::qPropertySet::Set<float>(WritableProperties, (UFG::qArray<unsigned long,0> *)&qSymbol_RadioStation, *v11);
    }
  }
}

// File Line: 1935
// RVA: 0x6592E0
void __fastcall UFG::AiDriverComponent::SetFollowOffset(
        UFG::AiDriverComponent *this,
        CarCombat::Side side,
        CarCombat::Position position,
        float tolerance)
{
  UFG::VehicleSubjectComponent *m_pSimComponent; // rcx
  __int64 v6; // rbx
  UFG::qVector3 *v8; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 customOffset; // [rsp+30h] [rbp-28h] BYREF

  m_pSimComponent = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  v6 = position;
  if ( m_pSimComponent && UFG::VehicleSubjectComponent::IsBoat(m_pSimComponent) )
    v8 = &UFG::AiDriverComponent::mCombatBoatOffsets[v6];
  else
    v8 = &UFG::AiDriverComponent::mCombatCarOffsets[v6];
  y = v8->y;
  customOffset.x = v8->x;
  z = v8->z;
  customOffset.y = y;
  customOffset.z = z;
  if ( side == Right )
    LODWORD(customOffset.y) = LODWORD(y) ^ _xmm[0];
  UFG::AiDriverComponent::SetFollowOffsetCustom(this, side, (CarCombat::Position)v6, &customOffset, tolerance);
}

// File Line: 1941
// RVA: 0x6593B0
void __fastcall UFG::AiDriverComponent::SetFollowOffsetCustom(
        UFG::AiDriverComponent *this,
        unsigned __int32 side,
        unsigned __int32 position,
        UFG::qVector3 *customOffset,
        float tolerance)
{
  float y; // xmm0_4
  float z; // xmm1_4

  if ( __PAIR64__(side, position) != *(_QWORD *)&this->m_DesiredOffset || tolerance < this->m_fFollowOffsetTolerance )
  {
    if ( side == 2 || side == 3 )
      this->m_Side = (int)UFG::qRandom(0x64u, (unsigned int *)&UFG::qDefaultSeed) <= 50;
    else
      this->m_Side = side;
    this->m_DesiredOffset = position;
    y = customOffset->y;
    z = customOffset->z;
    this->m_vFollowOffsetDesired.x = customOffset->x;
    this->m_vFollowOffsetDesired.y = y;
    this->m_vFollowOffsetDesired.z = z;
    this->m_fTimeNearOffset = 0.0;
  }
  if ( !position )
    this->m_vFollowOffsetDesired.x = this->m_fFollowDistance * customOffset->x;
  if ( tolerance <= 5.0 )
    this->m_fFollowOffsetTolerance = tolerance;
  else
    this->m_fFollowOffsetTolerance = FLOAT_5_0;
}

// File Line: 1978
// RVA: 0x650F90
float __fastcall UFG::AiDriverComponent::GetTimeAtOffset(UFG::AiDriverComponent *this, CarCombat::Position position)
{
  if ( this->m_DesiredOffset == position )
    return this->m_fTimeNearOffset;
  else
    return 0.0;
}

// File Line: 1985
// RVA: 0x657F50
void __fastcall UFG::AiDriverComponent::RemoveFromRace(UFG::AiDriverComponent *this, bool hideBlip)
{
  UFG::RoadSpaceComponent *m_pSimComponent; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::HudComponent *ComponentOfTypeHK; // rax
  UFG::qBaseTreeRB *Icon; // rax

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
  m_pSimComponent = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::RoadSpaceComponent::SetRaceTrail(m_pSimComponent, 0i64);
  if ( hideBlip )
  {
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( m_pSimObject )
    {
      ComponentOfTypeHK = (UFG::HudComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pSimObject,
                                                 UFG::HudComponent::_TypeUID);
      if ( ComponentOfTypeHK )
      {
        Icon = UFG::HudComponent::GetIcon(ComponentOfTypeHK);
        if ( Icon )
          UFG::UIMapBlip::SetVisible((UFG::UIMapBlip *)Icon, 0);
      }
    }
  }
}

// File Line: 2000
// RVA: 0x662EE0
void __fastcall UFG::AiDriverComponent::UpdateRace(UFG::AiDriverComponent *this, float seconds)
{
  bool v3; // al
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rsi
  bool v5; // bp
  bool v6; // di
  UFG::PhysicsMoverInterface *m_pSimComponent; // rcx
  bool v8; // al
  bool v9; // dl
  UFG::RoadSpaceComponent *m_pSimObject; // rcx
  __int16 v11; // dx
  UFG::RoadSpaceComponent *ComponentOfTypeHK; // rax
  UFG::RacePosition *m_pRacePosition; // rcx
  float v14; // xmm6_4
  float m_CatchupRangeBehind; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm6_4
  float v18; // xmm0_4

  if ( !this->m_pRoadSpace.m_pSimComponent )
    return;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v3 = UFG::RoadSpaceComponent::CleanupOnRaceDeleted((UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent);
  mPrev = this->m_pRoadSpace.m_pSimComponent[26].m_SafePointerList.mNode.mPrev;
  v5 = v3;
  if ( mPrev )
    v6 = *((float *)&mPrev[3].mPrev + 1) > 100.0;
  else
    v6 = 0;
  m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  v8 = m_pSimComponent && UFG::PhysicsMoverInterface::GetEngineDamage(m_pSimComponent) >= 1.0;
  if ( v6 || v8 )
  {
    v9 = 1;
    if ( v6 || v8 )
      goto LABEL_39;
  }
  else
  {
    v9 = 0;
  }
  if ( v5 )
  {
LABEL_39:
    UFG::AiDriverComponent::RemoveFromRace(this, v9);
    return;
  }
  m_pSimObject = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent[26].m_pSimObject;
  if ( m_pSimObject
    && ((v11 = WORD2(m_pSimObject->mNext), (v11 & 0x4000) == 0)
      ? (v11 >= 0
       ? ((v11 & 0x2000) != 0 || (v11 & 0x1000) != 0
        ? (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)m_pSimObject,
                                                            UFG::RoadSpaceComponent::_TypeUID))
        : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)m_pSimObject,
                                                            UFG::RoadSpaceComponent::_TypeUID)))
       : (ComponentOfTypeHK = *(UFG::RoadSpaceComponent **)(*(_QWORD *)&m_pSimObject->m_NavGuide.m_PathQueryState
                                                          + 384i64)))
      : (ComponentOfTypeHK = *(UFG::RoadSpaceComponent **)(*(_QWORD *)&m_pSimObject->m_NavGuide.m_PathQueryState + 384i64)),
        ComponentOfTypeHK) )
  {
    m_pRacePosition = ComponentOfTypeHK->m_pRacePosition;
  }
  else
  {
    m_pRacePosition = 0i64;
  }
  if ( mPrev && m_pRacePosition )
  {
    v14 = *(float *)&mPrev[3].mPrev - (float)(this->m_CatchupOffset + m_pRacePosition->fRaceDistance);
    UFG::qPidControllerCore::Record(&this->m_CatchupPid, v14, seconds, 0i64);
    m_CatchupRangeBehind = this->m_CatchupRangeBehind;
    if ( v14 > 0.0 )
      m_CatchupRangeBehind = this->m_CatchupRangeAhead;
    UFG::AiDriverComponent::m_CatchupParams.m_P_Coefficient = -1.0 / m_CatchupRangeBehind;
    if ( m_CatchupRangeBehind >= 50.0 )
      m_CatchupRangeBehind = FLOAT_50_0;
    v16 = FLOAT_3_1415927;
    v17 = (float)(v14 * 3.1415927) / m_CatchupRangeBehind;
    if ( v17 <= -3.1415927 )
    {
      v17 = FLOAT_N3_1415927;
    }
    else if ( v17 >= 3.1415927 )
    {
      goto LABEL_38;
    }
    v16 = v17;
LABEL_38:
    v18 = (float)(cosf(v16) + 1.0) * 0.5;
    UFG::AiDriverComponent::m_CatchupParams.m_I_Coefficient = (float)(1.0 - v18) * UFG::AiDriverComponent::m_Catchup_I;
    UFG::AiDriverComponent::m_CatchupParams.m_D_Coefficient = UFG::AiDriverComponent::m_Catchup_D * v18;
    UFG::qPidControllerCore::SetParameters(&this->m_CatchupPid, &UFG::AiDriverComponent::m_CatchupParams);
  }
}

// File Line: 2099
// RVA: 0x64D830
float __fastcall UFG::AiDriverComponent::GetCatchupBoost(UFG::AiDriverComponent *this)
{
  float result; // xmm0_4
  UFG::SimComponent *m_pSimComponent; // rax

  if ( this->m_DrivingMode != 6 )
    return 0.0;
  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  if ( !m_pSimComponent || !m_pSimComponent[26].m_pSimObject )
    return 0.0;
  result = UFG::qPidControllerCore::GetOutput(&this->m_CatchupPid);
  if ( result <= COERCE_FLOAT(LODWORD(this->m_CatchupMaxSlowDown) ^ _xmm[0]) )
    LODWORD(result) = LODWORD(this->m_CatchupMaxSlowDown) ^ _xmm[0];
  if ( result >= this->m_CatchupMaxSpeedUp )
    result = this->m_CatchupMaxSpeedUp;
  if ( result < -1.0 )
    return FLOAT_N1_0;
  return result;
}

// File Line: 2142
// RVA: 0x648080
void __fastcall UFG::AiDriverComponent::CheckForGround(UFG::AiDriverComponent *this)
{
  unsigned int m_DrivingMode; // ecx
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimComponentHolder *p; // rax
  UFG::SimComponent *m_pComponent; // rdi

  m_DrivingMode = this->m_DrivingMode;
  if ( ((m_DrivingMode - 3) & 0xFFFFFFFC) == 0 && m_DrivingMode != 5 )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
    {
      p = m_pSimObject->m_Components.p;
      m_pComponent = p[2].m_pComponent;
      if ( m_pComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)p[2].m_pComponent);
        if ( *(float *)&m_pComponent[2].m_BoundComponentHandles.mNode.mNext < -20.0 )
        {
          if ( this->m_DrivingMode == 6 )
            UFG::AiDriverComponent::RemoveFromRace(this, 1);
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
        }
      }
    }
  }
}

// File Line: 2185
// RVA: 0x648140
void __fastcall UFG::AiDriverComponent::CheckForReattach(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::RoadNetworkGuide *p_mNext; // rdi
  UFG::VehicleWayFinderClient *p_m_pSimObject; // rsi
  UFG::RoadNetworkLocation *Name; // rbp
  UFG::RoadNetworkGraph *RoadNetworkGraph; // rax
  UFG::RoadNetworkResource *pRoadNetworkResource; // rbp
  UFG::SimComponent *v8; // rdi
  float m_LaneT; // xmm6_4
  unsigned int mLaneIndex; // ebx
  UFG::RoadNetworkNode *RoadNetworkNode; // rax
  bool v12; // zf
  UFG::qVector3 result; // [rsp+30h] [rbp-48h] BYREF
  UFG::qVector3 v14; // [rsp+40h] [rbp-38h] BYREF
  UFG::RoadNetworkLocation v15; // [rsp+50h] [rbp-28h] BYREF

  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  if ( m_pSimComponent )
  {
    p_mNext = (UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext;
    if ( m_pSimComponent != (UFG::SimComponent *)-376i64 )
    {
      if ( LOBYTE(m_pSimComponent[8].m_Flags) )
      {
        p_m_pSimObject = (UFG::VehicleWayFinderClient *)&m_pSimComponent[8].m_pSimObject;
        if ( m_pSimComponent != (UFG::SimComponent *)-552i64 )
        {
          if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this) )
          {
            if ( !UFG::AiDriverComponent::IsBoat(this) )
            {
              Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
              if ( UFG::RoadNetworkLocation::IsValid(Name) )
              {
                UFG::RoadNetworkLocation::GetPos(Name, &result);
                if ( (float)((float)((float)((float)(p_mNext->m_Position.y - result.y)
                                           * (float)(p_mNext->m_Position.y - result.y))
                                   + (float)((float)(p_mNext->m_Position.x - result.x)
                                           * (float)(p_mNext->m_Position.x - result.x)))
                           + (float)((float)(p_mNext->m_Position.z - result.z)
                                   * (float)(p_mNext->m_Position.z - result.z))) >= 3600.0 )
                {
                  RoadNetworkGraph = UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(
                                       UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                                       p_m_pSimObject);
                  if ( RoadNetworkGraph )
                  {
                    pRoadNetworkResource = RoadNetworkGraph->pRoadNetworkResource;
                    if ( pRoadNetworkResource )
                    {
                      Scaleform::GFx::AS3::Value::Value(&v15);
                      UFG::RoadNetworkLocation::AttachToNetwork(
                        &v15,
                        pRoadNetworkResource,
                        &p_mNext->m_Position,
                        0i64,
                        p_m_pSimObject->m_RoadNetworkType);
                      if ( UFG::RoadNetworkLocation::IsValid(&v15)
                        && (UFG::RoadNetworkLocation::GetPos(&v15, &v14),
                            (float)((float)((float)((float)(p_mNext->m_Position.y - v14.y)
                                                  * (float)(p_mNext->m_Position.y - v14.y))
                                          + (float)((float)(p_mNext->m_Position.x - v14.x)
                                                  * (float)(p_mNext->m_Position.x - v14.x)))
                                  + (float)((float)(p_mNext->m_Position.z - v14.z)
                                          * (float)(p_mNext->m_Position.z - v14.z))) < 3025.0) )
                      {
                        v8 = this->m_pRoadSpace.m_pSimComponent;
                        m_LaneT = v15.m_LaneT;
                        mLaneIndex = v15.m_CurrentLane->mLaneIndex;
                        RoadNetworkNode = UFG::RoadNetworkLocation::GetRoadNetworkNode(&v15);
                        UFG::RoadNetworkGuide::AttachToNetwork(
                          (UFG::RoadNetworkGuide *)&v8[5].m_BoundComponentHandles.mNode.mNext,
                          v8->m_pSimObject,
                          RoadNetworkNode,
                          mLaneIndex,
                          m_LaneT);
                      }
                      else
                      {
                        v12 = this->m_DrivingMode == 0;
                        this->m_IsAmbient = 0;
                        if ( !v12 )
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
  UFG::SimObject *m_pSimObject; // rax
  int v4; // edi
  UFG::TransformNodeComponent *m_pComponent; // rbx
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  float *p_mFOVOffset; // rcx
  char v8; // r15
  float v9; // xmm6_4
  float v10; // xmm1_4
  UFG::AiDriverComponent::AmbientDriverType m_AmbientDriverType; // eax
  UFG::SimObject *v13; // rax
  UFG::SimComponentHolder *p; // rax
  UFG::VehicleOccupantComponent *v15; // r14
  int NumberOfOccupants; // ebp
  UFG::SimObjectCharacter *Passenger; // rbx
  UFG::SimObject *v18; // rax
  UFG::VehicleOccupantComponent *v19; // rcx
  UFG::SimObject *v20; // rax
  hkSimpleLocalFrame *v21; // rcx

  if ( !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this)
    && !UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &qSymbol_Taxi)
    || this->m_AmbientDriverType == AmbientDriverType_None )
  {
    return 0;
  }
  m_pSimObject = this->m_pSimObject;
  v4 = 0;
  if ( m_pSimObject )
    m_pComponent = (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent;
  else
    m_pComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mFOVOffset = &mCurrentCamera->mCamera.mFOVOffset;
  else
    p_mFOVOffset = 0i64;
  v8 = 0;
  v9 = (float)((float)((float)(p_mFOVOffset[45] - m_pComponent->mWorldTransform.v3.y)
                     * (float)(p_mFOVOffset[45] - m_pComponent->mWorldTransform.v3.y))
             + (float)((float)(p_mFOVOffset[44] - m_pComponent->mWorldTransform.v3.x)
                     * (float)(p_mFOVOffset[44] - m_pComponent->mWorldTransform.v3.x)))
     + (float)((float)(p_mFOVOffset[46] - m_pComponent->mWorldTransform.v3.z)
             * (float)(p_mFOVOffset[46] - m_pComponent->mWorldTransform.v3.z));
  if ( UFG::VehicleSubjectComponent::IsBike((UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent) )
    v10 = UFG::AiDriverComponent::m_AmbientBikeDriverPopInDistanceSquared;
  else
    v10 = UFG::AiDriverComponent::m_AmbientDriverPopInDistanceSquared;
  m_AmbientDriverType = this->m_AmbientDriverType;
  if ( m_AmbientDriverType == AmbientDriverType_Placement && v9 < (float)(v10 - 5.0) )
    return UFG::AiDriverComponent::PopulateVehicleOccupants(this);
  if ( m_AmbientDriverType == AmbientDriverType_Real )
  {
    if ( v9 >= (float)(v10 + 5.0) )
    {
      v13 = this->m_pSimObject;
      if ( v13
        && (p = v13->m_Components.p, (v15 = (UFG::VehicleOccupantComponent *)p[30].m_pComponent) != 0i64)
        && (NumberOfOccupants = UFG::VehicleOccupantComponent::GetNumberOfOccupants((UFG::VehicleOccupantComponent *)p[30].m_pComponent),
            NumberOfOccupants > 0) )
      {
        while ( 1 )
        {
          Passenger = (UFG::SimObjectCharacter *)UFG::VehicleOccupantComponent::GetPassenger(v15, v4, 0);
          if ( Passenger == UFG::GetLocalPlayer() )
            break;
          if ( ++v4 >= NumberOfOccupants )
            goto LABEL_24;
        }
      }
      else
      {
LABEL_24:
        v18 = this->m_pSimObject;
        v8 = 0;
        this->m_AmbientDriverType = AmbientDriverType_Placement;
        if ( v18 )
        {
          v19 = (UFG::VehicleOccupantComponent *)v18->m_Components.p[30].m_pComponent;
          if ( v19 )
          {
            UFG::VehicleOccupantComponent::DeleteAllOccupants(v19);
            return 1;
          }
        }
      }
      return v8;
    }
    v20 = this->m_pSimObject;
    if ( v20 )
    {
      v21 = (hkSimpleLocalFrame *)v20->m_Components.p[30].m_pComponent;
      if ( v21 )
      {
        if ( !Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v21) )
          return UFG::AiDriverComponent::DepopulateVehicleOccupants(this);
      }
    }
  }
  return v8;
}return UFG::AiDriverComponent::DepopulateVehicleOccupants(this);


// File Line: 2299
// RVA: 0x65EDD0
void __fastcall UFG::AiDriverComponent::Update(UFG::AiDriverComponent *this, float seconds)
{
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rsi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rdx
  UFG::PhysicsWheeledVehicle *v10; // rcx
  float v11; // xmm0_4
  float v12; // xmm0_4
  float x; // xmm0_4
  bool v14; // si
  UFG::qPidParameterBlock *v15; // rdx
  UFG::qPidParameterBlock *v16; // rdx
  int m_EndIndex; // eax
  float HalfSteeringRange; // xmm1_4
  __int64 v19; // rax
  __int64 v20; // r14
  UFG::SimObjectGame *v21; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *m_pComponent; // rsi
  UFG::SimComponent *v24; // rax
  UFG::qVector3 *v25; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  bool v29; // dl
  UFG::SimObject *v30; // rcx
  UFG::SimComponent *v31; // rax
  bool v32; // al
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::allocator::free_link *v35; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v38; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rdi
  float tAmplitude; // xmm2_4
  signed __int16 v42; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> result; // [rsp+28h] [rbp-38h] BYREF
  UFG::qVector2 value; // [rsp+80h] [rbp+20h] BYREF

  v4 = *(_QWORD *)&this[-1].m_ResetStopDistOnStop;
  if ( !v4 || (*(_WORD *)(v4 + 76) & 0x400) == 0 )
  {
    UFG::AiDriverComponent::m_InUpdateScope = 1;
    UFG::AiDriverComponent::CheckForGround((UFG::AiDriverComponent *)((char *)this - 64));
    if ( *(_BYTE *)(*(_QWORD *)&this->mForceDock + 1940i64) )
    {
      v5 = *(_QWORD *)&this[-1].m_ResetStopDistOnStop;
      if ( v5 )
      {
        v6 = *(_QWORD *)(v5 + 104);
        v7 = *(_QWORD *)(v6 + 32);
        if ( v7 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v6 + 32));
          UFG::NavGuide::UpdatePathPosition(
            (UFG::NavGuide *)(*(_QWORD *)&this->mForceDock + 80i64),
            (UFG::qVector3 *)(v7 + 176));
        }
      }
    }
    UFG::AiDriverComponent::CheckForReattach((UFG::AiDriverComponent *)((char *)this - 64));
    if ( this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev )
    {
      mPrev = this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev;
      mNext = mPrev[40].mNext;
      if ( mNext )
      {
        v10 = 0i64;
        if ( (BYTE4(mNext[37].mNext) & 7) != 0 )
          v10 = (UFG::PhysicsWheeledVehicle *)mPrev[40].mNext;
        if ( v10 )
          UFG::PhysicsWheeledVehicle::ClearSteeringDeadZone(v10);
      }
    }
    UFG::VehicleDriverInterface::Update(this, seconds);
    v11 = *(float *)&this->m_CombatStats.mNumAttacks[1];
    if ( v11 > 0.0 )
    {
      v12 = v11 - seconds;
      if ( v12 < 0.0 )
        v12 = 0.0;
      *(float *)&this->m_CombatStats.mNumAttacks[1] = v12;
    }
    x = *(float *)&this->m_CombatStats.mNumAttacks[2];
    if ( x > 0.0 )
    {
      x = x - seconds;
      if ( x < 0.0 )
        x = 0.0;
      *(float *)&this->m_CombatStats.mNumAttacks[2] = x;
    }
    v14 = this->m_pRoadSpace.mNext
       && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)this->m_pRoadSpace.mNext);
    v15 = &UFG::AiDriverComponent::m_Throttle;
    if ( v14 )
      v15 = &UFG::AiDriverComponent::m_BoatThrottle;
    UFG::qPidControllerCore::SetParameters((UFG::qPidControllerCore *)&this->m_SteeringPid.m_I_Term.m_EndIndex, v15);
    if ( !((__int64 (__fastcall *)(UFG::SimObject **))this[-1].m_PathingTarget.m_pPointer[1].vfptr)(&this[-1].m_PathingTarget.m_pPointer)
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
    UFG::qPidControllerCore::SetParameters((UFG::qPidControllerCore *)&this->m_pChaseVehicleSubject.mNext, v16);
    UFG::qPidControllerCore::SetParameters(
      (UFG::qPidControllerCore *)&this->m_CarGapGraph,
      &UFG::AiDriverComponent::m_CatchupParams);
    m_EndIndex = this->m_ThrottlePid.m_D_Term.m_EndIndex;
    if ( m_EndIndex == 3 || m_EndIndex == 7 && !HIDWORD(this->m_pCastingPhantom) )
      UFG::VehicleCombatStats::Tick((UFG::VehicleCombatStats *)&this->m_AvoidableSensor, seconds);
    if ( this->m_ThrottlePid.m_D_Term.m_EndIndex == 6 )
      UFG::AiDriverComponent::UpdateRace((UFG::AiDriverComponent *)((char *)this - 64), seconds);
    if ( this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev )
    {
      HalfSteeringRange = UFG::PhysicsMoverInterface::GetHalfSteeringRange((UFG::PhysicsMoverInterface *)this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev);
      if ( HalfSteeringRange <= 0.017453292 )
        HalfSteeringRange = FLOAT_0_017453292;
      x = 0.78539819 / HalfSteeringRange;
      *(float *)&this->m_CatchupPid.m_D_Term.m_EndIndex = 0.78539819 / HalfSteeringRange;
    }
    v19 = *(_QWORD *)&this[-1].m_ResetStopDistOnStop;
    if ( v19 )
      v20 = *(_QWORD *)(*(_QWORD *)(v19 + 104) + 32i64);
    else
      v20 = 0i64;
    if ( this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev
      && this->m_pRoadSpace.mNext
      && v20 )
    {
      if ( UFG::AiDriverComponent::UpdateVehicleOccupants((UFG::AiDriverComponent *)((char *)this - 64)) )
      {
LABEL_93:
        UFG::AiDriverComponent::m_InUpdateScope = 0;
        return;
      }
      v21 = *(UFG::SimObjectGame **)(*(_QWORD *)&this->mForceDock + 1704i64);
      if ( v21 )
      {
        m_Flags = v21->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::RoadSpaceComponent *)v21->m_Components.p[24].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          v24 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::RoadSpaceComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v21, UFG::RoadSpaceComponent::_TypeUID);
          m_pComponent = (UFG::RoadSpaceComponent *)v24;
        }
        else
        {
          m_pComponent = (UFG::RoadSpaceComponent *)v21->m_Components.p[24].m_pComponent;
        }
        if ( m_pComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v20);
          v25 = UFG::RoadSpaceComponent::WorldToChase(
                  m_pComponent,
                  (UFG::qVector3 *)&result,
                  (UFG::qVector3 *)(v20 + 176));
          x = v25->x;
          y = v25->y;
          z = v25->z;
          this->m_CatchupRangeBehind = v25->x;
          this->m_CatchupRangeAhead = y;
          this->m_CatchupMaxSpeedUp = z;
        }
      }
      UFG::AiDriverComponent::UpdateAvoidableSensor((UFG::AiDriverComponent *)((char *)this - 64), seconds, x);
      UFG::AiDriverComponent::UpdateDesiredSpeed((UFG::AiDriverComponent *)((char *)this - 64), seconds);
      UFG::AiDriverComponent::UpdateSteering((UFG::AiDriverComponent *)((char *)this - 64), seconds);
      UFG::AiDriverComponent::UpdateSpeed((UFG::AiDriverComponent *)((char *)this - 64), seconds);
    }
    if ( *(float *)&this->m_bSteeringLock > 0.5
      && UFG::Metrics::msInstance.mSimTimeMSec - *(_QWORD *)&this->m_fSteeringScale < UFG::gLastValidHighSpeedCollisionDuration )
    {
      v28 = this->m_pVehicleSubject.mPrev;
      v29 = v28
         && ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))v28->mPrev[23].mPrev)(v28);
      v30 = *(UFG::SimObject **)&this[-1].m_ResetStopDistOnStop;
      v31 = v30 ? v30->m_Components.p[16].m_pComponent : 0i64;
      v32 = v31 != 0i64;
      if ( v29 && v32 )
      {
        result.mPrev = &result;
        result.mNext = &result;
        result.m_pPointer = v30;
        if ( v30 )
        {
          p_mNode = &v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
          v34 = p_mNode->mPrev;
          v34->mNext = &result;
          result.mPrev = v34;
          result.mNext = p_mNode;
          p_mNode->mPrev = &result;
        }
        v35 = UFG::qMalloc(0x50ui64, "AiDriverComponent::VehicleDisabledEvent", 0i64);
        value = (UFG::qVector2)v35;
        if ( v35 )
          UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v35, UFG::gVehicleDisabledChannel.mName, &result);
        UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v35);
        if ( result.m_pPointer )
        {
          v36 = result.mPrev;
          v37 = result.mNext;
          result.mPrev->mNext = result.mNext;
          v37->mPrev = v36;
          result.mPrev = &result;
          result.mNext = &result;
        }
        result.m_pPointer = 0i64;
        v38 = result.mPrev;
        v39 = result.mNext;
        result.mPrev->mNext = result.mNext;
        v39->mPrev = v38;
        result.mPrev = &result;
        result.mNext = &result;
      }
    }
    value.x = (float)(seconds * 4294967300.0) / this->m_SteeringNoise.tFrequency;
    LODWORD(this->m_SteeringNoise.tOffset) += (int)value.x;
    v40 = this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev;
    LODWORD(v40[6].mNext) |= 0x400u;
    value.x = *(float *)&v40[5].mNext;
    value.y = *(float *)&v40[6].mPrev;
    UFG::HistoryBuffer<UFG::qVector2>::Record(
      (UFG::HistoryBuffer<UFG::qVector2> *)&this->m_SteeringNoise.tFrequency,
      &value);
    tAmplitude = this->m_SteeringNoise.tAmplitude;
    if ( tAmplitude > 0.0 )
    {
      UFG::HistoryBuffer<UFG::qVector2>::GetValue(
        (UFG::HistoryBuffer<UFG::qVector2> *)&this->m_SteeringNoise.tFrequency,
        &value,
        tAmplitude);
      *(float *)&v40[6].mPrev = value.y;
      *(float *)&v40[5].mNext = value.x;
    }
    if ( UFG::AiDriverComponent::m_CurrentDebugCar )
    {
      v42 = UFG::AiDriverComponent::m_CurrentDebugCar->m_Flags;
      if ( (v42 & 0x4000) != 0 || v42 < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)UFG::AiDriverComponent::m_CurrentDebugCar);
      }
      else if ( (v42 & 0x2000) != 0 || (v42 & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)UFG::AiDriverComponent::m_CurrentDebugCar,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                        UFG::AiDriverComponent::m_CurrentDebugCar,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
      {
        if ( LOBYTE(ComponentOfTypeHK->m_pRoadSpace.m_pSimComponent[8].m_Flags) )
          Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&ComponentOfTypeHK->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext);
      }
    }
    goto LABEL_93;
  }
}ponentOfTypeHK->m_pRoadSpace.m_pSimComponent[8].m_Flags) )
          Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&ComponentOfTypeHK->m

// File Line: 2701
// RVA: 0x6579C0
bool __fastcall UFG::AiDriverComponent::PopulateVehicleOccupants(UFG::AiDriverComponent *this)
{
  UFG::SimObjectCharacter *AmbientPedForVehicle; // rax
  UFG::SimObjectVehicle *m_pSimObject; // rsi
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rbx
  UFG::qPropertyList *v6; // r14
  UFG::qPropertyList *v7; // r15
  UFG::PedSpawnManager *Instance; // rax
  UFG::qPropertySet *WritableProperties; // rax
  unsigned int *v10; // rax
  unsigned int v11; // ebx
  unsigned int v12; // edi
  UFG::SimObject *v13; // rax
  UFG::VehicleOccupantComponent *v14; // rbp
  UFG::PedSpawnManager *v15; // rax
  UFG::SimObjectCharacter *v16; // rax

  LOBYTE(AmbientPedForVehicle) = UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame;
  if ( UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame )
  {
    --UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame;
    m_pSimObject = (UFG::SimObjectVehicle *)this->m_pSimObject;
    m_pSceneObj = m_pSimObject->m_pSceneObj;
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = m_pSceneObj->mpConstProperties;
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&qSymbol_VehiclePriorityClassList,
           DEPTH_RECURSE);
    v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&qSymbol_VehicleExclusionClassList,
           DEPTH_RECURSE);
    Instance = UFG::PedSpawnManager::GetInstance();
    AmbientPedForVehicle = UFG::PedSpawnManager::GetAmbientPedForVehicle(Instance, v6, v7, 0i64);
    if ( AmbientPedForVehicle )
    {
      this->m_AmbientDriverType = AmbientDriverType_Real;
      UFG::VehicleUtility::PlaceCharacterInVehicle(
        AmbientPedForVehicle,
        m_pSimObject,
        eTARGET_TYPE_VEHICLE_DRIVER,
        0,
        1,
        0);
      WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(m_pSimObject->m_pSceneObj);
      v10 = UFG::qPropertySet::Get<unsigned long>(
              WritableProperties,
              (UFG::qArray<unsigned long,0> *)&qSymbol_AmbientPassengerCount,
              DEPTH_RECURSE);
      v11 = 0;
      v12 = 0;
      if ( v10 )
      {
        v12 = *v10;
        v13 = this->m_pSimObject;
        v14 = v13 ? (UFG::VehicleOccupantComponent *)v13->m_Components.p[30].m_pComponent : 0i64;
        if ( v12 > (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfSeats(v14) - 1 )
          v12 = UFG::VehicleOccupantComponent::GetNumberOfSeats(v14) - 1;
      }
      if ( v12 )
      {
        do
        {
          v15 = UFG::PedSpawnManager::GetInstance();
          v16 = UFG::PedSpawnManager::GetAmbientPedForVehicle(v15, v6, v7, 0i64);
          if ( !v16 )
            break;
          UFG::VehicleUtility::PlaceCharacterInVehicle(v16, m_pSimObject, (UFG::eTargetTypeEnum)(v11 + 5), 0, 1, 0);
          ++v11;
        }
        while ( v11 < v12 );
      }
      LOBYTE(AmbientPedForVehicle) = 1;
    }
  }
  return (char)AmbientPedForVehicle;
}

// File Line: 2782
// RVA: 0x64AAD0
char __fastcall UFG::AiDriverComponent::DepopulateVehicleOccupants(UFG::AiDriverComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::VehicleOccupantComponent *m_pComponent; // rcx

  m_pSimObject = this->m_pSimObject;
  this->m_AmbientDriverType = AmbientDriverType_Placement;
  if ( !m_pSimObject )
    return 0;
  m_pComponent = (UFG::VehicleOccupantComponent *)m_pSimObject->m_Components.p[30].m_pComponent;
  if ( !m_pComponent )
    return 0;
  UFG::VehicleOccupantComponent::DeleteAllOccupants(m_pComponent);
  return 1;
}

// File Line: 2817
// RVA: 0x64F570
float __fastcall UFG::AiDriverComponent::GetSpeedForNextGuide(UFG::AiDriverComponent *this, float desiredSpeed)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  float v3; // xmm6_4
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **v5; // rdi
  UFG::RoadNetworkLane *mPrev; // rcx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **ClosestCarToStart; // rax
  float Gap; // xmm8_4
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v9; // r8
  __int16 v10; // cx
  UFG::SimComponent *ComponentOfType; // rax
  bool v12; // zf
  UFG::SimObjectGame *v13; // rcx
  float v14; // xmm7_4
  float Value; // xmm0_4
  UFG::LinearGraph<float> *m_BrakingGraph; // rcx
  float v17; // xmm8_4
  float v18; // xmm0_4
  float v19; // xmm7_4

  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  v3 = FLOAT_3_4028235e38;
  if ( LOBYTE(m_pSimComponent[8].m_Flags) )
  {
    v5 = *(UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> ***)&m_pSimComponent[8].m_TypeUID;
    if ( v5 )
    {
      Gap = *(float *)&m_pSimComponent[7].m_BoundComponentHandles.mNode.mNext;
    }
    else
    {
      mPrev = (UFG::RoadNetworkLane *)m_pSimComponent[7].m_SafePointerList.mNode.mPrev;
      if ( !mPrev )
        return v3;
      ClosestCarToStart = UFG::RoadNetworkLane::GetClosestCarToStart(mPrev);
      v5 = ClosestCarToStart;
      if ( !ClosestCarToStart )
        return v3;
      Gap = UFG::RoadNetworkGuide::GetGap(
              (UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext,
              (UFG::RoadNetworkGuide *)ClosestCarToStart);
    }
    v9 = v5[9];
    if ( v9 )
    {
      v10 = WORD2(v9[4].mNext);
      if ( (v10 & 0x4000) == 0 )
      {
        if ( v10 >= 0 )
        {
          if ( (v10 & 0x2000) != 0 )
            return v3;
          v12 = (v10 & 0x1000) == 0;
          v13 = (UFG::SimObjectGame *)v5[9];
          if ( v12 )
            ComponentOfType = UFG::SimObject::GetComponentOfType(v13, UFG::PhysicsMoverInterface::_TypeUID);
          else
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::PhysicsMoverInterface::_TypeUID);
        }
        else
        {
          ComponentOfType = (UFG::SimComponent *)v9[6].mNext[34].mPrev;
        }
        if ( ComponentOfType )
        {
          v14 = *((float *)&ComponentOfType[10].m_BoundComponentHandles.mNode.mPrev + 1);
          if ( v14 <= desiredSpeed
            || *((float *)&this->mMoverComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1) == 0.0
            && v14 < 0.001 )
          {
            Value = UFG::LinearGraph<float>::GetValue(this->m_CarGapGraph, v14);
            m_BrakingGraph = this->m_BrakingGraph;
            v17 = Gap - Value;
            if ( v17 < m_BrakingGraph->fDomain[m_BrakingGraph->nData - 1] )
            {
              v18 = UFG::LinearGraph<float>::GetValue(m_BrakingGraph, v17);
              v19 = v14 - 5.0;
              if ( v18 <= v19 )
                v18 = v19;
              if ( v18 < desiredSpeed )
                return v18;
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
  UFG::SimComponent *m_pSimComponent; // rbx
  float v3; // xmm6_4
  float result; // xmm0_4
  float v7; // xmm1_4
  UFG::LinearGraph<float> *m_BrakingGraph; // rcx
  float Value; // xmm0_4

  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  v3 = FLOAT_3_4028235e38;
  if ( !LOBYTE(m_pSimComponent[8].m_Flags)
    || !UFG::RoadNetworkGuide::GetNextConnection((UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext) )
  {
    return v3;
  }
  result = 0.0;
  if ( m_pSimComponent[7].m_SafePointerList.mNode.mPrev )
  {
    v7 = *((float *)&m_pSimComponent[7].m_BoundComponentHandles.mNode.mNext + 1);
    if ( v7 >= 0.0 )
    {
      m_BrakingGraph = this->m_BrakingGraph;
      if ( v7 < m_BrakingGraph->fDomain[m_BrakingGraph->nData - 1] )
      {
        Value = UFG::LinearGraph<float>::GetValue(m_BrakingGraph, v7);
        if ( Value < desiredSpeed )
          return Value;
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
  UFG::SimComponent *m_pSimComponent; // rdx
  float m_fDesiredSpeed; // xmm3_4
  float v4; // xmm7_4
  float m_fRaceSpeedLimit; // xmm1_4
  float m_RoadSpeedLimitScale; // xmm0_4
  float v9; // xmm6_4
  float m_fDelayedStopDecel; // xmm0_4
  float v11; // xmm0_4
  char IsClassType; // bl
  char IsPlayerPassengerOfVehicle; // al
  float v14; // xmm1_4
  float updated; // xmm0_4
  __int64 v16; // rax
  UFG::SimComponent *v17; // rcx
  UFG::SimObject *m_pPointer; // rbx
  float x; // xmm1_4
  __m128 mPrev_high; // xmm0
  float z; // xmm2_4
  float *v22; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v24; // xmm7_4
  UFG::VehicleSubjectComponent *v25; // rcx
  float Mass; // xmm8_4
  bool IsBoat; // al
  UFG::SimComponent *v28; // rax
  float *p_m_fChaseSpeedLimit; // rcx
  bool v30; // zf
  float *v31; // rax
  UFG::SimComponent *v32; // rcx
  __m128 v33; // xmm2
  float v34; // xmm8_4
  UFG::VehicleSubjectComponent *v35; // rcx
  float v36; // xmm7_4
  bool v37; // al
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  float m_DesiredSpeedLimit; // xmm1_4
  float v40; // xmm0_4

  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  m_fDesiredSpeed = this->m_fDesiredSpeed;
  v4 = FLOAT_16_6;
  this->m_fDesiredSpeed = 0.0;
  this->m_RoadSpeedLimit = -1.0;
  if ( m_pSimComponent && m_pSimComponent != (UFG::SimComponent *)-376i64 && LOBYTE(m_pSimComponent[8].m_Flags) )
    v4 = *(float *)(&m_pSimComponent[7].m_SimObjIndex + 1);
  m_fRaceSpeedLimit = FLOAT_35_0;
  if ( !this->m_bRespectSpeedLimit )
    v4 = FLOAT_35_0;
  m_RoadSpeedLimitScale = this->m_RoadSpeedLimitScale;
  v9 = 0.0;
  if ( m_RoadSpeedLimitScale >= 0.0 )
    v4 = v4 * m_RoadSpeedLimitScale;
  m_fDelayedStopDecel = this->m_fDelayedStopDecel;
  if ( m_fDelayedStopDecel >= 0.0 )
  {
    switch ( this->m_DrivingMode )
    {
      case 1u:
        IsClassType = UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &qSymbol_Taxi);
        IsPlayerPassengerOfVehicle = UFG::VehicleUtility::IsPlayerPassengerOfVehicle(this->m_pSimObject);
        if ( IsClassType && IsPlayerPassengerOfVehicle )
          goto $LN3_62;
        this->m_RoadSpeedLimit = v4;
        v14 = v4;
        goto LABEL_21;
      case 2u:
        this->m_RoadSpeedLimit = v4;
        this->m_fDesiredSpeed = UFG::AiDriverComponent::GetSpeedFromRoad(this, v4);
        if ( this->m_GoToSlowDownForDestination )
        {
          v16 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[17].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent);
          v17 = this->m_pRoadSpace.m_pSimComponent;
          m_pPointer = this->m_PathingTarget.m_pPointer;
          x = *(float *)&v17[25].m_BoundComponentHandles.mNode.mPrev;
          mPrev_high = (__m128)HIDWORD(v17[25].m_BoundComponentHandles.mNode.mPrev);
          z = *(float *)&v17[25].m_BoundComponentHandles.mNode.mNext;
          v22 = (float *)v16;
          if ( m_pPointer )
          {
            m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
            x = m_pTransformNodeComponent->mWorldTransform.v3.x;
            mPrev_high = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
            z = m_pTransformNodeComponent->mWorldTransform.v3.z;
          }
          mPrev_high.m128_f32[0] = (float)((float)((float)(mPrev_high.m128_f32[0] - v22[1])
                                                 * (float)(mPrev_high.m128_f32[0] - v22[1]))
                                         + (float)((float)(x - *v22) * (float)(x - *v22)))
                                 + (float)((float)(z - v22[2]) * (float)(z - v22[2]));
          v24 = _mm_sqrt_ps(mPrev_high).m128_f32[0] - this->m_StopDist;
          if ( v24 < 0.0 )
            v24 = 0.0;
          v25 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
          if ( v25 )
            Mass = UFG::VehicleSubjectComponent::GetMass(v25);
          else
            Mass = FLOAT_2000_0;
          IsBoat = UFG::AiDriverComponent::IsBoat(this);
          this->m_fDesiredSpeed = UFG::GetBrakingSpeedLimit(v24, this->m_fDesiredSpeed, Mass, IsBoat);
        }
        break;
      case 3u:
      case 4u:
      case 7u:
        updated = UFG::AiDriverComponent::UpdateChaseSpeed(this, seconds);
        v28 = this->m_pRoadSpace.m_pSimComponent;
        if ( BYTE4(v28[30].m_SafePointerList.mNode.mNext) && *((_BYTE *)&v28[1].m_SimObjIndex + 2)
          || LOBYTE(v28[8].m_Flags) )
        {
          p_m_fChaseSpeedLimit = (float *)&UFG::AiDriverComponent::m_TopSpeed;
          this->m_RoadSpeedLimit = v4;
          if ( this->m_fChaseSpeedLimit >= 0.0 )
            p_m_fChaseSpeedLimit = &this->m_fChaseSpeedLimit;
          if ( updated <= *p_m_fChaseSpeedLimit )
            updated = *p_m_fChaseSpeedLimit;
          v14 = updated;
LABEL_21:
          updated = UFG::AiDriverComponent::GetSpeedFromRoad(this, v14);
        }
        this->m_fDesiredSpeed = updated;
        break;
      case 5u:
        v30 = this->m_StopInfo.eStopStyle == EStopStyle_Powerslide;
        this->m_fDesiredSpeed = 35.0;
        if ( !v30 )
        {
          v31 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[17].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent);
          v32 = this->m_pRoadSpace.m_pSimComponent;
          v33 = (__m128)HIDWORD(v32[25].m_BoundComponentHandles.mNode.mPrev);
          v33.m128_f32[0] = (float)((float)((float)(v33.m128_f32[0] - v31[1]) * (float)(v33.m128_f32[0] - v31[1]))
                                  + (float)((float)(*(float *)&v32[25].m_BoundComponentHandles.mNode.mPrev - *v31)
                                          * (float)(*(float *)&v32[25].m_BoundComponentHandles.mNode.mPrev - *v31)))
                          + (float)((float)(*(float *)&v32[25].m_BoundComponentHandles.mNode.mNext - v31[2])
                                  * (float)(*(float *)&v32[25].m_BoundComponentHandles.mNode.mNext - v31[2]));
          v34 = _mm_sqrt_ps(v33).m128_f32[0] - this->m_StopDist;
          if ( v34 < 0.0 )
            v34 = 0.0;
          v35 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
          if ( v35 )
            v36 = UFG::VehicleSubjectComponent::GetMass(v35);
          else
            v36 = FLOAT_2000_0;
          v37 = UFG::AiDriverComponent::IsBoat(this);
          this->m_fDesiredSpeed = UFG::GetBrakingSpeedLimit(v34, this->m_fDesiredSpeed, v36, v37);
        }
        break;
      case 6u:
        if ( m_pSimComponent )
        {
          mNext = m_pSimComponent[26].m_SafePointerList.mNode.mNext;
          if ( mNext || (mNext = m_pSimComponent[26].m_SafePointerList.mNode.mPrev) != 0i64 )
          {
            if ( mNext[1].mPrev )
            {
              if ( this->m_fRaceSpeedLimit >= 0.0 )
                m_fRaceSpeedLimit = this->m_fRaceSpeedLimit;
              this->m_fDesiredSpeed = m_fRaceSpeedLimit;
            }
          }
        }
        this->m_fDesiredSpeed = (float)(UFG::AiDriverComponent::GetCatchupBoost(this) + 1.0) * this->m_fDesiredSpeed;
        break;
      default:
$LN3_62:
        this->m_fDesiredSpeed = 0.0;
        break;
    }
    m_DesiredSpeedLimit = this->m_DesiredSpeedLimit;
    if ( m_DesiredSpeedLimit >= 0.0 )
    {
      v40 = this->m_fDesiredSpeed;
      if ( v40 >= m_DesiredSpeedLimit )
        v40 = this->m_DesiredSpeedLimit;
      this->m_fDesiredSpeed = v40;
    }
  }
  else
  {
    v11 = (float)(m_fDelayedStopDecel * seconds) + m_fDesiredSpeed;
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
  UFG::SimComponent *m_pSimComponent; // rdi
  float v4; // xmm6_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  float RoadHolding; // xmm2_4
  float SpeedLimitForCurvature; // xmm0_4
  float SpeedForStopPoint; // xmm0_4
  float SpeedForNextGuide; // xmm0_4

  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  v4 = speedLimit;
  *(_WORD *)&this->m_CappingSpeedForStopPoint = 0;
  if ( !m_pSimComponent )
    return 0.0;
  if ( BYTE4(m_pSimComponent[30].m_SafePointerList.mNode.mNext) && *((_BYTE *)&m_pSimComponent[1].m_SimObjIndex + 2) )
  {
    mNext = m_pSimComponent[4].m_BoundComponentHandles.mNode.mNext;
    if ( !mNext || !LODWORD(mNext->mNext) )
      return 0.0;
  }
  else if ( LOBYTE(m_pSimComponent[8].m_Flags) )
  {
    RoadHolding = UFG::AiDriverComponent::GetRoadHolding(this);
    SpeedLimitForCurvature = UFG::GetSpeedLimitForCurvature(
                               *(float *)&m_pSimComponent[7].m_pSimObject,
                               speedLimit,
                               RoadHolding);
    v4 = SpeedLimitForCurvature;
    if ( this->m_bRespectSpeedLimit )
    {
      if ( this->m_ObeyTrafficLights )
      {
        SpeedForStopPoint = UFG::AiDriverComponent::GetSpeedForStopPoint(this, SpeedLimitForCurvature);
        if ( SpeedForStopPoint < v4 )
        {
          v4 = SpeedForStopPoint;
          this->m_CappingSpeedForStopPoint = 1;
        }
      }
      if ( !this->m_bAllowedToPass && !this->m_bTemporaryAllowedToPass )
      {
        SpeedForNextGuide = UFG::AiDriverComponent::GetSpeedForNextGuide(this, v4);
        if ( SpeedForNextGuide < v4 )
        {
          v4 = SpeedForNextGuide;
          this->m_CappingSpeedForNextGuide = 1;
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
  UFG::PhysicsMoverInterface *m_pSimComponent; // r14
  UFG::VehicleSubjectComponent *v5; // rcx
  bool v6; // r15
  UFG::PhysicsVehicle::Lod LOD; // eax
  float m_GettingUnstuckTimer; // xmm0_4
  bool v9; // bp
  float v10; // xmm10_4
  float m_BeenUnstuckTimer; // xmm0_4
  float m_fAvoidStopTimer; // xmm0_4
  float m_fReverseTimer; // xmm0_4
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
  __int64 v24; // rax
  float v25; // xmm0_4
  float v26; // xmm1_4
  float Output; // xmm0_4
  char v28; // dl
  float v29; // xmm3_4
  float v30; // xmm0_4
  int v31; // xmm0_4
  float v32; // xmm1_4
  int v33; // eax
  float v34; // xmm0_4
  UFG::RoadSpaceComponent *v35; // rax
  bool m_Attached; // r10
  bool v37; // r8
  bool v38; // dl
  UFG::RoadNetworkLane *m_CurrentLane; // rax
  float mGasBrakes; // xmm6_4
  int v41; // eax
  bool v42; // cl
  int v43; // eax

  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  *((_DWORD *)&m_pSimComponent->mInput + 4) &= ~4u;
  v5 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  v6 = v5 && UFG::VehicleSubjectComponent::IsBoat(v5);
  LOD = UFG::PhysicsMoverInterface::GetLOD((UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent);
  m_GettingUnstuckTimer = this->m_GettingUnstuckTimer;
  v9 = LOD != LOD_HIGH;
  v10 = *((float *)&this->mMoverComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1);
  this->m_fCurrentForwardSpeed = v10;
  if ( m_GettingUnstuckTimer >= 0.0 )
    this->m_GettingUnstuckTimer = m_GettingUnstuckTimer + seconds;
  m_BeenUnstuckTimer = this->m_BeenUnstuckTimer;
  if ( m_BeenUnstuckTimer >= 0.0 )
    this->m_BeenUnstuckTimer = m_BeenUnstuckTimer + seconds;
  m_fAvoidStopTimer = this->m_fAvoidStopTimer;
  if ( m_fAvoidStopTimer > 0.0 )
  {
    this->m_fDesiredSpeed = 0.0;
    this->m_fAvoidStopTimer = m_fAvoidStopTimer - seconds;
    goto LABEL_38;
  }
  m_fReverseTimer = this->m_fReverseTimer;
  if ( m_fReverseTimer > 0.0 )
  {
    this->m_fReverseTimer = m_fReverseTimer - seconds;
    v14 = this->m_pVehicleSubject.m_pSimComponent;
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
        v18 = this->m_pVehicleSubject.m_pSimComponent;
        if ( v18
          && (v19 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v18->vfptr[17].__vecDelDtor)(v18),
              (float)(v17 * v17) < (float)((float)((float)((float)(this->m_vStuckPosition.y - v19[1])
                                                         * (float)(this->m_vStuckPosition.y - v19[1]))
                                                 + (float)((float)(this->m_vStuckPosition.x - *v19)
                                                         * (float)(this->m_vStuckPosition.x - *v19)))
                                         + (float)((float)(this->m_vStuckPosition.z - v19[2])
                                                 * (float)(this->m_vStuckPosition.z - v19[2]))))
          || this->m_fReverseTimer <= 0.0 )
        {
          *((_DWORD *)&m_pSimComponent->mInput + 4) &= ~1u;
          *(_QWORD *)&this->m_fSteeringNoiseAmplitude = 0i64;
          this->m_fReverseTimer = 0.0;
        }
        else
        {
          v20 = *((_DWORD *)&m_pSimComponent->mInput + 4);
          m_pSimComponent->mInput.mSteering = 0.0;
          *((_DWORD *)&m_pSimComponent->mInput + 4) = v20 & 0xFFFFFFDE | 1;
          this->m_fDesiredSpeed = -10.0;
        }
        goto LABEL_38;
      }
    }
    v17 = v16;
    goto LABEL_17;
  }
  v21 = this->m_bAllowedToPass || this->m_bTemporaryAllowedToPass;
  if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this)
    && !v21
    || this->m_bGasBrakeLock
    || this->mModeGasBrakeLockEnabled
    || this->m_fDesiredSpeed <= 1.0
    || v10 >= 0.2 )
  {
    this->m_fStuckTimer = 0.0;
  }
  else
  {
    v22 = seconds + this->m_fStuckTimer;
    this->m_fStuckTimer = v22;
    if ( v22 > 3.0 )
    {
      this->m_fStuckTimer = 0.0;
      this->m_fReverseTimer = 3.0;
      UFG::AiDriverComponent::AddSteeringNoise(this, UFG::AiDriverComponent::m_fSteeringNoiseReverse);
      v23 = this->m_pVehicleSubject.m_pSimComponent;
      if ( v23 )
      {
        v24 = ((__int64 (__fastcall *)(UFG::SimComponent *))v23->vfptr[17].__vecDelDtor)(v23);
        v25 = *(float *)(v24 + 4);
        v26 = *(float *)(v24 + 8);
        this->m_vStuckPosition.x = *(float *)v24;
        this->m_vStuckPosition.y = v25;
        this->m_vStuckPosition.z = v26;
      }
      this->m_BeenUnstuckTimer = 0.0;
      if ( this->m_GettingUnstuckTimer < 0.0 )
        this->m_GettingUnstuckTimer = 0.0;
    }
  }
LABEL_38:
  if ( this->m_BeenUnstuckTimer >= 9.0 )
  {
    this->m_GettingUnstuckTimer = -1.0;
    this->m_BeenUnstuckTimer = -1.0;
  }
  UFG::qPidControllerCore::Record(&this->m_ThrottlePid, this->m_fDesiredSpeed - v10, seconds, 0i64);
  Output = UFG::qPidControllerCore::GetOutput(&this->m_ThrottlePid);
  v28 = 0;
  v29 = seconds * 10.0;
  if ( !this->m_bGasBrakeLock )
  {
    if ( this->mModeGasBrakeLockEnabled )
    {
      m_pSimComponent->mInput.mGasBrakes = this->mModeGasBrakeLock;
      goto LABEL_90;
    }
    if ( v9 )
    {
      v30 = Output * -0.5;
      if ( v30 <= -1.0 )
      {
        v30 = FLOAT_N1_0;
      }
      else if ( v30 >= 1.0 )
      {
        LODWORD(m_pSimComponent->mInput.mGasBrakes) = (_DWORD)FLOAT_1_0;
        goto LABEL_90;
      }
      m_pSimComponent->mInput.mGasBrakes = v30;
      goto LABEL_90;
    }
    v31 = LODWORD(Output) ^ _xmm[0];
    if ( *(float *)&v31 <= COERCE_FLOAT(LODWORD(v29) ^ _xmm[0]) )
      v31 = LODWORD(v29) ^ _xmm[0];
    if ( *(float *)&v31 >= v29 )
      *(float *)&v31 = seconds * 10.0;
    v32 = this->m_fPreviousGasBrakes + *(float *)&v31;
    if ( v32 <= -1.0 )
    {
      v32 = FLOAT_N1_0;
    }
    else if ( v32 >= 1.0 )
    {
      v32 = *(float *)&FLOAT_1_0;
    }
    v33 = *((_DWORD *)&m_pSimComponent->mInput + 4);
    if ( (v33 & 1) != 0 )
      v32 = v32 * -1.0;
    if ( (v33 & 0x20) != 0 )
      v32 = FLOAT_N1_0;
    if ( v32 <= COERCE_FLOAT(COERCE_UNSIGNED_INT(
                               1.0
                             - (float)((float)(m_pSimComponent->mInput.mSteering * m_pSimComponent->mInput.mSteering)
                                     * 0.2)) ^ _xmm[0]) )
      LODWORD(v32) = COERCE_UNSIGNED_INT(
                       1.0
                     - (float)((float)(m_pSimComponent->mInput.mSteering * m_pSimComponent->mInput.mSteering) * 0.2)) ^ _xmm[0];
    LODWORD(v34) = LODWORD(this->m_fDesiredSpeed) & _xmm;
    if ( v34 < 0.0099999998 && v32 <= 0.0 )
      v32 = 0.0;
    v35 = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
    m_Attached = v35->mGuide.m_Attached;
    v37 = this->m_CappingSpeedForStopPoint || this->m_CappingSpeedForNextGuide;
    v38 = v34 < 1.5 && COERCE_FLOAT(LODWORD(v10) & _xmm) < 1.5;
    m_CurrentLane = v35->mGuide.m_CurrentLocation.m_CurrentLane;
    if ( m_CurrentLane )
    {
      if ( m_CurrentLane->mNode.mOffset )
        LOBYTE(m_CurrentLane) = *(_WORD *)((char *)&m_CurrentLane->mNode.mOffset + m_CurrentLane->mNode.mOffset) == 1;
      else
        LOBYTE(m_CurrentLane) = (_WORD)MEMORY[0] == 1;
    }
    if ( !v6 && m_Attached && v37 && v38 && !(_BYTE)m_CurrentLane )
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
        m_pSimComponent->mInput.mGasBrakes = v32;
        goto LABEL_90;
      }
    }
    if ( v34 < 0.0099999998 && COERCE_FLOAT(LODWORD(v10) & _xmm) < 0.69999999 )
      v32 = *(float *)&FLOAT_1_0;
    goto LABEL_89;
  }
  m_pSimComponent->mInput.mGasBrakes = this->m_fGasBrakeLock;
LABEL_90:
  if ( !this->m_DrivingMode && this->m_StopInfo.eStopStyle == EStopStyle_Powerslide )
    *((_DWORD *)&m_pSimComponent->mInput + 4) |= 4u;
  mGasBrakes = m_pSimComponent->mInput.mGasBrakes;
  if ( (*((_BYTE *)&m_pSimComponent->mInput + 16) & 4) != 0 || mGasBrakes > 0.99000001 )
    this->m_fBrakeTimer = seconds + this->m_fBrakeTimer;
  else
    this->m_fBrakeTimer = 0.0;
  v41 = *((_DWORD *)&m_pSimComponent->mInput + 4);
  v42 = (v41 & 0x20) == 0
     && this->m_fBrakeTimer > 1.0
     && COERCE_FLOAT(LODWORD(this->m_fDesiredSpeed) & _xmm) < 0.1
     && COERCE_FLOAT(LODWORD(v10) & _xmm) < 2.0;
  if ( (v41 & 4) == 0 && !v6 && v42 )
    *((_DWORD *)&m_pSimComponent->mInput + 4) = v41 | 4;
  if ( COERCE_FLOAT(LODWORD(this->m_fDesiredSpeed) & _xmm) < 0.090000004 || v28 )
    v28 = 1;
  v43 = *((_DWORD *)&m_pSimComponent->mInput + 4);
  if ( (v43 & 4) == 0 && v28 && v10 < 0.090000004 )
    *((_DWORD *)&m_pSimComponent->mInput + 4) = v43 | 4;
  if ( v42 )
  {
    *((_BYTE *)&this->m_StopInfo + 8) &= ~1u;
    *(_QWORD *)&this->m_StopInfo.eStopStyle = 0i64;
  }
  if ( this->mRenderComponent.m_pSimComponent )
  {
    if ( mGasBrakes > 0.1
      || this->m_fDesiredSpeed < 0.1
      || UFG::VehicleSubjectComponent::IsBike((UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent)
      && (*((_BYTE *)&m_pSimComponent->mInput + 16) & 4) != 0 )
    {
      UFG::VehicleEffectsComponent::TurnOnBrakelights((UFG::VehicleEffectsComponent *)this->mRenderComponent.m_pSimComponent);
    }
    else
    {
      UFG::VehicleEffectsComponent::TurnOffBrakelights((UFG::VehicleEffectsComponent *)this->mRenderComponent.m_pSimComponent);
    }
  }
  if ( (*((_BYTE *)&m_pSimComponent->mInput + 16) & 1) != 0 )
    mGasBrakes = mGasBrakes * -1.0;
  this->m_fPreviousGasBrakes = mGasBrakes;
}

// File Line: 3439
// RVA: 0x651020
bool __fastcall UFG::AiDriverComponent::GetUnstuckFailed(UFG::AiDriverComponent *this)
{
  return this->m_GettingUnstuckTimer > 22.0;
}

// File Line: 3444
// RVA: 0x659970
void __fastcall UFG::AiDriverComponent::SetSteeringNoiseMin(UFG::AiDriverComponent *this, float min_amplitude)
{
  float m_fSteeringNoiseAmplitude; // xmm0_4

  this->m_fSteeringNoiseAmplitudeMin = min_amplitude;
  m_fSteeringNoiseAmplitude = this->m_fSteeringNoiseAmplitude;
  if ( m_fSteeringNoiseAmplitude <= min_amplitude )
    this->m_fSteeringNoiseAmplitude = min_amplitude;
  else
    this->m_fSteeringNoiseAmplitude = m_fSteeringNoiseAmplitude;
}

// File Line: 3450
// RVA: 0x644D90
void __fastcall UFG::AiDriverComponent::AddSteeringNoise(UFG::AiDriverComponent *this, float amplitude)
{
  float m_fSteeringNoiseAmplitude; // xmm0_4

  m_fSteeringNoiseAmplitude = this->m_fSteeringNoiseAmplitude;
  if ( m_fSteeringNoiseAmplitude < amplitude )
  {
    if ( m_fSteeringNoiseAmplitude <= 0.0 )
    {
      this->m_fSteeringNoiseTimer = UFG::qRandom(511.0, (unsigned int *)&UFG::qDefaultSeed);
      UFG::qNoise<float,float>::SetFrequency(
        &this->m_SteeringNoise,
        UFG::AiDriverComponent::m_fSteeringNoiseFrequency,
        0.0);
    }
    this->m_fSteeringNoiseAmplitude = amplitude;
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
  UFG::DrivingTargetOffsetMover *p_m_OffsetMover; // rsi
  Render::DebugDrawContext *Context; // r15
  float m_fPassingTimer; // xmm0_4
  char v7; // r12
  float v8; // xmm0_4
  float m_fSteeringNoiseAmplitudeMin; // xmm0_4
  UFG::VehicleSubjectComponent *m_pSimComponent; // rcx
  float v11; // xmm8_4
  bool v12; // r14
  bool v13; // bl
  float steer_to_distance; // xmm7_4
  UFG::qVector4 *v15; // rax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float x; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm5_4
  double v22; // xmm0_8
  float w; // xmm4_4
  float z; // xmm3_4
  float v25; // xmm5_4
  float v26; // xmm7_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pComponent; // rbx
  float v31; // xmm13_4
  float y; // xmm14_4
  float v33; // xmm9_4
  float *v34; // rax
  float v35; // xmm5_4
  __m128 v36; // xmm4
  float v37; // xmm6_4
  unsigned int m_DrivingMode; // eax
  __m128 v39; // xmm2
  float v40; // xmm3_4
  UFG::qVector3 *SteerTo; // rax
  float v42; // xmm1_4
  float v43; // xmm0_4
  unsigned int v44; // ecx
  float v45; // xmm9_4
  float v46; // xmm10_4
  bool v47; // r13
  float v48; // xmm11_4
  UFG::SimComponent *v49; // rax
  bool v50; // al
  UFG::VehicleSubjectComponent *v51; // rcx
  bool v52; // bl
  UFG::VehicleSubjectComponent *v53; // rcx
  float Mass; // xmm0_4
  UFG::qVector3 *SteerToRace; // rax
  float v56; // xmm1_4
  float v57; // xmm2_4
  bool v58; // zf
  UFG::VehicleSubjectComponent *v59; // rcx
  bool v60; // r9
  UFG::qVector3 *v61; // rax
  float v62; // xmm1_4
  float v63; // xmm2_4
  UFG::SimComponent *v64; // rcx
  bool v65; // r14
  bool v66; // r15
  bool v67; // bl
  bool v68; // si
  UFG::SimComponent *m_pPointer; // rcx
  bool v70; // cl
  bool v71; // al
  float v72; // xmm0_4
  UFG::qVector3 *v73; // rax
  float v74; // xmm1_4
  float v75; // xmm2_4
  Render::DebugDrawContext *v76; // rbx
  char v77; // si
  float v78; // xmm11_4
  char v79; // bl
  float v80; // xmm3_4
  float v81; // xmm4_4
  float v82; // xmm5_4
  char v83; // al
  bool v84; // dl
  bool v85; // cl
  float v86; // xmm3_4
  float v87; // xmm2_4
  float v88; // xmm1_4
  float v89; // xmm0_4
  UFG::PhysicsMoverInterface *v90; // rcx
  float v91; // xmm0_4
  float v92; // xmm7_4
  float Output; // xmm0_4
  float v94; // xmm9_4
  UFG::SimComponent *v95; // rbx
  float fSteeringOverride; // xmm0_4
  bool v97; // si
  double v98; // xmm0_8
  float m_fSteeringNoiseAmplitude; // xmm1_4
  float v100; // xmm0_4
  float v101; // xmm4_4
  float v102; // xmm3_4
  float v103; // xmm2_4
  float v104; // xmm6_4
  int v105; // ecx
  float m_fSteeringScale; // xmm1_4
  float v107; // xmm0_4
  bool v108; // dl
  unsigned int m_DrivingRole; // r8d
  char v110; // r9
  char v111; // r8
  float v112; // xmm1_4
  float v113; // xmm2_4
  float v114; // xmm3_4
  float v115; // xmm0_4
  float v116; // xmm8_4
  float v117; // xmm6_4
  float RoadHolding; // xmm2_4
  float SpeedLimitForCurvature; // xmm0_4
  UFG::qVector3 v120; // [rsp+40h] [rbp-80h] BYREF
  float v121; // [rsp+4Ch] [rbp-74h]
  UFG::qVector3 result; // [rsp+50h] [rbp-70h] BYREF
  UFG::qVector3 p1; // [rsp+60h] [rbp-60h] BYREF
  UFG::qVector3 p0; // [rsp+70h] [rbp-50h] BYREF
  float speed_limit; // [rsp+140h] [rbp+80h] BYREF
  float constrained_by_road[2]; // [rsp+148h] [rbp+88h] BYREF
  bool v127; // [rsp+150h] [rbp+90h]
  Render::DebugDrawContext *v128; // [rsp+158h] [rbp+98h]

  p_m_OffsetMover = &this->m_OffsetMover;
  UFG::DrivingTargetOffsetMover::Update(&this->m_OffsetMover, seconds);
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  v128 = Context;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  m_fPassingTimer = this->m_fPassingTimer;
  v7 = 0;
  if ( m_fPassingTimer > 0.0 )
  {
    v8 = m_fPassingTimer - seconds;
    this->m_fPassingTimer = v8;
    if ( v8 <= 0.0 )
      this->m_fPassingBias = 0.0;
  }
  m_fSteeringNoiseAmplitudeMin = this->m_fSteeringNoiseAmplitudeMin;
  if ( m_fSteeringNoiseAmplitudeMin <= (float)((float)(1.0
                                                     - (float)(UFG::AiDriverComponent::m_fSteeringNoiseAmplitudeDecay
                                                             * seconds))
                                             * this->m_fSteeringNoiseAmplitude) )
    m_fSteeringNoiseAmplitudeMin = (float)(1.0
                                         - (float)(UFG::AiDriverComponent::m_fSteeringNoiseAmplitudeDecay * seconds))
                                 * this->m_fSteeringNoiseAmplitude;
  this->m_fSteeringNoiseAmplitude = m_fSteeringNoiseAmplitudeMin;
  if ( m_fSteeringNoiseAmplitudeMin <= 0.001 )
    this->m_fSteeringNoiseAmplitude = 0.0;
  else
    this->m_fSteeringNoiseTimer = seconds + this->m_fSteeringNoiseTimer;
  m_pSimComponent = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  v11 = *((float *)&this->mMoverComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1);
  v12 = this->m_CurrentAttack != NumAttacks;
  LOBYTE(constrained_by_road[0]) = v12;
  v13 = m_pSimComponent && UFG::VehicleSubjectComponent::IsBoat(m_pSimComponent);
  steer_to_distance = FLOAT_5_0;
  if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this) )
  {
    if ( v13 )
    {
      v22 = ((double (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[21].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent);
      if ( UFG::AiDriverComponent::m_SteerDistanceRampBoat.z >= UFG::AiDriverComponent::m_SteerDistanceRampBoat.w )
        w = UFG::AiDriverComponent::m_SteerDistanceRampBoat.w;
      else
        w = UFG::AiDriverComponent::m_SteerDistanceRampBoat.z;
      if ( UFG::AiDriverComponent::m_SteerDistanceRampBoat.z <= UFG::AiDriverComponent::m_SteerDistanceRampBoat.w )
        z = UFG::AiDriverComponent::m_SteerDistanceRampBoat.w;
      else
        z = UFG::AiDriverComponent::m_SteerDistanceRampBoat.z;
      v25 = FLOAT_0_000099999997;
      if ( (float)(UFG::AiDriverComponent::m_SteerDistanceRampBoat.y - UFG::AiDriverComponent::m_SteerDistanceRampBoat.x) >= 0.000099999997 )
        v25 = UFG::AiDriverComponent::m_SteerDistanceRampBoat.y - UFG::AiDriverComponent::m_SteerDistanceRampBoat.x;
      v26 = (float)((float)(v11 - UFG::AiDriverComponent::m_SteerDistanceRampBoat.x)
                  * (float)((float)(UFG::AiDriverComponent::m_SteerDistanceRampBoat.w
                                  - UFG::AiDriverComponent::m_SteerDistanceRampBoat.z)
                          / v25))
          + UFG::AiDriverComponent::m_SteerDistanceRampBoat.z;
      if ( v26 <= w )
        v26 = w;
      if ( v26 >= z )
        v26 = z;
      steer_to_distance = v26 + *(float *)&v22;
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
    x = v15->x;
    if ( v17 >= v16 )
      v19 = v15->w;
    else
      v19 = v15->z;
    if ( v17 <= v16 )
      v20 = v15->w;
    else
      v20 = v15->z;
    v21 = FLOAT_0_000099999997;
    if ( (float)(v15->y - x) >= 0.000099999997 )
      v21 = v15->y - x;
    steer_to_distance = (float)((float)(v11 - x) * (float)((float)(v16 - v17) / v21)) + v17;
    if ( steer_to_distance <= v19 )
      steer_to_distance = v19;
    if ( steer_to_distance >= v20 )
      steer_to_distance = v20;
  }
  v27 = *(float *)&FLOAT_1_0;
  if ( steer_to_distance <= 1.0 || (v28 = FLOAT_100_0, v27 = steer_to_distance, steer_to_distance < 100.0) )
    v28 = v27;
  *(float *)&this->m_pRoadSpace.m_pSimComponent[8].vfptr = v28;
  this->m_fAvoidSteerLimit = 0.0;
  if ( this->m_bTemporaryAllowedToPass )
  {
    if ( v13 )
      this->m_fAvoidSteerLimit = FLOAT_N1_0;
    else
      this->m_fAvoidSteerLimit = UFG::AiDriverComponent::m_AvoidTemporaryLimit;
  }
  else if ( this->m_bAllowedToPass )
  {
    this->m_fAvoidSteerLimit = -1.0;
  }
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pComponent = (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent;
  else
    m_pComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
  v31 = m_pComponent->mWorldTransform.v3.x;
  y = m_pComponent->mWorldTransform.v3.y;
  v33 = m_pComponent->mWorldTransform.v3.z;
  v34 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[16].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent);
  v35 = v34[1];
  v36 = (__m128)*(unsigned int *)v34;
  v37 = v34[2];
  m_DrivingMode = this->m_DrivingMode;
  v39 = v36;
  v39.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v35 * v35)) + (float)(v37 * v37);
  v40 = steer_to_distance / _mm_sqrt_ps(v39).m128_f32[0];
  result.x = (float)(v36.m128_f32[0] * v40) + v31;
  result.y = (float)(v35 * v40) + y;
  result.z = (float)(v37 * v40) + v33;
  if ( m_DrivingMode )
  {
    if ( m_DrivingMode <= 4 )
    {
LABEL_63:
      SteerTo = UFG::RoadSpaceComponent::GetSteerTo(
                  (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent,
                  &result,
                  &result,
                  p_m_OffsetMover->m_CurrentLateralOffset,
                  steer_to_distance);
LABEL_64:
      v42 = SteerTo->y;
      v43 = SteerTo->x;
      result.z = SteerTo->z;
      result.y = v42;
      result.x = v43;
      goto LABEL_65;
    }
    if ( m_DrivingMode == 5 )
    {
      v59 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
      v60 = v59 && UFG::VehicleSubjectComponent::IsBoat(v59);
      SteerTo = UFG::RoadSpaceComponent::GetSteerToDestination(
                  (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent,
                  &p1,
                  steer_to_distance,
                  v60,
                  this->m_StopAtUseDestinationDirection);
      goto LABEL_64;
    }
    if ( m_DrivingMode != 6 )
    {
      if ( m_DrivingMode != 7 )
        goto LABEL_65;
      goto LABEL_63;
    }
    v51 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
    speed_limit = this->m_fDesiredSpeed;
    v52 = v51 && UFG::VehicleSubjectComponent::IsBoat(v51);
    v53 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
    if ( v53 )
      Mass = UFG::VehicleSubjectComponent::GetMass(v53);
    else
      Mass = FLOAT_2000_0;
    SteerToRace = UFG::RoadSpaceComponent::GetSteerToRace(
                    (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent,
                    &p0,
                    steer_to_distance,
                    &speed_limit,
                    Mass,
                    v52);
    v56 = SteerToRace->y;
    v57 = SteerToRace->z;
    result.x = SteerToRace->x;
    result.y = v56;
    v58 = speed_limit == this->m_fDesiredSpeed;
    result.z = v57;
    if ( !v58 )
      this->m_fDesiredSpeed = speed_limit;
  }
LABEL_65:
  if ( this->m_AvoidanceDebug )
  {
    p1.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + result.x;
    p1.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + result.z;
    p1.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + result.y;
    p0.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + v31;
    p0.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + y;
    p0.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + v33;
    Render::DebugDrawContext::DrawLine(Context, &p0, &p1, &UFG::qColour::Yellow, &UFG::qMatrix44::msIdentity, 0i64, 0);
    p0.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + result.z;
    p0.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + result.x;
    p0.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + result.y;
    Render::DebugDrawContext::DrawSphere(Context, &p0, 0.5, &UFG::qColour::Yellow, &UFG::qMatrix44::msIdentity, 0i64);
  }
  v44 = this->m_DrivingMode;
  v45 = result.x;
  v46 = result.y;
  this->m_fFollowOffsetBlend = 0.0;
  v47 = v44 == 1;
  v48 = result.z;
  v127 = v44 == 2;
  if ( ((v44 - 3) & 0xFFFFFFFA) == 0 && v44 != 8 )
    v7 = 1;
  v49 = this->m_pRoadSpace.m_pSimComponent;
  LOBYTE(speed_limit) = v44 == 6;
  v50 = BYTE4(v49[30].m_SafePointerList.mNode.mNext) && *((_BYTE *)&v49[1].m_SimObjIndex + 2) || LOBYTE(v49[8].m_Flags);
  if ( !v7 || v50 )
  {
    this->m_fTimeNearOffset = 0.0;
  }
  else
  {
    v61 = UFG::AiDriverComponent::SteerToFollowOffset(this, &result, seconds, steer_to_distance, &result);
    v62 = v61->y;
    v63 = v61->z;
    result.x = v61->x;
    result.y = v62;
    result.z = v63;
  }
  v64 = this->m_pVehicleSubject.m_pSimComponent;
  v65 = this->m_DrivingRole == 2;
  v66 = this->m_pEscortEnemyVehicleSubject.m_pPointer != 0i64;
  v67 = v64 && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))v64->vfptr[30].__vecDelDtor)(v64);
  v68 = this->m_fFollowOffsetBlend > 0.0 && UFG::AiDriverComponent::m_fReactionTimeStart < this->m_fTimeNearOffset;
  m_pPointer = this->m_pChaseVehicleSubject.m_pPointer;
  v70 = m_pPointer
     && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))m_pPointer->vfptr[46].__vecDelDtor)(m_pPointer);
  v71 = this->m_DrivingMode == 3 && this->m_DesiredOffset == Behind;
  if ( (v67 || v65) && v70 && !v71 && !v66 && !LOBYTE(constrained_by_road[0]) && v68 )
  {
    v72 = seconds + this->m_fReactionTime;
    if ( v72 >= UFG::AiDriverComponent::m_fReactionTimeMax )
      v72 = UFG::AiDriverComponent::m_fReactionTimeMax;
  }
  else
  {
    v72 = 0.0;
  }
  this->m_fReactionTime = v72;
  if ( v47 )
  {
    v73 = UFG::AiDriverComponent::SteerToBetterLane(this, &result, &result);
    v74 = v73->y;
    v75 = v73->z;
    result.x = v73->x;
    result.y = v74;
    result.z = v75;
  }
  if ( this->m_AvoidanceDebug )
  {
    v76 = v128;
    p0.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + result.x;
    p0.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + result.z;
    p0.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + result.y;
    p1.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + v45;
    p1.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + v46;
    p1.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + v48;
    Render::DebugDrawContext::DrawLine(v128, &p1, &p0, &UFG::qColour::Lime, &UFG::qMatrix44::msIdentity, 0i64, 0);
    p0.z = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + result.z;
    p0.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + result.x;
    p0.y = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + result.y;
    Render::DebugDrawContext::DrawSphere(v76, &p0, 0.44999999, &UFG::qColour::Lime, &UFG::qMatrix44::msIdentity, 0i64);
  }
  v77 = 0;
  v58 = this->m_DrivingMode == 3;
  v78 = steer_to_distance;
  LOBYTE(constrained_by_road[0]) = 0;
  *(float *)&v128 = steer_to_distance;
  if ( v58 )
  {
    UFG::AiDriverComponent::SteerToWithinRoad(this, &p0, (bool *)constrained_by_road, &result);
    v77 = LOBYTE(constrained_by_road[0]);
    result = p0;
  }
  v79 = 0;
  if ( this->m_AvoidObjectsEnabled )
  {
    constrained_by_road[0] = this->m_fDesiredSpeed;
    UFG::AiDriverComponent::SteerToAvoidObjects(this, &p0, &result, steer_to_distance);
    v80 = p0.x;
    v81 = p0.y;
    v82 = p0.z;
    if ( (float)((float)((float)((float)(result.y - p0.y) * (float)(result.y - p0.y))
                       + (float)((float)(result.x - p0.x) * (float)(result.x - p0.x)))
               + (float)((float)(result.z - p0.z) * (float)(result.z - p0.z))) <= 0.010000001
      && constrained_by_road[0] == this->m_fDesiredSpeed )
    {
      v79 = 0;
    }
    else
    {
      v79 = 1;
      if ( constrained_by_road[0] != this->m_fDesiredSpeed )
        this->m_fDesiredSpeed = constrained_by_road[0];
    }
    v78 = *(float *)&v128;
    result.x = v80;
    result.y = v81;
    result.z = v82;
  }
  v83 = 0;
  v84 = 0;
  if ( v7 )
    v83 = 1;
  if ( LOBYTE(speed_limit) )
    v83 = 1;
  v85 = this->m_bAllowedToPass || this->m_bTemporaryAllowedToPass;
  if ( (v47 || v127) && v85 )
    v83 = 1;
  if ( this->m_AvoidGeoEnabled && v83 )
  {
    UFG::AiDriverComponent::SteerToAvoidGeometry(this, &p0, &result, steer_to_distance);
    v78 = *(float *)&v128;
    v86 = (float)((float)((float)(result.y - p0.y) * (float)(result.y - p0.y))
                + (float)((float)(result.x - p0.x) * (float)(result.x - p0.x)))
        + (float)((float)(result.z - p0.z) * (float)(result.z - p0.z));
    result = p0;
    v84 = v86 > 0.010000001;
  }
  if ( v79 || v84 || v77 )
    this->m_fReactionTime = 0.0;
  v87 = result.x;
  v88 = result.y;
  v89 = result.z;
  v90 = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  this->m_vSteerToPosition.x = result.x;
  this->m_vSteerToPosition.y = v88;
  v120.z = v87 - v31;
  this->m_vSteerToPosition.z = v89;
  v121 = v88 - y;
  UFG::PhysicsMoverInterface::GetFacingDirection(v90, &v120);
  v91 = UFG::qAngleBetween((UFG::qVector2 *)&v120.z, (UFG::qVector2 *)&v120);
  v92 = v91;
  if ( v91 < -3.1415927 )
    v92 = v91 + 6.2831855;
  if ( v92 > 3.1415927 )
    v92 = v92 + -6.2831855;
  UFG::qPidControllerCore::Record(&this->m_SteeringPid, v92, seconds, 0i64);
  Output = UFG::qPidControllerCore::GetOutput(&this->m_SteeringPid);
  v94 = Output;
  if ( this->m_fReverseTimer > 0.0 )
    v94 = Output * -0.80000001;
  v95 = this->mMoverComponent.m_pSimComponent;
  LODWORD(v95[1].m_pSimObject) &= ~0x20u;
  if ( this->m_bSteeringLock )
  {
    v95[1].m_TypeUID = LODWORD(this->m_fSteeringLock);
    return;
  }
  if ( this->mModeSteeringLockEnabled )
  {
    v95[1].m_TypeUID = LODWORD(this->mModeSteeringLock);
    return;
  }
  if ( this->m_DrivingMode || (*((_BYTE *)&this->m_StopInfo + 8) & 1) == 0 )
  {
    v97 = UFG::PhysicsMoverInterface::GetLOD((UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent) == LOD_HIGH;
    v98 = ((double (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[28].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent);
    if ( v97 )
    {
      if ( *(float *)&v98 <= 0.30000001 && this->m_fDesiredSpeed <= 0.30000001 )
        return;
    }
    else if ( *(float *)&v98 <= 0.30000001 )
    {
      return;
    }
    m_fSteeringNoiseAmplitude = this->m_fSteeringNoiseAmplitude;
    v100 = 0.0;
    if ( m_fSteeringNoiseAmplitude <= 0.0 )
      v101 = this->m_fSteeringNoiseAmplitude;
    else
      v101 = 0.0;
    if ( m_fSteeringNoiseAmplitude >= 0.0 )
      v102 = this->m_fSteeringNoiseAmplitude;
    else
      v102 = 0.0;
    v103 = *(float *)&FLOAT_1_0;
    v104 = (float)(COERCE_FLOAT(LODWORD(v11) & _xmm) - 1.0) * (float)(m_fSteeringNoiseAmplitude * 0.25);
    if ( v104 <= v101 )
      v104 = v101;
    if ( v104 >= v102 )
      v104 = v102;
    if ( v104 != 0.0 )
    {
      v103 = *(float *)&FLOAT_1_0;
      v100 = UFG::qNoise<float,float>::GetValue(
               &this->m_SteeringNoise,
               COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_fSteeringNoiseTimer)))
           * v104;
    }
    v105 = (int)v95[1].m_pSimObject;
    if ( (v105 & 0x80u) != 0 )
      goto LABEL_195;
    if ( v97 )
      m_fSteeringScale = this->m_fSteeringScale;
    else
      m_fSteeringScale = v103;
    v107 = (float)(v100 + v94) * m_fSteeringScale;
    if ( v107 <= -1.0 )
    {
      v107 = FLOAT_N1_0;
    }
    else if ( v107 >= v103 )
    {
      goto LABEL_194;
    }
    v103 = v107;
LABEL_194:
    *(float *)&v95[1].m_TypeUID = v103;
LABEL_195:
    v108 = this->m_bAllowedToPass || this->m_bTemporaryAllowedToPass;
    m_DrivingRole = this->m_DrivingRole;
    v110 = 1;
    if ( m_DrivingRole - 1 <= 2 || m_DrivingRole == 5 )
      v108 = 1;
    else
      v110 = 0;
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
    if ( v92 < COERCE_FLOAT(LODWORD(v116) ^ _xmm[0]) || v92 > v116 )
      v111 = 1;
    if ( v110 && v111 )
      LODWORD(v95[1].m_pSimObject) = v105 | 0x20;
    if ( v108 )
    {
      v117 = FLOAT_2_0;
      if ( v78 >= 2.0 )
        v117 = v78;
      RoadHolding = UFG::AiDriverComponent::GetRoadHolding(this);
      SpeedLimitForCurvature = UFG::GetSpeedLimitForCurvature(v92 / v117, this->m_fDesiredSpeed, RoadHolding);
      if ( SpeedLimitForCurvature != this->m_fDesiredSpeed )
        this->m_fDesiredSpeed = SpeedLimitForCurvature;
    }
    return;
  }
  fSteeringOverride = this->m_StopInfo.fSteeringOverride;
  if ( fSteeringOverride <= -1.0 )
  {
    fSteeringOverride = FLOAT_N1_0;
  }
  else if ( fSteeringOverride >= 1.0 )
  {
    v95[1].m_TypeUID = (unsigned int)FLOAT_1_0;
    return;
  }
  *(float *)&v95[1].m_TypeUID = fSteeringOverride;
}

// File Line: 4008
// RVA: 0x65E5E0
UFG::qVector3 *__fastcall UFG::AiDriverComponent::SteerToWithinRoad(
        UFG::AiDriverComponent *this,
        UFG::qVector3 *result,
        bool *constrained_by_road,
        UFG::qVector3 *steer_to_position)
{
  UFG::SimObjectGame *m_pSimObject; // rdi
  __int16 m_Flags; // cx
  UFG::RoadSpaceComponent *m_pComponent; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *m_pSimComponent; // rcx
  unsigned int m_TypeUID; // eax
  UFG::SimObject **p_m_pSimObject; // rcx
  UFG::RoadNetworkGraph *p_m_TrafficGraph; // rbp
  __int16 v15; // r13
  unsigned __int16 v16; // r14
  UFG::SimObject *v17; // rax
  UFG::TransformNodeComponent *v18; // rbp
  UFG::RoadSpaceComponent *v19; // rcx
  float y; // xmm1_4
  float z; // xmm2_4
  __int16 v22; // cx
  UFG::SimComponent *v23; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v25; // rax
  float v26; // xmm1_4
  float v27; // xmm2_4
  UFG::qVector3 *v28; // rax
  float x; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // xmm2_4
  UFG::qVector3 targetPos; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 resulta; // [rsp+30h] [rbp-38h] BYREF

  *constrained_by_road = 0;
  *result = *steer_to_position;
  m_pSimObject = (UFG::SimObjectGame *)this->m_pRoadSpace.m_pSimComponent[26].m_pSimObject;
  if ( !m_pSimObject )
    return result;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::RoadSpaceComponent *)m_pSimObject->m_Components.p[24].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::RoadSpaceComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::RoadSpaceComponent::_TypeUID);
    m_pComponent = (UFG::RoadSpaceComponent *)ComponentOfTypeHK;
  }
  else
  {
    m_pComponent = (UFG::RoadSpaceComponent *)m_pSimObject->m_Components.p[24].m_pComponent;
  }
  if ( !m_pComponent )
    return result;
  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  m_TypeUID = m_pSimComponent[25].m_TypeUID;
  p_m_pSimObject = &m_pSimComponent[8].m_pSimObject;
  if ( m_TypeUID != m_pComponent->mWayClient.m_RoadNetworkType || m_TypeUID )
    return result;
  p_m_TrafficGraph = &UFG::WheeledVehicleManager::m_Instance->m_NavigationData->m_TrafficGraph;
  if ( UFG::WheeledVehicleManager::m_Instance->m_NavigationData != (UFG::WheeledVehicleNavigationData *)-32i64 )
  {
    v15 = ((__int64 (__fastcall *)(UFG::SimObject **, UFG::RoadNetworkGraph *))(*p_m_pSimObject)->mNode.mChild[1])(
            p_m_pSimObject,
            p_m_TrafficGraph);
    v16 = m_pComponent->mWayClient.vfptr->GetWayEdge(&m_pComponent->mWayClient, p_m_TrafficGraph);
    v17 = this->m_pSimObject;
    if ( v17 )
      v18 = (UFG::TransformNodeComponent *)v17->m_Components.p[2].m_pComponent;
    else
      v18 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v18);
    v19 = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
    y = v18->mWorldTransform.v3.y;
    z = v18->mWorldTransform.v3.z;
    targetPos.x = v18->mWorldTransform.v3.x;
    targetPos.y = y;
    targetPos.z = z;
    if ( v15 == v16 )
    {
      v22 = m_pSimObject->m_Flags;
      if ( (v22 & 0x4000) != 0 )
      {
        v23 = m_pSimObject->m_Components.p[37].m_pComponent;
      }
      else if ( v22 >= 0 )
      {
        if ( (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::CameraSubject::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CameraSubject::_TypeUID);
        v23 = ComponentOfType;
      }
      else
      {
        v23 = m_pSimObject->m_Components.p[31].m_pComponent;
      }
      v25 = ((__int64 (__fastcall *)(UFG::SimComponent *))v23->vfptr[17].__vecDelDtor)(v23);
      v19 = m_pComponent;
      v26 = *(float *)(v25 + 4);
      v27 = *(float *)(v25 + 8);
      targetPos.x = *(float *)v25;
      targetPos.y = v26;
      targetPos.z = v27;
    }
    v28 = UFG::RoadSpaceComponent::ClampToRoad(v19, &resulta, steer_to_position, &targetPos);
    x = v28->x;
    v30 = v28->y;
    v31 = v28->z;
    v32 = (float)((float)((float)(steer_to_position->y - v30) * (float)(steer_to_position->y - v30))
                + (float)((float)(steer_to_position->x - x) * (float)(steer_to_position->x - x)))
        + (float)((float)(steer_to_position->z - v31) * (float)(steer_to_position->z - v31));
    if ( v32 >= 0.010000001 && v32 <= 64.0 )
    {
      result->x = x;
      result->y = v30;
      result->z = v31;
      *constrained_by_road = 1;
    }
  }
  return result;
}

// File Line: 4073
// RVA: 0x65A280
bool __fastcall UFG::AiDriverComponent::ShouldWaitForTarget(UFG::AiDriverComponent *this)
{
  float *v2; // rax
  float v3; // xmm15_4
  __int64 v4; // rax
  float v5; // xmm3_4
  __m128 v6; // xmm4
  float v7; // xmm5_4
  __m128 v8; // xmm2
  float v9; // xmm1_4
  float *v10; // rax
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm14_4
  float *v14; // rax
  float v15; // xmm10_4
  float v16; // xmm8_4
  float v17; // xmm11_4
  __int64 v18; // rax
  float v19; // xmm3_4
  __m128 v20; // xmm4
  float v21; // xmm5_4
  __m128 v22; // xmm2
  float v23; // xmm6_4
  float *v24; // rax
  float v25; // xmm8_4
  float v26; // xmm11_4
  float v27; // xmm2_4
  float v28; // xmm10_4
  float v29; // xmm8_4
  bool v30; // al
  float v32; // [rsp+20h] [rbp-A8h]
  float v33; // [rsp+20h] [rbp-A8h]
  float v34; // [rsp+24h] [rbp-A4h]
  float v35; // [rsp+24h] [rbp-A4h]
  float v36; // [rsp+28h] [rbp-A0h]
  float v37; // [rsp+28h] [rbp-A0h]
  float v38; // [rsp+D0h] [rbp+8h]
  float v39; // [rsp+D8h] [rbp+10h]

  if ( !this->m_pVehicleSubject.m_pSimComponent || !this->m_pChaseVehicleSubject.m_pPointer )
    return 0;
  v2 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[17].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent);
  v3 = *v2;
  v38 = v2[1];
  v39 = v2[2];
  v4 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[20].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent);
  v5 = *(float *)v4;
  v6 = (__m128)*(unsigned int *)(v4 + 4);
  v7 = *(float *)(v4 + 8);
  v8 = v6;
  v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
  if ( v8.m128_f32[0] <= 0.090000004 )
  {
    v10 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[16].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent);
    v32 = *v10;
    v34 = v10[1];
    v36 = v10[2];
  }
  else
  {
    v9 = v8.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v8).m128_f32[0];
    v32 = v5 * v9;
    v34 = v6.m128_f32[0] * v9;
    v36 = v7 * v9;
  }
  v11 = v32;
  v12 = v34;
  v13 = v36;
  v14 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pChaseVehicleSubject.m_pPointer->vfptr[17].__vecDelDtor)(this->m_pChaseVehicleSubject.m_pPointer);
  v15 = *v14;
  v16 = v14[1];
  v17 = v14[2];
  v18 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pChaseVehicleSubject.m_pPointer->vfptr[20].__vecDelDtor)(this->m_pChaseVehicleSubject.m_pPointer);
  v19 = *(float *)v18;
  v20 = (__m128)*(unsigned int *)(v18 + 4);
  v21 = *(float *)(v18 + 8);
  v22 = v20;
  v22.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v19 * v19)) + (float)(v21 * v21);
  if ( v22.m128_f32[0] <= 0.090000004 )
  {
    v24 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pChaseVehicleSubject.m_pPointer->vfptr[16].__vecDelDtor)(this->m_pChaseVehicleSubject.m_pPointer);
    v33 = *v24;
    v35 = v24[1];
    v37 = v24[2];
  }
  else
  {
    v23 = v22.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
    v33 = v19 * v23;
    v35 = v20.m128_f32[0] * v23;
    v37 = v21 * v23;
  }
  v25 = v16 - v38;
  v26 = v17 - v39;
  v27 = v25 * v12;
  v28 = v15 - v3;
  v29 = (float)((float)(v25 * v25) + (float)(v28 * v28)) + (float)(v26 * v26);
  v30 = v29 >= 400.0 && v29 <= 6400.0;
  return (float)((float)(v27 + (float)(v28 * v11)) + (float)(v26 * v13)) < 0.0
      && (float)((float)((float)(v35 * v12) + (float)(v33 * v11)) + (float)(v37 * v13)) > 0.0
      && v30;
}

// File Line: 4109
// RVA: 0x662150
void __fastcall UFG::AiDriverComponent::UpdateFollowingNavigation(UFG::AiDriverComponent *this, float delta_seconds)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pComponent; // rcx
  bool v5; // bl
  UFG::VehicleWayFinderClient *p_m_pSimObject; // r15
  float v7; // xmm0_4
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::SimObjectGame *v9; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *v11; // r13
  UFG::SimComponent *v12; // rax
  UFG::RoadSpaceComponent *v13; // rdi
  __int16 v14; // cx
  UFG::SimComponent *v15; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float *v17; // rax
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float *v21; // rax
  char v22; // r12
  UFG::SimObject *v23; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  __int16 v25; // cx
  __int64 v26; // rbx
  UFG::WayFinder *WayFinder; // rax
  int v28; // eax
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v30; // rcx
  UFG::qVector3 *v31; // rbp
  UFG::qVector3 *v32; // rsi
  UFG::qVector3 *v33; // rdi
  UFG::qVector3 *v34; // rax
  float v35; // xmm2_4
  float v36; // xmm0_4
  float *v37; // rax
  int m_pSimObject_high; // xmm1_4
  UFG::qVector3 *v39; // rdi
  float v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm5_4
  int mPrev; // xmm0_4
  float *v44; // rax
  int *v45; // rax
  UFG::SimComponent *v46; // rcx
  int v47; // xmm0_4
  int v48; // xmm2_4
  UFG::WayFinder *RoadWayFinder; // rbx
  int v50[4]; // [rsp+30h] [rbp-68h] BYREF
  UFG::qVector3 goal_position; // [rsp+40h] [rbp-58h] BYREF
  bool v52; // [rsp+A0h] [rbp+8h]
  float closing_speed; // [rsp+B0h] [rbp+18h] BYREF
  __int64 v54; // [rsp+B8h] [rbp+20h]

  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pComponent = (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent;
  else
    m_pComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
  if ( UFG::AiDriverComponent::ShouldWaitForTarget(this) )
  {
    v5 = 1;
    this->mModeGasBrakeLock = 1.0;
    this->mModeSteeringLock = 0.0;
  }
  else
  {
    v5 = 0;
  }
  this->mModeSteeringLockEnabled = v5;
  this->mModeGasBrakeLockEnabled = v5;
  p_m_pSimObject = (UFG::VehicleWayFinderClient *)&this->m_pRoadSpace.m_pSimComponent[8].m_pSimObject;
  if ( this->m_pVehicleSubject.m_pSimComponent
    && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent) )
  {
    v7 = FLOAT_100_0;
  }
  else
  {
    v7 = FLOAT_25_0;
  }
  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  if ( v7 < *((float *)&m_pSimComponent[29].m_pSimObject + 1) && !v5 )
  {
    v9 = (UFG::SimObjectGame *)m_pSimComponent[26].m_pSimObject;
    if ( !v9 )
      return;
    m_Flags = v9->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      v11 = v9->m_Components.p[24].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v12 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RoadSpaceComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(v9, UFG::RoadSpaceComponent::_TypeUID);
      v11 = v12;
    }
    else
    {
      v11 = v9->m_Components.p[24].m_pComponent;
    }
    if ( !v11 )
      return;
    v13 = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
    if ( v13->m_NavGuideEnabled )
    {
      if ( !v13->m_NavGuide.m_Active )
        v13->m_NavGuide.m_Active = 1;
      v14 = v9->m_Flags;
      if ( (v14 & 0x4000) != 0 )
      {
        v15 = v9->m_Components.p[37].m_pComponent;
      }
      else if ( v14 >= 0 )
      {
        if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CameraSubject::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v9, UFG::CameraSubject::_TypeUID);
        v15 = ComponentOfTypeHK;
      }
      else
      {
        v15 = v9->m_Components.p[31].m_pComponent;
      }
      v17 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v15->vfptr[17].__vecDelDtor)(v15);
      v18 = *v17;
      v19 = v17[1];
      v20 = v17[2];
      v21 = (float *)this->m_pRoadSpace.m_pSimComponent;
      if ( (float)((float)((float)((float)(v21[413] - v19) * (float)(v21[413] - v19))
                         + (float)((float)(v21[412] - v18) * (float)(v21[412] - v18)))
                 + (float)((float)(v21[414] - v20) * (float)(v21[414] - v20))) > 9.0 )
      {
        v21[412] = v18;
        v21[413] = v19;
        v21[414] = v20;
        UFG::AiDriverComponent::BeginPathingNavigation(this);
      }
      UFG::AiDriverComponent::UpdatePathingNavigation(this);
      return;
    }
    v22 = 1;
    if ( v13->mGuide.m_Attached )
    {
      if ( p_m_pSimObject->m_NumWayEdges )
      {
        WayFinder = UFG::GetWayFinder();
        if ( UFG::WayFinderClient::OnWay(p_m_pSimObject, WayFinder->m_WayGraph) )
        {
          v28 = p_m_pSimObject->m_NumWayEdges - 1;
          if ( v28 >= 0
            && p_m_pSimObject != (UFG::VehicleWayFinderClient *)-38i64
            && p_m_pSimObject->m_WayEdges[v28] == LOWORD(v11[8].m_BoundComponentHandles.mNode.mPrev) )
          {
            v22 = 0;
LABEL_46:
            v52 = this->m_fSearchTimer <= 0.0;
            if ( v22 && this->m_fSearchTimer > 0.0 )
              v22 = 0;
            v25 = v9->m_Flags;
            if ( (v25 & 0x4000) != 0 )
            {
              v26 = (__int64)v9->m_Components.p[37].m_pComponent;
            }
            else if ( v25 >= 0 )
            {
              if ( (v25 & 0x2000) != 0 || (v25 & 0x1000) != 0 )
                ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CameraSubject::_TypeUID);
              else
                ComponentOfType = UFG::SimObject::GetComponentOfType(v9, UFG::CameraSubject::_TypeUID);
              v26 = (__int64)ComponentOfType;
            }
            else
            {
              v26 = (__int64)v9->m_Components.p[31].m_pComponent;
            }
            v54 = v26;
            if ( v22 )
            {
              if ( !this->m_pChaseVehicleSubject.m_pPointer )
                goto LABEL_72;
              if ( !((unsigned __int8 (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[30].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent) )
                goto LABEL_72;
              v30 = this->m_pVehicleSubject.m_pSimComponent;
              closing_speed = 0.0;
              v31 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *))v30->vfptr[17].__vecDelDtor)(v30);
              v32 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[20].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent);
              v33 = (UFG::qVector3 *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 136i64))(v26);
              v34 = (UFG::qVector3 *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 160i64))(v26);
              v35 = (float)((float)((float)(v33->y - v31->y)
                                  * *((float *)&this->m_pRoadSpace.m_pSimComponent[27].m_pSimObject + 1))
                          + (float)((float)(v33->x - v31->x)
                                  * *(float *)&this->m_pRoadSpace.m_pSimComponent[27].m_pSimObject))
                  + (float)((float)(v33->z - v31->z)
                          * *(float *)&this->m_pRoadSpace.m_pSimComponent[27].m_BoundComponentHandles.mNode.mPrev);
              v36 = UFG::SoonestCloserThan(v31, v32, v33, v34, 30.0, &closing_speed);
              if ( v35 >= 0.0 )
                goto LABEL_72;
              if ( closing_speed < 0.0 && v36 >= 0.0 && v36 <= 6.0 )
              {
                v22 = 0;
              }
              else
              {
LABEL_72:
                if ( v52 )
                  this->m_fSearchTimer = 0.5;
              }
            }
            v37 = (float *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v54 + 136i64))(v54);
            m_pSimObject_high = HIDWORD(v11[27].m_pSimObject);
            v39 = (UFG::qVector3 *)v50;
            v40 = v37[1];
            v41 = v37[2];
            v42 = *v37;
            if ( this->m_bIgnoreArrivalDirection )
              v39 = 0i64;
            v50[0] = (int)v11[27].m_pSimObject;
            mPrev = (int)v11[27].m_BoundComponentHandles.mNode.mPrev;
            goal_position.x = v42;
            v50[2] = mPrev;
            goal_position.y = v40;
            goal_position.z = v41;
            v50[1] = m_pSimObject_high;
            if ( v22
              || (v44 = (float *)this->m_pRoadSpace.m_pSimComponent,
                  (float)((float)((float)((float)(v42 - v44[412]) * (float)(v42 - v44[412]))
                                + (float)((float)(v40 - v44[413]) * (float)(v40 - v44[413])))
                        + (float)((float)(v41 - v44[414]) * (float)(v41 - v44[414]))) > 9.0) )
            {
              v45 = v50;
              if ( !v39 )
                v45 = (int *)&UFG::qVector3::msZero;
              v46 = this->m_pRoadSpace.m_pSimComponent;
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
                RoadWayFinder = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
                                  UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                                  p_m_pSimObject);
                UFG::WayFinder::FindWay(RoadWayFinder, p_m_pSimObject, &goal_position, v39);
                UFG::WayFinder::Service(RoadWayFinder, 0.0);
                if ( p_m_pSimObject->m_NumWayEdges )
                  UFG::VehicleOccupantComponent::SetParkingSpot(
                    (UFG::RoadNetworkGuide *)&this->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext,
                    0i64);
              }
            }
            if ( p_m_pSimObject->m_NumWayEdges )
              UFG::AiDriverComponent::UpdateWayfindingNavigation(this);
            else
              UFG::AiDriverComponent::UpdateWanderingNavigation(this);
            return;
          }
        }
      }
    }
    else
    {
      v23 = v13->m_pSimObject;
      if ( v23 )
        m_pTransformNodeComponent = v23->m_pTransformNodeComponent;
      else
        m_pTransformNodeComponent = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      UFG::RoadSpaceComponent::AttachToRoadNetwork(
        v13,
        (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
        0i64);
    }
    p_m_pSimObject->vfptr->ResetWay(p_m_pSimObject);
    goto LABEL_46;
  }
  if ( BYTE4(m_pSimComponent[30].m_SafePointerList.mNode.mNext) )
  {
    this->m_fSearchTimer = 0.0;
    if ( m_pSimComponent )
    {
      if ( *((_BYTE *)&m_pSimComponent[1].m_SimObjIndex + 2) )
        *((_BYTE *)&m_pSimComponent[1].m_SimObjIndex + 2) = 0;
      UFG::NavGuide::ClearPath((UFG::NavGuide *)&this->m_pRoadSpace.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
    }
  }
  else if ( LOBYTE(m_pSimComponent[8].m_Flags) )
  {
    UFG::RoadNetworkGuide::RemoveFromNetwork((UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext);
    this->m_fSearchTimer = 0.0;
    p_m_pSimObject->vfptr->ResetWay(p_m_pSimObject);
  }
}   this->m_fSearchTimer = 0.0;
    p_m_pSimObject->vfptr->ResetWay(p_m_pSimObject);
  }
}

// File Line: 4294
// RVA: 0x645690
void __fastcall UFG::AiDriverComponent::BeginPathingNavigation(UFG::AiDriverComponent *this)
{
  UFG::RoadSpaceComponent *m_pSimComponent; // rax
  UFG::SimComponent *v3; // rbx
  UFG::SimObject *m_pSimObject; // rdi

  m_pSimComponent = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
  if ( !m_pSimComponent->m_NavGuide.m_Active )
    m_pSimComponent->m_NavGuide.m_Active = 1;
  v3 = this->m_pRoadSpace.m_pSimComponent;
  m_pSimObject = v3->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
  UFG::NavGuide::FindPath(
    (UFG::NavGuide *)&v3[1].m_SafePointerList.mNode.mNext,
    (UFG::qVector3 *)m_pSimObject[1].mNode.mChild,
    (UFG::qVector3 *)&v3[25].m_BoundComponentHandles,
    *(float *)&v3[5].m_SafePointerList.mNode.mNext);
  this->m_fSearchTimer = 0.5;
}

// File Line: 4303
// RVA: 0x662D80
bool __fastcall UFG::AiDriverComponent::UpdatePathingNavigation(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rbp
  UFG::NavGuide *p_mNext; // rsi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::TransformNodeComponent *m_pComponent; // rbx
  int v6; // eax
  UFG::SimObject *m_pSimObject; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  p_mNext = (UFG::NavGuide *)&m_pSimComponent[1].m_SafePointerList.mNode.mNext;
  mNext = m_pSimComponent[4].m_BoundComponentHandles.mNode.mNext;
  m_pComponent = 0i64;
  if ( mNext )
    v6 = (int)mNext->mNext;
  else
    v6 = 0;
  if ( (unsigned int)(LODWORD(m_pSimComponent[1].m_pSimObject) - 1) > 1 )
  {
    if ( !v6 )
      goto LABEL_11;
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      m_pComponent = (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
    m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
    if ( (float)((float)((float)((float)(m_pComponent->mWorldTransform.v3.y
                                       - *((float *)&m_pSimComponent[25].m_BoundComponentHandles.mNode.mPrev + 1))
                               * (float)(m_pComponent->mWorldTransform.v3.y
                                       - *((float *)&m_pSimComponent[25].m_BoundComponentHandles.mNode.mPrev + 1)))
                       + (float)((float)(m_pComponent->mWorldTransform.v3.x
                                       - *(float *)&m_pSimComponent[25].m_BoundComponentHandles.mNode.mPrev)
                               * (float)(m_pComponent->mWorldTransform.v3.x
                                       - *(float *)&m_pSimComponent[25].m_BoundComponentHandles.mNode.mPrev)))
               + (float)((float)(m_pComponent->mWorldTransform.v3.z
                               - *(float *)&m_pSimComponent[25].m_BoundComponentHandles.mNode.mNext)
                       * (float)(m_pComponent->mWorldTransform.v3.z
                               - *(float *)&m_pSimComponent[25].m_BoundComponentHandles.mNode.mNext))) < (float)(this->m_StopAtDist * this->m_StopAtDist) )
      return this->m_GoToStopAtEnabled;
    UFG::NavGuide::GetPathSegmentPos(p_mNext, &result, p_mNext->m_CurrPathPointIndex, &p_mNext->m_Pos);
    if ( (float)((float)((float)((float)(p_mNext->m_Pos.y - result.y) * (float)(p_mNext->m_Pos.y - result.y))
                       + (float)((float)(p_mNext->m_Pos.x - result.x) * (float)(p_mNext->m_Pos.x - result.x)))
               + (float)((float)(p_mNext->m_Pos.z - result.z) * (float)(p_mNext->m_Pos.z - result.z))) >= 900.0 )
    {
LABEL_11:
      if ( this->m_fSearchTimer <= 0.0 )
      {
        UFG::RoadSpaceComponent::FindPath((UFG::RoadSpaceComponent *)m_pSimComponent);
        this->m_fSearchTimer = 0.5;
      }
    }
  }
  return 0;
}

// File Line: 4352
// RVA: 0x64C8E0
void __fastcall UFG::AiDriverComponent::EndPathingNavigation(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  this->m_fSearchTimer = 0.0;
  if ( m_pSimComponent )
  {
    if ( *((_BYTE *)&m_pSimComponent[1].m_SimObjIndex + 2) )
      *((_BYTE *)&m_pSimComponent[1].m_SimObjIndex + 2) = 0;
    UFG::NavGuide::ClearPath((UFG::NavGuide *)&this->m_pRoadSpace.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
  }
}

// File Line: 4365
// RVA: 0x665A60
void __fastcall UFG::AiDriverComponent::UpdateWayfindingNavigation(UFG::AiDriverComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::RoadNetworkNode *v3; // rdi
  UFG::TransformNodeComponent *m_pComponent; // rcx
  UFG::RoadNetworkGuide *p_mNext; // rbp
  UFG::RoadNetworkLocation *Name; // r13
  UFG::RoadNetworkLane *m_CurrentLane; // rbx
  char *v8; // r14
  UFG::RoadSpaceComponent *m_pSimComponent; // r15
  int m_CurrEdgeIndex; // ecx
  UFG::VehicleWayFinderClient *p_mWayClient; // r15
  float Length; // xmm0_4
  UFG::SimComponent *v13; // rax
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
  unsigned int v25; // r13d
  __int64 v26; // rax
  unsigned int v27; // edx
  UFG::RoadNetworkSegment *Segment; // r12
  UFG::RoadNetworkLane *NextWayfindLane; // rax
  UFG::RoadNetworkLane *v30; // r14
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v32; // r8
  __int64 v33; // rax
  _WORD *v34; // rcx
  UFG::RoadNetworkLane *Path; // rax
  UFG::RoadNetworkSegment *v36; // rcx
  UFG::RoadNetworkSegment *v37; // rbx
  __int64 v38; // rax
  UFG::RoadNetworkLane *FirstOutgoingLaneLeadingToNode; // rax
  __int64 v40; // rax
  UFG::RoadNetworkGate *v41; // rcx
  UFG::RoadNetworkLane *v42; // rax
  __int64 v43; // rax
  UFG::RoadNetworkGate *v44; // rcx
  __int64 v45; // rcx
  unsigned int LaneDirection; // r14d
  UFG::RoadNetworkNode *v47; // rcx
  __int64 v48; // rdx
  UFG::qVector3 pos; // [rsp+20h] [rbp-88h] BYREF
  UFG::qVector3 result; // [rsp+30h] [rbp-78h] BYREF
  float laneT; // [rsp+B0h] [rbp+8h] BYREF

  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  m_pSimObject = this->m_pSimObject;
  v3 = 0i64;
  if ( m_pSimObject )
    m_pComponent = (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent;
  else
    m_pComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
  p_mNext = (UFG::RoadNetworkGuide *)&this->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext;
  Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
  m_CurrentLane = Name->m_CurrentLane;
  v8 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  if ( !m_CurrentLane->mNode.mOffset )
    v8 = 0i64;
  m_pSimComponent = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
  m_CurrEdgeIndex = m_pSimComponent->mWayClient.m_CurrEdgeIndex;
  p_mWayClient = &m_pSimComponent->mWayClient;
  if ( m_CurrEdgeIndex + 1 >= p_mWayClient->m_NumWayEdges )
  {
    Length = UFG::RoadNetworkLane::GetLength(m_CurrentLane);
    v13 = this->m_pRoadSpace.m_pSimComponent;
    v14 = *((float *)&v13[25].m_BoundComponentHandles.mNode.mPrev + 1);
    v15 = *(float *)&v13[25].m_BoundComponentHandles.mNode.mNext;
    v16 = *(float *)&v13[25].m_BoundComponentHandles.mNode.mPrev;
    v17 = Length;
    v18 = Length * Name->m_LaneT;
    laneT = 0.0;
    pos.x = v16;
    pos.y = v14;
    pos.z = v15;
    UFG::RoadNetworkLane::GetNearestPoint(m_CurrentLane, &result, &pos, &laneT);
    v19 = (float)(laneT * Length) + 8.0;
    if ( v19 >= v17 )
      v19 = v17;
    if ( v18 > v19 )
    {
      v20 = (float *)this->m_pRoadSpace.m_pSimComponent;
      v21 = v20[415];
      v22 = v20[416];
      v23 = v20[417];
      if ( this->m_bIgnoreArrivalDirection
        || v21 == UFG::qVector3::msZero.x && v22 == UFG::qVector3::msZero.y && v23 == UFG::qVector3::msZero.z )
      {
        goto LABEL_59;
      }
      if ( m_CurrentLane->mNode.mOffset )
        v3 = (UFG::RoadNetworkNode *)((char *)m_CurrentLane + m_CurrentLane->mNode.mOffset);
      UFG::RoadNetworkNode::GetTangent(v3, &result, m_CurrentLane->mLaneIndex, laneT);
      if ( (float)((float)((float)(result.y * v22) + (float)(result.x * v21)) + (float)(result.z * v23)) <= 0.0 )
      {
LABEL_59:
        if ( UFG::RoadNetworkGuide::CanChangeLane(p_mNext, 1u) )
          UFG::AiDriverComponent::ChangeLane(this, 1u);
      }
    }
    UFG::AiDriverComponent::UpdateWanderingNavigation(this);
    return;
  }
  if ( !UFG::RoadNetworkGuide::NavigationInfoNeeded(p_mNext) )
    return;
  UFG::RoadNetworkGuide::SetLaneAfterNext(p_mNext, 0i64);
  v24 = p_mWayClient->m_CurrEdgeIndex;
  v25 = p_mWayClient->m_NumWayEdges - 1;
  if ( *((_DWORD *)v8 + 6) == *((unsigned __int16 *)&p_mWayClient->vfptr + v24 + 20) )
  {
    v24 = (unsigned __int16)(v24 + 1);
    p_mWayClient->m_CurrEdgeIndex = v24;
    if ( v24 >= v25 )
      return;
  }
  v26 = v24 + 1;
  v27 = p_mWayClient->m_WayEdges[v26];
  laneT = *(float *)&v26;
  Segment = UFG::RoadNetworkResource::GetSegment(UFG::gpRoadNetworkResource, v27);
  NextWayfindLane = UFG::AiDriverComponent::FindNextWayfindLane(this, m_CurrentLane, Segment);
  v30 = NextWayfindLane;
  if ( NextWayfindLane )
  {
    UFG::VehicleOccupantComponent::SetParkingSpot(p_mNext, NextWayfindLane);
    mOffset = v30->mNextConnection.mOffset;
    if ( !mOffset )
      return;
    v32 = (UFG::RoadNetworkConnection *)((char *)&v30->mNextConnection + mOffset);
    if ( !v32 )
      return;
    v33 = v30->mNode.mOffset;
    v34 = (_WORD *)((char *)v30 + v30->mNode.mOffset);
    if ( !v30->mNode.mOffset )
      v34 = 0i64;
    if ( *v34 == 1 )
    {
      Path = UFG::qBezierPathCollectionMemImaged::GetPath(v32, 0);
      if ( !Path )
        return;
      goto LABEL_30;
    }
    v36 = (UFG::RoadNetworkSegment *)((char *)v30 + v33);
    if ( !v33 )
      v36 = 0i64;
    if ( v36 == Segment && LODWORD(laneT) < v25 )
    {
      v37 = UFG::RoadNetworkResource::GetSegment(
              UFG::gpRoadNetworkResource,
              p_mWayClient->m_WayEdges[LODWORD(laneT) + 1]);
      Path = UFG::AiDriverComponent::FindNextWayfindLane(this, v30, v37);
      if ( Path )
        goto LABEL_30;
      v38 = v30->mEndGate.mOffset;
      if ( v38 )
        v3 = (UFG::RoadNetworkNode *)((char *)&v30->mEndGate + v38);
      FirstOutgoingLaneLeadingToNode = UFG::RoadNetworkGate::GetFirstOutgoingLaneLeadingToNode(
                                         (UFG::RoadNetworkGate *)v3,
                                         v37);
      if ( FirstOutgoingLaneLeadingToNode )
      {
        Path = UFG::AiDriverComponent::FindNextWayfindLane(this, FirstOutgoingLaneLeadingToNode, v37);
        if ( Path )
LABEL_30:
          UFG::RoadNetworkGuide::SetLaneAfterNext(p_mNext, Path);
      }
    }
  }
  else
  {
    v40 = m_CurrentLane->mEndGate.mOffset;
    if ( v40 )
      v41 = (UFG::RoadNetworkGate *)((char *)&m_CurrentLane->mEndGate + v40);
    else
      v41 = 0i64;
    v42 = UFG::RoadNetworkGate::GetFirstOutgoingLaneLeadingToNode(v41, Segment);
    if ( !v42 )
    {
      v43 = m_CurrentLane->mStartGate.mOffset;
      if ( v43 )
        v44 = (UFG::RoadNetworkGate *)((char *)&m_CurrentLane->mStartGate + v43);
      else
        v44 = 0i64;
      v42 = UFG::RoadNetworkGate::GetFirstOutgoingLaneLeadingToNode(v44, Segment);
    }
    v45 = v42->mStartGate.mOffset;
    LaneDirection = 1;
    if ( v45 )
      v47 = (UFG::RoadNetworkNode *)((char *)&v42->mStartGate + v45);
    else
      v47 = 0i64;
    v48 = m_CurrentLane->mStartGate.mOffset;
    if ( v48 )
      v3 = (UFG::RoadNetworkNode *)((char *)&m_CurrentLane->mStartGate + v48);
    if ( v47 == v3 )
      LaneDirection = UFG::RoadNetworkLane::GetLaneDirection(m_CurrentLane, v42);
    UFG::AiDriverComponent::ChangeLane(this, LaneDirection);
  }
}

// File Line: 4502
// RVA: 0x64D1D0
UFG::RoadNetworkLane *__fastcall UFG::AiDriverComponent::FindNextWayfindLane(
        UFG::AiDriverComponent *this,
        UFG::RoadNetworkLane *currLane,
        UFG::RoadNetworkNode *nextPathSegment)
{
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v5; // rdi
  _WORD *v6; // rax
  __int64 v7; // rax
  UFG::RoadNetworkNode **v8; // rcx
  UFG::RoadNetworkNode *v9; // rdx
  _WORD **v10; // rcx
  _WORD *v11; // rax
  unsigned int mNumLanes; // esi
  unsigned int v13; // ebx
  UFG::RoadNetworkLane *Path; // rax
  UFG::RoadNetworkLane *v15; // rdx
  __int64 v16; // rcx
  UFG::RoadNetworkNode **v17; // rax
  UFG::RoadNetworkNode *v18; // rcx

  mOffset = currLane->mNextConnection.mOffset;
  if ( mOffset )
    v5 = (UFG::RoadNetworkConnection *)((char *)&currLane->mNextConnection + mOffset);
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
    v10 = (_WORD **)((char *)&v5->mGate + v7);
  else
    v10 = 0i64;
  v11 = *v10;
  if ( *v10 )
    v11 = (_WORD *)((char *)v11 + (_QWORD)v10);
  if ( *v11 != 1 )
    return 0i64;
  mNumLanes = v5->mNumLanes;
  v13 = 0;
  if ( !v5->mNumLanes )
    return 0i64;
  while ( 1 )
  {
    Path = UFG::qBezierPathCollectionMemImaged::GetPath(v5, v13);
    v15 = Path;
    v16 = Path->mNextConnection.mOffset;
    if ( v16 )
      v16 += (__int64)&Path->mNextConnection;
    v17 = *(UFG::RoadNetworkNode ***)(v16 + 24);
    if ( v17 )
      v17 = (UFG::RoadNetworkNode **)((char *)v17 + v16 + 24);
    v18 = *v17;
    if ( *v17 )
      v18 = (UFG::RoadNetworkNode *)((char *)v18 + (_QWORD)v17);
    if ( v18 == nextPathSegment )
      break;
    if ( ++v13 >= mNumLanes )
      return 0i64;
  }
  return v15;
}

// File Line: 4529
// RVA: 0x662950
void __fastcall UFG::AiDriverComponent::UpdateNavWandering(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  float v3; // xmm7_4
  float *v4; // rax
  float v5; // xmm8_4
  float v6; // xmm6_4
  double v7; // xmm0_8
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::qVector3 dest; // [rsp+20h] [rbp-48h] BYREF

  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  if ( *((_BYTE *)&m_pSimComponent[5].m_SimObjIndex + 2) )
  {
    v3 = (float)((float)((float)(*(float *)&m_pSimComponent[5].m_pSimObject
                               - *((float *)&m_pSimComponent[5].m_SafePointerList.mNode.mNext + 1))
                       * (float)(*(float *)&m_pSimComponent[5].m_pSimObject
                               - *((float *)&m_pSimComponent[5].m_SafePointerList.mNode.mNext + 1)))
               + (float)((float)(*((float *)&m_pSimComponent[5].m_pSimObject + 1)
                               - *(float *)&m_pSimComponent[5].m_TypeUID)
                       * (float)(*((float *)&m_pSimComponent[5].m_pSimObject + 1)
                               - *(float *)&m_pSimComponent[5].m_TypeUID)))
       + (float)((float)(*(float *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mPrev
                       - *(float *)&m_pSimComponent[5].m_NameUID)
               * (float)(*(float *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mPrev
                       - *(float *)&m_pSimComponent[5].m_NameUID));
    v4 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[17].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent);
    v5 = *(float *)&this->m_pRoadSpace.m_pSimComponent[5].m_Flags;
    v6 = (float)((float)((float)(v4[1] - *(float *)&m_pSimComponent[5].m_TypeUID)
                       * (float)(v4[1] - *(float *)&m_pSimComponent[5].m_TypeUID))
               + (float)((float)(*v4 - *((float *)&m_pSimComponent[5].m_SafePointerList.mNode.mNext + 1))
                       * (float)(*v4 - *((float *)&m_pSimComponent[5].m_SafePointerList.mNode.mNext + 1))))
       + (float)((float)(v4[2] - *(float *)&m_pSimComponent[5].m_NameUID)
               * (float)(v4[2] - *(float *)&m_pSimComponent[5].m_NameUID));
    v7 = ((double (__fastcall *)(UFG::SimComponent *))this->m_pVehicleSubject.m_pSimComponent->vfptr[21].__vecDelDtor)(this->m_pVehicleSubject.m_pSimComponent);
    v8 = *(float *)&v7;
    v9 = FLOAT_2_0;
    v10 = v8 * 0.69999999;
    if ( v10 >= 2.0 )
      v9 = v10;
    if ( v3 >= (float)((float)(v5 + 0.1) * (float)(v5 + 0.1)) || v6 <= (float)(v9 * v9) )
    {
      v11 = UFG::qRandom(v5, (unsigned int *)&UFG::qDefaultSeed);
      v12 = UFG::qRandom(360.0, (unsigned int *)&UFG::qDefaultSeed);
      dest = UFG::qVector3::msDirFront;
      UFG::qRotateVectorZ(&dest, &UFG::qVector3::msDirFront, (float)(v12 * 3.1415927) * 0.0055555557);
      v13 = (float *)this->m_pRoadSpace.m_pSimComponent;
      v14 = (float)(dest.y * v11) + *((float *)&m_pSimComponent[5].m_pSimObject + 1);
      v15 = (float)(dest.z * v11) + *(float *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mPrev;
      v13[85] = (float)(dest.x * v11) + *(float *)&m_pSimComponent[5].m_pSimObject;
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
  UFG::SimObject *m_pSimObject; // rax
  unsigned int v3; // r15d
  UFG::TransformNodeComponent *m_pComponent; // rcx
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::RoadNetworkGuide *p_mNext; // rbx
  UFG::RoadNetworkConnection *NextConnection; // rax
  UFG::RoadNetworkConnection *v8; // r12
  unsigned int *v9; // rsi
  unsigned int size; // r14d
  unsigned int capacity; // ebx
  unsigned int v12; // edi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  unsigned int *p; // rcx
  __int64 i; // r8
  unsigned int v18; // eax
  UFG::RoadNetworkLane *Path; // rsi
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v21; // rax
  _WORD *v22; // rdx
  UFG::RoadNetworkLane *v23; // rdx
  UFG::RoadNetworkGuide *v24; // rcx
  UFG::RoadNetworkLane *WanderLaneAfterNext; // rax
  UFG::RoadNetworkLane *v26; // rdi
  __int64 v27; // rax
  UFG::RoadNetworkGate *v28; // r14
  unsigned int mNumOutgoingConnections; // r15d
  unsigned int v30; // ebx
  UFG::RoadNetworkConnection *OutgoingConnection; // rax
  UFG::RoadNetworkConnection *v32; // rcx
  __int64 v33; // rcx
  UFG::RoadNetworkConnection *v34; // rdx
  UFG::RoadNetworkLane *v35; // rax
  UFG::RoadNetworkGuide *v36; // [rsp+20h] [rbp-28h]
  UFG::qArray<unsigned long,0> laneIDs; // [rsp+30h] [rbp-18h] BYREF
  unsigned int whichLanes; // [rsp+98h] [rbp+50h] BYREF
  unsigned int mNumLanes; // [rsp+A0h] [rbp+58h]
  UFG::RoadNetworkConnection *v41; // [rsp+A8h] [rbp+60h]

  v1 = this;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  m_pSimObject = v1->m_pSimObject;
  v3 = 0;
  if ( m_pSimObject )
    m_pComponent = (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent;
  else
    m_pComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
  m_pSimComponent = v1->m_pRoadSpace.m_pSimComponent;
  if ( BYTE4(m_pSimComponent[30].m_SafePointerList.mNode.mNext) )
  {
    if ( !*((_BYTE *)&m_pSimComponent[1].m_SimObjIndex + 2) )
      *((_BYTE *)&m_pSimComponent[1].m_SimObjIndex + 2) = 1;
    UFG::AiDriverComponent::UpdateNavWandering(v1);
    return;
  }
  p_mNext = (UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext;
  v36 = (UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext;
  if ( !LOBYTE(m_pSimComponent[8].m_Flags) )
    return;
  if ( !UFG::RoadNetworkGuide::NavigationInfoNeeded((UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext) )
    return;
  UFG::RoadNetworkGuide::SetLaneAfterNext(p_mNext, 0i64);
  NextConnection = UFG::RoadNetworkGuide::GetNextConnection(p_mNext);
  v8 = NextConnection;
  v41 = NextConnection;
  if ( !NextConnection )
    return;
  laneIDs.p = 0i64;
  *(_QWORD *)&laneIDs.size = 0i64;
  UFG::RoadNetworkConnection::GetValidLanes(
    NextConnection,
    (unsigned __int8)v1->m_pRoadSpace.m_pSimComponent[30].m_SafePointerList.mNode.mNext,
    &laneIDs);
  if ( !laneIDs.size )
  {
    if ( UFG::PhysicsMoverInterface::GetLOD((UFG::PhysicsMoverInterface *)v1->mMoverComponent.m_pSimComponent) == LOD_LOW )
      goto LABEL_19;
    whichLanes = 3;
    if ( !UFG::RoadNetworkGuide::LaneChangeAvailable(p_mNext, &whichLanes)
      || !UFG::RoadNetworkGuide::ChangeLaneIfRoom(p_mNext, whichLanes) )
    {
      goto LABEL_19;
    }
    v8 = UFG::RoadNetworkGuide::GetNextConnection(p_mNext);
    v41 = v8;
    if ( !v8 )
      goto LABEL_75;
    if ( laneIDs.p )
      operator delete[](laneIDs.p);
    laneIDs.p = 0i64;
    *(_QWORD *)&laneIDs.size = 0i64;
    UFG::RoadNetworkConnection::GetValidLanes(
      v8,
      (unsigned __int8)v1->m_pRoadSpace.m_pSimComponent[30].m_SafePointerList.mNode.mNext,
      &laneIDs);
    if ( !laneIDs.size )
    {
LABEL_19:
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
        size = 0;
        laneIDs.size = 0;
        capacity = 0;
        laneIDs.capacity = 0;
        mNumLanes = v8->mNumLanes;
        if ( !mNumLanes )
          goto LABEL_46;
        while ( 1 )
        {
          v12 = size + 1;
          if ( size + 1 > capacity )
          {
            if ( capacity )
              v13 = 2 * capacity;
            else
              v13 = 1;
            for ( ; v13 < v12; v13 *= 2 )
              ;
            if ( v13 <= 4 )
              v13 = 4;
            if ( v13 - v12 > 0x10000 )
              v13 = size + 65537;
            if ( v13 != size )
            {
              v14 = 4i64 * v13;
              if ( !is_mul_ok(v13, 4ui64) )
                v14 = -1i64;
              v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
              v9 = (unsigned int *)v15;
              p = laneIDs.p;
              if ( laneIDs.p )
              {
                for ( i = 0i64; (unsigned int)i < laneIDs.size; p = laneIDs.p )
                {
                  *((_DWORD *)&v15->mNext + i) = p[i];
                  i = (unsigned int)(i + 1);
                }
                operator delete[](p);
              }
              laneIDs.p = v9;
              laneIDs.capacity = v13;
            }
          }
          laneIDs.size = size + 1;
          v9[size] = v3++;
          if ( v3 >= mNumLanes )
            break;
          v9 = laneIDs.p;
          capacity = laneIDs.capacity;
          size = laneIDs.size;
        }
        v1 = this;
        v8 = v41;
        if ( !laneIDs.size )
        {
LABEL_46:
          v1->m_fDesiredSpeed = 0.0;
          goto LABEL_75;
        }
        p_mNext = v36;
      }
    }
  }
  v18 = UFG::AiDriverComponent::ChooseNextLane(v1, v8, &laneIDs);
  Path = UFG::qBezierPathCollectionMemImaged::GetPath(v8, v18);
  UFG::VehicleOccupantComponent::SetParkingSpot(p_mNext, Path);
  mOffset = Path->mNextConnection.mOffset;
  if ( mOffset )
    v21 = (UFG::RoadNetworkConnection *)((char *)&Path->mNextConnection + mOffset);
  else
    v21 = 0i64;
  v22 = (_WORD *)((char *)Path + Path->mNode.mOffset);
  if ( !Path->mNode.mOffset )
    v22 = 0i64;
  if ( *v22 != 1 )
  {
    WanderLaneAfterNext = UFG::AiDriverComponent::FindWanderLaneAfterNext(v1, v21);
    v26 = WanderLaneAfterNext;
    if ( WanderLaneAfterNext )
    {
      v23 = WanderLaneAfterNext;
      v24 = p_mNext;
    }
    else
    {
      v27 = Path->mEndGate.mOffset;
      if ( v27 )
        v28 = (UFG::RoadNetworkGate *)((char *)&Path->mEndGate + v27);
      else
        v28 = 0i64;
      mNumOutgoingConnections = v28->mNumOutgoingConnections;
      v30 = 0;
      if ( !mNumOutgoingConnections )
        goto LABEL_75;
      do
      {
        OutgoingConnection = UFG::RoadNetworkGate::GetOutgoingConnection(v28, v30);
        v32 = (UFG::RoadNetworkConnection *)Path->mEndConnection.mOffset;
        if ( v32 )
          v32 = (UFG::RoadNetworkConnection *)((char *)v32 + (_QWORD)Path + 96);
        if ( OutgoingConnection != v32 )
        {
          v33 = OutgoingConnection->mConnection.mOffset;
          v34 = v33 ? (UFG::RoadNetworkConnection *)((char *)&OutgoingConnection->mConnection + v33) : 0i64;
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
      while ( v30 < mNumOutgoingConnections );
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
    v24 = p_mNext;
LABEL_74:
    UFG::RoadNetworkGuide::SetLaneAfterNext(v24, v23);
  }
LABEL_75:
  if ( laneIDs.p )
    operator delete[](laneIDs.p);
}21->mNumLanes )
  {
    v23 = UFG::qBezierPathCollectionMemImaged::GetPath(

// File Line: 4698
// RVA: 0x64D580
UFG::RoadNetworkLane *__fastcall UFG::AiDriverComponent::FindWanderLaneAfterNext(
        UFG::AiDriverComponent *this,
        UFG::RoadNetworkConnection *roadConn)
{
  unsigned int mNumLanes; // r14d
  UFG::RoadNetworkLane *v3; // rbx
  char v4; // bp
  unsigned int v7; // esi
  UFG::RoadNetworkLane *Path; // rdi
  int TurnDirection; // eax

  mNumLanes = roadConn->mNumLanes;
  v3 = 0i64;
  v4 = 0;
  v7 = 0;
  if ( !roadConn->mNumLanes )
    return v3;
  while ( 1 )
  {
    Path = UFG::qBezierPathCollectionMemImaged::GetPath(roadConn, v7);
    if ( UFG::RoadNetworkLane::IsFlagMatch(
           Path,
           (unsigned __int8)this->m_pRoadSpace.m_pSimComponent[30].m_SafePointerList.mNode.mNext) )
    {
      break;
    }
LABEL_8:
    if ( ++v7 >= mNumLanes )
      return v3;
  }
  TurnDirection = UFG::RoadNetworkLane::GetTurnDirection(Path);
  if ( TurnDirection != 1 )
  {
    if ( TurnDirection == 2 )
    {
      v3 = Path;
      v4 = 1;
    }
    else if ( !v4 )
    {
      v3 = Path;
    }
    goto LABEL_8;
  }
  return Path;
}

// File Line: 4729
// RVA: 0x648A40
__int64 __fastcall UFG::AiDriverComponent::ChooseNextLane(
        UFG::AiDriverComponent *this,
        UFG::RoadNetworkConnection *roadConnection,
        UFG::qArray<unsigned long,0> *validLanes)
{
  UFG::qArray<unsigned long,0> *v3; // rax
  UFG::RoadNetworkConnection *v4; // rdi
  UFG::AiDriverComponent *v5; // r14
  unsigned __int64 size; // rbx
  void *v8; // rsi
  unsigned int v9; // r13d
  unsigned int v10; // r12d
  unsigned __int64 v11; // rax
  unsigned int v12; // r15d
  __int64 v13; // rcx
  UFG::RoadNetworkLane *Path; // rax
  UFG::RoadNetworkLane *v15; // rbx
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v17; // rcx
  UFG::RoadNetworkLane *v18; // rax
  UFG::RoadNetworkLane *v19; // rbx
  float Length; // xmm0_4
  unsigned int v21; // edx
  _WORD *v22; // rcx
  __int64 v23; // rax
  UFG::RoadNetworkConnection *v24; // rsi
  unsigned __int64 v25; // rdi
  unsigned __int64 v26; // rax
  UFG::allocator::free_link *v27; // rax
  unsigned int *v28; // rbx
  unsigned int *p; // rcx
  __int64 i; // r8
  UFG::RoadNetworkLane *v31; // rax
  UFG::RoadNetworkConnection *v32; // rcx
  UFG::RoadNetworkLane *v33; // rbx
  float v34; // xmm0_4
  unsigned int v35; // edx
  __int64 v36; // r14
  unsigned int v37; // edi
  unsigned int v38; // ebx
  unsigned __int64 v39; // rax
  UFG::allocator::free_link *v40; // rax
  void *v41; // rcx
  UFG::allocator::free_link *v42; // rdx
  char *v43; // r9
  __int64 v44; // r8
  UFG::qArray<unsigned long,0> *v45; // rdx
  unsigned int v46; // ebx
  UFG::qArray<unsigned long,0> laneIDs; // [rsp+28h] [rbp-30h] BYREF
  __int64 v48; // [rsp+38h] [rbp-20h] BYREF
  void *mem; // [rsp+40h] [rbp-18h]
  unsigned int mNumLanes; // [rsp+B8h] [rbp+60h]

  v3 = validLanes;
  v4 = roadConnection;
  v5 = this;
  size = validLanes->size;
  if ( (_DWORD)size == 1 )
    return *validLanes->p;
  v8 = 0i64;
  mem = 0i64;
  v9 = 0;
  v48 = 0i64;
  v10 = 0;
  if ( (_DWORD)size )
  {
    v11 = 4 * size;
    if ( !is_mul_ok(size, 4ui64) )
      v11 = -1i64;
    v8 = UFG::qMalloc(v11, "AiDriverComponent", 0i64);
    mem = v8;
    v10 = size;
    HIDWORD(v48) = size;
    v3 = validLanes;
  }
  mNumLanes = v4->mNumLanes;
  v12 = 0;
  if ( !v4->mNumLanes )
  {
LABEL_73:
    v45 = v3;
    goto LABEL_74;
  }
  do
  {
    v13 = 0i64;
    if ( !v3->size )
      goto LABEL_71;
    while ( v12 != v3->p[v13] )
    {
      v13 = (unsigned int)(v13 + 1);
      if ( (unsigned int)v13 >= v3->size )
        goto LABEL_70;
    }
    if ( (_DWORD)v13 != -1 )
    {
      Path = UFG::qBezierPathCollectionMemImaged::GetPath(v4, v12);
      v15 = Path;
      if ( Path )
      {
        if ( !UFG::AiDriverComponent::IsJammed(Path, 1u) )
        {
          mOffset = v15->mNextConnection.mOffset;
          if ( mOffset )
          {
            v17 = (UFG::RoadNetworkConnection *)((char *)&v15->mNextConnection + mOffset);
            if ( v17 )
            {
              if ( v17->mNumLanes )
              {
                v18 = UFG::qBezierPathCollectionMemImaged::GetPath(v17, 0);
                v19 = v18;
                if ( v18 )
                {
                  Length = UFG::RoadNetworkLane::GetLength(v18);
                  v21 = 1;
                  if ( Length > 20.0 )
                    v21 = 3;
                  if ( !UFG::AiDriverComponent::IsJammed(v19, v21) )
                  {
                    if ( v19->mNode.mOffset )
                      v22 = (_WORD *)((char *)v19 + v19->mNode.mOffset);
                    else
                      v22 = 0i64;
                    if ( !*v22 )
                    {
                      v23 = v19->mNextConnection.mOffset;
                      if ( v23 )
                        v24 = (UFG::RoadNetworkConnection *)((char *)&v19->mNextConnection + v23);
                      else
                        v24 = 0i64;
                      laneIDs.p = 0i64;
                      *(_QWORD *)&laneIDs.size = 0i64;
                      v25 = v24->mNumLanes;
                      if ( (_DWORD)v25 )
                      {
                        v26 = 4i64 * v24->mNumLanes;
                        if ( !is_mul_ok(v25, 4ui64) )
                          v26 = -1i64;
                        v27 = UFG::qMalloc(v26, "qArray.Reallocate(Reserve)", 0i64);
                        v28 = (unsigned int *)v27;
                        p = laneIDs.p;
                        if ( laneIDs.p )
                        {
                          for ( i = 0i64; (unsigned int)i < laneIDs.size; p = laneIDs.p )
                          {
                            *((_DWORD *)&v27->mNext + i) = p[i];
                            i = (unsigned int)(i + 1);
                          }
                          operator delete[](p);
                        }
                        laneIDs.p = v28;
                        laneIDs.capacity = v25;
                      }
                      UFG::RoadNetworkConnection::GetValidLanes(
                        v24,
                        (unsigned __int8)v5->m_pRoadSpace.m_pSimComponent[30].m_SafePointerList.mNode.mNext,
                        &laneIDs);
                      if ( laneIDs.size == 1 )
                      {
                        v31 = UFG::qBezierPathCollectionMemImaged::GetPath(v24, *laneIDs.p);
                        v32 = (UFG::RoadNetworkConnection *)v31->mNextConnection.mOffset;
                        if ( v32 )
                          v32 = (UFG::RoadNetworkConnection *)((char *)v32 + (_QWORD)v31 + 104);
                        v33 = UFG::qBezierPathCollectionMemImaged::GetPath(v32, 0);
                        v34 = UFG::RoadNetworkLane::GetLength(v33);
                        v35 = 1;
                        if ( v34 > 20.0 )
                          v35 = 3;
                        if ( UFG::AiDriverComponent::IsJammed(v33, v35) )
                        {
                          if ( laneIDs.p )
                            operator delete[](laneIDs.p);
                          laneIDs.p = 0i64;
                          *(_QWORD *)&laneIDs.size = 0i64;
                          v8 = mem;
LABEL_69:
                          v4 = roadConnection;
                          goto LABEL_70;
                        }
                      }
                      if ( laneIDs.p )
                        operator delete[](laneIDs.p);
                      laneIDs.p = 0i64;
                      *(_QWORD *)&laneIDs.size = 0i64;
                    }
                    v36 = v9;
                    v37 = v9 + 1;
                    if ( v9 + 1 <= v10 )
                      goto LABEL_67;
                    v38 = 1;
                    if ( v10 )
                      v38 = 2 * v10;
                    for ( ; v38 < v37; v38 *= 2 )
                      ;
                    if ( v38 <= 4 )
                      v38 = 4;
                    if ( v38 - v37 > 0x10000 )
                      v38 = v9 + 65537;
                    if ( v38 == v9 )
                    {
LABEL_67:
                      v8 = mem;
                    }
                    else
                    {
                      v39 = 4i64 * v38;
                      if ( !is_mul_ok(v38, 4ui64) )
                        v39 = -1i64;
                      v40 = UFG::qMalloc(v39, "qArray.Add", 0i64);
                      v8 = v40;
                      v41 = mem;
                      if ( mem )
                      {
                        if ( v9 )
                        {
                          v42 = v40;
                          v43 = (char *)((_BYTE *)mem - (_BYTE *)v40);
                          v44 = v9;
                          do
                          {
                            LODWORD(v42->mNext) = *(_DWORD *)((char *)&v42->mNext + (_QWORD)v43);
                            v42 = (UFG::allocator::free_link *)((char *)v42 + 4);
                            --v44;
                          }
                          while ( v44 );
                        }
                        operator delete[](v41);
                      }
                      mem = v8;
                      v10 = v38;
                      HIDWORD(v48) = v38;
                    }
                    ++v9;
                    LODWORD(v48) = v37;
                    *((_DWORD *)v8 + v36) = v12;
                    v5 = this;
                    goto LABEL_69;
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_70:
    v3 = validLanes;
LABEL_71:
    ++v12;
  }
  while ( v12 < mNumLanes );
  v45 = (UFG::qArray<unsigned long,0> *)&v48;
  if ( !v9 )
    goto LABEL_73;
LABEL_74:
  v46 = UFG::AiDriverComponent::ChooseLane(v4, v45);
  if ( v8 )
    operator delete[](v8);
  return v46;
}

// File Line: 4813
// RVA: 0x6486A0
__int64 __fastcall UFG::AiDriverComponent::ChooseLane(
        UFG::RoadNetworkConnection *roadConn,
        UFG::qArray<unsigned long,0> *allowedLanes)
{
  UFG::qArray<unsigned long,0> *v2; // rdi
  unsigned __int64 size; // rbx
  UFG::allocator::free_link *v4; // r12
  unsigned int v5; // r14d
  unsigned int v6; // r15d
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rsi
  unsigned int v9; // ebp
  unsigned int v10; // r13d
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rdi
  __int64 v13; // rcx
  UFG::RoadNetworkLane *Path; // rax
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
  unsigned int v37; // [rsp+C0h] [rbp+18h]

  v2 = allowedLanes;
  size = allowedLanes->size;
  v4 = 0i64;
  v5 = 0;
  v6 = 0;
  if ( (_DWORD)size )
  {
    v7 = 4 * size;
    if ( !is_mul_ok(size, 4ui64) )
      v7 = -1i64;
    v4 = UFG::qMalloc(v7, "AiDriverComponent", 0i64);
    v6 = size;
  }
  v8 = 0i64;
  mem = 0i64;
  v9 = 0;
  v10 = 0;
  if ( (unsigned int)size > v6 )
  {
    if ( !(_DWORD)size )
      goto LABEL_60;
    v11 = 4 * size;
    if ( !is_mul_ok(size, 4ui64) )
      v11 = -1i64;
    v12 = UFG::qMalloc(v11, "AiDriverComponent", 0i64);
    if ( v4 )
      operator delete[](v4);
    v4 = v12;
    v6 = size;
    v2 = allowedLanes;
  }
  if ( (_DWORD)size )
  {
    v13 = 0i64;
    v33 = 0i64;
    v32 = size;
    do
    {
      v37 = *(unsigned int *)((char *)v2->p + v13);
      Path = UFG::qBezierPathCollectionMemImaged::GetPath(roadConn, v37);
      if ( UFG::RoadNetworkLane::IsPermissive(Path, 0) )
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
          size = v32;
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
          size = v32;
        }
        ++v9;
        *((_DWORD *)&v8->mNext + v23) = v37;
      }
      v13 = v33 + 4;
      v33 += 4i64;
      v32 = --size;
      v2 = allowedLanes;
    }
    while ( size );
    if ( v5 && (!v9 || UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) < 0.14285715) )
    {
      ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
      v30 = *((_DWORD *)&v4->mNext + ((v5 * HIWORD(ARandom::c_gen.i_seed)) >> 16));
      goto LABEL_61;
    }
  }
LABEL_60:
  ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
  v30 = *((_DWORD *)&v8->mNext + ((v9 * HIWORD(ARandom::c_gen.i_seed)) >> 16));
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
  UFG::qOffset64<UFG::RoadNetworkConnection *> *p_mStartConnection; // rsi
  unsigned int v3; // edi
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **p_mNext; // rbx
  UFG::SimObjectCVBase *v6; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  p_mStartConnection = &roadLane->mStartConnection;
  v3 = 0;
  p_mNext = &roadLane->mCars.mNode.mNext[-2].mNext;
  if ( p_mNext != (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **)&roadLane->mStartConnection )
  {
    do
    {
      v6 = (UFG::SimObjectCVBase *)p_mNext[9];
      if ( v6 )
      {
        m_Flags = v6->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v6);
        }
        else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v6,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                          v6,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
        if ( ComponentOfTypeHK && ComponentOfTypeHK->m_fCurrentForwardSpeed < 1.0 )
          ++v3;
      }
      p_mNext = &p_mNext[4][-2].mNext;
    }
    while ( p_mNext != (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **)p_mStartConnection );
  }
  return v3 >= numCarsForJam;
}

// File Line: 4875
// RVA: 0x645600
void __fastcall UFG::AiDriverComponent::BeginAttack(UFG::AiDriverComponent *this, CarCombat::Attack attack)
{
  if ( ((attack - 4) & 0xFFFFFFFD) == 0 )
  {
    switch ( this->m_DesiredOffset )
    {
      case Follow:
      case Behind:
      case RearCorner:
      case FrontCorner:
        attack = Ram;
        break;
      case PitPosition:
        attack = PitManeuvre;
        break;
      case Beside:
        attack = Sideswipe;
        break;
      case Front:
        attack = Block;
        break;
      default:
        break;
    }
  }
  this->m_CurrentAttack = attack;
  if ( attack == Ram )
    goto LABEL_11;
  if ( attack > Ram )
  {
    if ( attack <= PitManeuvre )
    {
      this->m_vFollowOffsetDesired.y = 0.0;
      return;
    }
    if ( attack == Block )
LABEL_11:
      this->m_vFollowOffsetDesired.x = 0.0;
  }
}

// File Line: 4917
// RVA: 0x64C7E0
void __fastcall UFG::AiDriverComponent::EndAttack(UFG::AiDriverComponent *this)
{
  UFG::VehicleSubjectComponent *m_pSimComponent; // rcx
  bool IsBoat; // al
  UFG::qVector3 *v4; // rax
  float y; // xmm0_4
  float z; // xmm2_4
  UFG::RoadSpaceComponent *v7; // rcx

  UFG::VehicleCombatStats::AttackOccured(&this->m_CombatStats, this->m_CurrentAttack);
  m_pSimComponent = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  if ( m_pSimComponent )
    IsBoat = UFG::VehicleSubjectComponent::IsBoat(m_pSimComponent);
  else
    IsBoat = 0;
  if ( IsBoat )
    v4 = &UFG::AiDriverComponent::mCombatBoatOffsets[this->m_DesiredOffset];
  else
    v4 = &UFG::AiDriverComponent::mCombatCarOffsets[this->m_DesiredOffset];
  y = v4->y;
  z = v4->z;
  if ( this->m_Side == Right )
    LODWORD(y) ^= _xmm[0];
  this->m_vFollowOffsetDesired.x = v4->x;
  this->m_vFollowOffsetDesired.y = y;
  this->m_vFollowOffsetDesired.z = z;
  v7 = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent;
  this->m_CurrentAttack = NumAttacks;
  if ( v7 && v7->m_pRacePosition && !UFG::RoadSpaceComponent::CleanupOnRaceDeleted(v7) && this->m_DrivingMode != 6 )
  {
    this->m_DrivingMode = 6;
    this->m_fReactionTime = 0.0;
    this->m_fDelayedStopDecel = 0.0;
    this->mModeSteeringLockEnabled = 0;
    this->mModeGasBrakeLockEnabled = 0;
    this->m_bIgnoreArrivalDirection = 0;
  }
}

// File Line: 4930
// RVA: 0x65EB60
char __fastcall UFG::AiDriverComponent::TimeWindowCloserThan(
        UFG::AiDriverComponent *this,
        UFG::qVector3 *p0,
        UFG::qVector3 *v0,
        UFG::qVector3 *p1,
        UFG::qVector3 *v1,
        float distance,
        UFG::AiDriverComponent::TimeWindowResult *result)
{
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  __m128 v11; // xmm8
  __m128 v12; // xmm7
  float v13; // xmm1_4
  __m128 y_low; // xmm6
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

  y_low = (__m128)LODWORD(v1->y);
  v11 = (__m128)LODWORD(p1->y);
  y_low.m128_f32[0] = y_low.m128_f32[0] - v0->y;
  v11.m128_f32[0] = v11.m128_f32[0] - p0->y;
  v7 = v1->x - v0->x;
  v12 = y_low;
  v12.m128_f32[0] = y_low.m128_f32[0] * y_low.m128_f32[0];
  y_low.m128_f32[0] = y_low.m128_f32[0] * v11.m128_f32[0];
  v8 = p1->x - p0->x;
  v9 = p1->z - p0->z;
  v10 = v1->z - v0->z;
  v11.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v8 * v8)) + (float)(v9 * v9);
  v12.m128_f32[0] = (float)(v12.m128_f32[0] + (float)(v7 * v7)) + (float)(v10 * v10);
  v13 = _mm_sqrt_ps(v11).m128_f32[0];
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] + (float)(v7 * v8)) + (float)(v10 * v9);
  if ( v13 >= 0.00000011920929 )
    v15 = y_low.m128_f32[0] / v13;
  else
    LODWORD(v15) = _mm_sqrt_ps(v12).m128_u32[0];
  v16 = 0.0;
  y_low.m128_f32[0] = y_low.m128_f32[0] * 2.0;
  result->fClosingSpeed = v15;
  v17 = y_low;
  v17.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                  - (float)((float)(v11.m128_f32[0] - (float)(distance * distance)) * (float)(v12.m128_f32[0] * 4.0));
  if ( v17.m128_f32[0] < 0.0 )
  {
    *(_QWORD *)&result->fEarliest = 0i64;
    return 0;
  }
  v19 = _mm_sqrt_ps(v17).m128_f32[0];
  v20 = v12.m128_f32[0] * 2.0;
  v21 = v19 - y_low.m128_f32[0];
  v22 = COERCE_FLOAT(y_low.m128_i32[0] ^ _xmm[0]) - v19;
  v23 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v19 - y_low.m128_f32[0]) & _xmm) * 0.001;
  if ( v20 > v23 )
    v23 = v20;
  if ( v20 <= (float)(COERCE_FLOAT(LODWORD(v22) & _xmm) * 0.001) )
    v20 = COERCE_FLOAT(LODWORD(v22) & _xmm) * 0.001;
  v24 = *(float *)&FLOAT_1_0;
  if ( v23 >= 0.00000011920929 )
  {
    v25 = v21 / v23;
  }
  else if ( y_low.m128_f32[0] <= 0.0 )
  {
    if ( y_low.m128_f32[0] >= 0.0 )
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
  if ( y_low.m128_f32[0] > 0.0 )
    goto LABEL_24;
  if ( y_low.m128_f32[0] >= 0.0 )
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
UFG::qVector3 *__fastcall UFG::AiDriverComponent::GetCombatOffset(
        UFG::qVector3 *result,
        int side,
        int index,
        bool isBoat)
{
  UFG::qVector3 *v5; // rcx
  float y; // xmm0_4
  float z; // eax
  UFG::qVector3 *v8; // rax

  if ( isBoat )
    v5 = &UFG::AiDriverComponent::mCombatBoatOffsets[index];
  else
    v5 = (UFG::qVector3 *)(0x140000000i64 + 12i64 * index + 34146368);
  y = v5->y;
  result->x = v5->x;
  z = v5->z;
  result->y = y;
  result->z = z;
  v8 = result;
  if ( side == 1 )
    LODWORD(result->y) = LODWORD(y) ^ _xmm[0];
  return v8;
}

// File Line: 4978
// RVA: 0x64D710
float __fastcall UFG::AiDriverComponent::GetAvoidanceFutureTime(UFG::AiDriverComponent *this)
{
  if ( this->m_bAllowedToPass )
    return *(float *)&FLOAT_1_0;
  else
    return FLOAT_2_0;
}

// File Line: 4987
// RVA: 0x64D730
float __fastcall UFG::AiDriverComponent::GetBumperGap(UFG::AiDriverComponent *this)
{
  UFG::VehicleSubjectComponent *m_pSimComponent; // rcx
  float result; // xmm0_4
  char v4; // al

  m_pSimComponent = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  if ( m_pSimComponent && UFG::VehicleSubjectComponent::IsBoat(m_pSimComponent) )
  {
    result = FLOAT_80_0;
    v4 = 1;
  }
  else
  {
    result = FLOAT_6_0;
    v4 = 0;
  }
  if ( this->m_bAllowedToPass )
  {
    if ( v4 )
      result = FLOAT_60_0;
    else
      result = 0.0;
  }
  if ( this->m_bTemporaryAllowedToPass )
  {
    if ( v4 )
      return FLOAT_60_0;
    else
      return 0.0;
  }
  return result;
}

// File Line: 5010
// RVA: 0x649960
void __fastcall UFG::AiDriverComponent::ComputeAvoidanceLimits(
        UFG::AiDriverComponent *this,
        UFG::qVector3 *my_position,
        UFG::qVector3 *avoid_hull,
        UFG::qVector3 *left_limit,
        UFG::qVector3 *right_limit,
        UFG::qVector3 *close_limit)
{
  int v7; // r11d
  __int64 v9; // rsi
  __int64 v10; // r14
  __int64 v11; // r15
  __int64 v12; // r12
  float v13; // xmm4_4
  int v14; // ebx
  int v15; // edi
  char *v16; // r9
  char *v17; // r8
  int v18; // ecx
  float *p_z; // rdx
  __int64 v20; // rbp
  float v21; // xmm2_4
  float v22; // xmm6_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float v25; // xmm5_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm5_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm1_4
  float x; // eax

  v7 = 0;
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
  p_z = &avoid_hull[2].z;
  v20 = -20i64 - (_QWORD)avoid_hull;
  do
  {
    v21 = *(p_z - 4);
    v22 = *(p_z - 5);
    v23 = (float)((float)(v22 * v22) + (float)(v21 * v21)) + (float)(*(p_z - 3) * *(p_z - 3));
    v24 = (float)(v22 * *(float *)((char *)&avoid_hull->y + (_QWORD)v16))
        - (float)(v21 * *(float *)((char *)&avoid_hull->x + (_QWORD)v16));
    if ( v23 < v13 )
    {
      v13 = v23;
      v15 = v18 - 2;
    }
    if ( v24 > 0.0 )
    {
      v7 = v18 - 2;
      v16 = (char *)p_z + v20;
    }
    if ( (float)((float)(*(p_z - 5) * *(float *)((char *)&avoid_hull->y + (_QWORD)v17))
               - (float)(*(p_z - 4) * *(float *)((char *)&avoid_hull->x + (_QWORD)v17))) < 0.0 )
    {
      v14 = v18 - 2;
      v17 = (char *)p_z + v20;
    }
    v25 = *(p_z - 2);
    v26 = (float)((float)(*(p_z - 1) * *(p_z - 1)) + (float)(v25 * v25)) + (float)(*p_z * *p_z);
    v27 = *(p_z - 1);
    v28 = (float)(v25 * *(float *)((char *)&avoid_hull->y + (_QWORD)v16))
        - (float)(v27 * *(float *)((char *)&avoid_hull->x + (_QWORD)v16));
    if ( v26 < v13 )
    {
      v13 = v26;
      v15 = v18 - 1;
    }
    if ( v28 > 0.0 )
    {
      v7 = v18 - 1;
      v16 = (char *)p_z + v9;
    }
    if ( (float)((float)(*(p_z - 2) * *(float *)((char *)&avoid_hull->y + (_QWORD)v17))
               - (float)(v27 * *(float *)((char *)&avoid_hull->x + (_QWORD)v17))) < 0.0 )
    {
      v14 = v18 - 1;
      v17 = (char *)p_z + v9;
    }
    v29 = p_z[2];
    if ( (float)((float)((float)(v29 * v29) + (float)(p_z[1] * p_z[1])) + (float)(p_z[3] * p_z[3])) < v13 )
    {
      v13 = (float)((float)(p_z[2] * p_z[2]) + (float)(p_z[1] * p_z[1])) + (float)(p_z[3] * p_z[3]);
      v15 = v18;
    }
    if ( (float)((float)(p_z[1] * *(float *)((char *)&avoid_hull->y + (_QWORD)v16))
               - (float)(v29 * *(float *)((char *)&avoid_hull->x + (_QWORD)v16))) > 0.0 )
    {
      v7 = v18;
      v16 = (char *)p_z + v10;
    }
    if ( (float)((float)(p_z[1] * *(float *)((char *)&avoid_hull->y + (_QWORD)v17))
               - (float)(v29 * *(float *)((char *)&avoid_hull->x + (_QWORD)v17))) < 0.0 )
    {
      v14 = v18;
      v17 = (char *)p_z + v10;
    }
    v30 = p_z[5];
    if ( (float)((float)((float)(v30 * v30) + (float)(p_z[4] * p_z[4])) + (float)(p_z[6] * p_z[6])) < v13 )
    {
      v13 = (float)((float)(p_z[5] * p_z[5]) + (float)(p_z[4] * p_z[4])) + (float)(p_z[6] * p_z[6]);
      v15 = v18 + 1;
    }
    if ( (float)((float)(p_z[4] * *(float *)((char *)&avoid_hull->y + (_QWORD)v16))
               - (float)(v30 * *(float *)((char *)&avoid_hull->x + (_QWORD)v16))) > 0.0 )
    {
      v7 = v18 + 1;
      v16 = (char *)p_z + v11;
    }
    if ( (float)((float)(p_z[4] * *(float *)((char *)&avoid_hull->y + (_QWORD)v17))
               - (float)(v30 * *(float *)((char *)&avoid_hull->x + (_QWORD)v17))) < 0.0 )
    {
      v14 = v18 + 1;
      v17 = (char *)p_z + v11;
    }
    v31 = p_z[8];
    if ( (float)((float)((float)(p_z[7] * p_z[7]) + (float)(v31 * v31)) + (float)(p_z[9] * p_z[9])) < v13 )
    {
      v13 = (float)((float)(p_z[7] * p_z[7]) + (float)(p_z[8] * p_z[8])) + (float)(p_z[9] * p_z[9]);
      v15 = v18 + 2;
    }
    if ( (float)((float)(p_z[7] * *(float *)((char *)&avoid_hull->y + (_QWORD)v16))
               - (float)(v31 * *(float *)((char *)&avoid_hull->x + (_QWORD)v16))) > 0.0 )
    {
      v7 = v18 + 2;
      v16 = (char *)p_z + v12;
    }
    if ( (float)((float)(p_z[7] * *(float *)((char *)&avoid_hull->y + (_QWORD)v17))
               - (float)(v31 * *(float *)((char *)&avoid_hull->x + (_QWORD)v17))) < 0.0 )
    {
      v14 = v18 + 2;
      v17 = (char *)p_z + v12;
    }
    v18 += 5;
    p_z += 15;
  }
  while ( v18 - 2 < 16 );
  y = avoid_hull[v7].y;
  z = avoid_hull[v7].z;
  right_limit->x = avoid_hull[v7].x;
  right_limit->y = y;
  right_limit->z = z;
  v34 = avoid_hull[v14].y;
  v35 = avoid_hull[v14].z;
  left_limit->x = avoid_hull[v14].x;
  left_limit->y = v34;
  left_limit->z = v35;
  v36 = avoid_hull[v15].z;
  x = avoid_hull[v15].x;
  close_limit->y = avoid_hull[v15].y;
  close_limit->z = v36;
  close_limit->x = x;
}

// File Line: 5082
// RVA: 0x65B0B0
UFG::qVector3 *__fastcall UFG::AiDriverComponent::SteerToAvoidGeometry(
        UFG::AiDriverComponent *this,
        UFG::qVector3 *result,
        UFG::qVector3 *steer_to_position,
        float steer_to_distance)
{
  Render::DebugDrawContext *Context; // r12
  float x; // xmm8_4
  float y; // xmm9_4
  float z; // xmm13_4
  UFG::SimComponent *m_pSimComponent; // r14
  hkpSimpleShapePhantom *m_pCastingPhantom; // rdx
  UFG::qVector3 *v14; // rsi
  float v15; // xmm10_4
  float v16; // xmm5_4
  float v17; // xmm11_4
  float v18; // xmm4_4
  float v19; // xmm12_4
  __m128 x_low; // xmm7
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
  char p1[20]; // [rsp+40h] [rbp-88h] BYREF
  float v53; // [rsp+54h] [rbp-74h]
  float v54; // [rsp+58h] [rbp-70h]
  float v55; // [rsp+5Ch] [rbp-6Ch]
  float v56; // [rsp+60h] [rbp-68h]
  float v57; // [rsp+64h] [rbp-64h]
  __m128 v58; // [rsp+68h] [rbp-60h] BYREF
  void **v59; // [rsp+78h] [rbp-50h] BYREF
  int v60; // [rsp+80h] [rbp-48h]
  char v61; // [rsp+88h] [rbp-40h]
  unsigned __int64 v62; // [rsp+98h] [rbp-30h]
  float v63; // [rsp+A0h] [rbp-28h]
  __m128 v64; // [rsp+A8h] [rbp-20h]
  __m128 v65; // [rsp+B8h] [rbp-10h] BYREF
  int v66; // [rsp+C8h] [rbp+0h]
  int v67; // [rsp+CCh] [rbp+4h]
  __int64 v68; // [rsp+D8h] [rbp+10h]
  float v69; // [rsp+1C8h] [rbp+100h]
  float v70; // [rsp+1D8h] [rbp+110h]
  float radius; // [rsp+1E0h] [rbp+118h]
  float *v72; // [rsp+1E8h] [rbp+120h]

  v68 = -2i64;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  x = steer_to_position->x;
  v55 = steer_to_position->x;
  y = steer_to_position->y;
  v54 = y;
  z = steer_to_position->z;
  v56 = z;
  m_pSimComponent = this->m_pVehicleSubject.m_pSimComponent;
  if ( m_pSimComponent )
  {
    m_pCastingPhantom = this->m_pCastingPhantom;
    if ( !m_pCastingPhantom->m_world )
      UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, m_pCastingPhantom, 0);
    v14 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[17].__vecDelDtor)(m_pSimComponent);
    v15 = v14->z;
    v16 = steer_to_position->z - v15;
    v17 = v14->y;
    v18 = steer_to_position->y - v17;
    v19 = v14->x;
    x_low = (__m128)LODWORD(steer_to_position->x);
    x_low.m128_f32[0] = x_low.m128_f32[0] - v14->x;
    v21 = x_low;
    v21.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v18 * v18)) + (float)(v16 * v16);
    v22 = _mm_sqrt_ps(v21).m128_f32[0];
    v23 = FLOAT_0_000099999997;
    if ( v22 >= 0.000099999997 )
      v23 = v22;
    if ( steer_to_distance < v23 )
    {
      x_low.m128_f32[0] = x_low.m128_f32[0] * (float)(steer_to_distance / v23);
      v18 = (float)(steer_to_distance / v23) * v18;
      v16 = (float)(steer_to_distance / v23) * v16;
    }
    v24 = fsqrt((float)((float)(v18 * v18) + (float)(x_low.m128_f32[0] * x_low.m128_f32[0])) + (float)(v16 * v16));
    v25 = this->m_pRoadSpace.m_pSimComponent;
    v26 = v17
        + (float)((float)(v24 * *((float *)&v25[27].m_pSimObject + 1))
                + (float)((float)(v18 - (float)(v24 * *((float *)&v25[27].m_pSimObject + 1))) * 0.25));
    v27 = v19
        + (float)((float)((float)(x_low.m128_f32[0] - (float)(v24 * *(float *)&v25[27].m_pSimObject)) * 0.25)
                + (float)(v24 * *(float *)&v25[27].m_pSimObject));
    v28 = UFG::qVector3::msDirUp.y * (float)(UFG::AiDriverComponent::m_fAvoidanceCastingRadius + 0.40000001);
    v29 = UFG::qVector3::msDirUp.x * (float)(UFG::AiDriverComponent::m_fAvoidanceCastingRadius + 0.40000001);
    *(float *)&p1[16] = v19 + v29;
    v53 = v17 + v28;
    v54 = v15
        + (float)(UFG::qVector3::msDirUp.z * (float)(UFG::AiDriverComponent::m_fAvoidanceCastingRadius + 0.40000001));
    v56 = v29 + v27;
    v57 = v28 + v26;
    v59 = &hkpSimpleClosestContactCollector::`vftable;
    v61 = 0;
    v64 = _mm_shuffle_ps(v64, _mm_unpackhi_ps(v64, (__m128)xmmword_141A712A0), 196);
    v60 = 2139095022;
    v66 = 872415232;
    v67 = 872415232;
    v58 = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT(v19 + v29), (__m128)LODWORD(v54)),
            _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT(v17 + v28), (__m128)(unsigned int)FLOAT_1_0));
    v65 = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT(v29 + v27), (__m128)v58.m128_u32[0]),
            _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT(v28 + v26), (__m128)(unsigned int)FLOAT_1_0));
    ((void (__fastcall *)(hkpSimpleShapePhantom *, __m128 *, __m128 *, void ***, void ***))this->m_pCastingPhantom->vfptr[7].__first_virtual_table_function__)(
      this->m_pCastingPhantom,
      &v58,
      &v65,
      &v59,
      &v59);
    if ( v61 )
    {
      v30 = (__m128)(unsigned int)v62;
      v58.m128_u64[0] = v62;
      v31 = *((float *)&v62 + 1);
      v32 = v63;
      v58.m128_f32[2] = v63;
      v70 = v54 - *(float *)&v62;
      v33 = v53 - v57;
      v69 = *(float *)&p1[16] - v56;
      *(_QWORD *)&p1[8] = v62;
      *(float *)&p1[16] = v63;
      v34 = (__m128)v64.m128_u32[1];
      v34.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v64.m128_f32[0] * v64.m128_f32[0]))
                      + (float)(v64.m128_f32[2] * v64.m128_f32[2]);
      if ( v34.m128_f32[0] == 0.0 )
        v35 = 0.0;
      else
        v35 = 1.0 / _mm_sqrt_ps(v34).m128_f32[0];
      v36 = v35 * v64.m128_f32[2];
      v37 = v35 * v64.m128_f32[1];
      v38 = v35 * v64.m128_f32[0];
      v39 = UFG::qVector3::msDirUp.x;
      v40 = UFG::qVector3::msDirUp.y;
      v41 = (float)((float)(UFG::qVector3::msDirUp.x * v38) + (float)(v37 * UFG::qVector3::msDirUp.y))
          + (float)(v36 * UFG::qVector3::msDirUp.z);
      if ( v41 > cosf(1.0471976) )
      {
        x = v55;
        y = v54;
        z = v56;
      }
      else
      {
        *(float *)p1 = v38;
        *(float *)&p1[4] = v37;
        *(float *)&p1[8] = v36;
        if ( (float)((float)((float)(v38 * v69) + (float)(v37 * v33)) + (float)(v36 * v70)) > 0.0 )
        {
          if ( (float)((float)(v37 * v69) - (float)(v33 * v38)) <= 0.0 )
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
          *(float *)&p1[8] = v42;
          *(float *)&p1[4] = v43;
          *(float *)p1 = v44 - v45;
        }
        *(float *)&p1[8] = (float)(v38 * 1.5) + v30.m128_f32[0];
        *(float *)&p1[12] = (float)(v37 * 1.5) + v31;
        *(float *)&p1[16] = (float)(v36 * 1.5) + v32;
        v46 = UFG::RoadSpaceComponent::SteerTo(
                (UFG::qVector3 *)&v58.m128_u16[4],
                v14,
                radius,
                (UFG::qVector3 *)&p1[8],
                (UFG::qVector3 *)p1);
        x = v46->x;
        y = v46->y;
        z = v46->z;
        v30.m128_f32[0] = (float)((float)((float)(v30.m128_f32[0] - v14->x) * (float)(v30.m128_f32[0] - v14->x))
                                + (float)((float)(v31 - v14->y) * (float)(v31 - v14->y)))
                        + (float)((float)(v32 - v14->z) * (float)(v32 - v14->z));
        v47 = _mm_sqrt_ps(v30).m128_f32[0]
            - *(float *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[24].__vecDelDtor)(m_pSimComponent);
        v48 = *v72;
        if ( *v72 >= v47 )
          v48 = v47;
        *v72 = v48;
        if ( this->m_AvoidanceDebug )
        {
          Render::DebugDrawContext::DrawPillar(
            Context,
            steer_to_position,
            0.17,
            0.17,
            &UFG::qColour::DodgerBlue,
            &UFG::qMatrix44::msIdentity,
            0i64);
          *(float *)p1 = x + (float)(UFG::qVector3::msDirUp.x * 0.69999999);
          *(float *)&p1[4] = y + (float)(UFG::qVector3::msDirUp.y * 0.69999999);
          *(float *)&p1[8] = z + (float)(UFG::qVector3::msDirUp.z * 0.69999999);
          v49 = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + steer_to_position->z;
          v50 = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + steer_to_position->y;
          v58.m128_f32[2] = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + steer_to_position->x;
          v58.m128_f32[3] = v50;
          *(float *)&v59 = v49;
          Render::DebugDrawContext::DrawLine(
            Context,
            (UFG::qVector3 *)&v58.m128_u16[4],
            (UFG::qVector3 *)p1,
            &UFG::qColour::DodgerBlue,
            &UFG::qMatrix44::msIdentity,
            0i64,
            0);
          v58.m128_f32[2] = x + (float)(UFG::qVector3::msDirUp.x * 0.69999999);
          v58.m128_f32[3] = y + (float)(UFG::qVector3::msDirUp.y * 0.69999999);
          *(float *)&v59 = z + (float)(UFG::qVector3::msDirUp.z * 0.69999999);
          Render::DebugDrawContext::DrawSphere(
            Context,
            (UFG::qVector3 *)&v58.m128_u16[4],
            0.69999999,
            &UFG::qColour::DodgerBlue,
            &UFG::qMatrix44::msIdentity,
            0i64);
        }
      }
    }
    result->x = x;
    result->y = y;
    result->z = z;
    v59 = &hkpCdPointCollector::`vftable;
  }
  else
  {
    result->x = x;
    result->y = y;
    result->z = z;
  }
  return result;
}

// File Line: 5371
// RVA: 0x652500
bool __fastcall UFG::AiDriverComponent::LaneContainsPlayer(UFG::AiDriverComponent *this, UFG::RoadNetworkGuide *guide)
{
  signed __int16 m_Flags; // r8
  UFG::CharacterOccupantComponent *ComponentOfType; // rax
  UFG::SimObjectGame *CurrentVehicle; // rax
  __int16 v6; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  result = LocalPlayer
        && ((m_Flags = LocalPlayer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                     LocalPlayer,
                                                                     UFG::CharacterOccupantComponent::_TypeUID))
           : (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     LocalPlayer,
                                                                     UFG::CharacterOccupantComponent::_TypeUID)))
          : (ComponentOfType = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent),
            ComponentOfType
         && (CurrentVehicle = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(ComponentOfType)) != 0i64
         && ((v6 = CurrentVehicle->m_Flags, (v6 & 0x4000) == 0)
           ? (v6 >= 0
            ? ((v6 & 0x2000) != 0 || (v6 & 0x1000) != 0
             ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      CurrentVehicle,
                                      UFG::RoadSpaceComponent::_TypeUID))
             : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                      CurrentVehicle,
                                      UFG::RoadSpaceComponent::_TypeUID)))
            : (ComponentOfTypeHK = CurrentVehicle->m_Components.p[24].m_pComponent))
           : (ComponentOfTypeHK = CurrentVehicle->m_Components.p[24].m_pComponent),
             ComponentOfTypeHK && ComponentOfTypeHK != (UFG::SimComponent *)-376i64))
        && guide->m_CurrentLocation.m_CurrentLane == (UFG::RoadNetworkLane *)ComponentOfTypeHK[6].m_BoundComponentHandles.mNode.mNext;
  return result;
}

// File Line: 5396
// RVA: 0x65DCB0
UFG::qVector3 *__fastcall UFG::AiDriverComponent::SteerToBetterLane(
        UFG::AiDriverComponent *this,
        UFG::qVector3 *result,
        UFG::qVector3 *steer_to_position)
{
  UFG::SimComponent *m_pSimComponent; // rsi
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  UFG::RoadNetworkGuide *p_mNext; // rsi
  UFG::RoadNetworkGuide *m_pPointer; // rcx
  UFG::SimObjectVehicle *m_SimObj; // rcx
  __int16 m_Flags; // dx
  UFG::CarPhysicsMoverComponent *ComponentOfTypeHK; // rax
  UFG::RoadNetworkLane *m_CurrentLane; // rbx
  bool v16; // cl
  UFG::RoadNetworkNode *v17; // r14
  unsigned int v18; // r15d
  unsigned int v19; // r12d
  UFG::RoadNetworkLane *Lane; // r14
  UFG::RoadNetworkLocation *Name; // rax
  float DistanceAlongSpline; // xmm0_4
  unsigned int NumberOfCarsInLaneAheadOfDistance; // ebx
  UFG::RoadNetworkLocation *v24; // rax
  float v25; // xmm0_4
  UFG::RoadNetworkLocation *TargetLocation; // rax
  float v27; // xmm1_4
  float v28; // xmm0_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-68h] BYREF
  unsigned int whichLanes; // [rsp+90h] [rbp+8h] BYREF

  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  x = steer_to_position->x;
  y = steer_to_position->y;
  z = steer_to_position->z;
  if ( !m_pSimComponent
    || (p_mNext = (UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext, !p_mNext->m_Attached)
    || (m_pPointer = p_mNext->m_NextGuide.m_pPointer) == 0i64 )
  {
    result->x = x;
    result->y = y;
    result->z = z;
    return result;
  }
  m_SimObj = (UFG::SimObjectVehicle *)m_pPointer->m_SimObj;
  if ( !m_SimObj
    || (m_Flags = m_SimObj->m_Flags, (m_Flags & 0x4000) != 0)
    || (m_Flags >= 0
      ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? (ComponentOfTypeHK = (UFG::CarPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 m_SimObj,
                                                                 UFG::CarPhysicsMoverComponent::_TypeUID))
       : (ComponentOfTypeHK = (UFG::CarPhysicsMoverComponent *)UFG::SimObject::GetComponentOfType(
                                                                 m_SimObj,
                                                                 UFG::CarPhysicsMoverComponent::_TypeUID)))
      : (ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>(m_SimObj)),
        !ComponentOfTypeHK) )
  {
    result->x = x;
    result->y = y;
    result->z = z;
    return result;
  }
  if ( ComponentOfTypeHK->mForwardSpeed >= 0.0049999999 )
    goto LABEL_32;
  whichLanes = -1;
  m_CurrentLane = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext)->m_CurrentLane;
  v16 = UFG::PhysicsMoverInterface::GetLOD((UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent) != LOD_LOW
     && UFG::RoadNetworkGuide::LaneChangeAvailable(p_mNext, &whichLanes)
     && !UFG::AiDriverComponent::LaneContainsPlayer(this, p_mNext);
  v17 = m_CurrentLane->mNode.mOffset
      ? (UFG::RoadNetworkNode *)((char *)m_CurrentLane + m_CurrentLane->mNode.mOffset)
      : 0i64;
  if ( !v16 )
    goto LABEL_32;
  if ( whichLanes == 2 )
  {
    v18 = 2;
  }
  else
  {
    if ( whichLanes != 1 )
    {
LABEL_32:
      result->x = x;
      result->y = y;
      result->z = z;
      return result;
    }
    v18 = 1;
  }
  v19 = UFG::RoadNetworkGuide::GetChangeLaneIndex(p_mNext, v18);
  Lane = UFG::RoadNetworkNode::GetLane(v17, v19);
  Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
  DistanceAlongSpline = UFG::RoadNetworkLocation::GetDistanceAlongSpline(Name);
  NumberOfCarsInLaneAheadOfDistance = UFG::RoadNetworkLane::GetNumberOfCarsInLaneAheadOfDistance(
                                        m_CurrentLane,
                                        DistanceAlongSpline);
  v24 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
  v25 = UFG::RoadNetworkLocation::GetDistanceAlongSpline(v24);
  if ( (unsigned int)UFG::RoadNetworkLane::GetNumberOfCarsInLaneAheadOfDistance(Lane, v25) >= NumberOfCarsInLaneAheadOfDistance
    || !UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(p_mNext, Lane)
    || !UFG::RoadNetworkGuide::TryGetPossibleSharedDestination(
          p_mNext,
          v19,
          (unsigned __int8)this->m_pRoadSpace.m_pSimComponent[30].m_SafePointerList.mNode.mNext) )
  {
    goto LABEL_32;
  }
  UFG::AiDriverComponent::ChangeLane(this, v18);
  TargetLocation = (UFG::RoadNetworkLocation *)UFG::RoadNetworkGuide::GetTargetLocation((UFG::RippleGenerator *)p_mNext);
  UFG::RoadNetworkLocation::GetPos(TargetLocation, &resulta);
  v27 = resulta.y;
  result->x = resulta.x;
  v28 = resulta.z;
  result->y = v27;
  result->z = v28;
  return result;
}

// File Line: 5491
// RVA: 0x652630
bool __fastcall UFG::AiDriverComponent::AvoidableOverlap::MergeLimits(
        UFG::AiDriverComponent::AvoidableOverlap *this,
        UFG::AiDriverComponent::AvoidableOverlap *overlap)
{
  float y; // xmm5_4
  float x; // xmm3_4
  bool result; // al
  float v5; // xmm7_4
  float v6; // xmm8_4
  float z; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm6_4
  float v16; // xmm4_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm5_4
  float v20; // xmm9_4
  bool v21; // r8

  y = overlap->m_LeftRay.y;
  x = overlap->m_LeftRay.x;
  result = 0;
  v5 = this->m_LeftRay.x;
  v6 = this->m_LeftRay.y;
  if ( (float)((float)(v5 * y) - (float)(x * v6)) > 0.0
    && (float)((float)(v5 * overlap->m_RightRay.y) - (float)(v6 * overlap->m_RightRay.x)) < 0.0 )
  {
    z = overlap->m_LeftRay.z;
    this->m_LeftRay.x = x;
    this->m_LeftRay.y = y;
    this->m_LeftRay.z = z;
LABEL_7:
    result = 1;
    goto LABEL_8;
  }
  if ( (float)((float)(x * v6) - (float)(v5 * y)) > 0.0
    && (float)((float)(x * this->m_RightRay.y) - (float)(y * this->m_RightRay.x)) < 0.0 )
  {
    v8 = this->m_LeftRay.z;
    overlap->m_LeftRay.x = v5;
    overlap->m_LeftRay.y = v6;
    overlap->m_LeftRay.z = v8;
    goto LABEL_7;
  }
LABEL_8:
  v9 = this->m_RightRay.x;
  v10 = this->m_RightRay.y;
  if ( (float)((float)(v9 * overlap->m_LeftRay.y) - (float)(v10 * overlap->m_LeftRay.x)) <= 0.0
    || (v11 = overlap->m_RightRay.y, v12 = overlap->m_RightRay.x, (float)((float)(v9 * v11) - (float)(v10 * v12)) >= 0.0) )
  {
    if ( (float)((float)(overlap->m_RightRay.x * this->m_LeftRay.y) - (float)(overlap->m_RightRay.y * this->m_LeftRay.x)) <= 0.0
      || (float)((float)(overlap->m_RightRay.x * v10) - (float)(overlap->m_RightRay.y * v9)) >= 0.0 )
    {
      if ( !result )
        return result;
    }
    else
    {
      v14 = this->m_RightRay.z;
      overlap->m_RightRay.x = v9;
      result = 1;
      overlap->m_RightRay.z = v14;
      overlap->m_RightRay.y = v10;
    }
  }
  else
  {
    v13 = overlap->m_RightRay.z;
    this->m_RightRay.x = v12;
    result = 1;
    this->m_RightRay.z = v13;
    this->m_RightRay.y = v11;
  }
  v15 = this->m_CloseLimit.y;
  v16 = this->m_CloseLimit.x;
  v17 = this->m_CloseLimit.z;
  v18 = overlap->m_CloseLimit.y;
  v19 = overlap->m_CloseLimit.x;
  v20 = overlap->m_CloseLimit.z;
  if ( (float)((float)((float)(v16 * v16) + (float)(v15 * v15)) + (float)(v17 * v17)) >= (float)((float)((float)(v19 * v19) + (float)(v18 * v18))
                                                                                               + (float)(v20 * v20)) )
  {
    this->m_CloseLimit.x = v19;
    this->m_CloseLimit.y = v18;
    this->m_CloseLimit.z = v20;
  }
  else
  {
    overlap->m_CloseLimit.x = v16;
    overlap->m_CloseLimit.y = v15;
    overlap->m_CloseLimit.z = v17;
  }
  v21 = this->m_CoChaser && overlap->m_CoChaser;
  overlap->m_CoChaser = v21;
  this->m_CoChaser = v21;
  ++overlap->m_Generation;
  ++this->m_Generation;
  return result;
}

// File Line: 5553
// RVA: 0x644800
void __fastcall UFG::AiDriverComponent::AddAvoidableOverlap(
        UFG::AiDriverComponent *this,
        UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> *list,
        UFG::allocator::free_link *avoidable_subject,
        UFG::AiDriverComponent::TimeWindowResult *time_window,
        bool co_chaser)
{
  UFG::allocator::free_link *v8; // rax
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v9; // r10
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *mNext; // rcx
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *mPrev; // rax
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v12; // rax

  v8 = UFG::qMalloc(0x58ui64, "AvoidableOverlap", 0i64);
  v9 = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)v8;
  if ( v8 )
  {
    v8->mNext = v8;
    v8[1].mNext = v8;
    HIDWORD(v8[2].mNext) = 0;
    LOBYTE(v8[2].mNext) = co_chaser;
    *(float *)&v8[3].mNext = time_window->fClosingSpeed;
    HIDWORD(v8[3].mNext) = LODWORD(time_window->fEarliest);
    *(float *)&v8[4].mNext = time_window->fLatest;
    v8[5].mNext = avoidable_subject;
  }
  else
  {
    v9 = 0i64;
  }
  mNext = list->mNode.mNext;
  if ( mNext == (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)list )
    goto LABEL_9;
  while ( time_window->fEarliest <= *((float *)&mNext[1].mNext + 1) )
  {
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)list )
      goto LABEL_9;
  }
  mPrev = mNext->mPrev;
  mPrev->mNext = v9;
  v9->mPrev = mPrev;
  v9->mNext = mNext;
  mNext->mPrev = v9;
  if ( mNext == (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)list )
  {
LABEL_9:
    v12 = list->mNode.mPrev;
    v12->mNext = v9;
    v9->mPrev = v12;
    v9->mNext = &list->mNode;
    list->mNode.mPrev = v9;
  }
}

// File Line: 5570
// RVA: 0x651330
void __fastcall UFG::AiDriverComponent::HandleCollision(
        UFG::AiDriverComponent *this,
        UFG::SimObject *pAttackerSimObject,
        float damage,
        __int64 dt)
{
  __int64 v4; // r8
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::SimComponent *m_pPointer; // rcx
  bool v8; // dl
  UFG::SimObject *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pComponent; // rsi
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rbx
  float *v13; // rax

  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent
    && (float)(3.5999999 * *((float *)&m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1)) > UFG::gHighSpeedCollisionThreshold )
  {
    m_pPointer = this->m_pChaseVehicleSubject.m_pPointer;
    v8 = m_pPointer
      && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *, UFG::SimObject *, __int64, __int64))m_pPointer->vfptr[46].__vecDelDtor)(
           m_pPointer,
           pAttackerSimObject,
           v4,
           dt);
    m_pSimObject = this->m_pSimObject;
    m_pComponent = 0i64;
    v11 = m_pSimObject ? m_pSimObject->m_Components.p[16].m_pComponent : 0i64;
    if ( v8 && v11 )
    {
      if ( m_pSimObject )
        m_pComponent = (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent;
      v12 = this->m_pChaseVehicleSubject.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
      v13 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v12->vfptr[17].__vecDelDtor)(v12);
      if ( (float)((float)((float)(v13[1] - m_pComponent->mWorldTransform.v3.y)
                         * (float)(v13[1] - m_pComponent->mWorldTransform.v3.y))
                 + (float)((float)(*v13 - m_pComponent->mWorldTransform.v3.x)
                         * (float)(*v13 - m_pComponent->mWorldTransform.v3.x))) < UFG::gHighSpeedCollisionDistanceSqToChaseeThreshold )
        this->m_iLastHighSpeedCollisionTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    }
  }
}

// File Line: 5591
// RVA: 0x659B70
char __fastcall UFG::AiDriverComponent::ShouldAvoid(
        UFG::AiDriverComponent *this,
        UFG::VehicleSubjectComponent *my_subject,
        UFG::CameraSubject *avoidable_subject,
        bool *co_chaser)
{
  bool v9; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  bool v11; // bp
  char v12; // r15
  bool v13; // bl
  double v14; // xmm0_8
  float v15; // xmm11_4
  float *v16; // rax
  float v17; // xmm6_4
  float v18; // xmm12_4
  float v19; // xmm7_4
  float *v20; // rax
  float v21; // xmm9_4
  float v22; // xmm10_4
  float v23; // xmm12_4
  float *v24; // rax
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm8_4
  float *v28; // rax
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm11_4
  UFG::SimObjectCVBase *m_pSimObject; // rbp
  _WORD *v33; // r12
  UFG::SimObject *m_pPointer; // rbx
  UFG::SimComponent *m_pComponent; // rax
  __int16 v36; // cx
  UFG::SimObject *v37; // rbx
  UFG::SimObject *v38; // rbx
  bool v39; // cl
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *v41; // rax
  UFG::SimComponent *m_pSimComponent; // rcx
  bool v43; // al
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **p_mNext; // rbx
  UFG::RoadNetworkLane *m_CurrentLane; // rcx
  char *v46; // rcx

  if ( !avoidable_subject )
    return 0;
  *co_chaser = 0;
  v9 = ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[41].__vecDelDtor)(avoidable_subject) == 0;
  vfptr = avoidable_subject->vfptr;
  if ( v9 )
  {
    if ( !((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))vfptr[37].__vecDelDtor)(avoidable_subject) )
      return 1;
    m_pSimObject = (UFG::SimObjectCVBase *)avoidable_subject->m_pSimObject;
    v33 = 0i64;
    if ( this->m_DrivingMode != 2 || (m_pPointer = this->m_PathingTarget.m_pPointer) == 0i64 )
    {
LABEL_54:
      v37 = this->m_pRoadSpace.m_pSimComponent[26].m_pSimObject;
      if ( !v37
        || (v37 != m_pSimObject
         || ((*co_chaser = 1, this->m_DrivingMode != 3) || this->m_DesiredOffset != Behind)
         && this->m_fTimeNearOffset <= 0.0
         && this->m_CurrentAttack == NumAttacks)
        && (v37 != (UFG::SimObject *)((__int64 (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[25].__vecDelDtor)(avoidable_subject)
         || (*co_chaser = 1, this->m_CurrentAttack == NumAttacks)
         && !((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[40].__vecDelDtor)(avoidable_subject))
        && avoidable_subject != this->m_pEscortEnemyVehicleSubject.m_pPointer )
      {
        if ( !((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))my_subject->vfptr[46].__vecDelDtor)(my_subject)
          || (v38 = my_subject->m_pSimObject,
              v38 != (UFG::SimObject *)((__int64 (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[25].__vecDelDtor)(avoidable_subject)) )
        {
          v39 = this->m_bAllowedToPass || this->m_bTemporaryAllowedToPass;
          if ( !LOBYTE(this->m_pRoadSpace.m_pSimComponent[8].m_Flags)
            || v39
            || UFG::VehicleSubjectComponent::IsBoat(my_subject) )
          {
            return 1;
          }
          if ( !((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[33].__vecDelDtor)(avoidable_subject) )
          {
            if ( !m_pSimObject )
              return 1;
            m_Flags = m_pSimObject->m_Flags;
            if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
              v41 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pSimObject);
            else
              v41 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pSimObject,
                                                 UFG::AiDriverComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pSimObject,
                                                 UFG::AiDriverComponent::_TypeUID));
            if ( !v41 )
              return 1;
            m_pSimComponent = v41->m_pRoadSpace.m_pSimComponent;
            if ( !m_pSimComponent )
              return 1;
            v43 = v41->m_bAllowedToPass || v41->m_bTemporaryAllowedToPass;
            if ( !LOBYTE(m_pSimComponent[8].m_Flags) || v43 )
              return 1;
            p_mNext = &m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext;
            if ( m_pSimComponent != (UFG::SimComponent *)-376i64 )
            {
              m_CurrentLane = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext)->m_CurrentLane;
              if ( m_CurrentLane )
              {
                if ( m_CurrentLane->mNode.mOffset )
                  v33 = (_WORD *)((char *)m_CurrentLane + m_CurrentLane->mNode.mOffset);
                if ( *v33 == 1 )
                {
                  v46 = *(char **)&this->m_pRoadSpace.m_pSimComponent[8].m_TypeUID;
                  if ( !v46 || v46 != (char *)p_mNext )
                    return 1;
                }
              }
            }
          }
        }
      }
      return 0;
    }
    if ( m_pSimObject == m_pPointer )
      return 0;
    if ( !m_pSimObject )
    {
      m_pComponent = 0i64;
      goto LABEL_53;
    }
    v36 = m_pSimObject->m_Flags;
    if ( (v36 & 0x4000) != 0 )
      goto LABEL_51;
    if ( v36 < 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[30].m_pComponent;
      goto LABEL_53;
    }
    if ( (v36 & 0x2000) != 0 || (v36 & 0x1000) != 0 )
LABEL_51:
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::VehicleOccupantComponent::_TypeUID);
    else
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_53:
    if ( Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent) == (hkLocalFrameGroup *)m_pPointer )
      return 0;
    goto LABEL_54;
  }
  if ( ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))vfptr[42].__vecDelDtor)(avoidable_subject) )
    return 0;
  v11 = this->m_fAvoidStopTimer > 0.0;
  v12 = ((__int64 (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[48].__vecDelDtor)(avoidable_subject);
  v13 = ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this)
     && ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[47].__vecDelDtor)(avoidable_subject);
  if ( v12 || v13 || v11 )
  {
    v14 = ((double (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[21].__vecDelDtor)(avoidable_subject);
    v15 = *(float *)&v14;
    v16 = (float *)((__int64 (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[17].__vecDelDtor)(avoidable_subject);
    v17 = *v16;
    v18 = v16[1];
    v19 = v16[2];
    v20 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))my_subject->vfptr[19].__vecDelDtor)(my_subject);
    v21 = (float)((float)((float)(v18 * v20[4]) + (float)(v17 * *v20)) + (float)(v19 * v20[8])) + v20[12];
    v22 = (float)((float)((float)(v18 * v20[5]) + (float)(v17 * v20[1])) + (float)(v19 * v20[9])) + v20[13];
    v23 = (float)((float)((float)(v18 * v20[6]) + (float)(v17 * v20[2])) + (float)(v19 * v20[10])) + v20[14];
    v24 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))my_subject->vfptr[23].__vecDelDtor)(my_subject);
    v25 = *v24 - *(float *)&v14;
    v26 = v24[1] - *(float *)&v14;
    v27 = v24[2] - *(float *)&v14;
    v28 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))my_subject->vfptr[24].__vecDelDtor)(my_subject);
    v29 = *(float *)&v14 + *v28;
    v30 = *(float *)&v14 + v28[1];
    v31 = v15 + v28[2];
    if ( v23 > v27 )
      v27 = v23;
    if ( v27 >= v31 )
      v27 = v31;
    if ( v22 > v26 )
      v26 = v22;
    if ( v26 >= v30 )
      v26 = v30;
    if ( v21 > v25 )
      v25 = v21;
    if ( v25 >= v29 )
      v25 = v29;
    if ( v21 == v25 && v22 == v26 && v23 == v27 )
    {
      if ( v12 )
        UFG::AiDriverComponent::AddSteeringNoise(this, UFG::AiDriverComponent::m_fSteeringNoiseActionHijack);
      if ( v13 || v11 )
        this->m_fAvoidStopTimer = 3.0;
      return 0;
    }
  }
  if ( this->m_bAvoidPeds )
    return 1;
  if ( !((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))my_subject->vfptr[30].__vecDelDtor)(my_subject) )
    return 0;
  if ( ((unsigned __int8 (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[32].__vecDelDtor)(avoidable_subject) )
    return 1;
  else
    return ((__int64 (__fastcall *)(UFG::CameraSubject *))avoidable_subject->vfptr[30].__vecDelDtor)(avoidable_subject);
}

// File Line: 5773
// RVA: 0x64CBB0
UFG::qVector3 *__fastcall UFG::AiDriverComponent::ExtrapolateWithCurvature(
        UFG::AiDriverComponent *this,
        UFG::qVector3 *result,
        float time,
        UFG::CameraSubject *subject,
        UFG::RoadSpaceComponent *road_space,
        UFG::qVector3 *new_velocity)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  float *v9; // rax
  float x; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  float *v13; // rax
  float v14; // xmm8_4
  float v15; // xmm6_4
  double v16; // xmm0_8
  float v17; // xmm6_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 position; // [rsp+20h] [rbp-68h] BYREF
  UFG::qVector3 resulta; // [rsp+30h] [rbp-58h] BYREF

  vfptr = subject->vfptr;
  if ( road_space )
  {
    v16 = ((double (__fastcall *)(UFG::CameraSubject *))vfptr[28].__vecDelDtor)(subject);
    v17 = *(float *)&v16;
    if ( *(float *)&v16 < 0.1 )
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
    y = resulta.y;
    result->x = resulta.x;
    z = resulta.z;
    result->y = y;
    result->z = z;
  }
  else
  {
    v9 = (float *)((__int64 (__fastcall *)(UFG::CameraSubject *))vfptr[20].__vecDelDtor)(subject);
    x = *v9;
    v11 = v9[1];
    v12 = v9[2];
    if ( (float)((float)((float)(v11 * v11) + (float)(x * x)) + (float)(v12 * v12)) < 0.010000001 )
    {
      x = UFG::qVector3::msZero.x;
      v11 = UFG::qVector3::msZero.y;
      v12 = UFG::qVector3::msZero.z;
    }
    if ( new_velocity )
    {
      new_velocity->x = x;
      new_velocity->y = v11;
      new_velocity->z = v12;
    }
    v13 = (float *)((__int64 (__fastcall *)(UFG::CameraSubject *))subject->vfptr[17].__vecDelDtor)(subject);
    v14 = (float)(v12 * time) + v13[2];
    v15 = (float)(x * time) + *v13;
    result->y = (float)(v11 * time) + v13[1];
    result->z = v14;
    result->x = v15;
  }
  return result;
}

// File Line: 5801
// RVA: 0x65B8A0
UFG::qVector3 *__fastcall UFG::AiDriverComponent::SteerToAvoidObjects(
        UFG::AiDriverComponent *this,
        UFG::qVector3 *result,
        UFG::qVector3 *steerToPos,
        float steerToDist)
{
  float x; // xmm7_4
  float y; // xmm9_4
  float z; // xmm8_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_CurrentAvoidable; // r12
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::VehicleSubjectComponent *m_pSimComponent; // r15
  UFG::SimObject *m_pSimObject; // rsi
  UFG::qVector3 *v15; // r13
  float v16; // xmm6_4
  float v17; // xmm10_4
  bool m_bAllowedToPass; // al
  float Mass; // xmm12_4
  double v20; // xmm0_8
  float v21; // xmm11_4
  float v22; // xmm11_4
  float v23; // xmm5_4
  float v24; // xmm13_4
  __int128 x_low; // xmm14
  __m128 v26; // xmm3
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float *v32; // rax
  float v33; // xmm1_4
  float v34; // xmm2_4
  int v35; // xmm15_4
  float v36; // xmm11_4
  float m_RoadSpeedLimit; // xmm2_4
  float *v38; // rdi
  __int64 v39; // rdi
  bool v40; // r12
  UFG::SimObjectGame *v41; // rax
  __int64 v42; // rcx
  __int16 m_Flags; // cx
  UFG::allocator::free_link *m_pComponent; // rbx
  UFG::SimComponent *v45; // rax
  double v46; // xmm0_8
  float v47; // xmm11_4
  float v48; // xmm0_4
  float v49; // xmm6_4
  float distance; // xmm6_4
  UFG::qVector3 *v51; // rsi
  float AvoidanceFutureTime; // xmm0_4
  float *v53; // rbx
  float v54; // xmm0_4
  float *v55; // rbx
  float v56; // xmm0_4
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v57; // rdi
  UFG::CameraSubject *v58; // rbx
  double v59; // xmm0_8
  float v60; // xmm6_4
  float v61; // xmm0_4
  float v62; // xmm2_4
  float v63; // xmm6_4
  UFG::SimObjectGame *v64; // rcx
  UFG::RoadSpaceComponent *v65; // rsi
  __int16 v66; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v68; // xmm14_4
  float v69; // xmm13_4
  float v70; // xmm15_4
  float v71; // xmm12_4
  float fLatest; // xmm10_4
  float v73; // xmm9_4
  float v74; // xmm8_4
  float fEarliest; // xmm11_4
  float v76; // xmm7_4
  float fClosingSpeed; // xmm6_4
  float v78; // xmm0_4
  float v79; // xmm6_4
  float v80; // xmm0_4
  float v81; // xmm2_4
  UFG::qVector3 *v82; // rax
  UFG::qVector3 *v83; // rax
  float *v84; // rcx
  float *v85; // rax
  float v86; // xmm13_4
  float v87; // xmm11_4
  float v88; // xmm9_4
  float v89; // xmm14_4
  float v90; // xmm15_4
  float v91; // xmm7_4
  float v92; // xmm8_4
  float v93; // xmm10_4
  float v94; // xmm12_4
  float v95; // xmm6_4
  float v96; // xmm4_4
  float v97; // xmm5_4
  float v98; // xmm6_4
  float v99; // xmm4_4
  float v100; // xmm5_4
  float v101; // xmm6_4
  float v102; // xmm4_4
  float v103; // xmm5_4
  float v104; // xmm6_4
  float v105; // xmm4_4
  float v106; // xmm5_4
  float v107; // xmm6_4
  float v108; // xmm4_4
  float v109; // xmm5_4
  float v110; // xmm6_4
  float v111; // xmm4_4
  float v112; // xmm5_4
  float v113; // xmm6_4
  float v114; // xmm4_4
  float v115; // xmm5_4
  float v116; // xmm5_4
  float v117; // xmm4_4
  float v118; // xmm6_4
  float v119; // xmm11_4
  float v120; // xmm10_4
  float v121; // xmm9_4
  float v122; // xmm2_4
  float v123; // xmm8_4
  float v124; // xmm7_4
  __m128 mNext_low; // xmm6
  __m128 v126; // xmm3
  float v127; // xmm0_4
  float v128; // xmm9_4
  float v129; // xmm10_4
  float v130; // xmm11_4
  float v131; // xmm12_4
  float v132; // xmm13_4
  float v133; // xmm14_4
  float v134; // xmm3_4
  float v135; // xmm7_4
  float v136; // xmm2_4
  float v137; // xmm8_4
  __m128 y_low; // xmm6
  __m128 v139; // xmm4
  float v140; // xmm0_4
  float v141; // xmm6_4
  float v142; // xmm8_4
  float v143; // xmm7_4
  int v144; // eax
  char v145; // si
  UFG::AiDriverComponent::AvoidableOverlap *v146; // rbx
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v147; // rbx
  float v148; // xmm11_4
  __m128 v149; // xmm12
  __m128 v150; // xmm2
  float v151; // xmm1_4
  float v152; // xmm11_4
  float v153; // xmm12_4
  float v154; // xmm8_4
  __int128 mNext_high; // xmm9
  __m128 v156; // xmm2
  float v157; // xmm4_4
  float v158; // xmm8_4
  bool v159; // cl
  float v160; // xmm14_4
  __m128 mPrev_high; // xmm15
  float v162; // xmm3_4
  float v163; // xmm0_4
  float v164; // xmm6_4
  __m128 v165; // xmm2
  float v166; // xmm10_4
  float v167; // xmm7_4
  float v168; // xmm13_4
  float v169; // xmm6_4
  float v170; // xmm7_4
  float v171; // xmm8_4
  __m128 v172; // xmm1
  float v173; // xmm4_4
  float v174; // xmm1_4
  float v175; // xmm11_4
  float v176; // xmm8_4
  char v177; // si
  char v178; // al
  float *v179; // rax
  float v180; // xmm6_4
  float v181; // xmm4_4
  float v182; // xmm2_4
  bool v183; // al
  float v184; // xmm0_4
  UFG::qVector3 *v185; // rax
  float v186; // xmm8_4
  __m128 v187; // xmm9
  float v188; // xmm7_4
  char v189; // al
  float m_fAvoidSteerLimit; // xmm3_4
  __m128 v191; // xmm2
  float v192; // xmm0_4
  float v193; // xmm3_4
  float *v194; // rax
  __m128 v195; // xmm6
  float v196; // xmm11_4
  float v197; // xmm6_4
  float v198; // xmm12_4
  char v199; // al
  float v200; // xmm0_4
  float v201; // xmm10_4
  float v202; // xmm6_4
  bool v203; // si
  float v204; // xmm2_4
  float v205; // xmm6_4
  float v206; // xmm0_4
  UFG::SimObject *v207; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v208; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v209; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v210; // rax
  char v211; // si
  UFG::SimObjectGame *v212; // rcx
  __int16 v213; // dx
  UFG::SimComponent *v214; // rax
  bool v215; // al
  int v216; // xmm0_4
  float v217; // xmm6_4
  float v218; // xmm0_4
  float v219; // xmm1_4
  float v220; // xmm5_4
  float v221; // xmm4_4
  float v222; // xmm8_4
  float v223; // xmm9_4
  UFG::qVector3 *v224; // rax
  float v225; // xmm1_4
  float v226; // xmm2_4
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *i; // rcx
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v228; // rdx
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v229; // rax
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v230; // rdx
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v231; // rax
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v232; // rcx
  UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *v233; // rax
  float v234; // [rsp+40h] [rbp-80h]
  float v235; // [rsp+44h] [rbp-7Ch]
  UFG::qVector3 close_limit; // [rsp+48h] [rbp-78h] BYREF
  float v237; // [rsp+54h] [rbp-6Ch]
  UFG::AiDriverComponent::TimeWindowResult time_window; // [rsp+58h] [rbp-68h] BYREF
  float v239; // [rsp+64h] [rbp-5Ch]
  float v240; // [rsp+68h] [rbp-58h]
  UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> list; // [rsp+70h] [rbp-50h] BYREF
  UFG::qVector3 right_limit; // [rsp+80h] [rbp-40h] BYREF
  float v243; // [rsp+90h] [rbp-30h]
  float v244; // [rsp+94h] [rbp-2Ch]
  float v245; // [rsp+98h] [rbp-28h]
  float v246; // [rsp+9Ch] [rbp-24h]
  UFG::qVector3 v247; // [rsp+A0h] [rbp-20h] BYREF
  float v248; // [rsp+ACh] [rbp-14h]
  UFG::qVector3 v0; // [rsp+B0h] [rbp-10h] BYREF
  float v250; // [rsp+C0h] [rbp+0h]
  float v251; // [rsp+C4h] [rbp+4h]
  float v252; // [rsp+C8h] [rbp+8h]
  UFG::qVector3 v253; // [rsp+D0h] [rbp+10h] BYREF
  UFG::qVector3 v254; // [rsp+E0h] [rbp+20h] BYREF
  UFG::qVector3 *v1; // [rsp+F0h] [rbp+30h]
  UFG::qVector3 v256; // [rsp+F8h] [rbp+38h] BYREF
  UFG::qVector3 point; // [rsp+108h] [rbp+48h] BYREF
  float v258; // [rsp+118h] [rbp+58h]
  float v259; // [rsp+11Ch] [rbp+5Ch]
  float v260; // [rsp+120h] [rbp+60h]
  float v261; // [rsp+124h] [rbp+64h]
  unsigned int v262; // [rsp+128h] [rbp+68h]
  float v263; // [rsp+12Ch] [rbp+6Ch]
  Render::DebugDrawContext *Context; // [rsp+130h] [rbp+70h]
  UFG::qVector3 world_direction; // [rsp+138h] [rbp+78h] BYREF
  UFG::qVector3 v266; // [rsp+148h] [rbp+88h] BYREF
  UFG::qVector3 local_corners; // [rsp+160h] [rbp+A0h] BYREF
  float v268; // [rsp+16Ch] [rbp+ACh]
  float v269; // [rsp+170h] [rbp+B0h]
  float v270; // [rsp+174h] [rbp+B4h]
  float v271; // [rsp+178h] [rbp+B8h]
  float v272; // [rsp+17Ch] [rbp+BCh]
  float v273; // [rsp+180h] [rbp+C0h]
  float v274; // [rsp+184h] [rbp+C4h]
  float v275; // [rsp+188h] [rbp+C8h]
  float v276; // [rsp+18Ch] [rbp+CCh]
  float v277; // [rsp+190h] [rbp+D0h]
  float v278; // [rsp+194h] [rbp+D4h]
  float v279; // [rsp+198h] [rbp+D8h]
  float v280; // [rsp+19Ch] [rbp+DCh]
  float v281; // [rsp+1A0h] [rbp+E0h]
  float v282; // [rsp+1A4h] [rbp+E4h]
  float v283; // [rsp+1A8h] [rbp+E8h]
  float v284; // [rsp+1ACh] [rbp+ECh]
  float v285; // [rsp+1B0h] [rbp+F0h]
  float v286; // [rsp+1B4h] [rbp+F4h]
  float v287; // [rsp+1B8h] [rbp+F8h]
  float v288; // [rsp+1BCh] [rbp+FCh]
  UFG::qVector3 avoid_hull; // [rsp+1C0h] [rbp+100h] BYREF
  float v290; // [rsp+1CCh] [rbp+10Ch]
  float v291; // [rsp+1D0h] [rbp+110h]
  float v292; // [rsp+1D4h] [rbp+114h]
  float v293; // [rsp+1D8h] [rbp+118h]
  float v294; // [rsp+1DCh] [rbp+11Ch]
  float v295; // [rsp+1E0h] [rbp+120h]
  float v296; // [rsp+1E4h] [rbp+124h]
  float v297; // [rsp+1E8h] [rbp+128h]
  float v298; // [rsp+1ECh] [rbp+12Ch]
  float v299; // [rsp+1F0h] [rbp+130h]
  float v300; // [rsp+1F4h] [rbp+134h]
  float v301; // [rsp+1F8h] [rbp+138h]
  float v302; // [rsp+1FCh] [rbp+13Ch]
  float v303; // [rsp+200h] [rbp+140h]
  float v304; // [rsp+204h] [rbp+144h]
  float v305; // [rsp+208h] [rbp+148h]
  float v306; // [rsp+20Ch] [rbp+14Ch]
  float v307; // [rsp+210h] [rbp+150h]
  float v308; // [rsp+214h] [rbp+154h]
  float v309; // [rsp+218h] [rbp+158h]
  float v310; // [rsp+21Ch] [rbp+15Ch]
  float v311; // [rsp+220h] [rbp+160h]
  float v312; // [rsp+224h] [rbp+164h]
  float v313; // [rsp+228h] [rbp+168h]
  float v314; // [rsp+22Ch] [rbp+16Ch]
  float v315; // [rsp+230h] [rbp+170h]
  float v316; // [rsp+234h] [rbp+174h]
  float v317; // [rsp+238h] [rbp+178h]
  float v318; // [rsp+23Ch] [rbp+17Ch]
  float v319; // [rsp+240h] [rbp+180h]
  float v320; // [rsp+244h] [rbp+184h]
  float v321; // [rsp+248h] [rbp+188h]
  float v322; // [rsp+24Ch] [rbp+18Ch]
  float v323; // [rsp+250h] [rbp+190h]
  float v324; // [rsp+254h] [rbp+194h]
  float v325; // [rsp+258h] [rbp+198h]
  float v326; // [rsp+25Ch] [rbp+19Ch]
  float v327; // [rsp+260h] [rbp+1A0h]
  float v328; // [rsp+264h] [rbp+1A4h]
  float v329; // [rsp+268h] [rbp+1A8h]
  float v330; // [rsp+26Ch] [rbp+1ACh]
  float v331; // [rsp+270h] [rbp+1B0h]
  float v332; // [rsp+274h] [rbp+1B4h]
  float v333; // [rsp+278h] [rbp+1B8h]
  float v334; // [rsp+27Ch] [rbp+1BCh]
  UFG::SensorPhantomIterator v335; // [rsp+280h] [rbp+1C0h] BYREF
  UFG::qVector3 new_velocity; // [rsp+298h] [rbp+1D8h] BYREF
  UFG::qVector3 v337; // [rsp+2A8h] [rbp+1E8h] BYREF
  UFG::qVector3 v338; // [rsp+2B8h] [rbp+1F8h] BYREF
  UFG::qVector3 v339; // [rsp+2C8h] [rbp+208h] BYREF
  UFG::qVector3 p1; // [rsp+2D8h] [rbp+218h] BYREF
  UFG::qVector3 v341; // [rsp+2E8h] [rbp+228h] BYREF
  UFG::qVector3 v342; // [rsp+2F8h] [rbp+238h] BYREF
  UFG::qVector3 p0; // [rsp+308h] [rbp+248h] BYREF
  UFG::qVector3 v344; // [rsp+318h] [rbp+258h] BYREF
  __int64 v345; // [rsp+328h] [rbp+268h]
  UFG::qVector3 v346; // [rsp+330h] [rbp+270h] BYREF
  UFG::qVector3 verts; // [rsp+340h] [rbp+280h] BYREF
  __int64 v348[129]; // [rsp+3A0h] [rbp+2E0h]
  bool co_chaser[8]; // [rsp+7B0h] [rbp+6F0h] BYREF
  float *v350; // [rsp+7B8h] [rbp+6F8h]
  float *v351; // [rsp+7C0h] [rbp+700h]
  float radius; // [rsp+7C8h] [rbp+708h]
  float *v353; // [rsp+7D0h] [rbp+710h]
  float *v354; // [rsp+7D8h] [rbp+718h]

  v345 = -2i64;
  x = steerToPos->x;
  v244 = x;
  y = steerToPos->y;
  v248 = y;
  z = steerToPos->z;
  v243 = z;
  point.x = x;
  point.y = y;
  point.z = z;
  p_m_CurrentAvoidable = &this->m_CurrentAvoidable;
  if ( this->m_CurrentAvoidable.m_pPointer )
  {
    mPrev = p_m_CurrentAvoidable->mPrev;
    mNext = p_m_CurrentAvoidable->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_CurrentAvoidable->mPrev = p_m_CurrentAvoidable;
    p_m_CurrentAvoidable->mNext = p_m_CurrentAvoidable;
  }
  p_m_CurrentAvoidable->m_pPointer = 0i64;
  this->m_BlockedByAvoidable = 0;
  m_pSimComponent = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  if ( m_pSimComponent )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    m_pSimObject = this->m_pSimObject;
    *(_QWORD *)&time_window.fClosingSpeed = m_pSimObject;
    v15 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[17].__vecDelDtor)(m_pSimComponent);
    v16 = FLOAT_0_2;
    v17 = FLOAT_0_2;
    v234 = FLOAT_0_2;
    m_bAllowedToPass = this->m_bAllowedToPass;
    if ( m_bAllowedToPass )
    {
      v17 = FLOAT_0_40000001;
      v234 = FLOAT_0_40000001;
    }
    if ( this->m_bTemporaryAllowedToPass )
    {
      v17 = FLOAT_0_2;
      v234 = FLOAT_0_2;
    }
    if ( m_bAllowedToPass )
      v16 = FLOAT_0_1;
    Mass = UFG::VehicleSubjectComponent::GetMass(m_pSimComponent);
    v20 = ((double (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[28].__vecDelDtor)(m_pSimComponent);
    v258 = *(float *)&v20;
    v21 = UFG::AiDriverComponent::m_fMaxBrakingForce;
    if ( this->m_pVehicleSubject.m_pSimComponent
      && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent) )
    {
      v21 = UFG::AiDriverComponent::m_fBoatMaxBrakingForce;
    }
    if ( Mass < 100.0 )
      Mass = FLOAT_100_0;
    v22 = v21 / Mass;
    v23 = steerToPos->z - v15->z;
    v246 = v23;
    v24 = steerToPos->y - v15->y;
    v240 = v24;
    x_low = LODWORD(steerToPos->x);
    *(float *)&x_low = *(float *)&x_low - v15->x;
    v245 = *(float *)&x_low;
    v26 = (__m128)x_low;
    v26.m128_f32[0] = (float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)(v24 * v24)) + (float)(v23 * v23);
    COERCE_FLOAT(v262 = _mm_sqrt_ps(v26).m128_u32[0]);
    v27 = 0.0;
    if ( *(float *)&v262 <= 0.0 )
    {
      LODWORD(time_window.fClosingSpeed) = x_low;
      time_window.fEarliest = v24;
      time_window.fLatest = v23;
    }
    else
    {
      if ( v26.m128_f32[0] != 0.0 )
        v27 = 1.0 / _mm_sqrt_ps(v26).m128_f32[0];
      time_window.fClosingSpeed = v27 * *(float *)&x_low;
      time_window.fEarliest = v27 * v24;
      time_window.fLatest = v27 * v23;
    }
    v28 = FLOAT_2_0;
    if ( this->m_bAllowedToPass )
      v28 = *(float *)&FLOAT_1_0;
    v29 = *(float *)&v20 - (float)(v28 * v22);
    v30 = (float)(v28 * UFG::AiDriverComponent::m_fMaxForwardAccel) + *(float *)&v20;
    v31 = *v354;
    if ( *v354 <= v29 )
      v31 = v29;
    if ( v31 >= v30 )
      v31 = v30;
    v32 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[20].__vecDelDtor)(m_pSimComponent);
    v33 = (float)(1.0 - v16) * v32[1];
    v34 = (float)(1.0 - v16) * *v32;
    *(float *)&v35 = (float)((float)(time_window.fLatest * v31) * v16) + (float)((float)(1.0 - v16) * v32[2]);
    v250 = *(float *)&v35;
    v251 = (float)((float)(time_window.fEarliest * v31) * v16) + v33;
    v36 = (float)((float)(time_window.fClosingSpeed * v31) * v16) + v34;
    v252 = v36;
    time_window.fLatest = v36;
    v239 = v251;
    v240 = *(float *)&v35;
    v0.x = v36;
    v0.y = v251;
    LODWORD(v0.z) = v35;
    if ( this->m_bAllowedToPass || (m_RoadSpeedLimit = this->m_RoadSpeedLimit, m_RoadSpeedLimit <= 0.0) )
    {
      co_chaser[0] = 0;
    }
    else
    {
      co_chaser[0] = 1;
      v0.x = m_RoadSpeedLimit * time_window.fClosingSpeed;
      v0.y = m_RoadSpeedLimit * time_window.fEarliest;
      v0.z = m_RoadSpeedLimit * time_window.fLatest;
    }
    v259 = (float)((float)((float)((float)((float)(time_window.fEarliest * v31) * v16) + v33)
                         * (float)((float)((float)(time_window.fEarliest * v31) * v16) + v33))
                 + (float)(v36 * v36))
         + (float)(*(float *)&v35 * *(float *)&v35);
    if ( v259 > 0.0 )
    {
      this->m_NumAvoidableOverlaps = 0;
      list.mNode.mPrev = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list;
      list.mNode.mNext = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list;
      UFG::SensorPhantomIterator::SensorPhantomIterator(&v335, this->m_AvoidableSensor, 0);
      v39 = 0i64;
      if ( UFG::SensorPhantomIterator::operator*(&v335) )
      {
        v40 = co_chaser[0];
        do
        {
          v41 = (UFG::SimObjectGame *)UFG::SensorPhantomIterator::operator*(&v335);
          if ( v41 != m_pSimObject )
          {
            v42 = 0i64;
            if ( v39 )
            {
              while ( (UFG::SimObjectGame *)v348[v42] != v41 )
              {
                if ( ++v42 == v39 )
                  goto LABEL_39;
              }
            }
            else
            {
LABEL_39:
              if ( v39 != 100 )
                v348[v39++] = (__int64)v41;
              co_chaser[0] = 0;
              if ( v41 )
              {
                m_Flags = v41->m_Flags;
                if ( (m_Flags & 0x4000) != 0 )
                {
                  m_pComponent = (UFG::allocator::free_link *)v41->m_Components.p[37].m_pComponent;
                }
                else if ( m_Flags >= 0 )
                {
                  v45 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                      ? UFG::SimObjectGame::GetComponentOfTypeHK(v41, UFG::CameraSubject::_TypeUID)
                      : UFG::SimObject::GetComponentOfType(v41, UFG::CameraSubject::_TypeUID);
                  m_pComponent = (UFG::allocator::free_link *)v45;
                }
                else
                {
                  m_pComponent = (UFG::allocator::free_link *)v41->m_Components.p[31].m_pComponent;
                }
                if ( m_pComponent
                  && UFG::AiDriverComponent::ShouldAvoid(
                       this,
                       m_pSimComponent,
                       (UFG::CameraSubject *)m_pComponent,
                       co_chaser) )
                {
                  v46 = ((double (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[21].__vecDelDtor)(m_pSimComponent);
                  v47 = *(float *)&v46;
                  v48 = ((float (__fastcall *)(UFG::allocator::free_link *))m_pComponent->mNext[21].mNext)(m_pComponent);
                  v49 = v17;
                  if ( this->m_DrivingMode == 2 )
                  {
                    if ( this->m_PathingTarget.m_pPointer )
                    {
                      if ( (float)(v47 + 0.2) > v48 )
                      {
                        v49 = v48 * 0.5;
                        if ( v17 > (float)(v48 * 0.5) )
                          v49 = v17;
                      }
                    }
                  }
                  distance = (float)(v49 + v47) + v48;
                  v51 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::allocator::free_link *))m_pComponent->mNext[17].mNext)(m_pComponent);
                  v1 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::allocator::free_link *))m_pComponent->mNext[20].mNext)(m_pComponent);
                  if ( UFG::AiDriverComponent::TimeWindowCloserThan(this, v15, &v0, v51, v1, distance, &time_window) )
                  {
                    AvoidanceFutureTime = UFG::AiDriverComponent::GetAvoidanceFutureTime(this);
                    if ( AvoidanceFutureTime > time_window.fEarliest )
                    {
                      if ( v40 )
                        UFG::AiDriverComponent::TimeWindowCloserThan(
                          this,
                          v15,
                          (UFG::qVector3 *)&time_window.fLatest,
                          v51,
                          v1,
                          distance,
                          &time_window);
                      UFG::AiDriverComponent::AddAvoidableOverlap(this, &list, m_pComponent, &time_window, co_chaser[0]);
                      ++this->m_NumAvoidableOverlaps;
                    }
                  }
                  m_pSimObject = *(UFG::SimObject **)&time_window.fClosingSpeed;
                }
              }
            }
          }
          UFG::SensorPhantomIterator::operator++(&v335);
        }
        while ( UFG::SensorPhantomIterator::operator*(&v335) );
        p_m_CurrentAvoidable = &this->m_CurrentAvoidable;
      }
      UFG::SensorPhantomIterator::~SensorPhantomIterator(&v335);
      UFG::CameraSubject::GetBoxVerts(m_pSimComponent, &verts, 0.0);
      if ( (UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> *)list.mNode.mNext == &list )
      {
        this->m_bTemporaryAllowedToPass = 0;
        this->m_TempPassLaneChangeDirectionCode = 0;
      }
      v53 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[15].__vecDelDtor)(m_pSimComponent);
      v54 = *(float *)(((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[24].__vecDelDtor)(m_pSimComponent)
                     + 4);
      v0.x = v54 * v53[2];
      *(float *)&v1 = v54 * v53[1];
      time_window.fClosingSpeed = v54 * *v53;
      v55 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[15].__vecDelDtor)(m_pSimComponent);
      v56 = *(float *)(((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[23].__vecDelDtor)(m_pSimComponent)
                     + 4);
      v261 = v56 * v55[2];
      v260 = v56 * v55[1];
      v263 = v56 * *v55;
      v57 = list.mNode.mNext;
      if ( (UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> *)list.mNode.mNext != &list )
      {
        do
        {
          v58 = (UFG::CameraSubject *)v57[2].mNext;
          *(_QWORD *)co_chaser = ((__int64 (__fastcall *)(UFG::CameraSubject *))v58->vfptr[17].__vecDelDtor)(v58);
          ((void (__fastcall *)(UFG::CameraSubject *))v58->vfptr[20].__vecDelDtor)(v58);
          v59 = ((double (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[21].__vecDelDtor)(m_pSimComponent);
          v60 = *(float *)&v59;
          v61 = ((float (__fastcall *)(UFG::CameraSubject *))v58->vfptr[21].__vecDelDtor)(v58);
          v62 = v17;
          v63 = v60 + 0.2;
          if ( this->m_DrivingMode == 2 )
          {
            if ( this->m_PathingTarget.m_pPointer )
            {
              if ( v63 > v61 )
              {
                v62 = v61 * 0.5;
                if ( v17 > (float)(v61 * 0.5) )
                  v62 = v17;
              }
            }
          }
          UFG::CameraSubject::GetBoxVerts(v58, &local_corners, v62);
          v64 = (UFG::SimObjectGame *)v58->m_pSimObject;
          if ( v64 )
          {
            v66 = v64->m_Flags;
            if ( (v66 & 0x4000) != 0 )
            {
              v65 = (UFG::RoadSpaceComponent *)v64->m_Components.p[24].m_pComponent;
            }
            else if ( v66 >= 0 )
            {
              if ( (v66 & 0x2000) != 0 || (v66 & 0x1000) != 0 )
                ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v64, UFG::RoadSpaceComponent::_TypeUID);
              else
                ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v64, UFG::RoadSpaceComponent::_TypeUID);
              v65 = (UFG::RoadSpaceComponent *)ComponentOfTypeHK;
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
            this,
            (UFG::qVector3 *)&time_window.fLatest,
            *(float *)&v57[2].mPrev,
            m_pSimComponent,
            (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent,
            &new_velocity);
          UFG::AiDriverComponent::ExtrapolateWithCurvature(
            this,
            (UFG::qVector3 *)&time_window,
            *((float *)&v57[1].mNext + 1),
            m_pSimComponent,
            (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pSimComponent,
            &v342);
          UFG::AiDriverComponent::ExtrapolateWithCurvature(this, &v266, *(float *)&v57[2].mPrev, v58, v65, &v338);
          UFG::AiDriverComponent::ExtrapolateWithCurvature(this, &v256, *((float *)&v57[1].mNext + 1), v58, v65, &v344);
          v68 = v266.z;
          v69 = v266.y;
          v70 = v239;
          v71 = v266.x;
          fLatest = time_window.fLatest;
          world_direction.x = v266.x - time_window.fLatest;
          world_direction.y = v266.y - v239;
          world_direction.z = v266.z - v240;
          UFG::CameraSubject::GetExtentInDirection(m_pSimComponent, &p0, &world_direction, &verts);
          v73 = v256.z;
          v74 = v256.y;
          fEarliest = time_window.fEarliest;
          v76 = v256.x;
          fClosingSpeed = time_window.fClosingSpeed;
          v254.x = v256.x - time_window.fClosingSpeed;
          v254.y = v256.y - time_window.fEarliest;
          v254.z = v256.z - time_window.fLatest;
          UFG::CameraSubject::GetExtentInDirection(m_pSimComponent, &v341, &v254, &verts);
          v253.x = fLatest - v71;
          v253.y = v70 - v69;
          v253.z = v240 - v68;
          UFG::CameraSubject::GetExtentInDirection(v58, &p1, &v253, &local_corners);
          v247.x = fClosingSpeed - v76;
          v247.y = fEarliest - v74;
          v247.z = time_window.fLatest - v73;
          UFG::CameraSubject::GetExtentInDirection(v58, &v339, &v247, &local_corners);
          v78 = UFG::ClosingTime(&p0, &new_velocity, &p1, &v338, 0i64);
          v79 = 0.0;
          if ( v78 >= 0.0 )
            v79 = v78;
          v80 = UFG::ClosingTime(&v341, &v342, &v339, &v344, 0i64);
          v81 = 0.0;
          if ( v80 >= 0.0 )
            v81 = v80;
          v82 = UFG::AiDriverComponent::ExtrapolateWithCurvature(this, &v346, v81, v58, v65, 0i64);
          v235 = v82->z - *(float *)(*(_QWORD *)co_chaser + 8i64);
          close_limit.x = v82->y - *(float *)(*(_QWORD *)co_chaser + 4i64);
          close_limit.z = v82->x - **(float **)co_chaser;
          v83 = UFG::AiDriverComponent::ExtrapolateWithCurvature(this, &v337, v79, v58, v65, 0i64);
          v84 = *(float **)co_chaser;
          *(float *)co_chaser = v83->z - *(float *)(*(_QWORD *)co_chaser + 8i64);
          v237 = v83->y - v84[1];
          close_limit.y = v83->x - *v84;
          v85 = (float *)((__int64 (__fastcall *)(UFG::CameraSubject *))v58->vfptr[18].__vecDelDtor)(v58);
          v86 = *v85;
          v87 = v85[5];
          v88 = v85[1];
          v89 = v85[9];
          v90 = v85[13];
          v91 = v85[6];
          v92 = v85[2];
          v93 = v85[10];
          v94 = v85[14];
          v95 = (float)((float)((float)((float)(local_corners.x * *v85) + (float)(local_corners.y * v85[4]))
                              + (float)(local_corners.z * v85[8]))
                      + v85[12])
              - v15->x;
          v96 = (float)((float)((float)((float)(local_corners.x * v88) + (float)(local_corners.y * v87))
                              + (float)(local_corners.z * v89))
                      + v90)
              - v15->y;
          v97 = (float)((float)((float)((float)(local_corners.x * v92) + (float)(local_corners.y * v91))
                              + (float)(local_corners.z * v93))
                      + v94)
              - v15->z;
          v311 = v95 + close_limit.y;
          v312 = v237 + v96;
          v313 = *(float *)co_chaser + v97;
          avoid_hull.x = v95 + close_limit.z;
          avoid_hull.y = close_limit.x + v96;
          avoid_hull.z = v235 + v97;
          v98 = (float)((float)((float)((float)(v268 * v86) + (float)(v269 * v85[4])) + (float)(v270 * v85[8])) + v85[12])
              - v15->x;
          v99 = (float)((float)((float)((float)(v268 * v88) + (float)(v269 * v87)) + (float)(v270 * v89)) + v90)
              - v15->y;
          v100 = (float)((float)((float)((float)(v268 * v92) + (float)(v269 * v91)) + (float)(v270 * v93)) + v94)
               - v15->z;
          v314 = v98 + close_limit.y;
          v315 = v237 + v99;
          v316 = *(float *)co_chaser + v100;
          v290 = v98 + close_limit.z;
          v291 = close_limit.x + v99;
          v292 = v235 + v100;
          v101 = (float)((float)((float)((float)(v271 * v86) + (float)(v272 * v85[4])) + (float)(v273 * v85[8]))
                       + v85[12])
               - v15->x;
          v102 = (float)((float)((float)((float)(v271 * v88) + (float)(v272 * v87)) + (float)(v273 * v89)) + v90)
               - v15->y;
          v103 = (float)((float)((float)((float)(v271 * v92) + (float)(v272 * v91)) + (float)(v273 * v93)) + v94)
               - v15->z;
          v317 = v101 + close_limit.y;
          v318 = v237 + v102;
          v319 = *(float *)co_chaser + v103;
          v293 = v101 + close_limit.z;
          v294 = close_limit.x + v102;
          v295 = v235 + v103;
          v104 = (float)((float)((float)((float)(v275 * v85[4]) + (float)(v274 * v86)) + (float)(v276 * v85[8]))
                       + v85[12])
               - v15->x;
          v105 = (float)((float)((float)((float)(v275 * v87) + (float)(v274 * v88)) + (float)(v276 * v89)) + v90)
               - v15->y;
          v106 = (float)((float)((float)((float)(v275 * v91) + (float)(v274 * v92)) + (float)(v276 * v93)) + v94)
               - v15->z;
          v320 = v104 + close_limit.y;
          v321 = v237 + v105;
          v322 = *(float *)co_chaser + v106;
          v296 = v104 + close_limit.z;
          v297 = close_limit.x + v105;
          v298 = v235 + v106;
          v107 = (float)((float)((float)((float)(v277 * v86) + (float)(v278 * v85[4])) + (float)(v279 * v85[8]))
                       + v85[12])
               - v15->x;
          v108 = (float)((float)((float)((float)(v277 * v88) + (float)(v278 * v87)) + (float)(v279 * v89)) + v90)
               - v15->y;
          v109 = (float)((float)((float)((float)(v277 * v92) + (float)(v278 * v91)) + (float)(v279 * v93)) + v94)
               - v15->z;
          v323 = v107 + close_limit.y;
          v324 = v237 + v108;
          v325 = *(float *)co_chaser + v109;
          v299 = v107 + close_limit.z;
          v300 = close_limit.x + v108;
          v301 = v235 + v109;
          v110 = (float)((float)((float)((float)(v280 * v86) + (float)(v281 * v85[4])) + (float)(v282 * v85[8]))
                       + v85[12])
               - v15->x;
          v111 = (float)((float)((float)((float)(v280 * v88) + (float)(v281 * v87)) + (float)(v282 * v89)) + v90)
               - v15->y;
          v112 = (float)((float)((float)((float)(v280 * v92) + (float)(v281 * v91)) + (float)(v282 * v93)) + v94)
               - v15->z;
          v326 = v110 + close_limit.y;
          v327 = v237 + v111;
          v328 = *(float *)co_chaser + v112;
          v302 = v110 + close_limit.z;
          v303 = close_limit.x + v111;
          v304 = v235 + v112;
          v113 = (float)((float)((float)((float)(v283 * v86) + (float)(v284 * v85[4])) + (float)(v285 * v85[8]))
                       + v85[12])
               - v15->x;
          v114 = (float)((float)((float)((float)(v283 * v88) + (float)(v284 * v87)) + (float)(v285 * v89)) + v90)
               - v15->y;
          v115 = (float)((float)((float)((float)(v283 * v92) + (float)(v284 * v91)) + (float)(v285 * v93)) + v94)
               - v15->z;
          v329 = v113 + close_limit.y;
          v330 = v237 + v114;
          v331 = *(float *)co_chaser + v115;
          v305 = v113 + close_limit.z;
          v306 = close_limit.x + v114;
          v307 = v235 + v115;
          v116 = (float)((float)((float)((float)(v287 * v91) + (float)(v286 * v92)) + (float)(v288 * v93)) + v94)
               - v15->z;
          v117 = (float)((float)((float)((float)(v286 * v88) + (float)(v287 * v87)) + (float)(v288 * v89)) + v90)
               - v15->y;
          v118 = (float)((float)((float)((float)(v286 * v86) + (float)(v287 * v85[4])) + (float)(v288 * v85[8]))
                       + v85[12])
               - v15->x;
          v332 = v118 + close_limit.y;
          v333 = v237 + v117;
          v334 = *(float *)co_chaser + v116;
          v308 = v118 + close_limit.z;
          v309 = close_limit.x + v117;
          v310 = v235 + v116;
          UFG::AiDriverComponent::ComputeAvoidanceLimits(
            this,
            v15,
            &avoid_hull,
            (UFG::qVector3 *)&list,
            &right_limit,
            &close_limit);
          v119 = *(float *)&list.mNode.mNext;
          mNext_low = (__m128)LODWORD(list.mNode.mNext);
          v120 = *((float *)&list.mNode.mPrev + 1);
          v121 = *(float *)&list.mNode.mPrev;
          v122 = 0.0;
          v123 = (float)((float)(*((float *)&list.mNode.mPrev + 1) - v260) * 0.0)
               - (float)((float)(*(float *)&list.mNode.mPrev - v263) * 0.0);
          mNext_low.m128_f32[0] = (float)(*(float *)&list.mNode.mNext - v261) * 0.0;
          v124 = (float)(*(float *)&list.mNode.mPrev - v263) - mNext_low.m128_f32[0];
          mNext_low.m128_f32[0] = mNext_low.m128_f32[0] - (float)(*((float *)&list.mNode.mPrev + 1) - v260);
          v126 = mNext_low;
          v126.m128_f32[0] = (float)((float)(mNext_low.m128_f32[0] * mNext_low.m128_f32[0]) + (float)(v124 * v124))
                           + (float)(v123 * v123);
          if ( v126.m128_f32[0] != 0.0 )
            v122 = 1.0 / _mm_sqrt_ps(v126).m128_f32[0];
          v127 = *(float *)(((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[23].__vecDelDtor)(m_pSimComponent)
                          + 4);
          v128 = v121 - (float)((float)(mNext_low.m128_f32[0] * v122) * v127);
          v129 = v120 - (float)((float)(v124 * v122) * v127);
          v130 = v119 - (float)((float)(v123 * v122) * v127);
          list.mNode.mPrev = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)__PAIR64__(LODWORD(v129), LODWORD(v128));
          *(float *)&list.mNode.mNext = v130;
          v131 = right_limit.z;
          v132 = right_limit.y;
          y_low = (__m128)LODWORD(right_limit.y);
          v133 = right_limit.x;
          v134 = 0.0;
          v135 = (float)((float)(right_limit.x - time_window.fClosingSpeed) * 0.0)
               - (float)((float)(right_limit.y - *(float *)&v1) * 0.0);
          v136 = (float)(right_limit.z - v0.x) * 0.0;
          v137 = v136 - (float)(right_limit.x - time_window.fClosingSpeed);
          y_low.m128_f32[0] = (float)(right_limit.y - *(float *)&v1) - v136;
          v139 = y_low;
          v139.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v137 * v137))
                           + (float)(v135 * v135);
          if ( v139.m128_f32[0] != 0.0 )
            v134 = 1.0 / _mm_sqrt_ps(v139).m128_f32[0];
          v140 = *(float *)(((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[24].__vecDelDtor)(m_pSimComponent)
                          + 4);
          v141 = (float)((float)(y_low.m128_f32[0] * v134) * v140) + v133;
          v142 = (float)((float)(v137 * v134) * v140) + v132;
          v143 = (float)((float)(v135 * v134) * v140) + v131;
          right_limit.x = v141;
          right_limit.y = v142;
          right_limit.z = v143;
          *(UFG::qVector3 *)&v57[3].mPrev = close_limit;
          *((float *)&v57[3].mNext + 1) = v141;
          *(float *)&v57[4].mPrev = v142;
          *((float *)&v57[4].mPrev + 1) = v143;
          *(float *)&v57[4].mNext = v128;
          *((float *)&v57[4].mNext + 1) = v129;
          *(float *)&v57[5].mPrev = v130;
          v57 = v57->mNext;
          v17 = v234;
        }
        while ( v57 != (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list );
        v57 = list.mNode.mNext;
        x = v244;
        z = v243;
        y = v248;
        v24 = v240;
        *(float *)&x_low = v245;
        p_m_CurrentAvoidable = &this->m_CurrentAvoidable;
      }
      v144 = 0;
      *(_DWORD *)co_chaser = 0;
      do
      {
        if ( v144 >= this->m_NumAvoidableOverlaps )
          break;
        v145 = 0;
        if ( v57 != (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list )
        {
          do
          {
            if ( SHIDWORD(v57[1].mPrev) <= v144 )
            {
              v146 = (UFG::AiDriverComponent::AvoidableOverlap *)v57->mNext;
              if ( v146 != (UFG::AiDriverComponent::AvoidableOverlap *)&list )
              {
                do
                {
                  v145 |= UFG::AiDriverComponent::AvoidableOverlap::MergeLimits(
                            (UFG::AiDriverComponent::AvoidableOverlap *)v57,
                            v146);
                  v146 = (UFG::AiDriverComponent::AvoidableOverlap *)v146->mNext;
                }
                while ( v146 != (UFG::AiDriverComponent::AvoidableOverlap *)&list );
                v144 = *(_DWORD *)co_chaser;
              }
            }
            v57 = v57->mNext;
          }
          while ( v57 != (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list );
          v57 = list.mNode.mNext;
        }
        *(_DWORD *)co_chaser = ++v144;
      }
      while ( v145 );
      if ( v57 != (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list )
      {
        v253.z = 0.0;
        v254.z = 0.0;
        do
        {
          v147 = v57[2].mNext;
          *(_QWORD *)&v0.x = ((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v147->mPrev[8].mNext)(v147);
          ((void (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v147->mPrev[10].mPrev)(v147);
          v148 = *((float *)&v57[4].mNext + 1);
          v149 = (__m128)LODWORD(v57[4].mNext);
          v150 = v149;
          v150.m128_f32[0] = (float)((float)(v149.m128_f32[0] * v149.m128_f32[0]) + (float)(v148 * v148))
                           + (float)(*(float *)&v57[5].mPrev * *(float *)&v57[5].mPrev);
          if ( v150.m128_f32[0] == 0.0 )
            v151 = 0.0;
          else
            v151 = 1.0 / _mm_sqrt_ps(v150).m128_f32[0];
          v152 = v148 * v151;
          v153 = v149.m128_f32[0] * v151;
          v253.x = v153;
          v253.y = v152;
          v154 = *(float *)&v57[4].mPrev;
          mNext_high = HIDWORD(v57[3].mNext);
          v156 = (__m128)mNext_high;
          v156.m128_f32[0] = (float)((float)(*(float *)&mNext_high * *(float *)&mNext_high) + (float)(v154 * v154))
                           + (float)(*((float *)&v57[4].mPrev + 1) * *((float *)&v57[4].mPrev + 1));
          if ( v156.m128_f32[0] == 0.0 )
            v157 = 0.0;
          else
            v157 = 1.0 / _mm_sqrt_ps(v156).m128_f32[0];
          v158 = v154 * v157;
          *(float *)&mNext_high = *(float *)&mNext_high * v157;
          LODWORD(v254.x) = mNext_high;
          v254.y = v158;
          v159 = (float)((float)(v152 * *(float *)&x_low) - (float)(v24 * v153)) > 0.0
              && (float)((float)(v158 * *(float *)&x_low) - (float)(v24 * *(float *)&mNext_high)) < 0.0;
          co_chaser[0] = v159;
          v160 = *(float *)&v57[3].mPrev;
          mPrev_high = (__m128)HIDWORD(v57[3].mPrev);
          v162 = *(float *)&v57[3].mNext;
          v234 = v162;
          v163 = v15->z + v162;
          v164 = v15->y + mPrev_high.m128_f32[0];
          time_window.fClosingSpeed = v15->x;
          v256.x = time_window.fClosingSpeed + v160;
          v256.y = v164;
          v256.z = v163;
          LODWORD(v1) = v159;
          if ( v159 )
          {
            v165 = mPrev_high;
            v165.m128_f32[0] = (float)((float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]) + (float)(v160 * v160))
                             + (float)(v162 * v162);
            time_window.fClosingSpeed = _mm_sqrt_ps(v165).m128_f32[0];
            v166 = 1.0
                 - (float)((float)((float)(time_window.fClosingSpeed
                                         - *(float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[24].__vecDelDtor)(m_pSimComponent))
                                 - 5.0)
                         * 0.1);
            if ( v166 <= 0.5 )
            {
              v166 = FLOAT_0_5;
            }
            else if ( v166 >= 1.0 )
            {
              v166 = *(float *)&FLOAT_1_0;
            }
            *(float *)co_chaser = 1.0 - v166;
            if ( v259 == 0.0 )
              v167 = 0.0;
            else
              v167 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(v259)).m128_f32[0];
            v168 = v167 * v250;
            v169 = v167 * v251;
            v170 = v167 * v252;
            v171 = v158 + v152;
            *(float *)&mNext_high = *(float *)&mNext_high + v153;
            v172 = (__m128)mNext_high;
            v172.m128_f32[0] = (float)(*(float *)&mNext_high * *(float *)&mNext_high) + (float)(v171 * v171);
            if ( v172.m128_f32[0] == 0.0 )
              v173 = 0.0;
            else
              v173 = 1.0 / _mm_sqrt_ps(v172).m128_f32[0];
            v174 = v173 * v171;
            v175 = v245;
            v176 = *(float *)co_chaser;
            v177 = (float)((float)((float)((float)((float)(v170 * v174)
                                                 - (float)(v169 * (float)(v173 * *(float *)&mNext_high)))
                                         * v166)
                                 + (float)((float)((float)(v174 * v245)
                                                 - (float)(v240 * (float)(v173 * *(float *)&mNext_high)))
                                         * *(float *)co_chaser))
                         + this->m_fPassingBias) < 0.0;
            if ( this->m_bStayOffSidewalk
              && ((LOBYTE(v234) = ((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v147->mPrev[16].mNext)(v147),
                   co_chaser[0] = ((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v147->mPrev[21].mNext)(v147),
                   v178 = ((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v147->mPrev[22].mPrev)(v147),
                   LOBYTE(v234))
               || co_chaser[0] != v178) )
            {
              v179 = (float *)((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v147->mPrev[8].mPrev)(v147);
              v180 = (float)((float)((float)(v169 * v179[1]) + (float)(v170 * *v179)) + (float)(v168 * v179[2])) * v166;
              v24 = v240;
              v181 = v246;
              v182 = (float)((float)((float)((float)(v240 * v179[1]) + (float)(v175 * *v179)) + (float)(v246 * v179[2]))
                           * v176)
                   + v180;
              v183 = co_chaser[0];
              if ( LOBYTE(v234) )
                v183 = 0;
              v177 = v183 ^ (v182 < 0.0);
            }
            else
            {
              v181 = v246;
              v24 = v240;
            }
            v184 = UFG::AiDriverComponent::m_fAvoidancePassingBias;
            if ( v177 )
              LODWORD(v184) = LODWORD(UFG::AiDriverComponent::m_fAvoidancePassingBias) ^ _xmm[0];
            this->m_fPassingBias = v184;
            this->m_fPassingTimer = 0.25;
            v185 = &v253;
            if ( !v177 )
              v185 = &v254;
            v187 = (__m128)v262;
            v186 = (float)(*(float *)&v262 * v185->z) - v181;
            v187.m128_f32[0] = (float)(*(float *)&v262 * v185->y) - v24;
            v188 = (float)(*(float *)&v262 * v185->x) - v175;
            if ( !((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[38].__vecDelDtor)(m_pSimComponent)
              || !((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v147->mPrev[23].mPrev)(v147)
              || (v189 = ((__int64 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v147->mPrev[18].mNext)(v147),
                  co_chaser[0] = 1,
                  !v189) )
            {
              co_chaser[0] = 0;
            }
            m_fAvoidSteerLimit = this->m_fAvoidSteerLimit;
            if ( m_fAvoidSteerLimit <= -1.0
              || (v191 = v187,
                  v191.m128_f32[0] = (float)((float)(v187.m128_f32[0] * v187.m128_f32[0]) + (float)(v188 * v188))
                                   + (float)(v186 * v186),
                  v192 = _mm_sqrt_ps(v191).m128_f32[0],
                  v192 <= m_fAvoidSteerLimit) )
            {
              if ( !LOBYTE(v57[1].mPrev) )
              {
                v216 = LODWORD(v57[1].mNext) ^ _xmm[0];
                if ( *(float *)&v216 > 0.0099999998 )
                {
                  v217 = time_window.fClosingSpeed / *(float *)&v216;
                  v218 = ((float (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[28].__vecDelDtor)(m_pSimComponent)
                       * v217;
                  v219 = *v353;
                  if ( *v353 >= v218 )
                    v219 = v218;
                  *v353 = v219;
                }
              }
            }
            else
            {
              if ( v192 < 0.001 )
                v192 = FLOAT_0_001;
              v193 = m_fAvoidSteerLimit / v192;
              v188 = v188 * v193;
              v187.m128_f32[0] = v187.m128_f32[0] * v193;
              v186 = v186 * v193;
              if ( (float)((float)((float)(mPrev_high.m128_f32[0] * v251) + (float)(v160 * v252)) + (float)(v234 * v250)) > 0.0 )
              {
                v194 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[16].__vecDelDtor)(m_pSimComponent);
                v195 = (__m128)*(unsigned int *)v194;
                v195.m128_f32[0] = (float)((float)(v195.m128_f32[0] * v160) + (float)(v194[1] * mPrev_high.m128_f32[0]))
                                 + (float)(v194[2] * v234);
                v196 = v258 + *(float *)&v57[1].mNext;
                v195.m128_f32[0] = (float)((float)((float)(v195.m128_f32[0] * *v194) * (float)(v195.m128_f32[0] * *v194))
                                         + (float)((float)(v195.m128_f32[0] * v194[1])
                                                 * (float)(v195.m128_f32[0] * v194[1])))
                                 + (float)((float)(v195.m128_f32[0] * v194[2]) * (float)(v195.m128_f32[0] * v194[2]));
                LODWORD(v197) = _mm_sqrt_ps(v195).m128_u32[0];
                v198 = *(float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))m_pSimComponent->vfptr[24].__vecDelDtor)(m_pSimComponent);
                if ( this->m_pVehicleSubject.m_pSimComponent
                  && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent) )
                {
                  v199 = 1;
                  v200 = FLOAT_80_0;
                }
                else
                {
                  v199 = 0;
                  v200 = FLOAT_6_0;
                }
                v201 = 0.0;
                if ( this->m_bAllowedToPass )
                {
                  if ( v199 )
                    v200 = FLOAT_60_0;
                  else
                    v200 = 0.0;
                }
                if ( this->m_bTemporaryAllowedToPass )
                {
                  if ( v199 )
                    v200 = FLOAT_60_0;
                  else
                    v200 = 0.0;
                }
                v202 = (float)(v197 - v198) - v200;
                if ( v202 >= 0.0 )
                  v201 = v202;
                v203 = this->m_pVehicleSubject.m_pSimComponent
                    && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent);
                v204 = UFG::VehicleSubjectComponent::GetMass(m_pSimComponent);
                v205 = 0.0;
                if ( (float)(UFG::GetBrakingSpeedLimit(v201, 100.0, v204, v203) + v196) >= 0.0 )
                  v205 = v201;
                v206 = *v354;
                if ( *v354 >= v205 )
                  v206 = v205;
                *v354 = v206;
                v207 = (UFG::SimObject *)v147[2].mNext;
                if ( p_m_CurrentAvoidable->m_pPointer )
                {
                  v208 = p_m_CurrentAvoidable->mPrev;
                  v209 = p_m_CurrentAvoidable->mNext;
                  v208->mNext = v209;
                  v209->mPrev = v208;
                  p_m_CurrentAvoidable->mPrev = p_m_CurrentAvoidable;
                  p_m_CurrentAvoidable->mNext = p_m_CurrentAvoidable;
                }
                p_m_CurrentAvoidable->m_pPointer = v207;
                if ( v207 )
                {
                  v210 = v207->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                  v210->mNext = p_m_CurrentAvoidable;
                  p_m_CurrentAvoidable->mPrev = v210;
                  p_m_CurrentAvoidable->mNext = &v207->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
                  v207->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_CurrentAvoidable;
                }
                v211 = 0;
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v147->mPrev[18].mNext)(v147) )
                {
                  v212 = (UFG::SimObjectGame *)v147[2].mNext;
                  if ( v212 )
                  {
                    v213 = v212->m_Flags;
                    if ( (v213 & 0x4000) != 0 )
                    {
                      v214 = v212->m_Components.p[24].m_pComponent;
                    }
                    else if ( v213 >= 0 )
                    {
                      v214 = (v213 & 0x2000) != 0 || (v213 & 0x1000) != 0
                           ? UFG::SimObjectGame::GetComponentOfTypeHK(v212, UFG::RoadSpaceComponent::_TypeUID)
                           : UFG::SimObject::GetComponentOfType(v212, UFG::RoadSpaceComponent::_TypeUID);
                    }
                    else
                    {
                      v214 = v212->m_Components.p[24].m_pComponent;
                    }
                    if ( v214 )
                      v211 = v214[8].m_Flags;
                  }
                }
                v215 = (this->m_pVehicleSubject.m_pSimComponent
                     && UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent)
                     || !co_chaser[0])
                    && !v211;
                this->m_BlockedByAvoidable = v215;
                if ( v205 < 1.0
                  && ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *))v147->mPrev[20].mNext)(v147) )
                {
                  this->m_fAvoidStopTimer = 3.0;
                }
              }
            }
            z = v186 + v351[2];
            v243 = z;
            y = v187.m128_f32[0] + v351[1];
            v248 = y;
            x = v188 + *v351;
            v244 = x;
            point.x = x;
            point.y = y;
            point.z = z;
            LOBYTE(v234) = 1;
          }
          else
          {
            x = v244;
            z = v243;
            y = v248;
            v24 = v240;
          }
          v57 = v57->mNext;
          *(float *)&x_low = v245;
        }
        while ( v57 != (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list );
      }
      if ( this->m_AvoidanceDebug && LOBYTE(v234) )
      {
        close_limit.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + x;
        close_limit.y = y + (float)(UFG::qVector3::msDirUp.y * 0.69999999);
        close_limit.z = z + (float)(UFG::qVector3::msDirUp.z * 0.69999999);
        v220 = (float)(UFG::qVector3::msDirUp.z * 0.69999999) + v351[2];
        v221 = (float)(UFG::qVector3::msDirUp.y * 0.69999999) + v351[1];
        v247.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + *v351;
        v247.y = v221;
        v247.z = v220;
        Render::DebugDrawContext::DrawLine(
          Context,
          &v247,
          &close_limit,
          &UFG::qColour::Blue,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        close_limit.x = (float)(UFG::qVector3::msDirUp.x * 0.69999999) + x;
        close_limit.y = y + (float)(UFG::qVector3::msDirUp.y * 0.69999999);
        close_limit.z = z + (float)(UFG::qVector3::msDirUp.z * 0.69999999);
        Render::DebugDrawContext::DrawSphere(
          Context,
          &close_limit,
          0.60000002,
          &UFG::qColour::Blue,
          &UFG::qMatrix44::msIdentity,
          0i64);
      }
      v222 = z - v15->z;
      v223 = y - v15->y;
      close_limit.x = x - v15->x;
      close_limit.y = v223;
      close_limit.z = v222;
      v224 = UFG::RoadSpaceComponent::SteerTo(&v337, v15, radius, &point, &close_limit);
      v225 = v224->y;
      v226 = v224->z;
      v38 = v350;
      *v350 = v224->x;
      v38[1] = v225;
      v38[2] = v226;
      for ( i = list.mNode.mNext;
            (UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> *)list.mNode.mNext != &list;
            i = list.mNode.mNext )
      {
        v228 = i->mPrev;
        v229 = i->mNext;
        v228->mNext = v229;
        v229->mPrev = v228;
        i->mPrev = i;
        i->mNext = i;
        v351 = (float *)i;
        v230 = i->mPrev;
        v231 = i->mNext;
        v230->mNext = v231;
        v231->mPrev = v230;
        i->mPrev = i;
        i->mNext = i;
        operator delete[](i);
      }
      v232 = list.mNode.mPrev;
      v233 = list.mNode.mNext;
      list.mNode.mPrev->mNext = list.mNode.mNext;
      v233->mPrev = v232;
      list.mNode.mPrev = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list;
      list.mNode.mNext = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list;
    }
    else
    {
      v38 = v350;
      *v350 = steerToPos->x;
      v38[1] = steerToPos->y;
      v38[2] = steerToPos->z;
    }
    return (UFG::qVector3 *)v38;
  }
  else
  {
    *result = *steerToPos;
    return result;
  }
}v350 = v224->x;
      v38[1] = v225;
      v38[2] = v226;
      for ( i = list.mNode.mNext;
            (UFG::qList<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap,1,0> *)list.mNode.mNext != &list;
            i = list.mNode.mNext )
      {
        v228 = i->mPrev;
        v229 = i->mNext;
        v228->mNext = v229;
        v229->mPrev = v228;
        i->mPrev = i;
        i->mNext = i;
        v351 = (float *)i;
        v230 = i->mPrev;
        v231 = i->mNext;
        v230->mNext = v231;
        v231->mPrev = v230;
        i->mPrev = i;
        i->mNext = i;
        operator delete[](i);
      }
      v232 = list.mNode.mPrev;
      v233 = list.mNode.mNext;
      list.mNode.mPrev->mNext = list.mNode.mNext;
      v233->mPrev = v232;
      list.mNode.mPrev = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list;
      list.mNode.mNext = (UFG::qNode<UFG::AiDriverComponent::AvoidableOverlap,UFG::AiDriverComponent::AvoidableOverlap> *)&list;
    }
    else
    {
      v38 = v350;
      *v350 = steerToPos->x;
      v38[1] = steerToPos->y;
      v38[2] = steerToPos->z;
    }
    return (UFG::qVector3 *)v38;
  }
  else
  {


// File Line: 6256
// RVA: 0x65FE50
void __fastcall UFG::AiDriverComponent::UpdateAvoidableSensor(UFG::AiDriverComponent *this, float delta_seconds)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  double v4; // xmm0_8
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
  float BumperGap; // xmm0_4
  bool m_bAllowedToPass; // al
  float v28; // xmm11_4
  bool m_bTemporaryAllowedToPass; // cl
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
  __m128 y_low; // xmm3
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
  float buf; // [rsp+28h] [rbp-69h] BYREF
  float v72; // [rsp+2Ch] [rbp-65h]
  float v73; // [rsp+30h] [rbp-61h]
  int nbytes; // [rsp+34h] [rbp-5Dh] BYREF
  float v75; // [rsp+38h] [rbp-59h]
  float v76; // [rsp+3Ch] [rbp-55h]
  void *retaddr; // [rsp+F8h] [rbp+67h]
  float v78; // [rsp+108h] [rbp+77h]

  m_pSimComponent = this->m_pVehicleSubject.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v4 = ((double (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[21].__vecDelDtor)(m_pSimComponent);
    v5 = *(float *)&v4;
    if ( *(float *)&v4 >= 5.0 )
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
    v11 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[20].__vecDelDtor)(m_pSimComponent);
    v12 = FLOAT_2_0;
    v13 = *(float *)v11;
    v14 = (__m128)*(unsigned int *)(v11 + 4);
    v15 = *(float *)(v11 + 8);
    if ( this->m_bAllowedToPass )
      v12 = *(float *)&FLOAT_1_0;
    v16 = v13 * v12;
    v17 = v14.m128_f32[0] * v12;
    v18 = v15 * v12;
    v19 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[16].__vecDelDtor)(m_pSimComponent);
    v22 = v14;
    v20 = 0.0;
    v21 = *v19;
    *(float *)&retaddr = v19[1];
    v78 = v19[2];
    v22.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v13 * v13)) + (float)(v15 * v15);
    if ( v22.m128_f32[0] >= 1.0 )
    {
      if ( v22.m128_f32[0] == 0.0 )
        v23 = 0.0;
      else
        v23 = 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
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
    BumperGap = UFG::AiDriverComponent::GetBumperGap(this);
    m_bAllowedToPass = this->m_bAllowedToPass;
    v28 = FLOAT_0_2;
    if ( m_bAllowedToPass )
      v28 = FLOAT_0_40000001;
    m_bTemporaryAllowedToPass = this->m_bTemporaryAllowedToPass;
    if ( m_bTemporaryAllowedToPass )
      v28 = FLOAT_0_2;
    v30 = v28 + BumperGap;
    v31 = v17 + (float)(v25 * v30);
    v32 = v18 + (float)(v69 * v30);
    v33 = v16 + (float)(v24 * v30);
    if ( m_bTemporaryAllowedToPass || m_bAllowedToPass )
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
    v46 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[17].__vecDelDtor)(m_pSimComponent);
    y_low = (__m128)LODWORD(this->m_vSteerToPosition.y);
    v47 = this->m_vSteerToPosition.x - *v46;
    y_low.m128_f32[0] = y_low.m128_f32[0] - v46[1];
    v49 = this->m_vSteerToPosition.z - v46[2];
    v50 = y_low;
    v50.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v47 * v47)) + (float)(v49 * v49);
    if ( v50.m128_f32[0] >= 0.010000001 )
    {
      if ( v50.m128_f32[0] != 0.0 )
        v20 = 1.0 / _mm_sqrt_ps(v50).m128_f32[0];
      v66 = v47 * v20;
      v68 = y_low.m128_f32[0] * v20;
      v70 = v49 * v20;
    }
    else
    {
      v66 = v21;
      v68 = *(float *)&retaddr;
      v70 = v78;
    }
    v51 = v47 + (float)(v66 * v30);
    v52 = nbytes;
    v53 = y_low.m128_f32[0] + (float)(v68 * v30);
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
    Scaleform::Render::WrapperImageSource::GetFormat((hkSubStreamWriter *)this->m_AvoidableSensor, &buf, (int)&nbytes);
    v64 = (UFG::qMatrix44 *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[18].__vecDelDtor)(m_pSimComponent);
    UFG::SensorPhantom::SetTransform(this->m_AvoidableSensor, v64);
  }
}

// File Line: 6344
// RVA: 0x64F220
float __fastcall UFG::AiDriverComponent::GetRoadHolding(UFG::AiDriverComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  float v3; // xmm6_4
  UFG::VehicleSubjectComponent *v4; // rcx

  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    v3 = *((float *)&m_pSimComponent[11].m_pSimObject + 1);
  else
    v3 = *(float *)&FLOAT_1_0;
  if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this)
    && (v4 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent) != 0i64
    && UFG::VehicleSubjectComponent::IsBoat(v4) )
  {
    return FLOAT_0_1;
  }
  else
  {
    return v3;
  }
}

// File Line: 6353
// RVA: 0x660A30
float __fastcall UFG::AiDriverComponent::UpdateChaseSpeed(UFG::AiDriverComponent *this, float seconds)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v6; // rax
  float x; // xmm10_4
  float m_fFollowOffsetBlend; // xmm12_4
  double v9; // xmm0_8
  UFG::SimComponent *m_pSimComponent; // rax
  float v11; // xmm11_4
  float v12; // xmm1_4
  float v13; // xmm8_4
  float m_fChaseSpeedLimit; // xmm9_4
  float v15; // xmm6_4
  float v16; // xmm8_4
  float RoadHolding; // xmm2_4
  float v18; // xmm10_4
  float SpeedLimitForCurvature; // xmm11_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  UFG::VehicleSubjectComponent *v23; // rcx
  float v24; // xmm6_4
  bool v25; // di
  UFG::VehicleSubjectComponent *v26; // rcx
  float Mass; // xmm0_4
  float v28; // xmm6_4
  float result; // xmm0_4

  m_pSimObject = (UFG::SimObjectGame *)this->m_pRoadSpace.m_pSimComponent[26].m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pSimObject = (UFG::SimObjectGame *)m_pSimObject->m_Components.p[37].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::CameraSubject::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CameraSubject::_TypeUID);
      m_pSimObject = (UFG::SimObjectGame *)ComponentOfTypeHK;
    }
    else
    {
      m_pSimObject = (UFG::SimObjectGame *)m_pSimObject->m_Components.p[31].m_pComponent;
    }
  }
  v6 = this->m_pSimObject;
  if ( !v6 || !v6->m_Components.p[2].m_pComponent || !this->m_pRoadSpace.m_pSimComponent || !m_pSimObject )
    return 0.0;
  x = this->m_vFollowOffsetDesired.x;
  m_fFollowOffsetBlend = this->m_fFollowOffsetBlend;
  v9 = ((double (*)(void))m_pSimObject->vfptr[28].__vecDelDtor)();
  m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
  v11 = *(float *)&m_pSimComponent[29].m_BoundComponentHandles.mNode.mPrev;
  LODWORD(v12) = LODWORD(v9) & _xmm;
  v13 = 1.0 - (float)(v11 * this->m_vFollowOffsetActual.y);
  if ( v13 < 0.0 )
    v13 = 0.0;
  m_fChaseSpeedLimit = this->m_fChaseSpeedLimit;
  v15 = (float)((float)(this->m_vFollowOffsetActual.x - COERCE_FLOAT(LODWORD(m_pSimComponent[29].m_pSimObject) ^ _xmm[0]))
              * m_fFollowOffsetBlend)
      + COERCE_FLOAT(LODWORD(m_pSimComponent[29].m_pSimObject) ^ _xmm[0]);
  v16 = (float)((float)((float)(v13 - 1.0) * m_fFollowOffsetBlend) + 1.0) * v12;
  if ( m_fChaseSpeedLimit < 0.0 )
    m_fChaseSpeedLimit = FLOAT_35_0;
  if ( m_fChaseSpeedLimit <= (float)(UFG::AiDriverComponent::m_fChaseFasterThanTarget + v12) )
    m_fChaseSpeedLimit = UFG::AiDriverComponent::m_fChaseFasterThanTarget + v12;
  RoadHolding = UFG::AiDriverComponent::GetRoadHolding(this);
  v18 = x - v15;
  SpeedLimitForCurvature = UFG::GetSpeedLimitForCurvature(v11, m_fChaseSpeedLimit, RoadHolding);
  if ( v18 <= -5.0 )
  {
    v21 = FLOAT_N5_0;
  }
  else
  {
    v20 = FLOAT_5_0;
    v21 = v18;
    if ( v18 >= 5.0 )
      goto LABEL_26;
  }
  v20 = v21;
LABEL_26:
  v22 = sinf((float)(v20 - -5.0) * 0.15707964);
  v23 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  v24 = (float)((float)(v22 * v22) * 20.0) - 10.0;
  v25 = v23 && UFG::VehicleSubjectComponent::IsBoat(v23);
  v26 = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  if ( v26 )
    Mass = UFG::VehicleSubjectComponent::GetMass(v26);
  else
    Mass = FLOAT_2000_0;
  v28 = (float)((float)((float)(v24 + v16) - SpeedLimitForCurvature) * m_fFollowOffsetBlend) + SpeedLimitForCurvature;
  result = UFG::GetBrakingSpeedLimit(v18, m_fChaseSpeedLimit, Mass, v25) + v16;
  if ( result >= v28 )
    result = v28;
  if ( result <= 0.0 )
    return 0.0;
  return result;
}

// File Line: 6395
// RVA: 0x6582E0
UFG::qVector3 *__fastcall UFG::AiDriverComponent::RotateSteerTo(
        UFG::AiDriverComponent *this,
        UFG::qVector3 *result,
        UFG::qVector3 *steer_to,
        float steer_to_distance,
        float radians)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pComponent; // rbx
  float x; // xmm11_4
  float y; // xmm10_4
  float z; // xmm9_4
  float v12; // xmm8_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm0_4
  UFG::qVector3 *v16; // rax

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pComponent = (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent;
  else
    m_pComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
  x = m_pComponent->mWorldTransform.v3.x;
  y = m_pComponent->mWorldTransform.v3.y;
  z = m_pComponent->mWorldTransform.v3.z;
  v12 = steer_to->z - z;
  v13 = atan2f(steer_to->y - y, steer_to->x - x) + radians;
  v14 = cosf(v13);
  v15 = sinf(v13);
  result->x = x + (float)(v14 * steer_to_distance);
  result->z = z + v12;
  v16 = result;
  result->y = y + (float)(v15 * steer_to_distance);
  return v16;
}

// File Line: 6408
// RVA: 0x65DF70
UFG::qVector3 *__fastcall UFG::AiDriverComponent::SteerToFollowOffset(
        UFG::AiDriverComponent *this,
        UFG::qVector3 *result,
        float delta_seconds,
        float steer_to_distance,
        UFG::qVector3 *steer_to)
{
  UFG::qVector3 *v5; // rsi
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimComponent *m_pComponent; // r13
  UFG::SimObjectGame *v10; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *v14; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  Render::DebugDrawContext *Context; // r15
  __m128 y_low; // xmm1
  float v18; // xmm9_4
  float v19; // xmm6_4
  bool v20; // zf
  __m128 v21; // xmm2
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm6_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float y; // xmm1_4
  float m_fFollowOffsetBlend; // xmm12_4
  float v29; // xmm7_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm6_4
  UFG::qVector3 *v33; // rax
  float v34; // xmm0_4
  float v35; // xmm5_4
  float z; // xmm6_4
  float v37; // xmm4_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  float v40; // xmm6_4
  float v41; // xmm5_4
  float g; // xmm1_4
  UFG::qColour *v43; // r9
  float b; // xmm0_4
  float m_fFollowOffsetTolerance; // xmm2_4
  float v46; // xmm2_4
  float ray_4; // [rsp+24h] [rbp-7Dh]
  float pre_draw_callback; // [rsp+28h] [rbp-79h]
  UFG::qVector3 resulta; // [rsp+30h] [rbp-71h] BYREF
  UFG::qVector3 p1; // [rsp+40h] [rbp-61h] BYREF
  UFG::qColour ray; // [rsp+50h] [rbp-51h] BYREF
  UFG::qVector3 *p0; // [rsp+120h] [rbp+7Fh]
  UFG::qVector3 *p0a; // [rsp+120h] [rbp+7Fh]

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject
    || (m_pComponent = m_pSimObject->m_Components.p[2].m_pComponent) == 0i64
    || (v10 = (UFG::SimObjectGame *)this->m_pRoadSpace.m_pSimComponent[26].m_pSimObject) == 0i64 )
  {
    *result = *p0;
    return result;
  }
  m_pTransformNodeComponent = v10->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
  {
    *result = *p0;
    return result;
  }
  m_Flags = v10->m_Flags;
  p0a = v5;
  if ( (m_Flags & 0x4000) != 0 )
  {
    v14 = (UFG::RoadSpaceComponent *)v10->m_Components.p[24].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RoadSpaceComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v10, UFG::RoadSpaceComponent::_TypeUID);
    v14 = (UFG::RoadSpaceComponent *)ComponentOfTypeHK;
  }
  else
  {
    v14 = (UFG::RoadSpaceComponent *)v10->m_Components.p[24].m_pComponent;
  }
  if ( v14 )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    if ( this->m_FollowDebug )
    {
      ray = UFG::qColour::Yellow;
      UFG::CrumbTrail::DebugDraw(&v14->m_PositionTrail, &ray, -1);
    }
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pComponent);
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    y_low = (__m128)LODWORD(this->m_vFollowOffsetActual.y);
    y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - this->m_vFollowOffsetDesired.y)
                              * (float)(y_low.m128_f32[0] - this->m_vFollowOffsetDesired.y))
                      + (float)((float)(this->m_vFollowOffsetActual.x - this->m_vFollowOffsetDesired.x)
                              * (float)(this->m_vFollowOffsetActual.x - this->m_vFollowOffsetDesired.x));
    v18 = _mm_sqrt_ps(y_low).m128_f32[0];
    if ( v18 >= this->m_fFollowOffsetTolerance )
      v19 = 0.0;
    else
      v19 = delta_seconds + this->m_fTimeNearOffset;
    v20 = this->m_CurrentAttack == NumAttacks;
    this->m_fTimeNearOffset = v19;
    v21 = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
    v22 = m_pTransformNodeComponent->mWorldTransform.v3.x
        - *(float *)&m_pComponent[2].m_BoundComponentHandles.mNode.mPrev;
    v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0]
                                            - *((float *)&m_pComponent[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                    * (float)(v21.m128_f32[0]
                                            - *((float *)&m_pComponent[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                            + (float)(v22 * v22))
                    + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z
                                    - *(float *)&m_pComponent[2].m_BoundComponentHandles.mNode.mNext)
                            * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z
                                    - *(float *)&m_pComponent[2].m_BoundComponentHandles.mNode.mNext));
    v23 = _mm_sqrt_ps(v21).m128_f32[0];
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
    this->m_fFollowOffsetBlend = v25;
    y = p0a->y;
    p1.x = p0a->x;
    ray_4 = y;
    pre_draw_callback = p0a->z;
    UFG::RoadSpaceComponent::ChaseToWorld(v14, &resulta, &this->m_vFollowOffsetDesired, (UFG::qVector3 *)&ray);
    m_fFollowOffsetBlend = this->m_fFollowOffsetBlend;
    if ( m_fFollowOffsetBlend <= 0.0 )
      goto LABEL_48;
    if ( this->mMoverComponent.m_pSimComponent )
      v29 = *((float *)&this->mMoverComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1);
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
    v31 = (float)(this->m_vFollowOffsetDesired.y - this->m_vFollowOffsetActual.y) / (float)(v18 + steer_to_distance);
    if ( v31 <= -1.0 )
    {
      v31 = FLOAT_N1_0;
    }
    else if ( v31 >= v24 )
    {
LABEL_46:
      v32 = sinf((float)(v24 - -1.0) * 0.78539819);
      UFG::RoadSpaceComponent::SteerTo(
        &p1,
        (UFG::qVector3 *)&m_pComponent[2].m_BoundComponentHandles,
        steer_to_distance,
        &resulta,
        (UFG::qVector3 *)&ray);
      v33 = UFG::AiDriverComponent::RotateSteerTo(
              this,
              (UFG::qVector3 *)&ray,
              &p1,
              steer_to_distance,
              (float)((float)((float)(v32 * v32) * 0.69813174) - 0.34906587) * (float)(m_fFollowOffsetBlend * v30));
      v34 = this->m_fFollowOffsetBlend;
      v35 = v33->y;
      z = v33->z;
      p1.x = v33->x;
      v37 = p1.x - p0a->x;
      p1.y = v35;
      v38 = v35 - p0a->y;
      v39 = (float)(v37 * v34) + p0a->x;
      p1.z = z;
      v40 = z - p0a->z;
      v41 = (float)(v38 * v34) + p0a->y;
      p1.x = v39;
      ray_4 = v41;
      pre_draw_callback = (float)(v40 * v34) + p0a->z;
      if ( this->m_FollowDebug )
      {
        Render::DebugDrawContext::DrawLine(Context, p0a, &p1, &UFG::qColour::Cyan, &UFG::qMatrix44::msIdentity, 0i64, 0);
        Render::DebugDrawContext::DrawSphere(
          Context,
          &p1,
          0.60000002,
          &UFG::qColour::Cyan,
          &UFG::qMatrix44::msIdentity,
          0i64);
        Render::DebugDrawContext::DrawSphere(Context, &p1, 0.2, &UFG::qColour::Red, &UFG::qMatrix44::msIdentity, 0i64);
      }
LABEL_48:
      if ( this->m_FollowDebug )
      {
        if ( this->m_fTimeNearOffset <= 0.0 )
        {
          UFG::RoadSpaceComponent::ChaseToWorld(v14, (UFG::qVector3 *)&ray, &this->m_vFollowOffsetActual, 0i64);
          m_fFollowOffsetTolerance = this->m_fFollowOffsetTolerance;
          p1.x = resulta.x;
          p1.y = resulta.y;
          p1.z = resulta.z + 0.5;
          Render::DebugDrawContext::DrawCircle(
            Context,
            &p1,
            m_fFollowOffsetTolerance,
            &UFG::qColour::Yellow,
            &UFG::qMatrix44::msIdentity,
            0i64);
          g = ray.g;
          v43 = &UFG::qColour::Blue;
          p1.x = ray.r;
          b = ray.b;
        }
        else
        {
          g = resulta.y;
          v43 = &UFG::qColour::Green;
          p1.x = resulta.x;
          b = resulta.z;
        }
        v46 = this->m_fFollowOffsetTolerance;
        p1.z = b + 0.5;
        p1.y = g;
        Render::DebugDrawContext::DrawCircle(Context, &p1, v46, v43, &UFG::qMatrix44::msIdentity, 0i64);
      }
      result->x = p1.x;
      result->y = ray_4;
      result->z = pre_draw_callback;
      return result;
    }
    v24 = v31;
    goto LABEL_46;
  }
  result->x = p0a->x;
  result->y = p0a->y;
  result->z = p0a->z;
  return result;
}

// File Line: 6482
// RVA: 0x659210
void __fastcall UFG::AiDriverComponent::SetFollowOffset(
        UFG::AiDriverComponent *this,
        float x,
        float y,
        float tolerance)
{
  if ( this->m_DesiredOffset == Follow
    && (float)((float)((float)((float)(this->m_vFollowOffsetDesired.y - y) * (float)(this->m_vFollowOffsetDesired.y - y))
                     + (float)((float)(this->m_vFollowOffsetDesired.x - x) * (float)(this->m_vFollowOffsetDesired.x - x)))
             + (float)(this->m_vFollowOffsetDesired.z * this->m_vFollowOffsetDesired.z)) >= (float)(this->m_fFollowOffsetTolerance
                                                                                                  * this->m_fFollowOffsetTolerance) )
  {
    this->m_fTimeNearOffset = 0.0;
  }
  this->m_DesiredOffset = Follow;
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
  return UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &qSymbol_Taxi);
}

// File Line: 6567
// RVA: 0x659620
void __fastcall UFG::AiDriverComponent::SetParked(UFG::AiDriverComponent *this, bool parked)
{
  UFG::SimComponent *m_pSimComponent; // rsi
  UFG::RoadNetworkLane *m_CurrentLane; // rdi
  UFG::RoadNetworkGuide *p_mNext; // rcx
  UFG::RoadNetworkLocation *Name; // rax
  float mOffset; // xmm6_4
  float v8; // xmm0_4
  UFG::RoadNetworkLocation *v9; // rax
  UFG::RoadNetworkSegment *RoadNetworkNode; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-28h] BYREF

  if ( this->m_bIsParked != parked )
  {
    this->m_bIsParked = parked;
    m_pSimComponent = this->m_pRoadSpace.m_pSimComponent;
    m_CurrentLane = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext)->m_CurrentLane;
    p_mNext = (UFG::RoadNetworkGuide *)&this->m_pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext;
    if ( this->m_bIsParked )
    {
      Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
      UFG::RoadNetworkLocation::GetPos(Name, &result);
      UFG::RoadNetworkGuide::Park((UFG::RoadNetworkGuide *)&m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext);
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
      mOffset = m_CurrentLane->mOffset;
      v8 = UFG::RoadNetworkLane::CalculateParkingOffset(m_CurrentLane, &result);
      if ( v8 <= mOffset )
        v8 = mOffset;
      m_CurrentLane->mOffset = v8;
    }
    else
    {
      v9 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
      RoadNetworkNode = (UFG::RoadNetworkSegment *)UFG::RoadNetworkLocation::GetRoadNetworkNode(v9);
      UFG::RoadNetworkSegment::RecalculateLaneOffset(RoadNetworkNode, m_CurrentLane->mLaneIndex);
    }
  }
}

// File Line: 6597
// RVA: 0x658E30
void __fastcall UFG::AiDriverComponent::SetDrivingRoleByClassType(UFG::AiDriverComponent *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::qPropertySet *mpWritableProperties; // rdi
  unsigned int ClassTypes; // eax
  unsigned int v5; // edi
  UFG::qSymbol *v6; // r11
  unsigned int mUID; // r10d
  UFG::qSymbol ptr[16]; // [rsp+40h] [rbp-48h] BYREF

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( mpWritableProperties || (mpWritableProperties = m_pSceneObj->mpConstProperties) != 0i64 )
  {
    `eh vector constructor iterator(ptr, 4ui64, 16, (void (__fastcall *)(void *))BackInfo::BackInfo);
    ClassTypes = UFG::SimObjectUtility::GetClassTypes(mpWritableProperties, ptr, 0x10u);
    v5 = 0;
    if ( ClassTypes )
    {
      v6 = ptr;
      while ( 1 )
      {
        mUID = v6->mUID;
        if ( v6->mUID == qSymbol_Ferry.mUID )
        {
          if ( this->m_DrivingRole == 8 )
            goto LABEL_27;
          this->m_DrivingRole = 8;
LABEL_23:
          if ( !this->m_RoadRuleFlagsLocked )
          {
            this->m_bStayOffSidewalk = 1;
            this->m_bAllowedToPass = 0;
            this->m_bAvoidPeds = 1;
LABEL_25:
            this->m_bRespectSpeedLimit = 1;
            this->m_bCanTurnAround = 0;
          }
LABEL_26:
          this->m_bSavedAvoidPeds = this->m_bAvoidPeds;
          goto LABEL_27;
        }
        if ( mUID == qSymbol_Tram.mUID )
          break;
        if ( mUID == qSymbol_Minibus.mUID )
        {
          if ( this->m_DrivingRole == 6 )
            goto LABEL_27;
          this->m_DrivingRole = 6;
          goto LABEL_23;
        }
        if ( mUID == qSymbol_Boat_21.mUID )
        {
          if ( this->m_DrivingRole == 9 )
            goto LABEL_27;
          this->m_DrivingRole = 9;
          if ( !this->m_RoadRuleFlagsLocked )
          {
            this->m_bAvoidPeds = 0;
            this->m_fAvoidStopTimer = 0.0;
            this->m_bAllowedToPass = 1;
            this->m_bStayOffSidewalk = 0;
            goto LABEL_25;
          }
          goto LABEL_26;
        }
        ++v5;
        ++v6;
        if ( v5 >= ClassTypes )
          goto LABEL_27;
      }
      if ( this->m_DrivingRole != 7 )
      {
        this->m_DrivingRole = 7;
        if ( !this->m_RoadRuleFlagsLocked )
        {
          this->m_bAvoidPeds = 0;
          this->m_fAvoidStopTimer = 0.0;
          this->m_bAllowedToPass = 0;
          this->m_bStayOffSidewalk = 0;
          this->m_bRespectSpeedLimit = 1;
          this->m_bCanTurnAround = 0;
        }
        this->m_bSavedAvoidPeds = this->m_bAvoidPeds;
      }
      this->m_RoadRuleFlagsLocked = 1;
    }
LABEL_27:
    `eh vector destructor iterator(ptr, 4ui64, 16, (void (__fastcall *)(void *))_);
  }
}

// File Line: 6654
// RVA: 0x651B20
bool __fastcall UFG::AiDriverComponent::IsBoat(UFG::AiDriverComponent *this)
{
  UFG::VehicleSubjectComponent *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::VehicleSubjectComponent *)this->m_pVehicleSubject.m_pSimComponent;
  return m_pSimComponent && UFG::VehicleSubjectComponent::IsBoat(m_pSimComponent);
}

// File Line: 6661
// RVA: 0x652100
bool __fastcall UFG::AiDriverComponent::IsTransit(UFG::AiDriverComponent *this)
{
  return this->m_DrivingRole - 6 <= 2;
}

