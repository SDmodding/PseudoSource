// File Line: 88
// RVA: 0x1513F70
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::BaseVehiclePhysicsDef_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::BaseVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::BaseVehiclePhysicsDef,UFG::qReflectObject>::sInventory,
    "UFG::BaseVehiclePhysicsDef",
    v0);
  UFG::qReflectObjectType<UFG::BaseVehiclePhysicsDef,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::BaseVehiclePhysicsDef>::`vftable;
  UFG::qReflectInventory<UFG::BaseVehiclePhysicsDef>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::BaseVehiclePhysicsDef,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::BaseVehiclePhysicsDef,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::BaseVehiclePhysicsDef_UFG::qReflectObject_::sInventory__);
}

// File Line: 89
// RVA: 0x15141F0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::WheeledVehiclePhysicsDef_UFG::BaseVehiclePhysicsDef_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::WheeledVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory,
    "UFG::WheeledVehiclePhysicsDef",
    v0);
  UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::WheeledVehiclePhysicsDef>::`vftable;
  UFG::qReflectInventory<UFG::WheeledVehiclePhysicsDef>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    &UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::WheeledVehiclePhysicsDef_UFG::BaseVehiclePhysicsDef_::sInventory__);
}

// File Line: 90
// RVA: 0x1513F30
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::CarPhysicsDef_UFG::WheeledVehiclePhysicsDef_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::CarPhysicsDef,UFG::WheeledVehiclePhysicsDef>::sFactoryOp);
}

// File Line: 91
// RVA: 0x1513FF0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::BikePhysicsDef_UFG::WheeledVehiclePhysicsDef_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::BikePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::BikePhysicsDef,UFG::WheeledVehiclePhysicsDef>::sInventory,
    "UFG::BikePhysicsDef",
    v0);
  UFG::qReflectObjectType<UFG::BikePhysicsDef,UFG::WheeledVehiclePhysicsDef>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::BikePhysicsDef>::`vftable;
  UFG::qReflectInventory<UFG::BikePhysicsDef>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::BikePhysicsDef,UFG::WheeledVehiclePhysicsDef>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    &UFG::qReflectObjectType<UFG::BikePhysicsDef,UFG::WheeledVehiclePhysicsDef>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::BikePhysicsDef_UFG::WheeledVehiclePhysicsDef_::sInventory__);
}

// File Line: 92
// RVA: 0x1514070
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::BoatPhysicsDef_UFG::BaseVehiclePhysicsDef_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::BoatPhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::BoatPhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory,
    "UFG::BoatPhysicsDef",
    v0);
  UFG::qReflectObjectType<UFG::BoatPhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::BoatPhysicsDef>::`vftable;
  UFG::qReflectInventory<UFG::BoatPhysicsDef>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::BoatPhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::BoatPhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::BoatPhysicsDef_UFG::BaseVehiclePhysicsDef_::sInventory__);
}

// File Line: 98
// RVA: 0x1513D10
__int64 dynamic_initializer_for__UFG::BaseVehiclePhysicsDef::mSearchTree__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BaseVehiclePhysicsDef::mSearchTree__);
}

// File Line: 113
// RVA: 0x1513CA0
__int64 dynamic_initializer_for__UFG::PhysicsVehicle::mAllocator__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::PhysicsVehicle::mAllocator);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PhysicsVehicle::mAllocator__);
}

// File Line: 119
// RVA: 0x1519EE0
void UFG::_dynamic_initializer_for__gWheelFixup__()
{
  UFG::gWheelFixup = UFG::qMatrix44::msIdentity;
}

// File Line: 149
// RVA: 0x44E420
void __fastcall UFG::VehicleParams::VehicleParams(UFG::VehicleParams *this)
{
  this->mPhysicsPropertiesName.mUID = -1;
  this->mSimObject.mPrev = &this->mSimObject;
  this->mSimObject.mNext = &this->mSimObject;
  this->mSimObject.m_pPointer = 0i64;
  UFG::qString::qString(&this->modelName);
}

// File Line: 163
// RVA: 0x468DD0
void __fastcall UFG::VehicleParams::Init(
        UFG::VehicleParams *this,
        UFG::qSymbol *physicsPropertiesName,
        const char *model_name)
{
  UFG::qString::Set(&this->modelName, model_name);
  this->mPhysicsPropertiesName = (UFG::qSymbol)physicsPropertiesName->mUID;
}

// File Line: 171
// RVA: 0x4519B0
void __fastcall UFG::VehicleParams::~VehicleParams(UFG::VehicleParams *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mSimObject; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  UFG::qString::~qString(&this->modelName);
  p_mSimObject = &this->mSimObject;
  if ( p_mSimObject->m_pPointer )
  {
    mPrev = p_mSimObject->mPrev;
    mNext = p_mSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mSimObject->mPrev = p_mSimObject;
    p_mSimObject->mNext = p_mSimObject;
  }
  p_mSimObject->m_pPointer = 0i64;
  v5 = p_mSimObject->mPrev;
  v6 = p_mSimObject->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mSimObject->mPrev = p_mSimObject;
  p_mSimObject->mNext = p_mSimObject;
}

// File Line: 177
// RVA: 0x4697E0
void UFG::PhysicsVehicle::Initialize(void)
{
  UFG::qRotationMatrixX(&UFG::gWheelFixup, 1.5707964);
  UFG::PhysicsVehicle::mAllocatorBuffer = UFG::qMemoryPool::Allocate(
                                            &gPhysicsMemoryPool,
                                            0x24900ui64,
                                            "PhysicsVehiclePool",
                                            0i64,
                                            1u);
  UFG::qFixedAllocator::Init(
    &UFG::PhysicsVehicle::mAllocator,
    (char *)UFG::PhysicsVehicle::mAllocatorBuffer,
    149760,
    1248,
    "PhysicsVehiclePool");
}

// File Line: 259
// RVA: 0x44BD30
void __fastcall UFG::PhysicsVehicle::PhysicsVehicle(
        UFG::PhysicsVehicle *this,
        UFG::VehicleParams *param,
        UFG::qMatrix44 *transform,
        UFG::qVector3 *velocity)
{
  UFG::SimComponent *v6; // r13
  UFG::qReflectHandle<UFG::BaseVehiclePhysicsDef> *p_mDnaDefinition; // rsi
  float y; // xmm2_4
  float z; // xmm1_4
  float w; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  UFG::qSafePointer<UFG::SimComponent,UFG::ParkourComponent> *p_mParkourComponent; // r12
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *p_mCoverComponent; // r15
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v50; // rax
  UFG::qReflectObject *mData; // rcx
  const char *vfptr; // rcx
  unsigned int v53; // ebx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v54; // rcx
  const char *TypeName; // rax
  UFG::allocator::free_link *v56; // rax
  UFG::CollisionInstanceData *v57; // rax
  UFG::CollisionInstanceData *v58; // rdi
  UFG::RigidBodyComponent *mFreeListHead; // rbx
  unsigned int v60; // eax
  UFG::RigidBodyComponent *v61; // rax
  UFG::RigidBodyComponent *v62; // rcx
  hkpRigidBody *mBody; // rdi
  UFG::qReflectObject *v64; // rbx
  float v65; // xmm6_4
  __int64 v66; // rbx
  char v67; // dl
  char v68; // cl
  _QWORD **Value; // rax
  hkpRigidBody *v70; // rax
  hkpRigidBody *v71; // rax
  char v72; // al
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v73; // rcx
  const char *v74; // rax
  unsigned int mParkourGuid; // ebx
  UFG::allocator::free_link *v76; // rax
  UFG::SimComponent *v77; // rax
  UFG::SimComponent *v78; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v81; // rax
  unsigned int mCoverGuid; // ebx
  UFG::allocator::free_link *v83; // rax
  UFG::SimComponent *v84; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v85; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v86; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v87; // rax
  UFG::SimObjectModifier v88; // [rsp+40h] [rbp-80h] BYREF
  __m128 v89; // [rsp+60h] [rbp-60h] BYREF
  hkQsTransformf orient; // [rsp+70h] [rbp-50h] BYREF
  hkTransformf transforma; // [rsp+A0h] [rbp-20h] BYREF
  hkpRigidBodyCinfo info; // [rsp+E0h] [rbp+20h] BYREF
  UFG::qSymbol result[2]; // [rsp+228h] [rbp+168h] BYREF
  UFG::qSymbol name[2]; // [rsp+230h] [rbp+170h] BYREF
  unsigned int *v95; // [rsp+238h] [rbp+178h]

  v88.mptrSimObject.m_pPointer = (UFG::SimObject *)-2i64;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  this->mUserData.isBoat = 0;
  v89.m128_u64[1] = (unsigned __int64)&this->mUserData.simComponent;
  this->mUserData.simComponent.mPrev = &this->mUserData.simComponent;
  this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  v6 = 0i64;
  this->mUserData.simComponent.m_pPointer = 0i64;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsVehicle::`vftable;
  this->mWaterFloatingTrackerComponent = 0i64;
  this->mParams = param;
  p_mDnaDefinition = &this->mDnaDefinition;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mDnaDefinition);
  p_mDnaDefinition->mTypeUID = UFG::qStringHash64("UFG::BaseVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  this->mRigidBody = 0i64;
  this->mBulletCollider = 0i64;
  this->mVolumeRigidBody = 0i64;
  *(_QWORD *)&name[0].mUID = &this->mCollisionMeshBundle;
  UFG::qResourceHandle::qResourceHandle(&this->mCollisionMeshBundle);
  this->mCollisionMeshBundle.mOwner = 0i64;
  this->mCollisionMeshBundle.mUnloading = 0;
  y = transform->v0.y;
  z = transform->v0.z;
  w = transform->v0.w;
  this->mLastGoodPosition.v0.x = transform->v0.x;
  this->mLastGoodPosition.v0.y = y;
  this->mLastGoodPosition.v0.z = z;
  this->mLastGoodPosition.v0.w = w;
  v11 = transform->v1.y;
  v12 = transform->v1.z;
  v13 = transform->v1.w;
  this->mLastGoodPosition.v1.x = transform->v1.x;
  this->mLastGoodPosition.v1.y = v11;
  this->mLastGoodPosition.v1.z = v12;
  this->mLastGoodPosition.v1.w = v13;
  v14 = transform->v2.y;
  v15 = transform->v2.z;
  v16 = transform->v2.w;
  this->mLastGoodPosition.v2.x = transform->v2.x;
  this->mLastGoodPosition.v2.y = v14;
  this->mLastGoodPosition.v2.z = v15;
  this->mLastGoodPosition.v2.w = v16;
  v17 = transform->v3.y;
  v18 = transform->v3.z;
  v19 = transform->v3.w;
  this->mLastGoodPosition.v3.x = transform->v3.x;
  this->mLastGoodPosition.v3.y = v17;
  this->mLastGoodPosition.v3.z = v18;
  this->mLastGoodPosition.v3.w = v19;
  v20 = transform->v0.y;
  v21 = transform->v0.z;
  v22 = transform->v0.w;
  this->mBodyTransform.v0.x = transform->v0.x;
  this->mBodyTransform.v0.y = v20;
  this->mBodyTransform.v0.z = v21;
  this->mBodyTransform.v0.w = v22;
  v23 = transform->v1.y;
  v24 = transform->v1.z;
  v25 = transform->v1.w;
  this->mBodyTransform.v1.x = transform->v1.x;
  this->mBodyTransform.v1.y = v23;
  this->mBodyTransform.v1.z = v24;
  this->mBodyTransform.v1.w = v25;
  v26 = transform->v2.y;
  v27 = transform->v2.z;
  v28 = transform->v2.w;
  this->mBodyTransform.v2.x = transform->v2.x;
  this->mBodyTransform.v2.y = v26;
  this->mBodyTransform.v2.z = v27;
  this->mBodyTransform.v2.w = v28;
  v29 = transform->v3.y;
  v30 = transform->v3.z;
  v31 = transform->v3.w;
  this->mBodyTransform.v3.x = transform->v3.x;
  this->mBodyTransform.v3.y = v29;
  this->mBodyTransform.v3.z = v30;
  this->mBodyTransform.v3.w = v31;
  v32 = transform->v0.y;
  v33 = transform->v0.z;
  v34 = transform->v0.w;
  this->mTargetTransform.v0.x = transform->v0.x;
  this->mTargetTransform.v0.y = v32;
  this->mTargetTransform.v0.z = v33;
  this->mTargetTransform.v0.w = v34;
  v35 = transform->v1.y;
  v36 = transform->v1.z;
  v37 = transform->v1.w;
  this->mTargetTransform.v1.x = transform->v1.x;
  this->mTargetTransform.v1.y = v35;
  this->mTargetTransform.v1.z = v36;
  this->mTargetTransform.v1.w = v37;
  v38 = transform->v2.y;
  v39 = transform->v2.z;
  v40 = transform->v2.w;
  this->mTargetTransform.v2.x = transform->v2.x;
  this->mTargetTransform.v2.y = v38;
  this->mTargetTransform.v2.z = v39;
  this->mTargetTransform.v2.w = v40;
  v41 = transform->v3.y;
  v42 = transform->v3.z;
  v43 = transform->v3.w;
  this->mTargetTransform.v3.x = transform->v3.x;
  this->mTargetTransform.v3.y = v41;
  this->mTargetTransform.v3.z = v42;
  this->mTargetTransform.v3.w = v43;
  v44 = UFG::qVector4::msZero.y;
  v45 = UFG::qVector4::msZero.z;
  v46 = UFG::qVector4::msZero.w;
  this->mLastFixupPosition.x = UFG::qVector4::msZero.x;
  this->mLastFixupPosition.y = v44;
  this->mLastFixupPosition.z = v45;
  this->mLastFixupPosition.w = v46;
  this->mLastGoodPositionSampleTimer = 0.0;
  this->mCollisionListener = 0i64;
  this->mReorientActionRoll = 0i64;
  this->mReorientActionPitch = 0i64;
  p_mParkourComponent = &this->mParkourComponent;
  this->mParkourComponent.mPrev = &this->mParkourComponent;
  this->mParkourComponent.mNext = &this->mParkourComponent;
  this->mParkourComponent.m_pPointer = 0i64;
  p_mCoverComponent = &this->mCoverComponent;
  *(_QWORD *)&name[0].mUID = &this->mCoverComponent;
  this->mCoverComponent.mPrev = &this->mCoverComponent;
  this->mCoverComponent.mNext = &this->mCoverComponent;
  this->mCoverComponent.m_pPointer = 0i64;
  *(_QWORD *)&this->mDesiredLod = 1i64;
  this->mIsProxy = 0;
  *(_QWORD *)&this->mSpeedKPH = 0i64;
  this->mRotMassScaleForCollisions = 2.5;
  *((_DWORD *)this + 151) &= ~8u;
  *((_DWORD *)this + 151) |= 0x10u;
  mUID = this->mParams->mPhysicsPropertiesName.mUID;
  if ( mUID )
  {
    v50 = UFG::qBaseTreeRB::Get(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree, mUID);
    if ( v50 )
      UFG::qReflectHandleBase::Init(p_mDnaDefinition, p_mDnaDefinition->mTypeUID, (unsigned __int64)v50->mNULL.mParent);
  }
  UFG::PhysicsVehicle::LoadProperties(this);
  *((_DWORD *)this + 151) ^= (*((_DWORD *)this + 151) ^ LODWORD(this->mDnaDefinition.mData[1].mBaseNode.mParent)) & 7;
  this->mSystemId = UFG::CustomCollisionFilter::GetUnusedSystemId(UFG::BasePhysicsSystem::mInstance->mCollisionFilter);
  hkTransformf::set4x4ColumnMajor(&transforma, &transform->v0.x);
  hkQsTransformf::setFromTransformNoScale(&orient, &transforma);
  mData = this->mDnaDefinition.mData;
  if ( LODWORD(mData[1].mBaseNode.mUID) )
    vfptr = (const char *)mData[1].vfptr;
  else
    vfptr = &customCaption;
  v53 = UFG::qStringHashUpper32(vfptr, -1);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&orient);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v54);
  *(_QWORD *)&v88.mbOpen = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::PhysicsPropertyManager::GetObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&orient, v53, 0);
  UFG::PhysicsVehicle::SetupCollisionGeometry(this, *(const char **)(*(_QWORD *)&result[0].mUID + 56i64));
  v56 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x70ui64, "CollisionInstanceData", 0i64, 1u);
  *(_QWORD *)&name[0].mUID = v56;
  if ( v56 )
  {
    UFG::CollisionInstanceData::CollisionInstanceData((UFG::CollisionInstanceData *)v56);
    v58 = v57;
  }
  else
  {
    v58 = 0i64;
  }
  UFG::qSymbol::create_from_string(result, "PhysicsVehicle");
  v89.m128_u64[1] = (unsigned __int64)name;
  name[0] = result[0];
  UFG::CollisionInstanceData::Set(
    v58,
    result[0].mUID,
    0,
    &name[0].mUID,
    &orient.m_translation,
    &orient.m_rotation,
    this->mBodyCollisionMesh->mNode.mUID);
  mFreeListHead = (UFG::RigidBodyComponent *)UFG::RigidBodyComponent::mAllocator.mFreeListHead;
  if ( UFG::RigidBodyComponent::mAllocator.mFreeListHead )
  {
    UFG::RigidBodyComponent::mAllocator.mFreeListHead = *(char **)UFG::RigidBodyComponent::mAllocator.mFreeListHead;
    v60 = UFG::RigidBodyComponent::mAllocator.mNumSlotsAllocated + 1;
    UFG::RigidBodyComponent::mAllocator.mNumSlotsAllocated = v60;
    if ( UFG::RigidBodyComponent::mAllocator.mMostSlotsAllocated <= v60 )
      UFG::RigidBodyComponent::mAllocator.mMostSlotsAllocated = v60;
    *(_QWORD *)&name[0].mUID = mFreeListHead;
  }
  else
  {
    mFreeListHead = (UFG::RigidBodyComponent *)UFG::qMemoryPool::Allocate(
                                                 &gPhysicsMemoryPool,
                                                 0x1D8ui64,
                                                 "RigidBodyComponent",
                                                 0i64,
                                                 1u);
    *(_QWORD *)&name[0].mUID = mFreeListHead;
  }
  if ( mFreeListHead )
  {
    UFG::RigidBodyComponent::RigidBodyComponent(mFreeListHead, this->mBodyCollisionMesh, v58, 0x30000u, -1);
    v62 = v61;
  }
  else
  {
    v62 = 0i64;
  }
  this->mRigidBody = v62;
  v62->UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(v62, 0);
  UFG::RigidBody::SetCollisionLayer(this->mRigidBody, 0x16u, this->mSystemId, 1, 1);
  mBody = this->mRigidBody->mBody;
  v64 = this->mDnaDefinition.mData;
  v65 = *((float *)&v64[1].mBaseNode.mParent + 1) / hkpMotion::getMass(&mBody->m_motion);
  hkpRigidBody::setMass(mBody, *((float *)&this->mDnaDefinition.mData[1].mBaseNode.mParent + 1));
  UFG::CollisionMeshData::GetInertiaTensor(this->mBodyCollisionMesh, &transforma.m_rotation, v65);
  hkpRigidBody::setInertiaLocal(mBody, &transforma.m_rotation);
  hkpRigidBody::setFriction(mBody, *(float *)this->mDnaDefinition.mData[1].mBaseNode.mChildren);
  hkpRigidBody::setRestitution(mBody, *((float *)this->mDnaDefinition.mData[1].mBaseNode.mChildren + 1));
  mBody->m_responseModifierFlags = 1;
  UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
    (hkSimplePropertyValue)v88.mptrSimObject.mNext->mNext,
    mBody);
  v89 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)*v95, (__m128)v95[2]), _mm_unpacklo_ps((__m128)v95[1], (__m128)0i64));
  hkpEntity::activate(mBody);
  mBody->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&mBody->m_motion, (unsigned int)&v89);
  UFG::SimObjectModifier::SimObjectModifier(&v88, this->mParams->mSimObject.m_pPointer, 1);
  UFG::SimObjectModifier::AttachComponent(&v88, this->mRigidBody, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v88);
  UFG::SimObjectModifier::~SimObjectModifier(&v88);
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&info);
  UFG::CollisionMeshData::GetInertiaTensor(this->mBulletCollisionMesh, &info.m_inertiaTensor, 1.0);
  UFG::CollisionMeshData::GetCentreOfMass(this->mBulletCollisionMesh, &info.m_centerOfMass);
  info.m_collisionFilterInfo = 27;
  info.m_shape = this->mBulletCollisionMesh->mShape;
  info.m_position = orient.m_translation;
  info.m_rotation = orient.m_rotation;
  info.m_motionType.m_storage = 5;
  v66 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v67 = ++*(_BYTE *)(v66 + 80);
  *(_DWORD *)(v66 + 4i64 * v67) = 0;
  *(_QWORD *)(v66 + 8i64 * v67 + 16) = "hkpRigidBody";
  *(_QWORD *)(v66 + 8i64 * v67 + 48) = 0i64;
  v68 = *(_BYTE *)(v66 + 81);
  if ( v67 > v68 )
    v68 = v67;
  *(_BYTE *)(v66 + 81) = v68;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v70 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 720i64);
  *(_QWORD *)&result[0].mUID = v70;
  if ( v70 )
    hkpRigidBody::hkpRigidBody(v70, &info);
  else
    v71 = 0i64;
  this->mBulletCollider = v71;
  v72 = *(_BYTE *)(v66 + 80);
  if ( v72 > 0 )
  {
    *(_BYTE *)(v66 + 80) = v72 - 1;
  }
  else
  {
    *(_BYTE *)(v66 + 80) = 0;
    *(_DWORD *)v66 = 3;
    *(_QWORD *)(v66 + 16) = 0i64;
    *(_QWORD *)(v66 + 48) = 0i64;
  }
  if ( (_S11_5 & 1) == 0 )
  {
    _S11_5 |= 1u;
    bulletMoppGuid = UFG::qStringHashUpper32("BulletMopp", -1);
  }
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v88);
  v74 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v73);
  v88.mptrSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)UFG::qStringHash64(v74, 0xFFFFFFFFFFFFFFFFui64);
  UFG::PhysicsPropertyManager::GetObjectProperties(
    (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v88,
    bulletMoppGuid,
    0);
  UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
    *(hkSimplePropertyValue *)(v89.m128_u64[0] + 8),
    this->mBulletCollider);
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v88);
  mParkourGuid = this->mBodyCollisionMesh->mParkourGuid;
  if ( mParkourGuid )
  {
    v76 = UFG::qMalloc(0xC8ui64, "ParkourComponent", 0x800ui64);
    *(_QWORD *)&result[0].mUID = v76;
    if ( v76 )
    {
      UFG::ParkourComponent::ParkourComponent((UFG::ParkourComponent *)v76, mParkourGuid, -1);
      v78 = v77;
    }
    else
    {
      v78 = 0i64;
    }
    if ( this->mParkourComponent.m_pPointer )
    {
      mPrev = p_mParkourComponent->mPrev;
      mNext = this->mParkourComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mParkourComponent->mPrev = p_mParkourComponent;
      this->mParkourComponent.mNext = &this->mParkourComponent;
    }
    this->mParkourComponent.m_pPointer = v78;
    if ( v78 )
    {
      v81 = v78->m_SafePointerList.mNode.mPrev;
      v81->mNext = p_mParkourComponent;
      p_mParkourComponent->mPrev = v81;
      this->mParkourComponent.mNext = &v78->m_SafePointerList.mNode;
      v78->m_SafePointerList.mNode.mPrev = p_mParkourComponent;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v88, this->mParams->mSimObject.m_pPointer, 1);
    UFG::SimObjectModifier::AttachComponent(&v88, this->mParkourComponent.m_pPointer, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v88);
    UFG::SimObjectModifier::~SimObjectModifier(&v88);
  }
  mCoverGuid = this->mBodyCollisionMesh->mCoverGuid;
  if ( mCoverGuid )
  {
    v83 = UFG::qMalloc(0x88ui64, "DynamicCoverComponent", 0x800ui64);
    *(_QWORD *)&result[0].mUID = v83;
    if ( v83 )
    {
      UFG::DynamicCoverComponent::DynamicCoverComponent((UFG::DynamicCoverComponent *)v83, mCoverGuid);
      v6 = v84;
    }
    if ( this->mCoverComponent.m_pPointer )
    {
      v85 = p_mCoverComponent->mPrev;
      v86 = this->mCoverComponent.mNext;
      v85->mNext = v86;
      v86->mPrev = v85;
      p_mCoverComponent->mPrev = p_mCoverComponent;
      this->mCoverComponent.mNext = &this->mCoverComponent;
    }
    this->mCoverComponent.m_pPointer = v6;
    if ( v6 )
    {
      v87 = v6->m_SafePointerList.mNode.mPrev;
      v87->mNext = p_mCoverComponent;
      p_mCoverComponent->mPrev = v87;
      this->mCoverComponent.mNext = &v6->m_SafePointerList.mNode;
      v6->m_SafePointerList.mNode.mPrev = p_mCoverComponent;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v88, this->mParams->mSimObject.m_pPointer, 1);
    UFG::SimObjectModifier::AttachComponent(&v88, this->mCoverComponent.m_pPointer, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v88);
    UFG::SimObjectModifier::~SimObjectModifier(&v88);
  }
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&orient);
}

// File Line: 379
// RVA: 0x4507D0
void __fastcall UFG::PhysicsVehicle::~PhysicsVehicle(UFG::PhysicsVehicle *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  hkpRigidBody *mBulletCollider; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *p_mCoverComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ParkourComponent> *p_mParkourComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax

  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsVehicle::`vftable;
  UFG::CustomCollisionFilter::ReleaseSystemId(UFG::BasePhysicsSystem::mInstance->mCollisionFilter, this->mSystemId);
  this->mCollisionMeshBundle.mOwner = 0i64;
  UFG::Simulation::DestroySimComponent(&UFG::gSim, this->mWaterFloatingTrackerComponent);
  p_simComponent = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    mPrev = p_simComponent->mPrev;
    mNext = this->mUserData.simComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_simComponent->mPrev = p_simComponent;
    this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  }
  this->mUserData.simComponent.m_pPointer = 0i64;
  mBulletCollider = this->mBulletCollider;
  if ( mBulletCollider )
    mBulletCollider->m_userData = 0i64;
  UFG::PhysicsVehicle::DeleteHavokComponents(this);
  UFG::Simulation::DestroySimComponent(&UFG::gSim, this->mRigidBody);
  p_mCoverComponent = &this->mCoverComponent;
  if ( this->mCoverComponent.m_pPointer )
  {
    v7 = p_mCoverComponent->mPrev;
    v8 = this->mCoverComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    p_mCoverComponent->mPrev = p_mCoverComponent;
    this->mCoverComponent.mNext = &this->mCoverComponent;
  }
  this->mCoverComponent.m_pPointer = 0i64;
  v9 = p_mCoverComponent->mPrev;
  v10 = this->mCoverComponent.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mCoverComponent->mPrev = p_mCoverComponent;
  this->mCoverComponent.mNext = &this->mCoverComponent;
  p_mParkourComponent = &this->mParkourComponent;
  if ( this->mParkourComponent.m_pPointer )
  {
    v12 = p_mParkourComponent->mPrev;
    v13 = this->mParkourComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    p_mParkourComponent->mPrev = p_mParkourComponent;
    this->mParkourComponent.mNext = &this->mParkourComponent;
  }
  this->mParkourComponent.m_pPointer = 0i64;
  v14 = p_mParkourComponent->mPrev;
  v15 = this->mParkourComponent.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  p_mParkourComponent->mPrev = p_mParkourComponent;
  this->mParkourComponent.mNext = &this->mParkourComponent;
  UFG::qResourceHandle::~qResourceHandle(&this->mCollisionMeshBundle);
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->mDnaDefinition);
  UFG::BasePhysicsObject::~BasePhysicsObject(this);
}

// File Line: 401
// RVA: 0x472BC0
void __fastcall UFG::PhysicsVehicle::Reload(UFG::PhysicsVehicle *this, UFG::qSymbol *physicsPropertiesName)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v4; // rax

  this->mParams->mPhysicsPropertiesName.mUID = physicsPropertiesName->mUID;
  mUID = this->mParams->mPhysicsPropertiesName.mUID;
  if ( mUID )
  {
    v4 = UFG::qBaseTreeRB::Get(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree, mUID);
    if ( v4 )
      UFG::qReflectHandleBase::Init(
        &this->mDnaDefinition,
        this->mDnaDefinition.mTypeUID,
        (unsigned __int64)v4->mNULL.mParent);
  }
  UFG::PhysicsVehicle::LoadProperties(this);
}

// File Line: 414
// RVA: 0x474A10
void __fastcall UFG::PhysicsVehicle::SetControlledByAi(UFG::PhysicsVehicle *this, bool aiControlled)
{
  if ( aiControlled )
  {
    if ( (*((_BYTE *)this + 604) & 0x10) == 0 )
    {
      UFG::PhysicsVehicle::ClearMassScaleForCollisions(this);
      *((_DWORD *)this + 151) |= 0x10u;
    }
  }
  else if ( (*((_BYTE *)this + 604) & 0x10) != 0 )
  {
    UFG::PhysicsVehicle::SetMassScaleForCollisions(this, 1.0, this->mRotMassScaleForCollisions);
    *((_DWORD *)this + 151) &= ~0x10u;
  }
}

// File Line: 437
// RVA: 0x46BAB0
void __fastcall UFG::PhysicsVehicle::LoadProperties(UFG::PhysicsVehicle *this)
{
  float *mData; // rcx
  char *v3; // rax
  UFG::qReflectHandleBase v4; // [rsp+28h] [rbp-30h] BYREF

  UFG::qReflectHandleBase::qReflectHandleBase(&v4);
  v4.mTypeUID = UFG::qStringHash64("UFG::BaseVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v4, v4.mTypeUID, this->mDnaDefinition.mData->mBaseNode.mUID);
  mData = (float *)v4.mData;
  this->mAirSteerYawRate = *((float *)v4.mData[1].mBaseNode.mNeighbours + 1);
  this->mVerticalVelocityDampingDown = mData[33];
  this->mVerticalVelocityDampingUp = mData[32];
  if ( (*((_BYTE *)this + 604) & 0x10) != 0 || mData[28] <= 130.0 )
  {
    this->mHighSpeedGovernor = mData[28];
  }
  else
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)this->mParams);
    UFG::qPrintf("Error: property set %s has mHighSpeedGovernor set higher than %f.\n", v3, DOUBLE_130_0);
    this->mHighSpeedGovernor = 130.0;
    mData = (float *)v4.mData;
  }
  this->mReverseSpeedGovernor = mData[29];
  this->mSuperStopDrag = mData[30];
  this->mPitchStability = mData[35];
  this->mRollStability = mData[34];
  UFG::qReflectHandleBase::~qReflectHandleBase(&v4);
}

// File Line: 469
// RVA: 0x4611E0
void __fastcall UFG::PhysicsVehicle::DeleteHavokComponents(UFG::PhysicsVehicle *this)
{
  UFG::BasePhysicsSystem *v1; // rbx
  UFG::VehicleCollisionListener *mCollisionListener; // rcx
  hkpReorientAction *mReorientActionRoll; // rdx
  hkpReorientAction *v5; // rcx
  hkpReorientAction *mReorientActionPitch; // rcx
  hkpRigidBody *mBody; // rdx
  hkpRigidBody *mBulletCollider; // rdx
  hkpRigidBody *v9; // rcx
  int m_referenceCount; // ebx

  v1 = UFG::BasePhysicsSystem::mInstance;
  mCollisionListener = this->mCollisionListener;
  if ( mCollisionListener )
    ((void (__fastcall *)(UFG::VehicleCollisionListener *, __int64))mCollisionListener->hkpContactListener::vfptr->~hkpContactListener)(
      mCollisionListener,
      1i64);
  mReorientActionRoll = this->mReorientActionRoll;
  this->mCollisionListener = 0i64;
  if ( mReorientActionRoll )
  {
    UFG::BasePhysicsSystem::RemoveAction(v1, mReorientActionRoll);
    v5 = this->mReorientActionRoll;
    if ( v5 )
      v5->vfptr->__vecDelDtor(v5, 1u);
    this->mReorientActionRoll = 0i64;
  }
  mReorientActionPitch = this->mReorientActionPitch;
  if ( mReorientActionPitch )
  {
    mReorientActionPitch->vfptr->__vecDelDtor(mReorientActionPitch, 1u);
    this->mReorientActionPitch = 0i64;
  }
  mBody = this->mRigidBody->mBody;
  if ( mBody )
    UFG::BasePhysicsSystem::RemoveEntity(v1, mBody, 0);
  mBulletCollider = this->mBulletCollider;
  if ( mBulletCollider )
  {
    UFG::BasePhysicsSystem::RemoveEntity(v1, mBulletCollider, 0);
    v9 = this->mBulletCollider;
    m_referenceCount = v9->m_referenceCount;
    hkReferencedObject::removeReference(v9);
    if ( m_referenceCount > 1 )
      this->mBulletCollider->m_collidable.m_shape = UFG::BasePhysicsSystem::mDummyShape;
    this->mBulletCollider = 0i64;
  }
  UFG::PhysicsVehicle::DeactivateVolume(this);
}

// File Line: 519
// RVA: 0x475750
void __fastcall UFG::PhysicsVehicle::SetUserData(UFG::PhysicsVehicle *this, UFG::SimComponent *component)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  hkpRigidBody *mBulletCollider; // rcx

  p_simComponent = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    mPrev = p_simComponent->mPrev;
    mNext = this->mUserData.simComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_simComponent->mPrev = p_simComponent;
    this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  }
  this->mUserData.simComponent.m_pPointer = component;
  if ( component )
  {
    v6 = component->m_SafePointerList.mNode.mPrev;
    v6->mNext = p_simComponent;
    p_simComponent->mPrev = v6;
    this->mUserData.simComponent.mNext = &component->m_SafePointerList.mNode;
    component->m_SafePointerList.mNode.mPrev = p_simComponent;
  }
  mBulletCollider = this->mBulletCollider;
  if ( mBulletCollider )
  {
    if ( component )
      mBulletCollider->m_userData = (unsigned __int64)&this->mUserData;
    else
      mBulletCollider->m_userData = 0i64;
  }
}

// File Line: 532
// RVA: 0x474270
void __fastcall UFG::PhysicsVehicle::RestoreSuperStopDrag(UFG::PhysicsVehicle *this)
{
  UFG::qReflectHandleBase v2; // [rsp+28h] [rbp-30h] BYREF

  UFG::qReflectHandleBase::qReflectHandleBase(&v2);
  v2.mTypeUID = UFG::qStringHash64("UFG::BaseVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v2, v2.mTypeUID, this->mDnaDefinition.mData->mBaseNode.mUID);
  this->mSuperStopDrag = *(float *)v2.mData[1].mBaseNode.mNeighbours;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v2);
}

// File Line: 543
// RVA: 0x4767A0
void __fastcall UFG::PhysicsVehicle::Teleport(UFG::PhysicsVehicle *this, UFG::qMatrix44 *mat)
{
  UFG::qVector4 v2; // xmm3
  UFG::qVector4 v3; // xmm2
  UFG::qVector4 v4; // xmm1

  v2 = mat->v1;
  v3 = mat->v2;
  v4 = mat->v3;
  this->mLastGoodPosition.v0 = mat->v0;
  this->mLastGoodPosition.v1 = v2;
  this->mLastGoodPosition.v2 = v3;
  this->mLastGoodPosition.v3 = v4;
  ((void (__fastcall *)(UFG::PhysicsVehicle *, _QWORD))this->vfptr[1].DebugDraw)(this, 0i64);
}

// File Line: 551
// RVA: 0x4763A0
void __fastcall UFG::PhysicsVehicle::Suspend(UFG::PhysicsVehicle *this)
{
  UFG::BasePhysicsSystem *v1; // rdi
  hkpRigidBody *mBody; // rdx
  hkpRigidBody *mBulletCollider; // rdx
  UFG::WaterFloatingTrackerComponent *mWaterFloatingTrackerComponent; // rcx

  v1 = UFG::BasePhysicsSystem::mInstance;
  mBody = this->mRigidBody->mBody;
  if ( mBody && mBody->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, mBody, 0);
  mBulletCollider = this->mBulletCollider;
  if ( mBulletCollider && mBulletCollider->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(v1, mBulletCollider, 0);
  mWaterFloatingTrackerComponent = this->mWaterFloatingTrackerComponent;
  if ( mWaterFloatingTrackerComponent )
    ((void (__fastcall *)(UFG::WaterFloatingTrackerComponent *))mWaterFloatingTrackerComponent->UFG::WaterFloatingTrackerBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[8].__vecDelDtor)(mWaterFloatingTrackerComponent);
}

// File Line: 580
// RVA: 0x473EA0
void __fastcall UFG::PhysicsVehicle::Restore(UFG::PhysicsVehicle *this)
{
  UFG::BasePhysicsSystem *v2; // rdi
  hkpRigidBody *mBody; // rdx
  hkpRigidBody *mBulletCollider; // rdx
  UFG::WaterFloatingTrackerComponent *mWaterFloatingTrackerComponent; // rcx

  if ( this->mCollisionMeshBundle.mData )
  {
    v2 = UFG::BasePhysicsSystem::mInstance;
    mBody = this->mRigidBody->mBody;
    if ( !mBody->m_world )
      UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, mBody, 1);
    mBulletCollider = this->mBulletCollider;
    if ( !mBulletCollider->m_world )
      UFG::BasePhysicsSystem::AddEntity(v2, mBulletCollider, 1);
    mWaterFloatingTrackerComponent = this->mWaterFloatingTrackerComponent;
    if ( mWaterFloatingTrackerComponent )
      ((void (__fastcall *)(UFG::WaterFloatingTrackerComponent *))mWaterFloatingTrackerComponent->UFG::WaterFloatingTrackerBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[9].__vecDelDtor)(mWaterFloatingTrackerComponent);
  }
}

// File Line: 609
// RVA: 0x46B500
_BOOL8 __fastcall UFG::PhysicsVehicle::IsSuspended(UFG::PhysicsVehicle *this)
{
  return (this->mRigidBody->mFlags & 2) == 0;
}

// File Line: 616
// RVA: 0x473510
void __fastcall UFG::PhysicsVehicle::Reset(UFG::PhysicsVehicle *this, UFG::VehicleResetOptions options)
{
  __m128 z_low; // xmm9
  __m128 v4; // xmm0
  __m128 v5; // xmm7
  float v6; // xmm12_4
  __m128 v7; // xmm6
  float v8; // xmm13_4
  float v9; // xmm5_4
  float z; // xmm14_4
  __m128 v11; // xmm4
  float v12; // xmm1_4
  float v13; // xmm7_4
  float v14; // xmm5_4
  float v15; // xmm4_4
  __m128 v16; // xmm8
  float v17; // xmm9_4
  __m128 v18; // xmm10
  float v19; // xmm2_4
  UFG::BasePhysicsObjectVtbl *vfptr; // rax
  UFG::RigidBodyComponent *mRigidBody; // rcx
  float x; // [rsp+20h] [rbp-D8h] BYREF
  float y; // [rsp+24h] [rbp-D4h]
  int v24; // [rsp+28h] [rbp-D0h]
  int v25; // [rsp+2Ch] [rbp-CCh]
  int v26; // [rsp+30h] [rbp-C8h]
  float v27; // [rsp+34h] [rbp-C4h]
  float v28; // [rsp+38h] [rbp-C0h]
  int v29; // [rsp+3Ch] [rbp-BCh]
  float v30; // [rsp+40h] [rbp-B8h]
  float v31; // [rsp+44h] [rbp-B4h]
  float v32; // [rsp+48h] [rbp-B0h]
  int v33; // [rsp+4Ch] [rbp-ACh]
  float v34; // [rsp+50h] [rbp-A8h]
  float v35; // [rsp+54h] [rbp-A4h]
  float v36; // [rsp+58h] [rbp-A0h]
  int v37; // [rsp+5Ch] [rbp-9Ch]

  if ( options )
  {
    if ( options == RESET_IN_PLACE )
    {
      z_low = (__m128)LODWORD(this->mBodyTransform.v0.z);
      x = this->mBodyTransform.v0.x;
      v24 = z_low.m128_i32[0];
      v4 = z_low;
      v5 = (__m128)LODWORD(x);
      y = this->mBodyTransform.v0.y;
      v4.m128_f32[0] = z_low.m128_f32[0] * 0.0;
      v5.m128_f32[0] = x - (float)(z_low.m128_f32[0] * 0.0);
      v7 = v4;
      v6 = this->mBodyTransform.v3.x;
      v7.m128_f32[0] = (float)(z_low.m128_f32[0] * 0.0) - y;
      v11 = v5;
      v8 = this->mBodyTransform.v3.y;
      v9 = (float)(y * 0.0) - (float)(x * 0.0);
      z = this->mBodyTransform.v3.z;
      v11.m128_f32[0] = (float)((float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(v7.m128_f32[0] * v7.m128_f32[0]))
                      + (float)(v9 * v9);
      if ( v11.m128_f32[0] == 0.0 )
        v12 = 0.0;
      else
        v12 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
      v13 = v5.m128_f32[0] * v12;
      v14 = v9 * v12;
      v7.m128_f32[0] = v7.m128_f32[0] * v12;
      v16 = v7;
      v15 = (float)(v14 * y) - (float)(v13 * z_low.m128_f32[0]);
      v16.m128_f32[0] = (float)(v7.m128_f32[0] * z_low.m128_f32[0]) - (float)(v14 * x);
      v18 = v16;
      v17 = (float)(v13 * x) - (float)(v7.m128_f32[0] * y);
      v18.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v15 * v15)) + (float)(v17 * v17);
      if ( v18.m128_f32[0] == 0.0 )
        v19 = 0.0;
      else
        v19 = 1.0 / _mm_sqrt_ps(v18).m128_f32[0];
      vfptr = this->vfptr;
      v26 = v7.m128_i32[0];
      v27 = v13;
      v25 = 0;
      v29 = 0;
      v33 = 0;
      v28 = v14;
      v34 = v6;
      v35 = v8;
      v30 = v15 * v19;
      v31 = v16.m128_f32[0] * v19;
      v36 = z;
      v37 = 1065353216;
      v32 = v17 * v19;
      ((void (__fastcall *)(UFG::PhysicsVehicle *, float *))vfptr[3].DebugDraw)(this, &x);
    }
  }
  else
  {
    ((void (__fastcall *)(UFG::PhysicsVehicle *, UFG::qMatrix44 *))this->vfptr[3].DebugDraw)(
      this,
      &this->mLastGoodPosition);
  }
  mRigidBody = this->mRigidBody;
  this->mSpeedKPH = 0.0;
  UFG::RigidBody::SetVelocity(mRigidBody, &UFG::qVector3::msZero);
  UFG::RigidBody::SetAngularVelocity(this->mRigidBody, &UFG::qVector3::msZero);
}

// File Line: 657
// RVA: 0x47AE40
void __fastcall UFG::PhysicsVehicle::Update(
        UFG::PhysicsVehicle *this,
        UFG::qMatrix44 *targetTransform,
        UFG::VehicleInput *driverInput,
        float deltaTime)
{
  hkpRigidBody *mBody; // rdi
  int v7; // eax
  float x; // xmm7_4
  float y; // xmm6_4
  float z; // xmm8_4
  UFG::PhysicsVehicle::Lod mCurrentLod; // eax
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  UFG::qVector3 result; // [rsp+20h] [rbp-48h] BYREF

  mBody = this->mRigidBody->mBody;
  if ( !mBody )
  {
    UFG::qPrintf("PhysicsVehicle %x is missing its rigid body\n", this);
    return;
  }
  v7 = *((_DWORD *)driverInput + 4);
  if ( (v7 & 0x200) != 0 || (v7 & 0x400) != 0 || this->mIsProxy )
  {
    if ( hkpRigidBody::isDeactivationEnabled(mBody) )
    {
      hkpRigidBody::enableDeactivation(mBody, 0);
      hkpEntity::activate(mBody);
    }
  }
  else if ( !hkpRigidBody::isDeactivationEnabled(mBody) )
  {
    hkpRigidBody::enableDeactivation(mBody, 1);
  }
  x = this->mBodyTransform.v0.x;
  y = this->mBodyTransform.v0.y;
  z = this->mBodyTransform.v0.z;
  UFG::RigidBody::GetVelocity(this->mRigidBody, &result);
  mCurrentLod = this->mCurrentLod;
  this->mSpeedKPH = (float)((float)((float)(result.y * y) + (float)(result.x * x)) + (float)(result.z * z)) * 3.5999999;
  if ( mCurrentLod > LOD_UNINITIALIZED )
  {
    if ( mCurrentLod > LOD_MEDIUM )
    {
      if ( mCurrentLod == LOD_HIGH )
      {
        v12 = this->mBodyTransform.v1;
        v13 = this->mBodyTransform.v2;
        v14 = this->mBodyTransform.v3;
        v15 = this->mBodyTransform.v0;
        goto LABEL_15;
      }
      if ( mCurrentLod != LOD_NIS )
        return;
    }
    v12 = targetTransform->v1;
    v13 = targetTransform->v2;
    v14 = targetTransform->v3;
    v15 = targetTransform->v0;
LABEL_15:
    this->mTargetTransform.v0 = v15;
    this->mTargetTransform.v1 = v12;
    this->mTargetTransform.v2 = v13;
    this->mTargetTransform.v3 = v14;
  }
}

// File Line: 747
// RVA: 0x461FB0
void __fastcall UFG::PhysicsVehicle::DoKeyframes(UFG::PhysicsVehicle *this, float deltaTime)
{
  UFG::PhysicsVehicle::Lod mCurrentLod; // ecx
  float v4; // xmm2_4
  hkVector4f nextPosition; // [rsp+20h] [rbp-A8h] BYREF
  hkQuaternionf nextOrientation; // [rsp+30h] [rbp-98h] BYREF
  hkQsTransformf v7; // [rsp+40h] [rbp-88h] BYREF
  hkTransformf transform; // [rsp+70h] [rbp-58h] BYREF

  mCurrentLod = this->mCurrentLod;
  if ( ((mCurrentLod - 1) & 0xFFFFFFFC) == 0 && mCurrentLod != LOD_HIGH && this->mRigidBody->mBody && !this->mIsProxy )
  {
    hkTransformf::set4x4ColumnMajor(&transform, &this->mTargetTransform.v0.x);
    hkQsTransformf::setFromTransformNoScale(&v7, &transform);
    nextPosition.m_quad = (__m128)v7.m_translation;
    nextOrientation.m_vec.m_quad = (__m128)v7.m_rotation;
    if ( deltaTime <= 0.0005 )
      v4 = FLOAT_2000_0;
    else
      v4 = 1.0 / deltaTime;
    hkpKeyFrameUtility::applyHardKeyFrame(&nextPosition, &nextOrientation, v4, this->mRigidBody->mBody);
  }
}

// File Line: 779
// RVA: 0x471F50
void __fastcall UFG::PhysicsWheeledVehicle::QueueAsyncQueryForGroundFixup(
        UFG::PhysicsWheeledVehicle *this,
        bool useLongRaysToFindGround,
        bool hasDriver,
        bool isMoving)
{
  UFG::PhysicsVehicle::Lod mCurrentLod; // eax
  hkpRigidBody *mBody; // rcx
  __m128 y_low; // xmm3
  float v11; // xmm0_4
  float x; // eax
  int v13; // xmm2_4
  float z; // xmm0_4
  float w; // xmm1_4
  UFG::BasePhysicsSystem *v16; // rdi
  UFG::SimComponent *m_pPointer; // r14
  float v18; // xmm11_4
  float v19; // xmm11_4
  __int64 v20; // rbp
  UFG::qSafeArray<float,4> *p_mRestingSuspensionLength; // r15
  float y; // xmm7_4
  float v23; // xmm6_4
  float v24; // xmm8_4
  float v25; // xmm2_4
  float v26; // xmm9_4
  float v27; // xmm3_4
  UFG::BasePhysicsSystemVtbl *vfptr; // rax
  float v29; // xmm5_4
  float v30; // xmm9_4
  float v31; // xmm0_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  float v34; // xmm3_4
  UFG::BasePhysicsSystemVtbl *v35; // rax
  float v36; // [rsp+40h] [rbp-A8h] BYREF
  float v37; // [rsp+44h] [rbp-A4h]
  float v38; // [rsp+48h] [rbp-A0h]
  float v39; // [rsp+50h] [rbp-98h] BYREF
  float v40; // [rsp+54h] [rbp-94h]
  float v41; // [rsp+58h] [rbp-90h]
  hkBool result; // [rsp+F0h] [rbp+8h] BYREF

  mCurrentLod = this->mCurrentLod;
  *((_DWORD *)this + 274) &= 0xFFFFFFF8;
  if ( (unsigned int)(mCurrentLod - 3) <= 1 || this->mBodyTransform.v2.z < 0.2 )
    return;
  mBody = this->mRigidBody->mBody;
  if ( !mBody || hkpEntity::isActive(mBody, &result)->m_bool )
  {
    if ( !hasDriver )
      goto LABEL_9;
  }
  else if ( !hasDriver )
  {
    return;
  }
  if ( !isMoving )
  {
LABEL_9:
    y_low = (__m128)LODWORD(this->mLastFixupPosition.y);
    v11 = this->mLastFixupPosition.z - this->mTargetTransform.v3.z;
    y_low.m128_f32[0] = (float)((float)((float)((float)(y_low.m128_f32[0] - this->mTargetTransform.v3.y)
                                              * (float)(y_low.m128_f32[0] - this->mTargetTransform.v3.y))
                                      + (float)((float)(this->mLastFixupPosition.x - this->mTargetTransform.v3.x)
                                              * (float)(this->mLastFixupPosition.x - this->mTargetTransform.v3.x)))
                              + (float)(v11 * v11))
                      + (float)((float)(this->mLastFixupPosition.w - this->mTargetTransform.v3.w)
                              * (float)(this->mLastFixupPosition.w - this->mTargetTransform.v3.w));
    if ( _mm_sqrt_ps(y_low).m128_f32[0] <= 0.001 )
      return;
  }
  x = this->mTargetTransform.v3.x;
  v13 = SLODWORD(this->mTargetTransform.v3.y);
  z = this->mTargetTransform.v3.z;
  w = this->mTargetTransform.v3.w;
  this->mLastFixupPosition.y = *(float *)&v13;
  this->mLastFixupPosition.z = z;
  this->mLastFixupPosition.x = x;
  this->mLastFixupPosition.w = w;
  if ( this != (UFG::PhysicsWheeledVehicle *)-8i64 )
  {
    v16 = UFG::BasePhysicsSystem::mInstance;
    m_pPointer = this->mUserData.simComponent.m_pPointer;
    if ( useLongRaysToFindGround )
      v18 = FLOAT_2_0;
    else
      v18 = 0.0;
    v19 = v18 + 2.0;
    if ( this->mCurrentLod == LOD_MEDIUM && (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) > 2 )
    {
      v20 = 0i64;
      p_mRestingSuspensionLength = &this->mRestingSuspensionLength;
      do
      {
        y = this->mBodyTransform.v2.y;
        v23 = this->mBodyTransform.v2.x;
        v24 = this->mBodyTransform.v2.z;
        v25 = this->mHardPointChassisSpace[v20].m_quad.m128_f32[0];
        v26 = this->mHardPointChassisSpace[v20].m_quad.m128_f32[1];
        v27 = this->mHardPointChassisSpace[v20].m_quad.m128_f32[2];
        vfptr = v16->vfptr;
        v29 = (float)((float)((float)(v25 * this->mTargetTransform.v0.y) + (float)(v26 * this->mTargetTransform.v1.y))
                    + (float)(v27 * this->mTargetTransform.v2.y))
            + this->mTargetTransform.v3.y;
        v30 = (float)((float)((float)((float)(v26 * this->mTargetTransform.v1.z)
                                    + (float)(v25 * this->mTargetTransform.v0.z))
                            + (float)(v27 * this->mTargetTransform.v2.z))
                    + this->mTargetTransform.v3.z)
            + (float)(v24 * 2.0);
        v31 = p_mRestingSuspensionLength->array[0] + this->mWheelRadius;
        v32 = (float)(v23 * 2.0)
            + (float)((float)((float)((float)(this->mHardPointChassisSpace[v20].m_quad.m128_f32[1]
                                            * this->mTargetTransform.v1.x)
                                    + (float)(v25 * this->mTargetTransform.v0.x))
                            + (float)(v27 * this->mTargetTransform.v2.x))
                    + this->mTargetTransform.v3.x);
        v40 = v29 + (float)(y * 2.0);
        v39 = v32;
        v41 = v30;
        LODWORD(v33) = COERCE_UNSIGNED_INT(v31 + v19) ^ _xmm[0];
        v36 = v32 + (float)(v23 * v33);
        v37 = v40 + (float)(y * v33);
        v38 = v30 + (float)(v24 * v33);
        vfptr->CastAsyncRay(
          v16,
          (UFG::qVector3 *)&v39,
          (UFG::qVector3 *)&v36,
          17u,
          UFG::PhysicsWheeledVehicle::ApplyGroundFixup,
          m_pPointer,
          (void *)(unsigned int)v20);
        v20 = (unsigned int)(v20 + 1);
        p_mRestingSuspensionLength = (UFG::qSafeArray<float,4> *)((char *)p_mRestingSuspensionLength + 4);
      }
      while ( (unsigned int)v20 < (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) );
    }
    else
    {
      v34 = this->mTargetTransform.v3.x;
      v35 = UFG::BasePhysicsSystem::mInstance->vfptr;
      v37 = *(float *)&v13;
      v41 = z - 4.0;
      v36 = v34;
      v38 = z + 2.0;
      v39 = v34;
      v40 = *(float *)&v13;
      v35->CastAsyncRay(
        UFG::BasePhysicsSystem::mInstance,
        (UFG::qVector3 *)&v36,
        (UFG::qVector3 *)&v39,
        17u,
        UFG::PhysicsWheeledVehicle::ApplyGroundFixup,
        m_pPointer,
        (void *)-1i64);
    }
  }
}

// File Line: 873
// RVA: 0x457230
void __fastcall UFG::PhysicsWheeledVehicle::ApplyGroundFixup(
        UFG::RayCastData *data,
        UFG::SimComponent *simComponent,
        void *callbackUserData)
{
  int v5; // esi
  int v6; // r14d
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // r8
  bool hit; // al
  float y; // xmm1_4
  float z; // xmm0_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm8_4
  float x; // xmm12_4
  float v18; // xmm6_4
  __m128 v19; // xmm7
  float v20; // xmm5_4
  __m128 v21; // xmm4
  float v22; // xmm0_4
  __m128 v23; // xmm4
  float v24; // xmm11_4
  float v25; // xmm10_4
  float v26; // xmm11_4
  float v27; // xmm10_4
  float v28; // xmm6_4
  float v29; // xmm3_4
  __m128 v30; // xmm7
  __m128 v31; // xmm5
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  __int64 v45; // rdx
  int v46; // r9d
  int v47; // edx
  int v48; // xmm15_4
  __m128 mPrev_high; // xmm2
  int mNext; // xmm14_4
  __int64 v51; // rax
  __int64 v52; // rcx
  float v53; // xmm9_4
  float v54; // xmm4_4
  __int64 v55; // rax
  __int64 v56; // rcx
  __int64 v57; // rax
  __int64 v58; // rcx
  float v59; // xmm0_4
  float v60; // xmm9_4
  __m128 v61; // xmm11
  float v62; // xmm3_4
  float v63; // xmm12_4
  float v64; // xmm5_4
  __m128 v65; // xmm6
  float v66; // xmm4_4
  __m128 v67; // xmm10
  float v68; // xmm1_4
  float v69; // xmm5_4
  float v70; // xmm6_4
  float v71; // xmm4_4
  float v72; // xmm10_4
  float v73; // xmm3_4
  __m128 v74; // xmm2
  float v75; // xmm1_4
  float v76; // xmm3_4
  __m128 v77; // xmm10
  float v78; // xmm12_4
  __m128 v79; // xmm2
  float v80; // xmm1_4
  float v81; // xmm2_4
  float v82; // xmm7_4
  __m128 v83; // xmm3
  __m128 v84; // xmm9
  float v85; // xmm1_4
  float v86; // xmm7_4
  float v87; // xmm8_4
  float v88; // xmm9_4
  __int64 v89; // r9
  float v90; // xmm2_4
  float *v91; // rax
  unsigned __int64 v92; // rcx
  __int64 v93; // rdx
  float *v94; // rcx
  float v95; // xmm0_4
  float v96; // xmm8_4
  float v97; // xmm9_4
  __m128 mPrev_low; // xmm10
  float v99; // xmm9_4
  __m128 v100; // xmm3
  float v101; // xmm2_4
  float v102; // xmm12_4
  float v103; // xmm11_4
  float v104; // xmm2_4
  float v105; // xmm12_4
  float v106; // xmm11_4
  float v107; // xmm8_4
  float v108; // xmm9_4
  float v109; // xmm10_4
  float v110; // xmm3_4
  float v111; // xmm13_4
  float v112; // xmm7_4
  float v113; // xmm3_4
  __m128 v114; // xmm5
  float v115; // xmm6_4
  __m128 v116; // xmm2
  __m128 v117; // xmm4
  float v118; // xmm13_4
  __m128 v119; // xmm12
  float v120; // xmm13_4
  float v121; // xmm5_4
  __m128 v122; // xmm6
  float v123; // xmm7_4
  __m128 v124; // xmm2
  float v125; // xmm1_4
  float v126; // xmm7_4
  float v127; // xmm6_4
  float v128; // xmm5_4
  float v129; // xmm9_4
  __m128 v130; // xmm10
  float v131; // xmm3_4
  __m128 v132; // xmm2
  float v133; // xmm8_4
  float v134; // xmm0_4
  float v135; // xmm2_4
  float v136; // xmm1_4
  float v137; // xmm3_4
  float v138; // xmm9_4
  float v139; // xmm10_4
  float v140; // [rsp+20h] [rbp-E0h]
  int v141; // [rsp+28h] [rbp-D8h]
  unsigned int v142; // [rsp+2Ch] [rbp-D4h]
  int v143; // [rsp+30h] [rbp-D0h]
  float v144; // [rsp+34h] [rbp-CCh]
  float v145; // [rsp+38h] [rbp-C8h]
  float v146; // [rsp+3Ch] [rbp-C4h]
  float v147; // [rsp+40h] [rbp-C0h]
  float v148; // [rsp+44h] [rbp-BCh]
  float v149; // [rsp+48h] [rbp-B8h]
  float v150; // [rsp+4Ch] [rbp-B4h]
  float v151; // [rsp+50h] [rbp-B0h]
  float v152; // [rsp+54h] [rbp-ACh]
  float v153; // [rsp+58h] [rbp-A8h]
  float v154; // [rsp+5Ch] [rbp-A4h]
  float v155; // [rsp+60h] [rbp-A0h]
  float v156; // [rsp+64h] [rbp-9Ch]
  float v157; // [rsp+68h] [rbp-98h]
  float v158; // [rsp+6Ch] [rbp-94h]
  float v159; // [rsp+70h] [rbp-90h]
  float v160; // [rsp+74h] [rbp-8Ch]
  float v161; // [rsp+78h] [rbp-88h]
  float v162; // [rsp+7Ch] [rbp-84h]
  int v163[12]; // [rsp+80h] [rbp-80h] BYREF
  float v164; // [rsp+178h] [rbp+78h]
  float v165; // [rsp+188h] [rbp+88h]

  if ( simComponent )
  {
    v5 = 1;
    v6 = (int)callbackUserData;
    Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    mPrev = simComponent[10].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
    {
      v8 = 0i64;
      if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
        v8 = simComponent[10].m_SafePointerList.mNode.mPrev;
      if ( v8 && (unsigned int)(HIDWORD(v8[34].mPrev) - 1) <= 1 )
      {
        LODWORD(v8[68].mNext) ^= ((unsigned __int8)LODWORD(v8[68].mNext) ^ (unsigned __int8)(LODWORD(v8[68].mNext) + 1)) & 7;
        hit = data->hit;
        if ( v6 == -1 )
        {
          LOBYTE(v8[58].mPrev) = hit;
          y = data->point.y;
          z = data->point.z;
          *(float *)&v8[55].mPrev = data->point.x;
          *((float *)&v8[55].mPrev + 1) = y;
          *(float *)&v8[55].mNext = z;
          if ( data->hit && data->normal.z >= 0.69999999 )
          {
            v12 = *((float *)&v8[24].mPrev + 1);
            v13 = *(float *)&v8[24].mNext;
            v14 = *(float *)&v8[24].mPrev;
            v15 = data->normal.y;
            v16 = data->normal.z;
            x = data->normal.x;
            v19 = (__m128)LODWORD(v16);
            v18 = (float)(v15 * v13) - (float)(v16 * v12);
            v19.m128_f32[0] = (float)(v16 * v14) - (float)(v13 * x);
            v20 = (float)(v12 * x) - (float)(v15 * v14);
            v21 = v19;
            v21.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v18 * v18))
                            + (float)(v20 * v20);
            if ( v21.m128_f32[0] == 0.0 )
            {
              v23 = 0i64;
            }
            else
            {
              v22 = _mm_sqrt_ps(v21).m128_f32[0];
              v23 = (__m128)(unsigned int)FLOAT_1_0;
              v23.m128_f32[0] = 1.0 / v22;
            }
            v24 = v23.m128_f32[0];
            v25 = v23.m128_f32[0];
            v23.m128_f32[0] = v23.m128_f32[0] * v20;
            v26 = v24 * v19.m128_f32[0];
            v27 = v25 * v18;
            v30 = v23;
            v28 = (float)(v16 * v26) - (float)(v15 * v23.m128_f32[0]);
            v29 = (float)(v15 * v27) - (float)(v26 * x);
            v30.m128_f32[0] = (float)(v23.m128_f32[0] * x) - (float)(v16 * v27);
            v31 = v30;
            v31.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v28 * v28))
                            + (float)(v29 * v29);
            if ( v31.m128_f32[0] == 0.0 )
              v32 = 0.0;
            else
              v32 = 1.0 / _mm_sqrt_ps(v31).m128_f32[0];
            v33 = v32;
            v34 = v32;
            v35 = v32 * v29;
            v36 = *((float *)&v8[68].mPrev + 1) + *(float *)&v8[68].mPrev;
            *(float *)&v8[24].mPrev = v33 * v28;
            *((float *)&v8[24].mPrev + 1) = v34 * v30.m128_f32[0];
            *(float *)&v8[24].mNext = v35;
            HIDWORD(v8[24].mNext) = 0;
            HIDWORD(v8[25].mNext) = 0;
            *(float *)&v8[25].mPrev = v27;
            *((float *)&v8[25].mPrev + 1) = v26;
            LODWORD(v8[25].mNext) = v23.m128_i32[0];
            v37 = data->normal.x;
            v38 = data->normal.y;
            v39 = data->normal.z;
            HIDWORD(v8[26].mNext) = 0;
            *(float *)&v8[26].mPrev = v37;
            *((float *)&v8[26].mPrev + 1) = v38;
            *(float *)&v8[26].mNext = v39;
            v40 = data->point.z;
            v41 = data->point.x;
            v42 = data->point.y;
            HIDWORD(v8[27].mNext) = 1065353216;
            *(float *)&v8[27].mPrev = v41;
            *((float *)&v8[27].mPrev + 1) = v42;
            *(float *)&v8[27].mNext = (float)(v36 * 0.5) + v40;
          }
        }
        else
        {
          *((_BYTE *)&v8[58].mPrev + v6) = hit;
          v43 = data->point.y;
          v44 = data->point.z;
          v45 = 3i64 * v6;
          *((_DWORD *)&v8[55].mPrev + v45) = LODWORD(data->point.x);
          *((float *)&v8[55].mPrev + v45 + 1) = v43;
          *((float *)&v8[55].mNext + v45) = v44;
          v46 = HIDWORD(v8[37].mNext) & 7;
          if ( ((__int64)v8[68].mNext & 7) == v46 )
          {
            v47 = 0;
            if ( LOBYTE(v8[58].mPrev) )
            {
              v48 = (int)v8[55].mPrev;
              mPrev_high = (__m128)HIDWORD(v8[55].mPrev);
              mNext = (int)v8[55].mNext;
              v47 = 1;
              v141 = v48;
              v142 = mPrev_high.m128_u32[0];
              v143 = mNext;
            }
            else
            {
              mNext = v143;
              mPrev_high = (__m128)v142;
              v48 = v141;
            }
            v164 = mPrev_high.m128_f32[0];
            if ( BYTE1(v8[58].mPrev) )
            {
              v51 = v47++;
              v52 = 3 * v51;
              *(&v141 + v52) = HIDWORD(v8[55].mNext);
              *(&v142 + v52) = (unsigned int)v8[56].mPrev;
              *(&v143 + v52) = HIDWORD(v8[56].mPrev);
              mPrev_high = (__m128)v142;
              mNext = v143;
              v48 = v141;
              v164 = *(float *)&v142;
            }
            v53 = *(float *)&v8[68].mPrev;
            v54 = *((float *)&v8[68].mPrev + 1);
            v155 = (float)((float)(*(float *)&v8[SLODWORD(v8[3].mPrev[4].mNext) + 42].mPrev
                                 / (float)(*(float *)&v8[SLODWORD(v8[3].mPrev[4].mNext) + 42].mPrev
                                         - *(float *)&v8[SLODWORD(v8[3].mPrev[5].mPrev) + 42].mPrev))
                         * (float)(v54 - v53))
                 + v53;
            if ( v46 == 4 )
            {
              if ( BYTE3(v8[58].mPrev) )
              {
                v55 = v47++;
                v56 = 3 * v55;
                *(&v141 + v56) = HIDWORD(v8[57].mPrev);
                *(&v142 + v56) = (unsigned int)v8[57].mNext;
                *(&v143 + v56) = HIDWORD(v8[57].mNext);
                mPrev_high.m128_i32[0] = v142;
                mNext = v143;
                v48 = v141;
                v164 = *(float *)&v142;
              }
              if ( BYTE2(v8[58].mPrev) )
              {
                v57 = v47++;
                v58 = 3 * v57;
                *(&v141 + v58) = (int)v8[56].mNext;
                *(&v142 + v58) = HIDWORD(v8[56].mNext);
                *(&v143 + v58) = (int)v8[57].mPrev;
                mPrev_high.m128_i32[0] = v142;
                mNext = v143;
                v48 = v141;
                v164 = *(float *)&v142;
              }
              if ( v47 > 2 )
              {
                v61 = (__m128)LODWORD(v144);
                v59 = *(float *)&mNext + v53;
                v60 = v53 + v146;
                v153 = v152 + v54;
                v61.m128_f32[0] = v144 - *(float *)&v48;
                v158 = v149 + v54;
                v65 = v61;
                v154 = (float)(v149 + v54) - v59;
                v62 = v145 - mPrev_high.m128_f32[0];
                v63 = v148 - mPrev_high.m128_f32[0];
                v165 = v60 - v59;
                v159 = v147 - *(float *)&v48;
                v64 = (float)((float)(v60 - v59) * (float)(v148 - mPrev_high.m128_f32[0]))
                    - (float)((float)(v145 - mPrev_high.m128_f32[0]) * v154);
                v157 = v144 - *(float *)&v48;
                v65.m128_f32[0] = (float)((float)(v144 - *(float *)&v48) * v154)
                                - (float)((float)(v60 - v59) * (float)(v147 - *(float *)&v48));
                v67 = v65;
                v66 = (float)((float)(v145 - mPrev_high.m128_f32[0]) * (float)(v147 - *(float *)&v48))
                    - (float)((float)(v144 - *(float *)&v48) * (float)(v148 - mPrev_high.m128_f32[0]));
                v67.m128_f32[0] = (float)((float)(v65.m128_f32[0] * v65.m128_f32[0]) + (float)(v64 * v64))
                                + (float)(v66 * v66);
                if ( v67.m128_f32[0] == 0.0 )
                  v68 = 0.0;
                else
                  v68 = 1.0 / _mm_sqrt_ps(v67).m128_f32[0];
                v69 = v64 * v68;
                v70 = v65.m128_f32[0] * v68;
                v71 = v66 * v68;
                v161 = v69;
                v162 = v70;
                *(float *)v163 = v71;
                if ( v47 == 4 )
                {
                  v156 = v151 - mPrev_high.m128_f32[0];
                  v160 = v150 - *(float *)&v48;
                  v72 = (float)(v165 * (float)(v151 - mPrev_high.m128_f32[0])) - (float)(v62 * (float)(v153 - v59));
                  v140 = v153 - v59;
                  v61.m128_f32[0] = (float)(v61.m128_f32[0] * (float)(v153 - v59))
                                  - (float)(v165 * (float)(v150 - *(float *)&v48));
                  v74 = v61;
                  v73 = (float)(v62 * (float)(v150 - *(float *)&v48)) - (float)(v157 * v156);
                  v74.m128_f32[0] = (float)((float)(v61.m128_f32[0] * v61.m128_f32[0]) + (float)(v72 * v72))
                                  + (float)(v73 * v73);
                  if ( v74.m128_f32[0] == 0.0 )
                    v75 = 0.0;
                  else
                    v75 = 1.0 / _mm_sqrt_ps(v74).m128_f32[0];
                  *(float *)&v163[3] = v73 * v75;
                  *(float *)&v163[1] = v72 * v75;
                  v76 = (float)(v154 * v156) - (float)(v63 * v140);
                  *(float *)&v163[2] = v61.m128_f32[0] * v75;
                  v77 = (__m128)LODWORD(v159);
                  v77.m128_f32[0] = (float)(v159 * v140) - (float)(v154 * v160);
                  v78 = (float)(v63 * v160) - (float)(v159 * v156);
                  v79 = v77;
                  v79.m128_f32[0] = (float)((float)(v77.m128_f32[0] * v77.m128_f32[0]) + (float)(v76 * v76))
                                  + (float)(v78 * v78);
                  if ( v79.m128_f32[0] == 0.0 )
                    v80 = 0.0;
                  else
                    v80 = 1.0 / _mm_sqrt_ps(v79).m128_f32[0];
                  v5 = 4;
                  *(float *)&v163[5] = v77.m128_f32[0] * v80;
                  *(float *)&v163[4] = v76 * v80;
                  *(float *)&v163[6] = v78 * v80;
                  v81 = (float)((float)(v158 - v60) * (float)(v151 - v145))
                      - (float)((float)(v148 - v145) * (float)(v153 - v60));
                  v83 = (__m128)COERCE_UNSIGNED_INT(v147 - v144);
                  v82 = (float)((float)(v148 - v145) * (float)(v150 - v144))
                      - (float)(v83.m128_f32[0] * (float)(v151 - v145));
                  v83.m128_f32[0] = (float)(v83.m128_f32[0] * (float)(v153 - v60))
                                  - (float)((float)(v158 - v60) * (float)(v150 - v144));
                  v84 = v83;
                  v84.m128_f32[0] = (float)((float)(v83.m128_f32[0] * v83.m128_f32[0]) + (float)(v81 * v81))
                                  + (float)(v82 * v82);
                  if ( v84.m128_f32[0] == 0.0 )
                    v85 = 0.0;
                  else
                    v85 = 1.0 / _mm_sqrt_ps(v84).m128_f32[0];
                  *(float *)&v163[7] = v81 * v85;
                  *(float *)&v163[8] = v83.m128_f32[0] * v85;
                  *(float *)&v163[9] = v82 * v85;
                }
                v86 = *(float *)&v8[26].mPrev;
                v87 = *((float *)&v8[26].mPrev + 1);
                v88 = *(float *)&v8[26].mNext;
                v89 = 0i64;
                v90 = (float)((float)(v87 * v70) + (float)(v86 * v69)) + (float)(v71 * v88);
                if ( v5 >= 4i64 )
                {
                  v91 = (float *)v163;
                  v92 = ((unsigned __int64)(v5 - 4i64) >> 2) + 1;
                  v89 = 4 * v92;
                  do
                  {
                    if ( (float)((float)((float)(*(v91 - 2) * v86) + (float)(*(v91 - 1) * v87)) + (float)(*v91 * v88)) > v90 )
                    {
                      v69 = *(v91 - 2);
                      v70 = *(v91 - 1);
                      v71 = *v91;
                      v90 = (float)((float)(v69 * v86) + (float)(v70 * v87)) + (float)(*v91 * v88);
                    }
                    if ( (float)((float)((float)(v91[1] * v86) + (float)(v91[2] * v87)) + (float)(v91[3] * v88)) > v90 )
                    {
                      v69 = v91[1];
                      v70 = v91[2];
                      v71 = v91[3];
                      v90 = (float)((float)(v69 * v86) + (float)(v70 * v87)) + (float)(v71 * v88);
                    }
                    if ( (float)((float)((float)(v91[4] * v86) + (float)(v91[5] * v87)) + (float)(v91[6] * v88)) > v90 )
                    {
                      v69 = v91[4];
                      v70 = v91[5];
                      v71 = v91[6];
                      v90 = (float)((float)(v69 * v86) + (float)(v70 * v87)) + (float)(v71 * v88);
                    }
                    if ( (float)((float)((float)(v91[7] * v86) + (float)(v91[8] * v87)) + (float)(v91[9] * v88)) > v90 )
                    {
                      v69 = v91[7];
                      v70 = v91[8];
                      v71 = v91[9];
                      v90 = (float)((float)(v69 * v86) + (float)(v70 * v87)) + (float)(v71 * v88);
                    }
                    v91 += 12;
                    --v92;
                  }
                  while ( v92 );
                }
                if ( v89 < v5 )
                {
                  v93 = v5 - v89;
                  v94 = (float *)&v163[3 * v89];
                  do
                  {
                    if ( (float)((float)((float)(*(v94 - 2) * v86) + (float)(*(v94 - 1) * v87)) + (float)(*v94 * v88)) > v90 )
                    {
                      v69 = *(v94 - 2);
                      v70 = *(v94 - 1);
                      v71 = *v94;
                      v90 = (float)((float)(v69 * v86) + (float)(v70 * v87)) + (float)(*v94 * v88);
                    }
                    v94 += 3;
                    --v93;
                  }
                  while ( v93 );
                }
                mPrev_low = (__m128)LODWORD(v8[24].mPrev);
                v95 = *((float *)&v8[24].mPrev + 1);
                v96 = (float)(v95 * v69) - (float)(mPrev_low.m128_f32[0] * v70);
                v97 = *(float *)&v8[24].mNext;
                mPrev_low.m128_f32[0] = (float)(mPrev_low.m128_f32[0] * v71) - (float)(v97 * v69);
                v99 = (float)(v97 * v70) - (float)(v95 * v71);
                v100 = mPrev_low;
                v100.m128_f32[0] = (float)((float)(mPrev_low.m128_f32[0] * mPrev_low.m128_f32[0]) + (float)(v99 * v99))
                                 + (float)(v96 * v96);
                if ( v100.m128_f32[0] == 0.0 )
                  v101 = 0.0;
                else
                  v101 = 1.0 / _mm_sqrt_ps(v100).m128_f32[0];
                v102 = v101;
                v103 = v101;
                v104 = v101 * v96;
                v105 = v102 * mPrev_low.m128_f32[0];
                v106 = v103 * v99;
                v107 = (float)(v105 * v71) - (float)(v104 * v70);
                v108 = (float)(v104 * v69) - (float)(v106 * v71);
                v109 = (float)(v106 * v70) - (float)(v105 * v69);
                v110 = (float)((float)(v108 * v108) + (float)(v107 * v107)) + (float)(v109 * v109);
                if ( v110 == 0.0 )
                  v111 = 0.0;
                else
                  v111 = 1.0 / fsqrt(v110);
                v112 = (float)((float)((float)(*(float *)&v8[27].mNext - *(float *)&mNext)
                                     - (float)((float)((float)((float)((float)(*((float *)&v8[27].mPrev + 1) - v164)
                                                                     * v70)
                                                             + (float)((float)(*(float *)&v8[27].mPrev - *(float *)&v48)
                                                                     * v69))
                                                     + (float)((float)(*(float *)&v8[27].mNext - *(float *)&mNext) * v71))
                                             * v71))
                             + *(float *)&mNext)
                     + v155;
                *(float *)&v8[24].mPrev = v111 * v107;
                *((float *)&v8[24].mPrev + 1) = v111 * v108;
                *(float *)&v8[24].mNext = v111 * v109;
                HIDWORD(v8[24].mNext) = 0;
                HIDWORD(v8[25].mNext) = 0;
                *(float *)&v8[25].mPrev = v106;
                *((float *)&v8[25].mPrev + 1) = v105;
                *(float *)&v8[25].mNext = v104;
                HIDWORD(v8[26].mNext) = 0;
                *(float *)&v8[26].mPrev = v69;
                *((float *)&v8[26].mPrev + 1) = v70;
                *(float *)&v8[26].mNext = v71;
                *(float *)&v8[27].mNext = v112;
              }
            }
            else if ( v46 == 2 && v47 == 2 )
            {
              v114 = mPrev_high;
              v113 = *(float *)&v48 - v144;
              v114.m128_f32[0] = mPrev_high.m128_f32[0] - v145;
              v116 = v114;
              v115 = *(float *)&mNext - v146;
              v116.m128_f32[0] = (float)((float)(v114.m128_f32[0] * v114.m128_f32[0]) + (float)(v113 * v113))
                               + (float)(v115 * v115);
              if ( v116.m128_f32[0] == 0.0 )
              {
                v117 = 0i64;
              }
              else
              {
                v117 = (__m128)(unsigned int)FLOAT_1_0;
                v117.m128_f32[0] = 1.0 / _mm_sqrt_ps(v116).m128_f32[0];
              }
              v119 = v117;
              v118 = v117.m128_f32[0];
              v117.m128_f32[0] = v117.m128_f32[0] * v115;
              v119.m128_f32[0] = v119.m128_f32[0] * v113;
              v120 = v118 * v114.m128_f32[0];
              if ( v117.m128_f32[0] < 0.69999999 )
              {
                v122 = v119;
                v121 = (float)(v117.m128_f32[0] * UFG::qVector3::msAxisZ.y) - (float)(v120 * UFG::qVector3::msAxisZ.z);
                v122.m128_f32[0] = (float)(v119.m128_f32[0] * UFG::qVector3::msAxisZ.z)
                                 - (float)(v117.m128_f32[0] * UFG::qVector3::msAxisZ.x);
                v124 = v122;
                v123 = (float)(v120 * UFG::qVector3::msAxisZ.x) - (float)(v119.m128_f32[0] * UFG::qVector3::msAxisZ.y);
                v124.m128_f32[0] = (float)((float)(v122.m128_f32[0] * v122.m128_f32[0]) + (float)(v121 * v121))
                                 + (float)(v123 * v123);
                if ( v124.m128_f32[0] == 0.0 )
                  v125 = 0.0;
                else
                  v125 = 1.0 / _mm_sqrt_ps(v124).m128_f32[0];
                v126 = v123 * v125;
                v127 = v122.m128_f32[0] * v125;
                v128 = v121 * v125;
                v130 = v117;
                v129 = (float)(v126 * v120) - (float)(v117.m128_f32[0] * v127);
                v130.m128_f32[0] = (float)(v117.m128_f32[0] * v128) - (float)(v126 * v119.m128_f32[0]);
                v132 = v130;
                v131 = (float)(v127 * v119.m128_f32[0]) - (float)(v128 * v120);
                v132.m128_f32[0] = (float)((float)(v130.m128_f32[0] * v130.m128_f32[0]) + (float)(v129 * v129))
                                 + (float)(v131 * v131);
                if ( v132.m128_f32[0] == 0.0 )
                  v133 = 0.0;
                else
                  v133 = 1.0 / _mm_sqrt_ps(v132).m128_f32[0];
                v134 = *(float *)&v8[27].mPrev;
                v135 = *(float *)&v8[27].mNext;
                v136 = *((float *)&v8[27].mPrev + 1);
                HIDWORD(v8[24].mNext) = 0;
                v137 = v131 * v133;
                v138 = v129 * v133;
                v139 = v130.m128_f32[0] * v133;
                LODWORD(v8[24].mPrev) = v119.m128_i32[0];
                *((float *)&v8[24].mPrev + 1) = v120;
                LODWORD(v8[24].mNext) = v117.m128_i32[0];
                *(float *)&v8[25].mPrev = v128;
                HIDWORD(v8[25].mNext) = 0;
                *((float *)&v8[25].mPrev + 1) = v127;
                *(float *)&v8[25].mNext = v126;
                HIDWORD(v8[26].mNext) = 0;
                *(float *)&v8[26].mPrev = v138;
                *((float *)&v8[26].mPrev + 1) = v139;
                *(float *)&v8[26].mNext = v137;
                *(float *)&v8[27].mNext = (float)((float)((float)(v135 - *(float *)&mNext)
                                                        - (float)((float)((float)((float)((float)(v136 - v164) * v139)
                                                                                + (float)((float)(v134 - *(float *)&v48)
                                                                                        * v138))
                                                                        + (float)((float)(v135 - *(float *)&mNext) * v137))
                                                                * v137))
                                                + *(float *)&mNext)
                                        + v155;
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 1069
// RVA: 0x4547A0
void __fastcall UFG::PhysicsVehicle::ActivateVolume(
        UFG::PhysicsVehicle *this,
        unsigned int volumePropertyKey,
        UFG::qVector3 *halfExtents,
        UFG::qMatrix44 *markerOffset,
        float extendVolumeBy)
{
  UFG::qVector4 v9; // xmm3
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::AIOutlineComponent *ComponentOfType; // rax
  UFG::AIOutlineComponent *v15; // rbx
  UFG::Event *v16; // rdx
  UFG::qVector3 max; // [rsp+20h] [rbp-78h] BYREF
  UFG::qVector3 min; // [rsp+30h] [rbp-68h] BYREF
  UFG::qMatrix44 result; // [rsp+40h] [rbp-58h] BYREF

  UFG::PhysicsVehicle::DeactivateVolume(this);
  v9 = markerOffset->v1;
  v10 = markerOffset->v2;
  v11 = markerOffset->v3;
  this->mVolumeOffset.v0 = markerOffset->v0;
  this->mVolumeOffset.v1 = v9;
  this->mVolumeOffset.v2 = v10;
  this->mVolumeOffset.v3 = v11;
  UFG::qMatrix44::operator*(&this->mVolumeOffset, &result, &this->mBodyTransform);
  this->mVolumeRigidBody = (hkpRigidBody *)UFG::PhantomCallback::CreatePhantom(halfExtents, &result, volumePropertyKey);
  if ( this != (UFG::PhysicsVehicle *)-8i64 )
  {
    m_pPointer = this->mUserData.simComponent.m_pPointer;
    if ( m_pPointer )
    {
      m_pSimObject = m_pPointer->m_pSimObject;
      if ( m_pSimObject )
      {
        ComponentOfType = (UFG::AIOutlineComponent *)UFG::SimObject::GetComponentOfType(
                                                       m_pSimObject,
                                                       UFG::AIOutlineComponent::_TypeUID);
        v15 = ComponentOfType;
        if ( ComponentOfType )
        {
          UFG::AIOutlineComponent::GetLocalAABB(ComponentOfType, &min, &max);
          min.x = min.x - (float)(extendVolumeBy * 0.5);
          min.y = min.y - (float)(extendVolumeBy * 0.5);
          max.x = max.x + (float)(extendVolumeBy * 0.5);
          max.y = max.y + (float)(extendVolumeBy * 0.5);
          UFG::AIOutlineComponent::SetLocalAABB(v15, &min, &max, eOutlineDimensionsDefinedBy_PropertySet);
          UFG::AIOutlineComponent::ForceUpdate(v15, v16);
        }
      }
    }
  }
}

// File Line: 1103
// RVA: 0x4602E0
void __fastcall UFG::PhysicsVehicle::DeactivateVolume(UFG::PhysicsVehicle *this)
{
  hkpRigidBody *mVolumeRigidBody; // rcx
  UFG::HavokUserData *p_mUserData; // rbx
  UFG::SimComponent *m_pPointer; // rbx
  UFG::SimObject *m_pSimObject; // rbx
  UFG::AIOutlineComponent *ComponentOfType; // rax
  UFG::AIOutlineComponent *v7; // rdi
  UFG::Event *v8; // rdx

  mVolumeRigidBody = this->mVolumeRigidBody;
  if ( mVolumeRigidBody )
  {
    UFG::PhantomCallback::DestroyPhantom(mVolumeRigidBody);
    this->mVolumeRigidBody = 0i64;
    p_mUserData = &this->mUserData;
    if ( p_mUserData )
    {
      m_pPointer = p_mUserData->simComponent.m_pPointer;
      if ( m_pPointer )
      {
        m_pSimObject = m_pPointer->m_pSimObject;
        if ( m_pSimObject )
        {
          ComponentOfType = (UFG::AIOutlineComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pSimObject,
                                                         UFG::AIOutlineComponent::_TypeUID);
          v7 = ComponentOfType;
          if ( ComponentOfType )
          {
            UFG::AIOutlineComponent::SetAABBFromPropertySet(ComponentOfType, m_pSimObject->m_pSceneObj);
            UFG::AIOutlineComponent::ForceUpdate(v7, v8);
          }
        }
      }
    }
  }
}

// File Line: 1135
// RVA: 0x45AF90
void __fastcall UFG::PhysicsVehicle::ComputeBodyTransform(UFG::PhysicsVehicle *this)
{
  hkpRigidBody *mBody; // rdx
  __m128 m_quad; // xmm4
  UFG::qVector4 v3; // xmm2
  UFG::qVector4 v4; // xmm0

  mBody = this->mRigidBody->mBody;
  if ( mBody )
  {
    m_quad = mBody->m_motion.m_motionState.m_transform.m_translation.m_quad;
    v3 = (UFG::qVector4)_mm_srli_si128(
                          _mm_slli_si128(
                            _mm_load_si128((const __m128i *)&mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2),
                            4),
                          4);
    v4 = (UFG::qVector4)_mm_srli_si128(
                          _mm_slli_si128(_mm_load_si128((const __m128i *)&mBody->m_motion.m_motionState), 4),
                          4);
    this->mBodyTransform.v1 = (UFG::qVector4)_mm_srli_si128(
                                               _mm_slli_si128(
                                                 _mm_load_si128((const __m128i *)&mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1),
                                                 4),
                                               4);
    this->mBodyTransform.v0 = v4;
    this->mBodyTransform.v2 = v3;
    this->mBodyTransform.v3 = (UFG::qVector4)_mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, query.m_quad), 196);
  }
}

// File Line: 1164
// RVA: 0x4803D0
void __fastcall UFG::PhysicsVehicle::UpdateTransforms(UFG::PhysicsVehicle *this, UFG::qMatrix44 *rootTransform)
{
  hkpRigidBody *mBody; // rdx
  hkpRigidBody *mBulletCollider; // rcx
  UFG::qMatrix44 result; // [rsp+20h] [rbp-88h] BYREF
  hkTransformf transform; // [rsp+60h] [rbp-48h] BYREF

  mBody = this->mRigidBody->mBody;
  if ( mBody )
  {
    mBulletCollider = this->mBulletCollider;
    if ( mBulletCollider )
      hkpRigidBody::setTransform(mBulletCollider, &mBody->m_motion.m_motionState.m_transform);
    if ( this->mVolumeRigidBody )
    {
      UFG::qMatrix44::operator*(&this->mVolumeOffset, &result, rootTransform);
      hkTransformf::set4x4ColumnMajor(&transform, &result.v0.x);
      hkpRigidBody::setTransform(this->mVolumeRigidBody, &transform);
    }
  }
}

// File Line: 1192
// RVA: 0x4585E0
void __fastcall UFG::PhysicsVehicle::ApplyImpulse(
        UFG::PhysicsVehicle *this,
        UFG::qVector3 *impulse,
        UFG::qVector3 *pos)
{
  UFG::RigidBody::ApplyLinearImpulse(this->mRigidBody, impulse, pos);
}

// File Line: 1199
// RVA: 0x475170
void __fastcall UFG::PhysicsVehicle::SetMassScaleForCollisions(
        UFG::PhysicsVehicle *this,
        float scaleMass,
        float scaleRotMass)
{
  UFG::VehicleCollisionListener *v4; // rbx
  char v5; // dl
  char v6; // cl
  _QWORD **Value; // rax
  UFG::VehicleCollisionListener *v8; // rax
  char v9; // al
  UFG::VehicleCollisionListener *mCollisionListener; // rax

  if ( !this->mCollisionListener && this->mRigidBody->mBody )
  {
    v4 = (UFG::VehicleCollisionListener *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64);
    v5 = ++v4[1].mInverseMassScale.m_quad.m128_i8[0];
    *((_DWORD *)&v4->hkpContactListener::vfptr + v5) = 3;
    *((_QWORD *)&v4->mBody + v5) = "VehicleCollisionListener";
    *((_QWORD *)&v4[1].hkpContactListener::vfptr + v5) = 0i64;
    v6 = v4[1].mInverseMassScale.m_quad.m128_i8[1];
    if ( v5 > v6 )
      v6 = v5;
    v4[1].mInverseMassScale.m_quad.m128_i8[1] = v6;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (UFG::VehicleCollisionListener *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                            Value[11],
                                            48i64);
    if ( v8 )
      UFG::VehicleCollisionListener::VehicleCollisionListener(v8, this->mRigidBody->mBody);
    this->mCollisionListener = v8;
    v9 = v4[1].mInverseMassScale.m_quad.m128_i8[0];
    if ( v9 > 0 )
    {
      v4[1].mInverseMassScale.m_quad.m128_i8[0] = v9 - 1;
    }
    else
    {
      v4[1].mInverseMassScale.m_quad.m128_i8[0] = 0;
      LODWORD(v4->hkpContactListener::vfptr) = 3;
      v4->mBody = 0i64;
      v4[1].hkpContactListener::vfptr = 0i64;
    }
  }
  mCollisionListener = this->mCollisionListener;
  mCollisionListener->mInverseMassScale.m_quad.m128_f32[0] = 1.0 / scaleRotMass;
  mCollisionListener->mInverseMassScale.m_quad.m128_f32[1] = 1.0 / scaleRotMass;
  mCollisionListener->mInverseMassScale.m_quad.m128_f32[2] = 1.0 / scaleRotMass;
  mCollisionListener->mInverseMassScale.m_quad.m128_f32[3] = 1.0 / scaleMass;
}

// File Line: 1213
// RVA: 0x45A630
void __fastcall UFG::PhysicsVehicle::ClearMassScaleForCollisions(UFG::PhysicsVehicle *this)
{
  UFG::VehicleCollisionListener *mCollisionListener; // rcx

  if ( (*((_BYTE *)this + 604) & 0x10) != 0 )
  {
    mCollisionListener = this->mCollisionListener;
    if ( mCollisionListener )
      ((void (__fastcall *)(UFG::VehicleCollisionListener *, __int64))mCollisionListener->hkpContactListener::vfptr->~hkpContactListener)(
        mCollisionListener,
        1i64);
    this->mCollisionListener = 0i64;
  }
  else
  {
    UFG::PhysicsVehicle::SetMassScaleForCollisions(this, 1.0, this->mRotMassScaleForCollisions);
  }
}

// File Line: 1228
// RVA: 0x466B80
double __fastcall UFG::PhysicsVehicle::GetMass(UFG::PhysicsVehicle *this)
{
  return UFG::RigidBody::GetMass(this->mRigidBody);
}

// File Line: 1236
// RVA: 0x44E200
void __fastcall UFG::VehicleCollisionListener::VehicleCollisionListener(
        UFG::VehicleCollisionListener *this,
        hkpRigidBody *rb)
{
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&UFG::VehicleCollisionListener::`vftable{for `hkpContactListener};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&UFG::VehicleCollisionListener::`vftable{for `hkpEntityListener};
  this->mBody = rb;
  this->mInverseMassScale = *(hkVector4f *)_xmm;
  hkpEntity::addContactListener(rb, this);
  hkpEntity::addEntityListener(this->mBody, &this->hkpEntityListener);
  this->mBody->m_collidable.m_forceCollideOntoPpu |= 4u;
}

// File Line: 1247
// RVA: 0x451940
void __fastcall UFG::VehicleCollisionListener::~VehicleCollisionListener(UFG::VehicleCollisionListener *this)
{
  hkpRigidBody *mBody; // rcx

  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&UFG::VehicleCollisionListener::`vftable{for `hkpContactListener};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&UFG::VehicleCollisionListener::`vftable{for `hkpEntityListener};
  mBody = this->mBody;
  if ( mBody )
  {
    hkpEntity::removeContactListener(mBody, this);
    hkpEntity::removeEntityListener(this->mBody, &this->hkpEntityListener);
  }
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
}

// File Line: 1271
// RVA: 0x486AB0
void __fastcall UFG::VehicleCollisionListener::contactPointCallback(
        UFG::VehicleCollisionListener *this,
        hkpContactPointEvent *event)
{
  if ( event->m_bodies[0]->m_material.m_responseType.m_storage == 1
    && event->m_bodies[1]->m_material.m_responseType.m_storage == 1 )
  {
    hkpAddModifierUtil::setInvMassScalingForContact(event, this->mBody, &this->mInverseMassScale);
  }
}

// File Line: 1287
// RVA: 0x487700
void __fastcall UFG::VehicleCollisionListener::entityDeletedCallback(
        UFG::VehicleCollisionListener *this,
        hkpEntity *entity)
{
  char *v2; // rbx
  hkpEntityListener *v5; // rdx

  v2 = &this[-1].mInverseMassScale.m_quad.m128_i8[8];
  hkpEntity::removeContactListener(entity, (UFG::VehicleCollisionListener *)((char *)this - 8));
  v5 = 0i64;
  if ( v2 )
    v5 = (hkpEntityListener *)this;
  hkpEntity::removeEntityListener(entity, v5);
  this->hkpEntityListener::vfptr = 0i64;
}

// File Line: 1297
// RVA: 0x482B70
void __fastcall UFG::VehicleSetup::buildVehicle(
        UFG::VehicleSetup *this,
        UFG::PhysicsWheeledVehicle *pwv,
        hkpWorld *world,
        hkpVehicleInstance *vehicle,
        hkpVehicleWheelCollide *wheelCollide)
{
  __int64 v8; // rdi
  char v9; // dl
  int v10; // esi
  char v11; // cl
  _QWORD **Value; // rax
  hkpVehicleData *v13; // rax
  hkpVehicleData *v14; // rax
  char v15; // al
  char v16; // dl
  char v17; // cl
  _QWORD **v18; // rax
  __int64 v19; // rax
  char v20; // al
  char v21; // dl
  char v22; // cl
  _QWORD **v23; // rax
  __int64 v24; // rax
  char v25; // al
  char v26; // dl
  char v27; // cl
  _QWORD **v28; // rax
  hkpVehicleDefaultEngine *v29; // rax
  hkpVehicleDefaultEngine *v30; // rbx
  char v31; // al
  char v32; // dl
  char v33; // cl
  _QWORD **v34; // rax
  hkpVehicleDefaultTransmission *v35; // rax
  hkpVehicleDefaultTransmission *v36; // rbx
  char v37; // al
  char v38; // dl
  char v39; // cl
  _QWORD **v40; // rax
  hkpVehicleDefaultBrake *v41; // rax
  hkpVehicleDefaultBrake *v42; // rbx
  char v43; // al
  char v44; // r8
  char v45; // cl
  _QWORD **v46; // rax
  __int64 v47; // rax
  char v48; // al
  char v49; // dl
  char v50; // cl
  _QWORD **v51; // rax
  hkpVehicleDefaultAerodynamics *v52; // rax
  hkpVehicleDefaultAerodynamics *v53; // r15
  UFG::qReflectObject *mData; // rbx
  char v55; // al
  char v56; // dl
  char v57; // cl
  _QWORD **v58; // rax
  hkpVehicleDefaultVelocityDamper *v59; // rax
  hkpVehicleVelocityDamper *v60; // rax
  char v61; // al
  char v62; // r8
  char v63; // cl
  _QWORD **v64; // rax
  __int64 v65; // rax
  char v66; // al
  hkpVehicleDriverInputStatus *m_deviceStatus; // rax
  hkpRigidBody *mBody; // r15
  __int64 v69; // rbx
  UFG::qSafeArray<float,4> *p_mCurrentSuspensionLength; // rdi
  UFG::qReflectHandleBase v71; // [rsp+38h] [rbp-39h] BYREF
  UFG::qReflectHandleBase v72; // [rsp+60h] [rbp-11h] BYREF

  UFG::qReflectHandleBase::qReflectHandleBase(&v72);
  v72.mTypeUID = UFG::qStringHash64("UFG::BaseVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::operator=(&v72, &pwv->mDnaDefinition);
  UFG::qReflectHandleBase::qReflectHandleBase(&v71);
  v71.mTypeUID = UFG::qStringHash64("UFG::WheeledVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v71, v71.mTypeUID, v72.mData->mBaseNode.mUID);
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v9 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v9) = 3;
  *(_QWORD *)(v8 + 8i64 * v9 + 16) = "hkpVehicleData";
  v10 = 0;
  *(_QWORD *)(v8 + 8i64 * v9 + 48) = 0i64;
  v11 = *(_BYTE *)(v8 + 81);
  if ( v9 > v11 )
    v11 = v9;
  *(_BYTE *)(v8 + 81) = v11;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hkpVehicleData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 208i64);
  if ( v13 )
    hkpVehicleData::hkpVehicleData(v13);
  else
    v14 = 0i64;
  vehicle->m_data = v14;
  v15 = *(_BYTE *)(v8 + 80);
  if ( v15 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v15 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v16 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v16) = 3;
  *(_QWORD *)(v8 + 8i64 * v16 + 16) = "VehicleAnalogDriverInput";
  *(_QWORD *)(v8 + 8i64 * v16 + 48) = 0i64;
  v17 = *(_BYTE *)(v8 + 81);
  if ( v16 > v17 )
    v17 = v16;
  *(_BYTE *)(v8 + 81) = v17;
  v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v18[11] + 8i64))(v18[11], 24i64);
  if ( v19 )
  {
    *(_QWORD *)v19 = &hkBaseObject::`vftable;
    *(_QWORD *)v19 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v19 + 8) = 0x1FFFF;
    *(_QWORD *)v19 = &hkpVehicleDriverInput::`vftable;
    *(_QWORD *)v19 = &UFG::VehicleAnalogDriverInput::`vftable;
    *(_DWORD *)(v19 + 16) = 0;
    *(_BYTE *)(v19 + 20) = 0;
  }
  else
  {
    v19 = 0i64;
  }
  vehicle->m_driverInput = (hkpVehicleDriverInput *)v19;
  v20 = *(_BYTE *)(v8 + 80);
  if ( v20 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v20 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v21 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v21) = 3;
  *(_QWORD *)(v8 + 8i64 * v21 + 16) = "Steering";
  *(_QWORD *)(v8 + 8i64 * v21 + 48) = 0i64;
  v22 = *(_BYTE *)(v8 + 81);
  if ( v21 > v22 )
    v22 = v21;
  *(_BYTE *)(v8 + 81) = v22;
  v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v23[11] + 8i64))(v23[11], 72i64);
  if ( v24 )
  {
    *(_QWORD *)v24 = &hkBaseObject::`vftable;
    *(_QWORD *)v24 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v24 + 8) = 0x1FFFF;
    *(_QWORD *)v24 = &hkpVehicleSteering::`vftable;
    *(_QWORD *)v24 = &UFG::Steering::`vftable;
    *(_QWORD *)(v24 + 16) = 0i64;
    *(_DWORD *)(v24 + 24) = 0;
    *(_DWORD *)(v24 + 28) = 0x80000000;
    *(_DWORD *)(v24 + 32) = 0;
    *(_QWORD *)(v24 + 56) = 0i64;
    *(_DWORD *)(v24 + 68) = 0;
  }
  else
  {
    v24 = 0i64;
  }
  vehicle->m_steering = (hkpVehicleSteering *)v24;
  v25 = *(_BYTE *)(v8 + 80);
  if ( v25 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v25 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v26 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v26) = 3;
  *(_QWORD *)(v8 + 8i64 * v26 + 16) = "Engine";
  *(_QWORD *)(v8 + 8i64 * v26 + 48) = 0i64;
  v27 = *(_BYTE *)(v8 + 81);
  if ( v26 > v27 )
    v27 = v26;
  *(_BYTE *)(v8 + 81) = v27;
  v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (hkpVehicleDefaultEngine *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v28[11] + 8i64))(v28[11], 104i64);
  v30 = v29;
  if ( v29 )
  {
    hkpVehicleDefaultEngine::hkpVehicleDefaultEngine(v29);
    v30->vfptr = (hkBaseObjectVtbl *)&UFG::Engine::`vftable;
    *(_QWORD *)&v30[1].m_memSizeAndFlags = 0i64;
    v30[1].vfptr = 0i64;
    *(_QWORD *)&v30[1].m_minRPM = 0i64;
    v30[1].m_maxRPM = 1000000.0;
    *(_QWORD *)&v30[1].m_maxTorque = 1113325568i64;
    v30[1].m_torqueFactorAtMaxRPM = 0.33000001;
    v30[1].m_resistanceFactorAtMinRPM = 0.02;
  }
  else
  {
    v30 = 0i64;
  }
  vehicle->m_engine = v30;
  v31 = *(_BYTE *)(v8 + 80);
  if ( v31 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v31 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v32 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v32) = 3;
  *(_QWORD *)(v8 + 8i64 * v32 + 16) = "Transmission";
  *(_QWORD *)(v8 + 8i64 * v32 + 48) = 0i64;
  v33 = *(_BYTE *)(v8 + 81);
  if ( v32 > v33 )
    v33 = v32;
  *(_BYTE *)(v8 + 81) = v33;
  v34 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v35 = (hkpVehicleDefaultTransmission *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v34[11] + 8i64))(
                                           v34[11],
                                           112i64);
  v36 = v35;
  if ( v35 )
  {
    hkpVehicleDefaultTransmission::hkpVehicleDefaultTransmission(v35);
    v36->vfptr = (hkBaseObjectVtbl *)&UFG::Transmission::`vftable;
    v36[1].vfptr = 0i64;
    *(_DWORD *)&v36[1].m_memSizeAndFlags = 0;
    *(_DWORD *)(&v36[1].m_referenceCount + 1) = 0x80000000;
    *(_QWORD *)&v36[1].m_downshiftRPM = 0i64;
    v36[1].m_primaryTransmissionRatio = 0.0;
    v36[1].m_clutchDelayTime = -0.0;
    LODWORD(v36[1].m_reverseGearRatio) &= ~1u;
  }
  else
  {
    v36 = 0i64;
  }
  vehicle->m_transmission = v36;
  v37 = *(_BYTE *)(v8 + 80);
  if ( v37 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v37 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v38 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v38) = 3;
  *(_QWORD *)(v8 + 8i64 * v38 + 16) = "Brakes";
  *(_QWORD *)(v8 + 8i64 * v38 + 48) = 0i64;
  v39 = *(_BYTE *)(v8 + 81);
  if ( v38 > v39 )
    v39 = v38;
  *(_BYTE *)(v8 + 81) = v39;
  v40 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v41 = (hkpVehicleDefaultBrake *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v40[11] + 8i64))(v40[11], 48i64);
  v42 = v41;
  if ( v41 )
  {
    hkpVehicleDefaultBrake::hkpVehicleDefaultBrake(v41);
    v42->vfptr = (hkBaseObjectVtbl *)&UFG::Brakes::`vftable;
    v42[1].vfptr = 0i64;
  }
  else
  {
    v42 = 0i64;
  }
  vehicle->m_brake = v42;
  v43 = *(_BYTE *)(v8 + 80);
  if ( v43 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v43 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v44 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v44) = 3;
  *(_QWORD *)(v8 + 8i64 * v44 + 16) = "hkpVehicleDefaultSuspension";
  *(_QWORD *)(v8 + 8i64 * v44 + 48) = 0i64;
  v45 = *(_BYTE *)(v8 + 81);
  if ( v44 > v45 )
    v45 = v44;
  *(_BYTE *)(v8 + 81) = v45;
  v46 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v47 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v46[11] + 8i64))(v46[11], 48i64);
  if ( v47 )
  {
    *(_QWORD *)v47 = &hkBaseObject::`vftable;
    *(_QWORD *)v47 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v47 + 8) = 0x1FFFF;
    *(_QWORD *)v47 = &hkpVehicleSuspension::`vftable;
    *(_QWORD *)(v47 + 16) = 0i64;
    *(_DWORD *)(v47 + 24) = 0;
    *(_DWORD *)(v47 + 28) = 0x80000000;
    *(_QWORD *)v47 = &hkpVehicleDefaultSuspension::`vftable;
    *(_QWORD *)(v47 + 32) = 0i64;
    *(_DWORD *)(v47 + 40) = 0;
    *(_DWORD *)(v47 + 44) = 0x80000000;
  }
  else
  {
    v47 = 0i64;
  }
  vehicle->m_suspension = (hkpVehicleSuspension *)v47;
  v48 = *(_BYTE *)(v8 + 80);
  if ( v48 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v48 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v49 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v49) = 3;
  *(_QWORD *)(v8 + 8i64 * v49 + 16) = "VehicleAerodynamics";
  *(_QWORD *)(v8 + 8i64 * v49 + 48) = 0i64;
  v50 = *(_BYTE *)(v8 + 81);
  if ( v49 > v50 )
    v50 = v49;
  *(_BYTE *)(v8 + 81) = v50;
  v51 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v52 = (hkpVehicleDefaultAerodynamics *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v51[11] + 8i64))(
                                           v51[11],
                                           64i64);
  v53 = v52;
  if ( v52 )
  {
    mData = v71.mData;
    hkpVehicleDefaultAerodynamics::hkpVehicleDefaultAerodynamics(v52);
    v53->vfptr = (hkBaseObjectVtbl *)&UFG::VehicleAerodynamics::`vftable;
    LODWORD(v53[1].vfptr) = 0;
    HIDWORD(v53[1].vfptr) = 1065353216;
    v53->m_extraGravityws.m_quad = _mm_unpacklo_ps(
                                     _mm_unpacklo_ps((__m128)0i64, (__m128)HIDWORD(mData[5].mBaseNode.mNeighbours[1])),
                                     (__m128)0i64);
  }
  else
  {
    v53 = 0i64;
  }
  vehicle->m_aerodynamics = v53;
  v55 = *(_BYTE *)(v8 + 80);
  if ( v55 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v55 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v56 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v56) = 3;
  *(_QWORD *)(v8 + 8i64 * v56 + 16) = "hkpVehicleDefaultVelocityDamper";
  *(_QWORD *)(v8 + 8i64 * v56 + 48) = 0i64;
  v57 = *(_BYTE *)(v8 + 81);
  if ( v56 > v57 )
    v57 = v56;
  *(_BYTE *)(v8 + 81) = v57;
  v58 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v59 = (hkpVehicleDefaultVelocityDamper *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v58[11] + 8i64))(
                                             v58[11],
                                             32i64);
  if ( v59 )
    hkpVehicleDefaultVelocityDamper::hkpVehicleDefaultVelocityDamper(v59);
  else
    v60 = 0i64;
  vehicle->m_velocityDamper = v60;
  v61 = *(_BYTE *)(v8 + 80);
  if ( v61 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v61 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  vehicle->m_wheelCollide = wheelCollide;
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpWorld *, hkpVehicleData *, UFG::qReflectObject *))this->vfptr[2].__vecDelDtor)(
    this,
    world,
    vehicle->m_data,
    v71.mData);
  vehicle->m_tyreMarks = 0i64;
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleDriverInput *))this->vfptr[6].__vecDelDtor)(
    this,
    vehicle->m_data,
    v71.mData,
    vehicle->m_driverInput);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleEngine *))this->vfptr[5].__vecDelDtor)(
    this,
    vehicle->m_data,
    v71.mData,
    vehicle->m_engine);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleTransmission *))this->vfptr[4].__first_virtual_table_function__)(
    this,
    vehicle->m_data,
    v71.mData,
    vehicle->m_transmission);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleSteering *))this->vfptr[5].__first_virtual_table_function__)(
    this,
    vehicle->m_data,
    v71.mData,
    vehicle->m_steering);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleBrake *))this->vfptr[4].__vecDelDtor)(
    this,
    vehicle->m_data,
    v71.mData,
    vehicle->m_brake);
  ((void (__fastcall *)(UFG::VehicleSetup *, UFG::PhysicsWheeledVehicle *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleSuspension *))this->vfptr[3].__first_virtual_table_function__)(
    this,
    pwv,
    vehicle->m_data,
    v71.mData,
    vehicle->m_suspension);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleAerodynamics *))this->vfptr[3].__vecDelDtor)(
    this,
    vehicle->m_data,
    v71.mData,
    vehicle->m_aerodynamics);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleVelocityDamper *))this->vfptr[2].__first_virtual_table_function__)(
    this,
    vehicle->m_data,
    v71.mData,
    vehicle->m_velocityDamper);
  ((void (__fastcall *)(UFG::VehicleSetup *, UFG::PhysicsWheeledVehicle *, hkpWorld *, hkpVehicleInstance *, hkpVehicleWheelCollide *))this->vfptr[6].__first_virtual_table_function__)(
    this,
    pwv,
    world,
    vehicle,
    vehicle->m_wheelCollide);
  v62 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v62) = 3;
  *(_QWORD *)(v8 + 8i64 * v62 + 16) = "hkpVehicleDriverInputAnalogStatus";
  *(_QWORD *)(v8 + 8i64 * v62 + 48) = 0i64;
  v63 = *(_BYTE *)(v8 + 81);
  if ( v62 > v63 )
    v63 = v62;
  *(_BYTE *)(v8 + 81) = v63;
  v64 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v65 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v64[11] + 8i64))(v64[11], 32i64);
  if ( v65 )
  {
    *(_QWORD *)v65 = &hkBaseObject::`vftable;
    *(_QWORD *)v65 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v65 + 8) = 0x1FFFF;
    *(_QWORD *)v65 = &hkpVehicleDriverInputStatus::`vftable;
    *(_QWORD *)v65 = &hkpVehicleDriverInputAnalogStatus::`vftable;
  }
  else
  {
    v65 = 0i64;
  }
  vehicle->m_deviceStatus = (hkpVehicleDriverInputStatus *)v65;
  v66 = *(_BYTE *)(v8 + 80);
  if ( v66 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v66 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  m_deviceStatus = vehicle->m_deviceStatus;
  m_deviceStatus[1].vfptr = 0i64;
  m_deviceStatus[1].m_memSizeAndFlags = 0;
  ((void (__fastcall *)(hkpVehicleInstance *))vehicle->vfptr[4].__vecDelDtor)(vehicle);
  mBody = pwv->mRigidBody->mBody;
  if ( vehicle->m_data->m_numWheels > 0 )
  {
    v69 = 0i64;
    p_mCurrentSuspensionLength = &pwv->mCurrentSuspensionLength;
    do
    {
      vehicle->m_wheelsInfo.m_data[v69].m_currentSuspensionLength = p_mCurrentSuspensionLength->array[0];
      hkVector4f::setRotatedDir(
        &vehicle->m_wheelsInfo.m_data[v10].m_suspensionDirectionWs,
        &mBody->m_motion.m_motionState.m_sweptTransform.m_rotation1,
        &pwv->mSuspensionDirChassisSpace[v10]);
      ++v10;
      p_mCurrentSuspensionLength = (UFG::qSafeArray<float,4> *)((char *)p_mCurrentSuspensionLength + 4);
      ++v69;
    }
    while ( v10 < vehicle->m_data->m_numWheels );
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v71);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v72);
}

// File Line: 1376
// RVA: 0x488A90
void __fastcall UFG::VehicleSetup::setupVehicleData(
        UFG::VehicleSetup *this,
        hkpWorld *world,
        hkpVehicleData *data,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr)
{
  hkArray<hkpVehicleData::WheelComponentParams,hkContainerHeapAllocator> *p_m_wheelParams; // rbx
  int numWheels_low; // r14d
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  hkArray<hkpVehicleData::WheelComponentParams,hkContainerHeapAllocator> *v12; // r8
  __int64 firstFrontWheel; // r8
  __int64 v14; // rdx
  __int64 firstRearWheel; // r8
  __int64 v16; // rdx
  int v17; // r8d
  __int64 v18; // rdx
  float v19; // xmm0_4
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  hkResult v23; // [rsp+A0h] [rbp+8h] BYREF

  p_m_wheelParams = &data->m_wheelParams;
  data->m_gravity = world->m_gravity;
  data->m_chassisOrientation.m_col0.m_quad = _xmm;
  data->m_chassisOrientation.m_col1 = (hkVector4f)_xmm;
  data->m_chassisOrientation.m_col2 = (hkVector4f)_xmm;
  data->m_frictionEqualizer = vehicle_data_ptr->other_frictionEqualizer;
  data->m_torqueRollFactor = vehicle_data_ptr->other_torqueRollFactor;
  data->m_torquePitchFactor = vehicle_data_ptr->other_torquePitchFactor;
  data->m_torqueYawFactor = vehicle_data_ptr->other_torqueYawFactor;
  data->m_extraTorqueFactor = vehicle_data_ptr->other_extraTorqueFactor;
  data->m_maxVelocityForPositionalFriction = vehicle_data_ptr->other_maxVelocityForPositionalFriction;
  data->m_normalClippingAngleCos = vehicle_data_ptr->other_normalClippingAngle;
  data->m_chassisUnitInertiaYaw = vehicle_data_ptr->other_chassisUnitInertiaYaw;
  data->m_chassisUnitInertiaRoll = vehicle_data_ptr->other_chassisUnitInertiaRoll;
  data->m_chassisUnitInertiaPitch = vehicle_data_ptr->other_chassisUnitInertiaPitch;
  numWheels_low = SLOBYTE(vehicle_data_ptr->numWheels);
  data->m_numWheels = vehicle_data_ptr->numWheels;
  v9 = data->m_wheelParams.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < numWheels_low )
  {
    v10 = 2 * v9;
    v11 = numWheels_low;
    v12 = &data->m_wheelParams;
    if ( numWheels_low < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&v23, &hkContainerHeapAllocator::s_alloc, v12, v11, 40);
  }
  p_m_wheelParams->m_size = numWheels_low;
  firstFrontWheel = this->mParams.firstFrontWheel;
  if ( (int)firstFrontWheel <= this->mParams.lastFrontWheel )
  {
    v14 = firstFrontWheel;
    do
    {
      LODWORD(firstFrontWheel) = firstFrontWheel + 1;
      p_m_wheelParams->m_data[v14++].m_radius = vehicle_data_ptr->wheels_radius_front;
      p_m_wheelParams->m_data[v14 - 1].m_axle = 0;
      p_m_wheelParams->m_data[v14 - 1].m_friction = vehicle_data_ptr->wheels_frictionFront;
    }
    while ( (int)firstFrontWheel <= this->mParams.lastFrontWheel );
  }
  firstRearWheel = this->mParams.firstRearWheel;
  if ( (int)firstRearWheel <= this->mParams.lastRearWheel )
  {
    v16 = firstRearWheel;
    do
    {
      LODWORD(firstRearWheel) = firstRearWheel + 1;
      p_m_wheelParams->m_data[v16++].m_radius = vehicle_data_ptr->wheels_radius_rear;
      p_m_wheelParams->m_data[v16 - 1].m_axle = 1;
      p_m_wheelParams->m_data[v16 - 1].m_friction = vehicle_data_ptr->wheels_frictionRear;
    }
    while ( (int)firstRearWheel <= this->mParams.lastRearWheel );
  }
  v17 = 0;
  if ( data->m_numWheels > 0 )
  {
    v18 = 0i64;
    do
    {
      if ( data->m_numWheels == 2 )
        v19 = FLOAT_0_1;
      else
        v19 = FLOAT_0_25;
      ++v17;
      p_m_wheelParams->m_data[v18++].m_width = v19;
      p_m_wheelParams->m_data[v18 - 1].m_mass = vehicle_data_ptr->wheels_mass;
      p_m_wheelParams->m_data[v18 - 1].m_viscosityFriction = vehicle_data_ptr->wheels_viscosityFriction;
      p_m_wheelParams->m_data[v18 - 1].m_slipAngle = vehicle_data_ptr->wheels_slipAngle;
      p_m_wheelParams->m_data[v18 - 1].m_maxFriction = p_m_wheelParams->m_data[v18 - 1].m_friction * 2.0;
      p_m_wheelParams->m_data[v18 - 1].m_forceFeedbackMultiplier = vehicle_data_ptr->wheels_forceFeedbackMultiplier;
      v20 = _mm_mul_ps(data->m_gravity.m_quad, data->m_gravity.m_quad);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
              _mm_shuffle_ps(v20, v20, 170));
      v22 = _mm_rsqrt_ps(v21);
      p_m_wheelParams->m_data[v18 - 1].m_maxContactBodyAcceleration = _mm_andnot_ps(
                                                                        _mm_cmple_ps(v21, (__m128)0i64),
                                                                        _mm_mul_ps(
                                                                          _mm_mul_ps(
                                                                            _mm_sub_ps(
                                                                              (__m128)_xmm,
                                                                              _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                                                                            _mm_mul_ps(*(__m128 *)_xmm, v22)),
                                                                          v21)).m128_f32[0]
                                                                    * 2.0;
    }
    while ( v17 < data->m_numWheels );
  }
}

// File Line: 1433
// RVA: 0x488730
void __fastcall UFG::VehicleSetup::setupComponent(
        UFG::VehicleSetup *this,
        hkpVehicleData *data,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr,
        UFG::Steering *steering)
{
  UFG::Steering::InitializeFromPropertySet(
    steering,
    vehicle_data_ptr,
    data->m_numWheels,
    this->mParams.firstFrontWheel,
    this->mParams.lastFrontWheel,
    this->mParams.firstRearWheel,
    this->mParams.lastRearWheel);
}

// File Line: 1445
// RVA: 0x4886E0
void __fastcall UFG::VehicleSetup::setupComponent(
        UFG::VehicleSetup *this,
        hkpVehicleData *data,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr,
        UFG::Brakes *brake)
{
  UFG::Brakes::InitializeFromPropertySet(
    brake,
    vehicle_data_ptr,
    data->m_numWheels,
    this->mParams.firstFrontWheel,
    this->mParams.lastFrontWheel,
    this->mParams.firstRearWheel,
    this->mParams.lastRearWheel);
}

// File Line: 1457
// RVA: 0x488830
void __fastcall UFG::VehicleSetup::setupComponent(
        UFG::VehicleSetup *this,
        UFG::PhysicsWheeledVehicle *pwv,
        hkpVehicleData *data,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr,
        hkpVehicleDefaultSuspension *suspension)
{
  int m_numWheels; // edi
  hkpVehicleDefaultSuspension *v10; // r15
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  int m_size; // ecx
  int v15; // edx
  int v16; // r14d
  int v17; // eax
  int v18; // eax
  int v19; // r9d
  __int64 firstFrontWheel; // r10
  __int64 v21; // r8
  __int64 v22; // r9
  hkVector4f *v23; // rdx
  __int64 firstRearWheel; // r10
  __int64 v25; // rdx
  __int64 v26; // r8
  hkVector4f *v27; // r9

  m_numWheels = data->m_numWheels;
  v10 = suspension;
  v11 = suspension->m_wheelParams.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < m_numWheels )
  {
    v12 = 2 * v11;
    v13 = data->m_numWheels;
    if ( m_numWheels < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(
      (hkResult *)&suspension,
      &hkContainerHeapAllocator::s_alloc,
      &suspension->m_wheelParams,
      v13,
      48);
  }
  m_size = v10->m_wheelParams.m_size;
  v15 = 0;
  LODWORD(suspension) = 0;
  if ( m_numWheels - m_size > 0 )
  {
    do
      LODWORD(suspension) = ++v15;
    while ( v15 < m_numWheels - v10->m_wheelParams.m_size );
  }
  v10->m_wheelParams.m_size = m_numWheels;
  v16 = data->m_numWheels;
  v17 = v10->m_wheelSpringParams.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < v16 )
  {
    v18 = 2 * v17;
    v19 = v16;
    if ( v16 < v18 )
      v19 = v18;
    hkArrayUtil::_reserve(
      (hkResult *)&suspension,
      &hkContainerHeapAllocator::s_alloc,
      &v10->m_wheelSpringParams,
      v19,
      12);
  }
  v10->m_wheelSpringParams.m_size = v16;
  firstFrontWheel = this->mParams.firstFrontWheel;
  if ( (int)firstFrontWheel <= this->mParams.lastFrontWheel )
  {
    v21 = firstFrontWheel;
    v22 = firstFrontWheel;
    v23 = &pwv->mHardPointChassisSpace[firstFrontWheel];
    do
    {
      v10->m_wheelParams.m_data[v22].m_length = vehicle_data_ptr->suspension_frontSpringLength;
      v10->m_wheelParams.m_data[v22].m_directionChassisSpace = (hkVector4f)v23[4].m_quad;
      v10->m_wheelParams.m_data[v22].m_hardpointChassisSpace = (hkVector4f)v23->m_quad;
      v10->m_wheelSpringParams.m_data[v21].m_strength = vehicle_data_ptr->suspension_frontSpringRate;
      v10->m_wheelSpringParams.m_data[v21].m_dampingCompression = vehicle_data_ptr->suspension_frontShockDampingCompression;
      v10->m_wheelSpringParams.m_data[v21].m_dampingRelaxation = vehicle_data_ptr->suspension_frontShockDampingExtension;
      LODWORD(firstFrontWheel) = firstFrontWheel + 1;
      ++v23;
      ++v22;
      ++v21;
    }
    while ( (int)firstFrontWheel <= this->mParams.lastFrontWheel );
  }
  firstRearWheel = this->mParams.firstRearWheel;
  if ( (int)firstRearWheel <= this->mParams.lastRearWheel )
  {
    v25 = firstRearWheel;
    v26 = firstRearWheel;
    v27 = &pwv->mHardPointChassisSpace[firstRearWheel];
    do
    {
      v10->m_wheelParams.m_data[v26].m_length = vehicle_data_ptr->suspension_rearSpringLength;
      v10->m_wheelParams.m_data[v26].m_directionChassisSpace = (hkVector4f)v27[4].m_quad;
      v10->m_wheelParams.m_data[v26].m_hardpointChassisSpace = (hkVector4f)v27->m_quad;
      v10->m_wheelSpringParams.m_data[v25].m_strength = vehicle_data_ptr->suspension_rearSpringRate;
      v10->m_wheelSpringParams.m_data[v25].m_dampingCompression = vehicle_data_ptr->suspension_rearShockDampingCompression;
      v10->m_wheelSpringParams.m_data[v25].m_dampingRelaxation = vehicle_data_ptr->suspension_rearShockDampingExtension;
      LODWORD(firstRearWheel) = firstRearWheel + 1;
      ++v27;
      ++v26;
      ++v25;
    }
    while ( (int)firstRearWheel <= this->mParams.lastRearWheel );
  }
}

// File Line: 1485
// RVA: 0x488770
void __fastcall UFG::VehicleSetup::setupComponent(
        UFG::VehicleSetup *this,
        hkpVehicleData *data,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr,
        UFG::Transmission *transmission)
{
  UFG::Transmission::InitializeFromPropertySet(
    transmission,
    vehicle_data_ptr,
    data->m_numWheels,
    this->mParams.firstFrontWheel,
    this->mParams.lastFrontWheel,
    this->mParams.firstRearWheel,
    this->mParams.lastRearWheel);
}

// File Line: 1497
// RVA: 0x4887E0
void __fastcall UFG::VehicleSetup::setupComponent(
        UFG::VehicleSetup *this,
        hkpVehicleData *data,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr,
        UFG::VehicleAnalogDriverInput *driverInput)
{
  driverInput->m_deadZone = vehicle_data_ptr->steering_DeadZone;
  driverInput->m_autoReverse.m_bool = 0;
}

// File Line: 1506
// RVA: 0x488720
void __fastcall UFG::VehicleSetup::setupComponent(
        UFG::VehicleSetup *this,
        hkpVehicleData *data,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr,
        UFG::Engine *engine)
{
  UFG::Engine::InitializeFromPropertySet(engine, vehicle_data_ptr);
}

// File Line: 1513
// RVA: 0x4887B0
void __fastcall UFG::VehicleSetup::setupComponent(
        UFG::VehicleSetup *this,
        hkpVehicleData *data,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr,
        UFG::VehicleAerodynamics *aerodynamics)
{
  aerodynamics->m_airDensity = vehicle_data_ptr->aerodynamics_airDensity;
  aerodynamics->m_frontalArea = vehicle_data_ptr->aerodynamics_frontalArea;
  aerodynamics->m_dragCoefficient = vehicle_data_ptr->aerodynamics_dragCoefficient;
  aerodynamics->m_liftCoefficient = vehicle_data_ptr->aerodynamics_liftCoefficient;
}

// File Line: 1520
// RVA: 0x488800
void __fastcall UFG::VehicleSetup::setupComponent(
        UFG::VehicleSetup *this,
        hkpVehicleData *data,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr,
        hkpVehicleDefaultVelocityDamper *velocityDamper)
{
  velocityDamper->m_normalSpinDamping = vehicle_data_ptr->damping_normalSpinDamping;
  velocityDamper->m_collisionSpinDamping = vehicle_data_ptr->damping_collisionSpinDamping;
  velocityDamper->m_collisionThreshold = vehicle_data_ptr->damping_collisionThreshold;
}

// File Line: 1529
// RVA: 0x488D80
void __fastcall UFG::VehicleSetup::setupWheelCollide(
        UFG::VehicleSetup *this,
        UFG::PhysicsWheeledVehicle *pwv,
        hkpWorld *world,
        hkpVehicleInstance *vehicle,
        hkpVehicleWheelCollide *wheelCollide)
{
  ((void (__fastcall *)(hkpVehicleWheelCollide *, _QWORD, hkpWorld *, hkpVehicleInstance *))wheelCollide->vfptr[5].__vecDelDtor)(
    wheelCollide,
    ((unsigned __int16)pwv->mSystemId << 16) | 0x42Bu,
    world,
    vehicle);
}

// File Line: 1544
// RVA: 0x44E0F0
void __fastcall UFG::VehicleAction::VehicleAction(UFG::VehicleAction *this, UFG::PhysicsWheeledVehicle *vehicle)
{
  hkpUnaryAction::hkpUnaryAction(this, vehicle->mRigidBody->mBody, 0i64);
  this->vfptr = (hkBaseObjectVtbl *)&UFG::VehicleAction::`vftable;
  this->mVehicle = vehicle;
  this->mFlatTireDistance = 0.0;
}

// File Line: 1556
// RVA: 0x4823F0
void __fastcall UFG::VehicleAction::applyAction(UFG::VehicleAction *this, hkStepInfo *stepInfo)
{
  hkpEntity *m_entity; // rsi
  UFG::PhysicsWheeledVehicle *mVehicle; // rcx
  __m128 m_quad; // xmm8
  __m128 v7; // xmm0
  float v8; // xmm1_4
  hkpReorientAction *mReorientActionPitch; // rcx
  __m128 v10; // xmm2
  UFG::PhysicsWheeledVehicle *v11; // rbx
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm7
  float v16; // xmm0_4
  __m128 mBlownTireWobbleFrequency_low; // xmm1
  float v18; // xmm0_4
  unsigned int v19; // r8d
  __int64 v20; // rdx
  float *array; // rcx
  UFG::VehicleInstance *mHavokVehicle; // rax
  hkpVehicleWheelCollide *mWheelCollider; // rcx
  float mBlownTireFrictionMultiplier; // xmm0_4
  UFG::qMatrix44 *v25; // rax
  UFG::qVector4 v26; // xmm4
  UFG::qVector4 v27; // xmm2
  UFG::qVector4 v28; // xmm0
  UFG::PhysicsWheeledVehicle *v29; // rax
  __m128 v30; // xmm1
  __m128 m_storage_low; // xmm6
  __int64 v32; // rdx
  UFG::PhysicsWheeledVehicle *v33; // rdx
  int v34; // ecx
  UFG::PhysicsWheeledVehicle *v35; // rcx
  __m128 v36; // [rsp+30h] [rbp-D0h] BYREF
  __m128 v37; // [rsp+40h] [rbp-C0h] BYREF
  __m128 v38; // [rsp+50h] [rbp-B0h] BYREF
  hkVector4f v39; // [rsp+60h] [rbp-A0h] BYREF
  hkQuaternionf qi; // [rsp+70h] [rbp-90h] BYREF
  UFG::qMatrix44 d; // [rsp+80h] [rbp-80h] BYREF
  hkTransformf v42; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qMatrix44 result; // [rsp+100h] [rbp+0h] BYREF

  m_entity = this->m_entity;
  mVehicle = this->mVehicle;
  m_quad = m_entity->m_motion.m_linearVelocity.m_quad;
  if ( (*((_DWORD *)mVehicle + 274) & 8) != 0 )
  {
    v7 = _mm_shuffle_ps(m_quad, m_quad, 170);
    v8 = v7.m128_f32[0] <= 0.0 ? mVehicle->mVerticalVelocityDampingDown : mVehicle->mVerticalVelocityDampingUp;
    v7.m128_f32[0] = v7.m128_f32[0] * v8;
    v36 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, _mm_xor_ps(v7, *(__m128 *)_xmm)), (__m128)0i64);
    ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, hkStepInfo *, __m128 *, const char *))mVehicle->vfptr[6].__vecDelDtor)(
      mVehicle,
      stepInfo,
      &v36,
      "Vert Vel Damping");
    mReorientActionPitch = this->mVehicle->mReorientActionPitch;
    if ( mReorientActionPitch )
    {
      v10 = _mm_mul_ps(_xmm, m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad);
      if ( (float)((float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0] + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
                 + _mm_shuffle_ps(v10, v10, 170).m128_f32[0]) > 0.40000001 )
        ((void (__fastcall *)(hkpReorientAction *, hkStepInfo *))mReorientActionPitch->vfptr[1].__first_virtual_table_function__)(
          mReorientActionPitch,
          stepInfo);
    }
  }
  v11 = this->mVehicle;
  v12 = _mm_mul_ps(m_quad, m_quad);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  v15 = _mm_andnot_ps(
          _mm_cmple_ps(v13, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
              _mm_mul_ps(*(__m128 *)_xmm, v14)),
            v13));
  v16 = (float)(v15.m128_f32[0] * stepInfo->m_deltaTime.m_storage) + this->mFlatTireDistance;
  this->mFlatTireDistance = v16;
  mBlownTireWobbleFrequency_low = (__m128)LODWORD(v11->mBlownTireWobbleFrequency);
  if ( v16 >= mBlownTireWobbleFrequency_low.m128_f32[0] )
  {
    v18 = fmodf(v16, mBlownTireWobbleFrequency_low.m128_f32[0]);
    v19 = 0;
    this->mFlatTireDistance = v18;
    if ( (*((_DWORD *)&v11->UFG::PhysicsVehicle + 151) & 7) != 0 )
    {
      v20 = 0i64;
      array = v11->mTireDamage.array;
      while ( 1 )
      {
        if ( *array >= 1.0 )
        {
          mHavokVehicle = v11->mHavokVehicle;
          if ( !mHavokVehicle || mHavokVehicle->m_wheelsInfo.hkpVehicleInstance::m_data[v20].m_contactBody )
            break;
        }
        ++v19;
        ++array;
        ++v20;
        if ( (int)v19 >= (*((_DWORD *)&v11->UFG::PhysicsVehicle + 151) & 7) )
          goto LABEL_23;
      }
      mWheelCollider = v11->mWheelCollider;
      mBlownTireFrictionMultiplier = v11->mBlownTireFrictionMultiplier;
      if ( mWheelCollider )
      {
        if ( (*((_DWORD *)&v11->UFG::PhysicsVehicle + 151) & 7) == 2 )
          *((float *)&mWheelCollider[8].m_memSizeAndFlags + v19) = mBlownTireFrictionMultiplier;
        else
          *((float *)&mWheelCollider[7].m_alreadyUsed.m_bool + v19) = mBlownTireFrictionMultiplier;
      }
      ((void (__fastcall *)(UFG::VehicleInstance *, hkpRigidBody *, hkpVehicleSuspension *, _QWORD, hkVector4f *, hkQuaternionf *))this->mVehicle->mHavokVehicle->vfptr[5].__first_virtual_table_function__)(
        this->mVehicle->mHavokVehicle,
        this->mVehicle->mRigidBody->mBody,
        this->mVehicle->mHavokVehicle->m_suspension,
        v19,
        &v39,
        &qi);
      v42.m_translation = (hkVector4f)v39.m_quad;
      hkRotationf::set(&v42.m_rotation, &qi);
      hkTransformf::get4x4ColumnMajor(&v42, &d.v0.x);
      v25 = UFG::qMatrix44::operator*(&UFG::gWheelFixup, &result, &d);
      v15.m128_f32[0] = v15.m128_f32[0] * 0.1;
      v26 = v25->v3;
      v27 = v25->v2;
      v28 = v25->v0;
      d.v1 = v25->v1;
      v29 = this->mVehicle;
      d.v3 = v26;
      v30 = _mm_unpacklo_ps(_mm_shuffle_ps((__m128)v26, (__m128)v26, 85), _mm_shuffle_ps((__m128)v26, (__m128)v26, 255));
      d.v0 = v28;
      d.v2 = v27;
      v36 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)v26, _mm_shuffle_ps((__m128)v26, (__m128)v26, 170)), v30);
      v30.m128_i32[0] = LODWORD(v29->mBlownTireDrag) ^ _xmm[0];
      v38 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), m_quad);
      if ( v15.m128_f32[0] > 1.0 )
        v15 = (__m128)(unsigned int)FLOAT_1_0;
      v15.m128_f32[0] = v15.m128_f32[0] * v29->mBlownTireWobbleMagnitude;
      v37 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v15), (__m128)0i64);
      hkpEntity::activate(m_entity);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __m128 *))m_entity->m_motion.vfptr[11].__first_virtual_table_function__)(
        &m_entity->m_motion,
        &v37,
        &v36);
      m_storage_low = (__m128)LODWORD(stepInfo->m_deltaTime.m_storage);
      hkpEntity::activate(m_entity);
      mBlownTireWobbleFrequency_low = m_storage_low;
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, __m128 *))m_entity->m_motion.vfptr[12].__first_virtual_table_function__)(
        &m_entity->m_motion,
        v32,
        &v38,
        &v36);
    }
  }
LABEL_23:
  v33 = this->mVehicle;
  v34 = *((_DWORD *)&v33->UFG::PhysicsVehicle + 151);
  if ( (v34 & 8) != 0 && (*((_DWORD *)v33 + 274) & 8) == 0 )
  {
    if ( v33->mSpeedKPH < 0.5 )
      *((_DWORD *)&v33->UFG::PhysicsVehicle + 151) = v34 & 0xFFFFFFF7;
    v35 = this->mVehicle;
    mBlownTireWobbleFrequency_low.m128_i32[0] = LODWORD(v35->mSuperStopDrag) ^ _xmm[0];
    v36 = _mm_mul_ps(_mm_shuffle_ps(mBlownTireWobbleFrequency_low, mBlownTireWobbleFrequency_low, 0), m_quad);
    v36.m128_i32[2] = 0;
    ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, UFG::PhysicsWheeledVehicle *, __m128 *, const char *))v35->vfptr[6].__vecDelDtor)(
      v35,
      v33,
      &v36,
      "Super Stop");
  }
}

// File Line: 1667
// RVA: 0x4758A0
void __fastcall UFG::PhysicsVehicle::SetupCollisionGeometry(UFG::PhysicsVehicle *this, const char *modelName)
{
  int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int mBundleGuid; // r8d

  v3 = UFG::qStringHashUpper32(modelName, -1);
  v4 = UFG::qStringHashUpper32("_Body_P", v3);
  this->mBodyCollisionMesh = (UFG::CollisionMeshData *)UFG::BasePhysicsSystem::GetCollisionModel(
                                                         UFG::BasePhysicsSystem::mInstance,
                                                         v4);
  v5 = UFG::qStringHashUpper32("_BodyBullet_P", v3);
  this->mBulletCollisionMesh = (UFG::CollisionMeshData *)UFG::BasePhysicsSystem::GetCollisionModel(
                                                           UFG::BasePhysicsSystem::mInstance,
                                                           v5);
  mBundleGuid = this->mBodyCollisionMesh->mBundleGuid;
  this->mCollisionMeshBundle.mOwner = this;
  UFG::qResourceHandle::Init(&this->mCollisionMeshBundle, 0x1723EA91u, mBundleGuid);
}

// File Line: 1685
// RVA: 0x473C70
void __fastcall UFG::PhysicsVehicle::ResourceUnloaded(UFG::PhysicsVehicle *this, UFG::PhysicsResourceHandle *resource)
{
  UFG::SimComponent *m_pPointer; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  ArrayOfTuplesImplementation v6; // [rsp+28h] [rbp-30h] BYREF

  this->mCollisionMeshBundle.mOwner = 0i64;
  if ( this->mCoverComponent.m_pPointer )
  {
    UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&v6, this->mParams->mSimObject.m_pPointer, 1);
    ArrayOfTuplesImplementation::clear(&v6);
    UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v6);
    UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v6);
    m_pPointer = this->mCoverComponent.m_pPointer;
    if ( m_pPointer )
      m_pPointer->vfptr->__vecDelDtor(m_pPointer, 1u);
    resource = (UFG::PhysicsResourceHandle *)&this->mCoverComponent;
    if ( this->mCoverComponent.m_pPointer )
    {
      mPrev = resource->mPrev;
      mNext = this->mCoverComponent.mNext;
      mPrev->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)mNext;
      mNext->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)mPrev;
      resource->mPrev = resource;
      this->mCoverComponent.mNext = &this->mCoverComponent;
    }
    this->mCoverComponent.m_pPointer = 0i64;
  }
  ((void (__fastcall *)(UFG::PhysicsVehicle *, UFG::PhysicsResourceHandle *))this->vfptr[2].DebugDraw)(this, resource);
  UFG::PhysicsVehicle::DeleteHavokComponents(this);
}

// File Line: 1703
// RVA: 0x47F450
void __fastcall UFG::PhysicsVehicle::UpdateLevelOfDetail(UFG::PhysicsVehicle *this)
{
  UFG::PhysicsVehicle::Lod mCurrentLod; // ecx
  hkpRigidBody *mBody; // rsi
  UFG::BasePhysicsSystem *v4; // rbx
  UFG::PhysicsVehicle::Lod mDesiredLod; // ecx
  __int32 v6; // ecx
  __int32 v7; // ecx
  __int32 v8; // ecx
  UFG::SimComponent *v9; // rcx
  UFG::SimComponent *v10; // rcx
  UFG::SimComponent *v11; // rcx
  UFG::SimComponent *v12; // rcx
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimComponent *v14; // rcx

  if ( this->mCollisionMeshBundle.mUnloading )
    this->mDesiredLod = LOD_RESOURCES_UNLOADED;
  mCurrentLod = this->mCurrentLod;
  if ( this->mDesiredLod != mCurrentLod )
  {
    mBody = this->mRigidBody->mBody;
    if ( mCurrentLod == LOD_UNINITIALIZED )
    {
      v4 = UFG::BasePhysicsSystem::mInstance;
      UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, mBody, 1);
      UFG::BasePhysicsSystem::AddEntity(v4, this->mBulletCollider, 1);
    }
    mDesiredLod = this->mDesiredLod;
    this->mCurrentLod = mDesiredLod;
    v6 = mDesiredLod - 1;
    if ( !v6 )
      goto LABEL_10;
    v7 = v6 - 1;
    if ( !v7 )
    {
      m_pPointer = this->mParkourComponent.m_pPointer;
      if ( m_pPointer )
        ((void (__fastcall *)(UFG::SimComponent *))m_pPointer->vfptr[9].__vecDelDtor)(m_pPointer);
      v14 = this->mCoverComponent.m_pPointer;
      if ( v14 )
        ((void (__fastcall *)(UFG::SimComponent *))v14->vfptr[9].__vecDelDtor)(v14);
      if ( mBody )
      {
        hkpRigidBody::setMotionType(
          mBody,
          MOTION_BOX_INERTIA,
          HK_ENTITY_ACTIVATION_DO_ACTIVATE,
          HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
        mBody->m_motion.m_gravityFactor.m_value = 0;
      }
      goto LABEL_16;
    }
    v8 = v7 - 1;
    if ( !v8 )
    {
      if ( mBody )
      {
        hkpRigidBody::setMotionType(
          mBody,
          MOTION_BOX_INERTIA,
          HK_ENTITY_ACTIVATION_DO_ACTIVATE,
          HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
        mBody->m_motion.m_gravityFactor.m_value = HIWORD(FLOAT_1_0039062);
        hkpEntity::activate(mBody);
      }
      v11 = this->mParkourComponent.m_pPointer;
      if ( v11 )
        ((void (__fastcall *)(UFG::SimComponent *))v11->vfptr[9].__vecDelDtor)(v11);
      v12 = this->mCoverComponent.m_pPointer;
      if ( v12 )
        ((void (__fastcall *)(UFG::SimComponent *))v12->vfptr[9].__vecDelDtor)(v12);
      goto LABEL_16;
    }
    if ( v8 == 1 )
    {
LABEL_10:
      v9 = this->mParkourComponent.m_pPointer;
      if ( v9 )
        ((void (__fastcall *)(UFG::SimComponent *))v9->vfptr[8].__vecDelDtor)(v9);
      v10 = this->mCoverComponent.m_pPointer;
      if ( v10 )
        ((void (__fastcall *)(UFG::SimComponent *))v10->vfptr[8].__vecDelDtor)(v10);
      if ( mBody )
        hkpRigidBody::setMotionType(
          mBody,
          (hkpMotion::MotionType)(4 - this->mIsProxy),
          HK_ENTITY_ACTIVATION_DO_ACTIVATE,
          HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
    }
LABEL_16:
    ((void (__fastcall *)(UFG::PhysicsVehicle *, _QWORD))this->vfptr[5].DebugDraw)(
      this,
      (unsigned int)this->mCurrentLod);
  }
}

// File Line: 1808
// RVA: 0x4654C0
void __fastcall UFG::PhysicsVehicle::FlipVehicle(
        UFG::PhysicsVehicle *this,
        float torqueFactor,
        UFG::qVector3 *collisionPoint)
{
  hkVector4f result; // [rsp+20h] [rbp-18h] BYREF

  UFG::PhysicsVehicle::ComputeLocalXTorsionalImpulseWS(this, &result, torqueFactor, collisionPoint);
  ((void (__fastcall *)(UFG::PhysicsVehicle *, hkVector4f *, const char *))this->vfptr[7].DebugDraw)(
    this,
    &result,
    "Flip Vehicle");
}

// File Line: 1816
// RVA: 0x45B160
hkVector4f *__fastcall UFG::PhysicsVehicle::ComputeLocalXTorsionalImpulseWS(
        UFG::PhysicsVehicle *this,
        hkVector4f *result,
        float torqueFactor,
        UFG::qVector3 *collisionPoint)
{
  hkpMaxSizeMotion *p_m_motion; // rcx
  hkpRigidBody *mBody; // rcx
  __m128 v9; // xmm3
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 x_low; // xmm6
  hkVector4f v15; // xmm2
  __m128 v16; // xmm8
  __m128 m_quad; // xmm3
  __m128 v18; // xmm8
  __m128i m_col1; // xmm1
  __m128 y_low; // xmm2
  __m128 v21; // xmm6
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  hkVector4f *v26; // rax
  hkMatrix4f m; // [rsp+20h] [rbp-F8h] BYREF
  hkSimdFloat32 eps; // [rsp+60h] [rbp-B8h] BYREF
  int v29[12]; // [rsp+70h] [rbp-A8h] BYREF
  hkMatrix4f v30; // [rsp+A0h] [rbp-78h] BYREF
  hkResult resulta; // [rsp+130h] [rbp+18h] BYREF

  p_m_motion = &this->mRigidBody->mBody->m_motion;
  ((void (__fastcall *)(hkpMaxSizeMotion *, int *))p_m_motion->vfptr[3].__first_virtual_table_function__)(
    p_m_motion,
    v29);
  mBody = this->mRigidBody->mBody;
  v9 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)(unsigned int)v29[0], (__m128)(unsigned int)v29[8]),
         _mm_unpacklo_ps((__m128)(unsigned int)v29[4], (__m128)0i64));
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  v13 = _mm_andnot_ps(
          _mm_cmple_ps(v11, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
              _mm_mul_ps(*(__m128 *)_xmm, v12)),
            v11));
  v13.m128_f32[0] = v13.m128_f32[0] * torqueFactor;
  x_low = (__m128)LODWORD(collisionPoint->x);
  v15.m_quad = (__m128)_mm_srli_si128(
                         _mm_slli_si128((__m128i)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad, 4),
                         4);
  v16 = v13;
  m_quad = mBody->m_motion.m_motionState.m_transform.m_translation.m_quad;
  v18 = _mm_unpacklo_ps(_mm_unpacklo_ps(v16, (__m128)0i64), (__m128)0i64);
  m_col1 = (__m128i)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  m.m_col0 = (hkVector4f)_mm_srli_si128(
                           _mm_slli_si128(
                             (__m128i)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad,
                             4),
                           4);
  m.m_col2 = (hkVector4f)v15.m_quad;
  y_low = (__m128)LODWORD(collisionPoint->y);
  m.m_col1 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(m_col1, 4), 4);
  v21 = _mm_unpacklo_ps(x_low, (__m128)LODWORD(collisionPoint->z));
  m.m_col3.m_quad = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, query.m_quad), 196);
  v22 = _mm_unpacklo_ps(v21, _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
  eps.m_real = (__m128)_xmm;
  hkMatrix4f::setInverse(&v30, &resulta, &m, &eps);
  v23 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v30.m_col0.m_quad), v30.m_col3.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v30.m_col1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v30.m_col2.m_quad));
  v24 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), (__m128)_xmm),
          _mm_mul_ps(_mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 201), v23));
  v25 = _mm_shuffle_ps(v24, v24, 201);
  if ( _mm_shuffle_ps(v25, v25, 170).m128_f32[0] < 0.0 )
    v18 = _mm_mul_ps(v18, *(__m128 *)_xmm_bf800000bf800000bf800000bf800000);
  v26 = result;
  result->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), m.m_col1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), m.m_col0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), m.m_col2.m_quad));
  return v26;
}

// File Line: 1859
// RVA: 0x464F40
UFG::PhysicsVehicle *__fastcall UFG::PhysicsVehicle::FixupTransformForGround(
        UFG::PhysicsVehicle *this,
        UFG::qMatrix44 *localWorld)
{
  UFG::PhysicsVehicle *result; // rax
  __int64 v4; // rbx
  float v5; // xmm0_4
  float x; // xmm3_4
  float y; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  unsigned __int8 v11; // r14
  float z; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  float v15; // xmm11_4
  float v16; // xmm13_4
  float v17; // xmm10_4
  __int64 v18; // rsi
  int v19; // ebx
  float v20; // xmm12_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm9_4
  float v24; // xmm5_4
  float v25; // xmm0_4
  __int128 y_low; // xmm3
  __m128 x_low; // xmm6
  float v28; // xmm5_4
  __m128 v29; // xmm4
  float v30; // xmm1_4
  float v31; // xmm6_4
  float v32; // xmm5_4
  float v33; // xmm2_4
  __m128 v34; // xmm4
  float v35; // xmm10_4
  __m128 v36; // xmm11
  float v37; // xmm14_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  UFG::qVector3 v41; // [rsp+20h] [rbp-E0h] BYREF
  UFG::qVector3 v42; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qVector3 rayStart; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 rayEnd; // [rsp+50h] [rbp-B0h] BYREF
  UFG::RayCastData data; // [rsp+60h] [rbp-A0h] BYREF
  UFG::RayCastData v46; // [rsp+140h] [rbp+40h] BYREF

  result = 0i64;
  if ( (*((_BYTE *)this + 604) & 7) != 0 )
    result = this;
  if ( result )
  {
    v41.y = 0.0;
    v41.x = FLOAT_2_0;
    v42.z = 0.0;
    v4 = 0i64;
    v41.z = FLOAT_10_0;
    v42.y = FLOAT_N10_0;
    v42.x = FLOAT_N2_0;
    while ( 1 )
    {
      v5 = *(float *)((char *)&v41.x + v4);
      x = localWorld->v3.x;
      y = localWorld->v3.y;
      data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
      data.mInput.m_filterInfo = 0;
      v8 = v5 + localWorld->v3.z;
      rayStart.x = x;
      rayStart.y = y;
      data.mInput.m_userData = 0i64;
      data.mOutput.m_hitFraction = 1.0;
      data.mOutput.m_extraInfo = -1;
      rayStart.z = v8;
      v9 = *(float *)((char *)&v42.x + v4);
      rayEnd.x = x;
      data.mOutput.m_shapeKeyIndex = 0;
      data.mOutput.m_shapeKeys[0] = -1;
      data.mOutput.m_rootCollidable = 0i64;
      v10 = v9 + localWorld->v3.z;
      rayEnd.y = y;
      data.mDebugName = "PhysicsVehicle";
      data.mCollisionModelName.mUID = -1;
      rayEnd.z = v10;
      UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0x11u);
      v11 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
      if ( v11 )
        break;
      v4 += 4i64;
      if ( v4 >= 12 )
        return (UFG::PhysicsVehicle *)v11;
    }
    z = data.normal.z;
    v13 = data.normal.x;
    v14 = data.normal.y;
    if ( data.normal.z <= 0.69999999 )
    {
      v15 = UFG::qVector3::msZero.x;
      v16 = UFG::qVector3::msZero.z;
      v17 = 0.0;
      v18 = 6i64;
      v19 = 0;
      v20 = UFG::qVector3::msZero.y;
      do
      {
        v21 = sinf(v17);
        v22 = cosf(v17);
        v46.mInput.m_enableShapeCollectionFilter.m_bool = 0;
        v46.mInput.m_filterInfo = 0;
        v42.y = rayEnd.y + v21;
        v42.x = rayEnd.x + v22;
        v46.mInput.m_userData = 0i64;
        v46.mOutput.m_hitFraction = 1.0;
        v46.mOutput.m_extraInfo = -1;
        v46.mOutput.m_shapeKeyIndex = 0;
        v46.mOutput.m_shapeKeys[0] = -1;
        v46.mOutput.m_rootCollidable = 0i64;
        v42.z = rayEnd.z;
        v41.x = rayStart.x + v22;
        v46.mDebugName = "PhysicsVehicle";
        v46.mCollisionModelName.mUID = -1;
        v41.y = rayStart.y + v21;
        v41.z = rayStart.z;
        UFG::RayCastData::Init(&v46, &v41, &v42, 0x11u);
        if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &v46) )
        {
          v13 = v13 + v46.normal.x;
          v14 = v14 + v46.normal.y;
          z = z + v46.normal.z;
          if ( v46.normal.z > 0.69999999 )
          {
            ++v19;
            v15 = v15 + v46.normal.x;
            v20 = v20 + v46.normal.y;
            v16 = v16 + v46.normal.z;
          }
        }
        v17 = v17 + 1.0471976;
        --v18;
      }
      while ( v18 );
      if ( v19 <= 0 )
      {
        v13 = v13 * 0.14285715;
        v14 = v14 * 0.14285715;
        z = z * 0.14285715;
      }
      else
      {
        v23 = 1.0 / (float)v19;
        z = v23 * v16;
        v13 = v23 * v15;
        v14 = v23 * v20;
      }
    }
    y_low = LODWORD(localWorld->v0.y);
    v24 = localWorld->v0.z;
    v25 = *(float *)&y_low;
    x_low = (__m128)LODWORD(localWorld->v0.x);
    *(float *)&y_low = (float)(*(float *)&y_low * v13) - (float)(x_low.m128_f32[0] * v14);
    x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * z) - (float)(v24 * v13);
    v28 = (float)(v24 * v14) - (float)(v25 * z);
    v29 = x_low;
    v29.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v28 * v28))
                    + (float)(*(float *)&y_low * *(float *)&y_low);
    if ( v29.m128_f32[0] == 0.0 )
      v30 = 0.0;
    else
      v30 = 1.0 / _mm_sqrt_ps(v29).m128_f32[0];
    v31 = x_low.m128_f32[0] * v30;
    *(float *)&y_low = *(float *)&y_low * v30;
    v32 = v28 * v30;
    v34 = (__m128)y_low;
    v33 = (float)(v31 * z) - (float)(*(float *)&y_low * v14);
    v34.m128_f32[0] = (float)(*(float *)&y_low * v13) - (float)(v32 * z);
    v36 = v34;
    v35 = (float)(v32 * v14) - (float)(v31 * v13);
    v36.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v33 * v33)) + (float)(v35 * v35);
    if ( v36.m128_f32[0] == 0.0 )
      v37 = 0.0;
    else
      v37 = 1.0 / _mm_sqrt_ps(v36).m128_f32[0];
    v38 = data.point.x;
    v39 = data.point.y;
    localWorld->v2.w = 0.0;
    localWorld->v2.x = v13;
    localWorld->v2.y = v14;
    localWorld->v2.z = z;
    localWorld->v3.w = 1.0;
    localWorld->v3.x = v38;
    v40 = data.point.z;
    localWorld->v3.y = v39;
    localWorld->v3.z = v40;
    localWorld->v0.z = v35 * v37;
    localWorld->v0.x = v33 * v37;
    localWorld->v0.w = 0.0;
    localWorld->v0.y = v34.m128_f32[0] * v37;
    localWorld->v1.y = v31;
    localWorld->v1.x = v32;
    localWorld->v1.w = 0.0;
    LODWORD(localWorld->v1.z) = y_low;
    return (UFG::PhysicsVehicle *)v11;
  }
  return result;
}

// File Line: 1958
// RVA: 0x475440
void __fastcall UFG::PhysicsVehicle::SetPositionAndOrientation(UFG::PhysicsVehicle *this, UFG::qMatrix44 *mat)
{
  float y; // xmm1_4
  float x; // xmm0_4
  hkMatrix4f matrixIn; // [rsp+20h] [rbp-138h] BYREF
  hkMatrixDecompositionImpl<float>::Decomposition decompOut; // [rsp+60h] [rbp-F8h] BYREF

  if ( this->mRigidBody->mBody )
  {
    y = mat->v0.y;
    matrixIn.m_col0.m_quad.m128_i32[0] = LODWORD(mat->v0.x);
    *(unsigned __int64 *)((char *)matrixIn.m_col0.m_quad.m128_u64 + 4) = __PAIR64__(LODWORD(mat->v0.z), LODWORD(y));
    x = mat->v1.x;
    matrixIn.m_col0.m_quad.m128_i32[3] = LODWORD(mat->v0.w);
    matrixIn.m_col1.m_quad.m128_u64[0] = __PAIR64__(LODWORD(mat->v1.y), LODWORD(x));
    matrixIn.m_col1.m_quad.m128_u64[1] = *(_QWORD *)&mat->v1.z;
    matrixIn.m_col2 = (hkVector4f)mat->v2;
    matrixIn.m_col3 = (hkVector4f)mat->v3;
    hkMatrixDecompositionImpl<float>::decomposeMatrix(&matrixIn, &decompOut);
    hkpRigidBody::setPositionAndRotation(this->mRigidBody->mBody, &decompOut.m_translation, &decompOut.m_rotation);
  }
}

// File Line: 1972
// RVA: 0x4681D0
UFG::qVector3 *__fastcall UFG::PhysicsVehicle::GetVelocity(UFG::PhysicsVehicle *this, UFG::qVector3 *result)
{
  UFG::RigidBody::GetVelocity(this->mRigidBody, result);
  return result;
}

// File Line: 1979
// RVA: 0x475850
void __fastcall UFG::PhysicsVehicle::SetVelocity(UFG::PhysicsVehicle *this, UFG::qVector3 *velocity)
{
  UFG::RigidBody::SetVelocity(this->mRigidBody, velocity);
}

// File Line: 1986
// RVA: 0x4660D0
UFG::qVector3 *__fastcall UFG::PhysicsVehicle::GetAngularVelocity(UFG::PhysicsVehicle *this, UFG::qVector3 *result)
{
  UFG::RigidBody::GetAngularVelocity(this->mRigidBody, result);
  return result;
}

// File Line: 1994
// RVA: 0x4828B0
void __fastcall UFG::PhysicsVehicle::applyForce(
        UFG::PhysicsVehicle *this,
        const float deltaTime,
        hkVector4f *force,
        const char *dbgName)
{
  hkpRigidBody *mBody; // rbx
  __int64 v6; // rdx

  mBody = this->mRigidBody->mBody;
  hkpEntity::activate(mBody);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))mBody->m_motion.hkpEntity::vfptr[13].__vecDelDtor)(
    &mBody->m_motion,
    v6,
    force);
}

// File Line: 2009
// RVA: 0x482AE0
void __fastcall UFG::PhysicsVehicle::applyTorque(
        UFG::PhysicsVehicle *this,
        const float deltaTime,
        hkVector4f *torque,
        const char *dbgName)
{
  hkpRigidBody *mBody; // rbx
  __int64 v6; // rdx

  mBody = this->mRigidBody->mBody;
  hkpEntity::activate(mBody);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))mBody->m_motion.hkpEntity::vfptr[13].__first_virtual_table_function__)(
    &mBody->m_motion,
    v6,
    torque);
}

// File Line: 2024
// RVA: 0x482830
void __fastcall UFG::PhysicsVehicle::applyAngularImpulse(
        UFG::PhysicsVehicle *this,
        hkVector4f *imp,
        const char *dbgName)
{
  hkpRigidBody *mBody; // rbx

  mBody = this->mRigidBody->mBody;
  hkpEntity::activate(mBody);
  mBody->m_motion.hkpEntity::vfptr[12].__vecDelDtor(&mBody->m_motion, (unsigned int)imp);
}

// File Line: 2040
// RVA: 0x482940
void __fastcall UFG::PhysicsVehicle::applyLinearImpulse(
        UFG::PhysicsVehicle *this,
        hkVector4f *imp,
        const char *dbgName)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  float v7; // xmm4_4
  hkpRigidBody *mBody; // rbx

  v4 = _mm_mul_ps(imp->m_quad, imp->m_quad);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v6 = _mm_rsqrt_ps(v5);
  v7 = _mm_andnot_ps(
         _mm_cmple_ps(v5, (__m128)0i64),
         _mm_mul_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v5), v6)), _mm_mul_ps(*(__m128 *)_xmm, v6)),
           v5)).m128_f32[0];
  if ( v7 < 0.0 )
    LODWORD(v7) ^= _xmm[0];
  if ( v7 >= 0.1 )
  {
    mBody = this->mRigidBody->mBody;
    hkpEntity::activate(mBody);
    mBody->m_motion.hkpEntity::vfptr[11].__vecDelDtor(&mBody->m_motion, (unsigned int)imp);
  }
}

// File Line: 2058
// RVA: 0x482A30
void __fastcall UFG::PhysicsVehicle::applyPointImpulse(
        UFG::PhysicsVehicle *this,
        hkVector4f *imp,
        hkVector4f *p,
        const char *dbgName)
{
  hkpRigidBody *mBody; // rbx

  mBody = this->mRigidBody->mBody;
  hkpEntity::activate(mBody);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkVector4f *))mBody->m_motion.hkpEntity::vfptr[11].__first_virtual_table_function__)(
    &mBody->m_motion,
    imp,
    p);
}

// File Line: 2073
// RVA: 0x488550
void __fastcall UFG::PhysicsVehicle::setAngularVelocity(
        UFG::PhysicsVehicle *this,
        hkVector4f *newVel,
        const char *dbgName)
{
  hkpRigidBody *mBody; // rbx

  mBody = this->mRigidBody->mBody;
  hkpEntity::activate(mBody);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))mBody->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
    &mBody->m_motion,
    newVel);
}

// File Line: 2088
// RVA: 0x4885D0
void __fastcall UFG::PhysicsVehicle::setLinearVelocity(
        UFG::PhysicsVehicle *this,
        hkVector4f *newVel,
        const char *dbgName)
{
  hkpRigidBody *mBody; // rbx

  mBody = this->mRigidBody->mBody;
  hkpEntity::activate(mBody);
  mBody->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&mBody->m_motion, (unsigned int)newVel);
}

// File Line: 2104
// RVA: 0x482900
void __fastcall UFG::PhysicsVehicle::applyForce(
        UFG::PhysicsVehicle *this,
        const float deltaTime,
        UFG::qVector3 *force,
        const char *dbgName)
{
  __int64 v4; // rdx
  UFG::BasePhysicsObjectVtbl *vfptr; // rax
  __m128 v6; // [rsp+20h] [rbp-18h] BYREF

  vfptr = this->vfptr;
  v6 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(force->x), (__m128)LODWORD(force->z)),
         _mm_unpacklo_ps((__m128)LODWORD(force->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __int64, __m128 *, const char *))vfptr[6].__vecDelDtor)(
    this,
    v4,
    &v6,
    dbgName);
}

// File Line: 2110
// RVA: 0x482B30
void __fastcall UFG::PhysicsVehicle::applyTorque(
        UFG::PhysicsVehicle *this,
        const float deltaTime,
        UFG::qVector3 *torque,
        const char *dbgName)
{
  __int64 v4; // rdx
  UFG::BasePhysicsObjectVtbl *vfptr; // rax
  __m128 v6; // [rsp+20h] [rbp-18h] BYREF

  vfptr = this->vfptr;
  v6 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(torque->x), (__m128)LODWORD(torque->z)),
         _mm_unpacklo_ps((__m128)LODWORD(torque->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __int64, __m128 *, const char *))vfptr[6].ResourceUnloaded)(
    this,
    v4,
    &v6,
    dbgName);
}

// File Line: 2117
// RVA: 0x482870
void __fastcall UFG::PhysicsVehicle::applyAngularImpulse(
        UFG::PhysicsVehicle *this,
        UFG::qVector3 *imp,
        const char *dbgName)
{
  UFG::BasePhysicsObjectVtbl *vfptr; // rax
  __m128 v4; // [rsp+20h] [rbp-18h] BYREF

  vfptr = this->vfptr;
  v4 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(imp->x), (__m128)LODWORD(imp->z)),
         _mm_unpacklo_ps((__m128)LODWORD(imp->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __m128 *, const char *))vfptr[7].DebugDraw)(this, &v4, dbgName);
}

// File Line: 2123
// RVA: 0x4829F0
void __fastcall UFG::PhysicsVehicle::applyLinearImpulse(
        UFG::PhysicsVehicle *this,
        UFG::qVector3 *imp,
        const char *dbgName)
{
  UFG::BasePhysicsObjectVtbl *vfptr; // rax
  __m128 v4; // [rsp+20h] [rbp-18h] BYREF

  vfptr = this->vfptr;
  v4 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(imp->x), (__m128)LODWORD(imp->z)),
         _mm_unpacklo_ps((__m128)LODWORD(imp->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __m128 *, const char *))vfptr[8].__vecDelDtor)(this, &v4, dbgName);
}

// File Line: 2129
// RVA: 0x482A80
void __fastcall UFG::PhysicsVehicle::applyPointImpulse(
        UFG::PhysicsVehicle *this,
        UFG::qVector3 *imp,
        UFG::qVector3 *p,
        const char *dbgName)
{
  UFG::BasePhysicsObjectVtbl *vfptr; // rax
  __m128 z_low; // xmm0
  __m128 y_low; // xmm2
  __m128 v7; // [rsp+20h] [rbp-28h] BYREF
  __m128 v8; // [rsp+30h] [rbp-18h] BYREF

  vfptr = this->vfptr;
  z_low = (__m128)LODWORD(p->z);
  y_low = (__m128)LODWORD(p->y);
  v8 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(imp->x), (__m128)LODWORD(imp->z)),
         _mm_unpacklo_ps((__m128)LODWORD(imp->y), (__m128)0i64));
  v7 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)LODWORD(p->x), z_low), _mm_unpacklo_ps(y_low, (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __m128 *, __m128 *, const char *))vfptr[8].ResourceUnloaded)(
    this,
    &v8,
    &v7,
    dbgName);
}

// File Line: 2137
// RVA: 0x488590
void __fastcall UFG::PhysicsVehicle::setAngularVelocity(
        UFG::PhysicsVehicle *this,
        UFG::qVector3 *newVel,
        const char *dbgName)
{
  UFG::BasePhysicsObjectVtbl *vfptr; // rax
  __m128 v4; // [rsp+20h] [rbp-18h] BYREF

  vfptr = this->vfptr;
  v4 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(newVel->x), (__m128)LODWORD(newVel->z)),
         _mm_unpacklo_ps((__m128)LODWORD(newVel->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __m128 *, const char *))vfptr[9].DebugDraw)(this, &v4, dbgName);
}

// File Line: 2143
// RVA: 0x488610
void __fastcall UFG::PhysicsVehicle::setLinearVelocity(
        UFG::PhysicsVehicle *this,
        UFG::qVector3 *newVel,
        const char *dbgName)
{
  UFG::BasePhysicsObjectVtbl *vfptr; // rax
  __m128 v4; // [rsp+20h] [rbp-18h] BYREF

  vfptr = this->vfptr;
  v4 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(newVel->x), (__m128)LODWORD(newVel->z)),
         _mm_unpacklo_ps((__m128)LODWORD(newVel->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __m128 *, const char *))vfptr[10].__vecDelDtor)(this, &v4, dbgName);
}

// File Line: 2167
// RVA: 0x44C7F0
void __fastcall UFG::PhysicsWheeledVehicle::PhysicsWheeledVehicle(
        UFG::PhysicsWheeledVehicle *this,
        UFG::VehicleParams *param,
        UFG::qMatrix44 *transform,
        UFG::qVector3 *velocity,
        UFG::qVector3 *wheelPositions)
{
  hkpReorientAction *v6; // rbx
  UFG::qReflectObject *mData; // rsi
  __m128 mNext_high; // xmm6
  __m128 v9; // xmm0
  __m128 v10; // xmm13
  __m128 vfptr_low; // xmm6
  __m128 v12; // xmm0
  __m128 v13; // xmm14
  __m128 v14; // xmm10
  __m128 vfptr_high; // xmm11
  __m128 mUID_low; // xmm12
  __m128 mUID_high; // xmm7
  __m128 mParent_low; // xmm8
  __m128 mParent_high; // xmm9
  UFG::VehicleParams *mParams; // rax
  __int64 firstFrontWheel; // r9
  __m128 v22; // xmm5
  _DWORD *v23; // rcx
  hkVector4f *v24; // rdx
  float *v25; // r8
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  UFG::VehicleParams *v29; // rax
  __int64 firstRearWheel; // r9
  __m128 v31; // xmm5
  _DWORD *v32; // rcx
  hkVector4f *v33; // rdx
  float *v34; // r8
  __m128 v35; // xmm0
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  unsigned int v38; // edx
  UFG::qSafeArray<float,4> *p_mLateralSkidStrength; // rcx
  _QWORD **Value; // rax
  hkpReorientAction *v41; // rax
  hkpReorientAction *v42; // rax
  float v43; // [rsp+30h] [rbp-F8h]
  float v44; // [rsp+38h] [rbp-F0h]
  UFG::qReflectHandleBase v45; // [rsp+40h] [rbp-E8h] BYREF
  __int64 v46; // [rsp+68h] [rbp-C0h]
  hkVector4f rotationAxis; // [rsp+70h] [rbp-B8h] BYREF
  hkVector4f upAxis; // [rsp+80h] [rbp-A8h] BYREF

  v46 = -2i64;
  UFG::PhysicsVehicle::PhysicsVehicle(this, param, transform, velocity);
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsWheeledVehicle::`vftable;
  v6 = 0i64;
  this->mWheelCollider = 0i64;
  this->mHavokVehicle = 0i64;
  this->mVehicleAction = 0i64;
  this->mEngine = 0i64;
  this->mTransmission = 0i64;
  this->mBrakes = 0i64;
  this->mSteering = 0i64;
  this->mAerodynamics = 0i64;
  this->mPreviousSpeed = 0.0;
  *((_DWORD *)this + 274) = *((_DWORD *)this + 274) & 0xFFFFFFA0 | 0x10;
  UFG::qReflectHandleBase::qReflectHandleBase(&v45);
  v45.mTypeUID = UFG::qStringHash64("UFG::WheeledVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v45, v45.mTypeUID, this->mDnaDefinition.mData->mBaseNode.mUID);
  UFG::PhysicsWheeledVehicle::LoadProperties(this);
  mData = v45.mData;
  this->mWheelRadius = *(float *)v45.mData[5].mBaseNode.mChildren;
  this->mLodHeightFixupFront = *((float *)&mData[8].mBaseNode.mUID + 1);
  this->mLodHeightFixupRear = *(float *)&mData[8].mBaseNode.mParent;
  mNext_high = (__m128)HIDWORD(mData[4].mHandles.mNode.mNext);
  mNext_high.m128_f32[0] = (float)(mNext_high.m128_f32[0] * 3.1415927) * 0.0055555557;
  v43 = sinf(mNext_high.m128_f32[0]);
  v9 = mNext_high;
  v9.m128_f32[0] = cosf(mNext_high.m128_f32[0]);
  v10 = v9;
  vfptr_low = (__m128)LODWORD(mData[5].vfptr);
  vfptr_low.m128_f32[0] = (float)(vfptr_low.m128_f32[0] * 3.1415927) * 0.0055555557;
  v44 = sinf(vfptr_low.m128_f32[0]);
  v12 = vfptr_low;
  v12.m128_f32[0] = cosf(vfptr_low.m128_f32[0]);
  v13 = v12;
  v14 = (__m128)LODWORD(mData[3].vfptr);
  vfptr_high = (__m128)HIDWORD(mData[3].vfptr);
  mUID_low = (__m128)LODWORD(mData[3].mBaseNode.mUID);
  mUID_high = (__m128)HIDWORD(mData[3].mBaseNode.mUID);
  mParent_low = (__m128)LODWORD(mData[3].mBaseNode.mParent);
  mParent_high = (__m128)HIDWORD(mData[3].mBaseNode.mParent);
  mParams = this->mParams;
  firstFrontWheel = mParams->firstFrontWheel;
  if ( (int)firstFrontWheel <= mParams->lastFrontWheel )
  {
    v22 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)LODWORD(v43), _mm_xor_ps(v10, *(__m128 *)_xmm)), (__m128)0i64);
    v23 = (_DWORD *)&this->mSuspensionUpTravelLimit.array[firstFrontWheel];
    v24 = &this->mHardPointChassisSpace[firstFrontWheel];
    v25 = &wheelPositions->y + 2 * firstFrontWheel + firstFrontWheel;
    do
    {
      v24[4] = (hkVector4f)v22;
      v26 = mUID_low;
      v26.m128_f32[0] = mUID_low.m128_f32[0] + v25[1];
      v27 = vfptr_high;
      v27.m128_f32[0] = vfptr_high.m128_f32[0] + *v25;
      v28 = v14;
      v28.m128_f32[0] = v14.m128_f32[0] + *(v25 - 1);
      v24->m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v28, v26), _mm_unpacklo_ps(v27, (__m128)(unsigned int)FLOAT_1_0));
      v26.m128_i32[0] = HIDWORD(mData[8].mBaseNode.mParent);
      *(v23 - 4) = v26.m128_i32[0];
      *v23 = HIDWORD(mData[4].mTypeUID);
      v23[4] = HIDWORD(mData[4].mHandles.mNode.mPrev);
      *(v23 - 37) = v26.m128_i32[0];
      LODWORD(firstFrontWheel) = firstFrontWheel + 1;
      ++v24;
      ++v23;
      v25 += 3;
    }
    while ( (int)firstFrontWheel <= this->mParams->lastFrontWheel );
  }
  v29 = this->mParams;
  firstRearWheel = v29->firstRearWheel;
  if ( (int)firstRearWheel <= v29->lastRearWheel )
  {
    v31 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)LODWORD(v44), _mm_xor_ps(v13, *(__m128 *)_xmm)), (__m128)0i64);
    v32 = (_DWORD *)&this->mSuspensionUpTravelLimit.array[firstRearWheel];
    v33 = &this->mHardPointChassisSpace[firstRearWheel];
    v34 = &wheelPositions->y + 2 * firstRearWheel + firstRearWheel;
    do
    {
      v33[4] = (hkVector4f)v31;
      v35 = mParent_high;
      v35.m128_f32[0] = mParent_high.m128_f32[0] + v34[1];
      v36 = mParent_low;
      v36.m128_f32[0] = mParent_low.m128_f32[0] + *v34;
      v37 = mUID_high;
      v37.m128_f32[0] = mUID_high.m128_f32[0] + *(v34 - 1);
      v33->m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v37, v35), _mm_unpacklo_ps(v36, (__m128)(unsigned int)FLOAT_1_0));
      v35.m128_i32[0] = (int)mData[8].mBaseNode.mChildren[0];
      *(v32 - 4) = v35.m128_i32[0];
      *v32 = mData[4].mHandles.mNode.mPrev;
      v32[4] = mData[4].mHandles.mNode.mNext;
      *(v32 - 37) = v35.m128_i32[0];
      LODWORD(firstRearWheel) = firstRearWheel + 1;
      ++v33;
      ++v32;
      v34 += 3;
    }
    while ( (int)firstRearWheel <= this->mParams->lastRearWheel );
  }
  v38 = 0;
  if ( (*((_BYTE *)&this->UFG::PhysicsVehicle + 604) & 7) != 0 )
  {
    p_mLateralSkidStrength = &this->mLateralSkidStrength;
    do
    {
      p_mLateralSkidStrength[-2].array[0] = 0.0;
      p_mLateralSkidStrength->array[0] = 0.0;
      p_mLateralSkidStrength[-1].array[0] = 0.0;
      p_mLateralSkidStrength[8].array[1] = 0.0;
      p_mLateralSkidStrength[1].array[0] = 0.0;
      ++v38;
      p_mLateralSkidStrength = (UFG::qSafeArray<float,4> *)((char *)p_mLateralSkidStrength + 4);
    }
    while ( v38 < (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) );
  }
  if ( this->mPitchStability > 0.0099999998 )
  {
    rotationAxis.m_quad = _xmm;
    upAxis.m_quad = _xmm;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v41 = (hkpReorientAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
    if ( v41 )
    {
      hkpReorientAction::hkpReorientAction(
        v41,
        this->mRigidBody->mBody,
        &rotationAxis,
        &upAxis,
        this->mPitchStability,
        0.1);
      v6 = v42;
    }
    this->mReorientActionPitch = v6;
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v45);
}

// File Line: 2226
// RVA: 0x450930
void __fastcall UFG::PhysicsWheeledVehicle::~PhysicsWheeledVehicle(UFG::PhysicsWheeledVehicle *this)
{
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsWheeledVehicle::`vftable;
  UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents(this);
  UFG::PhysicsVehicle::~PhysicsVehicle(this);
}

// File Line: 2233
// RVA: 0x472C20
void __fastcall UFG::PhysicsWheeledVehicle::Reload(UFG::PhysicsWheeledVehicle *this, UFG::qSymbol *propertySetName)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v4; // rax
  UFG::VehicleParams *mParams; // rax
  __int64 firstFrontWheel; // r9
  __int64 v7; // r8
  UFG::VehicleParams *v8; // rax
  __int64 firstRearWheel; // r8
  __int64 v10; // r9
  unsigned int v11; // r9d
  __int64 v12; // r8
  hkpVehicleData::WheelComponentParams *m_data; // rax
  UFG::qReflectObject *mData; // rdx
  UFG::VehicleAerodynamics *mAerodynamics; // rcx
  UFG::qReflectHandleBase v16; // [rsp+48h] [rbp-30h] BYREF

  this->mParams->mPhysicsPropertiesName.mUID = propertySetName->mUID;
  mUID = this->mParams->mPhysicsPropertiesName.mUID;
  if ( mUID )
  {
    v4 = UFG::qBaseTreeRB::Get(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree, mUID);
    if ( v4 )
      UFG::qReflectHandleBase::Init(
        &this->mDnaDefinition,
        this->mDnaDefinition.mTypeUID,
        (unsigned __int64)v4->mNULL.mParent);
  }
  UFG::PhysicsVehicle::LoadProperties(this);
  UFG::PhysicsWheeledVehicle::LoadProperties(this);
  if ( this->mHavokVehicle )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v16);
    v16.mTypeUID = UFG::qStringHash64("UFG::WheeledVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v16, v16.mTypeUID, this->mDnaDefinition.mData->mBaseNode.mUID);
    this->mHavokVehicle->m_data->m_torqueRollFactor = *((float *)&v16.mData[5].mTypeUID + 1);
    this->mHavokVehicle->m_data->m_torquePitchFactor = *(float *)&v16.mData[5].mHandles.mNode.mPrev;
    this->mHavokVehicle->m_data->m_torqueYawFactor = *((float *)&v16.mData[5].mHandles.mNode.mPrev + 1);
    this->mHavokVehicle->m_data->m_extraTorqueFactor = *(float *)&v16.mData[5].mHandles.mNode.mNext;
    this->mHavokVehicle->m_data->m_maxVelocityForPositionalFriction = *((float *)v16.mData[8].mBaseNode.mChildren + 1);
    this->mHavokVehicle->m_data->m_chassisUnitInertiaYaw = *(float *)&v16.mData[6].vfptr;
    this->mHavokVehicle->m_data->m_chassisUnitInertiaRoll = *((float *)&v16.mData[6].vfptr + 1);
    this->mHavokVehicle->m_data->m_chassisUnitInertiaPitch = *(float *)&v16.mData[6].mBaseNode.mUID;
    mParams = this->mParams;
    firstFrontWheel = mParams->firstFrontWheel;
    if ( (int)firstFrontWheel <= mParams->lastFrontWheel )
    {
      v7 = firstFrontWheel;
      do
      {
        this->mHavokVehicle->m_data->m_wheelParams.m_data[v7].m_friction = *((float *)v16.mData[5].mBaseNode.mChildren
                                                                           + 1);
        LODWORD(firstFrontWheel) = firstFrontWheel + 1;
        ++v7;
      }
      while ( (int)firstFrontWheel <= this->mParams->lastFrontWheel );
    }
    v8 = this->mParams;
    firstRearWheel = v8->firstRearWheel;
    if ( (int)firstRearWheel <= v8->lastRearWheel )
    {
      v10 = firstRearWheel;
      do
      {
        this->mHavokVehicle->m_data->m_wheelParams.m_data[v10].m_friction = *(float *)&v16.mData[5].mBaseNode.mChildren[1];
        LODWORD(firstRearWheel) = firstRearWheel + 1;
        ++v10;
      }
      while ( (int)firstRearWheel <= this->mParams->lastRearWheel );
    }
    v11 = 0;
    if ( (*((_BYTE *)&this->UFG::PhysicsVehicle + 604) & 7) != 0 )
    {
      v12 = 0i64;
      do
      {
        this->mHavokVehicle->m_data->m_wheelParams.m_data[v12].m_mass = *((float *)v16.mData[6].mBaseNode.mChildren + 1);
        this->mHavokVehicle->m_data->m_wheelParams.m_data[v12].m_viscosityFriction = *(float *)&v16.mData[6].mBaseNode.mChildren[1];
        this->mHavokVehicle->m_data->m_wheelParams.m_data[v12].m_slipAngle = *((float *)&v16.mData[6].mBaseNode.mChildren[1]
                                                                             + 1);
        m_data = this->mHavokVehicle->m_data->m_wheelParams.m_data;
        m_data[v12].m_maxFriction = m_data[v12].m_friction * 2.0;
        ++v11;
        ++v12;
      }
      while ( v11 < (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) );
    }
    UFG::Engine::InitializeFromPropertySet(this->mEngine, (UFG::WheeledVehiclePhysicsDef *)v16.mData);
    UFG::Transmission::InitializeFromPropertySet(
      this->mTransmission,
      (UFG::WheeledVehiclePhysicsDef *)v16.mData,
      *((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7,
      this->mParams->firstFrontWheel,
      this->mParams->lastFrontWheel,
      this->mParams->firstRearWheel,
      this->mParams->lastRearWheel);
    UFG::Brakes::InitializeFromPropertySet(
      this->mBrakes,
      (UFG::WheeledVehiclePhysicsDef *)v16.mData,
      *((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7,
      this->mParams->firstFrontWheel,
      this->mParams->lastFrontWheel,
      this->mParams->firstRearWheel,
      this->mParams->lastRearWheel);
    UFG::Steering::InitializeFromPropertySet(
      this->mSteering,
      (UFG::WheeledVehiclePhysicsDef *)v16.mData,
      *((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7,
      this->mParams->firstFrontWheel,
      this->mParams->lastFrontWheel,
      this->mParams->firstRearWheel,
      this->mParams->lastRearWheel);
    mData = v16.mData;
    mAerodynamics = this->mAerodynamics;
    mAerodynamics->m_airDensity = *((float *)v16.mData[6].mBaseNode.mNeighbours + 1);
    mAerodynamics->m_frontalArea = *(float *)mData[5].mBaseNode.mNeighbours;
    mAerodynamics->m_dragCoefficient = *((float *)mData[5].mBaseNode.mNeighbours + 1);
    mAerodynamics->m_liftCoefficient = *(float *)&mData[5].mBaseNode.mNeighbours[1];
    UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
  }
}

// File Line: 2303
// RVA: 0x46BBB0
void __fastcall UFG::PhysicsWheeledVehicle::LoadProperties(UFG::PhysicsWheeledVehicle *this)
{
  UFG::qReflectObject *mData; // rcx
  UFG::qReflectHandleBase v3; // [rsp+28h] [rbp-30h] BYREF

  UFG::qReflectHandleBase::qReflectHandleBase(&v3);
  v3.mTypeUID = UFG::qStringHash64("UFG::WheeledVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v3, v3.mTypeUID, this->mDnaDefinition.mData->mBaseNode.mUID);
  mData = v3.mData;
  this->mBurnoutMinSpeed = *(float *)&v3.mData[7].mBaseNode.mUID;
  this->mBurnoutMaxSpeed = *((float *)&mData[7].mBaseNode.mUID + 1);
  *(_QWORD *)&this->mBurnoutSpinTorqueAtLowSpeed = mData[7].mBaseNode.mParent;
  *(_OWORD *)&this->mBurnoutSpinFrontTireFrictionAtLowSpeed = *(_OWORD *)mData[7].mBaseNode.mChildren;
  *((_DWORD *)this + 274) ^= (*((_DWORD *)this + 274) ^ (32 * LOBYTE(mData[8].mBaseNode.mChildren[1]))) & 0x20;
  *(_OWORD *)&this->mBurnoutTorqueFactor_LowSpeed = *(_OWORD *)mData[7].mBaseNode.mNeighbours;
  *(_QWORD *)&this->mBurnoutFwdThrustFactor_HighSpeed = mData[7].mTypeUID;
  *(UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mJTurnSpinTorque = mData[7].mHandles;
  this->mBlownTireWobbleFrequency = *(float *)&mData[8].vfptr;
  this->mBlownTireDrag = *((float *)&mData[8].vfptr + 1);
  this->mBlownTireFrictionMultiplier = *(float *)&mData[8].mBaseNode.mUID;
  this->mDollarValue = *(float *)&mData[1].mHandles.mNode.mPrev;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v3);
}

// File Line: 2342
// RVA: 0x47AFD0
void __fastcall UFG::PhysicsWheeledVehicle::Update(
        UFG::PhysicsWheeledVehicle *this,
        UFG::qMatrix44 *targetTransform,
        UFG::VehicleInput *driverInput,
        float deltaTime)
{
  UFG::WaterFloatingTrackerComponent *mWaterFloatingTrackerComponent; // rax
  int mInWaterState; // eax
  hkpRigidBody *mBody; // rcx
  UFG::PhysicsVehicle::Lod mCurrentLod; // eax
  unsigned int v12; // esi
  UFG::qSafeArray<float,4> *p_mCurrentSuspensionLength; // rbx
  float v14; // xmm0_4
  hkpVehicleEngine *m_engine; // rcx
  float mSpeedKPH; // xmm3_4
  bool v17; // dl
  float z; // xmm2_4
  float v19; // xmm0_4
  unsigned int v20; // r9d
  __int64 v21; // rdx
  UFG::qSafeArray<float,4> *p_mWheelSpinAngle; // r8
  hkpVehicleInstance::WheelInfo *m_data; // rcx
  float v24; // xmm9_4
  float v25; // xmm14_4
  hkpVehicleWheelCollide *v26; // rdx
  __int64 v27; // r8
  hkpVehicleWheelCollide *mWheelCollider; // rcx
  int v29; // eax
  float v30; // xmm0_4
  float v31; // xmm0_4
  int v32; // xmm12_4
  float v33; // xmm13_4
  UFG::Engine *mEngine; // rax
  float mBurnoutSpinFrontTireFrictionAtHighSpeed; // xmm1_4
  float mBurnoutSpinFrontTireFrictionAtLowSpeed; // xmm2_4
  __m128 v37; // xmm6
  float v38; // xmm3_4
  float v39; // xmm4_4
  float v40; // xmm8_4
  float v41; // xmm5_4
  float v42; // xmm10_4
  float v43; // xmm0_4
  float v44; // xmm0_4
  float mBurnoutSpinRearTireFrictionAtHighSpeed; // xmm2_4
  float mBurnoutSpinRearTireFrictionAtLowSpeed; // xmm5_4
  float v47; // xmm9_4
  float v48; // xmm8_4
  float v49; // xmm1_4
  float v50; // xmm1_4
  float mBurnoutSpinTorqueAtHighSpeed; // xmm2_4
  float mBurnoutSpinTorqueAtLowSpeed; // xmm5_4
  float v53; // xmm9_4
  float v54; // xmm8_4
  float v55; // xmm3_4
  float v56; // xmm11_4
  UFG::VehicleParams *mParams; // rax
  int firstFrontWheel; // ecx
  UFG::VehicleParams *v59; // rax
  int firstRearWheel; // ecx
  float v61; // xmm9_4
  float v62; // xmm9_4
  UFG::VehicleParams *v63; // rax
  __int64 lastRearWheel; // rdx
  __int64 v65; // rcx
  UFG::RigidBodyComponent *mRigidBody; // rax
  float mBurnoutSideThrustFactor_HighSpeed; // xmm0_4
  float mBurnoutSideThrustFactor_LowSpeed; // xmm3_4
  float v69; // xmm4_4
  float v70; // xmm5_4
  __m128 mBurnoutSideThrustFactor_HighSpeed_low; // xmm12
  __m128 mBurnoutSideThrustFactor_LowSpeed_low; // xmm8
  float v73; // xmm1_4
  __m128 v74; // xmm2
  float mBurnoutTorqueFactor_HighSpeed; // xmm0_4
  float mBurnoutTorqueFactor_LowSpeed; // xmm1_4
  float v77; // xmm13_4
  float v78; // xmm12_4
  float v79; // xmm3_4
  float v80; // xmm8_4
  float mBurnoutFwdThrustFactor_HighSpeed; // xmm0_4
  float mBurnoutFwdThrustFactor_LowSpeed; // xmm1_4
  __m128 mBurnoutFwdThrustFactor_HighSpeed_low; // xmm12
  __m128 mBurnoutFwdThrustFactor_LowSpeed_low; // xmm3
  float v85; // xmm4_4
  UFG::RigidBodyComponent *v86; // rax
  hkpRigidBody *v87; // rbx
  __int64 v88; // rdx
  UFG::BasePhysicsObjectVtbl *vfptr; // rax
  __m128 z_low; // xmm0
  __m128 v91; // xmm3
  __int64 v92; // rdx
  __m128 v93; // xmm0
  UFG::BasePhysicsObjectVtbl *v94; // rax
  __m128 v95; // xmm3
  hkpVehicleDriverInputStatus *m_deviceStatus; // rbx
  __int64 v97; // rdx
  __m128 x_low; // xmm2
  float v99; // xmm8_4
  int v100; // eax
  int v101; // xmm0_4
  __m128 v102; // xmm3
  __m128 v103; // xmm6
  __m128 w_low; // xmm2
  UFG::BasePhysicsObjectVtbl *v105; // rax
  __m128 y_low; // xmm4
  float v107; // xmm5_4
  unsigned int v108; // edx
  unsigned int v109; // r10d
  UFG::VehicleInstance *mHavokVehicle; // r8
  __int64 v111; // rcx
  __int64 v112; // r9
  float v113; // xmm0_4
  UFG::qVector4 v114; // xmm3
  UFG::qVector4 v115; // xmm2
  UFG::qVector4 v116; // xmm1
  UFG::Engine *v117; // rcx
  float mSteering; // xmm1_4
  __m128 v119; // xmm0
  UFG::RigidBodyComponent *v120; // rax
  __m128 v121; // xmm3
  hkpEntity *v122; // rbx
  __int64 v123; // rdx
  UFG::VehicleParams *v124; // rax
  int v125; // ecx
  hkpVehicleWheelCollide *v126; // rdx
  float mJTurnSpinFrontTireFriction; // xmm0_4
  UFG::VehicleParams *v128; // rax
  int v129; // ecx
  hkpVehicleWheelCollide *v130; // rdx
  float mJTurnSpinRearTireFriction; // xmm0_4
  UFG::BasePhysicsObjectVtbl *v132; // rax
  __m128 v133; // xmm2
  UFG::qVector3 result; // [rsp+20h] [rbp-108h] BYREF
  hkVector4f b; // [rsp+30h] [rbp-F8h] BYREF
  hkVector4f v136; // [rsp+40h] [rbp-E8h] BYREF
  hkVector4f v137; // [rsp+50h] [rbp-D8h] BYREF
  hkVector4f v138; // [rsp+60h] [rbp-C8h] BYREF
  __m128 v139; // [rsp+70h] [rbp-B8h] BYREF

  if ( !this->mRigidBody->mBody )
    UFG::qPrintf("PhysicsWheeledVehicle %x is missing its rigid body\n", this);
  UFG::PhysicsVehicle::Update(this, targetTransform, driverInput, deltaTime);
  mWaterFloatingTrackerComponent = this->mWaterFloatingTrackerComponent;
  if ( mWaterFloatingTrackerComponent )
  {
    mInWaterState = mWaterFloatingTrackerComponent->mInWaterState;
    if ( mInWaterState > 0 && mInWaterState != 2 )
    {
      mBody = this->mRigidBody->mBody;
      if ( mBody )
        hkpEntity::activate(mBody);
    }
  }
  mCurrentLod = this->mCurrentLod;
  if ( mCurrentLod > LOD_UNINITIALIZED )
  {
    if ( mCurrentLod <= LOD_MEDIUM )
    {
LABEL_12:
      v12 = 0;
      if ( (*((_BYTE *)&this->UFG::PhysicsVehicle + 604) & 7) != 0 )
      {
        p_mCurrentSuspensionLength = &this->mCurrentSuspensionLength;
        do
        {
          p_mCurrentSuspensionLength->array[0] = (float)((float)((float)(p_mCurrentSuspensionLength[8].array[1]
                                                                       - p_mCurrentSuspensionLength->array[0])
                                                               * 0.30000001)
                                                       * deltaTime)
                                               + p_mCurrentSuspensionLength->array[0];
          v14 = fmodf(
                  (float)((float)((float)(this->mSpeedKPH * 0.27777779) * deltaTime) / this->mWheelRadius)
                + p_mCurrentSuspensionLength[4].array[0],
                  6.2831855);
          ++v12;
          p_mCurrentSuspensionLength = (UFG::qSafeArray<float,4> *)((char *)p_mCurrentSuspensionLength + 4);
          p_mCurrentSuspensionLength[3].array[3] = v14;
        }
        while ( v12 < (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) );
      }
      return;
    }
    if ( mCurrentLod != LOD_HIGH )
    {
      if ( mCurrentLod != LOD_NIS )
        return;
      goto LABEL_12;
    }
    m_engine = this->mHavokVehicle->m_engine;
    *(_DWORD *)(&m_engine[4].m_referenceCount + 1) = 0;
    mSpeedKPH = this->mSpeedKPH;
    v17 = mSpeedKPH < 0.0 && (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2;
    if ( (*((_DWORD *)this + 274) & 0x10) != 0 && !v17 )
    {
      z = this->mBodyTransform.v0.z;
      if ( z > 0.0 )
      {
        v19 = (float)(*(float *)(&m_engine[1].m_referenceCount + 1) * UFG::PhysicsWheeledVehicle::mHillTorqueBoost) * z;
        if ( mSpeedKPH < 75.0 )
          v19 = v19
              + (float)((float)(*(float *)(&m_engine[1].m_referenceCount + 1)
                              * UFG::PhysicsWheeledVehicle::mHillTorqueBoostLowSpeed)
                      * z);
        *(float *)(&m_engine[4].m_referenceCount + 1) = v19;
      }
    }
    v20 = 0;
    if ( (*((_BYTE *)&this->UFG::PhysicsVehicle + 604) & 7) != 0 )
    {
      v21 = 0i64;
      p_mWheelSpinAngle = &this->mWheelSpinAngle;
      do
      {
        ++v20;
        p_mWheelSpinAngle = (UFG::qSafeArray<float,4> *)((char *)p_mWheelSpinAngle + 4);
        m_data = this->mHavokVehicle->m_wheelsInfo.m_data;
        p_mWheelSpinAngle[-5].array[3] = m_data[v21++].m_currentSuspensionLength;
        p_mWheelSpinAngle[-1].array[3] = m_data[v21 - 1].m_spinAngle;
      }
      while ( v20 < (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) );
    }
    v24 = FLOAT_0_5;
    v25 = *(float *)&FLOAT_1_0;
    v26 = 0i64;
    if ( (*((_BYTE *)&this->UFG::PhysicsVehicle + 604) & 7) != 0 )
    {
      v27 = 184i64;
      do
      {
        mWheelCollider = this->mWheelCollider;
        v29 = *((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7;
        if ( v29 == 2 )
        {
          if ( !mWheelCollider )
            goto LABEL_36;
          v30 = *(float *)(&mWheelCollider->m_alreadyUsed.m_bool + v27);
        }
        else
        {
          if ( !mWheelCollider )
          {
LABEL_36:
            v30 = 0.0;
            goto LABEL_37;
          }
          v30 = *(float *)((char *)&mWheelCollider->vfptr + v27);
        }
LABEL_37:
        v31 = v30 + (float)(deltaTime * 0.5);
        if ( v31 > 1.0 )
          v31 = *(float *)&FLOAT_1_0;
        if ( mWheelCollider )
        {
          if ( v29 == 2 )
            *((float *)&mWheelCollider[8].m_memSizeAndFlags + (unsigned int)v26) = v31;
          else
            *((float *)&mWheelCollider[7].m_alreadyUsed.m_bool + (unsigned int)v26) = v31;
        }
        v26 = (hkpVehicleWheelCollide *)(unsigned int)((_DWORD)v26 + 1);
        v27 += 4i64;
      }
      while ( (unsigned int)v26 < (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) );
    }
    v32 = _xmm;
    v33 = FLOAT_N1_0;
    if ( (*((_BYTE *)driverInput + 16) & 0x20) != 0 )
    {
      mEngine = this->mEngine;
      if ( !mEngine || mEngine->mDamage < 1.0 )
      {
        mBurnoutSpinFrontTireFrictionAtHighSpeed = this->mBurnoutSpinFrontTireFrictionAtHighSpeed;
        mBurnoutSpinFrontTireFrictionAtLowSpeed = this->mBurnoutSpinFrontTireFrictionAtLowSpeed;
        v37 = _mm_and_ps((__m128)LODWORD(this->mSpeedKPH), (__m128)(unsigned int)_xmm);
        v38 = this->mBurnoutMaxSpeed * this->mBurnoutMaxSpeed;
        v39 = this->mBurnoutMinSpeed * this->mBurnoutMinSpeed;
        if ( mBurnoutSpinFrontTireFrictionAtLowSpeed >= mBurnoutSpinFrontTireFrictionAtHighSpeed )
          v40 = this->mBurnoutSpinFrontTireFrictionAtHighSpeed;
        else
          v40 = this->mBurnoutSpinFrontTireFrictionAtLowSpeed;
        if ( mBurnoutSpinFrontTireFrictionAtLowSpeed <= mBurnoutSpinFrontTireFrictionAtHighSpeed )
          v41 = this->mBurnoutSpinFrontTireFrictionAtHighSpeed;
        else
          v41 = this->mBurnoutSpinFrontTireFrictionAtLowSpeed;
        v42 = FLOAT_0_000099999997;
        v43 = v38 - v39;
        if ( (float)(v38 - v39) < 0.000099999997 )
          v43 = FLOAT_0_000099999997;
        v37.m128_f32[0] = v37.m128_f32[0] * v37.m128_f32[0];
        v44 = (float)((float)(v37.m128_f32[0] - v39)
                    * (float)((float)(mBurnoutSpinFrontTireFrictionAtHighSpeed - mBurnoutSpinFrontTireFrictionAtLowSpeed)
                            / v43))
            + mBurnoutSpinFrontTireFrictionAtLowSpeed;
        if ( v44 <= v40 )
          v44 = v40;
        if ( v44 >= v41 )
          v44 = v41;
        mBurnoutSpinRearTireFrictionAtHighSpeed = this->mBurnoutSpinRearTireFrictionAtHighSpeed;
        mBurnoutSpinRearTireFrictionAtLowSpeed = this->mBurnoutSpinRearTireFrictionAtLowSpeed;
        if ( mBurnoutSpinRearTireFrictionAtLowSpeed >= mBurnoutSpinRearTireFrictionAtHighSpeed )
          v47 = this->mBurnoutSpinRearTireFrictionAtHighSpeed;
        else
          v47 = this->mBurnoutSpinRearTireFrictionAtLowSpeed;
        if ( mBurnoutSpinRearTireFrictionAtLowSpeed <= mBurnoutSpinRearTireFrictionAtHighSpeed )
          v48 = this->mBurnoutSpinRearTireFrictionAtHighSpeed;
        else
          v48 = this->mBurnoutSpinRearTireFrictionAtLowSpeed;
        v49 = v38 - v39;
        if ( (float)(v38 - v39) < 0.000099999997 )
          v49 = FLOAT_0_000099999997;
        v50 = (float)((float)(v37.m128_f32[0] - v39)
                    * (float)((float)(mBurnoutSpinRearTireFrictionAtHighSpeed - mBurnoutSpinRearTireFrictionAtLowSpeed)
                            / v49))
            + mBurnoutSpinRearTireFrictionAtLowSpeed;
        if ( v50 <= v47 )
          v50 = v47;
        if ( v50 >= v48 )
          v50 = v48;
        mBurnoutSpinTorqueAtHighSpeed = this->mBurnoutSpinTorqueAtHighSpeed;
        mBurnoutSpinTorqueAtLowSpeed = this->mBurnoutSpinTorqueAtLowSpeed;
        if ( mBurnoutSpinTorqueAtLowSpeed >= mBurnoutSpinTorqueAtHighSpeed )
          v53 = this->mBurnoutSpinTorqueAtHighSpeed;
        else
          v53 = this->mBurnoutSpinTorqueAtLowSpeed;
        if ( mBurnoutSpinTorqueAtLowSpeed <= mBurnoutSpinTorqueAtHighSpeed )
          v54 = this->mBurnoutSpinTorqueAtHighSpeed;
        else
          v54 = this->mBurnoutSpinTorqueAtLowSpeed;
        v55 = v38 - v39;
        if ( v55 < 0.000099999997 )
          v55 = FLOAT_0_000099999997;
        v56 = (float)((float)(v37.m128_f32[0] - v39)
                    * (float)((float)(mBurnoutSpinTorqueAtHighSpeed - mBurnoutSpinTorqueAtLowSpeed) / v55))
            + mBurnoutSpinTorqueAtLowSpeed;
        if ( v56 <= v53 )
          v56 = v53;
        if ( v56 >= v54 )
          v56 = v54;
        mParams = this->mParams;
        firstFrontWheel = mParams->firstFrontWheel;
        if ( firstFrontWheel <= mParams->lastFrontWheel )
        {
          do
          {
            v26 = this->mWheelCollider;
            if ( v26 )
            {
              if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
                *((float *)&v26[8].m_memSizeAndFlags + (unsigned int)firstFrontWheel) = v44;
              else
                *((float *)&v26[7].m_alreadyUsed.m_bool + (unsigned int)firstFrontWheel) = v44;
            }
            ++firstFrontWheel;
          }
          while ( firstFrontWheel <= this->mParams->lastFrontWheel );
        }
        v59 = this->mParams;
        firstRearWheel = v59->firstRearWheel;
        if ( firstRearWheel <= v59->lastRearWheel )
        {
          do
          {
            v26 = this->mWheelCollider;
            if ( v26 )
            {
              if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
                *((float *)&v26[8].m_memSizeAndFlags + (unsigned int)firstRearWheel) = v50;
              else
                *((float *)&v26[7].m_alreadyUsed.m_bool + (unsigned int)firstRearWheel) = v50;
            }
            ++firstRearWheel;
          }
          while ( firstRearWheel <= this->mParams->lastRearWheel );
        }
        if ( driverInput->mSteering <= 0.0 )
        {
          if ( driverInput->mSteering >= 0.0 )
            v61 = 0.0;
          else
            v61 = FLOAT_N1_0;
        }
        else
        {
          v61 = *(float *)&FLOAT_1_0;
        }
        LODWORD(v62) = COERCE_UNSIGNED_INT(v61 * v56) ^ _xmm[0];
        if ( (*((_BYTE *)this + 1096) & 0x20) != 0 )
        {
          v63 = this->mParams;
          lastRearWheel = v63->lastRearWheel;
          v65 = v63->firstRearWheel;
          mRigidBody = this->mRigidBody;
          b.m_quad = _mm_mul_ps(
                       _mm_add_ps(
                         this->mHardPointChassisSpace[lastRearWheel].m_quad,
                         this->mHardPointChassisSpace[v65].m_quad),
                       *(__m128 *)_xmm);
          hkVector4f::setTransformedPos(&v137, &mRigidBody->mBody->m_motion.m_motionState.m_transform, &b);
          mBurnoutSideThrustFactor_HighSpeed = this->mBurnoutSideThrustFactor_HighSpeed;
          mBurnoutSideThrustFactor_LowSpeed = this->mBurnoutSideThrustFactor_LowSpeed;
          v69 = this->mBurnoutMaxSpeed * this->mBurnoutMaxSpeed;
          v70 = this->mBurnoutMinSpeed * this->mBurnoutMinSpeed;
          if ( mBurnoutSideThrustFactor_LowSpeed >= mBurnoutSideThrustFactor_HighSpeed )
            mBurnoutSideThrustFactor_HighSpeed_low = (__m128)LODWORD(this->mBurnoutSideThrustFactor_HighSpeed);
          else
            mBurnoutSideThrustFactor_HighSpeed_low = (__m128)LODWORD(this->mBurnoutSideThrustFactor_LowSpeed);
          if ( mBurnoutSideThrustFactor_LowSpeed <= mBurnoutSideThrustFactor_HighSpeed )
            mBurnoutSideThrustFactor_LowSpeed_low = (__m128)LODWORD(this->mBurnoutSideThrustFactor_HighSpeed);
          else
            mBurnoutSideThrustFactor_LowSpeed_low = (__m128)LODWORD(this->mBurnoutSideThrustFactor_LowSpeed);
          v73 = v69 - v70;
          if ( (float)(v69 - v70) < 0.000099999997 )
            v73 = FLOAT_0_000099999997;
          v74 = v37;
          v74.m128_f32[0] = (float)((float)(v37.m128_f32[0] - v70)
                                  * (float)((float)(mBurnoutSideThrustFactor_HighSpeed
                                                  - mBurnoutSideThrustFactor_LowSpeed)
                                          / v73))
                          + mBurnoutSideThrustFactor_LowSpeed;
          if ( v74.m128_f32[0] <= mBurnoutSideThrustFactor_HighSpeed_low.m128_f32[0] )
            v74 = mBurnoutSideThrustFactor_HighSpeed_low;
          if ( v74.m128_f32[0] >= mBurnoutSideThrustFactor_LowSpeed_low.m128_f32[0] )
            v74 = mBurnoutSideThrustFactor_LowSpeed_low;
          mBurnoutTorqueFactor_HighSpeed = this->mBurnoutTorqueFactor_HighSpeed;
          mBurnoutTorqueFactor_LowSpeed = this->mBurnoutTorqueFactor_LowSpeed;
          if ( mBurnoutTorqueFactor_LowSpeed >= mBurnoutTorqueFactor_HighSpeed )
            v77 = this->mBurnoutTorqueFactor_HighSpeed;
          else
            v77 = this->mBurnoutTorqueFactor_LowSpeed;
          if ( mBurnoutTorqueFactor_LowSpeed <= mBurnoutTorqueFactor_HighSpeed )
            v78 = this->mBurnoutTorqueFactor_HighSpeed;
          else
            v78 = this->mBurnoutTorqueFactor_LowSpeed;
          v79 = v69 - v70;
          if ( (float)(v69 - v70) < 0.000099999997 )
            v79 = FLOAT_0_000099999997;
          v80 = (float)((float)(v37.m128_f32[0] - v70)
                      * (float)((float)(mBurnoutTorqueFactor_HighSpeed - mBurnoutTorqueFactor_LowSpeed) / v79))
              + mBurnoutTorqueFactor_LowSpeed;
          if ( v80 <= v77 )
            v80 = v77;
          if ( v80 >= v78 )
            v80 = v78;
          mBurnoutFwdThrustFactor_HighSpeed = this->mBurnoutFwdThrustFactor_HighSpeed;
          mBurnoutFwdThrustFactor_LowSpeed = this->mBurnoutFwdThrustFactor_LowSpeed;
          if ( mBurnoutFwdThrustFactor_LowSpeed >= mBurnoutFwdThrustFactor_HighSpeed )
            mBurnoutFwdThrustFactor_HighSpeed_low = (__m128)LODWORD(this->mBurnoutFwdThrustFactor_HighSpeed);
          else
            mBurnoutFwdThrustFactor_HighSpeed_low = (__m128)LODWORD(this->mBurnoutFwdThrustFactor_LowSpeed);
          if ( mBurnoutFwdThrustFactor_LowSpeed <= mBurnoutFwdThrustFactor_HighSpeed )
            mBurnoutFwdThrustFactor_LowSpeed_low = (__m128)LODWORD(this->mBurnoutFwdThrustFactor_HighSpeed);
          else
            mBurnoutFwdThrustFactor_LowSpeed_low = (__m128)LODWORD(this->mBurnoutFwdThrustFactor_LowSpeed);
          v85 = v69 - v70;
          if ( v85 >= 0.000099999997 )
            v42 = v85;
          v37.m128_f32[0] = (float)((float)(v37.m128_f32[0] - v70)
                                  * (float)((float)(mBurnoutFwdThrustFactor_HighSpeed - mBurnoutFwdThrustFactor_LowSpeed)
                                          / v42))
                          + mBurnoutFwdThrustFactor_LowSpeed;
          if ( v37.m128_f32[0] <= mBurnoutFwdThrustFactor_HighSpeed_low.m128_f32[0] )
            v37 = mBurnoutFwdThrustFactor_HighSpeed_low;
          if ( v37.m128_f32[0] >= mBurnoutFwdThrustFactor_LowSpeed_low.m128_f32[0] )
            v37 = mBurnoutFwdThrustFactor_LowSpeed_low;
          v32 = _xmm;
          v86 = this->mRigidBody;
          v74.m128_f32[0] = v74.m128_f32[0] * v62;
          v37.m128_f32[0] = (float)(v37.m128_f32[0] * v56) * driverInput->mSteering;
          v136.m_quad = _mm_add_ps(
                          _mm_unpacklo_ps(
                            _mm_unpacklo_ps(_mm_and_ps(v37, (__m128)(unsigned int)_xmm), (__m128)0i64),
                            (__m128)0i64),
                          _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps(_mm_xor_ps(v74, *(__m128 *)_xmm), (__m128)0i64)));
          hkVector4f::setTransformedPos(&v138, &v86->mBody->m_motion.m_motionState.m_transform, &v136);
          v87 = this->mRigidBody->mBody;
          hkpEntity::activate(v87);
          ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *, hkVector4f *))v87->m_motion.hkpEntity::vfptr[12].__first_virtual_table_function__)(
            &v87->m_motion,
            v88,
            &v138,
            &v137);
          vfptr = this->vfptr;
          z_low = (__m128)LODWORD(this->mBodyTransform.v2.z);
          v91 = _mm_unpacklo_ps((__m128)LODWORD(this->mBodyTransform.v2.x), z_low);
          z_low.m128_f32[0] = v80 * v62;
          v139 = _mm_mul_ps(
                   _mm_unpacklo_ps(v91, _mm_unpacklo_ps((__m128)LODWORD(this->mBodyTransform.v2.y), (__m128)0i64)),
                   _mm_shuffle_ps(z_low, z_low, 0));
          ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, __int64, __m128 *, const char *))vfptr[6].ResourceUnloaded)(
            this,
            v92,
            &v139,
            "Burnout");
          v33 = FLOAT_N1_0;
        }
        else
        {
          v93 = (__m128)LODWORD(this->mBodyTransform.v2.z);
          v94 = this->vfptr;
          v95 = _mm_unpacklo_ps((__m128)LODWORD(this->mBodyTransform.v2.x), v93);
          v93.m128_f32[0] = v62;
          v139 = _mm_mul_ps(
                   _mm_unpacklo_ps(v95, _mm_unpacklo_ps((__m128)LODWORD(this->mBodyTransform.v2.y), (__m128)0i64)),
                   _mm_shuffle_ps(v93, v93, 0));
          ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, hkpVehicleWheelCollide *, __m128 *, const char *))v94[6].ResourceUnloaded)(
            this,
            v26,
            &v139,
            "Burnout");
        }
        v24 = FLOAT_0_5;
      }
    }
    m_deviceStatus = this->mHavokVehicle->m_deviceStatus;
    *(float *)&m_deviceStatus[1].vfptr = driverInput->mSteering;
    HIDWORD(m_deviceStatus[1].vfptr) = LODWORD(driverInput->mGasBrakes);
    LOBYTE(m_deviceStatus[1].m_memSizeAndFlags) = (*((_DWORD *)driverInput + 4) & 4) != 0;
    HIBYTE(m_deviceStatus[1].m_memSizeAndFlags) = *((_BYTE *)driverInput + 16) & 1;
    *((_DWORD *)this->mTransmission + 26) ^= (*((_DWORD *)this->mTransmission + 26) ^ (*((_DWORD *)driverInput + 4) >> 1)) & 1;
    UFG::RigidBody::GetVelocity(this->mRigidBody, &result);
    x_low = (__m128)LODWORD(result.x);
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(result.y * result.y))
                      + (float)(result.z * result.z);
    v99 = _mm_sqrt_ps(x_low).m128_f32[0] - this->mPreviousSpeed;
    if ( COERCE_FLOAT(LODWORD(this->mSpeedKPH) & v32) < 1.5
      && (*((_BYTE *)this + 1096) & 0x10) != 0
      && (float)(COERCE_FLOAT(LODWORD(v99) & v32) / deltaTime) < 3.0 )
    {
      v100 = *((_DWORD *)driverInput + 4);
      if ( (v100 & 0x20) == 0
        && (v100 & 0x10) == 0
        && ((v100 & 8) == 0 || (v100 & 0x100) != 0)
        && COERCE_FLOAT(LODWORD(driverInput->mGasBrakes) & v32) <= 0.0099999998
        && COERCE_FLOAT(LODWORD(driverInput->mRawGasBrakes) & v32) <= 0.0099999998 )
      {
        LOBYTE(m_deviceStatus[1].m_memSizeAndFlags) = 1;
      }
    }
    if ( (*((_DWORD *)this + 274) & 8) != 0 )
    {
      v101 = LODWORD(driverInput->mSteering) & v32;
      if ( *(float *)&v101 > 0.25 )
      {
        v102 = (__m128)LODWORD(this->mBodyTransform.v1.z);
        v103 = (__m128)LODWORD(this->mBodyTransform.v1.x);
        w_low = (__m128)LODWORD(this->mBodyTransform.v1.w);
        v105 = this->vfptr;
        y_low = (__m128)LODWORD(this->mBodyTransform.v1.y);
        v107 = (float)((float)(v33 / *(float *)&v101) * driverInput->mSteering) * this->mAirSteerYawRate;
        v103.m128_f32[0] = (float)((float)((float)(v103.m128_f32[0] + this->mBodyTransform.v0.x) * 0.0)
                                 + (float)(v107 * this->mBodyTransform.v2.x))
                         + (float)(this->mBodyTransform.v3.x * 0.0);
        y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] + this->mBodyTransform.v0.y) * 0.0)
                                  + (float)(v107 * this->mBodyTransform.v2.y))
                          + (float)(this->mBodyTransform.v3.y * 0.0);
        v102.m128_f32[0] = (float)((float)((float)(v102.m128_f32[0] + this->mBodyTransform.v0.z) * 0.0)
                                 + (float)(v107 * this->mBodyTransform.v2.z))
                         + (float)(this->mBodyTransform.v3.z * 0.0);
        w_low.m128_f32[0] = (float)((float)((float)(w_low.m128_f32[0] + this->mBodyTransform.v0.w) * 0.0)
                                  + (float)(v107 * this->mBodyTransform.v2.w))
                          + (float)(this->mBodyTransform.v3.w * 0.0);
        v139 = _mm_unpacklo_ps(_mm_unpacklo_ps(v103, v102), _mm_unpacklo_ps(y_low, w_low));
        ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, __int64, __m128 *, const char *))v105[6].ResourceUnloaded)(
          this,
          v97,
          &v139,
          "Air Steer");
      }
    }
    v108 = 0;
    v109 = *((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7;
    if ( v109 )
    {
      mHavokVehicle = this->mHavokVehicle;
      v111 = 0i64;
      v112 = v109;
      do
      {
        if ( !mHavokVehicle || mHavokVehicle->m_wheelsInfo.hkpVehicleInstance::m_data[v111].m_contactBody )
          ++v108;
        ++v111;
        --v112;
      }
      while ( v112 );
    }
    *((_DWORD *)this + 274) &= 0xFFFFFFE7;
    *((_DWORD *)this + 274) |= 8 * ((v108 == 0) | (2 * (v108 == v109)));
    if ( (*((_BYTE *)this + 1096) & 0x10) != 0 )
    {
      v113 = deltaTime + this->mLastGoodPositionSampleTimer;
      this->mLastGoodPositionSampleTimer = v113;
      if ( v113 > 2.0 )
      {
        this->mLastGoodPositionSampleTimer = 0.0;
        v114 = this->mBodyTransform.v1;
        v115 = this->mBodyTransform.v2;
        v116 = this->mBodyTransform.v3;
        this->mLastGoodPosition.v0 = this->mBodyTransform.v0;
        this->mLastGoodPosition.v1 = v114;
        this->mLastGoodPosition.v2 = v115;
        this->mLastGoodPosition.v3 = v116;
      }
    }
    else
    {
      this->mLastGoodPositionSampleTimer = 0.0;
    }
    v117 = this->mEngine;
    if ( this->mSpeedKPH >= 0.0 )
    {
      v117->mGovernorSpeedKPH = this->mHighSpeedGovernor;
    }
    else
    {
      v117->mGovernorSpeedKPH = this->mReverseSpeedGovernor;
      if ( v108 >= (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) - 1 && this->mSpeedKPH < -10.0 )
      {
        mSteering = driverInput->mSteering;
        if ( COERCE_FLOAT(LODWORD(driverInput->mSteering) & v32) > v24 )
        {
          if ( mSteering <= 0.0 )
          {
            if ( mSteering >= 0.0 )
              v25 = 0.0;
            else
              v25 = v33;
          }
          v119 = (__m128)LODWORD(this->mBodyTransform.v2.z);
          v120 = this->mRigidBody;
          v121 = _mm_unpacklo_ps((__m128)LODWORD(this->mBodyTransform.v2.x), v119);
          v119.m128_f32[0] = v25 * this->mJTurnSpinTorque;
          v139 = _mm_mul_ps(
                   _mm_unpacklo_ps(v121, _mm_unpacklo_ps((__m128)LODWORD(this->mBodyTransform.v2.y), (__m128)0i64)),
                   _mm_shuffle_ps(v119, v119, 0));
          v122 = v120->mBody;
          hkpEntity::activate(v122);
          ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *))v122->m_motion.vfptr[13].__first_virtual_table_function__)(
            &v122->m_motion,
            v123,
            &v139);
          v124 = this->mParams;
          v125 = v124->firstFrontWheel;
          if ( v125 <= v124->lastFrontWheel )
          {
            do
            {
              v126 = this->mWheelCollider;
              mJTurnSpinFrontTireFriction = this->mJTurnSpinFrontTireFriction;
              if ( v126 )
              {
                if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
                  *((float *)&v126[8].m_memSizeAndFlags + (unsigned int)v125) = mJTurnSpinFrontTireFriction;
                else
                  *((float *)&v126[7].m_alreadyUsed.m_bool + (unsigned int)v125) = mJTurnSpinFrontTireFriction;
              }
              ++v125;
            }
            while ( v125 <= this->mParams->lastFrontWheel );
          }
          v128 = this->mParams;
          v129 = v128->firstRearWheel;
          if ( v129 <= v128->lastRearWheel )
          {
            do
            {
              v130 = this->mWheelCollider;
              mJTurnSpinRearTireFriction = this->mJTurnSpinRearTireFriction;
              if ( v130 )
              {
                if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
                  *((float *)&v130[8].m_memSizeAndFlags + (unsigned int)v129) = mJTurnSpinRearTireFriction;
                else
                  *((float *)&v130[7].m_alreadyUsed.m_bool + (unsigned int)v129) = mJTurnSpinRearTireFriction;
              }
              ++v129;
            }
            while ( v129 <= this->mParams->lastRearWheel );
          }
        }
      }
    }
    UFG::PhysicsWheeledVehicle::UpdateSkids(this, driverInput, v99);
    v132 = this->vfptr;
    v133 = (__m128)LODWORD(result.x);
    v133.m128_f32[0] = (float)((float)(v133.m128_f32[0] * v133.m128_f32[0]) + (float)(result.y * result.y))
                     + (float)(result.z * result.z);
    LODWORD(this->mPreviousSpeed) = _mm_sqrt_ps(v133).m128_u32[0];
    ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, UFG::VehicleInput *))v132[10].DebugDraw)(this, driverInput);
  }
}

// File Line: 2599
// RVA: 0x466BF0
__int64 __fastcall UFG::PhysicsWheeledVehicle::GetNumWheelsOnGround(UFG::PhysicsWheeledVehicle *this)
{
  __int64 result; // rax
  __int64 v2; // r8
  UFG::VehicleInstance *mHavokVehicle; // r9
  __int64 v4; // rdx

  result = 0i64;
  v2 = *((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7;
  if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) != 0 )
  {
    mHavokVehicle = this->mHavokVehicle;
    v4 = 0i64;
    do
    {
      if ( !mHavokVehicle || mHavokVehicle->m_wheelsInfo.hkpVehicleInstance::m_data[v4].m_contactBody )
        result = (unsigned int)(result + 1);
      ++v4;
      --v2;
    }
    while ( v2 );
  }
  return result;
}

// File Line: 2615
// RVA: 0x4737B0
void __fastcall UFG::PhysicsWheeledVehicle::Reset(UFG::PhysicsWheeledVehicle *this, UFG::VehicleResetOptions options)
{
  __int64 v3; // rdx
  unsigned int v4; // eax
  hkpVehicleWheelCollide *mWheelCollider; // rcx

  UFG::PhysicsVehicle::Reset(this, options);
  v3 = 0i64;
  v4 = *((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7;
  if ( v4 )
  {
    do
    {
      mWheelCollider = this->mWheelCollider;
      if ( mWheelCollider )
      {
        if ( v4 == 2 )
          *((_DWORD *)&mWheelCollider[8].m_memSizeAndFlags + v3) = 1065353216;
        else
          *((_DWORD *)&mWheelCollider[7].m_alreadyUsed.m_bool + v3) = 1065353216;
      }
      v3 = (unsigned int)(v3 + 1);
      v4 = *((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7;
    }
    while ( (unsigned int)v3 < v4 );
  }
}

// File Line: 2627
// RVA: 0x476410
void __fastcall UFG::PhysicsWheeledVehicle::Suspend(UFG::PhysicsWheeledVehicle *this)
{
  UFG::BasePhysicsSystem *v1; // rdi
  UFG::VehicleAction *mVehicleAction; // rdx
  UFG::VehicleInstance *mHavokVehicle; // rdx
  UFG::BasePhysicsSystem *v5; // rdi
  hkpRigidBody *mBody; // rdx
  hkpRigidBody *mBulletCollider; // rdx
  UFG::WaterFloatingTrackerComponent *mWaterFloatingTrackerComponent; // rcx

  v1 = UFG::BasePhysicsSystem::mInstance;
  if ( this->mHavokVehicle )
    UFG::PhysicsWheeledVehicle::RemoveWheelPhantoms(this);
  mVehicleAction = this->mVehicleAction;
  if ( mVehicleAction )
    UFG::BasePhysicsSystem::RemoveAction(v1, mVehicleAction);
  mHavokVehicle = this->mHavokVehicle;
  if ( mHavokVehicle )
    UFG::BasePhysicsSystem::RemoveAction(v1, mHavokVehicle);
  v5 = UFG::BasePhysicsSystem::mInstance;
  mBody = this->mRigidBody->mBody;
  if ( mBody && mBody->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, mBody, 0);
  mBulletCollider = this->mBulletCollider;
  if ( mBulletCollider && mBulletCollider->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(v5, mBulletCollider, 0);
  mWaterFloatingTrackerComponent = this->mWaterFloatingTrackerComponent;
  if ( mWaterFloatingTrackerComponent )
    ((void (__fastcall *)(UFG::WaterFloatingTrackerComponent *))mWaterFloatingTrackerComponent->UFG::WaterFloatingTrackerBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[8].__vecDelDtor)(mWaterFloatingTrackerComponent);
}

// File Line: 2654
// RVA: 0x473F20
void __fastcall UFG::PhysicsWheeledVehicle::Restore(UFG::PhysicsWheeledVehicle *this)
{
  UFG::BasePhysicsSystem *v2; // rdi
  UFG::VehicleAction *mVehicleAction; // rdx
  UFG::VehicleInstance *mHavokVehicle; // rdx

  UFG::PhysicsVehicle::Restore(this);
  if ( this->mCollisionMeshBundle.mData )
  {
    v2 = UFG::BasePhysicsSystem::mInstance;
    if ( this->mCurrentLod == LOD_HIGH )
    {
      mVehicleAction = this->mVehicleAction;
      if ( mVehicleAction && !mVehicleAction->m_world )
        UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, mVehicleAction);
      mHavokVehicle = this->mHavokVehicle;
      if ( mHavokVehicle )
      {
        if ( !mHavokVehicle->m_world )
        {
          UFG::BasePhysicsSystem::AddAction(v2, mHavokVehicle);
          UFG::PhysicsWheeledVehicle::AddWheelPhantoms(this);
        }
      }
    }
  }
}

// File Line: 2683
// RVA: 0x473D30
void __fastcall UFG::PhysicsWheeledVehicle::ResourceUnloaded(
        UFG::PhysicsWheeledVehicle *this,
        UFG::PhysicsResourceHandle *resource)
{
  this->mDesiredLod = LOD_RESOURCES_UNLOADED;
  UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents(this);
  UFG::PhysicsVehicle::ResourceUnloaded(this, resource);
}

// File Line: 2694
// RVA: 0x461630
void __fastcall UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents(UFG::PhysicsWheeledVehicle *this)
{
  UFG::VehicleAction *mVehicleAction; // rdx
  UFG::BasePhysicsSystem *v2; // rdi

  mVehicleAction = this->mVehicleAction;
  v2 = UFG::BasePhysicsSystem::mInstance;
  if ( mVehicleAction )
  {
    UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, mVehicleAction);
    hkReferencedObject::removeReference(this->mVehicleAction);
    this->mVehicleAction = 0i64;
  }
  if ( this->mHavokVehicle )
  {
    UFG::PhysicsWheeledVehicle::RemoveWheelPhantoms(this);
    UFG::BasePhysicsSystem::RemoveAction(v2, this->mHavokVehicle);
    hkReferencedObject::removeReference(this->mHavokVehicle);
    this->mHavokVehicle = 0i64;
    this->mWheelCollider = 0i64;
  }
  this->mEngine = 0i64;
  this->mTransmission = 0i64;
  this->mBrakes = 0i64;
  this->mSteering = 0i64;
  this->mAerodynamics = 0i64;
}

// File Line: 2738
// RVA: 0x474D90
void __fastcall UFG::PhysicsWheeledVehicle::SetLevelOfDetailInternal(UFG::PhysicsWheeledVehicle *this, int lod)
{
  UFG::BasePhysicsSystem *v3; // rbp
  hkpWorld *mWorld; // r14
  unsigned int v5; // edi
  __int64 v6; // rsi
  __int64 v7; // rsi
  char v8; // dl
  char v9; // cl
  _QWORD **Value; // rax
  UFG::VehicleLinearCastWheelCollide *v11; // rax
  hkJobType v12; // edx
  hkpVehicleWheelCollide *v13; // rax
  char v14; // dl
  char v15; // cl
  _QWORD **v16; // rax
  UFG::VehicleRaycastWheelCollide *v17; // rax
  UFG::VehicleParams *mParams; // rdx
  char v19; // dl
  char v20; // cl
  _QWORD **v21; // rax
  UFG::VehicleInstance *v22; // rax
  UFG::VehicleInstance *v23; // rax
  char v24; // al
  UFG::VehicleInstance *mHavokVehicle; // rcx
  char v26; // dl
  char v27; // cl
  _QWORD **v28; // rax
  UFG::VehicleAction *v29; // rax
  UFG::VehicleAction *v30; // rax
  char v31; // al
  __int64 v32; // rdx
  UFG::qSafeArray<float,4> *p_mWheelSpinAngle; // r8
  UFG::VehicleSetup v34; // [rsp+40h] [rbp-98h] BYREF

  if ( lod > 0 )
  {
    v3 = UFG::BasePhysicsSystem::mInstance;
    if ( lod <= 2 )
      goto LABEL_37;
    if ( lod != 3 )
    {
      if ( lod != 4 )
        return;
LABEL_37:
      UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents(this);
      return;
    }
    mWorld = UFG::BasePhysicsSystem::mInstance->mWorld;
    v5 = 0;
    v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
    if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
    {
      v7 = v6 + 16;
      v8 = ++*(_BYTE *)(v7 + 80);
      *(_DWORD *)(v7 + 4i64 * v8) = 3;
      *(_QWORD *)(v7 + 8i64 * v8 + 16) = "VehicleLinearCastWheelCollide";
      *(_QWORD *)(v7 + 8i64 * v8 + 48) = 0i64;
      v9 = *(_BYTE *)(v7 + 81);
      if ( v8 > v9 )
        v9 = v8;
      *(_BYTE *)(v7 + 81) = v9;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v11 = (UFG::VehicleLinearCastWheelCollide *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                    Value[11],
                                                    216i64);
      if ( v11 )
        UFG::VehicleLinearCastWheelCollide::VehicleLinearCastWheelCollide(v11);
      else
        v13 = 0i64;
    }
    else
    {
      v7 = v6 + 16;
      v14 = ++*(_BYTE *)(v7 + 80);
      *(_DWORD *)(v7 + 4i64 * v14) = 3;
      *(_QWORD *)(v7 + 8i64 * v14 + 16) = "VehicleRaycastWheelCollide";
      *(_QWORD *)(v7 + 8i64 * v14 + 48) = 0i64;
      v15 = *(_BYTE *)(v7 + 81);
      if ( v14 > v15 )
        v15 = v14;
      *(_BYTE *)(v7 + 81) = v15;
      v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v17 = (UFG::VehicleRaycastWheelCollide *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(
                                                 v16[11],
                                                 200i64);
      if ( v17 )
        UFG::VehicleRaycastWheelCollide::VehicleRaycastWheelCollide(v17);
      else
        v13 = 0i64;
    }
    this->mWheelCollider = v13;
    HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v12);
    mParams = this->mParams;
    *(_DWORD *)&v34.m_memSizeAndFlags = 0x1FFFF;
    v34.vfptr = (hkBaseObjectVtbl *)&UFG::VehicleSetup::`vftable;
    UFG::VehicleParams::VehicleParams(&v34.mParams, mParams);
    v19 = ++*(_BYTE *)(v7 + 80);
    *(_DWORD *)(v7 + 4i64 * v19) = 3;
    *(_QWORD *)(v7 + 8i64 * v19 + 16) = "hkpVehicleInstance";
    *(_QWORD *)(v7 + 8i64 * v19 + 48) = 0i64;
    v20 = *(_BYTE *)(v7 + 81);
    if ( v19 > v20 )
      v20 = v19;
    *(_BYTE *)(v7 + 81) = v20;
    v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (UFG::VehicleInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v21[11] + 8i64))(v21[11], 256i64);
    if ( v22 )
      UFG::VehicleInstance::VehicleInstance(v22, this->mRigidBody->mBody);
    else
      v23 = 0i64;
    this->mHavokVehicle = v23;
    v24 = *(_BYTE *)(v7 + 80);
    if ( v24 > 0 )
    {
      *(_BYTE *)(v7 + 80) = v24 - 1;
    }
    else
    {
      *(_BYTE *)(v7 + 80) = 0;
      *(_DWORD *)v7 = 3;
      *(_QWORD *)(v7 + 16) = 0i64;
      *(_QWORD *)(v7 + 48) = 0i64;
    }
    UFG::VehicleSetup::buildVehicle(&v34, this, mWorld, this->mHavokVehicle, this->mWheelCollider);
    mHavokVehicle = this->mHavokVehicle;
    this->mEngine = (UFG::Engine *)mHavokVehicle->m_engine;
    this->mTransmission = (UFG::Transmission *)mHavokVehicle->m_transmission;
    this->mBrakes = (UFG::Brakes *)mHavokVehicle->m_brake;
    this->mSteering = (UFG::Steering *)mHavokVehicle->m_steering;
    this->mAerodynamics = (UFG::VehicleAerodynamics *)mHavokVehicle->m_aerodynamics;
    v26 = ++*(_BYTE *)(v7 + 80);
    *(_DWORD *)(v7 + 4i64 * v26) = 3;
    *(_QWORD *)(v7 + 8i64 * v26 + 16) = "VehicleAction";
    *(_QWORD *)(v7 + 8i64 * v26 + 48) = 0i64;
    v27 = *(_BYTE *)(v7 + 81);
    if ( v26 > v27 )
      v27 = v26;
    *(_BYTE *)(v7 + 81) = v27;
    v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v29 = (UFG::VehicleAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v28[11] + 8i64))(v28[11], 72i64);
    if ( v29 )
      UFG::VehicleAction::VehicleAction(v29, this);
    else
      v30 = 0i64;
    this->mVehicleAction = v30;
    v31 = *(_BYTE *)(v7 + 80);
    if ( v31 > 0 )
    {
      *(_BYTE *)(v7 + 80) = v31 - 1;
    }
    else
    {
      *(_BYTE *)(v7 + 80) = 0;
      *(_DWORD *)v7 = 3;
      *(_QWORD *)(v7 + 16) = 0i64;
      *(_QWORD *)(v7 + 48) = 0i64;
    }
    UFG::BasePhysicsSystem::AddAction(v3, this->mHavokVehicle);
    UFG::BasePhysicsSystem::AddAction(v3, this->mVehicleAction);
    UFG::PhysicsWheeledVehicle::AddWheelPhantoms(this);
    if ( (*((_BYTE *)&this->UFG::PhysicsVehicle + 604) & 7) != 0 )
    {
      v32 = 0i64;
      p_mWheelSpinAngle = &this->mWheelSpinAngle;
      do
      {
        this->mHavokVehicle->m_wheelsInfo.m_data[v32].m_spinAngle = p_mWheelSpinAngle->array[0];
        ++v5;
        p_mWheelSpinAngle = (UFG::qSafeArray<float,4> *)((char *)p_mWheelSpinAngle + 4);
        ++v32;
      }
      while ( v5 < (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) );
    }
    UFG::VehicleParams::~VehicleParams(&v34.mParams);
    v34.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  }
}

// File Line: 2809
// RVA: 0x47FC50
void __fastcall UFG::PhysicsWheeledVehicle::UpdateSkids(
        UFG::PhysicsWheeledVehicle *this,
        UFG::VehicleInput *input,
        float speed_delta)
{
  unsigned int v3; // r10d
  unsigned int v5; // ebx
  float v6; // xmm4_4
  float v7; // xmm5_4
  __int64 v8; // r11
  UFG::qSafeArray<float,4> *p_mForwardSkidStrength; // r8
  float v10; // xmm7_4
  UFG::VehicleInstance *mHavokVehicle; // rax
  hkpVehicleInstance::WheelInfo *v12; // rcx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  hkpVehicleInstance::WheelInfo *m_data; // rcx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  UFG::qSafeArray<float,4> *v20; // rcx
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  UFG::VehicleParams *mParams; // rax
  __int64 firstRearWheel; // rdx
  _DWORD *v28; // rcx

  v3 = 0;
  v5 = 0;
  if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) != 0 )
  {
    v6 = speed_skid_factor;
    v7 = speed_down_skid_threshold;
    v8 = 0i64;
    p_mForwardSkidStrength = &this->mForwardSkidStrength;
    v10 = speed_up_skid_threshold;
    do
    {
      mHavokVehicle = this->mHavokVehicle;
      if ( v5 <= mHavokVehicle->m_wheelsInfo.m_size
        && (v12 = mHavokVehicle->m_wheelsInfo.hkpVehicleInstance::m_data, v12[v8].m_contactBody) )
      {
        LODWORD(v13) = LODWORD(v12[v8].m_forwardSlipVelocity) & _xmm;
        p_mForwardSkidStrength->array[0] = v13;
        if ( speed_delta <= v10 )
          v14 = 0.0;
        else
          v14 = v6 * speed_delta;
        if ( v13 <= v14 )
          v13 = v14;
        p_mForwardSkidStrength->array[0] = v13;
        if ( speed_delta >= v7 || input->mGasBrakes <= 0.0 )
          v15 = 0.0;
        else
          v15 = (float)(speed_delta * -1.0) * v6;
        if ( v13 <= v15 )
          v13 = v15;
        p_mForwardSkidStrength->array[0] = v13;
        LODWORD(p_mForwardSkidStrength[1].array[0]) = LODWORD(this->mHavokVehicle->m_wheelsInfo.m_data[v8].m_sideSlipVelocity) & _xmm;
        m_data = this->mHavokVehicle->m_wheelsInfo.m_data;
        LODWORD(v17) = LODWORD(m_data[v8].m_sideSlipVelocity) & _xmm;
        if ( v17 <= COERCE_FLOAT(LODWORD(m_data[v8].m_forwardSlipVelocity) & _xmm) )
          LODWORD(v17) = LODWORD(m_data[v8].m_forwardSlipVelocity) & _xmm;
        p_mForwardSkidStrength[-1].array[0] = v17;
        if ( speed_delta <= v10 )
          v18 = 0.0;
        else
          v18 = v6 * speed_delta;
        if ( v17 <= v18 )
          v17 = v18;
        p_mForwardSkidStrength[-1].array[0] = v17;
        if ( speed_delta >= v7 || input->mGasBrakes <= 0.0 )
          v19 = 0.0;
        else
          v19 = (float)(speed_delta * -1.0) * v6;
        if ( v17 <= v19 )
          v17 = v19;
        p_mForwardSkidStrength[-1].array[0] = v17;
      }
      else
      {
        p_mForwardSkidStrength[-1].array[0] = 0.0;
        p_mForwardSkidStrength->array[0] = 0.0;
        p_mForwardSkidStrength[1].array[0] = 0.0;
      }
      ++v5;
      p_mForwardSkidStrength = (UFG::qSafeArray<float,4> *)((char *)p_mForwardSkidStrength + 4);
      ++v8;
    }
    while ( v5 < (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) );
  }
  if ( (*((_BYTE *)&this->UFG::PhysicsVehicle + 604) & 7) != 0 )
  {
    v20 = &this->mForwardSkidStrength;
    do
    {
      v21 = (float)(v20[-1].array[0] - 4.0) * 0.125;
      if ( v21 <= 0.0 )
      {
        v21 = 0.0;
      }
      else if ( v21 >= 1.0 )
      {
        v21 = *(float *)&FLOAT_1_0;
      }
      v22 = v20->array[0];
      v20[-1].array[0] = v21;
      v23 = (float)(v22 - 4.0) * 0.125;
      if ( v23 <= 0.0 )
      {
        v23 = 0.0;
      }
      else if ( v23 >= 1.0 )
      {
        v23 = *(float *)&FLOAT_1_0;
      }
      v24 = v20[1].array[0];
      v20->array[0] = v23;
      v25 = (float)(v24 - 4.0) * 0.125;
      if ( v25 <= 0.0 )
      {
        v25 = 0.0;
      }
      else if ( v25 >= 1.0 )
      {
        v25 = *(float *)&FLOAT_1_0;
      }
      v20[1].array[0] = v25;
      ++v3;
      v20 = (UFG::qSafeArray<float,4> *)((char *)v20 + 4);
    }
    while ( v3 < (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) );
  }
  if ( (*((_BYTE *)input + 16) & 0x20) != 0 )
  {
    mParams = this->mParams;
    firstRearWheel = mParams->firstRearWheel;
    if ( (int)firstRearWheel <= mParams->lastRearWheel )
    {
      v28 = (_DWORD *)&this->mLateralSkidStrength.array[firstRearWheel];
      do
      {
        *(v28 - 4) = 1065353216;
        *v28 = 1065353216;
        *(v28 - 8) = 1065353216;
        LODWORD(firstRearWheel) = firstRearWheel + 1;
        ++v28;
      }
      while ( (int)firstRearWheel <= this->mParams->lastRearWheel );
    }
  }
}

// File Line: 2876
// RVA: 0x4755D0
void __fastcall UFG::PhysicsWheeledVehicle::SetTireDamage(UFG::PhysicsWheeledVehicle *this, int index, float damage)
{
  float v3; // xmm1_4
  UFG::VehicleInstance *mHavokVehicle; // rax
  UFG::VehicleInstance *v5; // rax

  if ( damage <= 0.0 )
  {
    damage = 0.0;
  }
  else if ( damage >= 1.0 )
  {
    damage = *(float *)&FLOAT_1_0;
  }
  if ( this->mTireDamage.array[index] != damage )
  {
    v3 = gFlatTireRadiusReduction;
    this->mTireDamage.array[index] = damage;
    if ( damage >= 1.0 )
    {
      mHavokVehicle = this->mHavokVehicle;
      if ( mHavokVehicle )
        mHavokVehicle->m_data->m_wheelParams.hkpVehicleInstance::m_data[index].m_radius = mHavokVehicle->m_data->m_wheelParams.hkpVehicleInstance::m_data[index].m_radius
                                                                                        - v3;
    }
    if ( damage == 0.0 )
    {
      v5 = this->mHavokVehicle;
      if ( v5 )
        v5->m_data->m_wheelParams.hkpVehicleInstance::m_data[index].m_radius = v3
                                                                             + v5->m_data->m_wheelParams.hkpVehicleInstance::m_data[index].m_radius;
    }
  }
}

// File Line: 2909
// RVA: 0x468460
void __fastcall UFG::PhysicsWheeledVehicle::GetWheelMatrix(
        UFG::PhysicsWheeledVehicle *this,
        unsigned int i,
        UFG::qMatrix44 *mat)
{
  UFG::qMatrix44 *v4; // rax
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  hkQuaternionf qi; // [rsp+30h] [rbp-A8h] BYREF
  hkVector4f v9; // [rsp+40h] [rbp-98h] BYREF
  hkTransformf v10; // [rsp+50h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+90h] [rbp-48h] BYREF

  ((void (__fastcall *)(UFG::VehicleInstance *, hkpRigidBody *, hkpVehicleSuspension *, _QWORD, hkVector4f *, hkQuaternionf *))this->mHavokVehicle->vfptr[5].__first_virtual_table_function__)(
    this->mHavokVehicle,
    this->mRigidBody->mBody,
    this->mHavokVehicle->m_suspension,
    i,
    &v9,
    &qi);
  v10.m_translation = (hkVector4f)v9.m_quad;
  hkRotationf::set(&v10.m_rotation, &qi);
  hkTransformf::get4x4ColumnMajor(&v10, &mat->v0.x);
  v4 = UFG::qMatrix44::operator*(&UFG::gWheelFixup, &result, mat);
  v5 = v4->v1;
  v6 = v4->v2;
  v7 = v4->v3;
  mat->v0 = v4->v0;
  mat->v1 = v5;
  mat->v2 = v6;
  mat->v3 = v7;
}

// File Line: 2926
// RVA: 0x468510
void __fastcall UFG::PhysicsWheeledVehicle::GetWheelTransforms(
        UFG::PhysicsWheeledVehicle *this,
        hkQsTransformf *axleTransform,
        hkQuaternionf *wheelTransform,
        bool clampSuspensionTravel)
{
  __int64 v4; // rbp
  UFG::qSafeArray<float,4> *p_mRestingSuspensionLength; // rdi
  float minSuspensionLength; // xmm1_4
  double v11; // xmm2_8
  float maxSuspensionLength; // xmm0_4
  hkQsTransformf *axlePosOut; // rbx

  v4 = 0i64;
  if ( (*((_BYTE *)&this->UFG::PhysicsVehicle + 604) & 7) != 0 )
  {
    p_mRestingSuspensionLength = &this->mRestingSuspensionLength;
    do
    {
      if ( clampSuspensionTravel )
      {
        minSuspensionLength = p_mRestingSuspensionLength->array[0] - p_mRestingSuspensionLength[1].array[0];
        v11 = (float)(p_mRestingSuspensionLength->array[0] + p_mRestingSuspensionLength[2].array[0]);
      }
      else
      {
        minSuspensionLength = 0.0;
        v11 = DOUBLE_1000000_0;
      }
      maxSuspensionLength = v11;
      axlePosOut = &axleTransform[v4];
      UFG::VehicleInstance::CalcCurrentPositionAndRotation(
        this->mHavokVehicle,
        this->mRigidBody->mBody,
        this->mHavokVehicle->m_suspension,
        v4,
        &axlePosOut->m_translation,
        &axlePosOut->m_rotation,
        &wheelTransform[(unsigned int)v4],
        minSuspensionLength,
        maxSuspensionLength);
      axlePosOut->m_scale = (hkVector4f)query.m_quad;
      v4 = (unsigned int)(v4 + 1);
      p_mRestingSuspensionLength = (UFG::qSafeArray<float,4> *)((char *)p_mRestingSuspensionLength + 4);
    }
    while ( (unsigned int)v4 < (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) );
  }
}

// File Line: 2948
// RVA: 0x46B520
bool __fastcall UFG::PhysicsWheeledVehicle::IsWheelOnGround(UFG::PhysicsWheeledVehicle *this, int wheelNum)
{
  UFG::VehicleInstance *mHavokVehicle; // rcx

  mHavokVehicle = this->mHavokVehicle;
  return !mHavokVehicle || mHavokVehicle->m_wheelsInfo.hkpVehicleInstance::m_data[wheelNum].m_contactBody != 0i64;
}

// File Line: 2963
// RVA: 0x466BB0
float __fastcall UFG::PhysicsWheeledVehicle::GetMinSuspensionLength(UFG::PhysicsWheeledVehicle *this, int i)
{
  return this->mRestingSuspensionLength.array[i] - this->mSuspensionUpTravelLimit.array[i];
}

// File Line: 2970
// RVA: 0x466B90
float __fastcall UFG::PhysicsWheeledVehicle::GetMaxSuspensionLength(UFG::PhysicsWheeledVehicle *this, int i)
{
  return this->mSuspensionDownTravelLimit.array[i] + this->mRestingSuspensionLength.array[i];
}

// File Line: 2977
// RVA: 0x46AF50
bool __fastcall UFG::PhysicsWheeledVehicle::IsInDeepWater(UFG::PhysicsWheeledVehicle *this)
{
  UFG::WaterFloatingTrackerComponent *mWaterFloatingTrackerComponent; // rbx

  mWaterFloatingTrackerComponent = this->mWaterFloatingTrackerComponent;
  return ((unsigned __int8 (__fastcall *)(UFG::PhysicsWheeledVehicle *))this->vfptr[4].DebugDraw)(this)
      && mWaterFloatingTrackerComponent
      && mWaterFloatingTrackerComponent->mInWaterState > 0;
}

// File Line: 2985
// RVA: 0x474C80
void __fastcall UFG::PhysicsWheeledVehicle::SetEngineDamage(UFG::PhysicsWheeledVehicle *this, float damage)
{
  UFG::Engine *mEngine; // rax

  mEngine = this->mEngine;
  if ( mEngine )
    mEngine->mDamage = damage;
}

// File Line: 3005
// RVA: 0x467010
float __fastcall UFG::PhysicsWheeledVehicle::GetRPM(UFG::PhysicsWheeledVehicle *this)
{
  UFG::VehicleInstance *mHavokVehicle; // rcx
  float result; // xmm0_4

  mHavokVehicle = this->mHavokVehicle;
  if ( !mHavokVehicle )
    return FLOAT_1000_0;
  ((void (__fastcall *)(UFG::VehicleInstance *))mHavokVehicle->vfptr[6].__vecDelDtor)(mHavokVehicle);
  return result;
}

// File Line: 3019
// RVA: 0x466840
float __fastcall UFG::PhysicsWheeledVehicle::GetHalfSteeringRange(UFG::PhysicsWheeledVehicle *this)
{
  UFG::VehicleInstance *mHavokVehicle; // rax
  hkpVehicleSteering *m_steering; // rax
  float result; // xmm0_4

  mHavokVehicle = this->mHavokVehicle;
  if ( !mHavokVehicle )
    return FLOAT_0_78539819;
  m_steering = mHavokVehicle->m_steering;
  if ( !m_steering )
    return FLOAT_0_78539819;
  LODWORD(result) = *(_DWORD *)&m_steering[3].m_memSizeAndFlags & _xmm;
  return result;
}

// File Line: 3032
// RVA: 0x468400
float __fastcall UFG::PhysicsWheeledVehicle::GetWheelAngle(UFG::PhysicsWheeledVehicle *this, int index)
{
  return this->mWheelSpinAngle.array[index];
}

// File Line: 3052
// RVA: 0x45A6E0
void __fastcall UFG::PhysicsWheeledVehicle::ClearSteeringDeadZone(UFG::PhysicsWheeledVehicle *this)
{
  UFG::VehicleInstance *mHavokVehicle; // rax

  mHavokVehicle = this->mHavokVehicle;
  if ( mHavokVehicle )
    LODWORD(mHavokVehicle->m_driverInput[1].vfptr) = 0;
}

// File Line: 3063
// RVA: 0x466C40
unsigned __int64 __fastcall UFG::PhysicsWheeledVehicle::GetObjectPropertyHandleUidUnderWheel(
        UFG::PhysicsWheeledVehicle *this,
        int wheelNum)
{
  __int64 v2; // r9
  hkpVehicleWheelCollide *mWheelCollider; // r8
  hkpVehicleWheelCollide *v5; // rdx

  v2 = wheelNum;
  if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
  {
    mWheelCollider = this->mWheelCollider;
    if ( mWheelCollider )
      return *((_QWORD *)&mWheelCollider[5].vfptr + wheelNum);
  }
  else
  {
    v5 = this->mWheelCollider;
    if ( v5 )
      return *((_QWORD *)&v5[4].m_memSizeAndFlags + v2);
  }
  return 0i64;
}

// File Line: 3099
// RVA: 0x468410
float __fastcall UFG::PhysicsWheeledVehicle::GetWheelFrictionMultiplier(
        UFG::PhysicsWheeledVehicle *this,
        int wheelIndex)
{
  __int64 v2; // r9
  hkpVehicleWheelCollide *mWheelCollider; // r8
  hkpVehicleWheelCollide *v5; // rdx

  v2 = wheelIndex;
  if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
  {
    mWheelCollider = this->mWheelCollider;
    if ( mWheelCollider )
      return *((float *)&mWheelCollider[8].m_memSizeAndFlags + wheelIndex);
  }
  else
  {
    v5 = this->mWheelCollider;
    if ( v5 )
      return *((float *)&v5[7].m_alreadyUsed.m_bool + v2);
  }
  return 0.0;
}

// File Line: 3116
// RVA: 0x475860
void __fastcall UFG::PhysicsWheeledVehicle::SetWheelFrictionMultiplier(
        UFG::PhysicsWheeledVehicle *this,
        unsigned int wheelIndex,
        float multiplier)
{
  hkpVehicleWheelCollide *mWheelCollider; // r8

  mWheelCollider = this->mWheelCollider;
  if ( mWheelCollider )
  {
    if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
      *((float *)&mWheelCollider[8].m_memSizeAndFlags + wheelIndex) = multiplier;
    else
      *((float *)&mWheelCollider[7].m_alreadyUsed.m_bool + wheelIndex) = multiplier;
  }
}

// File Line: 3139
// RVA: 0x467B20
unsigned __int64 __fastcall UFG::PhysicsWheeledVehicle::GetSurfacePropertyHandleUidUnderWheel(
        UFG::PhysicsWheeledVehicle *this,
        int wheelNum)
{
  __int64 v2; // r9
  hkpVehicleWheelCollide *mWheelCollider; // r8
  hkpVehicleWheelCollide *v5; // rdx

  v2 = wheelNum;
  if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
  {
    mWheelCollider = this->mWheelCollider;
    if ( mWheelCollider )
      return *((_QWORD *)&mWheelCollider[3].m_alreadyUsed.m_bool + wheelNum);
  }
  else
  {
    v5 = this->mWheelCollider;
    if ( v5 )
      return *((_QWORD *)&v5[3].vfptr + v2);
  }
  return 0i64;
}

// File Line: 3168
// RVA: 0x456030
void __fastcall UFG::PhysicsWheeledVehicle::AddWheelPhantoms(UFG::PhysicsWheeledVehicle *this)
{
  UFG::BasePhysicsSystem *v1; // rsi
  int v2; // edi
  __int64 v3; // rbx
  char *v4; // [rsp+28h] [rbp-20h] BYREF
  int v5; // [rsp+30h] [rbp-18h]
  int v6; // [rsp+34h] [rbp-14h]

  v1 = UFG::BasePhysicsSystem::mInstance;
  if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
  {
    v4 = 0i64;
    v5 = 0;
    v6 = 0x80000000;
    ((void (__fastcall *)(hkpVehicleWheelCollide *, char **))this->mHavokVehicle->m_wheelCollide->vfptr[2].__first_virtual_table_function__)(
      this->mHavokVehicle->m_wheelCollide,
      &v4);
    v2 = 0;
    if ( v5 > 0 )
    {
      v3 = 0i64;
      do
      {
        UFG::BasePhysicsSystem::AddEntity(v1, *(hkpPhantom **)&v4[v3], 1);
        ++v2;
        v3 += 8i64;
      }
      while ( v2 < v5 );
    }
    v5 = 0;
    if ( v6 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v4, 8 * v6);
    v4 = 0i64;
    v6 = 0x80000000;
  }
  else
  {
    UFG::BasePhysicsSystem::AddEntity(
      UFG::BasePhysicsSystem::mInstance,
      *(hkpPhantom **)&this->mHavokVehicle->m_wheelCollide[1].m_memSizeAndFlags,
      1);
  }
}

// File Line: 3202
// RVA: 0x473320
void __fastcall UFG::PhysicsWheeledVehicle::RemoveWheelPhantoms(UFG::PhysicsWheeledVehicle *this)
{
  UFG::BasePhysicsSystem *v1; // rsi
  int v2; // edi
  __int64 v3; // rbx
  char *v4; // [rsp+28h] [rbp-20h] BYREF
  int v5; // [rsp+30h] [rbp-18h]
  int v6; // [rsp+34h] [rbp-14h]

  v1 = UFG::BasePhysicsSystem::mInstance;
  if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
  {
    v4 = 0i64;
    v5 = 0;
    v6 = 0x80000000;
    ((void (__fastcall *)(hkpVehicleWheelCollide *, char **))this->mHavokVehicle->m_wheelCollide->vfptr[2].__first_virtual_table_function__)(
      this->mHavokVehicle->m_wheelCollide,
      &v4);
    v2 = 0;
    if ( v5 > 0 )
    {
      v3 = 0i64;
      do
      {
        UFG::BasePhysicsSystem::RemoveEntity(v1, *(hkpPhantom **)&v4[v3], 0);
        ++v2;
        v3 += 8i64;
      }
      while ( v2 < v5 );
    }
    v5 = 0;
    if ( v6 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v4, 8 * v6);
    v4 = 0i64;
    v6 = 0x80000000;
  }
  else
  {
    UFG::BasePhysicsSystem::RemoveEntity(
      UFG::BasePhysicsSystem::mInstance,
      *(hkpPhantom **)&this->mHavokVehicle->m_wheelCollide[1].m_memSizeAndFlags,
      0);
  }
}

