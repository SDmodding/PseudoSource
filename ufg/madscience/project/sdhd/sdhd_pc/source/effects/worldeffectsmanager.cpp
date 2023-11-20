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
  UFG::WorldEffectsManager *v1; // r15
  signed __int64 v2; // rbp
  UFG::WorldEffectsManager::WorldEffectElement *v3; // rsi
  signed __int64 v4; // r14
  UFG::TransformNodeComponent **v5; // rbx
  UFG::WorldEffectsManager::UIElement *v6; // rdi
  UFG::qMemoryPool *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::TransformNodeComponent *v9; // rax
  UFG::TransformNodeComponent **v10; // rbx
  UFG::qMemoryPool *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::TransformNodeComponent *v13; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v14; // [rsp+78h] [rbp+10h]

  v1 = this;
  v2 = 15i64;
  `eh vector constructor iterator(
    this,
    0x68ui64,
    15,
    (void (__fastcall *)(void *))UFG::WorldEffectsManager::UIElement::UIElement);
  v3 = v1->mWorldEffectElements;
  v4 = 5i64;
  `eh vector constructor iterator(
    v1->mWorldEffectElements,
    0x90ui64,
    5,
    (void (__fastcall *)(void *))UFG::WorldEffectsManager::WorldEffectElement::WorldEffectElement);
  *(_WORD *)&v1->mShowHealthUIs = 0;
  v1->mTriggeredBuffEffect = 0;
  v1->mPlayerFaction = 0;
  v14 = &v1->mFocusTarget;
  v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v1->mFocusTarget.m_pPointer = 0i64;
  v1->mHealthMeterActive = 0;
  *(_QWORD *)&v1->mCheckForHostileTimer = 0i64;
  v1->mGlobalAlpha = 0.0;
  v5 = &v1->mUIElements[0].mTransformNode;
  v6 = (UFG::WorldEffectsManager::UIElement *)v1;
  do
  {
    UFG::WorldEffectsManager::UIElement::Reset(v6);
    v7 = UFG::GetSimulationMemoryPool();
    v8 = UFG::qMemoryPool::Allocate(v7, 0x110ui64, "WorldEffectsManager::TransformNodeComponent", 0i64, 1u);
    if ( v8 )
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v8, 0xDEADBEEF, 0i64, 0);
    else
      v9 = 0i64;
    *v5 = v9;
    ++v6;
    v5 += 13;
    --v2;
  }
  while ( v2 );
  v10 = &v1->mWorldEffectElements[0].mTransformNode;
  do
  {
    UFG::qMemSet(v3, 0, 0x90u);
    v11 = UFG::GetSimulationMemoryPool();
    v12 = UFG::qMemoryPool::Allocate(v11, 0x110ui64, "WorldEffectsManager::TransformNodeComponent", 0i64, 1u);
    if ( v12 )
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v12, 0xDEADBEEF, 0i64, 0);
    else
      v13 = 0i64;
    *v10 = v13;
    ++v3;
    v10 += 18;
    --v4;
  }
  while ( v4 );
}

// File Line: 181
// RVA: 0x400D00
char __fastcall UFG::WorldEffectsManager::IsWorldEffectActive(UFG::WorldEffectsManager *this, UFG::WorldEffectsManager::WorldEffectType type)
{
  unsigned int v2; // er8
  UFG::WorldEffectsManager::WorldEffectElement *v3; // rax

  v2 = 0;
  v3 = this->mWorldEffectElements;
  while ( !v3->mActive || v3->mEffectType != type )
  {
    ++v2;
    ++v3;
    if ( v2 >= 5 )
      return 0;
  }
  return 1;
}

// File Line: 204
// RVA: 0x3FEC60
signed __int64 __fastcall UFG::WorldEffectsManager::AllocUIElement(UFG::WorldEffectsManager *this)
{
  signed __int64 result; // rax
  float v2; // xmm1_4
  float v3; // xmm2_4
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
  this->mUIElements[0].mCurrentHealthUI = 4;
  this->mUIElements[0].mFightClassUIID = -1;
  v2 = UFG::qVector3::msDirUp.y;
  v3 = UFG::qVector3::msDirUp.z;
  this->mUIElements[0].mCurrentNormal.x = UFG::qVector3::msDirUp.x;
  this->mUIElements[0].mCurrentNormal.y = v2;
  this->mUIElements[0].mCurrentNormal.z = v3;
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
  Render::FXOverride *v3; // rax
  Render::FXOverride *v4; // rdi
  unsigned int v5; // edx
  Render::FXOverride *v6; // rax
  Render::FXOverride *v7; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterEffectsComponent> *v8; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  if ( index != -1 )
  {
    v2 = &this->mUIElements[index];
    Render::FXManager::KillEffect(&Render::gFXManager, v2->mHealthUIID, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
    v3 = v2->mHealthFXOverride.m_pPointer;
    if ( v3 )
    {
      --v3->mReferenceCount;
      v4 = v2->mHealthFXOverride.m_pPointer;
      if ( v4->mReferenceCount <= 0 )
      {
        if ( v4 )
        {
          Render::FXOverride::~FXOverride(v2->mHealthFXOverride.m_pPointer);
          operator delete[](v4);
        }
        v2->mHealthFXOverride.m_pPointer = 0i64;
      }
      v2->mHealthFXOverride.m_pPointer = 0i64;
    }
    v5 = v2->mFightClassUIID;
    v2->mHealthUIType = 0;
    v2->mHealthUIID = -1;
    v2->mCurrentHealthUI = 4;
    Render::FXManager::KillEffect(&Render::gFXManager, v5, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
    v6 = v2->mFightClassFXOverride.m_pPointer;
    if ( v6 )
    {
      --v6->mReferenceCount;
      v7 = v2->mFightClassFXOverride.m_pPointer;
      if ( v7->mReferenceCount <= 0 )
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
    v2->mFightClassUIType = 0;
    v2->mFightClassUIID = -1;
    v8 = &v2->mComponent;
    if ( v8->m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v8->mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v8->m_pPointer = 0i64;
  }
}

// File Line: 251
// RVA: 0x3FFE90
void __fastcall UFG::WorldEffectsManager::BeginFrame(UFG::WorldEffectsManager *this, float dt)
{
  UFG::WorldEffectsManager *v2; // rsi
  char v3; // di
  char v4; // al
  UFG::SimObjectCharacter *v5; // rax
  UFG::SimObject *v6; // r14
  UFG::SimObject *v7; // r15
  UFG::SimComponent *v8; // rax
  UFG::TransformNodeComponent *v9; // rbx
  UFG::SimComponent *v10; // rbp
  float v11; // ecx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  float v13; // xmm1_4
  UFG::SimObject *v14; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  signed __int64 v18; // rcx
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
  float v29; // xmm0_4

  v2 = this;
  v3 = 0;
  if ( !UFG::LocalPlayerIsInCombatManager::s_pInstance
    || !UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0)
    || (v4 = 1, UFG::WorldEffectsManager::sDisableHealthUIs) )
  {
    v4 = 0;
  }
  v2->mShowHealthUIs = v4;
  if ( v4 )
  {
    v5 = UFG::GetLocalPlayer();
    v6 = v2->mFocusTarget.m_pPointer;
    v7 = (UFG::SimObject *)&v5->vfptr;
    v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v9 = v7->m_pTransformNodeComponent;
    v10 = v8;
    UFG::TransformNodeComponent::UpdateWorldTransform(v7->m_pTransformNodeComponent);
    v11 = v9->mWorldTransform.v3.x;
    v12 = &v2->mFocusTarget;
    v13 = v9->mWorldTransform.v3.z;
    v2->mPlayerPos.y = v9->mWorldTransform.v3.y;
    v2->mPlayerPos.z = v13;
    v2->mPlayerPos.x = v11;
    if ( v10 )
    {
      v14 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + 30i64)
                               + *(_QWORD *)&v10[1].m_TypeUID
                               + 40);
      if ( v2->mFocusTarget.m_pPointer )
      {
        v15 = v12->mPrev;
        v16 = v2->mFocusTarget.mNext;
        v15->mNext = v16;
        v16->mPrev = v15;
        v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
        v2->mFocusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mFocusTarget.mPrev;
      }
      v2->mFocusTarget.m_pPointer = v14;
      if ( v14 )
      {
        v17 = v14->m_SafePointerList.mNode.mPrev;
        v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
        v12->mPrev = v17;
        v2->mFocusTarget.mNext = &v14->m_SafePointerList.mNode;
        v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      }
      v2->mPlayerFaction = (UFG::eFactionClassEnum)UFG::SimObject::GetComponentOfType(
                                                     v7,
                                                     UFG::SimObjectCharacterPropertiesComponent::_TypeUID)[3].m_SafePointerList.mNode.mPrev;
      v18 = *(_QWORD *)&v10[1].m_TypeUID + 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + 30i64);
      if ( *(_QWORD *)(v18 + 40) && *(_BYTE *)(v18 + 49) )
        v3 = 1;
    }
    else
    {
      if ( v2->mFocusTarget.m_pPointer )
      {
        v19 = v12->mPrev;
        v20 = v2->mFocusTarget.mNext;
        v19->mNext = v20;
        v20->mPrev = v19;
        v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
        v2->mFocusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mFocusTarget.mPrev;
      }
      v2->mFocusTarget.m_pPointer = 0i64;
      v2->mPlayerFaction = 0;
    }
    v2->mFocusTargetLocked = v3;
    if ( v3 )
    {
      if ( v6 )
      {
        v21 = v2->mFocusTarget.m_pPointer;
        if ( v21 )
        {
          if ( v6 != v21 )
          {
            v22 = UFG::SimObject::GetComponentOfType(v6, UFG::CharacterEffectsComponent::_TypeUID);
            v23 = UFG::SimObject::GetComponentOfType(
                    v2->mFocusTarget.m_pPointer,
                    UFG::CharacterEffectsComponent::_TypeUID);
            v24 = v22 && HIDWORD(v22[6].m_pSimObject) != -1;
            v25 = v23 && HIDWORD(v23[6].m_pSimObject) != -1;
            if ( v24 && v25 )
            {
              v26 = v2->mFocusTarget.m_pPointer->m_pTransformNodeComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(v26);
              v27 = v6->m_pTransformNodeComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(v6->m_pTransformNodeComponent);
              UFG::WorldEffectsManager::StartWorldEffect(
                v2,
                0,
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
    v29 = UFG::GameStatTracker::GetStat(v28, PlayerFaceMeterBuff_Activated);
    if ( v29 <= 0.0 )
      goto LABEL_39;
    if ( !v2->mTriggeredBuffEffect )
    {
      UFG::WorldEffectsManager::StartWorldEffect(
        v2,
        WorldEffectType_BuffEffect,
        &v2->mPlayerPos,
        &v2->mPlayerPos,
        &UFG::qMatrix44::msIdentity,
        -1.0);
      v2->mTriggeredBuffEffect = 1;
      return;
    }
    if ( v29 <= 0.0 )
LABEL_39:
      v2->mTriggeredBuffEffect = 0;
  }
}

// File Line: 314
// RVA: 0x4006E0
void __fastcall UFG::WorldEffectsManager::EndFrame(UFG::WorldEffectsManager *this, float dt)
{
  float v2; // xmm6_4
  float v3; // xmm0_4
  UFG::WorldEffectsManager *v4; // rbx
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4

  v2 = dt;
  v3 = this->mHealthUITimer - dt;
  v4 = this;
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
  v6 = (float)(v2 * 4.0) + this->mGlobalAlpha;
  if ( v6 >= 1.0 )
    v6 = *(float *)&FLOAT_1_0;
  this->mGlobalAlpha = v6;
LABEL_14:
  UFG::WorldEffectsManager::UpdateUIEffects(this, v2);
  UFG::WorldEffectsManager::UpdateWorldEffects(v4, v2);
}

// File Line: 341
// RVA: 0x402CB0
void __fastcall UFG::WorldEffectsManager::UpdateUIEffects(UFG::WorldEffectsManager *this, UFG::CharacterEffectsComponent *component)
{
  bool v2; // r12
  bool v3; // r14
  UFG::CharacterEffectsComponent *v4; // rsi
  UFG::WorldEffectsManager *v5; // rdi
  UFG::SimObjectCharacter *v6; // rax
  UFG::SimObjectCVBase *v7; // rbp
  UFG::HealthComponent *v8; // rcx
  UFG::ActiveAIEntityComponent *v9; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v10; // rax
  UFG::SimComponent *v11; // r15
  UFG::eFactionClassEnum v12; // ebx
  UFG::GameStatTracker *v13; // rax
  __m128 v14; // xmm2
  float v15; // xmm0_4
  float v16; // xmm1_4
  UFG::SimComponentHolder *v17; // rcx
  bool v18; // al
  bool v19; // zf
  float v20; // xmm0_4
  float v21; // xmm0_4
  unsigned int v22; // eax

  v2 = 0;
  v3 = 0;
  v4 = component;
  v5 = this;
  if ( this->mShowHealthUIs )
  {
    if ( component->ShowHealthBar )
    {
      v6 = UFG::GetLocalPlayer();
      v7 = (UFG::SimObjectCVBase *)v4->m_pSimObject;
      if ( v7 != (UFG::SimObjectCVBase *)v6 )
      {
        if ( v7 )
        {
          v8 = (UFG::HealthComponent *)v7->m_Components.p[6].m_pComponent;
          if ( v8 )
          {
            if ( !UFG::HealthComponent::GetIsKilled(v8) )
            {
              v9 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v7);
              v10 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v7);
              v11 = v7->m_Components.p[2].m_pComponent;
              if ( v9 )
              {
                if ( v10 )
                {
                  if ( v11 )
                  {
                    if ( UFG::g_AIObjectiveParams[v9->m_CurrentObjective].m_IsHostile )
                    {
                      v12 = v10->m_eFactionClass;
                      v13 = UFG::FactionInterface::Get();
                      v2 = (unsigned int)UFG::FactionInterface::GetStanding(
                                           &v13->mFactionInterface,
                                           v5->mPlayerFaction,
                                           v12) == 0;
                      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11);
                      v14 = (__m128)HIDWORD(v11[2].m_BoundComponentHandles.mNode.mPrev);
                      v15 = *(float *)&v11[2].m_BoundComponentHandles.mNode.mPrev - v5->mPlayerPos.x;
                      v16 = *(float *)&v11[2].m_BoundComponentHandles.mNode.mNext - v5->mPlayerPos.z;
                      v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] - v5->mPlayerPos.y)
                                                      * (float)(v14.m128_f32[0] - v5->mPlayerPos.y))
                                              + (float)(v15 * v15))
                                      + (float)(v16 * v16);
                      if ( COERCE_FLOAT(_mm_sqrt_ps(v14)) < (float)(UFG::WorldEffectsManager::sAlphaUIRadius * 1.2) )
                      {
                        v17 = v7->m_Components.p;
                        if ( !v17[44].m_pComponent )
                        {
                          v18 = UFG::HasRangedWeaponEquippedWithAmmo((UFG::TargetingSystemBaseComponent *)v17[20].m_pComponent);
                          v3 = v18 == 0;
                          if ( !v18 )
                            goto LABEL_30;
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
  }
  if ( v5->mFocusTargetLocked )
  {
LABEL_30:
    v19 = v5->mHealthMeterActive == 0;
    v5->mCheckForHostileTimer = UFG::WorldEffectsManager::sCheckForHostileTimeout;
    if ( v19 )
    {
      v5->mHealthMeterActive = 1;
      v20 = UFG::WorldEffectsManager::sHealthUITimeout;
      v5->mGlobalAlpha = 1.0;
      v5->mHealthUITimer = v20;
    }
    if ( v5->mFocusTargetLocked )
    {
      v21 = v5->mHealthUITimer;
      if ( v21 <= UFG::WorldEffectsManager::sLockOnHealthUITimeout )
        v21 = UFG::WorldEffectsManager::sLockOnHealthUITimeout;
      v5->mHealthUITimer = v21;
    }
  }
  if ( v3 && v5->mHealthMeterActive && v5->mGlobalAlpha > 0.0 )
  {
    if ( v4->mUIElementIndex == -1 )
    {
      v22 = UFG::WorldEffectsManager::AllocUIElement(v5);
      v4->mUIElementIndex = v22;
      if ( v22 != -1 )
      {
        UFG::qSafePointer<Creature,Creature>::operator=(
          (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v5->mUIElements[v22].mComponent,
          (UFG::SimComponent *)&v4->vfptr);
        v5->mUIElements[v4->mUIElementIndex].mIsAlly = v2;
      }
    }
  }
  else
  {
    UFG::WorldEffectsManager::FreeUIElement(v5, v4->mUIElementIndex);
    v4->mUIElementIndex = -1;
  }
}

// File Line: 427
// RVA: 0x4010C0
void __fastcall UFG::WorldEffectsManager::RemoveUIEffects(UFG::WorldEffectsManager *this, UFG::CharacterEffectsComponent *component)
{
  UFG::CharacterEffectsComponent *v2; // rbx
  unsigned int v3; // edx

  v2 = component;
  v3 = component->mUIElementIndex;
  if ( v3 != -1 )
  {
    UFG::WorldEffectsManager::FreeUIElement(this, v3);
    v2->mUIElementIndex = -1;
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
  __int64 v7; // r15
  UFG::SimObjectCVBase *v8; // r14
  UFG::SimComponent *v9; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v10; // r13
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rax
  bool v13; // zf
  UFG::SimObjectGame *v14; // rcx
  unsigned __int16 v15; // cx
  UFG::SimObjectCharacterPropertiesComponent *v16; // rax
  bool v17; // al
  int v18; // er15
  signed int v19; // er12
  unsigned int v20; // edi
  UFG::allocator::free_link *v21; // rax
  __int64 v22; // rax
  signed __int64 v23; // rdi
  unsigned int *v24; // rbx
  signed int v25; // edi
  Render::FXOverride *v26; // rax
  Render::FXOverride *v27; // r15
  UFG::allocator::free_link *v28; // rax
  unsigned int v29; // edx
  UFG::allocator::free_link *v30; // rax
  unsigned __int16 v31; // cx
  UFG::CharacterAnimationComponent *v32; // rax
  Creature *v33; // rcx
  UFG::BaseCameraComponent *v34; // rax
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm8_4
  UFG::BaseCameraComponent *v38; // rax
  float v39; // xmm12_4
  float v40; // xmm13_4
  float v41; // xmm14_4
  __int128 v42; // xmm4
  __m128 v43; // xmm5
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
  float v68; // xmm3_4
  float v69; // xmm7_4
  float v70; // xmm9_4
  float v71; // xmm3_4
  float v72; // xmm2_4
  float v73; // xmm1_4
  UFG::TransformNodeComponent *v74; // rcx
  __m128 v75; // xmm2
  float v76; // xmm1_4
  Render::FXOverride *v77; // rax
  float v78; // xmm1_4
  Render::FXOverride *v79; // rax
  UFG::qVector3 result; // [rsp+40h] [rbp-C0h]
  __int64 v81; // [rsp+50h] [rbp-B0h]
  __int64 v82; // [rsp+58h] [rbp-A8h]
  float v83; // [rsp+60h] [rbp-A0h]
  float v84; // [rsp+64h] [rbp-9Ch]
  float v85; // [rsp+68h] [rbp-98h]
  float v86; // [rsp+70h] [rbp-90h]
  float v87; // [rsp+74h] [rbp-8Ch]
  float v88; // [rsp+78h] [rbp-88h]
  UFG::qMatrix44 m; // [rsp+80h] [rbp-80h]
  UFG::WorldEffectsManager *v90; // [rsp+1B0h] [rbp+B0h]
  float v91; // [rsp+1B8h] [rbp+B8h]
  bool v92; // [rsp+1C0h] [rbp+C0h]
  unsigned int v93; // [rsp+1C8h] [rbp+C8h]

  v91 = dt;
  v90 = this;
  v2 = FLOAT_15_0;
  v3 = 0;
  v4 = 0i64;
  v5 = this;
  v93 = 0;
  v81 = 0i64;
  do
  {
    v6 = &v5->mUIElements[v4];
    v7 = (__int64)v6->mComponent.m_pPointer;
    v82 = v7;
    if ( !v7 )
      goto LABEL_117;
    v8 = *(UFG::SimObjectCVBase **)(v7 + 40);
    if ( v6->mIsAlly )
    {
      if ( v6->mHealthUIID == -1 )
        v6->mHealthUIID = Render::FXManager::CreateEffect(
                            &Render::gFXManager,
                            UFG::WorldEffectsManager::sFriendlyTargedEffectID,
                            v6->mTransformNode,
                            0xFFFFFFFF,
                            0i64);
      goto LABEL_68;
    }
    if ( v8 )
    {
      v11 = v8->m_Flags;
      if ( (v11 >> 14) & 1 )
      {
        v9 = v8->m_Components.p[6].m_pComponent;
      }
      else if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  *(UFG::SimObjectGame **)(v7 + 40),
                  UFG::HealthComponent::_TypeUID);
        }
        else
        {
          v13 = ((v11 >> 12) & 1) == 0;
          v14 = *(UFG::SimObjectGame **)(v7 + 40);
          if ( v13 )
            v12 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v14->vfptr, UFG::HealthComponent::_TypeUID);
          else
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::HealthComponent::_TypeUID);
        }
        v9 = v12;
      }
      else
      {
        v9 = v8->m_Components.p[6].m_pComponent;
      }
      v15 = v8->m_Flags;
      if ( (v15 >> 14) & 1 )
      {
        v16 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v8);
      }
      else if ( (v15 & 0x8000u) == 0 )
      {
        if ( (v15 >> 13) & 1 )
        {
          v16 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                (UFG::SimObjectGame *)&v8->vfptr,
                                                                UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        }
        else if ( (v15 >> 12) & 1 )
        {
          v16 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                (UFG::SimObjectGame *)&v8->vfptr,
                                                                UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        }
        else
        {
          v16 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                (UFG::SimObject *)&v8->vfptr,
                                                                UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        }
      }
      else
      {
        v16 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v8);
      }
      v10 = v16;
    }
    else
    {
      v9 = 0i64;
      v10 = 0i64;
    }
    v17 = v8 == (UFG::SimObjectCVBase *)v5->mFocusTarget.m_pPointer
       && v5->mFocusTargetLocked
       && !UFG::WorldEffectsManager::IsWorldEffectActive(v5, 0);
    v92 = v17;
    if ( *(_BYTE *)(v7 + 432) )
      v18 = (v17 != 0) + 2;
    else
      v18 = v17 != 0;
    v19 = (signed int)(float)((float)(*((float *)&v9[1].m_SafePointerList.mNode.mNext + 1) / *(float *)&v9[1].m_NameUID)
                            * 4.0);
    if ( v19 > 3 )
      v19 = 3;
    if ( v6->mHealthUIType != v18 || v6->mCurrentHealthUI != v19 || v6->mHealthUIID == -1 )
    {
      Render::FXManager::KillEffect(&Render::gFXManager, v6->mHealthUIID, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
      v20 = UFG::WorldEffectsManager::sHealthUIEffectIds[v19 + 4i64 * v18].mMainEffect;
      v21 = Render::FXOverride::CreateOverride("mHealthFXOverride", 0i64);
      FX::SharedPointer<Render::FXOverride>::Set(&v6->mHealthFXOverride, (Render::FXOverride *)v21);
      v6->mHealthUIID = Render::FXManager::CreateEffect(
                          &Render::gFXManager,
                          v20,
                          v6->mTransformNode,
                          0xFFFFFFFF,
                          v6->mHealthFXOverride.m_pPointer);
      v22 = v6->mCurrentHealthUI;
      if ( (_DWORD)v22 != 4 && (signed int)v22 > v19 && v22 != v19 )
      {
        v23 = (signed int)v6->mCurrentHealthUI - (signed __int64)v19;
        v24 = &UFG::WorldEffectsManager::sHealthUIEffectIds[v22 + 4i64 * v18].mDepleteEffect;
        do
        {
          Render::FXManager::CreateEffect(&Render::gFXManager, *v24, v6->mTransformNode, 0xFFFFFFFF, 0i64);
          v24 -= 2;
          --v23;
        }
        while ( v23 );
      }
      v6->mHealthUIType = v18;
      v6->mCurrentHealthUI = v19;
    }
    if ( v10->m_eFightingClass == 5 )
    {
      v25 = 1;
    }
    else if ( v10->m_eFightingClass == 6 )
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
        v27 = v6->mFightClassFXOverride.m_pPointer;
        if ( v27->mReferenceCount <= 0 )
        {
          if ( v27 )
          {
            Render::FXOverride::~FXOverride(v6->mFightClassFXOverride.m_pPointer);
            operator delete[](v27);
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
        if ( v92 )
          v29 = UFG::WorldEffectsManager::sBrawlerTargetEffectID;
      }
      else
      {
        if ( v25 != 2 )
        {
LABEL_66:
          v6->mFightClassUIType = v25;
          goto LABEL_67;
        }
        v28 = Render::FXOverride::CreateOverride("mFightClassFXOverride", 0i64);
        FX::SharedPointer<Render::FXOverride>::Set(&v6->mFightClassFXOverride, (Render::FXOverride *)v28);
        v29 = UFG::WorldEffectsManager::sGrapplerEffectID;
        if ( v92 )
          v29 = UFG::WorldEffectsManager::sGrapplerTargetEffectID;
      }
      v6->mFightClassUIID = Render::FXManager::CreateEffect(
                              &Render::gFXManager,
                              v29,
                              v6->mTransformNode,
                              0xFFFFFFFF,
                              v6->mFightClassFXOverride.m_pPointer);
      goto LABEL_66;
    }
LABEL_67:
    v4 = v81;
    v3 = v93;
    v7 = v82;
    v5 = v90;
LABEL_68:
    if ( v8
      && ((v31 = v8->m_Flags, !((v31 >> 14) & 1)) ? ((v31 & 0x8000u) == 0 ? (!((v31 >> 13) & 1) ? (!((v31 >> 12) & 1) ? (v32 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::CharacterAnimationComponent::_TypeUID)) : (v32 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v8->vfptr, UFG::CharacterAnimationComponent::_TypeUID))) : (v32 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8))) : (v32 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8))) : (v32 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8)),
          v32) )
    {
      v33 = v32->mCreature;
    }
    else
    {
      v33 = 0i64;
    }
    if ( v33 )
    {
      Creature::GetTranslation(v33, &result, 1);
      result.z = result.z - UFG::WorldEffectsManager::sRaycastLength;
      v34 = UFG::Director::Get()->mCurrentCamera;
      if ( v34 )
        v34 = (UFG::BaseCameraComponent *)((char *)v34 + 80);
      v35 = COERCE_FLOAT(LODWORD(v34->mCamera.mView.v1.x) ^ _xmm[0]) * v2;
      v36 = COERCE_FLOAT(LODWORD(v34->mCamera.mView.v1.y) ^ _xmm[0]) * v2;
      v37 = COERCE_FLOAT(LODWORD(v34->mCamera.mView.v1.z) ^ _xmm[0]) * v2;
      v38 = UFG::Director::Get()->mCurrentCamera;
      if ( v38 )
        v38 = (UFG::BaseCameraComponent *)((char *)v38 + 80);
      v42 = LODWORD(v38->mCamera.mView.v2.x);
      v43 = (__m128)LODWORD(v38->mCamera.mView.v2.y);
      v39 = result.x;
      v40 = result.y;
      v41 = result.z;
      *(float *)&v42 = (float)(*(float *)&v42 - v35) - result.x;
      v43.m128_f32[0] = (float)(v43.m128_f32[0] - v36) - result.y;
      v44 = v43;
      v44.m128_f32[0] = (float)((float)(v43.m128_f32[0] * v43.m128_f32[0]) + (float)(*(float *)&v42 * *(float *)&v42))
                      + (float)((float)((float)(v38->mCamera.mView.v2.z - v37) - result.z)
                              * (float)((float)(v38->mCamera.mView.v2.z - v37) - result.z));
      if ( v44.m128_f32[0] == 0.0 )
        v45 = 0.0;
      else
        v45 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v44));
      v46 = *(float *)&v42 * v45;
      v43.m128_f32[0] = v43.m128_f32[0] * v45;
      v47 = UFG::WorldEffectsManager::sNormalLerpRateScale * v91;
      if ( (float)(UFG::WorldEffectsManager::sNormalLerpRateScale * v91) <= 0.0 )
      {
        v47 = 0.0;
      }
      else if ( v47 >= 1.0 )
      {
        v47 = *(float *)&FLOAT_1_0;
      }
      v49 = (__m128)LODWORD(v6->mPreviousNormal.y);
      v51 = v43;
      v48 = (float)((float)(v6->mPreviousNormal.x - v6->mCurrentNormal.x) * v47) + v6->mCurrentNormal.x;
      v49.m128_f32[0] = (float)((float)(v49.m128_f32[0] - v6->mCurrentNormal.y) * v47) + v6->mCurrentNormal.y;
      v50 = (float)((float)(v6->mPreviousNormal.z - v6->mCurrentNormal.z) * v47) + v6->mCurrentNormal.z;
      v6->mCurrentNormal.x = v48;
      v51.m128_f32[0] = (float)(v43.m128_f32[0] * v43.m128_f32[0]) + (float)(v46 * v46);
      LODWORD(v6->mCurrentNormal.y) = v49.m128_i32[0];
      v6->mCurrentNormal.z = v50;
      if ( v51.m128_f32[0] == 0.0 )
        v52 = 0.0;
      else
        v52 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v51));
      v53 = v48;
      *(float *)&v42 = v46 * v52;
      v54 = v43.m128_f32[0] * v52;
      v55 = v49;
      m.v0.w = 0.0;
      LODWORD(m.v0.x) = v42;
      m.v0.y = v54;
      v55.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v53 * v53)) + (float)(v50 * v50);
      v56 = v52 * 0.0;
      m.v0.z = v56;
      if ( v55.m128_f32[0] == 0.0 )
        v57 = 0.0;
      else
        v57 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v55));
      v58 = v49.m128_f32[0] * v57;
      v59 = v50 * v57;
      v60 = v57;
      v63 = (__m128)v42;
      v61 = v60 * v53;
      v62 = (float)(v56 * v58) - (float)(v54 * v59);
      v63.m128_f32[0] = (float)(*(float *)&v42 * v59) - (float)(v56 * v61);
      v64 = *(float *)&v42 * v58;
      v66 = v63;
      v65 = (float)(v54 * v61) - v64;
      v66.m128_f32[0] = (float)((float)(v63.m128_f32[0] * v63.m128_f32[0]) + (float)(v62 * v62)) + (float)(v65 * v65);
      if ( v66.m128_f32[0] == 0.0 )
        v67 = 0.0;
      else
        v67 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v66));
      v68 = v63.m128_f32[0] * v67;
      m.v1.w = 0.0;
      m.v1.y = v68;
      m.v1.z = v65 * v67;
      m.v1.x = v62 * v67;
      v69 = (float)((float)(v65 * v67) * v54) - (float)(v68 * v56);
      v70 = (float)((float)(v62 * v67) * v56) - (float)((float)(v65 * v67) * *(float *)&v42);
      v71 = (float)(v68 * *(float *)&v42) - (float)((float)(v62 * v67) * v54);
      v72 = (float)((float)(v70 * v70) + (float)(v69 * v69)) + (float)(v71 * v71);
      if ( v72 == 0.0 )
        v73 = 0.0;
      else
        v73 = 1.0 / fsqrt(v72);
      v74 = v6->mTransformNode;
      m.v3.x = v39;
      m.v3.y = v40;
      m.v2.w = 0.0;
      m.v3.w = 1.0;
      m.v3.z = v41;
      m.v2.x = v69 * v73;
      m.v2.y = v70 * v73;
      m.v2.z = v71 * v73;
      UFG::TransformNodeComponent::SetWorldTransform(v74, &m);
      v87 = result.y;
      v84 = result.y;
      v86 = result.x;
      v83 = result.x;
      v85 = result.z - UFG::WorldEffectsManager::sRaycastLength;
      v88 = UFG::WorldEffectsManager::sRaycastLength + result.z;
      UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay(
        UFG::BasePhysicsSystem::mInstance,
        (UFG::qVector3 *)&v86,
        (UFG::qVector3 *)&v83,
        15u,
        UFG::WorldEffectsManager::AsyncRayCallback,
        (UFG::SimComponent *)v7,
        v6);
      v75 = (__m128)LODWORD(v5->mPlayerPos.y);
      v75.m128_f32[0] = (float)((float)((float)(v75.m128_f32[0] - result.y) * (float)(v75.m128_f32[0] - result.y))
                              + (float)((float)(v5->mPlayerPos.x - result.x) * (float)(v5->mPlayerPos.x - result.x)))
                      + (float)((float)(v5->mPlayerPos.z - result.z) * (float)(v5->mPlayerPos.z - result.z));
      v76 = (float)(1.0 - (float)(COERCE_FLOAT(_mm_sqrt_ps(v75)) / UFG::WorldEffectsManager::sAlphaUIRadius)) + 0.75;
      if ( v76 <= 0.0 )
      {
        v76 = 0.0;
      }
      else if ( v76 >= 1.0 )
      {
        v76 = *(float *)&FLOAT_1_0;
      }
      if ( UFG::WorldEffectsManager::sOverrideUIAlpha )
        v76 = UFG::WorldEffectsManager::sOverrideUIAlphaValue;
      v77 = v6->mHealthFXOverride.m_pPointer;
      v78 = v76 * v5->mGlobalAlpha;
      if ( v77 )
        v77->stateBlock.ColorTint[3] = v78;
      v79 = v6->mFightClassFXOverride.m_pPointer;
      v2 = FLOAT_15_0;
      if ( v79 )
        v79->stateBlock.ColorTint[3] = v78;
    }
LABEL_117:
    ++v3;
    ++v4;
    v93 = v3;
    v81 = v4;
  }
  while ( v3 < 0xF );
}

// File Line: 599
// RVA: 0x4017C0
void __fastcall UFG::WorldEffectsManager::StartWorldEffect(UFG::WorldEffectsManager *this, UFG::WorldEffectsManager::WorldEffectType type, UFG::qVector3 *startPos, UFG::qVector3 *endPos, UFG::qMatrix44 *transform, float duration)
{
  __int64 v6; // r10
  UFG::WorldEffectsManager::WorldEffectElement *v7; // rbx
  unsigned int v8; // eax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // eax
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  UFG::qVector4 v18; // xmm3
  UFG::qVector4 v19; // xmm2
  UFG::qVector4 v20; // xmm1
  unsigned int v21; // eax

  v6 = type;
  v7 = this->mWorldEffectElements;
  v8 = 0;
  while ( v7->mActive )
  {
    ++v8;
    ++v7;
    if ( v8 >= 5 )
      return;
  }
  v9 = &v7->mParentTransform;
  if ( v7->mParentTransform.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v7->mParentTransform.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v7->mParentTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mParentTransform.mPrev;
  }
  v12 = duration;
  v7->mParentTransform.m_pPointer = 0i64;
  v7->mEffectType = v6;
  if ( duration <= 0.0 )
    v13 = FLOAT_3_4028235e38;
  else
    v13 = duration;
  v7->mDuration = v13;
  if ( duration <= 0.0 )
    v12 = FLOAT_3_4028235e38;
  v7->mTime = v12;
  v14 = startPos->x;
  v15 = startPos->z;
  v7->mStart.y = startPos->y;
  v7->mStart.x = v14;
  v7->mStart.z = v15;
  v16 = endPos->y;
  v17 = endPos->z;
  v7->mEnd.x = endPos->x;
  v7->mEnd.y = v16;
  v7->mEnd.z = v17;
  v18 = transform->v1;
  v19 = transform->v2;
  v20 = transform->v3;
  v7->mTransform.v0 = transform->v0;
  v7->mTransform.v1 = v18;
  v7->mTransform.v2 = v19;
  v7->mTransform.v3 = v20;
  v21 = Render::FXManager::CreateEffect(
          &Render::gFXManager,
          UFG::WorldEffectsManager::sWorldEffectIds[v6],
          v7->mTransformNode,
          0xFFFFFFFF,
          0i64);
  v7->mEffectID = v21;
  v7->mActive = v21 != -1;
}

// File Line: 619
// RVA: 0x4018E0
signed __int64 __fastcall UFG::WorldEffectsManager::StartWorldEffect(UFG::WorldEffectsManager *this, unsigned int effectID, UFG::qVector3 *startPos, UFG::qVector3 *endPos, UFG::qMatrix44 *transform, float duration)
{
  unsigned int v6; // er10
  UFG::WorldEffectsManager::WorldEffectElement *v7; // rbx
  unsigned int v8; // eax
  signed __int64 result; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // eax
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  UFG::qVector4 v19; // xmm3
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1

  v6 = effectID;
  v7 = this->mWorldEffectElements;
  v8 = 0;
  while ( v7->mActive )
  {
    ++v8;
    ++v7;
    if ( v8 >= 5 )
      return 0xFFFFFFFFi64;
  }
  v10 = &v7->mParentTransform;
  if ( v7->mParentTransform.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v7->mParentTransform.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v7->mParentTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mParentTransform.mPrev;
  }
  v13 = duration;
  v7->mParentTransform.m_pPointer = 0i64;
  v7->mEffectType = 2;
  if ( duration <= 0.0 )
    v14 = FLOAT_3_4028235e38;
  else
    v14 = duration;
  v7->mDuration = v14;
  if ( duration <= 0.0 )
    v13 = FLOAT_3_4028235e38;
  v7->mTime = v13;
  v15 = startPos->x;
  v16 = startPos->z;
  v7->mStart.y = startPos->y;
  v7->mStart.x = v15;
  v7->mStart.z = v16;
  v17 = endPos->y;
  v18 = endPos->z;
  v7->mEnd.x = endPos->x;
  v7->mEnd.y = v17;
  v7->mEnd.z = v18;
  v19 = transform->v1;
  v20 = transform->v2;
  v21 = transform->v3;
  v7->mTransform.v0 = transform->v0;
  v7->mTransform.v1 = v19;
  v7->mTransform.v2 = v20;
  v7->mTransform.v3 = v21;
  result = Render::FXManager::CreateEffect(&Render::gFXManager, v6, v7->mTransformNode, 0xFFFFFFFF, 0i64);
  v7->mEffectID = result;
  v7->mActive = (_DWORD)result != -1;
  return result;
}

// File Line: 640
// RVA: 0x401A00
signed __int64 __fastcall UFG::WorldEffectsManager::StartWorldEffect(UFG::WorldEffectsManager *this, unsigned int effectID, UFG::SimObject *attachTo, UFG::qMatrix44 *transform, float duration)
{
  UFG::TransformNodeComponent *v5; // rdi
  UFG::qMatrix44 *v6; // rsi
  unsigned int v7; // ebp
  unsigned int v8; // eax
  UFG::WorldEffectsManager::WorldEffectElement *v9; // rbx
  signed __int64 result; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  float v14; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // eax
  float v20; // xmm1_4
  UFG::qVector4 v21; // xmm3
  UFG::qVector4 v22; // xmm2
  UFG::qVector4 v23; // xmm1

  v5 = attachTo->m_pTransformNodeComponent;
  v6 = transform;
  v7 = effectID;
  v8 = 0;
  v9 = this->mWorldEffectElements;
  while ( v9->mActive )
  {
    ++v8;
    ++v9;
    if ( v8 >= 5 )
      return 0xFFFFFFFFi64;
  }
  if ( !v5 )
    return 0xFFFFFFFFi64;
  v11 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mParentTransform.mPrev;
  if ( v9->mParentTransform.m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v9->mParentTransform.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = v11;
    v9->mParentTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mParentTransform.mPrev;
  }
  v14 = duration;
  v9->mParentTransform.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
  v15 = v5->m_SafePointerList.mNode.mPrev;
  v15->mNext = v11;
  v11->mPrev = v15;
  v9->mParentTransform.mNext = &v5->m_SafePointerList.mNode;
  v5->m_SafePointerList.mNode.mPrev = v11;
  v9->mEffectType = 2;
  if ( duration <= 0.0 )
    v16 = FLOAT_3_4028235e38;
  else
    v16 = duration;
  v9->mDuration = v16;
  if ( duration <= 0.0 )
    v14 = FLOAT_3_4028235e38;
  v9->mTime = v14;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v17 = v5->mWorldTransform.v3.y;
  v18 = v5->mWorldTransform.v3.z;
  v9->mStart.x = v5->mWorldTransform.v3.x;
  v9->mStart.y = v17;
  v9->mStart.z = v18;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v19 = v5->mWorldTransform.v3.x;
  v20 = v5->mWorldTransform.v3.z;
  v9->mEnd.y = v5->mWorldTransform.v3.y;
  v9->mEnd.z = v20;
  v9->mEnd.x = v19;
  v21 = v6->v1;
  v22 = v6->v2;
  v23 = v6->v3;
  v9->mTransform.v0 = v6->v0;
  v9->mTransform.v1 = v21;
  v9->mTransform.v2 = v22;
  v9->mTransform.v3 = v23;
  LODWORD(result) = Render::FXManager::CreateEffect(&Render::gFXManager, v7, v9->mTransformNode, 0xFFFFFFFF, 0i64);
  v9->mEffectID = result;
  v9->mActive = (_DWORD)result != -1;
  return (unsigned int)result;
}

// File Line: 681
// RVA: 0x4007B0
void __fastcall UFG::WorldEffectsManager::EndWorldEffect(UFG::WorldEffectsManager *this, unsigned int effectID)
{
  unsigned int v2; // esi
  unsigned int *v3; // rbx
  signed __int64 v4; // rdi

  v2 = effectID;
  v3 = &this->mWorldEffectElements[0].mEffectID;
  v4 = 5i64;
  do
  {
    if ( *((_BYTE *)v3 - 36) )
    {
      if ( *v3 == v2 )
      {
        Render::FXManager::KillEffect(&Render::gFXManager, *v3, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
        *((_BYTE *)v3 - 36) = 0;
        *v3 = -1;
      }
    }
    v3 += 36;
    --v4;
  }
  while ( v4 );
}

// File Line: 697
// RVA: 0x402F30
void __fastcall UFG::WorldEffectsManager::UpdateWorldEffects(UFG::WorldEffectsManager *this, float dt)
{
  unsigned int *v2; // rdi
  signed __int64 v3; // rsi
  unsigned int v4; // edx
  float v5; // xmm0_4
  float *v6; // rbx
  float v7; // xmm5_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm15_4
  float v11; // xmm14_4
  float v12; // xmm12_4
  float *v13; // rbx
  float v14; // xmm9_4
  float v15; // xmm11_4
  float v16; // xmm15_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm11_4
  float v20; // xmm12_4
  float v21; // xmm9_4
  __m128 v22; // xmm13
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  float v25; // xmm2_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  __m128 v28; // xmm4
  float v29; // xmm5_4
  float v30; // xmm7_4
  float v31; // xmm3_4
  __m128 v32; // xmm2
  float v33; // xmm8_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm8_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  float v39; // xmm9_4
  float v40; // xmm4_4
  float v41; // xmm8_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm4_4
  float v45; // xmm2_4
  float v46; // xmm11_4
  float v47; // xmm4_4
  float v48; // xmm3_4
  float v49; // xmm1_4
  UFG::qMatrix44 *v50; // rax
  UFG::TransformNodeComponent *v51; // rcx
  UFG::qVector4 v52; // xmm2
  UFG::qVector4 v53; // xmm1
  UFG::qVector4 v54; // xmm0
  __int64 v55; // rcx
  _QWORD *v56; // rax
  UFG::qMatrix44 m; // [rsp+20h] [rbp-C8h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-88h]
  float vars0; // [rsp+150h] [rbp+68h]

  v2 = (unsigned int *)&this->mWorldEffectElements[0].mStart.y;
  v3 = 5i64;
  do
  {
    if ( *((_BYTE *)v2 - 16) )
    {
      v4 = v2[5];
      *((float *)v2 - 3) = *((float *)v2 - 3) - dt;
      if ( Render::FXManager::FindEffect(&Render::gFXManager, v4) && (v5 = *((float *)v2 - 3), v5 >= 0.0) )
      {
        v6 = (float *)*((_QWORD *)v2 + 15);
        v7 = *(float *)&FLOAT_1_0;
        v8 = 0.0;
        v9 = 0.0;
        if ( v6 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(*((UFG::TransformNodeComponent **)v2 + 15));
          v10 = v6[44];
          v11 = v6[45];
          v12 = UFG::WorldEffectsManager::sHeightFudgeFactor + v6[46];
          v13 = (float *)*((_QWORD *)v2 + 15);
          UFG::TransformNodeComponent::UpdateWorldTransform(*((UFG::TransformNodeComponent **)v2 + 15));
          v7 = v13[32];
          v8 = v13[33];
          v9 = v13[34];
        }
        else
        {
          v22 = (__m128)*v2;
          v14 = *((float *)v2 + 1);
          v15 = *((float *)v2 - 1);
          v16 = v15;
          v17 = 1.0 - (float)(v5 / *((float *)v2 - 2));
          v18 = *((float *)v2 + 2) - v15;
          v19 = v15 - *((float *)v2 + 2);
          v10 = v16 + (float)(v18 * v17);
          v20 = (float)((float)(*((float *)v2 + 4) - v14) * v17) + v14;
          v21 = v14 - *((float *)v2 + 4);
          v12 = v20 + UFG::WorldEffectsManager::sHeightFudgeFactor;
          v11 = (float)((float)(*((float *)v2 + 3) - v22.m128_f32[0]) * v17) + v22.m128_f32[0];
          v22.m128_f32[0] = v22.m128_f32[0] - *((float *)v2 + 3);
          v23 = v22;
          v23.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v19 * v19))
                          + (float)(v21 * v21);
          if ( COERCE_FLOAT(_mm_sqrt_ps(v23)) > 0.02 )
          {
            v24 = v22;
            v24.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v19 * v19))
                            + (float)(v21 * v21);
            if ( v24.m128_f32[0] == 0.0 )
              v25 = 0.0;
            else
              v25 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
            v7 = v19 * v25;
            v8 = v22.m128_f32[0] * v25;
            v9 = 0.0;
          }
        }
        v26 = (float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9);
        if ( v26 == 0.0 )
          v27 = 0.0;
        else
          v27 = 1.0 / fsqrt(v26);
        v28 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        v29 = v7 * v27;
        v30 = v8 * v27;
        v31 = v27 * v9;
        m.v0.w = 0.0;
        v32 = v28;
        m.v0.x = v29;
        m.v0.y = v30;
        m.v0.z = v31;
        v32.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0])
                                + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                        + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
        if ( v32.m128_f32[0] == 0.0 )
          v33 = 0.0;
        else
          v33 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v32));
        v34 = v33;
        v35 = v33;
        v36 = v33 * UFG::qVector3::msDirUp.z;
        v37 = v35 * v28.m128_f32[0];
        v38 = v34 * UFG::qVector3::msDirUp.y;
        v39 = (float)(v31 * v38) - (float)(v30 * v36);
        v40 = (float)(v29 * v36) - (float)(v31 * v37);
        v41 = (float)(v30 * v37) - (float)(v29 * v38);
        v42 = (float)((float)(v40 * v40) + (float)(v39 * v39)) + (float)(v41 * v41);
        if ( v42 == 0.0 )
          v43 = 0.0;
        else
          v43 = 1.0 / fsqrt(v42);
        v44 = v40 * v43;
        m.v1.w = 0.0;
        m.v1.y = v44;
        m.v1.z = v41 * v43;
        m.v1.x = v39 * v43;
        v45 = (float)((float)(v41 * v43) * v30) - (float)(v44 * v31);
        v46 = (float)((float)(v39 * v43) * v31) - (float)((float)(v41 * v43) * v29);
        v47 = (float)(v44 * v29) - (float)((float)(v39 * v43) * v30);
        v48 = (float)((float)(v46 * v46) + (float)(v45 * v45)) + (float)(v47 * v47);
        if ( v48 == 0.0 )
          v49 = 0.0;
        else
          v49 = 1.0 / fsqrt(v48);
        m.v3.x = v10;
        m.v3.y = v11;
        m.v3.z = v12;
        m.v2.w = 0.0;
        m.v3.w = 1.0;
        m.v2.x = v45 * v49;
        m.v2.y = v46 * v49;
        m.v2.z = v47 * v49;
        v50 = UFG::qMatrix44::operator*(&m, &result, (UFG::qMatrix44 *)(v2 + 6));
        v51 = (UFG::TransformNodeComponent *)*((_QWORD *)v2 + 12);
        v52 = v50->v2;
        v53 = v50->v3;
        v54 = v50->v0;
        m.v1 = v50->v1;
        m.v2 = v52;
        m.v0 = v54;
        m.v3 = v53;
        UFG::TransformNodeComponent::SetWorldTransform(v51, &m);
      }
      else
      {
        Render::FXManager::KillEffect(&Render::gFXManager, v2[5], FXKILLOPTION_ERASE_EMITTED_OBJECTS);
        *((_BYTE *)v2 - 16) = 0;
        v2[5] = -1;
        if ( *((_QWORD *)v2 + 15) )
        {
          v55 = *((_QWORD *)v2 + 13);
          v56 = (_QWORD *)*((_QWORD *)v2 + 14);
          *(_QWORD *)(v55 + 8) = v56;
          *v56 = v55;
          *((_QWORD *)v2 + 13) = v2 + 26;
          *((_QWORD *)v2 + 14) = v2 + 26;
        }
        *((_QWORD *)v2 + 15) = 0i64;
      }
      dt = vars0;
    }
    v2 += 36;
    --v3;
  }
  while ( v3 );
}

// File Line: 759
// RVA: 0x3FED30
void __fastcall UFG::WorldEffectsManager::AsyncRayCallback(UFG::RayCastData *raycastData, UFG::SimComponent *simComponent, void *callbackUserData)
{
  unsigned int *v3; // rbx
  int v4; // xmm0_4
  int v5; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm12_4
  float v9; // xmm13_4
  float v10; // xmm14_4
  signed __int64 v11; // rdi
  UFG::BaseCameraComponent *v12; // rax
  _DWORD *v13; // rax
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  UFG::BaseCameraComponent *v17; // rcx
  __int128 v18; // xmm4
  __m128 v19; // xmm5
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
  float v40; // xmm7_4
  float v41; // xmm0_4
  __m128 v42; // xmm9
  float v43; // xmm7_4
  float v44; // xmm8_4
  __m128 v45; // xmm4
  float v46; // xmm2_4
  UFG::TransformNodeComponent *v47; // rcx
  int v48; // xmm1_4
  int v49; // xmm0_4
  float v50; // xmm2_4
  float v51; // xmm0_4
  UFG::qMatrix44 m; // [rsp+20h] [rbp-D8h]

  if ( simComponent )
  {
    v3 = (unsigned int *)callbackUserData;
    if ( raycastData->hit
      && (float)((float)((float)(UFG::qVector3::msDirUp.x * raycastData->normal.x)
                       + (float)(UFG::qVector3::msDirUp.y * raycastData->normal.y))
               + (float)(UFG::qVector3::msDirUp.z * raycastData->normal.z)) > 0.866 )
    {
      v4 = *((_DWORD *)callbackUserData + 13);
      v5 = *((_DWORD *)callbackUserData + 11);
      *((_DWORD *)callbackUserData + 15) = *((_DWORD *)callbackUserData + 12);
      *((_DWORD *)callbackUserData + 16) = v4;
      *((_DWORD *)callbackUserData + 14) = v5;
      v6 = raycastData->normal.y;
      v7 = raycastData->normal.z;
      *((_DWORD *)callbackUserData + 11) = LODWORD(raycastData->normal.x);
      *((float *)callbackUserData + 12) = v6;
      *((float *)callbackUserData + 13) = v7;
      v8 = UFG::WorldEffectsManager::sHeightFudgeFactor + raycastData->point.z;
      v9 = raycastData->point.x;
      v10 = raycastData->point.y;
      v11 = 0i64;
      v12 = UFG::Director::Get()->mCurrentCamera;
      if ( v12 )
        v13 = (_DWORD *)&v12->mCamera.mFOVOffset;
      else
        v13 = 0i64;
      v14 = COERCE_FLOAT(v13[40] ^ _xmm[0]) * 15.0;
      v15 = COERCE_FLOAT(v13[41] ^ _xmm[0]) * 15.0;
      v16 = COERCE_FLOAT(v13[42] ^ _xmm[0]) * 15.0;
      v17 = UFG::Director::Get()->mCurrentCamera;
      if ( v17 )
        v11 = (signed __int64)&v17->mCamera;
      v18 = *(unsigned int *)(v11 + 176);
      v19 = (__m128)*(unsigned int *)(v11 + 180);
      *(float *)&v18 = (float)(*(float *)&v18 - v14) - v9;
      v19.m128_f32[0] = (float)(v19.m128_f32[0] - v15) - v10;
      v20 = v19;
      v20.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(*(float *)&v18 * *(float *)&v18))
                      + (float)((float)((float)(*(float *)(v11 + 184) - v16) - v8)
                              * (float)((float)(*(float *)(v11 + 184) - v16) - v8));
      if ( v20.m128_f32[0] == 0.0 )
        v21 = 0.0;
      else
        v21 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v20));
      v22 = *(float *)&v18 * v21;
      v19.m128_f32[0] = v19.m128_f32[0] * v21;
      v23 = v19;
      v23.m128_f32[0] = (float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v22 * v22);
      if ( v23.m128_f32[0] == 0.0 )
      {
        v24 = 0i64;
      }
      else
      {
        v24 = (unsigned int)FLOAT_1_0;
        *(float *)&v24 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
      }
      v25 = *((float *)v3 + 12);
      v26 = (__m128)v3[11];
      v27 = *((float *)v3 + 13);
      *(float *)&v18 = v22 * *(float *)&v24;
      v28 = v19.m128_f32[0] * *(float *)&v24;
      *(float *)&v24 = *(float *)&v24 * 0.0;
      m.v0.w = 0.0;
      v29 = v26;
      LODWORD(m.v0.x) = v18;
      m.v0.y = v28;
      LODWORD(m.v0.z) = v24;
      v29.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v27 * v27);
      if ( v29.m128_f32[0] == 0.0 )
        v30 = 0.0;
      else
        v30 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29));
      v31 = v26.m128_f32[0] * v30;
      v32 = v27 * v30;
      v33 = v25 * v30;
      v34 = v24;
      v36 = (__m128)v18;
      v36.m128_f32[0] = *(float *)&v18 * v32;
      *(float *)&v34 = (float)(*(float *)&v24 * v33) - (float)(v28 * v32);
      v35 = v28 * v31;
      v36.m128_f32[0] = v36.m128_f32[0] - (float)(*(float *)&v24 * v31);
      v38 = v36;
      v37 = v35 - (float)(*(float *)&v18 * v33);
      v38.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(*(float *)&v34 * *(float *)&v34))
                      + (float)(v37 * v37);
      if ( v38.m128_f32[0] == 0.0 )
        v39 = 0.0;
      else
        v39 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v38));
      *(float *)&v34 = *(float *)&v34 * v39;
      v40 = v36.m128_f32[0] * v39;
      m.v1.w = 0.0;
      v42 = (__m128)v34;
      m.v1.z = v37 * v39;
      LODWORD(m.v1.x) = v34;
      m.v1.y = v40;
      v41 = v40 * *(float *)&v24;
      v42.m128_f32[0] = (float)(*(float *)&v34 * *(float *)&v24) - (float)((float)(v37 * v39) * *(float *)&v18);
      v43 = (float)(v40 * *(float *)&v18) - (float)(*(float *)&v34 * v28);
      v45 = v42;
      v44 = (float)((float)(v37 * v39) * v28) - v41;
      v45.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v44 * v44)) + (float)(v43 * v43);
      if ( v45.m128_f32[0] == 0.0 )
        v46 = 0.0;
      else
        v46 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v45));
      v47 = (UFG::TransformNodeComponent *)*((_QWORD *)v3 + 12);
      m.v3.x = v9;
      m.v3.y = v10;
      m.v2.w = 0.0;
      m.v3.w = 1.0;
      m.v3.z = v8;
      m.v2.x = v44 * v46;
      m.v2.y = v42.m128_f32[0] * v46;
      m.v2.z = v43 * v46;
      UFG::TransformNodeComponent::SetWorldTransform(v47, &m);
    }
    else
    {
      v48 = *((_DWORD *)callbackUserData + 12);
      v49 = *((_DWORD *)callbackUserData + 13);
      *((_DWORD *)callbackUserData + 14) = *((_DWORD *)callbackUserData + 11);
      *((_DWORD *)callbackUserData + 15) = v48;
      *((_DWORD *)callbackUserData + 16) = v49;
      v50 = UFG::qVector3::msDirUp.z;
      v51 = UFG::qVector3::msDirUp.x;
      *((_DWORD *)callbackUserData + 12) = LODWORD(UFG::qVector3::msDirUp.y);
      *((float *)callbackUserData + 11) = v51;
      *((float *)callbackUserData + 13) = v50;
    }
  }
}

