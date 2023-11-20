// File Line: 46
// RVA: 0x1544980
__int64 UFG::_anonymous_namespace_::_dynamic_initializer_for__IsEliteFighterSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("IsEliteFighter", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&IsEliteFighterSymbol, v0);
  return atexit(UFG::_anonymous_namespace_::_dynamic_atexit_destructor_for__IsEliteFighterSymbol__);
}

// File Line: 47
// RVA: 0x15448C0
__int64 UFG::_anonymous_namespace_::_dynamic_initializer_for__FootWearUnderwearSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("FootwearUnderwear", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&FootWearUnderwearSymbol, v0);
  return atexit(UFG::_anonymous_namespace_::_dynamic_atexit_destructor_for__FootWearUnderwearSymbol__);
}

// File Line: 69
// RVA: 0x1543DC0
__int64 dynamic_initializer_for__UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList__);
}

// File Line: 70
// RVA: 0x5323B0
const char *__fastcall UFG::CharacterEffectsComponent::GetTypeName(UFG::CharacterEffectsComponent *this)
{
  return "CharacterEffectsComponent";
}

// File Line: 96
// RVA: 0x516250
void __fastcall UFG::CharacterEffectsComponent::CharacterEffectsComponent(UFG::CharacterEffectsComponent *this, unsigned int name_uid, component_CharacterEffects *data, UFG::qPropertySet *properties)
{
  UFG::qPropertySet *v4; // rsi
  component_CharacterEffects *v5; // rdi
  UFG::CharacterEffectsComponent *v6; // r14
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *v7; // rbx
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *v8; // rax

  v4 = properties;
  v5 = data;
  v6 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v7 = (UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *)&v6->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterEffectsComponent::`vftable;
  *(_WORD *)&v6->InvulnerableToFire = 256;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&v6->mCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>(&v6->mCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::PhantomVolumeComponent,0>::RebindingComponentHandle<UFG::PhantomVolumeComponent,0>(&v6->mPhantomVolumeComponent);
  v6->mWalkingThroughWaterEffect.mUID = -1;
  v6->mMaxWaterDepthForWalkingThroughWaterEffect = 0.0;
  UFG::qBaseTreeRB::qBaseTreeRB(&v6->mPhysVolumeRefs.mTree);
  *(_QWORD *)&v6->mActiveSurfaceUID = 0i64;
  v6->mIsOnFire = 0;
  v6->mIsSmoldering = 0;
  *(_QWORD *)&v6->mFireExtinguishTime = 0i64;
  v6->mQueuedHealthDamage = 0.0;
  v6->mPhantomRigidBody = 0i64;
  v6->mIsAttachedToPlayer = 0;
  v6->mUIElementIndex = -1;
  v6->mIsEliteFighter = 0;
  v8 = UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList.mNode.mPrev;
  UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *)&v6->mPrev;
  v7->mPrev = v8;
  v6->mNext = (UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *)&UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList;
  UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList.mNode.mPrev = (UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *)&v6->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v6->vfptr,
    UFG::CharacterEffectsComponent::_CharacterEffectsComponentTypeUID,
    "CharacterEffectsComponent");
  *(_QWORD *)v6->mActiveVolumeUID = 0i64;
  *(_QWORD *)&v6->mActiveVolumeUID[2] = 0i64;
  v6->mActiveVolumeUID[4] = 0;
  *(_QWORD *)v6->mFootstepOverride = -1i64;
  v6->mWalkingThroughWaterEffect.mUID = v5->fxPlayerWalkingThroughWater.mUID;
  v6->mWalkingThroughWaterMinSpeedForEffectSqr = v5->fxPlayerWalkingThroughWaterMinSpeed
                                               * v5->fxPlayerWalkingThroughWaterMinSpeed;
  v6->mMaxWaterDepthForWalkingThroughWaterEffect = v5->fxMaxWaterDepthForWalkingThroughWaterEffect;
  v6->mIsEliteFighter = *UFG::qPropertySet::Get<bool>(v4, (UFG::qSymbol *)&IsEliteFighterSymbol.mUID, DEPTH_RECURSE);
  UFG::CharacterEffectsComponent::CreateNodes(v6);
}

// File Line: 115
// RVA: 0x51AF20
void __fastcall UFG::CharacterEffectsComponent::~CharacterEffectsComponent(UFG::CharacterEffectsComponent *this)
{
  UFG::CharacterEffectsComponent *v1; // rsi
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *v2; // r14
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *v3; // rcx
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *v4; // rax
  UFG::TransformNodeComponent **v5; // rbx
  signed __int64 v6; // rdi
  Render::SkinningCacheNode *v7; // rbx
  UFG::WorldEffectsManager *v8; // rax
  Render::SkinningCacheNode *v9; // rbx
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *v10; // rcx
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterEffectsComponent::`vftable;
  if ( this == UFG::CharacterEffectsComponent::s_CharacterEffectsComponentpCurrentIterator )
    UFG::CharacterEffectsComponent::s_CharacterEffectsComponentpCurrentIterator = (UFG::CharacterEffectsComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mNodes;
  v6 = 2i64;
  do
  {
    if ( *v5 )
      (*v5)->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&(*v5)->vfptr, 1u);
    *v5 = 0i64;
    ++v5;
    --v6;
  }
  while ( v6 );
  while ( v1->mPhysVolumeRefs.mTree.mCount )
  {
    v7 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mPhysVolumeRefs);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mPhysVolumeRefs,
      &v7->mNode);
    operator delete[](v7);
  }
  if ( v1->mIsOnFire )
    UFG::CharacterEffectsComponent::ExtinguishFire(v1);
  if ( v1->mIsSmoldering )
    UFG::CharacterEffectsComponent::ExtinguishSmolder(v1);
  v8 = UFG::WorldEffectsManager::Get();
  UFG::WorldEffectsManager::RemoveUIEffects(v8, v1);
  while ( v1->mPhysVolumeRefs.mTree.mCount )
  {
    v9 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mPhysVolumeRefs);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mPhysVolumeRefs,
      &v9->mNode);
    operator delete[](v9);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mPhysVolumeRefs);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mPhantomVolumeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mCharacterAnimationComponent);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 128
// RVA: 0x53D4F0
void __fastcall UFG::CharacterEffectsComponent::OnAttach(UFG::CharacterEffectsComponent *this, UFG::SimObject *object)
{
  UFG::SimObjectCharacter *v2; // rdi
  UFG::CharacterEffectsComponent *v3; // rbx
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  v2 = (UFG::SimObjectCharacter *)object;
  v3 = this;
  if ( object == (UFG::SimObject *)LocalPlayer )
    this->mIsAttachedToPlayer = 1;
  v4 = &this->mCharacterAnimationComponent;
  if ( v4->m_pSimComponent )
  {
    v5 = v4->mNext;
    v6 = v4->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    v4->m_pSimComponent = 0i64;
LABEL_9:
    v4->m_pSimObject = 0i64;
    v4->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_10;
  }
  if ( v4->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v4->mNext != v4) )
  {
    v7 = v4->mNext;
    v8 = v4->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_9;
  }
LABEL_10:
  v4->m_Changed = 1;
  v4->m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v4->m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObjectVehicle>(v4, v2);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v3->mCharacterPhysicsComponent,
    v2);
  UFG::RebindingComponentHandle<UFG::PhantomVolumeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v3->mPhantomVolumeComponent,
    v2);
}

// File Line: 144
// RVA: 0x53FDE0
void __fastcall UFG::CharacterEffectsComponent::OnDetach(UFG::CharacterEffectsComponent *this)
{
  UFG::CharacterEffectsComponent *v1; // rbx
  UFG::WorldEffectsManager *v2; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::RebindingComponentHandle<UFG::PhantomVolumeComponent,0> *v13; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax

  v1 = this;
  if ( this->mIsOnFire )
    UFG::CharacterEffectsComponent::ExtinguishFire(this);
  if ( v1->mIsSmoldering )
    UFG::CharacterEffectsComponent::ExtinguishSmolder(v1);
  v2 = UFG::WorldEffectsManager::Get();
  UFG::WorldEffectsManager::RemoveUIEffects(v2, v1);
  v3 = &v1->mCharacterAnimationComponent;
  if ( v1->mCharacterAnimationComponent.m_pSimComponent )
  {
    v4 = v3->mPrev;
    v5 = v1->mCharacterAnimationComponent.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v1->mCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_11:
    v1->mCharacterAnimationComponent.m_pSimObject = 0i64;
    v1->mCharacterAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mCharacterAnimationComponent.mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_12;
  }
  if ( v1->mCharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v1->mCharacterAnimationComponent.mNext != &v1->mCharacterAnimationComponent) )
  {
    v6 = v3->mPrev;
    v7 = v1->mCharacterAnimationComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    goto LABEL_11;
  }
LABEL_12:
  v1->mCharacterAnimationComponent.m_Changed = 1;
  v8 = &v1->mCharacterPhysicsComponent;
  if ( v1->mCharacterPhysicsComponent.m_pSimComponent )
  {
    v9 = v8->mPrev;
    v10 = v1->mCharacterPhysicsComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v1->mCharacterPhysicsComponent.m_pSimComponent = 0i64;
LABEL_18:
    v1->mCharacterPhysicsComponent.m_pSimObject = 0i64;
    v1->mCharacterPhysicsComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mCharacterPhysicsComponent.mPrev;
    v8->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v8->mPrev;
    goto LABEL_19;
  }
  if ( v1->mCharacterPhysicsComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)v8->mPrev != v8
     || (UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)v1->mCharacterPhysicsComponent.mNext != &v1->mCharacterPhysicsComponent) )
  {
    v11 = v8->mPrev;
    v12 = v1->mCharacterPhysicsComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    goto LABEL_18;
  }
LABEL_19:
  v1->mCharacterPhysicsComponent.m_Changed = 1;
  v13 = &v1->mPhantomVolumeComponent;
  if ( v1->mPhantomVolumeComponent.m_pSimComponent )
  {
    v14 = v13->mPrev;
    v15 = v1->mPhantomVolumeComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v1->mPhantomVolumeComponent.m_pSimComponent = 0i64;
LABEL_25:
    v1->mPhantomVolumeComponent.m_pSimObject = 0i64;
    v1->mPhantomVolumeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPhantomVolumeComponent.mPrev;
    v13->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v13->mPrev;
    goto LABEL_26;
  }
  if ( v1->mPhantomVolumeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::PhantomVolumeComponent,0> *)v13->mPrev != v13
     || (UFG::RebindingComponentHandle<UFG::PhantomVolumeComponent,0> *)v1->mPhantomVolumeComponent.mNext != &v1->mPhantomVolumeComponent) )
  {
    v16 = v13->mPrev;
    v17 = v1->mPhantomVolumeComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    goto LABEL_25;
  }
LABEL_26:
  v1->mPhantomVolumeComponent.m_Changed = 1;
}

// File Line: 168
// RVA: 0x545FD0
UFG::SimComponent *__fastcall UFG::CharacterEffectsComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *sceneObject, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertySet *v11; // r9
  UFG::SimComponent *v12; // rax
  UFG::SimObject *v13; // rdx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = sceneObject;
  v4 = sceneObject->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_CharacterEffects::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    v7 = 0i64;
  if ( !v2 && !v7 )
    return 0i64;
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x1B8ui64, "CharacterEffectsComponent", 0i64, 1u);
  if ( v10 )
  {
    v11 = v3->mpWritableProperties;
    if ( !v11 )
      v11 = v3->mpConstProperties;
    UFG::CharacterEffectsComponent::CharacterEffectsComponent(
      (UFG::CharacterEffectsComponent *)v10,
      v3->m_NameUID,
      (component_CharacterEffects *)v7,
      v11);
    v6 = v12;
  }
  v13 = v3->m_pSimObject;
  if ( (v13->m_Flags >> 14) & 1 )
    v14 = 38;
  else
    v14 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v15, v13, 1);
  UFG::SimObjectModifier::AttachComponent(&v15, v6, v14);
  UFG::SimObjectModifier::Close(&v15);
  UFG::SimObjectModifier::~SimObjectModifier(&v15);
  return v6;
}

// File Line: 236
// RVA: 0x533E90
void __fastcall UFG::CharacterEffectsComponent::HandleFootstep(UFG::CharacterEffectsComponent *this, UFG::CharacterEffectsComponent::Foot foot)
{
  UFG::SimComponent *v2; // rbx
  __int64 v3; // r14
  UFG::CharacterEffectsComponent *v4; // rdi
  Creature *v5; // rbx
  unsigned int v6; // edx
  UFG::qWiseSymbol *v7; // rax
  int v8; // eax
  __m128 v9; // xmm1
  float v10; // xmm7_4
  UFG::CharacterPhysicsComponent *v11; // rsi
  UFG::SimObject *v12; // rax
  UFG::TransformNodeComponent *v13; // rbx
  float v14; // xmm6_4
  signed int v15; // esi
  UFG::qBaseTreeRB *i; // rbx
  UFG::qBaseNodeRB *v17; // rax
  unsigned int v18; // edx
  UFG::qBaseNodeRB *v19; // rax
  unsigned int v20; // ecx
  unsigned int v21; // edx
  UFG::qVector4 v22; // [rsp+28h] [rbp-79h]
  UFG::qVector4 basis_8; // [rsp+38h] [rbp-69h]
  UFG::qVector4 basis_16; // [rsp+40h] [rbp-61h]
  UFG::qVector4 v25; // [rsp+78h] [rbp-29h]
  UFG::qWiseSymbol result; // [rsp+110h] [rbp+6Fh]

  v2 = this->mCharacterAnimationComponent.m_pSimComponent;
  v3 = foot;
  v4 = this;
  basis_16 = UFG::qMatrix44::msIdentity.v1;
  v22 = UFG::qMatrix44::msIdentity.v2;
  basis_8 = UFG::qMatrix44::msIdentity.v3;
  if ( foot )
  {
    if ( !v2 )
      goto LABEL_12;
    v5 = *(Creature **)&v2[2].m_TypeUID;
    if ( !v5 )
      goto LABEL_12;
    v6 = -94440458;
  }
  else
  {
    if ( !v2 )
      goto LABEL_12;
    v5 = *(Creature **)&v2[2].m_TypeUID;
    if ( !v5 )
      goto LABEL_12;
    v6 = -810582767;
  }
  v7 = UFG::qSymbol::qSymbol(&result, v6);
  if ( v5->mPose.mRigHandle.mData )
    v8 = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, v7->mUID);
  else
    v8 = -1;
  Creature::GetTransform(v5, v8, (UFG::qMatrix44 *)&basis_16.z);
LABEL_12:
  v9 = (__m128)LODWORD(basis_16.w);
  v9.m128_f32[0] = (float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(basis_16.z * basis_16.z);
  if ( v9.m128_f32[0] == 0.0 )
    v10 = 0.0;
  else
    v10 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
  v11 = (UFG::CharacterPhysicsComponent *)v4->mCharacterPhysicsComponent.m_pSimComponent;
  v22.z = basis_16.z * v10;
  v22.w = basis_16.w * v10;
  basis_8 = v25;
  basis_16.z = (float)((float)(basis_16.w * v10) * UFG::qVector3::msAxisZ.x)
             - (float)((float)(basis_16.z * v10) * UFG::qVector3::msAxisZ.y);
  if ( v11 && UFG::CharacterPhysicsComponent::IsInWater(v11) )
  {
    v12 = v4->m_pSimObject;
    if ( v12 )
      v13 = (UFG::TransformNodeComponent *)v12->m_Components.p[2].m_pComponent;
    else
      v13 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v13);
    v14 = v13->mWorldTransform.v3.z;
    if ( (float)(UFG::CharacterPhysicsComponent::GetWaterElevation(v11) - v14) >= v4->mMaxWaterDepthForWalkingThroughWaterEffect )
    {
      if ( v4->mIsOnFire )
        UFG::CharacterEffectsComponent::ExtinguishFire(v4);
      if ( v4->mIsSmoldering )
        UFG::CharacterEffectsComponent::ExtinguishSmolder(v4);
    }
    else
    {
      Render::FXManager::CreateEffect(
        &Render::gFXManager,
        v4->mWalkingThroughWaterEffect.mUID,
        v4->mNodes[v3],
        0xFFFFFFFF,
        0i64);
    }
  }
  v15 = -1;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v4->mPhysVolumeRefs);
        i;
        i = UFG::qBaseTreeRB::GetNext(&v4->mPhysVolumeRefs.mTree, &i->mRoot) )
  {
    if ( !BYTE1(i->mNULL.mParent) )
    {
      v17 = i->mNULL.mChild[1];
      if ( *((float *)&v17[3].mChild[1] + 1) <= 0.0 || v4->mIsOnFire )
      {
        if ( LOBYTE(i->mNULL.mParent) )
        {
          v18 = (unsigned int)v17[3].mParent;
          if ( v18 != -1 )
            Render::FXManager::CreateEffect(&Render::gFXManager, v18, (UFG::qMatrix44 *)&v22.z, 0xFFFFFFFF);
        }
        v19 = i->mNULL.mChild[1];
        if ( (_DWORD)v3 )
          v20 = (unsigned int)v19[3].mChild[0];
        else
          v20 = HIDWORD(v19[3].mParent);
        if ( v20 != -1 )
        {
          v15 = v20;
          Render::FXManager::CreateEffect(&Render::gFXManager, v20, (UFG::qMatrix44 *)&v22.z, 0xFFFFFFFF);
        }
      }
    }
  }
  v21 = v4->mFootstepOverride[v3];
  if ( v21 != -1 && v21 != v15 )
    Render::FXManager::CreateEffect(&Render::gFXManager, v21, (UFG::qMatrix44 *)&v22.z, 0xFFFFFFFF);
}

// File Line: 332
// RVA: 0x559AF0
void __fastcall UFG::CharacterEffectsComponent::Update(UFG::CharacterEffectsComponent *this, float delta_sec)
{
  float v2; // xmm8_4
  UFG::CharacterEffectsComponent *v3; // rdi
  UFG::PhantomVolumeComponent *v4; // r14
  unsigned __int8 v5; // bl
  UFG::PhysicsVolumeProperties *v6; // rax
  UFG::qBaseNodeRB *v7; // rsi
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::qBaseNodeRB *v10; // rdx
  UFG::SimComponent *v11; // rax
  unsigned __int64 v12; // rsi
  unsigned __int64 v13; // rbx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v14; // rcx
  const char *v15; // rax
  UFG::qReflectObject *v16; // rax
  unsigned int v17; // ebx
  const char *v18; // rax
  UFG::qReflectObject *v19; // rax
  UFG::qReflectObject *v20; // rbx
  UFG::allocator::free_link *v21; // rax
  UFG::qBaseNodeRB *v22; // rdx
  UFG::qReflectObject *v23; // rbx
  UFG::allocator::free_link *v24; // rax
  UFG::qBaseNodeRB *v25; // rdx
  UFG::qBaseTreeRB *v26; // rsi
  unsigned int v27; // eax
  bool v28; // zf
  char v29; // al
  float *v30; // rdx
  char v31; // cl
  UFG::qBaseNodeRB *v32; // rdx
  UFG::qBaseTreeRB *v33; // rcx
  float v34; // xmm1_4
  UFG::SimObject *v35; // r8
  UFG::HealthComponent *v36; // r15
  float v37; // xmm0_4
  float v38; // xmm1_4
  bool v39; // r12
  UFG::HitReactionComponent *v40; // rbx
  int v41; // ecx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v42; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v43; // rax
  UFG::HitRecord *v44; // r14
  bool v45; // al
  bool v46; // cl
  UFG::allocator::free_link *v47; // rax
  UFG::HitRecord *v48; // rax
  UFG::HitRecord *v49; // rax
  float v50; // xmm0_4
  unsigned int v51; // edx
  bool v52; // r8
  float v53; // xmm0_4
  UFG::SimObject *v54; // rax
  UFG::HitReactionComponent *v55; // rbx
  UFG::qBaseNodeRB *v56; // rax
  int v57; // ecx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v58; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v59; // rax
  bool v60; // al
  bool v61; // cl
  UFG::allocator::free_link *v62; // rax
  UFG::HitRecord *v63; // rax
  UFG::HitRecord *v64; // r14
  UFG::HitRecord *v65; // rax
  float v66; // xmm0_4
  UFG::qBaseTreeRB *v67; // rbx
  float v68; // xmm0_4
  UFG::SimComponentHolder *v69; // rcx
  UFG::SimComponent *v70; // rbx
  float v71; // xmm2_4
  float v72; // xmm0_4
  UFG::WorldEffectsManager *v73; // rax
  UFG::qReflectHandleBase v74; // [rsp+30h] [rbp-A8h]
  UFG::HitRecord hitrecord; // [rsp+58h] [rbp-80h]
  UFG::HitRecord __that; // [rsp+188h] [rbp+B0h]
  hkTransformf transform; // [rsp+2B8h] [rbp+1E0h]
  UFG::allocator::free_link *v78; // [rsp+368h] [rbp+290h]

  hitrecord.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)-2i64;
  v2 = delta_sec;
  v3 = this;
  *(_QWORD *)&this->mActiveSurfaceUID = 0i64;
  *(_QWORD *)this->mActiveVolumeUID = 0i64;
  *(_QWORD *)&this->mActiveVolumeUID[2] = 0i64;
  this->mActiveVolumeUID[4] = 0;
  v4 = (UFG::PhantomVolumeComponent *)this->mPhantomVolumeComponent.m_pSimComponent;
  if ( v4 )
  {
    v5 = 0;
    do
    {
      v6 = UFG::PhantomVolumeComponent::GetProperties(v4, v5);
      v7 = (UFG::qBaseNodeRB *)v6;
      if ( !v6 )
        break;
      v3->mActiveVolumeUID[v5] = v6->mBaseNode.mUID;
      v8 = v6->mBaseNode.mUID;
      if ( !(_DWORD)v8 || !UFG::qBaseTreeRB::Get(&v3->mPhysVolumeRefs.mTree, v8) )
      {
        v9 = UFG::qMalloc(0x40ui64, "PhysVolumeRef", 0i64);
        v10 = (UFG::qBaseNodeRB *)v9;
        v78 = v9;
        if ( v9 )
        {
          v9->mNext = 0i64;
          v9[1].mNext = 0i64;
          v9[2].mNext = 0i64;
          LOWORD(v9[4].mNext) = 0;
          *(UFG::allocator::free_link **)((char *)&v9[4].mNext + 4) = 0i64;
          v9[6].mNext = 0i64;
          LOBYTE(v9[7].mNext) = 0;
        }
        else
        {
          v10 = 0i64;
        }
        v10->mUID = (unsigned int)v7->mChild[0];
        v10[1].mChild[1] = v7;
        UFG::qBaseTreeRB::Add(&v3->mPhysVolumeRefs.mTree, v10);
      }
      ++v5;
    }
    while ( v5 < 5u );
  }
  v11 = v3->mCharacterPhysicsComponent.m_pSimComponent;
  if ( v11 )
  {
    v12 = (unsigned __int64)v11[6].m_SafePointerList.mNode.mPrev;
    v13 = (unsigned __int64)v11[6].m_SafePointerList.mNode.mNext;
    UFG::qReflectHandleBase::qReflectHandleBase(&v74);
    if ( v13 )
    {
      v15 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v14);
      v74.mTypeUID = UFG::qStringHash64(v15, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v74, v74.mTypeUID, v13);
      v16 = v74.mData;
      if ( !v74.mData )
      {
        UFG::PhysicsPropertyManager::GetDefaultSurfaceProperties((UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *)&v74);
        v16 = v74.mData;
      }
      v17 = HIDWORD(v16[1].mBaseNode.mChildren[0]);
    }
    else
    {
      v18 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName((UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *)v14);
      v74.mTypeUID = UFG::qStringHash64(v18, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v74, v74.mTypeUID, v12);
      v19 = v74.mData;
      if ( !v74.mData )
      {
        UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v74);
        v19 = v74.mData;
      }
      v17 = *(_DWORD *)(v19[4].mBaseNode.mUID + 108);
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v74);
    v3->mActiveSurfaceUID = v17;
    if ( !v17 || !UFG::qBaseTreeRB::Get(&v3->mPhysVolumeRefs.mTree, v17) )
    {
      v20 = UFG::PhysicsVolumePropertyManager::Find(v17, 0);
      if ( v20 )
      {
        v21 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
        v22 = (UFG::qBaseNodeRB *)v21;
        v78 = v21;
        if ( v21 )
        {
          v21->mNext = 0i64;
          v21[1].mNext = 0i64;
          v21[2].mNext = 0i64;
          LOWORD(v21[4].mNext) = 0;
          *(UFG::allocator::free_link **)((char *)&v21[4].mNext + 4) = 0i64;
          v21[6].mNext = 0i64;
          LOBYTE(v21[7].mNext) = 0;
        }
        else
        {
          v22 = 0i64;
        }
        v22->mUID = v20->mBaseNode.mUID;
        v22[1].mChild[1] = (UFG::qBaseNodeRB *)v20;
        UFG::qBaseTreeRB::Add(&v3->mPhysVolumeRefs.mTree, v22);
      }
    }
  }
  if ( v3->mIsAttachedToPlayer )
  {
    if ( UFG::TimeOfDayManager::GetInstance()->m_WeatherState > 1.0 && !UFG::TidoGame::IsInside() )
    {
      v3->mActiveWetSurfaceUID = -242425211;
      if ( !UFG::qBaseTreeRB::Get(&v3->mPhysVolumeRefs.mTree, 0xF18CE285) )
      {
        v23 = UFG::PhysicsVolumePropertyManager::Find(v3->mActiveWetSurfaceUID, 0);
        if ( v23 )
        {
          v24 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
          v25 = (UFG::qBaseNodeRB *)v24;
          v78 = v24;
          if ( v24 )
          {
            v24->mNext = 0i64;
            v24[1].mNext = 0i64;
            v24[2].mNext = 0i64;
            LOWORD(v24[4].mNext) = 0;
            *(UFG::allocator::free_link **)((char *)&v24[4].mNext + 4) = 0i64;
            v24[6].mNext = 0i64;
            LOBYTE(v24[7].mNext) = 0;
          }
          else
          {
            v25 = 0i64;
          }
          v25->mUID = v23->mBaseNode.mUID;
          v25[1].mChild[1] = (UFG::qBaseNodeRB *)v23;
          UFG::qBaseTreeRB::Add(&v3->mPhysVolumeRefs.mTree, v25);
        }
      }
    }
  }
  v26 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mPhysVolumeRefs);
  while ( v26 )
  {
    v27 = v26->mRoot.mUID;
    if ( v27 == v3->mActiveVolumeUID[0]
      || v27 == v3->mActiveVolumeUID[1]
      || v27 == v3->mActiveVolumeUID[2]
      || v27 == v3->mActiveVolumeUID[3]
      || v27 == v3->mActiveVolumeUID[4]
      || v27 == v3->mActiveSurfaceUID
      || (v28 = v27 == v3->mActiveWetSurfaceUID, v29 = 0, v28) )
    {
      v29 = 1;
    }
    LOBYTE(v26->mNULL.mParent) = v29;
    v30 = (float *)v26->mNULL.mChild[1];
    if ( v30[29] <= 0.0 || (v31 = 1, !v3->InvulnerableToFire) )
      v31 = 0;
    BYTE1(v26->mNULL.mParent) = v31;
    if ( v31 )
    {
      v32 = &v26->mRoot;
      v33 = &v3->mPhysVolumeRefs.mTree;
      if ( v29 )
        goto LABEL_119;
    }
    else
    {
      if ( v29 )
      {
        *((float *)&v26->mNULL.mParent + 1) = v2 + *((float *)&v26->mNULL.mParent + 1);
        LODWORD(v26->mNULL.mChild[0]) = 0;
        v34 = v30[28];
        if ( v34 <= 0.0 )
          goto LABEL_83;
        v35 = v3->m_pSimObject;
        if ( !v35 )
          goto LABEL_83;
        v36 = (UFG::HealthComponent *)v35->m_Components.p[6].m_pComponent;
        if ( !v36 )
          goto LABEL_83;
        v37 = v3->mIsAttachedToPlayer ? FLOAT_100_0 : (float)(signed int)v36->m_fMaxHealth;
        v38 = (float)((float)(v34 * v37) * v2) + v3->mQueuedHealthDamage;
        v3->mQueuedHealthDamage = v38;
        if ( v38 <= 5.0 )
          goto LABEL_83;
        v39 = *((float *)&v26->mNULL.mChild[1][3].mChild[1] + 1) > 0.0;
        if ( v39 != 1
          || !v35
          || (v40 = (UFG::HitReactionComponent *)v35->m_Components.p[15].m_pComponent) == 0i64
          || UFG::PhysicsVolumePropertyManager::FireHitRecordType == -1 )
        {
          UFG::HealthComponent::ApplyHealthDamage(v36, 5, v35, 0i64, 0);
          goto LABEL_77;
        }
        UFG::HitRecord::HitRecord(&__that);
        v41 = UFG::PhysicsVolumePropertyManager::FireHitRecordType;
        __that.mAttackTypeID = UFG::PhysicsVolumePropertyManager::FireHitRecordType;
        __that.mDamage = 5;
        if ( __that.mAttacker.m_pPointer )
        {
          v42 = __that.mAttacker.mPrev;
          v43 = __that.mAttacker.mNext;
          __that.mAttacker.mPrev->mNext = __that.mAttacker.mNext;
          v43->mPrev = v42;
          __that.mAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.mAttacker.mPrev;
          __that.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.mAttacker.mPrev;
          v41 = __that.mAttackTypeID;
        }
        v44 = 0i64;
        __that.mAttacker.m_pPointer = 0i64;
        *(_QWORD *)&__that.mTimeSinceHit = 0i64;
        if ( v40->mHitRecord.mHitRecordProcessed != 1 )
        {
          v45 = v41 == gAttackCollisionProjectile.m_EnumValue
             && v40->mHitRecord.mAttackTypeID == gAttackCollisionProjectile.m_EnumValue;
          v46 = v41 > v40->mHitRecord.mAttackTypeID;
          if ( v45 )
          {
            ++v40->mNumHits;
            v47 = UFG::qMalloc(0x128ui64, UFG::gGlobalNewName, 0i64);
            v78 = v47;
            if ( v47 )
            {
              UFG::HitRecord::HitRecord((UFG::HitRecord *)v47);
              v44 = v48;
            }
            UFG::HitRecord::operator=(v44, &__that);
            v49 = v40->mHitRecord.mNext;
            v40->mHitRecord.mNext = v44;
            v44->mNext = v49;
LABEL_75:
            UFG::HitRecord::~HitRecord(&__that);
LABEL_77:
            v3->mQueuedHealthDamage = v3->mQueuedHealthDamage - 5.0;
            if ( v39 && (signed int)v36->m_fHealth < 1 )
            {
              if ( v3->mIsAttachedToPlayer )
                v50 = UFG::CharacterEffectsComponent::sTimeFireIsActivePlayer;
              else
                v50 = UFG::CharacterEffectsComponent::sTimeFireIsActive;
              v3->mFireExtinguishTime = v50;
              UFG::CharacterEffectsComponent::IgniteFire(v3);
            }
LABEL_83:
            if ( *((float *)&v26->mNULL.mChild[1][3].mChild[1] + 1) > 0.0 )
            {
              if ( _S68 & 1 )
              {
                v51 = physVol_OnFire;
              }
              else
              {
                _S68 |= 1u;
                v51 = UFG::qStringHashUpper32("PhysVol_OnFire", 0xFFFFFFFF);
                physVol_OnFire = v51;
              }
              v52 = v3->mIsOnFire;
              if ( !v52 || v26->mNULL.mChild[1]->mChild[0] != (UFG::qBaseNodeRB *)v51 )
              {
                if ( v3->mIsAttachedToPlayer )
                  v53 = UFG::CharacterEffectsComponent::sTimeFireIsActivePlayer;
                else
                  v53 = UFG::CharacterEffectsComponent::sTimeFireIsActive;
                v3->mFireExtinguishTime = v53;
              }
              v3->mSmolderExtinguishTime = UFG::CharacterEffectsComponent::sTimeSmolderIsActive;
              if ( !v3->mIsSmoldering && !v52 )
                UFG::CharacterEffectsComponent::IgniteSmolder(v3);
            }
            if ( v26->mNULL.mChild[1][3].mUID == -1 )
              goto LABEL_118;
            if ( LOBYTE(v26->mNULL.mUID) )
              goto LABEL_118;
            v54 = v3->m_pSimObject;
            if ( !v54 )
              goto LABEL_118;
            v55 = (UFG::HitReactionComponent *)v54->m_Components.p[15].m_pComponent;
            if ( !v55 )
              goto LABEL_118;
            UFG::HitRecord::HitRecord(&hitrecord);
            v56 = v26->mNULL.mChild[1];
            v57 = v56[3].mUID;
            hitrecord.mAttackTypeID = v56[3].mUID;
            hitrecord.mDamage = 0;
            if ( hitrecord.mAttacker.m_pPointer )
            {
              v58 = hitrecord.mAttacker.mPrev;
              v59 = hitrecord.mAttacker.mNext;
              hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
              v59->mPrev = v58;
              hitrecord.mAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
              hitrecord.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
              v57 = hitrecord.mAttackTypeID;
            }
            hitrecord.mAttacker.m_pPointer = 0i64;
            *(_QWORD *)&hitrecord.mTimeSinceHit = 0i64;
            if ( v55->mHitRecord.mHitRecordProcessed != 1 )
            {
              v60 = v57 == gAttackCollisionProjectile.m_EnumValue
                 && v55->mHitRecord.mAttackTypeID == gAttackCollisionProjectile.m_EnumValue;
              v61 = v57 > v55->mHitRecord.mAttackTypeID;
              if ( v60 )
              {
                ++v55->mNumHits;
                v62 = UFG::qMalloc(0x128ui64, UFG::gGlobalNewName, 0i64);
                v78 = v62;
                if ( v62 )
                {
                  UFG::HitRecord::HitRecord((UFG::HitRecord *)v62);
                  v64 = v63;
                }
                else
                {
                  v64 = 0i64;
                }
                UFG::HitRecord::operator=(v64, &hitrecord);
                v65 = v55->mHitRecord.mNext;
                v55->mHitRecord.mNext = v64;
                v64->mNext = v65;
LABEL_114:
                LOBYTE(v26->mNULL.mUID) = 1;
                UFG::HitRecord::~HitRecord(&hitrecord);
LABEL_118:
                v32 = &v26->mRoot;
                v33 = &v3->mPhysVolumeRefs.mTree;
LABEL_119:
                v26 = UFG::qBaseTreeRB::GetNext(v33, v32);
                continue;
              }
              if ( !v61 )
                goto LABEL_114;
            }
            UFG::HitReactionComponent::SetHitRecord(v55, &hitrecord);
            goto LABEL_114;
          }
          if ( !v46 )
            goto LABEL_75;
        }
        UFG::HitReactionComponent::SetHitRecord(v40, &__that);
        goto LABEL_75;
      }
      v66 = v2 + *(float *)v26->mNULL.mChild;
      *(float *)v26->mNULL.mChild = v66;
      if ( v66 <= v30[27] )
        goto LABEL_118;
      v32 = &v26->mRoot;
      v33 = &v3->mPhysVolumeRefs.mTree;
    }
    v67 = UFG::qBaseTreeRB::GetNext(v33, v32);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mPhysVolumeRefs,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)v26);
    operator delete[](v26);
    v26 = v67;
  }
  if ( v3->mIsOnFire )
  {
    v68 = v3->mFireExtinguishTime - v2;
    v3->mFireExtinguishTime = v68;
    if ( v68 < 0.0 || v3->InvulnerableToFire )
      UFG::CharacterEffectsComponent::ExtinguishFire(v3);
    if ( v3->mPhantomRigidBody )
    {
      v69 = v3->m_pSimObject->m_Components.p;
      v70 = v69[2].m_pComponent;
      if ( v70 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v69[2].m_pComponent);
        v74.mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v70[2].vfptr;
        v74.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v70[2].m_SafePointerList.mNode.mPrev;
        v74.mTypeUID = (unsigned __int64)v70[2].m_SafePointerList.mNode.mNext;
        v74.mNameUID = *(_QWORD *)&v70[2].m_TypeUID;
        v74.mData = *(UFG::qReflectObject **)&v70[2].m_Flags;
        *(_DWORD *)&hitrecord.mHitRecordProcessed = v70[2].m_pSimObject;
        hitrecord.mAttackTypeID = HIDWORD(v70[2].m_pSimObject);
        hitrecord.mDamage = (int)v70[2].m_BoundComponentHandles.mNode.mPrev;
        *(&hitrecord.mDamage + 1) = HIDWORD(v70[2].m_BoundComponentHandles.mNode.mPrev);
        v71 = *(float *)&v70[2].m_BoundComponentHandles.mNode.mNext;
        HIDWORD(hitrecord.mAttacker.mPrev) = HIDWORD(v70[2].m_BoundComponentHandles.mNode.mNext);
        *(float *)&hitrecord.mAttacker.mPrev = v71 + 1.0;
        hkTransformf::set4x4ColumnMajor(&transform, (const float *)&v74);
        hkpRigidBody::setTransform(v3->mPhantomRigidBody, &transform);
      }
    }
  }
  if ( v3->mIsSmoldering )
  {
    v72 = v3->mSmolderExtinguishTime - v2;
    v3->mSmolderExtinguishTime = v72;
    if ( v72 < 0.0 || v3->InvulnerableToFire )
      UFG::CharacterEffectsComponent::ExtinguishSmolder(v3);
  }
  v73 = UFG::WorldEffectsManager::Get();
  UFG::WorldEffectsManager::UpdateUIEffects(v73, v3);
}

// File Line: 673
// RVA: 0x535140
void __fastcall UFG::CharacterEffectsComponent::HandleWaterCollision(UFG::CharacterEffectsComponent *this, UFG::qMatrix44 *mat, UFG::qVector3 *characterVelocity)
{
  UFG::SimComponent *v3; // rdi
  int v4; // esi
  UFG::qMatrix44 *v5; // rbp
  UFG::CharacterEffectsComponent *v6; // rbx
  Creature *v7; // rdi
  UFG::qWiseSymbol *v8; // rax
  int v9; // eax
  UFG::SimComponent *v10; // rdi
  Creature *v11; // rdi
  UFG::qWiseSymbol *v12; // rax
  UFG::TransformNodeComponent *v13; // rcx
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-88h]
  UFG::qMatrix44 m; // [rsp+60h] [rbp-48h]
  UFG::qWiseSymbol result; // [rsp+B0h] [rbp+8h]

  v3 = this->mCharacterAnimationComponent.m_pSimComponent;
  v4 = -1;
  v5 = mat;
  v6 = this;
  if ( v3 )
  {
    v7 = *(Creature **)&v3[2].m_TypeUID;
    if ( v7 )
    {
      v8 = UFG::qSymbol::qSymbol(&result, 0x8C4CF328);
      if ( v7->mPose.mRigHandle.mData )
        v9 = Skeleton::GetBoneID(v7->mPose.mRigHandle.mUFGSkeleton, v8->mUID);
      else
        v9 = -1;
      Creature::GetTransform(v7, v9, &transform);
    }
  }
  v10 = v6->mCharacterAnimationComponent.m_pSimComponent;
  if ( v10 )
  {
    v11 = *(Creature **)&v10[2].m_TypeUID;
    if ( v11 )
    {
      v12 = UFG::qSymbol::qSymbol(&result, 0xB9BD7DCF);
      if ( v11->mPose.mRigHandle.mData )
        v4 = Skeleton::GetBoneID(v11->mPose.mRigHandle.mUFGSkeleton, v12->mUID);
      Creature::GetTransform(v11, v4, &m);
    }
  }
  v13 = v6->mNodes[0];
  transform.v3.z = v5->v3.z;
  m.v3.z = transform.v3.z;
  UFG::TransformNodeComponent::SetLocalTransform(v13, &transform);
  UFG::TransformNodeComponent::SetLocalTransform(v6->mNodes[1], &m);
  if ( v6->mIsOnFire )
    UFG::CharacterEffectsComponent::ExtinguishFire(v6);
  if ( v6->mIsSmoldering )
    UFG::CharacterEffectsComponent::ExtinguishSmolder(v6);
}

// File Line: 723
// RVA: 0x524970
void __fastcall UFG::CharacterEffectsComponent::CreateNodes(UFG::CharacterEffectsComponent *this)
{
  _QWORD *v1; // rbx
  signed __int64 v2; // rdi
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax

  v1 = this->mNodes;
  v2 = 2i64;
  do
  {
    v3 = UFG::GetSimulationMemoryPool();
    v4 = UFG::qMemoryPool::Allocate(v3, 0x110ui64, "CharacterEffectsComponent::TransformNodeComponet", 0i64, 1u);
    if ( v4 )
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v4, 0xDEADBEEF, 0i64, 0);
    *v1 = v4;
    ++v1;
    --v2;
  }
  while ( v2 );
}

// File Line: 767
// RVA: 0x52A2B0
void __fastcall UFG::CharacterEffectsComponent::ForceIgniteFire(UFG::CharacterEffectsComponent *this)
{
  if ( this->mIsAttachedToPlayer )
    this->mFireExtinguishTime = UFG::CharacterEffectsComponent::sTimeFireIsActivePlayer;
  else
    this->mFireExtinguishTime = UFG::CharacterEffectsComponent::sTimeFireIsActive;
  UFG::CharacterEffectsComponent::IgniteFire(this);
}

// File Line: 776
// RVA: 0x54D2A0
void __fastcall UFG::CharacterEffectsComponent::SetFootstepOverride(UFG::CharacterEffectsComponent *this, unsigned int leftFootEffectID, unsigned int rightFootEffectID)
{
  this->mFootstepOverride[0] = leftFootEffectID;
  this->mFootstepOverride[1] = rightFootEffectID;
}

// File Line: 785
// RVA: 0x535AD0
void __fastcall UFG::CharacterEffectsComponent::IgniteFire(UFG::CharacterEffectsComponent *this)
{
  UFG::CharacterEffectsComponent *v1; // rbx
  bool v2; // zf
  UFG::SimObject *v3; // rax
  unsigned int v4; // er8
  unsigned int v5; // er10
  signed __int64 v6; // rdx
  Render::FXSimComponent *v7; // rdi
  hkpRigidBody *v8; // rcx
  UFG::SimComponentHolder *v9; // rcx
  float *v10; // rdi
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  unsigned int v26; // eax
  UFG::CharacterAnimationComponent *v27; // rcx
  UFG::qVector3 halfExtents; // [rsp+30h] [rbp-58h]
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-48h]

  v1 = this;
  if ( !this->mIsOnFire )
  {
    v2 = this->mIsSmoldering == 0;
    this->mIsOnFire = 1;
    if ( !v2 )
      UFG::CharacterEffectsComponent::ExtinguishSmolder(this);
    v3 = v1->m_pSimObject;
    if ( v3 )
    {
      v4 = (unsigned int)v3[1].vfptr;
      v5 = v3->m_Components.size;
      if ( v4 < v5 )
      {
        v6 = (signed __int64)&v3->m_Components.p[v4];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
             || Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
        {
          ++v4;
          v6 += 16i64;
          if ( v4 >= v5 )
            goto LABEL_13;
        }
        v7 = *(Render::FXSimComponent **)v6;
        if ( *(_QWORD *)v6 )
        {
          v1->mFireEffectID[0] = Render::FXSimComponent::AttachEffect(v7, 0xA6B7A27D, 1, 0i64);
          v1->mFireEffectID[1] = Render::FXSimComponent::AttachEffect(v7, 0x6811A3DBu, 13, 0i64);
          v1->mFireEffectID[2] = Render::FXSimComponent::AttachEffect(v7, 0x6811A3DBu, 14, 0i64);
        }
      }
    }
LABEL_13:
    v8 = v1->mPhantomRigidBody;
    if ( v8 )
    {
      UFG::PhantomCallback::DestroyPhantom(v8);
      v1->mPhantomRigidBody = 0i64;
    }
    v9 = v1->m_pSimObject->m_Components.p;
    v10 = (float *)v9[2].m_pComponent;
    if ( v10 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9[2].m_pComponent);
      v11 = v10[32];
      v12 = v10[33];
      v13 = v10[46];
      halfExtents.x = 0.5;
      halfExtents.y = 0.5;
      halfExtents.z = 1.0;
      transform.v0.x = v11;
      transform.v0.z = v10[34];
      v14 = v10[36];
      transform.v0.y = v12;
      v15 = v10[35];
      transform.v1.x = v14;
      v16 = v10[38];
      transform.v0.w = v15;
      v17 = v10[37];
      transform.v1.z = v16;
      v18 = v10[40];
      transform.v1.y = v17;
      v19 = v10[39];
      transform.v2.x = v18;
      v20 = v10[42];
      transform.v1.w = v19;
      v21 = v10[41];
      transform.v2.z = v20;
      v22 = v10[44];
      transform.v2.y = v21;
      v23 = v10[43];
      transform.v3.x = v22;
      v24 = v10[47];
      transform.v2.w = v23;
      v25 = v10[45];
      transform.v3.w = v24;
      transform.v3.y = v25;
      transform.v3.z = v13 + 1.0;
      v26 = UFG::qStringHashUpper32("PhysVol_OnFire", 0xFFFFFFFF);
      v1->mPhantomRigidBody = (hkpRigidBody *)UFG::PhantomCallback::CreatePhantom(&halfExtents, &transform, v26);
    }
    v27 = (UFG::CharacterAnimationComponent *)v1->mCharacterAnimationComponent.m_pSimComponent;
    if ( v27 )
      UFG::CharacterAnimationComponent::ApplyCharredEffect(v27, 1.0);
  }
}

// File Line: 840
// RVA: 0x527A20
void __fastcall UFG::CharacterEffectsComponent::ExtinguishFire(UFG::CharacterEffectsComponent *this)
{
  UFG::CharacterEffectsComponent *v1; // rbx
  UFG::SimObject *v2; // rax
  unsigned int v3; // er8
  unsigned int v4; // er9
  signed __int64 v5; // rdx
  Render::FXSimComponent *v6; // rdi
  hkpRigidBody *v7; // rcx

  v1 = this;
  if ( this->mIsOnFire )
  {
    v2 = this->m_pSimObject;
    this->mIsOnFire = 0;
    if ( v2 )
    {
      v3 = (unsigned int)v2[1].vfptr;
      v4 = v2->m_Components.size;
      if ( v3 < v4 )
      {
        v5 = (signed __int64)&v2->m_Components.p[v3];
        while ( (*(_DWORD *)(v5 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
             || Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v5 + 8) & 0x1FFFFFF )
        {
          ++v3;
          v5 += 16i64;
          if ( v3 >= v4 )
            goto LABEL_11;
        }
        v6 = *(Render::FXSimComponent **)v5;
        if ( *(_QWORD *)v5 )
        {
          Render::FXSimComponent::DetachEffect(v6, this->mFireEffectID[0], 0);
          Render::FXSimComponent::DetachEffect(v6, v1->mFireEffectID[1], 0);
          Render::FXSimComponent::DetachEffect(v6, v1->mFireEffectID[2], 0);
        }
      }
    }
LABEL_11:
    v7 = v1->mPhantomRigidBody;
    if ( v7 )
    {
      UFG::PhantomCallback::DestroyPhantom(v7);
      v1->mPhantomRigidBody = 0i64;
    }
  }
}

// File Line: 872
// RVA: 0x535D70
void __fastcall UFG::CharacterEffectsComponent::IgniteSmolder(UFG::CharacterEffectsComponent *this)
{
  UFG::CharacterEffectsComponent *v1; // rsi
  UFG::SimObject *v2; // rbx
  unsigned __int16 v3; // dx
  unsigned int v4; // er8
  unsigned int v5; // er9
  signed __int64 v6; // rdx
  Render::FXSimComponent *v7; // rdi
  unsigned int v8; // er8
  unsigned int v9; // er9
  unsigned int v10; // er8
  unsigned int v11; // er9
  unsigned int v12; // er8
  unsigned int v13; // er9
  unsigned __int16 v14; // cx
  UFG::ActorAudioComponent *v15; // rcx
  unsigned int v16; // er8
  unsigned int v17; // er9
  signed __int64 v18; // rdx
  unsigned int v19; // er8
  unsigned int v20; // er9
  unsigned int v21; // er8
  unsigned int v22; // er9

  v1 = this;
  if ( !this->mIsSmoldering )
  {
    v2 = this->m_pSimObject;
    this->mIsSmoldering = 1;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = (unsigned int)v2[1].vfptr;
        v5 = v2->m_Components.size;
        if ( v4 < v5 )
        {
          v6 = (signed __int64)&v2->m_Components.p[v4];
          while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
               || Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
          {
            ++v4;
            v6 += 16i64;
            if ( v4 >= v5 )
              goto LABEL_9;
          }
LABEL_10:
          v7 = *(Render::FXSimComponent **)v6;
          goto LABEL_33;
        }
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v10 = (unsigned int)v2[1].vfptr;
          v11 = v2->m_Components.size;
          if ( v10 < v11 )
          {
            v6 = (signed __int64)&v2->m_Components.p[v10];
            while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
                 || Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
            {
              ++v10;
              v6 += 16i64;
              if ( v10 >= v11 )
              {
                v7 = 0i64;
                goto LABEL_33;
              }
            }
            goto LABEL_10;
          }
        }
        else
        {
          if ( !((v3 >> 12) & 1) )
          {
            v7 = (Render::FXSimComponent *)UFG::SimObject::GetComponentOfType(v2, Render::FXSimComponent::_TypeUID);
LABEL_33:
            if ( v7 )
            {
              v1->mSmolderEffectID[0] = Render::FXSimComponent::AttachEffect(v7, 0x88AA83Au, 1, 0i64);
              v1->mSmolderEffectID[1] = Render::FXSimComponent::AttachEffect(v7, 0xCF8F3EA9, 13, 0i64);
              v1->mSmolderEffectID[2] = Render::FXSimComponent::AttachEffect(v7, 0xCF8F3EA9, 14, 0i64);
            }
            v14 = v2->m_Flags;
            if ( (v14 >> 14) & 1 )
            {
              v15 = (UFG::ActorAudioComponent *)v2->m_Components.p[40].m_pComponent;
              if ( v15
                && !((UFG::ActorAudioComponent::_TypeUID ^ v15->m_TypeUID) & 0xFE000000)
                && !(UFG::ActorAudioComponent::_TypeUID & ~v15->m_TypeUID & 0x1FFFFFF) )
              {
                goto LABEL_63;
              }
              goto LABEL_39;
            }
            if ( (v14 & 0x8000u) == 0 )
            {
              if ( (v14 >> 13) & 1 )
              {
                v19 = (unsigned int)v2[1].vfptr;
                v20 = v2->m_Components.size;
                if ( v19 < v20 )
                {
                  v18 = (signed __int64)&v2->m_Components.p[v19];
                  while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
                       || UFG::ActorAudioComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
                  {
                    ++v19;
                    v18 += 16i64;
                    if ( v19 >= v20 )
                    {
                      v15 = 0i64;
                      goto LABEL_63;
                    }
                  }
                  goto LABEL_47;
                }
              }
              else
              {
                if ( !((v14 >> 12) & 1) )
                {
                  v15 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                      v2,
                                                      UFG::ActorAudioComponent::_TypeUID);
LABEL_63:
                  if ( v15 )
                    UFG::ActorAudioComponent::PlayScreamPain(v15);
                  return;
                }
                v21 = (unsigned int)v2[1].vfptr;
                v22 = v2->m_Components.size;
                if ( v21 < v22 )
                {
                  v18 = (signed __int64)&v2->m_Components.p[v21];
                  while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
                       || UFG::ActorAudioComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
                  {
                    ++v21;
                    v18 += 16i64;
                    if ( v21 >= v22 )
                    {
                      v15 = 0i64;
                      goto LABEL_63;
                    }
                  }
                  goto LABEL_47;
                }
              }
            }
            else
            {
              v16 = (unsigned int)v2[1].vfptr;
              v17 = v2->m_Components.size;
              if ( v16 < v17 )
              {
                v18 = (signed __int64)&v2->m_Components.p[v16];
                while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
                     || UFG::ActorAudioComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
                {
                  ++v16;
                  v18 += 16i64;
                  if ( v16 >= v17 )
                  {
                    v15 = 0i64;
                    goto LABEL_63;
                  }
                }
LABEL_47:
                v15 = *(UFG::ActorAudioComponent **)v18;
                goto LABEL_63;
              }
            }
LABEL_39:
            v15 = 0i64;
            goto LABEL_63;
          }
          v12 = (unsigned int)v2[1].vfptr;
          v13 = v2->m_Components.size;
          if ( v12 < v13 )
          {
            v6 = (signed __int64)&v2->m_Components.p[v12];
            while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
                 || Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
            {
              ++v12;
              v6 += 16i64;
              if ( v12 >= v13 )
              {
                v7 = 0i64;
                goto LABEL_33;
              }
            }
            goto LABEL_10;
          }
        }
      }
      else
      {
        v8 = (unsigned int)v2[1].vfptr;
        v9 = v2->m_Components.size;
        if ( v8 < v9 )
        {
          v6 = (signed __int64)&v2->m_Components.p[v8];
          while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
               || Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
          {
            ++v8;
            v6 += 16i64;
            if ( v8 >= v9 )
            {
              v7 = 0i64;
              goto LABEL_33;
            }
          }
          goto LABEL_10;
        }
      }
LABEL_9:
      v7 = 0i64;
      goto LABEL_33;
    }
  }
}

// File Line: 897
// RVA: 0x527B20
void __fastcall UFG::CharacterEffectsComponent::ExtinguishSmolder(UFG::CharacterEffectsComponent *this)
{
  UFG::CharacterEffectsComponent *v1; // rbx
  UFG::SimObject *v2; // rax
  unsigned int v3; // er8
  unsigned int v4; // er9
  signed __int64 v5; // rdx
  Render::FXSimComponent *v6; // rdi

  v1 = this;
  if ( this->mIsSmoldering )
  {
    v2 = this->m_pSimObject;
    this->mIsSmoldering = 0;
    if ( v2 )
    {
      v3 = (unsigned int)v2[1].vfptr;
      v4 = v2->m_Components.size;
      if ( v3 < v4 )
      {
        v5 = (signed __int64)&v2->m_Components.p[v3];
        while ( (*(_DWORD *)(v5 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
             || Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v5 + 8) & 0x1FFFFFF )
        {
          ++v3;
          v5 += 16i64;
          if ( v3 >= v4 )
            return;
        }
        v6 = *(Render::FXSimComponent **)v5;
        if ( *(_QWORD *)v5 )
        {
          Render::FXSimComponent::DetachEffect(v6, this->mSmolderEffectID[0], 0);
          Render::FXSimComponent::DetachEffect(v6, v1->mSmolderEffectID[1], 0);
          Render::FXSimComponent::DetachEffect(v6, v1->mSmolderEffectID[2], 0);
        }
      }
    }
  }
}

