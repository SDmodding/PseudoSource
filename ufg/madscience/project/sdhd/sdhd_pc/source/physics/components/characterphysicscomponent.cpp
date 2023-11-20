// File Line: 81
// RVA: 0x15142F0
__int64 dynamic_initializer_for__UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList__);
}

// File Line: 82
// RVA: 0x4663F0
UFG::ComponentIDDesc *__fastcall UFG::CharacterPhysicsComponent::GetDesc(UFG::CharacterPhysicsComponent *this)
{
  return &UFG::CharacterPhysicsComponent::_TypeIDesc;
}

// File Line: 84
// RVA: 0x1513C80
__int64 dynamic_initializer_for__UFG::CharacterPhysicsComponent::mAllocator__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::CharacterPhysicsComponent::mAllocator);
  return atexit(dynamic_atexit_destructor_for__UFG::CharacterPhysicsComponent::mAllocator__);
}

// File Line: 140
// RVA: 0x448B40
void __fastcall UFG::CharacterCollisionListener::CharacterCollisionListener(UFG::CharacterCollisionListener *this, UFG::CharacterPhysicsComponent *charPhysComp)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  this->vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
  this->vfptr = (hkpContactListenerVtbl *)&UFG::CharacterCollisionListener::`vftable;
  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mCharacterPhysicsComponent.mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->mCharacterPhysicsComponent.m_pPointer = 0i64;
  if ( this->mCharacterPhysicsComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)charPhysComp;
  if ( charPhysComp )
  {
    v5 = charPhysComp->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &charPhysComp->m_SafePointerList.mNode;
    charPhysComp->m_SafePointerList.mNode.mPrev = v2;
  }
}

// File Line: 150
// RVA: 0x486950
void __fastcall UFG::CharacterCollisionListener::contactPointCallback(UFG::CharacterCollisionListener *this, hkpContactPointEvent *event)
{
  hkpContactPointEvent *v2; // rbx
  UFG::CharacterCollisionListener *v3; // rdi
  hkContactPoint *cp; // r10
  float v5; // xmm7_4
  float v6; // xmm8_4
  float *v7; // rax
  __m128 v8; // xmm6
  __m128 v9; // xmm0
  UFG::SimComponent *v10; // rax
  __m128 v11; // xmm1
  float v12; // xmm2_4
  hkVector4f direction; // [rsp+30h] [rbp-68h]
  hkVector4f v14; // [rsp+40h] [rbp-58h]
  hkSimdFloat32 result; // [rsp+50h] [rbp-48h]

  v2 = event;
  v3 = this;
  if ( UFG::enableCurbClipping )
  {
    cp = event->m_contactPoint;
    v5 = cp->m_position.m_quad.m128_f32[2];
    v6 = *(float *)&this->mCharacterPhysicsComponent.m_pPointer[5].m_Flags;
    v7 = event->m_separatingVelocity;
    if ( v7 )
      v8.m128_f32[0] = *v7;
    else
      v8 = hkpSimpleContactConstraintUtil::calculateSeparatingVelocity(
             &result,
             event->m_bodies[0],
             event->m_bodies[1],
             &event->m_bodies[0]->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1,
             &event->m_bodies[1]->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1,
             cp)->m_real;
    v9 = v2->m_contactPoint->m_separatingNormal.m_quad;
    v10 = v3->mCharacterPhysicsComponent.m_pPointer;
    direction.m_quad = (__m128)_xmm;
    result.m_real = v9;
    hkVector4f::setRotatedDir(
      &v14,
      (hkQuaternionf *)&v10[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev[30],
      &direction);
    v11 = _mm_mul_ps(v2->m_contactPoint->m_separatingNormal.m_quad, v14.m_quad);
    v12 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170));
    if ( (float)(v5 - v6) < 0.25
      && COERCE_FLOAT(v8.m128_i32[0] & _xmm) > 0.0099999998
      && result.m_real.m128_f32[2] < 0.70700002
      && v12 > 0.0 )
    {
      result.m_real = _xmm;
      hkpContactPointEvent::setNormal(v2, (hkVector4f *)&result);
    }
  }
}

// File Line: 181
// RVA: 0x4690A0
void UFG::CharacterPhysicsComponent::Initialize(void)
{
  UFG::allocator::free_link *v0; // rax

  v0 = UFG::qMalloc(0x48ui64, "CharacterPhysicsComponentManager", 0i64);
  if ( v0 )
  {
    v0[1].mNext = 0i64;
    v0->mNext = 0i64;
    LODWORD(v0[8].mNext) = 0;
    v0[2].mNext = 0i64;
    v0[3].mNext = 0i64;
    v0[4].mNext = 0i64;
    v0[5].mNext = 0i64;
    v0[6].mNext = 0i64;
    v0[7].mNext = 0i64;
  }
  else
  {
    v0 = 0i64;
  }
  UFG::CharacterPhysicsComponentManager::mInstance = (UFG::CharacterPhysicsComponentManager *)v0;
  UFG::CharacterPhysicsComponent::mAllocatorBuffer = UFG::qMemoryPool::Allocate(
                                                       &gPhysicsMemoryPool,
                                                       0x38680ui64,
                                                       "CharacterPhysicsPool",
                                                       0i64,
                                                       1u);
  UFG::qFixedAllocator::Init(
    &UFG::CharacterPhysicsComponent::mAllocator,
    UFG::CharacterPhysicsComponent::mAllocatorBuffer,
    231040,
    608,
    "CharacterPhysicsPool");
}

// File Line: 247
// RVA: 0x448BD0
void __fastcall UFG::CharacterPhysicsComponent::CharacterPhysicsComponent(UFG::CharacterPhysicsComponent *this, UFG::qVector4 *pos, unsigned int name_uid, component_CharacterPhysics *data)
{
  component_CharacterPhysics *v4; // r14
  UFG::CharacterPhysicsComponent *v5; // rbx
  UFG::BasePhysicsObject *v6; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v7; // rax
  signed int v8; // edi
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v9; // rsi
  UFG::qSafePointer<UFG::SimComponent,UFG::WaterFloatingTrackerComponent> *v10; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // rax
  signed __int64 v12; // rax
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v17; // rax
  UFG::CharacterPhysicsComponentManager *v18; // r13
  UFG::CharacterCollisionMode v19; // esi
  hkpShape **v20; // r15
  float *v21; // r14
  float *v22; // r12
  _QWORD **v23; // rax
  hkpListShape *v24; // rax
  hkpListShape *v25; // rax
  hkpListShape *v26; // r14
  _QWORD **v27; // rax
  CharacterRigidBody *v28; // rax
  CharacterRigidBody *v29; // rax
  __m128 v30; // xmm0
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v31; // rcx
  const char *v32; // rax
  UFG::allocator::free_link *v33; // rax
  hkpContactListener *v34; // rax
  hkpContactListener *v35; // rdx
  unsigned __int16 v36; // cx
  signed int v37; // er8
  signed int v38; // eax
  int *v39; // rcx
  UFG::SimComponent *v40; // rcx
  hkpCharacterRigidBodyCinfo info; // [rsp+30h] [rbp-79h]
  __int64 v42; // [rsp+B0h] [rbp+7h]
  UFG::HavokUserData *v43; // [rsp+B8h] [rbp+Fh]
  unsigned int *v44; // [rsp+110h] [rbp+67h]
  hkpListShape *v45; // [rsp+120h] [rbp+77h]
  int v46; // [rsp+128h] [rbp+7Fh]

  v42 = -2i64;
  v4 = data;
  v5 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v6 = (UFG::BasePhysicsObject *)&v5->vfptr;
  v45 = (hkpListShape *)v6;
  v6->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  v43 = &v5->mUserData;
  v5->mUserData.isBoat = 0;
  v7 = &v5->mUserData.simComponent;
  *(_QWORD *)&info.m_maxLinearVelocity = v7;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v8 = 0;
  v5->mUserData.simComponent.m_pPointer = 0i64;
  v9 = (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *)&v5->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterPhysicsComponent::`vftable{for `UFG::SimComponent};
  v6->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::CharacterPhysicsComponent::`vftable{for `UFG::BasePhysicsObject};
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::RebindingComponentHandle<UFG::RagdollComponent,0>(&v5->mRagdollComponent);
  v10 = &v5->mWaterTracker;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v5->mWaterTracker.m_pPointer = 0i64;
  v11 = &v5->mGrapplePartner;
  v45 = (hkpListShape *)v11;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v5->mGrapplePartner.m_pPointer = 0i64;
  v5->mParam.mMass = 75.0;
  v5->mParam.mMaxClimableSlope = 50.0;
  v5->mParam.mMaxForce = 1000.0;
  v12 = 0i64;
  do
  {
    v5->mParam.mCollisionHeight[v12] = 1.3;
    v5->mParam.mCollisionRadius[v12++] = 0.30000001;
  }
  while ( v12 < 14 );
  v13 = UFG::qVector3::msZero.y;
  v14 = UFG::qVector3::msZero.z;
  v5->mGroundProperties.groundPosition.x = UFG::qVector3::msZero.x;
  v5->mGroundProperties.groundPosition.y = v13;
  v5->mGroundProperties.groundPosition.z = v14;
  *(_QWORD *)&v5->mGroundProperties.groundNormal.x = 0i64;
  *(_QWORD *)&v5->mGroundProperties.groundNormal.z = 0x3F800000i64;
  *(_QWORD *)&v5->mGroundProperties.maxOffGroundElevation = 0i64;
  *(_QWORD *)&v5->mGroundProperties.latchedFallDistance = 0i64;
  v5->mGroundProperties.groundObjectHandleUid = 0i64;
  v5->mGroundProperties.groundSurfaceHandleUid = 0i64;
  v5->mGroundProperties.support = 2;
  *((_DWORD *)&v5->mGroundProperties + 17) = *((_DWORD *)&v5->mGroundProperties + 17) & 0xFFFFFFF7 | 7;
  v15 = UFG::qVector3::msZero.y;
  v16 = UFG::qVector3::msZero.z;
  v5->mAdditiveVelocity.x = UFG::qVector3::msZero.x;
  v5->mAdditiveVelocity.y = v15;
  v5->mAdditiveVelocity.z = v16;
  v5->mCharacterListener = 0i64;
  v5->mCollisionModelType = 0;
  v5->mDesiredCollisionModelType = 1;
  v5->mSpeedZ = 0.0;
  v5->mGravity = -9.8100004;
  *(_QWORD *)&v5->mHeightFixup = 0i64;
  v5->mAsyncRaycastBucket = -1;
  v5->mGrappleState = 0;
  *((_DWORD *)v5 + 0x97) = *((_DWORD *)v5 + 151) & 0xFFFFFE00 | ((v46 & 1) << 7);
  v17 = UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mPrev;
  UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mPrev->mNext = v9;
  v9->mPrev = v17;
  v5->mNext = (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList;
  UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mPrev = (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::CharacterPhysicsComponent::_CharacterPhysicsComponentTypeUID,
    "CharacterPhysicsComponent");
  if ( v4 )
    UFG::CharacterPhysicsComponent::PropertiesLoad(v5, v4);
  v5->mCollisionSystem = UFG::CustomCollisionFilter::GetUnusedSystemId(UFG::BasePhysicsSystem::mInstance->mCollisionFilter);
  v18 = UFG::CharacterPhysicsComponentManager::mInstance;
  v19 = 1;
  v20 = &v5->mCollisionShapes[1];
  v21 = &v5->mParam.mCollisionHeight[1];
  v22 = &v5->mParam.mCollisionHeight[1];
  do
  {
    if ( v19 == 8 )
    {
      *(_QWORD *)&info.m_maxLinearVelocity = UFG::CharacterPhysicsComponentManager::GetShape(
                                               v18,
                                               CP_WALK,
                                               *v21,
                                               v5->mParam.mCollisionRadius[1]);
      info.m_up.m_quad.m128_u64[0] = (unsigned __int64)UFG::CharacterPhysicsComponentManager::GetShape(
                                                         v18,
                                                         CP_COMBAT,
                                                         v5->mParam.mCollisionHeight[8],
                                                         v5->mParam.mCollisionRadius[8]);
      v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v24 = (hkpListShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v23[11] + 8i64))(v23[11], 144i64);
      v45 = v24;
      if ( v24 )
      {
        hkpListShape::hkpListShape(v24, (hkpShape *const *)&info.m_maxLinearVelocity, 2, REFERENCE_POLICY_INCREMENT);
        v26 = v25;
      }
      else
      {
        v26 = 0i64;
      }
      hkpListShape::setCollisionFilterInfo(v26, 0, 2u);
      hkpListShape::setCollisionFilterInfo(v26, 1u, 3u);
      *v20 = (hkpShape *)&v26->vfptr;
      v21 = &v5->mParam.mCollisionHeight[1];
    }
    else
    {
      *((_BYTE *)v5 + 604);
      *v20 = UFG::CharacterPhysicsComponentManager::GetShape(v18, v19, *v22, v22[14]);
    }
    ++v19;
    ++v22;
    ++v20;
  }
  while ( (signed int)v19 < 14 );
  info.vfptr = (hkBaseObjectVtbl *)&hkpCharacterRigidBodyCinfo::`vftable;
  *(float *)&info.m_memSizeAndFlags = FLOAT_100_0;
  *(_DWORD *)(&info.m_referenceCount + 1) = 0;
  *(&info.m_collisionFilterInfo + 1) = 0xBDCCCCCD;
  info.m_collisionFilterInfo = 0;
  info.m_position = 0i64;
  info.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  info.m_rotation.m_vec.m_quad.m128_u64[1] = LODWORD(FLOAT_0_1);
  info.m_mass = -4.319868e-19;
  info.m_shape = 0i64;
  *(float *)&info.m_memSizeAndFlags = v5->mParam.mMass;
  *(_DWORD *)(&info.m_referenceCount + 1) = 0;
  info.m_shape = v5->mCollisionShapes[1];
  *(float *)&info.m_collisionFilterInfo = FLOAT_50_0;
  *(&info.m_collisionFilterInfo + 1) = 0xBDCCCCCD;
  *(unsigned __int64 *)((char *)info.m_rotation.m_vec.m_quad.m128_u64 + 4) = __PAIR__(
                                                                               LODWORD(FLOAT_0_050000001),
                                                                               (unsigned int)FLOAT_1_0);
  info.m_position.m_quad.m128_i32[3] = LODWORD(v5->mParam.mMaxForce);
  *(__m128 *)&info.m_shape = _xmm;
  info.m_position.m_quad = _mm_unpacklo_ps(
                             _mm_unpacklo_ps((__m128)*v44, (__m128)v44[2]),
                             _mm_unpacklo_ps((__m128)v44[1], (__m128)v44[3]));
  info.m_position.m_quad.m128_i32[2] = LODWORD(v5->mParam.mMaxClimableSlope);
  info.m_collisionFilterInfo = 1;
  v27 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v28 = (CharacterRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v27[11] + 8i64))(v27[11], 192i64);
  v44 = (unsigned int *)v28;
  if ( v28 )
    CharacterRigidBody::CharacterRigidBody(v28, &info);
  else
    v29 = 0i64;
  v5->mHavokCharacter = v29;
  hkStringPtr::operator=(&v29->m_character->m_name, "CharacterCapsule");
  v5->mHavokCharacter->mBottomVertex = (hkVector4f)_xmm;
  v30 = (__m128)*(unsigned int *)v21;
  v30.m128_f32[0] = v30.m128_f32[0] - 0.050000001;
  v5->mHavokCharacter->mTopVertex.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v30), _xmm);
  v5->mHavokCharacter->m_isPlayer = (*((_DWORD *)v5 + 151) >> 7) & 1;
  if ( !(_S13_3 & 1) )
  {
    _S13_3 |= 1u;
    propertyUID = UFG::qStringHashUpper32("CharacterCapsule", 0xFFFFFFFF);
  }
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&info.m_up.m_quad.m128_u16[4]);
  v32 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v31);
  *(_QWORD *)&info.m_unweldingHeightOffsetFactor = UFG::qStringHash64(v32, 0xFFFFFFFFFFFFFFFFui64);
  UFG::PhysicsPropertyManager::GetObjectProperties(
    (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&info.m_up.m_quad.m128_u16[4],
    propertyUID,
    0);
  UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
    *(_QWORD *)(*(_QWORD *)&info.m_vdbColor + 8i64),
    (hkpWorldObject *)&v5->mHavokCharacter->m_character->vfptr);
  if ( *((_BYTE *)v5 + 604) < 0 )
  {
    v33 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
    v44 = (unsigned int *)v33;
    if ( v33 )
    {
      UFG::CharacterCollisionListener::CharacterCollisionListener((UFG::CharacterCollisionListener *)v33, v5);
      v35 = v34;
    }
    else
    {
      v35 = 0i64;
    }
    v5->mCharacterListener = (UFG::CharacterCollisionListener *)v35;
    hkpEntity::addContactListener((hkpEntity *)&v5->mHavokCharacter->m_character->vfptr, v35);
    v5->mHavokCharacter->m_character->m_contactPointCallbackDelay = 0;
  }
  v36 = v5->m_Flags;
  if ( ((unsigned __int8)v36 >> 1) & 1 )
  {
    v5->m_Flags = v36 & 0xFFFD;
    v37 = 0x7FFFFFFF;
    v38 = 0;
    v39 = UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts;
    do
    {
      if ( *v39 <= v37 )
      {
        v37 = *v39;
        v8 = v38;
      }
      ++v38;
      ++v39;
    }
    while ( v38 < 12 );
    ++UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts[v8];
    v5->mAsyncRaycastBucket = v8;
  }
  v40 = v5->mWaterTracker.m_pPointer;
  if ( v40 )
    ((void (__cdecl *)(UFG::SimComponent *))v40->vfptr[9].__vecDelDtor)(v40);
  v5->mHavokCharacter->mSupportRadius = 0.050000001;
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&info.m_up.m_quad.m128_u16[4]);
}m_pPointer;
  if ( v40 )
    ((void (__cdecl *)(UFG::SimComponent *))v40->vfptr[9].__vecDelDtor)(v40);
  v5->mHavokCharacter->mSupportRadius = 0.050000001;
  U

// File Line: 341
// RVA: 0x44F9B0
void __fastcall UFG::CharacterPhysicsComponent::~CharacterPhysicsComponent(UFG::CharacterPhysicsComponent *this)
{
  UFG::CharacterPhysicsComponent *v1; // rbx
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v2; // rdi
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v3; // rcx
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v4; // rax
  UFG::SimComponent *v5; // rax
  hkpRigidBody *v6; // rsi
  hkpContactListener *v7; // rdx
  UFG::CharacterCollisionListener *v8; // rcx
  UFG::BasePhysicsSystem *v9; // rbp
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::WaterFloatingTrackerComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v20; // rdx
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v21; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterPhysicsComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::CharacterPhysicsComponent::`vftable{for `UFG::BasePhysicsObject};
  if ( this == UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentpCurrentIterator )
    UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentpCurrentIterator = (UFG::CharacterPhysicsComponent *)&this->mPrev[-7].mNext;
  v2 = (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mWaterTracker.m_pPointer;
  if ( v5 && SLODWORD(v5[1].m_BoundComponentHandles.mNode.mNext) > 0 )
    UFG::GameStatAction::Character::ExitWater(v1->m_pSimObject);
  v6 = v1->mHavokCharacter->m_character;
  v6->m_userData = 0i64;
  v7 = (hkpContactListener *)&v1->mCharacterListener->vfptr;
  if ( v7 )
  {
    hkpEntity::removeContactListener((hkpEntity *)&v6->vfptr, v7);
    v8 = v1->mCharacterListener;
    if ( v8 )
      ((void (__fastcall *)(UFG::CharacterCollisionListener *, signed __int64))v8->vfptr->~hkpContactListener)(v8, 1i64);
  }
  v9 = UFG::BasePhysicsSystem::mInstance;
  UFG::CustomCollisionFilter::ReenableCollisions(
    UFG::BasePhysicsSystem::mInstance->mCollisionFilter,
    (hkpEntity *)&v6->vfptr);
  if ( v6->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(v9, v6, 1);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mHavokCharacter->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mCollisionShapes[8]->vfptr);
  if ( v1->mAsyncRaycastBucket != -1 )
    --UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts[v1->mAsyncRaycastBucket];
  UFG::CustomCollisionFilter::ReleaseSystemId(v9->mCollisionFilter, v1->mCollisionSystem);
  v10 = &v1->mGrapplePartner;
  if ( v1->mGrapplePartner.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->mGrapplePartner.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->mGrapplePartner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mGrapplePartner.mPrev;
  }
  v1->mGrapplePartner.m_pPointer = 0i64;
  v13 = v10->mPrev;
  v14 = v1->mGrapplePartner.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->mGrapplePartner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mGrapplePartner.mPrev;
  v15 = &v1->mWaterTracker;
  if ( v1->mWaterTracker.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v1->mWaterTracker.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v1->mWaterTracker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mWaterTracker.mPrev;
  }
  v1->mWaterTracker.m_pPointer = 0i64;
  v18 = v15->mPrev;
  v19 = v1->mWaterTracker.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v1->mWaterTracker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mWaterTracker.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mRagdollComponent);
  v20 = v2->mPrev;
  v21 = v2->mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BasePhysicsObject::~BasePhysicsObject((UFG::BasePhysicsObject *)&v1->vfptr);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 392
// RVA: 0x470990
void __fastcall UFG::CharacterPhysicsComponent::PropertiesLoad(UFG::CharacterPhysicsComponent *this, component_CharacterPhysics *data)
{
  this->mParam.mMass = data->Mass;
  this->mParam.mMaxClimableSlope = data->MaxClimableSlope * 0.017453292;
  this->mParam.mMaxForce = data->MaxForce;
  this->mParam.mCollisionHeight[1] = data->WalkCollisionHeight;
  this->mParam.mCollisionHeight[5] = data->WalkCollisionHeight;
  this->mParam.mCollisionHeight[2] = data->CrouchCollisionHeight;
  this->mParam.mCollisionHeight[4] = data->DrivingCollisionHeight;
  this->mParam.mCollisionHeight[3] = data->CrawlCollisionHeight;
  this->mParam.mCollisionHeight[6] = data->CrawlCollisionHeight;
  this->mParam.mCollisionHeight[7] = data->SittingCollisionHeight;
  this->mParam.mCollisionHeight[8] = data->CombatCollisionHeight;
  this->mParam.mCollisionHeight[9] = data->CrawlCollisionHeight;
  this->mParam.mCollisionHeight[10] = data->WalkCollisionHeight;
  this->mParam.mCollisionHeight[11] = data->WalkCollisionHeight;
  this->mParam.mCollisionHeight[12] = data->CoverCollisionHeight;
  this->mParam.mCollisionHeight[13] = data->FreerunCollisionHeight;
  this->mParam.mCollisionRadius[1] = data->WalkCollisionRadius;
  this->mParam.mCollisionRadius[5] = data->WalkCollisionRadius;
  this->mParam.mCollisionRadius[2] = data->CrouchCollisionRadius;
  this->mParam.mCollisionRadius[4] = data->DrivingCollisionRadius;
  this->mParam.mCollisionRadius[3] = data->CrawlCollisionRadius;
  this->mParam.mCollisionRadius[6] = data->CrawlCollisionRadius;
  this->mParam.mCollisionRadius[7] = data->SittingCollisionRadius;
  this->mParam.mCollisionRadius[8] = data->CombatCollisionRadius;
  this->mParam.mCollisionRadius[9] = data->CrawlCollisionRadius;
  this->mParam.mCollisionRadius[10] = data->WalkCollisionRadius;
  this->mParam.mCollisionRadius[11] = data->WalkCollisionRadius;
  this->mParam.mCollisionRadius[12] = data->CoverCollisionRadius;
  this->mParam.mCollisionRadius[13] = data->FreerunCollisionRadius;
  *((_DWORD *)this + 151) ^= (*((_DWORD *)this + 151) ^ 2 * data->DetailedOnGroundCheck) & 2;
}

// File Line: 434
// RVA: 0x45A580
void __fastcall UFG::CharacterPhysicsComponent_OnEnterWater(void *cxt)
{
  UFG::CharacterPhysicsComponent::OnEnterWater((UFG::CharacterPhysicsComponent *)cxt);
}

// File Line: 442
// RVA: 0x45A590
void __fastcall UFG::CharacterPhysicsComponent_OnExitWater(void *cxt)
{
  UFG::GameStatAction::Character::ExitWater(*((UFG::SimObject **)cxt + 5));
}

// File Line: 449
// RVA: 0x470CD0
UFG::CharacterPhysicsComponent *__fastcall UFG::CharacterPhysicsComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // bl
  UFG::SceneObjectProperties *v3; // rbp
  __int64 v4; // rdi
  UFG::qPropertySet *v5; // rcx
  UFG::qPropertySet *v6; // rax
  char *v7; // r14
  UFG::SimObject *v9; // rsi
  UFG::TransformNodeComponent *v10; // rbx
  float v11; // xmm1_4
  float v12; // xmm2_4
  char *v13; // rbx
  unsigned int v14; // eax
  __int64 v15; // rax
  unsigned int v16; // ebx
  UFG::SimComponent *v17; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  _QWORD *v22; // rax
  __int64 *v23; // rcx
  __int64 v24; // rax
  UFG::qVector4 pos; // [rsp+40h] [rbp-58h]
  UFG::qSymbol v26; // [rsp+A0h] [rbp+8h]
  UFG::qSymbol result; // [rsp+A8h] [rbp+10h]
  UFG::qSymbol v28; // [rsp+B0h] [rbp+18h]
  UFG::qSymbol v29; // [rsp+B8h] [rbp+20h]

  v2 = required;
  v3 = pSceneObj;
  v4 = 0i64;
  v5 = pSceneObj->mpWritableProperties;
  if ( !v5 )
    v5 = v3->mpConstProperties;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v5,
         (UFG::qSymbol *)&component_CharacterPhysics::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v6 )
    v7 = UFG::qPropertySet::GetMemImagePtr(v6);
  else
    v7 = 0i64;
  if ( !v2 && !v7 )
    return 0i64;
  v9 = v3->m_pSimObject;
  v10 = v9->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v9->m_pTransformNodeComponent);
  v11 = v10->mWorldTransform.v3.y;
  v12 = v10->mWorldTransform.v3.z;
  pos.x = v10->mWorldTransform.v3.x;
  pos.y = v11;
  pos.z = v12;
  LODWORD(pos.w) = (_DWORD)FLOAT_1_0;
  if ( v9->m_Name.mUID != UFG::qSymbol::create_from_string(&result, "PlayerOne_Havok")->mUID
    && v9->m_Name.mUID != UFG::qSymbol::create_from_string(&v26, "PlayerTwo_Havok")->mUID
    && v9->m_Name.mUID != UFG::qSymbol::create_from_string(&v28, "PlayerThree_Havok")->mUID )
  {
    v9->m_Name.mUID;
    UFG::qSymbol::create_from_string(&v29, "PlayerFour_Havok")->mUID;
  }
  v13 = UFG::CharacterPhysicsComponent::mAllocator.mFreeListHead;
  if ( UFG::CharacterPhysicsComponent::mAllocator.mFreeListHead )
  {
    UFG::CharacterPhysicsComponent::mAllocator.mFreeListHead = *(char **)UFG::CharacterPhysicsComponent::mAllocator.mFreeListHead;
    v14 = UFG::CharacterPhysicsComponent::mAllocator.mNumSlotsAllocated + 1;
    UFG::CharacterPhysicsComponent::mAllocator.mNumSlotsAllocated = v14;
    if ( UFG::CharacterPhysicsComponent::mAllocator.mMostSlotsAllocated <= v14 )
      UFG::CharacterPhysicsComponent::mAllocator.mMostSlotsAllocated = v14;
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&UFG::CharacterPhysicsComponent::mAllocator);
  }
  *(_QWORD *)&v26.mUID = v13;
  if ( v13 )
  {
    UFG::CharacterPhysicsComponent::CharacterPhysicsComponent(
      (UFG::CharacterPhysicsComponent *)v13,
      &pos,
      v3->m_NameUID,
      (component_CharacterPhysics *)v7);
    v4 = v15;
  }
  if ( (v9->m_Flags >> 14) & 1 )
    v16 = 27;
  else
    v16 = -1;
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&pos, v9, 1);
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&pos, (UFG::SimComponent *)v4, v16);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&pos);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&pos);
  v17 = UFG::AquireWaterFloatingTrackerComponent(v9, *(hkpRigidBody **)(*(_QWORD *)(v4 + 432) + 32i64));
  if ( UFG::SimComponent::IsType(v17, UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID) )
  {
    v18 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v4 + 168);
    if ( *(_QWORD *)(v4 + 184) )
    {
      v19 = v18->mPrev;
      v20 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v4 + 176);
      v19->mNext = v20;
      v20->mPrev = v19;
      v18->mPrev = v18;
      *(_QWORD *)(v4 + 176) = v4 + 168;
    }
    *(_QWORD *)(v4 + 184) = v17;
    if ( v17 )
    {
      v21 = v17->m_SafePointerList.mNode.mPrev;
      v21->mNext = v18;
      v18->mPrev = v21;
      *(_QWORD *)(v4 + 176) = (char *)v17 + 8;
      v17->m_SafePointerList.mNode.mPrev = v18;
    }
    v22 = *(_QWORD **)(v4 + 184);
    v22[20] = UFG::CharacterPhysicsComponent_OnEnterWater;
    v22[21] = UFG::CharacterPhysicsComponent_OnExitWater;
    v22[22] = v4;
    v23 = *(__int64 **)(v4 + 184);
    v24 = *v23;
    if ( (*(_BYTE *)(v4 + 32) >> 1) & 1 )
      (*(void (__cdecl **)(__int64 *))(v24 + 64))(v23);
    else
      (*(void (__cdecl **)(__int64 *))(v24 + 72))(v23);
  }
  return (UFG::CharacterPhysicsComponent *)v4;
}

// File Line: 513
// RVA: 0x46DE90
void __fastcall UFG::CharacterPhysicsComponent::OnAttach(UFG::CharacterPhysicsComponent *this, UFG::SimObject *object)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v2; // r9
  UFG::SimObjectCharacter *v3; // rsi
  UFG::CharacterPhysicsComponent *v4; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v8; // rcx
  UFG::TransformNodeComponent *v9; // rdi
  CharacterRigidBody *v10; // rcx
  hkVector4f position; // [rsp+20h] [rbp-18h]

  v2 = &this->mUserData.simComponent;
  v3 = (UFG::SimObjectCharacter *)object;
  v4 = this;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    v5 = v2->mPrev;
    v6 = this->mUserData.simComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    this->mUserData.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mUserData.simComponent.mPrev;
  }
  this->mUserData.simComponent.m_pPointer = (UFG::SimComponent *)&this->vfptr;
  if ( this )
  {
    v7 = this->m_SafePointerList.mNode.mPrev;
    v8 = &this->m_SafePointerList;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mPrev = v7;
    v2->mNext = &v8->mNode;
    v8->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v4->mHavokCharacter->m_character->m_userData = (unsigned __int64)&v4->mUserData;
  if ( object )
    v9 = object->m_pTransformNodeComponent;
  else
    v9 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v9);
  v10 = v4->mHavokCharacter;
  position.m_quad = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(
                        (__m128)LODWORD(v9->mWorldTransform.v3.x),
                        (__m128)LODWORD(v9->mWorldTransform.v3.z)),
                      _mm_unpacklo_ps((__m128)LODWORD(v9->mWorldTransform.v3.y), (__m128)(unsigned int)FLOAT_1_0));
  hkpRigidBody::setPosition(v10->m_character, &position);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::Bind<UFG::SimObjectCharacter>(&v4->mRagdollComponent, v3);
}

// File Line: 533
// RVA: 0x46E6D0
void __fastcall UFG::CharacterPhysicsComponent::OnDetach(UFG::CharacterPhysicsComponent *this)
{
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0> *v1; // r8
  UFG::CharacterPhysicsComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::SimComponent *v7; // rax

  v1 = &this->mRagdollComponent;
  v2 = this;
  if ( this->mRagdollComponent.m_pSimComponent )
  {
    v3 = this->mRagdollComponent.mNext;
    v4 = v1->mPrev;
    v4->mNext = v3;
    v3->mPrev = v4;
    this->mRagdollComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->mRagdollComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::RagdollComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::RagdollComponent,0> *)this->mRagdollComponent.mNext != &this->mRagdollComponent) )
  {
    v5 = this->mRagdollComponent.mNext;
    v6 = v1->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    goto LABEL_7;
  }
LABEL_8:
  v1->m_Changed = 1;
  v7 = v2->mWaterTracker.m_pPointer;
  if ( v7 )
  {
    if ( SLODWORD(v7[1].m_BoundComponentHandles.mNode.mNext) > 0 )
      UFG::GameStatAction::Character::ExitWater(v2->m_pSimObject);
  }
}

// File Line: 544
// RVA: 0x476240
void __fastcall UFG::CharacterPhysicsComponent::Suspend(UFG::CharacterPhysicsComponent *this)
{
  UFG::SimObject *v1; // rax
  UFG::CharacterPhysicsComponent *v2; // rdx
  unsigned __int16 v3; // cx
  __int64 v4; // rax
  UFG::SimComponent *v5; // rcx

  v1 = this->m_pSimObject;
  v2 = this;
  if ( !v1 || !((v1->m_Flags >> 11) & 1) )
  {
    v3 = this->m_Flags;
    if ( !(((unsigned __int8)v3 >> 1) & 1) )
    {
      v4 = v2->mAsyncRaycastBucket;
      v2->m_Flags = v3 | 2;
      if ( (_DWORD)v4 != -1 )
        --UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts[v4];
      v2->mAsyncRaycastBucket = -1;
    }
    v5 = v2->mWaterTracker.m_pPointer;
    if ( v5 )
      ((void (*)(void))v5->vfptr[8].__vecDelDtor)();
  }
}

// File Line: 568
// RVA: 0x473DC0
void __fastcall UFG::CharacterPhysicsComponent::Restore(UFG::CharacterPhysicsComponent *this)
{
  UFG::CharacterPhysicsComponent *v1; // r10
  unsigned __int16 v2; // cx
  signed int v3; // er8
  signed int v4; // er9
  signed int v5; // eax
  int *v6; // rcx
  UFG::SimComponent *v7; // rcx

  v1 = this;
  v2 = this->m_Flags;
  if ( ((unsigned __int8)v2 >> 1) & 1 )
  {
    v3 = 0x7FFFFFFF;
    v4 = 0;
    v1->m_Flags = v2 & 0xFFFD;
    v5 = 0;
    v6 = UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts;
    do
    {
      if ( *v6 <= v3 )
      {
        v3 = *v6;
        v4 = v5;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < 12 );
    ++UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts[v4];
    v1->mAsyncRaycastBucket = v4;
  }
  v7 = v1->mWaterTracker.m_pPointer;
  if ( v7 )
    ((void (*)(void))v7->vfptr[9].__vecDelDtor)();
}

// File Line: 588
// RVA: 0x4767E0
void __fastcall UFG::CharacterPhysicsComponent::TeleportEventHandler(UFG::CharacterPhysicsComponent *this, UFG::Event *event)
{
  UFG::CharacterPhysicsComponent *v2; // rdi
  CharacterRigidBody *v3; // rcx
  float v4; // xmm6_4
  UFG::Event *v5; // rbx
  __m128 v6; // xmm7
  float v7; // xmm0_4
  CharacterRigidBody *v8; // rbx
  UFG::SimObject *v9; // rax
  __m128 *v10; // rax
  hkpEntity *v11; // rbx
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::SimObject *v14; // rax
  CharacterRigidBody *v15; // rax
  hkpRigidBody *v16; // rbx
  UFG::SimComponent *v17; // rax
  hkVector4f position; // [rsp+20h] [rbp-58h]
  hkQuaternionf rotation; // [rsp+30h] [rbp-48h]
  __int128 v20; // [rsp+40h] [rbp-38h]

  v2 = this;
  v3 = this->mHavokCharacter;
  v4 = 0.0;
  v5 = event;
  v6 = (__m128)event[2].m_EventUID;
  position.m_quad = _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)LODWORD(event[2].mNext), v6),
                      _mm_unpacklo_ps((__m128)HIDWORD(event[2].mNext), (__m128)0i64));
  hkpRigidBody::setPosition(v3->m_character, &position);
  v7 = atan2f(*((float *)&v5[1].m_EventUID + 1), *(float *)&v5[1].m_EventUID);
  v8 = v2->mHavokCharacter;
  v2->mFacing = v7;
  hkQuaternionf::setAxisAngle(&rotation, &v8->m_up, v7);
  hkpRigidBody::setRotation(v8->m_character, &rotation);
  v9 = v2->m_pSimObject;
  if ( !v9 || !((v9->m_Flags >> 11) & 1) )
  {
    v10 = (__m128 *)v2->mHavokCharacter;
    rotation.m_vec.m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)LODWORD(UFG::qVector3::msZero.x),
                                (__m128)LODWORD(UFG::qVector3::msZero.z)),
                              _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.y), (__m128)0i64));
    v11 = (hkpEntity *)v10[2].m128_u64[0];
    v10[10] = _mm_mul_ps(_mm_sub_ps(rotation.m_vec.m_quad, v11->m_motion.m_linearVelocity.m_quad), (__m128)_xmm);
    hkpEntity::activate(v11);
    v11->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v11->m_motion.vfptr, (unsigned int)&rotation);
  }
  v12 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  v2->mAdditiveVelocity.x = UFG::qVector3::msZero.x;
  v2->mAdditiveVelocity.y = v12;
  v2->mAdditiveVelocity.z = v13;
  v14 = v2->m_pSimObject;
  if ( !v14 || !((v14->m_Flags >> 11) & 1) )
    v4 = FLOAT_N9_8100004;
  v15 = v2->mHavokCharacter;
  v2->mGravity = v4;
  v2->mSpeedZ = 0.0;
  v20 = 0i64;
  v16 = v15->m_character;
  hkpEntity::activate((hkpEntity *)&v15->m_character->vfptr);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))v16->m_motion.vfptr[9].__first_virtual_table_function__)(
    &v16->m_motion,
    &v20);
  v17 = v2->mWaterTracker.m_pPointer;
  if ( v17 && SLODWORD(v17[1].m_BoundComponentHandles.mNode.mNext) > 0 )
    UFG::GameStatAction::Character::ExitWater(v2->m_pSimObject);
  *((_DWORD *)&v2->mGroundProperties + 17) &= 0xFFFFFFFE;
  LODWORD(v2->mGroundProperties.maxOffGroundElevation) = v6.m128_i32[0];
  *(_QWORD *)&v2->mGroundProperties.latchedFallDistance = 0i64;
  v2->mGroundProperties.timeOffGround = 0.0;
  v2->mGroundProperties.heightAboveGround = 0.0;
}

// File Line: 624
// RVA: 0x46F8A0
void __fastcall UFG::CharacterPhysicsComponent::PlaceOnGroundAfterNIS(UFG::CharacterPhysicsComponent *this)
{
  UFG::SimObject *v1; // rdi
  UFG::CharacterPhysicsComponent *v2; // rsi
  float v3; // xmm1_4
  float v4; // xmm2_4
  CharacterRigidBody *v5; // rcx
  float v6; // xmm6_4
  float v7; // xmm1_4
  int v8; // xmm0_4
  int v9; // xmm1_4
  int v10; // xmm0_4
  int v11; // xmm1_4
  int v12; // xmm0_4
  int v13; // xmm1_4
  int v14; // xmm0_4
  int v15; // xmm1_4
  int v16; // xmm1_4
  float v17; // xmm0_4
  CharacterRigidBody *v18; // rbx
  UFG::SimObject *v19; // rax
  CharacterRigidBody *v20; // rax
  hkpRigidBody *v21; // rbx
  UFG::qVector3 out; // [rsp+20h] [rbp-39h]
  hkVector4f position; // [rsp+30h] [rbp-29h]
  hkQuaternionf rotation; // [rsp+40h] [rbp-19h]
  __int128 v25; // [rsp+50h] [rbp-9h]
  float fx; // [rsp+60h] [rbp+7h]
  float fy; // [rsp+64h] [rbp+Bh]
  int v28; // [rsp+68h] [rbp+Fh]
  int v29; // [rsp+6Ch] [rbp+13h]
  int v30; // [rsp+70h] [rbp+17h]
  int v31; // [rsp+74h] [rbp+1Bh]
  int v32; // [rsp+78h] [rbp+1Fh]
  int v33; // [rsp+7Ch] [rbp+23h]
  int v34; // [rsp+80h] [rbp+27h]
  int v35; // [rsp+84h] [rbp+2Bh]
  int v36; // [rsp+88h] [rbp+2Fh]
  int v37; // [rsp+8Ch] [rbp+33h]
  UFG::qVector3 v38; // [rsp+90h] [rbp+37h]
  int v39; // [rsp+9Ch] [rbp+43h]

  v1 = this->m_pSimObject;
  v2 = this;
  if ( v1 )
    v1 = (UFG::SimObject *)v1->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1);
  v3 = *((float *)v1[1].mNode.mChild + 1);
  v4 = *(float *)&v1[1].mNode.mChild[1];
  out.x = *(float *)v1[1].mNode.mChild;
  out.y = v3;
  out.z = v4;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1);
  if ( UFG::SimObjectUtility::PlaceOnGround(&out, (UFG::qVector3 *)v1[1].mNode.mChild, 0.1, 3.0) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1);
    v5 = v2->mHavokCharacter;
    v6 = 0.0;
    v7 = *((float *)&v1[1].vfptr + 1);
    fx = *(float *)&v1[1].vfptr;
    v8 = (int)v1[1].m_SafePointerList.mNode.mPrev;
    fy = v7;
    v9 = HIDWORD(v1[1].m_SafePointerList.mNode.mPrev);
    v28 = v8;
    v10 = (int)v1[1].m_SafePointerList.mNode.mNext;
    v29 = v9;
    v11 = HIDWORD(v1[1].m_SafePointerList.mNode.mNext);
    v30 = v10;
    v32 = (int)v1[1].m_SafePointerWithCallbackList.mNode.mPrev;
    v12 = (int)v1[1].m_SafePointerWithCallbackList.mNode.mNext;
    v31 = v11;
    v13 = HIDWORD(v1[1].m_SafePointerWithCallbackList.mNode.mPrev);
    v34 = v12;
    v14 = (int)v1[1].mNode.mParent;
    v33 = v13;
    v15 = HIDWORD(v1[1].m_SafePointerWithCallbackList.mNode.mNext);
    v36 = v14;
    v35 = v15;
    v16 = HIDWORD(v1[1].mNode.mParent);
    v39 = (signed int)FLOAT_1_0;
    v37 = v16;
    v38 = out;
    position.m_quad = _mm_unpacklo_ps(
                        _mm_unpacklo_ps((__m128)LODWORD(out.x), (__m128)LODWORD(out.z)),
                        _mm_unpacklo_ps((__m128)LODWORD(out.y), (__m128)0i64));
    hkpRigidBody::setPosition(v5->m_character, &position);
    v17 = atan2f(fy, fx);
    v18 = v2->mHavokCharacter;
    v2->mFacing = v17;
    hkQuaternionf::setAxisAngle(&rotation, &v18->m_up, v17);
    hkpRigidBody::setRotation(v18->m_character, &rotation);
    v19 = v2->m_pSimObject;
    if ( !v19 || !((v19->m_Flags >> 11) & 1) )
      v6 = FLOAT_N9_8100004;
    v20 = v2->mHavokCharacter;
    v2->mGravity = v6;
    v25 = 0i64;
    v21 = v20->m_character;
    hkpEntity::activate((hkpEntity *)&v20->m_character->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))v21->m_motion.vfptr[9].__first_virtual_table_function__)(
      &v21->m_motion,
      &v25);
    UFG::TransformNodeComponent::SetWorldTransform((UFG::TransformNodeComponent *)v1, (UFG::qMatrix44 *)&fx);
  }
}

// File Line: 663
// RVA: 0x4755C0
void __fastcall UFG::CharacterPhysicsComponent::SetSuperMassive(UFG::CharacterPhysicsComponent *this)
{
  this->mHavokCharacter->m_superMassive = 1;
}

// File Line: 670
// RVA: 0x45A700
void __fastcall UFG::CharacterPhysicsComponent::ClearSuperMassive(UFG::CharacterPhysicsComponent *this)
{
  this->mHavokCharacter->m_superMassive = 0;
}

// File Line: 680
// RVA: 0x476DC0
void __fastcall UFG::CharacterPhysicsComponent::Update(UFG::CharacterPhysicsComponent *this, float deltaT)
{
  UFG::PhysicsSystem *v2; // r13
  char v3; // r12
  UFG::CharacterPhysicsComponent *v4; // rsi
  int v5; // ebx
  float v6; // xmm15_4
  UFG::SimComponent *v7; // rdx
  CharacterRigidBody *v8; // rdi
  unsigned int v9; // er15
  UFG::CharacterCollisionMode v10; // eax
  hkpEntity *v11; // rdi
  hkpWorld *v12; // r14
  __m128 v13; // xmm0
  signed int v14; // eax
  hkpEntity *v15; // rdx
  hkpWorld *v16; // rcx
  UFG::SimObject *v17; // rdi
  float v18; // xmm10_4
  UFG::TransformNodeComponent *v19; // rdi
  float v20; // xmm4_4
  __m128 v21; // xmm5
  float v22; // xmm2_4
  float v23; // xmm3_4
  UFG::SimObject *v24; // rbx
  UFG::TransformNodeComponent *v25; // rbx
  float v26; // xmm6_4
  float v27; // xmm7_4
  float v28; // xmm8_4
  __m128 v29; // xmm1
  float v30; // xmm2_4
  float v31; // xmm0_4
  UFG::SimObject *v32; // rax
  CharacterRigidBody *v33; // rbx
  float v34; // xmm1_4
  unsigned __int16 v35; // cx
  CharacterRigidBody *v36; // rax
  __m128 v37; // xmm0
  hkpRigidBody *v38; // rbx
  hkQuaternionf *v39; // rdx
  CharacterRigidBody *v40; // rax
  UFG::SimComponent *v41; // rax
  char v42; // r14
  CharacterRigidBody *v43; // rax
  __m128 v44; // xmm6
  UFG::SimObjectCVBase *v45; // rcx
  UFG::CharacterAnimationComponent *v46; // rax
  unsigned __int16 v47; // dx
  Creature *v48; // rcx
  hkQsTransformf *v49; // rax
  bool v50; // zf
  __m128 v51; // xmm0
  __m128 v52; // xmm0
  __m128 v53; // xmm2
  float v54; // xmm2_4
  float v55; // xmm3_4
  float v56; // xmm1_4
  __m128 v57; // xmm1
  unsigned int v58; // xmm3_4
  CharacterRigidBody *v59; // rcx
  unsigned int v60; // xmm1_4
  hkpRigidBody *v61; // rcx
  float v62; // xmm1_4
  __m128 v63; // xmm6
  hkpRigidBody *v64; // rbx
  UFG::SimComponent *v65; // rax
  float v66; // xmm7_4
  float v67; // xmm1_4
  float v68; // xmm0_4
  __m128 v69; // xmm6
  UFG::GameStatTracker *v70; // rbx
  hkpEntity *v71; // rdi
  __int64 v72; // rdx
  UFG::SimObjectGame *v73; // rcx
  unsigned __int16 v74; // dx
  UFG::SimComponent *v75; // rcx
  UFG::SimComponent *v76; // rax
  hkpEntity *v77; // rdi
  __m128 *v78; // rcx
  __int64 v79; // rdx
  int v80; // eax
  float *v81; // rcx
  int v82; // eax
  float v83; // xmm4_4
  int v84; // eax
  UFG::SimComponent *v85; // rax
  int v86; // ecx
  UFG::SimObjectCVBase *v87; // rcx
  unsigned __int16 v88; // dx
  UFG::CharacterAnimationComponent *v89; // rax
  float v90; // xmm6_4
  __m128 v91; // xmm3
  __m128 v92; // xmm4
  __m128 v93; // xmm5
  float v94; // xmm2_4
  float v95; // xmm2_4
  __m128 v96; // xmm7
  __m128 v97; // xmm5
  __m128 v98; // xmm4
  float v99; // xmm3_4
  float v100; // xmm2_4
  float v101; // xmm2_4
  float v102; // xmm1_4
  float v103; // xmm12_4
  float v104; // xmm0_4
  float v105; // xmm6_4
  __m128 v106; // xmm4
  float v107; // xmm1_4
  __m128 v108; // xmm3
  __m128 v109; // xmm2
  UFG::SimObject *v110; // rax
  __m128 *v111; // rax
  hkpEntity *v112; // rbx
  UFG::qVector3 dir; // [rsp+30h] [rbp-A8h]
  float number[4]; // [rsp+40h] [rbp-98h]
  __m128 v115; // [rsp+50h] [rbp-88h]
  hkQuaternionf rotation; // [rsp+60h] [rbp-78h]
  hkQsTransformf v117; // [rsp+70h] [rbp-68h]
  hkBool result[4]; // [rsp+128h] [rbp+50h]

  v2 = (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance;
  *((_DWORD *)this + 151) &= 0xFFFFFFFB;
  v3 = 0;
  v4 = this;
  v5 = 6;
  v6 = deltaT;
  *((_DWORD *)&this->mGroundProperties + 17) ^= ((unsigned __int8)*((_DWORD *)&this->mGroundProperties + 17) ^ (unsigned __int8)(4 * *((unsigned int *)&this->mGroundProperties + 17))) & 4;
  v7 = this->mRagdollComponent.m_pSimComponent;
  if ( v7 && LODWORD(v7[2].m_SafePointerList.mNode.mPrev) == 1 && HIDWORD(v7[2].m_SafePointerList.mNode.mPrev) == 1 )
  {
    if ( *(float *)&v7[2].vfptr >= 1.0 )
    {
      this->mDesiredCollisionModelType = 6;
      v3 = 1;
    }
    else
    {
      this->mDesiredCollisionModelType = 3;
    }
  }
  v8 = this->mHavokCharacter;
  v9 = v8->m_character->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
  v10 = this->mDesiredCollisionModelType;
  if ( this->mCollisionModelType != v10 )
  {
    this->mCollisionModelType = v10;
    v11 = (hkpEntity *)&v8->m_character->vfptr;
    v12 = v11->m_world;
    if ( v12 )
      hkpWorld::removeEntity(v11->m_world, result, v11);
    ((void (__fastcall *)(hkpEntity *, hkpShape *))v11->vfptr[1].__first_virtual_table_function__)(
      v11,
      v4->mCollisionShapes[v4->mCollisionModelType]);
    v13 = (__m128)LODWORD(v4->mParam.mCollisionHeight[v4->mDesiredCollisionModelType]);
    v13.m128_f32[0] = v13.m128_f32[0] - 0.050000001;
    v4->mHavokCharacter->mTopVertex.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v13), _xmm);
    if ( v12 )
      hkpWorld::addEntity(v12, v11, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  }
  switch ( v4->mCollisionModelType )
  {
    case 4:
      v14 = 27;
      if ( v4->mRagdollComponent.m_pSimComponent )
        v14 = 21;
      v5 = v14;
      break;
    case 5:
      v5 = 5;
      break;
    case 6:
      v5 = 21;
      break;
    default:
      if ( v4->mCollisionModelType != 7 )
      {
        if ( v4->mCollisionModelType == 9 )
          v5 = 4;
        else
          v5 = (v4->mRagdollComponent.m_pSimComponent != 0i64) + 1;
      }
      break;
  }
  if ( v4->mCollisionModelType != 8 && v5 != v9 )
  {
    v15 = (hkpEntity *)&v4->mHavokCharacter->m_character->vfptr;
    v16 = v15->m_world;
    v15->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v5;
    if ( v16 )
      hkpWorld::updateCollisionFilterOnEntity(v16, v15, 0, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  }
  v17 = v4->m_pSimObject;
  v18 = v4->mFacing;
  if ( v17 )
    v19 = v17->m_pTransformNodeComponent;
  else
    v19 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v19);
  v20 = v19->mWorldTransform.v0.x;
  v21 = (__m128)LODWORD(v19->mWorldTransform.v0.y);
  v22 = v19->mWorldTransform.v0.z;
  v23 = v19->mWorldTransform.v0.w;
  if ( v4->mGrappleState == 1 )
  {
    v24 = v4->mGrapplePartner.m_pPointer;
    if ( v24 )
    {
      v25 = v24->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v19);
      v26 = v19->mWorldTransform.v3.x;
      v27 = v19->mWorldTransform.v3.y;
      v28 = v19->mWorldTransform.v3.z;
      UFG::TransformNodeComponent::UpdateWorldTransform(v25);
      v23 = 0.0;
      v21 = (__m128)LODWORD(v25->mWorldTransform.v3.y);
      v20 = v25->mWorldTransform.v3.x - v26;
      v21.m128_f32[0] = v21.m128_f32[0] - v27;
      v22 = v25->mWorldTransform.v3.z - v28;
    }
  }
  v29 = v21;
  v29.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20)) + (float)(v22 * v22))
                  + (float)(v23 * v23);
  if ( v29.m128_f32[0] == 0.0 )
    v30 = 0.0;
  else
    v30 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29));
  v31 = atan2f(v30 * v21.m128_f32[0], v30 * v20);
  v32 = v4->m_pSimObject;
  v4->mFacing = v31;
  if ( !v32 || !((v32->m_Flags >> 11) & 1) )
  {
    if ( v4->mGrappleState == 1 )
    {
      v33 = v4->mHavokCharacter;
      hkQuaternionf::setAxisAngle(&rotation, &v33->m_up, v31);
      hkpRigidBody::setRotation(v33->m_character, &rotation);
      v34 = *(float *)&FLOAT_1_0;
      v35 = (signed int)(float)((float)(v4->mFacing * 32768.0) * 0.31830987)
          - (signed int)(float)((float)(v18 * 32768.0) * 0.31830987);
      if ( (v35 & 0x8000u) != 0 )
      {
        v34 = FLOAT_N1_0;
        v35 = (signed int)(float)((float)(v18 * 32768.0) * 0.31830987)
            - (signed int)(float)((float)(v4->mFacing * 32768.0) * 0.31830987);
      }
      v36 = v4->mHavokCharacter;
      v37 = (__m128)COERCE_UNSIGNED_INT((float)v35);
      v37.m128_f32[0] = (float)((float)((float)(v37.m128_f32[0] * 3.1415927) * 0.000030517578) / v6) * v34;
      *(__m128 *)number = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v37), (__m128)0i64);
      v38 = v36->m_character;
      hkpEntity::activate((hkpEntity *)&v36->m_character->vfptr);
      v39 = (hkQuaternionf *)number;
    }
    else
    {
      v40 = v4->mHavokCharacter;
      rotation.m_vec.m_quad = 0i64;
      v38 = v40->m_character;
      hkpEntity::activate((hkpEntity *)&v40->m_character->vfptr);
      v39 = &rotation;
    }
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkQuaternionf *))v38->m_motion.vfptr[9].__first_virtual_table_function__)(
      &v38->m_motion,
      v39);
  }
  v41 = v4->mWaterTracker.m_pPointer;
  if ( v41 && SLODWORD(v41[1].m_BoundComponentHandles.mNode.mNext) > 0 )
  {
    v42 = 1;
    v4->mHavokCharacter->m_isInWater = 1;
    v4->mHeightFixup = 0.0;
  }
  else
  {
    v42 = 0;
    v4->mHavokCharacter->m_isInWater = 0;
    if ( *((_BYTE *)&v4->mGroundProperties + 68) & 1 )
      v4->mHeightFixup = v4->mGroundProperties.heightAboveGround;
  }
  v43 = v4->mHavokCharacter;
  v44 = v43->m_character->m_motion.m_motionState.m_transform.m_translation.m_quad;
  v45 = (UFG::SimObjectCVBase *)v4->m_pSimObject;
  rotation.m_vec.m_quad = (__m128)v43->m_character->m_motion.m_motionState.m_transform.m_translation;
  if ( v45 )
  {
    v47 = v45->m_Flags;
    if ( (v47 >> 14) & 1 )
    {
      v46 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v45);
    }
    else if ( (v47 & 0x8000u) == 0 )
    {
      if ( (v47 >> 13) & 1 )
      {
        v46 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v45);
      }
      else if ( (v47 >> 12) & 1 )
      {
        v46 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v45->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v46 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v45->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v46 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v45);
    }
  }
  else
  {
    v46 = 0i64;
  }
  v48 = v46->mCreature;
  if ( v48 )
  {
    v49 = Creature::GetPositionhkQ(v48, &v117);
    v50 = (*((_BYTE *)v4 + 0x25C) & 0x10) == 0;
    v51 = v49->m_translation.m_quad;
    v115 = v51;
    v52 = _mm_shuffle_ps(v51, v51, 170);
    v115.m128_f32[2] = v52.m128_f32[0] + v4->mHeightFixup;
    if ( v50 )
    {
      v52 = (__m128)(unsigned int)FLOAT_1_0;
      v53 = _mm_sub_ps(v115, v44);
      v115 = v53;
      v54 = v53.m128_f32[0] * (float)(1.0 / v6);
      v55 = v115.m128_f32[1] * (float)(1.0 / v6);
      v56 = v53.m128_f32[2] * (float)(1.0 / v6);
      v115.m128_f32[0] = v54;
      v115.m128_f32[1] = v115.m128_f32[1] * (float)(1.0 / v6);
    }
    else
    {
      v57 = v4->mHavokCharacter->m_character->m_motion.m_linearVelocity.m_quad;
      v115 = v57;
      v55 = v115.m128_f32[1];
      v54 = v57.m128_f32[0];
      LODWORD(v56) = (unsigned __int128)_mm_shuffle_ps(v57, v57, 170);
      v4->mSpeedZ = v56;
    }
    v115.m128_f32[2] = v56;
    if ( v3 )
    {
      v4->mSpeedZ = v56;
      goto LABEL_110;
    }
    v50 = (*((_BYTE *)&v4->mGroundProperties + 68) & 1) == 0;
    *(float *)&v58 = v55 + v4->mAdditiveVelocity.y;
    v59 = v4->mHavokCharacter;
    *(float *)&v60 = v56 + v4->mAdditiveVelocity.z;
    v115.m128_f32[0] = v54 + v4->mAdditiveVelocity.x;
    *(unsigned __int64 *)((char *)v115.m128_u64 + 4) = __PAIR__(v60, v58);
    v61 = v59->m_character;
    if ( v50 )
      v62 = IN_AIR_FRICTION;
    else
      v62 = ON_GROUND_FRICTION;
    hkpRigidBody::setFriction(v61, v62);
    if ( *((_BYTE *)&v4->mGroundProperties + 68) & 2 || *((_DWORD *)v4 + 151) & 0x100 )
    {
      v80 = *((_DWORD *)v4 + 151);
      if ( v80 & 0x20 || _bittest(&v80, 8u) )
      {
        v81 = &v4->mCurbBullShitHackNormal.x;
        v82 = (unsigned __int8)v80 >> 8;
        if ( !v82 )
          v81 = &v4->mGroundProperties.groundNormal.x;
        v83 = v81[2];
        if ( v82 || v83 > 0.70700002 )
          v4->mSpeedZ = v115.m128_f32[2]
                      - (float)((float)((float)((float)(v115.m128_f32[1] * v81[1]) + (float)(v115.m128_f32[0] * *v81))
                                      + (float)(v115.m128_f32[2] * v83))
                              * v83);
        goto LABEL_105;
      }
    }
    else
    {
      v63 = 0i64;
      if ( v42 )
      {
        v64 = v4->mHavokCharacter->m_character;
        v65 = v4->mWaterTracker.m_pPointer;
        *(hkVector4f *)number = v64->m_motion.m_motionState.m_transform.m_translation;
        if ( v65 )
          v66 = *((float *)&v65[2].m_SafePointerList.mNode.mPrev + 1);
        else
          v66 = FLOAT_N0_31400001;
        v67 = (float)(v4->mParam.mCollisionHeight[v4->mCollisionModelType] * 0.5) + 0.4 + number[2];
        v68 = UFG::PhysicsSystem::ComputeBuoyancy(v2, v67, 1.0, v66);
        v63 = 0i64;
        if ( COERCE_FLOAT(LODWORD(v68) & _xmm) > 0.0099999998 )
        {
          v69 = _mm_shuffle_ps(v64->m_motion.m_linearVelocity.m_quad, v64->m_motion.m_linearVelocity.m_quad, 170);
          v69.m128_f32[0] = v69.m128_f32[0] * UFG::CharacterPhysicsComponent::mViscousFrictionCoeff;
          v63 = _mm_xor_ps(v69, (__m128)(unsigned int)_xmm[0]);
        }
        v63.m128_f32[0] = v63.m128_f32[0] + (float)(v68 * UFG::CharacterPhysicsComponent::mBuoyancy);
        if ( (UFG::SimObjectCharacter *)v4->m_pSimObject == LocalPlayer )
        {
          v70 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v70, PlayerLastStableLocationX, number[0]);
          UFG::GameStatTracker::SetStat(v70, PlayerLastStableLocationY, number[1]);
          UFG::GameStatTracker::SetStat(v70, PlayerLastStableLocationZ, v66);
        }
      }
      if ( v4->mGrappleState != 2 )
      {
        v71 = (hkpEntity *)&v4->mHavokCharacter->m_character->vfptr;
        v63.m128_f32[0] = (float)(v63.m128_f32[0] + v4->mGravity)
                        * hkpMotion::getMass((hkpMotion *)&v71->m_motion.vfptr);
        *(__m128 *)number = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v63), (__m128)0i64);
        hkpEntity::activate(v71);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, float *))v71->m_motion.vfptr[13].__vecDelDtor)(
          &v71->m_motion,
          v72,
          number);
        v4->mSpeedZ = v71->m_motion.m_linearVelocity.m_quad.m128_f32[2];
LABEL_105:
        v84 = *((_DWORD *)v4 + 151);
        if ( !(v84 & 1) || _bittest(&v84, 8u) )
        {
          v52 = (__m128)LODWORD(v4->mSpeedZ);
          v115.m128_i32[2] = LODWORD(v4->mSpeedZ);
        }
        else
        {
          v52 = (__m128)v115.m128_u32[2];
          v4->mSpeedZ = v115.m128_f32[2];
        }
LABEL_110:
        v85 = v4->mRagdollComponent.m_pSimComponent;
        if ( !v85 || *(float *)&v85[2].vfptr < 1.0 || (v86 = (int)v85[2].m_SafePointerList.mNode.mPrev) == 0 || v86 == 5 )
        {
          v87 = (UFG::SimObjectCVBase *)v4->m_pSimObject;
          if ( v87 )
          {
            v88 = v87->m_Flags;
            if ( (v88 >> 14) & 1 )
            {
              v89 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v87);
            }
            else if ( (v88 & 0x8000u) == 0 )
            {
              if ( (v88 >> 13) & 1 )
                v89 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v87);
              else
                v89 = (UFG::CharacterAnimationComponent *)((v88 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                               (UFG::SimObjectGame *)&v87->vfptr,
                                                                               UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v87->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
            }
            else
            {
              v89 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v87);
            }
            if ( v89 && v89->mUpdatedFromNIS )
              v4->mSpeedZ = 0.0;
          }
        }
        if ( !v42 )
          goto LABEL_148;
        *(float *)&result[0].m_bool = 0.0;
        *(_QWORD *)&dir.x = 0i64;
        dir.z = 0.0;
        v90 = FLOAT_15_0;
        number[0] = rotation.m_vec.m_quad.m128_f32[0];
        v52 = (__m128)rotation.m_vec.m_quad.m128_u32[2];
        *(_QWORD *)&number[1] = *(unsigned __int64 *)((char *)rotation.m_vec.m_quad.m128_u64 + 4);
        if ( (UFG::SimObjectCharacter *)v4->m_pSimObject == LocalPlayer
          && UFG::WorldBoundaries::IsOutsideBoundaries2(&v2->mBoundaries, (UFG::qVector3 *)number, 15.0, &dir) )
        {
          v91 = (__m128)LODWORD(dir.y);
          v92 = (__m128)LODWORD(dir.x);
          v93 = (__m128)LODWORD(dir.z);
          LODWORD(v94) = COERCE_UNSIGNED_INT(
                           (float)((float)(dir.y * v115.m128_f32[1]) + (float)(dir.x * v115.m128_f32[0]))
                         + (float)(dir.z * v115.m128_f32[2])) ^ _xmm[0];
          if ( v94 < 0.0 )
            v94 = 0.0;
          v95 = v94 + 1.0;
          v91.m128_f32[0] = dir.y * v95;
          v93.m128_f32[0] = dir.z * v95;
          v92.m128_f32[0] = dir.x * v95;
          v52 = _mm_add_ps(v115, _mm_unpacklo_ps(_mm_unpacklo_ps(v92, v93), _mm_unpacklo_ps(v91, (__m128)0i64)));
          v115 = v52;
          goto LABEL_148;
        }
        if ( !UFG::WorldBoundaries::IsOutsideBoundaries(
                &v2->mBoundaries,
                (UFG::qVector3 *)number,
                15.0,
                &dir,
                (float *)result) )
        {
LABEL_148:
          v4->mHavokCharacter->m_fixCurbContacts = *((_BYTE *)v4 + 604) & 0x20
                                                && (v52 = (__m128)LODWORD(CharacterRigidBody::mMaxCurbHeight),
                                                    (float)(CharacterRigidBody::mMaxCurbHeight * 2.0) > v4->mGroundProperties.heightAboveGround);
          v110 = v4->m_pSimObject;
          if ( !v110 || !((v110->m_Flags >> 11) & 1) )
          {
            v111 = (__m128 *)v4->mHavokCharacter;
            v112 = (hkpEntity *)v111[2].m128_u64[0];
            v52.m128_f32[0] = 1.0 / v6;
            v111[10] = _mm_mul_ps(_mm_sub_ps(v115, v112->m_motion.m_linearVelocity.m_quad), _mm_shuffle_ps(v52, v52, 0));
            hkpEntity::activate(v112);
            v112->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v112->m_motion.vfptr, (unsigned int)&v115);
          }
          return;
        }
        v96 = (__m128)v115.m128_u32[1];
        v97 = (__m128)v115.m128_u32[0];
        v98 = (__m128)v115.m128_u32[2];
        v99 = *(float *)&result[0].m_bool;
        v100 = (float)((float)(dir.y * v115.m128_f32[1]) + (float)(dir.x * v115.m128_f32[0]))
             + (float)(dir.z * v115.m128_f32[2]);
        if ( v100 >= 0.0 )
        {
          v106 = v115;
LABEL_142:
          if ( *(float *)&result[0].m_bool <= 0.0 )
          {
            v99 = 0.0;
          }
          else
          {
            v107 = FLOAT_13_0;
            if ( *(float *)&result[0].m_bool >= 13.0 )
              goto LABEL_147;
          }
          v107 = v99;
LABEL_147:
          v52 = (__m128)(unsigned int)FLOAT_1_0;
          v52.m128_f32[0] = (float)(1.0 - (float)(v107 * 0.07692308)) * 4.0;
          v108 = v52;
          v109 = v52;
          v52.m128_f32[0] = v52.m128_f32[0] * dir.z;
          v108.m128_f32[0] = v108.m128_f32[0] * dir.x;
          v109.m128_f32[0] = v109.m128_f32[0] * dir.y;
          v115 = _mm_add_ps(v106, _mm_unpacklo_ps(_mm_unpacklo_ps(v108, v52), _mm_unpacklo_ps(v109, (__m128)0i64)));
          goto LABEL_148;
        }
        v101 = v100 * dir.z;
        v104 = *(float *)&result[0].m_bool - 4.0;
        if ( (float)(*(float *)&result[0].m_bool - 4.0) <= 0.0 )
        {
          v104 = 0.0;
        }
        else if ( v104 >= 15.0 )
        {
          goto LABEL_140;
        }
        v90 = v104;
LABEL_140:
        v105 = v90 * 0.06666667;
        v98.m128_f32[0] = (float)(v115.m128_f32[2] - v101) + (float)(v105 * v101);
        v102 = (float)((float)((float)(dir.y * v115.m128_f32[1]) + (float)(dir.x * v115.m128_f32[0]))
                     + (float)(dir.z * v115.m128_f32[2]))
             * dir.x;
        v97.m128_f32[0] = (float)(v115.m128_f32[0] - v102) + (float)(v105 * v102);
        v103 = (float)((float)((float)(dir.y * v115.m128_f32[1]) + (float)(dir.x * v115.m128_f32[0]))
                     + (float)(dir.z * v115.m128_f32[2]))
             * dir.y;
        v96.m128_f32[0] = (float)(v115.m128_f32[1] - v103) + (float)(v105 * v103);
        v106 = _mm_unpacklo_ps(_mm_unpacklo_ps(v97, v98), _mm_unpacklo_ps(v96, (__m128)0i64));
        goto LABEL_142;
      }
      v73 = (UFG::SimObjectGame *)v4->mGrapplePartner.m_pPointer;
      if ( !v73 )
        goto LABEL_105;
      v74 = v73->m_Flags;
      if ( (v74 >> 14) & 1 )
      {
        v75 = v73->m_Components.p[27].m_pComponent;
      }
      else
      {
        if ( (v74 & 0x8000u) == 0 )
        {
          if ( (v74 >> 13) & 1 )
            v76 = UFG::SimObjectGame::GetComponentOfTypeHK(v73, UFG::CharacterPhysicsComponent::_TypeUID);
          else
            v76 = (v74 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v73,
                                      UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                    (UFG::SimObject *)&v73->vfptr,
                                                                                    UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v76 = UFG::SimObjectGame::GetComponentOfTypeHK(v73, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        v75 = v76;
      }
      if ( !v75 )
        goto LABEL_105;
      v77 = (hkpEntity *)&v4->mHavokCharacter->m_character->vfptr;
      v78 = (__m128 *)v75[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
      if ( v77
        && v78
        && _mm_movemask_ps(_mm_cmpltps(v78[26], v77->m_motion.m_motionState.m_transform.m_translation.m_quad)) & 4 )
      {
        v63.m128_f32[0] = (float)(v63.m128_f32[0] + v4->mGravity)
                        * hkpMotion::getMass((hkpMotion *)&v77->m_motion.vfptr);
        *(__m128 *)number = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v63), (__m128)0i64);
        hkpEntity::activate(v77);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, float *))v77->m_motion.vfptr[13].__vecDelDtor)(
          &v77->m_motion,
          v79,
          number);
        v4->mSpeedZ = v77->m_motion.m_linearVelocity.m_quad.m128_f32[2];
        goto LABEL_105;
      }
    }
    v4->mSpeedZ = 0.0;
    goto LABEL_105;
  }
}

// File Line: 1216
// RVA: 0x47EB10
void __fastcall UFG::CharacterPhysicsComponent::UpdateGroundState(UFG::CharacterPhysicsComponent *this, float timestep)
{
  UFG::CharacterPhysicsComponent *v2; // rdi
  CharacterRigidBody *v3; // rcx
  hkpRigidBody *v4; // rax
  float v5; // xmm0_4
  bool v6; // zf
  unsigned int v7; // edx
  hkpSurfaceInfo::SupportedState v8; // ecx
  int v9; // eax
  int v10; // eax
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  UFG::GameStatTracker *v21; // rbx
  UFG::SimObjectCVBase *v22; // rcx
  unsigned __int16 v23; // dx
  UFG::CharacterAnimationComponent *v24; // rax
  Creature *v25; // rcx
  hkStepInfo stepInfo; // [rsp+20h] [rbp-88h]
  hkVector4f v27; // [rsp+30h] [rbp-78h]
  hkpSurfaceInfo ground; // [rsp+40h] [rbp-68h]

  v2 = this;
  v3 = this->mHavokCharacter;
  v4 = v3->m_character;
  stepInfo.m_startTime.m_storage = 0.0;
  stepInfo.m_endTime.m_storage = timestep;
  stepInfo.m_deltaTime.m_storage = timestep;
  v27.m_quad = (__m128)v4->m_motion.m_motionState.m_transform.m_translation;
  if ( timestep == 0.0 )
    v5 = 0.0;
  else
    v5 = 1.0 / timestep;
  v6 = v3->m_isPlayer == 0;
  stepInfo.m_invDeltaTime.m_storage = v5;
  ground.m_surfaceDistanceExcess = 0.0;
  ground.m_surfaceIsDynamic.m_bool = 0;
  ground.m_surfaceNormal = (hkVector4f)stru_141A71280.m_quad;
  ground.m_surfaceVelocity = 0i64;
  ground.m_supportedState = 2;
  if ( v6 )
    CharacterRigidBody::checkSupportForNonPlayer(v3, &stepInfo, &ground);
  else
    CharacterRigidBody::checkSupportForPlayer(v3, &stepInfo, &ground);
  v7 = *((_DWORD *)v2 + 151);
  if ( (v7 & 0x80u) != 0 && v2->mHavokCharacter->m_supportedOffCentre )
  {
    v8 = ground.m_supportedState;
    if ( *((_BYTE *)&v2->mGroundProperties + 68) & 4 )
      v8 = 2;
  }
  else
  {
    v8 = ground.m_supportedState;
  }
  *((_DWORD *)&v2->mGroundProperties + 17) &= 0xFFFFFFF7;
  v9 = *((_DWORD *)&v2->mGroundProperties + 17);
  v2->mGroundProperties.support = v8;
  if ( v8 )
  {
    v14 = FLOAT_0_050000001;
    v15 = v9 | 1;
    *((_DWORD *)&v2->mGroundProperties + 17) = v15;
    v16 = (v7 >> 1) & 1;
    if ( !v16 || COERCE_FLOAT(LODWORD(v2->mGroundProperties.heightAboveGround) & _xmm) > 0.050000001 )
    {
      if ( !v16 )
        v14 = 0.0;
      v2->mGroundProperties.heightAboveGround = v14;
      *((_DWORD *)&v2->mGroundProperties + 17) = v15 | 8;
    }
    v17 = *((_DWORD *)&v2->mGroundProperties + 17);
    v18 = v27.m_quad.m128_f32[2];
    if ( v17 & 4 || (v19 = v2->mGroundProperties.timeOffGround, v19 < 0.5) )
    {
      *(_QWORD *)&v2->mGroundProperties.latchedFallDistance = 0i64;
    }
    else
    {
      v20 = v2->mGroundProperties.maxOffGroundElevation;
      v2->mGroundProperties.latchedFallTime = v19;
      v2->mGroundProperties.latchedFallDistance = v20 - v18;
    }
    v2->mGroundProperties.maxOffGroundElevation = v18;
    v2->mGroundProperties.timeOffGround = 0.0;
    *((_DWORD *)&v2->mGroundProperties + 17) = v17 | 2;
    if ( (UFG::SimObjectCharacter *)v2->m_pSimObject == LocalPlayer )
    {
      v21 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v21, PlayerLastStableLocationX, v2->mGroundProperties.groundPosition.x);
      UFG::GameStatTracker::SetStat(v21, PlayerLastStableLocationY, v2->mGroundProperties.groundPosition.y);
      UFG::GameStatTracker::SetStat(v21, PlayerLastStableLocationZ, v2->mGroundProperties.groundPosition.z);
    }
  }
  else
  {
    *((_DWORD *)&v2->mGroundProperties + 17) = v9 & 0xFFFFFFFE;
    v10 = 0;
    if ( !(v7 & 4) )
    {
      v2->mGroundProperties.heightAboveGround = 0.0;
      v11 = UFG::qVector3::msZero.z;
      v12 = UFG::qVector3::msZero.x;
      v2->mGroundProperties.groundPosition.y = UFG::qVector3::msZero.y;
      v2->mGroundProperties.groundPosition.z = v11;
      v2->mGroundProperties.groundPosition.x = v12;
    }
    if ( v27.m_quad.m128_f32[2] > v2->mGroundProperties.maxOffGroundElevation )
      v2->mGroundProperties.maxOffGroundElevation = v27.m_quad.m128_f32[2];
    v13 = timestep + v2->mGroundProperties.timeOffGround;
    v2->mGroundProperties.timeOffGround = v13;
    LOBYTE(v10) = UFG::CharacterPhysicsComponent::mMaxTimeOffGroundFilter >= v13;
    *((_DWORD *)&v2->mGroundProperties + 17) ^= (*((_DWORD *)&v2->mGroundProperties + 17) ^ 2 * v10) & 2;
  }
  v22 = (UFG::SimObjectCVBase *)v2->m_pSimObject;
  if ( v22 )
  {
    v23 = v22->m_Flags;
    if ( (v23 >> 14) & 1 )
    {
      v24 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v22);
    }
    else if ( (v23 & 0x8000u) == 0 )
    {
      if ( (v23 >> 13) & 1 )
      {
        v24 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v22);
      }
      else if ( (v23 >> 12) & 1 )
      {
        v24 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v22->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v24 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v22->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v24 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v22);
    }
    if ( v24 )
    {
      v25 = v24->mCreature;
      if ( v25 )
        Creature::SetGroundProperties(v25, &v2->mGroundProperties);
    }
  }
}

// File Line: 1338
// RVA: 0x47FF90
void __fastcall UFG::CharacterPhysicsComponent::UpdateTransforms(UFG::CharacterPhysicsComponent *this, float deltaT)
{
  UFG::CharacterPhysicsComponent *v2; // rbx
  UFG::SimComponent *v3; // rax
  UFG::TransformNodeComponent *v4; // rdi
  int v5; // ecx
  UFG::SimObjectCVBase *v6; // rcx
  UFG::CharacterAnimationComponent *v7; // rdx
  unsigned __int16 v8; // dx
  UFG::CharacterAnimationComponent *v9; // rax
  Creature *v10; // rsi
  int v11; // eax
  bool v12; // zf
  float v13; // xmm2_4
  __int128 v14; // xmm1
  float v15; // xmm3_4
  hkQsTransformf *v16; // rax
  CharacterRigidBody *v17; // rcx
  UFG::SimObject *v18; // rax
  __m128 v19; // xmm1
  UFG::qVector3 pos; // [rsp+20h] [rbp-58h]
  hkVector4f position; // [rsp+30h] [rbp-48h]
  hkQsTransformf result; // [rsp+40h] [rbp-38h]

  v2 = this;
  if ( (this->m_Flags & 3) == 1 )
  {
    UFG::CharacterPhysicsComponent::UpdateGroundState(this, deltaT);
    v3 = v2->mRagdollComponent.m_pSimComponent;
    v4 = 0i64;
    if ( !v3 || *(float *)&v3[2].vfptr < 1.0 || (v5 = (int)v3[2].m_SafePointerList.mNode.mPrev) == 0 || v5 == 5 )
    {
      v6 = (UFG::SimObjectCVBase *)v2->m_pSimObject;
      if ( v6 )
      {
        v8 = v6->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
            v9 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v6);
          else
            v9 = (UFG::CharacterAnimationComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v6->vfptr,
                                                                         UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
        }
        else
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
        }
        v7 = v9;
      }
      else
      {
        v7 = 0i64;
      }
      v10 = v7->mCreature;
      position.m_quad = (__m128)v2->mHavokCharacter->m_character->m_motion.m_motionState.m_transform.m_translation;
      if ( v10 )
      {
        *((_DWORD *)v2 + 151) &= 0xFFFFFEFF;
        v11 = *((_DWORD *)v2 + 151);
        if ( v7->mUpdatedFromNIS )
        {
          v16 = Creature::GetPositionhkQ(v10, &result);
          v17 = v2->mHavokCharacter;
          position.m_quad = (__m128)v16->m_translation;
          hkpRigidBody::setPosition(v17->m_character, &position);
          v13 = position.m_quad.m128_f32[2];
        }
        else
        {
          if ( (v11 & 0x80u) != 0 && v11 & 0x40 && !UFG::CharacterPhysicsComponent::mDisableCurbHack )
            UFG::CharacterPhysicsComponent::MagicCurbBullShitHack(v2);
          v12 = (*((_BYTE *)v2 + 604) & 8) == 0;
          v13 = position.m_quad.m128_f32[2] - v2->mHeightFixup;
          position.m_quad.m128_f32[2] = position.m_quad.m128_f32[2] - v2->mHeightFixup;
          if ( !v12 )
          {
            v14 = Creature::GetPositionhkQ(v10, &result)->m_translation.m_quad.m128_u32[2];
            v15 = position.m_quad.m128_f32[2] - *(float *)&v14;
            if ( (float)(position.m_quad.m128_f32[2] - *(float *)&v14) <= 0.0 )
            {
              v13 = (float)(UFG::CharacterPhysicsComponent::mZFilterValueDown * v15) + *(float *)&v14;
              position.m_quad.m128_f32[2] = (float)(UFG::CharacterPhysicsComponent::mZFilterValueDown * v15)
                                          + *(float *)&v14;
            }
            else
            {
              v13 = (float)(UFG::CharacterPhysicsComponent::mZFilterValueUp * v15) + *(float *)&v14;
              position.m_quad.m128_f32[2] = (float)(UFG::CharacterPhysicsComponent::mZFilterValueUp * v15)
                                          + *(float *)&v14;
            }
          }
        }
        if ( !sDontUpdate )
        {
          *(_QWORD *)&pos.x = position.m_quad.m128_u64[0];
          pos.z = v13;
          Creature::SetTranslation(v10, &pos);
          if ( !v2->mRagdollComponent.m_pSimComponent )
            Creature::UpdateAttachmentPoses(v10);
        }
      }
    }
    v18 = v2->m_pSimObject;
    if ( v18 )
      v4 = v18->m_pTransformNodeComponent;
    if ( v4 )
    {
      v19 = v2->mHavokCharacter->m_character->m_motion.m_linearVelocity.m_quad;
      LODWORD(v4->mWorldVelocity.x) = v19.m128_i32[0];
      LODWORD(v4->mWorldVelocity.z) = (unsigned __int128)_mm_shuffle_ps(v19, v19, 170);
      LODWORD(v4->mWorldVelocity.y) = (unsigned __int128)_mm_shuffle_ps(v19, v19, 85);
    }
    v2->vfptr->DebugDraw((UFG::BasePhysicsObject *)&v2->vfptr);
  }
}

// File Line: 1426
// RVA: 0x468630
int UFG::CharacterPhysicsComponent::GrappleFixup(...)
{
  UFG::CharacterPhysicsComponent *v3; // rbx
  float v4; // xmm6_4
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  __m128 v8; // xmm7
  UFG::SimObjectCVBase *v9; // rcx
  UFG::CharacterAnimationComponent *v10; // rax
  unsigned __int16 v11; // dx
  Creature *v12; // rcx
  hkVector4f v13; // xmm1
  __m128 v14; // xmm2
  hkQsTransformf result; // [rsp+20h] [rbp-58h]

  v3 = this;
  v4 = deltaT;
  if ( (this->m_Flags & 3) == 1 && this->mGrappleState == 1 )
  {
    v5 = (UFG::SimObjectGame *)this->mGrapplePartner.m_pPointer;
    if ( v5 )
    {
      if ( deltaT > 0.0 )
      {
        v6 = v5->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = v5->m_Components.p[27].m_pComponent;
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
          {
            v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else if ( (v6 >> 12) & 1 )
          {
            v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else
          {
            v7 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v5->vfptr,
                   UFG::CharacterPhysicsComponent::_TypeUID);
          }
        }
        else
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        v8 = (__m128)v7[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev[26];
        v9 = (UFG::SimObjectCVBase *)v3->mGrapplePartner.m_pPointer;
        if ( v9 )
        {
          v11 = v9->m_Flags;
          if ( (v11 >> 14) & 1 )
          {
            v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
          }
          else if ( (v11 & 0x8000u) == 0 )
          {
            if ( (v11 >> 13) & 1 )
            {
              v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
            }
            else if ( (v11 >> 12) & 1 )
            {
              v10 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v9->vfptr,
                                                          UFG::CharacterAnimationComponent::_TypeUID);
            }
            else
            {
              v10 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v9->vfptr,
                                                          UFG::CharacterAnimationComponent::_TypeUID);
            }
          }
          else
          {
            v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
          }
        }
        else
        {
          v10 = 0i64;
        }
        v12 = v10->mCreature;
        if ( v12 )
        {
          v13.m_quad = (__m128)Creature::GetPositionhkQ(v12, &result)->m_translation;
          v3->mAdditiveVelocity.z = 0.0;
          a3.m128_f32[0] = (float)(-1.0 / v4) * 0.2;
          v14 = _mm_mul_ps(_mm_shuffle_ps(a3, a3, 0), _mm_sub_ps(v13.m_quad, v8));
          LODWORD(v3->mAdditiveVelocity.x) = v14.m128_i32[0];
          LODWORD(v3->mAdditiveVelocity.y) = (unsigned __int128)_mm_shuffle_ps(v14, v14, 85);
        }
      }
    }
  }
}

// File Line: 1469
// RVA: 0x46BE00
void __fastcall UFG::CharacterPhysicsComponent::MagicCurbBullShitHack(UFG::CharacterPhysicsComponent *this)
{
  UFG::CharacterPhysicsComponent *v1; // rbx
  __m128 v2; // xmm7
  __m128 v3; // xmm0
  float v4; // xmm6_4
  char *v5; // rbx
  UFG::RayCastData *v6; // rdi
  signed __int64 v7; // rsi
  __m128 v8; // ST30_16
  UFG::RayCastData *v9; // rbx
  UFG::allocator::free_link *v10; // rdi
  unsigned int v11; // er14
  unsigned int v12; // ecx
  signed int v13; // er13
  char *v14; // r12
  unsigned int v15; // edx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  unsigned __int64 v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // r15
  UFG::allocator::free_link *v21; // rdx
  __int64 v22; // rcx
  int v23; // er8
  unsigned int v24; // er14
  __int64 v25; // r9
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  unsigned int v29; // er9
  __int64 v30; // r8
  UFG::allocator::free_link *v31; // rdx
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  UFG::allocator::free_link *v35; // rcx
  float v36; // xmm8_4
  __m128 v37; // xmm9
  float v38; // xmm10_4
  __m128 v39; // xmm2
  __int64 v40; // rax
  __m128 v41; // xmm6
  __m128 v42; // xmm11
  float v43; // xmm5_4
  __m128 v44; // xmm3
  float v45; // xmm1_4
  float v46; // xmm11_4
  float v47; // xmm5_4
  float v48; // xmm3_4
  float v49; // xmm5_4
  __m128 v50; // xmm4
  float v51; // xmm2_4
  hkVector4f rayEnd; // [rsp+40h] [rbp-88h]
  hkVector4f direction; // [rsp+50h] [rbp-78h]
  hkVector4f axis; // [rsp+60h] [rbp-68h]
  hkQuaternionf quat; // [rsp+70h] [rbp-58h]
  char ptr[144]; // [rsp+88h] [rbp-40h]
  char v57; // [rsp+118h] [rbp+50h]
  char v58; // [rsp+138h] [rbp+70h]
  __int64 v59; // [rsp+9E8h] [rbp+920h]
  char *v60; // [rsp+9F8h] [rbp+930h]

  quat.m_vec.m_quad.m128_u64[1] = -2i64;
  v1 = this;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  if ( v1->mHavokCharacter )
  {
    axis.m_quad = _xmm;
    hkQuaternionf::setAxisAngle(&quat, &axis, v1->mFacing);
    v2 = v1->mHavokCharacter->m_character->m_motion.m_motionState.m_transform.m_translation.m_quad;
    direction.m_quad = v2;
    *(hkVector4f *)((char *)&axis + 8) = (hkVector4f)_mm_add_ps((__m128)_xmm, v2);
    v3 = (__m128)_xmm;
    *(hkVector4f *)((char *)&direction + 8) = (hkVector4f)_xmm;
    hkVector4f::setRotatedDir(&rayEnd, &quat, (hkVector4f *)((char *)&direction + 8));
    v4 = FLOAT_0_1;
    `eh vector constructor iterator(ptr, 0xE0ui64, 10, (void (__fastcall *)(void *))UFG::RayCastData::RayCastData);
    v5 = &v57;
    v6 = (UFG::RayCastData *)ptr;
    v7 = 10i64;
    do
    {
      v3.m128_f32[0] = v4;
      v8 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), rayEnd.m_quad);
      v8.m128_i32[2] = -1110651699;
      v3 = _mm_add_ps(v8, v2);
      *(hkVector4f *)((char *)&rayEnd + 8) = (hkVector4f)v3;
      *(_QWORD *)v5 = "CurbHack";
      UFG::RayCastData::Init(v6, (hkVector4f *)((char *)&axis + 8), (hkVector4f *)((char *)&rayEnd + 8), 0xEu);
      v4 = v4 + 0.1;
      ++v6;
      v5 += 224;
      --v7;
    }
    while ( v7 );
    v9 = (UFG::RayCastData *)ptr;
    v10 = (UFG::allocator::free_link *)10;
    do
    {
      UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, v9);
      ++v9;
      v10 = (UFG::allocator::free_link *)((char *)v10 - 1);
    }
    while ( v10 );
    v11 = 0;
    v12 = 0;
    v13 = 0;
    v14 = &v58;
    do
    {
      if ( !v14[24] )
      {
        if ( v10 )
          operator delete[](v10);
        goto LABEL_55;
      }
      if ( *(float *)v14 > 0.70700002 )
      {
        v60 = &ptr[224 * v13];
        v15 = v11;
        v16 = v11 + 1;
        if ( v11 + 1 > v12 )
        {
          v17 = 1;
          if ( v12 )
            v17 = 2 * v12;
          for ( ; v17 < v16; v17 *= 2 )
            ;
          if ( v17 <= 2 )
            v17 = 2;
          if ( v17 - v16 > 0x10000 )
            v17 = v11 + 65537;
          if ( v17 != v11 )
          {
            v18 = 8i64 * v17;
            if ( !is_mul_ok(v17, 8ui64) )
              v18 = -1i64;
            v19 = UFG::qMalloc(v18, "qArray.Add", 0i64);
            v20 = v19;
            if ( v10 )
            {
              if ( v11 )
              {
                v21 = v19;
                v22 = v11;
                do
                {
                  v21->mNext = *(UFG::allocator::free_link **)((char *)v21 + (char *)v10 - (char *)v19);
                  ++v21;
                  --v22;
                }
                while ( v22 );
              }
              operator delete[](v10);
            }
            v10 = v20;
            v12 = v17;
            v15 = v11;
          }
        }
        ++v11;
        v10[v15].mNext = (UFG::allocator::free_link *)v60;
      }
      ++v13;
      v14 += 224;
    }
    while ( v13 < 10 );
    if ( v11 )
    {
      v23 = 0;
      v24 = v11 - 1;
      if ( v24 )
      {
        while ( 1 )
        {
          v25 = (unsigned int)(v23 + 1);
          v26 = *((float *)&v10[v23].mNext[20].mNext + 1);
          v27 = *((float *)&v10[v25].mNext[20].mNext + 1) - v26;
          v28 = v26 - direction.m_quad.m128_f32[2];
          if ( v27 >= 0.0099999998
            && v27 <= UFG::CharacterPhysicsComponent::mCurbHackMaxHeight
            && v28 <= UFG::CharacterPhysicsComponent::mCurbHackMaxHeight )
          {
            break;
          }
          ++v23;
          if ( (unsigned int)v25 >= v24 )
            goto LABEL_50;
        }
        v29 = v23 + 1;
        if ( v23 != -1 )
        {
          LODWORD(v30) = v23 + 1;
          if ( v29 < v24 )
          {
            do
            {
              v31 = v10[(unsigned int)v30].mNext;
              v30 = (unsigned int)(v30 + 1);
              v32 = *((float *)&v31[20].mNext + 1);
              v33 = *((float *)&v10[v30].mNext[20].mNext + 1) - v32;
              v34 = v32 - direction.m_quad.m128_f32[2];
              if ( v33 < 0.0099999998 )
                break;
              if ( v33 > UFG::CharacterPhysicsComponent::mCurbHackMaxHeight )
                break;
              if ( v34 > UFG::CharacterPhysicsComponent::mCurbHackMaxHeight )
                break;
              v29 = v30;
            }
            while ( (unsigned int)v30 < v24 );
          }
          v35 = v10[v29].mNext;
          v36 = *((float *)&v35[19].mNext + 1) - direction.m_quad.m128_f32[0];
          v37 = (__m128)LODWORD(v35[20].mNext);
          v37.m128_f32[0] = v37.m128_f32[0] - direction.m_quad.m128_f32[1];
          v38 = *((float *)&v35[20].mNext + 1) - direction.m_quad.m128_f32[2];
          v39 = v37;
          v39.m128_f32[0] = (float)((float)(v37.m128_f32[0] * v37.m128_f32[0]) + (float)(v36 * v36))
                          + (float)(v38 * v38);
          if ( COERCE_FLOAT(_mm_sqrt_ps(v39)) > 0.0 )
          {
            v40 = v59;
            *(_DWORD *)(v40 + 604) |= 0x100u;
            v41 = (__m128)rayEnd.m_quad.m128_u32[1];
            v42 = (__m128)rayEnd.m_quad.m128_u32[0];
            v41.m128_f32[0] = (float)(rayEnd.m_quad.m128_f32[1] * UFG::qVector3::msAxisZ.x)
                            - (float)(rayEnd.m_quad.m128_f32[0] * UFG::qVector3::msAxisZ.y);
            v42.m128_f32[0] = (float)(rayEnd.m_quad.m128_f32[0] * UFG::qVector3::msAxisZ.z)
                            - (float)(rayEnd.m_quad.m128_f32[2] * UFG::qVector3::msAxisZ.x);
            v43 = (float)(rayEnd.m_quad.m128_f32[2] * UFG::qVector3::msAxisZ.y)
                - (float)(rayEnd.m_quad.m128_f32[1] * UFG::qVector3::msAxisZ.z);
            v44 = v42;
            v44.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v43 * v43))
                            + (float)(v41.m128_f32[0] * v41.m128_f32[0]);
            if ( v44.m128_f32[0] == 0.0 )
              v45 = 0.0;
            else
              v45 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v44));
            v41.m128_f32[0] = v41.m128_f32[0] * v45;
            v46 = v42.m128_f32[0] * v45;
            v47 = v43 * v45;
            v48 = (float)(v46 * v36) - (float)(v47 * v37.m128_f32[0]);
            v49 = (float)(v47 * v38) - (float)(v41.m128_f32[0] * v36);
            v41.m128_f32[0] = (float)(v41.m128_f32[0] * v37.m128_f32[0]) - (float)(v46 * v38);
            v50 = v41;
            v50.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v49 * v49))
                            + (float)(v48 * v48);
            if ( v50.m128_f32[0] == 0.0 )
              v51 = 0.0;
            else
              v51 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v50));
            *(float *)(v40 + 568) = v41.m128_f32[0] * v51;
            *(float *)(v40 + 572) = v49 * v51;
            *(float *)(v40 + 576) = v48 * v51;
          }
        }
      }
    }
LABEL_50:
    if ( v10 )
      operator delete[](v10);
LABEL_55:
    `eh vector destructor iterator(ptr, 0xE0ui64, 10, (void (__fastcall *)(void *))_);
  }
}

// File Line: 1629
// RVA: 0x4757C0
void __fastcall UFG::CharacterPhysicsComponent::SetVelocity(UFG::CharacterPhysicsComponent *this, UFG::qVector3 *velocity)
{
  UFG::SimObject *v2; // rax
  CharacterRigidBody *v3; // rax
  hkpEntity *v4; // rbx
  __m128 v5; // [rsp+20h] [rbp-18h]

  v2 = this->m_pSimObject;
  if ( !v2 || !((v2->m_Flags >> 11) & 1) )
  {
    v3 = this->mHavokCharacter;
    v5 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(velocity->x), (__m128)LODWORD(velocity->z)),
           _mm_unpacklo_ps((__m128)LODWORD(velocity->y), (__m128)0i64));
    v4 = (hkpEntity *)&v3->m_character->vfptr;
    v3->m_acceleration.m_quad = _mm_mul_ps(_mm_sub_ps(v5, v4->m_motion.m_linearVelocity.m_quad), (__m128)_xmm);
    hkpEntity::activate(v4);
    v4->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v4->m_motion.vfptr, (unsigned int)&v5);
  }
}

// File Line: 1640
// RVA: 0x467070
hkpRigidBody *__fastcall UFG::CharacterPhysicsComponent::GetRigidBody(UFG::CharacterPhysicsComponent *this)
{
  return this->mHavokCharacter->m_character;
}

// File Line: 1647
// RVA: 0x468150
UFG::qVector3 *__fastcall UFG::CharacterPhysicsComponent::GetVelocity(UFG::CharacterPhysicsComponent *this, UFG::qVector3 *result)
{
  hkpRigidBody *v2; // rcx
  UFG::qVector3 *v3; // rax
  __m128 v4; // xmm1

  v2 = this->mHavokCharacter->m_character;
  v3 = result;
  v4 = v2->m_motion.m_linearVelocity.m_quad;
  LODWORD(result->x) = v4.m128_i32[0];
  result->z = v2->m_motion.m_linearVelocity.m_quad.m128_f32[2];
  LODWORD(result->y) = (unsigned __int128)_mm_shuffle_ps(v4, v4, 85);
  return v3;
}

// File Line: 1663
// RVA: 0x466870
float __fastcall UFG::CharacterPhysicsComponent::GetHeight(UFG::CharacterPhysicsComponent *this, UFG::CharacterCollisionMode model)
{
  return this->mParam.mCollisionHeight[model];
}

// File Line: 1670
// RVA: 0x467040
float __fastcall UFG::CharacterPhysicsComponent::GetRadius(UFG::CharacterPhysicsComponent *this)
{
  return this->mParam.mCollisionRadius[this->mCollisionModelType];
}

// File Line: 1675
// RVA: 0x467030
float __fastcall UFG::CharacterPhysicsComponent::GetRadius(UFG::CharacterPhysicsComponent *this, UFG::CharacterCollisionMode model)
{
  return this->mParam.mCollisionRadius[model];
}

// File Line: 1682
// RVA: 0x4749F0
void __fastcall UFG::CharacterPhysicsComponent::SetCollisionModel(UFG::CharacterPhysicsComponent *this, UFG::CharacterCollisionMode type)
{
  this->mDesiredCollisionModelType = type;
}

// File Line: 1689
// RVA: 0x463E20
void __fastcall UFG::CharacterPhysicsComponent::EnableDetailedOnGroundCheck(UFG::CharacterPhysicsComponent *this)
{
  *((_DWORD *)this + 151) |= 2u;
}

// File Line: 1696
// RVA: 0x461D30
void __fastcall UFG::CharacterPhysicsComponent::DisableDetailedOnGroundCheck(UFG::CharacterPhysicsComponent *this)
{
  *((_DWORD *)this + 151) &= 0xFFFFFFFD;
}

// File Line: 1703
// RVA: 0x46E930
void __fastcall UFG::CharacterPhysicsComponent::OnEnterWater(UFG::CharacterPhysicsComponent *this)
{
  UFG::CharacterPhysicsComponent *v1; // rdi
  CharacterRigidBody *v2; // rcx
  __m128 v3; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm1
  hkpEntity *v6; // rbx
  __m128 v7; // [rsp+20h] [rbp-28h]

  v1 = this;
  v2 = this->mHavokCharacter;
  v3 = _mm_mul_ps((__m128)_xmm, v2->m_character->m_motion.m_linearVelocity.m_quad);
  v4 = _mm_and_ps((__m128)xmmword_141687F20, v3);
  v7 = v3;
  v5 = _mm_or_ps(_mm_shuffle_ps(v4, v4, 78), v4);
  if ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v5, v5, 177) | v5.m128_i32[0]) < -15.0 )
  {
    v3 = _mm_or_ps(
           _mm_and_ps((__m128)_xmm_c1700000c1700000c1700000c1700000, (__m128)xmmword_141687F20),
           _mm_andnot_ps((__m128)xmmword_141687F20, v3));
    v7 = v3;
  }
  v6 = (hkpEntity *)&v2->m_character->vfptr;
  v2->m_acceleration.m_quad = _mm_mul_ps(_mm_sub_ps(v3, v6->m_motion.m_linearVelocity.m_quad), (__m128)_xmm);
  hkpEntity::activate(v6);
  v6->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v6->m_motion.vfptr, (unsigned int)&v7);
  if ( v1->mSpeedZ < -15.0 )
    v1->mSpeedZ = -15.0;
  if ( v1->mAdditiveVelocity.z < 0.0 )
    v1->mAdditiveVelocity.z = 0.0;
  UFG::GameStatAction::Character::EnterWater(v1->m_pSimObject);
}

// File Line: 1739
// RVA: 0x46AF80
bool __fastcall UFG::CharacterPhysicsComponent::IsInWater(UFG::CharacterPhysicsComponent *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->mWaterTracker.m_pPointer;
  if ( v1 )
    LOBYTE(v1) = SLODWORD(v1[1].m_BoundComponentHandles.mNode.mNext) > 0;
  return (char)v1;
}

// File Line: 1746
// RVA: 0x4683E0
float __fastcall UFG::CharacterPhysicsComponent::GetWaterElevation(UFG::CharacterPhysicsComponent *this)
{
  UFG::SimComponent *v1; // rax
  float result; // xmm0_4

  v1 = this->mWaterTracker.m_pPointer;
  if ( v1 )
    result = *((float *)&v1[2].m_SafePointerList.mNode.mPrev + 1);
  else
    result = FLOAT_N0_31400001;
  return result;
}

// File Line: 1753
// RVA: 0x4648E0
void __fastcall UFG::CharacterPhysicsComponent::FireAsyncRaycasts(UFG::CharacterPhysicsComponent *this, int currentBucket)
{
  hkpRigidBody *v2; // rdx
  UFG::BasePhysicsSystemVtbl *v3; // rax
  __m128 v4; // xmm3
  __m128 v5; // xmm2
  float v6; // xmm1_4
  int v7; // [rsp+40h] [rbp-28h]
  int v8; // [rsp+44h] [rbp-24h]
  float v9; // [rsp+48h] [rbp-20h]
  int v10; // [rsp+50h] [rbp-18h]
  int v11; // [rsp+54h] [rbp-14h]
  float v12; // [rsp+58h] [rbp-10h]

  if ( *((_BYTE *)this + 604) & 2 || this->mAsyncRaycastBucket == currentBucket )
  {
    v2 = this->mHavokCharacter->m_character;
    v3 = UFG::BasePhysicsSystem::mInstance->vfptr;
    v4 = v2->m_motion.m_motionState.m_transform.m_translation.m_quad;
    v5 = v2->m_motion.m_motionState.m_transform.m_translation.m_quad;
    v10 = (int)v2->m_motion.m_motionState.m_transform.m_translation;
    v7 = v4.m128_i32[0];
    LODWORD(v6) = (unsigned __int128)_mm_shuffle_ps(v4, v4, 170);
    v11 = (unsigned __int128)_mm_shuffle_ps(v5, v4, 85);
    v8 = v11;
    v9 = v6 - 4.0;
    v12 = v6 + 0.25;
    v3->CastAsyncRay(
      UFG::BasePhysicsSystem::mInstance,
      (UFG::qVector3 *)&v10,
      (UFG::qVector3 *)&v7,
      12u,
      UFG::CharacterPhysicsComponent::DetailedOnGroundCheck,
      (UFG::SimComponent *)&this->vfptr,
      0i64);
  }
}

// File Line: 1770
// RVA: 0x461830
void __fastcall UFG::CharacterPhysicsComponent::DetailedOnGroundCheck(UFG::RayCastData *raycastData, UFG::SimComponent *simComponent, void *callbackUserData)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // eax
  float v6; // xmm1_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rcx

  if ( simComponent )
  {
    simComponent[9].m_NameUID |= 4u;
    if ( raycastData->hit )
    {
      *(float *)&simComponent[5].m_BoundComponentHandles.mNode.mPrev = *(float *)&simComponent[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev[26].mNext
                                                                     - raycastData->point.z;
      v3 = raycastData->point.y;
      v4 = raycastData->point.z;
      simComponent[5].m_TypeUID = LODWORD(raycastData->point.x);
      *(float *)&simComponent[5].m_NameUID = v3;
      *(float *)&simComponent[5].m_Flags = v4;
      v5 = raycastData->normal.x;
      v6 = raycastData->normal.z;
      *(float *)&simComponent[5].m_pSimObject = raycastData->normal.y;
      *(float *)(&simComponent[5].m_SimObjIndex + 1) = v5;
      *((float *)&simComponent[5].m_pSimObject + 1) = v6;
      simComponent[6].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)raycastData->mPhysicsObjectPropertyHandleUid;
      v7 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)raycastData->mPhysicsSurfacePropertyHandleUid;
    }
    else
    {
      LODWORD(simComponent[5].m_BoundComponentHandles.mNode.mPrev) = 1082130432;
      v8 = UFG::qVector3::msZero.z;
      v7 = 0i64;
      v9 = UFG::qVector3::msZero.x;
      simComponent[5].m_NameUID = LODWORD(UFG::qVector3::msZero.y);
      *(float *)&simComponent[5].m_Flags = v8;
      *(float *)&simComponent[5].m_TypeUID = v9;
      v10 = UFG::qVector3::msAxisZ.z;
      v11 = UFG::qVector3::msAxisZ.x;
      *(float *)&simComponent[5].m_pSimObject = UFG::qVector3::msAxisZ.y;
      *((float *)&simComponent[5].m_pSimObject + 1) = v10;
      *(float *)(&simComponent[5].m_SimObjIndex + 1) = v11;
      simComponent[6].m_SafePointerList.mNode.mPrev = 0i64;
    }
    v12 = simComponent[6].m_BoundComponentHandles.mNode.mPrev;
    simComponent[6].m_SafePointerList.mNode.mNext = v7;
    LODWORD(v12[7].mNext) = simComponent[5].m_BoundComponentHandles.mNode.mPrev;
  }
}

// File Line: 1801
// RVA: 0x475370
void __fastcall UFG::CharacterPhysicsComponent::SetPairedGrappleMaster(UFG::CharacterPhysicsComponent *this, UFG::CharacterPhysicsComponent *slave, UFG::CharacterPhysicsComponent::GrappleMode mode)
{
  UFG::CharacterPhysicsComponent *v3; // r10
  UFG::SimObject *v4; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v9; // rcx

  v3 = this;
  v4 = slave->m_pSimObject;
  v5 = &v3->mGrapplePartner;
  if ( v3->mGrapplePartner.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v3->mGrapplePartner.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v3->mGrapplePartner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mGrapplePartner.mPrev;
  }
  v3->mGrapplePartner.m_pPointer = v4;
  if ( v4 )
  {
    v8 = v4->m_SafePointerList.mNode.mPrev;
    v9 = &v4->m_SafePointerList;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mPrev = v8;
    v3->mGrapplePartner.mNext = &v9->mNode;
    v9->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v3->mGrappleState = 1;
  v3->mDesiredCollisionModelType = (mode != 0) + 10;
}

// File Line: 1811
// RVA: 0x4753E0
void __fastcall UFG::CharacterPhysicsComponent::SetPairedGrappleSlave(UFG::CharacterPhysicsComponent *this, UFG::CharacterPhysicsComponent *master)
{
  UFG::CharacterPhysicsComponent *v2; // r9
  UFG::SimObject *v3; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v8; // rcx

  v2 = this;
  v3 = master->m_pSimObject;
  v4 = &v2->mGrapplePartner;
  if ( v2->mGrapplePartner.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v2->mGrapplePartner.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v2->mGrapplePartner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mGrapplePartner.mPrev;
  }
  v2->mGrapplePartner.m_pPointer = v3;
  if ( v3 )
  {
    v7 = v3->m_SafePointerList.mNode.mPrev;
    v8 = &v3->m_SafePointerList;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mPrev = v7;
    v2->mGrapplePartner.mNext = &v8->mNode;
    v8->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v2->mGrappleState = 2;
}

// File Line: 1819
// RVA: 0x45A690
void __fastcall UFG::CharacterPhysicsComponent::ClearPairedGrapple(UFG::CharacterPhysicsComponent *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v1; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rax
  bool v4; // zf

  v1 = &this->mGrapplePartner;
  if ( this->mGrapplePartner.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = this->mGrapplePartner.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    this->mGrapplePartner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mGrapplePartner.mPrev;
  }
  this->mGrapplePartner.m_pPointer = 0i64;
  v4 = this->mGrappleState == 1;
  this->mGrappleState = 0;
  if ( v4 )
    this->mDesiredCollisionModelType = 1;
}

// File Line: 1834
// RVA: 0x46D7F0
void __fastcall UFG::CharacterPhysicsComponent::NotifyProxyModeChanged(UFG::CharacterPhysicsComponent *this, UFG::SimObject::eProxyMode proxyMode)
{
  bool v2; // zf
  UFG::CharacterPhysicsComponent *v3; // rbx
  hkpRigidBody *v4; // rdx
  hkpWorld *v5; // rcx

  v2 = proxyMode == 2;
  v3 = this;
  v4 = this->mHavokCharacter->m_character;
  v5 = v4->m_world;
  v4->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = 1;
  if ( v2 )
  {
    if ( v5 )
      hkpWorld::updateCollisionFilterOnEntity(
        v5,
        (hkpEntity *)&v4->vfptr,
        0,
        HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
    v3->mGravity = 0.0;
    *((_DWORD *)v3 + 151) |= 1u;
  }
  else
  {
    if ( v5 )
      hkpWorld::updateCollisionFilterOnEntity(
        v5,
        (hkpEntity *)&v4->vfptr,
        0,
        HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
    v3->mGravity = -9.8100004;
    *((_DWORD *)v3 + 151) &= 0xFFFFFFFE;
  }
}

// File Line: 2067
// RVA: 0x475DC0
void UFG::CharacterPhysicsComponentManager::Shutdown(void)
{
  UFG::CharacterPhysicsComponentManager *v0; // rdi
  UFG::CharacterPhysicsComponentManager::ShapeCacheEntry *v1; // rcx
  hkpShape **v2; // rbx

  v0 = UFG::CharacterPhysicsComponentManager::mInstance;
  if ( UFG::CharacterPhysicsComponentManager::mInstance )
  {
    v1 = UFG::CharacterPhysicsComponentManager::mInstance->mCollisionShapeCache.p;
    if ( v1 )
    {
      v2 = &v1[-1].shape;
      `eh vector destructor iterator(
        v1,
        0x70ui64,
        (int)v1[-1].shape,
        (void (__fastcall *)(void *))UFG::CharacterPhysicsComponentManager::ShapeCacheEntry::~ShapeCacheEntry);
      operator delete[](v2);
    }
    v0->mCollisionShapeCache.p = 0i64;
    *(_QWORD *)&v0->mCollisionShapeCache.size = 0i64;
    operator delete[](v0);
  }
  UFG::CharacterPhysicsComponentManager::mInstance = 0i64;
}

// File Line: 2081
// RVA: 0x477B20
void __fastcall UFG::CharacterPhysicsComponentManager::Update(UFG::CharacterPhysicsComponentManager *this, float deltaT)
{
  UFG::CharacterPhysicsComponentManager *v2; // rdi
  UFG::CharacterPhysicsComponent *v3; // rcx
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v4; // rbx
  int v5; // eax

  v2 = this;
  v3 = (UFG::CharacterPhysicsComponent *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext;
  if ( &UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext != (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> **)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList - 104) )
  {
    do
    {
      v4 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&v3->mNext[-7].mNext;
      UFG::CharacterPhysicsComponent::FireAsyncRaycasts(v3, v2->mCurrentBucket);
      v3 = (UFG::CharacterPhysicsComponent *)v4;
    }
    while ( v4 != (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList
                                                                                                  - 104) );
  }
  v5 = ++v2->mCurrentBucket;
  if ( v5 == 12 )
    v5 = 0;
  v2->mCurrentBucket = v5;
}

// File Line: 2101
// RVA: 0x4673D0
hkpShape *__fastcall UFG::CharacterPhysicsComponentManager::GetShape(UFG::CharacterPhysicsComponentManager *this, UFG::CharacterCollisionMode model, float height, float radius)
{
  float v4; // xmm7_4
  UFG::CharacterCollisionMode v5; // esi
  UFG::CharacterPhysicsComponentManager *v6; // r15
  int v7; // er8
  unsigned int v8; // edx
  UFG::CharacterPhysicsComponentManager::ShapeCacheEntry *v9; // rcx
  signed __int64 v10; // rax
  hkpShape *result; // rax
  unsigned int v12; // ebx
  UFG::allocator::free_link *v13; // rax
  float v14; // xmm8_4
  __int64 v15; // rax
  __int64 v16; // rax
  float v17; // xmm1_4
  float v18; // xmm2_4
  __int64 v19; // rax
  float v20; // xmm3_4
  __int64 v21; // rax
  float v22; // xmm5_4
  __int64 v23; // rax
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rax
  __int64 v27; // rax
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // rax
  __int64 v31; // rax
  UFG::allocator::free_link *v32; // rax
  __int64 v33; // rax
  __int64 v34; // rax
  __int64 v35; // rax
  __int64 v36; // rax
  __int64 v37; // rax
  __int64 v38; // rax
  __int64 v39; // rax
  int v40; // er13
  unsigned __int64 v41; // rax
  UFG::allocator::free_link *v42; // rax
  float v43; // xmm9_4
  __int64 v44; // r14
  __int64 v45; // rdi
  float v46; // xmm6_4
  float v47; // xmm0_4
  __int64 v48; // rax
  signed __int64 v49; // rcx
  __int64 v50; // rax
  signed __int64 v51; // rdx
  __int64 v52; // rax
  _QWORD **v53; // rax
  hkpConvexVerticesShape *v54; // rax
  __int64 v55; // rax
  __int64 v56; // r14
  __int64 v57; // rsi
  unsigned int v58; // edi
  unsigned int v59; // eax
  hkStridedVertices stridedVertsIn; // [rsp+20h] [rbp-79h]
  hkArray<hkVector4f,hkContainerHeapAllocator> planeEquationsOut; // [rsp+30h] [rbp-69h]
  hkGeometry geometryOut; // [rsp+40h] [rbp-59h]
  __int64 v63; // [rsp+70h] [rbp-29h]
  hkGeometry *v64; // [rsp+F8h] [rbp+5Fh]
  void *retaddr; // [rsp+118h] [rbp+7Fh]

  stridedVertsIn.m_vertices = (const float *)-2i64;
  v4 = radius;
  v5 = model;
  v6 = this;
  v7 = 0;
  v8 = this->mCollisionShapeCache.size;
  if ( !this->mCollisionShapeCache.size )
    goto LABEL_10;
  v9 = this->mCollisionShapeCache.p;
  while ( 1 )
  {
    v10 = (signed __int64)&v9[v7];
    if ( *(_DWORD *)(v10 + 20) == v5
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(v10 + 4) - height) & _xmm) < 0.0099999998
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)v10 - radius) & _xmm) < 0.0099999998
      && *(_DWORD *)(v10 + 16) == (_DWORD)retaddr )
    {
      break;
    }
    if ( ++v7 >= v8 )
      goto LABEL_10;
  }
  result = *(hkpShape **)(v10 + 104);
  if ( !result )
  {
LABEL_10:
    stridedVertsIn.m_numVertices = 0;
    planeEquationsOut.m_size = 0;
    planeEquationsOut.m_capacityAndFlags = 2147483648;
    v64 = &geometryOut;
    *(_DWORD *)&geometryOut.m_memSizeAndFlags = 0x1FFFF;
    v12 = 1;
    geometryOut.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
    geometryOut.m_vertices.m_data = 0i64;
    geometryOut.m_vertices.m_size = 0;
    geometryOut.m_vertices.m_capacityAndFlags = 2147483648;
    geometryOut.m_triangles.m_data = 0i64;
    geometryOut.m_triangles.m_size = 0;
    geometryOut.m_triangles.m_capacityAndFlags = 2147483648;
    planeEquationsOut.m_data = (hkVector4f *)__PAIR__(LODWORD(height), LODWORD(radius));
    LODWORD(geometryOut.vfptr) = (_DWORD)retaddr;
    stridedVertsIn.m_striding = 12;
    switch ( v5 )
    {
      case 1:
        v40 = 2 * (_DWORD)retaddr + 2;
        v41 = 12i64 * v40;
        if ( !is_mul_ok(v40, 0xCui64) )
          v41 = -1i64;
        v42 = UFG::qMalloc(v41, "CharacterPhysicsVert_Cache", 0i64);
        v64 = (hkGeometry *)v42;
        *(_QWORD *)&planeEquationsOut.m_size = v42;
        stridedVertsIn.m_numVertices = 2 * (_DWORD)retaddr + 2;
        stridedVertsIn.m_vertices = (const float *)v42;
        v42->mNext = 0i64;
        *(float *)&v42[1].mNext = height - 0.050000001;
        v43 = 0.0;
        v44 = (signed int)retaddr;
        if ( (signed int)retaddr > 0 )
        {
          v45 = 0i64;
          do
          {
            v46 = sinf(v43) * radius;
            v47 = cosf(v43) * radius;
            v48 = *(_QWORD *)&planeEquationsOut.m_size;
            *(float *)(v45 + *(_QWORD *)&planeEquationsOut.m_size + 12) = v46;
            *(float *)(v45 + v48 + 16) = v47;
            *(float *)(v45 + v48 + 20) = height - radius;
            v49 = v45 + 12i64 * (signed int)retaddr;
            v50 = *(_QWORD *)&planeEquationsOut.m_size;
            *(float *)(v49 + *(_QWORD *)&planeEquationsOut.m_size + 12) = v46;
            *(float *)(v49 + v50 + 16) = v47;
            *(float *)(v49 + v50 + 20) = radius;
            v43 = v43 + (float)(6.2831855 / (float)(signed int)retaddr);
            v45 += 12i64;
            --v44;
          }
          while ( v44 );
        }
        v51 = 3i64 * (2 * (signed int)retaddr + 1);
        v52 = *(_QWORD *)&planeEquationsOut.m_size;
        *(_QWORD *)(*(_QWORD *)&planeEquationsOut.m_size + 4 * v51) = 0i64;
        *(_DWORD *)(v52 + 4 * v51 + 8) = 1028443341;
        goto LABEL_30;
      case 2:
      case 4:
      case 5:
      case 7:
      case 8:
      case 10:
      case 11:
      case 12:
      case 13:
        v13 = UFG::qMalloc(0xA8ui64, "CharacterPhysicsVert_Cache", 0i64);
        v64 = (hkGeometry *)v13;
        *(_QWORD *)&planeEquationsOut.m_size = v13;
        stridedVertsIn.m_numVertices = 14;
        stridedVertsIn.m_vertices = (const float *)v13;
        v13->mNext = 0i64;
        *(float *)&v13[1].mNext = height - 0.050000001;
        v14 = height - radius;
        v15 = *(_QWORD *)&planeEquationsOut.m_size;
        *(_DWORD *)(*(_QWORD *)&planeEquationsOut.m_size + 12i64) = 0;
        *(float *)(v15 + 16) = radius;
        *(float *)(v15 + 20) = height - radius;
        v16 = *(_QWORD *)&planeEquationsOut.m_size;
        v17 = radius * 0.866;
        v18 = radius * 0.5;
        *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 32i64) = v14;
        *(float *)(v16 + 28) = radius * 0.5;
        if ( v5 == 10 )
        {
          *(float *)(v16 + 24) = v17 + 0.80000001;
          v19 = *(_QWORD *)&planeEquationsOut.m_size;
          *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 36i64) = v17 + 0.80000001;
        }
        else if ( v5 == 11 )
        {
          *(float *)(v16 + 24) = v17 + 0.40000001;
          v19 = *(_QWORD *)&planeEquationsOut.m_size;
          *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 36i64) = v17 + 0.40000001;
        }
        else
        {
          *(float *)(v16 + 24) = v17;
          v19 = *(_QWORD *)&planeEquationsOut.m_size;
          *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 36i64) = v17;
        }
        *(float *)(v19 + 44) = v14;
        v20 = radius * -0.5;
        *(float *)(v19 + 40) = v4 * -0.5;
        v21 = *(_QWORD *)&planeEquationsOut.m_size;
        *(_DWORD *)(*(_QWORD *)&planeEquationsOut.m_size + 48i64) = 0;
        *(_DWORD *)(v21 + 52) = LODWORD(v4) ^ _xmm[0];
        *(float *)(v21 + 56) = v14;
        v22 = v4 * -0.866;
        v23 = *(_QWORD *)&planeEquationsOut.m_size;
        *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 60i64) = v4 * -0.866;
        *(float *)(v23 + 64) = v4 * -0.5;
        *(float *)(v23 + 68) = v14;
        v24 = *(_QWORD *)&planeEquationsOut.m_size;
        *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 72i64) = v4 * -0.866;
        *(float *)(v24 + 76) = v18;
        *(float *)(v24 + 80) = v14;
        v25 = *(_QWORD *)&planeEquationsOut.m_size;
        *(_DWORD *)(*(_QWORD *)&planeEquationsOut.m_size + 84i64) = 0;
        *(float *)(v25 + 88) = v4;
        *(float *)(v25 + 92) = v4;
        v26 = *(_QWORD *)&planeEquationsOut.m_size;
        *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 100i64) = v18;
        if ( v5 == 10 )
        {
          v17 = v17 + 0.80000001;
        }
        else
        {
          if ( v5 != 11 )
          {
            *(float *)(v26 + 96) = v17;
            *(float *)(v26 + 104) = v4;
            v27 = *(_QWORD *)&planeEquationsOut.m_size;
            *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 116i64) = v4;
            goto LABEL_22;
          }
          v17 = v17 + 0.40000001;
        }
        *(float *)(v26 + 96) = v17;
        *(float *)(v26 + 104) = v4 + 0.5;
        v27 = *(_QWORD *)&planeEquationsOut.m_size;
        *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 116i64) = v4 + 0.5;
LABEL_22:
        *(float *)(v27 + 112) = v20;
        *(float *)(v27 + 108) = v17;
        v28 = *(_QWORD *)&planeEquationsOut.m_size;
        *(_DWORD *)(*(_QWORD *)&planeEquationsOut.m_size + 120i64) = 0;
        *(_DWORD *)(v28 + 124) = LODWORD(v4) ^ _xmm[0];
        *(float *)(v28 + 128) = v4;
        v29 = *(_QWORD *)&planeEquationsOut.m_size;
        *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 132i64) = v22;
        *(float *)(v29 + 136) = v20;
        *(float *)(v29 + 140) = v4;
        v30 = *(_QWORD *)&planeEquationsOut.m_size;
        *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 144i64) = v22;
        *(float *)(v30 + 148) = v18;
        *(float *)(v30 + 152) = v4;
        v31 = *(_QWORD *)&planeEquationsOut.m_size;
        *(_QWORD *)(*(_QWORD *)&planeEquationsOut.m_size + 156i64) = 0i64;
        *(_DWORD *)(v31 + 164) = 1028443341;
LABEL_30:
        hkGeometryUtility::createConvexGeometry(&stridedVertsIn, &geometryOut, &planeEquationsOut);
        stridedVertsIn.m_numVertices = geometryOut.m_vertices.m_size;
        stridedVertsIn.m_striding = 16;
        stridedVertsIn.m_vertices = geometryOut.m_vertices.m_data->m_quad.m128_f32;
        v53 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v54 = (hkpConvexVerticesShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v53[11] + 8i64))(
                                          v53[11],
                                          128i64);
        v64 = (hkGeometry *)v54;
        if ( v54 )
        {
          hkpConvexVerticesShape::hkpConvexVerticesShape(v54, &stridedVertsIn, &planeEquationsOut, 0.050000001);
          v56 = v55;
        }
        else
        {
          v56 = 0i64;
        }
        v63 = v56;
        v57 = v6->mCollisionShapeCache.size;
        v58 = v57 + 1;
        v59 = v6->mCollisionShapeCache.capacity;
        if ( (signed int)v57 + 1 > v59 )
        {
          if ( v59 )
            v12 = 2 * v59;
          for ( ; v12 < v58; v12 *= 2 )
            ;
          if ( v12 - v58 > 0x10000 )
            v12 = v57 + 65537;
          UFG::qArray<UFG::CharacterPhysicsComponentManager::ShapeCacheEntry,0>::Reallocate(
            &v6->mCollisionShapeCache,
            v12,
            "qArray.Add");
        }
        v6->mCollisionShapeCache.size = v58;
        UFG::CharacterPhysicsComponentManager::ShapeCacheEntry::operator=(
          &v6->mCollisionShapeCache.p[v57],
          (UFG::CharacterPhysicsComponentManager::ShapeCacheEntry *)&planeEquationsOut);
        hkGeometry::~hkGeometry(&geometryOut);
        planeEquationsOut.m_size = 0;
        if ( planeEquationsOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            planeEquationsOut.m_data,
            16 * planeEquationsOut.m_capacityAndFlags);
        return (hkpShape *)v56;
      case 3:
      case 6:
      case 9:
        v32 = UFG::qMalloc(0x60ui64, "CharacterPhysicsVert_Cache", 0i64);
        v64 = (hkGeometry *)v32;
        *(_QWORD *)&planeEquationsOut.m_size = v32;
        stridedVertsIn.m_numVertices = 8;
        stridedVertsIn.m_vertices = (const float *)v32;
        v32->mNext = 0i64;
        *(float *)&v32[1].mNext = height - 0.050000001;
        v33 = *(_QWORD *)&planeEquationsOut.m_size;
        *(_DWORD *)(*(_QWORD *)&planeEquationsOut.m_size + 12i64) = 0;
        *(float *)(v33 + 16) = radius;
        *(float *)(v33 + 20) = height * 0.5;
        v34 = *(_QWORD *)&planeEquationsOut.m_size;
        *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 24i64) = radius * 0.866;
        *(float *)(v34 + 28) = radius * 0.5;
        *(float *)(v34 + 32) = height * 0.5;
        v35 = *(_QWORD *)&planeEquationsOut.m_size;
        *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 36i64) = radius * 0.866;
        *(float *)(v35 + 40) = radius * -0.5;
        *(float *)(v35 + 44) = height * 0.5;
        v36 = *(_QWORD *)&planeEquationsOut.m_size;
        *(_DWORD *)(*(_QWORD *)&planeEquationsOut.m_size + 48i64) = 0;
        *(_DWORD *)(v36 + 52) = LODWORD(radius) ^ _xmm[0];
        *(float *)(v36 + 56) = height * 0.5;
        v37 = *(_QWORD *)&planeEquationsOut.m_size;
        *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 60i64) = radius * -0.866;
        *(float *)(v37 + 64) = radius * -0.5;
        *(float *)(v37 + 68) = height * 0.5;
        v38 = *(_QWORD *)&planeEquationsOut.m_size;
        *(float *)(*(_QWORD *)&planeEquationsOut.m_size + 72i64) = radius * -0.866;
        *(float *)(v38 + 76) = radius * 0.5;
        *(float *)(v38 + 80) = height * 0.5;
        v39 = *(_QWORD *)&planeEquationsOut.m_size;
        *(_QWORD *)(*(_QWORD *)&planeEquationsOut.m_size + 84i64) = 0i64;
        *(_DWORD *)(v39 + 92) = 1028443341;
        goto LABEL_30;
      default:
        goto LABEL_30;
    }
  }
  return result;
}

// File Line: 2325
// RVA: 0x4664D0
void __fastcall UFG::CharacterPhysicsComponentManager::GetEntitiesForBatchOperations(UFG::CharacterPhysicsComponentManager *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesToAdd, hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesToRemove)
{
  UFG::BasePhysicsSystem *v3; // r14
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v4; // rcx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v5; // rbx
  hkpRigidBody *v6; // rdi
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v7; // rsi

  v3 = UFG::BasePhysicsSystem::mInstance;
  v4 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext;
  v5 = entitiesToAdd;
  if ( &UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext != (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> **)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList - 104) )
  {
    do
    {
      v6 = (hkpRigidBody *)v4[27].mNode.mPrev[2].mPrev;
      v7 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&v4[7].mNode.mPrev[-7].mNext;
      if ( (LOBYTE(v4[2].mNode.mPrev) >> 1) & 1 )
      {
        if ( v6->m_world )
          UFG::BasePhysicsSystem::RemoveEntity(v3, v6, 1);
      }
      else if ( !v6->m_world )
      {
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
        v5->m_data[v5->m_size++] = (hkpEntity *)&v6->vfptr;
      }
      v4 = v7;
    }
    while ( v7 != (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList
                                                                                                  - 104) );
  }
}

// File Line: 2353
// RVA: 0x473960
void __fastcall UFG::CharacterPhysicsComponentManager::ResetScene(UFG::CharacterPhysicsComponentManager *this)
{
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v1; // rsi
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v2; // rbx
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v3; // rdi
  UFG::RippleGenerator *v4; // rcx
  hkpAction *v5; // rdx
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v6; // rcx

  v1 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext;
  if ( &UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext != (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> **)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList - 104) )
  {
    do
    {
      v2 = v1[11].mNode.mNext;
      v3 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&v1[7].mNode.mPrev[-7].mNext;
      if ( v2 && SLODWORD(v2[7].mNext) > 0 )
      {
        v4 = (UFG::RippleGenerator *)v2[6].mNext;
        if ( v4 )
        {
          UFG::Water::RemoveRippleGenerator(v4);
          v2[6].mNext = 0i64;
        }
        v5 = (hkpAction *)v2[9].mPrev;
        if ( v5 )
        {
          UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, v5);
          v6 = v2[9].mPrev;
          if ( v6 )
            ((void (__fastcall *)(UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *, signed __int64))v6->mPrev->mPrev)(
              v6,
              1i64);
          v2[9].mPrev = 0i64;
        }
        LODWORD(v2[7].mNext) = 0;
        UFG::GameStatAction::Character::ExitWater((UFG::SimObject *)v1[2].mNode.mNext);
      }
      v1 = v3;
    }
    while ( v3 != (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList
                                                                                                  - 104) );
  }
}

