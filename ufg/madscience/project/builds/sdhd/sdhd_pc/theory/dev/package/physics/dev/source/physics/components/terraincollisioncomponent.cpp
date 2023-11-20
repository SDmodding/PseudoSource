// File Line: 65
// RVA: 0x1458DE0
__int64 dynamic_initializer_for__UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList__);
}

// File Line: 66
// RVA: 0xAB740
const char *__fastcall UFG::TerrainCollisionComponent::GetTypeName(UFG::TerrainCollisionComponent *this)
{
  return "TerrainCollisionComponent";
}

// File Line: 78
// RVA: 0x9A070
void __fastcall UFG::TerrainCollisionComponent::TerrainCollisionComponent(UFG::TerrainCollisionComponent *this, unsigned int name_uid, int width, int height, unsigned __int16 *data, float quant_offset, float quant_scale, UFG::qVector3 *dimensions, UFG::qVector3 *pos)
{
  int v9; // edi
  int v10; // ebx
  UFG::TerrainCollisionComponent *v11; // rsi
  UFG::BasePhysicsObject *v12; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v13; // ST38_8
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *v14; // rcx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *v19; // rax
  signed __int64 v20; // rbx
  char v21; // dl
  __int64 v22; // rax
  char v23; // cl
  _QWORD **v24; // rax
  __int64 v25; // rax
  int v26; // edx
  char v27; // al

  v9 = height;
  v10 = width;
  v11 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v12 = (UFG::BasePhysicsObject *)&v11->vfptr;
  v12->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable';
  v11->mUserData.isBoat = 0;
  v13 = &v11->mUserData.simComponent;
  v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v11->mUserData.simComponent.m_pPointer = 0i64;
  v14 = (UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *)&v11->mPrev;
  v14->mPrev = v14;
  v14->mNext = v14;
  v11->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TerrainCollisionComponent::`vftable'{for `UFG::SimComponent'};
  v12->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::TerrainCollisionComponent::`vftable'{for `UFG::BasePhysicsObject'};
  v11->mWidth = v10;
  v11->mHeight = v9;
  v11->mQuantOffset = quant_offset;
  v11->mQuantScale = quant_scale;
  v15 = pos->y;
  v16 = pos->z;
  v11->mPosition.x = pos->x;
  v11->mPosition.y = v15;
  v11->mPosition.z = v16;
  v17 = dimensions->y;
  v18 = dimensions->z;
  v11->mDimensions.x = dimensions->x;
  v11->mDimensions.y = v17;
  v11->mDimensions.z = v18;
  v11->mRigidBody = 0i64;
  v11->mHeightFieldShape = 0i64;
  v19 = UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList.mNode.mPrev;
  UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *)&v11->mPrev;
  v14->mPrev = v19;
  v11->mNext = (UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *)&UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList;
  UFG::TerrainCollisionComponent::s_TerrainCollisionComponentList.mNode.mPrev = (UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *)&v11->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v11->vfptr,
    UFG::TerrainCollisionComponent::_TerrainCollisionComponentTypeUID,
    "TerrainCollisionComponent");
  v20 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v21 = ++*(_BYTE *)(v20 + 80);
  v22 = v21;
  *(_DWORD *)(v20 + 4 * v22) = 3;
  *(_QWORD *)(v20 + 8 * v22 + 16) = "TerrainCollisionElementArray";
  *(_QWORD *)(v20 + 8 * v22 + 48) = 0i64;
  v23 = *(_BYTE *)(v20 + 81);
  if ( v21 > v23 )
    v23 = v21;
  *(_BYTE *)(v20 + 81) = v23;
  v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(v24[11], 16i64);
  if ( v25 )
  {
    v26 = v11->mHeight * v11->mWidth;
    *(_QWORD *)v25 = data;
    *(_DWORD *)(v25 + 8) = v26;
    *(_DWORD *)(v25 + 12) = v26 | 0x80000000;
  }
  else
  {
    v25 = 0i64;
  }
  v11->mData = (hkArray<unsigned short,hkContainerHeapAllocator> *)v25;
  v27 = *(_BYTE *)(v20 + 80);
  if ( v27 > 0 )
  {
    *(_BYTE *)(v20 + 80) = v27 - 1;
  }
  else
  {
    *(_BYTE *)(v20 + 80) = 0;
    *(_DWORD *)v20 = 3;
    *(_QWORD *)(v20 + 16) = 0i64;
    *(_QWORD *)(v20 + 48) = 0i64;
  }
}

// File Line: 90
// RVA: 0x9D540
void __fastcall UFG::TerrainCollisionComponent::~TerrainCollisionComponent(UFG::TerrainCollisionComponent *this)
{
  UFG::TerrainCollisionComponent *v1; // rdi
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *v2; // rbx
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *v3; // rcx
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *v4; // rax
  hkArray<unsigned short,hkContainerHeapAllocator> *v5; // rsi
  int v6; // er8
  _QWORD **v7; // rax
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *v8; // rdx
  UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TerrainCollisionComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::TerrainCollisionComponent::`vftable'{for `UFG::BasePhysicsObject'};
  if ( this == UFG::TerrainCollisionComponent::s_TerrainCollisionComponentpCurrentIterator )
    UFG::TerrainCollisionComponent::s_TerrainCollisionComponentpCurrentIterator = (UFG::TerrainCollisionComponent *)&this->mPrev[-7].mNext;
  v2 = (UFG::qNode<UFG::TerrainCollisionComponent,UFG::TerrainCollisionComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mData;
  if ( v5 )
  {
    v5->m_size = 0;
    v6 = v5->m_capacityAndFlags;
    if ( v6 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v5->m_data,
        2 * (v6 & 0x3FFFFFFF));
    v5->m_data = 0i64;
    v5->m_capacityAndFlags = 2147483648;
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkArray<unsigned short,hkContainerHeapAllocator> *, signed __int64))(*v7[11] + 16i64))(
      v7[11],
      v5,
      16i64);
  }
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BasePhysicsObject::~BasePhysicsObject((UFG::BasePhysicsObject *)&v1->vfptr);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 98
// RVA: 0xADBB0
void __fastcall UFG::TerrainCollisionComponent::OnAttach(UFG::TerrainCollisionComponent *this, UFG::SimObject *object)
{
  UFG::TerrainCollisionComponent *v2; // rbx
  signed __int64 v3; // rdi
  char v4; // dl
  __int64 v5; // rax
  char v6; // cl
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  __m128 v12; // xmm8
  _QWORD **v13; // rax
  hkpCompressedSampledHeightFieldShape *v14; // rax
  hkpSampledHeightFieldShape *v15; // rax
  hkpSampledHeightFieldShape *v16; // rsi
  _QWORD **v17; // rax
  hkpTriSampledHeightFieldCollection *v18; // rax
  hkpTriSampledHeightFieldCollection *v19; // rax
  hkpTriSampledHeightFieldCollection *v20; // r14
  _QWORD **v21; // rax
  hkpTriSampledHeightFieldBvTreeShape *v22; // rax
  hkpShape *v23; // rax
  hkpShape *v24; // r15
  unsigned int v25; // er14
  unsigned int v26; // eax
  UFG::qBaseTreeRB *v27; // rsi
  UFG::qBaseTreeRB *v28; // rax
  unsigned __int64 v29; // r8
  _QWORD **v30; // rax
  hkpRigidBody *v31; // rax
  char v32; // al
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v33; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qReflectHandleBase v37; // [rsp+30h] [rbp-A8h]
  char v38; // [rsp+58h] [rbp-80h]
  hkpSampledHeightFieldBaseCinfo info; // [rsp+60h] [rbp-78h]
  __int128 v40; // [rsp+98h] [rbp-40h]
  __m128 v41; // [rsp+A8h] [rbp-30h]
  hkQsTransformf v42; // [rsp+B8h] [rbp-20h]
  hkpRigidBodyCinfo v43; // [rsp+E8h] [rbp+10h]
  hkTransformf transform; // [rsp+1C8h] [rbp+F0h]
  hkTransformf transformOut; // [rsp+208h] [rbp+130h]
  void *v46; // [rsp+2A8h] [rbp+1D0h]

  info.m_scale.m_quad.m128_u64[1] = -2i64;
  v2 = this;
  if ( !this->mRigidBody )
  {
    v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v4 = ++*(_BYTE *)(v3 + 80);
    v5 = v4;
    *(_DWORD *)(v3 + 4 * v5) = 3;
    *(_QWORD *)(v3 + 8 * v5 + 16) = "TerrainCollisionElement";
    *(_QWORD *)(v3 + 8 * v5 + 48) = 0i64;
    v6 = *(_BYTE *)(v3 + 81);
    if ( v4 > v6 )
      v6 = v4;
    *(_BYTE *)(v3 + 81) = v6;
    v38 = 0;
    info.m_xRes = v2->mWidth;
    info.m_zRes = v2->mHeight;
    info.m_minHeight = 0.0;
    info.m_maxHeight = v2->mDimensions.z;
    v7 = (__m128)LODWORD(v2->mDimensions.x);
    v7.m128_f32[0] = v7.m128_f32[0] / (float)(info.m_xRes - 1);
    v8 = (__m128)LODWORD(v2->mDimensions.y);
    v8.m128_f32[0] = v8.m128_f32[0] / (float)(info.m_zRes - 1);
    info.m_scale.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v7, v8), _xmm);
    v9 = 0i64;
    v9.m128_f32[0] = (float)1;
    *(__m128 *)&info.m_minHeight = v9;
    v41 = _mm_shuffle_ps(v9, v9, 21);
    *(__m128 *)(&info.m_useProjectionBasedHeight + 8) = _xmm;
    v40 = _xmm;
    hkTransformf::set4x4ColumnMajor(&transform, &info.m_minHeight);
    hkQsTransformf::setFromTransformNoScale(&v42, &transform);
    hkQsTransformf::copyToTransform(&v42, &transformOut);
    v10 = (__m128)LODWORD(v2->mPosition.z);
    v11 = (__m128)LODWORD(v2->mPosition.y);
    v12 = (__m128)LODWORD(v2->mPosition.x);
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkpCompressedSampledHeightFieldShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(
                                                    v13[11],
                                                    176i64);
    v46 = v14;
    if ( v14 )
    {
      hkpCompressedSampledHeightFieldShape::hkpCompressedSampledHeightFieldShape(
        v14,
        &info,
        v2->mData,
        v2->mQuantOffset,
        v2->mQuantScale);
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (hkpTriSampledHeightFieldCollection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(
                                                  v17[11],
                                                  96i64);
    v46 = v18;
    if ( v18 )
    {
      hkpTriSampledHeightFieldCollection::hkpTriSampledHeightFieldCollection(v18, v16, hkConvexShapeDefaultRadius);
      v20 = v19;
    }
    else
    {
      v20 = 0i64;
    }
    hkReferencedObject::removeReference((hkReferencedObject *)&v16->vfptr);
    v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (hkpTriSampledHeightFieldBvTreeShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(
                                                   v21[11],
                                                   80i64);
    v46 = v22;
    if ( v22 )
    {
      hkpTriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape(v22, v20, (hkBool)1);
      v24 = v23;
    }
    else
    {
      v24 = 0i64;
    }
    hkReferencedObject::removeReference((hkReferencedObject *)&v20->vfptr);
    v2->mHeightFieldShape = (hkpCompressedSampledHeightFieldShape *)v16;
    hkpRigidBodyCinfo::hkpRigidBodyCinfo(&v43);
    v43.m_position.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v12, v10), _mm_unpacklo_ps(v11, (__m128)0i64));
    v43.m_rotation = v42.m_rotation;
    v43.m_motionType.m_storage = 5;
    v43.m_shape = v24;
    v43.m_collisionFilterInfo = 9;
    UFG::qReflectHandleBase::qReflectHandleBase(&v37);
    v37.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
    v25 = UFG::qStringHashUpper32("STATIC_HEIGHTFIELD", 0xFFFFFFFF);
    if ( _S2_3 & 1 )
    {
      v26 = default_uid;
    }
    else
    {
      _S2_3 |= 1u;
      v26 = UFG::qStringHashUpper32("default", 0xFFFFFFFF);
      default_uid = v26;
    }
    if ( v26 )
      v27 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, v26);
    else
      v27 = 0i64;
    if ( v25 && (v28 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, v25)) != 0i64 )
      v29 = *(_QWORD *)&v28->mNULL.mUID;
    else
      v29 = *(_QWORD *)&v27->mNULL.mUID;
    UFG::qReflectHandleBase::Init(&v37, v37.mTypeUID, v29);
    v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v31 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v30[11] + 8i64))(v30[11], 720i64);
    v46 = v31;
    if ( v31 )
      hkpRigidBody::hkpRigidBody(v31, &v43);
    v2->mRigidBody = v31;
    v32 = *(_BYTE *)(v3 + 80);
    if ( v32 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v32 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
    v33 = &v2->mUserData.simComponent;
    if ( v2->mUserData.simComponent.m_pPointer )
    {
      v34 = v33->mPrev;
      v35 = v2->mUserData.simComponent.mNext;
      v34->mNext = v35;
      v35->mPrev = v34;
      v33->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v33->mPrev;
      v2->mUserData.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mUserData.simComponent.mPrev;
    }
    v2->mUserData.simComponent.m_pPointer = (UFG::SimComponent *)&v2->vfptr;
    v36 = v2->m_SafePointerList.mNode.mPrev;
    v36->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v33->mPrev;
    v33->mPrev = v36;
    v2->mUserData.simComponent.mNext = &v2->m_SafePointerList.mNode;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v33->mPrev;
    v2->mRigidBody->m_userData = (unsigned __int64)&v2->mUserData;
    UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
      v37.mData->mBaseNode.mUID,
      (hkpWorldObject *)&v2->mRigidBody->vfptr);
    hkpWorld::addEntity(
      UFG::BasePhysicsSystem::mInstance->mWorld,
      (hkpEntity *)&v2->mRigidBody->vfptr,
      HK_ENTITY_ACTIVATION_DO_ACTIVATE);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v37);
  }
}tity(
      UFG::BasePhysicsSystem::mIns

// File Line: 167
// RVA: 0xAE0A0
void __fastcall UFG::TerrainCollisionComponent::OnDetach(UFG::TerrainCollisionComponent *this)
{
  UFG::TerrainCollisionComponent *v1; // rbx

  v1 = this;
  if ( this->mRigidBody )
  {
    hkReferencedObject::removeReference((hkReferencedObject *)&this->mHeightFieldShape->vfptr);
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, v1->mRigidBody, 0);
    hkReferencedObject::removeReference((hkReferencedObject *)&v1->mRigidBody->vfptr);
    v1->mRigidBody->m_userData = 0i64;
    v1->mRigidBody = 0i64;
  }
}

