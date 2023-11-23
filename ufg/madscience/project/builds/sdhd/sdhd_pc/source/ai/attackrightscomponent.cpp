// File Line: 79
// RVA: 0x14AEAA0
__int64 dynamic_initializer_for__UFG::AttackRightsComponent::s_AttackRightsComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AttackRightsComponent::s_AttackRightsComponentList__);
}

// File Line: 80
// RVA: 0x363470
__int64 __fastcall UFG::AttackRightsComponent::GetTypeSize(UFG::AttackRightsComponent *this)
{
  return 10368i64;
}

// File Line: 91
// RVA: 0x32C900
void __fastcall UFG::AttackRightsComponent::AttackRightsComponent(
        UFG::AttackRightsComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties)
{
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *mPrev; // rax
  int v6; // eax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent>;
  this->mNext = &this->UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AttackRightsComponent::`vftable;
  `eh vector constructor iterator(
    this->m_pAttackSlot,
    0x18ui64,
    384,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  `eh vector constructor iterator(
    this->m_pCachedNextAttacker,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  `eh vector constructor iterator(
    this->m_pPreviousBestAttacker,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  `eh vector constructor iterator(
    this->m_AttackSlotQueue,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  `eh vector constructor iterator(
    this->m_FollowerAttackSlotQueue,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0>::RebindingComponentHandle<UFG::FormationManagerComponent,0>(&this->m_pFormationManagerComponent);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::RebindingComponentHandle<UFG::AIEntityComponent,0>(&this->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>(&this->m_pCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&this->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::RebindingComponentHandle<UFG::HitReactionComponent,0>(&this->m_pHitReactionComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&this->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>(&this->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&this->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>(&this->m_pCharacterOccupantComponent);
  this->m_pNextAttacker.mPrev = &this->m_pNextAttacker;
  this->m_pNextAttacker.mNext = &this->m_pNextAttacker;
  this->m_pNextAttacker.m_pPointer = 0i64;
  `eh vector constructor iterator(
    this->m_pLastAttackRequest,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  UFG::qString::qString(&this->m_DebugText);
  mPrev = UFG::AttackRightsComponent::s_AttackRightsComponentList.mNode.mPrev;
  UFG::AttackRightsComponent::s_AttackRightsComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *)&UFG::AttackRightsComponent::s_AttackRightsComponentList;
  UFG::AttackRightsComponent::s_AttackRightsComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent>;
  UFG::SimComponent::AddType(this, UFG::AttackRightsComponent::_AttackRightsComponentTypeUID, "AttackRightsComponent");
  *(_QWORD *)this->m_NumAttackSlots = 0x4000000040i64;
  this->m_NumAttackSlots[2] = 64;
  this->m_MinTimeBetweenAttackerSwitch = -1.0;
  this->m_MaxTimeBetweenAttackerSwitch = -1.0;
  UFG::AttackRightsComponent::ClearAttackSlots(this);
  this->m_DebugDrawEnabled = 0;
  v6 = initted_0;
  if ( !initted_0 )
    v6 = 1;
  initted_0 = v6;
  UFG::AttackRightsComponent::InitFromProperties(this, properties);
}

// File Line: 127
// RVA: 0x335370
void __fastcall UFG::AttackRightsComponent::~AttackRightsComponent(UFG::AttackRightsComponent *this)
{
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *v2; // rdi
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *mPrev; // rcx
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *mNext; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *p_m_pNextAttacker; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *v10; // rcx
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AttackRightsComponent::`vftable;
  if ( this == UFG::AttackRightsComponent::s_AttackRightsComponentpCurrentIterator )
    UFG::AttackRightsComponent::s_AttackRightsComponentpCurrentIterator = (UFG::AttackRightsComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qString::~qString(&this->m_DebugText);
  `eh vector destructor iterator(
    this->m_pLastAttackRequest,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  p_m_pNextAttacker = &this->m_pNextAttacker;
  if ( this->m_pNextAttacker.m_pPointer )
  {
    v6 = p_m_pNextAttacker->mPrev;
    v7 = this->m_pNextAttacker.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pNextAttacker->mPrev = p_m_pNextAttacker;
    this->m_pNextAttacker.mNext = &this->m_pNextAttacker;
  }
  this->m_pNextAttacker.m_pPointer = 0i64;
  v8 = p_m_pNextAttacker->mPrev;
  v9 = this->m_pNextAttacker.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_m_pNextAttacker->mPrev = p_m_pNextAttacker;
  this->m_pNextAttacker.mNext = &this->m_pNextAttacker;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pCharacterOccupantComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pHitReactionComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pFormationManagerComponent);
  `eh vector destructor iterator(
    this->m_FollowerAttackSlotQueue,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qList<UFG::SoundBank,UFG::SoundBankGroupBankList,0,0>::~qList<UFG::SoundBank,UFG::SoundBankGroupBankList,0,0>);
  `eh vector destructor iterator(
    this->m_AttackSlotQueue,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>);
  `eh vector destructor iterator(
    this->m_pPreviousBestAttacker,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  `eh vector destructor iterator(
    this->m_pCachedNextAttacker,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  `eh vector destructor iterator(
    this->m_pAttackSlot,
    0x18ui64,
    384,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 144
// RVA: 0x364DA0
bool __fastcall UFG::AttackRightsComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentAttackRights,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 150
// RVA: 0x37E560
UFG::SimComponent *__fastcall UFG::AttackRightsComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x2880ui64, "AttackRightsComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::AttackRightsComponent::AttackRightsComponent(
      (UFG::AttackRightsComponent *)v3,
      pSceneObj->m_NameUID,
      mpWritableProperties);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v8 = 46;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v6, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v6;
}

// File Line: 157
// RVA: 0x366D40
void __fastcall UFG::AttackRightsComponent::InitFromProperties(
        UFG::AttackRightsComponent *this,
        UFG::qPropertySet *property_set)
{
  UFG::qArray<unsigned long,0> *v4; // rsi
  UFG::qString *v5; // rax
  UFG::qString *v6; // rax
  UFG::qString *v7; // rax
  int *v8; // rbx
  __int64 v9; // rbp
  int *v10; // rax
  int v11; // edx
  int v12; // ecx
  int v13; // ecx
  unsigned int v14; // eax
  float *v15; // rax
  float v16; // xmm8_4
  float *v17; // rax
  float v18; // xmm7_4
  float *v19; // rax
  float v20; // xmm6_4
  float *v21; // rax
  float v22; // xmm0_4
  unsigned int v23; // eax
  float *v24; // rax
  float v25; // xmm6_4
  float *v26; // rax
  float v27; // xmm0_4
  float *v28; // rax
  float *v29; // rax
  float *v30; // rax
  float *v31; // rax
  float *v32; // rax
  int v33; // [rsp+28h] [rbp-80h] BYREF
  int v34; // [rsp+2Ch] [rbp-7Ch]
  int v35; // [rsp+30h] [rbp-78h]
  UFG::qString result; // [rsp+38h] [rbp-70h] BYREF

  v4 = (UFG::qArray<unsigned long,0> *)attack_slot_names;
  if ( (_S11_2 & 1) == 0 )
  {
    _S11_2 |= 1u;
    v5 = UFG::qString::FormatEx(&result, "NumAttackSlots%s", UFG::AttackTypeNames[0]);
    UFG::qSymbol::create_from_string(attack_slot_names, v5->mData);
    UFG::qString::~qString(&result);
    v6 = UFG::qString::FormatEx(&result, "NumAttackSlots%s", off_14206C120[0]);
    UFG::qSymbol::create_from_string(&::result, v6->mData);
    UFG::qString::~qString(&result);
    v7 = UFG::qString::FormatEx(&result, "NumAttackSlots%s", off_14206C128[0]);
    UFG::qSymbol::create_from_string(&stru_1423C1AA0, v7->mData);
    UFG::qString::~qString(&result);
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_2_::_dynamic_atexit_destructor_for__attack_slot_names__);
  }
  v8 = &v33;
  v9 = 3i64;
  do
  {
    v10 = UFG::qPropertySet::Get<long>(property_set, v4, DEPTH_RECURSE);
    if ( v10 )
      *v8 = *v10;
    else
      *v8 = 0;
    v4 = (UFG::qArray<unsigned long,0> *)((char *)v4 + 4);
    ++v8;
    --v9;
  }
  while ( v9 );
  v11 = 64;
  v12 = 64;
  if ( v33 < 64 )
    v12 = v33;
  this->m_NumAttackSlots[0] = v12;
  v13 = 64;
  if ( v34 < 64 )
    v13 = v34;
  this->m_NumAttackSlots[1] = v13;
  if ( v35 < 64 )
    v11 = v35;
  this->m_NumAttackSlots[2] = v11;
  v14 = _S11_2;
  if ( (_S11_2 & 2) == 0 )
  {
    _S11_2 |= 2u;
    UFG::qSymbol::create_from_string(&min_distance_symbol, "MinDistanceToBeConsideredInCombat");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_11_::_dynamic_atexit_destructor_for__min_distance_symbol__);
    v14 = _S11_2;
  }
  if ( (v14 & 4) == 0 )
  {
    _S11_2 = v14 | 4;
    UFG::qSymbol::create_from_string(&max_distance_symbol, "MaxDistanceToBeConsideredInCombat");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_11_::_dynamic_atexit_destructor_for__max_distance_symbol__);
    v14 = _S11_2;
  }
  if ( (v14 & 8) == 0 )
  {
    _S11_2 = v14 | 8;
    UFG::qSymbol::create_from_string(&min_angle_symbol, "MinAngleToBeConsideredInCombat");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_11_::_dynamic_atexit_destructor_for__min_angle_symbol__);
    v14 = _S11_2;
  }
  if ( (v14 & 0x10) == 0 )
  {
    _S11_2 = v14 | 0x10;
    UFG::qSymbol::create_from_string(&max_angle_symbol, "MaxAngleToBeConsideredInCombat");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_11_::_dynamic_atexit_destructor_for__max_angle_symbol__);
  }
  v15 = UFG::qPropertySet::Get<float>(property_set, (UFG::qArray<unsigned long,0> *)&min_distance_symbol, DEPTH_RECURSE);
  if ( v15 )
  {
    v16 = *v15;
    v17 = UFG::qPropertySet::Get<float>(
            property_set,
            (UFG::qArray<unsigned long,0> *)&max_distance_symbol,
            DEPTH_RECURSE);
    if ( v17 )
    {
      v18 = *v17;
      v19 = UFG::qPropertySet::Get<float>(
              property_set,
              (UFG::qArray<unsigned long,0> *)&min_angle_symbol,
              DEPTH_RECURSE);
      if ( v19 )
      {
        v20 = *v19;
        v21 = UFG::qPropertySet::Get<float>(
                property_set,
                (UFG::qArray<unsigned long,0> *)&max_angle_symbol,
                DEPTH_RECURSE);
        if ( v21 )
        {
          v22 = *v21;
          this->m_InCombatParams.m_CloseDistance = v16;
          this->m_InCombatParams.m_FarDistance = v18;
          this->m_InCombatParams.m_NarrowAngle = v20;
          this->m_InCombatParams.m_WideAngle = v22;
        }
      }
    }
  }
  v23 = _S11_2;
  if ( (_S11_2 & 0x20) == 0 )
  {
    _S11_2 |= 0x20u;
    UFG::qSymbol::create_from_string(&min_time_symbol, "MinTimeBetweenAttackerSwitch");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_14_::_dynamic_atexit_destructor_for__min_time_symbol__);
    v23 = _S11_2;
  }
  if ( (v23 & 0x40) == 0 )
  {
    _S11_2 = v23 | 0x40;
    UFG::qSymbol::create_from_string(&max_time_symbol, "MaxTimeBetweenAttackerSwitch");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_14_::_dynamic_atexit_destructor_for__max_time_symbol__);
  }
  v24 = UFG::qPropertySet::Get<float>(property_set, (UFG::qArray<unsigned long,0> *)&min_time_symbol, DEPTH_RECURSE);
  if ( v24 )
  {
    v25 = *v24;
    v26 = UFG::qPropertySet::Get<float>(property_set, (UFG::qArray<unsigned long,0> *)&max_time_symbol, DEPTH_RECURSE);
    if ( v26 )
    {
      v27 = *v26;
      this->m_MinTimeBetweenAttackerSwitch = v25;
      this->m_MaxTimeBetweenAttackerSwitch = v27;
    }
  }
  v28 = UFG::qPropertySet::Get<float>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_OnScreenTestFOVReduction,
          DEPTH_RECURSE);
  if ( v28 )
    UFG::AttackRightsComponent::s_OnScreenTestFOVReduction = (float)(*v28 * 3.1415927) * 0.0055555557;
  v29 = UFG::qPropertySet::Get<float>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_OnScreenTestFootSphereRadius,
          DEPTH_RECURSE);
  if ( v29 )
    UFG::AttackRightsComponent::s_OnScreenTestFootSphereRadius = *v29;
  v30 = UFG::qPropertySet::Get<float>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_OnScreenTestHeadSphereRadius,
          DEPTH_RECURSE);
  if ( v30 )
    UFG::AttackRightsComponent::s_OnScreenTestHeadSphereRadius = *v30;
  v31 = UFG::qPropertySet::Get<float>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_OnScreenTestHeadHeight,
          DEPTH_RECURSE);
  if ( v31 )
    UFG::AttackRightsComponent::s_OnScreenTestHeadHeight = *v31;
  v32 = UFG::qPropertySet::Get<float>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_DefaultTimeUntilNextAttack,
          DEPTH_RECURSE);
  if ( v32 )
    UFG::AttackRightsComponent::s_DefaultTimeUntilNextAttack = *v32;
  UFG::AttackRightsComponent::ClearAttackSlots(this);
}

// File Line: 268
// RVA: 0x378900
void __fastcall UFG::AttackRightsComponent::OnAttach(UFG::AttackRightsComponent *this, UFG::SimObjectCharacter *object)
{
  UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0> *p_m_pFormationManagerComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *p_m_pSimObjectCharacterPropertiesComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax

  p_m_pFormationManagerComponent = &this->m_pFormationManagerComponent;
  if ( p_m_pFormationManagerComponent->m_pSimComponent )
  {
    mPrev = p_m_pFormationManagerComponent->mPrev;
    mNext = p_m_pFormationManagerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pFormationManagerComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_m_pFormationManagerComponent->m_pSimObject = 0i64;
    p_m_pFormationManagerComponent->mNext = p_m_pFormationManagerComponent;
    p_m_pFormationManagerComponent->mPrev = p_m_pFormationManagerComponent;
    goto LABEL_8;
  }
  if ( p_m_pFormationManagerComponent->m_pSimObject
    && (p_m_pFormationManagerComponent->mPrev != p_m_pFormationManagerComponent
     || p_m_pFormationManagerComponent->mNext != p_m_pFormationManagerComponent) )
  {
    v7 = p_m_pFormationManagerComponent->mPrev;
    v8 = p_m_pFormationManagerComponent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pFormationManagerComponent->m_Changed = 1;
  p_m_pFormationManagerComponent->m_pSimObject = object;
  p_m_pFormationManagerComponent->m_TypeUID = UFG::FormationManagerComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    p_m_pFormationManagerComponent,
    object);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pTransformNodeComponent,
    object);
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pAIEntityComponent,
    object);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pActionTreeComponent,
    object);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pCharacterPhysicsComponent,
    object);
  p_m_pSimObjectCharacterPropertiesComponent = &this->m_pSimObjectCharacterPropertiesComponent;
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v10 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v11 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    this->m_pSimObjectCharacterPropertiesComponent.mNext = &this->m_pSimObjectCharacterPropertiesComponent;
    p_m_pSimObjectCharacterPropertiesComponent->mPrev = p_m_pSimObjectCharacterPropertiesComponent;
    goto LABEL_15;
  }
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && (p_m_pSimObjectCharacterPropertiesComponent->mPrev != p_m_pSimObjectCharacterPropertiesComponent
     || this->m_pSimObjectCharacterPropertiesComponent.mNext != &this->m_pSimObjectCharacterPropertiesComponent) )
  {
    v12 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v13 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = object;
  this->m_pSimObjectCharacterPropertiesComponent.m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &this->m_pSimObjectCharacterPropertiesComponent,
    object);
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pHitReactionComponent,
    object);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pHealthComponent,
    object);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pAIScriptInterfaceComponent,
    object);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pTargetingSystemBaseComponent,
    object);
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pCharacterOccupantComponent,
    object);
}

// File Line: 292
// RVA: 0x37A110
void __fastcall UFG::AttackRightsComponent::OnDetach(UFG::AttackRightsComponent *this)
{
  UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0> *p_m_pFormationManagerComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *p_m_pCharacterPhysicsComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *p_m_pSimObjectCharacterPropertiesComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *p_m_pHitReactionComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *p_m_pHealthComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rax
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *p_m_pAIScriptInterfaceComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v43; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v44; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v45; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v46; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v48; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v49; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v50; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v51; // rax
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *p_m_pCharacterOccupantComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v53; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v54; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v55; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v56; // rax

  UFG::AttackRightsComponent::ClearAttackSlots(this);
  p_m_pFormationManagerComponent = &this->m_pFormationManagerComponent;
  if ( this->m_pFormationManagerComponent.m_pSimComponent )
  {
    mPrev = p_m_pFormationManagerComponent->mPrev;
    mNext = this->m_pFormationManagerComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pFormationManagerComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->m_pFormationManagerComponent.m_pSimObject = 0i64;
    this->m_pFormationManagerComponent.mNext = &this->m_pFormationManagerComponent;
    p_m_pFormationManagerComponent->mPrev = p_m_pFormationManagerComponent;
    goto LABEL_8;
  }
  if ( this->m_pFormationManagerComponent.m_pSimObject
    && (p_m_pFormationManagerComponent->mPrev != p_m_pFormationManagerComponent
     || this->m_pFormationManagerComponent.mNext != &this->m_pFormationManagerComponent) )
  {
    v5 = p_m_pFormationManagerComponent->mPrev;
    v6 = this->m_pFormationManagerComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  this->m_pFormationManagerComponent.m_Changed = 1;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v8 = p_m_pTransformNodeComponent->mPrev;
    v9 = this->m_pTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pTransformNodeComponent.m_pSimObject = 0i64;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    goto LABEL_15;
  }
  if ( this->m_pTransformNodeComponent.m_pSimObject
    && (p_m_pTransformNodeComponent->mPrev != p_m_pTransformNodeComponent
     || this->m_pTransformNodeComponent.mNext != &this->m_pTransformNodeComponent) )
  {
    v10 = p_m_pTransformNodeComponent->mPrev;
    v11 = this->m_pTransformNodeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pTransformNodeComponent.m_Changed = 1;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    v13 = p_m_pAIEntityComponent->mPrev;
    v14 = this->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pAIEntityComponent.m_pSimObject = 0i64;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    goto LABEL_22;
  }
  if ( this->m_pAIEntityComponent.m_pSimObject
    && (p_m_pAIEntityComponent->mPrev != p_m_pAIEntityComponent
     || this->m_pAIEntityComponent.mNext != &this->m_pAIEntityComponent) )
  {
    v15 = p_m_pAIEntityComponent->mPrev;
    v16 = this->m_pAIEntityComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pAIEntityComponent.m_Changed = 1;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v18 = p_m_pActionTreeComponent->mPrev;
    v19 = this->m_pActionTreeComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pActionTreeComponent.m_pSimObject = 0i64;
    this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    goto LABEL_29;
  }
  if ( this->m_pActionTreeComponent.m_pSimObject
    && (p_m_pActionTreeComponent->mPrev != p_m_pActionTreeComponent
     || this->m_pActionTreeComponent.mNext != &this->m_pActionTreeComponent) )
  {
    v20 = p_m_pActionTreeComponent->mPrev;
    v21 = this->m_pActionTreeComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pActionTreeComponent.m_Changed = 1;
  p_m_pCharacterPhysicsComponent = &this->m_pCharacterPhysicsComponent;
  if ( this->m_pCharacterPhysicsComponent.m_pSimComponent )
  {
    v23 = p_m_pCharacterPhysicsComponent->mPrev;
    v24 = this->m_pCharacterPhysicsComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    this->m_pCharacterPhysicsComponent.m_pSimComponent = 0i64;
LABEL_35:
    this->m_pCharacterPhysicsComponent.m_pSimObject = 0i64;
    this->m_pCharacterPhysicsComponent.mNext = &this->m_pCharacterPhysicsComponent;
    p_m_pCharacterPhysicsComponent->mPrev = p_m_pCharacterPhysicsComponent;
    goto LABEL_36;
  }
  if ( this->m_pCharacterPhysicsComponent.m_pSimObject
    && (p_m_pCharacterPhysicsComponent->mPrev != p_m_pCharacterPhysicsComponent
     || this->m_pCharacterPhysicsComponent.mNext != &this->m_pCharacterPhysicsComponent) )
  {
    v25 = p_m_pCharacterPhysicsComponent->mPrev;
    v26 = this->m_pCharacterPhysicsComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  this->m_pCharacterPhysicsComponent.m_Changed = 1;
  p_m_pSimObjectCharacterPropertiesComponent = &this->m_pSimObjectCharacterPropertiesComponent;
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v28 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v29 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_42:
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    this->m_pSimObjectCharacterPropertiesComponent.mNext = &this->m_pSimObjectCharacterPropertiesComponent;
    p_m_pSimObjectCharacterPropertiesComponent->mPrev = p_m_pSimObjectCharacterPropertiesComponent;
    goto LABEL_43;
  }
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && (p_m_pSimObjectCharacterPropertiesComponent->mPrev != p_m_pSimObjectCharacterPropertiesComponent
     || this->m_pSimObjectCharacterPropertiesComponent.mNext != &this->m_pSimObjectCharacterPropertiesComponent) )
  {
    v30 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v31 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  this->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  p_m_pHitReactionComponent = &this->m_pHitReactionComponent;
  if ( this->m_pHitReactionComponent.m_pSimComponent )
  {
    v33 = p_m_pHitReactionComponent->mPrev;
    v34 = this->m_pHitReactionComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    this->m_pHitReactionComponent.m_pSimComponent = 0i64;
LABEL_49:
    this->m_pHitReactionComponent.m_pSimObject = 0i64;
    this->m_pHitReactionComponent.mNext = &this->m_pHitReactionComponent;
    p_m_pHitReactionComponent->mPrev = p_m_pHitReactionComponent;
    goto LABEL_50;
  }
  if ( this->m_pHitReactionComponent.m_pSimObject
    && (p_m_pHitReactionComponent->mPrev != p_m_pHitReactionComponent
     || this->m_pHitReactionComponent.mNext != &this->m_pHitReactionComponent) )
  {
    v35 = p_m_pHitReactionComponent->mPrev;
    v36 = this->m_pHitReactionComponent.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    goto LABEL_49;
  }
LABEL_50:
  this->m_pHitReactionComponent.m_Changed = 1;
  p_m_pHealthComponent = &this->m_pHealthComponent;
  if ( this->m_pHealthComponent.m_pSimComponent )
  {
    v38 = p_m_pHealthComponent->mPrev;
    v39 = this->m_pHealthComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    this->m_pHealthComponent.m_pSimComponent = 0i64;
LABEL_56:
    this->m_pHealthComponent.m_pSimObject = 0i64;
    this->m_pHealthComponent.mNext = &this->m_pHealthComponent;
    p_m_pHealthComponent->mPrev = p_m_pHealthComponent;
    goto LABEL_57;
  }
  if ( this->m_pHealthComponent.m_pSimObject
    && (p_m_pHealthComponent->mPrev != p_m_pHealthComponent
     || this->m_pHealthComponent.mNext != &this->m_pHealthComponent) )
  {
    v40 = p_m_pHealthComponent->mPrev;
    v41 = this->m_pHealthComponent.mNext;
    v40->mNext = v41;
    v41->mPrev = v40;
    goto LABEL_56;
  }
LABEL_57:
  this->m_pHealthComponent.m_Changed = 1;
  p_m_pAIScriptInterfaceComponent = &this->m_pAIScriptInterfaceComponent;
  if ( this->m_pAIScriptInterfaceComponent.m_pSimComponent )
  {
    v43 = p_m_pAIScriptInterfaceComponent->mPrev;
    v44 = this->m_pAIScriptInterfaceComponent.mNext;
    v43->mNext = v44;
    v44->mPrev = v43;
    this->m_pAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_63:
    this->m_pAIScriptInterfaceComponent.m_pSimObject = 0i64;
    this->m_pAIScriptInterfaceComponent.mNext = &this->m_pAIScriptInterfaceComponent;
    p_m_pAIScriptInterfaceComponent->mPrev = p_m_pAIScriptInterfaceComponent;
    goto LABEL_64;
  }
  if ( this->m_pAIScriptInterfaceComponent.m_pSimObject
    && (p_m_pAIScriptInterfaceComponent->mPrev != p_m_pAIScriptInterfaceComponent
     || this->m_pAIScriptInterfaceComponent.mNext != &this->m_pAIScriptInterfaceComponent) )
  {
    v45 = p_m_pAIScriptInterfaceComponent->mPrev;
    v46 = this->m_pAIScriptInterfaceComponent.mNext;
    v45->mNext = v46;
    v46->mPrev = v45;
    goto LABEL_63;
  }
LABEL_64:
  this->m_pAIScriptInterfaceComponent.m_Changed = 1;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v48 = p_m_pTargetingSystemBaseComponent->mPrev;
    v49 = this->m_pTargetingSystemBaseComponent.mNext;
    v48->mNext = v49;
    v49->mPrev = v48;
    this->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_70:
    this->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    goto LABEL_71;
  }
  if ( this->m_pTargetingSystemBaseComponent.m_pSimObject
    && (p_m_pTargetingSystemBaseComponent->mPrev != p_m_pTargetingSystemBaseComponent
     || this->m_pTargetingSystemBaseComponent.mNext != &this->m_pTargetingSystemBaseComponent) )
  {
    v50 = p_m_pTargetingSystemBaseComponent->mPrev;
    v51 = this->m_pTargetingSystemBaseComponent.mNext;
    v50->mNext = v51;
    v51->mPrev = v50;
    goto LABEL_70;
  }
LABEL_71:
  this->m_pTargetingSystemBaseComponent.m_Changed = 1;
  p_m_pCharacterOccupantComponent = &this->m_pCharacterOccupantComponent;
  if ( this->m_pCharacterOccupantComponent.m_pSimComponent )
  {
    v53 = p_m_pCharacterOccupantComponent->mPrev;
    v54 = this->m_pCharacterOccupantComponent.mNext;
    v53->mNext = v54;
    v54->mPrev = v53;
    this->m_pCharacterOccupantComponent.m_pSimComponent = 0i64;
LABEL_77:
    this->m_pCharacterOccupantComponent.m_pSimObject = 0i64;
    this->m_pCharacterOccupantComponent.mNext = &this->m_pCharacterOccupantComponent;
    p_m_pCharacterOccupantComponent->mPrev = p_m_pCharacterOccupantComponent;
    goto LABEL_78;
  }
  if ( this->m_pCharacterOccupantComponent.m_pSimObject
    && (p_m_pCharacterOccupantComponent->mPrev != p_m_pCharacterOccupantComponent
     || this->m_pCharacterOccupantComponent.mNext != &this->m_pCharacterOccupantComponent) )
  {
    v55 = p_m_pCharacterOccupantComponent->mPrev;
    v56 = this->m_pCharacterOccupantComponent.mNext;
    v55->mNext = v56;
    v56->mPrev = v55;
    goto LABEL_77;
  }
LABEL_78:
  this->m_pCharacterOccupantComponent.m_Changed = 1;
}

// File Line: 309
// RVA: 0x382980
// attributes: thunk
void __fastcall UFG::AttackRightsComponent::Reset(UFG::AttackRightsComponent *this)
{
  UFG::AttackRightsComponent::ClearAttackSlots(this);
}

// File Line: 314
// RVA: 0x34EF10
void __fastcall UFG::AttackRightsComponent::ClearAttackSlots(UFG::AttackRightsComponent *this)
{
  bool *m_CurrentlyAttacking; // r14
  float *m_NextTimeToUpdateAllowedToUseAttackSlotList; // rdi
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> (*m_pAttackSlot)[2][64]; // r8
  int (*m_NextAttackBaton)[2]; // rbx
  bool (*m_OverrideAllowedToUseAttackSlotListThisFrame)[2]; // r9
  UFG::HasAttackRequestNode **p_m_pPointer; // r11
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> **p_mNext; // rsi
  __int64 v9; // r15
  __int64 v10; // r10
  __int64 v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *i; // rdx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v15; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v16; // rcx
  __int64 v17; // rcx
  _QWORD *v18; // rax
  UFG::HasAttackRequestNode *v19; // rcx
  UFG::HasAttackRequestNode *v20; // rax
  UFG::HasAttackRequestNode *v21; // rax
  UFG::HasAttackRequestNode *v22; // rcx

  m_CurrentlyAttacking = this->m_CurrentlyAttacking;
  m_NextTimeToUpdateAllowedToUseAttackSlotList = this->m_NextTimeToUpdateAllowedToUseAttackSlotList;
  m_pAttackSlot = this->m_pAttackSlot;
  m_NextAttackBaton = this->m_NextAttackBaton;
  m_OverrideAllowedToUseAttackSlotListThisFrame = this->m_OverrideAllowedToUseAttackSlotListThisFrame;
  p_m_pPointer = &this->m_pCachedNextAttacker[0].m_pPointer;
  p_mNext = &this->m_AttackSlotQueue[0].mNode.mNext;
  v9 = 3i64;
  do
  {
    v10 = 2i64;
    do
    {
      v11 = 64i64;
      do
      {
        if ( (*m_pAttackSlot)[0][0].m_pPointer )
        {
          mPrev = (*m_pAttackSlot)[0][0].mPrev;
          mNext = (*m_pAttackSlot)[0][0].mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          (*m_pAttackSlot)[0][0].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)m_pAttackSlot;
          (*m_pAttackSlot)[0][0].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)m_pAttackSlot;
        }
        (*m_pAttackSlot)[0][0].m_pPointer = 0i64;
        m_pAttackSlot = (UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> (*)[2][64])((char *)m_pAttackSlot + 24);
        --v11;
      }
      while ( v11 );
      *(_DWORD *)m_NextAttackBaton = 0;
      (*m_OverrideAllowedToUseAttackSlotListThisFrame)[-6] = 1;
      *(_BYTE *)m_OverrideAllowedToUseAttackSlotListThisFrame = 0;
      m_OverrideAllowedToUseAttackSlotListThisFrame = (bool (*)[2])((char *)m_OverrideAllowedToUseAttackSlotListThisFrame
                                                                  + 1);
      m_NextAttackBaton = (int (*)[2])((char *)m_NextAttackBaton + 4);
      --v10;
    }
    while ( v10 );
    for ( i = *p_mNext; &(*p_mNext)[-3].mNext != p_mNext - 6; i = *p_mNext )
    {
      v15 = i->mNext;
      v16 = i->mPrev;
      v16->mNext = v15;
      v15->mPrev = v16;
      i->mPrev = i;
      i->mNext = i;
    }
    m_NextTimeToUpdateAllowedToUseAttackSlotList[49] = 0.0;
    *(m_CurrentlyAttacking - 64) = 1;
    *m_CurrentlyAttacking = 0;
    *m_NextTimeToUpdateAllowedToUseAttackSlotList = -99999.0;
    m_NextTimeToUpdateAllowedToUseAttackSlotList[65] = -99999.0;
    m_NextTimeToUpdateAllowedToUseAttackSlotList[61] = -99999.0;
    if ( *p_m_pPointer )
    {
      v17 = (__int64)*(p_m_pPointer - 2);
      v18 = *(p_m_pPointer - 1);
      *(_QWORD *)(v17 + 8) = v18;
      *v18 = v17;
      *(p_m_pPointer - 2) = (UFG::HasAttackRequestNode *)(p_m_pPointer - 2);
      *(p_m_pPointer - 1) = (UFG::HasAttackRequestNode *)(p_m_pPointer - 2);
    }
    *p_m_pPointer = 0i64;
    if ( p_m_pPointer[9] )
    {
      v19 = p_m_pPointer[7];
      v20 = p_m_pPointer[8];
      v19->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v20;
      v20->vfptr = (UFG::qSafePointerNode<UFG::HasAttackRequestNode>Vtbl *)v19;
      p_m_pPointer[7] = (UFG::HasAttackRequestNode *)(p_m_pPointer + 7);
      p_m_pPointer[8] = (UFG::HasAttackRequestNode *)(p_m_pPointer + 7);
    }
    p_m_pPointer[9] = 0i64;
    m_NextTimeToUpdateAllowedToUseAttackSlotList[46] = -99999.0;
    if ( p_m_pPointer[111] )
    {
      v21 = p_m_pPointer[110];
      v22 = p_m_pPointer[109];
      v22->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v21;
      v21->vfptr = (UFG::qSafePointerNode<UFG::HasAttackRequestNode>Vtbl *)v22;
      p_m_pPointer[109] = (UFG::HasAttackRequestNode *)(p_m_pPointer + 109);
      p_m_pPointer[110] = (UFG::HasAttackRequestNode *)(p_m_pPointer + 109);
    }
    p_m_pPointer[111] = 0i64;
    p_m_pPointer += 3;
    ++m_NextTimeToUpdateAllowedToUseAttackSlotList;
    p_mNext += 2;
    ++m_CurrentlyAttacking;
    --v9;
  }
  while ( v9 );
  this->m_InCombatWithSomeone = 0;
  this->m_IsDowned = 0;
  this->m_NextTimeCanPerformRunningAttack = -99999.0;
  this->m_RunningAttacksEnabled = 1;
}

// File Line: 351
// RVA: 0x34CD90
void __fastcall UFG::AttackRightsComponent::CheckIfDownedStateChanged(UFG::AttackRightsComponent *this)
{
  UFG::ActionTreeComponent *m_pSimComponent; // rcx
  bool IsDowned; // al
  __int64 v4; // r8
  float *m_TimeUntilNextAttack; // rdi
  int i; // esi
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *NextAttacker; // rax
  float TimeUntilNextAttack; // xmm0_4

  m_pSimComponent = (UFG::ActionTreeComponent *)this->m_pActionTreeComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    IsDowned = UFG::IsDowned(m_pSimComponent, (UFG::HealthComponent *)this->m_pHealthComponent.m_pSimComponent);
    if ( this->m_IsDowned != IsDowned )
    {
      this->m_IsDowned = IsDowned;
      if ( IsDowned )
      {
        *(_QWORD *)this->m_TimeUntilNextAttack = 0x497423F0497423F0i64;
        this->m_TimeUntilNextAttack[2] = 999999.0;
        return;
      }
      m_TimeUntilNextAttack = this->m_TimeUntilNextAttack;
      for ( i = 0; i < 3; ++i )
      {
        NextAttacker = UFG::AttackRightsComponent::GetNextAttacker(this, (UFG::eAttackType)i, v4);
        if ( NextAttacker )
        {
          TimeUntilNextAttack = UFG::AttackRightsComponent::GetTimeUntilNextAttack(
                                  this,
                                  (UFG::HasAttackRequestNode *)NextAttacker,
                                  (UFG::HasAttackRequestNode *)NextAttacker);
          if ( !this->m_IsDowned )
            goto LABEL_11;
        }
        else if ( !this->m_IsDowned )
        {
          TimeUntilNextAttack = UFG::AttackRightsComponent::s_DefaultTimeUntilNextAttack;
LABEL_11:
          *m_TimeUntilNextAttack = TimeUntilNextAttack;
        }
        ++m_TimeUntilNextAttack;
      }
    }
  }
}

// File Line: 441
// RVA: 0x36D220
void __fastcall UFG::AttackRightsComponent::JustPerformedOpportunityAttack(
        UFG::AttackRightsComponent *this,
        UFG::eAttackType attack_type,
        float min_time_until_next_one,
        float max_time_until_next_one)
{
  __int64 v4; // rbx
  float v6; // xmm0_4
  float mSimTime_Temp; // xmm8_4

  v4 = attack_type;
  v6 = max_time_until_next_one;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( max_time_until_next_one > min_time_until_next_one )
  {
    v6 = UFG::qRandom(max_time_until_next_one - min_time_until_next_one, (unsigned int *)&UFG::qDefaultSeed)
       + min_time_until_next_one;
    if ( v6 <= min_time_until_next_one )
      v6 = min_time_until_next_one;
    if ( v6 >= max_time_until_next_one )
      v6 = max_time_until_next_one;
  }
  this->m_NextTimeCanPerformOpportunityAttack[v4] = v6 + mSimTime_Temp;
}

// File Line: 473
// RVA: 0x382280
void __fastcall UFG::AttackRightsComponent::RequestAttackSlot(
        UFG::AttackRightsComponent *this,
        UFG::HasAttackRequestNode *attacker)
{
  __int64 m_AttackType; // r11
  __int64 v5; // r10
  __int64 v6; // r9
  __int64 v7; // rdx
  UFG::HasAttackRequestNode **v8; // rax
  __int64 v9; // r11
  int v10; // ecx
  bool *v11; // rdx
  UFG::HasAttackRequestNode *p_mNext; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *mPrev; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *mNext; // rax
  UFG::qList<UFG::HasAttackRequestNode,UFG::AttackRightsList,0,0> *v15; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v16; // rax

  if ( attacker )
  {
    m_AttackType = attacker->m_AttackType;
    v5 = 0i64;
    v6 = this->m_NumAttackSlots[m_AttackType];
    while ( 1 )
    {
      v7 = 0i64;
      if ( v6 > 0 )
        break;
LABEL_7:
      if ( ++v5 >= 2 )
      {
        v9 = m_AttackType;
        v10 = -1;
        v11 = &this->m_RunningAttacksEnabled + v9 * 16;
        p_mNext = (UFG::HasAttackRequestNode *)&this->m_AttackSlotQueue[v9].mNode.mNext[-3].mNext;
        if ( p_mNext == (UFG::HasAttackRequestNode *)v11 )
        {
LABEL_11:
          v10 = -1;
        }
        else
        {
          while ( 1 )
          {
            ++v10;
            if ( p_mNext == attacker )
              break;
            p_mNext = (UFG::HasAttackRequestNode *)&p_mNext->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext[-3].mNext;
            if ( p_mNext == (UFG::HasAttackRequestNode *)v11 )
              goto LABEL_11;
          }
        }
        if ( v10 == -1 )
        {
          mPrev = attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mPrev;
          mNext = attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mPrev = &attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>;
          attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext = &attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>;
          v15 = &this->m_AttackSlotQueue[attacker->m_AttackType];
          v16 = v15->mNode.mPrev;
          v16->mNext = &attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>;
          attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mPrev = v16;
          attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext = &v15->mNode;
          v15->mNode.mPrev = &attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>;
        }
        return;
      }
    }
    v8 = &this->m_pAttackSlot[0][0][0].m_pPointer + 384 * m_AttackType + 192 * v5;
    while ( attacker != *v8 )
    {
      ++v7;
      v8 += 3;
      if ( v7 >= v6 )
        goto LABEL_7;
    }
  }
}

// File Line: 500
// RVA: 0x3414C0
void __fastcall UFG::AttackRightsComponent::AddToFollowerAttackSlotQueue(
        UFG::AttackRightsComponent *this,
        UFG::HasAttackRequestNode *attacker)
{
  int v4; // r9d
  bool *v5; // r8
  UFG::HasAttackRequestNode *p_mNext; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *mPrev; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *mNext; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v9; // rdx
  UFG::qList<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList,0,0> *v10; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v11; // rax

  if ( attacker )
  {
    v4 = -1;
    v5 = &this->m_CurrentlyAttacking[16 * attacker->m_AttackType];
    p_mNext = (UFG::HasAttackRequestNode *)&this->m_FollowerAttackSlotQueue[attacker->m_AttackType].mNode.mNext[-4].mNext;
    if ( p_mNext == (UFG::HasAttackRequestNode *)v5 )
    {
LABEL_5:
      v4 = -1;
    }
    else
    {
      while ( 1 )
      {
        ++v4;
        if ( p_mNext == attacker )
          break;
        p_mNext = (UFG::HasAttackRequestNode *)&p_mNext->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mNext[-4].mNext;
        if ( p_mNext == (UFG::HasAttackRequestNode *)v5 )
          goto LABEL_5;
      }
    }
    if ( v4 == -1 )
    {
      mPrev = attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mPrev;
      mNext = attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mNext;
      v9 = &attacker->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v9->mPrev = v9;
      v9->mNext = v9;
      v10 = &this->m_FollowerAttackSlotQueue[attacker->m_AttackType];
      v11 = v10->mNode.mPrev;
      v11->mNext = v9;
      v9->mPrev = v11;
      v9->mNext = &v10->mNode;
      v10->mNode.mPrev = v9;
    }
  }
}

// File Line: 558
// RVA: 0x359BC0
char __fastcall UFG::AttackRightsComponent::GetAttackSlotInfo(
        UFG::AttackRightsComponent *this,
        UFG::HasAttackRequestNode *attacker,
        UFG::AttackSlotInfo *attack_slot_info)
{
  __int64 m_AttackType; // rsi
  UFG::eAttackSlotList v6; // ebx
  __int64 v7; // r11
  __int64 v8; // r9
  int v9; // r8d
  __int64 v10; // rdx
  UFG::HasAttackRequestNode **v11; // rax

  if ( !attacker )
    return 0;
  m_AttackType = attacker->m_AttackType;
  v6 = eATTACK_SLOT_LIST_ON_SCREEN;
  v7 = 0i64;
  v8 = this->m_NumAttackSlots[m_AttackType];
  while ( 1 )
  {
    v9 = 0;
    v10 = 0i64;
    if ( v8 > 0 )
      break;
LABEL_7:
    ++v7;
    ++v6;
    if ( v7 >= 2 )
      return 0;
  }
  v11 = &this->m_pAttackSlot[0][0][0].m_pPointer + 384 * m_AttackType + 192 * v7;
  while ( attacker != *v11 )
  {
    ++v10;
    ++v9;
    v11 += 3;
    if ( v10 >= v8 )
      goto LABEL_7;
  }
  attack_slot_info->m_AttackSlotList = v6;
  attack_slot_info->m_AttackSlot = v9;
  return 1;
}

// File Line: 610
// RVA: 0x38AE10
void __fastcall UFG::AttackRightsComponent::UnregisterUnavailableAttackers(UFG::AttackRightsComponent *this)
{
  __int64 v2; // r13
  int *m_NumAttackSlots; // rsi
  UFG::HasAttackRequestNode **p_m_pPointer; // r15
  bool *m_CurrentlyAttacking; // r12
  __int64 i; // rbp
  int v7; // edi
  UFG::HasAttackRequestNode **v8; // rbx
  __int64 v9; // rcx
  _QWORD *v10; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> **v11; // rdi
  UFG::HasAttackRequestNode *v12; // rbx
  __int64 v13; // rdi
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *mPrev; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *mNext; // rax
  __int64 v16; // rcx
  _QWORD *v17; // rax
  bool v18; // zf
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> **p_mNext; // [rsp+68h] [rbp+10h]
  __int64 v20; // [rsp+70h] [rbp+18h]

  v2 = 0i64;
  m_NumAttackSlots = this->m_NumAttackSlots;
  p_m_pPointer = &this->m_pCachedNextAttacker[0].m_pPointer;
  m_CurrentlyAttacking = this->m_CurrentlyAttacking;
  p_mNext = &this->m_FollowerAttackSlotQueue[0].mNode.mNext;
  v20 = 3i64;
  do
  {
    for ( i = 0i64; i < 2; ++i )
    {
      v7 = 0;
      if ( *m_NumAttackSlots > 0 )
      {
        v8 = &this->m_pAttackSlot[0][0][0].m_pPointer + 192 * i + 192 * v2;
        do
        {
          if ( *v8 && !UFG::AttackRightsComponent::AttackerIsAvailable(this, *v8) )
          {
            if ( *v8 )
            {
              v9 = (__int64)*(v8 - 2);
              v10 = *(v8 - 1);
              *(_QWORD *)(v9 + 8) = v10;
              *v10 = v9;
              *(v8 - 2) = (UFG::HasAttackRequestNode *)(v8 - 2);
              *(v8 - 1) = (UFG::HasAttackRequestNode *)(v8 - 2);
            }
            *v8 = 0i64;
          }
          ++v7;
          v8 += 3;
        }
        while ( v7 < *m_NumAttackSlots );
      }
    }
    v11 = p_mNext;
    v12 = (UFG::HasAttackRequestNode *)&(*p_mNext)[-4].mNext;
    if ( v12 != (UFG::HasAttackRequestNode *)m_CurrentlyAttacking )
    {
      do
      {
        v13 = (__int64)&v12->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mNext[-4].mNext;
        if ( !UFG::AttackRightsComponent::AttackerIsAvailable(this, v12) )
        {
          mPrev = v12->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mPrev;
          mNext = v12->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          v12->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mPrev = &v12->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>;
          v12->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mNext = &v12->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>;
        }
        v12 = (UFG::HasAttackRequestNode *)v13;
      }
      while ( (bool *)v13 != m_CurrentlyAttacking );
      v11 = p_mNext;
    }
    if ( *p_m_pPointer && !UFG::AttackRightsComponent::AttackerIsAvailable(this, *p_m_pPointer) )
    {
      if ( *p_m_pPointer )
      {
        v16 = (__int64)*(p_m_pPointer - 2);
        v17 = *(p_m_pPointer - 1);
        *(_QWORD *)(v16 + 8) = v17;
        *v17 = v16;
        *(p_m_pPointer - 2) = (UFG::HasAttackRequestNode *)(p_m_pPointer - 2);
        *(p_m_pPointer - 1) = (UFG::HasAttackRequestNode *)(p_m_pPointer - 2);
      }
      *p_m_pPointer = 0i64;
    }
    m_CurrentlyAttacking += 16;
    ++m_NumAttackSlots;
    v2 += 2i64;
    p_m_pPointer += 3;
    v18 = v20-- == 1;
    p_mNext = v11 + 2;
  }
  while ( !v18 );
}

// File Line: 675
// RVA: 0x34CE60
void __fastcall UFG::AttackRightsComponent::CheckIfInCombat(UFG::AttackRightsComponent *this)
{
  float v2; // xmm9_4
  float v3; // xmm0_4
  bool m_InCombatWithSomeone; // al
  float m_FarDistance; // xmm8_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  __int64 v8; // r12
  int *m_NumAttackSlots; // rsi
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> **p_mNext; // r13
  bool *p_m_RunningAttacksEnabled; // r15
  UFG::HasAttackRequestNode *i; // rbx
  __int64 j; // rbp
  int v14; // edi
  UFG::HasAttackRequestNode **v15; // rbx
  UFG::HasAttackRequestNode *v16; // rdx
  __int64 v17; // [rsp+20h] [rbp-98h]
  float distance_away; // [rsp+C0h] [rbp+8h] BYREF
  float cosine_of_angle_away; // [rsp+C8h] [rbp+10h] BYREF
  float v20; // [rsp+D0h] [rbp+18h] BYREF
  float v21; // [rsp+D8h] [rbp+20h] BYREF

  v2 = cosf((float)(this->m_InCombatParams.m_NarrowAngle * 3.1415927) * 0.0055555557);
  v3 = cosf((float)(this->m_InCombatParams.m_WideAngle * 3.1415927) * 0.0055555557);
  m_InCombatWithSomeone = this->m_InCombatWithSomeone;
  if ( m_InCombatWithSomeone )
    m_FarDistance = this->m_InCombatParams.m_FarDistance;
  else
    m_FarDistance = this->m_InCombatParams.m_CloseDistance;
  if ( m_InCombatWithSomeone )
    v2 = v3;
  v6 = FLOAT_99999_0;
  v7 = 0.0;
  v8 = 0i64;
  m_NumAttackSlots = this->m_NumAttackSlots;
  p_mNext = &this->m_AttackSlotQueue[0].mNode.mNext;
  p_m_RunningAttacksEnabled = &this->m_RunningAttacksEnabled;
  v17 = 3i64;
  do
  {
    for ( i = (UFG::HasAttackRequestNode *)&(*p_mNext)[-3].mNext;
          i != (UFG::HasAttackRequestNode *)p_m_RunningAttacksEnabled;
          i = (UFG::HasAttackRequestNode *)&i->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext[-3].mNext )
    {
      distance_away = 0.0;
      cosine_of_angle_away = 0.0;
      UFG::AttackRightsComponent::GetDistanceAndAngleAway(this, i, &distance_away, &cosine_of_angle_away);
      if ( v6 >= distance_away )
        v6 = distance_away;
      if ( v7 <= cosine_of_angle_away )
        v7 = cosine_of_angle_away;
    }
    for ( j = 0i64; j < 2; ++j )
    {
      v14 = 0;
      if ( *m_NumAttackSlots > 0 )
      {
        v15 = &this->m_pAttackSlot[0][0][0].m_pPointer + 192 * v8 + 192 * j;
        do
        {
          v16 = *v15;
          if ( *v15 )
          {
            v20 = 0.0;
            v21 = 0.0;
            UFG::AttackRightsComponent::GetDistanceAndAngleAway(this, v16, &v20, &v21);
            if ( v6 >= v20 )
              v6 = v20;
            if ( v7 <= v21 )
              v7 = v21;
          }
          ++v14;
          v15 += 3;
        }
        while ( v14 < *m_NumAttackSlots );
      }
    }
    p_m_RunningAttacksEnabled += 16;
    p_mNext += 2;
    ++m_NumAttackSlots;
    v8 += 2i64;
    --v17;
  }
  while ( v17 );
  this->m_InCombatWithSomeone = v6 <= m_FarDistance && v7 >= v2;
}

// File Line: 743
// RVA: 0x35EC30
void __fastcall UFG::AttackRightsComponent::GetDistanceAndAngleAway(
        UFG::AttackRightsComponent *this,
        UFG::HasAttackRequestNode *attacker,
        float *distance_away,
        float *cosine_of_angle_away)
{
  UFG::TransformNodeComponent *m_pSimComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rdi
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimComponent *v10; // rax
  UFG::TransformNodeComponent *v11; // rbx
  float v12; // xmm6_4
  __m128 mPrev_high; // xmm7
  UFG::SimComponent *v14; // rbx
  __m128 v15; // xmm1
  float v16; // xmm4_4
  __m128 vfptr_high; // xmm3
  __m128 v18; // xmm1
  float v19; // xmm5_4

  UFG::g_pThis = this;
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  mNext = 0i64;
  UFG::g_Attacker = attacker;
  UFG::g_pAttackerTransformNodeComponent = 0i64;
  UFG::g_pMyTransformNodeComponent = m_pSimComponent;
  *distance_away = 99999.0;
  *cosine_of_angle_away = 0.0;
  if ( attacker )
  {
    m_pPointer = attacker->m_pOwner.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer[3].m_BoundComponentHandles.mNode.mNext && this->m_pTransformNodeComponent.m_pSimComponent )
      {
        UFG::g_pAttackerTransformNodeComponent = (UFG::TransformNodeComponent *)m_pPointer[3].m_BoundComponentHandles.mNode.mNext;
        v10 = attacker->m_pOwner.m_pPointer;
        if ( v10 )
          mNext = v10[3].m_BoundComponentHandles.mNode.mNext;
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mNext);
        v11 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(v11);
        mPrev_high = (__m128)HIDWORD(mNext[11].mPrev);
        v12 = *(float *)&mNext[11].mPrev - v11->mWorldTransform.v3.x;
        mPrev_high.m128_f32[0] = mPrev_high.m128_f32[0] - v11->mWorldTransform.v3.y;
        v14 = this->m_pTransformNodeComponent.m_pSimComponent;
        v15 = mPrev_high;
        v15.m128_f32[0] = (float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]) + (float)(v12 * v12);
        *(_DWORD *)distance_away = _mm_sqrt_ps(v15).m128_u32[0];
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v14);
        v16 = *(float *)&v14[2].vfptr;
        vfptr_high = (__m128)HIDWORD(v14[2].vfptr);
        v18 = vfptr_high;
        v18.m128_f32[0] = (float)(vfptr_high.m128_f32[0] * vfptr_high.m128_f32[0]) + (float)(v16 * v16);
        LODWORD(v19) = _mm_sqrt_ps(v18).m128_u32[0];
        if ( *distance_away > 0.001 && v19 > 0.001 )
          *cosine_of_angle_away = (float)((float)((float)(vfptr_high.m128_f32[0] * (float)(1.0 / v19))
                                                * (float)(mPrev_high.m128_f32[0] * (float)(1.0 / *distance_away)))
                                        + (float)((float)(v16 * (float)(1.0 / v19))
                                                * (float)(v12 * (float)(1.0 / *distance_away))))
                                + (float)((float)((float)(1.0 / v19) * 0.0)
                                        * (float)((float)(1.0 / *distance_away) * 0.0));
      }
    }
  }
}

// File Line: 791
// RVA: 0x350780
__int64 __fastcall UFG::AttackRightsComponent::CountNumDistinctAttackers(
        UFG::AttackRightsComponent *this,
        UFG::SimObject *exclude_this_guy)
{
  unsigned int v2; // r14d
  __int64 v5; // rsi
  int *m_NumAttackSlots; // rbp
  __int64 v7; // rdi
  int v8; // r10d
  __int64 v9; // r8
  __int64 i; // r11
  __int64 v11; // r9
  UFG::HasAttackRequestNode **v12; // rdx
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimObject *v14; // rcx
  __int64 m_pSimObject; // rcx
  __int64 v16; // rax
  __int64 v18[128]; // [rsp+0h] [rbp-418h]

  v2 = 0;
  v5 = 0i64;
  m_NumAttackSlots = this->m_NumAttackSlots;
  do
  {
    v7 = *m_NumAttackSlots;
    v8 = 0;
    v9 = 0i64;
    for ( i = 0i64; i < 2; ++i )
    {
      if ( v7 > 0 )
      {
        v11 = v7;
        v12 = &this->m_pAttackSlot[0][0][0].m_pPointer + 192 * v5 + 192 * i;
        do
        {
          if ( *v12 )
          {
            m_pPointer = (*v12)->m_pOwner.m_pPointer;
            v14 = m_pPointer ? m_pPointer->m_pSimObject : 0i64;
            if ( v14 != exclude_this_guy )
            {
              if ( m_pPointer )
                m_pSimObject = (__int64)m_pPointer->m_pSimObject;
              else
                m_pSimObject = 0i64;
              v16 = 0i64;
              if ( v9 <= 0 )
              {
LABEL_16:
                if ( v9 < 128 )
                {
                  v18[v9] = m_pSimObject;
                  ++v8;
                  ++v9;
                }
              }
              else
              {
                while ( v18[v16] != m_pSimObject )
                {
                  if ( ++v16 >= v9 )
                    goto LABEL_16;
                }
              }
            }
          }
          v12 += 3;
          --v11;
        }
        while ( v11 );
      }
    }
    v5 += 2i64;
    v2 += v8;
    ++m_NumAttackSlots;
  }
  while ( v5 < 6 );
  return v2;
}

// File Line: 957
// RVA: 0x342770
char __fastcall UFG::AttackRightsComponent::AttackerIsAvailable(
        UFG::AttackRightsComponent *this,
        UFG::HasAttackRequestNode *attacker)
{
  UFG::SimComponent *m_pPointer; // rax
  UFG::TransformNodeComponent *mNext; // rbp
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  UFG::SimComponent *v7; // rdx
  float v8; // xmm1_4
  float v9; // xmm0_4
  char v10; // bl
  float v11; // xmm1_4
  __int64 v12; // r8
  UFG::SimObject *v13; // r14
  float v14; // xmm0_4
  UFG::HealthComponent *m_pSimObject; // rax
  UFG::ActionTreeComponent *v16; // rcx
  bool IsDowned; // al
  UFG::SimComponent *v18; // rcx
  bool v19; // bp
  UFG::ActionTreeComponent *v20; // rcx
  bool IsStunned; // al

  if ( !attacker )
    return 0;
  m_pPointer = attacker->m_pOwner.m_pPointer;
  if ( !m_pPointer )
    return 0;
  if ( !*(_QWORD *)&m_pPointer[2].m_TypeUID )
    return 0;
  mNext = (UFG::TransformNodeComponent *)m_pPointer[3].m_BoundComponentHandles.mNode.mNext;
  if ( !mNext || !this->m_pTransformNodeComponent.m_pSimComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  v7 = attacker->m_pOwner.m_pPointer;
  v8 = mNext->mWorldTransform.v3.y - m_pSimComponent->mWorldTransform.v3.y;
  v9 = mNext->mWorldTransform.v3.x - m_pSimComponent->mWorldTransform.v3.x;
  v10 = 0;
  v11 = (float)(v8 * v8) + (float)(v9 * v9);
  if ( v7 )
    v12 = *(_QWORD *)&v7[2].m_TypeUID;
  else
    v12 = 0i64;
  v13 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v12 + 96) + 30i64) + *(_QWORD *)(v12 + 88) + 40);
  v14 = UFG::AttackRightsComponent::s_MaxAttackRanges[attacker->m_AttackType];
  if ( v7 )
    m_pSimObject = (UFG::HealthComponent *)v7[4].m_pSimObject;
  else
    m_pSimObject = 0i64;
  if ( v7 )
    v16 = *(UFG::ActionTreeComponent **)&v7[5].m_TypeUID;
  else
    v16 = 0i64;
  IsDowned = UFG::IsDowned(v16, m_pSimObject);
  v18 = attacker->m_pOwner.m_pPointer;
  v19 = IsDowned;
  if ( v18 )
    v20 = *(UFG::ActionTreeComponent **)&v18[5].m_TypeUID;
  else
    v20 = 0i64;
  IsStunned = UFG::IsStunned(v20);
  if ( !v19 && !IsStunned && v11 <= (float)(v14 * v14) && v13 == this->m_pSimObject )
    return 1;
  return v10;
}

// File Line: 981
// RVA: 0x394300
void __fastcall UFG::AttackRightsComponent::UpdateAttackSlotLists(
        UFG::AttackRightsComponent *this,
        UFG::eAttackType attack_type)
{
  float mSimTime_Temp; // xmm1_4
  __int64 v4; // rbp
  __int64 i; // r10
  int v6; // r9d
  UFG::HasAttackRequestNode **v7; // r8
  UFG::HasAttackRequestNode *v8; // rax
  __int64 v9; // rcx
  _QWORD *v10; // rax
  __int64 *v11; // rax
  __int64 v12; // rcx
  __int64 j; // r15
  int v14; // edi
  UFG::HasAttackRequestNode **v15; // rsi
  UFG::HasAttackRequestNode *v16; // r14
  int CorrectAttackSlotList; // eax
  int *v18; // r8
  __int64 v19; // rcx
  __int64 v20; // rdx
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  __int64 v24; // r11
  __int64 *v25; // rsi
  int v26; // edi
  int v27; // r9d
  __int64 *v28; // r10
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v29; // rdx
  UFG::HasAttackRequestNode *v30; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v33; // rax
  bool *v34; // r15
  UFG::HasAttackRequestNode *p_mNext; // rsi
  __int64 v36; // r14
  int v37; // eax
  __int64 v38; // r8
  __int64 v39; // r9
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v40; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v41; // rax
  __int64 v42; // rdx
  bool v43; // zf
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v44; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v45; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v46; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v47; // rax
  __int64 v48[128]; // [rsp+20h] [rbp-428h] BYREF
  __int64 v49; // [rsp+450h] [rbp+8h] BYREF

  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  v4 = attack_type;
  for ( i = 0i64; i < 2; ++i )
  {
    v6 = 0;
    if ( this->m_NumAttackSlots[attack_type] > 0 )
    {
      v7 = &this->m_pAttackSlot[0][0][0].m_pPointer + 384 * attack_type + 192 * i;
      do
      {
        v8 = *v7;
        if ( *v7
          && !v8->m_CurrentlyAttacking
          && (float)(mSimTime_Temp - v8->m_TimeFinishedAttacking) > 0.5
          && (float)(mSimTime_Temp - v8->m_LastTimePolled) > 7.0 )
        {
          if ( v8 )
          {
            v9 = (__int64)*(v7 - 2);
            v10 = *(v7 - 1);
            *(_QWORD *)(v9 + 8) = v10;
            *v10 = v9;
            *(v7 - 2) = (UFG::HasAttackRequestNode *)(v7 - 2);
            *(v7 - 1) = (UFG::HasAttackRequestNode *)(v7 - 2);
          }
          *v7 = 0i64;
        }
        ++v6;
        v7 += 3;
      }
      while ( v6 < this->m_NumAttackSlots[attack_type] );
    }
  }
  v11 = v48;
  v12 = 16i64;
  do
  {
    *v11 = 0i64;
    v11[1] = 0i64;
    v11[2] = 0i64;
    v11 += 8;
    *(v11 - 5) = 0i64;
    *(v11 - 4) = 0i64;
    *(v11 - 3) = 0i64;
    *(v11 - 2) = 0i64;
    *(v11 - 1) = 0i64;
    --v12;
  }
  while ( v12 );
  v49 = 0i64;
  for ( j = 0i64; j < 2; ++j )
  {
    v14 = 0;
    if ( this->m_NumAttackSlots[v4] > 0 )
    {
      v15 = &this->m_pAttackSlot[0][0][0].m_pPointer + 384 * v4 + 192 * j;
      do
      {
        v16 = *v15;
        if ( *v15 )
        {
          CorrectAttackSlotList = UFG::AttackRightsComponent::GetCorrectAttackSlotList(this, *v15);
          v18 = (int *)&v49 + CorrectAttackSlotList;
          v19 = *v18;
          v20 = v19 + ((__int64)CorrectAttackSlotList << 6);
          v21 = v19 + 1;
          v22 = 63;
          v48[v20] = (__int64)v16;
          if ( v21 < 63 )
            v22 = v21;
          *v18 = v22;
        }
        ++v14;
        v15 += 3;
      }
      while ( v14 < this->m_NumAttackSlots[v4] );
    }
  }
  v23 = this->m_NumAttackSlots[v4];
  v24 = 0i64;
  v25 = v48;
  v26 = v23;
  do
  {
    v27 = 0;
    if ( v23 > 0 )
    {
      v28 = v25;
      v29 = this->m_pAttackSlot[v4][v24];
      do
      {
        v30 = (UFG::HasAttackRequestNode *)*v28;
        if ( v29->m_pPointer )
        {
          mPrev = v29->mPrev;
          mNext = v29->mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          v29->mPrev = v29;
          v29->mNext = v29;
        }
        v29->m_pPointer = v30;
        if ( v30 )
        {
          v33 = v30->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
          --v26;
          v33->mNext = v29;
          v29->mPrev = v33;
          v29->mNext = &v30->m_SafePointerList.mNode;
          v30->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = v29;
        }
        v23 = this->m_NumAttackSlots[v4];
        ++v27;
        ++v28;
        ++v29;
      }
      while ( v27 < v23 );
    }
    ++v24;
    v25 += 64;
  }
  while ( v24 < 2 );
  v34 = &this->m_RunningAttacksEnabled + 16 * v4;
  p_mNext = (UFG::HasAttackRequestNode *)&this->m_AttackSlotQueue[v4].mNode.mNext[-3].mNext;
  if ( p_mNext != (UFG::HasAttackRequestNode *)v34 )
  {
    do
    {
      if ( v26 <= 0 )
        break;
      v36 = (__int64)&p_mNext->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext[-3].mNext;
      v37 = UFG::AttackRightsComponent::GetCorrectAttackSlotList(this, p_mNext);
      if ( v37 != -1 )
      {
        v38 = v37;
        v39 = *((int *)&v49 + v37);
        if ( (int)v39 < 64 )
        {
          v40 = p_mNext->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mPrev;
          v41 = p_mNext->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext;
          v40->mNext = v41;
          v41->mPrev = v40;
          p_mNext->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mPrev = &p_mNext->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>;
          p_mNext->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext = &p_mNext->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>;
          v42 = v39 + ((v38 + 2 * v4) << 6) + 2 * (v39 + ((v38 + 2 * v4) << 6)) + 11;
          v43 = *((_QWORD *)&this->m_SafePointerList.mNode.mNext + v42) == 0i64;
          v44 = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&(&this->vfptr)[v42];
          if ( !v43 )
          {
            v45 = v44->mPrev;
            v46 = v44->mNext;
            v45->mNext = v46;
            v46->mPrev = v45;
            v44->mPrev = v44;
            v44->mNext = v44;
          }
          v44[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)p_mNext;
          v47 = p_mNext->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
          v47->mNext = v44;
          v44->mPrev = v47;
          v44->mNext = &p_mNext->m_SafePointerList.mNode;
          --v26;
          *((_DWORD *)&v49 + v38) = v39 + 1;
          p_mNext->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = v44;
        }
      }
      p_mNext = (UFG::HasAttackRequestNode *)v36;
    }
    while ( (bool *)v36 != v34 );
  }
}

// File Line: 1102
// RVA: 0x3965B0
void __fastcall UFG::AttackRightsComponent::UpdateFrustum(float a1)
{
  UFG::BaseCameraComponent *CurrentBaseCamera; // rax
  UFG::BaseCameraComponent *v2; // rdi
  double v3; // xmm0_8
  float v4; // xmm6_4
  float DisplayAspectRatio; // xmm9_4
  float *v6; // rbx
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  float *p_mFOVOffset; // rax
  float v9; // xmm0_4
  float v10; // xmm8_4
  UFG::BaseCameraComponent *v11; // rcx
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  UFG::qMatrix44 *WorldView; // rax
  float v16; // xmm10_4
  float v17; // xmm9_4
  float v18; // xmm11_4
  float v19; // xmm15_4
  float v20; // xmm14_4
  float v21; // xmm13_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  float v25; // xmm4_4
  float v26; // xmm0_4
  __m128 v27; // xmm2
  float v28; // xmm0_4
  __m128 v29; // xmm2
  float v30; // xmm4_4
  float v31; // xmm6_4
  float v32; // xmm0_4
  __m128 v33; // xmm2
  float v34; // xmm7_4
  float v35; // [rsp+30h] [rbp-158h]
  float v36; // [rsp+3Ch] [rbp-14Ch]
  float v37; // [rsp+40h] [rbp-148h]
  float v38; // [rsp+44h] [rbp-144h]
  UFG::qMatrix44 result; // [rsp+50h] [rbp-138h] BYREF
  UFG::qMatrix44 dest; // [rsp+90h] [rbp-F8h] BYREF
  float v41; // [rsp+190h] [rbp+8h]
  float v42; // [rsp+190h] [rbp+8h]

  if ( UFG::Metrics::msInstance.mSimFrameCount != UFG::AttackRightsComponent::s_FrustumPlanesLastUpdateFrame )
  {
    UFG::AttackRightsComponent::s_FrustumPlanesLastUpdateFrame = UFG::Metrics::msInstance.mSimFrameCount;
    CurrentBaseCamera = UFG::GetCurrentBaseCamera();
    v2 = CurrentBaseCamera;
    if ( CurrentBaseCamera )
    {
      v3 = ((double (__fastcall *)(UFG::BaseCameraComponent *))CurrentBaseCamera->vfptr[19].__vecDelDtor)(CurrentBaseCamera);
      v4 = *(float *)&v3 - UFG::AttackRightsComponent::s_OnScreenTestFOVReduction;
      if ( (float)(*(float *)&v3 - UFG::AttackRightsComponent::s_OnScreenTestFOVReduction) <= 0.0 )
        v4 = 0.0;
      DisplayAspectRatio = Render::GetDisplayAspectRatio();
      v6 = 0i64;
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        p_mFOVOffset = &mCurrentCamera->mCamera.mFOVOffset;
      else
        p_mFOVOffset = 0i64;
      v9 = p_mFOVOffset[58];
      if ( v9 == 0.0 || v9 == p_mFOVOffset[59] )
        v10 = v41;
      else
        v10 = p_mFOVOffset[62] / v9;
      v11 = UFG::Director::Get()->mCurrentCamera;
      if ( v11 )
        v6 = &v11->mCamera.mFOVOffset;
      v12 = v6[58];
      v13 = v6[59];
      if ( v12 == 0.0 || v12 == v13 )
        v14 = v41;
      else
        v14 = (float)(v6[62] - v6[63]) / (float)(v12 - v13);
      UFG::qPerspectiveMatrix(&dest, v4, DisplayAspectRatio, v10, v14 - 1.0);
      WorldView = UFG::Camera::GetWorldView(&v2->mCamera);
      UFG::qMatrix44::operator*(WorldView, &result, &dest);
      LODWORD(v16) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
      LODWORD(v17) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
      LODWORD(v42) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
      LODWORD(v38) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
      LODWORD(v18) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
      LODWORD(v19) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
      LODWORD(v20) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
      LODWORD(v21) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
      LODWORD(v36) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
      LODWORD(v37) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
      LODWORD(v35) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
      v22 = fsqrt(
              (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                    + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
            + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
      UFG::AttackRightsComponent::s_FrustumPlanes[0].x = COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])
                                                       * (float)(1.0 / v22);
      *(float *)&dword_1423BA854 = COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * (float)(1.0 / v22);
      *(float *)&dword_1423BA858 = COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * (float)(1.0 / v22);
      *(float *)&dword_1423BA85C = COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]) * (float)(1.0 / v22);
      v23 = fsqrt((float)((float)(v16 * v16) + (float)(v18 * v18)) + (float)(v17 * v17));
      LODWORD(v24) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
      LODWORD(v25) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
      *(float *)&dword_1423BA860 = v18 * (float)(1.0 / v23);
      *(float *)&dword_1423BA864 = v16 * (float)(1.0 / v23);
      *(float *)&dword_1423BA868 = v17 * (float)(1.0 / v23);
      *(float *)&dword_1423BA86C = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0])
                                 * (float)(1.0 / v23);
      v26 = fsqrt((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v21 * v21));
      v27 = (__m128)LODWORD(v42);
      *(float *)&dword_1423BA870 = v19 * (float)(1.0 / v26);
      *(float *)&dword_1423BA874 = v20 * (float)(1.0 / v26);
      v27.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v24 * v24)) + (float)(v25 * v25);
      *(float *)&dword_1423BA878 = v21 * (float)(1.0 / v26);
      *(float *)&dword_1423BA87C = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0])
                                 * (float)(1.0 / v26);
      v28 = _mm_sqrt_ps(v27).m128_f32[0];
      *(float *)&dword_1423BA88C = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0])
                                 * (float)(1.0 / v28);
      *(float *)&dword_1423BA884 = v42 * (float)(1.0 / v28);
      v29 = (__m128)LODWORD(v36);
      *(float *)&dword_1423BA888 = v25 * (float)(1.0 / v28);
      LODWORD(v30) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
      *(float *)&dword_1423BA880 = v24 * (float)(1.0 / v28);
      LODWORD(v31) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
      v29.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v31 * v31)) + (float)(v30 * v30);
      v32 = _mm_sqrt_ps(v29).m128_f32[0];
      *(float *)&dword_1423BA89C = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0])
                                 * (float)(1.0 / v32);
      *(float *)&dword_1423BA894 = v36 * (float)(1.0 / v32);
      v33 = (__m128)LODWORD(v38);
      *(float *)&dword_1423BA898 = v30 * (float)(1.0 / v32);
      *(float *)&dword_1423BA890 = v31 * (float)(1.0 / v32);
      v33.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v37 * v37)) + (float)(v35 * v35);
      v34 = 1.0 / _mm_sqrt_ps(v33).m128_f32[0];
      *(float *)&dword_1423BA8A4 = v38 * v34;
      *(float *)&dword_1423BA8A8 = v35 * v34;
      *(float *)&dword_1423BA8AC = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]) * v34;
      *(float *)&dword_1423BA8A0 = v34 * v37;
    }
  }
}

// File Line: 1152
// RVA: 0x35B630
signed __int64 __fastcall UFG::AttackRightsComponent::GetCorrectAttackSlotList(
        UFG::AttackRightsComponent *this,
        UFG::HasAttackRequestNode *attacker)
{
  UFG::SimComponent *m_pPointer; // rax
  float *mNext; // rbx
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm6_4
  int v7; // ebx
  int v8; // eax
  UFG::qVector3 pos; // [rsp+20h] [rbp-38h] BYREF
  UFG::qVector3 v11; // [rsp+30h] [rbp-28h] BYREF

  m_pPointer = attacker->m_pOwner.m_pPointer;
  if ( !m_pPointer )
    return 0xFFFFFFFFi64;
  mNext = (float *)m_pPointer[3].m_BoundComponentHandles.mNode.mNext;
  if ( !mNext )
    return 0xFFFFFFFFi64;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer[3].m_BoundComponentHandles.mNode.mNext);
  v4 = mNext[44];
  v5 = mNext[45];
  v6 = UFG::AttackRightsComponent::s_OnScreenTestHeadSphereRadius;
  pos.z = mNext[46];
  v11.z = pos.z + UFG::AttackRightsComponent::s_OnScreenTestHeadHeight;
  pos.x = v4;
  pos.y = v5;
  v11.x = v4;
  v11.y = v5;
  v7 = IntersectSphereFrustum(
         UFG::AttackRightsComponent::s_FrustumPlanes,
         &pos,
         UFG::AttackRightsComponent::s_OnScreenTestFootSphereRadius);
  v8 = IntersectSphereFrustum(UFG::AttackRightsComponent::s_FrustumPlanes, &v11, v6);
  return v7 == 2 && v8 == 2;
}

// File Line: 1185
// RVA: 0x384EC0
void __fastcall UFG::AttackRightsComponent::SetAllowedToUseAttackSlotLists(
        UFG::AttackRightsComponent *this,
        UFG::eAttackType attack_type)
{
  float mSimTime_Temp; // xmm7_4
  __int64 v3; // rdi
  float v5; // xmm0_4
  int v6; // r9d
  int v7; // edx
  UFG::HasAttackRequestNode **i; // rcx

  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  v3 = attack_type;
  if ( attack_type )
  {
    if ( UFG::Metrics::msInstance.mSimTime_Temp <= this->m_NextTimeToUpdateAllowedToUseAttackSlotList[attack_type] )
      goto LABEL_9;
    this->m_AllowedToUseAttackSlotList[attack_type][0] = 1;
    this->m_AllowedToUseAttackSlotList[attack_type][1] = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) < 0.2;
    v5 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) + 3.0;
    if ( v5 <= 3.0 )
    {
      v5 = FLOAT_3_0;
    }
    else if ( v5 >= 4.0 )
    {
      this->m_NextTimeToUpdateAllowedToUseAttackSlotList[v3] = mSimTime_Temp + 4.0;
      goto LABEL_9;
    }
    this->m_NextTimeToUpdateAllowedToUseAttackSlotList[v3] = v5 + mSimTime_Temp;
  }
  else
  {
    *(_WORD *)&this->m_AllowedToUseAttackSlotList[0][0] = 257;
    this->m_NextTimeToUpdateAllowedToUseAttackSlotList[0] = -99999.0;
  }
LABEL_9:
  *(_WORD *)&this->m_OverrideAllowedToUseAttackSlotListThisFrame[v3][0] = 256;
  v6 = this->m_NumAttackSlots[v3];
  v7 = 0;
  if ( v6 > 0 )
  {
    for ( i = &this->m_pAttackSlot[0][0][0].m_pPointer + 384 * v3; !*i; i += 3 )
    {
      if ( ++v7 >= v6 )
        return;
    }
    this->m_OverrideAllowedToUseAttackSlotListThisFrame[v3][1] = 0;
  }
}

// File Line: 1229
// RVA: 0x3883D0
void __fastcall UFG::AttackRightsComponent::SortAttackSlots(
        UFG::AttackRightsComponent *this,
        UFG::eAttackType attack_type)
{
  UFG::TransformNodeComponent *m_pSimComponent; // rcx
  UFG::HasAttackRequestNode **p_m_pPointer; // rsi
  __int64 v5; // r12
  int (*m_NextAttackBaton)[2]; // r13
  __int64 v7; // r14
  __int64 v8; // rbx
  UFG::HasAttackRequestNode *v9; // rdi
  float AttackerScore; // xmm0_4
  int v11; // edi
  int v12; // r14d
  char v13; // r8
  __int64 v14; // r9
  __int64 v15; // rbx
  int v16; // xmm1_4
  int v17; // xmm0_4
  bool v18; // al
  UFG::HasAttackRequestNode *m_pPointer; // r10
  __int64 v20; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v21; // rdx
  __int64 v22; // r11
  UFG::HasAttackRequestNode *v23; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v30; // rax
  int v31[64]; // [rsp+20h] [rbp-138h]
  UFG::HasAttackRequestNode **v32; // [rsp+170h] [rbp+18h]

  if ( attack_type == eATTACK_TYPE_MELEE && UFG::BattleManager::s_pInstance->m_CurrentBattleType == eBATTLE_TYPE_NORMAL )
  {
    m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
      p_m_pPointer = &this->m_pAttackSlot[0][0][0].m_pPointer;
      v32 = &this->m_pAttackSlot[0][0][0].m_pPointer;
      v5 = 0i64;
      m_NextAttackBaton = this->m_NextAttackBaton;
      do
      {
        v7 = this->m_NumAttackSlots[0];
        v8 = 0i64;
        if ( (int)v7 > 0 )
        {
          do
          {
            v9 = *p_m_pPointer;
            AttackerScore = UFG::AttackRightsComponent::GetAttackerScore(this, *p_m_pPointer, 0i64);
            *(float *)&v31[v8] = AttackerScore;
            if ( v9 )
              v9->m_Score = AttackerScore;
            ++v8;
            p_m_pPointer += 3;
          }
          while ( v8 < v7 );
          p_m_pPointer = v32;
        }
        v11 = 0;
        v12 = v7 - 1;
        do
        {
          v13 = 0;
          v14 = 0i64;
          if ( v12 > 0 )
          {
            v15 = (unsigned int)v12;
            do
            {
              v16 = v31[v14];
              v17 = v31[v14 + 1];
              v18 = *(float *)&v16 >= 0.0 && *(float *)&v17 >= 0.0;
              if ( *(float *)&v16 < *(float *)&v17 && v18 || *(float *)&v16 < 0.0 && *(float *)&v17 >= 0.0 )
              {
                v31[v14] = v17;
                v31[v14 + 1] = v16;
                m_pPointer = this->m_pAttackSlot[0][0][v14 + v5].m_pPointer;
                v20 = v14 + v5 + 1;
                v21 = &this->m_pAttackSlot[0][0][v14 + v5];
                v22 = v20;
                v23 = this->m_pAttackSlot[0][0][v20].m_pPointer;
                if ( v21->m_pPointer )
                {
                  mPrev = v21->mPrev;
                  mNext = v21->mNext;
                  mPrev->mNext = mNext;
                  mNext->mPrev = mPrev;
                  v21->mPrev = v21;
                  v21->mNext = v21;
                }
                v21->m_pPointer = v23;
                if ( v23 )
                {
                  v26 = v23->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
                  v26->mNext = v21;
                  v21->mPrev = v26;
                  v21->mNext = &v23->m_SafePointerList.mNode;
                  v23->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = v21;
                }
                v27 = &this->m_pAttackSlot[0][0][v22];
                if ( v27->m_pPointer )
                {
                  v28 = v27->mPrev;
                  v29 = v27->mNext;
                  v28->mNext = v29;
                  v29->mPrev = v28;
                  v27->mPrev = v27;
                  v27->mNext = v27;
                }
                v27->m_pPointer = m_pPointer;
                if ( m_pPointer )
                {
                  v30 = m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
                  v30->mNext = v27;
                  v27->mPrev = v30;
                  v27->mNext = &m_pPointer->m_SafePointerList.mNode;
                  m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = v27;
                }
                v13 = 1;
              }
              ++v14;
              --v15;
            }
            while ( v15 );
          }
          ++v11;
        }
        while ( v13 && v11 < 100 );
        p_m_pPointer += 192;
        v5 += 64i64;
        *(_DWORD *)m_NextAttackBaton = 0;
        m_NextAttackBaton = (int (*)[2])((char *)m_NextAttackBaton + 4);
        v32 = p_m_pPointer;
      }
      while ( v5 < 128 );
    }
  }
  if ( UFG::AttackRightsComponent::s_SimPauseOnSortAttackSlots )
  {
    UFG::Metrics::msInstance.mSimPausedDebug = 1;
    UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
  }
}

// File Line: 1318
// RVA: 0x35AB40
float __fastcall UFG::AttackRightsComponent::GetAttackerScore(
        UFG::AttackRightsComponent *this,
        UFG::HasAttackRequestNode *attacker,
        UFG::qString *debug_string)
{
  float v6; // xmm6_4
  __int64 m_AttackType; // r13
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimObject *v9; // rbp
  UFG::TransformNodeComponent *v10; // r14
  __int64 v11; // rsi
  UFG::SimComponent *m_pSimComponent; // rbx
  __m128 mPrev_low; // xmm1
  float v14; // xmm0_4
  UFG::qString *v15; // rax
  UFG::SimComponent *v16; // rax
  UFG::SimObject *m_pSimObject; // rax
  UFG::qString *v18; // rax
  UFG::SimObjectProp *v19; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  UFG::qString *v22; // rax
  UFG::SimComponent *v23; // r14
  __int64 p_m_pTransformNodeComponent; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **i; // r14
  __int64 v26; // rcx
  float v27; // xmm7_4
  char *String_DBG; // rax
  UFG::qString *v29; // rax
  __int64 v30; // rcx
  UFG::qString *v31; // rax
  UFG::HasAttackRequestNode *v32; // rcx
  UFG::SimComponent *v33; // rax
  UFG::SimObject *v34; // rax
  UFG::SimComponent *v35; // rcx
  __int64 v37; // [rsp+20h] [rbp-88h]
  UFG::qString v38; // [rsp+28h] [rbp-80h] BYREF

  v37 = -2i64;
  v6 = FLOAT_N1_0;
  if ( !attacker )
    return v6;
  m_AttackType = attacker->m_AttackType;
  m_pPointer = attacker->m_pOwner.m_pPointer;
  v9 = 0i64;
  v10 = m_pPointer ? (UFG::TransformNodeComponent *)m_pPointer[3].m_BoundComponentHandles.mNode.mNext : 0i64;
  if ( !this->m_pTransformNodeComponent.m_pSimComponent
    || !this->m_pTargetingSystemBaseComponent.m_pSimComponent
    || !v10 )
  {
    return v6;
  }
  if ( m_pPointer )
    v11 = *(_QWORD *)&m_pPointer[2].m_TypeUID;
  else
    v11 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v10);
  m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
  mPrev_low = (__m128)LODWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev);
  v14 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1) - v10->mWorldTransform.v3.y;
  mPrev_low.m128_f32[0] = (float)((float)(mPrev_low.m128_f32[0] - v10->mWorldTransform.v3.x)
                                * (float)(mPrev_low.m128_f32[0] - v10->mWorldTransform.v3.x))
                        + (float)(v14 * v14);
  v6 = MAX_DISTANCE - _mm_sqrt_ps(mPrev_low).m128_f32[0];
  if ( v6 <= 0.0 )
    v6 = 0.0;
  if ( debug_string )
  {
    UFG::qString::qString(&v38, "\nDistance score: %.1f", v6);
    UFG::qString::operator+=(debug_string, v15);
    UFG::qString::~qString(&v38);
  }
  v16 = attacker->m_pOwner.m_pPointer;
  if ( v16 )
    m_pSimObject = v16->m_pSimObject;
  else
    m_pSimObject = 0i64;
  if ( m_pSimObject == *(UFG::SimObject **)(56i64
                                          * *(unsigned __int8 *)(*(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags
                                                               + 30i64)
                                          + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
                                          + 40) )
  {
    v6 = v6 + CURRENT_TARGET_BONUS;
    if ( debug_string )
    {
      UFG::qString::qString(&v38, "\nCurrent target bonus: %.1f", CURRENT_TARGET_BONUS);
      UFG::qString::operator+=(debug_string, v18);
      UFG::qString::~qString(&v38);
    }
  }
  if ( v11 )
  {
    v19 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v11 + 96) + 25i64)
                                 + *(_QWORD *)(v11 + 88)
                                 + 40);
    if ( v19 )
    {
      m_Flags = v19->m_Flags;
      if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v19);
LABEL_31:
          if ( ComponentOfType )
          {
            if ( ComponentOfType->mWeaponTypeInfo->mFireModes[ComponentOfType->mFireMode]->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID )
            {
              v6 = v6 + MELEE_WEAPON_BONUS;
              if ( debug_string )
              {
                UFG::qString::qString(&v38, "\nMelee weapon bonus: %.1f", MELEE_WEAPON_BONUS);
                UFG::qString::operator+=(debug_string, v22);
                UFG::qString::~qString(&v38);
              }
            }
          }
          goto LABEL_35;
        }
        if ( (m_Flags & 0x1000) == 0 )
        {
          ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                         v19,
                                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          goto LABEL_31;
        }
      }
      ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v19,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      goto LABEL_31;
    }
  }
LABEL_35:
  v23 = attacker->m_pOwner.m_pPointer;
  if ( v23 )
  {
    p_m_pTransformNodeComponent = (__int64)&v23[1].m_pSimObject[-1].m_pTransformNodeComponent;
    for ( i = &v23->m_BoundComponentHandles.mNode.mNext;
          (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)p_m_pTransformNodeComponent != i;
          p_m_pTransformNodeComponent = *(_QWORD *)(p_m_pTransformNodeComponent + 48) - 40i64 )
    {
      v26 = *(_QWORD *)(p_m_pTransformNodeComponent + 24);
      v27 = *(float *)(v26 + 56);
      if ( debug_string )
      {
        String_DBG = ActionPath::GetString_DBG((ActionPath *)(v26 + 64));
        UFG::qString::qString(&v38, "\nAttackRightsScoreBonusTrack: %.1f from %s", v27, String_DBG, v37);
        UFG::qString::operator+=(debug_string, v29);
        UFG::qString::~qString(&v38);
      }
      v6 = v6 + v27;
    }
  }
  if ( v11 )
  {
    v30 = *(_QWORD *)(v11 + 88) + 56i64 * *(unsigned __int8 *)(*(_QWORD *)(v11 + 96) + 31i64);
    if ( *(_QWORD *)(v30 + 40) )
    {
      if ( *(_BYTE *)(v30 + 49) )
      {
        if ( v6 >= 0.0 )
          v6 = 0.0;
        if ( debug_string )
        {
          UFG::qString::qString(&v38, "\nZeroed out because in grapple");
          UFG::qString::operator+=(debug_string, v31);
          UFG::qString::~qString(&v38);
        }
      }
    }
  }
  v32 = this->m_pPreviousBestAttacker[m_AttackType].m_pPointer;
  if ( v32 )
  {
    v33 = attacker->m_pOwner.m_pPointer;
    if ( v33 )
      v34 = v33->m_pSimObject;
    else
      v34 = 0i64;
    v35 = v32->m_pOwner.m_pPointer;
    if ( v35 )
      v9 = v35->m_pSimObject;
    if ( v34 == v9 )
    {
      if ( v6 >= 0.0 )
        v6 = 0.0;
      if ( debug_string )
      {
        UFG::qString::operator+=(debug_string, "\nZeroed out because was last attacker");
        if ( v6 < 0.0 )
          UFG::qString::operator+=(debug_string, " (left as negative though)");
      }
    }
  }
  return v6;
}

// File Line: 1438
// RVA: 0x381280
void __fastcall UFG::AttackRightsComponent::RemoveAttackSlotGuysFromTheQueue(UFG::AttackRightsComponent *this)
{
  __int64 v2; // rbx
  int *m_NumAttackSlots; // rdi
  __int64 i; // r10
  __int64 v5; // r9
  UFG::HasAttackRequestNode **v6; // r8
  UFG::HasAttackRequestNode *v7; // rdx
  bool *v8; // rcx
  bool *j; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *mPrev; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *mNext; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v12; // rdx

  v2 = 0i64;
  m_NumAttackSlots = this->m_NumAttackSlots;
  do
  {
    for ( i = 0i64; i < 2; ++i )
    {
      v5 = *m_NumAttackSlots;
      if ( v5 > 0 )
      {
        v6 = &this->m_pAttackSlot[0][0][0].m_pPointer + 192 * v2 + 192 * i;
        do
        {
          v7 = *v6;
          if ( *v6 )
          {
            v8 = &this->m_RunningAttacksEnabled + 16 * v7->m_AttackType;
            for ( j = (bool *)&this->m_AttackSlotQueue[v7->m_AttackType].mNode.mNext[-3].mNext;
                  j != v8;
                  j = (bool *)(*((_QWORD *)j + 6) - 40i64) )
            {
              if ( j == (bool *)v7 )
                break;
            }
            mPrev = v7->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mPrev;
            mNext = v7->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext;
            v12 = &v7->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>;
            mPrev->mNext = mNext;
            mNext->mPrev = mPrev;
            v12->mPrev = v12;
            v12->mNext = v12;
          }
          v6 += 3;
          --v5;
        }
        while ( v5 );
      }
    }
    v2 += 2i64;
    ++m_NumAttackSlots;
  }
  while ( v2 < 6 );
}

// File Line: 1468
// RVA: 0x3980D0
void __fastcall UFG::AttackRightsComponent::UpdatePreviousBestAttacker(UFG::AttackRightsComponent *this)
{
  float mSimTime_Temp; // xmm9_4
  int (*m_NextAttackBaton)[2]; // rax
  __int64 v4; // r13
  float *m_NextTimeToUpdatePreviousBestAttacker; // rbp
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *m_pPreviousBestAttacker; // r12
  int v7; // r15d
  __int64 v8; // rsi
  __int64 v9; // r10
  int *v10; // rdi
  int v11; // ecx
  int v12; // r8d
  UFG::HasAttackRequestNode *m_pPointer; // r9
  bool v14; // zf
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v17; // rax
  float m_MaxTimeBetweenAttackerSwitch; // xmm6_4
  float m_MinTimeBetweenAttackerSwitch; // xmm7_4
  float v20; // xmm0_4
  int (*v21)[2]; // [rsp+98h] [rbp+10h]

  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  m_NextAttackBaton = this->m_NextAttackBaton;
  v4 = 0i64;
  m_NextTimeToUpdatePreviousBestAttacker = this->m_NextTimeToUpdatePreviousBestAttacker;
  m_pPreviousBestAttacker = this->m_pPreviousBestAttacker;
  v21 = this->m_NextAttackBaton;
  do
  {
    if ( mSimTime_Temp > *m_NextTimeToUpdatePreviousBestAttacker )
    {
      v7 = 0;
LABEL_4:
      v8 = 0i64;
      v9 = v4;
      v10 = (int *)m_NextAttackBaton;
      while ( 1 )
      {
        v11 = *v10;
        v12 = *v10 <= 0 ? *((_DWORD *)m_NextTimeToUpdatePreviousBestAttacker - 52) - 1 : v11 - 1;
        if ( v12 != -1 )
          break;
LABEL_13:
        ++v8;
        ++v10;
        v9 += 64i64;
        if ( v8 >= 2 )
        {
          if ( ++v7 >= 2 )
            goto $done_2;
          m_NextAttackBaton = v21;
          goto LABEL_4;
        }
      }
      while ( 1 )
      {
        m_pPointer = this->m_pAttackSlot[0][0][v9 + v11].m_pPointer;
        if ( m_pPointer )
        {
          if ( m_pPointer->m_Score >= 0.0 || v7 > 0 )
            break;
        }
        v14 = v11 == v12;
        v11 = (v11 + 1) % *((_DWORD *)m_NextTimeToUpdatePreviousBestAttacker - 52);
        if ( v14 )
          goto LABEL_13;
      }
      if ( m_pPreviousBestAttacker->m_pPointer )
      {
        mPrev = m_pPreviousBestAttacker->mPrev;
        mNext = m_pPreviousBestAttacker->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        m_pPreviousBestAttacker->mPrev = m_pPreviousBestAttacker;
        m_pPreviousBestAttacker->mNext = m_pPreviousBestAttacker;
      }
      m_pPreviousBestAttacker->m_pPointer = m_pPointer;
      v17 = m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
      v17->mNext = m_pPreviousBestAttacker;
      m_pPreviousBestAttacker->mPrev = v17;
      m_pPreviousBestAttacker->mNext = &m_pPointer->m_SafePointerList.mNode;
      m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = m_pPreviousBestAttacker;
$done_2:
      m_MaxTimeBetweenAttackerSwitch = this->m_MaxTimeBetweenAttackerSwitch;
      m_MinTimeBetweenAttackerSwitch = this->m_MinTimeBetweenAttackerSwitch;
      v20 = m_MaxTimeBetweenAttackerSwitch;
      if ( m_MaxTimeBetweenAttackerSwitch > m_MinTimeBetweenAttackerSwitch )
      {
        v20 = UFG::qRandom(
                m_MaxTimeBetweenAttackerSwitch - m_MinTimeBetweenAttackerSwitch,
                (unsigned int *)&UFG::qDefaultSeed)
            + m_MinTimeBetweenAttackerSwitch;
        if ( v20 <= m_MinTimeBetweenAttackerSwitch )
          v20 = m_MinTimeBetweenAttackerSwitch;
        if ( v20 >= m_MaxTimeBetweenAttackerSwitch )
          v20 = m_MaxTimeBetweenAttackerSwitch;
      }
      m_NextAttackBaton = v21;
      *m_NextTimeToUpdatePreviousBestAttacker = v20 + mSimTime_Temp;
    }
    ++m_NextAttackBaton;
    v4 += 128i64;
    ++m_NextTimeToUpdatePreviousBestAttacker;
    ++m_pPreviousBestAttacker;
    v21 = m_NextAttackBaton;
  }
  while ( v4 < 384 );
}ousBestAttacker;
    ++m_p

// File Line: 1543
// RVA: 0x38CD60
void __fastcall UFG::AttackRightsComponent::Update(UFG::AttackRightsComponent *this, float delta_sec)
{
  float r; // xmm0_4
  UFG::SimObjectCharacter *m_pSimObject; // rcx
  UFG::HasAttackRequestNode *m_pPointer; // rdx
  UFG::SimComponent *v6; // rdx
  UFG::TransformNodeComponent *mNext; // rdx
  UFG::HasAttackRequestNode *NextAttacker; // rax
  UFG::SimComponent *v9; // rax
  int v10; // ebp
  float mSimTime_Temp; // xmm6_4
  __int64 v12; // r15
  float *m_TimeUntilNextAttack; // rsi
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *m_pCachedNextAttacker; // r14
  bool *p_m_RunningAttacksEnabled; // r13
  int v16; // r8d
  __int64 v17; // r9
  int v18; // edx
  UFG::HasAttackRequestNode **v19; // rax
  char v20; // al
  char v21; // di
  bool v22; // al
  __int64 v23; // r8
  UFG::HasAttackRequestNode *v24; // rax
  float TimeUntilInitialAttack; // xmm0_4
  UFG::HasAttackRequestNode *v26; // rax
  UFG::HasAttackRequestNode *v27; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::HasAttackRequestNode *v31; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qColour v33; // [rsp+40h] [rbp-88h] BYREF
  UFG::AttackSlotInfo next_attack_baton; // [rsp+D0h] [rbp+8h] BYREF
  UFG::AttackSlotInfo v35; // [rsp+E0h] [rbp+18h] BYREF

  m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
  if ( !m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0 )
  {
    if ( UFG::AttackRightsComponent::s_ProducerAttackRightsDebug && m_pSimObject && m_pSimObject == LocalPlayer )
    {
      r = this->m_NextTimeCanPerformOpportunityAttack[UFG::AttackRightsComponent::s_AttackTypeToDebug]
        - UFG::Metrics::msInstance.mSimTime_Temp;
      UFG::DrawDebugText(
        (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent,
        &UFG::qColour::White,
        "Next %s attack: %.1fs\nNext %s opportunity attack in %.1fs",
        (__int64)UFG::AttackTypeNames[UFG::AttackRightsComponent::s_AttackTypeToDebug],
        this->m_TimeUntilNextAttack[UFG::AttackRightsComponent::s_AttackTypeToDebug],
        UFG::AttackTypeNames[UFG::AttackRightsComponent::s_AttackTypeToDebug],
        r);
    }
    if ( !this->m_DebugDrawEnabled )
      goto LABEL_16;
    m_pPointer = this->m_pLastAttackRequest[UFG::AttackRightsComponent::s_AttackTypeToDebug].m_pPointer;
    if ( m_pPointer )
    {
      r = UFG::qColour::Green.r;
      v6 = m_pPointer->m_pOwner.m_pPointer;
      v33 = UFG::qColour::Green;
      if ( v6 )
      {
        mNext = (UFG::TransformNodeComponent *)v6[3].m_BoundComponentHandles.mNode.mNext;
LABEL_15:
        UFG::DrawLine((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent, mNext, &v33, 0.1);
        goto LABEL_16;
      }
    }
    else
    {
      NextAttacker = UFG::AttackRightsComponent::FindNextAttacker(
                       this,
                       UFG::AttackRightsComponent::s_AttackTypeToDebug,
                       &next_attack_baton);
      if ( !NextAttacker )
      {
LABEL_16:
        UFG::AttackRightsComponent::UpdateFrustum(r);
        UFG::AttackRightsComponent::RemoveAttackSlotGuysFromTheQueue(this);
        UFG::AttackRightsComponent::UnregisterUnavailableAttackers(this);
        UFG::AttackRightsComponent::CheckIfInCombat(this);
        UFG::AttackRightsComponent::CheckIfDownedStateChanged(this);
        UFG::AttackRightsComponent::UpdatePreviousBestAttacker(this);
        v10 = 0;
        mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
        v12 = 0i64;
        m_TimeUntilNextAttack = this->m_TimeUntilNextAttack;
        m_pCachedNextAttacker = this->m_pCachedNextAttacker;
        p_m_RunningAttacksEnabled = &this->m_RunningAttacksEnabled;
        while ( 1 )
        {
          *m_TimeUntilNextAttack = *m_TimeUntilNextAttack - delta_sec;
          UFG::AttackRightsComponent::SetAllowedToUseAttackSlotLists(this, (UFG::eAttackType)v10);
          if ( (bool *)(*((_QWORD *)p_m_RunningAttacksEnabled + 6) - 40i64) == p_m_RunningAttacksEnabled )
          {
            v16 = *((_DWORD *)m_TimeUntilNextAttack - 55);
            v17 = 0i64;
            while ( 1 )
            {
              v18 = 0;
              if ( v16 > 0 )
                break;
LABEL_23:
              if ( ++v17 >= 2 )
              {
                v20 = 0;
                goto LABEL_25;
              }
            }
            v19 = &this->m_pAttackSlot[0][0][0].m_pPointer + 384 * v12 + 192 * v17;
            while ( !*v19 )
            {
              ++v18;
              v19 += 3;
              if ( v18 >= v16 )
                goto LABEL_23;
            }
          }
          v20 = 1;
          if ( (float)(mSimTime_Temp - m_TimeUntilNextAttack[16]) <= 5.0 )
          {
LABEL_25:
            v21 = 0;
            if ( !v20 )
              goto LABEL_27;
          }
          else
          {
            v21 = 1;
          }
          m_TimeUntilNextAttack[16] = mSimTime_Temp;
LABEL_27:
          v22 = this->m_AttackingEnabled[v12];
          if ( v10 == 1 )
          {
            if ( !v22 || this->m_InCombatWithSomeone )
              goto LABEL_55;
          }
          else if ( !v22 )
          {
            goto LABEL_55;
          }
          UFG::AttackRightsComponent::UpdateAttackSlotLists(this, (UFG::eAttackType)v10);
          if ( this->m_CurrentlyAttacking[v12] || !v21 )
            goto LABEL_39;
          v24 = UFG::AttackRightsComponent::GetNextAttacker(this, (UFG::eAttackType)v10, v23);
          if ( v24 )
          {
            TimeUntilInitialAttack = UFG::AttackRightsComponent::GetTimeUntilInitialAttack(this, v24);
            if ( !this->m_IsDowned )
              *m_TimeUntilNextAttack = TimeUntilInitialAttack;
LABEL_39:
            if ( *m_TimeUntilNextAttack <= 0.0 )
            {
              v26 = UFG::AttackRightsComponent::FindNextAttacker(this, (UFG::eAttackType)v10, &v35);
              v27 = v26;
              if ( m_pCachedNextAttacker->m_pPointer )
              {
                mPrev = m_pCachedNextAttacker->mPrev;
                v29 = m_pCachedNextAttacker->mNext;
                mPrev->mNext = v29;
                v29->mPrev = mPrev;
                m_pCachedNextAttacker->mPrev = m_pCachedNextAttacker;
                m_pCachedNextAttacker->mNext = m_pCachedNextAttacker;
              }
              m_pCachedNextAttacker->m_pPointer = v26;
              if ( v26 )
              {
                p_mNode = &v26->m_SafePointerList.mNode;
                v31 = v26;
                v32 = v26->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
                v32->mNext = m_pCachedNextAttacker;
                m_pCachedNextAttacker->mNext = p_mNode;
                m_pCachedNextAttacker->mPrev = v32;
                p_mNode->mPrev = m_pCachedNextAttacker;
                UFG::AttackRightsComponent::MakeAttackRequest(this, v31, (bool *)(unsigned int)v10);
                if ( v10 || UFG::BattleManager::s_pInstance->m_CurrentBattleType )
                {
                  this->m_NextAttackBaton[v12][v35.m_AttackSlotList] = v35.m_AttackSlot;
                }
                else
                {
                  UFG::AttackRightsComponent::GetAttackSlotInfo(this, v27, &next_attack_baton);
                  if ( next_attack_baton.m_AttackSlotList != eATTACK_SLOT_LIST_NONE
                    && next_attack_baton.m_AttackSlot != -1 )
                  {
                    this->m_NextAttackBaton[v12][next_attack_baton.m_AttackSlotList] = next_attack_baton.m_AttackSlot;
                  }
                }
                if ( !this->m_IsDowned )
                  *m_TimeUntilNextAttack = *(float *)((char *)m_TimeUntilNextAttack
                                                    + (char *)TIMEOUT_UNTIL_NEXT_ATTACK
                                                    - (char *)this
                                                    - 9524);
              }
              else if ( !this->m_IsDowned )
              {
                *m_TimeUntilNextAttack = 0.0;
              }
            }
            goto LABEL_55;
          }
          if ( this->m_IsDowned )
            goto LABEL_39;
          *m_TimeUntilNextAttack = 0.1;
LABEL_55:
          ++v10;
          ++v12;
          p_m_RunningAttacksEnabled += 16;
          ++m_pCachedNextAttacker;
          ++m_TimeUntilNextAttack;
          if ( v10 >= 3 )
          {
            UFG::AttackRightsComponent::UpdateNextAttacker(this);
            return;
          }
        }
      }
      r = UFG::qColour::Blue.r;
      v9 = NextAttacker->m_pOwner.m_pPointer;
      v33 = UFG::qColour::Blue;
      if ( v9 )
      {
        mNext = (UFG::TransformNodeComponent *)v9[3].m_BoundComponentHandles.mNode.mNext;
        goto LABEL_15;
      }
    }
    mNext = 0i64;
    goto LABEL_15;
  }
}

// File Line: 1732
// RVA: 0x3581C0
void __fastcall UFG::AttackRightsComponent::FinishedAttacking(
        UFG::AttackRightsComponent *this,
        UFG::HasAttackRequestNode *attacker)
{
  __int64 m_AttackType; // r14
  __int64 v5; // rcx
  bool v6; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v7; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v8; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v9; // rax
  UFG::SimObject *v10; // rsi
  __int64 v11; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *NextAttacker; // rax
  float TimeUntilNextAttack; // xmm0_4
  UFG::SimObjectCharacter *m_pSimObject; // rax
  UFG::SimComponent *m_pPointer; // rax

  m_AttackType = attacker->m_AttackType;
  v5 = m_AttackType + 2 * (m_AttackType + 641);
  v6 = *((_QWORD *)&this->m_SafePointerList.mNode.mNext + v5) == 0i64;
  v7 = &(&this->vfptr)[v5];
  if ( !v6 )
  {
    v8 = *v7;
    v9 = v7[1];
    v8[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v9;
    v9->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v8;
    *v7 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v7;
    v7[1] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v7;
  }
  v10 = 0i64;
  v7[2] = 0i64;
  this->m_CurrentlyAttacking[m_AttackType] = 0;
  UFG::AttackRightsComponent::SortAttackSlots(this, (UFG::eAttackType)m_AttackType);
  NextAttacker = UFG::AttackRightsComponent::GetNextAttacker(this, (UFG::eAttackType)m_AttackType, v11);
  if ( NextAttacker )
  {
    TimeUntilNextAttack = UFG::AttackRightsComponent::GetTimeUntilNextAttack(
                            this,
                            attacker,
                            (UFG::HasAttackRequestNode *)NextAttacker);
    if ( !this->m_IsDowned )
      goto LABEL_8;
  }
  else if ( !this->m_IsDowned )
  {
    TimeUntilNextAttack = UFG::AttackRightsComponent::s_DefaultTimeUntilNextAttack;
LABEL_8:
    this->m_TimeUntilNextAttack[m_AttackType] = TimeUntilNextAttack;
  }
  if ( UFG::AttackRightsComponent::s_ProducerAttackRightsDebug )
  {
    m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
    if ( m_pSimObject )
    {
      if ( m_pSimObject == LocalPlayer )
      {
        m_pPointer = attacker->m_pOwner.m_pPointer;
        if ( m_pPointer )
          v10 = m_pPointer->m_pSimObject;
        UFG::UnHighlightSimObject(v10);
      }
    }
  }
}

// File Line: 1771
// RVA: 0x36D320
void __fastcall UFG::AttackRightsComponent::MakeAttackRequest(
        UFG::AttackRightsComponent *this,
        UFG::HasAttackRequestNode *attacker,
        bool *attack_type)
{
  __int64 v5; // rbx
  UFG::HasAttackRequestNode *m_pPointer; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::SimObject *v14; // rdi
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v18; // rax
  int v19; // esi
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> **p_mNext; // r14
  UFG::HasAttackRequestNode *NextAttacker; // rax
  UFG::SimComponent *v22; // rdx
  UFG::SimObject *m_pSimObject; // rdx
  UFG::HasAttackRequestNode *v24; // rbx
  UFG::SimComponent *v25; // rax
  UFG::SimObject *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_m_pAttackeeRequest; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *p_m_pSecondaryCharacterRequest; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v34; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::SimObjectCharacter *v38; // rax
  UFG::SimComponent *v39; // rax
  UFG::HighlightParams highlight_params; // [rsp+20h] [rbp-38h] BYREF

  v5 = (int)attack_type;
  if ( !(_DWORD)attack_type )
  {
    m_pPointer = this->m_pLastAttackRequest[0].m_pPointer;
    if ( m_pPointer )
      UFG::HasAttackRequestNode::ClearAttackRequest(m_pPointer);
  }
  this->m_CurrentlyAttacking[v5] = 1;
  if ( (_DWORD)v5 == 2 )
  {
    v14 = 0i64;
    v19 = 0;
    p_mNext = &this->m_FollowerAttackSlotQueue[0].mNode.mNext;
    while ( 1 )
    {
      if ( v19 != 2 )
      {
        NextAttacker = UFG::AttackRightsComponent::GetNextAttacker(this, (UFG::eAttackType)v19, (__int64)attack_type);
        if ( NextAttacker && (v22 = NextAttacker->m_pOwner.m_pPointer) != 0i64 )
          m_pSimObject = v22->m_pSimObject;
        else
          m_pSimObject = 0i64;
        v24 = (UFG::HasAttackRequestNode *)&(*p_mNext)[-4].mNext;
        attack_type = &this->m_CurrentlyAttacking[16 * v19];
        if ( v24 != (UFG::HasAttackRequestNode *)attack_type )
          break;
      }
LABEL_26:
      ++v19;
      p_mNext += 2;
      if ( v19 >= 3 )
        goto LABEL_38;
    }
    while ( 1 )
    {
      v25 = v24->m_pOwner.m_pPointer;
      v26 = v25 ? v25->m_pSimObject : 0i64;
      if ( v26 != m_pSimObject )
        break;
      v24 = (UFG::HasAttackRequestNode *)&v24->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mNext[-4].mNext;
      if ( v24 == (UFG::HasAttackRequestNode *)attack_type )
        goto LABEL_26;
    }
    UFG::HasAttackRequestNode::RequestAttack(attacker, this, v24);
    p_m_pAttackeeRequest = &v24->m_pAttackeeRequest;
    if ( v24->m_pAttackeeRequest.m_pPointer )
    {
      mPrev = p_m_pAttackeeRequest->mPrev;
      mNext = v24->m_pAttackeeRequest.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAttackeeRequest->mPrev = p_m_pAttackeeRequest;
      v24->m_pAttackeeRequest.mNext = &v24->m_pAttackeeRequest;
    }
    v24->m_pAttackeeRequest.m_pPointer = this;
    if ( this )
    {
      v30 = this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v30->mNext = p_m_pAttackeeRequest;
      p_m_pAttackeeRequest->mPrev = v30;
      v24->m_pAttackeeRequest.mNext = &this->m_SafePointerList.mNode;
      this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pAttackeeRequest;
    }
    p_m_pSecondaryCharacterRequest = &v24->m_pSecondaryCharacterRequest;
    if ( v24->m_pSecondaryCharacterRequest.m_pPointer )
    {
      v32 = p_m_pSecondaryCharacterRequest->mPrev;
      v33 = v24->m_pSecondaryCharacterRequest.mNext;
      v32->mNext = v33;
      v33->mPrev = v32;
      p_m_pSecondaryCharacterRequest->mPrev = p_m_pSecondaryCharacterRequest;
      v24->m_pSecondaryCharacterRequest.mNext = &v24->m_pSecondaryCharacterRequest;
    }
    v24->m_pSecondaryCharacterRequest.m_pPointer = 0i64;
    v34 = &this->m_pLastAttackRequest[2];
    v24->m_AttackeeRequestTime = UFG::Metrics::msInstance.mSimTime_Temp;
    if ( this->m_pLastAttackRequest[2].m_pPointer )
    {
      v35 = v34->mPrev;
      v36 = this->m_pLastAttackRequest[2].mNext;
      v35->mNext = v36;
      v36->mPrev = v35;
      v34->mPrev = v34;
      this->m_pLastAttackRequest[2].mNext = &this->m_pLastAttackRequest[2];
    }
    this->m_pLastAttackRequest[2].m_pPointer = attacker;
    if ( attacker )
    {
      v37 = attacker->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
      v37->mNext = v34;
      v34->mPrev = v37;
      this->m_pLastAttackRequest[2].mNext = &attacker->m_SafePointerList.mNode;
      attacker->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = v34;
    }
  }
  else
  {
    v7 = &attacker->m_pAttackeeRequest;
    if ( attacker->m_pAttackeeRequest.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = attacker->m_pAttackeeRequest.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = v7;
      attacker->m_pAttackeeRequest.mNext = &attacker->m_pAttackeeRequest;
    }
    attacker->m_pAttackeeRequest.m_pPointer = this;
    if ( this )
    {
      v10 = this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v10->mNext = v7;
      v7->mPrev = v10;
      attacker->m_pAttackeeRequest.mNext = &this->m_SafePointerList.mNode;
      this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v7;
    }
    v11 = &attacker->m_pSecondaryCharacterRequest;
    if ( attacker->m_pSecondaryCharacterRequest.m_pPointer )
    {
      v12 = v11->mPrev;
      v13 = attacker->m_pSecondaryCharacterRequest.mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v11->mPrev = v11;
      attacker->m_pSecondaryCharacterRequest.mNext = &attacker->m_pSecondaryCharacterRequest;
    }
    v14 = 0i64;
    attacker->m_pSecondaryCharacterRequest.m_pPointer = 0i64;
    v15 = &this->m_pLastAttackRequest[v5];
    attacker->m_AttackeeRequestTime = UFG::Metrics::msInstance.mSimTime_Temp;
    if ( v15->m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v15->mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = v15;
      v15->mNext = v15;
    }
    v15->m_pPointer = attacker;
    v18 = attacker->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
    v18->mNext = v15;
    v15->mPrev = v18;
    v15->mNext = &attacker->m_SafePointerList.mNode;
    attacker->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = v15;
  }
LABEL_38:
  if ( UFG::AttackRightsComponent::s_ProducerAttackRightsDebug )
  {
    v38 = (UFG::SimObjectCharacter *)this->m_pSimObject;
    if ( v38 )
    {
      if ( v38 == LocalPlayer )
      {
        v39 = attacker->m_pOwner.m_pPointer;
        highlight_params.mIsDepthEnabled = 0;
        highlight_params.mColour = UFG::qColour::White;
        LODWORD(highlight_params.mOutlineStrength) = (_DWORD)FLOAT_1_0;
        highlight_params.mXrayStrength = 0.0;
        if ( v39 )
          v14 = v39->m_pSimObject;
        UFG::HighlightSimObject(v14, &highlight_params);
      }
    }
  }
}

// File Line: 1864
// RVA: 0x35D600
UFG::HasAttackRequestNode *__fastcall UFG::AttackRightsComponent::GetCurrentAttacker(
        UFG::AttackRightsComponent *this,
        UFG::eAttackType attack_type)
{
  __int64 v2; // r9
  int v3; // r11d
  char *v4; // rbx
  __int64 v5; // rdx
  UFG::HasAttackRequestNode *result; // rax

  v2 = attack_type;
  v3 = 0;
  v4 = (char *)this + 2 * attack_type;
LABEL_2:
  v5 = 0i64;
  while ( 1 )
  {
    if ( v4[v5 + 0x2464] == 1 || this->m_OverrideAllowedToUseAttackSlotListThisFrame[v2][v5] )
    {
      result = this->m_pAttackSlot[v2][v5][0].m_pPointer;
      if ( result )
      {
        if ( result->m_Score >= 0.0 || v3 > 0 )
          return result;
      }
    }
    if ( ++v5 >= 2 )
    {
      if ( ++v3 < 2 )
        goto LABEL_2;
      return 0i64;
    }
  }
}

// File Line: 1892
// RVA: 0x360DB0
UFG::HasAttackRequestNode *__fastcall UFG::AttackRightsComponent::GetNextAttacker(
        UFG::AttackRightsComponent *this,
        UFG::eAttackType attack_type,
        __int64 a3)
{
  __int64 v3; // rsi
  UFG::HasAttackRequestNode *m_pPointer; // rbx
  UFG::HasAttackRequestNode **p_m_pPointer; // r15
  UFG::SimComponent *v7; // rax
  unsigned int v8; // ebp
  CanAttackConditionGroup *v9; // rcx
  ActionContext *m_pActionContextCopy; // rdx
  UFG::SimComponent *mPrev; // rax
  UFG::HasAttackRequestNode *NextAttacker; // rax
  UFG::HasAttackRequestNode *v14; // r9
  __int64 v15; // r8
  bool v16; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v17; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v18; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v19; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::AttackSlotInfo next_attack_baton; // [rsp+40h] [rbp+8h] BYREF

  v3 = attack_type;
  m_pPointer = this->m_pCachedNextAttacker[attack_type].m_pPointer;
  p_m_pPointer = &this->m_pCachedNextAttacker[attack_type].m_pPointer;
  if ( m_pPointer )
  {
    if ( attack_type == eATTACK_TYPE_MELEE
      && UFG::BattleManager::s_pInstance->m_CurrentBattleType == eBATTLE_TYPE_NORMAL )
    {
      v7 = m_pPointer->m_pOwner.m_pPointer;
      if ( v7 )
      {
        if ( v7[3].m_SafePointerList.mNode.mPrev )
        {
          if ( UFG::Metrics::msInstance.mSimFrameCount )
            v8 = UFG::Metrics::msInstance.mSimFrameCount - 1;
          else
            v8 = -1;
          v9 = m_pPointer->m_pCanAttackConditions.m_pPointer;
          LOBYTE(a3) = 0;
          if ( v9 )
          {
            m_pActionContextCopy = m_pPointer->m_pActionContextCopy;
            if ( m_pActionContextCopy )
              LOBYTE(a3) = ((__int64 (__fastcall *)(CanAttackConditionGroup *, ActionContext *, __int64))v9->ConditionGroup::Condition::Expression::IMemberMap::vfptr[1].FindWithOldPath)(
                             v9,
                             m_pActionContextCopy,
                             a3);
          }
          mPrev = m_pPointer->m_pOwner.m_pPointer;
          if ( mPrev )
            mPrev = (UFG::SimComponent *)mPrev[3].m_SafePointerList.mNode.mPrev;
          if ( (_BYTE)a3
            && (BYTE1(mPrev[32].m_BoundComponentHandles.mNode.mPrev) & 0x10) != 0
            && m_pPointer->m_LastFramePolled >= v8 )
          {
            return m_pPointer;
          }
        }
      }
    }
  }
  NextAttacker = UFG::AttackRightsComponent::FindNextAttacker(this, (UFG::eAttackType)v3, &next_attack_baton);
  v14 = NextAttacker;
  if ( !NextAttacker )
    return *p_m_pPointer;
  v15 = v3 + 2 * v3 + 1171;
  v16 = *((_QWORD *)&this->m_SafePointerList.mNode.mNext + v15) == 0i64;
  v17 = &(&this->vfptr)[v15];
  if ( !v16 )
  {
    v18 = *v17;
    v19 = v17[1];
    v18[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v19;
    v19->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v18;
    *v17 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v17;
    v17[1] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v17;
  }
  v17[2] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)NextAttacker;
  p_m_SafePointerList = &NextAttacker->m_SafePointerList;
  v21 = NextAttacker->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
  v21->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v17;
  *v17 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v21;
  v17[1] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)p_m_SafePointerList;
  p_m_SafePointerList->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v17;
  return v14;
}

// File Line: 1935
// RVA: 0x357720
UFG::HasAttackRequestNode *__fastcall UFG::AttackRightsComponent::FindNextAttacker(
        UFG::AttackRightsComponent *this,
        UFG::eAttackType attack_type,
        UFG::AttackSlotInfo *next_attack_baton)
{
  int v3; // r9d
  UFG::eAttackSlotList v5; // r10d
  __int64 v6; // rcx
  __int64 v7; // r8
  UFG::HasAttackRequestNode *v8; // r15
  UFG::eAttackSlotList v9; // r12d
  bool *i; // rax
  int v11; // esi
  int v12; // r14d
  __int64 v13; // rcx
  UFG::HasAttackRequestNode *m_pPointer; // rbx
  int v15; // ebp
  UFG::SimComponent *v16; // rax
  unsigned int v17; // edi
  CanAttackConditionGroup *v18; // rcx
  char v19; // al
  UFG::SimComponent *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  bool v22; // zf
  int v24; // [rsp+20h] [rbp-68h]
  __int64 v25; // [rsp+28h] [rbp-60h]
  __int64 v26; // [rsp+30h] [rbp-58h]
  __int64 v27; // [rsp+38h] [rbp-50h]
  UFG::eAttackSlotList v29; // [rsp+A8h] [rbp+20h]

  v3 = -1;
  v5 = eATTACK_SLOT_LIST_ON_SCREEN;
  v6 = 0i64;
  next_attack_baton->m_AttackSlotList = eATTACK_SLOT_LIST_NONE;
  next_attack_baton->m_AttackSlot = -1;
  v7 = attack_type;
  v8 = 0i64;
  v9 = eATTACK_SLOT_LIST_ON_SCREEN;
  v24 = -1;
  v29 = eATTACK_SLOT_LIST_ON_SCREEN;
  v26 = 0i64;
  v27 = attack_type;
  for ( i = this->m_AllowedToUseAttackSlotList[attack_type]; ; i = this->m_AllowedToUseAttackSlotList[v7] )
  {
    if ( i[v6] || this->m_OverrideAllowedToUseAttackSlotListThisFrame[v7][v6] )
    {
      v11 = this->m_NextAttackBaton[v7][v6];
      v12 = v11 <= 0 ? this->m_NumAttackSlots[v7] - 1 : v11 - 1;
      if ( v12 != -1 )
      {
        v13 = (v6 + 2 * v7) << 6;
        v25 = v13;
        while ( 1 )
        {
          m_pPointer = this->m_pAttackSlot[0][0][v13 + v11].m_pPointer;
          v15 = (v11 + 1) % this->m_NumAttackSlots[v7];
          if ( m_pPointer )
          {
            v16 = m_pPointer->m_pOwner.m_pPointer;
            if ( v16 )
            {
              if ( v16[3].m_SafePointerList.mNode.mPrev )
              {
                if ( UFG::Metrics::msInstance.mSimFrameCount )
                  v17 = UFG::Metrics::msInstance.mSimFrameCount - 1;
                else
                  v17 = -1;
                v18 = m_pPointer->m_pCanAttackConditions.m_pPointer;
                v19 = 0;
                if ( v18 && m_pPointer->m_pActionContextCopy )
                {
                  v19 = ((__int64 (__fastcall *)(CanAttackConditionGroup *))v18->ConditionGroup::Condition::Expression::IMemberMap::vfptr[1].FindWithOldPath)(v18);
                  v7 = v27;
                  v3 = v24;
                  v5 = v29;
                }
                v20 = m_pPointer->m_pOwner.m_pPointer;
                if ( v20 )
                  mPrev = v20[3].m_SafePointerList.mNode.mPrev;
                else
                  mPrev = 0i64;
                if ( v19 && (BYTE1(mPrev[131].mPrev) & 0x10) != 0 && m_pPointer->m_LastFramePolled >= v17 )
                {
                  if ( m_pPointer->m_Score >= 0.0 )
                  {
                    next_attack_baton->m_AttackSlotList = v9;
                    next_attack_baton->m_AttackSlot = v15;
                    return m_pPointer;
                  }
                  v13 = v25;
                  if ( !v8 )
                  {
                    v5 = v9;
                    v29 = v9;
                    v3 = v15;
                    v24 = v15;
                    v8 = m_pPointer;
                  }
                }
                else
                {
                  v13 = v25;
                }
              }
            }
          }
          v22 = v11 == v12;
          v11 = v15;
          if ( v22 )
          {
            v6 = v26;
            break;
          }
        }
      }
    }
    ++v6;
    ++v9;
    v26 = v6;
    if ( v9 >= NUM_ATTACK_SLOT_LISTS )
      break;
  }
  if ( !v8 )
    return 0i64;
  next_attack_baton->m_AttackSlotList = v5;
  next_attack_baton->m_AttackSlot = v3;
  return v8;
} !v8 )
    return 0i64;
  next_attack_baton->m_AttackSlotLi

// File Line: 2002
// RVA: 0x362DB0
float __fastcall UFG::AttackRightsComponent::GetTimeUntilInitialAttack(
        UFG::AttackRightsComponent *this,
        UFG::HasAttackRequestNode *attacker)
{
  UFG::SimComponent *m_pPointer; // rax
  float InitialAttackTimeMax; // xmm6_4
  UFG::AIScriptInterfaceComponent *mPrev; // rcx
  float InitialAttackTimeMin; // xmm7_4
  UFG::SimComponent *v7; // rax
  UFG::AIScriptInterfaceComponent *v8; // rcx
  float result; // xmm0_4

  m_pPointer = attacker->m_pOwner.m_pPointer;
  InitialAttackTimeMax = 0.0;
  if ( m_pPointer && (mPrev = (UFG::AIScriptInterfaceComponent *)m_pPointer[3].m_SafePointerList.mNode.mPrev) != 0i64 )
    InitialAttackTimeMin = UFG::AIScriptInterfaceComponent::GetInitialAttackTimeMin(
                             mPrev,
                             attacker->m_AttackType,
                             attacker->m_TargetType,
                             attacker->m_InCoverType);
  else
    InitialAttackTimeMin = 0.0;
  v7 = attacker->m_pOwner.m_pPointer;
  if ( v7 )
  {
    v8 = (UFG::AIScriptInterfaceComponent *)v7[3].m_SafePointerList.mNode.mPrev;
    if ( v8 )
      InitialAttackTimeMax = UFG::AIScriptInterfaceComponent::GetInitialAttackTimeMax(
                               v8,
                               attacker->m_AttackType,
                               attacker->m_TargetType,
                               attacker->m_InCoverType);
  }
  result = InitialAttackTimeMax;
  if ( InitialAttackTimeMax > InitialAttackTimeMin )
  {
    result = UFG::qRandom(InitialAttackTimeMax - InitialAttackTimeMin, (unsigned int *)&UFG::qDefaultSeed)
           + InitialAttackTimeMin;
    if ( result <= InitialAttackTimeMin )
      result = InitialAttackTimeMin;
    if ( result >= InitialAttackTimeMax )
      return InitialAttackTimeMax;
  }
  return result;
}

// File Line: 2014
// RVA: 0x362E60
double __fastcall UFG::AttackRightsComponent::GetTimeUntilNextAttack(
        UFG::AttackRightsComponent *this,
        UFG::HasAttackRequestNode *prev_attacker,
        UFG::HasAttackRequestNode *next_attacker)
{
  double v3; // xmm0_8
  UFG::SimComponent *m_pPointer; // rax
  UFG::AIScriptInterfaceComponent *mPrev; // rcx
  double v8; // xmm6_8
  UFG::SimComponent *v9; // rax
  UFG::AIScriptInterfaceComponent *v10; // rcx
  float AttackTimeMax; // xmm7_4
  UFG::SimComponent *v12; // rax
  UFG::AIScriptInterfaceComponent *v13; // rcx
  UFG::SimComponent *v14; // rax
  UFG::AIScriptInterfaceComponent *v15; // rcx
  UFG::SimComponent *m_pSimComponent; // rax
  double result; // xmm0_8

  m_pPointer = next_attacker->m_pOwner.m_pPointer;
  if ( m_pPointer && (mPrev = (UFG::AIScriptInterfaceComponent *)m_pPointer[3].m_SafePointerList.mNode.mPrev) != 0i64 )
  {
    *(float *)&v3 = UFG::AIScriptInterfaceComponent::GetAttackTimeMin(
                      mPrev,
                      next_attacker->m_AttackType,
                      next_attacker->m_TargetType,
                      next_attacker->m_InCoverType);
    v8 = v3;
  }
  else
  {
    v8 = 0.0;
  }
  v9 = next_attacker->m_pOwner.m_pPointer;
  if ( v9 && (v10 = (UFG::AIScriptInterfaceComponent *)v9[3].m_SafePointerList.mNode.mPrev) != 0i64 )
    AttackTimeMax = UFG::AIScriptInterfaceComponent::GetAttackTimeMax(
                      v10,
                      next_attacker->m_AttackType,
                      next_attacker->m_TargetType,
                      next_attacker->m_InCoverType);
  else
    AttackTimeMax = 0.0;
  if ( UFG::IsDowned(
         (UFG::ActionTreeComponent *)this->m_pActionTreeComponent.m_pSimComponent,
         (UFG::HealthComponent *)this->m_pHealthComponent.m_pSimComponent) )
  {
    v12 = next_attacker->m_pOwner.m_pPointer;
    if ( v12 && (v13 = (UFG::AIScriptInterfaceComponent *)v12[3].m_SafePointerList.mNode.mPrev) != 0i64 )
    {
      *(float *)&v3 = UFG::AIScriptInterfaceComponent::GetAttackTimeMinDowned(
                        v13,
                        next_attacker->m_AttackType,
                        next_attacker->m_TargetType,
                        next_attacker->m_InCoverType);
      v8 = v3;
    }
    else
    {
      v8 = 0.0;
    }
    v14 = next_attacker->m_pOwner.m_pPointer;
    if ( v14 && (v15 = (UFG::AIScriptInterfaceComponent *)v14[3].m_SafePointerList.mNode.mPrev) != 0i64 )
      AttackTimeMax = UFG::AIScriptInterfaceComponent::GetAttackTimeMaxDowned(
                        v15,
                        next_attacker->m_AttackType,
                        next_attacker->m_TargetType,
                        next_attacker->m_InCoverType);
    else
      AttackTimeMax = 0.0;
  }
  m_pSimComponent = this->m_pHitReactionComponent.m_pSimComponent;
  if ( !m_pSimComponent )
    return v8;
  result = v8;
  if ( *(float *)&m_pSimComponent[1].m_TypeUID < 3.0 )
    *(float *)&result = UFG::GetRandomNumberInRange(*(float *)&v8, AttackTimeMax);
  return result;
}

// File Line: 2062
// RVA: 0x3971E0
void __fastcall UFG::AttackRightsComponent::UpdateNextAttacker(UFG::AttackRightsComponent *this)
{
  __int64 v2; // r8
  UFG::HasAttackRequestNode *NextAttacker; // rsi
  UFG::HasAttackRequestNode *v4; // rax
  UFG::HasAttackRequestNode *m_pPointer; // rbx
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::SimComponent *v15; // rax
  unsigned int v16; // ebp
  CanAttackConditionGroup *v17; // rcx
  char v18; // al
  UFG::SimComponent *v19; // rcx
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *m_pCachedNextAttacker; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *p_m_pNextAttacker; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::AttackSlotInfo next_attack_baton; // [rsp+30h] [rbp+8h] BYREF

  if ( UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) >= 0.5 )
  {
    NextAttacker = UFG::AttackRightsComponent::FindNextAttacker(this, eATTACK_TYPE_RANGED, &next_attack_baton);
    if ( NextAttacker )
    {
      v11 = &this->m_pCachedNextAttacker[1];
      if ( this->m_pCachedNextAttacker[1].m_pPointer )
      {
        mPrev = v11->mPrev;
        mNext = this->m_pCachedNextAttacker[1].mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v11->mPrev = v11;
        this->m_pCachedNextAttacker[1].mNext = &this->m_pCachedNextAttacker[1];
      }
      this->m_pCachedNextAttacker[1].m_pPointer = NextAttacker;
      v14 = NextAttacker->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
      v14->mNext = v11;
      v11->mPrev = v14;
      this->m_pCachedNextAttacker[1].mNext = &NextAttacker->m_SafePointerList.mNode;
      NextAttacker->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = v11;
    }
    else
    {
      NextAttacker = this->m_pCachedNextAttacker[1].m_pPointer;
    }
    m_pPointer = this->m_pCachedNextAttacker[0].m_pPointer;
    if ( !m_pPointer )
      goto LABEL_27;
    if ( UFG::BattleManager::s_pInstance->m_CurrentBattleType )
      goto LABEL_27;
    v15 = m_pPointer->m_pOwner.m_pPointer;
    if ( !v15 || !v15[3].m_SafePointerList.mNode.mPrev )
      goto LABEL_27;
    if ( UFG::Metrics::msInstance.mSimFrameCount )
      v16 = UFG::Metrics::msInstance.mSimFrameCount - 1;
    else
      v16 = -1;
    v17 = m_pPointer->m_pCanAttackConditions.m_pPointer;
    v18 = 0;
    if ( v17 && m_pPointer->m_pActionContextCopy )
      v18 = ((__int64 (__fastcall *)(CanAttackConditionGroup *))v17->ConditionGroup::Condition::Expression::IMemberMap::vfptr[1].FindWithOldPath)(v17);
    v19 = m_pPointer->m_pOwner.m_pPointer;
    if ( v19 )
      v19 = (UFG::SimComponent *)v19[3].m_SafePointerList.mNode.mPrev;
    if ( !v18 || (BYTE1(v19[32].m_BoundComponentHandles.mNode.mPrev) & 0x10) == 0 || m_pPointer->m_LastFramePolled < v16 )
    {
LABEL_27:
      m_pPointer = UFG::AttackRightsComponent::FindNextAttacker(this, eATTACK_TYPE_MELEE, &next_attack_baton);
      if ( m_pPointer )
      {
        m_pCachedNextAttacker = this->m_pCachedNextAttacker;
        if ( this->m_pCachedNextAttacker[0].m_pPointer )
        {
          v21 = m_pCachedNextAttacker->mPrev;
          v22 = this->m_pCachedNextAttacker[0].mNext;
          v21->mNext = v22;
          v22->mPrev = v21;
          m_pCachedNextAttacker->mPrev = m_pCachedNextAttacker;
          this->m_pCachedNextAttacker[0].mNext = this->m_pCachedNextAttacker;
        }
        this->m_pCachedNextAttacker[0].m_pPointer = m_pPointer;
        v23 = m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
        v23->mNext = m_pCachedNextAttacker;
        m_pCachedNextAttacker->mPrev = v23;
        this->m_pCachedNextAttacker[0].mNext = &m_pPointer->m_SafePointerList.mNode;
        m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = m_pCachedNextAttacker;
      }
      else
      {
        m_pPointer = this->m_pCachedNextAttacker[0].m_pPointer;
      }
    }
  }
  else
  {
    NextAttacker = UFG::AttackRightsComponent::GetNextAttacker(this, eATTACK_TYPE_MELEE, v2);
    v4 = UFG::AttackRightsComponent::FindNextAttacker(this, eATTACK_TYPE_RANGED, &next_attack_baton);
    m_pPointer = v4;
    if ( v4 )
    {
      v6 = &this->m_pCachedNextAttacker[1];
      if ( this->m_pCachedNextAttacker[1].m_pPointer )
      {
        v7 = v6->mPrev;
        v8 = this->m_pCachedNextAttacker[1].mNext;
        v7->mNext = v8;
        v8->mPrev = v7;
        v6->mPrev = v6;
        this->m_pCachedNextAttacker[1].mNext = &this->m_pCachedNextAttacker[1];
      }
      this->m_pCachedNextAttacker[1].m_pPointer = v4;
      p_mNode = &v4->m_SafePointerList.mNode;
      v10 = v4->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
      v10->mNext = v6;
      v6->mPrev = v10;
      this->m_pCachedNextAttacker[1].mNext = p_mNode;
      p_mNode->mPrev = v6;
    }
    else
    {
      m_pPointer = this->m_pCachedNextAttacker[1].m_pPointer;
    }
  }
  p_m_pNextAttacker = &this->m_pNextAttacker;
  if ( NextAttacker )
    m_pPointer = NextAttacker;
  if ( this->m_pNextAttacker.m_pPointer )
  {
    v25 = p_m_pNextAttacker->mPrev;
    v26 = this->m_pNextAttacker.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    p_m_pNextAttacker->mPrev = p_m_pNextAttacker;
    this->m_pNextAttacker.mNext = &this->m_pNextAttacker;
  }
  this->m_pNextAttacker.m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v27 = m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
    v27->mNext = p_m_pNextAttacker;
    p_m_pNextAttacker->mPrev = v27;
    this->m_pNextAttacker.mNext = &m_pPointer->m_SafePointerList.mNode;
    m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = p_m_pNextAttacker;
  }
}

// File Line: 2111
// RVA: 0x34F710
void __fastcall UFG::AttackRightsComponent::ClearPreviousBestAttacker(
        UFG::AttackRightsComponent *this,
        int attack_type)
{
  __int64 v2; // rdi
  float mSimTime_Temp; // xmm8_4
  __int64 v5; // r8
  bool v6; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v7; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v8; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v9; // rax
  float m_MaxTimeBetweenAttackerSwitch; // xmm6_4
  float m_MinTimeBetweenAttackerSwitch; // xmm7_4
  float v12; // xmm0_4

  v2 = attack_type;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  v5 = attack_type + 2 * (attack_type + 590i64);
  v6 = *((_QWORD *)&this->m_SafePointerList.mNode.mNext + v5) == 0i64;
  v7 = &(&this->vfptr)[v5];
  if ( !v6 )
  {
    v8 = *v7;
    v9 = v7[1];
    v8[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v9;
    v9->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v8;
    *v7 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v7;
    v7[1] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v7;
  }
  v7[2] = 0i64;
  m_MaxTimeBetweenAttackerSwitch = this->m_MaxTimeBetweenAttackerSwitch;
  m_MinTimeBetweenAttackerSwitch = this->m_MinTimeBetweenAttackerSwitch;
  v12 = m_MaxTimeBetweenAttackerSwitch;
  if ( m_MaxTimeBetweenAttackerSwitch > m_MinTimeBetweenAttackerSwitch )
  {
    v12 = UFG::qRandom(
            m_MaxTimeBetweenAttackerSwitch - m_MinTimeBetweenAttackerSwitch,
            (unsigned int *)&UFG::qDefaultSeed)
        + m_MinTimeBetweenAttackerSwitch;
    if ( v12 <= m_MinTimeBetweenAttackerSwitch )
      v12 = m_MinTimeBetweenAttackerSwitch;
    if ( v12 >= m_MaxTimeBetweenAttackerSwitch )
      v12 = m_MaxTimeBetweenAttackerSwitch;
  }
  this->m_NextTimeToUpdatePreviousBestAttacker[v2] = v12 + mSimTime_Temp;
}

// File Line: 2137
// RVA: 0x353BA0
void __fastcall UFG::AttackRightsComponent::DrawDebugInfo(UFG::AttackRightsComponent *this, Render::View *view)
{
  Render::DebugDrawManager *Context; // rax
  __int64 v5; // r15
  UFG::HasAttackRequestNode **v6; // r14
  __int64 v7; // r12
  UFG::HasAttackRequestNode *v8; // rsi
  UFG::SimComponent *m_pPointer; // rbx
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  UFG::qVector4 v14; // xmm2
  __int64 v15; // rsi
  __int64 v16; // rbx
  UFG::qVector4 v17; // xmm6
  __int64 v18; // r15
  UFG::qVector4 v19; // xmm7
  UFG::qVector4 v20; // xmm8
  UFG::qVector4 v21; // xmm9
  float r; // xmm0_4
  float g; // xmm1_4
  __int64 v24; // rdi
  float b; // xmm0_4
  float a; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  UFG::qColour v32; // [rsp+30h] [rbp-B8h]
  UFG::qColour v33; // [rsp+40h] [rbp-A8h]
  UFG::qVector3 v34; // [rsp+50h] [rbp-98h] BYREF
  float pos; // [rsp+60h] [rbp-88h] BYREF
  float pos_4; // [rsp+64h] [rbp-84h]
  UFG::qColour pos_8; // [rsp+68h] [rbp-80h] BYREF
  int info_8; // [rsp+78h] [rbp-70h]
  int info_12; // [rsp+7Ch] [rbp-6Ch]
  __int16 info_16; // [rsp+80h] [rbp-68h]
  char info_18; // [rsp+82h] [rbp-66h]
  __int64 info_24; // [rsp+88h] [rbp-60h]
  UFG::qColour info_32[3]; // [rsp+90h] [rbp-58h] BYREF
  UFG::qMatrix44 v44; // [rsp+C8h] [rbp-20h] BYREF
  UFG::DrawInfo v45; // [rsp+108h] [rbp+20h] BYREF
  UFG::qMatrix44 xform; // [rsp+148h] [rbp+60h] BYREF
  __int64 v47; // [rsp+208h] [rbp+120h]
  __int64 retaddr; // [rsp+218h] [rbp+130h]
  Render::DebugDrawContext *v49; // [rsp+220h] [rbp+138h]

  if ( this->m_DebugDrawEnabled )
  {
    retaddr = 2i64;
    Context = Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    v5 = UFG::AttackRightsComponent::s_AttackTypeToDebug;
    v49 = (Render::DebugDrawContext *)Context;
    info_32[0] = UFG::qColour::Red;
    info_32[1] = UFG::qColour::Green;
    info_32[2] = UFG::qColour::Blue;
    v6 = &this->m_pAttackSlot[0][0][0].m_pPointer + 384 * UFG::AttackRightsComponent::s_AttackTypeToDebug;
    do
    {
      v7 = 64i64;
      do
      {
        v8 = *v6;
        if ( *v6 )
        {
          m_pPointer = v8->m_pOwner.m_pPointer;
          if ( m_pPointer )
            m_pPointer = (UFG::SimComponent *)m_pPointer[3].m_BoundComponentHandles.mNode.mNext;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
          Render::DebugDrawContext::DrawPoint(
            v49,
            (UFG::qVector3 *)&m_pPointer[2].m_BoundComponentHandles,
            &info_32[v5],
            &UFG::qMatrix44::msIdentity,
            0i64);
          UFG::HasAttackRequestComponent::DrawDebugString(
            (UFG::HasAttackRequestComponent *)v8->m_pOwner.m_pPointer,
            view);
          if ( UFG::AttackRightsComponent::s_DebugDrawOnScreenTest )
          {
            v10 = 0.0;
            v11 = 0.0;
            if ( m_pPointer )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
              v12 = *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev;
              v13 = *((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + 1);
              v10 = UFG::AttackRightsComponent::s_OnScreenTestFootSphereRadius;
              v11 = UFG::AttackRightsComponent::s_OnScreenTestHeadSphereRadius;
              pos_8.r = *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mNext;
              pos = v12;
              pos_4 = v13;
              v34.z = pos_8.r + UFG::AttackRightsComponent::s_OnScreenTestHeadHeight;
              v34.x = v12;
              v34.y = v13;
            }
            v32 = UFG::qColour::Red;
            v33 = UFG::qColour::Red;
            if ( IntersectSphereFrustum(UFG::AttackRightsComponent::s_FrustumPlanes, (UFG::qVector3 *)&pos, v10) != 2 )
              v32 = UFG::qColour::Green;
            if ( IntersectSphereFrustum(UFG::AttackRightsComponent::s_FrustumPlanes, &v34, v11) != 2 )
              v33 = UFG::qColour::Green;
            v14 = 0i64;
            pos_8 = v32;
            v45.mScale = v11 * 2.0;
            info_8 = LODWORD(v32.b);
            v45.mColour1 = v33;
            v45.mColour2 = v33;
            v14.x = (float)1;
            xform.v0 = v14;
            v44.v0 = v14;
            xform.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v14, (__m128)v14, 81);
            xform.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v14, (__m128)v14, 69);
            info_12 = 662883558;
            info_16 = 257;
            info_18 = 0;
            info_24 = 0i64;
            v44.v2 = xform.v2;
            v44.v1 = xform.v1;
            v45.mAlphaBlend = AlphaState_none;
            *(_WORD *)&v45.mDepthBuffer = 257;
            v45.mDepthBias = 0;
            v45.mPreDrawCallback = 0i64;
            xform.v3.w = 1.0;
            v44.v3.w = 1.0;
            xform.v3.x = pos;
            xform.v3.y = pos_4;
            xform.v3.z = v32.r;
            v44.v3.x = v34.x;
            v44.v3.y = v34.y;
            v44.v3.z = v34.z;
            Render::View::DrawSphere(view, &xform, (UFG::DrawInfo *)&pos_8.b);
            Render::View::DrawSphere(view, &v44, &v45);
          }
        }
        v6 += 3;
        --v7;
      }
      while ( v7 );
      --retaddr;
    }
    while ( retaddr );
    v15 = v47 + 16 * (v5 + 598);
    v16 = *(_QWORD *)(v47 + 16 * (v5 + 601)) - 40i64;
    if ( v16 != v15 )
    {
      v17 = 0i64;
      v17.x = (float)1;
      v18 = v5;
      v19 = (UFG::qVector4)_mm_shuffle_ps((__m128)v17, (__m128)v17, 81);
      v20 = (UFG::qVector4)_mm_shuffle_ps((__m128)v17, (__m128)v17, 69);
      v21 = (UFG::qVector4)_mm_shuffle_ps((__m128)v17, (__m128)v17, 21);
      do
      {
        r = info_32[v18].r;
        g = info_32[v18].g;
        v24 = *(_QWORD *)(v16 + 216);
        info_8 = 1048576000;
        info_12 = 662883558;
        info_16 = 257;
        *(_QWORD *)&pos_8.b = __PAIR64__(LODWORD(g), LODWORD(r));
        b = info_32[v18].b;
        info_18 = 0;
        info_24 = 0i64;
        a = info_32[v18].a;
        info_8 = LODWORD(b);
        v27 = info_32[v18].r;
        info_12 = LODWORD(a);
        *(_QWORD *)&pos_8.r = __PAIR64__(LODWORD(info_32[v18].g), LODWORD(v27));
        v28 = info_32[v18].a;
        pos_8.b = info_32[v18].b;
        pos_8.a = v28;
        v44.v0 = v17;
        v44.v1 = v19;
        v44.v2 = v20;
        v44.v3 = v21;
        if ( v24 )
          v24 = *(_QWORD *)(v24 + 248);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v24);
        v29 = *(float *)(v24 + 180);
        v30 = *(float *)(v24 + 184);
        v31 = *(float *)(v24 + 176);
        v44.v3.w = 1.0;
        v44.v3.x = v31;
        v44.v3.y = v29;
        v44.v3.z = v30;
        Render::View::DrawSphere(view, &v44, (UFG::DrawInfo *)&pos_8.b);
        v16 = *(_QWORD *)(v16 + 48) - 40i64;
      }
      while ( v16 != v15 );
    }
    if ( UFG::AttackRightsComponent::s_DebugDrawOnScreenTest )
      Render::View::DrawFrustum(view, UFG::AttackRightsComponent::s_FrustumPlanes, &UFG::qColour::Red);
  }
}

