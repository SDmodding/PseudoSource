// File Line: 77
// RVA: 0x154CE50
__int64 UFG::_dynamic_initializer_for__sym_health__()
{
  sym_health.mUID = UFG::qWiseSymbolUIDFromString("health", 0x811C9DC5);
  _((AMD_HD3D *)sym_health.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_health__);
}

// File Line: 112
// RVA: 0x1543EA0
__int64 dynamic_initializer_for__UFG::HealthComponent::s_HealthComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::HealthComponent::s_HealthComponentList__);
}

// File Line: 113
// RVA: 0x532470
const char *__fastcall UFG::HealthComponent::GetTypeName(UFG::HealthComponent *this)
{
  return "HealthComponent";
}

// File Line: 129
// RVA: 0x517950
void __fastcall UFG::HealthComponent::HealthComponent(
        UFG::HealthComponent *this,
        unsigned int name_uid,
        component_Health *dataPtr)
{
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::HealthComponent,UFG::HealthComponent>;
  this->mNext = &this->UFG::qNode<UFG::HealthComponent,UFG::HealthComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HealthComponent::`vftable;
  this->m_fHealth = 100.0;
  this->m_fMinHealth = -1.0;
  this->m_fMaxHealth = 100.0;
  this->m_fMaxUpgradedHealth = 100.0;
  this->m_NonPlayerDamageMultiplier = 1.0;
  this->m_ProjectileDamageMultiplier = 1.0;
  this->m_bIsTakingDamage = 1;
  this->m_fRegenerativeHealthRate = -1.0;
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::RebindingComponentHandle<UFG::HitReactionComponent,0>(&this->m_HitReactionComponent);
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&this->m_CharacterAnimationComponent);
  this->m_HealthRegenerateTaskList.mNode.mPrev = &this->m_HealthRegenerateTaskList.mNode;
  this->m_HealthRegenerateTaskList.mNode.mNext = &this->m_HealthRegenerateTaskList.mNode;
  mPrev = UFG::HealthComponent::s_HealthComponentList.mNode.mPrev;
  UFG::HealthComponent::s_HealthComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::HealthComponent,UFG::HealthComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *)&UFG::HealthComponent::s_HealthComponentList;
  UFG::HealthComponent::s_HealthComponentList.mNode.mPrev = &this->UFG::qNode<UFG::HealthComponent,UFG::HealthComponent>;
  UFG::SimComponent::AddType(this, UFG::HealthComponent::_HealthComponentTypeUID, "HealthComponent");
  UFG::HealthComponent::Reset(this, dataPtr);
}

// File Line: 168
// RVA: 0x51B980
void __fastcall UFG::HealthComponent::~HealthComponent(UFG::HealthComponent *this)
{
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v2; // rbx
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *mPrev; // rcx
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *mNext; // rax
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v5; // rcx
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HealthComponent::`vftable;
  if ( this == UFG::HealthComponent::s_HealthComponentpCurrentIterator )
    UFG::HealthComponent::s_HealthComponentpCurrentIterator = (UFG::HealthComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::HealthComponent,UFG::HealthComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&this->m_HealthRegenerateTaskList);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_CharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_HitReactionComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 191
// RVA: 0x546310
UFG::SimComponent *__fastcall UFG::HealthComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *sceneObject,
        bool bRequired)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_Health::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !bRequired )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "HealthComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::HealthComponent::HealthComponent(
      (UFG::HealthComponent *)v10,
      sceneObject->m_NameUID,
      (component_Health *)MemImagePtr);
    v6 = v11;
  }
  m_pSimObject = sceneObject->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v14 = 6;
  else
    v14 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v15, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v15, v6, v14);
  UFG::SimObjectModifier::Close(&v15);
  UFG::SimObjectModifier::~SimObjectModifier(&v15);
  return v6;
}

// File Line: 209
// RVA: 0x5496F0
void __fastcall UFG::HealthComponent::Reset(UFG::HealthComponent *this, component_Health *data_ptr)
{
  UFG::qMemSet(this->m_bAttackDir, 0, 4u);
  this->m_fRegenerativeHealthRatio = 1.0;
  *(_DWORD *)&this->m_bIsKnockedOut = 16842752;
  this->m_fTimeOfDeath = -1.0;
  this->m_fRegenerationDelayS = -1.0;
  *(_WORD *)&this->m_bHasDeathTouch = 0;
  this->m_fTimeSinceDamagedS = 1000.0;
  this->m_fHealthBoost = 0.0;
  if ( data_ptr && !UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject) )
  {
    this->m_fMaxUpgradedHealth = (float)data_ptr->maxUpgradedHealth;
    UFG::HealthComponent::SetMaxHealth(this, data_ptr->maxHealth);
    this->m_fRegenerativeHealthRate = data_ptr->regenerativeHealthRate;
    this->m_bIsInvulnerable = data_ptr->InvulnerableCharacter;
    this->m_ProjectileDamageMultiplier = data_ptr->healthProjectileDamageMultiplier;
  }
  this->m_fHealth = this->m_fMaxHealth;
}

// File Line: 251
// RVA: 0x5497A0
void __fastcall UFG::HealthComponent::Reset(UFG::HealthComponent *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v4; // rax
  char *MemImagePtr; // rax

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_Health::sPropertyName,
         DEPTH_RECURSE);
  if ( v4 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v4);
    UFG::HealthComponent::Reset(this, (component_Health *)MemImagePtr);
  }
  else
  {
    UFG::HealthComponent::Reset(this, 0i64);
  }
}

// File Line: 258
// RVA: 0x53C950
void __fastcall UFG::HealthComponent::LoadHealthSettings(UFG::HealthComponent *this)
{
  UFG::GameStatTracker *v2; // rbx
  float Stat; // xmm0_4
  float v4; // xmm0_4
  UFG::SimObjectCharacter *m_pSimObject; // rcx
  UFG::GameStatTracker *v6; // rax

  if ( UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject) )
  {
    v2 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v2, MaxHealth);
    UFG::HealthComponent::SetMaxHealth(this, (int)Stat);
    v4 = UFG::GameStatTracker::GetStat(v2, RegenHealthRatio);
    if ( v4 <= UFG::HealthComponent::ms_fRegenerativeHealthRatioMin )
      v4 = UFG::HealthComponent::ms_fRegenerativeHealthRatioMin;
    if ( v4 >= 1.0 )
      v4 = *(float *)&FLOAT_1_0;
    m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
    this->m_fRegenerativeHealthRatio = v4;
    if ( UFG::IsAnyLocalPlayer(m_pSimObject) )
    {
      v6 = UFG::GameStatTracker::Instance();
      if ( UFG::GameStatTracker::GetStat(v6, HealthRegen_Activated) >= 0.0 )
        this->m_fRegenerativeHealthRatio = 1.0;
    }
    UFG::HealthComponent::SetRegenerativeHealthRatio(this, 1.0, 1);
    UFG::HealthComponent::SetHealth(this, (int)(float)(this->m_fMaxHealth * this->m_fRegenerativeHealthRatio), 0i64);
  }
}

// File Line: 272
// RVA: 0x53DEE0
void __fastcall UFG::HealthComponent::OnAttach(UFG::HealthComponent *this, UFG::SimObject *pObject)
{
  UFG::SimObject *m_pSimObject; // r8
  __int16 m_Flags; // r9
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // r11
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *p_m_HitReactionComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_m_CharacterAnimationComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::allocator::free_link *v20; // [rsp+40h] [rbp+8h]

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_16:
          m_pComponent = 0i64;
        }
        else
        {
          p = m_pSimObject->m_Components.p;
          while ( (p[vfptr].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || (UFG::UELComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) != 0 )
          {
            if ( ++vfptr >= size )
              goto LABEL_16;
          }
          m_pComponent = p[vfptr].m_pComponent;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(this->m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
    {
      v20 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
      m_pComponent[2].m_pSimObject = (UFG::SimObject *)v20;
      v20->mNext = (UFG::allocator::free_link *)&this->m_fHealth;
      m_pComponent[2].m_pSimObject->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_fMaxHealth;
    }
  }
  p_m_HitReactionComponent = &this->m_HitReactionComponent;
  if ( this->m_HitReactionComponent.m_pSimComponent )
  {
    mPrev = p_m_HitReactionComponent->mPrev;
    mNext = this->m_HitReactionComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_HitReactionComponent.m_pSimComponent = 0i64;
LABEL_26:
    this->m_HitReactionComponent.m_pSimObject = 0i64;
    this->m_HitReactionComponent.mNext = &this->m_HitReactionComponent;
    p_m_HitReactionComponent->mPrev = p_m_HitReactionComponent;
    goto LABEL_27;
  }
  if ( this->m_HitReactionComponent.m_pSimObject
    && (p_m_HitReactionComponent->mPrev != p_m_HitReactionComponent
     || this->m_HitReactionComponent.mNext != &this->m_HitReactionComponent) )
  {
    v13 = p_m_HitReactionComponent->mPrev;
    v14 = this->m_HitReactionComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_26;
  }
LABEL_27:
  this->m_HitReactionComponent.m_Changed = 1;
  this->m_HitReactionComponent.m_pSimObject = pObject;
  this->m_HitReactionComponent.m_TypeUID = UFG::HitReactionComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_HitReactionComponent,
    pObject);
  p_m_CharacterAnimationComponent = &this->m_CharacterAnimationComponent;
  if ( this->m_CharacterAnimationComponent.m_pSimComponent )
  {
    v16 = p_m_CharacterAnimationComponent->mPrev;
    v17 = this->m_CharacterAnimationComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    this->m_CharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_33:
    this->m_CharacterAnimationComponent.m_pSimObject = 0i64;
    this->m_CharacterAnimationComponent.mNext = &this->m_CharacterAnimationComponent;
    p_m_CharacterAnimationComponent->mPrev = p_m_CharacterAnimationComponent;
    goto LABEL_34;
  }
  if ( this->m_CharacterAnimationComponent.m_pSimObject
    && (p_m_CharacterAnimationComponent->mPrev != p_m_CharacterAnimationComponent
     || this->m_CharacterAnimationComponent.mNext != &this->m_CharacterAnimationComponent) )
  {
    v18 = p_m_CharacterAnimationComponent->mPrev;
    v19 = this->m_CharacterAnimationComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    goto LABEL_33;
  }
LABEL_34:
  this->m_CharacterAnimationComponent.m_Changed = 1;
  this->m_CharacterAnimationComponent.m_pSimObject = pObject;
  this->m_CharacterAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_CharacterAnimationComponent,
    pObject);
  this->m_fArmour = 0.0;
}

// File Line: 289
// RVA: 0x540560
void __fastcall UFG::HealthComponent::OnDetach(UFG::HealthComponent *this)
{
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_m_CharacterAnimationComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *p_m_HitReactionComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v17; // rdx

  p_m_CharacterAnimationComponent = &this->m_CharacterAnimationComponent;
  if ( this->m_CharacterAnimationComponent.m_pSimComponent )
  {
    mPrev = p_m_CharacterAnimationComponent->mPrev;
    mNext = this->m_CharacterAnimationComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_CharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_m_CharacterAnimationComponent->m_pSimObject = 0i64;
    p_m_CharacterAnimationComponent->mNext = p_m_CharacterAnimationComponent;
    p_m_CharacterAnimationComponent->mPrev = p_m_CharacterAnimationComponent;
    goto LABEL_8;
  }
  if ( this->m_CharacterAnimationComponent.m_pSimObject
    && (p_m_CharacterAnimationComponent->mPrev != p_m_CharacterAnimationComponent
     || this->m_CharacterAnimationComponent.mNext != &this->m_CharacterAnimationComponent) )
  {
    v5 = p_m_CharacterAnimationComponent->mPrev;
    v6 = p_m_CharacterAnimationComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_HitReactionComponent = &this->m_HitReactionComponent;
  p_m_CharacterAnimationComponent->m_Changed = 1;
  if ( this->m_HitReactionComponent.m_pSimComponent )
  {
    v8 = p_m_HitReactionComponent->mPrev;
    v9 = this->m_HitReactionComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_HitReactionComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_HitReactionComponent.m_pSimObject = 0i64;
    this->m_HitReactionComponent.mNext = &this->m_HitReactionComponent;
    p_m_HitReactionComponent->mPrev = p_m_HitReactionComponent;
    goto LABEL_15;
  }
  if ( this->m_HitReactionComponent.m_pSimObject
    && (p_m_HitReactionComponent->mPrev != p_m_HitReactionComponent
     || this->m_HitReactionComponent.mNext != &this->m_HitReactionComponent) )
  {
    v10 = p_m_HitReactionComponent->mPrev;
    v11 = this->m_HitReactionComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_HitReactionComponent.m_Changed = 1;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_28:
          m_pComponent = 0i64;
        }
        else
        {
          v17 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || (UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v17 += 16i64;
            if ( vfptr >= size )
              goto LABEL_28;
          }
          m_pComponent = *(UFG::SimComponent **)v17;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
    {
      operator delete[](m_pComponent[2].m_pSimObject);
      m_pComponent[2].m_pSimObject = 0i64;
    }
  }
}

// File Line: 304
// RVA: 0x53F4F0
void __fastcall UFG::HealthComponent::OnDeath(UFG::HealthComponent *this, UFG::HitRecord *pReferenceHitRecord)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObjectCharacter *v5; // rsi
  bool v6; // di
  int mAttackTypeID; // ecx
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // r8
  const char *mName; // rdx
  unsigned int mUID; // ecx
  UFG::allocator::free_link *v12; // rax
  UFG::SimObject *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rcx
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // r8
  const char *v22; // rdx
  unsigned int v23; // ecx
  UFG::allocator::free_link *v24; // rax
  UFG::SimObjectProp *v25; // rcx
  __int16 v26; // dx
  unsigned int v27; // edx
  unsigned int v28; // r9d
  UFG::SimComponentHolder *v29; // rbx
  __int64 v30; // r8
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  unsigned int v32; // edx
  unsigned int v33; // r9d
  unsigned int mComponentTableEntryCount; // edx
  unsigned int v35; // r9d
  UFG::allocator::free_link *v36; // rax
  const char *v37; // rdx
  unsigned int v38; // ecx
  UFG::allocator::free_link *v39; // rax

  this->m_fTimeOfDeath = UFG::Metrics::msInstance.mSimTime_Temp;
  LocalPlayer = UFG::GetLocalPlayer();
  v5 = LocalPlayer;
  if ( !pReferenceHitRecord || this->m_pSimObject == LocalPlayer )
    return;
  v6 = LocalPlayer == pReferenceHitRecord->mAttacker.m_pPointer;
  mAttackTypeID = pReferenceHitRecord->mAttackTypeID;
  if ( mAttackTypeID == gAttackCollisionExplosionNoDamage.m_EnumValue
    || mAttackTypeID == gAttackCollisionExplosion.m_EnumValue )
  {
    v8 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
    v9 = v8;
    if ( v8 )
    {
      mName = UFG::gGameStatEventChannel.mName;
      mUID = UFG::gGameStatEventChannel.mUID;
      v12 = v8 + 1;
      v12->mNext = v12;
      v12[1].mNext = v12;
      v9->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
      LODWORD(v9[3].mNext) = mUID;
      v9[4].mNext = (UFG::allocator::free_link *)mName;
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
    if ( pReferenceHitRecord->mAttackTypeID == gAttackCollisionProjectile.m_EnumValue )
    {
      m_pPointer = pReferenceHitRecord->mAttacker.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            vfptr = (unsigned int)m_pPointer[1].vfptr;
            size = m_pPointer->m_Components.size;
            if ( vfptr >= size )
            {
LABEL_26:
              m_pComponent = 0i64;
            }
            else
            {
              p = m_pPointer->m_Components.p;
              while ( (p[vfptr].m_TypeUID & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                   || (UFG::ActionTreeComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) != 0 )
              {
                if ( ++vfptr >= size )
                  goto LABEL_26;
              }
              m_pComponent = p[vfptr].m_pComponent;
            }
          }
          else
          {
            m_pComponent = UFG::SimObject::GetComponentOfType(
                             pReferenceHitRecord->mAttacker.m_pPointer,
                             UFG::ActionTreeComponent::_TypeUID);
          }
        }
        else
        {
          m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
        }
        if ( m_pComponent )
        {
          v19 = *((_QWORD *)&m_pComponent[11].m_SafePointerList.mNode.mPrev
                + ((__int64)(int)gActionRequest_CoverPopoutBlind.m_EnumValue >> 6));
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
LABEL_66:
            UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v21);
            return;
          }
        }
      }
    }
    return;
  }
  if ( pReferenceHitRecord->mAttackTypeID != gAttackTypeWorldCollision.m_EnumValue )
    return;
  v25 = (UFG::SimObjectProp *)pReferenceHitRecord->mAttacker.m_pPointer;
  if ( !v25 )
    return;
  v26 = v25->m_Flags;
  if ( (v26 & 0x4000) == 0 )
  {
    if ( v26 >= 0 )
    {
      if ( (v26 & 0x2000) != 0 )
      {
        ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v25);
        goto LABEL_61;
      }
      if ( (v26 & 0x1000) == 0 )
      {
        ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v25,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        goto LABEL_61;
      }
      mComponentTableEntryCount = v25->mComponentTableEntryCount;
      v35 = v25->m_Components.size;
      if ( mComponentTableEntryCount < v35 )
      {
        v29 = v25->m_Components.p;
        do
        {
          v30 = mComponentTableEntryCount;
          if ( (v29[mComponentTableEntryCount].m_TypeUID & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
            && (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v29[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_42;
          }
        }
        while ( ++mComponentTableEntryCount < v35 );
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
            && (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v29[v32].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_42;
          }
        }
        while ( ++v32 < v33 );
      }
    }
LABEL_43:
    ComponentOfType = 0i64;
    goto LABEL_61;
  }
  v27 = v25->mComponentTableEntryCount;
  v28 = v25->m_Components.size;
  if ( v27 >= v28 )
    goto LABEL_43;
  v29 = v25->m_Components.p;
  while ( 1 )
  {
    v30 = v27;
    if ( (v29[v27].m_TypeUID & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
      && (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v29[v27].m_TypeUID & 0x1FFFFFF) == 0 )
    {
      break;
    }
    if ( ++v27 >= v28 )
      goto LABEL_43;
  }
LABEL_42:
  ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)v29[v30].m_pComponent;
LABEL_61:
  if ( ComponentOfType && ComponentOfType->mLastOwner == v5->mNode.mUID )
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
    goto LABEL_66;
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
  UFG::SimObjectCharacter *m_pSimObject; // rcx
  UFG::FaceActionComponent *m_pComponent; // rdi
  bool IsAnyLocalPlayer; // si
  UFG::SimComponent **p_mNext; // rax
  float m_fMaxHealth; // xmm1_4
  float m_fRegenerationDelayS; // xmm0_4
  float v10; // xmm6_4
  UFG::GameStatTracker *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float m_fHealthBoost; // xmm0_4
  float m_fHealth; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  UFG::BaseAnimationComponent *v23; // rcx
  float v24; // xmm1_4
  UFG::BaseAnimationComponent *m_pSimComponent; // rcx
  float v26; // xmm6_4
  UFG::TiDo *Instance; // rax
  UFG::SimObject *v28; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v32; // rdx
  unsigned int v33; // r8d
  unsigned int v34; // r9d
  unsigned int v35; // r8d
  unsigned int v36; // r9d
  UFG::GameStatTracker *v37; // rax

  m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
  if ( !m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0 )
  {
    this->m_fTimeSinceDamagedS = delta_sec + this->m_fTimeSinceDamagedS;
    m_pComponent = 0i64;
    IsAnyLocalPlayer = UFG::IsAnyLocalPlayer(m_pSimObject);
    if ( this->m_bIsKnockedOut )
    {
      m_pSimComponent = (UFG::BaseAnimationComponent *)this->m_CharacterAnimationComponent.m_pSimComponent;
      if ( m_pSimComponent )
        UFG::BaseAnimationComponent::UnbindRequiredAnimationBanks(m_pSimComponent);
      goto LABEL_43;
    }
    if ( this->m_fRegenerativeHealthRate <= 0.0 )
    {
LABEL_35:
      v23 = (UFG::BaseAnimationComponent *)this->m_CharacterAnimationComponent.m_pSimComponent;
      if ( v23 )
        UFG::BaseAnimationComponent::RebindRequiredAnimationBanks(v23);
      if ( !IsAnyLocalPlayer )
      {
LABEL_50:
        if ( this->m_fHealth > 0.0 || (v28 = this->m_pSimObject) == 0i64 )
        {
LABEL_81:
          if ( IsAnyLocalPlayer )
          {
            v37 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v37, Health, this->m_fHealth);
          }
          return;
        }
        m_Flags = v28->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::FaceActionComponent *)v28->m_Components.p[45].m_pComponent;
          goto LABEL_77;
        }
        if ( m_Flags < 0 )
        {
          vfptr = (unsigned int)v28[1].vfptr;
          size = v28->m_Components.size;
          if ( vfptr >= size )
            goto LABEL_77;
          v32 = (__int64)&v28->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
               || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v32 += 16i64;
            if ( vfptr >= size )
              goto LABEL_77;
          }
          goto LABEL_61;
        }
        if ( (m_Flags & 0x2000) != 0 )
        {
          v33 = (unsigned int)v28[1].vfptr;
          v34 = v28->m_Components.size;
          if ( v33 < v34 )
          {
            v32 = (__int64)&v28->m_Components.p[v33];
            while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                 || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v33;
              v32 += 16i64;
              if ( v33 >= v34 )
                goto LABEL_77;
            }
LABEL_61:
            m_pComponent = *(UFG::FaceActionComponent **)v32;
          }
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          v35 = (unsigned int)v28[1].vfptr;
          v36 = v28->m_Components.size;
          if ( v35 < v36 )
          {
            v32 = (__int64)&v28->m_Components.p[v35];
            while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                 || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF) != 0 )
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
          m_pComponent = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                                       v28,
                                                       UFG::FaceActionComponent::_TypeUID);
        }
LABEL_77:
        if ( m_pComponent )
        {
          if ( m_pComponent->mFaceActionEnabled )
            UFG::FaceActionComponent::KillEffect(m_pComponent);
          m_pComponent->mFaceActionEnabled = 0;
        }
        goto LABEL_81;
      }
      v24 = this->m_fArmour - (float)(UFG::HealthComponent::ms_fArmourDecay * delta_sec);
      if ( v24 < 0.0 )
        v24 = 0.0;
      this->m_fArmour = v24;
LABEL_43:
      if ( IsAnyLocalPlayer )
      {
        v26 = NISManager::GetInstance()->mState || !UFG::HealthComponent::ms_bEnableAudioEffects
            ? FLOAT_1000_0
            : this->m_fHealth;
        if ( last_health_rtpc != v26 )
        {
          Instance = UFG::TiDo::GetInstance();
          UFG::TiDo::SetWwiseRtpcValue(Instance, sym_health.mUID, v26, 0xFFFFFFFFFFFFFFFFui64);
          last_health_rtpc = v26;
        }
      }
      goto LABEL_50;
    }
    p_mNext = (UFG::SimComponent **)&this->m_HealthRegenerateTaskList.mNode.mNext[-3].mNext;
    if ( p_mNext != &this->m_CharacterAnimationComponent.m_pSimComponent )
    {
      m_fMaxHealth = this->m_fMaxHealth;
      if ( m_fMaxHealth >= (float)((float)(delta_sec * *((float *)&p_mNext[3]->m_BoundComponentHandles.mNode.mNext + 1))
                                 + this->m_fHealth) )
        m_fMaxHealth = (float)(delta_sec * *((float *)&p_mNext[3]->m_BoundComponentHandles.mNode.mNext + 1))
                     + this->m_fHealth;
      this->m_fHealth = m_fMaxHealth;
    }
    if ( !UFG::HealthComponent::ShouldRegenerateHealth(this) )
    {
      this->m_fRegenerationDelayS = s_fRegenerationDelayS;
LABEL_27:
      m_fHealthBoost = this->m_fHealthBoost;
      if ( m_fHealthBoost > 0.0 )
      {
        m_fHealth = this->m_fHealth;
        v20 = this->m_fMaxHealth;
        if ( m_fHealth >= v20 )
        {
          this->m_fHealthBoost = 0.0;
        }
        else
        {
          v21 = m_fHealth + (float)(UFG::HealthComponent::ms_fRegenerativeHealthBoostRate * delta_sec);
          if ( v20 >= v21 )
            v20 = v21;
          v22 = m_fHealthBoost - (float)(UFG::HealthComponent::ms_fRegenerativeHealthBoostRate * delta_sec);
          this->m_fHealth = v20;
          if ( v22 < 0.0 )
            v22 = 0.0;
          this->m_fHealthBoost = v22;
        }
      }
      goto LABEL_35;
    }
    m_fRegenerationDelayS = this->m_fRegenerationDelayS;
    if ( m_fRegenerationDelayS > 0.0 )
    {
      v16 = FLOAT_N1_0;
      v17 = m_fRegenerationDelayS - delta_sec;
      if ( v17 >= -1.0 )
        v16 = v17;
      this->m_fRegenerationDelayS = v16;
      goto LABEL_27;
    }
    v10 = *(float *)&FLOAT_1_0;
    if ( UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject) )
      v10 = UFG::PlayerBuffTracker::GetRegenerativeHealthRateMultiplier() + 1.0;
    v11 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v11, HealthRegen_Activated) < 0.0 )
    {
      v14 = this->m_fHealth;
      v12 = UFG::HealthComponent::ms_fRegenerativeHealthPhase1;
      if ( v14 < UFG::HealthComponent::ms_fRegenerativeHealthPhase1 )
      {
        v15 = (float)((float)(delta_sec * this->m_fRegenerativeHealthRate) * v10) + v14;
        if ( UFG::HealthComponent::ms_fRegenerativeHealthPhase1 >= v15 )
        {
          this->m_fHealth = v15;
          goto LABEL_27;
        }
        goto LABEL_22;
      }
      v12 = UFG::HealthComponent::ms_fRegenerativeHealthPhase2;
      if ( v14 >= UFG::HealthComponent::ms_fRegenerativeHealthPhase2 )
        goto LABEL_27;
      v13 = (float)((float)(UFG::HealthComponent::ms_fRegenerativeHealthRate2 * delta_sec) * v10) + v14;
    }
    else
    {
      v12 = this->m_fMaxHealth;
      v13 = (float)((float)(delta_sec * this->m_fRegenerativeHealthRate) * v10) + this->m_fHealth;
    }
    if ( v12 >= v13 )
      v12 = v13;
LABEL_22:
    this->m_fHealth = v12;
    goto LABEL_27;
  }
}

// File Line: 588
// RVA: 0x55E180
void __fastcall UFG::HealthComponent::UpdateAll(float sim_time_delta)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::HealthComponent::s_HealthComponentList.mNode.mNext - 4;
  for ( UFG::HealthComponent::s_HealthComponentpCurrentIterator = (UFG::HealthComponent *)&UFG::HealthComponent::s_HealthComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *)(&UFG::HealthComponent::s_HealthComponentList - 4);
        UFG::HealthComponent::s_HealthComponentpCurrentIterator = (UFG::HealthComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::HealthComponent::Update((UFG::HealthComponent *)v2, sim_time_delta);
      v2 = (UFG::qNode<UFG::HealthComponent,UFG::HealthComponent> *)UFG::HealthComponent::s_HealthComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::HealthComponent::s_HealthComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 597
// RVA: 0x521F60
bool __fastcall UFG::HealthComponent::ApplyHealthDamage(
        UFG::HealthComponent *this,
        const int iDamage,
        UFG::SimObjectCharacter *pAttacker,
        UFG::HitRecord *pHitRecord,
        bool bProjectileDamage)
{
  UFG::SimObject *m_pSimObject; // rax
  bool result; // al
  bool v10; // r15
  float v11; // xmm6_4
  float GeneralDamageReductionPercent; // xmm7_4
  float ProjectileDamageReductionPercent; // xmm0_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  UFG::GameStatTracker *v17; // rax
  UFG::GameStat::FloatStat v18; // edx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *CurrentGameCamera; // rax
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v20; // r14
  UFG::SimObject *v21; // rbx
  UFG::SimObjectCharacter *v22; // rbx
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rdx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v27; // rdx
  unsigned int v28; // r8d
  unsigned int v29; // r9d
  unsigned __int8 v30; // al

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject && (m_pSimObject->m_Flags & 0x400) != 0 )
    return 0;
  v10 = 0;
  v11 = (float)iDamage;
  if ( pAttacker != UFG::GetLocalPlayer() && !UFG::SimObjectUtility::IsPlayerVehicle(pAttacker) )
    v11 = v11 * this->m_NonPlayerDamageMultiplier;
  if ( UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject) )
  {
    GeneralDamageReductionPercent = UFG::PlayerBuffTracker::GetGeneralDamageReductionPercent();
    if ( bProjectileDamage )
    {
      ProjectileDamageReductionPercent = UFG::PlayerBuffTracker::GetProjectileDamageReductionPercent();
    }
    else if ( pHitRecord->mMeleeInfo.mAttackMaterialUID == gAttackMaterialWeaponEquipped.m_EnumSymbol.mUID )
    {
      ProjectileDamageReductionPercent = UFG::PlayerBuffTracker::GetMeleeWeaponDamageReductionPercent();
    }
    else
    {
      ProjectileDamageReductionPercent = UFG::PlayerBuffTracker::GetMeleeDamageReductionPercent();
    }
    v14 = v11 * (float)(1.0 - (float)(GeneralDamageReductionPercent + ProjectileDamageReductionPercent));
    if ( bProjectileDamage )
    {
      v15 = UFG::HealthComponent::ms_fMaxArmour;
      v14 = v14 * (float)(1.0 - this->m_fArmour);
      if ( UFG::HealthComponent::ms_fMaxArmour >= (float)((float)((float)(v14 * 0.0099999998)
                                                                * UFG::HealthComponent::ms_fDamageToArmourRatio)
                                                        + this->m_fArmour) )
        v15 = (float)((float)(v14 * 0.0099999998) * UFG::HealthComponent::ms_fDamageToArmourRatio) + this->m_fArmour;
      this->m_fArmour = v15;
    }
    v16 = this->m_fHealth - UFG::HealthComponent::ms_fLowHealthThreshold;
    if ( v16 <= 0.0 )
      v16 = 0.0;
    if ( v16 >= v14 )
      v16 = v14;
    v11 = (float)((float)(v14 - v16) * UFG::HealthComponent::ms_fLowHealthMultiplier) + v16;
  }
  if ( bProjectileDamage )
    v11 = v11 * this->m_ProjectileDamageMultiplier;
  if ( this->m_bIsTakingDamage && !this->m_bIsInvulnerable && !this->m_bIsKnockedOut )
  {
    v10 = UFG::HealthComponent::SetHealth(this, (int)(float)(this->m_fHealth - v11), pHitRecord);
    if ( v10 && UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject) )
    {
      v17 = UFG::GameStatTracker::Instance();
      v18 = RangedDamageReceived;
      if ( !bProjectileDamage )
        v18 = MeleeDamageReceived;
      UFG::GameStatTracker::ApplyDelta(v17, v18, v11);
    }
    this->m_fTimeSinceDamagedS = 0.0;
    CurrentGameCamera = UFG::GetCurrentGameCamera();
    v20 = CurrentGameCamera;
    if ( CurrentGameCamera )
    {
      v21 = this->m_pSimObject;
      if ( v21 == (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *))CurrentGameCamera->mPrev[8].mNext)(CurrentGameCamera) )
        ((void (__fastcall *)(UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *))v20->mPrev[16].mPrev)(v20);
    }
    v22 = (UFG::SimObjectCharacter *)this->m_pSimObject;
    if ( v22 == UFG::GetLocalPlayer() )
    {
      if ( !pAttacker )
        goto LABEL_69;
      if ( pAttacker != this->m_pSimObject )
        UFG::HealthComponent::SetDirectionalDamage(this, pAttacker);
    }
    if ( pAttacker )
    {
      m_Flags = pAttacker->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = pAttacker->m_Components.p[20].m_pComponent;
        if ( !m_pComponent
          || ((UFG::TargetingSystemPedBaseComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0
          || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          goto LABEL_44;
        }
LABEL_66:
        if ( m_pComponent )
        {
          v30 = *(_BYTE *)(*(_QWORD *)&m_pComponent[1].m_Flags + 86i64);
          if ( v30 )
            UFG::TargetingSimObject::SetTarget(
              (UFG::TargetingSimObject *)(*(_QWORD *)&m_pComponent[1].m_TypeUID + 56i64 * v30),
              this->m_pSimObject);
        }
        goto LABEL_69;
      }
      if ( m_Flags < 0 )
      {
        m_pComponent = pAttacker->m_Components.p[20].m_pComponent;
        if ( m_pComponent
          && ((UFG::TargetingSystemPedBaseComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) == 0 )
        {
          if ( (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
            m_pComponent = 0i64;
          goto LABEL_66;
        }
        goto LABEL_44;
      }
      if ( (m_Flags & 0x2000) != 0 )
      {
        mComponentTableEntryCount = pAttacker->mComponentTableEntryCount;
        size = pAttacker->m_Components.size;
        if ( mComponentTableEntryCount < size )
        {
          v27 = &pAttacker->m_Components.p[mComponentTableEntryCount];
          while ( (v27->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
               || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v27->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            ++v27;
            if ( mComponentTableEntryCount >= size )
            {
              m_pComponent = 0i64;
              goto LABEL_66;
            }
          }
LABEL_57:
          m_pComponent = v27->m_pComponent;
          goto LABEL_66;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(pAttacker, UFG::TargetingSystemPedBaseComponent::_TypeUID);
          goto LABEL_66;
        }
        v28 = pAttacker->mComponentTableEntryCount;
        v29 = pAttacker->m_Components.size;
        if ( v28 < v29 )
        {
          v27 = &pAttacker->m_Components.p[v28];
          while ( (v27->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
               || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v27->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v28;
            ++v27;
            if ( v28 >= v29 )
            {
              m_pComponent = 0i64;
              goto LABEL_66;
            }
          }
          goto LABEL_57;
        }
      }
LABEL_44:
      m_pComponent = 0i64;
      goto LABEL_66;
    }
  }
LABEL_69:
  result = v10;
  this->m_fHealthBoost = 0.0;
  return result;
}

// File Line: 836
// RVA: 0x54C6F0
void __fastcall UFG::HealthComponent::SetDirectionalDamage(UFG::HealthComponent *this, UFG::SimObject *pAttacker)
{
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *CurrentGameCamera; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v6; // rbp
  UFG::TransformNodeComponent *v7; // rsi
  float v8; // xmm1_4
  float v9; // xmm0_4
  int mPrev_high; // xmm1_4
  float v11; // xmm0_4
  int v12; // eax
  float v13; // xmm0_4
  UFG::qVector2 v2; // [rsp+40h] [rbp+8h] BYREF
  UFG::qVector2 v1; // [rsp+48h] [rbp+10h] BYREF

  CurrentGameCamera = UFG::GetCurrentGameCamera();
  m_pTransformNodeComponent = pAttacker->m_pTransformNodeComponent;
  v6 = CurrentGameCamera;
  v7 = this->m_pSimObject->m_pTransformNodeComponent;
  if ( CurrentGameCamera && m_pTransformNodeComponent && v7 && UFG::HealthComponent::IsProjectileAttack(this) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    UFG::TransformNodeComponent::UpdateWorldTransform(v7);
    v8 = m_pTransformNodeComponent->mWorldTransform.v3.x - v7->mWorldTransform.v3.x;
    v9 = m_pTransformNodeComponent->mWorldTransform.v3.y - v7->mWorldTransform.v3.y;
    LODWORD(v1.x) = LODWORD(v6[15].mPrev) ^ _xmm[0];
    v2.x = v8;
    mPrev_high = HIDWORD(v6[15].mPrev);
    v2.y = v9;
    LODWORD(v1.y) = mPrev_high ^ _xmm[0];
    v11 = UFG::qAngleBetween(&v1, &v2);
    v12 = 2;
    v13 = (float)(v11 * 180.0) * 0.31830987;
    if ( v13 >= 45.0 && v13 < 135.0 )
    {
      v12 = 0;
LABEL_14:
      this->m_bAttackDir[v12] = 1;
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
bool __fastcall UFG::HealthComponent::IsProjectileAttack(UFG::HealthComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v6; // rdx
  unsigned int v7; // r8d
  unsigned int v8; // r9d

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[15].m_pComponent;
      return m_pComponent
          && HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) == gAttackCollisionProjectile.m_EnumValue;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        v6 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::HitReactionComponent::_TypeUID & 0xFE000000)
             || (UFG::HitReactionComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v6 += 16i64;
          if ( vfptr >= size )
            goto LABEL_12;
        }
LABEL_13:
        m_pComponent = *(UFG::SimComponent **)v6;
        return m_pComponent
            && HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) == gAttackCollisionProjectile.m_EnumValue;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::HitReactionComponent::_TypeUID);
        return m_pComponent
            && HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) == gAttackCollisionProjectile.m_EnumValue;
      }
      v7 = (unsigned int)m_pSimObject[1].vfptr;
      v8 = m_pSimObject->m_Components.size;
      if ( v7 < v8 )
      {
        v6 = (__int64)&m_pSimObject->m_Components.p[v7];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::HitReactionComponent::_TypeUID & 0xFE000000)
             || (UFG::HitReactionComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
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
    m_pComponent = 0i64;
    return m_pComponent
        && HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) == gAttackCollisionProjectile.m_EnumValue;
  }
  m_pComponent = m_pSimObject->m_Components.p[15].m_pComponent;
  return m_pComponent
      && HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) == gAttackCollisionProjectile.m_EnumValue;
}

// File Line: 898
// RVA: 0x549620
void __fastcall UFG::HealthComponent::ReplenishHealth(UFG::HealthComponent *this)
{
  UFG::HealthComponent::SetRegenerativeHealthRatio(this, 1.0, 1);
  UFG::HealthComponent::SetHealth(this, (int)(float)(this->m_fRegenerativeHealthRatio * this->m_fMaxHealth), 0i64);
}

// File Line: 906
// RVA: 0x54D3D0
bool __fastcall UFG::HealthComponent::SetHealth(
        UFG::HealthComponent *this,
        const int uHealth,
        UFG::HitRecord *pReferenceHitRecord)
{
  float m_fHealth; // xmm6_4
  bool m_bIsKnockedOut; // si
  float m_fMaxHealth; // xmm0_4
  float m_fMinHealth; // xmm1_4
  bool v8; // di
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *m_pSimComponent; // rcx

  m_fHealth = this->m_fHealth;
  m_bIsKnockedOut = this->m_bIsKnockedOut;
  m_fMaxHealth = (float)uHealth;
  if ( (float)uHealth <= 0.0 )
    m_fMaxHealth = 0.0;
  if ( m_fMaxHealth >= this->m_fMaxHealth )
    m_fMaxHealth = this->m_fMaxHealth;
  this->m_fHealth = m_fMaxHealth;
  m_fMinHealth = this->m_fMinHealth;
  if ( m_fMaxHealth < m_fMinHealth )
  {
    this->m_bHealthClampedToMinimum = 1;
    this->m_fHealth = m_fMinHealth;
  }
  v8 = this->m_fHealth <= 0.0;
  if ( !this->m_bIsKnockedOut && this->m_fHealth <= 0.0 )
    UFG::HealthComponent::OnDeath(this, pReferenceHitRecord);
  this->m_bIsKnockedOut = v8;
  if ( v8 && !m_bIsKnockedOut )
  {
    v9 = UFG::qMalloc(0x50ui64, "EvtEntityDied", 0i64);
    if ( v9 )
      UFG::EvtEntityDied::EvtEntityDied((UFG::EvtEntityDied *)v9, "EVT_ENTITY_DEATH", this->m_pSimObject);
    UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v9);
    m_pSimComponent = this->m_HitReactionComponent.m_pSimComponent;
    if ( m_pSimComponent )
      BYTE1(m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext) = 1;
  }
  return m_fHealth != this->m_fHealth || m_bIsKnockedOut != this->m_bIsKnockedOut;
}

// File Line: 937
// RVA: 0x54D980
void __fastcall UFG::HealthComponent::SetMaxHealth(UFG::HealthComponent *this, const int iMaxHealth)
{
  float m_fMaxUpgradedHealth; // xmm0_4
  float m_fHealth; // xmm1_4
  bool v5; // di

  m_fMaxUpgradedHealth = (float)iMaxHealth;
  if ( (float)iMaxHealth >= this->m_fMaxUpgradedHealth )
    m_fMaxUpgradedHealth = this->m_fMaxUpgradedHealth;
  this->m_fMaxHealth = m_fMaxUpgradedHealth;
  m_fHealth = this->m_fHealth;
  if ( m_fHealth >= m_fMaxUpgradedHealth )
    m_fHealth = m_fMaxUpgradedHealth;
  this->m_fHealth = m_fHealth;
  v5 = m_fHealth <= 0.0;
  if ( this->m_bIsKnockedOut || m_fHealth > 0.0 )
  {
    this->m_bIsKnockedOut = v5;
  }
  else
  {
    this->m_fTimeOfDeath = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::GetLocalPlayer();
    this->m_bIsKnockedOut = v5;
  }
}

// File Line: 946
// RVA: 0x54DA00
void __fastcall UFG::HealthComponent::SetMinHealth(UFG::HealthComponent *this, const int iMinHealth)
{
  bool v2; // cc

  v2 = (float)iMinHealth <= this->m_fHealth;
  this->m_fMinHealth = (float)iMinHealth;
  if ( !v2 )
  {
    this->m_fHealth = (float)iMinHealth;
    this->m_bHealthClampedToMinimum = 1;
  }
}

// File Line: 958
// RVA: 0x54E570
void __fastcall UFG::HealthComponent::SetRegenerativeHealthRatio(
        UFG::HealthComponent *this,
        float fRegenerativeHealthRatio,
        bool saveSnapshot)
{
  bool IsAnyLocalPlayer; // di
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax

  if ( fRegenerativeHealthRatio <= UFG::HealthComponent::ms_fRegenerativeHealthRatioMin )
    fRegenerativeHealthRatio = UFG::HealthComponent::ms_fRegenerativeHealthRatioMin;
  if ( fRegenerativeHealthRatio >= 1.0 )
    fRegenerativeHealthRatio = *(float *)&FLOAT_1_0;
  this->m_fRegenerativeHealthRatio = fRegenerativeHealthRatio;
  IsAnyLocalPlayer = UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject);
  if ( IsAnyLocalPlayer )
  {
    v6 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v6, HealthRegen_Activated) >= 0.0 )
      this->m_fRegenerativeHealthRatio = 1.0;
  }
  if ( saveSnapshot && IsAnyLocalPlayer )
  {
    v7 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v7, RegenHealthRatio, this->m_fRegenerativeHealthRatio);
  }
}

// File Line: 979
// RVA: 0x52DFA0
unsigned __int8 __fastcall UFG::HealthComponent::GetIsKilled(UFG::HealthComponent *this)
{
  unsigned int v2; // eax
  unsigned int MostUsedIndex; // r8d
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rcx

  v2 = _S65;
  if ( (_S65 & 1) == 0 )
  {
    _S65 |= 1u;
    UID_Dead.mUID = UFG::qStringHashUpper32("Dead", -1);
    v2 = _S65;
  }
  if ( (v2 & 2) != 0 )
  {
    MostUsedIndex = mostUsed_Dead;
  }
  else
  {
    _S65 = v2 | 2;
    MostUsedIndex = GetMostUsedIndex(UID_Dead.mUID);
    mostUsed_Dead = MostUsedIndex;
  }
  if ( !this->m_bIsKnockedOut )
    return 0;
  m_pSimComponent = this->m_HitReactionComponent.m_pSimComponent;
  if ( m_pSimComponent && (vfptr = m_pSimComponent[8].vfptr) != 0i64 )
    return ActionController::IsPlaying((ActionController *)&vfptr[24], &UID_Dead, MostUsedIndex, 1);
  else
    return 1;
}

// File Line: 1039
// RVA: 0x5209C0
void __fastcall UFG::HealthComponent::AddHealthRegenerateTask(
        UFG::HealthComponent *this,
        HealthRegenerateTask *pHealthRegenerateTask)
{
  UFG::qNode<HealthRegenerateTask,HealthRegenerateTaskList> *v2; // rdx
  UFG::qList<HealthRegenerateTask,HealthRegenerateTaskList,0,0> *p_m_HealthRegenerateTaskList; // rcx
  UFG::qNode<HealthRegenerateTask,HealthRegenerateTaskList> *mPrev; // rax

  v2 = &pHealthRegenerateTask->UFG::qNode<HealthRegenerateTask,HealthRegenerateTaskList>;
  p_m_HealthRegenerateTaskList = &this->m_HealthRegenerateTaskList;
  mPrev = p_m_HealthRegenerateTaskList->mNode.mPrev;
  mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = &p_m_HealthRegenerateTaskList->mNode;
  p_m_HealthRegenerateTaskList->mNode.mPrev = v2;
}

