// File Line: 109
// RVA: 0x1514390
__int64 dynamic_initializer_for__UFG::RagdollComponent::s_RagdollComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RagdollComponent::s_RagdollComponentList__);
}

// File Line: 110
// RVA: 0x466440
UFG::ComponentIDDesc *__fastcall UFG::RagdollComponent::GetDesc(UFG::RagdollComponent *this)
{
  return &UFG::RagdollComponent::_TypeIDesc;
}

// File Line: 185
// RVA: 0x44CD10
void __fastcall UFG::RagdollComponent::RagdollComponent(UFG::RagdollComponent *this, unsigned int name_uid)
{
  __int64 v3; // rsi
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *mConstraint; // rbx
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *mPrev; // rax
  UFG::Ragdoll *mRagdoll; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *mNext; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent>;
  this->mNext = &this->UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent>;
  UFG::qSafePointerNode<UFG::RagdollComponent>::qSafePointerNode<UFG::RagdollComponent>(&this->UFG::qSafePointerNode<UFG::RagdollComponent>);
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RagdollComponent::`vftable{for `UFG::SimComponent};
  this->UFG::qSafePointerNode<UFG::RagdollComponent>::vfptr = (UFG::qSafePointerNode<UFG::RagdollComponent>Vtbl *)&UFG::RagdollComponent::`vftable{for `UFG::qSafePointerNode<UFG::RagdollComponent>};
  this->mRagdoll = 0i64;
  this->mPose = 0i64;
  *(_QWORD *)&this->mRagDollWeight = 0i64;
  v3 = 4i64;
  this->mPoseState = STATE_UNINITIALIZED;
  *(_QWORD *)&this->mDesiredPoseState = 5i64;
  this->mDesiredLevelOfDetail = LOD_MEDIUM;
  this->mLockHighLOD = 0;
  this->mAnimPelvisBoneIndex = -1;
  *(_QWORD *)&this->mReferenceCount = 1i64;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&this->mAnimationComponent);
  mConstraint = this->mConstraint;
  `eh vector constructor iterator(
    this->mConstraint,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  mPrev = UFG::RagdollComponent::s_RagdollComponentList.mNode.mPrev;
  UFG::RagdollComponent::s_RagdollComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *)&UFG::RagdollComponent::s_RagdollComponentList;
  UFG::RagdollComponent::s_RagdollComponentList.mNode.mPrev = &this->UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent>;
  UFG::SimComponent::AddType(this, UFG::RagdollComponent::_RagdollComponentTypeUID, "RagdollComponent");
  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
    UFG::Ragdoll::AddToWorld(mRagdoll);
  this->m_Flags &= ~2u;
  ++UFG::RagdollComponent::mNumRagdollComponents;
  do
  {
    if ( mConstraint->m_pPointer )
    {
      v7 = mConstraint->mPrev;
      mNext = mConstraint->mNext;
      v7->mNext = mNext;
      mNext->mPrev = v7;
      mConstraint->mPrev = mConstraint;
      mConstraint->mNext = mConstraint;
    }
    mConstraint->m_pPointer = 0i64;
    ++mConstraint;
    --v3;
  }
  while ( v3 );
  this->mDebugDraw = 0;
}

// File Line: 206
// RVA: 0x450970
void __fastcall UFG::RagdollComponent::~RagdollComponent(UFG::RagdollComponent *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // r14
  UFG::Ragdoll *mRagdoll; // rcx
  SkeletalPose *mPose; // rbx
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *mPrev; // rcx
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *v9; // rcx
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *v10; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RagdollComponent::`vftable{for `UFG::SimComponent};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->UFG::qSafePointerNode<UFG::RagdollComponent>;
  this->UFG::qSafePointerNode<UFG::RagdollComponent>::vfptr = (UFG::qSafePointerNode<UFG::RagdollComponent>Vtbl *)&UFG::RagdollComponent::`vftable{for `UFG::qSafePointerNode<UFG::RagdollComponent>};
  UFG::RagdollComponent::ClearConstraints(this);
  --UFG::RagdollComponent::mNumRagdollComponents;
  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
  {
    UFG::Ragdoll::RemoveFromWorld(mRagdoll);
    UFG::RagdollFactory::ReleaseRagdoll(UFG::RagdollFactory::mInstance, this->mRagdoll);
  }
  mPose = this->mPose;
  if ( mPose )
  {
    SkeletalPose::~SkeletalPose(this->mPose);
    operator delete[](mPose);
  }
  if ( this == UFG::RagdollComponent::s_RagdollComponentpCurrentIterator )
    UFG::RagdollComponent::s_RagdollComponentpCurrentIterator = (UFG::RagdollComponent *)&this->mPrev[-6].mNext;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent>;
  this->mNext = &this->UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent>;
  `eh vector destructor iterator(
    this->mConstraint,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mAnimationComponent);
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::RagdollComponent>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  v7 = v2->m_SafePointerList.mNode.mPrev;
  v8 = v2->m_SafePointerList.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->m_SafePointerList.mNode.mPrev = &v2->m_SafePointerList.mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  v9 = this->mPrev;
  v10 = this->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->mPrev = &this->UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent>;
  this->mNext = &this->UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 227
// RVA: 0x470FD0
UFG::RagdollComponent *__fastcall UFG::RagdollComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::RagdollComponent *result; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SimComponent *v9; // rax
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v11; // ebx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_Ragdoll::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    result = (UFG::RagdollComponent *)UFG::qPropertySet::GetMemImagePtr(v5);
  else
    result = 0i64;
  if ( required || result )
  {
    v8 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x180ui64, "RagdollComponent", 0i64, 1u);
    if ( v8 )
    {
      UFG::RagdollComponent::RagdollComponent((UFG::RagdollComponent *)v8, pSceneObj->m_NameUID);
      v6 = v9;
    }
    m_pSimObject = pSceneObj->m_pSimObject;
    if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
      v11 = 42;
    else
      v11 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v12, m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v12, v6, v11);
    UFG::SimObjectModifier::Close(&v12);
    UFG::SimObjectModifier::~SimObjectModifier(&v12);
    return (UFG::RagdollComponent *)v6;
  }
  return result;
}

// File Line: 249
// RVA: 0x473BC0
void __fastcall UFG::RagdollComponent::ResetState(UFG::RagdollComponent *this)
{
  UFG::Ragdoll *mRagdoll; // rcx
  UFG::Ragdoll *v3; // rcx

  this->mDesiredPoseState = STATE_KEYFRAME_TRACKING;
  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
    UFG::Ragdoll::SetCollisionState(mRagdoll, CS_KEYFRAMED_RAGDOLL_LAYER_2);
  v3 = this->mRagdoll;
  if ( v3 )
    UFG::Ragdoll::ResetKeyframeControllerParams(v3);
}

// File Line: 262
// RVA: 0x46E030
void __fastcall UFG::RagdollComponent::OnAttach(UFG::RagdollComponent *this, UFG::SimObjectCharacter *object)
{
  if ( (object->m_Flags & 0x4000) != 0 )
  {
    UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::Bind<UFG::SimObjectCharacter>(
      &this->mAnimationComponent,
      object);
    if ( this->mAnimationComponent.m_pSimComponent )
      UFG::RagdollComponent::CreateMyRagdoll(this, object);
  }
}

// File Line: 291
// RVA: 0x46E800
void __fastcall UFG::RagdollComponent::OnDetach(UFG::RagdollComponent *this)
{
  UFG::Ragdoll *mRagdoll; // rcx
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_mAnimationComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax

  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
  {
    UFG::Ragdoll::RemoveFromWorld(mRagdoll);
    UFG::RagdollFactory::ReleaseRagdoll(UFG::RagdollFactory::mInstance, this->mRagdoll);
    this->mRagdoll = 0i64;
  }
  p_mAnimationComponent = &this->mAnimationComponent;
  if ( this->mAnimationComponent.m_pSimComponent )
  {
    mPrev = p_mAnimationComponent->mPrev;
    mNext = this->mAnimationComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mAnimationComponent.m_pSimComponent = 0i64;
LABEL_9:
    this->mAnimationComponent.m_pSimObject = 0i64;
    this->mAnimationComponent.mNext = &this->mAnimationComponent;
    p_mAnimationComponent->mPrev = p_mAnimationComponent;
    goto LABEL_10;
  }
  if ( this->mAnimationComponent.m_pSimObject
    && (p_mAnimationComponent->mPrev != p_mAnimationComponent
     || this->mAnimationComponent.mNext != &this->mAnimationComponent) )
  {
    v6 = p_mAnimationComponent->mPrev;
    v7 = this->mAnimationComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    goto LABEL_9;
  }
LABEL_10:
  this->mAnimationComponent.m_Changed = 1;
}

// File Line: 311
// RVA: 0x4764C0
void __fastcall UFG::RagdollComponent::Suspend(UFG::RagdollComponent *this)
{
  UFG::Ragdoll *mRagdoll; // rcx

  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
    UFG::Ragdoll::RemoveFromWorld(mRagdoll);
  this->m_Flags |= 2u;
}

// File Line: 323
// RVA: 0x473FA0
void __fastcall UFG::RagdollComponent::Restore(UFG::RagdollComponent *this)
{
  UFG::Ragdoll *mRagdoll; // rcx

  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
    UFG::Ragdoll::AddToWorld(mRagdoll);
  this->m_Flags &= ~2u;
}

// File Line: 335
// RVA: 0x45E1E0
void __fastcall UFG::RagdollComponent::CreateMyRagdoll(UFG::RagdollComponent *this, UFG::SimObjectGame *simObject)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::RagdollQuality quality; // ebp
  UFG::qPropertySet *v7; // rax
  char *MemImagePtr; // rsi
  UFG::qPropertySet *PropertySet; // rsi
  __int64 v10; // r14
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  unsigned __int16 mNext_high; // ax
  UFG::Ragdoll *v15; // rax
  bool v16; // zf

  m_pSceneObj = simObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  quality = RQ_STANDARD;
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_Ragdoll::sPropertyName,
         DEPTH_RECURSE);
  if ( v7 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v7);
  else
    MemImagePtr = 0i64;
  if ( !MemImagePtr )
  {
    PropertySet = UFG::PropertySetManager::FindPropertySet(&SimSymX_propset_componentRagdoll);
    if ( component_Ragdoll::IsClass(PropertySet->mSchemaName.mUID) )
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(PropertySet);
    else
      MemImagePtr = 0i64;
    quality = RQ_LOW;
  }
  v10 = *(_QWORD *)&this->mAnimationComponent.m_pSimComponent[2].m_TypeUID;
  if ( v10 )
  {
    m_Flags = simObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = simObject->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              simObject,
                              UFG::CharacterPhysicsComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(simObject, UFG::CharacterPhysicsComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
      mNext_high = HIWORD(m_pComponent[9].m_SafePointerList.mNode.mNext);
    else
      mNext_high = UFG::CustomCollisionFilter::GetUnusedSystemId(UFG::BasePhysicsSystem::mInstance->mCollisionFilter);
    v15 = UFG::RagdollFactory::AquireRagdoll(
            UFG::RagdollFactory::mInstance,
            *(Skeleton **)(v10 + 480),
            (component_Ragdoll *)MemImagePtr,
            mNext_high,
            quality);
    v16 = this->mDesiredPoseState == STATE_KEYFRAME_TRACKING;
    this->mRagdoll = v15;
    if ( v16 )
      UFG::Ragdoll::SetCollisionState(v15, CS_KEYFRAMED_RAGDOLL_LAYER_2);
    UFG::Ragdoll::SetUserData(this->mRagdoll, this);
    if ( (this->m_Flags & 2) == 0 )
      UFG::Ragdoll::AddToWorld(this->mRagdoll);
  }
}

// File Line: 379
// RVA: 0x1519EA0
__int64 UFG::_dynamic_initializer_for__gSymbip01Pelvis__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Pelvis", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymbip01Pelvis, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSymbip01Pelvis__);
}

// File Line: 382
// RVA: 0x47BDC0
void __fastcall UFG::RagdollComponent::Update(UFG::RagdollComponent *this, float deltaT)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::SimComponent *m_pComponent; // r13
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::TransformNodeComponent *v8; // rbx
  __m128 y_low; // xmm2
  float v10; // xmm0_4
  UFG::RagdollComponent::LevelOfDetail mDesiredLevelOfDetail; // eax
  UFG::Ragdoll *mRagdoll; // rcx
  Creature *v13; // r14
  SkeletalPose *mPose; // rbx
  int BoneID; // eax
  hkaSkeleton *mhkaSkeleton; // r15
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *SyncedPoseLocalSpace; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v18; // rax
  int v19; // r9d
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v20; // rdi
  __int64 v21; // r8
  hkQsTransformf *m_data; // rdx
  hkQsTransformf *v23; // rcx
  __int64 m_size; // rbx
  __int64 v25; // r12
  __int64 v26; // r14
  __int64 v27; // rbx
  __m128 *mPrev; // rcx
  __m128 v29; // xmm0
  UFG::RagdollComponent::PoseState mPoseState; // eax
  Creature *v31; // rbx
  UFG::RagdollComponent::PoseState v32; // eax
  float mVelocityFromProxyScale; // xmm6_4
  char v34; // di
  UFG::SimObjectGame *v35; // rcx
  UFG::SimComponent *v36; // rbx
  __int16 v37; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::RagdollComponent::PoseState mDesiredPoseState; // ecx
  __int32 v40; // ecx
  __int32 v41; // ecx
  UFG::Ragdoll *v42; // rcx
  UFG::RagdollComponent::PoseState v43; // eax
  hkQuaternionf v44; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 v; // [rsp+50h] [rbp-B0h] BYREF
  __m128 m_quad; // [rsp+60h] [rbp-A0h]
  __m128 v47; // [rsp+70h] [rbp-90h]
  hkQsTransformf result; // [rsp+80h] [rbp-80h] BYREF
  hkQsTransformf worldTransform; // [rsp+B0h] [rbp-50h] BYREF
  Creature *v50; // [rsp+130h] [rbp+30h]

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pSimObject,
                              UFG::CharacterPhysicsComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CharacterPhysicsComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( this->mAnimationComponent.m_pSimComponent )
  {
    if ( this->mLockHighLOD
      || UFG::RagdollComponent::mNumRagdollComponents < 32
      || (m_pTransformNodeComponent = this->m_pSimObject->m_pTransformNodeComponent,
          v8 = LocalPlayer->m_pTransformNodeComponent,
          UFG::TransformNodeComponent::UpdateWorldTransform(v8),
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent),
          y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y),
          v10 = m_pTransformNodeComponent->mWorldTransform.v3.z - v8->mWorldTransform.v3.z,
          y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v8->mWorldTransform.v3.y)
                                            * (float)(y_low.m128_f32[0] - v8->mWorldTransform.v3.y))
                                    + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                                    - v8->mWorldTransform.v3.x)
                                            * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                                    - v8->mWorldTransform.v3.x)))
                            + (float)(v10 * v10),
          _mm_sqrt_ps(y_low).m128_f32[0] <= gRagdollLodDistance) )
    {
      this->mDesiredLevelOfDetail = LOD_MEDIUM;
    }
    else
    {
      this->mDesiredLevelOfDetail = LOD_LOW;
    }
    mDesiredLevelOfDetail = this->mDesiredLevelOfDetail;
    if ( this->mLevelOfDetail != mDesiredLevelOfDetail )
    {
      if ( mDesiredLevelOfDetail == LOD_LOW )
      {
        mRagdoll = this->mRagdoll;
        if ( mRagdoll )
        {
          UFG::Ragdoll::RemoveFromWorld(mRagdoll);
          UFG::RagdollFactory::ReleaseRagdoll(UFG::RagdollFactory::mInstance, this->mRagdoll);
          this->mRagdoll = 0i64;
        }
      }
      if ( this->mDesiredLevelOfDetail == LOD_MEDIUM && !this->mRagdoll )
      {
        UFG::RagdollComponent::CreateMyRagdoll(this, (UFG::SimObjectGame *)this->m_pSimObject);
        this->mPoseState = STATE_UNINITIALIZED;
      }
      this->mLevelOfDetail = this->mDesiredLevelOfDetail;
    }
    if ( this->mRagdoll )
    {
      v13 = *(Creature **)&this->mAnimationComponent.m_pSimComponent[2].m_TypeUID;
      v50 = v13;
      if ( this->mAnimationComponent.m_Changed )
      {
        mPose = this->mPose;
        this->mAnimationComponent.m_Changed = 0;
        if ( mPose )
        {
          SkeletalPose::~SkeletalPose(mPose);
          operator delete[](mPose);
        }
        this->mPose = SkeletalPose::Clone(&v13->mPose);
        if ( v13->mPose.mRigHandle.mData )
          BoneID = Skeleton::GetBoneID(v13->mPose.mRigHandle.mUFGSkeleton, UFG::gSymbip01Pelvis.mUID);
        else
          BoneID = -1;
        this->mAnimPelvisBoneIndex = BoneID;
      }
      mhkaSkeleton = v13->mPose.mRigHandle.mUFGSkeleton->mhkaSkeleton;
      if ( this->mRagdoll && this->mLevelOfDetail != LOD_LOW )
      {
        SyncedPoseLocalSpace = hkaPose::getSyncedPoseLocalSpace(v13->mPose.mHavokPose);
        v18 = hkaPose::accessUnsyncedPoseLocalSpace(this->mPose->mHavokPose);
        v19 = 0;
        v20 = v18;
        if ( v18->m_size > 0 )
        {
          v21 = 0i64;
          do
          {
            m_data = SyncedPoseLocalSpace->m_data;
            v23 = v18->m_data;
            ++v19;
            ++v21;
            v23[v21 - 1].m_translation = SyncedPoseLocalSpace->m_data[v21 - 1].m_translation;
            v23[v21 - 1].m_rotation = m_data[v21 - 1].m_rotation;
            v23[v21 - 1].m_scale = m_data[v21 - 1].m_scale;
          }
          while ( v19 < v18->m_size );
        }
        m_size = v18->m_size;
        hkQsTransform_fasterRenormalizeBatch(v18->m_data, v18->m_size);
        v25 = m_size;
        if ( (int)m_size > 0 )
        {
          v26 = 0i64;
          v27 = 0i64;
          do
          {
            v44.m_vec.m_quad = (__m128)v20->m_data[v27].m_rotation;
            if ( !hkQuaternionf::isOk(&v44, 0.001) )
            {
              UFG::qPrintf(
                "RagdollComponent.cpp.  Bad rotation on input animation.  Skeleton %s Bone %s (%f,%f,%f,%f)",
                (const char *)((unsigned __int64)mhkaSkeleton->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                (const char *)((unsigned __int64)mhkaSkeleton->m_bones.m_data[v26].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                v44.m_vec.m_quad.m128_f32[0],
                v44.m_vec.m_quad.m128_f32[1],
                v44.m_vec.m_quad.m128_f32[2],
                v44.m_vec.m_quad.m128_f32[3]);
              v44.m_vec.m_quad = qi.m_vec.m_quad;
            }
            m_quad = v20->m_data[v27].m_translation.m_quad;
            if ( (_mm_movemask_ps(_mm_cmpunord_ps(m_quad, m_quad)) & 7) != 0 )
              UFG::qPrintf(
                "RagdollComponent.cpp.  Bad translation on input animation. Skeleton %s Bone %s (%f,%f,%f)",
                (const char *)((unsigned __int64)mhkaSkeleton->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                (const char *)((unsigned __int64)mhkaSkeleton->m_bones.m_data[v26].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                m_quad.m128_f32[0],
                m_quad.m128_f32[1],
                m_quad.m128_f32[2]);
            v47 = v20->m_data[v27].m_scale.m_quad;
            if ( (_mm_movemask_ps(_mm_cmpunord_ps(v47, v47)) & 7) != 0 )
              UFG::qPrintf(
                "RagdollComponent.cpp.  Bad scale on input animation. Skeleton %s Bone %s (%f,%f,%f)",
                (const char *)((unsigned __int64)mhkaSkeleton->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                (const char *)((unsigned __int64)mhkaSkeleton->m_bones.m_data[v26].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                v47.m128_f32[0],
                v47.m128_f32[1],
                v47.m128_f32[2]);
            ++v27;
            ++v26;
            --v25;
          }
          while ( v25 );
          v13 = v50;
        }
      }
      Creature::GetPositionhkQ(v13, &result);
      if ( m_pComponent )
      {
        mPrev = (__m128 *)m_pComponent[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
        v29 = mPrev[35];
        v44.m_vec.m_quad.m128_i32[0] = v29.m128_i32[0];
        v44.m_vec.m_quad.m128_i32[2] = mPrev[35].m128_i32[2];
        v44.m_vec.m_quad.m128_i32[1] = _mm_shuffle_ps(v29, v29, 85).m128_u32[0];
      }
      else
      {
        v44.m_vec.m_quad.m128_u64[0] = *(_QWORD *)&UFG::qVector3::msZero.x;
        v44.m_vec.m_quad.m128_i32[2] = LODWORD(UFG::qVector3::msZero.z);
      }
      *(_QWORD *)&v.x = v44.m_vec.m_quad.m128_u64[0];
      mPoseState = this->mPoseState;
      LODWORD(v.z) = v44.m_vec.m_quad.m128_i32[2];
      if ( mPoseState == this->mDesiredPoseState )
      {
LABEL_82:
        if ( deltaT <= 0.0 )
          return;
        v43 = this->mPoseState;
        if ( v43 )
        {
          if ( v43 != STATE_POWERED_TRACKING )
          {
            if ( v43 > STATE_TRANSITION_TO_POWERED )
            {
              if ( v43 <= STATE_UNINITIALIZED )
              {
                ++this->mNumFramesInKeyframedMode;
                UFG::Ragdoll::ForcePose(this->mRagdoll, mhkaSkeleton, this->mPose->mHavokPose, &result);
                UFG::Ragdoll::SetVelocity(this->mRagdoll, &v);
              }
              else if ( v43 == STATE_KEYFRAME_TRACKING )
              {
                UFG::Ragdoll::UpdateVelocityTracking(
                  this->mRagdoll,
                  mhkaSkeleton,
                  this->mPose->mHavokPose,
                  &result,
                  deltaT);
              }
            }
            return;
          }
          UFG::Ragdoll::UpdatePoweredTracking(this->mRagdoll, mhkaSkeleton, this->mPose->mHavokPose);
          UFG::Ragdoll::DampMotionOfExtremities(this->mRagdoll, deltaT);
        }
        else
        {
          UFG::Ragdoll::UpdateVelocityTracking(this->mRagdoll, mhkaSkeleton, this->mPose->mHavokPose, &result, deltaT);
        }
        this->mNumFramesInKeyframedMode = 0;
        return;
      }
      if ( mPoseState == STATE_UNINITIALIZED )
      {
        v31 = *(Creature **)&this->mAnimationComponent.m_pSimComponent[2].m_TypeUID;
        Creature::GetPositionhkQ(v31, &worldTransform);
        UFG::Ragdoll::ForcePose(
          this->mRagdoll,
          v31->mPose.mRigHandle.mUFGSkeleton->mhkaSkeleton,
          this->mPose->mHavokPose,
          &worldTransform);
      }
      v32 = this->mPoseState;
      mVelocityFromProxyScale = this->mVelocityFromProxyScale;
      v34 = 0;
      if ( v32 == STATE_POWERED_TRACKING )
      {
        UFG::Ragdoll::ShutdownPoweredTracking(this->mRagdoll);
      }
      else if ( (unsigned int)(v32 - 3) <= 1 )
      {
        mVelocityFromProxyScale = *(float *)&FLOAT_1_0;
        v34 = 1;
      }
      v35 = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( v35 )
      {
        v37 = v35->m_Flags;
        if ( (v37 & 0x4000) != 0 )
        {
          v36 = v35->m_Components.p[13].m_pComponent;
        }
        else if ( v37 >= 0 )
        {
          if ( (v37 & 0x2000) != 0 || (v37 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::AnimationLODComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(v35, UFG::AnimationLODComponent::_TypeUID);
          v36 = ComponentOfType;
        }
        else
        {
          v36 = v35->m_Components.p[13].m_pComponent;
        }
      }
      else
      {
        v36 = 0i64;
      }
      mDesiredPoseState = this->mDesiredPoseState;
      if ( mDesiredPoseState )
      {
        v40 = mDesiredPoseState - 1;
        if ( v40 )
        {
          v41 = v40 - 2;
          if ( v41 )
          {
            if ( v41 == 2 )
            {
              UFG::Ragdoll::SetCollisionState(this->mRagdoll, CS_KEYFRAMED_RAGDOLL_LAYER_2);
              UFG::Ragdoll::SetControlData(this->mRagdoll);
              UFG::Ragdoll::EnableConstraints(this->mRagdoll);
              LOBYTE(v36[4].m_BoundComponentHandles.mNode.mNext) &= ~8u;
            }
          }
          else
          {
            UFG::Ragdoll::SetCollisionState(this->mRagdoll, CS_KEYFRAMED_RAGDOLL_LAYER_2);
            UFG::Ragdoll::SetControlData(this->mRagdoll);
            UFG::Ragdoll::DisableConstraints(this->mRagdoll);
            LOBYTE(v36[4].m_BoundComponentHandles.mNode.mNext) &= ~8u;
          }
          goto LABEL_79;
        }
        UFG::Ragdoll::SetCollisionState(this->mRagdoll, CS_DYNAMIC);
        UFG::Ragdoll::SetControlData(this->mRagdoll);
        UFG::Ragdoll::EnableConstraints(this->mRagdoll);
        UFG::Ragdoll::InitializePoweredTracking(this->mRagdoll);
      }
      else
      {
        UFG::Ragdoll::SetCollisionState(this->mRagdoll, CS_DYNAMIC);
        UFG::Ragdoll::SetControlData(this->mRagdoll);
        UFG::Ragdoll::EnableConstraints(this->mRagdoll);
        UFG::Ragdoll::InitializeVelocityTracking(this->mRagdoll);
      }
      LOBYTE(v36[4].m_BoundComponentHandles.mNode.mNext) |= 8u;
LABEL_79:
      if ( v34 )
      {
        v42 = this->mRagdoll;
        v44.m_vec.m_quad.m128_f32[0] = v.x * mVelocityFromProxyScale;
        v44.m_vec.m_quad.m128_f32[1] = v.y * mVelocityFromProxyScale;
        v44.m_vec.m_quad.m128_f32[2] = v.z * mVelocityFromProxyScale;
        UFG::Ragdoll::SetVelocity(v42, (UFG::qVector3 *)&v44);
      }
      this->mPoseState = this->mDesiredPoseState;
      goto LABEL_82;
    }
  }
}

// File Line: 750
// RVA: 0x480460
void __fastcall UFG::RagdollComponent::UpdateTransforms(UFG::RagdollComponent *this)
{
  UFG::RagdollComponent::PoseState mPoseState; // ecx
  __int32 v3; // ecx
  __int32 v4; // ecx
  __int64 mAnimPelvisBoneIndex; // rdx
  hkaPose *mHavokPose; // r8
  hkQsTransformf *v7; // rax
  UFG::Ragdoll *mRagdoll; // rcx
  UFG::qMatrix44 *v9; // rax
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  UFG::qVector4 v12; // xmm0
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-138h] BYREF
  hkQsTransformf v14; // [rsp+60h] [rbp-F8h] BYREF
  UFG::qMatrix44 d; // [rsp+90h] [rbp-C8h] BYREF
  UFG::qMatrix44 v16; // [rsp+D0h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+110h] [rbp-48h] BYREF

  if ( (this->m_Flags & 3) != 1 )
    return;
  Creature::GetTransform(*(Creature **)&this->mAnimationComponent.m_pSimComponent[2].m_TypeUID, &transform);
  mPoseState = this->mPoseState;
  if ( mPoseState == STATE_VELOCITY_TRACKING )
  {
LABEL_13:
    UFG::RagdollComponent::FeedPoseIntoCreature(this, &transform);
    return;
  }
  v3 = mPoseState - 1;
  if ( !v3 )
  {
    mAnimPelvisBoneIndex = this->mAnimPelvisBoneIndex;
    mHavokPose = this->mPose->mHavokPose;
    if ( (mHavokPose->m_boneFlags.m_data[mAnimPelvisBoneIndex] & 2) != 0 )
      v7 = hkaPose::calculateBoneModelSpace(this->mPose->mHavokPose, mAnimPelvisBoneIndex);
    else
      v7 = &mHavokPose->m_modelPose.m_data[mAnimPelvisBoneIndex];
    v14 = *v7;
    hkQsTransformf::get4x4ColumnMajor(&v14, &d.v0.x);
    UFG::qInverseAffine(&v16, &d);
    mRagdoll = this->mRagdoll;
    if ( mRagdoll )
      UFG::Ragdoll::GetPelvisTransformWS(mRagdoll, &this->mPelvisRagdollWS);
    v9 = UFG::qMatrix44::operator*(&v16, &result, &this->mPelvisRagdollWS);
    v10 = v9->v2;
    v11 = v9->v3;
    v12 = v9->v0;
    transform.v1 = v9->v1;
    transform.v2 = v10;
    transform.v0 = v12;
    transform.v3 = v11;
    goto LABEL_13;
  }
  v4 = v3 - 2;
  if ( !v4 || v4 == 2 )
    UFG::RagdollComponent::FeedProceduralBonesIntoCreature(this);
}

// File Line: 837
// RVA: 0x467060
hkArray<hkpRigidBody *,hkContainerHeapAllocator> *__fastcall UFG::RagdollComponent::GetRigidBodies(
        UFG::RagdollComponent *this)
{
  return &this->mRagdoll->mRagdollInstance->m_rigidBodies;
}

// File Line: 844
// RVA: 0x4585F0
void __fastcall UFG::RagdollComponent::ApplyImpulse(
        UFG::RagdollComponent *this,
        int bone,
        UFG::qVector3 *location,
        UFG::qVector3 *impulse)
{
  UFG::Ragdoll *mRagdoll; // rcx
  __m128 z_low; // xmm0
  __m128 y_low; // xmm2
  hkVector4f impulsea; // [rsp+20h] [rbp-28h] BYREF
  hkVector4f locationa; // [rsp+30h] [rbp-18h] BYREF

  mRagdoll = this->mRagdoll;
  z_low = (__m128)LODWORD(impulse->z);
  y_low = (__m128)LODWORD(impulse->y);
  locationa.m_quad = _mm_unpacklo_ps(
                       _mm_unpacklo_ps((__m128)LODWORD(location->x), (__m128)LODWORD(location->z)),
                       _mm_unpacklo_ps((__m128)LODWORD(location->y), (__m128)0i64));
  impulsea.m_quad = _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)LODWORD(impulse->x), z_low),
                      _mm_unpacklo_ps(y_low, (__m128)0i64));
  UFG::Ragdoll::ApplyImpulse(mRagdoll, bone, &locationa, &impulsea);
}

// File Line: 853
// RVA: 0x456310
void __fastcall UFG::RagdollComponent::ApplyAngularImpulse(
        UFG::RagdollComponent *this,
        int bone,
        UFG::qVector3 *impulse,
        float connectionTransfer)
{
  UFG::Ragdoll *mRagdoll; // rcx
  hkVector4f impulsea; // [rsp+20h] [rbp-18h] BYREF

  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
  {
    impulsea.m_quad = _mm_unpacklo_ps(
                        _mm_unpacklo_ps((__m128)LODWORD(impulse->x), (__m128)LODWORD(impulse->z)),
                        _mm_unpacklo_ps((__m128)LODWORD(impulse->y), (__m128)0i64));
    UFG::Ragdoll::ApplyAngularImpulse(mRagdoll, bone, &impulsea, connectionTransfer);
  }
}

// File Line: 864
// RVA: 0x463EE0
void __fastcall UFG::RagdollComponent::FeedPoseIntoCreature(
        UFG::RagdollComponent *this,
        UFG::qMatrix44 *worldTransform)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::Ragdoll *mRagdoll; // rcx
  Creature *v5; // rdi
  hkQsTransformf *TranslationMS; // rax
  SkeletalPose *mPose; // rcx
  hkQsTransformf *v9; // rax
  SkeletalPose *v10; // rcx
  hkQsTransformf *v11; // rax
  SkeletalPose *v12; // rcx
  hkQsTransformf *v13; // rax
  SkeletalPose *v14; // rcx
  UFG::Ragdoll *v15; // rcx
  hkQsTransformf *Root; // rax
  SkeletalPose *v17; // r8
  Skeleton *mUFGSkeleton; // rdx
  UFG::Ragdoll *v19; // rcx
  float mRagDollWeight; // xmm2_4
  hkQsTransformf worldTransforma; // [rsp+20h] [rbp-C8h] BYREF
  hkQsTransformf v22; // [rsp+50h] [rbp-98h] BYREF
  hkQsTransformf v23; // [rsp+80h] [rbp-68h] BYREF
  hkQsTransformf transformMS; // [rsp+B0h] [rbp-38h] BYREF

  m_pSimComponent = this->mAnimationComponent.m_pSimComponent;
  mRagdoll = this->mRagdoll;
  v5 = *(Creature **)&m_pSimComponent[2].m_TypeUID;
  if ( mRagdoll )
  {
    UFG::Ragdoll::GetPelvisTransformWS(mRagdoll, &this->mPelvisRagdollWS);
    TranslationMS = SkeletalPose::GetTranslationMS(this->mPose, 0);
    mPose = this->mPose;
    transformMS = *TranslationMS;
    v9 = SkeletalPose::GetTranslationMS(mPose, 1);
    v10 = this->mPose;
    v22 = *v9;
    v11 = SkeletalPose::GetTranslationMS(v10, 2);
    v12 = this->mPose;
    v23 = *v11;
    v13 = SkeletalPose::GetTranslationMS(v12, 3);
    v14 = this->mPose;
    worldTransforma = *v13;
    SkeletalPose::SetToRestPose(v14);
    SkeletalPose::SetQsTransformMS(this->mPose, 0, &transformMS);
    SkeletalPose::SetQsTransformMS(this->mPose, 1, &v22);
    SkeletalPose::SetQsTransformMS(this->mPose, 2, &v23);
    SkeletalPose::SetQsTransformMS(this->mPose, 3, &worldTransforma);
  }
  v15 = this->mRagdoll;
  if ( v15 )
    UFG::Ragdoll::UpdateTotalInertia(v15);
  SkeletalPose::SetRoot(this->mPose, worldTransform, 0);
  if ( this->mRagdoll )
  {
    Root = SkeletalPose::GetRoot(this->mPose);
    v17 = this->mPose;
    mUFGSkeleton = v5->mPose.mRigHandle.mUFGSkeleton;
    v19 = this->mRagdoll;
    worldTransforma = *Root;
    UFG::Ragdoll::GetHighResPose(v19, mUFGSkeleton->mhkaSkeleton, v17->mHavokPose, &worldTransforma);
  }
  if ( gOverRideRagdollWeight )
    mRagDollWeight = gOverRideRagdollWeightValue;
  else
    mRagDollWeight = this->mRagDollWeight;
  Creature::BlendInPose(v5, this->mPose, mRagDollWeight, ((this->mPoseState - 1) & 0xFFFFFFFB) == 0);
}

// File Line: 932
// RVA: 0x4640E0
void __fastcall UFG::RagdollComponent::FeedProceduralBonesIntoCreature(UFG::RagdollComponent *this)
{
  UFG::Ragdoll *mRagdoll; // r13
  Creature *v2; // r12
  hkaRagdollInstance *mRagdollInstance; // r14
  UFG::RagdollData *m_pPointer; // r13
  __int64 m_size; // r15
  int v6; // ebx
  __int64 i; // rdi
  hkpRigidBody *v8; // rbp
  hkaSkeletonMapper *ragdollToHighResMapper; // rax
  __int64 v10; // rcx
  __int64 v11; // r8
  hkaSkeletonMapperData::SimpleMapping *m_data; // rdx
  int m_boneB; // esi
  __m128 m_quad; // xmm6
  __m128 v15; // xmm8
  __m128i inserted; // xmm0
  __m128 v17; // xmm7
  __m128 v18; // xmm1
  __m128 v19; // xmm5
  __m128 v20; // xmm3
  __m128i v21; // xmm11
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm10
  __m128 v25; // xmm1
  __m128 v26; // xmm10
  __m128 v27; // xmm6
  __m128 v28; // xmm7
  __m128 v29; // xmm10
  __m128 v30; // xmm6
  __m128 v31; // xmm2
  __m128 v32; // xmm10
  __m128 v33; // xmm6
  __m128 v34; // xmm6
  hkQsTransformf *TranslationMS; // rax
  __m128 v36; // xmm3
  __m128 v37; // xmm4
  __m128 m_proceduralBoneBlendWeight_low; // xmm2
  __m128 v39; // xmm2
  __m128 v40; // xmm11
  __m128 v41; // xmm10
  __m128 v42; // xmm0
  __m128 v43; // xmm1
  __m128 v44; // xmm7
  __m128 v45; // xmm6
  __m128 v46; // xmm0
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm7
  __m128 v51; // xmm3
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm5
  __m128 v56; // xmm2
  __m128 v57; // xmm2
  hkQsTransformf result; // [rsp+20h] [rbp-198h] BYREF
  hkQsTransformf v59; // [rsp+50h] [rbp-168h] BYREF
  hkVector4f v60; // [rsp+80h] [rbp-138h] BYREF
  UFG::qMatrix44 pos; // [rsp+B0h] [rbp-108h] BYREF
  float d[16]; // [rsp+F0h] [rbp-C8h] BYREF

  mRagdoll = this->mRagdoll;
  v2 = *(Creature **)&this->mAnimationComponent.m_pSimComponent[2].m_TypeUID;
  if ( mRagdoll && v2 )
  {
    mRagdollInstance = mRagdoll->mRagdollInstance;
    m_pPointer = mRagdoll->mRagdollData.m_pPointer;
    m_size = mRagdollInstance->m_rigidBodies.m_size;
    v6 = m_pPointer->mLastCoreRagdollBone + 1;
    for ( i = v6; i < m_size; ++v6 )
    {
      v8 = mRagdollInstance->m_rigidBodies.m_data[i];
      hkTransformf::get4x4ColumnMajor(&v8->m_motion.m_motionState.m_transform, d);
      ragdollToHighResMapper = m_pPointer->ragdollToHighResMapper;
      v10 = 0i64;
      v11 = ragdollToHighResMapper->m_mapping.m_simpleMappings.m_size;
      if ( v11 > 0 )
      {
        m_data = ragdollToHighResMapper->m_mapping.m_simpleMappings.m_data;
        while ( v6 != m_data->m_boneA )
        {
          ++v10;
          ++m_data;
          if ( v10 >= v11 )
            goto LABEL_11;
        }
        m_boneB = ragdollToHighResMapper->m_mapping.m_simpleMappings.m_data[v10].m_boneB;
        if ( m_boneB != -1 )
        {
          Creature::GetPositionhkQ(v2, &result);
          m_quad = v8->m_motion.m_motionState.m_transform.m_translation.m_quad;
          v15 = v8->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
          hkVector4f::setRotatedInverseDir(&v60, &result.m_rotation, &result.m_translation);
          inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
          v17 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), result.m_rotation.m_vec.m_quad);
          v18 = _mm_rcp_ps(result.m_scale.m_quad);
          v19 = _mm_shuffle_ps(v17, v17, 255);
          v20 = _mm_shuffle_ps(v17, v17, 201);
          v21 = _mm_slli_si128(
                  (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(result.m_scale.m_quad, v18)), v18),
                  4);
          v22 = _mm_mul_ps(v17, m_quad);
          v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v17), _mm_mul_ps(v20, m_quad));
          v24 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                  _mm_shuffle_ps(v22, v22, 170));
          v25 = v17;
          v26 = _mm_add_ps(
                  _mm_mul_ps(v24, v17),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v19, v19), (__m128)xmmword_141A711B0), m_quad));
          v27 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v17);
          v28 = _mm_mul_ps(v17, v15);
          v29 = _mm_add_ps(v26, _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v19));
          v30 = _mm_sub_ps(v27, _mm_mul_ps(v20, v15));
          v31 = _mm_shuffle_ps(v15, v15, 255);
          v32 = _mm_add_ps(_mm_add_ps(v29, v29), _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 0), v60.m_quad));
          v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 201), _mm_mul_ps(v15, v19)), _mm_mul_ps(v25, v31));
          v34 = _mm_shuffle_ps(
                  v33,
                  _mm_unpackhi_ps(
                    v33,
                    _mm_sub_ps(
                      _mm_mul_ps(v31, v19),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                        _mm_shuffle_ps(v28, v28, 170)))),
                  196);
          TranslationMS = SkeletalPose::GetTranslationMS(&v2->mPose, m_boneB);
          v36 = TranslationMS->m_rotation.m_vec.m_quad;
          v37 = _mm_shuffle_ps(result.m_rotation.m_vec.m_quad, result.m_rotation.m_vec.m_quad, 201);
          m_proceduralBoneBlendWeight_low = (__m128)LODWORD(this->mRagdoll->mRagdollData.m_pPointer->m_proceduralBoneBlendWeight);
          v39 = _mm_shuffle_ps(m_proceduralBoneBlendWeight_low, m_proceduralBoneBlendWeight_low, 0);
          v40 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(_mm_mul_ps((__m128)_mm_srli_si128(v21, 4), query.m_quad), TranslationMS->m_scale.m_quad),
                    v39),
                  TranslationMS->m_scale.m_quad);
          v41 = _mm_add_ps(
                  _mm_mul_ps(_mm_sub_ps(v32, TranslationMS->m_translation.m_quad), v39),
                  TranslationMS->m_translation.m_quad);
          v42 = _mm_mul_ps(v36, v34);
          v43 = _mm_add_ps(_mm_shuffle_ps(v42, v42, 78), v42);
          v44 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(
                                _mm_srli_epi32(
                                  (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v43, v43, 177), v43), (__m128)0i64),
                                  0x1Fu),
                                0x1Fu),
                      v39),
                    v34),
                  _mm_mul_ps(_mm_sub_ps(query.m_quad, v39), v36));
          v45 = _mm_shuffle_ps(result.m_rotation.m_vec.m_quad, result.m_rotation.m_vec.m_quad, 255);
          v46 = _mm_mul_ps(v44, v44);
          v47 = _mm_add_ps(_mm_shuffle_ps(v46, v46, 78), v46);
          v48 = _mm_add_ps(_mm_shuffle_ps(v47, v47, 177), v47);
          v49 = _mm_rsqrt_ps(v48);
          v50 = _mm_mul_ps(
                  v44,
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v49, v48), v49)),
                    _mm_mul_ps(*(__m128 *)_xmm, v49)));
          v51 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), result.m_rotation.m_vec.m_quad),
                  _mm_mul_ps(v41, v37));
          v52 = _mm_mul_ps(v41, result.m_rotation.m_vec.m_quad);
          v53 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                        _mm_shuffle_ps(v52, v52, 170)),
                      result.m_rotation.m_vec.m_quad),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v45, v45), (__m128)xmmword_141A711B0), v41)),
                  _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v45));
          v54 = _mm_shuffle_ps(v50, v50, 255);
          v59.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v53, v53), result.m_translation.m_quad);
          v55 = _mm_mul_ps(result.m_rotation.m_vec.m_quad, v50);
          v56 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), result.m_rotation.m_vec.m_quad),
                  _mm_mul_ps(v50, v37));
          v57 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v56, v56, 201), _mm_mul_ps(v50, v45)),
                  _mm_mul_ps(result.m_rotation.m_vec.m_quad, v54));
          v59.m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                          v57,
                                          _mm_unpackhi_ps(
                                            v57,
                                            _mm_sub_ps(
                                              _mm_mul_ps(v54, v45),
                                              _mm_add_ps(
                                                _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                                                _mm_shuffle_ps(v55, v55, 170)))),
                                          196);
          v59.m_scale.m_quad = _mm_mul_ps(result.m_scale.m_quad, v40);
          hkQsTransformf::get4x4ColumnMajor(&v59, &pos.v0.x);
          Creature::SetTransform(v2, m_boneB, &pos);
        }
      }
LABEL_11:
      ++i;
    }
    Creature::ForceSyncPose(v2);
  }
}

// File Line: 1416
// RVA: 0x4769E0
void __fastcall UFG::RagdollComponent::TeleportEventHandler(UFG::RagdollComponent *this, UFG::Event *_evt)
{
  hkQsTransformf worldTransform; // [rsp+30h] [rbp-78h] BYREF
  hkTransformf transform; // [rsp+60h] [rbp-48h] BYREF

  if ( this->mRagdoll )
  {
    hkTransformf::set4x4ColumnMajor(&transform, (const float *)&_evt[1].m_EventUID);
    hkQsTransformf::setFromTransformNoScale(&worldTransform, &transform);
    UFG::Ragdoll::ForcePose(
      this->mRagdoll,
      *(hkaSkeleton **)(*(_QWORD *)(*(_QWORD *)&this->mAnimationComponent.m_pSimComponent[2].m_TypeUID + 480i64) + 8i64),
      *(hkaPose **)(*(_QWORD *)&this->mAnimationComponent.m_pSimComponent[2].m_TypeUID + 488i64),
      &worldTransform);
    this->mPoseState = STATE_UNINITIALIZED;
  }
}

// File Line: 1434
// RVA: 0x475360
void __fastcall UFG::RagdollComponent::SetMotorMaxForce(UFG::RagdollComponent *this, float force)
{
  UFG::Ragdoll *mRagdoll; // rcx

  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
    UFG::Ragdoll::SetMotorMaxForce(mRagdoll, force);
}

// File Line: 1444
// RVA: 0x474CA0
void __fastcall UFG::RagdollComponent::SetFriction(UFG::RagdollComponent *this, float mu)
{
  UFG::Ragdoll *mRagdoll; // rcx

  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
    UFG::Ragdoll::SetFriction(mRagdoll, mu);
}

// File Line: 1455
// RVA: 0x4742E0
void __fastcall UFG::RagdollComponent::ScaleMass(UFG::RagdollComponent *this, float mu)
{
  UFG::Ragdoll *mRagdoll; // rcx

  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
    UFG::Ragdoll::ScaleMass(mRagdoll, mu);
}

// File Line: 1468
// RVA: 0x466BD0
double __fastcall UFG::RagdollComponent::GetMotorMaxForce(UFG::RagdollComponent *this)
{
  UFG::Ragdoll *mRagdoll; // rcx
  double result; // xmm0_8

  mRagdoll = this->mRagdoll;
  if ( !mRagdoll )
    return 0.0;
  *(float *)&result = UFG::Ragdoll::GetMotorMaxForce(mRagdoll);
  return result;
}

// File Line: 1482
// RVA: 0x474A00
void __fastcall UFG::RagdollComponent::SetCollisionState(
        UFG::RagdollComponent *this,
        UFG::Ragdoll::CollisionState state)
{
  UFG::Ragdoll *mRagdoll; // rcx

  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
    UFG::Ragdoll::SetCollisionState(mRagdoll, state);
}

// File Line: 1492
// RVA: 0x475540
void __fastcall UFG::RagdollComponent::SetPositionTrackingStiffness(UFG::RagdollComponent *this, float p)
{
  UFG::Ragdoll *mRagdoll; // rcx

  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
    UFG::Ragdoll::SetPositionTrackingStiffness(mRagdoll, p);
}

// File Line: 1502
// RVA: 0x475550
void __fastcall UFG::RagdollComponent::SetPositionTrackingStiffnessAtJoint(
        UFG::RagdollComponent *this,
        float p,
        int skeletonBoneID)
{
  UFG::Ragdoll *mRagdoll; // rcx

  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
    UFG::Ragdoll::SetPositionTrackingStiffnessAtJoint(mRagdoll, p, skeletonBoneID);
}

// File Line: 1512
// RVA: 0x466FD0
double __fastcall UFG::RagdollComponent::GetPositionTrackingStiffness(UFG::RagdollComponent *this)
{
  UFG::Ragdoll *mRagdoll; // rcx
  double result; // xmm0_8

  mRagdoll = this->mRagdoll;
  if ( !mRagdoll )
    return 0.0;
  *(float *)&result = UFG::Ragdoll::GetPositionTrackingStiffness(mRagdoll);
  return result;
}

// File Line: 1526
// RVA: 0x475160
void __fastcall UFG::RagdollComponent::SetLimitStiffness(UFG::RagdollComponent *this, float p)
{
  UFG::Ragdoll *mRagdoll; // rcx

  mRagdoll = this->mRagdoll;
  if ( mRagdoll )
    UFG::Ragdoll::SetLimitStiffness(mRagdoll, p);
}

// File Line: 1536
// RVA: 0x466B60
double __fastcall UFG::RagdollComponent::GetLimitStiffness(UFG::RagdollComponent *this)
{
  UFG::Ragdoll *mRagdoll; // rcx
  double result; // xmm0_8

  mRagdoll = this->mRagdoll;
  if ( !mRagdoll )
    return 0.0;
  *(float *)&result = UFG::Ragdoll::GetLimitStiffness(mRagdoll);
  return result;
}

// File Line: 1550
// RVA: 0x468B10
bool __fastcall UFG::HasRagdoll(UFG::SimObjectGame *obj, bool bActive)
{
  UFG::SimComponent *m_pComponent; // rax
  signed __int16 m_Flags; // dx

  if ( obj )
  {
    m_Flags = obj->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = obj->m_Components.p[42].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(obj, UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(obj, UFG::RagdollComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( !bActive )
    return m_pComponent != 0i64;
  return m_pComponent && LODWORD(m_pComponent[2].m_SafePointerList.mNode.mPrev) <= 1;
}

// File Line: 1573
// RVA: 0x454510
UFG::SimComponent *__fastcall UFG::RagdollComponent::Acquire(UFG::SimObjectGame *obj)
{
  UFG::SimComponent *v2; // rsi
  UFG::SimComponent *m_pComponent; // rdx
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rdi
  UFG::allocator::free_link *v7; // rax
  UFG::SimComponent *v8; // rax
  unsigned int v9; // edi
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  v2 = 0i64;
  if ( obj )
  {
    m_Flags = obj->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = obj->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(obj, UFG::RagdollComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(obj, UFG::RagdollComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      ++LODWORD(m_pComponent[3].m_pSimObject);
      return m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( (obj->m_Flags & 2) != 0 )
    return m_pComponent;
  m_pSceneObj = obj->m_pSceneObj;
  v7 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x180ui64, "RagdollComponent", 0i64, 1u);
  if ( v7 )
  {
    UFG::RagdollComponent::RagdollComponent((UFG::RagdollComponent *)v7, m_pSceneObj->m_NameUID);
    v2 = v8;
  }
  if ( (obj->m_Flags & 0x4000) != 0 )
    v9 = 42;
  else
    v9 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, obj, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v2, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  if ( UFG::RagdollComponent::mNumRagdollComponents > 29 )
  {
    UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::msRunRagdollDelete = 1;
  }
  return v2;
}

// File Line: 1607
// RVA: 0x472930
void __fastcall UFG::RagdollComponent::Release(UFG::RagdollComponent *ragdoll, const bool bForceRelease)
{
  bool v2; // zf

  if ( bForceRelease || (v2 = ragdoll->mReferenceCount == 1, --ragdoll->mReferenceCount, v2) )
    UFG::Simulation::DestroySimComponent(&UFG::gSim, ragdoll);
}

// File Line: 1617
// RVA: 0x472950
void __fastcall UFG::RagdollComponent::Release(UFG::SimObjectGame *obj, const bool bForceRelease)
{
  signed __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  bool v5; // zf

  if ( obj )
  {
    m_Flags = obj->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = obj->m_Components.p[42].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(obj, UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(obj, UFG::RagdollComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      if ( bForceRelease
        || (v5 = LODWORD(m_pComponent[3].m_pSimObject) == 1, --LODWORD(m_pComponent[3].m_pSimObject), v5) )
      {
        UFG::Simulation::DestroySimComponent(&UFG::gSim, m_pComponent);
      }
    }
  }
}

// File Line: 1630
// RVA: 0x454E80
char __fastcall UFG::RagdollComponent::AddConstraint(UFG::RagdollComponent *this, UFG::Constraint *constraint)
{
  int v2; // r10d
  UFG::Constraint **p_m_pPointer; // r8
  __int64 v5; // rax
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v10; // rax

  v2 = 0;
  p_m_pPointer = &this->mConstraint[0].m_pPointer;
  v5 = 0i64;
  while ( *p_m_pPointer != constraint )
  {
    if ( !*p_m_pPointer )
    {
      v7 = &this->mConstraint[v2];
      if ( v7->m_pPointer )
      {
        mPrev = v7->mPrev;
        mNext = v7->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v7->mPrev = v7;
        v7->mNext = v7;
      }
      v7->m_pPointer = constraint;
      if ( constraint )
      {
        v10 = constraint->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev;
        v10->mNext = v7;
        v7->mPrev = v10;
        v7->mNext = &constraint->m_SafePointerList.mNode;
        constraint->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev = v7;
      }
      UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, constraint->mConstraintInstance);
      return 1;
    }
    ++v5;
    ++v2;
    p_m_pPointer += 3;
    if ( v5 >= 4 )
      return 0;
  }
  return 1;
}

// File Line: 1671
// RVA: 0x473140
void __fastcall UFG::RagdollComponent::RemoveConstraint(
        UFG::RagdollComponent *this,
        hkpRigidBody *owner,
        hkpRigidBody *external)
{
  UFG::Constraint **p_m_pPointer; // rbx
  __int64 v6; // rsi
  UFG::Constraint *v7; // rdi
  hkpConstraintInstance *mConstraintInstance; // rdx
  __int64 v9; // rcx
  _QWORD *v10; // rax

  p_m_pPointer = &this->mConstraint[0].m_pPointer;
  v6 = 4i64;
  do
  {
    v7 = *p_m_pPointer;
    if ( *p_m_pPointer )
    {
      mConstraintInstance = v7->mConstraintInstance;
      if ( mConstraintInstance->m_entities[0] == owner && mConstraintInstance->m_entities[1] == external )
      {
        UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, mConstraintInstance);
        v7->vfptr->__vecDelDtor(v7, 1u);
        if ( *p_m_pPointer )
        {
          v9 = (__int64)*(p_m_pPointer - 2);
          v10 = *(p_m_pPointer - 1);
          *(_QWORD *)(v9 + 8) = v10;
          *v10 = v9;
          *(p_m_pPointer - 2) = (UFG::Constraint *)(p_m_pPointer - 2);
          *(p_m_pPointer - 1) = (UFG::Constraint *)(p_m_pPointer - 2);
        }
        *p_m_pPointer = 0i64;
      }
    }
    p_m_pPointer += 3;
    --v6;
  }
  while ( v6 );
}

// File Line: 1695
// RVA: 0x45A5A0
void __fastcall UFG::RagdollComponent::ClearConstraints(UFG::RagdollComponent *this)
{
  UFG::Constraint **p_m_pPointer; // rbx
  __int64 v2; // rsi
  UFG::Constraint *v3; // rdi
  __int64 v4; // rcx
  _QWORD *v5; // rax

  p_m_pPointer = &this->mConstraint[0].m_pPointer;
  v2 = 4i64;
  do
  {
    v3 = *p_m_pPointer;
    if ( *p_m_pPointer )
    {
      UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v3->mConstraintInstance);
      v3->vfptr->__vecDelDtor(v3, 1u);
      if ( *p_m_pPointer )
      {
        v4 = (__int64)*(p_m_pPointer - 2);
        v5 = *(p_m_pPointer - 1);
        *(_QWORD *)(v4 + 8) = v5;
        *v5 = v4;
        *(p_m_pPointer - 2) = (UFG::Constraint *)(p_m_pPointer - 2);
        *(p_m_pPointer - 1) = (UFG::Constraint *)(p_m_pPointer - 2);
      }
      *p_m_pPointer = 0i64;
    }
    p_m_pPointer += 3;
    --v2;
  }
  while ( v2 );
}

// File Line: 1712
// RVA: 0x468970
char __fastcall UFG::RagdollComponent::HasConstraints(UFG::RagdollComponent *this)
{
  __int64 v1; // rdx
  UFG::Constraint **i; // rax

  v1 = 0i64;
  for ( i = &this->mConstraint[0].m_pPointer; !*i; i += 3 )
  {
    if ( ++v1 >= 4 )
      return 0;
  }
  return 1;
}

