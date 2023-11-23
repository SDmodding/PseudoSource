// File Line: 39
// RVA: 0x157B7B0
__int64 dynamic_initializer_for__UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList__);
}

// File Line: 40
// RVA: 0x67B430
const char *__fastcall UFG::CarPhysicsMoverComponent::GetTypeName(UFG::CarPhysicsMoverComponent *this)
{
  return "CarPhysicsMoverComponent";
}

// File Line: 47
// RVA: 0x667A00
void __fastcall UFG::CarPhysicsMoverComponent::CarPhysicsMoverComponent(
        UFG::CarPhysicsMoverComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        component_CarPhysicsMover *dataPtr)
{
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *mPrev; // rax

  UFG::PhysicsMoverInterface::PhysicsMoverInterface(this, 4, pSceneObj, dataPtr);
  this->UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent>::mPrev = &this->UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent>;
  this->UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent>::mNext = &this->UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent>;
  this->UFG::PhysicsMoverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CarPhysicsMoverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::PhysicsMoverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CarPhysicsMoverComponent::`vftable{for `UFG::UpdateInterface};
  this->mSupportsAttachments = 1;
  mPrev = UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList.mNode.mPrev;
  UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent>;
  this->UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent>::mNext = (UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *)&UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList;
  UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::CarPhysicsMoverComponent::_CarPhysicsMoverComponentTypeUID,
    "CarPhysicsMoverComponent");
}

// File Line: 55
// RVA: 0x66C560
void __fastcall UFG::CarPhysicsMoverComponent::~CarPhysicsMoverComponent(UFG::CarPhysicsMoverComponent *this)
{
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *v2; // rdx
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *mPrev; // rcx
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *mNext; // rax
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *v5; // rcx
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *v6; // rax

  this->UFG::PhysicsMoverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CarPhysicsMoverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::PhysicsMoverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CarPhysicsMoverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentpCurrentIterator )
    UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentpCurrentIterator = (UFG::CarPhysicsMoverComponent *)&this->UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent>::mPrev[-58].mNext;
  v2 = &this->UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent>;
  mPrev = this->UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent>::mPrev;
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

// File Line: 60
// RVA: 0x6880B0
UFG::CarPhysicsMoverComponent *__fastcall UFG::CarPhysicsMoverComponent::PropertiesOnActivateNew(
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
         (UFG::qArray<unsigned long,0> *)&component_CarPhysicsMover::sPropertyName,
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
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x3B0ui64, "CarPhysicsMoverComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::CarPhysicsMoverComponent::CarPhysicsMoverComponent(
      (UFG::CarPhysicsMoverComponent *)v10,
      pSceneObj,
      (component_CarPhysicsMover *)MemImagePtr);
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
  return (UFG::CarPhysicsMoverComponent *)v6;
}

// File Line: 78
// RVA: 0x676A20
void __fastcall UFG::CarPhysicsMoverComponent::DisableFlappingAttachments(UFG::CarPhysicsMoverComponent *this)
{
  UFG::PhysicsCar *mPhysicsVehicle; // rcx

  this->mSupportsAttachments = 0;
  mPhysicsVehicle = (UFG::PhysicsCar *)this->mPhysicsVehicle;
  if ( mPhysicsVehicle )
    UFG::PhysicsCar::DestroyAllAttachments(mPhysicsVehicle);
}

// File Line: 91
// RVA: 0x6751C0
void __fastcall UFG::CarPhysicsMoverComponent::CreateVehicle(
        UFG::CarPhysicsMoverComponent *this,
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
  UFG::PhysicsCar *mFreeListHead; // rdi
  unsigned int v24; // eax
  UFG::PhysicsVehicle *v25; // rax
  UFG::WaterFloatingTrackerComponent *v26; // rdi
  UFG::qVector3 wheelPositions; // [rsp+38h] [rbp-60h] BYREF

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
  this->mParameters.firstFrontWheel = 0;
  this->mParameters.lastFrontWheel = 1;
  this->mParameters.firstRearWheel = 2;
  this->mParameters.lastRearWheel = 3;
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
  mFreeListHead = (UFG::PhysicsCar *)UFG::PhysicsVehicle::mAllocator.mFreeListHead;
  if ( UFG::PhysicsVehicle::mAllocator.mFreeListHead )
  {
    UFG::PhysicsVehicle::mAllocator.mFreeListHead = *(char **)UFG::PhysicsVehicle::mAllocator.mFreeListHead;
    v24 = UFG::PhysicsVehicle::mAllocator.mNumSlotsAllocated + 1;
    UFG::PhysicsVehicle::mAllocator.mNumSlotsAllocated = v24;
    if ( UFG::PhysicsVehicle::mAllocator.mMostSlotsAllocated <= v24 )
      UFG::PhysicsVehicle::mAllocator.mMostSlotsAllocated = v24;
  }
  else
  {
    mFreeListHead = (UFG::PhysicsCar *)UFG::qMemoryPool::Allocate(
                                         &gPhysicsMemoryPool,
                                         0x470ui64,
                                         "PhysicsCar",
                                         0i64,
                                         1u);
  }
  if ( mFreeListHead )
  {
    UFG::PhysicsCar::PhysicsCar(mFreeListHead, &this->mParameters, transform, velocity, &wheelPositions);
    v12 = v25;
  }
  this->mPhysicsVehicle = v12;
  v12->vfptr[3].__vecDelDtor(v12, (unsigned int)this);
  v26 = (UFG::WaterFloatingTrackerComponent *)UFG::AquireWaterFloatingTrackerComponent(
                                                this->m_pSimObject,
                                                this->mPhysicsVehicle->mRigidBody->mBody);
  if ( UFG::SimComponent::IsType(v26, UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID) )
  {
    this->mPhysicsVehicle->mWaterFloatingTrackerComponent = v26;
    ((void (__fastcall *)(UFG::WaterFloatingTrackerComponent *))this->mPhysicsVehicle->mWaterFloatingTrackerComponent->vfptr[14].__vecDelDtor)(this->mPhysicsVehicle->mWaterFloatingTrackerComponent);
  }
}

// File Line: 142
// RVA: 0x1582FE0
__int64 UFG::_dynamic_initializer_for__gsymM_WheelL01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_WheelL01", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_WheelL01, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymM_WheelL01__);
}

// File Line: 143
// RVA: 0x1583060
__int64 UFG::_dynamic_initializer_for__gsymM_WheelR01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_WheelR01", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_WheelR01, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymM_WheelR01__);
}

// File Line: 144
// RVA: 0x1583020
__int64 UFG::_dynamic_initializer_for__gsymM_WheelL02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_WheelL02", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_WheelL02, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymM_WheelL02__);
}

// File Line: 145
// RVA: 0x15830A0
__int64 UFG::_dynamic_initializer_for__gsymM_WheelR02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_WheelR02", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_WheelR02, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymM_WheelR02__);
}

// File Line: 147
// RVA: 0x1582EE0
__int64 UFG::_dynamic_initializer_for__gsymM_AxleL01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_AxleL01", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_AxleL01, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymM_AxleL01__);
}

// File Line: 148
// RVA: 0x1582F60
__int64 UFG::_dynamic_initializer_for__gsymM_AxleR01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_AxleR01", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_AxleR01, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymM_AxleR01__);
}

// File Line: 149
// RVA: 0x1582F20
__int64 UFG::_dynamic_initializer_for__gsymM_AxleL02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_AxleL02", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_AxleL02, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymM_AxleL02__);
}

// File Line: 150
// RVA: 0x1582FA0
__int64 UFG::_dynamic_initializer_for__gsymM_AxleR02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_AxleR02", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_AxleR02, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymM_AxleR02__);
}

// File Line: 153
// RVA: 0x6829D0
void __fastcall UFG::CarPhysicsMoverComponent::OnAttach(UFG::CarPhysicsMoverComponent *this, UFG::SimObject *object)
{
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::CharacterAnimationComponent *v4; // rax
  Creature *mCreature; // rsi
  int v6; // ebp
  int BoneID; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  UFG::qSafeArray<int,4> *p_mAxleBoneId; // rbx
  int v13; // eax
  int v14; // eax
  int i; // esi
  fastdelegate::FastDelegate1<UFG::Event *,void> v16; // [rsp+30h] [rbp-18h] BYREF

  UFG::PhysicsMoverInterface::OnAttach(this, object);
  m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( m_pSimObject )
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
  else
    v4 = 0i64;
  mCreature = v4->mCreature;
  if ( mCreature )
  {
    v6 = -1;
    if ( mCreature->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_WheelL01.mUID);
    else
      BoneID = -1;
    this->mWheelBoneId.array[0] = BoneID;
    if ( mCreature->mPose.mRigHandle.mData )
      v8 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_WheelR01.mUID);
    else
      v8 = -1;
    this->mWheelBoneId.array[1] = v8;
    if ( mCreature->mPose.mRigHandle.mData )
      v9 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_WheelL02.mUID);
    else
      v9 = -1;
    this->mWheelBoneId.array[2] = v9;
    if ( mCreature->mPose.mRigHandle.mData )
      v10 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_WheelR02.mUID);
    else
      v10 = -1;
    this->mWheelBoneId.array[3] = v10;
    if ( mCreature->mPose.mRigHandle.mData )
      v11 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_AxleL01.mUID);
    else
      v11 = -1;
    p_mAxleBoneId = &this->mAxleBoneId;
    this->mAxleBoneId.array[0] = v11;
    if ( mCreature->mPose.mRigHandle.mData )
      v13 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_AxleR01.mUID);
    else
      v13 = -1;
    this->mAxleBoneId.array[1] = v13;
    if ( mCreature->mPose.mRigHandle.mData )
      v14 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_AxleL02.mUID);
    else
      v14 = -1;
    this->mAxleBoneId.array[2] = v14;
    if ( mCreature->mPose.mRigHandle.mData )
      v6 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_AxleR02.mUID);
    this->mAxleBoneId.array[3] = v6;
    for ( i = 0; i < this->mNumWheels; p_mAxleBoneId = (UFG::qSafeArray<int,4> *)((char *)p_mAxleBoneId + 4) )
    {
      if ( p_mAxleBoneId->array[0] == -1 )
      {
        UFG::qPrintf("axle hack for fucked up vehicle skeleton %s \n", this->mParameters.modelName.mData);
        p_mAxleBoneId->array[0] = p_mAxleBoneId[1].array[0];
      }
      ++i;
    }
  }
  v16.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v16.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::PhysicsMoverInterface::TargetSphereEventHandler;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v16,
    UFG::gBulletImpactDamageSphereEventChannel.mUID,
    UFG::gBulletImpactDamageSphereEventChannel.mName,
    0);
}

