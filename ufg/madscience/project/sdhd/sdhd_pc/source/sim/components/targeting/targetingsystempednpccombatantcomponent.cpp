// File Line: 40
// RVA: 0x1544160
__int64 dynamic_initializer_for__UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList__);
}

// File Line: 41
// RVA: 0x532740
signed __int64 __fastcall UFG::TargetingSystemPedNPCCombatantComponent::GetTypeSize(UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  return 2904i64;
}

// File Line: 43
// RVA: 0x1543B30
__int64 dynamic_initializer_for__UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap__()
{
  signed __int64 v0; // rcx
  __int64 v1; // rax

  v0 = 91i64;
  v1 = UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[v1] = 0;
    v1 = UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.size++ + 1;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap__);
}

// File Line: 63
// RVA: 0x550AC0
void UFG::TargetingSystemPedNPCCombatantComponent::StaticInit(void)
{
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[2] = UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[4] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                           + 1;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[5] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                           + 2;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[6] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                           + 3;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[7] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                           + 4;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[8] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                           + 5;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[9] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                           + 6;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[13] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 7;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[14] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 8;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[15] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 9;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[16] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 10;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[17] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 11;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[18] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 12;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[19] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 13;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[20] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 14;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[21] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 15;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[22] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 16;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[23] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 17;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[24] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 18;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[25] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 19;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[26] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 20;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[79] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 21;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[27] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 22;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[28] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 23;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[55] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 24;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[56] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 25;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[61] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 26;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[62] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 27;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[63] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 28;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[64] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 29;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[65] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 30;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[66] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 31;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[67] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 32;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[68] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 33;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[69] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 34;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[70] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 35;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[71] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 36;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[36] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 37;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[76] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 38;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[80] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 39;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[29] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 40;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[31] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 41;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[34] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 42;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[33] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 43;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[35] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 44;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[32] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 45;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[30] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 46;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[1] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                           + 47;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[75] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 48;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[37] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 49;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[3] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                           + 50;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[50] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 51;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[38] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 52;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[39] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 53;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[40] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 54;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[41] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 55;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[42] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 56;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[43] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 57;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[58] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 58;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[77] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 59;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[49] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 60;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[47] = LOBYTE(UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                            + 61;
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes += 62;
}

// File Line: 150
// RVA: 0x5358A0
bool __fastcall UFG::TargetingSystemPedNPCCombatantComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentTargetingSystemPedNPCCombatant.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 156
// RVA: 0x5458B0
UFG::SimComponent *__fastcall UFG::TargetingSystemPedNPCCombatantComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rsi
  UFG::SimObject *v2; // rdi
  UFG::SimComponent *v3; // rbp
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  unsigned int v6; // ecx
  unsigned int v7; // er9
  UFG::SimComponentHolder *v8; // rbx
  signed __int64 v9; // r8
  unsigned int v10; // ecx
  unsigned int v11; // er9
  UFG::qMemoryPool *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::qPropertySet *v15; // r8
  UFG::SimComponent *v16; // rax
  unsigned __int16 v17; // cx
  unsigned int v18; // ebx
  UFG::SimObjectModifier v19; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = pSceneObj->m_pSimObject;
  v3 = 0i64;
  if ( !v2 )
    goto LABEL_25;
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v2->m_Components.p[20].m_pComponent;
    goto LABEL_23;
  }
  if ( (v4 & 0x8000u) != 0 )
  {
    v5 = v2->m_Components.p[20].m_pComponent;
    goto LABEL_23;
  }
  if ( (v4 >> 13) & 1 )
  {
    v6 = (unsigned int)v2[1].vfptr;
    v7 = v2->m_Components.size;
    if ( v6 < v7 )
    {
      v8 = v2->m_Components.p;
      while ( 1 )
      {
        v9 = v6;
        if ( (v8[v6].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
          && !(UFG::TargetingSystemBaseComponent::_TypeUID & ~v8[v6].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v6 >= v7 )
          goto LABEL_14;
      }
LABEL_13:
      v5 = v8[v9].m_pComponent;
      goto LABEL_23;
    }
LABEL_14:
    v5 = 0i64;
    goto LABEL_23;
  }
  if ( (v4 >> 12) & 1 )
  {
    v10 = (unsigned int)v2[1].vfptr;
    v11 = v2->m_Components.size;
    if ( v10 < v11 )
    {
      v8 = v2->m_Components.p;
      while ( 1 )
      {
        v9 = v10;
        if ( (v8[v10].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
          && !(UFG::TargetingSystemBaseComponent::_TypeUID & ~v8[v10].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_13;
        }
        if ( ++v10 >= v11 )
          goto LABEL_14;
      }
    }
    goto LABEL_14;
  }
  v5 = UFG::SimObject::GetComponentOfType(pSceneObj->m_pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_23:
  if ( v5 )
    return 0i64;
LABEL_25:
  v13 = UFG::GetSimulationMemoryPool();
  v14 = UFG::qMemoryPool::Allocate(v13, 0xB58ui64, "TargetingSystemPedNPCCombatantComponent", 0i64, 1u);
  if ( v14 )
  {
    v15 = v1->mpWritableProperties;
    if ( !v15 )
      v15 = v1->mpConstProperties;
    UFG::TargetingSystemPedNPCCombatantComponent::TargetingSystemPedNPCCombatantComponent(
      (UFG::TargetingSystemPedNPCCombatantComponent *)v14,
      v1->m_NameUID,
      v15,
      0);
    v3 = v16;
  }
  v17 = v2->m_Flags;
  if ( (v17 >> 14) & 1 || (v17 & 0x8000u) != 0 )
    v18 = 20;
  else
    v18 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v19, v2, 1);
  UFG::SimObjectModifier::AttachComponent(&v19, v3, v18);
  UFG::SimObjectModifier::Close(&v19);
  UFG::SimObjectModifier::~SimObjectModifier(&v19);
  return v3;
}

// File Line: 183
// RVA: 0x519D10
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::TargetingSystemPedNPCCombatantComponent(UFG::TargetingSystemPedNPCCombatantComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::TargetingSystemPedNPCCombatantComponent *v4; // rdi
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *v5; // rbx
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *v6; // rax

  v4 = this;
  UFG::TargetingSystemPedNPCBaseComponent::TargetingSystemPedNPCBaseComponent(
    (UFG::TargetingSystemPedNPCBaseComponent *)&this->vfptr,
    &UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap,
    name_uid,
    properties);
  v5 = (UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCCombatantComponent::`vftable'{for `UFG::SimComponent'};
  v4->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedNPCCombatantComponent::`vftable'{for `UFG::UpdateInterface'};
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::RebindingComponentHandle<UFG::AttackRightsComponent,0>(&v4->m_pAttackRightsComponent);
  v6 = UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList.mNode.mPrev;
  UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *)&UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList;
  UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList.mNode.mPrev = (UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::TargetingSystemPedNPCCombatantComponent::_TargetingSystemPedNPCCombatantComponentTypeUID,
    "TargetingSystemPedNPCCombatantComponent");
}

// File Line: 193
// RVA: 0x51D180
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::~TargetingSystemPedNPCCombatantComponent(UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::TargetingSystemPedNPCCombatantComponent *v1; // rdi
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *v2; // rbx
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *v3; // rcx
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *v4; // rax
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *v5; // rcx
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCCombatantComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedNPCCombatantComponent::`vftable'{for `UFG::UpdateInterface'};
  if ( this == UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentpCurrentIterator )
    UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentpCurrentIterator = (UFG::TargetingSystemPedNPCCombatantComponent *)&this->mPrev[-178].mNext;
  v2 = (UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAttackRightsComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::TargetingSystemPedNPCBaseComponent::~TargetingSystemPedNPCBaseComponent((UFG::TargetingSystemPedNPCBaseComponent *)&v1->vfptr);
}

// File Line: 202
// RVA: 0x53EF60
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::OnAttach(UFG::TargetingSystemPedNPCCombatantComponent *this, UFG::SimObject *pSimObject)
{
  UFG::TargetingSystemPedNPCCombatantComponent *v2; // rdi
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *v3; // rcx
  UFG::SimObject *v4; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  v2 = this;
  v3 = &this->m_pAttackRightsComponent;
  v4 = pSimObject;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mNext;
    v6 = v3->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    v3->m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pSimObject = 0i64;
    v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v3->mNext != v3) )
  {
    v7 = v3->mNext;
    v8 = v3->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = v4;
  v3->m_TypeUID = UFG::AttackRightsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::BindInternal<UFG::SimObject>(v3, v4);
  UFG::TargetingSystemPedNPCBaseComponent::OnAttach((UFG::TargetingSystemPedNPCBaseComponent *)&v2->vfptr, v4);
}

// File Line: 211
// RVA: 0x5410C0
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::OnDetach(UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *v1; // r8
  UFG::TargetingSystemPedNPCCombatantComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax

  v1 = &this->m_pAttackRightsComponent;
  v2 = this;
  if ( this->m_pAttackRightsComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->m_pAttackRightsComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pAttackRightsComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)this->m_pAttackRightsComponent.mNext != &this->m_pAttackRightsComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->m_pAIActionTreeComponent;
  v1->m_Changed = 1;
  if ( v2->m_pAIActionTreeComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pAIActionTreeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->m_pAIActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pAIActionTreeComponent.m_pSimObject = 0i64;
    v2->m_pAIActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAIActionTreeComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pAIActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *)v2->m_pAIActionTreeComponent.mNext != &v2->m_pAIActionTreeComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->m_pAIActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pAIActionTreeComponent.m_Changed = 1;
  UFG::TargetingSystemPedBaseComponent::OnDetach((UFG::TargetingSystemPedBaseComponent *)&v2->vfptr);
}

// File Line: 230
// RVA: 0x5717A0
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::updateFocusTarget(UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::TargetingSystemPedNPCCombatantComponent *v1; // rbx
  UFG::TargetingSimObject *v2; // rax
  signed __int64 v3; // rdx
  bool v4; // di
  bool v5; // al
  UFG::SimComponent *v6; // rcx
  UFG::SimObject *v7; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v8; // rax
  unsigned __int8 v9; // cl

  v1 = this;
  v2 = this->m_pTargets;
  v3 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[22];
  v4 = v2[v3].m_pTarget.m_pPointer && v2[v3].m_bLock;
  v5 = UFG::TargetingSystemPedNPCBaseComponent::isScriptControlled((UFG::TargetingSystemPedNPCBaseComponent *)&this->vfptr);
  if ( !v4 )
  {
    v6 = v1->m_pActiveAIEntityComponent.m_pSimComponent;
    if ( v6 )
    {
      if ( v5 )
      {
        v7 = (UFG::SimObject *)v6[38].m_BoundComponentHandles.mNode.mNext;
        if ( !v7 )
          return;
      }
      else
      {
        v8 = v6[30].vfptr;
        if ( !v8 )
        {
          UFG::TargetingSystemBaseComponent::ClearTarget(
            (UFG::TargetingSystemBaseComponent *)&v1->vfptr,
            eTARGET_TYPE_FOCUS);
          return;
        }
        v7 = (UFG::SimObject *)v8[5].__vecDelDtor;
      }
      v9 = v1->m_pTargetingMap->m_Map.p[22];
      if ( v9 )
        UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v9], v7);
    }
  }
}

// File Line: 274
// RVA: 0x55FB40
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::UpdateHijackableVehicleTarget(UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::TargetingSystemPedNPCCombatantComponent *v1; // r13
  unsigned __int8 v2; // dl
  unsigned __int64 v3; // rbx
  UFG::TargetingSimObject *v4; // rax
  signed __int64 v5; // rcx
  int v6; // er12
  unsigned int v7; // er14
  unsigned int v8; // er9
  unsigned int v9; // ebx
  UFG::SimObject *v10; // rdi
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rsi
  unsigned int v13; // er8
  unsigned int v14; // er11
  signed __int64 v15; // rdx
  unsigned int v16; // er8
  unsigned int v17; // er11
  unsigned __int16 v18; // dx
  UFG::PhysicsMoverInterface *v19; // rax
  unsigned int v20; // er8
  unsigned int v21; // er11
  signed __int64 v22; // rdx
  unsigned __int16 v23; // cx
  unsigned int v24; // er8
  unsigned int v25; // er10
  signed __int64 v26; // rdx
  UFG::SimComponent *v27; // rax
  unsigned int v28; // er8
  unsigned int v29; // er10
  unsigned int v30; // er8
  unsigned int v31; // er10
  char v32; // bl
  unsigned __int16 v33; // cx
  UFG::SimComponent *v34; // rax
  unsigned int v35; // er8
  unsigned int v36; // er10
  signed __int64 v37; // rdx
  unsigned int v38; // er8
  unsigned int v39; // er10
  signed __int64 v40; // r14
  UFG::RoadNetworkLocation *v41; // rbx
  UFG::RoadNetworkSegment *v42; // rbp
  UFG::qVector3 *v43; // rax
  UFG::RoadNetworkSubSegment *v44; // rbx
  unsigned int v45; // er15
  float v46; // xmm0_4
  UFG::qVector3 *v47; // rax
  float v48; // xmm6_4
  float v49; // xmm0_4
  UFG::qVector3 *v50; // rax
  unsigned int v51; // edx
  UFG::RoadNetworkLane *v52; // rbp
  bool v53; // bl
  unsigned __int8 v54; // cl
  UFG::qVector3 v55; // [rsp+28h] [rbp-780h]
  UFG::qVector3 v56; // [rsp+34h] [rbp-774h]
  UFG::qVector3 result; // [rsp+40h] [rbp-768h]
  UFG::qFixedArray<UFG::CloseTarget *,20> closeVehiclesList; // [rsp+50h] [rbp-758h]
  UFG::qFixedArray<UFG::CloseTarget,20> closeTargetsList; // [rsp+100h] [rbp-6A8h]

  v1 = this;
  v2 = this->m_pTargetingMap->m_Map.p[75];
  if ( v2 )
  {
    v3 = v2;
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v3], 0i64);
    v4 = v1->m_pTargets;
    if ( v4[v3].m_bLock )
      v4[v3].m_bLock = 0;
  }
  closeTargetsList.size = 0;
  closeVehiclesList.size = 0;
  UFG::TargetingSystemPedBaseComponent::updateCloseVehiclesList(
    (UFG::TargetingSystemPedBaseComponent *)&v1->vfptr,
    &closeTargetsList,
    &closeVehiclesList);
  v5 = (signed __int64)&v1->m_pTargets[(unsigned __int8)v1->m_pTargetingMap->m_Map.p[75]];
  if ( !*(_QWORD *)(v5 + 40) || !*(_BYTE *)(v5 + 49) )
  {
    v6 = 0;
    v7 = closeVehiclesList.size;
    if ( closeVehiclesList.size )
    {
      v8 = UFG::AiDriverComponent::_TypeUID;
      v9 = UFG::PhysicsMoverInterface::_TypeUID;
      while ( 1 )
      {
        v10 = closeVehiclesList.p[v6]->m_pSimObjectPropertiesComponent->m_pSimObject;
        if ( v10 )
          break;
LABEL_108:
        if ( ++v6 >= v7 )
          return;
      }
      v11 = v10->m_Flags;
      if ( (v11 >> 14) & 1 )
      {
        v12 = v10->m_Components.p[23].m_pComponent;
        if ( v12 && !((v8 ^ v12->m_TypeUID) & 0xFE000000) && !(v8 & ~v12->m_TypeUID & 0x1FFFFFF) )
          goto LABEL_33;
        goto LABEL_13;
      }
      if ( (v11 & 0x8000u) != 0 )
      {
        v12 = v10->m_Components.p[23].m_pComponent;
        if ( v12 && !((v8 ^ v12->m_TypeUID) & 0xFE000000) )
        {
          if ( v8 & ~v12->m_TypeUID & 0x1FFFFFF )
            v12 = 0i64;
          goto LABEL_33;
        }
        goto LABEL_13;
      }
      if ( (v11 >> 13) & 1 )
      {
        v13 = (unsigned int)v10[1].vfptr;
        v14 = v10->m_Components.size;
        if ( v13 >= v14 )
        {
LABEL_13:
          v12 = 0i64;
LABEL_33:
          v18 = v10->m_Flags;
          if ( (v18 >> 14) & 1 )
            goto LABEL_34;
          if ( (v18 & 0x8000u) != 0 )
          {
            v19 = (UFG::PhysicsMoverInterface *)v10->m_Components.p[34].m_pComponent;
            goto LABEL_47;
          }
          if ( (v18 >> 13) & 1 )
          {
            v19 = 0i64;
            goto LABEL_47;
          }
          if ( !((v18 >> 12) & 1) )
          {
            v19 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(v10, v9);
            v8 = UFG::AiDriverComponent::_TypeUID;
            v9 = UFG::PhysicsMoverInterface::_TypeUID;
            goto LABEL_47;
          }
          v20 = (unsigned int)v10[1].vfptr;
          v21 = v10->m_Components.size;
          if ( v20 >= v21 )
          {
LABEL_34:
            v19 = 0i64;
          }
          else
          {
            while ( 1 )
            {
              v22 = (signed __int64)&v10->m_Components.p[v20];
              if ( (*(_DWORD *)(v22 + 8) & 0xFE000000) == (v9 & 0xFE000000) && !(v9 & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF) )
                break;
              if ( ++v20 >= v21 )
                goto LABEL_34;
            }
            v19 = *(UFG::PhysicsMoverInterface **)v22;
          }
LABEL_47:
          if ( !v12 || !v19 )
            goto LABEL_108;
          if ( UFG::PhysicsMoverInterface::GetEngineDamage(v19) >= 0.5 )
            goto LABEL_107;
          v23 = v10->m_Flags;
          if ( (v23 >> 14) & 1 )
          {
            v24 = (unsigned int)v10[1].vfptr;
            v25 = v10->m_Components.size;
            if ( v24 < v25 )
            {
              while ( 1 )
              {
                v26 = (signed __int64)&v10->m_Components.p[v24];
                if ( (*(_DWORD *)(v26 + 8) & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                  && !(UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) )
                {
                  break;
                }
                if ( ++v24 >= v25 )
                  goto LABEL_57;
              }
LABEL_56:
              v27 = *(UFG::SimComponent **)v26;
LABEL_73:
              if ( !v27 )
                goto LABEL_107;
              if ( UFG::SimObjectUtility::IsClassType(v10, (UFG::qSymbol *)&qSymbol_Minibus.mUID)
                || UFG::SimObjectUtility::IsClassType(v10, (UFG::qSymbol *)&qSymbol_Tram.mUID)
                || UFG::SimObjectUtility::IsClassType(v10, (UFG::qSymbol *)&qSymbol_Cop.mUID)
                || (v32 = 1, UFG::SimObjectUtility::IsClassType(v10, (UFG::qSymbol *)&qSymbol_Taxi.mUID)) )
              {
                v32 = 0;
              }
              if ( !((unsigned __int8)v32 & (((unsigned __int8 (__fastcall *)(UFG::SimComponent *))v12->vfptr[16].__vecDelDtor)(v12) == 1)) )
              {
LABEL_107:
                v8 = UFG::AiDriverComponent::_TypeUID;
                v9 = UFG::PhysicsMoverInterface::_TypeUID;
                goto LABEL_108;
              }
              v33 = v10->m_Flags;
              if ( (v33 >> 14) & 1 )
              {
                v34 = v10->m_Components.p[24].m_pComponent;
                goto LABEL_99;
              }
              if ( (v33 & 0x8000u) != 0 )
              {
                v34 = v10->m_Components.p[24].m_pComponent;
                goto LABEL_99;
              }
              if ( (v33 >> 13) & 1 )
              {
                v35 = (unsigned int)v10[1].vfptr;
                v36 = v10->m_Components.size;
                if ( v35 < v36 )
                {
                  while ( 1 )
                  {
                    v37 = (signed __int64)&v10->m_Components.p[v35];
                    if ( (*(_DWORD *)(v37 + 8) & 0xFE000000) == (UFG::RoadSpaceComponent::_TypeUID & 0xFE000000)
                      && !(UFG::RoadSpaceComponent::_TypeUID & ~*(_DWORD *)(v37 + 8) & 0x1FFFFFF) )
                    {
                      break;
                    }
                    if ( ++v35 >= v36 )
                      goto LABEL_91;
                  }
LABEL_90:
                  v34 = *(UFG::SimComponent **)v37;
                  goto LABEL_99;
                }
              }
              else
              {
                if ( !((v33 >> 12) & 1) )
                {
                  v34 = UFG::SimObject::GetComponentOfType(v10, UFG::RoadSpaceComponent::_TypeUID);
LABEL_99:
                  v40 = (signed __int64)&v34[5].m_BoundComponentHandles.mNode.mNext;
                  v41 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v34[5].m_BoundComponentHandles.mNode.mNext);
                  v42 = (UFG::RoadNetworkSegment *)UFG::RoadNetworkLocation::GetRoadNetworkNode(v41);
                  if ( 0 == v42->mType.mValue )
                  {
                    v43 = UFG::RoadNetworkLocation::GetPos(v41, &result);
                    v44 = UFG::RoadNetworkSegment::GetClosestSubSegment(v42, v43);
                    v45 = (unsigned __int8)v42->mNumLanes - 1;
                    v46 = UFG::RoadNetworkSubSegment::GetBeginT(v44, 0);
                    v47 = UFG::RoadNetworkNode::GetPos((UFG::RoadNetworkNode *)&v42->mType, &v55, 0, v46);
                    v48 = (float)((float)((float)(v1->m_vTargetingPosition.x - v47->x)
                                        * (float)(v1->m_vTargetingPosition.x - v47->x))
                                + (float)((float)(v1->m_vTargetingPosition.y - v47->y)
                                        * (float)(v1->m_vTargetingPosition.y - v47->y)))
                        + (float)((float)(v1->m_vTargetingPosition.z - v47->z)
                                * (float)(v1->m_vTargetingPosition.z - v47->z));
                    v49 = UFG::RoadNetworkSubSegment::GetBeginT(v44, v45);
                    v50 = UFG::RoadNetworkNode::GetPos((UFG::RoadNetworkNode *)&v42->mType, &v56, v45, v49);
                    v51 = v48 >= (float)((float)((float)((float)(v1->m_vTargetingPosition.x - v50->x)
                                                       * (float)(v1->m_vTargetingPosition.x - v50->x))
                                               + (float)((float)(v1->m_vTargetingPosition.y - v50->y)
                                                       * (float)(v1->m_vTargetingPosition.y - v50->y)))
                                       + (float)((float)(v1->m_vTargetingPosition.z - v50->z)
                                               * (float)(v1->m_vTargetingPosition.z - v50->z))) ? v45 : 0;
                    v52 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v42->mType, v51);
                    v53 = UFG::RoadNetworkLane::IsReversedInNode(*(UFG::RoadNetworkLane **)(v40 + 64));
                    if ( v53 == UFG::RoadNetworkLane::IsReversedInNode(v52)
                      && !*(_QWORD *)(v40 + 160)
                      && *(float *)&v12[16].m_NameUID <= 1.0 )
                    {
                      v54 = v1->m_pTargetingMap->m_Map.p[75];
                      if ( v54 )
                        UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v54], v10);
                      return;
                    }
                  }
                  v7 = closeVehiclesList.size;
                  goto LABEL_107;
                }
                v38 = (unsigned int)v10[1].vfptr;
                v39 = v10->m_Components.size;
                if ( v38 < v39 )
                {
                  do
                  {
                    v37 = (signed __int64)&v10->m_Components.p[v38];
                    if ( (*(_DWORD *)(v37 + 8) & 0xFE000000) == (UFG::RoadSpaceComponent::_TypeUID & 0xFE000000)
                      && !(UFG::RoadSpaceComponent::_TypeUID & ~*(_DWORD *)(v37 + 8) & 0x1FFFFFF) )
                    {
                      goto LABEL_90;
                    }
                  }
                  while ( ++v38 < v39 );
                }
              }
LABEL_91:
              v34 = 0i64;
              goto LABEL_99;
            }
          }
          else
          {
            if ( (v23 & 0x8000u) != 0 )
            {
              v27 = v10->m_Components.p[30].m_pComponent;
              goto LABEL_73;
            }
            if ( (v23 >> 13) & 1 )
            {
              v28 = (unsigned int)v10[1].vfptr;
              v29 = v10->m_Components.size;
              if ( v28 < v29 )
              {
                do
                {
                  v26 = (signed __int64)&v10->m_Components.p[v28];
                  if ( (*(_DWORD *)(v26 + 8) & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                    && !(UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) )
                  {
                    goto LABEL_56;
                  }
                }
                while ( ++v28 < v29 );
              }
            }
            else
            {
              if ( !((v23 >> 12) & 1) )
              {
                v27 = UFG::SimObject::GetComponentOfType(v10, UFG::VehicleOccupantComponent::_TypeUID);
                goto LABEL_73;
              }
              v30 = (unsigned int)v10[1].vfptr;
              v31 = v10->m_Components.size;
              if ( v30 < v31 )
              {
                do
                {
                  v26 = (signed __int64)&v10->m_Components.p[v30];
                  if ( (*(_DWORD *)(v26 + 8) & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                    && !(UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) )
                  {
                    goto LABEL_56;
                  }
                }
                while ( ++v30 < v31 );
              }
            }
          }
LABEL_57:
          v27 = 0i64;
          goto LABEL_73;
        }
        while ( 1 )
        {
          v15 = (signed __int64)&v10->m_Components.p[v13];
          if ( (*(_DWORD *)(v15 + 8) & 0xFE000000) == (v8 & 0xFE000000) && !(v8 & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF) )
            break;
          if ( ++v13 >= v14 )
            goto LABEL_13;
        }
      }
      else
      {
        if ( !((v11 >> 12) & 1) )
        {
          v12 = UFG::SimObject::GetComponentOfType(v10, v8);
          v8 = UFG::AiDriverComponent::_TypeUID;
          v9 = UFG::PhysicsMoverInterface::_TypeUID;
          goto LABEL_33;
        }
        v16 = (unsigned int)v10[1].vfptr;
        v17 = v10->m_Components.size;
        if ( v16 >= v17 )
          goto LABEL_13;
        while ( 1 )
        {
          v15 = (signed __int64)&v10->m_Components.p[v16];
          if ( (*(_DWORD *)(v15 + 8) & 0xFE000000) == (v8 & 0xFE000000) && !(v8 & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF) )
            break;
          if ( ++v16 >= v17 )
            goto LABEL_13;
        }
      }
      v12 = *(UFG::SimComponent **)v15;
      goto LABEL_33;
    }
  }
}

// File Line: 365
// RVA: 0x579E60
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::updateTargets(UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::TargetingSystemPedNPCCombatantComponent *v1; // rdi
  UFG::SimComponent *v2; // rax
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm3_4
  UFG::SimComponent *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  unsigned __int8 v10; // cl
  signed __int64 v11; // rcx
  UFG::RigidBodyComponent *v12; // rbx
  UFG::SimObject *v13; // rdx
  unsigned __int8 v14; // cl
  unsigned __int8 v15; // cl
  signed __int64 v16; // rbx
  UFG::TargetingSimObject *v17; // rax
  UFG::qFixedArray<UFG::ClosePhysicalTarget,1> closePhysicalMeleeAttackableList; // [rsp+48h] [rbp-B8h]
  UFG::qFixedArray<UFG::CloseTarget *,5> closePropsList; // [rsp+60h] [rbp-A0h]
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePickupsList; // [rsp+90h] [rbp-70h]
  UFG::qFixedArray<UFG::ClosePhysicalTarget,2> closePhysicalDodgeableList; // [rsp+C0h] [rbp-40h]
  UFG::qFixedArray<UFG::ClosePhysicalTarget,10> filteredClosePhysicalTargetsList; // [rsp+F0h] [rbp-10h]
  UFG::qFixedArray<UFG::CloseTarget *,20> filteredCloseVehiclesList; // [rsp+1A0h] [rbp+A0h]
  UFG::qMatrix44 mat; // [rsp+250h] [rbp+150h]
  UFG::qFixedArray<UFG::CloseTarget *,80> filteredClosePedsList; // [rsp+290h] [rbp+190h]
  UFG::qFixedArray<UFG::CloseTarget,100> closeTargetsList; // [rsp+520h] [rbp+420h]
  UFG::qFixedArray<UFG::CloseTarget,100> filteredCloseTargetsList; // [rsp+2470h] [rbp+2370h]

  v1 = this;
  closeTargetsList.size = 0;
  filteredClosePedsList.size = 0;
  filteredCloseTargetsList.size = 0;
  filteredClosePickupsList.size = 0;
  closePropsList.size = 0;
  filteredCloseVehiclesList.size = 0;
  filteredClosePhysicalTargetsList.size = 0;
  closePhysicalDodgeableList.size = 0;
  closePhysicalMeleeAttackableList.size = 0;
  v2 = this->m_pEquippedSOWPC.m_pPointer;
  if ( v2 )
  {
    v3 = *(float *)(*((_QWORD *)&v2[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v2[2].m_pSimObject)) + 40i64);
    v4 = v3 * v3;
  }
  else
  {
    v4 = this->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
  }
  v5 = this->m_fMinimumTargetDistanceSquared;
  if ( v5 <= v4 )
    v5 = v4;
  UFG::TargetingSystemPedBaseComponent::findCloseTargets(
    &closeTargetsList,
    this->m_pSimObject,
    &this->m_vTargetingPosition,
    v5);
  UFG::TargetingSystemPedBaseComponent::filterCloseTargets(
    &closeTargetsList,
    &v1->m_CachedPedsList,
    &filteredClosePedsList,
    &filteredClosePickupsList,
    &closePropsList,
    &filteredCloseVehiclesList,
    &filteredCloseTargetsList);
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
  UFG::TargetingSystemPedNPCCombatantComponent::updateFocusTarget(v1);
  UFG::TargetingSystemPedBaseComponent::updateClosestPedTarget(
    (UFG::TargetingSystemPedBaseComponent *)&v1->vfptr,
    &filteredClosePedsList);
  v10 = v1->m_pTargetingMap->m_Map.p[58];
  if ( v10 )
    UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v10], 0i64);
  UFG::TargetingSystemPedBaseComponent::updateGroupTargets((UFG::TargetingSystemPedBaseComponent *)&v1->vfptr);
  UFG::TargetingSystemPedBaseComponent::updatePickupTarget(
    (UFG::TargetingSystemPedBaseComponent *)&v1->vfptr,
    &filteredClosePickupsList);
  UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets((UFG::TargetingSystemPedBaseComponent *)&v1->vfptr);
  UFG::TargetingSystemPedNPCBaseComponent::updatePropTarget(
    (UFG::TargetingSystemPedNPCBaseComponent *)&v1->vfptr,
    &closePropsList);
  v11 = (signed __int64)&v1->m_pTargets[(unsigned __int8)v1->m_pTargetingMap->m_Map.p[49]];
  if ( !*(_QWORD *)(v11 + 40) || !*(_BYTE *)(v11 + 49) )
  {
    if ( filteredClosePhysicalTargetsList.size
      && (v12 = filteredClosePhysicalTargetsList.p[0].m_pRigidBodyComponent,
          UFG::RigidBody::GetTransform(
            (UFG::RigidBody *)&filteredClosePhysicalTargetsList.p[0].m_pRigidBodyComponent->vfptr,
            &mat),
          (v13 = v12->m_pSimObject) != 0i64) )
    {
      v14 = v1->m_pTargetingMap->m_Map.p[49];
      if ( v14 )
        UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v14], v13);
    }
    else
    {
      v15 = v1->m_pTargetingMap->m_Map.p[49];
      if ( v15 )
      {
        v16 = v15;
        UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v16], 0i64);
        v17 = v1->m_pTargets;
        if ( v17[v16].m_bLock )
          v17[v16].m_bLock = 0;
      }
    }
  }
  UFG::TargetingSystemBaseComponent::updateMySpawnPointTarget((UFG::TargetingSystemBaseComponent *)&v1->vfptr);
}

// File Line: 423
// RVA: 0x55CDB0
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::Update(UFG::TargetingSystemPedNPCCombatantComponent *this, float delta_sec)
{
  UFG::TargetingSystemPedNPCCombatantComponent *v2; // rdi
  UFG::AttackRightsComponent *v3; // rcx
  UFG::HasAttackRequestNode *v4; // rax
  UFG::SimObject *v5; // rdx
  unsigned __int8 v6; // cl
  __int64 v7; // rbx

  v2 = this;
  UFG::TargetingSystemPedBaseComponent::UpdateCommon((UFG::TargetingSystemPedBaseComponent *)&this[-1].mPrev);
  UFG::TargetingSystemPedNPCBaseComponent::updateTargetingIntentions((UFG::TargetingSystemPedNPCBaseComponent *)&v2[-1].mPrev);
  UFG::TargetingSystemPedNPCCombatantComponent::updateFocusTargetSubTargetingLocation((UFG::TargetingSystemPedNPCCombatantComponent *)((char *)v2 - 64));
  if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> **))v2[-1].mPrev[11].mPrev)(&v2[-1].mPrev) )
    UFG::TargetingSystemPedNPCCombatantComponent::updateTargets((UFG::TargetingSystemPedNPCCombatantComponent *)((char *)v2 - 64));
  v3 = (UFG::AttackRightsComponent *)v2->m_pAIActionTreeComponent.m_pSimComponent;
  if ( v3 )
  {
    v4 = UFG::AttackRightsComponent::GetCurrentAttacker(v3, 0);
    v5 = v4 ? UFG::HasAttackRequestNode::GetSimObject(v4) : 0i64;
    v6 = *(_BYTE *)(*(_QWORD *)&v2->m_Flags + 85i64);
    if ( v6 )
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(*(_QWORD *)&v2->m_TypeUID + 56i64 * v6), v5);
  }
  v7 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v2->m_Flags + 30i64) + *(_QWORD *)&v2->m_TypeUID + 40);
  if ( v7 != *(_QWORD *)&v2->m_vTargetingPosition.z )
  {
    ((void (*)(void))v2->m_pTransformNodeComponent.mNext->mPrev[11].mPrev)();
    *(_QWORD *)&v2->m_vTargetingPosition.z = v7;
  }
  LOBYTE(v2->m_pInterestPointUserComponent.m_Changed) = 0;
}

// File Line: 461
// RVA: 0x154CD10
__int64 UFG::_dynamic_initializer_for__symSubTargetingLocationCoverPopoutLeft__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Targeting-SubTargetingProfiles-Locations-CharacterCoverPopoutLeft", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symSubTargetingLocationCoverPopoutLeft, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symSubTargetingLocationCoverPopoutLeft__);
}

// File Line: 462
// RVA: 0x154CD50
__int64 UFG::_dynamic_initializer_for__symSubTargetingLocationCoverPopoutRight__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Targeting-SubTargetingProfiles-Locations-CharacterCoverPopoutRight", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symSubTargetingLocationCoverPopoutRight, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symSubTargetingLocationCoverPopoutRight__);
}

// File Line: 463
// RVA: 0x154CD90
__int64 UFG::_dynamic_initializer_for__symSubTargetingLocationCoverPopoutTop__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Targeting-SubTargetingProfiles-Locations-CharacterCoverPopoutTop", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symSubTargetingLocationCoverPopoutTop, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symSubTargetingLocationCoverPopoutTop__);
}

// File Line: 466
// RVA: 0x569D20
char __fastcall UFG::TargetingSystemPedNPCCombatantComponent::hasLineOfSightToFocus(UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::SimObject *v1; // r8
  unsigned __int16 v2; // cx
  UFG::SimComponent *v3; // rbx
  unsigned int v4; // ecx
  unsigned int v5; // er9
  UFG::SimComponentHolder *v6; // r11
  signed __int64 v7; // rbx
  unsigned int v8; // ecx
  unsigned int v9; // er9

  v1 = this->m_pSimObject;
  if ( !v1 )
    return 0;
  v2 = v1->m_Flags;
  if ( !((v2 >> 14) & 1) )
  {
    if ( (v2 & 0x8000u) != 0 )
    {
      v3 = v1->m_Components.p[19].m_pComponent;
      goto LABEL_23;
    }
    if ( (v2 >> 13) & 1 )
    {
      v4 = (unsigned int)v1[1].vfptr;
      v5 = v1->m_Components.size;
      if ( v4 < v5 )
      {
        v6 = v1->m_Components.p;
        while ( 1 )
        {
          v7 = v4;
          if ( (v6[v4].m_TypeUID & 0xFE000000) == (UFG::AIActionTreeComponent::_TypeUID & 0xFE000000)
            && !(UFG::AIActionTreeComponent::_TypeUID & ~v6[v4].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v4 >= v5 )
            goto LABEL_14;
        }
LABEL_13:
        v3 = v6[v7].m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( !((v2 >> 12) & 1) )
      {
        v3 = UFG::SimObject::GetComponentOfType(v1, UFG::AIActionTreeComponent::_TypeUID);
        goto LABEL_23;
      }
      v8 = (unsigned int)v1[1].vfptr;
      v9 = v1->m_Components.size;
      if ( v8 < v9 )
      {
        v6 = v1->m_Components.p;
        do
        {
          v7 = v8;
          if ( (v6[v8].m_TypeUID & 0xFE000000) == (UFG::AIActionTreeComponent::_TypeUID & 0xFE000000)
            && !(UFG::AIActionTreeComponent::_TypeUID & ~v6[v8].m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_13;
          }
        }
        while ( ++v8 < v9 );
      }
    }
LABEL_14:
    v3 = 0i64;
    goto LABEL_23;
  }
  v3 = v1->m_Components.p[19].m_pComponent;
LABEL_23:
  if ( v3 )
  {
    if ( !(_S33_0 & 1) )
    {
      _S33_0 |= 1u;
      actionID.mUID = UFG::qStringHashUpper32("LineOfSightToFocus_KEY", 0xFFFFFFFF);
    }
    if ( ActionController::IsPlaying((ActionController *)&v3[3].m_TypeUID, &actionID, 0xFFFFFFFF, 1) )
      return 1;
  }
  return 0;
}

// File Line: 482
// RVA: 0x572C90
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::updateFocusTargetSubTargetingLocation(UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::TargetingSystemPedNPCCombatantComponent *v1; // rdi
  UFG::qBaseTreeRB *v2; // rsi
  UFG::qBaseTreeRB *v3; // rax
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // dx
  unsigned int v6; // edx
  unsigned int v7; // er8
  signed __int64 v8; // rbx
  UFG::SimComponent *v9; // rbx
  unsigned int v10; // edx
  unsigned int v11; // er8
  unsigned int v12; // edx
  unsigned int v13; // er8
  unsigned int v14; // edx
  unsigned int v15; // er8
  unsigned int v16; // edx
  UFG::SubTargetingLocation *v17; // rax
  UFG::SubTargetingLocation *v18; // rcx

  v1 = this;
  if ( this->m_pFocusTargetSubTargetingLocationOverride )
    goto LABEL_52;
  v2 = 0i64;
  if ( UFG::gNullQSymbol.mUID == -1 )
  {
    this->m_pFocusTargetSubTargetingLocation = 0i64;
  }
  else
  {
    v3 = UFG::gNullQSymbol.mUID ? UFG::qBaseTreeRB::Get(
                                    &UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree,
                                    UFG::gNullQSymbol.mUID) : 0i64;
    v1->m_pFocusTargetSubTargetingLocation = (UFG::SubTargetingLocation *)v3;
  }
  v4 = v1->m_pTargets[(unsigned __int8)v1->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( !v4 )
    goto LABEL_52;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = (unsigned int)v4[1].vfptr;
    v7 = v4->m_Components.size;
    if ( v6 < v7 )
    {
      v8 = (signed __int64)&v4->m_Components.p[v6];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
           || UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v6;
        v8 += 16i64;
        if ( v6 >= v7 )
          goto LABEL_15;
      }
LABEL_16:
      v9 = *(UFG::SimComponent **)v8;
      goto LABEL_39;
    }
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
    {
      v12 = (unsigned int)v4[1].vfptr;
      v13 = v4->m_Components.size;
      if ( v12 < v13 )
      {
        v8 = (signed __int64)&v4->m_Components.p[v12];
        while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
             || UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
        {
          ++v12;
          v8 += 16i64;
          if ( v12 >= v13 )
          {
            v9 = 0i64;
            goto LABEL_39;
          }
        }
        goto LABEL_16;
      }
    }
    else
    {
      if ( !((v5 >> 12) & 1) )
      {
        v9 = UFG::SimObject::GetComponentOfType(v4, UFG::AICoverComponent::_TypeUID);
        goto LABEL_39;
      }
      v14 = (unsigned int)v4[1].vfptr;
      v15 = v4->m_Components.size;
      if ( v14 < v15 )
      {
        v8 = (signed __int64)&v4->m_Components.p[v14];
        while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
             || UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
        {
          ++v14;
          v8 += 16i64;
          if ( v14 >= v15 )
          {
            v9 = 0i64;
            goto LABEL_39;
          }
        }
        goto LABEL_16;
      }
    }
  }
  else
  {
    v10 = (unsigned int)v4[1].vfptr;
    v11 = v4->m_Components.size;
    if ( v10 < v11 )
    {
      v8 = (signed __int64)&v4->m_Components.p[v10];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
           || UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v10;
        v8 += 16i64;
        if ( v10 >= v11 )
        {
          v9 = 0i64;
          goto LABEL_39;
        }
      }
      goto LABEL_16;
    }
  }
LABEL_15:
  v9 = 0i64;
LABEL_39:
  if ( v9
    && UFG::AICoverComponent::IsInCover((UFG::AICoverComponent *)v9)
    && !UFG::TargetingSystemPedNPCCombatantComponent::hasLineOfSightToFocus(v1) )
  {
    switch ( LODWORD(v9[2].vfptr) )
    {
      case 1:
        v16 = UFG::symSubTargetingLocationCoverPopoutLeft.mUID;
        break;
      case 2:
        v16 = UFG::symSubTargetingLocationCoverPopoutRight.mUID;
        break;
      case 3:
        v16 = UFG::symSubTargetingLocationCoverPopoutTop.mUID;
        break;
      default:
        goto LABEL_52;
    }
    if ( v16 != -1 && v16 )
      v2 = UFG::qBaseTreeRB::Get(&UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree, v16);
    v1->m_pFocusTargetSubTargetingLocation = (UFG::SubTargetingLocation *)v2;
  }
LABEL_52:
  v17 = v1->m_pFocusTargetSubTargetingLocationOverride;
  if ( v17 )
    v1->m_pFocusTargetSubTargetingLocation = v17;
  v18 = v1->m_pFocusTargetSubTargetingLocation;
  if ( v18 )
  {
    if ( v18 != v1->m_pLastFocusTargetSubTargetingLocation )
    {
      *(float *)&v1->m_pAimingBaseComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev = v18->m_fAccuracyPenalty + *(float *)&v1->m_pAimingBaseComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
      v1->m_pLastFocusTargetSubTargetingLocation = v1->m_pFocusTargetSubTargetingLocation;
    }
  }
}

