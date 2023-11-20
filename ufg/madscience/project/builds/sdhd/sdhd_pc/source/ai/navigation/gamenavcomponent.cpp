// File Line: 30
// RVA: 0x365B00
void __fastcall UFG::GameNavComponent::Init(UFG::GameNavComponent *this, UFG::SimObject *pSimObject)
{
  UFG::SceneObjectProperties *v2; // rax
  UFG::qPropertySet *v3; // rdi
  UFG::SimObject *v4; // rbx
  UFG::GameNavComponent *v5; // rsi
  char *v6; // rax
  char *v7; // rax
  int v8; // eax
  unsigned __int16 v9; // cx
  UFG::CharacterPhysicsComponent *v10; // rax
  unsigned int v11; // edx
  UFG::SimObjectGame *v12; // rcx
  bool v13; // zf
  float v14; // xmm0_4
  UFG::NavComponent::InitParameters parameters; // [rsp+20h] [rbp-18h]

  v2 = pSimObject->m_pSceneObj;
  *(_WORD *)&parameters.m_bIsFreerunner = 257;
  parameters.m_fAIRadius = 0.5;
  parameters.m_fAIAvoidanceRadius = 0.5;
  v3 = v2->mpWritableProperties;
  v4 = pSimObject;
  v5 = this;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v6 = UFG::qPropertySet::Get<char const *>(v3, (UFG::qSymbol *)&SimSym_AIEntityType.mUID, DEPTH_RECURSE);
  parameters.m_bIsFreerunner = strcmp(v6, "eAI_ENTITY_FREERUNNER") == 0;
  v7 = UFG::qPropertySet::Get<char const *>(v3, (UFG::qSymbol *)&SimSym_AIAvoidanceType.mUID, DEPTH_RECURSE);
  v8 = strcmp(v7, "eAI_AVOIDANCE_NONE");
  v9 = v4->m_Flags;
  parameters.m_bIsAvoidanceEnabled = v8 != 0;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::CharacterPhysicsComponent *)v4->m_Components.p[27].m_pComponent;
  }
  else
  {
    if ( (v9 & 0x8000u) != 0 || (v9 >> 13) & 1 )
    {
      v11 = UFG::CharacterPhysicsComponent::_TypeUID;
      v12 = (UFG::SimObjectGame *)v4;
    }
    else
    {
      v11 = UFG::CharacterPhysicsComponent::_TypeUID;
      v13 = ((v9 >> 12) & 1) == 0;
      v12 = (UFG::SimObjectGame *)v4;
      if ( v13 )
      {
        v10 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                  v4,
                                                  UFG::CharacterPhysicsComponent::_TypeUID);
        goto LABEL_11;
      }
    }
    v10 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v12, v11);
  }
LABEL_11:
  v14 = UFG::CharacterPhysicsComponent::GetRadius(v10, CP_WALK);
  parameters.m_fAIAvoidanceRadius = v14 + 0.059999999;
  parameters.m_fAIRadius = v14 + 0.050000001;
  UFG::NavComponent::SetPathingModule<UFG::NavModulePathing>((UFG::NavComponent *)&v5->vfptr);
  UFG::NavAvoidanceManager::SetLocalModuleFor((SSDivert *)UFG::NavAvoidanceManager::mspAvoidanceManager);
  UFG::NavComponent::SetControllerModule<UFG::NavModuleControllerPedestrian>((UFG::NavComponent *)&v5->vfptr);
  UFG::NavComponent::InitWithParams((UFG::NavComponent *)&v5->vfptr, &parameters);
}

// File Line: 58
// RVA: 0x37ED80
UFG::SimComponent *__fastcall UFG::GameNavComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rdi
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x110ui64, "NavComponent", 0i64, 1u);
  v5 = (UFG::SimComponent *)v4;
  if ( v4 )
  {
    UFG::NavComponent::NavComponent((UFG::NavComponent *)v4, v2->m_NameUID);
    v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GameNavComponent::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, v2->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return v5;
}

// File Line: 65
// RVA: 0x398020
void __fastcall UFG::GameNavComponent::UpdatePostStreaming(UFG::GameNavComponent *this, float dt)
{
  UFG::GameNavComponent *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rax
  unsigned __int16 v5; // dx

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[6].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HealthComponent::_TypeUID);
      }
    }
    else
    {
      v4 = v3->m_Components.p[6].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  if ( BYTE4(v4[1].m_BoundComponentHandles.mNode.mPrev) )
    ((void (*)(void))v2->m_pNavModuleLocal->vfptr->Shutdown)();
  UFG::NavComponent::UpdatePostStreaming((UFG::NavComponent *)&v2->vfptr, dt);
}

