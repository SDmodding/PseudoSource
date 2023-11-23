// File Line: 59
// RVA: 0x157B730
__int64 dynamic_initializer_for__UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList__);
}

// File Line: 60
// RVA: 0x67B3F0
const char *__fastcall UFG::BikePhysicsMoverComponent::GetTypeName(UFG::BikePhysicsMoverComponent *this)
{
  return "BikePhysicsMoverComponent";
}

// File Line: 66
// RVA: 0x666EA0
void __fastcall UFG::BikePhysicsMoverComponent::BikePhysicsMoverComponent(
        UFG::BikePhysicsMoverComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        component_BikePhysicsMover *dataPtr)
{
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *mPrev; // rax

  UFG::PhysicsMoverInterface::PhysicsMoverInterface(this, 2, pSceneObj, dataPtr);
  this->UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent>::mPrev = &this->UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent>;
  this->UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent>::mNext = &this->UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent>;
  this->UFG::PhysicsMoverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BikePhysicsMoverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::PhysicsMoverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BikePhysicsMoverComponent::`vftable{for `UFG::UpdateInterface};
  mPrev = UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList.mNode.mPrev;
  UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent>;
  this->UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent>::mNext = (UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *)&UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList;
  UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::BikePhysicsMoverComponent::_BikePhysicsMoverComponentTypeUID,
    "BikePhysicsMoverComponent");
}

// File Line: 74
// RVA: 0x66C0E0
void __fastcall UFG::BikePhysicsMoverComponent::~BikePhysicsMoverComponent(UFG::BikePhysicsMoverComponent *this)
{
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *v2; // rdx
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *mPrev; // rcx
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *mNext; // rax
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *v5; // rcx
  UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent> *v6; // rax

  this->UFG::PhysicsMoverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BikePhysicsMoverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::PhysicsMoverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BikePhysicsMoverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentpCurrentIterator )
    UFG::BikePhysicsMoverComponent::s_BikePhysicsMoverComponentpCurrentIterator = (UFG::BikePhysicsMoverComponent *)&this->UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent>::mPrev[-58].mNext;
  v2 = &this->UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent>;
  mPrev = this->UFG::qNode<UFG::BikePhysicsMoverComponent,UFG::BikePhysicsMoverComponent>::mPrev;
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

// File Line: 79
// RVA: 0x687E50
UFG::SimComponent *__fastcall UFG::BikePhysicsMoverComponent::PropertiesOnActivateNew(
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
         (UFG::qArray<unsigned long,0> *)&component_BikePhysicsMover::sPropertyName,
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
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x3A8ui64, "BikePhysicsMoverComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::BikePhysicsMoverComponent::BikePhysicsMoverComponent(
      (UFG::BikePhysicsMoverComponent *)v10,
      pSceneObj,
      (component_BikePhysicsMover *)MemImagePtr);
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
  return v6;
}

// File Line: 97
// RVA: 0x674D80
void __fastcall UFG::BikePhysicsMoverComponent::CreateVehicle(
        UFG::BikePhysicsMoverComponent *this,
        UFG::qMatrix44 *transform,
        UFG::qVector3 *velocity)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mSimObject; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::PhysicsVehicle *v12; // r15
  UFG::SimObjectCVBase *v13; // rcx
  UFG::CharacterAnimationComponent *v14; // rax
  Creature *mCreature; // rcx
  SkeletalPose *v16; // rsi
  int v17; // ebp
  float *p_z; // rdi
  UFG::qSafeArray<int,4> *p_mWheelBoneId; // r14
  hkQsTransformf *TranslationMS; // rax
  int v21; // xmm1_4
  int v22; // xmm2_4
  __int64 mNumWheels; // rcx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float *v27; // rax
  UFG::PhysicsMotorBike *mFreeListHead; // rdi
  unsigned int v29; // eax
  UFG::PhysicsVehicle *v30; // rax
  UFG::WaterFloatingTrackerComponent *v31; // rdi
  UFG::qVector3 wheelPositions; // [rsp+38h] [rbp-40h] BYREF

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
  this->mParameters.firstRearWheel = 1;
  this->mParameters.lastRearWheel = 1;
  v13 = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( v13 )
    v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v13);
  else
    v14 = 0i64;
  mCreature = v14->mCreature;
  if ( mCreature )
  {
    v16 = SkeletalPose::Clone(&mCreature->mPose);
    SkeletalPose::SetToRestPose(v16);
    v17 = 0;
    if ( this->mNumWheels > 0 )
    {
      p_z = &wheelPositions.z;
      p_mWheelBoneId = &this->mWheelBoneId;
      do
      {
        TranslationMS = SkeletalPose::GetTranslationMS(v16, p_mWheelBoneId->array[0]);
        v21 = TranslationMS->m_translation.m_quad.m128_i32[1];
        v22 = TranslationMS->m_translation.m_quad.m128_i32[2];
        *(p_z - 2) = TranslationMS->m_translation.m_quad.m128_f32[0];
        *((_DWORD *)p_z - 1) = v21;
        *(_DWORD *)p_z = v22;
        ++v17;
        p_mWheelBoneId = (UFG::qSafeArray<int,4> *)((char *)p_mWheelBoneId + 4);
        p_z += 3;
      }
      while ( v17 < this->mNumWheels );
    }
    if ( v16 )
    {
      SkeletalPose::~SkeletalPose(v16);
      operator delete[](v16);
    }
  }
  else
  {
    mNumWheels = (unsigned int)this->mNumWheels;
    if ( (int)mNumWheels > 0 )
    {
      x = transform->v3.x;
      y = transform->v3.y;
      z = transform->v3.z;
      v27 = &wheelPositions.z;
      do
      {
        *(v27 - 2) = x;
        *(v27 - 1) = y;
        *v27 = z;
        v27 += 3;
        --mNumWheels;
      }
      while ( mNumWheels );
    }
  }
  mFreeListHead = (UFG::PhysicsMotorBike *)UFG::PhysicsVehicle::mAllocator.mFreeListHead;
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
    mFreeListHead = (UFG::PhysicsMotorBike *)UFG::qMemoryPool::Allocate(
                                               &gPhysicsMemoryPool,
                                               0x4E0ui64,
                                               "PhysicsMotorBike",
                                               0i64,
                                               1u);
  }
  if ( mFreeListHead )
  {
    UFG::PhysicsMotorBike::PhysicsMotorBike(mFreeListHead, &this->mParameters, transform, velocity, &wheelPositions);
    v12 = v30;
  }
  this->mPhysicsVehicle = v12;
  v12->vfptr[3].__vecDelDtor(v12, (unsigned int)this);
  v31 = (UFG::WaterFloatingTrackerComponent *)UFG::AquireWaterFloatingTrackerComponent(
                                                this->m_pSimObject,
                                                this->mPhysicsVehicle->mRigidBody->mBody);
  if ( UFG::SimComponent::IsType(v31, UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID) )
  {
    this->mPhysicsVehicle->mWaterFloatingTrackerComponent = v31;
    ((void (__fastcall *)(UFG::WaterFloatingTrackerComponent *))this->mPhysicsVehicle->mWaterFloatingTrackerComponent->vfptr[14].__vecDelDtor)(this->mPhysicsVehicle->mWaterFloatingTrackerComponent);
  }
}

// File Line: 148
// RVA: 0x6826F0
void __fastcall UFG::BikePhysicsMoverComponent::OnAttach(UFG::BikePhysicsMoverComponent *this, UFG::SimObject *object)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::CharacterAnimationComponent *v10; // rax
  Creature *mCreature; // rbx
  int v12; // esi
  int BoneID; // eax
  int v14; // eax
  int v15; // eax
  fastdelegate::FastDelegate1<UFG::Event *,void> v16; // [rsp+38h] [rbp-20h] BYREF

  v4 = _S29_1;
  if ( (_S29_1 & 1) == 0 )
  {
    _S29_1 |= 1u;
    v5 = UFG::qStringHashUpper32("M_Wheel01", -1);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symM_Wheel01, v5);
    atexit(UFG::BikePhysicsMoverComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symM_Wheel01__);
    v4 = _S29_1;
  }
  if ( (v4 & 2) == 0 )
  {
    _S29_1 = v4 | 2;
    v6 = UFG::qStringHashUpper32("M_Wheel02", -1);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symM_Wheel02, v6);
    atexit(UFG::BikePhysicsMoverComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symM_Wheel02__);
    v4 = _S29_1;
  }
  if ( (v4 & 4) == 0 )
  {
    _S29_1 = v4 | 4;
    v7 = UFG::qStringHashUpper32("M_Axle01", -1);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symM_Axle01, v7);
    atexit(UFG::BikePhysicsMoverComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symM_Axle01__);
    v4 = _S29_1;
  }
  if ( (v4 & 8) == 0 )
  {
    _S29_1 = v4 | 8;
    v8 = UFG::qStringHashUpper32("M_Axle02", -1);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symM_Axle02, v8);
    atexit(UFG::BikePhysicsMoverComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symM_Axle02__);
  }
  UFG::PhysicsMoverInterface::OnAttach(this, object);
  m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( m_pSimObject )
    v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
  else
    v10 = 0i64;
  mCreature = v10->mCreature;
  if ( mCreature )
  {
    v12 = -1;
    if ( mCreature->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, symM_Wheel01.mUID);
    else
      BoneID = -1;
    this->mWheelBoneId.array[0] = BoneID;
    if ( mCreature->mPose.mRigHandle.mData )
      v14 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, symM_Wheel02.mUID);
    else
      v14 = -1;
    this->mWheelBoneId.array[1] = v14;
    if ( mCreature->mPose.mRigHandle.mData )
      v15 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, symM_Axle01.mUID);
    else
      v15 = -1;
    this->mAxleBoneId.array[0] = v15;
    if ( mCreature->mPose.mRigHandle.mData )
      v12 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, symM_Axle02.mUID);
    this->mAxleBoneId.array[1] = v12;
  }
  v16.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::PhysicsMoverInterface::TargetSphereEventHandler;
  v16.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v16,
    UFG::gBulletImpactDamageSphereEventChannel.mUID,
    UFG::gBulletImpactDamageSphereEventChannel.mName,
    0);
}

// File Line: 181
// RVA: 0x684120
void __fastcall UFG::BikePhysicsMoverComponent::OnDetach(UFG::CarPhysicsMoverComponent *this)
{
  fastdelegate::FastDelegate1<UFG::Event *,void> v2; // [rsp+20h] [rbp-18h] BYREF

  v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::PhysicsMoverInterface::TargetSphereEventHandler;
  v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    &v2,
    UFG::gBulletImpactDamageSphereEventChannel.mUID);
  UFG::PhysicsMoverInterface::OnDetach(this);
}

// File Line: 191
// RVA: 0x68F590
void __fastcall UFG::BikePhysicsMoverComponent::Update(UFG::BikePhysicsMoverComponent *this, float deltaTime)
{
  UFG::SimObject *m_pPointer; // rbx

  UFG::PhysicsMoverInterface::Update(this, deltaTime);
  m_pPointer = this->mParameters.mSimObject.m_pPointer;
  if ( this->UFG::PhysicsMoverInterface::UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface>::mPrev )
  {
    if ( m_pPointer
      && (UFG::PhysicsMotorBike::DidStabilizationJustSwitchOff((UFG::PhysicsMotorBike *)this->mParameters.mSimObject.m_pPointer)
       || UFG::PhysicsMotorBike::IsStabilizationDisabled((UFG::PhysicsMotorBike *)m_pPointer)) )
    {
      UFG::VehicleDriverInterface::EjectDriver((UFG::VehicleDriverInterface *)this->UFG::PhysicsMoverInterface::UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface>::mPrev);
    }
    if ( *(float *)&this->mDriverComponent.UFG::PhysicsMoverInterface::mPrev >= 1.0 )
    {
      if ( m_pPointer )
        UFG::PhysicsMotorBike::DumpBike((UFG::PhysicsMotorBike *)m_pPointer);
      UFG::VehicleDriverInterface::EjectDriver((UFG::VehicleDriverInterface *)this->UFG::PhysicsMoverInterface::UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface>::mPrev);
    }
  }
}

// File Line: 214
// RVA: 0x681D50
void __fastcall UFG::BikePhysicsMoverComponent::Mount(UFG::BikePhysicsMoverComponent *this)
{
  UFG::PhysicsMotorBike *mPhysicsVehicle; // rcx

  mPhysicsVehicle = (UFG::PhysicsMotorBike *)this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
    UFG::PhysicsMotorBike::ResetStabilization(mPhysicsVehicle);
}

// File Line: 225
// RVA: 0x676A40
void __fastcall UFG::BikePhysicsMoverComponent::Dismount(UFG::BikePhysicsMoverComponent *this)
{
  UFG::PhysicsWheeledVehicle *mPhysicsVehicle; // rbx
  UFG::PhysicsVehicle *v3; // rax
  UFG::qVector3 pos; // [rsp+20h] [rbp-68h] BYREF
  UFG::qVector3 impulse; // [rsp+30h] [rbp-58h] BYREF
  UFG::qMatrix44 mat; // [rsp+40h] [rbp-48h] BYREF

  mPhysicsVehicle = (UFG::PhysicsWheeledVehicle *)this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
  {
    UFG::PhysicsMotorBike::DumpBike((UFG::PhysicsMotorBike *)this->mPhysicsVehicle);
    UFG::PhysicsWheeledVehicle::SetWheelFrictionMultiplier(mPhysicsVehicle, 1u, 0.0);
    UFG::PhysicsWheeledVehicle::SetWheelFrictionMultiplier(mPhysicsVehicle, 0, 0.0);
    v3 = this->mPhysicsVehicle;
    if ( v3 )
    {
      if ( v3->mCurrentLod == LOD_SETTING_EXTREME )
      {
        UFG::PhysicsWheeledVehicle::GetWheelMatrix(mPhysicsVehicle, 1u, &mat);
        impulse.z = mat.v1.z * 500.0;
        pos.x = mat.v3.x;
        impulse.x = mat.v1.x * 500.0;
        impulse.y = mat.v1.y * 500.0;
        *(_QWORD *)&pos.y = *(_QWORD *)&mat.v3.y;
        UFG::PhysicsVehicle::ApplyImpulse(mPhysicsVehicle, &impulse, &pos);
      }
    }
  }
}

// File Line: 247
// RVA: 0x67AFC0
UFG::PhysicsMotorBike *__fastcall UFG::BikePhysicsMoverComponent::GetPhysicsBike(UFG::BikePhysicsMoverComponent *this)
{
  return (UFG::PhysicsMotorBike *)this->mPhysicsVehicle;
}

