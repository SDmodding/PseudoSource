// File Line: 30
// RVA: 0x365B00
void __fastcall UFG::GameNavComponent::Init(UFG::GameNavComponent *this, UFG::SimObjectGame *pSimObject)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rdi
  char *v6; // rax
  char *v7; // rax
  int v8; // eax
  signed __int16 m_Flags; // cx
  UFG::CharacterPhysicsComponent *m_pComponent; // rax
  unsigned int v11; // edx
  UFG::SimObjectGame *v12; // rcx
  bool v13; // zf
  float Radius; // xmm0_4
  UFG::NavComponent::InitParameters parameters; // [rsp+20h] [rbp-18h] BYREF

  m_pSceneObj = pSimObject->m_pSceneObj;
  *(_WORD *)&parameters.m_bIsFreerunner = 257;
  parameters.m_fAIRadius = 0.5;
  parameters.m_fAIAvoidanceRadius = 0.5;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v6 = UFG::qPropertySet::Get<char const *>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&SimSym_AIEntityType,
         DEPTH_RECURSE);
  parameters.m_bIsFreerunner = strcmp(v6, "eAI_ENTITY_FREERUNNER") == 0;
  v7 = UFG::qPropertySet::Get<char const *>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&SimSym_AIAvoidanceType,
         DEPTH_RECURSE);
  v8 = strcmp(v7, "eAI_AVOIDANCE_NONE");
  m_Flags = pSimObject->m_Flags;
  parameters.m_bIsAvoidanceEnabled = v8 != 0;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterPhysicsComponent *)pSimObject->m_Components.p[27].m_pComponent;
  }
  else
  {
    if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
    {
      v11 = UFG::CharacterPhysicsComponent::_TypeUID;
      v12 = pSimObject;
    }
    else
    {
      v11 = UFG::CharacterPhysicsComponent::_TypeUID;
      v13 = (m_Flags & 0x1000) == 0;
      v12 = pSimObject;
      if ( v13 )
      {
        m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                           pSimObject,
                                                           UFG::CharacterPhysicsComponent::_TypeUID);
        goto LABEL_11;
      }
    }
    m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v12, v11);
  }
LABEL_11:
  Radius = UFG::CharacterPhysicsComponent::GetRadius(m_pComponent, CP_WALK);
  parameters.m_fAIAvoidanceRadius = Radius + 0.059999999;
  parameters.m_fAIRadius = Radius + 0.050000001;
  UFG::NavComponent::SetPathingModule<UFG::NavModulePathing>(this);
  UFG::NavAvoidanceManager::SetLocalModuleFor((SSDivert *)UFG::NavAvoidanceManager::mspAvoidanceManager);
  UFG::NavComponent::SetControllerModule<UFG::NavModuleControllerPedestrian>(this);
  UFG::NavComponent::InitWithParams(this, &parameters);
}

// File Line: 58
// RVA: 0x37ED80
UFG::SimComponent *__fastcall UFG::GameNavComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "NavComponent", 0i64, 1u);
  v5 = (UFG::SimComponent *)v4;
  if ( v4 )
  {
    UFG::NavComponent::NavComponent((UFG::NavComponent *)v4, pSceneObj->m_NameUID);
    v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GameNavComponent::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return v5;
}

// File Line: 65
// RVA: 0x398020
void __fastcall UFG::GameNavComponent::UpdatePostStreaming(UFG::GameNavComponent *this, float dt)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // dx

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::HealthComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::HealthComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( BYTE4(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) )
    this->m_pNavModuleLocal->UFG::NavComponent::vfptr->Shutdown(this->m_pNavModuleLocal);
  UFG::NavComponent::UpdatePostStreaming(this, dt);
}

