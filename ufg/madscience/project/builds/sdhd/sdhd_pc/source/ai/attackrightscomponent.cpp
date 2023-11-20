// File Line: 79
// RVA: 0x14AEAA0
__int64 dynamic_initializer_for__UFG::AttackRightsComponent::s_AttackRightsComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AttackRightsComponent::s_AttackRightsComponentList__);
}

// File Line: 80
// RVA: 0x363470
signed __int64 __fastcall UFG::AttackRightsComponent::GetTypeSize(UFG::AttackRightsComponent *this)
{
  return 10368i64;
}

// File Line: 91
// RVA: 0x32C900
void __fastcall UFG::AttackRightsComponent::AttackRightsComponent(UFG::AttackRightsComponent *this, unsigned int name_uid, UFG::qPropertySet *properties)
{
  UFG::qPropertySet *v3; // rdi
  UFG::AttackRightsComponent *v4; // rsi
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *v5; // rbx
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *v6; // rax
  signed int v7; // eax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v8; // [rsp+78h] [rbp+20h]

  v3 = properties;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AttackRightsComponent::`vftable;
  `eh vector constructor iterator(
    v4->m_pAttackSlot,
    0x18ui64,
    384,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  `eh vector constructor iterator(
    v4->m_pCachedNextAttacker,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  `eh vector constructor iterator(
    v4->m_pPreviousBestAttacker,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  `eh vector constructor iterator(
    v4->m_AttackSlotQueue,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  `eh vector constructor iterator(
    v4->m_FollowerAttackSlotQueue,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0>::RebindingComponentHandle<UFG::FormationManagerComponent,0>(&v4->m_pFormationManagerComponent);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v4->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::RebindingComponentHandle<UFG::AIEntityComponent,0>(&v4->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&v4->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>(&v4->m_pCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&v4->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::RebindingComponentHandle<UFG::HitReactionComponent,0>(&v4->m_pHitReactionComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&v4->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>(&v4->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&v4->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>(&v4->m_pCharacterOccupantComponent);
  v8 = &v4->m_pNextAttacker;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v4->m_pNextAttacker.m_pPointer = 0i64;
  `eh vector constructor iterator(
    v4->m_pLastAttackRequest,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  UFG::qString::qString(&v4->m_DebugText);
  v6 = UFG::AttackRightsComponent::s_AttackRightsComponentList.mNode.mPrev;
  UFG::AttackRightsComponent::s_AttackRightsComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *)&UFG::AttackRightsComponent::s_AttackRightsComponentList;
  UFG::AttackRightsComponent::s_AttackRightsComponentList.mNode.mPrev = (UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::AttackRightsComponent::_AttackRightsComponentTypeUID,
    "AttackRightsComponent");
  *(_QWORD *)v4->m_NumAttackSlots = 274877907008i64;
  v4->m_NumAttackSlots[2] = 64;
  v4->m_MinTimeBetweenAttackerSwitch = -1.0;
  v4->m_MaxTimeBetweenAttackerSwitch = -1.0;
  UFG::AttackRightsComponent::ClearAttackSlots(v4);
  v4->m_DebugDrawEnabled = 0;
  v7 = initted_0;
  if ( !initted_0 )
    v7 = 1;
  initted_0 = v7;
  UFG::AttackRightsComponent::InitFromProperties(v4, v3);
}

// File Line: 127
// RVA: 0x335370
void __fastcall UFG::AttackRightsComponent::~AttackRightsComponent(UFG::AttackRightsComponent *this)
{
  UFG::AttackRightsComponent *v1; // rbx
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *v2; // rdi
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *v3; // rcx
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *v4; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *v10; // rcx
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AttackRightsComponent::`vftable;
  if ( this == UFG::AttackRightsComponent::s_AttackRightsComponentpCurrentIterator )
    UFG::AttackRightsComponent::s_AttackRightsComponentpCurrentIterator = (UFG::AttackRightsComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qString::~qString(&v1->m_DebugText);
  `eh vector destructor iterator(
    v1->m_pLastAttackRequest,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v5 = &v1->m_pNextAttacker;
  if ( v1->m_pNextAttacker.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->m_pNextAttacker.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->m_pNextAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v1->m_pNextAttacker.mPrev;
  }
  v1->m_pNextAttacker.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->m_pNextAttacker.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->m_pNextAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v1->m_pNextAttacker.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pCharacterOccupantComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pHitReactionComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pFormationManagerComponent);
  `eh vector destructor iterator(
    v1->m_FollowerAttackSlotQueue,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qList<UFG::SoundBank,UFG::SoundBankGroupBankList,0,0>::~qList<UFG::SoundBank,UFG::SoundBankGroupBankList,0,0>);
  `eh vector destructor iterator(
    v1->m_AttackSlotQueue,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>);
  `eh vector destructor iterator(
    v1->m_pPreviousBestAttacker,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  `eh vector destructor iterator(
    v1->m_pCachedNextAttacker,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  `eh vector destructor iterator(
    v1->m_pAttackSlot,
    0x18ui64,
    384,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 144
// RVA: 0x364DA0
bool __fastcall UFG::AttackRightsComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentAttackRights.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 150
// RVA: 0x37E560
UFG::SimComponent *__fastcall UFG::AttackRightsComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *v7; // rdx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x2880ui64, "AttackRightsComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v1->mpWritableProperties;
    if ( !v4 )
      v4 = v1->mpConstProperties;
    UFG::AttackRightsComponent::AttackRightsComponent((UFG::AttackRightsComponent *)v3, v1->m_NameUID, v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v1->m_pSimObject;
  if ( (v7->m_Flags >> 14) & 1 )
    v8 = 46;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v6, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v6;
}

// File Line: 157
// RVA: 0x366D40
void __fastcall UFG::AttackRightsComponent::InitFromProperties(UFG::AttackRightsComponent *this, UFG::qPropertySet *property_set)
{
  UFG::qPropertySet *v2; // rdi
  UFG::AttackRightsComponent *v3; // r14
  UFG::qSymbol *v4; // rsi
  UFG::qString *v5; // rax
  UFG::qString *v6; // rax
  UFG::qString *v7; // rax
  int *v8; // rbx
  signed __int64 v9; // rbp
  int *v10; // rax
  signed int v11; // edx
  signed int v12; // ecx
  signed int v13; // ecx
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
  int v33; // [rsp+28h] [rbp-80h]
  int v34; // [rsp+2Ch] [rbp-7Ch]
  int v35; // [rsp+30h] [rbp-78h]
  UFG::qString result; // [rsp+38h] [rbp-70h]

  v2 = property_set;
  v3 = this;
  v4 = attack_slot_names;
  if ( !(_S11_2 & 1) )
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
    v10 = UFG::qPropertySet::Get<long>(v2, v4, DEPTH_RECURSE);
    if ( v10 )
      *v8 = *v10;
    else
      *v8 = 0;
    ++v4;
    ++v8;
    --v9;
  }
  while ( v9 );
  v11 = 64;
  v12 = 64;
  if ( v33 < 64 )
    v12 = v33;
  v3->m_NumAttackSlots[0] = v12;
  v13 = 64;
  if ( v34 < 64 )
    v13 = v34;
  v3->m_NumAttackSlots[1] = v13;
  if ( v35 < 64 )
    v11 = v35;
  v3->m_NumAttackSlots[2] = v11;
  v14 = _S11_2;
  if ( !(_S11_2 & 2) )
  {
    _S11_2 |= 2u;
    UFG::qSymbol::create_from_string(&min_distance_symbol, "MinDistanceToBeConsideredInCombat");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_11_::_dynamic_atexit_destructor_for__min_distance_symbol__);
    v14 = _S11_2;
  }
  if ( !(v14 & 4) )
  {
    _S11_2 = v14 | 4;
    UFG::qSymbol::create_from_string(&max_distance_symbol, "MaxDistanceToBeConsideredInCombat");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_11_::_dynamic_atexit_destructor_for__max_distance_symbol__);
    v14 = _S11_2;
  }
  if ( !(v14 & 8) )
  {
    _S11_2 = v14 | 8;
    UFG::qSymbol::create_from_string(&min_angle_symbol, "MinAngleToBeConsideredInCombat");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_11_::_dynamic_atexit_destructor_for__min_angle_symbol__);
    v14 = _S11_2;
  }
  if ( !(v14 & 0x10) )
  {
    _S11_2 = v14 | 0x10;
    UFG::qSymbol::create_from_string(&max_angle_symbol, "MaxAngleToBeConsideredInCombat");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_11_::_dynamic_atexit_destructor_for__max_angle_symbol__);
  }
  v15 = UFG::qPropertySet::Get<float>(v2, &min_distance_symbol, DEPTH_RECURSE);
  if ( v15 )
  {
    v16 = *v15;
    v17 = UFG::qPropertySet::Get<float>(v2, &max_distance_symbol, DEPTH_RECURSE);
    if ( v17 )
    {
      v18 = *v17;
      v19 = UFG::qPropertySet::Get<float>(v2, &min_angle_symbol, DEPTH_RECURSE);
      if ( v19 )
      {
        v20 = *v19;
        v21 = UFG::qPropertySet::Get<float>(v2, &max_angle_symbol, DEPTH_RECURSE);
        if ( v21 )
        {
          v22 = *v21;
          v3->m_InCombatParams.m_CloseDistance = v16;
          v3->m_InCombatParams.m_FarDistance = v18;
          v3->m_InCombatParams.m_NarrowAngle = v20;
          v3->m_InCombatParams.m_WideAngle = v22;
        }
      }
    }
  }
  v23 = _S11_2;
  if ( !(_S11_2 & 0x20) )
  {
    _S11_2 |= 0x20u;
    UFG::qSymbol::create_from_string(&min_time_symbol, "MinTimeBetweenAttackerSwitch");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_14_::_dynamic_atexit_destructor_for__min_time_symbol__);
    v23 = _S11_2;
  }
  if ( !(v23 & 0x40) )
  {
    _S11_2 = v23 | 0x40;
    UFG::qSymbol::create_from_string(&max_time_symbol, "MaxTimeBetweenAttackerSwitch");
    atexit(UFG::AttackRightsComponent::InitFromProperties_::_14_::_dynamic_atexit_destructor_for__max_time_symbol__);
  }
  v24 = UFG::qPropertySet::Get<float>(v2, &min_time_symbol, DEPTH_RECURSE);
  if ( v24 )
  {
    v25 = *v24;
    v26 = UFG::qPropertySet::Get<float>(v2, &max_time_symbol, DEPTH_RECURSE);
    if ( v26 )
    {
      v27 = *v26;
      v3->m_MinTimeBetweenAttackerSwitch = v25;
      v3->m_MaxTimeBetweenAttackerSwitch = v27;
    }
  }
  v28 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&qSymbol_OnScreenTestFOVReduction.mUID, DEPTH_RECURSE);
  if ( v28 )
    UFG::AttackRightsComponent::s_OnScreenTestFOVReduction = (float)(*v28 * 3.1415927) * 0.0055555557;
  v29 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&qSymbol_OnScreenTestFootSphereRadius.mUID, DEPTH_RECURSE);
  if ( v29 )
    UFG::AttackRightsComponent::s_OnScreenTestFootSphereRadius = *v29;
  v30 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&qSymbol_OnScreenTestHeadSphereRadius.mUID, DEPTH_RECURSE);
  if ( v30 )
    UFG::AttackRightsComponent::s_OnScreenTestHeadSphereRadius = *v30;
  v31 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&qSymbol_OnScreenTestHeadHeight.mUID, DEPTH_RECURSE);
  if ( v31 )
    UFG::AttackRightsComponent::s_OnScreenTestHeadHeight = *v31;
  v32 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&qSymbol_DefaultTimeUntilNextAttack.mUID, DEPTH_RECURSE);
  if ( v32 )
    UFG::AttackRightsComponent::s_DefaultTimeUntilNextAttack = *v32;
  UFG::AttackRightsComponent::ClearAttackSlots(v3);
}

// File Line: 268
// RVA: 0x378900
void __fastcall UFG::AttackRightsComponent::OnAttach(UFG::AttackRightsComponent *this, UFG::SimObject *object)
{
  UFG::AttackRightsComponent *v2; // rbx
  UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0> *v3; // rcx
  UFG::SimObjectCharacter *v4; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax

  v2 = this;
  v3 = &this->m_pFormationManagerComponent;
  v4 = (UFG::SimObjectCharacter *)object;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pSimObject = 0i64;
    v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0> *)v3->mNext != v3) )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = (UFG::SimObject *)&v4->vfptr;
  v3->m_TypeUID = UFG::FormationManagerComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0>::BindInternal<UFG::SimObjectCharacter>(v3, v4);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pTransformNodeComponent,
    v4);
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::Bind<UFG::SimObjectCharacter>(&v2->m_pAIEntityComponent, v4);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pActionTreeComponent,
    v4);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pCharacterPhysicsComponent,
    v4);
  v9 = &v2->m_pSimObjectCharacterPropertiesComponent;
  if ( v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->m_pSimObjectCharacterPropertiesComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    v2->m_pSimObjectCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pSimObjectCharacterPropertiesComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v2->m_pSimObjectCharacterPropertiesComponent.mNext != &v2->m_pSimObjectCharacterPropertiesComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->m_pSimObjectCharacterPropertiesComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = (UFG::SimObject *)&v4->vfptr;
  v2->m_pSimObjectCharacterPropertiesComponent.m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &v2->m_pSimObjectCharacterPropertiesComponent,
    v4);
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pHitReactionComponent,
    v4);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::Bind<UFG::SimObjectCharacter>(&v2->m_pHealthComponent, v4);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pAIScriptInterfaceComponent,
    v4);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pTargetingSystemBaseComponent,
    v4);
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pCharacterOccupantComponent,
    v4);
}

// File Line: 292
// RVA: 0x37A110
void __fastcall UFG::AttackRightsComponent::OnDetach(UFG::AttackRightsComponent *this)
{
  UFG::AttackRightsComponent *v1; // rbx
  UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0> *v2; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v27; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *v32; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *v37; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rax
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *v42; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v43; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v44; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v45; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v46; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v47; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v48; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v49; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v50; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v51; // rax
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *v52; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v53; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v54; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v55; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v56; // rax

  v1 = this;
  UFG::AttackRightsComponent::ClearAttackSlots(this);
  v2 = &v1->m_pFormationManagerComponent;
  if ( v1->m_pFormationManagerComponent.m_pSimComponent )
  {
    v3 = v2->mPrev;
    v4 = v1->m_pFormationManagerComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->m_pFormationManagerComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pFormationManagerComponent.m_pSimObject = 0i64;
    v1->m_pFormationManagerComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pFormationManagerComponent.mPrev;
    v2->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    goto LABEL_8;
  }
  if ( v1->m_pFormationManagerComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0> *)v2->mPrev != v2
     || (UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0> *)v1->m_pFormationManagerComponent.mNext != &v1->m_pFormationManagerComponent) )
  {
    v5 = v2->mPrev;
    v6 = v1->m_pFormationManagerComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v1->m_pTransformNodeComponent;
  v1->m_pFormationManagerComponent.m_Changed = 1;
  if ( v1->m_pTransformNodeComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v1->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_14:
    v1->m_pTransformNodeComponent.m_pSimObject = 0i64;
    v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pTransformNodeComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v1->m_pTransformNodeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->m_pTransformNodeComponent.mNext != &v1->m_pTransformNodeComponent) )
  {
    v10 = v7->mPrev;
    v11 = v1->m_pTransformNodeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v1->m_pTransformNodeComponent.m_Changed = 1;
  v12 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v1->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_21:
    v1->m_pAIEntityComponent.m_pSimObject = 0i64;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pAIEntityComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v1->m_pAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)v1->m_pAIEntityComponent.mNext != &v1->m_pAIEntityComponent) )
  {
    v15 = v12->mPrev;
    v16 = v1->m_pAIEntityComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v1->m_pAIEntityComponent.m_Changed = 1;
  v17 = &v1->m_pActionTreeComponent;
  if ( v1->m_pActionTreeComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v1->m_pActionTreeComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v1->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_28:
    v1->m_pActionTreeComponent.m_pSimObject = 0i64;
    v1->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pActionTreeComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_29;
  }
  if ( v1->m_pActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v1->m_pActionTreeComponent.mNext != &v1->m_pActionTreeComponent) )
  {
    v20 = v17->mPrev;
    v21 = v1->m_pActionTreeComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  v1->m_pActionTreeComponent.m_Changed = 1;
  v22 = &v1->m_pCharacterPhysicsComponent;
  if ( v1->m_pCharacterPhysicsComponent.m_pSimComponent )
  {
    v23 = v22->mPrev;
    v24 = v1->m_pCharacterPhysicsComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v1->m_pCharacterPhysicsComponent.m_pSimComponent = 0i64;
LABEL_35:
    v1->m_pCharacterPhysicsComponent.m_pSimObject = 0i64;
    v1->m_pCharacterPhysicsComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pCharacterPhysicsComponent.mPrev;
    v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    goto LABEL_36;
  }
  if ( v1->m_pCharacterPhysicsComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)v22->mPrev != v22
     || (UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)v1->m_pCharacterPhysicsComponent.mNext != &v1->m_pCharacterPhysicsComponent) )
  {
    v25 = v22->mPrev;
    v26 = v1->m_pCharacterPhysicsComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  v1->m_pCharacterPhysicsComponent.m_Changed = 1;
  v27 = &v1->m_pSimObjectCharacterPropertiesComponent;
  if ( v1->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v28 = v27->mPrev;
    v29 = v1->m_pSimObjectCharacterPropertiesComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v1->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_42:
    v1->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    v1->m_pSimObjectCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pSimObjectCharacterPropertiesComponent.mPrev;
    v27->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v27->mPrev;
    goto LABEL_43;
  }
  if ( v1->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v27->mPrev != v27
     || (UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v1->m_pSimObjectCharacterPropertiesComponent.mNext != &v1->m_pSimObjectCharacterPropertiesComponent) )
  {
    v30 = v27->mPrev;
    v31 = v1->m_pSimObjectCharacterPropertiesComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  v1->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  v32 = &v1->m_pHitReactionComponent;
  if ( v1->m_pHitReactionComponent.m_pSimComponent )
  {
    v33 = v32->mPrev;
    v34 = v1->m_pHitReactionComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    v1->m_pHitReactionComponent.m_pSimComponent = 0i64;
LABEL_49:
    v1->m_pHitReactionComponent.m_pSimObject = 0i64;
    v1->m_pHitReactionComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pHitReactionComponent.mPrev;
    v32->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v32->mPrev;
    goto LABEL_50;
  }
  if ( v1->m_pHitReactionComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *)v32->mPrev != v32
     || (UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *)v1->m_pHitReactionComponent.mNext != &v1->m_pHitReactionComponent) )
  {
    v35 = v32->mPrev;
    v36 = v1->m_pHitReactionComponent.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    goto LABEL_49;
  }
LABEL_50:
  v1->m_pHitReactionComponent.m_Changed = 1;
  v37 = &v1->m_pHealthComponent;
  if ( v1->m_pHealthComponent.m_pSimComponent )
  {
    v38 = v37->mPrev;
    v39 = v1->m_pHealthComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    v1->m_pHealthComponent.m_pSimComponent = 0i64;
LABEL_56:
    v1->m_pHealthComponent.m_pSimObject = 0i64;
    v1->m_pHealthComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pHealthComponent.mPrev;
    v37->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v37->mPrev;
    goto LABEL_57;
  }
  if ( v1->m_pHealthComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v37->mPrev != v37
     || (UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v1->m_pHealthComponent.mNext != &v1->m_pHealthComponent) )
  {
    v40 = v37->mPrev;
    v41 = v1->m_pHealthComponent.mNext;
    v40->mNext = v41;
    v41->mPrev = v40;
    goto LABEL_56;
  }
LABEL_57:
  v1->m_pHealthComponent.m_Changed = 1;
  v42 = &v1->m_pAIScriptInterfaceComponent;
  if ( v1->m_pAIScriptInterfaceComponent.m_pSimComponent )
  {
    v43 = v42->mPrev;
    v44 = v1->m_pAIScriptInterfaceComponent.mNext;
    v43->mNext = v44;
    v44->mPrev = v43;
    v1->m_pAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_63:
    v1->m_pAIScriptInterfaceComponent.m_pSimObject = 0i64;
    v1->m_pAIScriptInterfaceComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pAIScriptInterfaceComponent.mPrev;
    v42->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v42->mPrev;
    goto LABEL_64;
  }
  if ( v1->m_pAIScriptInterfaceComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v42->mPrev != v42
     || (UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v1->m_pAIScriptInterfaceComponent.mNext != &v1->m_pAIScriptInterfaceComponent) )
  {
    v45 = v42->mPrev;
    v46 = v1->m_pAIScriptInterfaceComponent.mNext;
    v45->mNext = v46;
    v46->mPrev = v45;
    goto LABEL_63;
  }
LABEL_64:
  v1->m_pAIScriptInterfaceComponent.m_Changed = 1;
  v47 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v48 = v47->mPrev;
    v49 = v1->m_pTargetingSystemBaseComponent.mNext;
    v48->mNext = v49;
    v49->mPrev = v48;
    v1->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_70:
    v1->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
    v47->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v47->mPrev;
    goto LABEL_71;
  }
  if ( v1->m_pTargetingSystemBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v47->mPrev != v47
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v1->m_pTargetingSystemBaseComponent.mNext != &v1->m_pTargetingSystemBaseComponent) )
  {
    v50 = v47->mPrev;
    v51 = v1->m_pTargetingSystemBaseComponent.mNext;
    v50->mNext = v51;
    v51->mPrev = v50;
    goto LABEL_70;
  }
LABEL_71:
  v1->m_pTargetingSystemBaseComponent.m_Changed = 1;
  v52 = &v1->m_pCharacterOccupantComponent;
  if ( v1->m_pCharacterOccupantComponent.m_pSimComponent )
  {
    v53 = v52->mPrev;
    v54 = v1->m_pCharacterOccupantComponent.mNext;
    v53->mNext = v54;
    v54->mPrev = v53;
    v1->m_pCharacterOccupantComponent.m_pSimComponent = 0i64;
LABEL_77:
    v1->m_pCharacterOccupantComponent.m_pSimObject = 0i64;
    v1->m_pCharacterOccupantComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pCharacterOccupantComponent.mPrev;
    v52->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v52->mPrev;
    goto LABEL_78;
  }
  if ( v1->m_pCharacterOccupantComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *)v52->mPrev != v52
     || (UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *)v1->m_pCharacterOccupantComponent.mNext != &v1->m_pCharacterOccupantComponent) )
  {
    v55 = v52->mPrev;
    v56 = v1->m_pCharacterOccupantComponent.mNext;
    v55->mNext = v56;
    v56->mPrev = v55;
    goto LABEL_77;
  }
LABEL_78:
  v1->m_pCharacterOccupantComponent.m_Changed = 1;
}

// File Line: 309
// RVA: 0x382980
void __fastcall UFG::AttackRightsComponent::Reset(UFG::AttackRightsComponent *this)
{
  UFG::AttackRightsComponent::ClearAttackSlots(this);
}

// File Line: 314
// RVA: 0x34EF10
void __fastcall UFG::AttackRightsComponent::ClearAttackSlots(UFG::AttackRightsComponent *this)
{
  UFG::AttackRightsComponent *v1; // rbp
  bool *v2; // r14
  _DWORD *v3; // rdi
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> (*v4)[2][64]; // r8
  int (*v5)[2]; // rbx
  bool (*v6)[2]; // r9
  UFG::HasAttackRequestNode **v7; // r11
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> **v8; // rsi
  signed __int64 v9; // r15
  signed __int64 v10; // r10
  signed __int64 v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *i; // rdx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v15; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v16; // rcx
  __int64 v17; // rcx
  _QWORD *v18; // rax
  UFG::HasAttackRequestNode *v19; // rcx
  UFG::HasAttackRequestNode *v20; // rax
  UFG::HasAttackRequestNode *v21; // rax
  UFG::HasAttackRequestNode *v22; // rcx

  v1 = this;
  v2 = this->m_CurrentlyAttacking;
  v3 = (_DWORD *)this->m_NextTimeToUpdateAllowedToUseAttackSlotList;
  v4 = this->m_pAttackSlot;
  v5 = this->m_NextAttackBaton;
  v6 = this->m_OverrideAllowedToUseAttackSlotListThisFrame;
  v7 = &this->m_pCachedNextAttacker[0].m_pPointer;
  v8 = &this->m_AttackSlotQueue[0].mNode.mNext;
  v9 = 3i64;
  do
  {
    v10 = 2i64;
    do
    {
      v11 = 64i64;
      do
      {
        if ( (*v4)[0][0].m_pPointer )
        {
          v12 = (*v4)[0][0].mPrev;
          v13 = (*v4)[0][0].mNext;
          v12->mNext = v13;
          v13->mPrev = v12;
          (*v4)[0][0].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v4;
          (*v4)[0][0].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v4;
        }
        (*v4)[0][0].m_pPointer = 0i64;
        v4 = (UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> (*)[2][64])((char *)v4 + 24);
        --v11;
      }
      while ( v11 );
      *(_DWORD *)v5 = 0;
      (*v6)[-6] = 1;
      *(_BYTE *)v6 = 0;
      v6 = (bool (*)[2])((char *)v6 + 1);
      v5 = (int (*)[2])((char *)v5 + 4);
      --v10;
    }
    while ( v10 );
    for ( i = *v8; &(*v8)[-3].mNext != v8 - 6; i = *v8 )
    {
      v15 = i->mNext;
      v16 = i->mPrev;
      v16->mNext = v15;
      v15->mPrev = v16;
      i->mPrev = i;
      i->mNext = i;
    }
    v3[49] = 0;
    *(v2 - 64) = 1;
    *v2 = 0;
    *v3 = -943501440;
    v3[65] = -943501440;
    v3[61] = -943501440;
    if ( *v7 )
    {
      v17 = (__int64)*(v7 - 2);
      v18 = *(v7 - 1);
      *(_QWORD *)(v17 + 8) = v18;
      *v18 = v17;
      *(v7 - 2) = (UFG::HasAttackRequestNode *)(v7 - 2);
      *(v7 - 1) = (UFG::HasAttackRequestNode *)(v7 - 2);
    }
    *v7 = 0i64;
    if ( v7[9] )
    {
      v19 = v7[7];
      v20 = v7[8];
      v19->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v20;
      v20->vfptr = (UFG::qSafePointerNode<UFG::HasAttackRequestNode>Vtbl *)v19;
      v7[7] = (UFG::HasAttackRequestNode *)(v7 + 7);
      v7[8] = (UFG::HasAttackRequestNode *)(v7 + 7);
    }
    v7[9] = 0i64;
    v3[46] = -943501440;
    if ( v7[111] )
    {
      v21 = v7[110];
      v22 = v7[109];
      v22->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v21;
      v21->vfptr = (UFG::qSafePointerNode<UFG::HasAttackRequestNode>Vtbl *)v22;
      v7[109] = (UFG::HasAttackRequestNode *)(v7 + 109);
      v7[110] = (UFG::HasAttackRequestNode *)(v7 + 109);
    }
    v7[111] = 0i64;
    v7 += 3;
    ++v3;
    v8 += 2;
    ++v2;
    --v9;
  }
  while ( v9 );
  v1->m_InCombatWithSomeone = 0;
  v1->m_IsDowned = 0;
  v1->m_NextTimeCanPerformRunningAttack = -99999.0;
  v1->m_RunningAttacksEnabled = 1;
}e = 0;
  v1->m_IsDowned = 0;
  

// File Line: 351
// RVA: 0x34CD90
void __fastcall UFG::AttackRightsComponent::CheckIfDownedStateChanged(UFG::AttackRightsComponent *this)
{
  UFG::AttackRightsComponent *v1; // rbx
  UFG::ActionTreeComponent *v2; // rcx
  bool v3; // al
  __int64 v4; // r8
  float *v5; // rdi
  UFG::eAttackType v6; // esi
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v7; // rax
  float v8; // xmm0_4

  v1 = this;
  v2 = (UFG::ActionTreeComponent *)this->m_pActionTreeComponent.m_pSimComponent;
  if ( v2 )
  {
    v3 = UFG::IsDowned(v2, (UFG::HealthComponent *)v1->m_pHealthComponent.m_pSimComponent);
    if ( v1->m_IsDowned != v3 )
    {
      v1->m_IsDowned = v3;
      if ( v3 )
      {
        *(_QWORD *)v1->m_TimeUntilNextAttack = 5292894976998646768i64;
        v1->m_TimeUntilNextAttack[2] = 999999.0;
        return;
      }
      v5 = v1->m_TimeUntilNextAttack;
      v6 = 0;
      do
      {
        v7 = UFG::AttackRightsComponent::GetNextAttacker(v1, v6, v4);
        if ( v7 )
        {
          v8 = UFG::AttackRightsComponent::GetTimeUntilNextAttack(
                 v1,
                 (UFG::HasAttackRequestNode *)v7,
                 (UFG::HasAttackRequestNode *)v7);
          if ( !v1->m_IsDowned )
            goto LABEL_11;
        }
        else if ( !v1->m_IsDowned )
        {
          v8 = UFG::AttackRightsComponent::s_DefaultTimeUntilNextAttack;
LABEL_11:
          *v5 = v8;
          goto LABEL_12;
        }
LABEL_12:
        ++v6;
        ++v5;
      }
      while ( (signed int)v6 < 3 );
    }
  }
}

// File Line: 441
// RVA: 0x36D220
void __fastcall UFG::AttackRightsComponent::JustPerformedOpportunityAttack(UFG::AttackRightsComponent *this, UFG::eAttackType attack_type, float min_time_until_next_one, float max_time_until_next_one)
{
  __int64 v4; // rbx
  UFG::AttackRightsComponent *v5; // rdi
  float v6; // xmm0_4
  float v7; // xmm8_4

  v4 = (signed int)attack_type;
  v5 = this;
  v6 = max_time_until_next_one;
  v7 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( max_time_until_next_one > min_time_until_next_one )
  {
    v6 = UFG::qRandom(max_time_until_next_one - min_time_until_next_one, &UFG::qDefaultSeed) + min_time_until_next_one;
    if ( v6 <= min_time_until_next_one )
      v6 = min_time_until_next_one;
    if ( v6 >= max_time_until_next_one )
      v6 = max_time_until_next_one;
  }
  v5->m_NextTimeCanPerformOpportunityAttack[v4] = v6 + v7;
}

// File Line: 473
// RVA: 0x382280
void __fastcall UFG::AttackRightsComponent::RequestAttackSlot(UFG::AttackRightsComponent *this, UFG::HasAttackRequestNode *attacker)
{
  UFG::HasAttackRequestNode *v2; // r8
  UFG::AttackRightsComponent *v3; // rbx
  signed __int64 v4; // r11
  __int64 v5; // r10
  __int64 v6; // r9
  __int64 v7; // rdx
  UFG::HasAttackRequestNode **v8; // rax
  signed __int64 v9; // r11
  signed int v10; // ecx
  signed __int64 v11; // rdx
  signed __int64 v12; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v13; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v14; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v15; // rdx
  UFG::qList<UFG::HasAttackRequestNode,UFG::AttackRightsList,0,0> *v16; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v17; // rax

  v2 = attacker;
  v3 = this;
  if ( attacker )
  {
    v4 = (signed int)attacker->m_AttackType;
    v5 = 0i64;
    v6 = this->m_NumAttackSlots[v4];
    while ( 1 )
    {
      v7 = 0i64;
      if ( v6 > 0 )
        break;
LABEL_7:
      if ( ++v5 >= 2 )
      {
        v9 = v4;
        v10 = -1;
        v11 = (signed __int64)(&v3->m_RunningAttacksEnabled + v9 * 16);
        v12 = (signed __int64)&v3->m_AttackSlotQueue[v9].mNode.mNext[-3].mNext;
        if ( v12 == v11 )
        {
LABEL_11:
          v10 = -1;
        }
        else
        {
          while ( 1 )
          {
            ++v10;
            if ( (UFG::HasAttackRequestNode *)v12 == v2 )
              break;
            v12 = *(_QWORD *)(v12 + 48) - 40i64;
            if ( v12 == v11 )
              goto LABEL_11;
          }
        }
        if ( v10 == -1 )
        {
          v13 = v2->mPrev;
          v14 = v2->mNext;
          v15 = (UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *)&v2->mPrev;
          v13->mNext = v14;
          v14->mPrev = v13;
          v15->mPrev = v15;
          v15->mNext = v15;
          v16 = &v3->m_AttackSlotQueue[v2->m_AttackType];
          v17 = v16->mNode.mPrev;
          v17->mNext = (UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *)&v2->mPrev;
          v15->mPrev = v17;
          v15->mNext = &v16->mNode;
          v16->mNode.mPrev = (UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *)&v2->mPrev;
        }
        return;
      }
    }
    v8 = &this->m_pAttackSlot[0][0][0].m_pPointer + 192 * (v5 + 2 * v4);
    while ( v2 != *v8 )
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
void __fastcall UFG::AttackRightsComponent::AddToFollowerAttackSlotQueue(UFG::AttackRightsComponent *this, UFG::HasAttackRequestNode *attacker)
{
  UFG::HasAttackRequestNode *v2; // r10
  UFG::AttackRightsComponent *v3; // r11
  signed int v4; // er9
  UFG::HasAttackRequestNode *v5; // r8
  UFG::HasAttackRequestNode *v6; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v7; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v8; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v9; // rdx
  UFG::qList<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList,0,0> *v10; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v11; // rax

  v2 = attacker;
  v3 = this;
  if ( attacker )
  {
    v4 = -1;
    v5 = (UFG::HasAttackRequestNode *)&this->m_CurrentlyAttacking[16 * attacker->m_AttackType];
    v6 = (UFG::HasAttackRequestNode *)&this->m_FollowerAttackSlotQueue[attacker->m_AttackType].mNode.mNext[-4].mNext;
    if ( v6 == v5 )
    {
LABEL_5:
      v4 = -1;
    }
    else
    {
      while ( 1 )
      {
        ++v4;
        if ( v6 == attacker )
          break;
        v6 = (UFG::HasAttackRequestNode *)&v6->mNext[-4].mNext;
        if ( v6 == v5 )
          goto LABEL_5;
      }
    }
    if ( v4 == -1 )
    {
      v7 = attacker->mPrev;
      v8 = attacker->mNext;
      v9 = (UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *)&attacker->mPrev;
      v7->mNext = v8;
      v8->mPrev = v7;
      v9->mPrev = v9;
      v9->mNext = v9;
      v10 = &v3->m_FollowerAttackSlotQueue[v2->m_AttackType];
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
char __fastcall UFG::AttackRightsComponent::GetAttackSlotInfo(UFG::AttackRightsComponent *this, UFG::HasAttackRequestNode *attacker, UFG::AttackSlotInfo *attack_slot_info)
{
  UFG::AttackSlotInfo *v3; // r14
  UFG::HasAttackRequestNode *v4; // r10
  __int64 v5; // rsi
  UFG::eAttackSlotList v6; // ebx
  signed __int64 v7; // r11
  __int64 v8; // r9
  int v9; // er8
  __int64 v10; // rdx
  UFG::HasAttackRequestNode **v11; // rax

  v3 = attack_slot_info;
  v4 = attacker;
  if ( !attacker )
    return 0;
  v5 = (signed int)attacker->m_AttackType;
  v6 = 0;
  v7 = 0i64;
  v8 = this->m_NumAttackSlots[v5];
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
  v11 = &this->m_pAttackSlot[0][0][0].m_pPointer + 192 * (v7 + 2 * v5);
  while ( v4 != *v11 )
  {
    ++v10;
    ++v9;
    v11 += 3;
    if ( v10 >= v8 )
      goto LABEL_7;
  }
  v3->m_AttackSlotList = v6;
  v3->m_AttackSlot = v9;
  return 1;
}

// File Line: 610
// RVA: 0x38AE10
void __fastcall UFG::AttackRightsComponent::UnregisterUnavailableAttackers(UFG::AttackRightsComponent *this)
{
  UFG::AttackRightsComponent *v1; // r14
  __int64 v2; // r13
  int *v3; // rsi
  UFG::HasAttackRequestNode **v4; // r15
  bool *v5; // r12
  signed __int64 v6; // rbp
  int v7; // edi
  UFG::HasAttackRequestNode **v8; // rbx
  __int64 v9; // rcx
  _QWORD *v10; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> **v11; // rdi
  UFG::HasAttackRequestNode *v12; // rbx
  signed __int64 v13; // rdi
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v14; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v15; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v16; // rdx
  __int64 v17; // rcx
  _QWORD *v18; // rax
  bool v19; // zf
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> **v20; // [rsp+68h] [rbp+10h]
  signed __int64 v21; // [rsp+70h] [rbp+18h]

  v1 = this;
  v2 = 0i64;
  v3 = this->m_NumAttackSlots;
  v4 = &this->m_pCachedNextAttacker[0].m_pPointer;
  v5 = this->m_CurrentlyAttacking;
  v20 = &this->m_FollowerAttackSlotQueue[0].mNode.mNext;
  v21 = 3i64;
  do
  {
    v6 = 0i64;
    do
    {
      v7 = 0;
      if ( *v3 > 0 )
      {
        v8 = &v1->m_pAttackSlot[0][0][0].m_pPointer + 192 * (v6 + v2);
        do
        {
          if ( *v8 && !UFG::AttackRightsComponent::AttackerIsAvailable(v1, *v8) )
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
        while ( v7 < *v3 );
      }
      ++v6;
    }
    while ( v6 < 2 );
    v11 = v20;
    v12 = (UFG::HasAttackRequestNode *)&(*v20)[-4].mNext;
    if ( v12 != (UFG::HasAttackRequestNode *)v5 )
    {
      do
      {
        v13 = (signed __int64)&v12->mNext[-4].mNext;
        if ( !UFG::AttackRightsComponent::AttackerIsAvailable(v1, v12) )
        {
          v14 = v12->mPrev;
          v15 = v12->mNext;
          v16 = (UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *)&v12->mPrev;
          v14->mNext = v15;
          v15->mPrev = v14;
          v16->mPrev = v16;
          v16->mNext = v16;
        }
        v12 = (UFG::HasAttackRequestNode *)v13;
      }
      while ( (bool *)v13 != v5 );
      v11 = v20;
    }
    if ( *v4 && !UFG::AttackRightsComponent::AttackerIsAvailable(v1, *v4) )
    {
      if ( *v4 )
      {
        v17 = (__int64)*(v4 - 2);
        v18 = *(v4 - 1);
        *(_QWORD *)(v17 + 8) = v18;
        *v18 = v17;
        *(v4 - 2) = (UFG::HasAttackRequestNode *)(v4 - 2);
        *(v4 - 1) = (UFG::HasAttackRequestNode *)(v4 - 2);
      }
      *v4 = 0i64;
    }
    v5 += 16;
    ++v3;
    v2 += 2i64;
    v4 += 3;
    v19 = v21-- == 1;
    v20 = v11 + 2;
  }
  while ( !v19 );
}

// File Line: 675
// RVA: 0x34CE60
void __fastcall UFG::AttackRightsComponent::CheckIfInCombat(UFG::AttackRightsComponent *this)
{
  UFG::AttackRightsComponent *v1; // r14
  float v2; // xmm9_4
  float v3; // xmm0_4
  bool v4; // al
  float v5; // xmm8_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  __int64 v8; // r12
  int *v9; // rsi
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> **v10; // r13
  signed __int64 v11; // r15
  UFG::HasAttackRequestNode *i; // rbx
  signed __int64 v13; // rbp
  int v14; // edi
  UFG::HasAttackRequestNode **v15; // rbx
  UFG::HasAttackRequestNode *v16; // rdx
  signed __int64 v17; // [rsp+20h] [rbp-98h]
  float distance_away; // [rsp+C0h] [rbp+8h]
  float cosine_of_angle_away; // [rsp+C8h] [rbp+10h]
  float v20; // [rsp+D0h] [rbp+18h]
  float v21; // [rsp+D8h] [rbp+20h]

  v1 = this;
  v2 = cosf((float)(this->m_InCombatParams.m_NarrowAngle * 3.1415927) * 0.0055555557);
  v3 = cosf((float)(v1->m_InCombatParams.m_WideAngle * 3.1415927) * 0.0055555557);
  v4 = v1->m_InCombatWithSomeone;
  if ( v4 )
    v5 = v1->m_InCombatParams.m_FarDistance;
  else
    v5 = v1->m_InCombatParams.m_CloseDistance;
  if ( v4 )
    v2 = v3;
  v6 = FLOAT_99999_0;
  v7 = 0.0;
  v8 = 0i64;
  v9 = v1->m_NumAttackSlots;
  v10 = &v1->m_AttackSlotQueue[0].mNode.mNext;
  v11 = (signed __int64)&v1->m_RunningAttacksEnabled;
  v17 = 3i64;
  do
  {
    for ( i = (UFG::HasAttackRequestNode *)&(*v10)[-3].mNext;
          i != (UFG::HasAttackRequestNode *)v11;
          i = (UFG::HasAttackRequestNode *)&i->mNext[-3].mNext )
    {
      distance_away = 0.0;
      cosine_of_angle_away = 0.0;
      UFG::AttackRightsComponent::GetDistanceAndAngleAway(v1, i, &distance_away, &cosine_of_angle_away);
      if ( v6 >= distance_away )
        v6 = distance_away;
      if ( v7 <= cosine_of_angle_away )
        v7 = cosine_of_angle_away;
    }
    v13 = 0i64;
    do
    {
      v14 = 0;
      if ( *v9 > 0 )
      {
        v15 = &v1->m_pAttackSlot[0][0][0].m_pPointer + 192 * (v8 + v13);
        do
        {
          v16 = *v15;
          if ( *v15 )
          {
            v20 = 0.0;
            v21 = 0.0;
            UFG::AttackRightsComponent::GetDistanceAndAngleAway(v1, v16, &v20, &v21);
            if ( v6 >= v20 )
              v6 = v20;
            if ( v7 <= v21 )
              v7 = v21;
          }
          ++v14;
          v15 += 3;
        }
        while ( v14 < *v9 );
      }
      ++v13;
    }
    while ( v13 < 2 );
    v11 += 16i64;
    v10 += 2;
    ++v9;
    v8 += 2i64;
    --v17;
  }
  while ( v17 );
  v1->m_InCombatWithSomeone = v6 <= v5 && v7 >= v2;
}

// File Line: 743
// RVA: 0x35EC30
void __fastcall UFG::AttackRightsComponent::GetDistanceAndAngleAway(UFG::AttackRightsComponent *this, UFG::HasAttackRequestNode *attacker, float *distance_away, float *cosine_of_angle_away)
{
  UFG::TransformNodeComponent *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rdi
  float *v6; // r15
  float *v7; // r14
  UFG::AttackRightsComponent *v8; // rsi
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rbx
  float v12; // xmm6_4
  __m128 v13; // xmm7
  UFG::SimComponent *v14; // rbx
  UFG::TransformNodeComponent *v15; // rcx
  __m128 v16; // xmm1
  float v17; // xmm4_4
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  float v20; // xmm5_4

  UFG::g_pThis = this;
  v4 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v5 = 0i64;
  UFG::g_Attacker = attacker;
  UFG::g_pAttackerTransformNodeComponent = 0i64;
  UFG::g_pMyTransformNodeComponent = v4;
  *distance_away = 99999.0;
  v6 = cosine_of_angle_away;
  v7 = distance_away;
  v8 = this;
  *cosine_of_angle_away = 0.0;
  if ( attacker )
  {
    v9 = attacker->m_pOwner.m_pPointer;
    if ( v9 )
    {
      if ( v9[3].m_BoundComponentHandles.mNode.mNext && this->m_pTransformNodeComponent.m_pSimComponent )
      {
        UFG::g_pAttackerTransformNodeComponent = (UFG::TransformNodeComponent *)v9[3].m_BoundComponentHandles.mNode.mNext;
        v10 = attacker->m_pOwner.m_pPointer;
        if ( v10 )
          v5 = v10[3].m_BoundComponentHandles.mNode.mNext;
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5);
        v11 = v8->m_pTransformNodeComponent.m_pSimComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8->m_pTransformNodeComponent.m_pSimComponent);
        v13 = (__m128)HIDWORD(v5[11].mPrev);
        v12 = *(float *)&v5[11].mPrev - *(float *)&v11[2].m_BoundComponentHandles.mNode.mPrev;
        v13.m128_f32[0] = v13.m128_f32[0] - *((float *)&v11[2].m_BoundComponentHandles.mNode.mPrev + 1);
        v14 = v8->m_pTransformNodeComponent.m_pSimComponent;
        v15 = (UFG::TransformNodeComponent *)v8->m_pTransformNodeComponent.m_pSimComponent;
        v16 = v13;
        v16.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12);
        *(_DWORD *)v7 = (unsigned __int128)_mm_sqrt_ps(v16);
        UFG::TransformNodeComponent::UpdateWorldTransform(v15);
        v17 = *(float *)&v14[2].vfptr;
        v18 = (__m128)HIDWORD(v14[2].vfptr);
        v19 = v18;
        v19.m128_f32[0] = (float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)(v17 * v17);
        LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v19);
        if ( *v7 > 0.001 && v20 > 0.001 )
          *v6 = (float)((float)((float)(v18.m128_f32[0] * (float)(1.0 / v20))
                              * (float)(v13.m128_f32[0] * (float)(1.0 / *v7)))
                      + (float)((float)(v17 * (float)(1.0 / v20)) * (float)(v12 * (float)(1.0 / *v7))))
              + (float)((float)((float)(1.0 / v20) * 0.0) * (float)((float)(1.0 / *v7) * 0.0));
      }
    }
  }
}

// File Line: 791
// RVA: 0x350780
__int64 __fastcall UFG::AttackRightsComponent::CountNumDistinctAttackers(UFG::AttackRightsComponent *this, UFG::SimObject *exclude_this_guy)
{
  unsigned int v2; // er14
  UFG::SimObject *v3; // rbx
  UFG::AttackRightsComponent *v4; // r15
  signed __int64 v5; // rsi
  int *v6; // rbp
  __int64 v7; // rdi
  int v8; // er10
  signed __int64 v9; // r8
  signed __int64 v10; // r11
  __int64 v11; // r9
  signed __int64 v12; // rdx
  __int64 v13; // rax
  UFG::SimObject *v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rax
  __int64 v18[128]; // [rsp+0h] [rbp-418h]

  v2 = 0;
  v3 = exclude_this_guy;
  v4 = this;
  v5 = 0i64;
  v6 = this->m_NumAttackSlots;
  do
  {
    v7 = *v6;
    v8 = 0;
    v9 = 0i64;
    v10 = 0i64;
    do
    {
      if ( v7 > 0 )
      {
        v11 = v7;
        v12 = (signed __int64)(&v4->m_pAttackSlot[0][0][0].m_pPointer + 192 * (v5 + v10));
        do
        {
          if ( *(_QWORD *)v12 )
          {
            v13 = *(_QWORD *)(*(_QWORD *)v12 + 216i64);
            v14 = (UFG::SimObject *)(v13 ? *(_QWORD *)(v13 + 40) : 0i64);
            if ( v14 != v3 )
            {
              if ( v13 )
                v15 = *(_QWORD *)(v13 + 40);
              else
                v15 = 0i64;
              v16 = 0i64;
              if ( v9 <= 0 )
              {
LABEL_16:
                if ( v9 < 128 )
                {
                  v18[v9] = v15;
                  ++v8;
                  ++v9;
                }
              }
              else
              {
                while ( v18[v16] != v15 )
                {
                  if ( ++v16 >= v9 )
                    goto LABEL_16;
                }
              }
            }
          }
          v12 += 24i64;
          --v11;
        }
        while ( v11 );
      }
      ++v10;
    }
    while ( v10 < 2 );
    v5 += 2i64;
    v2 += v8;
    ++v6;
  }
  while ( v5 < 6 );
  return v2;
}

// File Line: 957
// RVA: 0x342770
char __fastcall UFG::AttackRightsComponent::AttackerIsAvailable(UFG::AttackRightsComponent *this, UFG::HasAttackRequestNode *attacker)
{
  UFG::HasAttackRequestNode *v2; // rdi
  UFG::AttackRightsComponent *v3; // rsi
  UFG::SimComponent *v4; // rax
  UFG::TransformNodeComponent *v5; // rbp
  UFG::SimComponent *v6; // rbx
  UFG::SimComponent *v7; // rdx
  float v8; // xmm1_4
  float v9; // xmm0_4
  char v10; // bl
  float v11; // xmm1_4
  __int64 v12; // r8
  UFG::SimObject *v13; // r14
  float v14; // xmm0_4
  UFG::HealthComponent *v15; // rax
  UFG::ActionTreeComponent *v16; // rcx
  bool v17; // al
  UFG::SimComponent *v18; // rcx
  bool v19; // bp
  UFG::ActionTreeComponent *v20; // rcx
  bool v21; // al

  v2 = attacker;
  v3 = this;
  if ( !attacker )
    return 0;
  v4 = attacker->m_pOwner.m_pPointer;
  if ( !v4 )
    return 0;
  if ( !*(_QWORD *)&v4[2].m_TypeUID )
    return 0;
  v5 = (UFG::TransformNodeComponent *)v4[3].m_BoundComponentHandles.mNode.mNext;
  if ( !v5 || !this->m_pTransformNodeComponent.m_pSimComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v6 = v3->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->m_pTransformNodeComponent.m_pSimComponent);
  v7 = v2->m_pOwner.m_pPointer;
  v8 = v5->mWorldTransform.v3.y - *((float *)&v6[2].m_BoundComponentHandles.mNode.mPrev + 1);
  v9 = v5->mWorldTransform.v3.x - *(float *)&v6[2].m_BoundComponentHandles.mNode.mPrev;
  v10 = 0;
  v11 = (float)(v8 * v8) + (float)(v9 * v9);
  if ( v7 )
    v12 = *(_QWORD *)&v7[2].m_TypeUID;
  else
    v12 = 0i64;
  v13 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v12 + 96) + 30i64) + *(_QWORD *)(v12 + 88) + 40);
  v14 = UFG::AttackRightsComponent::s_MaxAttackRanges[v2->m_AttackType];
  if ( v7 )
    v15 = (UFG::HealthComponent *)v7[4].m_pSimObject;
  else
    v15 = 0i64;
  if ( v7 )
    v16 = *(UFG::ActionTreeComponent **)&v7[5].m_TypeUID;
  else
    v16 = 0i64;
  v17 = UFG::IsDowned(v16, v15);
  v18 = v2->m_pOwner.m_pPointer;
  v19 = v17;
  if ( v18 )
    v20 = *(UFG::ActionTreeComponent **)&v18[5].m_TypeUID;
  else
    v20 = 0i64;
  v21 = UFG::IsStunned(v20);
  if ( !v19 && !v21 && v11 <= (float)(v14 * v14) && v13 == v3->m_pSimObject )
    v10 = 1;
  return v10;
}

// File Line: 981
// RVA: 0x394300
void __fastcall UFG::AttackRightsComponent::UpdateAttackSlotLists(UFG::AttackRightsComponent *this, UFG::eAttackType attack_type)
{
  float v2; // xmm1_4
  UFG::AttackRightsComponent *v3; // rbx
  __int64 v4; // rbp
  signed __int64 v5; // r10
  int v6; // er9
  UFG::HasAttackRequestNode **v7; // r8
  UFG::HasAttackRequestNode *v8; // rax
  __int64 v9; // rcx
  _QWORD *v10; // rax
  __int64 *v11; // rax
  signed __int64 v12; // rcx
  signed __int64 v13; // r15
  int v14; // edi
  UFG::HasAttackRequestNode **v15; // rsi
  UFG::HasAttackRequestNode *v16; // r14
  int v17; // eax
  signed int *v18; // r8
  __int64 v19; // rcx
  signed __int64 v20; // rdx
  signed int v21; // eax
  signed int v22; // ecx
  int v23; // eax
  signed __int64 v24; // r11
  __int64 *v25; // rsi
  int v26; // edi
  int v27; // er9
  __int64 *v28; // r10
  __int64 *v29; // rdx
  __int64 v30; // r8
  __int64 v31; // rcx
  _QWORD *v32; // rax
  __int64 v33; // rax
  signed __int64 v34; // r15
  UFG::HasAttackRequestNode *v35; // rsi
  signed __int64 v36; // r14
  int v37; // eax
  __int64 v38; // r8
  __int64 v39; // r9
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v40; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v41; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v42; // rdx
  signed __int64 v43; // rdx
  bool v44; // zf
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v45; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v46; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v47; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v48; // rax
  __int64 v49[128]; // [rsp+20h] [rbp-428h]
  __int64 v50; // [rsp+450h] [rbp+8h]

  v2 = UFG::Metrics::msInstance.mSimTime_Temp;
  v3 = this;
  v4 = (signed int)attack_type;
  v5 = 0i64;
  do
  {
    v6 = 0;
    if ( v3->m_NumAttackSlots[attack_type] > 0 )
    {
      v7 = &v3->m_pAttackSlot[0][0][0].m_pPointer + 192 * (v5 + 2i64 * (signed int)attack_type);
      do
      {
        v8 = *v7;
        if ( *v7
          && !v8->m_CurrentlyAttacking
          && (float)(v2 - v8->m_TimeFinishedAttacking) > 0.5
          && (float)(v2 - v8->m_LastTimePolled) > 7.0 )
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
      while ( v6 < v3->m_NumAttackSlots[attack_type] );
    }
    ++v5;
  }
  while ( v5 < 2 );
  v11 = v49;
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
  v50 = 0i64;
  v13 = 0i64;
  do
  {
    v14 = 0;
    if ( v3->m_NumAttackSlots[v4] > 0 )
    {
      v15 = &v3->m_pAttackSlot[0][0][0].m_pPointer + 192 * (v13 + 2 * v4);
      do
      {
        v16 = *v15;
        if ( *v15 )
        {
          v17 = UFG::AttackRightsComponent::GetCorrectAttackSlotList(v3, *v15);
          v18 = (signed int *)((char *)&v50 + 4 * v17);
          v19 = *v18;
          v20 = v19 + ((signed __int64)v17 << 6);
          v21 = v19 + 1;
          v22 = 63;
          v49[v20] = (__int64)v16;
          if ( v21 < 63 )
            v22 = v21;
          *v18 = v22;
        }
        ++v14;
        v15 += 3;
      }
      while ( v14 < v3->m_NumAttackSlots[v4] );
    }
    ++v13;
  }
  while ( v13 < 2 );
  v23 = v3->m_NumAttackSlots[v4];
  v24 = 0i64;
  v25 = v49;
  v26 = v3->m_NumAttackSlots[v4];
  do
  {
    v27 = 0;
    if ( v23 > 0 )
    {
      v28 = v25;
      v29 = (__int64 *)((char *)v3->m_pAttackSlot + 1536 * (v24 + 2 * v4));
      do
      {
        v30 = *v28;
        if ( v29[2] )
        {
          v31 = *v29;
          v32 = (_QWORD *)v29[1];
          *(_QWORD *)(v31 + 8) = v32;
          *v32 = v31;
          *v29 = (__int64)v29;
          v29[1] = (__int64)v29;
        }
        v29[2] = v30;
        if ( v30 )
        {
          v33 = *(_QWORD *)(v30 + 8);
          --v26;
          *(_QWORD *)(v33 + 8) = v29;
          *v29 = v33;
          v29[1] = v30 + 8;
          *(_QWORD *)(v30 + 8) = v29;
        }
        v23 = v3->m_NumAttackSlots[v4];
        ++v27;
        ++v28;
        v29 += 3;
      }
      while ( v27 < v23 );
    }
    ++v24;
    v25 += 64;
  }
  while ( v24 < 2 );
  v34 = (signed __int64)v3 + 16 * (v4 + 598);
  v35 = (UFG::HasAttackRequestNode *)&(&v3->vfptr)[2 * (v4 + 601)][-5];
  if ( v35 != (UFG::HasAttackRequestNode *)v34 )
  {
    do
    {
      if ( v26 <= 0 )
        break;
      v36 = (signed __int64)&v35->mNext[-3].mNext;
      v37 = UFG::AttackRightsComponent::GetCorrectAttackSlotList(v3, v35);
      if ( v37 != -1 )
      {
        v38 = v37;
        v39 = *((signed int *)&v50 + v37);
        if ( (signed int)v39 < 64 )
        {
          v40 = v35->mPrev;
          v41 = v35->mNext;
          v42 = (UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *)&v35->mPrev;
          v40->mNext = v41;
          v41->mPrev = v40;
          v42->mPrev = v42;
          v42->mNext = v42;
          v43 = v39 + ((v38 + 2 * v4) << 6) + 2 * (v39 + ((v38 + 2 * v4) << 6)) + 11;
          v44 = *((_QWORD *)&v3->m_SafePointerList.mNode.mNext + v43) == 0i64;
          v45 = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&(&v3->vfptr)[v43];
          if ( !v44 )
          {
            v46 = v45->mPrev;
            v47 = v45->mNext;
            v46->mNext = v47;
            v47->mPrev = v46;
            v45->mPrev = v45;
            v45->mNext = v45;
          }
          v45[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v35;
          v48 = v35->m_SafePointerList.mNode.mPrev;
          v48->mNext = v45;
          v45->mPrev = v48;
          v45->mNext = &v35->m_SafePointerList.mNode;
          --v26;
          *((_DWORD *)&v50 + v38) = v39 + 1;
          v35->m_SafePointerList.mNode.mPrev = v45;
        }
      }
      v35 = (UFG::HasAttackRequestNode *)v36;
    }
    while ( v36 != v34 );
  }
}

// File Line: 1102
// RVA: 0x3965B0
void __fastcall UFG::AttackRightsComponent::UpdateFrustum(float a1)
{
  UFG::BaseCameraComponent *v1; // rax
  UFG::BaseCameraComponent *v2; // rdi
  float v3; // xmm6_4
  float v4; // xmm9_4
  float *v5; // rbx
  UFG::BaseCameraComponent *v6; // rax
  float *v7; // rax
  float v8; // xmm0_4
  float v9; // xmm8_4
  UFG::BaseCameraComponent *v10; // rcx
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  UFG::qMatrix44 *v14; // rax
  float v15; // xmm10_4
  float v16; // xmm9_4
  float v17; // ST44_4
  float v18; // xmm11_4
  float v19; // xmm15_4
  float v20; // xmm14_4
  float v21; // xmm13_4
  float v22; // ST3C_4
  float v23; // ST40_4
  float v24; // ST30_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm6_4
  float v28; // xmm4_4
  float v29; // xmm0_4
  __m128 v30; // xmm2
  float v31; // xmm0_4
  __m128 v32; // xmm2
  float v33; // xmm4_4
  float v34; // xmm6_4
  float v35; // xmm0_4
  __m128 v36; // xmm2
  float v37; // xmm7_4
  UFG::qMatrix44 result; // [rsp+50h] [rbp-138h]
  UFG::qMatrix44 dest; // [rsp+90h] [rbp-F8h]
  float v40; // [rsp+190h] [rbp+8h]
  float v41; // [rsp+190h] [rbp+8h]

  if ( UFG::Metrics::msInstance.mSimFrameCount != UFG::AttackRightsComponent::s_FrustumPlanesLastUpdateFrame )
  {
    UFG::AttackRightsComponent::s_FrustumPlanesLastUpdateFrame = UFG::Metrics::msInstance.mSimFrameCount;
    v1 = UFG::GetCurrentBaseCamera();
    v2 = v1;
    if ( v1 )
    {
      ((void (__fastcall *)(UFG::BaseCameraComponent *))v1->vfptr[19].__vecDelDtor)(v1);
      v3 = a1 - UFG::AttackRightsComponent::s_OnScreenTestFOVReduction;
      if ( (float)(a1 - UFG::AttackRightsComponent::s_OnScreenTestFOVReduction) <= 0.0 )
        v3 = 0.0;
      v4 = Render::GetDisplayAspectRatio();
      v5 = 0i64;
      v6 = UFG::Director::Get()->mCurrentCamera;
      if ( v6 )
        v7 = &v6->mCamera.mFOVOffset;
      else
        v7 = 0i64;
      v8 = v7[58];
      if ( v8 == 0.0 || v8 == v7[59] )
        v9 = v40;
      else
        v9 = v7[62] / v8;
      v10 = UFG::Director::Get()->mCurrentCamera;
      if ( v10 )
        v5 = &v10->mCamera.mFOVOffset;
      v11 = v5[58];
      v12 = v5[59];
      if ( v11 == 0.0 || v11 == v12 )
        v13 = v40;
      else
        v13 = (float)(v5[62] - v5[63]) / (float)(v11 - v12);
      UFG::qPerspectiveMatrix(&dest, v3, v4, v9, v13 - 1.0);
      v14 = UFG::Camera::GetWorldView(&v2->mCamera);
      UFG::qMatrix44::operator*(v14, &result, &dest);
      LODWORD(v15) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
      LODWORD(v16) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
      LODWORD(v41) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
      LODWORD(v17) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
      LODWORD(v18) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
      LODWORD(v19) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
      LODWORD(v20) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
      LODWORD(v21) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
      LODWORD(v22) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
      LODWORD(v23) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
      LODWORD(v24) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
      v25 = fsqrt(
              (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                    + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
            + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
      UFG::AttackRightsComponent::s_FrustumPlanes[0].x = COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])
                                                       * (float)(1.0 / v25);
      *(float *)&dword_1423BA854 = COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * (float)(1.0 / v25);
      *(float *)&dword_1423BA858 = COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * (float)(1.0 / v25);
      *(float *)&dword_1423BA85C = COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]) * (float)(1.0 / v25);
      v26 = fsqrt((float)((float)(v15 * v15) + (float)(v18 * v18)) + (float)(v16 * v16));
      LODWORD(v27) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
      LODWORD(v28) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
      *(float *)&dword_1423BA860 = v18 * (float)(1.0 / v26);
      *(float *)&dword_1423BA864 = v15 * (float)(1.0 / v26);
      *(float *)&dword_1423BA868 = v16 * (float)(1.0 / v26);
      *(float *)&dword_1423BA86C = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0])
                                 * (float)(1.0 / v26);
      v29 = fsqrt((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v21 * v21));
      v30 = (__m128)LODWORD(v41);
      *(float *)&dword_1423BA870 = v19 * (float)(1.0 / v29);
      *(float *)&dword_1423BA874 = v20 * (float)(1.0 / v29);
      v30.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v27 * v27)) + (float)(v28 * v28);
      *(float *)&dword_1423BA878 = v21 * (float)(1.0 / v29);
      *(float *)&dword_1423BA87C = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0])
                                 * (float)(1.0 / v29);
      LODWORD(v31) = (unsigned __int128)_mm_sqrt_ps(v30);
      *(float *)&dword_1423BA88C = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0])
                                 * (float)(1.0 / v31);
      *(float *)&dword_1423BA884 = v41 * (float)(1.0 / v31);
      v32 = (__m128)LODWORD(v22);
      *(float *)&dword_1423BA888 = v28 * (float)(1.0 / v31);
      LODWORD(v33) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
      *(float *)&dword_1423BA880 = v27 * (float)(1.0 / v31);
      LODWORD(v34) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
      v32.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v34 * v34)) + (float)(v33 * v33);
      LODWORD(v35) = (unsigned __int128)_mm_sqrt_ps(v32);
      *(float *)&dword_1423BA89C = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0])
                                 * (float)(1.0 / v35);
      *(float *)&dword_1423BA894 = v22 * (float)(1.0 / v35);
      v36 = (__m128)LODWORD(v17);
      *(float *)&dword_1423BA898 = v33 * (float)(1.0 / v35);
      *(float *)&dword_1423BA890 = v34 * (float)(1.0 / v35);
      v36.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v23 * v23)) + (float)(v24 * v24);
      v37 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v36));
      *(float *)&dword_1423BA8A4 = v17 * v37;
      *(float *)&dword_1423BA8A8 = v24 * v37;
      *(float *)&dword_1423BA8AC = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]) * v37;
      *(float *)&dword_1423BA8A0 = v37 * v23;
    }
  }
}

// File Line: 1152
// RVA: 0x35B630
signed __int64 __fastcall UFG::AttackRightsComponent::GetCorrectAttackSlotList(UFG::AttackRightsComponent *this, UFG::HasAttackRequestNode *attacker)
{
  UFG::SimComponent *v2; // rax
  float *v3; // rbx
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm6_4
  int v7; // ebx
  int v8; // eax
  UFG::qVector3 pos; // [rsp+20h] [rbp-38h]
  UFG::qVector3 v11; // [rsp+30h] [rbp-28h]

  v2 = attacker->m_pOwner.m_pPointer;
  if ( !v2 )
    return 0xFFFFFFFFi64;
  v3 = (float *)v2[3].m_BoundComponentHandles.mNode.mNext;
  if ( !v3 )
    return 0xFFFFFFFFi64;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2[3].m_BoundComponentHandles.mNode.mNext);
  v4 = v3[44];
  v5 = v3[45];
  v6 = UFG::AttackRightsComponent::s_OnScreenTestHeadSphereRadius;
  pos.z = v3[46];
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
void __fastcall UFG::AttackRightsComponent::SetAllowedToUseAttackSlotLists(UFG::AttackRightsComponent *this, UFG::eAttackType attack_type)
{
  float v2; // xmm7_4
  __int64 v3; // rdi
  UFG::AttackRightsComponent *v4; // rbx
  float v5; // xmm0_4
  int v6; // er9
  int v7; // edx
  UFG::HasAttackRequestNode **v8; // rcx

  v2 = UFG::Metrics::msInstance.mSimTime_Temp;
  v3 = (signed int)attack_type;
  v4 = this;
  if ( attack_type )
  {
    if ( UFG::Metrics::msInstance.mSimTime_Temp <= this->m_NextTimeToUpdateAllowedToUseAttackSlotList[attack_type] )
      goto LABEL_9;
    this->m_AllowedToUseAttackSlotList[attack_type][0] = 1;
    this->m_AllowedToUseAttackSlotList[attack_type][1] = UFG::qRandom(1.0, &UFG::qDefaultSeed) < 0.2;
    v5 = UFG::qRandom(1.0, &UFG::qDefaultSeed) + 3.0;
    if ( v5 <= 3.0 )
    {
      v5 = FLOAT_3_0;
    }
    else if ( v5 >= 4.0 )
    {
      v4->m_NextTimeToUpdateAllowedToUseAttackSlotList[v3] = v2 + 4.0;
      goto LABEL_9;
    }
    v4->m_NextTimeToUpdateAllowedToUseAttackSlotList[v3] = v5 + v2;
  }
  else
  {
    *(_WORD *)&this->m_AllowedToUseAttackSlotList[0][0] = 257;
    this->m_NextTimeToUpdateAllowedToUseAttackSlotList[0] = -99999.0;
  }
LABEL_9:
  *(_WORD *)&v4->m_OverrideAllowedToUseAttackSlotListThisFrame[v3][0] = 256;
  v6 = v4->m_NumAttackSlots[v3];
  v7 = 0;
  if ( v6 > 0 )
  {
    v8 = &v4->m_pAttackSlot[0][0][0].m_pPointer + 384 * v3;
    while ( !*v8 )
    {
      ++v7;
      v8 += 3;
      if ( v7 >= v6 )
        return;
    }
    v4->m_OverrideAllowedToUseAttackSlotListThisFrame[v3][1] = 0;
  }
}

// File Line: 1229
// RVA: 0x3883D0
void __fastcall UFG::AttackRightsComponent::SortAttackSlots(UFG::AttackRightsComponent *this, UFG::eAttackType attack_type)
{
  UFG::AttackRightsComponent *v2; // r15
  UFG::TransformNodeComponent *v3; // rcx
  UFG::HasAttackRequestNode **v4; // rsi
  signed __int64 v5; // r12
  int (*v6)[2]; // r13
  __int64 v7; // r14
  __int64 v8; // rbx
  UFG::HasAttackRequestNode *v9; // rdi
  float v10; // xmm0_4
  signed int v11; // edi
  unsigned int v12; // er14
  char v13; // r8
  __int64 v14; // r9
  __int64 v15; // rbx
  float v16; // xmm1_4
  int v17; // xmm0_4
  bool v18; // al
  UFG::HasAttackRequestNode *v19; // r10
  signed __int64 v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v21; // rdx
  signed __int64 v22; // r11
  UFG::HasAttackRequestNode *v23; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v30; // rax
  int v31; // [rsp+20h] [rbp-138h]
  int v32[63]; // [rsp+24h] [rbp-134h]
  signed __int64 v33; // [rsp+170h] [rbp+18h]

  v2 = this;
  if ( attack_type == eATTACK_TYPE_MELEE && UFG::BattleManager::s_pInstance->m_CurrentBattleType == eBATTLE_TYPE_NORMAL )
  {
    v3 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    if ( v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v3);
      v4 = &v2->m_pAttackSlot[0][0][0].m_pPointer;
      v33 = (signed __int64)&v2->m_pAttackSlot[0][0][0].m_pPointer;
      v5 = 0i64;
      v6 = v2->m_NextAttackBaton;
      do
      {
        v7 = v2->m_NumAttackSlots[0];
        v8 = 0i64;
        if ( (signed int)v7 > 0 )
        {
          do
          {
            v9 = *v4;
            v10 = UFG::AttackRightsComponent::GetAttackerScore(v2, *v4, 0i64);
            *((float *)&v31 + v8) = v10;
            if ( v9 )
              v9->m_Score = v10;
            ++v8;
            v4 += 3;
          }
          while ( v8 < v7 );
          v4 = (UFG::HasAttackRequestNode **)v33;
        }
        v11 = 0;
        v12 = v7 - 1;
        do
        {
          v13 = 0;
          v14 = 0i64;
          if ( (signed int)v12 > 0 )
          {
            v15 = v12;
            do
            {
              v16 = *((float *)&v31 + v14);
              v17 = v32[v14];
              v18 = v16 >= 0.0 && *(float *)&v17 >= 0.0;
              if ( v16 < *(float *)&v17 && v18 || v16 < 0.0 && *(float *)&v17 >= 0.0 )
              {
                *(&v31 + v14) = v17;
                *(float *)&v32[v14] = v16;
                v19 = v2->m_pAttackSlot[0][0][v14 + v5].m_pPointer;
                v20 = v14 + v5 + 1;
                v21 = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)((char *)v2->m_pAttackSlot + 24 * (v14 + v5));
                v22 = 3 * v20;
                v23 = v2->m_pAttackSlot[0][0][v20].m_pPointer;
                if ( v21[1].mPrev )
                {
                  v24 = v21->mPrev;
                  v25 = v21->mNext;
                  v24->mNext = v25;
                  v25->mPrev = v24;
                  v21->mPrev = v21;
                  v21->mNext = v21;
                }
                v21[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v23;
                if ( v23 )
                {
                  v26 = v23->m_SafePointerList.mNode.mPrev;
                  v26->mNext = v21;
                  v21->mPrev = v26;
                  v21->mNext = &v23->m_SafePointerList.mNode;
                  v23->m_SafePointerList.mNode.mPrev = v21;
                }
                v27 = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)((char *)v2->m_pAttackSlot + 8 * v22);
                if ( v27[1].mPrev )
                {
                  v28 = v27->mPrev;
                  v29 = v27->mNext;
                  v28->mNext = v29;
                  v29->mPrev = v28;
                  v27->mPrev = v27;
                  v27->mNext = v27;
                }
                v27[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v19;
                if ( v19 )
                {
                  v30 = v19->m_SafePointerList.mNode.mPrev;
                  v30->mNext = v27;
                  v27->mPrev = v30;
                  v27->mNext = &v19->m_SafePointerList.mNode;
                  v19->m_SafePointerList.mNode.mPrev = v27;
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
        v4 += 192;
        v5 += 64i64;
        *(_DWORD *)v6 = 0;
        v6 = (int (*)[2])((char *)v6 + 4);
        v33 = (signed __int64)v4;
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
float __fastcall UFG::AttackRightsComponent::GetAttackerScore(UFG::AttackRightsComponent *this, UFG::HasAttackRequestNode *attacker, UFG::qString *debug_string)
{
  UFG::qString *v3; // rdi
  UFG::HasAttackRequestNode *v4; // r15
  UFG::AttackRightsComponent *v5; // r12
  float v6; // xmm6_4
  __int64 v7; // r13
  UFG::SimComponent *v8; // rax
  UFG::SimObject *v9; // rbp
  UFG::TransformNodeComponent *v10; // r14
  __int64 v11; // rsi
  UFG::SimComponent *v12; // rbx
  __m128 v13; // xmm1
  float v14; // xmm0_4
  UFG::qString *v15; // rax
  UFG::SimComponent *v16; // rax
  UFG::SimObject *v17; // rax
  UFG::qString *v18; // rax
  UFG::SimObjectProp *v19; // rcx
  unsigned __int16 v20; // dx
  UFG::SimObjectWeaponPropertiesComponent *v21; // rax
  UFG::qString *v22; // rax
  UFG::SimComponent *v23; // r14
  signed __int64 v24; // rbx
  signed __int64 i; // r14
  __int64 v26; // rcx
  float v27; // xmm7_4
  char *v28; // rax
  UFG::qString *v29; // rax
  signed __int64 v30; // rcx
  UFG::qString *v31; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v32; // rcx
  UFG::SimComponent *v33; // rax
  UFG::SimObject *v34; // rax
  void *(__fastcall *v35)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rcx
  signed __int64 v37; // [rsp+20h] [rbp-88h]
  UFG::qString v38; // [rsp+28h] [rbp-80h]

  v37 = -2i64;
  v3 = debug_string;
  v4 = attacker;
  v5 = this;
  v6 = FLOAT_N1_0;
  if ( attacker )
  {
    v7 = (signed int)attacker->m_AttackType;
    v8 = attacker->m_pOwner.m_pPointer;
    v9 = 0i64;
    v10 = (UFG::TransformNodeComponent *)(v8 ? v8[3].m_BoundComponentHandles.mNode.mNext : 0i64);
    if ( this->m_pTransformNodeComponent.m_pSimComponent && this->m_pTargetingSystemBaseComponent.m_pSimComponent && v10 )
    {
      if ( v8 )
        v11 = *(_QWORD *)&v8[2].m_TypeUID;
      else
        v11 = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v10);
      v12 = v5->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent);
      v13 = (__m128)LODWORD(v12[2].m_BoundComponentHandles.mNode.mPrev);
      v14 = *((float *)&v12[2].m_BoundComponentHandles.mNode.mPrev + 1) - v10->mWorldTransform.v3.y;
      v13.m128_f32[0] = (float)((float)(v13.m128_f32[0] - v10->mWorldTransform.v3.x)
                              * (float)(v13.m128_f32[0] - v10->mWorldTransform.v3.x))
                      + (float)(v14 * v14);
      v6 = MAX_DISTANCE - COERCE_FLOAT(_mm_sqrt_ps(v13));
      if ( v6 <= 0.0 )
        v6 = 0.0;
      if ( v3 )
      {
        UFG::qString::qString(&v38, "\nDistance score: %.1f", v6);
        UFG::qString::operator+=(v3, v15);
        UFG::qString::~qString(&v38);
      }
      v16 = v4->m_pOwner.m_pPointer;
      if ( v16 )
        v17 = v16->m_pSimObject;
      else
        v17 = 0i64;
      if ( v17 == *(UFG::SimObject **)(56i64
                                     * *(unsigned __int8 *)(*(_QWORD *)&v5->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags
                                                          + 30i64)
                                     + *(_QWORD *)&v5->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
                                     + 40) )
      {
        v6 = v6 + CURRENT_TARGET_BONUS;
        if ( v3 )
        {
          UFG::qString::qString(&v38, "\nCurrent target bonus: %.1f", CURRENT_TARGET_BONUS);
          UFG::qString::operator+=(v3, v18);
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
          v20 = v19->m_Flags;
          if ( (v20 >> 14) & 1 )
          {
            v21 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v19->vfptr,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          }
          else if ( (v20 & 0x8000u) == 0 )
          {
            if ( (v20 >> 13) & 1 )
              v21 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v19);
            else
              v21 = (UFG::SimObjectWeaponPropertiesComponent *)((v20 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                    (UFG::SimObjectGame *)&v19->vfptr,
                                                                                    UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v19->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
          }
          else
          {
            v21 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v19->vfptr,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          }
          if ( v21 )
          {
            if ( v21->mWeaponTypeInfo->mFireModes[v21->mFireMode]->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID )
            {
              v6 = v6 + MELEE_WEAPON_BONUS;
              if ( v3 )
              {
                UFG::qString::qString(&v38, "\nMelee weapon bonus: %.1f", MELEE_WEAPON_BONUS);
                UFG::qString::operator+=(v3, v22);
                UFG::qString::~qString(&v38);
              }
            }
          }
        }
      }
      v23 = v4->m_pOwner.m_pPointer;
      if ( v23 )
      {
        v24 = (signed __int64)&v23[1].m_pSimObject[-1].m_pTransformNodeComponent;
        for ( i = (signed __int64)&v23->m_BoundComponentHandles.mNode.mNext; v24 != i; v24 = *(_QWORD *)(v24 + 48)
                                                                                           - 40i64 )
        {
          v26 = *(_QWORD *)(v24 + 24);
          v27 = *(float *)(v26 + 56);
          if ( v3 )
          {
            v28 = ActionPath::GetString_DBG((ActionPath *)(v26 + 64));
            UFG::qString::qString(&v38, "\nAttackRightsScoreBonusTrack: %.1f from %s", v27, v28, v37);
            UFG::qString::operator+=(v3, v29);
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
            if ( v3 )
            {
              UFG::qString::qString(&v38, "\nZeroed out because in grapple");
              UFG::qString::operator+=(v3, v31);
              UFG::qString::~qString(&v38);
            }
          }
        }
      }
      v32 = (&v5->vfptr)[3 * (v7 + 394)];
      if ( v32 )
      {
        v33 = v4->m_pOwner.m_pPointer;
        if ( v33 )
          v34 = v33->m_pSimObject;
        else
          v34 = 0i64;
        v35 = v32[27].__vecDelDtor;
        if ( v35 )
          v9 = (UFG::SimObject *)*((_QWORD *)v35 + 5);
        if ( v34 == v9 )
        {
          if ( v6 >= 0.0 )
            v6 = 0.0;
          if ( v3 )
          {
            UFG::qString::operator+=(v3, "\nZeroed out because was last attacker");
            if ( v6 < 0.0 )
              UFG::qString::operator+=(v3, " (left as negative though)");
          }
        }
      }
    }
  }
  return v6;
}

// File Line: 1438
// RVA: 0x381280
void __fastcall UFG::AttackRightsComponent::RemoveAttackSlotGuysFromTheQueue(UFG::AttackRightsComponent *this)
{
  UFG::AttackRightsComponent *v1; // r11
  signed __int64 v2; // rbx
  int *v3; // rdi
  signed __int64 v4; // r10
  __int64 v5; // r9
  UFG::HasAttackRequestNode **v6; // r8
  UFG::HasAttackRequestNode *v7; // rdx
  signed __int64 v8; // rcx
  signed __int64 i; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v10; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v11; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v12; // rdx

  v1 = this;
  v2 = 0i64;
  v3 = this->m_NumAttackSlots;
  do
  {
    v4 = 0i64;
    do
    {
      v5 = *v3;
      if ( v5 > 0 )
      {
        v6 = &v1->m_pAttackSlot[0][0][0].m_pPointer + 192 * (v2 + v4);
        do
        {
          v7 = *v6;
          if ( *v6 )
          {
            v8 = (signed __int64)(&v1->m_RunningAttacksEnabled + 16 * (signed int)v7->m_AttackType);
            for ( i = (signed __int64)&v1->m_AttackSlotQueue[v7->m_AttackType].mNode.mNext[-3].mNext;
                  i != v8;
                  i = *(_QWORD *)(i + 48) - 40i64 )
            {
              if ( (UFG::HasAttackRequestNode *)i == v7 )
                break;
            }
            v10 = v7->mPrev;
            v11 = v7->mNext;
            v12 = (UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *)&v7->mPrev;
            v10->mNext = v11;
            v11->mPrev = v10;
            v12->mPrev = v12;
            v12->mNext = v12;
          }
          v6 += 3;
          --v5;
        }
        while ( v5 );
      }
      ++v4;
    }
    while ( v4 < 2 );
    v2 += 2i64;
    ++v3;
  }
  while ( v2 < 6 );
}

// File Line: 1468
// RVA: 0x3980D0
void __fastcall UFG::AttackRightsComponent::UpdatePreviousBestAttacker(UFG::AttackRightsComponent *this)
{
  float v1; // xmm9_4
  int (*v2)[2]; // rax
  UFG::AttackRightsComponent *v3; // r14
  signed __int64 v4; // r13
  float *v5; // rbp
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v6; // r12
  int v7; // er15
  signed __int64 v8; // rsi
  signed __int64 v9; // r10
  int *v10; // rdi
  int v11; // ecx
  int v12; // er8
  UFG::HasAttackRequestNode *v13; // r9
  bool v14; // zf
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v17; // rax
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm0_4
  int (*v21)[2]; // [rsp+98h] [rbp+10h]

  v1 = UFG::Metrics::msInstance.mSimTime_Temp;
  v2 = this->m_NextAttackBaton;
  v3 = this;
  v4 = 0i64;
  v5 = this->m_NextTimeToUpdatePreviousBestAttacker;
  v6 = this->m_pPreviousBestAttacker;
  v21 = this->m_NextAttackBaton;
  do
  {
    if ( v1 > *v5 )
    {
      v7 = 0;
LABEL_4:
      v8 = 0i64;
      v9 = v4;
      v10 = (int *)v2;
      while ( 1 )
      {
        v11 = *v10;
        v12 = *v10 <= 0 ? *((_DWORD *)v5 - 52) - 1 : v11 - 1;
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
          v2 = v21;
          goto LABEL_4;
        }
      }
      while ( 1 )
      {
        v13 = v3->m_pAttackSlot[0][0][v9 + v11].m_pPointer;
        if ( v13 )
        {
          if ( v13->m_Score >= 0.0 || v7 > 0 )
            break;
        }
        v14 = v11 == v12;
        v11 = (v11 + 1) % *((_DWORD *)v5 - 52);
        if ( v14 )
          goto LABEL_13;
      }
      if ( v6->m_pPointer )
      {
        v15 = v6->mPrev;
        v16 = v6->mNext;
        v15->mNext = v16;
        v16->mPrev = v15;
        v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
        v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      }
      v6->m_pPointer = v13;
      v17 = v13->m_SafePointerList.mNode.mPrev;
      v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mPrev = v17;
      v6->mNext = &v13->m_SafePointerList.mNode;
      v13->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
$done_2:
      v18 = v3->m_MaxTimeBetweenAttackerSwitch;
      v19 = v3->m_MinTimeBetweenAttackerSwitch;
      v20 = v3->m_MaxTimeBetweenAttackerSwitch;
      if ( v18 > v19 )
      {
        v20 = UFG::qRandom(v20 - v19, &UFG::qDefaultSeed) + v19;
        if ( v20 <= v19 )
          v20 = v19;
        if ( v20 >= v18 )
          v20 = v18;
      }
      v2 = v21;
      *v5 = v20 + v1;
    }
    ++v2;
    v4 += 128i64;
    ++v5;
    ++v6;
    v21 = v2;
  }
  while ( v4 < 384 );
}

// File Line: 1543
// RVA: 0x38CD60
void __usercall UFG::AttackRightsComponent::Update(UFG::AttackRightsComponent *this@<rcx>, float delta_sec@<xmm1>, float a3@<xmm0>)
{
  UFG::AttackRightsComponent *v3; // rbx
  UFG::SimObjectCharacter *v4; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v5; // rdx
  void *(__fastcall *v6)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rdx
  UFG::TransformNodeComponent *v7; // rdx
  UFG::HasAttackRequestNode *v8; // rax
  UFG::SimComponent *v9; // rax
  UFG::eAttackType v10; // ebp
  float v11; // xmm6_4
  __int64 v12; // r15
  float *v13; // rsi
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v14; // r14
  signed __int64 v15; // r13
  int v16; // er8
  __int64 v17; // r9
  int v18; // edx
  UFG::HasAttackRequestNode **v19; // rax
  char v20; // al
  char v21; // di
  bool v22; // al
  __int64 v23; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v24; // rax
  float v25; // xmm0_4
  UFG::HasAttackRequestNode *v26; // rax
  UFG::HasAttackRequestNode *v27; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v28; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList,1,0> *v30; // rcx
  UFG::HasAttackRequestNode *v31; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qColour v33; // [rsp+40h] [rbp-88h]
  UFG::AttackSlotInfo next_attack_baton; // [rsp+D0h] [rbp+8h]
  UFG::AttackSlotInfo v35; // [rsp+E0h] [rbp+18h]

  v3 = this;
  v4 = (UFG::SimObjectCharacter *)this->m_pSimObject;
  if ( !v4 || !((v4->m_Flags >> 10) & 1) )
  {
    if ( UFG::AttackRightsComponent::s_ProducerAttackRightsDebug && v4 && v4 == LocalPlayer )
    {
      a3 = v3->m_NextTimeCanPerformOpportunityAttack[UFG::AttackRightsComponent::s_AttackTypeToDebug]
         - UFG::Metrics::msInstance.mSimTime_Temp;
      UFG::DrawDebugText(
        (UFG::TransformNodeComponent *)v3->m_pTransformNodeComponent.m_pSimComponent,
        &UFG::qColour::White,
        "Next %s attack: %.1fs\nNext %s opportunity attack in %.1fs",
        UFG::AttackRightsComponent::s_AttackTypeToDebug,
        (__int64)UFG::AttackTypeNames[UFG::AttackRightsComponent::s_AttackTypeToDebug],
        v3->m_TimeUntilNextAttack[UFG::AttackRightsComponent::s_AttackTypeToDebug],
        UFG::AttackTypeNames[UFG::AttackRightsComponent::s_AttackTypeToDebug],
        a3);
    }
    if ( !v3->m_DebugDrawEnabled )
      goto LABEL_16;
    v5 = (&v3->vfptr)[3 * ((signed int)UFG::AttackRightsComponent::s_AttackTypeToDebug + 428i64)];
    if ( v5 )
    {
      a3 = UFG::qColour::Green.r;
      v6 = v5[27].__vecDelDtor;
      v33 = UFG::qColour::Green;
      if ( v6 )
      {
        v7 = (UFG::TransformNodeComponent *)*((_QWORD *)v6 + 31);
LABEL_15:
        UFG::DrawLine((UFG::TransformNodeComponent *)v3->m_pTransformNodeComponent.m_pSimComponent, v7, &v33, 0.1);
        goto LABEL_16;
      }
    }
    else
    {
      v8 = UFG::AttackRightsComponent::FindNextAttacker(
             v3,
             UFG::AttackRightsComponent::s_AttackTypeToDebug,
             &next_attack_baton);
      if ( !v8 )
      {
LABEL_16:
        UFG::AttackRightsComponent::UpdateFrustum(a3);
        UFG::AttackRightsComponent::RemoveAttackSlotGuysFromTheQueue(v3);
        UFG::AttackRightsComponent::UnregisterUnavailableAttackers(v3);
        UFG::AttackRightsComponent::CheckIfInCombat(v3);
        UFG::AttackRightsComponent::CheckIfDownedStateChanged(v3);
        UFG::AttackRightsComponent::UpdatePreviousBestAttacker(v3);
        v10 = 0;
        v11 = UFG::Metrics::msInstance.mSimTime_Temp;
        v12 = 0i64;
        v13 = v3->m_TimeUntilNextAttack;
        v14 = v3->m_pCachedNextAttacker;
        v15 = (signed __int64)&v3->m_RunningAttacksEnabled;
        while ( 1 )
        {
          *v13 = *v13 - delta_sec;
          UFG::AttackRightsComponent::SetAllowedToUseAttackSlotLists(v3, v10);
          if ( *(_QWORD *)(v15 + 48) - 40i64 == v15 )
          {
            v16 = *((_DWORD *)v13 - 55);
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
            v19 = &v3->m_pAttackSlot[0][0][0].m_pPointer + 192 * (v17 + 2 * v12);
            while ( !*v19 )
            {
              ++v18;
              v19 += 3;
              if ( v18 >= v16 )
                goto LABEL_23;
            }
          }
          v20 = 1;
          if ( (float)(v11 - v13[16]) <= 5.0 )
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
          v13[16] = v11;
LABEL_27:
          v22 = v3->m_AttackingEnabled[v12];
          if ( v10 == 1 )
          {
            if ( !v22 || v3->m_InCombatWithSomeone )
              goto LABEL_55;
          }
          else if ( !v22 )
          {
            goto LABEL_55;
          }
          UFG::AttackRightsComponent::UpdateAttackSlotLists(v3, v10);
          if ( v3->m_CurrentlyAttacking[v12] || !v21 )
            goto LABEL_39;
          v24 = UFG::AttackRightsComponent::GetNextAttacker(v3, v10, v23);
          if ( v24 )
          {
            v25 = UFG::AttackRightsComponent::GetTimeUntilInitialAttack(v3, (UFG::HasAttackRequestNode *)v24);
            if ( !v3->m_IsDowned )
              *v13 = v25;
LABEL_39:
            if ( *v13 <= 0.0 )
            {
              v26 = UFG::AttackRightsComponent::FindNextAttacker(v3, v10, &v35);
              v27 = v26;
              if ( v14->m_pPointer )
              {
                v28 = v14->mPrev;
                v29 = v14->mNext;
                v28->mNext = v29;
                v29->mPrev = v28;
                v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v14->mPrev;
                v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v14->mPrev;
              }
              v14->m_pPointer = v26;
              if ( v26 )
              {
                v30 = &v26->m_SafePointerList;
                v31 = v26;
                v32 = v26->m_SafePointerList.mNode.mPrev;
                v32->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v14->mPrev;
                v14->mNext = &v30->mNode;
                v14->mPrev = v32;
                v30->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v14->mPrev;
                UFG::AttackRightsComponent::MakeAttackRequest(v3, v31, v10);
                if ( v10 || UFG::BattleManager::s_pInstance->m_CurrentBattleType )
                {
                  v3->m_NextAttackBaton[0][(signed int)v35.m_AttackSlotList + 2 * v12] = v35.m_AttackSlot;
                }
                else
                {
                  UFG::AttackRightsComponent::GetAttackSlotInfo(v3, v27, &next_attack_baton);
                  if ( next_attack_baton.m_AttackSlotList != -1 && next_attack_baton.m_AttackSlot != -1 )
                    v3->m_NextAttackBaton[0][(signed int)next_attack_baton.m_AttackSlotList + 2 * v12] = next_attack_baton.m_AttackSlot;
                }
                if ( !v3->m_IsDowned )
                  *v13 = *(float *)((char *)v13 + (char *)TIMEOUT_UNTIL_NEXT_ATTACK - (char *)v3 - 9524);
              }
              else if ( !v3->m_IsDowned )
              {
                *v13 = 0.0;
              }
            }
            goto LABEL_55;
          }
          if ( v3->m_IsDowned )
            goto LABEL_39;
          *v13 = 0.1;
LABEL_55:
          ++v10;
          ++v12;
          v15 += 16i64;
          ++v14;
          ++v13;
          if ( (signed int)v10 >= 3 )
          {
            UFG::AttackRightsComponent::UpdateNextAttacker(v3);
            return;
          }
        }
      }
      a3 = UFG::qColour::Blue.r;
      v9 = v8->m_pOwner.m_pPointer;
      v33 = UFG::qColour::Blue;
      if ( v9 )
      {
        v7 = (UFG::TransformNodeComponent *)v9[3].m_BoundComponentHandles.mNode.mNext;
        goto LABEL_15;
      }
    }
    v7 = 0i64;
    goto LABEL_15;
  }
}

// File Line: 1732
// RVA: 0x3581C0
void __fastcall UFG::AttackRightsComponent::FinishedAttacking(UFG::AttackRightsComponent *this, UFG::HasAttackRequestNode *attacker)
{
  __int64 v2; // r14
  UFG::AttackRightsComponent *v3; // rbx
  UFG::HasAttackRequestNode *v4; // rbp
  signed __int64 v5; // rcx
  bool v6; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v7; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v8; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v9; // rax
  UFG::SimObject *v10; // rsi
  __int64 v11; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v12; // rax
  float v13; // xmm0_4
  UFG::SimObjectCharacter *v14; // rax
  UFG::SimComponent *v15; // rax

  v2 = (signed int)attacker->m_AttackType;
  v3 = this;
  v4 = attacker;
  v5 = v2 + 2 * (v2 + 641);
  v6 = *((_QWORD *)&v3->m_SafePointerList.mNode.mNext + v5) == 0i64;
  v7 = &(&v3->vfptr)[v5];
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
  v3->m_CurrentlyAttacking[v2] = 0;
  UFG::AttackRightsComponent::SortAttackSlots(v3, (UFG::eAttackType)v2);
  v12 = UFG::AttackRightsComponent::GetNextAttacker(v3, (UFG::eAttackType)v2, v11);
  if ( v12 )
  {
    v13 = UFG::AttackRightsComponent::GetTimeUntilNextAttack(v3, v4, (UFG::HasAttackRequestNode *)v12);
    if ( !v3->m_IsDowned )
      goto LABEL_8;
  }
  else if ( !v3->m_IsDowned )
  {
    v13 = UFG::AttackRightsComponent::s_DefaultTimeUntilNextAttack;
LABEL_8:
    v3->m_TimeUntilNextAttack[v2] = v13;
    goto LABEL_9;
  }
LABEL_9:
  if ( UFG::AttackRightsComponent::s_ProducerAttackRightsDebug )
  {
    v14 = (UFG::SimObjectCharacter *)v3->m_pSimObject;
    if ( v14 )
    {
      if ( v14 == LocalPlayer )
      {
        v15 = v4->m_pOwner.m_pPointer;
        if ( v15 )
          v10 = v15->m_pSimObject;
        UFG::UnHighlightSimObject(v10);
      }
    }
  }
}

// File Line: 1771
// RVA: 0x36D320
void __fastcall UFG::AttackRightsComponent::MakeAttackRequest(UFG::AttackRightsComponent *this, UFG::HasAttackRequestNode *attacker, __int64 attack_type)
{
  UFG::HasAttackRequestNode *v3; // r15
  UFG::AttackRightsComponent *v4; // rbp
  __int64 v5; // rbx
  UFG::HasAttackRequestNode *v6; // rcx
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
  UFG::eAttackType v19; // esi
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> **v20; // r14
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v21; // rax
  void *(__fastcall *v22)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rdx
  UFG::SimObject *v23; // rdx
  UFG::HasAttackRequestNode *v24; // rbx
  UFG::SimComponent *v25; // rax
  UFG::SimObject *v26; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v31; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v34; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::SimObjectCharacter *v38; // rax
  UFG::SimComponent *v39; // rax
  UFG::HighlightParams highlight_params; // [rsp+20h] [rbp-38h]

  v3 = attacker;
  v4 = this;
  v5 = (signed int)attack_type;
  if ( !(_DWORD)attack_type )
  {
    v6 = this->m_pLastAttackRequest[0].m_pPointer;
    if ( v6 )
      UFG::HasAttackRequestNode::ClearAttackRequest(v6);
  }
  v4->m_CurrentlyAttacking[v5] = 1;
  if ( (_DWORD)v5 == 2 )
  {
    v14 = 0i64;
    v19 = 0;
    v20 = &v4->m_FollowerAttackSlotQueue[0].mNode.mNext;
    while ( 1 )
    {
      if ( v19 != 2 )
      {
        v21 = UFG::AttackRightsComponent::GetNextAttacker(v4, v19, attack_type);
        if ( v21 && (v22 = v21[27].__vecDelDtor) != 0i64 )
          v23 = (UFG::SimObject *)*((_QWORD *)v22 + 5);
        else
          v23 = 0i64;
        v24 = (UFG::HasAttackRequestNode *)&(*v20)[-4].mNext;
        attack_type = (__int64)v4 + 16 * ((signed int)v19 + 600i64);
        if ( v24 != (UFG::HasAttackRequestNode *)attack_type )
          break;
      }
LABEL_26:
      ++v19;
      v20 += 2;
      if ( (signed int)v19 >= 3 )
        goto LABEL_38;
    }
    while ( 1 )
    {
      v25 = v24->m_pOwner.m_pPointer;
      v26 = v25 ? v25->m_pSimObject : 0i64;
      if ( v26 != v23 )
        break;
      v24 = (UFG::HasAttackRequestNode *)&v24->mNext[-4].mNext;
      if ( v24 == (UFG::HasAttackRequestNode *)attack_type )
        goto LABEL_26;
    }
    UFG::HasAttackRequestNode::RequestAttack(v3, v4, v24);
    v27 = &v24->m_pAttackeeRequest;
    if ( v24->m_pAttackeeRequest.m_pPointer )
    {
      v28 = v27->mPrev;
      v29 = v24->m_pAttackeeRequest.mNext;
      v28->mNext = v29;
      v29->mPrev = v28;
      v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
      v24->m_pAttackeeRequest.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->m_pAttackeeRequest.mPrev;
    }
    v24->m_pAttackeeRequest.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v30 = v4->m_SafePointerList.mNode.mPrev;
      v30->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
      v27->mPrev = v30;
      v24->m_pAttackeeRequest.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    }
    v31 = &v24->m_pSecondaryCharacterRequest;
    if ( v24->m_pSecondaryCharacterRequest.m_pPointer )
    {
      v32 = v31->mPrev;
      v33 = v24->m_pSecondaryCharacterRequest.mNext;
      v32->mNext = v33;
      v33->mPrev = v32;
      v31->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v31->mPrev;
      v24->m_pSecondaryCharacterRequest.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v24->m_pSecondaryCharacterRequest.mPrev;
    }
    v24->m_pSecondaryCharacterRequest.m_pPointer = 0i64;
    v34 = &v4->m_pLastAttackRequest[2];
    v24->m_AttackeeRequestTime = UFG::Metrics::msInstance.mSimTime_Temp;
    if ( v4->m_pLastAttackRequest[2].m_pPointer )
    {
      v35 = v34->mPrev;
      v36 = v4->m_pLastAttackRequest[2].mNext;
      v35->mNext = v36;
      v36->mPrev = v35;
      v34->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v34->mPrev;
      v4->m_pLastAttackRequest[2].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v4->m_pLastAttackRequest[2].mPrev;
    }
    v4->m_pLastAttackRequest[2].m_pPointer = v3;
    if ( v3 )
    {
      v37 = v3->m_SafePointerList.mNode.mPrev;
      v37->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v34->mPrev;
      v34->mPrev = v37;
      v4->m_pLastAttackRequest[2].mNext = &v3->m_SafePointerList.mNode;
      v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v34->mPrev;
    }
  }
  else
  {
    v7 = &v3->m_pAttackeeRequest;
    if ( v3->m_pAttackeeRequest.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v3->m_pAttackeeRequest.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v3->m_pAttackeeRequest.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pAttackeeRequest.mPrev;
    }
    v3->m_pAttackeeRequest.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v3->m_pAttackeeRequest.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
    v11 = &v3->m_pSecondaryCharacterRequest;
    if ( v3->m_pSecondaryCharacterRequest.m_pPointer )
    {
      v12 = v11->mPrev;
      v13 = v3->m_pSecondaryCharacterRequest.mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v11->mPrev;
      v3->m_pSecondaryCharacterRequest.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v3->m_pSecondaryCharacterRequest.mPrev;
    }
    v14 = 0i64;
    v3->m_pSecondaryCharacterRequest.m_pPointer = 0i64;
    v15 = &v4->m_pLastAttackRequest[v5];
    v3->m_AttackeeRequestTime = UFG::Metrics::msInstance.mSimTime_Temp;
    if ( v15->m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v15->mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
    v15->m_pPointer = v3;
    v18 = v3->m_SafePointerList.mNode.mPrev;
    v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v15->mPrev = v18;
    v15->mNext = &v3->m_SafePointerList.mNode;
    v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  }
LABEL_38:
  if ( UFG::AttackRightsComponent::s_ProducerAttackRightsDebug )
  {
    v38 = (UFG::SimObjectCharacter *)v4->m_pSimObject;
    if ( v38 )
    {
      if ( v38 == LocalPlayer )
      {
        v39 = v3->m_pOwner.m_pPointer;
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
UFG::HasAttackRequestNode *__fastcall UFG::AttackRightsComponent::GetCurrentAttacker(UFG::AttackRightsComponent *this, UFG::eAttackType attack_type)
{
  __int64 v2; // r9
  int v3; // er11
  char *v4; // rbx
  __int64 v5; // rdx
  UFG::HasAttackRequestNode *result; // rax

  v2 = (signed int)attack_type;
  v3 = 0;
  v4 = (char *)this + 2 * (signed int)attack_type;
LABEL_2:
  v5 = 0i64;
  while ( 1 )
  {
    if ( v4[v5 + 0x2464] == 1 || this->m_OverrideAllowedToUseAttackSlotListThisFrame[v2][v5] == 1 )
    {
      result = this->m_pAttackSlot[0][v5 + 2 * v2][0].m_pPointer;
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
UFG::qSafePointerNode<UFG::SimComponent>Vtbl *__fastcall UFG::AttackRightsComponent::GetNextAttacker(UFG::AttackRightsComponent *this, UFG::eAttackType attack_type, __int64 a3)
{
  __int64 v3; // rsi
  UFG::AttackRightsComponent *v4; // r14
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v5; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v6; // r15
  void *(__fastcall *v7)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  unsigned int v8; // ebp
  void *(__fastcall *v9)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rcx
  void *(__fastcall *v10)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rdx
  void *(__fastcall *v11)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  UFG::HasAttackRequestNode *v13; // rax
  UFG::HasAttackRequestNode *v14; // r9
  signed __int64 v15; // r8
  bool v16; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v17; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v18; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v19; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList,1,0> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::AttackSlotInfo next_attack_baton; // [rsp+40h] [rbp+8h]

  v3 = (signed int)attack_type;
  v4 = this;
  v5 = (&this->vfptr)[3 * ((signed int)attack_type + 391i64)];
  v6 = &(&this->vfptr)[3 * ((signed int)attack_type + 391i64)];
  if ( v5 )
  {
    if ( attack_type == eATTACK_TYPE_MELEE
      && UFG::BattleManager::s_pInstance->m_CurrentBattleType == eBATTLE_TYPE_NORMAL )
    {
      v7 = v5[27].__vecDelDtor;
      if ( v7 )
      {
        if ( *((_QWORD *)v7 + 25) )
        {
          if ( UFG::Metrics::msInstance.mSimFrameCount )
            v8 = UFG::Metrics::msInstance.mSimFrameCount - 1;
          else
            v8 = -1;
          v9 = v5[17].__vecDelDtor;
          LOBYTE(a3) = 0;
          if ( v9 )
          {
            v10 = v5[14].__vecDelDtor;
            if ( v10 )
              LOBYTE(a3) = (*(__int64 (__fastcall **)(void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int), void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int), __int64))(*(_QWORD *)v9 + 80i64))(
                             v9,
                             v10,
                             a3);
          }
          v11 = v5[27].__vecDelDtor;
          if ( v11 )
            v11 = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))*((_QWORD *)v11 + 25);
          if ( (_BYTE)a3 && *((_BYTE *)v11 + 2097) & 0x10 && LODWORD(v5[12].__vecDelDtor) >= v8 )
            return v5;
        }
      }
    }
  }
  v13 = UFG::AttackRightsComponent::FindNextAttacker(v4, (UFG::eAttackType)v3, &next_attack_baton);
  v14 = v13;
  if ( !v13 )
    return *v6;
  v15 = v3 + 2 * v3 + 1171;
  v16 = *((_QWORD *)&v4->m_SafePointerList.mNode.mNext + v15) == 0i64;
  v17 = &(&v4->vfptr)[v15];
  if ( !v16 )
  {
    v18 = *v17;
    v19 = v17[1];
    v18[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v19;
    v19->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v18;
    *v17 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v17;
    v17[1] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v17;
  }
  v17[2] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v13;
  v20 = &v13->m_SafePointerList;
  v21 = v13->m_SafePointerList.mNode.mPrev;
  v21->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v17;
  *v17 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v21;
  v17[1] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v20;
  v20->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v17;
  return (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v14;
}

// File Line: 1935
// RVA: 0x357720
UFG::HasAttackRequestNode *__fastcall UFG::AttackRightsComponent::FindNextAttacker(UFG::AttackRightsComponent *this, UFG::eAttackType attack_type, UFG::AttackSlotInfo *next_attack_baton)
{
  signed int v3; // er9
  UFG::AttackRightsComponent *v4; // r13
  signed int v5; // er10
  __int64 v6; // rcx
  __int64 v7; // r8
  UFG::HasAttackRequestNode *v8; // r15
  signed int v9; // er12
  signed __int64 i; // rax
  int v11; // esi
  int v12; // er14
  signed __int64 v13; // rcx
  UFG::HasAttackRequestNode *v14; // rbx
  int v15; // ebp
  UFG::SimComponent *v16; // rax
  unsigned int v17; // edi
  CanAttackConditionGroup *v18; // rcx
  char v19; // al
  UFG::SimComponent *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rdx
  bool v22; // zf
  signed int v24; // [rsp+20h] [rbp-68h]
  signed __int64 v25; // [rsp+28h] [rbp-60h]
  __int64 v26; // [rsp+30h] [rbp-58h]
  __int64 v27; // [rsp+38h] [rbp-50h]
  UFG::AttackSlotInfo *v28; // [rsp+A0h] [rbp+18h]
  signed int v29; // [rsp+A8h] [rbp+20h]

  v28 = next_attack_baton;
  v3 = -1;
  v4 = this;
  v5 = 0;
  v6 = 0i64;
  next_attack_baton->m_AttackSlotList = -1;
  next_attack_baton->m_AttackSlot = -1;
  v7 = (signed int)attack_type;
  v8 = 0i64;
  v9 = 0;
  v24 = -1;
  v29 = 0;
  v26 = 0i64;
  v27 = (signed int)attack_type;
  for ( i = (signed __int64)v4->m_AllowedToUseAttackSlotList[attack_type];
        ;
        i = (signed __int64)v4->m_AllowedToUseAttackSlotList[v7] )
  {
    if ( *(_BYTE *)(i + v6) == 1 || v4->m_OverrideAllowedToUseAttackSlotListThisFrame[v7][v6] == 1 )
    {
      v11 = v4->m_NextAttackBaton[0][v6 + 2 * v7];
      v12 = v11 <= 0 ? v4->m_NumAttackSlots[v7] - 1 : v11 - 1;
      if ( v12 != -1 )
      {
        v13 = (v6 + 2 * v7) << 6;
        v25 = v13;
        while ( 1 )
        {
          v14 = v4->m_pAttackSlot[0][0][v13 + v11].m_pPointer;
          v15 = (v11 + 1) % v4->m_NumAttackSlots[v7];
          if ( v14 )
          {
            v16 = v14->m_pOwner.m_pPointer;
            if ( v16 )
            {
              if ( v16[3].m_SafePointerList.mNode.mPrev )
              {
                if ( UFG::Metrics::msInstance.mSimFrameCount )
                  v17 = UFG::Metrics::msInstance.mSimFrameCount - 1;
                else
                  v17 = -1;
                v18 = v14->m_pCanAttackConditions.m_pPointer;
                v19 = 0;
                if ( v18 && v14->m_pActionContextCopy )
                {
                  v19 = ((__int64 (*)(void))v18->vfptr[1].FindWithOldPath)();
                  v7 = v27;
                  v3 = v24;
                  v5 = v29;
                }
                v20 = v14->m_pOwner.m_pPointer;
                if ( v20 )
                  v21 = v20[3].m_SafePointerList.mNode.mPrev;
                else
                  v21 = 0i64;
                if ( v19 && BYTE1(v21[131].mPrev) & 0x10 && v14->m_LastFramePolled >= v17 )
                {
                  if ( v14->m_Score >= 0.0 )
                  {
                    v28->m_AttackSlotList = v9;
                    v28->m_AttackSlot = v15;
                    return v14;
                  }
                  v13 = v25;
                  if ( !v8 )
                  {
                    v5 = v9;
                    v29 = v9;
                    v3 = v15;
                    v24 = v15;
                    v8 = v14;
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
    if ( v9 >= 2 )
      break;
  }
  if ( !v8 )
    return 0i64;
  v28->m_AttackSlotList = v5;
  v28->m_AttackSlot = v3;
  return v8;
}

// File Line: 2002
// RVA: 0x362DB0
float __fastcall UFG::AttackRightsComponent::GetTimeUntilInitialAttack(UFG::AttackRightsComponent *this, UFG::HasAttackRequestNode *attacker)
{
  UFG::SimComponent *v2; // rax
  UFG::HasAttackRequestNode *v3; // rbx
  float v4; // xmm6_4
  UFG::AIScriptInterfaceComponent *v5; // rcx
  float v6; // xmm7_4
  UFG::SimComponent *v7; // rax
  UFG::AIScriptInterfaceComponent *v8; // rcx
  float result; // xmm0_4

  v2 = attacker->m_pOwner.m_pPointer;
  v3 = attacker;
  v4 = 0.0;
  if ( v2 && (v5 = (UFG::AIScriptInterfaceComponent *)v2[3].m_SafePointerList.mNode.mPrev) != 0i64 )
    v6 = UFG::AIScriptInterfaceComponent::GetInitialAttackTimeMin(
           v5,
           attacker->m_AttackType,
           attacker->m_TargetType,
           attacker->m_InCoverType);
  else
    v6 = 0.0;
  v7 = v3->m_pOwner.m_pPointer;
  if ( v7 )
  {
    v8 = (UFG::AIScriptInterfaceComponent *)v7[3].m_SafePointerList.mNode.mPrev;
    if ( v8 )
      v4 = UFG::AIScriptInterfaceComponent::GetInitialAttackTimeMax(
             v8,
             v3->m_AttackType,
             v3->m_TargetType,
             v3->m_InCoverType);
  }
  result = v4;
  if ( v4 > v6 )
  {
    result = UFG::qRandom(v4 - v6, &UFG::qDefaultSeed) + v6;
    if ( result <= v6 )
      result = v6;
    if ( result >= v4 )
      result = v4;
  }
  return result;
}

// File Line: 2014
// RVA: 0x362E60
void __fastcall UFG::AttackRightsComponent::GetTimeUntilNextAttack(UFG::AttackRightsComponent *this, UFG::HasAttackRequestNode *prev_attacker, UFG::HasAttackRequestNode *next_attacker)
{
  UFG::SimComponent *v3; // rax
  UFG::HasAttackRequestNode *v4; // rbx
  UFG::AttackRightsComponent *v5; // rdi
  UFG::AIScriptInterfaceComponent *v6; // rcx
  float v7; // xmm6_4
  UFG::SimComponent *v8; // rax
  UFG::AIScriptInterfaceComponent *v9; // rcx
  float v10; // xmm7_4
  UFG::SimComponent *v11; // rax
  UFG::AIScriptInterfaceComponent *v12; // rcx
  UFG::SimComponent *v13; // rax
  UFG::AIScriptInterfaceComponent *v14; // rcx
  UFG::SimComponent *v15; // rax

  v3 = next_attacker->m_pOwner.m_pPointer;
  v4 = next_attacker;
  v5 = this;
  if ( v3 && (v6 = (UFG::AIScriptInterfaceComponent *)v3[3].m_SafePointerList.mNode.mPrev) != 0i64 )
    v7 = UFG::AIScriptInterfaceComponent::GetAttackTimeMin(
           v6,
           next_attacker->m_AttackType,
           next_attacker->m_TargetType,
           next_attacker->m_InCoverType);
  else
    v7 = 0.0;
  v8 = v4->m_pOwner.m_pPointer;
  if ( v8 && (v9 = (UFG::AIScriptInterfaceComponent *)v8[3].m_SafePointerList.mNode.mPrev) != 0i64 )
    v10 = UFG::AIScriptInterfaceComponent::GetAttackTimeMax(v9, v4->m_AttackType, v4->m_TargetType, v4->m_InCoverType);
  else
    v10 = 0.0;
  if ( UFG::IsDowned(
         (UFG::ActionTreeComponent *)v5->m_pActionTreeComponent.m_pSimComponent,
         (UFG::HealthComponent *)v5->m_pHealthComponent.m_pSimComponent) )
  {
    v11 = v4->m_pOwner.m_pPointer;
    if ( v11 && (v12 = (UFG::AIScriptInterfaceComponent *)v11[3].m_SafePointerList.mNode.mPrev) != 0i64 )
      v7 = UFG::AIScriptInterfaceComponent::GetAttackTimeMinDowned(
             v12,
             v4->m_AttackType,
             v4->m_TargetType,
             v4->m_InCoverType);
    else
      v7 = 0.0;
    v13 = v4->m_pOwner.m_pPointer;
    if ( v13 && (v14 = (UFG::AIScriptInterfaceComponent *)v13[3].m_SafePointerList.mNode.mPrev) != 0i64 )
      v10 = UFG::AIScriptInterfaceComponent::GetAttackTimeMaxDowned(
              v14,
              v4->m_AttackType,
              v4->m_TargetType,
              v4->m_InCoverType);
    else
      v10 = 0.0;
  }
  v15 = v5->m_pHitReactionComponent.m_pSimComponent;
  if ( v15 )
  {
    if ( *(float *)&v15[1].m_TypeUID < 3.0 )
      UFG::GetRandomNumberInRange(v7, v10);
  }
}

// File Line: 2062
// RVA: 0x3971E0
void __fastcall UFG::AttackRightsComponent::UpdateNextAttacker(UFG::AttackRightsComponent *this)
{
  UFG::AttackRightsComponent *v1; // rdi
  __int64 v2; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v3; // rsi
  UFG::HasAttackRequestNode *v4; // rax
  UFG::HasAttackRequestNode *v5; // rbx
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList,1,0> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v13; // rax
  void *(__fastcall *v14)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  UFG::SimComponent *v15; // rax
  unsigned int v16; // ebp
  CanAttackConditionGroup *v17; // rcx
  char v18; // al
  UFG::SimComponent *v19; // rcx
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::AttackSlotInfo next_attack_baton; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( UFG::qRandom(1.0, &UFG::qDefaultSeed) >= 0.5 )
  {
    v3 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)UFG::AttackRightsComponent::FindNextAttacker(
                                                           v1,
                                                           eATTACK_TYPE_RANGED,
                                                           &next_attack_baton);
    if ( v3 )
    {
      v11 = &v1->m_pCachedNextAttacker[1];
      if ( v1->m_pCachedNextAttacker[1].m_pPointer )
      {
        v12 = v11->mPrev;
        v13 = v1->m_pCachedNextAttacker[1].mNext;
        v12->mNext = v13;
        v13->mPrev = v12;
        v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v11->mPrev;
        v1->m_pCachedNextAttacker[1].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v1->m_pCachedNextAttacker[1].mPrev;
      }
      v1->m_pCachedNextAttacker[1].m_pPointer = (UFG::HasAttackRequestNode *)v3;
      v14 = v3[1].__vecDelDtor;
      *((_QWORD *)v14 + 1) = v11;
      v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v14;
      v1->m_pCachedNextAttacker[1].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v3[1];
      v3[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v11;
    }
    else
    {
      v3 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v1->m_pCachedNextAttacker[1].m_pPointer;
    }
    v5 = v1->m_pCachedNextAttacker[0].m_pPointer;
    if ( !v5 )
      goto LABEL_40;
    if ( UFG::BattleManager::s_pInstance->m_CurrentBattleType )
      goto LABEL_40;
    v15 = v5->m_pOwner.m_pPointer;
    if ( !v15 || !v15[3].m_SafePointerList.mNode.mPrev )
      goto LABEL_40;
    if ( UFG::Metrics::msInstance.mSimFrameCount )
      v16 = UFG::Metrics::msInstance.mSimFrameCount - 1;
    else
      v16 = -1;
    v17 = v5->m_pCanAttackConditions.m_pPointer;
    v18 = 0;
    if ( v17 && v5->m_pActionContextCopy )
      v18 = ((__int64 (*)(void))v17->vfptr[1].FindWithOldPath)();
    v19 = v5->m_pOwner.m_pPointer;
    if ( v19 )
      v19 = (UFG::SimComponent *)v19[3].m_SafePointerList.mNode.mPrev;
    if ( !v18 || !(BYTE1(v19[32].m_BoundComponentHandles.mNode.mPrev) & 0x10) || v5->m_LastFramePolled < v16 )
    {
LABEL_40:
      v5 = UFG::AttackRightsComponent::FindNextAttacker(v1, 0, &next_attack_baton);
      if ( v5 )
      {
        v20 = v1->m_pCachedNextAttacker;
        if ( v1->m_pCachedNextAttacker[0].m_pPointer )
        {
          v21 = v20->mPrev;
          v22 = v1->m_pCachedNextAttacker[0].mNext;
          v21->mNext = v22;
          v22->mPrev = v21;
          v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v20->mPrev;
          v1->m_pCachedNextAttacker[0].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)v1->m_pCachedNextAttacker;
        }
        v1->m_pCachedNextAttacker[0].m_pPointer = v5;
        v23 = v5->m_SafePointerList.mNode.mPrev;
        v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v20->mPrev;
        v20->mPrev = v23;
        v1->m_pCachedNextAttacker[0].mNext = &v5->m_SafePointerList.mNode;
        v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v20->mPrev;
      }
      else
      {
        v5 = v1->m_pCachedNextAttacker[0].m_pPointer;
      }
    }
  }
  else
  {
    v3 = UFG::AttackRightsComponent::GetNextAttacker(v1, 0, v2);
    v4 = UFG::AttackRightsComponent::FindNextAttacker(v1, eATTACK_TYPE_RANGED, &next_attack_baton);
    v5 = v4;
    if ( v4 )
    {
      v6 = &v1->m_pCachedNextAttacker[1];
      if ( v1->m_pCachedNextAttacker[1].m_pPointer )
      {
        v7 = v6->mPrev;
        v8 = v1->m_pCachedNextAttacker[1].mNext;
        v7->mNext = v8;
        v8->mPrev = v7;
        v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
        v1->m_pCachedNextAttacker[1].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v1->m_pCachedNextAttacker[1].mPrev;
      }
      v1->m_pCachedNextAttacker[1].m_pPointer = v4;
      v9 = &v4->m_SafePointerList;
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mPrev = v10;
      v1->m_pCachedNextAttacker[1].mNext = &v9->mNode;
      v9->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
    else
    {
      v5 = v1->m_pCachedNextAttacker[1].m_pPointer;
    }
  }
  v24 = &v1->m_pNextAttacker;
  if ( v3 )
    v5 = (UFG::HasAttackRequestNode *)v3;
  if ( v1->m_pNextAttacker.m_pPointer )
  {
    v25 = v24->mPrev;
    v26 = v1->m_pNextAttacker.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    v1->m_pNextAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v1->m_pNextAttacker.mPrev;
  }
  v1->m_pNextAttacker.m_pPointer = v5;
  if ( v5 )
  {
    v27 = v5->m_SafePointerList.mNode.mPrev;
    v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    v24->mPrev = v27;
    v1->m_pNextAttacker.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v24->mPrev;
  }
}t.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNode

// File Line: 2111
// RVA: 0x34F710
void __fastcall UFG::AttackRightsComponent::ClearPreviousBestAttacker(UFG::AttackRightsComponent *this, UFG::eAttackType attack_type)
{
  __int64 v2; // rdi
  UFG::AttackRightsComponent *v3; // rbx
  float v4; // xmm8_4
  signed __int64 v5; // r8
  bool v6; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v7; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v8; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v9; // rax
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm0_4

  v2 = (signed int)attack_type;
  v3 = this;
  v4 = UFG::Metrics::msInstance.mSimTime_Temp;
  v5 = (signed int)attack_type + 2 * ((signed int)attack_type + 590i64);
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
  v10 = this->m_MaxTimeBetweenAttackerSwitch;
  v11 = this->m_MinTimeBetweenAttackerSwitch;
  v12 = this->m_MaxTimeBetweenAttackerSwitch;
  if ( v10 > v11 )
  {
    v12 = UFG::qRandom(v12 - v11, &UFG::qDefaultSeed) + v11;
    if ( v12 <= v11 )
      v12 = v11;
    if ( v12 >= v10 )
      v12 = v10;
  }
  v3->m_NextTimeToUpdatePreviousBestAttacker[v2] = v12 + v4;
}

// File Line: 2137
// RVA: 0x353BA0
void __fastcall UFG::AttackRightsComponent::DrawDebugInfo(UFG::AttackRightsComponent *this, Render::View *view)
{
  Render::View *v2; // r13
  UFG::AttackRightsComponent *v3; // rbx
  Render::DebugDrawManager *v4; // rax
  __int64 v5; // r15
  UFG::HasAttackRequestNode **v6; // r14
  signed __int64 v7; // r12
  UFG::HasAttackRequestNode *v8; // rsi
  UFG::SimComponent *v9; // rbx
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  UFG::qVector4 v14; // xmm2
  __int64 v15; // rsi
  signed __int64 v16; // rbx
  UFG::qVector4 v17; // xmm6
  signed __int64 v18; // r15
  UFG::qVector4 v19; // xmm7
  UFG::qVector4 v20; // xmm8
  UFG::qVector4 v21; // xmm9
  int v22; // xmm0_4
  int v23; // xmm1_4
  __int64 v24; // rdi
  int v25; // xmm0_4
  int v26; // xmm1_4
  float v27; // xmm0_4
  int v28; // xmm1_4
  int v29; // xmm0_4
  int v30; // xmm1_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  __int64 v34; // [rsp+30h] [rbp-B8h]
  __int64 v35; // [rsp+38h] [rbp-B0h]
  __int64 v36; // [rsp+40h] [rbp-A8h]
  __int64 v37; // [rsp+48h] [rbp-A0h]
  UFG::qVector3 v38; // [rsp+50h] [rbp-98h]
  UFG::qVector3 pos; // [rsp+60h] [rbp-88h]
  int v40; // [rsp+6Ch] [rbp-7Ch]
  char info[60]; // [rsp+70h] [rbp-78h]
  float v42; // [rsp+ACh] [rbp-3Ch]
  UFG::qColour v43; // [rsp+B0h] [rbp-38h]
  UFG::qMatrix44 v44; // [rsp+C8h] [rbp-20h]
  UFG::DrawInfo v45; // [rsp+108h] [rbp+20h]
  UFG::qMatrix44 xform; // [rsp+148h] [rbp+60h]
  __int64 v47; // [rsp+208h] [rbp+120h]
  signed __int64 retaddr; // [rsp+218h] [rbp+130h]
  Render::DebugDrawContext *v49; // [rsp+220h] [rbp+138h]

  v2 = view;
  v3 = this;
  if ( this->m_DebugDrawEnabled )
  {
    retaddr = 2i64;
    v4 = Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    v5 = (signed int)UFG::AttackRightsComponent::s_AttackTypeToDebug;
    v49 = (Render::DebugDrawContext *)v4;
    *(float *)&info[44] = UFG::qColour::Red.a;
    v42 = UFG::qColour::Green.a;
    v43 = UFG::qColour::Blue;
    *(float *)&info[48] = UFG::qColour::Green.r;
    *(float *)&info[32] = UFG::qColour::Red.r;
    *(_QWORD *)&info[36] = *(_QWORD *)&UFG::qColour::Red.g;
    *(_QWORD *)&info[52] = *(_QWORD *)&UFG::qColour::Green.g;
    v6 = &v3->m_pAttackSlot[0][0][0].m_pPointer + 384 * (signed int)UFG::AttackRightsComponent::s_AttackTypeToDebug;
    do
    {
      v7 = 64i64;
      do
      {
        v8 = *v6;
        if ( *v6 )
        {
          v9 = v8->m_pOwner.m_pPointer;
          if ( v9 )
            v9 = (UFG::SimComponent *)v9[3].m_BoundComponentHandles.mNode.mNext;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
          Render::DebugDrawContext::DrawPoint(
            v49,
            (UFG::qVector3 *)&v9[2].m_BoundComponentHandles,
            (UFG::qColour *)&info[16 * v5 + 32],
            &UFG::qMatrix44::msIdentity,
            0i64);
          UFG::HasAttackRequestComponent::DrawDebugString((UFG::HasAttackRequestComponent *)v8->m_pOwner.m_pPointer, v2);
          if ( UFG::AttackRightsComponent::s_DebugDrawOnScreenTest )
          {
            v10 = 0.0;
            v11 = 0.0;
            if ( v9 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
              v12 = *(float *)&v9[2].m_BoundComponentHandles.mNode.mPrev;
              v13 = *((float *)&v9[2].m_BoundComponentHandles.mNode.mPrev + 1);
              v10 = UFG::AttackRightsComponent::s_OnScreenTestFootSphereRadius;
              v11 = UFG::AttackRightsComponent::s_OnScreenTestHeadSphereRadius;
              pos.z = *(float *)&v9[2].m_BoundComponentHandles.mNode.mNext;
              pos.x = v12;
              pos.y = v13;
              v38.z = pos.z + UFG::AttackRightsComponent::s_OnScreenTestHeadHeight;
              v38.x = v12;
              v38.y = v13;
            }
            v35 = *(_QWORD *)&UFG::qColour::Red.b;
            v37 = *(_QWORD *)&UFG::qColour::Red.b;
            v34 = *(_QWORD *)&UFG::qColour::Red.r;
            v36 = *(_QWORD *)&UFG::qColour::Red.r;
            if ( IntersectSphereFrustum(UFG::AttackRightsComponent::s_FrustumPlanes, &pos, v10) != 2 )
            {
              v34 = *(_QWORD *)&UFG::qColour::Green.r;
              v35 = *(_QWORD *)&UFG::qColour::Green.b;
            }
            if ( IntersectSphereFrustum(UFG::AttackRightsComponent::s_FrustumPlanes, &v38, v11) != 2 )
            {
              v36 = *(_QWORD *)&UFG::qColour::Green.r;
              v37 = *(_QWORD *)&UFG::qColour::Green.b;
            }
            v14 = 0i64;
            *(_QWORD *)&pos.z = v34;
            v45.mScale = v11 * 2.0;
            *(_QWORD *)&info[8] = v35;
            *(_QWORD *)info = v35;
            *(_QWORD *)&v45.mColour1.r = v36;
            *(_QWORD *)&v45.mColour2.r = v36;
            v14.x = (float)1;
            xform.v0 = v14;
            v44.v0 = v14;
            xform.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v14, (__m128)v14, 81);
            xform.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v14, (__m128)v14, 69);
            *(_DWORD *)&info[12] = 662883558;
            *(_WORD *)&info[16] = 257;
            info[18] = 0;
            *(_QWORD *)&info[24] = 0i64;
            *(_QWORD *)&v45.mColour1.b = v37;
            *(_QWORD *)&v45.mColour2.b = v37;
            v44.v2 = xform.v2;
            v44.v1 = xform.v1;
            v45.mAlphaBlend = 662883558;
            *(_WORD *)&v45.mDepthBuffer = 257;
            v45.mDepthBias = 0;
            v45.mPreDrawCallback = 0i64;
            xform.v3.w = 1.0;
            v44.v3.w = 1.0;
            xform.v3.x = pos.x;
            xform.v3.y = pos.y;
            LODWORD(xform.v3.z) = v34;
            *(UFG::qVector3 *)&v44.v3.x = v38;
            Render::View::DrawSphere(v2, &xform, (UFG::DrawInfo *)info);
            Render::View::DrawSphere(v2, &v44, &v45);
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
      v18 = 2 * v5;
      v19 = (UFG::qVector4)_mm_shuffle_ps((__m128)v17, (__m128)v17, 81);
      v20 = (UFG::qVector4)_mm_shuffle_ps((__m128)v17, (__m128)v17, 69);
      v21 = (UFG::qVector4)_mm_shuffle_ps((__m128)v17, (__m128)v17, 21);
      do
      {
        v22 = *(_DWORD *)&info[8 * v18 + 32];
        v23 = *(_DWORD *)&info[8 * v18 + 36];
        v24 = *(_QWORD *)(v16 + 216);
        *(_DWORD *)&info[8] = 1048576000;
        *(_DWORD *)&info[12] = 662883558;
        *(_WORD *)&info[16] = 257;
        *(_DWORD *)info = v22;
        v25 = *(_DWORD *)&info[8 * v18 + 40];
        *(_DWORD *)&info[4] = v23;
        info[18] = 0;
        *(_QWORD *)&info[24] = 0i64;
        v26 = *(_DWORD *)&info[8 * v18 + 44];
        *(_DWORD *)&info[8] = v25;
        v27 = *(float *)&info[8 * v18 + 32];
        *(_DWORD *)&info[12] = v26;
        v28 = *(_DWORD *)&info[8 * v18 + 36];
        pos.z = v27;
        v29 = *(_DWORD *)&info[8 * v18 + 40];
        v40 = v28;
        v30 = *(_DWORD *)&info[8 * v18 + 44];
        *(_DWORD *)info = v29;
        *(_DWORD *)&info[4] = v30;
        v44.v0 = v17;
        v44.v1 = v19;
        v44.v2 = v20;
        v44.v3 = v21;
        if ( v24 )
          v24 = *(_QWORD *)(v24 + 248);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v24);
        v31 = *(float *)(v24 + 180);
        v32 = *(float *)(v24 + 184);
        v33 = *(float *)(v24 + 176);
        v44.v3.w = 1.0;
        v44.v3.x = v33;
        v44.v3.y = v31;
        v44.v3.z = v32;
        Render::View::DrawSphere(v2, &v44, (UFG::DrawInfo *)info);
        v16 = *(_QWORD *)(v16 + 48) - 40i64;
      }
      while ( v16 != v15 );
    }
    if ( UFG::AttackRightsComponent::s_DebugDrawOnScreenTest )
      Render::View::DrawFrustum(v2, UFG::AttackRightsComponent::s_FrustumPlanes, &UFG::qColour::Red);
  }
}   }
      while ( v16 != v15 );
    }
    if ( UFG::AttackRightsComponent::s_DebugDrawOnScreenTest )
      Render::View::DrawFr

