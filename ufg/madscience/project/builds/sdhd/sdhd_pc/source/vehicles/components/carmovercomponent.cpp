// File Line: 39
// RVA: 0x157B7B0
__int64 dynamic_initializer_for__UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList__);
}

// File Line: 40
// RVA: 0x67B430
const char *__fastcall UFG::CarPhysicsMoverComponent::GetTypeName(UFG::CarPhysicsMoverComponent *this)
{
  return "CarPhysicsMoverComponent";
}

// File Line: 47
// RVA: 0x667A00
void __fastcall UFG::CarPhysicsMoverComponent::CarPhysicsMoverComponent(UFG::CarPhysicsMoverComponent *this, UFG::SceneObjectProperties *pSceneObj, component_CarPhysicsMover *dataPtr)
{
  UFG::CarPhysicsMoverComponent *v3; // rbx
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *v4; // rdx
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *v5; // rax

  v3 = this;
  UFG::PhysicsMoverInterface::PhysicsMoverInterface(
    (UFG::PhysicsMoverInterface *)&this->vfptr,
    4,
    pSceneObj,
    (component_PhysicsMover *)&dataPtr->physicsPropertySetAI);
  v4 = (UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CarPhysicsMoverComponent::`vftable'{for `UFG::SimComponent'};
  v3->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CarPhysicsMoverComponent::`vftable'{for `UFG::UpdateInterface'};
  v3->mSupportsAttachments = 1;
  v5 = UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList.mNode.mPrev;
  UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *)&UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList;
  UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentList.mNode.mPrev = (UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::CarPhysicsMoverComponent::_CarPhysicsMoverComponentTypeUID,
    "CarPhysicsMoverComponent");
}

// File Line: 55
// RVA: 0x66C560
void __fastcall UFG::CarPhysicsMoverComponent::~CarPhysicsMoverComponent(UFG::CarPhysicsMoverComponent *this)
{
  UFG::CarPhysicsMoverComponent *v1; // r8
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *v2; // rdx
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *v3; // rcx
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *v4; // rax
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *v5; // rcx
  UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CarPhysicsMoverComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CarPhysicsMoverComponent::`vftable'{for `UFG::UpdateInterface'};
  if ( this == UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentpCurrentIterator )
    UFG::CarPhysicsMoverComponent::s_CarPhysicsMoverComponentpCurrentIterator = (UFG::CarPhysicsMoverComponent *)&this->mPrev[-58].mNext;
  v2 = (UFG::qNode<UFG::CarPhysicsMoverComponent,UFG::CarPhysicsMoverComponent> *)&this->mPrev;
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

// File Line: 60
// RVA: 0x6880B0
UFG::SimComponent *__fastcall UFG::CarPhysicsMoverComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
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
         (UFG::qSymbol *)&component_CarPhysicsMover::sPropertyName.mUID,
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
  v10 = UFG::qMemoryPool::Allocate(v9, 0x3B0ui64, "CarPhysicsMoverComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::CarPhysicsMoverComponent::CarPhysicsMoverComponent(
      (UFG::CarPhysicsMoverComponent *)v10,
      v3,
      (component_CarPhysicsMover *)v7);
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

// File Line: 78
// RVA: 0x676A20
void __fastcall UFG::CarPhysicsMoverComponent::DisableFlappingAttachments(UFG::CarPhysicsMoverComponent *this)
{
  this->mSupportsAttachments = 0;
  JUMPOUT(this->mPhysicsVehicle, 0i64, UFG::PhysicsCar::DestroyAllAttachments);
}

// File Line: 91
// RVA: 0x6751C0
void __fastcall UFG::CarPhysicsMoverComponent::CreateVehicle(UFG::CarPhysicsMoverComponent *this, UFG::qMatrix44 *transform, UFG::qVector3 *velocity)
{
  UFG::qVector3 *v3; // r12
  UFG::qMatrix44 *v4; // r13
  UFG::CarPhysicsMoverComponent *v5; // rbx
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
  UFG::PhysicsCar *v23; // rdi
  unsigned int v24; // eax
  UFG::PhysicsVehicle *v25; // rax
  UFG::SimComponent *v26; // rdi
  UFG::qVector3 wheelPositions; // [rsp+38h] [rbp-60h]

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
  v5->mParameters.firstFrontWheel = 0;
  v5->mParameters.lastFrontWheel = 1;
  v5->mParameters.firstRearWheel = 2;
  v5->mParameters.lastRearWheel = 3;
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
  v23 = (UFG::PhysicsCar *)UFG::PhysicsVehicle::mAllocator.mFreeListHead;
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
    v23 = (UFG::PhysicsCar *)UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x470ui64, "PhysicsCar", 0i64, 1u);
  }
  if ( v23 )
  {
    UFG::PhysicsCar::PhysicsCar(v23, &v5->mParameters, v4, v3, &wheelPositions);
    v12 = v25;
  }
  v5->mPhysicsVehicle = v12;
  v12->vfptr[3].__vecDelDtor((UFG::BasePhysicsObject *)&v12->vfptr, (unsigned int)v5);
  v26 = UFG::AquireWaterFloatingTrackerComponent(v5->m_pSimObject, v5->mPhysicsVehicle->mRigidBody->mBody);
  if ( UFG::SimComponent::IsType(v26, UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID) )
  {
    v5->mPhysicsVehicle->mWaterFloatingTrackerComponent = (UFG::WaterFloatingTrackerComponent *)v26;
    ((void (__cdecl *)(UFG::WaterFloatingTrackerComponent *))v5->mPhysicsVehicle->mWaterFloatingTrackerComponent->vfptr[14].__vecDelDtor)(v5->mPhysicsVehicle->mWaterFloatingTrackerComponent);
  }
}

// File Line: 142
// RVA: 0x1582FE0
__int64 UFG::_dynamic_initializer_for__gsymM_WheelL01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_WheelL01", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_WheelL01, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymM_WheelL01__);
}

// File Line: 143
// RVA: 0x1583060
__int64 UFG::_dynamic_initializer_for__gsymM_WheelR01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_WheelR01", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_WheelR01, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymM_WheelR01__);
}

// File Line: 144
// RVA: 0x1583020
__int64 UFG::_dynamic_initializer_for__gsymM_WheelL02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_WheelL02", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_WheelL02, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymM_WheelL02__);
}

// File Line: 145
// RVA: 0x15830A0
__int64 UFG::_dynamic_initializer_for__gsymM_WheelR02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_WheelR02", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_WheelR02, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymM_WheelR02__);
}

// File Line: 147
// RVA: 0x1582EE0
__int64 UFG::_dynamic_initializer_for__gsymM_AxleL01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_AxleL01", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_AxleL01, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymM_AxleL01__);
}

// File Line: 148
// RVA: 0x1582F60
__int64 UFG::_dynamic_initializer_for__gsymM_AxleR01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_AxleR01", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_AxleR01, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymM_AxleR01__);
}

// File Line: 149
// RVA: 0x1582F20
__int64 UFG::_dynamic_initializer_for__gsymM_AxleL02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_AxleL02", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_AxleL02, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymM_AxleL02__);
}

// File Line: 150
// RVA: 0x1582FA0
__int64 UFG::_dynamic_initializer_for__gsymM_AxleR02__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("M_AxleR02", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymM_AxleR02, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymM_AxleR02__);
}

// File Line: 153
// RVA: 0x6829D0
void __fastcall UFG::CarPhysicsMoverComponent::OnAttach(UFG::CarPhysicsMoverComponent *this, UFG::SimObject *object)
{
  UFG::CarPhysicsMoverComponent *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::CharacterAnimationComponent *v4; // rax
  Creature *v5; // rsi
  signed int v6; // ebp
  signed int v7; // eax
  signed int v8; // eax
  signed int v9; // eax
  signed int v10; // eax
  signed int v11; // eax
  UFG::qSafeArray<int,4> *v12; // rbx
  signed int v13; // eax
  signed int v14; // eax
  int i; // esi
  hkSeekableStreamReader *v16; // [rsp+30h] [rbp-18h]
  void (__usercall *v17)(UFG::PhysicsMoverInterface *@<rcx>, UFG::Event *@<rdx>, float@<xmm0>); // [rsp+38h] [rbp-10h]

  v2 = this;
  UFG::PhysicsMoverInterface::OnAttach((UFG::PhysicsMoverInterface *)&this->vfptr, object);
  v3 = (UFG::SimObjectCVBase *)v2->m_pSimObject;
  if ( v3 )
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
  else
    v4 = 0i64;
  v5 = v4->mCreature;
  if ( v5 )
  {
    v6 = -1;
    if ( v5->mPose.mRigHandle.mData )
      v7 = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_WheelL01.mUID);
    else
      v7 = -1;
    v2->mWheelBoneId.array[0] = v7;
    if ( v5->mPose.mRigHandle.mData )
      v8 = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_WheelR01.mUID);
    else
      v8 = -1;
    v2->mWheelBoneId.array[1] = v8;
    if ( v5->mPose.mRigHandle.mData )
      v9 = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_WheelL02.mUID);
    else
      v9 = -1;
    v2->mWheelBoneId.array[2] = v9;
    if ( v5->mPose.mRigHandle.mData )
      v10 = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_WheelR02.mUID);
    else
      v10 = -1;
    v2->mWheelBoneId.array[3] = v10;
    if ( v5->mPose.mRigHandle.mData )
      v11 = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_AxleL01.mUID);
    else
      v11 = -1;
    v12 = &v2->mAxleBoneId;
    v2->mAxleBoneId.array[0] = v11;
    if ( v5->mPose.mRigHandle.mData )
      v13 = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_AxleR01.mUID);
    else
      v13 = -1;
    v2->mAxleBoneId.array[1] = v13;
    if ( v5->mPose.mRigHandle.mData )
      v14 = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_AxleL02.mUID);
    else
      v14 = -1;
    v2->mAxleBoneId.array[2] = v14;
    if ( v5->mPose.mRigHandle.mData )
      v6 = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, UFG::gsymM_AxleR02.mUID);
    v2->mAxleBoneId.array[3] = v6;
    for ( i = 0; i < v2->mNumWheels; v12 = (UFG::qSafeArray<int,4> *)((char *)v12 + 4) )
    {
      if ( v12->array[0] == -1 )
      {
        UFG::qPrintf("axle hack for fucked up vehicle skeleton %s \n", v2->mParameters.modelName.mData);
        v12->array[0] = v12[1].array[0];
      }
      ++i;
    }
  }
  v16 = Assembly::GetRCX(v2);
  v17 = UFG::PhysicsMoverInterface::TargetSphereEventHandler;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v16,
    UFG::gBulletImpactDamageSphereEventChannel.mUID,
    UFG::gBulletImpactDamageSphereEventChannel.mName,
    0);
}

