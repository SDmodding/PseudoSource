// File Line: 168
// RVA: 0x532A60
UFG::ComponentTypeTable *__fastcall UFG::GetTypeTableProp()
{
  if ( (_S8_15 & 1) == 0 )
  {
    _S8_15 |= 1u;
    entries_Prop[0].uid = UFG::UELComponent::_UELComponentTypeUID;
    dword_1424187C4 = UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID;
    dword_1424187C8 = UFG::TransformNodeComponent::_TransformNodeComponentTypeUID;
    dword_1424187CC = UFG::TSActorComponent::_TSActorComponentTypeUID;
    dword_1424187D0 = UFG::SimObjectPropertiesComponent::_SimObjectPropertiesComponentTypeUID;
    dword_1424187D4 = UFG::PhantomVolumeComponent::_PhantomVolumeComponentTypeUID;
    dword_1424187D8 = UFG::ActionTreeComponent::_ActionTreeComponentTypeUID;
    dword_1424187DC = UFG::StreamedResourceComponent::_StreamedResourceComponentTypeUID;
    dword_1424187E0 = UFG::BaseAnimationComponent::_BaseAnimationComponentTypeUID;
    dword_1424187E4 = UFG::CompositeDrawableComponent::_CompositeDrawableComponentTypeUID;
    dword_1424187E8 = UFG::InterestPoint::_InterestPointTypeUID;
    dword_1424187EC = UFG::InventoryItemComponent::_InventoryItemComponentTypeUID;
    dword_1424187F0 = UFG::InterestPointUserComponent::_InterestPointUserComponentTypeUID;
    dword_1424187F4 = UFG::PropInteractComponent::_PropInteractComponentTypeUID;
  }
  return &type_table_Prop;
}

// File Line: 172
// RVA: 0x532A00
UFG::ComponentTypeTable *__fastcall UFG::GetTypeTableInterestPoint()
{
  if ( (_S9_15 & 1) == 0 )
  {
    _S9_15 |= 1u;
    entries_InterestPoint[0].uid = UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID;
    dword_142418804 = UFG::TransformNodeComponent::_TransformNodeComponentTypeUID;
    dword_142418808 = UFG::TSActorComponent::_TSActorComponentTypeUID;
    dword_14241880C = UFG::InterestPoint::_InterestPointTypeUID;
  }
  return &type_table_InterestPoint;
}

// File Line: 176
// RVA: 0x532780
UFG::ComponentTypeTable *__fastcall UFG::GetTypeTableCharacter()
{
  if ( (_S10_10 & 1) == 0 )
  {
    _S10_10 |= 1u;
    entries_Character[0].uid = UFG::UELComponent::_UELComponentTypeUID;
    dword_142418824 = UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID;
    dword_142418828 = UFG::TransformNodeComponent::_TransformNodeComponentTypeUID;
    dword_14241882C = UFG::SimObjectPropertiesComponent::_SimObjectPropertiesComponentTypeUID;
    dword_142418830 = UFG::TSActorComponent::_TSActorComponentTypeUID;
    dword_142418834 = UFG::AIScriptInterfaceComponent::_AIScriptInterfaceComponentTypeUID;
    dword_142418838 = UFG::HealthComponent::_HealthComponentTypeUID;
    dword_14241883C = UFG::ActionTreeComponent::_ActionTreeComponentTypeUID;
    dword_142418840 = UFG::MissionFailConditionComponent::_MissionFailConditionComponentTypeUID;
    dword_142418844 = UFG::BaseAnimationComponent::_BaseAnimationComponentTypeUID;
    dword_142418848 = UFG::StreamedResourceComponent::_StreamedResourceComponentTypeUID;
    dword_14241884C = UFG::StimulusReceiverComponent::_StimulusReceiverComponentTypeUID;
    dword_142418850 = UFG::InteractableComponent::_InteractableComponentTypeUID;
    dword_142418854 = UFG::AnimationLODComponent::_AnimationLODComponentTypeUID;
    dword_142418858 = UFG::CompositeDrawableComponent::_CompositeDrawableComponentTypeUID;
    dword_14241885C = UFG::HitReactionComponent::_HitReactionComponentTypeUID;
    dword_142418860 = UFG::EncounterUnitComponent::_EncounterUnitComponentTypeUID;
    dword_142418864 = UFG::CopUnitComponent::_CopUnitComponentTypeUID;
    dword_142418868 = UFG::PhantomVolumeComponent::_PhantomVolumeComponentTypeUID;
    dword_14241886C = UFG::AIActionTreeComponent::_AIActionTreeComponentTypeUID;
    dword_142418870 = UFG::TargetingSystemBaseComponent::_TargetingSystemBaseComponentTypeUID;
    dword_142418874 = UFG::CharacterControllerInterface::_CharacterControllerInterfaceTypeUID;
    dword_142418878 = UFG::AIEntityComponent::_AIEntityComponentTypeUID;
    dword_14241887C = UFG::VehicleDriverInterface::_VehicleDriverInterfaceTypeUID;
    dword_142418880 = UFG::RoadSpaceComponent::_RoadSpaceComponentTypeUID;
    dword_142418884 = UFG::InterestPoint::_InterestPointTypeUID;
    dword_142418888 = UFG::SensorComponent::_SensorComponentTypeUID;
    dword_14241888C = UFG::CharacterPhysicsComponent::_CharacterPhysicsComponentTypeUID;
    dword_142418890 = UFG::WorldContextComponent::_WorldContextComponentTypeUID;
    dword_142418894 = UFG::InteractorComponent::_InteractorComponentTypeUID;
    dword_142418898 = UFG::ActionTreeResourcesComponent::_ActionTreeResourcesComponentTypeUID;
    dword_14241889C = UFG::FacialActionTreeComponent::_FacialActionTreeComponentTypeUID;
    dword_1424188A0 = UFG::GetInFormationComponent::_GetInFormationComponentTypeUID;
    dword_1424188A4 = UFG::PedFormationManagerComponent::_PedFormationManagerComponentTypeUID;
    dword_1424188A8 = UFG::GetInPedFormationComponent::_GetInPedFormationComponentTypeUID;
    dword_1424188AC = UFG::HasAttackRequestComponent::_HasAttackRequestComponentTypeUID;
    dword_1424188B0 = UFG::NavComponent::_NavComponentTypeUID;
    dword_1424188B4 = UFG::CameraSubject::_CameraSubjectTypeUID;
    dword_1424188B8 = UFG::CharacterEffectsComponent::_CharacterEffectsComponentTypeUID;
    dword_1424188BC = UFG::InventoryComponent::_InventoryComponentTypeUID;
    dword_1424188C0 = UFG::HkAudioEntityComponent::_HkAudioEntityComponentTypeUID;
    dword_1424188C4 = UFG::DialogueAnimationComponent::_DialogueAnimationComponentTypeUID;
    dword_1424188C8 = UFG::RagdollComponent::_RagdollComponentTypeUID;
    dword_1424188CC = UFG::InterestPointUserComponent::_InterestPointUserComponentTypeUID;
    dword_1424188D0 = UFG::CharacterOccupantComponent::_CharacterOccupantComponentTypeUID;
    dword_1424188D4 = UFG::FaceActionComponent::_FaceActionComponentTypeUID;
    dword_1424188D8 = UFG::AttackRightsComponent::_AttackRightsComponentTypeUID;
    dword_1424188DC = UFG::AimingBaseComponent::_AimingBaseComponentTypeUID;
    dword_1424188E0 = UFG::PedSpawningInfo::_PedSpawningInfoTypeUID;
  }
  return &type_table_Character;
}

// File Line: 181
// RVA: 0x532B40
UFG::ComponentTypeTable *__fastcall UFG::GetTypeTableVehicle()
{
  if ( (_S11_7 & 1) == 0 )
  {
    _S11_7 |= 1u;
    entries_Vehicle[0].uid = UFG::UELComponent::_UELComponentTypeUID;
    dword_1424188F4 = UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID;
    dword_1424188F8 = UFG::TransformNodeComponent::_TransformNodeComponentTypeUID;
    dword_1424188FC = UFG::SimObjectPropertiesComponent::_SimObjectPropertiesComponentTypeUID;
    dword_142418900 = UFG::TSActorComponent::_TSActorComponentTypeUID;
    dword_142418904 = UFG::AIScriptInterfaceComponent::_AIScriptInterfaceComponentTypeUID;
    dword_142418908 = UFG::HealthComponent::_HealthComponentTypeUID;
    dword_14241890C = UFG::ActionTreeComponent::_ActionTreeComponentTypeUID;
    dword_142418910 = UFG::MissionFailConditionComponent::_MissionFailConditionComponentTypeUID;
    dword_142418914 = UFG::BaseAnimationComponent::_BaseAnimationComponentTypeUID;
    dword_142418918 = UFG::StreamedResourceComponent::_StreamedResourceComponentTypeUID;
    dword_14241891C = UFG::StimulusReceiverComponent::_StimulusReceiverComponentTypeUID;
    dword_142418920 = UFG::InteractableComponent::_InteractableComponentTypeUID;
    dword_142418924 = UFG::AnimationLODComponent::_AnimationLODComponentTypeUID;
    dword_142418928 = UFG::CompositeDrawableComponent::_CompositeDrawableComponentTypeUID;
    dword_14241892C = UFG::HitReactionComponent::_HitReactionComponentTypeUID;
    dword_142418930 = UFG::EncounterUnitComponent::_EncounterUnitComponentTypeUID;
    dword_142418934 = UFG::CopUnitComponent::_CopUnitComponentTypeUID;
    dword_142418938 = UFG::PhantomVolumeComponent::_PhantomVolumeComponentTypeUID;
    dword_14241893C = UFG::AIActionTreeComponent::_AIActionTreeComponentTypeUID;
    dword_142418940 = UFG::TargetingSystemBaseComponent::_TargetingSystemBaseComponentTypeUID;
    dword_142418944 = UFG::CharacterControllerInterface::_CharacterControllerInterfaceTypeUID;
    dword_142418948 = UFG::AIEntityComponent::_AIEntityComponentTypeUID;
    dword_14241894C = UFG::VehicleDriverInterface::_VehicleDriverInterfaceTypeUID;
    dword_142418950 = UFG::RoadSpaceComponent::_RoadSpaceComponentTypeUID;
    dword_142418954 = UFG::InterestPoint::_InterestPointTypeUID;
    dword_142418958 = UFG::SensorComponent::_SensorComponentTypeUID;
    dword_14241895C = UFG::AIOutlineComponent::_AIOutlineComponentTypeUID;
    dword_142418960 = UFG::HkAudioEntityComponent::_HkAudioEntityComponentTypeUID;
    dword_142418964 = UFG::VehiclesBlipComponent::_VehiclesBlipComponentTypeUID;
    dword_142418968 = UFG::VehicleOccupantComponent::_VehicleOccupantComponentTypeUID;
    dword_14241896C = UFG::CameraSubject::_CameraSubjectTypeUID;
    dword_142418970 = UFG::VehicleEffectsComponent::_VehicleEffectsComponentTypeUID;
    dword_142418974 = UFG::PropInteractComponent::_PropInteractComponentTypeUID;
    dword_142418978 = UFG::PhysicsMoverInterface::_PhysicsMoverInterfaceTypeUID;
    dword_14241897C = UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID;
  }
  return &type_table_Vehicle;
}

// File Line: 208
// RVA: 0x513DB0
UFG::CharacterAnimationComponent *__fastcall UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(
        UFG::SimObjectProp *this)
{
  UFG::CharacterAnimationComponent *result; // rax
  unsigned int m_TypeUID; // edx

  result = (UFG::CharacterAnimationComponent *)this->m_Components.p[8].m_pComponent;
  if ( !result )
    return 0i64;
  m_TypeUID = result->m_TypeUID;
  if ( ((m_TypeUID ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) != 0
    || (UFG::CharacterAnimationComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
  {
    return 0i64;
  }
  return result;
}

// File Line: 210
// RVA: 0x513B30
UFG::ActorAudioComponent *__fastcall UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(
        UFG::SimObjectCharacter *this)
{
  UFG::ActorAudioComponent *result; // rax
  unsigned int m_TypeUID; // edx

  result = (UFG::ActorAudioComponent *)this->m_Components.p[40].m_pComponent;
  if ( !result )
    return 0i64;
  m_TypeUID = result->m_TypeUID;
  if ( ((m_TypeUID ^ UFG::ActorAudioComponent::_TypeUID) & 0xFE000000) != 0
    || (UFG::ActorAudioComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
  {
    return 0i64;
  }
  return result;
}

// File Line: 211
// RVA: 0x513CF0
UFG::CarHumanDriverComponent *__fastcall UFG::SimObjectCVBase::GetComponent<UFG::CarHumanDriverComponent>(
        UFG::SimObjectCVBase *this)
{
  UFG::CarHumanDriverComponent *result; // rax
  unsigned int m_TypeUID; // edx

  result = (UFG::CarHumanDriverComponent *)this->m_Components.p[23].m_pComponent;
  if ( !result )
    return 0i64;
  m_TypeUID = result->m_TypeUID;
  if ( ((m_TypeUID ^ UFG::CarHumanDriverComponent::_TypeUID) & 0xFE000000) != 0
    || (UFG::CarHumanDriverComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
  {
    return 0i64;
  }
  return result;
}

// File Line: 212
// RVA: 0x5140F0
UFG::VehicleSubjectComponent *__fastcall UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(
        UFG::SimObjectVehicle *this)
{
  UFG::VehicleSubjectComponent *result; // rax
  unsigned int m_TypeUID; // edx

  result = (UFG::VehicleSubjectComponent *)this->m_Components.p[31].m_pComponent;
  if ( !result )
    return 0i64;
  m_TypeUID = result->m_TypeUID;
  if ( ((m_TypeUID ^ UFG::VehicleSubjectComponent::_TypeUID) & 0xFE000000) != 0
    || (UFG::VehicleSubjectComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
  {
    return 0i64;
  }
  return result;
}

// File Line: 222
// RVA: 0x518980
void __fastcall UFG::SimObjectGame::SimObjectGame(
        UFG::SimObjectGame *this,
        UFG::ComponentTypeTable *type_table,
        UFG::qSymbol *name)
{
  int mComponentTableEntryCount_low; // eax
  unsigned int size; // ecx
  int v7; // eax
  unsigned int v8; // ebx
  unsigned int capacity; // edx
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int i; // ecx
  UFG::SimComponentHolder *v13; // rax

  UFG::SimObject::SimObject(this, name);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectGame::`vftable;
  this->mComponentTableEntryCount = type_table->mEntryCount;
  this->mComponentTableEntries = type_table->mEntries;
  mComponentTableEntryCount_low = LOBYTE(this->mComponentTableEntryCount);
  this->m_ReservedComponentSlots = mComponentTableEntryCount_low;
  size = this->m_Components.size;
  v7 = mComponentTableEntryCount_low - size;
  if ( v7 <= 0 )
  {
    v11 = -v7;
    if ( v11 )
    {
      if ( v11 < size )
        this->m_Components.size = size - v11;
      else
        this->m_Components.size = 0;
    }
  }
  else
  {
    v8 = size + v7;
    capacity = this->m_Components.capacity;
    if ( size + v7 > capacity )
    {
      if ( capacity )
        v10 = 2 * capacity;
      else
        v10 = 1;
      for ( ; v10 < v8; v10 *= 2 )
        ;
      if ( v10 - v8 > 0x10000 )
        v10 = v8 + 0x10000;
      UFG::qArray<UFG::SimComponentHolder,0>::Reallocate(&this->m_Components, v10, "SimObjectGame");
    }
    this->m_Components.size = v8;
  }
  for ( i = 0; i < (unsigned __int8)this->m_ReservedComponentSlots; ++i )
  {
    v13 = &this->m_Components.p[i];
    v13->m_pComponent = 0i64;
    v13->m_TypeUID = -1;
  }
}

// File Line: 237
// RVA: 0x522350
void __fastcall UFG::SimObjectGame::Attach(
        UFG::SimObjectGame *this,
        UFG::TransformNodeComponent *component,
        unsigned int index)
{
  unsigned int mComponentTableEntryCount; // r10d
  unsigned int v5; // r9d
  unsigned int m_TypeUID; // edi
  UFG::ComponentTypeEntry *mComponentTableEntries; // rcx

  if ( index == -1 )
  {
    mComponentTableEntryCount = this->mComponentTableEntryCount;
    v5 = 0;
    m_TypeUID = component->m_TypeUID;
    if ( mComponentTableEntryCount )
    {
      mComponentTableEntries = this->mComponentTableEntries;
      while ( (m_TypeUID & 0xFE000000) != (mComponentTableEntries->uid & 0xFE000000)
           || (mComponentTableEntries->uid & ~m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v5;
        ++mComponentTableEntries;
        if ( v5 >= mComponentTableEntryCount )
          goto LABEL_9;
      }
      index = v5;
    }
  }
LABEL_9:
  UFG::SimObject::Attach(this, component, index);
}

// File Line: 258
// RVA: 0x5255C0
// attributes: thunk
void __fastcall UFG::SimObjectGame::Detach(UFG::SimObjectGame *this, UFG::TransformNodeComponent *component)
{
  UFG::SimObject::Detach(this, component);
}

// File Line: 266
// RVA: 0x52BBC0
UFG::SimComponent *__fastcall UFG::SimObjectGame::GetComponentOfTypeHK(UFG::SimObjectGame *this, unsigned int type_uid)
{
  unsigned int mComponentTableEntryCount; // r9d
  unsigned int size; // r10d
  UFG::SimComponentHolder *i; // r8

  mComponentTableEntryCount = this->mComponentTableEntryCount;
  size = this->m_Components.size;
  if ( mComponentTableEntryCount >= size )
    return 0i64;
  for ( i = &this->m_Components.p[mComponentTableEntryCount];
        (i->m_TypeUID & 0xFE000000) != (type_uid & 0xFE000000) || (type_uid & ~i->m_TypeUID & 0x1FFFFFF) != 0;
        ++i )
  {
    if ( ++mComponentTableEntryCount >= size )
      return 0i64;
  }
  return i->m_pComponent;
}

