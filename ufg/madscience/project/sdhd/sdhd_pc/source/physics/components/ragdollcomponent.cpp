// File Line: 109
// RVA: 0x1514390
__int64 dynamic_initializer_for__UFG::RagdollComponent::s_RagdollComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::RagdollComponent::s_RagdollComponentList__);
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
  UFG::RagdollComponent *v2; // r14
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *v3; // rdi
  signed __int64 v4; // rsi
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v5; // rbx
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *v6; // rax
  UFG::Ragdoll *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  UFG::qSafePointerNode<UFG::RagdollComponent>::qSafePointerNode<UFG::RagdollComponent>((UFG::qSafePointerNode<UFG::RagdollComponent> *)&v2->vfptr);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RagdollComponent::`vftable'{for `UFG::SimComponent'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::RagdollComponent>Vtbl *)&UFG::RagdollComponent::`vftable'{for `UFG::qSafePointerNode<UFG::RagdollComponent>'};
  v2->mRagdoll = 0i64;
  v2->mPose = 0i64;
  *(_QWORD *)&v2->mRagDollWeight = 0i64;
  v4 = 4i64;
  v2->mPoseState = 4;
  *(_QWORD *)&v2->mDesiredPoseState = 5i64;
  v2->mDesiredLevelOfDetail = 2;
  v2->mLockHighLOD = 0;
  v2->mAnimPelvisBoneIndex = -1;
  *(_QWORD *)&v2->mReferenceCount = 1i64;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&v2->mAnimationComponent);
  v5 = v2->mConstraint;
  `eh vector constructor iterator'(
    v2->mConstraint,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  v6 = UFG::RagdollComponent::s_RagdollComponentList.mNode.mPrev;
  UFG::RagdollComponent::s_RagdollComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *)&v2->mPrev;
  v3->mPrev = v6;
  v2->mNext = (UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *)&UFG::RagdollComponent::s_RagdollComponentList;
  UFG::RagdollComponent::s_RagdollComponentList.mNode.mPrev = (UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::RagdollComponent::_RagdollComponentTypeUID,
    "RagdollComponent");
  v7 = v2->mRagdoll;
  if ( v7 )
    UFG::Ragdoll::AddToWorld(v7);
  v2->m_Flags &= 0xFFFDu;
  ++UFG::RagdollComponent::mNumRagdollComponents;
  do
  {
    if ( v5->m_pPointer )
    {
      v8 = v5->mPrev;
      v9 = v5->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    }
    v5->m_pPointer = 0i64;
    ++v5;
    --v4;
  }
  while ( v4 );
  v2->mDebugDraw = 0;
}

// File Line: 206
// RVA: 0x450970
void __fastcall UFG::RagdollComponent::~RagdollComponent(UFG::RagdollComponent *this)
{
  UFG::RagdollComponent *v1; // rsi
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // r14
  UFG::Ragdoll *v3; // rcx
  SkeletalPose *v4; // rbx
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *v5; // rdi
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *v6; // rcx
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *v10; // rcx
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RagdollComponent::`vftable'{for `UFG::SimComponent'};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->vfptr;
  this->vfptr = (UFG::qSafePointerNode<UFG::RagdollComponent>Vtbl *)&UFG::RagdollComponent::`vftable'{for `UFG::qSafePointerNode<UFG::RagdollComponent>'};
  UFG::RagdollComponent::ClearConstraints(this);
  --UFG::RagdollComponent::mNumRagdollComponents;
  v3 = v1->mRagdoll;
  if ( v3 )
  {
    UFG::Ragdoll::RemoveFromWorld(v3);
    UFG::RagdollFactory::ReleaseRagdoll(UFG::RagdollFactory::mInstance, v1->mRagdoll);
  }
  v4 = v1->mPose;
  if ( v4 )
  {
    SkeletalPose::~SkeletalPose(v1->mPose);
    operator delete[](v4);
  }
  if ( v1 == UFG::RagdollComponent::s_RagdollComponentpCurrentIterator )
    UFG::RagdollComponent::s_RagdollComponentpCurrentIterator = (UFG::RagdollComponent *)&v1->mPrev[-6].mNext;
  v5 = (UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
  `eh vector destructor iterator'(
    v1->mConstraint,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mAnimationComponent);
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::RagdollComponent>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  v8 = v2->m_SafePointerList.mNode.mPrev;
  v9 = v2->m_SafePointerList.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->m_SafePointerList.mNode.mPrev = &v2->m_SafePointerList.mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v5->mPrev = v5;
  v1->mNext = (UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *)&v1->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 227
// RVA: 0x470FD0
UFG::RagdollComponent *__fastcall UFG::RagdollComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // si
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::RagdollComponent *v6; // rdi
  UFG::RagdollComponent *result; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::RagdollComponent *v9; // rax
  UFG::SimObject *v10; // rdx
  unsigned int v11; // ebx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_Ragdoll::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    result = (UFG::RagdollComponent *)UFG::qPropertySet::GetMemImagePtr(v5);
  else
    result = 0i64;
  if ( v2 || result )
  {
    v8 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x180ui64, "RagdollComponent", 0i64, 1u);
    if ( v8 )
    {
      UFG::RagdollComponent::RagdollComponent((UFG::RagdollComponent *)v8, v3->m_NameUID);
      v6 = v9;
    }
    v10 = v3->m_pSimObject;
    if ( (v10->m_Flags >> 14) & 1 )
      v11 = 42;
    else
      v11 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v12, v10, 1);
    UFG::SimObjectModifier::AttachComponent(&v12, (UFG::SimComponent *)&v6->vfptr, v11);
    UFG::SimObjectModifier::Close(&v12);
    UFG::SimObjectModifier::~SimObjectModifier(&v12);
    result = v6;
  }
  return result;
}

// File Line: 249
// RVA: 0x473BC0
void __fastcall UFG::RagdollComponent::ResetState(UFG::RagdollComponent *this)
{
  UFG::RagdollComponent *v1; // rbx
  UFG::Ragdoll *v2; // rcx
  UFG::Ragdoll *v3; // rcx

  v1 = this;
  this->mDesiredPoseState = STATE_KEYFRAME_TRACKING;
  v2 = this->mRagdoll;
  if ( v2 )
    UFG::Ragdoll::SetCollisionState(v2, CS_KEYFRAMED_RAGDOLL_LAYER_2);
  v3 = v1->mRagdoll;
  if ( v3 )
    UFG::Ragdoll::ResetKeyframeControllerParams(v3);
}

// File Line: 262
// RVA: 0x46E030
void __fastcall UFG::RagdollComponent::OnAttach(UFG::RagdollComponent *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rdi
  UFG::RagdollComponent *v3; // rbx

  v2 = object;
  v3 = this;
  if ( (object->m_Flags >> 14) & 1 )
  {
    UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::Bind<UFG::SimObjectCharacter>(
      &this->mAnimationComponent,
      (UFG::SimObjectCharacter *)object);
    if ( v3->mAnimationComponent.m_pSimComponent )
      UFG::RagdollComponent::CreateMyRagdoll(v3, v2);
  }
}

// File Line: 291
// RVA: 0x46E800
void __fastcall UFG::RagdollComponent::OnDetach(UFG::RagdollComponent *this)
{
  UFG::RagdollComponent *v1; // rbx
  UFG::Ragdoll *v2; // rcx
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax

  v1 = this;
  v2 = this->mRagdoll;
  if ( v2 )
  {
    UFG::Ragdoll::RemoveFromWorld(v2);
    UFG::RagdollFactory::ReleaseRagdoll(UFG::RagdollFactory::mInstance, v1->mRagdoll);
    v1->mRagdoll = 0i64;
  }
  v3 = &v1->mAnimationComponent;
  if ( v1->mAnimationComponent.m_pSimComponent )
  {
    v4 = v3->mPrev;
    v5 = v1->mAnimationComponent.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v1->mAnimationComponent.m_pSimComponent = 0i64;
LABEL_9:
    v1->mAnimationComponent.m_pSimObject = 0i64;
    v1->mAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mAnimationComponent.mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_10;
  }
  if ( v1->mAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v1->mAnimationComponent.mNext != &v1->mAnimationComponent) )
  {
    v6 = v3->mPrev;
    v7 = v1->mAnimationComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    goto LABEL_9;
  }
LABEL_10:
  v1->mAnimationComponent.m_Changed = 1;
}

// File Line: 311
// RVA: 0x4764C0
void __fastcall UFG::RagdollComponent::Suspend(UFG::RagdollComponent *this)
{
  UFG::RagdollComponent *v1; // rbx
  UFG::Ragdoll *v2; // rcx

  v1 = this;
  v2 = this->mRagdoll;
  if ( v2 )
    UFG::Ragdoll::RemoveFromWorld(v2);
  v1->m_Flags |= 2u;
}

// File Line: 323
// RVA: 0x473FA0
void __fastcall UFG::RagdollComponent::Restore(UFG::RagdollComponent *this)
{
  UFG::RagdollComponent *v1; // rbx
  UFG::Ragdoll *v2; // rcx

  v1 = this;
  v2 = this->mRagdoll;
  if ( v2 )
    UFG::Ragdoll::AddToWorld(v2);
  v1->m_Flags &= 0xFFFDu;
}

// File Line: 335
// RVA: 0x45E1E0
void __fastcall UFG::RagdollComponent::CreateMyRagdoll(UFG::RagdollComponent *this, UFG::SimObject *simObject)
{
  UFG::SceneObjectProperties *v2; // rax
  UFG::RagdollComponent *v3; // rdi
  UFG::SimObjectGame *v4; // rbx
  UFG::qPropertySet *v5; // rcx
  UFG::RagdollQuality quality; // ebp
  UFG::qPropertySet *v7; // rax
  char *v8; // rsi
  UFG::qPropertySet *v9; // rsi
  __int64 v10; // r14
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rcx
  UFG::SimComponent *v13; // rax
  unsigned __int16 v14; // ax
  UFG::Ragdoll *v15; // rax
  bool v16; // zf

  v2 = simObject->m_pSceneObj;
  v3 = this;
  v4 = (UFG::SimObjectGame *)simObject;
  v5 = v2->mpWritableProperties;
  if ( !v5 )
    v5 = v2->mpConstProperties;
  quality = 1;
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v5,
         (UFG::qSymbol *)&component_Ragdoll::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v7 )
    v8 = UFG::qPropertySet::GetMemImagePtr(v7);
  else
    v8 = 0i64;
  if ( !v8 )
  {
    v9 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&SimSymX_propset_componentRagdoll.mUID);
    if ( component_Ragdoll::IsClass(v9->mSchemaName.mUID) )
      v8 = UFG::qPropertySet::GetMemImagePtr(v9);
    else
      v8 = 0i64;
    quality = 0;
  }
  v10 = *(_QWORD *)&v3->mAnimationComponent.m_pSimComponent[2].m_TypeUID;
  if ( v10 )
  {
    v11 = v4->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = v4->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v11 >> 12) & 1 )
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v13 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v4->vfptr,
                  UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v12 = v13;
    }
    if ( v12 )
      v14 = HIWORD(v12[9].m_SafePointerList.mNode.mNext);
    else
      v14 = UFG::CustomCollisionFilter::GetUnusedSystemId(UFG::BasePhysicsSystem::mInstance->mCollisionFilter);
    v15 = UFG::RagdollFactory::AquireRagdoll(
            UFG::RagdollFactory::mInstance,
            *(Skeleton **)(v10 + 480),
            (component_Ragdoll *)v8,
            v14,
            quality);
    v16 = v3->mDesiredPoseState == 5;
    v3->mRagdoll = v15;
    if ( v16 )
      UFG::Ragdoll::SetCollisionState(v15, CS_KEYFRAMED_RAGDOLL_LAYER_2);
    UFG::Ragdoll::SetUserData(v3->mRagdoll, (UFG::SimComponent *)&v3->vfptr);
    if ( !((LOBYTE(v3->m_Flags) >> 1) & 1) )
      UFG::Ragdoll::AddToWorld(v3->mRagdoll);
  }
}

// File Line: 379
// RVA: 0x1519EA0
__int64 UFG::_dynamic_initializer_for__gSymbip01Pelvis__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Pelvis", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymbip01Pelvis, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSymbip01Pelvis__);
}

// File Line: 382
// RVA: 0x47BDC0
void __usercall UFG::RagdollComponent::Update(UFG::RagdollComponent *this@<rcx>, float deltaT@<xmm1>, __int128 a3@<xmm6>)
{
  UFG::RagdollComponent *v3; // rsi
  UFG::SimObjectGame *v4; // rcx
  float v5; // xmm7_4
  UFG::SimComponent *v6; // r13
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::TransformNodeComponent *v9; // rdi
  UFG::TransformNodeComponent *v10; // rbx
  __m128 v11; // xmm2
  float v12; // xmm0_4
  UFG::RagdollComponent::LevelOfDetail v13; // eax
  UFG::Ragdoll *v14; // rcx
  UFG::SimComponent *v15; // rax
  Creature *v16; // r14
  SkeletalPose *v17; // rbx
  signed int v18; // eax
  Skeleton *v19; // rax
  hkaSkeleton *v20; // r15
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v21; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v22; // rax
  int v23; // er9
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v24; // rdi
  __int64 v25; // r8
  hkQsTransformf *v26; // rdx
  hkQsTransformf *v27; // rcx
  __int64 v28; // rbx
  __int64 v29; // r12
  __int64 v30; // r14
  __int64 v31; // rbx
  __m128 *v32; // rcx
  __m128 v33; // xmm1
  UFG::RagdollComponent::PoseState v34; // eax
  Creature *v35; // rbx
  UFG::RagdollComponent::PoseState v36; // eax
  float v37; // xmm6_4
  char v38; // di
  UFG::SimObjectGame *v39; // rcx
  UFG::SimComponent *v40; // rbx
  unsigned __int16 v41; // dx
  UFG::SimComponent *v42; // rax
  UFG::RagdollComponent::PoseState v43; // ecx
  int v44; // ecx
  int v45; // ecx
  UFG::Ragdoll *v46; // rcx
  __m128 *v47; // xmm6_8
  signed int v48; // eax
  hkQuaternionf v49; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 v; // [rsp+50h] [rbp-B0h]
  __m128 v51; // [rsp+60h] [rbp-A0h]
  __m128 v52; // [rsp+70h] [rbp-90h]
  hkQsTransformf result; // [rsp+80h] [rbp-80h]
  hkQsTransformf worldTransform; // [rsp+B0h] [rbp-50h]
  __int128 v55; // [rsp+F0h] [rbp-10h]
  Creature *v56; // [rsp+130h] [rbp+30h]

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->m_pSimObject;
  v5 = deltaT;
  if ( v4 )
  {
    v7 = v4->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v6 = v4->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v4->vfptr,
                 UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v6 = v8;
    }
  }
  else
  {
    v6 = 0i64;
  }
  if ( v3->mAnimationComponent.m_pSimComponent )
  {
    if ( v3->mLockHighLOD
      || UFG::RagdollComponent::mNumRagdollComponents < 32
      || (v9 = v3->m_pSimObject->m_pTransformNodeComponent,
          v10 = LocalPlayer->m_pTransformNodeComponent,
          UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent),
          UFG::TransformNodeComponent::UpdateWorldTransform(v9),
          v11 = (__m128)LODWORD(v9->mWorldTransform.v3.y),
          v12 = v9->mWorldTransform.v3.z - v10->mWorldTransform.v3.z,
          v11.m128_f32[0] = (float)((float)((float)(v11.m128_f32[0] - v10->mWorldTransform.v3.y)
                                          * (float)(v11.m128_f32[0] - v10->mWorldTransform.v3.y))
                                  + (float)((float)(v9->mWorldTransform.v3.x - v10->mWorldTransform.v3.x)
                                          * (float)(v9->mWorldTransform.v3.x - v10->mWorldTransform.v3.x)))
                          + (float)(v12 * v12),
          COERCE_FLOAT(_mm_sqrt_ps(v11)) <= gRagdollLodDistance) )
    {
      v3->mDesiredLevelOfDetail = 2;
    }
    else
    {
      v3->mDesiredLevelOfDetail = 1;
    }
    v13 = v3->mDesiredLevelOfDetail;
    if ( v3->mLevelOfDetail != v13 )
    {
      if ( v13 == 1 )
      {
        v14 = v3->mRagdoll;
        if ( v14 )
        {
          UFG::Ragdoll::RemoveFromWorld(v14);
          UFG::RagdollFactory::ReleaseRagdoll(UFG::RagdollFactory::mInstance, v3->mRagdoll);
          v3->mRagdoll = 0i64;
        }
      }
      if ( v3->mDesiredLevelOfDetail == 2 && !v3->mRagdoll )
      {
        UFG::RagdollComponent::CreateMyRagdoll(v3, v3->m_pSimObject);
        v3->mPoseState = 4;
      }
      v3->mLevelOfDetail = v3->mDesiredLevelOfDetail;
    }
    if ( v3->mRagdoll )
    {
      v15 = v3->mAnimationComponent.m_pSimComponent;
      v16 = *(Creature **)&v15[2].m_TypeUID;
      v56 = *(Creature **)&v15[2].m_TypeUID;
      if ( v3->mAnimationComponent.m_Changed )
      {
        v17 = v3->mPose;
        v3->mAnimationComponent.m_Changed = 0;
        if ( v17 )
        {
          SkeletalPose::~SkeletalPose(v17);
          operator delete[](v17);
        }
        v3->mPose = SkeletalPose::Clone(&v16->mPose);
        if ( v16->mPose.mRigHandle.mData )
          v18 = Skeleton::GetBoneID(v16->mPose.mRigHandle.mUFGSkeleton, UFG::gSymbip01Pelvis.mUID);
        else
          v18 = -1;
        v3->mAnimPelvisBoneIndex = v18;
      }
      v19 = v16->mPose.mRigHandle.mUFGSkeleton;
      v55 = a3;
      v20 = v19->mhkaSkeleton;
      if ( v3->mRagdoll && v3->mLevelOfDetail != 1 )
      {
        v21 = hkaPose::getSyncedPoseLocalSpace(v16->mPose.mHavokPose);
        v22 = hkaPose::accessUnsyncedPoseLocalSpace(v3->mPose->mHavokPose);
        v23 = 0;
        v24 = v22;
        if ( v22->m_size > 0 )
        {
          v25 = 0i64;
          do
          {
            v26 = v21->m_data;
            v27 = v22->m_data;
            ++v23;
            ++v25;
            v27[v25 - 1].m_translation = v21->m_data[v25 - 1].m_translation;
            *((_OWORD *)&v27[v25] - 2) = *((_OWORD *)&v26[v25] - 2);
            *((_OWORD *)&v27[v25] - 1) = *((_OWORD *)&v26[v25] - 1);
          }
          while ( v23 < v22->m_size );
        }
        v28 = v22->m_size;
        hkQsTransform_fasterRenormalizeBatch(v22->m_data, v22->m_size);
        v29 = v28;
        if ( (signed int)v28 > 0 )
        {
          v30 = 0i64;
          v31 = 0i64;
          do
          {
            v49.m_vec.m_quad = (__m128)v24->m_data[v31].m_rotation;
            if ( !hkQuaternionf::isOk(&v49, 0.001) )
            {
              UFG::qPrintf(
                "RagdollComponent.cpp.  Bad rotation on input animation.  Skeleton %s Bone %s (%f,%f,%f,%f)",
                (_QWORD)v20->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
                (_QWORD)v20->m_bones.m_data[v30].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
                v49.m_vec.m_quad.m128_f32[0],
                v49.m_vec.m_quad.m128_f32[1],
                v49.m_vec.m_quad.m128_f32[2],
                v49.m_vec.m_quad.m128_f32[3]);
              v49.m_vec.m_quad = qi.m_vec.m_quad;
            }
            v51 = v24->m_data[v31].m_translation.m_quad;
            if ( _mm_movemask_ps(_mm_cmpunordps(v51, v51)) & 7 )
              UFG::qPrintf(
                "RagdollComponent.cpp.  Bad translation on input animation. Skeleton %s Bone %s (%f,%f,%f)",
                (_QWORD)v20->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
                (_QWORD)v20->m_bones.m_data[v30].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
                v51.m128_f32[0],
                v51.m128_f32[1],
                v51.m128_f32[2]);
            v52 = v24->m_data[v31].m_scale.m_quad;
            if ( _mm_movemask_ps(_mm_cmpunordps(v52, v52)) & 7 )
              UFG::qPrintf(
                "RagdollComponent.cpp.  Bad scale on input animation. Skeleton %s Bone %s (%f,%f,%f)",
                (_QWORD)v20->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
                (_QWORD)v20->m_bones.m_data[v30].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
                v52.m128_f32[0],
                v52.m128_f32[1],
                v52.m128_f32[2]);
            ++v31;
            ++v30;
            --v29;
          }
          while ( v29 );
          v16 = v56;
        }
      }
      Creature::GetPositionhkQ(v16, &result);
      if ( v6 )
      {
        v32 = (__m128 *)v6[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
        v33 = v32[35];
        v49.m_vec.m_quad.m128_i32[0] = (int)v32[35];
        v49.m_vec.m_quad.m128_i32[2] = v32[35].m128_i32[2];
        v49.m_vec.m_quad.m128_i32[1] = (unsigned __int128)_mm_shuffle_ps(v33, v33, 85);
      }
      else
      {
        *(UFG::qVector3 *)v49.m_vec.m_quad.m128_f32 = UFG::qVector3::msZero;
      }
      *(_QWORD *)&v.x = v49.m_vec.m_quad.m128_u64[0];
      v34 = v3->mPoseState;
      v.z = v49.m_vec.m_quad.m128_f32[2];
      if ( v34 == v3->mDesiredPoseState )
      {
LABEL_84:
        v47 = (__m128 *)v55;
        if ( v5 <= 0.0 )
          return;
        v48 = v3->mPoseState;
        if ( v48 )
        {
          if ( v48 != 1 )
          {
            if ( v48 > 2 )
            {
              if ( v48 <= 4 )
              {
                ++v3->mNumFramesInKeyframedMode;
                UFG::Ragdoll::ForcePose(v3->mRagdoll, v20, v3->mPose->mHavokPose, &result);
                UFG::Ragdoll::SetVelocity(v3->mRagdoll, &v);
              }
              else if ( v48 == 5 )
              {
                UFG::Ragdoll::UpdateVelocityTracking(v3->mRagdoll, v20, v3->mPose->mHavokPose, &result, v5);
              }
            }
            return;
          }
          UFG::Ragdoll::UpdatePoweredTracking(v3->mRagdoll, v20, v3->mPose->mHavokPose);
          UFG::Ragdoll::DampMotionOfExtremities(v3->mRagdoll, v5, v47);
        }
        else
        {
          UFG::Ragdoll::UpdateVelocityTracking(v3->mRagdoll, v20, v3->mPose->mHavokPose, &result, v5);
        }
        v3->mNumFramesInKeyframedMode = 0;
        return;
      }
      if ( v34 == STATE_UNINITIALIZED )
      {
        v35 = *(Creature **)&v3->mAnimationComponent.m_pSimComponent[2].m_TypeUID;
        Creature::GetPositionhkQ(v35, &worldTransform);
        UFG::Ragdoll::ForcePose(
          v3->mRagdoll,
          v35->mPose.mRigHandle.mUFGSkeleton->mhkaSkeleton,
          v3->mPose->mHavokPose,
          &worldTransform);
      }
      v36 = v3->mPoseState;
      v37 = v3->mVelocityFromProxyScale;
      v38 = 0;
      if ( v36 == 1 )
      {
        UFG::Ragdoll::ShutdownPoweredTracking(v3->mRagdoll);
      }
      else if ( (unsigned int)(v36 - 3) <= 1 )
      {
        v37 = *(float *)&FLOAT_1_0;
        v38 = 1;
      }
      v39 = (UFG::SimObjectGame *)v3->m_pSimObject;
      if ( v39 )
      {
        v41 = v39->m_Flags;
        if ( (v41 >> 14) & 1 )
        {
          v40 = v39->m_Components.p[13].m_pComponent;
        }
        else if ( (v41 & 0x8000u) == 0 )
        {
          if ( (v41 >> 13) & 1 )
          {
            v42 = UFG::SimObjectGame::GetComponentOfTypeHK(v39, UFG::AnimationLODComponent::_TypeUID);
          }
          else if ( (v41 >> 12) & 1 )
          {
            v42 = UFG::SimObjectGame::GetComponentOfTypeHK(v39, UFG::AnimationLODComponent::_TypeUID);
          }
          else
          {
            v42 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v39->vfptr,
                    UFG::AnimationLODComponent::_TypeUID);
          }
          v40 = v42;
        }
        else
        {
          v40 = v39->m_Components.p[13].m_pComponent;
        }
      }
      else
      {
        v40 = 0i64;
      }
      v43 = v3->mDesiredPoseState;
      if ( v43 )
      {
        v44 = v43 - 1;
        if ( v44 )
        {
          v45 = v44 - 2;
          if ( v45 )
          {
            if ( v45 == 2 )
            {
              UFG::Ragdoll::SetCollisionState(v3->mRagdoll, CS_KEYFRAMED_RAGDOLL_LAYER_2);
              UFG::Ragdoll::SetControlData(v3->mRagdoll);
              UFG::Ragdoll::EnableConstraints(v3->mRagdoll);
              LOBYTE(v40[4].m_BoundComponentHandles.mNode.mNext) &= 0xF7u;
            }
          }
          else
          {
            UFG::Ragdoll::SetCollisionState(v3->mRagdoll, CS_KEYFRAMED_RAGDOLL_LAYER_2);
            UFG::Ragdoll::SetControlData(v3->mRagdoll);
            UFG::Ragdoll::DisableConstraints(v3->mRagdoll);
            LOBYTE(v40[4].m_BoundComponentHandles.mNode.mNext) &= 0xF7u;
          }
          goto LABEL_81;
        }
        UFG::Ragdoll::SetCollisionState(v3->mRagdoll, 0);
        UFG::Ragdoll::SetControlData(v3->mRagdoll);
        UFG::Ragdoll::EnableConstraints(v3->mRagdoll);
        UFG::Ragdoll::InitializePoweredTracking(v3->mRagdoll);
      }
      else
      {
        UFG::Ragdoll::SetCollisionState(v3->mRagdoll, 0);
        UFG::Ragdoll::SetControlData(v3->mRagdoll);
        UFG::Ragdoll::EnableConstraints(v3->mRagdoll);
        UFG::Ragdoll::InitializeVelocityTracking(v3->mRagdoll);
      }
      LOBYTE(v40[4].m_BoundComponentHandles.mNode.mNext) |= 8u;
LABEL_81:
      if ( v38 )
      {
        v46 = v3->mRagdoll;
        v49.m_vec.m_quad.m128_f32[0] = v.x * v37;
        v49.m_vec.m_quad.m128_f32[1] = v.y * v37;
        v49.m_vec.m_quad.m128_f32[2] = v.z * v37;
        UFG::Ragdoll::SetVelocity(v46, (UFG::qVector3 *)&v49);
      }
      v3->mPoseState = v3->mDesiredPoseState;
      goto LABEL_84;
    }
  }
}

// File Line: 750
// RVA: 0x480460
void __fastcall UFG::RagdollComponent::UpdateTransforms(UFG::RagdollComponent *this)
{
  UFG::RagdollComponent *v1; // rbx
  UFG::RagdollComponent::PoseState v2; // ecx
  int v3; // ecx
  int v4; // ecx
  __int64 v5; // rdx
  hkaPose *v6; // r8
  hkQsTransformf *v7; // rax
  UFG::Ragdoll *v8; // rcx
  UFG::qMatrix44 *v9; // rax
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  UFG::qVector4 v12; // xmm0
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-138h]
  hkQsTransformf v14; // [rsp+60h] [rbp-F8h]
  UFG::qMatrix44 d; // [rsp+90h] [rbp-C8h]
  UFG::qMatrix44 v16; // [rsp+D0h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+110h] [rbp-48h]

  v1 = this;
  if ( (this->m_Flags & 3) != 1 )
    return;
  Creature::GetTransform(*(Creature **)&this->mAnimationComponent.m_pSimComponent[2].m_TypeUID, &transform);
  v2 = v1->mPoseState;
  if ( v2 == STATE_VELOCITY_TRACKING )
  {
LABEL_13:
    UFG::RagdollComponent::FeedPoseIntoCreature(v1, &transform);
    return;
  }
  v3 = v2 - 1;
  if ( !v3 )
  {
    v5 = v1->mAnimPelvisBoneIndex;
    v6 = v1->mPose->mHavokPose;
    if ( v6->m_boneFlags.m_data[v5] & 2 )
      v7 = hkaPose::calculateBoneModelSpace(v1->mPose->mHavokPose, v5);
    else
      v7 = &v6->m_modelPose.m_data[v5];
    v14.m_translation = v7->m_translation;
    v14.m_rotation = v7->m_rotation;
    v14.m_scale = v7->m_scale;
    hkQsTransformf::get4x4ColumnMajor(&v14, &d.v0.x);
    UFG::qInverseAffine(&v16, &d);
    v8 = v1->mRagdoll;
    if ( v8 )
      UFG::Ragdoll::GetPelvisTransformWS(v8, &v1->mPelvisRagdollWS);
    v9 = UFG::qMatrix44::operator*(&v16, &result, &v1->mPelvisRagdollWS);
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
    UFG::RagdollComponent::FeedProceduralBonesIntoCreature(v1);
}

// File Line: 837
// RVA: 0x467060
hkArray<hkpRigidBody *,hkContainerHeapAllocator> *__fastcall UFG::RagdollComponent::GetRigidBodies(UFG::RagdollComponent *this)
{
  return &this->mRagdoll->mRagdollInstance->m_rigidBodies;
}

// File Line: 844
// RVA: 0x4585F0
void __fastcall UFG::RagdollComponent::ApplyImpulse(UFG::RagdollComponent *this, int bone, UFG::qVector3 *location, UFG::qVector3 *impulse)
{
  UFG::Ragdoll *v4; // rcx
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  hkVector4f impulsea; // [rsp+20h] [rbp-28h]
  hkVector4f locationa; // [rsp+30h] [rbp-18h]

  v4 = this->mRagdoll;
  v5 = (__m128)LODWORD(impulse->z);
  v6 = (__m128)LODWORD(impulse->y);
  locationa.m_quad = _mm_unpacklo_ps(
                       _mm_unpacklo_ps((__m128)LODWORD(location->x), (__m128)LODWORD(location->z)),
                       _mm_unpacklo_ps((__m128)LODWORD(location->y), (__m128)0i64));
  impulsea.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)LODWORD(impulse->x), v5), _mm_unpacklo_ps(v6, (__m128)0i64));
  UFG::Ragdoll::ApplyImpulse(v4, bone, &locationa, &impulsea);
}

// File Line: 853
// RVA: 0x456310
void __fastcall UFG::RagdollComponent::ApplyAngularImpulse(UFG::RagdollComponent *this, int bone, UFG::qVector3 *impulse, float connectionTransfer)
{
  UFG::Ragdoll *v4; // rcx
  hkVector4f impulsea; // [rsp+20h] [rbp-18h]

  v4 = this->mRagdoll;
  if ( v4 )
  {
    impulsea.m_quad = _mm_unpacklo_ps(
                        _mm_unpacklo_ps((__m128)LODWORD(impulse->x), (__m128)LODWORD(impulse->z)),
                        _mm_unpacklo_ps((__m128)LODWORD(impulse->y), (__m128)0i64));
    UFG::Ragdoll::ApplyAngularImpulse(v4, bone, &impulsea, connectionTransfer);
  }
}

// File Line: 864
// RVA: 0x463EE0
void __fastcall UFG::RagdollComponent::FeedPoseIntoCreature(UFG::RagdollComponent *this, UFG::qMatrix44 *worldTransform)
{
  UFG::SimComponent *v2; // rax
  UFG::RagdollComponent *v3; // rbx
  UFG::Ragdoll *v4; // rcx
  Creature *v5; // rdi
  UFG::qMatrix44 *v6; // rsi
  hkQsTransformf *v7; // rax
  SkeletalPose *v8; // rcx
  hkQsTransformf *v9; // rax
  SkeletalPose *v10; // rcx
  hkQsTransformf *v11; // rax
  SkeletalPose *v12; // rcx
  hkQsTransformf *v13; // rax
  SkeletalPose *v14; // rcx
  UFG::Ragdoll *v15; // rcx
  hkQsTransformf *v16; // rax
  SkeletalPose *v17; // r8
  Skeleton *v18; // rdx
  UFG::Ragdoll *v19; // rcx
  float v20; // xmm2_4
  hkQsTransformf worldTransforma; // [rsp+20h] [rbp-C8h]
  hkQsTransformf v22; // [rsp+50h] [rbp-98h]
  hkQsTransformf v23; // [rsp+80h] [rbp-68h]
  hkQsTransformf transformMS; // [rsp+B0h] [rbp-38h]

  v2 = this->mAnimationComponent.m_pSimComponent;
  v3 = this;
  v4 = this->mRagdoll;
  v5 = *(Creature **)&v2[2].m_TypeUID;
  v6 = worldTransform;
  if ( v4 )
  {
    UFG::Ragdoll::GetPelvisTransformWS(v4, &v3->mPelvisRagdollWS);
    v7 = SkeletalPose::GetTranslationMS(v3->mPose, 0);
    v8 = v3->mPose;
    transformMS.m_translation = v7->m_translation;
    transformMS.m_rotation = v7->m_rotation;
    transformMS.m_scale = v7->m_scale;
    v9 = SkeletalPose::GetTranslationMS(v8, 1);
    v10 = v3->mPose;
    v22.m_translation = v9->m_translation;
    v22.m_rotation = v9->m_rotation;
    v22.m_scale = v9->m_scale;
    v11 = SkeletalPose::GetTranslationMS(v10, 2);
    v12 = v3->mPose;
    v23.m_translation = v11->m_translation;
    v23.m_rotation = v11->m_rotation;
    v23.m_scale = v11->m_scale;
    v13 = SkeletalPose::GetTranslationMS(v12, 3);
    v14 = v3->mPose;
    worldTransforma.m_translation = v13->m_translation;
    worldTransforma.m_rotation = v13->m_rotation;
    worldTransforma.m_scale = v13->m_scale;
    SkeletalPose::SetToRestPose(v14);
    SkeletalPose::SetQsTransformMS(v3->mPose, 0, &transformMS);
    SkeletalPose::SetQsTransformMS(v3->mPose, 1, &v22);
    SkeletalPose::SetQsTransformMS(v3->mPose, 2, &v23);
    SkeletalPose::SetQsTransformMS(v3->mPose, 3, &worldTransforma);
  }
  v15 = v3->mRagdoll;
  if ( v15 )
    UFG::Ragdoll::UpdateTotalInertia(v15);
  SkeletalPose::SetRoot(v3->mPose, v6, 0);
  if ( v3->mRagdoll )
  {
    v16 = SkeletalPose::GetRoot(v3->mPose);
    v17 = v3->mPose;
    v18 = v5->mPose.mRigHandle.mUFGSkeleton;
    v19 = v3->mRagdoll;
    worldTransforma.m_translation = v16->m_translation;
    worldTransforma.m_rotation = v16->m_rotation;
    worldTransforma.m_scale = v16->m_scale;
    UFG::Ragdoll::GetHighResPose(v19, v18->mhkaSkeleton, v17->mHavokPose, &worldTransforma);
  }
  if ( gOverRideRagdollWeight )
    v20 = gOverRideRagdollWeightValue;
  else
    v20 = v3->mRagDollWeight;
  Creature::BlendInPose(v5, v3->mPose, v20, ((v3->mPoseState - 1) & 0xFFFFFFFB) == 0);
}

// File Line: 932
// RVA: 0x4640E0
void __fastcall UFG::RagdollComponent::FeedProceduralBonesIntoCreature(UFG::RagdollComponent *this)
{
  UFG::Ragdoll *v1; // r13
  Creature *v2; // r12
  hkaRagdollInstance *v3; // r14
  UFG::RagdollData *v4; // r13
  __int64 v5; // r15
  int v6; // ebx
  __int64 i; // rdi
  hkpRigidBody *v8; // rbp
  hkaSkeletonMapper *v9; // rax
  __int64 v10; // rcx
  __int64 v11; // r8
  hkaSkeletonMapperData::SimpleMapping *v12; // rdx
  int v13; // esi
  __m128 v14; // xmm6
  __m128 v15; // xmm8
  __m128i v16; // xmm0
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
  hkQsTransformf *v35; // rax
  __m128 v36; // xmm3
  __m128 v37; // xmm4
  __m128 v38; // xmm2
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
  hkQsTransformf result; // [rsp+20h] [rbp-198h]
  hkQsTransformf v59; // [rsp+50h] [rbp-168h]
  hkVector4f v60; // [rsp+80h] [rbp-138h]
  UFG::qMatrix44 pos; // [rsp+B0h] [rbp-108h]
  float d; // [rsp+F0h] [rbp-C8h]
  UFG::RagdollComponent *v63; // [rsp+1C0h] [rbp+8h]

  v63 = this;
  v1 = this->mRagdoll;
  v2 = *(Creature **)&this->mAnimationComponent.m_pSimComponent[2].m_TypeUID;
  if ( v1 && v2 )
  {
    v3 = v1->mRagdollInstance;
    v4 = v1->mRagdollData.m_pPointer;
    v5 = v3->m_rigidBodies.m_size;
    v6 = v4->mLastCoreRagdollBone + 1;
    for ( i = v6; i < v5; ++v6 )
    {
      v8 = v3->m_rigidBodies.m_data[i];
      hkTransformf::get4x4ColumnMajor(&v8->m_motion.m_motionState.m_transform, &d);
      v9 = v4->ragdollToHighResMapper;
      v10 = 0i64;
      v11 = v9->m_mapping.m_simpleMappings.m_size;
      if ( v11 > 0 )
      {
        v12 = v9->m_mapping.m_simpleMappings.m_data;
        while ( v6 != v12->m_boneA )
        {
          ++v10;
          ++v12;
          if ( v10 >= v11 )
            goto LABEL_11;
        }
        v13 = v9->m_mapping.m_simpleMappings.m_data[v10].m_boneB;
        if ( v13 != -1 )
        {
          Creature::GetPositionhkQ(v2, &result);
          v14 = v8->m_motion.m_motionState.m_transform.m_translation.m_quad;
          v15 = v8->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
          hkVector4f::setRotatedInverseDir(&v60, &result.m_rotation, &result.m_translation);
          v16 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
          v17 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v16, 64), result.m_rotation.m_vec.m_quad);
          v18 = _mm_rcp_ps(result.m_scale.m_quad);
          v19 = _mm_shuffle_ps(v17, v17, 255);
          v20 = _mm_shuffle_ps(v17, v17, 201);
          v21 = _mm_slli_si128(
                  (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(result.m_scale.m_quad, v18)), v18),
                  4);
          v22 = _mm_mul_ps(v17, v14);
          v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v17), _mm_mul_ps(v20, v14));
          v24 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                  _mm_shuffle_ps(v22, v22, 170));
          v25 = v17;
          v26 = _mm_add_ps(
                  _mm_mul_ps(v24, v17),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v19, v19), (__m128)xmmword_141A711B0), v14));
          v27 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v17);
          v28 = _mm_mul_ps(v17, v15);
          v29 = _mm_add_ps(v26, _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v19));
          v30 = _mm_sub_ps(v27, _mm_mul_ps(v20, v15));
          v31 = _mm_shuffle_ps(v15, v15, 255);
          v32 = _mm_add_ps(_mm_add_ps(v29, v29), _mm_xor_ps((__m128)_mm_shuffle_epi32(v16, 0), v60.m_quad));
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
          v35 = SkeletalPose::GetTranslationMS(&v2->mPose, v13);
          v36 = v35->m_rotation.m_vec.m_quad;
          v37 = _mm_shuffle_ps(result.m_rotation.m_vec.m_quad, result.m_rotation.m_vec.m_quad, 201);
          v38 = (__m128)LODWORD(v63->mRagdoll->mRagdollData.m_pPointer->m_proceduralBoneBlendWeight);
          v39 = _mm_shuffle_ps(v38, v38, 0);
          v40 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(_mm_mul_ps((__m128)_mm_srli_si128(v21, 4), query.m_quad), v35->m_scale.m_quad),
                    v39),
                  v35->m_scale.m_quad);
          v41 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v32, v35->m_translation.m_quad), v39), v35->m_translation.m_quad);
          v42 = _mm_mul_ps(v36, v34);
          v43 = _mm_add_ps(_mm_shuffle_ps(v42, v42, 78), v42);
          v44 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(
                                _mm_srli_epi32(
                                  (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v43, v43, 177), v43), (__m128)0i64),
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
          Creature::SetTransform(v2, v13, &pos);
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
  UFG::RagdollComponent *v2; // rbx
  hkQsTransformf worldTransform; // [rsp+30h] [rbp-78h]
  hkTransformf transform; // [rsp+60h] [rbp-48h]

  v2 = this;
  if ( this->mRagdoll )
  {
    hkTransformf::set4x4ColumnMajor(&transform, (const float *)&_evt[1].m_EventUID);
    hkQsTransformf::setFromTransformNoScale(&worldTransform, &transform);
    UFG::Ragdoll::ForcePose(
      v2->mRagdoll,
      *(hkaSkeleton **)(*(_QWORD *)(*(_QWORD *)&v2->mAnimationComponent.m_pSimComponent[2].m_TypeUID + 480i64) + 8i64),
      *(hkaPose **)(*(_QWORD *)&v2->mAnimationComponent.m_pSimComponent[2].m_TypeUID + 488i64),
      &worldTransform);
    v2->mPoseState = STATE_UNINITIALIZED;
  }
}

// File Line: 1434
// RVA: 0x475360
void __fastcall UFG::RagdollComponent::SetMotorMaxForce(UFG::RagdollComponent *this, float force)
{
  JUMPOUT(this->mRagdoll, 0i64, UFG::Ragdoll::SetMotorMaxForce);
}

// File Line: 1444
// RVA: 0x474CA0
void __fastcall UFG::RagdollComponent::SetFriction(UFG::RagdollComponent *this, float mu)
{
  JUMPOUT(this->mRagdoll, 0i64, UFG::Ragdoll::SetFriction);
}

// File Line: 1455
// RVA: 0x4742E0
void __fastcall UFG::RagdollComponent::ScaleMass(UFG::RagdollComponent *this, float mu)
{
  JUMPOUT(this->mRagdoll, 0i64, UFG::Ragdoll::ScaleMass);
}

// File Line: 1468
// RVA: 0x466BD0
float __fastcall UFG::RagdollComponent::GetMotorMaxForce(UFG::RagdollComponent *this)
{
  JUMPOUT(this->mRagdoll, 0i64, UFG::Ragdoll::GetMotorMaxForce);
  return 0.0;
}

// File Line: 1482
// RVA: 0x474A00
void __fastcall UFG::RagdollComponent::SetCollisionState(UFG::RagdollComponent *this, UFG::Ragdoll::CollisionState state)
{
  JUMPOUT(this->mRagdoll, 0i64, UFG::Ragdoll::SetCollisionState);
}

// File Line: 1492
// RVA: 0x475540
void __fastcall UFG::RagdollComponent::SetPositionTrackingStiffness(UFG::RagdollComponent *this, float p)
{
  JUMPOUT(this->mRagdoll, 0i64, UFG::Ragdoll::SetPositionTrackingStiffness);
}

// File Line: 1502
// RVA: 0x475550
void __fastcall UFG::RagdollComponent::SetPositionTrackingStiffnessAtJoint(UFG::RagdollComponent *this, float p, int skeletonBoneID)
{
  JUMPOUT(this->mRagdoll, 0i64, UFG::Ragdoll::SetPositionTrackingStiffnessAtJoint);
}

// File Line: 1512
// RVA: 0x466FD0
float __fastcall UFG::RagdollComponent::GetPositionTrackingStiffness(UFG::RagdollComponent *this)
{
  JUMPOUT(this->mRagdoll, 0i64, UFG::Ragdoll::GetPositionTrackingStiffness);
  return 0.0;
}

// File Line: 1526
// RVA: 0x475160
void __fastcall UFG::RagdollComponent::SetLimitStiffness(UFG::RagdollComponent *this, float p)
{
  JUMPOUT(this->mRagdoll, 0i64, UFG::Ragdoll::SetLimitStiffness);
}

// File Line: 1536
// RVA: 0x466B60
float __fastcall UFG::RagdollComponent::GetLimitStiffness(UFG::RagdollComponent *this)
{
  JUMPOUT(this->mRagdoll, 0i64, UFG::Ragdoll::GetLimitStiffness);
  return 0.0;
}

// File Line: 1550
// RVA: 0x468B10
bool __fastcall UFG::HasRagdoll(UFG::SimObject *obj, bool bActive)
{
  bool v2; // di
  UFG::SimComponent *v3; // rax
  unsigned __int16 v4; // dx

  v2 = bActive;
  if ( obj )
  {
    v4 = obj->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = obj->m_Components.p[42].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)obj, UFG::RagdollComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)obj, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType(obj, UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)obj, UFG::RagdollComponent::_TypeUID);
    }
  }
  else
  {
    v3 = 0i64;
  }
  if ( !v2 )
    return v3 != 0i64;
  if ( v3 && LODWORD(v3[2].m_SafePointerList.mNode.mPrev) <= 1 )
    return 1;
  return 0;
}

// File Line: 1573
// RVA: 0x454510
UFG::SimComponent *__fastcall UFG::RagdollComponent::Acquire(UFG::SimObject *obj)
{
  UFG::SimObject *v1; // rbx
  UFG::SimComponent *v2; // rsi
  UFG::SimComponent *v3; // rdx
  unsigned __int16 v4; // cx
  UFG::SimComponent *v5; // rax
  UFG::SceneObjectProperties *v6; // rdi
  UFG::allocator::free_link *v7; // rax
  UFG::SimComponent *v8; // rax
  unsigned int v9; // edi
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v1 = obj;
  v2 = 0i64;
  if ( obj )
  {
    v4 = obj->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = v1->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v1, UFG::RagdollComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v1, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType(v1, UFG::RagdollComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v1, UFG::RagdollComponent::_TypeUID);
      }
      v3 = v5;
    }
    if ( v3 )
    {
      ++LODWORD(v3[3].m_pSimObject);
      return v3;
    }
  }
  else
  {
    v3 = 0i64;
  }
  if ( (LOBYTE(v1->m_Flags) >> 1) & 1 )
    return v3;
  v6 = v1->m_pSceneObj;
  v7 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x180ui64, "RagdollComponent", 0i64, 1u);
  if ( v7 )
  {
    UFG::RagdollComponent::RagdollComponent((UFG::RagdollComponent *)v7, v6->m_NameUID);
    v2 = v8;
  }
  if ( (v1->m_Flags >> 14) & 1 )
    v9 = 42;
  else
    v9 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, v1, 1);
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
    UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)&ragdoll->vfptr);
}

// File Line: 1617
// RVA: 0x472950
void __fastcall UFG::RagdollComponent::Release(UFG::SimObject *obj, const bool bForceRelease)
{
  unsigned __int16 v2; // r8
  bool v3; // bl
  UFG::SimComponent *v4; // rax
  bool v5; // zf

  if ( obj )
  {
    v2 = obj->m_Flags;
    v3 = bForceRelease;
    if ( (v2 >> 14) & 1 )
    {
      v4 = obj->m_Components.p[42].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)obj, UFG::RagdollComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)obj, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType(obj, UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)obj, UFG::RagdollComponent::_TypeUID);
    }
    if ( v4 )
    {
      if ( v3 || (v5 = LODWORD(v4[3].m_pSimObject) == 1, --LODWORD(v4[3].m_pSimObject), v5) )
        UFG::Simulation::DestroySimComponent(&UFG::gSim, v4);
    }
  }
}

// File Line: 1630
// RVA: 0x454E80
char __fastcall UFG::RagdollComponent::AddConstraint(UFG::RagdollComponent *this, UFG::Constraint *constraint)
{
  int v2; // er10
  UFG::Constraint *v3; // r11
  UFG::Constraint **v4; // r8
  signed __int64 v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v10; // rax

  v2 = 0;
  v3 = constraint;
  v4 = &this->mConstraint[0].m_pPointer;
  v5 = 0i64;
  while ( *v4 != constraint )
  {
    if ( !*v4 )
    {
      v7 = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&(&this->vfptr)[3 * (v2 + 12i64)];
      if ( *((_QWORD *)&this->m_SafePointerList.mNode.mNext + 3 * (v2 + 12i64)) )
      {
        v8 = v7->mPrev;
        v9 = v7->mNext;
        v8->mNext = v9;
        v9->mPrev = v8;
        v7->mPrev = v7;
        v7->mNext = v7;
      }
      v7[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)v3;
      if ( v3 )
      {
        v10 = v3->m_SafePointerList.mNode.mPrev;
        v10->mNext = v7;
        v7->mPrev = v10;
        v7->mNext = &v3->m_SafePointerList.mNode;
        v3->m_SafePointerList.mNode.mPrev = v7;
      }
      UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v3->mConstraintInstance);
      return 1;
    }
    ++v5;
    ++v2;
    v4 += 3;
    if ( v5 >= 4 )
      return 0;
  }
  return 1;
}

// File Line: 1671
// RVA: 0x473140
void __fastcall UFG::RagdollComponent::RemoveConstraint(UFG::RagdollComponent *this, hkpRigidBody *owner, hkpRigidBody *external)
{
  hkpRigidBody *v3; // rbp
  hkpRigidBody *v4; // r14
  UFG::Constraint **v5; // rbx
  signed __int64 v6; // rsi
  UFG::Constraint *v7; // rdi
  hkpConstraintInstance *v8; // rdx
  __int64 v9; // rcx
  _QWORD *v10; // rax

  v3 = external;
  v4 = owner;
  v5 = &this->mConstraint[0].m_pPointer;
  v6 = 4i64;
  do
  {
    v7 = *v5;
    if ( *v5 )
    {
      v8 = v7->mConstraintInstance;
      if ( (hkpRigidBody *)v8->m_entities[0] == v4 && (hkpRigidBody *)v8->m_entities[1] == v3 )
      {
        UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v8);
        v7->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::Constraint> *)&v7->vfptr, 1u);
        if ( *v5 )
        {
          v9 = (__int64)*(v5 - 2);
          v10 = *(v5 - 1);
          *(_QWORD *)(v9 + 8) = v10;
          *v10 = v9;
          *(v5 - 2) = (UFG::Constraint *)(v5 - 2);
          *(v5 - 1) = (UFG::Constraint *)(v5 - 2);
        }
        *v5 = 0i64;
      }
    }
    v5 += 3;
    --v6;
  }
  while ( v6 );
}

// File Line: 1695
// RVA: 0x45A5A0
void __fastcall UFG::RagdollComponent::ClearConstraints(UFG::RagdollComponent *this)
{
  UFG::Constraint **v1; // rbx
  signed __int64 v2; // rsi
  UFG::Constraint *v3; // rdi
  __int64 v4; // rcx
  _QWORD *v5; // rax

  v1 = &this->mConstraint[0].m_pPointer;
  v2 = 4i64;
  do
  {
    v3 = *v1;
    if ( *v1 )
    {
      UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v3->mConstraintInstance);
      v3->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::Constraint> *)&v3->vfptr, 1u);
      if ( *v1 )
      {
        v4 = (__int64)*(v1 - 2);
        v5 = *(v1 - 1);
        *(_QWORD *)(v4 + 8) = v5;
        *v5 = v4;
        *(v1 - 2) = (UFG::Constraint *)(v1 - 2);
        *(v1 - 1) = (UFG::Constraint *)(v1 - 2);
      }
      *v1 = 0i64;
    }
    v1 += 3;
    --v2;
  }
  while ( v2 );
}

// File Line: 1712
// RVA: 0x468970
char __fastcall UFG::RagdollComponent::HasConstraints(UFG::RagdollComponent *this)
{
  signed __int64 v1; // rdx
  UFG::Constraint **v2; // rax

  v1 = 0i64;
  v2 = &this->mConstraint[0].m_pPointer;
  while ( !*v2 )
  {
    ++v1;
    v2 += 3;
    if ( v1 >= 4 )
      return 0;
  }
  return 1;
}

