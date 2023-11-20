// File Line: 41
// RVA: 0x157B770
__int64 dynamic_initializer_for__UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList__);
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
void __fastcall UFG::BoatPhysicsMoverComponent::BoatPhysicsMoverComponent(UFG::BoatPhysicsMoverComponent *this, UFG::SceneObjectProperties *pSceneObj, component_BoatPhysicsMover *dataPtr)
{
  UFG::BoatPhysicsMoverComponent *v3; // rbx
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *v4; // rdx
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *v5; // rax

  v3 = this;
  UFG::PhysicsMoverInterface::PhysicsMoverInterface(
    (UFG::PhysicsMoverInterface *)&this->vfptr,
    0,
    pSceneObj,
    (component_PhysicsMover *)&dataPtr->physicsPropertySetAI);
  v4 = (UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoatPhysicsMoverComponent::`vftable{for `UFG::SimComponent};
  v3->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BoatPhysicsMoverComponent::`vftable{for `UFG::UpdateInterface};
  v3->mDocked = 0;
  v3->mIgnoreDockingTimer = 2.0;
  v5 = UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList.mNode.mPrev;
  UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *)&UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList;
  UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentList.mNode.mPrev = (UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::BoatPhysicsMoverComponent::_BoatPhysicsMoverComponentTypeUID,
    "BoatPhysicsMoverComponent");
}

// File Line: 72
// RVA: 0x66C200
void __fastcall UFG::BoatPhysicsMoverComponent::~BoatPhysicsMoverComponent(UFG::BoatPhysicsMoverComponent *this)
{
  UFG::BoatPhysicsMoverComponent *v1; // r8
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *v2; // rdx
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *v3; // rcx
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *v4; // rax
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *v5; // rcx
  UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoatPhysicsMoverComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BoatPhysicsMoverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentpCurrentIterator )
    UFG::BoatPhysicsMoverComponent::s_BoatPhysicsMoverComponentpCurrentIterator = (UFG::BoatPhysicsMoverComponent *)&this->mPrev[-58].mNext;
  v2 = (UFG::qNode<UFG::BoatPhysicsMoverComponent,UFG::BoatPhysicsMoverComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::PhysicsMoverInterface::~PhysicsMoverInterface((UFG::PhysicsMoverInterface *)&v1->vfptr);
}

// File Line: 81
// RVA: 0x687F80
UFG::SimComponent *__fastcall UFG::BoatPhysicsMoverComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rdx
  unsigned __int16 v13; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_BoatPhysicsMover::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v7 )
      goto LABEL_9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x3B0ui64, "BoatPhysicsMoverComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::BoatPhysicsMoverComponent::BoatPhysicsMoverComponent(
      (UFG::BoatPhysicsMoverComponent *)v10,
      v3,
      (component_BoatPhysicsMover *)v7);
    v6 = v11;
  }
  v12 = v3->m_pSimObject;
  v13 = v12->m_Flags;
  if ( (v13 >> 14) & 1 || (v13 & 0x8000u) == 0 )
    v14 = -1;
  else
    v14 = 34;
  UFG::SimObjectModifier::SimObjectModifier(&v15, v12, 1);
  UFG::SimObjectModifier::AttachComponent(&v15, v6, v14);
  UFG::SimObjectModifier::Close(&v15);
  UFG::SimObjectModifier::~SimObjectModifier(&v15);
  return v6;
}

// File Line: 104
// RVA: 0x685F00
void __fastcall UFG::PhysicsBoat_OnExitWater(void *cxt)
{
  (*(void (**)(void))(*(_QWORD *)cxt + 264i64))();
}

// File Line: 111
// RVA: 0x675030
void __fastcall UFG::BoatPhysicsMoverComponent::CreateVehicle(UFG::BoatPhysicsMoverComponent *this, UFG::qMatrix44 *transform, UFG::qVector3 *velocity)
{
  UFG::qVector3 *v3; // rbp
  UFG::qMatrix44 *v4; // r14
  UFG::BoatPhysicsMoverComponent *v5; // rbx
  UFG::SimObject *v6; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::PhysicsVehicle *v12; // rsi
  UFG::PhysicsBoat *v13; // rdi
  unsigned int v14; // eax
  UFG::PhysicsVehicle *v15; // rax
  UFG::WaterFloatingTrackerComponent *v16; // rdi
  UFG::PhysicsVehicle *v17; // rcx

  v3 = velocity;
  v4 = transform;
  v5 = this;
  v6 = this->m_pSimObject;
  v7 = &v5->mParameters.mSimObject;
  if ( v5->mParameters.mSimObject.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v5->mParameters.mSimObject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v5->mParameters.mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mParameters.mSimObject.mPrev;
  }
  v5->mParameters.mSimObject.m_pPointer = v6;
  if ( v6 )
  {
    v10 = &v6->m_SafePointerList;
    v11 = v10->mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v11;
    v5->mParameters.mSimObject.mNext = &v10->mNode;
    v10->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v12 = 0i64;
  *(_QWORD *)&v5->mParameters.firstFrontWheel = 0i64;
  *(_QWORD *)&v5->mParameters.firstRearWheel = 0i64;
  v13 = (UFG::PhysicsBoat *)UFG::PhysicsVehicle::mAllocator.mFreeListHead;
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
    v13 = (UFG::PhysicsBoat *)UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x3E0ui64, "PhysicsBoat", 0i64, 1u);
  }
  if ( v13 )
  {
    UFG::PhysicsBoat::PhysicsBoat(v13, &v5->mParameters, v4, v3);
    v12 = v15;
  }
  v5->mPhysicsVehicle = v12;
  v12->vfptr[3].__vecDelDtor((UFG::BasePhysicsObject *)&v12->vfptr, (unsigned int)v5);
  v16 = (UFG::WaterFloatingTrackerComponent *)UFG::AquireWaterFloatingTrackerComponent(
                                                v5->m_pSimObject,
                                                v5->mPhysicsVehicle->mRigidBody->mBody);
  if ( UFG::SimComponent::IsType(
         (UFG::SimComponent *)&v16->vfptr,
         UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID) )
  {
    v5->mPhysicsVehicle->mWaterFloatingTrackerComponent = v16;
    v17 = v5->mPhysicsVehicle;
    v16->mOnEnterWaterCallback = (void (__fastcall *)(void *))UFG::CharacterSubjectComponent::ContainsPlayer;
    v16->mOnExitWaterCallback = UFG::PhysicsBoat_OnExitWater;
    v16->mCallbackObject = v17;
    UFG::WaterFloatingTrackerComponent::DisableSplashGeneration(v16);
  }
}

// File Line: 137
// RVA: 0x682940
void __fastcall UFG::BoatPhysicsMoverComponent::OnAttach(UFG::BoatPhysicsMoverComponent *this, UFG::SimObject *simObject)
{
  this->mMotorBoneId = (UFG::qSafeArray<int,2>)-1i64;
  this->mPropellerBoneId = (UFG::qSafeArray<int,2>)-1i64;
  UFG::PhysicsMoverInterface::OnAttach((UFG::PhysicsMoverInterface *)&this->vfptr, simObject);
}

// File Line: 149
// RVA: 0x684100
void __fastcall UFG::BoatPhysicsMoverComponent::OnDetach(UFG::BoatPhysicsMoverComponent *this)
{
  UFG::PhysicsMoverInterface::OnDetach((UFG::PhysicsMoverInterface *)&this->vfptr);
}

// File Line: 156
// RVA: 0x1585460
__int64 UFG::_dynamic_initializer_for__symM_Motor01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_Motor01", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symM_Motor01, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symM_Motor01__);
}

// File Line: 157
// RVA: 0x15854A0
__int64 UFG::_dynamic_initializer_for__symM_Motor02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_Motor02", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symM_Motor02, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symM_Motor02__);
}

// File Line: 158
// RVA: 0x1585560
__int64 UFG::_dynamic_initializer_for__symM_Propeller__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_Propeller", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symM_Propeller, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symM_Propeller__);
}

// File Line: 159
// RVA: 0x15854E0
__int64 UFG::_dynamic_initializer_for__symM_Propeller01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_Propeller01", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symM_Propeller01, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symM_Propeller01__);
}

// File Line: 160
// RVA: 0x1585520
__int64 UFG::_dynamic_initializer_for__symM_Propeller02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_Propeller02", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symM_Propeller02, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symM_Propeller02__);
}

// File Line: 163
// RVA: 0x68F7F0
void __fastcall UFG::BoatPhysicsMoverComponent::Update(UFG::BoatPhysicsMoverComponent *this, float deltaTime)
{
  UFG::BoatPhysicsMoverComponent *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::CharacterAnimationComponent *v4; // rax
  Creature *v5; // rdi
  signed int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  signed int v10; // eax

  v2 = this;
  if ( *(_OWORD *)&this->mLowLodMaxSpeed == __PAIR__(-1i64, -1i64) )
  {
    v3 = (UFG::SimObjectCVBase *)this[-1].mPrev;
    if ( v3 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
      if ( v4 )
      {
        v5 = v4->mCreature;
        if ( v5 )
        {
          v6 = -1;
          v7 = v5->mPose.mRigHandle.mData ? (unsigned int)Skeleton::GetBoneID(
                                                            v5->mPose.mRigHandle.mUFGSkeleton,
                                                            UFG::symM_Motor01.mUID) : -1;
          LODWORD(v2->mLowLodMaxSpeed) = v7;
          v8 = v5->mPose.mRigHandle.mData ? (unsigned int)Skeleton::GetBoneID(
                                                            v5->mPose.mRigHandle.mUFGSkeleton,
                                                            UFG::symM_Motor02.mUID) : -1;
          LODWORD(v2->mLowLodMaxLateralAcceleration) = v8;
          v9 = v5->mPose.mRigHandle.mData ? (unsigned int)Skeleton::GetBoneID(
                                                            v5->mPose.mRigHandle.mUFGSkeleton,
                                                            UFG::symM_Propeller.mUID) : -1;
          LODWORD(v2->mLowLodMinTurningRadius) = v9;
          if ( v9 == -1 )
          {
            if ( v5->mPose.mRigHandle.mData )
              v10 = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, UFG::symM_Propeller01.mUID);
            else
              v10 = -1;
            LODWORD(v2->mLowLodMinTurningRadius) = v10;
            if ( v5->mPose.mRigHandle.mData )
              v6 = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, UFG::symM_Propeller02.mUID);
            LODWORD(v2->mAutoDeterioratingDamageThreshold) = v6;
          }
        }
      }
    }
  }
  UFG::PhysicsMoverInterface::Update((UFG::PhysicsMoverInterface *)&v2->vfptr, deltaTime);
  UFG::BoatPhysicsMoverComponent::UpdateDockSnapTo((UFG::BoatPhysicsMoverComponent *)((char *)v2 - 64), deltaTime);
}

// File Line: 209
// RVA: 0x695CF0
void __fastcall UFG::BoatPhysicsMoverComponent::UpdateDockSnapTo(UFG::BoatPhysicsMoverComponent *this, float deltaTime)
{
  UFG::BoatPhysicsMoverComponent *v2; // rdi
  Render::DebugDrawContext *v3; // rbx
  float v4; // xmm0_4
  UFG::AiDriverComponent *v5; // rbx
  float v6; // xmm0_4
  char v7; // r12
  UFG::SimObject *v8; // rcx
  UFG::SimComponentHolder *v9; // rax
  UFG::SensorComponent *v10; // r13
  UFG::Event *v11; // rsi
  UFG::SimComponent *v12; // r14
  float *v13; // r15
  float v14; // xmm7_4
  int v15; // xmm14_4
  int v16; // xmm15_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm12_4
  float v25; // xmm1_4
  float v26; // xmm12_4
  float v27; // xmm8_4
  float v28; // xmm0_4
  UFG::ParkourHandle *v29; // rax
  UFG::ParkourHandle *v30; // r13
  float v31; // xmm0_4
  float v32; // xmm9_4
  float v33; // xmm6_4
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
  __m128 v48; // xmm10
  __m128 v49; // xmm2
  float v50; // xmm5_4
  float v51; // xmm7_4
  float v52; // xmm0_4
  __m128 v53; // xmm2
  float v54; // xmm1_4
  __m128 v55; // xmm3
  float v56; // xmm2_4
  __m128 v57; // xmm5
  float v58; // xmm1_4
  float v59; // xmm12_4
  float v60; // xmm3_4
  UFG::PhysicsVehicle *v61; // rax
  __m128 v62; // xmm3
  __m128 v63; // xmm4
  UFG::allocator::free_link *v64; // rax
  UFG::Event *v65; // rax
  hkpEntity *v66; // rbx
  __int64 v67; // rdx
  UFG::allocator::free_link *v68; // rax
  UFG::Event *v69; // rax
  UFG::qMatrix44 *distanceZMax; // [rsp+40h] [rbp-80h]
  unsigned int check; // [rsp+48h] [rbp-78h]
  UFG::qVector3 *contactPosition; // [rsp+50h] [rbp-70h]
  float v73; // [rsp+58h] [rbp-68h]
  UFG::qMatrix44 *v74[2]; // [rsp+60h] [rbp-60h]
  UFG::qVector3 p1; // [rsp+70h] [rbp-50h]
  UFG::qVector3 vmin; // [rsp+80h] [rbp-40h]
  UFG::qVector3 aabb_min; // [rsp+90h] [rbp-30h]
  UFG::qVector3 vmax; // [rsp+A0h] [rbp-20h]
  UFG::qMatrix44 xform; // [rsp+B0h] [rbp-10h]
  __m128 v80; // [rsp+F0h] [rbp+30h]
  __int64 v81; // [rsp+100h] [rbp+40h]
  UFG::qMatrix44 dest; // [rsp+110h] [rbp+50h]
  UFG::qMatrix44 result; // [rsp+150h] [rbp+90h]
  UFG::ParkourHandle *v84; // [rsp+280h] [rbp+1C0h]
  UFG::SensorComponent *sensor_component; // [rsp+290h] [rbp+1D0h]
  UFG::qVector2 v1; // [rsp+298h] [rbp+1D8h]

  v81 = -2i64;
  v2 = this;
  v3 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v4 = v2->mIgnoreDockingTimer - deltaTime;
  v2->mIgnoreDockingTimer = v4;
  if ( v4 <= 0.0 )
    v4 = 0.0;
  v2->mIgnoreDockingTimer = v4;
  if ( !v2->mDocked )
  {
    if ( v4 > 0.0 )
      return;
    v7 = v2->mDriverComponent.m_pSimComponent && LOBYTE(v2->mDriverComponent.m_pSimComponent[4].m_TypeUID) ? 1 : 0;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH((UFG::PhysicsMoverInterface *)&v2->vfptr)) & _xmm) >= UFG::BoatPhysicsMoverComponent::msDockSnapToSpeedThreshold
      && !v7 )
    {
      return;
    }
    v8 = v2->m_pSimObject;
    if ( !v8 )
      return;
    v9 = v8->m_Components.p;
    v10 = (UFG::SensorComponent *)v9[26].m_pComponent;
    sensor_component = v10;
    if ( !v10 )
      return;
    v11 = 0i64;
    v12 = 0i64;
    if ( v8 )
      v12 = v9[2].m_pComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
    v13 = (float *)&v12[2].m_SafePointerList.mNode.mNext;
    LODWORD(v14) = v12[2].m_TypeUID ^ _xmm[0];
    v15 = HIDWORD(v12[2].m_SafePointerList.mNode.mNext) ^ _xmm[0];
    v16 = LODWORD(v12[2].m_SafePointerList.mNode.mNext) ^ _xmm[0];
    LODWORD(contactPosition) = LODWORD(v12[2].m_SafePointerList.mNode.mNext) ^ _xmm[0];
    HIDWORD(contactPosition) = v15;
    v73 = v14;
    v84 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
    v74[0] = (UFG::qMatrix44 *)&v12[2];
    v17 = (float)(Twk_DockBoatCenterOffset * *(float *)&v12[2].m_SafePointerList.mNode.mPrev)
        + *(float *)&v12[2].m_BoundComponentHandles.mNode.mNext;
    v18 = (float)(Twk_DockBoatCenterOffset * *((float *)&v12[2].vfptr + 1))
        + *((float *)&v12[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v19 = (float)(Twk_DockBoatCenterOffset * *(float *)&v12[2].vfptr)
        + *(float *)&v12[2].m_BoundComponentHandles.mNode.mPrev;
    *(float *)v74 = (float)(Twk_DockBoatCenterOffset * *(float *)&v12[2].vfptr)
                  + *(float *)&v12[2].m_BoundComponentHandles.mNode.mPrev;
    *((float *)v74 + 1) = v18;
    *(float *)&v74[1] = v17;
    if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
    {
      v20 = (float)(*(float *)&v12[2].m_TypeUID * 2.0) + v17;
      v21 = (float)(*((float *)&v12[2].m_SafePointerList.mNode.mNext + 1) * 2.0) + v18;
      p1.x = (float)(*v13 * 2.0) + v19;
      p1.y = v21;
      p1.z = v20;
      Render::DebugDrawContext::DrawLine(
        v3,
        (UFG::qVector3 *)v74,
        &p1,
        &UFG::qColour::Yellow,
        &UFG::qMatrix44::msIdentity,
        0i64,
        0);
      p1.x = (float)(*(float *)&v16 * 2.0) + *(float *)v74;
      p1.y = *((float *)v74 + 1) + (float)(*(float *)&v15 * 2.0);
      p1.z = *(float *)&v74[1] + (float)(v14 * 2.0);
      Render::DebugDrawContext::DrawLine(
        v3,
        (UFG::qVector3 *)v74,
        &p1,
        &UFG::qColour::Red,
        &UFG::qMatrix44::msIdentity,
        0i64,
        0);
    }
    v22 = v2->mBoundingBoxMin.y;
    v23 = v2->mBoundingBoxMin.z;
    aabb_min.x = v2->mBoundingBoxMin.x;
    aabb_min.y = v22;
    aabb_min.z = v23;
    v24 = v2->mBoundingBoxMax.y;
    v25 = v2->mBoundingBoxMax.z;
    p1.x = v2->mBoundingBoxMax.x;
    p1.y = v24;
    p1.z = v25;
    v26 = v24 - v22;
    v27 = v26 * 3.0;
    UFG::SensorComponent::GetExtents(v10, &vmin, &vmax);
    LODWORD(v28) = COERCE_UNSIGNED_INT(vmax.x - vmin.x) & _xmm;
    if ( v28 >= COERCE_FLOAT(COERCE_UNSIGNED_INT(vmax.y - vmin.y) & _xmm) )
      LODWORD(v28) = COERCE_UNSIGNED_INT(vmax.y - vmin.y) & _xmm;
    if ( v28 < v27 )
      v27 = v28;
    v29 = UFG::BoatPhysicsMoverComponent::FindClosestParkourHandle(
            v2,
            v10,
            (UFG::qVector3 *)v74,
            (UFG::qVector3 *)&v12[2].m_SafePointerList.mNode.mNext,
            0.78539819,
            0.0,
            v27,
            -0.5,
            3.0,
            2u,
            0i64);
    v30 = v29;
    if ( v29 )
    {
      if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
      {
        UFG::ParkourHandle::GetPosition(v29, (UFG::qVector3 *)&distanceZMax);
        Render::DebugDrawContext::DrawLine(
          v3,
          (UFG::qVector3 *)v74,
          (UFG::qVector3 *)&distanceZMax,
          &UFG::qColour::Cyan,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        *(_QWORD *)&p1.x = distanceZMax;
        p1.z = *(float *)&check + 3.0;
        Render::DebugDrawContext::DrawCylinder(
          v3,
          (UFG::qVector3 *)&distanceZMax,
          &p1,
          0.2,
          &UFG::qColour::Cyan,
          &UFG::qMatrix44::msIdentity,
          0i64);
      }
      v31 = UFG::ParkourHandle::GetDistanceTo(v30, (UFG::qVector3 *)v74);
      v32 = FLOAT_3_4028235e38;
      if ( v31 < 3.4028235e38 && (v31 < UFG::BoatPhysicsMoverComponent::msDockSnapToDistanceThreshold || v7) )
      {
        v32 = v31;
        v84 = v30;
        v33 = *v13;
        v34 = *((float *)&v12[2].m_SafePointerList.mNode.mNext + 1);
        goto LABEL_38;
      }
    }
    else
    {
      v32 = FLOAT_3_4028235e38;
    }
    v34 = vmin.y;
    v33 = vmin.x;
LABEL_38:
    v35 = sensor_component;
    v36 = UFG::BoatPhysicsMoverComponent::FindClosestParkourHandle(
            v2,
            sensor_component,
            (UFG::qVector3 *)v74,
            (UFG::qVector3 *)&contactPosition,
            0.78539819,
            0.0,
            v27,
            -0.5,
            3.0,
            2u,
            0i64);
    v37 = v36;
    if ( !v36 )
      goto LABEL_79;
    if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
    {
      UFG::ParkourHandle::GetPosition(v36, (UFG::qVector3 *)&distanceZMax);
      Render::DebugDrawContext::DrawLine(
        v3,
        (UFG::qVector3 *)v74,
        (UFG::qVector3 *)&distanceZMax,
        &UFG::qColour::Magenta,
        &UFG::qMatrix44::msIdentity,
        0i64,
        0);
      *(_QWORD *)&p1.x = distanceZMax;
      p1.z = *(float *)&check + 3.0;
      Render::DebugDrawContext::DrawCylinder(
        v3,
        (UFG::qVector3 *)&distanceZMax,
        &p1,
        0.2,
        &UFG::qColour::Magenta,
        &UFG::qMatrix44::msIdentity,
        0i64);
    }
    v38 = UFG::ParkourHandle::GetDistanceTo(v37, (UFG::qVector3 *)v74);
    if ( v38 < v32 && (v38 < UFG::BoatPhysicsMoverComponent::msDockSnapToDistanceThreshold || v7) )
    {
      v33 = *(float *)&v16;
      v34 = *(float *)&v15;
    }
    else
    {
LABEL_79:
      v37 = v84;
    }
    if ( v37 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
      LODWORD(v84) = v12[2].m_BoundComponentHandles.mNode.mNext;
      if ( UFG::ParkourHandle::GetNormal(v37, &p1) )
      {
        v1.x = p1.x;
        v1.y = p1.y;
        LODWORD(sensor_component) = LODWORD(v33) ^ _xmm[0];
        HIDWORD(sensor_component) = LODWORD(v34) ^ _xmm[0];
        v39 = UFG::qAngleBetween(&v1, (UFG::qVector2 *)&sensor_component);
        if ( v39 > 3.1415927 )
          v39 = v39 + -3.1415927;
        UFG::qRotationMatrixAxis(&dest, &UFG::qVector3::msDirUp, v39);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
        v40 = v74[0];
        v41 = UFG::qMatrix44::operator*(v74[0], &result, &dest);
        v42 = v41->v1;
        v43 = v41->v2;
        v44 = v41->v3;
        xform.v0 = v41->v0;
        xform.v1 = v42;
        xform.v2 = v43;
        xform.v3 = v44;
        if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
        {
          Render::DebugDrawContext::DrawAABB(v3, &aabb_min, &p1, &UFG::qColour::Cyan, &xform, 0i64);
          Render::DebugDrawContext::DrawAxes(v3, &xform, 1.0, 0, 0i64);
        }
        UFG::ParkourHandle::GetClosestPointOnHandle(v37, (UFG::qVector3 *)&distanceZMax, (UFG::qVector3 *)v74);
        v45 = (__m128)LODWORD(v74[1]);
        v46 = (__m128)HIDWORD(v74[0]);
        v47 = (__m128)LODWORD(v74[0]);
        v48 = (__m128)(unsigned int)distanceZMax;
        v49 = (__m128)LODWORD(p1.y);
        v49.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(p1.x * p1.x))
                        + (float)(p1.z * p1.z);
        LODWORD(v50) = (unsigned __int128)_mm_sqrt_ps(v49);
        v51 = (float)((float)((float)(*(float *)v74 - *(float *)&distanceZMax) * p1.x)
                    + (float)(p1.y * (float)(*((float *)v74 + 1) - *((float *)&distanceZMax + 1))))
            + (float)(p1.z * (float)(*(float *)&v74[1] - *(float *)&check));
        LODWORD(v52) = (unsigned __int128)_mm_sqrt_ps(v49);
        v53 = (__m128)(unsigned int)FLOAT_1_0;
        v53.m128_f32[0] = 1.0 / v50;
        v54 = (float)(1.0 / v50) * (float)((float)(p1.z * (float)(1.0 / v52)) * v51);
        v55 = v53;
        v55.m128_f32[0] = (float)(1.0 / v50) * (float)((float)(p1.y * (float)(1.0 / v52)) * v51);
        v56 = (float)(1.0 / v50) * (float)((float)(p1.x * (float)(1.0 / v52)) * v51);
        v57 = v55;
        v57.m128_f32[0] = (float)((float)(v55.m128_f32[0] * v55.m128_f32[0]) + (float)(v56 * v56)) + (float)(v54 * v54);
        if ( v57.m128_f32[0] == 0.0 )
          v58 = 0.0;
        else
          v58 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v57));
        v59 = (float)(v26 * 0.5) + UFG::BoatPhysicsMoverComponent::msDockSnapToDistanceFromDock;
        v60 = (float)(v55.m128_f32[0] * v58) * v59;
        v48.m128_f32[0] = *(float *)&distanceZMax + (float)((float)(v56 * v58) * v59);
        *(float *)&contactPosition = *(float *)&distanceZMax + (float)((float)(v56 * v58) * v59);
        *((float *)&contactPosition + 1) = *((float *)&distanceZMax + 1) + v60;
        v73 = *(float *)&v84;
        xform.v3.x = *(float *)&distanceZMax + (float)((float)(v56 * v58) * v59);
        xform.v3.y = *((float *)&distanceZMax + 1) + v60;
        LODWORD(xform.v3.z) = (_DWORD)v84;
        xform.v3.w = 1.0;
        if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
        {
          *(float *)&v74[1] = *(float *)&v74[1] + 3.0;
          Render::DebugDrawContext::DrawCylinder(
            v3,
            (UFG::qVector3 *)v74,
            (UFG::qVector3 *)v74,
            0.2,
            &UFG::qColour::Green,
            &UFG::qMatrix44::msIdentity,
            0i64);
          v74[0] = (UFG::qMatrix44 *)contactPosition;
          *(float *)&v74[1] = v73 + 2.8;
          Render::DebugDrawContext::DrawCylinder(
            v3,
            (UFG::qVector3 *)&contactPosition,
            (UFG::qVector3 *)v74,
            0.25,
            &UFG::qColour::Yellow,
            &UFG::qMatrix44::msIdentity,
            0i64);
          Render::DebugDrawContext::DrawLine(
            v3,
            (UFG::qVector3 *)v74,
            (UFG::qVector3 *)&contactPosition,
            &UFG::qColour::Green,
            &UFG::qMatrix44::msIdentity,
            0i64,
            0);
          v74[0] = distanceZMax;
          *(float *)&v74[1] = *(float *)&check + 2.5999999;
          Render::DebugDrawContext::DrawCylinder(
            v3,
            (UFG::qVector3 *)&distanceZMax,
            (UFG::qVector3 *)v74,
            0.30000001,
            &UFG::qColour::Blue,
            &UFG::qMatrix44::msIdentity,
            0i64);
          if ( UFG::BoatPhysicsMoverComponent::msDebugBoatSnapTo )
          {
            Render::DebugDrawContext::DrawAABB(v3, &aabb_min, &p1, &UFG::qColour::Orange, &xform, 0i64);
            Render::DebugDrawContext::DrawAxes(v3, &xform, 1.0, 0, 0i64);
          }
          v48 = (__m128)(unsigned int)contactPosition;
          v47 = (__m128)LODWORD(v74[0]);
          v46 = (__m128)HIDWORD(v74[0]);
          v45 = (__m128)LODWORD(v74[1]);
        }
        if ( Twk_DockingEnabled )
        {
          if ( Twk_SlideToDockedLocation )
          {
            v61 = v2->mPhysicsVehicle;
            if ( v61 )
            {
              v62 = (__m128)LODWORD(v73);
              v62.m128_f32[0] = v73 - v45.m128_f32[0];
              v63 = (__m128)HIDWORD(contactPosition);
              v63.m128_f32[0] = *((float *)&contactPosition + 1) - v46.m128_f32[0];
              v48.m128_f32[0] = v48.m128_f32[0] - v47.m128_f32[0];
              if ( (float)((float)((float)(v48.m128_f32[0] * v48.m128_f32[0])
                                 + (float)(v63.m128_f32[0] * v63.m128_f32[0]))
                         + (float)(v62.m128_f32[0] * v62.m128_f32[0])) >= Twk_SlideToDockDistToDestThresholdSq )
              {
                v62.m128_f32[0] = v62.m128_f32[0] * Twk_SlideToSpringConstant;
                v63.m128_f32[0] = v63.m128_f32[0] * Twk_SlideToSpringConstant;
                v48.m128_f32[0] = v48.m128_f32[0] * Twk_SlideToSpringConstant;
                v80 = _mm_unpacklo_ps(_mm_unpacklo_ps(v48, v62), _mm_unpacklo_ps(v63, (__m128)0i64));
                v66 = (hkpEntity *)&v61->mRigidBody->mBody->vfptr;
                *(__m128 *)v74 = _mm_unpacklo_ps(_mm_unpacklo_ps(v47, v45), _mm_unpacklo_ps(v46, (__m128)0i64));
                hkpEntity::activate(v66);
                ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, UFG::qMatrix44 **))v66->m_motion.vfptr[12].__first_virtual_table_function__)(
                  &v66->m_motion,
                  v67,
                  &v80,
                  v74);
              }
              else
              {
                v64 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
                v84 = (UFG::ParkourHandle *)v64;
                if ( v64 )
                  UFG::TeleportEvent::TeleportEvent(
                    (UFG::TeleportEvent *)v64,
                    v40,
                    v2->m_pSimObject->mNode.mUID,
                    0,
                    UFG::TeleportEvent::m_Name,
                    0);
                else
                  v65 = 0i64;
                UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v65);
                v2->mDocked = 1;
                v2->mIgnoreDockingTimer = 2.0;
                if ( v7 && v2->mDriverComponent.m_pSimComponent )
                  LOBYTE(v2->mDriverComponent.m_pSimComponent[4].m_TypeUID) = 0;
              }
            }
          }
          if ( Twk_TeleportToDockedLocation )
          {
            v68 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
            v84 = (UFG::ParkourHandle *)v68;
            if ( v68 )
            {
              UFG::TeleportEvent::TeleportEvent(
                (UFG::TeleportEvent *)v68,
                &xform,
                v2->m_pSimObject->mNode.mUID,
                0,
                UFG::TeleportEvent::m_Name,
                0);
              v11 = v69;
            }
            UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v11);
            v2->mDocked = 1;
            v2->mIgnoreDockingTimer = 2.0;
            if ( v7 && v2->mDriverComponent.m_pSimComponent )
              LOBYTE(v2->mDriverComponent.m_pSimComponent[4].m_TypeUID) = 0;
          }
        }
      }
    }
    UFG::SensorComponent::CollectParkourHandles(v35, 6.0);
    return;
  }
  if ( v2->mDriverComponent.m_pSimComponent
    && ((unsigned __int8 (*)(void))v2->mDriverComponent.m_pSimComponent->vfptr[14].__vecDelDtor)() )
  {
    v5 = (UFG::AiDriverComponent *)v2->mDriverComponent.m_pSimComponent;
    if ( v5 )
    {
      v2->vfptr[14].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v2->vfptr, 2u);
      UFG::AiDriverComponent::SetGasBrakeLock(v5, 0.0);
      *((_DWORD *)&v2->mInput + 4) &= 0xFFFFFFDF;
      *((_DWORD *)&v2->mInput + 4) |= 4u;
      if ( v5->m_fDesiredSpeed > 0.0 )
      {
        UFG::AiDriverComponent::ClearGasBrakeLock(v5);
LABEL_11:
        v2->mDocked = 0;
        v2->mIgnoreDockingTimer = 2.0;
        return;
      }
    }
  }
  else
  {
    v6 = v2->mInput.mGasBrakes;
    if ( v6 >= 0.5 || v6 <= -0.5 )
      goto LABEL_11;
  }
}

// File Line: 553
// RVA: 0x678600
UFG::ParkourHandle *__fastcall UFG::BoatPhysicsMoverComponent::FindClosestParkourHandle(UFG::BoatPhysicsMoverComponent *this, UFG::SensorComponent *sensor_component, UFG::qVector3 *position, UFG::qVector3 *orientationVector, const float relativeAngle, const float distanceXYMin, const float distanceXYMax, const float distanceZMin, const float distanceZMax, unsigned int check, UFG::qVector3 *contactPosition)
{
  int *v11; // rsi
  UFG::qVector3 *v12; // r14
  UFG::SensorComponent *v13; // rbx
  UFG::BoatPhysicsMoverComponent *v14; // rbp
  __int64 v15; // rdi
  UFG::qVector3 *v16; // r15
  unsigned int v17; // er12
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm9_4
  float v22; // xmm10_4
  UFG::ParkourHandle *v23; // rbx
  int v24; // xmm1_4
  int v25; // xmm2_4
  float v27; // [rsp+70h] [rbp-48E8h]
  __int64 v28; // [rsp+78h] [rbp-48E0h]
  int v29; // [rsp+80h] [rbp-48D8h]
  int v30; // [rsp+84h] [rbp-48D4h]
  int v31; // [rsp+88h] [rbp-48D0h]
  __int64 v32; // [rsp+90h] [rbp-48C8h]
  UFG::qVector3 vmax; // [rsp+98h] [rbp-48C0h]
  UFG::qVector3 vmin; // [rsp+A8h] [rbp-48B0h]
  UFG::qFixedArray<UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle>,768> out; // [rsp+C0h] [rbp-4898h]
  char v36; // [rsp+4968h] [rbp+10h]

  v32 = -2i64;
  v11 = (int *)orientationVector;
  v12 = position;
  v13 = sensor_component;
  v14 = this;
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
  UFG::SensorComponent::GetParkourHandles(v13, &out);
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
      v36 = 0;
      v23 = (UFG::ParkourHandle *)*((_QWORD *)&out.p[0].m_pPointer + 3 * v15);
      if ( v23
        && v23->mSimObject.m_pPointer != v14->m_pSimObject
        && UFG::ParkourHandle::IsEnabled(*(&out.p[0].m_pPointer + 3 * v15)) )
      {
        v24 = v11[1];
        v25 = v11[2];
        v29 = *v11;
        v30 = v24;
        v31 = v25;
        UFG::ParkourHandle::CompareParkourHandles(
          v23,
          v17,
          v12,
          (UFG::qVector3 *)&v29,
          v22,
          0.0,
          v21,
          v20,
          v19,
          v18,
          v16,
          (UFG::ParkourHandle **)&v28,
          &v27,
          (bool *)&v36);
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
  return (UFG::ParkourHandle *)v28;
}

