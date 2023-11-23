// File Line: 119
// RVA: 0x1582E30
__int64 UFG::_dynamic_initializer_for__gVehicleTakenDownChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gVehicleTakenDownChannel, "EVT_VEHICLE_TAKENDOWN", 0i64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gVehicleTakenDownChannel__);
}

// File Line: 120
// RVA: 0x1582E00
__int64 UFG::_dynamic_initializer_for__gVehicleDisabledChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gVehicleDisabledChannel, "EVT_VEHICLE_DISABLED", 0i64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gVehicleDisabledChannel__);
}

// File Line: 123
// RVA: 0x685F10
void __fastcall UFG::PhysicsMoverInterface_EmitVehicleDisabledEvent(UFG::SimObject *pVehicle)
{
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rcx
  __int64 *mPrev; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::Event *v4; // rbx
  const char *mName; // rcx
  UFG::allocator::free_link *v6; // rax
  UFG::Event *v7; // rdx
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  __int64 *v10; // rcx
  __int64 **v11; // rax
  __int64 *v12; // rcx
  __int64 **v13; // rax
  __int64 *v14; // [rsp+28h] [rbp-18h] BYREF
  __int64 **v15; // [rsp+30h] [rbp-10h]
  UFG::SimObject *v16; // [rsp+38h] [rbp-8h]

  v14 = (__int64 *)&v14;
  v15 = &v14;
  v16 = pVehicle;
  if ( pVehicle )
  {
    p_m_SafePointerList = &pVehicle->m_SafePointerList;
    mPrev = (__int64 *)p_m_SafePointerList->mNode.mPrev;
    mPrev[1] = (__int64)&v14;
    v14 = mPrev;
    v15 = (__int64 **)p_m_SafePointerList;
    p_m_SafePointerList->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14;
  }
  v3 = UFG::qMalloc(0x50ui64, "AnimatedEvent", 0i64);
  v4 = (UFG::Event *)v3;
  if ( v3 )
  {
    mName = UFG::gVehicleDisabledChannel.mName;
    v6 = v3 + 1;
    v6->mNext = v6;
    v6[1].mNext = v6;
    v4->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
    v4->m_NamePTR = mName;
    v4->m_EventUID = UFG::qStringHash32(mName, 0xFFFFFFFF);
    v4->vfptr = (UFG::EventVtbl *)&UFG::AnimatedEvent::`vftable;
    v7 = v4 + 1;
    v4[1].vfptr = (UFG::EventVtbl *)&v4[1];
    v4[1].mPrev = (UFG::qNode<UFG::Event,UFG::Event> *)&v4[1];
    v4[1].mNext = (UFG::qNode<UFG::Event,UFG::Event> *)v16;
    if ( v16 )
    {
      v8 = &v16->m_SafePointerList;
      v9 = v16->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
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
  UFG::qPidController *v5; // rax

  this->vfptr = (UFG::CruiseControlVtbl *)&UFG::CruiseControl::`vftable;
  *(_WORD *)&this->mIsActive = 0;
  v5 = (UFG::qPidController *)UFG::qMalloc(0xB0ui64, "qPidController", 0i64);
  if ( v5 )
    UFG::qPidController::qPidController(v5);
  this->mPidController = v5;
  v5->m_ParameterBlock.m_P_Coefficient = pid_p;
  v5->m_ParameterBlock.m_I_Coefficient = pid_i;
  v5->m_ParameterBlock.m_D_Coefficient = pid_d;
  this->mSetSpeedMPS = 0.0;
}

// File Line: 166
// RVA: 0x690610
float __fastcall UFG::CruiseControl::Update(
        UFG::CruiseControl *this,
        float deltaTime,
        float speedMPS,
        float gasBrakes,
        bool overrideSpeed)
{
  float result; // xmm0_4
  float v7; // xmm1_4
  UFG::qPidController *mPidController; // rcx

  UFG::qPidControllerCore::Record(this->mPidController, speedMPS - this->mSetSpeedMPS, deltaTime, 0i64);
  if ( this->mIsEnabled )
  {
    this->mIsActive = 1;
    if ( overrideSpeed )
    {
      this->mSetSpeedMPS = speedMPS;
      return gasBrakes;
    }
    else
    {
      result = UFG::qPidControllerCore::GetOutput(this->mPidController);
      v7 = FLOAT_N1_0;
      if ( result <= -1.0 )
        return v7;
      v7 = 0.0;
      if ( result >= 0.0 )
        return v7;
    }
  }
  else
  {
    mPidController = this->mPidController;
    this->mIsActive = 0;
    UFG::qPidControllerCore::Clear(mPidController);
    return gasBrakes;
  }
  return result;
}

// File Line: 213
// RVA: 0x157B830
__int64 dynamic_initializer_for__UFG::PhysicsMoverInterface::s_VehicleAttacks__()
{
  `eh vector constructor iterator(
    (char *)&UFG::PhysicsMoverInterface::s_VehicleAttacks,
    0x38ui64,
    200,
    (void (__fastcall *)(void *))UFG::AttackData::AttackData);
  UFG::PhysicsMoverInterface::s_VehicleAttacks.size = 0;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PhysicsMoverInterface::s_VehicleAttacks__);
}

// File Line: 235
// RVA: 0x157B7F0
__int64 dynamic_initializer_for__UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList__);
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
void __fastcall UFG::PhysicsMoverInterface::PhysicsMoverInterface(
        UFG::PhysicsMoverInterface *this,
        int numWheels,
        UFG::SceneObjectProperties *pSceneObj,
        component_PhysicsMover *dataPtr)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, pSceneObj->m_NameUID);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface>;
  this->mNext = &this->UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhysicsMoverInterface::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::PhysicsMoverInterface::`vftable{for `UFG::UpdateInterface};
  *(_QWORD *)&this->mInput.mSteering = 0i64;
  *(_QWORD *)&this->mInput.mGasBrakes = 0i64;
  *((_DWORD *)&this->mInput + 4) &= 0xFFFFF800;
  UFG::RebindingComponentHandle<UFG::VehicleDriverInterface,0>::RebindingComponentHandle<UFG::VehicleDriverInterface,0>(&this->mDriverComponent);
  *(_QWORD *)&this->mDestructState = 0i64;
  *(_QWORD *)&this->mDestructTimerInitial = 0i64;
  this->mLastDamageSource.mPrev = &this->mLastDamageSource;
  this->mLastDamageSource.mNext = &this->mLastDamageSource;
  this->mLastDamageSource.m_pPointer = 0i64;
  *(_QWORD *)&this->mPropertySetNameAI.mUID = -1i64;
  this->mPropertySetExplosion.mUID = -1;
  `eh vector constructor iterator(
    this->mTargetSpheres,
    0x40ui64,
    5,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  UFG::VehicleParams::VehicleParams(&this->mParameters);
  this->mPhysicsVehicle = 0i64;
  this->mRammingState = 0i64;
  this->mPostRamImmunityTimer = 0.0;
  *(_QWORD *)&this->mForwardSpeed = 0i64;
  this->mDamageMultiplierWorldCollisions = 1.0;
  this->mDamageMultiplierVehicleCollisions = 1.0;
  this->mDamageMultiplierAttack = 1.0;
  this->mDamageMultiplierBullets = 1.0;
  *(_QWORD *)&this->mDamageMultiplierTires = 1065353216i64;
  *(_QWORD *)&this->mTireBlownImpulse = 0i64;
  *(_QWORD *)&this->mAutoDeterioratingDamageThreshold = 0i64;
  *(_QWORD *)&this->mNotMovingTime = 0i64;
  this->mGroundFixupRequired = 0;
  this->mNumWheels = numWheels;
  *(_QWORD *)&this->mLockAtHighLODMode = 3i64;
  this->mVehicleCollisionMinImpulseRequiredToTakeDamage = 5.0;
  this->mVehicleCollisionDamageDealtAtMinImpulse = 0.1;
  this->mVehicleCollisionDamageDealtAtMaxImpulse = 0.2;
  this->mVehicleCollisionDamageDealtAtMinRamImpulse = 0.1;
  this->mVehicleCollisionDamageDealtAtMaxRamImpulse = 0.2;
  this->mVehicleCollisionExtraDamageMultiplier = 1.5;
  this->mVehicleCollisionMinImpulseRequiredToDealDamage = 5.0;
  this->mVehicleCollisionMaxImpulseForDealingDamage = 10.0;
  this->mVehicleCollisionMinRamImpulseRequiredToDealDamage = 5.0;
  *(_QWORD *)&this->mVehicleCollisionMaxRamImpulseForDealingDamage = 1092616192i64;
  this->mSecondsEngineHasBeenDeteriorating = -1.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mRamVelocity.x = UFG::qVector3::msZero.x;
  this->mRamVelocity.y = y;
  this->mRamVelocity.z = z;
  *((_DWORD *)this + 224) &= 0xFFFFFFE4;
  *((_BYTE *)this + 900) &= 0xC0u;
  *(_WORD *)&this->mDoorsLocked = 1;
  this->mCreatedWithTemporaryRig = 0;
  this->mTrunkType = eVEHICLE_TRUNK_TYPE_NONE;
  mPrev = UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mPrev;
  UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList;
  UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mPrev = &this->UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface>;
  UFG::SimComponent::AddType(this, UFG::PhysicsMoverInterface::_PhysicsMoverInterfaceTypeUID, "PhysicsMoverInterface");
  UFG::PhysicsMoverInterface::PropertiesLoad(this, pSceneObj, dataPtr);
  *(_QWORD *)this->mDamageState.tireDamage.array = 0i64;
  *(_QWORD *)&this->mDamageState.tireDamage.array[2] = 0i64;
  this->mDamageState.engineDamage = 0.0;
  this->mMotorBoneId = (UFG::qSafeArray<int,2>)-1i64;
  this->mPropellerBoneId = (UFG::qSafeArray<int,2>)-1i64;
}

// File Line: 322
// RVA: 0x66CC00
void __fastcall UFG::PhysicsMoverInterface::~PhysicsMoverInterface(UFG::PhysicsMoverInterface *this)
{
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v2; // rdi
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *mPrev; // rcx
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *mNext; // rax
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLastDamageSource; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v11; // rcx
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v12; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhysicsMoverInterface::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::PhysicsMoverInterface::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::PhysicsMoverInterface::s_PhysicsMoverInterfacepCurrentIterator )
    UFG::PhysicsMoverInterface::s_PhysicsMoverInterfacepCurrentIterator = (UFG::PhysicsMoverInterface *)&this->mPrev[-5].mNext;
  v2 = &this->UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
    mPhysicsVehicle->vfptr->__vecDelDtor(mPhysicsVehicle, 1u);
  UFG::VehicleParams::~VehicleParams(&this->mParameters);
  `eh vector destructor iterator(
    this->mTargetSpheres,
    0x40ui64,
    5,
    (void (__fastcall *)(void *))UFG::TargetSphere::~TargetSphere);
  p_mLastDamageSource = &this->mLastDamageSource;
  if ( this->mLastDamageSource.m_pPointer )
  {
    v7 = p_mLastDamageSource->mPrev;
    v8 = this->mLastDamageSource.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    p_mLastDamageSource->mPrev = p_mLastDamageSource;
    this->mLastDamageSource.mNext = &this->mLastDamageSource;
  }
  this->mLastDamageSource.m_pPointer = 0i64;
  v9 = p_mLastDamageSource->mPrev;
  v10 = this->mLastDamageSource.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mLastDamageSource->mPrev = p_mLastDamageSource;
  this->mLastDamageSource.mNext = &this->mLastDamageSource;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mDriverComponent);
  v11 = v2->mPrev;
  v12 = v2->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 363
// RVA: 0x67CA90
void __fastcall UFG::PhysicsMoverInterface::HandleResourceLoadedEvent(
        UFG::PhysicsMoverInterface *this,
        UFG::ResourceRequest *request,
        bool loaded)
{
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::PhysicsMoverInterface::ReloadReason v5; // edi
  UFG::HumanDriverComponent *v6; // rax

  if ( loaded && !this->mPhysicsVehicle )
  {
    m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
    v5 = RELOAD_AI;
    if ( m_pSimObject )
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(m_pSimObject);
    else
      v6 = 0i64;
    LOBYTE(v5) = v6 != 0i64;
    UFG::PhysicsMoverInterface::Reload(this, v5);
  }
}

// File Line: 374
// RVA: 0x687750
void __fastcall UFG::PhysicsMoverInterface::PropertiesLoad(
        UFG::PhysicsMoverInterface *this,
        UFG::SceneObjectProperties *pSceneObj,
        component_PhysicsMover *dataPtr)
{
  __int64 mOffset; // rax
  const char *v7; // r14
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v9; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v15; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+38h] [rbp-28h] BYREF
  UFG::qSymbol defaultValue; // [rsp+90h] [rbp+30h] BYREF
  UFG::qSymbol result; // [rsp+98h] [rbp+38h] BYREF
  UFG::qSymbol *p_defaultValue; // [rsp+A0h] [rbp+40h]

  mOffset = dataPtr->modelName.mOffset;
  if ( mOffset )
    v7 = (char *)&dataPtr->modelName + mOffset;
  else
    v7 = 0i64;
  this->mPropertySetNameAI.mUID = dataPtr->physicsPropertySetAI.mUID;
  this->mPropertySetNameHuman.mUID = dataPtr->physicsPropertySetHuman.mUID;
  p_defaultValue = &defaultValue;
  defaultValue.mUID = UFG::gNullQSymbol.mUID;
  this->mPropertySetExplosion = (UFG::qSymbol)PropertyUtils::GetWithDefault<UFG::qSymbol>(
                                                &result,
                                                pSceneObj,
                                                (UFG::qArray<unsigned long,0> *)&qSymbol_explosionPropertySet,
                                                &defaultValue.mUID,
                                                DEPTH_RECURSE)->mUID;
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v9 = PropertyUtils::Get<bool>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&SimSym_UnlockVehicleDoors,
         DEPTH_RECURSE);
  if ( v9 )
    LOBYTE(v9) = *v9;
  this->mDoorsLocked = (_BYTE)v9 == 0;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol.mUID = dataPtr->TrunkType.mUID;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gVehicleTrunkTypeEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gVehicleTrunkTypeEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = UFG::gVehicleTrunkTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gVehicleTrunkTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &UFG::gVehicleTrunkTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gVehicleTrunkTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  this->mTrunkType = pTrackEnumBinding.m_EnumValue;
  this->mDamageMultiplierWorldCollisions = dataPtr->damageMultiplierWorldCollisions;
  this->mDamageMultiplierVehicleCollisions = dataPtr->damageMultiplierVehicleCollisions;
  this->mDamageMultiplierBullets = dataPtr->damageMultiplierBullets;
  this->mDamageMultiplierTires = dataPtr->damageMultiplierTires;
  this->mVehicleCollisionMinImpulseRequiredToTakeDamage = dataPtr->vehicleCollisionMinImpulseRequiredToTakeDamage;
  this->mVehicleCollisionMinImpulseRequiredToDealDamage = dataPtr->vehicleCollisionMinImpulseRequiredToDealDamage;
  this->mVehicleCollisionDamageDealtAtMinImpulse = dataPtr->vehicleCollisionDamageDealtAtMinImpulse;
  this->mVehicleCollisionDamageDealtAtMaxImpulse = dataPtr->vehicleCollisionDamageDealtAtMaxImpulse;
  this->mVehicleCollisionMinRamImpulseRequiredToDealDamage = dataPtr->vehicleCollisionMinRamImpulseRequiredToDealDamage;
  this->mVehicleCollisionDamageDealtAtMinRamImpulse = dataPtr->vehicleCollisionDamageDealtAtMinRamImpulse;
  this->mVehicleCollisionDamageDealtAtMaxRamImpulse = dataPtr->vehicleCollisionDamageDealtAtMaxRamImpulse;
  this->mVehicleCollisionExtraDamageMultiplier = dataPtr->vehicleCollisionExtraDamageMultiplier;
  this->mVehicleCollisionMaxImpulseForDealingDamage = dataPtr->vehicleCollisionMaxImpulseForDealingDamage;
  this->mVehicleCollisionMaxRamImpulseForDealingDamage = dataPtr->vehicleCollisionMaxRamImpulseForDealingDamage;
  *((_BYTE *)this + 900) ^= (*((_BYTE *)this + 900) ^ dataPtr->vehicleCollisionForceDamageDealer) & 1;
  this->mLowLodThrottleAcceleration = dataPtr->lowLodThrottleAcceleration;
  this->mLowLodBrakesAcceleration = dataPtr->lowLodBrakesAcceleration;
  this->mLowLodCoastAcceleration = dataPtr->lowLodCoastAcceleration;
  this->mLowLodMaxSpeed = dataPtr->lowLodMaxSpeed;
  this->mLowLodMaxLateralAcceleration = dataPtr->lowLodMaxLateralAcceleration;
  this->mLowLodMinTurningRadius = dataPtr->lowLodMinTurningRadius;
  y = dataPtr->boundingBoxMin.y;
  z = dataPtr->boundingBoxMin.z;
  this->mBoundingBoxMin.x = dataPtr->boundingBoxMin.x;
  this->mBoundingBoxMin.y = y;
  this->mBoundingBoxMin.z = z;
  v13 = dataPtr->boundingBoxMax.y;
  v14 = dataPtr->boundingBoxMax.z;
  this->mBoundingBoxMax.x = dataPtr->boundingBoxMax.x;
  this->mBoundingBoxMax.y = v13;
  this->mBoundingBoxMax.z = v14;
  this->mTireShotImpulse = dataPtr->tireShotImpulse;
  this->mTireBlownImpulse = dataPtr->tireBlownImpulse;
  *((_DWORD *)this + 224) ^= (*((_DWORD *)this + 224) ^ dataPtr->lockedAtLowLOD) & 1;
  this->mAutoDeterioratingDamageThreshold = dataPtr->autoDeterioratingDamageThreshold;
  this->mAutoDeterioratingDamageRate = dataPtr->autoDeterioratingDamageRate;
  this->mDistanceToHighLod = dataPtr->vehicleDistanceToHighLod;
  this->mDistanceToMedLod = dataPtr->vehicleDistanceToMedLod;
  UFG::VehicleParams::Init(&this->mParameters, &this->mPropertySetNameAI, v7);
  v15 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v15;
}

// File Line: 436
// RVA: 0x683040
void __fastcall UFG::PhysicsMoverInterface::OnAttach(UFG::PhysicsMoverInterface *this, UFG::SimObjectVehicle *object)
{
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  signed __int16 m_Flags; // cx
  bool v6; // al
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLastDamageSource; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  UFG::RebindingComponentHandle<UFG::VehicleDriverInterface,0>::Bind<UFG::SimObjectVehicle>(
    &this->mDriverComponent,
    object);
  this->mGroundFixupRequired = 0;
  this->mUntargetable = 0;
  if ( object )
  {
    m_Flags = object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(object);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)object);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                object,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                object,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  v6 = ComponentOfTypeHK->mTemporaryRig || !ComponentOfTypeHK->mRigHandle.mData;
  p_mLastDamageSource = &this->mLastDamageSource;
  this->mCreatedWithTemporaryRig = v6;
  if ( this->mLastDamageSource.m_pPointer )
  {
    mPrev = p_mLastDamageSource->mPrev;
    mNext = this->mLastDamageSource.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mLastDamageSource->mPrev = p_mLastDamageSource;
    this->mLastDamageSource.mNext = &this->mLastDamageSource;
  }
  this->mLastDamageSource.m_pPointer = 0i64;
}

// File Line: 457
// RVA: 0x684170
void __fastcall UFG::PhysicsMoverInterface::OnDetach(UFG::PhysicsMoverInterface *this)
{
  UFG::RebindingComponentHandle<UFG::VehicleDriverInterface,0> *p_mDriverComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx

  p_mDriverComponent = &this->mDriverComponent;
  if ( this->mDriverComponent.m_pSimComponent )
  {
    mPrev = p_mDriverComponent->mPrev;
    mNext = this->mDriverComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mDriverComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_mDriverComponent->m_pSimObject = 0i64;
    p_mDriverComponent->mNext = p_mDriverComponent;
    p_mDriverComponent->mPrev = p_mDriverComponent;
    goto LABEL_8;
  }
  if ( this->mDriverComponent.m_pSimObject
    && (p_mDriverComponent->mPrev != p_mDriverComponent || this->mDriverComponent.mNext != &this->mDriverComponent) )
  {
    v5 = p_mDriverComponent->mPrev;
    v6 = p_mDriverComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_mDriverComponent->m_Changed = 1;
  UFG::PhysicsMoverInterface::DeactivateTargetSpheres(this);
  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
    mPhysicsVehicle->vfptr->__vecDelDtor(mPhysicsVehicle, 1u);
  this->mPhysicsVehicle = 0i64;
}

// File Line: 475
// RVA: 0x689A00
void __fastcall UFG::PhysicsMoverInterface::Reset(UFG::PhysicsMoverInterface *this, __int64 options)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx

  this->mGroundFixupRequired = 0;
  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
    ((void (__fastcall *)(UFG::PhysicsVehicle *, __int64))mPhysicsVehicle->vfptr[1].DebugDraw)(mPhysicsVehicle, options);
}

// File Line: 487
// RVA: 0x68D050
void __fastcall UFG::PhysicsMoverInterface::Teleport(UFG::PhysicsMoverInterface *this, UFG::Event *this_event)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pComponent; // rcx
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_pComponent = (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent;
    if ( m_pComponent )
      UFG::TransformNodeComponent::SetWorldTransform(m_pComponent, (UFG::qMatrix44 *)&this_event[1].m_EventUID);
  }
  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
    mPhysicsVehicle->vfptr[3].ResourceUnloaded(mPhysicsVehicle, (UFG::PhysicsResourceHandle *)&this_event[1].m_EventUID);
}

// File Line: 505
// RVA: 0x67A640
UFG::qVector3 *__fastcall UFG::PhysicsMoverInterface::GetFacingDirection(
        UFG::PhysicsMoverInterface *this,
        UFG::qVector3 *result)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pComponent; // rbx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pComponent = (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent;
  else
    m_pComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
  result->x = m_pComponent->mWorldTransform.v0.x;
  result->y = m_pComponent->mWorldTransform.v0.y;
  result->z = m_pComponent->mWorldTransform.v0.z;
  return result;
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
    return (float)(this->mLowLodMaxLateralAcceleration * 9.8000002) / v3;
  return v4;
}

// File Line: 541
// RVA: 0x67E430
void __fastcall UFG::PhysicsMoverInterface::InitializeDestructCountdown(UFG::PhysicsMoverInterface *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimObjectCharacter *p; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_Components.p[30].m_pComponent;
  p = (UFG::SimObjectCharacter *)m_pSimObject->m_Components.p;
  if ( p && UFG::IsAnyLocalPlayer(p) )
  {
    this->mDestructTimerInitial = 3.0;
    this->mDestructTimer = 3.0;
  }
  else
  {
    this->mDestructTimerInitial = UFG::PhysicsMoverInterface::sVehicleDestructCountdown;
    this->mDestructTimer = UFG::PhysicsMoverInterface::sVehicleDestructCountdown;
  }
}

// File Line: 559
// RVA: 0x696D70
void __fastcall UFG::PhysicsMoverInterface::UpdateEngineDamage(UFG::PhysicsMoverInterface *this, float deltaTime)
{
  float engineDamage; // xmm0_4
  float mSecondsEngineHasBeenDeteriorating; // xmm0_4
  UFG::PhysicsMoverInterface::DestructState mDestructState; // ecx
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  UFG::SimObject *m_pSimObject; // rcx

  engineDamage = this->mDamageState.engineDamage;
  if ( engineDamage < this->mAutoDeterioratingDamageThreshold || engineDamage >= 1.0 )
  {
    this->mSecondsEngineHasBeenDeteriorating = -1.0;
  }
  else
  {
    mSecondsEngineHasBeenDeteriorating = this->mSecondsEngineHasBeenDeteriorating;
    if ( mSecondsEngineHasBeenDeteriorating == -1.0 )
    {
      this->mSecondsEngineHasBeenDeteriorating = deltaTime;
      UFG::PhysicsMoverInterface_EmitVehicleDisabledEvent(this->m_pSimObject);
    }
    else
    {
      this->mSecondsEngineHasBeenDeteriorating = mSecondsEngineHasBeenDeteriorating + deltaTime;
    }
  }
  mDestructState = this->mDestructState;
  if ( mDestructState )
  {
    if ( mDestructState == MID_DESTRUCT )
    {
      v7 = this->mDestructTimer - deltaTime;
      this->mDestructTimer = v7;
      v8 = 1.0 - (float)(v7 / this->mDestructTimerInitial);
      if ( v8 >= 1.0 )
        v8 = *(float *)&FLOAT_1_0;
      this->mDestructPercentage = v8;
      if ( v7 < 0.0 )
        UFG::PhysicsMoverInterface::TriggerExplosion(this);
    }
  }
  else
  {
    v9 = this->mDamageState.engineDamage;
    if ( v9 < 1.0 )
    {
      if ( this->mSecondsEngineHasBeenDeteriorating >= 0.0 )
      {
        UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(
          this,
          (float)(deltaTime * this->mAutoDeterioratingDamageRate) + v9);
        *((_BYTE *)this + 0x384) |= 0x20u;
      }
    }
    else
    {
      if ( (*((_BYTE *)this + 896) & 0x10) != 0 )
      {
        m_pSimObject = this->m_pSimObject;
        this->mDestructState = POST_DESTRUCT;
      }
      else
      {
        UFG::PhysicsMoverInterface::InitializeDestructCountdown(this);
        m_pSimObject = this->m_pSimObject;
        this->mDestructState = MID_DESTRUCT;
      }
      UFG::PhysicsMoverInterface_EmitVehicleDisabledEvent(m_pSimObject);
    }
  }
}

// File Line: 670
// RVA: 0x695AE0
void UFG::PhysicsMoverInterface::UpdateDetailSettings(void)
{
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-78h] BYREF

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
  UFG::SimObject *m_pPointer; // rcx
  bool v5; // dl
  int m_pSimObject; // eax
  UFG::SimObject *v7; // rax
  hkpEntity *v8; // rcx
  float v9; // xmm0_4
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::SimObject *v16; // r15
  int v17; // ebx
  float *p_mGasBrakes; // rsi
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v19; // rcx
  bool v20; // r12
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v21; // rcx
  char v22; // al
  __int64 v23; // rax
  bool v24; // r15
  __int64 v25; // rax
  UFG::TransformNodeComponent *v26; // rsi
  unsigned int VisIndexAtPosition; // eax
  bool IsSectionVisible_VisIndex; // al
  float mLockAtHighLODTime; // ecx
  int v30; // ebx
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm10_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::BaseCameraComponent *mCurrentCamera; // rbx
  float *p_x; // rbx
  float v37; // xmm2_4
  int v38; // r12d
  UFG::SimObject *v39; // rax
  hkpEntity *v40; // rcx
  UFG::SimObject *v41; // rcx
  UFG::SimObject *v42; // rcx
  UFG::SimObject *v43; // rax
  UFG::PhysicsVehicle *v44; // rcx
  UFG::PhysicsVehicle::Lod mCurrentLod; // eax
  float v46; // xmm7_4
  float v47; // xmm6_4
  float v48; // xmm8_4
  bool v49; // r12
  __int64 v50; // rax
  __int64 v51; // rbx
  bool v52; // bl
  float *v53; // rax
  float v54; // xmm14_4
  float v55; // xmm15_4
  float v56; // xmm3_4
  float v57; // xmm4_4
  float v58; // xmm13_4
  float v59; // xmm10_4
  float v60; // xmm11_4
  float v61; // xmm6_4
  UFG::SimObject *v62; // rcx
  float v63; // xmm2_4
  double v64; // xmm0_8
  float v65; // xmm11_4
  float v66; // xmm6_4
  float v67; // xmm0_4
  float v68; // xmm10_4
  float v69; // xmm11_4
  float v70; // xmm6_4
  float v71; // xmm0_4
  float v72; // xmm1_4
  float v73; // xmm2_4
  float v74; // xmm10_4
  float v75; // xmm11_4
  float v76; // xmm6_4
  float v77; // xmm5_4
  float v78; // xmm10_4
  float v79; // xmm11_4
  float v80; // xmm6_4
  float v81; // xmm7_4
  float v82; // xmm15_4
  float v83; // xmm7_4
  float v84; // xmm3_4
  float v85; // xmm13_4
  float v86; // xmm6_4
  float v87; // xmm10_4
  float v88; // xmm2_4
  float v89; // xmm1_4
  float v90; // xmm2_4
  __m128 y_low; // xmm11
  float v92; // xmm6_4
  __m128 v93; // xmm3
  float v94; // xmm1_4
  float SpeedLimitForCurvature; // xmm0_4
  float v96; // xmm13_4
  float v97; // xmm4_4
  float v98; // xmm5_4
  float v99; // xmm3_4
  float v100; // xmm2_4
  float v101; // xmm12_4
  float v102; // xmm4_4
  float v103; // xmm5_4
  float v104; // xmm3_4
  UFG::SimObject *v105; // rcx
  float v106; // xmm6_4
  double Mass; // xmm0_8
  float v108; // xmm6_4
  float v109; // xmm14_4
  float v110; // xmm6_4
  bool v111; // si
  UFG::RoadNetworkLocation *Name; // rbx
  __m128 v113; // xmm1
  __m128 v114; // xmm10
  __m128 v115; // xmm2
  float v116; // xmm1_4
  float v117; // xmm11_4
  float v118; // xmm0_4
  float v119; // xmm1_4
  float v120; // xmm0_4
  float v121; // xmm4_4
  __int128 x_low; // xmm7
  __m128 v123; // xmm5
  float v124; // xmm3_4
  float v125; // xmm0_4
  float v126; // xmm2_4
  float v127; // xmm3_4
  __m128 v128; // xmm2
  float v129; // xmm1_4
  __int128 v130; // xmm10
  float v131; // xmm12_4
  float v132; // xmm3_4
  float v133; // xmm11_4
  __m128 v134; // xmm1
  float v135; // xmm2_4
  float v136; // xmm1_4
  float v137; // xmm2_4
  float v138; // xmm13_4
  float v139; // xmm14_4
  float v140; // xmm15_4
  float v141; // xmm11_4
  float v142; // xmm6_4
  UFG::SimObject *v143; // rax
  UFG::SimObject *v144; // rcx
  float v145; // xmm1_4
  UFG::qMatrix44 localWorld; // [rsp+20h] [rbp-A0h] BYREF
  float top_speed; // [rsp+60h] [rbp-60h]
  float v148; // [rsp+64h] [rbp-5Ch]
  float v149; // [rsp+68h] [rbp-58h]
  UFG::qMatrix44 v150; // [rsp+70h] [rbp-50h] BYREF
  __int64 v151; // [rsp+B0h] [rbp-10h]
  UFG::qNode<UFG::qString,UFG::qString> *v152; // [rsp+1B0h] [rbp+F0h]
  hkBool result[4]; // [rsp+1B8h] [rbp+F8h] BYREF
  hkBool v154[4]; // [rsp+1C0h] [rbp+100h] BYREF
  float v155; // [rsp+1C8h] [rbp+108h]

  v151 = -2i64;
  if ( !this->mPrev )
  {
    *(_QWORD *)&this->m_TypeUID = 0i64;
    *(_QWORD *)&this->m_Flags = 0i64;
    LODWORD(this->m_pSimObject) &= 0xFFFFF9C0;
    LODWORD(this->m_pSimObject) |= 6u;
    m_pPointer = this->mParameters.mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      if ( *(float *)&m_pPointer[4].m_Flags > 20.0 )
        LODWORD(this->m_pSimObject) &= 0xFFFFFFF9;
    }
  }
  if ( this->mParameters.mSimObject.m_pPointer )
  {
    v5 = !this->mPrev
      || !UFG::SimComponent::IsType(
            (UFG::SimComponent *)this->mPrev,
            UFG::HumanDriverComponent::_HumanDriverComponentTypeUID);
    UFG::PhysicsVehicle::SetControlledByAi((UFG::PhysicsVehicle *)this->mParameters.mSimObject.m_pPointer, v5);
  }
  m_pSimObject = (int)this->m_pSimObject;
  if ( (m_pSimObject & 0x40) != 0 )
    LODWORD(this->m_pSimObject) = m_pSimObject | 6;
  if ( LODWORD(this->mNotMovingTime) == 2 )
  {
    v7 = this->mParameters.mSimObject.m_pPointer;
    if ( !v7
      || (v8 = *(hkpEntity **)(*(_QWORD *)&v7->m_Components.size + 168i64)) == 0i64
      || !hkpEntity::isActive(v8, result)->m_bool )
    {
      *(_QWORD *)&this->mNotMovingTime = 3i64;
    }
  }
  if ( LODWORD(this->mNotMovingTime) == 1 )
  {
    v9 = this->mPropellerAngle - deltaTime;
    this->mPropellerAngle = v9;
    if ( v9 <= 0.0 )
      *(_QWORD *)&this->mNotMovingTime = 3i64;
  }
  *(float *)&this->mMotorBoneId.array[1] = deltaTime + *(float *)&this->mMotorBoneId.array[1];
  mPrev = this->mParameters.modelName.mPrev;
  if ( mPrev
    && UFG::RammingState::Update(
         (UFG::RammingState *)mPrev,
         (UFG::PhysicsMoverInterface *)((char *)this - 64),
         deltaTime) )
  {
    v11 = this->mParameters.modelName.mPrev;
    v152 = v11;
    if ( v11 )
    {
      v152 = v11;
      if ( v11[1].mPrev )
      {
        v12 = v11->mPrev;
        mNext = v11->mNext;
        v12->mNext = mNext;
        mNext->mPrev = v12;
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
    this->mParameters.modelName.mPrev = 0i64;
  }
  *(float *)&this->mParameters.modelName.mNext = *(float *)&this->mParameters.modelName.mNext - deltaTime;
  if ( this->mParameters.mSimObject.m_pPointer )
  {
    if ( (LOBYTE(this->mVehicleCollisionMinImpulseRequiredToTakeDamage) & 2) != 0
      && ((unsigned int)UFG::VehicleUtility::GetVehicleOrientation(
                          *((UFG::SimObjectVehicle **)&this[-1] + 112),
                          0,
                          0i64) != 5
       || *(float *)&this->mParameters.mSimObject.m_pPointer[4].m_Flags < 0.1) )
    {
      LOBYTE(this->mVehicleCollisionMinImpulseRequiredToTakeDamage) &= ~2u;
    }
    UFG::PhysicsMoverInterface::UpdateEngineDamage((UFG::PhysicsMoverInterface *)((char *)this - 64), deltaTime);
    ((void (__fastcall *)(UFG::SimObject *))this->mParameters.mSimObject.m_pPointer->vfptr[12].__vecDelDtor)(this->mParameters.mSimObject.m_pPointer);
    v16 = 0i64;
    if ( (BYTE4(this->mParameters.mSimObject.m_pPointer[4].m_pTransformNodeComponent) & 7) != 0 )
      v16 = this->mParameters.mSimObject.m_pPointer;
    if ( v16 )
    {
      v17 = 0;
      if ( SLODWORD(this->mAutoDeterioratingDamageRate) > 0 )
      {
        p_mGasBrakes = &this->mInput.mGasBrakes;
        do
          UFG::PhysicsWheeledVehicle::SetTireDamage((UFG::PhysicsWheeledVehicle *)v16, v17++, *p_mGasBrakes++);
        while ( v17 < SLODWORD(this->mAutoDeterioratingDamageRate) );
      }
    }
    v19 = this->mPrev;
    v20 = v19
       && ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *))v19->mPrev[7].mNext)(v19);
    v21 = this->mPrev;
    if ( !v21
      || (v22 = ((__int64 (__fastcall *)(UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *))v21->mPrev[8].mPrev)(v21),
          result[0].m_bool = 0,
          v22) )
    {
      result[0].m_bool = 1;
    }
    v23 = *((_QWORD *)&this[-1] + 112);
    if ( v23 )
      v24 = (*(_WORD *)(v23 + 76) & 0x800) != 0;
    else
      v24 = 0;
    *(float *)&v154[0].m_bool = *((float *)&this->mParameters.mSimObject.m_pPointer[4].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext
                                + 1);
    v25 = *((_QWORD *)&this[-1] + 112);
    if ( v25 )
      v26 = *(UFG::TransformNodeComponent **)(*(_QWORD *)(v25 + 104) + 32i64);
    else
      v26 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v26);
    VisIndexAtPosition = UFG::SectionChooser::GetVisIndexAtPosition((UFG::qVector3 *)&v26->mWorldTransform.v3, 0);
    IsSectionVisible_VisIndex = UFG::SectionChooser::IsSectionVisible_VisIndex(VisIndexAtPosition, SCENERY_LAYER_STD, 0);
    LOBYTE(v152) = IsSectionVisible_VisIndex;
    if ( !IsSectionVisible_VisIndex )
      this->mDamageMultiplierAttack = 0.0;
    mLockAtHighLODTime = this->mLockAtHighLODTime;
    if ( (LOBYTE(mLockAtHighLODTime) & 8) != 0 )
    {
      v30 = 4;
LABEL_92:
      v38 = *(_DWORD *)&v154[0].m_bool;
      goto LABEL_93;
    }
    if ( (LOBYTE(mLockAtHighLODTime) & 1) == 0 )
    {
      if ( v24 )
      {
        v30 = 3;
        LOBYTE(this->mParameters.mSimObject.m_pPointer[4].mNode.mParent) = v24;
        goto LABEL_92;
      }
      if ( v20 )
      {
        v30 = 3;
        goto LABEL_92;
      }
      if ( IsSectionVisible_VisIndex )
      {
        if ( result[0].m_bool && LODWORD(this->mNotMovingTime) == 3 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v26);
          x = v26->mWorldTransform.v3.x;
          y = v26->mWorldTransform.v3.y;
          z = v26->mWorldTransform.v3.z;
          if ( LocalPlayer )
          {
            m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          }
          else
          {
            mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
            if ( mCurrentCamera )
              m_pTransformNodeComponent = (UFG::TransformNodeComponent *)&mCurrentCamera->mCamera;
            else
              m_pTransformNodeComponent = 0i64;
          }
          p_x = &m_pTransformNodeComponent->mWorldTransform.v3.x;
          v37 = (float)((float)((float)(p_x[1] - y) * (float)(p_x[1] - y))
                      + (float)((float)(*p_x - x) * (float)(*p_x - x)))
              + (float)((float)(p_x[2] - z) * (float)(p_x[2] - z));
          if ( v37 >= (float)((float)(UFG::PhysicsMoverInterface::mLodDistanceMultiplier
                                    * this->mVehicleCollisionDamageDealtAtMinImpulse)
                            * (float)(UFG::PhysicsMoverInterface::mLodDistanceMultiplier
                                    * this->mVehicleCollisionDamageDealtAtMinImpulse)) )
            v30 = ((float)((float)(UFG::PhysicsMoverInterface::mLodDistanceMultiplier
                                 * this->mVehicleCollisionDamageDealtAtMaxImpulse)
                         * (float)(UFG::PhysicsMoverInterface::mLodDistanceMultiplier
                                 * this->mVehicleCollisionDamageDealtAtMaxImpulse)) > v37)
                + 1;
          else
            v30 = 3;
          v38 = *(_DWORD *)&v154[0].m_bool;
          if ( *(_DWORD *)&v154[0].m_bool == 3 && v30 != 3 )
          {
            if ( !UFG::PhysicsMoverInterface::AreAllWheelsOnGround((UFG::PhysicsMoverInterface *)((char *)this - 64)) )
              v30 = v38;
            v39 = this->mParameters.mSimObject.m_pPointer;
            if ( v39 )
            {
              v40 = *(hkpEntity **)(*(_QWORD *)&v39->m_Components.size + 168i64);
              if ( v40 )
              {
                if ( hkpEntity::isActive(v40, v154)->m_bool )
                  v30 = v38;
              }
            }
            v41 = this->mParameters.mSimObject.m_pPointer;
            if ( v41
              && (HIDWORD(v41[4].m_pTransformNodeComponent) & 7) == 4
              && UFG::PhysicsCar::HasActiveAttachments((UFG::PhysicsCar *)v41) )
            {
              v30 = 3;
            }
          }
        }
        else
        {
          v30 = 3;
          v42 = this->mParameters.mSimObject.m_pPointer;
          if ( !v42 )
            goto LABEL_92;
          v43 = 0i64;
          if ( (BYTE4(v42[4].m_pTransformNodeComponent) & 7) != 0 )
            v43 = this->mParameters.mSimObject.m_pPointer;
          if ( !v43 )
            goto LABEL_92;
          v38 = *(_DWORD *)&v154[0].m_bool;
          if ( SLODWORD(this->mDamageMultiplierAttack) <= 0 && *(_DWORD *)&v154[0].m_bool != 3 )
            LODWORD(this->mDamageMultiplierAttack) = 1;
        }
LABEL_93:
        if ( SLODWORD(this->mDamageMultiplierAttack) > 0 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v26);
          localWorld = v26->mWorldTransform;
          if ( !(unsigned __int8)UFG::PhysicsVehicle::FixupTransformForGround(
                                   (UFG::PhysicsVehicle *)this->mParameters.mSimObject.m_pPointer,
                                   &localWorld) )
          {
            if ( (int)++LODWORD(this->mDamageMultiplierAttack) <= 3 )
              goto LABEL_102;
            if ( this->mPrev )
              ((void (__fastcall *)(UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *, UFG::qMatrix44 *))this->mPrev->mPrev[8].mNext)(
                this->mPrev,
                &localWorld);
            v30 = 1;
          }
          this->mDamageMultiplierAttack = 0.0;
        }
        if ( v30 != v38 )
          UFG::PhysicsMoverInterface::SetLOD(
            (UFG::PhysicsMoverInterface *)((char *)this - 64),
            (UFG::PhysicsVehicle::Lod)v30);
LABEL_102:
        UFG::PhysicsVehicle::UpdateLevelOfDetail((UFG::PhysicsVehicle *)this->mParameters.mSimObject.m_pPointer);
        v44 = (UFG::PhysicsVehicle *)this->mParameters.mSimObject.m_pPointer;
        mCurrentLod = v44->mCurrentLod;
        if ( mCurrentLod <= LOD_UNINITIALIZED )
        {
LABEL_204:
          v145 = *(float *)&this->mParameters.modelName.mStringHashUpper32;
          *(float *)&this->mParameters.firstFrontWheel = (float)(v145 * deltaTime)
                                                       + *(float *)&this->mParameters.firstFrontWheel;
          if ( v145 >= kfNotMovingSpeed )
            this->mDamageMultiplierWorldCollisions = 0.0;
          else
            this->mDamageMultiplierWorldCollisions = deltaTime + this->mDamageMultiplierWorldCollisions;
          LODWORD(this->mLockAtHighLODTime) &= ~4u;
          LODWORD(this->mLockAtHighLODTime) |= 4 * (kfNotMovingTimeThreshold < this->mDamageMultiplierWorldCollisions);
          return;
        }
        if ( mCurrentLod > LOD_SETTING_HIGH )
        {
          if ( mCurrentLod == LOD_SETTING_EXTREME )
          {
            ((void (__fastcall *)(UFG::PhysicsVehicle *, _QWORD, unsigned int *))v44->vfptr[1].ResourceUnloaded)(
              v44,
              0i64,
              &this->m_TypeUID);
            UFG::TransformNodeComponent::UpdateWorldTransform(v26);
            v46 = v26->mWorldTransform.v0.x;
            v47 = v26->mWorldTransform.v0.y;
            v48 = v26->mWorldTransform.v0.z;
            UFG::PhysicsVehicle::GetVelocity(
              (UFG::PhysicsVehicle *)this->mParameters.mSimObject.m_pPointer,
              (UFG::qVector3 *)&v150);
            *(float *)&this->mParameters.modelName.mStringHashUpper32 = (float)((float)(v150.v0.y * v47)
                                                                              + (float)(v150.v0.x * v46))
                                                                      + (float)(v150.v0.z * v48);
          }
          else if ( mCurrentLod == NUM_LOD_SETTING )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v26);
            localWorld = v26->mWorldTransform;
            ((void (__fastcall *)(UFG::SimObject *, UFG::qMatrix44 *, unsigned int *))this->mParameters.mSimObject.m_pPointer->vfptr[5].__vecDelDtor)(
              this->mParameters.mSimObject.m_pPointer,
              &localWorld,
              &this->m_TypeUID);
          }
          goto LABEL_204;
        }
        UFG::TransformNodeComponent::UpdateWorldTransform(v26);
        localWorld = v26->mWorldTransform;
        v49 = 0;
        v50 = *((_QWORD *)&this[-1] + 112);
        if ( v50 )
          v51 = *(_QWORD *)(*(_QWORD *)(v50 + 104) + 384i64);
        else
          v51 = 0i64;
        if ( this->mPrev
          && ((__int64 (__fastcall *)(UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *))this->mPrev->mPrev[7].mPrev)(this->mPrev)
          && !v24 )
        {
          v49 = 1;
          v52 = *(float *)&this->mDriverComponent.mPrev >= 1.0;
          v53 = (float *)this->mPrev;
          if ( result[0].m_bool )
            top_speed = this->mBoundingBoxMax.x;
          else
            top_speed = UFG::AiDriverComponent::m_TopSpeed;
          v54 = v53[263];
          v55 = localWorld.v0.x;
          localWorld.v2.y = localWorld.v0.x;
          v56 = localWorld.v0.y;
          *(float *)&result[0].m_bool = localWorld.v0.y;
          v57 = localWorld.v0.z;
          *(float *)&v154[0].m_bool = localWorld.v0.z;
          v155 = localWorld.v3.x;
          v148 = localWorld.v3.y;
          v149 = localWorld.v3.z;
          v58 = deltaTime * *(float *)&this->mParameters.modelName.mStringHashUpper32;
          v59 = v53[267];
          v60 = v53[268];
          v61 = v53[269];
          if ( v52 )
          {
            v62 = this->mParameters.mSimObject.m_pPointer;
            if ( v62 )
            {
              v64 = ((double (__fastcall *)(UFG::SimObject *))v62->vfptr[15].__vecDelDtor)(v62);
              v63 = *(float *)&v64;
            }
            else
            {
              v63 = FLOAT_0_78539819;
            }
            v65 = localWorld.v3.x;
            v66 = (float)(*(float *)&this->m_TypeUID * 0.5) * v63;
            cosf(v66);
            v67 = sinf(v66);
            v68 = (float)((float)((float)(v67 * localWorld.v1.x) + (float)(v66 * localWorld.v0.x))
                        + (float)(localWorld.v2.x * 0.0))
                + (float)(v65 * 0.0);
            v69 = (float)((float)((float)(v67 * localWorld.v1.y) + (float)(v66 * localWorld.v0.y))
                        + (float)(localWorld.v2.y * 0.0))
                + (float)(localWorld.v3.y * 0.0);
            v70 = (float)((float)((float)(v67 * localWorld.v1.z) + (float)(v66 * localWorld.v0.z))
                        + (float)(localWorld.v2.z * 0.0))
                + (float)(localWorld.v3.z * 0.0);
            v71 = v155;
            v59 = v68 + v155;
            v72 = v148;
            v60 = v69 + v148;
            v73 = v149;
            v61 = v70 + v149;
            v56 = *(float *)&result[0].m_bool;
            v57 = *(float *)&v154[0].m_bool;
          }
          else
          {
            v71 = v155;
            v72 = v148;
            v73 = v149;
          }
          v74 = v59 - v71;
          v75 = v60 - v72;
          v76 = v61 - v73;
          v77 = fsqrt((float)((float)(v75 * v75) + (float)(v74 * v74)) + (float)(v76 * v76));
          if ( v77 <= 0.050000001 )
          {
LABEL_152:
            v105 = this->mParameters.mSimObject.m_pPointer;
            if ( (HIDWORD(v105[4].m_pTransformNodeComponent) & 8) != 0 )
            {
              v106 = *(float *)&v105[4].mNode.mUID;
              Mass = UFG::PhysicsVehicle::GetMass((UFG::PhysicsVehicle *)v105);
              LODWORD(v108) = COERCE_UNSIGNED_INT(v106 / *(float *)&Mass) ^ _xmm[0];
            }
            else
            {
              v108 = deltaTime * this->mBoundingBoxMin.y;
              if ( v52 )
              {
                v108 = v108 * 0.5;
              }
              else
              {
                v109 = v54 - *(float *)&this->mParameters.modelName.mStringHashUpper32;
                if ( v109 > v108 )
                  v108 = v109;
                if ( v108 >= (float)(deltaTime * this->mBoundingBoxMin.x) )
                  v108 = deltaTime;
              }
            }
            v110 = v108 + *(float *)&this->mParameters.modelName.mStringHashUpper32;
            if ( v110 <= 0.0 )
              v110 = 0.0;
            if ( v110 >= top_speed )
              v110 = top_speed;
            *(float *)&this->mParameters.modelName.mStringHashUpper32 = v110;
            goto LABEL_197;
          }
          localWorld.v2.x = 1.0 / v77;
          v78 = v74 * (float)(1.0 / v77);
          v79 = v75 * (float)(1.0 / v77);
          v80 = v76 * (float)(1.0 / v77);
          v81 = (float)((float)(v79 * v56) + (float)(v78 * v55)) + (float)(v80 * v57);
          if ( ((__int64)this->m_pSimObject & 0x20) != 0 )
            v82 = deltaTime * 6.2831855;
          else
            v82 = UFG::PhysicsMoverInterface::GetCurvatureLimit(
                    (UFG::PhysicsMoverInterface *)((char *)this - 64),
                    *(float *)&this->mParameters.modelName.mStringHashUpper32)
                * v58;
          if ( v81 <= -1.0 )
          {
            v81 = FLOAT_N1_0;
          }
          else if ( v81 >= 1.0 )
          {
            v81 = *(float *)&FLOAT_1_0;
            goto LABEL_132;
          }
          if ( v81 <= -1.0 )
          {
            v81 = FLOAT_N1_0;
LABEL_135:
            LODWORD(v83) = COERCE_UNSIGNED_INT(acosf(v81)) & _xmm;
            if ( v83 > v82 )
            {
              v84 = (float)(v79 * *(float *)&v154[0].m_bool) - (float)(v80 * *(float *)&result[0].m_bool);
              v85 = localWorld.v2.y;
              v86 = (float)(v80 * localWorld.v2.y) - (float)(v78 * *(float *)&v154[0].m_bool);
              v87 = (float)(v78 * *(float *)&result[0].m_bool) - (float)(v79 * localWorld.v2.y);
              v88 = (float)((float)(v86 * v86) + (float)(v84 * v84)) + (float)(v87 * v87);
              if ( v88 == 0.0 )
                v89 = 0.0;
              else
                v89 = 1.0 / fsqrt(v88);
              localWorld.v2.z = v84 * v89;
              localWorld.v2.w = v86 * v89;
              localWorld.v3.x = v87 * v89;
              UFG::qRotationMatrixAxis(&v150, (UFG::qVector3 *)&localWorld.v2.z, v82);
              v90 = (float)((float)(v150.v1.x * *(float *)&result[0].m_bool) + (float)(v150.v0.x * v85))
                  + (float)(v150.v2.x * *(float *)&v154[0].m_bool);
              y_low = (__m128)LODWORD(v150.v1.y);
              y_low.m128_f32[0] = (float)((float)(v150.v1.y * *(float *)&result[0].m_bool) + (float)(v150.v0.y * v85))
                                + (float)(v150.v2.y * *(float *)&v154[0].m_bool);
              v92 = (float)((float)(v150.v1.z * *(float *)&result[0].m_bool) + (float)(v150.v0.z * v85))
                  + (float)(v150.v2.z * *(float *)&v154[0].m_bool);
              v93 = y_low;
              v93.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v90 * v90))
                              + (float)(v92 * v92);
              if ( v93.m128_f32[0] == 0.0 )
                v94 = 0.0;
              else
                v94 = 1.0 / _mm_sqrt_ps(v93).m128_f32[0];
              v78 = v94 * v90;
              v79 = y_low.m128_f32[0] * v94;
              v80 = v92 * v94;
              SpeedLimitForCurvature = UFG::GetSpeedLimitForCurvature(
                                         localWorld.v2.x * v83,
                                         top_speed,
                                         this->mBoundingBoxMax.y);
              if ( v54 >= SpeedLimitForCurvature )
                v54 = SpeedLimitForCurvature;
              v96 = *(float *)&this->mParameters.modelName.mStringHashUpper32;
              if ( v54 < v96 )
                v96 = v54;
              v58 = v96 * deltaTime;
            }
            v97 = (float)(v80 * 0.0) - v79;
            v98 = v78 - (float)(v80 * 0.0);
            v99 = (float)(v79 * 0.0) - (float)(v78 * 0.0);
            v100 = (float)((float)(v98 * v98) + (float)(v97 * v97)) + (float)(v99 * v99);
            if ( v100 == 0.0 )
              v101 = 0.0;
            else
              v101 = 1.0 / fsqrt(v100);
            v102 = v97 * v101;
            v103 = v98 * v101;
            v104 = v99 * v101;
            if ( v58 > 0.0049999999 )
            {
              localWorld.v3.x = v155 + (float)(v78 * v58);
              localWorld.v3.y = v148 + (float)(v79 * v58);
              localWorld.v3.z = v149 + (float)(v80 * v58);
              localWorld.v3.w = 1.0;
              localWorld.v0.x = v78;
              localWorld.v0.y = v79;
              localWorld.v0.z = v80;
              localWorld.v0.w = 0.0;
              localWorld.v1.x = v102;
              localWorld.v1.y = v103;
              localWorld.v1.z = v104;
              localWorld.v1.w = 0.0;
              localWorld.v2.x = (float)(v104 * v79) - (float)(v103 * v80);
              localWorld.v2.y = (float)(v102 * v80) - (float)(v104 * v78);
              localWorld.v2.z = (float)(v103 * v78) - (float)(v102 * v79);
              localWorld.v2.w = 0.0;
            }
            goto LABEL_152;
          }
LABEL_132:
          if ( v81 >= 1.0 )
            v81 = *(float *)&FLOAT_1_0;
          goto LABEL_135;
        }
        if ( !v51 || v24 || v51 == -376 || !*(_BYTE *)(v51 + 544) )
        {
LABEL_197:
          ((void (__fastcall *)(UFG::SimObject *, UFG::qMatrix44 *, unsigned int *))this->mParameters.mSimObject.m_pPointer->vfptr[5].__vecDelDtor)(
            this->mParameters.mSimObject.m_pPointer,
            &localWorld,
            &this->m_TypeUID);
          if ( (_BYTE)v152 )
          {
            if ( !v24 )
            {
              v143 = this->mParameters.mSimObject.m_pPointer;
              if ( v143 )
              {
                v144 = 0i64;
                if ( (BYTE4(v143[4].m_pTransformNodeComponent) & 7) != 0 )
                  v144 = this->mParameters.mSimObject.m_pPointer;
                if ( v144 )
                  UFG::PhysicsWheeledVehicle::QueueAsyncQueryForGroundFixup(
                    (UFG::PhysicsWheeledVehicle *)v144,
                    v49,
                    this->mPrev != 0i64,
                    COERCE_FLOAT(this->mParameters.modelName.mStringHashUpper32 & _xmm) > 0.050000001);
              }
            }
          }
          goto LABEL_204;
        }
        v49 = 1;
        v111 = *(float *)&this->mDriverComponent.mPrev >= 1.0;
        Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)(v51 + 376));
        UFG::RoadNetworkLocation::GetPos(Name, (UFG::qVector3 *)&localWorld.v3.z);
        UFG::RoadNetworkLocation::GetTangent(Name, (UFG::qVector3 *)&v150);
        v113 = (__m128)LODWORD(v150.v0.y);
        v113.m128_f32[0] = (float)(v113.m128_f32[0] * v113.m128_f32[0]) + (float)(v150.v0.x * v150.v0.x);
        v114 = _mm_sqrt_ps(v113);
        v115 = v114;
        v115.m128_f32[0] = (float)(v114.m128_f32[0] * v114.m128_f32[0]) + (float)(v150.v0.z * v150.v0.z);
        if ( v115.m128_f32[0] == 0.0 )
          v116 = 0.0;
        else
          v116 = 1.0 / _mm_sqrt_ps(v115).m128_f32[0];
        v114.m128_f32[0] = v114.m128_f32[0] * v116;
        v117 = v150.v0.z * v116;
        if ( v111 )
        {
          v118 = (float)(deltaTime * 0.5) * this->mBoundingBoxMin.y;
        }
        else
        {
          v119 = *(float *)&this->m_Flags;
          if ( v119 > 0.0 )
          {
            *(float *)&this->mParameters.modelName.mStringHashUpper32 = (float)((float)(v119 * deltaTime)
                                                                              * this->mBoundingBoxMin.y)
                                                                      + *(float *)&this->mParameters.modelName.mStringHashUpper32;
LABEL_181:
            v121 = *(float *)&this->mParameters.modelName.mStringHashUpper32;
            if ( v121 <= 0.0 )
              v121 = 0.0;
            if ( v121 >= this->mBoundingBoxMax.x )
              v121 = this->mBoundingBoxMax.x;
            *(float *)&this->mParameters.modelName.mStringHashUpper32 = v121;
            x_low = LODWORD(localWorld.v0.x);
            v123 = (__m128)LODWORD(localWorld.v0.y);
            v124 = localWorld.v0.z;
            if ( v121 > 1.0 )
            {
              v125 = *(float *)&this->m_TypeUID * 0.30000001;
              v126 = (float)(localWorld.v0.y * v125) + localWorld.v0.x;
              v127 = (float)(COERCE_FLOAT(LODWORD(localWorld.v0.x) ^ _xmm[0]) * v125) + localWorld.v0.y;
              v123 = v114;
              v123.m128_f32[0] = v114.m128_f32[0] / fsqrt((float)(v127 * v127) + (float)(v126 * v126));
              x_low = (__int128)v123;
              *(float *)&x_low = v123.m128_f32[0] * v126;
              v123.m128_f32[0] = v123.m128_f32[0] * v127;
              v124 = v117;
            }
            v128 = v123;
            v128.m128_f32[0] = (float)((float)(v123.m128_f32[0] * v123.m128_f32[0])
                                     + (float)(*(float *)&x_low * *(float *)&x_low))
                             + (float)(v124 * v124);
            if ( v128.m128_f32[0] == 0.0 )
              v129 = 0.0;
            else
              v129 = 1.0 / _mm_sqrt_ps(v128).m128_f32[0];
            v130 = x_low;
            *(float *)&v130 = *(float *)&x_low * v129;
            v131 = v123.m128_f32[0] * v129;
            v132 = v124 * v129;
            LODWORD(v133) = COERCE_UNSIGNED_INT(v123.m128_f32[0] * v129) ^ _xmm[0];
            v134 = (__m128)v130;
            v134.m128_f32[0] = (float)(*(float *)&v130 * *(float *)&v130) + (float)(v133 * v133);
            if ( v134.m128_f32[0] == 0.0 )
              v135 = 0.0;
            else
              v135 = 1.0 / _mm_sqrt_ps(v134).m128_f32[0];
            v136 = v135 * v133;
            *(float *)&result[0].m_bool = v135 * v133;
            *(float *)&v154[0].m_bool = *(float *)&v130 * v135;
            v137 = v135 * 0.0;
            v138 = (float)(v137 * v131) - (float)(*(float *)&v154[0].m_bool * v132);
            v139 = (float)(v136 * v132) - (float)(v137 * *(float *)&v130);
            v140 = (float)(*(float *)&v154[0].m_bool * *(float *)&v130) - (float)(v136 * v131);
            v141 = (float)((float)(v139 * v139) + (float)(v138 * v138)) + (float)(v140 * v140);
            if ( v141 == 0.0 )
              v142 = 0.0;
            else
              v142 = 1.0 / fsqrt(v141);
            LODWORD(localWorld.v0.x) = v130;
            localWorld.v0.y = v131;
            localWorld.v0.z = v132;
            localWorld.v0.w = 0.0;
            localWorld.v1.x = *(float *)&result[0].m_bool;
            localWorld.v1.y = *(float *)&v154[0].m_bool;
            localWorld.v1.z = v137;
            localWorld.v1.w = 0.0;
            localWorld.v2.x = v142 * v138;
            localWorld.v2.y = v142 * v139;
            localWorld.v2.z = v142 * v140;
            localWorld.v2.w = 0.0;
            localWorld.v3.x = (float)((float)(v121 * *(float *)&x_low) * deltaTime) + localWorld.v3.x;
            localWorld.v3.y = (float)((float)(v121 * v123.m128_f32[0]) * deltaTime) + localWorld.v3.y;
            localWorld.v3.z = top_speed;
            localWorld.v3.w = 1.0;
            goto LABEL_197;
          }
          if ( v119 < 0.0 )
          {
            v120 = *(float *)&this->mParameters.modelName.mStringHashUpper32
                 - (float)((float)(v119 * deltaTime) * this->mBoundingBoxMin.x);
LABEL_180:
            *(float *)&this->mParameters.modelName.mStringHashUpper32 = v120;
            goto LABEL_181;
          }
          v118 = deltaTime * this->mBoundingBoxMin.z;
        }
        v120 = v118 + *(float *)&this->mParameters.modelName.mStringHashUpper32;
        goto LABEL_180;
      }
    }
    v30 = 1;
    goto LABEL_92;
  }
}aTime) + localWorld.v3.x;
            localWorld.v3.y = (float)((float)(v121 * v123.m128_f32[0]) * deltaTime) + localWorld.v3.y;
            localWorld.v3.z = top_speed;
            localWorld.v3.w = 1.0;
            goto LABEL_197;
          }
          if ( v119 < 0.0 )
          {
            v120 = *(float *)&this->mParameters.modelNa

// File Line: 1196
// RVA: 0x69A600
void __fastcall UFG::PhysicsMoverInterface::UpdateTransforms(UFG::PhysicsMoverInterface *this, float delta_seconds)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::CharacterAnimationComponent *v6; // rax
  Creature *mCreature; // rax
  SkeletalPose *p_mPose; // r15
  UFG::SimObject *v9; // rax
  UFG::SimComponent *m_pComponent; // rbx
  UFG::qMatrix44 *p_mBodyTransform; // r12
  UFG::qVector3 *Velocity; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::PhysicsVehicle *v15; // r13
  __int64 v16; // rbx
  UFG::PhysicsWheeledVehicle *v17; // r14
  unsigned int v18; // edx
  int v19; // eax
  char *v20; // rbx
  _DWORD *array; // rsi
  signed __int64 v22; // r14
  __int64 v23; // r15
  int v24; // xmm2_4
  __m128 v25; // xmm3
  int mNumWheels; // eax
  UFG::qSafeArray<int,4> *p_mWheelBoneId; // r12
  int *v28; // r14
  __int64 v29; // rsi
  __m128 v30; // xmm3
  __m128 v31; // xmm4
  __m128 v32; // xmm5
  __m128 v33; // xmm6
  __m128 v34; // xmm6
  __m128 v35; // xmm3
  __m128 v36; // xmm7
  __m128 v37; // xmm8
  __m128 v38; // xmm9
  hkQuaternionf *p_m_rotation; // rcx
  __int64 v40; // rdx
  __m128 v41; // xmm3
  __m128 v42; // xmm4
  __m128 v43; // xmm6
  __m128 v44; // xmm6
  __m128 v45; // xmm3
  __m128 v46; // xmm6
  __m128 v47; // xmm3
  __m128 v48; // xmm4
  __m128 v49; // xmm5
  __m128 v50; // xmm5
  __m128 v51; // xmm6
  float WheelAngle; // xmm8_4
  float v53; // xmm6_4
  double v54; // xmm0_8
  int v55; // xmm0_4
  float v56; // xmm0_4
  float v57; // xmm7_4
  float MaxSuspensionLength; // xmm6_4
  float MinSuspensionLength; // xmm0_4
  __m128 m_quad; // xmm6
  float v61; // xmm10_4
  float v62; // xmm8_4
  float v63; // xmm9_4
  float v64; // xmm6_4
  UFG::qMatrix44 *p_dest; // r8
  UFG::qMatrix44 *v66; // rcx
  UFG::qMatrix44 *v67; // rdx
  UFG::qMatrix44 *v68; // rax
  __int128 v69; // xmm3
  __m128 v70; // xmm0
  int *v71; // rax
  __int64 v72; // rsi
  float RudderAngle; // xmm0_4
  UFG::qSafeArray<int,2> *p_mMotorBoneId; // rbx
  __int64 v75; // rsi
  __int64 v76; // r14
  float mPropellerAngle; // xmm0_4
  UFG::qSafeArray<int,2> *p_mPropellerBoneId; // rbx
  __int64 v79; // rdx
  __int64 v80; // rdx
  __m128 v81; // xmm4
  __m128 v82; // xmm5
  __m128 v83; // xmm6
  __m128 v84; // xmm6
  __m128 v85; // xmm3
  UFG::qVector4 row_vec4; // [rsp+20h] [rbp-B8h] BYREF
  hkQuaternionf wheelTransform; // [rsp+30h] [rbp-A8h] BYREF
  __int128 v88; // [rsp+40h] [rbp-98h]
  _BYTE v89[24]; // [rsp+50h] [rbp-88h] BYREF
  hkQsTransformf matrixLS; // [rsp+68h] [rbp-70h] BYREF
  __int128 v91; // [rsp+98h] [rbp-40h]
  __int128 v92; // [rsp+A8h] [rbp-30h]
  __int64 v93[2]; // [rsp+C8h] [rbp-10h] BYREF
  int v94; // [rsp+D8h] [rbp+0h]
  int v95; // [rsp+DCh] [rbp+4h]
  int v96; // [rsp+E0h] [rbp+8h]
  int v97; // [rsp+E4h] [rbp+Ch]
  hkVector4f v98; // [rsp+E8h] [rbp+10h]
  hkQuaternionf v99; // [rsp+F8h] [rbp+20h]
  UFG::qVector4 result; // [rsp+108h] [rbp+30h] BYREF
  __int64 v101; // [rsp+118h] [rbp+40h]
  UFG::qVector4 v102; // [rsp+120h] [rbp+48h] BYREF
  UFG::qMatrix44 dest; // [rsp+138h] [rbp+60h] BYREF
  hkQsTransformf axleTransform; // [rsp+178h] [rbp+A0h] BYREF
  UFG::qMatrix44 v105; // [rsp+238h] [rbp+160h] BYREF
  UFG::qMatrix44 v106; // [rsp+278h] [rbp+1A0h] BYREF
  UFG::qMatrix44 v107; // [rsp+2B8h] [rbp+1E0h] BYREF
  char v108; // [rsp+2F8h] [rbp+220h] BYREF
  Creature *v109; // [rsp+3B8h] [rbp+2E0h]

  v101 = -2i64;
  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
  {
    if ( mPhysicsVehicle->mRigidBody->mBody )
    {
      m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
      if ( m_pSimObject )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
        if ( v6 )
        {
          mCreature = v6->mCreature;
          v109 = mCreature;
          if ( mCreature )
          {
            p_mPose = &mCreature->mPose;
            if ( mCreature->mPose.mRigHandle.mData )
            {
              v9 = this->m_pSimObject;
              if ( v9 )
              {
                m_pComponent = v9->m_Components.p[2].m_pComponent;
                if ( m_pComponent )
                {
                  UFG::PhysicsVehicle::ComputeBodyTransform(this->mPhysicsVehicle);
                  p_mBodyTransform = &this->mPhysicsVehicle->mBodyTransform;
                  UFG::TransformNodeComponent::SetWorldTransform(
                    (UFG::TransformNodeComponent *)m_pComponent,
                    p_mBodyTransform);
                  Velocity = UFG::PhysicsVehicle::GetVelocity(this->mPhysicsVehicle, (UFG::qVector3 *)&row_vec4);
                  y = Velocity->y;
                  z = Velocity->z;
                  *(float *)&m_pComponent[4].vfptr = Velocity->x;
                  *((float *)&m_pComponent[4].vfptr + 1) = y;
                  *(float *)&m_pComponent[4].m_SafePointerList.mNode.mPrev = z;
                  this->mPhysicsVehicle->vfptr[2].__vecDelDtor(this->mPhysicsVehicle, (unsigned int)p_mBodyTransform);
                  v15 = this->mPhysicsVehicle;
                  if ( v15 )
                  {
                    v16 = 0i64;
                    v17 = 0i64;
                    if ( (*((_BYTE *)v15 + 604) & 7) != 0 )
                      v17 = (UFG::PhysicsWheeledVehicle *)this->mPhysicsVehicle;
                    if ( v17 )
                    {
                      v18 = _S26_4;
                      if ( (_S26_4 & 1) == 0 )
                      {
                        v18 = _S26_4 | 1;
                        _S26_4 |= 1u;
                        flip_left.v0 = (UFG::qVector4)_xmm;
                        flip_left.v1 = (UFG::qVector4)_xmm;
                        flip_left.v2 = (UFG::qVector4)_xmm;
                        flip_left.v3 = (UFG::qVector4)_xmm;
                      }
                      if ( this->mPhysicsVehicle->mCurrentLod == LOD_MEDIUM )
                      {
                        WheelAngle = UFG::PhysicsWheeledVehicle::GetWheelAngle(v17, 0);
                        v53 = UFG::PhysicsMoverInterface::mWheelAngleRateLimit * delta_seconds;
                        v54 = ((double (__fastcall *)(UFG::PhysicsWheeledVehicle *))v17->vfptr[5].__vecDelDtor)(v17);
                        *(float *)&v55 = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v54 * this->mInput.mSteering) ^ _xmm[0])
                                       - this->mWheelRenderAngle;
                        if ( *(float *)&v55 <= COERCE_FLOAT(LODWORD(v53) ^ _xmm[0]) )
                          v55 = LODWORD(v53) ^ _xmm[0];
                        if ( *(float *)&v55 >= v53 )
                          *(float *)&v55 = v53;
                        v56 = *(float *)&v55 + this->mWheelRenderAngle;
                        this->mWheelRenderAngle = v56;
                        UFG::qRotationMatrixZ(&dest, v56);
                        UFG::qRotationMatrixY((UFG::qMatrix44 *)&matrixLS.m_translation.m_quad.m128_u16[4], WheelAngle);
                        if ( this->mNumWheels > 0 )
                        {
                          do
                          {
                            v57 = v17->mCurrentSuspensionLength.array[(int)v16];
                            MaxSuspensionLength = UFG::PhysicsWheeledVehicle::GetMaxSuspensionLength(v17, v16);
                            MinSuspensionLength = UFG::PhysicsWheeledVehicle::GetMinSuspensionLength(v17, v16);
                            if ( v57 <= MinSuspensionLength )
                              v57 = MinSuspensionLength;
                            if ( v57 >= MaxSuspensionLength )
                              v57 = MaxSuspensionLength;
                            m_quad = v17->mSuspensionDirChassisSpace[(int)v16].m_quad;
                            v61 = m_quad.m128_f32[0] * v57;
                            v62 = _mm_shuffle_ps(m_quad, m_quad, 85).m128_f32[0] * v57;
                            v63 = _mm_shuffle_ps(m_quad, m_quad, 170).m128_f32[0] * v57;
                            v64 = _mm_shuffle_ps(m_quad, m_quad, 255).m128_f32[0] * v57;
                            row_vec4 = (UFG::qVector4)v17->mHardPointChassisSpace[(int)v16];
                            if ( ((unsigned __int8)~(_BYTE)v16 & (this->mNumWheels != 2)) != 0 )
                            {
                              p_dest = (UFG::qMatrix44 *)&matrixLS.m_translation.m_quad.m128_u16[4];
                              v66 = &flip_left;
                              if ( (int)v16 >= this->mNumWheels >> 1 )
                              {
                                v67 = &v105;
                              }
                              else
                              {
                                v66 = UFG::qMatrix44::operator*(
                                        &flip_left,
                                        &v107,
                                        (UFG::qMatrix44 *)&matrixLS.m_translation.m_quad.m128_u16[4]);
                                p_dest = &dest;
                                v67 = (UFG::qMatrix44 *)&v108;
                              }
                              v68 = UFG::qMatrix44::operator*(v66, v67, p_dest);
                            }
                            else if ( (int)v16 >= this->mNumWheels >> 1 )
                            {
                              v93[0] = matrixLS.m_translation.m_quad.m128_i64[1];
                              v93[1] = matrixLS.m_rotation.m_vec.m_quad.m128_i64[0];
                              v94 = *(_DWORD *)&v89[8];
                              v95 = *(_DWORD *)&v89[12];
                              v96 = *(_DWORD *)&v89[16];
                              v97 = *(_DWORD *)&v89[20];
                              v98.m_quad = (__m128)matrixLS.m_translation;
                              v99.m_vec.m_quad = (__m128)matrixLS.m_rotation;
                              v68 = (UFG::qMatrix44 *)v93;
                            }
                            else
                            {
                              v68 = UFG::qMatrix44::operator*(
                                      (UFG::qMatrix44 *)&matrixLS.m_translation.m_quad.m128_u16[4],
                                      &v106,
                                      &dest);
                            }
                            v69 = (__int128)v68->v1;
                            v70 = (__m128)v68->v0;
                            *(UFG::qVector4 *)v89 = v68->v2;
                            v88 = v69;
                            wheelTransform.m_vec.m_quad = v70;
                            *(float *)&v89[16] = row_vec4.x + v61;
                            *(float *)&v89[20] = row_vec4.y + v62;
                            matrixLS.m_translation.m_quad.m128_f32[0] = row_vec4.z + v63;
                            matrixLS.m_translation.m_quad.m128_f32[1] = row_vec4.w + v64;
                            SkeletalPose::SetPositionMS(
                              p_mPose,
                              this->mWheelBoneId.array[(int)v16],
                              (UFG::qMatrix44 *)&wheelTransform);
                            v71 = (int *)UFG::operator*(&v102, (UFG::qVector4 *)&v89[16], p_mBodyTransform);
                            v72 = 2i64 * (int)v16;
                            matrixLS.m_scale.m_quad.m128_i32[2 * v72] = *v71;
                            matrixLS.m_scale.m_quad.m128_i32[2 * v72 + 1] = v71[1];
                            matrixLS.m_scale.m_quad.m128_i32[2 * v72 + 2] = v71[2];
                            matrixLS.m_scale.m_quad.m128_i32[2 * v72 + 3] = v71[3];
                            LODWORD(v16) = v16 + 1;
                          }
                          while ( (int)v16 < this->mNumWheels );
                        }
                      }
                      else if ( this->mPhysicsVehicle->mCurrentLod == LOD_HIGH )
                      {
                        if ( (v18 & 2) == 0 )
                        {
                          _S26_4 = v18 | 2;
                          flip.m_vec.m_quad = _xmm;
                        }
                        UFG::PhysicsWheeledVehicle::GetWheelTransforms(v17, &axleTransform, &wheelTransform, 1);
                        mNumWheels = this->mNumWheels;
                        if ( mNumWheels == 4 )
                        {
                          SkeletalPose::SetPositionWS(p_mPose, this->mAxleBoneId.array, &axleTransform, 4);
                          if ( this->mNumWheels > 0 )
                          {
                            p_mWheelBoneId = &this->mWheelBoneId;
                            v28 = &axleTransform.m_translation.m_quad.m128_i32[2];
                            v29 = 0i64;
                            do
                            {
                              if ( (v16 & 1) != 0 )
                              {
                                v30 = *(__m128 *)((char *)&wheelTransform.m_vec.m_quad + v29 * 4);
                                v31 = _mm_shuffle_ps(v30, v30, 255);
                                v32 = _mm_shuffle_ps(flip.m_vec.m_quad, flip.m_vec.m_quad, 255);
                                v33 = _mm_sub_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(flip.m_vec.m_quad, flip.m_vec.m_quad, 201), v30),
                                        _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), flip.m_vec.m_quad));
                                v34 = _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v33, v33, 201), _mm_mul_ps(v31, flip.m_vec.m_quad)),
                                        _mm_mul_ps(v30, v32));
                                v35 = _mm_mul_ps(v30, flip.m_vec.m_quad);
                                *(__m128 *)((char *)&wheelTransform.m_vec.m_quad + v29 * 4) = _mm_shuffle_ps(
                                                                                                v34,
                                                                                                _mm_unpackhi_ps(
                                                                                                  v34,
                                                                                                  _mm_sub_ps(
                                                                                                    _mm_mul_ps(v32, v31),
                                                                                                    _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)), _mm_shuffle_ps(v35, v35, 170)))),
                                                                                                196);
                              }
                              matrixLS.m_scale.m_quad.m128_i32[v29] = *(v28 - 2);
                              matrixLS.m_scale.m_quad.m128_i32[v29 + 1] = *(v28 - 1);
                              matrixLS.m_scale.m_quad.m128_i32[v29 + 2] = *v28;
                              matrixLS.m_scale.m_quad.m128_i32[v29 + 3] = v28[1];
                              matrixLS.m_translation.m_quad.m128_u64[0] = 0x3F8000003F800000i64;
                              *(hkVector4f *)((char *)&matrixLS.m_translation + 8) = (hkVector4f)aabbOut.m_quad;
                              *(hkQuaternionf *)&v89[8] = *(hkQuaternionf *)((char *)&wheelTransform + v29 * 4);
                              SkeletalPose::SetQsTransformLS(
                                p_mPose,
                                p_mWheelBoneId->array[0],
                                (hkQsTransformf *)&matrixLS.m_translation.m_quad.m128_u16[4]);
                              LODWORD(v16) = v16 + 1;
                              p_mWheelBoneId = (UFG::qSafeArray<int,4> *)((char *)p_mWheelBoneId + 4);
                              v28 += 12;
                              v29 += 4i64;
                            }
                            while ( (int)v16 < this->mNumWheels );
                          }
                        }
                        else if ( mNumWheels == 2 )
                        {
                          v36 = flip.m_vec.m_quad;
                          v37 = _mm_shuffle_ps(flip.m_vec.m_quad, flip.m_vec.m_quad, 255);
                          v38 = _mm_shuffle_ps(flip.m_vec.m_quad, flip.m_vec.m_quad, 201);
                          p_m_rotation = &axleTransform.m_rotation;
                          v40 = 2i64;
                          do
                          {
                            v41 = *(__m128 *)((char *)&wheelTransform.m_vec.m_quad + v16);
                            v42 = _mm_shuffle_ps(v41, v41, 255);
                            v43 = _mm_sub_ps(_mm_mul_ps(v38, v41), _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v36));
                            v44 = _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v43, v43, 201), _mm_mul_ps(v42, v36)),
                                    _mm_mul_ps(v41, v37));
                            v45 = _mm_mul_ps(v41, v36);
                            v46 = _mm_shuffle_ps(
                                    v44,
                                    _mm_unpackhi_ps(
                                      v44,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v37, v42),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                                          _mm_shuffle_ps(v45, v45, 170)))),
                                    196);
                            *(__m128 *)((char *)&wheelTransform + v16) = v46;
                            v47 = _mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 255);
                            v48 = _mm_shuffle_ps(v46, v46, 255);
                            v49 = _mm_sub_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), p_m_rotation->m_vec.m_quad),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201),
                                      v46));
                            v50 = _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v49, v49, 201), _mm_mul_ps(v46, v47)),
                                    _mm_mul_ps(p_m_rotation->m_vec.m_quad, v48));
                            v51 = _mm_mul_ps(v46, p_m_rotation->m_vec.m_quad);
                            p_m_rotation->m_vec.m_quad = _mm_shuffle_ps(
                                                           v50,
                                                           _mm_unpackhi_ps(
                                                             v50,
                                                             _mm_sub_ps(
                                                               _mm_mul_ps(v48, v47),
                                                               _mm_add_ps(
                                                                 _mm_add_ps(
                                                                   _mm_shuffle_ps(v51, v51, 85),
                                                                   _mm_shuffle_ps(v51, v51, 0)),
                                                                 _mm_shuffle_ps(v51, v51, 170)))),
                                                           196);
                            *(int *)((char *)matrixLS.m_scale.m_quad.m128_i32 + v16) = p_m_rotation[-1].m_vec.m_quad.m128_i32[0];
                            *(int *)((char *)&matrixLS.m_scale.m_quad.m128_i32[1] + v16) = p_m_rotation[-1].m_vec.m_quad.m128_i32[1];
                            *(int *)((char *)&matrixLS.m_scale.m_quad.m128_i32[2] + v16) = p_m_rotation[-1].m_vec.m_quad.m128_i32[2];
                            *(int *)((char *)&matrixLS.m_scale.m_quad.m128_i32[3] + v16) = p_m_rotation[-1].m_vec.m_quad.m128_i32[3];
                            p_m_rotation += 3;
                            v16 += 16i64;
                            --v40;
                          }
                          while ( v40 );
                          SkeletalPose::SetPositionWS(p_mPose, this->mWheelBoneId.array, &axleTransform, 2);
                        }
                      }
                      else
                      {
                        v19 = this->mNumWheels;
                        if ( v19 > 0 )
                        {
                          v20 = &matrixLS.m_scale.m_quad.m128_i8[4];
                          array = (_DWORD *)v17->mRestingSuspensionLength.array;
                          v22 = (char *)v17 - (char *)&matrixLS.m_scale.m_quad.m128_i16[2];
                          v23 = (unsigned int)v19;
                          do
                          {
                            v24 = *array ^ _xmm[0];
                            v25 = *(__m128 *)&v20[v22 + 672];
                            LODWORD(row_vec4.x) = v25.m128_i32[0];
                            LODWORD(row_vec4.y) = _mm_shuffle_ps(v25, v25, 85).m128_u32[0];
                            row_vec4.z = _mm_shuffle_ps(v25, v25, 170).m128_f32[0] + *(float *)&v24;
                            row_vec4.w = *(float *)&v20[v22 + 684];
                            *(UFG::qVector4 *)(v20 - 4) = *UFG::operator*(&result, &row_vec4, p_mBodyTransform);
                            ++array;
                            v20 += 16;
                            --v23;
                          }
                          while ( v23 );
                        }
                      }
                      UFG::PhysicsMoverInterface::UpdateTargetSpheres(this, (UFG::qVector4 *)&matrixLS.m_scale);
                    }
                    else if ( (*((_BYTE *)v15 + 604) & 7) == 0 && v15->mCurrentLod != LOD_LOW )
                    {
                      RudderAngle = UFG::PhysicsBoat::GetRudderAngle((UFG::PhysicsBoat *)this->mPhysicsVehicle);
                      UFG::qRotationMatrixZ(
                        (UFG::qMatrix44 *)&matrixLS.m_scale,
                        COERCE_FLOAT(LODWORD(RudderAngle) ^ _xmm[0]));
                      p_mMotorBoneId = &this->mMotorBoneId;
                      v75 = 2i64;
                      v76 = 2i64;
                      do
                      {
                        if ( p_mMotorBoneId->array[0] != -1 )
                        {
                          SkeletalPose::GetPositionLS(
                            p_mPose,
                            p_mMotorBoneId->array[0],
                            (UFG::qMatrix44 *)&wheelTransform);
                          wheelTransform.m_vec.m_quad = (__m128)matrixLS.m_scale;
                          v88 = v91;
                          *(_OWORD *)v89 = v92;
                          SkeletalPose::SetPositionLS(
                            p_mPose,
                            p_mMotorBoneId->array[0],
                            (UFG::qMatrix44 *)&wheelTransform);
                        }
                        p_mMotorBoneId = (UFG::qSafeArray<int,2> *)((char *)p_mMotorBoneId + 4);
                        --v76;
                      }
                      while ( v76 );
                      if ( v15->mCurrentLod == LOD_HIGH )
                      {
                        if ( this->mDriverComponent.m_pSimComponent )
                          this->mPropellerAngle = (float)((float)(this->mForwardSpeed * 5.0) * delta_seconds)
                                                + this->mPropellerAngle;
                        mPropellerAngle = this->mPropellerAngle;
                        if ( mPropellerAngle > 6.2831855 )
                          this->mPropellerAngle = mPropellerAngle - 6.2831855;
                        p_mPropellerBoneId = &this->mPropellerBoneId;
                        do
                        {
                          v79 = p_mPropellerBoneId->array[0];
                          if ( (_DWORD)v79 != -1 )
                          {
                            row_vec4 = (UFG::qVector4)_xmm;
                            v80 = (__int64)&p_mPose->mHavokPose->m_skeleton->m_referencePose.m_data[v79];
                            *(hkVector4f *)((char *)&matrixLS.m_translation + 8) = *(hkVector4f *)v80;
                            *(_OWORD *)&v89[8] = *(_OWORD *)(v80 + 16);
                            matrixLS.m_translation = *(hkVector4f *)(v80 + 32);
                            hkQuaternionf::setAxisAngle(
                              (hkQuaternionf *)&result,
                              (hkVector4f *)&row_vec4,
                              this->mPropellerAngle);
                            v81 = _mm_shuffle_ps(*(__m128 *)&v89[8], *(__m128 *)&v89[8], 255);
                            v82 = _mm_shuffle_ps((__m128)result, (__m128)result, 255);
                            v83 = _mm_sub_ps(
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)result, (__m128)result, 201), *(__m128 *)&v89[8]),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&v89[8], *(__m128 *)&v89[8], 201),
                                      (__m128)result));
                            v84 = _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v83, v83, 201), _mm_mul_ps((__m128)result, v81)),
                                    _mm_mul_ps(*(__m128 *)&v89[8], v82));
                            v85 = _mm_mul_ps((__m128)result, *(__m128 *)&v89[8]);
                            *(__m128 *)&v89[8] = _mm_shuffle_ps(
                                                   v84,
                                                   _mm_unpackhi_ps(
                                                     v84,
                                                     _mm_sub_ps(
                                                       _mm_mul_ps(v82, v81),
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v85, v85, 85),
                                                           _mm_shuffle_ps(v85, v85, 0)),
                                                         _mm_shuffle_ps(v85, v85, 170)))),
                                                   196);
                            SkeletalPose::SetQsTransformLS(
                              p_mPose,
                              p_mPropellerBoneId->array[0],
                              (hkQsTransformf *)&matrixLS.m_translation.m_quad.m128_u16[4]);
                          }
                          p_mPropellerBoneId = (UFG::qSafeArray<int,2> *)((char *)p_mPropellerBoneId + 4);
                          --v75;
                        }
                        while ( v75 );
                      }
                    }
                  }
                  Creature::updateEffectorsToPose(v109);
                  Creature::UpdateAttachmentPoses(v109);
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
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx

  v1 = *((_DWORD *)this + 224);
  if ( (v1 & 2) == 0 )
  {
    *((_DWORD *)this + 224) = v1 | 2;
    mPhysicsVehicle = this->mPhysicsVehicle;
    if ( mPhysicsVehicle )
      mPhysicsVehicle->vfptr[2].DebugDraw(mPhysicsVehicle);
    this->m_Flags |= 2u;
  }
}

// File Line: 1456
// RVA: 0x689A50
void __fastcall UFG::PhysicsMoverInterface::Restore(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx

  if ( (*((_BYTE *)this + 896) & 2) != 0 )
  {
    mPhysicsVehicle = this->mPhysicsVehicle;
    if ( mPhysicsVehicle )
      ((void (__fastcall *)(UFG::PhysicsVehicle *))mPhysicsVehicle->vfptr[2].ResourceUnloaded)(mPhysicsVehicle);
    this->m_Flags &= ~2u;
    *((_DWORD *)this + 224) &= ~2u;
  }
}

// File Line: 1472
// RVA: 0x67A700
__int64 __fastcall UFG::PhysicsMoverInterface::GetLOD(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
    return (unsigned int)mPhysicsVehicle->mCurrentLod;
  else
    return 1i64;
}

// File Line: 1479
// RVA: 0x68A9B0
void __fastcall UFG::PhysicsMoverInterface::SetLOD(UFG::PhysicsMoverInterface *this, UFG::PhysicsVehicle::Lod lod)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax

  if ( lod == LOD_HIGH )
    ((void (__fastcall *)(UFG::PhysicsMoverInterface *))this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[9].__vecDelDtor)(this);
  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
    mPhysicsVehicle->mDesiredLod = lod;
  switch ( lod )
  {
    case LOD_UNINITIALIZED:
    case LOD_LOW:
    case LOD_NIS:
    case LOD_RESOURCES_UNLOADED:
      UFG::PhysicsMoverInterface::DeactivateTargetSpheres(this);
      break;
    case LOD_MEDIUM:
    case LOD_HIGH:
      UFG::PhysicsMoverInterface::ActivateTargetSpheres(this);
      break;
    default:
      return;
  }
}

// File Line: 1519
// RVA: 0x67FDD0
void __fastcall UFG::PhysicsMoverInterface::LockHighLod(
        UFG::PhysicsMoverInterface *this,
        UFG::PhysicsMoverInterface::ELODLockMode eMode,
        float time)
{
  int v3; // eax
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax

  v3 = *((_DWORD *)this + 224);
  if ( (v3 & 1) == 0 && (v3 & 8) == 0 )
  {
    UFG::OnlineManager::Instance();
    ((void (__fastcall *)(UFG::PhysicsMoverInterface *))this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[9].__vecDelDtor)(this);
    mPhysicsVehicle = this->mPhysicsVehicle;
    if ( mPhysicsVehicle )
      mPhysicsVehicle->mDesiredLod = LOD_HIGH;
    UFG::PhysicsMoverInterface::ActivateTargetSpheres(this);
    this->mLockAtHighLODMode = eMode;
    this->mLockAtHighLODTime = time;
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
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimComponent *m_pComponent; // r14
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **p_mNext; // r15
  __int64 v6; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rbx
  int i; // ecx
  int j; // esi
  int k; // edi
  UFG::SimObjectGame *v11; // rcx
  int v12; // edx
  int v13; // r8d
  __int64 v14; // rax
  __int64 m; // rcx
  int v16; // edx
  __int64 n; // rcx
  int ii; // ecx
  __int16 m_Flags; // dx
  UFG::SimComponent *v20; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_pComponent = m_pSimObject->m_Components.p[30].m_pComponent;
    if ( m_pComponent )
    {
      p_mNext = &m_pComponent[1].m_BoundComponentHandles.mNode.mNext;
      v6 = (__int64)&m_pComponent[1].m_BoundComponentHandles.mNode.mNext[-4];
      p_m_BoundComponentHandles = &m_pComponent->m_BoundComponentHandles;
      if ( m_pComponent[1].m_pSimObject )
      {
        for ( i = 0;
              (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v6 != p_m_BoundComponentHandles;
              v6 = *(_QWORD *)(v6 + 72) - 64i64 )
        {
          ++i;
        }
        j = i + 1;
      }
      else
      {
        for ( j = 0;
              (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v6 != p_m_BoundComponentHandles;
              v6 = *(_QWORD *)(v6 + 72) - 64i64 )
        {
          ++j;
        }
      }
      for ( k = 0; k < j; ++k )
      {
        v11 = (UFG::SimObjectGame *)m_pComponent[1].m_pSimObject;
        if ( v11 )
        {
          if ( !k )
            goto LABEL_26;
          v12 = k - 1;
          v13 = 0;
          v14 = (__int64)&(*p_mNext)[-4];
          for ( m = v14;
                (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)m != p_m_BoundComponentHandles;
                m = *(_QWORD *)(m + 72) - 64i64 )
          {
            ++v13;
          }
          if ( v12 >= v13 )
            continue;
          for ( ; v12 > 0; v14 = *(_QWORD *)(v14 + 72) - 64i64 )
          {
            if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v14 == p_m_BoundComponentHandles )
              break;
            --v12;
          }
        }
        else
        {
          v16 = 0;
          v14 = (__int64)&(*p_mNext)[-4];
          for ( n = v14;
                (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)n != p_m_BoundComponentHandles;
                n = *(_QWORD *)(n + 72) - 64i64 )
          {
            ++v16;
          }
          if ( k >= v16 )
            continue;
          for ( ii = k; ii > 0; v14 = *(_QWORD *)(v14 + 72) - 64i64 )
          {
            if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v14 == p_m_BoundComponentHandles )
              break;
            --ii;
          }
        }
        v11 = *(UFG::SimObjectGame **)(v14 + 40);
LABEL_26:
        if ( v11 )
        {
          m_Flags = v11->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            v20 = v11->m_Components.p[20].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v11,
                                    UFG::TargetingSystemBaseComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
            v20 = ComponentOfTypeHK;
          }
          else
          {
            v20 = v11->m_Components.p[20].m_pComponent;
          }
          if ( v20 )
            ((void (__fastcall *)(UFG::SimComponent *, __int64, bool, bool, _DWORD, _QWORD, _QWORD, _QWORD))v20->vfptr[14].__vecDelDtor)(
              v20,
              28i64,
              lock,
              lock,
              0,
              0i64,
              0i64,
              0i64);
        }
      }
    }
  }
}

// File Line: 1566
// RVA: 0x6892E0
void __fastcall UFG::PhysicsMoverInterface::Reload(
        UFG::PhysicsMoverInterface *this,
        UFG::PhysicsMoverInterface::ReloadReason reason)
{
  UFG::qSymbol v4; // [rsp+50h] [rbp+18h] BYREF
  UFG::qSymbol propertySetName; // [rsp+58h] [rbp+20h] BYREF

  v4.mUID = -1;
  UFG::qSymbol::set_null(&v4);
  propertySetName.mUID = v4.mUID;
  UFG::PhysicsMoverInterface::Reload(this, reason, (__int64)&propertySetName);
}

// File Line: 1575
// RVA: 0x689340
void __fastcall UFG::PhysicsMoverInterface::Reload(
        UFG::PhysicsMoverInterface *this,
        unsigned int reason,
        unsigned int *propertySetName)
{
  unsigned int v6; // eax
  unsigned int mUID; // eax
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx
  UFG::PhysicsWheeledVehicle *v9; // rdi
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimComponent *m_pComponent; // rsi
  UFG::PhysicsVehicle::Lod mCurrentLod; // r15d
  int mPrev; // xmm2_4
  int mPrev_high; // xmm3_4
  int vfptr; // xmm0_4
  int mNext_high; // xmm1_4
  int m_TypeUID; // xmm2_4
  int m_NameUID; // xmm3_4
  int v19; // xmm2_4
  int m_pSimObject_high; // xmm3_4
  int v21; // xmm0_4
  int mNext; // xmm2_4
  int v23; // xmm3_4
  int v24; // xmm0_4
  UFG::PhysicsVehicle *v25; // rcx
  float v26; // xmm1_4
  float v27; // xmm2_4
  UFG::qVector3 *v28; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::PhysicsVehicle *v31; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v32; // rax
  UFG::SimObjectCVBase *v33; // rcx
  UFG::PhysicsVehicle *v34; // rax
  UFG::qVector3 velocity; // [rsp+20h] [rbp-60h] BYREF
  UFG::qVector3 result; // [rsp+30h] [rbp-50h] BYREF
  int v37[16]; // [rsp+40h] [rbp-40h] BYREF
  unsigned int v38; // [rsp+A0h] [rbp+20h] BYREF

  if ( this->mParameters.modelName.mStringHashUpper32 == -1 )
    this->mParameters.modelName.mStringHashUpper32 = UFG::qStringHashUpper32(this->mParameters.modelName.mData, -1);
  v6 = UFG::qStringHashUpper32("_Body_P", this->mParameters.modelName.mStringHashUpper32);
  if ( UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v6) )
  {
    mUID = *propertySetName;
    v38 = *propertySetName;
    if ( reason )
    {
      if ( reason != 1 )
        goto LABEL_9;
      mUID = this->mPropertySetNameHuman.mUID;
    }
    else
    {
      mUID = this->mPropertySetNameAI.mUID;
    }
    v38 = mUID;
LABEL_9:
    mPhysicsVehicle = this->mPhysicsVehicle;
    v9 = 0i64;
    if ( !mPhysicsVehicle || mUID != this->mParameters.mPhysicsPropertiesName.mUID )
    {
      this->mParameters.mPhysicsPropertiesName.mUID = mUID;
      if ( mPhysicsVehicle && reason <= 1 )
      {
        mPhysicsVehicle->vfptr[1].__vecDelDtor(mPhysicsVehicle, (unsigned int)&v38);
      }
      else
      {
        m_pSimObject = this->m_pSimObject;
        if ( m_pSimObject )
          m_pComponent = m_pSimObject->m_Components.p[2].m_pComponent;
        else
          m_pComponent = 0i64;
        mCurrentLod = LOD_LOW;
        if ( (*((_BYTE *)this + 896) & 8) != 0 )
        {
          mCurrentLod = LOD_NIS;
        }
        else if ( mPhysicsVehicle )
        {
          mCurrentLod = mPhysicsVehicle->mCurrentLod;
        }
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pComponent);
        mPrev = (int)m_pComponent[2].m_SafePointerList.mNode.mPrev;
        mPrev_high = HIDWORD(m_pComponent[2].m_SafePointerList.mNode.mPrev);
        vfptr = (int)m_pComponent[2].vfptr;
        v37[1] = HIDWORD(m_pComponent[2].vfptr);
        v37[2] = mPrev;
        v37[0] = vfptr;
        v37[3] = mPrev_high;
        mNext_high = HIDWORD(m_pComponent[2].m_SafePointerList.mNode.mNext);
        m_TypeUID = m_pComponent[2].m_TypeUID;
        m_NameUID = m_pComponent[2].m_NameUID;
        v37[4] = (int)m_pComponent[2].m_SafePointerList.mNode.mNext;
        v37[5] = mNext_high;
        v37[6] = m_TypeUID;
        v37[7] = m_NameUID;
        v19 = (int)m_pComponent[2].m_pSimObject;
        m_pSimObject_high = HIDWORD(m_pComponent[2].m_pSimObject);
        v21 = *(_DWORD *)&m_pComponent[2].m_Flags;
        v37[9] = *(_DWORD *)(&m_pComponent[2].m_SimObjIndex + 1);
        v37[8] = v21;
        v37[10] = v19;
        v37[11] = m_pSimObject_high;
        mNext = (int)m_pComponent[2].m_BoundComponentHandles.mNode.mNext;
        v23 = HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
        v24 = (int)m_pComponent[2].m_BoundComponentHandles.mNode.mPrev;
        v37[13] = HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mPrev);
        v37[14] = mNext;
        v37[12] = v24;
        v37[15] = v23;
        UFG::PhysicsMoverInterface::SetOccupantTargetLocks(this, 0);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pComponent);
        v25 = this->mPhysicsVehicle;
        v26 = *((float *)&m_pComponent[4].vfptr + 1);
        v27 = *(float *)&m_pComponent[4].m_SafePointerList.mNode.mPrev;
        velocity.x = *(float *)&m_pComponent[4].vfptr;
        velocity.y = v26;
        velocity.z = v27;
        if ( v25 )
        {
          v28 = UFG::PhysicsVehicle::GetVelocity(v25, &result);
          y = v28->y;
          z = v28->z;
          velocity.x = v28->x;
          velocity.y = y;
          velocity.z = z;
        }
        v31 = this->mPhysicsVehicle;
        if ( v31 )
          v31->vfptr->__vecDelDtor(v31, 1u);
        v32 = this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr;
        this->mPhysicsVehicle = 0i64;
        ((void (__fastcall *)(UFG::PhysicsMoverInterface *, int *, UFG::qVector3 *))v32[19].__vecDelDtor)(
          this,
          v37,
          &velocity);
        this->mPhysicsVehicle->mDesiredLod = mCurrentLod;
        UFG::PhysicsVehicle::SetVelocity(this->mPhysicsVehicle, &velocity);
        if ( (*((_BYTE *)this + 896) & 2) != 0 )
          this->mPhysicsVehicle->vfptr[2].DebugDraw(this->mPhysicsVehicle);
        UFG::PhysicsMoverInterface::SetOccupantTargetLocks(this, 1);
      }
    }
    if ( !reason
      || (v33 = (UFG::SimObjectCVBase *)this->m_pSimObject) != 0i64
      && UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v33) )
    {
      v34 = this->mPhysicsVehicle;
      if ( v34 )
      {
        if ( (*((_BYTE *)v34 + 604) & 7) != 0 )
          v9 = (UFG::PhysicsWheeledVehicle *)this->mPhysicsVehicle;
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
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx
  int v4; // edi
  UFG::PhysicsVehicle *v5; // rax
  float y; // xmm6_4
  void **p_owner; // rsi

  v1 = UFG::BulletManager::mInstance;
  mPhysicsVehicle = this->mPhysicsVehicle;
  v4 = 0;
  if ( !mPhysicsVehicle )
    goto LABEL_6;
  v5 = 0i64;
  if ( (*((_BYTE *)mPhysicsVehicle + 604) & 7) != 0 )
    v5 = mPhysicsVehicle;
  if ( v5 )
    y = v5[1].mTargetTransform.v0.y;
  else
LABEL_6:
    y = FLOAT_0_27000001;
  if ( this->mNumWheels > 0 )
  {
    p_owner = &this->mTargetSpheres[0].owner;
    do
    {
      *((float *)p_owner - 2) = y;
      *p_owner = this;
      *((_DWORD *)p_owner + 2) = v4;
      UFG::BulletManager::AddTargetSphere(v1, &this->mTargetSpheres[(__int64)v4++]);
      p_owner += 8;
    }
    while ( v4 < this->mNumWheels );
  }
  if ( this->mNumWheels == 4 )
  {
    this->mTargetSpheres[4].radius = y * 0.60000002;
    this->mTargetSpheres[(__int64)this->mNumWheels].owner = this;
    this->mTargetSpheres[(__int64)this->mNumWheels].userData = this->mNumWheels;
    UFG::BulletManager::AddTargetSphere(v1, &this->mTargetSpheres[(__int64)this->mNumWheels]);
  }
}

// File Line: 1714
// RVA: 0x6761E0
void __fastcall UFG::PhysicsMoverInterface::DeactivateTargetSpheres(UFG::PhysicsMoverInterface *this)
{
  UFG::BulletManager *v1; // rsi
  int i; // ebx

  v1 = UFG::BulletManager::mInstance;
  for ( i = 0; i < this->mNumWheels; ++i )
    UFG::BulletManager::RemoveTargetSphere(v1, &this->mTargetSpheres[(__int64)i]);
  if ( this->mNumWheels == 4 )
    UFG::BulletManager::RemoveTargetSphere(v1, &this->mTargetSpheres[4]);
}

// File Line: 1731
// RVA: 0x699F20
void __fastcall UFG::PhysicsMoverInterface::UpdateTargetSpheres(
        UFG::PhysicsMoverInterface *this,
        UFG::qVector4 *wheelPosition)
{
  int v2; // r9d
  float *p_z; // rax
  float *v5; // r8
  int v6; // xmm2_4
  int v7; // xmm0_4
  int v8; // xmm1_4
  int v9; // xmm0_4
  int v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  __int64 mNumWheels; // rdx
  UFG::qVector3 *p_positionT0; // rax
  float v15; // xmm1_4
  float v16; // xmm2_4
  __int64 v17; // rax
  float v18; // xmm1_4
  float v19; // xmm0_4
  __int64 v20; // rax
  float v21; // xmm1_4
  float v22; // xmm2_4

  v2 = 0;
  if ( this->mNumWheels > 0 )
  {
    p_z = &wheelPosition->z;
    v5 = &this->mTargetSpheres[0].positionT0.z;
    do
    {
      v6 = *((_DWORD *)p_z - 2);
      v7 = *((_DWORD *)p_z - 1);
      v8 = *(_DWORD *)p_z;
      ++v2;
      p_z += 4;
      v5 += 16;
      *((_DWORD *)v5 - 18) = v6;
      *((_DWORD *)v5 - 17) = v7;
      *((_DWORD *)v5 - 16) = v8;
      v9 = *((_DWORD *)p_z - 5);
      v10 = *((_DWORD *)p_z - 4);
      *(v5 - 15) = *(p_z - 6);
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
    mNumWheels = this->mNumWheels;
    p_positionT0 = &this->mTargetSpheres[mNumWheels].positionT0;
    v15 = (float)(wheelPosition[(int)mNumWheels - 1].y * 0.60000002) + p_positionT0->y;
    v16 = (float)(wheelPosition[(int)mNumWheels - 1].z * 0.60000002) + p_positionT0->z;
    p_positionT0->x = (float)(wheelPosition[(int)mNumWheels - 1].x * 0.60000002) + p_positionT0->x;
    p_positionT0->y = v15;
    p_positionT0->z = v16;
    v17 = (__int64)this->mNumWheels << 6;
    v18 = wheelPosition[this->mNumWheels - 2].y * 0.60000002;
    v19 = wheelPosition[this->mNumWheels - 2].z * 0.60000002;
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.x + v17) = wheelPosition[this->mNumWheels - 2].x * 0.60000002;
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.y + v17) = v18;
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.z + v17) = v19;
    LODWORD(mNumWheels) = this->mNumWheels;
    v20 = (__int64)(int)mNumWheels << 6;
    v21 = (float)(wheelPosition[(int)mNumWheels - 1].y * 0.40000001)
        + *(float *)((char *)&this->mTargetSpheres[0].positionT1.y + v20);
    v22 = (float)(wheelPosition[(int)mNumWheels - 1].z * 0.40000001)
        + *(float *)((char *)&this->mTargetSpheres[0].positionT1.z + v20);
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.x + v20) = (float)(wheelPosition[(int)mNumWheels - 1].x
                                                                            * 0.40000001)
                                                                    + *(float *)((char *)&this->mTargetSpheres[0].positionT1.x
                                                                               + v20);
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.y + v20) = v21;
    *(float *)((char *)&this->mTargetSpheres[0].positionT1.z + v20) = v22;
  }
}

// File Line: 1753
// RVA: 0x68BCA0
char __fastcall UFG::PhysicsMoverInterface::ShouldIgnoreBulletImpactDamageSphereEvent(
        UFG::PhysicsMoverInterface *this,
        UFG::SimObjectGame *weaponOwnerSimObject)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimComponentHolder *p; // rax
  UFG::SimComponent *v8; // rbx
  UFG::SimObjectCharacter *v9; // rsi
  unsigned int NumberOfOccupants; // eax
  int v11; // r10d
  unsigned int v12; // edi
  UFG::SimObjectCharacter *v13; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // r8
  int v15; // r9d
  __int64 v16; // rax
  int v17; // edx
  __int64 v18; // rcx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v19; // r8
  int v20; // edx
  __int64 v21; // rcx
  int v22; // ecx

  if ( !weaponOwnerSimObject )
    return 0;
  m_Flags = weaponOwnerSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = weaponOwnerSimObject->m_Components.p[17].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(weaponOwnerSimObject, UFG::CopUnitComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(weaponOwnerSimObject, UFG::CopUnitComponent::_TypeUID);
  }
  else
  {
    m_pComponent = weaponOwnerSimObject->m_Components.p[17].m_pComponent;
  }
  if ( m_pComponent )
    return 0;
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  p = m_pSimObject->m_Components.p;
  v8 = p[30].m_pComponent;
  if ( !v8 )
    return 0;
  v9 = LocalPlayer;
  NumberOfOccupants = UFG::VehicleOccupantComponent::GetNumberOfOccupants((UFG::VehicleOccupantComponent *)p[30].m_pComponent);
  v11 = 0;
  v12 = NumberOfOccupants;
  if ( !NumberOfOccupants )
    return 0;
  while ( 1 )
  {
    if ( v8[1].m_pSimObject )
    {
      if ( !v11 )
      {
        v13 = (UFG::SimObjectCharacter *)v8[1].m_pSimObject;
        goto LABEL_33;
      }
      p_m_BoundComponentHandles = &v8->m_BoundComponentHandles;
      v15 = 0;
      v16 = (__int64)&v8[1].m_BoundComponentHandles.mNode.mNext[-4];
      v17 = v11 - 1;
      v18 = v16;
      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v16 != &v8->m_BoundComponentHandles )
      {
        do
        {
          ++v15;
          v18 = *(_QWORD *)(v18 + 72) - 64i64;
        }
        while ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v18 != p_m_BoundComponentHandles );
      }
      if ( v17 < v15 )
      {
        for ( ; v17 > 0; v16 = *(_QWORD *)(v16 + 72) - 64i64 )
        {
          if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v16 == p_m_BoundComponentHandles )
            break;
          --v17;
        }
LABEL_24:
        v13 = *(UFG::SimObjectCharacter **)(v16 + 40);
        goto LABEL_33;
      }
    }
    else
    {
      v19 = &v8->m_BoundComponentHandles;
      v20 = 0;
      v16 = (__int64)&v8[1].m_BoundComponentHandles.mNode.mNext[-4];
      v21 = v16;
      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v16 != &v8->m_BoundComponentHandles )
      {
        do
        {
          ++v20;
          v21 = *(_QWORD *)(v21 + 72) - 64i64;
        }
        while ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v21 != v19 );
      }
      if ( v11 < v20 )
      {
        v22 = v11;
        if ( v11 > 0 )
        {
          while ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v16 != v19 )
          {
            --v22;
            v16 = *(_QWORD *)(v16 + 72) - 64i64;
            if ( v22 <= 0 )
            {
              v13 = *(UFG::SimObjectCharacter **)(v16 + 40);
              goto LABEL_33;
            }
          }
        }
        goto LABEL_24;
      }
    }
    v13 = 0i64;
LABEL_33:
    if ( v9 == v13 )
      return 1;
    if ( ++v11 >= v12 )
      return 0;
  }
}

// File Line: 1788
// RVA: 0x68CC60
void __fastcall UFG::PhysicsMoverInterface::TargetSphereEventHandler(UFG::PhysicsMoverInterface *this, UFG::Event *e)
{
  UFG::SimObject *m_pSimObject; // rax
  unsigned __int64 mUserData0; // r14
  __int64 v6; // rsi
  UFG::PhysicsVehicle *v7; // rcx
  double v8; // xmm0_8
  float v9; // xmm0_4
  double Mass; // xmm0_8
  UFG::SimObject *v11; // rax
  UFG::HitReactionComponent *v12; // r14
  UFG::SimObject *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rcx
  _QWORD *v19; // rax
  __int64 v20; // rax
  UFG::CopSystem *v21; // rax
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax
  UFG::SimObject *v23; // rax
  UFG::HitReactionComponent *m_pComponent; // rbx
  UFG::SimObject *mNext; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  __int64 v29; // rdx
  __int64 v30; // rcx
  _QWORD *v31; // rax
  float **v32; // rdx
  float *v33; // rax
  char v34; // [rsp+28h] [rbp-C0h]
  UFG::qVector3 impulse; // [rsp+30h] [rbp-B8h] BYREF
  UFG::HitRecord hitrecord; // [rsp+40h] [rbp-A8h] BYREF

  *(_QWORD *)&hitrecord.mAttackerNetworkID = -2i64;
  m_pSimObject = this->m_pSimObject;
  if ( (!m_pSimObject || (m_pSimObject->m_Flags & 0x800) == 0)
    && !UFG::PhysicsMoverInterface::ShouldIgnoreBulletImpactDamageSphereEvent(this, (UFG::SimObjectGame *)e[1].mNext) )
  {
    mUserData0 = e[2].mUserData0;
    if ( *(UFG::PhysicsMoverInterface **)(mUserData0 + 48) == this )
    {
      v6 = *(int *)(mUserData0 + 56);
      if ( (int)v6 < 0 || (int)v6 >= this->mNumWheels )
      {
        mPhysicsVehicle = this->mPhysicsVehicle;
        if ( mPhysicsVehicle )
        {
          if ( (*((_DWORD *)mPhysicsVehicle + 151) & 7) == 4 && (_DWORD)v6 == this->mNumWheels )
          {
            v23 = this->m_pSimObject;
            if ( v23 )
            {
              m_pComponent = (UFG::HitReactionComponent *)v23->m_Components.p[15].m_pComponent;
              if ( m_pComponent )
              {
                UFG::HitRecord::HitRecord(&hitrecord);
                mNext = (UFG::SimObject *)e[1].mNext;
                hitrecord.mAttackTypeID = gAttackCollisionVehicleGasTankShot.m_EnumValue;
                hitrecord.mDamage = 100;
                if ( hitrecord.mAttacker.m_pPointer )
                {
                  mPrev = hitrecord.mAttacker.mPrev;
                  v27 = hitrecord.mAttacker.mNext;
                  hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
                  v27->mPrev = mPrev;
                  hitrecord.mAttacker.mPrev = &hitrecord.mAttacker;
                  hitrecord.mAttacker.mNext = &hitrecord.mAttacker;
                }
                hitrecord.mAttacker.m_pPointer = mNext;
                if ( mNext )
                {
                  v28 = mNext->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                  v28->mNext = &hitrecord.mAttacker;
                  hitrecord.mAttacker.mPrev = v28;
                  hitrecord.mAttacker.mNext = &mNext->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
                  mNext->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &hitrecord.mAttacker;
                }
                hitrecord.mTimeSinceHit = 0.0;
                hitrecord.mFramesSinceHit = 0;
                v29 = e[1].mUserData0;
                if ( hitrecord.mMeleeInfo.mActionPath.mPath.mData.mOffset )
                {
                  v30 = *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z;
                  v31 = *(_QWORD **)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount;
                  *(_QWORD *)(*(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z + 8i64) = *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount;
                  *v31 = v30;
                  *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z = &hitrecord.mMeleeInfo.mHitNormal.z;
                  *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount = &hitrecord.mMeleeInfo.mHitNormal.z;
                }
                hitrecord.mMeleeInfo.mActionPath.mPath.mData.mOffset = v29;
                if ( v29 )
                {
                  v32 = (float **)(v29 + 8);
                  v33 = *v32;
                  *((_QWORD *)v33 + 1) = &hitrecord.mMeleeInfo.mHitNormal.z;
                  *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z = v33;
                  *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount = v32;
                  *v32 = &hitrecord.mMeleeInfo.mHitNormal.z;
                }
                hitrecord.mProjectileInfo.m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)e[1].mUserData1;
                LOWORD(hitrecord.mProjectileInfo.m_pSOWPC.mNext) = e[2].vfptr;
                UFG::HitReactionComponent::HandleHitReaction(m_pComponent, &hitrecord);
                goto LABEL_39;
              }
            }
          }
        }
      }
      else if ( this->mDamageState.tireDamage.array[v6] < 1.0 )
      {
        UFG::PhysicsMoverInterface::LockHighLod(this, ELODLockMode_TIMED, 10.0);
        UFG::PhysicsMoverInterface::DamageTire(this, (UFG::SimObject *)e[1].mNext, v6, 1.0);
        v7 = this->mPhysicsVehicle;
        if ( v7 && (*((_BYTE *)this + 896) & 1) == 0 )
        {
          if ( this->mDamageState.tireDamage.array[v6] < 1.0 )
          {
            Mass = UFG::PhysicsVehicle::GetMass(v7);
            v9 = *(float *)&Mass * this->mTireShotImpulse;
          }
          else
          {
            v8 = UFG::PhysicsVehicle::GetMass(v7);
            v9 = *(float *)&v8 * this->mTireBlownImpulse;
          }
          impulse.z = v9;
          *(_QWORD *)&impulse.x = 0i64;
          UFG::PhysicsVehicle::ApplyImpulse(this->mPhysicsVehicle, &impulse, (UFG::qVector3 *)(mUserData0 + 28));
        }
        v11 = this->m_pSimObject;
        if ( v11 )
        {
          v12 = (UFG::HitReactionComponent *)v11->m_Components.p[15].m_pComponent;
          if ( v12 )
          {
            UFG::HitRecord::HitRecord(&hitrecord);
            v13 = (UFG::SimObject *)e[1].mNext;
            hitrecord.mAttackTypeID = gAttackCollisionVehicleTireShot.m_EnumValue;
            hitrecord.mDamage = 100;
            if ( hitrecord.mAttacker.m_pPointer )
            {
              v14 = hitrecord.mAttacker.mPrev;
              v15 = hitrecord.mAttacker.mNext;
              hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
              v15->mPrev = v14;
              hitrecord.mAttacker.mPrev = &hitrecord.mAttacker;
              hitrecord.mAttacker.mNext = &hitrecord.mAttacker;
            }
            hitrecord.mAttacker.m_pPointer = v13;
            if ( v13 )
            {
              v16 = v13->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
              v16->mNext = &hitrecord.mAttacker;
              hitrecord.mAttacker.mPrev = v16;
              hitrecord.mAttacker.mNext = &v13->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
              v13->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &hitrecord.mAttacker;
            }
            *(_QWORD *)&hitrecord.mTimeSinceHit = 0i64;
            v17 = e[1].mUserData0;
            if ( hitrecord.mMeleeInfo.mActionPath.mPath.mData.mOffset )
            {
              v18 = *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z;
              v19 = *(_QWORD **)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount;
              *(_QWORD *)(*(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z + 8i64) = *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount;
              *v19 = v18;
              *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z = &hitrecord.mMeleeInfo.mHitNormal.z;
              *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount = &hitrecord.mMeleeInfo.mHitNormal.z;
            }
            hitrecord.mMeleeInfo.mActionPath.mPath.mData.mOffset = v17;
            if ( v17 )
            {
              v20 = *(_QWORD *)(v17 + 8);
              *(_QWORD *)(v20 + 8) = &hitrecord.mMeleeInfo.mHitNormal.z;
              *(_QWORD *)&hitrecord.mMeleeInfo.mHitNormal.z = v20;
              *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount = v17 + 8;
              *(_QWORD *)(v17 + 8) = &hitrecord.mMeleeInfo.mHitNormal.z;
            }
            hitrecord.mProjectileInfo.m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)e[1].mUserData1;
            LOWORD(hitrecord.mProjectileInfo.m_pSOWPC.mNext) = e[2].vfptr;
            v21 = UFG::CopSystem::Instance();
            v34 = 1;
            ((void (__fastcall *)(UFG::CopSystem *, UFG::qNode<UFG::Event,UFG::Event> *, UFG::SimObject *, UFG::HitRecord *, _QWORD, char))v21->vfptr[95].__vecDelDtor)(
              v21,
              e[1].mNext,
              this->m_pSimObject,
              &hitrecord,
              0i64,
              v34);
            UFG::GameStatAction::Vehicle::TireHit(
              (UFG::SimObjectCharacter *)e[1].mNext,
              (UFG::SimObjectCVBase *)this->m_pSimObject);
            UFG::HitReactionComponent::HandleHitReaction(v12, &hitrecord);
LABEL_39:
            UFG::HitRecord::~HitRecord(&hitrecord);
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
    return (UFG::PhysicsVehicle *)result->mRigidBody->mBody;
  return result;
}

// File Line: 2104
// RVA: 0x67B7D0
UFG::qVector3 *__fastcall UFG::PhysicsMoverInterface::GetVelocity(
        UFG::PhysicsMoverInterface *this,
        UFG::qVector3 *result)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx
  UFG::qVector3 *v5; // rax
  float y; // xmm1_4
  float z; // xmm2_4

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( !mPhysicsVehicle || UFG::PhysicsVehicle::IsSuspended(mPhysicsVehicle) )
  {
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    v5 = result;
    result->x = UFG::qVector3::msZero.x;
    result->y = y;
    result->z = z;
  }
  else
  {
    UFG::PhysicsVehicle::GetVelocity(this->mPhysicsVehicle, result);
    return result;
  }
  return v5;
}

// File Line: 2116
// RVA: 0x6795C0
UFG::qVector3 *__fastcall UFG::PhysicsMoverInterface::GetAngularVelocity(
        UFG::PhysicsMoverInterface *this,
        UFG::qVector3 *result)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx
  UFG::qVector3 *v5; // rax
  float y; // xmm1_4
  float z; // xmm2_4

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( !mPhysicsVehicle || UFG::PhysicsVehicle::IsSuspended(mPhysicsVehicle) )
  {
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    v5 = result;
    result->x = UFG::qVector3::msZero.x;
    result->y = y;
    result->z = z;
  }
  else
  {
    UFG::PhysicsVehicle::GetAngularVelocity(this->mPhysicsVehicle, result);
    return result;
  }
  return v5;
}

// File Line: 2128
// RVA: 0x6796B0
void __fastcall UFG::PhysicsMoverInterface::GetBoundingBoxLocalSpace(
        UFG::PhysicsMoverInterface *this,
        UFG::qVector3 *min,
        UFG::qVector3 *max)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  y = this->mBoundingBoxMin.y;
  z = this->mBoundingBoxMin.z;
  min->x = this->mBoundingBoxMin.x;
  min->y = y;
  min->z = z;
  v5 = this->mBoundingBoxMax.y;
  v6 = this->mBoundingBoxMax.z;
  max->x = this->mBoundingBoxMax.x;
  max->y = v5;
  max->z = v6;
}

// File Line: 2172
// RVA: 0x670840
bool __fastcall UFG::PhysicsMoverInterface::AreAllWheelsOnGround(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rdx
  UFG::PhysicsVehicle *v2; // rax

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( !mPhysicsVehicle )
    return 1;
  v2 = 0i64;
  if ( (*((_BYTE *)mPhysicsVehicle + 0x25C) & 7) != 0 )
    v2 = this->mPhysicsVehicle;
  return !v2 || ((__int64)v2[1].mReorientActionPitch & 0x10) != 0;
}

// File Line: 2184
// RVA: 0x67BA50
float __fastcall UFG::PhysicsMoverInterface::GetWheelRadius(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rdx
  UFG::PhysicsVehicle *v2; // rax

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( !mPhysicsVehicle )
    return FLOAT_0_27000001;
  v2 = 0i64;
  if ( (*((_BYTE *)mPhysicsVehicle + 604) & 7) != 0 )
    v2 = this->mPhysicsVehicle;
  if ( v2 )
    return v2[1].mTargetTransform.v0.y;
  else
    return FLOAT_0_27000001;
}

// File Line: 2196
// RVA: 0x68C4E0
void __fastcall UFG::PhysicsMoverInterface::StartSlide(UFG::PhysicsMoverInterface *this)
{
  if ( (*((_BYTE *)this + 900) & 2) == 0
    && (unsigned int)UFG::VehicleUtility::GetVehicleOrientation((UFG::SimObjectVehicle *)this->m_pSimObject, 0, 0i64) == 5 )
  {
    *((_BYTE *)this + 900) |= 2u;
  }
}

// File Line: 2209
// RVA: 0x676100
void __fastcall UFG::PhysicsMoverInterface::DamageTire(
        UFG::PhysicsMoverInterface *this,
        UFG::SimObject *pAttackerSimObject,
        int tireIndex,
        float damage)
{
  __int64 v4; // rsi
  float v5; // xmm2_4
  float v8; // xmm6_4
  UFG::SimObject *m_pSimObject; // rax
  UFG::VehicleEffectsComponent *m_pComponent; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLastDamageSource; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax

  v4 = tireIndex;
  v5 = this->mDamageState.tireDamage.array[tireIndex];
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
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_pComponent = (UFG::VehicleEffectsComponent *)m_pSimObject->m_Components.p[32].m_pComponent;
      if ( m_pComponent )
        UFG::VehicleEffectsComponent::BlowTire(m_pComponent, tireIndex);
    }
  }
  this->mDamageState.tireDamage.array[v4] = v8;
  if ( pAttackerSimObject )
  {
    p_mLastDamageSource = &this->mLastDamageSource;
    if ( this->mLastDamageSource.m_pPointer )
    {
      mPrev = p_mLastDamageSource->mPrev;
      mNext = this->mLastDamageSource.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mLastDamageSource->mPrev = p_mLastDamageSource;
      this->mLastDamageSource.mNext = &this->mLastDamageSource;
    }
    this->mLastDamageSource.m_pPointer = pAttackerSimObject;
    v14 = pAttackerSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v14->mNext = p_mLastDamageSource;
    p_mLastDamageSource->mPrev = v14;
    this->mLastDamageSource.mNext = &pAttackerSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pAttackerSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mLastDamageSource;
  }
}

// File Line: 2222
// RVA: 0x68B710
void __fastcall UFG::PhysicsMoverInterface::SetTireDamage(
        UFG::PhysicsMoverInterface *this,
        int tireIndex,
        float totalDamage)
{
  float v3; // xmm6_4
  __int64 v5; // rdi
  UFG::SimObject *m_pSimObject; // rax
  UFG::VehicleEffectsComponent *m_pComponent; // rcx

  v3 = totalDamage;
  if ( totalDamage <= 0.0 )
  {
    v3 = 0.0;
  }
  else if ( totalDamage >= 1.0 )
  {
    v3 = *(float *)&FLOAT_1_0;
  }
  v5 = tireIndex;
  if ( this->mDamageState.tireDamage.array[tireIndex] < 1.0 && v3 >= 1.0 && (m_pSimObject = this->m_pSimObject) != 0i64 )
  {
    m_pComponent = (UFG::VehicleEffectsComponent *)m_pSimObject->m_Components.p[32].m_pComponent;
    if ( m_pComponent )
      UFG::VehicleEffectsComponent::BlowTire(m_pComponent, tireIndex);
    this->mDamageState.tireDamage.array[v5] = v3;
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
  float v3; // xmm7_4
  UFG::allocator::free_link *v4; // rax
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax
  float v6; // xmm6_4
  UFG::GameStatTracker *v7; // rax

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
      UFG::EvtEntityDied::EvtEntityDied((UFG::EvtEntityDied *)v4, "EVT_ENTITY_DEATH", this->m_pSimObject);
    UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
  }
LABEL_9:
  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
  {
    v6 = mPhysicsVehicle->mDollarValue * (float)(v3 - this->mDamageState.engineDamage);
    v7 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v7, PropertyDamaged, v6);
  }
  this->mDamageState.engineDamage = v3;
}

// File Line: 2267
// RVA: 0x6757B0
__int64 __fastcall UFG::PhysicsMoverInterface::DamageEngine(
        UFG::PhysicsMoverInterface *this,
        UFG::SimObjectCVBase *pAttackerSimObject,
        float damage,
        UFG::PhysicsMoverInterface::DamageType dt)
{
  float v4; // xmm7_4
  int v7; // edi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int64 *v10; // rcx
  __int64 **v11; // rax
  __int64 *v12; // rax
  char v13; // r10
  unsigned int size; // r8d
  unsigned int v15; // edx
  UFG::SimObject **p_m_pPointer; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLastDamageSource; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::AttackData *v21; // rdx
  __int64 v22; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pAttacked; // r8
  __int64 v27; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rax
  int v31; // r9d
  int v32; // r9d
  signed __int16 m_Flags; // cx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObject *v35; // rbx
  unsigned __int8 v36; // r8
  UFG::SimObject *v37; // rax
  UFG::SimComponent *v38; // rdx
  UFG::SimObjectCharacter *v39; // rbx
  signed __int16 v40; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v42; // rax
  UFG::SimComponent *v43; // rdx
  UFG::GameStatTracker *v44; // rax
  signed __int16 v45; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v47; // rax
  UFG::SimComponent *v48; // r13
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **p_mNext; // r12
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rbx
  __int64 v51; // rax
  int i; // ecx
  unsigned int j; // r15d
  UFG::SimObjectCharacter *v54; // rcx
  int v55; // edx
  int v56; // r8d
  __int64 v57; // rcx
  __int64 k; // rax
  int v59; // edx
  __int64 m; // rax
  int v61; // edx
  float engineDamage; // xmm6_4
  float v63; // xmm0_4
  UFG::CopSystem *v64; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // r10
  __int64 *v66; // rcx
  __int64 **v67; // rax
  __int64 *v68; // rcx
  __int64 **v69; // rax
  __int64 v70; // rcx
  __int64 *v71; // rax
  __int64 v72; // rdx
  __int64 *v73; // rcx
  __int64 *v75; // [rsp+10h] [rbp-29h] BYREF
  __int64 *p_m_SafePointerList; // [rsp+18h] [rbp-21h]
  UFG::SimObjectCVBase *v77; // [rsp+20h] [rbp-19h]
  __int64 *v78; // [rsp+28h] [rbp-11h] BYREF
  __int64 **v79; // [rsp+30h] [rbp-9h]
  UFG::SimObject *v80; // [rsp+38h] [rbp-1h] BYREF
  float v81; // [rsp+40h] [rbp+7h]
  __int64 **v82; // [rsp+98h] [rbp+5Fh]
  void *retaddr; // [rsp+B8h] [rbp+7Fh]

  v4 = damage;
  v75 = (__int64 *)&v80;
  p_m_SafePointerList = (__int64 *)&v80;
  v7 = 0;
  v82 = &v78;
  v78 = (__int64 *)&v78;
  v79 = &v78;
  v80 = 0i64;
  v81 = 0.0;
  v77 = pAttackerSimObject;
  if ( pAttackerSimObject )
  {
    mPrev = pAttackerSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v75;
    v75 = (__int64 *)mPrev;
    p_m_SafePointerList = (__int64 *)&pAttackerSimObject->m_SafePointerList;
    pAttackerSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v75;
  }
  m_pSimObject = this->m_pSimObject;
  if ( v80 )
  {
    v10 = v78;
    v11 = v79;
    v78[1] = (__int64)v79;
    *v11 = v10;
    v78 = (__int64 *)&v78;
    v79 = &v78;
  }
  v80 = m_pSimObject;
  if ( m_pSimObject )
  {
    v12 = (__int64 *)m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v12[1] = (__int64)&v78;
    v78 = v12;
    v79 = (__int64 **)&m_pSimObject->m_SafePointerList;
    m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v78;
  }
  v13 = 0;
  size = UFG::PhysicsMoverInterface::s_VehicleAttacks.size;
  v15 = 0;
  if ( UFG::PhysicsMoverInterface::s_VehicleAttacks.size )
  {
    p_m_pPointer = &UFG::PhysicsMoverInterface::s_VehicleAttacks.array[0].pAttacked.m_pPointer;
    do
    {
      if ( v77 == *(p_m_pPointer - 3) && v80 == *p_m_pPointer )
      {
        v13 = 1;
        if ( (_BYTE)retaddr )
          goto LABEL_45;
        *((_DWORD *)p_m_pPointer + 2) = 0;
      }
      ++v15;
      p_m_pPointer += 7;
    }
    while ( v15 < size );
    size = UFG::PhysicsMoverInterface::s_VehicleAttacks.size;
  }
  if ( pAttackerSimObject )
  {
    p_mLastDamageSource = &this->mLastDamageSource;
    if ( this->mLastDamageSource.m_pPointer )
    {
      v18 = p_mLastDamageSource->mPrev;
      mNext = this->mLastDamageSource.mNext;
      v18->mNext = mNext;
      mNext->mPrev = v18;
      p_mLastDamageSource->mPrev = p_mLastDamageSource;
      this->mLastDamageSource.mNext = &this->mLastDamageSource;
    }
    this->mLastDamageSource.m_pPointer = pAttackerSimObject;
    v20 = pAttackerSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v20->mNext = p_mLastDamageSource;
    p_mLastDamageSource->mPrev = v20;
    this->mLastDamageSource.mNext = &pAttackerSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pAttackerSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mLastDamageSource;
    size = UFG::PhysicsMoverInterface::s_VehicleAttacks.size;
  }
  if ( !v13 )
  {
    v21 = &UFG::PhysicsMoverInterface::s_VehicleAttacks.array[size];
    UFG::PhysicsMoverInterface::s_VehicleAttacks.size = size + 1;
    v22 = (__int64)v77;
    if ( v21->pAttacker.m_pPointer )
    {
      v23 = v21->pAttacker.mPrev;
      v24 = v21->pAttacker.mNext;
      v23->mNext = v24;
      v24->mPrev = v23;
      v21->pAttacker.mPrev = &v21->pAttacker;
      v21->pAttacker.mNext = &v21->pAttacker;
    }
    v21->pAttacker.m_pPointer = (UFG::SimObject *)v22;
    if ( v22 )
    {
      v25 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v22 + 8);
      v25->mNext = &v21->pAttacker;
      v21->pAttacker.mPrev = v25;
      v21->pAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v22 + 8);
      *(_QWORD *)(v22 + 8) = v21;
    }
    p_pAttacked = &v21->pAttacked;
    v27 = (__int64)v80;
    if ( v21->pAttacked.m_pPointer )
    {
      v28 = p_pAttacked->mPrev;
      v29 = v21->pAttacked.mNext;
      v28->mNext = v29;
      v29->mPrev = v28;
      p_pAttacked->mPrev = p_pAttacked;
      v21->pAttacked.mNext = &v21->pAttacked;
    }
    v21->pAttacked.m_pPointer = (UFG::SimObject *)v27;
    if ( v27 )
    {
      v30 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v27 + 8);
      v30->mNext = p_pAttacked;
      p_pAttacked->mPrev = v30;
      v21->pAttacked.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v27 + 8);
      *(_QWORD *)(v27 + 8) = p_pAttacked;
    }
    v21->fElapsedTime = v81;
  }
  if ( dt == dtWORLD_COLLISION )
  {
    v4 = damage * this->mDamageMultiplierWorldCollisions;
    goto LABEL_81;
  }
  v31 = dt - 1;
  if ( v31 )
  {
    v32 = v31 - 1;
    if ( v32 )
    {
      if ( v32 == 1 )
        v4 = damage * this->mDamageMultiplierAttack;
    }
    else
    {
      if ( !pAttackerSimObject )
        goto LABEL_50;
      m_Flags = pAttackerSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::CharacterOccupantComponent *)pAttackerSimObject->m_Components.p[44].m_pComponent;
      }
      else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            pAttackerSimObject,
                                                            UFG::CharacterOccupantComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                            pAttackerSimObject,
                                                            UFG::CharacterOccupantComponent::_TypeUID);
      }
      if ( m_pComponent )
      {
        v35 = this->m_pSimObject;
        if ( UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent) == (UFG::VehicleOccupantComponent *)v35 )
        {
LABEL_45:
          v36 = 0;
          goto LABEL_121;
        }
      }
      v37 = this->m_pSimObject;
      if ( v37
        && (v38 = v37->m_Components.p[30].m_pComponent) != 0i64
        && UFG::AreCharactersAllied(pAttackerSimObject, (UFG::SimObjectCVBase *)v38[1].m_pSimObject) )
      {
        v4 = 0.0;
      }
      else
      {
LABEL_50:
        v4 = damage * this->mDamageMultiplierBullets;
      }
    }
    goto LABEL_81;
  }
  v39 = (UFG::SimObjectCharacter *)pAttackerSimObject;
  if ( pAttackerSimObject )
  {
    v40 = pAttackerSimObject->m_Flags;
    if ( (v40 & 0x4000) != 0 )
      goto LABEL_58;
    if ( v40 < 0 )
    {
      ComponentOfTypeHK = pAttackerSimObject->m_Components.p[30].m_pComponent;
      goto LABEL_60;
    }
    if ( (v40 & 0x2000) != 0 || (v40 & 0x1000) != 0 )
LABEL_58:
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            pAttackerSimObject,
                            UFG::VehicleOccupantComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                            pAttackerSimObject,
                            UFG::VehicleOccupantComponent::_TypeUID);
LABEL_60:
    if ( ComponentOfTypeHK )
      v39 = (UFG::SimObjectCharacter *)ComponentOfTypeHK[1].m_pSimObject;
  }
  v42 = this->m_pSimObject;
  if ( v42
    && (v43 = v42->m_Components.p[30].m_pComponent) != 0i64
    && UFG::AreCharactersAllied(v39, (UFG::SimObjectCVBase *)v43[1].m_pSimObject) )
  {
    v4 = 0.0;
  }
  else
  {
    v4 = damage * this->mDamageMultiplierVehicleCollisions;
    if ( v39 )
    {
      if ( v39 == LocalPlayer )
      {
        v44 = UFG::GameStatTracker::Instance();
        if ( UFG::GameStatTracker::GetStat(v44, VehicleRamUpgrade) )
        {
          if ( pAttackerSimObject )
          {
            v45 = pAttackerSimObject->m_Flags;
            if ( (v45 & 0x4000) == 0 )
            {
              if ( v45 >= 0 )
              {
                if ( (v45 & 0x2000) != 0 )
                  goto LABEL_81;
                if ( (v45 & 0x1000) != 0 )
                  ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      pAttackerSimObject,
                                      UFG::PhysicsMoverInterface::_TypeUID);
                else
                  ComponentOfType = UFG::SimObject::GetComponentOfType(
                                      pAttackerSimObject,
                                      UFG::PhysicsMoverInterface::_TypeUID);
              }
              else
              {
                ComponentOfType = pAttackerSimObject->m_Components.p[34].m_pComponent;
              }
              if ( ComponentOfType && (BYTE4(ComponentOfType[14].vfptr) & 8) != 0 )
                v4 = v4 * *(float *)&ComponentOfType[13].m_TypeUID;
            }
          }
        }
      }
    }
  }
LABEL_81:
  v47 = this->m_pSimObject;
  if ( v47 )
  {
    v48 = v47->m_Components.p[30].m_pComponent;
    if ( v48 )
    {
      p_mNext = &v48[1].m_BoundComponentHandles.mNode.mNext;
      p_m_BoundComponentHandles = &v48->m_BoundComponentHandles;
      v51 = (__int64)&v48[1].m_BoundComponentHandles.mNode.mNext[-4];
      if ( v48[1].m_pSimObject )
      {
        for ( i = 0;
              (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v51 != p_m_BoundComponentHandles;
              v51 = *(_QWORD *)(v51 + 72) - 64i64 )
        {
          ++i;
        }
        j = i + 1;
      }
      else
      {
        for ( j = 0;
              (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v51 != p_m_BoundComponentHandles;
              v51 = *(_QWORD *)(v51 + 72) - 64i64 )
        {
          ++j;
        }
      }
      if ( j )
      {
        do
        {
          v54 = (UFG::SimObjectCharacter *)v48[1].m_pSimObject;
          if ( v54 )
          {
            if ( !v7 )
              goto LABEL_107;
            v55 = v7 - 1;
            v56 = 0;
            v57 = (__int64)&(*p_mNext)[-4];
            for ( k = v57;
                  (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)k != p_m_BoundComponentHandles;
                  k = *(_QWORD *)(k + 72) - 64i64 )
            {
              ++v56;
            }
            if ( v55 < v56 )
            {
              for ( ; v55 > 0; v57 = *(_QWORD *)(v57 + 72) - 64i64 )
              {
                if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v57 == p_m_BoundComponentHandles )
                  break;
                --v55;
              }
LABEL_98:
              v54 = *(UFG::SimObjectCharacter **)(v57 + 40);
              goto LABEL_107;
            }
          }
          else
          {
            v59 = 0;
            v57 = (__int64)&(*p_mNext)[-4];
            for ( m = v57;
                  (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)m != p_m_BoundComponentHandles;
                  m = *(_QWORD *)(m + 72) - 64i64 )
            {
              ++v59;
            }
            if ( v7 < v59 )
            {
              v61 = v7;
              if ( v7 > 0 )
              {
                while ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v57 != p_m_BoundComponentHandles )
                {
                  --v61;
                  v57 = *(_QWORD *)(v57 + 72) - 64i64;
                  if ( v61 <= 0 )
                  {
                    v54 = *(UFG::SimObjectCharacter **)(v57 + 40);
                    goto LABEL_107;
                  }
                }
              }
              goto LABEL_98;
            }
          }
          v54 = 0i64;
LABEL_107:
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
  engineDamage = this->mDamageState.engineDamage;
  UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(this, engineDamage + v4);
  v63 = this->mDamageState.engineDamage;
  if ( v63 < UFG::PhysicsMoverInterface::mIgnoreRipenessTakedownThreshold )
  {
    if ( engineDamage < UFG::PhysicsMoverInterface::mRipeForTakedownThreshold
      || v63 < UFG::PhysicsMoverInterface::mRipeForTakedownThreshold )
    {
      *((_BYTE *)this + 900) &= ~4u;
    }
    else
    {
      *((_BYTE *)this + 900) |= 4u;
    }
  }
  else
  {
    *((_BYTE *)this + 900) |= 4u;
  }
  if ( engineDamage != 1.0 && v63 == 1.0 )
    _((AMD_HD3D *)&UFG::PoliceScannerAudio::sm_Instance);
  v64 = UFG::CopSystem::Instance();
  vfptr = v64->vfptr;
  LOBYTE(v78) = 1;
  v77 = 0i64;
  ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObjectCVBase *, UFG::SimObject *, _QWORD))vfptr[95].__vecDelDtor)(
    v64,
    pAttackerSimObject,
    this->m_pSimObject,
    0i64);
  v36 = 1;
LABEL_121:
  v82 = &v78;
  if ( v80 )
  {
    v66 = v78;
    v67 = v79;
    v78[1] = (__int64)v79;
    *v67 = v66;
    v78 = (__int64 *)&v78;
    v79 = &v78;
  }
  v80 = 0i64;
  v68 = v78;
  v69 = v79;
  v78[1] = (__int64)v79;
  *v69 = v68;
  v78 = (__int64 *)&v78;
  v79 = &v78;
  v82 = &v75;
  if ( v77 )
  {
    v70 = (__int64)v75;
    v71 = p_m_SafePointerList;
    v75[1] = (__int64)p_m_SafePointerList;
    *v71 = v70;
    v75 = (__int64 *)&v75;
    p_m_SafePointerList = (__int64 *)&v75;
  }
  v72 = (__int64)v75;
  v73 = p_m_SafePointerList;
  v75[1] = (__int64)p_m_SafePointerList;
  *v73 = v72;
  return v36;
}

// File Line: 2552
// RVA: 0x6741F0
bool __fastcall UFG::PhysicsMoverInterface::CanApplySpeedBoostRewardFromVehicleTakedown(
        UFG::PhysicsMoverInterface *this)
{
  return this->mSecondsSinceAppliedSpeedBoostRewardFromVehicleTakedown > 5.0;
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
  return this->mDamageState.tireDamage.array[tireIndex] >= 1.0;
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
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
    *((_DWORD *)mPhysicsVehicle + 151) |= 8u;
}

// File Line: 2611
// RVA: 0x685E40
void __fastcall UFG::PhysicsMoverInterface::OverrideSuperStopDrag(
        UFG::PhysicsMoverInterface *this,
        bool bOverride,
        float fDrag)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
  {
    if ( bOverride )
      mPhysicsVehicle->mSuperStopDrag = fDrag;
    else
      UFG::PhysicsVehicle::RestoreSuperStopDrag(mPhysicsVehicle);
  }
}

// File Line: 2628
// RVA: 0x6795A0
void __fastcall UFG::PhysicsMoverInterface::FlipVehicle(
        UFG::PhysicsMoverInterface *this,
        float torqueFactor,
        UFG::qVector3 *collisionPoint)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
    UFG::PhysicsVehicle::FlipVehicle(mPhysicsVehicle, torqueFactor, collisionPoint);
}

// File Line: 2638
// RVA: 0x67A6C0
float __fastcall UFG::PhysicsMoverInterface::GetHalfSteeringRange(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx
  float result; // xmm0_4

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( !mPhysicsVehicle )
    return FLOAT_0_78539819;
  ((void (__fastcall *)(UFG::PhysicsVehicle *))mPhysicsVehicle->vfptr[5].__vecDelDtor)(mPhysicsVehicle);
  return result;
}

// File Line: 2645
// RVA: 0x670FE0
void __fastcall UFG::PhysicsMoverInterface::AutoDeteriorateEngineIfNotAlready(UFG::PhysicsMoverInterface *this)
{
  UFG::SimObject *m_pSimObject; // rcx

  if ( this->mSecondsEngineHasBeenDeteriorating < 0.0 )
  {
    UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(this, this->mAutoDeterioratingDamageThreshold);
    m_pSimObject = this->m_pSimObject;
    this->mSecondsEngineHasBeenDeteriorating = 0.0;
    UFG::PhysicsMoverInterface_EmitVehicleDisabledEvent(m_pSimObject);
  }
}

// File Line: 2658
// RVA: 0x68D360
void __fastcall UFG::PhysicsMoverInterface::TriggerExplosion(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx
  UFG::PhysicsVehicle *v3; // rax
  int i; // ebx
  UFG::PhysicsVehicle *v5; // rcx
  UFG::WaterFloatingTrackerComponent *mWaterFloatingTrackerComponent; // rcx
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *v8; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::ExplosionTypeInfo *ExplosionTypeInfo; // r12
  UFG::SimObject *v12; // rcx
  UFG::SimComponentHolder *p; // rcx
  UFG::SimComponent *m_pComponent; // r14
  int NumberOfOccupants; // r15d
  int v16; // edi
  UFG::SimObjectGame *v17; // rcx
  int v18; // edx
  int v19; // r9d
  __int64 v20; // rcx
  __int64 v21; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *j; // r8
  int v23; // edx
  __int64 v24; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *k; // r8
  int m; // edx
  __int16 m_Flags; // dx
  UFG::HitReactionComponent *v28; // rbx
  UFG::SimComponent *v29; // rax
  UFG::SimObject *v30; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::SimObject *v34; // rax
  UFG::VehicleEffectsComponent *v35; // rcx
  UFG::qVector3 pos; // [rsp+30h] [rbp-A8h] BYREF
  __int64 v37; // [rsp+40h] [rbp-98h]
  UFG::HitRecord hitrecord; // [rsp+50h] [rbp-88h] BYREF

  v37 = -2i64;
  *((_BYTE *)this + 900) &= ~0x10u;
  if ( this->mDestructState != POST_DESTRUCT )
  {
    UFG::PhysicsMoverInterface_EmitVehicleDisabledEvent(this->m_pSimObject);
    UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(this, 1.0);
    mPhysicsVehicle = this->mPhysicsVehicle;
    if ( mPhysicsVehicle )
    {
      v3 = 0i64;
      if ( (*((_BYTE *)mPhysicsVehicle + 604) & 7) != 0 )
        v3 = this->mPhysicsVehicle;
      if ( v3 )
      {
        for ( i = 0; i < this->mNumWheels; ++i )
          UFG::PhysicsMoverInterface::SetTireDamage(this, i, 1.0);
      }
    }
    v5 = this->mPhysicsVehicle;
    if ( v5 && (*((_DWORD *)v5 + 151) & 7) == 2 )
      BYTE1(v5[2].mUserData.simComponent.mPrev) = 1;
    if ( (*((_BYTE *)this + 896) & 0x10) == 0 )
    {
      mWaterFloatingTrackerComponent = this->mPhysicsVehicle->mWaterFloatingTrackerComponent;
      if ( !mWaterFloatingTrackerComponent
        || !UFG::WaterFloatingTrackerComponent::IsSubmerged(mWaterFloatingTrackerComponent, 0.64999998) )
      {
        if ( this->mPropertySetExplosion.mUID != -1 )
        {
          UFG::PhysicsMoverInterface::LockHighLod(this, ELODLockMode_UNTIL_AT_REST, 0.0);
          m_pSimObject = this->m_pSimObject;
          v8 = m_pSimObject ? (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent : 0i64;
          UFG::TransformNodeComponent::UpdateWorldTransform(v8);
          y = v8->mWorldTransform.v3.y;
          z = v8->mWorldTransform.v3.z;
          pos.x = v8->mWorldTransform.v3.x;
          pos.y = y;
          pos.z = z + 0.5;
          UFG::ExplosionManager::CreateExplosion(
            &pos,
            &this->mPropertySetExplosion,
            this->m_pSimObject,
            this->mLastDamageSource.m_pPointer);
          ExplosionTypeInfo = UFG::ExplosionManager::GetExplosionTypeInfo(&this->mPropertySetExplosion);
          UFG::GameStatAction::Vehicle::Explosion((UFG::SimObjectCVBase *)this->m_pSimObject);
          v12 = this->m_pSimObject;
          if ( v12 )
          {
            p = v12->m_Components.p;
            m_pComponent = p[30].m_pComponent;
            if ( m_pComponent )
            {
              NumberOfOccupants = UFG::VehicleOccupantComponent::GetNumberOfOccupants((UFG::VehicleOccupantComponent *)p[30].m_pComponent);
              v16 = 0;
              if ( NumberOfOccupants > 0 )
              {
                while ( 1 )
                {
                  v17 = (UFG::SimObjectGame *)m_pComponent[1].m_pSimObject;
                  if ( !v17 )
                    break;
                  if ( v16 )
                  {
                    v18 = v16 - 1;
                    v19 = 0;
                    v20 = (__int64)&m_pComponent[1].m_BoundComponentHandles.mNode.mNext[-4];
                    v21 = v20;
                    for ( j = &m_pComponent->m_BoundComponentHandles;
                          (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v21 != j;
                          v21 = *(_QWORD *)(v21 + 72) - 64i64 )
                    {
                      ++v19;
                    }
                    if ( v18 >= v19 )
                      goto LABEL_53;
                    for ( ; v18 > 0; v20 = *(_QWORD *)(v20 + 72) - 64i64 )
                    {
                      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v20 == j )
                        break;
                      --v18;
                    }
                    goto LABEL_36;
                  }
LABEL_37:
                  if ( v17 )
                  {
                    m_Flags = v17->m_Flags;
                    if ( (m_Flags & 0x4000) != 0 )
                    {
                      v28 = (UFG::HitReactionComponent *)v17->m_Components.p[15].m_pComponent;
                    }
                    else if ( m_Flags >= 0 )
                    {
                      v29 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                          ? UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::HitReactionComponent::_TypeUID)
                          : UFG::SimObject::GetComponentOfType(v17, UFG::HitReactionComponent::_TypeUID);
                      v28 = (UFG::HitReactionComponent *)v29;
                    }
                    else
                    {
                      v28 = (UFG::HitReactionComponent *)v17->m_Components.p[15].m_pComponent;
                    }
                    if ( v28 )
                    {
                      UFG::HitRecord::HitRecord(&hitrecord);
                      v30 = this->m_pSimObject;
                      hitrecord.mAttackTypeID = gAttackCollisionExplosion.m_EnumValue;
                      hitrecord.mDamage = 100;
                      if ( hitrecord.mAttacker.m_pPointer )
                      {
                        mPrev = hitrecord.mAttacker.mPrev;
                        mNext = hitrecord.mAttacker.mNext;
                        hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
                        mNext->mPrev = mPrev;
                        hitrecord.mAttacker.mPrev = &hitrecord.mAttacker;
                        hitrecord.mAttacker.mNext = &hitrecord.mAttacker;
                      }
                      hitrecord.mAttacker.m_pPointer = v30;
                      if ( v30 )
                      {
                        v33 = v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                        v33->mNext = &hitrecord.mAttacker;
                        hitrecord.mAttacker.mPrev = v33;
                        hitrecord.mAttacker.mNext = &v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
                        v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &hitrecord.mAttacker;
                      }
                      *(_QWORD *)&hitrecord.mTimeSinceHit = 0i64;
                      hitrecord.mCollisionInfo.mOtherVelocity.x = 0.0;
                      *(_QWORD *)&hitrecord.mCollisionInfo.mOtherVelocity.z = ExplosionTypeInfo;
                      memset(&hitrecord.mProjectileInfo, 0, 32);
                      *(float *)&hitrecord.mProjectileInfo.m_bIsFullyAccurate = UFG::qVector3::msZero.x;
                      *(float *)(&hitrecord.mProjectileInfo.m_bIsHardLocked + 3) = UFG::qVector3::msZero.y;
                      hitrecord.mCollisionInfo.mPhysicsObjectPropertyHandleUID = __PAIR64__(
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
LABEL_53:
                  if ( ++v16 >= NumberOfOccupants )
                    goto LABEL_54;
                }
                v23 = 0;
                v20 = (__int64)&m_pComponent[1].m_BoundComponentHandles.mNode.mNext[-4];
                v24 = v20;
                for ( k = &m_pComponent->m_BoundComponentHandles;
                      (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v24 != k;
                      v24 = *(_QWORD *)(v24 + 72) - 64i64 )
                {
                  ++v23;
                }
                if ( v16 >= v23 )
                  goto LABEL_53;
                for ( m = v16; m > 0; v20 = *(_QWORD *)(v20 + 72) - 64i64 )
                {
                  if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v20 == k )
                    break;
                  --m;
                }
LABEL_36:
                v17 = *(UFG::SimObjectGame **)(v20 + 40);
                goto LABEL_37;
              }
            }
          }
        }
LABEL_54:
        v34 = this->m_pSimObject;
        if ( v34 )
        {
          v35 = (UFG::VehicleEffectsComponent *)v34->m_Components.p[32].m_pComponent;
          if ( v35 )
            UFG::VehicleEffectsComponent::TurnOnDestroyedEffect(v35);
        }
      }
    }
    this->mDestructState = POST_DESTRUCT;
  }
}

// File Line: 2741
// RVA: 0x68A470
void __fastcall UFG::PhysicsMoverInterface::SetCannotExplode(UFG::PhysicsMoverInterface *this, bool cannotExplode)
{
  *((_DWORD *)this + 0xE0) &= ~0x10u;
  *((_DWORD *)this + 0xE0) |= 16 * cannotExplode;
}

// File Line: 2768
// RVA: 0x67A780
float __fastcall UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax
  hkpRigidBody *mBody; // rdx
  __m128 v3; // xmm2

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( !mPhysicsVehicle )
    return this->mForwardSpeed * 3.5999999;
  mBody = mPhysicsVehicle->mRigidBody->mBody;
  if ( !mBody )
    return this->mForwardSpeed * 3.5999999;
  v3 = (__m128)mBody->m_motion.m_linearVelocity.m_quad.m128_u32[0];
  v3.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0])
                         + (float)(mBody->m_motion.m_linearVelocity.m_quad.m128_f32[1]
                                 * mBody->m_motion.m_linearVelocity.m_quad.m128_f32[1]))
                 + (float)(mBody->m_motion.m_linearVelocity.m_quad.m128_f32[2]
                         * mBody->m_motion.m_linearVelocity.m_quad.m128_f32[2]);
  return _mm_sqrt_ps(v3).m128_f32[0] * 3.5999999;
}

// File Line: 2775
// RVA: 0x67A720
float __fastcall UFG::PhysicsMoverInterface::GetLinearVelocityMagnitude(UFG::PhysicsMoverInterface *this)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax
  hkpRigidBody *mBody; // rdx
  __m128 v3; // xmm2
  float result; // xmm0_4

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( !mPhysicsVehicle )
    return this->mForwardSpeed;
  mBody = mPhysicsVehicle->mRigidBody->mBody;
  if ( !mBody )
    return this->mForwardSpeed;
  v3 = (__m128)mBody->m_motion.m_linearVelocity.m_quad.m128_u32[0];
  v3.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0])
                         + (float)(mBody->m_motion.m_linearVelocity.m_quad.m128_f32[1]
                                 * mBody->m_motion.m_linearVelocity.m_quad.m128_f32[1]))
                 + (float)(mBody->m_motion.m_linearVelocity.m_quad.m128_f32[2]
                         * mBody->m_motion.m_linearVelocity.m_quad.m128_f32[2]);
  LODWORD(result) = _mm_sqrt_ps(v3).m128_u32[0];
  return result;
}

// File Line: 2788
// RVA: 0x681EF0
void __fastcall UFG::PhysicsMoverInterface::NotifyProxyModeChanged(
        UFG::PhysicsMoverInterface *this,
        UFG::SimObject::eProxyMode proxyMode)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // r8

  mPhysicsVehicle = this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
    mPhysicsVehicle->mIsProxy = proxyMode == ePM_PROXY_REMOTE_PHYSICS;
}

// File Line: 2797
// RVA: 0x694FB0
void __fastcall UFG::PhysicsMoverInterface::UpdateAttacks(float delta_sec)
{
  unsigned int v2; // ebx
  __int64 v3; // rcx
  float v4; // xmm0_4
  UFG::AttackData *v5; // rdx
  __int64 v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pAttacked; // r8
  __int64 v11; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  unsigned int size; // eax
  __int64 *v16; // rcx
  __int64 **v17; // rax
  __int64 *v18; // rcx
  __int64 **v19; // rax
  __int64 *v20; // rcx
  __int64 **v21; // rax
  __int64 *v22; // rcx
  __int64 **v23; // rax
  __int64 *v24; // [rsp+28h] [rbp-58h] BYREF
  __int64 **v25; // [rsp+30h] [rbp-50h]
  __int64 v26; // [rsp+38h] [rbp-48h]
  __int64 *v27; // [rsp+40h] [rbp-40h] BYREF
  __int64 **v28; // [rsp+48h] [rbp-38h]
  __int64 v29; // [rsp+50h] [rbp-30h]
  float v30; // [rsp+58h] [rbp-28h]

  v24 = (__int64 *)&v24;
  v25 = &v24;
  v26 = 0i64;
  v27 = (__int64 *)&v27;
  v28 = &v27;
  v29 = 0i64;
  v30 = 0.0;
  v2 = 0;
  if ( UFG::PhysicsMoverInterface::s_VehicleAttacks.size )
  {
    do
    {
      v3 = v2;
      v4 = delta_sec + UFG::PhysicsMoverInterface::s_VehicleAttacks.array[v3].fElapsedTime;
      UFG::PhysicsMoverInterface::s_VehicleAttacks.array[v3].fElapsedTime = v4;
      if ( v4 <= 0.75 )
      {
        ++v2;
        size = UFG::PhysicsMoverInterface::s_VehicleAttacks.size;
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
          mPrev = v5->pAttacker.mPrev;
          mNext = v5->pAttacker.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          v5->pAttacker.mPrev = &v5->pAttacker;
          v5->pAttacker.mNext = &v5->pAttacker;
        }
        v5->pAttacker.m_pPointer = (UFG::SimObject *)v6;
        if ( v6 )
        {
          v9 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v6 + 8);
          v9->mNext = &v5->pAttacker;
          v5->pAttacker.mPrev = v9;
          v5->pAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v6 + 8);
          *(_QWORD *)(v6 + 8) = v5;
        }
        p_pAttacked = &v5->pAttacked;
        v11 = v29;
        if ( v5->pAttacked.m_pPointer )
        {
          v12 = p_pAttacked->mPrev;
          v13 = v5->pAttacked.mNext;
          v12->mNext = v13;
          v13->mPrev = v12;
          p_pAttacked->mPrev = p_pAttacked;
          v5->pAttacked.mNext = &v5->pAttacked;
        }
        v5->pAttacked.m_pPointer = (UFG::SimObject *)v11;
        if ( v11 )
        {
          v14 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v11 + 8);
          v14->mNext = p_pAttacked;
          p_pAttacked->mPrev = v14;
          v5->pAttacked.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v11 + 8);
          *(_QWORD *)(v11 + 8) = p_pAttacked;
        }
        v5->fElapsedTime = v30;
        size = --UFG::PhysicsMoverInterface::s_VehicleAttacks.size;
      }
    }
    while ( v2 < size );
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
  UFG::PhysicsMoverInterface *p_mNext; // rcx
  UFG::PhysicsMoverInterface *v1; // rbx

  p_mNext = (UFG::PhysicsMoverInterface *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( &UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> **)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72) )
  {
    do
    {
      v1 = (UFG::PhysicsMoverInterface *)&p_mNext->mNext[-5].mNext;
      if ( (*((_BYTE *)p_mNext + 900) & 0x10) != 0 )
        UFG::PhysicsMoverInterface::TriggerExplosion(p_mNext);
      p_mNext = v1;
    }
    while ( v1 != (UFG::PhysicsMoverInterface *)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72) );
  }
}

// File Line: 2845
// RVA: 0x67E8B0
void __fastcall UFG::PhysicsMoverInterface::InitiateRamming(UFG::PhysicsMoverInterface *this, UFG::RammingState *rs)
{
  UFG::RammingState *mRammingState; // rcx
  UFG::allocator::free_link *v5; // rax
  UFG::RammingState *v6; // rax

  mRammingState = this->mRammingState;
  if ( mRammingState )
  {
    mRammingState->mState = ERS_Boosting;
    this->mRammingState->mForwardSpeedPenaltyPercent = this->mRammingState->mForwardSpeedPenaltyPercent * 0.30000001;
    v6 = this->mRammingState;
    v6->mVelocityToAdd.x = v6->mVelocityToAdd.x * 0.89999998;
    v6->mVelocityToAdd.y = v6->mVelocityToAdd.y * 0.89999998;
    v6->mVelocityToAdd.z = v6->mVelocityToAdd.z * 0.89999998;
  }
  else
  {
    v5 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
    if ( v5 )
      UFG::RammingState::RammingState((UFG::RammingState *)v5, rs);
    this->mRammingState = (UFG::RammingState *)v5;
  }
}

// File Line: 2869
// RVA: 0x66A330
void __fastcall UFG::RammingState::RammingState(UFG::RammingState *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  this->mTarget.mPrev = &this->mTarget;
  this->mTarget.mNext = &this->mTarget;
  this->mTarget.m_pPointer = 0i64;
  this->mState = ERS_Boosting;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mCounterSpin.x = UFG::qVector3::msZero.x;
  this->mCounterSpin.y = y;
  this->mCounterSpin.z = z;
  this->mOriginalForwardSpeedKPH = 0.0;
}

// File Line: 2875
// RVA: 0x66A1F0
void __fastcall UFG::RammingState::RammingState(UFG::RammingState *this, UFG::RammingState *rs)
{
  UFG::SimObject *m_pPointer; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4

  this->mTarget.mPrev = &this->mTarget;
  this->mTarget.mNext = &this->mTarget;
  this->mTarget.m_pPointer = 0i64;
  m_pPointer = rs->mTarget.m_pPointer;
  if ( this->mTarget.m_pPointer )
  {
    mPrev = this->mTarget.mPrev;
    mNext = this->mTarget.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mTarget.mPrev = &this->mTarget;
    this->mTarget.mNext = &this->mTarget;
  }
  this->mTarget.m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v6 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v6->mNext = &this->mTarget;
    this->mTarget.mPrev = v6;
    this->mTarget.mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &this->mTarget;
  }
  this->mState = rs->mState;
  y = rs->mCounterSpin.y;
  z = rs->mCounterSpin.z;
  this->mCounterSpin.x = rs->mCounterSpin.x;
  this->mCounterSpin.y = y;
  this->mCounterSpin.z = z;
  v9 = rs->mVelocityToAdd.y;
  v10 = rs->mVelocityToAdd.z;
  this->mVelocityToAdd.x = rs->mVelocityToAdd.x;
  this->mVelocityToAdd.y = v9;
  this->mVelocityToAdd.z = v10;
  v11 = rs->mMotionIntentionDirection.y;
  v12 = rs->mMotionIntentionDirection.z;
  this->mMotionIntentionDirection.x = rs->mMotionIntentionDirection.x;
  this->mMotionIntentionDirection.y = v11;
  this->mMotionIntentionDirection.z = v12;
  this->mForwardsness = rs->mForwardsness;
  this->mOriginalForwardSpeedKPH = rs->mOriginalForwardSpeedKPH;
  this->mMinForwardSpeedKPH = rs->mMinForwardSpeedKPH;
  this->mMaxForwardSpeedKPH = rs->mMaxForwardSpeedKPH;
  this->mMinAddSpeedKPH = rs->mMinAddSpeedKPH;
  this->mMaxAddSpeedKPH = rs->mMaxAddSpeedKPH;
  this->mForwardSpeedPenaltyPercent = rs->mForwardSpeedPenaltyPercent;
  this->mForwardSpeedPenaltyDecelKPHPS = rs->mForwardSpeedPenaltyDecelKPHPS;
  this->mNoTargetModifier = rs->mNoTargetModifier;
  this->mCounterSwerveModifier = rs->mCounterSwerveModifier;
  this->mSwerveImpulse = rs->mSwerveImpulse;
  this->mTargetMaxDistance = rs->mTargetMaxDistance;
  this->mTargetForwardsVelocityModifier = rs->mTargetForwardsVelocityModifier;
  this->mTargetAngle = rs->mTargetAngle;
}

// File Line: 2909
// RVA: 0x6934E0
char __fastcall UFG::RammingState::Update(UFG::RammingState *this, UFG::PhysicsMoverInterface *pmi, float timestep)
{
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax
  UFG::SimComponent *m_pComponent; // rbp
  hkpEntity *mBody; // rdi
  UFG::RammingState::ERamState mState; // ecx
  __int32 v9; // ecx
  __int32 v10; // ecx
  float mForwardSpeed; // xmm3_4
  __m128 v13; // xmm0
  __m128 mForwardSpeed_low; // xmm1
  __m128 m_quad; // xmm5
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm6
  UFG::SimObject *m_pSimObject; // rax
  float v25; // xmm1_4
  __m128 vfptr_high; // xmm7
  __m128 mPrev_low; // xmm5
  __m128 vfptr_low; // xmm6
  float mNoTargetModifier; // xmm0_4
  float mCounterSwerveModifier; // xmm1_4
  float v31; // xmm0_4
  float y; // xmm0_4
  float z; // xmm1_4
  __m128 v34; // [rsp+20h] [rbp-48h] BYREF
  __m128 v35; // [rsp+30h] [rbp-38h] BYREF

  mPhysicsVehicle = pmi->mPhysicsVehicle;
  m_pComponent = 0i64;
  if ( mPhysicsVehicle )
    mBody = mPhysicsVehicle->mRigidBody->mBody;
  else
    mBody = 0i64;
  mState = this->mState;
  if ( mState )
  {
    v9 = mState - 1;
    if ( v9 )
    {
      v10 = v9 - 1;
      if ( v10 )
      {
        if ( v10 == 1 )
        {
          *((_BYTE *)pmi + 900) &= ~8u;
          return 1;
        }
      }
      else
      {
        v13 = (__m128)(unsigned int)FLOAT_1_0;
        mForwardSpeed = pmi->mForwardSpeed;
        v13.m128_f32[0] = (float)((float)(1.0 - this->mForwardSpeedPenaltyPercent) * this->mOriginalForwardSpeedKPH)
                        * 0.27777779;
        if ( mForwardSpeed > v13.m128_f32[0] )
        {
          mForwardSpeed_low = (__m128)LODWORD(pmi->mForwardSpeed);
          mForwardSpeed_low.m128_f32[0] = mForwardSpeed - (float)(timestep * this->mForwardSpeedPenaltyDecelKPHPS);
          if ( mForwardSpeed_low.m128_f32[0] < v13.m128_f32[0] )
            mForwardSpeed_low = v13;
          mForwardSpeed_low.m128_f32[0] = mForwardSpeed_low.m128_f32[0] - mForwardSpeed;
          v34 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(mForwardSpeed_low, mForwardSpeed_low, 0),
                    mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
                  mBody->m_motion.m_linearVelocity.m_quad);
          hkpEntity::activate(mBody);
          mBody->m_motion.vfptr[9].__vecDelDtor(&mBody->m_motion, (unsigned int)&v34);
        }
        else
        {
          this->mState = ERamState_DoneDecelWaitingToEnd;
        }
      }
    }
    else
    {
      m_quad = mBody->m_motion.m_angularVelocity.m_quad;
      v16 = _mm_unpacklo_ps(
              _mm_unpacklo_ps((__m128)LODWORD(this->mCounterSpin.x), (__m128)LODWORD(this->mCounterSpin.z)),
              _mm_unpacklo_ps((__m128)LODWORD(this->mCounterSpin.y), (__m128)0i64));
      v17 = _mm_mul_ps(v16, v16);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v19 = _mm_rsqrt_ps(v18);
      v20 = _mm_andnot_ps(
              _mm_cmple_ps(v18, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                _mm_mul_ps(*(__m128 *)_xmm, v19)));
      v21 = _mm_mul_ps(v16, v20);
      v22 = _mm_mul_ps(v21, m_quad);
      v23 = _mm_sub_ps(
              _mm_mul_ps(v20, v18),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                _mm_shuffle_ps(v22, v22, 170)));
      if ( v23.m128_f32[0] > 0.0 )
      {
        v34 = _mm_add_ps(m_quad, _mm_mul_ps(v21, v23));
        hkpEntity::activate(mBody);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))mBody->m_motion.vfptr[9].__first_virtual_table_function__)(
          &mBody->m_motion,
          &v34);
      }
      this->mState = ERamState_DeceleratingToGoalSpeed;
    }
  }
  else
  {
    v34 = _mm_add_ps(
            _mm_unpacklo_ps(
              _mm_unpacklo_ps((__m128)LODWORD(this->mVelocityToAdd.x), (__m128)LODWORD(this->mVelocityToAdd.z)),
              _mm_unpacklo_ps((__m128)LODWORD(this->mVelocityToAdd.y), (__m128)0i64)),
            mBody->m_motion.m_linearVelocity.m_quad);
    hkpEntity::activate(mBody);
    mBody->m_motion.vfptr[9].__vecDelDtor(&mBody->m_motion, (unsigned int)&v34);
    m_pSimObject = pmi->m_pSimObject;
    if ( m_pSimObject )
      m_pComponent = m_pSimObject->m_Components.p[2].m_pComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pComponent);
    mPrev_low = (__m128)LODWORD(m_pComponent[2].m_SafePointerList.mNode.mPrev);
    vfptr_low = (__m128)LODWORD(m_pComponent[2].vfptr);
    vfptr_high = (__m128)HIDWORD(m_pComponent[2].vfptr);
    v25 = (float)(1.0 - COERCE_FLOAT(LODWORD(this->mForwardsness) & _xmm)) * this->mSwerveImpulse;
    vfptr_high.m128_f32[0] = (float)((float)(vfptr_high.m128_f32[0] * this->mMotionIntentionDirection.z)
                                   - (float)(*(float *)&m_pComponent[2].m_SafePointerList.mNode.mPrev
                                           * this->mMotionIntentionDirection.y))
                           * v25;
    mPrev_low.m128_f32[0] = (float)((float)(mPrev_low.m128_f32[0] * this->mMotionIntentionDirection.x)
                                  - (float)(*(float *)&m_pComponent[2].vfptr * this->mMotionIntentionDirection.z))
                          * v25;
    vfptr_low.m128_f32[0] = (float)((float)(vfptr_low.m128_f32[0] * this->mMotionIntentionDirection.y)
                                  - (float)(*((float *)&m_pComponent[2].vfptr + 1) * this->mMotionIntentionDirection.x))
                          * v25;
    if ( !this->mTarget.m_pPointer )
    {
      mNoTargetModifier = this->mNoTargetModifier;
      vfptr_high.m128_f32[0] = vfptr_high.m128_f32[0] * mNoTargetModifier;
      mPrev_low.m128_f32[0] = mPrev_low.m128_f32[0] * mNoTargetModifier;
      vfptr_low.m128_f32[0] = vfptr_low.m128_f32[0] * mNoTargetModifier;
    }
    mCounterSwerveModifier = this->mCounterSwerveModifier;
    this->mCounterSpin.x = vfptr_high.m128_f32[0] * mCounterSwerveModifier;
    this->mCounterSpin.y = mPrev_low.m128_f32[0] * mCounterSwerveModifier;
    this->mCounterSpin.z = vfptr_low.m128_f32[0] * mCounterSwerveModifier;
    v35 = _mm_add_ps(
            _mm_unpacklo_ps(_mm_unpacklo_ps(vfptr_high, vfptr_low), _mm_unpacklo_ps(mPrev_low, (__m128)0i64)),
            mBody->m_motion.m_angularVelocity.m_quad);
    hkpEntity::activate(mBody);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))mBody->m_motion.vfptr[9].__first_virtual_table_function__)(
      &mBody->m_motion,
      &v35);
    v31 = pmi->mForwardSpeed;
    this->mState = ERamState_BoostedWaitingToDecel;
    this->mOriginalForwardSpeedKPH = v31 * 3.5999999;
    *((_BYTE *)pmi + 900) |= 8u;
    y = this->mVelocityToAdd.y;
    z = this->mVelocityToAdd.z;
    pmi->mRamVelocity.x = this->mVelocityToAdd.x;
    pmi->mRamVelocity.y = y;
    pmi->mRamVelocity.z = z;
  }
  return 0;
}

