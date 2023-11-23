// File Line: 40
// RVA: 0x1544160
__int64 dynamic_initializer_for__UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList__);
}

// File Line: 41
// RVA: 0x532740
__int64 __fastcall UFG::TargetingSystemPedNPCCombatantComponent::GetTypeSize(
        UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  return 2904i64;
}

// File Line: 43
// RVA: 0x1543B30
__int64 dynamic_initializer_for__UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap__()
{
  __int64 v0; // rcx
  __int64 size; // rax

  v0 = 91i64;
  size = UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[size] = 0;
    size = ++UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.size;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap__);
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
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentTargetingSystemPedNPCCombatant,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 156
// RVA: 0x5458B0
UFG::SimComponent *__fastcall UFG::TargetingSystemPedNPCCombatantComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SimObject *m_pSimObject; // rdi
  UFG::SimComponent *v3; // rbp
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v9; // r8
  unsigned int v10; // ecx
  unsigned int v11; // r9d
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v16; // rax
  __int16 v17; // cx
  unsigned int v18; // ebx
  UFG::SimObjectModifier v19; // [rsp+38h] [rbp-30h] BYREF

  m_pSimObject = pSceneObj->m_pSimObject;
  v3 = 0i64;
  if ( !m_pSimObject )
    goto LABEL_25;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
    goto LABEL_23;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
    goto LABEL_23;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v9 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
          && (UFG::TargetingSystemBaseComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_14;
      }
LABEL_13:
      m_pComponent = p[v9].m_pComponent;
      goto LABEL_23;
    }
LABEL_14:
    m_pComponent = 0i64;
    goto LABEL_23;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v10 = (unsigned int)m_pSimObject[1].vfptr;
    v11 = m_pSimObject->m_Components.size;
    if ( v10 < v11 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v9 = v10;
        if ( (p[v10].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
          && (UFG::TargetingSystemBaseComponent::_TypeUID & ~p[v10].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_13;
        }
        if ( ++v10 >= v11 )
          goto LABEL_14;
      }
    }
    goto LABEL_14;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(
                   pSceneObj->m_pSimObject,
                   UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_23:
  if ( m_pComponent )
    return 0i64;
LABEL_25:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v14 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xB58ui64, "TargetingSystemPedNPCCombatantComponent", 0i64, 1u);
  if ( v14 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::TargetingSystemPedNPCCombatantComponent::TargetingSystemPedNPCCombatantComponent(
      (UFG::TargetingSystemPedNPCCombatantComponent *)v14,
      pSceneObj->m_NameUID,
      mpWritableProperties,
      0);
    v3 = v16;
  }
  v17 = m_pSimObject->m_Flags;
  if ( (v17 & 0x4000) != 0 || v17 < 0 )
    v18 = 20;
  else
    v18 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v19, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v19, v3, v18);
  UFG::SimObjectModifier::Close(&v19);
  UFG::SimObjectModifier::~SimObjectModifier(&v19);
  return v3;
}

// File Line: 183
// RVA: 0x519D10
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::TargetingSystemPedNPCCombatantComponent(
        UFG::TargetingSystemPedNPCCombatantComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *mPrev; // rax

  UFG::TargetingSystemPedNPCBaseComponent::TargetingSystemPedNPCBaseComponent(
    this,
    &UFG::TargetingSystemPedNPCCombatantComponent::ms_TargetingMap,
    name_uid,
    properties);
  this->UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>::mPrev = &this->UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>;
  this->UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>::mNext = &this->UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>;
  this->UFG::TargetingSystemPedNPCBaseComponent::UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCCombatantComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemPedNPCBaseComponent::UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedNPCCombatantComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::RebindingComponentHandle<UFG::AttackRightsComponent,0>(&this->m_pAttackRightsComponent);
  mPrev = UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList.mNode.mPrev;
  UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>;
  this->UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>::mNext = (UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *)&UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList;
  UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentList.mNode.mPrev = &this->UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::TargetingSystemPedNPCCombatantComponent::_TargetingSystemPedNPCCombatantComponentTypeUID,
    "TargetingSystemPedNPCCombatantComponent");
}

// File Line: 193
// RVA: 0x51D180
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::~TargetingSystemPedNPCCombatantComponent(
        UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *v2; // rbx
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *mPrev; // rcx
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *mNext; // rax
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *v5; // rcx
  UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *v6; // rax

  this->UFG::TargetingSystemPedNPCBaseComponent::UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCCombatantComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemPedNPCBaseComponent::UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedNPCCombatantComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentpCurrentIterator )
    UFG::TargetingSystemPedNPCCombatantComponent::s_TargetingSystemPedNPCCombatantComponentpCurrentIterator = (UFG::TargetingSystemPedNPCCombatantComponent *)&this->UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>::mPrev[-178].mNext;
  v2 = &this->UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>;
  mPrev = this->UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAttackRightsComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::TargetingSystemPedNPCBaseComponent::~TargetingSystemPedNPCBaseComponent(this);
}

// File Line: 202
// RVA: 0x53EF60
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::OnAttach(
        UFG::TargetingSystemPedNPCCombatantComponent *this,
        UFG::SimObject *pSimObject)
{
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *p_m_pAttackRightsComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  p_m_pAttackRightsComponent = &this->m_pAttackRightsComponent;
  if ( p_m_pAttackRightsComponent->m_pSimComponent )
  {
    mNext = p_m_pAttackRightsComponent->mNext;
    mPrev = p_m_pAttackRightsComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAttackRightsComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_m_pAttackRightsComponent->m_pSimObject = 0i64;
    p_m_pAttackRightsComponent->mNext = p_m_pAttackRightsComponent;
    p_m_pAttackRightsComponent->mPrev = p_m_pAttackRightsComponent;
    goto LABEL_8;
  }
  if ( p_m_pAttackRightsComponent->m_pSimObject
    && (p_m_pAttackRightsComponent->mPrev != p_m_pAttackRightsComponent
     || p_m_pAttackRightsComponent->mNext != p_m_pAttackRightsComponent) )
  {
    v7 = p_m_pAttackRightsComponent->mNext;
    v8 = p_m_pAttackRightsComponent->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAttackRightsComponent->m_Changed = 1;
  p_m_pAttackRightsComponent->m_pSimObject = pSimObject;
  p_m_pAttackRightsComponent->m_TypeUID = UFG::AttackRightsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::BindInternal<UFG::SimObject>(
    p_m_pAttackRightsComponent,
    pSimObject);
  UFG::TargetingSystemPedNPCBaseComponent::OnAttach(this, pSimObject);
}

// File Line: 211
// RVA: 0x5410C0
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::OnDetach(
        UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *p_m_pAttackRightsComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *p_m_pAIActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax

  p_m_pAttackRightsComponent = &this->m_pAttackRightsComponent;
  if ( this->m_pAttackRightsComponent.m_pSimComponent )
  {
    mPrev = p_m_pAttackRightsComponent->mPrev;
    mNext = this->m_pAttackRightsComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_m_pAttackRightsComponent->m_pSimObject = 0i64;
    p_m_pAttackRightsComponent->mNext = p_m_pAttackRightsComponent;
    p_m_pAttackRightsComponent->mPrev = p_m_pAttackRightsComponent;
    goto LABEL_8;
  }
  if ( this->m_pAttackRightsComponent.m_pSimObject
    && (p_m_pAttackRightsComponent->mPrev != p_m_pAttackRightsComponent
     || this->m_pAttackRightsComponent.mNext != &this->m_pAttackRightsComponent) )
  {
    v5 = p_m_pAttackRightsComponent->mPrev;
    v6 = p_m_pAttackRightsComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAIActionTreeComponent = &this->m_pAIActionTreeComponent;
  p_m_pAttackRightsComponent->m_Changed = 1;
  if ( this->m_pAIActionTreeComponent.m_pSimComponent )
  {
    v8 = p_m_pAIActionTreeComponent->mPrev;
    v9 = this->m_pAIActionTreeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pAIActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pAIActionTreeComponent.m_pSimObject = 0i64;
    this->m_pAIActionTreeComponent.mNext = &this->m_pAIActionTreeComponent;
    p_m_pAIActionTreeComponent->mPrev = p_m_pAIActionTreeComponent;
    goto LABEL_15;
  }
  if ( this->m_pAIActionTreeComponent.m_pSimObject
    && (p_m_pAIActionTreeComponent->mPrev != p_m_pAIActionTreeComponent
     || this->m_pAIActionTreeComponent.mNext != &this->m_pAIActionTreeComponent) )
  {
    v10 = p_m_pAIActionTreeComponent->mPrev;
    v11 = this->m_pAIActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pAIActionTreeComponent.m_Changed = 1;
  UFG::TargetingSystemPedBaseComponent::OnDetach(this);
}

// File Line: 230
// RVA: 0x5717A0
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::updateFocusTarget(
        UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v3; // rdx
  bool v4; // di
  bool isScriptControlled; // al
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::SimObject *mNext; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  unsigned __int8 v9; // cl

  m_pTargets = this->m_pTargets;
  v3 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[22];
  v4 = m_pTargets[v3].m_pTarget.m_pPointer && m_pTargets[v3].m_bLock;
  isScriptControlled = UFG::TargetingSystemPedNPCBaseComponent::isScriptControlled(this);
  if ( !v4 )
  {
    m_pSimComponent = this->m_pActiveAIEntityComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      if ( isScriptControlled )
      {
        mNext = (UFG::SimObject *)m_pSimComponent[38].m_BoundComponentHandles.mNode.mNext;
        if ( !mNext )
          return;
      }
      else
      {
        vfptr = m_pSimComponent[30].vfptr;
        if ( !vfptr )
        {
          UFG::TargetingSystemBaseComponent::ClearTarget(this, eTARGET_TYPE_FOCUS);
          return;
        }
        mNext = (UFG::SimObject *)vfptr[5].__vecDelDtor;
      }
      v9 = this->m_pTargetingMap->m_Map.p[22];
      if ( v9 )
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v9], mNext);
    }
  }
}

// File Line: 274
// RVA: 0x55FB40
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::UpdateHijackableVehicleTarget(
        UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  unsigned __int8 v2; // dl
  unsigned __int64 v3; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  UFG::TargetingSimObject *v5; // rcx
  int v6; // r12d
  unsigned int size; // r14d
  unsigned int v8; // r9d
  unsigned int v9; // ebx
  UFG::SimObject *m_pSimObject; // rdi
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rsi
  unsigned int vfptr; // r8d
  unsigned int v14; // r11d
  __int64 v15; // rdx
  unsigned int v16; // r8d
  unsigned int v17; // r11d
  __int16 v18; // dx
  UFG::PhysicsMoverInterface *ComponentOfType; // rax
  unsigned int v20; // r8d
  unsigned int v21; // r11d
  __int64 v22; // rdx
  __int16 v23; // cx
  unsigned int v24; // r8d
  unsigned int v25; // r10d
  __int64 v26; // rdx
  UFG::SimComponent *v27; // rax
  unsigned int v28; // r8d
  unsigned int v29; // r10d
  unsigned int v30; // r8d
  unsigned int v31; // r10d
  char v32; // bl
  __int16 v33; // cx
  UFG::SimComponent *v34; // rax
  unsigned int v35; // r8d
  unsigned int v36; // r10d
  __int64 v37; // rdx
  unsigned int v38; // r8d
  unsigned int v39; // r10d
  UFG::RoadNetworkLane **p_mNext; // r14
  UFG::RoadNetworkLocation *Name; // rbx
  UFG::RoadNetworkSegment *RoadNetworkNode; // rbp
  UFG::qVector3 *Pos; // rax
  UFG::RoadNetworkSubSegment *ClosestSubSegment; // rbx
  unsigned int v45; // r15d
  float BeginT; // xmm0_4
  UFG::qVector3 *v47; // rax
  float v48; // xmm6_4
  float v49; // xmm0_4
  UFG::qVector3 *v50; // rax
  unsigned int v51; // edx
  UFG::RoadNetworkLane *Lane; // rbp
  bool IsReversedInNode; // bl
  unsigned __int8 v54; // cl
  UFG::qVector3 v55; // [rsp+28h] [rbp-780h] BYREF
  UFG::qVector3 v56; // [rsp+34h] [rbp-774h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-768h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,20> closeVehiclesList; // [rsp+50h] [rbp-758h] BYREF
  UFG::qFixedArray<UFG::CloseTarget,20> closeTargetsList; // [rsp+100h] [rbp-6A8h] BYREF

  v2 = this->m_pTargetingMap->m_Map.p[75];
  if ( v2 )
  {
    v3 = v2;
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v3], 0i64);
    m_pTargets = this->m_pTargets;
    if ( m_pTargets[v3].m_bLock )
      m_pTargets[v3].m_bLock = 0;
  }
  closeTargetsList.size = 0;
  closeVehiclesList.size = 0;
  UFG::TargetingSystemPedBaseComponent::updateCloseVehiclesList(this, &closeTargetsList, &closeVehiclesList);
  v5 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[75]];
  if ( !v5->m_pTarget.m_pPointer || !v5->m_bLock )
  {
    v6 = 0;
    size = closeVehiclesList.size;
    if ( closeVehiclesList.size )
    {
      v8 = UFG::AiDriverComponent::_TypeUID;
      v9 = UFG::PhysicsMoverInterface::_TypeUID;
      while ( 1 )
      {
        m_pSimObject = closeVehiclesList.p[v6]->m_pSimObjectPropertiesComponent->m_pSimObject;
        if ( m_pSimObject )
          break;
LABEL_108:
        if ( ++v6 >= size )
          return;
      }
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[23].m_pComponent;
        if ( m_pComponent
          && ((v8 ^ m_pComponent->m_TypeUID) & 0xFE000000) == 0
          && (v8 & ~m_pComponent->m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_33;
        }
        goto LABEL_13;
      }
      if ( m_Flags < 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[23].m_pComponent;
        if ( m_pComponent && ((v8 ^ m_pComponent->m_TypeUID) & 0xFE000000) == 0 )
        {
          if ( (v8 & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
            m_pComponent = 0i64;
          goto LABEL_33;
        }
        goto LABEL_13;
      }
      if ( (m_Flags & 0x2000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        v14 = m_pSimObject->m_Components.size;
        if ( vfptr >= v14 )
        {
LABEL_13:
          m_pComponent = 0i64;
LABEL_33:
          v18 = m_pSimObject->m_Flags;
          if ( (v18 & 0x4000) != 0 )
            goto LABEL_34;
          if ( v18 < 0 )
          {
            ComponentOfType = (UFG::PhysicsMoverInterface *)m_pSimObject->m_Components.p[34].m_pComponent;
            goto LABEL_47;
          }
          if ( (v18 & 0x2000) != 0 )
          {
            ComponentOfType = 0i64;
            goto LABEL_47;
          }
          if ( (v18 & 0x1000) == 0 )
          {
            ComponentOfType = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(m_pSimObject, v9);
            v8 = UFG::AiDriverComponent::_TypeUID;
            v9 = UFG::PhysicsMoverInterface::_TypeUID;
            goto LABEL_47;
          }
          v20 = (unsigned int)m_pSimObject[1].vfptr;
          v21 = m_pSimObject->m_Components.size;
          if ( v20 >= v21 )
          {
LABEL_34:
            ComponentOfType = 0i64;
          }
          else
          {
            while ( 1 )
            {
              v22 = (__int64)&m_pSimObject->m_Components.p[v20];
              if ( (*(_DWORD *)(v22 + 8) & 0xFE000000) == (v9 & 0xFE000000)
                && (v9 & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++v20 >= v21 )
                goto LABEL_34;
            }
            ComponentOfType = *(UFG::PhysicsMoverInterface **)v22;
          }
LABEL_47:
          if ( !m_pComponent || !ComponentOfType )
            goto LABEL_108;
          if ( UFG::PhysicsMoverInterface::GetEngineDamage(ComponentOfType) >= 0.5 )
            goto LABEL_107;
          v23 = m_pSimObject->m_Flags;
          if ( (v23 & 0x4000) != 0 )
          {
            v24 = (unsigned int)m_pSimObject[1].vfptr;
            v25 = m_pSimObject->m_Components.size;
            if ( v24 < v25 )
            {
              while ( 1 )
              {
                v26 = (__int64)&m_pSimObject->m_Components.p[v24];
                if ( (*(_DWORD *)(v26 + 8) & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                  && (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) == 0 )
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
              if ( UFG::SimObjectUtility::IsClassType(m_pSimObject, &qSymbol_Minibus)
                || UFG::SimObjectUtility::IsClassType(m_pSimObject, &qSymbol_Tram)
                || UFG::SimObjectUtility::IsClassType(m_pSimObject, &qSymbol_Cop)
                || (v32 = 1, UFG::SimObjectUtility::IsClassType(m_pSimObject, &qSymbol_Taxi)) )
              {
                v32 = 0;
              }
              if ( ((unsigned __int8)v32 & (((unsigned __int8 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[16].__vecDelDtor)(m_pComponent) == 1)) == 0 )
              {
LABEL_107:
                v8 = UFG::AiDriverComponent::_TypeUID;
                v9 = UFG::PhysicsMoverInterface::_TypeUID;
                goto LABEL_108;
              }
              v33 = m_pSimObject->m_Flags;
              if ( (v33 & 0x4000) != 0 )
              {
                v34 = m_pSimObject->m_Components.p[24].m_pComponent;
                goto LABEL_99;
              }
              if ( v33 < 0 )
              {
                v34 = m_pSimObject->m_Components.p[24].m_pComponent;
                goto LABEL_99;
              }
              if ( (v33 & 0x2000) != 0 )
              {
                v35 = (unsigned int)m_pSimObject[1].vfptr;
                v36 = m_pSimObject->m_Components.size;
                if ( v35 < v36 )
                {
                  while ( 1 )
                  {
                    v37 = (__int64)&m_pSimObject->m_Components.p[v35];
                    if ( (*(_DWORD *)(v37 + 8) & 0xFE000000) == (UFG::RoadSpaceComponent::_TypeUID & 0xFE000000)
                      && (UFG::RoadSpaceComponent::_TypeUID & ~*(_DWORD *)(v37 + 8) & 0x1FFFFFF) == 0 )
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
                if ( (v33 & 0x1000) == 0 )
                {
                  v34 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::RoadSpaceComponent::_TypeUID);
LABEL_99:
                  p_mNext = (UFG::RoadNetworkLane **)&v34[5].m_BoundComponentHandles.mNode.mNext;
                  Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v34[5].m_BoundComponentHandles.mNode.mNext);
                  RoadNetworkNode = (UFG::RoadNetworkSegment *)UFG::RoadNetworkLocation::GetRoadNetworkNode(Name);
                  if ( !RoadNetworkNode->mType.mValue )
                  {
                    Pos = UFG::RoadNetworkLocation::GetPos(Name, &result);
                    ClosestSubSegment = UFG::RoadNetworkSegment::GetClosestSubSegment(RoadNetworkNode, Pos);
                    v45 = (unsigned __int8)RoadNetworkNode->mNumLanes - 1;
                    BeginT = UFG::RoadNetworkSubSegment::GetBeginT(ClosestSubSegment, 0);
                    v47 = UFG::RoadNetworkNode::GetPos(RoadNetworkNode, &v55, 0, BeginT);
                    v48 = (float)((float)((float)(this->m_vTargetingPosition.x - v47->x)
                                        * (float)(this->m_vTargetingPosition.x - v47->x))
                                + (float)((float)(this->m_vTargetingPosition.y - v47->y)
                                        * (float)(this->m_vTargetingPosition.y - v47->y)))
                        + (float)((float)(this->m_vTargetingPosition.z - v47->z)
                                * (float)(this->m_vTargetingPosition.z - v47->z));
                    v49 = UFG::RoadNetworkSubSegment::GetBeginT(ClosestSubSegment, v45);
                    v50 = UFG::RoadNetworkNode::GetPos(RoadNetworkNode, &v56, v45, v49);
                    v51 = v48 >= (float)((float)((float)((float)(this->m_vTargetingPosition.x - v50->x)
                                                       * (float)(this->m_vTargetingPosition.x - v50->x))
                                               + (float)((float)(this->m_vTargetingPosition.y - v50->y)
                                                       * (float)(this->m_vTargetingPosition.y - v50->y)))
                                       + (float)((float)(this->m_vTargetingPosition.z - v50->z)
                                               * (float)(this->m_vTargetingPosition.z - v50->z)))
                        ? v45
                        : 0;
                    Lane = UFG::RoadNetworkNode::GetLane(RoadNetworkNode, v51);
                    IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(p_mNext[8]);
                    if ( IsReversedInNode == UFG::RoadNetworkLane::IsReversedInNode(Lane)
                      && !p_mNext[20]
                      && *(float *)&m_pComponent[16].m_NameUID <= 1.0 )
                    {
                      v54 = this->m_pTargetingMap->m_Map.p[75];
                      if ( v54 )
                        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v54], m_pSimObject);
                      return;
                    }
                  }
                  size = closeVehiclesList.size;
                  goto LABEL_107;
                }
                v38 = (unsigned int)m_pSimObject[1].vfptr;
                v39 = m_pSimObject->m_Components.size;
                if ( v38 < v39 )
                {
                  do
                  {
                    v37 = (__int64)&m_pSimObject->m_Components.p[v38];
                    if ( (*(_DWORD *)(v37 + 8) & 0xFE000000) == (UFG::RoadSpaceComponent::_TypeUID & 0xFE000000)
                      && (UFG::RoadSpaceComponent::_TypeUID & ~*(_DWORD *)(v37 + 8) & 0x1FFFFFF) == 0 )
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
            if ( v23 < 0 )
            {
              v27 = m_pSimObject->m_Components.p[30].m_pComponent;
              goto LABEL_73;
            }
            if ( (v23 & 0x2000) != 0 )
            {
              v28 = (unsigned int)m_pSimObject[1].vfptr;
              v29 = m_pSimObject->m_Components.size;
              if ( v28 < v29 )
              {
                do
                {
                  v26 = (__int64)&m_pSimObject->m_Components.p[v28];
                  if ( (*(_DWORD *)(v26 + 8) & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                    && (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) == 0 )
                  {
                    goto LABEL_56;
                  }
                }
                while ( ++v28 < v29 );
              }
            }
            else
            {
              if ( (v23 & 0x1000) == 0 )
              {
                v27 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::VehicleOccupantComponent::_TypeUID);
                goto LABEL_73;
              }
              v30 = (unsigned int)m_pSimObject[1].vfptr;
              v31 = m_pSimObject->m_Components.size;
              if ( v30 < v31 )
              {
                do
                {
                  v26 = (__int64)&m_pSimObject->m_Components.p[v30];
                  if ( (*(_DWORD *)(v26 + 8) & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
                    && (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) == 0 )
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
          v15 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          if ( (*(_DWORD *)(v15 + 8) & 0xFE000000) == (v8 & 0xFE000000) && (v8 & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF) == 0 )
            break;
          if ( ++vfptr >= v14 )
            goto LABEL_13;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, v8);
          v8 = UFG::AiDriverComponent::_TypeUID;
          v9 = UFG::PhysicsMoverInterface::_TypeUID;
          goto LABEL_33;
        }
        v16 = (unsigned int)m_pSimObject[1].vfptr;
        v17 = m_pSimObject->m_Components.size;
        if ( v16 >= v17 )
          goto LABEL_13;
        while ( 1 )
        {
          v15 = (__int64)&m_pSimObject->m_Components.p[v16];
          if ( (*(_DWORD *)(v15 + 8) & 0xFE000000) == (v8 & 0xFE000000) && (v8 & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF) == 0 )
            break;
          if ( ++v16 >= v17 )
            goto LABEL_13;
        }
      }
      m_pComponent = *(UFG::SimComponent **)v15;
      goto LABEL_33;
    }
  }
}

// File Line: 365
// RVA: 0x579E60
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::updateTargets(
        UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::SimComponent *m_pPointer; // rax
  float v3; // xmm0_4
  float m_fMaximumTargetDistanceSquared; // xmm0_4
  float m_fMinimumTargetDistanceSquared; // xmm3_4
  UFG::SimComponent *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  unsigned __int8 v10; // cl
  UFG::TargetingSimObject *v11; // rcx
  UFG::RigidBodyComponent *m_pRigidBodyComponent; // rbx
  UFG::SimObject *m_pSimObject; // rdx
  unsigned __int8 v14; // cl
  unsigned __int8 v15; // cl
  unsigned __int64 v16; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  UFG::qFixedArray<UFG::ClosePhysicalTarget,1> closePhysicalMeleeAttackableList; // [rsp+48h] [rbp-B8h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,5> closePropsList; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePickupsList; // [rsp+90h] [rbp-70h] BYREF
  UFG::qFixedArray<UFG::ClosePhysicalTarget,2> closePhysicalDodgeableList; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qFixedArray<UFG::ClosePhysicalTarget,10> filteredClosePhysicalTargetsList; // [rsp+F0h] [rbp-10h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,20> filteredCloseVehiclesList; // [rsp+1A0h] [rbp+A0h] BYREF
  UFG::qMatrix44 mat; // [rsp+250h] [rbp+150h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,80> filteredClosePedsList; // [rsp+290h] [rbp+190h] BYREF
  UFG::qFixedArray<UFG::CloseTarget,100> closeTargetsList; // [rsp+520h] [rbp+420h] BYREF
  UFG::qFixedArray<UFG::CloseTarget,100> filteredCloseTargetsList; // [rsp+2470h] [rbp+2370h] BYREF

  closeTargetsList.size = 0;
  filteredClosePedsList.size = 0;
  filteredCloseTargetsList.size = 0;
  filteredClosePickupsList.size = 0;
  closePropsList.size = 0;
  filteredCloseVehiclesList.size = 0;
  filteredClosePhysicalTargetsList.size = 0;
  closePhysicalDodgeableList.size = 0;
  closePhysicalMeleeAttackableList.size = 0;
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
    &closeTargetsList,
    this->m_pSimObject,
    &this->m_vTargetingPosition,
    m_fMinimumTargetDistanceSquared);
  UFG::TargetingSystemPedBaseComponent::filterCloseTargets(
    &closeTargetsList,
    &this->m_CachedPedsList,
    &filteredClosePedsList,
    &filteredClosePickupsList,
    &closePropsList,
    &filteredCloseVehiclesList,
    &filteredCloseTargetsList);
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
  UFG::TargetingSystemPedNPCCombatantComponent::updateFocusTarget(this);
  UFG::TargetingSystemPedBaseComponent::updateClosestPedTarget(this, &filteredClosePedsList);
  v10 = this->m_pTargetingMap->m_Map.p[58];
  if ( v10 )
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v10], 0i64);
  UFG::TargetingSystemPedBaseComponent::updateGroupTargets(this);
  UFG::TargetingSystemPedBaseComponent::updatePickupTarget(this, &filteredClosePickupsList);
  UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(this);
  UFG::TargetingSystemPedNPCBaseComponent::updatePropTarget(this, &closePropsList);
  v11 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[49]];
  if ( !v11->m_pTarget.m_pPointer || !v11->m_bLock )
  {
    if ( filteredClosePhysicalTargetsList.size
      && (m_pRigidBodyComponent = filteredClosePhysicalTargetsList.p[0].m_pRigidBodyComponent,
          UFG::RigidBody::GetTransform(filteredClosePhysicalTargetsList.p[0].m_pRigidBodyComponent, &mat),
          (m_pSimObject = m_pRigidBodyComponent->m_pSimObject) != 0i64) )
    {
      v14 = this->m_pTargetingMap->m_Map.p[49];
      if ( v14 )
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v14], m_pSimObject);
    }
    else
    {
      v15 = this->m_pTargetingMap->m_Map.p[49];
      if ( v15 )
      {
        v16 = v15;
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v16], 0i64);
        m_pTargets = this->m_pTargets;
        if ( m_pTargets[v16].m_bLock )
          m_pTargets[v16].m_bLock = 0;
      }
    }
  }
  UFG::TargetingSystemBaseComponent::updateMySpawnPointTarget(this);
}

// File Line: 423
// RVA: 0x55CDB0
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::Update(
        UFG::TargetingSystemPedNPCCombatantComponent *this,
        float delta_sec)
{
  UFG::AttackRightsComponent *m_pSimComponent; // rcx
  UFG::HasAttackRequestNode *CurrentAttacker; // rax
  UFG::SimObject *v5; // rdx
  unsigned __int8 v6; // cl
  __int64 v7; // rbx

  UFG::TargetingSystemPedBaseComponent::UpdateCommon((UFG::TargetingSystemPedNPCCombatantComponent *)((char *)this - 64));
  UFG::TargetingSystemPedNPCBaseComponent::updateTargetingIntentions((UFG::TargetingSystemPedNPCCombatantComponent *)((char *)this - 64));
  UFG::TargetingSystemPedNPCCombatantComponent::updateFocusTargetSubTargetingLocation((UFG::TargetingSystemPedNPCCombatantComponent *)((char *)this - 64));
  if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent> *))this[-1].UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>::mPrev[11].mPrev)(&this[-1].UFG::qNode<UFG::TargetingSystemPedNPCCombatantComponent,UFG::TargetingSystemPedNPCCombatantComponent>) )
    UFG::TargetingSystemPedNPCCombatantComponent::updateTargets((UFG::TargetingSystemPedNPCCombatantComponent *)((char *)this - 64));
  m_pSimComponent = (UFG::AttackRightsComponent *)this->m_pAIActionTreeComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    CurrentAttacker = UFG::AttackRightsComponent::GetCurrentAttacker(m_pSimComponent, eATTACK_TYPE_MELEE);
    v5 = CurrentAttacker ? (UFG::SimObject *)UFG::HasAttackRequestNode::GetSimObject(CurrentAttacker) : 0i64;
    v6 = *(_BYTE *)(*(_QWORD *)&this->m_Flags + 85i64);
    if ( v6 )
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(*(_QWORD *)&this->m_TypeUID + 56i64 * v6), v5);
  }
  v7 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_Flags + 30i64) + *(_QWORD *)&this->m_TypeUID + 40);
  if ( v7 != *(_QWORD *)&this->m_vTargetingPosition.z )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))this->m_pTransformNodeComponent.mNext->mPrev[11].mPrev)(this->m_pTransformNodeComponent.mNext);
    *(_QWORD *)&this->m_vTargetingPosition.z = v7;
  }
  LOBYTE(this->m_pInterestPointUserComponent.m_Changed) = 0;
}

// File Line: 461
// RVA: 0x154CD10
__int64 UFG::_dynamic_initializer_for__symSubTargetingLocationCoverPopoutLeft__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Targeting-SubTargetingProfiles-Locations-CharacterCoverPopoutLeft", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symSubTargetingLocationCoverPopoutLeft, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symSubTargetingLocationCoverPopoutLeft__);
}

// File Line: 462
// RVA: 0x154CD50
__int64 UFG::_dynamic_initializer_for__symSubTargetingLocationCoverPopoutRight__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Targeting-SubTargetingProfiles-Locations-CharacterCoverPopoutRight", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symSubTargetingLocationCoverPopoutRight, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symSubTargetingLocationCoverPopoutRight__);
}

// File Line: 463
// RVA: 0x154CD90
__int64 UFG::_dynamic_initializer_for__symSubTargetingLocationCoverPopoutTop__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Targeting-SubTargetingProfiles-Locations-CharacterCoverPopoutTop", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symSubTargetingLocationCoverPopoutTop, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symSubTargetingLocationCoverPopoutTop__);
}

// File Line: 466
// RVA: 0x569D20
char __fastcall UFG::TargetingSystemPedNPCCombatantComponent::hasLineOfSightToFocus(
        UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::SimObject *m_pSimObject; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // r11
  __int64 v7; // rbx
  unsigned int v8; // ecx
  unsigned int v9; // r9d

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[19].m_pComponent;
      goto LABEL_23;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        p = m_pSimObject->m_Components.p;
        while ( 1 )
        {
          v7 = vfptr;
          if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::AIActionTreeComponent::_TypeUID & 0xFE000000)
            && (UFG::AIActionTreeComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++vfptr >= size )
            goto LABEL_14;
        }
LABEL_13:
        m_pComponent = p[v7].m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::AIActionTreeComponent::_TypeUID);
        goto LABEL_23;
      }
      v8 = (unsigned int)m_pSimObject[1].vfptr;
      v9 = m_pSimObject->m_Components.size;
      if ( v8 < v9 )
      {
        p = m_pSimObject->m_Components.p;
        do
        {
          v7 = v8;
          if ( (p[v8].m_TypeUID & 0xFE000000) == (UFG::AIActionTreeComponent::_TypeUID & 0xFE000000)
            && (UFG::AIActionTreeComponent::_TypeUID & ~p[v8].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_13;
          }
        }
        while ( ++v8 < v9 );
      }
    }
LABEL_14:
    m_pComponent = 0i64;
    goto LABEL_23;
  }
  m_pComponent = m_pSimObject->m_Components.p[19].m_pComponent;
LABEL_23:
  if ( m_pComponent )
  {
    if ( (_S33_0 & 1) == 0 )
    {
      _S33_0 |= 1u;
      actionID.mUID = UFG::qStringHashUpper32("LineOfSightToFocus_KEY", -1);
    }
    if ( ActionController::IsPlaying((ActionController *)&m_pComponent[3].m_TypeUID, &actionID, 0xFFFFFFFF, 1) )
      return 1;
  }
  return 0;
}

// File Line: 482
// RVA: 0x572C90
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::updateFocusTargetSubTargetingLocation(
        UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::qBaseTreeRB *v2; // rsi
  UFG::SubTargetingLocation *v3; // rax
  UFG::SimObject *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // edx
  unsigned int size; // r8d
  __int64 v8; // rbx
  UFG::SimComponent *ComponentOfType; // rbx
  unsigned int v10; // edx
  unsigned int v11; // r8d
  unsigned int v12; // edx
  unsigned int v13; // r8d
  unsigned int v14; // edx
  unsigned int v15; // r8d
  unsigned int mUID; // edx
  UFG::SubTargetingLocation *m_pFocusTargetSubTargetingLocationOverride; // rax
  UFG::SubTargetingLocation *m_pFocusTargetSubTargetingLocation; // rcx

  if ( this->m_pFocusTargetSubTargetingLocationOverride )
    goto LABEL_52;
  v2 = 0i64;
  if ( UFG::gNullQSymbol.mUID == -1 )
  {
    this->m_pFocusTargetSubTargetingLocation = 0i64;
  }
  else
  {
    v3 = UFG::gNullQSymbol.mUID
       ? (UFG::SubTargetingLocation *)UFG::qBaseTreeRB::Get(
                                        &UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree,
                                        UFG::gNullQSymbol.mUID)
       : 0i64;
    this->m_pFocusTargetSubTargetingLocation = v3;
  }
  m_pPointer = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
  if ( !m_pPointer )
    goto LABEL_52;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    vfptr = (unsigned int)m_pPointer[1].vfptr;
    size = m_pPointer->m_Components.size;
    if ( vfptr < size )
    {
      v8 = (__int64)&m_pPointer->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
           || (UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v8 += 16i64;
        if ( vfptr >= size )
          goto LABEL_15;
      }
LABEL_16:
      ComponentOfType = *(UFG::SimComponent **)v8;
      goto LABEL_39;
    }
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      v12 = (unsigned int)m_pPointer[1].vfptr;
      v13 = m_pPointer->m_Components.size;
      if ( v12 < v13 )
      {
        v8 = (__int64)&m_pPointer->m_Components.p[v12];
        while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
             || (UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v12;
          v8 += 16i64;
          if ( v12 >= v13 )
          {
            ComponentOfType = 0i64;
            goto LABEL_39;
          }
        }
        goto LABEL_16;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
        goto LABEL_39;
      }
      v14 = (unsigned int)m_pPointer[1].vfptr;
      v15 = m_pPointer->m_Components.size;
      if ( v14 < v15 )
      {
        v8 = (__int64)&m_pPointer->m_Components.p[v14];
        while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
             || (UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v14;
          v8 += 16i64;
          if ( v14 >= v15 )
          {
            ComponentOfType = 0i64;
            goto LABEL_39;
          }
        }
        goto LABEL_16;
      }
    }
  }
  else
  {
    v10 = (unsigned int)m_pPointer[1].vfptr;
    v11 = m_pPointer->m_Components.size;
    if ( v10 < v11 )
    {
      v8 = (__int64)&m_pPointer->m_Components.p[v10];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
           || (UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v10;
        v8 += 16i64;
        if ( v10 >= v11 )
        {
          ComponentOfType = 0i64;
          goto LABEL_39;
        }
      }
      goto LABEL_16;
    }
  }
LABEL_15:
  ComponentOfType = 0i64;
LABEL_39:
  if ( ComponentOfType
    && UFG::AICoverComponent::IsInCover((UFG::AICoverComponent *)ComponentOfType)
    && !UFG::TargetingSystemPedNPCCombatantComponent::hasLineOfSightToFocus(this) )
  {
    switch ( LODWORD(ComponentOfType[2].vfptr) )
    {
      case 1:
        mUID = UFG::symSubTargetingLocationCoverPopoutLeft.mUID;
        break;
      case 2:
        mUID = UFG::symSubTargetingLocationCoverPopoutRight.mUID;
        break;
      case 3:
        mUID = UFG::symSubTargetingLocationCoverPopoutTop.mUID;
        break;
      default:
        goto LABEL_52;
    }
    if ( mUID != -1 && mUID )
      v2 = UFG::qBaseTreeRB::Get(&UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree, mUID);
    this->m_pFocusTargetSubTargetingLocation = (UFG::SubTargetingLocation *)v2;
  }
LABEL_52:
  m_pFocusTargetSubTargetingLocationOverride = this->m_pFocusTargetSubTargetingLocationOverride;
  if ( m_pFocusTargetSubTargetingLocationOverride )
    this->m_pFocusTargetSubTargetingLocation = m_pFocusTargetSubTargetingLocationOverride;
  m_pFocusTargetSubTargetingLocation = this->m_pFocusTargetSubTargetingLocation;
  if ( m_pFocusTargetSubTargetingLocation )
  {
    if ( m_pFocusTargetSubTargetingLocation != this->m_pLastFocusTargetSubTargetingLocation )
    {
      *(float *)&this->m_pAimingBaseComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev = m_pFocusTargetSubTargetingLocation->m_fAccuracyPenalty + *(float *)&this->m_pAimingBaseComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
      this->m_pLastFocusTargetSubTargetingLocation = this->m_pFocusTargetSubTargetingLocation;
    }
  }
}

