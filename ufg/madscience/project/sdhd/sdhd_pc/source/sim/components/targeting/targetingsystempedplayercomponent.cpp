// File Line: 98
// RVA: 0x1544180
__int64 dynamic_initializer_for__UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList__);
}

// File Line: 99
// RVA: 0x52CBB0
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemPedPlayerComponent::GetDesc(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  return &UFG::TargetingSystemPedPlayerComponent::_TypeIDesc;
}

// File Line: 103
// RVA: 0x1543B90
__int64 dynamic_initializer_for__UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap__()
{
  __int64 v0; // rcx
  __int64 size; // rax

  v0 = 91i64;
  size = UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[size] = 0;
    size = ++UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.size;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap__);
}

// File Line: 192
// RVA: 0x52A670
signed __int64 __fastcall UFG::GetActionMostUsedIndex_Grapple()
{
  signed __int64 result; // rax

  if ( (_S35_0 & 1) != 0 )
    return index;
  _S35_0 |= 1u;
  if ( (_S34 & 1) == 0 )
  {
    _S34 |= 1u;
    actionID_0.mUID = UFG::qStringHashUpper32("Grapple", -1);
  }
  result = GetMostUsedIndex(actionID_0.mUID);
  index = result;
  return result;
}

// File Line: 193
// RVA: 0x52A6E0
signed __int64 __fastcall UFG::GetActionMostUsedIndex_Hostage()
{
  signed __int64 result; // rax

  if ( (_S37_0 & 1) != 0 )
    return index_0;
  _S37_0 |= 1u;
  if ( (_S36_0 & 1) == 0 )
  {
    _S36_0 |= 1u;
    actionID_1.mUID = UFG::qStringHashUpper32("Hostage", -1);
  }
  result = GetMostUsedIndex(actionID_1.mUID);
  index_0 = result;
  return result;
}

// File Line: 194
// RVA: 0x52A510
ActionID *__fastcall UFG::GetActionID_DismountShoot()
{
  if ( (_S38_0 & 1) == 0 )
  {
    _S38_0 |= 1u;
    actionID_2.mUID = UFG::qStringHashUpper32("DismountShoot", -1);
  }
  return &actionID_2;
}

// File Line: 199
// RVA: 0x550EF0
void UFG::TargetingSystemPedPlayerComponent::StaticInit(void)
{
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[2] = UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[4] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                     + 1;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[5] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                     + 2;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[6] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                     + 3;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[7] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                     + 4;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[8] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                     + 5;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[9] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                     + 6;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[13] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 7;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[14] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 8;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[15] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 9;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[16] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 10;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[17] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 11;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[18] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 12;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[19] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 13;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[20] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 14;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[21] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 15;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[22] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 16;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[23] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 17;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[24] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 18;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[25] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 19;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[26] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 20;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[27] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 21;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[28] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 22;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[46] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 23;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[55] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 24;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[56] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 25;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[68] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 26;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[36] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 27;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[76] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 28;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[78] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 29;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[79] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 30;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[80] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 31;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[38] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 32;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[39] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 33;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[40] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 34;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[41] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 35;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[42] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 36;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[43] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 37;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[58] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 38;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[31] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 39;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[1] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                     + 40;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[77] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 41;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[29] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 42;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[30] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 43;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[3] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                     + 44;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[44] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 45;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[45] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 46;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[47] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 47;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[48] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 48;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[49] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 49;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[50] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 50;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[51] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 51;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[52] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 52;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[53] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 53;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[57] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 54;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[81] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 55;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[33] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 56;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[34] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 57;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[82] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 58;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[83] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 59;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[84] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 60;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[85] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 61;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[86] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 62;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[87] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 63;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[88] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 64;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[89] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 65;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[90] = LOBYTE(UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                      + 66;
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes += 67;
}

// File Line: 347
// RVA: 0x5358E0
bool __fastcall UFG::TargetingSystemPedPlayerComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentTargetingSystemPedPlayer,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 353
// RVA: 0x545AD0
UFG::SimComponent *__fastcall UFG::TargetingSystemPedPlayerComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x2D38ui64, "TargetingSystemPedPlayerComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::TargetingSystemPedPlayerComponent::TargetingSystemPedPlayerComponent(
      (UFG::TargetingSystemPedPlayerComponent *)v3,
      pSceneObj->m_NameUID,
      mpWritableProperties,
      0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v9 = 20;
  else
    v9 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return v6;
}

// File Line: 369
// RVA: 0x519DC0
void __fastcall UFG::TargetingSystemPedPlayerComponent::TargetingSystemPedPlayerComponent(
        UFG::TargetingSystemPedPlayerComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *mPrev; // rax
  char v6; // cl

  UFG::TargetingSystemPedBaseComponent::TargetingSystemPedBaseComponent(
    this,
    &UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap,
    name_uid,
    properties);
  this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>::mPrev = &this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>;
  this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>::mNext = &this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>;
  this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedPlayerComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedPlayerComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&this->m_pCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0>::RebindingComponentHandle<UFG::AimingPlayerComponent,0>(&this->m_pAimingPlayerComponent);
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::RebindingComponentHandle<UFG::AttackRightsComponent,0>(&this->m_pAttackRightsComponent);
  this->m_RagdollTarget.mPrev = &this->m_RagdollTarget;
  this->m_RagdollTarget.mNext = &this->m_RagdollTarget;
  this->m_RagdollTarget.m_pPointer = 0i64;
  this->m_FocusTargetsGrappleTarget.mPrev = &this->m_FocusTargetsGrappleTarget;
  this->m_FocusTargetsGrappleTarget.mNext = &this->m_FocusTargetsGrappleTarget;
  this->m_FocusTargetsGrappleTarget.m_pPointer = 0i64;
  this->m_pVehicleFocusTarget.mPrev = &this->m_pVehicleFocusTarget;
  this->m_pVehicleFocusTarget.mNext = &this->m_pVehicleFocusTarget;
  this->m_pVehicleFocusTarget.m_pPointer = 0i64;
  this->m_pFocusModeOverrideSimObject.mPrev = &this->m_pFocusModeOverrideSimObject;
  this->m_pFocusModeOverrideSimObject.mNext = &this->m_pFocusModeOverrideSimObject;
  this->m_pFocusModeOverrideSimObject.m_pPointer = 0i64;
  this->m_pOccupantOfVehicle.mPrev = &this->m_pOccupantOfVehicle;
  this->m_pOccupantOfVehicle.mNext = &this->m_pOccupantOfVehicle;
  this->m_pOccupantOfVehicle.m_pPointer = 0i64;
  this->m_pVehicleClosestPointSimObject.mPrev = &this->m_pVehicleClosestPointSimObject;
  this->m_pVehicleClosestPointSimObject.mNext = &this->m_pVehicleClosestPointSimObject;
  this->m_pVehicleClosestPointSimObject.m_pPointer = 0i64;
  this->m_pVehicleClosestPointTNC.mPrev = &this->m_pVehicleClosestPointTNC;
  this->m_pVehicleClosestPointTNC.mNext = &this->m_pVehicleClosestPointTNC;
  this->m_pVehicleClosestPointTNC.m_pPointer = 0i64;
  this->m_RimLighting.m_bEnabled = 0;
  this->m_RimLighting.m_TargetType = eTARGET_TYPE_INVALID;
  this->m_RimLighting.m_Target.mPrev = &this->m_RimLighting.m_Target;
  this->m_RimLighting.m_Target.mNext = &this->m_RimLighting.m_Target;
  this->m_RimLighting.m_Target.m_pPointer = 0i64;
  `eh vector constructor iterator(
    this->m_VehicleCharacterRagdolls,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  this->m_CloseTargetsList.size = 0;
  mPrev = UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList.mNode.mPrev;
  UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>;
  this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>::mNext = (UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *)&UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList;
  UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList.mNode.mPrev = &this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::TargetingSystemPedPlayerComponent::_TargetingSystemPedPlayerComponentTypeUID,
    "TargetingSystemPedPlayerComponent");
  v6 = s_bStaticallyInitialized;
  if ( !s_bStaticallyInitialized )
    v6 = 1;
  s_bStaticallyInitialized = v6;
  UFG::TargetingSystemPedPlayerComponent::initialize(this);
}

// File Line: 389
// RVA: 0x51D220
void __fastcall UFG::TargetingSystemPedPlayerComponent::~TargetingSystemPedPlayerComponent(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *v2; // rdi
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *mPrev; // rcx
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_Target; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pVehicleClosestPointTNC; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pVehicleClosestPointSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pOccupantOfVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pFocusModeOverrideSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_m_pVehicleFocusTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *p_m_FocusTargetsGrappleTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v38; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *p_m_RagdollTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v43; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v44; // rax
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *v45; // rcx
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *v46; // rax

  this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedPlayerComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedPlayerComponent::`vftable{for `UFG::UpdateInterface};
  UFG::TargetingSystemPedPlayerComponent::shutdown(this);
  if ( this == UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentpCurrentIterator )
    UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentpCurrentIterator = (UFG::TargetingSystemPedPlayerComponent *)&this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>::mPrev[-174].mNext;
  v2 = &this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>;
  mPrev = this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>::mPrev;
  mNext = this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>::mPrev = &this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>;
  this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>::mNext = &this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>;
  this->m_CloseTargetsList.size = 0;
  `eh vector destructor iterator(
    this->m_VehicleCharacterRagdolls,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  p_m_Target = &this->m_RimLighting.m_Target;
  if ( this->m_RimLighting.m_Target.m_pPointer )
  {
    v6 = p_m_Target->mPrev;
    v7 = this->m_RimLighting.m_Target.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_Target->mPrev = p_m_Target;
    this->m_RimLighting.m_Target.mNext = &this->m_RimLighting.m_Target;
  }
  this->m_RimLighting.m_Target.m_pPointer = 0i64;
  v8 = p_m_Target->mPrev;
  v9 = this->m_RimLighting.m_Target.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_m_Target->mPrev = p_m_Target;
  this->m_RimLighting.m_Target.mNext = &this->m_RimLighting.m_Target;
  p_m_pVehicleClosestPointTNC = &this->m_pVehicleClosestPointTNC;
  if ( this->m_pVehicleClosestPointTNC.m_pPointer )
  {
    v11 = p_m_pVehicleClosestPointTNC->mPrev;
    v12 = this->m_pVehicleClosestPointTNC.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_m_pVehicleClosestPointTNC->mPrev = p_m_pVehicleClosestPointTNC;
    this->m_pVehicleClosestPointTNC.mNext = &this->m_pVehicleClosestPointTNC;
  }
  this->m_pVehicleClosestPointTNC.m_pPointer = 0i64;
  v13 = p_m_pVehicleClosestPointTNC->mPrev;
  v14 = this->m_pVehicleClosestPointTNC.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_m_pVehicleClosestPointTNC->mPrev = p_m_pVehicleClosestPointTNC;
  this->m_pVehicleClosestPointTNC.mNext = &this->m_pVehicleClosestPointTNC;
  p_m_pVehicleClosestPointSimObject = &this->m_pVehicleClosestPointSimObject;
  if ( this->m_pVehicleClosestPointSimObject.m_pPointer )
  {
    v16 = p_m_pVehicleClosestPointSimObject->mPrev;
    v17 = this->m_pVehicleClosestPointSimObject.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    p_m_pVehicleClosestPointSimObject->mPrev = p_m_pVehicleClosestPointSimObject;
    this->m_pVehicleClosestPointSimObject.mNext = &this->m_pVehicleClosestPointSimObject;
  }
  this->m_pVehicleClosestPointSimObject.m_pPointer = 0i64;
  v18 = p_m_pVehicleClosestPointSimObject->mPrev;
  v19 = this->m_pVehicleClosestPointSimObject.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  p_m_pVehicleClosestPointSimObject->mPrev = p_m_pVehicleClosestPointSimObject;
  this->m_pVehicleClosestPointSimObject.mNext = &this->m_pVehicleClosestPointSimObject;
  p_m_pOccupantOfVehicle = &this->m_pOccupantOfVehicle;
  if ( this->m_pOccupantOfVehicle.m_pPointer )
  {
    v21 = p_m_pOccupantOfVehicle->mPrev;
    v22 = this->m_pOccupantOfVehicle.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    p_m_pOccupantOfVehicle->mPrev = p_m_pOccupantOfVehicle;
    this->m_pOccupantOfVehicle.mNext = &this->m_pOccupantOfVehicle;
  }
  this->m_pOccupantOfVehicle.m_pPointer = 0i64;
  v23 = p_m_pOccupantOfVehicle->mPrev;
  v24 = this->m_pOccupantOfVehicle.mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  p_m_pOccupantOfVehicle->mPrev = p_m_pOccupantOfVehicle;
  this->m_pOccupantOfVehicle.mNext = &this->m_pOccupantOfVehicle;
  p_m_pFocusModeOverrideSimObject = &this->m_pFocusModeOverrideSimObject;
  if ( this->m_pFocusModeOverrideSimObject.m_pPointer )
  {
    v26 = p_m_pFocusModeOverrideSimObject->mPrev;
    v27 = this->m_pFocusModeOverrideSimObject.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    p_m_pFocusModeOverrideSimObject->mPrev = p_m_pFocusModeOverrideSimObject;
    this->m_pFocusModeOverrideSimObject.mNext = &this->m_pFocusModeOverrideSimObject;
  }
  this->m_pFocusModeOverrideSimObject.m_pPointer = 0i64;
  v28 = p_m_pFocusModeOverrideSimObject->mPrev;
  v29 = this->m_pFocusModeOverrideSimObject.mNext;
  v28->mNext = v29;
  v29->mPrev = v28;
  p_m_pFocusModeOverrideSimObject->mPrev = p_m_pFocusModeOverrideSimObject;
  this->m_pFocusModeOverrideSimObject.mNext = &this->m_pFocusModeOverrideSimObject;
  p_m_pVehicleFocusTarget = &this->m_pVehicleFocusTarget;
  if ( this->m_pVehicleFocusTarget.m_pPointer )
  {
    v31 = p_m_pVehicleFocusTarget->mPrev;
    v32 = this->m_pVehicleFocusTarget.mNext;
    v31->mNext = v32;
    v32->mPrev = v31;
    p_m_pVehicleFocusTarget->mPrev = p_m_pVehicleFocusTarget;
    this->m_pVehicleFocusTarget.mNext = &this->m_pVehicleFocusTarget;
  }
  this->m_pVehicleFocusTarget.m_pPointer = 0i64;
  v33 = p_m_pVehicleFocusTarget->mPrev;
  v34 = this->m_pVehicleFocusTarget.mNext;
  v33->mNext = v34;
  v34->mPrev = v33;
  p_m_pVehicleFocusTarget->mPrev = p_m_pVehicleFocusTarget;
  this->m_pVehicleFocusTarget.mNext = &this->m_pVehicleFocusTarget;
  p_m_FocusTargetsGrappleTarget = &this->m_FocusTargetsGrappleTarget;
  if ( this->m_FocusTargetsGrappleTarget.m_pPointer )
  {
    v36 = p_m_FocusTargetsGrappleTarget->mPrev;
    v37 = this->m_FocusTargetsGrappleTarget.mNext;
    v36->mNext = v37;
    v37->mPrev = v36;
    p_m_FocusTargetsGrappleTarget->mPrev = p_m_FocusTargetsGrappleTarget;
    this->m_FocusTargetsGrappleTarget.mNext = &this->m_FocusTargetsGrappleTarget;
  }
  this->m_FocusTargetsGrappleTarget.m_pPointer = 0i64;
  v38 = p_m_FocusTargetsGrappleTarget->mPrev;
  v39 = this->m_FocusTargetsGrappleTarget.mNext;
  v38->mNext = v39;
  v39->mPrev = v38;
  p_m_FocusTargetsGrappleTarget->mPrev = p_m_FocusTargetsGrappleTarget;
  this->m_FocusTargetsGrappleTarget.mNext = &this->m_FocusTargetsGrappleTarget;
  p_m_RagdollTarget = &this->m_RagdollTarget;
  if ( this->m_RagdollTarget.m_pPointer )
  {
    v41 = p_m_RagdollTarget->mPrev;
    v42 = this->m_RagdollTarget.mNext;
    v41->mNext = v42;
    v42->mPrev = v41;
    p_m_RagdollTarget->mPrev = p_m_RagdollTarget;
    this->m_RagdollTarget.mNext = &this->m_RagdollTarget;
  }
  this->m_RagdollTarget.m_pPointer = 0i64;
  v43 = p_m_RagdollTarget->mPrev;
  v44 = this->m_RagdollTarget.mNext;
  v43->mNext = v44;
  v44->mPrev = v43;
  p_m_RagdollTarget->mPrev = p_m_RagdollTarget;
  this->m_RagdollTarget.mNext = &this->m_RagdollTarget;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAttackRightsComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAimingPlayerComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pCharacterAnimationComponent);
  v45 = v2->mPrev;
  v46 = this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>::mNext;
  v45->mNext = v46;
  v46->mPrev = v45;
  v2->mPrev = v2;
  this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>::mNext = &this->UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent>;
  UFG::TargetingSystemPedBaseComponent::~TargetingSystemPedBaseComponent(this);
}

// File Line: 397
// RVA: 0x15499C0
__int64 UFG::_dynamic_initializer_for__driverFaceActionSceneObjectSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("object-physical-character-taxi_driver_faceaction", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::driverFaceActionSceneObjectSymbol, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__driverFaceActionSceneObjectSymbol__);
}

// File Line: 399
// RVA: 0x1544560
__int64 UFG::_dynamic_initializer_for__DriverFaceActionComponent_Hash__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DriverFaceActionComponent", 0xFFFFFFFF);
  UFG::DriverFaceActionComponent_Hash = result;
  return result;
}

// File Line: 400
// RVA: 0x1544540
__int64 UFG::_dynamic_initializer_for__ClosestVehiclePointTransform_Hash__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ClosestVehiclePointTransform", 0xFFFFFFFF);
  UFG::ClosestVehiclePointTransform_Hash = result;
  return result;
}

// File Line: 403
// RVA: 0x56A210
void __fastcall UFG::TargetingSystemPedPlayerComponent::initialize(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *v2; // rsi
  UFG::qVector3 *p_m_vDirectionalTargetingIntention; // r15
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 *p_m_vAimTargetingIntention; // r12
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::FaceActionComponent *v13; // rax
  UFG::FaceActionComponent *v14; // r14
  UFG::SceneObjectProperties *m_pDriverSceneObjectProperties; // rbx
  UFG::SceneObjectProperties *v16; // rax
  UFG::qPropertySet *mpWritableProperties; // r14
  unsigned int v18; // ebx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v20; // rax
  UFG::qMemoryPool *v21; // rax
  UFG::allocator::free_link *v22; // rax
  UFG::SimObject *v23; // rax
  UFG::SimObject *v24; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pVehicleClosestPointSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qMemoryPool *v29; // rax
  UFG::allocator::free_link *v30; // rax
  UFG::SimComponent *v31; // rax
  UFG::SimObject *m_pPointer; // rdx
  __int16 m_Flags; // cx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pVehicleClosestPointTNC; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rax
  unsigned __int8 v38; // cl
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v39; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v40; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v41; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v42; // rax
  TracksEnumBinding<unsigned long> v43; // [rsp+38h] [rbp-41h] BYREF
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+58h] [rbp-21h] BYREF
  UFG::SimObjectModifier v45; // [rsp+78h] [rbp-1h] BYREF
  UFG::qSymbol result; // [rsp+E0h] [rbp+67h] BYREF
  UFG::qSymbol name; // [rsp+E8h] [rbp+6Fh] BYREF
  UFG::allocator::free_link *v48; // [rsp+F0h] [rbp+77h]

  *(_QWORD *)&this->m_bIsAimingActive = 0i64;
  *(_DWORD *)&this->m_bFocusTargetIsHostile = 0;
  this->m_bTargetingFreeAimAssistance = 0;
  v2 = 0i64;
  *(_QWORD *)&this->m_eOverrideDesiredFocusMode = 0i64;
  *(_QWORD *)&this->m_eFocusMode = 0i64;
  this->m_fTargetingIntentionIdleTime = 1000.0;
  p_m_vDirectionalTargetingIntention = &this->m_vDirectionalTargetingIntention;
  y = UFG::qVector3::msAxisX.y;
  z = UFG::qVector3::msAxisX.z;
  this->m_vDirectionalTargetingIntention.x = UFG::qVector3::msAxisX.x;
  this->m_vDirectionalTargetingIntention.y = y;
  this->m_vDirectionalTargetingIntention.z = z;
  p_m_vAimTargetingIntention = &this->m_vAimTargetingIntention;
  v7 = UFG::qVector3::msAxisX.y;
  v8 = UFG::qVector3::msAxisX.z;
  this->m_vAimTargetingIntention.x = UFG::qVector3::msAxisX.x;
  this->m_vAimTargetingIntention.y = v7;
  this->m_vAimTargetingIntention.z = v8;
  this->m_bAimInputRaw = 0;
  v9 = UFG::qVector2::msZero.y;
  this->m_vAimInput.x = UFG::qVector2::msZero.x;
  this->m_vAimInput.y = v9;
  this->m_vAimInputDir = (UFG::qVector2)1065353216i64;
  v10 = UFG::qVector2::msZero.y;
  this->m_vLockedFreeAimInput.x = UFG::qVector2::msZero.x;
  this->m_vLockedFreeAimInput.y = v10;
  this->m_fAimInputLength = 0.0;
  *(_DWORD *)&this->m_bHasPriorityTarget = 0;
  this->m_fTimeSinceStartedInput = UFG::TargetingSystemPedPlayerComponent::ms_fTimeToTargetCycle;
  this->m_bTargetCycleDirectionLeft = 0;
  this->m_iVisibilityFromBoneID = -1;
  this->m_pDriverSceneObjectProperties = UFG::SceneObjectProperties::Create(
                                           &UFG::driverFaceActionSceneObjectSymbol,
                                           0i64,
                                           &UFG::driverFaceActionSceneObjectSymbol);
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v12 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x520ui64, "FaceActionComponent", 0i64, 1u);
  v48 = v12;
  if ( v12 )
  {
    UFG::FaceActionComponent::FaceActionComponent((UFG::FaceActionComponent *)v12, UFG::DriverFaceActionComponent_Hash);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  this->m_pDriverFaceActionComponent = v14;
  m_pDriverSceneObjectProperties = this->m_pDriverSceneObjectProperties;
  UFG::FaceActionComponent::ResetState(v14);
  v14->vfptr[12].__vecDelDtor(v14, (unsigned int)m_pDriverSceneObjectProperties);
  this->m_pDriverFaceActionComponent->m_Flags &= ~8u;
  v16 = this->m_pDriverSceneObjectProperties;
  mpWritableProperties = v16->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = v16->mpConstProperties;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  v18 = -1;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)UFG::qPropertySet::Get<UFG::qSymbol>(
                                                   mpWritableProperties,
                                                   (UFG::qArray<unsigned long,0> *)&SimSym_FaceAction,
                                                   DEPTH_RECURSE)->mUID;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gFaceActionTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gFaceActionTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = UFG::gFaceActionTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gFaceActionTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &UFG::gFaceActionTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gFaceActionTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  this->m_eDriverFaceActionType = pTrackEnumBinding.m_EnumValue;
  v43.mPrev = &v43;
  v43.mNext = &v43;
  v43.m_EnumSymbol.mUID = -1;
  v43.m_EnumSymbol = (UFG::qSymbol)UFG::qPropertySet::Get<UFG::qSymbol>(
                                     mpWritableProperties,
                                     (UFG::qArray<unsigned long,0> *)&SimSym_SellableItem,
                                     DEPTH_RECURSE)->mUID;
  *(_QWORD *)&v43.m_EnumValue = 0i64;
  v43.m_uEnumUID = 0;
  if ( UFG::gInventoryItemTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gInventoryItemTracksEnum, &v43);
  }
  else
  {
    v20 = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &v43;
    v43.mPrev = v20;
    v43.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &v43;
  }
  this->m_eDriverSellableItemType = v43.m_EnumValue;
  this->m_eDriverOriginalSellableItemType = eINVENTORY_ITEM_INVALID;
  this->m_ConeToIntentionMap[0] = &this->m_vTargetingIntention;
  this->m_ConeToIntentionMap[2] = &this->m_vTargetingIntention;
  this->m_ConeToIntentionMap[3] = &this->m_vTargetingIntention;
  this->m_ConeToIntentionMap[4] = &this->m_vTargetingIntention;
  this->m_ConeToIntentionMap[1] = p_m_vAimTargetingIntention;
  this->m_ConeToIntentionMap[5] = p_m_vDirectionalTargetingIntention;
  this->m_fMinimumTargetDistanceSquared = 2500.0;
  UFG::qSymbol::create_from_string(&result, "TargetingSystemPedPlayer_ClosestVehiclePoint");
  UFG::Simulation::GenerateUniqueName(&UFG::gSim, &name, &result);
  v21 = UFG::GetSimulationMemoryPool();
  v22 = UFG::qMemoryPool::Allocate(v21, 0x80ui64, "TargetingSystemPedPlayerComponent.ClosestVehiclePoint", 0i64, 1u);
  v48 = v22;
  if ( v22 )
  {
    UFG::SimObject::SimObject((UFG::SimObject *)v22, &name);
    v24 = v23;
  }
  else
  {
    v24 = 0i64;
  }
  p_m_pVehicleClosestPointSimObject = &this->m_pVehicleClosestPointSimObject;
  if ( this->m_pVehicleClosestPointSimObject.m_pPointer )
  {
    v26 = p_m_pVehicleClosestPointSimObject->mPrev;
    mNext = this->m_pVehicleClosestPointSimObject.mNext;
    v26->mNext = mNext;
    mNext->mPrev = v26;
    p_m_pVehicleClosestPointSimObject->mPrev = p_m_pVehicleClosestPointSimObject;
    this->m_pVehicleClosestPointSimObject.mNext = &this->m_pVehicleClosestPointSimObject;
  }
  this->m_pVehicleClosestPointSimObject.m_pPointer = v24;
  if ( v24 )
  {
    v28 = v24->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v28->mNext = p_m_pVehicleClosestPointSimObject;
    p_m_pVehicleClosestPointSimObject->mPrev = v28;
    this->m_pVehicleClosestPointSimObject.mNext = &v24->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v24->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pVehicleClosestPointSimObject;
  }
  v29 = UFG::GetSimulationMemoryPool();
  v30 = UFG::qMemoryPool::Allocate(v29, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  v48 = v30;
  if ( v30 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent(
      (UFG::TransformNodeComponent *)v30,
      UFG::ClosestVehiclePointTransform_Hash,
      0i64,
      0);
    v2 = v31;
  }
  UFG::Simulation::TrackSimObject(&UFG::gSim, this->m_pVehicleClosestPointSimObject.m_pPointer);
  m_pPointer = this->m_pVehicleClosestPointSimObject.m_pPointer;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    v18 = 2;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      v18 = 2;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      v18 = 1;
    }
  }
  else
  {
    v18 = 2;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v45, m_pPointer, 1);
  UFG::SimObjectModifier::AttachComponent(&v45, v2, v18);
  UFG::SimObjectModifier::Close(&v45);
  UFG::SimObjectModifier::~SimObjectModifier(&v45);
  p_m_pVehicleClosestPointTNC = &this->m_pVehicleClosestPointTNC;
  if ( this->m_pVehicleClosestPointTNC.m_pPointer )
  {
    v35 = p_m_pVehicleClosestPointTNC->mPrev;
    v36 = this->m_pVehicleClosestPointTNC.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    p_m_pVehicleClosestPointTNC->mPrev = p_m_pVehicleClosestPointTNC;
    this->m_pVehicleClosestPointTNC.mNext = &this->m_pVehicleClosestPointTNC;
  }
  this->m_pVehicleClosestPointTNC.m_pPointer = v2;
  if ( v2 )
  {
    v37 = v2->m_SafePointerList.mNode.mPrev;
    v37->mNext = p_m_pVehicleClosestPointTNC;
    p_m_pVehicleClosestPointTNC->mPrev = v37;
    this->m_pVehicleClosestPointTNC.mNext = &v2->m_SafePointerList.mNode;
    v2->m_SafePointerList.mNode.mPrev = p_m_pVehicleClosestPointTNC;
  }
  if ( this->m_pAimingPlayerComponent.m_pSimComponent )
  {
    v38 = this->m_pTargetingMap->m_Map.p[3];
    if ( v38 )
      UFG::TargetingSimObject::SetTarget(
        &this->m_pTargets[v38],
        (UFG::SimObject *)this->m_pAimingPlayerComponent.m_pSimComponent[13].m_BoundComponentHandles.mNode.mPrev);
  }
  v39 = v43.mPrev;
  v40 = v43.mNext;
  v43.mPrev->mNext = v43.mNext;
  v40->mPrev = v39;
  v41 = pTrackEnumBinding.mPrev;
  v42 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v42->mPrev = v41;
}TrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v42->mPrev = v41;
}

// File Line: 488
// RVA: 0x56D740
void __fastcall UFG::TargetingSystemPedPlayerComponent::shutdown(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::FaceActionComponent *m_pDriverFaceActionComponent; // rcx
  UFG::SceneObjectProperties *m_pDriverSceneObjectProperties; // rcx
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *p_m_RagdollTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_m_pVehicleFocusTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pFocusModeOverrideSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pOccupantOfVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::SimObject *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pVehicleClosestPointSimObject; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax

  if ( (this->m_pDriverFaceActionComponent->m_Flags & 1) != 0 )
    UFG::TargetingSystemPedPlayerComponent::deattachTransitDriverFaceComponent(this);
  m_pDriverFaceActionComponent = this->m_pDriverFaceActionComponent;
  if ( m_pDriverFaceActionComponent )
    m_pDriverFaceActionComponent->vfptr->__vecDelDtor(m_pDriverFaceActionComponent, 1u);
  m_pDriverSceneObjectProperties = this->m_pDriverSceneObjectProperties;
  this->m_pDriverFaceActionComponent = 0i64;
  UFG::SceneObjectProperties::Deactivate(m_pDriverSceneObjectProperties);
  p_m_RagdollTarget = &this->m_RagdollTarget;
  this->m_pDriverSceneObjectProperties = 0i64;
  if ( this->m_RagdollTarget.m_pPointer )
  {
    mPrev = p_m_RagdollTarget->mPrev;
    mNext = this->m_RagdollTarget.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_RagdollTarget->mPrev = p_m_RagdollTarget;
    this->m_RagdollTarget.mNext = &this->m_RagdollTarget;
  }
  this->m_RagdollTarget.m_pPointer = 0i64;
  p_m_pVehicleFocusTarget = &this->m_pVehicleFocusTarget;
  this->m_RimLighting.m_bEnabled = 0;
  if ( this->m_pVehicleFocusTarget.m_pPointer )
  {
    v8 = p_m_pVehicleFocusTarget->mPrev;
    v9 = this->m_pVehicleFocusTarget.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pVehicleFocusTarget->mPrev = p_m_pVehicleFocusTarget;
    this->m_pVehicleFocusTarget.mNext = &this->m_pVehicleFocusTarget;
  }
  this->m_pVehicleFocusTarget.m_pPointer = 0i64;
  p_m_pFocusModeOverrideSimObject = &this->m_pFocusModeOverrideSimObject;
  if ( this->m_pFocusModeOverrideSimObject.m_pPointer )
  {
    v11 = p_m_pFocusModeOverrideSimObject->mPrev;
    v12 = this->m_pFocusModeOverrideSimObject.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_m_pFocusModeOverrideSimObject->mPrev = p_m_pFocusModeOverrideSimObject;
    this->m_pFocusModeOverrideSimObject.mNext = &this->m_pFocusModeOverrideSimObject;
  }
  this->m_pFocusModeOverrideSimObject.m_pPointer = 0i64;
  p_m_pOccupantOfVehicle = &this->m_pOccupantOfVehicle;
  if ( this->m_pOccupantOfVehicle.m_pPointer )
  {
    v14 = p_m_pOccupantOfVehicle->mPrev;
    v15 = this->m_pOccupantOfVehicle.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    p_m_pOccupantOfVehicle->mPrev = p_m_pOccupantOfVehicle;
    this->m_pOccupantOfVehicle.mNext = &this->m_pOccupantOfVehicle;
  }
  this->m_pOccupantOfVehicle.m_pPointer = 0i64;
  m_pPointer = this->m_pVehicleClosestPointSimObject.m_pPointer;
  this->m_CloseTargetsList.size = 0;
  if ( m_pPointer )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
    p_m_pVehicleClosestPointSimObject = &this->m_pVehicleClosestPointSimObject;
    if ( p_m_pVehicleClosestPointSimObject->m_pPointer )
    {
      v18 = p_m_pVehicleClosestPointSimObject->mPrev;
      v19 = p_m_pVehicleClosestPointSimObject->mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      p_m_pVehicleClosestPointSimObject->mPrev = p_m_pVehicleClosestPointSimObject;
      p_m_pVehicleClosestPointSimObject->mNext = p_m_pVehicleClosestPointSimObject;
    }
    p_m_pVehicleClosestPointSimObject->m_pPointer = 0i64;
  }
}

// File Line: 518
// RVA: 0x55F170
void __fastcall UFG::TargetingSystemPedPlayerComponent::UpdateCommon(
        UFG::TargetingSystemPedPlayerComponent *this,
        float fDeltaS)
{
  UFG::SimObject *m_pSimObject; // rdi
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v5; // rcx
  int BoneID; // eax
  unsigned int v7; // eax
  unsigned int MostUsedIndex; // eax
  unsigned int v9; // eax
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObject *mNext; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pOccupantOfVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  int v16; // edi
  UFG::SimComponent *v17; // rax
  UFG::Controller *v18; // rax
  UFG::InputActionData *v19; // rcx
  float v20; // xmm1_4
  float mAxisPositionX; // xmm2_4
  float mAxisPositionY; // xmm0_4
  UFG::InputActionData *v23; // rcx
  float v24; // xmm0_4
  float v25; // xmm0_4
  float y; // xmm4_4
  __m128 x_low; // xmm3
  __m128 v28; // xmm2
  bool v29; // al
  bool m_bHasAimInput; // cl
  bool v31; // di
  bool v32; // cl

  if ( (_S40 & 1) == 0 )
  {
    _S40 |= 1u;
    UFG::qSymbolUC::create_from_string(&symBip01Head, "Bip01 Head");
    atexit(UFG::TargetingSystemPedPlayerComponent::UpdateCommon_::_2_::_dynamic_atexit_destructor_for__symBip01Head__);
  }
  m_pSimObject = this->m_pSimObject;
  UFG::TargetingSystemPedBaseComponent::UpdateCommon(this);
  if ( this->m_iVisibilityFromBoneID < 0 )
  {
    if ( this->m_pCharacterAnimationComponent.m_pSimComponent )
    {
      m_pSimComponent = this->m_pCharacterAnimationComponent.m_pSimComponent;
      if ( *(_QWORD *)&m_pSimComponent[2].m_TypeUID )
      {
        v5 = *(_QWORD *)&m_pSimComponent[2].m_TypeUID;
        if ( *(_QWORD *)(v5 + 440) )
          BoneID = Skeleton::GetBoneID(*(Skeleton **)(v5 + 480), symBip01Head.mUID);
        else
          BoneID = -1;
        this->m_iVisibilityFromBoneID = BoneID;
      }
    }
  }
  *(_WORD *)&this->m_bIsAimingActive = 0;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v7 = _S40;
    if ( (_S40 & 2) == 0 )
    {
      _S40 |= 2u;
      UID_VaultActions.mUID = UFG::qStringHashUpper32("VaultActions", -1);
      v7 = _S40;
    }
    if ( (v7 & 4) != 0 )
    {
      MostUsedIndex = mostUsed_VaultActions;
    }
    else
    {
      _S40 = v7 | 4;
      MostUsedIndex = GetMostUsedIndex(UID_VaultActions.mUID);
      mostUsed_VaultActions = MostUsedIndex;
    }
    this->m_bIsTransitionalAttackActive = ActionController::IsPlaying(
                                            (ActionController *)&this->m_pActionTreeComponent.m_pSimComponent[3],
                                            &UID_VaultActions,
                                            MostUsedIndex,
                                            1);
    v9 = _S40;
    if ( (_S40 & 8) == 0 )
    {
      _S40 |= 8u;
      UID_Aim.mUID = UFG::qStringHashUpper32("Aim", -1);
      v9 = _S40;
    }
    if ( (v9 & 0x10) == 0 )
    {
      _S40 = v9 | 0x10;
      mostUsed_Aim = GetMostUsedIndex(UID_Aim.mUID);
      v9 = _S40;
    }
    if ( (v9 & 0x20) == 0 )
    {
      _S40 = v9 | 0x20;
      UID_Aiming.mUID = UFG::qStringHashUpper32("Aiming", -1);
      v9 = _S40;
    }
    if ( (v9 & 0x40) == 0 )
    {
      _S40 = v9 | 0x40;
      mostUsed_Aiming = GetMostUsedIndex(UID_Aiming.mUID);
      v9 = _S40;
    }
    if ( (v9 & 0x80u) == 0 )
    {
      _S40 = v9 | 0x80;
      UID_VaultAim.mUID = UFG::qStringHashUpper32("VaultAim", -1);
      v9 = _S40;
    }
    if ( (v9 & 0x100) == 0 )
    {
      _S40 = v9 | 0x100;
      mostUsed_VaultAim = GetMostUsedIndex(UID_VaultAim.mUID);
    }
    if ( ActionController::IsPlaying(
           (ActionController *)&this->m_pActionTreeComponent.m_pSimComponent[3],
           &UID_Aim,
           mostUsed_Aim,
           1)
      || ActionController::IsPlaying(
           (ActionController *)&this->m_pActionTreeComponent.m_pSimComponent[3],
           &UID_Aiming,
           mostUsed_Aiming,
           1)
      || ActionController::IsPlaying(
           (ActionController *)&this->m_pActionTreeComponent.m_pSimComponent[3],
           &UID_VaultAim,
           mostUsed_VaultAim,
           1) )
    {
      this->m_bIsAimingActive = 1;
    }
  }
  if ( m_pSimObject
    && (m_pComponent = m_pSimObject->m_Components.p[44].m_pComponent) != 0i64
    && m_pComponent[1].m_BoundComponentHandles.mNode.mPrev )
  {
    mNext = (UFG::SimObject *)m_pComponent[1].m_BoundComponentHandles.mNode.mPrev[2].mNext;
  }
  else
  {
    mNext = 0i64;
  }
  p_m_pOccupantOfVehicle = &this->m_pOccupantOfVehicle;
  if ( this->m_pOccupantOfVehicle.m_pPointer )
  {
    mPrev = p_m_pOccupantOfVehicle->mPrev;
    v14 = this->m_pOccupantOfVehicle.mNext;
    mPrev->mNext = v14;
    v14->mPrev = mPrev;
    p_m_pOccupantOfVehicle->mPrev = p_m_pOccupantOfVehicle;
    this->m_pOccupantOfVehicle.mNext = &this->m_pOccupantOfVehicle;
  }
  this->m_pOccupantOfVehicle.m_pPointer = mNext;
  if ( mNext )
  {
    v15 = mNext->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v15->mNext = p_m_pOccupantOfVehicle;
    p_m_pOccupantOfVehicle->mPrev = v15;
    this->m_pOccupantOfVehicle.mNext = &mNext->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    mNext->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pOccupantOfVehicle;
  }
  v16 = 0;
  v17 = this->m_pAICharacterControllerComponent.m_pSimComponent;
  if ( v17 )
    v16 = (int)v17[17].m_SafePointerList.mNode.mPrev;
  v18 = UFG::InputSystem::AcquireController(UFG::gInputSystem, v16);
  if ( v18 && v18->m_IsKeyboardController )
  {
    v19 = UFG::ActionDef_Mouse.mDataPerController[v16];
    v20 = 0.0;
    if ( v19 )
    {
      mAxisPositionX = v19->mAxisPositionX;
      mAxisPositionY = v19->mAxisPositionY;
    }
    else
    {
      mAxisPositionX = 0.0;
      mAxisPositionY = 0.0;
    }
    this->m_bAimInputRaw = 1;
  }
  else
  {
    v23 = UFG::ActionDef_AimLocation.mDataPerController[v16];
    v20 = 0.0;
    if ( v23 )
    {
      mAxisPositionX = v23->mAxisPositionX;
      mAxisPositionY = v23->mAxisPositionY;
    }
    else
    {
      mAxisPositionX = 0.0;
      mAxisPositionY = 0.0;
    }
    this->m_bAimInputRaw = 0;
  }
  LODWORD(v24) = LODWORD(mAxisPositionY) ^ _xmm[0];
  this->m_vAimInput.x = mAxisPositionX;
  this->m_vAimInput.y = v24;
  v25 = fsqrt((float)(v24 * v24) + (float)(mAxisPositionX * mAxisPositionX));
  this->m_fAimInputLength = v25;
  if ( v25 <= 0.00000011920929 )
  {
    this->m_vAimInputDir = (UFG::qVector2)1065353216i64;
  }
  else
  {
    y = this->m_vAimInput.y;
    x_low = (__m128)LODWORD(this->m_vAimInput.x);
    v28 = x_low;
    v28.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y);
    if ( v28.m128_f32[0] != 0.0 )
      v20 = 1.0 / _mm_sqrt_ps(v28).m128_f32[0];
    this->m_vAimInputDir.x = x_low.m128_f32[0] * v20;
    this->m_vAimInputDir.y = y * v20;
  }
  v29 = this->m_fAimInputLength > 0.00000011920929;
  m_bHasAimInput = this->m_bHasAimInput;
  v31 = !m_bHasAimInput && this->m_fAimInputLength > 0.00000011920929;
  v32 = m_bHasAimInput && this->m_fAimInputLength <= 0.00000011920929;
  this->m_bHasNoAimInputTransition = v32;
  this->m_bHasAimInput = v29;
  if ( this->m_fAimInputLength < 0.89999998 )
  {
    *(_WORD *)&this->m_bHasFullAimInput = 0;
  }
  else
  {
    this->m_bHasFullAimInputTransition = !this->m_bHasFullAimInput;
    this->m_bHasFullAimInput = 1;
  }
  this->m_bIsInAnyCombat = UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(
                             UFG::LocalPlayerIsInCombatManager::s_pInstance,
                             0);
  if ( v31 )
    this->m_fTimeSinceStartedInput = 0.0;
  else
    this->m_fTimeSinceStartedInput = UFG::Metrics::msInstance.mSimTimeUnscaledDelta + this->m_fTimeSinceStartedInput;
}ombatManager::s_pInstance,
             

// File Line: 671
// RVA: 0x571250
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateDesiredFocusMode(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // r8
  UFG::eFocusModeEnum m_eDesiredFocusMode; // esi
  unsigned __int8 v3; // bp
  unsigned __int8 v4; // di
  __int64 m_EnumValue; // r11
  __int64 v7; // r9
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  bool v11; // dl
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  UFG::eFocusModeEnum m_eOverrideDesiredFocusMode; // eax
  UFG::GameStatTracker *v16; // rax
  int v17; // eax
  UFG::eFocusModeEnum v18; // ecx
  UFG::SimComponent *m_pPointer; // rax
  float v20; // xmm1_4
  UFG::eFocusModeEnum m_eFocusMode; // eax
  UFG::eFocusModeEnum v22; // ecx

  m_pSimComponent = this->m_pAICharacterControllerBaseComponent.m_pSimComponent;
  m_eDesiredFocusMode = this->m_eDesiredFocusMode;
  v3 = 0;
  v4 = 0;
  this->m_bFocusModeJustRequested = 0;
  if ( m_pSimComponent )
  {
    m_EnumValue = (int)gActionRequest_TargetingFreeAimAssistance.m_EnumValue;
    v7 = (int)gActionRequest_Grab.m_EnumValue;
    v8 = *((_QWORD *)&m_pSimComponent[4].m_BoundComponentHandles.mNode.mPrev
         + ((__int64)(int)gActionRequest_Focus.m_EnumValue >> 6));
    v3 = _bittest64(&v8, gActionRequest_Focus.m_EnumValue & 0x3F);
    v9 = *((_QWORD *)&m_pSimComponent[4].m_BoundComponentHandles.mNode.mPrev
         + ((__int64)(int)gActionRequest_Focus_Lock.m_EnumValue >> 6));
    v4 = _bittest64(&v9, gActionRequest_Focus_Lock.m_EnumValue & 0x3F);
    v11 = 0;
    if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      v10 = *((_QWORD *)&m_pSimComponent[4].m_BoundComponentHandles.mNode.mPrev
            + ((__int64)(int)gActionRequest_TargetingAutoAcquisition.m_EnumValue >> 6));
      if ( _bittest64(&v10, gActionRequest_TargetingAutoAcquisition.m_EnumValue & 0x3F) )
        v11 = 1;
    }
    v12 = *((_QWORD *)&m_pSimComponent[4].m_BoundComponentHandles.mNode.mPrev
          + ((__int64)(int)gActionRequest_TargetingFreeShootingDesired.m_EnumValue >> 6));
    this->m_bTargetingFreeShootingDesired = _bittest64(
                                              &v12,
                                              gActionRequest_TargetingFreeShootingDesired.m_EnumValue & 0x3F);
    v13 = *((_QWORD *)&m_pSimComponent[4].m_BoundComponentHandles.mNode.mPrev + (m_EnumValue >> 6));
    this->m_bTargetingFreeAimAssistance = _bittest64(&v13, m_EnumValue & 0x3F);
    this->m_bTargetAutoAcquisitionJustRequested = v11 && !this->m_bTargetAutoAcquisition;
    v14 = *((_QWORD *)&m_pSimComponent[4].m_BoundComponentHandles.mNode.mPrev + (v7 >> 6));
    if ( _bittest64(&v14, v7 & 0x3F) )
      this->m_bIsInAnyCombat = 0;
    this->m_bTargetAutoAcquisition = v11;
  }
  else
  {
    *(_DWORD *)&this->m_bTargetAutoAcquisition = 0;
  }
  m_eOverrideDesiredFocusMode = this->m_eOverrideDesiredFocusMode;
  if ( m_eOverrideDesiredFocusMode )
  {
    this->m_eDesiredFocusMode = m_eOverrideDesiredFocusMode;
    goto LABEL_49;
  }
  v16 = UFG::GameStatTracker::Instance();
  v17 = UFG::GameStatTracker::GetStat(v16, AimMode) - 1;
  if ( v17 )
  {
    if ( v17 == 1 )
      v4 = 0;
  }
  else if ( v3 )
  {
    v4 = 1;
  }
  if ( this->m_bTargetingFreeShootingDesired )
  {
    this->m_eDesiredFocusMode = eFOCUS_MODE_FREE_AIMING;
    goto LABEL_49;
  }
  if ( v3 )
  {
    if ( v4 || !this->m_bHasRangedWeapon )
    {
      this->m_eDesiredFocusMode = eFOCUS_MODE_LOCKED;
    }
    else if ( m_eDesiredFocusMode )
    {
      if ( this->m_eFocusMode == eFOCUS_MODE_FREE_AIMING_LOCKED )
      {
        this->m_eDesiredFocusMode = eFOCUS_MODE_FREE_AIMING_LOCKED;
      }
      else if ( this->m_bHasAimInput
             || this->m_bHasNoAimInputTransition
             || m_eDesiredFocusMode == eFOCUS_MODE_LOCKED_SOFT )
      {
        this->m_eDesiredFocusMode = eFOCUS_MODE_LOCKED_SOFT;
      }
      else
      {
        this->m_eDesiredFocusMode = eFOCUS_MODE_FREE_AIMING;
      }
    }
    else
    {
      this->m_eDesiredFocusMode = eFOCUS_MODE_LOCKED_SOFT;
      UFG::AimingPlayerComponent::SnapAccuracy(
        (UFG::AimingPlayerComponent *)this->m_pAimingPlayerComponent.m_pSimComponent,
        1.0);
    }
    v18 = this->m_eDesiredFocusMode;
    if ( (unsigned int)(v18 - 1) <= 1 )
    {
      if ( m_eDesiredFocusMode != v18 )
        goto LABEL_43;
      if ( UFG::TargetingSystemPedPlayerComponent::ms_bSoftLockOnNoInputTransition )
      {
        if ( !this->m_bHasNoAimInputTransition )
          goto LABEL_49;
        goto LABEL_43;
      }
      if ( UFG::TargetingSystemPedPlayerComponent::ms_bSoftLockOnNoInput && !this->m_bHasAimInput )
LABEL_43:
        this->m_bFocusModeJustRequested = 1;
    }
  }
  else
  {
    if ( this->m_eFocusMode )
    {
      m_pPointer = this->m_pEquippedSOWPC.m_pPointer;
      if ( m_pPointer )
      {
        v20 = *(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                         + HIDWORD(m_pPointer[2].m_pSimObject))
                       + 408i64);
        if ( v20 < 0.0 )
          *(float *)&this->m_pAimingPlayerComponent.m_pSimComponent[1].m_NameUID = v20;
      }
    }
    this->m_eDesiredFocusMode = eFOCUS_MODE_NONE;
  }
LABEL_49:
  m_eFocusMode = this->m_eFocusMode;
  v22 = this->m_eDesiredFocusMode;
  this->m_eFocusMode = v22;
  if ( m_eFocusMode == eFOCUS_MODE_NONE && v22 && !this->m_pFocusModeOverrideSimObject.m_pPointer )
    UFG::TargetingSystemBaseComponent::ClearTarget(this, eTARGET_TYPE_FOCUS);
}

// File Line: 899
// RVA: 0x54D100
void __fastcall UFG::TargetingSystemPedPlayerComponent::SetFocusMode(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::eFocusModeEnum eFocusMode)
{
  this->m_eDesiredFocusMode = eFocusMode;
  this->m_eFocusMode = eFocusMode;
}

// File Line: 908
// RVA: 0x5795F0
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateTargetingIntentions(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *v2; // rdi
  UFG::eFocusModeEnum m_eFocusMode; // ecx
  bool m_bHasAimInput; // al
  float v5; // xmm2_4
  float y; // xmm3_4
  float x; // xmm4_4
  __int64 v8; // rcx
  UFG::TargetingSimObject *m_pTargets; // rax
  bool v10; // dl
  UFG::SimObject *v11; // rdx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rcx
  float v13; // xmm1_4
  UFG::eFocusModeEnum v14; // eax
  float v15; // xmm0_4
  float z; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  UFG::TargetingSystemPedPlayerComponent *p_mNext; // rcx
  float v20; // xmm0_4
  float v21; // xmm1_4
  UFG::SimObject *m_pPointer; // rcx
  float v23; // xmm2_4
  float v24; // xmm1_4
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  float m_fHalfHorizontalIntentionLimiter; // xmm11_4
  float v28; // xmm4_4
  __m128 y_low; // xmm5
  float v30; // xmm6_4
  __m128 v31; // xmm7
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  float v34; // xmm2_4
  float v35; // xmm1_4
  double v36; // xmm0_8
  float v37; // xmm2_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  float v40; // xmm6_4
  float v41; // xmm3_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  __m128 x_low; // xmm4
  float v45; // xmm5_4
  __m128 v46; // xmm2
  float v47; // xmm2_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  UFG::BaseCameraComponent *v50; // rax
  UFG::Camera *v51; // rax
  int v52; // xmm1_4
  float v53; // xmm3_4
  __m128 v54; // xmm4
  float v55; // xmm5_4
  __m128 v56; // xmm2
  float v57; // xmm9_4
  UFG::qVector3 n2; // [rsp+20h] [rbp-71h] BYREF
  UFG::qVector3 n1; // [rsp+30h] [rbp-61h] BYREF
  UFG::qMatrix44 matSimObject; // [rsp+48h] [rbp-49h] BYREF

  v2 = 0i64;
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
    v2 = this->m_pAICharacterControllerBaseComponent.m_pSimComponent + 2;
  m_eFocusMode = this->m_eFocusMode;
  if ( (unsigned int)(m_eFocusMode - 2) <= 2 )
  {
    m_bHasAimInput = this->m_bHasAimInput;
    this->m_bHasFreeAimInput = m_bHasAimInput;
    if ( m_eFocusMode == eFOCUS_MODE_FREE_AIMING_LOCKED )
    {
      if ( !m_bHasAimInput )
        goto LABEL_14;
      if ( (_S41_0 & 1) != 0 )
      {
        v5 = s_fMinimumInputDifferenceSquared;
      }
      else
      {
        _S41_0 |= 1u;
        v5 = FLOAT_0_25;
        s_fMinimumInputDifferenceSquared = FLOAT_0_25;
      }
      y = this->m_vLockedFreeAimInput.y;
      x = this->m_vLockedFreeAimInput.x;
      if ( (float)((float)(x * x) + (float)(y * y)) <= 0.0 )
        v5 = 0.0;
      if ( (float)((float)((float)(this->m_vAimInput.y - y) * (float)(this->m_vAimInput.y - y))
                 + (float)((float)(this->m_vAimInput.x - x) * (float)(this->m_vAimInput.x - x))) <= v5 )
      {
        this->m_bHasFreeAimInput = 0;
      }
      else
      {
LABEL_14:
        this->m_eFocusMode = eFOCUS_MODE_FREE_AIMING;
        this->m_eDesiredFocusMode = eFOCUS_MODE_FREE_AIMING;
      }
    }
  }
  else
  {
    this->m_bHasFreeAimInput = 0;
  }
  this->m_fTargetingIntentionIdleTime = UFG::Metrics::msInstance.mSimTimeUnscaledDelta
                                      + this->m_fTargetingIntentionIdleTime;
  v8 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[22];
  m_pTargets = this->m_pTargets;
  v10 = m_pTargets[v8].m_pTarget.m_pPointer && m_pTargets[v8].m_bLock;
  if ( this->m_eDesiredFocusMode != eFOCUS_MODE_LOCKED || !v10 )
  {
    if ( this->m_pOccupantOfVehicle.m_pPointer
      || this->m_bIsTransitionalAttackActive && this->m_bHasRangedWeapon
      || (v14 = this->m_eFocusMode, v14 == eFOCUS_MODE_LOCKED_SOFT) )
    {
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        p_mCamera = &mCurrentCamera->mCamera;
      else
        p_mCamera = 0i64;
      LODWORD(v23) = LODWORD(p_mCamera->mTransformation.v2.x) ^ _xmm[0];
      LODWORD(v24) = LODWORD(p_mCamera->mTransformation.v2.y) ^ _xmm[0];
    }
    else
    {
      if ( v14 == eFOCUS_MODE_LOCKED && !this->m_bFocusModeJustRequested )
      {
        v15 = this->m_vTargetingForward.y;
        z = this->m_vTargetingForward.z;
        this->m_vTargetingIntention.x = this->m_vTargetingForward.x;
        this->m_vTargetingIntention.y = v15;
        this->m_vTargetingIntention.z = z;
        goto LABEL_44;
      }
      if ( !v2 )
      {
LABEL_44:
        m_fHalfHorizontalIntentionLimiter = this->m_pActiveTargetingProfile->m_fHalfHorizontalIntentionLimiter;
        if ( m_fHalfHorizontalIntentionLimiter < 3.1415927 )
        {
          v28 = this->m_vTargetingForward.x;
          y_low = (__m128)LODWORD(this->m_vTargetingForward.y);
          n1.z = 0.0;
          v30 = this->m_vTargetingIntention.x;
          v31 = (__m128)LODWORD(this->m_vTargetingIntention.y);
          n2.z = 0.0;
          v32 = y_low;
          v32.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v28 * v28);
          if ( v32.m128_f32[0] > 0.001 )
          {
            v33 = v31;
            v33.m128_f32[0] = (float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30);
            if ( v33.m128_f32[0] > 0.001 )
            {
              v34 = v32.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v32).m128_f32[0];
              n1.x = v28 * v34;
              n1.y = y_low.m128_f32[0] * v34;
              n1.z = v34 * 0.0;
              v35 = v33.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v33).m128_f32[0];
              n2.x = v30 * v35;
              n2.y = v31.m128_f32[0] * v35;
              n2.z = v35 * 0.0;
              v36 = UFG::qAngleBetweenNormals(&n1, &n2);
              v37 = *(float *)&v36 - m_fHalfHorizontalIntentionLimiter;
              if ( (float)(*(float *)&v36 - m_fHalfHorizontalIntentionLimiter) > 0.0 )
              {
                if ( (float)((float)((float)(this->m_vTargetingLeft.y * n2.y) + (float)(this->m_vTargetingLeft.x * n2.x))
                           + (float)(n2.z * 0.0)) > 0.0 )
                  LODWORD(v37) ^= _xmm[0];
                UFG::qRotationMatrixZ(&matSimObject, v37);
                v38 = this->m_vTargetingIntention.y;
                v39 = this->m_vTargetingIntention.x;
                v40 = this->m_vTargetingIntention.z;
                v41 = (float)((float)(matSimObject.v0.y * v39) + (float)(matSimObject.v1.y * v38))
                    + (float)(matSimObject.v2.y * v40);
                v42 = (float)((float)(matSimObject.v0.z * v39) + (float)(matSimObject.v1.z * v38))
                    + (float)(matSimObject.v2.z * v40);
                this->m_vTargetingIntention.x = (float)((float)(matSimObject.v0.x * v39)
                                                      + (float)(matSimObject.v1.x * v38))
                                              + (float)(matSimObject.v2.x * v40);
                this->m_vTargetingIntention.y = v41;
                this->m_vTargetingIntention.z = v42;
              }
            }
          }
        }
        goto LABEL_57;
      }
      if ( *(float *)&v2->m_SafePointerList.mNode.mNext > 0.0 )
      {
        v17 = *(float *)&v2->m_TypeUID;
        v18 = *(float *)&v2->m_NameUID;
        this->m_vTargetingIntention.x = *((float *)&v2->m_SafePointerList.mNode.mNext + 1);
        this->m_vTargetingIntention.y = v17;
        this->m_vTargetingIntention.z = v18;
        this->m_fTargetingIntentionIdleTime = 0.0;
        goto LABEL_44;
      }
      p_mNext = (UFG::TargetingSystemPedPlayerComponent *)&this->m_TargetSteerToTaskList.mNode.mNext[-3].mNext;
      v20 = this->m_vTargetingForward.y;
      v21 = this->m_vTargetingForward.z;
      this->m_vTargetingIntention.x = this->m_vTargetingForward.x;
      this->m_vTargetingIntention.y = v20;
      this->m_vTargetingIntention.z = v21;
      if ( p_mNext == (UFG::TargetingSystemPedPlayerComponent *)&this->m_pInterestPointUserComponent.m_pSimObject )
        goto LABEL_44;
      if ( this->m_TargetSteerToTaskList.mNode.mNext == (UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *)40 )
        goto LABEL_44;
      m_pPointer = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[SBYTE4(this->m_TargetSteerToTaskList.mNode.mNext[-1].mPrev[4].mNext)]].m_pTarget.m_pPointer;
      if ( !m_pPointer )
        goto LABEL_44;
      UFG::TargetingSystemBaseComponent::FindMatrix(m_pPointer->m_pTransformNodeComponent, m_pPointer, &matSimObject);
      v23 = matSimObject.v3.x - this->m_vTargetingPosition.x;
      v24 = matSimObject.v3.y - this->m_vTargetingPosition.y;
    }
    this->m_vTargetingIntention.x = v23;
    this->m_vTargetingIntention.y = v24;
    this->m_vTargetingIntention.z = 0.0;
    goto LABEL_44;
  }
  v11 = m_pTargets[v8].m_pTarget.m_pPointer;
  m_pTransformNodeComponent = 0i64;
  if ( v11 )
    m_pTransformNodeComponent = v11->m_pTransformNodeComponent;
  UFG::TargetingSystemBaseComponent::FindMatrix(m_pTransformNodeComponent, v11, &matSimObject);
  v13 = matSimObject.v3.y - this->m_vTargetingPosition.y;
  this->m_vTargetingIntention.x = matSimObject.v3.x - this->m_vTargetingPosition.x;
  this->m_vTargetingIntention.y = v13;
  this->m_vTargetingIntention.z = 0.0;
  if ( this->m_pOccupantOfVehicle.m_pPointer )
    goto LABEL_44;
LABEL_57:
  this->m_vTargetingIntention.z = 0.0;
  v43 = this->m_vTargetingIntention.y;
  x_low = (__m128)LODWORD(this->m_vTargetingIntention.x);
  v45 = this->m_vTargetingIntention.z;
  v46 = x_low;
  v46.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v43 * v43)) + (float)(v45 * v45);
  if ( v46.m128_f32[0] == 0.0 )
    v47 = 0.0;
  else
    v47 = 1.0 / _mm_sqrt_ps(v46).m128_f32[0];
  this->m_vTargetingIntention.x = v47 * x_low.m128_f32[0];
  this->m_vTargetingIntention.y = v47 * v43;
  this->m_vTargetingIntention.z = v47 * v45;
  if ( v2 && *(float *)&v2->m_SafePointerList.mNode.mNext > 0.0 )
  {
    v48 = *(float *)&v2->m_TypeUID;
    v49 = *(float *)&v2->m_NameUID;
    this->m_vDirectionalTargetingIntention.x = *((float *)&v2->m_SafePointerList.mNode.mNext + 1);
    this->m_vDirectionalTargetingIntention.y = v48;
    this->m_vDirectionalTargetingIntention.z = v49;
  }
  v50 = UFG::Director::Get()->mCurrentCamera;
  if ( v50 )
    v51 = &v50->mCamera;
  else
    v51 = 0i64;
  v52 = LODWORD(v51->mTransformation.v2.y) ^ _xmm[0];
  LODWORD(this->m_vAimTargetingIntention.x) = LODWORD(v51->mTransformation.v2.x) ^ _xmm[0];
  LODWORD(this->m_vAimTargetingIntention.y) = v52;
  this->m_vAimTargetingIntention.z = 0.0;
  v53 = this->m_vAimTargetingIntention.y;
  v54 = (__m128)LODWORD(this->m_vAimTargetingIntention.x);
  v55 = this->m_vAimTargetingIntention.z;
  v56 = v54;
  v56.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(v53 * v53)) + (float)(v55 * v55);
  if ( v56.m128_f32[0] == 0.0 )
    v57 = 0.0;
  else
    v57 = 1.0 / _mm_sqrt_ps(v56).m128_f32[0];
  this->m_vAimTargetingIntention.x = v57 * v54.m128_f32[0];
  this->m_vAimTargetingIntention.y = v57 * v53;
  this->m_vAimTargetingIntention.z = v57 * v55;
}

// File Line: 1117
// RVA: 0x56AC50
bool __fastcall UFG::TargetingSystemPedPlayerComponent::isLocationTargetingActive(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 mPrev_low; // r8
  bool v3; // dl
  UFG::InputActionData *v4; // r8
  float mAxisPositionX; // xmm0_4
  bool result; // al
  UFG::InputActionData *v7; // r8
  float v8; // xmm0_4
  UFG::InputActionData *v9; // r8
  bool v10; // al
  bool v11; // zf
  UFG::InputActionData *v12; // rax
  bool v13; // r11
  UFG::InputActionData *v14; // rax
  bool v15; // r10
  bool m_bHasAimInput; // r8
  char v17; // al
  bool v18; // al
  char v19; // cl
  UFG::InputActionData *v20; // r8
  bool v21; // r10
  bool v22; // r8

  m_pSimComponent = this->m_pAICharacterControllerComponent.m_pSimComponent;
  if ( !m_pSimComponent )
    return 0;
  mPrev_low = SLODWORD(m_pSimComponent[17].m_SafePointerList.mNode.mPrev);
  v3 = (unsigned int)(this->m_eFocusMode - 1) <= 3;
  switch ( UFG::TargetingSystemPedPlayerComponent::ms_eTargetCycleAndLocationTargetingModeEnum )
  {
    case TCALTM_SLIGHTLY_RELEASE_FOCUS:
      v4 = UFG::ActionDef_Focus.mDataPerController[mPrev_low];
      if ( v4 )
        mAxisPositionX = v4->mAxisPositionX;
      else
        mAxisPositionX = 0.0;
      if ( (unsigned int)(this->m_eFocusMode - 1) > 3 || !this->m_bHasAimInput || mAxisPositionX >= 1.0 )
        goto LABEL_9;
      return 1;
    case TCALTM_SLIGHTLY_PRESS_FIRE:
      v7 = UFG::ActionDef_FireTest.mDataPerController[mPrev_low];
      if ( v7 )
        v8 = v7->mAxisPositionX;
      else
        v8 = 0.0;
      if ( (unsigned int)(this->m_eFocusMode - 1) > 3 || !this->m_bHasAimInput || v8 <= 0.0 )
        goto LABEL_9;
      return 1;
    case TCALTM_SLIGHTLY_PRESS_AIM:
    case TCALTM_PRESS_STICK_TO_CYCLE:
    case TCALTM_DOUBLE_TAP_TO_CYCLE:
      if ( (unsigned int)(this->m_eFocusMode - 1) > 3 || !this->m_bHasAimInput )
        goto LABEL_9;
      return 1;
    case TCALTM_RELEASE_AIM_QUICKLY_TO_CYCLE_DELAY:
      if ( (unsigned int)(this->m_eFocusMode - 1) > 3
        || !this->m_bHasFullAimInput
        || UFG::TargetingSystemPedPlayerComponent::ms_fTimeToTargetCycleVis > this->m_fTimeSinceStartedInput )
      {
        goto LABEL_9;
      }
      return 1;
    case TCALTM_PRESS_STICK_TO_AIM:
      v9 = UFG::ActionDef_AimLocationHold.mDataPerController[mPrev_low];
      v10 = v9 && v9->mActionTrue;
      if ( (unsigned int)(this->m_eFocusMode - 1) > 3 )
        goto LABEL_9;
      v11 = !this->m_bHasAimInput;
      goto LABEL_30;
    case TCALTM_PRESS_STICK_TO_START_AIM:
      v12 = UFG::ActionDef_AimLocationToggle.mDataPerController[mPrev_low];
      v13 = v12 && v12->mActionTrue;
      v14 = UFG::ActionDef_AimLocationHold.mDataPerController[mPrev_low];
      v15 = v14 && v14->mActionTrue;
      m_bHasAimInput = this->m_bHasAimInput;
      if ( m_bHasAimInput )
      {
        v17 = s_bAllowAiming;
      }
      else
      {
        v17 = s_bAllowAiming;
        if ( !v15 )
          v17 = 0;
      }
      if ( v13 )
        v17 = 1;
      s_bAllowAiming = v17;
      if ( !v3 || !m_bHasAimInput || !v17 )
        goto LABEL_9;
      return 1;
    case TCALTM_PRESS_STICK_TO_START_AIM_MODE:
      v18 = this->m_bHasAimInput;
      if ( v18 && s_bAimModeActive )
      {
        s_bAimModeActive = 0;
        v19 = 1;
      }
      else
      {
        v19 = s_bAimModeLatched;
      }
      if ( !v18 )
        v19 = 0;
      s_bAimModeLatched = v19;
      if ( !v3 || !v18 || !v19 )
        goto LABEL_9;
      return 1;
    case TCALTM_PRESS_STICK_TO_START_AIM_TIME:
      v20 = UFG::ActionDef_AimLocationHold.mDataPerController[mPrev_low];
      v21 = v20 && v20->mActionTrue;
      v22 = this->m_bHasAimInput;
      if ( v22 )
      {
        v10 = s_bAimingLatched;
      }
      else
      {
        v10 = s_bAimingLatched;
        if ( !v21 )
          v10 = 0;
        s_bAimingLatched = v10;
      }
      if ( v22 )
      {
        if ( s_fAimModeActiveS > 0.0 )
          v10 = 1;
        s_bAimingLatched = v10;
      }
      if ( !v3 )
        goto LABEL_9;
      v11 = !v22;
LABEL_30:
      if ( v11 || !v10 )
LABEL_9:
        result = 0;
      else
        result = 1;
      break;
    default:
      return 0;
  }
  return result;
}

// File Line: 1247
// RVA: 0x568670
float __fastcall UFG::TargetingSystemPedPlayerComponent::getLocationTargetingAngle(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  float result; // xmm0_4

  result = atan2f(this->m_vAimInputDir.x, this->m_vAimInputDir.y);
  if ( result < 0.0 )
    return result + 6.2831855;
  return result;
}

// File Line: 1271
// RVA: 0x572FA0
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateFocusTargetSubTargetingLocation(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *m_pComponent; // rdi
  UFG::GameStatTracker *v3; // rax
  __int64 v4; // rdx
  UFG::SimObject *v5; // rsi
  __int16 v6; // cx
  unsigned int vfptr; // r8d
  unsigned int v8; // r9d
  float LocationTargetingAngle; // xmm0_4
  UFG::SubTargetingLocation *SubTargetingLocationByAimOffset; // rax
  UFG::SubTargetingProfile *v11; // rax
  UFG::SimObjectProp *m_pPointer; // rsi
  __int16 m_Flags; // cx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  __int64 v16; // rdx
  UFG::SubTargetingProfile *v17; // rdi
  bool v18; // zf
  float *m_pSimComponent; // rcx
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  UFG::SubTargetingLocation *m_pFocusTargetSubTargetingLocation; // rcx
  UFG::SimComponent *v24; // rax
  float v25; // xmm1_4
  UFG::qVector3 vAimOffset; // [rsp+20h] [rbp-68h] BYREF
  UFG::qMatrix44 matSimObject; // [rsp+30h] [rbp-58h] BYREF

  m_pComponent = 0i64;
  this->m_pFocusTargetSubTargetingLocation = 0i64;
  v3 = UFG::GameStatTracker::Instance();
  if ( (int)UFG::GameStatTracker::GetStat(v3, GunplayUpgradeStage) < UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_iRequiredLevelForGunplayUpgradeSubTargeting )
    return;
  if ( (unsigned int)(this->m_eFocusMode - 2) <= 2 )
  {
    m_pPointer = (UFG::SimObjectProp *)this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
    if ( !m_pPointer )
      goto LABEL_48;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[3].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[4].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        mComponentTableEntryCount = m_pPointer->mComponentTableEntryCount;
        size = m_pPointer->m_Components.size;
        if ( mComponentTableEntryCount < size )
        {
          v16 = (__int64)&m_pPointer->m_Components.p[mComponentTableEntryCount];
          while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || (UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            v16 += 16i64;
            if ( mComponentTableEntryCount >= size )
              goto LABEL_41;
          }
          m_pComponent = *(UFG::SimComponent **)v16;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[3].m_pComponent;
    }
LABEL_41:
    if ( !m_pComponent )
      goto LABEL_48;
    v17 = (UFG::SubTargetingProfile *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[14].__vecDelDtor)(m_pComponent);
    if ( !v17 )
      goto LABEL_48;
    UFG::TargetingSystemBaseComponent::FindMatrix(m_pPointer->m_pTransformNodeComponent, m_pPointer, &matSimObject);
    v18 = !this->m_bTargetingFreeAimAssistance;
    m_pSimComponent = (float *)this->m_pAimingPlayerComponent.m_pSimComponent;
    v20 = m_pSimComponent[155] - matSimObject.v3.y;
    vAimOffset.x = m_pSimComponent[154] - matSimObject.v3.x;
    v21 = m_pSimComponent[156];
    vAimOffset.y = v20;
    vAimOffset.z = v21 - matSimObject.v3.z;
    if ( v18 )
      v22 = *(float *)&FLOAT_1_0;
    else
      v22 = UFG::TargetingSystemPedPlayerComponent::ms_fFreeAimAssistanceSubTargetingMultiplier;
    SubTargetingLocationByAimOffset = UFG::SubTargetingProfile::FindSubTargetingLocationByAimOffset(
                                        v17,
                                        m_pPointer,
                                        &vAimOffset,
                                        v22);
  }
  else
  {
    if ( !UFG::TargetingSystemPedPlayerComponent::isLocationTargetingActive(this) )
      goto LABEL_48;
    v5 = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
    if ( !v5 )
      goto LABEL_48;
    v6 = v5->m_Flags;
    if ( (v6 & 0x4000) != 0 )
    {
      m_pComponent = v5->m_Components.p[3].m_pComponent;
    }
    else if ( v6 >= 0 )
    {
      if ( (v6 & 0x2000) != 0 )
      {
        m_pComponent = v5->m_Components.p[4].m_pComponent;
      }
      else if ( (v6 & 0x1000) != 0 )
      {
        vfptr = (unsigned int)v5[1].vfptr;
        v8 = v5->m_Components.size;
        v4 = vfptr;
        if ( vfptr < v8 )
        {
          v4 = (__int64)&v5->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v4 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || (UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v4 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v4 += 16i64;
            if ( vfptr >= v8 )
              goto LABEL_20;
          }
          m_pComponent = *(UFG::SimComponent **)v4;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(v5, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = v5->m_Components.p[3].m_pComponent;
    }
LABEL_20:
    if ( !m_pComponent || !m_pComponent->vfptr[14].__vecDelDtor(m_pComponent, v4) )
      goto LABEL_48;
    LocationTargetingAngle = UFG::TargetingSystemPedPlayerComponent::getLocationTargetingAngle(this);
    SubTargetingLocationByAimOffset = this->m_pLastFocusTargetSubTargetingLocation;
    if ( !SubTargetingLocationByAimOffset
      || COERCE_FLOAT(COERCE_UNSIGNED_INT(this->m_fLastLocationTargetingAngle - LocationTargetingAngle) & _xmm) > 0.087266468 )
    {
      v11 = (UFG::SubTargetingProfile *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[14].__vecDelDtor)(m_pComponent);
      SubTargetingLocationByAimOffset = UFG::SubTargetingProfile::FindSubTargetingLocationByInput(
                                          v11,
                                          v5,
                                          LocationTargetingAngle);
      this->m_fLastLocationTargetingAngle = LocationTargetingAngle;
    }
  }
  this->m_pFocusTargetSubTargetingLocation = SubTargetingLocationByAimOffset;
LABEL_48:
  m_pFocusTargetSubTargetingLocation = this->m_pFocusTargetSubTargetingLocation;
  if ( m_pFocusTargetSubTargetingLocation != this->m_pLastFocusTargetSubTargetingLocation )
  {
    if ( m_pFocusTargetSubTargetingLocation && this->m_eFocusMode == eFOCUS_MODE_LOCKED )
      *(float *)&this->m_pAimingPlayerComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev = m_pFocusTargetSubTargetingLocation->m_fAccuracyPenalty + *(float *)&this->m_pAimingPlayerComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    v24 = this->m_pEquippedSOWPC.m_pPointer;
    if ( v24 )
    {
      v25 = *(float *)(*((_QWORD *)&v24[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v24[2].m_pSimObject))
                     + 404i64);
      if ( v25 < 0.0 )
        *(float *)&this->m_pAimingPlayerComponent.m_pSimComponent[1].m_NameUID = v25;
    }
    this->m_pLastFocusTargetSubTargetingLocation = this->m_pFocusTargetSubTargetingLocation;
  }
}

// File Line: 1373
// RVA: 0x56EE70
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateActionHijackTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList)
{
  UFG::TargetingMap *m_pTargetingMap; // rcx
  UFG::TargetingSimObject *m_pTargets; // r8
  __int64 v6; // rax
  bool v7; // r13
  UFG::TargetingSimObject *v8; // rax
  bool v9; // al
  UFG::SimObject *v10; // r12
  UFG::SimObject *v11; // rbp
  UFG::SimObject *m_pPointer; // rcx
  bool v13; // al
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  unsigned int m_TypeUID; // edx
  unsigned int v17; // edx
  unsigned int vfptr; // r8d
  unsigned int v19; // r9d
  __int64 v20; // rdx
  unsigned int v21; // r8d
  unsigned int v22; // r9d
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  unsigned int size; // r15d
  unsigned int v25; // esi
  UFG::CloseTarget **p; // r14
  UFG::SimObjectVehicle *m_pSimObject; // rbx
  UFG::TargetingMap *v28; // rcx
  UFG::TargetingSimObject *v29; // r8
  __int64 v30; // rax
  UFG::SimObject *v31; // r9
  unsigned __int8 v32; // al
  unsigned __int8 v33; // cl
  unsigned __int64 v34; // rbx
  UFG::TargetingSimObject *v35; // rax
  unsigned __int8 v36; // cl
  unsigned __int64 v37; // rbx
  UFG::TargetingSimObject *v38; // rax
  bool v39; // [rsp+70h] [rbp+8h]
  bool bCanActionHijackThisVehicle; // [rsp+80h] [rbp+18h] BYREF
  bool bCanPotentiallyActionHijackThisVehicle; // [rsp+88h] [rbp+20h] BYREF

  m_pTargetingMap = this->m_pTargetingMap;
  m_pTargets = this->m_pTargets;
  v6 = (unsigned __int8)m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE_ACTION_HIJACK];
  v7 = m_pTargets[v6].m_pTarget.m_pPointer && m_pTargets[v6].m_bLock;
  v8 = &m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE_ACTION_HIJACK_POTENTIAL]];
  v9 = v8->m_pTarget.m_pPointer && v8->m_bLock;
  v39 = v9;
  if ( v7 && v9 )
    return;
  v10 = 0i64;
  v11 = 0i64;
  if ( UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreInVehicle || this->m_pOccupantOfVehicle.m_pPointer )
  {
    m_pPointer = this->m_pOccupantOfVehicle.m_pPointer;
    v13 = 0;
    if ( !m_pPointer )
      goto LABEL_45;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      if ( m_pComponent )
      {
        m_TypeUID = m_pComponent->m_TypeUID;
        if ( ((m_TypeUID ^ UFG::TargetingSystemVehicleComponent::_TypeUID) & 0xFE000000) == 0
          && (UFG::TargetingSystemVehicleComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) == 0 )
        {
LABEL_40:
          v13 = 0;
          if ( m_pComponent )
          {
            mPrev = m_pComponent[2].m_SafePointerList.mNode.mPrev;
            if ( mPrev )
            {
              if ( BYTE4(mPrev[3].mNext) )
                v13 = 1;
            }
          }
LABEL_45:
          if ( UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreInVehicle || v13 )
          {
            size = closeVehiclesList->size;
            v25 = 0;
            if ( closeVehiclesList->size )
            {
              p = closeVehiclesList->p;
              while ( 1 )
              {
                m_pSimObject = (UFG::SimObjectVehicle *)(*p)->m_pSimObjectPropertiesComponent->m_pSimObject;
                if ( (UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreInVehicle
                   || m_pSimObject != this->m_pOccupantOfVehicle.m_pPointer)
                  && m_pSimObject != this->m_pOccupantOfVehicle.m_pPointer )
                {
                  UFG::TargetingSystemPedPlayerComponent::canActionHijackThisVehicle(
                    this,
                    m_pSimObject,
                    (UFG::qVector3 *)&(*p)->m_Xform,
                    &bCanActionHijackThisVehicle,
                    &bCanPotentiallyActionHijackThisVehicle);
                  if ( bCanActionHijackThisVehicle )
                  {
                    v10 = m_pSimObject;
                    v11 = m_pSimObject;
                    goto LABEL_59;
                  }
                  if ( bCanPotentiallyActionHijackThisVehicle && !v11 )
                    v11 = m_pSimObject;
                }
                ++v25;
                ++p;
                if ( v25 >= size )
                  goto LABEL_59;
              }
            }
          }
          goto LABEL_59;
        }
      }
LABEL_18:
      m_pComponent = 0i64;
      goto LABEL_40;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      if ( m_pComponent )
      {
        v17 = m_pComponent->m_TypeUID;
        if ( ((v17 ^ UFG::TargetingSystemVehicleComponent::_TypeUID) & 0xFE000000) == 0 )
        {
          if ( (UFG::TargetingSystemVehicleComponent::_TypeUID & ~v17 & 0x1FFFFFF) != 0 )
            m_pComponent = 0i64;
          goto LABEL_40;
        }
      }
      goto LABEL_18;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pPointer[1].vfptr;
      v19 = m_pPointer->m_Components.size;
      if ( vfptr >= v19 )
        goto LABEL_18;
      v20 = (__int64)&m_pPointer->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::TargetingSystemVehicleComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemVehicleComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v20 += 16i64;
        if ( vfptr >= v19 )
        {
          m_pComponent = 0i64;
          goto LABEL_40;
        }
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemVehicleComponent::_TypeUID);
        goto LABEL_40;
      }
      v21 = (unsigned int)m_pPointer[1].vfptr;
      v22 = m_pPointer->m_Components.size;
      if ( v21 >= v22 )
        goto LABEL_18;
      v20 = (__int64)&m_pPointer->m_Components.p[v21];
      while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::TargetingSystemVehicleComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemVehicleComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v21;
        v20 += 16i64;
        if ( v21 >= v22 )
        {
          m_pComponent = 0i64;
          goto LABEL_40;
        }
      }
    }
    m_pComponent = *(UFG::SimComponent **)v20;
    goto LABEL_40;
  }
LABEL_59:
  if ( !v7 )
  {
    if ( v10 )
    {
      v28 = this->m_pTargetingMap;
      v29 = this->m_pTargets;
      v30 = (unsigned __int8)v28->m_Map.p[eTARGET_TYPE_FOCUS];
      v31 = v29[v30].m_pTarget.m_pPointer;
      if ( v31 && v29[v30].m_bLock && v31 != v10 )
      {
        UFG::TargetingSystemBaseComponent::ClearTarget(this, eTARGET_TYPE_VEHICLE_ACTION_HIJACK);
      }
      else
      {
        v32 = v28->m_Map.p[44];
        if ( v32 )
          UFG::TargetingSimObject::SetTarget(&v29[v32], v10);
      }
    }
    else
    {
      v33 = this->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE_ACTION_HIJACK];
      if ( v33 )
      {
        v34 = v33;
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v34], 0i64);
        v35 = this->m_pTargets;
        if ( v35[v34].m_bLock )
          v35[v34].m_bLock = 0;
      }
    }
  }
  if ( !v39 )
  {
    v36 = this->m_pTargetingMap->m_Map.p[45];
    if ( v11 )
    {
      if ( v36 )
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v36], v11);
    }
    else if ( v36 )
    {
      v37 = v36;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v37], 0i64);
      v38 = this->m_pTargets;
      if ( v38[v37].m_bLock )
        v38[v37].m_bLock = 0;
    }
  }
}

// File Line: 1549
// RVA: 0x570380
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateAttackingTarget(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingSimObject *v2; // rdx
  UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *p_m_TargetedBy; // r15
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *mNext; // rcx
  unsigned int mfnInPlaceNew; // edi
  unsigned int v6; // ebx
  UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *v7; // rbp
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *mPrev; // r14
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v9; // r8
  __int16 v10; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v12; // ecx
  unsigned int v13; // r9d
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v14; // r11
  __int64 v15; // r8
  unsigned int v16; // ecx
  unsigned int v17; // r9d
  unsigned int m_NameUID; // ecx
  float v19; // xmm0_4
  __int64 v20; // rcx
  unsigned __int8 v21; // cl
  unsigned __int8 v22; // cl
  unsigned __int64 v23; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  ClassTypeDescriptor right; // [rsp+28h] [rbp-6B0h] BYREF
  ClassTypeDescriptor left[104]; // [rsp+38h] [rbp-6A0h] BYREF

  v2 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[38]];
  if ( !v2->m_pTarget.m_pPointer || !v2->m_bLock )
  {
    LODWORD(right.mfnInPlaceNew) = 0;
    p_m_TargetedBy = &this->m_TargetedBy;
    mNext = this->m_TargetedBy.mNode.mNext;
    mfnInPlaceNew = 0;
    if ( mNext != (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)p_m_TargetedBy )
    {
      v6 = UFG::HitReactionComponent::_TypeUID;
      while ( 1 )
      {
        v7 = (UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *)mNext->mNext;
        if ( LOBYTE(mNext[3].mPrev) != 22 )
          goto LABEL_37;
        if ( mNext[2].mNext != (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)this->m_pSimObject )
          goto LABEL_37;
        mPrev = mNext[1].mPrev;
        v9 = mPrev[2].mNext;
        if ( !v9 )
          goto LABEL_37;
        v10 = WORD2(v9[4].mNext);
        if ( (v10 & 0x4000) != 0 )
        {
          ComponentOfType = (UFG::SimComponent *)v9[6].mNext[15].mPrev;
          goto LABEL_29;
        }
        if ( v10 < 0 )
        {
          ComponentOfType = (UFG::SimComponent *)v9[6].mNext[15].mPrev;
          goto LABEL_29;
        }
        if ( (v10 & 0x2000) != 0 )
          break;
        if ( (v10 & 0x1000) != 0 )
        {
          v16 = (unsigned int)v9[8].mPrev;
          v17 = (unsigned int)v9[6].mPrev;
          if ( v16 < v17 )
          {
            v14 = v9[6].mNext;
            while ( 1 )
            {
              v15 = v16;
              if ( ((__int64)v14[v16].mNext & 0xFE000000) == (v6 & 0xFE000000)
                && (v6 & ~LODWORD(v14[v16].mNext) & 0x1FFFFFF) == 0 )
              {
                goto LABEL_19;
              }
              if ( ++v16 >= v17 )
                goto LABEL_20;
            }
          }
          goto LABEL_20;
        }
        ComponentOfType = UFG::SimObject::GetComponentOfType((UFG::SimObject *)mPrev[2].mNext, v6);
        mfnInPlaceNew = (unsigned int)right.mfnInPlaceNew;
        v6 = UFG::HitReactionComponent::_TypeUID;
LABEL_29:
        if ( ComponentOfType )
        {
          m_NameUID = ComponentOfType[1].m_NameUID;
          if ( m_NameUID == 1 )
          {
            v19 = (float)(*(float *)&ComponentOfType[1].m_TypeUID * _real) + 1.0;
LABEL_34:
            if ( v19 >= 0.0 && mfnInPlaceNew < 0x64 )
            {
              v20 = mfnInPlaceNew;
              LODWORD(right.mfnInPlaceNew) = mfnInPlaceNew + 1;
              left[v20].mfnInPlaceNew = (void (__fastcall *)(void *))mPrev[2].mNext;
              *(float *)&left[v20].mUID = v19;
              mfnInPlaceNew = (unsigned int)right.mfnInPlaceNew;
            }
            goto LABEL_37;
          }
          if ( m_NameUID == 2 )
          {
            v19 = (float)(*(float *)&ComponentOfType[1].m_TypeUID * _real) + 2.0;
            goto LABEL_34;
          }
        }
LABEL_37:
        mNext = &v7->mNode;
        if ( v7 == p_m_TargetedBy )
          goto LABEL_38;
      }
      v12 = (unsigned int)v9[8].mPrev;
      v13 = (unsigned int)v9[6].mPrev;
      if ( v12 < v13 )
      {
        v14 = v9[6].mNext;
        while ( 1 )
        {
          v15 = v12;
          if ( ((__int64)v14[v12].mNext & 0xFE000000) == (v6 & 0xFE000000)
            && (v6 & ~LODWORD(v14[v12].mNext) & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v12 >= v13 )
            goto LABEL_20;
        }
LABEL_19:
        ComponentOfType = (UFG::SimComponent *)v14[v15].mPrev;
        goto LABEL_29;
      }
LABEL_20:
      ComponentOfType = 0i64;
      goto LABEL_29;
    }
LABEL_38:
    UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
      left,
      &right + (int)mfnInPlaceNew,
      (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
    if ( LODWORD(right.mfnInPlaceNew) && left[0].mfnInPlaceNew )
    {
      v21 = this->m_pTargetingMap->m_Map.p[38];
      if ( v21 )
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v21], (UFG::SimObject *)left[0].mfnInPlaceNew);
    }
    else
    {
      v22 = this->m_pTargetingMap->m_Map.p[38];
      if ( v22 )
      {
        v23 = v22;
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v23], 0i64);
        m_pTargets = this->m_pTargets;
        if ( m_pTargets[v23].m_bLock )
          m_pTargets[v23].m_bLock = 0;
      }
    }
  }
}

// File Line: 1626
// RVA: 0x577F60
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateSocialTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList)
{
  UFG::TargetingProfile *m_pActiveTargetingProfile; // rax
  float v5; // xmm7_4
  float v6; // xmm9_4
  unsigned int size; // edi
  unsigned int v8; // r15d
  __int64 v9; // r14
  UFG::CloseTarget *v10; // rsi
  float v11; // xmm1_4
  float y; // xmm1_4
  double v13; // xmm0_8
  UFG::SimObject *m_pSimObject; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rcx
  unsigned int vfptr; // edx
  unsigned int v18; // r9d
  UFG::SimComponentHolder *p; // rdi
  __int64 v20; // r8
  unsigned int v21; // edx
  unsigned int v22; // r9d
  __int64 mfnInPlaceNew_low; // rbp
  float v24; // xmm6_4
  __int16 v25; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v27; // edx
  unsigned int v28; // r9d
  UFG::SimComponentHolder *v29; // rdi
  __int64 v30; // r8
  unsigned int v31; // edx
  unsigned int v32; // r9d
  unsigned int v33; // edx
  unsigned int v34; // r9d
  UFG::SimObject *v35; // rcx
  void (__fastcall *mfnInPlaceNew)(void *); // r9
  UFG::TargetingMap *m_pTargetingMap; // r10
  __int64 v38; // r8
  UFG::TargetingSimObject *m_pTargets; // rdx
  UFG::TargetingSimObject *v40; // rcx
  __int64 v41; // rax
  __int64 v42; // rbx
  UFG::TargetingSimObject *v43; // rax
  UFG::qVector3 v2; // [rsp+20h] [rbp-6E8h] BYREF
  UFG::qVector3 v1; // [rsp+30h] [rbp-6D8h] BYREF
  __int64 v46; // [rsp+40h] [rbp-6C8h]
  ClassTypeDescriptor right; // [rsp+48h] [rbp-6C0h] BYREF
  ClassTypeDescriptor left[104]; // [rsp+58h] [rbp-6B0h] BYREF
  unsigned int v49; // [rsp+710h] [rbp+8h]

  v46 = -2i64;
  if ( !this->m_pOccupantOfVehicle.m_pPointer )
  {
    LODWORD(right.mfnInPlaceNew) = 0;
    m_pActiveTargetingProfile = this->m_pActiveTargetingProfile;
    v5 = m_pActiveTargetingProfile->m_ConeDistancesSquared[3];
    v6 = m_pActiveTargetingProfile->m_HalfHorizontalFOVs[3];
    size = closePedsList->size;
    v49 = closePedsList->size;
    v8 = 0;
    v9 = 0i64;
    while ( v8 < size )
    {
      v10 = closePedsList->p[v9];
      if ( v5 < v10->m_fDistance2 )
        goto LABEL_71;
      v11 = v10->m_Xform.v3.y - this->m_vTargetingPosition.y;
      v1.x = v10->m_Xform.v3.x - this->m_vTargetingPosition.x;
      v1.y = v11;
      v1.z = 0.0;
      y = this->m_vTargetingForward.y;
      v2.x = this->m_vTargetingForward.x;
      *(_QWORD *)&v13 = LODWORD(v2.x);
      v2.y = y;
      v2.z = 0.0;
      *(float *)&v13 = UFG::qAngleBetween(&v1, &v2);
      if ( v6 < *(float *)&v13 )
        goto LABEL_71;
      m_pSimObject = v10->m_pSimObjectPropertiesComponent->m_pSimObject;
      if ( !m_pSimObject )
        goto LABEL_36;
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
        if ( !m_pComponent
          || ((UFG::TargetingSystemPedBaseComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0
          || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          goto LABEL_10;
        }
      }
      else
      {
        if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            vfptr = (unsigned int)m_pSimObject[1].vfptr;
            v18 = m_pSimObject->m_Components.size;
            if ( vfptr < v18 )
            {
              p = m_pSimObject->m_Components.p;
              do
              {
                v20 = vfptr;
                if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
                  && (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_23;
                }
              }
              while ( ++vfptr < v18 );
            }
LABEL_24:
            m_pComponent = 0i64;
          }
          else
          {
            if ( (m_Flags & 0x1000) == 0 )
            {
              m_pComponent = UFG::SimObject::GetComponentOfType(
                               m_pSimObject,
                               UFG::TargetingSystemPedBaseComponent::_TypeUID);
              goto LABEL_34;
            }
            v21 = (unsigned int)m_pSimObject[1].vfptr;
            v22 = m_pSimObject->m_Components.size;
            if ( v21 >= v22 )
              goto LABEL_24;
            p = m_pSimObject->m_Components.p;
            while ( 1 )
            {
              v20 = v21;
              if ( (p[v21].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
                && (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~p[v21].m_TypeUID & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++v21 >= v22 )
                goto LABEL_24;
            }
LABEL_23:
            m_pComponent = p[v20].m_pComponent;
          }
          size = v49;
          goto LABEL_34;
        }
        m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
        if ( !m_pComponent
          || ((UFG::TargetingSystemPedBaseComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0 )
        {
LABEL_10:
          m_pComponent = 0i64;
          goto LABEL_34;
        }
        if ( (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
          m_pComponent = 0i64;
      }
LABEL_34:
      if ( m_pComponent && !BYTE1(m_pComponent[8].m_BoundComponentHandles.mNode.mPrev) )
        goto LABEL_71;
LABEL_36:
      if ( LODWORD(right.mfnInPlaceNew) < 0x64 )
      {
        mfnInPlaceNew_low = LODWORD(right.mfnInPlaceNew);
        ++LODWORD(right.mfnInPlaceNew);
        v24 = UFG::TargetingSystemPedBaseComponent::scoreBasic(v10->m_fDistance2, v5, v13);
        if ( !m_pSimObject )
          goto LABEL_69;
        v25 = m_pSimObject->m_Flags;
        if ( (v25 & 0x4000) != 0 )
        {
          ComponentOfType = m_pSimObject->m_Components.p[45].m_pComponent;
LABEL_64:
          if ( ComponentOfType )
          {
            if ( *((_BYTE *)&ComponentOfType[3].m_SimObjIndex + 2) )
            {
              v35 = ComponentOfType->m_pSimObject;
              if ( !v35 || (v35->m_Flags & 0x400) == 0 )
              {
LABEL_70:
                left[mfnInPlaceNew_low].mfnInPlaceNew = (void (__fastcall *)(void *))m_pSimObject;
                *(float *)&left[mfnInPlaceNew_low].mUID = v24;
                size = v49;
                goto LABEL_71;
              }
            }
          }
LABEL_69:
          v24 = v24 + 1.0;
          goto LABEL_70;
        }
        if ( v25 >= 0 )
        {
          if ( (v25 & 0x2000) != 0 )
          {
            v31 = (unsigned int)m_pSimObject[1].vfptr;
            v32 = m_pSimObject->m_Components.size;
            if ( v31 < v32 )
            {
              v29 = m_pSimObject->m_Components.p;
              do
              {
                v30 = v31;
                if ( (v29[v31].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                  && (UFG::FaceActionComponent::_TypeUID & ~v29[v31].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_47;
                }
              }
              while ( ++v31 < v32 );
            }
          }
          else
          {
            if ( (v25 & 0x1000) == 0 )
            {
              ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FaceActionComponent::_TypeUID);
              goto LABEL_64;
            }
            v33 = (unsigned int)m_pSimObject[1].vfptr;
            v34 = m_pSimObject->m_Components.size;
            if ( v33 < v34 )
            {
              v29 = m_pSimObject->m_Components.p;
              do
              {
                v30 = v33;
                if ( (v29[v33].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                  && (UFG::FaceActionComponent::_TypeUID & ~v29[v33].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_47;
                }
              }
              while ( ++v33 < v34 );
            }
          }
        }
        else
        {
          v27 = (unsigned int)m_pSimObject[1].vfptr;
          v28 = m_pSimObject->m_Components.size;
          if ( v27 < v28 )
          {
            v29 = m_pSimObject->m_Components.p;
            while ( 1 )
            {
              v30 = v27;
              if ( (v29[v27].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                && (UFG::FaceActionComponent::_TypeUID & ~v29[v27].m_TypeUID & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++v27 >= v28 )
                goto LABEL_48;
            }
LABEL_47:
            ComponentOfType = v29[v30].m_pComponent;
            goto LABEL_64;
          }
        }
LABEL_48:
        ComponentOfType = 0i64;
        goto LABEL_64;
      }
LABEL_71:
      ++v8;
      ++v9;
    }
    UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
      left,
      &right + SLODWORD(right.mfnInPlaceNew),
      (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
    mfnInPlaceNew = 0i64;
    if ( LODWORD(right.mfnInPlaceNew) )
      mfnInPlaceNew = left[0].mfnInPlaceNew;
    m_pTargetingMap = this->m_pTargetingMap;
    v38 = (unsigned __int8)m_pTargetingMap->m_Map.p[50];
    m_pTargets = this->m_pTargets;
    v40 = &m_pTargets[v38];
    if ( !v40->m_pTarget.m_pPointer || !v40->m_bLock )
    {
      v41 = (unsigned __int8)m_pTargetingMap->m_Map.p[22];
      if ( m_pTargets[v41].m_pTarget.m_pPointer && m_pTargets[v41].m_bLock )
      {
        if ( (_BYTE)v38 )
          UFG::TargetingSimObject::SetTarget(v40, m_pTargets[v41].m_pTarget.m_pPointer);
      }
      else if ( mfnInPlaceNew )
      {
        if ( (_BYTE)v38 )
          UFG::TargetingSimObject::SetTarget(v40, (UFG::SimObject *)mfnInPlaceNew);
      }
      else if ( (_BYTE)v38 )
      {
        v42 = v38;
        UFG::TargetingSimObject::SetTarget(&m_pTargets[v38], 0i64);
        v43 = this->m_pTargets;
        if ( v43[v42].m_bLock )
          v43[v42].m_bLock = 0;
      }
    }
  }
}

// File Line: 1738
// RVA: 0x564DF0
UFG::ScoredTarget *__fastcall UFG::TargetingSystemPedPlayerComponent::chooseBestVisibleTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qFixedArray<UFG::ScoredTarget,100> *potentialTargets,
        const int iMaxRaycastsBeforeGiveUp)
{
  Render::DebugDrawContext *Context; // r15
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  int v9; // xmm10_4
  int v10; // xmm9_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float y; // xmm7_4
  __m128 y_low; // xmm8
  float x; // xmm6_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm11_4
  __m128 v19; // xmm1
  int v20; // r12d
  float v21; // xmm0_4
  float v22; // xmm9_4
  float size; // xmm1_4
  UFG::SimObject *m_pSimObject; // rdi
  __int16 m_Flags; // cx
  unsigned int vfptr; // r8d
  unsigned int v27; // r10d
  UFG::SimComponentHolder *p; // rbx
  __int64 v29; // rdx
  UFG::AICoverComponent *ComponentOfType; // rbx
  unsigned int v31; // r8d
  unsigned int v32; // r10d
  unsigned int v33; // r8d
  unsigned int v34; // r10d
  unsigned int v35; // r8d
  unsigned int v36; // r10d
  UFG::SimObject *m_pPointer; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qMatrix44 *p_mWorldTransform; // rax
  float v40; // xmm7_4
  float v41; // xmm8_4
  float v42; // xmm6_4
  float z; // xmm6_4
  float v44; // xmm11_4
  float v45; // xmm12_4
  float v46; // xmm5_4
  __m128 x_low; // xmm10
  float v48; // xmm9_4
  __m128 v49; // xmm1
  float v50; // xmm1_4
  UFG::RayCastData *p_data; // r14
  char v52; // bl
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v53; // rcx
  const char *TypeName; // rax
  UFG::qReflectObject *mData; // rax
  bool v56; // si
  UFG::qReflectHandleBase *v57; // rcx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v58; // rcx
  const char *v59; // rax
  UFG::qReflectObject *v60; // rax
  float v61; // xmm2_4
  __m128 v62; // xmm3
  float v63; // xmm4_4
  __m128 v64; // xmm5
  float v65; // xmm1_4
  hkpRigidBody *mHavokRigidBody; // rax
  unsigned __int64 m_userData; // rcx
  __int64 v68; // rax
  UFG::SimObject *v69; // rax
  UFG::qVector3 centre; // [rsp+40h] [rbp-80h] BYREF
  UFG::qVector3 rayStart; // [rsp+50h] [rbp-70h] BYREF
  UFG::qVector3 vSegA; // [rsp+60h] [rbp-60h] BYREF
  float v74; // [rsp+6Ch] [rbp-54h]
  float vSegB[2]; // [rsp+70h] [rbp-50h] BYREF
  UFG::qMatrix44 *vSegB_8; // [rsp+78h] [rbp-48h] BYREF
  UFG::qReflectHandleBase v77; // [rsp+80h] [rbp-40h] BYREF
  UFG::qReflectHandleBase v78; // [rsp+A8h] [rbp-18h] BYREF
  __int64 v79; // [rsp+D0h] [rbp+10h]
  UFG::RayCastData data; // [rsp+E0h] [rbp+20h] BYREF
  UFG::RayCastData v81; // [rsp+1C0h] [rbp+100h] BYREF
  UFG::TargetingSystemPedPlayerComponent *v82; // [rsp+390h] [rbp+2D0h]
  float fRadius; // [rsp+398h] [rbp+2D8h] BYREF
  float v84; // [rsp+3A0h] [rbp+2E0h]
  float v85; // [rsp+3A8h] [rbp+2E8h]

  v79 = -2i64;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mCamera = &mCurrentCamera->mCamera;
  else
    p_mCamera = 0i64;
  v9 = LODWORD(p_mCamera->mTransformation.v2.y) ^ _xmm[0];
  v10 = LODWORD(p_mCamera->mTransformation.v2.x) ^ _xmm[0];
  v11 = (float)(*(float *)&v10 * *(float *)&v10) + (float)(*(float *)&v9 * *(float *)&v9);
  if ( v11 == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / fsqrt(v11);
  y = this->m_vTargetingPosition.y;
  y_low = (__m128)LODWORD(p_mCamera->mTransformation.v3.y);
  x = this->m_vTargetingPosition.x;
  v16 = p_mCamera->mTransformation.v3.x;
  v17 = (float)((float)((float)(v12 * *(float *)&v9) * (float)(y - y_low.m128_f32[0]))
              + (float)((float)(x - v16) * (float)(*(float *)&v10 * v12)))
      / (float)((float)((float)(v12 * *(float *)&v9) * *(float *)&v9)
              + (float)((float)(*(float *)&v10 * v12) * *(float *)&v10));
  v18 = (float)(COERCE_FLOAT(LODWORD(p_mCamera->mTransformation.v2.z) ^ _xmm[0]) * v17)
      + p_mCamera->mTransformation.v3.z;
  centre.x = (float)(*(float *)&v10 * v17) + v16;
  centre.y = y_low.m128_f32[0] + (float)(*(float *)&v9 * v17);
  centre.z = v18;
  vSegA.x = v18 - this->m_vTargetingPosition.z;
  y_low.m128_f32[0] = centre.y - y;
  v19 = y_low;
  v19.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                  + (float)((float)(centre.x - x) * (float)(centre.x - x));
  LODWORD(v85) = _mm_sqrt_ps(v19).m128_u32[0];
  if ( (float)((float)((float)((float)(centre.y - y) * this->m_vTargetingLeft.y)
                     + (float)((float)(centre.x - x) * this->m_vTargetingLeft.x))
             + (float)(vSegA.x * this->m_vTargetingLeft.z)) < 0.0 )
    v84 = *(float *)&FLOAT_1_0;
  else
    v84 = FLOAT_N1_0;
  if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
    Render::DebugDrawContext::DrawSphere(
      Context,
      &centre,
      0.1,
      &UFG::qColour::Yellow,
      &UFG::qMatrix44::msIdentity,
      0i64);
  v20 = 0;
  v21 = (float)iMaxRaycastsBeforeGiveUp;
  vSegA.y = (float)iMaxRaycastsBeforeGiveUp;
  v22 = FLOAT_0_5;
  while ( 1 )
  {
    size = (float)(int)potentialTargets->size;
    if ( size >= v21 )
      size = v21;
    if ( (float)v20 >= size )
      return 0i64;
    m_pSimObject = potentialTargets->p[v20].m_pSimObject;
    if ( !m_pSimObject )
      goto LABEL_92;
    vSegB_8 = 0i64;
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      v27 = m_pSimObject->m_Components.size;
      if ( vfptr >= v27 )
        goto LABEL_25;
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v29 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::AICoverComponent::_TypeUID & 0xFE000000)
          && (UFG::AICoverComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= v27 )
          goto LABEL_25;
      }
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        v33 = (unsigned int)m_pSimObject[1].vfptr;
        v34 = m_pSimObject->m_Components.size;
        if ( v33 >= v34 )
          goto LABEL_25;
        p = m_pSimObject->m_Components.p;
        while ( 1 )
        {
          v29 = v33;
          if ( (p[v33].m_TypeUID & 0xFE000000) == (UFG::AICoverComponent::_TypeUID & 0xFE000000)
            && (UFG::AICoverComponent::_TypeUID & ~p[v33].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v33 >= v34 )
            goto LABEL_25;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          ComponentOfType = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                                       m_pSimObject,
                                                       UFG::AICoverComponent::_TypeUID);
          goto LABEL_48;
        }
        v35 = (unsigned int)m_pSimObject[1].vfptr;
        v36 = m_pSimObject->m_Components.size;
        if ( v35 >= v36 )
        {
LABEL_25:
          ComponentOfType = 0i64;
          goto LABEL_48;
        }
        p = m_pSimObject->m_Components.p;
        while ( 1 )
        {
          v29 = v35;
          if ( (p[v35].m_TypeUID & 0xFE000000) == (UFG::AICoverComponent::_TypeUID & 0xFE000000)
            && (UFG::AICoverComponent::_TypeUID & ~p[v35].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v35 >= v36 )
            goto LABEL_25;
        }
      }
    }
    else
    {
      v31 = (unsigned int)m_pSimObject[1].vfptr;
      v32 = m_pSimObject->m_Components.size;
      if ( v31 >= v32 )
        goto LABEL_25;
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v29 = v31;
        if ( (p[v31].m_TypeUID & 0xFE000000) == (UFG::AICoverComponent::_TypeUID & 0xFE000000)
          && (UFG::AICoverComponent::_TypeUID & ~p[v31].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++v31 >= v32 )
          goto LABEL_25;
      }
    }
    ComponentOfType = (UFG::AICoverComponent *)p[v29].m_pComponent;
LABEL_48:
    if ( ComponentOfType
      && UFG::AICoverComponent::IsInCover(ComponentOfType)
      && (m_pPointer = ComponentOfType->m_pSimTargetPopout.m_pPointer) != 0i64
      && (m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent) != 0i64 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      p_mWorldTransform = &m_pTransformNodeComponent->mWorldTransform;
      v40 = m_pTransformNodeComponent->mWorldTransform.v3.x;
      v41 = m_pTransformNodeComponent->mWorldTransform.v3.y;
      v42 = m_pTransformNodeComponent->mWorldTransform.v3.z + s_fCoverPopoutZOffset;
    }
    else
    {
      if ( !UFG::SimObjectUtility::GetObjectCapsuleApproximation(
              m_pSimObject,
              &vSegB_8,
              &vSegA,
              (UFG::qVector3 *)vSegB,
              &fRadius) )
        goto LABEL_92;
      z = vSegA.z;
      if ( vSegA.z <= *(float *)&vSegB_8 )
        z = *(float *)&vSegB_8;
      v41 = (float)(vSegA.y + vSegB[1]) * v22;
      v40 = (float)(vSegA.x + vSegB[0]) * v22;
      v42 = (float)(z + fRadius) + s_fCapsuleZOffset;
      p_mWorldTransform = vSegB_8;
    }
    if ( p_mWorldTransform )
    {
      v44 = this->m_vTargetingPosition.z;
      v45 = this->m_vTargetingPosition.y;
      x_low = (__m128)LODWORD(this->m_vTargetingPosition.x);
      x_low.m128_f32[0] = x_low.m128_f32[0] - v40;
      v46 = (float)((float)(v45 - v41) * UFG::qVector3::msAxisZ.x)
          - (float)(x_low.m128_f32[0] * UFG::qVector3::msAxisZ.y);
      x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * UFG::qVector3::msAxisZ.z)
                        - (float)((float)(v44 - v42) * UFG::qVector3::msAxisZ.x);
      v48 = (float)((float)(v44 - v42) * UFG::qVector3::msAxisZ.y)
          - (float)((float)(v45 - v41) * UFG::qVector3::msAxisZ.z);
      v49 = x_low;
      v49.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v48 * v48))
                      + (float)(v46 * v46);
      if ( v49.m128_f32[0] == 0.0 )
        v50 = 0.0;
      else
        v50 = 1.0 / _mm_sqrt_ps(v49).m128_f32[0];
      rayStart.x = (float)((float)(v84 * v85) * (float)(v48 * v50)) + this->m_vTargetingPosition.x;
      rayStart.y = (float)((float)(v84 * v85) * (float)(x_low.m128_f32[0] * v50)) + v45;
      rayStart.z = (float)(v44 + vSegA.x) + s_fAimThruZOffset;
      if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
      {
        Render::DebugDrawContext::DrawSphere(
          Context,
          &rayStart,
          0.1,
          &UFG::qColour::Green,
          &UFG::qMatrix44::msIdentity,
          0i64);
        Render::DebugDrawContext::DrawSphere(
          Context,
          &rayStart,
          0.1,
          &UFG::qColour::ForestGreen,
          &UFG::qMatrix44::msIdentity,
          0i64);
      }
      centre.x = v40;
      centre.y = v41;
      centre.z = v42;
      data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
      data.mInput.m_filterInfo = 0;
      data.mInput.m_userData = 0i64;
      data.mOutput.m_hitFraction = 1.0;
      data.mOutput.m_extraInfo = -1;
      data.mOutput.m_shapeKeyIndex = 0;
      data.mOutput.m_shapeKeys[0] = -1;
      data.mOutput.m_rootCollidable = 0i64;
      data.mDebugName = 0i64;
      data.mCollisionModelName.mUID = -1;
      v81.mInput.m_enableShapeCollectionFilter.m_bool = 0;
      v81.mInput.m_filterInfo = 0;
      v81.mInput.m_userData = 0i64;
      v81.mOutput.m_hitFraction = 1.0;
      v81.mOutput.m_extraInfo = -1;
      v81.mOutput.m_shapeKeyIndex = 0;
      v81.mOutput.m_shapeKeys[0] = -1;
      v81.mOutput.m_rootCollidable = 0i64;
      v81.mDebugName = 0i64;
      v81.mCollisionModelName.mUID = -1;
      p_data = &data;
      UFG::RayCastData::Init(&data, &rayStart, &centre, 0xCu);
      if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
        Render::DebugDrawContext::DrawLine(
          Context,
          &rayStart,
          &centre,
          &UFG::qColour::Red,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
      v52 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
      if ( !v52 )
        return &potentialTargets->p[v20];
      if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
        Render::DebugDrawContext::DrawPoint(
          Context,
          &data.point,
          &UFG::qColour::Orange,
          &UFG::qMatrix44::msIdentity,
          0i64);
      if ( data.mPhysicsSurfacePropertyHandleUid )
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v77);
        TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v53);
        v77.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v77, v77.mTypeUID, data.mPhysicsSurfacePropertyHandleUid);
        mData = v77.mData;
        if ( !v77.mData )
        {
          UFG::PhysicsPropertyManager::GetDefaultSurfaceProperties((UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *)&v77);
          mData = v77.mData;
        }
        v56 = *(float *)&mData[1].mBaseNode.mUID > 0.0;
        v57 = &v77;
      }
      else
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v78);
        v59 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v58);
        v78.mTypeUID = UFG::qStringHash64(v59, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v78, v78.mTypeUID, data.mPhysicsObjectPropertyHandleUid);
        v60 = v78.mData;
        if ( !v78.mData )
        {
          UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v78);
          v60 = v78.mData;
        }
        v56 = *(float *)(v60[4].mBaseNode.mUID + 88) > 0.0;
        v57 = &v78;
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(v57);
      if ( v56 )
      {
        v61 = centre.x - rayStart.x;
        v62 = (__m128)LODWORD(centre.y);
        v62.m128_f32[0] = centre.y - rayStart.y;
        v63 = centre.z - rayStart.z;
        v64 = v62;
        v64.m128_f32[0] = (float)((float)(v62.m128_f32[0] * v62.m128_f32[0]) + (float)(v61 * v61)) + (float)(v63 * v63);
        if ( v64.m128_f32[0] == 0.0 )
          v65 = 0.0;
        else
          v65 = 1.0 / _mm_sqrt_ps(v64).m128_f32[0];
        vSegA.z = (float)((float)(v61 * v65) * 0.050000001) + data.point.x;
        v74 = (float)((float)(v62.m128_f32[0] * v65) * 0.050000001) + data.point.y;
        vSegB[0] = (float)((float)(v63 * v65) * 0.050000001) + data.point.z;
        UFG::RayCastData::Init(&v81, (UFG::qVector3 *)&vSegA.z, &centre, 0xCu);
        if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
          Render::DebugDrawContext::DrawLine(
            Context,
            (UFG::qVector3 *)&vSegA.z,
            &centre,
            &UFG::qColour::Orange,
            &UFG::qMatrix44::msIdentity,
            0i64,
            0);
        v52 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &v81);
        p_data = &v81;
      }
      if ( !v52 )
        return &potentialTargets->p[v20];
      if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
        Render::DebugDrawContext::DrawPoint(
          Context,
          &p_data->point,
          &UFG::qColour::Red,
          &UFG::qMatrix44::msIdentity,
          0i64);
      mHavokRigidBody = p_data->mHavokRigidBody;
      if ( mHavokRigidBody )
      {
        m_userData = mHavokRigidBody->m_userData;
        if ( m_userData )
        {
          v68 = *(_QWORD *)(m_userData + 24);
          v69 = v68 ? *(UFG::SimObject **)(v68 + 40) : 0i64;
          if ( v69 == m_pSimObject )
            return &potentialTargets->p[v20];
        }
      }
      v22 = FLOAT_0_5;
      this = v82;
    }
LABEL_92:
    ++v20;
    v21 = vSegA.y;
  }
}   if ( mHavokRigidBody )
      {
        m_userData = mHavokRigidBody->m_userData;
        if ( m_userData )
        {
          v68 = *(_QWORD *)(m_userData + 24);
          v69 = v68 ? *(UFG::SimObject **)(v68 + 40) : 0i64;
          if ( v69 == m_pSimObject )
            return &pot

// File Line: 1979
// RVA: 0x56D0B0
char __fastcall UFG::TargetingSystemPedPlayerComponent::shouldCycleTarget(UFG::TargetingSystemPedPlayerComponent *this)
{
  unsigned __int8 v2; // r9
  __int64 v3; // rax
  __int64 v4; // rax
  bool v5; // al
  bool v6; // di
  __int64 mPrev_low; // rsi
  UFG::InputActionData *v8; // rcx
  UFG::InputActionData *v9; // rax
  bool v10; // al
  UFG::InputActionData *v11; // rcx
  float mAxisPositionX; // xmm0_4
  UFG::InputActionData *v14; // rax
  bool v15; // al
  UFG::InputActionData *v16; // rcx
  float v17; // xmm0_4
  bool v18; // zf
  UFG::InputActionData *v19; // rax
  UFG::InputActionData *v20; // rcx
  UFG::InputActionData *v21; // rcx
  float v22; // xmm6_4
  float x; // xmm7_4
  UFG::InputActionData *v24; // rax
  bool v25; // cl
  UFG::InputActionData *v26; // rax
  bool v27; // al
  UFG::InputActionData *v28; // rax
  UFG::InputActionData *v29; // rdx
  UFG::InputActionData *v30; // rax
  bool v31; // cl
  UFG::InputActionData *v32; // rax
  bool v33; // al
  UFG::InputActionData *v34; // rax
  float v35; // xmm0_4
  float v36; // xmm0_4
  UFG::InputActionData *v37; // rax
  bool v38; // al
  UFG::InputActionData *v39; // rcx
  int v40; // eax

  v2 = 0;
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v3 = *((_QWORD *)&this->m_pAICharacterControllerBaseComponent.m_pSimComponent[4].m_BoundComponentHandles.mNode.mPrev
         + ((__int64)(int)gActionRequest_Focus.m_EnumValue >> 6));
    v2 = _bittest64(&v3, gActionRequest_Focus.m_EnumValue & 0x3F);
  }
  v5 = 0;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v4 = *((_QWORD *)&this->m_pActionTreeComponent.m_pSimComponent[11].m_SafePointerList.mNode.mPrev
         + ((__int64)(int)gActionRequest_CameraZoom.m_EnumValue >> 6));
    if ( _bittest64(&v4, gActionRequest_CameraZoom.m_EnumValue & 0x3F) )
      v5 = 1;
  }
  v6 = 0;
  if ( (this->m_bTargetAutoAcquisition || v2 && !v5 && this->m_eFocusMode == eFOCUS_MODE_LOCKED)
    && this->m_pAICharacterControllerComponent.m_pSimComponent )
  {
    mPrev_low = SLODWORD(this->m_pAICharacterControllerComponent.m_pSimComponent[17].m_SafePointerList.mNode.mPrev);
    switch ( UFG::TargetingSystemPedPlayerComponent::ms_eTargetCycleAndLocationTargetingModeEnum )
    {
      case TCALTM_NO_LOCATION:
      case TCALTM_SLIGHTLY_PRESS_AIM:
        v8 = UFG::ActionDef_TargetCycle.mDataPerController[mPrev_low];
        return v8 && v8->mActionTrue;
      case TCALTM_SLIGHTLY_RELEASE_FOCUS:
        v9 = UFG::ActionDef_TargetCycle.mDataPerController[mPrev_low];
        v10 = v9 && v9->mActionTrue;
        v11 = UFG::ActionDef_Focus.mDataPerController[mPrev_low];
        if ( v11 )
          mAxisPositionX = v11->mAxisPositionX;
        else
          mAxisPositionX = 0.0;
        return v10 && mAxisPositionX >= 1.0;
      case TCALTM_SLIGHTLY_PRESS_FIRE:
        v14 = UFG::ActionDef_TargetCycle.mDataPerController[mPrev_low];
        v15 = v14 && v14->mActionTrue;
        v16 = UFG::ActionDef_FireTest.mDataPerController[mPrev_low];
        if ( v16 )
          v17 = v16->mAxisPositionX;
        else
          v17 = 0.0;
        v18 = !v15;
        return !v18 && v17 <= 0.0;
      case TCALTM_RELEASE_AIM_QUICKLY_TO_CYCLE_DELAY:
        if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
        {
          v19 = UFG::ActionDef_TargetCycleUp.mDataPerController[mPrev_low];
          if ( !v19 || !v19->mActionTrue )
          {
            v20 = UFG::ActionDef_TargetCycleDown.mDataPerController[mPrev_low];
            if ( !v20 || !v20->mActionTrue )
              return 0;
          }
          if ( v19 && v19->mActionTrue )
            v6 = 1;
          this->m_bTargetCycleDirectionLeft = v6;
          this->m_bTargetCycleDesired = 0;
          return 1;
        }
        if ( UFG::TargetingSystemPedPlayerComponent::useTargetRelativeMeleeCycling(this) )
        {
          v21 = UFG::ActionDef_TargetCycle.mDataPerController[mPrev_low];
          if ( v21 && v21->mActionTrue )
            return 1;
          return v6;
        }
        if ( this->m_bHasFullAimInputTransition )
        {
          if ( (_S43 & 1) != 0 )
          {
            v22 = s_fMaxAngleRad;
          }
          else
          {
            _S43 |= 1u;
            v22 = FLOAT_0_87266463;
            s_fMaxAngleRad = FLOAT_0_87266463;
          }
          x = this->m_vAimInputDir.x;
          if ( atan2f(COERCE_FLOAT(LODWORD(this->m_vAimInputDir.y) & _xmm), COERCE_FLOAT(LODWORD(x) & _xmm)) <= v22 )
          {
            this->m_bTargetCycleDirectionLeft = x < 0.0;
            this->m_bTargetCycleDesired = 1;
          }
        }
        if ( this->m_bHasNoAimInputTransition
          && this->m_bTargetCycleDesired
          && UFG::TargetingSystemPedPlayerComponent::ms_fTimeToTargetCycle > this->m_fTimeSinceStartedInput )
        {
          this->m_fTimeSinceStartedInput = UFG::TargetingSystemPedPlayerComponent::ms_fTimeToTargetCycle;
          this->m_bTargetCycleDesired = 0;
          return 1;
        }
        if ( !this->m_bHasAimInput )
          this->m_bTargetCycleDesired = 0;
        return 0;
      case TCALTM_PRESS_STICK_TO_AIM:
      case TCALTM_PRESS_STICK_TO_START_AIM:
        v24 = UFG::ActionDef_TargetCycle.mDataPerController[mPrev_low];
        v25 = v24 && v24->mActionTrue;
        v26 = UFG::ActionDef_AimLocationHold.mDataPerController[mPrev_low];
        v27 = v26 && v26->mActionTrue;
        return v25 && !v27;
      case TCALTM_PRESS_STICK_TO_START_AIM_MODE:
        v28 = UFG::ActionDef_TargetCycle.mDataPerController[mPrev_low];
        v25 = v28 && v28->mActionTrue;
        v29 = UFG::ActionDef_AimLocationToggle.mDataPerController[mPrev_low];
        if ( v29 )
        {
          v27 = s_bAimModeActive;
          if ( v29->mActionTrue )
            v27 = 1;
          s_bAimModeActive = v27;
        }
        else
        {
          v27 = s_bAimModeActive;
        }
        return v25 && !v27;
      case TCALTM_PRESS_STICK_TO_START_AIM_TIME:
        v30 = UFG::ActionDef_TargetCycle.mDataPerController[mPrev_low];
        v31 = v30 && v30->mActionTrue;
        v32 = UFG::ActionDef_AimLocationToggle.mDataPerController[mPrev_low];
        v33 = v32 && v32->mActionTrue;
        v17 = s_fAimModeActiveS - UFG::Metrics::msInstance.mSimTimeUnscaledDelta;
        if ( (float)(s_fAimModeActiveS - UFG::Metrics::msInstance.mSimTimeUnscaledDelta) < 0.0 )
          v17 = 0.0;
        s_fAimModeActiveS = v17;
        if ( v33 )
        {
          v17 = s_fAimModeActiveDuration;
          s_fAimModeActiveS = s_fAimModeActiveDuration;
        }
        v18 = !v31;
        return !v18 && v17 <= 0.0;
      case TCALTM_PRESS_STICK_TO_CYCLE:
        v34 = UFG::ActionDef_TargetCycle.mDataPerController[mPrev_low];
        if ( v34 )
          v35 = v34->mAxisPositionX;
        else
          v35 = 0.0;
        LODWORD(v36) = LODWORD(v35) & _xmm;
        v37 = UFG::ActionDef_AimLocationToggle.mDataPerController[mPrev_low];
        v38 = v37 && v37->mActionTrue;
        return v36 > 0.0 && v38;
      case TCALTM_DOUBLE_TAP_TO_CYCLE:
        v39 = UFG::ActionDef_TargetCycle.mDataPerController[mPrev_low];
        if ( v39 && v39->mActionTrue )
          v40 = ++s_iNumTimesTargetCycleHit;
        else
          v40 = s_iNumTimesTargetCycleHit;
        if ( v40 >= 2 )
        {
          s_iNumTimesTargetCycleHit = 0;
          return 1;
        }
        if ( this->m_bHasAimInput )
        {
          s_fTimeNotAiming = 0.0;
        }
        else
        {
          s_fTimeNotAiming = s_fTimeNotAiming + UFG::Metrics::msInstance.mSimTimeUnscaledDelta;
          if ( s_fTimeNotAiming >= s_fTimeToResetEdgeHit )
            s_iNumTimesTargetCycleHit = 0;
        }
        break;
      default:
        return 0;
    }
  }
  return 0;
}

// File Line: 2180
// RVA: 0x564A00
void __fastcall UFG::TargetingSystemPedPlayerComponent::canActionHijackThisVehicle(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::SimObjectVehicle *pPotentialVehicleSimObject,
        UFG::qVector3 *pXform,
        bool *bCanActionHijackThisVehicle,
        bool *bCanPotentiallyActionHijackThisVehicle)
{
  UFG::PhysicsMoverInterface *ComponentOfType; // rbp
  UFG::TargetingSystemVehicleComponent *m_pComponent; // rdi
  UFG::ActionHijackProfile *m_pActionHijackProfile; // rdi
  double v12; // xmm0_8
  UFG::PhysicsMoverInterface *v13; // rcx
  float LinearVelocityMagnitudeKPH; // xmm0_4
  float v15; // xmm6_4
  UFG::SimObject *m_pPointer; // r9
  float v17; // xmm8_4
  float v18; // xmm12_4
  float v19; // xmm13_4
  float v20; // xmm14_4
  __int16 m_Flags; // cx
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  __int64 v24; // rdx
  float v25; // xmm7_4
  float m_fSpeedDifferenceModifiesDistanceAheadStart; // xmm9_4
  float m_fSpeedDifferenceModifiesDistanceAheadEnd; // xmm7_4
  float v28; // xmm10_4
  float m_fDistanceAheadOfTargetMax; // xmm6_4
  bool v30; // bl
  float DistanceBehindTargetMax; // xmm0_4
  bool v32; // al
  bool v33; // al
  float v34; // xmm0_4
  float v35; // xmm6_4
  float v36; // xmm1_4
  float v37; // xmm8_4

  ComponentOfType = 0i64;
  *bCanActionHijackThisVehicle = 0;
  *bCanPotentiallyActionHijackThisVehicle = 0;
  if ( !pPotentialVehicleSimObject
    || (m_pComponent = (UFG::TargetingSystemVehicleComponent *)pPotentialVehicleSimObject->m_Components.p[20].m_pComponent) == 0i64
    || ((UFG::TargetingSystemVehicleComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0
    || (UFG::TargetingSystemVehicleComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
  {
    m_pActionHijackProfile = 0i64;
  }
  else
  {
    m_pActionHijackProfile = m_pComponent->m_pActionHijackProfile;
  }
  if ( !m_pActionHijackProfile )
    return;
  if ( !m_pActionHijackProfile->m_bCanActionHijackTo )
    return;
  v12 = UFG::qAngleBetweenNormals(&this->m_vTargetingForward, pXform);
  if ( *(float *)&v12 > m_pActionHijackProfile->m_fOrientationDeltaRadMax )
    return;
  if ( !pPotentialVehicleSimObject )
    return;
  v13 = (UFG::PhysicsMoverInterface *)pPotentialVehicleSimObject->m_Components.p[34].m_pComponent;
  if ( !v13 )
    return;
  LinearVelocityMagnitudeKPH = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(v13);
  v15 = LinearVelocityMagnitudeKPH;
  if ( !UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreSpeed
    && LinearVelocityMagnitudeKPH < m_pActionHijackProfile->m_fVehicleSpeedMinKPH )
  {
    return;
  }
  m_pPointer = this->m_pOccupantOfVehicle.m_pPointer;
  v17 = this->m_vTargetingPosition.y - pXform[4].y;
  v18 = this->m_vTargetingPosition.x - pXform[4].x;
  v19 = this->m_vTargetingPosition.z - pXform[4].z;
  v20 = (float)((float)(v17 * this->m_vTargetingForward.y) + (float)(v18 * this->m_vTargetingForward.x))
      + (float)(v19 * this->m_vTargetingForward.z);
  if ( !m_pPointer )
    goto LABEL_30;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_30;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      goto LABEL_30;
    if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)m_pPointer[1].vfptr;
      size = m_pPointer->m_Components.size;
      if ( vfptr < size )
      {
        v24 = (__int64)&m_pPointer->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
             || (UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v24 += 16i64;
          if ( vfptr >= size )
            goto LABEL_28;
        }
        ComponentOfType = *(UFG::PhysicsMoverInterface **)v24;
      }
    }
    else
    {
      ComponentOfType = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::PhysicsMoverInterface::_TypeUID);
    }
  }
  else
  {
    ComponentOfType = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
  }
LABEL_28:
  if ( ComponentOfType )
  {
    v25 = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(ComponentOfType);
    goto LABEL_31;
  }
LABEL_30:
  v25 = FLOAT_N1_0;
LABEL_31:
  m_fSpeedDifferenceModifiesDistanceAheadStart = m_pActionHijackProfile->m_fSpeedDifferenceModifiesDistanceAheadStart;
  LODWORD(m_fSpeedDifferenceModifiesDistanceAheadEnd) = COERCE_UNSIGNED_INT(v25 - v15) & _xmm;
  if ( m_fSpeedDifferenceModifiesDistanceAheadEnd <= m_fSpeedDifferenceModifiesDistanceAheadStart )
    m_fSpeedDifferenceModifiesDistanceAheadEnd = m_pActionHijackProfile->m_fSpeedDifferenceModifiesDistanceAheadStart;
  if ( m_fSpeedDifferenceModifiesDistanceAheadEnd >= m_pActionHijackProfile->m_fSpeedDifferenceModifiesDistanceAheadEnd )
    m_fSpeedDifferenceModifiesDistanceAheadEnd = m_pActionHijackProfile->m_fSpeedDifferenceModifiesDistanceAheadEnd;
  m_fDistanceAheadOfTargetMax = m_pActionHijackProfile->m_fDistanceAheadOfTargetMax;
  v28 = m_pActionHijackProfile->m_fSpeedDifferenceModifiesDistanceAheadEnd
      - m_fSpeedDifferenceModifiesDistanceAheadStart;
  v30 = (float)(m_fDistanceAheadOfTargetMax
              - (float)((float)(UFG::ActionHijackProfile::GetDistanceBehindTargetMax(m_pActionHijackProfile)
                              + m_fDistanceAheadOfTargetMax)
                      * (float)((float)(m_fSpeedDifferenceModifiesDistanceAheadEnd
                                      - m_fSpeedDifferenceModifiesDistanceAheadStart)
                              / v28))) >= v20;
  DistanceBehindTargetMax = UFG::ActionHijackProfile::GetDistanceBehindTargetMax(m_pActionHijackProfile);
  *bCanPotentiallyActionHijackThisVehicle = v30;
  v32 = v30 && v20 >= COERCE_FLOAT(LODWORD(DistanceBehindTargetMax) ^ _xmm[0]);
  if ( UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreDistance || v32 )
  {
    *bCanPotentiallyActionHijackThisVehicle = 1;
    v33 = UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreDistance;
    if ( !UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreDistance )
    {
      v34 = pXform[4].x - this->m_vTargetingPosition.x;
      v36 = pXform[4].z - this->m_vTargetingPosition.z;
      v35 = pXform[4].y - this->m_vTargetingPosition.y;
      if ( (float)((float)((float)(v35 * v35) + (float)(v34 * v34)) + (float)(v36 * v36)) > UFG::ActionHijackProfile::GetDistanceSquaredMax(m_pActionHijackProfile) )
        return;
      v33 = UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreDistance;
    }
    v37 = (float)((float)(v17 * pXform[1].z) + (float)(v18 * pXform[1].y)) + (float)(v19 * pXform[2].x);
    if ( v33
      || COERCE_FLOAT(LODWORD(v37) & _xmm) <= UFG::ActionHijackProfile::GetDistanceToSideMax(m_pActionHijackProfile) )
    {
      *bCanActionHijackThisVehicle = 1;
      *bCanPotentiallyActionHijackThisVehicle = 1;
    }
  }
}

// File Line: 2262
// RVA: 0x572600
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateFocusTargetStep2(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList,
        UFG::qFixedArray<UFG::CloseTarget *,5> *closePickupsList,
        UFG::qFixedArray<UFG::CloseTarget *,5> *closePropsList)
{
  UFG::eFocusModeEnum m_eFocusMode; // eax
  bool v7; // r12
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdi
  __int16 v9; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v11; // r8d
  unsigned int v12; // r9d
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rsi
  __int64 v14; // rdx
  unsigned int v15; // r8d
  unsigned int v16; // r9d
  unsigned int v17; // r8d
  unsigned int v18; // r9d
  float v19; // xmm0_4
  unsigned __int8 v20; // cl
  bool v21; // r15
  unsigned int size; // ebp
  unsigned int v23; // esi
  UFG::CloseTarget **p; // r14
  UFG::SimObject *m_pSimObject; // rdi
  UFG::qMatrix44 *p_m_Xform; // r9
  float v27; // xmm0_4
  __int64 v28; // rax
  UFG::ScoredTarget *v29; // rax
  UFG::ScoredTarget *v30; // rsi
  UFG::SimObject *v31; // rdx
  unsigned __int8 v32; // al
  UFG::SimObject *v33; // rcx
  UFG::ActionTreeComponent *m_pComponent; // rdi
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int v37; // r9d
  __int64 v38; // rdx
  UFG::SimObject *v39; // rcx
  UFG::HealthComponent *v40; // rax
  __int16 v41; // dx
  unsigned int v42; // r8d
  unsigned int v43; // r9d
  UFG::SimComponentHolder *v44; // rsi
  __int64 v45; // rdx
  unsigned int v46; // r8d
  unsigned int v47; // r9d
  unsigned __int8 v48; // cl
  unsigned __int64 v49; // rdi
  UFG::TargetingSimObject *m_pTargets; // rax
  UFG::qMatrix44 matSimObject; // [rsp+40h] [rbp-6B8h] BYREF
  UFG::qFixedArray<UFG::ScoredTarget,100> potentialTargets; // [rsp+80h] [rbp-678h] BYREF

  potentialTargets.size = 0;
  m_eFocusMode = this->m_eFocusMode;
  v7 = m_eFocusMode == eFOCUS_MODE_LOCKED_SOFT;
  if ( (unsigned int)(m_eFocusMode - 3) > 1 && m_eFocusMode != eFOCUS_MODE_LOCKED_SOFT )
    goto LABEL_41;
  mPrev = this->m_pAimingPlayerComponent.m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
  if ( !mPrev )
    goto LABEL_41;
  v9 = WORD2(mPrev[4].mNext);
  if ( (v9 & 0x4000) != 0 )
  {
    ComponentOfType = (UFG::SimComponent *)mPrev[6].mNext[44].mPrev;
    goto LABEL_30;
  }
  if ( v9 < 0 )
  {
    v11 = (unsigned int)mPrev[8].mPrev;
    v12 = (unsigned int)mPrev[6].mPrev;
    if ( v11 < v12 )
    {
      mNext = mPrev[6].mNext;
      while ( 1 )
      {
        v14 = v11;
        if ( ((__int64)mNext[v11].mNext & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && (UFG::CharacterOccupantComponent::_TypeUID & ~LODWORD(mNext[v11].mNext) & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++v11 >= v12 )
          goto LABEL_14;
      }
LABEL_13:
      ComponentOfType = (UFG::SimComponent *)mNext[v14].mPrev;
      goto LABEL_30;
    }
    goto LABEL_14;
  }
  if ( (v9 & 0x2000) != 0 )
  {
    v15 = (unsigned int)mPrev[8].mPrev;
    v16 = (unsigned int)mPrev[6].mPrev;
    if ( v15 < v16 )
    {
      mNext = mPrev[6].mNext;
      while ( 1 )
      {
        v14 = v15;
        if ( ((__int64)mNext[v15].mNext & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && (UFG::CharacterOccupantComponent::_TypeUID & ~LODWORD(mNext[v15].mNext) & 0x1FFFFFF) == 0 )
        {
          goto LABEL_13;
        }
        if ( ++v15 >= v16 )
          goto LABEL_14;
      }
    }
    goto LABEL_14;
  }
  if ( (v9 & 0x1000) != 0 )
  {
    v17 = (unsigned int)mPrev[8].mPrev;
    v18 = (unsigned int)mPrev[6].mPrev;
    if ( v17 < v18 )
    {
      mNext = mPrev[6].mNext;
      do
      {
        v14 = v17;
        if ( ((__int64)mNext[v17].mNext & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && (UFG::CharacterOccupantComponent::_TypeUID & ~LODWORD(mNext[v17].mNext) & 0x1FFFFFF) == 0 )
        {
          goto LABEL_13;
        }
      }
      while ( ++v17 < v18 );
    }
LABEL_14:
    ComponentOfType = 0i64;
    goto LABEL_30;
  }
  ComponentOfType = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)mPrev,
                      UFG::CharacterOccupantComponent::_TypeUID);
LABEL_30:
  if ( ComponentOfType )
  {
    if ( !ComponentOfType[1].m_BoundComponentHandles.mNode.mPrev )
      goto LABEL_41;
    mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)ComponentOfType[1].m_BoundComponentHandles.mNode.mPrev[2].mNext;
  }
  if ( mPrev )
  {
    UFG::TargetingSystemBaseComponent::FindMatrix(
      (UFG::TransformNodeComponent *)mPrev[5].mNext,
      (UFG::SimObject *)mPrev,
      &matSimObject);
    v19 = UFG::TargetingSystemPedPlayerComponent::scoreSoftLockTarget(
            this,
            &this->m_vTargetingPosition,
            (UFG::SimObject *)mPrev,
            &matSimObject,
            this->m_pOccupantOfVehicle.m_pPointer);
    if ( v19 >= 0.0 )
    {
      if ( this->m_eDesiredFocusMode == eFOCUS_MODE_LOCKED && this->m_pOccupantOfVehicle.m_pPointer )
        v19 = UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(
                this,
                &this->m_vTargetingPosition,
                (UFG::SimObject *)mPrev,
                &matSimObject,
                0,
                0);
      if ( v19 >= 0.0 )
      {
        v20 = this->m_pTargetingMap->m_Map.p[22];
        if ( v20 )
          UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v20], (UFG::SimObject *)mPrev);
        return;
      }
    }
  }
LABEL_41:
  v21 = this->m_bHasRangedWeapon && (unsigned int)(this->m_eFocusMode - 1) <= 3;
  size = closePedsList->size;
  v23 = 0;
  if ( closePedsList->size )
  {
    p = closePedsList->p;
    while ( 1 )
    {
      m_pSimObject = (*p)->m_pSimObjectPropertiesComponent->m_pSimObject;
      if ( !m_pSimObject )
        return;
      p_m_Xform = &(*p)->m_Xform;
      if ( !v21 )
        break;
      if ( !v7 )
      {
        if ( this->m_pOccupantOfVehicle.m_pPointer
          && this->m_bFocusModeJustRequested
          && !this->m_bHasNoAimInputTransition )
        {
          v27 = UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(
                  this,
                  &this->m_vTargetingPosition,
                  m_pSimObject,
                  p_m_Xform,
                  0,
                  1);
        }
        else
        {
          v27 = UFG::TargetingSystemPedPlayerComponent::scoreSoftLockTarget(
                  this,
                  &this->m_vTargetingPosition,
                  m_pSimObject,
                  p_m_Xform,
                  this->m_pOccupantOfVehicle.m_pPointer);
        }
LABEL_56:
        if ( v27 >= 0.0 && potentialTargets.size < 0x64 )
        {
          v28 = potentialTargets.size++;
          potentialTargets.p[v28].m_pSimObject = m_pSimObject;
          potentialTargets.p[v28].m_fScore = v27;
        }
      }
      ++v23;
      ++p;
      if ( v23 >= size )
        goto LABEL_60;
    }
    v27 = UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(
            this,
            &this->m_vTargetingPosition,
            m_pSimObject,
            p_m_Xform,
            1,
            0);
    goto LABEL_56;
  }
LABEL_60:
  UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
    (ClassTypeDescriptor *)potentialTargets.p,
    (ClassTypeDescriptor *)&matSimObject.v3.z + (int)potentialTargets.size,
    (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
  v29 = UFG::TargetingSystemPedPlayerComponent::chooseBestVisibleTarget(
          this,
          &potentialTargets,
          UFG::TargetingSystemPedPlayerComponent::ms_MaxRaycastsBeforeGiveUpNormally);
  v30 = v29;
  this->m_bHasPriorityTarget = 0;
  if ( v29 && (v31 = v29->m_pSimObject) != 0i64 )
  {
    v32 = this->m_pTargetingMap->m_Map.p[22];
    if ( v32 )
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v32], v31);
    if ( v30->m_fScore >= 0.0 && v30->m_fScore < 2.0 )
    {
      v33 = v30->m_pSimObject;
      if ( !v33 )
      {
LABEL_67:
        m_pComponent = 0i64;
        goto LABEL_82;
      }
      m_Flags = v33->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::ActionTreeComponent *)v33->m_Components.p[7].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = (UFG::ActionTreeComponent *)v33->m_Components.p[6].m_pComponent;
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          vfptr = (unsigned int)v33[1].vfptr;
          v37 = v33->m_Components.size;
          if ( vfptr >= v37 )
            goto LABEL_67;
          while ( 1 )
          {
            v38 = (__int64)&v33->m_Components.p[vfptr];
            if ( (*(_DWORD *)(v38 + 8) & 0xFE000000) == (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
              && (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF) == 0 )
            {
              break;
            }
            if ( ++vfptr >= v37 )
              goto LABEL_67;
          }
          m_pComponent = *(UFG::ActionTreeComponent **)v38;
        }
        else
        {
          m_pComponent = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                                       v33,
                                                       UFG::ActionTreeComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = (UFG::ActionTreeComponent *)v33->m_Components.p[7].m_pComponent;
      }
LABEL_82:
      v39 = v30->m_pSimObject;
      if ( !v39 )
      {
LABEL_83:
        v40 = 0i64;
        goto LABEL_104;
      }
      v41 = v39->m_Flags;
      if ( (v41 & 0x4000) != 0 )
      {
        v40 = (UFG::HealthComponent *)v39->m_Components.p[6].m_pComponent;
        goto LABEL_104;
      }
      if ( v41 < 0 )
      {
        v40 = (UFG::HealthComponent *)v39->m_Components.p[6].m_pComponent;
        goto LABEL_104;
      }
      if ( (v41 & 0x2000) != 0 )
      {
        v42 = (unsigned int)v39[1].vfptr;
        v43 = v39->m_Components.size;
        if ( v42 >= v43 )
          goto LABEL_83;
        v44 = v39->m_Components.p;
        while ( 1 )
        {
          v45 = v42;
          if ( (v44[v42].m_TypeUID & 0xFE000000) == (UFG::HealthComponent::_TypeUID & 0xFE000000)
            && (UFG::HealthComponent::_TypeUID & ~v44[v42].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v42 >= v43 )
            goto LABEL_83;
        }
      }
      else
      {
        if ( (v41 & 0x1000) == 0 )
        {
          v40 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(v39, UFG::HealthComponent::_TypeUID);
LABEL_104:
          if ( !UFG::IsDowned(m_pComponent, v40) )
            this->m_bHasPriorityTarget = 1;
          return;
        }
        v46 = (unsigned int)v39[1].vfptr;
        v47 = v39->m_Components.size;
        if ( v46 >= v47 )
          goto LABEL_83;
        v44 = v39->m_Components.p;
        while ( 1 )
        {
          v45 = v46;
          if ( (v44[v46].m_TypeUID & 0xFE000000) == (UFG::HealthComponent::_TypeUID & 0xFE000000)
            && (UFG::HealthComponent::_TypeUID & ~v44[v46].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v46 >= v47 )
            goto LABEL_83;
        }
      }
      v40 = (UFG::HealthComponent *)v44[v45].m_pComponent;
      goto LABEL_104;
    }
  }
  else
  {
    v48 = this->m_pTargetingMap->m_Map.p[22];
    if ( v48 )
    {
      v49 = v48;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v49], 0i64);
      m_pTargets = this->m_pTargets;
      if ( m_pTargets[v49].m_bLock )
        m_pTargets[v49].m_bLock = 0;
    }
  }
}UFG::HealthComponent *)v44[v45].m_pComponent;
      goto LABEL_104;
    }
  }
  else
  {
    v48 = this->m_pTargetingMap->m_Map.p[22];
    if ( v48 )
    {
      v49 = v48;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v49], 0i64);

// File Line: 2459
// RVA: 0x571850
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateFocusTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList,
        unsigned __int64 closePickupsList,
        UFG::qFixedArray<UFG::CloseTarget *,5> *closePropsList,
        UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList,
        UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList)
{
  UFG::qFixedArray<UFG::CloseTarget *,5> *v6; // r12
  UFG::qFixedArray<UFG::CloseTarget *,5> *v8; // r15
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v11; // rcx
  bool v12; // bp
  char shouldCycleTarget; // al
  UFG::qFixedArray<UFG::CloseTarget,100> *v14; // r14
  UFG::SimComponent *m_pSimComponent; // rdi
  unsigned int ActionMostUsedIndex_Grapple; // ebx
  ActionID *ActionID_Grapple; // rax
  UFG::SimComponent *v18; // rbx
  unsigned int ActionMostUsedIndex_Hostage; // edi
  ActionID *ActionID_Hostage; // rax
  char v21; // al
  UFG::SimComponent *v22; // rax
  int mPrev; // ecx
  bool m_bTargetCycleDirectionLeft; // al
  UFG::InputActionData *v25; // rcx
  float v26; // xmm0_4
  UFG::SimObject *m_pPointer; // rbx
  UFG::SimComponent *v28; // rax
  float v29; // xmm0_4
  UFG::eFocusModeEnum m_eFocusMode; // eax
  UFG::qFixedArray<UFG::CloseTarget *,20> *v31; // rdi
  UFG::eFocusModeEnum m_eDesiredFocusMode; // ebx
  UFG::TargetingMap *m_pTargetingMap; // rax
  UFG::SimObject *Texture; // rdi
  __int16 m_Flags; // cx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v38; // rdx
  hkSimpleLocalFrame *m_pComponent; // rbx
  unsigned int v40; // r8d
  unsigned int v41; // r9d
  unsigned int v42; // r8d
  unsigned int v43; // r9d
  __int16 v44; // dx
  UFG::SimComponent *v45; // rax
  unsigned int v46; // r8d
  unsigned int v47; // r9d
  __int64 v48; // rdx
  unsigned int v49; // r8d
  unsigned int v50; // r9d
  char v51; // bp
  bool isHostileToMe; // r14
  __int16 v53; // dx
  UFG::SimComponent *ComponentOfType; // rdi
  __int64 v55; // rdx
  unsigned int v56; // ebx
  ActionID *v57; // rax
  char v58; // al
  UFG::qFixedArray<UFG::CloseTarget *,20> *v59; // rax
  UFG::TargetingMap *v60; // rax
  UFG::SimObject *v61; // rdi
  __int16 v62; // cx
  UFG::SimObject *v63; // rbp
  __int64 v64; // rdx
  hkSimpleLocalFrame *v65; // rbx
  __int16 v66; // dx
  UFG::SimComponent *v67; // rax
  __int64 v68; // rdx
  __int16 v69; // cx
  UFG::SimComponent *v70; // rax
  __int64 v71; // rdx
  int mNext; // ecx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v73; // rax
  bool v74; // zf
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pFocusModeOverrideSimObject; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v76; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v77; // rax
  bool bTargetVehicleHasOccupant; // [rsp+60h] [rbp-98h] BYREF
  bool bIsSocialActionAvailable; // [rsp+61h] [rbp-97h] BYREF
  bool bIsTargetVehicle; // [rsp+62h] [rbp-96h] BYREF
  bool bIsScripted; // [rsp+63h] [rbp-95h] BYREF
  bool bIsKnockedOut; // [rsp+64h] [rbp-94h] BYREF
  bool bIsDowned; // [rsp+65h] [rbp-93h] BYREF
  UFG::eFactionStandingEnum eFactionStanding; // [rsp+68h] [rbp-90h] BYREF
  UFG::SimObject *pPedTarget; // [rsp+70h] [rbp-88h] BYREF
  UFG::qMatrix44 matSimObject; // [rsp+80h] [rbp-78h] BYREF
  bool bShouldRejectTarget; // [rsp+100h] [rbp+8h] BYREF

  v6 = (UFG::qFixedArray<UFG::CloseTarget *,5> *)closePickupsList;
  v8 = closePropsList;
  if ( !this->m_pFocusModeOverrideSimObject.m_pPointer )
  {
    UFG::TargetingSystemPedPlayerComponent::maybeReleaseLockedTarget(this);
    m_pTargets = this->m_pTargets;
    v11 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[22];
    v12 = m_pTargets[v11].m_pTarget.m_pPointer && m_pTargets[v11].m_bLock;
    shouldCycleTarget = UFG::TargetingSystemPedPlayerComponent::shouldCycleTarget(this);
    v14 = closeTargetsList;
    if ( shouldCycleTarget )
    {
      m_pSimComponent = this->m_pActionTreeComponent.m_pSimComponent;
      if ( m_pSimComponent )
      {
        ActionMostUsedIndex_Grapple = UFG::GetActionMostUsedIndex_Grapple();
        ActionID_Grapple = UFG::GetActionID_Grapple();
        if ( !ActionController::IsPlaying(
                (ActionController *)&m_pSimComponent[3],
                ActionID_Grapple,
                ActionMostUsedIndex_Grapple,
                0)
          || (v18 = this->m_pActionTreeComponent.m_pSimComponent,
              ActionMostUsedIndex_Hostage = UFG::GetActionMostUsedIndex_Hostage(),
              ActionID_Hostage = UFG::GetActionID_Hostage(),
              ActionController::IsPlaying((ActionController *)&v18[3], ActionID_Hostage, ActionMostUsedIndex_Hostage, 1)) )
        {
          if ( UFG::TargetingSystemPedPlayerComponent::useTargetRelativeMeleeCycling(this) )
          {
            v21 = UFG::TargetingSystemPedPlayerComponent::cycleTargetManual(this, v14);
          }
          else
          {
            v22 = this->m_pAICharacterControllerComponent.m_pSimComponent;
            mPrev = 0;
            if ( v22 )
              mPrev = (int)v22[17].m_SafePointerList.mNode.mPrev;
            if ( UFG::TargetingSystemPedPlayerComponent::ms_eTargetCycleAndLocationTargetingModeEnum == TCALTM_RELEASE_AIM_QUICKLY_TO_CYCLE_DELAY )
            {
              m_bTargetCycleDirectionLeft = this->m_bTargetCycleDirectionLeft;
            }
            else
            {
              v25 = UFG::ActionDef_TargetCycle.mDataPerController[mPrev];
              if ( v25 )
                v26 = v25->mAxisRawX[0];
              else
                v26 = 0.0;
              m_bTargetCycleDirectionLeft = v26 < 0.0;
            }
            v21 = UFG::TargetingSystemPedPlayerComponent::cycleTarget(this, !m_bTargetCycleDirectionLeft, v14);
          }
          if ( v21 )
          {
            m_pPointer = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
            if ( m_pPointer )
            {
              UFG::TargetingSystemBaseComponent::FindMatrix(
                m_pPointer->m_pTransformNodeComponent,
                m_pPointer,
                &matSimObject);
              if ( UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(
                     this,
                     &this->m_vTargetingPosition,
                     m_pPointer,
                     &matSimObject,
                     0,
                     0) >= 0.0 )
              {
                v28 = this->m_pEquippedSOWPC.m_pPointer;
                if ( v28 )
                {
                  v29 = *(float *)(*((_QWORD *)&v28[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                   + HIDWORD(v28[2].m_pSimObject))
                                 + 400i64);
                  if ( v29 < 0.0 )
                    *(float *)&this->m_pAimingPlayerComponent.m_pSimComponent[1].m_NameUID = v29;
                }
                LOBYTE(closePickupsList) = 1;
                ((void (__fastcall *)(UFG::TargetingSystemPedPlayerComponent *, __int64, unsigned __int64))this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
                  this,
                  22i64,
                  closePickupsList);
                v12 = 1;
                if ( (unsigned int)(this->m_eFocusMode - 2) <= 2 )
                {
                  this->m_eDesiredFocusMode = eFOCUS_MODE_LOCKED_SOFT;
                  this->m_eFocusMode = eFOCUS_MODE_LOCKED_SOFT;
                  LOBYTE(this->m_pAimingPlayerComponent.m_pSimComponent[12].m_SafePointerList.mNode.mNext) = 1;
                  if ( this->m_bTargetAutoAcquisition )
                    HIDWORD(this->m_pAimingPlayerComponent.m_pSimComponent[12].m_pSimObject) = 22;
                }
              }
            }
          }
        }
      }
    }
    m_eFocusMode = this->m_eFocusMode;
    if ( m_eFocusMode == eFOCUS_MODE_FREE_AIMING_LOCKED )
    {
      v59 = closeVehiclesList;
      this->m_eDesiredFocusMode = eFOCUS_MODE_FREE_AIMING;
      this->m_eFocusMode = eFOCUS_MODE_FREE_AIMING;
      UFG::TargetingSystemPedPlayerComponent::updateFocusTargetStep2(this, closePedsList, v6, v8, v59, v14);
      this->m_eDesiredFocusMode = eFOCUS_MODE_FREE_AIMING_LOCKED;
      this->m_eFocusMode = eFOCUS_MODE_FREE_AIMING_LOCKED;
      goto LABEL_116;
    }
    if ( !v12 || m_eFocusMode == eFOCUS_MODE_FREE_AIMING )
    {
      v31 = closeVehiclesList;
      UFG::TargetingSystemPedPlayerComponent::updateFocusTargetStep2(
        this,
        closePedsList,
        v6,
        v8,
        closeVehiclesList,
        v14);
      if ( !this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer
        && (unsigned int)(this->m_eFocusMode - 1) <= 1
        && this->m_bHasRangedWeapon )
      {
        m_eDesiredFocusMode = this->m_eDesiredFocusMode;
        this->m_eFocusMode = eFOCUS_MODE_FREE_AIMING;
        this->m_eDesiredFocusMode = eFOCUS_MODE_FREE_AIMING;
        UFG::TargetingSystemPedPlayerComponent::updateTargetingIntentions(this);
        UFG::TargetingSystemPedPlayerComponent::updateFocusTargetStep2(this, closePedsList, v6, v8, v31, v14);
        m_pTargetingMap = this->m_pTargetingMap;
        this->m_eDesiredFocusMode = m_eDesiredFocusMode;
        Texture = this->m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
        if ( m_eDesiredFocusMode == eFOCUS_MODE_LOCKED )
        {
          if ( Texture )
          {
            m_Flags = Texture->m_Flags;
            if ( (m_Flags & 0x4000) != 0 )
            {
              vfptr = (unsigned int)Texture[1].vfptr;
              size = Texture->m_Components.size;
              if ( vfptr < size )
              {
                v38 = (__int64)&Texture->m_Components.p[vfptr];
                while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                     || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++vfptr;
                  v38 += 16i64;
                  if ( vfptr >= size )
                    goto LABEL_44;
                }
LABEL_45:
                m_pComponent = *(hkSimpleLocalFrame **)v38;
                goto LABEL_63;
              }
            }
            else
            {
              if ( m_Flags < 0 )
              {
                m_pComponent = (hkSimpleLocalFrame *)Texture->m_Components.p[30].m_pComponent;
                goto LABEL_63;
              }
              if ( (m_Flags & 0x2000) != 0 )
              {
                v40 = (unsigned int)Texture[1].vfptr;
                v41 = Texture->m_Components.size;
                if ( v40 < v41 )
                {
                  v38 = (__int64)&Texture->m_Components.p[v40];
                  while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                       || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF) != 0 )
                  {
                    ++v40;
                    v38 += 16i64;
                    if ( v40 >= v41 )
                    {
                      m_pComponent = 0i64;
                      goto LABEL_63;
                    }
                  }
                  goto LABEL_45;
                }
              }
              else
              {
                if ( (m_Flags & 0x1000) == 0 )
                {
                  m_pComponent = (hkSimpleLocalFrame *)UFG::SimObject::GetComponentOfType(
                                                         Texture,
                                                         UFG::VehicleOccupantComponent::_TypeUID);
                  goto LABEL_63;
                }
                v42 = (unsigned int)Texture[1].vfptr;
                v43 = Texture->m_Components.size;
                if ( v42 < v43 )
                {
                  v38 = (__int64)&Texture->m_Components.p[v42];
                  while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                       || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF) != 0 )
                  {
                    ++v42;
                    v38 += 16i64;
                    if ( v42 >= v43 )
                    {
                      m_pComponent = 0i64;
                      goto LABEL_63;
                    }
                  }
                  goto LABEL_45;
                }
              }
            }
LABEL_44:
            m_pComponent = 0i64;
LABEL_63:
            if ( m_pComponent && Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(m_pComponent) )
              Texture = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(m_pComponent);
            if ( !Texture )
              goto LABEL_90;
            v44 = Texture->m_Flags;
            if ( (v44 & 0x4000) != 0 )
            {
              v45 = Texture->m_Components.p[6].m_pComponent;
LABEL_87:
              if ( v45 && BYTE4(v45[1].m_BoundComponentHandles.mNode.mPrev) )
              {
                v51 = 1;
                goto LABEL_91;
              }
LABEL_90:
              v51 = 0;
LABEL_91:
              isHostileToMe = UFG::TargetingSystemPedBaseComponent::isHostileToMe(this, Texture);
              if ( !Texture )
                goto LABEL_110;
              v53 = Texture->m_Flags;
              if ( (v53 & 0x4000) != 0 )
              {
                ComponentOfType = Texture->m_Components.p[7].m_pComponent;
              }
              else if ( v53 >= 0 )
              {
                if ( (v53 & 0x2000) != 0 )
                {
                  ComponentOfType = Texture->m_Components.p[6].m_pComponent;
                }
                else if ( (v53 & 0x1000) != 0 )
                {
                  closePickupsList = LODWORD(Texture[1].vfptr);
                  closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)Texture->m_Components.size;
                  if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
                  {
LABEL_104:
                    ComponentOfType = 0i64;
                  }
                  else
                  {
                    v55 = (__int64)&Texture->m_Components.p[(unsigned int)closePickupsList];
                    while ( (*(_DWORD *)(v55 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                         || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v55 + 8) & 0x1FFFFFF) != 0 )
                    {
                      closePickupsList = (unsigned int)(closePickupsList + 1);
                      v55 += 16i64;
                      if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
                        goto LABEL_104;
                    }
                    ComponentOfType = *(UFG::SimComponent **)v55;
                  }
                }
                else
                {
                  ComponentOfType = UFG::SimObject::GetComponentOfType(Texture, UFG::ActionTreeComponent::_TypeUID);
                }
              }
              else
              {
                ComponentOfType = Texture->m_Components.p[7].m_pComponent;
              }
              if ( ComponentOfType
                && (v56 = UFG::GetActionMostUsedIndex_Hostage(),
                    v57 = UFG::GetActionID_Hostage(),
                    ActionController::IsPlaying((ActionController *)&ComponentOfType[3], v57, v56, 1)) )
              {
                v58 = 1;
              }
              else
              {
LABEL_110:
                v58 = 0;
              }
              if ( isHostileToMe && !v51 && !v58 )
              {
                this->m_eDesiredFocusMode = eFOCUS_MODE_LOCKED;
                this->m_eFocusMode = eFOCUS_MODE_LOCKED;
              }
              goto LABEL_116;
            }
            if ( v44 < 0 )
            {
              v45 = Texture->m_Components.p[6].m_pComponent;
              goto LABEL_87;
            }
            if ( (v44 & 0x2000) != 0 )
            {
              v46 = (unsigned int)Texture[1].vfptr;
              v47 = Texture->m_Components.size;
              if ( v46 < v47 )
              {
                v48 = (__int64)&Texture->m_Components.p[v46];
                while ( (*(_DWORD *)(v48 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                     || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v48 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v46;
                  v48 += 16i64;
                  if ( v46 >= v47 )
                    goto LABEL_77;
                }
LABEL_78:
                v45 = *(UFG::SimComponent **)v48;
                goto LABEL_87;
              }
            }
            else
            {
              if ( (v44 & 0x1000) == 0 )
              {
                v45 = UFG::SimObject::GetComponentOfType(Texture, UFG::HealthComponent::_TypeUID);
                goto LABEL_87;
              }
              v49 = (unsigned int)Texture[1].vfptr;
              v50 = Texture->m_Components.size;
              if ( v49 < v50 )
              {
                v48 = (__int64)&Texture->m_Components.p[v49];
                while ( (*(_DWORD *)(v48 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                     || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v48 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v49;
                  v48 += 16i64;
                  if ( v49 >= v50 )
                  {
                    v45 = 0i64;
                    goto LABEL_87;
                  }
                }
                goto LABEL_78;
              }
            }
LABEL_77:
            v45 = 0i64;
            goto LABEL_87;
          }
        }
      }
    }
  }
LABEL_116:
  v60 = this->m_pTargetingMap;
  this->m_bFocusTargetIsHostile = 0;
  v61 = this->m_pTargets[(unsigned __int8)v60->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( !v61 )
    goto LABEL_190;
  v62 = v61->m_Flags;
  v63 = this->m_pTargets[(unsigned __int8)v60->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( (v62 & 0x4000) != 0 )
  {
    closePickupsList = LODWORD(v61[1].vfptr);
    closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)v61->m_Components.size;
    if ( (unsigned int)closePickupsList < (unsigned int)closePropsList )
    {
      v64 = (__int64)&v61->m_Components.p[(unsigned int)closePickupsList];
      while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
           || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF) != 0 )
      {
        closePickupsList = (unsigned int)(closePickupsList + 1);
        v64 += 16i64;
        if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
          goto LABEL_123;
      }
LABEL_124:
      v65 = *(hkSimpleLocalFrame **)v64;
      goto LABEL_142;
    }
  }
  else
  {
    if ( v62 < 0 )
    {
      v65 = (hkSimpleLocalFrame *)v61->m_Components.p[30].m_pComponent;
      goto LABEL_142;
    }
    if ( (v62 & 0x2000) != 0 )
    {
      closePickupsList = LODWORD(v61[1].vfptr);
      closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)v61->m_Components.size;
      if ( (unsigned int)closePickupsList < (unsigned int)closePropsList )
      {
        v64 = (__int64)&v61->m_Components.p[(unsigned int)closePickupsList];
        while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF) != 0 )
        {
          closePickupsList = (unsigned int)(closePickupsList + 1);
          v64 += 16i64;
          if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
          {
            v65 = 0i64;
            goto LABEL_142;
          }
        }
        goto LABEL_124;
      }
    }
    else
    {
      if ( (v62 & 0x1000) == 0 )
      {
        v65 = (hkSimpleLocalFrame *)UFG::SimObject::GetComponentOfType(v61, UFG::VehicleOccupantComponent::_TypeUID);
        goto LABEL_142;
      }
      closePickupsList = LODWORD(v61[1].vfptr);
      closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)v61->m_Components.size;
      if ( (unsigned int)closePickupsList < (unsigned int)closePropsList )
      {
        v64 = (__int64)&v61->m_Components.p[(unsigned int)closePickupsList];
        while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF) != 0 )
        {
          closePickupsList = (unsigned int)(closePickupsList + 1);
          v64 += 16i64;
          if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
          {
            v65 = 0i64;
            goto LABEL_142;
          }
        }
        goto LABEL_124;
      }
    }
  }
LABEL_123:
  v65 = 0i64;
LABEL_142:
  if ( v65 && Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v65) )
    v63 = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v65);
  if ( !v63 )
    goto LABEL_169;
  v66 = v63->m_Flags;
  if ( (v66 & 0x4000) == 0 )
  {
    if ( v66 < 0 )
    {
      v67 = v63->m_Components.p[6].m_pComponent;
      goto LABEL_166;
    }
    if ( (v66 & 0x2000) != 0 )
    {
      closePickupsList = LODWORD(v63[1].vfptr);
      closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)v63->m_Components.size;
      if ( (unsigned int)closePickupsList < (unsigned int)closePropsList )
      {
        v68 = (__int64)&v63->m_Components.p[(unsigned int)closePickupsList];
        while ( (*(_DWORD *)(v68 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v68 + 8) & 0x1FFFFFF) != 0 )
        {
          closePickupsList = (unsigned int)(closePickupsList + 1);
          v68 += 16i64;
          if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
            goto LABEL_156;
        }
LABEL_157:
        v67 = *(UFG::SimComponent **)v68;
        goto LABEL_166;
      }
    }
    else
    {
      if ( (v66 & 0x1000) == 0 )
      {
        v67 = UFG::SimObject::GetComponentOfType(v63, UFG::HealthComponent::_TypeUID);
        goto LABEL_166;
      }
      closePickupsList = LODWORD(v63[1].vfptr);
      closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)v63->m_Components.size;
      if ( (unsigned int)closePickupsList < (unsigned int)closePropsList )
      {
        v68 = (__int64)&v63->m_Components.p[(unsigned int)closePickupsList];
        while ( (*(_DWORD *)(v68 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v68 + 8) & 0x1FFFFFF) != 0 )
        {
          closePickupsList = (unsigned int)(closePickupsList + 1);
          v68 += 16i64;
          if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
          {
            v67 = 0i64;
            goto LABEL_166;
          }
        }
        goto LABEL_157;
      }
    }
LABEL_156:
    v67 = 0i64;
    goto LABEL_166;
  }
  v67 = v63->m_Components.p[6].m_pComponent;
LABEL_166:
  if ( v67 && !BYTE4(v67[1].m_BoundComponentHandles.mNode.mPrev) )
    this->m_bFocusTargetIsHostile = UFG::TargetingSystemPedBaseComponent::isHostileToMe(this, v63);
LABEL_169:
  if ( this->m_eFocusMode == eFOCUS_MODE_LOCKED )
  {
    v69 = v61->m_Flags;
    if ( (v69 & 0x4000) != 0 )
    {
      v70 = v61->m_Components.p[3].m_pComponent;
    }
    else if ( v69 >= 0 )
    {
      if ( (v69 & 0x2000) != 0 )
      {
        v70 = v61->m_Components.p[4].m_pComponent;
      }
      else if ( (v69 & 0x1000) != 0 )
      {
        closePickupsList = LODWORD(v61[1].vfptr);
        closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)v61->m_Components.size;
        if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
        {
LABEL_182:
          v70 = 0i64;
        }
        else
        {
          v71 = (__int64)&v61->m_Components.p[(unsigned int)closePickupsList];
          while ( (*(_DWORD *)(v71 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || (UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v71 + 8) & 0x1FFFFFF) != 0 )
          {
            closePickupsList = (unsigned int)(closePickupsList + 1);
            v71 += 16i64;
            if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
              goto LABEL_182;
          }
          v70 = *(UFG::SimComponent **)v71;
        }
      }
      else
      {
        v70 = UFG::SimObject::GetComponentOfType(v61, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v70 = v61->m_Components.p[3].m_pComponent;
    }
    if ( v70 )
    {
      mNext = (int)v70[1].m_SafePointerList.mNode.mNext;
      if ( mNext == 1 || mNext == 4 && this->m_bHasRangedWeapon )
      {
        UFG::TargetingSystemPedPlayerComponent::EnableRimLighting(this, eTARGET_TYPE_FOCUS);
        goto LABEL_192;
      }
    }
  }
LABEL_190:
  if ( this->m_RimLighting.m_bEnabled )
    this->m_RimLighting.m_bEnabled = 0;
LABEL_192:
  if ( v61 )
  {
    v73 = this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr;
    if ( (unsigned int)(this->m_eFocusMode - 1) > 1 )
    {
      LOBYTE(closePropsList) = 1;
      ((void (__fastcall *)(UFG::TargetingSystemPedPlayerComponent *, __int64, _QWORD, UFG::qFixedArray<UFG::CloseTarget *,5> *, _DWORD, const char *, _QWORD, _QWORD))v73[14].__vecDelDtor)(
        this,
        22i64,
        0i64,
        closePropsList,
        0,
        "TargetingSystemPedPlayerComponent::updateFocusTarget",
        0i64,
        0i64);
    }
    else
    {
      LOBYTE(closePickupsList) = 1;
      ((void (__fastcall *)(UFG::TargetingSystemPedPlayerComponent *, __int64, unsigned __int64, _QWORD, _DWORD, _QWORD, _QWORD, _QWORD))v73[14].__vecDelDtor)(
        this,
        22i64,
        closePickupsList,
        0i64,
        0,
        0i64,
        0i64,
        0i64);
    }
    if ( this->m_bTargetAutoAcquisitionJustRequested )
    {
      this->m_eDesiredFocusMode = eFOCUS_MODE_LOCKED_SOFT;
      this->m_eFocusMode = eFOCUS_MODE_LOCKED_SOFT;
      LOBYTE(this->m_pAimingPlayerComponent.m_pSimComponent[12].m_SafePointerList.mNode.mNext) = 1;
      v74 = this->m_pFocusModeOverrideSimObject.m_pPointer == 0i64;
      bShouldRejectTarget = 0;
      if ( !v74
        || (UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(
              this,
              this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer,
              this->m_bIsInAnyCombat,
              &bShouldRejectTarget,
              &pPedTarget,
              &bIsTargetVehicle,
              &bTargetVehicleHasOccupant,
              &eFactionStanding,
              &bIsDowned,
              &bIsScripted,
              &bIsKnockedOut,
              &bIsSocialActionAvailable),
            !bShouldRejectTarget) )
      {
        HIDWORD(this->m_pAimingPlayerComponent.m_pSimComponent[12].m_pSimObject) = 22;
      }
    }
  }
  if ( this->m_pFocusModeOverrideSimObject.m_pPointer && (unsigned int)(this->m_eFocusMode - 1) <= 1 )
  {
    p_m_pFocusModeOverrideSimObject = &this->m_pFocusModeOverrideSimObject;
    if ( p_m_pFocusModeOverrideSimObject->m_pPointer )
    {
      v76 = p_m_pFocusModeOverrideSimObject->mPrev;
      v77 = p_m_pFocusModeOverrideSimObject->mNext;
      v76->mNext = v77;
      v77->mPrev = v76;
      p_m_pFocusModeOverrideSimObject->mPrev = p_m_pFocusModeOverrideSimObject;
      p_m_pFocusModeOverrideSimObject->mNext = p_m_pFocusModeOverrideSimObject;
    }
    p_m_pFocusModeOverrideSimObject->m_pPointer = 0i64;
  }
}is->m_pAimingPlayerComponent.m_pSimComponent[12].m_pSimObject) = 22;
      }
    }
  }
  if ( this->m_pFocusModeOverrideSimObject.m_pPointer && (unsigned int)(this->m_eFocusMode - 1) <= 1 )
  {
    p_m_pFocusModeOverrideSimObject = &this->m_pFocusModeOverrideSimObject;
    if ( p_m_pFocusModeOverrideSimObject->m_pPointer )
    {
      v76 = p_m_pFocusModeOverrideSimObject->mPrev;
      v77 = p_m_pFocusModeOverrideSimObject->mNext;
      v76->mNext = v77;
    

// File Line: 2762
// RVA: 0x571590
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateDirectionalTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList)
{
  UFG::TargetingSimObject *v3; // rcx
  UFG::qMatrix44 *p_m_Xform; // rbx
  __int64 size; // rsi
  UFG::SimObject *v6; // rbp
  float v7; // xmm0_4
  int mfnInPlaceNew; // ecx
  __int64 mfnInPlaceNew_low; // rax
  UFG::ScoredTarget *v10; // rax
  UFG::SimObject *m_pSimObject; // rdx
  unsigned __int8 v12; // cl
  unsigned __int8 v13; // cl
  unsigned __int64 v14; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  ClassTypeDescriptor right; // [rsp+28h] [rbp-670h] BYREF
  ClassTypeDescriptor left[101]; // [rsp+38h] [rbp-660h] BYREF

  v3 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[48]];
  if ( (!v3->m_pTarget.m_pPointer || !v3->m_bLock) && !this->m_pOccupantOfVehicle.m_pPointer )
  {
    LODWORD(right.mfnInPlaceNew) = 0;
    if ( closeTargetsList->size )
    {
      p_m_Xform = &closeTargetsList->p[0].m_Xform;
      size = closeTargetsList->size;
      while ( 1 )
      {
        v6 = *(UFG::SimObject **)(*(_QWORD *)&p_m_Xform[-1].v3.z + 40i64);
        v7 = UFG::TargetingSystemPedPlayerComponent::scoreDirectionalTarget(
               this,
               &this->m_vTargetingPosition,
               v6,
               p_m_Xform);
        if ( v7 < 0.0 )
          goto LABEL_9;
        mfnInPlaceNew = (int)right.mfnInPlaceNew;
        if ( LODWORD(right.mfnInPlaceNew) < 0x64 )
          break;
LABEL_10:
        p_m_Xform = (UFG::qMatrix44 *)((char *)p_m_Xform + 80);
        if ( !--size )
          goto LABEL_13;
      }
      mfnInPlaceNew_low = LODWORD(right.mfnInPlaceNew);
      ++LODWORD(right.mfnInPlaceNew);
      left[mfnInPlaceNew_low].mfnInPlaceNew = (void (__fastcall *)(void *))v6;
      *(float *)&left[mfnInPlaceNew_low].mUID = v7;
LABEL_9:
      mfnInPlaceNew = (int)right.mfnInPlaceNew;
      goto LABEL_10;
    }
    mfnInPlaceNew = (int)right.mfnInPlaceNew;
LABEL_13:
    UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
      left,
      &right + mfnInPlaceNew,
      (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
    v10 = UFG::TargetingSystemPedPlayerComponent::chooseBestVisibleTarget(
            this,
            (UFG::qFixedArray<UFG::ScoredTarget,100> *)&right.mfnInPlaceNew,
            UFG::TargetingSystemPedPlayerComponent::ms_MaxRaycastsBeforeGiveUpNormally);
    if ( v10 && (m_pSimObject = v10->m_pSimObject) != 0i64 )
    {
      v12 = this->m_pTargetingMap->m_Map.p[48];
      if ( v12 )
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v12], m_pSimObject);
    }
    else
    {
      v13 = this->m_pTargetingMap->m_Map.p[48];
      if ( v13 )
      {
        v14 = v13;
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v14], 0i64);
        m_pTargets = this->m_pTargets;
        if ( m_pTargets[v14].m_bLock )
          m_pTargets[v14].m_bLock = 0;
      }
    }
  }
}

// File Line: 2821
// RVA: 0x570A10
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateClosestDownedPedTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList)
{
  UFG::TargetingSimObject *v3; // rcx
  UFG::TargetingProfile *m_pActiveTargetingProfile; // rax
  float m_fIdlePriorityConeTime; // xmm1_4
  float v6; // xmm7_4
  float v7; // xmm0_4
  float v8; // xmm6_4
  unsigned int size; // r14d
  unsigned int v10; // esi
  UFG::CloseTarget **p; // rdi
  float *v12; // rcx
  float v13; // xmm1_4
  float v14; // xmm0_4
  __int64 v15; // rax
  float v16; // xmm1_4
  float v17; // xmm0_4
  UFG::SimObject *v18; // rbp
  float y; // xmm1_4
  float x; // xmm0_4
  UFG::ActionTreeComponent *m_pComponent; // rcx
  UFG::HealthComponent *v22; // rdx
  UFG::SimComponentHolder *v23; // rax
  unsigned __int8 v24; // cl
  unsigned __int64 v25; // rdi
  UFG::TargetingSimObject *m_pTargets; // rax
  unsigned __int8 v27; // cl
  UFG::qVector3 v2; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 v1; // [rsp+30h] [rbp-38h] BYREF

  v3 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[47]];
  if ( (!v3->m_pTarget.m_pPointer || !v3->m_bLock) && !this->m_pOccupantOfVehicle.m_pPointer )
  {
    if ( this->m_bHasPriorityTarget )
      goto LABEL_19;
    m_pActiveTargetingProfile = this->m_pActiveTargetingProfile;
    m_fIdlePriorityConeTime = m_pActiveTargetingProfile->m_fIdlePriorityConeTime;
    v6 = m_pActiveTargetingProfile->m_ConeDistancesSquared[0];
    if ( m_fIdlePriorityConeTime <= 0.0 )
    {
      v8 = m_pActiveTargetingProfile->m_HalfHorizontalFOVs[0];
    }
    else
    {
      v7 = this->m_fTargetingIntentionIdleTime / m_fIdlePriorityConeTime;
      if ( v7 > 1.0 )
        v7 = *(float *)&FLOAT_1_0;
      v8 = (float)((float)(1.0 - v7) * m_pActiveTargetingProfile->m_HalfHorizontalFOVs[0])
         + (float)(v7 * m_pActiveTargetingProfile->m_fHalfIdlePriorityConeHorizontalFOV);
    }
    size = closePedsList->size;
    v10 = 0;
    if ( !closePedsList->size )
      goto LABEL_19;
    p = closePedsList->p;
    while ( 1 )
    {
      v12 = (float *)*p;
      if ( v6 >= (*p)->m_fDistance2 )
      {
        v13 = v12[16];
        v14 = v12[17];
        v15 = *((_QWORD *)v12 + 1);
        v1.z = 0.0;
        v16 = v13 - this->m_vTargetingPosition.x;
        v17 = v14 - this->m_vTargetingPosition.y;
        v18 = *(UFG::SimObject **)(v15 + 40);
        v2.z = 0.0;
        v1.x = v16;
        y = this->m_vTargetingIntention.y;
        v1.y = v17;
        x = this->m_vTargetingIntention.x;
        v2.y = y;
        v2.x = x;
        if ( UFG::qAngleBetween(&v1, &v2) <= v8 )
        {
          if ( v18 )
          {
            v23 = v18->m_Components.p;
            m_pComponent = (UFG::ActionTreeComponent *)v23[7].m_pComponent;
            v22 = (UFG::HealthComponent *)v23[6].m_pComponent;
          }
          else
          {
            m_pComponent = 0i64;
            v22 = 0i64;
          }
          if ( UFG::IsDowned(m_pComponent, v22) )
            break;
        }
      }
      ++v10;
      ++p;
      if ( v10 >= size )
        goto LABEL_19;
    }
    if ( v18 )
    {
      v27 = this->m_pTargetingMap->m_Map.p[47];
      if ( v27 )
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v27], v18);
    }
    else
    {
LABEL_19:
      v24 = this->m_pTargetingMap->m_Map.p[47];
      if ( v24 )
      {
        v25 = v24;
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v25], 0i64);
        m_pTargets = this->m_pTargets;
        if ( m_pTargets[v25].m_bLock )
          m_pTargets[v25].m_bLock = 0;
      }
    }
  }
}

// File Line: 2893
// RVA: 0x570CF0
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateCrowdPushTargets(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList,
        UFG::qFixedArray<UFG::ClosePhysicalTarget,2> *closePhysicalDodgeableList)
{
  UFG::TargetingSimObject *v5; // rcx
  unsigned int v6; // eax
  unsigned int z_low; // ebx
  UFG::CloseTarget **p; // r14
  __int64 size; // r15
  float *v10; // rcx
  __int64 v11; // rdi
  float v12; // xmm9_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm6_4
  float y; // xmm1_4
  UFG::ActionTreeComponent *v17; // rcx
  UFG::HealthComponent *v18; // rdx
  __int64 v19; // rax
  __int64 v20; // rax
  UFG::RigidBody **p_m_pRigidBodyComponent; // rdi
  __int64 v22; // r14
  float v23; // xmm8_4
  float v24; // xmm7_4
  float z; // xmm9_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  __int64 v28; // rdx
  float v29; // xmm2_4
  UFG::SimObject *v30; // rdx
  UFG::SimObject *v31; // rdi
  unsigned int v32; // r8d
  __int64 v33; // rax
  __int128 v34; // xmm1
  char *v35; // rcx
  unsigned int v36; // eax
  __int64 v37; // rdx
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  UFG::qVector4 *v41; // rcx
  __int64 v42; // r8
  unsigned __int8 v43; // cl
  unsigned __int64 v44; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  unsigned __int8 v46; // cl
  unsigned __int64 v47; // rbx
  UFG::TargetingSimObject *v48; // rax
  __int128 v49; // [rsp+20h] [rbp-C8h] BYREF
  UFG::SimObject *pNewTarget[2]; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v51; // [rsp+40h] [rbp-A8h]
  UFG::qMatrix44 mat; // [rsp+50h] [rbp-98h] BYREF
  char v53; // [rsp+90h] [rbp-58h] BYREF

  v51 = -2i64;
  v5 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[51]];
  if ( (!v5->m_pTarget.m_pPointer || !v5->m_bLock) && !this->m_pOccupantOfVehicle.m_pPointer )
  {
    v6 = _S44;
    if ( (_S44 & 1) == 0 )
    {
      v6 = _S44 | 1;
      _S44 |= 1u;
      s_fHalfAngleRange = FLOAT_1_3962635;
    }
    if ( (v6 & 2) == 0 )
    {
      _S44 = v6 | 2;
      s_fMaxDistanceSquared = FLOAT_25_0;
    }
    z_low = 0;
    mat.v2.z = 0.0;
    if ( closePedsList->size )
    {
      p = closePedsList->p;
      size = closePedsList->size;
      do
      {
        v10 = (float *)*p;
        if ( s_fMaxDistanceSquared >= (*p)->m_fDistance2 )
        {
          v11 = *(_QWORD *)(*((_QWORD *)v10 + 1) + 40i64);
          if ( !v11 || !*(_QWORD *)(*(_QWORD *)(v11 + 104) + 704i64) )
          {
            v12 = v10[18] - this->m_vTargetingPosition.z;
            v13 = v10[17] - this->m_vTargetingPosition.y;
            v14 = v10[16] - this->m_vTargetingPosition.x;
            v15 = s_fHalfAngleRange;
            *(float *)&v49 = v14;
            *(_QWORD *)((char *)&v49 + 4) = LODWORD(v13);
            y = this->m_vTargetingForward.y;
            *(float *)pNewTarget = this->m_vTargetingForward.x;
            *((float *)pNewTarget + 1) = y;
            LODWORD(pNewTarget[1]) = 0;
            if ( v15 >= UFG::qAngleBetween((UFG::qVector3 *)&v49, (UFG::qVector3 *)pNewTarget) )
            {
              if ( v11 )
              {
                v19 = *(_QWORD *)(v11 + 104);
                v17 = *(UFG::ActionTreeComponent **)(v19 + 112);
                v18 = *(UFG::HealthComponent **)(v19 + 96);
              }
              else
              {
                v17 = 0i64;
                v18 = 0i64;
              }
              if ( !UFG::IsDowned(v17, v18) && z_low < 0x64 )
              {
                v20 = 2i64 * z_low;
                LODWORD(mat.v2.z) = z_low + 1;
                *((_QWORD *)&mat.v3.z + v20) = v11;
                *(&mat.v3.x + 2 * v20) = (float)((float)(v13 * v13) + (float)(v14 * v14)) + (float)(v12 * v12);
                z_low = LODWORD(mat.v2.z);
              }
            }
          }
        }
        ++p;
        --size;
      }
      while ( size );
    }
    if ( closePhysicalDodgeableList->size )
    {
      p_m_pRigidBodyComponent = &closePhysicalDodgeableList->p[0].m_pRigidBodyComponent;
      v22 = closePhysicalDodgeableList->size;
      do
      {
        if ( s_fMaxDistanceSquared >= *((float *)p_m_pRigidBodyComponent - 2) )
        {
          UFG::RigidBody::GetTransform(*p_m_pRigidBodyComponent, &mat);
          v23 = mat.v1.w - this->m_vTargetingPosition.y;
          v24 = mat.v1.z - this->m_vTargetingPosition.x;
          z = this->m_vTargetingPosition.z;
          v26 = s_fHalfAngleRange;
          *(float *)pNewTarget = v24;
          *((float *)pNewTarget + 1) = v23;
          LODWORD(pNewTarget[1]) = 0;
          v27 = this->m_vTargetingForward.y;
          *(float *)&v49 = this->m_vTargetingForward.x;
          *(_QWORD *)((char *)&v49 + 4) = LODWORD(v27);
          if ( v26 >= UFG::qAngleBetween((UFG::qVector3 *)pNewTarget, (UFG::qVector3 *)&v49) && z_low < 0x64 )
          {
            v28 = 2i64 * z_low;
            LODWORD(mat.v2.z) = z_low + 1;
            *((_QWORD *)&mat.v3.z + v28) = (*p_m_pRigidBodyComponent)->m_pSimObject;
            *(&mat.v3.x + 2 * v28) = (float)((float)(v24 * v24) + (float)(v23 * v23)) + (float)(z * z);
            z_low = LODWORD(mat.v2.z);
          }
        }
        p_m_pRigidBodyComponent += 2;
        --v22;
      }
      while ( v22 );
    }
    v29 = FLOAT_3_4028235e38;
    *(float *)pNewTarget = FLOAT_3_4028235e38;
    v30 = 0i64;
    pNewTarget[1] = 0i64;
    LODWORD(v49) = 2139095039;
    v31 = 0i64;
    *((_QWORD *)&v49 + 1) = 0i64;
    v32 = 0;
    v33 = 0i64;
    v34 = (unsigned __int64)pNewTarget[0];
    if ( (int)z_low >= 4 )
    {
      v35 = &v53;
      v36 = ((z_low - 4) >> 2) + 1;
      v37 = v36;
      v32 = 4 * v36;
      v33 = 4i64 * v36;
      do
      {
        v38 = *((float *)v35 - 4);
        if ( v38 >= v29 )
        {
          if ( v38 < *(float *)&v49 )
            v49 = *((_OWORD *)v35 - 1);
        }
        else
        {
          v49 = v34;
          v34 = *((_OWORD *)v35 - 1);
          *(_OWORD *)pNewTarget = v34;
          v29 = *(float *)&v34;
        }
        if ( *(float *)v35 >= v29 )
        {
          if ( *(float *)v35 < *(float *)&v49 )
            v49 = *(_OWORD *)v35;
        }
        else
        {
          v49 = v34;
          v34 = *(_OWORD *)v35;
          *(_OWORD *)pNewTarget = *(_OWORD *)v35;
          v29 = *(float *)pNewTarget;
        }
        v39 = *((float *)v35 + 4);
        if ( v39 >= v29 )
        {
          if ( v39 < *(float *)&v49 )
            v49 = *((_OWORD *)v35 + 1);
        }
        else
        {
          v49 = v34;
          v34 = *((_OWORD *)v35 + 1);
          *(_OWORD *)pNewTarget = v34;
          v29 = *(float *)&v34;
        }
        v40 = *((float *)v35 + 8);
        if ( v40 >= v29 )
        {
          if ( v40 < *(float *)&v49 )
            v49 = *((_OWORD *)v35 + 2);
        }
        else
        {
          v49 = v34;
          v34 = *((_OWORD *)v35 + 2);
          *(_OWORD *)pNewTarget = v34;
          v29 = *(float *)&v34;
        }
        v35 += 64;
        --v37;
      }
      while ( v37 );
      v30 = pNewTarget[1];
      v31 = (UFG::SimObject *)*((_QWORD *)&v49 + 1);
    }
    if ( v32 < z_low )
    {
      v41 = &mat.v3 + v33;
      v42 = z_low - v32;
      do
      {
        if ( v41->x >= v29 )
        {
          if ( v41->x < *(float *)&v49 )
          {
            *(_QWORD *)&v49 = *(_QWORD *)&v41->x;
            v31 = *(UFG::SimObject **)&v41->z;
          }
        }
        else
        {
          v49 = v34;
          pNewTarget[0] = *(UFG::SimObject **)&v41->x;
          v30 = *(UFG::SimObject **)&v41->z;
          pNewTarget[1] = v30;
          v29 = *(float *)pNewTarget;
          v34 = *(_OWORD *)pNewTarget;
          v31 = (UFG::SimObject *)*((_QWORD *)&v49 + 1);
        }
        ++v41;
        --v42;
      }
      while ( v42 );
    }
    v43 = this->m_pTargetingMap->m_Map.p[51];
    if ( v30 )
    {
      if ( v43 )
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v43], v30);
    }
    else if ( v43 )
    {
      v44 = v43;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v44], 0i64);
      m_pTargets = this->m_pTargets;
      if ( m_pTargets[v44].m_bLock )
        m_pTargets[v44].m_bLock = 0;
    }
    v46 = this->m_pTargetingMap->m_Map.p[52];
    if ( v31 )
    {
      if ( v46 )
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v46], v31);
    }
    else if ( v46 )
    {
      v47 = v46;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v47], 0i64);
      v48 = this->m_pTargets;
      if ( v48[v47].m_bLock )
        v48[v47].m_bLock = 0;
    }
  }
}

// File Line: 3043
// RVA: 0x57A470
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateTransitTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList)
{
  UFG::qFixedArray<UFG::CloseTarget *,20> *v2; // r14
  UFG::CopSystem *v4; // rax
  UFG::TargetingSimObject *v5; // rcx
  UFG::GameStatTracker *v6; // rax
  UFG::SimComponent *v7; // rsi
  UFG::SimObject *v8; // r13
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rdi
  UFG::qMatrix44 *ViewProjection; // rbx
  UFG::qMatrix44 *WorldView; // rax
  float v13; // xmm12_4
  float v14; // xmm11_4
  float v15; // xmm10_4
  float v16; // xmm13_4
  float v17; // xmm14_4
  float v18; // xmm15_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm6_4
  float v23; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  __m128 v27; // xmm2
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm4_4
  __m128 v31; // xmm2
  float v32; // xmm0_4
  float v33; // xmm6_4
  float v34; // xmm0_4
  float v35; // xmm3_4
  unsigned int v36; // edx
  int v37; // r12d
  __m128 v38; // xmm2
  float v39; // xmm8_4
  unsigned int v40; // r8d
  UFG::CloseTarget *v41; // r14
  UFG::SimObject *m_pSimObject; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rdi
  unsigned int v45; // r10d
  unsigned int v46; // edi
  __int64 v47; // r9
  unsigned int v48; // r10d
  unsigned int v49; // edi
  UFG::SimComponent *v50; // rax
  __int16 v51; // r9
  UFG::PhysicsMoverInterface *ComponentOfType; // rax
  unsigned int vfptr; // r10d
  unsigned int size; // r14d
  __int64 v55; // r9
  __int16 v56; // cx
  unsigned int v57; // r9d
  unsigned int v58; // r11d
  __int64 v59; // r8
  UFG::VehicleOccupantComponent *v60; // rdi
  unsigned int v61; // r9d
  unsigned int v62; // r11d
  unsigned int v63; // r9d
  unsigned int v64; // r11d
  unsigned __int8 v65; // cl
  hkLocalFrameGroup *Texture; // rbx
  __int16 v67; // cx
  unsigned int v68; // r9d
  unsigned int v69; // r11d
  __int64 v70; // r8
  hkSimpleLocalFrame *v71; // rax
  unsigned int v72; // r9d
  unsigned int v73; // r11d
  unsigned int v74; // r9d
  unsigned int v75; // r11d
  UFG::FaceActionComponent *m_pDriverFaceActionComponent; // rax
  __int16 v77; // cx
  unsigned int v78; // r8d
  unsigned int v79; // r10d
  __int64 v80; // rdx
  unsigned int v81; // r8d
  unsigned int v82; // r10d
  unsigned int v83; // r8d
  unsigned int v84; // r10d
  unsigned __int8 v85; // cl
  unsigned __int64 v86; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  float v88; // [rsp+2Ch] [rbp-D4h]
  float v89; // [rsp+34h] [rbp-CCh]
  float v90; // [rsp+38h] [rbp-C8h]
  float v91; // [rsp+44h] [rbp-BCh]
  UFG::qMatrix44 result; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qVector4 planes; // [rsp+90h] [rbp-70h] BYREF
  float v94; // [rsp+A0h] [rbp-60h]
  float v95; // [rsp+A4h] [rbp-5Ch]
  float v96; // [rsp+A8h] [rbp-58h]
  float v97; // [rsp+ACh] [rbp-54h]
  float v98; // [rsp+B0h] [rbp-50h]
  float v99; // [rsp+B4h] [rbp-4Ch]
  float v100; // [rsp+B8h] [rbp-48h]
  float v101; // [rsp+BCh] [rbp-44h]
  float v102; // [rsp+C0h] [rbp-40h]
  float v103; // [rsp+C4h] [rbp-3Ch]
  float v104; // [rsp+C8h] [rbp-38h]
  float v105; // [rsp+CCh] [rbp-34h]
  float v106; // [rsp+D0h] [rbp-30h]
  float v107; // [rsp+D4h] [rbp-2Ch]
  float v108; // [rsp+D8h] [rbp-28h]
  int v109; // [rsp+DCh] [rbp-24h]
  float v110; // [rsp+E0h] [rbp-20h]
  float v111; // [rsp+E4h] [rbp-1Ch]
  float v112; // [rsp+E8h] [rbp-18h]
  float v113; // [rsp+ECh] [rbp-14h]
  float v114; // [rsp+1E0h] [rbp+E0h]
  UFG::CloseTarget *v115; // [rsp+1E0h] [rbp+E0h]

  v2 = closeVehiclesList;
  if ( *(_WORD *)&this->m_TransitTargetingDisabledByMiniGame
    || (v4 = UFG::CopSystem::Instance(), ((int (__fastcall *)(UFG::CopSystem *))v4->vfptr[89].__vecDelDtor)(v4) > 0) )
  {
    if ( (this->m_pDriverFaceActionComponent->m_Flags & 1) != 0 )
      UFG::TargetingSystemPedPlayerComponent::deattachTransitDriverFaceComponent(this);
    v85 = this->m_pTargetingMap->m_Map.p[57];
    if ( v85 )
    {
      v86 = v85;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v86], 0i64);
      m_pTargets = this->m_pTargets;
      if ( m_pTargets[v86].m_bLock )
        m_pTargets[v86].m_bLock = 0;
    }
    return;
  }
  v5 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[57]];
  if ( v5->m_pTarget.m_pPointer && v5->m_bLock )
    return;
  UFG::TargetingSystemBaseComponent::ClearTarget(this, eTARGET_TYPE_TRANSIT);
  v6 = UFG::GameStatTracker::Instance();
  if ( (int)UFG::GameStatTracker::GetStat(v6, Money) < 310 )
  {
    if ( (this->m_pDriverFaceActionComponent->m_Flags & 1) != 0 )
      UFG::TargetingSystemPedPlayerComponent::deattachTransitDriverFaceComponent(this);
    return;
  }
  v7 = 0i64;
  v8 = 0i64;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  p_mCamera = &mCurrentCamera->mCamera;
  if ( !mCurrentCamera )
    p_mCamera = 0i64;
  ViewProjection = UFG::Camera::GetViewProjection(p_mCamera);
  WorldView = UFG::Camera::GetWorldView(p_mCamera);
  UFG::qMatrix44::operator*(WorldView, &result, ViewProjection);
  LODWORD(v13) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
  LODWORD(v91) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
  LODWORD(v14) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
  LODWORD(v15) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
  LODWORD(v114) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v16) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
  LODWORD(v17) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
  LODWORD(v18) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
  LODWORD(v90) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
  LODWORD(v88) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
  LODWORD(v89) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
  v19 = fsqrt(
          (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
        + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
  planes.w = (float)(1.0 / v19) * COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]);
  planes.x = (float)(1.0 / v19) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
  planes.z = (float)(1.0 / v19) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
  planes.y = (float)(1.0 / v19) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]);
  v20 = fsqrt((float)((float)(v14 * v14) + (float)(v13 * v13)) + (float)(v15 * v15));
  v21 = (float)(1.0 / v20) * v13;
  LODWORD(v22) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  LODWORD(v23) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  v24 = (float)(1.0 / v20) * v14;
  v25 = 1.0 / v20;
  v94 = v21;
  v95 = v24;
  v97 = v25 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0]);
  v96 = v25 * v15;
  v26 = fsqrt((float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(v18 * v18));
  v101 = (float)(1.0 / v26) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0]);
  v98 = (float)(1.0 / v26) * v16;
  v100 = (float)(1.0 / v26) * v18;
  v99 = (float)(1.0 / v26) * v17;
  v27 = (__m128)LODWORD(v114);
  v27.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v22 * v22)) + (float)(v23 * v23);
  v28 = 1.0 / _mm_sqrt_ps(v27).m128_f32[0];
  v29 = v28 * v23;
  LODWORD(v30) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
  v102 = v28 * v22;
  v104 = v29;
  v103 = v28 * v114;
  v31 = (__m128)LODWORD(v91);
  v105 = v28 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0]);
  v31.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30)) + (float)(v90 * v90);
  v32 = _mm_sqrt_ps(v31).m128_f32[0];
  v33 = v90 * (float)(1.0 / v32);
  v31.m128_f32[0] = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0]) * (float)(1.0 / v32);
  v34 = 1.0 / v32;
  v108 = v33;
  v109 = v31.m128_i32[0];
  v106 = v34 * v30;
  v107 = v34 * v91;
  LODWORD(v35) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
  v36 = UFG::VehicleOccupantComponent::_TypeUID;
  v37 = 0;
  v38 = (__m128)LODWORD(v89);
  v38.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v88 * v88)) + (float)(v35 * v35);
  v39 = 1.0 / _mm_sqrt_ps(v38).m128_f32[0];
  v110 = v39 * v88;
  v112 = v39 * v35;
  v113 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]) * v39;
  v111 = v39 * v89;
  if ( v2->size )
  {
    v40 = UFG::AiDriverComponent::_TypeUID;
    while ( 1 )
    {
      v41 = v2->p[v37];
      v115 = v41;
      m_pSimObject = v41->m_pSimObjectPropertiesComponent->m_pSimObject;
      if ( m_pSimObject )
        break;
LABEL_89:
      v2 = closeVehiclesList;
      if ( ++v37 >= closeVehiclesList->size )
        goto LABEL_92;
    }
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[23].m_pComponent;
      if ( !m_pComponent
        || ((v40 ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0
        || (v40 & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        goto LABEL_17;
      }
LABEL_39:
      v51 = m_pSimObject->m_Flags;
      if ( (v51 & 0x4000) != 0 )
      {
        ComponentOfType = 0i64;
      }
      else if ( v51 >= 0 )
      {
        if ( (v51 & 0x2000) != 0 )
        {
          ComponentOfType = 0i64;
        }
        else if ( (v51 & 0x1000) != 0 )
        {
          vfptr = (unsigned int)m_pSimObject[1].vfptr;
          size = m_pSimObject->m_Components.size;
          if ( vfptr >= size )
          {
LABEL_51:
            v41 = v115;
            ComponentOfType = 0i64;
          }
          else
          {
            v55 = (__int64)&m_pSimObject->m_Components.p[vfptr];
            while ( (*(_DWORD *)(v55 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
                 || (UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v55 + 8) & 0x1FFFFFF) != 0 )
            {
              ++vfptr;
              v55 += 16i64;
              if ( vfptr >= size )
                goto LABEL_51;
            }
            ComponentOfType = *(UFG::PhysicsMoverInterface **)v55;
            v41 = v115;
          }
        }
        else
        {
          ComponentOfType = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                            m_pSimObject,
                                                            UFG::PhysicsMoverInterface::_TypeUID);
          v40 = UFG::AiDriverComponent::_TypeUID;
          v36 = UFG::VehicleOccupantComponent::_TypeUID;
        }
      }
      else
      {
        ComponentOfType = (UFG::PhysicsMoverInterface *)m_pSimObject->m_Components.p[34].m_pComponent;
      }
      if ( !m_pComponent || !ComponentOfType )
        goto LABEL_89;
      if ( UFG::PhysicsMoverInterface::GetEngineDamage(ComponentOfType) >= 0.5 )
        goto LABEL_87;
      v56 = m_pSimObject->m_Flags;
      if ( (v56 & 0x4000) != 0 )
      {
        v57 = (unsigned int)m_pSimObject[1].vfptr;
        v58 = m_pSimObject->m_Components.size;
        v36 = UFG::VehicleOccupantComponent::_TypeUID;
        if ( v57 < v58 )
        {
          v59 = (__int64)&m_pSimObject->m_Components.p[v57];
          while ( (*(_DWORD *)(v59 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
               || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v59 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v57;
            v59 += 16i64;
            if ( v57 >= v58 )
              goto LABEL_63;
          }
LABEL_64:
          v60 = *(UFG::VehicleOccupantComponent **)v59;
          goto LABEL_83;
        }
        goto LABEL_63;
      }
      if ( v56 >= 0 )
      {
        v36 = UFG::VehicleOccupantComponent::_TypeUID;
        if ( (v56 & 0x2000) != 0 )
        {
          v61 = (unsigned int)m_pSimObject[1].vfptr;
          v62 = m_pSimObject->m_Components.size;
          if ( v61 < v62 )
          {
            v59 = (__int64)&m_pSimObject->m_Components.p[v61];
            while ( (*(_DWORD *)(v59 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                 || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v59 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v61;
              v59 += 16i64;
              if ( v61 >= v62 )
              {
                v60 = 0i64;
                goto LABEL_83;
              }
            }
            goto LABEL_64;
          }
LABEL_63:
          v60 = 0i64;
LABEL_83:
          if ( !v60 )
          {
LABEL_88:
            v40 = UFG::AiDriverComponent::_TypeUID;
            goto LABEL_89;
          }
          if ( UFG::SimObjectUtility::IsClassType(m_pSimObject, &qSymbol_Taxi) == 1
            && !UFG::VehicleOccupantComponent::HasPassengers(v60)
            && (int)InFrustum(&planes, (UFG::qVector3 *)&v41->m_Xform.v3) > 0 )
          {
            v36 = UFG::VehicleOccupantComponent::_TypeUID;
            v8 = m_pSimObject;
            goto LABEL_92;
          }
LABEL_87:
          v36 = UFG::VehicleOccupantComponent::_TypeUID;
          goto LABEL_88;
        }
        if ( (v56 & 0x1000) != 0 )
        {
          v63 = (unsigned int)m_pSimObject[1].vfptr;
          v64 = m_pSimObject->m_Components.size;
          if ( v63 < v64 )
          {
            v59 = (__int64)&m_pSimObject->m_Components.p[v63];
            while ( (*(_DWORD *)(v59 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                 || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v59 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v63;
              v59 += 16i64;
              if ( v63 >= v64 )
              {
                v60 = 0i64;
                goto LABEL_83;
              }
            }
            goto LABEL_64;
          }
          goto LABEL_63;
        }
        v60 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                 m_pSimObject,
                                                 UFG::VehicleOccupantComponent::_TypeUID);
      }
      else
      {
        v60 = (UFG::VehicleOccupantComponent *)m_pSimObject->m_Components.p[30].m_pComponent;
      }
      v36 = UFG::VehicleOccupantComponent::_TypeUID;
      goto LABEL_83;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[23].m_pComponent;
      if ( !m_pComponent || ((v40 ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0 )
        goto LABEL_17;
      if ( (v40 & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
        m_pComponent = 0i64;
      goto LABEL_39;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      v45 = (unsigned int)m_pSimObject[1].vfptr;
      v46 = m_pSimObject->m_Components.size;
      if ( v45 < v46 )
      {
        v47 = (__int64)&m_pSimObject->m_Components.p[v45];
        while ( (*(_DWORD *)(v47 + 8) & 0xFE000000) != (v40 & 0xFE000000)
             || (v40 & ~*(_DWORD *)(v47 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v45;
          v47 += 16i64;
          if ( v45 >= v46 )
          {
            m_pComponent = 0i64;
            goto LABEL_39;
          }
        }
LABEL_30:
        m_pComponent = *(UFG::SimComponent **)v47;
        goto LABEL_39;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        v50 = UFG::SimObject::GetComponentOfType(m_pSimObject, v40);
        v40 = UFG::AiDriverComponent::_TypeUID;
        v36 = UFG::VehicleOccupantComponent::_TypeUID;
        m_pComponent = v50;
        goto LABEL_39;
      }
      v48 = (unsigned int)m_pSimObject[1].vfptr;
      v49 = m_pSimObject->m_Components.size;
      if ( v48 < v49 )
      {
        v47 = (__int64)&m_pSimObject->m_Components.p[v48];
        while ( (*(_DWORD *)(v47 + 8) & 0xFE000000) != (v40 & 0xFE000000)
             || (v40 & ~*(_DWORD *)(v47 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v48;
          v47 += 16i64;
          if ( v48 >= v49 )
          {
            m_pComponent = 0i64;
            goto LABEL_39;
          }
        }
        goto LABEL_30;
      }
    }
LABEL_17:
    m_pComponent = 0i64;
    goto LABEL_39;
  }
LABEL_92:
  v65 = this->m_pTargetingMap->m_Map.p[57];
  if ( v65 )
  {
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v65], v8);
    v36 = UFG::VehicleOccupantComponent::_TypeUID;
  }
  Texture = 0i64;
  if ( v8 )
  {
    v67 = v8->m_Flags;
    if ( (v67 & 0x4000) != 0 )
    {
      v68 = (unsigned int)v8[1].vfptr;
      v69 = v8->m_Components.size;
      if ( v68 < v69 )
      {
        v70 = (__int64)&v8->m_Components.p[v68];
        while ( (*(_DWORD *)(v70 + 8) & 0xFE000000) != (v36 & 0xFE000000)
             || (v36 & ~*(_DWORD *)(v70 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v68;
          v70 += 16i64;
          if ( v68 >= v69 )
            goto LABEL_101;
        }
LABEL_102:
        v71 = *(hkSimpleLocalFrame **)v70;
        goto LABEL_120;
      }
      goto LABEL_101;
    }
    if ( v67 >= 0 )
    {
      if ( (v67 & 0x2000) != 0 )
      {
        v72 = (unsigned int)v8[1].vfptr;
        v73 = v8->m_Components.size;
        if ( v72 < v73 )
        {
          v70 = (__int64)&v8->m_Components.p[v72];
          while ( (*(_DWORD *)(v70 + 8) & 0xFE000000) != (v36 & 0xFE000000)
               || (v36 & ~*(_DWORD *)(v70 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v72;
            v70 += 16i64;
            if ( v72 >= v73 )
            {
              v71 = 0i64;
              goto LABEL_120;
            }
          }
          goto LABEL_102;
        }
LABEL_101:
        v71 = 0i64;
        goto LABEL_120;
      }
      if ( (v67 & 0x1000) != 0 )
      {
        v74 = (unsigned int)v8[1].vfptr;
        v75 = v8->m_Components.size;
        if ( v74 < v75 )
        {
          v70 = (__int64)&v8->m_Components.p[v74];
          while ( (*(_DWORD *)(v70 + 8) & 0xFE000000) != (v36 & 0xFE000000)
               || (v36 & ~*(_DWORD *)(v70 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v74;
            v70 += 16i64;
            if ( v74 >= v75 )
            {
              v71 = 0i64;
              goto LABEL_120;
            }
          }
          goto LABEL_102;
        }
        goto LABEL_101;
      }
      v71 = (hkSimpleLocalFrame *)UFG::SimObject::GetComponentOfType(v8, v36);
    }
    else
    {
      v71 = (hkSimpleLocalFrame *)v8->m_Components.p[30].m_pComponent;
    }
LABEL_120:
    if ( v71 )
      Texture = Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v71);
  }
  m_pDriverFaceActionComponent = this->m_pDriverFaceActionComponent;
  if ( (hkLocalFrameGroup *)m_pDriverFaceActionComponent->m_pSimObject != Texture )
  {
    if ( (m_pDriverFaceActionComponent->m_Flags & 1) != 0 )
      UFG::TargetingSystemPedPlayerComponent::deattachTransitDriverFaceComponent(this);
    if ( Texture )
    {
      v77 = WORD2(Texture[3].vfptr);
      if ( (v77 & 0x4000) != 0 )
      {
        v7 = *(UFG::SimComponent **)(*(_QWORD *)&Texture[4].m_memSizeAndFlags + 720i64);
        goto LABEL_151;
      }
      if ( v77 >= 0 )
      {
        if ( (v77 & 0x2000) != 0 )
        {
          v81 = *(_DWORD *)&Texture[5].m_memSizeAndFlags;
          v82 = (unsigned int)Texture[4].vfptr;
          if ( v81 >= v82 )
            goto LABEL_151;
          v80 = *(_QWORD *)&Texture[4].m_memSizeAndFlags + 16i64 * v81;
          while ( (*(_DWORD *)(v80 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
               || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v80 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v81;
            v80 += 16i64;
            if ( v81 >= v82 )
              goto LABEL_151;
          }
        }
        else
        {
          if ( (v77 & 0x1000) == 0 )
          {
            v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)Texture, UFG::FaceActionComponent::_TypeUID);
            goto LABEL_151;
          }
          v83 = *(_DWORD *)&Texture[5].m_memSizeAndFlags;
          v84 = (unsigned int)Texture[4].vfptr;
          if ( v83 >= v84 )
          {
LABEL_151:
            if ( !v7 && (this->m_pDriverFaceActionComponent->m_Flags & 1) == 0 )
              UFG::TargetingSystemPedPlayerComponent::attachTransitDriverFaceComponent(this, (UFG::SimObject *)Texture);
            return;
          }
          v80 = *(_QWORD *)&Texture[4].m_memSizeAndFlags + 16i64 * v83;
          while ( (*(_DWORD *)(v80 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
               || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v80 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v83;
            v80 += 16i64;
            if ( v83 >= v84 )
              goto LABEL_151;
          }
        }
      }
      else
      {
        v78 = *(_DWORD *)&Texture[5].m_memSizeAndFlags;
        v79 = (unsigned int)Texture[4].vfptr;
        if ( v78 >= v79 )
          goto LABEL_151;
        v80 = *(_QWORD *)&Texture[4].m_memSizeAndFlags + 16i64 * v78;
        while ( (*(_DWORD *)(v80 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
             || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v80 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v78;
          v80 += 16i64;
          if ( v78 >= v79 )
            goto LABEL_151;
        }
      }
      v7 = *(UFG::SimComponent **)v80;
      goto LABEL_151;
    }
  }
}

// File Line: 3152
// RVA: 0x566F00
void __fastcall UFG::TargetingSystemPedPlayerComponent::deattachTransitDriverFaceComponent(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimObject *m_pSimObject; // rdi
  __int16 m_Flags; // dx
  int v4; // esi
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // ecx
  unsigned int size; // r8d
  UFG::SimComponentHolder *p; // r11
  __int64 v9; // rbx
  unsigned int v10; // ecx
  unsigned int v11; // r8d
  unsigned int v12; // ecx
  unsigned int v13; // r8d
  __int64 m_eDriverSellableItemType; // rax
  ArrayOfTuplesImplementation v15; // [rsp+28h] [rbp-30h] BYREF

  m_pSimObject = this->m_pDriverFaceActionComponent->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_35;
  m_Flags = m_pSimObject->m_Flags;
  v4 = 0;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[39].m_pComponent;
    goto LABEL_28;
  }
  if ( m_Flags < 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v9 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
          && (UFG::InventoryComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_12;
      }
LABEL_11:
      m_pComponent = p[v9].m_pComponent;
      goto LABEL_28;
    }
    goto LABEL_12;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v10 = (unsigned int)m_pSimObject[1].vfptr;
    v11 = m_pSimObject->m_Components.size;
    if ( v10 < v11 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v9 = v10;
        if ( (p[v10].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
          && (UFG::InventoryComponent::_TypeUID & ~p[v10].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_11;
        }
        if ( ++v10 >= v11 )
          goto LABEL_12;
      }
    }
    goto LABEL_12;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v12 = (unsigned int)m_pSimObject[1].vfptr;
    v13 = m_pSimObject->m_Components.size;
    if ( v12 < v13 )
    {
      p = m_pSimObject->m_Components.p;
      do
      {
        v9 = v12;
        if ( (p[v12].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
          && (UFG::InventoryComponent::_TypeUID & ~p[v12].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_11;
        }
      }
      while ( ++v12 < v13 );
    }
LABEL_12:
    m_pComponent = 0i64;
    goto LABEL_28;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::InventoryComponent::_TypeUID);
LABEL_28:
  if ( m_pComponent )
  {
    m_eDriverSellableItemType = this->m_eDriverSellableItemType;
    *(&m_pComponent[1].m_NameUID + m_eDriverSellableItemType) = 0;
    if ( m_pComponent->m_pSimObject == LocalPlayer )
    {
      if ( LOBYTE(m_pComponent[14].m_pSimObject)
        && (_DWORD)m_eDriverSellableItemType == *(_DWORD *)&m_pComponent[14].m_Flags )
      {
        v4 = 1;
      }
      UFG::GameStatAction::Inventory::UpdateItem((UFG::eInventoryItemEnum)m_eDriverSellableItemType, v4);
    }
    *(_DWORD *)&m_pComponent[14].m_Flags = this->m_eDriverOriginalSellableItemType;
  }
LABEL_35:
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&v15, m_pSimObject, 1);
  ArrayOfTuplesImplementation::clear(&v15);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v15);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v15);
}

// File Line: 3171
// RVA: 0x564280
void __fastcall UFG::TargetingSystemPedPlayerComponent::attachTransitDriverFaceComponent(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::SimObject *driver)
{
  UFG::SimObject *m_pSimObject; // r8
  UFG::SimComponent *ComponentOfType; // rbx
  __int16 m_Flags; // r9
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rsi
  __int64 v11; // r8
  unsigned int v12; // ecx
  unsigned int v13; // r9d
  unsigned int v14; // ecx
  unsigned int v15; // r9d
  signed __int16 v16; // cx
  unsigned int v17; // ecx
  unsigned int v18; // r9d
  UFG::SimComponentHolder *v19; // rsi
  __int64 v20; // r8
  unsigned int v21; // ecx
  unsigned int v22; // r9d
  unsigned int v23; // ecx
  unsigned int v24; // r9d
  UFG::eInventoryItemEnum v25; // ecx
  UFG::eInventoryItemEnum m_eDriverSellableItemType; // eax
  __int64 v27; // rcx
  signed __int16 v28; // cx
  unsigned int v29; // edx
  unsigned int v30; // r8d
  UFG::SimComponentHolder *v31; // r11
  unsigned int v32; // edx
  unsigned int v33; // r8d
  UFG::SimComponentHolder *v34; // r11
  unsigned int v35; // edx
  unsigned int v36; // r8d
  UFG::SimComponentHolder *v37; // r11
  UFG::FaceActionComponent *m_pDriverFaceActionComponent; // rcx
  unsigned int v39; // ebx
  UFG::FaceActionComponent *v40; // rbx
  UFG::SimObjectModifier v41; // [rsp+28h] [rbp-30h] BYREF

  m_pSimObject = this->m_pSimObject;
  ComponentOfType = 0i64;
  if ( !m_pSimObject )
    goto LABEL_29;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[44].m_pComponent;
    goto LABEL_28;
  }
  if ( m_Flags < 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v11 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && (UFG::CharacterOccupantComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_12;
      }
LABEL_11:
      m_pComponent = p[v11].m_pComponent;
      goto LABEL_28;
    }
    goto LABEL_12;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v12 = (unsigned int)m_pSimObject[1].vfptr;
    v13 = m_pSimObject->m_Components.size;
    if ( v12 < v13 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v11 = v12;
        if ( (p[v12].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && (UFG::CharacterOccupantComponent::_TypeUID & ~p[v12].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_11;
        }
        if ( ++v12 >= v13 )
          goto LABEL_12;
      }
    }
    goto LABEL_12;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v14 = (unsigned int)m_pSimObject[1].vfptr;
    v15 = m_pSimObject->m_Components.size;
    if ( v14 < v15 )
    {
      p = m_pSimObject->m_Components.p;
      do
      {
        v11 = v14;
        if ( (p[v14].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && (UFG::CharacterOccupantComponent::_TypeUID & ~p[v14].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_11;
        }
      }
      while ( ++v14 < v15 );
    }
LABEL_12:
    m_pComponent = 0i64;
    goto LABEL_28;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(this->m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
LABEL_28:
  if ( m_pComponent )
    return;
LABEL_29:
  if ( !driver )
    return;
  v16 = driver->m_Flags;
  if ( (v16 & 0x4000) != 0 )
  {
    ComponentOfType = driver->m_Components.p[39].m_pComponent;
    goto LABEL_55;
  }
  if ( v16 < 0 )
  {
    v17 = (unsigned int)driver[1].vfptr;
    v18 = driver->m_Components.size;
    if ( v17 >= v18 )
      goto LABEL_55;
    v19 = driver->m_Components.p;
    while ( 1 )
    {
      v20 = v17;
      if ( (v19[v17].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
        && (UFG::InventoryComponent::_TypeUID & ~v19[v17].m_TypeUID & 0x1FFFFFF) == 0 )
      {
        goto LABEL_39;
      }
      if ( ++v17 >= v18 )
        goto LABEL_55;
    }
  }
  if ( (v16 & 0x2000) != 0 )
  {
    v21 = (unsigned int)driver[1].vfptr;
    v22 = driver->m_Components.size;
    if ( v21 < v22 )
    {
      v19 = driver->m_Components.p;
      while ( 1 )
      {
        v20 = v21;
        if ( (v19[v21].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
          && (UFG::InventoryComponent::_TypeUID & ~v19[v21].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++v21 >= v22 )
          goto LABEL_55;
      }
LABEL_39:
      ComponentOfType = v19[v20].m_pComponent;
    }
  }
  else if ( (v16 & 0x1000) != 0 )
  {
    v23 = (unsigned int)driver[1].vfptr;
    v24 = driver->m_Components.size;
    if ( v23 < v24 )
    {
      v19 = driver->m_Components.p;
      do
      {
        v20 = v23;
        if ( (v19[v23].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
          && (UFG::InventoryComponent::_TypeUID & ~v19[v23].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_39;
        }
      }
      while ( ++v23 < v24 );
    }
  }
  else
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(driver, UFG::InventoryComponent::_TypeUID);
  }
LABEL_55:
  if ( ComponentOfType )
  {
    v25 = *(_DWORD *)&ComponentOfType[14].m_Flags;
    m_eDriverSellableItemType = this->m_eDriverSellableItemType;
    if ( v25 != m_eDriverSellableItemType )
    {
      this->m_eDriverOriginalSellableItemType = v25;
      *(_DWORD *)&ComponentOfType[14].m_Flags = m_eDriverSellableItemType;
    }
    v27 = this->m_eDriverSellableItemType;
    if ( (!LOBYTE(ComponentOfType[14].m_pSimObject) || (_DWORD)v27 != *(_DWORD *)&ComponentOfType[14].m_Flags)
      && *((int *)&ComponentOfType[1].m_NameUID + v27) <= 0 )
    {
      *(&ComponentOfType[1].m_NameUID + v27) = 1;
      if ( ComponentOfType->m_pSimObject == LocalPlayer )
        UFG::GameStatAction::Inventory::UpdateItem((UFG::eInventoryItemEnum)v27, 1);
    }
    v28 = driver->m_Flags;
    if ( (v28 & 0x4000) == 0 )
    {
      if ( v28 >= 0 )
      {
        if ( (v28 & 0x2000) != 0 )
        {
          v32 = (unsigned int)driver[1].vfptr;
          v33 = driver->m_Components.size;
          if ( v32 < v33 )
          {
            v34 = driver->m_Components.p;
            do
            {
              if ( (v34[v32].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                && (UFG::FaceActionComponent::_TypeUID & ~v34[v32].m_TypeUID & 0x1FFFFFF) == 0 )
              {
                break;
              }
              ++v32;
            }
            while ( v32 < v33 );
          }
        }
        else if ( (v28 & 0x1000) != 0 )
        {
          v35 = (unsigned int)driver[1].vfptr;
          v36 = driver->m_Components.size;
          if ( v35 < v36 )
          {
            v37 = driver->m_Components.p;
            do
            {
              if ( (v37[v35].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                && (UFG::FaceActionComponent::_TypeUID & ~v37[v35].m_TypeUID & 0x1FFFFFF) == 0 )
              {
                break;
              }
              ++v35;
            }
            while ( v35 < v36 );
          }
        }
        else
        {
          UFG::SimObject::GetComponentOfType(driver, UFG::FaceActionComponent::_TypeUID);
        }
      }
      else
      {
        v29 = (unsigned int)driver[1].vfptr;
        v30 = driver->m_Components.size;
        if ( v29 < v30 )
        {
          v31 = driver->m_Components.p;
          do
          {
            if ( (v31[v29].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
              && (UFG::FaceActionComponent::_TypeUID & ~v31[v29].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              break;
            }
            ++v29;
          }
          while ( v29 < v30 );
        }
      }
    }
    m_pDriverFaceActionComponent = this->m_pDriverFaceActionComponent;
    if ( (m_pDriverFaceActionComponent->m_Flags & 1) == 0 )
    {
      UFG::FaceActionComponent::ResetState(m_pDriverFaceActionComponent);
      if ( (driver->m_Flags & 0x4000) != 0 )
        v39 = 45;
      else
        v39 = -1;
      UFG::SimObjectModifier::SimObjectModifier(&v41, driver, 1);
      UFG::SimObjectModifier::AttachComponent(&v41, this->m_pDriverFaceActionComponent, v39);
      UFG::SimObjectModifier::Close(&v41);
      UFG::SimObjectModifier::~SimObjectModifier(&v41);
      v40 = this->m_pDriverFaceActionComponent;
      if ( !v40->mFaceActionEnabled )
        UFG::FaceActionComponent::ProcessIconLogic(this->m_pDriverFaceActionComponent);
      v40->mFaceActionEnabled = 1;
    }
  }
}

// File Line: 3221
// RVA: 0x57B360
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateVehicleClosestPointTarget(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingMap *m_pTargetingMap; // rdx
  UFG::TargetingSimObject *m_pTargets; // r8
  UFG::SimObject *m_pPointer; // rcx
  unsigned __int8 v5; // al
  __int64 v6; // rbx
  UFG::TargetingSimObject *v7; // rax
  __int64 v8; // rax
  __int16 m_Flags; // dx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::PhysicsMoverInterface *m_pComponent; // rbx
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  __int64 v14; // rdx
  float x; // xmm2_4
  float y; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm7_4
  float v19; // xmm6_4
  float v20; // xmm8_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  UFG::qVector4 *v24; // rax
  UFG::TransformNodeComponent *v25; // rcx
  float v26; // xmm0_4
  float z; // xmm1_4
  unsigned __int8 v28; // cl
  unsigned __int8 v29; // cl
  unsigned __int64 v30; // rbx
  UFG::TargetingSimObject *v31; // rax
  UFG::qVector3 pos; // [rsp+20h] [rbp-79h] BYREF
  UFG::qVector3 min; // [rsp+30h] [rbp-69h] BYREF
  UFG::qVector3 max; // [rsp+40h] [rbp-59h] BYREF
  UFG::qVector4 row_vec4; // [rsp+50h] [rbp-49h] BYREF
  UFG::qMatrix44 d; // [rsp+60h] [rbp-39h] BYREF
  UFG::qVector4 result; // [rsp+A0h] [rbp+7h] BYREF

  m_pTargetingMap = this->m_pTargetingMap;
  m_pTargets = this->m_pTargets;
  m_pPointer = m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[28]].m_pTarget.m_pPointer;
  if ( !m_pPointer )
  {
    v5 = m_pTargetingMap->m_Map.p[46];
    if ( v5 )
    {
      v6 = v5;
      UFG::TargetingSimObject::SetTarget(&m_pTargets[v6], 0i64);
      v7 = this->m_pTargets;
      if ( v7[v6].m_bLock )
        v7[v6].m_bLock = 0;
    }
    return;
  }
  v8 = (unsigned __int8)m_pTargetingMap->m_Map.p[46];
  if ( m_pTargets[v8].m_pTarget.m_pPointer && m_pTargets[v8].m_bLock )
    return;
  if ( !this->m_pVehicleClosestPointTNC.m_pPointer )
    goto LABEL_39;
  m_Flags = m_pPointer->m_Flags;
  m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_9;
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
    goto LABEL_23;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    m_pComponent = 0i64;
    goto LABEL_23;
  }
  if ( (m_Flags & 0x1000) == 0 )
  {
    m_pComponent = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::PhysicsMoverInterface::_TypeUID);
    goto LABEL_23;
  }
  vfptr = (unsigned int)m_pPointer[1].vfptr;
  size = m_pPointer->m_Components.size;
  if ( vfptr >= size )
  {
LABEL_9:
    m_pComponent = 0i64;
  }
  else
  {
    v14 = (__int64)&m_pPointer->m_Components.p[vfptr];
    while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
         || (UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF) != 0 )
    {
      ++vfptr;
      v14 += 16i64;
      if ( vfptr >= size )
      {
        m_pComponent = 0i64;
        goto LABEL_23;
      }
    }
    m_pComponent = *(UFG::PhysicsMoverInterface **)v14;
  }
LABEL_23:
  if ( m_pTransformNodeComponent && m_pComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    UFG::qInverseAffine(&d, &m_pTransformNodeComponent->mWorldTransform);
    x = this->m_vTargetingPosition.x;
    y = this->m_vTargetingPosition.y;
    v17 = this->m_vTargetingPosition.z + 0.69999999;
    v18 = (float)((float)((float)(d.v0.x * x) + (float)(d.v1.x * y)) + (float)(d.v2.x * v17)) + d.v3.x;
    v19 = (float)((float)((float)(d.v0.y * x) + (float)(d.v1.y * y)) + (float)(d.v2.y * v17)) + d.v3.y;
    v20 = (float)((float)((float)(d.v0.z * x) + (float)(d.v1.z * y)) + (float)(d.v2.z * v17)) + d.v3.z;
    UFG::PhysicsMoverInterface::GetBoundingBoxLocalSpace(m_pComponent, &min, &max);
    v21 = min.z + 0.5;
    v22 = min.x + 0.5;
    v23 = min.y + 0.5;
    if ( v20 > (float)(min.z + 0.5) )
    {
      if ( v20 <= (float)(max.z - 0.5) )
        v21 = v20;
      else
        v21 = max.z - 0.5;
    }
    if ( v19 > v23 )
    {
      if ( v19 <= (float)(max.y - 0.5) )
        v23 = v19;
      else
        v23 = max.y - 0.5;
    }
    if ( v18 > v22 )
    {
      if ( v18 <= (float)(max.x - 0.5) )
        v22 = v18;
      else
        v22 = max.x - 0.5;
    }
    row_vec4.x = v22;
    row_vec4.y = v23;
    LODWORD(row_vec4.w) = (_DWORD)FLOAT_1_0;
    row_vec4.z = v21;
    v24 = UFG::operator*(&result, &row_vec4, &m_pTransformNodeComponent->mWorldTransform);
    v25 = (UFG::TransformNodeComponent *)this->m_pVehicleClosestPointTNC.m_pPointer;
    v26 = v24->x;
    pos.y = v24->y;
    z = this->m_vTargetingPosition.z;
    pos.x = v26;
    pos.z = z;
    UFG::TransformNodeComponent::SetWorldTranslation(v25, &pos);
    v28 = this->m_pTargetingMap->m_Map.p[46];
    if ( v28 )
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v28], this->m_pVehicleClosestPointSimObject.m_pPointer);
    return;
  }
LABEL_39:
  v29 = this->m_pTargetingMap->m_Map.p[46];
  if ( v29 )
  {
    v30 = v29;
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v30], 0i64);
    v31 = this->m_pTargets;
    if ( v31[v30].m_bLock )
      v31[v30].m_bLock = 0;
  }
}

// File Line: 3287
// RVA: 0x576DD0
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateRagdoll(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *v1; // rsi
  UFG::SimObjectGame *v3; // rbp
  UFG::SimObjectGame *m_pPointer; // rdi
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r8
  unsigned int m_TypeUID; // ecx
  unsigned int v8; // ecx
  unsigned int mComponentTableEntryCount; // edx
  unsigned int size; // r9d
  __int64 v11; // r8
  unsigned int v12; // edx
  unsigned int v13; // r9d
  __int64 v14; // rax
  __int64 v15; // rdx
  __int16 v16; // cx
  UFG::RagdollComponent *ComponentOfType; // rax
  unsigned int v18; // r8d
  unsigned int v19; // r10d
  unsigned int v20; // r9d
  __int64 v21; // rdx
  unsigned int v22; // r8d
  unsigned int v23; // r10d
  unsigned int v24; // r8d
  unsigned int v25; // r10d
  __int16 v26; // cx
  UFG::RagdollComponent *v27; // rax
  unsigned int v28; // r8d
  unsigned int v29; // r10d
  __int64 v30; // rdx
  unsigned int v31; // r8d
  unsigned int v32; // r10d
  unsigned int v33; // r8d
  unsigned int v34; // r10d
  UFG::RagdollComponent *v35; // rcx
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *p_m_RagdollTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::RagdollComponent *v39; // rcx
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *p_m_FocusTargetsGrappleTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v42; // rax
  __int16 v43; // cx
  UFG::SimComponent *v44; // rax
  unsigned int v45; // r8d
  unsigned int v46; // r10d
  unsigned int v47; // r9d
  __int64 v48; // rdx
  UFG::RagdollComponent *v49; // rax
  __int16 v50; // cx
  unsigned int v51; // r8d
  unsigned int v52; // r10d
  __int64 v53; // rdx
  UFG::RagdollComponent *v54; // rax

  v1 = 0i64;
  v3 = 0i64;
  m_pPointer = (UFG::SimObjectGame *)this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( !m_pPointer )
  {
LABEL_87:
    v35 = this->m_RagdollTarget.m_pPointer;
    if ( v35 )
    {
      UFG::RagdollComponent::Release(v35, 0);
      p_m_RagdollTarget = &this->m_RagdollTarget;
      if ( this->m_RagdollTarget.m_pPointer )
      {
        mPrev = p_m_RagdollTarget->mPrev;
        mNext = this->m_RagdollTarget.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_m_RagdollTarget->mPrev = p_m_RagdollTarget;
        this->m_RagdollTarget.mNext = &this->m_RagdollTarget;
      }
      this->m_RagdollTarget.m_pPointer = 0i64;
    }
    goto LABEL_91;
  }
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_6;
    m_TypeUID = m_pComponent->m_TypeUID;
    if ( ((m_TypeUID ^ UFG::TargetingSystemPedBaseComponent::_TypeUID) & 0xFE000000) != 0
      || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_6;
    }
  }
  else
  {
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        mComponentTableEntryCount = m_pPointer->mComponentTableEntryCount;
        size = m_pPointer->m_Components.size;
        if ( mComponentTableEntryCount >= size )
        {
LABEL_6:
          m_pComponent = 0i64;
          goto LABEL_28;
        }
        v11 = (__int64)&m_pPointer->m_Components.p[mComponentTableEntryCount];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF) != 0 )
        {
          ++mComponentTableEntryCount;
          v11 += 16i64;
          if ( mComponentTableEntryCount >= size )
          {
            m_pComponent = 0i64;
            goto LABEL_28;
          }
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemPedBaseComponent::_TypeUID);
          goto LABEL_28;
        }
        v12 = m_pPointer->mComponentTableEntryCount;
        v13 = m_pPointer->m_Components.size;
        if ( v12 >= v13 )
          goto LABEL_6;
        v11 = (__int64)&m_pPointer->m_Components.p[v12];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v12;
          v11 += 16i64;
          if ( v12 >= v13 )
          {
            m_pComponent = 0i64;
            goto LABEL_28;
          }
        }
      }
      m_pComponent = *(UFG::SimComponent **)v11;
      goto LABEL_28;
    }
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_6;
    v8 = m_pComponent->m_TypeUID;
    if ( ((v8 ^ UFG::TargetingSystemPedBaseComponent::_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_6;
    if ( (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v8 & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
  }
LABEL_28:
  if ( m_pComponent )
  {
    v14 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
    v15 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 31i64);
    if ( *(_QWORD *)(v15 + v14 + 40) )
    {
      if ( *(_BYTE *)(v15 + v14 + 49) )
        v3 = *(UFG::SimObjectGame **)(v15 + v14 + 40);
    }
  }
  v16 = m_pPointer->m_Flags;
  if ( (v16 & 0x4000) == 0 )
  {
    if ( v16 >= 0 )
    {
      if ( (v16 & 0x2000) != 0 )
      {
        v22 = m_pPointer->mComponentTableEntryCount;
        v23 = m_pPointer->m_Components.size;
        v20 = UFG::RagdollComponent::_TypeUID;
        if ( v22 < v23 )
        {
          v21 = (__int64)&m_pPointer->m_Components.p[v22];
          while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
               || (UFG::RagdollComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v22;
            v21 += 16i64;
            if ( v22 >= v23 )
            {
              ComponentOfType = 0i64;
              goto LABEL_58;
            }
          }
          goto LABEL_41;
        }
      }
      else
      {
        if ( (v16 & 0x1000) == 0 )
        {
          ComponentOfType = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                                       m_pPointer,
                                                       UFG::RagdollComponent::_TypeUID);
          goto LABEL_57;
        }
        v24 = m_pPointer->mComponentTableEntryCount;
        v25 = m_pPointer->m_Components.size;
        v20 = UFG::RagdollComponent::_TypeUID;
        if ( v24 < v25 )
        {
          v21 = (__int64)&m_pPointer->m_Components.p[v24];
          while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
               || (UFG::RagdollComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v24;
            v21 += 16i64;
            if ( v24 >= v25 )
            {
              ComponentOfType = 0i64;
              goto LABEL_58;
            }
          }
          goto LABEL_41;
        }
      }
    }
    else
    {
      v18 = m_pPointer->mComponentTableEntryCount;
      v19 = m_pPointer->m_Components.size;
      v20 = UFG::RagdollComponent::_TypeUID;
      if ( v18 < v19 )
      {
        v21 = (__int64)&m_pPointer->m_Components.p[v18];
        while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
             || (UFG::RagdollComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v18;
          v21 += 16i64;
          if ( v18 >= v19 )
            goto LABEL_40;
        }
LABEL_41:
        ComponentOfType = *(UFG::RagdollComponent **)v21;
        goto LABEL_58;
      }
    }
LABEL_40:
    ComponentOfType = 0i64;
    goto LABEL_58;
  }
  ComponentOfType = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
LABEL_57:
  v20 = UFG::RagdollComponent::_TypeUID;
LABEL_58:
  if ( ComponentOfType != this->m_RagdollTarget.m_pPointer )
    goto LABEL_87;
  if ( v3 )
  {
    v26 = v3->m_Flags;
    if ( (v26 & 0x4000) != 0 )
    {
      v27 = (UFG::RagdollComponent *)v3->m_Components.p[42].m_pComponent;
      goto LABEL_85;
    }
    if ( v26 >= 0 )
    {
      if ( (v26 & 0x2000) != 0 )
      {
        v31 = v3->mComponentTableEntryCount;
        v32 = v3->m_Components.size;
        if ( v31 < v32 )
        {
          v30 = (__int64)&v3->m_Components.p[v31];
          while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (v20 & 0xFE000000)
               || (v20 & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v31;
            v30 += 16i64;
            if ( v31 >= v32 )
            {
              v27 = 0i64;
              goto LABEL_85;
            }
          }
          goto LABEL_69;
        }
      }
      else
      {
        if ( (v26 & 0x1000) == 0 )
        {
          v27 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(v3, v20);
LABEL_85:
          if ( v27 == this->m_FocusTargetsGrappleTarget.m_pPointer )
            goto LABEL_95;
          goto LABEL_91;
        }
        v33 = v3->mComponentTableEntryCount;
        v34 = v3->m_Components.size;
        if ( v33 < v34 )
        {
          v30 = (__int64)&v3->m_Components.p[v33];
          while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (v20 & 0xFE000000)
               || (v20 & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v33;
            v30 += 16i64;
            if ( v33 >= v34 )
            {
              v27 = 0i64;
              goto LABEL_85;
            }
          }
          goto LABEL_69;
        }
      }
    }
    else
    {
      v28 = v3->mComponentTableEntryCount;
      v29 = v3->m_Components.size;
      if ( v28 < v29 )
      {
        v30 = (__int64)&v3->m_Components.p[v28];
        while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (v20 & 0xFE000000)
             || (v20 & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v28;
          v30 += 16i64;
          if ( v28 >= v29 )
            goto LABEL_68;
        }
LABEL_69:
        v27 = *(UFG::RagdollComponent **)v30;
        goto LABEL_85;
      }
    }
LABEL_68:
    v27 = 0i64;
    goto LABEL_85;
  }
LABEL_91:
  v39 = this->m_FocusTargetsGrappleTarget.m_pPointer;
  if ( v39 )
  {
    UFG::RagdollComponent::Release(v39, 0);
    p_m_FocusTargetsGrappleTarget = &this->m_FocusTargetsGrappleTarget;
    if ( this->m_FocusTargetsGrappleTarget.m_pPointer )
    {
      v41 = p_m_FocusTargetsGrappleTarget->mPrev;
      v42 = this->m_FocusTargetsGrappleTarget.mNext;
      v41->mNext = v42;
      v42->mPrev = v41;
      p_m_FocusTargetsGrappleTarget->mPrev = p_m_FocusTargetsGrappleTarget;
      this->m_FocusTargetsGrappleTarget.mNext = &this->m_FocusTargetsGrappleTarget;
    }
    this->m_FocusTargetsGrappleTarget.m_pPointer = 0i64;
  }
LABEL_95:
  if ( !this->m_bIsAimingActive )
    return;
  if ( this->m_RagdollTarget.m_pPointer || !m_pPointer )
    goto LABEL_117;
  v43 = m_pPointer->m_Flags;
  if ( (v43 & 0x4000) != 0 )
  {
    v44 = m_pPointer->m_Components.p[3].m_pComponent;
LABEL_113:
    v47 = UFG::SimObjectPropertiesComponent::_TypeUID;
    goto LABEL_114;
  }
  if ( v43 < 0 )
  {
    v44 = m_pPointer->m_Components.p[3].m_pComponent;
    goto LABEL_113;
  }
  if ( (v43 & 0x2000) != 0 )
  {
    v44 = m_pPointer->m_Components.p[4].m_pComponent;
    goto LABEL_113;
  }
  if ( (v43 & 0x1000) == 0 )
  {
    v44 = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SimObjectPropertiesComponent::_TypeUID);
    goto LABEL_113;
  }
  v45 = m_pPointer->mComponentTableEntryCount;
  v46 = m_pPointer->m_Components.size;
  v47 = UFG::SimObjectPropertiesComponent::_TypeUID;
  if ( v45 >= v46 )
  {
LABEL_110:
    v44 = 0i64;
  }
  else
  {
    v48 = (__int64)&m_pPointer->m_Components.p[v45];
    while ( (*(_DWORD *)(v48 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
         || (UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v48 + 8) & 0x1FFFFFF) != 0 )
    {
      ++v45;
      v48 += 16i64;
      if ( v45 >= v46 )
        goto LABEL_110;
    }
    v44 = *(UFG::SimComponent **)v48;
  }
LABEL_114:
  if ( v44 && LODWORD(v44[1].m_SafePointerList.mNode.mNext) == 1 )
  {
    v49 = (UFG::RagdollComponent *)UFG::RagdollComponent::Acquire(m_pPointer);
    UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent>::operator=(&this->m_RagdollTarget, v49);
LABEL_117:
    v47 = UFG::SimObjectPropertiesComponent::_TypeUID;
  }
  if ( !this->m_FocusTargetsGrappleTarget.m_pPointer && v3 && v3 != this->m_pSimObject )
  {
    v50 = v3->m_Flags;
    if ( (v50 & 0x4000) != 0 )
    {
      v1 = v3->m_Components.p[3].m_pComponent;
    }
    else if ( v50 >= 0 )
    {
      if ( (v50 & 0x2000) != 0 )
      {
        v1 = v3->m_Components.p[4].m_pComponent;
      }
      else if ( (v50 & 0x1000) != 0 )
      {
        v51 = v3->mComponentTableEntryCount;
        v52 = v3->m_Components.size;
        if ( v51 < v52 )
        {
          v53 = (__int64)&v3->m_Components.p[v51];
          while ( (*(_DWORD *)(v53 + 8) & 0xFE000000) != (v47 & 0xFE000000)
               || (v47 & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v51;
            v53 += 16i64;
            if ( v51 >= v52 )
              goto LABEL_136;
          }
          v1 = *(UFG::SimComponent **)v53;
        }
      }
      else
      {
        v1 = UFG::SimObject::GetComponentOfType(v3, v47);
      }
    }
    else
    {
      v1 = v3->m_Components.p[3].m_pComponent;
    }
LABEL_136:
    if ( v1 )
    {
      if ( LODWORD(v1[1].m_SafePointerList.mNode.mNext) == 1 )
      {
        v54 = (UFG::RagdollComponent *)UFG::RagdollComponent::Acquire(v3);
        UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent>::operator=(
          &this->m_FocusTargetsGrappleTarget,
          v54);
      }
    }
  }
}

// File Line: 3378
// RVA: 0x577EE0
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateRimLighting(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimObject *m_pPointer; // r9
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_Target; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  if ( this->m_RimLighting.m_bEnabled )
  {
    m_pPointer = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[this->m_RimLighting.m_TargetType]].m_pTarget.m_pPointer;
    if ( m_pPointer != this->m_RimLighting.m_Target.m_pPointer )
    {
      p_m_Target = &this->m_RimLighting.m_Target;
      if ( this->m_RimLighting.m_Target.m_pPointer )
      {
        mPrev = p_m_Target->mPrev;
        mNext = p_m_Target->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_m_Target->mPrev = p_m_Target;
        p_m_Target->mNext = p_m_Target;
      }
      p_m_Target->m_pPointer = m_pPointer;
      if ( m_pPointer )
      {
        v5 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v5->mNext = p_m_Target;
        p_m_Target->mPrev = v5;
        p_m_Target->mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_Target;
      }
    }
  }
}

// File Line: 3403
// RVA: 0x57B980
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateVehicleProjectileTargets(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimObject *m_pPointer; // rdi
  UFG::VehicleOccupantComponent *m_pComponent; // r14
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_m_pVehicleFocusTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::RagdollComponent **p_m_pPointer; // rbx
  __int64 v8; // rsi
  __int64 v9; // rcx
  _QWORD *v10; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  unsigned int NumberOfOccupants; // esi
  unsigned int v16; // edi
  char *v17; // rbx
  UFG::SimObjectGame *Occupant; // rax
  UFG::SimComponent *v19; // rax
  __int64 v20; // rdx
  _QWORD *v21; // rcx
  _QWORD *p_mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  unsigned int v24; // edi
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *m_VehicleCharacterRagdolls; // rbx
  UFG::RagdollComponent *v26; // rcx
  UFG::RagdollComponent *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v32; // rax
  char ptr[16]; // [rsp+40h] [rbp-118h] BYREF
  char v34; // [rsp+50h] [rbp-108h] BYREF

  m_pPointer = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( !m_pPointer )
    goto LABEL_5;
  if ( (m_pPointer->m_Flags & 0x8000u) == 0 )
    m_pPointer = 0i64;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::VehicleOccupantComponent *)m_pPointer->m_Components.p[30].m_pComponent;
    if ( m_pComponent )
    {
      if ( m_pPointer == this->m_pVehicleFocusTarget.m_pPointer )
        goto LABEL_19;
      goto LABEL_9;
    }
  }
  else
  {
LABEL_5:
    m_pComponent = 0i64;
  }
  m_pPointer = 0i64;
LABEL_9:
  if ( this->m_pVehicleFocusTarget.m_pPointer )
  {
    p_m_pVehicleFocusTarget = &this->m_pVehicleFocusTarget;
    if ( this->m_pVehicleFocusTarget.m_pPointer )
    {
      mPrev = p_m_pVehicleFocusTarget->mPrev;
      mNext = p_m_pVehicleFocusTarget->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pVehicleFocusTarget->mPrev = p_m_pVehicleFocusTarget;
      p_m_pVehicleFocusTarget->mNext = p_m_pVehicleFocusTarget;
    }
    p_m_pVehicleFocusTarget->m_pPointer = 0i64;
  }
  p_m_pPointer = &this->m_VehicleCharacterRagdolls[0].m_pPointer;
  v8 = 10i64;
  do
  {
    if ( *p_m_pPointer )
    {
      UFG::RagdollComponent::Release(*p_m_pPointer, 0);
      if ( *p_m_pPointer )
      {
        v9 = (__int64)*(p_m_pPointer - 2);
        v10 = *(p_m_pPointer - 1);
        *(_QWORD *)(v9 + 8) = v10;
        *v10 = v9;
        *(p_m_pPointer - 2) = (UFG::RagdollComponent *)(p_m_pPointer - 2);
        *(p_m_pPointer - 1) = (UFG::RagdollComponent *)(p_m_pPointer - 2);
      }
      *p_m_pPointer = 0i64;
    }
    p_m_pPointer += 3;
    --v8;
  }
  while ( v8 );
LABEL_19:
  if ( this->m_bIsAimingActive && m_pPointer )
  {
    if ( !this->m_pVehicleFocusTarget.m_pPointer )
    {
      v11 = &this->m_pVehicleFocusTarget;
      if ( this->m_pVehicleFocusTarget.m_pPointer )
      {
        v12 = v11->mPrev;
        v13 = this->m_pVehicleFocusTarget.mNext;
        v12->mNext = v13;
        v13->mPrev = v12;
        v11->mPrev = v11;
        this->m_pVehicleFocusTarget.mNext = &this->m_pVehicleFocusTarget;
      }
      this->m_pVehicleFocusTarget.m_pPointer = m_pPointer;
      v14 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v14->mNext = v11;
      v11->mPrev = v14;
      this->m_pVehicleFocusTarget.mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v11;
    }
    `eh vector constructor iterator(
      ptr,
      0x18ui64,
      10,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody>::qSafePointer<UFG::SimComponent,UFG::RigidBody>);
    NumberOfOccupants = UFG::VehicleOccupantComponent::GetNumberOfOccupants(m_pComponent);
    v16 = 0;
    if ( NumberOfOccupants )
    {
      v17 = ptr;
      do
      {
        Occupant = (UFG::SimObjectGame *)UFG::VehicleOccupantComponent::GetOccupant(m_pComponent, v16, 0i64);
        v19 = UFG::RagdollComponent::Acquire(Occupant);
        if ( *((_QWORD *)v17 + 2) )
        {
          v20 = *(_QWORD *)v17;
          v21 = (_QWORD *)*((_QWORD *)v17 + 1);
          *(_QWORD *)(v20 + 8) = v21;
          *v21 = v20;
          *(_QWORD *)v17 = v17;
          *((_QWORD *)v17 + 1) = v17;
        }
        *((_QWORD *)v17 + 2) = v19;
        if ( v19 )
        {
          p_mPrev = &v19->m_SafePointerList.mNode.mPrev;
          v23 = v19->m_SafePointerList.mNode.mPrev;
          v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v17;
          *(_QWORD *)v17 = v23;
          *((_QWORD *)v17 + 1) = p_mPrev;
          *p_mPrev = v17;
        }
        ++v16;
        v17 += 24;
      }
      while ( v16 < NumberOfOccupants );
    }
    v24 = 0;
    m_VehicleCharacterRagdolls = this->m_VehicleCharacterRagdolls;
    do
    {
      v26 = m_VehicleCharacterRagdolls->m_pPointer;
      if ( v26 )
        UFG::RagdollComponent::Release(v26, 0);
      if ( v24 >= NumberOfOccupants )
      {
        if ( m_VehicleCharacterRagdolls->m_pPointer )
        {
          v31 = m_VehicleCharacterRagdolls->mPrev;
          v32 = m_VehicleCharacterRagdolls->mNext;
          v31->mNext = v32;
          v32->mPrev = v31;
          m_VehicleCharacterRagdolls->mPrev = m_VehicleCharacterRagdolls;
          m_VehicleCharacterRagdolls->mNext = m_VehicleCharacterRagdolls;
        }
        m_VehicleCharacterRagdolls->m_pPointer = 0i64;
      }
      else
      {
        v27 = *(UFG::RagdollComponent **)((char *)&m_VehicleCharacterRagdolls[-130] + &v34 - (char *)this - 16);
        if ( m_VehicleCharacterRagdolls->m_pPointer )
        {
          v28 = m_VehicleCharacterRagdolls->mPrev;
          v29 = m_VehicleCharacterRagdolls->mNext;
          v28->mNext = v29;
          v29->mPrev = v28;
          m_VehicleCharacterRagdolls->mPrev = m_VehicleCharacterRagdolls;
          m_VehicleCharacterRagdolls->mNext = m_VehicleCharacterRagdolls;
        }
        m_VehicleCharacterRagdolls->m_pPointer = v27;
        if ( v27 )
        {
          v30 = v27->UFG::qSafePointerNode<UFG::RagdollComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::RagdollComponent>::mPrev;
          v30->mNext = m_VehicleCharacterRagdolls;
          m_VehicleCharacterRagdolls->mPrev = v30;
          m_VehicleCharacterRagdolls->mNext = &v27->UFG::qSafePointerNode<UFG::RagdollComponent>::m_SafePointerList.mNode;
          v27->UFG::qSafePointerNode<UFG::RagdollComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::RagdollComponent>::mPrev = m_VehicleCharacterRagdolls;
        }
      }
      ++v24;
      ++m_VehicleCharacterRagdolls;
    }
    while ( v24 < 0xA );
    `eh vector destructor iterator(
      ptr,
      0x18ui64,
      10,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
  }
}

// File Line: 3521
// RVA: 0x56B090
void __fastcall UFG::TargetingSystemPedPlayerComponent::maybeReleaseLockedTarget(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingProfile *m_pActiveTargetingProfile; // r13
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v4; // rdx
  UFG::SimObject *m_pPointer; // r15
  bool v6; // di
  int v7; // r14d
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v12; // rdx
  unsigned int v13; // r8d
  unsigned int v14; // r9d
  __int16 v15; // cx
  unsigned int v16; // r8d
  unsigned int v17; // r9d
  __int64 v18; // rdx
  UFG::VehicleOccupantComponent *ComponentOfType; // rbp
  unsigned int v20; // r8d
  unsigned int v21; // r9d
  unsigned int v22; // r8d
  unsigned int v23; // r9d
  unsigned int v24; // edi
  unsigned int NumberOfOccupants; // r12d
  UFG::SimObject *Occupant; // rax
  __int16 v27; // dx
  UFG::SimComponent *v28; // rax
  unsigned int v29; // r8d
  unsigned int v30; // r10d
  __int64 v31; // rdx
  unsigned int v32; // r8d
  unsigned int v33; // r10d
  UFG::SimComponent *m_pSimComponent; // rdi
  unsigned int ActionMostUsedIndex_DismountShoot; // ebx
  ActionID *ActionID_DismountShoot; // rax
  unsigned __int8 IsPlaying; // al
  UFG::SimComponent *v38; // rax
  UFG::TargetingProfile *v39; // rdx
  float v40; // xmm10_4
  float v41; // xmm11_4
  float v42; // xmm0_4
  float m_fTargetReleaseDistanceSquared; // xmm0_4
  __int64 v44; // rbx
  bool v45; // zf
  float m_fIdlePriorityConeTime; // xmm1_4
  float v47; // xmm0_4
  float v48; // xmm6_4
  float x; // xmm0_4
  float y; // xmm1_4
  UFG::qVector3 *v51; // rdx
  unsigned __int8 v52; // cl
  unsigned __int64 v53; // rbx
  UFG::TargetingSimObject *v54; // rax
  UFG::qVector3 v1; // [rsp+20h] [rbp-F8h] BYREF
  int v56[4]; // [rsp+30h] [rbp-E8h] BYREF
  UFG::qVector3 v2; // [rsp+40h] [rbp-D8h] BYREF
  UFG::qMatrix44 matSimObject; // [rsp+50h] [rbp-C8h] BYREF

  m_pActiveTargetingProfile = this->m_pActiveTargetingProfile;
  m_pTargets = this->m_pTargets;
  v4 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[22];
  if ( !m_pTargets[v4].m_pTarget.m_pPointer )
    return;
  if ( !m_pTargets[v4].m_bLock )
    return;
  m_pPointer = m_pTargets[v4].m_pTarget.m_pPointer;
  if ( !m_pPointer )
    return;
  v6 = 0;
  v7 = 0;
  if ( !this->m_bHasRangedWeapon && !this->m_bIsInAnyCombat )
    goto LABEL_82;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
    goto LABEL_26;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
    goto LABEL_26;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    vfptr = (unsigned int)m_pPointer[1].vfptr;
    size = m_pPointer->m_Components.size;
    if ( vfptr < size )
    {
      v12 = (__int64)&m_pPointer->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
           || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v12 += 16i64;
        if ( vfptr >= size )
          goto LABEL_16;
      }
LABEL_17:
      m_pComponent = *(UFG::SimComponent **)v12;
      goto LABEL_26;
    }
    goto LABEL_16;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v13 = (unsigned int)m_pPointer[1].vfptr;
    v14 = m_pPointer->m_Components.size;
    if ( v13 < v14 )
    {
      v12 = (__int64)&m_pPointer->m_Components.p[v13];
      while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
           || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v13;
        v12 += 16i64;
        if ( v13 >= v14 )
        {
          m_pComponent = 0i64;
          goto LABEL_26;
        }
      }
      goto LABEL_17;
    }
LABEL_16:
    m_pComponent = 0i64;
    goto LABEL_26;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HealthComponent::_TypeUID);
LABEL_26:
  if ( m_pComponent )
    v6 = BYTE4(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) != 0;
  v15 = m_pPointer->m_Flags;
  if ( (v15 & 0x4000) != 0 )
  {
    v16 = (unsigned int)m_pPointer[1].vfptr;
    v17 = m_pPointer->m_Components.size;
    if ( v16 < v17 )
    {
      v18 = (__int64)&m_pPointer->m_Components.p[v16];
      while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
           || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v16;
        v18 += 16i64;
        if ( v16 >= v17 )
          goto LABEL_34;
      }
LABEL_35:
      ComponentOfType = *(UFG::VehicleOccupantComponent **)v18;
      goto LABEL_53;
    }
    goto LABEL_34;
  }
  if ( v15 >= 0 )
  {
    if ( (v15 & 0x2000) != 0 )
    {
      v20 = (unsigned int)m_pPointer[1].vfptr;
      v21 = m_pPointer->m_Components.size;
      if ( v20 < v21 )
      {
        v18 = (__int64)&m_pPointer->m_Components.p[v20];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v20;
          v18 += 16i64;
          if ( v20 >= v21 )
          {
            ComponentOfType = 0i64;
            goto LABEL_53;
          }
        }
        goto LABEL_35;
      }
LABEL_34:
      ComponentOfType = 0i64;
      goto LABEL_53;
    }
    if ( (v15 & 0x1000) != 0 )
    {
      v22 = (unsigned int)m_pPointer[1].vfptr;
      v23 = m_pPointer->m_Components.size;
      if ( v22 < v23 )
      {
        v18 = (__int64)&m_pPointer->m_Components.p[v22];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v22;
          v18 += 16i64;
          if ( v22 >= v23 )
          {
            ComponentOfType = 0i64;
            goto LABEL_53;
          }
        }
        goto LABEL_35;
      }
      goto LABEL_34;
    }
    ComponentOfType = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::VehicleOccupantComponent::_TypeUID);
  }
  else
  {
    ComponentOfType = (UFG::VehicleOccupantComponent *)m_pPointer->m_Components.p[30].m_pComponent;
  }
LABEL_53:
  if ( v6 )
    goto LABEL_104;
  if ( !ComponentOfType )
    goto LABEL_82;
  v24 = 0;
  NumberOfOccupants = UFG::VehicleOccupantComponent::GetNumberOfOccupants(ComponentOfType);
  if ( !NumberOfOccupants )
  {
LABEL_80:
    m_pSimComponent = this->m_pActionTreeComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      ActionMostUsedIndex_DismountShoot = UFG::GetActionMostUsedIndex_DismountShoot();
      ActionID_DismountShoot = UFG::GetActionID_DismountShoot();
      IsPlaying = ActionController::IsPlaying(
                    (ActionController *)&m_pSimComponent[3],
                    ActionID_DismountShoot,
                    ActionMostUsedIndex_DismountShoot,
                    1);
      v6 = IsPlaying == 0;
      if ( IsPlaying )
        goto LABEL_82;
    }
    goto LABEL_104;
  }
  while ( 1 )
  {
    Occupant = UFG::VehicleOccupantComponent::GetOccupant(ComponentOfType, v24, 0i64);
    if ( Occupant )
      break;
LABEL_79:
    if ( ++v24 >= NumberOfOccupants )
      goto LABEL_80;
  }
  v27 = Occupant->m_Flags;
  if ( (v27 & 0x4000) == 0 )
  {
    if ( v27 < 0 )
    {
      v28 = Occupant->m_Components.p[6].m_pComponent;
      goto LABEL_77;
    }
    if ( (v27 & 0x2000) != 0 )
    {
      v29 = (unsigned int)Occupant[1].vfptr;
      v30 = Occupant->m_Components.size;
      if ( v29 < v30 )
      {
        v31 = (__int64)&Occupant->m_Components.p[v29];
        while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v29;
          v31 += 16i64;
          if ( v29 >= v30 )
            goto LABEL_67;
        }
LABEL_68:
        v28 = *(UFG::SimComponent **)v31;
        goto LABEL_77;
      }
    }
    else
    {
      if ( (v27 & 0x1000) == 0 )
      {
        v28 = UFG::SimObject::GetComponentOfType(Occupant, UFG::HealthComponent::_TypeUID);
        goto LABEL_77;
      }
      v32 = (unsigned int)Occupant[1].vfptr;
      v33 = Occupant->m_Components.size;
      if ( v32 < v33 )
      {
        v31 = (__int64)&Occupant->m_Components.p[v32];
        while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v32;
          v31 += 16i64;
          if ( v32 >= v33 )
          {
            v28 = 0i64;
            goto LABEL_77;
          }
        }
        goto LABEL_68;
      }
    }
LABEL_67:
    v28 = 0i64;
    goto LABEL_77;
  }
  v28 = Occupant->m_Components.p[6].m_pComponent;
LABEL_77:
  if ( !v28 || BYTE4(v28[1].m_BoundComponentHandles.mNode.mPrev) )
    goto LABEL_79;
  v6 = 0;
LABEL_82:
  UFG::TargetingSystemBaseComponent::FindMatrix(m_pPointer->m_pTransformNodeComponent, m_pPointer, &matSimObject);
  v38 = this->m_pEquippedSOWPC.m_pPointer;
  v39 = this->m_pActiveTargetingProfile;
  v40 = matSimObject.v3.x - this->m_vTargetingPosition.x;
  v41 = matSimObject.v3.y - this->m_vTargetingPosition.y;
  if ( v38 )
  {
    v42 = *(float *)(*((_QWORD *)&v38[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v38[2].m_pSimObject))
                   + 40i64);
    m_fTargetReleaseDistanceSquared = (float)(v42 + v39->m_fTargetReleaseDistancePastMaxDistance)
                                    * (float)(v42 + v39->m_fTargetReleaseDistancePastMaxDistance);
  }
  else
  {
    m_fTargetReleaseDistanceSquared = v39->m_fTargetReleaseDistanceSquared;
  }
  if ( (float)((float)((float)(v41 * v41) + (float)(v40 * v40))
             + (float)((float)(matSimObject.v3.z - this->m_vTargetingPosition.z)
                     * (float)(matSimObject.v3.z - this->m_vTargetingPosition.z))) > m_fTargetReleaseDistanceSquared )
    goto LABEL_104;
  if ( !this->m_pOccupantOfVehicle.m_pPointer || this->m_eFocusMode == eFOCUS_MODE_LOCKED )
  {
    v44 = 0i64;
    v45 = 0;
    while ( 1 )
    {
      if ( v44
        || (m_fIdlePriorityConeTime = m_pActiveTargetingProfile->m_fIdlePriorityConeTime, m_fIdlePriorityConeTime <= 0.0) )
      {
        v48 = m_pActiveTargetingProfile->m_HalfHorizontalFOVs[v44];
      }
      else
      {
        v47 = this->m_fTargetingIntentionIdleTime / m_fIdlePriorityConeTime;
        if ( v47 > 1.0 )
          v47 = *(float *)&FLOAT_1_0;
        v48 = (float)((float)(1.0 - v47) * m_pActiveTargetingProfile->m_HalfHorizontalFOVs[0])
            + (float)(v47 * m_pActiveTargetingProfile->m_fHalfIdlePriorityConeHorizontalFOV);
      }
      x = this->m_vTargetingIntention.x;
      y = this->m_vTargetingIntention.y;
      v1.x = v40;
      v1.z = 0.0;
      v2.z = 0.0;
      v2.x = x;
      v2.y = y;
      v1.y = v41;
      if ( v45 )
      {
        v56[2] = 0x80000000;
        v51 = (UFG::qVector3 *)v56;
        v56[0] = LODWORD(x) ^ _xmm[0];
        v56[1] = LODWORD(y) ^ _xmm[0];
      }
      else
      {
        v51 = &v2;
      }
      if ( UFG::qAngleBetween(&v1, v51) <= v48 )
        break;
      ++v7;
      ++v44;
      v45 = v7 == 4;
      if ( v7 > 4 )
        goto LABEL_104;
    }
    if ( v7 == -1 )
      goto LABEL_104;
  }
  if ( v6 )
  {
LABEL_104:
    v52 = this->m_pTargetingMap->m_Map.p[22];
    if ( v52 )
    {
      v53 = v52;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v53], 0i64);
      v54 = this->m_pTargets;
      if ( v54[v53].m_bLock )
        v54[v53].m_bLock = 0;
    }
    if ( !this->m_pOccupantOfVehicle.m_pPointer && this->m_eFocusMode == eFOCUS_MODE_LOCKED && this->m_bHasRangedWeapon )
    {
      this->m_eDesiredFocusMode = eFOCUS_MODE_FREE_AIMING_LOCKED;
      this->m_eFocusMode = eFOCUS_MODE_FREE_AIMING_LOCKED;
      this->m_vLockedFreeAimInput = this->m_vAimInput;
    }
  }
}

// File Line: 3669
// RVA: 0x5660A0
bool __fastcall UFG::TargetingSystemPedPlayerComponent::cycleTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        int eCycleTargetDirection,
        UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList)
{
  UFG::SimComponent *m_pPointer; // rax
  float m_fFlickTargetingAngularLimitRad; // xmm8_4
  UFG::ScoredTarget *v8; // rax
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  int v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm7_4
  __int64 v13; // rcx
  UFG::TargetingSimObject *m_pTargets; // rax
  void *v15; // rdi
  UFG::TransformNodeComponent *v16; // rbx
  UFG::BaseCameraComponent *v17; // rdi
  float v18; // xmm1_4
  float v19; // xmm4_4
  float v20; // xmm10_4
  float v21; // xmm7_4
  float v22; // xmm9_4
  UFG::qVector4 *v23; // r13
  __int64 size; // r12
  __int64 v25; // rbx
  bool v26; // r8
  UFG::BaseCameraComponent *v27; // rax
  __m128 y_low; // xmm4
  float v29; // xmm2_4
  __m128 v30; // xmm1
  float v31; // xmm3_4
  float v32; // xmm5_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  bool v35; // al
  __int16 v36; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v38; // r8d
  unsigned int v39; // r9d
  __int64 v40; // rdi
  UFG::SimObject *m_pSimObject; // rcx
  bool v42; // di
  double v43; // xmm0_8
  float v44; // xmm2_4
  float v45; // xmm1_4
  bool IsWithinVerticalFOV; // al
  signed int v47; // ecx
  __int64 v48; // rax
  float v49; // xmm2_4
  unsigned __int8 v50; // cl
  bool *bIsKnockedOut; // [rsp+50h] [rbp-78h]
  bool *bIsKnockedOuta; // [rsp+50h] [rbp-78h]
  UFG::eFactionStandingEnum eFactionStanding[2]; // [rsp+58h] [rbp-70h] BYREF
  UFG::qVector3 vMeToTarget; // [rsp+60h] [rbp-68h] BYREF
  float v56; // [rsp+6Ch] [rbp-5Ch]
  __int64 v57; // [rsp+70h] [rbp-58h]
  UFG::qVector3 n2; // [rsp+78h] [rbp-50h] BYREF
  UFG::qFixedArray<UFG::ScoredTarget,100> potentialTargets; // [rsp+88h] [rbp-40h] BYREF
  bool bShouldRejectTarget; // [rsp+778h] [rbp+6B0h] BYREF
  int v61; // [rsp+780h] [rbp+6B8h]
  bool bIsSocialActionAvailable; // [rsp+790h] [rbp+6C8h] BYREF

  v57 = -2i64;
  m_pPointer = this->m_pEquippedSOWPC.m_pPointer;
  if ( m_pPointer )
    m_fFlickTargetingAngularLimitRad = *(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                                  + HIDWORD(m_pPointer[2].m_pSimObject))
                                                + 156i64);
  else
    m_fFlickTargetingAngularLimitRad = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fFlickTargetingAngularLimitRad;
  if ( (unsigned int)(this->m_eFocusMode - 2) <= 2 )
  {
    m_fFlickTargetingAngularLimitRad = UFG::TargetingSystemPedPlayerComponent::ms_fSoftLockFlickAcquisitionConeHalfAngleRad;
    if ( UFG::TargetingSystemPedPlayerComponent::ms_fSoftLockFlickAcquisitionConeHalfAngleRad <= 0.0 )
    {
      LOBYTE(v8) = 0;
      return (char)v8;
    }
  }
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
  v10 = LODWORD(mCurrentCamera->mCamera.mView.v1.z) ^ _xmm[0];
  LODWORD(v11) = LODWORD(mCurrentCamera->mCamera.mView.v1.y) ^ _xmm[0];
  LODWORD(v12) = LODWORD(mCurrentCamera->mCamera.mView.v1.x) ^ _xmm[0];
  vMeToTarget.z = v12;
  v56 = v11;
  LODWORD(v57) = v10;
  v13 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[22];
  m_pTargets = this->m_pTargets;
  if ( m_pTargets[v13].m_pTarget.m_pPointer && m_pTargets[v13].m_bLock )
  {
    v15 = m_pTargets[v13].m_pTarget.m_pPointer;
    bIsKnockedOut = (bool *)v15;
    if ( v15 )
    {
      if ( (unsigned int)(this->m_eFocusMode - 3) > 1 )
      {
        v16 = (UFG::TransformNodeComponent *)*((_QWORD *)v15 + 11);
        if ( v16 )
        {
          v17 = UFG::Director::Get()->mCurrentCamera;
          if ( v17 )
            v17 = (UFG::BaseCameraComponent *)((char *)v17 + 80);
          UFG::TransformNodeComponent::UpdateWorldTransform(v16);
          v11 = v16->mWorldTransform.v3.y - v17->mCamera.mView.v2.y;
          v12 = v16->mWorldTransform.v3.x - v17->mCamera.mView.v2.x;
          v15 = bIsKnockedOut;
        }
      }
    }
  }
  else
  {
    v15 = 0i64;
  }
  v18 = (float)(v12 * v12) + (float)(v11 * v11);
  if ( v18 == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / fsqrt(v18);
  vMeToTarget.z = v12 * v19;
  v56 = v11 * v19;
  *(float *)&v57 = v19 * 0.0;
  v20 = (float)((float)(v11 * v19) * UFG::qVector3::msAxisZ.x) - (float)((float)(v12 * v19) * UFG::qVector3::msAxisZ.y);
  v21 = (float)((float)(v12 * v19) * UFG::qVector3::msAxisZ.z) - (float)(UFG::qVector3::msAxisZ.x * (float)(v19 * 0.0));
  v22 = (float)(UFG::qVector3::msAxisZ.y * (float)(v19 * 0.0)) - (float)((float)(v11 * v19) * UFG::qVector3::msAxisZ.z);
  potentialTargets.size = 0;
  if ( closeTargetsList->size )
  {
    v23 = &closeTargetsList->p[0].m_Xform.v3;
    size = closeTargetsList->size;
    while ( 1 )
    {
      v25 = *(_QWORD *)(*(_QWORD *)&v23[-4].z + 40i64);
      eFactionStanding[0] = FACTIONSTANDING_INDIFFERENT;
      v26 = this->m_bIsInAnyCombat || this->m_bIsAimingActive;
      UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(
        this,
        (UFG::SimObject *)v25,
        v26,
        &bShouldRejectTarget,
        (UFG::SimObject **)&n2,
        (bool *)&vMeToTarget.y,
        (bool *)&vMeToTarget,
        eFactionStanding,
        (bool *)&vMeToTarget.x + 2,
        (bool *)&vMeToTarget.x + 1,
        (bool *)&vMeToTarget.x + 3,
        &bIsSocialActionAvailable);
      if ( bShouldRejectTarget || (void *)v25 == v15 )
        goto LABEL_69;
      v27 = UFG::Director::Get()->mCurrentCamera;
      if ( v27 )
        v27 = (UFG::BaseCameraComponent *)((char *)v27 + 80);
      y_low = (__m128)LODWORD(v23->y);
      y_low.m128_f32[0] = y_low.m128_f32[0] - v27->mCamera.mView.v2.y;
      v29 = v23->x - v27->mCamera.mView.v2.x;
      v30 = y_low;
      v30.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v29 * v29);
      v31 = v30.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
      v32 = v31 * 0.0;
      v33 = v31 * y_low.m128_f32[0];
      v34 = v29 * v31;
      n2.x = v34;
      n2.y = v31 * y_low.m128_f32[0];
      if ( eCycleTargetDirection )
      {
        if ( eCycleTargetDirection != 1 )
          goto LABEL_69;
        v35 = (float)((float)((float)(v33 * v21) + (float)(v34 * v22)) + (float)(v20 * v32)) <= 0.0;
      }
      else
      {
        v35 = (float)((float)((float)(v33 * v21) + (float)(v34 * v22)) + (float)(v20 * v32)) >= 0.0;
      }
      if ( !v35 )
        goto LABEL_69;
      if ( !v25 )
        goto LABEL_58;
      v36 = *(_WORD *)(v25 + 76);
      if ( (v36 & 0x4000) != 0 )
      {
        ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v25 + 104) + 224i64);
      }
      else if ( v36 >= 0 )
      {
        if ( (v36 & 0x2000) != 0 )
        {
          ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v25 + 104) + 144i64);
        }
        else if ( (v36 & 0x1000) != 0 )
        {
          v38 = *(_DWORD *)(v25 + 128);
          v39 = *(_DWORD *)(v25 + 96);
          if ( v38 >= v39 )
          {
LABEL_54:
            ComponentOfType = 0i64;
          }
          else
          {
            v40 = *(_QWORD *)(v25 + 104);
            while ( (*(_DWORD *)(v40 + 16i64 * v38 + 8) & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
                 || (UFG::CompositeDrawableComponent::_TypeUID & ~*(_DWORD *)(v40 + 16i64 * v38 + 8) & 0x1FFFFFF) != 0 )
            {
              if ( ++v38 >= v39 )
                goto LABEL_54;
            }
            ComponentOfType = *(UFG::SimComponent **)(v40 + 16i64 * v38);
          }
        }
        else
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(
                              (UFG::SimObject *)v25,
                              UFG::CompositeDrawableComponent::_TypeUID);
        }
      }
      else
      {
        ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v25 + 104) + 224i64);
      }
      if ( ComponentOfType )
        m_pSimObject = ComponentOfType[19].m_pSimObject;
      else
LABEL_58:
        m_pSimObject = 0i64;
      v42 = !m_pSimObject || LOBYTE(m_pSimObject->vfptr) <= 1u;
      v43 = UFG::qAngleBetweenNormals((UFG::qVector3 *)&vMeToTarget.z, &n2);
      if ( !v42 && m_fFlickTargetingAngularLimitRad < *(float *)&v43 )
        goto LABEL_69;
      v44 = v23->z - this->m_vTargetingPosition.z;
      v45 = v23->y - this->m_vTargetingPosition.y;
      vMeToTarget.x = v23->x - this->m_vTargetingPosition.x;
      vMeToTarget.y = v45;
      vMeToTarget.z = v44;
      IsWithinVerticalFOV = UFG::TargetingSystemPedBaseComponent::IsWithinVerticalFOV(
                              this,
                              &vMeToTarget,
                              this->m_pActiveTargetingProfile->m_fHalfVerticalFOV,
                              this->m_pActiveTargetingProfile->m_fExtraPositivePitch,
                              this->m_pActiveTargetingProfile->m_fExtraNegativePitch);
      if ( !v42 && !IsWithinVerticalFOV )
        goto LABEL_69;
      if ( UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(
             this,
             &this->m_vTargetingPosition,
             (UFG::SimObject *)v25,
             (UFG::qMatrix44 *)&v23[-3],
             0,
             0) < 0.0 )
        goto LABEL_69;
      v47 = potentialTargets.size;
      if ( potentialTargets.size < 0x64 )
        break;
LABEL_70:
      v23 += 5;
      --size;
      v15 = bIsKnockedOuta;
      eCycleTargetDirection = v61;
      if ( !size )
        goto LABEL_73;
    }
    v48 = potentialTargets.size++;
    v49 = (float)((float)(n2.x * vMeToTarget.z) + (float)(n2.y * v56)) + (float)((float)(v31 * 0.0) * *(float *)&v57);
    potentialTargets.p[v48].m_pSimObject = (UFG::SimObject *)v25;
    potentialTargets.p[v48].m_fScore = v49;
LABEL_69:
    v47 = potentialTargets.size;
    goto LABEL_70;
  }
  v47 = potentialTargets.size;
LABEL_73:
  UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
    (ClassTypeDescriptor *)potentialTargets.p,
    (ClassTypeDescriptor *)&n2.z + v47,
    (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::BiggerScoresAreBetter);
  v8 = UFG::TargetingSystemPedPlayerComponent::chooseBestVisibleTarget(
         this,
         &potentialTargets,
         UFG::TargetingSystemPedPlayerComponent::ms_MaxRaycastsBeforeGiveUpForCycle);
  if ( v8 )
  {
    v50 = this->m_pTargetingMap->m_Map.p[22];
    if ( v50 )
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v50], v8->m_pSimObject);
    LOBYTE(v8) = 1;
  }
  return (char)v8;
}

// File Line: 3883
// RVA: 0x566700
char __fastcall UFG::TargetingSystemPedPlayerComponent::cycleTargetManual(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList)
{
  UFG::SimObject *m_pPointer; // r15
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  int mPrev; // eax
  UFG::InputActionData *v7; // rcx
  float v8; // xmm11_4
  int v9; // xmm10_4
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  int v11; // xmm2_4
  int v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  __m128 v15; // xmm1
  float v16; // xmm7_4
  __m128 v17; // xmm8
  float v18; // xmm6_4
  UFG::BaseCameraComponent *v19; // rax
  float mFarBlurRadius; // xmm3_4
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  float v23; // xmm2_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  __m128 v26; // xmm2
  float v27; // xmm1_4
  float x; // xmm12_4
  float y; // xmm13_4
  float z; // xmm14_4
  float v31; // xmm8_4
  __int64 size; // r8
  unsigned int v33; // r9d
  __int64 v34; // rax
  float *p_y; // rcx
  unsigned int v36; // eax
  __int64 v37; // rdx
  float v38; // xmm2_4
  float v39; // xmm2_4
  float v40; // xmm2_4
  float v41; // xmm2_4
  float *v42; // rcx
  __int64 v43; // rdx
  float v44; // xmm2_4
  UFG::qVector4 *v45; // rdi
  __int64 v46; // rsi
  __int64 v47; // rbx
  __m128 y_low; // xmm4
  float v49; // xmm2_4
  __m128 v50; // xmm1
  float v51; // xmm3_4
  float v52; // xmm10_4
  __int16 v53; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v55; // r8d
  unsigned int v56; // r10d
  __int64 v57; // r11
  UFG::SimObject *m_pSimObject; // rcx
  float v59; // xmm7_4
  float v60; // xmm6_4
  float v61; // xmm11_4
  float v62; // xmm11_4
  float v63; // xmm0_4
  __int64 mfnInPlaceNew_low; // rax
  UFG::ScoredTarget *v65; // rax
  unsigned __int8 v66; // cl
  UFG::qVector3 n2; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qVector3 vMeToTarget; // [rsp+40h] [rbp-A8h] BYREF
  UFG::qVector3 n1; // [rsp+50h] [rbp-98h] BYREF
  __int64 v71; // [rsp+60h] [rbp-88h]
  ClassTypeDescriptor right; // [rsp+68h] [rbp-80h] BYREF
  ClassTypeDescriptor left[110]; // [rsp+78h] [rbp-70h] BYREF

  v71 = -2i64;
  m_pPointer = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0;
  mPrev = 0;
  if ( this->m_pAICharacterControllerComponent.m_pSimComponent )
    mPrev = (int)this->m_pAICharacterControllerComponent.m_pSimComponent[17].m_SafePointerList.mNode.mPrev;
  v7 = UFG::ActionDef_TargetCycle.mDataPerController[mPrev];
  if ( !v7 || !v7->mActionTrue )
    return 0;
  v8 = v7->mAxisRawX[0];
  v9 = LODWORD(v7->mAxisRawY[0]) ^ _xmm[0];
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
  v11 = LODWORD(mCurrentCamera->mCamera.mView.v1.y) ^ _xmm[0];
  v12 = LODWORD(mCurrentCamera->mCamera.mView.v1.x) ^ _xmm[0];
  v13 = (float)(*(float *)&v11 * *(float *)&v11) + (float)(*(float *)&v12 * *(float *)&v12);
  if ( v13 == 0.0 )
  {
    v15 = 0i64;
  }
  else
  {
    v14 = fsqrt(v13);
    v15 = (__m128)(unsigned int)FLOAT_1_0;
    v15.m128_f32[0] = 1.0 / v14;
  }
  v16 = v15.m128_f32[0] * 0.0;
  v17 = v15;
  v17.m128_f32[0] = v15.m128_f32[0] * *(float *)&v11;
  v18 = *(float *)&v12 * v15.m128_f32[0];
  v19 = UFG::Director::Get()->mCurrentCamera;
  if ( v19 )
    v19 = (UFG::BaseCameraComponent *)((char *)v19 + 80);
  mFarBlurRadius = v19->mCamera.mDepthOfFieldFocus.mFarBlurRadius;
  v21 = (__m128)*((unsigned int *)&v19->mCamera.mDepthOfFieldFocus + 6);
  v22 = v21;
  v22.m128_f32[0] = (float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(mFarBlurRadius * mFarBlurRadius);
  if ( v22.m128_f32[0] == 0.0 )
    v23 = 0.0;
  else
    v23 = 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
  v24 = (float)(v16 * *(float *)&v9) + (float)((float)(v23 * 0.0) * v8);
  v17.m128_f32[0] = (float)(v17.m128_f32[0] * *(float *)&v9) + (float)((float)(v23 * v21.m128_f32[0]) * v8);
  v25 = (float)(v18 * *(float *)&v9) + (float)((float)(v23 * mFarBlurRadius) * v8);
  v26 = v17;
  v26.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v25 * v25)) + (float)(v24 * v24);
  if ( v26.m128_f32[0] == 0.0 )
    v27 = 0.0;
  else
    v27 = 1.0 / _mm_sqrt_ps(v26).m128_f32[0];
  n2.x = v25 * v27;
  n2.y = v17.m128_f32[0] * v27;
  n2.z = v24 * v27;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  LODWORD(right.mfnInPlaceNew) = 0;
  v31 = 0.0;
  size = closeTargetsList->size;
  v33 = 0;
  v34 = 0i64;
  if ( (int)size >= 4 )
  {
    p_y = &closeTargetsList->p[3].m_Xform.v3.y;
    v36 = ((unsigned int)(size - 4) >> 2) + 1;
    v37 = v36;
    v33 = 4 * v36;
    v34 = 4i64 * v36;
    do
    {
      v38 = (float)((float)((float)(*(p_y - 60) - y) * (float)(*(p_y - 60) - y))
                  + (float)((float)(*(p_y - 61) - x) * (float)(*(p_y - 61) - x)))
          + (float)((float)(*(p_y - 59) - z) * (float)(*(p_y - 59) - z));
      if ( v38 > v31 )
      {
        if ( v38 <= 0.0 )
        {
          v31 = 0.0;
        }
        else
        {
          v31 = (float)((float)((float)(*(p_y - 60) - y) * (float)(*(p_y - 60) - y))
                      + (float)((float)(*(p_y - 61) - x) * (float)(*(p_y - 61) - x)))
              + (float)((float)(*(p_y - 59) - z) * (float)(*(p_y - 59) - z));
          if ( v38 >= 100.0 )
            v31 = FLOAT_100_0;
        }
      }
      v39 = (float)((float)((float)(*(p_y - 40) - y) * (float)(*(p_y - 40) - y))
                  + (float)((float)(*(p_y - 41) - x) * (float)(*(p_y - 41) - x)))
          + (float)((float)(*(p_y - 39) - z) * (float)(*(p_y - 39) - z));
      if ( v39 > v31 )
      {
        if ( v39 <= 0.0 )
        {
          v31 = 0.0;
        }
        else
        {
          v31 = (float)((float)((float)(*(p_y - 40) - y) * (float)(*(p_y - 40) - y))
                      + (float)((float)(*(p_y - 41) - x) * (float)(*(p_y - 41) - x)))
              + (float)((float)(*(p_y - 39) - z) * (float)(*(p_y - 39) - z));
          if ( v39 >= 100.0 )
            v31 = FLOAT_100_0;
        }
      }
      v40 = (float)((float)((float)(*(p_y - 20) - y) * (float)(*(p_y - 20) - y))
                  + (float)((float)(*(p_y - 21) - x) * (float)(*(p_y - 21) - x)))
          + (float)((float)(*(p_y - 19) - z) * (float)(*(p_y - 19) - z));
      if ( v40 > v31 )
      {
        if ( v40 <= 0.0 )
        {
          v31 = 0.0;
        }
        else
        {
          v31 = (float)((float)((float)(*(p_y - 20) - y) * (float)(*(p_y - 20) - y))
                      + (float)((float)(*(p_y - 21) - x) * (float)(*(p_y - 21) - x)))
              + (float)((float)(*(p_y - 19) - z) * (float)(*(p_y - 19) - z));
          if ( v40 >= 100.0 )
            v31 = FLOAT_100_0;
        }
      }
      v41 = (float)((float)((float)(*p_y - y) * (float)(*p_y - y))
                  + (float)((float)(*(p_y - 1) - x) * (float)(*(p_y - 1) - x)))
          + (float)((float)(p_y[1] - z) * (float)(p_y[1] - z));
      if ( v41 > v31 )
      {
        if ( v41 <= 0.0 )
        {
          v31 = 0.0;
        }
        else
        {
          v31 = (float)((float)((float)(*p_y - y) * (float)(*p_y - y))
                      + (float)((float)(*(p_y - 1) - x) * (float)(*(p_y - 1) - x)))
              + (float)((float)(p_y[1] - z) * (float)(p_y[1] - z));
          if ( v41 >= 100.0 )
            v31 = FLOAT_100_0;
        }
      }
      p_y += 80;
      --v37;
    }
    while ( v37 );
  }
  if ( v33 < (unsigned int)size )
  {
    v42 = &closeTargetsList->p[v34].m_Xform.v3.y;
    v43 = (unsigned int)size - v33;
    do
    {
      v44 = (float)((float)((float)(*v42 - y) * (float)(*v42 - y))
                  + (float)((float)(*(v42 - 1) - x) * (float)(*(v42 - 1) - x)))
          + (float)((float)(v42[1] - z) * (float)(v42[1] - z));
      if ( v44 > v31 )
      {
        if ( v44 <= 0.0 )
        {
          v31 = 0.0;
        }
        else
        {
          v31 = (float)((float)((float)(*v42 - y) * (float)(*v42 - y))
                      + (float)((float)(*(v42 - 1) - x) * (float)(*(v42 - 1) - x)))
              + (float)((float)(v42[1] - z) * (float)(v42[1] - z));
          if ( v44 >= 100.0 )
            v31 = FLOAT_100_0;
        }
      }
      v42 += 20;
      --v43;
    }
    while ( v43 );
  }
  if ( (_DWORD)size )
  {
    v45 = &closeTargetsList->p[0].m_Xform.v3;
    v46 = size;
    do
    {
      v47 = *(_QWORD *)(*(_QWORD *)&v45[-4].z + 40i64);
      if ( (UFG::SimObject *)v47 != m_pPointer )
      {
        y_low = (__m128)LODWORD(v45->y);
        y_low.m128_f32[0] = y_low.m128_f32[0] - y;
        v49 = v45->x - x;
        v50 = y_low;
        v50.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v49 * v49);
        v51 = v50.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v50).m128_f32[0];
        n1.x = v49 * v51;
        n1.y = v51 * y_low.m128_f32[0];
        n1.z = v51 * 0.0;
        v52 = (float)((float)((float)(v51 * y_low.m128_f32[0]) * n2.y) + (float)((float)(v49 * v51) * n2.x))
            + (float)(n2.z * (float)(v51 * 0.0));
        if ( v52 > 0.0 )
        {
          if ( !v47 )
            goto LABEL_77;
          v53 = *(_WORD *)(v47 + 76);
          if ( (v53 & 0x4000) != 0 )
          {
            ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v47 + 104) + 224i64);
          }
          else if ( v53 >= 0 )
          {
            if ( (v53 & 0x2000) != 0 )
            {
              ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v47 + 104) + 144i64);
            }
            else if ( (v53 & 0x1000) != 0 )
            {
              v55 = *(_DWORD *)(v47 + 128);
              v56 = *(_DWORD *)(v47 + 96);
              if ( v55 >= v56 )
              {
LABEL_73:
                ComponentOfType = 0i64;
              }
              else
              {
                v57 = *(_QWORD *)(v47 + 104);
                while ( (*(_DWORD *)(v57 + 16i64 * v55 + 8) & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
                     || (UFG::CompositeDrawableComponent::_TypeUID & ~*(_DWORD *)(v57 + 16i64 * v55 + 8) & 0x1FFFFFF) != 0 )
                {
                  if ( ++v55 >= v56 )
                    goto LABEL_73;
                }
                ComponentOfType = *(UFG::SimComponent **)(v57 + 16i64 * v55);
              }
            }
            else
            {
              ComponentOfType = UFG::SimObject::GetComponentOfType(
                                  (UFG::SimObject *)v47,
                                  UFG::CompositeDrawableComponent::_TypeUID);
            }
          }
          else
          {
            ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v47 + 104) + 224i64);
          }
          if ( ComponentOfType )
            m_pSimObject = ComponentOfType[19].m_pSimObject;
          else
LABEL_77:
            m_pSimObject = 0i64;
          if ( !m_pSimObject || LOBYTE(m_pSimObject->vfptr) <= 1u )
          {
            v59 = v45->z - z;
            v60 = v45->y - y;
            vMeToTarget.x = v45->x - x;
            v61 = vMeToTarget.x;
            vMeToTarget.y = v60;
            vMeToTarget.z = v59;
            UFG::TargetingSystemPedBaseComponent::IsWithinVerticalFOV(
              this,
              &vMeToTarget,
              this->m_pActiveTargetingProfile->m_fHalfVerticalFOV,
              this->m_pActiveTargetingProfile->m_fExtraPositivePitch,
              this->m_pActiveTargetingProfile->m_fExtraNegativePitch);
            UFG::qAngleBetweenNormals(&n1, &n2);
            v62 = (float)((float)(v61 * v61) + (float)(v60 * v60)) + (float)(v59 * v59);
            if ( UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(
                   this,
                   &this->m_vTargetingPosition,
                   *(UFG::SimObject **)(*(_QWORD *)&v45[-4].z + 40i64),
                   (UFG::qMatrix44 *)&v45[-3],
                   0,
                   0) >= 0.0 )
            {
              v63 = (float)((float)(1.0 - (float)(v62 / v31))
                          * UFG::TargetingSystemPedPlayerComponent::ms_fTargetRelativeMeleeCyclingDistanceScale)
                  + (float)(v52 * UFG::TargetingSystemPedPlayerComponent::ms_fTargetRelativeMeleeCyclingAngleScale);
              if ( LODWORD(right.mfnInPlaceNew) < 0x64 )
              {
                mfnInPlaceNew_low = LODWORD(right.mfnInPlaceNew);
                ++LODWORD(right.mfnInPlaceNew);
                *((_QWORD *)&right.mUID + mfnInPlaceNew_low * 2) = v47;
                *(float *)&left[mfnInPlaceNew_low].mUID = v63;
              }
            }
          }
        }
      }
      v45 += 5;
      --v46;
    }
    while ( v46 );
  }
  UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
    left,
    &right + SLODWORD(right.mfnInPlaceNew),
    (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::BiggerScoresAreBetter);
  v65 = UFG::TargetingSystemPedPlayerComponent::chooseBestVisibleTarget(
          this,
          (UFG::qFixedArray<UFG::ScoredTarget,100> *)&right.mfnInPlaceNew,
          UFG::TargetingSystemPedPlayerComponent::ms_MaxRaycastsBeforeGiveUpForCycle);
  if ( !v65 )
  {
    LODWORD(right.mfnInPlaceNew) = 0;
    return 0;
  }
  v66 = this->m_pTargetingMap->m_Map.p[22];
  if ( v66 )
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v66], v65->m_pSimObject);
  LODWORD(right.mfnInPlaceNew) = 0;
  return 1;
}

// File Line: 4042
// RVA: 0x564810
float __fastcall UFG::TargetingSystemPedPlayerComponent::calculateScore(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::eConeEnum eCone,
        const float fDistanceToTargetSquared,
        const float fMaxDistanceToTargetSquared,
        unsigned int fHorizontalAngularDiff,
        bool bIsAlreadyTargeted,
        bool bIsDowned,
        bool bIsKnockedOut,
        UFG::eFactionStandingEnum eFactionStanding,
        bool bIsScripted,
        bool bIsOnVehicle,
        bool bIsTargetVehicle,
        bool bTargetVehicleHasOccupant,
        bool bIsSocialActionAvailable)
{
  double v16; // xmm1_8
  float v17; // xmm8_4
  float Value; // xmm0_4
  double v19; // xmm1_8
  float v20; // xmm7_4
  float v21; // xmm7_4
  float v22; // xmm7_4
  float v23; // xmm0_4

  if ( (unsigned int)(eCone - 3) <= 1 && eFactionStanding != FACTIONSTANDING_HOSTILE && !bIsSocialActionAvailable )
    return FLOAT_N1_0;
  *(_QWORD *)&v16 = (unsigned int)FLOAT_1_0;
  v17 = (float)eCone;
  *(float *)&v16 = 1.0 - (float)(fDistanceToTargetSquared / fMaxDistanceToTargetSquared);
  Value = UFG::LinearTable<float>::GetValue(&UFG::TargetingSystemPedBaseComponent::ms_CloseToTargetTable, v16);
  *(_QWORD *)&v19 = fHorizontalAngularDiff;
  *(float *)&v19 = *(float *)&fHorizontalAngularDiff * 0.31830987;
  v20 = (float)(1.0 - Value) * UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias;
  v21 = v20
      + (float)(UFG::LinearTable<float>::GetValue(&UFG::TargetingSystemPedBaseComponent::ms_CloseToCenterTable, v19)
              * (float)(1.0 - UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias));
  if ( bIsAlreadyTargeted )
    v21 = v21 - UFG::TargetingSystemPedPlayerComponent::ms_fCurrentTargetBonus;
  if ( bIsDowned )
  {
    v22 = (float)(v21 * 0.10000002) + 0.89999998;
  }
  else if ( eFactionStanding == FACTIONSTANDING_HOSTILE )
  {
    v22 = v21 * 0.5;
  }
  else if ( bIsSocialActionAvailable )
  {
    v22 = (float)(v21 * 0.10000002) + 0.5;
  }
  else
  {
    v22 = (float)(v21 * 0.29999995) + 0.60000002;
    if ( bIsScripted && s_bUseScriptedCheck )
      v22 = v22 * s_fScriptedModifierBonus;
  }
  if ( v22 <= 0.0 )
  {
    v22 = 0.0;
    goto LABEL_20;
  }
  v23 = FLOAT_0_99900001;
  if ( v22 < 0.99900001 )
LABEL_20:
    v23 = v22;
  if ( eCone )
  {
    if ( bIsDowned )
      v17 = FLOAT_5_0;
    if ( eFactionStanding != FACTIONSTANDING_HOSTILE )
      v17 = v17 + 1.0;
  }
  if ( bIsKnockedOut )
    v17 = v17 + 10.0;
  if ( bIsOnVehicle )
  {
    if ( bIsTargetVehicle )
    {
      if ( !bTargetVehicleHasOccupant )
        return v23 + (float)(v17 + 10.0);
    }
    else
    {
      v17 = v17 + 5.0;
    }
  }
  return v23 + v17;
}

// File Line: 4172
// RVA: 0x56A9B0
bool __fastcall UFG::TargetingSystemPedPlayerComponent::isCommonInvalidTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::SimObject *pSimObject)
{
  bool result; // al
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v6; // rcx
  UFG::SimObject *m_pPointer; // rax

  result = 1;
  if ( pSimObject != this->m_pOccupantOfVehicle.m_pPointer
    && ((pSimObject->m_Flags & 0x4000) == 0
     || !pSimObject->m_Components.p[44].m_pComponent
     && !UFG::TargetingSystemPedBaseComponent::isAlliedToMe(this, pSimObject)) )
  {
    m_pTargets = this->m_pTargets;
    v6 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[23];
    if ( !m_pTargets[v6].m_pTarget.m_pPointer )
      return 0;
    if ( !m_pTargets[v6].m_bLock )
      return 0;
    m_pPointer = m_pTargets[v6].m_pTarget.m_pPointer;
    if ( !m_pPointer || pSimObject != m_pPointer )
      return 0;
  }
  return result;
}

// File Line: 4221
// RVA: 0x568800
void __fastcall UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::SimObject *pSimObject,
        bool bRejectIfNotHostile,
        bool *bShouldRejectTarget,
        UFG::SimObject **pPedTarget,
        bool *bIsTargetVehicle,
        bool *bTargetVehicleHasOccupant,
        UFG::eFactionStandingEnum *eFactionStanding,
        bool *bIsDowned,
        bool *bIsScripted,
        bool *bIsKnockedOut,
        bool *bIsSocialActionAvailable)
{
  bool v12; // bp
  bool *v13; // rdi
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v19; // rdx
  int mNext; // ecx
  bool v21; // al
  UFG::HealthComponent *v22; // r14
  UFG::SimObject *v23; // rcx
  __int16 v24; // dx
  unsigned int v25; // r8d
  unsigned int v26; // r9d
  __int64 v27; // rdx
  UFG::VehicleOccupantComponent *ComponentOfType; // rsi
  unsigned int v29; // r8d
  unsigned int v30; // r9d
  unsigned int v31; // r8d
  unsigned int v32; // r9d
  unsigned int v33; // edi
  unsigned int NumberOfOccupants; // ebp
  UFG::SimObject *Occupant; // rax
  UFG::SimObject *v36; // rbx
  __int16 v37; // dx
  UFG::SimComponent *v38; // rax
  unsigned int v39; // r8d
  unsigned int v40; // r9d
  __int64 v41; // rdx
  unsigned int v42; // r8d
  unsigned int v43; // r9d
  __int16 v44; // dx
  unsigned int v45; // r8d
  unsigned int v46; // r9d
  __int64 v47; // rdx
  unsigned int v48; // r8d
  unsigned int v49; // r9d
  UFG::eFactionStandingEnum TargetingStandingToMe; // eax
  UFG::SimObject *v51; // rcx
  UFG::ActionTreeComponent *v52; // rax
  __int16 v53; // dx
  unsigned int v54; // r8d
  unsigned int v55; // r9d
  __int64 v56; // rdx
  bool v57; // di
  bool v58; // cl
  UFG::SimObject *v59; // rcx
  __int16 v60; // dx
  UFG::FaceActionComponent *v61; // rbx
  unsigned int v62; // r8d
  unsigned int v63; // r9d
  __int64 v64; // rdx
  unsigned int v65; // r8d
  unsigned int v66; // r9d
  unsigned int v67; // r8d
  unsigned int v68; // r9d
  UFG::SimObject *m_pSimObject; // rax

  v12 = bRejectIfNotHostile;
  *bShouldRejectTarget = 0;
  v13 = bShouldRejectTarget;
  *pPedTarget = pSimObject;
  if ( !pSimObject )
    goto LABEL_22;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = pSimObject->m_Components.p[3].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = pSimObject->m_Components.p[4].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)pSimObject[1].vfptr;
      size = pSimObject->m_Components.size;
      if ( vfptr >= size )
      {
LABEL_14:
        m_pComponent = 0i64;
      }
      else
      {
        v19 = &pSimObject->m_Components.p[vfptr];
        while ( (v19->m_TypeUID & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectPropertiesComponent::_TypeUID & ~v19->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          ++v19;
          if ( vfptr >= size )
            goto LABEL_14;
        }
        m_pComponent = v19->m_pComponent;
      }
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(pSimObject, UFG::SimObjectPropertiesComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = pSimObject->m_Components.p[3].m_pComponent;
  }
  if ( !m_pComponent )
    goto LABEL_22;
  mNext = (int)m_pComponent[1].m_SafePointerList.mNode.mNext;
  if ( mNext == 5 )
  {
    *v13 = 1;
    return;
  }
  if ( mNext == 4 )
    v21 = 1;
  else
LABEL_22:
    v21 = 0;
  *bIsTargetVehicle = v21;
  v22 = 0i64;
  *bTargetVehicleHasOccupant = 0;
  v23 = *pPedTarget;
  if ( *bIsTargetVehicle )
  {
    if ( !v23 )
      goto LABEL_78;
    v24 = v23->m_Flags;
    if ( (v24 & 0x4000) != 0 )
    {
      v25 = (unsigned int)v23[1].vfptr;
      v26 = v23->m_Components.size;
      if ( v25 < v26 )
      {
        v27 = (__int64)&v23->m_Components.p[v25];
        while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v25;
          v27 += 16i64;
          if ( v25 >= v26 )
            goto LABEL_31;
        }
LABEL_32:
        ComponentOfType = *(UFG::VehicleOccupantComponent **)v27;
        goto LABEL_50;
      }
      goto LABEL_31;
    }
    if ( v24 >= 0 )
    {
      if ( (v24 & 0x2000) != 0 )
      {
        v29 = (unsigned int)v23[1].vfptr;
        v30 = v23->m_Components.size;
        if ( v29 < v30 )
        {
          v27 = (__int64)&v23->m_Components.p[v29];
          while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
               || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v29;
            v27 += 16i64;
            if ( v29 >= v30 )
            {
              ComponentOfType = 0i64;
              goto LABEL_50;
            }
          }
          goto LABEL_32;
        }
LABEL_31:
        ComponentOfType = 0i64;
        goto LABEL_50;
      }
      if ( (v24 & 0x1000) != 0 )
      {
        v31 = (unsigned int)v23[1].vfptr;
        v32 = v23->m_Components.size;
        if ( v31 < v32 )
        {
          v27 = (__int64)&v23->m_Components.p[v31];
          while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
               || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v31;
            v27 += 16i64;
            if ( v31 >= v32 )
            {
              ComponentOfType = 0i64;
              goto LABEL_50;
            }
          }
          goto LABEL_32;
        }
        goto LABEL_31;
      }
      ComponentOfType = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                           v23,
                                                           UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::VehicleOccupantComponent *)v23->m_Components.p[30].m_pComponent;
    }
LABEL_50:
    if ( ComponentOfType )
    {
      v33 = 0;
      NumberOfOccupants = UFG::VehicleOccupantComponent::GetNumberOfOccupants(ComponentOfType);
      if ( NumberOfOccupants )
      {
        do
        {
          Occupant = UFG::VehicleOccupantComponent::GetOccupant(ComponentOfType, v33, 0i64);
          v36 = Occupant;
          if ( !Occupant )
            goto LABEL_75;
          v37 = Occupant->m_Flags;
          if ( (v37 & 0x4000) != 0 )
          {
            v38 = Occupant->m_Components.p[6].m_pComponent;
          }
          else if ( v37 >= 0 )
          {
            if ( (v37 & 0x2000) != 0 )
            {
              v39 = (unsigned int)Occupant[1].vfptr;
              v40 = Occupant->m_Components.size;
              if ( v39 < v40 )
              {
                v41 = (__int64)&Occupant->m_Components.p[v39];
                while ( (*(_DWORD *)(v41 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                     || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v41 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v39;
                  v41 += 16i64;
                  if ( v39 >= v40 )
                    goto LABEL_63;
                }
LABEL_64:
                v38 = *(UFG::SimComponent **)v41;
                goto LABEL_73;
              }
            }
            else
            {
              if ( (v37 & 0x1000) == 0 )
              {
                v38 = UFG::SimObject::GetComponentOfType(Occupant, UFG::HealthComponent::_TypeUID);
                goto LABEL_73;
              }
              v42 = (unsigned int)Occupant[1].vfptr;
              v43 = Occupant->m_Components.size;
              if ( v42 < v43 )
              {
                v41 = (__int64)&Occupant->m_Components.p[v42];
                while ( (*(_DWORD *)(v41 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                     || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v41 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v42;
                  v41 += 16i64;
                  if ( v42 >= v43 )
                  {
                    v38 = 0i64;
                    goto LABEL_73;
                  }
                }
                goto LABEL_64;
              }
            }
LABEL_63:
            v38 = 0i64;
          }
          else
          {
            v38 = Occupant->m_Components.p[6].m_pComponent;
          }
LABEL_73:
          if ( v38 && !BYTE4(v38[1].m_BoundComponentHandles.mNode.mPrev) )
          {
            *pPedTarget = v36;
            *bTargetVehicleHasOccupant = 1;
            goto LABEL_102;
          }
LABEL_75:
          ++v33;
        }
        while ( v33 < NumberOfOccupants );
      }
      v12 = bRejectIfNotHostile;
      v13 = bShouldRejectTarget;
    }
    if ( !*bTargetVehicleHasOccupant )
    {
LABEL_78:
      if ( v12 )
      {
        *pPedTarget = 0i64;
        *v13 = 1;
        return;
      }
      goto LABEL_103;
    }
    goto LABEL_103;
  }
  if ( !v23 )
    goto LABEL_103;
  v44 = v23->m_Flags;
  if ( (v44 & 0x4000) != 0 )
  {
    v22 = (UFG::HealthComponent *)v23->m_Components.p[6].m_pComponent;
    goto LABEL_103;
  }
  if ( v44 < 0 )
  {
    v22 = (UFG::HealthComponent *)v23->m_Components.p[6].m_pComponent;
    goto LABEL_103;
  }
  if ( (v44 & 0x2000) != 0 )
  {
    v45 = (unsigned int)v23[1].vfptr;
    v46 = v23->m_Components.size;
    if ( v45 >= v46 )
      goto LABEL_103;
    v47 = (__int64)&v23->m_Components.p[v45];
    while ( (*(_DWORD *)(v47 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
         || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v47 + 8) & 0x1FFFFFF) != 0 )
    {
      ++v45;
      v47 += 16i64;
      if ( v45 >= v46 )
        goto LABEL_103;
    }
LABEL_93:
    v22 = *(UFG::HealthComponent **)v47;
    goto LABEL_103;
  }
  if ( (v44 & 0x1000) == 0 )
  {
    v38 = UFG::SimObject::GetComponentOfType(v23, UFG::HealthComponent::_TypeUID);
LABEL_102:
    v22 = (UFG::HealthComponent *)v38;
    goto LABEL_103;
  }
  v48 = (unsigned int)v23[1].vfptr;
  v49 = v23->m_Components.size;
  if ( v48 < v49 )
  {
    v47 = (__int64)&v23->m_Components.p[v48];
    while ( (*(_DWORD *)(v47 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
         || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v47 + 8) & 0x1FFFFFF) != 0 )
    {
      ++v48;
      v47 += 16i64;
      if ( v48 >= v49 )
        goto LABEL_103;
    }
    goto LABEL_93;
  }
LABEL_103:
  TargetingStandingToMe = (unsigned int)UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(
                                          this,
                                          *pPedTarget);
  *eFactionStanding = TargetingStandingToMe;
  if ( bRejectIfNotHostile && TargetingStandingToMe != FACTIONSTANDING_HOSTILE
    || *bIsTargetVehicle && !this->m_bHasRangedWeapon )
  {
LABEL_129:
    *bShouldRejectTarget = 1;
    return;
  }
  v51 = *pPedTarget;
  if ( !*pPedTarget )
    goto LABEL_108;
  v53 = v51->m_Flags;
  if ( (v53 & 0x4000) != 0 )
  {
    v52 = (UFG::ActionTreeComponent *)v51->m_Components.p[7].m_pComponent;
    goto LABEL_124;
  }
  if ( v53 < 0 )
  {
    v52 = (UFG::ActionTreeComponent *)v51->m_Components.p[7].m_pComponent;
    goto LABEL_124;
  }
  if ( (v53 & 0x2000) != 0 )
  {
    v52 = (UFG::ActionTreeComponent *)v51->m_Components.p[6].m_pComponent;
    goto LABEL_124;
  }
  if ( (v53 & 0x1000) == 0 )
  {
    v52 = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(v51, UFG::ActionTreeComponent::_TypeUID);
    goto LABEL_124;
  }
  v54 = (unsigned int)v51[1].vfptr;
  v55 = v51->m_Components.size;
  if ( v54 < v55 )
  {
    v56 = (__int64)&v51->m_Components.p[v54];
    while ( (*(_DWORD *)(v56 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
         || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v56 + 8) & 0x1FFFFFF) != 0 )
    {
      ++v54;
      v56 += 16i64;
      if ( v54 >= v55 )
      {
        v52 = 0i64;
        goto LABEL_124;
      }
    }
    v52 = *(UFG::ActionTreeComponent **)v56;
  }
  else
  {
LABEL_108:
    v52 = 0i64;
  }
LABEL_124:
  *bIsDowned = UFG::IsDowned(v52, v22);
  *bIsScripted = UFG::TargetingSystemPedBaseComponent::isScripted(*pPedTarget);
  if ( v22 && v22->m_bIsKnockedOut )
  {
    v57 = 1;
    v58 = 1;
  }
  else
  {
    v58 = 0;
    v57 = 1;
  }
  *bIsKnockedOut = v58;
  if ( v58 )
    goto LABEL_129;
  v59 = *pPedTarget;
  if ( *pPedTarget )
  {
    v60 = v59->m_Flags;
    if ( (v60 & 0x4000) != 0 )
    {
      v61 = (UFG::FaceActionComponent *)v59->m_Components.p[45].m_pComponent;
      goto LABEL_156;
    }
    if ( v60 >= 0 )
    {
      if ( (v60 & 0x2000) != 0 )
      {
        v65 = (unsigned int)v59[1].vfptr;
        v66 = v59->m_Components.size;
        if ( v65 < v66 )
        {
          v64 = (__int64)&v59->m_Components.p[v65];
          while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
               || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v65;
            v64 += 16i64;
            if ( v65 >= v66 )
            {
              v61 = 0i64;
              goto LABEL_156;
            }
          }
          goto LABEL_140;
        }
      }
      else
      {
        if ( (v60 & 0x1000) == 0 )
        {
          v61 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(v59, UFG::FaceActionComponent::_TypeUID);
LABEL_156:
          if ( v61 )
          {
            if ( UFG::FaceActionComponent::IsFaceActionEnabled(v61) )
            {
              m_pSimObject = v61->m_pSimObject;
              if ( (!m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0) && v61->mFaceActionSetup )
                goto LABEL_162;
            }
          }
          goto LABEL_161;
        }
        v67 = (unsigned int)v59[1].vfptr;
        v68 = v59->m_Components.size;
        if ( v67 < v68 )
        {
          v64 = (__int64)&v59->m_Components.p[v67];
          while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
               || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v67;
            v64 += 16i64;
            if ( v67 >= v68 )
            {
              v61 = 0i64;
              goto LABEL_156;
            }
          }
          goto LABEL_140;
        }
      }
    }
    else
    {
      v62 = (unsigned int)v59[1].vfptr;
      v63 = v59->m_Components.size;
      if ( v62 < v63 )
      {
        v64 = (__int64)&v59->m_Components.p[v62];
        while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
             || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v62;
          v64 += 16i64;
          if ( v62 >= v63 )
            goto LABEL_139;
        }
LABEL_140:
        v61 = *(UFG::FaceActionComponent **)v64;
        goto LABEL_156;
      }
    }
LABEL_139:
    v61 = 0i64;
    goto LABEL_156;
  }
LABEL_161:
  v57 = 0;
LABEL_162:
  *bIsSocialActionAvailable = v57;
} }
    }
LABEL_139:
    v61 = 0i64;
    goto LABEL_156;
  }
LABEL_161:
  v57 = 0;
LABEL_162:
  *bIsSocialActionAvailable = v57;
}

// File Line: 4310
// RVA: 0x57BE10
bool __fastcall UFG::TargetingSystemPedPlayerComponent::useTargetRelativeMeleeCycling(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *m_pPointer; // rax
  bool result; // al

  result = 0;
  if ( UFG::TargetingSystemPedPlayerComponent::ms_bUseTargetRelativeMeleeCycling
    && !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    m_pPointer = this->m_pEquippedSOWPC.m_pPointer;
    if ( !m_pPointer
      || *(_DWORD *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                     + HIDWORD(m_pPointer[2].m_pSimObject))
                   + 100i64) == UFG::gNullQSymbolUC.mUID )
    {
      return 1;
    }
  }
  return result;
}

// File Line: 4322
// RVA: 0x56C3F0
float __fastcall UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qVector3 *vMyPosition,
        UFG::SimObject *pTargetSimObject,
        UFG::qMatrix44 *pTargetXform,
        bool bUseCones,
        bool bInitialAcquisition)
{
  float v7; // xmm15_4
  UFG::TargetingProfile *m_pActiveTargetingProfile; // r14
  int v12; // r12d
  float x; // xmm9_4
  float v14; // xmm9_4
  float v15; // xmm10_4
  float v16; // xmm8_4
  float TargetAcquisitionDistanceSquared; // xmm14_4
  float v18; // xmm12_4
  int v19; // ebx
  __int64 v20; // rdi
  UFG::qVector3 *v21; // rax
  float m_fIdlePriorityConeTime; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  float v25; // xmm0_4
  float y; // xmm1_4
  UFG::qVector3 *p_n1; // rdx
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v32; // rdx
  UFG::SimObject *m_pSimObject; // rcx
  float v34; // xmm8_4
  __m128 y_low; // xmm9
  float v36; // xmm7_4
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  float *p_mFOVOffset; // rax
  float v39; // xmm8_4
  float v40; // xmm7_4
  __m128 v41; // xmm2
  float v42; // xmm6_4
  UFG::BaseCameraComponent *v43; // rax
  _DWORD *v44; // rax
  int v45; // xmm3_4
  int v46; // xmm1_4
  double v47; // xmm0_8
  __int64 v48; // rax
  float v49; // xmm0_4
  signed __int16 v50; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v52; // r8d
  unsigned int v53; // r9d
  UFG::SimComponentHolder *v54; // rdx
  UFG::SimObject *v55; // rcx
  float v56; // xmm8_4
  __m128 v57; // xmm9
  float v58; // xmm7_4
  UFG::BaseCameraComponent *v59; // rax
  float *v60; // rax
  float v61; // xmm8_4
  float v62; // xmm7_4
  __m128 v63; // xmm2
  float v64; // xmm6_4
  UFG::BaseCameraComponent *v65; // rax
  _DWORD *v66; // rax
  int v67; // xmm3_4
  int v68; // xmm1_4
  double v69; // xmm0_8
  float v70; // xmm0_4
  float v71; // xmm1_4
  float m_fMaximumHalfHorizontalFOVWithLimiter; // xmm6_4
  bool bIsScripted; // [rsp+70h] [rbp-90h] BYREF
  bool bIsDowned; // [rsp+71h] [rbp-8Fh] BYREF
  bool bIsKnockedOut; // [rsp+72h] [rbp-8Eh] BYREF
  bool bTargetVehicleHasOccupant; // [rsp+73h] [rbp-8Dh] BYREF
  bool bIsTargetVehicle; // [rsp+74h] [rbp-8Ch] BYREF
  bool bIsSocialActionAvailable; // [rsp+75h] [rbp-8Bh] BYREF
  bool bShouldRejectTarget; // [rsp+76h] [rbp-8Ah] BYREF
  UFG::qVector3 v2; // [rsp+78h] [rbp-88h] BYREF
  UFG::qVector3 n1; // [rsp+88h] [rbp-78h] BYREF
  UFG::eFactionStandingEnum eFactionStanding; // [rsp+98h] [rbp-68h] BYREF
  UFG::qVector3 v1; // [rsp+A0h] [rbp-60h] BYREF
  UFG::qVector3 vMeToTarget; // [rsp+B0h] [rbp-50h] BYREF

  v7 = FLOAT_N1_0;
  if ( UFG::TargetingSystemPedPlayerComponent::isCommonInvalidTarget(this, pTargetSimObject) )
    return v7;
  m_pActiveTargetingProfile = this->m_pActiveTargetingProfile;
  v12 = -1;
  x = pTargetXform->v3.x;
  vMeToTarget.z = pTargetXform->v3.z - vMyPosition->z;
  v14 = x - vMyPosition->x;
  v15 = pTargetXform->v3.y - vMyPosition->y;
  vMeToTarget.x = v14;
  vMeToTarget.y = v15;
  v16 = 0.0;
  TargetAcquisitionDistanceSquared = 0.0;
  v18 = (float)((float)(v14 * v14) + (float)(v15 * v15)) + (float)(vMeToTarget.z * vMeToTarget.z);
  if ( bUseCones )
  {
    v19 = 0;
    v20 = 0i64;
    while ( 1 )
    {
      if ( v18 <= m_pActiveTargetingProfile->m_ConeDistancesSquared[v20] )
      {
        v21 = this->m_ConeToIntentionMap[v20];
        if ( v20
          || (m_fIdlePriorityConeTime = m_pActiveTargetingProfile->m_fIdlePriorityConeTime,
              m_fIdlePriorityConeTime <= 0.0) )
        {
          v24 = m_pActiveTargetingProfile->m_HalfHorizontalFOVs[v20];
        }
        else
        {
          v23 = this->m_fTargetingIntentionIdleTime / m_fIdlePriorityConeTime;
          if ( v23 > 1.0 )
            v23 = *(float *)&FLOAT_1_0;
          v24 = (float)((float)(1.0 - v23) * m_pActiveTargetingProfile->m_HalfHorizontalFOVs[0])
              + (float)(v23 * m_pActiveTargetingProfile->m_fHalfIdlePriorityConeHorizontalFOV);
        }
        v25 = v21->x;
        y = v21->y;
        v1.z = 0.0;
        v2.z = 0.0;
        v2.x = v25;
        v2.y = y;
        v1.x = v14;
        v1.y = v15;
        if ( v19 == 4 )
        {
          n1.z = -0.0;
          p_n1 = &n1;
          LODWORD(n1.x) = LODWORD(v25) ^ _xmm[0];
          LODWORD(n1.y) = LODWORD(y) ^ _xmm[0];
        }
        else
        {
          p_n1 = &v2;
        }
        v16 = UFG::qAngleBetween(&v1, p_n1);
        if ( v16 <= v24 )
          break;
      }
      ++v19;
      ++v20;
      if ( v19 > 4 )
        goto LABEL_95;
    }
    v12 = v19;
    if ( v19 != -1 )
      TargetAcquisitionDistanceSquared = m_pActiveTargetingProfile->m_ConeDistancesSquared[v19];
    goto LABEL_95;
  }
  if ( this->m_eFocusMode == eFOCUS_MODE_LOCKED_SOFT )
  {
    if ( !pTargetSimObject )
      goto LABEL_38;
    m_Flags = pTargetSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pTargetSimObject->m_Components.p[14].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = pTargetSimObject->m_Components.p[9].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)pTargetSimObject[1].vfptr;
        size = pTargetSimObject->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_33:
          m_pComponent = 0i64;
        }
        else
        {
          v32 = &pTargetSimObject->m_Components.p[vfptr];
          while ( (v32->m_TypeUID & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
               || (UFG::CompositeDrawableComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            ++v32;
            if ( vfptr >= size )
              goto LABEL_33;
          }
          m_pComponent = v32->m_pComponent;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pTargetSimObject, UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = pTargetSimObject->m_Components.p[14].m_pComponent;
    }
    if ( m_pComponent )
      m_pSimObject = m_pComponent[19].m_pSimObject;
    else
LABEL_38:
      m_pSimObject = 0i64;
    if ( m_pSimObject && LOBYTE(m_pSimObject->vfptr) > 1u )
      goto LABEL_95;
    TargetAcquisitionDistanceSquared = UFG::TargetingSystemPedBaseComponent::getTargetAcquisitionDistanceSquared(this);
    if ( v18 > TargetAcquisitionDistanceSquared )
      goto LABEL_95;
    v34 = pTargetXform->v3.x;
    y_low = (__m128)LODWORD(pTargetXform->v3.y);
    v36 = pTargetXform->v3.z + 1.0;
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      p_mFOVOffset = &mCurrentCamera->mCamera.mFOVOffset;
    else
      p_mFOVOffset = 0i64;
    v39 = v34 - p_mFOVOffset[44];
    y_low.m128_f32[0] = y_low.m128_f32[0] - p_mFOVOffset[45];
    v40 = v36 - p_mFOVOffset[46];
    v41 = y_low;
    v41.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v39 * v39)) + (float)(v40 * v40);
    if ( v41.m128_f32[0] == 0.0 )
      v42 = 0.0;
    else
      v42 = 1.0 / _mm_sqrt_ps(v41).m128_f32[0];
    v2.x = v39 * v42;
    v2.y = y_low.m128_f32[0] * v42;
    v2.z = v40 * v42;
    v43 = UFG::Director::Get()->mCurrentCamera;
    if ( v43 )
      v44 = (_DWORD *)&v43->mCamera.mFOVOffset;
    else
      v44 = 0i64;
    v45 = v44[42] ^ _xmm[0];
    v46 = v44[41] ^ _xmm[0];
    LODWORD(n1.x) = v44[40] ^ _xmm[0];
    LODWORD(n1.y) = v46;
    LODWORD(n1.z) = v45;
    v47 = UFG::qAngleBetweenNormals(&n1, &v2);
    v16 = *(float *)&v47;
    if ( bInitialAcquisition )
    {
      if ( this->m_pActionTreeComponent.m_pSimComponent
        && (v48 = *((_QWORD *)&this->m_pActionTreeComponent.m_pSimComponent[11].m_SafePointerList.mNode.mPrev
                  + ((__int64)(int)gActionRequest_UseCover.m_EnumValue >> 6)),
            _bittest64(&v48, gActionRequest_UseCover.m_EnumValue & 0x3F)) )
      {
        v49 = UFG::TargetingSystemPedPlayerComponent::ms_fSoftLockAutoAcquisitionInCoverConeHalfAngleRad;
      }
      else
      {
        v49 = UFG::TargetingSystemPedPlayerComponent::ms_fSoftLockAutoAcquisitionConeHalfAngleRad;
      }
      if ( v16 <= v49 )
        v12 = 0;
      goto LABEL_95;
    }
  }
  else
  {
    if ( !this->m_pOccupantOfVehicle.m_pPointer )
    {
      v70 = this->m_vTargetingForward.x;
      v71 = this->m_vTargetingForward.y;
      m_fMaximumHalfHorizontalFOVWithLimiter = m_pActiveTargetingProfile->m_fMaximumHalfHorizontalFOVWithLimiter;
      n1.z = 0.0;
      v2.z = 0.0;
      v2.x = v70;
      v2.y = v71;
      n1.x = v14;
      n1.y = v15;
      v16 = UFG::qAngleBetween(&n1, &v2);
      if ( v16 <= m_fMaximumHalfHorizontalFOVWithLimiter )
      {
        TargetAcquisitionDistanceSquared = UFG::TargetingSystemPedBaseComponent::getTargetAcquisitionDistanceSquared(this);
        if ( TargetAcquisitionDistanceSquared >= v18 )
          v12 = 0;
      }
      goto LABEL_95;
    }
    if ( !pTargetSimObject )
      goto LABEL_77;
    v50 = pTargetSimObject->m_Flags;
    if ( (v50 & 0x4000) != 0 )
    {
      ComponentOfType = pTargetSimObject->m_Components.p[14].m_pComponent;
    }
    else if ( v50 >= 0 )
    {
      if ( (v50 & 0x2000) != 0 )
      {
        ComponentOfType = pTargetSimObject->m_Components.p[9].m_pComponent;
      }
      else if ( (v50 & 0x1000) != 0 )
      {
        v52 = (unsigned int)pTargetSimObject[1].vfptr;
        v53 = pTargetSimObject->m_Components.size;
        if ( v52 >= v53 )
        {
LABEL_72:
          ComponentOfType = 0i64;
        }
        else
        {
          v54 = &pTargetSimObject->m_Components.p[v52];
          while ( (v54->m_TypeUID & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
               || (UFG::CompositeDrawableComponent::_TypeUID & ~v54->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v52;
            ++v54;
            if ( v52 >= v53 )
              goto LABEL_72;
          }
          ComponentOfType = v54->m_pComponent;
        }
      }
      else
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            pTargetSimObject,
                            UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfType = pTargetSimObject->m_Components.p[14].m_pComponent;
    }
    if ( ComponentOfType )
      v55 = ComponentOfType[19].m_pSimObject;
    else
LABEL_77:
      v55 = 0i64;
    if ( v55 && LOBYTE(v55->vfptr) > 1u )
      goto LABEL_95;
    TargetAcquisitionDistanceSquared = UFG::TargetingSystemPedBaseComponent::getTargetAcquisitionDistanceSquared(this);
    if ( v18 > TargetAcquisitionDistanceSquared )
      goto LABEL_95;
    v56 = pTargetXform->v3.x;
    v57 = (__m128)LODWORD(pTargetXform->v3.y);
    v58 = pTargetXform->v3.z + 1.0;
    v59 = UFG::Director::Get()->mCurrentCamera;
    if ( v59 )
      v60 = &v59->mCamera.mFOVOffset;
    else
      v60 = 0i64;
    v61 = v56 - v60[44];
    v57.m128_f32[0] = v57.m128_f32[0] - v60[45];
    v62 = v58 - v60[46];
    v63 = v57;
    v63.m128_f32[0] = (float)((float)(v57.m128_f32[0] * v57.m128_f32[0]) + (float)(v61 * v61)) + (float)(v62 * v62);
    if ( v63.m128_f32[0] == 0.0 )
      v64 = 0.0;
    else
      v64 = 1.0 / _mm_sqrt_ps(v63).m128_f32[0];
    v2.x = v61 * v64;
    v2.y = v57.m128_f32[0] * v64;
    v2.z = v62 * v64;
    v65 = UFG::Director::Get()->mCurrentCamera;
    if ( v65 )
      v66 = (_DWORD *)&v65->mCamera.mFOVOffset;
    else
      v66 = 0i64;
    v67 = v66[42] ^ _xmm[0];
    v68 = v66[41] ^ _xmm[0];
    LODWORD(n1.x) = v66[40] ^ _xmm[0];
    LODWORD(n1.y) = v68;
    LODWORD(n1.z) = v67;
    v69 = UFG::qAngleBetweenNormals(&n1, &v2);
    v16 = *(float *)&v69;
  }
  v12 = 0;
LABEL_95:
  bIsDowned = 0;
  bIsScripted = 0;
  bIsKnockedOut = 0;
  eFactionStanding = FACTIONSTANDING_INDIFFERENT;
  if ( v12 >= 0
    && UFG::TargetingSystemPedBaseComponent::IsWithinVerticalFOV(
         this,
         &vMeToTarget,
         m_pActiveTargetingProfile->m_fHalfVerticalFOV,
         m_pActiveTargetingProfile->m_fExtraPositivePitch,
         m_pActiveTargetingProfile->m_fExtraNegativePitch) )
  {
    UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(
      this,
      pTargetSimObject,
      this->m_bIsInAnyCombat,
      &bShouldRejectTarget,
      (UFG::SimObject **)&v1,
      &bIsTargetVehicle,
      &bTargetVehicleHasOccupant,
      &eFactionStanding,
      &bIsDowned,
      &bIsScripted,
      &bIsKnockedOut,
      &bIsSocialActionAvailable);
    if ( !bShouldRejectTarget && ((float)m_pActiveTargetingProfile->m_bConsiderDownedTargets != 0.0 || !bIsDowned) )
      return UFG::TargetingSystemPedPlayerComponent::calculateScore(
               this,
               (UFG::eConeEnum)v12,
               v18,
               TargetAcquisitionDistanceSquared,
               LODWORD(v16),
               pTargetSimObject == this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer,
               bIsDowned,
               bIsKnockedOut,
               eFactionStanding,
               bIsScripted,
               this->m_pOccupantOfVehicle.m_pPointer != 0i64,
               bIsTargetVehicle,
               bTargetVehicleHasOccupant,
               bIsSocialActionAvailable);
  }
  return v7;
}

// File Line: 4577
// RVA: 0x56C120
float __fastcall UFG::TargetingSystemPedPlayerComponent::scoreDirectionalTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qVector3 *vMyPosition,
        UFG::SimObject *pTargetSimObject,
        UFG::qMatrix44 *pTargetXform)
{
  float v5; // xmm7_4
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v10; // rcx
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm1_4
  UFG::TargetingProfile *m_pActiveTargetingProfile; // r14
  int v15; // edi
  float v16; // xmm9_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm8_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm6_4
  bool bIsTargetVehicle[8]; // [rsp+58h] [rbp-39h] BYREF
  UFG::eFactionStandingEnum eFactionStanding; // [rsp+60h] [rbp-31h] BYREF
  UFG::qVector3 v2; // [rsp+68h] [rbp-29h] BYREF
  UFG::qVector3 v1; // [rsp+78h] [rbp-19h] BYREF
  UFG::qVector3 vMeToTarget; // [rsp+88h] [rbp-9h] BYREF

  v5 = FLOAT_N1_0;
  if ( !UFG::TargetingSystemPedPlayerComponent::isCommonInvalidTarget(this, pTargetSimObject) )
  {
    m_pTargets = this->m_pTargets;
    v10 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[22];
    if ( m_pTargets[v10].m_pTarget.m_pPointer != pTargetSimObject
      || !m_pTargets[v10].m_pTarget.m_pPointer
      || !m_pTargets[v10].m_bLock )
    {
      x = pTargetXform->v3.x;
      y = pTargetXform->v3.y;
      z = pTargetXform->v3.z;
      m_pActiveTargetingProfile = this->m_pActiveTargetingProfile;
      v15 = -1;
      v16 = 0.0;
      v17 = x - vMyPosition->x;
      v18 = y - vMyPosition->y;
      vMeToTarget.z = z - vMyPosition->z;
      vMeToTarget.x = v17;
      v19 = (float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(vMeToTarget.z * vMeToTarget.z);
      vMeToTarget.y = v18;
      if ( v19 <= m_pActiveTargetingProfile->m_ConeDistancesSquared[5] )
      {
        v20 = this->m_vDirectionalTargetingIntention.x;
        v21 = this->m_vDirectionalTargetingIntention.y;
        v1.z = 0.0;
        v2.z = 0.0;
        v22 = m_pActiveTargetingProfile->m_HalfHorizontalFOVs[5];
        v2.x = v20;
        v2.y = v21;
        v1.x = v17;
        v1.y = v18;
        v16 = UFG::qAngleBetween(&v1, &v2);
        if ( v22 >= v16 )
          v15 = 5;
      }
      bIsTargetVehicle[1] = 0;
      bIsTargetVehicle[0] = 0;
      bIsTargetVehicle[2] = 0;
      eFactionStanding = FACTIONSTANDING_INDIFFERENT;
      if ( v15 >= 0
        && UFG::TargetingSystemPedBaseComponent::IsWithinVerticalFOV(
             this,
             &vMeToTarget,
             m_pActiveTargetingProfile->m_fHalfVerticalFOV,
             m_pActiveTargetingProfile->m_fExtraPositivePitch,
             m_pActiveTargetingProfile->m_fExtraNegativePitch) )
      {
        UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(
          this,
          pTargetSimObject,
          this->m_bIsInAnyCombat,
          &bIsTargetVehicle[4],
          (UFG::SimObject **)&v2,
          &bIsTargetVehicle[6],
          &bIsTargetVehicle[3],
          &eFactionStanding,
          &bIsTargetVehicle[1],
          bIsTargetVehicle,
          &bIsTargetVehicle[2],
          &bIsTargetVehicle[5]);
        if ( !bIsTargetVehicle[4] && !bIsTargetVehicle[1] && eFactionStanding )
          return UFG::TargetingSystemPedPlayerComponent::calculateScore(
                   this,
                   (UFG::eConeEnum)v15,
                   v19,
                   m_pActiveTargetingProfile->m_ConeDistancesSquared[v15],
                   LODWORD(v16),
                   pTargetSimObject == this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[48]].m_pTarget.m_pPointer,
                   0,
                   bIsTargetVehicle[2],
                   eFactionStanding,
                   bIsTargetVehicle[6],
                   this->m_pOccupantOfVehicle.m_pPointer != 0i64,
                   bIsTargetVehicle[6],
                   bIsTargetVehicle[3],
                   bIsTargetVehicle[5]);
      }
    }
  }
  return v5;
}

// File Line: 4752
// RVA: 0x56CD30
float __fastcall UFG::TargetingSystemPedPlayerComponent::scoreSoftLockTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::qVector3 *vMyPosition,
        UFG::SimObject *pTargetSimObject,
        UFG::qMatrix44 *pTargetXform,
        UFG::SimObject *pMyOccupiedVehicle)
{
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v11; // rcx
  UFG::SimObject *m_pPointer; // rdx
  UFG::SimComponent *v13; // rax
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm9_4
  float v17; // xmm0_4
  float m_fMaximumTargetDistanceSquared; // xmm0_4
  UFG::Camera *p_mCamera; // rdi
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  _DWORD *p_mFOVOffset; // rax
  UFG::BaseCameraComponent *v22; // rax
  _DWORD *v23; // rax
  int v24; // xmm2_4
  int v25; // xmm1_4
  UFG::BaseCameraComponent *v26; // rcx
  float v27; // xmm6_4
  float v28; // xmm7_4
  __int64 v29; // r8
  UFG::SubTargetingProfile *SubTargetingProfileForTarget; // rax
  float m_fSoftLockExtraCapsuleRadius; // xmm0_4
  bool v32; // r8
  bool bShouldRejectTarget; // [rsp+60h] [rbp-51h] BYREF
  bool bIsTargetVehicle; // [rsp+61h] [rbp-50h] BYREF
  bool bIsDowned; // [rsp+62h] [rbp-4Fh] BYREF
  bool bIsKnockedOut; // [rsp+63h] [rbp-4Eh] BYREF
  bool bTargetVehicleHasOccupant; // [rsp+64h] [rbp-4Dh] BYREF
  bool bIsScripted; // [rsp+65h] [rbp-4Ch] BYREF
  bool bIsSocialActionAvailable; // [rsp+66h] [rbp-4Bh] BYREF
  UFG::eFactionStandingEnum fRadius; // [rsp+68h] [rbp-49h] BYREF
  UFG::qVector3 pXform; // [rsp+70h] [rbp-41h] BYREF
  UFG::qVector3 ray_pos_p; // [rsp+80h] [rbp-31h] BYREF
  UFG::qVector3 seg_pos_p; // [rsp+90h] [rbp-21h] BYREF
  UFG::qVector3 vSegB; // [rsp+A0h] [rbp-11h] BYREF
  UFG::qVector3 vSegA; // [rsp+B0h] [rbp-1h] BYREF

  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  if ( UFG::TargetingSystemPedPlayerComponent::isCommonInvalidTarget(this, pTargetSimObject) )
    return FLOAT_N1_0;
  m_pTargets = this->m_pTargets;
  v11 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[17];
  if ( m_pTargets[v11].m_pTarget.m_pPointer )
  {
    if ( m_pTargets[v11].m_bLock )
    {
      m_pPointer = m_pTargets[v11].m_pTarget.m_pPointer;
      if ( m_pPointer )
      {
        if ( pTargetSimObject == m_pPointer )
          return FLOAT_N1_0;
      }
    }
  }
  v13 = this->m_pEquippedSOWPC.m_pPointer;
  v14 = pTargetXform->v3.x - vMyPosition->x;
  v15 = pTargetXform->v3.y - vMyPosition->y;
  v16 = pTargetXform->v3.z - vMyPosition->z;
  if ( v13 )
  {
    v17 = *(float *)(*((_QWORD *)&v13[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v13[2].m_pSimObject))
                   + 40i64);
    m_fMaximumTargetDistanceSquared = v17 * v17;
  }
  else
  {
    m_fMaximumTargetDistanceSquared = this->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
  }
  if ( (float)((float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v16 * v16)) > m_fMaximumTargetDistanceSquared )
    return FLOAT_N1_0;
  p_mCamera = 0i64;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mFOVOffset = (_DWORD *)&mCurrentCamera->mCamera.mFOVOffset;
  else
    p_mFOVOffset = 0i64;
  if ( (float)((float)((float)(COERCE_FLOAT(p_mFOVOffset[41] ^ _xmm[0]) * v15)
                     + (float)(COERCE_FLOAT(p_mFOVOffset[40] ^ _xmm[0]) * v14))
             + (float)(COERCE_FLOAT(p_mFOVOffset[42] ^ _xmm[0]) * v16)) <= 0.0 )
    return FLOAT_N1_0;
  *(_QWORD *)&pXform.x = 0i64;
  UFG::SimObjectUtility::GetObjectCapsuleApproximation(
    pTargetSimObject,
    (UFG::qMatrix44 **)&pXform,
    &vSegA,
    &vSegB,
    (float *)&fRadius);
  v22 = UFG::Director::Get()->mCurrentCamera;
  if ( v22 )
    v23 = (_DWORD *)&v22->mCamera.mFOVOffset;
  else
    v23 = 0i64;
  v24 = v23[42] ^ _xmm[0];
  v25 = v23[41] ^ _xmm[0];
  LODWORD(pXform.x) = v23[40] ^ _xmm[0];
  LODWORD(pXform.y) = v25;
  LODWORD(pXform.z) = v24;
  v26 = UFG::Director::Get()->mCurrentCamera;
  if ( v26 )
    p_mCamera = &v26->mCamera;
  UFG::qNearestRaySeg((UFG::qVector3 *)&p_mCamera->mTransformation.v3, &pXform, &vSegA, &vSegB, &ray_pos_p, &seg_pos_p);
  v27 = *(float *)&fRadius;
  v28 = (float)((float)((float)(seg_pos_p.y - ray_pos_p.y) * (float)(seg_pos_p.y - ray_pos_p.y))
              + (float)((float)(seg_pos_p.x - ray_pos_p.x) * (float)(seg_pos_p.x - ray_pos_p.x)))
      + (float)((float)(seg_pos_p.z - ray_pos_p.z) * (float)(seg_pos_p.z - ray_pos_p.z));
  SubTargetingProfileForTarget = UFG::TargetingSystemPedBaseComponent::GetSubTargetingProfileForTarget(
                                   this,
                                   pTargetSimObject,
                                   v29);
  if ( SubTargetingProfileForTarget )
  {
    m_fSoftLockExtraCapsuleRadius = SubTargetingProfileForTarget->m_fSoftLockExtraCapsuleRadius;
    if ( pMyOccupiedVehicle )
      m_fSoftLockExtraCapsuleRadius = m_fSoftLockExtraCapsuleRadius
                                    * UFG::TargetingSystemPedPlayerComponent::ms_fInVehicleCapsuleInflationFactor;
    v27 = m_fSoftLockExtraCapsuleRadius + v27;
  }
  if ( v28 > (float)(v27 * v27) )
    return FLOAT_N1_0;
  v32 = (unsigned int)(this->m_eFocusMode - 1) <= 1 || this->m_bTargetAutoAcquisitionJustRequested;
  UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(
    this,
    pTargetSimObject,
    v32,
    &bShouldRejectTarget,
    (UFG::SimObject **)&pXform,
    &bIsTargetVehicle,
    &bTargetVehicleHasOccupant,
    &fRadius,
    &bIsDowned,
    &bIsScripted,
    &bIsKnockedOut,
    &bIsSocialActionAvailable);
  if ( bShouldRejectTarget )
    return FLOAT_N1_0;
  else
    return v28;
}

// File Line: 4926
// RVA: 0x57A120
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateTargets(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *m_pPointer; // rax
  float v3; // xmm0_4
  float m_fMaximumTargetDistanceSquared; // xmm0_4
  float m_fMinimumTargetDistanceSquared; // xmm3_4
  UFG::SimComponent *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  UFG::TargetingMap *m_pTargetingMap; // rdx
  UFG::TargetingSimObject *m_pTargets; // r9
  UFG::TargetingSimObject *v12; // rcx
  unsigned __int8 v13; // cl
  __int64 v14; // r8
  UFG::TargetingSimObject *v15; // rdx
  UFG::TargetingSimObject *v16; // rcx
  __int64 v17; // rdi
  UFG::TargetingSimObject *v18; // rax
  UFG::qFixedArray<UFG::ClosePhysicalTarget,1> closePhysicalMeleeAttackableList; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v20; // [rsp+58h] [rbp-A8h]
  UFG::qFixedArray<UFG::CloseTarget *,5> closePropsList; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePickupsList; // [rsp+90h] [rbp-70h] BYREF
  UFG::qFixedArray<UFG::ClosePhysicalTarget,2> closePhysicalDodgeableList; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,20> closeVehiclesList; // [rsp+F0h] [rbp-10h] BYREF
  UFG::qFixedArray<UFG::ClosePhysicalTarget,10> filteredClosePhysicalTargetsList; // [rsp+1A0h] [rbp+A0h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,80> filteredClosePedsList; // [rsp+250h] [rbp+150h] BYREF
  UFG::qFixedArray<UFG::CloseTarget,100> closeTargetsList; // [rsp+4E0h] [rbp+3E0h] BYREF

  v20 = -2i64;
  filteredClosePedsList.size = 0;
  closeTargetsList.size = 0;
  filteredClosePickupsList.size = 0;
  closePropsList.size = 0;
  closeVehiclesList.size = 0;
  filteredClosePhysicalTargetsList.size = 0;
  closePhysicalDodgeableList.size = 0;
  closePhysicalMeleeAttackableList.size = 0;
  if ( ((unsigned __int8 (__fastcall *)(UFG::TargetingSystemPedPlayerComponent *))this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[22].__vecDelDtor)(this) )
  {
    m_pPointer = this->m_pEquippedSOWPC.m_pPointer;
    if ( m_pPointer )
    {
      v3 = *(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                      + HIDWORD(m_pPointer[2].m_pSimObject))
                    + 40i64);
      m_fMaximumTargetDistanceSquared = v3 * v3;
    }
    else
    {
      m_fMaximumTargetDistanceSquared = this->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
    }
    m_fMinimumTargetDistanceSquared = this->m_fMinimumTargetDistanceSquared;
    if ( m_fMinimumTargetDistanceSquared <= m_fMaximumTargetDistanceSquared )
      m_fMinimumTargetDistanceSquared = m_fMaximumTargetDistanceSquared;
    UFG::TargetingSystemPedBaseComponent::findCloseTargets(
      &this->m_CloseTargetsList,
      this->m_pSimObject,
      &this->m_vTargetingPosition,
      m_fMinimumTargetDistanceSquared);
  }
  UFG::TargetingSystemPedBaseComponent::filterCloseTargets(
    &this->m_CloseTargetsList,
    &this->m_CachedPedsList,
    &filteredClosePedsList,
    &filteredClosePickupsList,
    &closePropsList,
    &closeVehiclesList,
    &closeTargetsList);
  v6 = this->m_pEquippedSOWPC.m_pPointer;
  if ( v6 )
  {
    v7 = *(float *)(*((_QWORD *)&v6[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v6[2].m_pSimObject)) + 40i64);
    v8 = v7 * v7;
  }
  else
  {
    v8 = this->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
  }
  v9 = this->m_fMinimumTargetDistanceSquared;
  if ( v9 <= v8 )
    v9 = v8;
  UFG::TargetingSystemPedBaseComponent::findClosePhysicalTargets(
    this,
    &this->m_ClosePhysicalTargetsList,
    this->m_pSimObject,
    v9);
  UFG::TargetingSystemPedBaseComponent::filterClosePhysicalTargets(
    this,
    &this->m_ClosePhysicalTargetsList,
    &closePhysicalDodgeableList,
    &closePhysicalMeleeAttackableList,
    &filteredClosePhysicalTargetsList);
  UFG::TargetingSystemPedPlayerComponent::updateAttackingTarget(this);
  UFG::TargetingSystemPedPlayerComponent::updateFocusTarget(
    this,
    &filteredClosePedsList,
    (unsigned __int64)&filteredClosePickupsList,
    &closePropsList,
    &closeVehiclesList,
    &closeTargetsList);
  UFG::TargetingSystemPedBaseComponent::updateClosestPedTarget(this, &filteredClosePedsList);
  m_pTargetingMap = this->m_pTargetingMap;
  m_pTargets = this->m_pTargets;
  v12 = &m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[21]];
  if ( (!v12->m_pTarget.m_pPointer || !v12->m_bLock) && m_pTargetingMap->m_Map.p[21] )
    UFG::TargetingSimObject::SetTarget(
      v12,
      m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer);
  v13 = this->m_pTargetingMap->m_Map.p[eTARGET_TYPE_WORLD_EDITOR_SELECTED_OBJECT];
  if ( v13 )
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v13], 0i64);
  v14 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[eTARGET_TYPE_INTERACTIVE_PROP];
  v15 = this->m_pTargets;
  v16 = &v15[v14];
  if ( !v16->m_pTarget.m_pPointer || !v16->m_bLock )
  {
    if ( closePropsList.size )
    {
      if ( (_BYTE)v14 )
        UFG::TargetingSimObject::SetTarget(v16, closePropsList.p[0]->m_pSimObjectPropertiesComponent->m_pSimObject);
    }
    else if ( (_BYTE)v14 )
    {
      v17 = v14;
      UFG::TargetingSimObject::SetTarget(&v15[v14], 0i64);
      v18 = this->m_pTargets;
      if ( v18[v17].m_bLock )
        v18[v17].m_bLock = 0;
    }
  }
  UFG::TargetingSystemPedBaseComponent::updatePickupTarget(this, &filteredClosePickupsList);
  UFG::TargetingSystemPedBaseComponent::updateVehicleTarget(this, &closeVehiclesList);
  UFG::TargetingSystemPedPlayerComponent::updateActionHijackTarget(this, &closeVehiclesList);
  UFG::TargetingSystemPedPlayerComponent::updateClosestDownedPedTarget(this, &filteredClosePedsList);
  UFG::TargetingSystemPedPlayerComponent::updateDirectionalTarget(this, &closeTargetsList);
  UFG::TargetingSystemPedBaseComponent::updatePhysicalTarget(this, &filteredClosePhysicalTargetsList);
  UFG::TargetingSystemPedPlayerComponent::updateSocialTarget(this, &filteredClosePedsList);
  UFG::TargetingSystemPedPlayerComponent::updateCrowdPushTargets(
    this,
    &filteredClosePedsList,
    &closePhysicalDodgeableList);
  UFG::TargetingSystemPedPlayerComponent::updateTransitTarget(this, &closeVehiclesList);
  UFG::TargetingSystemPedPlayerComponent::updateVehicleClosestPointTarget(this);
}

// File Line: 4985
// RVA: 0x56D650
bool __fastcall UFG::TargetingSystemPedPlayerComponent::shouldUpdateThisFrame(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  return UFG::Metrics::msInstance.mSimFrameCount & 1;
}

// File Line: 4995
// RVA: 0x549D70
void __fastcall UFG::TargetingSystemPedPlayerComponent::Reset(UFG::TargetingSystemPedPlayerComponent *this)
{
  unsigned int *m_pBucketList; // rcx

  UFG::TargetingSystemBaseComponent::shutdown(this);
  UFG::TargetingSystemBaseComponent::initialize(this);
  m_pBucketList = this->m_pBucketList;
  this->m_CachedPedsList.size = 0;
  if ( m_pBucketList )
  {
    --m_pBucketList[this->m_uUpdateBucket];
    this->m_pBucketList = 0i64;
  }
  UFG::TargetingSystemPedBaseComponent::initialize(this);
  UFG::TargetingSystemPedPlayerComponent::shutdown(this);
  UFG::TargetingSystemPedPlayerComponent::initialize(this);
}

// File Line: 5005
// RVA: 0x54D110
void __fastcall UFG::TargetingSystemPedPlayerComponent::SetFocusModeOverrideSimObject(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::SimObject *pSimObject,
        UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pFocusModeOverrideSimObject; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  unsigned __int8 v7; // cl

  p_m_pFocusModeOverrideSimObject = &this->m_pFocusModeOverrideSimObject;
  if ( this->m_pFocusModeOverrideSimObject.m_pPointer )
  {
    mPrev = p_m_pFocusModeOverrideSimObject->mPrev;
    mNext = this->m_pFocusModeOverrideSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pFocusModeOverrideSimObject->mPrev = p_m_pFocusModeOverrideSimObject;
    this->m_pFocusModeOverrideSimObject.mNext = &this->m_pFocusModeOverrideSimObject;
  }
  this->m_pFocusModeOverrideSimObject.m_pPointer = pSimObject;
  if ( pSimObject )
  {
    v6 = pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v6->mNext = p_m_pFocusModeOverrideSimObject;
    p_m_pFocusModeOverrideSimObject->mPrev = v6;
    this->m_pFocusModeOverrideSimObject.mNext = &pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pFocusModeOverrideSimObject;
  }
  v7 = this->m_pTargetingMap->m_Map.p[22];
  if ( v7 )
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v7], pSimObject);
  LOBYTE(mPrev) = 1;
  ((void (__fastcall *)(UFG::TargetingSystemPedPlayerComponent *, __int64, UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *, _QWORD, _DWORD, _QWORD, _QWORD, _QWORD))this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
    this,
    22i64,
    mPrev,
    0i64,
    0,
    0i64,
    0i64,
    0i64);
}

// File Line: 5014
// RVA: 0x522D80
void __fastcall UFG::TargetingSystemPedPlayerComponent::ClearFocusModeOverrideSimObject(
        UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pFocusModeOverrideSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  p_m_pFocusModeOverrideSimObject = &this->m_pFocusModeOverrideSimObject;
  if ( this->m_pFocusModeOverrideSimObject.m_pPointer )
  {
    mPrev = p_m_pFocusModeOverrideSimObject->mPrev;
    mNext = p_m_pFocusModeOverrideSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pFocusModeOverrideSimObject->mPrev = p_m_pFocusModeOverrideSimObject;
    p_m_pFocusModeOverrideSimObject->mNext = p_m_pFocusModeOverrideSimObject;
  }
  p_m_pFocusModeOverrideSimObject->m_pPointer = 0i64;
}

// File Line: 5021
// RVA: 0x526DE0
void __fastcall UFG::TargetingSystemPedPlayerComponent::EnableRimLighting(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::eTargetTypeEnum eTargetType)
{
  UFG::TargetingMap *m_pTargetingMap; // rax
  __int64 v3; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_Target; // rdx
  UFG::SimObject *m_pPointer; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax

  if ( !this->m_RimLighting.m_bEnabled )
  {
    m_pTargetingMap = this->m_pTargetingMap;
    this->m_RimLighting.m_TargetType = eTargetType;
    this->m_RimLighting.m_bEnabled = 1;
    v3 = (unsigned __int8)m_pTargetingMap->m_Map.p[eTargetType];
    p_m_Target = &this->m_RimLighting.m_Target;
    m_pPointer = this->m_pTargets[v3].m_pTarget.m_pPointer;
    if ( this->m_RimLighting.m_Target.m_pPointer )
    {
      mPrev = p_m_Target->mPrev;
      mNext = p_m_Target->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_Target->mPrev = p_m_Target;
      p_m_Target->mNext = p_m_Target;
    }
    p_m_Target->m_pPointer = m_pPointer;
    if ( m_pPointer )
    {
      v8 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v8->mNext = p_m_Target;
      p_m_Target->mPrev = v8;
      p_m_Target->mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_Target;
    }
  }
}

// File Line: 5053
// RVA: 0x548F10
void __fastcall UFG::TargetingSystemPedPlayerComponent::RemoveCloseTarget(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::SimObjectPropertiesComponent *pSOPC)
{
  unsigned int size; // ecx
  int v4; // eax
  UFG::SimObjectPropertiesComponent **i; // r8
  __int64 v6; // r10
  __int64 v7; // rax
  __int64 v8; // rdx
  __int64 v9; // r8
  UFG::qVector4 v10; // xmm3
  UFG::qVector4 v11; // xmm2
  UFG::qVector4 v12; // xmm1

  size = this->m_CloseTargetsList.size;
  v4 = 0;
  if ( size )
  {
    for ( i = &this->m_CloseTargetsList.p[0].m_pSimObjectPropertiesComponent; *i != pSOPC; i += 10 )
    {
      if ( ++v4 >= size )
        return;
    }
    v6 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v6 < size )
    {
      do
      {
        v7 = (unsigned int)(v6 - 1);
        v8 = 5 * v6;
        v6 = (unsigned int)(v6 + 1);
        v8 *= 2i64;
        v9 = v7;
        this->m_CloseTargetsList.p[v9].m_fDistance2 = *(&this->m_CloseTargetsList.p[0].m_fDistance2 + 2 * v8);
        this->m_CloseTargetsList.p[v9].m_pSimObjectPropertiesComponent = (UFG::SimObjectPropertiesComponent *)*((_QWORD *)&this->m_CloseTargetsList.p[0].m_pSimObjectPropertiesComponent + v8);
        v10 = *(UFG::qVector4 *)((char *)&this->m_CloseTargetsList.p[0].m_Xform.v1 + 8 * v8);
        v11 = *(UFG::qVector4 *)((char *)&this->m_CloseTargetsList.p[0].m_Xform.v2 + 8 * v8);
        v12 = *(UFG::qVector4 *)((char *)&this->m_CloseTargetsList.p[0].m_Xform.v3 + 8 * v8);
        this->m_CloseTargetsList.p[v9].m_Xform.v0 = *(UFG::qVector4 *)((char *)&this->m_CloseTargetsList.p[0].m_Xform.v0
                                                                     + 8 * v8);
        this->m_CloseTargetsList.p[v9].m_Xform.v1 = v10;
        this->m_CloseTargetsList.p[v9].m_Xform.v2 = v11;
        this->m_CloseTargetsList.p[v9].m_Xform.v3 = v12;
      }
      while ( (unsigned int)v6 < this->m_CloseTargetsList.size );
    }
    --this->m_CloseTargetsList.size;
  }
}

// File Line: 5070
// RVA: 0x55CE80
void __fastcall UFG::TargetingSystemPedPlayerComponent::Update(
        UFG::TargetingSystemPedPlayerComponent *this,
        float fDeltaS)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rcx
  UFG::HasAttackRequestNode *CurrentAttacker; // rax
  UFG::SimObject *v5; // rdx
  unsigned __int8 v6; // cl
  unsigned int v7; // eax
  bool v8; // cf
  bool v9; // zf
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax
  __int64 v11; // rbx

  UFG::TargetingSystemPedPlayerComponent::UpdateCommon(
    (UFG::TargetingSystemPedPlayerComponent *)((char *)this - 64),
    UFG::Metrics::msInstance.mSimTimeUnscaledDelta);
  UFG::TargetingSystemPedPlayerComponent::updateDesiredFocusMode((UFG::TargetingSystemPedPlayerComponent *)((char *)this - 64));
  UFG::TargetingSystemPedPlayerComponent::updateTargetingIntentions((UFG::TargetingSystemPedPlayerComponent *)((char *)this - 64));
  UFG::TargetingSystemPedPlayerComponent::updateTargets((UFG::TargetingSystemPedPlayerComponent *)((char *)this - 64));
  UFG::TargetingSystemPedPlayerComponent::updateRagdoll((UFG::TargetingSystemPedPlayerComponent *)((char *)this - 64));
  UFG::TargetingSystemPedPlayerComponent::updateRimLighting((UFG::TargetingSystemPedPlayerComponent *)((char *)this - 64));
  UFG::TargetingSystemPedPlayerComponent::updateVehicleProjectileTargets((UFG::TargetingSystemPedPlayerComponent *)((char *)this - 64));
  UFG::TargetingSystemPedPlayerComponent::updateFocusTargetSubTargetingLocation((UFG::TargetingSystemPedPlayerComponent *)((char *)this - 64));
  mNext = this->m_pAimingPlayerComponent.mNext;
  if ( mNext )
  {
    CurrentAttacker = UFG::AttackRightsComponent::GetCurrentAttacker(
                        (UFG::AttackRightsComponent *)mNext,
                        eATTACK_TYPE_MELEE);
    v5 = CurrentAttacker ? (UFG::SimObject *)UFG::HasAttackRequestNode::GetSimObject(CurrentAttacker) : 0i64;
    v6 = *(_BYTE *)(*(_QWORD *)&this->m_Flags + 85i64);
    if ( v6 )
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(*(_QWORD *)&this->m_TypeUID + 56i64 * v6), v5);
  }
  v7 = LODWORD(this->m_VehicleCharacterRagdolls[9].m_pPointer) - 1;
  v8 = v7 < 3;
  v9 = v7 == 3;
  v10 = this->m_pCharacterAnimationComponent.mNext;
  LOBYTE(v10[53].mPrev) &= ~1u;
  LOBYTE(v10[53].mPrev) |= v8 || v9;
  v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_Flags + 30i64) + *(_QWORD *)&this->m_TypeUID + 40);
  if ( v11 != *(_QWORD *)&this->m_vTargetingPosition.z )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))this->m_pCharacterAnimationComponent.mNext->mPrev[11].mPrev)(this->m_pCharacterAnimationComponent.mNext);
    *(_QWORD *)&this->m_vTargetingPosition.z = v11;
  }
  LOBYTE(this->m_pInterestPointUserComponent.m_Changed) = 0;
}

// File Line: 5113
// RVA: 0x53F000
void __fastcall UFG::TargetingSystemPedPlayerComponent::OnAttach(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::SimObject *pSimObject)
{
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_m_pCharacterAnimationComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0> *p_m_pAimingPlayerComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *p_m_pAttackRightsComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::SimComponent *m_pSimComponent; // rax
  unsigned __int8 v20; // cl

  UFG::TargetingSystemPedBaseComponent::OnAttach(this, pSimObject);
  p_m_pCharacterAnimationComponent = &this->m_pCharacterAnimationComponent;
  if ( this->m_pCharacterAnimationComponent.m_pSimComponent )
  {
    mPrev = p_m_pCharacterAnimationComponent->mPrev;
    mNext = this->m_pCharacterAnimationComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->m_pCharacterAnimationComponent.m_pSimObject = 0i64;
    this->m_pCharacterAnimationComponent.mNext = &this->m_pCharacterAnimationComponent;
    p_m_pCharacterAnimationComponent->mPrev = p_m_pCharacterAnimationComponent;
    goto LABEL_8;
  }
  if ( this->m_pCharacterAnimationComponent.m_pSimObject
    && (p_m_pCharacterAnimationComponent->mPrev != p_m_pCharacterAnimationComponent
     || this->m_pCharacterAnimationComponent.mNext != &this->m_pCharacterAnimationComponent) )
  {
    v7 = p_m_pCharacterAnimationComponent->mPrev;
    v8 = this->m_pCharacterAnimationComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  this->m_pCharacterAnimationComponent.m_Changed = 1;
  this->m_pCharacterAnimationComponent.m_pSimObject = pSimObject;
  this->m_pCharacterAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObject>(
    p_m_pCharacterAnimationComponent,
    pSimObject);
  p_m_pAimingPlayerComponent = &this->m_pAimingPlayerComponent;
  if ( this->m_pAimingPlayerComponent.m_pSimComponent )
  {
    v10 = p_m_pAimingPlayerComponent->mPrev;
    v11 = this->m_pAimingPlayerComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->m_pAimingPlayerComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pAimingPlayerComponent.m_pSimObject = 0i64;
    this->m_pAimingPlayerComponent.mNext = &this->m_pAimingPlayerComponent;
    p_m_pAimingPlayerComponent->mPrev = p_m_pAimingPlayerComponent;
    goto LABEL_15;
  }
  if ( this->m_pAimingPlayerComponent.m_pSimObject
    && (p_m_pAimingPlayerComponent->mPrev != p_m_pAimingPlayerComponent
     || this->m_pAimingPlayerComponent.mNext != &this->m_pAimingPlayerComponent) )
  {
    v12 = p_m_pAimingPlayerComponent->mPrev;
    v13 = this->m_pAimingPlayerComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pAimingPlayerComponent.m_Changed = 1;
  this->m_pAimingPlayerComponent.m_pSimObject = pSimObject;
  this->m_pAimingPlayerComponent.m_TypeUID = UFG::AimingPlayerComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pAimingPlayerComponent,
    pSimObject);
  p_m_pAttackRightsComponent = &this->m_pAttackRightsComponent;
  if ( this->m_pAttackRightsComponent.m_pSimComponent )
  {
    v15 = p_m_pAttackRightsComponent->mPrev;
    v16 = this->m_pAttackRightsComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    this->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pAttackRightsComponent.m_pSimObject = 0i64;
    this->m_pAttackRightsComponent.mNext = &this->m_pAttackRightsComponent;
    p_m_pAttackRightsComponent->mPrev = p_m_pAttackRightsComponent;
    goto LABEL_22;
  }
  if ( this->m_pAttackRightsComponent.m_pSimObject
    && (p_m_pAttackRightsComponent->mPrev != p_m_pAttackRightsComponent
     || this->m_pAttackRightsComponent.mNext != &this->m_pAttackRightsComponent) )
  {
    v17 = p_m_pAttackRightsComponent->mPrev;
    v18 = this->m_pAttackRightsComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pAttackRightsComponent.m_Changed = 1;
  this->m_pAttackRightsComponent.m_pSimObject = pSimObject;
  this->m_pAttackRightsComponent.m_TypeUID = UFG::AttackRightsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pAttackRightsComponent,
    pSimObject);
  m_pSimComponent = this->m_pAimingPlayerComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v20 = this->m_pTargetingMap->m_Map.p[3];
    if ( v20 )
      UFG::TargetingSimObject::SetTarget(
        &this->m_pTargets[v20],
        (UFG::SimObject *)m_pSimComponent[13].m_BoundComponentHandles.mNode.mPrev);
  }
}

// File Line: 5126
// RVA: 0x541180
void __fastcall UFG::TargetingSystemPedPlayerComponent::OnDetach(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0> *p_m_pAimingPlayerComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_m_pCharacterAnimationComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *p_m_pAttackRightsComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax

  p_m_pAimingPlayerComponent = &this->m_pAimingPlayerComponent;
  if ( this->m_pAimingPlayerComponent.m_pSimComponent )
  {
    mPrev = p_m_pAimingPlayerComponent->mPrev;
    mNext = this->m_pAimingPlayerComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pAimingPlayerComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_m_pAimingPlayerComponent->m_pSimObject = 0i64;
    p_m_pAimingPlayerComponent->mNext = p_m_pAimingPlayerComponent;
    p_m_pAimingPlayerComponent->mPrev = p_m_pAimingPlayerComponent;
    goto LABEL_8;
  }
  if ( this->m_pAimingPlayerComponent.m_pSimObject
    && (p_m_pAimingPlayerComponent->mPrev != p_m_pAimingPlayerComponent
     || this->m_pAimingPlayerComponent.mNext != &this->m_pAimingPlayerComponent) )
  {
    v5 = p_m_pAimingPlayerComponent->mPrev;
    v6 = p_m_pAimingPlayerComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pCharacterAnimationComponent = &this->m_pCharacterAnimationComponent;
  p_m_pAimingPlayerComponent->m_Changed = 1;
  if ( this->m_pCharacterAnimationComponent.m_pSimComponent )
  {
    v8 = p_m_pCharacterAnimationComponent->mPrev;
    v9 = this->m_pCharacterAnimationComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pCharacterAnimationComponent.m_pSimObject = 0i64;
    this->m_pCharacterAnimationComponent.mNext = &this->m_pCharacterAnimationComponent;
    p_m_pCharacterAnimationComponent->mPrev = p_m_pCharacterAnimationComponent;
    goto LABEL_15;
  }
  if ( this->m_pCharacterAnimationComponent.m_pSimObject
    && (p_m_pCharacterAnimationComponent->mPrev != p_m_pCharacterAnimationComponent
     || this->m_pCharacterAnimationComponent.mNext != &this->m_pCharacterAnimationComponent) )
  {
    v10 = p_m_pCharacterAnimationComponent->mPrev;
    v11 = this->m_pCharacterAnimationComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pCharacterAnimationComponent.m_Changed = 1;
  p_m_pAttackRightsComponent = &this->m_pAttackRightsComponent;
  if ( this->m_pAttackRightsComponent.m_pSimComponent )
  {
    v13 = p_m_pAttackRightsComponent->mPrev;
    v14 = this->m_pAttackRightsComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pAttackRightsComponent.m_pSimObject = 0i64;
    this->m_pAttackRightsComponent.mNext = &this->m_pAttackRightsComponent;
    p_m_pAttackRightsComponent->mPrev = p_m_pAttackRightsComponent;
    goto LABEL_22;
  }
  if ( this->m_pAttackRightsComponent.m_pSimObject
    && (p_m_pAttackRightsComponent->mPrev != p_m_pAttackRightsComponent
     || this->m_pAttackRightsComponent.mNext != &this->m_pAttackRightsComponent) )
  {
    v15 = p_m_pAttackRightsComponent->mPrev;
    v16 = this->m_pAttackRightsComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pAttackRightsComponent.m_Changed = 1;
  UFG::TargetingSystemPedBaseComponent::OnDetach(this);
}

// File Line: 5137
// RVA: 0x54DA20
void __fastcall UFG::TargetingSystemPedPlayerComponent::SetOverrideDesiredFocusMode(
        UFG::TargetingSystemPedPlayerComponent *this,
        UFG::eFocusModeEnum eOverrideMode)
{
  this->m_eOverrideDesiredFocusMode = eOverrideMode;
}

