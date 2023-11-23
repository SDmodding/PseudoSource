// File Line: 35
// RVA: 0x1514430
__int64 dynamic_initializer_for__UFG::WaterPhantomComponent::s_WaterPhantomComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WaterPhantomComponent::s_WaterPhantomComponentList__);
}

// File Line: 36
// RVA: 0x468100
const char *__fastcall UFG::WaterPhantomComponent::GetTypeName(UFG::WaterPhantomComponent *this)
{
  return "WaterPhantomComponent";
}

// File Line: 44
// RVA: 0x44E5F0
void __fastcall UFG::WaterPhantomComponent::WaterPhantomComponent(
        UFG::WaterPhantomComponent *this,
        UFG::CollisionInstanceData *instance)
{
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *mPrev; // rax
  UFG::qBaseTreeRB *CollisionModel; // r15
  unsigned int v6; // r8d
  __int64 v7; // r8
  __int64 v8; // rbx
  char v9; // dl
  char v10; // cl
  _QWORD **Value; // rax
  hkpCachingShapePhantom *v12; // rax
  hkpShapePhantom *v13; // rax
  char v14; // dl
  char v15; // cl
  _QWORD **v16; // rax
  hkpSimpleShapePhantom *v17; // rax
  char v18; // al
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  char v23[24]; // [rsp+30h] [rbp-98h] BYREF
  float v24; // [rsp+48h] [rbp-80h]
  hkTransformf v25; // [rsp+50h] [rbp-78h] BYREF

  UFG::SimComponent::SimComponent(this, instance->mInstanceGuid);
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  this->mUserData.isBoat = 0;
  this->mUserData.simComponent.mPrev = &this->mUserData.simComponent;
  this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  this->mUserData.simComponent.m_pPointer = 0i64;
  this->mPrev = &this->UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent>;
  this->mNext = &this->UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterPhantomComponent::`vftable{for `UFG::SimComponent};
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::WaterPhantomComponent::`vftable{for `UFG::BasePhysicsObject};
  UFG::qResourceHandle::qResourceHandle(&this->mCollisionMeshBundle);
  this->mCollisionMeshBundle.mOwner = 0i64;
  this->mCollisionMeshBundle.mUnloading = 0;
  this->mPhantom = 0i64;
  this->mCollector.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpCdBodyPairCollector::`vftable;
  this->mCollector.m_earlyOut.m_bool = 0;
  this->mCollector.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpAllCdBodyPairCollector::`vftable;
  this->mCollector.m_hits.m_data = this->mCollector.m_hits.m_storage;
  this->mCollector.m_hits.m_size = 0;
  this->mCollector.m_hits.m_capacityAndFlags = -2147483632;
  this->mCollector.m_hits.m_size = 0;
  this->mCollector.m_earlyOut.m_bool = 0;
  this->mElevation = -1.0;
  mPrev = UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mPrev;
  UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList;
  UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mPrev = &this->UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent>;
  UFG::SimComponent::AddType(this, UFG::WaterPhantomComponent::_WaterPhantomComponentTypeUID, "WaterPhantomComponent");
  CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(
                     UFG::BasePhysicsSystem::mInstance,
                     instance->mCollisionModelGuid);
  v6 = (unsigned int)CollisionModel->mNULL.mChild[0];
  this->mCollisionMeshBundle.mOwner = &this->UFG::BasePhysicsObject;
  UFG::qResourceHandle::Init(&this->mCollisionMeshBundle, 0x1723EA91u, v6);
  v25.m_translation = instance->mPosition;
  hkRotationf::set(&v25.m_rotation, &instance->mOrientation);
  ((void (__fastcall *)(UFG::qBaseNodeRB *, hkTransformf *, __int64, char *, __int64))CollisionModel[2].mNULL.mChild[1]->mParent[1].mParent)(
    CollisionModel[2].mNULL.mChild[1],
    &v25,
    v7,
    v23,
    -2i64);
  this->mElevation = v24;
  *((_DWORD *)this + 181) ^= (*((_DWORD *)this + 181) ^ (HIDWORD(CollisionModel->mNULL.mChild[0]) != 0)) & 1;
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  if ( (*((_BYTE *)this + 724) & 1) != 0 )
  {
    v9 = ++*(_BYTE *)(v8 + 80);
    *(_DWORD *)(v8 + 4i64 * v9) = 3;
    *(_QWORD *)(v8 + 8i64 * v9 + 16) = "hkpCachingShapePhantom";
    *(_QWORD *)(v8 + 8i64 * v9 + 48) = 0i64;
    v10 = *(_BYTE *)(v8 + 81);
    if ( v9 > v10 )
      v10 = v9;
    *(_BYTE *)(v8 + 81) = v10;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (hkpCachingShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                      Value[11],
                                      448i64);
    if ( v12 )
      hkpCachingShapePhantom::hkpCachingShapePhantom(
        v12,
        (hkpShape *)CollisionModel[2].mNULL.mChild[1],
        &v25,
        CollisionModel[3].mNULL.mChild[0][5].mUID);
    else
      v13 = 0i64;
  }
  else
  {
    v14 = ++*(_BYTE *)(v8 + 80);
    *(_DWORD *)(v8 + 4i64 * v14) = 3;
    *(_QWORD *)(v8 + 8i64 * v14 + 16) = "hkpSimpleShapePhantom";
    *(_QWORD *)(v8 + 8i64 * v14 + 48) = 0i64;
    v15 = *(_BYTE *)(v8 + 81);
    if ( v14 > v15 )
      v15 = v14;
    *(_BYTE *)(v8 + 81) = v15;
    v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkpSimpleShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(v16[11], 448i64);
    if ( v17 )
      hkpSimpleShapePhantom::hkpSimpleShapePhantom(
        v17,
        (hkpShape *)CollisionModel[2].mNULL.mChild[1],
        &v25,
        CollisionModel[3].mNULL.mChild[0][5].mUID);
    else
      v13 = 0i64;
  }
  this->mPhantom = v13;
  v18 = *(_BYTE *)(v8 + 80);
  if ( v18 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v18 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_QWORD *)(v8 + 48) = 0i64;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_DWORD *)v8 = 3;
  }
  p_simComponent = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    v20 = p_simComponent->mPrev;
    mNext = this->mUserData.simComponent.mNext;
    v20->mNext = mNext;
    mNext->mPrev = v20;
    p_simComponent->mPrev = p_simComponent;
    this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  }
  this->mUserData.simComponent.m_pPointer = this;
  v22 = this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
  v22->mNext = p_simComponent;
  p_simComponent->mPrev = v22;
  this->mUserData.simComponent.mNext = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_simComponent;
  this->mPhantom->m_userData = (unsigned __int64)&this->mUserData;
  UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
    (hkSimplePropertyValue)CollisionModel->mNULL.mParent,
    this->mPhantom);
  UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, this->mPhantom, 1);
}

// File Line: 93
// RVA: 0x451B40
void __fastcall UFG::WaterPhantomComponent::~WaterPhantomComponent(UFG::WaterPhantomComponent *this)
{
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v2; // rdi
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *mPrev; // rcx
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *mNext; // rax
  hkpShapePhantom *mPhantom; // rdx
  hkpShapePhantom *v6; // rcx
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v7; // rdx
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v8; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterPhantomComponent::`vftable{for `UFG::SimComponent};
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::WaterPhantomComponent::`vftable{for `UFG::BasePhysicsObject};
  if ( this == UFG::WaterPhantomComponent::s_WaterPhantomComponentpCurrentIterator )
    UFG::WaterPhantomComponent::s_WaterPhantomComponentpCurrentIterator = (UFG::WaterPhantomComponent *)&this->mPrev[-7].mNext;
  v2 = &this->UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  mPhantom = this->mPhantom;
  if ( mPhantom )
  {
    this->mCollisionMeshBundle.mOwner = 0i64;
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, mPhantom, 0);
    v6 = this->mPhantom;
    if ( v6 )
      v6->vfptr->__vecDelDtor(v6, 1u);
  }
  hkpAllCdBodyPairCollector::~hkpAllCdBodyPairCollector(&this->mCollector);
  UFG::qResourceHandle::~qResourceHandle(&this->mCollisionMeshBundle);
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BasePhysicsObject::~BasePhysicsObject(&this->UFG::BasePhysicsObject);
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 111
// RVA: 0x47DFD0
void __fastcall UFG::WaterPhantomComponent::Update(UFG::WaterPhantomComponent *this, float deltaT)
{
  hkpShapePhantom *mPhantom; // rcx

  if ( (*((_BYTE *)this + 724) & 1) != 0 )
  {
    this->mCollector.vfptr->reset(&this->mCollector);
    mPhantom = this->mPhantom;
    if ( mPhantom->m_world )
      ((void (__fastcall *)(hkpShapePhantom *, hkpAllCdBodyPairCollector *, _QWORD))mPhantom->vfptr[9].__vecDelDtor)(
        mPhantom,
        &this->mCollector,
        0i64);
    s_WaterphantomRaycasts = 0;
  }
  else
  {
    s_WaterphantomRaycasts = 0;
  }
}

// File Line: 128
// RVA: 0x473D70
void __fastcall UFG::WaterPhantomComponent::ResourceUnloaded(
        UFG::WaterPhantomComponent *this,
        UFG::PhysicsResourceHandle *__formal)
{
  hkpPhantom *mPrev; // rdx
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v4; // rcx

  mPrev = (hkpPhantom *)this->mPrev;
  this->mUserData.simComponent.mNext = 0i64;
  if ( mPrev )
  {
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, mPrev, 0);
    v4 = this->mPrev;
    if ( v4 )
      ((void (__fastcall *)(UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *, __int64))v4->mPrev->mPrev)(
        v4,
        1i64);
    this->mPrev = 0i64;
  }
}

// File Line: 171
// RVA: 0x46A8B0
bool __fastcall UFG::WaterPhantomComponent::IntersectRay(
        UFG::WaterPhantomComponent *this,
        hkVector4f *start,
        hkVector4f *end)
{
  hkpShapePhantom *mPhantom; // rbx
  hkVector4f v7; // [rsp+20h] [rbp-98h] BYREF
  hkVector4f v8; // [rsp+30h] [rbp-88h] BYREF
  int v9; // [rsp+40h] [rbp-78h]
  __int64 v10; // [rsp+48h] [rbp-70h]
  __int64 v11; // [rsp+50h] [rbp-68h]
  __int64 v12; // [rsp+58h] [rbp-60h]
  char v13[16]; // [rsp+60h] [rbp-58h] BYREF
  float v14; // [rsp+70h] [rbp-48h]
  int v15; // [rsp+74h] [rbp-44h]
  int v16; // [rsp+80h] [rbp-38h]
  int v17; // [rsp+A0h] [rbp-18h]
  char v18; // [rsp+C0h] [rbp+8h] BYREF

  mPhantom = this->mPhantom;
  ++s_WaterphantomRaycasts;
  v9 = 0;
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  v14 = 1.0;
  v15 = -1;
  v17 = 0;
  v16 = -1;
  hkVector4f::setTransformedInversePos(&v7, &mPhantom->m_motionState.m_transform, start);
  hkVector4f::setTransformedInversePos(&v8, &mPhantom->m_motionState.m_transform, end);
  ((void (__fastcall *)(hkpShape *, char *, hkVector4f *, char *))this->mPhantom->m_collidable.m_shape->vfptr[2].__first_virtual_table_function__)(
    this->mPhantom->m_collidable.m_shape,
    &v18,
    &v7,
    v13);
  return v14 < 1.0;
}

