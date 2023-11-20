// File Line: 35
// RVA: 0x1514430
__int64 dynamic_initializer_for__UFG::WaterPhantomComponent::s_WaterPhantomComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::WaterPhantomComponent::s_WaterPhantomComponentList__);
}

// File Line: 36
// RVA: 0x468100
const char *__fastcall UFG::WaterPhantomComponent::GetTypeName(UFG::WaterPhantomComponent *this)
{
  return "WaterPhantomComponent";
}

// File Line: 44
// RVA: 0x44E5F0
void __fastcall UFG::WaterPhantomComponent::WaterPhantomComponent(UFG::WaterPhantomComponent *this, UFG::CollisionInstanceData *instance)
{
  UFG::CollisionInstanceData *v2; // rbp
  UFG::WaterPhantomComponent *v3; // r14
  UFG::BasePhysicsObject *v4; // rsi
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v5; // rbx
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v6; // rax
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseTreeRB *v8; // r15
  unsigned int v9; // er8
  __int64 v10; // r8
  _QWORD *v11; // rax
  signed __int64 v12; // rbx
  char v13; // dl
  __int64 v14; // rax
  char v15; // cl
  _QWORD **v16; // rax
  hkpCachingShapePhantom *v17; // rax
  hkpShapePhantom *v18; // rax
  char v19; // dl
  __int64 v20; // rax
  char v21; // cl
  _QWORD **v22; // rax
  hkpSimpleShapePhantom *v23; // rax
  char v24; // al
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v25; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  char v29; // [rsp+30h] [rbp-98h]
  float v30; // [rsp+48h] [rbp-80h]
  hkRotationf v31; // [rsp+50h] [rbp-78h]
  hkVector4f v32; // [rsp+80h] [rbp-48h]
  signed __int64 v33; // [rsp+D8h] [rbp+10h]
  signed __int64 v34; // [rsp+E0h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v35; // [rsp+E8h] [rbp+20h]

  v2 = instance;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, instance->mInstanceGuid);
  v4 = (UFG::BasePhysicsObject *)&v3->vfptr;
  v4->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  v3->mUserData.isBoat = 0;
  v35 = &v3->mUserData.simComponent;
  v35->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v35->mPrev;
  v35->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v35->mPrev;
  v3->mUserData.simComponent.m_pPointer = 0i64;
  v5 = (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)&v3->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterPhantomComponent::`vftable{for `UFG::SimComponent};
  v4->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::WaterPhantomComponent::`vftable{for `UFG::BasePhysicsObject};
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mCollisionMeshBundle.mPrev);
  v3->mCollisionMeshBundle.mOwner = 0i64;
  v3->mCollisionMeshBundle.mUnloading = 0;
  v3->mPhantom = 0i64;
  v33 = (signed __int64)&v3->mCollector;
  *(_QWORD *)v33 = &hkpCdBodyPairCollector::`vftable;
  *(_BYTE *)(v33 + 8) = 0;
  *(_QWORD *)v33 = &hkpAllCdBodyPairCollector::`vftable;
  v34 = (signed __int64)&v3->mCollector.m_hits;
  *(_QWORD *)v34 = (char *)v3 + 208;
  *(_DWORD *)(v34 + 8) = 0;
  *(_DWORD *)(v34 + 12) = -2147483632;
  *(_DWORD *)(v33 + 24) = 0;
  v3->mCollector.m_earlyOut.m_bool = 0;
  v3->mElevation = -1.0;
  v6 = UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mPrev;
  UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)&v3->mPrev;
  v5->mPrev = v6;
  v3->mNext = (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList;
  UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mPrev = (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::WaterPhantomComponent::_WaterPhantomComponentTypeUID,
    "WaterPhantomComponent");
  v7 = UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v2->mCollisionModelGuid);
  v8 = v7;
  v9 = (unsigned int)v7->mNULL.mChild[0];
  v3->mCollisionMeshBundle.mOwner = (UFG::BasePhysicsObject *)&v3->vfptr;
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mCollisionMeshBundle.mPrev, 0x1723EA91u, v9);
  v32.m_quad = (__m128)v2->mPosition;
  hkRotationf::set(&v31, &v2->mOrientation);
  ((void (__fastcall *)(UFG::qBaseNodeRB *, hkRotationf *, __int64, char *, signed __int64))v8[2].mNULL.mChild[1]->mParent[1].mParent)(
    v8[2].mNULL.mChild[1],
    &v31,
    v10,
    &v29,
    -2i64);
  v3->mElevation = v30;
  *((_DWORD *)v3 + 181) ^= (*((_DWORD *)v3 + 181) ^ (HIDWORD(v8->mNULL.mChild[0]) != 0)) & 1;
  v11 = NtCurrentTeb()->Reserved1[11];
  v12 = v11[tls_index] + 16i64;
  if ( *((_BYTE *)v3 + 724) & 1 )
  {
    ++*(_BYTE *)(v11[tls_index] + 96i64);
    v13 = *(_BYTE *)(v12 + 80);
    v14 = v13;
    *(_DWORD *)(v12 + 4 * v14) = 3;
    *(_QWORD *)(v12 + 8 * v14 + 16) = "hkpCachingShapePhantom";
    *(_QWORD *)(v12 + 8 * v14 + 48) = 0i64;
    v15 = *(_BYTE *)(v12 + 81);
    if ( v13 > v15 )
      v15 = v13;
    *(_BYTE *)(v12 + 81) = v15;
    v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkpCachingShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(
                                      v16[11],
                                      448i64);
    if ( v17 )
      hkpCachingShapePhantom::hkpCachingShapePhantom(
        v17,
        (hkpShape *)v8[2].mNULL.mChild[1],
        (hkTransformf *)&v31,
        v8[3].mNULL.mChild[0][5].mUID);
    else
      v18 = 0i64;
  }
  else
  {
    ++*(_BYTE *)(v11[tls_index] + 96i64);
    v19 = *(_BYTE *)(v12 + 80);
    v20 = v19;
    *(_DWORD *)(v12 + 4 * v20) = 3;
    *(_QWORD *)(v12 + 8 * v20 + 16) = "hkpSimpleShapePhantom";
    *(_QWORD *)(v12 + 8 * v20 + 48) = 0i64;
    v21 = *(_BYTE *)(v12 + 81);
    if ( v19 > v21 )
      v21 = v19;
    *(_BYTE *)(v12 + 81) = v21;
    v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v23 = (hkpSimpleShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v22[11] + 8i64))(
                                     v22[11],
                                     448i64);
    if ( v23 )
      hkpSimpleShapePhantom::hkpSimpleShapePhantom(
        v23,
        (hkpShape *)v8[2].mNULL.mChild[1],
        (hkTransformf *)&v31,
        v8[3].mNULL.mChild[0][5].mUID);
    else
      v18 = 0i64;
  }
  v3->mPhantom = v18;
  v24 = *(_BYTE *)(v12 + 80);
  if ( v24 > 0 )
  {
    *(_BYTE *)(v12 + 80) = v24 - 1;
  }
  else
  {
    *(_BYTE *)(v12 + 80) = 0;
    *(_QWORD *)(v12 + 48) = 0i64;
    *(_QWORD *)(v12 + 16) = 0i64;
    *(_DWORD *)v12 = 3;
  }
  v25 = &v3->mUserData.simComponent;
  if ( v3->mUserData.simComponent.m_pPointer )
  {
    v26 = v25->mPrev;
    v27 = v3->mUserData.simComponent.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    v25->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
    v3->mUserData.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mUserData.simComponent.mPrev;
  }
  v3->mUserData.simComponent.m_pPointer = (UFG::SimComponent *)&v3->vfptr;
  v28 = v3->m_SafePointerList.mNode.mPrev;
  v28->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
  v25->mPrev = v28;
  v3->mUserData.simComponent.mNext = &v3->m_SafePointerList.mNode;
  v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
  v3->mPhantom->m_userData = (unsigned __int64)&v3->mUserData;
  UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
    (unsigned __int64)v8->mNULL.mParent,
    (hkpWorldObject *)&v3->mPhantom->vfptr);
  UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, (hkpPhantom *)&v3->mPhantom->vfptr, 1);
}

// File Line: 93
// RVA: 0x451B40
void __fastcall UFG::WaterPhantomComponent::~WaterPhantomComponent(UFG::WaterPhantomComponent *this)
{
  UFG::WaterPhantomComponent *v1; // rbx
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v2; // rdi
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v3; // rcx
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v4; // rax
  hkpPhantom *v5; // rdx
  hkpShapePhantom *v6; // rcx
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v7; // rdx
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v8; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterPhantomComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::WaterPhantomComponent::`vftable{for `UFG::BasePhysicsObject};
  if ( this == UFG::WaterPhantomComponent::s_WaterPhantomComponentpCurrentIterator )
    UFG::WaterPhantomComponent::s_WaterPhantomComponentpCurrentIterator = (UFG::WaterPhantomComponent *)&this->mPrev[-7].mNext;
  v2 = (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = (hkpPhantom *)&v1->mPhantom->vfptr;
  if ( v5 )
  {
    v1->mCollisionMeshBundle.mOwner = 0i64;
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, v5, 0i64);
    v6 = v1->mPhantom;
    if ( v6 )
      v6->vfptr->__vecDelDtor((hkBaseObject *)&v6->vfptr, 1u);
  }
  hkpAllCdBodyPairCollector::~hkpAllCdBodyPairCollector(&v1->mCollector);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mCollisionMeshBundle.mPrev);
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BasePhysicsObject::~BasePhysicsObject((UFG::BasePhysicsObject *)&v1->vfptr);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 111
// RVA: 0x47DFD0
void __fastcall UFG::WaterPhantomComponent::Update(UFG::WaterPhantomComponent *this, float deltaT)
{
  UFG::WaterPhantomComponent *v2; // rbx
  hkpShapePhantom *v3; // rcx

  v2 = this;
  if ( *((_BYTE *)this + 724) & 1 )
  {
    this->mCollector.vfptr->reset((hkpCdBodyPairCollector *)&this->mCollector);
    v3 = v2->mPhantom;
    if ( v3->m_world )
      ((void (__fastcall *)(hkpShapePhantom *, hkpAllCdBodyPairCollector *, _QWORD))v3->vfptr[9].__vecDelDtor)(
        v3,
        &v2->mCollector,
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
void __fastcall UFG::WaterPhantomComponent::ResourceUnloaded(UFG::WaterPhantomComponent *this, UFG::PhysicsResourceHandle *__formal)
{
  hkpPhantom *v2; // rdx
  UFG::WaterPhantomComponent *v3; // rbx
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v4; // rcx

  v2 = (hkpPhantom *)this->mPrev;
  v3 = this;
  this->mUserData.simComponent.mNext = 0i64;
  if ( v2 )
  {
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, v2, 0i64);
    v4 = v3->mPrev;
    if ( v4 )
      ((void (__fastcall *)(UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *, signed __int64))v4->mPrev->mPrev)(
        v4,
        1i64);
    v3->mPrev = 0i64;
  }
}

// File Line: 171
// RVA: 0x46A8B0
bool __fastcall UFG::WaterPhantomComponent::IntersectRay(UFG::WaterPhantomComponent *this, hkVector4f *start, hkVector4f *end)
{
  hkpShapePhantom *v3; // rbx
  hkVector4f *v4; // rdi
  UFG::WaterPhantomComponent *v5; // rsi
  hkVector4f v7; // [rsp+20h] [rbp-98h]
  hkVector4f v8; // [rsp+30h] [rbp-88h]
  int v9; // [rsp+40h] [rbp-78h]
  __int64 v10; // [rsp+48h] [rbp-70h]
  __int64 v11; // [rsp+50h] [rbp-68h]
  __int64 v12; // [rsp+58h] [rbp-60h]
  char v13; // [rsp+60h] [rbp-58h]
  float v14; // [rsp+70h] [rbp-48h]
  int v15; // [rsp+74h] [rbp-44h]
  int v16; // [rsp+80h] [rbp-38h]
  int v17; // [rsp+A0h] [rbp-18h]
  char v18; // [rsp+C0h] [rbp+8h]

  v3 = this->mPhantom;
  ++s_WaterphantomRaycasts;
  v4 = end;
  v5 = this;
  v9 = 0;
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  v14 = 1.0;
  v15 = -1;
  v17 = 0;
  v16 = -1;
  hkVector4f::setTransformedInversePos(&v7, &v3->m_motionState.m_transform, start);
  hkVector4f::setTransformedInversePos(&v8, &v3->m_motionState.m_transform, v4);
  ((void (__fastcall *)(hkpShape *, char *, hkVector4f *, char *))v5->mPhantom->m_collidable.m_shape->vfptr[2].__first_virtual_table_function__)(
    v5->mPhantom->m_collidable.m_shape,
    &v18,
    &v7,
    &v13);
  return v14 < 1.0;
}

