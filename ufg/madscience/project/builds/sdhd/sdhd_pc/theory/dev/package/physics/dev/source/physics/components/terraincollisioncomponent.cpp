// File Line: 65
// RVA: 0x1458DE0
__int64 dynamic_initializer_for__UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList__);
}

// File Line: 66
// RVA: 0xAB740
const char *__fastcall UFG::TerrainCollisionComponent::GetTypeName(UFG::TerrainCollisionComponent *this)
{
  return "TerrainCollisionComponent";
}

// File Line: 78
// RVA: 0x9A070
void __fastcall UFG::TerrainCollisionComponent::TerrainCollisionComponent(
        UFG::TerrainCollisionComponent *this,
        unsigned int name_uid,
        int width,
        int height,
        unsigned __int16 *data,
        float quant_offset,
        float quant_scale,
        UFG::qVector3 *dimensions,
        UFG::qVector3 *pos)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *mPrev; // rax
  __int64 v17; // rbx
  char v18; // dl
  char v19; // cl
  _QWORD **Value; // rax
  hkArray<unsigned short,hkContainerHeapAllocator> *v21; // rax
  int v22; // edx
  char v23; // al

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  this->mUserData.isBoat = 0;
  this->mUserData.simComponent.mPrev = &this->mUserData.simComponent;
  this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  this->mUserData.simComponent.m_pPointer = 0i64;
  this->mPrev = &this->UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent>;
  this->mNext = &this->UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TerrainCollisionComponent::`vftable{for `UFG::SimComponent};
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::TerrainCollisionComponent::`vftable{for `UFG::BasePhysicsObject};
  this->mWidth = width;
  this->mHeight = height;
  this->mQuantOffset = quant_offset;
  this->mQuantScale = quant_scale;
  y = pos->y;
  z = pos->z;
  this->mPosition.x = pos->x;
  this->mPosition.y = y;
  this->mPosition.z = z;
  v14 = dimensions->y;
  v15 = dimensions->z;
  this->mDimensions.x = dimensions->x;
  this->mDimensions.y = v14;
  this->mDimensions.z = v15;
  this->mRigidBody = 0i64;
  this->mHeightFieldShape = 0i64;
  mPrev = UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList.mNode.mPrev;
  UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *)&UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList;
  UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList.mNode.mPrev = &this->UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::TerrainCollisionComponent::_TerrainCollisionComponentTypeUID,
    "TerrainCollisionComponent");
  v17 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v18 = ++*(_BYTE *)(v17 + 80);
  *(_DWORD *)(v17 + 4i64 * v18) = 3;
  *(_QWORD *)(v17 + 8i64 * v18 + 16) = "TerrainCollisionElementArray";
  *(_QWORD *)(v17 + 8i64 * v18 + 48) = 0i64;
  v19 = *(_BYTE *)(v17 + 81);
  if ( v18 > v19 )
    v19 = v18;
  *(_BYTE *)(v17 + 81) = v19;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (hkArray<unsigned short,hkContainerHeapAllocator> *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                              Value[11],
                                                              16i64);
  if ( v21 )
  {
    v22 = this->mHeight * this->mWidth;
    v21->m_data = data;
    v21->m_size = v22;
    v21->m_capacityAndFlags = v22 | 0x80000000;
  }
  else
  {
    v21 = 0i64;
  }
  this->mData = v21;
  v23 = *(_BYTE *)(v17 + 80);
  if ( v23 > 0 )
  {
    *(_BYTE *)(v17 + 80) = v23 - 1;
  }
  else
  {
    *(_BYTE *)(v17 + 80) = 0;
    *(_DWORD *)v17 = 3;
    *(_QWORD *)(v17 + 16) = 0i64;
    *(_QWORD *)(v17 + 48) = 0i64;
  }
}

// File Line: 90
// RVA: 0x9D540
void __fastcall UFG::TerrainCollisionComponent::~TerrainCollisionComponent(UFG::TerrainCollisionComponent *this)
{
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *v2; // rbx
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *mPrev; // rcx
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *mNext; // rax
  hkArray<unsigned short,hkContainerHeapAllocator> *mData; // rsi
  int m_capacityAndFlags; // r8d
  _QWORD **Value; // rax
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *v8; // rdx
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *v9; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TerrainCollisionComponent::`vftable{for `UFG::SimComponent};
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::TerrainCollisionComponent::`vftable{for `UFG::BasePhysicsObject};
  if ( this == UFG::TerrainCollisionComponent::s_TerrainCollisionComponentpCurrentIterator )
    UFG::TerrainCollisionComponent::s_TerrainCollisionComponentpCurrentIterator = (UFG::TerrainCollisionComponent *)&this->mPrev[-7].mNext;
  v2 = &this->UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  mData = this->mData;
  if ( mData )
  {
    mData->m_size = 0;
    m_capacityAndFlags = mData->m_capacityAndFlags;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        mData->m_data,
        2 * (m_capacityAndFlags & 0x3FFFFFFF));
    mData->m_data = 0i64;
    mData->m_capacityAndFlags = 0x80000000;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkArray<unsigned short,hkContainerHeapAllocator> *, __int64))(*Value[11] + 16i64))(
      Value[11],
      mData,
      16i64);
  }
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BasePhysicsObject::~BasePhysicsObject(&this->UFG::BasePhysicsObject);
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 98
// RVA: 0xADBB0
void __fastcall UFG::TerrainCollisionComponent::OnAttach(UFG::TerrainCollisionComponent *this, UFG::SimObject *object)
{
  __int64 v3; // rdi
  char v4; // dl
  char v5; // cl
  __m128 x_low; // xmm2
  __m128 y_low; // xmm1
  __m128 v8; // xmm3
  __m128 z_low; // xmm6
  __m128 v10; // xmm7
  __m128 v11; // xmm8
  _QWORD **Value; // rax
  hkpCompressedSampledHeightFieldShape *v13; // rax
  hkpCompressedSampledHeightFieldShape *v14; // rax
  hkpCompressedSampledHeightFieldShape *v15; // rsi
  _QWORD **v16; // rax
  hkpTriSampledHeightFieldCollection *v17; // rax
  hkpTriSampledHeightFieldCollection *v18; // rax
  hkpTriSampledHeightFieldCollection *v19; // r14
  _QWORD **v20; // rax
  hkpTriSampledHeightFieldBvTreeShape *v21; // rax
  hkpShape *v22; // rax
  hkpShape *v23; // r15
  unsigned int v24; // r14d
  unsigned int v25; // eax
  UFG::qBaseTreeRB *v26; // rsi
  UFG::qBaseTreeRB *v27; // rax
  unsigned __int64 v28; // r8
  _QWORD **v29; // rax
  hkpRigidBody *v30; // rax
  char v31; // al
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::qReflectHandleBase v36; // [rsp+30h] [rbp-A8h] BYREF
  char v37; // [rsp+58h] [rbp-80h]
  __m128 info; // [rsp+60h] [rbp-78h] BYREF
  int info_16; // [rsp+70h] [rbp-68h]
  int info_20; // [rsp+74h] [rbp-64h]
  _OWORD info_24[4]; // [rsp+78h] [rbp-60h] BYREF
  hkQsTransformf v42; // [rsp+B8h] [rbp-20h] BYREF
  hkpRigidBodyCinfo v43; // [rsp+E8h] [rbp+10h] BYREF
  hkTransformf transform; // [rsp+1C8h] [rbp+F0h] BYREF
  hkTransformf transformOut; // [rsp+208h] [rbp+130h] BYREF
  void *v46; // [rsp+2A8h] [rbp+1D0h]

  info.m128_u64[1] = -2i64;
  if ( !this->mRigidBody )
  {
    v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v4 = ++*(_BYTE *)(v3 + 80);
    *(_DWORD *)(v3 + 4i64 * v4) = 3;
    *(_QWORD *)(v3 + 8i64 * v4 + 16) = "TerrainCollisionElement";
    *(_QWORD *)(v3 + 8i64 * v4 + 48) = 0i64;
    v5 = *(_BYTE *)(v3 + 81);
    if ( v4 > v5 )
      v5 = v4;
    *(_BYTE *)(v3 + 81) = v5;
    v37 = 0;
    info_16 = this->mWidth;
    info_20 = this->mHeight;
    LODWORD(info_24[0]) = 0;
    DWORD1(info_24[0]) = LODWORD(this->mDimensions.z);
    x_low = (__m128)LODWORD(this->mDimensions.x);
    x_low.m128_f32[0] = x_low.m128_f32[0] / (float)(info_16 - 1);
    y_low = (__m128)LODWORD(this->mDimensions.y);
    y_low.m128_f32[0] = y_low.m128_f32[0] / (float)(info_20 - 1);
    info = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, y_low), _xmm);
    v8 = 0i64;
    v8.m128_f32[0] = (float)1;
    info_24[0] = v8;
    info_24[3] = _mm_shuffle_ps(v8, v8, 21);
    info_24[1] = _xmm;
    info_24[2] = _xmm;
    hkTransformf::set4x4ColumnMajor(&transform, (const float *)info_24);
    hkQsTransformf::setFromTransformNoScale(&v42, &transform);
    hkQsTransformf::copyToTransform(&v42, &transformOut);
    z_low = (__m128)LODWORD(this->mPosition.z);
    v10 = (__m128)LODWORD(this->mPosition.y);
    v11 = (__m128)LODWORD(this->mPosition.x);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (hkpCompressedSampledHeightFieldShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                    Value[11],
                                                    176i64);
    v46 = v13;
    if ( v13 )
    {
      hkpCompressedSampledHeightFieldShape::hkpCompressedSampledHeightFieldShape(
        v13,
        (hkpSampledHeightFieldBaseCinfo *)&info,
        this->mData,
        this->mQuantOffset,
        this->mQuantScale);
      v15 = v14;
    }
    else
    {
      v15 = 0i64;
    }
    v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkpTriSampledHeightFieldCollection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(
                                                  v16[11],
                                                  96i64);
    v46 = v17;
    if ( v17 )
    {
      hkpTriSampledHeightFieldCollection::hkpTriSampledHeightFieldCollection(v17, v15, hkConvexShapeDefaultRadius);
      v19 = v18;
    }
    else
    {
      v19 = 0i64;
    }
    hkReferencedObject::removeReference(v15);
    v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v21 = (hkpTriSampledHeightFieldBvTreeShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v20[11] + 8i64))(
                                                   v20[11],
                                                   80i64);
    v46 = v21;
    if ( v21 )
    {
      hkpTriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape(v21, v19, (hkBool)1);
      v23 = v22;
    }
    else
    {
      v23 = 0i64;
    }
    hkReferencedObject::removeReference(v19);
    this->mHeightFieldShape = v15;
    hkpRigidBodyCinfo::hkpRigidBodyCinfo(&v43);
    v43.m_position.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v11, z_low), _mm_unpacklo_ps(v10, (__m128)0i64));
    v43.m_rotation = v42.m_rotation;
    v43.m_motionType.m_storage = 5;
    v43.m_shape = v23;
    v43.m_collisionFilterInfo = 9;
    UFG::qReflectHandleBase::qReflectHandleBase(&v36);
    v36.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
    v24 = UFG::qStringHashUpper32("STATIC_HEIGHTFIELD", 0xFFFFFFFF);
    if ( (_S2_3 & 1) != 0 )
    {
      v25 = default_uid;
    }
    else
    {
      _S2_3 |= 1u;
      v25 = UFG::qStringHashUpper32("default", 0xFFFFFFFF);
      default_uid = v25;
    }
    if ( v25 )
      v26 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, v25);
    else
      v26 = 0i64;
    if ( v24 && (v27 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, v24)) != 0i64 )
      v28 = *(_QWORD *)&v27->mNULL.mUID;
    else
      v28 = *(_QWORD *)&v26->mNULL.mUID;
    UFG::qReflectHandleBase::Init(&v36, v36.mTypeUID, v28);
    v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v30 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v29[11] + 8i64))(v29[11], 720i64);
    v46 = v30;
    if ( v30 )
      hkpRigidBody::hkpRigidBody(v30, &v43);
    this->mRigidBody = v30;
    v31 = *(_BYTE *)(v3 + 80);
    if ( v31 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v31 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
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
    this->mUserData.simComponent.m_pPointer = this;
    v35 = this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v35->mNext = p_simComponent;
    p_simComponent->mPrev = v35;
    this->mUserData.simComponent.mNext = &this->m_SafePointerList.mNode;
    this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_simComponent;
    this->mRigidBody->m_userData = (unsigned __int64)&this->mUserData;
    UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(v36.mData->mBaseNode.mUID, this->mRigidBody);
    hkpWorld::addEntity(UFG::BasePhysicsSystem::mInstance->mWorld, this->mRigidBody, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v36);
  }
}

// File Line: 167
// RVA: 0xAE0A0
void __fastcall UFG::TerrainCollisionComponent::OnDetach(UFG::TerrainCollisionComponent *this)
{
  if ( this->mRigidBody )
  {
    hkReferencedObject::removeReference(this->mHeightFieldShape);
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, this->mRigidBody, 0);
    hkReferencedObject::removeReference(this->mRigidBody);
    this->mRigidBody->m_userData = 0i64;
    this->mRigidBody = 0i64;
  }
}

