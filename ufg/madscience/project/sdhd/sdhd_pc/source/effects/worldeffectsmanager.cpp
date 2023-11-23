// File Line: 88
// RVA: 0x400CA0
void UFG::WorldEffectsManager::Init(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::WorldEffectsManager *v1; // rax

  v0 = UFG::qMalloc(0x928ui64, "WorldEffectsManager", 0i64);
  if ( v0 )
  {
    UFG::WorldEffectsManager::WorldEffectsManager((UFG::WorldEffectsManager *)v0);
    UFG::WorldEffectsManager::sInstance = v1;
  }
  else
  {
    UFG::WorldEffectsManager::sInstance = 0i64;
  }
}

// File Line: 105
// RVA: 0x400930
UFG::WorldEffectsManager *__fastcall UFG::WorldEffectsManager::Get()
{
  return UFG::WorldEffectsManager::sInstance;
}

// File Line: 122
// RVA: 0x3FDF00
void __fastcall UFG::WorldEffectsManager::WorldEffectsManager(UFG::WorldEffectsManager *this)
{
  __int64 v2; // rbp
  UFG::WorldEffectsManager::WorldEffectElement *mWorldEffectElements; // rsi
  __int64 v4; // r14
  UFG::TransformNodeComponent **p_mTransformNode; // rbx
  UFG::WorldEffectsManager *v6; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::TransformNodeComponent *v9; // rax
  UFG::TransformNodeComponent **v10; // rbx
  UFG::qMemoryPool *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::TransformNodeComponent *v13; // rax

  v2 = 15i64;
  `eh vector constructor iterator(
    this,
    0x68ui64,
    15,
    (void (__fastcall *)(void *))UFG::WorldEffectsManager::UIElement::UIElement);
  mWorldEffectElements = this->mWorldEffectElements;
  v4 = 5i64;
  `eh vector constructor iterator(
    this->mWorldEffectElements,
    0x90ui64,
    5,
    (void (__fastcall *)(void *))UFG::WorldEffectsManager::WorldEffectElement::WorldEffectElement);
  *(_WORD *)&this->mShowHealthUIs = 0;
  this->mTriggeredBuffEffect = 0;
  this->mPlayerFaction = FACTION_INVALID;
  this->mFocusTarget.mPrev = &this->mFocusTarget;
  this->mFocusTarget.mNext = &this->mFocusTarget;
  this->mFocusTarget.m_pPointer = 0i64;
  this->mHealthMeterActive = 0;
  *(_QWORD *)&this->mCheckForHostileTimer = 0i64;
  this->mGlobalAlpha = 0.0;
  p_mTransformNode = &this->mUIElements[0].mTransformNode;
  v6 = this;
  do
  {
    UFG::WorldEffectsManager::UIElement::Reset(v6->mUIElements);
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v8 = UFG::qMemoryPool::Allocate(
           SimulationMemoryPool,
           0x110ui64,
           "WorldEffectsManager::TransformNodeComponent",
           0i64,
           1u);
    if ( v8 )
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v8, 0xDEADBEEF, 0i64, 0);
    else
      v9 = 0i64;
    *p_mTransformNode = v9;
    v6 = (UFG::WorldEffectsManager *)((char *)v6 + 104);
    p_mTransformNode += 13;
    --v2;
  }
  while ( v2 );
  v10 = &this->mWorldEffectElements[0].mTransformNode;
  do
  {
    UFG::qMemSet(mWorldEffectElements, 0, 0x90u);
    v11 = UFG::GetSimulationMemoryPool();
    v12 = UFG::qMemoryPool::Allocate(v11, 0x110ui64, "WorldEffectsManager::TransformNodeComponent", 0i64, 1u);
    if ( v12 )
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v12, 0xDEADBEEF, 0i64, 0);
    else
      v13 = 0i64;
    *v10 = v13;
    ++mWorldEffectElements;
    v10 += 18;
    --v4;
  }
  while ( v4 );
}

// File Line: 181
// RVA: 0x400D00
char __fastcall UFG::WorldEffectsManager::IsWorldEffectActive(
        UFG::WorldEffectsManager *this,
        UFG::WorldEffectsManager::WorldEffectType type)
{
  int v2; // r8d
  UFG::WorldEffectsManager::WorldEffectElement *i; // rax

  v2 = 0;
  for ( i = this->mWorldEffectElements; !i->mActive || i->mEffectType != type; ++i )
  {
    if ( (unsigned int)++v2 >= 5 )
      return 0;
  }
  return 1;
}

// File Line: 204
// RVA: 0x3FEC60
__int64 __fastcall UFG::WorldEffectsManager::AllocUIElement(UFG::WorldEffectsManager *this)
{
  __int64 result; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  result = 0i64;
  while ( this->mUIElements[0].mComponent.m_pPointer )
  {
    result = (unsigned int)(result + 1);
    this = (UFG::WorldEffectsManager *)((char *)this + 104);
    if ( (unsigned int)result >= 0xF )
      return 0xFFFFFFFFi64;
  }
  *(_QWORD *)&this->mUIElements[0].mHealthUIType = 0i64;
  this->mUIElements[0].mHealthUIID = -1;
  this->mUIElements[0].mCurrentHealthUI = HealthUI_Num;
  this->mUIElements[0].mFightClassUIID = -1;
  y = UFG::qVector3::msDirUp.y;
  z = UFG::qVector3::msDirUp.z;
  this->mUIElements[0].mCurrentNormal.x = UFG::qVector3::msDirUp.x;
  this->mUIElements[0].mCurrentNormal.y = y;
  this->mUIElements[0].mCurrentNormal.z = z;
  v4 = UFG::qVector3::msDirUp.y;
  v5 = UFG::qVector3::msDirUp.z;
  this->mUIElements[0].mPreviousNormal.x = UFG::qVector3::msDirUp.x;
  this->mUIElements[0].mPreviousNormal.y = v4;
  this->mUIElements[0].mPreviousNormal.z = v5;
  return result;
}

// File Line: 227
// RVA: 0x400820
void __fastcall UFG::WorldEffectsManager::FreeUIElement(UFG::WorldEffectsManager *this, unsigned int index)
{
  UFG::WorldEffectsManager::UIElement *v2; // rbx
  Render::FXOverride *m_pPointer; // rax
  int *p_mReferenceCount; // rdi
  unsigned int mFightClassUIID; // edx
  Render::FXOverride *v6; // rax
  int *v7; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterEffectsComponent> *p_mComponent; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  if ( index != -1 )
  {
    v2 = &this->mUIElements[index];
    Render::FXManager::KillEffect(&Render::gFXManager, v2->mHealthUIID, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
    m_pPointer = v2->mHealthFXOverride.m_pPointer;
    if ( m_pPointer )
    {
      --m_pPointer->mReferenceCount;
      p_mReferenceCount = &v2->mHealthFXOverride.m_pPointer->mReferenceCount;
      if ( *p_mReferenceCount <= 0 )
      {
        if ( p_mReferenceCount )
        {
          Render::FXOverride::~FXOverride(v2->mHealthFXOverride.m_pPointer);
          operator delete[](p_mReferenceCount);
        }
        v2->mHealthFXOverride.m_pPointer = 0i64;
      }
      v2->mHealthFXOverride.m_pPointer = 0i64;
    }
    mFightClassUIID = v2->mFightClassUIID;
    v2->mHealthUIType = HealthUIType_Normal;
    v2->mHealthUIID = -1;
    v2->mCurrentHealthUI = HealthUI_Num;
    Render::FXManager::KillEffect(&Render::gFXManager, mFightClassUIID, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
    v6 = v2->mFightClassFXOverride.m_pPointer;
    if ( v6 )
    {
      --v6->mReferenceCount;
      v7 = &v2->mFightClassFXOverride.m_pPointer->mReferenceCount;
      if ( *v7 <= 0 )
      {
        if ( v7 )
        {
          Render::FXOverride::~FXOverride(v2->mFightClassFXOverride.m_pPointer);
          operator delete[](v7);
        }
        v2->mFightClassFXOverride.m_pPointer = 0i64;
      }
      v2->mFightClassFXOverride.m_pPointer = 0i64;
    }
    v2->mFightClassUIType = FightClassUIType_None;
    v2->mFightClassUIID = -1;
    p_mComponent = &v2->mComponent;
    if ( p_mComponent->m_pPointer )
    {
      mPrev = p_mComponent->mPrev;
      mNext = p_mComponent->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mComponent->mPrev = p_mComponent;
      p_mComponent->mNext = p_mComponent;
    }
    p_mComponent->m_pPointer = 0i64;
  }
}

// File Line: 251
// RVA: 0x3FFE90
void __fastcall UFG::WorldEffectsManager::BeginFrame(UFG::WorldEffectsManager *this, float dt)
{
  bool v3; // di
  bool v4; // al
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObject *m_pPointer; // r14
  UFG::SimObject *v7; // r15
  UFG::SimComponent *ComponentOfType; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::SimComponent *v10; // rbp
  float x; // ecx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mFocusTarget; // rdx
  float z; // xmm1_4
  UFG::SimObject *v14; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  __int64 v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObject *v21; // rax
  UFG::SimComponent *v22; // rbx
  UFG::SimComponent *v23; // rax
  bool v24; // cl
  bool v25; // al
  UFG::TransformNodeComponent *v26; // rdi
  UFG::TransformNodeComponent *v27; // rbx
  UFG::GameStatTracker *v28; // rax
  float Stat; // xmm0_4

  v3 = 0;
  if ( !UFG::LocalPlayerIsInCombatManager::s_pInstance
    || !UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0)
    || (v4 = 1, UFG::WorldEffectsManager::sDisableHealthUIs) )
  {
    v4 = 0;
  }
  this->mShowHealthUIs = v4;
  if ( v4 )
  {
    LocalPlayer = UFG::GetLocalPlayer();
    m_pPointer = this->mFocusTarget.m_pPointer;
    v7 = LocalPlayer;
    ComponentOfType = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pTransformNodeComponent = v7->m_pTransformNodeComponent;
    v10 = ComponentOfType;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    p_mFocusTarget = &this->mFocusTarget;
    z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    this->mPlayerPos.y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    this->mPlayerPos.z = z;
    this->mPlayerPos.x = x;
    if ( v10 )
    {
      v14 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + 30i64)
                               + *(_QWORD *)&v10[1].m_TypeUID
                               + 40);
      if ( this->mFocusTarget.m_pPointer )
      {
        mPrev = p_mFocusTarget->mPrev;
        mNext = this->mFocusTarget.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mFocusTarget->mPrev = p_mFocusTarget;
        this->mFocusTarget.mNext = &this->mFocusTarget;
      }
      this->mFocusTarget.m_pPointer = v14;
      if ( v14 )
      {
        v17 = v14->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v17->mNext = p_mFocusTarget;
        p_mFocusTarget->mPrev = v17;
        this->mFocusTarget.mNext = &v14->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v14->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mFocusTarget;
      }
      this->mPlayerFaction = (UFG::eFactionClassEnum)UFG::SimObject::GetComponentOfType(
                                                       v7,
                                                       UFG::SimObjectCharacterPropertiesComponent::_TypeUID)[3].m_SafePointerList.mNode.mPrev;
      v18 = *(_QWORD *)&v10[1].m_TypeUID + 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + 30i64);
      if ( *(_QWORD *)(v18 + 40) && *(_BYTE *)(v18 + 49) )
        v3 = 1;
    }
    else
    {
      if ( this->mFocusTarget.m_pPointer )
      {
        v19 = p_mFocusTarget->mPrev;
        v20 = this->mFocusTarget.mNext;
        v19->mNext = v20;
        v20->mPrev = v19;
        p_mFocusTarget->mPrev = p_mFocusTarget;
        this->mFocusTarget.mNext = &this->mFocusTarget;
      }
      this->mFocusTarget.m_pPointer = 0i64;
      this->mPlayerFaction = FACTION_INVALID;
    }
    this->mFocusTargetLocked = v3;
    if ( v3 )
    {
      if ( m_pPointer )
      {
        v21 = this->mFocusTarget.m_pPointer;
        if ( v21 )
        {
          if ( m_pPointer != v21 )
          {
            v22 = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterEffectsComponent::_TypeUID);
            v23 = UFG::SimObject::GetComponentOfType(
                    this->mFocusTarget.m_pPointer,
                    UFG::CharacterEffectsComponent::_TypeUID);
            v24 = v22 && HIDWORD(v22[6].m_pSimObject) != -1;
            v25 = v23 && HIDWORD(v23[6].m_pSimObject) != -1;
            if ( v24 && v25 )
            {
              v26 = this->mFocusTarget.m_pPointer->m_pTransformNodeComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(v26);
              v27 = m_pPointer->m_pTransformNodeComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(v27);
              UFG::WorldEffectsManager::StartWorldEffect(
                this,
                WorldEffectType_FocusChange,
                (UFG::qVector3 *)&v27->mWorldTransform.v3,
                (UFG::qVector3 *)&v26->mWorldTransform.v3,
                &UFG::qMatrix44::msIdentity,
                UFG::WorldEffectsManager::sTargetSwapDuration);
            }
          }
        }
      }
    }
    v28 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v28, PlayerFaceMeterBuff_Activated);
    if ( Stat <= 0.0 )
      goto LABEL_36;
    if ( !this->mTriggeredBuffEffect )
    {
      UFG::WorldEffectsManager::StartWorldEffect(
        this,
        WorldEffectType_BuffEffect,
        &this->mPlayerPos,
        &this->mPlayerPos,
        &UFG::qMatrix44::msIdentity,
        -1.0);
      this->mTriggeredBuffEffect = 1;
      return;
    }
    if ( Stat <= 0.0 )
LABEL_36:
      this->mTriggeredBuffEffect = 0;
  }
}

// File Line: 314
// RVA: 0x4006E0
void __fastcall UFG::WorldEffectsManager::EndFrame(UFG::WorldEffectsManager *this, float dt)
{
  float v3; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4

  v3 = this->mHealthUITimer - dt;
  v5 = this->mCheckForHostileTimer - dt;
  this->mHealthUITimer = v3;
  this->mCheckForHostileTimer = v5;
  if ( v3 < 0.0 && v5 < 0.0 )
  {
    this->mHealthMeterActive = 0;
    this->mGlobalAlpha = 0.0;
  }
  if ( !this->mFocusTargetLocked )
  {
    if ( v3 <= 0.0 )
    {
      v3 = 0.0;
    }
    else
    {
      v7 = *(float *)&FLOAT_1_0;
      if ( v3 >= 1.0 )
        goto LABEL_13;
    }
    v7 = v3;
LABEL_13:
    this->mGlobalAlpha = v7;
    goto LABEL_14;
  }
  v6 = (float)(dt * 4.0) + this->mGlobalAlpha;
  if ( v6 >= 1.0 )
    v6 = *(float *)&FLOAT_1_0;
  this->mGlobalAlpha = v6;
LABEL_14:
  UFG::WorldEffectsManager::UpdateUIEffects(this, dt);
  UFG::WorldEffectsManager::UpdateWorldEffects(this, dt);
}

// File Line: 341
// RVA: 0x402CB0
void __fastcall UFG::WorldEffectsManager::UpdateUIEffects(
        UFG::WorldEffectsManager *this,
        UFG::CharacterEffectsComponent *component)
{
  bool v2; // r12
  bool v3; // r14
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObjectCVBase *m_pSimObject; // rbp
  UFG::HealthComponent *m_pComponent; // rcx
  UFG::ActiveAIEntityComponent *v9; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v10; // rax
  UFG::SimComponent *v11; // r15
  UFG::eFactionClassEnum m_eFactionClass; // ebx
  UFG::GameStatTracker *v13; // rax
  __m128 mPrev_high; // xmm2
  float v15; // xmm0_4
  float v16; // xmm1_4
  UFG::SimComponentHolder *p; // rcx
  bool HasRangedWeaponEquippedWithAmmo; // al
  bool v19; // zf
  float v20; // xmm0_4
  float mHealthUITimer; // xmm0_4
  unsigned int v22; // eax

  v2 = 0;
  v3 = 0;
  if ( this->mShowHealthUIs && component->ShowHealthBar )
  {
    LocalPlayer = UFG::GetLocalPlayer();
    m_pSimObject = (UFG::SimObjectCVBase *)component->m_pSimObject;
    if ( m_pSimObject != LocalPlayer )
    {
      if ( m_pSimObject )
      {
        m_pComponent = (UFG::HealthComponent *)m_pSimObject->m_Components.p[6].m_pComponent;
        if ( m_pComponent )
        {
          if ( !UFG::HealthComponent::GetIsKilled(m_pComponent) )
          {
            v9 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pSimObject);
            v10 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pSimObject);
            v11 = m_pSimObject->m_Components.p[2].m_pComponent;
            if ( v9 )
            {
              if ( v10 )
              {
                if ( v11 )
                {
                  if ( UFG::g_AIObjectiveParams[v9->m_CurrentObjective].m_IsHostile )
                  {
                    m_eFactionClass = v10->m_eFactionClass;
                    v13 = UFG::FactionInterface::Get();
                    v2 = (unsigned int)UFG::FactionInterface::GetStanding(
                                         &v13->mFactionInterface,
                                         this->mPlayerFaction,
                                         m_eFactionClass) == 0;
                    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11);
                    mPrev_high = (__m128)HIDWORD(v11[2].m_BoundComponentHandles.mNode.mPrev);
                    v15 = *(float *)&v11[2].m_BoundComponentHandles.mNode.mPrev - this->mPlayerPos.x;
                    v16 = *(float *)&v11[2].m_BoundComponentHandles.mNode.mNext - this->mPlayerPos.z;
                    mPrev_high.m128_f32[0] = (float)((float)((float)(mPrev_high.m128_f32[0] - this->mPlayerPos.y)
                                                           * (float)(mPrev_high.m128_f32[0] - this->mPlayerPos.y))
                                                   + (float)(v15 * v15))
                                           + (float)(v16 * v16);
                    if ( _mm_sqrt_ps(mPrev_high).m128_f32[0] < (float)(UFG::WorldEffectsManager::sAlphaUIRadius * 1.2) )
                    {
                      p = m_pSimObject->m_Components.p;
                      if ( !p[44].m_pComponent )
                      {
                        HasRangedWeaponEquippedWithAmmo = UFG::HasRangedWeaponEquippedWithAmmo((UFG::TargetingSystemBaseComponent *)p[20].m_pComponent);
                        v3 = !HasRangedWeaponEquippedWithAmmo;
                        if ( !HasRangedWeaponEquippedWithAmmo )
                          goto LABEL_15;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( this->mFocusTargetLocked )
  {
LABEL_15:
    v19 = !this->mHealthMeterActive;
    this->mCheckForHostileTimer = UFG::WorldEffectsManager::sCheckForHostileTimeout;
    if ( v19 )
    {
      this->mHealthMeterActive = 1;
      v20 = UFG::WorldEffectsManager::sHealthUITimeout;
      this->mGlobalAlpha = 1.0;
      this->mHealthUITimer = v20;
    }
    if ( this->mFocusTargetLocked )
    {
      mHealthUITimer = this->mHealthUITimer;
      if ( mHealthUITimer <= UFG::WorldEffectsManager::sLockOnHealthUITimeout )
        mHealthUITimer = UFG::WorldEffectsManager::sLockOnHealthUITimeout;
      this->mHealthUITimer = mHealthUITimer;
    }
  }
  if ( v3 && this->mHealthMeterActive && this->mGlobalAlpha > 0.0 )
  {
    if ( component->mUIElementIndex == -1 )
    {
      v22 = UFG::WorldEffectsManager::AllocUIElement(this);
      component->mUIElementIndex = v22;
      if ( v22 != -1 )
      {
        UFG::qSafePointer<Creature,Creature>::operator=(
          (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->mUIElements[v22].mComponent,
          component);
        this->mUIElements[component->mUIElementIndex].mIsAlly = v2;
      }
    }
  }
  else
  {
    UFG::WorldEffectsManager::FreeUIElement(this, component->mUIElementIndex);
    component->mUIElementIndex = -1;
  }
}

// File Line: 427
// RVA: 0x4010C0
void __fastcall UFG::WorldEffectsManager::RemoveUIEffects(
        UFG::WorldEffectsManager *this,
        UFG::CharacterEffectsComponent *component)
{
  unsigned int mUIElementIndex; // edx

  mUIElementIndex = component->mUIElementIndex;
  if ( mUIElementIndex != -1 )
  {
    UFG::WorldEffectsManager::FreeUIElement(this, mUIElementIndex);
    component->mUIElementIndex = -1;
  }
}

// File Line: 438
// RVA: 0x4022D0
void __fastcall UFG::WorldEffectsManager::UpdateUIEffects(UFG::WorldEffectsManager *this, float dt)
{
  float v2; // xmm9_4
  unsigned int v3; // ebx
  __int64 v4; // r12
  UFG::WorldEffectsManager *v5; // rdi
  UFG::WorldEffectsManager::UIElement *v6; // rsi
  __int64 m_pPointer; // r15
  UFG::SimObjectCVBase *v8; // r14
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v10; // r13
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v13; // zf
  UFG::SimObjectGame *v14; // rcx
  __int16 v15; // cx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfType; // rax
  bool v17; // al
  int v18; // r15d
  int v19; // r12d
  unsigned int mMainEffect; // edi
  UFG::allocator::free_link *Override; // rax
  __int64 mCurrentHealthUI; // rax
  __int64 v23; // rdi
  unsigned int *p_mDepleteEffect; // rbx
  int v25; // edi
  Render::FXOverride *v26; // rax
  int *p_mReferenceCount; // r15
  UFG::allocator::free_link *v28; // rax
  unsigned int v29; // edx
  UFG::allocator::free_link *v30; // rax
  __int16 v31; // cx
  UFG::CharacterAnimationComponent *v32; // rax
  Creature *mCreature; // rcx
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm8_4
  UFG::BaseCameraComponent *v38; // rax
  float x; // xmm12_4
  float y; // xmm13_4
  float z; // xmm14_4
  __int128 x_low; // xmm4
  __m128 y_low; // xmm5
  __m128 v44; // xmm2
  float v45; // xmm1_4
  float v46; // xmm4_4
  float v47; // xmm6_4
  float v48; // xmm3_4
  __m128 v49; // xmm7
  float v50; // xmm8_4
  __m128 v51; // xmm1
  float v52; // xmm2_4
  float v53; // xmm6_4
  float v54; // xmm5_4
  __m128 v55; // xmm3
  float v56; // xmm2_4
  float v57; // xmm3_4
  float v58; // xmm7_4
  float v59; // xmm8_4
  float v60; // xmm1_4
  float v61; // xmm1_4
  float v62; // xmm6_4
  __m128 v63; // xmm3
  float v64; // xmm0_4
  float v65; // xmm8_4
  __m128 v66; // xmm7
  float v67; // xmm1_4
  float v68; // xmm7_4
  float v69; // xmm9_4
  float v70; // xmm3_4
  float v71; // xmm2_4
  float v72; // xmm1_4
  UFG::TransformNodeComponent *mTransformNode; // rcx
  __m128 v74; // xmm2
  float v75; // xmm1_4
  Render::FXOverride *v76; // rax
  float v77; // xmm1_4
  Render::FXOverride *v78; // rax
  UFG::qVector3 result; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v80; // [rsp+50h] [rbp-B0h]
  __int64 v81; // [rsp+58h] [rbp-A8h]
  int v82[4]; // [rsp+60h] [rbp-A0h] BYREF
  int v83[4]; // [rsp+70h] [rbp-90h] BYREF
  UFG::qMatrix44 m; // [rsp+80h] [rbp-80h] BYREF
  bool v87; // [rsp+1C0h] [rbp+C0h]
  unsigned int v88; // [rsp+1C8h] [rbp+C8h]

  v2 = FLOAT_15_0;
  v3 = 0;
  v4 = 0i64;
  v5 = this;
  v88 = 0;
  v80 = 0i64;
  do
  {
    v6 = &v5->mUIElements[v4];
    m_pPointer = (__int64)v6->mComponent.m_pPointer;
    v81 = m_pPointer;
    if ( !m_pPointer )
      goto LABEL_114;
    v8 = *(UFG::SimObjectCVBase **)(m_pPointer + 40);
    if ( v6->mIsAlly )
    {
      if ( v6->mHealthUIID == -1 )
        v6->mHealthUIID = Render::FXManager::CreateEffect(
                            &Render::gFXManager,
                            UFG::WorldEffectsManager::sFriendlyTargedEffectID,
                            v6->mTransformNode,
                            0xFFFFFFFF,
                            0i64);
      goto LABEL_66;
    }
    if ( v8 )
    {
      m_Flags = v8->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v8->m_Components.p[6].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                *(UFG::SimObjectGame **)(m_pPointer + 40),
                                UFG::HealthComponent::_TypeUID);
        }
        else
        {
          v13 = (m_Flags & 0x1000) == 0;
          v14 = *(UFG::SimObjectGame **)(m_pPointer + 40);
          if ( v13 )
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v14, UFG::HealthComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::HealthComponent::_TypeUID);
        }
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = v8->m_Components.p[6].m_pComponent;
      }
      v15 = v8->m_Flags;
      if ( (v15 & 0x4000) != 0 || v15 < 0 )
      {
        ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v8);
      }
      else if ( (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
      {
        ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          v8,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          v8,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      v10 = ComponentOfType;
    }
    else
    {
      m_pComponent = 0i64;
      v10 = 0i64;
    }
    v17 = v8 == v5->mFocusTarget.m_pPointer
       && v5->mFocusTargetLocked
       && !UFG::WorldEffectsManager::IsWorldEffectActive(v5, WorldEffectType_FocusChange);
    v87 = v17;
    if ( *(_BYTE *)(m_pPointer + 432) )
      v18 = v17 + 2;
    else
      v18 = v17;
    v19 = (int)(float)((float)(*((float *)&m_pComponent[1].m_SafePointerList.mNode.mNext + 1)
                             / *(float *)&m_pComponent[1].m_NameUID)
                     * 4.0);
    if ( v19 > 3 )
      v19 = 3;
    if ( v6->mHealthUIType != v18 || v6->mCurrentHealthUI != v19 || v6->mHealthUIID == -1 )
    {
      Render::FXManager::KillEffect(&Render::gFXManager, v6->mHealthUIID, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
      mMainEffect = UFG::WorldEffectsManager::sHealthUIEffectIds[4 * v18 + v19].mMainEffect;
      Override = Render::FXOverride::CreateOverride("mHealthFXOverride", 0i64);
      FX::SharedPointer<Render::FXOverride>::Set(&v6->mHealthFXOverride, (Render::FXOverride *)Override);
      v6->mHealthUIID = Render::FXManager::CreateEffect(
                          &Render::gFXManager,
                          mMainEffect,
                          v6->mTransformNode,
                          0xFFFFFFFF,
                          v6->mHealthFXOverride.m_pPointer);
      mCurrentHealthUI = v6->mCurrentHealthUI;
      if ( (_DWORD)mCurrentHealthUI != 4 && (int)mCurrentHealthUI > v19 && mCurrentHealthUI != v19 )
      {
        v23 = (int)v6->mCurrentHealthUI - (__int64)v19;
        p_mDepleteEffect = &UFG::WorldEffectsManager::sHealthUIEffectIds[4 * v18 + mCurrentHealthUI].mDepleteEffect;
        do
        {
          Render::FXManager::CreateEffect(&Render::gFXManager, *p_mDepleteEffect, v6->mTransformNode, 0xFFFFFFFF, 0i64);
          p_mDepleteEffect -= 2;
          --v23;
        }
        while ( v23 );
      }
      v6->mHealthUIType = v18;
      v6->mCurrentHealthUI = v19;
    }
    if ( v10->m_eFightingClass == eFIGHTING_CLASS_STRIKER_BRAWLER )
    {
      v25 = 1;
    }
    else if ( v10->m_eFightingClass == eFIGHTING_CLASS_GRAPPLER )
    {
      v25 = 2;
    }
    else
    {
      v25 = 0;
    }
    if ( v6->mFightClassUIType != v25 || v6->mFightClassUIID == -1 )
    {
      Render::FXManager::KillEffect(&Render::gFXManager, v6->mFightClassUIID, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
      v6->mFightClassUIID = -1;
      v26 = v6->mFightClassFXOverride.m_pPointer;
      if ( v26 )
      {
        --v26->mReferenceCount;
        p_mReferenceCount = &v6->mFightClassFXOverride.m_pPointer->mReferenceCount;
        if ( *p_mReferenceCount <= 0 )
        {
          if ( p_mReferenceCount )
          {
            Render::FXOverride::~FXOverride(v6->mFightClassFXOverride.m_pPointer);
            operator delete[](p_mReferenceCount);
          }
          v6->mFightClassFXOverride.m_pPointer = 0i64;
        }
        v6->mFightClassFXOverride.m_pPointer = 0i64;
      }
      if ( v25 == 1 )
      {
        v30 = Render::FXOverride::CreateOverride("mFightClassFXOverride", 0i64);
        FX::SharedPointer<Render::FXOverride>::Set(&v6->mFightClassFXOverride, (Render::FXOverride *)v30);
        v29 = UFG::WorldEffectsManager::sBrawlerEffectID;
        if ( v87 )
          v29 = UFG::WorldEffectsManager::sBrawlerTargetEffectID;
      }
      else
      {
        if ( v25 != 2 )
        {
LABEL_64:
          v6->mFightClassUIType = v25;
          goto LABEL_65;
        }
        v28 = Render::FXOverride::CreateOverride("mFightClassFXOverride", 0i64);
        FX::SharedPointer<Render::FXOverride>::Set(&v6->mFightClassFXOverride, (Render::FXOverride *)v28);
        v29 = UFG::WorldEffectsManager::sGrapplerEffectID;
        if ( v87 )
          v29 = UFG::WorldEffectsManager::sGrapplerTargetEffectID;
      }
      v6->mFightClassUIID = Render::FXManager::CreateEffect(
                              &Render::gFXManager,
                              v29,
                              v6->mTransformNode,
                              0xFFFFFFFF,
                              v6->mFightClassFXOverride.m_pPointer);
      goto LABEL_64;
    }
LABEL_65:
    v4 = v80;
    v3 = v88;
    m_pPointer = v81;
    v5 = this;
LABEL_66:
    if ( v8
      && ((v31 = v8->m_Flags, (v31 & 0x4000) != 0) || v31 < 0
        ? (v32 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8))
        : (v31 & 0x2000) == 0
        ? ((v31 & 0x1000) == 0
         ? (v32 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                        v8,
                                                        UFG::CharacterAnimationComponent::_TypeUID))
         : (v32 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v8,
                                                        UFG::CharacterAnimationComponent::_TypeUID)))
        : (v32 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8)),
          v32) )
    {
      mCreature = v32->mCreature;
    }
    else
    {
      mCreature = 0i64;
    }
    if ( mCreature )
    {
      Creature::GetTranslation(mCreature, &result, 1);
      result.z = result.z - UFG::WorldEffectsManager::sRaycastLength;
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
      v35 = COERCE_FLOAT(LODWORD(mCurrentCamera->mCamera.mView.v1.x) ^ _xmm[0]) * v2;
      v36 = COERCE_FLOAT(LODWORD(mCurrentCamera->mCamera.mView.v1.y) ^ _xmm[0]) * v2;
      v37 = COERCE_FLOAT(LODWORD(mCurrentCamera->mCamera.mView.v1.z) ^ _xmm[0]) * v2;
      v38 = UFG::Director::Get()->mCurrentCamera;
      if ( v38 )
        v38 = (UFG::BaseCameraComponent *)((char *)v38 + 80);
      x_low = LODWORD(v38->mCamera.mView.v2.x);
      y_low = (__m128)LODWORD(v38->mCamera.mView.v2.y);
      x = result.x;
      y = result.y;
      z = result.z;
      *(float *)&x_low = (float)(*(float *)&x_low - v35) - result.x;
      y_low.m128_f32[0] = (float)(y_low.m128_f32[0] - v36) - result.y;
      v44 = y_low;
      v44.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                              + (float)(*(float *)&x_low * *(float *)&x_low))
                      + (float)((float)((float)(v38->mCamera.mView.v2.z - v37) - result.z)
                              * (float)((float)(v38->mCamera.mView.v2.z - v37) - result.z));
      if ( v44.m128_f32[0] == 0.0 )
        v45 = 0.0;
      else
        v45 = 1.0 / _mm_sqrt_ps(v44).m128_f32[0];
      v46 = *(float *)&x_low * v45;
      y_low.m128_f32[0] = y_low.m128_f32[0] * v45;
      v47 = UFG::WorldEffectsManager::sNormalLerpRateScale * dt;
      if ( (float)(UFG::WorldEffectsManager::sNormalLerpRateScale * dt) <= 0.0 )
      {
        v47 = 0.0;
      }
      else if ( v47 >= 1.0 )
      {
        v47 = *(float *)&FLOAT_1_0;
      }
      v49 = (__m128)LODWORD(v6->mPreviousNormal.y);
      v51 = y_low;
      v48 = (float)((float)(v6->mPreviousNormal.x - v6->mCurrentNormal.x) * v47) + v6->mCurrentNormal.x;
      v49.m128_f32[0] = (float)((float)(v49.m128_f32[0] - v6->mCurrentNormal.y) * v47) + v6->mCurrentNormal.y;
      v50 = (float)((float)(v6->mPreviousNormal.z - v6->mCurrentNormal.z) * v47) + v6->mCurrentNormal.z;
      v6->mCurrentNormal.x = v48;
      v51.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v46 * v46);
      LODWORD(v6->mCurrentNormal.y) = v49.m128_i32[0];
      v6->mCurrentNormal.z = v50;
      if ( v51.m128_f32[0] == 0.0 )
        v52 = 0.0;
      else
        v52 = 1.0 / _mm_sqrt_ps(v51).m128_f32[0];
      v53 = v48;
      *(float *)&x_low = v46 * v52;
      v54 = y_low.m128_f32[0] * v52;
      v55 = v49;
      m.v0.w = 0.0;
      LODWORD(m.v0.x) = x_low;
      m.v0.y = v54;
      v55.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v53 * v53)) + (float)(v50 * v50);
      v56 = v52 * 0.0;
      m.v0.z = v56;
      if ( v55.m128_f32[0] == 0.0 )
        v57 = 0.0;
      else
        v57 = 1.0 / _mm_sqrt_ps(v55).m128_f32[0];
      v58 = v49.m128_f32[0] * v57;
      v59 = v50 * v57;
      v60 = v57;
      v63 = (__m128)x_low;
      v61 = v60 * v53;
      v62 = (float)(v56 * v58) - (float)(v54 * v59);
      v63.m128_f32[0] = (float)(*(float *)&x_low * v59) - (float)(v56 * v61);
      v64 = *(float *)&x_low * v58;
      v66 = v63;
      v65 = (float)(v54 * v61) - v64;
      v66.m128_f32[0] = (float)((float)(v63.m128_f32[0] * v63.m128_f32[0]) + (float)(v62 * v62)) + (float)(v65 * v65);
      if ( v66.m128_f32[0] == 0.0 )
        v67 = 0.0;
      else
        v67 = 1.0 / _mm_sqrt_ps(v66).m128_f32[0];
      m.v1.w = 0.0;
      m.v1.y = v63.m128_f32[0] * v67;
      m.v1.z = v65 * v67;
      m.v1.x = v62 * v67;
      v68 = (float)((float)(v65 * v67) * v54) - (float)((float)(v63.m128_f32[0] * v67) * v56);
      v69 = (float)((float)(v62 * v67) * v56) - (float)((float)(v65 * v67) * *(float *)&x_low);
      v70 = (float)((float)(v63.m128_f32[0] * v67) * *(float *)&x_low) - (float)((float)(v62 * v67) * v54);
      v71 = (float)((float)(v69 * v69) + (float)(v68 * v68)) + (float)(v70 * v70);
      if ( v71 == 0.0 )
        v72 = 0.0;
      else
        v72 = 1.0 / fsqrt(v71);
      mTransformNode = v6->mTransformNode;
      m.v3.x = x;
      m.v3.y = y;
      m.v2.w = 0.0;
      m.v3.w = 1.0;
      m.v3.z = z;
      m.v2.x = v68 * v72;
      m.v2.y = v69 * v72;
      m.v2.z = v70 * v72;
      UFG::TransformNodeComponent::SetWorldTransform(mTransformNode, &m);
      v83[1] = LODWORD(result.y);
      v82[1] = LODWORD(result.y);
      v83[0] = LODWORD(result.x);
      v82[0] = LODWORD(result.x);
      *(float *)&v82[2] = result.z - UFG::WorldEffectsManager::sRaycastLength;
      *(float *)&v83[2] = UFG::WorldEffectsManager::sRaycastLength + result.z;
      UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay(
        UFG::BasePhysicsSystem::mInstance,
        (UFG::qVector3 *)v83,
        (UFG::qVector3 *)v82,
        15u,
        (void (__fastcall *)(UFG::RayCastData *, UFG::SimComponent *, void *))UFG::WorldEffectsManager::AsyncRayCallback,
        (UFG::SimComponent *)m_pPointer,
        v6);
      v74 = (__m128)LODWORD(v5->mPlayerPos.y);
      v74.m128_f32[0] = (float)((float)((float)(v74.m128_f32[0] - result.y) * (float)(v74.m128_f32[0] - result.y))
                              + (float)((float)(v5->mPlayerPos.x - result.x) * (float)(v5->mPlayerPos.x - result.x)))
                      + (float)((float)(v5->mPlayerPos.z - result.z) * (float)(v5->mPlayerPos.z - result.z));
      v75 = (float)(1.0 - (float)(_mm_sqrt_ps(v74).m128_f32[0] / UFG::WorldEffectsManager::sAlphaUIRadius)) + 0.75;
      if ( v75 <= 0.0 )
      {
        v75 = 0.0;
      }
      else if ( v75 >= 1.0 )
      {
        v75 = *(float *)&FLOAT_1_0;
      }
      if ( UFG::WorldEffectsManager::sOverrideUIAlpha )
        v75 = UFG::WorldEffectsManager::sOverrideUIAlphaValue;
      v76 = v6->mHealthFXOverride.m_pPointer;
      v77 = v75 * v5->mGlobalAlpha;
      if ( v76 )
        v76->stateBlock.ColorTint[3] = v77;
      v78 = v6->mFightClassFXOverride.m_pPointer;
      v2 = FLOAT_15_0;
      if ( v78 )
        v78->stateBlock.ColorTint[3] = v77;
    }
LABEL_114:
    ++v3;
    ++v4;
    v88 = v3;
    v80 = v4;
  }
  while ( v3 < 0xF );
}

// File Line: 599
// RVA: 0x4017C0
void __fastcall UFG::WorldEffectsManager::StartWorldEffect(
        UFG::WorldEffectsManager *this,
        UFG::WorldEffectsManager::WorldEffectType type,
        UFG::qVector3 *startPos,
        UFG::qVector3 *endPos,
        UFG::qMatrix44 *transform,
        float duration)
{
  __int64 v6; // r10
  UFG::WorldEffectsManager::WorldEffectElement *mWorldEffectElements; // rbx
  unsigned int v8; // eax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mParentTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float x; // eax
  float z; // xmm1_4
  float y; // xmm0_4
  float v17; // xmm1_4
  UFG::qVector4 v18; // xmm3
  UFG::qVector4 v19; // xmm2
  UFG::qVector4 v20; // xmm1
  unsigned int Effect; // eax

  v6 = type;
  mWorldEffectElements = this->mWorldEffectElements;
  v8 = 0;
  while ( mWorldEffectElements->mActive )
  {
    ++v8;
    ++mWorldEffectElements;
    if ( v8 >= 5 )
      return;
  }
  p_mParentTransform = &mWorldEffectElements->mParentTransform;
  if ( mWorldEffectElements->mParentTransform.m_pPointer )
  {
    mPrev = p_mParentTransform->mPrev;
    mNext = mWorldEffectElements->mParentTransform.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mParentTransform->mPrev = p_mParentTransform;
    mWorldEffectElements->mParentTransform.mNext = &mWorldEffectElements->mParentTransform;
  }
  v12 = duration;
  mWorldEffectElements->mParentTransform.m_pPointer = 0i64;
  mWorldEffectElements->mEffectType = v6;
  if ( duration <= 0.0 )
    v13 = FLOAT_3_4028235e38;
  else
    v13 = duration;
  mWorldEffectElements->mDuration = v13;
  if ( duration <= 0.0 )
    v12 = FLOAT_3_4028235e38;
  mWorldEffectElements->mTime = v12;
  x = startPos->x;
  z = startPos->z;
  mWorldEffectElements->mStart.y = startPos->y;
  mWorldEffectElements->mStart.x = x;
  mWorldEffectElements->mStart.z = z;
  y = endPos->y;
  v17 = endPos->z;
  mWorldEffectElements->mEnd.x = endPos->x;
  mWorldEffectElements->mEnd.y = y;
  mWorldEffectElements->mEnd.z = v17;
  v18 = transform->v1;
  v19 = transform->v2;
  v20 = transform->v3;
  mWorldEffectElements->mTransform.v0 = transform->v0;
  mWorldEffectElements->mTransform.v1 = v18;
  mWorldEffectElements->mTransform.v2 = v19;
  mWorldEffectElements->mTransform.v3 = v20;
  Effect = Render::FXManager::CreateEffect(
             &Render::gFXManager,
             UFG::WorldEffectsManager::sWorldEffectIds[v6],
             mWorldEffectElements->mTransformNode,
             0xFFFFFFFF,
             0i64);
  mWorldEffectElements->mEffectID = Effect;
  mWorldEffectElements->mActive = Effect != -1;
}

// File Line: 619
// RVA: 0x4018E0
signed __int64 __fastcall UFG::WorldEffectsManager::StartWorldEffect(
        UFG::WorldEffectsManager *this,
        unsigned int effectID,
        UFG::qVector3 *startPos,
        UFG::qVector3 *endPos,
        UFG::qMatrix44 *transform,
        float duration)
{
  UFG::WorldEffectsManager::WorldEffectElement *mWorldEffectElements; // rbx
  unsigned int v8; // eax
  signed __int64 result; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mParentTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float x; // eax
  float z; // xmm1_4
  float y; // xmm0_4
  float v18; // xmm1_4
  UFG::qVector4 v19; // xmm3
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1

  mWorldEffectElements = this->mWorldEffectElements;
  v8 = 0;
  while ( mWorldEffectElements->mActive )
  {
    ++v8;
    ++mWorldEffectElements;
    if ( v8 >= 5 )
      return 0xFFFFFFFFi64;
  }
  p_mParentTransform = &mWorldEffectElements->mParentTransform;
  if ( mWorldEffectElements->mParentTransform.m_pPointer )
  {
    mPrev = p_mParentTransform->mPrev;
    mNext = mWorldEffectElements->mParentTransform.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mParentTransform->mPrev = p_mParentTransform;
    mWorldEffectElements->mParentTransform.mNext = &mWorldEffectElements->mParentTransform;
  }
  v13 = duration;
  mWorldEffectElements->mParentTransform.m_pPointer = 0i64;
  mWorldEffectElements->mEffectType = WorldEffectType_Num;
  if ( duration <= 0.0 )
    v14 = FLOAT_3_4028235e38;
  else
    v14 = duration;
  mWorldEffectElements->mDuration = v14;
  if ( duration <= 0.0 )
    v13 = FLOAT_3_4028235e38;
  mWorldEffectElements->mTime = v13;
  x = startPos->x;
  z = startPos->z;
  mWorldEffectElements->mStart.y = startPos->y;
  mWorldEffectElements->mStart.x = x;
  mWorldEffectElements->mStart.z = z;
  y = endPos->y;
  v18 = endPos->z;
  mWorldEffectElements->mEnd.x = endPos->x;
  mWorldEffectElements->mEnd.y = y;
  mWorldEffectElements->mEnd.z = v18;
  v19 = transform->v1;
  v20 = transform->v2;
  v21 = transform->v3;
  mWorldEffectElements->mTransform.v0 = transform->v0;
  mWorldEffectElements->mTransform.v1 = v19;
  mWorldEffectElements->mTransform.v2 = v20;
  mWorldEffectElements->mTransform.v3 = v21;
  result = Render::FXManager::CreateEffect(
             &Render::gFXManager,
             effectID,
             mWorldEffectElements->mTransformNode,
             0xFFFFFFFF,
             0i64);
  mWorldEffectElements->mEffectID = result;
  mWorldEffectElements->mActive = (_DWORD)result != -1;
  return result;
}

// File Line: 640
// RVA: 0x401A00
__int64 __fastcall UFG::WorldEffectsManager::StartWorldEffect(
        UFG::WorldEffectsManager *this,
        unsigned int effectID,
        UFG::SimObject *attachTo,
        UFG::qMatrix44 *transform,
        float duration)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  int v8; // eax
  UFG::WorldEffectsManager::WorldEffectElement *i; // rbx
  __int64 result; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mParentTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  float v14; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  float v16; // xmm1_4
  float y; // xmm1_4
  float z; // xmm0_4
  float x; // eax
  float v20; // xmm1_4
  UFG::qVector4 v21; // xmm3
  UFG::qVector4 v22; // xmm2
  UFG::qVector4 v23; // xmm1

  m_pTransformNodeComponent = attachTo->m_pTransformNodeComponent;
  v8 = 0;
  for ( i = this->mWorldEffectElements; i->mActive; ++i )
  {
    if ( (unsigned int)++v8 >= 5 )
      return 0xFFFFFFFFi64;
  }
  if ( !m_pTransformNodeComponent )
    return 0xFFFFFFFFi64;
  p_mParentTransform = &i->mParentTransform;
  if ( i->mParentTransform.m_pPointer )
  {
    mPrev = p_mParentTransform->mPrev;
    mNext = i->mParentTransform.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mParentTransform->mPrev = p_mParentTransform;
    i->mParentTransform.mNext = &i->mParentTransform;
  }
  v14 = duration;
  i->mParentTransform.m_pPointer = m_pTransformNodeComponent;
  v15 = m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
  v15->mNext = p_mParentTransform;
  p_mParentTransform->mPrev = v15;
  i->mParentTransform.mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
  m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mParentTransform;
  i->mEffectType = WorldEffectType_Num;
  if ( duration <= 0.0 )
    v16 = FLOAT_3_4028235e38;
  else
    v16 = duration;
  i->mDuration = v16;
  if ( duration <= 0.0 )
    v14 = FLOAT_3_4028235e38;
  i->mTime = v14;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  i->mStart.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  i->mStart.y = y;
  i->mStart.z = z;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  v20 = m_pTransformNodeComponent->mWorldTransform.v3.z;
  i->mEnd.y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  i->mEnd.z = v20;
  i->mEnd.x = x;
  v21 = transform->v1;
  v22 = transform->v2;
  v23 = transform->v3;
  i->mTransform.v0 = transform->v0;
  i->mTransform.v1 = v21;
  i->mTransform.v2 = v22;
  i->mTransform.v3 = v23;
  LODWORD(result) = Render::FXManager::CreateEffect(&Render::gFXManager, effectID, i->mTransformNode, 0xFFFFFFFF, 0i64);
  i->mEffectID = result;
  i->mActive = (_DWORD)result != -1;
  return (unsigned int)result;
}

// File Line: 681
// RVA: 0x4007B0
void __fastcall UFG::WorldEffectsManager::EndWorldEffect(UFG::WorldEffectsManager *this, unsigned int effectID)
{
  unsigned int *p_mEffectID; // rbx
  __int64 v4; // rdi

  p_mEffectID = &this->mWorldEffectElements[0].mEffectID;
  v4 = 5i64;
  do
  {
    if ( *((_BYTE *)p_mEffectID - 36) )
    {
      if ( *p_mEffectID == effectID )
      {
        Render::FXManager::KillEffect(&Render::gFXManager, *p_mEffectID, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
        *((_BYTE *)p_mEffectID - 36) = 0;
        *p_mEffectID = -1;
      }
    }
    p_mEffectID += 36;
    --v4;
  }
  while ( v4 );
}

// File Line: 697
// RVA: 0x402F30
void __fastcall UFG::WorldEffectsManager::UpdateWorldEffects(UFG::WorldEffectsManager *this, float dt)
{
  float *p_y; // rdi
  __int64 v3; // rsi
  unsigned int v4; // edx
  float v5; // xmm0_4
  float *v6; // rbx
  float x; // xmm5_4
  float y; // xmm7_4
  float z; // xmm8_4
  float v10; // xmm15_4
  float v11; // xmm14_4
  float v12; // xmm12_4
  UFG::TransformNodeComponent *v13; // rbx
  float v14; // xmm9_4
  float v15; // xmm15_4
  float v16; // xmm1_4
  float v17; // xmm11_4
  float v18; // xmm12_4
  float v19; // xmm9_4
  __m128 v20; // xmm13
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  float v23; // xmm2_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm5_4
  float v27; // xmm7_4
  float v28; // xmm3_4
  __m128 x_low; // xmm2
  float v30; // xmm8_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm8_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm9_4
  float v37; // xmm4_4
  float v38; // xmm8_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm11_4
  float v43; // xmm4_4
  float v44; // xmm3_4
  float v45; // xmm1_4
  UFG::qMatrix44 *v46; // rax
  UFG::TransformNodeComponent *v47; // rcx
  UFG::qVector4 v48; // xmm2
  UFG::qVector4 v49; // xmm1
  UFG::qVector4 v50; // xmm0
  __int64 v51; // rcx
  _QWORD *v52; // rax
  UFG::qMatrix44 m; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qMatrix44 result; // [rsp+60h] [rbp-88h] BYREF
  float vars0; // [rsp+150h] [rbp+68h]

  p_y = &this->mWorldEffectElements[0].mStart.y;
  v3 = 5i64;
  do
  {
    if ( *((_BYTE *)p_y - 16) )
    {
      v4 = *((_DWORD *)p_y + 5);
      *(p_y - 3) = *(p_y - 3) - dt;
      if ( Render::FXManager::FindEffect(&Render::gFXManager, v4) && (v5 = *(p_y - 3), v5 >= 0.0) )
      {
        v6 = (float *)*((_QWORD *)p_y + 15);
        x = *(float *)&FLOAT_1_0;
        y = 0.0;
        z = 0.0;
        if ( v6 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(*((UFG::TransformNodeComponent **)p_y + 15));
          v10 = v6[44];
          v11 = v6[45];
          v12 = UFG::WorldEffectsManager::sHeightFudgeFactor + v6[46];
          v13 = (UFG::TransformNodeComponent *)*((_QWORD *)p_y + 15);
          UFG::TransformNodeComponent::UpdateWorldTransform(v13);
          x = v13->mWorldTransform.v0.x;
          y = v13->mWorldTransform.v0.y;
          z = v13->mWorldTransform.v0.z;
        }
        else
        {
          v20 = (__m128)*(unsigned int *)p_y;
          v14 = p_y[1];
          v15 = *(p_y - 1);
          v16 = 1.0 - (float)(v5 / *(p_y - 2));
          v17 = v15 - p_y[2];
          v10 = v15 + (float)((float)(p_y[2] - v15) * v16);
          v18 = (float)((float)(p_y[4] - v14) * v16) + v14;
          v19 = v14 - p_y[4];
          v12 = v18 + UFG::WorldEffectsManager::sHeightFudgeFactor;
          v11 = (float)((float)(p_y[3] - v20.m128_f32[0]) * v16) + v20.m128_f32[0];
          v20.m128_f32[0] = v20.m128_f32[0] - p_y[3];
          v21 = v20;
          v21.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v17 * v17))
                          + (float)(v19 * v19);
          if ( _mm_sqrt_ps(v21).m128_f32[0] > 0.02 )
          {
            v22 = v20;
            v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v17 * v17))
                            + (float)(v19 * v19);
            if ( v22.m128_f32[0] == 0.0 )
              v23 = 0.0;
            else
              v23 = 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
            x = v17 * v23;
            y = v20.m128_f32[0] * v23;
            z = 0.0;
          }
        }
        v24 = (float)((float)(y * y) + (float)(x * x)) + (float)(z * z);
        if ( v24 == 0.0 )
          v25 = 0.0;
        else
          v25 = 1.0 / fsqrt(v24);
        v26 = x * v25;
        v27 = y * v25;
        v28 = v25 * z;
        m.v0.w = 0.0;
        x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        m.v0.x = v26;
        m.v0.y = v27;
        m.v0.z = v28;
        x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                  + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                          + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
        if ( x_low.m128_f32[0] == 0.0 )
          v30 = 0.0;
        else
          v30 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
        v31 = v30;
        v32 = v30;
        v33 = v30 * UFG::qVector3::msDirUp.z;
        v34 = v32 * UFG::qVector3::msDirUp.x;
        v35 = v31 * UFG::qVector3::msDirUp.y;
        v36 = (float)(v28 * v35) - (float)(v27 * v33);
        v37 = (float)(v26 * v33) - (float)(v28 * v34);
        v38 = (float)(v27 * v34) - (float)(v26 * v35);
        v39 = (float)((float)(v37 * v37) + (float)(v36 * v36)) + (float)(v38 * v38);
        if ( v39 == 0.0 )
          v40 = 0.0;
        else
          v40 = 1.0 / fsqrt(v39);
        m.v1.w = 0.0;
        m.v1.y = v37 * v40;
        m.v1.z = v38 * v40;
        m.v1.x = v36 * v40;
        v41 = (float)((float)(v38 * v40) * v27) - (float)((float)(v37 * v40) * v28);
        v42 = (float)((float)(v36 * v40) * v28) - (float)((float)(v38 * v40) * v26);
        v43 = (float)((float)(v37 * v40) * v26) - (float)((float)(v36 * v40) * v27);
        v44 = (float)((float)(v42 * v42) + (float)(v41 * v41)) + (float)(v43 * v43);
        if ( v44 == 0.0 )
          v45 = 0.0;
        else
          v45 = 1.0 / fsqrt(v44);
        m.v3.x = v10;
        m.v3.y = v11;
        m.v3.z = v12;
        m.v2.w = 0.0;
        m.v3.w = 1.0;
        m.v2.x = v41 * v45;
        m.v2.y = v42 * v45;
        m.v2.z = v43 * v45;
        v46 = UFG::qMatrix44::operator*(&m, &result, (UFG::qMatrix44 *)(p_y + 6));
        v47 = (UFG::TransformNodeComponent *)*((_QWORD *)p_y + 12);
        v48 = v46->v2;
        v49 = v46->v3;
        v50 = v46->v0;
        m.v1 = v46->v1;
        m.v2 = v48;
        m.v0 = v50;
        m.v3 = v49;
        UFG::TransformNodeComponent::SetWorldTransform(v47, &m);
      }
      else
      {
        Render::FXManager::KillEffect(&Render::gFXManager, *((_DWORD *)p_y + 5), FXKILLOPTION_ERASE_EMITTED_OBJECTS);
        *((_BYTE *)p_y - 16) = 0;
        p_y[5] = NAN;
        if ( *((_QWORD *)p_y + 15) )
        {
          v51 = *((_QWORD *)p_y + 13);
          v52 = (_QWORD *)*((_QWORD *)p_y + 14);
          *(_QWORD *)(v51 + 8) = v52;
          *v52 = v51;
          *((_QWORD *)p_y + 13) = p_y + 26;
          *((_QWORD *)p_y + 14) = p_y + 26;
        }
        *((_QWORD *)p_y + 15) = 0i64;
      }
      dt = vars0;
    }
    p_y += 36;
    --v3;
  }
  while ( v3 );
}

// File Line: 759
// RVA: 0x3FED30
void __fastcall UFG::WorldEffectsManager::AsyncRayCallback(
        UFG::RayCastData *raycastData,
        UFG::SimComponent *simComponent,
        _DWORD *callbackUserData)
{
  int v4; // xmm0_4
  int v5; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm12_4
  float x; // xmm13_4
  float v10; // xmm14_4
  UFG::Camera *p_mCamera; // rdi
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  _DWORD *p_mFOVOffset; // rax
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  UFG::BaseCameraComponent *v17; // rcx
  __int128 x_low; // xmm4
  __m128 y_low; // xmm5
  __m128 v20; // xmm6
  float v21; // xmm1_4
  float v22; // xmm4_4
  __m128 v23; // xmm1
  __int128 v24; // xmm6
  float v25; // xmm9_4
  __m128 v26; // xmm8
  float v27; // xmm11_4
  float v28; // xmm5_4
  __m128 v29; // xmm7
  float v30; // xmm1_4
  float v31; // xmm8_4
  float v32; // xmm11_4
  float v33; // xmm9_4
  __int128 v34; // xmm10
  float v35; // xmm11_4
  __m128 v36; // xmm7
  float v37; // xmm11_4
  __m128 v38; // xmm8
  float v39; // xmm1_4
  float v40; // xmm0_4
  __m128 v41; // xmm9
  float v42; // xmm7_4
  float v43; // xmm8_4
  __m128 v44; // xmm4
  float v45; // xmm2_4
  UFG::TransformNodeComponent *v46; // rcx
  int v47; // xmm1_4
  int v48; // xmm0_4
  float v49; // xmm2_4
  float v50; // xmm0_4
  UFG::qMatrix44 m; // [rsp+20h] [rbp-D8h] BYREF

  if ( simComponent )
  {
    if ( raycastData->hit
      && (float)((float)((float)(UFG::qVector3::msDirUp.x * raycastData->normal.x)
                       + (float)(UFG::qVector3::msDirUp.y * raycastData->normal.y))
               + (float)(UFG::qVector3::msDirUp.z * raycastData->normal.z)) > 0.866 )
    {
      v4 = callbackUserData[13];
      v5 = callbackUserData[11];
      callbackUserData[15] = callbackUserData[12];
      callbackUserData[16] = v4;
      callbackUserData[14] = v5;
      y = raycastData->normal.y;
      z = raycastData->normal.z;
      callbackUserData[11] = LODWORD(raycastData->normal.x);
      *((float *)callbackUserData + 12) = y;
      *((float *)callbackUserData + 13) = z;
      v8 = UFG::WorldEffectsManager::sHeightFudgeFactor + raycastData->point.z;
      x = raycastData->point.x;
      v10 = raycastData->point.y;
      p_mCamera = 0i64;
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        p_mFOVOffset = (_DWORD *)&mCurrentCamera->mCamera.mFOVOffset;
      else
        p_mFOVOffset = 0i64;
      v14 = COERCE_FLOAT(p_mFOVOffset[40] ^ _xmm[0]) * 15.0;
      v15 = COERCE_FLOAT(p_mFOVOffset[41] ^ _xmm[0]) * 15.0;
      v16 = COERCE_FLOAT(p_mFOVOffset[42] ^ _xmm[0]) * 15.0;
      v17 = UFG::Director::Get()->mCurrentCamera;
      if ( v17 )
        p_mCamera = &v17->mCamera;
      x_low = LODWORD(p_mCamera->mTransformation.v3.x);
      y_low = (__m128)LODWORD(p_mCamera->mTransformation.v3.y);
      *(float *)&x_low = (float)(*(float *)&x_low - v14) - x;
      y_low.m128_f32[0] = (float)(y_low.m128_f32[0] - v15) - v10;
      v20 = y_low;
      v20.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                              + (float)(*(float *)&x_low * *(float *)&x_low))
                      + (float)((float)((float)(p_mCamera->mTransformation.v3.z - v16) - v8)
                              * (float)((float)(p_mCamera->mTransformation.v3.z - v16) - v8));
      if ( v20.m128_f32[0] == 0.0 )
        v21 = 0.0;
      else
        v21 = 1.0 / _mm_sqrt_ps(v20).m128_f32[0];
      v22 = *(float *)&x_low * v21;
      y_low.m128_f32[0] = y_low.m128_f32[0] * v21;
      v23 = y_low;
      v23.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v22 * v22);
      if ( v23.m128_f32[0] == 0.0 )
      {
        v24 = 0i64;
      }
      else
      {
        v24 = (unsigned int)FLOAT_1_0;
        *(float *)&v24 = 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
      }
      v25 = *((float *)callbackUserData + 12);
      v26 = (__m128)(unsigned int)callbackUserData[11];
      v27 = *((float *)callbackUserData + 13);
      *(float *)&x_low = v22 * *(float *)&v24;
      v28 = y_low.m128_f32[0] * *(float *)&v24;
      *(float *)&v24 = *(float *)&v24 * 0.0;
      m.v0.w = 0.0;
      v29 = v26;
      LODWORD(m.v0.x) = x_low;
      m.v0.y = v28;
      LODWORD(m.v0.z) = v24;
      v29.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v27 * v27);
      if ( v29.m128_f32[0] == 0.0 )
        v30 = 0.0;
      else
        v30 = 1.0 / _mm_sqrt_ps(v29).m128_f32[0];
      v31 = v26.m128_f32[0] * v30;
      v32 = v27 * v30;
      v33 = v25 * v30;
      v34 = v24;
      v36 = (__m128)x_low;
      v36.m128_f32[0] = *(float *)&x_low * v32;
      *(float *)&v34 = (float)(*(float *)&v24 * v33) - (float)(v28 * v32);
      v35 = v28 * v31;
      v36.m128_f32[0] = v36.m128_f32[0] - (float)(*(float *)&v24 * v31);
      v38 = v36;
      v37 = v35 - (float)(*(float *)&x_low * v33);
      v38.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(*(float *)&v34 * *(float *)&v34))
                      + (float)(v37 * v37);
      if ( v38.m128_f32[0] == 0.0 )
        v39 = 0.0;
      else
        v39 = 1.0 / _mm_sqrt_ps(v38).m128_f32[0];
      *(float *)&v34 = *(float *)&v34 * v39;
      m.v1.w = 0.0;
      v41 = (__m128)v34;
      m.v1.z = v37 * v39;
      LODWORD(m.v1.x) = v34;
      m.v1.y = v36.m128_f32[0] * v39;
      v40 = (float)(v36.m128_f32[0] * v39) * *(float *)&v24;
      v41.m128_f32[0] = (float)(*(float *)&v34 * *(float *)&v24) - (float)((float)(v37 * v39) * *(float *)&x_low);
      v42 = (float)((float)(v36.m128_f32[0] * v39) * *(float *)&x_low) - (float)(*(float *)&v34 * v28);
      v44 = v41;
      v43 = (float)((float)(v37 * v39) * v28) - v40;
      v44.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v43 * v43)) + (float)(v42 * v42);
      if ( v44.m128_f32[0] == 0.0 )
        v45 = 0.0;
      else
        v45 = 1.0 / _mm_sqrt_ps(v44).m128_f32[0];
      v46 = (UFG::TransformNodeComponent *)*((_QWORD *)callbackUserData + 12);
      m.v3.x = x;
      m.v3.y = v10;
      m.v2.w = 0.0;
      m.v3.w = 1.0;
      m.v3.z = v8;
      m.v2.x = v43 * v45;
      m.v2.y = v41.m128_f32[0] * v45;
      m.v2.z = v42 * v45;
      UFG::TransformNodeComponent::SetWorldTransform(v46, &m);
    }
    else
    {
      v47 = callbackUserData[12];
      v48 = callbackUserData[13];
      callbackUserData[14] = callbackUserData[11];
      callbackUserData[15] = v47;
      callbackUserData[16] = v48;
      v49 = UFG::qVector3::msDirUp.z;
      v50 = UFG::qVector3::msDirUp.x;
      callbackUserData[12] = LODWORD(UFG::qVector3::msDirUp.y);
      *((float *)callbackUserData + 11) = v50;
      *((float *)callbackUserData + 13) = v49;
    }
  }
}

