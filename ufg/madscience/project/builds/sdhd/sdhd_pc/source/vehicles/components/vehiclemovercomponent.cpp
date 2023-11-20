// File Line: 119
// RVA: 0x1582E30
__int64 UFG::_dynamic_initializer_for__gVehicleTakenDownChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gVehicleTakenDownChannel, "EVT_VEHICLE_TAKENDOWN", 0i64);
  return atexit(UFG::_dynamic_atexit_destructor_for__gVehicleTakenDownChannel__);
}

// File Line: 120
// RVA: 0x1582E00
__int64 UFG::_dynamic_initializer_for__gVehicleDisabledChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gVehicleDisabledChannel, "EVT_VEHICLE_DISABLED", 0i64);
  return atexit(UFG::_dynamic_atexit_destructor_for__gVehicleDisabledChannel__);
}

// File Line: 123
// RVA: 0x685F10
void __fastcall UFG::PhysicsMoverInterface_EmitVehicleDisabledEvent(UFG::SimObject *pVehicle)
{
  __int64 **v1; // rcx
  __int64 *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::Event *v4; // rbx
  const char *v5; // rcx
  UFG::allocator::free_link *v6; // rax
  UFG::Event *v7; // rdx
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  __int64 *v10; // rcx
  __int64 **v11; // rax
  __int64 *v12; // rcx
  __int64 **v13; // rax
  __int64 *v14; // [rsp+28h] [rbp-18h]
  __int64 **v15; // [rsp+30h] [rbp-10h]
  UFG::SimObject *v16; // [rsp+38h] [rbp-8h]

  v14 = (__int64 *)&v14;
  v15 = &v14;
  v16 = pVehicle;
  if ( pVehicle )
  {
    v1 = (__int64 **)&pVehicle->m_SafePointerList;
    v2 = *v1;
    v2[1] = (__int64)&v14;
    v14 = v2;
    v15 = v1;
    *v1 = (__int64 *)&v14;
  }
  v3 = UFG::qMalloc(0x50ui64, "AnimatedEvent", 0i64);
  v4 = (UFG::Event *)v3;
  if ( v3 )
  {
    v5 = UFG::gVehicleDisabledChannel.mName;
    v6 = v3 + 1;
    v6->mNext = v6;
    v6[1].mNext = v6;
    v4->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
    v4->m_NamePTR = v5;
    v4->m_EventUID = UFG::qStringHash32(v5, 0xFFFFFFFF);
    v4->vfptr = (UFG::EventVtbl *)&UFG::AnimatedEvent::`vftable;
    v7 = v4 + 1;
    v7->vfptr = (UFG::EventVtbl *)v7;
    v7->mPrev = (UFG::qNode<UFG::Event,UFG::Event> *)v7;
    v4[1].mNext = (UFG::qNode<UFG::Event,UFG::Event> *)v16;
    if ( v16 )
    {
      v8 = &v16->m_SafePointerList;
      v9 = v16->m_SafePointerList.mNode.mPrev;
      v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v7;
      v7->vfptr = (UFG::EventVtbl *)v9;
      v4[1].mPrev = (UFG::qNode<UFG::Event,UFG::Event> *)v8;
      v8->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v7;
    }
  }
  else
  {
    v4 = 0i64;
  }
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v4);
  if ( v16 )
  {
    v10 = v14;
    v11 = v15;
    v14[1] = (__int64)v15;
    *v11 = v10;
    v14 = (__int64 *)&v14;
    v15 = &v14;
  }
  v12 = v14;
  v13 = v15;
  v14[1] = (__int64)v15;
  *v13 = v12;
}

// File Line: 138
// RVA: 0x667C50
void __fastcall UFG::CruiseControl::CruiseControl(UFG::CruiseControl *this, float pid_p, float pid_i, float pid_d)
{
  UFG::CruiseControl *v4; // rbx
  UFG::qPidController *v5; // rax

  v4 = this;
  this->vfptr = (UFG::CruiseControlVtbl *)&UFG::CruiseControl::`vftable;
  *(_WORD *)&this->mIsActive = 0;
  v5 = (UFG::qPidController *)UFG::qMalloc(0xB0ui64, "qPidController", 0i64);
  if ( v5 )
    UFG::qPidController::qPidController(v5);
  v4->mPidController = v5;
  v5->m_ParameterBlock.m_P_Coefficient = pid_p;
  v5->m_ParameterBlock.m_I_Coefficient = pid_i;
  v5->m_ParameterBlock.m_D_Coefficient = pid_d;
  v4->mSetSpeedMPS = 0.0;
}

// File Line: 166
// RVA: 0x690610
float __fastcall UFG::CruiseControl::Update(UFG::CruiseControl *this, float deltaTime, float speedMPS, float gasBrakes, bool overrideSpeed)
{
  UFG::CruiseControl *v5; // rbx
  float result; // xmm0_4
  float v7; // xmm1_4
  UFG::qPidControllerCore *v8; // rcx

  v5 = this;
  UFG::qPidControllerCore::Record(
    (UFG::qPidControllerCore *)&this->mPidController->m_Parameters,
    speedMPS - this->mSetSpeedMPS,
    deltaTime,
    0i64);
  if ( v5->mIsEnabled )
  {
    v5->mIsActive = 1;
    if ( overrideSpeed )
    {
      v5->mSetSpeedMPS = speedMPS;
      result = gasBrakes;
    }
    else
    {
      result = UFG::qPidControllerCore::GetOutput((UFG::qPidControllerCore *)&v5->mPidController->m_Parameters);
      v7 = FLOAT_N1_0;
      if ( result <= -1.0 || (v7 = 0.0, result >= 0.0) )
        result = v7;
    }
  }
  else
  {
    v8 = (UFG::qPidControllerCore *)&v5->mPidController->m_Parameters;
    v5->mIsActive = 0;
    UFG::qPidControllerCore::Clear(v8);
    result = gasBrakes;
  }
  return result;
}

// File Line: 213
// RVA: 0x157B830
__int64 dynamic_initializer_for__UFG::PhysicsMoverInterface::s_VehicleAttacks__()
{
  `eh vector constructor iterator(
    &UFG::PhysicsMoverInterface::s_VehicleAttacks,
    0x38ui64,
    200,
    (void (__fastcall *)(void *))UFG::AttackData::AttackData);
  UFG::PhysicsMoverInterface::s_VehicleAttacks.size = 0;
  return atexit(dynamic_atexit_destructor_for__UFG::PhysicsMoverInterface::s_VehicleAttacks__);
}

// File Line: 235
// RVA: 0x157B7F0
__int64 dynamic_initializer_for__UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList__);
}

// File Line: 236
// RVA: 0x157AD00
__int64 dynamic_initializer_for__UFG::PhysicsMoverInterface::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::PhysicsMoverInterface::AccessComponentDesc();
  *(_DWORD *)&UFG::PhysicsMoverInterface::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::PhysicsMoverInterface::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::PhysicsMoverInterface::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 303
// RVA: 0x669BC0
void __fastcall UFG::PhysicsMoverInterface::PhysicsMoverInterface(UFG::PhysicsMoverInterface *this, int numWheels, UFG::SceneObjectProperties *pSceneObj, component_PhysicsMover *dataPtr)
{
  component_PhysicsMover *v4; // rsi
  UFG::SceneObjectProperties *v5; // rbp
  int v6; // ebx
  UFG::PhysicsMoverInterface *v7; // r14
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v8; // rdi
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // [rsp+80h] [rbp+18h]

  v4 = dataPtr;
  v5 = pSceneObj;
  v6 = numWheels;
  v7 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, pSceneObj->m_NameUID);
  v7->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  v8 = (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *)&v7->mPrev;
  v8->mPrev = v8;
  v8->mNext = v8;
  v7->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhysicsMoverInterface::`vftable{for `UFG::SimComponent};
  v7->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::PhysicsMoverInterface::`vftable{for `UFG::UpdateInterface};
  *(_QWORD *)&v7->mInput.mSteering = 0i64;
  *(_QWORD *)&v7->mInput.mGasBrakes = 0i64;
  *((_DWORD *)&v7->mInput + 4) &= 0xFFFFF800;
  UFG::RebindingComponentHandle<UFG::VehicleDriverInterface,0>::RebindingComponentHandle<UFG::VehicleDriverInterface,0>(&v7->mDriverComponent);
  *(_QWORD *)&v7->mDestructState = 0i64;
  *(_QWORD *)&v7->mDestructTimerInitial = 0i64;
  v12 = &v7->mLastDamageSource;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v7->mLastDamageSource.m_pPointer = 0i64;
  *(_QWORD *)&v7->mPropertySetNameAI.mUID = -1i64;
  v7->mPropertySetExplosion.mUID = -1;
  `eh vector constructor iterator(
    v7->mTargetSpheres,
    0x40ui64,
    5,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  UFG::VehicleParams::VehicleParams(&v7->mParameters);
  v7->mPhysicsVehicle = 0i64;
  v7->mRammingState = 0i64;
  v7->mPostRamImmunityTimer = 0.0;
  *(_QWORD *)&v7->mForwardSpeed = 0i64;
  v7->mDamageMultiplierWorldCollisions = 1.0;
  v7->mDamageMultiplierVehicleCollisions = 1.0;
  v7->mDamageMultiplierAttack = 1.0;
  v7->mDamageMultiplierBullets = 1.0;
  *(_QWORD *)&v7->mDamageMultiplierTires = 1065353216i64;
  *(_QWORD *)&v7->mTireBlownImpulse = 0i64;
  *(_QWORD *)&v7->mAutoDeterioratingDamageThreshold = 0i64;
  *(_QWORD *)&v7->mNotMovingTime = 0i64;
  v7->mGroundFixupRequired = 0;
  v7->mNumWheels = v6;
  *(_QWORD *)&v7->mLockAtHighLODMode = 3i64;
  v7->mVehicleCollisionMinImpulseRequiredToTakeDamage = 5.0;
  v7->mVehicleCollisionDamageDealtAtMinImpulse = 0.1;
  v7->mVehicleCollisionDamageDealtAtMaxImpulse = 0.2;
  v7->mVehicleCollisionDamageDealtAtMinRamImpulse = 0.1;
  v7->mVehicleCollisionDamageDealtAtMaxRamImpulse = 0.2;
  v7->mVehicleCollisionExtraDamageMultiplier = 1.5;
  v7->mVehicleCollisionMinImpulseRequiredToDealDamage = 5.0;
  v7->mVehicleCollisionMaxImpulseForDealingDamage = 10.0;
  v7->mVehicleCollisionMinRamImpulseRequiredToDealDamage = 5.0;
  *(_QWORD *)&v7->mVehicleCollisionMaxRamImpulseForDealingDamage = 1092616192i64;
  v7->mSecondsEngineHasBeenDeteriorating = -1.0;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v7->mRamVelocity.x = UFG::qVector3::msZero.x;
  v7->mRamVelocity.y = v9;
  v7->mRamVelocity.z = v10;
  *((_DWORD *)v7 + 224) &= 0xFFFFFFE4;
  *((_BYTE *)v7 + 900) &= 0xC0u;
  *(_WORD *)&v7->mDoorsLocked = 1;
  v7->mCreatedWithTemporaryRig = 0;
  v7->mTrunkType = 0;
  v11 = UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mPrev;
  UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mPrev->mNext = (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *)&v7->mPrev;
  v8->mPrev = v11;
  v7->mNext = (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList;
  UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mPrev = (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *)&v7->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v7->vfptr,
    UFG::PhysicsMoverInterface::_PhysicsMoverInterfaceTypeUID,
    "PhysicsMoverInterface");
  UFG::PhysicsMoverInterface::PropertiesLoad(v7, v5, v4);
  *(_QWORD *)v7->mDamageState.tireDamage.array = 0i64;
  *(_QWORD *)&v7->mDamageState.tireDamage.array[2] = 0i64;
  v7->mDamageState.engineDamage = 0.0;
  v7->mMotorBoneId = (UFG::qSafeArray<int,2>)-1i64;
  v7->mPropellerBoneId = (UFG::qSafeArray<int,2>)-1i64;
}

// File Line: 322
// RVA: 0x66CC00
void __fastcall UFG::PhysicsMoverInterface::~PhysicsMoverInterface(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsMoverInterface *v1; // rbx
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v2; // rdi
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v3; // rcx
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v4; // rax
  UFG::PhysicsVehicle *v5; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v11; // rcx
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhysicsMoverInterface::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::PhysicsMoverInterface::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::PhysicsMoverInterface::s_PhysicsMoverInterfacepCurrentIterator )
    UFG::PhysicsMoverInterface::s_PhysicsMoverInterfacepCurrentIterator = (UFG::PhysicsMoverInterface *)&this->mPrev[-5].mNext;
  v2 = (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mPhysicsVehicle;
  if ( v5 )
    v5->vfptr->__vecDelDtor((UFG::BasePhysicsObject *)&v5->vfptr, 1u);
  UFG::VehicleParams::~VehicleParams(&v1->mParameters);
  `eh vector destructor iterator(
    v1->mTargetSpheres,
    0x40ui64,
    5,
    (void (__fastcall *)(void *))UFG::TargetSphere::~TargetSphere);
  v6 = &v1->mLastDamageSource;
  if ( v1->mLastDamageSource.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v1->mLastDamageSource.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v1->mLastDamageSource.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mLastDamageSource.mPrev;
  }
  v1->mLastDamageSource.m_pPointer = 0i64;
  v9 = v6->mPrev;
  v10 = v1->mLastDamageSource.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v1->mLastDamageSource.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mLastDamageSource.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mDriverComponent);
  v11 = v2->mPrev;
  v12 = v2->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 363
// RVA: 0x67CA90
void __fastcall UFG::PhysicsMoverInterface::HandleResourceLoadedEvent(UFG::PhysicsMoverInterface *this, UFG::ResourceRequest *request, bool loaded)
{
  UFG::PhysicsMoverInterface *v3; // rbx
  UFG::SimObjectCVBase *v4; // rcx
  UFG::PhysicsMoverInterface::ReloadReason v5; // edi
  UFG::HumanDriverComponent *v6; // rax

  if ( loaded )
  {
    v3 = this;
    if ( !this->mPhysicsVehicle )
    {
      v4 = (UFG::SimObjectCVBase *)this->m_pSimObject;
      v5 = 0;
      if ( v4 )
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(v4);
      else
        v6 = 0i64;
      LOBYTE(v5) = v6 != 0i64;
      UFG::PhysicsMoverInterface::Reload(v3, v5);
    }
  }
}

// File Line: 374
// RVA: 0x687750
void __fastcall UFG::PhysicsMoverInterface::PropertiesLoad(UFG::PhysicsMoverInterface *this, UFG::SceneObjectProperties *pSceneObj, component_PhysicsMover *dataPtr)
{
  component_PhysicsMover *v3; // rbx
  UFG::SceneObjectProperties *v4; // rsi
  UFG::PhysicsMoverInterface *v5; // rdi
  __int64 v6; // rax
  const char *v7; // r14
  UFG::qPropertySet *v8; // rcx
  bool *v9; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v15; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v16; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+38h] [rbp-28h]
  UFG::qSymbol defaultValue; // [rsp+90h] [rbp+30h]
  UFG::qSymbol result; // [rsp+98h] [rbp+38h]
  UFG::qSymbol *v20; // [rsp+A0h] [rbp+40h]

  v3 = dataPtr;
  v4 = pSceneObj;
  v5 = this;
  v6 = dataPtr->modelName.mOffset;
  if ( v6 )
    v7 = (char *)&dataPtr->modelName + v6;
  else
    v7 = 0i64;
  this->mPropertySetNameAI.mUID = dataPtr->physicsPropertySetAI.mUID;
  this->mPropertySetNameHuman.mUID = dataPtr->physicsPropertySetHuman.mUID;
  v20 = &defaultValue;
  defaultValue.mUID = UFG::gNullQSymbol.mUID;
  this->mPropertySetExplosion = (UFG::qSymbol)PropertyUtils::GetWithDefault<UFG::qSymbol>(
                                                &result,
                                                pSceneObj,
                                                (UFG::qSymbol *)&qSymbol_explosionPropertySet.mUID,
                                                (__int64)&defaultValue,
                                                DEPTH_RECURSE)->mUID;
  v8 = v4->mpWritableProperties;
  if ( !v8 )
    v8 = v4->mpConstProperties;
  v9 = PropertyUtils::Get<bool>(v8, (UFG::qSymbol *)&SimSym_UnlockVehicleDoors.mUID, DEPTH_RECURSE);
  if ( v9 )
    LOBYTE(v9) = *v9;
  v5->mDoorsLocked = (_BYTE)v9 == 0;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol.mUID = v3->TrunkType.mUID;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gVehicleTrunkTypeEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gVehicleTrunkTypeEnum, &pTrackEnumBinding);
  }
  else
  {
    v10 = UFG::gVehicleTrunkTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gVehicleTrunkTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v10;
    pTrackEnumBinding.mNext = &UFG::gVehicleTrunkTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gVehicleTrunkTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v5->mTrunkType = pTrackEnumBinding.m_EnumValue;
  v5->mDamageMultiplierWorldCollisions = v3->damageMultiplierWorldCollisions;
  v5->mDamageMultiplierVehicleCollisions = v3->damageMultiplierVehicleCollisions;
  v5->mDamageMultiplierBullets = v3->damageMultiplierBullets;
  v5->mDamageMultiplierTires = v3->damageMultiplierTires;
  v5->mVehicleCollisionMinImpulseRequiredToTakeDamage = v3->vehicleCollisionMinImpulseRequiredToTakeDamage;
  v5->mVehicleCollisionMinImpulseRequiredToDealDamage = v3->vehicleCollisionMinImpulseRequiredToDealDamage;
  v5->mVehicleCollisionDamageDealtAtMinImpulse = v3->vehicleCollisionDamageDealtAtMinImpulse;
  v5->mVehicleCollisionDamageDealtAtMaxImpulse = v3->vehicleCollisionDamageDealtAtMaxImpulse;
  v5->mVehicleCollisionMinRamImpulseRequiredToDealDamage = v3->vehicleCollisionMinRamImpulseRequiredToDealDamage;
  v5->mVehicleCollisionDamageDealtAtMinRamImpulse = v3->vehicleCollisionDamageDealtAtMinRamImpulse;
  v5->mVehicleCollisionDamageDealtAtMaxRamImpulse = v3->vehicleCollisionDamageDealtAtMaxRamImpulse;
  v5->mVehicleCollisionExtraDamageMultiplier = v3->vehicleCollisionExtraDamageMultiplier;
  v5->mVehicleCollisionMaxImpulseForDealingDamage = v3->vehicleCollisionMaxImpulseForDealingDamage;
  v5->mVehicleCollisionMaxRamImpulseForDealingDamage = v3->vehicleCollisionMaxRamImpulseForDealingDamage;
  *((_BYTE *)v5 + 900) ^= (*((_BYTE *)v5 + 900) ^ v3->vehicleCollisionForceDamageDealer) & 1;
  v5->mLowLodThrottleAcceleration = v3->lowLodThrottleAcceleration;
  v5->mLowLodBrakesAcceleration = v3->lowLodBrakesAcceleration;
  v5->mLowLodCoastAcceleration = v3->lowLodCoastAcceleration;
  v5->mLowLodMaxSpeed = v3->lowLodMaxSpeed;
  v5->mLowLodMaxLateralAcceleration = v3->lowLodMaxLateralAcceleration;
  v5->mLowLodMinTurningRadius = v3->lowLodMinTurningRadius;
  v11 = v3->boundingBoxMin.y;
  v12 = v3->boundingBoxMin.z;
  v5->mBoundingBoxMin.x = v3->boundingBoxMin.x;
  v5->mBoundingBoxMin.y = v11;
  v5->mBoundingBoxMin.z = v12;
  v13 = v3->boundingBoxMax.y;
  v14 = v3->boundingBoxMax.z;
  v5->mBoundingBoxMax.x = v3->boundingBoxMax.x;
  v5->mBoundingBoxMax.y = v13;
  v5->mBoundingBoxMax.z = v14;
  v5->mTireShotImpulse = v3->tireShotImpulse;
  v5->mTireBlownImpulse = v3->tireBlownImpulse;
  *((_DWORD *)v5 + 224) ^= (*((_DWORD *)v5 + 224) ^ v3->lockedAtLowLOD) & 1;
  v5->mAutoDeterioratingDamageThreshold = v3->autoDeterioratingDamageThreshold;
  v5->mAutoDeterioratingDamageRate = v3->autoDeterioratingDamageRate;
  v5->mDistanceToHighLod = v3->vehicleDistanceToHighLod;
  v5->mDistanceToMedLod = v3->vehicleDistanceToMedLod;
  UFG::VehicleParams::Init(&v5->mParameters, &v5->mPropertySetNameAI, v7);
  v15 = pTrackEnumBinding.mPrev;
  v16 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v16->mPrev = v15;
}

// File Line: 436
// RVA: 0x683040
void __fastcall UFG::PhysicsMoverInterface::OnAttach(UFG::PhysicsMoverInterface *this, UFG::SimObject *object)
{
  UFG::PhysicsMoverInterface *v2; // rdi
  UFG::SimObjectCVBase *v3; // rbx
  UFG::CharacterAnimationComponent *v4; // rax
  unsigned __int16 v5; // cx
  bool v6; // al
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)object;
  UFG::RebindingComponentHandle<UFG::VehicleDriverInterface,0>::Bind<UFG::SimObjectVehicle>(
    &this->mDriverComponent,
    (UFG::SimObjectVehicle *)object);
  v2->mGroundFixupRequired = 0;
  v2->mUntargetable = 0;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v3->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v3->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
  }
  else
  {
    v4 = 0i64;
  }
  v6 = v4->mTemporaryRig || !v4->mRigHandle.mData;
  v7 = &v2->mLastDamageSource;
  v2->mCreatedWithTemporaryRig = v6;
  if ( v2->mLastDamageSource.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v2->mLastDamageSource.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v2->mLastDamageSource.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mLastDamageSource.mPrev;
  }
  v2->mLastDamageSource.m_pPointer = 0i64;
}

// File Line: 457
// RVA: 0x684170
void __fastcall UFG::PhysicsMoverInterface::OnDetach(UFG::PhysicsMoverInterface *this)
{
  UFG::RebindingComponentHandle<UFG::VehicleDriverInterface,0> *v1; // r8
  UFG::PhysicsMoverInterface *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::PhysicsVehicle *v7; // rcx

  v1 = &this->mDriverComponent;
  v2 = this;
  if ( this->mDriverComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->mDriverComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->mDriverComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->mDriverComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleDriverInterface,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::VehicleDriverInterface,0> *)this->mDriverComponent.mNext != &this->mDriverComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v1->m_Changed = 1;
  UFG::PhysicsMoverInterface::DeactivateTargetSpheres(v2);
  v7 = v2->mPhysicsVehicle;
  if ( v7 )
    v7->vfptr->__vecDelDtor((UFG::BasePhysicsObject *)&v7->vfptr, 1u);
  v2->mPhysicsVehicle = 0i64;
}

// File Line: 475
// RVA: 0x689A00
void __fastcall UFG::PhysicsMoverInterface::Reset(UFG::PhysicsMoverInterface *this, __int64 options)
{
  UFG::PhysicsVehicle *v2; // rcx

  this->mGroundFixupRequired = 0;
  v2 = this->mPhysicsVehicle;
  if ( v2 )
    ((void (__fastcall *)(UFG::PhysicsVehicle *, __int64))v2->vfptr[1].DebugDraw)(v2, options);
}

// File Line: 487
// RVA: 0x68D050
void __fastcall UFG::PhysicsMoverInterface::Teleport(UFG::PhysicsMoverInterface *this, UFG::Event *this_event)
{
  UFG::SimObject *v2; // rax
  UFG::Event *v3; // rdi
  UFG::PhysicsMoverInterface *v4; // rbx
  UFG::TransformNodeComponent *v5; // rcx
  UFG::PhysicsVehicle *v6; // rcx

  v2 = this->m_pSimObject;
  v3 = this_event;
  v4 = this;
  if ( v2 )
  {
    v5 = (UFG::TransformNodeComponent *)v2->m_Components.p[2].m_pComponent;
    if ( v5 )
      UFG::TransformNodeComponent::SetWorldTransform(v5, (UFG::qMatrix44 *)&this_event[1].m_EventUID);
  }
  v6 = v4->mPhysicsVehicle;
  if ( v6 )
    v6->vfptr[3].ResourceUnloaded((UFG::BasePhysicsObject *)&v6->vfptr, (UFG::PhysicsResourceHandle *)&v3[1].m_EventUID);
}

// File Line: 505
// RVA: 0x67A640
UFG::qVector3 *__fastcall UFG::PhysicsMoverInterface::GetFacingDirection(UFG::PhysicsMoverInterface *this, UFG::qVector3 *result)
{
  UFG::SimObject *v2; // rax
  UFG::qVector3 *v3; // rdi
  UFG::TransformNodeComponent *v4; // rbx

  v2 = this->m_pSimObject;
  v3 = result;
  if ( v2 )
    v4 = (UFG::TransformNodeComponent *)v2->m_Components.p[2].m_pComponent;
  else
    v4 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  v3->x = v4->mWorldTransform.v0.x;
  v3->y = v4->mWorldTransform.v0.y;
  v3->z = v4->mWorldTransform.v0.z;
  return v3;
}

// File Line: 529
// RVA: 0x67A250
float __fastcall UFG::PhysicsMoverInterface::GetCurvatureLimit(UFG::PhysicsMoverInterface *this, float speed)
{
  float v2; // xmm3_4
  float v3; // xmm1_4
  float v4; // xmm6_4
  float v5; // xmm0_4

  v2 = *(float *)&FLOAT_1_0;
  v3 = speed * speed;
  v4 = 1.0 / (float)(this->mLowLodMinTurningRadius * 3.1415927);
  if ( v3 <= 1.0 )
  {
    if ( v3 <= 0.0 )
    {
      v3 = 0.0;
    }
    else if ( v3 >= 1.0 )
    {
      goto LABEL_7;
    }
    v2 = v3;
LABEL_7:
    v5 = sinf(v2 * 1.5707964);
    return (float)(v5 * v5) * v4;
  }
  if ( v4 >= (float)((float)(this->mLowLodMaxLateralAcceleration * 9.8000002) / v3) )
    v4 = (float)(this->mLowLodMaxLateralAcceleration * 9.8000002) / v3;
  return v4;
}

// File Line: 541
// RVA: 0x67E430
void __fastcall UFG::PhysicsMoverInterface::InitializeDestructCountdown(UFG::PhysicsMoverInterface *this)
{
  UFG::SimObject *v1; // rax
  UFG::PhysicsMoverInterface *v2; // rbx
  UFG::SimObject *v3; // rcx

  v1 = this->m_pSimObject;
  v2 = this;
  if ( v1 )
    v1 = (UFG::SimObject *)v1->m_Components.p[30].m_pComponent;
  v3 = (UFG::SimObject *)v1->m_Components.p;
  if ( v3 && UFG::IsAnyLocalPlayer(v3) )
  {
    v2->mDestructTimerInitial = 3.0;
    v2->mDestructTimer = 3.0;
  }
  else
  {
    v2->mDestructTimerInitial = UFG::PhysicsMoverInterface::sVehicleDestructCountdown;
    v2->mDestructTimer = UFG::PhysicsMoverInterface::sVehicleDestructCountdown;
  }
}

// File Line: 559
// RVA: 0x696D70
void __fastcall UFG::PhysicsMoverInterface::UpdateEngineDamage(UFG::PhysicsMoverInterface *this, float deltaTime)
{
  float v2; // xmm0_4
  UFG::PhysicsMoverInterface *v3; // rbx
  float v4; // xmm6_4
  float v5; // xmm0_4
  UFG::PhysicsMoverInterface::DestructState v6; // ecx
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  UFG::SimObject *v10; // rcx

  v2 = this->mDamageState.engineDamage;
  v3 = this;
  v4 = deltaTime;
  if ( v2 < this->mAutoDeterioratingDamageThreshold || v2 >= 1.0 )
  {
    this->mSecondsEngineHasBeenDeteriorating = -1.0;
  }
  else
  {
    v5 = this->mSecondsEngineHasBeenDeteriorating;
    if ( v5 == -1.0 )
    {
      this->mSecondsEngineHasBeenDeteriorating = deltaTime;
      UFG::PhysicsMoverInterface_EmitVehicleDisabledEvent(this->m_pSimObject);
    }
    else
    {
      this->mSecondsEngineHasBeenDeteriorating = v5 + deltaTime;
    }
  }
  v6 = v3->mDestructState;
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      v7 = v3->mDestructTimer - deltaTime;
      v3->mDestructTimer = v7;
      v8 = 1.0 - (float)(v7 / v3->mDestructTimerInitial);
      if ( v8 >= 1.0 )
        v8 = *(float *)&FLOAT_1_0;
      v3->mDestructPercentage = v8;
      if ( v7 < 0.0 )
        UFG::PhysicsMoverInterface::TriggerExplosion(v3);
    }
  }
  else
  {
    v9 = v3->mDamageState.engineDamage;
    if ( v9 < 1.0 )
    {
      if ( v3->mSecondsEngineHasBeenDeteriorating >= 0.0 )
      {
        UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(v3, (float)(v4 * v3->mAutoDeterioratingDamageRate) + v9);
        *((_BYTE *)v3 + 0x384) |= 0x20u;
      }
    }
    else
    {
      if ( *((_BYTE *)v3 + 896) & 0x10 )
      {
        v10 = v3->m_pSimObject;
        v3->mDestructState = 2;
      }
      else
      {
        UFG::PhysicsMoverInterface::InitializeDestructCountdown(v3);
        v10 = v3->m_pSimObject;
        v3->mDestructState = 1;
      }
      UFG::PhysicsMoverInterface_EmitVehicleDisabledEvent(v10);
    }
  }
}

// File Line: 670
// RVA: 0x695AE0
void UFG::PhysicsMoverInterface::UpdateDetailSettings(void)
{
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-78h]

  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  if ( (unsigned int)(outSettings.mLODSetting - 2) > 1 )
    UFG::PhysicsMoverInterface::mLodDistanceMultiplier = FLOAT_1_5;
  else
    UFG::PhysicsMoverInterface::mLodDistanceMultiplier = FLOAT_2_0;
}

// File Line: 692
// RVA: 0x691D60
void __fastcall UFG::PhysicsMoverInterface::Update(UFG::PhysicsMoverInterface *this, float deltaTime)
{
  float v2; // xmm9_4
  UFG::PhysicsMoverInterface *v3; // rdi
  UFG::SimObject *v4; // rcx
  bool v5; // dl
  int v6; // eax
  UFG::SimObject *v7; // rax
  hkpEntity *v8; // rcx
  float v9; // xmm0_4
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  __int128 v16; // xmm1
  UFG::SimObject *v17; // r15
  int v18; // ebx
  float *v19; // rsi
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v20; // rcx
  bool v21; // r12
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v22; // rcx
  char v23; // al
  __int64 v24; // rax
  char v25; // r15
  __int64 v26; // rax
  UFG::TransformNodeComponent *v27; // rsi
  unsigned int v28; // eax
  char v29; // al
  float v30; // ecx
  int v31; // ebx
  float v32; // xmm6_4
  float v33; // xmm7_4
  float v34; // xmm10_4
  UFG::TransformNodeComponent *v35; // rbx
  UFG::BaseCameraComponent *v36; // rbx
  float *v37; // rbx
  float v38; // xmm2_4
  int v39; // er12
  UFG::SimObject *v40; // rax
  hkpEntity *v41; // rcx
  UFG::SimObject *v42; // rcx
  UFG::SimObject *v43; // rcx
  UFG::SimObject *v44; // rax
  UFG::PhysicsVehicle *v45; // rcx
  UFG::PhysicsVehicle::Lod v46; // eax
  float v47; // xmm7_4
  float v48; // xmm6_4
  float v49; // xmm8_4
  bool v50; // r12
  __int64 v51; // rax
  __int64 v52; // rbx
  bool v53; // bl
  float *v54; // rax
  float v55; // xmm14_4
  float v56; // xmm15_4
  float v57; // xmm3_4
  float v58; // xmm4_4
  float v59; // xmm0_4
  float v60; // xmm13_4
  float v61; // xmm10_4
  float v62; // xmm11_4
  float v63; // xmm6_4
  UFG::SimObject *v64; // rcx
  float v65; // xmm2_4
  float v66; // xmm11_4
  float v67; // xmm6_4
  float v68; // xmm7_4
  float v69; // xmm0_4
  float v70; // xmm10_4
  float v71; // xmm11_4
  float v72; // xmm6_4
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm2_4
  float v76; // xmm10_4
  float v77; // xmm11_4
  float v78; // xmm6_4
  float v79; // xmm0_4
  float v80; // xmm5_4
  float v81; // xmm10_4
  float v82; // xmm11_4
  float v83; // xmm6_4
  float v84; // xmm7_4
  float v85; // xmm15_4
  float v86; // xmm7_4
  float v87; // xmm3_4
  float v88; // xmm13_4
  float v89; // xmm6_4
  float v90; // xmm10_4
  float v91; // xmm2_4
  float v92; // xmm1_4
  float v93; // xmm2_4
  __m128 v94; // xmm11
  float v95; // xmm6_4
  __m128 v96; // xmm3
  float v97; // xmm1_4
  float v98; // xmm0_4
  float v99; // xmm13_4
  float v100; // xmm4_4
  float v101; // xmm5_4
  float v102; // xmm3_4
  float v103; // xmm2_4
  float v104; // xmm12_4
  float v105; // xmm4_4
  float v106; // xmm5_4
  float v107; // xmm3_4
  UFG::SimObject *v108; // rcx
  float v109; // xmm6_4
  float v110; // xmm6_4
  float v111; // xmm14_4
  float v112; // xmm6_4
  bool v113; // si
  UFG::RoadNetworkLocation *v114; // rbx
  __m128 v115; // xmm1
  __m128 v116; // xmm10
  __m128 v117; // xmm2
  float v118; // xmm1_4
  float v119; // xmm11_4
  float v120; // xmm0_4
  float v121; // xmm1_4
  float v122; // xmm0_4
  float v123; // xmm4_4
  __int128 v124; // xmm7
  __m128 v125; // xmm5
  float v126; // xmm3_4
  float v127; // xmm0_4
  float v128; // xmm2_4
  float v129; // xmm3_4
  __m128 v130; // xmm2
  float v131; // xmm1_4
  __int128 v132; // xmm10
  float v133; // xmm12_4
  float v134; // xmm3_4
  float v135; // xmm11_4
  __m128 v136; // xmm1
  float v137; // xmm2_4
  float v138; // xmm1_4
  float v139; // xmm11_4
  float v140; // xmm2_4
  float v141; // xmm13_4
  float v142; // xmm14_4
  float v143; // xmm15_4
  float v144; // xmm11_4
  float v145; // xmm6_4
  UFG::SimObject *v146; // rax
  UFG::SimObject *v147; // rcx
  float v148; // xmm1_4
  UFG::qMatrix44 localWorld; // [rsp+20h] [rbp-A0h]
  float top_speed; // [rsp+60h] [rbp-60h]
  float v151; // [rsp+64h] [rbp-5Ch]
  float v152; // [rsp+68h] [rbp-58h]
  UFG::qVector3 v153; // [rsp+70h] [rbp-50h]
  float v154; // [rsp+80h] [rbp-40h]
  float v155; // [rsp+84h] [rbp-3Ch]
  float v156; // [rsp+88h] [rbp-38h]
  float v157; // [rsp+90h] [rbp-30h]
  float v158; // [rsp+94h] [rbp-2Ch]
  float v159; // [rsp+98h] [rbp-28h]
  __int64 v160; // [rsp+B0h] [rbp-10h]
  UFG::qNode<UFG::qString,UFG::qString> *v161; // [rsp+1B0h] [rbp+F0h]
  hkBool result[4]; // [rsp+1B8h] [rbp+F8h]
  hkBool v163[4]; // [rsp+1C0h] [rbp+100h]
  float v164; // [rsp+1C8h] [rbp+108h]

  v160 = -2i64;
  v2 = deltaTime;
  v3 = this;
  if ( !this->mPrev )
  {
    *(_QWORD *)&this->m_TypeUID = 0i64;
    *(_QWORD *)&this->m_Flags = 0i64;
    LODWORD(this->m_pSimObject) &= 0xFFFFF9C0;
    LODWORD(this->m_pSimObject) |= 6u;
    v4 = this->mParameters.mSimObject.m_pPointer;
    if ( v4 )
    {
      if ( *(float *)&v4[4].m_Flags > 20.0 )
        LODWORD(v3->m_pSimObject) &= 0xFFFFFFF9;
    }
  }
  if ( v3->mParameters.mSimObject.m_pPointer )
  {
    v5 = !v3->mPrev
      || !UFG::SimComponent::IsType(
            (UFG::SimComponent *)v3->mPrev,
            UFG::HumanDriverComponent::_HumanDriverComponentTypeUID);
    UFG::PhysicsVehicle::SetControlledByAi((UFG::PhysicsVehicle *)v3->mParameters.mSimObject.m_pPointer, v5);
  }
  v6 = (int)v3->m_pSimObject;
  if ( v6 & 0x40 )
    LODWORD(v3->m_pSimObject) = v6 | 6;
  if ( LODWORD(v3->mNotMovingTime) == 2 )
  {
    v7 = v3->mParameters.mSimObject.m_pPointer;
    if ( !v7
      || (v8 = *(hkpEntity **)(*(_QWORD *)&v7->m_Components.size + 168i64)) == 0i64
      || !hkpEntity::isActive(v8, result)->m_bool )
    {
      *(_QWORD *)&v3->mNotMovingTime = 3i64;
    }
  }
  if ( LODWORD(v3->mNotMovingTime) == 1 )
  {
    v9 = v3->mPropellerAngle - deltaTime;
    v3->mPropellerAngle = v9;
    if ( v9 <= 0.0 )
      *(_QWORD *)&v3->mNotMovingTime = 3i64;
  }
  *(float *)&v3->mMotorBoneId.array[1] = deltaTime + *(float *)&v3->mMotorBoneId.array[1];
  v10 = v3->mParameters.modelName.mPrev;
  if ( v10
    && UFG::RammingState::Update((UFG::RammingState *)v10, (UFG::PhysicsMoverInterface *)((char *)v3 - 64), deltaTime) )
  {
    v11 = v3->mParameters.modelName.mPrev;
    v161 = v11;
    if ( v11 )
    {
      v161 = v11;
      if ( v11[1].mPrev )
      {
        v12 = v11->mPrev;
        v13 = v11->mNext;
        v12->mNext = v13;
        v13->mPrev = v12;
        v11->mPrev = v11;
        v11->mNext = v11;
      }
      v11[1].mPrev = 0i64;
      v14 = v11->mPrev;
      v15 = v11->mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      v11->mPrev = v11;
      v11->mNext = v11;
      operator delete[](v11);
    }
    v3->mParameters.modelName.mPrev = 0i64;
  }
  *(float *)&v3->mParameters.modelName.mNext = *(float *)&v3->mParameters.modelName.mNext - deltaTime;
  if ( v3->mParameters.mSimObject.m_pPointer )
  {
    if ( LOBYTE(v3->mVehicleCollisionMinImpulseRequiredToTakeDamage) & 2
      && ((unsigned int)UFG::VehicleUtility::GetVehicleOrientation(*((UFG::SimObjectVehicle **)&v3[-1] + 112), 0, 0i64) != 5
       || *(float *)&v3->mParameters.mSimObject.m_pPointer[4].m_Flags < 0.1) )
    {
      LOBYTE(v3->mVehicleCollisionMinImpulseRequiredToTakeDamage) &= 0xFDu;
    }
    UFG::PhysicsMoverInterface::UpdateEngineDamage((UFG::PhysicsMoverInterface *)((char *)v3 - 64), deltaTime);
    v16 = LODWORD(v3->mDriverComponent.mPrev);
    ((void (*)(void))v3->mParameters.mSimObject.m_pPointer->vfptr[12].__vecDelDtor)();
    v17 = 0i64;
    if ( BYTE4(v3->mParameters.mSimObject.m_pPointer[4].m_pTransformNodeComponent) & 7 )
      v17 = v3->mParameters.mSimObject.m_pPointer;
    if ( v17 )
    {
      v18 = 0;
      if ( SLODWORD(v3->mAutoDeterioratingDamageRate) > 0 )
      {
        v19 = &v3->mInput.mGasBrakes;
        do
        {
          UFG::PhysicsWheeledVehicle::SetTireDamage((UFG::PhysicsWheeledVehicle *)v17, v18++, *v19);
          ++v19;
        }
        while ( v18 < SLODWORD(v3->mAutoDeterioratingDamageRate) );
      }
    }
    v20 = v3->mPrev;
    v21 = v20 && ((unsigned __int8 (*)(void))v20->mPrev[7].mNext)();
    v22 = v3->mPrev;
    if ( !v22 || (v23 = ((__int64 (*)(void))v22->mPrev[8].mPrev)(), result[0].m_bool = 0, v23) )
      result[0].m_bool = 1;
    v24 = *((_QWORD *)&v3[-1] + 112);
    if ( v24 )
      v25 = (*(_WORD *)(v24 + 76) >> 11) & 1;
    else
      v25 = 0;
    *(float *)&v163[0].m_bool = *((float *)&v3->mParameters.mSimObject.m_pPointer[4].m_SafePointerWithCallbackList.mNode.mNext
                                + 1);
    v26 = *((_QWORD *)&v3[-1] + 112);
    if ( v26 )
      v27 = *(UFG::TransformNodeComponent **)(*(_QWORD *)(v26 + 104) + 32i64);
    else
      v27 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v27);
    v28 = UFG::SectionChooser::GetVisIndexAtPosition((UFG::qVector3 *)&v27->mWorldTransform.v3, 0);
    v29 = UFG::SectionChooser::IsSectionVisible_VisIndex(v28, SCENERY_LAYER_STD, 0);
    LOBYTE(v161) = v29;
    if ( !v29 )
      v3->mDamageMultiplierAttack = 0.0;
    v30 = v3->mLockAtHighLODTime;
    if ( LOBYTE(v30) & 8 )
    {
      v31 = 4;
LABEL_92:
      v39 = *(_DWORD *)&v163[0].m_bool;
      goto LABEL_93;
    }
    if ( !(LOBYTE(v30) & 1) )
    {
      if ( v25 )
      {
        v31 = 3;
        LOBYTE(v3->mParameters.mSimObject.m_pPointer[4].mNode.mParent) = v25;
        goto LABEL_92;
      }
      if ( v21 )
      {
        v31 = 3;
        goto LABEL_92;
      }
      if ( v29 )
      {
        if ( result[0].m_bool && LODWORD(v3->mNotMovingTime) == 3 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v27);
          v32 = v27->mWorldTransform.v3.x;
          v33 = v27->mWorldTransform.v3.y;
          v34 = v27->mWorldTransform.v3.z;
          if ( LocalPlayer )
          {
            v35 = LocalPlayer->m_pTransformNodeComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
          }
          else
          {
            v36 = UFG::Director::Get()->mCurrentCamera;
            if ( v36 )
              v35 = (UFG::TransformNodeComponent *)&v36->mCamera;
            else
              v35 = 0i64;
          }
          v37 = &v35->mWorldTransform.v3.x;
          v38 = (float)((float)((float)(v37[1] - v33) * (float)(v37[1] - v33))
                      + (float)((float)(*v37 - v32) * (float)(*v37 - v32)))
              + (float)((float)(v37[2] - v34) * (float)(v37[2] - v34));
          if ( v38 >= (float)((float)(UFG::PhysicsMoverInterface::mLodDistanceMultiplier
                                    * v3->mVehicleCollisionDamageDealtAtMinImpulse)
                            * (float)(UFG::PhysicsMoverInterface::mLodDistanceMultiplier
                                    * v3->mVehicleCollisionDamageDealtAtMinImpulse)) )
            v31 = ((float)((float)(UFG::PhysicsMoverInterface::mLodDistanceMultiplier
                                 * v3->mVehicleCollisionDamageDealtAtMaxImpulse)
                         * (float)(UFG::PhysicsMoverInterface::mLodDistanceMultiplier
                                 * v3->mVehicleCollisionDamageDealtAtMaxImpulse)) > v38)
                + 1;
          else
            v31 = 3;
          v39 = *(_DWORD *)&v163[0].m_bool;
          if ( *(_DWORD *)&v163[0].m_bool == 3 && v31 != *(_DWORD *)&v163[0].m_bool )
          {
            if ( !UFG::PhysicsMoverInterface::AreAllWheelsOnGround((UFG::PhysicsMoverInterface *)((char *)v3 - 64)) )
              v31 = v39;
            v40 = v3->mParameters.mSimObject.m_pPointer;
            if ( v40 )
            {
              v41 = *(hkpEntity **)(*(_QWORD *)&v40->m_Components.size + 168i64);
              if ( v41 )
              {
                if ( hkpEntity::isActive(v41, v163)->m_bool )
                  v31 = v39;
              }
            }
            v42 = v3->mParameters.mSimObject.m_pPointer;
            if ( v42
              && (HIDWORD(v42[4].m_pTransformNodeComponent) & 7) == 4
              && UFG::PhysicsCar::HasActiveAttachments((UFG::PhysicsCar *)v42) )
            {
              v31 = 3;
            }
          }
        }
        else
        {
          v31 = 3;
          v43 = v3->mParameters.mSimObject.m_pPointer;
          if ( !v43 )
            goto LABEL_92;
          v44 = 0i64;
          if ( BYTE4(v43[4].m_pTransformNodeComponent) & 7 )
            v44 = v3->mParameters.mSimObject.m_pPointer;
          if ( !v44 )
            goto LABEL_92;
          v39 = *(_DWORD *)&v163[0].m_bool;
          if ( SLODWORD(v3->mDamageMultiplierAttack) <= 0 && *(_DWORD *)&v163[0].m_bool != 3 )
            LODWORD(v3->mDamageMultiplierAttack) = 1;
        }
LABEL_93:
        if ( SLODWORD(v3->mDamageMultiplierAttack) > 0 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v27);
          localWorld.v0.x = v27->mWorldTransform.v0.x;
          localWorld.v0.y = v27->mWorldTransform.v0.y;
          localWorld.v0.z = v27->mWorldTransform.v0.z;
          localWorld.v0.w = v27->mWorldTransform.v0.w;
          localWorld.v1.x = v27->mWorldTransform.v1.x;
          localWorld.v1.y = v27->mWorldTransform.v1.y;
          localWorld.v1.z = v27->mWorldTransform.v1.z;
          localWorld.v1.w = v27->mWorldTransform.v1.w;
          localWorld.v2.x = v27->mWorldTransform.v2.x;
          localWorld.v2.y = v27->mWorldTransform.v2.y;
          localWorld.v2.z = v27->mWorldTransform.v2.z;
          localWorld.v2.w = v27->mWorldTransform.v2.w;
          localWorld.v3.x = v27->mWorldTransform.v3.x;
          localWorld.v3.y = v27->mWorldTransform.v3.y;
          localWorld.v3.z = v27->mWorldTransform.v3.z;
          localWorld.v3.w = v27->mWorldTransform.v3.w;
          if ( !(unsigned __int8)UFG::PhysicsVehicle::FixupTransformForGround(
                                   (UFG::PhysicsVehicle *)v3->mParameters.mSimObject.m_pPointer,
                                   &localWorld) )
          {
            if ( ++LODWORD(v3->mDamageMultiplierAttack) <= 3 )
              goto LABEL_102;
            if ( v3->mPrev )
              ((void (__fastcall *)(UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *, UFG::qMatrix44 *))v3->mPrev->mPrev[8].mNext)(
                v3->mPrev,
                &localWorld);
            v31 = 1;
          }
          v3->mDamageMultiplierAttack = 0.0;
        }
        if ( v31 != v39 )
          UFG::PhysicsMoverInterface::SetLOD(
            (UFG::PhysicsMoverInterface *)((char *)v3 - 64),
            (UFG::PhysicsVehicle::Lod)v31);
LABEL_102:
        UFG::PhysicsVehicle::UpdateLevelOfDetail((UFG::PhysicsVehicle *)v3->mParameters.mSimObject.m_pPointer);
        v45 = (UFG::PhysicsVehicle *)v3->mParameters.mSimObject.m_pPointer;
        v46 = v45->mCurrentLod;
        if ( (signed int)v46 <= 0 )
        {
LABEL_204:
          v148 = *(float *)&v3->mParameters.modelName.mStringHashUpper32;
          *(float *)&v3->mParameters.firstFrontWheel = (float)(*(float *)&v3->mParameters.modelName.mStringHashUpper32
                                                             * v2)
                                                     + *(float *)&v3->mParameters.firstFrontWheel;
          if ( v148 >= kfNotMovingSpeed )
            v3->mDamageMultiplierWorldCollisions = 0.0;
          else
            v3->mDamageMultiplierWorldCollisions = v2 + v3->mDamageMultiplierWorldCollisions;
          LODWORD(v3->mLockAtHighLODTime) &= 0xFFFFFFFB;
          LODWORD(v3->mLockAtHighLODTime) |= 4 * (kfNotMovingTimeThreshold < v3->mDamageMultiplierWorldCollisions);
          return;
        }
        if ( v46 > LOD_SETTING_HIGH )
        {
          if ( v46 == LOD_SETTING_EXTREME )
          {
            ((void (__fastcall *)(UFG::PhysicsVehicle *, _QWORD, unsigned int *))v45->vfptr[1].ResourceUnloaded)(
              v45,
              0i64,
              &v3->m_TypeUID);
            UFG::TransformNodeComponent::UpdateWorldTransform(v27);
            v47 = v27->mWorldTransform.v0.x;
            v48 = v27->mWorldTransform.v0.y;
            v49 = v27->mWorldTransform.v0.z;
            UFG::PhysicsVehicle::GetVelocity((UFG::PhysicsVehicle *)v3->mParameters.mSimObject.m_pPointer, &v153);
            *(float *)&v3->mParameters.modelName.mStringHashUpper32 = (float)((float)(v153.y * v48)
                                                                            + (float)(v153.x * v47))
                                                                    + (float)(v153.z * v49);
          }
          else if ( v46 == NUM_LOD_SETTING )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v27);
            localWorld.v0.x = v27->mWorldTransform.v0.x;
            localWorld.v0.y = v27->mWorldTransform.v0.y;
            localWorld.v0.z = v27->mWorldTransform.v0.z;
            localWorld.v0.w = v27->mWorldTransform.v0.w;
            localWorld.v1.x = v27->mWorldTransform.v1.x;
            localWorld.v1.y = v27->mWorldTransform.v1.y;
            localWorld.v1.z = v27->mWorldTransform.v1.z;
            localWorld.v1.w = v27->mWorldTransform.v1.w;
            localWorld.v2.x = v27->mWorldTransform.v2.x;
            localWorld.v2.y = v27->mWorldTransform.v2.y;
            localWorld.v2.z = v27->mWorldTransform.v2.z;
            localWorld.v2.w = v27->mWorldTransform.v2.w;
            localWorld.v3.x = v27->mWorldTransform.v3.x;
            localWorld.v3.y = v27->mWorldTransform.v3.y;
            localWorld.v3.z = v27->mWorldTransform.v3.z;
            localWorld.v3.w = v27->mWorldTransform.v3.w;
            ((void (__fastcall *)(UFG::SimObject *, UFG::qMatrix44 *, unsigned int *))v3->mParameters.mSimObject.m_pPointer->vfptr[5].__vecDelDtor)(
              v3->mParameters.mSimObject.m_pPointer,
              &localWorld,
              &v3->m_TypeUID);
          }
          goto LABEL_204;
        }
        UFG::TransformNodeComponent::UpdateWorldTransform(v27);
        localWorld.v0.x = v27->mWorldTransform.v0.x;
        localWorld.v0.y = v27->mWorldTransform.v0.y;
        localWorld.v0.z = v27->mWorldTransform.v0.z;
        localWorld.v0.w = v27->mWorldTransform.v0.w;
        localWorld.v1.x = v27->mWorldTransform.v1.x;
        localWorld.v1.y = v27->mWorldTransform.v1.y;
        localWorld.v1.z = v27->mWorldTransform.v1.z;
        localWorld.v1.w = v27->mWorldTransform.v1.w;
        localWorld.v2.x = v27->mWorldTransform.v2.x;
        localWorld.v2.y = v27->mWorldTransform.v2.y;
        localWorld.v2.z = v27->mWorldTransform.v2.z;
        localWorld.v2.w = v27->mWorldTransform.v2.w;
        localWorld.v3.x = v27->mWorldTransform.v3.x;
        localWorld.v3.y = v27->mWorldTransform.v3.y;
        localWorld.v3.z = v27->mWorldTransform.v3.z;
        localWorld.v3.w = v27->mWorldTransform.v3.w;
        v50 = 0;
        v51 = *((_QWORD *)&v3[-1] + 112);
        if ( v51 )
          v52 = *(_QWORD *)(*(_QWORD *)(v51 + 104) + 384i64);
        else
          v52 = 0i64;
        if ( v3->mPrev && ((unsigned __int8 (*)(void))v3->mPrev->mPrev[7].mPrev)() && !v25 )
        {
          v50 = 1;
          v53 = 1.0 <= *(float *)&v3->mDriverComponent.mPrev;
          v54 = (float *)v3->mPrev;
          if ( result[0].m_bool )
            top_speed = v3->mBoundingBoxMax.x;
          else
            top_speed = UFG::AiDriverComponent::m_TopSpeed;
          v55 = v54[263];
          v56 = localWorld.v0.x;
          localWorld.v2.y = localWorld.v0.x;
          v57 = localWorld.v0.y;
          *(float *)&result[0].m_bool = localWorld.v0.y;
          v58 = localWorld.v0.z;
          *(float *)&v163[0].m_bool = localWorld.v0.z;
          v164 = localWorld.v3.x;
          v59 = localWorld.v3.y;
          v151 = localWorld.v3.y;
          v152 = localWorld.v3.z;
          v60 = v2 * *(float *)&v3->mParameters.modelName.mStringHashUpper32;
          v61 = v54[267];
          v62 = v54[268];
          v63 = v54[269];
          if ( v53 )
          {
            v64 = v3->mParameters.mSimObject.m_pPointer;
            if ( v64 )
            {
              ((void (*)(void))v64->vfptr[15].__vecDelDtor)();
              v65 = v59;
            }
            else
            {
              v65 = FLOAT_0_78539819;
            }
            v66 = localWorld.v3.x;
            v67 = (float)(*(float *)&v3->m_TypeUID * 0.5) * v65;
            v68 = cosf(v67);
            v69 = sinf(v67);
            v70 = (float)((float)((float)(v69 * localWorld.v1.x) + (float)(v68 * localWorld.v0.x))
                        + (float)(localWorld.v2.x * 0.0))
                + (float)(v66 * 0.0);
            v71 = (float)((float)((float)(v69 * localWorld.v1.y) + (float)(v68 * localWorld.v0.y))
                        + (float)(localWorld.v2.y * 0.0))
                + (float)(localWorld.v3.y * 0.0);
            v72 = (float)((float)((float)(v69 * localWorld.v1.z) + (float)(v68 * localWorld.v0.z))
                        + (float)(localWorld.v2.z * 0.0))
                + (float)(localWorld.v3.z * 0.0);
            v73 = v164;
            v61 = v70 + v164;
            v74 = v151;
            v62 = v71 + v151;
            v75 = v152;
            v63 = v72 + v152;
            v57 = *(float *)&result[0].m_bool;
            v58 = *(float *)&v163[0].m_bool;
          }
          else
          {
            v73 = v164;
            v74 = v151;
            v75 = v152;
          }
          v76 = v61 - v73;
          v77 = v62 - v74;
          v78 = v63 - v75;
          v79 = v76 * v76;
          v80 = fsqrt((float)((float)(v77 * v77) + (float)(v76 * v76)) + (float)(v78 * v78));
          if ( v80 <= 0.050000001 )
          {
LABEL_152:
            v108 = v3->mParameters.mSimObject.m_pPointer;
            if ( (HIDWORD(v108[4].m_pTransformNodeComponent) >> 3) & 1 )
            {
              v109 = *(float *)&v108[4].mNode.mUID;
              UFG::PhysicsVehicle::GetMass((UFG::PhysicsVehicle *)v108);
              LODWORD(v110) = COERCE_UNSIGNED_INT(v109 / v79) ^ _xmm[0];
            }
            else
            {
              v110 = v2 * v3->mBoundingBoxMin.y;
              if ( v53 )
              {
                v110 = v110 * 0.5;
              }
              else
              {
                v111 = v55 - *(float *)&v3->mParameters.modelName.mStringHashUpper32;
                if ( v111 > v110 )
                  v110 = v111;
                if ( v110 >= (float)(v2 * v3->mBoundingBoxMin.x) )
                  v110 = v2 * v3->mBoundingBoxMin.x;
              }
            }
            v112 = v110 + *(float *)&v3->mParameters.modelName.mStringHashUpper32;
            if ( v112 <= 0.0 )
              v112 = 0.0;
            if ( v112 >= top_speed )
              v112 = top_speed;
            *(float *)&v3->mParameters.modelName.mStringHashUpper32 = v112;
            goto LABEL_197;
          }
          localWorld.v2.x = 1.0 / v80;
          v81 = v76 * (float)(1.0 / v80);
          v82 = v77 * (float)(1.0 / v80);
          v83 = v78 * (float)(1.0 / v80);
          v84 = (float)((float)(v82 * v57) + (float)(v81 * v56)) + (float)(v83 * v58);
          if ( (LODWORD(v3->m_pSimObject) >> 5) & 1 )
            v85 = v2 * 6.2831855;
          else
            v85 = UFG::PhysicsMoverInterface::GetCurvatureLimit(
                    (UFG::PhysicsMoverInterface *)((char *)v3 - 64),
                    *(float *)&v3->mParameters.modelName.mStringHashUpper32)
                * v60;
          if ( v84 <= -1.0 )
          {
            v84 = FLOAT_N1_0;
          }
          else if ( v84 >= 1.0 )
          {
            v84 = *(float *)&FLOAT_1_0;
            goto LABEL_132;
          }
          if ( v84 <= -1.0 )
          {
            v84 = FLOAT_N1_0;
LABEL_135:
            LODWORD(v86) = COERCE_UNSIGNED_INT(acosf(v84)) & _xmm;
            if ( v86 > v85 )
            {
              v87 = (float)(v82 * *(float *)&v163[0].m_bool) - (float)(v83 * *(float *)&result[0].m_bool);
              v88 = localWorld.v2.y;
              v89 = (float)(v83 * localWorld.v2.y) - (float)(v81 * *(float *)&v163[0].m_bool);
              v90 = (float)(v81 * *(float *)&result[0].m_bool) - (float)(v82 * localWorld.v2.y);
              v91 = (float)((float)(v89 * v89) + (float)(v87 * v87)) + (float)(v90 * v90);
              if ( v91 == 0.0 )
                v92 = 0.0;
              else
                v92 = 1.0 / fsqrt(v91);
              localWorld.v2.z = v87 * v92;
              localWorld.v2.w = v89 * v92;
              localWorld.v3.x = v90 * v92;
              UFG::qRotationMatrixAxis((UFG::qMatrix44 *)&v153, (UFG::qVector3 *)&localWorld.v2.z, v85);
              v93 = (float)((float)(v154 * *(float *)&result[0].m_bool) + (float)(v153.x * v88))
                  + (float)(v157 * *(float *)&v163[0].m_bool);
              v94 = (__m128)LODWORD(v155);
              v94.m128_f32[0] = (float)((float)(v155 * *(float *)&result[0].m_bool) + (float)(v153.y * v88))
                              + (float)(v158 * *(float *)&v163[0].m_bool);
              v95 = (float)((float)(v156 * *(float *)&result[0].m_bool) + (float)(v153.z * v88))
                  + (float)(v159 * *(float *)&v163[0].m_bool);
              v96 = v94;
              v96.m128_f32[0] = (float)((float)(v94.m128_f32[0] * v94.m128_f32[0]) + (float)(v93 * v93))
                              + (float)(v95 * v95);
              if ( v96.m128_f32[0] == 0.0 )
                v97 = 0.0;
              else
                v97 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v96));
              v81 = v97 * v93;
              v82 = v94.m128_f32[0] * v97;
              v83 = v95 * v97;
              v98 = UFG::GetSpeedLimitForCurvature(localWorld.v2.x * v86, top_speed, v3->mBoundingBoxMax.y);
              if ( v55 >= v98 )
                v55 = v98;
              v99 = *(float *)&v3->mParameters.modelName.mStringHashUpper32;
              if ( v55 < v99 )
                v99 = v55;
              v60 = v99 * v2;
            }
            v100 = (float)(v83 * 0.0) - v82;
            v101 = v81 - (float)(v83 * 0.0);
            v102 = (float)(v82 * 0.0) - (float)(v81 * 0.0);
            v103 = (float)((float)(v101 * v101) + (float)(v100 * v100)) + (float)(v102 * v102);
            if ( v103 == 0.0 )
              v104 = 0.0;
            else
              v104 = 1.0 / fsqrt(v103);
            v105 = v100 * v104;
            v106 = v101 * v104;
            v107 = v102 * v104;
            v79 = v105 * v82;
            if ( v60 > 0.0049999999 )
            {
              v79 = v151 + (float)(v82 * v60);
              localWorld.v3.x = v164 + (float)(v81 * v60);
              localWorld.v3.y = v151 + (float)(v82 * v60);
              localWorld.v3.z = v152 + (float)(v83 * v60);
              localWorld.v3.w = 1.0;
              localWorld.v0.x = v81;
              localWorld.v0.y = v82;
              localWorld.v0.z = v83;
              localWorld.v0.w = 0.0;
              localWorld.v1.x = v105;
              localWorld.v1.y = v106;
              localWorld.v1.z = v107;
              localWorld.v1.w = 0.0;
              localWorld.v2.x = (float)(v107 * v82) - (float)(v106 * v83);
              localWorld.v2.y = (float)(v105 * v83) - (float)(v107 * v81);
              localWorld.v2.z = (float)(v106 * v81) - (float)(v105 * v82);
              localWorld.v2.w = 0.0;
            }
            goto LABEL_152;
          }
LABEL_132:
          if ( v84 >= 1.0 )
            v84 = *(float *)&FLOAT_1_0;
          goto LABEL_135;
        }
        if ( !v52 || v25 || v52 == -376 || !*(_BYTE *)(v52 + 544) )
        {
LABEL_197:
          ((void (__fastcall *)(UFG::SimObject *, UFG::qMatrix44 *, unsigned int *))v3->mParameters.mSimObject.m_pPointer->vfptr[5].__vecDelDtor)(
            v3->mParameters.mSimObject.m_pPointer,
            &localWorld,
            &v3->m_TypeUID);
          if ( (_BYTE)v161 )
          {
            if ( !v25 )
            {
              v146 = v3->mParameters.mSimObject.m_pPointer;
              if ( v146 )
              {
                v147 = 0i64;
                if ( BYTE4(v146[4].m_pTransformNodeComponent) & 7 )
                  v147 = v3->mParameters.mSimObject.m_pPointer;
                if ( v147 )
                  UFG::PhysicsWheeledVehicle::QueueAsyncQueryForGroundFixup(
                    (UFG::PhysicsWheeledVehicle *)v147,
                    v50,
                    v3->mPrev != 0i64,
                    COERCE_FLOAT(v3->mParameters.modelName.mStringHashUpper32 & _xmm) > 0.050000001);
              }
            }
          }
          goto LABEL_204;
        }
        v50 = 1;
        v113 = 1.0 <= *(float *)&v3->mDriverComponent.mPrev;
        v114 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)(v52 + 376));
        UFG::RoadNetworkLocation::GetPos(v114, (UFG::qVector3 *)&localWorld.v3.z);
        UFG::RoadNetworkLocation::GetTangent(v114, &v153);
        v115 = (__m128)LODWORD(v153.y);
        v115.m128_f32[0] = (float)(v115.m128_f32[0] * v115.m128_f32[0]) + (float)(v153.x * v153.x);
        v116 = _mm_sqrt_ps(v115);
        v117 = v116;
        v117.m128_f32[0] = (float)(v116.m128_f32[0] * v116.m128_f32[0]) + (float)(v153.z * v153.z);
        if ( v117.m128_f32[0] == 0.0 )
          v118 = 0.0;
        else
          v118 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v117));
        v116.m128_f32[0] = v116.m128_f32[0] * v118;
        v119 = v153.z * v118;
        if ( v113 )
        {
          v120 = (float)(v2 * 0.5) * v3->mBoundingBoxMin.y;
        }
        else
        {
          v121 = *(float *)&v3->m_Flags;
          if ( v121 > 0.0 )
          {
            *(float *)&v3->mParameters.modelName.mStringHashUpper32 = (float)((float)(v121 * v2) * v3->mBoundingBoxMin.y)
                                                                    + *(float *)&v3->mParameters.modelName.mStringHashUpper32;
LABEL_181:
            v123 = *(float *)&v3->mParameters.modelName.mStringHashUpper32;
            if ( v123 <= 0.0 )
              v123 = 0.0;
            if ( v123 >= v3->mBoundingBoxMax.x )
              v123 = v3->mBoundingBoxMax.x;
            *(float *)&v3->mParameters.modelName.mStringHashUpper32 = v123;
            v124 = LODWORD(localWorld.v0.x);
            v125 = (__m128)LODWORD(localWorld.v0.y);
            v126 = localWorld.v0.z;
            if ( v123 > 1.0 )
            {
              v127 = *(float *)&v3->m_TypeUID * 0.30000001;
              v128 = (float)(localWorld.v0.y * v127) + localWorld.v0.x;
              v129 = (float)(COERCE_FLOAT(LODWORD(localWorld.v0.x) ^ _xmm[0]) * v127) + localWorld.v0.y;
              v125 = v116;
              v125.m128_f32[0] = v116.m128_f32[0] / fsqrt((float)(v129 * v129) + (float)(v128 * v128));
              v124 = (__int128)v125;
              *(float *)&v124 = v125.m128_f32[0] * v128;
              v125.m128_f32[0] = v125.m128_f32[0] * v129;
              v126 = v119;
            }
            v130 = v125;
            v130.m128_f32[0] = (float)((float)(v125.m128_f32[0] * v125.m128_f32[0])
                                     + (float)(*(float *)&v124 * *(float *)&v124))
                             + (float)(v126 * v126);
            if ( v130.m128_f32[0] == 0.0 )
              v131 = 0.0;
            else
              v131 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v130));
            v132 = v124;
            *(float *)&v132 = *(float *)&v124 * v131;
            v133 = v125.m128_f32[0] * v131;
            v134 = v126 * v131;
            LODWORD(v135) = COERCE_UNSIGNED_INT(v125.m128_f32[0] * v131) ^ _xmm[0];
            v136 = (__m128)v132;
            v136.m128_f32[0] = (float)(*(float *)&v132 * *(float *)&v132) + (float)(v135 * v135);
            if ( v136.m128_f32[0] == 0.0 )
              v137 = 0.0;
            else
              v137 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v136));
            v138 = v137 * v135;
            *(float *)&result[0].m_bool = v137 * v135;
            v139 = *(float *)&v132 * v137;
            *(float *)&v163[0].m_bool = v139;
            v140 = v137 * 0.0;
            v141 = (float)(v140 * v133) - (float)(v139 * v134);
            v142 = (float)(v138 * v134) - (float)(v140 * *(float *)&v132);
            v143 = (float)(v139 * *(float *)&v132) - (float)(v138 * v133);
            v144 = (float)((float)(v142 * v142) + (float)(v141 * v141)) + (float)(v143 * v143);
            if ( v144 == 0.0 )
              v145 = 0.0;
            else
              v145 = 1.0 / fsqrt(v144);
            LODWORD(localWorld.v0.x) = v132;
            localWorld.v0.y = v133;
            localWorld.v0.z = v134;
            localWorld.v0.w = 0.0;
            localWorld.v1.x = *(float *)&result[0].m_bool;
            localWorld.v1.y = *(float *)&v163[0].m_bool;
            localWorld.v1.z = v140;
            localWorld.v1.w = 0.0;
            localWorld.v2.x = v145 * v141;
            localWorld.v2.y = v145 * v142;
            localWorld.v2.z = v145 * v143;
            localWorld.v2.w = 0.0;
            localWorld.v3.x = (float)((float)(v123 * *(float *)&v124) * v2) + localWorld.v3.x;
            localWorld.v3.y = (float)((float)(v123 * v125.m128_f32[0]) * v2) + localWorld.v3.y;
            localWorld.v3.z = top_speed;
            localWorld.v3.w = 1.0;
            goto LABEL_197;
          }
          if ( v121 < 0.0 )
          {
            v122 = *(float *)&v3->mParameters.modelName.mStringHashUpper32
                 - (float)((float)(v121 * v2) * v3->mBoundingBoxMin.x);
LABEL_180:
            *(float *)&v3->mParameters.modelName.mStringHashUpper32 = v122;
            goto LABEL_181;
          }
          v120 = v2 * v3->mBoundingBoxMin.z;
        }
        v122 = v120 + *(float *)&v3->mParameters.modelName.mStringHashUpper32;
        goto LABEL_180;
      }
    }
    v31 = 1;
    goto LABEL_92;
  }
}

// File Line: 1196
// RVA: 0x69A600
void __fastcall UFG::PhysicsMoverInterface::UpdateTransforms(UFG::PhysicsMoverInterface *this, float delta_seconds)
{
  float v2; // xmm7_4
  UFG::PhysicsMoverInterface *v3; // rdi
  UFG::PhysicsVehicle *v4; // rax
  UFG::SimObjectCVBase *v5; // rcx
  UFG::CharacterAnimationComponent *v6; // rax
  Creature *v7; // rax
  signed __int64 v8; // r15
  UFG::SimObject *v9; // rax
  UFG::TransformNodeComponent *v10; // rbx
  UFG::qMatrix44 *v11; // r12
  UFG::qVector3 *v12; // rax
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::PhysicsVehicle *v15; // r13
  __int64 v16; // rbx
  UFG::PhysicsWheeledVehicle *v17; // r14
  unsigned int v18; // edx
  int v19; // eax
  int *v20; // rbx
  _DWORD *v21; // rsi
  signed __int64 v22; // r14
  __int64 v23; // r15
  int v24; // xmm2_4
  __m128 v25; // xmm3
  UFG::qVector4 *v26; // rax
  int v27; // eax
  int *v28; // r12
  int *v29; // r14
  __int64 v30; // rsi
  __m128 v31; // xmm3
  __m128 v32; // xmm4
  __m128 v33; // xmm5
  __m128 v34; // xmm6
  __m128 v35; // xmm6
  __m128 v36; // xmm3
  __m128 v37; // xmm7
  __m128 v38; // xmm8
  __m128 v39; // xmm9
  __m128 *v40; // rcx
  signed __int64 v41; // rdx
  __m128 v42; // xmm3
  __m128 v43; // xmm4
  __m128 v44; // xmm6
  __m128 v45; // xmm6
  __m128 v46; // xmm3
  __m128 v47; // xmm6
  __m128 v48; // xmm3
  __m128 v49; // xmm4
  __m128 v50; // xmm5
  __m128 v51; // xmm5
  __m128 v52; // xmm6
  float v53; // xmm0_4
  float v54; // xmm8_4
  float v55; // xmm6_4
  int v56; // xmm0_4
  float v57; // xmm0_4
  float v58; // xmm7_4
  float v59; // xmm6_4
  float v60; // xmm0_4
  __m128 v61; // xmm6
  float v62; // xmm10_4
  float v63; // xmm8_4
  float v64; // xmm9_4
  float v65; // xmm6_4
  bool v66; // dl
  UFG::qMatrix44 *v67; // r8
  UFG::qMatrix44 *v68; // rcx
  UFG::qMatrix44 *v69; // rdx
  UFG::qMatrix44 *v70; // rax
  __int128 v71; // xmm3
  __m128 v72; // xmm0
  UFG::qVector4 v73; // xmm1
  int *v74; // rax
  signed __int64 v75; // rsi
  float v76; // xmm0_4
  int *v77; // rbx
  signed __int64 v78; // rsi
  signed __int64 v79; // r14
  float v80; // xmm0_4
  int *v81; // rbx
  __int64 v82; // rdx
  signed __int64 v83; // rdx
  __m128 v84; // xmm4
  __m128 v85; // xmm5
  __m128 v86; // xmm6
  __m128 v87; // xmm6
  __m128 v88; // xmm3
  UFG::qVector4 row_vec4; // [rsp+20h] [rbp-B8h]
  hkQuaternionf wheelTransform; // [rsp+30h] [rbp-A8h]
  __int128 v91; // [rsp+40h] [rbp-98h]
  char v92[24]; // [rsp+50h] [rbp-88h]
  hkQsTransformf matrixLS; // [rsp+68h] [rbp-70h]
  __int128 v94; // [rsp+98h] [rbp-40h]
  __int128 v95; // [rsp+A8h] [rbp-30h]
  __int64 v96; // [rsp+C8h] [rbp-10h]
  __int64 v97; // [rsp+D0h] [rbp-8h]
  int v98; // [rsp+D8h] [rbp+0h]
  int v99; // [rsp+DCh] [rbp+4h]
  int v100; // [rsp+E0h] [rbp+8h]
  int v101; // [rsp+E4h] [rbp+Ch]
  hkVector4f v102; // [rsp+E8h] [rbp+10h]
  hkQuaternionf v103; // [rsp+F8h] [rbp+20h]
  UFG::qVector4 result; // [rsp+108h] [rbp+30h]
  __int64 v105; // [rsp+118h] [rbp+40h]
  UFG::qVector4 v106; // [rsp+120h] [rbp+48h]
  UFG::qMatrix44 dest; // [rsp+138h] [rbp+60h]
  hkQsTransformf axleTransform; // [rsp+178h] [rbp+A0h]
  UFG::qMatrix44 v109; // [rsp+238h] [rbp+160h]
  UFG::qMatrix44 v110; // [rsp+278h] [rbp+1A0h]
  UFG::qMatrix44 v111; // [rsp+2B8h] [rbp+1E0h]
  char v112; // [rsp+2F8h] [rbp+220h]
  Creature *v113; // [rsp+3B8h] [rbp+2E0h]

  v105 = -2i64;
  v2 = delta_seconds;
  v3 = this;
  v4 = this->mPhysicsVehicle;
  if ( v4 )
  {
    if ( v4->mRigidBody->mBody )
    {
      v5 = (UFG::SimObjectCVBase *)this->m_pSimObject;
      if ( v5 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
        if ( v6 )
        {
          v7 = v6->mCreature;
          v113 = v7;
          if ( v7 )
          {
            v8 = (signed __int64)&v7->mPose;
            if ( v7->mPose.mRigHandle.mData )
            {
              v9 = v3->m_pSimObject;
              if ( v9 )
              {
                v10 = (UFG::TransformNodeComponent *)v9->m_Components.p[2].m_pComponent;
                if ( v10 )
                {
                  UFG::PhysicsVehicle::ComputeBodyTransform(v3->mPhysicsVehicle);
                  v11 = &v3->mPhysicsVehicle->mBodyTransform;
                  UFG::TransformNodeComponent::SetWorldTransform(v10, v11);
                  v12 = UFG::PhysicsVehicle::GetVelocity(v3->mPhysicsVehicle, (UFG::qVector3 *)&row_vec4);
                  v13 = v12->y;
                  v14 = v12->z;
                  v10->mWorldVelocity.x = v12->x;
                  v10->mWorldVelocity.y = v13;
                  v10->mWorldVelocity.z = v14;
                  v3->mPhysicsVehicle->vfptr[2].__vecDelDtor(
                    (UFG::BasePhysicsObject *)&v3->mPhysicsVehicle->vfptr,
                    (unsigned int)v11);
                  v15 = v3->mPhysicsVehicle;
                  if ( v15 )
                  {
                    v16 = 0i64;
                    v17 = 0i64;
                    if ( *((_BYTE *)v15 + 604) & 7 )
                      v17 = (UFG::PhysicsWheeledVehicle *)v3->mPhysicsVehicle;
                    if ( v17 )
                    {
                      v18 = _S26_4;
                      if ( !(_S26_4 & 1) )
                      {
                        v18 = _S26_4 | 1;
                        _S26_4 |= 1u;
                        flip_left.v0 = (UFG::qVector4)_xmm;
                        flip_left.v1 = (UFG::qVector4)_xmm;
                        flip_left.v2 = (UFG::qVector4)_xmm;
                        flip_left.v3 = (UFG::qVector4)_xmm;
                      }
                      if ( v3->mPhysicsVehicle->mCurrentLod == 2 )
                      {
                        v53 = UFG::PhysicsWheeledVehicle::GetWheelAngle(v17, 0);
                        v54 = v53;
                        v55 = UFG::PhysicsMoverInterface::mWheelAngleRateLimit * v2;
                        ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *))v17->vfptr[5].__vecDelDtor)(v17);
                        *(float *)&v56 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v53 * v3->mInput.mSteering) ^ _xmm[0])
                                       - v3->mWheelRenderAngle;
                        if ( *(float *)&v56 <= COERCE_FLOAT(LODWORD(v55) ^ _xmm[0]) )
                          v56 = LODWORD(v55) ^ _xmm[0];
                        if ( *(float *)&v56 >= v55 )
                          *(float *)&v56 = v55;
                        v57 = *(float *)&v56 + v3->mWheelRenderAngle;
                        v3->mWheelRenderAngle = v57;
                        UFG::qRotationMatrixZ(&dest, v57);
                        UFG::qRotationMatrixY((UFG::qMatrix44 *)&matrixLS.m_translation.m_quad.m128_u16[4], v54);
                        if ( v3->mNumWheels > 0 )
                        {
                          do
                          {
                            v58 = v17->mCurrentSuspensionLength.array[(signed int)v16];
                            v59 = UFG::PhysicsWheeledVehicle::GetMaxSuspensionLength(v17, v16);
                            v60 = UFG::PhysicsWheeledVehicle::GetMinSuspensionLength(v17, v16);
                            if ( v58 <= v60 )
                              v58 = v60;
                            if ( v58 >= v59 )
                              v58 = v59;
                            v61 = *((__m128 *)&v17->vfptr + (signed int)v16 + 46i64);
                            v62 = COERCE_FLOAT(*((_OWORD *)&v17->vfptr + (signed int)v16 + 46i64)) * v58;
                            v63 = COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 85)) * v58;
                            v64 = COERCE_FLOAT(_mm_shuffle_ps(*((__m128 *)&v17->vfptr + (signed int)v16 + 46i64), v61, 170))
                                * v58;
                            v65 = COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 255)) * v58;
                            row_vec4 = (UFG::qVector4)*((_OWORD *)&v17->vfptr + (signed int)v16 + 42i64);
                            v66 = (signed int)v16 < v3->mNumWheels >> 1;
                            if ( (unsigned __int8)~(_BYTE)v16 & (v3->mNumWheels != 2) )
                            {
                              v67 = (UFG::qMatrix44 *)&matrixLS.m_translation.m_quad.m128_u16[4];
                              v68 = &flip_left;
                              if ( v66 )
                              {
                                v68 = UFG::qMatrix44::operator*(
                                        &flip_left,
                                        &v111,
                                        (UFG::qMatrix44 *)&matrixLS.m_translation.m_quad.m128_u16[4]);
                                v67 = &dest;
                                v69 = (UFG::qMatrix44 *)&v112;
                              }
                              else
                              {
                                v69 = &v109;
                              }
                              v70 = UFG::qMatrix44::operator*(v68, v69, v67);
                            }
                            else if ( v66 )
                            {
                              v70 = UFG::qMatrix44::operator*(
                                      (UFG::qMatrix44 *)&matrixLS.m_translation.m_quad.m128_u16[4],
                                      &v110,
                                      &dest);
                            }
                            else
                            {
                              v96 = matrixLS.m_translation.m_quad.m128_i64[1];
                              v97 = matrixLS.m_rotation.m_vec.m_quad.m128_i64[0];
                              v98 = *(_DWORD *)&v92[8];
                              v99 = *(_DWORD *)&v92[12];
                              v100 = *(_DWORD *)&v92[16];
                              v101 = *(_DWORD *)&v92[20];
                              v102.m_quad = (__m128)matrixLS.m_translation;
                              v103.m_vec.m_quad = (__m128)matrixLS.m_rotation;
                              v70 = (UFG::qMatrix44 *)&v96;
                            }
                            v71 = (__int128)v70->v1;
                            v72 = (__m128)v70->v0;
                            v73 = v70->v3;
                            *(UFG::qVector4 *)v92 = v70->v2;
                            v91 = v71;
                            wheelTransform.m_vec.m_quad = v72;
                            *(float *)&v92[16] = row_vec4.x + v62;
                            *(float *)&v92[20] = row_vec4.y + v63;
                            matrixLS.m_translation.m_quad.m128_f32[0] = row_vec4.z + v64;
                            matrixLS.m_translation.m_quad.m128_f32[1] = row_vec4.w + v65;
                            SkeletalPose::SetPositionMS(
                              (SkeletalPose *)v8,
                              v3->mWheelBoneId.array[(signed int)v16],
                              (UFG::qMatrix44 *)&wheelTransform);
                            v74 = (int *)UFG::operator*(&v106, (UFG::qVector4 *)&v92[16], v11);
                            v75 = 2i64 * (signed int)v16;
                            matrixLS.m_scale.m_quad.m128_i32[2 * v75] = *v74;
                            matrixLS.m_scale.m_quad.m128_i32[2 * v75 + 1] = v74[1];
                            matrixLS.m_scale.m_quad.m128_i32[2 * v75 + 2] = v74[2];
                            matrixLS.m_scale.m_quad.m128_i32[2 * v75 + 3] = v74[3];
                            LODWORD(v16) = v16 + 1;
                          }
                          while ( (signed int)v16 < v3->mNumWheels );
                        }
                      }
                      else if ( v3->mPhysicsVehicle->mCurrentLod == 3 )
                      {
                        if ( !(v18 & 2) )
                        {
                          _S26_4 = v18 | 2;
                          flip.m_vec.m_quad = _xmm;
                        }
                        UFG::PhysicsWheeledVehicle::GetWheelTransforms(v17, &axleTransform, &wheelTransform, 1);
                        v27 = v3->mNumWheels;
                        if ( v27 == 4 )
                        {
                          SkeletalPose::SetPositionWS((SkeletalPose *)v8, v3->mAxleBoneId.array, &axleTransform, 4);
                          if ( v3->mNumWheels > 0 )
                          {
                            v28 = v3->mWheelBoneId.array;
                            v29 = &axleTransform.m_translation.m_quad.m128_i32[2];
                            v30 = 0i64;
                            do
                            {
                              if ( v16 & 1 )
                              {
                                v31 = *(__m128 *)((char *)&wheelTransform.m_vec.m_quad + v30 * 4);
                                v32 = _mm_shuffle_ps(v31, v31, 255);
                                v33 = _mm_shuffle_ps(flip.m_vec.m_quad, flip.m_vec.m_quad, 255);
                                v34 = _mm_sub_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(flip.m_vec.m_quad, flip.m_vec.m_quad, 201), v31),
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(
                                            *(__m128 *)((char *)&wheelTransform.m_vec.m_quad + v30 * 4),
                                            v31,
                                            201),
                                          flip.m_vec.m_quad));
                                v35 = _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v34, v34, 201), _mm_mul_ps(v32, flip.m_vec.m_quad)),
                                        _mm_mul_ps(*(__m128 *)((char *)&wheelTransform.m_vec.m_quad + v30 * 4), v33));
                                v36 = _mm_mul_ps(v31, flip.m_vec.m_quad);
                                *(__m128 *)((char *)&wheelTransform.m_vec.m_quad + v30 * 4) = _mm_shuffle_ps(
                                                                                                v35,
                                                                                                _mm_unpackhi_ps(
                                                                                                  v35,
                                                                                                  _mm_sub_ps(
                                                                                                    _mm_mul_ps(v33, v32),
                                                                                                    _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)), _mm_shuffle_ps(v36, v36, 170)))),
                                                                                                196);
                              }
                              matrixLS.m_scale.m_quad.m128_i32[v30] = *(v29 - 2);
                              matrixLS.m_scale.m_quad.m128_i32[v30 + 1] = *(v29 - 1);
                              matrixLS.m_scale.m_quad.m128_i32[v30 + 2] = *v29;
                              matrixLS.m_scale.m_quad.m128_i32[v30 + 3] = v29[1];
                              matrixLS.m_translation = (hkVector4f)query.m_quad;
                              *(hkVector4f *)((char *)&matrixLS.m_translation + 8) = (hkVector4f)aabbOut.m_quad;
                              *(hkQuaternionf *)&v92[8] = *(hkQuaternionf *)((char *)&wheelTransform + v30 * 4);
                              SkeletalPose::SetQsTransformLS(
                                (SkeletalPose *)v8,
                                *v28,
                                (hkQsTransformf *)((char *)&matrixLS + 8));
                              LODWORD(v16) = v16 + 1;
                              ++v28;
                              v29 += 12;
                              v30 += 4i64;
                            }
                            while ( (signed int)v16 < v3->mNumWheels );
                          }
                        }
                        else if ( v27 == 2 )
                        {
                          v37 = flip.m_vec.m_quad;
                          v38 = _mm_shuffle_ps(flip.m_vec.m_quad, flip.m_vec.m_quad, 255);
                          v39 = _mm_shuffle_ps(flip.m_vec.m_quad, flip.m_vec.m_quad, 201);
                          v40 = &axleTransform.m_rotation.m_vec.m_quad;
                          v41 = 2i64;
                          do
                          {
                            v42 = *(__m128 *)((char *)&wheelTransform.m_vec.m_quad + v16);
                            v43 = _mm_shuffle_ps(v42, v42, 255);
                            v44 = _mm_sub_ps(
                                    _mm_mul_ps(v39, v42),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)((char *)&wheelTransform.m_vec.m_quad + v16), v42, 201),
                                      v37));
                            v45 = _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v44, v44, 201), _mm_mul_ps(v43, v37)),
                                    _mm_mul_ps(*(__m128 *)((char *)&wheelTransform.m_vec.m_quad + v16), v38));
                            v46 = _mm_mul_ps(v42, v37);
                            v47 = _mm_shuffle_ps(
                                    v45,
                                    _mm_unpackhi_ps(
                                      v45,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v38, v43),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                                          _mm_shuffle_ps(v46, v46, 170)))),
                                    196);
                            *(__m128 *)((char *)&wheelTransform + v16) = v47;
                            v48 = _mm_shuffle_ps(*v40, *v40, 255);
                            v49 = _mm_shuffle_ps(v47, v47, 255);
                            v50 = _mm_sub_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), *v40),
                                    _mm_mul_ps(_mm_shuffle_ps(*v40, *v40, 201), v47));
                            v51 = _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v50, v50, 201), _mm_mul_ps(v47, v48)),
                                    _mm_mul_ps(*v40, v49));
                            v52 = _mm_mul_ps(v47, *v40);
                            *v40 = _mm_shuffle_ps(
                                     v51,
                                     _mm_unpackhi_ps(
                                       v51,
                                       _mm_sub_ps(
                                         _mm_mul_ps(v49, v48),
                                         _mm_add_ps(
                                           _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                                           _mm_shuffle_ps(v52, v52, 170)))),
                                     196);
                            *(int *)((char *)matrixLS.m_scale.m_quad.m128_i32 + v16) = v40[-1].m128_i32[0];
                            *(int *)((char *)&matrixLS.m_scale.m_quad.m128_i32[1] + v16) = v40[-1].m128_i32[1];
                            *(int *)((char *)&matrixLS.m_scale.m_quad.m128_i32[2] + v16) = v40[-1].m128_i32[2];
                            *(int *)((char *)&matrixLS.m_scale.m_quad.m128_i32[3] + v16) = v40[-1].m128_i32[3];
                            v40 += 3;
                            v16 += 16i64;
                            --v41;
                          }
                          while ( v41 );
                          SkeletalPose::SetPositionWS((SkeletalPose *)v8, v3->mWheelBoneId.array, &axleTransform, 2);
                        }
                      }
                      else
                      {
                        v19 = v3->mNumWheels;
                        if ( v19 > 0 )
                        {
                          v20 = &matrixLS.m_scale.m_quad.m128_i32[1];
                          v21 = (_DWORD *)v17->mRestingSuspensionLength.array;
                          v22 = (char *)v17 - (char *)&matrixLS.m_scale.m_quad.m128_i16[2];
                          v23 = (unsigned int)v19;
                          do
                          {
                            v24 = *v21 ^ _xmm[0];
                            v25 = *(__m128 *)((char *)v20 + v22 + 672);
                            LODWORD(row_vec4.x) = *(_OWORD *)((char *)v20 + v22 + 672);
                            LODWORD(row_vec4.y) = (unsigned __int128)_mm_shuffle_ps(v25, v25, 85);
                            row_vec4.z = COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 170)) + *(float *)&v24;
                            LODWORD(row_vec4.w) = *(int *)((char *)v20 + v22 + 684);
                            v26 = UFG::operator*(&result, &row_vec4, v11);
                            *(v20 - 1) = LODWORD(v26->x);
                            *v20 = LODWORD(v26->y);
                            v20[1] = LODWORD(v26->z);
                            v20[2] = LODWORD(v26->w);
                            ++v21;
                            v20 += 4;
                            --v23;
                          }
                          while ( v23 );
                        }
                      }
                      UFG::PhysicsMoverInterface::UpdateTargetSpheres(v3, (UFG::qVector4 *)&matrixLS.m_scale);
                    }
                    else if ( v15 && !(*((_BYTE *)v15 + 604) & 7) && v15->mCurrentLod != 1 )
                    {
                      v76 = UFG::PhysicsBoat::GetRudderAngle((UFG::PhysicsBoat *)v3->mPhysicsVehicle);
                      UFG::qRotationMatrixZ((UFG::qMatrix44 *)&matrixLS.m_scale, COERCE_FLOAT(LODWORD(v76) ^ _xmm[0]));
                      v77 = (int *)&v3->mMotorBoneId;
                      v78 = 2i64;
                      v79 = 2i64;
                      do
                      {
                        if ( *v77 != -1 )
                        {
                          SkeletalPose::GetPositionLS((SkeletalPose *)v8, *v77, (UFG::qMatrix44 *)&wheelTransform);
                          wheelTransform.m_vec.m_quad = (__m128)matrixLS.m_scale;
                          v91 = v94;
                          *(_OWORD *)v92 = v95;
                          SkeletalPose::SetPositionLS((SkeletalPose *)v8, *v77, (UFG::qMatrix44 *)&wheelTransform);
                        }
                        ++v77;
                        --v79;
                      }
                      while ( v79 );
                      if ( v15->mCurrentLod == 3 )
                      {
                        if ( v3->mDriverComponent.m_pSimComponent )
                          v3->mPropellerAngle = (float)((float)(v3->mForwardSpeed * 5.0) * v2) + v3->mPropellerAngle;
                        v80 = v3->mPropellerAngle;
                        if ( v80 > 6.2831855 )
                          v3->mPropellerAngle = v80 - 6.2831855;
                        v81 = (int *)&v3->mPropellerBoneId;
                        do
                        {
                          v82 = *v81;
                          if ( (_DWORD)v82 != -1 )
                          {
                            row_vec4 = (UFG::qVector4)_xmm;
                            v83 = *(_QWORD *)(**(_QWORD **)(v8 + 248) + 56i64) + 48 * v82;
                            *(hkVector4f *)((char *)&matrixLS.m_translation + 8) = *(hkVector4f *)v83;
                            *(_OWORD *)&v92[8] = *(_OWORD *)(v83 + 16);
                            matrixLS.m_translation = *(hkVector4f *)(v83 + 32);
                            hkQuaternionf::setAxisAngle(
                              (hkQuaternionf *)&result,
                              (hkVector4f *)&row_vec4,
                              v3->mPropellerAngle);
                            v84 = _mm_shuffle_ps(*(__m128 *)&v92[8], *(__m128 *)&v92[8], 255);
                            v85 = _mm_shuffle_ps((__m128)result, (__m128)result, 255);
                            v86 = _mm_sub_ps(
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)result, (__m128)result, 201), *(__m128 *)&v92[8]),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&v92[8], *(__m128 *)&v92[8], 201),
                                      (__m128)result));
                            v87 = _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v86, v86, 201), _mm_mul_ps((__m128)result, v84)),
                                    _mm_mul_ps(*(__m128 *)&v92[8], v85));
                            v88 = _mm_mul_ps((__m128)result, *(__m128 *)&v92[8]);
                            *(__m128 *)&v92[8] = _mm_shuffle_ps(
                                                   v87,
                                                   _mm_unpackhi_ps(
                                                     v87,
                                                     _mm_sub_ps(
                                                       _mm_mul_ps(v85, v84),
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v88, v88, 85),
                                                           _mm_shuffle_ps(v88, v88, 0)),
                                                         _mm_shuffle_ps(v88, v88, 170)))),
                                                   196);
                            SkeletalPose::SetQsTransformLS(
                              (SkeletalPose *)v8,
                              *v81,
                              (hkQsTransformf *)((char *)&matrixLS + 8));
                          }
                          ++v81;
                          --v78;
                        }
                        while ( v78 );
                      }
                    }
                  }
                  Creature::updateEffectorsToPose(v113);
                  Creature::UpdateAttachmentPoses(v113);
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 1440
// RVA: 0x68CAD0
void __fastcall UFG::PhysicsMoverInterface::Suspend(UFG::PhysicsMoverInterface *this)
{
  int v1; // eax
  UFG::PhysicsMoverInterface *v2; // rbx
  UFG::PhysicsVehicle *v3; // rcx

  v1 = *((_DWORD *)this + 224);
  v2 = this;
  if ( !(v1 & 2) )
  {
    *((_DWORD *)this + 224) = v1 | 2;
    v3 = this->mPhysicsVehicle;
    if ( v3 )
      ((void (*)(void))v3->vfptr[2].DebugDraw)();
    v2->m_Flags |= 2u;
  }
}

// File Line: 1456
// RVA: 0x689A50
void __fastcall UFG::PhysicsMoverInterface::Restore(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsMoverInterface *v1; // rbx
  UFG::PhysicsVehicle *v2; // rcx

  v1 = this;
  if ( *((_BYTE *)this + 896) & 2 )
  {
    v2 = this->mPhysicsVehicle;
    if ( v2 )
      ((void (*)(void))v2->vfptr[2].ResourceUnloaded)();
    v1->m_Flags &= 0xFFFDu;
    *((_DWORD *)v1 + 224) &= 0xFFFFFFFD;
  }
}

// File Line: 1472
// RVA: 0x67A700
signed __int64 __fastcall UFG::PhysicsMoverInterface::GetLOD(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *v1; // rax
  signed __int64 result; // rax

  v1 = this->mPhysicsVehicle;
  if ( v1 )
    result = (unsigned int)v1->mCurrentLod;
  else
    result = 1i64;
  return result;
}

// File Line: 1479
// RVA: 0x68A9B0
void __fastcall UFG::PhysicsMoverInterface::SetLOD(UFG::PhysicsMoverInterface *this, UFG::PhysicsVehicle::Lod lod)
{
  UFG::PhysicsVehicle::Lod v2; // edi
  UFG::PhysicsMoverInterface *v3; // rbx
  UFG::PhysicsVehicle *v4; // rax

  v2 = lod;
  v3 = this;
  if ( lod == 3 )
    ((void (*)(void))this->vfptr[9].__vecDelDtor)();
  v4 = v3->mPhysicsVehicle;
  if ( v4 )
    v4->mDesiredLod = v2;
  switch ( v2 )
  {
    case 0:
    case 1:
    case 4:
    case 5:
      UFG::PhysicsMoverInterface::DeactivateTargetSpheres(v3);
      break;
    case 2:
    case 3:
      UFG::PhysicsMoverInterface::ActivateTargetSpheres(v3);
      break;
    default:
      return;
  }
}

// File Line: 1519
// RVA: 0x67FDD0
void __fastcall UFG::PhysicsMoverInterface::LockHighLod(UFG::PhysicsMoverInterface *this, UFG::PhysicsMoverInterface::ELODLockMode eMode, float time)
{
  int v3; // eax
  UFG::PhysicsMoverInterface::ELODLockMode v4; // edi
  UFG::PhysicsMoverInterface *v5; // rbx
  UFG::PhysicsVehicle *v6; // rax

  v3 = *((_DWORD *)this + 224);
  v4 = eMode;
  v5 = this;
  if ( !(v3 & 1) && !(v3 & 8) )
  {
    UFG::OnlineManager::Instance();
    ((void (__fastcall *)(UFG::PhysicsMoverInterface *))v5->vfptr[9].__vecDelDtor)(v5);
    v6 = v5->mPhysicsVehicle;
    if ( v6 )
      v6->mDesiredLod = 3;
    UFG::PhysicsMoverInterface::ActivateTargetSpheres(v5);
    v5->mLockAtHighLODMode = v4;
    v5->mLockAtHighLODTime = time;
  }
}

// File Line: 1536
// RVA: 0x68EE20
void __fastcall UFG::PhysicsMoverInterface::UnlockHighLod(UFG::PhysicsMoverInterface *this)
{
  *(_QWORD *)&this->mLockAtHighLODMode = 3i64;
}

// File Line: 1544
// RVA: 0x68AA60
void __fastcall UFG::PhysicsMoverInterface::SetOccupantTargetLocks(UFG::PhysicsMoverInterface *this, bool lock)
{
  UFG::SimObject *v2; // rax
  bool v3; // r12
  UFG::SimComponent *v4; // r14
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v5; // r15
  signed __int64 v6; // rax
  signed __int64 v7; // rbx
  int i; // ecx
  int j; // esi
  int k; // edi
  UFG::SimObjectGame *v11; // rcx
  int v12; // edx
  int v13; // er8
  signed __int64 v14; // rax
  signed __int64 l; // rcx
  int v16; // edx
  signed __int64 m; // rcx
  int n; // ecx
  unsigned __int16 v19; // dx
  UFG::SimComponent *v20; // rcx
  UFG::SimComponent *v21; // rax
  __int64 v22; // [rsp+20h] [rbp-48h]

  v2 = this->m_pSimObject;
  v3 = lock;
  if ( v2 )
  {
    v4 = v2->m_Components.p[30].m_pComponent;
    if ( v4 )
    {
      v5 = &v4[1].m_BoundComponentHandles.mNode.mNext;
      v6 = (signed __int64)&v4[1].m_BoundComponentHandles.mNode.mNext[-4];
      v7 = (signed __int64)&v4->m_BoundComponentHandles;
      if ( v4[1].m_pSimObject )
      {
        for ( i = 0; v6 != v7; v6 = *(_QWORD *)(v6 + 72) - 64i64 )
          ++i;
        j = i + 1;
      }
      else
      {
        for ( j = 0; v6 != v7; v6 = *(_QWORD *)(v6 + 72) - 64i64 )
          ++j;
      }
      for ( k = 0; k < j; ++k )
      {
        v11 = (UFG::SimObjectGame *)v4[1].m_pSimObject;
        if ( v11 )
        {
          if ( !k )
            goto LABEL_26;
          v12 = k - 1;
          v13 = 0;
          v14 = (signed __int64)&(*v5)[-4];
          for ( l = v14; l != v7; l = *(_QWORD *)(l + 72) - 64i64 )
            ++v13;
          if ( v12 >= v13 )
            continue;
          for ( ; v12 > 0; v14 = *(_QWORD *)(v14 + 72) - 64i64 )
          {
            if ( v14 == v7 )
              break;
            --v12;
          }
        }
        else
        {
          v16 = 0;
          v14 = (signed __int64)&(*v5)[-4];
          for ( m = v14; m != v7; m = *(_QWORD *)(m + 72) - 64i64 )
            ++v16;
          if ( k >= v16 )
            continue;
          for ( n = k; n > 0; v14 = *(_QWORD *)(v14 + 72) - 64i64 )
          {
            if ( v14 == v7 )
              break;
            --n;
          }
        }
        v11 = *(UFG::SimObjectGame **)(v14 + 40);
LABEL_26:
        if ( v11 )
        {
          v19 = v11->m_Flags;
          if ( (v19 >> 14) & 1 )
          {
            v20 = v11->m_Components.p[20].m_pComponent;
          }
          else if ( (v19 & 0x8000u) == 0 )
          {
            if ( (v19 >> 13) & 1 )
            {
              v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else if ( (v19 >> 12) & 1 )
            {
              v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else
            {
              v21 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v11->vfptr,
                      UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            v20 = v21;
          }
          else
          {
            v20 = v11->m_Components.p[20].m_pComponent;
          }
          if ( v20 )
          {
            LODWORD(v22) = 0;
            ((void (__fastcall *)(UFG::SimComponent *, signed __int64, bool, bool, __int64, _QWORD, _QWORD, _QWORD))v20->vfptr[14].__vecDelDtor)(
              v20,
              28i64,
              v3,
              v3,
              v22,
              0i64,
              0i64,
              0i64);
          }
        }
      }
    }
  }
}

// File Line: 1566
// RVA: 0x6892E0
void __fastcall UFG::PhysicsMoverInterface::Reload(UFG::PhysicsMoverInterface *this, UFG::PhysicsMoverInterface::ReloadReason reason)
{
  UFG::PhysicsMoverInterface::ReloadReason v2; // ebx
  UFG::PhysicsMoverInterface *v3; // rdi
  UFG::qSymbol v4; // [rsp+50h] [rbp+18h]
  UFG::qSymbol propertySetName; // [rsp+58h] [rbp+20h]

  v2 = reason;
  v3 = this;
  v4.mUID = -1;
  UFG::qSymbol::set_null(&v4);
  propertySetName.mUID = v4.mUID;
  UFG::PhysicsMoverInterface::Reload(v3, v2, (__int64)&propertySetName);
}

// File Line: 1575
// RVA: 0x689340
void __fastcall UFG::PhysicsMoverInterface::Reload(UFG::PhysicsMoverInterface *this, UFG::PhysicsMoverInterface::ReloadReason reason, __int64 propertySetName)
{
  int *v3; // rdi
  UFG::PhysicsMoverInterface::ReloadReason v4; // er14
  UFG::PhysicsMoverInterface *v5; // rbx
  unsigned int v6; // eax
  int v7; // eax
  UFG::PhysicsVehicle *v8; // rcx
  UFG::PhysicsWheeledVehicle *v9; // rdi
  UFG::SimObject *v10; // rax
  UFG::SimComponent *v11; // rsi
  signed int v12; // er15
  int v13; // xmm2_4
  int v14; // xmm3_4
  int v15; // xmm0_4
  int v16; // xmm1_4
  int v17; // xmm2_4
  int v18; // xmm3_4
  int v19; // xmm2_4
  int v20; // xmm3_4
  int v21; // xmm0_4
  int v22; // xmm2_4
  int v23; // xmm3_4
  int v24; // xmm0_4
  UFG::PhysicsVehicle *v25; // rcx
  float v26; // xmm1_4
  float v27; // xmm2_4
  UFG::qVector3 *v28; // rax
  float v29; // xmm1_4
  float v30; // xmm2_4
  UFG::PhysicsVehicle *v31; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v32; // rax
  __int64 v33; // rdx
  UFG::SimObjectCVBase *v34; // rcx
  UFG::PhysicsVehicle *v35; // rax
  UFG::qVector3 velocity; // [rsp+20h] [rbp-60h]
  UFG::qVector3 result; // [rsp+30h] [rbp-50h]
  int v38; // [rsp+40h] [rbp-40h]
  int v39; // [rsp+44h] [rbp-3Ch]
  int v40; // [rsp+48h] [rbp-38h]
  int v41; // [rsp+4Ch] [rbp-34h]
  int v42; // [rsp+50h] [rbp-30h]
  int v43; // [rsp+54h] [rbp-2Ch]
  int v44; // [rsp+58h] [rbp-28h]
  int v45; // [rsp+5Ch] [rbp-24h]
  int v46; // [rsp+60h] [rbp-20h]
  int v47; // [rsp+64h] [rbp-1Ch]
  int v48; // [rsp+68h] [rbp-18h]
  int v49; // [rsp+6Ch] [rbp-14h]
  int v50; // [rsp+70h] [rbp-10h]
  int v51; // [rsp+74h] [rbp-Ch]
  int v52; // [rsp+78h] [rbp-8h]
  int v53; // [rsp+7Ch] [rbp-4h]
  int v54; // [rsp+A0h] [rbp+20h]

  v3 = (int *)propertySetName;
  v4 = reason;
  v5 = this;
  if ( this->mParameters.modelName.mStringHashUpper32 == -1 )
    this->mParameters.modelName.mStringHashUpper32 = UFG::qStringHashUpper32(
                                                       this->mParameters.modelName.mData,
                                                       0xFFFFFFFF);
  v6 = UFG::qStringHashUpper32("_Body_P", v5->mParameters.modelName.mStringHashUpper32);
  if ( UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v6) )
  {
    v7 = *v3;
    v54 = *v3;
    if ( v4 )
    {
      if ( v4 != 1 )
        goto LABEL_9;
      v7 = v5->mPropertySetNameHuman.mUID;
    }
    else
    {
      v7 = v5->mPropertySetNameAI.mUID;
    }
    v54 = v7;
LABEL_9:
    v8 = v5->mPhysicsVehicle;
    v9 = 0i64;
    if ( !v8 || v7 != v5->mParameters.mPhysicsPropertiesName.mUID )
    {
      v5->mParameters.mPhysicsPropertiesName.mUID = v7;
      if ( v8 && (unsigned int)v4 <= 1 )
      {
        v8->vfptr[1].__vecDelDtor((UFG::BasePhysicsObject *)&v8->vfptr, (unsigned int)&v54);
      }
      else
      {
        v10 = v5->m_pSimObject;
        if ( v10 )
          v11 = v10->m_Components.p[2].m_pComponent;
        else
          v11 = 0i64;
        v12 = 1;
        if ( *((_BYTE *)v5 + 896) & 8 )
        {
          v12 = 4;
        }
        else if ( v8 )
        {
          v12 = v8->mCurrentLod;
        }
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11);
        v13 = (int)v11[2].m_SafePointerList.mNode.mPrev;
        v14 = HIDWORD(v11[2].m_SafePointerList.mNode.mPrev);
        v15 = (int)v11[2].vfptr;
        v39 = HIDWORD(v11[2].vfptr);
        v40 = v13;
        v38 = v15;
        v41 = v14;
        v16 = HIDWORD(v11[2].m_SafePointerList.mNode.mNext);
        v17 = v11[2].m_TypeUID;
        v18 = v11[2].m_NameUID;
        v42 = (int)v11[2].m_SafePointerList.mNode.mNext;
        v43 = v16;
        v44 = v17;
        v45 = v18;
        v19 = (int)v11[2].m_pSimObject;
        v20 = HIDWORD(v11[2].m_pSimObject);
        v21 = *(_DWORD *)&v11[2].m_Flags;
        v47 = *(_DWORD *)(&v11[2].m_SimObjIndex + 1);
        v46 = v21;
        v48 = v19;
        v49 = v20;
        v22 = (int)v11[2].m_BoundComponentHandles.mNode.mNext;
        v23 = HIDWORD(v11[2].m_BoundComponentHandles.mNode.mNext);
        v24 = (int)v11[2].m_BoundComponentHandles.mNode.mPrev;
        v51 = HIDWORD(v11[2].m_BoundComponentHandles.mNode.mPrev);
        v52 = v22;
        v50 = v24;
        v53 = v23;
        UFG::PhysicsMoverInterface::SetOccupantTargetLocks(v5, 0);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11);
        v25 = v5->mPhysicsVehicle;
        v26 = *((float *)&v11[4].vfptr + 1);
        v27 = *(float *)&v11[4].m_SafePointerList.mNode.mPrev;
        velocity.x = *(float *)&v11[4].vfptr;
        velocity.y = v26;
        velocity.z = v27;
        if ( v25 )
        {
          v28 = UFG::PhysicsVehicle::GetVelocity(v25, &result);
          v29 = v28->y;
          v30 = v28->z;
          velocity.x = v28->x;
          velocity.y = v29;
          velocity.z = v30;
        }
        v31 = v5->mPhysicsVehicle;
        if ( v31 )
          v31->vfptr->__vecDelDtor((UFG::BasePhysicsObject *)&v31->vfptr, 1u);
        v32 = v5->vfptr;
        v5->mPhysicsVehicle = 0i64;
        ((void (__fastcall *)(UFG::PhysicsMoverInterface *, int *, UFG::qVector3 *))v32[19].__vecDelDtor)(
          v5,
          &v38,
          &velocity);
        v5->mPhysicsVehicle->mDesiredLod = v12;
        UFG::PhysicsVehicle::SetVelocity(v5->mPhysicsVehicle, &velocity);
        if ( *((_BYTE *)v5 + 896) & 2 )
          ((void (__cdecl *)(UFG::PhysicsVehicle *, __int64))v5->mPhysicsVehicle->vfptr[2].DebugDraw)(
            v5->mPhysicsVehicle,
            v33);
        UFG::PhysicsMoverInterface::SetOccupantTargetLocks(v5, 1);
      }
    }
    if ( v4 == RELOAD_AI
      || (v34 = (UFG::SimObjectCVBase *)v5->m_pSimObject) != 0i64
      && UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v34) )
    {
      v35 = v5->mPhysicsVehicle;
      if ( v35 )
      {
        if ( *((_BYTE *)v35 + 604) & 7 )
          v9 = (UFG::PhysicsWheeledVehicle *)v5->mPhysicsVehicle;
        if ( v9 )
          UFG::PhysicsWheeledVehicle::ClearSteeringDeadZone(v9);
      }
    }
  }
}

// File Line: 1688
// RVA: 0x66F250
void __fastcall UFG::PhysicsMoverInterface::ActivateTargetSpheres(UFG::PhysicsMoverInterface *this)
{
  UFG::BulletManager *v1; // rbp
  UFG::PhysicsMoverInterface *v2; // rbx
  UFG::PhysicsVehicle *v3; // rcx
  int v4; // edi
  UFG::PhysicsVehicle *v5; // rax
  float v6; // xmm6_4
  signed __int64 v7; // rsi

  v1 = UFG::BulletManager::mInstance;
  v2 = this;
  v3 = this->mPhysicsVehicle;
  v4 = 0;
  if ( !v3 )
    goto LABEL_14;
  v5 = 0i64;
  if ( *((_BYTE *)v3 + 604) & 7 )
    v5 = v3;
  if ( v5 )
    v6 = v5[1].mTargetTransform.v0.y;
  else
LABEL_14:
    v6 = FLOAT_0_27000001;
  if ( v2->mNumWheels > 0 )
  {
    v7 = (signed __int64)&v2->mTargetSpheres[0].owner;
    do
    {
      *(float *)(v7 - 8) = v6;
      *(_QWORD *)v7 = v2;
      *(_DWORD *)(v7 + 8) = v4;
      UFG::BulletManager::AddTargetSphere(v1, &v2->mTargetSpheres[(signed __int64)v4++]);
      v7 += 64i64;
    }
    while ( v4 < v2->mNumWheels );
  }
  if ( v2->mNumWheels == 4 )
  {
    v2->mTargetSpheres[4].radius = v6 * 0.60000002;
    v2->mTargetSpheres[(signed __int64)v2->mNumWheels].owner = v2;
    v2->mTargetSpheres[(signed __int64)v2->mNumWheels].userData = v2->mNumWheels;
    UFG::BulletManager::AddTargetSphere(v1, &v2->mTargetSpheres[(signed __int64)v2->mNumWheels]);
  }
}

// File Line: 1714
// RVA: 0x6761E0
void __fastcall UFG::PhysicsMoverInterface::DeactivateTargetSpheres(UFG::PhysicsMoverInterface *this)
{
  UFG::BulletManager *v1; // rsi
  int v2; // ebx
  UFG::PhysicsMoverInterface *i; // rdi

  v1 = UFG::BulletManager::mInstance;
  v2 = 0;
  for ( i = this; v2 < i->mNumWheels; ++v2 )
    UFG::BulletManager::RemoveTargetSphere(v1, &i->mTargetSpheres[(signed __int64)v2]);
  if ( i->mNumWheels == 4 )
    UFG::BulletManager::RemoveTargetSphere(v1, &i->mTargetSpheres[4]);
}

// File Line: 1731
// RVA: 0x699F20
void __fastcall UFG::PhysicsMoverInterface::UpdateTargetSpheres(UFG::PhysicsMoverInterface *this, UFG::qVector4 *wheelPosition)
{
  int v2; // er9
  UFG::qVector4 *v3; // r11
  int *v4; // rax
  char *v5; // r8
  int v6; // xmm2_4
  int v7; // xmm0_4
  int v8; // xmm1_4
  int v9; // xmm0_4
  int v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  __int64 v13; // rdx
  float *v14; // rax
  float v15; // xmm1_4
  float v16; // xmm2_4
  signed __int64 v17; // rax
  float v18; // xmm1_4
  float v19; // xmm0_4
  signed __int64 v20; // rax
  float v21; // xmm1_4
  float v22; // xmm2_4

  v2 = 0;
  v3 = wheelPosition;
  if ( this->mNumWheels > 0 )
  {
    v4 = (int *)&wheelPosition->z;
    v5 = (char *)&this->mTargetSpheres[0].positionT0.z;
    do
    {
      v6 = *(v4 - 2);
      v7 = *(v4 - 1);
      v8 = *v4;
      ++v2;
      v4 += 4;
      v5 += 64;
      *((_DWORD *)v5 - 18) = v6;
      *((_DWORD *)v5 - 17) = v7;
      *((_DWORD *)v5 - 16) = v8;
      v9 = *(v4 - 5);
      v10 = *(v4 - 4);
      *((_DWORD *)v5 - 15) = *(v4 - 6);
      *((_DWORD *)v5 - 14) = v9;
      *((_DWORD *)v5 - 13) = v10;
    }
    while ( v2 < this->mNumWheels );
  }
  if ( this->mNumWheels == 4 )
  {
    v11 = wheelPosition[2].y * 0.40000001;
    v12 = wheelPosition[2].z * 0.40000001;
    this->mTargetSpheres[4].positionT0.x = wheelPosition[2].x * 0.40000001;
    this->mTargetSpheres[4].positionT0.y = v11;
    this->mTargetSpheres[4].positionT0.z = v12;
    v13 = this->mNumWheels;
    v14 = (float *)&(&this->vfptr)[8 * (v13 + 4)];
    v15 = (float)(v3[(signed int)v13 - 1].y * 0.60000002) + v14[1];
    v16 = (float)(v3[(signed int)v13 - 1].z * 0.60000002) + v14[2];
    *v14 = (float)(v3[(signed int)v13 - 1].x * 0.60000002) + *v14;
    v14[1] = v15;
    v14[2] = v16;
    v17 = (signed __int64)this->mNumWheels << 6;
    v18 = v3[this->mNumWheels - 2].y * 0.60000002;
    v19 = v3[this->mNumWheels - 2].z * 0.60000002;
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.x + v17) = v3[this->mNumWheels - 2].x * 0.60000002;
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.y + v17) = v18;
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.z + v17) = v19;
    LODWORD(v13) = this->mNumWheels;
    v20 = (signed __int64)this->mNumWheels << 6;
    v21 = (float)(v3[(signed int)v13 - 1].y * 0.40000001)
        + *(float *)((char *)&this->mTargetSpheres[0].positionT1.y + v20);
    v22 = (float)(v3[(signed int)v13 - 1].z * 0.40000001)
        + *(float *)((char *)&this->mTargetSpheres[0].positionT1.z + v20);
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.x + v20) = (float)(v3[(signed int)v13 - 1].x * 0.40000001)
                                                                    + *(float *)((char *)&this->mTargetSpheres[0].positionT1.x
                                                                               + v20);
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.y + v20) = v21;
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.z + v20) = v22;
  }
}

// File Line: 1753
// RVA: 0x68BCA0
char __fastcall UFG::PhysicsMoverInterface::ShouldIgnoreBulletImpactDamageSphereEvent(UFG::PhysicsMoverInterface *this, UFG::SimObject *weaponOwnerSimObject)
{
  UFG::PhysicsMoverInterface *v2; // rbx
  unsigned __int16 v4; // cx
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // rax
  UFG::SimComponentHolder *v7; // rax
  UFG::SimComponent *v8; // rbx
  UFG::SimObjectCharacter *v9; // rsi
  unsigned int v10; // eax
  int v11; // er10
  unsigned int v12; // edi
  UFG::SimObjectCharacter *v13; // rax
  signed __int64 v14; // r8
  int v15; // er9
  signed __int64 v16; // rax
  int v17; // edx
  signed __int64 v18; // rcx
  signed __int64 v19; // r8
  int v20; // edx
  signed __int64 v21; // rcx
  int v22; // ecx

  v2 = this;
  if ( !weaponOwnerSimObject )
    return 0;
  v4 = weaponOwnerSimObject->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = weaponOwnerSimObject->m_Components.p[17].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(
             (UFG::SimObjectGame *)weaponOwnerSimObject,
             UFG::CopUnitComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)weaponOwnerSimObject,
                              UFG::CopUnitComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                   weaponOwnerSimObject,
                                                                   UFG::CopUnitComponent::_TypeUID);
  }
  else
  {
    v5 = weaponOwnerSimObject->m_Components.p[17].m_pComponent;
  }
  if ( v5 )
    return 0;
  v6 = v2->m_pSimObject;
  if ( !v6 )
    return 0;
  v7 = v6->m_Components.p;
  v8 = v7[30].m_pComponent;
  if ( !v8 )
    return 0;
  v9 = LocalPlayer;
  v10 = UFG::VehicleOccupantComponent::GetNumberOfOccupants((UFG::VehicleOccupantComponent *)v7[30].m_pComponent);
  v11 = 0;
  v12 = v10;
  if ( !v10 )
    return 0;
  while ( 1 )
  {
    if ( v8[1].m_pSimObject )
    {
      if ( !v11 )
      {
        v13 = (UFG::SimObjectCharacter *)v8[1].m_pSimObject;
        goto LABEL_34;
      }
      v14 = (signed __int64)&v8->m_BoundComponentHandles;
      v15 = 0;
      v16 = (signed __int64)&v8[1].m_BoundComponentHandles.mNode.mNext[-4];
      v17 = v11 - 1;
      v18 = v16;
      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v16 != &v8->m_BoundComponentHandles )
      {
        do
        {
          ++v15;
          v18 = *(_QWORD *)(v18 + 72) - 64i64;
        }
        while ( v18 != v14 );
      }
      if ( v17 < v15 )
      {
        for ( ; v17 > 0; v16 = *(_QWORD *)(v16 + 72) - 64i64 )
        {
          if ( v16 == v14 )
            break;
          --v17;
        }
LABEL_25:
        v13 = *(UFG::SimObjectCharacter **)(v16 + 40);
        goto LABEL_34;
      }
    }
    else
    {
      v19 = (signed __int64)&v8->m_BoundComponentHandles;
      v20 = 0;
      v16 = (signed __int64)&v8[1].m_BoundComponentHandles.mNode.mNext[-4];
      v21 = v16;
      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v16 != &v8->m_BoundComponentHandles )
      {
        do
        {
          ++v20;
          v21 = *(_QWORD *)(v21 + 72) - 64i64;
        }
        while ( v21 != v19 );
      }
      if ( v11 < v20 )
      {
        v22 = v11;
        if ( v11 > 0 )
        {
          while ( v16 != v19 )
          {
            --v22;
            v16 = *(_QWORD *)(v16 + 72) - 64i64;
            if ( v22 <= 0 )
            {
              v13 = *(UFG::SimObjectCharacter **)(v16 + 40);
              goto LABEL_34;
            }
          }
        }
        goto LABEL_25;
      }
    }
    v13 = 0i64;
LABEL_34:
    if ( v9 == v13 )
      return 1;
    if ( ++v11 >= v12 )
      return 0;
  }
}

// File Line: 1788
// RVA: 0x68CC60
void __usercall UFG::PhysicsMoverInterface::TargetSphereEventHandler(UFG::PhysicsMoverInterface *this@<rcx>, UFG::Event *e@<rdx>, float a3@<xmm0>)
{
  UFG::Event *v3; // rdi
  UFG::PhysicsMoverInterface *v4; // rbx
  UFG::SimObject *v5; // rax
  unsigned __int64 v6; // r14
  __int64 v7; // rsi
  UFG::PhysicsVehicle *v8; // rcx
  float v9; // xmm0_4
  UFG::SimObject *v10; // rax
  UFG::HitReactionComponent *v11; // r14
  UFG::SimObject *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  __int64 v16; // rdx
  __int64 v17; // rcx
  _QWORD *v18; // rax
  __int64 v19; // rax
  UFG::CopSystem *v20; // rax
  UFG::PhysicsVehicle *v21; // rax
  UFG::SimObject *v22; // rax
  UFG::HitReactionComponent *v23; // rbx
  UFG::SimObject *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rax
  __int64 v28; // rdx
  __int64 v29; // rcx
  _QWORD *v30; // rax
  __int64 *v31; // rdx
  __int64 v32; // rax
  UFG::qVector3 impulse; // [rsp+30h] [rbp-B8h]
  UFG::HitRecord hitrecord; // [rsp+40h] [rbp-A8h]

  *(_QWORD *)&hitrecord.mAttackerNetworkID = -2i64;
  v3 = e;
  v4 = this;
  v5 = this->m_pSimObject;
  if ( (!v5 || !((v5->m_Flags >> 11) & 1))
    && !UFG::PhysicsMoverInterface::ShouldIgnoreBulletImpactDamageSphereEvent(this, (UFG::SimObject *)e[1].mNext) )
  {
    v6 = v3[2].mUserData0;
    if ( *(UFG::PhysicsMoverInterface **)(v6 + 48) == v4 )
    {
      v7 = *(signed int *)(v6 + 56);
      if ( (signed int)v7 < 0 || (signed int)v7 >= v4->mNumWheels )
      {
        v21 = v4->mPhysicsVehicle;
        if ( v21 )
        {
          if ( (*((_DWORD *)v21 + 151) & 7) == 4 && (_DWORD)v7 == v4->mNumWheels )
          {
            v22 = v4->m_pSimObject;
            if ( v22 )
            {
              v23 = (UFG::HitReactionComponent *)v22->m_Components.p[15].m_pComponent;
              if ( v23 )
              {
                UFG::HitRecord::HitRecord(&hitrecord);
                v24 = (UFG::SimObject *)v3[1].mNext;
                hitrecord.mAttackTypeID = gAttackCollisionVehicleGasTankShot.m_EnumValue;
                hitrecord.mDamage = 100;
                if ( hitrecord.mAttacker.m_pPointer )
                {
                  v25 = hitrecord.mAttacker.mPrev;
                  v26 = hitrecord.mAttacker.mNext;
                  hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
                  v26->mPrev = v25;
                  hitrecord.mAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                  hitrecord.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                }
                hitrecord.mAttacker.m_pPointer = v24;
                if ( v24 )
                {
                  v27 = v24->m_SafePointerList.mNode.mPrev;
                  v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                  hitrecord.mAttacker.mPrev = v27;
                  hitrecord.mAttacker.mNext = &v24->m_SafePointerList.mNode;
                  v24->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                }
                hitrecord.mTimeSinceHit = 0.0;
                hitrecord.mFramesSinceHit = 0;
                v28 = v3[1].mUserData0;
                if ( hitrecord.mMeleeInfo.mActionPath.mPath.mData.mOffset )
                {
                  v29 = *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z;
                  v30 = *(_QWORD **)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount;
                  *(_QWORD *)(*(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z + 8i64) = *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount;
                  *v30 = v29;
                  *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z = (char *)&hitrecord + 104;
                  *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount = (char *)&hitrecord + 104;
                }
                hitrecord.mMeleeInfo.mActionPath.mPath.mData.mOffset = v28;
                if ( v28 )
                {
                  v31 = (__int64 *)(v28 + 8);
                  v32 = *v31;
                  *(_QWORD *)(v32 + 8) = (char *)&hitrecord + 104;
                  *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z = v32;
                  *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount = v31;
                  *v31 = (__int64)&hitrecord.mMeleeInfo.mHitNormal.z;
                }
                hitrecord.mProjectileInfo.m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v3[1].mUserData1;
                LOWORD(hitrecord.mProjectileInfo.m_pSOWPC.mNext) = v3[2].vfptr;
                UFG::HitReactionComponent::HandleHitReaction(v23, &hitrecord);
                goto LABEL_39;
              }
            }
          }
        }
      }
      else if ( v4->mDamageState.tireDamage.array[v7] < 1.0 )
      {
        UFG::PhysicsMoverInterface::LockHighLod(v4, ELODLockMode_TIMED, 10.0);
        UFG::PhysicsMoverInterface::DamageTire(v4, (UFG::SimObject *)v3[1].mNext, v7, 1.0);
        v8 = v4->mPhysicsVehicle;
        if ( v8 && !(*((_BYTE *)v4 + 896) & 1) )
        {
          if ( v4->mDamageState.tireDamage.array[v7] < 1.0 )
          {
            UFG::PhysicsVehicle::GetMass(v8);
            v9 = a3 * v4->mTireShotImpulse;
          }
          else
          {
            UFG::PhysicsVehicle::GetMass(v8);
            v9 = a3 * v4->mTireBlownImpulse;
          }
          impulse.z = v9;
          *(_QWORD *)&impulse.x = 0i64;
          UFG::PhysicsVehicle::ApplyImpulse(v4->mPhysicsVehicle, &impulse, (UFG::qVector3 *)(v6 + 28));
        }
        v10 = v4->m_pSimObject;
        if ( v10 )
        {
          v11 = (UFG::HitReactionComponent *)v10->m_Components.p[15].m_pComponent;
          if ( v11 )
          {
            UFG::HitRecord::HitRecord(&hitrecord);
            v12 = (UFG::SimObject *)v3[1].mNext;
            hitrecord.mAttackTypeID = gAttackCollisionVehicleTireShot.m_EnumValue;
            hitrecord.mDamage = 100;
            if ( hitrecord.mAttacker.m_pPointer )
            {
              v13 = hitrecord.mAttacker.mPrev;
              v14 = hitrecord.mAttacker.mNext;
              hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
              v14->mPrev = v13;
              hitrecord.mAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
              hitrecord.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
            }
            hitrecord.mAttacker.m_pPointer = v12;
            if ( v12 )
            {
              v15 = v12->m_SafePointerList.mNode.mPrev;
              v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
              hitrecord.mAttacker.mPrev = v15;
              hitrecord.mAttacker.mNext = &v12->m_SafePointerList.mNode;
              v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
            }
            *(_QWORD *)&hitrecord.mTimeSinceHit = 0i64;
            v16 = v3[1].mUserData0;
            if ( hitrecord.mMeleeInfo.mActionPath.mPath.mData.mOffset )
            {
              v17 = *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z;
              v18 = *(_QWORD **)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount;
              *(_QWORD *)(*(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z + 8i64) = *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount;
              *v18 = v17;
              *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z = (char *)&hitrecord + 104;
              *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount = (char *)&hitrecord + 104;
            }
            hitrecord.mMeleeInfo.mActionPath.mPath.mData.mOffset = v16;
            if ( v16 )
            {
              v19 = *(_QWORD *)(v16 + 8);
              *(_QWORD *)(v19 + 8) = (char *)&hitrecord + 104;
              *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z = v19;
              *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount = v16 + 8;
              *(_QWORD *)(v16 + 8) = (char *)&hitrecord + 104;
            }
            hitrecord.mProjectileInfo.m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v3[1].mUserData1;
            LOWORD(hitrecord.mProjectileInfo.m_pSOWPC.mNext) = v3[2].vfptr;
            v20 = UFG::CopSystem::Instance();
            ((void (__fastcall *)(UFG::CopSystem *, UFG::qNode<UFG::Event,UFG::Event> *, UFG::SimObject *, UFG::HitRecord *, _QWORD, char))v20->vfptr[95].__vecDelDtor)(
              v20,
              v3[1].mNext,
              v4->m_pSimObject,
              &hitrecord,
              0i64,
              1);
            UFG::GameStatAction::Vehicle::TireHit((UFG::SimObject *)v3[1].mNext, v4->m_pSimObject);
            UFG::HitReactionComponent::HandleHitReaction(v11, &hitrecord);
LABEL_39:
            UFG::HitRecord::~HitRecord(&hitrecord);
            return;
          }
        }
      }
    }
  }
}

// File Line: 2030
// RVA: 0x67B1A0
UFG::PhysicsVehicle *__fastcall UFG::PhysicsMoverInterface::GetRigidBody(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *result; // rax

  result = this->mPhysicsVehicle;
  if ( result )
    result = (UFG::PhysicsVehicle *)result->mRigidBody->mBody;
  return result;
}

// File Line: 2104
// RVA: 0x67B7D0
UFG::qVector3 *__fastcall UFG::PhysicsMoverInterface::GetVelocity(UFG::PhysicsMoverInterface *this, UFG::qVector3 *result)
{
  UFG::PhysicsMoverInterface *v2; // rdi
  UFG::PhysicsVehicle *v3; // rcx
  UFG::qVector3 *v4; // rbx
  UFG::qVector3 *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4

  v2 = this;
  v3 = this->mPhysicsVehicle;
  v4 = result;
  if ( !v3 || (unsigned __int8)UFG::PhysicsVehicle::IsSuspended(v3) )
  {
    v6 = UFG::qVector3::msZero.y;
    v7 = UFG::qVector3::msZero.z;
    v5 = v4;
    v4->x = UFG::qVector3::msZero.x;
    v4->y = v6;
    v4->z = v7;
  }
  else
  {
    UFG::PhysicsVehicle::GetVelocity(v2->mPhysicsVehicle, v4);
    v5 = v4;
  }
  return v5;
}

// File Line: 2116
// RVA: 0x6795C0
UFG::qVector3 *__fastcall UFG::PhysicsMoverInterface::GetAngularVelocity(UFG::PhysicsMoverInterface *this, UFG::qVector3 *result)
{
  UFG::PhysicsMoverInterface *v2; // rdi
  UFG::PhysicsVehicle *v3; // rcx
  UFG::qVector3 *v4; // rbx
  UFG::qVector3 *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4

  v2 = this;
  v3 = this->mPhysicsVehicle;
  v4 = result;
  if ( !v3 || (unsigned __int8)UFG::PhysicsVehicle::IsSuspended(v3) )
  {
    v6 = UFG::qVector3::msZero.y;
    v7 = UFG::qVector3::msZero.z;
    v5 = v4;
    v4->x = UFG::qVector3::msZero.x;
    v4->y = v6;
    v4->z = v7;
  }
  else
  {
    UFG::PhysicsVehicle::GetAngularVelocity(v2->mPhysicsVehicle, v4);
    v5 = v4;
  }
  return v5;
}

// File Line: 2128
// RVA: 0x6796B0
void __fastcall UFG::PhysicsMoverInterface::GetBoundingBoxLocalSpace(UFG::PhysicsMoverInterface *this, UFG::qVector3 *min, UFG::qVector3 *max)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  v3 = this->mBoundingBoxMin.y;
  v4 = this->mBoundingBoxMin.z;
  min->x = this->mBoundingBoxMin.x;
  min->y = v3;
  min->z = v4;
  v5 = this->mBoundingBoxMax.y;
  v6 = this->mBoundingBoxMax.z;
  max->x = this->mBoundingBoxMax.x;
  max->y = v5;
  max->z = v6;
}

// File Line: 2172
// RVA: 0x670840
char __fastcall UFG::PhysicsMoverInterface::AreAllWheelsOnGround(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *v1; // rdx
  UFG::PhysicsVehicle *v2; // rax
  char result; // al

  v1 = this->mPhysicsVehicle;
  if ( !v1 )
    goto LABEL_9;
  v2 = 0i64;
  if ( *((_BYTE *)v1 + 0x25C) & 7 )
    v2 = this->mPhysicsVehicle;
  if ( v2 )
    result = (LODWORD(v2[1].mReorientActionPitch) >> 4) & 1;
  else
LABEL_9:
    result = 1;
  return result;
}

// File Line: 2184
// RVA: 0x67BA50
float __fastcall UFG::PhysicsMoverInterface::GetWheelRadius(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *v1; // rdx
  UFG::PhysicsVehicle *v2; // rax
  float result; // xmm0_4

  v1 = this->mPhysicsVehicle;
  if ( !v1 )
    goto LABEL_9;
  v2 = 0i64;
  if ( *((_BYTE *)v1 + 604) & 7 )
    v2 = this->mPhysicsVehicle;
  if ( v2 )
    result = v2[1].mTargetTransform.v0.y;
  else
LABEL_9:
    result = FLOAT_0_27000001;
  return result;
}

// File Line: 2196
// RVA: 0x68C4E0
void __fastcall UFG::PhysicsMoverInterface::StartSlide(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsMoverInterface *v1; // rbx

  v1 = this;
  if ( !(*((_BYTE *)this + 900) & 2)
    && (unsigned int)UFG::VehicleUtility::GetVehicleOrientation((UFG::SimObjectVehicle *)this->m_pSimObject, 0, 0i64) == 5 )
  {
    *((_BYTE *)v1 + 900) |= 2u;
  }
}

// File Line: 2209
// RVA: 0x676100
void __fastcall UFG::PhysicsMoverInterface::DamageTire(UFG::PhysicsMoverInterface *this, UFG::SimObject *pAttackerSimObject, int tireIndex, float damage)
{
  __int64 v4; // rsi
  float v5; // xmm2_4
  UFG::SimObject *v6; // rdi
  UFG::PhysicsMoverInterface *v7; // rbx
  float v8; // xmm6_4
  UFG::SimObject *v9; // rax
  UFG::VehicleEffectsComponent *v10; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax

  v4 = tireIndex;
  v5 = this->mDamageState.tireDamage.array[tireIndex];
  v6 = pAttackerSimObject;
  v7 = this;
  v8 = (float)(damage * this->mDamageMultiplierTires) + v5;
  if ( v8 <= 0.0 )
  {
    v8 = 0.0;
  }
  else if ( v8 >= 1.0 )
  {
    v8 = *(float *)&FLOAT_1_0;
  }
  if ( v5 < 1.0 && v8 >= 1.0 )
  {
    v9 = this->m_pSimObject;
    if ( v9 )
    {
      v10 = (UFG::VehicleEffectsComponent *)v9->m_Components.p[32].m_pComponent;
      if ( v10 )
        UFG::VehicleEffectsComponent::BlowTire(v10, tireIndex);
    }
  }
  v7->mDamageState.tireDamage.array[v4] = v8;
  if ( v6 )
  {
    v11 = &v7->mLastDamageSource;
    if ( v7->mLastDamageSource.m_pPointer )
    {
      v12 = v11->mPrev;
      v13 = v7->mLastDamageSource.mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
      v7->mLastDamageSource.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mLastDamageSource.mPrev;
    }
    v7->mLastDamageSource.m_pPointer = v6;
    v14 = v6->m_SafePointerList.mNode.mPrev;
    v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v11->mPrev = v14;
    v7->mLastDamageSource.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  }
}

// File Line: 2222
// RVA: 0x68B710
void __fastcall UFG::PhysicsMoverInterface::SetTireDamage(UFG::PhysicsMoverInterface *this, int tireIndex, float totalDamage)
{
  float v3; // xmm6_4
  UFG::PhysicsMoverInterface *v4; // rbx
  __int64 v5; // rdi
  UFG::SimObject *v6; // rax
  UFG::VehicleEffectsComponent *v7; // rcx

  v3 = totalDamage;
  v4 = this;
  if ( totalDamage <= 0.0 )
  {
    v3 = 0.0;
  }
  else if ( totalDamage >= 1.0 )
  {
    v3 = *(float *)&FLOAT_1_0;
  }
  v5 = tireIndex;
  if ( this->mDamageState.tireDamage.array[tireIndex] < 1.0 && v3 >= 1.0 && (v6 = this->m_pSimObject) != 0i64 )
  {
    v7 = (UFG::VehicleEffectsComponent *)v6->m_Components.p[32].m_pComponent;
    if ( v7 )
      UFG::VehicleEffectsComponent::BlowTire(v7, tireIndex);
    v4->mDamageState.tireDamage.array[v5] = v3;
  }
  else
  {
    this->mDamageState.tireDamage.array[tireIndex] = v3;
  }
}

// File Line: 2243
// RVA: 0x68A5C0
void __fastcall UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(UFG::PhysicsMoverInterface *this, float damage)
{
  UFG::PhysicsMoverInterface *v2; // rbx
  float v3; // xmm7_4
  UFG::allocator::free_link *v4; // rax
  UFG::PhysicsVehicle *v5; // rax
  float v6; // xmm6_4
  UFG::GameStatTracker *v7; // rax

  v2 = this;
  if ( damage <= 0.0 )
  {
    damage = 0.0;
    goto LABEL_8;
  }
  v3 = *(float *)&FLOAT_1_0;
  if ( damage < 1.0 )
  {
LABEL_8:
    v3 = damage;
    goto LABEL_9;
  }
  if ( this->mDamageState.engineDamage < 1.0 )
  {
    v4 = UFG::qMalloc(0x50ui64, "PhysicsMoverInterface.EvtEntityDied", 0i64);
    if ( v4 )
      UFG::EvtEntityDied::EvtEntityDied((UFG::EvtEntityDied *)v4, "EVT_ENTITY_DEATH", v2->m_pSimObject);
    UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
  }
LABEL_9:
  v5 = v2->mPhysicsVehicle;
  if ( v5 )
  {
    v6 = v5->mDollarValue * (float)(v3 - v2->mDamageState.engineDamage);
    v7 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v7, PropertyDamaged, v6);
  }
  v2->mDamageState.engineDamage = v3;
}

// File Line: 2267
// RVA: 0x6757B0
__int64 __fastcall UFG::PhysicsMoverInterface::DamageEngine(UFG::PhysicsMoverInterface *this, UFG::SimObject *pAttackerSimObject, float damage, UFG::PhysicsMoverInterface::DamageType dt)
{
  float v4; // xmm7_4
  UFG::SimObjectGame *v5; // rsi
  UFG::PhysicsMoverInterface *v6; // r14
  signed int v7; // edi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::SimObject *v9; // rdx
  __int64 *v10; // rcx
  __int64 **v11; // rax
  __int64 *v12; // rax
  char v13; // r10
  unsigned int v14; // er8
  unsigned int v15; // edx
  UFG::SimObject **v16; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::AttackData *v21; // rdx
  __int64 v22; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v26; // r8
  __int64 v27; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rax
  __int32 v31; // er9
  int v32; // er9
  unsigned __int16 v33; // cx
  UFG::CharacterOccupantComponent *v34; // rax
  UFG::VehicleOccupantComponent *v35; // rbx
  unsigned __int8 v36; // r8
  UFG::SimObject *v37; // rax
  UFG::SimComponent *v38; // rdx
  UFG::SimObjectCharacter *v39; // rbx
  unsigned __int16 v40; // cx
  UFG::SimComponent *v41; // rax
  UFG::SimObject *v42; // rax
  UFG::SimComponent *v43; // rdx
  UFG::GameStatTracker *v44; // rax
  unsigned __int16 v45; // cx
  UFG::SimComponent *v46; // rax
  UFG::SimObject *v47; // rax
  UFG::SimComponent *v48; // r13
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v49; // r12
  signed __int64 v50; // rbx
  signed __int64 v51; // rax
  int i; // ecx
  unsigned int j; // er15
  UFG::SimObject *v54; // rcx
  int v55; // edx
  int v56; // er8
  signed __int64 v57; // rcx
  signed __int64 k; // rax
  signed int v59; // edx
  signed __int64 l; // rax
  signed int v61; // edx
  float v62; // xmm6_4
  float v63; // xmm0_4
  UFG::SimObject *v64; // rdx
  UFG::CopSystem *v65; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v66; // r10
  __int64 *v67; // rcx
  __int64 **v68; // rax
  __int64 *v69; // rcx
  __int64 **v70; // rax
  __int64 v71; // rcx
  __int64 *v72; // rax
  __int64 v73; // rdx
  __int64 *v74; // rcx
  __int64 *v76; // [rsp+10h] [rbp-29h]
  __int64 *v77; // [rsp+18h] [rbp-21h]
  UFG::SimObject *v78; // [rsp+20h] [rbp-19h]
  __int64 *v79; // [rsp+28h] [rbp-11h]
  __int64 **v80; // [rsp+30h] [rbp-9h]
  UFG::SimObject *v81; // [rsp+38h] [rbp-1h]
  float v82; // [rsp+40h] [rbp+7h]
  __int64 **v83; // [rsp+98h] [rbp+5Fh]
  void *retaddr; // [rsp+B8h] [rbp+7Fh]

  v4 = damage;
  v5 = (UFG::SimObjectGame *)pAttackerSimObject;
  v6 = this;
  v76 = (__int64 *)&v81;
  v77 = (__int64 *)&v81;
  v7 = 0;
  v83 = &v79;
  v79 = (__int64 *)&v79;
  v80 = &v79;
  v81 = 0i64;
  v82 = 0.0;
  v78 = pAttackerSimObject;
  if ( pAttackerSimObject )
  {
    v8 = pAttackerSimObject->m_SafePointerList.mNode.mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v76;
    v76 = (__int64 *)v8;
    v77 = (__int64 *)&pAttackerSimObject->m_SafePointerList;
    pAttackerSimObject->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v76;
  }
  v9 = this->m_pSimObject;
  if ( v81 )
  {
    v10 = v79;
    v11 = v80;
    v79[1] = (__int64)v80;
    *v11 = v10;
    v79 = (__int64 *)&v79;
    v80 = &v79;
  }
  v81 = v9;
  if ( v9 )
  {
    v12 = (__int64 *)v9->m_SafePointerList.mNode.mPrev;
    v12[1] = (__int64)&v79;
    v79 = v12;
    v80 = (__int64 **)&v9->m_SafePointerList;
    v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v79;
  }
  v13 = 0;
  v14 = UFG::PhysicsMoverInterface::s_VehicleAttacks.size;
  v15 = 0;
  if ( UFG::PhysicsMoverInterface::s_VehicleAttacks.size )
  {
    v16 = &UFG::PhysicsMoverInterface::s_VehicleAttacks.array[0].pAttacked.m_pPointer;
    do
    {
      if ( v78 == *(v16 - 3) && v81 == *v16 )
      {
        v13 = 1;
        if ( (_BYTE)retaddr )
          goto LABEL_46;
        *((_DWORD *)v16 + 2) = 0;
      }
      ++v15;
      v16 += 7;
    }
    while ( v15 < v14 );
    v14 = UFG::PhysicsMoverInterface::s_VehicleAttacks.size;
  }
  if ( v5 )
  {
    v17 = &v6->mLastDamageSource;
    if ( v6->mLastDamageSource.m_pPointer )
    {
      v18 = v17->mPrev;
      v19 = v6->mLastDamageSource.mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v17->mPrev;
      v6->mLastDamageSource.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mLastDamageSource.mPrev;
    }
    v6->mLastDamageSource.m_pPointer = (UFG::SimObject *)&v5->vfptr;
    v20 = v5->m_SafePointerList.mNode.mPrev;
    v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v17->mPrev = v20;
    v6->mLastDamageSource.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v14 = UFG::PhysicsMoverInterface::s_VehicleAttacks.size;
  }
  if ( !v13 )
  {
    v21 = &UFG::PhysicsMoverInterface::s_VehicleAttacks.array[v14];
    UFG::PhysicsMoverInterface::s_VehicleAttacks.size = v14 + 1;
    v22 = (__int64)v78;
    if ( v21->pAttacker.m_pPointer )
    {
      v23 = v21->pAttacker.mPrev;
      v24 = v21->pAttacker.mNext;
      v23->mNext = v24;
      v24->mPrev = v23;
      v21->pAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v21->pAttacker.mPrev;
      v21->pAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v21->pAttacker.mPrev;
    }
    v21->pAttacker.m_pPointer = (UFG::SimObject *)v22;
    if ( v22 )
    {
      v25 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v22 + 8);
      v25->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v21->pAttacker.mPrev;
      v21->pAttacker.mPrev = v25;
      v21->pAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v22 + 8);
      *(_QWORD *)(v22 + 8) = v21;
    }
    v26 = &v21->pAttacked;
    v27 = (__int64)v81;
    if ( v21->pAttacked.m_pPointer )
    {
      v28 = v26->mPrev;
      v29 = v21->pAttacked.mNext;
      v28->mNext = v29;
      v29->mPrev = v28;
      v26->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v26->mPrev;
      v21->pAttacked.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v21->pAttacked.mPrev;
    }
    v21->pAttacked.m_pPointer = (UFG::SimObject *)v27;
    if ( v27 )
    {
      v30 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v27 + 8);
      v30->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v26->mPrev;
      v26->mPrev = v30;
      v21->pAttacked.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v27 + 8);
      *(_QWORD *)(v27 + 8) = v26;
    }
    v21->fElapsedTime = v82;
  }
  if ( dt == dtWORLD_COLLISION )
  {
    v4 = damage * v6->mDamageMultiplierWorldCollisions;
    goto LABEL_83;
  }
  v31 = dt - 1;
  if ( v31 )
  {
    v32 = v31 - 1;
    if ( v32 )
    {
      if ( v32 == 1 )
        v4 = damage * v6->mDamageMultiplierAttack;
    }
    else
    {
      if ( !v5 )
        goto LABEL_130;
      v33 = v5->m_Flags;
      if ( (v33 >> 14) & 1 )
      {
        v34 = (UFG::CharacterOccupantComponent *)v5->m_Components.p[44].m_pComponent;
      }
      else if ( (v33 & 0x8000u) == 0 )
      {
        if ( (v33 >> 13) & 1 )
        {
          v34 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v5,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
        else if ( (v33 >> 12) & 1 )
        {
          v34 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v5,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
        else
        {
          v34 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v5->vfptr,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
      }
      else
      {
        v34 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v5,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
      if ( v34 )
      {
        v35 = (UFG::VehicleOccupantComponent *)v6->m_pSimObject;
        if ( UFG::CharacterOccupantComponent::GetCurrentVehicle(v34) == v35 )
        {
LABEL_46:
          v36 = 0;
          goto LABEL_123;
        }
      }
      v37 = v6->m_pSimObject;
      if ( v37
        && (v38 = v37->m_Components.p[30].m_pComponent) != 0i64
        && UFG::AreCharactersAllied((UFG::SimObject *)&v5->vfptr, v38[1].m_pSimObject) )
      {
        v4 = 0.0;
      }
      else
      {
LABEL_130:
        v4 = damage * v6->mDamageMultiplierBullets;
      }
    }
  }
  else
  {
    v39 = (UFG::SimObjectCharacter *)v5;
    if ( v5 )
    {
      v40 = v5->m_Flags;
      if ( (v40 >> 14) & 1 )
      {
        v41 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::VehicleOccupantComponent::_TypeUID);
      }
      else if ( (v40 & 0x8000u) == 0 )
      {
        if ( (v40 >> 13) & 1 )
          v41 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::VehicleOccupantComponent::_TypeUID);
        else
          v41 = (v40 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::VehicleOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
      }
      else
      {
        v41 = v5->m_Components.p[30].m_pComponent;
      }
      if ( v41 )
        v39 = (UFG::SimObjectCharacter *)v41[1].m_pSimObject;
    }
    v42 = v6->m_pSimObject;
    if ( v42
      && (v43 = v42->m_Components.p[30].m_pComponent) != 0i64
      && UFG::AreCharactersAllied((UFG::SimObject *)&v39->vfptr, v43[1].m_pSimObject) )
    {
      v4 = 0.0;
    }
    else
    {
      v4 = damage * v6->mDamageMultiplierVehicleCollisions;
      if ( v39 )
      {
        if ( v39 == LocalPlayer )
        {
          v44 = UFG::GameStatTracker::Instance();
          if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v44, 0) == 1 )
          {
            if ( v5 )
            {
              v45 = v5->m_Flags;
              if ( !((v45 >> 14) & 1) )
              {
                if ( (v45 & 0x8000u) == 0 )
                {
                  if ( (v45 >> 13) & 1 )
                    goto LABEL_83;
                  if ( (v45 >> 12) & 1 )
                    v46 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::PhysicsMoverInterface::_TypeUID);
                  else
                    v46 = UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)&v5->vfptr,
                            UFG::PhysicsMoverInterface::_TypeUID);
                }
                else
                {
                  v46 = v5->m_Components.p[34].m_pComponent;
                }
                if ( v46 && BYTE4(v46[14].vfptr) & 8 )
                  v4 = v4 * *(float *)&v46[13].m_TypeUID;
                goto LABEL_83;
              }
            }
          }
        }
      }
    }
  }
LABEL_83:
  v47 = v6->m_pSimObject;
  if ( v47 )
  {
    v48 = v47->m_Components.p[30].m_pComponent;
    if ( v48 )
    {
      v49 = &v48[1].m_BoundComponentHandles.mNode.mNext;
      v50 = (signed __int64)&v48->m_BoundComponentHandles;
      v51 = (signed __int64)&v48[1].m_BoundComponentHandles.mNode.mNext[-4];
      if ( v48[1].m_pSimObject )
      {
        for ( i = 0; v51 != v50; v51 = *(_QWORD *)(v51 + 72) - 64i64 )
          ++i;
        j = i + 1;
      }
      else
      {
        for ( j = 0; v51 != v50; v51 = *(_QWORD *)(v51 + 72) - 64i64 )
          ++j;
      }
      if ( j )
      {
        do
        {
          v54 = v48[1].m_pSimObject;
          if ( v54 )
          {
            if ( !v7 )
              goto LABEL_109;
            v55 = v7 - 1;
            v56 = 0;
            v57 = (signed __int64)&(*v49)[-4];
            for ( k = v57; k != v50; k = *(_QWORD *)(k + 72) - 64i64 )
              ++v56;
            if ( v55 < v56 )
            {
              for ( ; v55 > 0; v57 = *(_QWORD *)(v57 + 72) - 64i64 )
              {
                if ( v57 == v50 )
                  break;
                --v55;
              }
LABEL_100:
              v54 = *(UFG::SimObject **)(v57 + 40);
              goto LABEL_109;
            }
          }
          else
          {
            v59 = 0;
            v57 = (signed __int64)&(*v49)[-4];
            for ( l = v57; l != v50; l = *(_QWORD *)(l + 72) - 64i64 )
              ++v59;
            if ( v7 < v59 )
            {
              v61 = v7;
              if ( v7 > 0 )
              {
                while ( v57 != v50 )
                {
                  --v61;
                  v57 = *(_QWORD *)(v57 + 72) - 64i64;
                  if ( v61 <= 0 )
                  {
                    v54 = *(UFG::SimObject **)(v57 + 40);
                    goto LABEL_109;
                  }
                }
              }
              goto LABEL_100;
            }
          }
          v54 = 0i64;
LABEL_109:
          if ( UFG::IsAnyLocalPlayer(v54) )
          {
            v4 = v4 * 0.2;
            break;
          }
          ++v7;
        }
        while ( v7 < j );
      }
    }
  }
  v62 = v6->mDamageState.engineDamage;
  UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(v6, v6->mDamageState.engineDamage + v4);
  v63 = v6->mDamageState.engineDamage;
  if ( v63 < UFG::PhysicsMoverInterface::mIgnoreRipenessTakedownThreshold )
  {
    if ( v62 < UFG::PhysicsMoverInterface::mRipeForTakedownThreshold
      || v63 < UFG::PhysicsMoverInterface::mRipeForTakedownThreshold )
    {
      *((_BYTE *)v6 + 900) &= 0xFBu;
    }
    else
    {
      *((_BYTE *)v6 + 900) |= 4u;
    }
  }
  else
  {
    *((_BYTE *)v6 + 900) |= 4u;
  }
  if ( v62 != 1.0 && v63 == 1.0 )
  {
    v64 = v6->m_pSimObject;
    _((AMD_HD3D *)&UFG::PoliceScannerAudio::sm_Instance);
  }
  v65 = UFG::CopSystem::Instance();
  v66 = v65->vfptr;
  LOBYTE(v79) = 1;
  v78 = 0i64;
  ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObjectGame *, UFG::SimObject *, _QWORD))v66[95].__vecDelDtor)(
    v65,
    v5,
    v6->m_pSimObject,
    0i64);
  v36 = 1;
LABEL_123:
  v83 = &v79;
  if ( v81 )
  {
    v67 = v79;
    v68 = v80;
    v79[1] = (__int64)v80;
    *v68 = v67;
    v79 = (__int64 *)&v79;
    v80 = &v79;
  }
  v81 = 0i64;
  v69 = v79;
  v70 = v80;
  v79[1] = (__int64)v80;
  *v70 = v69;
  v79 = (__int64 *)&v79;
  v80 = &v79;
  v83 = &v76;
  if ( v78 )
  {
    v71 = (__int64)v76;
    v72 = v77;
    v76[1] = (__int64)v77;
    *v72 = v71;
    v76 = (__int64 *)&v76;
    v77 = (__int64 *)&v76;
  }
  v73 = (__int64)v76;
  v74 = v77;
  v76[1] = (__int64)v77;
  *v74 = v73;
  return v36;
}68 = v80;
    v79[1] = (__int64)v80;
    *v68 = v67;
    v79 = (__int64 *)&v79;
    v80 = &v79;

// File Line: 2552
// RVA: 0x6741F0
bool __fastcall UFG::PhysicsMoverInterface::CanApplySpeedBoostRewardFromVehicleTakedown(UFG::PhysicsMoverInterface *this)
{
  return 5.0 < this->mSecondsSinceAppliedSpeedBoostRewardFromVehicleTakedown;
}

// File Line: 2561
// RVA: 0x67B3D0
float __fastcall UFG::PhysicsMoverInterface::GetTireDamage(UFG::PhysicsMoverInterface *this, int tireIndex)
{
  return this->mDamageState.tireDamage.array[tireIndex];
}

// File Line: 2568
// RVA: 0x67F590
bool __fastcall UFG::PhysicsMoverInterface::IsTireBlown(UFG::PhysicsMoverInterface *this, int tireIndex)
{
  return 1.0 <= this->mDamageState.tireDamage.array[tireIndex];
}

// File Line: 2575
// RVA: 0x67A630
float __fastcall UFG::PhysicsMoverInterface::GetEngineDamage(UFG::PhysicsMoverInterface *this)
{
  return this->mDamageState.engineDamage;
}

// File Line: 2583
// RVA: 0x6899D0
void __fastcall UFG::PhysicsMoverInterface::RepairDamage(UFG::PhysicsMoverInterface *this)
{
  this->mSecondsEngineHasBeenDeteriorating = -1.0;
  *(_QWORD *)this->mDamageState.tireDamage.array = 0i64;
  *(_QWORD *)&this->mDamageState.tireDamage.array[2] = 0i64;
  this->mDamageState.engineDamage = 0.0;
}

// File Line: 2591
// RVA: 0x677920
void __fastcall UFG::PhysicsMoverInterface::EnableSuperStop(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *v1; // rax

  v1 = this->mPhysicsVehicle;
  if ( v1 )
    *((_DWORD *)v1 + 151) |= 8u;
}

// File Line: 2611
// RVA: 0x685E40
void __fastcall UFG::PhysicsMoverInterface::OverrideSuperStopDrag(UFG::PhysicsMoverInterface *this, bool bOverride, float fDrag)
{
  UFG::PhysicsVehicle *v3; // rcx

  v3 = this->mPhysicsVehicle;
  if ( v3 )
  {
    if ( bOverride )
      v3->mSuperStopDrag = fDrag;
    else
      UFG::PhysicsVehicle::RestoreSuperStopDrag(v3);
  }
}

// File Line: 2628
// RVA: 0x6795A0
void __fastcall UFG::PhysicsMoverInterface::FlipVehicle(UFG::PhysicsMoverInterface *this, float torqueFactor, UFG::qVector3 *collisionPoint)
{
  JUMPOUT(this->mPhysicsVehicle, 0i64, UFG::PhysicsVehicle::FlipVehicle);
}

// File Line: 2638
// RVA: 0x67A6C0
float __fastcall UFG::PhysicsMoverInterface::GetHalfSteeringRange(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *v1; // rcx
  float result; // xmm0_4

  v1 = this->mPhysicsVehicle;
  if ( !v1 )
    return FLOAT_0_78539819;
  ((void (*)(void))v1->vfptr[5].__vecDelDtor)();
  return result;
}

// File Line: 2645
// RVA: 0x670FE0
void __fastcall UFG::PhysicsMoverInterface::AutoDeteriorateEngineIfNotAlready(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsMoverInterface *v1; // rbx
  UFG::SimObject *v2; // rcx

  v1 = this;
  if ( this->mSecondsEngineHasBeenDeteriorating < 0.0 )
  {
    UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(this, this->mAutoDeterioratingDamageThreshold);
    v2 = v1->m_pSimObject;
    v1->mSecondsEngineHasBeenDeteriorating = 0.0;
    UFG::PhysicsMoverInterface_EmitVehicleDisabledEvent(v2);
  }
}

// File Line: 2658
// RVA: 0x68D360
void __fastcall UFG::PhysicsMoverInterface::TriggerExplosion(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsMoverInterface *v1; // rsi
  UFG::PhysicsVehicle *v2; // rcx
  UFG::PhysicsVehicle *v3; // rax
  int i; // ebx
  UFG::PhysicsVehicle *v5; // rcx
  UFG::WaterFloatingTrackerComponent *v6; // rcx
  UFG::SimObject *v7; // rax
  UFG::TransformNodeComponent *v8; // rbx
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::ExplosionTypeInfo *v11; // r12
  UFG::SimObject *v12; // rcx
  UFG::SimComponentHolder *v13; // rcx
  UFG::SimComponent *v14; // r14
  int v15; // er15
  int v16; // edi
  UFG::SimObjectGame *v17; // rcx
  int v18; // edx
  int v19; // er9
  signed __int64 v20; // rcx
  signed __int64 v21; // rax
  signed __int64 j; // r8
  int v23; // edx
  signed __int64 v24; // rax
  signed __int64 k; // r8
  int l; // edx
  unsigned __int16 v27; // dx
  UFG::HitReactionComponent *v28; // rbx
  UFG::SimComponent *v29; // rax
  UFG::SimObject *v30; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::SimObject *v34; // rax
  UFG::VehicleEffectsComponent *v35; // rcx
  UFG::qVector3 pos; // [rsp+30h] [rbp-A8h]
  __int64 v37; // [rsp+40h] [rbp-98h]
  UFG::HitRecord hitrecord; // [rsp+50h] [rbp-88h]

  v37 = -2i64;
  v1 = this;
  *((_BYTE *)this + 900) &= 0xEFu;
  if ( this->mDestructState != 2 )
  {
    UFG::PhysicsMoverInterface_EmitVehicleDisabledEvent(this->m_pSimObject);
    UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(v1, 1.0);
    v2 = v1->mPhysicsVehicle;
    if ( v2 )
    {
      v3 = 0i64;
      if ( *((_BYTE *)v2 + 604) & 7 )
        v3 = v1->mPhysicsVehicle;
      if ( v3 )
      {
        for ( i = 0; i < v1->mNumWheels; ++i )
          UFG::PhysicsMoverInterface::SetTireDamage(v1, i, 1.0);
      }
    }
    v5 = v1->mPhysicsVehicle;
    if ( v5 && (*((_DWORD *)v5 + 151) & 7) == 2 )
      BYTE1(v5[2].mUserData.simComponent.mPrev) = 1;
    if ( !(*((_BYTE *)v1 + 896) & 0x10) )
    {
      v6 = v1->mPhysicsVehicle->mWaterFloatingTrackerComponent;
      if ( !v6 || !UFG::WaterFloatingTrackerComponent::IsSubmerged(v6, 0.64999998) )
      {
        if ( v1->mPropertySetExplosion.mUID != -1 )
        {
          UFG::PhysicsMoverInterface::LockHighLod(v1, ELODLockMode_UNTIL_AT_REST, 0.0);
          v7 = v1->m_pSimObject;
          v8 = (UFG::TransformNodeComponent *)(v7 ? v7->m_Components.p[2].m_pComponent : 0i64);
          UFG::TransformNodeComponent::UpdateWorldTransform(v8);
          v9 = v8->mWorldTransform.v3.y;
          v10 = v8->mWorldTransform.v3.z;
          pos.x = v8->mWorldTransform.v3.x;
          pos.y = v9;
          pos.z = v10 + 0.5;
          UFG::ExplosionManager::CreateExplosion(
            &pos,
            &v1->mPropertySetExplosion,
            v1->m_pSimObject,
            v1->mLastDamageSource.m_pPointer);
          v11 = UFG::ExplosionManager::GetExplosionTypeInfo(&v1->mPropertySetExplosion);
          UFG::GameStatAction::Vehicle::Explosion(v1->m_pSimObject);
          v12 = v1->m_pSimObject;
          if ( v12 )
          {
            v13 = v12->m_Components.p;
            v14 = v13[30].m_pComponent;
            if ( v14 )
            {
              v15 = UFG::VehicleOccupantComponent::GetNumberOfOccupants((UFG::VehicleOccupantComponent *)v13[30].m_pComponent);
              v16 = 0;
              if ( v15 > 0 )
              {
                while ( 1 )
                {
                  v17 = (UFG::SimObjectGame *)v14[1].m_pSimObject;
                  if ( !v17 )
                    break;
                  if ( v16 )
                  {
                    v18 = v16 - 1;
                    v19 = 0;
                    v20 = (signed __int64)&v14[1].m_BoundComponentHandles.mNode.mNext[-4];
                    v21 = v20;
                    for ( j = (signed __int64)&v14->m_BoundComponentHandles; v21 != j; v21 = *(_QWORD *)(v21 + 72)
                                                                                           - 64i64 )
                      ++v19;
                    if ( v18 >= v19 )
                      goto LABEL_54;
                    for ( ; v18 > 0; v20 = *(_QWORD *)(v20 + 72) - 64i64 )
                    {
                      if ( v20 == j )
                        break;
                      --v18;
                    }
                    goto LABEL_36;
                  }
LABEL_37:
                  if ( v17 )
                  {
                    v27 = v17->m_Flags;
                    if ( (v27 >> 14) & 1 )
                    {
                      v28 = (UFG::HitReactionComponent *)v17->m_Components.p[15].m_pComponent;
                    }
                    else if ( (v27 & 0x8000u) == 0 )
                    {
                      if ( (v27 >> 13) & 1 )
                        v29 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::HitReactionComponent::_TypeUID);
                      else
                        v29 = (v27 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v17,
                                                  UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                           (UFG::SimObject *)&v17->vfptr,
                                                                                           UFG::HitReactionComponent::_TypeUID);
                      v28 = (UFG::HitReactionComponent *)v29;
                    }
                    else
                    {
                      v28 = (UFG::HitReactionComponent *)v17->m_Components.p[15].m_pComponent;
                    }
                    if ( v28 )
                    {
                      UFG::HitRecord::HitRecord(&hitrecord);
                      v30 = v1->m_pSimObject;
                      hitrecord.mAttackTypeID = gAttackCollisionExplosion.m_EnumValue;
                      hitrecord.mDamage = 100;
                      if ( hitrecord.mAttacker.m_pPointer )
                      {
                        v31 = hitrecord.mAttacker.mPrev;
                        v32 = hitrecord.mAttacker.mNext;
                        hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
                        v32->mPrev = v31;
                        hitrecord.mAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                        hitrecord.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                      }
                      hitrecord.mAttacker.m_pPointer = v30;
                      if ( v30 )
                      {
                        v33 = v30->m_SafePointerList.mNode.mPrev;
                        v33->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                        hitrecord.mAttacker.mPrev = v33;
                        hitrecord.mAttacker.mNext = &v30->m_SafePointerList.mNode;
                        v30->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                      }
                      *(_QWORD *)&hitrecord.mTimeSinceHit = 0i64;
                      hitrecord.mCollisionInfo.mOtherVelocity.x = 0.0;
                      *(_QWORD *)&hitrecord.mCollisionInfo.mOtherVelocity.z = v11;
                      hitrecord.mProjectileInfo.m_pSOWPC.mPrev = 0i64;
                      hitrecord.mProjectileInfo.m_pSOWPC.mNext = 0i64;
                      hitrecord.mProjectileInfo.m_pSOWPC.m_pPointer = 0i64;
                      hitrecord.mProjectileInfo.m_pSubTargetingLocation = 0i64;
                      *(float *)&hitrecord.mProjectileInfo.m_bIsFullyAccurate = UFG::qVector3::msZero.x;
                      *(float *)(&hitrecord.mProjectileInfo.m_bIsHardLocked + 3) = UFG::qVector3::msZero.y;
                      hitrecord.mCollisionInfo.mPhysicsObjectPropertyHandleUID = __PAIR__(
                                                                                   LODWORD(UFG::qVector3::msZero.x),
                                                                                   LODWORD(UFG::qVector3::msZero.z));
                      hitrecord.mCollisionInfo.mAttackerPhysicsObjectPropertyHandleUID = *(_QWORD *)&UFG::qVector3::msZero.y;
                      *(UFG::qVector3 *)&hitrecord.mCollisionInfo.mSurfacePropertyHandleUID = UFG::qVector3::msZero;
                      *(unsigned __int64 *)((char *)&hitrecord.mCollisionInfo.mAttackerSurfacePropertyHandleUID + 4) = 0i64;
                      hitrecord.mCollisionInfo.mHitLocation.y = -1.0;
                      UFG::HitReactionComponent::HandleHitReaction(v28, &hitrecord);
                      UFG::HitRecord::~HitRecord(&hitrecord);
                    }
                  }
LABEL_54:
                  if ( ++v16 >= v15 )
                    goto LABEL_55;
                }
                v23 = 0;
                v20 = (signed __int64)&v14[1].m_BoundComponentHandles.mNode.mNext[-4];
                v24 = v20;
                for ( k = (signed __int64)&v14->m_BoundComponentHandles; v24 != k; v24 = *(_QWORD *)(v24 + 72) - 64i64 )
                  ++v23;
                if ( v16 >= v23 )
                  goto LABEL_54;
                for ( l = v16; l > 0; v20 = *(_QWORD *)(v20 + 72) - 64i64 )
                {
                  if ( v20 == k )
                    break;
                  --l;
                }
LABEL_36:
                v17 = *(UFG::SimObjectGame **)(v20 + 40);
                goto LABEL_37;
              }
            }
          }
        }
LABEL_55:
        v34 = v1->m_pSimObject;
        if ( v34 )
        {
          v35 = (UFG::VehicleEffectsComponent *)v34->m_Components.p[32].m_pComponent;
          if ( v35 )
            UFG::VehicleEffectsComponent::TurnOnDestroyedEffect(v35);
        }
      }
    }
    v1->mDestructState = 2;
  }
}

// File Line: 2741
// RVA: 0x68A470
void __fastcall UFG::PhysicsMoverInterface::SetCannotExplode(UFG::PhysicsMoverInterface *this, bool cannotExplode)
{
  *((_DWORD *)this + 0xE0) &= 0xFFFFFFEF;
  *((_DWORD *)this + 0xE0) |= 16 * (cannotExplode != 0);
}

// File Line: 2768
// RVA: 0x67A780
float __fastcall UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *v1; // rax
  hkpRigidBody *v2; // rdx
  __m128 v3; // xmm2

  v1 = this->mPhysicsVehicle;
  if ( !v1 )
    return this->mForwardSpeed * 3.5999999;
  v2 = v1->mRigidBody->mBody;
  if ( !v2 )
    return this->mForwardSpeed * 3.5999999;
  v3 = (__m128)v2->m_motion.m_linearVelocity.m_quad.m128_u32[0];
  v3.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0])
                         + (float)(v2->m_motion.m_linearVelocity.m_quad.m128_f32[1]
                                 * v2->m_motion.m_linearVelocity.m_quad.m128_f32[1]))
                 + (float)(v2->m_motion.m_linearVelocity.m_quad.m128_f32[2]
                         * v2->m_motion.m_linearVelocity.m_quad.m128_f32[2]);
  return COERCE_FLOAT(_mm_sqrt_ps(v3)) * 3.5999999;
}

// File Line: 2775
// RVA: 0x67A720
float __fastcall UFG::PhysicsMoverInterface::GetLinearVelocityMagnitude(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *v1; // rax
  hkpRigidBody *v2; // rdx
  __m128 v3; // xmm2
  float result; // xmm0_4

  v1 = this->mPhysicsVehicle;
  if ( !v1 )
    return this->mForwardSpeed;
  v2 = v1->mRigidBody->mBody;
  if ( !v2 )
    return this->mForwardSpeed;
  v3 = (__m128)v2->m_motion.m_linearVelocity.m_quad.m128_u32[0];
  v3.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0])
                         + (float)(v2->m_motion.m_linearVelocity.m_quad.m128_f32[1]
                                 * v2->m_motion.m_linearVelocity.m_quad.m128_f32[1]))
                 + (float)(v2->m_motion.m_linearVelocity.m_quad.m128_f32[2]
                         * v2->m_motion.m_linearVelocity.m_quad.m128_f32[2]);
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v3);
  return result;
}

// File Line: 2788
// RVA: 0x681EF0
void __fastcall UFG::PhysicsMoverInterface::NotifyProxyModeChanged(UFG::PhysicsMoverInterface *this, UFG::SimObject::eProxyMode proxyMode)
{
  UFG::PhysicsVehicle *v2; // r8

  v2 = this->mPhysicsVehicle;
  if ( v2 )
    v2->mIsProxy = proxyMode == 2;
}

// File Line: 2797
// RVA: 0x694FB0
void __fastcall UFG::PhysicsMoverInterface::UpdateAttacks(float delta_sec)
{
  float v1; // xmm7_4
  unsigned int v2; // ebx
  __int64 v3; // rcx
  float v4; // xmm0_4
  UFG::AttackData *v5; // rdx
  __int64 v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // r8
  __int64 v11; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  unsigned int v15; // eax
  __int64 *v16; // rcx
  __int64 **v17; // rax
  __int64 *v18; // rcx
  __int64 **v19; // rax
  __int64 *v20; // rcx
  __int64 **v21; // rax
  __int64 *v22; // rcx
  __int64 **v23; // rax
  __int64 *v24; // [rsp+28h] [rbp-58h]
  __int64 **v25; // [rsp+30h] [rbp-50h]
  __int64 v26; // [rsp+38h] [rbp-48h]
  __int64 *v27; // [rsp+40h] [rbp-40h]
  __int64 **v28; // [rsp+48h] [rbp-38h]
  __int64 v29; // [rsp+50h] [rbp-30h]
  float v30; // [rsp+58h] [rbp-28h]

  v1 = delta_sec;
  v24 = (__int64 *)&v24;
  v25 = &v24;
  v26 = 0i64;
  v27 = (__int64 *)&v27;
  v28 = &v27;
  v29 = 0i64;
  v30 = 0.0;
  v2 = 0;
  if ( UFG::PhysicsMoverInterface::s_VehicleAttacks.size > 0 )
  {
    do
    {
      v3 = v2;
      v4 = v1 + UFG::PhysicsMoverInterface::s_VehicleAttacks.array[v3].fElapsedTime;
      UFG::PhysicsMoverInterface::s_VehicleAttacks.array[v3].fElapsedTime = v4;
      if ( v4 <= 0.75 )
      {
        ++v2;
        v15 = UFG::PhysicsMoverInterface::s_VehicleAttacks.size;
      }
      else
      {
        UFG::AttackData::operator=(
          &UFG::PhysicsMoverInterface::s_VehicleAttacks.array[v3],
          &UFG::PhysicsMoverInterface::s_VehicleAttacks.array[UFG::PhysicsMoverInterface::s_VehicleAttacks.size - 1]);
        v5 = &UFG::PhysicsMoverInterface::s_VehicleAttacks.array[UFG::PhysicsMoverInterface::s_VehicleAttacks.size - 1];
        v6 = v26;
        if ( v5->pAttacker.m_pPointer )
        {
          v7 = v5->pAttacker.mPrev;
          v8 = v5->pAttacker.mNext;
          v7->mNext = v8;
          v8->mPrev = v7;
          v5->pAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->pAttacker.mPrev;
          v5->pAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->pAttacker.mPrev;
        }
        v5->pAttacker.m_pPointer = (UFG::SimObject *)v6;
        if ( v6 )
        {
          v9 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v6 + 8);
          v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->pAttacker.mPrev;
          v5->pAttacker.mPrev = v9;
          v5->pAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v6 + 8);
          *(_QWORD *)(v6 + 8) = v5;
        }
        v10 = &v5->pAttacked;
        v11 = v29;
        if ( v5->pAttacked.m_pPointer )
        {
          v12 = v10->mPrev;
          v13 = v5->pAttacked.mNext;
          v12->mNext = v13;
          v13->mPrev = v12;
          v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
          v5->pAttacked.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->pAttacked.mPrev;
        }
        v5->pAttacked.m_pPointer = (UFG::SimObject *)v11;
        if ( v11 )
        {
          v14 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v11 + 8);
          v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
          v10->mPrev = v14;
          v5->pAttacked.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v11 + 8);
          *(_QWORD *)(v11 + 8) = v10;
        }
        v5->fElapsedTime = v30;
        v15 = UFG::PhysicsMoverInterface::s_VehicleAttacks.size-- - 1;
      }
    }
    while ( v2 < v15 );
  }
  if ( v29 )
  {
    v16 = v27;
    v17 = v28;
    v27[1] = (__int64)v28;
    *v17 = v16;
    v27 = (__int64 *)&v27;
    v28 = &v27;
  }
  v29 = 0i64;
  v18 = v27;
  v19 = v28;
  v27[1] = (__int64)v28;
  *v19 = v18;
  v27 = (__int64 *)&v27;
  v28 = &v27;
  if ( v26 )
  {
    v20 = v24;
    v21 = v25;
    v24[1] = (__int64)v25;
    *v21 = v20;
    v24 = (__int64 *)&v24;
    v25 = &v24;
  }
  v22 = v24;
  v23 = v25;
  v24[1] = (__int64)v25;
  *v23 = v22;
}

// File Line: 2823
// RVA: 0x6875A0
void UFG::PhysicsMoverInterface::PostFreemanUpdate(void)
{
  UFG::PhysicsMoverInterface *v0; // rcx
  UFG::PhysicsMoverInterface *v1; // rbx

  v0 = (UFG::PhysicsMoverInterface *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( &UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> **)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72) )
  {
    do
    {
      v1 = (UFG::PhysicsMoverInterface *)&v0->mNext[-5].mNext;
      if ( *((_BYTE *)v0 + 900) & 0x10 )
        UFG::PhysicsMoverInterface::TriggerExplosion(v0);
      v0 = v1;
    }
    while ( v1 != (UFG::PhysicsMoverInterface *)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72) );
  }
}

// File Line: 2845
// RVA: 0x67E8B0
void __fastcall UFG::PhysicsMoverInterface::InitiateRamming(UFG::PhysicsMoverInterface *this, UFG::RammingState *rs)
{
  UFG::RammingState *v2; // rdi
  UFG::PhysicsMoverInterface *v3; // rbx
  UFG::RammingState *v4; // rcx
  UFG::allocator::free_link *v5; // rax
  float *v6; // rax

  v2 = rs;
  v3 = this;
  v4 = this->mRammingState;
  if ( v4 )
  {
    v4->mState = 0;
    v3->mRammingState->mForwardSpeedPenaltyPercent = v3->mRammingState->mForwardSpeedPenaltyPercent * 0.30000001;
    v6 = (float *)v3->mRammingState;
    v6[10] = v6[10] * 0.89999998;
    v6[11] = v6[11] * 0.89999998;
    v6[12] = v6[12] * 0.89999998;
  }
  else
  {
    v5 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
    if ( v5 )
      UFG::RammingState::RammingState((UFG::RammingState *)v5, v2);
    v3->mRammingState = (UFG::RammingState *)v5;
  }
}

// File Line: 2869
// RVA: 0x66A330
void __fastcall UFG::RammingState::RammingState(UFG::RammingState *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4

  this->mTarget.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mTarget.mPrev;
  this->mTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mTarget.mPrev;
  this->mTarget.m_pPointer = 0i64;
  this->mState = 0;
  v1 = UFG::qVector3::msZero.y;
  v2 = UFG::qVector3::msZero.z;
  this->mCounterSpin.x = UFG::qVector3::msZero.x;
  this->mCounterSpin.y = v1;
  this->mCounterSpin.z = v2;
  this->mOriginalForwardSpeedKPH = 0.0;
}

// File Line: 2875
// RVA: 0x66A1F0
void __fastcall UFG::RammingState::RammingState(UFG::RammingState *this, UFG::RammingState *rs)
{
  UFG::RammingState *v2; // r8
  UFG::SimObject *v3; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4

  v2 = this;
  this->mTarget.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mTarget.mPrev;
  this->mTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mTarget.mPrev;
  this->mTarget.m_pPointer = 0i64;
  v3 = rs->mTarget.m_pPointer;
  if ( this->mTarget.m_pPointer )
  {
    v4 = this->mTarget.mPrev;
    v5 = v2->mTarget.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mTarget.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mTarget.mPrev;
    v2->mTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mTarget.mPrev;
  }
  v2->mTarget.m_pPointer = v3;
  if ( v3 )
  {
    v6 = v3->m_SafePointerList.mNode.mPrev;
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mTarget.mPrev;
    v2->mTarget.mPrev = v6;
    v2->mTarget.mNext = &v3->m_SafePointerList.mNode;
    v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mTarget.mPrev;
  }
  v2->mState = rs->mState;
  v7 = rs->mCounterSpin.y;
  v8 = rs->mCounterSpin.z;
  v2->mCounterSpin.x = rs->mCounterSpin.x;
  v2->mCounterSpin.y = v7;
  v2->mCounterSpin.z = v8;
  v9 = rs->mVelocityToAdd.y;
  v10 = rs->mVelocityToAdd.z;
  v2->mVelocityToAdd.x = rs->mVelocityToAdd.x;
  v2->mVelocityToAdd.y = v9;
  v2->mVelocityToAdd.z = v10;
  v11 = rs->mMotionIntentionDirection.y;
  v12 = rs->mMotionIntentionDirection.z;
  v2->mMotionIntentionDirection.x = rs->mMotionIntentionDirection.x;
  v2->mMotionIntentionDirection.y = v11;
  v2->mMotionIntentionDirection.z = v12;
  v2->mForwardsness = rs->mForwardsness;
  v2->mOriginalForwardSpeedKPH = rs->mOriginalForwardSpeedKPH;
  v2->mMinForwardSpeedKPH = rs->mMinForwardSpeedKPH;
  v2->mMaxForwardSpeedKPH = rs->mMaxForwardSpeedKPH;
  v2->mMinAddSpeedKPH = rs->mMinAddSpeedKPH;
  v2->mMaxAddSpeedKPH = rs->mMaxAddSpeedKPH;
  v2->mForwardSpeedPenaltyPercent = rs->mForwardSpeedPenaltyPercent;
  v2->mForwardSpeedPenaltyDecelKPHPS = rs->mForwardSpeedPenaltyDecelKPHPS;
  v2->mNoTargetModifier = rs->mNoTargetModifier;
  v2->mCounterSwerveModifier = rs->mCounterSwerveModifier;
  v2->mSwerveImpulse = rs->mSwerveImpulse;
  v2->mTargetMaxDistance = rs->mTargetMaxDistance;
  v2->mTargetForwardsVelocityModifier = rs->mTargetForwardsVelocityModifier;
  v2->mTargetAngle = rs->mTargetAngle;
}

// File Line: 2909
// RVA: 0x6934E0
char __fastcall UFG::RammingState::Update(UFG::RammingState *this, UFG::PhysicsMoverInterface *pmi, float timestep)
{
  UFG::PhysicsVehicle *v3; // rax
  UFG::SimComponent *v4; // rbp
  UFG::PhysicsMoverInterface *v5; // rsi
  UFG::RammingState *v6; // rbx
  hkpEntity *v7; // rdi
  UFG::RammingState::ERamState v8; // ecx
  int v9; // ecx
  int v10; // ecx
  float v12; // xmm3_4
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm6
  UFG::SimObject *v24; // rax
  float v25; // xmm1_4
  __m128 v26; // xmm7
  __m128 v27; // xmm5
  __m128 v28; // xmm6
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  __m128 v34; // [rsp+20h] [rbp-48h]
  __m128 v35; // [rsp+30h] [rbp-38h]

  v3 = pmi->mPhysicsVehicle;
  v4 = 0i64;
  v5 = pmi;
  v6 = this;
  if ( v3 )
    v7 = (hkpEntity *)&v3->mRigidBody->mBody->vfptr;
  else
    v7 = 0i64;
  v8 = this->mState;
  if ( v8 )
  {
    v9 = v8 - 1;
    if ( v9 )
    {
      v10 = v9 - 1;
      if ( v10 )
      {
        if ( v10 == 1 )
        {
          *((_BYTE *)pmi + 900) &= 0xF7u;
          return 1;
        }
      }
      else
      {
        v13 = (__m128)(unsigned int)FLOAT_1_0;
        v12 = pmi->mForwardSpeed;
        v13.m128_f32[0] = (float)((float)(1.0 - v6->mForwardSpeedPenaltyPercent) * v6->mOriginalForwardSpeedKPH)
                        * 0.27777779;
        if ( v12 > v13.m128_f32[0] )
        {
          v14 = (__m128)LODWORD(pmi->mForwardSpeed);
          v14.m128_f32[0] = v12 - (float)(timestep * v6->mForwardSpeedPenaltyDecelKPHPS);
          if ( v14.m128_f32[0] < v13.m128_f32[0] )
            v14 = v13;
          v14.m128_f32[0] = v14.m128_f32[0] - v12;
          v34 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v14, v14, 0),
                    v7->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
                  v7->m_motion.m_linearVelocity.m_quad);
          hkpEntity::activate(v7);
          v7->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v7->m_motion.vfptr, (unsigned int)&v34);
        }
        else
        {
          v6->mState = 3;
        }
      }
    }
    else
    {
      v15 = v7->m_motion.m_angularVelocity.m_quad;
      v16 = _mm_unpacklo_ps(
              _mm_unpacklo_ps((__m128)LODWORD(v6->mCounterSpin.x), (__m128)LODWORD(v6->mCounterSpin.z)),
              _mm_unpacklo_ps((__m128)LODWORD(v6->mCounterSpin.y), (__m128)0i64));
      v17 = _mm_mul_ps(v16, v16);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v19 = _mm_rsqrt_ps(v18);
      v20 = _mm_andnot_ps(
              _mm_cmpleps(v18, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                _mm_mul_ps(*(__m128 *)_xmm, v19)));
      v21 = _mm_mul_ps(v16, v20);
      v22 = _mm_mul_ps(v21, v15);
      v23 = _mm_sub_ps(
              _mm_mul_ps(v20, v18),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                _mm_shuffle_ps(v22, v22, 170)));
      if ( v23.m128_f32[0] > 0.0 )
      {
        v34 = _mm_add_ps(v15, _mm_mul_ps(v21, v23));
        hkpEntity::activate(v7);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v7->m_motion.vfptr[9].__first_virtual_table_function__)(
          &v7->m_motion,
          &v34);
      }
      v6->mState = 2;
    }
  }
  else
  {
    v34 = _mm_add_ps(
            _mm_unpacklo_ps(
              _mm_unpacklo_ps((__m128)LODWORD(v6->mVelocityToAdd.x), (__m128)LODWORD(v6->mVelocityToAdd.z)),
              _mm_unpacklo_ps((__m128)LODWORD(v6->mVelocityToAdd.y), (__m128)0i64)),
            v7->m_motion.m_linearVelocity.m_quad);
    hkpEntity::activate(v7);
    v7->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v7->m_motion.vfptr, (unsigned int)&v34);
    v24 = v5->m_pSimObject;
    if ( v24 )
      v4 = v24->m_Components.p[2].m_pComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    v27 = (__m128)LODWORD(v4[2].m_SafePointerList.mNode.mPrev);
    v28 = (__m128)LODWORD(v4[2].vfptr);
    v26 = (__m128)HIDWORD(v4[2].vfptr);
    v25 = (float)(1.0 - COERCE_FLOAT(LODWORD(v6->mForwardsness) & _xmm)) * v6->mSwerveImpulse;
    v26.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v6->mMotionIntentionDirection.z)
                            - (float)(*(float *)&v4[2].m_SafePointerList.mNode.mPrev * v6->mMotionIntentionDirection.y))
                    * v25;
    v27.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v6->mMotionIntentionDirection.x)
                            - (float)(*(float *)&v4[2].vfptr * v6->mMotionIntentionDirection.z))
                    * v25;
    v28.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v6->mMotionIntentionDirection.y)
                            - (float)(*((float *)&v4[2].vfptr + 1) * v6->mMotionIntentionDirection.x))
                    * v25;
    if ( !v6->mTarget.m_pPointer )
    {
      v29 = v6->mNoTargetModifier;
      v26.m128_f32[0] = v26.m128_f32[0] * v29;
      v27.m128_f32[0] = v27.m128_f32[0] * v29;
      v28.m128_f32[0] = v28.m128_f32[0] * v29;
    }
    v30 = v6->mCounterSwerveModifier;
    v6->mCounterSpin.x = v26.m128_f32[0] * v30;
    v6->mCounterSpin.y = v27.m128_f32[0] * v30;
    v6->mCounterSpin.z = v28.m128_f32[0] * v30;
    v35 = _mm_add_ps(
            _mm_unpacklo_ps(_mm_unpacklo_ps(v26, v28), _mm_unpacklo_ps(v27, (__m128)0i64)),
            v7->m_motion.m_angularVelocity.m_quad);
    hkpEntity::activate(v7);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v7->m_motion.vfptr[9].__first_virtual_table_function__)(
      &v7->m_motion,
      &v35);
    v31 = v5->mForwardSpeed;
    v6->mState = 1;
    v6->mOriginalForwardSpeedKPH = v31 * 3.5999999;
    *((_BYTE *)v5 + 900) |= 8u;
    v32 = v6->mVelocityToAdd.y;
    v33 = v6->mVelocityToAdd.z;
    v5->mRamVelocity.x = v6->mVelocityToAdd.x;
    v5->mRamVelocity.y = v32;
    v5->mRamVelocity.z = v33;
  }
  return 0;
}

