// File Line: 77
// RVA: 0x154CE50
__int64 UFG::_dynamic_initializer_for__sym_health__()
{
  sym_health.mUID = UFG::qWiseSymbolUIDFromString("health", 0x811C9DC5);
  _((AMD_HD3D *)sym_health.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_health__);
}

// File Line: 112
// RVA: 0x1543EA0
__int64 dynamic_initializer_for__UFG::HealthComponent::s_HealthComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::HealthComponent::s_HealthComponentList__);
}

// File Line: 113
// RVA: 0x532470
const char *__fastcall UFG::HealthComponent::GetTypeName(UFG::HealthComponent *this)
{
  return "HealthComponent";
}

// File Line: 129
// RVA: 0x517950
void __fastcall UFG::HealthComponent::HealthComponent(UFG::HealthComponent *this, unsigned int name_uid, component_Health *dataPtr)
{
  component_Health *v3; // rdi
  UFG::HealthComponent *v4; // rsi
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v5; // rbx
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v6; // rax
  UFG::qList<HealthRegenerateTask,HealthRegenerateTaskList,0,0> *v7; // [rsp+58h] [rbp+20h]

  v3 = dataPtr;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HealthComponent::`vftable;
  v4->m_fHealth = 100.0;
  v4->m_fMinHealth = -1.0;
  v4->m_fMaxHealth = 100.0;
  v4->m_fMaxUpgradedHealth = 100.0;
  v4->m_NonPlayerDamageMultiplier = 1.0;
  v4->m_ProjectileDamageMultiplier = 1.0;
  v4->m_bIsTakingDamage = 1;
  v4->m_fRegenerativeHealthRate = -1.0;
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::RebindingComponentHandle<UFG::HitReactionComponent,0>(&v4->m_HitReactionComponent);
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&v4->m_CharacterAnimationComponent);
  v7 = &v4->m_HealthRegenerateTaskList;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v6 = UFG::HealthComponent::s_HealthComponentList.mNode.mPrev;
  UFG::HealthComponent::s_HealthComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *)&UFG::HealthComponent::s_HealthComponentList;
  UFG::HealthComponent::s_HealthComponentList.mNode.mPrev = (UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::HealthComponent::_HealthComponentTypeUID,
    "HealthComponent");
  UFG::HealthComponent::Reset(v4, v3);
}

// File Line: 168
// RVA: 0x51B980
void __fastcall UFG::HealthComponent::~HealthComponent(UFG::HealthComponent *this)
{
  UFG::HealthComponent *v1; // rdi
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v2; // rbx
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v3; // rcx
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v4; // rax
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v5; // rcx
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HealthComponent::`vftable;
  if ( this == UFG::HealthComponent::s_HealthComponentpCurrentIterator )
    UFG::HealthComponent::s_HealthComponentpCurrentIterator = (UFG::HealthComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&v1->m_HealthRegenerateTaskList);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_CharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_HitReactionComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 191
// RVA: 0x546310
UFG::SimComponent *__fastcall UFG::HealthComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *sceneObject, bool bRequired)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rdx
  unsigned __int16 v13; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h]

  v2 = bRequired;
  v3 = sceneObject;
  v4 = sceneObject->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_Health::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v7 )
      goto LABEL_9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x110ui64, "HealthComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::HealthComponent::HealthComponent((UFG::HealthComponent *)v10, v3->m_NameUID, (component_Health *)v7);
    v6 = v11;
  }
  v12 = v3->m_pSimObject;
  v13 = v12->m_Flags;
  if ( (v13 >> 14) & 1 || (v13 & 0x8000u) != 0 )
    v14 = 6;
  else
    v14 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v15, v12, 1);
  UFG::SimObjectModifier::AttachComponent(&v15, v6, v14);
  UFG::SimObjectModifier::Close(&v15);
  UFG::SimObjectModifier::~SimObjectModifier(&v15);
  return v6;
}

// File Line: 209
// RVA: 0x5496F0
void __fastcall UFG::HealthComponent::Reset(UFG::HealthComponent *this, component_Health *data_ptr)
{
  component_Health *v2; // rdi
  UFG::HealthComponent *v3; // rbx

  v2 = data_ptr;
  v3 = this;
  UFG::qMemSet(this->m_bAttackDir, 0, 4u);
  v3->m_fRegenerativeHealthRatio = 1.0;
  *(_DWORD *)&v3->m_bIsKnockedOut = 16842752;
  v3->m_fTimeOfDeath = -1.0;
  v3->m_fRegenerationDelayS = -1.0;
  *(_WORD *)&v3->m_bHasDeathTouch = 0;
  v3->m_fTimeSinceDamagedS = 1000.0;
  v3->m_fHealthBoost = 0.0;
  if ( v2 && !UFG::IsAnyLocalPlayer(v3->m_pSimObject) )
  {
    v3->m_fMaxUpgradedHealth = (float)v2->maxUpgradedHealth;
    UFG::HealthComponent::SetMaxHealth(v3, v2->maxHealth);
    v3->m_fRegenerativeHealthRate = v2->regenerativeHealthRate;
    v3->m_bIsInvulnerable = v2->InvulnerableCharacter;
    v3->m_ProjectileDamageMultiplier = v2->healthProjectileDamageMultiplier;
  }
  v3->m_fHealth = v3->m_fMaxHealth;
}

// File Line: 251
// RVA: 0x5497A0
void __fastcall UFG::HealthComponent::Reset(UFG::HealthComponent *this)
{
  UFG::HealthComponent *v1; // rbx
  UFG::SceneObjectProperties *v2; // rdx
  UFG::qPropertySet *v3; // rcx
  UFG::qPropertySet *v4; // rax
  char *v5; // rax

  v1 = this;
  v2 = this->m_pSimObject->m_pSceneObj;
  v3 = v2->mpWritableProperties;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v3,
         (UFG::qSymbol *)&component_Health::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v4 )
  {
    v5 = UFG::qPropertySet::GetMemImagePtr(v4);
    UFG::HealthComponent::Reset(v1, (component_Health *)v5);
  }
  else
  {
    UFG::HealthComponent::Reset(v1, 0i64);
  }
}

// File Line: 258
// RVA: 0x53C950
void __fastcall UFG::HealthComponent::LoadHealthSettings(UFG::HealthComponent *this)
{
  UFG::HealthComponent *v1; // rdi
  UFG::GameStatTracker *v2; // rbx
  float v3; // xmm0_4
  float v4; // xmm0_4
  UFG::SimObject *v5; // rcx
  UFG::GameStatTracker *v6; // rax

  v1 = this;
  if ( UFG::IsAnyLocalPlayer(this->m_pSimObject) )
  {
    v2 = UFG::GameStatTracker::Instance();
    v3 = UFG::GameStatTracker::GetStat(v2, MaxHealth);
    UFG::HealthComponent::SetMaxHealth(v1, (signed int)v3);
    v4 = UFG::GameStatTracker::GetStat(v2, RegenHealthRatio);
    if ( v4 <= UFG::HealthComponent::ms_fRegenerativeHealthRatioMin )
      v4 = UFG::HealthComponent::ms_fRegenerativeHealthRatioMin;
    if ( v4 >= 1.0 )
      v4 = *(float *)&FLOAT_1_0;
    v5 = v1->m_pSimObject;
    v1->m_fRegenerativeHealthRatio = v4;
    if ( UFG::IsAnyLocalPlayer(v5) )
    {
      v6 = UFG::GameStatTracker::Instance();
      if ( UFG::GameStatTracker::GetStat(v6, HealthRegen_Activated) >= 0.0 )
        v1->m_fRegenerativeHealthRatio = 1.0;
    }
    UFG::HealthComponent::SetRegenerativeHealthRatio(v1, 1.0, 1);
    UFG::HealthComponent::SetHealth(v1, (signed int)(float)(v1->m_fMaxHealth * v1->m_fRegenerativeHealthRatio), 0i64);
  }
}

// File Line: 272
// RVA: 0x53DEE0
void __fastcall UFG::HealthComponent::OnAttach(UFG::HealthComponent *this, UFG::SimObject *pObject)
{
  UFG::SimObject *v2; // rsi
  UFG::HealthComponent *v3; // rdi
  UFG::SimObject *v4; // r8
  unsigned __int16 v5; // r9
  UFG::SimComponent *v6; // rbx
  unsigned int v7; // ecx
  unsigned int v8; // er9
  UFG::SimComponentHolder *v9; // r11
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *v10; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v15; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::allocator::free_link *v20; // [rsp+40h] [rbp+8h]

  v2 = pObject;
  v3 = this;
  v4 = this->m_pSimObject;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v4->m_Components.p->m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = v4->m_Components.p->m_pComponent;
      }
      else if ( (v5 >> 12) & 1 )
      {
        v7 = (unsigned int)v4[1].vfptr;
        v8 = v4->m_Components.size;
        if ( v7 >= v8 )
        {
LABEL_16:
          v6 = 0i64;
        }
        else
        {
          v9 = v4->m_Components.p;
          while ( (v9[v7].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || UFG::UELComponent::_TypeUID & ~v9[v7].m_TypeUID & 0x1FFFFFF )
          {
            if ( ++v7 >= v8 )
              goto LABEL_16;
          }
          v6 = v9[v7].m_pComponent;
        }
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(this->m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v6 = v4->m_Components.p->m_pComponent;
    }
    if ( v6 )
    {
      v20 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
      v6[2].m_pSimObject = (UFG::SimObject *)v20;
      v20->mNext = (UFG::allocator::free_link *)&v3->m_fHealth;
      v6[2].m_pSimObject->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->m_fMaxHealth;
    }
  }
  v10 = &v3->m_HitReactionComponent;
  if ( v3->m_HitReactionComponent.m_pSimComponent )
  {
    v11 = v10->mPrev;
    v12 = v3->m_HitReactionComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v3->m_HitReactionComponent.m_pSimComponent = 0i64;
LABEL_26:
    v3->m_HitReactionComponent.m_pSimObject = 0i64;
    v3->m_HitReactionComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_HitReactionComponent.mPrev;
    v10->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v10->mPrev;
    goto LABEL_27;
  }
  if ( v3->m_HitReactionComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *)v10->mPrev != v10
     || (UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *)v3->m_HitReactionComponent.mNext != &v3->m_HitReactionComponent) )
  {
    v13 = v10->mPrev;
    v14 = v3->m_HitReactionComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_26;
  }
LABEL_27:
  v3->m_HitReactionComponent.m_Changed = 1;
  v3->m_HitReactionComponent.m_pSimObject = v2;
  v3->m_HitReactionComponent.m_TypeUID = UFG::HitReactionComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_HitReactionComponent,
    v2);
  v15 = &v3->m_CharacterAnimationComponent;
  if ( v3->m_CharacterAnimationComponent.m_pSimComponent )
  {
    v16 = v15->mPrev;
    v17 = v3->m_CharacterAnimationComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v3->m_CharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_33:
    v3->m_CharacterAnimationComponent.m_pSimObject = 0i64;
    v3->m_CharacterAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_CharacterAnimationComponent.mPrev;
    v15->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v15->mPrev;
    goto LABEL_34;
  }
  if ( v3->m_CharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v15->mPrev != v15
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v3->m_CharacterAnimationComponent.mNext != &v3->m_CharacterAnimationComponent) )
  {
    v18 = v15->mPrev;
    v19 = v3->m_CharacterAnimationComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    goto LABEL_33;
  }
LABEL_34:
  v3->m_CharacterAnimationComponent.m_Changed = 1;
  v3->m_CharacterAnimationComponent.m_pSimObject = v2;
  v3->m_CharacterAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_CharacterAnimationComponent,
    v2);
  v3->m_fArmour = 0.0;
}

// File Line: 289
// RVA: 0x540560
void __fastcall UFG::HealthComponent::OnDetach(UFG::HealthComponent *this)
{
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v1; // r8
  UFG::HealthComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::SimObject *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rbx
  unsigned int v15; // er8
  unsigned int v16; // er9
  signed __int64 v17; // rdx

  v1 = &this->m_CharacterAnimationComponent;
  v2 = this;
  if ( this->m_CharacterAnimationComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->m_CharacterAnimationComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->m_CharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_CharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)this->m_CharacterAnimationComponent.mNext != &this->m_CharacterAnimationComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->m_HitReactionComponent;
  v1->m_Changed = 1;
  if ( v2->m_HitReactionComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->m_HitReactionComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->m_HitReactionComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_HitReactionComponent.m_pSimObject = 0i64;
    v2->m_HitReactionComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_HitReactionComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_HitReactionComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *)v2->m_HitReactionComponent.mNext != &v2->m_HitReactionComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->m_HitReactionComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_HitReactionComponent.m_Changed = 1;
  v12 = v2->m_pSimObject;
  if ( v12 )
  {
    v13 = v12->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v14 = v12->m_Components.p->m_pComponent;
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
      {
        v14 = v12->m_Components.p->m_pComponent;
      }
      else if ( (v13 >> 12) & 1 )
      {
        v15 = (unsigned int)v12[1].vfptr;
        v16 = v12->m_Components.size;
        if ( v15 >= v16 )
        {
LABEL_28:
          v14 = 0i64;
        }
        else
        {
          v17 = (signed __int64)&v12->m_Components.p[v15];
          while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF )
          {
            ++v15;
            v17 += 16i64;
            if ( v15 >= v16 )
              goto LABEL_28;
          }
          v14 = *(UFG::SimComponent **)v17;
        }
      }
      else
      {
        v14 = UFG::SimObject::GetComponentOfType(v12, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v14 = v12->m_Components.p->m_pComponent;
    }
    if ( v14 )
    {
      operator delete[](v14[2].m_pSimObject);
      v14[2].m_pSimObject = 0i64;
    }
  }
}

// File Line: 304
// RVA: 0x53F4F0
void __fastcall UFG::HealthComponent::OnDeath(UFG::HealthComponent *this, UFG::HitRecord *pReferenceHitRecord)
{
  UFG::HitRecord *v2; // rbx
  UFG::HealthComponent *v3; // rdi
  UFG::SimObjectCharacter *v4; // rax
  UFG::SimObjectCharacter *v5; // rsi
  bool v6; // di
  int v7; // ecx
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // r8
  const char *v10; // rdx
  unsigned int v11; // ecx
  UFG::allocator::free_link *v12; // rax
  UFG::SimObject *v13; // r8
  unsigned __int16 v14; // cx
  UFG::SimComponent *v15; // rcx
  unsigned int v16; // ecx
  unsigned int v17; // er9
  UFG::SimComponentHolder *v18; // rbx
  __int64 v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // r8
  const char *v22; // rdx
  unsigned int v23; // ecx
  UFG::allocator::free_link *v24; // rax
  UFG::SimObjectProp *v25; // rcx
  unsigned __int16 v26; // dx
  unsigned int v27; // edx
  unsigned int v28; // er9
  UFG::SimComponentHolder *v29; // rbx
  signed __int64 v30; // r8
  UFG::SimObjectWeaponPropertiesComponent *v31; // rax
  unsigned int v32; // edx
  unsigned int v33; // er9
  unsigned int v34; // edx
  unsigned int v35; // er9
  UFG::allocator::free_link *v36; // rax
  const char *v37; // rdx
  unsigned int v38; // ecx
  UFG::allocator::free_link *v39; // rax

  v2 = pReferenceHitRecord;
  v3 = this;
  this->m_fTimeOfDeath = UFG::Metrics::msInstance.mSimTime_Temp;
  v4 = UFG::GetLocalPlayer();
  v5 = v4;
  if ( !v2 || (UFG::SimObjectCharacter *)v3->m_pSimObject == v4 )
    return;
  v6 = v4 == (UFG::SimObjectCharacter *)v2->mAttacker.m_pPointer;
  v7 = v2->mAttackTypeID;
  if ( v7 == gAttackCollisionExplosionNoDamage.m_EnumValue || v7 == gAttackCollisionExplosion.m_EnumValue )
  {
    v8 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
    v9 = v8;
    if ( v8 )
    {
      v10 = UFG::gGameStatEventChannel.mName;
      v11 = UFG::gGameStatEventChannel.mUID;
      v12 = v8 + 1;
      v12->mNext = v12;
      v12[1].mNext = v12;
      v9->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
      LODWORD(v9[3].mNext) = v11;
      v9[4].mNext = (UFG::allocator::free_link *)v10;
      v9->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable;
      LODWORD(v9[7].mNext) = 37;
      v9[8].mNext = (UFG::allocator::free_link *)v5;
    }
    else
    {
      v9 = 0i64;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v9);
  }
  if ( v6 )
  {
    if ( v2->mAttackTypeID == gAttackCollisionProjectile.m_EnumValue )
    {
      v13 = v2->mAttacker.m_pPointer;
      if ( v13 )
      {
        v14 = v13->m_Flags;
        if ( (v14 >> 14) & 1 )
        {
          v15 = v13->m_Components.p[7].m_pComponent;
        }
        else if ( (v14 & 0x8000u) == 0 )
        {
          if ( (v14 >> 13) & 1 )
          {
            v15 = v13->m_Components.p[6].m_pComponent;
          }
          else if ( (v14 >> 12) & 1 )
          {
            v16 = (unsigned int)v13[1].vfptr;
            v17 = v13->m_Components.size;
            if ( v16 >= v17 )
            {
LABEL_26:
              v15 = 0i64;
            }
            else
            {
              v18 = v13->m_Components.p;
              while ( (v18[v16].m_TypeUID & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                   || UFG::ActionTreeComponent::_TypeUID & ~v18[v16].m_TypeUID & 0x1FFFFFF )
              {
                if ( ++v16 >= v17 )
                  goto LABEL_26;
              }
              v15 = v18[v16].m_pComponent;
            }
          }
          else
          {
            v15 = UFG::SimObject::GetComponentOfType(v2->mAttacker.m_pPointer, UFG::ActionTreeComponent::_TypeUID);
          }
        }
        else
        {
          v15 = v13->m_Components.p[7].m_pComponent;
        }
        if ( v15 )
        {
          v19 = *((_QWORD *)&v15[11].m_SafePointerList.mNode.mPrev
                + ((signed __int64)(signed int)gActionRequest_CoverPopoutBlind.m_EnumValue >> 6));
          if ( _bittest64(&v19, gActionRequest_CoverPopoutBlind.m_EnumValue & 0x3F) )
          {
            v20 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
            v21 = v20;
            if ( v20 )
            {
              v22 = UFG::gGameStatEventChannel.mName;
              v23 = UFG::gGameStatEventChannel.mUID;
              v24 = v20 + 1;
              v24->mNext = v24;
              v24[1].mNext = v24;
              v21->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
              LODWORD(v21[3].mNext) = v23;
              v21[4].mNext = (UFG::allocator::free_link *)v22;
              v21->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable;
              LODWORD(v21[7].mNext) = 21;
              v21[8].mNext = (UFG::allocator::free_link *)v5;
            }
            else
            {
              v21 = 0i64;
            }
LABEL_67:
            UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v21);
            return;
          }
        }
      }
    }
    return;
  }
  if ( v2->mAttackTypeID != gAttackTypeWorldCollision.m_EnumValue )
    return;
  v25 = (UFG::SimObjectProp *)v2->mAttacker.m_pPointer;
  if ( !v25 )
    return;
  v26 = v25->m_Flags;
  if ( !((v26 >> 14) & 1) )
  {
    if ( (v26 & 0x8000u) == 0 )
    {
      if ( (v26 >> 13) & 1 )
      {
        v31 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v25);
        goto LABEL_62;
      }
      if ( !((v26 >> 12) & 1) )
      {
        v31 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                           (UFG::SimObject *)&v25->vfptr,
                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        goto LABEL_62;
      }
      v34 = v25->mComponentTableEntryCount;
      v35 = v25->m_Components.size;
      if ( v34 < v35 )
      {
        v29 = v25->m_Components.p;
        do
        {
          v30 = v34;
          if ( (v29[v34].m_TypeUID & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
            && !(UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v29[v34].m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_43;
          }
        }
        while ( ++v34 < v35 );
      }
    }
    else
    {
      v32 = v25->mComponentTableEntryCount;
      v33 = v25->m_Components.size;
      if ( v32 < v33 )
      {
        v29 = v25->m_Components.p;
        do
        {
          v30 = v32;
          if ( (v29[v32].m_TypeUID & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
            && !(UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v29[v32].m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_43;
          }
        }
        while ( ++v32 < v33 );
      }
    }
LABEL_44:
    v31 = 0i64;
    goto LABEL_62;
  }
  v27 = v25->mComponentTableEntryCount;
  v28 = v25->m_Components.size;
  if ( v27 >= v28 )
    goto LABEL_44;
  v29 = v25->m_Components.p;
  while ( 1 )
  {
    v30 = v27;
    if ( (v29[v27].m_TypeUID & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
      && !(UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v29[v27].m_TypeUID & 0x1FFFFFF) )
    {
      break;
    }
    if ( ++v27 >= v28 )
      goto LABEL_44;
  }
LABEL_43:
  v31 = (UFG::SimObjectWeaponPropertiesComponent *)v29[v30].m_pComponent;
LABEL_62:
  if ( v31 && v31->mLastOwner == v5->mNode.mUID )
  {
    v36 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
    v21 = v36;
    if ( v36 )
    {
      v37 = UFG::gGameStatEventChannel.mName;
      v38 = UFG::gGameStatEventChannel.mUID;
      v39 = v36 + 1;
      v39->mNext = v39;
      v39[1].mNext = v39;
      v21->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
      LODWORD(v21[3].mNext) = v38;
      v21[4].mNext = (UFG::allocator::free_link *)v37;
      v21->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable;
      LODWORD(v21[7].mNext) = 81;
      v21[8].mNext = (UFG::allocator::free_link *)v5;
    }
    else
    {
      v21 = 0i64;
    }
    goto LABEL_67;
  }
}

// File Line: 389
// RVA: 0x54FAE0
bool __fastcall UFG::HealthComponent::ShouldRegenerateHealth(UFG::HealthComponent *this)
{
  return this->m_fRegenerativeHealthRate > 0.0
      && (float)(this->m_fHealth / this->m_fMaxHealth) < this->m_fRegenerativeHealthRatio
      && s_fRecentDamageDurationS <= this->m_fTimeSinceDamagedS
      && !UFG::LocalPlayerIsInCombatManager::IsInMeleeCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0);
}

// File Line: 416
// RVA: 0x55B3B0
void __fastcall UFG::HealthComponent::Update(UFG::HealthComponent *this, float delta_sec)
{
  UFG::HealthComponent *v2; // rbx
  UFG::SimObject *v3; // rcx
  float v4; // xmm8_4
  UFG::FaceActionComponent *v5; // rdi
  bool v6; // si
  signed __int64 v7; // rax
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm6_4
  UFG::GameStatTracker *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  UFG::BaseAnimationComponent *v23; // rcx
  float v24; // xmm1_4
  UFG::BaseAnimationComponent *v25; // rcx
  float v26; // xmm6_4
  UFG::TiDo *v27; // rax
  UFG::SimObject *v28; // rcx
  unsigned __int16 v29; // dx
  unsigned int v30; // er8
  unsigned int v31; // er9
  signed __int64 v32; // rdx
  unsigned int v33; // er8
  unsigned int v34; // er9
  unsigned int v35; // er8
  unsigned int v36; // er9
  UFG::GameStatTracker *v37; // rax

  v2 = this;
  v3 = this->m_pSimObject;
  v4 = delta_sec;
  if ( !v3 || !((v3->m_Flags >> 10) & 1) )
  {
    v2->m_fTimeSinceDamagedS = delta_sec + v2->m_fTimeSinceDamagedS;
    v5 = 0i64;
    v6 = UFG::IsAnyLocalPlayer(v3);
    if ( v2->m_bIsKnockedOut )
    {
      v25 = (UFG::BaseAnimationComponent *)v2->m_CharacterAnimationComponent.m_pSimComponent;
      if ( v25 )
        UFG::BaseAnimationComponent::UnbindRequiredAnimationBanks(v25);
      goto LABEL_43;
    }
    if ( v2->m_fRegenerativeHealthRate <= 0.0 )
    {
LABEL_35:
      v23 = (UFG::BaseAnimationComponent *)v2->m_CharacterAnimationComponent.m_pSimComponent;
      if ( v23 )
        UFG::BaseAnimationComponent::RebindRequiredAnimationBanks(v23);
      if ( !v6 )
      {
LABEL_50:
        if ( v2->m_fHealth > 0.0 || (v28 = v2->m_pSimObject) == 0i64 )
        {
LABEL_81:
          if ( v6 )
          {
            v37 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v37, Health, v2->m_fHealth);
          }
          return;
        }
        v29 = v28->m_Flags;
        if ( (v29 >> 14) & 1 )
        {
          v5 = (UFG::FaceActionComponent *)v28->m_Components.p[45].m_pComponent;
          goto LABEL_77;
        }
        if ( (v29 & 0x8000u) != 0 )
        {
          v30 = (unsigned int)v28[1].vfptr;
          v31 = v28->m_Components.size;
          if ( v30 >= v31 )
            goto LABEL_77;
          v32 = (signed __int64)&v28->m_Components.p[v30];
          while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
               || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF )
          {
            ++v30;
            v32 += 16i64;
            if ( v30 >= v31 )
              goto LABEL_77;
          }
          goto LABEL_61;
        }
        if ( (v29 >> 13) & 1 )
        {
          v33 = (unsigned int)v28[1].vfptr;
          v34 = v28->m_Components.size;
          if ( v33 < v34 )
          {
            v32 = (signed __int64)&v28->m_Components.p[v33];
            while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                 || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF )
            {
              ++v33;
              v32 += 16i64;
              if ( v33 >= v34 )
                goto LABEL_77;
            }
LABEL_61:
            v5 = *(UFG::FaceActionComponent **)v32;
            goto LABEL_77;
          }
        }
        else if ( (v29 >> 12) & 1 )
        {
          v35 = (unsigned int)v28[1].vfptr;
          v36 = v28->m_Components.size;
          if ( v35 < v36 )
          {
            v32 = (signed __int64)&v28->m_Components.p[v35];
            while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                 || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF )
            {
              ++v35;
              v32 += 16i64;
              if ( v35 >= v36 )
                goto LABEL_77;
            }
            goto LABEL_61;
          }
        }
        else
        {
          v5 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(v28, UFG::FaceActionComponent::_TypeUID);
        }
LABEL_77:
        if ( v5 )
        {
          if ( v5->mFaceActionEnabled == 1 )
            UFG::FaceActionComponent::KillEffect(v5);
          v5->mFaceActionEnabled = 0;
        }
        goto LABEL_81;
      }
      v24 = v2->m_fArmour - (float)(UFG::HealthComponent::ms_fArmourDecay * v4);
      if ( v24 < 0.0 )
        v24 = 0.0;
      v2->m_fArmour = v24;
LABEL_43:
      if ( v6 )
      {
        v26 = NISManager::GetInstance()->mState || !UFG::HealthComponent::ms_bEnableAudioEffects ? FLOAT_1000_0 : v2->m_fHealth;
        if ( last_health_rtpc != v26 )
        {
          v27 = UFG::TiDo::GetInstance();
          UFG::TiDo::SetWwiseRtpcValue(v27, sym_health.mUID, v26, 0xFFFFFFFFFFFFFFFFui64);
          last_health_rtpc = v26;
        }
      }
      goto LABEL_50;
    }
    v7 = (signed __int64)&v2->m_HealthRegenerateTaskList.mNode.mNext[-3].mNext;
    if ( (UFG::SimComponent **)v7 != &v2->m_CharacterAnimationComponent.m_pSimComponent )
    {
      v8 = v2->m_fMaxHealth;
      if ( v8 >= (float)((float)(v4 * *(float *)(*(_QWORD *)(v7 + 24) + 60i64)) + v2->m_fHealth) )
        v8 = (float)(v4 * *(float *)(*(_QWORD *)(v7 + 24) + 60i64)) + v2->m_fHealth;
      v2->m_fHealth = v8;
    }
    if ( !UFG::HealthComponent::ShouldRegenerateHealth(v2) )
    {
      v2->m_fRegenerationDelayS = s_fRegenerationDelayS;
LABEL_27:
      v18 = v2->m_fHealthBoost;
      if ( v18 > 0.0 )
      {
        v19 = v2->m_fHealth;
        v20 = v2->m_fMaxHealth;
        if ( v19 >= v20 )
        {
          v2->m_fHealthBoost = 0.0;
        }
        else
        {
          v21 = v19 + (float)(UFG::HealthComponent::ms_fRegenerativeHealthBoostRate * v4);
          if ( v20 >= v21 )
            v20 = v21;
          v22 = v18 - (float)(UFG::HealthComponent::ms_fRegenerativeHealthBoostRate * v4);
          v2->m_fHealth = v20;
          if ( v22 < 0.0 )
            v22 = 0.0;
          v2->m_fHealthBoost = v22;
        }
      }
      goto LABEL_35;
    }
    v9 = v2->m_fRegenerationDelayS;
    if ( v9 > 0.0 )
    {
      v16 = FLOAT_N1_0;
      v17 = v9 - v4;
      if ( v17 >= -1.0 )
        v16 = v17;
      v2->m_fRegenerationDelayS = v16;
      goto LABEL_27;
    }
    v10 = *(float *)&FLOAT_1_0;
    if ( UFG::IsAnyLocalPlayer(v2->m_pSimObject) )
      v10 = UFG::PlayerBuffTracker::GetRegenerativeHealthRateMultiplier() + 1.0;
    v11 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v11, HealthRegen_Activated) < 0.0 )
    {
      v14 = v2->m_fHealth;
      v12 = UFG::HealthComponent::ms_fRegenerativeHealthPhase1;
      if ( v14 < UFG::HealthComponent::ms_fRegenerativeHealthPhase1 )
      {
        v15 = (float)((float)(v4 * v2->m_fRegenerativeHealthRate) * v10) + v14;
        if ( UFG::HealthComponent::ms_fRegenerativeHealthPhase1 >= v15 )
        {
          v2->m_fHealth = v15;
          goto LABEL_27;
        }
        goto LABEL_22;
      }
      v12 = UFG::HealthComponent::ms_fRegenerativeHealthPhase2;
      if ( v14 >= UFG::HealthComponent::ms_fRegenerativeHealthPhase2 )
        goto LABEL_27;
      v13 = (float)((float)(UFG::HealthComponent::ms_fRegenerativeHealthRate2 * v4) * v10) + v14;
    }
    else
    {
      v12 = v2->m_fMaxHealth;
      v13 = (float)((float)(v4 * v2->m_fRegenerativeHealthRate) * v10) + v2->m_fHealth;
    }
    if ( v12 >= v13 )
      v12 = v13;
LABEL_22:
    v2->m_fHealth = v12;
    goto LABEL_27;
  }
}

// File Line: 588
// RVA: 0x55E180
void __fastcall UFG::HealthComponent::UpdateAll(float sim_time_delta)
{
  unsigned __int64 v1; // rdi
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  v1 = UFG::qGetTicks();
  v2 = UFG::HealthComponent::s_HealthComponentList.mNode.mNext - 4;
  for ( UFG::HealthComponent::s_HealthComponentpCurrentIterator = (UFG::HealthComponent *)&UFG::HealthComponent::s_HealthComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *)(&UFG::HealthComponent::s_HealthComponentList - 4);
        UFG::HealthComponent::s_HealthComponentpCurrentIterator = (UFG::HealthComponent *)v2 )
  {
    if ( ((_QWORD)v2[2].mPrev & 3) == 1 )
    {
      UFG::HealthComponent::Update((UFG::HealthComponent *)v2, sim_time_delta);
      v2 = (UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *)UFG::HealthComponent::s_HealthComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::HealthComponent::s_HealthComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(v1, v3);
}

// File Line: 597
// RVA: 0x521F60
bool __fastcall UFG::HealthComponent::ApplyHealthDamage(UFG::HealthComponent *this, const int iDamage, UFG::SimObject *pAttacker, UFG::HitRecord *pHitRecord, bool bProjectileDamage)
{
  UFG::SimObject *v5; // rax
  UFG::HitRecord *v6; // rbp
  UFG::SimObject *v7; // rdi
  UFG::HealthComponent *v8; // rsi
  bool result; // al
  bool v10; // r15
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  UFG::GameStatTracker *v17; // rax
  UFG::GameStat::FloatStat v18; // edx
  UFG::SimComponent *v19; // rax
  UFG::SimComponent *v20; // r14
  UFG::SimObject *v21; // rbx
  UFG::SimObjectCharacter *v22; // rbx
  unsigned __int16 v23; // cx
  UFG::SimComponent *v24; // rdx
  unsigned int v25; // er8
  unsigned int v26; // er9
  signed __int64 v27; // rdx
  unsigned int v28; // er8
  unsigned int v29; // er9
  unsigned __int8 v30; // al

  v5 = this->m_pSimObject;
  v6 = pHitRecord;
  v7 = pAttacker;
  v8 = this;
  if ( v5 && (v5->m_Flags >> 10) & 1 )
    return 0;
  v10 = 0;
  v11 = (float)iDamage;
  if ( pAttacker != (UFG::SimObject *)UFG::GetLocalPlayer() && !UFG::SimObjectUtility::IsPlayerVehicle(v7) )
    v11 = v11 * v8->m_NonPlayerDamageMultiplier;
  if ( UFG::IsAnyLocalPlayer(v8->m_pSimObject) )
  {
    v12 = UFG::PlayerBuffTracker::GetGeneralDamageReductionPercent();
    if ( bProjectileDamage )
    {
      v13 = UFG::PlayerBuffTracker::GetProjectileDamageReductionPercent();
    }
    else if ( v6->mMeleeInfo.mAttackMaterialUID == gAttackMaterialWeaponEquipped.m_EnumSymbol.mUID )
    {
      v13 = UFG::PlayerBuffTracker::GetMeleeWeaponDamageReductionPercent();
    }
    else
    {
      v13 = UFG::PlayerBuffTracker::GetMeleeDamageReductionPercent();
    }
    v14 = v11 * (float)(1.0 - (float)(v12 + v13));
    if ( bProjectileDamage )
    {
      v15 = UFG::HealthComponent::ms_fMaxArmour;
      v14 = v14 * (float)(1.0 - v8->m_fArmour);
      if ( UFG::HealthComponent::ms_fMaxArmour >= (float)((float)((float)(v14 * 0.0099999998)
                                                                * UFG::HealthComponent::ms_fDamageToArmourRatio)
                                                        + v8->m_fArmour) )
        v15 = (float)((float)(v14 * 0.0099999998) * UFG::HealthComponent::ms_fDamageToArmourRatio) + v8->m_fArmour;
      v8->m_fArmour = v15;
    }
    v16 = v8->m_fHealth - UFG::HealthComponent::ms_fLowHealthThreshold;
    if ( v16 <= 0.0 )
      v16 = 0.0;
    if ( v16 >= v14 )
      v16 = v14;
    v11 = (float)((float)(v14 - v16) * UFG::HealthComponent::ms_fLowHealthMultiplier) + v16;
  }
  if ( bProjectileDamage )
    v11 = v11 * v8->m_ProjectileDamageMultiplier;
  if ( v8->m_bIsTakingDamage && !v8->m_bIsInvulnerable && !v8->m_bIsKnockedOut )
  {
    v10 = UFG::HealthComponent::SetHealth(v8, (signed int)(float)(v8->m_fHealth - v11), v6);
    if ( v10 && UFG::IsAnyLocalPlayer(v8->m_pSimObject) )
    {
      v17 = UFG::GameStatTracker::Instance();
      v18 = 137;
      if ( !bProjectileDamage )
        v18 = 138;
      UFG::GameStatTracker::ApplyDelta(v17, v18, v11);
    }
    v8->m_fTimeSinceDamagedS = 0.0;
    v19 = UFG::GetCurrentGameCamera();
    v20 = v19;
    if ( v19 )
    {
      v21 = v8->m_pSimObject;
      if ( v21 == (UFG::SimObject *)((__int64 (__fastcall *)(UFG::SimComponent *))v19->vfptr[17].__vecDelDtor)(v19) )
        ((void (__fastcall *)(UFG::SimComponent *))v20->vfptr[32].__vecDelDtor)(v20);
    }
    v22 = (UFG::SimObjectCharacter *)v8->m_pSimObject;
    if ( v22 == UFG::GetLocalPlayer() )
    {
      if ( !v7 )
        goto LABEL_69;
      if ( v7 != v8->m_pSimObject )
        UFG::HealthComponent::SetDirectionalDamage(v8, v7);
    }
    if ( v7 )
    {
      v23 = v7->m_Flags;
      if ( (v23 >> 14) & 1 )
      {
        v24 = v7->m_Components.p[20].m_pComponent;
        if ( !v24
          || (UFG::TargetingSystemPedBaseComponent::_TypeUID ^ v24->m_TypeUID) & 0xFE000000
          || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v24->m_TypeUID & 0x1FFFFFF )
        {
          goto LABEL_44;
        }
LABEL_66:
        if ( v24 )
        {
          v30 = *(_BYTE *)(*(_QWORD *)&v24[1].m_Flags + 86i64);
          if ( v30 )
            UFG::TargetingSimObject::SetTarget(
              (UFG::TargetingSimObject *)(*(_QWORD *)&v24[1].m_TypeUID + 56i64 * v30),
              v8->m_pSimObject);
        }
        goto LABEL_69;
      }
      if ( (v23 & 0x8000u) != 0 )
      {
        v24 = v7->m_Components.p[20].m_pComponent;
        if ( v24 && !((UFG::TargetingSystemPedBaseComponent::_TypeUID ^ v24->m_TypeUID) & 0xFE000000) )
        {
          if ( UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v24->m_TypeUID & 0x1FFFFFF )
            v24 = 0i64;
          goto LABEL_66;
        }
        goto LABEL_44;
      }
      if ( (v23 >> 13) & 1 )
      {
        v25 = (unsigned int)v7[1].vfptr;
        v26 = v7->m_Components.size;
        if ( v25 < v26 )
        {
          v27 = (signed __int64)&v7->m_Components.p[v25];
          while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
               || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF )
          {
            ++v25;
            v27 += 16i64;
            if ( v25 >= v26 )
            {
              v24 = 0i64;
              goto LABEL_66;
            }
          }
LABEL_57:
          v24 = *(UFG::SimComponent **)v27;
          goto LABEL_66;
        }
      }
      else
      {
        if ( !((v23 >> 12) & 1) )
        {
          v24 = UFG::SimObject::GetComponentOfType(v7, UFG::TargetingSystemPedBaseComponent::_TypeUID);
          goto LABEL_66;
        }
        v28 = (unsigned int)v7[1].vfptr;
        v29 = v7->m_Components.size;
        if ( v28 < v29 )
        {
          v27 = (signed __int64)&v7->m_Components.p[v28];
          while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
               || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF )
          {
            ++v28;
            v27 += 16i64;
            if ( v28 >= v29 )
            {
              v24 = 0i64;
              goto LABEL_66;
            }
          }
          goto LABEL_57;
        }
      }
LABEL_44:
      v24 = 0i64;
      goto LABEL_66;
    }
  }
LABEL_69:
  result = v10;
  v8->m_fHealthBoost = 0.0;
  return result;
}

// File Line: 836
// RVA: 0x54C6F0
void __fastcall UFG::HealthComponent::SetDirectionalDamage(UFG::HealthComponent *this, UFG::SimObject *pAttacker)
{
  UFG::SimObject *rbx1a; // rbx
  UFG::HealthComponent *v3; // rdi
  UFG::SimComponent *v4; // rax
  UFG::TransformNodeComponent *v5; // rbx
  UFG::SimComponent *v6; // rbp
  UFG::TransformNodeComponent *v7; // rsi
  float v8; // xmm1_4
  float v9; // xmm0_4
  int v10; // xmm1_4
  float v11; // xmm0_4
  signed int v12; // eax
  float v13; // xmm0_4
  UFG::qVector2 v2; // [rsp+40h] [rbp+8h]
  UFG::qVector2 v1; // [rsp+48h] [rbp+10h]

  rbx1a = pAttacker;
  v3 = this;
  v4 = UFG::GetCurrentGameCamera();
  v5 = rbx1a->m_pTransformNodeComponent;
  v6 = v4;
  v7 = v3->m_pSimObject->m_pTransformNodeComponent;
  if ( v4 && v5 && v7 && UFG::HealthComponent::IsProjectileAttack(v3) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    UFG::TransformNodeComponent::UpdateWorldTransform(v7);
    v8 = v5->mWorldTransform.v3.x - v7->mWorldTransform.v3.x;
    v9 = v5->mWorldTransform.v3.y - v7->mWorldTransform.v3.y;
    LODWORD(v1.x) = LODWORD(v6[3].m_BoundComponentHandles.mNode.mPrev) ^ _xmm[0];
    v2.x = v8;
    v10 = HIDWORD(v6[3].m_BoundComponentHandles.mNode.mPrev);
    v2.y = v9;
    LODWORD(v1.y) = v10 ^ _xmm[0];
    v11 = UFG::qAngleBetween(&v1, &v2);
    v12 = 2;
    v13 = (float)(v11 * 180.0) * 0.31830987;
    if ( v13 >= 45.0 && v13 < 135.0 )
    {
      v12 = 0;
LABEL_14:
      v3->m_bAttackDir[v12] = 1;
      return;
    }
    if ( v13 < 135.0 )
    {
      if ( v13 < 225.0 )
        goto LABEL_14;
    }
    else if ( v13 < 225.0 )
    {
      v12 = 3;
      goto LABEL_14;
    }
    if ( v13 < 315.0 )
      v12 = 1;
    goto LABEL_14;
  }
}

// File Line: 875
// RVA: 0x53BF00
char __fastcall UFG::HealthComponent::IsProjectileAttack(UFG::HealthComponent *this)
{
  UFG::SimObject *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax
  unsigned int v4; // er8
  unsigned int v5; // er9
  signed __int64 v6; // rdx
  unsigned int v7; // er8
  unsigned int v8; // er9

  v1 = this->m_pSimObject;
  if ( !v1 )
    return 0;
  v2 = v1->m_Flags;
  if ( !((v2 >> 14) & 1) )
  {
    if ( (v2 & 0x8000u) != 0 )
    {
      v3 = v1->m_Components.p[15].m_pComponent;
      goto LABEL_22;
    }
    if ( (v2 >> 13) & 1 )
    {
      v4 = (unsigned int)v1[1].vfptr;
      v5 = v1->m_Components.size;
      if ( v4 < v5 )
      {
        v6 = (signed __int64)&v1->m_Components.p[v4];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::HitReactionComponent::_TypeUID & 0xFE000000)
             || UFG::HitReactionComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
        {
          ++v4;
          v6 += 16i64;
          if ( v4 >= v5 )
            goto LABEL_12;
        }
LABEL_13:
        v3 = *(UFG::SimComponent **)v6;
        goto LABEL_22;
      }
    }
    else
    {
      if ( !((v2 >> 12) & 1) )
      {
        v3 = UFG::SimObject::GetComponentOfType(v1, UFG::HitReactionComponent::_TypeUID);
        goto LABEL_22;
      }
      v7 = (unsigned int)v1[1].vfptr;
      v8 = v1->m_Components.size;
      if ( v7 < v8 )
      {
        v6 = (signed __int64)&v1->m_Components.p[v7];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::HitReactionComponent::_TypeUID & 0xFE000000)
             || UFG::HitReactionComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
        {
          ++v7;
          v6 += 16i64;
          if ( v7 >= v8 )
            goto LABEL_12;
        }
        goto LABEL_13;
      }
    }
LABEL_12:
    v3 = 0i64;
    goto LABEL_22;
  }
  v3 = v1->m_Components.p[15].m_pComponent;
LABEL_22:
  if ( v3 && HIDWORD(v3[2].m_BoundComponentHandles.mNode.mNext) == gAttackCollisionProjectile.m_EnumValue )
    return 1;
  return 0;
}

// File Line: 898
// RVA: 0x549620
void __fastcall UFG::HealthComponent::ReplenishHealth(UFG::HealthComponent *this)
{
  UFG::HealthComponent *v1; // rbx

  v1 = this;
  UFG::HealthComponent::SetRegenerativeHealthRatio(this, 1.0, 1);
  UFG::HealthComponent::SetHealth(v1, (signed int)(float)(v1->m_fRegenerativeHealthRatio * v1->m_fMaxHealth), 0i64);
}

// File Line: 906
// RVA: 0x54D3D0
bool __fastcall UFG::HealthComponent::SetHealth(UFG::HealthComponent *this, const int uHealth, UFG::HitRecord *pReferenceHitRecord)
{
  UFG::HealthComponent *v3; // rbx
  float v4; // xmm6_4
  bool v5; // si
  float v6; // xmm0_4
  float v7; // xmm1_4
  bool v8; // di
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rcx

  v3 = this;
  v4 = this->m_fHealth;
  v5 = this->m_bIsKnockedOut;
  v6 = (float)uHealth;
  if ( (float)uHealth <= 0.0 )
    v6 = 0.0;
  if ( v6 >= this->m_fMaxHealth )
    v6 = this->m_fMaxHealth;
  this->m_fHealth = v6;
  v7 = this->m_fMinHealth;
  if ( v6 < v7 )
  {
    this->m_bHealthClampedToMinimum = 1;
    this->m_fHealth = v7;
  }
  v8 = this->m_fHealth <= 0.0;
  if ( !this->m_bIsKnockedOut && this->m_fHealth <= 0.0 )
    UFG::HealthComponent::OnDeath(this, pReferenceHitRecord);
  v3->m_bIsKnockedOut = v8;
  if ( v8 && !v5 )
  {
    v9 = UFG::qMalloc(0x50ui64, "EvtEntityDied", 0i64);
    if ( v9 )
      UFG::EvtEntityDied::EvtEntityDied((UFG::EvtEntityDied *)v9, "EVT_ENTITY_DEATH", v3->m_pSimObject);
    UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v9);
    v10 = v3->m_HitReactionComponent.m_pSimComponent;
    if ( v10 )
      BYTE1(v10[2].m_BoundComponentHandles.mNode.mNext) = 1;
  }
  return v4 != v3->m_fHealth || v5 != v3->m_bIsKnockedOut;
}

// File Line: 937
// RVA: 0x54D980
void __fastcall UFG::HealthComponent::SetMaxHealth(UFG::HealthComponent *this, const int iMaxHealth)
{
  UFG::HealthComponent *v2; // rbx
  float v3; // xmm0_4
  float v4; // xmm1_4
  bool v5; // di

  v2 = this;
  v3 = (float)iMaxHealth;
  if ( (float)iMaxHealth >= this->m_fMaxUpgradedHealth )
    v3 = this->m_fMaxUpgradedHealth;
  this->m_fMaxHealth = v3;
  v4 = this->m_fHealth;
  if ( v4 >= v3 )
    v4 = v3;
  this->m_fHealth = v4;
  v5 = v4 <= 0.0;
  if ( this->m_bIsKnockedOut || v4 > 0.0 )
  {
    this->m_bIsKnockedOut = v5;
  }
  else
  {
    this->m_fTimeOfDeath = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::GetLocalPlayer();
    v2->m_bIsKnockedOut = v5;
  }
}

// File Line: 946
// RVA: 0x54DA00
void __fastcall UFG::HealthComponent::SetMinHealth(UFG::HealthComponent *this, const int iMinHealth)
{
  bool v2; // cf
  bool v3; // zf

  v2 = (float)iMinHealth < this->m_fHealth;
  v3 = (float)iMinHealth == this->m_fHealth;
  this->m_fMinHealth = (float)iMinHealth;
  if ( !v2 && !v3 )
  {
    this->m_fHealth = (float)iMinHealth;
    this->m_bHealthClampedToMinimum = 1;
  }
}

// File Line: 958
// RVA: 0x54E570
void __fastcall UFG::HealthComponent::SetRegenerativeHealthRatio(UFG::HealthComponent *this, const float fRegenerativeHealthRatio, bool saveSnapshot)
{
  bool v3; // si
  UFG::HealthComponent *v4; // rbx
  bool v5; // di
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax

  v3 = saveSnapshot;
  v4 = this;
  if ( fRegenerativeHealthRatio <= UFG::HealthComponent::ms_fRegenerativeHealthRatioMin )
    fRegenerativeHealthRatio = UFG::HealthComponent::ms_fRegenerativeHealthRatioMin;
  if ( fRegenerativeHealthRatio >= 1.0 )
    fRegenerativeHealthRatio = *(float *)&FLOAT_1_0;
  this->m_fRegenerativeHealthRatio = fRegenerativeHealthRatio;
  v5 = UFG::IsAnyLocalPlayer(this->m_pSimObject);
  if ( v5 )
  {
    v6 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v6, HealthRegen_Activated) >= 0.0 )
      v4->m_fRegenerativeHealthRatio = 1.0;
  }
  if ( v3 && v5 )
  {
    v7 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v7, RegenHealthRatio, v4->m_fRegenerativeHealthRatio);
  }
}

// File Line: 979
// RVA: 0x52DFA0
unsigned __int8 __fastcall UFG::HealthComponent::GetIsKilled(UFG::HealthComponent *this)
{
  UFG::HealthComponent *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // er8
  UFG::SimComponent *v4; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v5; // rcx
  unsigned __int8 result; // al

  v1 = this;
  v2 = _S65;
  if ( !(_S65 & 1) )
  {
    _S65 |= 1u;
    UID_Dead.mUID = UFG::qStringHashUpper32("Dead", 0xFFFFFFFF);
    v2 = _S65;
  }
  if ( v2 & 2 )
  {
    v3 = mostUsed_Dead;
  }
  else
  {
    _S65 = v2 | 2;
    v3 = GetMostUsedIndex(UID_Dead.mUID);
    mostUsed_Dead = v3;
  }
  if ( !v1->m_bIsKnockedOut )
    return 0;
  v4 = v1->m_HitReactionComponent.m_pSimComponent;
  if ( v4 && (v5 = v4[8].vfptr) != 0i64 )
    result = ActionController::IsPlaying((ActionController *)&v5[24], &UID_Dead, v3, 1);
  else
    result = 1;
  return result;
}

// File Line: 1039
// RVA: 0x5209C0
void __fastcall UFG::HealthComponent::AddHealthRegenerateTask(UFG::HealthComponent *this, HealthRegenerateTask *pHealthRegenerateTask)
{
  UFG::qNode<HealthRegenerateTask,HealthRegenerateTaskList> *v2; // rdx
  UFG::qList<HealthRegenerateTask,HealthRegenerateTaskList,0,0> *v3; // rcx
  UFG::qNode<HealthRegenerateTask,HealthRegenerateTaskList> *v4; // rax

  v2 = (UFG::qNode<HealthRegenerateTask,HealthRegenerateTaskList> *)&pHealthRegenerateTask->mPrev;
  v3 = &this->m_HealthRegenerateTaskList;
  v4 = v3->mNode.mPrev;
  v4->mNext = v2;
  v2->mPrev = v4;
  v2->mNext = &v3->mNode;
  v3->mNode.mPrev = v2;
}

