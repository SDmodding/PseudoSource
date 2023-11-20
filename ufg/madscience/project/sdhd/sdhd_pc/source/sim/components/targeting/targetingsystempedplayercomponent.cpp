// File Line: 98
// RVA: 0x1544180
__int64 dynamic_initializer_for__UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList__);
}

// File Line: 99
// RVA: 0x52CBB0
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemPedPlayerComponent::GetDesc(UFG::TargetingSystemPedPlayerComponent *this)
{
  return &UFG::TargetingSystemPedPlayerComponent::_TypeIDesc;
}

// File Line: 103
// RVA: 0x1543B90
__int64 dynamic_initializer_for__UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap__()
{
  signed __int64 v0; // rcx
  __int64 v1; // rax

  v0 = 91i64;
  v1 = UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[v1] = 0;
    v1 = UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.size++ + 1;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap__);
}

// File Line: 192
// RVA: 0x52A670
signed __int64 __fastcall UFG::GetActionMostUsedIndex_Grapple()
{
  signed __int64 result; // rax

  if ( _S35_0 & 1 )
    return index;
  _S35_0 |= 1u;
  if ( !(_S34 & 1) )
  {
    _S34 |= 1u;
    actionID_0.mUID = UFG::qStringHashUpper32("Grapple", 0xFFFFFFFF);
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

  if ( _S37_0 & 1 )
    return index_0;
  _S37_0 |= 1u;
  if ( !(_S36_0 & 1) )
  {
    _S36_0 |= 1u;
    actionID_1.mUID = UFG::qStringHashUpper32("Hostage", 0xFFFFFFFF);
  }
  result = GetMostUsedIndex(actionID_1.mUID);
  index_0 = result;
  return result;
}

// File Line: 194
// RVA: 0x52A510
ActionID *__fastcall UFG::GetActionID_DismountShoot()
{
  if ( !(_S38_0 & 1) )
  {
    _S38_0 |= 1u;
    actionID_2.mUID = UFG::qStringHashUpper32("DismountShoot", 0xFFFFFFFF);
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
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentTargetingSystemPedPlayer.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 353
// RVA: 0x545AD0
UFG::SimComponent *__fastcall UFG::TargetingSystemPedPlayerComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *v7; // rdx
  unsigned __int16 v8; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x2D38ui64, "TargetingSystemPedPlayerComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v1->mpWritableProperties;
    if ( !v4 )
      v4 = v1->mpConstProperties;
    UFG::TargetingSystemPedPlayerComponent::TargetingSystemPedPlayerComponent(
      (UFG::TargetingSystemPedPlayerComponent *)v3,
      v1->m_NameUID,
      v4,
      0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v1->m_pSimObject;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 || (v8 & 0x8000u) != 0 )
    v9 = 20;
  else
    v9 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return v6;
}

// File Line: 369
// RVA: 0x519DC0
void __fastcall UFG::TargetingSystemPedPlayerComponent::TargetingSystemPedPlayerComponent(UFG::TargetingSystemPedPlayerComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::TargetingSystemPedPlayerComponent *v4; // rdi
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *v5; // rbx
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *v6; // ST38_8
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *v7; // ST38_8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v8; // ST38_8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // ST38_8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // ST38_8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // ST38_8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v12; // ST38_8
  signed __int64 v13; // ST38_8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v14; // ST40_8
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *v15; // rax
  char v16; // cl

  v4 = this;
  UFG::TargetingSystemPedBaseComponent::TargetingSystemPedBaseComponent(
    (UFG::TargetingSystemPedBaseComponent *)&this->vfptr,
    &UFG::TargetingSystemPedPlayerComponent::ms_TargetingMap,
    name_uid,
    properties);
  v5 = (UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedPlayerComponent::`vftable{for `UFG::SimComponent};
  v4->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedPlayerComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&v4->m_pCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0>::RebindingComponentHandle<UFG::AimingPlayerComponent,0>(&v4->m_pAimingPlayerComponent);
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::RebindingComponentHandle<UFG::AttackRightsComponent,0>(&v4->m_pAttackRightsComponent);
  v6 = &v4->m_RagdollTarget;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v4->m_RagdollTarget.m_pPointer = 0i64;
  v7 = &v4->m_FocusTargetsGrappleTarget;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v4->m_FocusTargetsGrappleTarget.m_pPointer = 0i64;
  v8 = &v4->m_pVehicleFocusTarget;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v4->m_pVehicleFocusTarget.m_pPointer = 0i64;
  v9 = &v4->m_pFocusModeOverrideSimObject;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v4->m_pFocusModeOverrideSimObject.m_pPointer = 0i64;
  v10 = &v4->m_pOccupantOfVehicle;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v4->m_pOccupantOfVehicle.m_pPointer = 0i64;
  v11 = &v4->m_pVehicleClosestPointSimObject;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v4->m_pVehicleClosestPointSimObject.m_pPointer = 0i64;
  v12 = &v4->m_pVehicleClosestPointTNC;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v4->m_pVehicleClosestPointTNC.m_pPointer = 0i64;
  v13 = (signed __int64)&v4->m_RimLighting;
  *(_BYTE *)v13 = 0;
  *(_DWORD *)(v13 + 4) = 0;
  v14 = &v4->m_RimLighting.m_Target;
  v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v4->m_RimLighting.m_Target.m_pPointer = 0i64;
  `eh vector constructor iterator(
    v4->m_VehicleCharacterRagdolls,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  v4->m_CloseTargetsList.size = 0;
  v15 = UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList.mNode.mPrev;
  UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *)&v4->mPrev;
  v5->mPrev = v15;
  v4->mNext = (UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *)&UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList;
  UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentList.mNode.mPrev = (UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::TargetingSystemPedPlayerComponent::_TargetingSystemPedPlayerComponentTypeUID,
    "TargetingSystemPedPlayerComponent");
  v16 = s_bStaticallyInitialized;
  if ( !s_bStaticallyInitialized )
    v16 = 1;
  s_bStaticallyInitialized = v16;
  UFG::TargetingSystemPedPlayerComponent::initialize(v4);
}

// File Line: 389
// RVA: 0x51D220
void __fastcall UFG::TargetingSystemPedPlayerComponent::~TargetingSystemPedPlayerComponent(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingSystemPedPlayerComponent *v1; // rbx
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *v2; // rdi
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *v3; // rcx
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *v4; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v25; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v30; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *v35; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v38; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *v40; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v43; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v44; // rax
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *v45; // rcx
  UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *v46; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedPlayerComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedPlayerComponent::`vftable{for `UFG::UpdateInterface};
  UFG::TargetingSystemPedPlayerComponent::shutdown(this);
  if ( v1 == UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentpCurrentIterator )
    UFG::TargetingSystemPedPlayerComponent::s_TargetingSystemPedPlayerComponentpCurrentIterator = (UFG::TargetingSystemPedPlayerComponent *)&v1->mPrev[-174].mNext;
  v2 = (UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->m_CloseTargetsList.size = 0;
  `eh vector destructor iterator(
    v1->m_VehicleCharacterRagdolls,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v5 = &v1->m_RimLighting.m_Target;
  if ( v1->m_RimLighting.m_Target.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->m_RimLighting.m_Target.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->m_RimLighting.m_Target.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_RimLighting.m_Target.mPrev;
  }
  v1->m_RimLighting.m_Target.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->m_RimLighting.m_Target.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->m_RimLighting.m_Target.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_RimLighting.m_Target.mPrev;
  v10 = &v1->m_pVehicleClosestPointTNC;
  if ( v1->m_pVehicleClosestPointTNC.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->m_pVehicleClosestPointTNC.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->m_pVehicleClosestPointTNC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pVehicleClosestPointTNC.mPrev;
  }
  v1->m_pVehicleClosestPointTNC.m_pPointer = 0i64;
  v13 = v10->mPrev;
  v14 = v1->m_pVehicleClosestPointTNC.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->m_pVehicleClosestPointTNC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pVehicleClosestPointTNC.mPrev;
  v15 = &v1->m_pVehicleClosestPointSimObject;
  if ( v1->m_pVehicleClosestPointSimObject.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v1->m_pVehicleClosestPointSimObject.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v1->m_pVehicleClosestPointSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pVehicleClosestPointSimObject.mPrev;
  }
  v1->m_pVehicleClosestPointSimObject.m_pPointer = 0i64;
  v18 = v15->mPrev;
  v19 = v1->m_pVehicleClosestPointSimObject.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v1->m_pVehicleClosestPointSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pVehicleClosestPointSimObject.mPrev;
  v20 = &v1->m_pOccupantOfVehicle;
  if ( v1->m_pOccupantOfVehicle.m_pPointer )
  {
    v21 = v20->mPrev;
    v22 = v1->m_pOccupantOfVehicle.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20->mPrev;
    v1->m_pOccupantOfVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pOccupantOfVehicle.mPrev;
  }
  v1->m_pOccupantOfVehicle.m_pPointer = 0i64;
  v23 = v20->mPrev;
  v24 = v1->m_pOccupantOfVehicle.mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20->mPrev;
  v1->m_pOccupantOfVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pOccupantOfVehicle.mPrev;
  v25 = &v1->m_pFocusModeOverrideSimObject;
  if ( v1->m_pFocusModeOverrideSimObject.m_pPointer )
  {
    v26 = v25->mPrev;
    v27 = v1->m_pFocusModeOverrideSimObject.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    v25->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v25->mPrev;
    v1->m_pFocusModeOverrideSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pFocusModeOverrideSimObject.mPrev;
  }
  v1->m_pFocusModeOverrideSimObject.m_pPointer = 0i64;
  v28 = v25->mPrev;
  v29 = v1->m_pFocusModeOverrideSimObject.mNext;
  v28->mNext = v29;
  v29->mPrev = v28;
  v25->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v25->mPrev;
  v1->m_pFocusModeOverrideSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pFocusModeOverrideSimObject.mPrev;
  v30 = &v1->m_pVehicleFocusTarget;
  if ( v1->m_pVehicleFocusTarget.m_pPointer )
  {
    v31 = v30->mPrev;
    v32 = v1->m_pVehicleFocusTarget.mNext;
    v31->mNext = v32;
    v32->mPrev = v31;
    v30->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v30->mPrev;
    v1->m_pVehicleFocusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pVehicleFocusTarget.mPrev;
  }
  v1->m_pVehicleFocusTarget.m_pPointer = 0i64;
  v33 = v30->mPrev;
  v34 = v1->m_pVehicleFocusTarget.mNext;
  v33->mNext = v34;
  v34->mPrev = v33;
  v30->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v30->mPrev;
  v1->m_pVehicleFocusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pVehicleFocusTarget.mPrev;
  v35 = &v1->m_FocusTargetsGrappleTarget;
  if ( v1->m_FocusTargetsGrappleTarget.m_pPointer )
  {
    v36 = v35->mPrev;
    v37 = v1->m_FocusTargetsGrappleTarget.mNext;
    v36->mNext = v37;
    v37->mPrev = v36;
    v35->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v35->mPrev;
    v1->m_FocusTargetsGrappleTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v1->m_FocusTargetsGrappleTarget.mPrev;
  }
  v1->m_FocusTargetsGrappleTarget.m_pPointer = 0i64;
  v38 = v35->mPrev;
  v39 = v1->m_FocusTargetsGrappleTarget.mNext;
  v38->mNext = v39;
  v39->mPrev = v38;
  v35->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v35->mPrev;
  v1->m_FocusTargetsGrappleTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v1->m_FocusTargetsGrappleTarget.mPrev;
  v40 = &v1->m_RagdollTarget;
  if ( v1->m_RagdollTarget.m_pPointer )
  {
    v41 = v40->mPrev;
    v42 = v1->m_RagdollTarget.mNext;
    v41->mNext = v42;
    v42->mPrev = v41;
    v40->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v40->mPrev;
    v1->m_RagdollTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v1->m_RagdollTarget.mPrev;
  }
  v1->m_RagdollTarget.m_pPointer = 0i64;
  v43 = v40->mPrev;
  v44 = v1->m_RagdollTarget.mNext;
  v43->mNext = v44;
  v44->mPrev = v43;
  v40->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v40->mPrev;
  v1->m_RagdollTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v1->m_RagdollTarget.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAttackRightsComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAimingPlayerComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pCharacterAnimationComponent);
  v45 = v2->mPrev;
  v46 = v1->mNext;
  v45->mNext = v46;
  v46->mPrev = v45;
  v2->mPrev = v2;
  v1->mNext = (UFG::qNode<UFG::TargetingSystemPedPlayerComponent,UFG::TargetingSystemPedPlayerComponent> *)&v1->mPrev;
  UFG::TargetingSystemPedBaseComponent::~TargetingSystemPedBaseComponent((UFG::TargetingSystemPedBaseComponent *)&v1->vfptr);
}

// File Line: 397
// RVA: 0x15499C0
__int64 UFG::_dynamic_initializer_for__driverFaceActionSceneObjectSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("object-physical-character-taxi_driver_faceaction", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::driverFaceActionSceneObjectSymbol, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__driverFaceActionSceneObjectSymbol__);
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
  UFG::TargetingSystemPedPlayerComponent *v1; // rdi
  UFG::SimComponent *v2; // rsi
  UFG::qVector3 *v3; // r15
  float v4; // xmm1_4
  float v5; // xmm2_4
  UFG::qVector3 *v6; // r12
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  UFG::qMemoryPool *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::FaceActionComponent *v13; // rax
  UFG::FaceActionComponent *v14; // r14
  UFG::SceneObjectProperties *v15; // rbx
  UFG::SceneObjectProperties *v16; // rax
  UFG::qPropertySet *v17; // r14
  unsigned int v18; // ebx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v19; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v20; // rax
  UFG::qMemoryPool *v21; // rax
  UFG::allocator::free_link *v22; // rax
  UFG::SimObject *v23; // rax
  UFG::SimObject *v24; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v25; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qMemoryPool *v29; // rax
  UFG::allocator::free_link *v30; // rax
  UFG::SimComponent *v31; // rax
  UFG::SimObject *v32; // rdx
  unsigned __int16 v33; // cx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v34; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rax
  unsigned __int8 v38; // cl
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v39; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v40; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v41; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v42; // rax
  TracksEnumBinding<unsigned long> v43; // [rsp+38h] [rbp-41h]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+58h] [rbp-21h]
  UFG::SimObjectModifier v45; // [rsp+78h] [rbp-1h]
  UFG::qSymbol result; // [rsp+E0h] [rbp+67h]
  UFG::qSymbol name; // [rsp+E8h] [rbp+6Fh]
  UFG::allocator::free_link *v48; // [rsp+F0h] [rbp+77h]

  v1 = this;
  *(_QWORD *)&this->m_bIsAimingActive = 0i64;
  *(_DWORD *)&this->m_bFocusTargetIsHostile = 0;
  this->m_bTargetingFreeAimAssistance = 0;
  v2 = 0i64;
  *(_QWORD *)&this->m_eOverrideDesiredFocusMode = 0i64;
  *(_QWORD *)&this->m_eFocusMode = 0i64;
  this->m_fTargetingIntentionIdleTime = 1000.0;
  v3 = &this->m_vDirectionalTargetingIntention;
  v4 = UFG::qVector3::msAxisX.y;
  v5 = UFG::qVector3::msAxisX.z;
  v3->x = UFG::qVector3::msAxisX.x;
  v3->y = v4;
  v3->z = v5;
  v6 = &this->m_vAimTargetingIntention;
  v7 = UFG::qVector3::msAxisX.y;
  v8 = UFG::qVector3::msAxisX.z;
  v6->x = UFG::qVector3::msAxisX.x;
  v6->y = v7;
  v6->z = v8;
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
                                           (UFG::qSymbol *)&UFG::driverFaceActionSceneObjectSymbol.mUID,
                                           0i64,
                                           (UFG::qSymbol *)&UFG::driverFaceActionSceneObjectSymbol.mUID);
  v11 = UFG::GetSimulationMemoryPool();
  v12 = UFG::qMemoryPool::Allocate(v11, 0x520ui64, "FaceActionComponent", 0i64, 1u);
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
  v1->m_pDriverFaceActionComponent = v14;
  v15 = v1->m_pDriverSceneObjectProperties;
  UFG::FaceActionComponent::ResetState(v14);
  v14->vfptr[12].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v14->vfptr, (unsigned int)v15);
  v1->m_pDriverFaceActionComponent->m_Flags &= 0xFFF7u;
  v16 = v1->m_pDriverSceneObjectProperties;
  v17 = v16->mpWritableProperties;
  if ( !v17 )
    v17 = v16->mpConstProperties;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  v18 = -1;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)UFG::qPropertySet::Get<UFG::qSymbol>(
                                                   v17,
                                                   (UFG::qSymbol *)&SimSym_FaceAction.mUID,
                                                   DEPTH_RECURSE)->mUID;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gFaceActionTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gFaceActionTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    v19 = UFG::gFaceActionTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gFaceActionTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v19;
    pTrackEnumBinding.mNext = &UFG::gFaceActionTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gFaceActionTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v1->m_eDriverFaceActionType = pTrackEnumBinding.m_EnumValue;
  v43.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v43;
  v43.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v43;
  v43.m_EnumSymbol.mUID = -1;
  v43.m_EnumSymbol = (UFG::qSymbol)UFG::qPropertySet::Get<UFG::qSymbol>(
                                     v17,
                                     (UFG::qSymbol *)&SimSym_SellableItem.mUID,
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
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v43;
    v43.mPrev = v20;
    v43.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v43;
  }
  v1->m_eDriverSellableItemType = v43.m_EnumValue;
  v1->m_eDriverOriginalSellableItemType = 0;
  v1->m_ConeToIntentionMap[0] = &v1->m_vTargetingIntention;
  v1->m_ConeToIntentionMap[2] = &v1->m_vTargetingIntention;
  v1->m_ConeToIntentionMap[3] = &v1->m_vTargetingIntention;
  v1->m_ConeToIntentionMap[4] = &v1->m_vTargetingIntention;
  v1->m_ConeToIntentionMap[1] = v6;
  v1->m_ConeToIntentionMap[5] = v3;
  v1->m_fMinimumTargetDistanceSquared = 2500.0;
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
  v25 = &v1->m_pVehicleClosestPointSimObject;
  if ( v1->m_pVehicleClosestPointSimObject.m_pPointer )
  {
    v26 = v25->mPrev;
    v27 = v1->m_pVehicleClosestPointSimObject.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    v25->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v25->mPrev;
    v1->m_pVehicleClosestPointSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pVehicleClosestPointSimObject.mPrev;
  }
  v1->m_pVehicleClosestPointSimObject.m_pPointer = v24;
  if ( v24 )
  {
    v28 = v24->m_SafePointerList.mNode.mPrev;
    v28->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v25->mPrev;
    v25->mPrev = v28;
    v1->m_pVehicleClosestPointSimObject.mNext = &v24->m_SafePointerList.mNode;
    v24->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v25->mPrev;
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
  UFG::Simulation::TrackSimObject(&UFG::gSim, v1->m_pVehicleClosestPointSimObject.m_pPointer);
  v32 = v1->m_pVehicleClosestPointSimObject.m_pPointer;
  v33 = v32->m_Flags;
  if ( (v33 >> 14) & 1 )
  {
    v18 = 2;
  }
  else if ( (v33 & 0x8000u) == 0 )
  {
    if ( (v33 >> 13) & 1 )
    {
      v18 = 2;
    }
    else if ( (v33 >> 12) & 1 )
    {
      v18 = 1;
    }
  }
  else
  {
    v18 = 2;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v45, v32, 1);
  UFG::SimObjectModifier::AttachComponent(&v45, v2, v18);
  UFG::SimObjectModifier::Close(&v45);
  UFG::SimObjectModifier::~SimObjectModifier(&v45);
  v34 = &v1->m_pVehicleClosestPointTNC;
  if ( v1->m_pVehicleClosestPointTNC.m_pPointer )
  {
    v35 = v34->mPrev;
    v36 = v1->m_pVehicleClosestPointTNC.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    v34->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v34->mPrev;
    v1->m_pVehicleClosestPointTNC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pVehicleClosestPointTNC.mPrev;
  }
  v1->m_pVehicleClosestPointTNC.m_pPointer = v2;
  if ( v2 )
  {
    v37 = v2->m_SafePointerList.mNode.mPrev;
    v37->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v34->mPrev;
    v34->mPrev = v37;
    v1->m_pVehicleClosestPointTNC.mNext = &v2->m_SafePointerList.mNode;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v34->mPrev;
  }
  if ( v1->m_pAimingPlayerComponent.m_pSimComponent )
  {
    v38 = v1->m_pTargetingMap->m_Map.p[3];
    if ( v38 )
      UFG::TargetingSimObject::SetTarget(
        &v1->m_pTargets[v38],
        (UFG::SimObject *)v1->m_pAimingPlayerComponent.m_pSimComponent[13].m_BoundComponentHandles.mNode.mPrev);
  }
  v39 = v43.mPrev;
  v40 = v43.mNext;
  v43.mPrev->mNext = v43.mNext;
  v40->mPrev = v39;
  v41 = pTrackEnumBinding.mPrev;
  v42 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v42->mPrev = v41;
}es.mNode.mPrev);
  }
  v39 = v43.mPrev;
  v40 = v43.mNext;
  v43.mPrev->mNext = v43.mNext;
  v40->mPrev = v39;
  v41 = pTrackEnumBinding.mPrev;
  v42 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding

// File Line: 488
// RVA: 0x56D740
void __fastcall UFG::TargetingSystemPedPlayerComponent::shutdown(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingSystemPedPlayerComponent *v1; // rbx
  UFG::FaceActionComponent *v2; // rcx
  UFG::SceneObjectProperties *v3; // rcx
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::SimObject *v16; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v17; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax

  v1 = this;
  if ( this->m_pDriverFaceActionComponent->m_Flags & 1 )
    UFG::TargetingSystemPedPlayerComponent::deattachTransitDriverFaceComponent(this);
  v2 = v1->m_pDriverFaceActionComponent;
  if ( v2 )
    v2->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v2->vfptr, 1u);
  v3 = v1->m_pDriverSceneObjectProperties;
  v1->m_pDriverFaceActionComponent = 0i64;
  UFG::SceneObjectProperties::Deactivate(v3);
  v4 = &v1->m_RagdollTarget;
  v1->m_pDriverSceneObjectProperties = 0i64;
  if ( v1->m_RagdollTarget.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v1->m_RagdollTarget.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v1->m_RagdollTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v1->m_RagdollTarget.mPrev;
  }
  v1->m_RagdollTarget.m_pPointer = 0i64;
  v7 = &v1->m_pVehicleFocusTarget;
  v1->m_RimLighting.m_bEnabled = 0;
  if ( v1->m_pVehicleFocusTarget.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pVehicleFocusTarget.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pVehicleFocusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pVehicleFocusTarget.mPrev;
  }
  v1->m_pVehicleFocusTarget.m_pPointer = 0i64;
  v10 = &v1->m_pFocusModeOverrideSimObject;
  if ( v1->m_pFocusModeOverrideSimObject.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->m_pFocusModeOverrideSimObject.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->m_pFocusModeOverrideSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pFocusModeOverrideSimObject.mPrev;
  }
  v1->m_pFocusModeOverrideSimObject.m_pPointer = 0i64;
  v13 = &v1->m_pOccupantOfVehicle;
  if ( v1->m_pOccupantOfVehicle.m_pPointer )
  {
    v14 = v13->mPrev;
    v15 = v1->m_pOccupantOfVehicle.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v1->m_pOccupantOfVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pOccupantOfVehicle.mPrev;
  }
  v1->m_pOccupantOfVehicle.m_pPointer = 0i64;
  v16 = v1->m_pVehicleClosestPointSimObject.m_pPointer;
  v1->m_CloseTargetsList.size = 0;
  if ( v16 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, v16);
    v17 = &v1->m_pVehicleClosestPointSimObject;
    if ( v17->m_pPointer )
    {
      v18 = v17->mPrev;
      v19 = v17->mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v17->mPrev;
      v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    }
    v17->m_pPointer = 0i64;
  }
}

// File Line: 518
// RVA: 0x55F170
void __fastcall UFG::TargetingSystemPedPlayerComponent::UpdateCommon(UFG::TargetingSystemPedPlayerComponent *this, float fDeltaS)
{
  UFG::TargetingSystemPedPlayerComponent *v2; // rbx
  UFG::SimObject *v3; // rdi
  UFG::SimComponent *v4; // rax
  __int64 v5; // rcx
  signed int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  UFG::SimComponent *v10; // rax
  UFG::SimObject *v11; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  int v16; // edi
  UFG::SimComponent *v17; // rax
  UFG::Controller *v18; // rax
  UFG::InputActionData *v19; // rcx
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  UFG::InputActionData *v23; // rcx
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm4_4
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  bool v29; // al
  bool v30; // cl
  bool v31; // di
  bool v32; // cl

  v2 = this;
  if ( !(_S40 & 1) )
  {
    _S40 |= 1u;
    UFG::qSymbolUC::create_from_string(&symBip01Head, "Bip01 Head");
    atexit(UFG::TargetingSystemPedPlayerComponent::UpdateCommon_::_2_::_dynamic_atexit_destructor_for__symBip01Head__);
  }
  v3 = v2->m_pSimObject;
  UFG::TargetingSystemPedBaseComponent::UpdateCommon((UFG::TargetingSystemPedBaseComponent *)&v2->vfptr);
  if ( v2->m_iVisibilityFromBoneID < 0 )
  {
    if ( v2->m_pCharacterAnimationComponent.m_pSimComponent )
    {
      v4 = v2->m_pCharacterAnimationComponent.m_pSimComponent;
      if ( *(_QWORD *)&v4[2].m_TypeUID )
      {
        v5 = *(_QWORD *)&v4[2].m_TypeUID;
        if ( *(_QWORD *)(v5 + 440) )
          v6 = Skeleton::GetBoneID(*(Skeleton **)(v5 + 480), symBip01Head.mUID);
        else
          v6 = -1;
        v2->m_iVisibilityFromBoneID = v6;
      }
    }
  }
  *(_WORD *)&v2->m_bIsAimingActive = 0;
  if ( v2->m_pActionTreeComponent.m_pSimComponent )
  {
    v7 = _S40;
    if ( !(_S40 & 2) )
    {
      _S40 |= 2u;
      UID_VaultActions.mUID = UFG::qStringHashUpper32("VaultActions", 0xFFFFFFFF);
      v7 = _S40;
    }
    if ( v7 & 4 )
    {
      v8 = mostUsed_VaultActions;
    }
    else
    {
      _S40 = v7 | 4;
      v8 = GetMostUsedIndex(UID_VaultActions.mUID);
      mostUsed_VaultActions = v8;
    }
    v2->m_bIsTransitionalAttackActive = ActionController::IsPlaying(
                                          (ActionController *)&v2->m_pActionTreeComponent.m_pSimComponent[3],
                                          &UID_VaultActions,
                                          v8,
                                          1);
    v9 = _S40;
    if ( !(_S40 & 8) )
    {
      _S40 |= 8u;
      UID_Aim.mUID = UFG::qStringHashUpper32("Aim", 0xFFFFFFFF);
      v9 = _S40;
    }
    if ( !(v9 & 0x10) )
    {
      _S40 = v9 | 0x10;
      mostUsed_Aim = GetMostUsedIndex(UID_Aim.mUID);
      v9 = _S40;
    }
    if ( !(v9 & 0x20) )
    {
      _S40 = v9 | 0x20;
      UID_Aiming.mUID = UFG::qStringHashUpper32("Aiming", 0xFFFFFFFF);
      v9 = _S40;
    }
    if ( !(v9 & 0x40) )
    {
      _S40 = v9 | 0x40;
      mostUsed_Aiming = GetMostUsedIndex(UID_Aiming.mUID);
      v9 = _S40;
    }
    if ( (v9 & 0x80u) == 0 )
    {
      _S40 = v9 | 0x80;
      UID_VaultAim.mUID = UFG::qStringHashUpper32("VaultAim", 0xFFFFFFFF);
      v9 = _S40;
    }
    if ( !_bittest((const signed int *)&v9, 8u) )
    {
      _S40 = v9 | 0x100;
      mostUsed_VaultAim = GetMostUsedIndex(UID_VaultAim.mUID);
    }
    if ( ActionController::IsPlaying(
           (ActionController *)&v2->m_pActionTreeComponent.m_pSimComponent[3],
           &UID_Aim,
           mostUsed_Aim,
           1)
      || ActionController::IsPlaying(
           (ActionController *)&v2->m_pActionTreeComponent.m_pSimComponent[3],
           &UID_Aiming,
           mostUsed_Aiming,
           1)
      || ActionController::IsPlaying(
           (ActionController *)&v2->m_pActionTreeComponent.m_pSimComponent[3],
           &UID_VaultAim,
           mostUsed_VaultAim,
           1) )
    {
      v2->m_bIsAimingActive = 1;
    }
  }
  if ( v3 && (v10 = v3->m_Components.p[44].m_pComponent) != 0i64 && v10[1].m_BoundComponentHandles.mNode.mPrev )
    v11 = (UFG::SimObject *)v10[1].m_BoundComponentHandles.mNode.mPrev[2].mNext;
  else
    v11 = 0i64;
  v12 = &v2->m_pOccupantOfVehicle;
  if ( v2->m_pOccupantOfVehicle.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v2->m_pOccupantOfVehicle.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v2->m_pOccupantOfVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->m_pOccupantOfVehicle.mPrev;
  }
  v2->m_pOccupantOfVehicle.m_pPointer = v11;
  if ( v11 )
  {
    v15 = v11->m_SafePointerList.mNode.mPrev;
    v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v12->mPrev = v15;
    v2->m_pOccupantOfVehicle.mNext = &v11->m_SafePointerList.mNode;
    v11->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  }
  v16 = 0;
  v17 = v2->m_pAICharacterControllerComponent.m_pSimComponent;
  if ( v17 )
    v16 = (int)v17[17].m_SafePointerList.mNode.mPrev;
  v18 = UFG::InputSystem::AcquireController(UFG::gInputSystem, v16);
  if ( v18 && v18->m_IsKeyboardController )
  {
    v19 = UFG::ActionDef_Mouse.mDataPerController[v16];
    v20 = 0.0;
    if ( v19 )
    {
      v21 = v19->mAxisPositionX;
      v22 = v19->mAxisPositionY;
    }
    else
    {
      v21 = 0.0;
      v22 = 0.0;
    }
    v2->m_bAimInputRaw = 1;
  }
  else
  {
    v23 = UFG::ActionDef_AimLocation.mDataPerController[v16];
    v20 = 0.0;
    if ( v23 )
    {
      v21 = v23->mAxisPositionX;
      v22 = v23->mAxisPositionY;
    }
    else
    {
      v21 = 0.0;
      v22 = 0.0;
    }
    v2->m_bAimInputRaw = 0;
  }
  LODWORD(v24) = LODWORD(v22) ^ _xmm[0];
  v2->m_vAimInput.x = v21;
  v2->m_vAimInput.y = v24;
  v25 = fsqrt((float)(v24 * v24) + (float)(v21 * v21));
  v2->m_fAimInputLength = v25;
  if ( v25 <= 0.00000011920929 )
  {
    v2->m_vAimInputDir = (UFG::qVector2)1065353216i64;
  }
  else
  {
    v26 = v2->m_vAimInput.y;
    v27 = (__m128)LODWORD(v2->m_vAimInput.x);
    v28 = v27;
    v28.m128_f32[0] = (float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v26 * v26);
    if ( v28.m128_f32[0] != 0.0 )
      v20 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v28));
    v2->m_vAimInputDir.x = v27.m128_f32[0] * v20;
    v2->m_vAimInputDir.y = v26 * v20;
  }
  v29 = 0.00000011920929 < v2->m_fAimInputLength;
  v30 = v2->m_bHasAimInput;
  v31 = !v30 && v2->m_fAimInputLength > 0.00000011920929;
  v32 = v30 && v2->m_fAimInputLength <= 0.00000011920929;
  v2->m_bHasNoAimInputTransition = v32;
  v2->m_bHasAimInput = v29;
  if ( v2->m_fAimInputLength < 0.89999998 )
  {
    *(_WORD *)&v2->m_bHasFullAimInput = 0;
  }
  else
  {
    v2->m_bHasFullAimInputTransition = v2->m_bHasFullAimInput == 0;
    v2->m_bHasFullAimInput = 1;
  }
  v2->m_bIsInAnyCombat = UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(
                           UFG::LocalPlayerIsInCombatManager::s_pInstance,
                           0);
  if ( v31 )
    v2->m_fTimeSinceStartedInput = 0.0;
  else
    v2->m_fTimeSinceStartedInput = UFG::Metrics::msInstance.mSimTimeUnscaledDelta + v2->m_fTimeSinceStartedInput;
}

// File Line: 671
// RVA: 0x571250
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateDesiredFocusMode(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *v1; // r8
  UFG::eFocusModeEnum v2; // esi
  unsigned __int8 v3; // bp
  unsigned __int8 v4; // di
  UFG::TargetingSystemPedPlayerComponent *v5; // rbx
  __int64 v6; // r11
  __int64 v7; // r9
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  bool v11; // dl
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  UFG::eFocusModeEnum v15; // eax
  UFG::GameStatTracker *v16; // rax
  int v17; // eax
  UFG::eFocusModeEnum v18; // ecx
  UFG::SimComponent *v19; // rax
  float v20; // xmm1_4
  UFG::eFocusModeEnum v21; // eax
  UFG::eFocusModeEnum v22; // ecx

  v1 = this->m_pAICharacterControllerBaseComponent.m_pSimComponent;
  v2 = this->m_eDesiredFocusMode;
  v3 = 0;
  v4 = 0;
  v5 = this;
  this->m_bFocusModeJustRequested = 0;
  if ( v1 )
  {
    v6 = (signed int)gActionRequest_TargetingFreeAimAssistance.m_EnumValue;
    v7 = (signed int)gActionRequest_Grab.m_EnumValue;
    v8 = *((_QWORD *)&v1[4].m_BoundComponentHandles.mNode.mPrev
         + ((signed __int64)(signed int)gActionRequest_Focus.m_EnumValue >> 6));
    v3 = _bittest64(&v8, gActionRequest_Focus.m_EnumValue & 0x3F);
    v9 = *((_QWORD *)&v1[4].m_BoundComponentHandles.mNode.mPrev
         + ((signed __int64)(signed int)gActionRequest_Focus_Lock.m_EnumValue >> 6));
    v4 = _bittest64(&v9, gActionRequest_Focus_Lock.m_EnumValue & 0x3F);
    v11 = 0;
    if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      v10 = *((_QWORD *)&v1[4].m_BoundComponentHandles.mNode.mPrev
            + ((signed __int64)(signed int)gActionRequest_TargetingAutoAcquisition.m_EnumValue >> 6));
      if ( _bittest64(&v10, gActionRequest_TargetingAutoAcquisition.m_EnumValue & 0x3F) )
        v11 = 1;
    }
    v12 = *((_QWORD *)&v1[4].m_BoundComponentHandles.mNode.mPrev
          + ((signed __int64)(signed int)gActionRequest_TargetingFreeShootingDesired.m_EnumValue >> 6));
    this->m_bTargetingFreeShootingDesired = _bittest64(
                                              &v12,
                                              gActionRequest_TargetingFreeShootingDesired.m_EnumValue & 0x3F);
    v13 = *((_QWORD *)&v1[4].m_BoundComponentHandles.mNode.mPrev + (v6 >> 6));
    this->m_bTargetingFreeAimAssistance = _bittest64(&v13, v6 & 0x3F);
    this->m_bTargetAutoAcquisitionJustRequested = v11 && !this->m_bTargetAutoAcquisition;
    v14 = *((_QWORD *)&v1[4].m_BoundComponentHandles.mNode.mPrev + (v7 >> 6));
    if ( _bittest64(&v14, v7 & 0x3F) )
      this->m_bIsInAnyCombat = 0;
    this->m_bTargetAutoAcquisition = v11;
  }
  else
  {
    *(_DWORD *)&this->m_bTargetAutoAcquisition = 0;
  }
  v15 = this->m_eOverrideDesiredFocusMode;
  if ( v15 )
  {
    this->m_eDesiredFocusMode = v15;
    goto LABEL_49;
  }
  v16 = UFG::GameStatTracker::Instance();
  v17 = (unsigned __int64)UFG::GameStatTracker::GetStat(v16, AimMode) - 1;
  if ( v17 )
  {
    if ( v17 == 1 )
      v4 = 0;
  }
  else if ( v3 )
  {
    v4 = 1;
  }
  if ( v5->m_bTargetingFreeShootingDesired )
  {
    v5->m_eDesiredFocusMode = 3;
    goto LABEL_49;
  }
  if ( v3 )
  {
    if ( v4 || !v5->m_bHasRangedWeapon )
    {
      v5->m_eDesiredFocusMode = 1;
    }
    else if ( v2 )
    {
      if ( v5->m_eFocusMode == eFOCUS_MODE_FREE_AIMING_LOCKED )
      {
        v5->m_eDesiredFocusMode = eFOCUS_MODE_FREE_AIMING_LOCKED;
      }
      else if ( v5->m_bHasAimInput || v5->m_bHasNoAimInputTransition || v2 == 2 )
      {
        v5->m_eDesiredFocusMode = eFOCUS_MODE_LOCKED_SOFT;
      }
      else
      {
        v5->m_eDesiredFocusMode = eFOCUS_MODE_FREE_AIMING;
      }
    }
    else
    {
      v5->m_eDesiredFocusMode = 2;
      UFG::AimingPlayerComponent::SnapAccuracy(
        (UFG::AimingPlayerComponent *)v5->m_pAimingPlayerComponent.m_pSimComponent,
        1.0);
    }
    v18 = v5->m_eDesiredFocusMode;
    if ( (unsigned int)(v18 - 1) <= 1 )
    {
      if ( v2 != v18 )
        goto LABEL_43;
      if ( UFG::TargetingSystemPedPlayerComponent::ms_bSoftLockOnNoInputTransition )
      {
        if ( !v5->m_bHasNoAimInputTransition )
          goto LABEL_49;
        goto LABEL_43;
      }
      if ( UFG::TargetingSystemPedPlayerComponent::ms_bSoftLockOnNoInput && !v5->m_bHasAimInput )
      {
LABEL_43:
        v5->m_bFocusModeJustRequested = 1;
        goto LABEL_49;
      }
    }
  }
  else
  {
    if ( v5->m_eFocusMode )
    {
      v19 = v5->m_pEquippedSOWPC.m_pPointer;
      if ( v19 )
      {
        v20 = *(float *)(*((_QWORD *)&v19[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v19[2].m_pSimObject))
                       + 408i64);
        if ( v20 < 0.0 )
          *(float *)&v5->m_pAimingPlayerComponent.m_pSimComponent[1].m_NameUID = v20;
      }
    }
    v5->m_eDesiredFocusMode = 0;
  }
LABEL_49:
  v21 = v5->m_eFocusMode;
  v22 = v5->m_eDesiredFocusMode;
  v5->m_eFocusMode = v22;
  if ( v21 == eFOCUS_MODE_NONE && v22 && !v5->m_pFocusModeOverrideSimObject.m_pPointer )
    UFG::TargetingSystemBaseComponent::ClearTarget((UFG::TargetingSystemBaseComponent *)&v5->vfptr, eTARGET_TYPE_FOCUS);
}

// File Line: 899
// RVA: 0x54D100
void __fastcall UFG::TargetingSystemPedPlayerComponent::SetFocusMode(UFG::TargetingSystemPedPlayerComponent *this, UFG::eFocusModeEnum eFocusMode)
{
  this->m_eDesiredFocusMode = eFocusMode;
  this->m_eFocusMode = eFocusMode;
}

// File Line: 908
// RVA: 0x5795F0
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateTargetingIntentions(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingSystemPedPlayerComponent *v1; // rbx
  UFG::SimComponent *v2; // rdi
  UFG::eFocusModeEnum v3; // ecx
  bool v4; // al
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  signed __int64 v8; // rcx
  UFG::TargetingSimObject *v9; // rax
  bool v10; // dl
  UFG::SimObject *v11; // rdx
  UFG::TransformNodeComponent *v12; // rcx
  float v13; // xmm1_4
  UFG::eFocusModeEnum v14; // eax
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  signed __int64 v19; // rcx
  float v20; // xmm0_4
  float v21; // xmm1_4
  UFG::SimObject *v22; // rcx
  float v23; // xmm2_4
  float v24; // xmm1_4
  UFG::BaseCameraComponent *v25; // rax
  signed __int64 v26; // rax
  float v27; // xmm11_4
  float v28; // xmm4_4
  __m128 v29; // xmm5
  float v30; // xmm6_4
  __m128 v31; // xmm7
  __m128 v32; // xmm1
  float v33; // xmm0_4
  __m128 v34; // xmm3
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  float v40; // xmm6_4
  float v41; // xmm3_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  __m128 v44; // xmm4
  float v45; // xmm5_4
  __m128 v46; // xmm2
  float v47; // xmm2_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  UFG::BaseCameraComponent *v50; // rax
  signed __int64 v51; // rax
  int v52; // xmm1_4
  float v53; // xmm3_4
  __m128 v54; // xmm4
  float v55; // xmm5_4
  __m128 v56; // xmm2
  float v57; // xmm9_4
  UFG::qVector3 n2; // [rsp+20h] [rbp-71h]
  UFG::qVector3 n1; // [rsp+30h] [rbp-61h]
  UFG::qMatrix44 matSimObject; // [rsp+48h] [rbp-49h]

  v1 = this;
  v2 = 0i64;
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
    v2 = this->m_pAICharacterControllerBaseComponent.m_pSimComponent + 2;
  v3 = this->m_eFocusMode;
  if ( (unsigned int)(v3 - 2) <= 2 )
  {
    v4 = v1->m_bHasAimInput;
    v1->m_bHasFreeAimInput = v4;
    if ( v3 == 4 )
    {
      if ( !v4 )
        goto LABEL_72;
      if ( _S41_0 & 1 )
      {
        v5 = s_fMinimumInputDifferenceSquared;
      }
      else
      {
        _S41_0 |= 1u;
        v5 = FLOAT_0_25;
        s_fMinimumInputDifferenceSquared = FLOAT_0_25;
      }
      v6 = v1->m_vLockedFreeAimInput.y;
      v7 = v1->m_vLockedFreeAimInput.x;
      if ( (float)((float)(v7 * v7) + (float)(v6 * v6)) <= 0.0 )
        v5 = 0.0;
      if ( (float)((float)((float)(v1->m_vAimInput.y - v6) * (float)(v1->m_vAimInput.y - v6))
                 + (float)((float)(v1->m_vAimInput.x - v7) * (float)(v1->m_vAimInput.x - v7))) <= v5 )
      {
        v1->m_bHasFreeAimInput = 0;
      }
      else
      {
LABEL_72:
        v1->m_eFocusMode = 3;
        v1->m_eDesiredFocusMode = 3;
      }
    }
  }
  else
  {
    v1->m_bHasFreeAimInput = 0;
  }
  v1->m_fTargetingIntentionIdleTime = UFG::Metrics::msInstance.mSimTimeUnscaledDelta + v1->m_fTargetingIntentionIdleTime;
  v8 = (unsigned __int8)v1->m_pTargetingMap->m_Map.p[22];
  v9 = v1->m_pTargets;
  v10 = v9[v8].m_pTarget.m_pPointer && v9[v8].m_bLock;
  if ( v1->m_eDesiredFocusMode != 1 || !v10 )
  {
    if ( v1->m_pOccupantOfVehicle.m_pPointer
      || v1->m_bIsTransitionalAttackActive && v1->m_bHasRangedWeapon
      || (v14 = v1->m_eFocusMode, v14 == 2) )
    {
      v25 = UFG::Director::Get()->mCurrentCamera;
      if ( v25 )
        v26 = (signed __int64)&v25->mCamera;
      else
        v26 = 0i64;
      LODWORD(v23) = *(_DWORD *)(v26 + 160) ^ _xmm[0];
      LODWORD(v24) = *(_DWORD *)(v26 + 164) ^ _xmm[0];
    }
    else
    {
      if ( v14 == 1 && !v1->m_bFocusModeJustRequested )
      {
        v15 = v1->m_vTargetingForward.y;
        v16 = v1->m_vTargetingForward.z;
        v1->m_vTargetingIntention.x = v1->m_vTargetingForward.x;
        v1->m_vTargetingIntention.y = v15;
        v1->m_vTargetingIntention.z = v16;
        goto LABEL_44;
      }
      if ( !v2 )
      {
LABEL_44:
        v27 = v1->m_pActiveTargetingProfile->m_fHalfHorizontalIntentionLimiter;
        if ( v27 < 3.1415927 )
        {
          v28 = v1->m_vTargetingForward.x;
          v29 = (__m128)LODWORD(v1->m_vTargetingForward.y);
          n1.z = 0.0;
          v30 = v1->m_vTargetingIntention.x;
          v31 = (__m128)LODWORD(v1->m_vTargetingIntention.y);
          n2.z = 0.0;
          v32 = v29;
          v32.m128_f32[0] = (float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v28 * v28);
          if ( v32.m128_f32[0] > 0.001 )
          {
            v34 = v31;
            v33 = v30 * v30;
            v34.m128_f32[0] = (float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30);
            if ( v34.m128_f32[0] > 0.001 )
            {
              if ( v32.m128_f32[0] == 0.0 )
              {
                v35 = 0.0;
              }
              else
              {
                LODWORD(v33) = (unsigned __int128)_mm_sqrt_ps(v32);
                v35 = 1.0 / v33;
              }
              n1.x = v28 * v35;
              n1.y = v29.m128_f32[0] * v35;
              n1.z = v35 * 0.0;
              if ( v34.m128_f32[0] == 0.0 )
              {
                v36 = 0.0;
              }
              else
              {
                LODWORD(v33) = (unsigned __int128)_mm_sqrt_ps(v34);
                v36 = 1.0 / v33;
              }
              n2.x = v30 * v36;
              n2.y = v31.m128_f32[0] * v36;
              n2.z = v36 * 0.0;
              UFG::qAngleBetweenNormals(&n1, &n2);
              v37 = v33 - v27;
              if ( (float)(v33 - v27) > 0.0 )
              {
                if ( (float)((float)((float)(v1->m_vTargetingLeft.y * n2.y) + (float)(v1->m_vTargetingLeft.x * n2.x))
                           + (float)(n2.z * 0.0)) > 0.0 )
                  LODWORD(v37) ^= _xmm[0];
                UFG::qRotationMatrixZ(&matSimObject, v37);
                v38 = v1->m_vTargetingIntention.y;
                v39 = v1->m_vTargetingIntention.x;
                v40 = v1->m_vTargetingIntention.z;
                v41 = (float)((float)(matSimObject.v0.y * v39) + (float)(matSimObject.v1.y * v38))
                    + (float)(matSimObject.v2.y * v40);
                v42 = (float)((float)(matSimObject.v0.z * v39) + (float)(matSimObject.v1.z * v38))
                    + (float)(matSimObject.v2.z * v40);
                v1->m_vTargetingIntention.x = (float)((float)(matSimObject.v0.x * v39) + (float)(matSimObject.v1.x * v38))
                                            + (float)(matSimObject.v2.x * v40);
                v1->m_vTargetingIntention.y = v41;
                v1->m_vTargetingIntention.z = v42;
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
        v1->m_vTargetingIntention.x = *((float *)&v2->m_SafePointerList.mNode.mNext + 1);
        v1->m_vTargetingIntention.y = v17;
        v1->m_vTargetingIntention.z = v18;
        v1->m_fTargetingIntentionIdleTime = 0.0;
        goto LABEL_44;
      }
      v19 = (signed __int64)&v1->m_TargetSteerToTaskList.mNode.mNext[-3].mNext;
      v20 = v1->m_vTargetingForward.y;
      v21 = v1->m_vTargetingForward.z;
      v1->m_vTargetingIntention.x = v1->m_vTargetingForward.x;
      v1->m_vTargetingIntention.y = v20;
      v1->m_vTargetingIntention.z = v21;
      if ( (UFG::SimObject **)v19 == &v1->m_pInterestPointUserComponent.m_pSimObject )
        goto LABEL_44;
      if ( v1->m_TargetSteerToTaskList.mNode.mNext == (UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *)40 )
        goto LABEL_44;
      v22 = v1->m_pTargets[(unsigned __int8)v1->m_pTargetingMap->m_Map.p[SBYTE4(v1->m_TargetSteerToTaskList.mNode.mNext[-1].mPrev[4].mNext)]].m_pTarget.m_pPointer;
      if ( !v22 )
        goto LABEL_44;
      UFG::TargetingSystemBaseComponent::FindMatrix(v22->m_pTransformNodeComponent, v22, &matSimObject);
      v23 = matSimObject.v3.x - v1->m_vTargetingPosition.x;
      v24 = matSimObject.v3.y - v1->m_vTargetingPosition.y;
    }
    v1->m_vTargetingIntention.x = v23;
    v1->m_vTargetingIntention.y = v24;
    v1->m_vTargetingIntention.z = 0.0;
    goto LABEL_44;
  }
  v11 = v9[v8].m_pTarget.m_pPointer;
  v12 = 0i64;
  if ( v11 )
    v12 = v11->m_pTransformNodeComponent;
  UFG::TargetingSystemBaseComponent::FindMatrix(v12, v11, &matSimObject);
  v13 = matSimObject.v3.y - v1->m_vTargetingPosition.y;
  v1->m_vTargetingIntention.x = matSimObject.v3.x - v1->m_vTargetingPosition.x;
  v1->m_vTargetingIntention.y = v13;
  v1->m_vTargetingIntention.z = 0.0;
  if ( v1->m_pOccupantOfVehicle.m_pPointer )
    goto LABEL_44;
LABEL_57:
  v1->m_vTargetingIntention.z = 0.0;
  v43 = v1->m_vTargetingIntention.y;
  v44 = (__m128)LODWORD(v1->m_vTargetingIntention.x);
  v45 = v1->m_vTargetingIntention.z;
  v46 = v44;
  v46.m128_f32[0] = (float)((float)(v44.m128_f32[0] * v44.m128_f32[0]) + (float)(v43 * v43)) + (float)(v45 * v45);
  if ( v46.m128_f32[0] == 0.0 )
    v47 = 0.0;
  else
    v47 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v46));
  v1->m_vTargetingIntention.x = v47 * v44.m128_f32[0];
  v1->m_vTargetingIntention.y = v47 * v43;
  v1->m_vTargetingIntention.z = v47 * v45;
  if ( v2 && *(float *)&v2->m_SafePointerList.mNode.mNext > 0.0 )
  {
    v48 = *(float *)&v2->m_TypeUID;
    v49 = *(float *)&v2->m_NameUID;
    v1->m_vDirectionalTargetingIntention.x = *((float *)&v2->m_SafePointerList.mNode.mNext + 1);
    v1->m_vDirectionalTargetingIntention.y = v48;
    v1->m_vDirectionalTargetingIntention.z = v49;
  }
  v50 = UFG::Director::Get()->mCurrentCamera;
  if ( v50 )
    v51 = (signed __int64)&v50->mCamera;
  else
    v51 = 0i64;
  v52 = *(_DWORD *)(v51 + 164) ^ _xmm[0];
  LODWORD(v1->m_vAimTargetingIntention.x) = *(_DWORD *)(v51 + 160) ^ _xmm[0];
  LODWORD(v1->m_vAimTargetingIntention.y) = v52;
  v1->m_vAimTargetingIntention.z = 0.0;
  v53 = v1->m_vAimTargetingIntention.y;
  v54 = (__m128)LODWORD(v1->m_vAimTargetingIntention.x);
  v55 = v1->m_vAimTargetingIntention.z;
  v56 = v54;
  v56.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(v53 * v53)) + (float)(v55 * v55);
  if ( v56.m128_f32[0] == 0.0 )
    v57 = 0.0;
  else
    v57 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v56));
  v1->m_vAimTargetingIntention.x = v57 * v54.m128_f32[0];
  v1->m_vAimTargetingIntention.y = v57 * v53;
  v1->m_vAimTargetingIntention.z = v57 * v55;
}

// File Line: 1117
// RVA: 0x56AC50
bool __fastcall UFG::TargetingSystemPedPlayerComponent::isLocationTargetingActive(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *v1; // rax
  __int64 v2; // r8
  bool v3; // dl
  UFG::InputActionData *v4; // r8
  float v5; // xmm0_4
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
  bool v16; // r8
  char v17; // al
  bool v18; // al
  char v19; // cl
  UFG::InputActionData *v20; // r8
  bool v21; // r10
  bool v22; // r8

  v1 = this->m_pAICharacterControllerComponent.m_pSimComponent;
  if ( !v1 )
    return 0;
  v2 = SLODWORD(v1[17].m_SafePointerList.mNode.mPrev);
  v3 = (unsigned int)(this->m_eFocusMode - 1) <= 3;
  switch ( UFG::TargetingSystemPedPlayerComponent::ms_eTargetCycleAndLocationTargetingModeEnum )
  {
    case 1:
      v4 = UFG::ActionDef_Focus.mDataPerController[v2];
      if ( v4 )
        v5 = v4->mAxisPositionX;
      else
        v5 = 0.0;
      if ( !v3 || !this->m_bHasAimInput || v5 >= 1.0 )
        goto LABEL_9;
      return 1;
    case 2:
      v7 = UFG::ActionDef_FireTest.mDataPerController[v2];
      if ( v7 )
        v8 = v7->mAxisPositionX;
      else
        v8 = 0.0;
      if ( !v3 || !this->m_bHasAimInput || v8 <= 0.0 )
        goto LABEL_9;
      return 1;
    case 3:
    case 10:
    case 11:
      if ( !v3 || !this->m_bHasAimInput )
        goto LABEL_9;
      return 1;
    case 5:
      if ( !v3
        || !this->m_bHasFullAimInput
        || UFG::TargetingSystemPedPlayerComponent::ms_fTimeToTargetCycleVis > this->m_fTimeSinceStartedInput )
      {
        goto LABEL_9;
      }
      return 1;
    case 6:
      v9 = UFG::ActionDef_AimLocationHold.mDataPerController[v2];
      v10 = v9 && v9->mActionTrue;
      if ( !v3 )
        goto LABEL_9;
      v11 = this->m_bHasAimInput == 0;
      goto LABEL_30;
    case 7:
      v12 = UFG::ActionDef_AimLocationToggle.mDataPerController[v2];
      v13 = v12 && v12->mActionTrue;
      v14 = UFG::ActionDef_AimLocationHold.mDataPerController[v2];
      v15 = v14 && v14->mActionTrue;
      v16 = this->m_bHasAimInput;
      if ( v16 )
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
      if ( !v3 || !v16 || !v17 )
        goto LABEL_9;
      return 1;
    case 8:
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
      result = 1;
      break;
    case 9:
      v20 = UFG::ActionDef_AimLocationHold.mDataPerController[v2];
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
      v11 = v22 == 0;
LABEL_30:
      if ( v11 )
        goto LABEL_9;
      if ( v10 )
        result = 1;
      else
LABEL_9:
        result = 0;
      break;
    default:
      return 0;
  }
  return result;
}

// File Line: 1247
// RVA: 0x568670
float __fastcall UFG::TargetingSystemPedPlayerComponent::getLocationTargetingAngle(UFG::TargetingSystemPedPlayerComponent *this)
{
  float result; // xmm0_4

  result = atan2f(this->m_vAimInputDir.x, this->m_vAimInputDir.y);
  if ( result < 0.0 )
    result = result + 6.2831855;
  return result;
}

// File Line: 1271
// RVA: 0x572FA0
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateFocusTargetSubTargetingLocation(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *v1; // rdi
  UFG::TargetingSystemPedPlayerComponent *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  signed __int64 v4; // rdx
  UFG::SimObject *v5; // rsi
  unsigned __int16 v6; // cx
  unsigned int v7; // er8
  unsigned int v8; // er9
  float v9; // xmm0_4
  UFG::SubTargetingLocation *v10; // rax
  UFG::SubTargetingProfile *v11; // rax
  UFG::SimObject *v12; // rsi
  unsigned __int16 v13; // cx
  unsigned int v14; // er8
  unsigned int v15; // er9
  signed __int64 v16; // rdx
  UFG::SubTargetingProfile *v17; // rdi
  bool v18; // zf
  float *v19; // rcx
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  UFG::SubTargetingLocation *v23; // rcx
  UFG::SimComponent *v24; // rax
  float v25; // xmm1_4
  UFG::qVector3 vAimOffset; // [rsp+20h] [rbp-68h]
  UFG::qMatrix44 matSimObject; // [rsp+30h] [rbp-58h]

  v1 = 0i64;
  v2 = this;
  this->m_pFocusTargetSubTargetingLocation = 0i64;
  v3 = UFG::GameStatTracker::Instance();
  if ( (signed int)UFG::GameStatTracker::GetStat(v3, GunplayUpgradeStage) < UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_iRequiredLevelForGunplayUpgradeSubTargeting )
    return;
  if ( (unsigned int)(v2->m_eFocusMode - 2) <= 2 )
  {
    v12 = v2->m_pTargets[(unsigned __int8)v2->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
    if ( !v12 )
      goto LABEL_48;
    v13 = v12->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v1 = v12->m_Components.p[3].m_pComponent;
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
      {
        v1 = v12->m_Components.p[4].m_pComponent;
      }
      else if ( (v13 >> 12) & 1 )
      {
        v14 = (unsigned int)v12[1].vfptr;
        v15 = v12->m_Components.size;
        if ( v14 < v15 )
        {
          v16 = (signed __int64)&v12->m_Components.p[v14];
          while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
          {
            ++v14;
            v16 += 16i64;
            if ( v14 >= v15 )
              goto LABEL_41;
          }
          v1 = *(UFG::SimComponent **)v16;
        }
      }
      else
      {
        v1 = UFG::SimObject::GetComponentOfType(v12, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v1 = v12->m_Components.p[3].m_pComponent;
    }
LABEL_41:
    if ( !v1 )
      goto LABEL_48;
    v17 = (UFG::SubTargetingProfile *)((__int64 (__fastcall *)(UFG::SimComponent *))v1->vfptr[14].__vecDelDtor)(v1);
    if ( !v17 )
      goto LABEL_48;
    UFG::TargetingSystemBaseComponent::FindMatrix(v12->m_pTransformNodeComponent, v12, &matSimObject);
    v18 = v2->m_bTargetingFreeAimAssistance == 0;
    v19 = (float *)v2->m_pAimingPlayerComponent.m_pSimComponent;
    v20 = v19[155] - matSimObject.v3.y;
    vAimOffset.x = v19[154] - matSimObject.v3.x;
    v21 = v19[156];
    vAimOffset.y = v20;
    vAimOffset.z = v21 - matSimObject.v3.z;
    if ( v18 )
      v22 = *(float *)&FLOAT_1_0;
    else
      v22 = UFG::TargetingSystemPedPlayerComponent::ms_fFreeAimAssistanceSubTargetingMultiplier;
    v10 = UFG::SubTargetingProfile::FindSubTargetingLocationByAimOffset(v17, v12, &vAimOffset, v22);
  }
  else
  {
    if ( !UFG::TargetingSystemPedPlayerComponent::isLocationTargetingActive(v2) )
      goto LABEL_48;
    v5 = v2->m_pTargets[(unsigned __int8)v2->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
    if ( !v5 )
      goto LABEL_48;
    v6 = v5->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v1 = v5->m_Components.p[3].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v1 = v5->m_Components.p[4].m_pComponent;
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (unsigned int)v5[1].vfptr;
        v8 = v5->m_Components.size;
        v4 = v7;
        if ( v7 < v8 )
        {
          v4 = (signed __int64)&v5->m_Components.p[v7];
          while ( (*(_DWORD *)(v4 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v4 + 8) & 0x1FFFFFF )
          {
            ++v7;
            v4 += 16i64;
            if ( v7 >= v8 )
              goto LABEL_20;
          }
          v1 = *(UFG::SimComponent **)v4;
        }
      }
      else
      {
        v1 = UFG::SimObject::GetComponentOfType(v5, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v1 = v5->m_Components.p[3].m_pComponent;
    }
LABEL_20:
    if ( !v1 )
      goto LABEL_48;
    if ( !(__int64)v1->vfptr[14].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v1->vfptr, v4) )
      goto LABEL_48;
    v9 = UFG::TargetingSystemPedPlayerComponent::getLocationTargetingAngle(v2);
    v10 = v2->m_pLastFocusTargetSubTargetingLocation;
    if ( !v10 || COERCE_FLOAT(COERCE_UNSIGNED_INT(v2->m_fLastLocationTargetingAngle - v9) & _xmm) > 0.087266468 )
    {
      v11 = (UFG::SubTargetingProfile *)((__int64 (__fastcall *)(UFG::SimComponent *))v1->vfptr[14].__vecDelDtor)(v1);
      v10 = UFG::SubTargetingProfile::FindSubTargetingLocationByInput(v11, v5, v9);
      v2->m_fLastLocationTargetingAngle = v9;
    }
  }
  v2->m_pFocusTargetSubTargetingLocation = v10;
LABEL_48:
  v23 = v2->m_pFocusTargetSubTargetingLocation;
  if ( v23 != v2->m_pLastFocusTargetSubTargetingLocation )
  {
    if ( v23 && v2->m_eFocusMode == 1 )
      *(float *)&v2->m_pAimingPlayerComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev = v23->m_fAccuracyPenalty + *(float *)&v2->m_pAimingPlayerComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    v24 = v2->m_pEquippedSOWPC.m_pPointer;
    if ( v24 )
    {
      v25 = *(float *)(*((_QWORD *)&v24[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v24[2].m_pSimObject))
                     + 404i64);
      if ( v25 < 0.0 )
        *(float *)&v2->m_pAimingPlayerComponent.m_pSimComponent[1].m_NameUID = v25;
    }
    v2->m_pLastFocusTargetSubTargetingLocation = v2->m_pFocusTargetSubTargetingLocation;
  }
}

// File Line: 1373
// RVA: 0x56EE70
void __usercall UFG::TargetingSystemPedPlayerComponent::updateActionHijackTarget(UFG::TargetingSystemPedPlayerComponent *this@<rcx>, UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList@<rdx>, float a3@<xmm0>)
{
  UFG::TargetingSystemPedPlayerComponent *v3; // rdi
  UFG::TargetingMap *v4; // rcx
  UFG::qFixedArray<UFG::CloseTarget *,20> *v5; // r14
  UFG::TargetingSimObject *v6; // r8
  signed __int64 v7; // rax
  bool v8; // r13
  UFG::TargetingSimObject *v9; // rax
  bool v10; // al
  UFG::SimObject *v11; // r12
  UFG::SimObject *v12; // rbp
  UFG::SimObject *v13; // rcx
  bool v14; // al
  unsigned __int16 v15; // dx
  UFG::SimComponent *v16; // rcx
  unsigned int v17; // edx
  unsigned int v18; // edx
  unsigned int v19; // er8
  unsigned int v20; // er9
  signed __int64 v21; // rdx
  unsigned int v22; // er8
  unsigned int v23; // er9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  unsigned int v25; // er15
  unsigned int v26; // esi
  signed __int64 v27; // r14
  UFG::SimObjectVehicle *v28; // rbx
  UFG::TargetingMap *v29; // rcx
  UFG::TargetingSimObject *v30; // r8
  signed __int64 v31; // rax
  UFG::SimObject *v32; // r9
  unsigned __int8 v33; // al
  unsigned __int8 v34; // cl
  signed __int64 v35; // rbx
  UFG::TargetingSimObject *v36; // rax
  unsigned __int8 v37; // cl
  signed __int64 v38; // rbx
  UFG::TargetingSimObject *v39; // rax
  bool v40; // [rsp+70h] [rbp+8h]
  bool bCanActionHijackThisVehicle; // [rsp+80h] [rbp+18h]
  bool bCanPotentiallyActionHijackThisVehicle; // [rsp+88h] [rbp+20h]

  v3 = this;
  v4 = this->m_pTargetingMap;
  v5 = closeVehiclesList;
  v6 = v3->m_pTargets;
  v7 = (unsigned __int8)v4->m_Map.p[eTARGET_TYPE_VEHICLE_ACTION_HIJACK];
  v8 = v6[v7].m_pTarget.m_pPointer && v6[v7].m_bLock;
  v9 = &v6[(unsigned __int8)v4->m_Map.p[eTARGET_TYPE_VEHICLE_ACTION_HIJACK_POTENTIAL]];
  v10 = v9->m_pTarget.m_pPointer && v9->m_bLock;
  v40 = v10;
  if ( v8 && v10 )
    return;
  v11 = 0i64;
  v12 = 0i64;
  if ( UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreInVehicle || v3->m_pOccupantOfVehicle.m_pPointer )
  {
    v13 = v3->m_pOccupantOfVehicle.m_pPointer;
    v14 = 0;
    if ( !v13 )
      goto LABEL_45;
    v15 = v13->m_Flags;
    if ( (v15 >> 14) & 1 )
    {
      v16 = v13->m_Components.p[20].m_pComponent;
      if ( v16 )
      {
        v17 = v16->m_TypeUID;
        if ( !((v17 ^ UFG::TargetingSystemVehicleComponent::_TypeUID) & 0xFE000000)
          && !(UFG::TargetingSystemVehicleComponent::_TypeUID & ~v17 & 0x1FFFFFF) )
        {
LABEL_40:
          v14 = 0;
          if ( v16 )
          {
            v24 = v16[2].m_SafePointerList.mNode.mPrev;
            if ( v24 )
            {
              if ( BYTE4(v24[3].mNext) )
                v14 = 1;
            }
          }
LABEL_45:
          if ( UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreInVehicle || v14 )
          {
            v25 = v5->size;
            v26 = 0;
            if ( v5->size )
            {
              v27 = (signed __int64)v5->p;
              while ( 1 )
              {
                v28 = *(UFG::SimObjectVehicle **)(*(_QWORD *)(*(_QWORD *)v27 + 8i64) + 40i64);
                if ( (UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreInVehicle
                   || v28 != (UFG::SimObjectVehicle *)v3->m_pOccupantOfVehicle.m_pPointer)
                  && v28 != (UFG::SimObjectVehicle *)v3->m_pOccupantOfVehicle.m_pPointer )
                {
                  UFG::TargetingSystemPedPlayerComponent::canActionHijackThisVehicle(
                    v3,
                    v28,
                    (UFG::qMatrix44 *)(*(_QWORD *)v27 + 16i64),
                    &bCanActionHijackThisVehicle,
                    a3,
                    &bCanPotentiallyActionHijackThisVehicle);
                  if ( bCanActionHijackThisVehicle )
                  {
                    v11 = (UFG::SimObject *)&v28->vfptr;
                    v12 = (UFG::SimObject *)&v28->vfptr;
                    goto LABEL_59;
                  }
                  if ( bCanPotentiallyActionHijackThisVehicle && !v12 )
                    v12 = (UFG::SimObject *)&v28->vfptr;
                }
                ++v26;
                v27 += 8i64;
                if ( v26 >= v25 )
                  goto LABEL_59;
              }
            }
          }
          goto LABEL_59;
        }
      }
LABEL_18:
      v16 = 0i64;
      goto LABEL_40;
    }
    if ( (v15 & 0x8000u) != 0 )
    {
      v16 = v13->m_Components.p[20].m_pComponent;
      if ( v16 )
      {
        v18 = v16->m_TypeUID;
        if ( !((v18 ^ UFG::TargetingSystemVehicleComponent::_TypeUID) & 0xFE000000) )
        {
          if ( UFG::TargetingSystemVehicleComponent::_TypeUID & ~v18 & 0x1FFFFFF )
            v16 = 0i64;
          goto LABEL_40;
        }
      }
      goto LABEL_18;
    }
    if ( (v15 >> 13) & 1 )
    {
      v19 = (unsigned int)v13[1].vfptr;
      v20 = v13->m_Components.size;
      if ( v19 >= v20 )
        goto LABEL_18;
      v21 = (signed __int64)&v13->m_Components.p[v19];
      while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::TargetingSystemVehicleComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemVehicleComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF )
      {
        ++v19;
        v21 += 16i64;
        if ( v19 >= v20 )
        {
          v16 = 0i64;
          goto LABEL_40;
        }
      }
    }
    else
    {
      if ( !((v15 >> 12) & 1) )
      {
        v16 = UFG::SimObject::GetComponentOfType(v13, UFG::TargetingSystemVehicleComponent::_TypeUID);
        goto LABEL_40;
      }
      v22 = (unsigned int)v13[1].vfptr;
      v23 = v13->m_Components.size;
      if ( v22 >= v23 )
        goto LABEL_18;
      v21 = (signed __int64)&v13->m_Components.p[v22];
      while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::TargetingSystemVehicleComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemVehicleComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF )
      {
        ++v22;
        v21 += 16i64;
        if ( v22 >= v23 )
        {
          v16 = 0i64;
          goto LABEL_40;
        }
      }
    }
    v16 = *(UFG::SimComponent **)v21;
    goto LABEL_40;
  }
LABEL_59:
  if ( !v8 )
  {
    if ( v11 )
    {
      v29 = v3->m_pTargetingMap;
      v30 = v3->m_pTargets;
      v31 = (unsigned __int8)v29->m_Map.p[eTARGET_TYPE_FOCUS];
      v32 = v30[v31].m_pTarget.m_pPointer;
      if ( v32 && v30[v31].m_bLock && v32 != v11 )
      {
        UFG::TargetingSystemBaseComponent::ClearTarget(
          (UFG::TargetingSystemBaseComponent *)&v3->vfptr,
          eTARGET_TYPE_VEHICLE_ACTION_HIJACK);
      }
      else
      {
        v33 = v29->m_Map.p[44];
        if ( v33 )
          UFG::TargetingSimObject::SetTarget(&v30[v33], v11);
      }
    }
    else
    {
      v34 = v3->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE_ACTION_HIJACK];
      if ( v34 )
      {
        v35 = v34;
        UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v35], 0i64);
        v36 = v3->m_pTargets;
        if ( v36[v35].m_bLock )
          v36[v35].m_bLock = 0;
      }
    }
  }
  if ( !v40 )
  {
    v37 = v3->m_pTargetingMap->m_Map.p[45];
    if ( v12 )
    {
      if ( v37 )
        UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v37], v12);
    }
    else if ( v37 )
    {
      v38 = v37;
      UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v38], 0i64);
      v39 = v3->m_pTargets;
      if ( v39[v38].m_bLock )
        v39[v38].m_bLock = 0;
    }
  }
}

// File Line: 1549
// RVA: 0x570380
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateAttackingTarget(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingSystemPedPlayerComponent *v1; // rsi
  UFG::TargetingSimObject *v2; // rdx
  UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *v3; // r15
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v4; // rcx
  unsigned int v5; // edi
  unsigned int v6; // ebx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v7; // rbp
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v8; // r14
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v9; // r8
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  unsigned int v12; // ecx
  unsigned int v13; // er9
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v14; // r11
  signed __int64 v15; // r8
  unsigned int v16; // ecx
  unsigned int v17; // er9
  unsigned int v18; // ecx
  float v19; // xmm0_4
  __int64 v20; // rcx
  unsigned __int8 v21; // cl
  unsigned __int8 v22; // cl
  signed __int64 v23; // rbx
  UFG::TargetingSimObject *v24; // rax
  ClassTypeDescriptor right; // [rsp+28h] [rbp-6B0h]
  ClassTypeDescriptor left[104]; // [rsp+38h] [rbp-6A0h]

  v1 = this;
  v2 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[38]];
  if ( !v2->m_pTarget.m_pPointer || !v2->m_bLock )
  {
    LODWORD(right.mfnInPlaceNew) = 0;
    v3 = &this->m_TargetedBy;
    v4 = this->m_TargetedBy.mNode.mNext;
    v5 = 0;
    if ( v4 != (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)v3 )
    {
      v6 = UFG::HitReactionComponent::_TypeUID;
      while ( 1 )
      {
        v7 = v4->mNext;
        if ( LOBYTE(v4[3].mPrev) != 22 )
          goto LABEL_37;
        if ( v4[2].mNext != (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)v1->m_pSimObject )
          goto LABEL_37;
        v8 = v4[1].mPrev;
        v9 = v8[2].mNext;
        if ( !v9 )
          goto LABEL_37;
        v10 = WORD2(v9[4].mNext);
        if ( (v10 >> 14) & 1 )
        {
          v11 = (UFG::SimComponent *)v9[6].mNext[15].mPrev;
          goto LABEL_29;
        }
        if ( (v10 & 0x8000u) != 0 )
        {
          v11 = (UFG::SimComponent *)v9[6].mNext[15].mPrev;
          goto LABEL_29;
        }
        if ( (v10 >> 13) & 1 )
          break;
        if ( (v10 >> 12) & 1 )
        {
          v16 = (unsigned int)v9[8].mPrev;
          v17 = (unsigned int)v9[6].mPrev;
          if ( v16 < v17 )
          {
            v14 = v9[6].mNext;
            while ( 1 )
            {
              v15 = v16;
              if ( ((_QWORD)v14[v16].mNext & 0xFE000000) == (v6 & 0xFE000000)
                && !(v6 & ~LODWORD(v14[v16].mNext) & 0x1FFFFFF) )
              {
                goto LABEL_19;
              }
              if ( ++v16 >= v17 )
                goto LABEL_20;
            }
          }
          goto LABEL_20;
        }
        v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v8[2].mNext, v6);
        v5 = (unsigned int)right.mfnInPlaceNew;
        v6 = UFG::HitReactionComponent::_TypeUID;
LABEL_29:
        if ( v11 )
        {
          v18 = v11[1].m_NameUID;
          if ( v18 == 1 )
          {
            v19 = (float)(*(float *)&v11[1].m_TypeUID * _real) + 1.0;
LABEL_34:
            if ( v19 >= 0.0 && v5 < 0x64 )
            {
              v20 = v5;
              LODWORD(right.mfnInPlaceNew) = v5 + 1;
              left[v20].mfnInPlaceNew = (void (__fastcall *)(void *))v8[2].mNext;
              *(float *)&left[v20].mUID = v19;
              v5 = (unsigned int)right.mfnInPlaceNew;
            }
            goto LABEL_37;
          }
          if ( v18 == 2 )
          {
            v19 = (float)(*(float *)&v11[1].m_TypeUID * _real) + 2.0;
            goto LABEL_34;
          }
        }
LABEL_37:
        v4 = v7;
        if ( v7 == (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)v3 )
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
          if ( ((_QWORD)v14[v12].mNext & 0xFE000000) == (v6 & 0xFE000000)
            && !(v6 & ~LODWORD(v14[v12].mNext) & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v12 >= v13 )
            goto LABEL_20;
        }
LABEL_19:
        v11 = (UFG::SimComponent *)v14[v15].mPrev;
        goto LABEL_29;
      }
LABEL_20:
      v11 = 0i64;
      goto LABEL_29;
    }
LABEL_38:
    UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
      left,
      &right + (signed int)v5,
      (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
    if ( LODWORD(right.mfnInPlaceNew) && left[0].mfnInPlaceNew )
    {
      v21 = v1->m_pTargetingMap->m_Map.p[38];
      if ( v21 )
        UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v21], (UFG::SimObject *)left[0].mfnInPlaceNew);
    }
    else
    {
      v22 = v1->m_pTargetingMap->m_Map.p[38];
      if ( v22 )
      {
        v23 = v22;
        UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v23], 0i64);
        v24 = v1->m_pTargets;
        if ( v24[v23].m_bLock )
          v24[v23].m_bLock = 0;
      }
    }
  }
}

// File Line: 1626
// RVA: 0x577F60
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateSocialTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList)
{
  UFG::qFixedArray<UFG::CloseTarget *,80> *r12_1; // r12
  UFG::TargetingSystemPedPlayerComponent *v3; // r13
  UFG::TargetingProfile *v4; // rax
  float v5; // xmm7_4
  float v6; // xmm9_4
  unsigned int v7; // edi
  unsigned int v8; // er15
  __int64 v9; // r14
  UFG::CloseTarget *v10; // rsi
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm6_4
  UFG::SimObject *v14; // rbx
  unsigned __int16 v15; // cx
  UFG::SimComponent *v16; // rcx
  unsigned int v17; // edx
  unsigned int v18; // er9
  UFG::SimComponentHolder *v19; // rdi
  signed __int64 v20; // r8
  unsigned int v21; // edx
  unsigned int v22; // er9
  __int64 v23; // rbp
  float v24; // xmm6_4
  unsigned __int16 v25; // cx
  UFG::SimComponent *v26; // rax
  unsigned int v27; // edx
  unsigned int v28; // er9
  UFG::SimComponentHolder *v29; // rdi
  signed __int64 v30; // r8
  unsigned int v31; // edx
  unsigned int v32; // er9
  unsigned int v33; // edx
  unsigned int v34; // er9
  char v35; // dl
  UFG::SimObject *v36; // rcx
  void (__fastcall *v37)(void *); // r9
  UFG::TargetingMap *v38; // r10
  signed __int64 v39; // r8
  UFG::TargetingSimObject *v40; // rdx
  UFG::TargetingSimObject *v41; // rcx
  signed __int64 v42; // rax
  signed __int64 v43; // rbx
  UFG::TargetingSimObject *v44; // rax
  UFG::qVector3 v2; // [rsp+20h] [rbp-6E8h]
  UFG::qVector3 v1; // [rsp+30h] [rbp-6D8h]
  __int64 v47; // [rsp+40h] [rbp-6C8h]
  ClassTypeDescriptor right; // [rsp+48h] [rbp-6C0h]
  ClassTypeDescriptor left[104]; // [rsp+58h] [rbp-6B0h]
  unsigned int v50; // [rsp+710h] [rbp+8h]

  v47 = -2i64;
  r12_1 = closePedsList;
  v3 = this;
  if ( !this->m_pOccupantOfVehicle.m_pPointer )
  {
    LODWORD(right.mfnInPlaceNew) = 0;
    v4 = this->m_pActiveTargetingProfile;
    v5 = v4->m_ConeDistancesSquared[3];
    v6 = v4->m_HalfHorizontalFOVs[3];
    v7 = closePedsList->size;
    v50 = closePedsList->size;
    v8 = 0;
    v9 = 0i64;
    if ( closePedsList->size )
    {
      do
      {
        v10 = r12_1->p[v9];
        if ( v5 < v10->m_fDistance2 )
          goto LABEL_71;
        v11 = v10->m_Xform.v3.y - v3->m_vTargetingPosition.y;
        v1.x = v10->m_Xform.v3.x - v3->m_vTargetingPosition.x;
        v1.y = v11;
        v1.z = 0.0;
        v12 = v3->m_vTargetingForward.y;
        v2.x = v3->m_vTargetingForward.x;
        v2.y = v12;
        v2.z = 0.0;
        v13 = UFG::qAngleBetween(&v1, &v2);
        if ( v6 < v13 )
          goto LABEL_71;
        v14 = v10->m_pSimObjectPropertiesComponent->m_pSimObject;
        if ( !v14 )
          goto LABEL_36;
        v15 = v14->m_Flags;
        if ( (v15 >> 14) & 1 )
        {
          v16 = v14->m_Components.p[20].m_pComponent;
          if ( !v16
            || (UFG::TargetingSystemPedBaseComponent::_TypeUID ^ v16->m_TypeUID) & 0xFE000000
            || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v16->m_TypeUID & 0x1FFFFFF )
          {
            goto LABEL_10;
          }
        }
        else
        {
          if ( (v15 & 0x8000u) == 0 )
          {
            if ( (v15 >> 13) & 1 )
            {
              v17 = (unsigned int)v14[1].vfptr;
              v18 = v14->m_Components.size;
              if ( v17 < v18 )
              {
                v19 = v14->m_Components.p;
                do
                {
                  v20 = v17;
                  if ( (v19[v17].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
                    && !(UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v19[v17].m_TypeUID & 0x1FFFFFF) )
                  {
                    goto LABEL_23;
                  }
                }
                while ( ++v17 < v18 );
              }
LABEL_24:
              v16 = 0i64;
            }
            else
            {
              if ( !((v15 >> 12) & 1) )
              {
                v16 = UFG::SimObject::GetComponentOfType(v14, UFG::TargetingSystemPedBaseComponent::_TypeUID);
                goto LABEL_34;
              }
              v21 = (unsigned int)v14[1].vfptr;
              v22 = v14->m_Components.size;
              if ( v21 >= v22 )
                goto LABEL_24;
              v19 = v14->m_Components.p;
              while ( 1 )
              {
                v20 = v21;
                if ( (v19[v21].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
                  && !(UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v19[v21].m_TypeUID & 0x1FFFFFF) )
                {
                  break;
                }
                if ( ++v21 >= v22 )
                  goto LABEL_24;
              }
LABEL_23:
              v16 = v19[v20].m_pComponent;
            }
            v7 = v50;
            goto LABEL_34;
          }
          v16 = v14->m_Components.p[20].m_pComponent;
          if ( !v16 || (UFG::TargetingSystemPedBaseComponent::_TypeUID ^ v16->m_TypeUID) & 0xFE000000 )
          {
LABEL_10:
            v16 = 0i64;
            goto LABEL_34;
          }
          if ( UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v16->m_TypeUID & 0x1FFFFFF )
            v16 = 0i64;
        }
LABEL_34:
        if ( v16 && !BYTE1(v16[8].m_BoundComponentHandles.mNode.mPrev) )
          goto LABEL_71;
LABEL_36:
        if ( LODWORD(right.mfnInPlaceNew) < 0x64 )
        {
          v23 = LODWORD(right.mfnInPlaceNew);
          ++LODWORD(right.mfnInPlaceNew);
          v24 = UFG::TargetingSystemPedBaseComponent::scoreBasic(v10->m_fDistance2, v5, v13);
          if ( !v14 )
            goto LABEL_88;
          v25 = v14->m_Flags;
          if ( (v25 >> 14) & 1 )
          {
            v26 = v14->m_Components.p[45].m_pComponent;
            goto LABEL_64;
          }
          if ( (v25 & 0x8000u) == 0 )
          {
            if ( (v25 >> 13) & 1 )
            {
              v31 = (unsigned int)v14[1].vfptr;
              v32 = v14->m_Components.size;
              if ( v31 >= v32 )
                goto LABEL_48;
              v29 = v14->m_Components.p;
              while ( 1 )
              {
                v30 = v31;
                if ( (v29[v31].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                  && !(UFG::FaceActionComponent::_TypeUID & ~v29[v31].m_TypeUID & 0x1FFFFFF) )
                {
                  break;
                }
                if ( ++v31 >= v32 )
                  goto LABEL_48;
              }
            }
            else
            {
              if ( !((v25 >> 12) & 1) )
              {
                v26 = UFG::SimObject::GetComponentOfType(v14, UFG::FaceActionComponent::_TypeUID);
                goto LABEL_64;
              }
              v33 = (unsigned int)v14[1].vfptr;
              v34 = v14->m_Components.size;
              if ( v33 >= v34 )
                goto LABEL_48;
              v29 = v14->m_Components.p;
              while ( 1 )
              {
                v30 = v33;
                if ( (v29[v33].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                  && !(UFG::FaceActionComponent::_TypeUID & ~v29[v33].m_TypeUID & 0x1FFFFFF) )
                {
                  break;
                }
                if ( ++v33 >= v34 )
                  goto LABEL_48;
              }
            }
LABEL_47:
            v26 = v29[v30].m_pComponent;
            goto LABEL_64;
          }
          v27 = (unsigned int)v14[1].vfptr;
          v28 = v14->m_Components.size;
          if ( v27 < v28 )
          {
            v29 = v14->m_Components.p;
            do
            {
              v30 = v27;
              if ( (v29[v27].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                && !(UFG::FaceActionComponent::_TypeUID & ~v29[v27].m_TypeUID & 0x1FFFFFF) )
              {
                goto LABEL_47;
              }
            }
            while ( ++v27 < v28 );
          }
LABEL_48:
          v26 = 0i64;
LABEL_64:
          if ( !v26 )
            goto LABEL_88;
          v35 = *((_BYTE *)&v26[3].m_SimObjIndex + 2);
          if ( !v35 )
            goto LABEL_88;
          v36 = v26->m_pSimObject;
          if ( v36 )
          {
            if ( (v36->m_Flags >> 10) & 1 )
              goto LABEL_88;
          }
          if ( !v35 )
LABEL_88:
            v24 = v24 + 1.0;
          left[v23].mfnInPlaceNew = (void (__fastcall *)(void *))v14;
          *(float *)&left[v23].mUID = v24;
          v7 = v50;
        }
LABEL_71:
        ++v8;
        ++v9;
      }
      while ( v8 < v7 );
    }
    UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
      left,
      &right + SLODWORD(right.mfnInPlaceNew),
      (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
    v37 = 0i64;
    if ( LODWORD(right.mfnInPlaceNew) )
      v37 = left[0].mfnInPlaceNew;
    v38 = v3->m_pTargetingMap;
    v39 = (unsigned __int8)v38->m_Map.p[50];
    v40 = v3->m_pTargets;
    v41 = &v40[v39];
    if ( !v41->m_pTarget.m_pPointer || !v41->m_bLock )
    {
      v42 = (unsigned __int8)v38->m_Map.p[22];
      if ( v40[v42].m_pTarget.m_pPointer && v40[v42].m_bLock )
      {
        if ( (_BYTE)v39 )
          UFG::TargetingSimObject::SetTarget(v41, v40[v42].m_pTarget.m_pPointer);
      }
      else if ( v37 )
      {
        if ( (_BYTE)v39 )
          UFG::TargetingSimObject::SetTarget(v41, (UFG::SimObject *)v37);
      }
      else if ( (_BYTE)v39 )
      {
        v43 = v39;
        UFG::TargetingSimObject::SetTarget(&v40[v39], 0i64);
        v44 = v3->m_pTargets;
        if ( v44[v43].m_bLock )
          v44[v43].m_bLock = 0;
      }
    }
  }
}

// File Line: 1738
// RVA: 0x564DF0
UFG::ScoredTarget *__fastcall UFG::TargetingSystemPedPlayerComponent::chooseBestVisibleTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::qFixedArray<UFG::ScoredTarget,100> *potentialTargets, const int iMaxRaycastsBeforeGiveUp)
{
  int v3; // ebx
  UFG::qFixedArray<UFG::ScoredTarget,100> *v4; // r13
  UFG::TargetingSystemPedPlayerComponent *v5; // rsi
  Render::DebugDrawContext *v6; // r15
  UFG::BaseCameraComponent *v7; // rax
  signed __int64 v8; // rax
  int v9; // xmm10_4
  int v10; // xmm9_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm7_4
  __int128 v14; // xmm8
  float v15; // xmm6_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm11_4
  float v19; // xmm9_4
  float v20; // xmm9_4
  __m128 v21; // xmm1
  unsigned int v22; // er12
  float v23; // xmm0_4
  float v24; // xmm9_4
  float v25; // xmm1_4
  __int64 v26; // rdi
  unsigned __int16 v27; // cx
  unsigned int v28; // er8
  unsigned int v29; // er10
  __int64 v30; // rbx
  signed __int64 v31; // rdx
  UFG::AICoverComponent *v32; // rbx
  unsigned int v33; // er8
  unsigned int v34; // er10
  unsigned int v35; // er8
  unsigned int v36; // er10
  unsigned int v37; // er8
  unsigned int v38; // er10
  UFG::SimObject *v39; // rbx
  UFG::TransformNodeComponent *v40; // rbx
  signed __int64 v41; // rax
  float v42; // xmm7_4
  float v43; // xmm8_4
  float v44; // xmm6_4
  float v45; // xmm6_4
  float v46; // xmm11_4
  float v47; // xmm9_4
  float v48; // xmm12_4
  float v49; // xmm4_4
  float v50; // xmm5_4
  __m128 v51; // xmm10
  float v52; // xmm9_4
  __m128 v53; // xmm1
  float v54; // xmm1_4
  UFG::RayCastData *v55; // r14
  char v56; // bl
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v57; // rcx
  const char *v58; // rax
  UFG::qReflectObject *v59; // rax
  bool v60; // si
  UFG::qReflectHandleBase *v61; // rcx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v62; // rcx
  const char *v63; // rax
  UFG::qReflectObject *v64; // rax
  float v65; // xmm2_4
  __m128 v66; // xmm3
  float v67; // xmm4_4
  __m128 v68; // xmm5
  float v69; // xmm1_4
  hkpRigidBody *v70; // rax
  unsigned __int64 v71; // rcx
  __int64 v72; // rax
  __int64 v73; // rax
  UFG::qVector3 centre; // [rsp+40h] [rbp-80h]
  UFG::qVector3 rayStart; // [rsp+50h] [rbp-70h]
  UFG::qVector3 vSegA; // [rsp+60h] [rbp-60h]
  float v78; // [rsp+6Ch] [rbp-54h]
  __int128 vSegB; // [rsp+70h] [rbp-50h]
  UFG::qReflectHandleBase v80; // [rsp+80h] [rbp-40h]
  UFG::qReflectHandleBase v81; // [rsp+A8h] [rbp-18h]
  __int64 v82; // [rsp+D0h] [rbp+10h]
  UFG::RayCastData data; // [rsp+E0h] [rbp+20h]
  UFG::RayCastData v84; // [rsp+1C0h] [rbp+100h]
  UFG::TargetingSystemPedPlayerComponent *v85; // [rsp+390h] [rbp+2D0h]
  float fRadius; // [rsp+398h] [rbp+2D8h]
  float v87; // [rsp+3A0h] [rbp+2E0h]
  float v88; // [rsp+3A8h] [rbp+2E8h]

  v82 = -2i64;
  v3 = iMaxRaycastsBeforeGiveUp;
  v4 = potentialTargets;
  v5 = this;
  v6 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v7 = UFG::Director::Get()->mCurrentCamera;
  if ( v7 )
    v8 = (signed __int64)&v7->mCamera;
  else
    v8 = 0i64;
  v9 = *(_DWORD *)(v8 + 164) ^ _xmm[0];
  v10 = *(_DWORD *)(v8 + 160) ^ _xmm[0];
  v11 = (float)(*(float *)&v10 * *(float *)&v10) + (float)(*(float *)&v9 * *(float *)&v9);
  if ( v11 == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / fsqrt(v11);
  v13 = v5->m_vTargetingPosition.y;
  v14 = *(unsigned int *)(v8 + 180);
  v15 = v5->m_vTargetingPosition.x;
  v16 = *(float *)(v8 + 176);
  v17 = (float)((float)((float)(v12 * *(float *)&v9) * (float)(v5->m_vTargetingPosition.y - *(float *)&v14))
              + (float)((float)(v5->m_vTargetingPosition.x - v16) * (float)(*(float *)&v10 * v12)))
      / (float)((float)((float)(v12 * *(float *)&v9) * *(float *)&v9)
              + (float)((float)(*(float *)&v10 * v12) * *(float *)&v10));
  v18 = (float)(COERCE_FLOAT(*(_DWORD *)(v8 + 168) ^ _xmm[0]) * v17) + *(float *)(v8 + 184);
  *(float *)&v14 = *(float *)&v14 + (float)(*(float *)&v9 * v17);
  v19 = (float)(*(float *)&v10 * v17) + v16;
  centre.x = v19;
  LODWORD(centre.y) = v14;
  centre.z = v18;
  vSegA.x = v18 - v5->m_vTargetingPosition.z;
  *(float *)&v14 = *(float *)&v14 - v13;
  v20 = v19 - v15;
  v21 = (__m128)v14;
  v21.m128_f32[0] = (float)(*(float *)&v14 * *(float *)&v14) + (float)(v20 * v20);
  LODWORD(v88) = (unsigned __int128)_mm_sqrt_ps(v21);
  if ( (float)((float)((float)(*(float *)&v14 * v5->m_vTargetingLeft.y) + (float)(v20 * v5->m_vTargetingLeft.x))
             + (float)(vSegA.x * v5->m_vTargetingLeft.z)) < 0.0 )
    v87 = *(float *)&FLOAT_1_0;
  else
    v87 = FLOAT_N1_0;
  if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
    Render::DebugDrawContext::DrawSphere(v6, &centre, 0.1, &UFG::qColour::Yellow, &UFG::qMatrix44::msIdentity, 0i64);
  v22 = 0;
  v23 = (float)v3;
  vSegA.y = (float)v3;
  v24 = FLOAT_0_5;
  while ( 1 )
  {
    v25 = (float)(signed int)v4->size;
    if ( v25 >= v23 )
      v25 = v23;
    if ( (float)(signed int)v22 >= v25 )
      return 0i64;
    v26 = *((_QWORD *)&v4->size + 2 * (v22 + 1i64));
    if ( !v26 )
      goto LABEL_92;
    *((_QWORD *)&vSegB + 1) = 0i64;
    v27 = *(_WORD *)(v26 + 76);
    if ( (v27 >> 14) & 1 )
    {
      v28 = *(_DWORD *)(v26 + 128);
      v29 = *(_DWORD *)(v26 + 96);
      if ( v28 >= v29 )
        goto LABEL_25;
      v30 = *(_QWORD *)(v26 + 104);
      while ( 1 )
      {
        v31 = 2i64 * v28;
        if ( (*(_DWORD *)(v30 + 16i64 * v28 + 8) & 0xFE000000) == (UFG::AICoverComponent::_TypeUID & 0xFE000000)
          && !(UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v30 + 16i64 * v28 + 8) & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v28 >= v29 )
          goto LABEL_25;
      }
    }
    else if ( (v27 & 0x8000u) == 0 )
    {
      if ( (v27 >> 13) & 1 )
      {
        v35 = *(_DWORD *)(v26 + 128);
        v36 = *(_DWORD *)(v26 + 96);
        if ( v35 >= v36 )
          goto LABEL_25;
        v30 = *(_QWORD *)(v26 + 104);
        while ( 1 )
        {
          v31 = 2i64 * v35;
          if ( (*(_DWORD *)(v30 + 16i64 * v35 + 8) & 0xFE000000) == (UFG::AICoverComponent::_TypeUID & 0xFE000000)
            && !(UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v30 + 16i64 * v35 + 8) & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v35 >= v36 )
            goto LABEL_25;
        }
      }
      else
      {
        if ( !((v27 >> 12) & 1) )
        {
          v32 = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)v26,
                                           UFG::AICoverComponent::_TypeUID);
          goto LABEL_48;
        }
        v37 = *(_DWORD *)(v26 + 128);
        v38 = *(_DWORD *)(v26 + 96);
        if ( v37 >= v38 )
        {
LABEL_25:
          v32 = 0i64;
          goto LABEL_48;
        }
        v30 = *(_QWORD *)(v26 + 104);
        while ( 1 )
        {
          v31 = 2i64 * v37;
          if ( (*(_DWORD *)(v30 + 16i64 * v37 + 8) & 0xFE000000) == (UFG::AICoverComponent::_TypeUID & 0xFE000000)
            && !(UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v30 + 16i64 * v37 + 8) & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v37 >= v38 )
            goto LABEL_25;
        }
      }
    }
    else
    {
      v33 = *(_DWORD *)(v26 + 128);
      v34 = *(_DWORD *)(v26 + 96);
      if ( v33 >= v34 )
        goto LABEL_25;
      v30 = *(_QWORD *)(v26 + 104);
      while ( 1 )
      {
        v31 = 2i64 * v33;
        if ( (*(_DWORD *)(v30 + 16i64 * v33 + 8) & 0xFE000000) == (UFG::AICoverComponent::_TypeUID & 0xFE000000)
          && !(UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v30 + 16i64 * v33 + 8) & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v33 >= v34 )
          goto LABEL_25;
      }
    }
    v32 = *(UFG::AICoverComponent **)(v30 + 8 * v31);
LABEL_48:
    if ( v32
      && UFG::AICoverComponent::IsInCover(v32)
      && (v39 = v32->m_pSimTargetPopout.m_pPointer) != 0i64
      && (v40 = v39->m_pTransformNodeComponent) != 0i64 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v40);
      v41 = (signed __int64)&v40->mWorldTransform;
      v42 = v40->mWorldTransform.v3.x;
      v43 = v40->mWorldTransform.v3.y;
      v44 = v40->mWorldTransform.v3.z + s_fCoverPopoutZOffset;
    }
    else
    {
      if ( !UFG::SimObjectUtility::GetObjectCapsuleApproximation(
              (UFG::SimObject *)v26,
              (UFG::qMatrix44 **)&vSegB + 1,
              &vSegA,
              (UFG::qVector3 *)&vSegB,
              &fRadius) )
        goto LABEL_92;
      v45 = vSegA.z;
      if ( vSegA.z <= *((float *)&vSegB + 2) )
        v45 = *((float *)&vSegB + 2);
      v43 = (float)(vSegA.y + *((float *)&vSegB + 1)) * v24;
      v42 = (float)(vSegA.x + *(float *)&vSegB) * v24;
      v44 = (float)(v45 + fRadius) + s_fCapsuleZOffset;
      v41 = *((_QWORD *)&vSegB + 1);
    }
    if ( v41 )
    {
      v46 = v5->m_vTargetingPosition.z;
      v47 = v5->m_vTargetingPosition.z - v44;
      v48 = v5->m_vTargetingPosition.y;
      v49 = v5->m_vTargetingPosition.y - v43;
      v51 = (__m128)LODWORD(v5->m_vTargetingPosition.x);
      v51.m128_f32[0] = v51.m128_f32[0] - v42;
      v50 = (float)(v49 * UFG::qVector3::msAxisZ.x) - (float)(v51.m128_f32[0] * UFG::qVector3::msAxisZ.y);
      v51.m128_f32[0] = (float)(v51.m128_f32[0] * UFG::qVector3::msAxisZ.z) - (float)(v47 * UFG::qVector3::msAxisZ.x);
      v52 = (float)(v47 * UFG::qVector3::msAxisZ.y) - (float)(v49 * UFG::qVector3::msAxisZ.z);
      v53 = v51;
      v53.m128_f32[0] = (float)((float)(v51.m128_f32[0] * v51.m128_f32[0]) + (float)(v52 * v52)) + (float)(v50 * v50);
      if ( v53.m128_f32[0] == 0.0 )
        v54 = 0.0;
      else
        v54 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v53));
      rayStart.x = (float)((float)(v87 * v88) * (float)(v52 * v54)) + v5->m_vTargetingPosition.x;
      rayStart.y = (float)((float)(v87 * v88) * (float)(v51.m128_f32[0] * v54)) + v48;
      rayStart.z = (float)(v46 + vSegA.x) + s_fAimThruZOffset;
      if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
      {
        Render::DebugDrawContext::DrawSphere(
          v6,
          &rayStart,
          0.1,
          &UFG::qColour::Green,
          &UFG::qMatrix44::msIdentity,
          0i64);
        Render::DebugDrawContext::DrawSphere(
          v6,
          &rayStart,
          0.1,
          &UFG::qColour::ForestGreen,
          &UFG::qMatrix44::msIdentity,
          0i64);
      }
      centre.x = v42;
      centre.y = v43;
      centre.z = v44;
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
      v84.mInput.m_enableShapeCollectionFilter.m_bool = 0;
      v84.mInput.m_filterInfo = 0;
      v84.mInput.m_userData = 0i64;
      v84.mOutput.m_hitFraction = 1.0;
      v84.mOutput.m_extraInfo = -1;
      v84.mOutput.m_shapeKeyIndex = 0;
      v84.mOutput.m_shapeKeys[0] = -1;
      v84.mOutput.m_rootCollidable = 0i64;
      v84.mDebugName = 0i64;
      v84.mCollisionModelName.mUID = -1;
      v55 = &data;
      UFG::RayCastData::Init(&data, &rayStart, &centre, 0xCu);
      if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
        Render::DebugDrawContext::DrawLine(
          v6,
          &rayStart,
          &centre,
          &UFG::qColour::Red,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
      v56 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
      if ( !v56 )
        return &v4->p[v22];
      if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
        Render::DebugDrawContext::DrawPoint(v6, &data.point, &UFG::qColour::Orange, &UFG::qMatrix44::msIdentity, 0i64);
      if ( data.mPhysicsSurfacePropertyHandleUid )
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v80);
        v58 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v57);
        v80.mTypeUID = UFG::qStringHash64(v58, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v80, v80.mTypeUID, data.mPhysicsSurfacePropertyHandleUid);
        v59 = v80.mData;
        if ( !v80.mData )
        {
          UFG::PhysicsPropertyManager::GetDefaultSurfaceProperties((UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *)&v80);
          v59 = v80.mData;
        }
        v60 = *(float *)&v59[1].mBaseNode.mUID > 0.0;
        v61 = &v80;
      }
      else
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v81);
        v63 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v62);
        v81.mTypeUID = UFG::qStringHash64(v63, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v81, v81.mTypeUID, data.mPhysicsObjectPropertyHandleUid);
        v64 = v81.mData;
        if ( !v81.mData )
        {
          UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v81);
          v64 = v81.mData;
        }
        v60 = *(float *)(v64[4].mBaseNode.mUID + 88) > 0.0;
        v61 = &v81;
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(v61);
      if ( v60 )
      {
        v65 = centre.x - rayStart.x;
        v66 = (__m128)LODWORD(centre.y);
        v66.m128_f32[0] = centre.y - rayStart.y;
        v67 = centre.z - rayStart.z;
        v68 = v66;
        v68.m128_f32[0] = (float)((float)(v66.m128_f32[0] * v66.m128_f32[0]) + (float)(v65 * v65)) + (float)(v67 * v67);
        if ( v68.m128_f32[0] == 0.0 )
          v69 = 0.0;
        else
          v69 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v68));
        vSegA.z = (float)((float)(v65 * v69) * 0.050000001) + data.point.x;
        v78 = (float)((float)(v66.m128_f32[0] * v69) * 0.050000001) + data.point.y;
        *(float *)&vSegB = (float)((float)(v67 * v69) * 0.050000001) + data.point.z;
        UFG::RayCastData::Init(&v84, (UFG::qVector3 *)((char *)&vSegA + 8), &centre, 0xCu);
        if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
          Render::DebugDrawContext::DrawLine(
            v6,
            (UFG::qVector3 *)((char *)&vSegA + 8),
            &centre,
            &UFG::qColour::Orange,
            &UFG::qMatrix44::msIdentity,
            0i64,
            0);
        v56 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &v84);
        v55 = &v84;
      }
      if ( !v56 )
        return &v4->p[v22];
      if ( UFG::TargetingSystemPedPlayerComponent::ms_DrawRaycasts )
        Render::DebugDrawContext::DrawPoint(v6, &v55->point, &UFG::qColour::Red, &UFG::qMatrix44::msIdentity, 0i64);
      v70 = v55->mHavokRigidBody;
      if ( v70 )
      {
        v71 = v70->m_userData;
        if ( v71 )
        {
          v72 = *(_QWORD *)(v71 + 24);
          v73 = v72 ? *(_QWORD *)(v72 + 40) : 0i64;
          if ( v73 == v26 )
            return &v4->p[v22];
        }
      }
      v24 = FLOAT_0_5;
      v5 = v85;
    }
LABEL_92:
    ++v22;
    v23 = vSegA.y;
  }
}

// File Line: 1979
// RVA: 0x56D0B0
char __fastcall UFG::TargetingSystemPedPlayerComponent::shouldCycleTarget(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingSystemPedPlayerComponent *v1; // rbx
  unsigned __int8 v2; // r9
  __int64 v3; // rax
  __int64 v4; // rax
  bool v5; // al
  char v6; // di
  __int64 v7; // rsi
  UFG::InputActionData *v8; // rcx
  UFG::InputActionData *v9; // rax
  bool v10; // al
  UFG::InputActionData *v11; // rcx
  float v12; // xmm0_4
  UFG::InputActionData *v14; // rax
  bool v15; // al
  UFG::InputActionData *v16; // rcx
  float v17; // xmm0_4
  bool v18; // zf
  UFG::InputActionData *v19; // rax
  UFG::InputActionData *v20; // rcx
  UFG::InputActionData *v21; // rcx
  float v22; // xmm6_4
  float v23; // xmm7_4
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

  v1 = this;
  v2 = 0;
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v3 = *((_QWORD *)&this->m_pAICharacterControllerBaseComponent.m_pSimComponent[4].m_BoundComponentHandles.mNode.mPrev
         + ((signed __int64)(signed int)gActionRequest_Focus.m_EnumValue >> 6));
    v2 = _bittest64(&v3, gActionRequest_Focus.m_EnumValue & 0x3F);
  }
  v5 = 0;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v4 = *((_QWORD *)&this->m_pActionTreeComponent.m_pSimComponent[11].m_SafePointerList.mNode.mPrev
         + ((signed __int64)(signed int)gActionRequest_CameraZoom.m_EnumValue >> 6));
    if ( _bittest64(&v4, gActionRequest_CameraZoom.m_EnumValue & 0x3F) )
      v5 = 1;
  }
  v6 = 0;
  if ( (this->m_bTargetAutoAcquisition || v2 && !v5 && this->m_eFocusMode == 1)
    && this->m_pAICharacterControllerComponent.m_pSimComponent )
  {
    v7 = SLODWORD(this->m_pAICharacterControllerComponent.m_pSimComponent[17].m_SafePointerList.mNode.mPrev);
    switch ( UFG::TargetingSystemPedPlayerComponent::ms_eTargetCycleAndLocationTargetingModeEnum )
    {
      case 0:
      case 3:
        v8 = UFG::ActionDef_TargetCycle.mDataPerController[v7];
        if ( !v8 || !v8->mActionTrue )
          return 0;
        return 1;
      case 1:
        v9 = UFG::ActionDef_TargetCycle.mDataPerController[v7];
        v10 = v9 && v9->mActionTrue;
        v11 = UFG::ActionDef_Focus.mDataPerController[v7];
        if ( v11 )
          v12 = v11->mAxisPositionX;
        else
          v12 = 0.0;
        if ( !v10 || v12 < 1.0 )
          return 0;
        return 1;
      case 2:
        v14 = UFG::ActionDef_TargetCycle.mDataPerController[v7];
        v15 = v14 && v14->mActionTrue;
        v16 = UFG::ActionDef_FireTest.mDataPerController[v7];
        if ( v16 )
          v17 = v16->mAxisPositionX;
        else
          v17 = 0.0;
        v18 = v15 == 0;
        goto LABEL_34;
      case 5:
        if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
        {
          v19 = UFG::ActionDef_TargetCycleUp.mDataPerController[v7];
          if ( !v19 || !v19->mActionTrue )
          {
            v20 = UFG::ActionDef_TargetCycleDown.mDataPerController[v7];
            if ( !v20 || !v20->mActionTrue )
              return 0;
          }
          if ( v19 && v19->mActionTrue )
            v6 = 1;
          v1->m_bTargetCycleDirectionLeft = v6;
          v1->m_bTargetCycleDesired = 0;
          return 1;
        }
        if ( UFG::TargetingSystemPedPlayerComponent::useTargetRelativeMeleeCycling(this) )
        {
          v21 = UFG::ActionDef_TargetCycle.mDataPerController[v7];
          if ( v21 && v21->mActionTrue )
            v6 = 1;
          return v6;
        }
        if ( v1->m_bHasFullAimInputTransition )
        {
          if ( _S43 & 1 )
          {
            v22 = s_fMaxAngleRad;
          }
          else
          {
            _S43 |= 1u;
            v22 = FLOAT_0_87266463;
            s_fMaxAngleRad = FLOAT_0_87266463;
          }
          v23 = v1->m_vAimInputDir.x;
          if ( atan2f(
                 COERCE_FLOAT(LODWORD(v1->m_vAimInputDir.y) & _xmm),
                 COERCE_FLOAT(LODWORD(v1->m_vAimInputDir.x) & _xmm)) <= v22 )
          {
            v1->m_bTargetCycleDirectionLeft = v23 < 0.0;
            v1->m_bTargetCycleDesired = 1;
          }
        }
        if ( v1->m_bHasNoAimInputTransition
          && v1->m_bTargetCycleDesired
          && UFG::TargetingSystemPedPlayerComponent::ms_fTimeToTargetCycle > v1->m_fTimeSinceStartedInput )
        {
          v1->m_fTimeSinceStartedInput = UFG::TargetingSystemPedPlayerComponent::ms_fTimeToTargetCycle;
          v1->m_bTargetCycleDesired = 0;
          return 1;
        }
        if ( !v1->m_bHasAimInput )
          v1->m_bTargetCycleDesired = 0;
        return 0;
      case 6:
      case 7:
        v24 = UFG::ActionDef_TargetCycle.mDataPerController[v7];
        v25 = v24 && v24->mActionTrue;
        v26 = UFG::ActionDef_AimLocationHold.mDataPerController[v7];
        v27 = v26 && v26->mActionTrue;
        goto LABEL_72;
      case 8:
        v28 = UFG::ActionDef_TargetCycle.mDataPerController[v7];
        v25 = v28 && v28->mActionTrue;
        v29 = UFG::ActionDef_AimLocationToggle.mDataPerController[v7];
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
LABEL_72:
        if ( !v25 || v27 )
          return 0;
        return 1;
      case 9:
        v30 = UFG::ActionDef_TargetCycle.mDataPerController[v7];
        v31 = v30 && v30->mActionTrue;
        v32 = UFG::ActionDef_AimLocationToggle.mDataPerController[v7];
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
        v18 = v31 == 0;
LABEL_34:
        if ( v18 || v17 > 0.0 )
          return 0;
        return 1;
      case 10:
        v34 = UFG::ActionDef_TargetCycle.mDataPerController[v7];
        if ( v34 )
          v35 = v34->mAxisPositionX;
        else
          v35 = 0.0;
        LODWORD(v36) = LODWORD(v35) & _xmm;
        v37 = UFG::ActionDef_AimLocationToggle.mDataPerController[v7];
        v38 = v37 && v37->mActionTrue;
        if ( v36 > 0.0 && v38 )
          return 1;
        return 0;
      case 11:
        v39 = UFG::ActionDef_TargetCycle.mDataPerController[v7];
        if ( v39 && v39->mActionTrue )
          v40 = s_iNumTimesTargetCycleHit++ + 1;
        else
          v40 = s_iNumTimesTargetCycleHit;
        if ( v40 >= 2 )
        {
          s_iNumTimesTargetCycleHit = 0;
          return 1;
        }
        if ( v1->m_bHasAimInput )
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
void __usercall UFG::TargetingSystemPedPlayerComponent::canActionHijackThisVehicle(UFG::TargetingSystemPedPlayerComponent *this@<rcx>, UFG::SimObjectVehicle *pPotentialVehicleSimObject@<rdx>, UFG::qMatrix44 *pXform@<r8>, bool *bCanActionHijackThisVehicle@<r9>, float a5@<xmm0>, bool *bCanPotentiallyActionHijackThisVehicle)
{
  UFG::PhysicsMoverInterface *v6; // rbp
  bool *v7; // r13
  UFG::qMatrix44 *v8; // r14
  UFG::SimObjectVehicle *v9; // rbx
  UFG::TargetingSystemPedPlayerComponent *v10; // r15
  UFG::TargetingSystemVehicleComponent *v11; // rdi
  UFG::ActionHijackProfile *v12; // rdi
  UFG::PhysicsMoverInterface *v13; // rcx
  float v14; // xmm0_4
  float v15; // xmm6_4
  UFG::SimObject *v16; // r9
  float v17; // xmm8_4
  float v18; // xmm12_4
  float v19; // xmm13_4
  float v20; // xmm14_4
  unsigned __int16 v21; // cx
  unsigned int v22; // er8
  unsigned int v23; // er10
  signed __int64 v24; // rdx
  float v25; // xmm7_4
  float v26; // xmm9_4
  float v27; // xmm7_4
  float v28; // xmm10_4
  float v29; // xmm6_4
  bool v30; // bl
  float v31; // xmm0_4
  bool v32; // al
  bool v33; // al
  float v34; // xmm0_4
  float v35; // xmm6_4
  float v36; // xmm1_4
  float v37; // xmm8_4

  v6 = 0i64;
  *bCanActionHijackThisVehicle = 0;
  v7 = bCanActionHijackThisVehicle;
  v8 = pXform;
  v9 = pPotentialVehicleSimObject;
  *bCanPotentiallyActionHijackThisVehicle = 0;
  v10 = this;
  if ( !pPotentialVehicleSimObject
    || (v11 = (UFG::TargetingSystemVehicleComponent *)pPotentialVehicleSimObject->m_Components.p[20].m_pComponent) == 0i64
    || (UFG::TargetingSystemVehicleComponent::_TypeUID ^ v11->m_TypeUID) & 0xFE000000
    || UFG::TargetingSystemVehicleComponent::_TypeUID & ~v11->m_TypeUID & 0x1FFFFFF )
  {
    v12 = 0i64;
  }
  else
  {
    v12 = v11->m_pActionHijackProfile;
  }
  if ( !v12 )
    return;
  if ( !v12->m_bCanActionHijackTo )
    return;
  UFG::qAngleBetweenNormals(&this->m_vTargetingForward, (UFG::qVector3 *)pXform);
  if ( a5 > v12->m_fOrientationDeltaRadMax )
    return;
  if ( !v9 )
    return;
  v13 = (UFG::PhysicsMoverInterface *)v9->m_Components.p[34].m_pComponent;
  if ( !v13 )
    return;
  v14 = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(v13);
  v15 = v14;
  if ( !UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreSpeed && v14 < v12->m_fVehicleSpeedMinKPH )
    return;
  v16 = v10->m_pOccupantOfVehicle.m_pPointer;
  v17 = v10->m_vTargetingPosition.y - v8->v3.y;
  v18 = v10->m_vTargetingPosition.x - v8->v3.x;
  v19 = v10->m_vTargetingPosition.z - v8->v3.z;
  v20 = (float)((float)(v17 * v10->m_vTargetingForward.y) + (float)(v18 * v10->m_vTargetingForward.x))
      + (float)(v19 * v10->m_vTargetingForward.z);
  if ( !v16 )
    goto LABEL_30;
  v21 = v16->m_Flags;
  if ( (v21 >> 14) & 1 )
    goto LABEL_30;
  if ( (v21 & 0x8000u) == 0 )
  {
    if ( (v21 >> 13) & 1 )
      goto LABEL_30;
    if ( (v21 >> 12) & 1 )
    {
      v22 = (unsigned int)v16[1].vfptr;
      v23 = v16->m_Components.size;
      if ( v22 < v23 )
      {
        v24 = (signed __int64)&v16->m_Components.p[v22];
        while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
             || UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF )
        {
          ++v22;
          v24 += 16i64;
          if ( v22 >= v23 )
            goto LABEL_28;
        }
        v6 = *(UFG::PhysicsMoverInterface **)v24;
      }
    }
    else
    {
      v6 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(v16, UFG::PhysicsMoverInterface::_TypeUID);
    }
  }
  else
  {
    v6 = (UFG::PhysicsMoverInterface *)v16->m_Components.p[34].m_pComponent;
  }
LABEL_28:
  if ( v6 )
  {
    v25 = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(v6);
    goto LABEL_31;
  }
LABEL_30:
  v25 = FLOAT_N1_0;
LABEL_31:
  v26 = v12->m_fSpeedDifferenceModifiesDistanceAheadStart;
  LODWORD(v27) = COERCE_UNSIGNED_INT(v25 - v15) & _xmm;
  if ( v27 <= v26 )
    v27 = v12->m_fSpeedDifferenceModifiesDistanceAheadStart;
  if ( v27 >= v12->m_fSpeedDifferenceModifiesDistanceAheadEnd )
    v27 = v12->m_fSpeedDifferenceModifiesDistanceAheadEnd;
  v29 = v12->m_fDistanceAheadOfTargetMax;
  v28 = v12->m_fSpeedDifferenceModifiesDistanceAheadEnd - v26;
  v30 = (float)(v12->m_fDistanceAheadOfTargetMax
              - (float)((float)(UFG::ActionHijackProfile::GetDistanceBehindTargetMax(v12) + v29)
                      * (float)((float)(v27 - v26) / v28))) >= v20;
  v31 = UFG::ActionHijackProfile::GetDistanceBehindTargetMax(v12);
  *bCanPotentiallyActionHijackThisVehicle = v30;
  v32 = v30 && v20 >= COERCE_FLOAT(LODWORD(v31) ^ _xmm[0]);
  if ( UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreDistance || v32 )
  {
    *bCanPotentiallyActionHijackThisVehicle = 1;
    v33 = UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreDistance;
    if ( !UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreDistance )
    {
      v34 = v8->v3.x - v10->m_vTargetingPosition.x;
      v36 = v8->v3.z - v10->m_vTargetingPosition.z;
      v35 = v8->v3.y - v10->m_vTargetingPosition.y;
      if ( (float)((float)((float)(v35 * v35) + (float)(v34 * v34)) + (float)(v36 * v36)) > UFG::ActionHijackProfile::GetDistanceSquaredMax(v12) )
        return;
      v33 = UFG::TargetingSystemPedPlayerComponent::ms_bActionHijackIgnoreDistance;
    }
    v37 = (float)((float)(v17 * v8->v1.y) + (float)(v18 * v8->v1.x)) + (float)(v19 * v8->v1.z);
    if ( v33 || COERCE_FLOAT(LODWORD(v37) & _xmm) <= UFG::ActionHijackProfile::GetDistanceToSideMax(v12) )
    {
      *v7 = 1;
      *bCanPotentiallyActionHijackThisVehicle = 1;
    }
  }
}

// File Line: 2262
// RVA: 0x572600
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateFocusTargetStep2(UFG::TargetingSystemPedPlayerComponent *this, UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList, UFG::qFixedArray<UFG::CloseTarget *,5> *closePickupsList, UFG::qFixedArray<UFG::CloseTarget *,5> *closePropsList)
{
  UFG::qFixedArray<UFG::CloseTarget *,80> *v4; // r14
  UFG::TargetingSystemPedPlayerComponent *v5; // rbx
  UFG::eFocusModeEnum v6; // eax
  bool v7; // r12
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rdi
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rax
  unsigned int v11; // er8
  unsigned int v12; // er9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rsi
  signed __int64 v14; // rdx
  unsigned int v15; // er8
  unsigned int v16; // er9
  unsigned int v17; // er8
  unsigned int v18; // er9
  float v19; // xmm0_4
  unsigned __int8 v20; // cl
  bool v21; // r15
  unsigned int v22; // ebp
  unsigned int v23; // esi
  signed __int64 v24; // r14
  UFG::SimObject *v25; // rdi
  UFG::qMatrix44 *v26; // r9
  float v27; // xmm0_4
  __int64 v28; // rax
  UFG::ScoredTarget *v29; // rax
  UFG::ScoredTarget *v30; // rsi
  UFG::SimObject *v31; // rdx
  unsigned __int8 v32; // al
  UFG::SimObject *v33; // rcx
  UFG::ActionTreeComponent *v34; // rdi
  unsigned __int16 v35; // dx
  unsigned int v36; // er8
  unsigned int v37; // er9
  signed __int64 v38; // rdx
  UFG::SimObject *v39; // rcx
  UFG::HealthComponent *v40; // rax
  unsigned __int16 v41; // dx
  unsigned int v42; // er8
  unsigned int v43; // er9
  UFG::SimComponentHolder *v44; // rsi
  signed __int64 v45; // rdx
  unsigned int v46; // er8
  unsigned int v47; // er9
  unsigned __int8 v48; // cl
  signed __int64 v49; // rdi
  UFG::TargetingSimObject *v50; // rax
  UFG::qMatrix44 matSimObject; // [rsp+40h] [rbp-6B8h]
  UFG::qFixedArray<UFG::ScoredTarget,100> potentialTargets; // [rsp+80h] [rbp-678h]

  v4 = closePedsList;
  v5 = this;
  potentialTargets.size = 0;
  v6 = this->m_eFocusMode;
  v7 = v6 == 2;
  if ( (unsigned int)(v6 - 3) > 1 && !v7 )
    goto LABEL_41;
  v8 = this->m_pAimingPlayerComponent.m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
  if ( !v8 )
    goto LABEL_41;
  v9 = WORD2(v8[4].mNext);
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::SimComponent *)v8[6].mNext[44].mPrev;
    goto LABEL_30;
  }
  if ( (v9 & 0x8000u) != 0 )
  {
    v11 = (unsigned int)v8[8].mPrev;
    v12 = (unsigned int)v8[6].mPrev;
    if ( v11 < v12 )
    {
      v13 = v8[6].mNext;
      while ( 1 )
      {
        v14 = v11;
        if ( ((_QWORD)v13[v11].mNext & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && !(UFG::CharacterOccupantComponent::_TypeUID & ~LODWORD(v13[v11].mNext) & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v11 >= v12 )
          goto LABEL_14;
      }
LABEL_13:
      v10 = (UFG::SimComponent *)v13[v14].mPrev;
      goto LABEL_30;
    }
    goto LABEL_14;
  }
  if ( (v9 >> 13) & 1 )
  {
    v15 = (unsigned int)v8[8].mPrev;
    v16 = (unsigned int)v8[6].mPrev;
    if ( v15 < v16 )
    {
      v13 = v8[6].mNext;
      while ( 1 )
      {
        v14 = v15;
        if ( ((_QWORD)v13[v15].mNext & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && !(UFG::CharacterOccupantComponent::_TypeUID & ~LODWORD(v13[v15].mNext) & 0x1FFFFFF) )
        {
          goto LABEL_13;
        }
        if ( ++v15 >= v16 )
          goto LABEL_14;
      }
    }
    goto LABEL_14;
  }
  if ( (v9 >> 12) & 1 )
  {
    v17 = (unsigned int)v8[8].mPrev;
    v18 = (unsigned int)v8[6].mPrev;
    if ( v17 < v18 )
    {
      v13 = v8[6].mNext;
      do
      {
        v14 = v17;
        if ( ((_QWORD)v13[v17].mNext & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && !(UFG::CharacterOccupantComponent::_TypeUID & ~LODWORD(v13[v17].mNext) & 0x1FFFFFF) )
        {
          goto LABEL_13;
        }
      }
      while ( ++v17 < v18 );
    }
LABEL_14:
    v10 = 0i64;
    goto LABEL_30;
  }
  v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v8, UFG::CharacterOccupantComponent::_TypeUID);
LABEL_30:
  if ( v10 )
  {
    if ( !v10[1].m_BoundComponentHandles.mNode.mPrev )
      goto LABEL_41;
    v8 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v10[1].m_BoundComponentHandles.mNode.mPrev[2].mNext;
  }
  if ( v8 )
  {
    UFG::TargetingSystemBaseComponent::FindMatrix(
      (UFG::TransformNodeComponent *)v8[5].mNext,
      (UFG::SimObject *)v8,
      &matSimObject);
    v19 = UFG::TargetingSystemPedPlayerComponent::scoreSoftLockTarget(
            v5,
            &v5->m_vTargetingPosition,
            (UFG::SimObject *)v8,
            &matSimObject,
            v5->m_pOccupantOfVehicle.m_pPointer);
    if ( v19 >= 0.0 )
    {
      if ( v5->m_eDesiredFocusMode == 1 && v5->m_pOccupantOfVehicle.m_pPointer )
        v19 = UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(
                v5,
                &v5->m_vTargetingPosition,
                (UFG::SimObject *)v8,
                &matSimObject,
                0,
                0);
      if ( v19 >= 0.0 )
      {
        v20 = v5->m_pTargetingMap->m_Map.p[22];
        if ( v20 )
          UFG::TargetingSimObject::SetTarget(&v5->m_pTargets[v20], (UFG::SimObject *)v8);
        return;
      }
    }
  }
LABEL_41:
  v21 = v5->m_bHasRangedWeapon && (unsigned int)(v5->m_eFocusMode - 1) <= 3;
  v22 = v4->size;
  v23 = 0;
  if ( v4->size )
  {
    v24 = (signed __int64)v4->p;
    while ( 1 )
    {
      v25 = *(UFG::SimObject **)(*(_QWORD *)(*(_QWORD *)v24 + 8i64) + 40i64);
      if ( !v25 )
        return;
      v26 = (UFG::qMatrix44 *)(*(_QWORD *)v24 + 16i64);
      if ( !v21 )
        break;
      if ( !v7 )
      {
        if ( v5->m_pOccupantOfVehicle.m_pPointer && v5->m_bFocusModeJustRequested && !v5->m_bHasNoAimInputTransition )
          v27 = UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(v5, &v5->m_vTargetingPosition, v25, v26, 0, 1);
        else
          v27 = UFG::TargetingSystemPedPlayerComponent::scoreSoftLockTarget(
                  v5,
                  &v5->m_vTargetingPosition,
                  v25,
                  v26,
                  v5->m_pOccupantOfVehicle.m_pPointer);
LABEL_56:
        if ( v27 >= 0.0 && potentialTargets.size < 0x64 )
        {
          v28 = potentialTargets.size;
          ++potentialTargets.size;
          potentialTargets.p[v28].m_pSimObject = v25;
          potentialTargets.p[v28].m_fScore = v27;
        }
      }
      ++v23;
      v24 += 8i64;
      if ( v23 >= v22 )
        goto LABEL_60;
    }
    v27 = UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(v5, &v5->m_vTargetingPosition, v25, v26, 1, 0);
    goto LABEL_56;
  }
LABEL_60:
  UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
    (ClassTypeDescriptor *)potentialTargets.p,
    (ClassTypeDescriptor *)&matSimObject.v3.z + (signed int)potentialTargets.size,
    (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
  v29 = UFG::TargetingSystemPedPlayerComponent::chooseBestVisibleTarget(
          v5,
          &potentialTargets,
          UFG::TargetingSystemPedPlayerComponent::ms_MaxRaycastsBeforeGiveUpNormally);
  v30 = v29;
  v5->m_bHasPriorityTarget = 0;
  if ( v29 && (v31 = v29->m_pSimObject) != 0i64 )
  {
    v32 = v5->m_pTargetingMap->m_Map.p[22];
    if ( v32 )
      UFG::TargetingSimObject::SetTarget(&v5->m_pTargets[v32], v31);
    if ( v30->m_fScore >= 0.0 && v30->m_fScore < 2.0 )
    {
      v33 = v30->m_pSimObject;
      if ( !v33 )
      {
LABEL_67:
        v34 = 0i64;
        goto LABEL_82;
      }
      v35 = v33->m_Flags;
      if ( (v35 >> 14) & 1 )
      {
        v34 = (UFG::ActionTreeComponent *)v33->m_Components.p[7].m_pComponent;
      }
      else if ( (v35 & 0x8000u) == 0 )
      {
        if ( (v35 >> 13) & 1 )
        {
          v34 = (UFG::ActionTreeComponent *)v33->m_Components.p[6].m_pComponent;
        }
        else if ( (v35 >> 12) & 1 )
        {
          v36 = (unsigned int)v33[1].vfptr;
          v37 = v33->m_Components.size;
          if ( v36 >= v37 )
            goto LABEL_67;
          while ( 1 )
          {
            v38 = (signed __int64)&v33->m_Components.p[v36];
            if ( (*(_DWORD *)(v38 + 8) & 0xFE000000) == (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
              && !(UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF) )
            {
              break;
            }
            if ( ++v36 >= v37 )
              goto LABEL_67;
          }
          v34 = *(UFG::ActionTreeComponent **)v38;
        }
        else
        {
          v34 = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(v33, UFG::ActionTreeComponent::_TypeUID);
        }
      }
      else
      {
        v34 = (UFG::ActionTreeComponent *)v33->m_Components.p[7].m_pComponent;
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
      if ( (v41 >> 14) & 1 )
      {
        v40 = (UFG::HealthComponent *)v39->m_Components.p[6].m_pComponent;
        goto LABEL_104;
      }
      if ( (v41 & 0x8000u) != 0 )
      {
        v40 = (UFG::HealthComponent *)v39->m_Components.p[6].m_pComponent;
        goto LABEL_104;
      }
      if ( (v41 >> 13) & 1 )
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
            && !(UFG::HealthComponent::_TypeUID & ~v44[v42].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v42 >= v43 )
            goto LABEL_83;
        }
      }
      else
      {
        if ( !((v41 >> 12) & 1) )
        {
          v40 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(v39, UFG::HealthComponent::_TypeUID);
LABEL_104:
          if ( !UFG::IsDowned(v34, v40) )
            v5->m_bHasPriorityTarget = 1;
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
            && !(UFG::HealthComponent::_TypeUID & ~v44[v46].m_TypeUID & 0x1FFFFFF) )
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
    v48 = v5->m_pTargetingMap->m_Map.p[22];
    if ( v48 )
    {
      v49 = v48;
      UFG::TargetingSimObject::SetTarget(&v5->m_pTargets[v49], 0i64);
      v50 = v5->m_pTargets;
      if ( v50[v49].m_bLock )
        v50[v49].m_bLock = 0;
    }
  }
}

// File Line: 2459
// RVA: 0x571850
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateFocusTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList, UFG::qFixedArray<UFG::CloseTarget *,5> *closePickupsList, UFG::qFixedArray<UFG::CloseTarget *,5> *closePropsList, UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList, UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList)
{
  UFG::qFixedArray<UFG::CloseTarget *,5> *v6; // r12
  UFG::qFixedArray<UFG::CloseTarget *,80> *v7; // r13
  UFG::qFixedArray<UFG::CloseTarget *,5> *v8; // r15
  UFG::TargetingSystemPedPlayerComponent *v9; // rsi
  UFG::TargetingSimObject *v10; // rax
  signed __int64 v11; // rcx
  bool v12; // bp
  char v13; // al
  UFG::qFixedArray<UFG::CloseTarget,100> *v14; // r14
  UFG::SimComponent *v15; // rdi
  unsigned int v16; // ebx
  ActionID *v17; // rax
  UFG::SimComponent *v18; // rbx
  unsigned int v19; // edi
  ActionID *v20; // rax
  char v21; // al
  UFG::SimComponent *v22; // rax
  int v23; // ecx
  bool v24; // al
  UFG::InputActionData *v25; // rcx
  float v26; // xmm0_4
  UFG::SimObject *v27; // rbx
  UFG::SimComponent *v28; // rax
  float v29; // xmm0_4
  UFG::eFocusModeEnum v30; // eax
  UFG::qFixedArray<UFG::CloseTarget *,20> *v31; // rdi
  UFG::eFocusModeEnum v32; // ebx
  UFG::TargetingMap *v33; // rax
  hkLocalFrameGroup *v34; // rdi
  unsigned __int16 v35; // cx
  unsigned int v36; // er8
  unsigned int v37; // er9
  signed __int64 v38; // rdx
  hkSimpleLocalFrame *v39; // rbx
  unsigned int v40; // er8
  unsigned int v41; // er9
  unsigned int v42; // er8
  unsigned int v43; // er9
  unsigned __int16 v44; // dx
  UFG::SimComponent *v45; // rax
  unsigned int v46; // er8
  unsigned int v47; // er9
  signed __int64 v48; // rdx
  unsigned int v49; // er8
  unsigned int v50; // er9
  char v51; // bp
  bool v52; // r14
  unsigned __int16 v53; // dx
  UFG::SimComponent *v54; // rdi
  signed __int64 v55; // rdx
  unsigned int v56; // ebx
  ActionID *v57; // rax
  char v58; // al
  UFG::qFixedArray<UFG::CloseTarget *,20> *v59; // rax
  UFG::TargetingMap *v60; // rax
  UFG::SimObject *v61; // rdi
  unsigned __int16 v62; // cx
  hkLocalFrameGroup *v63; // rbp
  signed __int64 v64; // rdx
  hkSimpleLocalFrame *v65; // rbx
  unsigned __int16 v66; // dx
  UFG::SimComponent *v67; // rax
  signed __int64 v68; // rdx
  unsigned __int16 v69; // cx
  UFG::SimComponent *v70; // rax
  signed __int64 v71; // rdx
  int v72; // ecx
  bool v73; // zf
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v74; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v75; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v76; // rax
  __int64 bUseCones; // [rsp+20h] [rbp-D8h]
  const char *bInitialAcquisition; // [rsp+28h] [rbp-D0h]
  bool bTargetVehicleHasOccupant; // [rsp+60h] [rbp-98h]
  bool bIsSocialActionAvailable; // [rsp+61h] [rbp-97h]
  bool bIsTargetVehicle; // [rsp+62h] [rbp-96h]
  bool bIsScripted; // [rsp+63h] [rbp-95h]
  bool bIsKnockedOut; // [rsp+64h] [rbp-94h]
  bool bIsDowned; // [rsp+65h] [rbp-93h]
  UFG::eFactionStandingEnum eFactionStanding; // [rsp+68h] [rbp-90h]
  UFG::SimObject *pPedTarget; // [rsp+70h] [rbp-88h]
  UFG::qMatrix44 matSimObject; // [rsp+80h] [rbp-78h]
  bool bShouldRejectTarget; // [rsp+100h] [rbp+8h]

  v6 = closePickupsList;
  v7 = closePedsList;
  v8 = closePropsList;
  v9 = this;
  if ( !this->m_pFocusModeOverrideSimObject.m_pPointer )
  {
    UFG::TargetingSystemPedPlayerComponent::maybeReleaseLockedTarget(this);
    v10 = v9->m_pTargets;
    v11 = (unsigned __int8)v9->m_pTargetingMap->m_Map.p[22];
    v12 = v10[v11].m_pTarget.m_pPointer && v10[v11].m_bLock;
    v13 = UFG::TargetingSystemPedPlayerComponent::shouldCycleTarget(v9);
    v14 = closeTargetsList;
    if ( v13 )
    {
      v15 = v9->m_pActionTreeComponent.m_pSimComponent;
      if ( v15 )
      {
        v16 = UFG::GetActionMostUsedIndex_Grapple();
        v17 = UFG::GetActionID_Grapple();
        if ( !ActionController::IsPlaying((ActionController *)&v15[3], v17, v16, 0)
          || (v18 = v9->m_pActionTreeComponent.m_pSimComponent,
              v19 = UFG::GetActionMostUsedIndex_Hostage(),
              v20 = UFG::GetActionID_Hostage(),
              ActionController::IsPlaying((ActionController *)&v18[3], v20, v19, 1)) )
        {
          if ( UFG::TargetingSystemPedPlayerComponent::useTargetRelativeMeleeCycling(v9) )
          {
            v21 = UFG::TargetingSystemPedPlayerComponent::cycleTargetManual(v9, v14);
          }
          else
          {
            v22 = v9->m_pAICharacterControllerComponent.m_pSimComponent;
            v23 = 0;
            if ( v22 )
              v23 = (int)v22[17].m_SafePointerList.mNode.mPrev;
            if ( UFG::TargetingSystemPedPlayerComponent::ms_eTargetCycleAndLocationTargetingModeEnum == 5 )
            {
              v24 = v9->m_bTargetCycleDirectionLeft;
            }
            else
            {
              v25 = UFG::ActionDef_TargetCycle.mDataPerController[v23];
              if ( v25 )
                v26 = v25->mAxisRawX[0];
              else
                v26 = 0.0;
              v24 = v26 < 0.0;
            }
            v21 = UFG::TargetingSystemPedPlayerComponent::cycleTarget(
                    v9,
                    (UFG::TargetingSystemPedPlayerComponent::eCycleTargetDirectionEnum)(v24 == 0),
                    v14);
          }
          if ( v21 )
          {
            v27 = v9->m_pTargets[(unsigned __int8)v9->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
            if ( v27 )
            {
              UFG::TargetingSystemBaseComponent::FindMatrix(v27->m_pTransformNodeComponent, v27, &matSimObject);
              if ( UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(
                     v9,
                     &v9->m_vTargetingPosition,
                     v27,
                     &matSimObject,
                     0,
                     0) >= 0.0 )
              {
                v28 = v9->m_pEquippedSOWPC.m_pPointer;
                if ( v28 )
                {
                  v29 = *(float *)(*((_QWORD *)&v28[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                   + HIDWORD(v28[2].m_pSimObject))
                                 + 400i64);
                  if ( v29 < 0.0 )
                    *(float *)&v9->m_pAimingPlayerComponent.m_pSimComponent[1].m_NameUID = v29;
                }
                LOBYTE(closePickupsList) = 1;
                ((void (__fastcall *)(UFG::TargetingSystemPedPlayerComponent *, signed __int64, UFG::qFixedArray<UFG::CloseTarget *,5> *))v9->vfptr[14].__vecDelDtor)(
                  v9,
                  22i64,
                  closePickupsList);
                v12 = 1;
                if ( (unsigned int)(v9->m_eFocusMode - 2) <= 2 )
                {
                  v9->m_eDesiredFocusMode = 2;
                  v9->m_eFocusMode = 2;
                  LOBYTE(v9->m_pAimingPlayerComponent.m_pSimComponent[12].m_SafePointerList.mNode.mNext) = 1;
                  if ( v9->m_bTargetAutoAcquisition )
                    HIDWORD(v9->m_pAimingPlayerComponent.m_pSimComponent[12].m_pSimObject) = 22;
                }
              }
            }
          }
        }
      }
    }
    v30 = v9->m_eFocusMode;
    if ( v30 == 4 )
    {
      v59 = closeVehiclesList;
      v9->m_eDesiredFocusMode = 3;
      v9->m_eFocusMode = 3;
      UFG::TargetingSystemPedPlayerComponent::updateFocusTargetStep2(v9, v7, v6, v8, v59, v14);
      v9->m_eDesiredFocusMode = 4;
      v9->m_eFocusMode = 4;
      goto LABEL_116;
    }
    if ( !v12 || v30 == 3 )
    {
      v31 = closeVehiclesList;
      UFG::TargetingSystemPedPlayerComponent::updateFocusTargetStep2(v9, v7, v6, v8, closeVehiclesList, v14);
      if ( !v9->m_pTargets[(unsigned __int8)v9->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer
        && (unsigned int)(v9->m_eFocusMode - 1) <= 1 )
      {
        if ( v9->m_bHasRangedWeapon )
        {
          v32 = v9->m_eDesiredFocusMode;
          v9->m_eFocusMode = 3;
          v9->m_eDesiredFocusMode = 3;
          UFG::TargetingSystemPedPlayerComponent::updateTargetingIntentions(v9);
          UFG::TargetingSystemPedPlayerComponent::updateFocusTargetStep2(v9, v7, v6, v8, v31, v14);
          v33 = v9->m_pTargetingMap;
          v9->m_eDesiredFocusMode = v32;
          v34 = (hkLocalFrameGroup *)v9->m_pTargets[(unsigned __int8)v33->m_Map.p[22]].m_pTarget.m_pPointer;
          if ( v32 == 1 )
          {
            if ( v34 )
            {
              v35 = WORD2(v34[3].vfptr);
              if ( (v35 >> 14) & 1 )
              {
                v36 = *(_DWORD *)&v34[5].m_memSizeAndFlags;
                v37 = (unsigned int)v34[4].vfptr;
                if ( v36 < v37 )
                {
                  v38 = *(_QWORD *)&v34[4].m_memSizeAndFlags + 16i64 * v36;
                  while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                       || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF )
                  {
                    ++v36;
                    v38 += 16i64;
                    if ( v36 >= v37 )
                      goto LABEL_44;
                  }
LABEL_45:
                  v39 = *(hkSimpleLocalFrame **)v38;
                  goto LABEL_63;
                }
              }
              else
              {
                if ( (v35 & 0x8000u) != 0 )
                {
                  v39 = *(hkSimpleLocalFrame **)(*(_QWORD *)&v34[4].m_memSizeAndFlags + 480i64);
                  goto LABEL_63;
                }
                if ( (v35 >> 13) & 1 )
                {
                  v40 = *(_DWORD *)&v34[5].m_memSizeAndFlags;
                  v41 = (unsigned int)v34[4].vfptr;
                  if ( v40 < v41 )
                  {
                    v38 = *(_QWORD *)&v34[4].m_memSizeAndFlags + 16i64 * v40;
                    while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                         || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF )
                    {
                      ++v40;
                      v38 += 16i64;
                      if ( v40 >= v41 )
                      {
                        v39 = 0i64;
                        goto LABEL_63;
                      }
                    }
                    goto LABEL_45;
                  }
                }
                else
                {
                  if ( !((v35 >> 12) & 1) )
                  {
                    v39 = (hkSimpleLocalFrame *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)v34,
                                                  UFG::VehicleOccupantComponent::_TypeUID);
                    goto LABEL_63;
                  }
                  v42 = *(_DWORD *)&v34[5].m_memSizeAndFlags;
                  v43 = (unsigned int)v34[4].vfptr;
                  if ( v42 < v43 )
                  {
                    v38 = *(_QWORD *)&v34[4].m_memSizeAndFlags + 16i64 * v42;
                    while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                         || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF )
                    {
                      ++v42;
                      v38 += 16i64;
                      if ( v42 >= v43 )
                      {
                        v39 = 0i64;
                        goto LABEL_63;
                      }
                    }
                    goto LABEL_45;
                  }
                }
              }
LABEL_44:
              v39 = 0i64;
LABEL_63:
              if ( v39 && Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v39) )
                v34 = Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v39);
              if ( !v34 )
                goto LABEL_90;
              v44 = WORD2(v34[3].vfptr);
              if ( (v44 >> 14) & 1 )
              {
                v45 = *(UFG::SimComponent **)(*(_QWORD *)&v34[4].m_memSizeAndFlags + 96i64);
LABEL_87:
                if ( v45 && BYTE4(v45[1].m_BoundComponentHandles.mNode.mPrev) )
                {
                  v51 = 1;
                  goto LABEL_91;
                }
LABEL_90:
                v51 = 0;
LABEL_91:
                v52 = UFG::TargetingSystemPedBaseComponent::isHostileToMe(
                        (UFG::TargetingSystemPedBaseComponent *)&v9->vfptr,
                        (UFG::SimObject *)v34);
                if ( !v34 )
                  goto LABEL_207;
                v53 = WORD2(v34[3].vfptr);
                if ( (v53 >> 14) & 1 )
                {
                  v54 = *(UFG::SimComponent **)(*(_QWORD *)&v34[4].m_memSizeAndFlags + 112i64);
                }
                else if ( (v53 & 0x8000u) == 0 )
                {
                  if ( (v53 >> 13) & 1 )
                  {
                    v54 = *(UFG::SimComponent **)(*(_QWORD *)&v34[4].m_memSizeAndFlags + 96i64);
                  }
                  else if ( (v53 >> 12) & 1 )
                  {
                    closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)*(unsigned int *)&v34[5].m_memSizeAndFlags;
                    closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)LODWORD(v34[4].vfptr);
                    if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
                    {
LABEL_104:
                      v54 = 0i64;
                    }
                    else
                    {
                      v55 = *(_QWORD *)&v34[4].m_memSizeAndFlags + 16i64 * (unsigned int)closePickupsList;
                      while ( (*(_DWORD *)(v55 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                           || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v55 + 8) & 0x1FFFFFF )
                      {
                        closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)(unsigned int)((_DWORD)closePickupsList
                                                                                                  + 1);
                        v55 += 16i64;
                        if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
                          goto LABEL_104;
                      }
                      v54 = *(UFG::SimComponent **)v55;
                    }
                  }
                  else
                  {
                    v54 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v34, UFG::ActionTreeComponent::_TypeUID);
                  }
                }
                else
                {
                  v54 = *(UFG::SimComponent **)(*(_QWORD *)&v34[4].m_memSizeAndFlags + 112i64);
                }
                if ( v54
                  && (v56 = UFG::GetActionMostUsedIndex_Hostage(),
                      v57 = UFG::GetActionID_Hostage(),
                      ActionController::IsPlaying((ActionController *)&v54[3], v57, v56, 1)) )
                {
                  v58 = 1;
                }
                else
                {
LABEL_207:
                  v58 = 0;
                }
                if ( v52 && !v51 && !v58 )
                {
                  v9->m_eDesiredFocusMode = 1;
                  v9->m_eFocusMode = 1;
                }
                goto LABEL_116;
              }
              if ( (v44 & 0x8000u) != 0 )
              {
                v45 = *(UFG::SimComponent **)(*(_QWORD *)&v34[4].m_memSizeAndFlags + 96i64);
                goto LABEL_87;
              }
              if ( (v44 >> 13) & 1 )
              {
                v46 = *(_DWORD *)&v34[5].m_memSizeAndFlags;
                v47 = (unsigned int)v34[4].vfptr;
                if ( v46 < v47 )
                {
                  v48 = *(_QWORD *)&v34[4].m_memSizeAndFlags + 16i64 * v46;
                  while ( (*(_DWORD *)(v48 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                       || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v48 + 8) & 0x1FFFFFF )
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
                if ( !((v44 >> 12) & 1) )
                {
                  v45 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v34, UFG::HealthComponent::_TypeUID);
                  goto LABEL_87;
                }
                v49 = *(_DWORD *)&v34[5].m_memSizeAndFlags;
                v50 = (unsigned int)v34[4].vfptr;
                if ( v49 < v50 )
                {
                  v48 = *(_QWORD *)&v34[4].m_memSizeAndFlags + 16i64 * v49;
                  while ( (*(_DWORD *)(v48 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                       || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v48 + 8) & 0x1FFFFFF )
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
  }
LABEL_116:
  v60 = v9->m_pTargetingMap;
  v9->m_bFocusTargetIsHostile = 0;
  v61 = v9->m_pTargets[(unsigned __int8)v60->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( !v61 )
    goto LABEL_190;
  v62 = v61->m_Flags;
  v63 = (hkLocalFrameGroup *)v9->m_pTargets[(unsigned __int8)v60->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( (v62 >> 14) & 1 )
  {
    closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)LODWORD(v61[1].vfptr);
    closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)v61->m_Components.size;
    if ( (unsigned int)closePickupsList < (unsigned int)closePropsList )
    {
      v64 = (signed __int64)&v61->m_Components.p[(unsigned int)closePickupsList];
      while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF )
      {
        closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)(unsigned int)((_DWORD)closePickupsList + 1);
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
    if ( (v62 & 0x8000u) != 0 )
    {
      v65 = (hkSimpleLocalFrame *)v61->m_Components.p[30].m_pComponent;
      goto LABEL_142;
    }
    if ( (v62 >> 13) & 1 )
    {
      closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)LODWORD(v61[1].vfptr);
      closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)v61->m_Components.size;
      if ( (unsigned int)closePickupsList < (unsigned int)closePropsList )
      {
        v64 = (signed __int64)&v61->m_Components.p[(unsigned int)closePickupsList];
        while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF )
        {
          closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)(unsigned int)((_DWORD)closePickupsList + 1);
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
      if ( !((v62 >> 12) & 1) )
      {
        v65 = (hkSimpleLocalFrame *)UFG::SimObject::GetComponentOfType(v61, UFG::VehicleOccupantComponent::_TypeUID);
        goto LABEL_142;
      }
      closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)LODWORD(v61[1].vfptr);
      closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)v61->m_Components.size;
      if ( (unsigned int)closePickupsList < (unsigned int)closePropsList )
      {
        v64 = (signed __int64)&v61->m_Components.p[(unsigned int)closePickupsList];
        while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF )
        {
          closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)(unsigned int)((_DWORD)closePickupsList + 1);
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
    v63 = Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v65);
  if ( !v63 )
    goto LABEL_169;
  v66 = WORD2(v63[3].vfptr);
  if ( !((v66 >> 14) & 1) )
  {
    if ( (v66 & 0x8000u) != 0 )
    {
      v67 = *(UFG::SimComponent **)(*(_QWORD *)&v63[4].m_memSizeAndFlags + 96i64);
      goto LABEL_166;
    }
    if ( (v66 >> 13) & 1 )
    {
      closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)*(unsigned int *)&v63[5].m_memSizeAndFlags;
      closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)LODWORD(v63[4].vfptr);
      if ( (unsigned int)closePickupsList < (unsigned int)closePropsList )
      {
        v68 = *(_QWORD *)&v63[4].m_memSizeAndFlags + 16i64 * (unsigned int)closePickupsList;
        while ( (*(_DWORD *)(v68 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v68 + 8) & 0x1FFFFFF )
        {
          closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)(unsigned int)((_DWORD)closePickupsList + 1);
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
      if ( !((v66 >> 12) & 1) )
      {
        v67 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v63, UFG::HealthComponent::_TypeUID);
        goto LABEL_166;
      }
      closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)*(unsigned int *)&v63[5].m_memSizeAndFlags;
      closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)LODWORD(v63[4].vfptr);
      if ( (unsigned int)closePickupsList < (unsigned int)closePropsList )
      {
        v68 = *(_QWORD *)&v63[4].m_memSizeAndFlags + 16i64 * (unsigned int)closePickupsList;
        while ( (*(_DWORD *)(v68 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v68 + 8) & 0x1FFFFFF )
        {
          closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)(unsigned int)((_DWORD)closePickupsList + 1);
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
  v67 = *(UFG::SimComponent **)(*(_QWORD *)&v63[4].m_memSizeAndFlags + 96i64);
LABEL_166:
  if ( v67 && !BYTE4(v67[1].m_BoundComponentHandles.mNode.mPrev) )
    v9->m_bFocusTargetIsHostile = UFG::TargetingSystemPedBaseComponent::isHostileToMe(
                                    (UFG::TargetingSystemPedBaseComponent *)&v9->vfptr,
                                    (UFG::SimObject *)v63);
LABEL_169:
  if ( v9->m_eFocusMode == 1 )
  {
    v69 = v61->m_Flags;
    if ( (v69 >> 14) & 1 )
    {
      v70 = v61->m_Components.p[3].m_pComponent;
    }
    else if ( (v69 & 0x8000u) == 0 )
    {
      if ( (v69 >> 13) & 1 )
      {
        v70 = v61->m_Components.p[4].m_pComponent;
      }
      else if ( (v69 >> 12) & 1 )
      {
        closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)LODWORD(v61[1].vfptr);
        closePropsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)v61->m_Components.size;
        if ( (unsigned int)closePickupsList >= (unsigned int)closePropsList )
        {
LABEL_182:
          v70 = 0i64;
        }
        else
        {
          v71 = (signed __int64)&v61->m_Components.p[(unsigned int)closePickupsList];
          while ( (*(_DWORD *)(v71 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v71 + 8) & 0x1FFFFFF )
          {
            closePickupsList = (UFG::qFixedArray<UFG::CloseTarget *,5> *)(unsigned int)((_DWORD)closePickupsList + 1);
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
      v72 = (int)v70[1].m_SafePointerList.mNode.mNext;
      if ( v72 == 1 || v72 == 4 && v9->m_bHasRangedWeapon )
      {
        UFG::TargetingSystemPedPlayerComponent::EnableRimLighting(v9, eTARGET_TYPE_FOCUS);
        goto LABEL_192;
      }
    }
  }
LABEL_190:
  if ( v9->m_RimLighting.m_bEnabled )
    v9->m_RimLighting.m_bEnabled = 0;
LABEL_192:
  if ( v61 )
  {
    if ( (unsigned int)(v9->m_eFocusMode - 1) > 1 )
    {
      LOBYTE(closePropsList) = 1;
      closePickupsList = 0i64;
      bInitialAcquisition = "TargetingSystemPedPlayerComponent::updateFocusTarget";
    }
    else
    {
      bInitialAcquisition = 0i64;
      closePropsList = 0i64;
      LOBYTE(closePickupsList) = 1;
    }
    LODWORD(bUseCones) = 0;
    ((void (__fastcall *)(UFG::TargetingSystemPedPlayerComponent *, signed __int64, UFG::qFixedArray<UFG::CloseTarget *,5> *, UFG::qFixedArray<UFG::CloseTarget *,5> *, __int64, const char *, _QWORD, _QWORD))v9->vfptr[14].__vecDelDtor)(
      v9,
      22i64,
      closePickupsList,
      closePropsList,
      bUseCones,
      bInitialAcquisition,
      0i64,
      0i64);
    if ( v9->m_bTargetAutoAcquisitionJustRequested )
    {
      v9->m_eDesiredFocusMode = 2;
      v9->m_eFocusMode = 2;
      LOBYTE(v9->m_pAimingPlayerComponent.m_pSimComponent[12].m_SafePointerList.mNode.mNext) = 1;
      v73 = v9->m_pFocusModeOverrideSimObject.m_pPointer == 0i64;
      bShouldRejectTarget = 0;
      if ( !v73
        || (UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(
              v9,
              v9->m_pTargets[(unsigned __int8)v9->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer,
              v9->m_bIsInAnyCombat,
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
        HIDWORD(v9->m_pAimingPlayerComponent.m_pSimComponent[12].m_pSimObject) = 22;
      }
    }
  }
  if ( v9->m_pFocusModeOverrideSimObject.m_pPointer && (unsigned int)(v9->m_eFocusMode - 1) <= 1 )
  {
    v74 = &v9->m_pFocusModeOverrideSimObject;
    if ( v74->m_pPointer )
    {
      v75 = v74->mPrev;
      v76 = v74->mNext;
      v75->mNext = v76;
      v76->mPrev = v75;
      v74->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v74->mPrev;
      v74->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v74->mPrev;
    }
    v74->m_pPointer = 0i64;
  }
}Available),
            !bShouldRejectTarget) )
      {
        HIDWORD(v9->m_pAimingPlayerComponent.m_pSimComponent[12].m_pSimObject) = 22;
      }
    }
  }
  if ( v9->m_pFocusModeOverrideSimObject.m_pPointer && (unsigned int)(v9->m_eFocusMode - 1) <= 1 )
  {
    v74 = &v9->m_pFocusModeOverrideSimObject;
    if ( v74->m_pPointer )
    {
      

// File Line: 2762
// RVA: 0x571590
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateDirectionalTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList)
{
  UFG::TargetingSystemPedPlayerComponent *v2; // rdi
  UFG::TargetingSimObject *v3; // rcx
  UFG::qMatrix44 *v4; // rbx
  __int64 v5; // rsi
  UFG::SimObject *v6; // rbp
  float v7; // xmm0_4
  int v8; // ecx
  __int64 v9; // rax
  UFG::ScoredTarget *v10; // rax
  UFG::SimObject *v11; // rdx
  unsigned __int8 v12; // cl
  unsigned __int8 v13; // cl
  signed __int64 v14; // rbx
  UFG::TargetingSimObject *v15; // rax
  ClassTypeDescriptor right; // [rsp+28h] [rbp-670h]
  ClassTypeDescriptor left[101]; // [rsp+38h] [rbp-660h]

  v2 = this;
  v3 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[48]];
  if ( (!v3->m_pTarget.m_pPointer || !v3->m_bLock) && !v2->m_pOccupantOfVehicle.m_pPointer )
  {
    LODWORD(right.mfnInPlaceNew) = 0;
    if ( closeTargetsList->size )
    {
      v4 = &closeTargetsList->p[0].m_Xform;
      v5 = closeTargetsList->size;
      while ( 1 )
      {
        v6 = *(UFG::SimObject **)(*(_QWORD *)&v4[-1].v3.z + 40i64);
        v7 = UFG::TargetingSystemPedPlayerComponent::scoreDirectionalTarget(v2, &v2->m_vTargetingPosition, v6, v4);
        if ( v7 < 0.0 )
          goto LABEL_9;
        v8 = (int)right.mfnInPlaceNew;
        if ( LODWORD(right.mfnInPlaceNew) < 0x64 )
          break;
LABEL_10:
        v4 = (UFG::qMatrix44 *)((char *)v4 + 80);
        if ( !--v5 )
          goto LABEL_13;
      }
      v9 = LODWORD(right.mfnInPlaceNew);
      ++LODWORD(right.mfnInPlaceNew);
      left[v9].mfnInPlaceNew = (void (__fastcall *)(void *))v6;
      *(float *)&left[v9].mUID = v7;
LABEL_9:
      v8 = (int)right.mfnInPlaceNew;
      goto LABEL_10;
    }
    v8 = (int)right.mfnInPlaceNew;
LABEL_13:
    UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
      left,
      &right + v8,
      (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
    v10 = UFG::TargetingSystemPedPlayerComponent::chooseBestVisibleTarget(
            v2,
            (UFG::qFixedArray<UFG::ScoredTarget,100> *)&right.mfnInPlaceNew,
            UFG::TargetingSystemPedPlayerComponent::ms_MaxRaycastsBeforeGiveUpNormally);
    if ( v10 && (v11 = v10->m_pSimObject) != 0i64 )
    {
      v12 = v2->m_pTargetingMap->m_Map.p[48];
      if ( v12 )
        UFG::TargetingSimObject::SetTarget(&v2->m_pTargets[v12], v11);
    }
    else
    {
      v13 = v2->m_pTargetingMap->m_Map.p[48];
      if ( v13 )
      {
        v14 = v13;
        UFG::TargetingSimObject::SetTarget(&v2->m_pTargets[v14], 0i64);
        v15 = v2->m_pTargets;
        if ( v15[v14].m_bLock )
          v15[v14].m_bLock = 0;
      }
    }
  }
}

// File Line: 2821
// RVA: 0x570A10
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateClosestDownedPedTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList)
{
  UFG::TargetingSystemPedPlayerComponent *rbx1; // rbx
  UFG::TargetingSimObject *v3; // rcx
  float *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm7_4
  float v7; // xmm0_4
  float v8; // xmm6_4
  unsigned int v9; // er14
  unsigned int v10; // esi
  float **v11; // rdi
  float *v12; // rcx
  float v13; // xmm1_4
  float v14; // xmm0_4
  __int64 v15; // rax
  float v16; // xmm1_4
  float v17; // xmm0_4
  UFG::SimObject *v18; // rbp
  float v19; // xmm1_4
  float v20; // xmm0_4
  UFG::ActionTreeComponent *v21; // rcx
  UFG::HealthComponent *v22; // rdx
  UFG::SimComponentHolder *v23; // rax
  unsigned __int8 v24; // cl
  signed __int64 v25; // rdi
  UFG::TargetingSimObject *v26; // rax
  unsigned __int8 v27; // cl
  UFG::qVector3 v2; // [rsp+20h] [rbp-48h]
  UFG::qVector3 v1; // [rsp+30h] [rbp-38h]

  rbx1 = this;
  v3 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[47]];
  if ( (!v3->m_pTarget.m_pPointer || !v3->m_bLock) && !rbx1->m_pOccupantOfVehicle.m_pPointer )
  {
    if ( rbx1->m_bHasPriorityTarget )
      goto LABEL_19;
    v4 = (float *)rbx1->m_pActiveTargetingProfile;
    v5 = v4[29];
    v6 = v4[8];
    if ( v5 <= 0.0 )
    {
      v8 = v4[14];
    }
    else
    {
      v7 = rbx1->m_fTargetingIntentionIdleTime / v5;
      if ( v7 > 1.0 )
        v7 = *(float *)&FLOAT_1_0;
      v8 = (float)((float)(1.0 - v7) * v4[14]) + (float)(v7 * v4[28]);
    }
    v9 = closePedsList->size;
    v10 = 0;
    if ( !closePedsList->size )
      goto LABEL_19;
    v11 = (float **)closePedsList->p;
    while ( 1 )
    {
      v12 = *v11;
      if ( v6 >= **v11 )
      {
        v13 = v12[16];
        v14 = v12[17];
        v15 = *((_QWORD *)v12 + 1);
        v1.z = 0.0;
        v16 = v13 - rbx1->m_vTargetingPosition.x;
        v17 = v14 - rbx1->m_vTargetingPosition.y;
        v18 = *(UFG::SimObject **)(v15 + 40);
        v2.z = 0.0;
        v1.x = v16;
        v19 = rbx1->m_vTargetingIntention.y;
        v1.y = v17;
        v20 = rbx1->m_vTargetingIntention.x;
        v2.y = v19;
        v2.x = v20;
        if ( UFG::qAngleBetween(&v1, &v2) <= v8 )
        {
          if ( v18 )
          {
            v23 = v18->m_Components.p;
            v21 = (UFG::ActionTreeComponent *)v23[7].m_pComponent;
            v22 = (UFG::HealthComponent *)v23[6].m_pComponent;
          }
          else
          {
            v21 = 0i64;
            v22 = 0i64;
          }
          if ( UFG::IsDowned(v21, v22) )
            break;
        }
      }
      ++v10;
      ++v11;
      if ( v10 >= v9 )
        goto LABEL_19;
    }
    if ( v18 )
    {
      v27 = rbx1->m_pTargetingMap->m_Map.p[47];
      if ( v27 )
        UFG::TargetingSimObject::SetTarget(&rbx1->m_pTargets[v27], v18);
    }
    else
    {
LABEL_19:
      v24 = rbx1->m_pTargetingMap->m_Map.p[47];
      if ( v24 )
      {
        v25 = v24;
        UFG::TargetingSimObject::SetTarget(&rbx1->m_pTargets[v25], 0i64);
        v26 = rbx1->m_pTargets;
        if ( v26[v25].m_bLock )
          v26[v25].m_bLock = 0;
      }
    }
  }
}

// File Line: 2893
// RVA: 0x570CF0
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateCrowdPushTargets(UFG::TargetingSystemPedPlayerComponent *this, UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList, UFG::qFixedArray<UFG::ClosePhysicalTarget,2> *closePhysicalDodgeableList)
{
  UFG::qFixedArray<UFG::ClosePhysicalTarget,2> *v3; // r12
  UFG::TargetingSystemPedPlayerComponent *v4; // rsi
  UFG::TargetingSimObject *v5; // rcx
  unsigned int v6; // eax
  unsigned int v7; // ebx
  float **v8; // r14
  __int64 v9; // r15
  float *v10; // rcx
  __int64 v11; // rdi
  float v12; // xmm9_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm6_4
  float v16; // xmm1_4
  UFG::ActionTreeComponent *v17; // rcx
  UFG::HealthComponent *v18; // rdx
  __int64 v19; // rax
  signed __int64 v20; // rax
  UFG::RigidBody **v21; // rdi
  __int64 v22; // r14
  float v23; // xmm8_4
  float v24; // xmm7_4
  float v25; // xmm9_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  signed __int64 v28; // rdx
  float v29; // xmm2_4
  UFG::SimObject *v30; // rdx
  UFG::SimObject *v31; // rdi
  unsigned int v32; // er8
  signed __int64 v33; // rax
  __m128i v34; // xmm1
  char *v35; // rcx
  unsigned int v36; // eax
  __int64 v37; // rdx
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  UFG::SimObject **v41; // rcx
  __int64 v42; // r8
  unsigned __int8 v43; // cl
  signed __int64 v44; // rbx
  UFG::TargetingSimObject *v45; // rax
  unsigned __int8 v46; // cl
  signed __int64 v47; // rbx
  UFG::TargetingSimObject *v48; // rax
  __m128i v49; // [rsp+20h] [rbp-C8h]
  UFG::SimObject *pNewTarget[2]; // [rsp+30h] [rbp-B8h]
  __int64 v51; // [rsp+40h] [rbp-A8h]
  UFG::qMatrix44 mat; // [rsp+50h] [rbp-98h]
  char v53; // [rsp+90h] [rbp-58h]

  v51 = -2i64;
  v3 = closePhysicalDodgeableList;
  v4 = this;
  v5 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[51]];
  if ( (!v5->m_pTarget.m_pPointer || !v5->m_bLock) && !v4->m_pOccupantOfVehicle.m_pPointer )
  {
    v6 = _S44;
    if ( !(_S44 & 1) )
    {
      v6 = _S44 | 1;
      _S44 |= 1u;
      s_fHalfAngleRange = FLOAT_1_3962635;
    }
    if ( !(v6 & 2) )
    {
      _S44 = v6 | 2;
      s_fMaxDistanceSquared = FLOAT_25_0;
    }
    v7 = 0;
    mat.v2.z = 0.0;
    if ( closePedsList->size )
    {
      v8 = (float **)closePedsList->p;
      v9 = closePedsList->size;
      do
      {
        v10 = *v8;
        if ( s_fMaxDistanceSquared >= **v8 )
        {
          v11 = *(_QWORD *)(*((_QWORD *)v10 + 1) + 40i64);
          if ( !v11 || !*(_QWORD *)(*(_QWORD *)(v11 + 104) + 704i64) )
          {
            v12 = v10[18] - v4->m_vTargetingPosition.z;
            v13 = v10[17] - v4->m_vTargetingPosition.y;
            v14 = v10[16] - v4->m_vTargetingPosition.x;
            v15 = s_fHalfAngleRange;
            *(float *)v49.m128i_i32 = v10[16] - v4->m_vTargetingPosition.x;
            *(__int64 *)((char *)v49.m128i_i64 + 4) = LODWORD(v13);
            v16 = v4->m_vTargetingForward.y;
            *(float *)pNewTarget = v4->m_vTargetingForward.x;
            *((float *)pNewTarget + 1) = v16;
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
              if ( !UFG::IsDowned(v17, v18) && v7 < 0x64 )
              {
                v20 = 2i64 * v7;
                LODWORD(mat.v2.z) = v7 + 1;
                *((_QWORD *)&mat.v3.z + v20) = v11;
                *(&mat.v3.x + 2 * v20) = (float)((float)(v13 * v13) + (float)(v14 * v14)) + (float)(v12 * v12);
                v7 = LODWORD(mat.v2.z);
              }
            }
          }
        }
        ++v8;
        --v9;
      }
      while ( v9 );
    }
    if ( v3->size )
    {
      v21 = (UFG::RigidBody **)&v3->p[0].m_pRigidBodyComponent;
      v22 = v3->size;
      do
      {
        if ( s_fMaxDistanceSquared >= *((float *)v21 - 2) )
        {
          UFG::RigidBody::GetTransform(*v21, &mat);
          v23 = mat.v1.w - v4->m_vTargetingPosition.y;
          v24 = mat.v1.z - v4->m_vTargetingPosition.x;
          v25 = v4->m_vTargetingPosition.z;
          v26 = s_fHalfAngleRange;
          *(float *)pNewTarget = mat.v1.z - v4->m_vTargetingPosition.x;
          *((float *)pNewTarget + 1) = v23;
          LODWORD(pNewTarget[1]) = 0;
          v27 = v4->m_vTargetingForward.y;
          v49.m128i_i32[0] = LODWORD(v4->m_vTargetingForward.x);
          *(__int64 *)((char *)v49.m128i_i64 + 4) = LODWORD(v27);
          if ( v26 >= UFG::qAngleBetween((UFG::qVector3 *)pNewTarget, (UFG::qVector3 *)&v49) && v7 < 0x64 )
          {
            v28 = 2i64 * v7;
            LODWORD(mat.v2.z) = v7 + 1;
            *((_QWORD *)&mat.v3.z + v28) = (*v21)->m_pSimObject;
            *(&mat.v3.x + 2 * v28) = (float)((float)(v24 * v24) + (float)(v23 * v23)) + (float)(v25 * v25);
            v7 = LODWORD(mat.v2.z);
          }
        }
        v21 += 2;
        --v22;
      }
      while ( v22 );
    }
    v29 = FLOAT_3_4028235e38;
    *(float *)pNewTarget = FLOAT_3_4028235e38;
    v30 = 0i64;
    pNewTarget[1] = 0i64;
    v49.m128i_i32[0] = 2139095039;
    v31 = 0i64;
    v49.m128i_i64[1] = 0i64;
    v32 = 0;
    v33 = 0i64;
    v34 = (__m128i)(unsigned __int64)pNewTarget[0];
    if ( (signed int)v7 >= 4 )
    {
      v35 = &v53;
      v36 = ((v7 - 4) >> 2) + 1;
      v37 = v36;
      v32 = 4 * v36;
      v33 = 4i64 * v36;
      do
      {
        v38 = *((float *)v35 - 4);
        if ( v38 >= v29 )
        {
          if ( v38 < *(float *)v49.m128i_i32 )
            v49 = *((__m128i *)v35 - 1);
        }
        else
        {
          _mm_store_si128(&v49, v34);
          v34 = *((__m128i *)v35 - 1);
          *(_OWORD *)pNewTarget = *((_OWORD *)v35 - 1);
          v29 = *(float *)pNewTarget;
        }
        if ( *(float *)v35 >= v29 )
        {
          if ( *(float *)v35 < *(float *)v49.m128i_i32 )
            v49 = *(__m128i *)v35;
        }
        else
        {
          _mm_store_si128(&v49, v34);
          v34 = *(__m128i *)v35;
          *(_OWORD *)pNewTarget = *(_OWORD *)v35;
          v29 = *(float *)pNewTarget;
        }
        v39 = *((float *)v35 + 4);
        if ( v39 >= v29 )
        {
          if ( v39 < *(float *)v49.m128i_i32 )
            v49 = *((__m128i *)v35 + 1);
        }
        else
        {
          _mm_store_si128(&v49, v34);
          v34 = *((__m128i *)v35 + 1);
          *(_OWORD *)pNewTarget = *((_OWORD *)v35 + 1);
          v29 = *(float *)pNewTarget;
        }
        v40 = *((float *)v35 + 8);
        if ( v40 >= v29 )
        {
          if ( v40 < *(float *)v49.m128i_i32 )
            v49 = *((__m128i *)v35 + 2);
        }
        else
        {
          _mm_store_si128(&v49, v34);
          v34 = *((__m128i *)v35 + 2);
          *(_OWORD *)pNewTarget = *((_OWORD *)v35 + 2);
          v29 = *(float *)pNewTarget;
        }
        v35 += 64;
        --v37;
      }
      while ( v37 );
      v30 = pNewTarget[1];
      v31 = (UFG::SimObject *)v49.m128i_i64[1];
    }
    if ( v32 < v7 )
    {
      v41 = (UFG::SimObject **)(&mat.v3 + v33);
      v42 = v7 - v32;
      do
      {
        if ( *(float *)v41 >= v29 )
        {
          if ( *(float *)v41 < *(float *)v49.m128i_i32 )
          {
            v49.m128i_i64[0] = (__int64)*v41;
            v31 = v41[1];
          }
        }
        else
        {
          _mm_store_si128(&v49, v34);
          pNewTarget[0] = *v41;
          v30 = v41[1];
          pNewTarget[1] = v41[1];
          v29 = *(float *)pNewTarget;
          v34 = *(__m128i *)pNewTarget;
          v31 = (UFG::SimObject *)v49.m128i_i64[1];
        }
        v41 += 2;
        --v42;
      }
      while ( v42 );
    }
    v43 = v4->m_pTargetingMap->m_Map.p[51];
    if ( v30 )
    {
      if ( v43 )
        UFG::TargetingSimObject::SetTarget(&v4->m_pTargets[v43], v30);
    }
    else if ( v43 )
    {
      v44 = v43;
      UFG::TargetingSimObject::SetTarget(&v4->m_pTargets[v44], 0i64);
      v45 = v4->m_pTargets;
      if ( v45[v44].m_bLock )
        v45[v44].m_bLock = 0;
    }
    v46 = v4->m_pTargetingMap->m_Map.p[52];
    if ( v31 )
    {
      if ( v46 )
        UFG::TargetingSimObject::SetTarget(&v4->m_pTargets[v46], v31);
    }
    else if ( v46 )
    {
      v47 = v46;
      UFG::TargetingSimObject::SetTarget(&v4->m_pTargets[v47], 0i64);
      v48 = v4->m_pTargets;
      if ( v48[v47].m_bLock )
        v48[v47].m_bLock = 0;
    }
  }
}

// File Line: 3043
// RVA: 0x57A470
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateTransitTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList)
{
  UFG::qFixedArray<UFG::CloseTarget *,20> *v2; // r14
  UFG::TargetingSystemPedPlayerComponent *v3; // r15
  UFG::CopSystem *v4; // rax
  signed __int64 v5; // rcx
  UFG::GameStatTracker *v6; // rax
  UFG::SimComponent *v7; // rsi
  UFG::SimObject *v8; // r13
  UFG::BaseCameraComponent *v9; // rcx
  UFG::Camera *v10; // rdi
  UFG::qMatrix44 *v11; // rbx
  UFG::qMatrix44 *v12; // rax
  float v13; // xmm12_4
  float v14; // ST44_4
  float v15; // xmm11_4
  float v16; // xmm10_4
  float v17; // xmm13_4
  float v18; // xmm14_4
  float v19; // xmm15_4
  float v20; // ST38_4
  float v21; // ST2C_4
  float v22; // ST34_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // xmm0_4
  __m128 v28; // xmm2
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm4_4
  __m128 v34; // xmm2
  float v35; // xmm0_4
  float v36; // xmm6_4
  float v37; // xmm0_4
  float v38; // xmm3_4
  unsigned int v39; // edx
  int v40; // er12
  __m128 v41; // xmm2
  float v42; // xmm8_4
  unsigned int v43; // er8
  UFG::CloseTarget *v44; // r14
  UFG::SimObject *v45; // rbx
  unsigned __int16 v46; // cx
  UFG::SimComponent *v47; // rdi
  unsigned int v48; // er10
  unsigned int v49; // edi
  signed __int64 v50; // r9
  unsigned int v51; // er10
  unsigned int v52; // edi
  UFG::SimComponent *v53; // rax
  unsigned __int16 v54; // r9
  UFG::PhysicsMoverInterface *v55; // rax
  unsigned int v56; // er10
  unsigned int v57; // er14
  signed __int64 v58; // r9
  unsigned __int16 v59; // cx
  unsigned int v60; // er9
  unsigned int v61; // er11
  signed __int64 v62; // r8
  UFG::VehicleOccupantComponent *v63; // rdi
  unsigned int v64; // er9
  unsigned int v65; // er11
  unsigned int v66; // er9
  unsigned int v67; // er11
  unsigned __int8 v68; // cl
  hkLocalFrameGroup *v69; // rbx
  unsigned __int16 v70; // cx
  unsigned int v71; // er9
  unsigned int v72; // er11
  signed __int64 v73; // r8
  hkSimpleLocalFrame *v74; // rax
  unsigned int v75; // er9
  unsigned int v76; // er11
  unsigned int v77; // er9
  unsigned int v78; // er11
  UFG::FaceActionComponent *v79; // rax
  unsigned __int16 v80; // cx
  unsigned int v81; // er8
  unsigned int v82; // er10
  signed __int64 v83; // rdx
  unsigned int v84; // er8
  unsigned int v85; // er10
  unsigned int v86; // er8
  unsigned int v87; // er10
  unsigned __int8 v88; // cl
  signed __int64 v89; // rbx
  UFG::TargetingSimObject *v90; // rax
  UFG::qMatrix44 result; // [rsp+50h] [rbp-B0h]
  UFG::qVector4 planes; // [rsp+90h] [rbp-70h]
  float v93; // [rsp+A0h] [rbp-60h]
  float v94; // [rsp+A4h] [rbp-5Ch]
  float v95; // [rsp+A8h] [rbp-58h]
  float v96; // [rsp+ACh] [rbp-54h]
  float v97; // [rsp+B0h] [rbp-50h]
  float v98; // [rsp+B4h] [rbp-4Ch]
  float v99; // [rsp+B8h] [rbp-48h]
  float v100; // [rsp+BCh] [rbp-44h]
  int v101; // [rsp+C0h] [rbp-40h]
  float v102; // [rsp+C4h] [rbp-3Ch]
  float v103; // [rsp+C8h] [rbp-38h]
  float v104; // [rsp+CCh] [rbp-34h]
  float v105; // [rsp+D0h] [rbp-30h]
  float v106; // [rsp+D4h] [rbp-2Ch]
  float v107; // [rsp+D8h] [rbp-28h]
  int v108; // [rsp+DCh] [rbp-24h]
  float v109; // [rsp+E0h] [rbp-20h]
  float v110; // [rsp+E4h] [rbp-1Ch]
  float v111; // [rsp+E8h] [rbp-18h]
  float v112; // [rsp+ECh] [rbp-14h]
  float v113; // [rsp+1E0h] [rbp+E0h]
  UFG::CloseTarget *v114; // [rsp+1E0h] [rbp+E0h]
  UFG::qFixedArray<UFG::CloseTarget *,20> *v115; // [rsp+1E8h] [rbp+E8h]

  v115 = closeVehiclesList;
  v2 = closeVehiclesList;
  v3 = this;
  if ( *(_WORD *)&this->m_TransitTargetingDisabledByMiniGame
    || (v4 = UFG::CopSystem::Instance(),
        ((signed int (__fastcall *)(UFG::CopSystem *))v4->vfptr[89].__vecDelDtor)(v4) > 0) )
  {
    if ( v3->m_pDriverFaceActionComponent->m_Flags & 1 )
      UFG::TargetingSystemPedPlayerComponent::deattachTransitDriverFaceComponent(v3);
    v88 = v3->m_pTargetingMap->m_Map.p[57];
    if ( v88 )
    {
      v89 = v88;
      UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v89], 0i64);
      v90 = v3->m_pTargets;
      if ( v90[v89].m_bLock )
        v90[v89].m_bLock = 0;
    }
    return;
  }
  v5 = (signed __int64)&v3->m_pTargets[(unsigned __int8)v3->m_pTargetingMap->m_Map.p[57]];
  if ( *(_QWORD *)(v5 + 40) && *(_BYTE *)(v5 + 49) )
    return;
  UFG::TargetingSystemBaseComponent::ClearTarget((UFG::TargetingSystemBaseComponent *)&v3->vfptr, eTARGET_TYPE_TRANSIT);
  v6 = UFG::GameStatTracker::Instance();
  if ( (signed int)UFG::GameStatTracker::GetStat(v6, Money) < 310 )
  {
    if ( v3->m_pDriverFaceActionComponent->m_Flags & 1 )
      UFG::TargetingSystemPedPlayerComponent::deattachTransitDriverFaceComponent(v3);
    return;
  }
  v7 = 0i64;
  v8 = 0i64;
  v9 = UFG::Director::Get()->mCurrentCamera;
  v10 = &v9->mCamera;
  if ( !v9 )
    v10 = 0i64;
  v11 = UFG::Camera::GetViewProjection(v10);
  v12 = UFG::Camera::GetWorldView(v10);
  UFG::qMatrix44::operator*(v12, &result, v11);
  LODWORD(v13) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
  LODWORD(v14) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
  LODWORD(v15) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
  LODWORD(v16) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
  LODWORD(v113) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v17) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
  LODWORD(v18) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
  LODWORD(v19) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
  LODWORD(v20) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
  LODWORD(v21) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
  LODWORD(v22) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
  v23 = fsqrt(
          (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
        + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
  planes.w = (float)(1.0 / v23) * COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]);
  planes.x = (float)(1.0 / v23) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
  planes.z = (float)(1.0 / v23) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
  planes.y = (float)(1.0 / v23) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]);
  v24 = fsqrt((float)((float)(v15 * v15) + (float)(v13 * v13)) + (float)(v16 * v16));
  LODWORD(v25) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  LODWORD(v26) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  v93 = (float)(1.0 / v24) * v13;
  v94 = (float)(1.0 / v24) * v15;
  v96 = (float)(1.0 / v24) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0]);
  v95 = (float)(1.0 / v24) * v16;
  v27 = fsqrt((float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(v19 * v19));
  v100 = (float)(1.0 / v27) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0]);
  v97 = (float)(1.0 / v27) * v17;
  v99 = (float)(1.0 / v27) * v19;
  v98 = (float)(1.0 / v27) * v18;
  v28 = (__m128)LODWORD(v113);
  v28.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v25 * v25)) + (float)(v26 * v26);
  LODWORD(v29) = (unsigned __int128)_mm_sqrt_ps(v28);
  v30 = 1.0 / v29;
  v31 = 1.0 / v29;
  v28.m128_f32[0] = (float)(1.0 / v29) * v25;
  v32 = (float)(1.0 / v29) * v26;
  LODWORD(v33) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
  v101 = v28.m128_i32[0];
  v103 = v32;
  v102 = v31 * v113;
  v34 = (__m128)LODWORD(v14);
  v104 = v30 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0]);
  v34.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v33 * v33)) + (float)(v20 * v20);
  LODWORD(v35) = (unsigned __int128)_mm_sqrt_ps(v34);
  v36 = v20 * (float)(1.0 / v35);
  v34.m128_f32[0] = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0]) * (float)(1.0 / v35);
  v37 = 1.0 / v35;
  v107 = v36;
  v108 = v34.m128_i32[0];
  v105 = v37 * v33;
  v106 = v37 * v14;
  LODWORD(v38) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
  v39 = UFG::VehicleOccupantComponent::_TypeUID;
  v40 = 0;
  v41 = (__m128)LODWORD(v22);
  v41.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v21 * v21)) + (float)(v38 * v38);
  v42 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v41));
  v109 = v42 * v21;
  v111 = v42 * v38;
  v112 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]) * v42;
  v110 = v42 * v22;
  if ( v2->size > 0 )
  {
    v43 = UFG::AiDriverComponent::_TypeUID;
    while ( 1 )
    {
      v44 = v2->p[v40];
      v114 = v44;
      v45 = v44->m_pSimObjectPropertiesComponent->m_pSimObject;
      if ( v45 )
        break;
LABEL_89:
      v2 = v115;
      if ( ++v40 >= v115->size )
        goto LABEL_92;
    }
    v46 = v45->m_Flags;
    if ( (v46 >> 14) & 1 )
    {
      v47 = v45->m_Components.p[23].m_pComponent;
      if ( !v47 || (v43 ^ v47->m_TypeUID) & 0xFE000000 || v43 & ~v47->m_TypeUID & 0x1FFFFFF )
        goto LABEL_17;
LABEL_39:
      v54 = v45->m_Flags;
      if ( (v54 >> 14) & 1 )
      {
        v55 = 0i64;
      }
      else if ( (v54 & 0x8000u) == 0 )
      {
        if ( (v54 >> 13) & 1 )
        {
          v55 = 0i64;
        }
        else if ( (v54 >> 12) & 1 )
        {
          v56 = (unsigned int)v45[1].vfptr;
          v57 = v45->m_Components.size;
          if ( v56 >= v57 )
          {
LABEL_51:
            v44 = v114;
            v55 = 0i64;
          }
          else
          {
            v58 = (signed __int64)&v45->m_Components.p[v56];
            while ( (*(_DWORD *)(v58 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
                 || UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v58 + 8) & 0x1FFFFFF )
            {
              ++v56;
              v58 += 16i64;
              if ( v56 >= v57 )
                goto LABEL_51;
            }
            v55 = *(UFG::PhysicsMoverInterface **)v58;
            v44 = v114;
          }
        }
        else
        {
          v55 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                v45,
                                                UFG::PhysicsMoverInterface::_TypeUID);
          v43 = UFG::AiDriverComponent::_TypeUID;
          v39 = UFG::VehicleOccupantComponent::_TypeUID;
        }
      }
      else
      {
        v55 = (UFG::PhysicsMoverInterface *)v45->m_Components.p[34].m_pComponent;
      }
      if ( !v47 || !v55 )
        goto LABEL_89;
      if ( UFG::PhysicsMoverInterface::GetEngineDamage(v55) >= 0.5 )
        goto LABEL_87;
      v59 = v45->m_Flags;
      if ( (v59 >> 14) & 1 )
      {
        v60 = (unsigned int)v45[1].vfptr;
        v61 = v45->m_Components.size;
        v39 = UFG::VehicleOccupantComponent::_TypeUID;
        if ( v60 < v61 )
        {
          v62 = (signed __int64)&v45->m_Components.p[v60];
          while ( (*(_DWORD *)(v62 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
               || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v62 + 8) & 0x1FFFFFF )
          {
            ++v60;
            v62 += 16i64;
            if ( v60 >= v61 )
              goto LABEL_63;
          }
LABEL_64:
          v63 = *(UFG::VehicleOccupantComponent **)v62;
          goto LABEL_83;
        }
        goto LABEL_63;
      }
      if ( (v59 & 0x8000u) == 0 )
      {
        v39 = UFG::VehicleOccupantComponent::_TypeUID;
        if ( (v59 >> 13) & 1 )
        {
          v64 = (unsigned int)v45[1].vfptr;
          v65 = v45->m_Components.size;
          if ( v64 < v65 )
          {
            v62 = (signed __int64)&v45->m_Components.p[v64];
            while ( (*(_DWORD *)(v62 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                 || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v62 + 8) & 0x1FFFFFF )
            {
              ++v64;
              v62 += 16i64;
              if ( v64 >= v65 )
              {
                v63 = 0i64;
                goto LABEL_83;
              }
            }
            goto LABEL_64;
          }
LABEL_63:
          v63 = 0i64;
LABEL_83:
          if ( !v63 )
          {
LABEL_88:
            v43 = UFG::AiDriverComponent::_TypeUID;
            goto LABEL_89;
          }
          if ( UFG::SimObjectUtility::IsClassType(v45, (UFG::qSymbol *)&qSymbol_Taxi.mUID) == 1
            && !UFG::VehicleOccupantComponent::HasPassengers(v63)
            && (signed int)InFrustum(&planes, (UFG::qVector3 *)&v44->m_Xform.v3) > 0 )
          {
            v39 = UFG::VehicleOccupantComponent::_TypeUID;
            v8 = v45;
            goto LABEL_92;
          }
LABEL_87:
          v39 = UFG::VehicleOccupantComponent::_TypeUID;
          goto LABEL_88;
        }
        if ( (v59 >> 12) & 1 )
        {
          v66 = (unsigned int)v45[1].vfptr;
          v67 = v45->m_Components.size;
          if ( v66 < v67 )
          {
            v62 = (signed __int64)&v45->m_Components.p[v66];
            while ( (*(_DWORD *)(v62 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                 || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v62 + 8) & 0x1FFFFFF )
            {
              ++v66;
              v62 += 16i64;
              if ( v66 >= v67 )
              {
                v63 = 0i64;
                goto LABEL_83;
              }
            }
            goto LABEL_64;
          }
          goto LABEL_63;
        }
        v63 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                 v45,
                                                 UFG::VehicleOccupantComponent::_TypeUID);
      }
      else
      {
        v63 = (UFG::VehicleOccupantComponent *)v45->m_Components.p[30].m_pComponent;
      }
      v39 = UFG::VehicleOccupantComponent::_TypeUID;
      goto LABEL_83;
    }
    if ( (v46 & 0x8000u) != 0 )
    {
      v47 = v45->m_Components.p[23].m_pComponent;
      if ( !v47 || (v43 ^ v47->m_TypeUID) & 0xFE000000 )
        goto LABEL_17;
      if ( v43 & ~v47->m_TypeUID & 0x1FFFFFF )
        v47 = 0i64;
      goto LABEL_39;
    }
    if ( (v46 >> 13) & 1 )
    {
      v48 = (unsigned int)v45[1].vfptr;
      v49 = v45->m_Components.size;
      if ( v48 < v49 )
      {
        v50 = (signed __int64)&v45->m_Components.p[v48];
        while ( (*(_DWORD *)(v50 + 8) & 0xFE000000) != (v43 & 0xFE000000) || v43 & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF )
        {
          ++v48;
          v50 += 16i64;
          if ( v48 >= v49 )
          {
            v47 = 0i64;
            goto LABEL_39;
          }
        }
LABEL_30:
        v47 = *(UFG::SimComponent **)v50;
        goto LABEL_39;
      }
    }
    else
    {
      if ( !((v46 >> 12) & 1) )
      {
        v53 = UFG::SimObject::GetComponentOfType(v45, v43);
        v43 = UFG::AiDriverComponent::_TypeUID;
        v39 = UFG::VehicleOccupantComponent::_TypeUID;
        v47 = v53;
        goto LABEL_39;
      }
      v51 = (unsigned int)v45[1].vfptr;
      v52 = v45->m_Components.size;
      if ( v51 < v52 )
      {
        v50 = (signed __int64)&v45->m_Components.p[v51];
        while ( (*(_DWORD *)(v50 + 8) & 0xFE000000) != (v43 & 0xFE000000) || v43 & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF )
        {
          ++v51;
          v50 += 16i64;
          if ( v51 >= v52 )
          {
            v47 = 0i64;
            goto LABEL_39;
          }
        }
        goto LABEL_30;
      }
    }
LABEL_17:
    v47 = 0i64;
    goto LABEL_39;
  }
LABEL_92:
  v68 = v3->m_pTargetingMap->m_Map.p[57];
  if ( v68 )
  {
    UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v68], v8);
    v39 = UFG::VehicleOccupantComponent::_TypeUID;
  }
  v69 = 0i64;
  if ( v8 )
  {
    v70 = v8->m_Flags;
    if ( (v70 >> 14) & 1 )
    {
      v71 = (unsigned int)v8[1].vfptr;
      v72 = v8->m_Components.size;
      if ( v71 < v72 )
      {
        v73 = (signed __int64)&v8->m_Components.p[v71];
        while ( (*(_DWORD *)(v73 + 8) & 0xFE000000) != (v39 & 0xFE000000) || v39 & ~*(_DWORD *)(v73 + 8) & 0x1FFFFFF )
        {
          ++v71;
          v73 += 16i64;
          if ( v71 >= v72 )
            goto LABEL_101;
        }
LABEL_102:
        v74 = *(hkSimpleLocalFrame **)v73;
        goto LABEL_120;
      }
      goto LABEL_101;
    }
    if ( (v70 & 0x8000u) == 0 )
    {
      if ( (v70 >> 13) & 1 )
      {
        v75 = (unsigned int)v8[1].vfptr;
        v76 = v8->m_Components.size;
        if ( v75 < v76 )
        {
          v73 = (signed __int64)&v8->m_Components.p[v75];
          while ( (*(_DWORD *)(v73 + 8) & 0xFE000000) != (v39 & 0xFE000000) || v39 & ~*(_DWORD *)(v73 + 8) & 0x1FFFFFF )
          {
            ++v75;
            v73 += 16i64;
            if ( v75 >= v76 )
            {
              v74 = 0i64;
              goto LABEL_120;
            }
          }
          goto LABEL_102;
        }
LABEL_101:
        v74 = 0i64;
        goto LABEL_120;
      }
      if ( (v70 >> 12) & 1 )
      {
        v77 = (unsigned int)v8[1].vfptr;
        v78 = v8->m_Components.size;
        if ( v77 < v78 )
        {
          v73 = (signed __int64)&v8->m_Components.p[v77];
          while ( (*(_DWORD *)(v73 + 8) & 0xFE000000) != (v39 & 0xFE000000) || v39 & ~*(_DWORD *)(v73 + 8) & 0x1FFFFFF )
          {
            ++v77;
            v73 += 16i64;
            if ( v77 >= v78 )
            {
              v74 = 0i64;
              goto LABEL_120;
            }
          }
          goto LABEL_102;
        }
        goto LABEL_101;
      }
      v74 = (hkSimpleLocalFrame *)UFG::SimObject::GetComponentOfType(v8, v39);
    }
    else
    {
      v74 = (hkSimpleLocalFrame *)v8->m_Components.p[30].m_pComponent;
    }
LABEL_120:
    if ( v74 )
      v69 = Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v74);
  }
  v79 = v3->m_pDriverFaceActionComponent;
  if ( (hkLocalFrameGroup *)v79->m_pSimObject != v69 )
  {
    if ( v79->m_Flags & 1 )
      UFG::TargetingSystemPedPlayerComponent::deattachTransitDriverFaceComponent(v3);
    if ( v69 )
    {
      v80 = WORD2(v69[3].vfptr);
      if ( (v80 >> 14) & 1 )
      {
        v7 = *(UFG::SimComponent **)(*(_QWORD *)&v69[4].m_memSizeAndFlags + 720i64);
        goto LABEL_151;
      }
      if ( (v80 & 0x8000u) == 0 )
      {
        if ( (v80 >> 13) & 1 )
        {
          v84 = *(_DWORD *)&v69[5].m_memSizeAndFlags;
          v85 = (unsigned int)v69[4].vfptr;
          if ( v84 >= v85 )
            goto LABEL_151;
          v83 = *(_QWORD *)&v69[4].m_memSizeAndFlags + 16i64 * v84;
          while ( (*(_DWORD *)(v83 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
               || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v83 + 8) & 0x1FFFFFF )
          {
            ++v84;
            v83 += 16i64;
            if ( v84 >= v85 )
              goto LABEL_151;
          }
        }
        else
        {
          if ( !((v80 >> 12) & 1) )
          {
            v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v69, UFG::FaceActionComponent::_TypeUID);
            goto LABEL_151;
          }
          v86 = *(_DWORD *)&v69[5].m_memSizeAndFlags;
          v87 = (unsigned int)v69[4].vfptr;
          if ( v86 >= v87 )
          {
LABEL_151:
            if ( !v7 && !(v3->m_pDriverFaceActionComponent->m_Flags & 1) )
              UFG::TargetingSystemPedPlayerComponent::attachTransitDriverFaceComponent(v3, (UFG::SimObject *)v69);
            return;
          }
          v83 = *(_QWORD *)&v69[4].m_memSizeAndFlags + 16i64 * v86;
          while ( (*(_DWORD *)(v83 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
               || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v83 + 8) & 0x1FFFFFF )
          {
            ++v86;
            v83 += 16i64;
            if ( v86 >= v87 )
              goto LABEL_151;
          }
        }
      }
      else
      {
        v81 = *(_DWORD *)&v69[5].m_memSizeAndFlags;
        v82 = (unsigned int)v69[4].vfptr;
        if ( v81 >= v82 )
          goto LABEL_151;
        v83 = *(_QWORD *)&v69[4].m_memSizeAndFlags + 16i64 * v81;
        while ( (*(_DWORD *)(v83 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
             || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v83 + 8) & 0x1FFFFFF )
        {
          ++v81;
          v83 += 16i64;
          if ( v81 >= v82 )
            goto LABEL_151;
        }
      }
      v7 = *(UFG::SimComponent **)v83;
      goto LABEL_151;
    }
  }
}

// File Line: 3152
// RVA: 0x566F00
void __fastcall UFG::TargetingSystemPedPlayerComponent::deattachTransitDriverFaceComponent(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingSystemPedPlayerComponent *v1; // rbp
  UFG::SimObject *v2; // rdi
  unsigned __int16 v3; // dx
  int v4; // esi
  UFG::SimComponent *v5; // rbx
  unsigned int v6; // ecx
  unsigned int v7; // er8
  UFG::SimComponentHolder *v8; // r11
  signed __int64 v9; // rbx
  unsigned int v10; // ecx
  unsigned int v11; // er8
  unsigned int v12; // ecx
  unsigned int v13; // er8
  __int64 v14; // rax
  UFG::FaceActionComponent *v15; // rdx
  UFG::SimObjectModifier v16; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = this->m_pDriverFaceActionComponent->m_pSimObject;
  if ( !v2 )
    goto LABEL_35;
  v3 = v2->m_Flags;
  v4 = 0;
  if ( (v3 >> 14) & 1 )
  {
    v5 = v2->m_Components.p[39].m_pComponent;
    goto LABEL_28;
  }
  if ( (v3 & 0x8000u) != 0 )
  {
    v6 = (unsigned int)v2[1].vfptr;
    v7 = v2->m_Components.size;
    if ( v6 < v7 )
    {
      v8 = v2->m_Components.p;
      while ( 1 )
      {
        v9 = v6;
        if ( (v8[v6].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
          && !(UFG::InventoryComponent::_TypeUID & ~v8[v6].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v6 >= v7 )
          goto LABEL_12;
      }
LABEL_11:
      v5 = v8[v9].m_pComponent;
      goto LABEL_28;
    }
    goto LABEL_12;
  }
  if ( (v3 >> 13) & 1 )
  {
    v10 = (unsigned int)v2[1].vfptr;
    v11 = v2->m_Components.size;
    if ( v10 < v11 )
    {
      v8 = v2->m_Components.p;
      while ( 1 )
      {
        v9 = v10;
        if ( (v8[v10].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
          && !(UFG::InventoryComponent::_TypeUID & ~v8[v10].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_11;
        }
        if ( ++v10 >= v11 )
          goto LABEL_12;
      }
    }
    goto LABEL_12;
  }
  if ( (v3 >> 12) & 1 )
  {
    v12 = (unsigned int)v2[1].vfptr;
    v13 = v2->m_Components.size;
    if ( v12 < v13 )
    {
      v8 = v2->m_Components.p;
      do
      {
        v9 = v12;
        if ( (v8[v12].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
          && !(UFG::InventoryComponent::_TypeUID & ~v8[v12].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_11;
        }
      }
      while ( ++v12 < v13 );
    }
LABEL_12:
    v5 = 0i64;
    goto LABEL_28;
  }
  v5 = UFG::SimObject::GetComponentOfType(v2, UFG::InventoryComponent::_TypeUID);
LABEL_28:
  if ( v5 )
  {
    v14 = v1->m_eDriverSellableItemType;
    *(&v5[1].m_NameUID + v14) = 0;
    if ( (UFG::SimObjectCharacter *)v5->m_pSimObject == LocalPlayer )
    {
      if ( LOBYTE(v5[14].m_pSimObject) && (_DWORD)v14 == *(_DWORD *)&v5[14].m_Flags )
        v4 = 1;
      UFG::GameStatAction::Inventory::UpdateItem((UFG::eInventoryItemEnum)v14, v4);
    }
    *(_DWORD *)&v5[14].m_Flags = v1->m_eDriverOriginalSellableItemType;
  }
LABEL_35:
  UFG::SimObjectModifier::SimObjectModifier(&v16, v2, 1);
  v15 = v1->m_pDriverFaceActionComponent;
  ArrayOfTuplesImplementation::clear((ArrayOfTuplesImplementation *)&v16);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
}

// File Line: 3171
// RVA: 0x564280
void __fastcall UFG::TargetingSystemPedPlayerComponent::attachTransitDriverFaceComponent(UFG::TargetingSystemPedPlayerComponent *this, UFG::SimObject *driver)
{
  UFG::SimObject *v2; // rdi
  UFG::TargetingSystemPedPlayerComponent *v3; // rbp
  UFG::SimObject *v4; // r8
  UFG::SimComponent *v5; // rbx
  unsigned __int16 v6; // r9
  UFG::SimComponent *v7; // rax
  unsigned int v8; // ecx
  unsigned int v9; // er9
  UFG::SimComponentHolder *v10; // rsi
  signed __int64 v11; // r8
  unsigned int v12; // ecx
  unsigned int v13; // er9
  unsigned int v14; // ecx
  unsigned int v15; // er9
  unsigned __int16 v16; // cx
  unsigned int v17; // ecx
  unsigned int v18; // er9
  UFG::SimComponentHolder *v19; // rsi
  signed __int64 v20; // r8
  unsigned int v21; // ecx
  unsigned int v22; // er9
  unsigned int v23; // ecx
  unsigned int v24; // er9
  UFG::eInventoryItemEnum v25; // ecx
  UFG::eInventoryItemEnum v26; // eax
  __int64 v27; // rcx
  unsigned __int16 v28; // cx
  unsigned int v29; // edx
  unsigned int v30; // er8
  UFG::SimComponentHolder *v31; // r11
  unsigned int v32; // edx
  unsigned int v33; // er8
  UFG::SimComponentHolder *v34; // r11
  unsigned int v35; // edx
  unsigned int v36; // er8
  UFG::SimComponentHolder *v37; // r11
  UFG::FaceActionComponent *v38; // rcx
  unsigned int v39; // ebx
  UFG::FaceActionComponent *v40; // rbx
  UFG::SimObjectModifier v41; // [rsp+28h] [rbp-30h]

  v2 = driver;
  v3 = this;
  v4 = this->m_pSimObject;
  v5 = 0i64;
  if ( !v4 )
    goto LABEL_29;
  v6 = v4->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = v4->m_Components.p[44].m_pComponent;
    goto LABEL_28;
  }
  if ( (v6 & 0x8000u) != 0 )
  {
    v8 = (unsigned int)v4[1].vfptr;
    v9 = v4->m_Components.size;
    if ( v8 < v9 )
    {
      v10 = v4->m_Components.p;
      while ( 1 )
      {
        v11 = v8;
        if ( (v10[v8].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && !(UFG::CharacterOccupantComponent::_TypeUID & ~v10[v8].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v8 >= v9 )
          goto LABEL_12;
      }
LABEL_11:
      v7 = v10[v11].m_pComponent;
      goto LABEL_28;
    }
    goto LABEL_12;
  }
  if ( (v6 >> 13) & 1 )
  {
    v12 = (unsigned int)v4[1].vfptr;
    v13 = v4->m_Components.size;
    if ( v12 < v13 )
    {
      v10 = v4->m_Components.p;
      while ( 1 )
      {
        v11 = v12;
        if ( (v10[v12].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && !(UFG::CharacterOccupantComponent::_TypeUID & ~v10[v12].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_11;
        }
        if ( ++v12 >= v13 )
          goto LABEL_12;
      }
    }
    goto LABEL_12;
  }
  if ( (v6 >> 12) & 1 )
  {
    v14 = (unsigned int)v4[1].vfptr;
    v15 = v4->m_Components.size;
    if ( v14 < v15 )
    {
      v10 = v4->m_Components.p;
      do
      {
        v11 = v14;
        if ( (v10[v14].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
          && !(UFG::CharacterOccupantComponent::_TypeUID & ~v10[v14].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_11;
        }
      }
      while ( ++v14 < v15 );
    }
LABEL_12:
    v7 = 0i64;
    goto LABEL_28;
  }
  v7 = UFG::SimObject::GetComponentOfType(this->m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
LABEL_28:
  if ( v7 )
    return;
LABEL_29:
  if ( !v2 )
    return;
  v16 = v2->m_Flags;
  if ( (v16 >> 14) & 1 )
  {
    v5 = v2->m_Components.p[39].m_pComponent;
    goto LABEL_55;
  }
  if ( (v16 & 0x8000u) != 0 )
  {
    v17 = (unsigned int)v2[1].vfptr;
    v18 = v2->m_Components.size;
    if ( v17 >= v18 )
      goto LABEL_55;
    v19 = v2->m_Components.p;
    while ( 1 )
    {
      v20 = v17;
      if ( (v19[v17].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
        && !(UFG::InventoryComponent::_TypeUID & ~v19[v17].m_TypeUID & 0x1FFFFFF) )
      {
        goto LABEL_39;
      }
      if ( ++v17 >= v18 )
        goto LABEL_55;
    }
  }
  if ( (v16 >> 13) & 1 )
  {
    v21 = (unsigned int)v2[1].vfptr;
    v22 = v2->m_Components.size;
    if ( v21 < v22 )
    {
      v19 = v2->m_Components.p;
      while ( 1 )
      {
        v20 = v21;
        if ( (v19[v21].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
          && !(UFG::InventoryComponent::_TypeUID & ~v19[v21].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v21 >= v22 )
          goto LABEL_55;
      }
LABEL_39:
      v5 = v19[v20].m_pComponent;
      goto LABEL_55;
    }
  }
  else if ( (v16 >> 12) & 1 )
  {
    v23 = (unsigned int)v2[1].vfptr;
    v24 = v2->m_Components.size;
    if ( v23 < v24 )
    {
      v19 = v2->m_Components.p;
      do
      {
        v20 = v23;
        if ( (v19[v23].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
          && !(UFG::InventoryComponent::_TypeUID & ~v19[v23].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_39;
        }
      }
      while ( ++v23 < v24 );
    }
  }
  else
  {
    v5 = UFG::SimObject::GetComponentOfType(v2, UFG::InventoryComponent::_TypeUID);
  }
LABEL_55:
  if ( v5 )
  {
    v25 = *(_DWORD *)&v5[14].m_Flags;
    v26 = v3->m_eDriverSellableItemType;
    if ( v25 != v26 )
    {
      v3->m_eDriverOriginalSellableItemType = v25;
      *(_DWORD *)&v5[14].m_Flags = v26;
    }
    v27 = v3->m_eDriverSellableItemType;
    if ( (!LOBYTE(v5[14].m_pSimObject) || (_DWORD)v27 != *(_DWORD *)&v5[14].m_Flags)
      && (signed int)*(&v5[1].m_NameUID + v27) <= 0 )
    {
      *(&v5[1].m_NameUID + v27) = 1;
      if ( (UFG::SimObjectCharacter *)v5->m_pSimObject == LocalPlayer )
        UFG::GameStatAction::Inventory::UpdateItem((UFG::eInventoryItemEnum)v27, 1);
    }
    v28 = v2->m_Flags;
    if ( !((v28 >> 14) & 1) )
    {
      if ( (v28 & 0x8000u) == 0 )
      {
        if ( (v28 >> 13) & 1 )
        {
          v32 = (unsigned int)v2[1].vfptr;
          v33 = v2->m_Components.size;
          if ( v32 < v33 )
          {
            v34 = v2->m_Components.p;
            do
            {
              if ( (v34[v32].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                && !(UFG::FaceActionComponent::_TypeUID & ~v34[v32].m_TypeUID & 0x1FFFFFF) )
              {
                break;
              }
              ++v32;
            }
            while ( v32 < v33 );
          }
        }
        else if ( (v28 >> 12) & 1 )
        {
          v35 = (unsigned int)v2[1].vfptr;
          v36 = v2->m_Components.size;
          if ( v35 < v36 )
          {
            v37 = v2->m_Components.p;
            do
            {
              if ( (v37[v35].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                && !(UFG::FaceActionComponent::_TypeUID & ~v37[v35].m_TypeUID & 0x1FFFFFF) )
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
          UFG::SimObject::GetComponentOfType(v2, UFG::FaceActionComponent::_TypeUID);
        }
      }
      else
      {
        v29 = (unsigned int)v2[1].vfptr;
        v30 = v2->m_Components.size;
        if ( v29 < v30 )
        {
          v31 = v2->m_Components.p;
          do
          {
            if ( (v31[v29].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
              && !(UFG::FaceActionComponent::_TypeUID & ~v31[v29].m_TypeUID & 0x1FFFFFF) )
            {
              break;
            }
            ++v29;
          }
          while ( v29 < v30 );
        }
      }
    }
    v38 = v3->m_pDriverFaceActionComponent;
    if ( !(v38->m_Flags & 1) )
    {
      UFG::FaceActionComponent::ResetState(v38);
      if ( (v2->m_Flags >> 14) & 1 )
        v39 = 45;
      else
        v39 = -1;
      UFG::SimObjectModifier::SimObjectModifier(&v41, v2, 1);
      UFG::SimObjectModifier::AttachComponent(&v41, (UFG::SimComponent *)&v3->m_pDriverFaceActionComponent->vfptr, v39);
      UFG::SimObjectModifier::Close(&v41);
      UFG::SimObjectModifier::~SimObjectModifier(&v41);
      v40 = v3->m_pDriverFaceActionComponent;
      if ( !v40->mFaceActionEnabled )
        UFG::FaceActionComponent::ProcessIconLogic(v3->m_pDriverFaceActionComponent);
      v40->mFaceActionEnabled = 1;
    }
  }
}

// File Line: 3221
// RVA: 0x57B360
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateVehicleClosestPointTarget(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingMap *v1; // rdx
  UFG::TargetingSimObject *v2; // r8
  UFG::TargetingSystemPedPlayerComponent *v3; // rdi
  UFG::SimObject *v4; // rcx
  unsigned __int8 v5; // al
  signed __int64 v6; // rbx
  UFG::TargetingSimObject *v7; // rax
  signed __int64 v8; // rax
  unsigned __int16 v9; // dx
  UFG::TransformNodeComponent *v10; // rsi
  UFG::PhysicsMoverInterface *v11; // rbx
  unsigned int v12; // er8
  unsigned int v13; // er10
  signed __int64 v14; // rdx
  float v15; // xmm2_4
  float v16; // xmm3_4
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
  float v27; // xmm1_4
  unsigned __int8 v28; // cl
  unsigned __int8 v29; // cl
  signed __int64 v30; // rbx
  UFG::TargetingSimObject *v31; // rax
  UFG::qVector3 pos; // [rsp+20h] [rbp-79h]
  UFG::qVector3 min; // [rsp+30h] [rbp-69h]
  UFG::qVector3 max; // [rsp+40h] [rbp-59h]
  UFG::qVector4 row_vec4; // [rsp+50h] [rbp-49h]
  UFG::qMatrix44 d; // [rsp+60h] [rbp-39h]
  UFG::qVector4 result; // [rsp+A0h] [rbp+7h]

  v1 = this->m_pTargetingMap;
  v2 = this->m_pTargets;
  v3 = this;
  v4 = v2[(unsigned __int8)v1->m_Map.p[28]].m_pTarget.m_pPointer;
  if ( !v4 )
  {
    v5 = v1->m_Map.p[46];
    if ( v5 )
    {
      v6 = v5;
      UFG::TargetingSimObject::SetTarget(&v2[v6], 0i64);
      v7 = v3->m_pTargets;
      if ( v7[v6].m_bLock )
        v7[v6].m_bLock = 0;
    }
    return;
  }
  v8 = (unsigned __int8)v1->m_Map.p[46];
  if ( v2[v8].m_pTarget.m_pPointer && v2[v8].m_bLock )
    return;
  if ( !v3->m_pVehicleClosestPointTNC.m_pPointer )
    goto LABEL_39;
  v9 = v4->m_Flags;
  v10 = v4->m_pTransformNodeComponent;
  if ( (v9 >> 14) & 1 )
    goto LABEL_44;
  if ( (v9 & 0x8000u) != 0 )
  {
    v11 = (UFG::PhysicsMoverInterface *)v4->m_Components.p[34].m_pComponent;
    goto LABEL_23;
  }
  if ( (v9 >> 13) & 1 )
  {
    v11 = 0i64;
    goto LABEL_23;
  }
  if ( !((v9 >> 12) & 1) )
  {
    v11 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(v4, UFG::PhysicsMoverInterface::_TypeUID);
    goto LABEL_23;
  }
  v12 = (unsigned int)v4[1].vfptr;
  v13 = v4->m_Components.size;
  if ( v12 >= v13 )
  {
LABEL_44:
    v11 = 0i64;
  }
  else
  {
    v14 = (signed __int64)&v4->m_Components.p[v12];
    while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
         || UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
    {
      ++v12;
      v14 += 16i64;
      if ( v12 >= v13 )
      {
        v11 = 0i64;
        goto LABEL_23;
      }
    }
    v11 = *(UFG::PhysicsMoverInterface **)v14;
  }
LABEL_23:
  if ( v10 && v11 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v10);
    UFG::qInverseAffine(&d, &v10->mWorldTransform);
    v15 = v3->m_vTargetingPosition.x;
    v16 = v3->m_vTargetingPosition.y;
    v17 = v3->m_vTargetingPosition.z + 0.69999999;
    v18 = (float)((float)((float)(d.v0.x * v15) + (float)(d.v1.x * v16)) + (float)(d.v2.x * v17)) + d.v3.x;
    v19 = (float)((float)((float)(d.v0.y * v15) + (float)(d.v1.y * v16)) + (float)(d.v2.y * v17)) + d.v3.y;
    v20 = (float)((float)((float)(d.v0.z * v15) + (float)(d.v1.z * v16)) + (float)(d.v2.z * v17)) + d.v3.z;
    UFG::PhysicsMoverInterface::GetBoundingBoxLocalSpace(v11, &min, &max);
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
    v24 = UFG::operator*(&result, &row_vec4, &v10->mWorldTransform);
    v25 = (UFG::TransformNodeComponent *)v3->m_pVehicleClosestPointTNC.m_pPointer;
    v26 = v24->x;
    pos.y = v24->y;
    v27 = v3->m_vTargetingPosition.z;
    pos.x = v26;
    pos.z = v27;
    UFG::TransformNodeComponent::SetWorldTranslation(v25, &pos);
    v28 = v3->m_pTargetingMap->m_Map.p[46];
    if ( v28 )
      UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v28], v3->m_pVehicleClosestPointSimObject.m_pPointer);
    return;
  }
LABEL_39:
  v29 = v3->m_pTargetingMap->m_Map.p[46];
  if ( v29 )
  {
    v30 = v29;
    UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v30], 0i64);
    v31 = v3->m_pTargets;
    if ( v31[v30].m_bLock )
      v31[v30].m_bLock = 0;
  }
}

// File Line: 3287
// RVA: 0x576DD0
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateRagdoll(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *v1; // rsi
  UFG::TargetingSystemPedPlayerComponent *v2; // r14
  __int64 v3; // rbp
  UFG::SimObject *v4; // rdi
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // r8
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  unsigned int v9; // edx
  unsigned int v10; // er9
  signed __int64 v11; // r8
  unsigned int v12; // edx
  unsigned int v13; // er9
  __int64 v14; // rax
  signed __int64 v15; // rdx
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rax
  unsigned int v18; // er8
  unsigned int v19; // er10
  unsigned int v20; // er9
  signed __int64 v21; // rdx
  unsigned int v22; // er8
  unsigned int v23; // er10
  unsigned int v24; // er8
  unsigned int v25; // er10
  unsigned __int16 v26; // cx
  UFG::SimComponent *v27; // rax
  unsigned int v28; // er8
  unsigned int v29; // er10
  signed __int64 v30; // rdx
  unsigned int v31; // er8
  unsigned int v32; // er10
  unsigned int v33; // er8
  unsigned int v34; // er10
  UFG::RagdollComponent *v35; // rcx
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *v36; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::RagdollComponent *v39; // rcx
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *v40; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v42; // rax
  unsigned __int16 v43; // cx
  UFG::SimComponent *v44; // rax
  unsigned int v45; // er8
  unsigned int v46; // er10
  unsigned int v47; // er9
  signed __int64 v48; // rdx
  UFG::RagdollComponent *v49; // rax
  unsigned __int16 v50; // cx
  unsigned int v51; // er8
  unsigned int v52; // er10
  signed __int64 v53; // rdx
  UFG::RagdollComponent *v54; // rax

  v1 = 0i64;
  v2 = this;
  v3 = 0i64;
  v4 = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( !v4 )
  {
LABEL_87:
    v35 = v2->m_RagdollTarget.m_pPointer;
    if ( v35 )
    {
      UFG::RagdollComponent::Release(v35, 0);
      v36 = &v2->m_RagdollTarget;
      if ( v2->m_RagdollTarget.m_pPointer )
      {
        v37 = v36->mPrev;
        v38 = v2->m_RagdollTarget.mNext;
        v37->mNext = v38;
        v38->mPrev = v37;
        v36->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
        v2->m_RagdollTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v2->m_RagdollTarget.mPrev;
      }
      v2->m_RagdollTarget.m_pPointer = 0i64;
    }
    goto LABEL_91;
  }
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p[20].m_pComponent;
    if ( !v6 )
      goto LABEL_6;
    v7 = v6->m_TypeUID;
    if ( (v7 ^ UFG::TargetingSystemPedBaseComponent::_TypeUID) & 0xFE000000
      || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v7 & 0x1FFFFFF )
    {
      goto LABEL_6;
    }
  }
  else
  {
    if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v9 = (unsigned int)v4[1].vfptr;
        v10 = v4->m_Components.size;
        if ( v9 >= v10 )
        {
LABEL_6:
          v6 = 0i64;
          goto LABEL_28;
        }
        v11 = (signed __int64)&v4->m_Components.p[v9];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF )
        {
          ++v9;
          v11 += 16i64;
          if ( v9 >= v10 )
          {
            v6 = 0i64;
            goto LABEL_28;
          }
        }
      }
      else
      {
        if ( !((v5 >> 12) & 1) )
        {
          v6 = UFG::SimObject::GetComponentOfType(v4, UFG::TargetingSystemPedBaseComponent::_TypeUID);
          goto LABEL_28;
        }
        v12 = (unsigned int)v4[1].vfptr;
        v13 = v4->m_Components.size;
        if ( v12 >= v13 )
          goto LABEL_6;
        v11 = (signed __int64)&v4->m_Components.p[v12];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF )
        {
          ++v12;
          v11 += 16i64;
          if ( v12 >= v13 )
          {
            v6 = 0i64;
            goto LABEL_28;
          }
        }
      }
      v6 = *(UFG::SimComponent **)v11;
      goto LABEL_28;
    }
    v6 = v4->m_Components.p[20].m_pComponent;
    if ( !v6 )
      goto LABEL_6;
    v8 = v6->m_TypeUID;
    if ( (v8 ^ UFG::TargetingSystemPedBaseComponent::_TypeUID) & 0xFE000000 )
      goto LABEL_6;
    if ( UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v8 & 0x1FFFFFF )
      v6 = 0i64;
  }
LABEL_28:
  if ( v6 )
  {
    v14 = *(_QWORD *)&v6[1].m_TypeUID;
    v15 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + 31i64);
    if ( *(_QWORD *)(v15 + v14 + 40) )
    {
      if ( *(_BYTE *)(v15 + v14 + 49) )
        v3 = *(_QWORD *)(v15 + v14 + 40);
    }
  }
  v16 = v4->m_Flags;
  if ( !((v16 >> 14) & 1) )
  {
    if ( (v16 & 0x8000u) == 0 )
    {
      if ( (v16 >> 13) & 1 )
      {
        v22 = (unsigned int)v4[1].vfptr;
        v23 = v4->m_Components.size;
        v20 = UFG::RagdollComponent::_TypeUID;
        if ( v22 < v23 )
        {
          v21 = (signed __int64)&v4->m_Components.p[v22];
          while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
               || UFG::RagdollComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF )
          {
            ++v22;
            v21 += 16i64;
            if ( v22 >= v23 )
            {
              v17 = 0i64;
              goto LABEL_58;
            }
          }
          goto LABEL_41;
        }
      }
      else
      {
        if ( !((v16 >> 12) & 1) )
        {
          v17 = UFG::SimObject::GetComponentOfType(v4, UFG::RagdollComponent::_TypeUID);
          goto LABEL_57;
        }
        v24 = (unsigned int)v4[1].vfptr;
        v25 = v4->m_Components.size;
        v20 = UFG::RagdollComponent::_TypeUID;
        if ( v24 < v25 )
        {
          v21 = (signed __int64)&v4->m_Components.p[v24];
          while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
               || UFG::RagdollComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF )
          {
            ++v24;
            v21 += 16i64;
            if ( v24 >= v25 )
            {
              v17 = 0i64;
              goto LABEL_58;
            }
          }
          goto LABEL_41;
        }
      }
    }
    else
    {
      v18 = (unsigned int)v4[1].vfptr;
      v19 = v4->m_Components.size;
      v20 = UFG::RagdollComponent::_TypeUID;
      if ( v18 < v19 )
      {
        v21 = (signed __int64)&v4->m_Components.p[v18];
        while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
             || UFG::RagdollComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF )
        {
          ++v18;
          v21 += 16i64;
          if ( v18 >= v19 )
            goto LABEL_40;
        }
LABEL_41:
        v17 = *(UFG::SimComponent **)v21;
        goto LABEL_58;
      }
    }
LABEL_40:
    v17 = 0i64;
    goto LABEL_58;
  }
  v17 = v4->m_Components.p[42].m_pComponent;
LABEL_57:
  v20 = UFG::RagdollComponent::_TypeUID;
LABEL_58:
  if ( v17 != (UFG::SimComponent *)v2->m_RagdollTarget.m_pPointer )
    goto LABEL_87;
  if ( v3 )
  {
    v26 = *(_WORD *)(v3 + 76);
    if ( (v26 >> 14) & 1 )
    {
      v27 = *(UFG::SimComponent **)(*(_QWORD *)(v3 + 104) + 672i64);
      goto LABEL_85;
    }
    if ( (v26 & 0x8000u) == 0 )
    {
      if ( (v26 >> 13) & 1 )
      {
        v31 = *(_DWORD *)(v3 + 128);
        v32 = *(_DWORD *)(v3 + 96);
        if ( v31 < v32 )
        {
          v30 = *(_QWORD *)(v3 + 104) + 16i64 * v31;
          while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (v20 & 0xFE000000) || v20 & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF )
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
        if ( !((v26 >> 12) & 1) )
        {
          v27 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v3, v20);
LABEL_85:
          if ( v27 == (UFG::SimComponent *)v2->m_FocusTargetsGrappleTarget.m_pPointer )
            goto LABEL_95;
          goto LABEL_91;
        }
        v33 = *(_DWORD *)(v3 + 128);
        v34 = *(_DWORD *)(v3 + 96);
        if ( v33 < v34 )
        {
          v30 = *(_QWORD *)(v3 + 104) + 16i64 * v33;
          while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (v20 & 0xFE000000) || v20 & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF )
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
      v28 = *(_DWORD *)(v3 + 128);
      v29 = *(_DWORD *)(v3 + 96);
      if ( v28 < v29 )
      {
        v30 = *(_QWORD *)(v3 + 104) + 16i64 * v28;
        while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (v20 & 0xFE000000) || v20 & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF )
        {
          ++v28;
          v30 += 16i64;
          if ( v28 >= v29 )
            goto LABEL_68;
        }
LABEL_69:
        v27 = *(UFG::SimComponent **)v30;
        goto LABEL_85;
      }
    }
LABEL_68:
    v27 = 0i64;
    goto LABEL_85;
  }
LABEL_91:
  v39 = v2->m_FocusTargetsGrappleTarget.m_pPointer;
  if ( v39 )
  {
    UFG::RagdollComponent::Release(v39, 0);
    v40 = &v2->m_FocusTargetsGrappleTarget;
    if ( v2->m_FocusTargetsGrappleTarget.m_pPointer )
    {
      v41 = v40->mPrev;
      v42 = v2->m_FocusTargetsGrappleTarget.mNext;
      v41->mNext = v42;
      v42->mPrev = v41;
      v40->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v40->mPrev;
      v2->m_FocusTargetsGrappleTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v2->m_FocusTargetsGrappleTarget.mPrev;
    }
    v2->m_FocusTargetsGrappleTarget.m_pPointer = 0i64;
  }
LABEL_95:
  if ( !v2->m_bIsAimingActive )
    return;
  if ( v2->m_RagdollTarget.m_pPointer || !v4 )
    goto LABEL_117;
  v43 = v4->m_Flags;
  if ( (v43 >> 14) & 1 )
  {
    v44 = v4->m_Components.p[3].m_pComponent;
LABEL_113:
    v47 = UFG::SimObjectPropertiesComponent::_TypeUID;
    goto LABEL_114;
  }
  if ( (v43 & 0x8000u) != 0 )
  {
    v44 = v4->m_Components.p[3].m_pComponent;
    goto LABEL_113;
  }
  if ( (v43 >> 13) & 1 )
  {
    v44 = v4->m_Components.p[4].m_pComponent;
    goto LABEL_113;
  }
  if ( !((v43 >> 12) & 1) )
  {
    v44 = UFG::SimObject::GetComponentOfType(v4, UFG::SimObjectPropertiesComponent::_TypeUID);
    goto LABEL_113;
  }
  v45 = (unsigned int)v4[1].vfptr;
  v46 = v4->m_Components.size;
  v47 = UFG::SimObjectPropertiesComponent::_TypeUID;
  if ( v45 >= v46 )
  {
LABEL_110:
    v44 = 0i64;
  }
  else
  {
    v48 = (signed __int64)&v4->m_Components.p[v45];
    while ( (*(_DWORD *)(v48 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
         || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v48 + 8) & 0x1FFFFFF )
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
    v49 = (UFG::RagdollComponent *)UFG::RagdollComponent::Acquire(v4);
    UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent>::operator=(&v2->m_RagdollTarget, v49);
LABEL_117:
    v47 = UFG::SimObjectPropertiesComponent::_TypeUID;
  }
  if ( !v2->m_FocusTargetsGrappleTarget.m_pPointer && v3 && (UFG::SimObject *)v3 != v2->m_pSimObject )
  {
    v50 = *(_WORD *)(v3 + 76);
    if ( (v50 >> 14) & 1 )
    {
      v1 = *(UFG::SimComponent **)(*(_QWORD *)(v3 + 104) + 48i64);
    }
    else if ( (v50 & 0x8000u) == 0 )
    {
      if ( (v50 >> 13) & 1 )
      {
        v1 = *(UFG::SimComponent **)(*(_QWORD *)(v3 + 104) + 64i64);
      }
      else if ( (v50 >> 12) & 1 )
      {
        v51 = *(_DWORD *)(v3 + 128);
        v52 = *(_DWORD *)(v3 + 96);
        if ( v51 < v52 )
        {
          v53 = *(_QWORD *)(v3 + 104) + 16i64 * v51;
          while ( (*(_DWORD *)(v53 + 8) & 0xFE000000) != (v47 & 0xFE000000) || v47 & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF )
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
        v1 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v3, v47);
      }
    }
    else
    {
      v1 = *(UFG::SimComponent **)(*(_QWORD *)(v3 + 104) + 48i64);
    }
LABEL_136:
    if ( v1 )
    {
      if ( LODWORD(v1[1].m_SafePointerList.mNode.mNext) == 1 )
      {
        v54 = (UFG::RagdollComponent *)UFG::RagdollComponent::Acquire((UFG::SimObject *)v3);
        UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent>::operator=(&v2->m_FocusTargetsGrappleTarget, v54);
      }
    }
  }
}

// File Line: 3378
// RVA: 0x577EE0
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateRimLighting(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimObject *v1; // r9
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  if ( this->m_RimLighting.m_bEnabled )
  {
    v1 = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[this->m_RimLighting.m_TargetType]].m_pTarget.m_pPointer;
    if ( v1 != this->m_RimLighting.m_Target.m_pPointer )
    {
      v2 = &this->m_RimLighting.m_Target;
      if ( this->m_RimLighting.m_Target.m_pPointer )
      {
        v3 = v2->mPrev;
        v4 = v2->mNext;
        v3->mNext = v4;
        v4->mPrev = v3;
        v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
        v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
      }
      v2->m_pPointer = v1;
      if ( v1 )
      {
        v5 = v1->m_SafePointerList.mNode.mPrev;
        v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
        v2->mPrev = v5;
        v2->mNext = &v1->m_SafePointerList.mNode;
        v1->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
      }
    }
  }
}

// File Line: 3403
// RVA: 0x57B980
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateVehicleProjectileTargets(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingSystemPedPlayerComponent *v1; // rbp
  UFG::SimObject *v2; // rdi
  UFG::VehicleOccupantComponent *v3; // r14
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::RagdollComponent **v7; // rbx
  signed __int64 v8; // rsi
  __int64 v9; // rcx
  _QWORD *v10; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  unsigned int v15; // esi
  unsigned int v16; // edi
  char *v17; // rbx
  UFG::SimObject *v18; // rax
  UFG::SimComponent *v19; // rax
  __int64 v20; // rdx
  _QWORD *v21; // rcx
  _QWORD *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  unsigned int v24; // edi
  UFG::qSafePointer<UFG::RagdollComponent,UFG::RagdollComponent> *v25; // rbx
  UFG::RagdollComponent *v26; // rcx
  UFG::RagdollComponent *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v32; // rax
  char ptr; // [rsp+40h] [rbp-118h]
  char v34[224]; // [rsp+50h] [rbp-108h]

  v1 = this;
  v2 = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( !v2 )
    goto LABEL_47;
  if ( (v2->m_Flags & 0x8000u) == 0 )
    v2 = 0i64;
  if ( v2 )
  {
    v3 = (UFG::VehicleOccupantComponent *)v2->m_Components.p[30].m_pComponent;
    if ( v3 )
    {
      if ( v2 == this->m_pVehicleFocusTarget.m_pPointer )
        goto LABEL_19;
      goto LABEL_9;
    }
  }
  else
  {
LABEL_47:
    v3 = 0i64;
  }
  v2 = 0i64;
LABEL_9:
  if ( this->m_pVehicleFocusTarget.m_pPointer )
  {
    v4 = &this->m_pVehicleFocusTarget;
    if ( this->m_pVehicleFocusTarget.m_pPointer )
    {
      v5 = v4->mPrev;
      v6 = v4->mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    }
    v4->m_pPointer = 0i64;
  }
  v7 = &v1->m_VehicleCharacterRagdolls[0].m_pPointer;
  v8 = 10i64;
  do
  {
    if ( *v7 )
    {
      UFG::RagdollComponent::Release(*v7, 0);
      if ( *v7 )
      {
        v9 = (__int64)*(v7 - 2);
        v10 = *(v7 - 1);
        *(_QWORD *)(v9 + 8) = v10;
        *v10 = v9;
        *(v7 - 2) = (UFG::RagdollComponent *)(v7 - 2);
        *(v7 - 1) = (UFG::RagdollComponent *)(v7 - 2);
      }
      *v7 = 0i64;
    }
    v7 += 3;
    --v8;
  }
  while ( v8 );
LABEL_19:
  if ( v1->m_bIsAimingActive && v2 )
  {
    if ( !v1->m_pVehicleFocusTarget.m_pPointer )
    {
      v11 = &v1->m_pVehicleFocusTarget;
      if ( v1->m_pVehicleFocusTarget.m_pPointer )
      {
        v12 = v11->mPrev;
        v13 = v1->m_pVehicleFocusTarget.mNext;
        v12->mNext = v13;
        v13->mPrev = v12;
        v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
        v1->m_pVehicleFocusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pVehicleFocusTarget.mPrev;
      }
      v1->m_pVehicleFocusTarget.m_pPointer = v2;
      v14 = v2->m_SafePointerList.mNode.mPrev;
      v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
      v11->mPrev = v14;
      v1->m_pVehicleFocusTarget.mNext = &v2->m_SafePointerList.mNode;
      v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    }
    `eh vector constructor iterator(
      &ptr,
      0x18ui64,
      10,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody>::qSafePointer<UFG::SimComponent,UFG::RigidBody>);
    v15 = UFG::VehicleOccupantComponent::GetNumberOfOccupants(v3);
    v16 = 0;
    if ( v15 )
    {
      v17 = &ptr;
      do
      {
        v18 = UFG::VehicleOccupantComponent::GetOccupant(v3, v16, 0i64);
        v19 = UFG::RagdollComponent::Acquire(v18);
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
          v22 = &v19->m_SafePointerList.mNode.mPrev;
          v23 = v19->m_SafePointerList.mNode.mPrev;
          v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v17;
          *(_QWORD *)v17 = v23;
          *((_QWORD *)v17 + 1) = v22;
          *v22 = v17;
        }
        ++v16;
        v17 += 24;
      }
      while ( v16 < v15 );
    }
    v24 = 0;
    v25 = v1->m_VehicleCharacterRagdolls;
    do
    {
      v26 = v25->m_pPointer;
      if ( v26 )
        UFG::RagdollComponent::Release(v26, 0);
      if ( v24 >= v15 )
      {
        if ( v25->m_pPointer )
        {
          v31 = v25->mPrev;
          v32 = v25->mNext;
          v31->mNext = v32;
          v32->mPrev = v31;
          v25->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
          v25->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
        }
        v25->m_pPointer = 0i64;
      }
      else
      {
        v27 = *(UFG::RagdollComponent **)((char *)&v25[-130] + v34 - (char *)v1 - 16);
        if ( v25->m_pPointer )
        {
          v28 = v25->mPrev;
          v29 = v25->mNext;
          v28->mNext = v29;
          v29->mPrev = v28;
          v25->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
          v25->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
        }
        v25->m_pPointer = v27;
        if ( v27 )
        {
          v30 = v27->m_SafePointerList.mNode.mPrev;
          v30->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
          v25->mPrev = v30;
          v25->mNext = &v27->m_SafePointerList.mNode;
          v27->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
        }
      }
      ++v24;
      ++v25;
    }
    while ( v24 < 0xA );
    `eh vector destructor iterator(
      &ptr,
      0x18ui64,
      10,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
  }
}

// File Line: 3521
// RVA: 0x56B090
void __fastcall UFG::TargetingSystemPedPlayerComponent::maybeReleaseLockedTarget(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingProfile *r13_1; // r13
  UFG::TargetingSystemPedPlayerComponent *rsi1; // rsi
  UFG::TargetingSimObject *v3; // rax
  signed __int64 v4; // rdx
  UFG::SimObject *v5; // r15
  bool v6; // di
  signed int v7; // er14
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax
  unsigned int v10; // er8
  unsigned int v11; // er9
  signed __int64 v12; // rdx
  unsigned int v13; // er8
  unsigned int v14; // er9
  unsigned __int16 v15; // cx
  unsigned int v16; // er8
  unsigned int v17; // er9
  signed __int64 v18; // rdx
  UFG::VehicleOccupantComponent *v19; // rbp
  unsigned int v20; // er8
  unsigned int v21; // er9
  unsigned int v22; // er8
  unsigned int v23; // er9
  unsigned int v24; // edi
  unsigned int v25; // er12
  UFG::SimObject *v26; // rax
  unsigned __int16 v27; // dx
  UFG::SimComponent *v28; // rax
  unsigned int v29; // er8
  unsigned int v30; // er10
  signed __int64 v31; // rdx
  unsigned int v32; // er8
  unsigned int v33; // er10
  UFG::SimComponent *v34; // rdi
  unsigned int v35; // ebx
  ActionID *v36; // rax
  unsigned __int8 v37; // al
  UFG::SimComponent *v38; // rax
  UFG::TargetingProfile *v39; // rdx
  float v40; // xmm10_4
  float v41; // xmm11_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  __int64 v44; // rbx
  bool v45; // zf
  float v46; // xmm1_4
  float v47; // xmm0_4
  float v48; // xmm6_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  UFG::qVector3 *v51; // rdx
  unsigned __int8 v52; // cl
  signed __int64 v53; // rbx
  UFG::TargetingSimObject *v54; // rax
  float v55; // eax
  UFG::qVector3 v1; // [rsp+20h] [rbp-F8h]
  int v57; // [rsp+30h] [rbp-E8h]
  int v58; // [rsp+34h] [rbp-E4h]
  int v59; // [rsp+38h] [rbp-E0h]
  UFG::qVector3 v2; // [rsp+40h] [rbp-D8h]
  UFG::qMatrix44 matSimObject; // [rsp+50h] [rbp-C8h]

  r13_1 = this->m_pActiveTargetingProfile;
  rsi1 = this;
  v3 = this->m_pTargets;
  v4 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[22];
  if ( !v3[v4].m_pTarget.m_pPointer )
    return;
  if ( !v3[v4].m_bLock )
    return;
  v5 = v3[v4].m_pTarget.m_pPointer;
  if ( !v5 )
    return;
  v6 = 0;
  v7 = 0;
  if ( !this->m_bHasRangedWeapon && !this->m_bIsInAnyCombat )
    goto LABEL_83;
  v8 = v5->m_Flags;
  if ( !((v8 >> 14) & 1) )
  {
    if ( (v8 & 0x8000u) != 0 )
    {
      v9 = v5->m_Components.p[6].m_pComponent;
      goto LABEL_26;
    }
    if ( (v8 >> 13) & 1 )
    {
      v10 = (unsigned int)v5[1].vfptr;
      v11 = v5->m_Components.size;
      if ( v10 < v11 )
      {
        v12 = (signed __int64)&v5->m_Components.p[v10];
        while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
        {
          ++v10;
          v12 += 16i64;
          if ( v10 >= v11 )
            goto LABEL_16;
        }
LABEL_17:
        v9 = *(UFG::SimComponent **)v12;
        goto LABEL_26;
      }
    }
    else
    {
      if ( !((v8 >> 12) & 1) )
      {
        v9 = UFG::SimObject::GetComponentOfType(v5, UFG::HealthComponent::_TypeUID);
        goto LABEL_26;
      }
      v13 = (unsigned int)v5[1].vfptr;
      v14 = v5->m_Components.size;
      if ( v13 < v14 )
      {
        v12 = (signed __int64)&v5->m_Components.p[v13];
        while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
        {
          ++v13;
          v12 += 16i64;
          if ( v13 >= v14 )
          {
            v9 = 0i64;
            goto LABEL_26;
          }
        }
        goto LABEL_17;
      }
    }
LABEL_16:
    v9 = 0i64;
    goto LABEL_26;
  }
  v9 = v5->m_Components.p[6].m_pComponent;
LABEL_26:
  if ( v9 )
  {
    v6 = 0;
    if ( BYTE4(v9[1].m_BoundComponentHandles.mNode.mPrev) )
      v6 = 1;
  }
  v15 = v5->m_Flags;
  if ( (v15 >> 14) & 1 )
  {
    v16 = (unsigned int)v5[1].vfptr;
    v17 = v5->m_Components.size;
    if ( v16 < v17 )
    {
      v18 = (signed __int64)&v5->m_Components.p[v16];
      while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
      {
        ++v16;
        v18 += 16i64;
        if ( v16 >= v17 )
          goto LABEL_35;
      }
LABEL_36:
      v19 = *(UFG::VehicleOccupantComponent **)v18;
      goto LABEL_54;
    }
    goto LABEL_35;
  }
  if ( (v15 & 0x8000u) == 0 )
  {
    if ( (v15 >> 13) & 1 )
    {
      v20 = (unsigned int)v5[1].vfptr;
      v21 = v5->m_Components.size;
      if ( v20 < v21 )
      {
        v18 = (signed __int64)&v5->m_Components.p[v20];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
        {
          ++v20;
          v18 += 16i64;
          if ( v20 >= v21 )
          {
            v19 = 0i64;
            goto LABEL_54;
          }
        }
        goto LABEL_36;
      }
LABEL_35:
      v19 = 0i64;
      goto LABEL_54;
    }
    if ( (v15 >> 12) & 1 )
    {
      v22 = (unsigned int)v5[1].vfptr;
      v23 = v5->m_Components.size;
      if ( v22 < v23 )
      {
        v18 = (signed __int64)&v5->m_Components.p[v22];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
        {
          ++v22;
          v18 += 16i64;
          if ( v22 >= v23 )
          {
            v19 = 0i64;
            goto LABEL_54;
          }
        }
        goto LABEL_36;
      }
      goto LABEL_35;
    }
    v19 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                             v5,
                                             UFG::VehicleOccupantComponent::_TypeUID);
  }
  else
  {
    v19 = (UFG::VehicleOccupantComponent *)v5->m_Components.p[30].m_pComponent;
  }
LABEL_54:
  if ( v6 )
    goto LABEL_105;
  if ( !v19 )
    goto LABEL_83;
  v24 = 0;
  v25 = UFG::VehicleOccupantComponent::GetNumberOfOccupants(v19);
  if ( !v25 )
  {
LABEL_81:
    v34 = rsi1->m_pActionTreeComponent.m_pSimComponent;
    if ( v34 )
    {
      v35 = UFG::GetActionMostUsedIndex_DismountShoot();
      v36 = UFG::GetActionID_DismountShoot();
      v37 = ActionController::IsPlaying((ActionController *)&v34[3], v36, v35, 1);
      v6 = v37 == 0;
      if ( v37 )
        goto LABEL_83;
    }
    goto LABEL_105;
  }
  while ( 1 )
  {
    v26 = UFG::VehicleOccupantComponent::GetOccupant(v19, v24, 0i64);
    if ( v26 )
      break;
LABEL_80:
    if ( ++v24 >= v25 )
      goto LABEL_81;
  }
  v27 = v26->m_Flags;
  if ( !((v27 >> 14) & 1) )
  {
    if ( (v27 & 0x8000u) != 0 )
    {
      v28 = v26->m_Components.p[6].m_pComponent;
      goto LABEL_78;
    }
    if ( (v27 >> 13) & 1 )
    {
      v29 = (unsigned int)v26[1].vfptr;
      v30 = v26->m_Components.size;
      if ( v29 < v30 )
      {
        v31 = (signed __int64)&v26->m_Components.p[v29];
        while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF )
        {
          ++v29;
          v31 += 16i64;
          if ( v29 >= v30 )
            goto LABEL_68;
        }
LABEL_69:
        v28 = *(UFG::SimComponent **)v31;
        goto LABEL_78;
      }
    }
    else
    {
      if ( !((v27 >> 12) & 1) )
      {
        v28 = UFG::SimObject::GetComponentOfType(v26, UFG::HealthComponent::_TypeUID);
        goto LABEL_78;
      }
      v32 = (unsigned int)v26[1].vfptr;
      v33 = v26->m_Components.size;
      if ( v32 < v33 )
      {
        v31 = (signed __int64)&v26->m_Components.p[v32];
        while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF )
        {
          ++v32;
          v31 += 16i64;
          if ( v32 >= v33 )
          {
            v28 = 0i64;
            goto LABEL_78;
          }
        }
        goto LABEL_69;
      }
    }
LABEL_68:
    v28 = 0i64;
    goto LABEL_78;
  }
  v28 = v26->m_Components.p[6].m_pComponent;
LABEL_78:
  if ( !v28 || BYTE4(v28[1].m_BoundComponentHandles.mNode.mPrev) )
    goto LABEL_80;
  v6 = 0;
LABEL_83:
  UFG::TargetingSystemBaseComponent::FindMatrix(v5->m_pTransformNodeComponent, v5, &matSimObject);
  v38 = rsi1->m_pEquippedSOWPC.m_pPointer;
  v39 = rsi1->m_pActiveTargetingProfile;
  v40 = matSimObject.v3.x - rsi1->m_vTargetingPosition.x;
  v41 = matSimObject.v3.y - rsi1->m_vTargetingPosition.y;
  if ( v38 )
  {
    v42 = *(float *)(*((_QWORD *)&v38[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v38[2].m_pSimObject))
                   + 40i64);
    v43 = (float)(v42 + v39->m_fTargetReleaseDistancePastMaxDistance)
        * (float)(v42 + v39->m_fTargetReleaseDistancePastMaxDistance);
  }
  else
  {
    v43 = v39->m_fTargetReleaseDistanceSquared;
  }
  if ( (float)((float)((float)(v41 * v41) + (float)(v40 * v40))
             + (float)((float)(matSimObject.v3.z - rsi1->m_vTargetingPosition.z)
                     * (float)(matSimObject.v3.z - rsi1->m_vTargetingPosition.z))) > v43 )
    goto LABEL_105;
  if ( !rsi1->m_pOccupantOfVehicle.m_pPointer || rsi1->m_eFocusMode == 1 )
  {
    v44 = 0i64;
    v45 = 0;
    while ( 1 )
    {
      if ( v44 || (v46 = r13_1->m_fIdlePriorityConeTime, v46 <= 0.0) )
      {
        v48 = r13_1->m_HalfHorizontalFOVs[v44];
      }
      else
      {
        v47 = rsi1->m_fTargetingIntentionIdleTime / v46;
        if ( v47 > 1.0 )
          v47 = *(float *)&FLOAT_1_0;
        v48 = (float)((float)(1.0 - v47) * r13_1->m_HalfHorizontalFOVs[0])
            + (float)(v47 * r13_1->m_fHalfIdlePriorityConeHorizontalFOV);
      }
      v49 = rsi1->m_vTargetingIntention.x;
      v50 = rsi1->m_vTargetingIntention.y;
      v1.x = v40;
      v1.z = 0.0;
      v2.z = 0.0;
      v2.x = v49;
      v2.y = v50;
      v1.y = v41;
      if ( v45 )
      {
        v59 = 2147483648;
        v51 = (UFG::qVector3 *)&v57;
        v57 = LODWORD(v49) ^ _xmm[0];
        v58 = LODWORD(v50) ^ _xmm[0];
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
        goto LABEL_105;
    }
    if ( v7 == -1 )
      goto LABEL_105;
  }
  if ( v6 )
  {
LABEL_105:
    v52 = rsi1->m_pTargetingMap->m_Map.p[22];
    if ( v52 )
    {
      v53 = v52;
      UFG::TargetingSimObject::SetTarget(&rsi1->m_pTargets[v53], 0i64);
      v54 = rsi1->m_pTargets;
      if ( v54[v53].m_bLock )
        v54[v53].m_bLock = 0;
    }
    if ( !rsi1->m_pOccupantOfVehicle.m_pPointer && rsi1->m_eFocusMode == 1 )
    {
      if ( rsi1->m_bHasRangedWeapon )
      {
        rsi1->m_eDesiredFocusMode = 4;
        rsi1->m_eFocusMode = 4;
        v55 = rsi1->m_vAimInput.x;
        rsi1->m_vLockedFreeAimInput.y = rsi1->m_vAimInput.y;
        rsi1->m_vLockedFreeAimInput.x = v55;
      }
    }
  }
}

// File Line: 3669
// RVA: 0x5660A0
bool __fastcall UFG::TargetingSystemPedPlayerComponent::cycleTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::TargetingSystemPedPlayerComponent::eCycleTargetDirectionEnum eCycleTargetDirection, UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList)
{
  UFG::qFixedArray<UFG::CloseTarget,100> *v3; // rsi
  UFG::TargetingSystemPedPlayerComponent::eCycleTargetDirectionEnum v4; // er14
  UFG::TargetingSystemPedPlayerComponent *v5; // r15
  UFG::SimComponent *v6; // rax
  float v7; // xmm8_4
  UFG::ScoredTarget *v8; // rax
  UFG::BaseCameraComponent *v9; // rax
  int v10; // xmm1_4
  float v11; // xmm3_4
  int v12; // xmm7_4
  signed __int64 v13; // rcx
  UFG::TargetingSimObject *v14; // rax
  bool *v15; // rdi
  UFG::TransformNodeComponent *v16; // rbx
  UFG::BaseCameraComponent *v17; // rdi
  float v18; // xmm1_4
  float v19; // xmm4_4
  float v20; // xmm7_4
  float v21; // xmm10_4
  float v22; // xmm7_4
  float v23; // xmm9_4
  signed __int64 v24; // r13
  __int64 v25; // r12
  __int64 v26; // rbx
  bool v27; // r8
  UFG::BaseCameraComponent *v28; // rax
  __m128 v29; // xmm4
  float v30; // xmm2_4
  __m128 v31; // xmm1
  float v32; // xmm3_4
  float v33; // xmm5_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  bool v37; // al
  unsigned __int16 v38; // cx
  UFG::SimComponent *v39; // rax
  unsigned int v40; // er8
  unsigned int v41; // er9
  __int64 v42; // rdi
  UFG::SimObject *v43; // rcx
  bool v44; // di
  float v45; // xmm2_4
  float v46; // xmm1_4
  bool v47; // al
  signed int v48; // ecx
  __int64 v49; // rax
  float v50; // xmm2_4
  unsigned __int8 v51; // cl
  bool *bIsKnockedOut; // [rsp+50h] [rbp-78h]
  bool *bIsKnockedOuta; // [rsp+50h] [rbp-78h]
  UFG::eFactionStandingEnum eFactionStanding[2]; // [rsp+58h] [rbp-70h]
  UFG::qVector3 vMeToTarget; // [rsp+60h] [rbp-68h]
  float v57; // [rsp+6Ch] [rbp-5Ch]
  __int64 v58; // [rsp+70h] [rbp-58h]
  UFG::qVector3 n2; // [rsp+78h] [rbp-50h]
  UFG::qFixedArray<UFG::ScoredTarget,100> potentialTargets; // [rsp+88h] [rbp-40h]
  bool bShouldRejectTarget; // [rsp+778h] [rbp+6B0h]
  UFG::TargetingSystemPedPlayerComponent::eCycleTargetDirectionEnum v62; // [rsp+780h] [rbp+6B8h]
  bool bIsSocialActionAvailable; // [rsp+790h] [rbp+6C8h]

  v58 = -2i64;
  v3 = closeTargetsList;
  v4 = eCycleTargetDirection;
  v5 = this;
  v6 = this->m_pEquippedSOWPC.m_pPointer;
  if ( v6 )
    v7 = *(float *)(*((_QWORD *)&v6[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v6[2].m_pSimObject)) + 156i64);
  else
    v7 = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fFlickTargetingAngularLimitRad;
  if ( (unsigned int)(this->m_eFocusMode - 2) <= 2 )
  {
    v7 = UFG::TargetingSystemPedPlayerComponent::ms_fSoftLockFlickAcquisitionConeHalfAngleRad;
    if ( UFG::TargetingSystemPedPlayerComponent::ms_fSoftLockFlickAcquisitionConeHalfAngleRad <= 0.0 )
    {
      LOBYTE(v8) = 0;
      return (char)v8;
    }
  }
  v9 = UFG::Director::Get()->mCurrentCamera;
  if ( v9 )
    v9 = (UFG::BaseCameraComponent *)((char *)v9 + 80);
  v10 = LODWORD(v9->mCamera.mView.v1.z) ^ _xmm[0];
  LODWORD(v11) = LODWORD(v9->mCamera.mView.v1.y) ^ _xmm[0];
  v12 = LODWORD(v9->mCamera.mView.v1.x) ^ _xmm[0];
  LODWORD(vMeToTarget.z) = LODWORD(v9->mCamera.mView.v1.x) ^ _xmm[0];
  v57 = v11;
  LODWORD(v58) = v10;
  v13 = (unsigned __int8)v5->m_pTargetingMap->m_Map.p[22];
  v14 = v5->m_pTargets;
  if ( v14[v13].m_pTarget.m_pPointer && v14[v13].m_bLock )
  {
    v15 = (bool *)v14[v13].m_pTarget.m_pPointer;
    bIsKnockedOut = v15;
    if ( v15 )
    {
      if ( (unsigned int)(v5->m_eFocusMode - 3) > 1 )
      {
        v16 = (UFG::TransformNodeComponent *)*((_QWORD *)v15 + 11);
        if ( v16 )
        {
          v17 = UFG::Director::Get()->mCurrentCamera;
          if ( v17 )
            v17 = (UFG::BaseCameraComponent *)((char *)v17 + 80);
          UFG::TransformNodeComponent::UpdateWorldTransform(v16);
          v11 = v16->mWorldTransform.v3.y - v17->mCamera.mView.v2.y;
          *(float *)&v12 = v16->mWorldTransform.v3.x - v17->mCamera.mView.v2.x;
          v15 = bIsKnockedOut;
        }
      }
    }
  }
  else
  {
    v15 = 0i64;
  }
  v18 = (float)(*(float *)&v12 * *(float *)&v12) + (float)(v11 * v11);
  if ( v18 == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / fsqrt(v18);
  v20 = *(float *)&v12 * v19;
  vMeToTarget.z = v20;
  v57 = v11 * v19;
  *(float *)&v58 = v19 * 0.0;
  v21 = (float)((float)(v11 * v19) * UFG::qVector3::msAxisZ.x) - (float)(v20 * UFG::qVector3::msAxisZ.y);
  v22 = (float)(v20 * UFG::qVector3::msAxisZ.z) - (float)(UFG::qVector3::msAxisZ.x * (float)(v19 * 0.0));
  v23 = (float)(UFG::qVector3::msAxisZ.y * (float)(v19 * 0.0)) - (float)((float)(v11 * v19) * UFG::qVector3::msAxisZ.z);
  potentialTargets.size = 0;
  if ( v3->size )
  {
    v24 = (signed __int64)&v3->p[0].m_Xform.v3;
    v25 = v3->size;
    while ( 1 )
    {
      v26 = *(_QWORD *)(*(_QWORD *)(v24 - 56) + 40i64);
      eFactionStanding[0] = 1;
      v27 = v5->m_bIsInAnyCombat || v5->m_bIsAimingActive;
      UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(
        v5,
        (UFG::SimObject *)v26,
        v27,
        &bShouldRejectTarget,
        (UFG::SimObject **)&n2,
        (bool *)&vMeToTarget.y,
        (bool *)&vMeToTarget,
        eFactionStanding,
        (bool *)&vMeToTarget.x + 2,
        (bool *)&vMeToTarget.x + 1,
        (bool *)&vMeToTarget.x + 3,
        &bIsSocialActionAvailable);
      if ( bShouldRejectTarget || (bool *)v26 == v15 )
        goto LABEL_69;
      v28 = UFG::Director::Get()->mCurrentCamera;
      if ( v28 )
        v28 = (UFG::BaseCameraComponent *)((char *)v28 + 80);
      v29 = (__m128)*(unsigned int *)(v24 + 4);
      v29.m128_f32[0] = v29.m128_f32[0] - v28->mCamera.mView.v2.y;
      v30 = *(float *)v24 - v28->mCamera.mView.v2.x;
      v31 = v29;
      v31.m128_f32[0] = (float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v30 * v30);
      v32 = v31.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
      v33 = v32 * 0.0;
      v34 = v32 * v29.m128_f32[0];
      v35 = v30 * v32;
      n2.x = v35;
      n2.y = v32 * v29.m128_f32[0];
      if ( v4 )
      {
        if ( v4 != 1 )
          goto LABEL_69;
        v36 = v21 * v33;
        v37 = (float)((float)((float)(v34 * v22) + (float)(v35 * v23)) + (float)(v21 * v33)) <= 0.0;
      }
      else
      {
        v36 = v21 * v33;
        v37 = (float)((float)((float)(v34 * v22) + (float)(v35 * v23)) + (float)(v21 * v33)) >= 0.0;
      }
      if ( !v37 )
        goto LABEL_69;
      if ( !v26 )
        goto LABEL_80;
      v38 = *(_WORD *)(v26 + 76);
      if ( (v38 >> 14) & 1 )
      {
        v39 = *(UFG::SimComponent **)(*(_QWORD *)(v26 + 104) + 224i64);
      }
      else if ( (v38 & 0x8000u) == 0 )
      {
        if ( (v38 >> 13) & 1 )
        {
          v39 = *(UFG::SimComponent **)(*(_QWORD *)(v26 + 104) + 144i64);
        }
        else if ( (v38 >> 12) & 1 )
        {
          v40 = *(_DWORD *)(v26 + 128);
          v41 = *(_DWORD *)(v26 + 96);
          if ( v40 >= v41 )
          {
LABEL_54:
            v39 = 0i64;
          }
          else
          {
            v42 = *(_QWORD *)(v26 + 104);
            while ( (*(_DWORD *)(v42 + 16i64 * v40 + 8) & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
                 || UFG::CompositeDrawableComponent::_TypeUID & ~*(_DWORD *)(v42 + 16i64 * v40 + 8) & 0x1FFFFFF )
            {
              if ( ++v40 >= v41 )
                goto LABEL_54;
            }
            v39 = *(UFG::SimComponent **)(v42 + 16i64 * v40);
          }
        }
        else
        {
          v39 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v26, UFG::CompositeDrawableComponent::_TypeUID);
        }
      }
      else
      {
        v39 = *(UFG::SimComponent **)(*(_QWORD *)(v26 + 104) + 224i64);
      }
      if ( v39 )
        v43 = v39[19].m_pSimObject;
      else
LABEL_80:
        v43 = 0i64;
      v44 = v43 ? LOBYTE(v43->vfptr) <= 1u : 1;
      UFG::qAngleBetweenNormals((UFG::qVector3 *)((char *)&vMeToTarget + 8), &n2);
      if ( !v44 && v7 < v36 )
        goto LABEL_69;
      v45 = *(float *)(v24 + 8) - v5->m_vTargetingPosition.z;
      v46 = *(float *)(v24 + 4) - v5->m_vTargetingPosition.y;
      vMeToTarget.x = *(float *)v24 - v5->m_vTargetingPosition.x;
      vMeToTarget.y = v46;
      vMeToTarget.z = v45;
      v47 = UFG::TargetingSystemPedBaseComponent::IsWithinVerticalFOV(
              (UFG::TargetingSystemPedBaseComponent *)&v5->vfptr,
              &vMeToTarget,
              v5->m_pActiveTargetingProfile->m_fHalfVerticalFOV,
              v5->m_pActiveTargetingProfile->m_fExtraPositivePitch,
              v5->m_pActiveTargetingProfile->m_fExtraNegativePitch);
      if ( !v44 && !v47 )
        goto LABEL_69;
      if ( UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(
             v5,
             &v5->m_vTargetingPosition,
             (UFG::SimObject *)v26,
             (UFG::qMatrix44 *)(v24 - 48),
             0,
             0) < 0.0 )
        goto LABEL_69;
      v48 = potentialTargets.size;
      if ( potentialTargets.size < 0x64 )
        break;
LABEL_70:
      v24 += 80i64;
      --v25;
      v15 = bIsKnockedOuta;
      v4 = v62;
      if ( !v25 )
        goto LABEL_73;
    }
    v49 = potentialTargets.size;
    ++potentialTargets.size;
    v50 = (float)((float)(n2.x * vMeToTarget.z) + (float)(n2.y * v57)) + (float)((float)(v32 * 0.0) * *(float *)&v58);
    potentialTargets.p[v49].m_pSimObject = (UFG::SimObject *)v26;
    potentialTargets.p[v49].m_fScore = v50;
LABEL_69:
    v48 = potentialTargets.size;
    goto LABEL_70;
  }
  v48 = potentialTargets.size;
LABEL_73:
  UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
    (ClassTypeDescriptor *)potentialTargets.p,
    (ClassTypeDescriptor *)&n2.z + v48,
    (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::BiggerScoresAreBetter);
  v8 = UFG::TargetingSystemPedPlayerComponent::chooseBestVisibleTarget(
         v5,
         &potentialTargets,
         UFG::TargetingSystemPedPlayerComponent::ms_MaxRaycastsBeforeGiveUpForCycle);
  if ( v8 )
  {
    v51 = v5->m_pTargetingMap->m_Map.p[22];
    if ( v51 )
      UFG::TargetingSimObject::SetTarget(&v5->m_pTargets[v51], v8->m_pSimObject);
    LOBYTE(v8) = 1;
  }
  return (char)v8;
}

// File Line: 3883
// RVA: 0x566700
char __fastcall UFG::TargetingSystemPedPlayerComponent::cycleTargetManual(UFG::TargetingSystemPedPlayerComponent *this, UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList)
{
  UFG::qFixedArray<UFG::CloseTarget,100> *v2; // rdi
  UFG::TargetingSystemPedPlayerComponent *v3; // r14
  UFG::SimObject *v4; // r15
  UFG::TransformNodeComponent *v5; // rbx
  int v6; // eax
  UFG::InputActionData *v7; // rcx
  float v8; // xmm11_4
  int v9; // xmm10_4
  UFG::BaseCameraComponent *v10; // rax
  int v11; // xmm2_4
  int v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  __m128 v15; // xmm1
  float v16; // xmm7_4
  __m128 v17; // xmm8
  float v18; // xmm6_4
  UFG::BaseCameraComponent *v19; // rax
  float v20; // xmm3_4
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  float v23; // xmm2_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  __m128 v26; // xmm2
  float v27; // xmm1_4
  float v28; // xmm12_4
  float v29; // xmm13_4
  float v30; // xmm14_4
  float v31; // xmm8_4
  __int64 v32; // r8
  unsigned int v33; // er9
  signed __int64 v34; // rax
  float *v35; // rcx
  unsigned int v36; // eax
  __int64 v37; // rdx
  float v38; // xmm2_4
  float v39; // xmm2_4
  float v40; // xmm2_4
  float v41; // xmm2_4
  float *v42; // rcx
  __int64 v43; // rdx
  float v44; // xmm2_4
  signed __int64 v45; // rdi
  __int64 v46; // rsi
  __int64 v47; // rbx
  __m128 v48; // xmm4
  float v49; // xmm2_4
  __m128 v50; // xmm1
  float v51; // xmm3_4
  float v52; // xmm10_4
  unsigned __int16 v53; // cx
  UFG::SimComponent *v54; // rax
  unsigned int v55; // er8
  unsigned int v56; // er10
  __int64 v57; // r11
  UFG::SimObject *v58; // rcx
  float v59; // xmm7_4
  float v60; // xmm6_4
  float v61; // xmm11_4
  float v62; // xmm11_4
  float v63; // xmm0_4
  __int64 v64; // rax
  UFG::ScoredTarget *v65; // rax
  unsigned __int8 v66; // cl
  UFG::qVector3 n2; // [rsp+30h] [rbp-B8h]
  UFG::qVector3 vMeToTarget; // [rsp+40h] [rbp-A8h]
  UFG::qVector3 n1; // [rsp+50h] [rbp-98h]
  __int64 v71; // [rsp+60h] [rbp-88h]
  ClassTypeDescriptor right; // [rsp+68h] [rbp-80h]
  ClassTypeDescriptor left[110]; // [rsp+78h] [rbp-70h]

  v71 = -2i64;
  v2 = closeTargetsList;
  v3 = this;
  v4 = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( !v4 )
    return 0;
  v5 = v4->m_pTransformNodeComponent;
  if ( !v5 )
    return 0;
  v6 = 0;
  if ( this->m_pAICharacterControllerComponent.m_pSimComponent )
    v6 = (int)this->m_pAICharacterControllerComponent.m_pSimComponent[17].m_SafePointerList.mNode.mPrev;
  v7 = UFG::ActionDef_TargetCycle.mDataPerController[v6];
  if ( !v7 || !v7->mActionTrue )
    return 0;
  v8 = v7->mAxisRawX[0];
  v9 = LODWORD(v7->mAxisRawY[0]) ^ _xmm[0];
  v10 = UFG::Director::Get()->mCurrentCamera;
  if ( v10 )
    v10 = (UFG::BaseCameraComponent *)((char *)v10 + 80);
  v11 = LODWORD(v10->mCamera.mView.v1.y) ^ _xmm[0];
  v12 = LODWORD(v10->mCamera.mView.v1.x) ^ _xmm[0];
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
  v20 = v19->mCamera.mDepthOfFieldFocus.mFarBlurRadius;
  v21 = (__m128)*((unsigned int *)&v19->mCamera.mDepthOfFieldFocus + 6);
  v22 = v21;
  v22.m128_f32[0] = (float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20);
  if ( v22.m128_f32[0] == 0.0 )
    v23 = 0.0;
  else
    v23 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v22));
  v24 = (float)(v16 * *(float *)&v9) + (float)((float)(v23 * 0.0) * v8);
  v17.m128_f32[0] = (float)(v17.m128_f32[0] * *(float *)&v9) + (float)((float)(v23 * v21.m128_f32[0]) * v8);
  v25 = (float)(v18 * *(float *)&v9) + (float)((float)(v23 * v20) * v8);
  v26 = v17;
  v26.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v25 * v25)) + (float)(v24 * v24);
  if ( v26.m128_f32[0] == 0.0 )
    v27 = 0.0;
  else
    v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
  n2.x = v25 * v27;
  n2.y = v17.m128_f32[0] * v27;
  n2.z = v24 * v27;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v28 = v5->mWorldTransform.v3.x;
  v29 = v5->mWorldTransform.v3.y;
  v30 = v5->mWorldTransform.v3.z;
  LODWORD(right.mfnInPlaceNew) = 0;
  v31 = 0.0;
  v32 = v2->size;
  v33 = 0;
  v34 = 0i64;
  if ( (signed int)v32 >= 4 )
  {
    v35 = &v2->p[3].m_Xform.v3.y;
    v36 = ((unsigned int)(v32 - 4) >> 2) + 1;
    v37 = v36;
    v33 = 4 * v36;
    v34 = 4i64 * v36;
    do
    {
      v38 = (float)((float)((float)(*(v35 - 60) - v29) * (float)(*(v35 - 60) - v29))
                  + (float)((float)(*(v35 - 61) - v28) * (float)(*(v35 - 61) - v28)))
          + (float)((float)(*(v35 - 59) - v30) * (float)(*(v35 - 59) - v30));
      if ( v38 > v31 )
      {
        if ( v38 <= 0.0 )
        {
          v31 = 0.0;
        }
        else
        {
          v31 = (float)((float)((float)(*(v35 - 60) - v29) * (float)(*(v35 - 60) - v29))
                      + (float)((float)(*(v35 - 61) - v28) * (float)(*(v35 - 61) - v28)))
              + (float)((float)(*(v35 - 59) - v30) * (float)(*(v35 - 59) - v30));
          if ( v38 >= 100.0 )
            v31 = FLOAT_100_0;
        }
      }
      v39 = (float)((float)((float)(*(v35 - 40) - v29) * (float)(*(v35 - 40) - v29))
                  + (float)((float)(*(v35 - 41) - v28) * (float)(*(v35 - 41) - v28)))
          + (float)((float)(*(v35 - 39) - v30) * (float)(*(v35 - 39) - v30));
      if ( v39 > v31 )
      {
        if ( v39 <= 0.0 )
        {
          v31 = 0.0;
        }
        else
        {
          v31 = (float)((float)((float)(*(v35 - 40) - v29) * (float)(*(v35 - 40) - v29))
                      + (float)((float)(*(v35 - 41) - v28) * (float)(*(v35 - 41) - v28)))
              + (float)((float)(*(v35 - 39) - v30) * (float)(*(v35 - 39) - v30));
          if ( v39 >= 100.0 )
            v31 = FLOAT_100_0;
        }
      }
      v40 = (float)((float)((float)(*(v35 - 20) - v29) * (float)(*(v35 - 20) - v29))
                  + (float)((float)(*(v35 - 21) - v28) * (float)(*(v35 - 21) - v28)))
          + (float)((float)(*(v35 - 19) - v30) * (float)(*(v35 - 19) - v30));
      if ( v40 > v31 )
      {
        if ( v40 <= 0.0 )
        {
          v31 = 0.0;
        }
        else
        {
          v31 = (float)((float)((float)(*(v35 - 20) - v29) * (float)(*(v35 - 20) - v29))
                      + (float)((float)(*(v35 - 21) - v28) * (float)(*(v35 - 21) - v28)))
              + (float)((float)(*(v35 - 19) - v30) * (float)(*(v35 - 19) - v30));
          if ( v40 >= 100.0 )
            v31 = FLOAT_100_0;
        }
      }
      v41 = (float)((float)((float)(*v35 - v29) * (float)(*v35 - v29))
                  + (float)((float)(*(v35 - 1) - v28) * (float)(*(v35 - 1) - v28)))
          + (float)((float)(v35[1] - v30) * (float)(v35[1] - v30));
      if ( v41 > v31 )
      {
        if ( v41 <= 0.0 )
        {
          v31 = 0.0;
        }
        else
        {
          v31 = (float)((float)((float)(*v35 - v29) * (float)(*v35 - v29))
                      + (float)((float)(*(v35 - 1) - v28) * (float)(*(v35 - 1) - v28)))
              + (float)((float)(v35[1] - v30) * (float)(v35[1] - v30));
          if ( v41 >= 100.0 )
            v31 = FLOAT_100_0;
        }
      }
      v35 += 80;
      --v37;
    }
    while ( v37 );
  }
  if ( v33 < (unsigned int)v32 )
  {
    v42 = &v2->p[v34].m_Xform.v3.y;
    v43 = (unsigned int)v32 - v33;
    do
    {
      v44 = (float)((float)((float)(*v42 - v29) * (float)(*v42 - v29))
                  + (float)((float)(*(v42 - 1) - v28) * (float)(*(v42 - 1) - v28)))
          + (float)((float)(v42[1] - v30) * (float)(v42[1] - v30));
      if ( v44 > v31 )
      {
        if ( v44 <= 0.0 )
        {
          v31 = 0.0;
        }
        else
        {
          v31 = (float)((float)((float)(*v42 - v29) * (float)(*v42 - v29))
                      + (float)((float)(*(v42 - 1) - v28) * (float)(*(v42 - 1) - v28)))
              + (float)((float)(v42[1] - v30) * (float)(v42[1] - v30));
          if ( v44 >= 100.0 )
            v31 = FLOAT_100_0;
        }
      }
      v42 += 20;
      --v43;
    }
    while ( v43 );
  }
  if ( (_DWORD)v32 )
  {
    v45 = (signed __int64)&v2->p[0].m_Xform.v3;
    v46 = v32;
    do
    {
      v47 = *(_QWORD *)(*(_QWORD *)(v45 - 56) + 40i64);
      if ( (UFG::SimObject *)v47 != v4 )
      {
        v48 = (__m128)*(unsigned int *)(v45 + 4);
        v48.m128_f32[0] = v48.m128_f32[0] - v29;
        v49 = *(float *)v45 - v28;
        v50 = v48;
        v50.m128_f32[0] = (float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(v49 * v49);
        v51 = v50.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v50));
        n1.x = v49 * v51;
        n1.y = v51 * v48.m128_f32[0];
        n1.z = v51 * 0.0;
        v52 = (float)((float)((float)(v51 * v48.m128_f32[0]) * n2.y) + (float)((float)(v49 * v51) * n2.x))
            + (float)(n2.z * (float)(v51 * 0.0));
        if ( v52 > 0.0 )
        {
          if ( !v47 )
            goto LABEL_92;
          v53 = *(_WORD *)(v47 + 76);
          if ( (v53 >> 14) & 1 )
          {
            v54 = *(UFG::SimComponent **)(*(_QWORD *)(v47 + 104) + 224i64);
          }
          else if ( (v53 & 0x8000u) == 0 )
          {
            if ( (v53 >> 13) & 1 )
            {
              v54 = *(UFG::SimComponent **)(*(_QWORD *)(v47 + 104) + 144i64);
            }
            else if ( (v53 >> 12) & 1 )
            {
              v55 = *(_DWORD *)(v47 + 128);
              v56 = *(_DWORD *)(v47 + 96);
              if ( v55 >= v56 )
              {
LABEL_73:
                v54 = 0i64;
              }
              else
              {
                v57 = *(_QWORD *)(v47 + 104);
                while ( (*(_DWORD *)(v57 + 16i64 * v55 + 8) & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
                     || UFG::CompositeDrawableComponent::_TypeUID & ~*(_DWORD *)(v57 + 16i64 * v55 + 8) & 0x1FFFFFF )
                {
                  if ( ++v55 >= v56 )
                    goto LABEL_73;
                }
                v54 = *(UFG::SimComponent **)(v57 + 16i64 * v55);
              }
            }
            else
            {
              v54 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v47, UFG::CompositeDrawableComponent::_TypeUID);
            }
          }
          else
          {
            v54 = *(UFG::SimComponent **)(*(_QWORD *)(v47 + 104) + 224i64);
          }
          if ( v54 )
            v58 = v54[19].m_pSimObject;
          else
LABEL_92:
            v58 = 0i64;
          if ( !v58 || LOBYTE(v58->vfptr) <= 1u )
          {
            v59 = *(float *)(v45 + 8) - v30;
            v60 = *(float *)(v45 + 4) - v29;
            vMeToTarget.x = *(float *)v45 - v28;
            v61 = vMeToTarget.x;
            vMeToTarget.y = v60;
            vMeToTarget.z = v59;
            UFG::TargetingSystemPedBaseComponent::IsWithinVerticalFOV(
              (UFG::TargetingSystemPedBaseComponent *)&v3->vfptr,
              &vMeToTarget,
              v3->m_pActiveTargetingProfile->m_fHalfVerticalFOV,
              v3->m_pActiveTargetingProfile->m_fExtraPositivePitch,
              v3->m_pActiveTargetingProfile->m_fExtraNegativePitch);
            UFG::qAngleBetweenNormals(&n1, &n2);
            v62 = (float)((float)(v61 * v61) + (float)(v60 * v60)) + (float)(v59 * v59);
            if ( UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(
                   v3,
                   &v3->m_vTargetingPosition,
                   *(UFG::SimObject **)(*(_QWORD *)(v45 - 56) + 40i64),
                   (UFG::qMatrix44 *)(v45 - 48),
                   0,
                   0) >= 0.0 )
            {
              v63 = (float)((float)(1.0 - (float)(v62 / v31))
                          * UFG::TargetingSystemPedPlayerComponent::ms_fTargetRelativeMeleeCyclingDistanceScale)
                  + (float)(v52 * UFG::TargetingSystemPedPlayerComponent::ms_fTargetRelativeMeleeCyclingAngleScale);
              if ( LODWORD(right.mfnInPlaceNew) < 0x64 )
              {
                v64 = LODWORD(right.mfnInPlaceNew);
                ++LODWORD(right.mfnInPlaceNew);
                *((_QWORD *)&right.mUID + v64 * 2) = v47;
                *(float *)&left[v64].mUID = v63;
              }
            }
          }
        }
      }
      v45 += 80i64;
      --v46;
    }
    while ( v46 );
  }
  UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
    left,
    &right + SLODWORD(right.mfnInPlaceNew),
    (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::BiggerScoresAreBetter);
  v65 = UFG::TargetingSystemPedPlayerComponent::chooseBestVisibleTarget(
          v3,
          (UFG::qFixedArray<UFG::ScoredTarget,100> *)&right.mfnInPlaceNew,
          UFG::TargetingSystemPedPlayerComponent::ms_MaxRaycastsBeforeGiveUpForCycle);
  if ( !v65 )
  {
    LODWORD(right.mfnInPlaceNew) = 0;
    return 0;
  }
  v66 = v3->m_pTargetingMap->m_Map.p[22];
  if ( v66 )
    UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v66], v65->m_pSimObject);
  LODWORD(right.mfnInPlaceNew) = 0;
  return 1;
}

// File Line: 4042
// RVA: 0x564810
float __fastcall UFG::TargetingSystemPedPlayerComponent::calculateScore(UFG::TargetingSystemPedPlayerComponent *this, UFG::eConeEnum eCone, const float fDistanceToTargetSquared, const float fMaxDistanceToTargetSquared, const float fHorizontalAngularDiff, const bool bIsAlreadyTargeted, const bool bIsDowned, const bool bIsKnockedOut, UFG::eFactionStandingEnum eFactionStanding, const bool bIsScripted, const bool bIsOnVehicle, const bool bIsTargetVehicle, const bool bTargetVehicleHasOccupant, const bool bIsSocialActionAvailable)
{
  UFG::eConeEnum v14; // esi
  float v16; // xmm8_4
  float v17; // xmm7_4
  float v18; // xmm7_4
  float v19; // xmm7_4
  float v20; // xmm0_4

  v14 = eCone;
  if ( (unsigned int)(eCone - 3) <= 1 && eFactionStanding != 2 && !bIsSocialActionAvailable )
    return FLOAT_N1_0;
  v16 = (float)(signed int)eCone;
  v17 = (float)(1.0
              - UFG::LinearTable<float>::GetValue(
                  &UFG::TargetingSystemPedBaseComponent::ms_CloseToTargetTable,
                  1.0 - (float)(fDistanceToTargetSquared / fMaxDistanceToTargetSquared)))
      * UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias;
  v18 = v17
      + (float)(UFG::LinearTable<float>::GetValue(
                  &UFG::TargetingSystemPedBaseComponent::ms_CloseToCenterTable,
                  fHorizontalAngularDiff * 0.31830987)
              * (float)(1.0 - UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias));
  if ( bIsAlreadyTargeted )
    v18 = v18 - UFG::TargetingSystemPedPlayerComponent::ms_fCurrentTargetBonus;
  if ( bIsDowned )
  {
    v19 = (float)(v18 * 0.10000002) + 0.89999998;
  }
  else if ( eFactionStanding == 2 )
  {
    v19 = v18 * 0.5;
  }
  else if ( bIsSocialActionAvailable )
  {
    v19 = (float)(v18 * 0.10000002) + 0.5;
  }
  else
  {
    v19 = (float)(v18 * 0.29999995) + 0.60000002;
    if ( bIsScripted && s_bUseScriptedCheck )
      v19 = v19 * s_fScriptedModifierBonus;
  }
  if ( v19 <= 0.0 )
  {
    v19 = 0.0;
    goto LABEL_20;
  }
  v20 = FLOAT_0_99900001;
  if ( v19 < 0.99900001 )
LABEL_20:
    v20 = v19;
  if ( v14 )
  {
    if ( bIsDowned )
      v16 = FLOAT_5_0;
    if ( eFactionStanding != 2 )
      v16 = v16 + 1.0;
  }
  if ( bIsKnockedOut )
    v16 = v16 + 10.0;
  if ( bIsOnVehicle )
  {
    if ( bIsTargetVehicle )
    {
      if ( !bTargetVehicleHasOccupant )
        return v20 + (float)(v16 + 10.0);
    }
    else
    {
      v16 = v16 + 5.0;
    }
  }
  return v20 + v16;
}

// File Line: 4172
// RVA: 0x56A9B0
bool __fastcall UFG::TargetingSystemPedPlayerComponent::isCommonInvalidTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::SimObject *pSimObject)
{
  UFG::SimObject *v2; // rbx
  UFG::TargetingSystemPedPlayerComponent *v3; // rdi
  bool result; // al
  UFG::TargetingSimObject *v5; // rax
  signed __int64 v6; // rcx
  UFG::SimObject *v7; // rax

  v2 = pSimObject;
  v3 = this;
  result = 1;
  if ( pSimObject != this->m_pOccupantOfVehicle.m_pPointer
    && (!((pSimObject->m_Flags >> 14) & 1)
     || !pSimObject->m_Components.p[44].m_pComponent
     && !UFG::TargetingSystemPedBaseComponent::isAlliedToMe(
           (UFG::TargetingSystemPedBaseComponent *)&this->vfptr,
           pSimObject)) )
  {
    v5 = v3->m_pTargets;
    v6 = (unsigned __int8)v3->m_pTargetingMap->m_Map.p[23];
    if ( !v5[v6].m_pTarget.m_pPointer || !v5[v6].m_bLock || (v7 = v5[v6].m_pTarget.m_pPointer) == 0i64 || v2 != v7 )
      result = 0;
  }
  return result;
}

// File Line: 4221
// RVA: 0x568800
void __fastcall UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(UFG::TargetingSystemPedPlayerComponent *this, UFG::SimObject *pSimObject, const bool bRejectIfNotHostile, bool *bShouldRejectTarget, UFG::SimObject **pPedTarget, bool *bIsTargetVehicle, bool *bTargetVehicleHasOccupant, UFG::eFactionStandingEnum *eFactionStanding, bool *bIsDowned, bool *bIsScripted, bool *bIsKnockedOut, bool *bIsSocialActionAvailable)
{
  bool v12; // bp
  bool *v13; // rdi
  UFG::SimObject *v14; // r10
  unsigned __int16 v15; // dx
  UFG::SimComponent *v16; // rax
  unsigned int v17; // er8
  unsigned int v18; // er9
  signed __int64 v19; // rdx
  int v20; // ecx
  bool v21; // al
  UFG::HealthComponent *v22; // r14
  UFG::SimObject *v23; // rcx
  unsigned __int16 v24; // dx
  unsigned int v25; // er8
  unsigned int v26; // er9
  signed __int64 v27; // rdx
  UFG::VehicleOccupantComponent *v28; // rsi
  unsigned int v29; // er8
  unsigned int v30; // er9
  unsigned int v31; // er8
  unsigned int v32; // er9
  unsigned int v33; // edi
  unsigned int v34; // ebp
  UFG::SimObject *v35; // rax
  UFG::SimObject *v36; // rbx
  unsigned __int16 v37; // dx
  UFG::SimComponent *v38; // rax
  unsigned int v39; // er8
  unsigned int v40; // er9
  signed __int64 v41; // rdx
  unsigned int v42; // er8
  unsigned int v43; // er9
  unsigned __int16 v44; // dx
  unsigned int v45; // er8
  unsigned int v46; // er9
  signed __int64 v47; // rdx
  unsigned int v48; // er8
  unsigned int v49; // er9
  UFG::eFactionStandingEnum v50; // eax
  UFG::SimObject *v51; // rcx
  UFG::ActionTreeComponent *v52; // rax
  unsigned __int16 v53; // dx
  unsigned int v54; // er8
  unsigned int v55; // er9
  signed __int64 v56; // rdx
  bool v57; // di
  bool v58; // cl
  UFG::SimObject *v59; // rcx
  unsigned __int16 v60; // dx
  UFG::FaceActionComponent *v61; // rbx
  unsigned int v62; // er8
  unsigned int v63; // er9
  signed __int64 v64; // rdx
  unsigned int v65; // er8
  unsigned int v66; // er9
  unsigned int v67; // er8
  unsigned int v68; // er9
  UFG::SimObject *v69; // rax
  UFG::TargetingSystemPedPlayerComponent *v70; // [rsp+60h] [rbp+8h]
  bool v71; // [rsp+70h] [rbp+18h]
  bool *v72; // [rsp+78h] [rbp+20h]

  v72 = bShouldRejectTarget;
  v71 = bRejectIfNotHostile;
  v70 = this;
  v12 = bRejectIfNotHostile;
  *bShouldRejectTarget = 0;
  v13 = bShouldRejectTarget;
  v14 = pSimObject;
  *pPedTarget = pSimObject;
  if ( !pSimObject )
    goto LABEL_165;
  v15 = pSimObject->m_Flags;
  if ( (v15 >> 14) & 1 )
  {
    v16 = v14->m_Components.p[3].m_pComponent;
  }
  else if ( (v15 & 0x8000u) == 0 )
  {
    if ( (v15 >> 13) & 1 )
    {
      v16 = v14->m_Components.p[4].m_pComponent;
    }
    else if ( (v15 >> 12) & 1 )
    {
      v17 = (unsigned int)v14[1].vfptr;
      v18 = v14->m_Components.size;
      if ( v17 >= v18 )
      {
LABEL_14:
        v16 = 0i64;
      }
      else
      {
        v19 = (signed __int64)&v14->m_Components.p[v17];
        while ( (*(_DWORD *)(v19 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v19 + 8) & 0x1FFFFFF )
        {
          ++v17;
          v19 += 16i64;
          if ( v17 >= v18 )
            goto LABEL_14;
        }
        v16 = *(UFG::SimComponent **)v19;
      }
    }
    else
    {
      v16 = UFG::SimObject::GetComponentOfType(v14, UFG::SimObjectPropertiesComponent::_TypeUID);
    }
  }
  else
  {
    v16 = v14->m_Components.p[3].m_pComponent;
  }
  if ( !v16 )
    goto LABEL_165;
  v20 = (int)v16[1].m_SafePointerList.mNode.mNext;
  if ( v20 == 5 )
  {
    *v13 = 1;
    return;
  }
  if ( v20 == 4 )
    v21 = 1;
  else
LABEL_165:
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
    if ( (v24 >> 14) & 1 )
    {
      v25 = (unsigned int)v23[1].vfptr;
      v26 = v23->m_Components.size;
      if ( v25 < v26 )
      {
        v27 = (signed __int64)&v23->m_Components.p[v25];
        while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF )
        {
          ++v25;
          v27 += 16i64;
          if ( v25 >= v26 )
            goto LABEL_31;
        }
LABEL_32:
        v28 = *(UFG::VehicleOccupantComponent **)v27;
        goto LABEL_50;
      }
      goto LABEL_31;
    }
    if ( (v24 & 0x8000u) == 0 )
    {
      if ( (v24 >> 13) & 1 )
      {
        v29 = (unsigned int)v23[1].vfptr;
        v30 = v23->m_Components.size;
        if ( v29 < v30 )
        {
          v27 = (signed __int64)&v23->m_Components.p[v29];
          while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
               || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF )
          {
            ++v29;
            v27 += 16i64;
            if ( v29 >= v30 )
            {
              v28 = 0i64;
              goto LABEL_50;
            }
          }
          goto LABEL_32;
        }
LABEL_31:
        v28 = 0i64;
        goto LABEL_50;
      }
      if ( (v24 >> 12) & 1 )
      {
        v31 = (unsigned int)v23[1].vfptr;
        v32 = v23->m_Components.size;
        if ( v31 < v32 )
        {
          v27 = (signed __int64)&v23->m_Components.p[v31];
          while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
               || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF )
          {
            ++v31;
            v27 += 16i64;
            if ( v31 >= v32 )
            {
              v28 = 0i64;
              goto LABEL_50;
            }
          }
          goto LABEL_32;
        }
        goto LABEL_31;
      }
      v28 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                               v23,
                                               UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v28 = (UFG::VehicleOccupantComponent *)v23->m_Components.p[30].m_pComponent;
    }
LABEL_50:
    if ( v28 )
    {
      v33 = 0;
      v34 = UFG::VehicleOccupantComponent::GetNumberOfOccupants(v28);
      if ( v34 )
      {
        do
        {
          v35 = UFG::VehicleOccupantComponent::GetOccupant(v28, v33, 0i64);
          v36 = v35;
          if ( !v35 )
            goto LABEL_75;
          v37 = v35->m_Flags;
          if ( (v37 >> 14) & 1 )
          {
            v38 = v35->m_Components.p[6].m_pComponent;
          }
          else if ( (v37 & 0x8000u) == 0 )
          {
            if ( (v37 >> 13) & 1 )
            {
              v39 = (unsigned int)v35[1].vfptr;
              v40 = v35->m_Components.size;
              if ( v39 < v40 )
              {
                v41 = (signed __int64)&v35->m_Components.p[v39];
                while ( (*(_DWORD *)(v41 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                     || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v41 + 8) & 0x1FFFFFF )
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
              if ( !((v37 >> 12) & 1) )
              {
                v38 = UFG::SimObject::GetComponentOfType(v35, UFG::HealthComponent::_TypeUID);
                goto LABEL_73;
              }
              v42 = (unsigned int)v35[1].vfptr;
              v43 = v35->m_Components.size;
              if ( v42 < v43 )
              {
                v41 = (signed __int64)&v35->m_Components.p[v42];
                while ( (*(_DWORD *)(v41 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                     || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v41 + 8) & 0x1FFFFFF )
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
            v38 = v35->m_Components.p[6].m_pComponent;
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
        while ( v33 < v34 );
      }
      v12 = v71;
      v13 = v72;
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
  if ( (v44 >> 14) & 1 )
  {
    v22 = (UFG::HealthComponent *)v23->m_Components.p[6].m_pComponent;
    goto LABEL_103;
  }
  if ( (v44 & 0x8000u) != 0 )
  {
    v22 = (UFG::HealthComponent *)v23->m_Components.p[6].m_pComponent;
    goto LABEL_103;
  }
  if ( (v44 >> 13) & 1 )
  {
    v45 = (unsigned int)v23[1].vfptr;
    v46 = v23->m_Components.size;
    if ( v45 >= v46 )
      goto LABEL_103;
    v47 = (signed __int64)&v23->m_Components.p[v45];
    while ( (*(_DWORD *)(v47 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
         || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v47 + 8) & 0x1FFFFFF )
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
  if ( !((v44 >> 12) & 1) )
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
    v47 = (signed __int64)&v23->m_Components.p[v48];
    while ( (*(_DWORD *)(v47 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
         || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v47 + 8) & 0x1FFFFFF )
    {
      ++v48;
      v47 += 16i64;
      if ( v48 >= v49 )
        goto LABEL_103;
    }
    goto LABEL_93;
  }
LABEL_103:
  v50 = (unsigned int)UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(
                        (UFG::TargetingSystemPedBaseComponent *)&v70->vfptr,
                        *pPedTarget);
  *eFactionStanding = v50;
  if ( v71 && v50 != 2 || *bIsTargetVehicle && !v70->m_bHasRangedWeapon )
  {
LABEL_129:
    *v72 = 1;
    return;
  }
  v51 = *pPedTarget;
  if ( !*pPedTarget )
    goto LABEL_166;
  v53 = v51->m_Flags;
  if ( (v53 >> 14) & 1 )
  {
    v52 = (UFG::ActionTreeComponent *)v51->m_Components.p[7].m_pComponent;
    goto LABEL_124;
  }
  if ( (v53 & 0x8000u) != 0 )
  {
    v52 = (UFG::ActionTreeComponent *)v51->m_Components.p[7].m_pComponent;
    goto LABEL_124;
  }
  if ( (v53 >> 13) & 1 )
  {
    v52 = (UFG::ActionTreeComponent *)v51->m_Components.p[6].m_pComponent;
    goto LABEL_124;
  }
  if ( !((v53 >> 12) & 1) )
  {
    v52 = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(v51, UFG::ActionTreeComponent::_TypeUID);
    goto LABEL_124;
  }
  v54 = (unsigned int)v51[1].vfptr;
  v55 = v51->m_Components.size;
  if ( v54 < v55 )
  {
    v56 = (signed __int64)&v51->m_Components.p[v54];
    while ( (*(_DWORD *)(v56 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
         || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v56 + 8) & 0x1FFFFFF )
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
LABEL_166:
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
    if ( (v60 >> 14) & 1 )
    {
      v61 = (UFG::FaceActionComponent *)v59->m_Components.p[45].m_pComponent;
      goto LABEL_156;
    }
    if ( (v60 & 0x8000u) == 0 )
    {
      if ( (v60 >> 13) & 1 )
      {
        v65 = (unsigned int)v59[1].vfptr;
        v66 = v59->m_Components.size;
        if ( v65 < v66 )
        {
          v64 = (signed __int64)&v59->m_Components.p[v65];
          while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
               || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF )
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
        if ( !((v60 >> 12) & 1) )
        {
          v61 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(v59, UFG::FaceActionComponent::_TypeUID);
LABEL_156:
          if ( v61 )
          {
            if ( UFG::FaceActionComponent::IsFaceActionEnabled(v61) )
            {
              v69 = v61->m_pSimObject;
              if ( !v69 || !((v69->m_Flags >> 10) & 1) )
              {
                if ( v61->mFaceActionSetup )
                  goto LABEL_162;
              }
            }
          }
          goto LABEL_161;
        }
        v67 = (unsigned int)v59[1].vfptr;
        v68 = v59->m_Components.size;
        if ( v67 < v68 )
        {
          v64 = (signed __int64)&v59->m_Components.p[v67];
          while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
               || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF )
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
        v64 = (signed __int64)&v59->m_Components.p[v62];
        while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
             || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF )
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
}

// File Line: 4310
// RVA: 0x57BE10
bool __fastcall UFG::TargetingSystemPedPlayerComponent::useTargetRelativeMeleeCycling(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::SimComponent *v1; // rax
  bool result; // al

  result = 0;
  if ( UFG::TargetingSystemPedPlayerComponent::ms_bUseTargetRelativeMeleeCycling
    && !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v1 = this->m_pEquippedSOWPC.m_pPointer;
    if ( !v1
      || *(_DWORD *)(*((_QWORD *)&v1[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v1[2].m_pSimObject))
                   + 100i64) == UFG::gNullQSymbolUC.mUID )
    {
      result = 1;
    }
  }
  return result;
}

// File Line: 4322
// RVA: 0x56C3F0
float __fastcall UFG::TargetingSystemPedPlayerComponent::scoreFocusTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::qVector3 *vMyPosition, UFG::SimObject *pTargetSimObject, UFG::qMatrix44 *pTargetXform, const bool bUseCones, const bool bInitialAcquisition)
{
  UFG::qVector3 *v6; // rbx
  float v7; // xmm15_4
  UFG::qMatrix44 *v8; // rdi
  UFG::SimObject *v9; // r15
  UFG::TargetingSystemPedPlayerComponent *v10; // rsi
  UFG::TargetingProfile *v11; // r14
  UFG::eConeEnum v12; // er12
  float v13; // xmm9_4
  float v14; // xmm9_4
  float v15; // xmm10_4
  float v16; // xmm8_4
  float v17; // xmm14_4
  float v18; // xmm12_4
  signed int v19; // ebx
  __int64 v20; // rdi
  UFG::qVector3 *v21; // rax
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  UFG::qVector3 *v27; // rdx
  unsigned __int16 v28; // cx
  UFG::SimComponent *v29; // rax
  unsigned int v30; // er8
  unsigned int v31; // er9
  signed __int64 v32; // rdx
  UFG::SimObject *v33; // rcx
  float v34; // xmm8_4
  __m128 v35; // xmm9
  float v36; // xmm7_4
  UFG::BaseCameraComponent *v37; // rax
  float *v38; // rax
  float v39; // xmm8_4
  float v40; // xmm7_4
  __m128 v41; // xmm2
  float v42; // xmm6_4
  UFG::BaseCameraComponent *v43; // rax
  _DWORD *v44; // rax
  int v45; // xmm3_4
  int v46; // xmm1_4
  float v47; // xmm0_4
  __int64 v48; // rax
  float v49; // xmm0_4
  unsigned __int16 v50; // cx
  UFG::SimComponent *v51; // rax
  unsigned int v52; // er8
  unsigned int v53; // er9
  signed __int64 v54; // rdx
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
  float v69; // xmm0_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm6_4
  bool bIsScripted; // [rsp+70h] [rbp-90h]
  bool bIsDowned; // [rsp+71h] [rbp-8Fh]
  bool bIsKnockedOut; // [rsp+72h] [rbp-8Eh]
  bool bTargetVehicleHasOccupant; // [rsp+73h] [rbp-8Dh]
  bool bIsTargetVehicle; // [rsp+74h] [rbp-8Ch]
  bool bIsSocialActionAvailable; // [rsp+75h] [rbp-8Bh]
  bool bShouldRejectTarget; // [rsp+76h] [rbp-8Ah]
  UFG::qVector3 v2; // [rsp+78h] [rbp-88h]
  UFG::qVector3 n1; // [rsp+88h] [rbp-78h]
  UFG::eFactionStandingEnum eFactionStanding; // [rsp+98h] [rbp-68h]
  UFG::qVector3 v1; // [rsp+A0h] [rbp-60h]
  UFG::qVector3 vMeToTarget; // [rsp+B0h] [rbp-50h]

  v6 = vMyPosition;
  v7 = FLOAT_N1_0;
  v8 = pTargetXform;
  v9 = pTargetSimObject;
  v10 = this;
  if ( UFG::TargetingSystemPedPlayerComponent::isCommonInvalidTarget(this, pTargetSimObject) )
    return v7;
  v11 = v10->m_pActiveTargetingProfile;
  v12 = -1;
  v13 = v8->v3.x;
  vMeToTarget.z = v8->v3.z - v6->z;
  v14 = v13 - v6->x;
  v15 = v8->v3.y - v6->y;
  vMeToTarget.x = v14;
  vMeToTarget.y = v15;
  v16 = 0.0;
  v17 = 0.0;
  v18 = (float)((float)(v14 * v14) + (float)(v15 * v15)) + (float)(vMeToTarget.z * vMeToTarget.z);
  if ( bUseCones )
  {
    v19 = 0;
    v20 = 0i64;
    while ( 1 )
    {
      if ( v18 <= v11->m_ConeDistancesSquared[v20] )
      {
        v21 = v10->m_ConeToIntentionMap[v20];
        if ( v20 || (v22 = v11->m_fIdlePriorityConeTime, v22 <= 0.0) )
        {
          v24 = v11->m_HalfHorizontalFOVs[v20];
        }
        else
        {
          v23 = v10->m_fTargetingIntentionIdleTime / v22;
          if ( v23 > 1.0 )
            v23 = *(float *)&FLOAT_1_0;
          v24 = (float)((float)(1.0 - v23) * v11->m_HalfHorizontalFOVs[0])
              + (float)(v23 * v11->m_fHalfIdlePriorityConeHorizontalFOV);
        }
        v25 = v21->x;
        v26 = v21->y;
        v1.z = 0.0;
        v2.z = 0.0;
        v2.x = v25;
        v2.y = v26;
        v1.x = v14;
        v1.y = v15;
        if ( v19 == 4 )
        {
          n1.z = -0.0;
          v27 = &n1;
          LODWORD(n1.x) = LODWORD(v25) ^ _xmm[0];
          LODWORD(n1.y) = LODWORD(v26) ^ _xmm[0];
        }
        else
        {
          v27 = &v2;
        }
        v16 = UFG::qAngleBetween(&v1, v27);
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
      v17 = v11->m_ConeDistancesSquared[v19];
    goto LABEL_95;
  }
  if ( v10->m_eFocusMode == 2 )
  {
    if ( !v9 )
      goto LABEL_104;
    v28 = v9->m_Flags;
    if ( (v28 >> 14) & 1 )
    {
      v29 = v9->m_Components.p[14].m_pComponent;
    }
    else if ( (v28 & 0x8000u) == 0 )
    {
      if ( (v28 >> 13) & 1 )
      {
        v29 = v9->m_Components.p[9].m_pComponent;
      }
      else if ( (v28 >> 12) & 1 )
      {
        v30 = (unsigned int)v9[1].vfptr;
        v31 = v9->m_Components.size;
        if ( v30 >= v31 )
        {
LABEL_33:
          v29 = 0i64;
        }
        else
        {
          v32 = (signed __int64)&v9->m_Components.p[v30];
          while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
               || UFG::CompositeDrawableComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF )
          {
            ++v30;
            v32 += 16i64;
            if ( v30 >= v31 )
              goto LABEL_33;
          }
          v29 = *(UFG::SimComponent **)v32;
        }
      }
      else
      {
        v29 = UFG::SimObject::GetComponentOfType(v9, UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      v29 = v9->m_Components.p[14].m_pComponent;
    }
    if ( v29 )
      v33 = v29[19].m_pSimObject;
    else
LABEL_104:
      v33 = 0i64;
    if ( v33 && LOBYTE(v33->vfptr) > 1u )
      goto LABEL_95;
    v17 = UFG::TargetingSystemPedBaseComponent::getTargetAcquisitionDistanceSquared((UFG::TargetingSystemPedBaseComponent *)&v10->vfptr);
    if ( v18 > v17 )
      goto LABEL_95;
    v34 = v8->v3.x;
    v35 = (__m128)LODWORD(v8->v3.y);
    v36 = v8->v3.z + 1.0;
    v37 = UFG::Director::Get()->mCurrentCamera;
    if ( v37 )
      v38 = &v37->mCamera.mFOVOffset;
    else
      v38 = 0i64;
    v39 = v34 - v38[44];
    v35.m128_f32[0] = v35.m128_f32[0] - v38[45];
    v40 = v36 - v38[46];
    v41 = v35;
    v41.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(v39 * v39)) + (float)(v40 * v40);
    if ( v41.m128_f32[0] == 0.0 )
      v42 = 0.0;
    else
      v42 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v41));
    v2.x = v39 * v42;
    v2.y = v35.m128_f32[0] * v42;
    v2.z = v40 * v42;
    v43 = UFG::Director::Get()->mCurrentCamera;
    if ( v43 )
      v44 = (_DWORD *)&v43->mCamera.mFOVOffset;
    else
      v44 = 0i64;
    v45 = v44[42] ^ _xmm[0];
    v46 = v44[41] ^ _xmm[0];
    LODWORD(n1.x) = v44[40] ^ _xmm[0];
    v47 = n1.x;
    LODWORD(n1.y) = v46;
    LODWORD(n1.z) = v45;
    UFG::qAngleBetweenNormals(&n1, &v2);
    v16 = v47;
    if ( bInitialAcquisition )
    {
      if ( v10->m_pActionTreeComponent.m_pSimComponent
        && (v48 = *((_QWORD *)&v10->m_pActionTreeComponent.m_pSimComponent[11].m_SafePointerList.mNode.mPrev
                  + ((signed __int64)(signed int)gActionRequest_UseCover.m_EnumValue >> 6)),
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
    if ( !v10->m_pOccupantOfVehicle.m_pPointer )
    {
      v70 = v10->m_vTargetingForward.x;
      v71 = v10->m_vTargetingForward.y;
      v72 = v11->m_fMaximumHalfHorizontalFOVWithLimiter;
      n1.z = 0.0;
      v2.z = 0.0;
      v2.x = v70;
      v2.y = v71;
      n1.x = v14;
      n1.y = v15;
      v16 = UFG::qAngleBetween(&n1, &v2);
      if ( v16 <= v72 )
      {
        v17 = UFG::TargetingSystemPedBaseComponent::getTargetAcquisitionDistanceSquared((UFG::TargetingSystemPedBaseComponent *)&v10->vfptr);
        if ( v17 >= v18 )
          v12 = 0;
      }
      goto LABEL_95;
    }
    if ( !v9 )
      goto LABEL_105;
    v50 = v9->m_Flags;
    if ( (v50 >> 14) & 1 )
    {
      v51 = v9->m_Components.p[14].m_pComponent;
    }
    else if ( (v50 & 0x8000u) == 0 )
    {
      if ( (v50 >> 13) & 1 )
      {
        v51 = v9->m_Components.p[9].m_pComponent;
      }
      else if ( (v50 >> 12) & 1 )
      {
        v52 = (unsigned int)v9[1].vfptr;
        v53 = v9->m_Components.size;
        if ( v52 >= v53 )
        {
LABEL_72:
          v51 = 0i64;
        }
        else
        {
          v54 = (signed __int64)&v9->m_Components.p[v52];
          while ( (*(_DWORD *)(v54 + 8) & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
               || UFG::CompositeDrawableComponent::_TypeUID & ~*(_DWORD *)(v54 + 8) & 0x1FFFFFF )
          {
            ++v52;
            v54 += 16i64;
            if ( v52 >= v53 )
              goto LABEL_72;
          }
          v51 = *(UFG::SimComponent **)v54;
        }
      }
      else
      {
        v51 = UFG::SimObject::GetComponentOfType(v9, UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      v51 = v9->m_Components.p[14].m_pComponent;
    }
    if ( v51 )
      v55 = v51[19].m_pSimObject;
    else
LABEL_105:
      v55 = 0i64;
    if ( v55 && LOBYTE(v55->vfptr) > 1u )
      goto LABEL_95;
    v17 = UFG::TargetingSystemPedBaseComponent::getTargetAcquisitionDistanceSquared((UFG::TargetingSystemPedBaseComponent *)&v10->vfptr);
    if ( v18 > v17 )
      goto LABEL_95;
    v56 = v8->v3.x;
    v57 = (__m128)LODWORD(v8->v3.y);
    v58 = v8->v3.z + 1.0;
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
      v64 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v63));
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
    v69 = n1.x;
    LODWORD(n1.y) = v68;
    LODWORD(n1.z) = v67;
    UFG::qAngleBetweenNormals(&n1, &v2);
    v16 = v69;
  }
  v12 = 0;
LABEL_95:
  bIsDowned = 0;
  bIsScripted = 0;
  bIsKnockedOut = 0;
  eFactionStanding = 1;
  if ( (signed int)v12 >= 0
    && UFG::TargetingSystemPedBaseComponent::IsWithinVerticalFOV(
         (UFG::TargetingSystemPedBaseComponent *)&v10->vfptr,
         &vMeToTarget,
         v11->m_fHalfVerticalFOV,
         v11->m_fExtraPositivePitch,
         v11->m_fExtraNegativePitch) )
  {
    UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(
      v10,
      v9,
      v10->m_bIsInAnyCombat,
      &bShouldRejectTarget,
      (UFG::SimObject **)&v1,
      &bIsTargetVehicle,
      &bTargetVehicleHasOccupant,
      &eFactionStanding,
      &bIsDowned,
      &bIsScripted,
      &bIsKnockedOut,
      &bIsSocialActionAvailable);
    if ( !bShouldRejectTarget && ((float)v11->m_bConsiderDownedTargets != 0.0 || !bIsDowned) )
      v7 = UFG::TargetingSystemPedPlayerComponent::calculateScore(
             v10,
             v12,
             v18,
             v17,
             v16,
             v9 == v10->m_pTargets[(unsigned __int8)v10->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer,
             bIsDowned,
             bIsKnockedOut,
             eFactionStanding,
             bIsScripted,
             v10->m_pOccupantOfVehicle.m_pPointer != 0i64,
             bIsTargetVehicle,
             bTargetVehicleHasOccupant,
             bIsSocialActionAvailable);
  }
  return v7;
}
             v9 == v10->m_pTargets[(unsigned __int8)v10->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer,
             bIsDo

// File Line: 4577
// RVA: 0x56C120
float __fastcall UFG::TargetingSystemPedPlayerComponent::scoreDirectionalTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::qVector3 *vMyPosition, UFG::SimObject *pTargetSimObject, UFG::qMatrix44 *pTargetXform)
{
  UFG::qVector3 *v4; // r15
  float v5; // xmm7_4
  UFG::qMatrix44 *v6; // rdi
  UFG::SimObject *v7; // rsi
  UFG::TargetingSystemPedPlayerComponent *v8; // rbx
  UFG::TargetingSimObject *v9; // rax
  signed __int64 v10; // rcx
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  UFG::TargetingProfile *v14; // r14
  UFG::eConeEnum v15; // edi
  float v16; // xmm9_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm8_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm6_4
  bool bIsTargetVehicle[8]; // [rsp+58h] [rbp-39h]
  UFG::eFactionStandingEnum eFactionStanding; // [rsp+60h] [rbp-31h]
  UFG::qVector3 v2; // [rsp+68h] [rbp-29h]
  UFG::qVector3 v1; // [rsp+78h] [rbp-19h]
  UFG::qVector3 vMeToTarget; // [rsp+88h] [rbp-9h]

  v4 = vMyPosition;
  v5 = FLOAT_N1_0;
  v6 = pTargetXform;
  v7 = pTargetSimObject;
  v8 = this;
  if ( !UFG::TargetingSystemPedPlayerComponent::isCommonInvalidTarget(this, pTargetSimObject) )
  {
    v9 = v8->m_pTargets;
    v10 = (unsigned __int8)v8->m_pTargetingMap->m_Map.p[22];
    if ( v9[v10].m_pTarget.m_pPointer != v7 || !v9[v10].m_pTarget.m_pPointer || !v9[v10].m_bLock )
    {
      v11 = v6->v3.x;
      v12 = v6->v3.y;
      v13 = v6->v3.z;
      v14 = v8->m_pActiveTargetingProfile;
      v15 = -1;
      v16 = 0.0;
      v17 = v11 - v4->x;
      v18 = v12 - v4->y;
      vMeToTarget.z = v13 - v4->z;
      vMeToTarget.x = v17;
      v19 = (float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(vMeToTarget.z * vMeToTarget.z);
      vMeToTarget.y = v18;
      if ( v19 <= v14->m_ConeDistancesSquared[5] )
      {
        v20 = v8->m_vDirectionalTargetingIntention.x;
        v21 = v8->m_vDirectionalTargetingIntention.y;
        v1.z = 0.0;
        v2.z = 0.0;
        v22 = v14->m_HalfHorizontalFOVs[5];
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
      eFactionStanding = 1;
      if ( (signed int)v15 >= 0
        && UFG::TargetingSystemPedBaseComponent::IsWithinVerticalFOV(
             (UFG::TargetingSystemPedBaseComponent *)&v8->vfptr,
             &vMeToTarget,
             v14->m_fHalfVerticalFOV,
             v14->m_fExtraPositivePitch,
             v14->m_fExtraNegativePitch) )
      {
        UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(
          v8,
          v7,
          v8->m_bIsInAnyCombat,
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
          v5 = UFG::TargetingSystemPedPlayerComponent::calculateScore(
                 v8,
                 v15,
                 v19,
                 v14->m_ConeDistancesSquared[v15],
                 v16,
                 v7 == v8->m_pTargets[(unsigned __int8)v8->m_pTargetingMap->m_Map.p[48]].m_pTarget.m_pPointer,
                 0,
                 bIsTargetVehicle[2],
                 eFactionStanding,
                 bIsTargetVehicle[6],
                 v8->m_pOccupantOfVehicle.m_pPointer != 0i64,
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
float __fastcall UFG::TargetingSystemPedPlayerComponent::scoreSoftLockTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::qVector3 *vMyPosition, UFG::SimObject *pTargetSimObject, UFG::qMatrix44 *pTargetXform, UFG::SimObject *pMyOccupiedVehicle)
{
  UFG::TargetingSystemPedPlayerComponent *v5; // rbx
  UFG::qVector3 *v6; // r14
  UFG::qMatrix44 *v7; // rdi
  UFG::SimObject *v8; // rsi
  float result; // xmm0_4
  UFG::TargetingSimObject *v10; // rax
  signed __int64 v11; // rcx
  UFG::SimObject *v12; // rdx
  UFG::SimComponent *v13; // rax
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm9_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  signed __int64 v19; // rdi
  UFG::BaseCameraComponent *v20; // rax
  _DWORD *v21; // rax
  UFG::BaseCameraComponent *v22; // rax
  _DWORD *v23; // rax
  int v24; // xmm2_4
  int v25; // xmm1_4
  UFG::BaseCameraComponent *v26; // rcx
  float v27; // xmm6_4
  float v28; // xmm7_4
  __int64 v29; // r8
  UFG::SubTargetingProfile *v30; // rax
  float v31; // xmm0_4
  bool v32; // r8
  bool bShouldRejectTarget; // [rsp+60h] [rbp-51h]
  bool bIsTargetVehicle; // [rsp+61h] [rbp-50h]
  bool bIsDowned; // [rsp+62h] [rbp-4Fh]
  bool bIsKnockedOut; // [rsp+63h] [rbp-4Eh]
  bool bTargetVehicleHasOccupant; // [rsp+64h] [rbp-4Dh]
  bool bIsScripted; // [rsp+65h] [rbp-4Ch]
  bool bIsSocialActionAvailable; // [rsp+66h] [rbp-4Bh]
  UFG::eFactionStandingEnum fRadius; // [rsp+68h] [rbp-49h]
  UFG::qMatrix44 *pXform; // [rsp+70h] [rbp-41h]
  int v42; // [rsp+78h] [rbp-39h]
  UFG::qVector3 ray_pos_p; // [rsp+80h] [rbp-31h]
  UFG::qVector3 seg_pos_p; // [rsp+90h] [rbp-21h]
  UFG::qVector3 vSegB; // [rsp+A0h] [rbp-11h]
  UFG::qVector3 vSegA; // [rsp+B0h] [rbp-1h]

  v5 = this;
  v6 = vMyPosition;
  v7 = pTargetXform;
  v8 = pTargetSimObject;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  if ( UFG::TargetingSystemPedPlayerComponent::isCommonInvalidTarget(v5, v8) )
    return FLOAT_N1_0;
  v10 = v5->m_pTargets;
  v11 = (unsigned __int8)v5->m_pTargetingMap->m_Map.p[17];
  if ( v10[v11].m_pTarget.m_pPointer )
  {
    if ( v10[v11].m_bLock )
    {
      v12 = v10[v11].m_pTarget.m_pPointer;
      if ( v12 )
      {
        if ( v8 == v12 )
          return FLOAT_N1_0;
      }
    }
  }
  v13 = v5->m_pEquippedSOWPC.m_pPointer;
  v14 = v7->v3.x - v6->x;
  v15 = v7->v3.y - v6->y;
  v16 = v7->v3.z - v6->z;
  if ( v13 )
  {
    v17 = *(float *)(*((_QWORD *)&v13[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v13[2].m_pSimObject))
                   + 40i64);
    v18 = v17 * v17;
  }
  else
  {
    v18 = v5->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
  }
  if ( (float)((float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v16 * v16)) > v18 )
    return FLOAT_N1_0;
  v19 = 0i64;
  v20 = UFG::Director::Get()->mCurrentCamera;
  if ( v20 )
    v21 = (_DWORD *)&v20->mCamera.mFOVOffset;
  else
    v21 = 0i64;
  if ( (float)((float)((float)(COERCE_FLOAT(v21[41] ^ _xmm[0]) * v15) + (float)(COERCE_FLOAT(v21[40] ^ _xmm[0]) * v14))
             + (float)(COERCE_FLOAT(v21[42] ^ _xmm[0]) * v16)) <= 0.0 )
    goto LABEL_35;
  pXform = 0i64;
  UFG::SimObjectUtility::GetObjectCapsuleApproximation(v8, &pXform, &vSegA, &vSegB, (float *)&fRadius);
  v22 = UFG::Director::Get()->mCurrentCamera;
  if ( v22 )
    v23 = (_DWORD *)&v22->mCamera.mFOVOffset;
  else
    v23 = 0i64;
  v24 = v23[42] ^ _xmm[0];
  v25 = v23[41] ^ _xmm[0];
  LODWORD(pXform) = v23[40] ^ _xmm[0];
  HIDWORD(pXform) = v25;
  v42 = v24;
  v26 = UFG::Director::Get()->mCurrentCamera;
  if ( v26 )
    v19 = (signed __int64)&v26->mCamera;
  UFG::qNearestRaySeg((UFG::qVector3 *)(v19 + 176), (UFG::qVector3 *)&pXform, &vSegA, &vSegB, &ray_pos_p, &seg_pos_p);
  v27 = *(float *)&fRadius;
  v28 = (float)((float)((float)(seg_pos_p.y - ray_pos_p.y) * (float)(seg_pos_p.y - ray_pos_p.y))
              + (float)((float)(seg_pos_p.x - ray_pos_p.x) * (float)(seg_pos_p.x - ray_pos_p.x)))
      + (float)((float)(seg_pos_p.z - ray_pos_p.z) * (float)(seg_pos_p.z - ray_pos_p.z));
  v30 = UFG::TargetingSystemPedBaseComponent::GetSubTargetingProfileForTarget(
          (UFG::TargetingSystemPedBaseComponent *)&v5->vfptr,
          v8,
          v29);
  if ( v30 )
  {
    v31 = v30->m_fSoftLockExtraCapsuleRadius;
    if ( pMyOccupiedVehicle )
      v31 = v31 * UFG::TargetingSystemPedPlayerComponent::ms_fInVehicleCapsuleInflationFactor;
    v27 = v31 + v27;
  }
  if ( v28 > (float)(v27 * v27)
    || ((unsigned int)(v5->m_eFocusMode - 1) <= 1 || v5->m_bTargetAutoAcquisitionJustRequested ? (v32 = 1) : (v32 = 0),
        UFG::TargetingSystemPedPlayerComponent::getPedTargetInfo(
          v5,
          v8,
          v32,
          &bShouldRejectTarget,
          (UFG::SimObject **)&pXform,
          &bIsTargetVehicle,
          &bTargetVehicleHasOccupant,
          &fRadius,
          &bIsDowned,
          &bIsScripted,
          &bIsKnockedOut,
          &bIsSocialActionAvailable),
        bShouldRejectTarget) )
  {
LABEL_35:
    result = FLOAT_N1_0;
  }
  else
  {
    result = v28;
  }
  return result;
}

// File Line: 4926
// RVA: 0x57A120
void __fastcall UFG::TargetingSystemPedPlayerComponent::updateTargets(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingSystemPedPlayerComponent *v1; // rbx
  UFG::SimComponent *v2; // rax
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm3_4
  UFG::SimComponent *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  UFG::TargetingMap *v10; // rdx
  UFG::TargetingSimObject *v11; // r9
  UFG::TargetingSimObject *v12; // rcx
  unsigned __int8 v13; // cl
  signed __int64 v14; // r8
  UFG::TargetingSimObject *v15; // rdx
  UFG::TargetingSimObject *v16; // rcx
  signed __int64 v17; // rdi
  UFG::TargetingSimObject *v18; // rax
  UFG::qFixedArray<UFG::ClosePhysicalTarget,1> closePhysicalMeleeAttackableList; // [rsp+40h] [rbp-C0h]
  __int64 v20; // [rsp+58h] [rbp-A8h]
  UFG::qFixedArray<UFG::CloseTarget *,5> closePropsList; // [rsp+60h] [rbp-A0h]
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePickupsList; // [rsp+90h] [rbp-70h]
  UFG::qFixedArray<UFG::ClosePhysicalTarget,2> closePhysicalDodgeableList; // [rsp+C0h] [rbp-40h]
  UFG::qFixedArray<UFG::CloseTarget *,20> closeVehiclesList; // [rsp+F0h] [rbp-10h]
  UFG::qFixedArray<UFG::ClosePhysicalTarget,10> filteredClosePhysicalTargetsList; // [rsp+1A0h] [rbp+A0h]
  UFG::qFixedArray<UFG::CloseTarget *,80> filteredClosePedsList; // [rsp+250h] [rbp+150h]
  UFG::qFixedArray<UFG::CloseTarget,100> closeTargetsList; // [rsp+4E0h] [rbp+3E0h]

  v20 = -2i64;
  v1 = this;
  filteredClosePedsList.size = 0;
  closeTargetsList.size = 0;
  filteredClosePickupsList.size = 0;
  closePropsList.size = 0;
  closeVehiclesList.size = 0;
  filteredClosePhysicalTargetsList.size = 0;
  closePhysicalDodgeableList.size = 0;
  closePhysicalMeleeAttackableList.size = 0;
  if ( ((unsigned __int8 (*)(void))this->vfptr[22].__vecDelDtor)() )
  {
    v2 = v1->m_pEquippedSOWPC.m_pPointer;
    if ( v2 )
    {
      v3 = *(float *)(*((_QWORD *)&v2[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v2[2].m_pSimObject))
                    + 40i64);
      v4 = v3 * v3;
    }
    else
    {
      v4 = v1->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
    }
    v5 = v1->m_fMinimumTargetDistanceSquared;
    if ( v5 <= v4 )
      v5 = v4;
    UFG::TargetingSystemPedBaseComponent::findCloseTargets(
      &v1->m_CloseTargetsList,
      v1->m_pSimObject,
      &v1->m_vTargetingPosition,
      v5);
  }
  UFG::TargetingSystemPedBaseComponent::filterCloseTargets(
    &v1->m_CloseTargetsList,
    &v1->m_CachedPedsList,
    &filteredClosePedsList,
    &filteredClosePickupsList,
    &closePropsList,
    &closeVehiclesList,
    &closeTargetsList);
  v6 = v1->m_pEquippedSOWPC.m_pPointer;
  if ( v6 )
  {
    v7 = *(float *)(*((_QWORD *)&v6[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v6[2].m_pSimObject)) + 40i64);
    v8 = v7 * v7;
  }
  else
  {
    v8 = v1->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
  }
  v9 = v1->m_fMinimumTargetDistanceSquared;
  if ( v9 <= v8 )
    v9 = v8;
  UFG::TargetingSystemPedBaseComponent::findClosePhysicalTargets(
    (UFG::TargetingSystemPedBaseComponent *)&v1->vfptr,
    &v1->m_ClosePhysicalTargetsList,
    v1->m_pSimObject,
    v9);
  UFG::TargetingSystemPedBaseComponent::filterClosePhysicalTargets(
    (UFG::TargetingSystemPedBaseComponent *)&v1->vfptr,
    &v1->m_ClosePhysicalTargetsList,
    &closePhysicalDodgeableList,
    &closePhysicalMeleeAttackableList,
    &filteredClosePhysicalTargetsList);
  UFG::TargetingSystemPedPlayerComponent::updateAttackingTarget(v1);
  UFG::TargetingSystemPedPlayerComponent::updateFocusTarget(
    v1,
    &filteredClosePedsList,
    &filteredClosePickupsList,
    &closePropsList,
    &closeVehiclesList,
    &closeTargetsList);
  UFG::TargetingSystemPedBaseComponent::updateClosestPedTarget(
    (UFG::TargetingSystemPedBaseComponent *)&v1->vfptr,
    &filteredClosePedsList);
  v10 = v1->m_pTargetingMap;
  v11 = v1->m_pTargets;
  v12 = &v11[(unsigned __int8)v10->m_Map.p[21]];
  if ( (!v12->m_pTarget.m_pPointer || !v12->m_bLock) && v10->m_Map.p[21] )
    UFG::TargetingSimObject::SetTarget(v12, v11[(unsigned __int8)v10->m_Map.p[22]].m_pTarget.m_pPointer);
  v13 = v1->m_pTargetingMap->m_Map.p[eTARGET_TYPE_WORLD_EDITOR_SELECTED_OBJECT];
  if ( v13 )
    UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v13], 0i64);
  v14 = (unsigned __int8)v1->m_pTargetingMap->m_Map.p[eTARGET_TYPE_INTERACTIVE_PROP];
  v15 = v1->m_pTargets;
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
      v18 = v1->m_pTargets;
      if ( v18[v17].m_bLock )
        v18[v17].m_bLock = 0;
    }
  }
  UFG::TargetingSystemPedBaseComponent::updatePickupTarget(
    (UFG::TargetingSystemPedBaseComponent *)&v1->vfptr,
    &filteredClosePickupsList);
  UFG::TargetingSystemPedBaseComponent::updateVehicleTarget(
    (UFG::TargetingSystemPedBaseComponent *)&v1->vfptr,
    &closeVehiclesList);
  UFG::TargetingSystemPedPlayerComponent::updateActionHijackTarget(v1, &closeVehiclesList, v8);
  UFG::TargetingSystemPedPlayerComponent::updateClosestDownedPedTarget(v1, &filteredClosePedsList);
  UFG::TargetingSystemPedPlayerComponent::updateDirectionalTarget(v1, &closeTargetsList);
  UFG::TargetingSystemPedBaseComponent::updatePhysicalTarget(
    (UFG::TargetingSystemPedBaseComponent *)&v1->vfptr,
    &filteredClosePhysicalTargetsList);
  UFG::TargetingSystemPedPlayerComponent::updateSocialTarget(v1, &filteredClosePedsList);
  UFG::TargetingSystemPedPlayerComponent::updateCrowdPushTargets(
    v1,
    &filteredClosePedsList,
    &closePhysicalDodgeableList);
  UFG::TargetingSystemPedPlayerComponent::updateTransitTarget(v1, &closeVehiclesList);
  UFG::TargetingSystemPedPlayerComponent::updateVehicleClosestPointTarget(v1);
}

// File Line: 4985
// RVA: 0x56D650
bool __fastcall UFG::TargetingSystemPedPlayerComponent::shouldUpdateThisFrame(UFG::TargetingSystemPedPlayerComponent *this)
{
  return UFG::Metrics::msInstance.mSimFrameCount & 1;
}

// File Line: 4995
// RVA: 0x549D70
void __fastcall UFG::TargetingSystemPedPlayerComponent::Reset(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::TargetingSystemPedPlayerComponent *v1; // rbx
  unsigned int *v2; // rcx

  v1 = this;
  UFG::TargetingSystemBaseComponent::shutdown((UFG::TargetingSystemBaseComponent *)&this->vfptr);
  UFG::TargetingSystemBaseComponent::initialize((UFG::TargetingSystemBaseComponent *)&v1->vfptr);
  v2 = v1->m_pBucketList;
  v1->m_CachedPedsList.size = 0;
  if ( v2 )
  {
    --v2[v1->m_uUpdateBucket];
    v1->m_pBucketList = 0i64;
  }
  UFG::TargetingSystemPedBaseComponent::initialize((UFG::TargetingSystemPedBaseComponent *)&v1->vfptr);
  UFG::TargetingSystemPedPlayerComponent::shutdown(v1);
  UFG::TargetingSystemPedPlayerComponent::initialize(v1);
}

// File Line: 5005
// RVA: 0x54D110
void __fastcall UFG::TargetingSystemPedPlayerComponent::SetFocusModeOverrideSimObject(UFG::TargetingSystemPedPlayerComponent *this, UFG::SimObject *pSimObject, UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *a3)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // r9
  UFG::TargetingSystemPedPlayerComponent *v4; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  unsigned __int8 v7; // cl
  int v8; // ST20_4

  v3 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pFocusModeOverrideSimObject.mPrev;
  v4 = this;
  if ( this->m_pFocusModeOverrideSimObject.m_pPointer )
  {
    a3 = v3->mPrev;
    v5 = this->m_pFocusModeOverrideSimObject.mNext;
    a3->mNext = v5;
    v5->mPrev = a3;
    v3->mPrev = v3;
    this->m_pFocusModeOverrideSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pFocusModeOverrideSimObject.mPrev;
  }
  this->m_pFocusModeOverrideSimObject.m_pPointer = pSimObject;
  if ( pSimObject )
  {
    v6 = pSimObject->m_SafePointerList.mNode.mPrev;
    v6->mNext = v3;
    v3->mPrev = v6;
    this->m_pFocusModeOverrideSimObject.mNext = &pSimObject->m_SafePointerList.mNode;
    pSimObject->m_SafePointerList.mNode.mPrev = v3;
  }
  v7 = this->m_pTargetingMap->m_Map.p[22];
  if ( v7 )
    UFG::TargetingSimObject::SetTarget(&v4->m_pTargets[v7], pSimObject);
  v8 = 0;
  LOBYTE(a3) = 1;
  ((void (__fastcall *)(UFG::TargetingSystemPedPlayerComponent *, signed __int64, UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *, _QWORD, int, _QWORD, _QWORD, _QWORD))v4->vfptr[14].__vecDelDtor)(
    v4,
    22i64,
    a3,
    0i64,
    v8,
    0i64,
    0i64,
    0i64);
}

// File Line: 5014
// RVA: 0x522D80
void __fastcall UFG::TargetingSystemPedPlayerComponent::ClearFocusModeOverrideSimObject(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rax

  v1 = &this->m_pFocusModeOverrideSimObject;
  if ( this->m_pFocusModeOverrideSimObject.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = v1->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  }
  v1->m_pPointer = 0i64;
}

// File Line: 5021
// RVA: 0x526DE0
void __fastcall UFG::TargetingSystemPedPlayerComponent::EnableRimLighting(UFG::TargetingSystemPedPlayerComponent *this, UFG::eTargetTypeEnum eTargetType)
{
  UFG::TargetingMap *v2; // rax
  __int64 v3; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rdx
  UFG::SimObject *v5; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax

  if ( !this->m_RimLighting.m_bEnabled )
  {
    v2 = this->m_pTargetingMap;
    this->m_RimLighting.m_TargetType = eTargetType;
    this->m_RimLighting.m_bEnabled = 1;
    v3 = (unsigned __int8)v2->m_Map.p[eTargetType];
    v4 = &this->m_RimLighting.m_Target;
    v5 = this->m_pTargets[v3].m_pTarget.m_pPointer;
    if ( this->m_RimLighting.m_Target.m_pPointer )
    {
      v6 = v4->mPrev;
      v7 = v4->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    }
    v4->m_pPointer = v5;
    if ( v5 )
    {
      v8 = v5->m_SafePointerList.mNode.mPrev;
      v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      v4->mPrev = v8;
      v4->mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    }
  }
}

// File Line: 5053
// RVA: 0x548F10
void __fastcall UFG::TargetingSystemPedPlayerComponent::RemoveCloseTarget(UFG::TargetingSystemPedPlayerComponent *this, UFG::SimObjectPropertiesComponent *pSOPC)
{
  UFG::TargetingSystemPedPlayerComponent *v2; // r9
  unsigned int v3; // ecx
  unsigned int v4; // eax
  UFG::SimObjectPropertiesComponent **v5; // r8
  __int64 v6; // r10
  signed __int64 v7; // rax
  signed __int64 v8; // rdx
  signed __int64 v9; // r8
  UFG::qVector4 v10; // xmm3
  UFG::qVector4 v11; // xmm2
  UFG::qVector4 v12; // xmm1

  v2 = this;
  v3 = this->m_CloseTargetsList.size;
  v4 = 0;
  if ( v3 )
  {
    v5 = &v2->m_CloseTargetsList.p[0].m_pSimObjectPropertiesComponent;
    while ( *v5 != pSOPC )
    {
      ++v4;
      v5 += 10;
      if ( v4 >= v3 )
        return;
    }
    v6 = v4 + 1;
    if ( (unsigned int)v6 < v3 )
    {
      do
      {
        v7 = (unsigned int)(v6 - 1);
        v8 = 5 * v6;
        v6 = (unsigned int)(v6 + 1);
        v8 *= 2i64;
        v9 = v7;
        v2->m_CloseTargetsList.p[v9].m_fDistance2 = *(&v2->m_CloseTargetsList.p[0].m_fDistance2 + 2 * v8);
        v2->m_CloseTargetsList.p[v9].m_pSimObjectPropertiesComponent = (UFG::SimObjectPropertiesComponent *)*((_QWORD *)&v2->m_CloseTargetsList.p[0].m_pSimObjectPropertiesComponent + v8);
        v10 = *(UFG::qVector4 *)((char *)&v2->m_CloseTargetsList.p[0].m_Xform.v1 + 8 * v8);
        v11 = *(UFG::qVector4 *)((char *)&v2->m_CloseTargetsList.p[0].m_Xform.v2 + 8 * v8);
        v12 = *(UFG::qVector4 *)((char *)&v2->m_CloseTargetsList.p[0].m_Xform.v3 + 8 * v8);
        v2->m_CloseTargetsList.p[v9].m_Xform.v0 = *(UFG::qVector4 *)((char *)&v2->m_CloseTargetsList.p[0].m_Xform.v0
                                                                   + 8 * v8);
        v2->m_CloseTargetsList.p[v9].m_Xform.v1 = v10;
        v2->m_CloseTargetsList.p[v9].m_Xform.v2 = v11;
        v2->m_CloseTargetsList.p[v9].m_Xform.v3 = v12;
      }
      while ( (unsigned int)v6 < v2->m_CloseTargetsList.size );
    }
    --v2->m_CloseTargetsList.size;
  }
}

// File Line: 5070
// RVA: 0x55CE80
void __fastcall UFG::TargetingSystemPedPlayerComponent::Update(UFG::TargetingSystemPedPlayerComponent *this, float fDeltaS)
{
  UFG::TargetingSystemPedPlayerComponent *v2; // rdi
  UFG::AttackRightsComponent *v3; // rcx
  UFG::HasAttackRequestNode *v4; // rax
  UFG::SimObject *v5; // rdx
  unsigned __int8 v6; // cl
  unsigned int v7; // eax
  bool v8; // cf
  bool v9; // zf
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax
  __int64 v11; // rbx

  v2 = this;
  UFG::TargetingSystemPedPlayerComponent::UpdateCommon(
    (UFG::TargetingSystemPedPlayerComponent *)((char *)this - 64),
    UFG::Metrics::msInstance.mSimTimeUnscaledDelta);
  UFG::TargetingSystemPedPlayerComponent::updateDesiredFocusMode((UFG::TargetingSystemPedPlayerComponent *)((char *)v2 - 64));
  UFG::TargetingSystemPedPlayerComponent::updateTargetingIntentions((UFG::TargetingSystemPedPlayerComponent *)((char *)v2 - 64));
  UFG::TargetingSystemPedPlayerComponent::updateTargets((UFG::TargetingSystemPedPlayerComponent *)((char *)v2 - 64));
  UFG::TargetingSystemPedPlayerComponent::updateRagdoll((UFG::TargetingSystemPedPlayerComponent *)((char *)v2 - 64));
  UFG::TargetingSystemPedPlayerComponent::updateRimLighting((UFG::TargetingSystemPedPlayerComponent *)((char *)v2 - 64));
  UFG::TargetingSystemPedPlayerComponent::updateVehicleProjectileTargets((UFG::TargetingSystemPedPlayerComponent *)((char *)v2 - 64));
  UFG::TargetingSystemPedPlayerComponent::updateFocusTargetSubTargetingLocation((UFG::TargetingSystemPedPlayerComponent *)((char *)v2 - 64));
  v3 = (UFG::AttackRightsComponent *)v2->m_pAimingPlayerComponent.mNext;
  if ( v3 )
  {
    v4 = UFG::AttackRightsComponent::GetCurrentAttacker(v3, 0);
    v5 = v4 ? UFG::HasAttackRequestNode::GetSimObject(v4) : 0i64;
    v6 = *(_BYTE *)(*(_QWORD *)&v2->m_Flags + 85i64);
    if ( v6 )
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(*(_QWORD *)&v2->m_TypeUID + 56i64 * v6), v5);
  }
  v7 = LODWORD(v2->m_VehicleCharacterRagdolls[9].m_pPointer) - 1;
  v8 = v7 < 3;
  v9 = v7 == 3;
  v10 = v2->m_pCharacterAnimationComponent.mNext;
  LOBYTE(v10[53].mPrev) &= 0xFEu;
  LOBYTE(v10[53].mPrev) |= v8 || v9;
  v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v2->m_Flags + 30i64) + *(_QWORD *)&v2->m_TypeUID + 40);
  if ( v11 != *(_QWORD *)&v2->m_vTargetingPosition.z )
  {
    ((void (*)(void))v2->m_pCharacterAnimationComponent.mNext->mPrev[11].mPrev)();
    *(_QWORD *)&v2->m_vTargetingPosition.z = v11;
  }
  LOBYTE(v2->m_pInterestPointUserComponent.m_Changed) = 0;
}

// File Line: 5113
// RVA: 0x53F000
void __fastcall UFG::TargetingSystemPedPlayerComponent::OnAttach(UFG::TargetingSystemPedPlayerComponent *this, UFG::SimObject *pSimObject)
{
  UFG::SimObject *v2; // rdi
  UFG::TargetingSystemPedPlayerComponent *v3; // rbx
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *v14; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::SimComponent *v19; // rax
  unsigned __int8 v20; // cl

  v2 = pSimObject;
  v3 = this;
  UFG::TargetingSystemPedBaseComponent::OnAttach((UFG::TargetingSystemPedBaseComponent *)&this->vfptr, pSimObject);
  v4 = &v3->m_pCharacterAnimationComponent;
  if ( v3->m_pCharacterAnimationComponent.m_pSimComponent )
  {
    v5 = v4->mPrev;
    v6 = v3->m_pCharacterAnimationComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->m_pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pCharacterAnimationComponent.m_pSimObject = 0i64;
    v3->m_pCharacterAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pCharacterAnimationComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pCharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v3->m_pCharacterAnimationComponent.mNext != &v3->m_pCharacterAnimationComponent) )
  {
    v7 = v4->mPrev;
    v8 = v3->m_pCharacterAnimationComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_pCharacterAnimationComponent.m_Changed = 1;
  v3->m_pCharacterAnimationComponent.m_pSimObject = v2;
  v3->m_pCharacterAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObject>(v4, v2);
  v9 = &v3->m_pAimingPlayerComponent;
  if ( v3->m_pAimingPlayerComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v3->m_pAimingPlayerComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v3->m_pAimingPlayerComponent.m_pSimComponent = 0i64;
LABEL_14:
    v3->m_pAimingPlayerComponent.m_pSimObject = 0i64;
    v3->m_pAimingPlayerComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pAimingPlayerComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v3->m_pAimingPlayerComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0> *)v3->m_pAimingPlayerComponent.mNext != &v3->m_pAimingPlayerComponent) )
  {
    v12 = v9->mPrev;
    v13 = v3->m_pAimingPlayerComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v3->m_pAimingPlayerComponent.m_Changed = 1;
  v3->m_pAimingPlayerComponent.m_pSimObject = v2;
  v3->m_pAimingPlayerComponent.m_TypeUID = UFG::AimingPlayerComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pAimingPlayerComponent,
    v2);
  v14 = &v3->m_pAttackRightsComponent;
  if ( v3->m_pAttackRightsComponent.m_pSimComponent )
  {
    v15 = v14->mPrev;
    v16 = v3->m_pAttackRightsComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v3->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_21:
    v3->m_pAttackRightsComponent.m_pSimObject = 0i64;
    v3->m_pAttackRightsComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pAttackRightsComponent.mPrev;
    v14->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v14->mPrev;
    goto LABEL_22;
  }
  if ( v3->m_pAttackRightsComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v14->mPrev != v14
     || (UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v3->m_pAttackRightsComponent.mNext != &v3->m_pAttackRightsComponent) )
  {
    v17 = v14->mPrev;
    v18 = v3->m_pAttackRightsComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  v3->m_pAttackRightsComponent.m_Changed = 1;
  v3->m_pAttackRightsComponent.m_pSimObject = v2;
  v3->m_pAttackRightsComponent.m_TypeUID = UFG::AttackRightsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pAttackRightsComponent,
    v2);
  v19 = v3->m_pAimingPlayerComponent.m_pSimComponent;
  if ( v19 )
  {
    v20 = v3->m_pTargetingMap->m_Map.p[3];
    if ( v20 )
      UFG::TargetingSimObject::SetTarget(
        &v3->m_pTargets[v20],
        (UFG::SimObject *)v19[13].m_BoundComponentHandles.mNode.mPrev);
  }
}

// File Line: 5126
// RVA: 0x541180
void __fastcall UFG::TargetingSystemPedPlayerComponent::OnDetach(UFG::TargetingSystemPedPlayerComponent *this)
{
  UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0> *v1; // r8
  UFG::TargetingSystemPedPlayerComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax

  v1 = &this->m_pAimingPlayerComponent;
  v2 = this;
  if ( this->m_pAimingPlayerComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->m_pAimingPlayerComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->m_pAimingPlayerComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pAimingPlayerComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::AimingPlayerComponent,0> *)this->m_pAimingPlayerComponent.mNext != &this->m_pAimingPlayerComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->m_pCharacterAnimationComponent;
  v1->m_Changed = 1;
  if ( v2->m_pCharacterAnimationComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pCharacterAnimationComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->m_pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pCharacterAnimationComponent.m_pSimObject = 0i64;
    v2->m_pCharacterAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pCharacterAnimationComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pCharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v2->m_pCharacterAnimationComponent.mNext != &v2->m_pCharacterAnimationComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->m_pCharacterAnimationComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pCharacterAnimationComponent.m_Changed = 1;
  v12 = &v2->m_pAttackRightsComponent;
  if ( v2->m_pAttackRightsComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->m_pAttackRightsComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pAttackRightsComponent.m_pSimObject = 0i64;
    v2->m_pAttackRightsComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAttackRightsComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pAttackRightsComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v2->m_pAttackRightsComponent.mNext != &v2->m_pAttackRightsComponent) )
  {
    v15 = v12->mPrev;
    v16 = v2->m_pAttackRightsComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pAttackRightsComponent.m_Changed = 1;
  UFG::TargetingSystemPedBaseComponent::OnDetach((UFG::TargetingSystemPedBaseComponent *)&v2->vfptr);
}

// File Line: 5137
// RVA: 0x54DA20
void __fastcall UFG::TargetingSystemPedPlayerComponent::SetOverrideDesiredFocusMode(UFG::TargetingSystemPedPlayerComponent *this, UFG::eFocusModeEnum eOverrideMode)
{
  this->m_eOverrideDesiredFocusMode = eOverrideMode;
}

