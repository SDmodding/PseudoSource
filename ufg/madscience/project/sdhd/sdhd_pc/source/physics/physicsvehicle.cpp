// File Line: 88
// RVA: 0x1513F70
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::BaseVehiclePhysicsDef_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::BaseVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::BaseVehiclePhysicsDef,UFG::qReflectObject>::sInventory.vfptr,
    "UFG::BaseVehiclePhysicsDef",
    v0);
  UFG::qReflectObjectType<UFG::BaseVehiclePhysicsDef,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::BaseVehiclePhysicsDef>::`vftable;
  UFG::qReflectInventory<UFG::BaseVehiclePhysicsDef>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::BaseVehiclePhysicsDef,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::BaseVehiclePhysicsDef,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::BaseVehiclePhysicsDef_UFG::qReflectObject_::sInventory__);
}

// File Line: 89
// RVA: 0x15141F0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::WheeledVehiclePhysicsDef_UFG::BaseVehiclePhysicsDef_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::WheeledVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory.vfptr,
    "UFG::WheeledVehiclePhysicsDef",
    v0);
  UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::WheeledVehiclePhysicsDef>::`vftable;
  UFG::qReflectInventory<UFG::WheeledVehiclePhysicsDef>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::WheeledVehiclePhysicsDef_UFG::BaseVehiclePhysicsDef_::sInventory__);
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
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::BikePhysicsDef,UFG::WheeledVehiclePhysicsDef>::sInventory.vfptr,
    "UFG::BikePhysicsDef",
    v0);
  UFG::qReflectObjectType<UFG::BikePhysicsDef,UFG::WheeledVehiclePhysicsDef>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::BikePhysicsDef>::`vftable;
  UFG::qReflectInventory<UFG::BikePhysicsDef>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::BikePhysicsDef,UFG::WheeledVehiclePhysicsDef>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::BikePhysicsDef,UFG::WheeledVehiclePhysicsDef>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::BikePhysicsDef_UFG::WheeledVehiclePhysicsDef_::sInventory__);
}

// File Line: 92
// RVA: 0x1514070
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::BoatPhysicsDef_UFG::BaseVehiclePhysicsDef_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::BoatPhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::BoatPhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory.vfptr,
    "UFG::BoatPhysicsDef",
    v0);
  UFG::qReflectObjectType<UFG::BoatPhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::BoatPhysicsDef>::`vftable;
  UFG::qReflectInventory<UFG::BoatPhysicsDef>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::BoatPhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::BoatPhysicsDef,UFG::BaseVehiclePhysicsDef>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::BoatPhysicsDef_UFG::BaseVehiclePhysicsDef_::sInventory__);
}

// File Line: 98
// RVA: 0x1513D10
__int64 dynamic_initializer_for__UFG::BaseVehiclePhysicsDef::mSearchTree__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::BaseVehiclePhysicsDef::mSearchTree__);
}

// File Line: 113
// RVA: 0x1513CA0
__int64 dynamic_initializer_for__UFG::PhysicsVehicle::mAllocator__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::PhysicsVehicle::mAllocator);
  return atexit(dynamic_atexit_destructor_for__UFG::PhysicsVehicle::mAllocator__);
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
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v1; // [rsp+48h] [rbp+10h]

  this->mPhysicsPropertiesName.mUID = -1;
  v1 = &this->mSimObject;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  this->mSimObject.m_pPointer = 0i64;
  UFG::qString::qString(&this->modelName);
}

// File Line: 163
// RVA: 0x468DD0
void __fastcall UFG::VehicleParams::Init(UFG::VehicleParams *this, UFG::qSymbol *physicsPropertiesName, const char *model_name)
{
  UFG::qSymbol *v3; // rbx
  UFG::VehicleParams *v4; // rdi

  v3 = physicsPropertiesName;
  v4 = this;
  UFG::qString::Set(&this->modelName, model_name);
  v4->mPhysicsPropertiesName = (UFG::qSymbol)v3->mUID;
}

// File Line: 171
// RVA: 0x4519B0
void __fastcall UFG::VehicleParams::~VehicleParams(UFG::VehicleParams *this)
{
  UFG::VehicleParams *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  UFG::qString::~qString(&this->modelName);
  v2 = &v1->mSimObject;
  if ( v2->m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
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
    UFG::PhysicsVehicle::mAllocatorBuffer,
    149760,
    1248,
    "PhysicsVehiclePool");
}

// File Line: 259
// RVA: 0x44BD30
void __usercall UFG::PhysicsVehicle::PhysicsVehicle(UFG::PhysicsVehicle *this@<rcx>, UFG::VehicleParams *param@<rdx>, UFG::qMatrix44 *transform@<r8>, UFG::qVector3 *velocity@<r9>, __m128 *a5@<xmm10>)
{
  UFG::qMatrix44 *v5; // rdi
  UFG::PhysicsVehicle *v6; // r14
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v7; // rax
  UFG::SimComponent *v8; // r13
  UFG::qReflectHandleBase *v9; // rsi
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm3_4
  UFG::qSafePointer<UFG::SimComponent,UFG::ParkourComponent> *v49; // r12
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *v50; // r15
  unsigned int v51; // edx
  UFG::qBaseTreeRB *v52; // rax
  UFG::qReflectObject *v53; // rcx
  const char *v54; // rcx
  unsigned int v55; // ebx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v56; // rcx
  const char *v57; // rax
  UFG::allocator::free_link *v58; // rax
  UFG::CollisionInstanceData *v59; // rax
  UFG::CollisionInstanceData *v60; // rdi
  UFG::RigidBodyComponent *v61; // rbx
  unsigned int v62; // eax
  UFG::RigidBodyComponent *v63; // rax
  UFG::RigidBodyComponent *v64; // rcx
  hkpRigidBody *v65; // rdi
  UFG::qReflectObject *v66; // rbx
  float v67; // xmm6_4
  signed __int64 v68; // rbx
  char v69; // dl
  __int64 v70; // rax
  char v71; // cl
  _QWORD **v72; // rax
  hkpRigidBody *v73; // rax
  hkpRigidBody *v74; // rax
  char v75; // al
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v76; // rcx
  const char *v77; // rax
  unsigned int v78; // ebx
  UFG::allocator::free_link *v79; // rax
  UFG::SimComponent *v80; // rax
  UFG::SimComponent *v81; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v82; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v83; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v84; // rax
  unsigned int v85; // ebx
  UFG::allocator::free_link *v86; // rax
  UFG::SimComponent *v87; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v88; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v89; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v90; // rax
  UFG::SimObjectModifier v91; // [rsp+40h] [rbp-80h]
  __m128 v92; // [rsp+60h] [rbp-60h]
  hkQsTransformf orient; // [rsp+70h] [rbp-50h]
  hkTransformf transforma; // [rsp+A0h] [rbp-20h]
  hkpRigidBodyCinfo info; // [rsp+E0h] [rbp+20h]
  UFG::qSymbol result[2]; // [rsp+228h] [rbp+168h]
  UFG::qSymbol name[2]; // [rsp+230h] [rbp+170h]
  unsigned int *v98; // [rsp+238h] [rbp+178h]

  v91.mptrSimObject.m_pPointer = (UFG::SimObject *)-2i64;
  v5 = transform;
  v6 = this;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  this->mUserData.isBoat = 0;
  v7 = &this->mUserData.simComponent;
  v92.m128_u64[1] = (unsigned __int64)v7;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v8 = 0i64;
  this->mUserData.simComponent.m_pPointer = 0i64;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsVehicle::`vftable;
  this->mWaterFloatingTrackerComponent = 0i64;
  this->mParams = param;
  v9 = (UFG::qReflectHandleBase *)&this->mDnaDefinition.mPrev;
  *(_QWORD *)&name[0].mUID = (char *)this + 56;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&this->mDnaDefinition.mPrev);
  v9->mTypeUID = UFG::qStringHash64("UFG::BaseVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  v6->mRigidBody = 0i64;
  v6->mBulletCollider = 0i64;
  v6->mVolumeRigidBody = 0i64;
  *(_QWORD *)&name[0].mUID = (char *)v6 + 120;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v6->mCollisionMeshBundle.mPrev);
  v6->mCollisionMeshBundle.mOwner = 0i64;
  v6->mCollisionMeshBundle.mUnloading = 0;
  v10 = v5->v0.y;
  v11 = v5->v0.z;
  v12 = v5->v0.w;
  v6->mLastGoodPosition.v0.x = v5->v0.x;
  v6->mLastGoodPosition.v0.y = v10;
  v6->mLastGoodPosition.v0.z = v11;
  v6->mLastGoodPosition.v0.w = v12;
  v13 = v5->v1.y;
  v14 = v5->v1.z;
  v15 = v5->v1.w;
  v6->mLastGoodPosition.v1.x = v5->v1.x;
  v6->mLastGoodPosition.v1.y = v13;
  v6->mLastGoodPosition.v1.z = v14;
  v6->mLastGoodPosition.v1.w = v15;
  v16 = v5->v2.y;
  v17 = v5->v2.z;
  v18 = v5->v2.w;
  v6->mLastGoodPosition.v2.x = v5->v2.x;
  v6->mLastGoodPosition.v2.y = v16;
  v6->mLastGoodPosition.v2.z = v17;
  v6->mLastGoodPosition.v2.w = v18;
  v19 = v5->v3.y;
  v20 = v5->v3.z;
  v21 = v5->v3.w;
  v6->mLastGoodPosition.v3.x = v5->v3.x;
  v6->mLastGoodPosition.v3.y = v19;
  v6->mLastGoodPosition.v3.z = v20;
  v6->mLastGoodPosition.v3.w = v21;
  v22 = v5->v0.y;
  v23 = v5->v0.z;
  v24 = v5->v0.w;
  v6->mBodyTransform.v0.x = v5->v0.x;
  v6->mBodyTransform.v0.y = v22;
  v6->mBodyTransform.v0.z = v23;
  v6->mBodyTransform.v0.w = v24;
  v25 = v5->v1.y;
  v26 = v5->v1.z;
  v27 = v5->v1.w;
  v6->mBodyTransform.v1.x = v5->v1.x;
  v6->mBodyTransform.v1.y = v25;
  v6->mBodyTransform.v1.z = v26;
  v6->mBodyTransform.v1.w = v27;
  v28 = v5->v2.y;
  v29 = v5->v2.z;
  v30 = v5->v2.w;
  v6->mBodyTransform.v2.x = v5->v2.x;
  v6->mBodyTransform.v2.y = v28;
  v6->mBodyTransform.v2.z = v29;
  v6->mBodyTransform.v2.w = v30;
  v31 = v5->v3.y;
  v32 = v5->v3.z;
  v33 = v5->v3.w;
  v6->mBodyTransform.v3.x = v5->v3.x;
  v6->mBodyTransform.v3.y = v31;
  v6->mBodyTransform.v3.z = v32;
  v6->mBodyTransform.v3.w = v33;
  v34 = v5->v0.y;
  v35 = v5->v0.z;
  v36 = v5->v0.w;
  v6->mTargetTransform.v0.x = v5->v0.x;
  v6->mTargetTransform.v0.y = v34;
  v6->mTargetTransform.v0.z = v35;
  v6->mTargetTransform.v0.w = v36;
  v37 = v5->v1.y;
  v38 = v5->v1.z;
  v39 = v5->v1.w;
  v6->mTargetTransform.v1.x = v5->v1.x;
  v6->mTargetTransform.v1.y = v37;
  v6->mTargetTransform.v1.z = v38;
  v6->mTargetTransform.v1.w = v39;
  v40 = v5->v2.y;
  v41 = v5->v2.z;
  v42 = v5->v2.w;
  v6->mTargetTransform.v2.x = v5->v2.x;
  v6->mTargetTransform.v2.y = v40;
  v6->mTargetTransform.v2.z = v41;
  v6->mTargetTransform.v2.w = v42;
  v43 = v5->v3.y;
  v44 = v5->v3.z;
  v45 = v5->v3.w;
  v6->mTargetTransform.v3.x = v5->v3.x;
  v6->mTargetTransform.v3.y = v43;
  v6->mTargetTransform.v3.z = v44;
  v6->mTargetTransform.v3.w = v45;
  v46 = UFG::qVector4::msZero.y;
  v47 = UFG::qVector4::msZero.z;
  v48 = UFG::qVector4::msZero.w;
  v6->mLastFixupPosition.x = UFG::qVector4::msZero.x;
  v6->mLastFixupPosition.y = v46;
  v6->mLastFixupPosition.z = v47;
  v6->mLastFixupPosition.w = v48;
  v6->mLastGoodPositionSampleTimer = 0.0;
  v6->mCollisionListener = 0i64;
  v6->mReorientActionRoll = 0i64;
  v6->mReorientActionPitch = 0i64;
  v49 = &v6->mParkourComponent;
  v49->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v49->mPrev;
  v49->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v49->mPrev;
  v6->mParkourComponent.m_pPointer = 0i64;
  v50 = &v6->mCoverComponent;
  *(_QWORD *)&name[0].mUID = v50;
  v50->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v50->mPrev;
  v50->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v50->mPrev;
  v6->mCoverComponent.m_pPointer = 0i64;
  *(_QWORD *)&v6->mDesiredLod = 1i64;
  v6->mIsProxy = 0;
  *(_QWORD *)&v6->mSpeedKPH = 0i64;
  v6->mRotMassScaleForCollisions = 2.5;
  *((_DWORD *)v6 + 151) &= 0xFFFFFFF7;
  *((_DWORD *)v6 + 151) |= 0x10u;
  v51 = v6->mParams->mPhysicsPropertiesName.mUID;
  if ( v51 )
  {
    v52 = UFG::qBaseTreeRB::Get(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree, v51);
    if ( v52 )
      UFG::qReflectHandleBase::Init(v9, v9->mTypeUID, (unsigned __int64)v52->mNULL.mParent);
  }
  UFG::PhysicsVehicle::LoadProperties(v6);
  *((_DWORD *)v6 + 151) ^= (*((_DWORD *)v6 + 151) ^ LODWORD(v6->mDnaDefinition.mData[1].mBaseNode.mParent)) & 7;
  v6->mSystemId = UFG::CustomCollisionFilter::GetUnusedSystemId(UFG::BasePhysicsSystem::mInstance->mCollisionFilter);
  hkTransformf::set4x4ColumnMajor(&transforma, &v5->v0.x);
  hkQsTransformf::setFromTransformNoScale(&orient, &transforma);
  v53 = v6->mDnaDefinition.mData;
  if ( LODWORD(v53[1].mBaseNode.mUID) )
    v54 = (const char *)v53[1].vfptr;
  else
    v54 = &customWorldMapCaption;
  v55 = UFG::qStringHashUpper32(v54, 0xFFFFFFFF);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&orient);
  v57 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v56);
  *(_QWORD *)&v91.mbOpen = UFG::qStringHash64(v57, 0xFFFFFFFFFFFFFFFFui64);
  UFG::PhysicsPropertyManager::GetObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&orient, v55, 0);
  UFG::PhysicsVehicle::SetupCollisionGeometry(v6, *(const char **)(*(_QWORD *)&result[0].mUID + 56i64));
  v58 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x70ui64, "CollisionInstanceData", 0i64, 1u);
  *(_QWORD *)&name[0].mUID = v58;
  if ( v58 )
  {
    UFG::CollisionInstanceData::CollisionInstanceData((UFG::CollisionInstanceData *)v58);
    v60 = v59;
  }
  else
  {
    v60 = 0i64;
  }
  UFG::qSymbol::create_from_string(result, "PhysicsVehicle");
  v92.m128_u64[1] = (unsigned __int64)name;
  name[0] = result[0];
  UFG::CollisionInstanceData::Set(
    v60,
    result[0].mUID,
    0,
    (__int64)name,
    &orient.m_translation,
    &orient.m_rotation,
    v6->mBodyCollisionMesh->mNode.mUID);
  v61 = (UFG::RigidBodyComponent *)UFG::RigidBodyComponent::mAllocator.mFreeListHead;
  if ( UFG::RigidBodyComponent::mAllocator.mFreeListHead )
  {
    UFG::RigidBodyComponent::mAllocator.mFreeListHead = *(char **)UFG::RigidBodyComponent::mAllocator.mFreeListHead;
    v62 = UFG::RigidBodyComponent::mAllocator.mNumSlotsAllocated + 1;
    UFG::RigidBodyComponent::mAllocator.mNumSlotsAllocated = v62;
    if ( UFG::RigidBodyComponent::mAllocator.mMostSlotsAllocated <= v62 )
      UFG::RigidBodyComponent::mAllocator.mMostSlotsAllocated = v62;
    *(_QWORD *)&name[0].mUID = v61;
  }
  else
  {
    v61 = (UFG::RigidBodyComponent *)UFG::qMemoryPool::Allocate(
                                       &gPhysicsMemoryPool,
                                       0x1D8ui64,
                                       "RigidBodyComponent",
                                       0i64,
                                       1u);
    *(_QWORD *)&name[0].mUID = v61;
  }
  if ( v61 )
  {
    UFG::RigidBodyComponent::RigidBodyComponent(v61, v6->mBodyCollisionMesh, v60, 0x30000u, -1);
    v64 = v63;
  }
  else
  {
    v64 = 0i64;
  }
  v6->mRigidBody = v64;
  v64->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v64->vfptr, 0);
  UFG::RigidBody::SetCollisionLayer((UFG::RigidBody *)&v6->mRigidBody->vfptr, 0x16u, v6->mSystemId, 1, 1);
  v65 = v6->mRigidBody->mBody;
  v66 = v6->mDnaDefinition.mData;
  v67 = *((float *)&v66[1].mBaseNode.mParent + 1) / hkpMotion::getMass((hkpMotion *)&v65->m_motion.vfptr);
  hkpRigidBody::setMass(v65, *((float *)&v6->mDnaDefinition.mData[1].mBaseNode.mParent + 1));
  UFG::CollisionMeshData::GetInertiaTensor(v6->mBodyCollisionMesh, (hkMatrix3f *)&transforma.m_rotation.m_col0, v67, a5);
  hkpRigidBody::setInertiaLocal(v65, (hkMatrix3f *)&transforma.m_rotation.m_col0);
  hkpRigidBody::setFriction(v65, *(float *)v6->mDnaDefinition.mData[1].mBaseNode.mChildren);
  hkpRigidBody::setRestitution(v65, *((float *)v6->mDnaDefinition.mData[1].mBaseNode.mChildren + 1));
  v65->m_responseModifierFlags = 1;
  UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
    (unsigned __int64)v91.mptrSimObject.mNext->mNext,
    (hkpWorldObject *)&v65->vfptr);
  v92 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)*v98, (__m128)v98[2]), _mm_unpacklo_ps((__m128)v98[1], (__m128)0i64));
  hkpEntity::activate((hkpEntity *)&v65->vfptr);
  v65->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v65->m_motion.vfptr, (unsigned int)&v92);
  UFG::SimObjectModifier::SimObjectModifier(&v91, v6->mParams->mSimObject.m_pPointer, 1);
  UFG::SimObjectModifier::AttachComponent(&v91, (UFG::SimComponent *)&v6->mRigidBody->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v91);
  UFG::SimObjectModifier::~SimObjectModifier(&v91);
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&info);
  UFG::CollisionMeshData::GetInertiaTensor(v6->mBulletCollisionMesh, &info.m_inertiaTensor, 1.0, a5);
  UFG::CollisionMeshData::GetCentreOfMass(v6->mBulletCollisionMesh, &info.m_centerOfMass);
  info.m_collisionFilterInfo = 27;
  info.m_shape = v6->mBulletCollisionMesh->mShape;
  info.m_position = orient.m_translation;
  info.m_rotation = orient.m_rotation;
  info.m_motionType.m_storage = 5;
  v68 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v69 = ++*(_BYTE *)(v68 + 80);
  v70 = v69;
  *(_DWORD *)(v68 + 4 * v70) = 0;
  *(_QWORD *)(v68 + 8 * v70 + 16) = "hkpRigidBody";
  *(_QWORD *)(v68 + 8 * v70 + 48) = 0i64;
  v71 = *(_BYTE *)(v68 + 81);
  if ( v69 > v71 )
    v71 = v69;
  *(_BYTE *)(v68 + 81) = v71;
  v72 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v73 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v72[11] + 8i64))(v72[11], 720i64);
  *(_QWORD *)&result[0].mUID = v73;
  if ( v73 )
    hkpRigidBody::hkpRigidBody(v73, &info);
  else
    v74 = 0i64;
  v6->mBulletCollider = v74;
  v75 = *(_BYTE *)(v68 + 80);
  if ( v75 > 0 )
  {
    *(_BYTE *)(v68 + 80) = v75 - 1;
  }
  else
  {
    *(_BYTE *)(v68 + 80) = 0;
    *(_DWORD *)v68 = 3;
    *(_QWORD *)(v68 + 16) = 0i64;
    *(_QWORD *)(v68 + 48) = 0i64;
  }
  if ( !(_S11_5 & 1) )
  {
    _S11_5 |= 1u;
    bulletMoppGuid = UFG::qStringHashUpper32("BulletMopp", 0xFFFFFFFF);
  }
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v91);
  v77 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v76);
  v91.mptrSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)UFG::qStringHash64(v77, 0xFFFFFFFFFFFFFFFFui64);
  UFG::PhysicsPropertyManager::GetObjectProperties(
    (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v91,
    bulletMoppGuid,
    0);
  UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
    *(_QWORD *)(v92.m128_u64[0] + 8),
    (hkpWorldObject *)&v6->mBulletCollider->vfptr);
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v91);
  v78 = v6->mBodyCollisionMesh->mParkourGuid;
  if ( v78 )
  {
    v79 = UFG::qMalloc(0xC8ui64, "ParkourComponent", 0x800ui64);
    *(_QWORD *)&result[0].mUID = v79;
    if ( v79 )
    {
      UFG::ParkourComponent::ParkourComponent((UFG::ParkourComponent *)v79, v78, -1);
      v81 = v80;
    }
    else
    {
      v81 = 0i64;
    }
    if ( v6->mParkourComponent.m_pPointer )
    {
      v82 = v49->mPrev;
      v83 = v6->mParkourComponent.mNext;
      v82->mNext = v83;
      v83->mPrev = v82;
      v49->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v49->mPrev;
      v6->mParkourComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mParkourComponent.mPrev;
    }
    v6->mParkourComponent.m_pPointer = v81;
    if ( v81 )
    {
      v84 = v81->m_SafePointerList.mNode.mPrev;
      v84->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v49->mPrev;
      v49->mPrev = v84;
      v6->mParkourComponent.mNext = &v81->m_SafePointerList.mNode;
      v81->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v49->mPrev;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v91, v6->mParams->mSimObject.m_pPointer, 1);
    UFG::SimObjectModifier::AttachComponent(&v91, v6->mParkourComponent.m_pPointer, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v91);
    UFG::SimObjectModifier::~SimObjectModifier(&v91);
  }
  v85 = v6->mBodyCollisionMesh->mCoverGuid;
  if ( v85 )
  {
    v86 = UFG::qMalloc(0x88ui64, "DynamicCoverComponent", 0x800ui64);
    *(_QWORD *)&result[0].mUID = v86;
    if ( v86 )
    {
      UFG::DynamicCoverComponent::DynamicCoverComponent((UFG::DynamicCoverComponent *)v86, v85);
      v8 = v87;
    }
    if ( v6->mCoverComponent.m_pPointer )
    {
      v88 = v50->mPrev;
      v89 = v6->mCoverComponent.mNext;
      v88->mNext = v89;
      v89->mPrev = v88;
      v50->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v50->mPrev;
      v6->mCoverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mCoverComponent.mPrev;
    }
    v6->mCoverComponent.m_pPointer = v8;
    if ( v8 )
    {
      v90 = v8->m_SafePointerList.mNode.mPrev;
      v90->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v50->mPrev;
      v50->mPrev = v90;
      v6->mCoverComponent.mNext = &v8->m_SafePointerList.mNode;
      v8->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v50->mPrev;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v91, v6->mParams->mSimObject.m_pPointer, 1);
    UFG::SimObjectModifier::AttachComponent(&v91, v6->mCoverComponent.m_pPointer, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v91);
    UFG::SimObjectModifier::~SimObjectModifier(&v91);
  }
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&orient);
}

// File Line: 379
// RVA: 0x4507D0
void __fastcall UFG::PhysicsVehicle::~PhysicsVehicle(UFG::PhysicsVehicle *this)
{
  UFG::PhysicsVehicle *v1; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  hkpRigidBody *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ParkourComponent> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax

  v1 = this;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsVehicle::`vftable;
  UFG::CustomCollisionFilter::ReleaseSystemId(UFG::BasePhysicsSystem::mInstance->mCollisionFilter, this->mSystemId);
  v1->mCollisionMeshBundle.mOwner = 0i64;
  UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)&v1->mWaterFloatingTrackerComponent->vfptr);
  v2 = &v1->mUserData.simComponent;
  if ( v1->mUserData.simComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->mUserData.simComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->mUserData.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mUserData.simComponent.mPrev;
  }
  v1->mUserData.simComponent.m_pPointer = 0i64;
  v5 = v1->mBulletCollider;
  if ( v5 )
    v5->m_userData = 0i64;
  UFG::PhysicsVehicle::DeleteHavokComponents(v1);
  UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)&v1->mRigidBody->vfptr);
  v6 = &v1->mCoverComponent;
  if ( v1->mCoverComponent.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v1->mCoverComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v1->mCoverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mCoverComponent.mPrev;
  }
  v1->mCoverComponent.m_pPointer = 0i64;
  v9 = v6->mPrev;
  v10 = v1->mCoverComponent.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v1->mCoverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mCoverComponent.mPrev;
  v11 = &v1->mParkourComponent;
  if ( v1->mParkourComponent.m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v1->mParkourComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v1->mParkourComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mParkourComponent.mPrev;
  }
  v1->mParkourComponent.m_pPointer = 0i64;
  v14 = v11->mPrev;
  v15 = v1->mParkourComponent.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v1->mParkourComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mParkourComponent.mPrev;
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mCollisionMeshBundle.mPrev);
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mDnaDefinition.mPrev);
  UFG::BasePhysicsObject::~BasePhysicsObject((UFG::BasePhysicsObject *)&v1->vfptr);
}

// File Line: 401
// RVA: 0x472BC0
void __fastcall UFG::PhysicsVehicle::Reload(UFG::PhysicsVehicle *this, UFG::qSymbol *physicsPropertiesName)
{
  UFG::PhysicsVehicle *v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax

  v2 = this;
  this->mParams->mPhysicsPropertiesName.mUID = physicsPropertiesName->mUID;
  v3 = this->mParams->mPhysicsPropertiesName.mUID;
  if ( v3 )
  {
    v4 = UFG::qBaseTreeRB::Get(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree, v3);
    if ( v4 )
      UFG::qReflectHandleBase::Init(
        (UFG::qReflectHandleBase *)&v2->mDnaDefinition.mPrev,
        v2->mDnaDefinition.mTypeUID,
        (unsigned __int64)v4->mNULL.mParent);
  }
  UFG::PhysicsVehicle::LoadProperties(v2);
}

// File Line: 414
// RVA: 0x474A10
void __fastcall UFG::PhysicsVehicle::SetControlledByAi(UFG::PhysicsVehicle *this, bool aiControlled)
{
  UFG::PhysicsVehicle *v2; // rbx

  v2 = this;
  if ( aiControlled )
  {
    if ( !(*((_BYTE *)this + 604) & 0x10) )
    {
      UFG::PhysicsVehicle::ClearMassScaleForCollisions(this);
      *((_DWORD *)v2 + 151) |= 0x10u;
    }
  }
  else if ( *((_BYTE *)this + 604) & 0x10 )
  {
    UFG::PhysicsVehicle::SetMassScaleForCollisions(this, 1.0, this->mRotMassScaleForCollisions);
    *((_DWORD *)v2 + 151) &= 0xFFFFFFEF;
  }
}

// File Line: 437
// RVA: 0x46BAB0
void __fastcall UFG::PhysicsVehicle::LoadProperties(UFG::PhysicsVehicle *this)
{
  UFG::PhysicsVehicle *v1; // rbx
  UFG::qReflectObject *v2; // rcx
  char *v3; // rax
  UFG::qReflectHandleBase v4; // [rsp+28h] [rbp-30h]

  v1 = this;
  UFG::qReflectHandleBase::qReflectHandleBase(&v4);
  v4.mTypeUID = UFG::qStringHash64("UFG::BaseVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v4, v4.mTypeUID, v1->mDnaDefinition.mData->mBaseNode.mUID);
  v2 = v4.mData;
  v1->mAirSteerYawRate = *((float *)v4.mData[1].mBaseNode.mNeighbours + 1);
  v1->mVerticalVelocityDampingDown = *((float *)&v2[1].mBaseNode.mNeighbours[1] + 1);
  v1->mVerticalVelocityDampingUp = *(float *)&v2[1].mBaseNode.mNeighbours[1];
  if ( *((_BYTE *)v1 + 604) & 0x10 || *(float *)&v2[1].mBaseNode.mChildren[1] <= 130.0 )
  {
    v1->mHighSpeedGovernor = *(float *)&v2[1].mBaseNode.mChildren[1];
  }
  else
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v1->mParams);
    UFG::qPrintf("Error: property set %s has mHighSpeedGovernor set higher than %f.\n", v3, DOUBLE_130_0);
    v1->mHighSpeedGovernor = 130.0;
    v2 = v4.mData;
  }
  v1->mReverseSpeedGovernor = *((float *)&v2[1].mBaseNode.mChildren[1] + 1);
  v1->mSuperStopDrag = *(float *)v2[1].mBaseNode.mNeighbours;
  v1->mPitchStability = *((float *)&v2[1].mTypeUID + 1);
  v1->mRollStability = *(float *)&v2[1].mTypeUID;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v4);
}

// File Line: 469
// RVA: 0x4611E0
void __fastcall UFG::PhysicsVehicle::DeleteHavokComponents(UFG::PhysicsVehicle *this)
{
  UFG::BasePhysicsSystem *v1; // rbx
  UFG::PhysicsVehicle *v2; // rdi
  UFG::VehicleCollisionListener *v3; // rcx
  hkpAction *v4; // rdx
  hkpReorientAction *v5; // rcx
  hkpReorientAction *v6; // rcx
  hkpRigidBody *v7; // rdx
  hkpRigidBody *v8; // rdx
  hkReferencedObject *v9; // rcx
  signed int v10; // ebx

  v1 = UFG::BasePhysicsSystem::mInstance;
  v2 = this;
  v3 = this->mCollisionListener;
  if ( v3 )
    ((void (__fastcall *)(UFG::VehicleCollisionListener *, signed __int64))v3->vfptr->~hkpContactListener)(v3, 1i64);
  v4 = (hkpAction *)&v2->mReorientActionRoll->vfptr;
  v2->mCollisionListener = 0i64;
  if ( v4 )
  {
    UFG::BasePhysicsSystem::RemoveAction(v1, v4);
    v5 = v2->mReorientActionRoll;
    if ( v5 )
      v5->vfptr->__vecDelDtor((hkBaseObject *)&v5->vfptr, 1u);
    v2->mReorientActionRoll = 0i64;
  }
  v6 = v2->mReorientActionPitch;
  if ( v6 )
  {
    v6->vfptr->__vecDelDtor((hkBaseObject *)&v6->vfptr, 1u);
    v2->mReorientActionPitch = 0i64;
  }
  v7 = v2->mRigidBody->mBody;
  if ( v7 )
    UFG::BasePhysicsSystem::RemoveEntity(v1, v7, 0);
  v8 = v2->mBulletCollider;
  if ( v8 )
  {
    UFG::BasePhysicsSystem::RemoveEntity(v1, v8, 0);
    v9 = (hkReferencedObject *)&v2->mBulletCollider->vfptr;
    v10 = v9->m_referenceCount;
    hkReferencedObject::removeReference(v9);
    if ( v10 > 1 )
      v2->mBulletCollider->m_collidable.m_shape = UFG::BasePhysicsSystem::mDummyShape;
    v2->mBulletCollider = 0i64;
  }
  UFG::PhysicsVehicle::DeactivateVolume(v2);
}

// File Line: 519
// RVA: 0x475750
void __fastcall UFG::PhysicsVehicle::SetUserData(UFG::PhysicsVehicle *this, UFG::SimComponent *component)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r9
  UFG::PhysicsVehicle *v3; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  hkpRigidBody *v7; // rcx

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mUserData.simComponent.mPrev;
  v3 = this;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = this->mUserData.simComponent.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = v2;
    this->mUserData.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mUserData.simComponent.mPrev;
  }
  this->mUserData.simComponent.m_pPointer = component;
  if ( component )
  {
    v6 = component->m_SafePointerList.mNode.mPrev;
    v6->mNext = v2;
    v2->mPrev = v6;
    this->mUserData.simComponent.mNext = &component->m_SafePointerList.mNode;
    component->m_SafePointerList.mNode.mPrev = v2;
  }
  v7 = this->mBulletCollider;
  if ( v7 )
  {
    if ( component )
      v7->m_userData = (unsigned __int64)&v3->mUserData;
    else
      v7->m_userData = 0i64;
  }
}

// File Line: 532
// RVA: 0x474270
void __fastcall UFG::PhysicsVehicle::RestoreSuperStopDrag(UFG::PhysicsVehicle *this)
{
  UFG::PhysicsVehicle *v1; // rbx
  UFG::qReflectHandleBase v2; // [rsp+28h] [rbp-30h]

  v1 = this;
  UFG::qReflectHandleBase::qReflectHandleBase(&v2);
  v2.mTypeUID = UFG::qStringHash64("UFG::BaseVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v2, v2.mTypeUID, v1->mDnaDefinition.mData->mBaseNode.mUID);
  v1->mSuperStopDrag = *(float *)v2.mData[1].mBaseNode.mNeighbours;
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
  UFG::PhysicsVehicle *v2; // rbx
  hkpRigidBody *v3; // rdx
  hkpRigidBody *v4; // rdx
  UFG::WaterFloatingTrackerComponent *v5; // rcx

  v1 = UFG::BasePhysicsSystem::mInstance;
  v2 = this;
  v3 = this->mRigidBody->mBody;
  if ( v3 && v3->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, v3, 0);
  v4 = v2->mBulletCollider;
  if ( v4 && v4->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(v1, v4, 0);
  v5 = v2->mWaterFloatingTrackerComponent;
  if ( v5 )
    ((void (*)(void))v5->vfptr[8].__vecDelDtor)();
}

// File Line: 580
// RVA: 0x473EA0
void __fastcall UFG::PhysicsVehicle::Restore(UFG::PhysicsVehicle *this)
{
  UFG::PhysicsVehicle *v1; // rbx
  UFG::BasePhysicsSystem *v2; // rdi
  hkpRigidBody *v3; // rdx
  hkpRigidBody *v4; // rdx
  UFG::WaterFloatingTrackerComponent *v5; // rcx

  v1 = this;
  if ( this->mCollisionMeshBundle.mData )
  {
    v2 = UFG::BasePhysicsSystem::mInstance;
    v3 = this->mRigidBody->mBody;
    if ( !v3->m_world )
      UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, v3, 1);
    v4 = v1->mBulletCollider;
    if ( !v4->m_world )
      UFG::BasePhysicsSystem::AddEntity(v2, v4, 1);
    v5 = v1->mWaterFloatingTrackerComponent;
    if ( v5 )
      ((void (*)(void))v5->vfptr[9].__vecDelDtor)();
  }
}

// File Line: 609
// RVA: 0x46B500
__int64 __fastcall UFG::PhysicsVehicle::IsSuspended(UFG::PhysicsVehicle *this)
{
  return ~(unsigned __int8)(this->mRigidBody->mFlags >> 1) & 1;
}

// File Line: 616
// RVA: 0x473510
void __fastcall UFG::PhysicsVehicle::Reset(UFG::PhysicsVehicle *this, UFG::VehicleResetOptions options)
{
  UFG::PhysicsVehicle *v2; // rbx
  __m128 v3; // xmm9
  __m128 v4; // xmm0
  __m128 v5; // xmm7
  float v6; // xmm12_4
  __m128 v7; // xmm6
  float v8; // xmm13_4
  float v9; // xmm5_4
  float v10; // xmm14_4
  __m128 v11; // xmm4
  float v12; // xmm1_4
  float v13; // xmm7_4
  float v14; // xmm5_4
  float v15; // xmm4_4
  __m128 v16; // xmm8
  float v17; // xmm9_4
  __m128 v18; // xmm10
  float v19; // xmm2_4
  UFG::BasePhysicsObjectVtbl *v20; // rax
  UFG::RigidBody *v21; // rcx
  float v22; // [rsp+20h] [rbp-D8h]
  float v23; // [rsp+24h] [rbp-D4h]
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

  v2 = this;
  if ( options )
  {
    if ( options == 1 )
    {
      v3 = (__m128)LODWORD(this->mBodyTransform.v0.z);
      v22 = this->mBodyTransform.v0.x;
      v24 = v3.m128_i32[0];
      v4 = v3;
      v5 = (__m128)LODWORD(v22);
      v23 = this->mBodyTransform.v0.y;
      v4.m128_f32[0] = v3.m128_f32[0] * 0.0;
      v5.m128_f32[0] = v22 - (float)(v3.m128_f32[0] * 0.0);
      v7 = v4;
      v6 = this->mBodyTransform.v3.x;
      v7.m128_f32[0] = (float)(v3.m128_f32[0] * 0.0) - v23;
      v11 = v5;
      v8 = this->mBodyTransform.v3.y;
      v9 = (float)(v23 * 0.0) - (float)(v22 * 0.0);
      v10 = this->mBodyTransform.v3.z;
      v11.m128_f32[0] = (float)((float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(v7.m128_f32[0] * v7.m128_f32[0]))
                      + (float)(v9 * v9);
      if ( v11.m128_f32[0] == 0.0 )
        v12 = 0.0;
      else
        v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
      v13 = v5.m128_f32[0] * v12;
      v14 = v9 * v12;
      v7.m128_f32[0] = v7.m128_f32[0] * v12;
      v16 = v7;
      v15 = (float)(v14 * v23) - (float)(v13 * v3.m128_f32[0]);
      v16.m128_f32[0] = (float)(v7.m128_f32[0] * v3.m128_f32[0]) - (float)(v14 * v22);
      v18 = v16;
      v17 = (float)(v13 * v22) - (float)(v7.m128_f32[0] * v23);
      v18.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v15 * v15)) + (float)(v17 * v17);
      if ( v18.m128_f32[0] == 0.0 )
        v19 = 0.0;
      else
        v19 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v18));
      v20 = this->vfptr;
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
      v36 = v10;
      v37 = 1065353216;
      v32 = v17 * v19;
      ((void (__fastcall *)(UFG::PhysicsVehicle *, float *))v20[3].DebugDraw)(this, &v22);
    }
  }
  else
  {
    ((void (__fastcall *)(UFG::PhysicsVehicle *, UFG::qMatrix44 *))this->vfptr[3].DebugDraw)(
      this,
      &this->mLastGoodPosition);
  }
  v21 = (UFG::RigidBody *)&v2->mRigidBody->vfptr;
  v2->mSpeedKPH = 0.0;
  UFG::RigidBody::SetVelocity(v21, &UFG::qVector3::msZero);
  UFG::RigidBody::SetAngularVelocity((UFG::RigidBody *)&v2->mRigidBody->vfptr, &UFG::qVector3::msZero);
}

// File Line: 657
// RVA: 0x47AE40
void __fastcall UFG::PhysicsVehicle::Update(UFG::PhysicsVehicle *this, UFG::qMatrix44 *targetTransform, UFG::VehicleInput *driverInput, float deltaTime)
{
  UFG::qMatrix44 *v4; // rsi
  UFG::PhysicsVehicle *v5; // rbx
  hkpRigidBody *v6; // rdi
  int v7; // eax
  float v8; // xmm7_4
  float v9; // xmm6_4
  float v10; // xmm8_4
  signed int v11; // eax
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  UFG::qVector3 result; // [rsp+20h] [rbp-48h]

  v4 = targetTransform;
  v5 = this;
  v6 = this->mRigidBody->mBody;
  if ( !v6 )
  {
    UFG::qPrintf("PhysicsVehicle %x is missing its rigid body\n", this, driverInput);
    return;
  }
  v7 = *((_DWORD *)driverInput + 4);
  if ( _bittest(&v7, 9u) || _bittest(&v7, 0xAu) || this->mIsProxy )
  {
    if ( hkpRigidBody::isDeactivationEnabled(v6) )
    {
      hkpRigidBody::enableDeactivation(v6, 0);
      hkpEntity::activate((hkpEntity *)&v6->vfptr);
    }
  }
  else if ( !hkpRigidBody::isDeactivationEnabled(v6) )
  {
    hkpRigidBody::enableDeactivation(v6, 1);
  }
  v8 = v5->mBodyTransform.v0.x;
  v9 = v5->mBodyTransform.v0.y;
  v10 = v5->mBodyTransform.v0.z;
  UFG::RigidBody::GetVelocity((UFG::RigidBody *)&v5->mRigidBody->vfptr, &result);
  v11 = v5->mCurrentLod;
  v5->mSpeedKPH = (float)((float)((float)(result.y * v9) + (float)(result.x * v8)) + (float)(result.z * v10))
                * 3.5999999;
  if ( v11 > 0 )
  {
    if ( v11 > 2 )
    {
      if ( v11 == 3 )
      {
        v12 = v5->mBodyTransform.v1;
        v13 = v5->mBodyTransform.v2;
        v14 = v5->mBodyTransform.v3;
        v15 = v5->mBodyTransform.v0;
        goto LABEL_15;
      }
      if ( v11 != 4 )
        return;
    }
    v12 = v4->v1;
    v13 = v4->v2;
    v14 = v4->v3;
    v15 = v4->v0;
LABEL_15:
    v5->mTargetTransform.v0 = v15;
    v5->mTargetTransform.v1 = v12;
    v5->mTargetTransform.v2 = v13;
    v5->mTargetTransform.v3 = v14;
  }
}

// File Line: 747
// RVA: 0x461FB0
void __fastcall UFG::PhysicsVehicle::DoKeyframes(UFG::PhysicsVehicle *this, float deltaTime)
{
  UFG::PhysicsVehicle *v2; // rbx
  UFG::PhysicsVehicle::Lod v3; // ecx
  float v4; // xmm2_4
  hkVector4f nextPosition; // [rsp+20h] [rbp-A8h]
  hkQuaternionf nextOrientation; // [rsp+30h] [rbp-98h]
  hkQsTransformf v7; // [rsp+40h] [rbp-88h]
  hkTransformf transform; // [rsp+70h] [rbp-58h]

  v2 = this;
  v3 = this->mCurrentLod;
  if ( !((v3 - 1) & 0xFFFFFFFC) && v3 != 3 && v2->mRigidBody->mBody && !v2->mIsProxy )
  {
    hkTransformf::set4x4ColumnMajor(&transform, &v2->mTargetTransform.v0.x);
    hkQsTransformf::setFromTransformNoScale(&v7, &transform);
    nextPosition.m_quad = (__m128)v7.m_translation;
    nextOrientation.m_vec.m_quad = (__m128)v7.m_rotation;
    if ( deltaTime <= 0.0005 )
      v4 = FLOAT_2000_0;
    else
      v4 = 1.0 / deltaTime;
    hkpKeyFrameUtility::applyHardKeyFrame(&nextPosition, &nextOrientation, v4, v2->mRigidBody->mBody);
  }
}

// File Line: 779
// RVA: 0x471F50
void __fastcall UFG::PhysicsWheeledVehicle::QueueAsyncQueryForGroundFixup(UFG::PhysicsWheeledVehicle *this, bool useLongRaysToFindGround, bool hasDriver, bool isMoving)
{
  UFG::PhysicsVehicle::Lod v4; // eax
  bool v5; // si
  bool v6; // di
  bool v7; // bp
  UFG::PhysicsWheeledVehicle *v8; // rbx
  hkpRigidBody *v9; // rcx
  __m128 v10; // xmm3
  float v11; // xmm0_4
  float v12; // eax
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  UFG::BasePhysicsSystem *v16; // rdi
  UFG::SimComponent *v17; // r14
  float v18; // xmm11_4
  float v19; // xmm11_4
  unsigned int v20; // eax
  __int64 v21; // rbp
  float *v22; // r15
  float v23; // xmm7_4
  float v24; // xmm6_4
  float v25; // xmm8_4
  float v26; // xmm2_4
  float v27; // xmm9_4
  float v28; // xmm3_4
  UFG::BasePhysicsSystemVtbl *v29; // rax
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // xmm9_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm3_4
  UFG::BasePhysicsSystemVtbl *v36; // rax
  float v37; // [rsp+40h] [rbp-A8h]
  float v38; // [rsp+44h] [rbp-A4h]
  float v39; // [rsp+48h] [rbp-A0h]
  float v40; // [rsp+50h] [rbp-98h]
  float v41; // [rsp+54h] [rbp-94h]
  float v42; // [rsp+58h] [rbp-90h]
  hkBool result; // [rsp+F0h] [rbp+8h]

  v4 = this->mCurrentLod;
  *((_DWORD *)this + 274) &= 0xFFFFFFF8;
  v5 = isMoving;
  v6 = hasDriver;
  v7 = useLongRaysToFindGround;
  v8 = this;
  if ( (unsigned int)(v4 - 3) <= 1 || this->mBodyTransform.v2.z < 0.2 )
    return;
  v9 = this->mRigidBody->mBody;
  if ( !v9 || hkpEntity::isActive((hkpEntity *)&v9->vfptr, &result)->m_bool )
  {
    if ( !v6 )
      goto LABEL_9;
  }
  else if ( !v6 )
  {
    return;
  }
  if ( !v5 )
  {
LABEL_9:
    v10 = (__m128)LODWORD(v8->mLastFixupPosition.y);
    v11 = v8->mLastFixupPosition.z - v8->mTargetTransform.v3.z;
    v10.m128_f32[0] = (float)((float)((float)((float)(v10.m128_f32[0] - v8->mTargetTransform.v3.y)
                                            * (float)(v10.m128_f32[0] - v8->mTargetTransform.v3.y))
                                    + (float)((float)(v8->mLastFixupPosition.x - v8->mTargetTransform.v3.x)
                                            * (float)(v8->mLastFixupPosition.x - v8->mTargetTransform.v3.x)))
                            + (float)(v11 * v11))
                    + (float)((float)(v8->mLastFixupPosition.w - v8->mTargetTransform.v3.w)
                            * (float)(v8->mLastFixupPosition.w - v8->mTargetTransform.v3.w));
    if ( COERCE_FLOAT(_mm_sqrt_ps(v10)) <= 0.001 )
      return;
  }
  v12 = v8->mTargetTransform.v3.x;
  v13 = v8->mTargetTransform.v3.y;
  v14 = v8->mTargetTransform.v3.z;
  v15 = v8->mTargetTransform.v3.w;
  v8->mLastFixupPosition.y = v13;
  v8->mLastFixupPosition.z = v14;
  v8->mLastFixupPosition.x = v12;
  v8->mLastFixupPosition.w = v15;
  if ( v8 != (UFG::PhysicsWheeledVehicle *)-8i64 )
  {
    v16 = UFG::BasePhysicsSystem::mInstance;
    v17 = v8->mUserData.simComponent.m_pPointer;
    if ( v7 )
      v18 = FLOAT_2_0;
    else
      v18 = 0.0;
    v19 = v18 + 2.0;
    if ( v8->mCurrentLod != 2 || (v20 = *((_DWORD *)&v8->0 + 151) & 7, v20 <= 2) )
    {
      v35 = v8->mTargetTransform.v3.x;
      v36 = UFG::BasePhysicsSystem::mInstance->vfptr;
      v38 = v13;
      v42 = v14 - 4.0;
      v37 = v35;
      v39 = v14 + 2.0;
      v40 = v35;
      v41 = v13;
      v36->CastAsyncRay(
        UFG::BasePhysicsSystem::mInstance,
        (UFG::qVector3 *)&v37,
        (UFG::qVector3 *)&v40,
        17u,
        UFG::PhysicsWheeledVehicle::ApplyGroundFixup,
        v17,
        (void *)-1i64);
    }
    else
    {
      v21 = 0i64;
      if ( v20 )
      {
        v22 = v8->mRestingSuspensionLength.array;
        do
        {
          v23 = v8->mBodyTransform.v2.y;
          v24 = v8->mBodyTransform.v2.x;
          v25 = v8->mBodyTransform.v2.z;
          v26 = *((float *)&v8->vfptr + 4 * (v21 + 42));
          v27 = *((float *)&v8->vfptr + 4 * (v21 + 42) + 1);
          v28 = *((float *)&v8->mUserData.isBoat + 4 * (v21 + 42));
          v29 = v16->vfptr;
          v30 = (float)((float)((float)(*((float *)&v8->vfptr + 4 * (v21 + 42) + 1) * v8->mTargetTransform.v1.x)
                              + (float)(*((float *)&v8->vfptr + 4 * (v21 + 42)) * v8->mTargetTransform.v0.x))
                      + (float)(*((float *)&v8->mUserData.isBoat + 4 * (v21 + 42)) * v8->mTargetTransform.v2.x))
              + v8->mTargetTransform.v3.x;
          v31 = (float)((float)((float)(v26 * v8->mTargetTransform.v0.y) + (float)(v27 * v8->mTargetTransform.v1.y))
                      + (float)(v28 * v8->mTargetTransform.v2.y))
              + v8->mTargetTransform.v3.y;
          v32 = (float)((float)((float)((float)(v27 * v8->mTargetTransform.v1.z)
                                      + (float)(v26 * v8->mTargetTransform.v0.z))
                              + (float)(v28 * v8->mTargetTransform.v2.z))
                      + v8->mTargetTransform.v3.z)
              + (float)(v25 * 2.0);
          v33 = *v22 + v8->mWheelRadius;
          v41 = v31 + (float)(v23 * 2.0);
          v40 = (float)(v24 * 2.0) + v30;
          v42 = v32;
          LODWORD(v34) = COERCE_UNSIGNED_INT(v33 + v19) ^ _xmm[0];
          v37 = v40 + (float)(v24 * v34);
          v38 = v41 + (float)(v23 * v34);
          v39 = v32 + (float)(v25 * v34);
          v29->CastAsyncRay(
            v16,
            (UFG::qVector3 *)&v40,
            (UFG::qVector3 *)&v37,
            17u,
            UFG::PhysicsWheeledVehicle::ApplyGroundFixup,
            v17,
            (void *)(unsigned int)v21);
          v21 = (unsigned int)(v21 + 1);
          ++v22;
        }
        while ( (unsigned int)v21 < (*((_DWORD *)&v8->0 + 151) & 7u) );
      }
    }
  }
}

// File Line: 873
// RVA: 0x457230
void __fastcall UFG::PhysicsWheeledVehicle::ApplyGroundFixup(UFG::RayCastData *data, UFG::SimComponent *simComponent, void *callbackUserData)
{
  UFG::RayCastData *v3; // rbx
  UFG::SimComponent *v4; // rdi
  signed int v5; // esi
  int v6; // er14
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // r8
  bool v9; // al
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm8_4
  float v17; // xmm12_4
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
  signed __int64 v45; // rdx
  int v46; // er9
  signed int v47; // edx
  float v48; // xmm15_4
  __m128 v49; // xmm2
  int v50; // xmm14_4
  __int64 v51; // rax
  signed __int64 v52; // rcx
  float v53; // xmm9_4
  float v54; // xmm4_4
  __int64 v55; // rax
  signed __int64 v56; // rcx
  __int64 v57; // rax
  signed __int64 v58; // rcx
  float v59; // xmm0_4
  float v60; // xmm9_4
  float v61; // xmm3_4
  float v62; // xmm4_4
  __m128 v63; // xmm11
  float v64; // xmm3_4
  float v65; // xmm12_4
  float v66; // xmm5_4
  __m128 v67; // xmm6
  float v68; // xmm4_4
  __m128 v69; // xmm10
  float v70; // xmm1_4
  float v71; // xmm5_4
  float v72; // xmm6_4
  float v73; // xmm4_4
  float v74; // xmm10_4
  float v75; // xmm3_4
  __m128 v76; // xmm2
  float v77; // xmm1_4
  float v78; // xmm3_4
  __m128 v79; // xmm10
  float v80; // xmm12_4
  __m128 v81; // xmm2
  float v82; // xmm1_4
  float v83; // xmm2_4
  float v84; // xmm7_4
  __m128 v85; // xmm3
  __m128 v86; // xmm9
  float v87; // xmm1_4
  float v88; // xmm7_4
  float v89; // xmm8_4
  float v90; // xmm9_4
  signed __int64 v91; // r9
  float v92; // xmm2_4
  float *v93; // rax
  unsigned __int64 v94; // rcx
  signed __int64 v95; // rdx
  float *v96; // rcx
  float v97; // xmm8_4
  float v98; // xmm0_4
  float v99; // xmm8_4
  float v100; // xmm9_4
  __m128 v101; // xmm10
  float v102; // xmm9_4
  __m128 v103; // xmm3
  float v104; // xmm2_4
  float v105; // xmm12_4
  float v106; // xmm11_4
  float v107; // xmm2_4
  float v108; // xmm12_4
  float v109; // xmm11_4
  float v110; // xmm8_4
  float v111; // xmm9_4
  float v112; // xmm10_4
  float v113; // xmm3_4
  float v114; // xmm13_4
  float v115; // xmm7_4
  float v116; // xmm3_4
  __m128 v117; // xmm5
  float v118; // xmm6_4
  __m128 v119; // xmm2
  __m128 v120; // xmm4
  float v121; // xmm13_4
  __m128 v122; // xmm12
  float v123; // xmm13_4
  float v124; // xmm5_4
  __m128 v125; // xmm6
  float v126; // xmm7_4
  __m128 v127; // xmm2
  float v128; // xmm1_4
  float v129; // xmm7_4
  float v130; // xmm6_4
  float v131; // xmm5_4
  float v132; // xmm9_4
  __m128 v133; // xmm10
  float v134; // xmm3_4
  __m128 v135; // xmm2
  float v136; // xmm8_4
  float v137; // xmm0_4
  float v138; // xmm2_4
  float v139; // xmm1_4
  float v140; // xmm3_4
  float v141; // xmm9_4
  float v142; // xmm10_4
  float v143; // [rsp+20h] [rbp-E0h]
  float v144; // [rsp+28h] [rbp-D8h]
  unsigned int v145; // [rsp+2Ch] [rbp-D4h]
  int v146; // [rsp+30h] [rbp-D0h]
  float v147; // [rsp+34h] [rbp-CCh]
  float v148; // [rsp+38h] [rbp-C8h]
  float v149; // [rsp+3Ch] [rbp-C4h]
  float v150; // [rsp+40h] [rbp-C0h]
  float v151; // [rsp+44h] [rbp-BCh]
  float v152; // [rsp+48h] [rbp-B8h]
  float v153; // [rsp+4Ch] [rbp-B4h]
  float v154; // [rsp+50h] [rbp-B0h]
  float v155; // [rsp+54h] [rbp-ACh]
  float v156; // [rsp+58h] [rbp-A8h]
  float v157; // [rsp+5Ch] [rbp-A4h]
  float v158; // [rsp+60h] [rbp-A0h]
  float v159; // [rsp+64h] [rbp-9Ch]
  float v160; // [rsp+68h] [rbp-98h]
  float v161; // [rsp+6Ch] [rbp-94h]
  float v162; // [rsp+70h] [rbp-90h]
  float v163; // [rsp+74h] [rbp-8Ch]
  float v164; // [rsp+78h] [rbp-88h]
  float v165; // [rsp+7Ch] [rbp-84h]
  float v166; // [rsp+80h] [rbp-80h]
  float v167; // [rsp+84h] [rbp-7Ch]
  float v168; // [rsp+88h] [rbp-78h]
  float v169; // [rsp+8Ch] [rbp-74h]
  float v170; // [rsp+90h] [rbp-70h]
  float v171; // [rsp+94h] [rbp-6Ch]
  float v172; // [rsp+98h] [rbp-68h]
  float v173; // [rsp+9Ch] [rbp-64h]
  float v174; // [rsp+A0h] [rbp-60h]
  float v175; // [rsp+A4h] [rbp-5Ch]
  float v176; // [rsp+178h] [rbp+78h]
  float v177; // [rsp+188h] [rbp+88h]

  if ( simComponent )
  {
    v3 = data;
    v4 = simComponent;
    v5 = 1;
    v6 = (signed int)callbackUserData;
    Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    v7 = v4[10].m_SafePointerList.mNode.mPrev;
    if ( v7 )
    {
      v8 = 0i64;
      if ( BYTE4(v7[37].mNext) & 7 )
        v8 = v4[10].m_SafePointerList.mNode.mPrev;
      if ( v8 && (unsigned int)(HIDWORD(v8[34].mPrev) - 1) <= 1 )
      {
        LODWORD(v8[68].mNext) ^= ((unsigned __int8)LODWORD(v8[68].mNext) ^ (unsigned __int8)(LODWORD(v8[68].mNext) + 1)) & 7;
        v9 = v3->hit;
        if ( v6 == -1 )
        {
          LOBYTE(v8[58].mPrev) = v9;
          v10 = v3->point.y;
          v11 = v3->point.z;
          *(float *)&v8[55].mPrev = v3->point.x;
          *((float *)&v8[55].mPrev + 1) = v10;
          *(float *)&v8[55].mNext = v11;
          if ( v3->hit && v3->normal.z >= 0.69999999 )
          {
            v12 = *((float *)&v8[24].mPrev + 1);
            v13 = *(float *)&v8[24].mNext;
            v14 = *(float *)&v8[24].mPrev;
            v15 = v3->normal.y;
            v16 = v3->normal.z;
            v17 = v3->normal.x;
            v19 = (__m128)LODWORD(v3->normal.z);
            v18 = (float)(v3->normal.y * v13) - (float)(v3->normal.z * v12);
            v19.m128_f32[0] = (float)(v19.m128_f32[0] * v14) - (float)(v13 * v17);
            v20 = (float)(v12 * v17) - (float)(v3->normal.y * v14);
            v21 = v19;
            v21.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v18 * v18))
                            + (float)(v20 * v20);
            if ( v21.m128_f32[0] == 0.0 )
            {
              v23 = 0i64;
            }
            else
            {
              LODWORD(v22) = (unsigned __int128)_mm_sqrt_ps(v21);
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
            v29 = (float)(v15 * v27) - (float)(v26 * v17);
            v30.m128_f32[0] = (float)(v23.m128_f32[0] * v17) - (float)(v16 * v27);
            v31 = v30;
            v31.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v28 * v28))
                            + (float)(v29 * v29);
            if ( v31.m128_f32[0] == 0.0 )
              v32 = 0.0;
            else
              v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
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
            v37 = v3->normal.x;
            v38 = v3->normal.y;
            v39 = v3->normal.z;
            HIDWORD(v8[26].mNext) = 0;
            *(float *)&v8[26].mPrev = v37;
            *((float *)&v8[26].mPrev + 1) = v38;
            *(float *)&v8[26].mNext = v39;
            v40 = v3->point.z;
            v41 = v3->point.x;
            v42 = v3->point.y;
            HIDWORD(v8[27].mNext) = 1065353216;
            *(float *)&v8[27].mPrev = v41;
            *((float *)&v8[27].mPrev + 1) = v42;
            *(float *)&v8[27].mNext = (float)(v36 * 0.5) + v40;
          }
        }
        else
        {
          *((_BYTE *)&v8[58].mPrev + v6) = v9;
          v43 = v3->point.y;
          v44 = v3->point.z;
          v45 = 3i64 * v6;
          *((_DWORD *)&v8[55].mPrev + v45) = LODWORD(v3->point.x);
          *((float *)&v8[55].mPrev + v45 + 1) = v43;
          *((float *)&v8[55].mNext + v45) = v44;
          v46 = HIDWORD(v8[37].mNext) & 7;
          if ( ((_QWORD)v8[68].mNext & 7) == v46 )
          {
            v47 = 0;
            if ( LOBYTE(v8[58].mPrev) )
            {
              v48 = *(float *)&v8[55].mPrev;
              v49 = (__m128)HIDWORD(v8[55].mPrev);
              v50 = (int)v8[55].mNext;
              v47 = 1;
              v144 = *(float *)&v8[55].mPrev;
              v145 = v49.m128_u32[0];
              v146 = v50;
            }
            else
            {
              v50 = v146;
              v49 = (__m128)v145;
              v48 = v144;
            }
            v176 = v49.m128_f32[0];
            if ( BYTE1(v8[58].mPrev) )
            {
              v51 = v47++;
              v52 = 3 * v51;
              *(&v144 + v52) = *((float *)&v8[55].mNext + 1);
              *(&v145 + v52) = (unsigned int)v8[56].mPrev;
              *(&v146 + v52) = HIDWORD(v8[56].mPrev);
              v49 = (__m128)v145;
              v50 = v146;
              v48 = v144;
              v176 = *(float *)&v145;
            }
            v53 = *(float *)&v8[68].mPrev;
            v54 = *((float *)&v8[68].mPrev + 1);
            v158 = (float)((float)(*(float *)&v8[SLODWORD(v8[3].mPrev[4].mNext) + 42i64].mPrev
                                 / (float)(*(float *)&v8[SLODWORD(v8[3].mPrev[4].mNext) + 42i64].mPrev
                                         - *(float *)&v8[SLODWORD(v8[3].mPrev[5].mPrev) + 42i64].mPrev))
                         * (float)(v54 - v53))
                 + v53;
            if ( v46 == 4 )
            {
              if ( BYTE3(v8[58].mPrev) )
              {
                v55 = v47++;
                v56 = 3 * v55;
                *(&v144 + v56) = *((float *)&v8[57].mPrev + 1);
                *(&v145 + v56) = (unsigned int)v8[57].mNext;
                *(&v146 + v56) = HIDWORD(v8[57].mNext);
                v49.m128_i32[0] = v145;
                v50 = v146;
                v48 = v144;
                v176 = *(float *)&v145;
              }
              if ( BYTE2(v8[58].mPrev) )
              {
                v57 = v47++;
                v58 = 3 * v57;
                *(&v144 + v58) = *(float *)&v8[56].mNext;
                *(&v145 + v58) = HIDWORD(v8[56].mNext);
                *(&v146 + v58) = (int)v8[57].mPrev;
                v49.m128_i32[0] = v145;
                v50 = v146;
                v48 = v144;
                v176 = *(float *)&v145;
              }
              if ( v47 > 2 )
              {
                v63 = (__m128)LODWORD(v147);
                v59 = *(float *)&v50 + v53;
                v60 = v53 + v149;
                v61 = v152 + v54;
                v156 = v155 + v54;
                v62 = (float)(v152 + v54) - v59;
                v63.m128_f32[0] = v147 - v48;
                v161 = v61;
                v67 = v63;
                v157 = v62;
                v64 = v148 - v49.m128_f32[0];
                v65 = v151 - v49.m128_f32[0];
                v177 = v60 - v59;
                v162 = v150 - v48;
                v66 = (float)((float)(v60 - v59) * (float)(v151 - v49.m128_f32[0]))
                    - (float)((float)(v148 - v49.m128_f32[0]) * v62);
                v160 = v147 - v48;
                v67.m128_f32[0] = (float)((float)(v147 - v48) * v62) - (float)((float)(v60 - v59) * (float)(v150 - v48));
                v69 = v67;
                v68 = (float)((float)(v148 - v49.m128_f32[0]) * (float)(v150 - v48))
                    - (float)((float)(v147 - v48) * (float)(v151 - v49.m128_f32[0]));
                v69.m128_f32[0] = (float)((float)(v67.m128_f32[0] * v67.m128_f32[0]) + (float)(v66 * v66))
                                + (float)(v68 * v68);
                if ( v69.m128_f32[0] == 0.0 )
                  v70 = 0.0;
                else
                  v70 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v69));
                v71 = v66 * v70;
                v72 = v67.m128_f32[0] * v70;
                v73 = v68 * v70;
                v164 = v71;
                v165 = v72;
                v166 = v73;
                if ( v47 == 4 )
                {
                  v159 = v154 - v49.m128_f32[0];
                  v163 = v153 - v48;
                  v74 = (float)(v177 * (float)(v154 - v49.m128_f32[0])) - (float)(v64 * (float)(v156 - v59));
                  v143 = v156 - v59;
                  v63.m128_f32[0] = (float)(v63.m128_f32[0] * (float)(v156 - v59)) - (float)(v177 * (float)(v153 - v48));
                  v76 = v63;
                  v75 = (float)(v64 * (float)(v153 - v48)) - (float)(v160 * v159);
                  v76.m128_f32[0] = (float)((float)(v63.m128_f32[0] * v63.m128_f32[0]) + (float)(v74 * v74))
                                  + (float)(v75 * v75);
                  if ( v76.m128_f32[0] == 0.0 )
                    v77 = 0.0;
                  else
                    v77 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v76));
                  v169 = v75 * v77;
                  v167 = v74 * v77;
                  v78 = (float)(v157 * v159) - (float)(v65 * v143);
                  v168 = v63.m128_f32[0] * v77;
                  v79 = (__m128)LODWORD(v162);
                  v79.m128_f32[0] = (float)(v162 * v143) - (float)(v157 * v163);
                  v80 = (float)(v65 * v163) - (float)(v162 * v159);
                  v81 = v79;
                  v81.m128_f32[0] = (float)((float)(v79.m128_f32[0] * v79.m128_f32[0]) + (float)(v78 * v78))
                                  + (float)(v80 * v80);
                  if ( v81.m128_f32[0] == 0.0 )
                    v82 = 0.0;
                  else
                    v82 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v81));
                  v5 = 4;
                  v171 = v79.m128_f32[0] * v82;
                  v170 = v78 * v82;
                  v172 = v80 * v82;
                  v83 = (float)((float)(v161 - v60) * (float)(v154 - v148))
                      - (float)((float)(v151 - v148) * (float)(v156 - v60));
                  v85 = (__m128)COERCE_UNSIGNED_INT(v150 - v147);
                  v84 = (float)((float)(v151 - v148) * (float)(v153 - v147))
                      - (float)(v85.m128_f32[0] * (float)(v154 - v148));
                  v85.m128_f32[0] = (float)(v85.m128_f32[0] * (float)(v156 - v60))
                                  - (float)((float)(v161 - v60) * (float)(v153 - v147));
                  v86 = v85;
                  v86.m128_f32[0] = (float)((float)(v85.m128_f32[0] * v85.m128_f32[0]) + (float)(v83 * v83))
                                  + (float)(v84 * v84);
                  if ( v86.m128_f32[0] == 0.0 )
                    v87 = 0.0;
                  else
                    v87 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v86));
                  v173 = v83 * v87;
                  v174 = v85.m128_f32[0] * v87;
                  v175 = v84 * v87;
                }
                v88 = *(float *)&v8[26].mPrev;
                v89 = *((float *)&v8[26].mPrev + 1);
                v90 = *(float *)&v8[26].mNext;
                v91 = 0i64;
                v92 = (float)((float)(*((float *)&v8[26].mPrev + 1) * v72) + (float)(*(float *)&v8[26].mPrev * v71))
                    + (float)(v73 * v90);
                if ( v5 >= 4i64 )
                {
                  v93 = &v166;
                  v94 = ((unsigned __int64)(v5 - 4i64) >> 2) + 1;
                  v91 = 4 * v94;
                  do
                  {
                    if ( (float)((float)((float)(*(v93 - 2) * v88) + (float)(*(v93 - 1) * v89)) + (float)(*v93 * v90)) > v92 )
                    {
                      v71 = *(v93 - 2);
                      v72 = *(v93 - 1);
                      v73 = *v93;
                      v92 = (float)((float)(*(v93 - 2) * v88) + (float)(*(v93 - 1) * v89)) + (float)(*v93 * v90);
                    }
                    if ( (float)((float)((float)(v93[1] * v88) + (float)(v93[2] * v89)) + (float)(v93[3] * v90)) > v92 )
                    {
                      v71 = v93[1];
                      v72 = v93[2];
                      v73 = v93[3];
                      v92 = (float)((float)(v93[1] * v88) + (float)(v93[2] * v89)) + (float)(v93[3] * v90);
                    }
                    if ( (float)((float)((float)(v93[4] * v88) + (float)(v93[5] * v89)) + (float)(v93[6] * v90)) > v92 )
                    {
                      v71 = v93[4];
                      v72 = v93[5];
                      v73 = v93[6];
                      v92 = (float)((float)(v93[4] * v88) + (float)(v93[5] * v89)) + (float)(v93[6] * v90);
                    }
                    if ( (float)((float)((float)(v93[7] * v88) + (float)(v93[8] * v89)) + (float)(v93[9] * v90)) > v92 )
                    {
                      v71 = v93[7];
                      v72 = v93[8];
                      v73 = v93[9];
                      v92 = (float)((float)(v93[7] * v88) + (float)(v93[8] * v89)) + (float)(v93[9] * v90);
                    }
                    v93 += 12;
                    --v94;
                  }
                  while ( v94 );
                }
                if ( v91 < v5 )
                {
                  v95 = v5 - v91;
                  v96 = &v166 + 3 * v91;
                  do
                  {
                    if ( (float)((float)((float)(*(v96 - 2) * v88) + (float)(*(v96 - 1) * v89)) + (float)(*v96 * v90)) > v92 )
                    {
                      v71 = *(v96 - 2);
                      v72 = *(v96 - 1);
                      v73 = *v96;
                      v92 = (float)((float)(*(v96 - 2) * v88) + (float)(*(v96 - 1) * v89)) + (float)(*v96 * v90);
                    }
                    v96 += 3;
                    --v95;
                  }
                  while ( v95 );
                }
                v97 = *((float *)&v8[24].mPrev + 1);
                v101 = (__m128)LODWORD(v8[24].mPrev);
                v98 = v97;
                v99 = (float)(v97 * v71) - (float)(v101.m128_f32[0] * v72);
                v100 = *(float *)&v8[24].mNext;
                v101.m128_f32[0] = (float)(v101.m128_f32[0] * v73) - (float)(v100 * v71);
                v102 = (float)(v100 * v72) - (float)(v98 * v73);
                v103 = v101;
                v103.m128_f32[0] = (float)((float)(v101.m128_f32[0] * v101.m128_f32[0]) + (float)(v102 * v102))
                                 + (float)(v99 * v99);
                if ( v103.m128_f32[0] == 0.0 )
                  v104 = 0.0;
                else
                  v104 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v103));
                v105 = v104;
                v106 = v104;
                v107 = v104 * v99;
                v108 = v105 * v101.m128_f32[0];
                v109 = v106 * v102;
                v110 = (float)(v108 * v73) - (float)(v107 * v72);
                v111 = (float)(v107 * v71) - (float)(v109 * v73);
                v112 = (float)(v109 * v72) - (float)(v108 * v71);
                v113 = (float)((float)(v111 * v111) + (float)(v110 * v110)) + (float)(v112 * v112);
                if ( v113 == 0.0 )
                  v114 = 0.0;
                else
                  v114 = 1.0 / fsqrt(v113);
                v115 = (float)((float)((float)(*(float *)&v8[27].mNext - *(float *)&v50)
                                     - (float)((float)((float)((float)((float)(*((float *)&v8[27].mPrev + 1) - v176)
                                                                     * v72)
                                                             + (float)((float)(*(float *)&v8[27].mPrev - v48) * v71))
                                                     + (float)((float)(*(float *)&v8[27].mNext - *(float *)&v50) * v73))
                                             * v73))
                             + *(float *)&v50)
                     + v158;
                *(float *)&v8[24].mPrev = v114 * v110;
                *((float *)&v8[24].mPrev + 1) = v114 * v111;
                *(float *)&v8[24].mNext = v114 * v112;
                HIDWORD(v8[24].mNext) = 0;
                HIDWORD(v8[25].mNext) = 0;
                *(float *)&v8[25].mPrev = v109;
                *((float *)&v8[25].mPrev + 1) = v108;
                *(float *)&v8[25].mNext = v107;
                HIDWORD(v8[26].mNext) = 0;
                *(float *)&v8[26].mPrev = v71;
                *((float *)&v8[26].mPrev + 1) = v72;
                *(float *)&v8[26].mNext = v73;
                *(float *)&v8[27].mNext = v115;
              }
            }
            else if ( v46 == 2 && v47 == 2 )
            {
              v117 = v49;
              v116 = v48 - v147;
              v117.m128_f32[0] = v49.m128_f32[0] - v148;
              v119 = v117;
              v118 = *(float *)&v50 - v149;
              v119.m128_f32[0] = (float)((float)(v117.m128_f32[0] * v117.m128_f32[0]) + (float)(v116 * v116))
                               + (float)(v118 * v118);
              if ( v119.m128_f32[0] == 0.0 )
              {
                v120 = 0i64;
              }
              else
              {
                v120 = (__m128)(unsigned int)FLOAT_1_0;
                v120.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v119));
              }
              v122 = v120;
              v121 = v120.m128_f32[0];
              v120.m128_f32[0] = v120.m128_f32[0] * v118;
              v122.m128_f32[0] = v122.m128_f32[0] * v116;
              v123 = v121 * v117.m128_f32[0];
              if ( v120.m128_f32[0] < 0.69999999 )
              {
                v125 = v122;
                v124 = (float)(v120.m128_f32[0] * UFG::qVector3::msAxisZ.y) - (float)(v123 * UFG::qVector3::msAxisZ.z);
                v125.m128_f32[0] = (float)(v122.m128_f32[0] * UFG::qVector3::msAxisZ.z)
                                 - (float)(v120.m128_f32[0] * UFG::qVector3::msAxisZ.x);
                v127 = v125;
                v126 = (float)(v123 * UFG::qVector3::msAxisZ.x) - (float)(v122.m128_f32[0] * UFG::qVector3::msAxisZ.y);
                v127.m128_f32[0] = (float)((float)(v125.m128_f32[0] * v125.m128_f32[0]) + (float)(v124 * v124))
                                 + (float)(v126 * v126);
                if ( v127.m128_f32[0] == 0.0 )
                  v128 = 0.0;
                else
                  v128 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v127));
                v129 = v126 * v128;
                v130 = v125.m128_f32[0] * v128;
                v131 = v124 * v128;
                v133 = v120;
                v132 = (float)(v129 * v123) - (float)(v120.m128_f32[0] * v130);
                v133.m128_f32[0] = (float)(v120.m128_f32[0] * v131) - (float)(v129 * v122.m128_f32[0]);
                v135 = v133;
                v134 = (float)(v130 * v122.m128_f32[0]) - (float)(v131 * v123);
                v135.m128_f32[0] = (float)((float)(v133.m128_f32[0] * v133.m128_f32[0]) + (float)(v132 * v132))
                                 + (float)(v134 * v134);
                if ( v135.m128_f32[0] == 0.0 )
                  v136 = 0.0;
                else
                  v136 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v135));
                v137 = *(float *)&v8[27].mPrev;
                v138 = *(float *)&v8[27].mNext;
                v139 = *((float *)&v8[27].mPrev + 1);
                HIDWORD(v8[24].mNext) = 0;
                v140 = v134 * v136;
                v141 = v132 * v136;
                v142 = v133.m128_f32[0] * v136;
                LODWORD(v8[24].mPrev) = v122.m128_i32[0];
                *((float *)&v8[24].mPrev + 1) = v123;
                LODWORD(v8[24].mNext) = v120.m128_i32[0];
                *(float *)&v8[25].mPrev = v131;
                HIDWORD(v8[25].mNext) = 0;
                *((float *)&v8[25].mPrev + 1) = v130;
                *(float *)&v8[25].mNext = v129;
                HIDWORD(v8[26].mNext) = 0;
                *(float *)&v8[26].mPrev = v141;
                *((float *)&v8[26].mPrev + 1) = v142;
                *(float *)&v8[26].mNext = v140;
                *(float *)&v8[27].mNext = (float)((float)((float)(v138 - *(float *)&v50)
                                                        - (float)((float)((float)((float)((float)(v139 - v176) * v142)
                                                                                + (float)((float)(v137 - v48) * v141))
                                                                        + (float)((float)(v138 - *(float *)&v50) * v140))
                                                                * v140))
                                                + *(float *)&v50)
                                        + v158;
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
void __fastcall UFG::PhysicsVehicle::ActivateVolume(UFG::PhysicsVehicle *this, const unsigned int volumePropertyKey, UFG::qVector3 *halfExtents, UFG::qMatrix44 *markerOffset, const float extendVolumeBy)
{
  unsigned int v5; // edi
  UFG::qMatrix44 *v6; // rbx
  UFG::qVector3 *v7; // rsi
  UFG::PhysicsVehicle *v8; // rbp
  UFG::qVector4 *v9; // rcx
  UFG::qVector4 v10; // xmm3
  UFG::qVector4 v11; // xmm2
  UFG::qVector4 v12; // xmm1
  UFG::SimComponent *v13; // rax
  UFG::SimObject *v14; // rcx
  UFG::AIOutlineComponent *v15; // rax
  UFG::AIOutlineComponent *v16; // rbx
  UFG::Event *v17; // rdx
  UFG::qVector3 max; // [rsp+20h] [rbp-78h]
  UFG::qVector3 min; // [rsp+30h] [rbp-68h]
  UFG::qMatrix44 result; // [rsp+40h] [rbp-58h]

  v5 = volumePropertyKey;
  v6 = markerOffset;
  v7 = halfExtents;
  v8 = this;
  UFG::PhysicsVehicle::DeactivateVolume(this);
  v9 = &v8->mVolumeOffset.v0;
  v10 = v6->v1;
  v11 = v6->v2;
  v12 = v6->v3;
  *v9 = v6->v0;
  v9[1] = v10;
  v9[2] = v11;
  v9[3] = v12;
  UFG::qMatrix44::operator*(&v8->mVolumeOffset, &result, &v8->mBodyTransform);
  v8->mVolumeRigidBody = (hkpRigidBody *)UFG::PhantomCallback::CreatePhantom(v7, &result, v5);
  if ( v8 != (UFG::PhysicsVehicle *)-8i64 )
  {
    v13 = v8->mUserData.simComponent.m_pPointer;
    if ( v13 )
    {
      v14 = v13->m_pSimObject;
      if ( v14 )
      {
        v15 = (UFG::AIOutlineComponent *)UFG::SimObject::GetComponentOfType(v14, UFG::AIOutlineComponent::_TypeUID);
        v16 = v15;
        if ( v15 )
        {
          UFG::AIOutlineComponent::GetLocalAABB(v15, &min, &max);
          min.x = min.x - (float)(extendVolumeBy * 0.5);
          min.y = min.y - (float)(extendVolumeBy * 0.5);
          max.x = max.x + (float)(extendVolumeBy * 0.5);
          max.y = max.y + (float)(extendVolumeBy * 0.5);
          UFG::AIOutlineComponent::SetLocalAABB(v16, &min, &max, eOutlineDimensionsDefinedBy_PropertySet);
          UFG::AIOutlineComponent::ForceUpdate(v16, v17);
        }
      }
    }
  }
}

// File Line: 1103
// RVA: 0x4602E0
void __fastcall UFG::PhysicsVehicle::DeactivateVolume(UFG::PhysicsVehicle *this)
{
  UFG::PhysicsVehicle *v1; // rbx
  hkpRigidBody *v2; // rcx
  signed __int64 v3; // rbx
  __int64 v4; // rbx
  UFG::SimObject *v5; // rbx
  UFG::AIOutlineComponent *v6; // rax
  UFG::AIOutlineComponent *v7; // rdi
  UFG::Event *v8; // rdx

  v1 = this;
  v2 = this->mVolumeRigidBody;
  if ( v2 )
  {
    UFG::PhantomCallback::DestroyPhantom(v2);
    v1->mVolumeRigidBody = 0i64;
    v3 = (signed __int64)&v1->mUserData;
    if ( v3 )
    {
      v4 = *(_QWORD *)(v3 + 24);
      if ( v4 )
      {
        v5 = *(UFG::SimObject **)(v4 + 40);
        if ( v5 )
        {
          v6 = (UFG::AIOutlineComponent *)UFG::SimObject::GetComponentOfType(v5, UFG::AIOutlineComponent::_TypeUID);
          v7 = v6;
          if ( v6 )
          {
            UFG::AIOutlineComponent::SetAABBFromPropertySet(v6, v5->m_pSceneObj);
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
  hkpRigidBody *v1; // rdx
  __m128 v2; // xmm4
  UFG::qVector4 v3; // xmm2
  __m128 v4; // xmm3
  UFG::qVector4 v5; // xmm0

  v1 = this->mRigidBody->mBody;
  if ( v1 )
  {
    v2 = v1->m_motion.m_motionState.m_transform.m_translation.m_quad;
    v3 = (UFG::qVector4)_mm_srli_si128(
                          _mm_slli_si128(
                            _mm_load_si128((const __m128i *)&v1->m_motion.m_motionState.m_transform.m_rotation.m_col2),
                            4),
                          4);
    v4 = _mm_unpackhi_ps(v1->m_motion.m_motionState.m_transform.m_translation.m_quad, query.m_quad);
    v5 = (UFG::qVector4)_mm_srli_si128(
                          _mm_slli_si128(_mm_load_si128((const __m128i *)&v1->m_motion.m_motionState), 4),
                          4);
    this->mBodyTransform.v1 = (UFG::qVector4)_mm_srli_si128(
                                               _mm_slli_si128(
                                                 _mm_load_si128((const __m128i *)&v1->m_motion.m_motionState.m_transform.m_rotation.m_col1),
                                                 4),
                                               4);
    this->mBodyTransform.v0 = v5;
    this->mBodyTransform.v2 = v3;
    this->mBodyTransform.v3 = (UFG::qVector4)_mm_shuffle_ps(v2, v4, 196);
  }
}

// File Line: 1164
// RVA: 0x4803D0
void __fastcall UFG::PhysicsVehicle::UpdateTransforms(UFG::PhysicsVehicle *this, UFG::qMatrix44 *rootTransform)
{
  UFG::qMatrix44 *v2; // rdi
  UFG::PhysicsVehicle *v3; // rbx
  hkpRigidBody *v4; // rdx
  hkpRigidBody *v5; // rcx
  UFG::qMatrix44 result; // [rsp+20h] [rbp-88h]
  hkTransformf transform; // [rsp+60h] [rbp-48h]

  v2 = rootTransform;
  v3 = this;
  v4 = this->mRigidBody->mBody;
  if ( v4 )
  {
    v5 = this->mBulletCollider;
    if ( v5 )
      hkpRigidBody::setTransform(v5, &v4->m_motion.m_motionState.m_transform);
    if ( v3->mVolumeRigidBody )
    {
      UFG::qMatrix44::operator*(&v3->mVolumeOffset, &result, v2);
      hkTransformf::set4x4ColumnMajor(&transform, &result.v0.x);
      hkpRigidBody::setTransform(v3->mVolumeRigidBody, &transform);
    }
  }
}

// File Line: 1192
// RVA: 0x4585E0
void __fastcall UFG::PhysicsVehicle::ApplyImpulse(UFG::PhysicsVehicle *this, UFG::qVector3 *impulse, UFG::qVector3 *pos)
{
  UFG::RigidBody::ApplyLinearImpulse((UFG::RigidBody *)&this->mRigidBody->vfptr, impulse, pos);
}

// File Line: 1199
// RVA: 0x475170
void __fastcall UFG::PhysicsVehicle::SetMassScaleForCollisions(UFG::PhysicsVehicle *this, float scaleMass, float scaleRotMass)
{
  UFG::PhysicsVehicle *v3; // rdi
  UFG::VehicleCollisionListener *v4; // rbx
  char v5; // dl
  __int64 v6; // rax
  char v7; // cl
  _QWORD **v8; // rax
  UFG::VehicleCollisionListener *v9; // rax
  char v10; // al
  UFG::VehicleCollisionListener *v11; // rax

  v3 = this;
  if ( !this->mCollisionListener && this->mRigidBody->mBody )
  {
    v4 = (UFG::VehicleCollisionListener *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64);
    v5 = ++v4[1].mInverseMassScale.m_quad.m128_i8[0];
    v6 = v5;
    *((_DWORD *)&v4->vfptr + v6) = 3;
    *((_QWORD *)&v4->mBody + v6) = "VehicleCollisionListener";
    *((_QWORD *)&v4[1].vfptr + v6) = 0i64;
    v7 = v4[1].mInverseMassScale.m_quad.m128_i8[1];
    if ( v5 > v7 )
      v7 = v5;
    v4[1].mInverseMassScale.m_quad.m128_i8[1] = v7;
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (UFG::VehicleCollisionListener *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(
                                            v8[11],
                                            48i64);
    if ( v9 )
      UFG::VehicleCollisionListener::VehicleCollisionListener(v9, v3->mRigidBody->mBody);
    v3->mCollisionListener = v9;
    v10 = v4[1].mInverseMassScale.m_quad.m128_i8[0];
    if ( v10 > 0 )
    {
      v4[1].mInverseMassScale.m_quad.m128_i8[0] = v10 - 1;
    }
    else
    {
      v4[1].mInverseMassScale.m_quad.m128_i8[0] = 0;
      LODWORD(v4->vfptr) = 3;
      v4->mBody = 0i64;
      v4[1].vfptr = 0i64;
    }
  }
  v11 = v3->mCollisionListener;
  v11->mInverseMassScale.m_quad.m128_f32[0] = 1.0 / scaleRotMass;
  v11->mInverseMassScale.m_quad.m128_f32[1] = 1.0 / scaleRotMass;
  v11->mInverseMassScale.m_quad.m128_f32[2] = 1.0 / scaleRotMass;
  v11->mInverseMassScale.m_quad.m128_f32[3] = 1.0 / scaleMass;
}

// File Line: 1213
// RVA: 0x45A630
void __fastcall UFG::PhysicsVehicle::ClearMassScaleForCollisions(UFG::PhysicsVehicle *this)
{
  UFG::PhysicsVehicle *v1; // rbx
  UFG::VehicleCollisionListener *v2; // rcx

  v1 = this;
  if ( *((_BYTE *)this + 604) & 0x10 )
  {
    v2 = this->mCollisionListener;
    if ( v2 )
      ((void (__fastcall *)(UFG::VehicleCollisionListener *, signed __int64))v2->vfptr->~hkpContactListener)(v2, 1i64);
    v1->mCollisionListener = 0i64;
  }
  else
  {
    UFG::PhysicsVehicle::SetMassScaleForCollisions(this, 1.0, this->mRotMassScaleForCollisions);
  }
}

// File Line: 1228
// RVA: 0x466B80
void __fastcall UFG::PhysicsVehicle::GetMass(UFG::PhysicsVehicle *this)
{
  UFG::RigidBody::GetMass((UFG::RigidBody *)&this->mRigidBody->vfptr);
}

// File Line: 1236
// RVA: 0x44E200
void __fastcall UFG::VehicleCollisionListener::VehicleCollisionListener(UFG::VehicleCollisionListener *this, hkpRigidBody *rb)
{
  UFG::VehicleCollisionListener *v2; // rdi

  v2 = this;
  this->vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
  this->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  this->vfptr = (hkpContactListenerVtbl *)&UFG::VehicleCollisionListener::`vftable{for `hkpContactListener};
  this->vfptr = (hkpEntityListenerVtbl *)&UFG::VehicleCollisionListener::`vftable{for `hkpEntityListener};
  this->mBody = rb;
  this->mInverseMassScale = *(hkVector4f *)_xmm;
  hkpEntity::addContactListener((hkpEntity *)&rb->vfptr, (hkpContactListener *)&this->vfptr);
  hkpEntity::addEntityListener((hkpEntity *)&v2->mBody->vfptr, (hkpEntityListener *)&v2->vfptr);
  v2->mBody->m_collidable.m_forceCollideOntoPpu |= 4u;
}

// File Line: 1247
// RVA: 0x451940
void __fastcall UFG::VehicleCollisionListener::~VehicleCollisionListener(UFG::VehicleCollisionListener *this)
{
  UFG::VehicleCollisionListener *v1; // rbx
  hkpRigidBody *v2; // rcx

  v1 = this;
  this->vfptr = (hkpContactListenerVtbl *)&UFG::VehicleCollisionListener::`vftable{for `hkpContactListener};
  this->vfptr = (hkpEntityListenerVtbl *)&UFG::VehicleCollisionListener::`vftable{for `hkpEntityListener};
  v2 = this->mBody;
  if ( v2 )
  {
    hkpEntity::removeContactListener((hkpEntity *)&v2->vfptr, (hkpContactListener *)&v1->vfptr);
    hkpEntity::removeEntityListener((hkpEntity *)&v1->mBody->vfptr, (hkpEntityListener *)&v1->vfptr);
  }
  v1->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  v1->vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
}

// File Line: 1271
// RVA: 0x486AB0
void __fastcall UFG::VehicleCollisionListener::contactPointCallback(UFG::VehicleCollisionListener *this, hkpContactPointEvent *event)
{
  if ( event->m_bodies[0]->m_material.m_responseType.m_storage == 1
    && event->m_bodies[1]->m_material.m_responseType.m_storage == 1 )
  {
    hkpAddModifierUtil::setInvMassScalingForContact(event, this->mBody, &this->mInverseMassScale);
  }
}

// File Line: 1287
// RVA: 0x487700
void __fastcall UFG::VehicleCollisionListener::entityDeletedCallback(UFG::VehicleCollisionListener *this, hkpEntity *entity)
{
  char *v2; // rbx
  hkpEntity *v3; // rdi
  UFG::VehicleCollisionListener *v4; // rsi
  hkpEntityListener *v5; // rdx

  v2 = &this[-1].mInverseMassScale.m_quad.m128_i8[8];
  v3 = entity;
  v4 = this;
  hkpEntity::removeContactListener(entity, (hkpContactListener *)&this[-1].mInverseMassScale.m_quad.m128_u16[4]);
  v5 = 0i64;
  if ( v2 )
    v5 = (hkpEntityListener *)v4;
  hkpEntity::removeEntityListener(v3, v5);
  v4->vfptr = 0i64;
}

// File Line: 1297
// RVA: 0x482B70
void __fastcall UFG::VehicleSetup::buildVehicle(UFG::VehicleSetup *this, UFG::PhysicsWheeledVehicle *pwv, hkpWorld *world, hkpVehicleInstance *vehicle, hkpVehicleWheelCollide *wheelCollide)
{
  hkpVehicleInstance *v5; // r14
  UFG::PhysicsWheeledVehicle *v6; // r13
  UFG::VehicleSetup *v7; // r12
  signed __int64 v8; // rdi
  char v9; // dl
  __int64 v10; // rax
  signed int v11; // esi
  char v12; // cl
  _QWORD **v13; // rax
  hkpVehicleData *v14; // rax
  hkpVehicleData *v15; // rax
  char v16; // al
  char v17; // dl
  __int64 v18; // rax
  char v19; // cl
  _QWORD **v20; // rax
  __int64 v21; // rax
  char v22; // al
  char v23; // dl
  __int64 v24; // rax
  char v25; // cl
  _QWORD **v26; // rax
  __int64 v27; // rax
  char v28; // al
  char v29; // dl
  __int64 v30; // rax
  char v31; // cl
  _QWORD **v32; // rax
  hkpVehicleDefaultEngine *v33; // rax
  hkpVehicleDefaultEngine *v34; // rbx
  char v35; // al
  char v36; // dl
  __int64 v37; // rax
  char v38; // cl
  _QWORD **v39; // rax
  hkpVehicleDefaultTransmission *v40; // rax
  hkpVehicleDefaultTransmission *v41; // rbx
  char v42; // al
  char v43; // dl
  __int64 v44; // rax
  char v45; // cl
  _QWORD **v46; // rax
  hkpVehicleDefaultBrake *v47; // rax
  hkpVehicleDefaultBrake *v48; // rbx
  char v49; // al
  char v50; // r8
  __int64 v51; // rax
  char v52; // cl
  _QWORD **v53; // rax
  __int64 v54; // rax
  char v55; // al
  char v56; // dl
  __int64 v57; // rax
  char v58; // cl
  _QWORD **v59; // rax
  hkpVehicleDefaultAerodynamics *v60; // rax
  __m128 *v61; // r15
  UFG::qReflectObject *v62; // rbx
  char v63; // al
  char v64; // dl
  __int64 v65; // rax
  char v66; // cl
  _QWORD **v67; // rax
  hkpVehicleDefaultVelocityDamper *v68; // rax
  hkpVehicleVelocityDamper *v69; // rax
  char v70; // al
  char v71; // r8
  __int64 v72; // rax
  char v73; // cl
  _QWORD **v74; // rax
  __int64 v75; // rax
  char v76; // al
  hkpVehicleDriverInputStatus *v77; // rax
  hkQuaternionf *v78; // r15
  __int64 v79; // rbx
  float *v80; // rdi
  UFG::qReflectHandleBase v81; // [rsp+38h] [rbp-39h]
  UFG::qReflectHandleBase v82; // [rsp+60h] [rbp-11h]
  hkpWorld *v83; // [rsp+E0h] [rbp+6Fh]

  v83 = world;
  v5 = vehicle;
  v6 = pwv;
  v7 = this;
  UFG::qReflectHandleBase::qReflectHandleBase(&v82);
  v82.mTypeUID = UFG::qStringHash64("UFG::BaseVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::operator=(&v82, (UFG::qReflectHandleBase *)&v6->mDnaDefinition.mPrev);
  UFG::qReflectHandleBase::qReflectHandleBase(&v81);
  v81.mTypeUID = UFG::qStringHash64("UFG::WheeledVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v81, v81.mTypeUID, v82.mData->mBaseNode.mUID);
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v9 = ++*(_BYTE *)(v8 + 80);
  v10 = v9;
  *(_DWORD *)(v8 + 4 * v10) = 3;
  *(_QWORD *)(v8 + 8 * v10 + 16) = "hkpVehicleData";
  v11 = 0;
  *(_QWORD *)(v8 + 8 * v10 + 48) = 0i64;
  v12 = *(_BYTE *)(v8 + 81);
  if ( v9 > v12 )
    v12 = v9;
  *(_BYTE *)(v8 + 81) = v12;
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkpVehicleData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(v13[11], 208i64);
  if ( v14 )
    hkpVehicleData::hkpVehicleData(v14);
  else
    v15 = 0i64;
  v5->m_data = v15;
  v16 = *(_BYTE *)(v8 + 80);
  if ( v16 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v16 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v17 = ++*(_BYTE *)(v8 + 80);
  v18 = v17;
  *(_DWORD *)(v8 + 4 * v18) = 3;
  *(_QWORD *)(v8 + 8 * v18 + 16) = "VehicleAnalogDriverInput";
  *(_QWORD *)(v8 + 8 * v18 + 48) = 0i64;
  v19 = *(_BYTE *)(v8 + 81);
  if ( v17 > v19 )
    v19 = v17;
  *(_BYTE *)(v8 + 81) = v19;
  v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v20[11] + 8i64))(v20[11], 24i64);
  if ( v21 )
  {
    *(_QWORD *)v21 = &hkBaseObject::`vftable;
    *(_QWORD *)v21 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v21 + 8) = 0x1FFFF;
    *(_QWORD *)v21 = &hkpVehicleDriverInput::`vftable;
    *(_QWORD *)v21 = &UFG::VehicleAnalogDriverInput::`vftable;
    *(_DWORD *)(v21 + 16) = 0;
    *(_BYTE *)(v21 + 20) = 0;
  }
  else
  {
    v21 = 0i64;
  }
  v5->m_driverInput = (hkpVehicleDriverInput *)v21;
  v22 = *(_BYTE *)(v8 + 80);
  if ( v22 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v22 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v23 = ++*(_BYTE *)(v8 + 80);
  v24 = v23;
  *(_DWORD *)(v8 + 4 * v24) = 3;
  *(_QWORD *)(v8 + 8 * v24 + 16) = "Steering";
  *(_QWORD *)(v8 + 8 * v24 + 48) = 0i64;
  v25 = *(_BYTE *)(v8 + 81);
  if ( v23 > v25 )
    v25 = v23;
  *(_BYTE *)(v8 + 81) = v25;
  v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v26[11] + 8i64))(v26[11], 72i64);
  if ( v27 )
  {
    *(_QWORD *)v27 = &hkBaseObject::`vftable;
    *(_QWORD *)v27 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v27 + 8) = 0x1FFFF;
    *(_QWORD *)v27 = &hkpVehicleSteering::`vftable;
    *(_QWORD *)v27 = &UFG::Steering::`vftable;
    *(_QWORD *)(v27 + 16) = 0i64;
    *(_DWORD *)(v27 + 24) = 0;
    *(_DWORD *)(v27 + 28) = 2147483648;
    *(_DWORD *)(v27 + 32) = 0;
    *(_QWORD *)(v27 + 56) = 0i64;
    *(_DWORD *)(v27 + 68) = 0;
  }
  else
  {
    v27 = 0i64;
  }
  v5->m_steering = (hkpVehicleSteering *)v27;
  v28 = *(_BYTE *)(v8 + 80);
  if ( v28 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v28 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v29 = ++*(_BYTE *)(v8 + 80);
  v30 = v29;
  *(_DWORD *)(v8 + 4 * v30) = 3;
  *(_QWORD *)(v8 + 8 * v30 + 16) = "Engine";
  *(_QWORD *)(v8 + 8 * v30 + 48) = 0i64;
  v31 = *(_BYTE *)(v8 + 81);
  if ( v29 > v31 )
    v31 = v29;
  *(_BYTE *)(v8 + 81) = v31;
  v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v33 = (hkpVehicleDefaultEngine *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v32[11] + 8i64))(
                                     v32[11],
                                     104i64);
  v34 = v33;
  if ( v33 )
  {
    hkpVehicleDefaultEngine::hkpVehicleDefaultEngine(v33);
    v34->vfptr = (hkBaseObjectVtbl *)&UFG::Engine::`vftable;
    *(_QWORD *)&v34[1].m_memSizeAndFlags = 0i64;
    v34[1].vfptr = 0i64;
    *(_QWORD *)&v34[1].m_minRPM = 0i64;
    v34[1].m_maxRPM = 1000000.0;
    *(_QWORD *)&v34[1].m_maxTorque = 1113325568i64;
    v34[1].m_torqueFactorAtMaxRPM = 0.33000001;
    v34[1].m_resistanceFactorAtMinRPM = 0.02;
  }
  else
  {
    v34 = 0i64;
  }
  v5->m_engine = (hkpVehicleEngine *)&v34->vfptr;
  v35 = *(_BYTE *)(v8 + 80);
  if ( v35 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v35 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v36 = ++*(_BYTE *)(v8 + 80);
  v37 = v36;
  *(_DWORD *)(v8 + 4 * v37) = 3;
  *(_QWORD *)(v8 + 8 * v37 + 16) = "Transmission";
  *(_QWORD *)(v8 + 8 * v37 + 48) = 0i64;
  v38 = *(_BYTE *)(v8 + 81);
  if ( v36 > v38 )
    v38 = v36;
  *(_BYTE *)(v8 + 81) = v38;
  v39 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v40 = (hkpVehicleDefaultTransmission *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v39[11] + 8i64))(
                                           v39[11],
                                           112i64);
  v41 = v40;
  if ( v40 )
  {
    hkpVehicleDefaultTransmission::hkpVehicleDefaultTransmission(v40);
    v41->vfptr = (hkBaseObjectVtbl *)&UFG::Transmission::`vftable;
    v41[1].vfptr = 0i64;
    *(_DWORD *)&v41[1].m_memSizeAndFlags = 0;
    *(_DWORD *)(&v41[1].m_referenceCount + 1) = 2147483648;
    *(_QWORD *)&v41[1].m_downshiftRPM = 0i64;
    v41[1].m_primaryTransmissionRatio = 0.0;
    v41[1].m_clutchDelayTime = -0.0;
    LODWORD(v41[1].m_reverseGearRatio) &= 0xFFFFFFFE;
  }
  else
  {
    v41 = 0i64;
  }
  v5->m_transmission = (hkpVehicleTransmission *)&v41->vfptr;
  v42 = *(_BYTE *)(v8 + 80);
  if ( v42 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v42 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v43 = ++*(_BYTE *)(v8 + 80);
  v44 = v43;
  *(_DWORD *)(v8 + 4 * v44) = 3;
  *(_QWORD *)(v8 + 8 * v44 + 16) = "Brakes";
  *(_QWORD *)(v8 + 8 * v44 + 48) = 0i64;
  v45 = *(_BYTE *)(v8 + 81);
  if ( v43 > v45 )
    v45 = v43;
  *(_BYTE *)(v8 + 81) = v45;
  v46 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v47 = (hkpVehicleDefaultBrake *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v46[11] + 8i64))(
                                    v46[11],
                                    48i64);
  v48 = v47;
  if ( v47 )
  {
    hkpVehicleDefaultBrake::hkpVehicleDefaultBrake(v47);
    v48->vfptr = (hkBaseObjectVtbl *)&UFG::Brakes::`vftable;
    v48[1].vfptr = 0i64;
  }
  else
  {
    v48 = 0i64;
  }
  v5->m_brake = (hkpVehicleBrake *)&v48->vfptr;
  v49 = *(_BYTE *)(v8 + 80);
  if ( v49 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v49 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v50 = ++*(_BYTE *)(v8 + 80);
  v51 = v50;
  *(_DWORD *)(v8 + 4 * v51) = 3;
  *(_QWORD *)(v8 + 8 * v51 + 16) = "hkpVehicleDefaultSuspension";
  *(_QWORD *)(v8 + 8 * v51 + 48) = 0i64;
  v52 = *(_BYTE *)(v8 + 81);
  if ( v50 > v52 )
    v52 = v50;
  *(_BYTE *)(v8 + 81) = v52;
  v53 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v54 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v53[11] + 8i64))(v53[11], 48i64);
  if ( v54 )
  {
    *(_QWORD *)v54 = &hkBaseObject::`vftable;
    *(_QWORD *)v54 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v54 + 8) = 0x1FFFF;
    *(_QWORD *)v54 = &hkpVehicleSuspension::`vftable;
    *(_QWORD *)(v54 + 16) = 0i64;
    *(_DWORD *)(v54 + 24) = 0;
    *(_DWORD *)(v54 + 28) = 2147483648;
    *(_QWORD *)v54 = &hkpVehicleDefaultSuspension::`vftable;
    *(_QWORD *)(v54 + 32) = 0i64;
    *(_DWORD *)(v54 + 40) = 0;
    *(_DWORD *)(v54 + 44) = 2147483648;
  }
  else
  {
    v54 = 0i64;
  }
  v5->m_suspension = (hkpVehicleSuspension *)v54;
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
  v57 = v56;
  *(_DWORD *)(v8 + 4 * v57) = 3;
  *(_QWORD *)(v8 + 8 * v57 + 16) = "VehicleAerodynamics";
  *(_QWORD *)(v8 + 8 * v57 + 48) = 0i64;
  v58 = *(_BYTE *)(v8 + 81);
  if ( v56 > v58 )
    v58 = v56;
  *(_BYTE *)(v8 + 81) = v58;
  v59 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v60 = (hkpVehicleDefaultAerodynamics *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v59[11] + 8i64))(
                                           v59[11],
                                           64i64);
  v61 = (__m128 *)v60;
  if ( v60 )
  {
    v62 = v81.mData;
    hkpVehicleDefaultAerodynamics::hkpVehicleDefaultAerodynamics(v60);
    v61->m128_u64[0] = (unsigned __int64)&UFG::VehicleAerodynamics::`vftable;
    v61[3].m128_i32[0] = 0;
    v61[3].m128_i32[1] = 1065353216;
    v61[2] = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)0i64, (__m128)HIDWORD(v62[5].mBaseNode.mNeighbours[1])),
               (__m128)0i64);
  }
  else
  {
    v61 = 0i64;
  }
  v5->m_aerodynamics = (hkpVehicleAerodynamics *)v61;
  v63 = *(_BYTE *)(v8 + 80);
  if ( v63 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v63 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v64 = ++*(_BYTE *)(v8 + 80);
  v65 = v64;
  *(_DWORD *)(v8 + 4 * v65) = 3;
  *(_QWORD *)(v8 + 8 * v65 + 16) = "hkpVehicleDefaultVelocityDamper";
  *(_QWORD *)(v8 + 8 * v65 + 48) = 0i64;
  v66 = *(_BYTE *)(v8 + 81);
  if ( v64 > v66 )
    v66 = v64;
  *(_BYTE *)(v8 + 81) = v66;
  v67 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v68 = (hkpVehicleDefaultVelocityDamper *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v67[11] + 8i64))(
                                             v67[11],
                                             32i64);
  if ( v68 )
    hkpVehicleDefaultVelocityDamper::hkpVehicleDefaultVelocityDamper(v68);
  else
    v69 = 0i64;
  v5->m_velocityDamper = v69;
  v70 = *(_BYTE *)(v8 + 80);
  if ( v70 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v70 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v5->m_wheelCollide = wheelCollide;
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpWorld *, hkpVehicleData *, UFG::qReflectObject *))v7->vfptr[2].__vecDelDtor)(
    v7,
    v83,
    v5->m_data,
    v81.mData);
  v5->m_tyreMarks = 0i64;
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleDriverInput *))v7->vfptr[6].__vecDelDtor)(
    v7,
    v5->m_data,
    v81.mData,
    v5->m_driverInput);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleEngine *))v7->vfptr[5].__vecDelDtor)(
    v7,
    v5->m_data,
    v81.mData,
    v5->m_engine);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleTransmission *))v7->vfptr[4].__first_virtual_table_function__)(
    v7,
    v5->m_data,
    v81.mData,
    v5->m_transmission);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleSteering *))v7->vfptr[5].__first_virtual_table_function__)(
    v7,
    v5->m_data,
    v81.mData,
    v5->m_steering);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleBrake *))v7->vfptr[4].__vecDelDtor)(
    v7,
    v5->m_data,
    v81.mData,
    v5->m_brake);
  ((void (__fastcall *)(UFG::VehicleSetup *, UFG::PhysicsWheeledVehicle *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleSuspension *))v7->vfptr[3].__first_virtual_table_function__)(
    v7,
    v6,
    v5->m_data,
    v81.mData,
    v5->m_suspension);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleAerodynamics *))v7->vfptr[3].__vecDelDtor)(
    v7,
    v5->m_data,
    v81.mData,
    v5->m_aerodynamics);
  ((void (__fastcall *)(UFG::VehicleSetup *, hkpVehicleData *, UFG::qReflectObject *, hkpVehicleVelocityDamper *))v7->vfptr[2].__first_virtual_table_function__)(
    v7,
    v5->m_data,
    v81.mData,
    v5->m_velocityDamper);
  ((void (__fastcall *)(UFG::VehicleSetup *, UFG::PhysicsWheeledVehicle *, hkpWorld *, hkpVehicleInstance *, hkpVehicleWheelCollide *))v7->vfptr[6].__first_virtual_table_function__)(
    v7,
    v6,
    v83,
    v5,
    v5->m_wheelCollide);
  v71 = ++*(_BYTE *)(v8 + 80);
  v72 = v71;
  *(_DWORD *)(v8 + 4 * v72) = 3;
  *(_QWORD *)(v8 + 8 * v72 + 16) = "hkpVehicleDriverInputAnalogStatus";
  *(_QWORD *)(v8 + 8 * v72 + 48) = 0i64;
  v73 = *(_BYTE *)(v8 + 81);
  if ( v71 > v73 )
    v73 = v71;
  *(_BYTE *)(v8 + 81) = v73;
  v74 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v75 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v74[11] + 8i64))(v74[11], 32i64);
  if ( v75 )
  {
    *(_QWORD *)v75 = &hkBaseObject::`vftable;
    *(_QWORD *)v75 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v75 + 8) = 0x1FFFF;
    *(_QWORD *)v75 = &hkpVehicleDriverInputStatus::`vftable;
    *(_QWORD *)v75 = &hkpVehicleDriverInputAnalogStatus::`vftable;
  }
  else
  {
    v75 = 0i64;
  }
  v5->m_deviceStatus = (hkpVehicleDriverInputStatus *)v75;
  v76 = *(_BYTE *)(v8 + 80);
  if ( v76 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v76 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v77 = v5->m_deviceStatus;
  v77[1].vfptr = 0i64;
  v77[1].m_memSizeAndFlags = 0;
  ((void (__fastcall *)(hkpVehicleInstance *))v5->vfptr[4].__vecDelDtor)(v5);
  v78 = (hkQuaternionf *)v6->mRigidBody->mBody;
  if ( v5->m_data->m_numWheels > 0 )
  {
    v79 = 0i64;
    v80 = v6->mCurrentSuspensionLength.array;
    do
    {
      v5->m_wheelsInfo.m_data[v79].m_currentSuspensionLength = *v80;
      hkVector4f::setRotatedDir(
        &v5->m_wheelsInfo.m_data[v11].m_suspensionDirectionWs,
        v78 + 30,
        (hkVector4f *)v6 + v11 + 46i64);
      ++v11;
      ++v80;
      ++v79;
    }
    while ( v11 < v5->m_data->m_numWheels );
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v81);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v82);
}

// File Line: 1376
// RVA: 0x488A90
void __fastcall UFG::VehicleSetup::setupVehicleData(UFG::VehicleSetup *this, hkpWorld *world, hkpVehicleData *data, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr)
{
  hkArray<hkpVehicleData::WheelComponentParams,hkContainerHeapAllocator> *v4; // rbx
  UFG::WheeledVehiclePhysicsDef *v5; // rdi
  hkpVehicleData *v6; // rsi
  UFG::VehicleSetup *v7; // rbp
  int v8; // eax
  int v9; // er14
  int v10; // eax
  int v11; // eax
  int v12; // er9
  hkArray<hkpVehicleData::WheelComponentParams,hkContainerHeapAllocator> *v13; // r8
  signed __int64 v14; // r8
  signed __int64 v15; // rdx
  signed __int64 v16; // r8
  signed __int64 v17; // rdx
  signed int v18; // er8
  __int64 v19; // rdx
  float v20; // xmm0_4
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __int64 v24; // [rsp+A0h] [rbp+8h]

  v4 = &data->m_wheelParams;
  v5 = vehicle_data_ptr;
  v6 = data;
  v7 = this;
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
  v8 = SLOBYTE(vehicle_data_ptr->numWheels);
  v9 = v8;
  data->m_numWheels = v8;
  v10 = data->m_wheelParams.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < v9 )
  {
    v11 = 2 * v10;
    v12 = v9;
    v13 = &data->m_wheelParams;
    if ( v9 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve((hkResult *)&v24, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v13, v12, 40);
  }
  v4->m_size = v9;
  v14 = v7->mParams.firstFrontWheel;
  if ( (signed int)v14 <= v7->mParams.lastFrontWheel )
  {
    v15 = v14;
    do
    {
      LODWORD(v14) = v14 + 1;
      v4->m_data[v15].m_radius = v5->wheels_radius_front;
      ++v15;
      *((_BYTE *)&v4->m_data[v15] - 4) = 0;
      *((_DWORD *)&v4->m_data[v15] - 7) = LODWORD(v5->wheels_frictionFront);
    }
    while ( (signed int)v14 <= v7->mParams.lastFrontWheel );
  }
  v16 = v7->mParams.firstRearWheel;
  if ( (signed int)v16 <= v7->mParams.lastRearWheel )
  {
    v17 = v16;
    do
    {
      LODWORD(v16) = v16 + 1;
      v4->m_data[v17].m_radius = v5->wheels_radius_rear;
      ++v17;
      *((_BYTE *)&v4->m_data[v17] - 4) = 1;
      *((_DWORD *)&v4->m_data[v17] - 7) = LODWORD(v5->wheels_frictionRear);
    }
    while ( (signed int)v16 <= v7->mParams.lastRearWheel );
  }
  v18 = 0;
  if ( v6->m_numWheels > 0 )
  {
    v19 = 0i64;
    do
    {
      if ( v6->m_numWheels == 2 )
        v20 = FLOAT_0_1;
      else
        v20 = FLOAT_0_25;
      ++v18;
      ++v19;
      *((float *)&v4->m_data[v19] - 8) = v20;
      *((_DWORD *)&v4->m_data[v19] - 9) = LODWORD(v5->wheels_mass);
      *((_DWORD *)&v4->m_data[v19] - 6) = LODWORD(v5->wheels_viscosityFriction);
      *((_DWORD *)&v4->m_data[v19] - 4) = LODWORD(v5->wheels_slipAngle);
      *((float *)&v4->m_data[v19] - 5) = *((float *)&v4->m_data[v19] - 7) * 2.0;
      *((_DWORD *)&v4->m_data[v19] - 3) = LODWORD(v5->wheels_forceFeedbackMultiplier);
      v21 = _mm_mul_ps(v6->m_gravity.m_quad, v6->m_gravity.m_quad);
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
              _mm_shuffle_ps(v21, v21, 170));
      v23 = _mm_rsqrt_ps(v22);
      *((float *)&v4->m_data[v19] - 2) = COERCE_FLOAT(
                                           _mm_andnot_ps(
                                             _mm_cmpleps(v22, (__m128)0i64),
                                             _mm_mul_ps(
                                               _mm_mul_ps(
                                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                                                 _mm_mul_ps(*(__m128 *)_xmm, v23)),
                                               v22)))
                                       * 2.0;
    }
    while ( v18 < v6->m_numWheels );
  }
}

// File Line: 1433
// RVA: 0x488730
void __fastcall UFG::VehicleSetup::setupComponent(UFG::VehicleSetup *this, hkpVehicleData *data, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr, UFG::Steering *steering)
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
void __fastcall UFG::VehicleSetup::setupComponent(UFG::VehicleSetup *this, hkpVehicleData *data, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr, UFG::Brakes *brake)
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
void __fastcall UFG::VehicleSetup::setupComponent(UFG::VehicleSetup *this, UFG::PhysicsWheeledVehicle *pwv, hkpVehicleData *data, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr, hkpVehicleDefaultSuspension *suspension)
{
  UFG::WheeledVehiclePhysicsDef *v5; // rsi
  hkpVehicleData *v6; // r14
  UFG::PhysicsWheeledVehicle *v7; // r12
  UFG::VehicleSetup *v8; // rbp
  int v9; // edi
  hkpVehicleDefaultSuspension *v10; // r15
  int v11; // eax
  int v12; // eax
  int v13; // er9
  __int64 v14; // rcx
  signed __int64 v15; // r8
  int v16; // edx
  int v17; // er14
  int v18; // eax
  int v19; // eax
  int v20; // er9
  signed __int64 v21; // r10
  signed __int64 v22; // r8
  signed __int64 v23; // r9
  hkVector4f *v24; // rdx
  signed __int64 v25; // r10
  signed __int64 v26; // rdx
  signed __int64 v27; // r8
  hkVector4f *v28; // r9

  v5 = vehicle_data_ptr;
  v6 = data;
  v7 = pwv;
  v8 = this;
  v9 = data->m_numWheels;
  v10 = suspension;
  v11 = suspension->m_wheelParams.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v9 )
  {
    v12 = 2 * v11;
    v13 = data->m_numWheels;
    if ( v9 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(
      (hkResult *)&suspension,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &suspension->m_wheelParams,
      v13,
      48);
  }
  v14 = v10->m_wheelParams.m_size;
  v15 = (signed __int64)&v10->m_wheelParams.m_data[v14];
  v16 = 0;
  LODWORD(suspension) = 0;
  if ( v9 - (signed int)v14 > 0 )
  {
    do
      LODWORD(suspension) = ++v16;
    while ( v16 < v9 - v10->m_wheelParams.m_size );
  }
  v10->m_wheelParams.m_size = v9;
  v17 = v6->m_numWheels;
  v18 = v10->m_wheelSpringParams.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < v17 )
  {
    v19 = 2 * v18;
    v20 = v17;
    if ( v17 < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(
      (hkResult *)&suspension,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v10->m_wheelSpringParams,
      v20,
      12);
  }
  v10->m_wheelSpringParams.m_size = v17;
  v21 = v8->mParams.firstFrontWheel;
  if ( (signed int)v21 <= v8->mParams.lastFrontWheel )
  {
    v22 = v21;
    v23 = v21;
    v24 = (hkVector4f *)((char *)v7 + 16 * (v21 + 42));
    do
    {
      v10->m_wheelParams.m_data[v23].m_length = v5->suspension_frontSpringLength;
      v10->m_wheelParams.m_data[v23].m_directionChassisSpace = (hkVector4f)v24[4].m_quad;
      v10->m_wheelParams.m_data[v23].m_hardpointChassisSpace = (hkVector4f)v24->m_quad;
      v10->m_wheelSpringParams.m_data[v22].m_strength = v5->suspension_frontSpringRate;
      v10->m_wheelSpringParams.m_data[v22].m_dampingCompression = v5->suspension_frontShockDampingCompression;
      v10->m_wheelSpringParams.m_data[v22].m_dampingRelaxation = v5->suspension_frontShockDampingExtension;
      LODWORD(v21) = v21 + 1;
      ++v24;
      ++v23;
      ++v22;
    }
    while ( (signed int)v21 <= v8->mParams.lastFrontWheel );
  }
  v25 = v8->mParams.firstRearWheel;
  if ( (signed int)v25 <= v8->mParams.lastRearWheel )
  {
    v26 = v25;
    v27 = v25;
    v28 = (hkVector4f *)((char *)v7 + 16 * (v25 + 42));
    do
    {
      v10->m_wheelParams.m_data[v27].m_length = v5->suspension_rearSpringLength;
      v10->m_wheelParams.m_data[v27].m_directionChassisSpace = (hkVector4f)v28[4].m_quad;
      v10->m_wheelParams.m_data[v27].m_hardpointChassisSpace = (hkVector4f)v28->m_quad;
      v10->m_wheelSpringParams.m_data[v26].m_strength = v5->suspension_rearSpringRate;
      v10->m_wheelSpringParams.m_data[v26].m_dampingCompression = v5->suspension_rearShockDampingCompression;
      v10->m_wheelSpringParams.m_data[v26].m_dampingRelaxation = v5->suspension_rearShockDampingExtension;
      LODWORD(v25) = v25 + 1;
      ++v28;
      ++v27;
      ++v26;
    }
    while ( (signed int)v25 <= v8->mParams.lastRearWheel );
  }
}

// File Line: 1485
// RVA: 0x488770
void __fastcall UFG::VehicleSetup::setupComponent(UFG::VehicleSetup *this, hkpVehicleData *data, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr, UFG::Transmission *transmission)
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
void __fastcall UFG::VehicleSetup::setupComponent(UFG::VehicleSetup *this, hkpVehicleData *data, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr, UFG::VehicleAnalogDriverInput *driverInput)
{
  driverInput->m_deadZone = vehicle_data_ptr->steering_DeadZone;
  driverInput->m_autoReverse.m_bool = 0;
}

// File Line: 1506
// RVA: 0x488720
void __fastcall UFG::VehicleSetup::setupComponent(UFG::VehicleSetup *this, hkpVehicleData *data, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr, UFG::Engine *engine)
{
  UFG::Engine::InitializeFromPropertySet(engine, vehicle_data_ptr);
}

// File Line: 1513
// RVA: 0x4887B0
void __fastcall UFG::VehicleSetup::setupComponent(UFG::VehicleSetup *this, hkpVehicleData *data, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr, UFG::VehicleAerodynamics *aerodynamics)
{
  aerodynamics->m_airDensity = vehicle_data_ptr->aerodynamics_airDensity;
  aerodynamics->m_frontalArea = vehicle_data_ptr->aerodynamics_frontalArea;
  aerodynamics->m_dragCoefficient = vehicle_data_ptr->aerodynamics_dragCoefficient;
  aerodynamics->m_liftCoefficient = vehicle_data_ptr->aerodynamics_liftCoefficient;
}

// File Line: 1520
// RVA: 0x488800
void __fastcall UFG::VehicleSetup::setupComponent(UFG::VehicleSetup *this, hkpVehicleData *data, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr, hkpVehicleDefaultVelocityDamper *velocityDamper)
{
  velocityDamper->m_normalSpinDamping = vehicle_data_ptr->damping_normalSpinDamping;
  velocityDamper->m_collisionSpinDamping = vehicle_data_ptr->damping_collisionSpinDamping;
  velocityDamper->m_collisionThreshold = vehicle_data_ptr->damping_collisionThreshold;
}

// File Line: 1529
// RVA: 0x488D80
void __fastcall UFG::VehicleSetup::setupWheelCollide(UFG::VehicleSetup *this, UFG::PhysicsWheeledVehicle *pwv, hkpWorld *world, hkpVehicleInstance *vehicle, hkpVehicleWheelCollide *wheelCollide)
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
  UFG::PhysicsWheeledVehicle *v2; // rbx
  UFG::VehicleAction *v3; // rdi

  v2 = vehicle;
  v3 = this;
  hkpUnaryAction::hkpUnaryAction((hkpUnaryAction *)&this->vfptr, (hkpEntity *)&vehicle->mRigidBody->mBody->vfptr, 0i64);
  v3->vfptr = (hkBaseObjectVtbl *)&UFG::VehicleAction::`vftable;
  v3->mVehicle = v2;
  v3->mFlatTireDistance = 0.0;
}

// File Line: 1556
// RVA: 0x4823F0
void __fastcall UFG::VehicleAction::applyAction(UFG::VehicleAction *this, hkStepInfo *stepInfo)
{
  hkpEntity *v2; // rsi
  UFG::VehicleAction *v3; // rdi
  UFG::PhysicsWheeledVehicle *v4; // rcx
  hkStepInfo *v5; // r14
  __m128 v6; // xmm8
  __m128 v7; // xmm0
  float v8; // xmm1_4
  __int128 v9; // xmm1
  hkpReorientAction *v10; // rcx
  __m128 v11; // xmm2
  UFG::PhysicsWheeledVehicle *v12; // rbx
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm7
  float v17; // xmm0_4
  __m128 v18; // xmm1
  float v19; // xmm0_4
  unsigned int v20; // er8
  __int64 v21; // rdx
  float *v22; // rcx
  UFG::VehicleInstance *v23; // rax
  hkpVehicleWheelCollide *v24; // rcx
  float v25; // xmm0_4
  UFG::qMatrix44 *v26; // rax
  __m128 v27; // xmm4
  __int128 v28; // xmm2
  UFG::qVector4 v29; // xmm0
  UFG::PhysicsWheeledVehicle *v30; // rax
  __m128 v31; // xmm1
  __m128 v32; // xmm6
  __int64 v33; // rdx
  UFG::PhysicsWheeledVehicle *v34; // rdx
  int v35; // ecx
  UFG::PhysicsWheeledVehicle *v36; // rcx
  __int128 v37; // xmm1
  __m128 v38; // [rsp+30h] [rbp-D0h]
  __m128 v39; // [rsp+40h] [rbp-C0h]
  __m128 v40; // [rsp+50h] [rbp-B0h]
  __int128 v41; // [rsp+60h] [rbp-A0h]
  hkQuaternionf qi; // [rsp+70h] [rbp-90h]
  float d[4]; // [rsp+80h] [rbp-80h]
  UFG::qVector4 v44; // [rsp+90h] [rbp-70h]
  __int128 v45; // [rsp+A0h] [rbp-60h]
  __m128 v46; // [rsp+B0h] [rbp-50h]
  hkRotationf v47; // [rsp+C0h] [rbp-40h]
  __int128 v48; // [rsp+F0h] [rbp-10h]
  UFG::qMatrix44 result; // [rsp+100h] [rbp+0h]

  v2 = this->m_entity;
  v3 = this;
  v4 = this->mVehicle;
  v5 = stepInfo;
  v6 = v2->m_motion.m_linearVelocity.m_quad;
  if ( (*((_DWORD *)v4 + 274) >> 3) & 1 )
  {
    v7 = _mm_shuffle_ps(v6, v6, 170);
    v8 = v7.m128_f32[0] <= 0.0 ? v4->mVerticalVelocityDampingDown : v4->mVerticalVelocityDampingUp;
    v7.m128_f32[0] = v7.m128_f32[0] * v8;
    v9 = LODWORD(stepInfo->m_deltaTime.m_storage);
    v38 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, _mm_xor_ps(v7, *(__m128 *)_xmm)), (__m128)0i64);
    ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, hkStepInfo *, __m128 *, const char *))v4->vfptr[6].__vecDelDtor)(
      v4,
      stepInfo,
      &v38,
      "Vert Vel Damping");
    v10 = v3->mVehicle->mReorientActionPitch;
    if ( v10 )
    {
      v11 = _mm_mul_ps(_xmm, v2->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))) > 0.40000001 )
        ((void (__fastcall *)(hkpReorientAction *, hkStepInfo *))v10->vfptr[1].__first_virtual_table_function__)(
          v10,
          v5);
    }
  }
  v12 = v3->mVehicle;
  v13 = _mm_mul_ps(v6, v6);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rsqrt_ps(v14);
  v16 = _mm_andnot_ps(
          _mm_cmpleps(v14, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
              _mm_mul_ps(*(__m128 *)_xmm, v15)),
            v14));
  v17 = (float)(v16.m128_f32[0] * v5->m_deltaTime.m_storage) + v3->mFlatTireDistance;
  v3->mFlatTireDistance = v17;
  v18 = (__m128)LODWORD(v12->mBlownTireWobbleFrequency);
  if ( v17 >= v18.m128_f32[0] )
  {
    v19 = fmodf(v17, v18.m128_f32[0]);
    v20 = 0;
    v3->mFlatTireDistance = v19;
    if ( (*((_DWORD *)&v12->0 + 151) & 7) > 0 )
    {
      v21 = 0i64;
      v22 = v12->mTireDamage.array;
      while ( 1 )
      {
        if ( *v22 >= 1.0 )
        {
          v23 = v12->mHavokVehicle;
          if ( !v23 || v23->m_wheelsInfo.m_data[v21].m_contactBody != 0i64 )
            break;
        }
        ++v20;
        ++v22;
        ++v21;
        if ( (signed int)v20 >= (*((_DWORD *)&v12->0 + 151) & 7) )
          goto LABEL_23;
      }
      v24 = v12->mWheelCollider;
      v25 = v12->mBlownTireFrictionMultiplier;
      if ( v24 )
      {
        if ( (*((_DWORD *)&v12->0 + 151) & 7) == 2 )
          *((float *)&v24[8].m_memSizeAndFlags + v20) = v25;
        else
          *((float *)&v24[7].m_alreadyUsed.m_bool + v20) = v25;
      }
      ((void (__fastcall *)(UFG::VehicleInstance *, hkpRigidBody *, hkpVehicleSuspension *, _QWORD, __int128 *, hkQuaternionf *))v3->mVehicle->mHavokVehicle->vfptr[5].__first_virtual_table_function__)(
        v3->mVehicle->mHavokVehicle,
        v3->mVehicle->mRigidBody->mBody,
        v3->mVehicle->mHavokVehicle->m_suspension,
        v20,
        &v41,
        &qi);
      v48 = v41;
      hkRotationf::set(&v47, &qi);
      hkTransformf::get4x4ColumnMajor((hkTransformf *)&v47, d);
      v26 = UFG::qMatrix44::operator*(&UFG::gWheelFixup, &result, (UFG::qMatrix44 *)d);
      v16.m128_f32[0] = v16.m128_f32[0] * 0.1;
      v27 = (__m128)v26->v3;
      v28 = (__int128)v26->v2;
      v29 = v26->v0;
      v44 = v26->v1;
      v30 = v3->mVehicle;
      v46 = v27;
      v31 = _mm_unpacklo_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 255));
      *(UFG::qVector4 *)d = v29;
      v45 = v28;
      v38 = _mm_unpacklo_ps(_mm_unpacklo_ps(v27, _mm_shuffle_ps(v27, v27, 170)), v31);
      v31.m128_f32[0] = COERCE_FLOAT(LODWORD(v30->mBlownTireDrag) ^ _xmm[0]);
      v40 = _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v6);
      if ( v16.m128_f32[0] > 1.0 )
        v16 = (__m128)(unsigned int)FLOAT_1_0;
      v16.m128_f32[0] = v16.m128_f32[0] * v30->mBlownTireWobbleMagnitude;
      v39 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v16), (__m128)0i64);
      hkpEntity::activate(v2);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __m128 *))v2->m_motion.vfptr[11].__first_virtual_table_function__)(
        &v2->m_motion,
        &v39,
        &v38);
      v32 = (__m128)LODWORD(v5->m_deltaTime.m_storage);
      hkpEntity::activate(v2);
      v18 = v32;
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, __m128 *))v2->m_motion.vfptr[12].__first_virtual_table_function__)(
        &v2->m_motion,
        v33,
        &v40,
        &v38);
    }
  }
LABEL_23:
  v34 = v3->mVehicle;
  v35 = *((_DWORD *)&v34->0 + 151);
  if ( v35 & 8 && !((*((_DWORD *)v34 + 274) >> 3) & 1) )
  {
    if ( v34->mSpeedKPH < 0.5 )
      *((_DWORD *)&v34->0 + 151) = v35 & 0xFFFFFFF7;
    v36 = v3->mVehicle;
    v18.m128_f32[0] = COERCE_FLOAT(LODWORD(v36->mSuperStopDrag) ^ _xmm[0]);
    v38 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v6);
    v37 = LODWORD(v5->m_deltaTime.m_storage);
    v38.m128_i32[2] = 0;
    ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, UFG::PhysicsWheeledVehicle *, __m128 *, const char *))v36->vfptr[6].__vecDelDtor)(
      v36,
      v34,
      &v38,
      "Super Stop");
  }
}

// File Line: 1667
// RVA: 0x4758A0
void __fastcall UFG::PhysicsVehicle::SetupCollisionGeometry(UFG::PhysicsVehicle *this, const char *modelName)
{
  UFG::PhysicsVehicle *v2; // rdi
  unsigned int v3; // eax
  unsigned int v4; // ebx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // er8

  v2 = this;
  v3 = UFG::qStringHashUpper32(modelName, 0xFFFFFFFF);
  v4 = v3;
  v5 = UFG::qStringHashUpper32("_Body_P", v3);
  v2->mBodyCollisionMesh = (UFG::CollisionMeshData *)UFG::BasePhysicsSystem::GetCollisionModel(
                                                       UFG::BasePhysicsSystem::mInstance,
                                                       v5);
  v6 = UFG::qStringHashUpper32("_BodyBullet_P", v4);
  v2->mBulletCollisionMesh = (UFG::CollisionMeshData *)UFG::BasePhysicsSystem::GetCollisionModel(
                                                         UFG::BasePhysicsSystem::mInstance,
                                                         v6);
  v7 = v2->mBodyCollisionMesh->mBundleGuid;
  v2->mCollisionMeshBundle.mOwner = (UFG::BasePhysicsObject *)&v2->vfptr;
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mCollisionMeshBundle.mPrev, 0x1723EA91u, v7);
}

// File Line: 1685
// RVA: 0x473C70
void __fastcall UFG::PhysicsVehicle::ResourceUnloaded(UFG::PhysicsVehicle *this, UFG::PhysicsResourceHandle *resource)
{
  UFG::PhysicsVehicle *v2; // rbx
  UFG::SimComponent *v3; // rdx
  UFG::SimComponent *v4; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rax
  UFG::SimObjectModifier v7; // [rsp+28h] [rbp-30h]

  v2 = this;
  this->mCollisionMeshBundle.mOwner = 0i64;
  if ( this->mCoverComponent.m_pPointer )
  {
    UFG::SimObjectModifier::SimObjectModifier(&v7, this->mParams->mSimObject.m_pPointer, 1);
    v3 = v2->mCoverComponent.m_pPointer;
    ArrayOfTuplesImplementation::clear((ArrayOfTuplesImplementation *)&v7);
    UFG::SimObjectModifier::Close(&v7);
    UFG::SimObjectModifier::~SimObjectModifier(&v7);
    v4 = v2->mCoverComponent.m_pPointer;
    if ( v4 )
      v4->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v4->vfptr, 1u);
    resource = (UFG::PhysicsResourceHandle *)&v2->mCoverComponent;
    if ( v2->mCoverComponent.m_pPointer )
    {
      v5 = resource->mPrev;
      v6 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v2->mCoverComponent.mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      resource->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&resource->mPrev;
      v2->mCoverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mCoverComponent.mPrev;
    }
    v2->mCoverComponent.m_pPointer = 0i64;
  }
  ((void (__fastcall *)(UFG::PhysicsVehicle *, UFG::PhysicsResourceHandle *))v2->vfptr[2].DebugDraw)(v2, resource);
  UFG::PhysicsVehicle::DeleteHavokComponents(v2);
}

// File Line: 1703
// RVA: 0x47F450
void __fastcall UFG::PhysicsVehicle::UpdateLevelOfDetail(UFG::PhysicsVehicle *this)
{
  UFG::PhysicsVehicle *v1; // rdi
  UFG::PhysicsVehicle::Lod v2; // ecx
  hkpRigidBody *v3; // rsi
  UFG::BasePhysicsSystem *v4; // rbx
  UFG::PhysicsVehicle::Lod v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  UFG::SimComponent *v9; // rcx
  UFG::SimComponent *v10; // rcx
  UFG::SimComponent *v11; // rcx
  UFG::SimComponent *v12; // rcx
  UFG::SimComponent *v13; // rcx
  UFG::SimComponent *v14; // rcx

  v1 = this;
  if ( this->mCollisionMeshBundle.mUnloading )
    this->mDesiredLod = 5;
  v2 = this->mCurrentLod;
  if ( v1->mDesiredLod != v2 )
  {
    v3 = v1->mRigidBody->mBody;
    if ( v2 == LOD_UNINITIALIZED )
    {
      v4 = UFG::BasePhysicsSystem::mInstance;
      UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, v3, 1);
      UFG::BasePhysicsSystem::AddEntity(v4, v1->mBulletCollider, 1);
    }
    v5 = v1->mDesiredLod;
    v1->mCurrentLod = v5;
    v6 = v5 - 1;
    if ( !v6 )
      goto LABEL_32;
    v7 = v6 - 1;
    if ( !v7 )
    {
      v13 = v1->mParkourComponent.m_pPointer;
      if ( v13 )
        ((void (*)(void))v13->vfptr[9].__vecDelDtor)();
      v14 = v1->mCoverComponent.m_pPointer;
      if ( v14 )
        ((void (*)(void))v14->vfptr[9].__vecDelDtor)();
      if ( v3 )
      {
        hkpRigidBody::setMotionType(v3, MOTION_BOX_INERTIA, HK_ENTITY_ACTIVATION_DO_ACTIVATE, 0);
        v3->m_motion.m_gravityFactor.m_value = 0;
      }
      goto LABEL_16;
    }
    v8 = v7 - 1;
    if ( !v8 )
    {
      if ( v3 )
      {
        hkpRigidBody::setMotionType(v3, MOTION_BOX_INERTIA, HK_ENTITY_ACTIVATION_DO_ACTIVATE, 0);
        v3->m_motion.m_gravityFactor.m_value = HIWORD(FLOAT_1_0039062);
        hkpEntity::activate((hkpEntity *)&v3->vfptr);
      }
      v11 = v1->mParkourComponent.m_pPointer;
      if ( v11 )
        ((void (*)(void))v11->vfptr[9].__vecDelDtor)();
      v12 = v1->mCoverComponent.m_pPointer;
      if ( v12 )
        ((void (*)(void))v12->vfptr[9].__vecDelDtor)();
      goto LABEL_16;
    }
    if ( v8 == 1 )
    {
LABEL_32:
      v9 = v1->mParkourComponent.m_pPointer;
      if ( v9 )
        ((void (*)(void))v9->vfptr[8].__vecDelDtor)();
      v10 = v1->mCoverComponent.m_pPointer;
      if ( v10 )
        ((void (*)(void))v10->vfptr[8].__vecDelDtor)();
      if ( v3 )
        hkpRigidBody::setMotionType(
          v3,
          (hkpMotion::MotionType)(4 - (v1->mIsProxy != 0)),
          HK_ENTITY_ACTIVATION_DO_ACTIVATE,
          0);
    }
LABEL_16:
    ((void (__fastcall *)(UFG::PhysicsVehicle *, _QWORD))v1->vfptr[5].DebugDraw)(v1, (unsigned int)v1->mCurrentLod);
  }
}

// File Line: 1808
// RVA: 0x4654C0
void __fastcall UFG::PhysicsVehicle::FlipVehicle(UFG::PhysicsVehicle *this, float torqueFactor, UFG::qVector3 *collisionPoint)
{
  UFG::PhysicsVehicle *v3; // rbx
  hkVector4f result; // [rsp+20h] [rbp-18h]

  v3 = this;
  UFG::PhysicsVehicle::ComputeLocalXTorsionalImpulseWS(this, &result, torqueFactor, collisionPoint);
  ((void (__fastcall *)(UFG::PhysicsVehicle *, hkVector4f *, const char *))v3->vfptr[7].DebugDraw)(
    v3,
    &result,
    "Flip Vehicle");
}

// File Line: 1816
// RVA: 0x45B160
hkVector4f *__fastcall UFG::PhysicsVehicle::ComputeLocalXTorsionalImpulseWS(UFG::PhysicsVehicle *this, hkVector4f *result, float torqueFactor, UFG::qVector3 *collisionPoint)
{
  UFG::PhysicsVehicle *v4; // rbx
  hkVector4f *v5; // rsi
  UFG::qVector3 *v6; // rdi
  hkpMaxSizeMotion *v7; // rcx
  hkpRigidBody *v8; // rcx
  __m128 v9; // xmm3
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128i v15; // xmm2
  __m128 v16; // xmm8
  __m128 v17; // xmm3
  __m128 v18; // xmm8
  __m128i v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm6
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  hkVector4f *v26; // rax
  hkMatrix4f m; // [rsp+20h] [rbp-F8h]
  hkSimdFloat32 eps; // [rsp+60h] [rbp-B8h]
  unsigned int v29; // [rsp+70h] [rbp-A8h]
  unsigned int v30; // [rsp+80h] [rbp-98h]
  unsigned int v31; // [rsp+90h] [rbp-88h]
  hkMatrix4f v32; // [rsp+A0h] [rbp-78h]
  hkResult resulta; // [rsp+130h] [rbp+18h]

  v4 = this;
  v5 = result;
  v6 = collisionPoint;
  v7 = &this->mRigidBody->mBody->m_motion;
  ((void (__fastcall *)(hkpMaxSizeMotion *, unsigned int *))v7->vfptr[3].__first_virtual_table_function__)(v7, &v29);
  v8 = v4->mRigidBody->mBody;
  v9 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)v29, (__m128)v31), _mm_unpacklo_ps((__m128)v30, (__m128)0i64));
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  v13 = _mm_andnot_ps(
          _mm_cmpleps(v11, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
              _mm_mul_ps(*(__m128 *)_xmm, v12)),
            v11));
  v13.m128_f32[0] = v13.m128_f32[0] * torqueFactor;
  v14 = (__m128)LODWORD(v6->x);
  v15 = _mm_srli_si128(_mm_slli_si128((__m128i)v8->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad, 4), 4);
  v16 = v13;
  v17 = v8->m_motion.m_motionState.m_transform.m_translation.m_quad;
  v18 = _mm_unpacklo_ps(_mm_unpacklo_ps(v16, (__m128)0i64), (__m128)0i64);
  v19 = (__m128i)v8->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  _mm_store_si128(
    (__m128i *)&m,
    _mm_srli_si128(_mm_slli_si128((__m128i)v8->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, 4), 4));
  _mm_store_si128((__m128i *)&m.m_col2, v15);
  v20 = (__m128)LODWORD(v6->y);
  _mm_store_si128((__m128i *)&m.m_col1, _mm_srli_si128(_mm_slli_si128(v19, 4), 4));
  v21 = _mm_unpacklo_ps(v14, (__m128)LODWORD(v6->z));
  m.m_col3.m_quad = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, query.m_quad), 196);
  v22 = _mm_unpacklo_ps(v21, _mm_unpacklo_ps(v20, (__m128)(unsigned int)FLOAT_1_0));
  eps.m_real = (__m128)_xmm;
  hkMatrix4f::setInverse(&v32, &resulta, &m, &eps);
  v23 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v32.m_col0.m_quad), v32.m_col3.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v32.m_col1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v32.m_col2.m_quad));
  v24 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), (__m128)_xmm),
          _mm_mul_ps(_mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 201), v23));
  v25 = _mm_shuffle_ps(v24, v24, 201);
  if ( COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 170)) < 0.0 )
    v18 = _mm_mul_ps(v18, *(__m128 *)_xmm_bf800000bf800000bf800000bf800000);
  v26 = v5;
  v5->m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), m.m_col1.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), m.m_col0.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), m.m_col2.m_quad));
  return v26;
}

// File Line: 1859
// RVA: 0x464F40
UFG::PhysicsVehicle *__fastcall UFG::PhysicsVehicle::FixupTransformForGround(UFG::PhysicsVehicle *this, UFG::qMatrix44 *localWorld)
{
  UFG::qMatrix44 *v2; // rdi
  UFG::PhysicsVehicle *result; // rax
  signed __int64 v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  unsigned __int8 v11; // r14
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  float v15; // xmm11_4
  float v16; // xmm13_4
  float v17; // xmm10_4
  signed __int64 v18; // rsi
  signed int v19; // ebx
  float v20; // xmm12_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm8_4
  float v24; // xmm5_4
  float v25; // xmm0_4
  __int128 v26; // xmm3
  __m128 v27; // xmm6
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
  UFG::qVector3 v41; // [rsp+20h] [rbp-E0h]
  UFG::qVector3 v42; // [rsp+30h] [rbp-D0h]
  UFG::qVector3 rayStart; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 rayEnd; // [rsp+50h] [rbp-B0h]
  UFG::RayCastData data; // [rsp+60h] [rbp-A0h]
  UFG::RayCastData v46; // [rsp+140h] [rbp+40h]

  v2 = localWorld;
  result = 0i64;
  if ( *((_BYTE *)this + 604) & 7 )
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
      v6 = v2->v3.x;
      v7 = v2->v3.y;
      data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
      data.mInput.m_filterInfo = 0;
      v8 = v5 + v2->v3.z;
      rayStart.x = v6;
      rayStart.y = v7;
      data.mInput.m_userData = 0i64;
      data.mOutput.m_hitFraction = 1.0;
      data.mOutput.m_extraInfo = -1;
      rayStart.z = v8;
      v9 = *(float *)((char *)&v42.x + v4);
      rayEnd.x = v6;
      data.mOutput.m_shapeKeyIndex = 0;
      data.mOutput.m_shapeKeys[0] = -1;
      data.mOutput.m_rootCollidable = 0i64;
      v10 = v9 + v2->v3.z;
      rayEnd.y = v7;
      data.mDebugName = "PhysicsVehicle";
      data.mCollisionModelName.mUID = -1;
      rayEnd.z = v10;
      UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0x11u);
      v11 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
      if ( v11 )
        break;
      v4 += 4i64;
      if ( v4 >= 12 )
        goto LABEL_24;
    }
    v12 = data.normal.z;
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
          v12 = v12 + v46.normal.z;
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
        v12 = v12 * 0.14285715;
      }
      else
      {
        v23 = 1.0 / (float)v19;
        v12 = v23 * v16;
        v13 = v23 * v15;
        v14 = (float)(1.0 / (float)v19) * v20;
      }
    }
    v26 = LODWORD(v2->v0.y);
    v24 = v2->v0.z;
    v25 = *(float *)&v26;
    v27 = (__m128)LODWORD(v2->v0.x);
    *(float *)&v26 = (float)(*(float *)&v26 * v13) - (float)(v27.m128_f32[0] * v14);
    v27.m128_f32[0] = (float)(v27.m128_f32[0] * v12) - (float)(v24 * v13);
    v28 = (float)(v24 * v14) - (float)(v25 * v12);
    v29 = v27;
    v29.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v28 * v28))
                    + (float)(*(float *)&v26 * *(float *)&v26);
    if ( v29.m128_f32[0] == 0.0 )
      v30 = 0.0;
    else
      v30 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29));
    v31 = v27.m128_f32[0] * v30;
    *(float *)&v26 = *(float *)&v26 * v30;
    v32 = v28 * v30;
    v34 = (__m128)v26;
    v33 = (float)(v31 * v12) - (float)(*(float *)&v26 * v14);
    v34.m128_f32[0] = (float)(*(float *)&v26 * v13) - (float)(v32 * v12);
    v36 = v34;
    v35 = (float)(v32 * v14) - (float)(v31 * v13);
    v36.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v33 * v33)) + (float)(v35 * v35);
    if ( v36.m128_f32[0] == 0.0 )
      v37 = 0.0;
    else
      v37 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v36));
    v38 = data.point.x;
    v39 = data.point.y;
    v2->v2.w = 0.0;
    v2->v2.x = v13;
    v2->v2.y = v14;
    v2->v2.z = v12;
    v2->v3.w = 1.0;
    v2->v3.x = v38;
    v40 = data.point.z;
    v2->v3.y = v39;
    v2->v3.z = v40;
    v2->v0.z = v35 * v37;
    v2->v0.x = v33 * v37;
    v2->v0.w = 0.0;
    v2->v0.y = v34.m128_f32[0] * v37;
    v2->v1.y = v31;
    v2->v1.x = v32;
    v2->v1.w = 0.0;
    LODWORD(v2->v1.z) = v26;
LABEL_24:
    result = (UFG::PhysicsVehicle *)v11;
  }
  return result;
}

// File Line: 1958
// RVA: 0x475440
void __fastcall UFG::PhysicsVehicle::SetPositionAndOrientation(UFG::PhysicsVehicle *this, UFG::qMatrix44 *mat)
{
  UFG::PhysicsVehicle *v2; // rbx
  float v3; // xmm1_4
  float v4; // xmm0_4
  hkMatrix4f matrixIn; // [rsp+20h] [rbp-138h]
  hkMatrixDecompositionImpl<float>::Decomposition decompOut; // [rsp+60h] [rbp-F8h]

  v2 = this;
  if ( this->mRigidBody->mBody )
  {
    v3 = mat->v0.y;
    matrixIn.m_col0.m_quad.m128_i32[0] = LODWORD(mat->v0.x);
    *(unsigned __int64 *)((char *)matrixIn.m_col0.m_quad.m128_u64 + 4) = __PAIR__(LODWORD(mat->v0.z), LODWORD(v3));
    v4 = mat->v1.x;
    matrixIn.m_col0.m_quad.m128_i32[3] = LODWORD(mat->v0.w);
    matrixIn.m_col1.m_quad.m128_u64[0] = __PAIR__(LODWORD(mat->v1.y), LODWORD(v4));
    matrixIn.m_col1.m_quad.m128_u64[1] = *(_QWORD *)&mat->v1.z;
    matrixIn.m_col2 = (hkVector4f)mat->v2;
    matrixIn.m_col3 = (hkVector4f)mat->v3;
    hkMatrixDecompositionImpl<float>::decomposeMatrix(&matrixIn, &decompOut);
    hkpRigidBody::setPositionAndRotation(v2->mRigidBody->mBody, &decompOut.m_translation, &decompOut.m_rotation);
  }
}

// File Line: 1972
// RVA: 0x4681D0
UFG::qVector3 *__fastcall UFG::PhysicsVehicle::GetVelocity(UFG::PhysicsVehicle *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx

  v2 = result;
  UFG::RigidBody::GetVelocity((UFG::RigidBody *)&this->mRigidBody->vfptr, result);
  return v2;
}

// File Line: 1979
// RVA: 0x475850
void __fastcall UFG::PhysicsVehicle::SetVelocity(UFG::PhysicsVehicle *this, UFG::qVector3 *velocity)
{
  UFG::RigidBody::SetVelocity((UFG::RigidBody *)&this->mRigidBody->vfptr, velocity);
}

// File Line: 1986
// RVA: 0x4660D0
UFG::qVector3 *__fastcall UFG::PhysicsVehicle::GetAngularVelocity(UFG::PhysicsVehicle *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx

  v2 = result;
  UFG::RigidBody::GetAngularVelocity((UFG::RigidBody *)&this->mRigidBody->vfptr, result);
  return v2;
}

// File Line: 1994
// RVA: 0x4828B0
void __fastcall UFG::PhysicsVehicle::applyForce(UFG::PhysicsVehicle *this, const float deltaTime, hkVector4f *force, const char *dbgName)
{
  hkVector4f *v4; // rdi
  hkpRigidBody *v5; // rbx
  __int64 v6; // rdx

  v4 = force;
  v5 = this->mRigidBody->mBody;
  hkpEntity::activate((hkpEntity *)&v5->vfptr);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))v5->m_motion.vfptr[13].__vecDelDtor)(
    &v5->m_motion,
    v6,
    v4);
}

// File Line: 2009
// RVA: 0x482AE0
void __fastcall UFG::PhysicsVehicle::applyTorque(UFG::PhysicsVehicle *this, const float deltaTime, hkVector4f *torque, const char *dbgName)
{
  hkVector4f *v4; // rdi
  hkpRigidBody *v5; // rbx
  __int64 v6; // rdx

  v4 = torque;
  v5 = this->mRigidBody->mBody;
  hkpEntity::activate((hkpEntity *)&v5->vfptr);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))v5->m_motion.vfptr[13].__first_virtual_table_function__)(
    &v5->m_motion,
    v6,
    v4);
}

// File Line: 2024
// RVA: 0x482830
void __fastcall UFG::PhysicsVehicle::applyAngularImpulse(UFG::PhysicsVehicle *this, hkVector4f *imp, const char *dbgName)
{
  hkVector4f *v3; // rdi
  hkpRigidBody *v4; // rbx

  v3 = imp;
  v4 = this->mRigidBody->mBody;
  hkpEntity::activate((hkpEntity *)&v4->vfptr);
  v4->m_motion.vfptr[12].__vecDelDtor((hkBaseObject *)&v4->m_motion.vfptr, (unsigned int)v3);
}

// File Line: 2040
// RVA: 0x482940
void __fastcall UFG::PhysicsVehicle::applyLinearImpulse(UFG::PhysicsVehicle *this, hkVector4f *imp, const char *dbgName)
{
  hkVector4f *v3; // rdi
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  float v7; // xmm4_4
  hkpRigidBody *v8; // rbx

  v3 = imp;
  v4 = _mm_mul_ps(imp->m_quad, imp->m_quad);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v6 = _mm_rsqrt_ps(v5);
  LODWORD(v7) = (unsigned __int128)_mm_andnot_ps(
                                     _mm_cmpleps(v5, (__m128)0i64),
                                     _mm_mul_ps(
                                       _mm_mul_ps(
                                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v5), v6)),
                                         _mm_mul_ps(*(__m128 *)_xmm, v6)),
                                       v5));
  if ( v7 < 0.0 )
    LODWORD(v7) ^= _xmm[0];
  if ( v7 >= 0.1 )
  {
    v8 = this->mRigidBody->mBody;
    hkpEntity::activate((hkpEntity *)&v8->vfptr);
    v8->m_motion.vfptr[11].__vecDelDtor((hkBaseObject *)&v8->m_motion.vfptr, (unsigned int)v3);
  }
}

// File Line: 2058
// RVA: 0x482A30
void __fastcall UFG::PhysicsVehicle::applyPointImpulse(UFG::PhysicsVehicle *this, hkVector4f *imp, hkVector4f *p, const char *dbgName)
{
  hkVector4f *v4; // rdi
  hkVector4f *v5; // rsi
  hkpRigidBody *v6; // rbx

  v4 = p;
  v5 = imp;
  v6 = this->mRigidBody->mBody;
  hkpEntity::activate((hkpEntity *)&v6->vfptr);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkVector4f *))v6->m_motion.vfptr[11].__first_virtual_table_function__)(
    &v6->m_motion,
    v5,
    v4);
}

// File Line: 2073
// RVA: 0x488550
void __fastcall UFG::PhysicsVehicle::setAngularVelocity(UFG::PhysicsVehicle *this, hkVector4f *newVel, const char *dbgName)
{
  hkVector4f *v3; // rdi
  hkpRigidBody *v4; // rbx

  v3 = newVel;
  v4 = this->mRigidBody->mBody;
  hkpEntity::activate((hkpEntity *)&v4->vfptr);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v4->m_motion.vfptr[9].__first_virtual_table_function__)(
    &v4->m_motion,
    v3);
}

// File Line: 2088
// RVA: 0x4885D0
void __fastcall UFG::PhysicsVehicle::setLinearVelocity(UFG::PhysicsVehicle *this, hkVector4f *newVel, const char *dbgName)
{
  hkVector4f *v3; // rdi
  hkpRigidBody *v4; // rbx

  v3 = newVel;
  v4 = this->mRigidBody->mBody;
  hkpEntity::activate((hkpEntity *)&v4->vfptr);
  v4->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v4->m_motion.vfptr, (unsigned int)v3);
}

// File Line: 2104
// RVA: 0x482900
void __usercall UFG::PhysicsVehicle::applyForce(UFG::PhysicsVehicle *this@<rcx>, const float deltaTime@<xmm1>, UFG::qVector3 *force@<r8>, const char *dbgName@<r9>, __int64 a5@<rdx>)
{
  UFG::BasePhysicsObjectVtbl *v5; // rax
  __m128 v6; // [rsp+20h] [rbp-18h]

  v5 = this->vfptr;
  v6 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(force->x), (__m128)LODWORD(force->z)),
         _mm_unpacklo_ps((__m128)LODWORD(force->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __int64, __m128 *, const char *, unsigned __int64, unsigned __int64))v5[6].__vecDelDtor)(
    this,
    a5,
    &v6,
    dbgName,
    v6.m128_u64[0],
    v6.m128_u64[1]);
}

// File Line: 2110
// RVA: 0x482B30
void __usercall UFG::PhysicsVehicle::applyTorque(UFG::PhysicsVehicle *this@<rcx>, const float deltaTime@<xmm1>, UFG::qVector3 *torque@<r8>, const char *dbgName@<r9>, __int64 a5@<rdx>)
{
  UFG::BasePhysicsObjectVtbl *v5; // rax
  __m128 v6; // [rsp+20h] [rbp-18h]

  v5 = this->vfptr;
  v6 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(torque->x), (__m128)LODWORD(torque->z)),
         _mm_unpacklo_ps((__m128)LODWORD(torque->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __int64, __m128 *, const char *, unsigned __int64, unsigned __int64))v5[6].ResourceUnloaded)(
    this,
    a5,
    &v6,
    dbgName,
    v6.m128_u64[0],
    v6.m128_u64[1]);
}

// File Line: 2117
// RVA: 0x482870
void __fastcall UFG::PhysicsVehicle::applyAngularImpulse(UFG::PhysicsVehicle *this, UFG::qVector3 *imp, const char *dbgName)
{
  UFG::BasePhysicsObjectVtbl *v3; // rax
  __m128 v4; // [rsp+20h] [rbp-18h]

  v3 = this->vfptr;
  v4 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(imp->x), (__m128)LODWORD(imp->z)),
         _mm_unpacklo_ps((__m128)LODWORD(imp->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __m128 *, const char *))v3[7].DebugDraw)(this, &v4, dbgName);
}

// File Line: 2123
// RVA: 0x4829F0
void __fastcall UFG::PhysicsVehicle::applyLinearImpulse(UFG::PhysicsVehicle *this, UFG::qVector3 *imp, const char *dbgName)
{
  UFG::BasePhysicsObjectVtbl *v3; // rax
  __m128 v4; // [rsp+20h] [rbp-18h]

  v3 = this->vfptr;
  v4 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(imp->x), (__m128)LODWORD(imp->z)),
         _mm_unpacklo_ps((__m128)LODWORD(imp->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __m128 *, const char *))v3[8].__vecDelDtor)(this, &v4, dbgName);
}

// File Line: 2129
// RVA: 0x482A80
void __fastcall UFG::PhysicsVehicle::applyPointImpulse(UFG::PhysicsVehicle *this, UFG::qVector3 *imp, UFG::qVector3 *p, const char *dbgName)
{
  UFG::BasePhysicsObjectVtbl *v4; // rax
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // [rsp+20h] [rbp-28h]
  __m128 v8; // [rsp+30h] [rbp-18h]

  v4 = this->vfptr;
  v5 = (__m128)LODWORD(p->z);
  v6 = (__m128)LODWORD(p->y);
  v8 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(imp->x), (__m128)LODWORD(imp->z)),
         _mm_unpacklo_ps((__m128)LODWORD(imp->y), (__m128)0i64));
  v7 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)LODWORD(p->x), v5), _mm_unpacklo_ps(v6, (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __m128 *, __m128 *, const char *, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64))v4[8].ResourceUnloaded)(
    this,
    &v8,
    &v7,
    dbgName,
    v7.m128_u64[0],
    v7.m128_u64[1],
    v8.m128_u64[0],
    v8.m128_u64[1]);
}

// File Line: 2137
// RVA: 0x488590
void __fastcall UFG::PhysicsVehicle::setAngularVelocity(UFG::PhysicsVehicle *this, UFG::qVector3 *newVel, const char *dbgName)
{
  UFG::BasePhysicsObjectVtbl *v3; // rax
  __m128 v4; // [rsp+20h] [rbp-18h]

  v3 = this->vfptr;
  v4 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(newVel->x), (__m128)LODWORD(newVel->z)),
         _mm_unpacklo_ps((__m128)LODWORD(newVel->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __m128 *, const char *))v3[9].DebugDraw)(this, &v4, dbgName);
}

// File Line: 2143
// RVA: 0x488610
void __fastcall UFG::PhysicsVehicle::setLinearVelocity(UFG::PhysicsVehicle *this, UFG::qVector3 *newVel, const char *dbgName)
{
  UFG::BasePhysicsObjectVtbl *v3; // rax
  __m128 v4; // [rsp+20h] [rbp-18h]

  v3 = this->vfptr;
  v4 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(newVel->x), (__m128)LODWORD(newVel->z)),
         _mm_unpacklo_ps((__m128)LODWORD(newVel->y), (__m128)0i64));
  ((void (__fastcall *)(UFG::PhysicsVehicle *, __m128 *, const char *))v3[10].__vecDelDtor)(this, &v4, dbgName);
}

// File Line: 2167
// RVA: 0x44C7F0
void __usercall UFG::PhysicsWheeledVehicle::PhysicsWheeledVehicle(UFG::PhysicsWheeledVehicle *this@<rcx>, UFG::VehicleParams *param@<rdx>, UFG::qMatrix44 *transform@<r8>, UFG::qVector3 *velocity@<r9>, __m128 *a5@<xmm10>, UFG::qVector3 *wheelPositions)
{
  UFG::PhysicsWheeledVehicle *v6; // rdi
  hkpReorientAction *v7; // rbx
  unsigned int *v8; // rsi
  __m128 v9; // xmm6
  __m128 v10; // xmm0
  __m128 v11; // xmm13
  __m128 v12; // xmm6
  __m128 v13; // xmm0
  __m128 v14; // xmm14
  __m128 v15; // xmm10
  __m128 v16; // xmm11
  __m128 v17; // xmm12
  __m128 v18; // xmm7
  __m128 v19; // xmm8
  __m128 v20; // xmm9
  UFG::VehicleParams *v21; // rax
  __int64 v22; // r9
  __m128 v23; // xmm5
  _DWORD *v24; // rcx
  signed __int64 v25; // rdx
  float *v26; // r8
  __m128 v27; // xmm0
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  UFG::VehicleParams *v30; // rax
  __int64 v31; // r9
  __m128 v32; // xmm5
  _DWORD *v33; // rcx
  signed __int64 v34; // rdx
  float *v35; // r8
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  unsigned int v39; // edx
  _DWORD *v40; // rcx
  _QWORD **v41; // rax
  hkpReorientAction *v42; // rax
  hkpReorientAction *v43; // rax
  float v44; // [rsp+30h] [rbp-F8h]
  float v45; // [rsp+38h] [rbp-F0h]
  UFG::qReflectHandleBase v46; // [rsp+40h] [rbp-E8h]
  __int64 v47; // [rsp+68h] [rbp-C0h]
  hkVector4f rotationAxis; // [rsp+70h] [rbp-B8h]
  hkVector4f upAxis; // [rsp+80h] [rbp-A8h]

  v47 = -2i64;
  v6 = this;
  UFG::PhysicsVehicle::PhysicsVehicle((UFG::PhysicsVehicle *)&this->vfptr, param, transform, velocity, a5);
  v6->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsWheeledVehicle::`vftable;
  v7 = 0i64;
  v6->mWheelCollider = 0i64;
  v6->mHavokVehicle = 0i64;
  v6->mVehicleAction = 0i64;
  v6->mEngine = 0i64;
  v6->mTransmission = 0i64;
  v6->mBrakes = 0i64;
  v6->mSteering = 0i64;
  v6->mAerodynamics = 0i64;
  v6->mPreviousSpeed = 0.0;
  *((_DWORD *)v6 + 274) = *((_DWORD *)v6 + 274) & 0xFFFFFFB0 | 0x10;
  UFG::qReflectHandleBase::qReflectHandleBase(&v46);
  v46.mTypeUID = UFG::qStringHash64("UFG::WheeledVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v46, v46.mTypeUID, v6->mDnaDefinition.mData->mBaseNode.mUID);
  UFG::PhysicsWheeledVehicle::LoadProperties(v6);
  v8 = (unsigned int *)v46.mData;
  v6->mWheelRadius = *(float *)v46.mData[5].mBaseNode.mChildren;
  LODWORD(v6->mLodHeightFixupFront) = v8[163];
  LODWORD(v6->mLodHeightFixupRear) = v8[164];
  v9 = (__m128)v8[99];
  v9.m128_f32[0] = (float)(v9.m128_f32[0] * 3.1415927) * 0.0055555557;
  v44 = sinf(v9.m128_f32[0]);
  v10 = v9;
  v10.m128_f32[0] = cosf(v9.m128_f32[0]);
  v11 = v10;
  v12 = (__m128)v8[100];
  v12.m128_f32[0] = (float)(v12.m128_f32[0] * 3.1415927) * 0.0055555557;
  v45 = sinf(v12.m128_f32[0]);
  v13 = v12;
  v13.m128_f32[0] = cosf(v12.m128_f32[0]);
  v14 = v13;
  v15 = (__m128)v8[60];
  v16 = (__m128)v8[61];
  v17 = (__m128)v8[62];
  v18 = (__m128)v8[63];
  v19 = (__m128)v8[64];
  v20 = (__m128)v8[65];
  v21 = v6->mParams;
  v22 = v21->firstFrontWheel;
  if ( (signed int)v22 <= v21->lastFrontWheel )
  {
    v23 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)LODWORD(v44), _mm_xor_ps(v11, *(__m128 *)_xmm)), (__m128)0i64);
    v24 = (_DWORD *)&v6->mSuspensionUpTravelLimit.array[v22];
    v25 = (signed __int64)v6 + 16 * (v22 + 42);
    v26 = &wheelPositions->x + v22 + 2 * v22 + 1;
    do
    {
      *(__m128 *)(v25 + 64) = v23;
      v27 = v17;
      v27.m128_f32[0] = v17.m128_f32[0] + v26[1];
      v28 = v16;
      v28.m128_f32[0] = v16.m128_f32[0] + *v26;
      v29 = v15;
      v29.m128_f32[0] = v15.m128_f32[0] + *(v26 - 1);
      *(__m128 *)v25 = _mm_unpacklo_ps(_mm_unpacklo_ps(v29, v27), _mm_unpacklo_ps(v28, (__m128)(unsigned int)FLOAT_1_0));
      v27.m128_i32[0] = v8[165];
      *(v24 - 4) = v27.m128_i32[0];
      *v24 = v8[95];
      v24[4] = v8[97];
      *(v24 - 37) = v27.m128_i32[0];
      LODWORD(v22) = v22 + 1;
      v25 += 16i64;
      ++v24;
      v26 += 3;
    }
    while ( (signed int)v22 <= v6->mParams->lastFrontWheel );
  }
  v30 = v6->mParams;
  v31 = v30->firstRearWheel;
  if ( (signed int)v31 <= v30->lastRearWheel )
  {
    v32 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)LODWORD(v45), _mm_xor_ps(v14, *(__m128 *)_xmm)), (__m128)0i64);
    v33 = (_DWORD *)&v6->mSuspensionUpTravelLimit.array[v31];
    v34 = (signed __int64)v6 + 16 * (v31 + 42);
    v35 = &wheelPositions->x + v31 + 2 * v31 + 1;
    do
    {
      *(__m128 *)(v34 + 64) = v32;
      v36 = v20;
      v36.m128_f32[0] = v20.m128_f32[0] + v35[1];
      v37 = v19;
      v37.m128_f32[0] = v19.m128_f32[0] + *v35;
      v38 = v18;
      v38.m128_f32[0] = v18.m128_f32[0] + *(v35 - 1);
      *(__m128 *)v34 = _mm_unpacklo_ps(_mm_unpacklo_ps(v38, v36), _mm_unpacklo_ps(v37, (__m128)(unsigned int)FLOAT_1_0));
      v36.m128_i32[0] = v8[166];
      *(v33 - 4) = v36.m128_i32[0];
      *v33 = v8[96];
      v33[4] = v8[98];
      *(v33 - 37) = v36.m128_i32[0];
      LODWORD(v31) = v31 + 1;
      v34 += 16i64;
      ++v33;
      v35 += 3;
    }
    while ( (signed int)v31 <= v6->mParams->lastRearWheel );
  }
  v39 = 0;
  if ( *((_BYTE *)&v6->0 + 604) & 7 )
  {
    v40 = (_DWORD *)v6->mLateralSkidStrength.array;
    do
    {
      *(v40 - 8) = 0;
      *v40 = 0;
      *(v40 - 4) = 0;
      v40[33] = 0;
      v40[4] = 0;
      ++v39;
      ++v40;
    }
    while ( v39 < (*((_DWORD *)&v6->0 + 151) & 7u) );
  }
  if ( v6->mPitchStability > 0.0099999998 )
  {
    rotationAxis.m_quad = _xmm;
    upAxis.m_quad = _xmm;
    v41 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v42 = (hkpReorientAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v41[11] + 8i64))(v41[11], 112i64);
    if ( v42 )
    {
      hkpReorientAction::hkpReorientAction(v42, v6->mRigidBody->mBody, &rotationAxis, &upAxis, v6->mPitchStability, 0.1);
      v7 = v43;
    }
    v6->mReorientActionPitch = v7;
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v46);
}

// File Line: 2226
// RVA: 0x450930
void __fastcall UFG::PhysicsWheeledVehicle::~PhysicsWheeledVehicle(UFG::PhysicsWheeledVehicle *this)
{
  UFG::PhysicsWheeledVehicle *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsWheeledVehicle::`vftable;
  UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents(this);
  UFG::PhysicsVehicle::~PhysicsVehicle((UFG::PhysicsVehicle *)&v1->vfptr);
}

// File Line: 2233
// RVA: 0x472C20
void __fastcall UFG::PhysicsWheeledVehicle::Reload(UFG::PhysicsWheeledVehicle *this, UFG::qSymbol *propertySetName)
{
  UFG::PhysicsWheeledVehicle *v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax
  UFG::VehicleParams *v5; // rax
  signed __int64 v6; // r9
  signed __int64 v7; // r8
  UFG::VehicleParams *v8; // rax
  signed __int64 v9; // r8
  signed __int64 v10; // r9
  unsigned int v11; // er9
  __int64 v12; // r8
  hkpVehicleData::WheelComponentParams *v13; // rax
  UFG::qReflectObject *v14; // rdx
  UFG::VehicleAerodynamics *v15; // rcx
  UFG::qReflectHandleBase v16; // [rsp+48h] [rbp-30h]

  v2 = this;
  this->mParams->mPhysicsPropertiesName.mUID = propertySetName->mUID;
  v3 = this->mParams->mPhysicsPropertiesName.mUID;
  if ( v3 )
  {
    v4 = UFG::qBaseTreeRB::Get(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree, v3);
    if ( v4 )
      UFG::qReflectHandleBase::Init(
        (UFG::qReflectHandleBase *)&v2->mDnaDefinition.mPrev,
        v2->mDnaDefinition.mTypeUID,
        (unsigned __int64)v4->mNULL.mParent);
  }
  UFG::PhysicsVehicle::LoadProperties((UFG::PhysicsVehicle *)&v2->vfptr);
  UFG::PhysicsWheeledVehicle::LoadProperties(v2);
  if ( v2->mHavokVehicle )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v16);
    v16.mTypeUID = UFG::qStringHash64("UFG::WheeledVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v16, v16.mTypeUID, v2->mDnaDefinition.mData->mBaseNode.mUID);
    v2->mHavokVehicle->m_data->m_torqueRollFactor = *((float *)&v16.mData[5].mTypeUID + 1);
    v2->mHavokVehicle->m_data->m_torquePitchFactor = *(float *)&v16.mData[5].mHandles.mNode.mPrev;
    v2->mHavokVehicle->m_data->m_torqueYawFactor = *((float *)&v16.mData[5].mHandles.mNode.mPrev + 1);
    v2->mHavokVehicle->m_data->m_extraTorqueFactor = *(float *)&v16.mData[5].mHandles.mNode.mNext;
    v2->mHavokVehicle->m_data->m_maxVelocityForPositionalFriction = *((float *)v16.mData[8].mBaseNode.mChildren + 1);
    v2->mHavokVehicle->m_data->m_chassisUnitInertiaYaw = *(float *)&v16.mData[6].vfptr;
    v2->mHavokVehicle->m_data->m_chassisUnitInertiaRoll = *((float *)&v16.mData[6].vfptr + 1);
    v2->mHavokVehicle->m_data->m_chassisUnitInertiaPitch = *(float *)&v16.mData[6].mBaseNode.mUID;
    v5 = v2->mParams;
    v6 = v5->firstFrontWheel;
    if ( (signed int)v6 <= v5->lastFrontWheel )
    {
      v7 = v6;
      do
      {
        v2->mHavokVehicle->m_data->m_wheelParams.m_data[v7].m_friction = *((float *)v16.mData[5].mBaseNode.mChildren + 1);
        LODWORD(v6) = v6 + 1;
        ++v7;
      }
      while ( (signed int)v6 <= v2->mParams->lastFrontWheel );
    }
    v8 = v2->mParams;
    v9 = v8->firstRearWheel;
    if ( (signed int)v9 <= v8->lastRearWheel )
    {
      v10 = v9;
      do
      {
        v2->mHavokVehicle->m_data->m_wheelParams.m_data[v10].m_friction = *(float *)&v16.mData[5].mBaseNode.mChildren[1];
        LODWORD(v9) = v9 + 1;
        ++v10;
      }
      while ( (signed int)v9 <= v2->mParams->lastRearWheel );
    }
    v11 = 0;
    if ( *((_BYTE *)&v2->0 + 604) & 7 )
    {
      v12 = 0i64;
      do
      {
        v2->mHavokVehicle->m_data->m_wheelParams.m_data[v12].m_mass = *((float *)v16.mData[6].mBaseNode.mChildren + 1);
        v2->mHavokVehicle->m_data->m_wheelParams.m_data[v12].m_viscosityFriction = *(float *)&v16.mData[6].mBaseNode.mChildren[1];
        v2->mHavokVehicle->m_data->m_wheelParams.m_data[v12].m_slipAngle = *((float *)&v16.mData[6].mBaseNode.mChildren[1]
                                                                           + 1);
        v13 = v2->mHavokVehicle->m_data->m_wheelParams.m_data;
        v13[v12].m_maxFriction = v13[v12].m_friction * 2.0;
        ++v11;
        ++v12;
      }
      while ( v11 < (*((_DWORD *)&v2->0 + 151) & 7u) );
    }
    UFG::Engine::InitializeFromPropertySet(v2->mEngine, (UFG::WheeledVehiclePhysicsDef *)v16.mData);
    UFG::Transmission::InitializeFromPropertySet(
      v2->mTransmission,
      (UFG::WheeledVehiclePhysicsDef *)v16.mData,
      *((_DWORD *)&v2->0 + 151) & 7,
      v2->mParams->firstFrontWheel,
      v2->mParams->lastFrontWheel,
      v2->mParams->firstRearWheel,
      v2->mParams->lastRearWheel);
    UFG::Brakes::InitializeFromPropertySet(
      v2->mBrakes,
      (UFG::WheeledVehiclePhysicsDef *)v16.mData,
      *((_DWORD *)&v2->0 + 151) & 7,
      v2->mParams->firstFrontWheel,
      v2->mParams->lastFrontWheel,
      v2->mParams->firstRearWheel,
      v2->mParams->lastRearWheel);
    UFG::Steering::InitializeFromPropertySet(
      v2->mSteering,
      (UFG::WheeledVehiclePhysicsDef *)v16.mData,
      *((_DWORD *)&v2->0 + 151) & 7,
      v2->mParams->firstFrontWheel,
      v2->mParams->lastFrontWheel,
      v2->mParams->firstRearWheel,
      v2->mParams->lastRearWheel);
    v14 = v16.mData;
    v15 = v2->mAerodynamics;
    v15->m_airDensity = *((float *)v16.mData[6].mBaseNode.mNeighbours + 1);
    v15->m_frontalArea = *(float *)v14[5].mBaseNode.mNeighbours;
    v15->m_dragCoefficient = *((float *)v14[5].mBaseNode.mNeighbours + 1);
    v15->m_liftCoefficient = *(float *)&v14[5].mBaseNode.mNeighbours[1];
    UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
  }
}

// File Line: 2303
// RVA: 0x46BBB0
void __fastcall UFG::PhysicsWheeledVehicle::LoadProperties(UFG::PhysicsWheeledVehicle *this)
{
  UFG::PhysicsWheeledVehicle *v1; // rbx
  UFG::qReflectObject *v2; // rcx
  UFG::qReflectHandleBase v3; // [rsp+28h] [rbp-30h]

  v1 = this;
  UFG::qReflectHandleBase::qReflectHandleBase(&v3);
  v3.mTypeUID = UFG::qStringHash64("UFG::WheeledVehiclePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v3, v3.mTypeUID, v1->mDnaDefinition.mData->mBaseNode.mUID);
  v2 = v3.mData;
  v1->mBurnoutMinSpeed = *(float *)&v3.mData[7].mBaseNode.mUID;
  v1->mBurnoutMaxSpeed = *((float *)&v2[7].mBaseNode.mUID + 1);
  v1->mBurnoutSpinTorqueAtLowSpeed = *(float *)&v2[7].mBaseNode.mParent;
  v1->mBurnoutSpinTorqueAtHighSpeed = *((float *)&v2[7].mBaseNode.mParent + 1);
  v1->mBurnoutSpinFrontTireFrictionAtLowSpeed = *(float *)v2[7].mBaseNode.mChildren;
  v1->mBurnoutSpinFrontTireFrictionAtHighSpeed = *((float *)v2[7].mBaseNode.mChildren + 1);
  v1->mBurnoutSpinRearTireFrictionAtLowSpeed = *(float *)&v2[7].mBaseNode.mChildren[1];
  v1->mBurnoutSpinRearTireFrictionAtHighSpeed = *((float *)&v2[7].mBaseNode.mChildren[1] + 1);
  *((_DWORD *)v1 + 274) ^= (*((_DWORD *)v1 + 274) ^ 32 * LOBYTE(v2[8].mBaseNode.mChildren[1])) & 0x20;
  v1->mBurnoutTorqueFactor_LowSpeed = *(float *)v2[7].mBaseNode.mNeighbours;
  v1->mBurnoutFwdThrustFactor_LowSpeed = *((float *)v2[7].mBaseNode.mNeighbours + 1);
  v1->mBurnoutSideThrustFactor_LowSpeed = *(float *)&v2[7].mBaseNode.mNeighbours[1];
  v1->mBurnoutTorqueFactor_HighSpeed = *((float *)&v2[7].mBaseNode.mNeighbours[1] + 1);
  v1->mBurnoutFwdThrustFactor_HighSpeed = *(float *)&v2[7].mTypeUID;
  v1->mBurnoutSideThrustFactor_HighSpeed = *((float *)&v2[7].mTypeUID + 1);
  v1->mJTurnSpinTorque = *(float *)&v2[7].mHandles.mNode.mPrev;
  v1->mJTurnSpinFrontTireFriction = *((float *)&v2[7].mHandles.mNode.mPrev + 1);
  v1->mJTurnSpinRearTireFriction = *(float *)&v2[7].mHandles.mNode.mNext;
  v1->mBlownTireWobbleMagnitude = *((float *)&v2[7].mHandles.mNode.mNext + 1);
  v1->mBlownTireWobbleFrequency = *(float *)&v2[8].vfptr;
  v1->mBlownTireDrag = *((float *)&v2[8].vfptr + 1);
  v1->mBlownTireFrictionMultiplier = *(float *)&v2[8].mBaseNode.mUID;
  v1->mDollarValue = *(float *)&v2[1].mHandles.mNode.mPrev;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v3);
}

// File Line: 2342
// RVA: 0x47AFD0
void __fastcall UFG::PhysicsWheeledVehicle::Update(UFG::PhysicsWheeledVehicle *this, UFG::qMatrix44 *targetTransform, UFG::VehicleInput *driverInput, float deltaTime)
{
  UFG::VehicleInput *v4; // r14
  float v5; // xmm15_4
  UFG::qMatrix44 *v6; // rbx
  UFG::PhysicsWheeledVehicle *v7; // rdi
  UFG::WaterFloatingTrackerComponent *v8; // rax
  int v9; // eax
  hkpEntity *v10; // rcx
  signed int v11; // eax
  unsigned int v12; // esi
  float *v13; // rbx
  float v14; // xmm0_4
  hkpVehicleEngine *v15; // rcx
  float v16; // xmm3_4
  bool v17; // dl
  float v18; // xmm2_4
  float v19; // xmm0_4
  unsigned int v20; // er9
  __int64 v21; // rdx
  signed __int64 v22; // r8
  hkpVehicleInstance::WheelInfo *v23; // rcx
  float v24; // xmm9_4
  float v25; // xmm14_4
  hkpVehicleWheelCollide *v26; // rdx
  signed __int64 v27; // r8
  hkpVehicleWheelCollide *v28; // rcx
  int v29; // eax
  float v30; // xmm0_4
  float v31; // xmm0_4
  int v32; // xmm12_4
  float v33; // xmm13_4
  UFG::Engine *v34; // rax
  float v35; // xmm1_4
  float v36; // xmm2_4
  __m128 v37; // xmm6
  float v38; // xmm3_4
  float v39; // xmm4_4
  float v40; // xmm8_4
  float v41; // xmm5_4
  float v42; // xmm10_4
  float v43; // xmm0_4
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm5_4
  float v47; // xmm9_4
  float v48; // xmm8_4
  float v49; // xmm1_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float v52; // xmm5_4
  float v53; // xmm9_4
  float v54; // xmm8_4
  float v55; // xmm3_4
  float v56; // xmm11_4
  UFG::VehicleParams *v57; // rax
  int v58; // ecx
  UFG::VehicleParams *v59; // rax
  int v60; // ecx
  float v61; // xmm9_4
  float v62; // xmm9_4
  UFG::VehicleParams *v63; // rax
  __int64 v64; // rdx
  __int64 v65; // rcx
  UFG::RigidBodyComponent *v66; // rax
  float v67; // xmm0_4
  float v68; // xmm3_4
  float v69; // xmm4_4
  float v70; // xmm5_4
  __m128 v71; // xmm12
  __m128 v72; // xmm8
  float v73; // xmm1_4
  __m128 v74; // xmm2
  float v75; // xmm0_4
  float v76; // xmm1_4
  float v77; // xmm13_4
  float v78; // xmm12_4
  float v79; // xmm3_4
  float v80; // xmm8_4
  float v81; // xmm0_4
  float v82; // xmm1_4
  __m128 v83; // xmm12
  __m128 v84; // xmm3
  float v85; // xmm4_4
  UFG::RigidBodyComponent *v86; // rax
  hkpEntity *v87; // rbx
  __int64 v88; // rdx
  UFG::BasePhysicsObjectVtbl *v89; // rax
  __m128 v90; // xmm0
  __m128 v91; // xmm3
  __int64 v92; // rdx
  __m128 v93; // xmm0
  UFG::BasePhysicsObjectVtbl *v94; // rax
  __m128 v95; // xmm3
  hkpVehicleDriverInputStatus *v96; // rbx
  __int64 v97; // rdx
  __m128 v98; // xmm2
  float v99; // xmm8_4
  int v100; // eax
  int v101; // xmm0_4
  __m128 v102; // xmm3
  __m128 v103; // xmm6
  __m128 v104; // xmm2
  UFG::BasePhysicsObjectVtbl *v105; // rax
  __m128 v106; // xmm4
  float v107; // xmm5_4
  unsigned int v108; // edx
  unsigned int v109; // er10
  UFG::VehicleInstance *v110; // r8
  __int64 v111; // rcx
  __int64 v112; // r9
  float v113; // xmm0_4
  UFG::qVector4 v114; // xmm3
  UFG::qVector4 v115; // xmm2
  UFG::qVector4 v116; // xmm1
  UFG::Engine *v117; // rcx
  float v118; // xmm1_4
  __m128 v119; // xmm0
  UFG::RigidBodyComponent *v120; // rax
  __m128 v121; // xmm3
  hkpRigidBody *v122; // rbx
  __int64 v123; // rdx
  UFG::VehicleParams *v124; // rax
  int v125; // ecx
  hkpVehicleWheelCollide *v126; // rdx
  float v127; // xmm0_4
  UFG::VehicleParams *v128; // rax
  int v129; // ecx
  hkpVehicleWheelCollide *v130; // rdx
  float v131; // xmm0_4
  UFG::BasePhysicsObjectVtbl *v132; // rax
  __m128 v133; // xmm2
  UFG::qVector3 result; // [rsp+20h] [rbp-108h]
  hkVector4f b; // [rsp+30h] [rbp-F8h]
  hkVector4f v136; // [rsp+40h] [rbp-E8h]
  hkVector4f v137; // [rsp+50h] [rbp-D8h]
  hkVector4f v138; // [rsp+60h] [rbp-C8h]
  __m128 v139; // [rsp+70h] [rbp-B8h]

  v4 = driverInput;
  v5 = deltaTime;
  v6 = targetTransform;
  v7 = this;
  if ( !this->mRigidBody->mBody )
    UFG::qPrintf("PhysicsWheeledVehicle %x is missing its rigid body\n", this);
  UFG::PhysicsVehicle::Update((UFG::PhysicsVehicle *)&v7->vfptr, v6, v4, deltaTime);
  v8 = v7->mWaterFloatingTrackerComponent;
  if ( v8 )
  {
    v9 = v8->mInWaterState;
    if ( v9 > 0 && v9 != 2 )
    {
      v10 = (hkpEntity *)&v7->mRigidBody->mBody->vfptr;
      if ( v10 )
        hkpEntity::activate(v10);
    }
  }
  v11 = v7->mCurrentLod;
  if ( v11 > 0 )
  {
    if ( v11 <= 2 )
    {
LABEL_12:
      v12 = 0;
      if ( *((_BYTE *)&v7->0 + 604) & 7 )
      {
        v13 = v7->mCurrentSuspensionLength.array;
        do
        {
          *v13 = (float)((float)((float)(v13[33] - *v13) * 0.30000001) * deltaTime) + *v13;
          v14 = fmodf(
                  (float)((float)((float)(v7->mSpeedKPH * 0.27777779) * deltaTime) / v7->mWheelRadius) + v13[16],
                  6.2831855);
          ++v12;
          ++v13;
          v13[15] = v14;
        }
        while ( v12 < (*((_DWORD *)&v7->0 + 151) & 7u) );
      }
      return;
    }
    if ( v11 != 3 )
    {
      if ( v11 != 4 )
        return;
      goto LABEL_12;
    }
    v15 = v7->mHavokVehicle->m_engine;
    *(_DWORD *)(&v15[4].m_referenceCount + 1) = 0;
    v16 = v7->mSpeedKPH;
    v17 = v16 < 0.0 && (*((_DWORD *)&v7->0 + 151) & 7) == 2;
    if ( (*((_DWORD *)v7 + 274) >> 4) & 1 )
    {
      if ( !v17 )
      {
        v18 = v7->mBodyTransform.v0.z;
        if ( v18 > 0.0 )
        {
          v19 = (float)(*(float *)(&v15[1].m_referenceCount + 1) * UFG::PhysicsWheeledVehicle::mHillTorqueBoost) * v18;
          if ( v16 < 75.0 )
            v19 = v19
                + (float)((float)(*(float *)(&v15[1].m_referenceCount + 1)
                                * UFG::PhysicsWheeledVehicle::mHillTorqueBoostLowSpeed)
                        * v18);
          *(float *)(&v15[4].m_referenceCount + 1) = v19;
        }
      }
    }
    v20 = 0;
    if ( *((_BYTE *)&v7->0 + 604) & 7 )
    {
      v21 = 0i64;
      v22 = (signed __int64)&v7->mWheelSpinAngle;
      do
      {
        ++v20;
        v22 += 4i64;
        v23 = v7->mHavokVehicle->m_wheelsInfo.m_data;
        ++v21;
        *(_DWORD *)(v22 - 68) = *((_DWORD *)&v23[v21] - 28);
        *(_DWORD *)(v22 - 4) = *((_DWORD *)&v23[v21] - 6);
      }
      while ( v20 < (*((_DWORD *)&v7->0 + 151) & 7u) );
    }
    v24 = FLOAT_0_5;
    v25 = *(float *)&FLOAT_1_0;
    v26 = 0i64;
    if ( *((_BYTE *)&v7->0 + 604) & 7 )
    {
      v27 = 184i64;
      do
      {
        v28 = v7->mWheelCollider;
        v29 = *((_DWORD *)&v7->0 + 151) & 7;
        if ( v29 == 2 )
        {
          if ( !v28 )
            goto LABEL_36;
          v30 = *(float *)(&v28->m_alreadyUsed.m_bool + v27);
        }
        else
        {
          if ( !v28 )
          {
LABEL_36:
            v30 = 0.0;
            goto LABEL_37;
          }
          v30 = *(float *)((char *)&v28->vfptr + v27);
        }
LABEL_37:
        v31 = v30 + (float)(v5 * 0.5);
        if ( v31 > 1.0 )
          v31 = *(float *)&FLOAT_1_0;
        if ( v28 )
        {
          if ( v29 == 2 )
            *((float *)&v28[8].m_memSizeAndFlags + (unsigned int)v26) = v31;
          else
            *((float *)&v28[7].m_alreadyUsed.m_bool + (unsigned int)v26) = v31;
        }
        v26 = (hkpVehicleWheelCollide *)(unsigned int)((_DWORD)v26 + 1);
        v27 += 4i64;
      }
      while ( (unsigned int)v26 < (*((_DWORD *)&v7->0 + 151) & 7u) );
    }
    v32 = _xmm;
    v33 = FLOAT_N1_0;
    if ( *((_BYTE *)v4 + 16) & 0x20 )
    {
      v34 = v7->mEngine;
      if ( !v34 || v34->mDamage < 1.0 )
      {
        v35 = v7->mBurnoutSpinFrontTireFrictionAtHighSpeed;
        v36 = v7->mBurnoutSpinFrontTireFrictionAtLowSpeed;
        v37 = _mm_and_ps((__m128)LODWORD(v7->mSpeedKPH), (__m128)(unsigned int)_xmm);
        v38 = v7->mBurnoutMaxSpeed * v7->mBurnoutMaxSpeed;
        v39 = v7->mBurnoutMinSpeed * v7->mBurnoutMinSpeed;
        if ( v36 >= v35 )
          v40 = v7->mBurnoutSpinFrontTireFrictionAtHighSpeed;
        else
          v40 = v7->mBurnoutSpinFrontTireFrictionAtLowSpeed;
        if ( v36 <= v35 )
          v41 = v7->mBurnoutSpinFrontTireFrictionAtHighSpeed;
        else
          v41 = v7->mBurnoutSpinFrontTireFrictionAtLowSpeed;
        v42 = FLOAT_0_000099999997;
        v43 = v38 - v39;
        if ( (float)(v38 - v39) < 0.000099999997 )
          v43 = FLOAT_0_000099999997;
        v37.m128_f32[0] = v37.m128_f32[0] * v37.m128_f32[0];
        v44 = (float)((float)(v37.m128_f32[0] - v39) * (float)((float)(v35 - v36) / v43)) + v36;
        if ( v44 <= v40 )
          v44 = v40;
        if ( v44 >= v41 )
          v44 = v41;
        v45 = v7->mBurnoutSpinRearTireFrictionAtHighSpeed;
        v46 = v7->mBurnoutSpinRearTireFrictionAtLowSpeed;
        if ( v46 >= v45 )
          v47 = v7->mBurnoutSpinRearTireFrictionAtHighSpeed;
        else
          v47 = v7->mBurnoutSpinRearTireFrictionAtLowSpeed;
        if ( v46 <= v45 )
          v48 = v7->mBurnoutSpinRearTireFrictionAtHighSpeed;
        else
          v48 = v7->mBurnoutSpinRearTireFrictionAtLowSpeed;
        v49 = v38 - v39;
        if ( (float)(v38 - v39) < 0.000099999997 )
          v49 = FLOAT_0_000099999997;
        v50 = (float)((float)(v37.m128_f32[0] - v39) * (float)((float)(v45 - v46) / v49)) + v46;
        if ( v50 <= v47 )
          v50 = v47;
        if ( v50 >= v48 )
          v50 = v48;
        v51 = v7->mBurnoutSpinTorqueAtHighSpeed;
        v52 = v7->mBurnoutSpinTorqueAtLowSpeed;
        if ( v52 >= v51 )
          v53 = v7->mBurnoutSpinTorqueAtHighSpeed;
        else
          v53 = v7->mBurnoutSpinTorqueAtLowSpeed;
        if ( v52 <= v51 )
          v54 = v7->mBurnoutSpinTorqueAtHighSpeed;
        else
          v54 = v7->mBurnoutSpinTorqueAtLowSpeed;
        v55 = v38 - v39;
        if ( v55 < 0.000099999997 )
          v55 = FLOAT_0_000099999997;
        v56 = (float)((float)(v37.m128_f32[0] - v39) * (float)((float)(v51 - v52) / v55)) + v52;
        if ( v56 <= v53 )
          v56 = v53;
        if ( v56 >= v54 )
          v56 = v54;
        v57 = v7->mParams;
        v58 = v57->firstFrontWheel;
        if ( v58 <= v57->lastFrontWheel )
        {
          do
          {
            v26 = v7->mWheelCollider;
            if ( v26 )
            {
              if ( (*((_DWORD *)&v7->0 + 151) & 7) == 2 )
                *((float *)&v26[8].m_memSizeAndFlags + (unsigned int)v58) = v44;
              else
                *((float *)&v26[7].m_alreadyUsed.m_bool + (unsigned int)v58) = v44;
            }
            ++v58;
          }
          while ( v58 <= v7->mParams->lastFrontWheel );
        }
        v59 = v7->mParams;
        v60 = v59->firstRearWheel;
        if ( v60 <= v59->lastRearWheel )
        {
          do
          {
            v26 = v7->mWheelCollider;
            if ( v26 )
            {
              if ( (*((_DWORD *)&v7->0 + 151) & 7) == 2 )
                *((float *)&v26[8].m_memSizeAndFlags + (unsigned int)v60) = v50;
              else
                *((float *)&v26[7].m_alreadyUsed.m_bool + (unsigned int)v60) = v50;
            }
            ++v60;
          }
          while ( v60 <= v7->mParams->lastRearWheel );
        }
        if ( v4->mSteering <= 0.0 )
        {
          if ( v4->mSteering >= 0.0 )
            v61 = 0.0;
          else
            v61 = FLOAT_N1_0;
        }
        else
        {
          v61 = *(float *)&FLOAT_1_0;
        }
        LODWORD(v62) = COERCE_UNSIGNED_INT(v61 * v56) ^ _xmm[0];
        if ( *((_BYTE *)v7 + 1096) & 0x20 )
        {
          v63 = v7->mParams;
          v64 = v63->lastRearWheel;
          v65 = v63->firstRearWheel;
          v66 = v7->mRigidBody;
          b.m_quad = _mm_mul_ps(
                       _mm_add_ps(*((__m128 *)&v7->vfptr + v64 + 42), *((__m128 *)&v7->vfptr + v65 + 42)),
                       *(__m128 *)_xmm);
          hkVector4f::setTransformedPos(&v137, &v66->mBody->m_motion.m_motionState.m_transform, &b);
          v67 = v7->mBurnoutSideThrustFactor_HighSpeed;
          v68 = v7->mBurnoutSideThrustFactor_LowSpeed;
          v69 = v7->mBurnoutMaxSpeed * v7->mBurnoutMaxSpeed;
          v70 = v7->mBurnoutMinSpeed * v7->mBurnoutMinSpeed;
          if ( v68 >= v67 )
            v71 = (__m128)LODWORD(v7->mBurnoutSideThrustFactor_HighSpeed);
          else
            v71 = (__m128)LODWORD(v7->mBurnoutSideThrustFactor_LowSpeed);
          if ( v68 <= v67 )
            v72 = (__m128)LODWORD(v7->mBurnoutSideThrustFactor_HighSpeed);
          else
            v72 = (__m128)LODWORD(v7->mBurnoutSideThrustFactor_LowSpeed);
          v73 = v69 - v70;
          if ( (float)(v69 - v70) < 0.000099999997 )
            v73 = FLOAT_0_000099999997;
          v74 = v37;
          v74.m128_f32[0] = (float)((float)(v37.m128_f32[0] - v70) * (float)((float)(v67 - v68) / v73)) + v68;
          if ( v74.m128_f32[0] <= v71.m128_f32[0] )
            v74 = v71;
          if ( v74.m128_f32[0] >= v72.m128_f32[0] )
            v74 = v72;
          v75 = v7->mBurnoutTorqueFactor_HighSpeed;
          v76 = v7->mBurnoutTorqueFactor_LowSpeed;
          if ( v76 >= v75 )
            v77 = v7->mBurnoutTorqueFactor_HighSpeed;
          else
            v77 = v7->mBurnoutTorqueFactor_LowSpeed;
          if ( v76 <= v75 )
            v78 = v7->mBurnoutTorqueFactor_HighSpeed;
          else
            v78 = v7->mBurnoutTorqueFactor_LowSpeed;
          v79 = v69 - v70;
          if ( (float)(v69 - v70) < 0.000099999997 )
            v79 = FLOAT_0_000099999997;
          v80 = (float)((float)(v37.m128_f32[0] - v70) * (float)((float)(v75 - v76) / v79)) + v76;
          if ( v80 <= v77 )
            v80 = v77;
          if ( v80 >= v78 )
            v80 = v78;
          v81 = v7->mBurnoutFwdThrustFactor_HighSpeed;
          v82 = v7->mBurnoutFwdThrustFactor_LowSpeed;
          if ( v82 >= v81 )
            v83 = (__m128)LODWORD(v7->mBurnoutFwdThrustFactor_HighSpeed);
          else
            v83 = (__m128)LODWORD(v7->mBurnoutFwdThrustFactor_LowSpeed);
          if ( v82 <= v81 )
            v84 = (__m128)LODWORD(v7->mBurnoutFwdThrustFactor_HighSpeed);
          else
            v84 = (__m128)LODWORD(v7->mBurnoutFwdThrustFactor_LowSpeed);
          v85 = v69 - v70;
          if ( v85 >= 0.000099999997 )
            v42 = v85;
          v37.m128_f32[0] = (float)((float)(v37.m128_f32[0] - v70) * (float)((float)(v81 - v82) / v42)) + v82;
          if ( v37.m128_f32[0] <= v83.m128_f32[0] )
            v37 = v83;
          if ( v37.m128_f32[0] >= v84.m128_f32[0] )
            v37 = v84;
          v32 = _xmm;
          v86 = v7->mRigidBody;
          v74.m128_f32[0] = v74.m128_f32[0] * v62;
          v37.m128_f32[0] = (float)(v37.m128_f32[0] * v56) * v4->mSteering;
          v136.m_quad = _mm_add_ps(
                          _mm_unpacklo_ps(
                            _mm_unpacklo_ps(_mm_and_ps(v37, (__m128)(unsigned int)_xmm), (__m128)0i64),
                            (__m128)0i64),
                          _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps(_mm_xor_ps(v74, *(__m128 *)_xmm), (__m128)0i64)));
          hkVector4f::setTransformedPos(&v138, &v86->mBody->m_motion.m_motionState.m_transform, &v136);
          v87 = (hkpEntity *)&v7->mRigidBody->mBody->vfptr;
          hkpEntity::activate(v87);
          ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *, hkVector4f *))v87->m_motion.vfptr[12].__first_virtual_table_function__)(
            &v87->m_motion,
            v88,
            &v138,
            &v137);
          v89 = v7->vfptr;
          v90 = (__m128)LODWORD(v7->mBodyTransform.v2.z);
          v91 = _mm_unpacklo_ps((__m128)LODWORD(v7->mBodyTransform.v2.x), v90);
          v90.m128_f32[0] = v80 * v62;
          v139 = _mm_mul_ps(
                   _mm_unpacklo_ps(v91, _mm_unpacklo_ps((__m128)LODWORD(v7->mBodyTransform.v2.y), (__m128)0i64)),
                   _mm_shuffle_ps(v90, v90, 0));
          ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, __int64, __m128 *, const char *))v89[6].ResourceUnloaded)(
            v7,
            v92,
            &v139,
            "Burnout");
          v33 = FLOAT_N1_0;
        }
        else
        {
          v93 = (__m128)LODWORD(v7->mBodyTransform.v2.z);
          v94 = v7->vfptr;
          v95 = _mm_unpacklo_ps((__m128)LODWORD(v7->mBodyTransform.v2.x), v93);
          v93.m128_f32[0] = v62;
          v139 = _mm_mul_ps(
                   _mm_unpacklo_ps(v95, _mm_unpacklo_ps((__m128)LODWORD(v7->mBodyTransform.v2.y), (__m128)0i64)),
                   _mm_shuffle_ps(v93, v93, 0));
          ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, hkpVehicleWheelCollide *, __m128 *, const char *))v94[6].ResourceUnloaded)(
            v7,
            v26,
            &v139,
            "Burnout");
        }
        v24 = FLOAT_0_5;
      }
    }
    v96 = v7->mHavokVehicle->m_deviceStatus;
    *(float *)&v96[1].vfptr = v4->mSteering;
    HIDWORD(v96[1].vfptr) = LODWORD(v4->mGasBrakes);
    LOBYTE(v96[1].m_memSizeAndFlags) = (*((_DWORD *)v4 + 4) >> 2) & 1;
    HIBYTE(v96[1].m_memSizeAndFlags) = *((_BYTE *)v4 + 16) & 1;
    *((_DWORD *)v7->mTransmission + 26) ^= (*((_DWORD *)v7->mTransmission + 26) ^ (*((_DWORD *)v4 + 4) >> 1)) & 1;
    UFG::RigidBody::GetVelocity((UFG::RigidBody *)&v7->mRigidBody->vfptr, &result);
    v98 = (__m128)LODWORD(result.x);
    v98.m128_f32[0] = (float)((float)(v98.m128_f32[0] * v98.m128_f32[0]) + (float)(result.y * result.y))
                    + (float)(result.z * result.z);
    v99 = COERCE_FLOAT(_mm_sqrt_ps(v98)) - v7->mPreviousSpeed;
    if ( COERCE_FLOAT(LODWORD(v7->mSpeedKPH) & v32) < 1.5 )
    {
      if ( *((_BYTE *)v7 + 1096) & 0x10 )
      {
        if ( (float)(COERCE_FLOAT(LODWORD(v99) & v32) / v5) < 3.0 )
        {
          v100 = *((_DWORD *)v4 + 4);
          if ( !(v100 & 0x20)
            && !(v100 & 0x10)
            && (!(v100 & 8) || _bittest(&v100, 8u))
            && COERCE_FLOAT(LODWORD(v4->mGasBrakes) & v32) <= 0.0099999998
            && COERCE_FLOAT(LODWORD(v4->mRawGasBrakes) & v32) <= 0.0099999998 )
          {
            LOBYTE(v96[1].m_memSizeAndFlags) = 1;
          }
        }
      }
    }
    if ( (*((_DWORD *)v7 + 274) >> 3) & 1 )
    {
      v101 = LODWORD(v4->mSteering) & v32;
      if ( *(float *)&v101 > 0.25 )
      {
        v102 = (__m128)LODWORD(v7->mBodyTransform.v1.z);
        v103 = (__m128)LODWORD(v7->mBodyTransform.v1.x);
        v104 = (__m128)LODWORD(v7->mBodyTransform.v1.w);
        v105 = v7->vfptr;
        v106 = (__m128)LODWORD(v7->mBodyTransform.v1.y);
        v107 = (float)((float)(v33 / *(float *)&v101) * v4->mSteering) * v7->mAirSteerYawRate;
        v103.m128_f32[0] = (float)((float)((float)(v103.m128_f32[0] + v7->mBodyTransform.v0.x) * 0.0)
                                 + (float)(v107 * v7->mBodyTransform.v2.x))
                         + (float)(v7->mBodyTransform.v3.x * 0.0);
        v106.m128_f32[0] = (float)((float)((float)(v106.m128_f32[0] + v7->mBodyTransform.v0.y) * 0.0)
                                 + (float)(v107 * v7->mBodyTransform.v2.y))
                         + (float)(v7->mBodyTransform.v3.y * 0.0);
        v102.m128_f32[0] = (float)((float)((float)(v102.m128_f32[0] + v7->mBodyTransform.v0.z) * 0.0)
                                 + (float)(v107 * v7->mBodyTransform.v2.z))
                         + (float)(v7->mBodyTransform.v3.z * 0.0);
        v104.m128_f32[0] = (float)((float)((float)(v104.m128_f32[0] + v7->mBodyTransform.v0.w) * 0.0)
                                 + (float)(v107 * v7->mBodyTransform.v2.w))
                         + (float)(v7->mBodyTransform.v3.w * 0.0);
        v139 = _mm_unpacklo_ps(_mm_unpacklo_ps(v103, v102), _mm_unpacklo_ps(v106, v104));
        ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, __int64, __m128 *, const char *))v105[6].ResourceUnloaded)(
          v7,
          v97,
          &v139,
          "Air Steer");
      }
    }
    v108 = 0;
    v109 = *((_DWORD *)&v7->0 + 151) & 7;
    if ( v109 )
    {
      v110 = v7->mHavokVehicle;
      v111 = 0i64;
      v112 = v109;
      do
      {
        if ( !v110 || v110->m_wheelsInfo.m_data[v111].m_contactBody != 0i64 )
          ++v108;
        ++v111;
        --v112;
      }
      while ( v112 );
    }
    *((_DWORD *)v7 + 274) &= 0xFFFFFFE7;
    *((_DWORD *)v7 + 274) |= 8 * ((v108 == 0) | 2 * (v108 == v109));
    if ( *((_BYTE *)v7 + 1096) & 0x10 )
    {
      v113 = v5 + v7->mLastGoodPositionSampleTimer;
      v7->mLastGoodPositionSampleTimer = v113;
      if ( v113 > 2.0 )
      {
        v7->mLastGoodPositionSampleTimer = 0.0;
        v114 = v7->mBodyTransform.v1;
        v115 = v7->mBodyTransform.v2;
        v116 = v7->mBodyTransform.v3;
        v7->mLastGoodPosition.v0 = v7->mBodyTransform.v0;
        v7->mLastGoodPosition.v1 = v114;
        v7->mLastGoodPosition.v2 = v115;
        v7->mLastGoodPosition.v3 = v116;
      }
    }
    else
    {
      v7->mLastGoodPositionSampleTimer = 0.0;
    }
    v117 = v7->mEngine;
    if ( v7->mSpeedKPH >= 0.0 )
    {
      v117->mGovernorSpeedKPH = v7->mHighSpeedGovernor;
    }
    else
    {
      v117->mGovernorSpeedKPH = v7->mReverseSpeedGovernor;
      if ( v108 >= (*((_DWORD *)&v7->0 + 151) & 7u) - 1 && v7->mSpeedKPH < -10.0 )
      {
        v118 = v4->mSteering;
        if ( COERCE_FLOAT(LODWORD(v4->mSteering) & v32) > v24 )
        {
          if ( v118 <= 0.0 )
          {
            if ( v118 >= 0.0 )
              v25 = 0.0;
            else
              v25 = v33;
          }
          v119 = (__m128)LODWORD(v7->mBodyTransform.v2.z);
          v120 = v7->mRigidBody;
          v121 = _mm_unpacklo_ps((__m128)LODWORD(v7->mBodyTransform.v2.x), v119);
          v119.m128_f32[0] = v25 * v7->mJTurnSpinTorque;
          v139 = _mm_mul_ps(
                   _mm_unpacklo_ps(v121, _mm_unpacklo_ps((__m128)LODWORD(v7->mBodyTransform.v2.y), (__m128)0i64)),
                   _mm_shuffle_ps(v119, v119, 0));
          v122 = v120->mBody;
          hkpEntity::activate((hkpEntity *)&v120->mBody->vfptr);
          ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *))v122->m_motion.vfptr[13].__first_virtual_table_function__)(
            &v122->m_motion,
            v123,
            &v139);
          v124 = v7->mParams;
          v125 = v124->firstFrontWheel;
          if ( v125 <= v124->lastFrontWheel )
          {
            do
            {
              v126 = v7->mWheelCollider;
              v127 = v7->mJTurnSpinFrontTireFriction;
              if ( v126 )
              {
                if ( (*((_DWORD *)&v7->0 + 151) & 7) == 2 )
                  *((float *)&v126[8].m_memSizeAndFlags + (unsigned int)v125) = v127;
                else
                  *((float *)&v126[7].m_alreadyUsed.m_bool + (unsigned int)v125) = v127;
              }
              ++v125;
            }
            while ( v125 <= v7->mParams->lastFrontWheel );
          }
          v128 = v7->mParams;
          v129 = v128->firstRearWheel;
          if ( v129 <= v128->lastRearWheel )
          {
            do
            {
              v130 = v7->mWheelCollider;
              v131 = v7->mJTurnSpinRearTireFriction;
              if ( v130 )
              {
                if ( (*((_DWORD *)&v7->0 + 151) & 7) == 2 )
                  *((float *)&v130[8].m_memSizeAndFlags + (unsigned int)v129) = v131;
                else
                  *((float *)&v130[7].m_alreadyUsed.m_bool + (unsigned int)v129) = v131;
              }
              ++v129;
            }
            while ( v129 <= v7->mParams->lastRearWheel );
          }
        }
      }
    }
    UFG::PhysicsWheeledVehicle::UpdateSkids(v7, v4, v99);
    v132 = v7->vfptr;
    v133 = (__m128)LODWORD(result.x);
    v133.m128_f32[0] = (float)((float)(v133.m128_f32[0] * v133.m128_f32[0]) + (float)(result.y * result.y))
                     + (float)(result.z * result.z);
    LODWORD(v7->mPreviousSpeed) = (unsigned __int128)_mm_sqrt_ps(v133);
    ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, UFG::VehicleInput *))v132[10].DebugDraw)(v7, v4);
  }
}m_alreadyUsed.m_bool + (unsigned int)v129) = v131;
              }
              ++v129;
            }
            while ( v129 <= v7->mParams->lastRearWheel );
          }
        }
      }
    }
    UFG::PhysicsWheeledVehicle::UpdateSkids(v7, v4, v99);
    v132 = v7->vfptr;
    v133 = (__m128)LODWORD(result.x);
    v133.m128_f32[0] = (float)((float)(v133.m128_f32[0] * v133.m128_f32[0]) + (float)(result.y * result.y))
                     + (float)(result.z * result.z);
    LODWORD(v7->mPreviousSpeed) = (unsigned __int128)_mm_sqrt_ps(v133);
    ((void (__fastcall *)(UFG::PhysicsWheeledVehicle *, UFG::Vehicl

// File Line: 2599
// RVA: 0x466BF0
__int64 __fastcall UFG::PhysicsWheeledVehicle::GetNumWheelsOnGround(UFG::PhysicsWheeledVehicle *this)
{
  __int64 result; // rax
  __int64 v2; // r8
  UFG::VehicleInstance *v3; // r9
  __int64 v4; // rdx

  result = 0i64;
  v2 = *((_DWORD *)&this->0 + 151) & 7;
  if ( *((_DWORD *)&this->0 + 151) & 7 )
  {
    v3 = this->mHavokVehicle;
    v4 = 0i64;
    do
    {
      if ( !v3 || v3->m_wheelsInfo.m_data[v4].m_contactBody != 0i64 )
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
  UFG::PhysicsWheeledVehicle *v2; // rbx
  __int64 v3; // rdx
  unsigned int v4; // eax
  hkpVehicleWheelCollide *v5; // rcx

  v2 = this;
  UFG::PhysicsVehicle::Reset((UFG::PhysicsVehicle *)&this->vfptr, options);
  v3 = 0i64;
  v4 = *((_DWORD *)&v2->0 + 151) & 7;
  if ( v4 )
  {
    do
    {
      v5 = v2->mWheelCollider;
      if ( v5 )
      {
        if ( v4 == 2 )
          *((_DWORD *)&v5[8].m_memSizeAndFlags + v3) = 1065353216;
        else
          *((_DWORD *)&v5[7].m_alreadyUsed.m_bool + v3) = 1065353216;
      }
      v3 = (unsigned int)(v3 + 1);
      v4 = *((_DWORD *)&v2->0 + 151) & 7;
    }
    while ( (unsigned int)v3 < v4 );
  }
}

// File Line: 2627
// RVA: 0x476410
void __fastcall UFG::PhysicsWheeledVehicle::Suspend(UFG::PhysicsWheeledVehicle *this)
{
  UFG::BasePhysicsSystem *v1; // rdi
  UFG::PhysicsWheeledVehicle *v2; // rbx
  hkpAction *v3; // rdx
  hkpAction *v4; // rdx
  UFG::BasePhysicsSystem *v5; // rdi
  hkpRigidBody *v6; // rdx
  hkpRigidBody *v7; // rdx
  UFG::WaterFloatingTrackerComponent *v8; // rcx

  v1 = UFG::BasePhysicsSystem::mInstance;
  v2 = this;
  if ( this->mHavokVehicle )
    UFG::PhysicsWheeledVehicle::RemoveWheelPhantoms(this);
  v3 = (hkpAction *)&v2->mVehicleAction->vfptr;
  if ( v3 )
    UFG::BasePhysicsSystem::RemoveAction(v1, v3);
  v4 = (hkpAction *)&v2->mHavokVehicle->vfptr;
  if ( v4 )
    UFG::BasePhysicsSystem::RemoveAction(v1, v4);
  v5 = UFG::BasePhysicsSystem::mInstance;
  v6 = v2->mRigidBody->mBody;
  if ( v6 && v6->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, v6, 0);
  v7 = v2->mBulletCollider;
  if ( v7 && v7->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(v5, v7, 0);
  v8 = v2->mWaterFloatingTrackerComponent;
  if ( v8 )
    ((void (*)(void))v8->vfptr[8].__vecDelDtor)();
}

// File Line: 2654
// RVA: 0x473F20
void __fastcall UFG::PhysicsWheeledVehicle::Restore(UFG::PhysicsWheeledVehicle *this)
{
  UFG::PhysicsWheeledVehicle *v1; // rbx
  UFG::BasePhysicsSystem *v2; // rdi
  hkpAction *v3; // rdx
  hkpAction *v4; // rdx

  v1 = this;
  UFG::PhysicsVehicle::Restore((UFG::PhysicsVehicle *)&this->vfptr);
  if ( v1->mCollisionMeshBundle.mData )
  {
    v2 = UFG::BasePhysicsSystem::mInstance;
    if ( v1->mCurrentLod == 3 )
    {
      v3 = (hkpAction *)&v1->mVehicleAction->vfptr;
      if ( v3 && !v3->m_world )
        UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, v3);
      v4 = (hkpAction *)&v1->mHavokVehicle->vfptr;
      if ( v4 )
      {
        if ( !v4->m_world )
        {
          UFG::BasePhysicsSystem::AddAction(v2, v4);
          UFG::PhysicsWheeledVehicle::AddWheelPhantoms(v1);
        }
      }
    }
  }
}

// File Line: 2683
// RVA: 0x473D30
void __fastcall UFG::PhysicsWheeledVehicle::ResourceUnloaded(UFG::PhysicsWheeledVehicle *this, UFG::PhysicsResourceHandle *resource)
{
  UFG::PhysicsResourceHandle *v2; // rbx
  UFG::PhysicsWheeledVehicle *v3; // rdi

  v2 = resource;
  v3 = this;
  this->mDesiredLod = 5;
  UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents(this);
  UFG::PhysicsVehicle::ResourceUnloaded((UFG::PhysicsVehicle *)&v3->vfptr, v2);
}

// File Line: 2694
// RVA: 0x461630
void __fastcall UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents(UFG::PhysicsWheeledVehicle *this)
{
  UFG::VehicleAction *v1; // rdx
  UFG::BasePhysicsSystem *v2; // rdi
  UFG::PhysicsWheeledVehicle *v3; // rbx

  v1 = this->mVehicleAction;
  v2 = UFG::BasePhysicsSystem::mInstance;
  v3 = this;
  if ( v1 )
  {
    UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, (hkpAction *)&v1->vfptr);
    hkReferencedObject::removeReference((hkReferencedObject *)&v3->mVehicleAction->vfptr);
    v3->mVehicleAction = 0i64;
  }
  if ( v3->mHavokVehicle )
  {
    UFG::PhysicsWheeledVehicle::RemoveWheelPhantoms(v3);
    UFG::BasePhysicsSystem::RemoveAction(v2, (hkpAction *)&v3->mHavokVehicle->vfptr);
    hkReferencedObject::removeReference((hkReferencedObject *)&v3->mHavokVehicle->vfptr);
    v3->mHavokVehicle = 0i64;
    v3->mWheelCollider = 0i64;
  }
  v3->mEngine = 0i64;
  v3->mTransmission = 0i64;
  v3->mBrakes = 0i64;
  v3->mSteering = 0i64;
  v3->mAerodynamics = 0i64;
}

// File Line: 2738
// RVA: 0x474D90
void __fastcall UFG::PhysicsWheeledVehicle::SetLevelOfDetailInternal(UFG::PhysicsWheeledVehicle *this, UFG::PhysicsVehicle::Lod lod)
{
  UFG::PhysicsWheeledVehicle *v2; // rbx
  UFG::BasePhysicsSystem *v3; // rbp
  hkpWorld *v4; // r14
  unsigned int v5; // edi
  __int64 v6; // rsi
  signed __int64 v7; // rsi
  char v8; // dl
  __int64 v9; // rax
  char v10; // cl
  _QWORD **v11; // rax
  UFG::VehicleLinearCastWheelCollide *v12; // rax
  hkJobType v13; // edx
  hkpVehicleWheelCollide *v14; // rax
  char v15; // dl
  __int64 v16; // rax
  char v17; // cl
  _QWORD **v18; // rax
  UFG::VehicleRaycastWheelCollide *v19; // rax
  UFG::VehicleParams *v20; // rdx
  char v21; // dl
  __int64 v22; // rax
  char v23; // cl
  _QWORD **v24; // rax
  UFG::VehicleInstance *v25; // rax
  UFG::VehicleInstance *v26; // rax
  char v27; // al
  UFG::VehicleInstance *v28; // rcx
  char v29; // dl
  __int64 v30; // rax
  char v31; // cl
  _QWORD **v32; // rax
  UFG::VehicleAction *v33; // rax
  UFG::VehicleAction *v34; // rax
  char v35; // al
  __int64 v36; // rdx
  float *v37; // r8
  UFG::VehicleSetup v38; // [rsp+40h] [rbp-98h]

  if ( (signed int)lod > 0 )
  {
    v2 = this;
    v3 = UFG::BasePhysicsSystem::mInstance;
    if ( (signed int)lod <= 2 )
      goto LABEL_38;
    if ( lod != 3 )
    {
      if ( lod != 4 )
        return;
LABEL_38:
      UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents(this);
      return;
    }
    v4 = UFG::BasePhysicsSystem::mInstance->mWorld;
    v5 = 0;
    v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
    if ( (*((_DWORD *)&this->0 + 151) & 7) == 2 )
    {
      v7 = v6 + 16;
      v8 = ++*(_BYTE *)(v7 + 80);
      v9 = v8;
      *(_DWORD *)(v7 + 4 * v9) = 3;
      *(_QWORD *)(v7 + 8 * v9 + 16) = "VehicleLinearCastWheelCollide";
      *(_QWORD *)(v7 + 8 * v9 + 48) = 0i64;
      v10 = *(_BYTE *)(v7 + 81);
      if ( v8 > v10 )
        v10 = v8;
      *(_BYTE *)(v7 + 81) = v10;
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (UFG::VehicleLinearCastWheelCollide *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(
                                                    v11[11],
                                                    216i64);
      if ( v12 )
        UFG::VehicleLinearCastWheelCollide::VehicleLinearCastWheelCollide(v12);
      else
        v14 = 0i64;
    }
    else
    {
      v7 = v6 + 16;
      v15 = ++*(_BYTE *)(v7 + 80);
      v16 = v15;
      *(_DWORD *)(v7 + 4 * v16) = 3;
      *(_QWORD *)(v7 + 8 * v16 + 16) = "VehicleRaycastWheelCollide";
      *(_QWORD *)(v7 + 8 * v16 + 48) = 0i64;
      v17 = *(_BYTE *)(v7 + 81);
      if ( v15 > v17 )
        v17 = v15;
      *(_BYTE *)(v7 + 81) = v17;
      v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v19 = (UFG::VehicleRaycastWheelCollide *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(
                                                 v18[11],
                                                 200i64);
      if ( v19 )
        UFG::VehicleRaycastWheelCollide::VehicleRaycastWheelCollide(v19);
      else
        v14 = 0i64;
    }
    v2->mWheelCollider = v14;
    HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v13);
    v20 = v2->mParams;
    *(_DWORD *)&v38.m_memSizeAndFlags = 0x1FFFF;
    v38.vfptr = (hkBaseObjectVtbl *)&UFG::VehicleSetup::`vftable;
    UFG::VehicleParams::VehicleParams(&v38.mParams, v20);
    v21 = ++*(_BYTE *)(v7 + 80);
    v22 = v21;
    *(_DWORD *)(v7 + 4 * v22) = 3;
    *(_QWORD *)(v7 + 8 * v22 + 16) = "hkpVehicleInstance";
    *(_QWORD *)(v7 + 8 * v22 + 48) = 0i64;
    v23 = *(_BYTE *)(v7 + 81);
    if ( v21 > v23 )
      v23 = v21;
    *(_BYTE *)(v7 + 81) = v23;
    v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v25 = (UFG::VehicleInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(
                                    v24[11],
                                    256i64);
    if ( v25 )
      UFG::VehicleInstance::VehicleInstance(v25, v2->mRigidBody->mBody);
    else
      v26 = 0i64;
    v2->mHavokVehicle = v26;
    v27 = *(_BYTE *)(v7 + 80);
    if ( v27 > 0 )
    {
      *(_BYTE *)(v7 + 80) = v27 - 1;
    }
    else
    {
      *(_BYTE *)(v7 + 80) = 0;
      *(_DWORD *)v7 = 3;
      *(_QWORD *)(v7 + 16) = 0i64;
      *(_QWORD *)(v7 + 48) = 0i64;
    }
    UFG::VehicleSetup::buildVehicle(&v38, v2, v4, (hkpVehicleInstance *)&v2->mHavokVehicle->vfptr, v2->mWheelCollider);
    v28 = v2->mHavokVehicle;
    v2->mEngine = (UFG::Engine *)v28->m_engine;
    v2->mTransmission = (UFG::Transmission *)v28->m_transmission;
    v2->mBrakes = (UFG::Brakes *)v28->m_brake;
    v2->mSteering = (UFG::Steering *)v28->m_steering;
    v2->mAerodynamics = (UFG::VehicleAerodynamics *)v28->m_aerodynamics;
    v29 = ++*(_BYTE *)(v7 + 80);
    v30 = v29;
    *(_DWORD *)(v7 + 4 * v30) = 3;
    *(_QWORD *)(v7 + 8 * v30 + 16) = "VehicleAction";
    *(_QWORD *)(v7 + 8 * v30 + 48) = 0i64;
    v31 = *(_BYTE *)(v7 + 81);
    if ( v29 > v31 )
      v31 = v29;
    *(_BYTE *)(v7 + 81) = v31;
    v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v33 = (UFG::VehicleAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v32[11] + 8i64))(v32[11], 72i64);
    if ( v33 )
      UFG::VehicleAction::VehicleAction(v33, v2);
    else
      v34 = 0i64;
    v2->mVehicleAction = v34;
    v35 = *(_BYTE *)(v7 + 80);
    if ( v35 > 0 )
    {
      *(_BYTE *)(v7 + 80) = v35 - 1;
    }
    else
    {
      *(_BYTE *)(v7 + 80) = 0;
      *(_DWORD *)v7 = 3;
      *(_QWORD *)(v7 + 16) = 0i64;
      *(_QWORD *)(v7 + 48) = 0i64;
    }
    UFG::BasePhysicsSystem::AddAction(v3, (hkpAction *)&v2->mHavokVehicle->vfptr);
    UFG::BasePhysicsSystem::AddAction(v3, (hkpAction *)&v2->mVehicleAction->vfptr);
    UFG::PhysicsWheeledVehicle::AddWheelPhantoms(v2);
    if ( *((_BYTE *)&v2->0 + 604) & 7 )
    {
      v36 = 0i64;
      v37 = v2->mWheelSpinAngle.array;
      do
      {
        v2->mHavokVehicle->m_wheelsInfo.m_data[v36].m_spinAngle = *v37;
        ++v5;
        ++v37;
        ++v36;
      }
      while ( v5 < (*((_DWORD *)&v2->0 + 151) & 7u) );
    }
    UFG::VehicleParams::~VehicleParams(&v38.mParams);
    v38.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  }
}

// File Line: 2809
// RVA: 0x47FC50
void __fastcall UFG::PhysicsWheeledVehicle::UpdateSkids(UFG::PhysicsWheeledVehicle *this, UFG::VehicleInput *input, float speed_delta)
{
  unsigned int v3; // er10
  UFG::PhysicsWheeledVehicle *v4; // r9
  unsigned int v5; // ebx
  float v6; // xmm4_4
  float v7; // xmm5_4
  __int64 v8; // r11
  UFG::qSafeArray<float,4> *v9; // r8
  float v10; // xmm7_4
  UFG::VehicleInstance *v11; // rax
  hkpVehicleInstance::WheelInfo *v12; // rcx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  hkpVehicleInstance::WheelInfo *v16; // rcx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float *v20; // rcx
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  UFG::VehicleParams *v26; // rax
  __int64 v27; // rdx
  _DWORD *v28; // rcx

  v3 = 0;
  v4 = this;
  v5 = 0;
  if ( *((_DWORD *)&this->0 + 151) & 7 )
  {
    v6 = speed_skid_factor;
    v7 = speed_down_skid_threshold;
    v8 = 0i64;
    v9 = &this->mForwardSkidStrength;
    v10 = speed_up_skid_threshold;
    do
    {
      v11 = v4->mHavokVehicle;
      if ( v5 <= v11->m_wheelsInfo.m_size && (v12 = v11->m_wheelsInfo.m_data, v12[v8].m_contactBody) )
      {
        LODWORD(v13) = LODWORD(v12[v8].m_forwardSlipVelocity) & _xmm;
        v9->array[0] = v13;
        if ( speed_delta <= v10 )
          v14 = 0.0;
        else
          v14 = v6 * speed_delta;
        if ( v13 <= v14 )
          v13 = v14;
        v9->array[0] = v13;
        if ( speed_delta >= v7 || input->mGasBrakes <= 0.0 )
          v15 = 0.0;
        else
          v15 = (float)(speed_delta * -1.0) * v6;
        if ( v13 <= v15 )
          v13 = v15;
        v9->array[0] = v13;
        LODWORD(v9[1].array[0]) = LODWORD(v4->mHavokVehicle->m_wheelsInfo.m_data[v8].m_sideSlipVelocity) & _xmm;
        v16 = v4->mHavokVehicle->m_wheelsInfo.m_data;
        LODWORD(v17) = LODWORD(v16[v8].m_sideSlipVelocity) & _xmm;
        if ( v17 <= COERCE_FLOAT(LODWORD(v16[v8].m_forwardSlipVelocity) & _xmm) )
          LODWORD(v17) = LODWORD(v16[v8].m_forwardSlipVelocity) & _xmm;
        v9[-1].array[0] = v17;
        if ( speed_delta <= v10 )
          v18 = 0.0;
        else
          v18 = v6 * speed_delta;
        if ( v17 <= v18 )
          v17 = v18;
        v9[-1].array[0] = v17;
        if ( speed_delta >= v7 || input->mGasBrakes <= 0.0 )
          v19 = 0.0;
        else
          v19 = (float)(speed_delta * -1.0) * v6;
        if ( v17 <= v19 )
          v17 = v19;
        v9[-1].array[0] = v17;
      }
      else
      {
        v9[-1].array[0] = 0.0;
        v9->array[0] = 0.0;
        v9[1].array[0] = 0.0;
      }
      ++v5;
      v9 = (UFG::qSafeArray<float,4> *)((char *)v9 + 4);
      ++v8;
    }
    while ( v5 < (*((_DWORD *)&v4->0 + 151) & 7u) );
  }
  if ( *((_BYTE *)&v4->0 + 604) & 7 )
  {
    v20 = v4->mForwardSkidStrength.array;
    do
    {
      v21 = (float)(*(v20 - 4) - 4.0) * 0.125;
      if ( v21 <= 0.0 )
      {
        v21 = 0.0;
      }
      else if ( v21 >= 1.0 )
      {
        v21 = *(float *)&FLOAT_1_0;
      }
      v22 = *v20;
      *(v20 - 4) = v21;
      v23 = (float)(v22 - 4.0) * 0.125;
      if ( v23 <= 0.0 )
      {
        v23 = 0.0;
      }
      else if ( v23 >= 1.0 )
      {
        v23 = *(float *)&FLOAT_1_0;
      }
      v24 = v20[4];
      *v20 = v23;
      v25 = (float)(v24 - 4.0) * 0.125;
      if ( v25 <= 0.0 )
      {
        v25 = 0.0;
      }
      else if ( v25 >= 1.0 )
      {
        v25 = *(float *)&FLOAT_1_0;
      }
      v20[4] = v25;
      ++v3;
      ++v20;
    }
    while ( v3 < (*((_DWORD *)&v4->0 + 151) & 7u) );
  }
  if ( *((_BYTE *)input + 16) & 0x20 )
  {
    v26 = v4->mParams;
    v27 = v26->firstRearWheel;
    if ( (signed int)v27 <= v26->lastRearWheel )
    {
      v28 = (_DWORD *)((char *)v4 + 4 * (v27 + 212));
      do
      {
        *(v28 - 4) = 1065353216;
        *v28 = 1065353216;
        *(v28 - 8) = 1065353216;
        LODWORD(v27) = v27 + 1;
        ++v28;
      }
      while ( (signed int)v27 <= v4->mParams->lastRearWheel );
    }
  }
}8) = 106535321

// File Line: 2876
// RVA: 0x4755D0
void __fastcall UFG::PhysicsWheeledVehicle::SetTireDamage(UFG::PhysicsWheeledVehicle *this, int index, float damage)
{
  float v3; // xmm1_4
  UFG::VehicleInstance *v4; // rax
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
      v4 = this->mHavokVehicle;
      if ( v4 )
        v4->m_data->m_wheelParams.m_data[index].m_radius = v4->m_data->m_wheelParams.m_data[index].m_radius - v3;
    }
    if ( damage == 0.0 )
    {
      v5 = this->mHavokVehicle;
      if ( v5 )
        v5->m_data->m_wheelParams.m_data[index].m_radius = v3 + v5->m_data->m_wheelParams.m_data[index].m_radius;
    }
  }
}

// File Line: 2909
// RVA: 0x468460
void __fastcall UFG::PhysicsWheeledVehicle::GetWheelMatrix(UFG::PhysicsWheeledVehicle *this, int i, UFG::qMatrix44 *mat)
{
  UFG::qMatrix44 *v3; // rbx
  UFG::qMatrix44 *v4; // rax
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  hkQuaternionf qi; // [rsp+30h] [rbp-A8h]
  __int128 v9; // [rsp+40h] [rbp-98h]
  hkRotationf v10; // [rsp+50h] [rbp-88h]
  __int128 v11; // [rsp+80h] [rbp-58h]
  UFG::qMatrix44 result; // [rsp+90h] [rbp-48h]

  v3 = mat;
  ((void (__fastcall *)(UFG::VehicleInstance *, hkpRigidBody *, hkpVehicleSuspension *, _QWORD, __int128 *, hkQuaternionf *))this->mHavokVehicle->vfptr[5].__first_virtual_table_function__)(
    this->mHavokVehicle,
    this->mRigidBody->mBody,
    this->mHavokVehicle->m_suspension,
    (unsigned int)i,
    &v9,
    &qi);
  v11 = v9;
  hkRotationf::set(&v10, &qi);
  hkTransformf::get4x4ColumnMajor((hkTransformf *)&v10, &v3->v0.x);
  v4 = UFG::qMatrix44::operator*(&UFG::gWheelFixup, &result, v3);
  v5 = v4->v1;
  v6 = v4->v2;
  v7 = v4->v3;
  v3->v0 = v4->v0;
  v3->v1 = v5;
  v3->v2 = v6;
  v3->v3 = v7;
}

// File Line: 2926
// RVA: 0x468510
void __fastcall UFG::PhysicsWheeledVehicle::GetWheelTransforms(UFG::PhysicsWheeledVehicle *this, hkQsTransformf *axleTransform, hkQuaternionf *wheelTransform, bool clampSuspensionTravel)
{
  __int64 v4; // rbp
  bool v5; // r14
  hkQuaternionf *v6; // r15
  hkQsTransformf *v7; // r12
  UFG::PhysicsWheeledVehicle *v8; // rsi
  float *v9; // rdi
  float minSuspensionLength; // xmm1_4
  double v11; // xmm2_8
  float maxSuspensionLength; // xmm0_4
  hkQuaternionf *v13; // rbx

  v4 = 0i64;
  v5 = clampSuspensionTravel;
  v6 = wheelTransform;
  v7 = axleTransform;
  v8 = this;
  if ( *((_BYTE *)&this->0 + 604) & 7 )
  {
    v9 = this->mRestingSuspensionLength.array;
    do
    {
      if ( v5 )
      {
        minSuspensionLength = *v9 - v9[4];
        v11 = (float)(*v9 + v9[8]);
      }
      else
      {
        minSuspensionLength = 0.0;
        v11 = DOUBLE_1000000_0;
      }
      maxSuspensionLength = v11;
      v13 = (hkQuaternionf *)&v7[v4];
      UFG::VehicleInstance::CalcCurrentPositionAndRotation(
        v8->mHavokVehicle,
        v8->mRigidBody->mBody,
        v8->mHavokVehicle->m_suspension,
        v4,
        &v7[v4].m_translation,
        v13 + 1,
        &v6[(unsigned int)v4],
        minSuspensionLength,
        maxSuspensionLength);
      v13[2].m_vec = (hkVector4f)query.m_quad;
      v4 = (unsigned int)(v4 + 1);
      ++v9;
    }
    while ( (unsigned int)v4 < (*((_DWORD *)&v8->0 + 151) & 7u) );
  }
}

// File Line: 2948
// RVA: 0x46B520
bool __fastcall UFG::PhysicsWheeledVehicle::IsWheelOnGround(UFG::PhysicsWheeledVehicle *this, int wheelNum)
{
  UFG::VehicleInstance *v2; // rcx
  bool result; // al

  v2 = this->mHavokVehicle;
  if ( v2 )
    result = v2->m_wheelsInfo.m_data[wheelNum].m_contactBody != 0i64;
  else
    result = 1;
  return result;
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
  UFG::WaterFloatingTrackerComponent *v1; // rbx

  v1 = this->mWaterFloatingTrackerComponent;
  return ((unsigned __int8 (*)(void))this->vfptr[4].DebugDraw)() && v1 && v1->mInWaterState > 0;
}

// File Line: 2985
// RVA: 0x474C80
void __fastcall UFG::PhysicsWheeledVehicle::SetEngineDamage(UFG::PhysicsWheeledVehicle *this, float damage)
{
  UFG::Engine *v2; // rax

  v2 = this->mEngine;
  if ( v2 )
    v2->mDamage = damage;
}

// File Line: 3005
// RVA: 0x467010
float __fastcall UFG::PhysicsWheeledVehicle::GetRPM(UFG::PhysicsWheeledVehicle *this)
{
  UFG::VehicleInstance *v1; // rcx
  float result; // xmm0_4

  v1 = this->mHavokVehicle;
  if ( !v1 )
    return FLOAT_1000_0;
  ((void (*)(void))v1->vfptr[6].__vecDelDtor)();
  return result;
}

// File Line: 3019
// RVA: 0x466840
float __fastcall UFG::PhysicsWheeledVehicle::GetHalfSteeringRange(UFG::PhysicsWheeledVehicle *this)
{
  UFG::VehicleInstance *v1; // rax
  hkpVehicleSteering *v2; // rax
  float result; // xmm0_4

  v1 = this->mHavokVehicle;
  if ( !v1 )
    return FLOAT_0_78539819;
  v2 = v1->m_steering;
  if ( !v2 )
    return FLOAT_0_78539819;
  LODWORD(result) = *(_DWORD *)&v2[3].m_memSizeAndFlags & _xmm;
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
  UFG::VehicleInstance *v1; // rax

  v1 = this->mHavokVehicle;
  if ( v1 )
    LODWORD(v1->m_driverInput[1].vfptr) = 0;
}

// File Line: 3063
// RVA: 0x466C40
unsigned __int64 __fastcall UFG::PhysicsWheeledVehicle::GetObjectPropertyHandleUidUnderWheel(UFG::PhysicsWheeledVehicle *this, int wheelNum)
{
  __int64 v2; // r9
  hkpVehicleWheelCollide *v3; // r8
  hkpVehicleWheelCollide *v5; // rdx

  v2 = wheelNum;
  if ( (*((_DWORD *)&this->0 + 151) & 7) == 2 )
  {
    v3 = this->mWheelCollider;
    if ( v3 )
      return *((_QWORD *)&v3[5].vfptr + wheelNum);
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
float __fastcall UFG::PhysicsWheeledVehicle::GetWheelFrictionMultiplier(UFG::PhysicsWheeledVehicle *this, int wheelIndex)
{
  __int64 v2; // r9
  hkpVehicleWheelCollide *v3; // r8
  hkpVehicleWheelCollide *v5; // rdx

  v2 = wheelIndex;
  if ( (*((_DWORD *)&this->0 + 151) & 7) == 2 )
  {
    v3 = this->mWheelCollider;
    if ( v3 )
      return *((float *)&v3[8].m_memSizeAndFlags + wheelIndex);
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
void __fastcall UFG::PhysicsWheeledVehicle::SetWheelFrictionMultiplier(UFG::PhysicsWheeledVehicle *this, int wheelIndex, float multiplier)
{
  hkpVehicleWheelCollide *v3; // r8

  v3 = this->mWheelCollider;
  if ( v3 )
  {
    if ( (*((_DWORD *)&this->0 + 151) & 7) == 2 )
      *((float *)&v3[8].m_memSizeAndFlags + (unsigned int)wheelIndex) = multiplier;
    else
      *((float *)&v3[7].m_alreadyUsed.m_bool + (unsigned int)wheelIndex) = multiplier;
  }
}

// File Line: 3139
// RVA: 0x467B20
unsigned __int64 __fastcall UFG::PhysicsWheeledVehicle::GetSurfacePropertyHandleUidUnderWheel(UFG::PhysicsWheeledVehicle *this, int wheelNum)
{
  __int64 v2; // r9
  hkpVehicleWheelCollide *v3; // r8
  hkpVehicleWheelCollide *v5; // rdx

  v2 = wheelNum;
  if ( (*((_DWORD *)&this->0 + 151) & 7) == 2 )
  {
    v3 = this->mWheelCollider;
    if ( v3 )
      return *((_QWORD *)&v3[3].m_alreadyUsed.m_bool + wheelNum);
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
  char *v4; // [rsp+28h] [rbp-20h]
  int v5; // [rsp+30h] [rbp-18h]
  int v6; // [rsp+34h] [rbp-14h]

  v1 = UFG::BasePhysicsSystem::mInstance;
  if ( (*((_DWORD *)&this->0 + 151) & 7) == 2 )
  {
    v4 = 0i64;
    v5 = 0;
    v6 = 2147483648;
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
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v4,
        8 * v6);
    v4 = 0i64;
    v6 = 2147483648;
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
  char *v4; // [rsp+28h] [rbp-20h]
  int v5; // [rsp+30h] [rbp-18h]
  int v6; // [rsp+34h] [rbp-14h]

  v1 = UFG::BasePhysicsSystem::mInstance;
  if ( (*((_DWORD *)&this->0 + 151) & 7) == 2 )
  {
    v4 = 0i64;
    v5 = 0;
    v6 = 2147483648;
    ((void (__fastcall *)(hkpVehicleWheelCollide *, char **))this->mHavokVehicle->m_wheelCollide->vfptr[2].__first_virtual_table_function__)(
      this->mHavokVehicle->m_wheelCollide,
      &v4);
    v2 = 0;
    if ( v5 > 0 )
    {
      v3 = 0i64;
      do
      {
        UFG::BasePhysicsSystem::RemoveEntity(v1, *(hkpPhantom **)&v4[v3], 0i64);
        ++v2;
        v3 += 8i64;
      }
      while ( v2 < v5 );
    }
    v5 = 0;
    if ( v6 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v4,
        8 * v6);
    v4 = 0i64;
    v6 = 2147483648;
  }
  else
  {
    UFG::BasePhysicsSystem::RemoveEntity(
      UFG::BasePhysicsSystem::mInstance,
      *(hkpPhantom **)&this->mHavokVehicle->m_wheelCollide[1].m_memSizeAndFlags,
      0i64);
  }
}

