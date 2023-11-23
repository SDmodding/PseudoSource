// File Line: 46
// RVA: 0x1544980
__int64 UFG::_anonymous_namespace_::_dynamic_initializer_for__IsEliteFighterSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("IsEliteFighter", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&IsEliteFighterSymbol, v0);
  return atexit((int (__fastcall *)())UFG::_anonymous_namespace_::_dynamic_atexit_destructor_for__IsEliteFighterSymbol__);
}

// File Line: 47
// RVA: 0x15448C0
__int64 UFG::_anonymous_namespace_::_dynamic_initializer_for__FootWearUnderwearSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("FootwearUnderwear", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&FootWearUnderwearSymbol, v0);
  return atexit((int (__fastcall *)())UFG::_anonymous_namespace_::_dynamic_atexit_destructor_for__FootWearUnderwearSymbol__);
}

// File Line: 69
// RVA: 0x1543DC0
__int64 dynamic_initializer_for__UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList__);
}

// File Line: 70
// RVA: 0x5323B0
const char *__fastcall UFG::CharacterEffectsComponent::GetTypeName(UFG::CharacterEffectsComponent *this)
{
  return "CharacterEffectsComponent";
}

// File Line: 96
// RVA: 0x516250
void __fastcall UFG::CharacterEffectsComponent::CharacterEffectsComponent(
        UFG::CharacterEffectsComponent *this,
        unsigned int name_uid,
        component_CharacterEffects *data,
        UFG::qPropertySet *properties)
{
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent>;
  this->mNext = &this->UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterEffectsComponent::`vftable;
  *(_WORD *)&this->InvulnerableToFire = 256;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&this->mCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>(&this->mCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::PhantomVolumeComponent,0>::RebindingComponentHandle<UFG::PhantomVolumeComponent,0>(&this->mPhantomVolumeComponent);
  this->mWalkingThroughWaterEffect.mUID = -1;
  this->mMaxWaterDepthForWalkingThroughWaterEffect = 0.0;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mPhysVolumeRefs.mTree);
  *(_QWORD *)&this->mActiveSurfaceUID = 0i64;
  this->mIsOnFire = 0;
  this->mIsSmoldering = 0;
  *(_QWORD *)&this->mFireExtinguishTime = 0i64;
  this->mQueuedHealthDamage = 0.0;
  this->mPhantomRigidBody = 0i64;
  this->mIsAttachedToPlayer = 0;
  this->mUIElementIndex = -1;
  this->mIsEliteFighter = 0;
  mPrev = UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList.mNode.mPrev;
  UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *)&UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList;
  UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList.mNode.mPrev = &this->UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::CharacterEffectsComponent::_CharacterEffectsComponentTypeUID,
    "CharacterEffectsComponent");
  *(_QWORD *)this->mActiveVolumeUID = 0i64;
  *(_QWORD *)&this->mActiveVolumeUID[2] = 0i64;
  this->mActiveVolumeUID[4] = 0;
  *(_QWORD *)this->mFootstepOverride = -1i64;
  this->mWalkingThroughWaterEffect.mUID = data->fxPlayerWalkingThroughWater.mUID;
  this->mWalkingThroughWaterMinSpeedForEffectSqr = data->fxPlayerWalkingThroughWaterMinSpeed
                                                 * data->fxPlayerWalkingThroughWaterMinSpeed;
  this->mMaxWaterDepthForWalkingThroughWaterEffect = data->fxMaxWaterDepthForWalkingThroughWaterEffect;
  this->mIsEliteFighter = *UFG::qPropertySet::Get<bool>(
                             properties,
                             (UFG::qArray<unsigned long,0> *)&IsEliteFighterSymbol,
                             DEPTH_RECURSE);
  UFG::CharacterEffectsComponent::CreateNodes(this);
}

// File Line: 115
// RVA: 0x51AF20
void __fastcall UFG::CharacterEffectsComponent::~CharacterEffectsComponent(UFG::CharacterEffectsComponent *this)
{
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *v2; // r14
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *mPrev; // rcx
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *mNext; // rax
  UFG::TransformNodeComponent **mNodes; // rbx
  __int64 v6; // rdi
  Render::SkinningCacheNode *Head; // rbx
  UFG::WorldEffectsManager *v8; // rax
  Render::SkinningCacheNode *v9; // rbx
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *v10; // rcx
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterEffectsComponent::`vftable;
  if ( this == UFG::CharacterEffectsComponent::s_CharacterEffectsComponentpCurrentIterator )
    UFG::CharacterEffectsComponent::s_CharacterEffectsComponentpCurrentIterator = (UFG::CharacterEffectsComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  mNodes = this->mNodes;
  v6 = 2i64;
  do
  {
    if ( *mNodes )
      (*mNodes)->vfptr->__vecDelDtor(*mNodes, 1u);
    *mNodes++ = 0i64;
    --v6;
  }
  while ( v6 );
  while ( this->mPhysVolumeRefs.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mPhysVolumeRefs);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mPhysVolumeRefs,
      &Head->mNode);
    operator delete[](Head);
  }
  if ( this->mIsOnFire )
    UFG::CharacterEffectsComponent::ExtinguishFire(this);
  if ( this->mIsSmoldering )
    UFG::CharacterEffectsComponent::ExtinguishSmolder(this);
  v8 = UFG::WorldEffectsManager::Get();
  UFG::WorldEffectsManager::RemoveUIEffects(v8, this);
  while ( this->mPhysVolumeRefs.mTree.mCount )
  {
    v9 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mPhysVolumeRefs);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mPhysVolumeRefs,
      &v9->mNode);
    operator delete[](v9);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mPhysVolumeRefs);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mPhantomVolumeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mCharacterAnimationComponent);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 128
// RVA: 0x53D4F0
void __fastcall UFG::CharacterEffectsComponent::OnAttach(
        UFG::CharacterEffectsComponent *this,
        UFG::SimObjectCharacter *object)
{
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_mCharacterAnimationComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  if ( object == LocalPlayer )
    this->mIsAttachedToPlayer = 1;
  p_mCharacterAnimationComponent = &this->mCharacterAnimationComponent;
  if ( p_mCharacterAnimationComponent->m_pSimComponent )
  {
    mNext = p_mCharacterAnimationComponent->mNext;
    mPrev = p_mCharacterAnimationComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCharacterAnimationComponent->m_pSimComponent = 0i64;
LABEL_9:
    p_mCharacterAnimationComponent->m_pSimObject = 0i64;
    p_mCharacterAnimationComponent->mNext = p_mCharacterAnimationComponent;
    p_mCharacterAnimationComponent->mPrev = p_mCharacterAnimationComponent;
    goto LABEL_10;
  }
  if ( p_mCharacterAnimationComponent->m_pSimObject
    && (p_mCharacterAnimationComponent->mPrev != p_mCharacterAnimationComponent
     || p_mCharacterAnimationComponent->mNext != p_mCharacterAnimationComponent) )
  {
    v7 = p_mCharacterAnimationComponent->mNext;
    v8 = p_mCharacterAnimationComponent->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_9;
  }
LABEL_10:
  p_mCharacterAnimationComponent->m_Changed = 1;
  p_mCharacterAnimationComponent->m_pSimObject = object;
  p_mCharacterAnimationComponent->m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObjectVehicle>(
    p_mCharacterAnimationComponent,
    object);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->mCharacterPhysicsComponent,
    object);
  UFG::RebindingComponentHandle<UFG::PhantomVolumeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->mPhantomVolumeComponent,
    object);
}

// File Line: 144
// RVA: 0x53FDE0
void __fastcall UFG::CharacterEffectsComponent::OnDetach(UFG::CharacterEffectsComponent *this)
{
  UFG::WorldEffectsManager *v2; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_mCharacterAnimationComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *p_mCharacterPhysicsComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::RebindingComponentHandle<UFG::PhantomVolumeComponent,0> *p_mPhantomVolumeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax

  if ( this->mIsOnFire )
    UFG::CharacterEffectsComponent::ExtinguishFire(this);
  if ( this->mIsSmoldering )
    UFG::CharacterEffectsComponent::ExtinguishSmolder(this);
  v2 = UFG::WorldEffectsManager::Get();
  UFG::WorldEffectsManager::RemoveUIEffects(v2, this);
  p_mCharacterAnimationComponent = &this->mCharacterAnimationComponent;
  if ( this->mCharacterAnimationComponent.m_pSimComponent )
  {
    mPrev = p_mCharacterAnimationComponent->mPrev;
    mNext = this->mCharacterAnimationComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_11:
    this->mCharacterAnimationComponent.m_pSimObject = 0i64;
    this->mCharacterAnimationComponent.mNext = &this->mCharacterAnimationComponent;
    p_mCharacterAnimationComponent->mPrev = p_mCharacterAnimationComponent;
    goto LABEL_12;
  }
  if ( this->mCharacterAnimationComponent.m_pSimObject
    && (p_mCharacterAnimationComponent->mPrev != p_mCharacterAnimationComponent
     || this->mCharacterAnimationComponent.mNext != &this->mCharacterAnimationComponent) )
  {
    v6 = p_mCharacterAnimationComponent->mPrev;
    v7 = this->mCharacterAnimationComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    goto LABEL_11;
  }
LABEL_12:
  this->mCharacterAnimationComponent.m_Changed = 1;
  p_mCharacterPhysicsComponent = &this->mCharacterPhysicsComponent;
  if ( this->mCharacterPhysicsComponent.m_pSimComponent )
  {
    v9 = p_mCharacterPhysicsComponent->mPrev;
    v10 = this->mCharacterPhysicsComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    this->mCharacterPhysicsComponent.m_pSimComponent = 0i64;
LABEL_18:
    this->mCharacterPhysicsComponent.m_pSimObject = 0i64;
    this->mCharacterPhysicsComponent.mNext = &this->mCharacterPhysicsComponent;
    p_mCharacterPhysicsComponent->mPrev = p_mCharacterPhysicsComponent;
    goto LABEL_19;
  }
  if ( this->mCharacterPhysicsComponent.m_pSimObject
    && (p_mCharacterPhysicsComponent->mPrev != p_mCharacterPhysicsComponent
     || this->mCharacterPhysicsComponent.mNext != &this->mCharacterPhysicsComponent) )
  {
    v11 = p_mCharacterPhysicsComponent->mPrev;
    v12 = this->mCharacterPhysicsComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    goto LABEL_18;
  }
LABEL_19:
  this->mCharacterPhysicsComponent.m_Changed = 1;
  p_mPhantomVolumeComponent = &this->mPhantomVolumeComponent;
  if ( this->mPhantomVolumeComponent.m_pSimComponent )
  {
    v14 = p_mPhantomVolumeComponent->mPrev;
    v15 = this->mPhantomVolumeComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    this->mPhantomVolumeComponent.m_pSimComponent = 0i64;
LABEL_25:
    this->mPhantomVolumeComponent.m_pSimObject = 0i64;
    this->mPhantomVolumeComponent.mNext = &this->mPhantomVolumeComponent;
    p_mPhantomVolumeComponent->mPrev = p_mPhantomVolumeComponent;
    goto LABEL_26;
  }
  if ( this->mPhantomVolumeComponent.m_pSimObject
    && (p_mPhantomVolumeComponent->mPrev != p_mPhantomVolumeComponent
     || this->mPhantomVolumeComponent.mNext != &this->mPhantomVolumeComponent) )
  {
    v16 = p_mPhantomVolumeComponent->mPrev;
    v17 = this->mPhantomVolumeComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    goto LABEL_25;
  }
LABEL_26:
  this->mPhantomVolumeComponent.m_Changed = 1;
}

// File Line: 168
// RVA: 0x545FD0
UFG::SimComponent *__fastcall UFG::CharacterEffectsComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *sceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertySet *mpConstProperties; // r9
  UFG::SimComponent *v12; // rax
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_CharacterEffects::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    MemImagePtr = 0i64;
  if ( !required && !MemImagePtr )
    return 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x1B8ui64, "CharacterEffectsComponent", 0i64, 1u);
  if ( v10 )
  {
    mpConstProperties = sceneObject->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sceneObject->mpConstProperties;
    UFG::CharacterEffectsComponent::CharacterEffectsComponent(
      (UFG::CharacterEffectsComponent *)v10,
      sceneObject->m_NameUID,
      (component_CharacterEffects *)MemImagePtr,
      mpConstProperties);
    v6 = v12;
  }
  m_pSimObject = sceneObject->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v14 = 38;
  else
    v14 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v15, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v15, v6, v14);
  UFG::SimObjectModifier::Close(&v15);
  UFG::SimObjectModifier::~SimObjectModifier(&v15);
  return v6;
}

// File Line: 236
// RVA: 0x533E90
void __fastcall UFG::CharacterEffectsComponent::HandleFootstep(
        UFG::CharacterEffectsComponent *this,
        UFG::CharacterEffectsComponent::Foot foot)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  __int64 v3; // r14
  Creature *v5; // rbx
  unsigned int v6; // edx
  UFG::qWiseSymbol *v7; // rax
  int BoneID; // eax
  __m128 w_low; // xmm1
  float v10; // xmm7_4
  UFG::CharacterPhysicsComponent *v11; // rsi
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pComponent; // rbx
  float z; // xmm6_4
  int v15; // esi
  UFG::qBaseTreeRB *i; // rbx
  UFG::qBaseNodeRB *v17; // rax
  unsigned int mParent; // edx
  UFG::qBaseNodeRB *v19; // rax
  unsigned int mParent_high; // ecx
  unsigned int v21; // edx
  UFG::qMatrix44 basis; // [rsp+30h] [rbp-71h] BYREF
  __int128 v23; // [rsp+78h] [rbp-29h]
  UFG::qWiseSymbol result; // [rsp+110h] [rbp+6Fh] BYREF

  m_pSimComponent = this->mCharacterAnimationComponent.m_pSimComponent;
  v3 = foot;
  *(_QWORD *)&basis.v1.z = *(_QWORD *)&UFG::qMatrix44::msIdentity.v1.z;
  *(_QWORD *)&basis.v0.x = *(_QWORD *)&UFG::qMatrix44::msIdentity.v2.z;
  *(UFG::qVector4 *)&basis.v0.z = UFG::qMatrix44::msIdentity.v3;
  if ( foot )
  {
    if ( !m_pSimComponent )
      goto LABEL_12;
    v5 = *(Creature **)&m_pSimComponent[2].m_TypeUID;
    if ( !v5 )
      goto LABEL_12;
    v6 = 0xFA5EF3F6;
  }
  else
  {
    if ( !m_pSimComponent )
      goto LABEL_12;
    v5 = *(Creature **)&m_pSimComponent[2].m_TypeUID;
    if ( !v5 )
      goto LABEL_12;
    v6 = -810582767;
  }
  v7 = UFG::qSymbol::qSymbol(&result, v6);
  if ( v5->mPose.mRigHandle.mData )
    BoneID = Skeleton::GetBoneID(v5->mPose.mRigHandle.mUFGSkeleton, v7->mUID);
  else
    BoneID = -1;
  Creature::GetTransform(v5, BoneID, (UFG::qMatrix44 *)&basis.v1.z);
LABEL_12:
  w_low = (__m128)LODWORD(basis.v1.w);
  w_low.m128_f32[0] = (float)(w_low.m128_f32[0] * w_low.m128_f32[0]) + (float)(basis.v1.z * basis.v1.z);
  if ( w_low.m128_f32[0] == 0.0 )
    v10 = 0.0;
  else
    v10 = 1.0 / _mm_sqrt_ps(w_low).m128_f32[0];
  v11 = (UFG::CharacterPhysicsComponent *)this->mCharacterPhysicsComponent.m_pSimComponent;
  basis.v0.x = basis.v1.z * v10;
  basis.v0.y = basis.v1.w * v10;
  *(_OWORD *)&basis.v0.z = v23;
  basis.v1.z = (float)((float)(basis.v1.w * v10) * UFG::qVector3::msAxisZ.x)
             - (float)((float)(basis.v1.z * v10) * UFG::qVector3::msAxisZ.y);
  if ( v11 && UFG::CharacterPhysicsComponent::IsInWater(v11) )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      m_pComponent = (UFG::TransformNodeComponent *)m_pSimObject->m_Components.p[2].m_pComponent;
    else
      m_pComponent = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
    z = m_pComponent->mWorldTransform.v3.z;
    if ( (float)(UFG::CharacterPhysicsComponent::GetWaterElevation(v11) - z) >= this->mMaxWaterDepthForWalkingThroughWaterEffect )
    {
      if ( this->mIsOnFire )
        UFG::CharacterEffectsComponent::ExtinguishFire(this);
      if ( this->mIsSmoldering )
        UFG::CharacterEffectsComponent::ExtinguishSmolder(this);
    }
    else
    {
      Render::FXManager::CreateEffect(
        &Render::gFXManager,
        this->mWalkingThroughWaterEffect.mUID,
        this->mNodes[v3],
        0xFFFFFFFF,
        0i64);
    }
  }
  v15 = -1;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mPhysVolumeRefs);
        i;
        i = UFG::qBaseTreeRB::GetNext(&this->mPhysVolumeRefs.mTree, &i->mRoot) )
  {
    if ( !BYTE1(i->mNULL.mParent) )
    {
      v17 = i->mNULL.mChild[1];
      if ( *((float *)&v17[3].mChild[1] + 1) <= 0.0 || this->mIsOnFire )
      {
        if ( LOBYTE(i->mNULL.mParent) )
        {
          mParent = (unsigned int)v17[3].mParent;
          if ( mParent != -1 )
            Render::FXManager::CreateEffect(&Render::gFXManager, mParent, &basis, 0xFFFFFFFF);
        }
        v19 = i->mNULL.mChild[1];
        if ( (_DWORD)v3 )
          mParent_high = (unsigned int)v19[3].mChild[0];
        else
          mParent_high = HIDWORD(v19[3].mParent);
        if ( mParent_high != -1 )
        {
          v15 = mParent_high;
          Render::FXManager::CreateEffect(&Render::gFXManager, mParent_high, &basis, 0xFFFFFFFF);
        }
      }
    }
  }
  v21 = this->mFootstepOverride[v3];
  if ( v21 != -1 && v21 != v15 )
    Render::FXManager::CreateEffect(&Render::gFXManager, v21, &basis, 0xFFFFFFFF);
}

// File Line: 332
// RVA: 0x559AF0
void __fastcall UFG::CharacterEffectsComponent::Update(UFG::CharacterEffectsComponent *this, float delta_sec)
{
  UFG::PhantomVolumeComponent *m_pSimComponent; // r14
  unsigned __int8 i; // bl
  UFG::PhysicsVolumeProperties *Properties; // rax
  UFG::qBaseNodeRB *v7; // rsi
  unsigned __int64 mUID; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::qBaseNodeRB *v10; // rdx
  UFG::SimComponent *v11; // rax
  unsigned __int64 mPrev; // rsi
  unsigned __int64 mNext; // rbx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v14; // rcx
  const char *TypeName; // rax
  UFG::qReflectObject *mData; // rax
  unsigned int v17; // ebx
  const char *v18; // rax
  UFG::qReflectObject *v19; // rax
  UFG::qReflectObject *v20; // rbx
  UFG::allocator::free_link *v21; // rax
  UFG::qBaseNodeRB *v22; // rdx
  UFG::qReflectObject *v23; // rbx
  UFG::allocator::free_link *v24; // rax
  UFG::qBaseNodeRB *v25; // rdx
  UFG::qBaseTreeRB *Head; // rsi
  unsigned int v27; // eax
  bool v28; // zf
  char v29; // al
  float *v30; // rdx
  char v31; // cl
  UFG::qBaseNodeRB *p_mRoot; // rdx
  UFG::qTreeRB<UFG::CharacterEffectsComponent::PhysVolumeRef,UFG::CharacterEffectsComponent::PhysVolumeRef,1> *p_mPhysVolumeRefs; // rcx
  float v34; // xmm1_4
  UFG::SimObjectCharacter *m_pSimObject; // r8
  UFG::HealthComponent *m_pComponent; // r15
  float v37; // xmm0_4
  float v38; // xmm1_4
  bool v39; // r12
  UFG::HitReactionComponent *v40; // rbx
  int mAttackTypeID; // ecx
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
  bool mIsOnFire; // r8
  float v53; // xmm0_4
  UFG::SimObject *v54; // rax
  UFG::HitReactionComponent *v55; // rbx
  int v56; // ecx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v57; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v58; // rax
  bool v59; // al
  bool v60; // cl
  UFG::allocator::free_link *v61; // rax
  UFG::HitRecord *v62; // rax
  UFG::HitRecord *v63; // r14
  UFG::HitRecord *v64; // rax
  float v65; // xmm0_4
  UFG::qBaseTreeRB *Next; // rbx
  float v67; // xmm0_4
  UFG::SimComponentHolder *p; // rcx
  UFG::SimComponent *v69; // rbx
  float v70; // xmm2_4
  float v71; // xmm0_4
  UFG::WorldEffectsManager *v72; // rax
  UFG::qReflectHandleBase v73; // [rsp+30h] [rbp-A8h] BYREF
  UFG::HitRecord hitrecord; // [rsp+58h] [rbp-80h] BYREF
  UFG::HitRecord __that; // [rsp+188h] [rbp+B0h] BYREF
  hkTransformf transform; // [rsp+2B8h] [rbp+1E0h] BYREF
  UFG::allocator::free_link *v77; // [rsp+368h] [rbp+290h]

  hitrecord.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)-2i64;
  *(_QWORD *)&this->mActiveSurfaceUID = 0i64;
  *(_QWORD *)this->mActiveVolumeUID = 0i64;
  *(_QWORD *)&this->mActiveVolumeUID[2] = 0i64;
  this->mActiveVolumeUID[4] = 0;
  m_pSimComponent = (UFG::PhantomVolumeComponent *)this->mPhantomVolumeComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    for ( i = 0; i < 5u; ++i )
    {
      Properties = UFG::PhantomVolumeComponent::GetProperties(m_pSimComponent, i);
      v7 = (UFG::qBaseNodeRB *)Properties;
      if ( !Properties )
        break;
      this->mActiveVolumeUID[i] = Properties->mBaseNode.mUID;
      mUID = Properties->mBaseNode.mUID;
      if ( !(_DWORD)mUID || !UFG::qBaseTreeRB::Get(&this->mPhysVolumeRefs.mTree, mUID) )
      {
        v9 = UFG::qMalloc(0x40ui64, "PhysVolumeRef", 0i64);
        v10 = (UFG::qBaseNodeRB *)v9;
        v77 = v9;
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
        UFG::qBaseTreeRB::Add(&this->mPhysVolumeRefs.mTree, v10);
      }
    }
  }
  v11 = this->mCharacterPhysicsComponent.m_pSimComponent;
  if ( v11 )
  {
    mPrev = (unsigned __int64)v11[6].m_SafePointerList.mNode.mPrev;
    mNext = (unsigned __int64)v11[6].m_SafePointerList.mNode.mNext;
    UFG::qReflectHandleBase::qReflectHandleBase(&v73);
    if ( mNext )
    {
      TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v14);
      v73.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v73, v73.mTypeUID, mNext);
      mData = v73.mData;
      if ( !v73.mData )
      {
        UFG::PhysicsPropertyManager::GetDefaultSurfaceProperties((UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *)&v73);
        mData = v73.mData;
      }
      v17 = HIDWORD(mData[1].mBaseNode.mChildren[0]);
    }
    else
    {
      v18 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName((UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *)v14);
      v73.mTypeUID = UFG::qStringHash64(v18, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v73, v73.mTypeUID, mPrev);
      v19 = v73.mData;
      if ( !v73.mData )
      {
        UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v73);
        v19 = v73.mData;
      }
      v17 = *(_DWORD *)(v19[4].mBaseNode.mUID + 108);
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v73);
    this->mActiveSurfaceUID = v17;
    if ( !v17 || !UFG::qBaseTreeRB::Get(&this->mPhysVolumeRefs.mTree, v17) )
    {
      v20 = UFG::PhysicsVolumePropertyManager::Find(v17, 0);
      if ( v20 )
      {
        v21 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
        v22 = (UFG::qBaseNodeRB *)v21;
        v77 = v21;
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
        UFG::qBaseTreeRB::Add(&this->mPhysVolumeRefs.mTree, v22);
      }
    }
  }
  if ( this->mIsAttachedToPlayer
    && UFG::TimeOfDayManager::GetInstance()->m_WeatherState > 1.0
    && !UFG::TidoGame::IsInside() )
  {
    this->mActiveWetSurfaceUID = 0xF18CE285;
    if ( !UFG::qBaseTreeRB::Get(&this->mPhysVolumeRefs.mTree, 0xF18CE285) )
    {
      v23 = UFG::PhysicsVolumePropertyManager::Find(this->mActiveWetSurfaceUID, 0);
      if ( v23 )
      {
        v24 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
        v25 = (UFG::qBaseNodeRB *)v24;
        v77 = v24;
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
        UFG::qBaseTreeRB::Add(&this->mPhysVolumeRefs.mTree, v25);
      }
    }
  }
  Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mPhysVolumeRefs);
  while ( Head )
  {
    v27 = Head->mRoot.mUID;
    if ( v27 == this->mActiveVolumeUID[0]
      || v27 == this->mActiveVolumeUID[1]
      || v27 == this->mActiveVolumeUID[2]
      || v27 == this->mActiveVolumeUID[3]
      || v27 == this->mActiveVolumeUID[4]
      || v27 == this->mActiveSurfaceUID
      || (v28 = v27 == this->mActiveWetSurfaceUID, v29 = 0, v28) )
    {
      v29 = 1;
    }
    LOBYTE(Head->mNULL.mParent) = v29;
    v30 = (float *)Head->mNULL.mChild[1];
    if ( v30[29] <= 0.0 || (v31 = 1, !this->InvulnerableToFire) )
      v31 = 0;
    BYTE1(Head->mNULL.mParent) = v31;
    if ( v31 )
    {
      p_mRoot = &Head->mRoot;
      p_mPhysVolumeRefs = &this->mPhysVolumeRefs;
      if ( v29 )
        goto LABEL_118;
    }
    else
    {
      if ( v29 )
      {
        *((float *)&Head->mNULL.mParent + 1) = delta_sec + *((float *)&Head->mNULL.mParent + 1);
        LODWORD(Head->mNULL.mChild[0]) = 0;
        v34 = v30[28];
        if ( v34 <= 0.0 )
          goto LABEL_82;
        m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
        if ( !m_pSimObject )
          goto LABEL_82;
        m_pComponent = (UFG::HealthComponent *)m_pSimObject->m_Components.p[6].m_pComponent;
        if ( !m_pComponent )
          goto LABEL_82;
        v37 = this->mIsAttachedToPlayer ? FLOAT_100_0 : (float)(int)m_pComponent->m_fMaxHealth;
        v38 = (float)((float)(v34 * v37) * delta_sec) + this->mQueuedHealthDamage;
        this->mQueuedHealthDamage = v38;
        if ( v38 <= 5.0 )
          goto LABEL_82;
        v39 = *((float *)&Head->mNULL.mChild[1][3].mChild[1] + 1) > 0.0;
        if ( !v39
          || (v40 = (UFG::HitReactionComponent *)m_pSimObject->m_Components.p[15].m_pComponent) == 0i64
          || UFG::PhysicsVolumePropertyManager::FireHitRecordType == -1 )
        {
          UFG::HealthComponent::ApplyHealthDamage(m_pComponent, 5, m_pSimObject, 0i64, 0);
          goto LABEL_76;
        }
        UFG::HitRecord::HitRecord(&__that);
        mAttackTypeID = UFG::PhysicsVolumePropertyManager::FireHitRecordType;
        __that.mAttackTypeID = UFG::PhysicsVolumePropertyManager::FireHitRecordType;
        __that.mDamage = 5;
        if ( __that.mAttacker.m_pPointer )
        {
          v42 = __that.mAttacker.mPrev;
          v43 = __that.mAttacker.mNext;
          __that.mAttacker.mPrev->mNext = __that.mAttacker.mNext;
          v43->mPrev = v42;
          __that.mAttacker.mPrev = &__that.mAttacker;
          __that.mAttacker.mNext = &__that.mAttacker;
          mAttackTypeID = __that.mAttackTypeID;
        }
        v44 = 0i64;
        __that.mAttacker.m_pPointer = 0i64;
        *(_QWORD *)&__that.mTimeSinceHit = 0i64;
        if ( !v40->mHitRecord.mHitRecordProcessed )
        {
          v45 = mAttackTypeID == gAttackCollisionProjectile.m_EnumValue
             && v40->mHitRecord.mAttackTypeID == gAttackCollisionProjectile.m_EnumValue;
          v46 = mAttackTypeID > v40->mHitRecord.mAttackTypeID;
          if ( v45 )
          {
            ++v40->mNumHits;
            v47 = UFG::qMalloc(0x128ui64, UFG::gGlobalNewName, 0i64);
            v77 = v47;
            if ( v47 )
            {
              UFG::HitRecord::HitRecord((UFG::HitRecord *)v47);
              v44 = v48;
            }
            UFG::HitRecord::operator=(v44, &__that);
            v49 = v40->mHitRecord.mNext;
            v40->mHitRecord.mNext = v44;
            v44->mNext = v49;
LABEL_74:
            UFG::HitRecord::~HitRecord(&__that);
LABEL_76:
            this->mQueuedHealthDamage = this->mQueuedHealthDamage - 5.0;
            if ( v39 && (int)m_pComponent->m_fHealth < 1 )
            {
              if ( this->mIsAttachedToPlayer )
                v50 = UFG::CharacterEffectsComponent::sTimeFireIsActivePlayer;
              else
                v50 = UFG::CharacterEffectsComponent::sTimeFireIsActive;
              this->mFireExtinguishTime = v50;
              UFG::CharacterEffectsComponent::IgniteFire(this);
            }
LABEL_82:
            if ( *((float *)&Head->mNULL.mChild[1][3].mChild[1] + 1) > 0.0 )
            {
              if ( (_S68 & 1) != 0 )
              {
                v51 = physVol_OnFire;
              }
              else
              {
                _S68 |= 1u;
                v51 = UFG::qStringHashUpper32("PhysVol_OnFire", -1);
                physVol_OnFire = v51;
              }
              mIsOnFire = this->mIsOnFire;
              if ( !mIsOnFire || Head->mNULL.mChild[1]->mChild[0] != (UFG::qBaseNodeRB *)v51 )
              {
                if ( this->mIsAttachedToPlayer )
                  v53 = UFG::CharacterEffectsComponent::sTimeFireIsActivePlayer;
                else
                  v53 = UFG::CharacterEffectsComponent::sTimeFireIsActive;
                this->mFireExtinguishTime = v53;
              }
              this->mSmolderExtinguishTime = UFG::CharacterEffectsComponent::sTimeSmolderIsActive;
              if ( !this->mIsSmoldering && !mIsOnFire )
                UFG::CharacterEffectsComponent::IgniteSmolder(this);
            }
            if ( Head->mNULL.mChild[1][3].mUID == -1 )
              goto LABEL_117;
            if ( LOBYTE(Head->mNULL.mUID) )
              goto LABEL_117;
            v54 = this->m_pSimObject;
            if ( !v54 )
              goto LABEL_117;
            v55 = (UFG::HitReactionComponent *)v54->m_Components.p[15].m_pComponent;
            if ( !v55 )
              goto LABEL_117;
            UFG::HitRecord::HitRecord(&hitrecord);
            v56 = Head->mNULL.mChild[1][3].mUID;
            hitrecord.mAttackTypeID = v56;
            hitrecord.mDamage = 0;
            if ( hitrecord.mAttacker.m_pPointer )
            {
              v57 = hitrecord.mAttacker.mPrev;
              v58 = hitrecord.mAttacker.mNext;
              hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
              v58->mPrev = v57;
              hitrecord.mAttacker.mPrev = &hitrecord.mAttacker;
              hitrecord.mAttacker.mNext = &hitrecord.mAttacker;
              v56 = hitrecord.mAttackTypeID;
            }
            hitrecord.mAttacker.m_pPointer = 0i64;
            *(_QWORD *)&hitrecord.mTimeSinceHit = 0i64;
            if ( !v55->mHitRecord.mHitRecordProcessed )
            {
              v59 = v56 == gAttackCollisionProjectile.m_EnumValue
                 && v55->mHitRecord.mAttackTypeID == gAttackCollisionProjectile.m_EnumValue;
              v60 = v56 > v55->mHitRecord.mAttackTypeID;
              if ( v59 )
              {
                ++v55->mNumHits;
                v61 = UFG::qMalloc(0x128ui64, UFG::gGlobalNewName, 0i64);
                v77 = v61;
                if ( v61 )
                {
                  UFG::HitRecord::HitRecord((UFG::HitRecord *)v61);
                  v63 = v62;
                }
                else
                {
                  v63 = 0i64;
                }
                UFG::HitRecord::operator=(v63, &hitrecord);
                v64 = v55->mHitRecord.mNext;
                v55->mHitRecord.mNext = v63;
                v63->mNext = v64;
LABEL_113:
                LOBYTE(Head->mNULL.mUID) = 1;
                UFG::HitRecord::~HitRecord(&hitrecord);
LABEL_117:
                p_mRoot = &Head->mRoot;
                p_mPhysVolumeRefs = &this->mPhysVolumeRefs;
LABEL_118:
                Head = UFG::qBaseTreeRB::GetNext(&p_mPhysVolumeRefs->mTree, p_mRoot);
                continue;
              }
              if ( !v60 )
                goto LABEL_113;
            }
            UFG::HitReactionComponent::SetHitRecord(v55, &hitrecord);
            goto LABEL_113;
          }
          if ( !v46 )
            goto LABEL_74;
        }
        UFG::HitReactionComponent::SetHitRecord(v40, &__that);
        goto LABEL_74;
      }
      v65 = delta_sec + *(float *)Head->mNULL.mChild;
      *(float *)Head->mNULL.mChild = v65;
      if ( v65 <= v30[27] )
        goto LABEL_117;
      p_mRoot = &Head->mRoot;
      p_mPhysVolumeRefs = &this->mPhysVolumeRefs;
    }
    Next = UFG::qBaseTreeRB::GetNext(&p_mPhysVolumeRefs->mTree, p_mRoot);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mPhysVolumeRefs,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)Head);
    operator delete[](Head);
    Head = Next;
  }
  if ( this->mIsOnFire )
  {
    v67 = this->mFireExtinguishTime - delta_sec;
    this->mFireExtinguishTime = v67;
    if ( v67 < 0.0 || this->InvulnerableToFire )
      UFG::CharacterEffectsComponent::ExtinguishFire(this);
    if ( this->mPhantomRigidBody )
    {
      p = this->m_pSimObject->m_Components.p;
      v69 = p[2].m_pComponent;
      if ( v69 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)p[2].m_pComponent);
        v73 = *(UFG::qReflectHandleBase *)&v69[2].vfptr;
        *(_DWORD *)&hitrecord.mHitRecordProcessed = v69[2].m_pSimObject;
        hitrecord.mAttackTypeID = HIDWORD(v69[2].m_pSimObject);
        hitrecord.mDamage = (int)v69[2].m_BoundComponentHandles.mNode.mPrev;
        *(&hitrecord.mDamage + 1) = HIDWORD(v69[2].m_BoundComponentHandles.mNode.mPrev);
        v70 = *(float *)&v69[2].m_BoundComponentHandles.mNode.mNext;
        HIDWORD(hitrecord.mAttacker.mPrev) = HIDWORD(v69[2].m_BoundComponentHandles.mNode.mNext);
        *(float *)&hitrecord.mAttacker.mPrev = v70 + 1.0;
        hkTransformf::set4x4ColumnMajor(&transform, (const float *)&v73);
        hkpRigidBody::setTransform(this->mPhantomRigidBody, &transform);
      }
    }
  }
  if ( this->mIsSmoldering )
  {
    v71 = this->mSmolderExtinguishTime - delta_sec;
    this->mSmolderExtinguishTime = v71;
    if ( v71 < 0.0 || this->InvulnerableToFire )
      UFG::CharacterEffectsComponent::ExtinguishSmolder(this);
  }
  v72 = UFG::WorldEffectsManager::Get();
  UFG::WorldEffectsManager::UpdateUIEffects(v72, this);
}

// File Line: 673
// RVA: 0x535140
void __fastcall UFG::CharacterEffectsComponent::HandleWaterCollision(
        UFG::CharacterEffectsComponent *this,
        UFG::qMatrix44 *mat,
        UFG::qVector3 *characterVelocity)
{
  UFG::SimComponent *m_pSimComponent; // rdi
  int v4; // esi
  Creature *v7; // rdi
  UFG::qWiseSymbol *v8; // rax
  int BoneID; // eax
  UFG::SimComponent *v10; // rdi
  Creature *v11; // rdi
  UFG::qWiseSymbol *v12; // rax
  UFG::TransformNodeComponent *v13; // rcx
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-88h] BYREF
  UFG::qMatrix44 m; // [rsp+60h] [rbp-48h] BYREF
  UFG::qWiseSymbol result; // [rsp+B0h] [rbp+8h] BYREF

  m_pSimComponent = this->mCharacterAnimationComponent.m_pSimComponent;
  v4 = -1;
  if ( m_pSimComponent )
  {
    v7 = *(Creature **)&m_pSimComponent[2].m_TypeUID;
    if ( v7 )
    {
      v8 = UFG::qSymbol::qSymbol(&result, 0x8C4CF328);
      if ( v7->mPose.mRigHandle.mData )
        BoneID = Skeleton::GetBoneID(v7->mPose.mRigHandle.mUFGSkeleton, v8->mUID);
      else
        BoneID = -1;
      Creature::GetTransform(v7, BoneID, &transform);
    }
  }
  v10 = this->mCharacterAnimationComponent.m_pSimComponent;
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
  v13 = this->mNodes[0];
  transform.v3.z = mat->v3.z;
  m.v3.z = transform.v3.z;
  UFG::TransformNodeComponent::SetLocalTransform(v13, &transform);
  UFG::TransformNodeComponent::SetLocalTransform(this->mNodes[1], &m);
  if ( this->mIsOnFire )
    UFG::CharacterEffectsComponent::ExtinguishFire(this);
  if ( this->mIsSmoldering )
    UFG::CharacterEffectsComponent::ExtinguishSmolder(this);
}

// File Line: 723
// RVA: 0x524970
void __fastcall UFG::CharacterEffectsComponent::CreateNodes(UFG::CharacterEffectsComponent *this)
{
  UFG::TransformNodeComponent **mNodes; // rbx
  __int64 v2; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax

  mNodes = this->mNodes;
  v2 = 2i64;
  do
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v4 = UFG::qMemoryPool::Allocate(
           SimulationMemoryPool,
           0x110ui64,
           "CharacterEffectsComponent::TransformNodeComponet",
           0i64,
           1u);
    if ( v4 )
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v4, 0xDEADBEEF, 0i64, 0);
    *mNodes++ = (UFG::TransformNodeComponent *)v4;
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
void __fastcall UFG::CharacterEffectsComponent::SetFootstepOverride(
        UFG::CharacterEffectsComponent *this,
        unsigned int leftFootEffectID,
        unsigned int rightFootEffectID)
{
  this->mFootstepOverride[0] = leftFootEffectID;
  this->mFootstepOverride[1] = rightFootEffectID;
}

// File Line: 785
// RVA: 0x535AD0
void __fastcall UFG::CharacterEffectsComponent::IgniteFire(UFG::CharacterEffectsComponent *this)
{
  bool v2; // zf
  UFG::SimObject *m_pSimObject; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  __int64 v6; // rdx
  Render::FXSimComponent *v7; // rdi
  hkpRigidBody *mPhantomRigidBody; // rcx
  UFG::SimComponentHolder *p; // rcx
  float *m_pComponent; // rdi
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
  UFG::CharacterAnimationComponent *m_pSimComponent; // rcx
  UFG::qVector3 halfExtents; // [rsp+30h] [rbp-58h] BYREF
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-48h] BYREF

  if ( !this->mIsOnFire )
  {
    v2 = !this->mIsSmoldering;
    this->mIsOnFire = 1;
    if ( !v2 )
      UFG::CharacterEffectsComponent::ExtinguishSmolder(this);
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        v6 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
             || (Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v6 += 16i64;
          if ( vfptr >= size )
            goto LABEL_13;
        }
        v7 = *(Render::FXSimComponent **)v6;
        if ( *(_QWORD *)v6 )
        {
          this->mFireEffectID[0] = Render::FXSimComponent::AttachEffect(v7, 0xA6B7A27D, 1, 0i64);
          this->mFireEffectID[1] = Render::FXSimComponent::AttachEffect(v7, 0x6811A3DBu, 13, 0i64);
          this->mFireEffectID[2] = Render::FXSimComponent::AttachEffect(v7, 0x6811A3DBu, 14, 0i64);
        }
      }
    }
LABEL_13:
    mPhantomRigidBody = this->mPhantomRigidBody;
    if ( mPhantomRigidBody )
    {
      UFG::PhantomCallback::DestroyPhantom(mPhantomRigidBody);
      this->mPhantomRigidBody = 0i64;
    }
    p = this->m_pSimObject->m_Components.p;
    m_pComponent = (float *)p[2].m_pComponent;
    if ( m_pComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)p[2].m_pComponent);
      v11 = m_pComponent[32];
      v12 = m_pComponent[33];
      v13 = m_pComponent[46];
      halfExtents.x = 0.5;
      halfExtents.y = 0.5;
      halfExtents.z = 1.0;
      transform.v0.x = v11;
      transform.v0.z = m_pComponent[34];
      v14 = m_pComponent[36];
      transform.v0.y = v12;
      v15 = m_pComponent[35];
      transform.v1.x = v14;
      v16 = m_pComponent[38];
      transform.v0.w = v15;
      v17 = m_pComponent[37];
      transform.v1.z = v16;
      v18 = m_pComponent[40];
      transform.v1.y = v17;
      v19 = m_pComponent[39];
      transform.v2.x = v18;
      v20 = m_pComponent[42];
      transform.v1.w = v19;
      v21 = m_pComponent[41];
      transform.v2.z = v20;
      v22 = m_pComponent[44];
      transform.v2.y = v21;
      v23 = m_pComponent[43];
      transform.v3.x = v22;
      v24 = m_pComponent[47];
      transform.v2.w = v23;
      v25 = m_pComponent[45];
      transform.v3.w = v24;
      transform.v3.y = v25;
      transform.v3.z = v13 + 1.0;
      v26 = UFG::qStringHashUpper32("PhysVol_OnFire", -1);
      this->mPhantomRigidBody = (hkpRigidBody *)UFG::PhantomCallback::CreatePhantom(&halfExtents, &transform, v26);
    }
    m_pSimComponent = (UFG::CharacterAnimationComponent *)this->mCharacterAnimationComponent.m_pSimComponent;
    if ( m_pSimComponent )
      UFG::CharacterAnimationComponent::ApplyCharredEffect(m_pSimComponent, 1.0);
  }
}

// File Line: 840
// RVA: 0x527A20
void __fastcall UFG::CharacterEffectsComponent::ExtinguishFire(UFG::CharacterEffectsComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v5; // rdx
  Render::FXSimComponent *v6; // rdi
  hkpRigidBody *mPhantomRigidBody; // rcx

  if ( this->mIsOnFire )
  {
    m_pSimObject = this->m_pSimObject;
    this->mIsOnFire = 0;
    if ( m_pSimObject )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        v5 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v5 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
             || (Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v5 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v5 += 16i64;
          if ( vfptr >= size )
            goto LABEL_11;
        }
        v6 = *(Render::FXSimComponent **)v5;
        if ( *(_QWORD *)v5 )
        {
          Render::FXSimComponent::DetachEffect(v6, this->mFireEffectID[0], FXKILLOPTION_DEFAULT);
          Render::FXSimComponent::DetachEffect(v6, this->mFireEffectID[1], FXKILLOPTION_DEFAULT);
          Render::FXSimComponent::DetachEffect(v6, this->mFireEffectID[2], FXKILLOPTION_DEFAULT);
        }
      }
    }
LABEL_11:
    mPhantomRigidBody = this->mPhantomRigidBody;
    if ( mPhantomRigidBody )
    {
      UFG::PhantomCallback::DestroyPhantom(mPhantomRigidBody);
      this->mPhantomRigidBody = 0i64;
    }
  }
}

// File Line: 872
// RVA: 0x535D70
void __fastcall UFG::CharacterEffectsComponent::IgniteSmolder(UFG::CharacterEffectsComponent *this)
{
  UFG::SimObject *m_pSimObject; // rbx
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v6; // rdx
  Render::FXSimComponent *ComponentOfType; // rdi
  unsigned int v8; // r8d
  unsigned int v9; // r9d
  unsigned int v10; // r8d
  unsigned int v11; // r9d
  unsigned int v12; // r8d
  unsigned int v13; // r9d
  __int16 v14; // cx
  UFG::ActorAudioComponent *m_pComponent; // rcx
  unsigned int v16; // r8d
  unsigned int v17; // r9d
  __int64 v18; // rdx
  unsigned int v19; // r8d
  unsigned int v20; // r9d
  unsigned int v21; // r8d
  unsigned int v22; // r9d

  if ( !this->mIsSmoldering )
  {
    m_pSimObject = this->m_pSimObject;
    this->mIsSmoldering = 1;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr < size )
        {
          v6 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
               || (Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v6 += 16i64;
            if ( vfptr >= size )
              goto LABEL_9;
          }
LABEL_10:
          ComponentOfType = *(Render::FXSimComponent **)v6;
          goto LABEL_33;
        }
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          v10 = (unsigned int)m_pSimObject[1].vfptr;
          v11 = m_pSimObject->m_Components.size;
          if ( v10 < v11 )
          {
            v6 = (__int64)&m_pSimObject->m_Components.p[v10];
            while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
                 || (Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v10;
              v6 += 16i64;
              if ( v10 >= v11 )
              {
                ComponentOfType = 0i64;
                goto LABEL_33;
              }
            }
            goto LABEL_10;
          }
        }
        else
        {
          if ( (m_Flags & 0x1000) == 0 )
          {
            ComponentOfType = (Render::FXSimComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pSimObject,
                                                          Render::FXSimComponent::_TypeUID);
LABEL_33:
            if ( ComponentOfType )
            {
              this->mSmolderEffectID[0] = Render::FXSimComponent::AttachEffect(ComponentOfType, 0x88AA83Au, 1, 0i64);
              this->mSmolderEffectID[1] = Render::FXSimComponent::AttachEffect(ComponentOfType, 0xCF8F3EA9, 13, 0i64);
              this->mSmolderEffectID[2] = Render::FXSimComponent::AttachEffect(ComponentOfType, 0xCF8F3EA9, 14, 0i64);
            }
            v14 = m_pSimObject->m_Flags;
            if ( (v14 & 0x4000) != 0 )
            {
              m_pComponent = (UFG::ActorAudioComponent *)m_pSimObject->m_Components.p[40].m_pComponent;
              if ( m_pComponent
                && ((UFG::ActorAudioComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) == 0
                && (UFG::ActorAudioComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) == 0 )
              {
                goto LABEL_63;
              }
              goto LABEL_39;
            }
            if ( v14 >= 0 )
            {
              if ( (v14 & 0x2000) != 0 )
              {
                v19 = (unsigned int)m_pSimObject[1].vfptr;
                v20 = m_pSimObject->m_Components.size;
                if ( v19 < v20 )
                {
                  v18 = (__int64)&m_pSimObject->m_Components.p[v19];
                  while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
                       || (UFG::ActorAudioComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
                  {
                    ++v19;
                    v18 += 16i64;
                    if ( v19 >= v20 )
                    {
                      m_pComponent = 0i64;
                      goto LABEL_63;
                    }
                  }
                  goto LABEL_47;
                }
              }
              else
              {
                if ( (v14 & 0x1000) == 0 )
                {
                  m_pComponent = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                               m_pSimObject,
                                                               UFG::ActorAudioComponent::_TypeUID);
LABEL_63:
                  if ( m_pComponent )
                    UFG::ActorAudioComponent::PlayScreamPain(m_pComponent);
                  return;
                }
                v21 = (unsigned int)m_pSimObject[1].vfptr;
                v22 = m_pSimObject->m_Components.size;
                if ( v21 < v22 )
                {
                  v18 = (__int64)&m_pSimObject->m_Components.p[v21];
                  while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
                       || (UFG::ActorAudioComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
                  {
                    ++v21;
                    v18 += 16i64;
                    if ( v21 >= v22 )
                    {
                      m_pComponent = 0i64;
                      goto LABEL_63;
                    }
                  }
                  goto LABEL_47;
                }
              }
            }
            else
            {
              v16 = (unsigned int)m_pSimObject[1].vfptr;
              v17 = m_pSimObject->m_Components.size;
              if ( v16 < v17 )
              {
                v18 = (__int64)&m_pSimObject->m_Components.p[v16];
                while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
                     || (UFG::ActorAudioComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v16;
                  v18 += 16i64;
                  if ( v16 >= v17 )
                  {
                    m_pComponent = 0i64;
                    goto LABEL_63;
                  }
                }
LABEL_47:
                m_pComponent = *(UFG::ActorAudioComponent **)v18;
                goto LABEL_63;
              }
            }
LABEL_39:
            m_pComponent = 0i64;
            goto LABEL_63;
          }
          v12 = (unsigned int)m_pSimObject[1].vfptr;
          v13 = m_pSimObject->m_Components.size;
          if ( v12 < v13 )
          {
            v6 = (__int64)&m_pSimObject->m_Components.p[v12];
            while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
                 || (Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v12;
              v6 += 16i64;
              if ( v12 >= v13 )
              {
                ComponentOfType = 0i64;
                goto LABEL_33;
              }
            }
            goto LABEL_10;
          }
        }
      }
      else
      {
        v8 = (unsigned int)m_pSimObject[1].vfptr;
        v9 = m_pSimObject->m_Components.size;
        if ( v8 < v9 )
        {
          v6 = (__int64)&m_pSimObject->m_Components.p[v8];
          while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
               || (Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v8;
            v6 += 16i64;
            if ( v8 >= v9 )
            {
              ComponentOfType = 0i64;
              goto LABEL_33;
            }
          }
          goto LABEL_10;
        }
      }
LABEL_9:
      ComponentOfType = 0i64;
      goto LABEL_33;
    }
  }
}      {
              Com

// File Line: 897
// RVA: 0x527B20
void __fastcall UFG::CharacterEffectsComponent::ExtinguishSmolder(UFG::CharacterEffectsComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 i; // rdx
  Render::FXSimComponent *v6; // rdi

  if ( this->mIsSmoldering )
  {
    m_pSimObject = this->m_pSimObject;
    this->mIsSmoldering = 0;
    if ( m_pSimObject )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        for ( i = (__int64)&m_pSimObject->m_Components.p[vfptr];
              (*(_DWORD *)(i + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
           || (Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(i + 8) & 0x1FFFFFF) != 0;
              i += 16i64 )
        {
          if ( ++vfptr >= size )
            return;
        }
        v6 = *(Render::FXSimComponent **)i;
        if ( *(_QWORD *)i )
        {
          Render::FXSimComponent::DetachEffect(v6, this->mSmolderEffectID[0], FXKILLOPTION_DEFAULT);
          Render::FXSimComponent::DetachEffect(v6, this->mSmolderEffectID[1], FXKILLOPTION_DEFAULT);
          Render::FXSimComponent::DetachEffect(v6, this->mSmolderEffectID[2], FXKILLOPTION_DEFAULT);
        }
      }
    }
  }
}

