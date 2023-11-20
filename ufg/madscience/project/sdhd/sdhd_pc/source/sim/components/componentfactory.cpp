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
UFG::SimComponent *__fastcall UFG::CompositeDrawableComponent_PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject, bool required)
{
  bool v2; // si
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::qPropertySet *v7; // rcx
  UFG::qPropertySet *v8; // rax
  UFG::SimComponent *v9; // rdi
  char *v10; // rax
  UFG::qMemoryPool *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::SimComponent *v13; // rax
  UFG::SimObject *v14; // rdx
  unsigned __int16 v15; // cx
  unsigned int v16; // ebx
  UFG::SimObjectModifier v17; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = sceneObject;
  v4 = sceneObject->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_ModelAsset::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v5 && UFG::qPropertySet::GetMemImagePtr(v5) )
    return 0i64;
  v7 = v3->mpWritableProperties;
  if ( !v7 )
    v7 = v3->mpConstProperties;
  v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v7,
         (UFG::qSymbol *)&component_CompositeDrawable::sPropertyName.mUID,
         DEPTH_RECURSE);
  v9 = 0i64;
  v10 = v8 ? UFG::qPropertySet::GetMemImagePtr(v8) : 0i64;
  if ( !v2 && !v10 )
    return 0i64;
  v11 = UFG::GetSimulationMemoryPool();
  v12 = UFG::qMemoryPool::Allocate(v11, 0x5E0ui64, "CompositeDrawableComponent", 0i64, 1u);
  if ( v12 )
  {
    UFG::CompositeDrawableComponent::CompositeDrawableComponent((UFG::CompositeDrawableComponent *)v12);
    v9 = v13;
  }
  v14 = v3->m_pSimObject;
  v15 = v14->m_Flags;
  if ( (v15 >> 14) & 1 || (v15 & 0x8000u) != 0 )
  {
    v16 = 14;
  }
  else if ( (v15 >> 13) & 1 )
  {
    v16 = 9;
  }
  else
  {
    v16 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v17, v14, 1);
  UFG::SimObjectModifier::AttachComponent(&v17, v9, v16);
  UFG::SimObjectModifier::Close(&v17);
  UFG::SimObjectModifier::~SimObjectModifier(&v17);
  return v9;
}

// File Line: 258
// RVA: 0x58D0D0
UFG::TransformNodeComponent *__fastcall UFG::TransformNodeComponent_PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj, UFG::qMatrix44 *pWorldMatrix, UFG::TransformNodeComponent *parentTransform)
{
  UFG::TransformNodeComponent *v3; // r14
  UFG::qMatrix44 *v4; // r15
  UFG::SceneObjectProperties *v5; // rbp
  UFG::qMemoryPool *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::TransformNodeComponent *v8; // rax
  UFG::TransformNodeComponent *v9; // rdi
  UFG::SimObject *v10; // rdx
  unsigned __int16 v11; // cx
  unsigned int v12; // ebx
  UFG::TransformNodeComponent *result; // rax
  UFG::qMemoryPool *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::TransformNodeComponent *v16; // rax
  UFG::TransformNodeComponent *v17; // rdi
  UFG::SimObject *v18; // rdx
  unsigned __int16 v19; // cx
  unsigned int v20; // ebx
  UFG::SimObjectModifier v21; // [rsp+38h] [rbp-40h]

  v3 = parentTransform;
  v4 = pWorldMatrix;
  v5 = pSceneObj;
  if ( pWorldMatrix )
  {
    v6 = UFG::GetSimulationMemoryPool();
    v7 = UFG::qMemoryPool::Allocate(v6, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
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
    v10 = v5->m_pSimObject;
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 || (v11 & 0x8000u) != 0 || (v11 >> 13) & 1 )
    {
      v12 = 2;
    }
    else
    {
      v12 = -1;
      if ( (v11 >> 12) & 1 )
        v12 = 1;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v21, v10, 1);
    UFG::SimObjectModifier::AttachComponent(&v21, (UFG::SimComponent *)&v9->vfptr, v12);
    UFG::SimObjectModifier::Close(&v21);
    UFG::SimObjectModifier::~SimObjectModifier(&v21);
    UFG::TransformNodeComponent::PropertiesLoadWithMatrix(v9, v5, v4);
    result = v9;
  }
  else if ( PropertyUtils::HasComponentPropertySet(
              pSceneObj,
              (UFG::qSymbol *)&SimSymX_propset_componentTransformNode.mUID) )
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
    v18 = v5->m_pSimObject;
    v19 = v18->m_Flags;
    if ( (v19 >> 14) & 1 )
    {
      v20 = 2;
    }
    else if ( (v19 & 0x8000u) == 0 )
    {
      if ( (v19 >> 13) & 1 )
      {
        v20 = 2;
      }
      else
      {
        v20 = -1;
        if ( (v19 >> 12) & 1 )
          v20 = 1;
      }
    }
    else
    {
      v20 = 2;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v21, v18, 1);
    UFG::SimObjectModifier::AttachComponent(&v21, (UFG::SimComponent *)&v17->vfptr, v20);
    UFG::SimObjectModifier::Close(&v21);
    UFG::SimObjectModifier::~SimObjectModifier(&v21);
    UFG::TransformNodeComponent::PropertiesLoadWithMatrix(v17, v5, 0i64);
    if ( v3 )
      UFG::TransformNodeComponent::SetParent(v17, v3, 0);
    result = v17;
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 293
// RVA: 0x588860
void __fastcall UFG::ComponentFactory::PostComponentFactory(UFG::SimObject *simObject)
{
  UFG::SceneObjectProperties *v1; // rbx

  v1 = simObject->m_pSceneObj;
  UFG::TSActorComponent::PropertiesOnActivateNew(simObject->m_pSceneObj, 0);
  if ( UFG::AIOutlineComponent::HasComponent(v1) )
    UFG::AIOutlineComponent::PropertiesOnActivate(v1);
  UFG::SimObjectPropertiesComponent::PropertiesOnActivateNew(v1, 0);
  if ( PropertyUtils::HasComponentPropertySet(v1, (UFG::qSymbol *)&SimSymX_propset_componentActionTree.mUID) )
    UFG::ActionTreeComponent::PropertiesOnActivate(v1);
  if ( UFG::PropInteractComponent::HasComponent(v1) )
    UFG::PropInteractComponent::PropertiesOnActivate(v1);
  if ( UFG::DoorComponent::HasComponent(v1) )
    UFG::DoorComponent::PropertiesOnActivate(v1);
  if ( UFG::RadarComponent::HasComponent(v1) )
    UFG::RadarComponent::PropertiesOnActivate(v1);
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gPlayerNames__);
}

// File Line: 323
// RVA: 0x57F8F0
void __fastcall UFG::ComponentFactory_PropertiesOnActivateCharacter(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qPropertySet *v2; // rcx
  UFG::qPropertySet *v3; // rax
  component_CharacterAnimation *v4; // rdi
  UFG::qMemoryPool *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // rsi
  UFG::SimObject *v9; // rdx
  unsigned __int16 v10; // cx
  unsigned int v11; // edi
  char v12; // di
  unsigned int v13; // eax
  UFG::SimObjectCharacter *v14; // rbx
  __int64 v15; // rcx
  _QWORD *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::BaseCameraComponent *v18; // rcx
  UFG::SimObjectModifier v19; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  UFG::TSActorComponent::PropertiesOnActivateNew(pSceneObj, 1);
  UFG::SimObjectCharacterPropertiesComponent::PropertiesOnActivateNew(v1, 1);
  UFG::SimObjectSignalMemoryComponent::PropertiesOnActivateNew(v1, 1);
  v2 = v1->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  v3 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v2,
         (UFG::qSymbol *)&component_CharacterAnimation::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v3 )
  {
    v4 = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v3);
    if ( v4 )
    {
      v5 = UFG::GetSimulationMemoryPool();
      v6 = UFG::qMemoryPool::Allocate(v5, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
      if ( v6 )
      {
        UFG::CharacterAnimationComponent::CharacterAnimationComponent((UFG::CharacterAnimationComponent *)v6, v1, v4);
        v8 = v7;
      }
      else
      {
        v8 = 0i64;
      }
      v9 = v1->m_pSimObject;
      v10 = v9->m_Flags;
      if ( (v10 >> 14) & 1 )
      {
        v11 = 9;
      }
      else if ( (v10 & 0x8000u) == 0 )
      {
        if ( (v10 >> 13) & 1 )
          v11 = 8;
        else
          v11 = -1;
      }
      else
      {
        v11 = 9;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v19, v9, 1);
      UFG::SimObjectModifier::AttachComponent(&v19, v8, v11);
      UFG::SimObjectModifier::Close(&v19);
      UFG::SimObjectModifier::~SimObjectModifier(&v19);
    }
  }
  UFG::CompositeDrawableComponent_PropertiesOnActivate(v1, 0);
  Render::FXSimComponent::PropertiesOnActivateNew(v1, 1);
  UFG::CharacterLookComponent::PropertiesOnActivateNew(v1, 0);
  UFG::DropShadowComponent::PropertiesOnActivateNew(v1, 0);
  UFG::MissionFailConditionComponent::PropertiesOnActivateNew(v1, 1);
  UFG::StreamedResourceComponent::PropertiesOnActivateNew(v1, 0);
  UFG::CharacterPhysicsComponent::PropertiesOnActivateNew(v1, 1);
  UFG::AIAwarenessComponent::PropertiesOnActivateNew(v1, 1);
  UFG::ActiveAIEntityComponent::PropertiesOnActivateNew(v1, 1);
  UFG::AICharacterControllerComponent::PropertiesOnActivateNew(v1, 1);
  UFG::GameNavComponent::PropertiesOnActivateNew(v1, 1);
  UFG::StimulusReceiverComponent::PropertiesOnActivateNew(v1, 1);
  UFG::WorldContextComponent::PropertiesOnActivateNew(v1, 1);
  UFG::AIScriptInterfaceComponent::PropertiesOnActivateNew(v1, 1);
  UFG::HealthComponent::PropertiesOnActivateNew(v1, 1);
  UFG::HitReactionComponent::PropertiesOnActivateNew(v1, 1);
  UFG::InteractableComponent::PropertiesOnActivateNew(v1, 1);
  UFG::InteractorComponent::PropertiesOnActivateNew(v1, 1);
  UFG::AnimationLODComponent::PropertiesOnActivateNew(v1, 1);
  if ( PropertyUtils::HasComponentPropertySet(v1, (UFG::qSymbol *)&SimSymX_propset_componentActionTree.mUID) )
    UFG::ActionTreeComponent::PropertiesOnActivate(v1);
  if ( gPrototype_UseBehaviourController )
    UFG::BehaviourControllerComponent::PropertiesOnActivateNew(v1, 1);
  else
    UFG::AIActionTreeComponent::PropertiesOnActivateNew(v1, 1);
  UFG::ActionTreeResourcesComponent::PropertiesOnActivateNew(v1, 1);
  UFG::FacialActionTreeComponent::PropertiesOnActivateNew(v1, 1);
  UFG::GetInFormationComponent::PropertiesOnActivateNew(v1, 1);
  UFG::PedFormationManagerComponent::PropertiesOnActivateNew(v1, 1);
  UFG::GetInPedFormationComponent::PropertiesOnActivateNew(v1, 1);
  UFG::HasAttackRequestComponent::PropertiesOnActivateNew(v1, 1);
  UFG::CharacterSubjectComponent::PropertiesOnActivateNew(v1, 1);
  UFG::CharacterEffectsComponent::PropertiesOnActivateNew(v1, 1);
  UFG::InventoryComponent::PropertiesOnActivateNew(v1, 1);
  UFG::ActorAudioComponent::PropertiesOnActivateNew(v1, 1);
  UFG::DialogueAnimationComponent::PropertiesOnActivateNew(v1, 1);
  UFG::InterestPointUserComponent::PropertiesOnActivateNew(v1, 1);
  UFG::RagdollComponent::PropertiesOnActivateNew(v1, 0);
  UFG::SensorComponent::PropertiesOnActivateNew(v1, 0);
  UFG::FormationManagerComponent::PropertiesOnActivateNew(v1, 0);
  if ( UFG::AttackRightsComponent::HasComponent(v1) )
    UFG::AttackRightsComponent::PropertiesOnActivate(v1);
  if ( UFG::FaceActionComponent::HasComponent(v1) )
    UFG::FaceActionComponent::PropertiesOnActivate(v1);
  if ( UFG::CopUnitComponent::HasComponent(v1) )
    UFG::CopUnitComponent::PropertiesOnActivate(v1);
  if ( UFG::AICoverComponent::HasComponent(v1) )
    UFG::AICoverComponent::PropertiesOnActivate(v1);
  if ( UFG::StoreBlipComponent::HasComponent(v1) )
    UFG::StoreBlipComponent::PropertiesOnActivate(v1);
  v12 = 0;
  v13 = v1->m_NameUID;
  if ( v13 == UFG::gPlayerNames.mUID
    || v13 == stru_14242E38C.mUID
    || v13 == stru_14242E390.mUID
    || v13 == stru_14242E394.mUID )
  {
    if ( UFG::PlayerCoverComponent::HasComponent(v1) )
      UFG::PlayerCoverComponent::PropertiesOnActivate(v1);
    UFG::FaceMeterComponent::PropertiesOnActivate(v1);
    UFG::VehicleOwnershipComponent::PropertiesOnActivate(v1);
    if ( UFG::TargetingSystemPedPlayerComponent::HasComponent(v1) )
      UFG::TargetingSystemPedPlayerComponent::PropertiesOnActivate(v1);
    UFG::AimingPlayerComponent::PropertiesOnActivate(v1);
    v12 = 0;
    if ( v1->m_NameUID == UFG::gPlayerNames.mUID )
      v12 = 1;
  }
  UFG::TargetingSystemPedNPCCombatantComponent::PropertiesOnActivate(v1);
  UFG::AimingNPCComponent::PropertiesOnActivateNew(v1, 1);
  UFG::UELComponent::PropertiesOnActivate(v1);
  if ( v12 )
  {
    v14 = (UFG::SimObjectCharacter *)v1->m_pSimObject;
    if ( LocalPlayer )
    {
      v15 = unk_14235C478;
      v16 = (_QWORD *)unk_14235C480;
      *(_QWORD *)(unk_14235C478 + 8i64) = unk_14235C480;
      *v16 = v15;
      unk_14235C478 = &unk_14235C478;
      unk_14235C480 = &unk_14235C478;
    }
    LocalPlayer = v14;
    if ( v14 )
    {
      v17 = v14->m_SafePointerList.mNode.mPrev;
      v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&unk_14235C478;
      unk_14235C478 = v17;
      unk_14235C480 = (char *)v14 + 8;
      v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&unk_14235C478;
    }
    v18 = UFG::Director::Get()->mCurrentCamera;
    if ( v18 )
    {
      if ( v18->m_pSimObject )
        UFG::ResetCameraObjects((UFG::SimObject *)&v14->vfptr);
    }
  }
}

// File Line: 448
// RVA: 0x588E20
void __fastcall UFG::ComponentFactory::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj, UFG::qMatrix44 *pWorldMatrix, UFG::qSymbol *_objectType, UFG::TransformNodeComponent *parentTransform)
{
  UFG::qSymbol *v4; // rbx
  UFG::SceneObjectProperties *v5; // rdi
  UFG::SceneObjectProperties *v6; // r14
  unsigned int v7; // ebx
  UFG::qPropertySet *v8; // rax
  unsigned int v9; // esi
  UFG::qPropertySet *v10; // rcx
  UFG::qPropertySet *v11; // rax
  UFG::qMemoryPool *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::SceneObjectProperties *v14; // rax
  UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> **v15; // rcx
  UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *v16; // rax
  UFG::qPropertySet *v17; // rcx
  UFG::qPropertySet *v18; // rax
  component_CharacterAnimation *v19; // rbx
  UFG::qMemoryPool *v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::SceneObjectProperties *v22; // rax
  UFG::SimObject *v23; // rdx
  unsigned __int16 v24; // cx
  UFG::qPropertySet *v25; // rcx
  UFG::qPropertySet *v26; // rax
  component_CharacterAnimation *v27; // rbx
  UFG::qMemoryPool *v28; // rax
  UFG::allocator::free_link *v29; // rax
  UFG::SceneObjectProperties *v30; // rax
  UFG::SimObject *v31; // rdx
  unsigned __int16 v32; // cx
  UFG::qPropertySet *v33; // rcx
  UFG::qPropertySet *v34; // rax
  component_CharacterAnimation *v35; // rbx
  UFG::qMemoryPool *v36; // rax
  UFG::allocator::free_link *v37; // rax
  UFG::SceneObjectProperties *v38; // rax
  UFG::SimObject *v39; // rdx
  unsigned __int16 v40; // cx
  UFG::allocator::free_link *v41; // rax
  UFG::SceneObjectProperties *v42; // rax
  hkgpIndexedMeshDefinitions::Edge *v43; // rdx
  UFG::qPropertySet *v44; // rcx
  UFG::qPropertySet *v45; // rax
  component_CameraAnimation *v46; // rbx
  UFG::qMemoryPool *v47; // rax
  UFG::allocator::free_link *v48; // rax
  UFG::SimComponent *v49; // rax
  UFG::SimComponent *v50; // rbx
  UFG::qPropertySet *v51; // rcx
  UFG::qPropertySet *v52; // rax
  component_CharacterAnimation *v53; // rbx
  UFG::qMemoryPool *v54; // rax
  UFG::allocator::free_link *v55; // rax
  UFG::SimComponent *v56; // rax
  UFG::SimComponent *v57; // rbx
  UFG::SimObject *v58; // rdx
  unsigned __int16 v59; // cx
  UFG::qPropertySet *v60; // rcx
  UFG::qPropertySet *v61; // rax
  char *v62; // rsi
  UFG::qMemoryPool *v63; // rax
  UFG::allocator::free_link *v64; // r12
  UFG::SimObject *v65; // rbx
  UFG::qSymbol *v66; // rax
  UFG::SpawnPoint *v67; // rax
  UFG::SpawnPoint *v68; // rbx
  UFG::SimObject *v69; // rax
  UFG::SceneObjectProperties *v70; // rax
  UFG::qPropertySet *v71; // rcx
  UFG::qWiseSymbol result; // [rsp+34h] [rbp-2Ch]
  __int64 v73; // [rsp+38h] [rbp-28h]
  UFG::SimObjectModifier v74; // [rsp+40h] [rbp-20h]
  UFG::allocator::free_link *pPriority; // [rsp+A0h] [rbp+40h]

  v73 = -2i64;
  v4 = _objectType;
  v5 = pSceneObj;
  v6 = 0i64;
  UFG::TransformNodeComponent_PropertiesOnActivate(pSceneObj, pWorldMatrix, parentTransform);
  v7 = v4->mUID;
  if ( v7 == UFG::gNullQSymbol.mUID )
  {
    v8 = PropertyUtils::Get<UFG::qSymbol>(v5, (UFG::qSymbol *)&qSymbol_ObjectType.mUID);
    if ( v8 )
      v7 = v8->mFlags;
  }
  v9 = -1;
  if ( v7 == -1 )
    goto LABEL_331;
  if ( v7 == qSymbol_Marker.mUID )
  {
    UFG::Marker::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_NISScriptSystem.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(v5, 1);
    UFG::NISScriptSystemComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_MeleeScriptSystem.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(v5, 1);
    UFG::MeleeScriptSystemComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_ModelAsset.mUID )
  {
    UFG::ModelAssetComponent_PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_DynamicLight.mUID )
  {
    Render::DynamicLightComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_IrradianceVolume.mUID )
  {
    Render::IrradianceVolumeComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_MarkerRaceStartingGrid.mUID )
  {
    UFG::Marker::PropertiesOnActivate(v5);
    UFG::GameSubject::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_SpawnRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(v5) )
      UFG::RegionComponent::PropertiesOnActivate(v5);
    UFG::SpawnRegion::PropertiesOnActivateNew(v5, 1);
    return;
  }
  if ( v7 == qSymbol_SpawnPoint.mUID )
  {
    UFG::SpawnPoint::PropertiesOnActivateNew(v5, 1);
    return;
  }
  if ( v7 == qSymbol_InterestPoint.mUID )
  {
    UFG::InterestPoint::PropertiesOnActivate(v5);
    UFG::InteractableComponent::PropertiesOnActivateNew(v5, 0);
    return;
  }
  if ( v7 == qSymbol_Character.mUID )
  {
    UFG::ComponentFactory_PropertiesOnActivateCharacter(v5);
    UFG::TriadWarsComponent::PropertiesOnActivateNew(v5, 0);
    return;
  }
  if ( v7 == qSymbol_Vehicle.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(v5, 1);
    UFG::AIOutlineComponent::PropertiesOnActivate(v5);
    UFG::SimObjectVehiclePropertiesComponent::PropertiesOnActivateNew(v5, 1);
    UFG::VehicleAudioComponent::PropertiesOnActivateNew(v5, 1);
    UFG::VehiclesBlipComponent::PropertiesOnActivateNew(v5, 1);
    UFG::VehicleOccupantComponent::PropertiesOnActivate(v5);
    UFG::VehicleSubjectComponent::PropertiesOnActivate(v5);
    UFG::AIScriptInterfaceComponent::PropertiesOnActivateNew(v5, 1);
    UFG::MissionFailConditionComponent::PropertiesOnActivateNew(v5, 1);
    UFG::CharacterAnimationComponent::PropertiesOnActivateNew(v5, 1);
    UFG::StreamedResourceComponent::PropertiesOnActivateNew(v5, 1);
    UFG::CompositeDrawableComponent_PropertiesOnActivate(v5, 1);
    Render::FXSimComponent::PropertiesOnActivateNew(v5, 1);
    UFG::VehicleEffectsComponent::PropertiesOnActivateNew(v5, 1);
    v10 = v5->mpWritableProperties;
    if ( !v10 )
      v10 = v5->mpConstProperties;
    v11 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v10,
            (UFG::qSymbol *)&component_CompositeDrawable::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v11 )
      UFG::qPropertySet::GetMemImagePtr(v11);
    v12 = UFG::GetSimulationMemoryPool();
    v13 = UFG::qMemoryPool::Allocate(v12, 0x110ui64, "VehicleLookComponent", 0i64, 1u);
    pPriority = v13;
    if ( v13 )
    {
      UFG::VehicleLookComponent::VehicleLookComponent((UFG::VehicleLookComponent *)v13);
      v6 = v14;
    }
    v15 = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> **)&v6->mpOwner;
    v16 = UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&v6->mpOwner;
    *v15 = v16;
    v15[1] = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&UFG::CompositeLookComponent::s_CompositeLookComponentList;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&v6->mpOwner;
    UFG::SimObjectModifier::SimObjectModifier(&v74, v5->m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v74, (UFG::SimComponent *)&v6->vfptr, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v74);
    UFG::SimObjectModifier::~SimObjectModifier(&v74);
    UFG::DropShadowComponent::PropertiesOnActivateNew(v5, 1);
    UFG::ActionTreeComponent::PropertiesOnActivate(v5);
    UFG::HealthComponent::PropertiesOnActivateNew(v5, 1);
    UFG::HitReactionComponent::PropertiesOnActivateNew(v5, 1);
    UFG::PropInteractComponent::PropertiesOnActivate(v5);
    UFG::TargetingSystemVehicleComponent::PropertiesOnActivate(v5);
    UFG::StimulusReceiverComponent::PropertiesOnActivateNew(v5, 0);
    UFG::InteractableComponent::PropertiesOnActivateNew(v5, 1);
    UFG::AnimationLODComponent::PropertiesOnActivateNew(v5, 1);
    if ( UFG::CopUnitComponent::HasComponent(v5) )
      UFG::CopUnitComponent::PropertiesOnActivate(v5);
    if ( !UFG::CarPhysicsMoverComponent::PropertiesOnActivateNew(v5, 0)
      && !UFG::BikePhysicsMoverComponent::PropertiesOnActivateNew(v5, 0) )
    {
      UFG::BoatPhysicsMoverComponent::PropertiesOnActivateNew(v5, 0);
    }
    UFG::SensorComponent::PropertiesOnActivateNew(v5, 0);
LABEL_327:
    if ( UFG::UELComponent::HasComponent(v5) )
      UFG::UELComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_TriggerRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(v5) )
      UFG::RegionComponent::PropertiesOnActivate(v5);
    UFG::TriggerRegion::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_StartRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(v5) )
      UFG::RegionComponent::PropertiesOnActivate(v5);
    UFG::StartRegion::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_Prop.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(v5, 1);
    UFG::SimObjectPropertiesComponent::PropertiesOnActivateNew(v5, 0);
    UFG::StimulusReceiverComponent::PropertiesOnActivateNew(v5, 0);
    v17 = v5->mpWritableProperties;
    if ( !v17 )
      v17 = v5->mpConstProperties;
    v18 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v17,
            (UFG::qSymbol *)&component_CharacterAnimation::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v18 )
    {
      v19 = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v18);
      if ( v19 )
      {
        v20 = UFG::GetSimulationMemoryPool();
        v21 = UFG::qMemoryPool::Allocate(v20, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
        pPriority = v21;
        if ( v21 )
        {
          UFG::CharacterAnimationComponent::CharacterAnimationComponent(
            (UFG::CharacterAnimationComponent *)v21,
            v5,
            v19);
          v6 = v22;
        }
        v23 = v5->m_pSimObject;
        v24 = v23->m_Flags;
        if ( (v24 >> 14) & 1 )
        {
          v9 = 9;
        }
        else if ( (v24 & 0x8000u) == 0 )
        {
          if ( (v24 >> 13) & 1 )
            v9 = 8;
        }
        else
        {
          v9 = 9;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v74, v23, 1);
        UFG::SimObjectModifier::AttachComponent(&v74, (UFG::SimComponent *)&v6->vfptr, v9);
        UFG::SimObjectModifier::Close(&v74);
        UFG::SimObjectModifier::~SimObjectModifier(&v74);
      }
    }
    UFG::CompositeDrawableComponent_PropertiesOnActivate(v5, 0);
    Render::FXSimComponent::PropertiesOnActivateNew(v5, 1);
    UFG::CompositeLookComponent::PropertiesOnActivateNew(v5, 0);
    UFG::DropShadowComponent::PropertiesOnActivateNew(v5, 0);
    UFG::StreamedResourceComponent::PropertiesOnActivateNew(v5, 0);
    if ( PropertyUtils::HasComponentPropertySet(v5, (UFG::qSymbol *)&SimSymX_propset_componentActionTree.mUID) )
      UFG::ActionTreeComponent::PropertiesOnActivate(v5);
    if ( UFG::PropInteractComponent::HasComponent(v5) )
      UFG::PropInteractComponent::PropertiesOnActivate(v5);
    if ( UFG::RigidBodyComponent::HasComponent(v5) )
      UFG::RigidBodyComponent::PropertiesOnActivate(v5);
    UFG::InventoryItemComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::CollectibleComponent::HasComponent(v5) )
      UFG::CollectibleComponent::PropertiesOnActivate(v5);
    if ( UFG::DoorComponent::HasComponent(v5) )
      UFG::DoorComponent::PropertiesOnActivate(v5);
    if ( PropertyUtils::HasComponentPropertySet(v5, (UFG::qSymbol *)&SimSymX_propset_componentPowerManagement.mUID) )
      UFG::PowerManagementComponent::PropertiesOnActivate(v5);
    if ( UFG::RadarComponent::HasComponent(v5) )
      UFG::RadarComponent::PropertiesOnActivate(v5);
    if ( PropertyUtils::PropertyExists(v5, (UFG::qSymbol *)&qSymbolX_propset_componentPOI.mUID) )
      UFG::InterestPoint::PropertiesOnActivate(v5);
    if ( UFG::TargetingSystemPedNPCAmbientComponent::HasComponent(v5) )
      UFG::TargetingSystemPedNPCAmbientComponent::PropertiesOnActivate(v5);
    if ( UFG::TargetingSystemItemComponent::HasComponent(v5) )
      UFG::TargetingSystemItemComponent::PropertiesOnActivate(v5);
    if ( UFG::AIOutlineComponent::HasComponent(v5) )
      UFG::AIOutlineComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_AIOutlineRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(v5) )
      UFG::RegionComponent::PropertiesOnActivate(v5);
    UFG::AIOutlineComponent::PropertiesOnActivate(v5);
    UFG::AIOutlineRegion::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_BoostRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(v5) )
      UFG::RegionComponent::PropertiesOnActivate(v5);
    UFG::BoostRegion::PropertiesOnActivate(v5);
    if ( UFG::CollectibleComponent::HasComponent(v5) )
      UFG::CollectibleComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_CombatRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(v5) )
      UFG::RegionComponent::PropertiesOnActivate(v5);
    UFG::CombatRegion::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_Door.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(v5, 1);
    if ( UFG::AIOutlineComponent::HasComponent(v5) )
      UFG::AIOutlineComponent::PropertiesOnActivate(v5);
    UFG::SimObjectPropertiesComponent::PropertiesOnActivateNew(v5, 1);
    v25 = v5->mpWritableProperties;
    if ( !v25 )
      v25 = v5->mpConstProperties;
    v26 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v25,
            (UFG::qSymbol *)&component_CharacterAnimation::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v26 )
    {
      v27 = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v26);
      if ( v27 )
      {
        v28 = UFG::GetSimulationMemoryPool();
        v29 = UFG::qMemoryPool::Allocate(v28, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
        pPriority = v29;
        if ( v29 )
        {
          UFG::CharacterAnimationComponent::CharacterAnimationComponent(
            (UFG::CharacterAnimationComponent *)v29,
            v5,
            v27);
          v6 = v30;
        }
        v31 = v5->m_pSimObject;
        v32 = v31->m_Flags;
        if ( (v32 >> 14) & 1 )
        {
          v9 = 9;
        }
        else if ( (v32 & 0x8000u) == 0 )
        {
          if ( (v32 >> 13) & 1 )
            v9 = 8;
        }
        else
        {
          v9 = 9;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v74, v31, 1);
        UFG::SimObjectModifier::AttachComponent(&v74, (UFG::SimComponent *)&v6->vfptr, v9);
        UFG::SimObjectModifier::Close(&v74);
        UFG::SimObjectModifier::~SimObjectModifier(&v74);
      }
    }
    UFG::CompositeDrawableComponent_PropertiesOnActivate(v5, 0);
    Render::FXSimComponent::PropertiesOnActivateNew(v5, 1);
    UFG::ModelAssetComponent_PropertiesOnActivate(v5);
    UFG::CompositeLookComponent::PropertiesOnActivateNew(v5, 0);
    if ( PropertyUtils::HasComponentPropertySet(v5, (UFG::qSymbol *)&SimSymX_propset_componentActionTree.mUID) )
      UFG::ActionTreeComponent::PropertiesOnActivate(v5);
    if ( UFG::PropInteractComponent::HasComponent(v5) )
      UFG::PropInteractComponent::PropertiesOnActivate(v5);
    if ( UFG::DoorComponent::HasComponent(v5) )
      UFG::DoorComponent::PropertiesOnActivate(v5);
    if ( PropertyUtils::HasComponentPropertySet(v5, (UFG::qSymbol *)&SimSymX_propset_componentPowerManagement.mUID) )
      UFG::PowerManagementComponent::PropertiesOnActivate(v5);
LABEL_123:
    if ( UFG::RadarComponent::HasComponent(v5) )
      UFG::RadarComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_Weapon.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(v5, 1);
    UFG::SimObjectWeaponPropertiesComponent::PropertiesOnActivateNew(v5, 1);
    if ( UFG::TargetingSystemItemComponent::HasComponent(v5) )
      UFG::TargetingSystemItemComponent::PropertiesOnActivate(v5);
    UFG::StreamedResourceComponent::PropertiesOnActivateNew(v5, 0);
    UFG::InventoryItemComponent::PropertiesOnActivateNew(v5, 0);
    v33 = v5->mpWritableProperties;
    if ( !v33 )
      v33 = v5->mpConstProperties;
    v34 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v33,
            (UFG::qSymbol *)&component_CharacterAnimation::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v34 )
    {
      v35 = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v34);
      if ( v35 )
      {
        v36 = UFG::GetSimulationMemoryPool();
        v37 = UFG::qMemoryPool::Allocate(v36, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
        pPriority = v37;
        if ( v37 )
        {
          UFG::CharacterAnimationComponent::CharacterAnimationComponent(
            (UFG::CharacterAnimationComponent *)v37,
            v5,
            v35);
          v6 = v38;
        }
        v39 = v5->m_pSimObject;
        v40 = v39->m_Flags;
        if ( (v40 >> 14) & 1 )
        {
          v9 = 9;
        }
        else if ( (v40 & 0x8000u) == 0 )
        {
          if ( (v40 >> 13) & 1 )
            v9 = 8;
        }
        else
        {
          v9 = 9;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v74, v39, 1);
        UFG::SimObjectModifier::AttachComponent(&v74, (UFG::SimComponent *)&v6->vfptr, v9);
        UFG::SimObjectModifier::Close(&v74);
        UFG::SimObjectModifier::~SimObjectModifier(&v74);
      }
    }
    UFG::CompositeDrawableComponent_PropertiesOnActivate(v5, 0);
    Render::FXSimComponent::PropertiesOnActivateNew(v5, 1);
    UFG::CompositeLookComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::RadarComponent::HasComponent(v5) )
      UFG::RadarComponent::PropertiesOnActivate(v5);
    if ( PropertyUtils::HasComponentPropertySet(v5, (UFG::qSymbol *)&SimSymX_propset_componentActionTree.mUID) )
      UFG::ActionTreeComponent::PropertiesOnActivate(v5);
    UFG::InteractableComponent::PropertiesOnActivateNew(v5, 1);
    if ( UFG::GunComponent::HasComponent(v5) )
      UFG::GunComponent::PropertiesOnActivate(v5);
    goto LABEL_327;
  }
  if ( v7 == qSymbol_MarkerProgressionTrigger.mUID )
  {
    UFG::Marker::PropertiesOnActivate(v5);
    UFG::ProgressionTriggerComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_SpawnPointProgressionTrigger.mUID )
  {
    UFG::SpawnPoint::PropertiesOnActivateNew(v5, 1);
    UFG::ProgressionTriggerComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_Camera.mUID )
  {
    UFG::CameraAnimationComponent::PropertiesOnActivateNew(v5, 1);
    UFG::AnimatedCameraComponent::PropertiesOnActivate(v5);
    UFG::ProgressionCameraComponent::PropertiesOnActivate(v5);
    UFG::FollowCameraComponent::PropertiesOnActivate(v5);
    UFG::ChaseCameraComponent::PropertiesOnActivate(v5);
    UFG::ScriptCameraComponent::PropertiesOnActivate(v5);
    UFG::TurfCameraComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_Director.mUID )
  {
    UFG::Director::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_AudioTriggerRegion.mUID )
  {
    UFG::RegionComponent::PropertiesOnActivate(v5);
    UFG::AudioTriggerRegion::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_AudioEmitterMarker.mUID )
  {
    UFG::AudioEmitterMarker::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_CopRoadBlock.mUID )
  {
    UFG::CopRoadBlock::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_WeaponSpawner.mUID )
  {
    UFG::CollectibleWeaponSpawnerComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_HidingSpot.mUID )
  {
    UFG::CollectibleHidingSpotComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_Collectible.mUID )
  {
    if ( UFG::CollectibleWeaponSpawnerComponent::HasComponent(v5) )
      UFG::CollectibleWeaponSpawnerComponent::PropertiesOnActivate(v5);
    if ( UFG::CollectibleHidingSpotComponent::HasComponent(v5) )
      UFG::CollectibleHidingSpotComponent::PropertiesOnActivate(v5);
    UFG::CollectibleComponent::PropertiesOnActivate(v5);
    goto LABEL_123;
  }
  if ( v7 == qSymbol_TrafficRegion.mUID )
  {
    if ( UFG::RegionComponent::HasComponent(v5) )
      UFG::RegionComponent::PropertiesOnActivate(v5);
    UFG::TrafficRegion::PropertiesOnActivateNew(v5, 1);
    return;
  }
  if ( v7 == qSymbol_AIPathMarker.mUID )
  {
    if ( UFG::AIMarker::HasComponent(v5) )
      UFG::AIMarker::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_ParkingSpot.mUID )
  {
    UFG::ParkingSpot::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_CameraMarker.mUID )
  {
    UFG::CameraMarker::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_Prefab.mUID )
  {
    UFG::TSActorComponent::PropertiesOnActivateNew(v5, 0);
    UFG::PrefabComponent::PropertiesOnActivate(v5);
    return;
  }
  if ( v7 == qSymbol_FXSimComponent.mUID )
  {
    Render::FXSimComponent::PropertiesOnActivateNew(v5, 1);
    return;
  }
  if ( v7 != qSymbol_Turf.mUID )
  {
LABEL_331:
    if ( UFG::Marker::HasComponent(v5) )
      UFG::Marker::PropertiesOnActivate(v5);
    if ( UFG::RegionComponent::HasComponent(v5) )
      UFG::RegionComponent::PropertiesOnActivate(v5);
    if ( PropertyUtils::HasComponentPropertySet(v5, (UFG::qSymbol *)&SimSymX_propset_componentActionTree.mUID) )
      UFG::ActionTreeComponent::PropertiesOnActivate(v5);
    if ( UFG::CollectibleWeaponSpawnerComponent::HasComponent(v5) )
      UFG::CollectibleWeaponSpawnerComponent::PropertiesOnActivate(v5);
    if ( UFG::CollectibleHidingSpotComponent::HasComponent(v5) )
      UFG::CollectibleHidingSpotComponent::PropertiesOnActivate(v5);
    if ( UFG::CollectibleComponent::HasComponent(v5) )
      UFG::CollectibleComponent::PropertiesOnActivate(v5);
    if ( gPrototype_UseBehaviourController )
      UFG::BehaviourControllerComponent::PropertiesOnActivateNew(v5, 0);
    else
      UFG::AIActionTreeComponent::PropertiesOnActivateNew(v5, 0);
    UFG::AICharacterControllerComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::AICoverComponent::HasComponent(v5) )
      UFG::AICoverComponent::PropertiesOnActivate(v5);
    if ( UFG::AIOutlineComponent::HasComponent(v5) )
      UFG::AIOutlineComponent::PropertiesOnActivate(v5);
    UFG::AIScriptInterfaceComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::ProgressionCameraComponent::HasComponent(v5) )
      UFG::AnimatedCameraComponent::PropertiesOnActivate(v5);
    if ( UFG::ProgressionCameraComponent::HasComponent(v5) )
      UFG::ProgressionCameraComponent::PropertiesOnActivate(v5);
    if ( UFG::AttackRightsComponent::HasComponent(v5) )
      UFG::AttackRightsComponent::PropertiesOnActivate(v5);
    if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v5, v43) )
      UFG::AudioEmitterMarker::PropertiesOnActivate(v5);
    if ( UFG::AudioTriggerRegion::HasComponent(v5) )
      UFG::AudioTriggerRegion::PropertiesOnActivate(v5);
    UFG::BikePhysicsMoverComponent::PropertiesOnActivateNew(v5, 0);
    UFG::BoatPhysicsMoverComponent::PropertiesOnActivateNew(v5, 0);
    v44 = v5->mpWritableProperties;
    if ( !v44 )
      v44 = v5->mpConstProperties;
    v45 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v44,
            (UFG::qSymbol *)&component_CameraAnimation::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v45 )
    {
      v46 = (component_CameraAnimation *)UFG::qPropertySet::GetMemImagePtr(v45);
      if ( v46 )
      {
        v47 = UFG::GetSimulationMemoryPool();
        v48 = UFG::qMemoryPool::Allocate(v47, 0xD8ui64, "CameraAnimationComponent", 0i64, 1u);
        pPriority = v48;
        if ( v48 )
        {
          UFG::CameraAnimationComponent::CameraAnimationComponent((UFG::CameraAnimationComponent *)v48, v5, v46);
          v50 = v49;
        }
        else
        {
          v50 = 0i64;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v74, v5->m_pSimObject, 1);
        UFG::SimObjectModifier::AttachComponent(&v74, v50, 0xFFFFFFFFi64);
        UFG::SimObjectModifier::Close(&v74);
        UFG::SimObjectModifier::~SimObjectModifier(&v74);
      }
    }
    UFG::CarPhysicsMoverComponent::PropertiesOnActivateNew(v5, 0);
    v51 = v5->mpWritableProperties;
    if ( !v51 )
      v51 = v5->mpConstProperties;
    v52 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v51,
            (UFG::qSymbol *)&component_CharacterAnimation::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v52 )
    {
      v53 = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v52);
      if ( v53 )
      {
        v54 = UFG::GetSimulationMemoryPool();
        v55 = UFG::qMemoryPool::Allocate(v54, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
        pPriority = v55;
        if ( v55 )
        {
          UFG::CharacterAnimationComponent::CharacterAnimationComponent(
            (UFG::CharacterAnimationComponent *)v55,
            v5,
            v53);
          v57 = v56;
        }
        else
        {
          v57 = 0i64;
        }
        v58 = v5->m_pSimObject;
        v59 = v58->m_Flags;
        if ( (v59 >> 14) & 1 )
        {
          v9 = 9;
        }
        else if ( (v59 & 0x8000u) == 0 )
        {
          if ( (v59 >> 13) & 1 )
            v9 = 8;
        }
        else
        {
          v9 = 9;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v74, v58, 1);
        UFG::SimObjectModifier::AttachComponent(&v74, v57, v9);
        UFG::SimObjectModifier::Close(&v74);
        UFG::SimObjectModifier::~SimObjectModifier(&v74);
      }
    }
    UFG::CharacterPhysicsComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::ChaseCameraComponent::HasComponent(v5) )
      UFG::ChaseCameraComponent::PropertiesOnActivate(v5);
    if ( UFG::CollectibleComponent::HasComponent(v5) )
      UFG::CollectibleComponent::PropertiesOnActivate(v5);
    if ( UFG::CombatRegion::HasComponent(v5) )
      UFG::CombatRegion::PropertiesOnActivate(v5);
    UFG::CompositeDrawableComponent_PropertiesOnActivate(v5, 0);
    Render::FXSimComponent::PropertiesOnActivateNew(v5, 0);
    UFG::CompositeLookComponent::PropertiesOnActivateNew(v5, 0);
    UFG::DropShadowComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::CopRoadBlock::HasComponent(v5) )
      UFG::CopRoadBlock::PropertiesOnActivate(v5);
    if ( UFG::CopUnitComponent::HasComponent(v5) )
      UFG::CopUnitComponent::PropertiesOnActivate(v5);
    if ( PropertyUtils::HasComponentPropertySet(v5, (UFG::qSymbol *)&qSymbolX_propset_componentCorona.mUID) )
      UFG::Corona::PropertiesOnActivate(v5);
    if ( UFG::DoorComponent::HasComponent(v5) )
      UFG::DoorComponent::PropertiesOnActivate(v5);
    if ( UFG::FaceActionComponent::HasComponent(v5) )
      UFG::FaceActionComponent::PropertiesOnActivate(v5);
    if ( UFG::FaceMeterComponent::HasComponent(v5) )
      UFG::FaceMeterComponent::PropertiesOnActivate(v5);
    UFG::FacialActionTreeComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::FollowCameraComponent::HasComponent(v5) )
      UFG::FollowCameraComponent::PropertiesOnActivate(v5);
    UFG::FormationManagerComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::GunComponent::HasComponent(v5) )
      UFG::GunComponent::PropertiesOnActivate(v5);
    UFG::HealthComponent::PropertiesOnActivateNew(v5, 0);
    UFG::HitReactionComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::HudComponent::HasComponent(v5) )
      UFG::HudComponent::PropertiesOnActivate(v5);
    UFG::InteractableComponent::PropertiesOnActivateNew(v5, 0);
    if ( PropertyUtils::PropertyExists(v5, (UFG::qSymbol *)&qSymbolX_propset_componentPOI.mUID) )
      UFG::InterestPoint::PropertiesOnActivate(v5);
    UFG::InventoryComponent::PropertiesOnActivateNew(v5, 0);
    UFG::InventoryItemComponent::PropertiesOnActivateNew(v5, 0);
    UFG::MissionFailConditionComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::ParkingSpot::HasComponent(v5) )
      UFG::ParkingSpot::PropertiesOnActivate(v5);
    if ( UFG::PlayerCoverComponent::HasComponent(v5) )
      UFG::PlayerCoverComponent::PropertiesOnActivate(v5);
    if ( UFG::ProgressionTriggerComponent::HasComponent(v5) )
      UFG::ProgressionTriggerComponent::PropertiesOnActivate(v5);
    if ( UFG::PropInteractComponent::HasComponent(v5) )
      UFG::PropInteractComponent::PropertiesOnActivate(v5);
    if ( UFG::RadarComponent::HasComponent(v5) )
      UFG::RadarComponent::PropertiesOnActivate(v5);
    UFG::RagdollComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::RigidBodyComponent::HasComponent(v5) )
      UFG::RigidBodyComponent::PropertiesOnActivate(v5);
    if ( UFG::TurfCameraComponent::HasComponent(v5) )
      UFG::ScriptCameraComponent::PropertiesOnActivate(v5);
    UFG::SensorComponent::PropertiesOnActivateNew(v5, 0);
    UFG::SimObjectSignalMemoryComponent::PropertiesOnActivateNew(v5, 0);
    UFG::SimObjectPropertiesComponent::PropertiesOnActivateNew(v5, 0);
    v60 = v5->mpWritableProperties;
    if ( !v60 )
      v60 = v5->mpConstProperties;
    v61 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v60,
            (UFG::qSymbol *)&component_SpawnPoint::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v61 )
    {
      v62 = UFG::qPropertySet::GetMemImagePtr(v61);
      if ( v62 )
      {
        v63 = UFG::GetSimulationMemoryPool();
        v64 = UFG::qMemoryPool::Allocate(v63, 0xE0ui64, "SpawnPoint", 0i64, 1u);
        pPriority = v64;
        if ( v64 )
        {
          v65 = v5->m_pSimObject;
          v66 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v5->m_NameUID);
          UFG::SpawnPoint::SpawnPoint((UFG::SpawnPoint *)v64, v66, v65);
          v68 = v67;
        }
        else
        {
          v68 = 0i64;
        }
        v68->mThugPoint = v62[1];
        if ( UFG::SpawnPoint::Initialize(v68, v5->m_pSimObject) )
        {
          LODWORD(pPriority) = 0;
          v69 = v68->m_pSimObject;
          if ( v69 )
            v6 = v69->m_pSceneObj;
          v70 = UFG::SceneObjectProperties::GetChildAsSceneObject(v6, 0);
          if ( v70 )
          {
            v71 = v70->mpWritableProperties;
            if ( !v71 )
              v71 = v70->mpConstProperties;
            UFG::SpawnInfoInterface::GetSpawnPriority(v71, (UFG::SpawnInfoInterface::SpawnPriority *)&pPriority);
          }
          if ( !((unsigned __int8)*v62 | ((signed int)pPriority >= 1)) )
            UFG::SpawnPoint::Spawn(v68, 0, 0);
        }
      }
    }
    UFG::SpawnRegion::PropertiesOnActivateNew(v5, 0);
    UFG::StimulusReceiverComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::StoreBlipComponent::HasComponent(v5) )
      UFG::StoreBlipComponent::PropertiesOnActivate(v5);
    UFG::StreamedResourceComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::TargetingSystemCraneComponent::HasComponent(v5) )
      UFG::TargetingSystemCraneComponent::PropertiesOnActivate(v5);
    if ( UFG::TargetingSystemItemComponent::HasComponent(v5) )
      UFG::TargetingSystemItemComponent::PropertiesOnActivate(v5);
    if ( UFG::TargetingSystemPedPlayerComponent::HasComponent(v5) )
      UFG::TargetingSystemPedPlayerComponent::PropertiesOnActivate(v5);
    if ( UFG::TargetingSystemPedNPCAmbientComponent::HasComponent(v5) )
      UFG::TargetingSystemPedNPCAmbientComponent::PropertiesOnActivate(v5);
    if ( UFG::TargetingSystemPedNPCCombatantComponent::HasComponent(v5) )
      UFG::TargetingSystemPedNPCCombatantComponent::PropertiesOnActivate(v5);
    if ( UFG::TargetingSystemVehicleComponent::HasComponent(v5) )
      UFG::TargetingSystemVehicleComponent::PropertiesOnActivate(v5);
    if ( UFG::TriggerRegion::HasComponent(v5) )
      UFG::TriggerRegion::PropertiesOnActivate(v5);
    if ( UFG::TurfCameraComponent::HasComponent(v5) )
      UFG::TurfCameraComponent::PropertiesOnActivate(v5);
    UFG::TSActorComponent::PropertiesOnActivateNew(v5, 0);
    UFG::VehicleAudioComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::VehicleOccupantComponent::HasComponent(v5) )
      UFG::VehicleOccupantComponent::PropertiesOnActivate(v5);
    if ( UFG::VehicleOwnershipComponent::HasComponent(v5) )
      UFG::VehicleOwnershipComponent::PropertiesOnActivate(v5);
    UFG::VehicleEffectsComponent::PropertiesOnActivateNew(v5, 0);
    UFG::VehiclesBlipComponent::PropertiesOnActivateNew(v5, 0);
    if ( UFG::VehicleSubjectComponent::HasComponent(v5) )
      UFG::VehicleSubjectComponent::PropertiesOnActivate(v5);
    UFG::WorldContextComponent::PropertiesOnActivateNew(v5, 0);
    if ( PropertyUtils::HasComponentPropertySet(v5, (UFG::qSymbol *)&SimSymX_propset_componentPowerManagement.mUID) )
      UFG::PowerManagementComponent::PropertiesOnActivate(v5);
    if ( UFG::AimingPlayerComponent::HasComponent(v5) )
      UFG::AimingPlayerComponent::PropertiesOnActivate(v5);
    if ( UFG::AIMarker::HasComponent(v5) )
      UFG::AIMarker::PropertiesOnActivate(v5);
    goto LABEL_327;
  }
  v41 = UFG::SimComponent::operator new(0x1A0ui64);
  pPriority = v41;
  if ( v41 )
  {
    UFG::TurfComponent::TurfComponent((UFG::TurfComponent *)v41, v5->m_NameUID);
    v6 = v42;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v74, v5->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v74, (UFG::SimComponent *)&v6->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v74);
  UFG::SimObjectModifier::~SimObjectModifier(&v74);
}

