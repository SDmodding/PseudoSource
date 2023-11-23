// File Line: 224
// RVA: 0x154DBE0
__int64 UFG::_anonymous_namespace_::_dynamic_initializer_for__TransformNodeComponent_name_id_def__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("xform.root", 0xFFFFFFFF);
  UFG::`anonymous namespace::TransformNodeComponent_name_id_def = result;
  return result;
}

// File Line: 230
// RVA: 0x57FD40
UFG::SimComponent *__fastcall UFG::CompositeDrawableComponent_PropertiesOnActivate(
        UFG::SceneObjectProperties *sceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *v8; // rax
  UFG::SimComponent *v9; // rdi
  char *v10; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::SimComponent *v13; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v16; // ebx
  UFG::SimObjectModifier v17; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_ModelAsset::sPropertyName,
         DEPTH_RECURSE);
  if ( v5 && UFG::qPropertySet::GetMemImagePtr(v5) )
    return 0i64;
  mpConstProperties = sceneObject->mpWritableProperties;
  if ( !mpConstProperties )
    mpConstProperties = sceneObject->mpConstProperties;
  v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpConstProperties,
         (UFG::qArray<unsigned long,0> *)&component_CompositeDrawable::sPropertyName,
         DEPTH_RECURSE);
  v9 = 0i64;
  v10 = v8 ? UFG::qPropertySet::GetMemImagePtr(v8) : 0i64;
  if ( !required && !v10 )
    return 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v12 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x5E0ui64, "CompositeDrawableComponent", 0i64, 1u);
  if ( v12 )
  {
    UFG::CompositeDrawableComponent::CompositeDrawableComponent((UFG::CompositeDrawableComponent *)v12);
    v9 = v13;
  }
  m_pSimObject = sceneObject->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v16 = 14;
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v16 = 9;
  }
  else
  {
    v16 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v17, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v17, v9, v16);
  UFG::SimObjectModifier::Close(&v17);
  UFG::SimObjectModifier::~SimObjectModifier(&v17);
  return v9;
}

// File Line: 258
// RVA: 0x58D0D0
UFG::TransformNodeComponent *__fastcall UFG::TransformNodeComponent_PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj,
        UFG::qMatrix44 *pWorldMatrix,
        UFG::TransformNodeComponent *parentTransform)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::TransformNodeComponent *v8; // rax
  UFG::TransformNodeComponent *v9; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v12; // ebx
  UFG::qMemoryPool *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::TransformNodeComponent *v16; // rax
  UFG::TransformNodeComponent *v17; // rdi
  UFG::SimObject *v18; // rdx
  __int16 v19; // cx
  unsigned int v20; // ebx
  UFG::SimObjectModifier v21; // [rsp+38h] [rbp-40h] BYREF

  if ( pWorldMatrix )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v7 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
    if ( v7 )
    {
      UFG::TransformNodeComponent::TransformNodeComponent(
        (UFG::TransformNodeComponent *)v7,
        UFG::`anonymous namespace::TransformNodeComponent_name_id_def,
        0i64,
        0);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    m_pSimObject = pSceneObj->m_pSimObject;
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 )
    {
      v12 = 2;
    }
    else
    {
      v12 = -1;
      if ( (m_Flags & 0x1000) != 0 )
        v12 = 1;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v21, m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v21, v9, v12);
    UFG::SimObjectModifier::Close(&v21);
    UFG::SimObjectModifier::~SimObjectModifier(&v21);
    UFG::TransformNodeComponent::PropertiesLoadWithMatrix(v9, pSceneObj, pWorldMatrix);
    return v9;
  }
  else if ( PropertyUtils::HasComponentPropertySet(
              pSceneObj,
              (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentTransformNode) )
  {
    v14 = UFG::GetSimulationMemoryPool();
    v15 = UFG::qMemoryPool::Allocate(v14, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
    if ( v15 )
    {
      UFG::TransformNodeComponent::TransformNodeComponent(
        (UFG::TransformNodeComponent *)v15,
        UFG::`anonymous namespace::TransformNodeComponent_name_id_def,
        0i64,
        0);
      v17 = v16;
    }
    else
    {
      v17 = 0i64;
    }
    v18 = pSceneObj->m_pSimObject;
    v19 = v18->m_Flags;
    if ( (v19 & 0x4000) != 0 )
    {
      v20 = 2;
    }
    else if ( v19 >= 0 )
    {
      if ( (v19 & 0x2000) != 0 )
      {
        v20 = 2;
      }
      else
      {
        v20 = -1;
        if ( (v19 & 0x1000) != 0 )
          v20 = 1;
      }
    }
    else
    {
      v20 = 2;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v21, v18, 1);
    UFG::SimObjectModifier::AttachComponent(&v21, v17, v20);
    UFG::SimObjectModifier::Close(&v21);
    UFG::SimObjectModifier::~SimObjectModifier(&v21);
    UFG::TransformNodeComponent::PropertiesLoadWithMatrix(v17, pSceneObj, 0i64);
    if ( parentTransform )
      UFG::TransformNodeComponent::SetParent(v17, parentTransform, eInheritXform_Full);
    return v17;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 293
// RVA: 0x588860
void __fastcall UFG::ComponentFactory::PostComponentFactory(UFG::SimObject *simObject)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rbx

  m_pSceneObj = simObject->m_pSceneObj;
  UFG::TSActorComponent::PropertiesOnActivateNew(m_pSceneObj, 0);
  if ( UFG::AIOutlineComponent::HasComponent(m_pSceneObj) )
    UFG::AIOutlineComponent::PropertiesOnActivate(m_pSceneObj);
  UFG::SimObjectPropertiesComponent::PropertiesOnActivateNew(m_pSceneObj, 0);
  if ( PropertyUtils::HasComponentPropertySet(
         m_pSceneObj,
         (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentActionTree) )
  {
    UFG::ActionTreeComponent::PropertiesOnActivate(m_pSceneObj);
  }
  if ( UFG::PropInteractComponent::HasComponent(m_pSceneObj) )
    UFG::PropInteractComponent::PropertiesOnActivate(m_pSceneObj);
  if ( UFG::DoorComponent::HasComponent(m_pSceneObj) )
    UFG::DoorComponent::PropertiesOnActivate(m_pSceneObj);
  if ( UFG::RadarComponent::HasComponent(m_pSceneObj) )
    UFG::RadarComponent::PropertiesOnActivate(m_pSceneObj);
}

// File Line: 314
// RVA: 0x1552320
__int64 UFG::_dynamic_initializer_for__gPlayerNames__()
{
  unsigned int v0; // eax
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax

  v0 = UFG::qStringHash32("PlayerOne_Havok", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol(&UFG::gPlayerNames, v0);
  v1 = UFG::qStringHash32("PlayerTwo_Havok", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol(&stru_14242E38C, v1);
  v2 = UFG::qStringHash32("PlayerThree_Havok", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol(&stru_14242E390, v2);
  v3 = UFG::qStringHash32("PlayerFour_Havok", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol(&stru_14242E394, v3);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gPlayerNames__);
}

// File Line: 323
// RVA: 0x57F8F0
void __fastcall UFG::ComponentFactory_PropertiesOnActivateCharacter(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v3; // rax
  component_CharacterAnimation *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // rsi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v11; // edi
  bool v12; // di
  unsigned int m_NameUID; // eax
  UFG::SimObjectCharacter *v14; // rbx
  __int64 v15; // rcx
  __int64 *v16; // rax
  __int64 mPrev; // rax
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::SimObjectModifier v19; // [rsp+38h] [rbp-30h] BYREF

  UFG::TSActorComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::SimObjectCharacterPropertiesComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::SimObjectSignalMemoryComponent::PropertiesOnActivateNew(pSceneObj, 1);
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v3 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_CharacterAnimation::sPropertyName,
         DEPTH_RECURSE);
  if ( v3 )
  {
    MemImagePtr = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v3);
    if ( MemImagePtr )
    {
      SimulationMemoryPool = UFG::GetSimulationMemoryPool();
      v6 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
      if ( v6 )
      {
        UFG::CharacterAnimationComponent::CharacterAnimationComponent(
          (UFG::CharacterAnimationComponent *)v6,
          pSceneObj,
          MemImagePtr);
        v8 = v7;
      }
      else
      {
        v8 = 0i64;
      }
      m_pSimObject = pSceneObj->m_pSimObject;
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        v11 = 9;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          v11 = 8;
        else
          v11 = -1;
      }
      else
      {
        v11 = 9;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v19, m_pSimObject, 1);
      UFG::SimObjectModifier::AttachComponent(&v19, v8, v11);
      UFG::SimObjectModifier::Close(&v19);
      UFG::SimObjectModifier::~SimObjectModifier(&v19);
    }
  }
  UFG::CompositeDrawableComponent_PropertiesOnActivate(pSceneObj, 0);
  Render::FXSimComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::CharacterLookComponent::PropertiesOnActivateNew(pSceneObj, 0);
  UFG::DropShadowComponent::PropertiesOnActivateNew(pSceneObj, 0);
  UFG::MissionFailConditionComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::StreamedResourceComponent::PropertiesOnActivateNew(pSceneObj, 0);
  UFG::CharacterPhysicsComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::AIAwarenessComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::ActiveAIEntityComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::AICharacterControllerComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::GameNavComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::StimulusReceiverComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::WorldContextComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::AIScriptInterfaceComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::HealthComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::HitReactionComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::InteractableComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::InteractorComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::AnimationLODComponent::PropertiesOnActivateNew(pSceneObj, 1);
  if ( PropertyUtils::HasComponentPropertySet(
         pSceneObj,
         (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentActionTree) )
  {
    UFG::ActionTreeComponent::PropertiesOnActivate(pSceneObj);
  }
  if ( gPrototype_UseBehaviourController )
    UFG::BehaviourControllerComponent::PropertiesOnActivateNew(pSceneObj, 1);
  else
    UFG::AIActionTreeComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::ActionTreeResourcesComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::FacialActionTreeComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::GetInFormationComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::PedFormationManagerComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::GetInPedFormationComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::HasAttackRequestComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::CharacterSubjectComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::CharacterEffectsComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::InventoryComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::ActorAudioComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::DialogueAnimationComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::InterestPointUserComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::RagdollComponent::PropertiesOnActivateNew(pSceneObj, 0);
  UFG::SensorComponent::PropertiesOnActivateNew(pSceneObj, 0);
  UFG::FormationManagerComponent::PropertiesOnActivateNew(pSceneObj, 0);
  if ( UFG::AttackRightsComponent::HasComponent(pSceneObj) )
    UFG::AttackRightsComponent::PropertiesOnActivate(pSceneObj);
  if ( UFG::FaceActionComponent::HasComponent(pSceneObj) )
    UFG::FaceActionComponent::PropertiesOnActivate(pSceneObj);
  if ( UFG::CopUnitComponent::HasComponent(pSceneObj) )
    UFG::CopUnitComponent::PropertiesOnActivate(pSceneObj);
  if ( UFG::AICoverComponent::HasComponent(pSceneObj) )
    UFG::AICoverComponent::PropertiesOnActivate(pSceneObj);
  if ( UFG::StoreBlipComponent::HasComponent(pSceneObj) )
    UFG::StoreBlipComponent::PropertiesOnActivate(pSceneObj);
  v12 = 0;
  m_NameUID = pSceneObj->m_NameUID;
  if ( m_NameUID == UFG::gPlayerNames.mUID
    || m_NameUID == stru_14242E38C.mUID
    || m_NameUID == stru_14242E390.mUID
    || m_NameUID == stru_14242E394.mUID )
  {
    if ( UFG::PlayerCoverComponent::HasComponent(pSceneObj) )
      UFG::PlayerCoverComponent::PropertiesOnActivate(pSceneObj);
    UFG::FaceMeterComponent::PropertiesOnActivate(pSceneObj);
    UFG::VehicleOwnershipComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::TargetingSystemPedPlayerComponent::HasComponent(pSceneObj) )
      UFG::TargetingSystemPedPlayerComponent::PropertiesOnActivate(pSceneObj);
    UFG::AimingPlayerComponent::PropertiesOnActivate(pSceneObj);
    v12 = pSceneObj->m_NameUID == UFG::gPlayerNames.mUID;
  }
  UFG::TargetingSystemPedNPCCombatantComponent::PropertiesOnActivate(pSceneObj);
  UFG::AimingNPCComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::UELComponent::PropertiesOnActivate(pSceneObj);
  if ( v12 )
  {
    v14 = (UFG::SimObjectCharacter *)pSceneObj->m_pSimObject;
    if ( LocalPlayer )
    {
      v15 = qword_14235C478;
      v16 = (__int64 *)qword_14235C480;
      *(_QWORD *)(qword_14235C478 + 8) = qword_14235C480;
      *v16 = v15;
      qword_14235C478 = (__int64)&qword_14235C478;
      qword_14235C480 = (__int64)&qword_14235C478;
    }
    LocalPlayer = v14;
    if ( v14 )
    {
      mPrev = (__int64)v14->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      *(_QWORD *)(mPrev + 8) = &qword_14235C478;
      qword_14235C478 = mPrev;
      qword_14235C480 = (__int64)&v14->m_SafePointerList;
      v14->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&qword_14235C478;
    }
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
    {
      if ( mCurrentCamera->m_pSimObject )
        UFG::ResetCameraObjects(v14);
    }
  }
}era = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
    {
      if ( mCurrentCamera->m_pSimObject )

// File Line: 448
// RVA: 0x588E20
void __fastcall UFG::ComponentFactory::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj,
        UFG::qMatrix44 *pWorldMatrix,
        UFG::qSymbol *_objectType,
        UFG::TransformNodeComponent *parentTransform)
{
  UFG::SceneObjectProperties *m_pSceneObj; // r14
  unsigned int mUID; // ebx
  UFG::qPropertySet *v8; // rax
  unsigned int v9; // esi
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v11; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::SceneObjectProperties *v14; // rax
  UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *mPrev; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *v17; // rax
  component_CharacterAnimation *MemImagePtr; // rbx
  UFG::qMemoryPool *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::SceneObjectProperties *v21; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  UFG::qPropertySet *v24; // rcx
  UFG::qPropertySet *v25; // rax
  component_CharacterAnimation *v26; // rbx
  UFG::qMemoryPool *v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::SceneObjectProperties *v29; // rax
  UFG::SimObject *v30; // rdx
  __int16 v31; // cx
  UFG::qPropertySet *v32; // rcx
  UFG::qPropertySet *v33; // rax
  component_CharacterAnimation *v34; // rbx
  UFG::qMemoryPool *v35; // rax
  UFG::allocator::free_link *v36; // rax
  UFG::SceneObjectProperties *v37; // rax
  UFG::SimObject *v38; // rdx
  __int16 v39; // cx
  UFG::allocator::free_link *v40; // rax
  UFG::SceneObjectProperties *v41; // rax
  hkgpIndexedMeshDefinitions::Edge *v42; // rdx
  UFG::qPropertySet *v43; // rcx
  UFG::qPropertySet *v44; // rax
  component_CameraAnimation *v45; // rbx
  UFG::qMemoryPool *v46; // rax
  UFG::allocator::free_link *v47; // rax
  UFG::SimComponent *v48; // rax
  UFG::SimComponent *v49; // rbx
  UFG::qPropertySet *v50; // rcx
  UFG::qPropertySet *v51; // rax
  component_CharacterAnimation *v52; // rbx
  UFG::qMemoryPool *v53; // rax
  UFG::allocator::free_link *v54; // rax
  UFG::SimComponent *v55; // rax
  UFG::SimComponent *v56; // rbx
  UFG::SimObject *v57; // rdx
  __int16 v58; // cx
  UFG::qPropertySet *v59; // rcx
  UFG::qPropertySet *v60; // rax
  char *v61; // rsi
  UFG::qMemoryPool *v62; // rax
  UFG::allocator::free_link *v63; // r12
  UFG::SimObject *v64; // rbx
  UFG::qSymbol *v65; // rax
  UFG::SpawnPoint *v66; // rax
  UFG::SpawnPoint *v67; // rbx
  UFG::SimObject *v68; // rax
  UFG::SceneObjectProperties *ChildAsSceneObject; // rax
  UFG::qPropertySet *v70; // rcx
  UFG::qWiseSymbol result; // [rsp+34h] [rbp-2Ch] BYREF
  __int64 v72; // [rsp+38h] [rbp-28h]
  UFG::SimObjectModifier v73; // [rsp+40h] [rbp-20h] BYREF
  UFG::allocator::free_link *pPriority; // [rsp+A0h] [rbp+40h] BYREF

  v72 = -2i64;
  m_pSceneObj = 0i64;
  UFG::TransformNodeComponent_PropertiesOnActivate(pSceneObj, pWorldMatrix, parentTransform);
  mUID = _objectType->mUID;
  if ( mUID == UFG::gNullQSymbol.mUID )
  {
    v8 = PropertyUtils::Get<UFG::qSymbol>(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_ObjectType);
    if ( v8 )
      mUID = v8->mFlags;
  }
  v9 = -1;
  if ( mUID == -1 )
    goto LABEL_331;
  if ( mUID == qSymbol_Marker.mUID )
  {
    UFG::Marker::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_NISScriptSystem.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::NISScriptSystemComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_MeleeScriptSystem.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::MeleeScriptSystemComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_ModelAsset.mUID )
  {
    UFG::ModelAssetComponent_PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_DynamicLight.mUID )
  {
    Render::DynamicLightComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_IrradianceVolume.mUID )
  {
    Render::IrradianceVolumeComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_MarkerRaceStartingGrid.mUID )
  {
    UFG::Marker::PropertiesOnActivate(pSceneObj);
    UFG::GameSubject::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_SpawnRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(pSceneObj) )
      UFG::RegionComponent::PropertiesOnActivate(pSceneObj);
    UFG::SpawnRegion::PropertiesOnActivateNew(pSceneObj, 1);
    return;
  }
  if ( mUID == qSymbol_SpawnPoint.mUID )
  {
    UFG::SpawnPoint::PropertiesOnActivateNew(pSceneObj, 1);
    return;
  }
  if ( mUID == qSymbol_InterestPoint.mUID )
  {
    UFG::InterestPoint::PropertiesOnActivate(pSceneObj);
    UFG::InteractableComponent::PropertiesOnActivateNew(pSceneObj, 0);
    return;
  }
  if ( mUID == qSymbol_Character.mUID )
  {
    UFG::ComponentFactory_PropertiesOnActivateCharacter(pSceneObj);
    UFG::TriadWarsComponent::PropertiesOnActivateNew(pSceneObj, 0);
    return;
  }
  if ( mUID == qSymbol_Vehicle.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::AIOutlineComponent::PropertiesOnActivate(pSceneObj);
    UFG::SimObjectVehiclePropertiesComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::VehicleAudioComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::VehiclesBlipComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::VehicleOccupantComponent::PropertiesOnActivate(pSceneObj);
    UFG::VehicleSubjectComponent::PropertiesOnActivate(pSceneObj);
    UFG::AIScriptInterfaceComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::MissionFailConditionComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::CharacterAnimationComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::StreamedResourceComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::CompositeDrawableComponent_PropertiesOnActivate(pSceneObj, 1);
    Render::FXSimComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::VehicleEffectsComponent::PropertiesOnActivateNew(pSceneObj, 1);
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    v11 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&component_CompositeDrawable::sPropertyName,
            DEPTH_RECURSE);
    if ( v11 )
      UFG::qPropertySet::GetMemImagePtr(v11);
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v13 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "VehicleLookComponent", 0i64, 1u);
    pPriority = v13;
    if ( v13 )
    {
      UFG::VehicleLookComponent::VehicleLookComponent((UFG::VehicleLookComponent *)v13);
      m_pSceneObj = v14;
    }
    mPrev = UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&m_pSceneObj->mpOwner;
    m_pSceneObj->mpOwner.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)mPrev;
    m_pSceneObj->mpOwner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&UFG::CompositeLookComponent::s_CompositeLookComponentList;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&m_pSceneObj->mpOwner;
    UFG::SimObjectModifier::SimObjectModifier(&v73, pSceneObj->m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v73, m_pSceneObj, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v73);
    UFG::SimObjectModifier::~SimObjectModifier(&v73);
    UFG::DropShadowComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::ActionTreeComponent::PropertiesOnActivate(pSceneObj);
    UFG::HealthComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::HitReactionComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::PropInteractComponent::PropertiesOnActivate(pSceneObj);
    UFG::TargetingSystemVehicleComponent::PropertiesOnActivate(pSceneObj);
    UFG::StimulusReceiverComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::InteractableComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::AnimationLODComponent::PropertiesOnActivateNew(pSceneObj, 1);
    if ( UFG::CopUnitComponent::HasComponent(pSceneObj) )
      UFG::CopUnitComponent::PropertiesOnActivate(pSceneObj);
    if ( !UFG::CarPhysicsMoverComponent::PropertiesOnActivateNew(pSceneObj, 0)
      && !UFG::BikePhysicsMoverComponent::PropertiesOnActivateNew(pSceneObj, 0) )
    {
      UFG::BoatPhysicsMoverComponent::PropertiesOnActivateNew(pSceneObj, 0);
    }
    UFG::SensorComponent::PropertiesOnActivateNew(pSceneObj, 0);
LABEL_327:
    if ( UFG::UELComponent::HasComponent(pSceneObj) )
      UFG::UELComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_TriggerRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(pSceneObj) )
      UFG::RegionComponent::PropertiesOnActivate(pSceneObj);
    UFG::TriggerRegion::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_StartRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(pSceneObj) )
      UFG::RegionComponent::PropertiesOnActivate(pSceneObj);
    UFG::StartRegion::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_Prop.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::SimObjectPropertiesComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::StimulusReceiverComponent::PropertiesOnActivateNew(pSceneObj, 0);
    mpConstProperties = pSceneObj->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = pSceneObj->mpConstProperties;
    v17 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            mpConstProperties,
            (UFG::qArray<unsigned long,0> *)&component_CharacterAnimation::sPropertyName,
            DEPTH_RECURSE);
    if ( v17 )
    {
      MemImagePtr = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v17);
      if ( MemImagePtr )
      {
        v19 = UFG::GetSimulationMemoryPool();
        v20 = UFG::qMemoryPool::Allocate(v19, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
        pPriority = v20;
        if ( v20 )
        {
          UFG::CharacterAnimationComponent::CharacterAnimationComponent(
            (UFG::CharacterAnimationComponent *)v20,
            pSceneObj,
            MemImagePtr);
          m_pSceneObj = v21;
        }
        m_pSimObject = pSceneObj->m_pSimObject;
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          v9 = 9;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
            v9 = 8;
        }
        else
        {
          v9 = 9;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v73, m_pSimObject, 1);
        UFG::SimObjectModifier::AttachComponent(&v73, m_pSceneObj, v9);
        UFG::SimObjectModifier::Close(&v73);
        UFG::SimObjectModifier::~SimObjectModifier(&v73);
      }
    }
    UFG::CompositeDrawableComponent_PropertiesOnActivate(pSceneObj, 0);
    Render::FXSimComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::CompositeLookComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::DropShadowComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::StreamedResourceComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentActionTree) )
    {
      UFG::ActionTreeComponent::PropertiesOnActivate(pSceneObj);
    }
    if ( UFG::PropInteractComponent::HasComponent(pSceneObj) )
      UFG::PropInteractComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::RigidBodyComponent::HasComponent(pSceneObj) )
      UFG::RigidBodyComponent::PropertiesOnActivate(pSceneObj);
    UFG::InventoryItemComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::CollectibleComponent::HasComponent(pSceneObj) )
      UFG::CollectibleComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::DoorComponent::HasComponent(pSceneObj) )
      UFG::DoorComponent::PropertiesOnActivate(pSceneObj);
    if ( PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentPowerManagement) )
    {
      UFG::PowerManagementComponent::PropertiesOnActivate(pSceneObj);
    }
    if ( UFG::RadarComponent::HasComponent(pSceneObj) )
      UFG::RadarComponent::PropertiesOnActivate(pSceneObj);
    if ( PropertyUtils::PropertyExists(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_componentPOI) )
      UFG::InterestPoint::PropertiesOnActivate(pSceneObj);
    if ( UFG::TargetingSystemPedNPCAmbientComponent::HasComponent(pSceneObj) )
      UFG::TargetingSystemPedNPCAmbientComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::TargetingSystemItemComponent::HasComponent(pSceneObj) )
      UFG::TargetingSystemItemComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::AIOutlineComponent::HasComponent(pSceneObj) )
      UFG::AIOutlineComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_AIOutlineRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(pSceneObj) )
      UFG::RegionComponent::PropertiesOnActivate(pSceneObj);
    UFG::AIOutlineComponent::PropertiesOnActivate(pSceneObj);
    UFG::AIOutlineRegion::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_BoostRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(pSceneObj) )
      UFG::RegionComponent::PropertiesOnActivate(pSceneObj);
    UFG::BoostRegion::PropertiesOnActivate(pSceneObj);
    if ( UFG::CollectibleComponent::HasComponent(pSceneObj) )
      UFG::CollectibleComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_CombatRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(pSceneObj) )
      UFG::RegionComponent::PropertiesOnActivate(pSceneObj);
    UFG::CombatRegion::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_Door.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(pSceneObj, 1);
    if ( UFG::AIOutlineComponent::HasComponent(pSceneObj) )
      UFG::AIOutlineComponent::PropertiesOnActivate(pSceneObj);
    UFG::SimObjectPropertiesComponent::PropertiesOnActivateNew(pSceneObj, 1);
    v24 = pSceneObj->mpWritableProperties;
    if ( !v24 )
      v24 = pSceneObj->mpConstProperties;
    v25 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v24,
            (UFG::qArray<unsigned long,0> *)&component_CharacterAnimation::sPropertyName,
            DEPTH_RECURSE);
    if ( v25 )
    {
      v26 = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v25);
      if ( v26 )
      {
        v27 = UFG::GetSimulationMemoryPool();
        v28 = UFG::qMemoryPool::Allocate(v27, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
        pPriority = v28;
        if ( v28 )
        {
          UFG::CharacterAnimationComponent::CharacterAnimationComponent(
            (UFG::CharacterAnimationComponent *)v28,
            pSceneObj,
            v26);
          m_pSceneObj = v29;
        }
        v30 = pSceneObj->m_pSimObject;
        v31 = v30->m_Flags;
        if ( (v31 & 0x4000) != 0 )
        {
          v9 = 9;
        }
        else if ( v31 >= 0 )
        {
          if ( (v31 & 0x2000) != 0 )
            v9 = 8;
        }
        else
        {
          v9 = 9;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v73, v30, 1);
        UFG::SimObjectModifier::AttachComponent(&v73, m_pSceneObj, v9);
        UFG::SimObjectModifier::Close(&v73);
        UFG::SimObjectModifier::~SimObjectModifier(&v73);
      }
    }
    UFG::CompositeDrawableComponent_PropertiesOnActivate(pSceneObj, 0);
    Render::FXSimComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::ModelAssetComponent_PropertiesOnActivate(pSceneObj);
    UFG::CompositeLookComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentActionTree) )
    {
      UFG::ActionTreeComponent::PropertiesOnActivate(pSceneObj);
    }
    if ( UFG::PropInteractComponent::HasComponent(pSceneObj) )
      UFG::PropInteractComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::DoorComponent::HasComponent(pSceneObj) )
      UFG::DoorComponent::PropertiesOnActivate(pSceneObj);
    if ( PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentPowerManagement) )
    {
      UFG::PowerManagementComponent::PropertiesOnActivate(pSceneObj);
    }
LABEL_123:
    if ( UFG::RadarComponent::HasComponent(pSceneObj) )
      UFG::RadarComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_Weapon.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::SimObjectWeaponPropertiesComponent::PropertiesOnActivateNew(pSceneObj, 1);
    if ( UFG::TargetingSystemItemComponent::HasComponent(pSceneObj) )
      UFG::TargetingSystemItemComponent::PropertiesOnActivate(pSceneObj);
    UFG::StreamedResourceComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::InventoryItemComponent::PropertiesOnActivateNew(pSceneObj, 0);
    v32 = pSceneObj->mpWritableProperties;
    if ( !v32 )
      v32 = pSceneObj->mpConstProperties;
    v33 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v32,
            (UFG::qArray<unsigned long,0> *)&component_CharacterAnimation::sPropertyName,
            DEPTH_RECURSE);
    if ( v33 )
    {
      v34 = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v33);
      if ( v34 )
      {
        v35 = UFG::GetSimulationMemoryPool();
        v36 = UFG::qMemoryPool::Allocate(v35, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
        pPriority = v36;
        if ( v36 )
        {
          UFG::CharacterAnimationComponent::CharacterAnimationComponent(
            (UFG::CharacterAnimationComponent *)v36,
            pSceneObj,
            v34);
          m_pSceneObj = v37;
        }
        v38 = pSceneObj->m_pSimObject;
        v39 = v38->m_Flags;
        if ( (v39 & 0x4000) != 0 )
        {
          v9 = 9;
        }
        else if ( v39 >= 0 )
        {
          if ( (v39 & 0x2000) != 0 )
            v9 = 8;
        }
        else
        {
          v9 = 9;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v73, v38, 1);
        UFG::SimObjectModifier::AttachComponent(&v73, m_pSceneObj, v9);
        UFG::SimObjectModifier::Close(&v73);
        UFG::SimObjectModifier::~SimObjectModifier(&v73);
      }
    }
    UFG::CompositeDrawableComponent_PropertiesOnActivate(pSceneObj, 0);
    Render::FXSimComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::CompositeLookComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::RadarComponent::HasComponent(pSceneObj) )
      UFG::RadarComponent::PropertiesOnActivate(pSceneObj);
    if ( PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentActionTree) )
    {
      UFG::ActionTreeComponent::PropertiesOnActivate(pSceneObj);
    }
    UFG::InteractableComponent::PropertiesOnActivateNew(pSceneObj, 1);
    if ( UFG::GunComponent::HasComponent(pSceneObj) )
      UFG::GunComponent::PropertiesOnActivate(pSceneObj);
    goto LABEL_327;
  }
  if ( mUID == qSymbol_MarkerProgressionTrigger.mUID )
  {
    UFG::Marker::PropertiesOnActivate(pSceneObj);
    UFG::ProgressionTriggerComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_SpawnPointProgressionTrigger.mUID )
  {
    UFG::SpawnPoint::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::ProgressionTriggerComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_Camera.mUID )
  {
    UFG::CameraAnimationComponent::PropertiesOnActivateNew(pSceneObj, 1);
    UFG::AnimatedCameraComponent::PropertiesOnActivate(pSceneObj);
    UFG::ProgressionCameraComponent::PropertiesOnActivate(pSceneObj);
    UFG::FollowCameraComponent::PropertiesOnActivate(pSceneObj);
    UFG::ChaseCameraComponent::PropertiesOnActivate(pSceneObj);
    UFG::ScriptCameraComponent::PropertiesOnActivate(pSceneObj);
    UFG::TurfCameraComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_Director.mUID )
  {
    UFG::Director::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_AudioTriggerRegion.mUID )
  {
    UFG::RegionComponent::PropertiesOnActivate(pSceneObj);
    UFG::AudioTriggerRegion::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_AudioEmitterMarker.mUID )
  {
    UFG::AudioEmitterMarker::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_CopRoadBlock.mUID )
  {
    UFG::CopRoadBlock::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_WeaponSpawner.mUID )
  {
    UFG::CollectibleWeaponSpawnerComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_HidingSpot.mUID )
  {
    UFG::CollectibleHidingSpotComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_Collectible.mUID )
  {
    if ( UFG::CollectibleWeaponSpawnerComponent::HasComponent(pSceneObj) )
      UFG::CollectibleWeaponSpawnerComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::CollectibleHidingSpotComponent::HasComponent(pSceneObj) )
      UFG::CollectibleHidingSpotComponent::PropertiesOnActivate(pSceneObj);
    UFG::CollectibleComponent::PropertiesOnActivate(pSceneObj);
    goto LABEL_123;
  }
  if ( mUID == qSymbol_TrafficRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(pSceneObj) )
      UFG::RegionComponent::PropertiesOnActivate(pSceneObj);
    UFG::TrafficRegion::PropertiesOnActivateNew(pSceneObj, 1);
    return;
  }
  if ( mUID == qSymbol_AIPathMarker.mUID )
  {
    if ( UFG::AIMarker::HasComponent(pSceneObj) )
      UFG::AIMarker::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_ParkingSpot.mUID )
  {
    UFG::ParkingSpot::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_CameraMarker.mUID )
  {
    UFG::CameraMarker::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_Prefab.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::PrefabComponent::PropertiesOnActivate(pSceneObj);
    return;
  }
  if ( mUID == qSymbol_FXSimComponent.mUID )
  {
    Render::FXSimComponent::PropertiesOnActivateNew(pSceneObj, 1);
    return;
  }
  if ( mUID != qSymbol_Turf.mUID )
  {
LABEL_331:
    if ( UFG::Marker::HasComponent(pSceneObj) )
      UFG::Marker::PropertiesOnActivate(pSceneObj);
    if ( UFG::RegionComponent::HasComponent(pSceneObj) )
      UFG::RegionComponent::PropertiesOnActivate(pSceneObj);
    if ( PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentActionTree) )
    {
      UFG::ActionTreeComponent::PropertiesOnActivate(pSceneObj);
    }
    if ( UFG::CollectibleWeaponSpawnerComponent::HasComponent(pSceneObj) )
      UFG::CollectibleWeaponSpawnerComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::CollectibleHidingSpotComponent::HasComponent(pSceneObj) )
      UFG::CollectibleHidingSpotComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::CollectibleComponent::HasComponent(pSceneObj) )
      UFG::CollectibleComponent::PropertiesOnActivate(pSceneObj);
    if ( gPrototype_UseBehaviourController )
      UFG::BehaviourControllerComponent::PropertiesOnActivateNew(pSceneObj, 0);
    else
      UFG::AIActionTreeComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::AICharacterControllerComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::AICoverComponent::HasComponent(pSceneObj) )
      UFG::AICoverComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::AIOutlineComponent::HasComponent(pSceneObj) )
      UFG::AIOutlineComponent::PropertiesOnActivate(pSceneObj);
    UFG::AIScriptInterfaceComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::ProgressionCameraComponent::HasComponent(pSceneObj) )
      UFG::AnimatedCameraComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::ProgressionCameraComponent::HasComponent(pSceneObj) )
      UFG::ProgressionCameraComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::AttackRightsComponent::HasComponent(pSceneObj) )
      UFG::AttackRightsComponent::PropertiesOnActivate(pSceneObj);
    if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
           (hkgpIndexedMesh::EdgeBarrier *)pSceneObj,
           v42) )
    {
      UFG::AudioEmitterMarker::PropertiesOnActivate(pSceneObj);
    }
    if ( UFG::AudioTriggerRegion::HasComponent(pSceneObj) )
      UFG::AudioTriggerRegion::PropertiesOnActivate(pSceneObj);
    UFG::BikePhysicsMoverComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::BoatPhysicsMoverComponent::PropertiesOnActivateNew(pSceneObj, 0);
    v43 = pSceneObj->mpWritableProperties;
    if ( !v43 )
      v43 = pSceneObj->mpConstProperties;
    v44 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v43,
            (UFG::qArray<unsigned long,0> *)&component_CameraAnimation::sPropertyName,
            DEPTH_RECURSE);
    if ( v44 )
    {
      v45 = (component_CameraAnimation *)UFG::qPropertySet::GetMemImagePtr(v44);
      if ( v45 )
      {
        v46 = UFG::GetSimulationMemoryPool();
        v47 = UFG::qMemoryPool::Allocate(v46, 0xD8ui64, "CameraAnimationComponent", 0i64, 1u);
        pPriority = v47;
        if ( v47 )
        {
          UFG::CameraAnimationComponent::CameraAnimationComponent((UFG::CameraAnimationComponent *)v47, pSceneObj, v45);
          v49 = v48;
        }
        else
        {
          v49 = 0i64;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v73, pSceneObj->m_pSimObject, 1);
        UFG::SimObjectModifier::AttachComponent(&v73, v49, 0xFFFFFFFFi64);
        UFG::SimObjectModifier::Close(&v73);
        UFG::SimObjectModifier::~SimObjectModifier(&v73);
      }
    }
    UFG::CarPhysicsMoverComponent::PropertiesOnActivateNew(pSceneObj, 0);
    v50 = pSceneObj->mpWritableProperties;
    if ( !v50 )
      v50 = pSceneObj->mpConstProperties;
    v51 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v50,
            (UFG::qArray<unsigned long,0> *)&component_CharacterAnimation::sPropertyName,
            DEPTH_RECURSE);
    if ( v51 )
    {
      v52 = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v51);
      if ( v52 )
      {
        v53 = UFG::GetSimulationMemoryPool();
        v54 = UFG::qMemoryPool::Allocate(v53, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
        pPriority = v54;
        if ( v54 )
        {
          UFG::CharacterAnimationComponent::CharacterAnimationComponent(
            (UFG::CharacterAnimationComponent *)v54,
            pSceneObj,
            v52);
          v56 = v55;
        }
        else
        {
          v56 = 0i64;
        }
        v57 = pSceneObj->m_pSimObject;
        v58 = v57->m_Flags;
        if ( (v58 & 0x4000) != 0 )
        {
          v9 = 9;
        }
        else if ( v58 >= 0 )
        {
          if ( (v58 & 0x2000) != 0 )
            v9 = 8;
        }
        else
        {
          v9 = 9;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v73, v57, 1);
        UFG::SimObjectModifier::AttachComponent(&v73, v56, v9);
        UFG::SimObjectModifier::Close(&v73);
        UFG::SimObjectModifier::~SimObjectModifier(&v73);
      }
    }
    UFG::CharacterPhysicsComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::ChaseCameraComponent::HasComponent(pSceneObj) )
      UFG::ChaseCameraComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::CollectibleComponent::HasComponent(pSceneObj) )
      UFG::CollectibleComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::CombatRegion::HasComponent(pSceneObj) )
      UFG::CombatRegion::PropertiesOnActivate(pSceneObj);
    UFG::CompositeDrawableComponent_PropertiesOnActivate(pSceneObj, 0);
    Render::FXSimComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::CompositeLookComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::DropShadowComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::CopRoadBlock::HasComponent(pSceneObj) )
      UFG::CopRoadBlock::PropertiesOnActivate(pSceneObj);
    if ( UFG::CopUnitComponent::HasComponent(pSceneObj) )
      UFG::CopUnitComponent::PropertiesOnActivate(pSceneObj);
    if ( PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_componentCorona) )
    {
      UFG::Corona::PropertiesOnActivate(pSceneObj);
    }
    if ( UFG::DoorComponent::HasComponent(pSceneObj) )
      UFG::DoorComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::FaceActionComponent::HasComponent(pSceneObj) )
      UFG::FaceActionComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::FaceMeterComponent::HasComponent(pSceneObj) )
      UFG::FaceMeterComponent::PropertiesOnActivate(pSceneObj);
    UFG::FacialActionTreeComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::FollowCameraComponent::HasComponent(pSceneObj) )
      UFG::FollowCameraComponent::PropertiesOnActivate(pSceneObj);
    UFG::FormationManagerComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::GunComponent::HasComponent(pSceneObj) )
      UFG::GunComponent::PropertiesOnActivate(pSceneObj);
    UFG::HealthComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::HitReactionComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::HudComponent::HasComponent(pSceneObj) )
      UFG::HudComponent::PropertiesOnActivate(pSceneObj);
    UFG::InteractableComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( PropertyUtils::PropertyExists(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_componentPOI) )
      UFG::InterestPoint::PropertiesOnActivate(pSceneObj);
    UFG::InventoryComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::InventoryItemComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::MissionFailConditionComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::ParkingSpot::HasComponent(pSceneObj) )
      UFG::ParkingSpot::PropertiesOnActivate(pSceneObj);
    if ( UFG::PlayerCoverComponent::HasComponent(pSceneObj) )
      UFG::PlayerCoverComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::ProgressionTriggerComponent::HasComponent(pSceneObj) )
      UFG::ProgressionTriggerComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::PropInteractComponent::HasComponent(pSceneObj) )
      UFG::PropInteractComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::RadarComponent::HasComponent(pSceneObj) )
      UFG::RadarComponent::PropertiesOnActivate(pSceneObj);
    UFG::RagdollComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::RigidBodyComponent::HasComponent(pSceneObj) )
      UFG::RigidBodyComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::TurfCameraComponent::HasComponent(pSceneObj) )
      UFG::ScriptCameraComponent::PropertiesOnActivate(pSceneObj);
    UFG::SensorComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::SimObjectSignalMemoryComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::SimObjectPropertiesComponent::PropertiesOnActivateNew(pSceneObj, 0);
    v59 = pSceneObj->mpWritableProperties;
    if ( !v59 )
      v59 = pSceneObj->mpConstProperties;
    v60 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v59,
            (UFG::qArray<unsigned long,0> *)&component_SpawnPoint::sPropertyName,
            DEPTH_RECURSE);
    if ( v60 )
    {
      v61 = UFG::qPropertySet::GetMemImagePtr(v60);
      if ( v61 )
      {
        v62 = UFG::GetSimulationMemoryPool();
        v63 = UFG::qMemoryPool::Allocate(v62, 0xE0ui64, "SpawnPoint", 0i64, 1u);
        pPriority = v63;
        if ( v63 )
        {
          v64 = pSceneObj->m_pSimObject;
          v65 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, pSceneObj->m_NameUID);
          UFG::SpawnPoint::SpawnPoint((UFG::SpawnPoint *)v63, v65, v64);
          v67 = v66;
        }
        else
        {
          v67 = 0i64;
        }
        v67->mThugPoint = v61[1];
        if ( UFG::SpawnPoint::Initialize(v67, pSceneObj->m_pSimObject) )
        {
          LODWORD(pPriority) = 0;
          v68 = v67->m_pSimObject;
          if ( v68 )
            m_pSceneObj = v68->m_pSceneObj;
          ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject(m_pSceneObj, 0);
          if ( ChildAsSceneObject )
          {
            v70 = ChildAsSceneObject->mpWritableProperties;
            if ( !v70 )
              v70 = ChildAsSceneObject->mpConstProperties;
            UFG::SpawnInfoInterface::GetSpawnPriority(v70, (UFG::SpawnInfoInterface::SpawnPriority *)&pPriority);
          }
          if ( !((unsigned __int8)*v61 | ((int)pPriority >= 1)) )
            UFG::SpawnPoint::Spawn(v67, 0, 0);
        }
      }
    }
    UFG::SpawnRegion::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::StimulusReceiverComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::StoreBlipComponent::HasComponent(pSceneObj) )
      UFG::StoreBlipComponent::PropertiesOnActivate(pSceneObj);
    UFG::StreamedResourceComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::TargetingSystemCraneComponent::HasComponent(pSceneObj) )
      UFG::TargetingSystemCraneComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::TargetingSystemItemComponent::HasComponent(pSceneObj) )
      UFG::TargetingSystemItemComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::TargetingSystemPedPlayerComponent::HasComponent(pSceneObj) )
      UFG::TargetingSystemPedPlayerComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::TargetingSystemPedNPCAmbientComponent::HasComponent(pSceneObj) )
      UFG::TargetingSystemPedNPCAmbientComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::TargetingSystemPedNPCCombatantComponent::HasComponent(pSceneObj) )
      UFG::TargetingSystemPedNPCCombatantComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::TargetingSystemVehicleComponent::HasComponent(pSceneObj) )
      UFG::TargetingSystemVehicleComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::TriggerRegion::HasComponent(pSceneObj) )
      UFG::TriggerRegion::PropertiesOnActivate(pSceneObj);
    if ( UFG::TurfCameraComponent::HasComponent(pSceneObj) )
      UFG::TurfCameraComponent::PropertiesOnActivate(pSceneObj);
    UFG::TSActorComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::VehicleAudioComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::VehicleOccupantComponent::HasComponent(pSceneObj) )
      UFG::VehicleOccupantComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::VehicleOwnershipComponent::HasComponent(pSceneObj) )
      UFG::VehicleOwnershipComponent::PropertiesOnActivate(pSceneObj);
    UFG::VehicleEffectsComponent::PropertiesOnActivateNew(pSceneObj, 0);
    UFG::VehiclesBlipComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( UFG::VehicleSubjectComponent::HasComponent(pSceneObj) )
      UFG::VehicleSubjectComponent::PropertiesOnActivate(pSceneObj);
    UFG::WorldContextComponent::PropertiesOnActivateNew(pSceneObj, 0);
    if ( PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentPowerManagement) )
    {
      UFG::PowerManagementComponent::PropertiesOnActivate(pSceneObj);
    }
    if ( UFG::AimingPlayerComponent::HasComponent(pSceneObj) )
      UFG::AimingPlayerComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG::AIMarker::HasComponent(pSceneObj) )
      UFG::AIMarker::PropertiesOnActivate(pSceneObj);
    goto LABEL_327;
  }
  v40 = UFG::SimComponent::operator new(0x1A0ui64);
  pPriority = v40;
  if ( v40 )
  {
    UFG::TurfComponent::TurfComponent((UFG::TurfComponent *)v40, pSceneObj->m_NameUID);
    m_pSceneObj = v41;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v73, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v73, m_pSceneObj, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v73);
  UFG::SimObjectModifier::~SimObjectModifier(&v73);
}ong,0> *)&SimSymX_propset_componentPowerManagement) )
    {
      UFG::PowerManagementComponent::PropertiesOnActivate(pSceneObj);
    }
    if ( UFG::AimingPlayerComponent::HasComponent(pSceneObj) )
      UFG::AimingPlayerComponent::PropertiesOnActivate(pSceneObj);
    if ( UFG

