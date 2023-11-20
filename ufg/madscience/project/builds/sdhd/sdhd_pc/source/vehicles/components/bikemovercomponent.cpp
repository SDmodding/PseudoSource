// File Line: 59
// RVA: 0x157B730
__int64 dynamic_initializer_for__UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList__);
}

// File Line: 60
// RVA: 0x67B3F0
const char *__fastcall UFG::BikePhysicsMoverComponent::GetTypeName(UFG::BikePhysicsMoverComponent *this)
{
  return "BikePhysicsMoverComponent";
}

// File Line: 66
// RVA: 0x666EA0
void __fastcall UFG::BikePhysicsMoverComponent::BikePhysicsMoverComponent(UFG::BikePhysicsMoverComponent *this, UFG::SceneObjectProperties *pSceneObj, component_BikePhysicsMover *dataPtr)
{
  UFG::BikePhysicsMoverComponent *v3; // rbx
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *v4; // rdx
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *v5; // rax

  v3 = this;
  UFG::PhysicsMoverInterface::PhysicsMoverInterface(
    (UFG::PhysicsMoverInterface *)&this->vfptr,
    2,
    pSceneObj,
    (component_PhysicsMover *)&dataPtr->physicsPropertySetAI);
  v4 = (UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BikePhysicsMoverComponent::`vftable{for `UFG::SimComponent};
  v3->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BikePhysicsMoverComponent::`vftable{for `UFG::UpdateInterface};
  v5 = UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList.mNode.mPrev;
  UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *)&UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList;
  UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList.mNode.mPrev = (UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::BikePhysicsMoverComponent::_BikePhysicsMoverComponentTypeUID,
    "BikePhysicsMoverComponent");
}

// File Line: 74
// RVA: 0x66C0E0
void __fastcall UFG::BikePhysicsMoverComponent::~BikePhysicsMoverComponent(UFG::BikePhysicsMoverComponent *this)
{
  UFG::BikePhysicsMoverComponent *v1; // r8
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *v2; // rdx
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *v3; // rcx
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *v4; // rax
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *v5; // rcx
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BikePhysicsMoverComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BikePhysicsMoverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentpCurrentIterator )
    UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentpCurrentIterator = (UFG::BikePhysicsMoverComponent *)&this->mPrev[-58].mNext;
  v2 = (UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *)&this->mPrev;
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

// File Line: 79
// RVA: 0x687E50
UFG::SimComponent *__fastcall UFG::BikePhysicsMoverComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
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
         (UFG::qSymbol *)&component_BikePhysicsMover::sPropertyName.mUID,
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
  v10 = UFG::qMemoryPool::Allocate(v9, 0x3A8ui64, "BikePhysicsMoverComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::BikePhysicsMoverComponent::BikePhysicsMoverComponent(
      (UFG::BikePhysicsMoverComponent *)v10,
      v3,
      (component_BikePhysicsMover *)v7);
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

// File Line: 97
// RVA: 0x674D80
void __fastcall UFG::BikePhysicsMoverComponent::CreateVehicle(UFG::BikePhysicsMoverComponent *this, UFG::qMatrix44 *transform, UFG::qVector3 *velocity)
{
  UFG::qVector3 *v3; // r13
  UFG::qMatrix44 *v4; // r12
  UFG::BikePhysicsMoverComponent *v5; // rbx
  UFG::SimObject *v6; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::PhysicsVehicle *v12; // r15
  UFG::SimObjectCVBase *v13; // rcx
  UFG::CharacterAnimationComponent *v14; // rax
  Creature *v15; // rcx
  SkeletalPose *v16; // rsi
  int v17; // ebp
  float *v18; // rdi
  int *v19; // r14
  hkQsTransformf *v20; // rax
  float v21; // xmm1_4
  float v22; // xmm2_4
  __int64 v23; // rcx
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float *v27; // rax
  UFG::PhysicsMotorBike *v28; // rdi
  unsigned int v29; // eax
  UFG::PhysicsVehicle *v30; // rax
  UFG::SimComponent *v31; // rdi
  UFG::qVector3 wheelPositions; // [rsp+38h] [rbp-40h]

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
  v5->mParameters.firstRearWheel = 1;
  v5->mParameters.lastRearWheel = 1;
  v13 = (UFG::SimObjectCVBase *)v5->m_pSimObject;
  if ( v13 )
    v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v13);
  else
    v14 = 0i64;
  v15 = v14->mCreature;
  if ( v15 )
  {
    v16 = SkeletalPose::Clone(&v15->mPose);
    SkeletalPose::SetToRestPose(v16);
    v17 = 0;
    if ( v5->mNumWheels > 0 )
    {
      v18 = &wheelPositions.z;
      v19 = v5->mWheelBoneId.array;
      do
      {
        v20 = SkeletalPose::GetTranslationMS(v16, *v19);
        v21 = v20->m_translation.m_quad.m128_f32[1];
        v22 = v20->m_translation.m_quad.m128_f32[2];
        *(v18 - 2) = v20->m_translation.m_quad.m128_f32[0];
        *(v18 - 1) = v21;
        *v18 = v22;
        ++v17;
        ++v19;
        v18 += 3;
      }
      while ( v17 < v5->mNumWheels );
    }
    if ( v16 )
    {
      SkeletalPose::~SkeletalPose(v16);
      operator delete[](v16);
    }
  }
  else
  {
    v23 = (unsigned int)v5->mNumWheels;
    if ( (signed int)v23 > 0 )
    {
      v24 = v4->v3.x;
      v25 = v4->v3.y;
      v26 = v4->v3.z;
      v27 = &wheelPositions.z;
      do
      {
        *(v27 - 2) = v24;
        *(v27 - 1) = v25;
        *v27 = v26;
        v27 += 3;
        --v23;
      }
      while ( v23 );
    }
  }
  v28 = (UFG::PhysicsMotorBike *)UFG::PhysicsVehicle::mAllocator.mFreeListHead;
  if ( UFG::PhysicsVehicle::mAllocator.mFreeListHead )
  {
    UFG::PhysicsVehicle::mAllocator.mFreeListHead = *(char **)UFG::PhysicsVehicle::mAllocator.mFreeListHead;
    v29 = UFG::PhysicsVehicle::mAllocator.mNumSlotsAllocated + 1;
    UFG::PhysicsVehicle::mAllocator.mNumSlotsAllocated = v29;
    if ( UFG::PhysicsVehicle::mAllocator.mMostSlotsAllocated <= v29 )
      UFG::PhysicsVehicle::mAllocator.mMostSlotsAllocated = v29;
  }
  else
  {
    v28 = (UFG::PhysicsMotorBike *)UFG::qMemoryPool::Allocate(
                                     &gPhysicsMemoryPool,
                                     0x4E0ui64,
                                     "PhysicsMotorBike",
                                     0i64,
                                     1u);
  }
  if ( v28 )
  {
    UFG::PhysicsMotorBike::PhysicsMotorBike(v28, &v5->mParameters, v4, v3, &wheelPositions);
    v12 = v30;
  }
  v5->mPhysicsVehicle = v12;
  v12->vfptr[3].__vecDelDtor((UFG::BasePhysicsObject *)&v12->vfptr, (unsigned int)v5);
  v31 = UFG::AquireWaterFloatingTrackerComponent(v5->m_pSimObject, v5->mPhysicsVehicle->mRigidBody->mBody);
  if ( UFG::SimComponent::IsType(v31, UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID) )
  {
    v5->mPhysicsVehicle->mWaterFloatingTrackerComponent = (UFG::WaterFloatingTrackerComponent *)v31;
    ((void (__cdecl *)(UFG::WaterFloatingTrackerComponent *))v5->mPhysicsVehicle->mWaterFloatingTrackerComponent->vfptr[14].__vecDelDtor)(v5->mPhysicsVehicle->mWaterFloatingTrackerComponent);
  }
}

// File Line: 148
// RVA: 0x6826F0
void __fastcall UFG::BikePhysicsMoverComponent::OnAttach(UFG::BikePhysicsMoverComponent *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rbx
  UFG::BikePhysicsMoverComponent *v3; // rdi
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  UFG::SimObjectCVBase *v9; // rcx
  UFG::CharacterAnimationComponent *v10; // rax
  Creature *v11; // rbx
  signed int v12; // esi
  signed int v13; // eax
  signed int v14; // eax
  signed int v15; // eax
  hkSeekableStreamReader *v16; // [rsp+38h] [rbp-20h]
  void (__usercall *v17)(UFG::PhysicsMoverInterface *@<rcx>, UFG::Event *@<rdx>, float@<xmm0>); // [rsp+40h] [rbp-18h]

  v2 = object;
  v3 = this;
  v4 = _S29_1;
  if ( !(_S29_1 & 1) )
  {
    _S29_1 |= 1u;
    v5 = UFG::qStringHashUpper32("M_Wheel01", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symM_Wheel01, v5);
    atexit(UFG::BikePhysicsMoverComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symM_Wheel01__);
    v4 = _S29_1;
  }
  if ( !(v4 & 2) )
  {
    _S29_1 = v4 | 2;
    v6 = UFG::qStringHashUpper32("M_Wheel02", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symM_Wheel02, v6);
    atexit(UFG::BikePhysicsMoverComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symM_Wheel02__);
    v4 = _S29_1;
  }
  if ( !(v4 & 4) )
  {
    _S29_1 = v4 | 4;
    v7 = UFG::qStringHashUpper32("M_Axle01", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symM_Axle01, v7);
    atexit(UFG::BikePhysicsMoverComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symM_Axle01__);
    v4 = _S29_1;
  }
  if ( !(v4 & 8) )
  {
    _S29_1 = v4 | 8;
    v8 = UFG::qStringHashUpper32("M_Axle02", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symM_Axle02, v8);
    atexit(UFG::BikePhysicsMoverComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symM_Axle02__);
  }
  UFG::PhysicsMoverInterface::OnAttach((UFG::PhysicsMoverInterface *)&v3->vfptr, v2);
  v9 = (UFG::SimObjectCVBase *)v3->m_pSimObject;
  if ( v9 )
    v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
  else
    v10 = 0i64;
  v11 = v10->mCreature;
  if ( v11 )
  {
    v12 = -1;
    if ( v11->mPose.mRigHandle.mData )
      v13 = Skeleton::GetBoneID(v11->mPose.mRigHandle.mUFGSkeleton, symM_Wheel01.mUID);
    else
      v13 = -1;
    v3->mWheelBoneId.array[0] = v13;
    if ( v11->mPose.mRigHandle.mData )
      v14 = Skeleton::GetBoneID(v11->mPose.mRigHandle.mUFGSkeleton, symM_Wheel02.mUID);
    else
      v14 = -1;
    v3->mWheelBoneId.array[1] = v14;
    if ( v11->mPose.mRigHandle.mData )
      v15 = Skeleton::GetBoneID(v11->mPose.mRigHandle.mUFGSkeleton, symM_Axle01.mUID);
    else
      v15 = -1;
    v3->mAxleBoneId.array[0] = v15;
    if ( v11->mPose.mRigHandle.mData )
      v12 = Skeleton::GetBoneID(v11->mPose.mRigHandle.mUFGSkeleton, symM_Axle02.mUID);
    v3->mAxleBoneId.array[1] = v12;
  }
  v17 = UFG::PhysicsMoverInterface::TargetSphereEventHandler;
  v16 = Assembly::GetRCX(v3);
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v16,
    UFG::gBulletImpactDamageSphereEventChannel.mUID,
    UFG::gBulletImpactDamageSphereEventChannel.mName,
    0);
}

// File Line: 181
// RVA: 0x684120
void __fastcall UFG::BikePhysicsMoverComponent::OnDetach(UFG::CarPhysicsMoverComponent *this)
{
  UFG::CarPhysicsMoverComponent *v1; // rbx
  hkSeekableStreamReader *v2; // [rsp+20h] [rbp-18h]
  void (__usercall *v3)(UFG::PhysicsMoverInterface *@<rcx>, UFG::Event *@<rdx>, float@<xmm0>); // [rsp+28h] [rbp-10h]

  v1 = this;
  v3 = UFG::PhysicsMoverInterface::TargetSphereEventHandler;
  v2 = Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
    UFG::gBulletImpactDamageSphereEventChannel.mUID);
  UFG::PhysicsMoverInterface::OnDetach((UFG::PhysicsMoverInterface *)&v1->vfptr);
}

// File Line: 191
// RVA: 0x68F590
void __fastcall UFG::BikePhysicsMoverComponent::Update(UFG::BikePhysicsMoverComponent *this, float deltaTime)
{
  UFG::BikePhysicsMoverComponent *v2; // rdi
  UFG::PhysicsMotorBike *v3; // rbx

  v2 = this;
  UFG::PhysicsMoverInterface::Update((UFG::PhysicsMoverInterface *)&this->vfptr, deltaTime);
  v3 = (UFG::PhysicsMotorBike *)v2->mParameters.mSimObject.m_pPointer;
  if ( v2->mPrev )
  {
    if ( v3
      && ((unsigned __int8)UFG::PhysicsMotorBike::DidStabilizationJustSwitchOff((UFG::PhysicsMotorBike *)v2->mParameters.mSimObject.m_pPointer)
       || (unsigned __int8)UFG::PhysicsMotorBike::IsStabilizationDisabled(v3)) )
    {
      UFG::VehicleDriverInterface::EjectDriver((UFG::VehicleDriverInterface *)v2->mPrev);
    }
    if ( *(float *)&v2->mDriverComponent.mPrev >= 1.0 )
    {
      if ( v3 )
        UFG::PhysicsMotorBike::DumpBike(v3);
      UFG::VehicleDriverInterface::EjectDriver((UFG::VehicleDriverInterface *)v2->mPrev);
    }
  }
}

// File Line: 214
// RVA: 0x681D50
void __fastcall UFG::BikePhysicsMoverComponent::Mount(UFG::BikePhysicsMoverComponent *this)
{
  JUMPOUT(this->mPhysicsVehicle, 0i64, UFG::PhysicsMotorBike::ResetStabilization);
}

// File Line: 225
// RVA: 0x676A40
void __fastcall UFG::BikePhysicsMoverComponent::Dismount(UFG::BikePhysicsMoverComponent *this)
{
  UFG::PhysicsWheeledVehicle *v1; // rbx
  UFG::BikePhysicsMoverComponent *v2; // rdi
  UFG::PhysicsVehicle *v3; // rax
  UFG::qVector3 pos; // [rsp+20h] [rbp-68h]
  UFG::qVector3 impulse; // [rsp+30h] [rbp-58h]
  UFG::qMatrix44 mat; // [rsp+40h] [rbp-48h]

  v1 = (UFG::PhysicsWheeledVehicle *)this->mPhysicsVehicle;
  v2 = this;
  if ( v1 )
  {
    UFG::PhysicsMotorBike::DumpBike((UFG::PhysicsMotorBike *)this->mPhysicsVehicle);
    UFG::PhysicsWheeledVehicle::SetWheelFrictionMultiplier(v1, 1, 0.0);
    UFG::PhysicsWheeledVehicle::SetWheelFrictionMultiplier(v1, 0, 0.0);
    v3 = v2->mPhysicsVehicle;
    if ( v3 )
    {
      if ( v3->mCurrentLod == LOD_SETTING_EXTREME )
      {
        UFG::PhysicsWheeledVehicle::GetWheelMatrix(v1, 1, &mat);
        impulse.z = mat.v1.z * 500.0;
        pos = *(UFG::qVector3 *)&mat.v3.x;
        impulse.x = mat.v1.x * 500.0;
        impulse.y = mat.v1.y * 500.0;
        UFG::PhysicsVehicle::ApplyImpulse((UFG::PhysicsVehicle *)&v1->vfptr, &impulse, &pos);
      }
    }
  }
}

// File Line: 247
// RVA: 0x67AFC0
UFG::PhysicsVehicle *__fastcall UFG::BikePhysicsMoverComponent::GetPhysicsBike(UFG::BikePhysicsMoverComponent *this)
{
  return this->mPhysicsVehicle;
}

