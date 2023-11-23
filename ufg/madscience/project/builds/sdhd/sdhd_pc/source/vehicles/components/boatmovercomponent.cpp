// File Line: 41
// RVA: 0x157B770
__int64 dynamic_initializer_for__UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList__);
}

// File Line: 42
// RVA: 0x157AC40
__int64 dynamic_initializer_for__UFG::BoatPhysicsMoverComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::BoatPhysicsMoverComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::BoatPhysicsMoverComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::BoatPhysicsMoverComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::BoatPhysicsMoverComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 64
// RVA: 0x666FB0
void __fastcall UFG::BoatPhysicsMoverComponent::BoatPhysicsMoverComponent(
        UFG::BoatPhysicsMoverComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        component_BoatPhysicsMover *dataPtr)
{
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *mPrev; // rax

  UFG::PhysicsMoverInterface::PhysicsMoverInterface(this, 0, pSceneObj, dataPtr);
  this->UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>::mPrev = &this->UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>;
  this->UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>::mNext = &this->UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>;
  this->UFG::PhysicsMoverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoatPhysicsMoverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::PhysicsMoverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BoatPhysicsMoverComponent::`vftable{for `UFG::UpdateInterface};
  this->mDocked = 0;
  this->mIgnoreDockingTimer = 2.0;
  mPrev = UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList.mNode.mPrev;
  UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>;
  this->UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>::mNext = (UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *)&UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList;
  UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::BoatPhysicsMoverComponent::_BoatPhysicsMoverComponentTypeUID,
    "BoatPhysicsMoverComponent");
}

// File Line: 72
// RVA: 0x66C200
void __fastcall UFG::BoatPhysicsMoverComponent::~BoatPhysicsMoverComponent(UFG::BoatPhysicsMoverComponent *this)
{
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *v2; // rdx
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *mPrev; // rcx
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *mNext; // rax
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *v5; // rcx
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *v6; // rax

  this->UFG::PhysicsMoverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoatPhysicsMoverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::PhysicsMoverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BoatPhysicsMoverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentpCurrentIterator )
    UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentpCurrentIterator = (UFG::BoatPhysicsMoverComponent *)&this->UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>::mPrev[-58].mNext;
  v2 = &this->UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>;
  mPrev = this->UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::PhysicsMoverInterface::~PhysicsMoverInterface(this);
}

// File Line: 81
// RVA: 0x687F80
UFG::BoatPhysicsMoverComponent *__fastcall UFG::BoatPhysicsMoverComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_BoatPhysicsMover::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x3B0ui64, "BoatPhysicsMoverComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::BoatPhysicsMoverComponent::BoatPhysicsMoverComponent(
      (UFG::BoatPhysicsMoverComponent *)v10,
      pSceneObj,
      (component_BoatPhysicsMover *)MemImagePtr);
    v6 = v11;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags >= 0 )
    v14 = -1;
  else
    v14 = 34;
  UFG::SimObjectModifier::SimObjectModifier(&v15, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v15, v6, v14);
  UFG::SimObjectModifier::Close(&v15);
  UFG::SimObjectModifier::~SimObjectModifier(&v15);
  return (UFG::BoatPhysicsMoverComponent *)v6;
}

// File Line: 104
// RVA: 0x685F00
void __fastcall UFG::PhysicsBoat_OnExitWater(void *cxt)
{
  (*(void (__fastcall **)(void *))(*(_QWORD *)cxt + 264i64))(cxt);
}

// File Line: 111
// RVA: 0x675030
void __fastcall UFG::BoatPhysicsMoverComponent::CreateVehicle(
        UFG::BoatPhysicsMoverComponent *this,
        UFG::qMatrix44 *transform,
        UFG::qVector3 *velocity)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mSimObject; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::PhysicsVehicle *v12; // rsi
  UFG::PhysicsBoat *mFreeListHead; // rdi
  unsigned int v14; // eax
  UFG::PhysicsVehicle *v15; // rax
  UFG::WaterFloatingTrackerComponent *v16; // rdi
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx

  m_pSimObject = this->m_pSimObject;
  p_mSimObject = &this->mParameters.mSimObject;
  if ( this->mParameters.mSimObject.m_pPointer )
  {
    mPrev = p_mSimObject->mPrev;
    mNext = this->mParameters.mSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mSimObject->mPrev = p_mSimObject;
    this->mParameters.mSimObject.mNext = &this->mParameters.mSimObject;
  }
  this->mParameters.mSimObject.m_pPointer = m_pSimObject;
  if ( m_pSimObject )
  {
    p_mNode = &m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v11 = p_mNode->mPrev;
    v11->mNext = p_mSimObject;
    p_mSimObject->mPrev = v11;
    this->mParameters.mSimObject.mNext = p_mNode;
    p_mNode->mPrev = p_mSimObject;
  }
  v12 = 0i64;
  *(_QWORD *)&this->mParameters.firstFrontWheel = 0i64;
  *(_QWORD *)&this->mParameters.firstRearWheel = 0i64;
  mFreeListHead = (UFG::PhysicsBoat *)UFG::PhysicsVehicle::mAllocator.mFreeListHead;
  if ( UFG::PhysicsVehicle::mAllocator.mFreeListHead )
  {
    UFG::PhysicsVehicle::mAllocator.mFreeListHead = *(char **)UFG::PhysicsVehicle::mAllocator.mFreeListHead;
    v14 = UFG::PhysicsVehicle::mAllocator.mNumSlotsAllocated + 1;
    UFG::PhysicsVehicle::mAllocator.mNumSlotsAllocated = v14;
    if ( UFG::PhysicsVehicle::mAllocator.mMostSlotsAllocated <= v14 )
      UFG::PhysicsVehicle::mAllocator.mMostSlotsAllocated = v14;
  }
  else
  {
    mFreeListHead = (UFG::PhysicsBoat *)UFG::qMemoryPool::Allocate(
                                          &gPhysicsMemoryPool,
                                          0x3E0ui64,
                                          "PhysicsBoat",
                                          0i64,
                                          1u);
  }
  if ( mFreeListHead )
  {
    UFG::PhysicsBoat::PhysicsBoat(mFreeListHead, &this->mParameters, transform, velocity);
    v12 = v15;
  }
  this->mPhysicsVehicle = v12;
  v12->vfptr[3].__vecDelDtor(v12, (unsigned int)this);
  v16 = (UFG::WaterFloatingTrackerComponent *)UFG::AquireWaterFloatingTrackerComponent(
                                                this->m_pSimObject,
                                                this->mPhysicsVehicle->mRigidBody->mBody);
  if ( UFG::SimComponent::IsType(v16, UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID) )
  {
    this->mPhysicsVehicle->mWaterFloatingTrackerComponent = v16;
    mPhysicsVehicle = this->mPhysicsVehicle;
    v16->mOnEnterWaterCallback = (void (__fastcall *)(void *))UFG::CharacterSubjectComponent::ContainsPlayer;
    v16->mOnExitWaterCallback = UFG::PhysicsBoat_OnExitWater;
    v16->mCallbackObject = mPhysicsVehicle;
    UFG::WaterFloatingTrackerComponent::DisableSplashGeneration(v16);
  }
}

// File Line: 137
// RVA: 0x682940
void __fastcall UFG::BoatPhysicsMoverComponent::OnAttach(
        UFG::BoatPhysicsMoverComponent *this,
        UFG::SimObject *simObject)
{
  this->mMotorBoneId = (UFG::qSafeArray<int,2>)-1i64;
  this->mPropellerBoneId = (UFG::qSafeArray<int,2>)-1i64;
  UFG::PhysicsMoverInterface::OnAttach(this, simObject);
}

// File Line: 149
// RVA: 0x684100
// attributes: thunk
void __fastcall UFG::BoatPhysicsMoverComponent::OnDetach(UFG::BoatPhysicsMoverComponent *this)
{
  UFG::PhysicsMoverInterface::OnDetach(this);
}

// File Line: 156
// RVA: 0x1585460
__int64 UFG::_dynamic_initializer_for__symM_Motor01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_Motor01", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symM_Motor01, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symM_Motor01__);
}

// File Line: 157
// RVA: 0x15854A0
__int64 UFG::_dynamic_initializer_for__symM_Motor02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_Motor02", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symM_Motor02, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symM_Motor02__);
}

// File Line: 158
// RVA: 0x1585560
__int64 UFG::_dynamic_initializer_for__symM_Propeller__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_Propeller", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symM_Propeller, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symM_Propeller__);
}

// File Line: 159
// RVA: 0x15854E0
__int64 UFG::_dynamic_initializer_for__symM_Propeller01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_Propeller01", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symM_Propeller01, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symM_Propeller01__);
}

// File Line: 160
// RVA: 0x1585520
__int64 UFG::_dynamic_initializer_for__symM_Propeller02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_Propeller02", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symM_Propeller02, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symM_Propeller02__);
}

// File Line: 163
// RVA: 0x68F7F0
void __fastcall UFG::BoatPhysicsMoverComponent::Update(UFG::BoatPhysicsMoverComponent *this, float deltaTime)
{
  UFG::SimObjectCVBase *mPrev; // rcx
  UFG::CharacterAnimationComponent *v4; // rax
  Creature *mCreature; // rdi
  int v6; // esi
  float v7; // eax
  float v8; // eax
  float v9; // eax
  int BoneID; // eax

  if ( LODWORD(this->mLowLodMaxSpeed) == -1
    && LODWORD(this->mLowLodMaxLateralAcceleration) == -1
    && LODWORD(this->mLowLodMinTurningRadius) == -1
    && LODWORD(this->mAutoDeterioratingDamageThreshold) == -1 )
  {
    mPrev = (UFG::SimObjectCVBase *)this[-1].UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent>::mPrev;
    if ( mPrev )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(mPrev);
      if ( v4 )
      {
        mCreature = v4->mCreature;
        if ( mCreature )
        {
          v6 = -1;
          if ( mCreature->mPose.mRigHandle.mData )
            LODWORD(v7) = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::symM_Motor01.mUID);
          else
            v7 = NAN;
          this->mLowLodMaxSpeed = v7;
          if ( mCreature->mPose.mRigHandle.mData )
            LODWORD(v8) = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::symM_Motor02.mUID);
          else
            v8 = NAN;
          this->mLowLodMaxLateralAcceleration = v8;
          if ( mCreature->mPose.mRigHandle.mData )
            LODWORD(v9) = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::symM_Propeller.mUID);
          else
            v9 = NAN;
          this->mLowLodMinTurningRadius = v9;
          if ( v9 == NAN )
          {
            if ( mCreature->mPose.mRigHandle.mData )
              BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::symM_Propeller01.mUID);
            else
              BoneID = -1;
            LODWORD(this->mLowLodMinTurningRadius) = BoneID;
            if ( mCreature->mPose.mRigHandle.mData )
              v6 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::symM_Propeller02.mUID);
            LODWORD(this->mAutoDeterioratingDamageThreshold) = v6;
          }
        }
      }
    }
  }
  UFG::PhysicsMoverInterface::Update(this, deltaTime);
  UFG::BoatPhysicsMoverComponent::UpdateDockSnapTo((UFG::BoatPhysicsMoverComponent *)((char *)this - 64), deltaTime);
}

// File Line: 209
// RVA: 0x695CF0
void __fastcall UFG::BoatPhysicsMoverComponent::UpdateDockSnapTo(UFG::BoatPhysicsMoverComponent *this, float deltaTime)
{
  Render::DebugDrawContext *Context; // rbx
  float v4; // xmm0_4
  UFG::AiDriverComponent *m_pSimComponent; // rbx
  float mGasBrakes; // xmm0_4
  bool v7; // r12
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponentHolder *p; // rax
  UFG::SensorComponent *m_pComponent; // r13
  UFG::Event *v11; // rsi
  UFG::SimComponent *v12; // r14
  float *p_mNext; // r15
  float v14; // xmm7_4
  float v15; // xmm14_4
  float v16; // xmm15_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float y; // xmm2_4
  float z; // xmm1_4
  float v24; // xmm12_4
  float v25; // xmm1_4
  float v26; // xmm12_4
  float v27; // xmm8_4
  float v28; // xmm0_4
  UFG::ParkourHandle *ClosestParkourHandle; // rax
  UFG::ParkourHandle *v30; // r13
  float DistanceTo; // xmm0_4
  float v32; // xmm9_4
  float x; // xmm6_4
  float v34; // xmm7_4
  UFG::SensorComponent *v35; // r13
  UFG::ParkourHandle *v36; // rax
  UFG::ParkourHandle *v37; // r15
  float v38; // xmm0_4
  float v39; // xmm0_4
  UFG::qMatrix44 *v40; // r14
  UFG::qMatrix44 *v41; // rax
  UFG::qVector4 v42; // xmm2
  UFG::qVector4 v43; // xmm1
  UFG::qVector4 v44; // xmm0
  __m128 v45; // xmm13
  __m128 v46; // xmm15
  __m128 v47; // xmm14
  __m128 x_low; // xmm10
  __m128 y_low; // xmm2
  float v50; // xmm5_4
  float v51; // xmm7_4
  __m128 v52; // xmm2
  float v53; // xmm1_4
  __m128 v54; // xmm3
  float v55; // xmm2_4
  __m128 v56; // xmm5
  float v57; // xmm1_4
  float v58; // xmm12_4
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax
  __m128 z_low; // xmm3
  __m128 v61; // xmm4
  UFG::allocator::free_link *v62; // rax
  UFG::Event *v63; // rax
  hkpEntity *mBody; // rbx
  __int64 v65; // rdx
  UFG::allocator::free_link *v66; // rax
  UFG::Event *v67; // rax
  UFG::qVector3 distanceZMax; // [rsp+40h] [rbp-80h] BYREF
  UFG::qVector3 contactPosition; // [rsp+50h] [rbp-70h] BYREF
  UFG::qMatrix44 *v70[2]; // [rsp+60h] [rbp-60h] BYREF
  UFG::qVector3 p1; // [rsp+70h] [rbp-50h] BYREF
  UFG::qVector3 vmin; // [rsp+80h] [rbp-40h] BYREF
  UFG::qVector3 aabb_min; // [rsp+90h] [rbp-30h] BYREF
  UFG::qVector3 vmax; // [rsp+A0h] [rbp-20h] BYREF
  UFG::qMatrix44 xform; // [rsp+B0h] [rbp-10h] BYREF
  __m128 v76; // [rsp+F0h] [rbp+30h] BYREF
  __int64 v77; // [rsp+100h] [rbp+40h]
  UFG::qMatrix44 dest; // [rsp+110h] [rbp+50h] BYREF
  UFG::qMatrix44 result; // [rsp+150h] [rbp+90h] BYREF
  UFG::ParkourHandle *v80; // [rsp+280h] [rbp+1C0h]
  UFG::SensorComponent *sensor_component; // [rsp+290h] [rbp+1D0h] BYREF
  UFG::qVector2 v1; // [rsp+298h] [rbp+1D8h] BYREF

  v77 = -2i64;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v4 = this->mIgnoreDockingTimer - deltaTime;
  this->mIgnoreDockingTimer = v4;
  if ( v4 <= 0.0 )
    v4 = 0.0;
  this->mIgnoreDockingTimer = v4;
  if ( !this->mDocked )
  {
    if ( v4 > 0.0 )
      return;
    v7 = this->mDriverComponent.m_pSimComponent && LOBYTE(this->mDriverComponent.m_pSimComponent[4].m_TypeUID);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(this)) & _xmm) >= UFG::BoatPhysicsMoverComponent::msDockSnapToSpeedThreshold
      && !v7 )
    {
      return;
    }
    m_pSimObject = this->m_pSimObject;
    if ( !m_pSimObject )
      return;
    p = m_pSimObject->m_Components.p;
    m_pComponent = (UFG::SensorComponent *)p[26].m_pComponent;
    sensor_component = m_pComponent;
    if ( !m_pComponent )
      return;
    v11 = 0i64;
    v12 = p[2].m_pComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
    p_mNext = (float *)&v12[2].m_SafePointerList.mNode.mNext;
    LODWORD(v14) = v12[2].m_TypeUID ^ _xmm[0];
    LODWORD(v15) = HIDWORD(v12[2].m_SafePointerList.mNode.mNext) ^ _xmm[0];
    LODWORD(v16) = LODWORD(v12[2].m_SafePointerList.mNode.mNext) ^ _xmm[0];
    contactPosition.x = v16;
    contactPosition.y = v15;
    contactPosition.z = v14;
    v80 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
    v70[0] = (UFG::qMatrix44 *)&v12[2];
    v17 = (float)(Twk_DockBoatCenterOffset * *(float *)&v12[2].m_SafePointerList.mNode.mPrev)
        + *(float *)&v12[2].m_BoundComponentHandles.mNode.mNext;
    v18 = (float)(Twk_DockBoatCenterOffset * *((float *)&v12[2].vfptr + 1))
        + *((float *)&v12[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v19 = (float)(Twk_DockBoatCenterOffset * *(float *)&v12[2].vfptr)
        + *(float *)&v12[2].m_BoundComponentHandles.mNode.mPrev;
    *(float *)v70 = v19;
    *((float *)v70 + 1) = v18;
    *(float *)&v70[1] = v17;
    if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
    {
      v20 = (float)(*(float *)&v12[2].m_TypeUID * 2.0) + v17;
      v21 = (float)(*((float *)&v12[2].m_SafePointerList.mNode.mNext + 1) * 2.0) + v18;
      p1.x = (float)(*p_mNext * 2.0) + v19;
      p1.y = v21;
      p1.z = v20;
      Render::DebugDrawContext::DrawLine(
        Context,
        (UFG::qVector3 *)v70,
        &p1,
        &UFG::qColour::Yellow,
        &UFG::qMatrix44::msIdentity,
        0i64,
        0);
      p1.x = (float)(v16 * 2.0) + *(float *)v70;
      p1.y = *((float *)v70 + 1) + (float)(v15 * 2.0);
      p1.z = *(float *)&v70[1] + (float)(v14 * 2.0);
      Render::DebugDrawContext::DrawLine(
        Context,
        (UFG::qVector3 *)v70,
        &p1,
        &UFG::qColour::Red,
        &UFG::qMatrix44::msIdentity,
        0i64,
        0);
    }
    y = this->mBoundingBoxMin.y;
    z = this->mBoundingBoxMin.z;
    aabb_min.x = this->mBoundingBoxMin.x;
    aabb_min.y = y;
    aabb_min.z = z;
    v24 = this->mBoundingBoxMax.y;
    v25 = this->mBoundingBoxMax.z;
    p1.x = this->mBoundingBoxMax.x;
    p1.y = v24;
    p1.z = v25;
    v26 = v24 - y;
    v27 = v26 * 3.0;
    UFG::SensorComponent::GetExtents(m_pComponent, &vmin, &vmax);
    LODWORD(v28) = COERCE_UNSIGNED_INT(vmax.x - vmin.x) & _xmm;
    if ( v28 >= COERCE_FLOAT(COERCE_UNSIGNED_INT(vmax.y - vmin.y) & _xmm) )
      LODWORD(v28) = COERCE_UNSIGNED_INT(vmax.y - vmin.y) & _xmm;
    if ( v28 < v27 )
      v27 = v28;
    ClosestParkourHandle = UFG::BoatPhysicsMoverComponent::FindClosestParkourHandle(
                             this,
                             m_pComponent,
                             (UFG::qVector3 *)v70,
                             (UFG::qVector3 *)&v12[2].m_SafePointerList.mNode.mNext,
                             0.78539819,
                             0.0,
                             v27,
                             -0.5,
                             3.0,
                             2,
                             0i64);
    v30 = ClosestParkourHandle;
    if ( ClosestParkourHandle )
    {
      if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
      {
        UFG::ParkourHandle::GetPosition(ClosestParkourHandle, &distanceZMax);
        Render::DebugDrawContext::DrawLine(
          Context,
          (UFG::qVector3 *)v70,
          &distanceZMax,
          &UFG::qColour::Cyan,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        *(_QWORD *)&p1.x = *(_QWORD *)&distanceZMax.x;
        p1.z = distanceZMax.z + 3.0;
        Render::DebugDrawContext::DrawCylinder(
          Context,
          &distanceZMax,
          &p1,
          0.2,
          &UFG::qColour::Cyan,
          &UFG::qMatrix44::msIdentity,
          0i64);
      }
      DistanceTo = UFG::ParkourHandle::GetDistanceTo(v30, (UFG::qVector3 *)v70);
      v32 = FLOAT_3_4028235e38;
      if ( DistanceTo < 3.4028235e38
        && (DistanceTo < UFG::BoatPhysicsMoverComponent::msDockSnapToDistanceThreshold || v7) )
      {
        v32 = DistanceTo;
        v80 = v30;
        x = *p_mNext;
        v34 = *((float *)&v12[2].m_SafePointerList.mNode.mNext + 1);
        goto LABEL_38;
      }
    }
    else
    {
      v32 = FLOAT_3_4028235e38;
    }
    v34 = vmin.y;
    x = vmin.x;
LABEL_38:
    v35 = sensor_component;
    v36 = UFG::BoatPhysicsMoverComponent::FindClosestParkourHandle(
            this,
            sensor_component,
            (UFG::qVector3 *)v70,
            &contactPosition,
            0.78539819,
            0.0,
            v27,
            -0.5,
            3.0,
            2,
            0i64);
    v37 = v36;
    if ( !v36 )
      goto LABEL_45;
    if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
    {
      UFG::ParkourHandle::GetPosition(v36, &distanceZMax);
      Render::DebugDrawContext::DrawLine(
        Context,
        (UFG::qVector3 *)v70,
        &distanceZMax,
        &UFG::qColour::Magenta,
        &UFG::qMatrix44::msIdentity,
        0i64,
        0);
      *(_QWORD *)&p1.x = *(_QWORD *)&distanceZMax.x;
      p1.z = distanceZMax.z + 3.0;
      Render::DebugDrawContext::DrawCylinder(
        Context,
        &distanceZMax,
        &p1,
        0.2,
        &UFG::qColour::Magenta,
        &UFG::qMatrix44::msIdentity,
        0i64);
    }
    v38 = UFG::ParkourHandle::GetDistanceTo(v37, (UFG::qVector3 *)v70);
    if ( v38 < v32 && (v38 < UFG::BoatPhysicsMoverComponent::msDockSnapToDistanceThreshold || v7) )
    {
      x = v16;
      v34 = v15;
    }
    else
    {
LABEL_45:
      v37 = v80;
    }
    if ( v37 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
      LODWORD(v80) = v12[2].m_BoundComponentHandles.mNode.mNext;
      if ( UFG::ParkourHandle::GetNormal(v37, &p1) )
      {
        v1.x = p1.x;
        v1.y = p1.y;
        LODWORD(sensor_component) = LODWORD(x) ^ _xmm[0];
        HIDWORD(sensor_component) = LODWORD(v34) ^ _xmm[0];
        v39 = UFG::qAngleBetween(&v1, (UFG::qVector2 *)&sensor_component);
        if ( v39 > 3.1415927 )
          v39 = v39 + -3.1415927;
        UFG::qRotationMatrixAxis(&dest, &UFG::qVector3::msDirUp, v39);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
        v40 = v70[0];
        v41 = UFG::qMatrix44::operator*(v70[0], &result, &dest);
        v42 = v41->v1;
        v43 = v41->v2;
        v44 = v41->v3;
        xform.v0 = v41->v0;
        xform.v1 = v42;
        xform.v2 = v43;
        xform.v3 = v44;
        if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
        {
          Render::DebugDrawContext::DrawAABB(Context, &aabb_min, &p1, &UFG::qColour::Cyan, &xform, 0i64);
          Render::DebugDrawContext::DrawAxes(Context, &xform, 1.0, 0, 0i64);
        }
        UFG::ParkourHandle::GetClosestPointOnHandle(v37, &distanceZMax, (UFG::qVector3 *)v70);
        v45 = (__m128)LODWORD(v70[1]);
        v46 = (__m128)HIDWORD(v70[0]);
        v47 = (__m128)LODWORD(v70[0]);
        x_low = (__m128)LODWORD(distanceZMax.x);
        y_low = (__m128)LODWORD(p1.y);
        y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(p1.x * p1.x))
                          + (float)(p1.z * p1.z);
        v50 = _mm_sqrt_ps(y_low).m128_f32[0];
        v51 = (float)((float)((float)(*(float *)v70 - distanceZMax.x) * p1.x)
                    + (float)(p1.y * (float)(*((float *)v70 + 1) - distanceZMax.y)))
            + (float)(p1.z * (float)(*(float *)&v70[1] - distanceZMax.z));
        v52 = (__m128)(unsigned int)FLOAT_1_0;
        v52.m128_f32[0] = 1.0 / v50;
        v53 = (float)(1.0 / v50) * (float)((float)(p1.z * (float)(1.0 / v50)) * v51);
        v54 = v52;
        v54.m128_f32[0] = (float)(1.0 / v50) * (float)((float)(p1.y * (float)(1.0 / v50)) * v51);
        v55 = (float)(1.0 / v50) * (float)((float)(p1.x * (float)(1.0 / v50)) * v51);
        v56 = v54;
        v56.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(v55 * v55)) + (float)(v53 * v53);
        if ( v56.m128_f32[0] == 0.0 )
          v57 = 0.0;
        else
          v57 = 1.0 / _mm_sqrt_ps(v56).m128_f32[0];
        v58 = (float)(v26 * 0.5) + UFG::BoatPhysicsMoverComponent::msDockSnapToDistanceFromDock;
        x_low.m128_f32[0] = distanceZMax.x + (float)((float)(v55 * v57) * v58);
        contactPosition.x = x_low.m128_f32[0];
        contactPosition.y = distanceZMax.y + (float)((float)(v54.m128_f32[0] * v57) * v58);
        LODWORD(contactPosition.z) = (_DWORD)v80;
        xform.v3.x = x_low.m128_f32[0];
        xform.v3.y = contactPosition.y;
        LODWORD(xform.v3.z) = (_DWORD)v80;
        xform.v3.w = 1.0;
        if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
        {
          *(float *)&v70[1] = *(float *)&v70[1] + 3.0;
          Render::DebugDrawContext::DrawCylinder(
            Context,
            (UFG::qVector3 *)v70,
            (UFG::qVector3 *)v70,
            0.2,
            &UFG::qColour::Green,
            &UFG::qMatrix44::msIdentity,
            0i64);
          v70[0] = *(UFG::qMatrix44 **)&contactPosition.x;
          *(float *)&v70[1] = contactPosition.z + 2.8;
          Render::DebugDrawContext::DrawCylinder(
            Context,
            &contactPosition,
            (UFG::qVector3 *)v70,
            0.25,
            &UFG::qColour::Yellow,
            &UFG::qMatrix44::msIdentity,
            0i64);
          Render::DebugDrawContext::DrawLine(
            Context,
            (UFG::qVector3 *)v70,
            &contactPosition,
            &UFG::qColour::Green,
            &UFG::qMatrix44::msIdentity,
            0i64,
            0);
          v70[0] = *(UFG::qMatrix44 **)&distanceZMax.x;
          *(float *)&v70[1] = distanceZMax.z + 2.5999999;
          Render::DebugDrawContext::DrawCylinder(
            Context,
            &distanceZMax,
            (UFG::qVector3 *)v70,
            0.30000001,
            &UFG::qColour::Blue,
            &UFG::qMatrix44::msIdentity,
            0i64);
          if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
          {
            Render::DebugDrawContext::DrawAABB(Context, &aabb_min, &p1, &UFG::qColour::Orange, &xform, 0i64);
            Render::DebugDrawContext::DrawAxes(Context, &xform, 1.0, 0, 0i64);
          }
          x_low = (__m128)LODWORD(contactPosition.x);
          v47 = (__m128)LODWORD(v70[0]);
          v46 = (__m128)HIDWORD(v70[0]);
          v45 = (__m128)LODWORD(v70[1]);
        }
        if ( Twk_DockingEnabled )
        {
          if ( Twk_SlideToDockedLocation )
          {
            mPhysicsVehicle = this->mPhysicsVehicle;
            if ( mPhysicsVehicle )
            {
              z_low = (__m128)LODWORD(contactPosition.z);
              z_low.m128_f32[0] = contactPosition.z - v45.m128_f32[0];
              v61 = (__m128)LODWORD(contactPosition.y);
              v61.m128_f32[0] = contactPosition.y - v46.m128_f32[0];
              x_low.m128_f32[0] = x_low.m128_f32[0] - v47.m128_f32[0];
              if ( (float)((float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                 + (float)(v61.m128_f32[0] * v61.m128_f32[0]))
                         + (float)(z_low.m128_f32[0] * z_low.m128_f32[0])) >= Twk_SlideToDockDistToDestThresholdSq )
              {
                z_low.m128_f32[0] = z_low.m128_f32[0] * Twk_SlideToSpringConstant;
                v61.m128_f32[0] = v61.m128_f32[0] * Twk_SlideToSpringConstant;
                x_low.m128_f32[0] = x_low.m128_f32[0] * Twk_SlideToSpringConstant;
                v76 = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), _mm_unpacklo_ps(v61, (__m128)0i64));
                mBody = mPhysicsVehicle->mRigidBody->mBody;
                *(__m128 *)v70 = _mm_unpacklo_ps(_mm_unpacklo_ps(v47, v45), _mm_unpacklo_ps(v46, (__m128)0i64));
                hkpEntity::activate(mBody);
                ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, UFG::qMatrix44 **))mBody->m_motion.vfptr[12].__first_virtual_table_function__)(
                  &mBody->m_motion,
                  v65,
                  &v76,
                  v70);
              }
              else
              {
                v62 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
                v80 = (UFG::ParkourHandle *)v62;
                if ( v62 )
                  UFG::TeleportEvent::TeleportEvent(
                    (UFG::TeleportEvent *)v62,
                    v40,
                    this->m_pSimObject->mNode.mUID,
                    0,
                    UFG::TeleportEvent::m_Name,
                    0);
                else
                  v63 = 0i64;
                UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v63);
                this->mDocked = 1;
                this->mIgnoreDockingTimer = 2.0;
                if ( v7 && this->mDriverComponent.m_pSimComponent )
                  LOBYTE(this->mDriverComponent.m_pSimComponent[4].m_TypeUID) = 0;
              }
            }
          }
          if ( Twk_TeleportToDockedLocation )
          {
            v66 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
            v80 = (UFG::ParkourHandle *)v66;
            if ( v66 )
            {
              UFG::TeleportEvent::TeleportEvent(
                (UFG::TeleportEvent *)v66,
                &xform,
                this->m_pSimObject->mNode.mUID,
                0,
                UFG::TeleportEvent::m_Name,
                0);
              v11 = v67;
            }
            UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v11);
            this->mDocked = 1;
            this->mIgnoreDockingTimer = 2.0;
            if ( v7 && this->mDriverComponent.m_pSimComponent )
              LOBYTE(this->mDriverComponent.m_pSimComponent[4].m_TypeUID) = 0;
          }
        }
      }
    }
    UFG::SensorComponent::CollectParkourHandles(v35, 6.0);
    return;
  }
  if ( this->mDriverComponent.m_pSimComponent
    && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))this->mDriverComponent.m_pSimComponent->vfptr[14].__vecDelDtor)(this->mDriverComponent.m_pSimComponent) )
  {
    m_pSimComponent = (UFG::AiDriverComponent *)this->mDriverComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      this->UFG::PhysicsMoverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor(
        this,
        2u);
      UFG::AiDriverComponent::SetGasBrakeLock(m_pSimComponent, 0.0);
      *((_DWORD *)&this->mInput + 4) &= ~0x20u;
      *((_DWORD *)&this->mInput + 4) |= 4u;
      if ( m_pSimComponent->m_fDesiredSpeed > 0.0 )
      {
        UFG::AiDriverComponent::ClearGasBrakeLock(m_pSimComponent);
LABEL_11:
        this->mDocked = 0;
        this->mIgnoreDockingTimer = 2.0;
      }
    }
  }
  else
  {
    mGasBrakes = this->mInput.mGasBrakes;
    if ( mGasBrakes >= 0.5 || mGasBrakes <= -0.5 )
      goto LABEL_11;
  }
}

// File Line: 553
// RVA: 0x678600
UFG::ParkourHandle *__fastcall UFG::BoatPhysicsMoverComponent::FindClosestParkourHandle(
        UFG::BoatPhysicsMoverComponent *this,
        UFG::SensorComponent *sensor_component,
        UFG::qVector3 *position,
        UFG::qVector3 *orientationVector,
        float relativeAngle,
        float distanceXYMin,
        float distanceXYMax,
        float distanceZMin,
        float distanceZMax,
        __int16 check,
        UFG::qVector3 *contactPosition)
{
  __int64 v15; // rdi
  UFG::qVector3 *v16; // r15
  __int16 v17; // r12
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm9_4
  float v22; // xmm10_4
  UFG::ParkourHandle *v23; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  float v27; // [rsp+70h] [rbp-48E8h] BYREF
  UFG::ParkourHandle *v28; // [rsp+78h] [rbp-48E0h] BYREF
  UFG::qVector3 v29; // [rsp+80h] [rbp-48D8h] BYREF
  __int64 v30; // [rsp+90h] [rbp-48C8h]
  UFG::qVector3 vmax; // [rsp+98h] [rbp-48C0h] BYREF
  UFG::qVector3 vmin; // [rsp+A8h] [rbp-48B0h] BYREF
  UFG::qFixedArray<UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle>,768> out; // [rsp+C0h] [rbp-4898h] BYREF
  bool v34; // [rsp+4968h] [rbp+10h] BYREF

  v30 = -2i64;
  v28 = 0i64;
  v27 = FLOAT_3_4028235e38;
  if ( !sensor_component )
    return 0i64;
  UFG::SensorComponent::GetExtents(sensor_component, &vmin, &vmax);
  `eh vector constructor iterator(
    out.p,
    0x18ui64,
    768,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  out.size = 0;
  UFG::SensorComponent::GetParkourHandles(sensor_component, &out);
  v15 = 0i64;
  if ( out.size )
  {
    v16 = contactPosition;
    v17 = check;
    v18 = distanceZMax;
    v19 = distanceZMin;
    v20 = distanceXYMax;
    v21 = distanceXYMin;
    v22 = relativeAngle;
    do
    {
      v34 = 0;
      v23 = (UFG::ParkourHandle *)*((_QWORD *)&out.p[0].m_pPointer + 3 * v15);
      if ( v23
        && v23->mSimObject.m_pPointer != this->m_pSimObject
        && UFG::ParkourHandle::IsEnabled(*(&out.p[0].m_pPointer + 3 * v15)) )
      {
        y = orientationVector->y;
        z = orientationVector->z;
        v29.x = orientationVector->x;
        v29.y = y;
        v29.z = z;
        UFG::ParkourHandle::CompareParkourHandles(
          v23,
          v17,
          position,
          &v29,
          v22,
          0.0,
          v21,
          v20,
          v19,
          v18,
          v16,
          &v28,
          &v27,
          &v34);
      }
      v15 = (unsigned int)(v15 + 1);
    }
    while ( (unsigned int)v15 < out.size );
  }
  out.size = 0;
  `eh vector destructor iterator(
    out.p,
    0x18ui64,
    768,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  return v28;
}

