// File Line: 81
// RVA: 0x15142F0
__int64 dynamic_initializer_for__UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList__);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CharacterPhysicsComponent::mAllocator__);
}

// File Line: 140
// RVA: 0x448B40
void __fastcall UFG::CharacterCollisionListener::CharacterCollisionListener(
        UFG::CharacterCollisionListener *this,
        UFG::CharacterPhysicsComponent *charPhysComp)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterPhysicsComponent> *p_mCharacterPhysicsComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  this->vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
  this->vfptr = (hkpContactListenerVtbl *)&UFG::CharacterCollisionListener::`vftable;
  p_mCharacterPhysicsComponent = &this->mCharacterPhysicsComponent;
  this->mCharacterPhysicsComponent.mPrev = &this->mCharacterPhysicsComponent;
  this->mCharacterPhysicsComponent.mNext = &this->mCharacterPhysicsComponent;
  this->mCharacterPhysicsComponent.m_pPointer = 0i64;
  if ( this->mCharacterPhysicsComponent.m_pPointer )
  {
    mPrev = p_mCharacterPhysicsComponent->mPrev;
    mNext = p_mCharacterPhysicsComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCharacterPhysicsComponent->mPrev = p_mCharacterPhysicsComponent;
    p_mCharacterPhysicsComponent->mNext = p_mCharacterPhysicsComponent;
  }
  p_mCharacterPhysicsComponent->m_pPointer = charPhysComp;
  if ( charPhysComp )
  {
    v5 = charPhysComp->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v5->mNext = p_mCharacterPhysicsComponent;
    p_mCharacterPhysicsComponent->mPrev = v5;
    p_mCharacterPhysicsComponent->mNext = &charPhysComp->m_SafePointerList.mNode;
    charPhysComp->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mCharacterPhysicsComponent;
  }
}

// File Line: 150
// RVA: 0x486950
void __fastcall UFG::CharacterCollisionListener::contactPointCallback(
        UFG::CharacterCollisionListener *this,
        hkpContactPointEvent *event)
{
  hkContactPoint *cp; // r10
  float v5; // xmm7_4
  float v6; // xmm8_4
  float *m_separatingVelocity; // rax
  __m128 m_real; // xmm6
  __m128 m_quad; // xmm0
  UFG::SimComponent *m_pPointer; // rax
  __m128 v11; // xmm1
  float v12; // xmm2_4
  hkVector4f direction; // [rsp+30h] [rbp-68h] BYREF
  hkVector4f v14; // [rsp+40h] [rbp-58h] BYREF
  hkSimdFloat32 result; // [rsp+50h] [rbp-48h] BYREF

  if ( UFG::enableCurbClipping )
  {
    cp = event->m_contactPoint;
    v5 = cp->m_position.m_quad.m128_f32[2];
    v6 = *(float *)&this->mCharacterPhysicsComponent.m_pPointer[5].m_Flags;
    m_separatingVelocity = event->m_separatingVelocity;
    if ( m_separatingVelocity )
      m_real.m128_f32[0] = *m_separatingVelocity;
    else
      m_real = hkpSimpleContactConstraintUtil::calculateSeparatingVelocity(
                 &result,
                 event->m_bodies[0],
                 event->m_bodies[1],
                 &event->m_bodies[0]->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1,
                 &event->m_bodies[1]->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1,
                 cp)->m_real;
    m_quad = event->m_contactPoint->m_separatingNormal.m_quad;
    m_pPointer = this->mCharacterPhysicsComponent.m_pPointer;
    direction.m_quad = (__m128)_xmm;
    result.m_real = m_quad;
    hkVector4f::setRotatedDir(
      &v14,
      (hkQuaternionf *)&m_pPointer[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev[30],
      &direction);
    v11 = _mm_mul_ps(event->m_contactPoint->m_separatingNormal.m_quad, v14.m_quad);
    v12 = (float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
        + _mm_shuffle_ps(v11, v11, 170).m128_f32[0];
    if ( (float)(v5 - v6) < 0.25
      && COERCE_FLOAT(m_real.m128_i32[0] & _xmm) > 0.0099999998
      && result.m_real.m128_f32[2] < 0.70700002
      && v12 > 0.0 )
    {
      result.m_real = _xmm;
      hkpContactPointEvent::setNormal(event, (hkVector4f *)&result);
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
    (char *)UFG::CharacterPhysicsComponent::mAllocatorBuffer,
    231040,
    608,
    "CharacterPhysicsPool");
}

// File Line: 247
// RVA: 0x448BD0
void __fastcall UFG::CharacterPhysicsComponent::CharacterPhysicsComponent(
        UFG::CharacterPhysicsComponent *this,
        UFG::qVector4 *pos,
        unsigned int name_uid,
        component_CharacterPhysics *data)
{
  int v6; // edi
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v7; // rsi
  __int64 i; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *mPrev; // rax
  UFG::CharacterPhysicsComponentManager *v14; // r13
  int v15; // esi
  hkpShape **v16; // r15
  float *v17; // r14
  float *v18; // r12
  _QWORD **Value; // rax
  hkpListShape *v20; // rax
  hkpListShape *v21; // rax
  hkpListShape *v22; // r14
  _QWORD **v23; // rax
  CharacterRigidBody *v24; // rax
  CharacterRigidBody *v25; // rax
  __m128 v26; // xmm0
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v27; // rcx
  const char *TypeName; // rax
  UFG::allocator::free_link *v29; // rax
  UFG::CharacterCollisionListener *v30; // rax
  UFG::CharacterCollisionListener *v31; // rdx
  unsigned __int16 m_Flags; // cx
  int v33; // r8d
  int v34; // eax
  int *mAsyncRaycastBucketCounts; // rcx
  UFG::SimComponent *m_pPointer; // rcx
  hkpCharacterRigidBodyCinfo info; // [rsp+30h] [rbp-79h] BYREF
  __int64 v38; // [rsp+B0h] [rbp+7h]
  UFG::HavokUserData *p_mUserData; // [rsp+B8h] [rbp+Fh]
  unsigned int *v40; // [rsp+110h] [rbp+67h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mGrapplePartner; // [rsp+120h] [rbp+77h]
  int v42; // [rsp+128h] [rbp+7Fh]

  v38 = -2i64;
  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  p_mUserData = &this->mUserData;
  this->mUserData.isBoat = 0;
  *(_QWORD *)&info.m_maxLinearVelocity = &this->mUserData.simComponent;
  this->mUserData.simComponent.mPrev = &this->mUserData.simComponent;
  this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  v6 = 0;
  this->mUserData.simComponent.m_pPointer = 0i64;
  v7 = &this->UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent>;
  this->mPrev = &this->UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent>;
  this->mNext = &this->UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterPhysicsComponent::`vftable{for `UFG::SimComponent};
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::CharacterPhysicsComponent::`vftable{for `UFG::BasePhysicsObject};
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::RebindingComponentHandle<UFG::RagdollComponent,0>(&this->mRagdollComponent);
  this->mWaterTracker.mPrev = &this->mWaterTracker;
  this->mWaterTracker.mNext = &this->mWaterTracker;
  this->mWaterTracker.m_pPointer = 0i64;
  p_mGrapplePartner = &this->mGrapplePartner;
  this->mGrapplePartner.mPrev = &this->mGrapplePartner;
  this->mGrapplePartner.mNext = &this->mGrapplePartner;
  this->mGrapplePartner.m_pPointer = 0i64;
  this->mParam.mMass = 75.0;
  this->mParam.mMaxClimableSlope = 50.0;
  this->mParam.mMaxForce = 1000.0;
  for ( i = 0i64; i < 14; ++i )
  {
    this->mParam.mCollisionHeight[i] = 1.3;
    this->mParam.mCollisionRadius[i] = 0.30000001;
  }
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mGroundProperties.groundPosition.x = UFG::qVector3::msZero.x;
  this->mGroundProperties.groundPosition.y = y;
  this->mGroundProperties.groundPosition.z = z;
  *(_QWORD *)&this->mGroundProperties.groundNormal.x = 0i64;
  *(_QWORD *)&this->mGroundProperties.groundNormal.z = 0x3F800000i64;
  *(_QWORD *)&this->mGroundProperties.maxOffGroundElevation = 0i64;
  *(_QWORD *)&this->mGroundProperties.latchedFallDistance = 0i64;
  this->mGroundProperties.groundObjectHandleUid = 0i64;
  this->mGroundProperties.groundSurfaceHandleUid = 0i64;
  this->mGroundProperties.support = SUPPORTED;
  *((_DWORD *)&this->mGroundProperties + 17) = *((_DWORD *)&this->mGroundProperties + 17) & 0xFFFFFFF0 | 7;
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  this->mAdditiveVelocity.x = UFG::qVector3::msZero.x;
  this->mAdditiveVelocity.y = v11;
  this->mAdditiveVelocity.z = v12;
  this->mCharacterListener = 0i64;
  this->mCollisionModelType = CP_INVALID;
  this->mDesiredCollisionModelType = CP_WALK;
  this->mSpeedZ = 0.0;
  this->mGravity = -9.8100004;
  *(_QWORD *)&this->mHeightFixup = 0i64;
  this->mAsyncRaycastBucket = -1;
  this->mGrappleState = 0;
  *((_DWORD *)this + 0x97) = *((_DWORD *)this + 151) & 0xFFFFFE00 | ((v42 & 1) << 7);
  mPrev = UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mPrev;
  UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mPrev->mNext = v7;
  v7->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList;
  UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mPrev = &this->UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::CharacterPhysicsComponent::_CharacterPhysicsComponentTypeUID,
    "CharacterPhysicsComponent");
  if ( data )
    UFG::CharacterPhysicsComponent::PropertiesLoad(this, data);
  this->mCollisionSystem = UFG::CustomCollisionFilter::GetUnusedSystemId(UFG::BasePhysicsSystem::mInstance->mCollisionFilter);
  v14 = UFG::CharacterPhysicsComponentManager::mInstance;
  v15 = 1;
  v16 = &this->mCollisionShapes[1];
  v17 = &this->mParam.mCollisionHeight[1];
  v18 = &this->mParam.mCollisionHeight[1];
  do
  {
    if ( v15 == 8 )
    {
      *(_QWORD *)&info.m_maxLinearVelocity = UFG::CharacterPhysicsComponentManager::GetShape(
                                               v14,
                                               CP_WALK,
                                               *v17,
                                               this->mParam.mCollisionRadius[1]);
      info.m_up.m_quad.m128_u64[0] = (unsigned __int64)UFG::CharacterPhysicsComponentManager::GetShape(
                                                         v14,
                                                         CP_COMBAT,
                                                         this->mParam.mCollisionHeight[8],
                                                         this->mParam.mCollisionRadius[8]);
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v20 = (hkpListShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
      p_mGrapplePartner = (UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *)v20;
      if ( v20 )
      {
        hkpListShape::hkpListShape(v20, (hkpShape *const *)&info.m_maxLinearVelocity, 2, REFERENCE_POLICY_INCREMENT);
        v22 = v21;
      }
      else
      {
        v22 = 0i64;
      }
      hkpListShape::setCollisionFilterInfo(v22, 0, 2u);
      hkpListShape::setCollisionFilterInfo(v22, 1u, 3u);
      *v16 = v22;
      v17 = &this->mParam.mCollisionHeight[1];
    }
    else
    {
      *v16 = UFG::CharacterPhysicsComponentManager::GetShape(v14, (UFG::CharacterCollisionMode)v15, *v18, v18[14]);
    }
    ++v15;
    ++v18;
    ++v16;
  }
  while ( v15 < 14 );
  info.vfptr = (hkBaseObjectVtbl *)&hkpCharacterRigidBodyCinfo::`vftable;
  *(float *)&info.m_memSizeAndFlags = FLOAT_100_0;
  *(_DWORD *)(&info.m_referenceCount + 1) = 0;
  *(&info.m_collisionFilterInfo + 1) = 0xBDCCCCCD;
  info.m_collisionFilterInfo = 0;
  info.m_rotation.m_vec.m_quad.m128_u64[1] = LODWORD(FLOAT_0_1);
  info.m_mass = -4.319868e-19;
  memset(&info.m_shape, 0, 28);
  *(float *)&info.m_memSizeAndFlags = this->mParam.mMass;
  *(_DWORD *)(&info.m_referenceCount + 1) = 0;
  info.m_shape = this->mCollisionShapes[1];
  *(float *)&info.m_collisionFilterInfo = FLOAT_50_0;
  *(&info.m_collisionFilterInfo + 1) = 0xBDCCCCCD;
  *(unsigned __int64 *)((char *)info.m_rotation.m_vec.m_quad.m128_u64 + 4) = __PAIR64__(
                                                                               LODWORD(FLOAT_0_050000001),
                                                                               (unsigned int)FLOAT_1_0);
  info.m_position.m_quad.m128_i32[3] = LODWORD(this->mParam.mMaxForce);
  *(__m128 *)&info.m_shape = _xmm;
  info.m_position.m_quad = _mm_unpacklo_ps(
                             _mm_unpacklo_ps((__m128)*v40, (__m128)v40[2]),
                             _mm_unpacklo_ps((__m128)v40[1], (__m128)v40[3]));
  info.m_position.m_quad.m128_i32[2] = LODWORD(this->mParam.mMaxClimableSlope);
  info.m_collisionFilterInfo = 1;
  v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (CharacterRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v23[11] + 8i64))(v23[11], 192i64);
  v40 = (unsigned int *)v24;
  if ( v24 )
    CharacterRigidBody::CharacterRigidBody(v24, &info);
  else
    v25 = 0i64;
  this->mHavokCharacter = v25;
  hkStringPtr::operator=(&v25->m_character->m_name, "CharacterCapsule");
  this->mHavokCharacter->mBottomVertex = (hkVector4f)_xmm;
  v26 = (__m128)*(unsigned int *)v17;
  v26.m128_f32[0] = v26.m128_f32[0] - 0.050000001;
  this->mHavokCharacter->mTopVertex.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v26), _xmm);
  this->mHavokCharacter->m_isPlayer = (*((_DWORD *)this + 151) & 0x80) != 0;
  if ( (_S13_3 & 1) == 0 )
  {
    _S13_3 |= 1u;
    propertyUID = UFG::qStringHashUpper32("CharacterCapsule", -1);
  }
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&info.m_up.m_quad.m128_u16[4]);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v27);
  *(_QWORD *)&info.m_unweldingHeightOffsetFactor = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::PhysicsPropertyManager::GetObjectProperties(
    (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&info.m_up.m_quad.m128_u16[4],
    propertyUID,
    0);
  UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
    *(hkSimplePropertyValue *)(*(_QWORD *)&info.m_vdbColor + 8i64),
    this->mHavokCharacter->m_character);
  if ( *((char *)this + 604) < 0 )
  {
    v29 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
    v40 = (unsigned int *)v29;
    if ( v29 )
    {
      UFG::CharacterCollisionListener::CharacterCollisionListener((UFG::CharacterCollisionListener *)v29, this);
      v31 = v30;
    }
    else
    {
      v31 = 0i64;
    }
    this->mCharacterListener = v31;
    hkpEntity::addContactListener(this->mHavokCharacter->m_character, v31);
    this->mHavokCharacter->m_character->m_contactPointCallbackDelay = 0;
  }
  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) != 0 )
  {
    this->m_Flags = m_Flags & 0xFFFD;
    v33 = 0x7FFFFFFF;
    v34 = 0;
    mAsyncRaycastBucketCounts = UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts;
    do
    {
      if ( *mAsyncRaycastBucketCounts <= v33 )
      {
        v33 = *mAsyncRaycastBucketCounts;
        v6 = v34;
      }
      ++v34;
      ++mAsyncRaycastBucketCounts;
    }
    while ( v34 < 12 );
    ++UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts[v6];
    this->mAsyncRaycastBucket = v6;
  }
  m_pPointer = this->mWaterTracker.m_pPointer;
  if ( m_pPointer )
    ((void (__fastcall *)(UFG::SimComponent *))m_pPointer->vfptr[9].__vecDelDtor)(m_pPointer);
  this->mHavokCharacter->mSupportRadius = 0.050000001;
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&info.m_up.m_quad.m128_u16[4]);
}

// File Line: 341
// RVA: 0x44F9B0
void __fastcall UFG::CharacterPhysicsComponent::~CharacterPhysicsComponent(UFG::CharacterPhysicsComponent *this)
{
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v2; // rdi
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *mPrev; // rcx
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *mNext; // rax
  UFG::SimComponent *m_pPointer; // rax
  hkpRigidBody *m_character; // rsi
  UFG::CharacterCollisionListener *mCharacterListener; // rdx
  UFG::CharacterCollisionListener *v8; // rcx
  UFG::BasePhysicsSystem *v9; // rbp
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mGrapplePartner; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::WaterFloatingTrackerComponent> *p_mWaterTracker; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v20; // rdx
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v21; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterPhysicsComponent::`vftable{for `UFG::SimComponent};
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::CharacterPhysicsComponent::`vftable{for `UFG::BasePhysicsObject};
  if ( this == UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentpCurrentIterator )
    UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentpCurrentIterator = (UFG::CharacterPhysicsComponent *)&this->mPrev[-7].mNext;
  v2 = &this->UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  m_pPointer = this->mWaterTracker.m_pPointer;
  if ( m_pPointer && SLODWORD(m_pPointer[1].m_BoundComponentHandles.mNode.mNext) > 0 )
    UFG::GameStatAction::Character::ExitWater(this->m_pSimObject);
  m_character = this->mHavokCharacter->m_character;
  m_character->m_userData = 0i64;
  mCharacterListener = this->mCharacterListener;
  if ( mCharacterListener )
  {
    hkpEntity::removeContactListener(m_character, mCharacterListener);
    v8 = this->mCharacterListener;
    if ( v8 )
      ((void (__fastcall *)(UFG::CharacterCollisionListener *, __int64))v8->vfptr->~hkpContactListener)(v8, 1i64);
  }
  v9 = UFG::BasePhysicsSystem::mInstance;
  UFG::CustomCollisionFilter::ReenableCollisions(UFG::BasePhysicsSystem::mInstance->mCollisionFilter, m_character);
  if ( m_character->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(v9, m_character, 1);
  hkReferencedObject::removeReference(this->mHavokCharacter);
  hkReferencedObject::removeReference(this->mCollisionShapes[8]);
  if ( this->mAsyncRaycastBucket != -1 )
    --UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts[this->mAsyncRaycastBucket];
  UFG::CustomCollisionFilter::ReleaseSystemId(v9->mCollisionFilter, this->mCollisionSystem);
  p_mGrapplePartner = &this->mGrapplePartner;
  if ( this->mGrapplePartner.m_pPointer )
  {
    v11 = p_mGrapplePartner->mPrev;
    v12 = this->mGrapplePartner.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_mGrapplePartner->mPrev = p_mGrapplePartner;
    this->mGrapplePartner.mNext = &this->mGrapplePartner;
  }
  this->mGrapplePartner.m_pPointer = 0i64;
  v13 = p_mGrapplePartner->mPrev;
  v14 = this->mGrapplePartner.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_mGrapplePartner->mPrev = p_mGrapplePartner;
  this->mGrapplePartner.mNext = &this->mGrapplePartner;
  p_mWaterTracker = &this->mWaterTracker;
  if ( this->mWaterTracker.m_pPointer )
  {
    v16 = p_mWaterTracker->mPrev;
    v17 = this->mWaterTracker.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    p_mWaterTracker->mPrev = p_mWaterTracker;
    this->mWaterTracker.mNext = &this->mWaterTracker;
  }
  this->mWaterTracker.m_pPointer = 0i64;
  v18 = p_mWaterTracker->mPrev;
  v19 = this->mWaterTracker.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  p_mWaterTracker->mPrev = p_mWaterTracker;
  this->mWaterTracker.mNext = &this->mWaterTracker;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mRagdollComponent);
  v20 = v2->mPrev;
  v21 = v2->mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BasePhysicsObject::~BasePhysicsObject(&this->UFG::BasePhysicsObject);
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 392
// RVA: 0x470990
void __fastcall UFG::CharacterPhysicsComponent::PropertiesLoad(
        UFG::CharacterPhysicsComponent *this,
        component_CharacterPhysics *data)
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
  *((_DWORD *)this + 151) ^= (*((_DWORD *)this + 151) ^ (2 * data->DetailedOnGroundCheck)) & 2;
}

// File Line: 434
// RVA: 0x45A580
// attributes: thunk
void __fastcall UFG::CharacterPhysicsComponent_OnEnterWater(UFG::CharacterPhysicsComponent *cxt)
{
  UFG::CharacterPhysicsComponent::OnEnterWater(cxt);
}

// File Line: 442
// RVA: 0x45A590
void __fastcall UFG::CharacterPhysicsComponent_OnExitWater(UFG::SimObject **cxt)
{
  UFG::GameStatAction::Character::ExitWater(cxt[5]);
}

// File Line: 449
// RVA: 0x470CD0
UFG::CharacterPhysicsComponent *__fastcall UFG::CharacterPhysicsComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  __int64 v4; // rdi
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v6; // rax
  char *MemImagePtr; // r14
  UFG::SimObject *m_pSimObject; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  char *mFreeListHead; // rbx
  unsigned int v14; // eax
  __int64 v15; // rax
  unsigned int v16; // ebx
  UFG::WaterFloatingTrackerBaseComponent *v17; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  _QWORD *v22; // rax
  __int64 *v23; // rcx
  __int64 v24; // rax
  UFG::SimObjectModifier pos[2]; // [rsp+40h] [rbp-58h] BYREF
  char *v26; // [rsp+A0h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+A8h] [rbp+10h] BYREF
  UFG::qSymbol v28; // [rsp+B0h] [rbp+18h] BYREF
  UFG::qSymbol v29; // [rsp+B8h] [rbp+20h] BYREF

  v4 = 0i64;
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_CharacterPhysics::sPropertyName,
         DEPTH_RECURSE);
  if ( v6 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v6);
  else
    MemImagePtr = 0i64;
  if ( !required && !MemImagePtr )
    return 0i64;
  m_pSimObject = pSceneObj->m_pSimObject;
  m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  *(float *)&pos[0].mbOpen = m_pTransformNodeComponent->mWorldTransform.v3.x;
  *(float *)(&pos[0].mbBroadcastChange + 3) = y;
  pos[0].mptrSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)__PAIR64__((unsigned int)FLOAT_1_0, LODWORD(z));
  if ( m_pSimObject->m_Name.mUID != UFG::qSymbol::create_from_string(&result, "PlayerOne_Havok")->mUID
    && m_pSimObject->m_Name.mUID != UFG::qSymbol::create_from_string((UFG::qSymbol *)&v26, "PlayerTwo_Havok")->mUID
    && m_pSimObject->m_Name.mUID != UFG::qSymbol::create_from_string(&v28, "PlayerThree_Havok")->mUID )
  {
    UFG::qSymbol::create_from_string(&v29, "PlayerFour_Havok");
  }
  mFreeListHead = UFG::CharacterPhysicsComponent::mAllocator.mFreeListHead;
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
  v26 = mFreeListHead;
  if ( mFreeListHead )
  {
    UFG::CharacterPhysicsComponent::CharacterPhysicsComponent(
      (UFG::CharacterPhysicsComponent *)mFreeListHead,
      (UFG::qVector4 *)pos,
      pSceneObj->m_NameUID,
      (component_CharacterPhysics *)MemImagePtr);
    v4 = v15;
  }
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v16 = 27;
  else
    v16 = -1;
  UFG::SimObjectModifier::SimObjectModifier(pos, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(pos, (UFG::SimComponent *)v4, v16);
  UFG::SimObjectModifier::Close(pos);
  UFG::SimObjectModifier::~SimObjectModifier(pos);
  v17 = UFG::AquireWaterFloatingTrackerComponent(m_pSimObject, *(hkpRigidBody **)(*(_QWORD *)(v4 + 432) + 32i64));
  if ( UFG::SimComponent::IsType(v17, UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID) )
  {
    v18 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v4 + 168);
    if ( *(_QWORD *)(v4 + 184) )
    {
      mPrev = v18->mPrev;
      v20 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v4 + 176);
      mPrev->mNext = v20;
      v20->mPrev = mPrev;
      v18->mPrev = v18;
      *(_QWORD *)(v4 + 176) = v4 + 168;
    }
    *(_QWORD *)(v4 + 184) = v17;
    if ( v17 )
    {
      v21 = v17->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v21->mNext = v18;
      v18->mPrev = v21;
      *(_QWORD *)(v4 + 176) = &v17->m_SafePointerList;
      v17->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v18;
    }
    v22 = *(_QWORD **)(v4 + 184);
    v22[20] = UFG::CharacterPhysicsComponent_OnEnterWater;
    v22[21] = UFG::CharacterPhysicsComponent_OnExitWater;
    v22[22] = v4;
    v23 = *(__int64 **)(v4 + 184);
    v24 = *v23;
    if ( (*(_BYTE *)(v4 + 32) & 2) != 0 )
      (*(void (__fastcall **)(__int64 *))(v24 + 64))(v23);
    else
      (*(void (__fastcall **)(__int64 *))(v24 + 72))(v23);
  }
  return (UFG::CharacterPhysicsComponent *)v4;
}

// File Line: 513
// RVA: 0x46DE90
void __fastcall UFG::CharacterPhysicsComponent::OnAttach(
        UFG::CharacterPhysicsComponent *this,
        UFG::SimObjectCharacter *object)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  CharacterRigidBody *mHavokCharacter; // rcx
  hkVector4f position; // [rsp+20h] [rbp-18h] BYREF

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
  if ( this )
  {
    v7 = this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    p_m_SafePointerList = &this->m_SafePointerList;
    v7->mNext = p_simComponent;
    p_simComponent->mPrev = v7;
    p_simComponent->mNext = &p_m_SafePointerList->mNode;
    p_m_SafePointerList->mNode.mPrev = p_simComponent;
  }
  this->mHavokCharacter->m_character->m_userData = (unsigned __int64)&this->mUserData;
  if ( object )
    m_pTransformNodeComponent = object->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  mHavokCharacter = this->mHavokCharacter;
  position.m_quad = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(
                        (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.x),
                        (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.z)),
                      _mm_unpacklo_ps(
                        (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y),
                        (__m128)(unsigned int)FLOAT_1_0));
  hkpRigidBody::setPosition(mHavokCharacter->m_character, &position);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->mRagdollComponent,
    object);
}

// File Line: 533
// RVA: 0x46E6D0
void __fastcall UFG::CharacterPhysicsComponent::OnDetach(UFG::CharacterPhysicsComponent *this)
{
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0> *p_mRagdollComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::SimComponent *m_pPointer; // rax

  p_mRagdollComponent = &this->mRagdollComponent;
  if ( this->mRagdollComponent.m_pSimComponent )
  {
    mNext = this->mRagdollComponent.mNext;
    mPrev = p_mRagdollComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mRagdollComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_mRagdollComponent->m_pSimObject = 0i64;
    p_mRagdollComponent->mNext = p_mRagdollComponent;
    p_mRagdollComponent->mPrev = p_mRagdollComponent;
    goto LABEL_8;
  }
  if ( this->mRagdollComponent.m_pSimObject
    && (p_mRagdollComponent->mPrev != p_mRagdollComponent || this->mRagdollComponent.mNext != &this->mRagdollComponent) )
  {
    v5 = this->mRagdollComponent.mNext;
    v6 = p_mRagdollComponent->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    goto LABEL_7;
  }
LABEL_8:
  p_mRagdollComponent->m_Changed = 1;
  m_pPointer = this->mWaterTracker.m_pPointer;
  if ( m_pPointer )
  {
    if ( SLODWORD(m_pPointer[1].m_BoundComponentHandles.mNode.mNext) > 0 )
      UFG::GameStatAction::Character::ExitWater(this->m_pSimObject);
  }
}

// File Line: 544
// RVA: 0x476240
void __fastcall UFG::CharacterPhysicsComponent::Suspend(UFG::CharacterPhysicsComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  unsigned __int16 m_Flags; // cx
  __int64 mAsyncRaycastBucket; // rax
  UFG::SimComponent *m_pPointer; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject || (m_pSimObject->m_Flags & 0x800) == 0 )
  {
    m_Flags = this->m_Flags;
    if ( (m_Flags & 2) == 0 )
    {
      mAsyncRaycastBucket = this->mAsyncRaycastBucket;
      this->m_Flags = m_Flags | 2;
      if ( (_DWORD)mAsyncRaycastBucket != -1 )
        --UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts[mAsyncRaycastBucket];
      this->mAsyncRaycastBucket = -1;
    }
    m_pPointer = this->mWaterTracker.m_pPointer;
    if ( m_pPointer )
      ((void (__fastcall *)(UFG::SimComponent *))m_pPointer->vfptr[8].__vecDelDtor)(m_pPointer);
  }
}

// File Line: 568
// RVA: 0x473DC0
void __fastcall UFG::CharacterPhysicsComponent::Restore(UFG::CharacterPhysicsComponent *this)
{
  unsigned __int16 m_Flags; // cx
  int v3; // r8d
  int v4; // r9d
  int v5; // eax
  int *mAsyncRaycastBucketCounts; // rcx
  UFG::SimComponent *m_pPointer; // rcx

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) != 0 )
  {
    v3 = 0x7FFFFFFF;
    v4 = 0;
    this->m_Flags = m_Flags & 0xFFFD;
    v5 = 0;
    mAsyncRaycastBucketCounts = UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts;
    do
    {
      if ( *mAsyncRaycastBucketCounts <= v3 )
      {
        v3 = *mAsyncRaycastBucketCounts;
        v4 = v5;
      }
      ++v5;
      ++mAsyncRaycastBucketCounts;
    }
    while ( v5 < 12 );
    ++UFG::CharacterPhysicsComponentManager::mInstance->mAsyncRaycastBucketCounts[v4];
    this->mAsyncRaycastBucket = v4;
  }
  m_pPointer = this->mWaterTracker.m_pPointer;
  if ( m_pPointer )
    ((void (__fastcall *)(UFG::SimComponent *))m_pPointer->vfptr[9].__vecDelDtor)(m_pPointer);
}

// File Line: 588
// RVA: 0x4767E0
void __fastcall UFG::CharacterPhysicsComponent::TeleportEventHandler(
        UFG::CharacterPhysicsComponent *this,
        UFG::Event *event)
{
  CharacterRigidBody *mHavokCharacter; // rcx
  float v4; // xmm6_4
  __m128 m_EventUID; // xmm7
  float v7; // xmm0_4
  CharacterRigidBody *v8; // rbx
  UFG::SimObject *m_pSimObject; // rax
  CharacterRigidBody *v10; // rax
  hkpEntity *m_character; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SimObject *v14; // rax
  CharacterRigidBody *v15; // rax
  hkpEntity *v16; // rbx
  UFG::SimComponent *m_pPointer; // rax
  hkVector4f position; // [rsp+20h] [rbp-58h] BYREF
  hkQuaternionf rotation; // [rsp+30h] [rbp-48h] BYREF
  __int128 v20; // [rsp+40h] [rbp-38h] BYREF

  mHavokCharacter = this->mHavokCharacter;
  v4 = 0.0;
  m_EventUID = (__m128)event[2].m_EventUID;
  position.m_quad = _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)LODWORD(event[2].mNext), m_EventUID),
                      _mm_unpacklo_ps((__m128)HIDWORD(event[2].mNext), (__m128)0i64));
  hkpRigidBody::setPosition(mHavokCharacter->m_character, &position);
  v7 = atan2f(*((float *)&event[1].m_EventUID + 1), *(float *)&event[1].m_EventUID);
  v8 = this->mHavokCharacter;
  this->mFacing = v7;
  hkQuaternionf::setAxisAngle(&rotation, &v8->m_up, v7);
  hkpRigidBody::setRotation(v8->m_character, &rotation);
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject || (m_pSimObject->m_Flags & 0x800) == 0 )
  {
    v10 = this->mHavokCharacter;
    rotation.m_vec.m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)LODWORD(UFG::qVector3::msZero.x),
                                (__m128)LODWORD(UFG::qVector3::msZero.z)),
                              _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.y), (__m128)0i64));
    m_character = v10->m_character;
    v10->m_acceleration.m_quad = _mm_mul_ps(
                                   _mm_sub_ps(rotation.m_vec.m_quad, m_character->m_motion.m_linearVelocity.m_quad),
                                   (__m128)_xmm);
    hkpEntity::activate(m_character);
    m_character->m_motion.vfptr[9].__vecDelDtor(&m_character->m_motion, (unsigned int)&rotation);
  }
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mAdditiveVelocity.x = UFG::qVector3::msZero.x;
  this->mAdditiveVelocity.y = y;
  this->mAdditiveVelocity.z = z;
  v14 = this->m_pSimObject;
  if ( !v14 || (v14->m_Flags & 0x800) == 0 )
    v4 = FLOAT_N9_8100004;
  v15 = this->mHavokCharacter;
  this->mGravity = v4;
  this->mSpeedZ = 0.0;
  v20 = 0i64;
  v16 = v15->m_character;
  hkpEntity::activate(v16);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))v16->m_motion.vfptr[9].__first_virtual_table_function__)(
    &v16->m_motion,
    &v20);
  m_pPointer = this->mWaterTracker.m_pPointer;
  if ( m_pPointer && SLODWORD(m_pPointer[1].m_BoundComponentHandles.mNode.mNext) > 0 )
    UFG::GameStatAction::Character::ExitWater(this->m_pSimObject);
  *((_DWORD *)&this->mGroundProperties + 17) &= ~1u;
  LODWORD(this->mGroundProperties.maxOffGroundElevation) = m_EventUID.m128_i32[0];
  *(_QWORD *)&this->mGroundProperties.latchedFallDistance = 0i64;
  this->mGroundProperties.timeOffGround = 0.0;
  this->mGroundProperties.heightAboveGround = 0.0;
}

// File Line: 624
// RVA: 0x46F8A0
void __fastcall UFG::CharacterPhysicsComponent::PlaceOnGroundAfterNIS(UFG::CharacterPhysicsComponent *this)
{
  UFG::SimObject *m_pSimObject; // rdi
  float v3; // xmm1_4
  float v4; // xmm2_4
  CharacterRigidBody *mHavokCharacter; // rcx
  float v6; // xmm6_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  CharacterRigidBody *v18; // rbx
  UFG::SimObject *v19; // rax
  CharacterRigidBody *v20; // rax
  hkpEntity *m_character; // rbx
  UFG::qVector3 out; // [rsp+20h] [rbp-39h] BYREF
  hkVector4f position; // [rsp+30h] [rbp-29h] BYREF
  hkQuaternionf rotation; // [rsp+40h] [rbp-19h] BYREF
  __int128 v25; // [rsp+50h] [rbp-9h] BYREF
  UFG::qMatrix44 fx; // [rsp+60h] [rbp+7h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
  v3 = *((float *)m_pSimObject[1].mNode.mChild + 1);
  v4 = *(float *)&m_pSimObject[1].mNode.mChild[1];
  out.x = *(float *)m_pSimObject[1].mNode.mChild;
  out.y = v3;
  out.z = v4;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
  if ( UFG::SimObjectUtility::PlaceOnGround(&out, (UFG::qVector3 *)m_pSimObject[1].mNode.mChild, 0.1, 3.0) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
    mHavokCharacter = this->mHavokCharacter;
    v6 = 0.0;
    v7 = *((float *)&m_pSimObject[1].vfptr + 1);
    fx.v0.x = *(float *)&m_pSimObject[1].vfptr;
    v8 = *(float *)&m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    fx.v0.y = v7;
    v9 = *((float *)&m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev
         + 1);
    fx.v0.z = v8;
    v10 = *(float *)&m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
    fx.v0.w = v9;
    v11 = *((float *)&m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext
          + 1);
    fx.v1.x = v10;
    fx.v1.z = *(float *)&m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev;
    v12 = *(float *)&m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
    fx.v1.y = v11;
    v13 = *((float *)&m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev
          + 1);
    fx.v2.x = v12;
    v14 = *(float *)&m_pSimObject[1].mNode.mParent;
    fx.v1.w = v13;
    v15 = *((float *)&m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext
          + 1);
    fx.v2.z = v14;
    fx.v3.z = out.z;
    fx.v2.y = v15;
    v16 = *((float *)&m_pSimObject[1].mNode.mParent + 1);
    LODWORD(fx.v3.w) = (_DWORD)FLOAT_1_0;
    fx.v2.w = v16;
    *(_QWORD *)&fx.v3.x = *(_QWORD *)&out.x;
    position.m_quad = _mm_unpacklo_ps(
                        _mm_unpacklo_ps((__m128)LODWORD(out.x), (__m128)LODWORD(out.z)),
                        _mm_unpacklo_ps((__m128)LODWORD(out.y), (__m128)0i64));
    hkpRigidBody::setPosition(mHavokCharacter->m_character, &position);
    v17 = atan2f(fx.v0.y, fx.v0.x);
    v18 = this->mHavokCharacter;
    this->mFacing = v17;
    hkQuaternionf::setAxisAngle(&rotation, &v18->m_up, v17);
    hkpRigidBody::setRotation(v18->m_character, &rotation);
    v19 = this->m_pSimObject;
    if ( !v19 || (v19->m_Flags & 0x800) == 0 )
      v6 = FLOAT_N9_8100004;
    v20 = this->mHavokCharacter;
    this->mGravity = v6;
    v25 = 0i64;
    m_character = v20->m_character;
    hkpEntity::activate(m_character);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))m_character->m_motion.vfptr[9].__first_virtual_table_function__)(
      &m_character->m_motion,
      &v25);
    UFG::TransformNodeComponent::SetWorldTransform((UFG::TransformNodeComponent *)m_pSimObject, &fx);
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
  int v5; // ebx
  UFG::SimComponent *m_pSimComponent; // rdx
  CharacterRigidBody *mHavokCharacter; // rdi
  unsigned int m_collisionFilterInfo; // r15d
  UFG::CharacterCollisionMode mDesiredCollisionModelType; // eax
  hkpEntity *m_character; // rdi
  hkpWorld *m_world; // r14
  __m128 v13; // xmm0
  int v14; // eax
  hkpRigidBody *v15; // rdx
  hkpWorld *v16; // rcx
  UFG::SimObject *m_pSimObject; // rdi
  float mFacing; // xmm10_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float x; // xmm4_4
  __m128 y_low; // xmm5
  float z; // xmm2_4
  float w; // xmm3_4
  UFG::SimObject *m_pPointer; // rbx
  UFG::TransformNodeComponent *v25; // rbx
  float v26; // xmm6_4
  float y; // xmm7_4
  float v28; // xmm8_4
  __m128 v29; // xmm1
  float v30; // xmm2_4
  float v31; // xmm0_4
  UFG::SimObject *v32; // rax
  CharacterRigidBody *v33; // rbx
  float v34; // xmm1_4
  __int16 v35; // cx
  CharacterRigidBody *v36; // rax
  __m128 v37; // xmm0
  hkpEntity *v38; // rbx
  hkQuaternionf *p_rotation; // rdx
  CharacterRigidBody *v40; // rax
  UFG::SimComponent *v41; // rax
  char v42; // r14
  __m128 m_quad; // xmm6
  UFG::SimObjectCVBase *v44; // rcx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  Creature *mCreature; // rcx
  hkQsTransformf *PositionhkQ; // rax
  bool v49; // zf
  __m128 mSpeedZ_low; // xmm0
  __m128 v51; // xmm2
  float v52; // xmm2_4
  float v53; // xmm3_4
  int v54; // xmm1_4
  unsigned int v55; // xmm3_4
  CharacterRigidBody *v56; // rcx
  unsigned int v57; // xmm1_4
  hkpRigidBody *v58; // rcx
  float v59; // xmm1_4
  __m128 v60; // xmm6
  hkpRigidBody *v61; // rbx
  UFG::SimComponent *v62; // rax
  float v63; // xmm7_4
  float v64; // xmm1_4
  float v65; // xmm0_4
  __m128 v66; // xmm6
  UFG::GameStatTracker *v67; // rbx
  hkpRigidBody *v68; // rdi
  __int64 v69; // rdx
  UFG::SimObjectGame *v70; // rcx
  __int16 v71; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *v73; // rax
  hkpRigidBody *v74; // rdi
  __m128 *v75; // rcx
  __int64 v76; // rdx
  unsigned int v77; // eax
  UFG::qVector3 *p_mCurbBullShitHackNormal; // rcx
  int v79; // eax
  float v80; // xmm4_4
  int v81; // eax
  UFG::SimComponent *v82; // rax
  int mPrev; // ecx
  UFG::SimObjectCVBase *v84; // rcx
  __int16 v85; // dx
  UFG::CharacterAnimationComponent *v86; // rax
  float v87; // xmm6_4
  __m128 v88; // xmm3
  __m128 x_low; // xmm4
  __m128 z_low; // xmm5
  float v91; // xmm2_4
  float v92; // xmm2_4
  __m128 v93; // xmm7
  __m128 v94; // xmm5
  __m128 v95; // xmm4
  float v96; // xmm3_4
  float v97; // xmm2_4
  float v98; // xmm2_4
  float v99; // xmm1_4
  float v100; // xmm12_4
  float v101; // xmm0_4
  float v102; // xmm6_4
  __m128 v103; // xmm4
  float v104; // xmm1_4
  __m128 v105; // xmm3
  __m128 v106; // xmm2
  UFG::SimObject *v107; // rax
  CharacterRigidBody *v108; // rax
  hkpEntity *v109; // rbx
  UFG::qVector3 dir; // [rsp+30h] [rbp-A8h] BYREF
  float number[4]; // [rsp+40h] [rbp-98h] BYREF
  __m128 v112; // [rsp+50h] [rbp-88h] BYREF
  hkQuaternionf rotation; // [rsp+60h] [rbp-78h] BYREF
  hkQsTransformf v114; // [rsp+70h] [rbp-68h] BYREF
  hkBool result[4]; // [rsp+128h] [rbp+50h] BYREF

  v2 = (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance;
  *((_DWORD *)this + 151) &= ~4u;
  v3 = 0;
  v5 = 6;
  *((_DWORD *)&this->mGroundProperties + 17) ^= ((unsigned __int8)*((_DWORD *)&this->mGroundProperties + 17) ^ (unsigned __int8)(4 * *((_DWORD *)&this->mGroundProperties + 17))) & 4;
  m_pSimComponent = this->mRagdollComponent.m_pSimComponent;
  if ( m_pSimComponent
    && LODWORD(m_pSimComponent[2].m_SafePointerList.mNode.mPrev) == 1
    && HIDWORD(m_pSimComponent[2].m_SafePointerList.mNode.mPrev) == 1 )
  {
    if ( *(float *)&m_pSimComponent[2].vfptr >= 1.0 )
    {
      this->mDesiredCollisionModelType = CP_DISABLED;
      v3 = 1;
    }
    else
    {
      this->mDesiredCollisionModelType = CP_CRAWL;
    }
  }
  mHavokCharacter = this->mHavokCharacter;
  m_collisionFilterInfo = mHavokCharacter->m_character->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
  mDesiredCollisionModelType = this->mDesiredCollisionModelType;
  if ( this->mCollisionModelType != mDesiredCollisionModelType )
  {
    this->mCollisionModelType = mDesiredCollisionModelType;
    m_character = mHavokCharacter->m_character;
    m_world = m_character->m_world;
    if ( m_world )
      hkpWorld::removeEntity(m_character->m_world, result, m_character);
    ((void (__fastcall *)(hkpEntity *, hkpShape *))m_character->vfptr[1].__first_virtual_table_function__)(
      m_character,
      this->mCollisionShapes[this->mCollisionModelType]);
    v13 = (__m128)LODWORD(this->mParam.mCollisionHeight[this->mDesiredCollisionModelType]);
    v13.m128_f32[0] = v13.m128_f32[0] - 0.050000001;
    this->mHavokCharacter->mTopVertex.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v13), _xmm);
    if ( m_world )
      hkpWorld::addEntity(m_world, m_character, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  }
  switch ( this->mCollisionModelType )
  {
    case CP_DRIVING:
      v14 = 27;
      if ( this->mRagdollComponent.m_pSimComponent )
        v14 = 21;
      v5 = v14;
      break;
    case CP_ENTER_EXIT_VEHICLE:
      v5 = 5;
      break;
    case CP_DISABLED:
      v5 = 21;
      break;
    default:
      if ( this->mCollisionModelType != CP_SITTING )
      {
        if ( this->mCollisionModelType == CP_DEAD )
          v5 = 4;
        else
          v5 = (this->mRagdollComponent.m_pSimComponent != 0i64) + 1;
      }
      break;
  }
  if ( this->mCollisionModelType != CP_COMBAT && v5 != m_collisionFilterInfo )
  {
    v15 = this->mHavokCharacter->m_character;
    v16 = v15->m_world;
    v15->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v5;
    if ( v16 )
      hkpWorld::updateCollisionFilterOnEntity(
        v16,
        v15,
        HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
        HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  }
  m_pSimObject = this->m_pSimObject;
  mFacing = this->mFacing;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  x = m_pTransformNodeComponent->mWorldTransform.v0.x;
  y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.y);
  z = m_pTransformNodeComponent->mWorldTransform.v0.z;
  w = m_pTransformNodeComponent->mWorldTransform.v0.w;
  if ( this->mGrappleState == 1 )
  {
    m_pPointer = this->mGrapplePartner.m_pPointer;
    if ( m_pPointer )
    {
      v25 = m_pPointer->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v26 = m_pTransformNodeComponent->mWorldTransform.v3.x;
      y = m_pTransformNodeComponent->mWorldTransform.v3.y;
      v28 = m_pTransformNodeComponent->mWorldTransform.v3.z;
      UFG::TransformNodeComponent::UpdateWorldTransform(v25);
      w = 0.0;
      y_low = (__m128)LODWORD(v25->mWorldTransform.v3.y);
      x = v25->mWorldTransform.v3.x - v26;
      y_low.m128_f32[0] = y_low.m128_f32[0] - y;
      z = v25->mWorldTransform.v3.z - v28;
    }
  }
  v29 = y_low;
  v29.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x)) + (float)(z * z))
                  + (float)(w * w);
  if ( v29.m128_f32[0] == 0.0 )
    v30 = 0.0;
  else
    v30 = 1.0 / _mm_sqrt_ps(v29).m128_f32[0];
  v31 = atan2f(v30 * y_low.m128_f32[0], v30 * x);
  v32 = this->m_pSimObject;
  this->mFacing = v31;
  if ( !v32 || (v32->m_Flags & 0x800) == 0 )
  {
    if ( this->mGrappleState == 1 )
    {
      v33 = this->mHavokCharacter;
      hkQuaternionf::setAxisAngle(&rotation, &v33->m_up, v31);
      hkpRigidBody::setRotation(v33->m_character, &rotation);
      v34 = *(float *)&FLOAT_1_0;
      v35 = (int)(float)((float)(this->mFacing * 32768.0) * 0.31830987)
          - (int)(float)((float)(mFacing * 32768.0) * 0.31830987);
      if ( v35 < 0 )
      {
        v34 = FLOAT_N1_0;
        v35 = (int)(float)((float)(mFacing * 32768.0) * 0.31830987)
            - (int)(float)((float)(this->mFacing * 32768.0) * 0.31830987);
      }
      v36 = this->mHavokCharacter;
      v37 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int16)v35);
      v37.m128_f32[0] = (float)((float)((float)(v37.m128_f32[0] * 3.1415927) * 0.000030517578) / deltaT) * v34;
      *(__m128 *)number = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v37), (__m128)0i64);
      v38 = v36->m_character;
      hkpEntity::activate(v38);
      p_rotation = (hkQuaternionf *)number;
    }
    else
    {
      v40 = this->mHavokCharacter;
      rotation.m_vec.m_quad = 0i64;
      v38 = v40->m_character;
      hkpEntity::activate(v38);
      p_rotation = &rotation;
    }
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkQuaternionf *))v38->m_motion.vfptr[9].__first_virtual_table_function__)(
      &v38->m_motion,
      p_rotation);
  }
  v41 = this->mWaterTracker.m_pPointer;
  if ( v41 && SLODWORD(v41[1].m_BoundComponentHandles.mNode.mNext) > 0 )
  {
    v42 = 1;
    this->mHavokCharacter->m_isInWater = 1;
    this->mHeightFixup = 0.0;
  }
  else
  {
    v42 = 0;
    this->mHavokCharacter->m_isInWater = 0;
    if ( (*((_BYTE *)&this->mGroundProperties + 68) & 1) != 0 )
      this->mHeightFixup = this->mGroundProperties.heightAboveGround;
  }
  m_quad = this->mHavokCharacter->m_character->m_motion.m_motionState.m_transform.m_translation.m_quad;
  v44 = (UFG::SimObjectCVBase *)this->m_pSimObject;
  rotation.m_vec.m_quad = m_quad;
  if ( v44 )
  {
    m_Flags = v44->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v44);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v44);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v44,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                v44,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  mCreature = ComponentOfTypeHK->mCreature;
  if ( mCreature )
  {
    PositionhkQ = Creature::GetPositionhkQ(mCreature, &v114);
    v49 = (*((_BYTE *)this + 0x25C) & 0x10) == 0;
    v112 = PositionhkQ->m_translation.m_quad;
    mSpeedZ_low = _mm_shuffle_ps(v112, v112, 170);
    v112.m128_f32[2] = mSpeedZ_low.m128_f32[0] + this->mHeightFixup;
    if ( v49 )
    {
      mSpeedZ_low = (__m128)(unsigned int)FLOAT_1_0;
      v51 = _mm_sub_ps(v112, m_quad);
      v112.m128_u64[1] = v51.m128_u64[1];
      v52 = v51.m128_f32[0] * (float)(1.0 / deltaT);
      v53 = v51.m128_f32[1] * (float)(1.0 / deltaT);
      *(float *)&v54 = v51.m128_f32[2] * (float)(1.0 / deltaT);
      v112.m128_f32[0] = v52;
      v112.m128_f32[1] = v53;
    }
    else
    {
      v112 = this->mHavokCharacter->m_character->m_motion.m_linearVelocity.m_quad;
      v53 = v112.m128_f32[1];
      v52 = v112.m128_f32[0];
      v54 = _mm_shuffle_ps(v112, v112, 170).m128_u32[0];
      this->mSpeedZ = *(float *)&v54;
    }
    v112.m128_i32[2] = v54;
    if ( v3 )
    {
      this->mSpeedZ = *(float *)&v54;
LABEL_108:
      v82 = this->mRagdollComponent.m_pSimComponent;
      if ( !v82
        || *(float *)&v82[2].vfptr < 1.0
        || (mPrev = (int)v82[2].m_SafePointerList.mNode.mPrev) == 0
        || mPrev == 5 )
      {
        v84 = (UFG::SimObjectCVBase *)this->m_pSimObject;
        if ( v84 )
        {
          v85 = v84->m_Flags;
          if ( (v85 & 0x4000) != 0 || v85 < 0 )
          {
            v86 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v84);
          }
          else if ( (v85 & 0x2000) != 0 )
          {
            v86 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v84);
          }
          else
          {
            v86 = (UFG::CharacterAnimationComponent *)((v85 & 0x1000) != 0
                                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v84,
                                                         UFG::CharacterAnimationComponent::_TypeUID)
                                                     : UFG::SimObject::GetComponentOfType(
                                                         v84,
                                                         UFG::CharacterAnimationComponent::_TypeUID));
          }
          if ( v86 && v86->mUpdatedFromNIS )
            this->mSpeedZ = 0.0;
        }
      }
      if ( !v42 )
        goto LABEL_145;
      *(float *)&result[0].m_bool = 0.0;
      *(_QWORD *)&dir.x = 0i64;
      dir.z = 0.0;
      v87 = FLOAT_15_0;
      number[0] = rotation.m_vec.m_quad.m128_f32[0];
      mSpeedZ_low = (__m128)rotation.m_vec.m_quad.m128_u32[2];
      *(_QWORD *)&number[1] = *(unsigned __int64 *)((char *)rotation.m_vec.m_quad.m128_u64 + 4);
      if ( this->m_pSimObject == LocalPlayer
        && UFG::WorldBoundaries::IsOutsideBoundaries2(&v2->mBoundaries, (UFG::qVector3 *)number, 15.0, &dir) )
      {
        v88 = (__m128)LODWORD(dir.y);
        x_low = (__m128)LODWORD(dir.x);
        z_low = (__m128)LODWORD(dir.z);
        LODWORD(v91) = COERCE_UNSIGNED_INT(
                         (float)((float)(dir.y * v112.m128_f32[1]) + (float)(dir.x * v112.m128_f32[0]))
                       + (float)(dir.z * v112.m128_f32[2])) ^ _xmm[0];
        if ( v91 < 0.0 )
          v91 = 0.0;
        v92 = v91 + 1.0;
        v88.m128_f32[0] = dir.y * v92;
        z_low.m128_f32[0] = dir.z * v92;
        x_low.m128_f32[0] = dir.x * v92;
        mSpeedZ_low = _mm_add_ps(
                        v112,
                        _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), _mm_unpacklo_ps(v88, (__m128)0i64)));
        v112 = mSpeedZ_low;
        goto LABEL_145;
      }
      if ( !UFG::WorldBoundaries::IsOutsideBoundaries(
              &v2->mBoundaries,
              (UFG::qVector3 *)number,
              15.0,
              &dir,
              (float *)&result[0].m_bool) )
      {
LABEL_145:
        this->mHavokCharacter->m_fixCurbContacts = (*((_BYTE *)this + 604) & 0x20) != 0
                                                && (mSpeedZ_low = (__m128)LODWORD(CharacterRigidBody::mMaxCurbHeight),
                                                    (float)(CharacterRigidBody::mMaxCurbHeight * 2.0) > this->mGroundProperties.heightAboveGround);
        v107 = this->m_pSimObject;
        if ( !v107 || (v107->m_Flags & 0x800) == 0 )
        {
          v108 = this->mHavokCharacter;
          v109 = v108->m_character;
          mSpeedZ_low.m128_f32[0] = 1.0 / deltaT;
          v108->m_acceleration.m_quad = _mm_mul_ps(
                                          _mm_sub_ps(v112, v109->m_motion.m_linearVelocity.m_quad),
                                          _mm_shuffle_ps(mSpeedZ_low, mSpeedZ_low, 0));
          hkpEntity::activate(v109);
          v109->m_motion.vfptr[9].__vecDelDtor(&v109->m_motion, (unsigned int)&v112);
        }
        return;
      }
      v93 = (__m128)v112.m128_u32[1];
      v94 = (__m128)v112.m128_u32[0];
      v95 = (__m128)v112.m128_u32[2];
      v96 = *(float *)&result[0].m_bool;
      v97 = (float)((float)(dir.y * v112.m128_f32[1]) + (float)(dir.x * v112.m128_f32[0]))
          + (float)(dir.z * v112.m128_f32[2]);
      if ( v97 >= 0.0 )
      {
        v103 = v112;
LABEL_139:
        if ( *(float *)&result[0].m_bool <= 0.0 )
        {
          v96 = 0.0;
        }
        else
        {
          v104 = FLOAT_13_0;
          if ( *(float *)&result[0].m_bool >= 13.0 )
            goto LABEL_144;
        }
        v104 = v96;
LABEL_144:
        mSpeedZ_low = (__m128)(unsigned int)FLOAT_1_0;
        mSpeedZ_low.m128_f32[0] = (float)(1.0 - (float)(v104 * 0.07692308)) * 4.0;
        v105 = mSpeedZ_low;
        v106 = mSpeedZ_low;
        mSpeedZ_low.m128_f32[0] = mSpeedZ_low.m128_f32[0] * dir.z;
        v105.m128_f32[0] = v105.m128_f32[0] * dir.x;
        v106.m128_f32[0] = v106.m128_f32[0] * dir.y;
        v112 = _mm_add_ps(
                 v103,
                 _mm_unpacklo_ps(_mm_unpacklo_ps(v105, mSpeedZ_low), _mm_unpacklo_ps(v106, (__m128)0i64)));
        goto LABEL_145;
      }
      v98 = v97 * dir.z;
      v101 = *(float *)&result[0].m_bool - 4.0;
      if ( (float)(*(float *)&result[0].m_bool - 4.0) <= 0.0 )
      {
        v101 = 0.0;
      }
      else if ( v101 >= 15.0 )
      {
        goto LABEL_137;
      }
      v87 = v101;
LABEL_137:
      v102 = v87 * 0.06666667;
      v95.m128_f32[0] = (float)(v112.m128_f32[2] - v98) + (float)(v102 * v98);
      v99 = (float)((float)((float)(dir.y * v112.m128_f32[1]) + (float)(dir.x * v112.m128_f32[0]))
                  + (float)(dir.z * v112.m128_f32[2]))
          * dir.x;
      v94.m128_f32[0] = (float)(v112.m128_f32[0] - v99) + (float)(v102 * v99);
      v100 = (float)((float)((float)(dir.y * v112.m128_f32[1]) + (float)(dir.x * v112.m128_f32[0]))
                   + (float)(dir.z * v112.m128_f32[2]))
           * dir.y;
      v93.m128_f32[0] = (float)(v112.m128_f32[1] - v100) + (float)(v102 * v100);
      v103 = _mm_unpacklo_ps(_mm_unpacklo_ps(v94, v95), _mm_unpacklo_ps(v93, (__m128)0i64));
      goto LABEL_139;
    }
    v49 = (*((_BYTE *)&this->mGroundProperties + 68) & 1) == 0;
    *(float *)&v55 = v53 + this->mAdditiveVelocity.y;
    v56 = this->mHavokCharacter;
    *(float *)&v57 = *(float *)&v54 + this->mAdditiveVelocity.z;
    v112.m128_f32[0] = v52 + this->mAdditiveVelocity.x;
    *(unsigned __int64 *)((char *)v112.m128_u64 + 4) = __PAIR64__(v57, v55);
    v58 = v56->m_character;
    if ( v49 )
      v59 = IN_AIR_FRICTION;
    else
      v59 = ON_GROUND_FRICTION;
    hkpRigidBody::setFriction(v58, v59);
    if ( (*((_BYTE *)&this->mGroundProperties + 68) & 2) != 0 || (*((_DWORD *)this + 151) & 0x100) != 0 )
    {
      v77 = *((_DWORD *)this + 151);
      if ( (v77 & 0x20) != 0 || (v77 & 0x100) != 0 )
      {
        p_mCurbBullShitHackNormal = &this->mCurbBullShitHackNormal;
        v79 = (v77 >> 8) & 1;
        if ( !v79 )
          p_mCurbBullShitHackNormal = &this->mGroundProperties.groundNormal;
        v80 = p_mCurbBullShitHackNormal->z;
        if ( v79 || v80 > 0.70700002 )
          this->mSpeedZ = v112.m128_f32[2]
                        - (float)((float)((float)((float)(v112.m128_f32[1] * p_mCurbBullShitHackNormal->y)
                                                + (float)(v112.m128_f32[0] * p_mCurbBullShitHackNormal->x))
                                        + (float)(v112.m128_f32[2] * v80))
                                * v80);
        goto LABEL_103;
      }
    }
    else
    {
      v60 = 0i64;
      if ( v42 )
      {
        v61 = this->mHavokCharacter->m_character;
        v62 = this->mWaterTracker.m_pPointer;
        *(hkVector4f *)number = v61->m_motion.m_motionState.m_transform.m_translation;
        if ( v62 )
          v63 = *((float *)&v62[2].m_SafePointerList.mNode.mPrev + 1);
        else
          v63 = FLOAT_N0_31400001;
        v64 = (float)(this->mParam.mCollisionHeight[this->mCollisionModelType] * 0.5) + 0.4 + number[2];
        v65 = UFG::PhysicsSystem::ComputeBuoyancy(v2, v64, 1.0, v63);
        v60 = 0i64;
        if ( COERCE_FLOAT(LODWORD(v65) & _xmm) > 0.0099999998 )
        {
          v66 = _mm_shuffle_ps(v61->m_motion.m_linearVelocity.m_quad, v61->m_motion.m_linearVelocity.m_quad, 170);
          v66.m128_f32[0] = v66.m128_f32[0] * UFG::CharacterPhysicsComponent::mViscousFrictionCoeff;
          v60 = _mm_xor_ps(v66, (__m128)(unsigned int)_xmm[0]);
        }
        v60.m128_f32[0] = v60.m128_f32[0] + (float)(v65 * UFG::CharacterPhysicsComponent::mBuoyancy);
        if ( this->m_pSimObject == LocalPlayer )
        {
          v67 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v67, PlayerLastStableLocationX, number[0]);
          UFG::GameStatTracker::SetStat(v67, PlayerLastStableLocationY, number[1]);
          UFG::GameStatTracker::SetStat(v67, PlayerLastStableLocationZ, v63);
        }
      }
      if ( this->mGrappleState != 2 )
      {
        v68 = this->mHavokCharacter->m_character;
        v60.m128_f32[0] = (float)(v60.m128_f32[0] + this->mGravity) * hkpMotion::getMass(&v68->m_motion);
        *(__m128 *)number = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v60), (__m128)0i64);
        hkpEntity::activate(v68);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, float *))v68->m_motion.hkpEntity::vfptr[13].__vecDelDtor)(
          &v68->m_motion,
          v69,
          number);
        LODWORD(this->mSpeedZ) = v68->m_motion.m_linearVelocity.m_quad.m128_i32[2];
LABEL_103:
        v81 = *((_DWORD *)this + 151);
        if ( (v81 & 1) == 0 || (v81 & 0x100) != 0 )
        {
          mSpeedZ_low = (__m128)LODWORD(this->mSpeedZ);
          v112.m128_i32[2] = LODWORD(this->mSpeedZ);
        }
        else
        {
          mSpeedZ_low = (__m128)v112.m128_u32[2];
          LODWORD(this->mSpeedZ) = v112.m128_i32[2];
        }
        goto LABEL_108;
      }
      v70 = (UFG::SimObjectGame *)this->mGrapplePartner.m_pPointer;
      if ( !v70 )
        goto LABEL_103;
      v71 = v70->m_Flags;
      if ( (v71 & 0x4000) != 0 )
      {
        m_pComponent = v70->m_Components.p[27].m_pComponent;
      }
      else
      {
        v73 = v71 < 0 || (v71 & 0x2000) != 0 || (v71 & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(v70, UFG::CharacterPhysicsComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(v70, UFG::CharacterPhysicsComponent::_TypeUID);
        m_pComponent = v73;
      }
      if ( !m_pComponent )
        goto LABEL_103;
      v74 = this->mHavokCharacter->m_character;
      v75 = (__m128 *)m_pComponent[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
      if ( v74
        && v75
        && (_mm_movemask_ps(_mm_cmplt_ps(v75[26], v74->m_motion.m_motionState.m_transform.m_translation.m_quad)) & 4) != 0 )
      {
        v60.m128_f32[0] = (float)(v60.m128_f32[0] + this->mGravity) * hkpMotion::getMass(&v74->m_motion);
        *(__m128 *)number = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v60), (__m128)0i64);
        hkpEntity::activate(v74);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, float *))v74->m_motion.hkpEntity::vfptr[13].__vecDelDtor)(
          &v74->m_motion,
          v76,
          number);
        LODWORD(this->mSpeedZ) = v74->m_motion.m_linearVelocity.m_quad.m128_i32[2];
        goto LABEL_103;
      }
    }
    this->mSpeedZ = 0.0;
    goto LABEL_103;
  }
}

// File Line: 1216
// RVA: 0x47EB10
void __fastcall UFG::CharacterPhysicsComponent::UpdateGroundState(UFG::CharacterPhysicsComponent *this, float timestep)
{
  CharacterRigidBody *mHavokCharacter; // rcx
  hkpRigidBody *m_character; // rax
  float v5; // xmm0_4
  bool v6; // zf
  unsigned int v7; // edx
  hkpSurfaceInfo::SupportedState m_supportedState; // ecx
  int v9; // eax
  int v10; // eax
  float z; // xmm2_4
  float x; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  float v18; // xmm2_4
  float timeOffGround; // xmm1_4
  float maxOffGroundElevation; // xmm0_4
  UFG::GameStatTracker *v21; // rbx
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rcx
  hkStepInfo stepInfo; // [rsp+20h] [rbp-88h] BYREF
  hkVector4f v27; // [rsp+30h] [rbp-78h]
  hkpSurfaceInfo ground; // [rsp+40h] [rbp-68h] BYREF

  mHavokCharacter = this->mHavokCharacter;
  m_character = mHavokCharacter->m_character;
  stepInfo.m_startTime.m_storage = 0.0;
  stepInfo.m_endTime.m_storage = timestep;
  stepInfo.m_deltaTime.m_storage = timestep;
  v27.m_quad = (__m128)m_character->m_motion.m_motionState.m_transform.m_translation;
  if ( timestep == 0.0 )
    v5 = 0.0;
  else
    v5 = 1.0 / timestep;
  v6 = !mHavokCharacter->m_isPlayer;
  stepInfo.m_invDeltaTime.m_storage = v5;
  ground.m_surfaceNormal = (hkVector4f)stru_141A71280.m_quad;
  memset(&ground.m_surfaceVelocity, 0, 21);
  ground.m_supportedState = SUPPORTED;
  if ( v6 )
    CharacterRigidBody::checkSupportForNonPlayer(mHavokCharacter, &stepInfo, &ground);
  else
    CharacterRigidBody::checkSupportForPlayer(mHavokCharacter, &stepInfo, &ground);
  v7 = *((_DWORD *)this + 151);
  if ( (v7 & 0x80u) != 0 && this->mHavokCharacter->m_supportedOffCentre )
  {
    m_supportedState = ground.m_supportedState;
    if ( (*((_BYTE *)&this->mGroundProperties + 68) & 4) != 0 )
      m_supportedState = SUPPORTED;
  }
  else
  {
    m_supportedState = ground.m_supportedState;
  }
  *((_DWORD *)&this->mGroundProperties + 17) &= ~8u;
  v9 = *((_DWORD *)&this->mGroundProperties + 17);
  this->mGroundProperties.support = m_supportedState;
  if ( m_supportedState )
  {
    v14 = FLOAT_0_050000001;
    v15 = v9 | 1;
    *((_DWORD *)&this->mGroundProperties + 17) = v15;
    v16 = (v7 >> 1) & 1;
    if ( !v16 || COERCE_FLOAT(LODWORD(this->mGroundProperties.heightAboveGround) & _xmm) > 0.050000001 )
    {
      if ( !v16 )
        v14 = 0.0;
      this->mGroundProperties.heightAboveGround = v14;
      *((_DWORD *)&this->mGroundProperties + 17) = v15 | 8;
    }
    v17 = *((_DWORD *)&this->mGroundProperties + 17);
    v18 = v27.m_quad.m128_f32[2];
    if ( (v17 & 4) != 0 || (timeOffGround = this->mGroundProperties.timeOffGround, timeOffGround < 0.5) )
    {
      *(_QWORD *)&this->mGroundProperties.latchedFallDistance = 0i64;
    }
    else
    {
      maxOffGroundElevation = this->mGroundProperties.maxOffGroundElevation;
      this->mGroundProperties.latchedFallTime = timeOffGround;
      this->mGroundProperties.latchedFallDistance = maxOffGroundElevation - v18;
    }
    this->mGroundProperties.maxOffGroundElevation = v18;
    this->mGroundProperties.timeOffGround = 0.0;
    *((_DWORD *)&this->mGroundProperties + 17) = v17 | 2;
    if ( this->m_pSimObject == LocalPlayer )
    {
      v21 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v21, PlayerLastStableLocationX, this->mGroundProperties.groundPosition.x);
      UFG::GameStatTracker::SetStat(v21, PlayerLastStableLocationY, this->mGroundProperties.groundPosition.y);
      UFG::GameStatTracker::SetStat(v21, PlayerLastStableLocationZ, this->mGroundProperties.groundPosition.z);
    }
  }
  else
  {
    *((_DWORD *)&this->mGroundProperties + 17) = v9 & 0xFFFFFFFE;
    v10 = 0;
    if ( (v7 & 4) == 0 )
    {
      this->mGroundProperties.heightAboveGround = 0.0;
      z = UFG::qVector3::msZero.z;
      x = UFG::qVector3::msZero.x;
      this->mGroundProperties.groundPosition.y = UFG::qVector3::msZero.y;
      this->mGroundProperties.groundPosition.z = z;
      this->mGroundProperties.groundPosition.x = x;
    }
    if ( v27.m_quad.m128_f32[2] > this->mGroundProperties.maxOffGroundElevation )
      LODWORD(this->mGroundProperties.maxOffGroundElevation) = v27.m_quad.m128_i32[2];
    v13 = timestep + this->mGroundProperties.timeOffGround;
    this->mGroundProperties.timeOffGround = v13;
    LOBYTE(v10) = UFG::CharacterPhysicsComponent::mMaxTimeOffGroundFilter >= v13;
    *((_DWORD *)&this->mGroundProperties + 17) ^= (*((_DWORD *)&this->mGroundProperties + 17) ^ (2 * v10)) & 2;
  }
  m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pSimObject);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pSimObject,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pSimObject,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
    {
      mCreature = ComponentOfTypeHK->mCreature;
      if ( mCreature )
        Creature::SetGroundProperties(mCreature, &this->mGroundProperties);
    }
  }
}

// File Line: 1338
// RVA: 0x47FF90
void __fastcall UFG::CharacterPhysicsComponent::UpdateTransforms(UFG::CharacterPhysicsComponent *this, float deltaT)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  int mPrev; // ecx
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::CharacterAnimationComponent *v7; // rdx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v9; // rax
  Creature *mCreature; // rsi
  int v11; // eax
  bool v12; // zf
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  hkQsTransformf *PositionhkQ; // rax
  CharacterRigidBody *mHavokCharacter; // rcx
  UFG::SimObject *v18; // rax
  hkVector4f v19; // xmm1
  UFG::qVector3 pos; // [rsp+20h] [rbp-58h] BYREF
  hkVector4f position; // [rsp+30h] [rbp-48h] BYREF
  hkQsTransformf result; // [rsp+40h] [rbp-38h] BYREF

  if ( (this->m_Flags & 3) == 1 )
  {
    UFG::CharacterPhysicsComponent::UpdateGroundState(this, deltaT);
    m_pSimComponent = this->mRagdollComponent.m_pSimComponent;
    m_pTransformNodeComponent = 0i64;
    if ( !m_pSimComponent
      || *(float *)&m_pSimComponent[2].vfptr < 1.0
      || (mPrev = (int)m_pSimComponent[2].m_SafePointerList.mNode.mPrev) == 0
      || mPrev == 5 )
    {
      m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
        }
        else if ( (m_Flags & 0x2000) != 0 )
        {
          v9 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pSimObject);
        }
        else
        {
          v9 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pSimObject,
                                                      UFG::CharacterAnimationComponent::_TypeUID)
                                                  : UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::CharacterAnimationComponent::_TypeUID));
        }
        v7 = v9;
      }
      else
      {
        v7 = 0i64;
      }
      mCreature = v7->mCreature;
      position.m_quad = (__m128)this->mHavokCharacter->m_character->m_motion.m_motionState.m_transform.m_translation;
      if ( mCreature )
      {
        *((_DWORD *)this + 151) &= ~0x100u;
        v11 = *((_DWORD *)this + 151);
        if ( v7->mUpdatedFromNIS )
        {
          PositionhkQ = Creature::GetPositionhkQ(mCreature, &result);
          mHavokCharacter = this->mHavokCharacter;
          position.m_quad = (__m128)PositionhkQ->m_translation;
          hkpRigidBody::setPosition(mHavokCharacter->m_character, &position);
          v13 = position.m_quad.m128_f32[2];
        }
        else
        {
          if ( (v11 & 0x80u) != 0 && (v11 & 0x40) != 0 && !UFG::CharacterPhysicsComponent::mDisableCurbHack )
            UFG::CharacterPhysicsComponent::MagicCurbBullShitHack(this);
          v12 = (*((_BYTE *)this + 604) & 8) == 0;
          v13 = position.m_quad.m128_f32[2] - this->mHeightFixup;
          position.m_quad.m128_f32[2] = v13;
          if ( !v12 )
          {
            v14 = Creature::GetPositionhkQ(mCreature, &result)->m_translation.m_quad.m128_f32[2];
            v15 = position.m_quad.m128_f32[2] - v14;
            if ( (float)(position.m_quad.m128_f32[2] - v14) <= 0.0 )
              v13 = (float)(UFG::CharacterPhysicsComponent::mZFilterValueDown * v15) + v14;
            else
              v13 = (float)(UFG::CharacterPhysicsComponent::mZFilterValueUp * v15) + v14;
            position.m_quad.m128_f32[2] = v13;
          }
        }
        if ( !sDontUpdate )
        {
          *(_QWORD *)&pos.x = position.m_quad.m128_u64[0];
          pos.z = v13;
          Creature::SetTranslation(mCreature, &pos);
          if ( !this->mRagdollComponent.m_pSimComponent )
            Creature::UpdateAttachmentPoses(mCreature);
        }
      }
    }
    v18 = this->m_pSimObject;
    if ( v18 )
      m_pTransformNodeComponent = v18->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      v19.m_quad = (__m128)this->mHavokCharacter->m_character->m_motion.m_linearVelocity;
      LODWORD(m_pTransformNodeComponent->mWorldVelocity.x) = v19.m_quad.m128_i32[0];
      LODWORD(m_pTransformNodeComponent->mWorldVelocity.z) = _mm_shuffle_ps(v19.m_quad, v19.m_quad, 170).m128_u32[0];
      LODWORD(m_pTransformNodeComponent->mWorldVelocity.y) = _mm_shuffle_ps(v19.m_quad, v19.m_quad, 85).m128_u32[0];
    }
    this->UFG::BasePhysicsObject::vfptr->DebugDraw(&this->UFG::BasePhysicsObject);
  }
}

// File Line: 1426
// RVA: 0x468630
// local variable allocation has failed, the output may be wrong!
void __fastcall UFG::CharacterPhysicsComponent::GrappleFixup(
        UFG::CharacterPhysicsComponent *this,
        float deltaT,
        double a3)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  __m128 v8; // xmm7
  UFG::SimObjectCVBase *v9; // rcx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  __int16 v11; // dx
  Creature *mCreature; // rcx
  hkVector4f v13; // xmm1
  __m128 v14; // xmm2
  hkQsTransformf result; // [rsp+20h] [rbp-58h] BYREF

  if ( (this->m_Flags & 3) == 1 && this->mGrappleState == 1 )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mGrapplePartner.m_pPointer;
    if ( m_pPointer )
    {
      if ( deltaT > 0.0 )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pPointer->m_Components.p[27].m_pComponent;
        }
        else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        v8 = (__m128)m_pComponent[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev[26];
        v9 = (UFG::SimObjectCVBase *)this->mGrapplePartner.m_pPointer;
        if ( v9 )
        {
          v11 = v9->m_Flags;
          if ( (v11 & 0x4000) != 0 || v11 < 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
          }
          else if ( (v11 & 0x2000) != 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
          }
          else if ( (v11 & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v9,
                                                                      UFG::CharacterAnimationComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v9,
                                                                      UFG::CharacterAnimationComponent::_TypeUID);
          }
        }
        else
        {
          ComponentOfTypeHK = 0i64;
        }
        mCreature = ComponentOfTypeHK->mCreature;
        if ( mCreature )
        {
          v13.m_quad = (__m128)Creature::GetPositionhkQ(mCreature, &result)->m_translation;
          this->mAdditiveVelocity.z = 0.0;
          *(float *)&a3 = (float)(-1.0 / deltaT) * 0.2;
          v14 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a3, *(__m128 *)&a3, 0), _mm_sub_ps(v13.m_quad, v8));
          LODWORD(this->mAdditiveVelocity.x) = v14.m128_i32[0];
          LODWORD(this->mAdditiveVelocity.y) = _mm_shuffle_ps(v14, v14, 85).m128_u32[0];
        }
      }
    }
  }
}

// File Line: 1469
// RVA: 0x46BE00
void __fastcall UFG::CharacterPhysicsComponent::MagicCurbBullShitHack(UFG::CharacterPhysicsComponent *this)
{
  CharacterRigidBody *mHavokCharacter; // rax
  __m128 m_quad; // xmm7
  __m128 v4; // xmm0
  float v5; // xmm6_4
  char *v6; // rbx
  UFG::RayCastData *v7; // rdi
  __int64 v8; // rsi
  UFG::RayCastData *v9; // rbx
  __int64 v10; // rdi
  unsigned int v11; // r14d
  unsigned int v12; // ecx
  int v13; // r13d
  char *v14; // r12
  unsigned int v15; // edx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  unsigned __int64 v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // r15
  UFG::allocator::free_link *v21; // rdx
  __int64 v22; // rcx
  unsigned int v23; // r8d
  unsigned int v24; // r14d
  __int64 v25; // r9
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  unsigned int v29; // r9d
  __int64 v30; // r8
  __int64 v31; // rdx
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  __int64 v35; // rcx
  float v36; // xmm8_4
  __m128 v37; // xmm9
  float v38; // xmm10_4
  __m128 v39; // xmm2
  float *v40; // rax
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
  __m128 v52; // [rsp+30h] [rbp-98h]
  _BYTE rayEnd[24]; // [rsp+40h] [rbp-88h] BYREF
  __m256i direction_8; // [rsp+58h] [rbp-70h] BYREF
  __int64 quat_8; // [rsp+78h] [rbp-50h]
  char ptr[144]; // [rsp+88h] [rbp-40h] BYREF
  char v57; // [rsp+118h] [rbp+50h] BYREF
  char v58; // [rsp+138h] [rbp+70h] BYREF
  __int64 v59; // [rsp+9E8h] [rbp+920h]
  char *v60; // [rsp+9F8h] [rbp+930h]

  quat_8 = -2i64;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  if ( this->mHavokCharacter )
  {
    *(__m128 *)&direction_8.m256i_u64[1] = _xmm;
    hkQuaternionf::setAxisAngle(
      (hkQuaternionf *)&direction_8.m256i_u64[3],
      (hkVector4f *)&direction_8.m256i_u64[1],
      this->mFacing);
    mHavokCharacter = this->mHavokCharacter;
    m_quad = mHavokCharacter->m_character->m_motion.m_motionState.m_transform.m_translation.m_quad;
    *(_QWORD *)&rayEnd[16] = mHavokCharacter->m_character->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_u64[0];
    *(__m128 *)&direction_8.m256i_u64[2] = _mm_add_ps((__m128)_xmm, m_quad);
    v4 = (__m128)_xmm;
    *(_OWORD *)direction_8.m256i_i8 = _xmm;
    hkVector4f::setRotatedDir(
      (hkVector4f *)rayEnd,
      (hkQuaternionf *)&direction_8.m256i_u64[3],
      (hkVector4f *)&direction_8);
    v5 = FLOAT_0_1;
    `eh vector constructor iterator(ptr, 0xE0ui64, 10, (void (__fastcall *)(void *))UFG::RayCastData::RayCastData);
    v6 = &v57;
    v7 = (UFG::RayCastData *)ptr;
    v8 = 10i64;
    do
    {
      v4.m128_f32[0] = v5;
      v52 = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), *(__m128 *)rayEnd);
      v52.m128_i32[2] = -1110651699;
      v4 = _mm_add_ps(v52, m_quad);
      *(__m128 *)&rayEnd[8] = v4;
      *(_QWORD *)v6 = "CurbHack";
      UFG::RayCastData::Init(v7, (hkVector4f *)&direction_8.m256i_u64[2], (hkVector4f *)&rayEnd[8], 0xEu);
      v5 = v5 + 0.1;
      ++v7;
      v6 += 224;
      --v8;
    }
    while ( v8 );
    v9 = (UFG::RayCastData *)ptr;
    v10 = 10i64;
    do
    {
      UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, v9++);
      --v10;
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
          operator delete[]((void *)v10);
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
                  v21->mNext = *(UFG::allocator::free_link **)((char *)v21 + v10 - (_QWORD)v19);
                  ++v21;
                  --v22;
                }
                while ( v22 );
              }
              operator delete[]((void *)v10);
            }
            v10 = (__int64)v20;
            v12 = v17;
            v15 = v11;
          }
        }
        ++v11;
        *(_QWORD *)(v10 + 8i64 * v15) = v60;
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
          v25 = v23 + 1;
          v26 = *(float *)(*(_QWORD *)(v10 + 8i64 * v23) + 164i64);
          v27 = *(float *)(*(_QWORD *)(v10 + 8 * v25) + 164i64) - v26;
          v28 = v26 - *(float *)direction_8.m256i_i32;
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
              v31 = *(_QWORD *)(v10 + 8i64 * (unsigned int)v30);
              v30 = (unsigned int)(v30 + 1);
              v32 = *(float *)(v31 + 164);
              v33 = *(float *)(*(_QWORD *)(v10 + 8 * v30) + 164i64) - v32;
              v34 = v32 - *(float *)direction_8.m256i_i32;
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
          v35 = *(_QWORD *)(v10 + 8i64 * v29);
          v36 = *(float *)(v35 + 156) - *(float *)&rayEnd[16];
          v37 = (__m128)*(unsigned int *)(v35 + 160);
          v37.m128_f32[0] = v37.m128_f32[0] - *(float *)&rayEnd[20];
          v38 = *(float *)(v35 + 164) - *(float *)direction_8.m256i_i32;
          v39 = v37;
          v39.m128_f32[0] = (float)((float)(v37.m128_f32[0] * v37.m128_f32[0]) + (float)(v36 * v36))
                          + (float)(v38 * v38);
          if ( _mm_sqrt_ps(v39).m128_f32[0] > 0.0 )
          {
            v40 = (float *)v59;
            *(_DWORD *)(v59 + 604) |= 0x100u;
            v41 = (__m128)*(unsigned int *)&rayEnd[4];
            v42 = (__m128)*(unsigned int *)rayEnd;
            v41.m128_f32[0] = (float)(*(float *)&rayEnd[4] * UFG::qVector3::msAxisZ.x)
                            - (float)(*(float *)rayEnd * UFG::qVector3::msAxisZ.y);
            v42.m128_f32[0] = (float)(*(float *)rayEnd * UFG::qVector3::msAxisZ.z)
                            - (float)(*(float *)&rayEnd[8] * UFG::qVector3::msAxisZ.x);
            v43 = (float)(*(float *)&rayEnd[8] * UFG::qVector3::msAxisZ.y)
                - (float)(*(float *)&rayEnd[4] * UFG::qVector3::msAxisZ.z);
            v44 = v42;
            v44.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v43 * v43))
                            + (float)(v41.m128_f32[0] * v41.m128_f32[0]);
            if ( v44.m128_f32[0] == 0.0 )
              v45 = 0.0;
            else
              v45 = 1.0 / _mm_sqrt_ps(v44).m128_f32[0];
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
              v51 = 1.0 / _mm_sqrt_ps(v50).m128_f32[0];
            v40[142] = v41.m128_f32[0] * v51;
            v40[143] = v49 * v51;
            v40[144] = v48 * v51;
          }
        }
      }
    }
LABEL_50:
    if ( v10 )
      operator delete[]((void *)v10);
LABEL_55:
    `eh vector destructor iterator(ptr, 0xE0ui64, 10, (void (__fastcall *)(void *))_);
  }
}

// File Line: 1629
// RVA: 0x4757C0
void __fastcall UFG::CharacterPhysicsComponent::SetVelocity(
        UFG::CharacterPhysicsComponent *this,
        UFG::qVector3 *velocity)
{
  UFG::SimObject *m_pSimObject; // rax
  CharacterRigidBody *mHavokCharacter; // rax
  hkpEntity *m_character; // rbx
  __m128 v5; // [rsp+20h] [rbp-18h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject || (m_pSimObject->m_Flags & 0x800) == 0 )
  {
    mHavokCharacter = this->mHavokCharacter;
    v5 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(velocity->x), (__m128)LODWORD(velocity->z)),
           _mm_unpacklo_ps((__m128)LODWORD(velocity->y), (__m128)0i64));
    m_character = mHavokCharacter->m_character;
    mHavokCharacter->m_acceleration.m_quad = _mm_mul_ps(
                                               _mm_sub_ps(v5, m_character->m_motion.m_linearVelocity.m_quad),
                                               (__m128)_xmm);
    hkpEntity::activate(m_character);
    m_character->m_motion.vfptr[9].__vecDelDtor(&m_character->m_motion, (unsigned int)&v5);
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
UFG::qVector3 *__fastcall UFG::CharacterPhysicsComponent::GetVelocity(
        UFG::CharacterPhysicsComponent *this,
        UFG::qVector3 *result)
{
  hkpRigidBody *m_character; // rcx
  UFG::qVector3 *v3; // rax
  __m128 m_quad; // xmm0

  m_character = this->mHavokCharacter->m_character;
  v3 = result;
  m_quad = m_character->m_motion.m_linearVelocity.m_quad;
  LODWORD(result->x) = m_quad.m128_i32[0];
  LODWORD(result->z) = m_character->m_motion.m_linearVelocity.m_quad.m128_i32[2];
  LODWORD(result->y) = _mm_shuffle_ps(m_quad, m_quad, 85).m128_u32[0];
  return v3;
}

// File Line: 1663
// RVA: 0x466870
float __fastcall UFG::CharacterPhysicsComponent::GetHeight(
        UFG::CharacterPhysicsComponent *this,
        UFG::CharacterCollisionMode model)
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
float __fastcall UFG::CharacterPhysicsComponent::GetRadius(
        UFG::CharacterPhysicsComponent *this,
        UFG::CharacterCollisionMode model)
{
  return this->mParam.mCollisionRadius[model];
}

// File Line: 1682
// RVA: 0x4749F0
void __fastcall UFG::CharacterPhysicsComponent::SetCollisionModel(
        UFG::CharacterPhysicsComponent *this,
        UFG::CharacterCollisionMode type)
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
  *((_DWORD *)this + 151) &= ~2u;
}

// File Line: 1703
// RVA: 0x46E930
void __fastcall UFG::CharacterPhysicsComponent::OnEnterWater(UFG::CharacterPhysicsComponent *this)
{
  CharacterRigidBody *mHavokCharacter; // rcx
  __m128 v3; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm1
  hkpEntity *m_character; // rbx
  __m128 v7; // [rsp+20h] [rbp-28h] BYREF

  mHavokCharacter = this->mHavokCharacter;
  v3 = _mm_mul_ps((__m128)_xmm, mHavokCharacter->m_character->m_motion.m_linearVelocity.m_quad);
  v4 = _mm_and_ps((__m128)xmmword_141687F20, v3);
  v7 = v3;
  v5 = _mm_or_ps(_mm_shuffle_ps(v4, v4, 78), v4);
  if ( COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 177).m128_u32[0] | v5.m128_i32[0]) < -15.0 )
  {
    v3 = _mm_or_ps(
           _mm_and_ps((__m128)_xmm_c1700000c1700000c1700000c1700000, (__m128)xmmword_141687F20),
           _mm_andnot_ps((__m128)xmmword_141687F20, v3));
    v7 = v3;
  }
  m_character = mHavokCharacter->m_character;
  mHavokCharacter->m_acceleration.m_quad = _mm_mul_ps(
                                             _mm_sub_ps(v3, m_character->m_motion.m_linearVelocity.m_quad),
                                             (__m128)_xmm);
  hkpEntity::activate(m_character);
  m_character->m_motion.vfptr[9].__vecDelDtor(&m_character->m_motion, (unsigned int)&v7);
  if ( this->mSpeedZ < -15.0 )
    this->mSpeedZ = -15.0;
  if ( this->mAdditiveVelocity.z < 0.0 )
    this->mAdditiveVelocity.z = 0.0;
  UFG::GameStatAction::Character::EnterWater(this->m_pSimObject);
}

// File Line: 1739
// RVA: 0x46AF80
bool __fastcall UFG::CharacterPhysicsComponent::IsInWater(UFG::CharacterPhysicsComponent *this)
{
  UFG::SimComponent *m_pPointer; // rax

  m_pPointer = this->mWaterTracker.m_pPointer;
  if ( m_pPointer )
    LOBYTE(m_pPointer) = SLODWORD(m_pPointer[1].m_BoundComponentHandles.mNode.mNext) > 0;
  return (char)m_pPointer;
}

// File Line: 1746
// RVA: 0x4683E0
float __fastcall UFG::CharacterPhysicsComponent::GetWaterElevation(UFG::CharacterPhysicsComponent *this)
{
  UFG::SimComponent *m_pPointer; // rax

  m_pPointer = this->mWaterTracker.m_pPointer;
  if ( m_pPointer )
    return *((float *)&m_pPointer[2].m_SafePointerList.mNode.mPrev + 1);
  else
    return FLOAT_N0_31400001;
}

// File Line: 1753
// RVA: 0x4648E0
void __fastcall UFG::CharacterPhysicsComponent::FireAsyncRaycasts(
        UFG::CharacterPhysicsComponent *this,
        int currentBucket)
{
  UFG::BasePhysicsSystemVtbl *vfptr; // rax
  hkVector4f v3; // xmm3
  float v4; // xmm0_4
  int v5[4]; // [rsp+40h] [rbp-28h] BYREF
  int v6; // [rsp+50h] [rbp-18h] BYREF
  int v7; // [rsp+54h] [rbp-14h]
  float v8; // [rsp+58h] [rbp-10h]

  if ( (*((_BYTE *)this + 604) & 2) != 0 || this->mAsyncRaycastBucket == currentBucket )
  {
    vfptr = UFG::BasePhysicsSystem::mInstance->vfptr;
    v3.m_quad = (__m128)this->mHavokCharacter->m_character->m_motion.m_motionState.m_transform.m_translation;
    v6 = v3.m_quad.m128_i32[0];
    v5[0] = v3.m_quad.m128_i32[0];
    v4 = _mm_shuffle_ps(v3.m_quad, v3.m_quad, 170).m128_f32[0];
    v7 = _mm_shuffle_ps(v3.m_quad, v3.m_quad, 85).m128_u32[0];
    v5[1] = v7;
    *(float *)&v5[2] = v4 - 4.0;
    v8 = v4 + 0.25;
    vfptr->CastAsyncRay(
      UFG::BasePhysicsSystem::mInstance,
      (UFG::qVector3 *)&v6,
      (UFG::qVector3 *)v5,
      12u,
      UFG::CharacterPhysicsComponent::DetailedOnGroundCheck,
      this,
      0i64);
  }
}

// File Line: 1770
// RVA: 0x461830
void __fastcall UFG::CharacterPhysicsComponent::DetailedOnGroundCheck(
        UFG::RayCastData *raycastData,
        UFG::SimComponent *simComponent,
        void *callbackUserData)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // eax
  float v6; // xmm1_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPhysicsSurfacePropertyHandleUid; // rax
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx

  if ( simComponent )
  {
    simComponent[9].m_NameUID |= 4u;
    if ( raycastData->hit )
    {
      *(float *)&simComponent[5].m_BoundComponentHandles.mNode.mPrev = *(float *)&simComponent[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev[26].mNext
                                                                     - raycastData->point.z;
      y = raycastData->point.y;
      z = raycastData->point.z;
      simComponent[5].m_TypeUID = LODWORD(raycastData->point.x);
      *(float *)&simComponent[5].m_NameUID = y;
      *(float *)&simComponent[5].m_Flags = z;
      x = raycastData->normal.x;
      v6 = raycastData->normal.z;
      *(float *)&simComponent[5].m_pSimObject = raycastData->normal.y;
      *(float *)(&simComponent[5].m_SimObjIndex + 1) = x;
      *((float *)&simComponent[5].m_pSimObject + 1) = v6;
      simComponent[6].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)raycastData->mPhysicsObjectPropertyHandleUid;
      mPhysicsSurfacePropertyHandleUid = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)raycastData->mPhysicsSurfacePropertyHandleUid;
    }
    else
    {
      LODWORD(simComponent[5].m_BoundComponentHandles.mNode.mPrev) = 1082130432;
      v8 = UFG::qVector3::msZero.z;
      mPhysicsSurfacePropertyHandleUid = 0i64;
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
    mPrev = simComponent[6].m_BoundComponentHandles.mNode.mPrev;
    simComponent[6].m_SafePointerList.mNode.mNext = mPhysicsSurfacePropertyHandleUid;
    LODWORD(mPrev[7].mNext) = simComponent[5].m_BoundComponentHandles.mNode.mPrev;
  }
}

// File Line: 1801
// RVA: 0x475370
void __fastcall UFG::CharacterPhysicsComponent::SetPairedGrappleMaster(
        UFG::CharacterPhysicsComponent *this,
        UFG::CharacterPhysicsComponent *slave,
        UFG::CharacterPhysicsComponent::GrappleMode mode)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mGrapplePartner; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx

  m_pSimObject = slave->m_pSimObject;
  p_mGrapplePartner = &this->mGrapplePartner;
  if ( this->mGrapplePartner.m_pPointer )
  {
    mPrev = p_mGrapplePartner->mPrev;
    mNext = this->mGrapplePartner.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mGrapplePartner->mPrev = p_mGrapplePartner;
    this->mGrapplePartner.mNext = &this->mGrapplePartner;
  }
  this->mGrapplePartner.m_pPointer = m_pSimObject;
  if ( m_pSimObject )
  {
    v8 = m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    p_mNode = &m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v8->mNext = p_mGrapplePartner;
    p_mGrapplePartner->mPrev = v8;
    this->mGrapplePartner.mNext = p_mNode;
    p_mNode->mPrev = p_mGrapplePartner;
  }
  this->mGrappleState = 1;
  this->mDesiredCollisionModelType = (mode != GRAPPLE_REGULAR) + 10;
}

// File Line: 1811
// RVA: 0x4753E0
void __fastcall UFG::CharacterPhysicsComponent::SetPairedGrappleSlave(
        UFG::CharacterPhysicsComponent *this,
        UFG::CharacterPhysicsComponent *master)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mGrapplePartner; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx

  m_pSimObject = master->m_pSimObject;
  p_mGrapplePartner = &this->mGrapplePartner;
  if ( this->mGrapplePartner.m_pPointer )
  {
    mPrev = p_mGrapplePartner->mPrev;
    mNext = this->mGrapplePartner.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mGrapplePartner->mPrev = p_mGrapplePartner;
    this->mGrapplePartner.mNext = &this->mGrapplePartner;
  }
  this->mGrapplePartner.m_pPointer = m_pSimObject;
  if ( m_pSimObject )
  {
    v7 = m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    p_mNode = &m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v7->mNext = p_mGrapplePartner;
    p_mGrapplePartner->mPrev = v7;
    this->mGrapplePartner.mNext = p_mNode;
    p_mNode->mPrev = p_mGrapplePartner;
  }
  this->mGrappleState = 2;
}

// File Line: 1819
// RVA: 0x45A690
void __fastcall UFG::CharacterPhysicsComponent::ClearPairedGrapple(UFG::CharacterPhysicsComponent *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mGrapplePartner; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  bool v4; // zf

  p_mGrapplePartner = &this->mGrapplePartner;
  if ( this->mGrapplePartner.m_pPointer )
  {
    mPrev = p_mGrapplePartner->mPrev;
    mNext = this->mGrapplePartner.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mGrapplePartner->mPrev = p_mGrapplePartner;
    this->mGrapplePartner.mNext = &this->mGrapplePartner;
  }
  this->mGrapplePartner.m_pPointer = 0i64;
  v4 = this->mGrappleState == 1;
  this->mGrappleState = 0;
  if ( v4 )
    this->mDesiredCollisionModelType = CP_WALK;
}

// File Line: 1834
// RVA: 0x46D7F0
void __fastcall UFG::CharacterPhysicsComponent::NotifyProxyModeChanged(
        UFG::CharacterPhysicsComponent *this,
        UFG::SimObject::eProxyMode proxyMode)
{
  bool v2; // zf
  hkpRigidBody *m_character; // rdx
  hkpWorld *m_world; // rcx

  v2 = proxyMode == ePM_PROXY_REMOTE_PHYSICS;
  m_character = this->mHavokCharacter->m_character;
  m_world = m_character->m_world;
  m_character->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = 1;
  if ( v2 )
  {
    if ( m_world )
      hkpWorld::updateCollisionFilterOnEntity(
        m_world,
        m_character,
        HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
        HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
    this->mGravity = 0.0;
    *((_DWORD *)this + 151) |= 1u;
  }
  else
  {
    if ( m_world )
      hkpWorld::updateCollisionFilterOnEntity(
        m_world,
        m_character,
        HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
        HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
    this->mGravity = -9.8100004;
    *((_DWORD *)this + 151) &= ~1u;
  }
}

// File Line: 2067
// RVA: 0x475DC0
void UFG::CharacterPhysicsComponentManager::Shutdown(void)
{
  UFG::CharacterPhysicsComponentManager *v0; // rdi
  UFG::CharacterPhysicsComponentManager::ShapeCacheEntry *p; // rcx
  hkpShape **p_shape; // rbx

  v0 = UFG::CharacterPhysicsComponentManager::mInstance;
  if ( UFG::CharacterPhysicsComponentManager::mInstance )
  {
    p = UFG::CharacterPhysicsComponentManager::mInstance->mCollisionShapeCache.p;
    if ( p )
    {
      p_shape = &p[-1].shape;
      `eh vector destructor iterator(
        p,
        0x70ui64,
        (int)p[-1].shape,
        (void (__fastcall *)(void *))UFG::CharacterPhysicsComponentManager::ShapeCacheEntry::~ShapeCacheEntry);
      operator delete[](p_shape);
    }
    v0->mCollisionShapeCache.p = 0i64;
    *(_QWORD *)&v0->mCollisionShapeCache.size = 0i64;
    operator delete[](v0);
  }
  UFG::CharacterPhysicsComponentManager::mInstance = 0i64;
}

// File Line: 2081
// RVA: 0x477B20
void __fastcall UFG::CharacterPhysicsComponentManager::Update(
        UFG::CharacterPhysicsComponentManager *this,
        float deltaT)
{
  UFG::CharacterPhysicsComponent *p_mNext; // rcx
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v4; // rbx
  int v5; // eax

  p_mNext = (UFG::CharacterPhysicsComponent *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext;
  if ( &UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext != (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> **)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList - 104) )
  {
    do
    {
      v4 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&p_mNext->mNext[-7].mNext;
      UFG::CharacterPhysicsComponent::FireAsyncRaycasts(p_mNext, this->mCurrentBucket);
      p_mNext = (UFG::CharacterPhysicsComponent *)v4;
    }
    while ( v4 != (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList
                                                                                                  - 104) );
  }
  v5 = ++this->mCurrentBucket;
  if ( v5 == 12 )
    v5 = 0;
  this->mCurrentBucket = v5;
}

// File Line: 2101
// RVA: 0x4673D0
hkpShape *__fastcall UFG::CharacterPhysicsComponentManager::GetShape(
        UFG::CharacterPhysicsComponentManager *this,
        UFG::CharacterCollisionMode model,
        float height,
        float radius)
{
  int v7; // r8d
  unsigned int size; // edx
  UFG::CharacterPhysicsComponentManager::ShapeCacheEntry *p; // rcx
  UFG::CharacterPhysicsComponentManager::ShapeCacheEntry *v10; // rax
  hkpShape *result; // rax
  unsigned int v12; // ebx
  UFG::qVector3 *v13; // rax
  float v14; // xmm8_4
  UFG::qVector3 *v15; // rax
  UFG::qVector3 *v16; // rax
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::qVector3 *v19; // rax
  float v20; // xmm3_4
  UFG::qVector3 *v21; // rax
  float v22; // xmm5_4
  UFG::qVector3 *v23; // rax
  UFG::qVector3 *v24; // rax
  UFG::qVector3 *v25; // rax
  UFG::qVector3 *v26; // rax
  UFG::qVector3 *v27; // rax
  UFG::qVector3 *v28; // rax
  UFG::qVector3 *v29; // rax
  UFG::qVector3 *v30; // rax
  UFG::qVector3 *v31; // rax
  UFG::qVector3 *v32; // rax
  UFG::qVector3 *v33; // rax
  UFG::qVector3 *v34; // rax
  UFG::qVector3 *v35; // rax
  UFG::qVector3 *v36; // rax
  UFG::qVector3 *v37; // rax
  UFG::qVector3 *v38; // rax
  UFG::qVector3 *v39; // rax
  int v40; // r13d
  unsigned __int64 v41; // rax
  UFG::qVector3 *v42; // rax
  float v43; // xmm9_4
  __int64 v44; // r14
  __int64 v45; // rdi
  float v46; // xmm6_4
  float v47; // xmm0_4
  UFG::qVector3 *vertexBuffer; // rax
  __int64 v49; // rcx
  UFG::qVector3 *v50; // rax
  unsigned __int64 v51; // rdx
  UFG::qVector3 *v52; // rax
  _QWORD **Value; // rax
  hkpConvexVerticesShape *v54; // rax
  __int64 v55; // rax
  __int64 v56; // r14
  __int64 v57; // rsi
  unsigned int v58; // edi
  unsigned int capacity; // eax
  hkStridedVertices stridedVertsIn; // [rsp+20h] [rbp-79h] BYREF
  UFG::CharacterPhysicsComponentManager::ShapeCacheEntry planeEquationsOut; // [rsp+30h] [rbp-69h] BYREF
  int *p_numFacets; // [rsp+F8h] [rbp+5Fh]
  void *retaddr; // [rsp+118h] [rbp+7Fh]

  stridedVertsIn.m_vertices = (const float *)-2i64;
  v7 = 0;
  size = this->mCollisionShapeCache.size;
  if ( !this->mCollisionShapeCache.size )
    goto LABEL_10;
  p = this->mCollisionShapeCache.p;
  while ( 1 )
  {
    v10 = &p[v7];
    if ( v10->type == model
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(v10->height - height) & _xmm) < 0.0099999998
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(v10->radius - radius) & _xmm) < 0.0099999998
      && v10->numFacets == (_DWORD)retaddr )
    {
      break;
    }
    if ( ++v7 >= size )
      goto LABEL_10;
  }
  result = v10->shape;
  if ( !result )
  {
LABEL_10:
    stridedVertsIn.m_numVertices = 0;
    planeEquationsOut.vertexBuffer = (UFG::qVector3 *)0x8000000000000000i64;
    p_numFacets = &planeEquationsOut.numFacets;
    LODWORD(planeEquationsOut.stridedVerts.m_vertices) = 0x1FFFF;
    v12 = 1;
    *(_QWORD *)&planeEquationsOut.numFacets = &hkGeometry::`vftable;
    *(_QWORD *)&planeEquationsOut.stridedVerts.m_numVertices = 0i64;
    planeEquationsOut.planeEquations.m_data = (hkVector4f *)0x8000000000000000i64;
    *(_QWORD *)&planeEquationsOut.planeEquations.m_size = 0i64;
    planeEquationsOut.geom.vfptr = (hkBaseObjectVtbl *)0x8000000000000000i64;
    planeEquationsOut.height = height;
    planeEquationsOut.radius = radius;
    planeEquationsOut.numFacets = (int)retaddr;
    stridedVertsIn.m_striding = 12;
    switch ( model )
    {
      case CP_WALK:
        v40 = 2 * (_DWORD)retaddr + 2;
        v41 = 12i64 * v40;
        if ( !is_mul_ok(v40, 0xCui64) )
          v41 = -1i64;
        v42 = (UFG::qVector3 *)UFG::qMalloc(v41, "CharacterPhysicsVert_Cache", 0i64);
        p_numFacets = (int *)v42;
        planeEquationsOut.vertexBuffer = v42;
        stridedVertsIn.m_numVertices = 2 * (_DWORD)retaddr + 2;
        stridedVertsIn.m_vertices = &v42->x;
        *(_QWORD *)&v42->x = 0i64;
        v42->z = height - 0.050000001;
        v43 = 0.0;
        v44 = (int)retaddr;
        if ( (int)retaddr > 0 )
        {
          v45 = 0i64;
          do
          {
            v46 = sinf(v43) * radius;
            v47 = cosf(v43) * radius;
            vertexBuffer = planeEquationsOut.vertexBuffer;
            planeEquationsOut.vertexBuffer[v45 + 1].x = v46;
            vertexBuffer[v45 + 1].y = v47;
            vertexBuffer[v45 + 1].z = height - radius;
            v49 = v45 * 12 + 12i64 * (int)retaddr;
            v50 = planeEquationsOut.vertexBuffer;
            *(float *)((char *)&planeEquationsOut.vertexBuffer[1].x + v49) = v46;
            *(float *)((char *)&v50[1].y + v49) = v47;
            *(float *)((char *)&v50[1].z + v49) = radius;
            v43 = v43 + (float)(6.2831855 / (float)(int)retaddr);
            ++v45;
            --v44;
          }
          while ( v44 );
        }
        v51 = 2 * (int)retaddr + 1;
        v52 = planeEquationsOut.vertexBuffer;
        *(_QWORD *)&planeEquationsOut.vertexBuffer[v51].x = 0i64;
        v52[v51].z = 0.050000001;
        goto LABEL_30;
      case CP_CROUCH:
      case CP_DRIVING:
      case CP_ENTER_EXIT_VEHICLE:
      case CP_SITTING:
      case CP_COMBAT:
      case CP_GRAPPLE:
      case CP_GRAPPLE_SMALL:
      case CP_COVER:
      case CP_FREERUN:
        v13 = (UFG::qVector3 *)UFG::qMalloc(0xA8ui64, "CharacterPhysicsVert_Cache", 0i64);
        p_numFacets = (int *)v13;
        planeEquationsOut.vertexBuffer = v13;
        stridedVertsIn.m_numVertices = 14;
        stridedVertsIn.m_vertices = &v13->x;
        *(_QWORD *)&v13->x = 0i64;
        v13->z = height - 0.050000001;
        v14 = height - radius;
        v15 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[1].x = 0.0;
        v15[1].y = radius;
        v15[1].z = height - radius;
        v16 = planeEquationsOut.vertexBuffer;
        v17 = radius * 0.866;
        v18 = radius * 0.5;
        planeEquationsOut.vertexBuffer[2].z = v14;
        v16[2].y = radius * 0.5;
        if ( model == CP_GRAPPLE )
        {
          v16[2].x = v17 + 0.80000001;
          v19 = planeEquationsOut.vertexBuffer;
          planeEquationsOut.vertexBuffer[3].x = v17 + 0.80000001;
        }
        else if ( model == CP_GRAPPLE_SMALL )
        {
          v16[2].x = v17 + 0.40000001;
          v19 = planeEquationsOut.vertexBuffer;
          planeEquationsOut.vertexBuffer[3].x = v17 + 0.40000001;
        }
        else
        {
          v16[2].x = v17;
          v19 = planeEquationsOut.vertexBuffer;
          planeEquationsOut.vertexBuffer[3].x = v17;
        }
        v19[3].z = v14;
        v20 = radius * -0.5;
        v19[3].y = radius * -0.5;
        v21 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[4].x = 0.0;
        LODWORD(v21[4].y) = LODWORD(radius) ^ _xmm[0];
        v21[4].z = v14;
        v22 = radius * -0.866;
        v23 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[5].x = radius * -0.866;
        v23[5].y = radius * -0.5;
        v23[5].z = v14;
        v24 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[6].x = radius * -0.866;
        v24[6].y = v18;
        v24[6].z = v14;
        v25 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[7].x = 0.0;
        v25[7].y = radius;
        v25[7].z = radius;
        v26 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[8].y = v18;
        if ( model == CP_GRAPPLE )
        {
          v17 = v17 + 0.80000001;
        }
        else
        {
          if ( model != CP_GRAPPLE_SMALL )
          {
            v26[8].x = v17;
            v26[8].z = radius;
            v27 = planeEquationsOut.vertexBuffer;
            planeEquationsOut.vertexBuffer[9].z = radius;
            goto LABEL_22;
          }
          v17 = v17 + 0.40000001;
        }
        v26[8].x = v17;
        v26[8].z = radius + 0.5;
        v27 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[9].z = radius + 0.5;
LABEL_22:
        v27[9].y = v20;
        v27[9].x = v17;
        v28 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[10].x = 0.0;
        LODWORD(v28[10].y) = LODWORD(radius) ^ _xmm[0];
        v28[10].z = radius;
        v29 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[11].x = v22;
        v29[11].y = v20;
        v29[11].z = radius;
        v30 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[12].x = v22;
        v30[12].y = v18;
        v30[12].z = radius;
        v31 = planeEquationsOut.vertexBuffer;
        *(_QWORD *)&planeEquationsOut.vertexBuffer[13].x = 0i64;
        v31[13].z = 0.050000001;
LABEL_30:
        hkGeometryUtility::createConvexGeometry(
          &stridedVertsIn,
          (hkGeometry *)&planeEquationsOut.numFacets,
          (hkArray<hkVector4f,hkContainerHeapAllocator> *)&planeEquationsOut);
        stridedVertsIn.m_numVertices = (int)planeEquationsOut.planeEquations.m_data;
        stridedVertsIn.m_striding = 16;
        stridedVertsIn.m_vertices = *(const float **)&planeEquationsOut.stridedVerts.m_numVertices;
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v54 = (hkpConvexVerticesShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                          Value[11],
                                          128i64);
        p_numFacets = (int *)v54;
        if ( v54 )
        {
          hkpConvexVerticesShape::hkpConvexVerticesShape(
            v54,
            &stridedVertsIn,
            (hkArray<hkVector4f,hkContainerHeapAllocator> *)&planeEquationsOut,
            0.050000001);
          v56 = v55;
        }
        else
        {
          v56 = 0i64;
        }
        *(_QWORD *)&planeEquationsOut.geom.m_memSizeAndFlags = v56;
        v57 = this->mCollisionShapeCache.size;
        v58 = v57 + 1;
        capacity = this->mCollisionShapeCache.capacity;
        if ( (int)v57 + 1 > capacity )
        {
          if ( capacity )
            v12 = 2 * capacity;
          for ( ; v12 < v58; v12 *= 2 )
            ;
          if ( v12 - v58 > 0x10000 )
            v12 = v57 + 65537;
          UFG::qArray<UFG::CharacterPhysicsComponentManager::ShapeCacheEntry,0>::Reallocate(
            &this->mCollisionShapeCache,
            v12,
            "qArray.Add");
        }
        this->mCollisionShapeCache.size = v58;
        UFG::CharacterPhysicsComponentManager::ShapeCacheEntry::operator=(
          &this->mCollisionShapeCache.p[v57],
          &planeEquationsOut);
        hkGeometry::~hkGeometry((hkGeometry *)&planeEquationsOut.numFacets);
        LODWORD(planeEquationsOut.vertexBuffer) = 0;
        if ( SHIDWORD(planeEquationsOut.vertexBuffer) >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)&planeEquationsOut.radius,
            16 * HIDWORD(planeEquationsOut.vertexBuffer));
        return (hkpShape *)v56;
      case CP_CRAWL:
      case CP_DISABLED:
      case CP_DEAD:
        v32 = (UFG::qVector3 *)UFG::qMalloc(0x60ui64, "CharacterPhysicsVert_Cache", 0i64);
        p_numFacets = (int *)v32;
        planeEquationsOut.vertexBuffer = v32;
        stridedVertsIn.m_numVertices = 8;
        stridedVertsIn.m_vertices = &v32->x;
        *(_QWORD *)&v32->x = 0i64;
        v32->z = height - 0.050000001;
        v33 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[1].x = 0.0;
        v33[1].y = radius;
        v33[1].z = height * 0.5;
        v34 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[2].x = radius * 0.866;
        v34[2].y = radius * 0.5;
        v34[2].z = height * 0.5;
        v35 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[3].x = radius * 0.866;
        v35[3].y = radius * -0.5;
        v35[3].z = height * 0.5;
        v36 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[4].x = 0.0;
        LODWORD(v36[4].y) = LODWORD(radius) ^ _xmm[0];
        v36[4].z = height * 0.5;
        v37 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[5].x = radius * -0.866;
        v37[5].y = radius * -0.5;
        v37[5].z = height * 0.5;
        v38 = planeEquationsOut.vertexBuffer;
        planeEquationsOut.vertexBuffer[6].x = radius * -0.866;
        v38[6].y = radius * 0.5;
        v38[6].z = height * 0.5;
        v39 = planeEquationsOut.vertexBuffer;
        *(_QWORD *)&planeEquationsOut.vertexBuffer[7].x = 0i64;
        v39[7].z = 0.050000001;
        goto LABEL_30;
      default:
        goto LABEL_30;
    }
  }
  return result;
}

// File Line: 2325
// RVA: 0x4664D0
void __fastcall UFG::CharacterPhysicsComponentManager::GetEntitiesForBatchOperations(
        UFG::CharacterPhysicsComponentManager *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesToAdd,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesToRemove)
{
  UFG::BasePhysicsSystem *v3; // r14
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *p_mNext; // rcx
  hkpRigidBody *mPrev; // rdi
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v7; // rsi

  v3 = UFG::BasePhysicsSystem::mInstance;
  p_mNext = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext;
  if ( &UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext != (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> **)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList - 104) )
  {
    do
    {
      mPrev = (hkpRigidBody *)p_mNext[27].mNode.mPrev[2].mPrev;
      v7 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&p_mNext[7].mNode.mPrev[-7].mNext;
      if ( ((__int64)p_mNext[2].mNode.mPrev & 2) != 0 )
      {
        if ( mPrev->m_world )
          UFG::BasePhysicsSystem::RemoveEntity(v3, mPrev, 1);
      }
      else if ( !mPrev->m_world )
      {
        if ( entitiesToAdd->m_size == (entitiesToAdd->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, entitiesToAdd, 8);
        entitiesToAdd->m_data[entitiesToAdd->m_size++] = mPrev;
      }
      p_mNext = v7;
    }
    while ( v7 != (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList
                                                                                                  - 104) );
  }
}

// File Line: 2353
// RVA: 0x473960
void __fastcall UFG::CharacterPhysicsComponentManager::ResetScene(UFG::CharacterPhysicsComponentManager *this)
{
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *p_mNext; // rsi
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *mNext; // rbx
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v3; // rdi
  UFG::RippleGenerator *v4; // rcx
  hkpAction *mPrev; // rdx
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v6; // rcx

  p_mNext = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext;
  if ( &UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext != (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> **)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList - 104) )
  {
    do
    {
      mNext = p_mNext[11].mNode.mNext;
      v3 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&p_mNext[7].mNode.mPrev[-7].mNext;
      if ( mNext && SLODWORD(mNext[7].mNext) > 0 )
      {
        v4 = (UFG::RippleGenerator *)mNext[6].mNext;
        if ( v4 )
        {
          UFG::Water::RemoveRippleGenerator(v4);
          mNext[6].mNext = 0i64;
        }
        mPrev = (hkpAction *)mNext[9].mPrev;
        if ( mPrev )
        {
          UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, mPrev);
          v6 = mNext[9].mPrev;
          if ( v6 )
            ((void (__fastcall *)(UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *, __int64))v6->mPrev->mPrev)(
              v6,
              1i64);
          mNext[9].mPrev = 0i64;
        }
        LODWORD(mNext[7].mNext) = 0;
        UFG::GameStatAction::Character::ExitWater((UFG::SimObject *)p_mNext[2].mNode.mNext);
      }
      p_mNext = v3;
    }
    while ( v3 != (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList
                                                                                                  - 104) );
  }
}

