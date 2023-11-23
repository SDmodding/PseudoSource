// File Line: 36
// RVA: 0x14AED50
__int64 UFG::_dynamic_initializer_for__FactionStandingSym_ALLIED__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ALLIED", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&FactionStandingSym_ALLIED, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__FactionStandingSym_ALLIED__);
}

// File Line: 40
// RVA: 0x14AF210
__int64 UFG::_dynamic_initializer_for__FactionSym_NETWORK_TEAM_1__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("NETWORK_TEAM_1", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::FactionSym_NETWORK_TEAM_1, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__FactionSym_NETWORK_TEAM_1__);
}

// File Line: 215
// RVA: 0x32E1B0
void __fastcall UFG::FactionInterface::FactionInterface(UFG::FactionInterface *this)
{
  UFG::FactionInterface::InternalReset(this);
}

// File Line: 240
// RVA: 0x3367D0
void __fastcall UFG::FactionInterface::~FactionInterface(UFG::FactionInterface *this)
{
  gDebugFactionRender = 0;
  gDebugFactionSelected = 0;
}

// File Line: 255
// RVA: 0x359610
// attributes: thunk
UFG::GameStatTracker *__fastcall UFG::FactionInterface::Get()
{
  return UFG::GameStatTracker::Instance();
}

// File Line: 282
// RVA: 0x382A00
// attributes: thunk
void __fastcall UFG::FactionInterface::Reset(UFG::FactionInterface *this)
{
  UFG::FactionInterface::InternalReset(this);
}

// File Line: 319
// RVA: 0x3694F0
void __fastcall UFG::FactionInterface::InternalReset(UFG::FactionInterface *this)
{
  UFG::FactionInterface *v1; // rax
  __int64 v2; // rdx
  UFG::eFactionStandingEnum *v3; // rdx
  __int64 v4; // r8
  UFG::eFactionStandingEnum *v5; // rax
  __int64 v6; // rax

  v1 = this;
  v2 = 95i64;
  do
  {
    *(_QWORD *)&v1->mStandings[0][0] = 0x100000001i64;
    *(_QWORD *)&v1->mStandings[0][2] = 0x100000001i64;
    *(_QWORD *)&v1->mStandings[0][4] = 0x100000001i64;
    v1 = (UFG::FactionInterface *)((char *)v1 + 64);
    *(_QWORD *)&v1[-1].mStandings[38][29] = 0x100000001i64;
    *(_QWORD *)&v1[-1].mStandings[38][31] = 0x100000001i64;
    *(_QWORD *)&v1[-1].mStandings[38][33] = 0x100000001i64;
    *(_QWORD *)&v1[-1].mStandings[38][35] = 0x100000001i64;
    *(_QWORD *)&v1[-1].mStandings[38][37] = 0x100000001i64;
    --v2;
  }
  while ( v2 );
  v1->mStandings[0][0] = FACTIONSTANDING_INDIFFERENT;
  v3 = &this->mStandings[FACTION_LAW][FACTION_NETWORK_TEAM_1];
  *(_QWORD *)&this->mStandings[FACTION_PLAYER][FACTION_LAW] = FACTIONSTANDING_INDIFFERENT;
  this->mStandings[FACTION_LAW][FACTION_PLAYER] = FACTIONSTANDING_INDIFFERENT;
  this->mStandings[FACTION_PLAYER][FACTION_TRIAD_GENERIC] = FACTIONSTANDING_HOSTILE;
  v4 = 8i64;
  this->mStandings[FACTION_TRIAD_GENERIC][FACTION_PLAYER] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_TRIAD_WINSTON][FACTION_PLAYER] = FACTIONSTANDING_ALLIED;
  this->mStandings[FACTION_PLAYER][FACTION_TRIAD_LEE] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_TRIAD_LEE][FACTION_PLAYER] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_PLAYER][FACTION_TRIAD_18K] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_TRIAD_18K][FACTION_PLAYER] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_PLAYER][FACTION_AMBIENT_AGGRESSIVE] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_AMBIENT_AGGRESSIVE][FACTION_PLAYER] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_PLAYER][FACTION_HOSTILE_SPECIAL_1] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_HOSTILE_SPECIAL_1][FACTION_PLAYER] = FACTIONSTANDING_HOSTILE;
  *(_QWORD *)&this->mStandings[FACTION_PLAYER][FACTION_HOSTILE_SPECIAL_2] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_HOSTILE_SPECIAL_2][FACTION_PLAYER] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_ALLIED_SPECIAL_1][FACTION_PLAYER] = FACTIONSTANDING_ALLIED;
  this->mStandings[FACTION_PLAYER][FACTION_ALLIED_SPECIAL_2] = FACTIONSTANDING_ALLIED;
  this->mStandings[FACTION_ALLIED_SPECIAL_2][FACTION_PLAYER] = FACTIONSTANDING_ALLIED;
  this->mStandings[FACTION_TRIAD_WINSTON][FACTION_TRIAD_LEE] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_TRIAD_LEE][FACTION_TRIAD_WINSTON] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_TRIAD_WINSTON][FACTION_TRIAD_18K] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_TRIAD_18K][FACTION_TRIAD_WINSTON] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_TRIAD_DOGBOYS][FACTION_PLAYER] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_PLAYER][FACTION_TRIAD_DOGBOYS] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_TRIAD_DOGBOYS][FACTION_TRIAD_WINSTON] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_TRIAD_WINSTON][FACTION_TRIAD_DOGBOYS] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_HOSTILE_SPECIAL_1][FACTION_HOSTILE_SPECIAL_2] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_HOSTILE_SPECIAL_2][FACTION_HOSTILE_SPECIAL_1] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_HOSTILE_SPECIAL_1][FACTION_ALLIED_SPECIAL_1] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_ALLIED_SPECIAL_1][FACTION_HOSTILE_SPECIAL_1] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_HOSTILE_SPECIAL_1][FACTION_ALLIED_SPECIAL_2] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_ALLIED_SPECIAL_2][FACTION_HOSTILE_SPECIAL_1] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_HOSTILE_SPECIAL_2][FACTION_ALLIED_SPECIAL_1] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_ALLIED_SPECIAL_1][FACTION_HOSTILE_SPECIAL_2] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_HOSTILE_SPECIAL_2][FACTION_ALLIED_SPECIAL_2] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_ALLIED_SPECIAL_2][FACTION_HOSTILE_SPECIAL_2] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_ALLIED_SPECIAL_1][FACTION_ALLIED_SPECIAL_2] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_ALLIED_SPECIAL_2][FACTION_ALLIED_SPECIAL_1] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_LAW_HOSTILE][FACTION_LAW] = FACTIONSTANDING_HOSTILE;
  this->mStandings[FACTION_LAW][FACTION_LAW_HOSTILE] = FACTIONSTANDING_HOSTILE;
  v5 = &this->mStandings[FACTION_NETWORK_TEAM_1][FACTION_LAW];
  do
  {
    *((_DWORD *)v5 - 1) = 2;
    *((_DWORD *)v3 - 39) = 2;
    *v5 = FACTIONSTANDING_ALLIED;
    *v3 = FACTIONSTANDING_ALLIED;
    *((_DWORD *)v5 + 7) = 2;
    *((_DWORD *)v3 + 273) = 2;
    *((_DWORD *)v5 + 10) = 2;
    *((_DWORD *)v3 + 390) = 2;
    *(_QWORD *)(v5 + 21) = 0x200000002i64;
    *(_QWORD *)(v5 + 23) = 0x200000002i64;
    *(_QWORD *)(v5 + 25) = 0x200000002i64;
    *(_QWORD *)(v5 + 27) = 0x200000002i64;
    v5 += 39;
    ++v3;
    --v4;
  }
  while ( v4 );
  v6 = 39i64;
  do
  {
    this->mStandings[0][0] = FACTIONSTANDING_ALLIED;
    this = (UFG::FactionInterface *)((char *)this + 0xA0);
    --v6;
  }
  while ( v6 );
}

// File Line: 408
// RVA: 0x387BE0
void __fastcall UFG::FactionInterface::SetStanding(
        UFG::FactionInterface *this,
        UFG::eFactionClassEnum source,
        UFG::eFactionClassEnum target,
        UFG::eFactionStandingEnum standing)
{
  this->mStandings[source][target] = standing;
  this->mStandings[target][source] = standing;
}

// File Line: 457
// RVA: 0x35F580
__int64 __fastcall UFG::FactionInterface::GetFaction(UFG::FactionInterface *this, UFG::SimObjectCVBase *pObject)
{
  signed __int16 m_Flags; // cx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax

  if ( pObject
    && ((m_Flags = pObject->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(pObject))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             pObject,
                                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                             pObject,
                                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return (unsigned int)ComponentOfTypeHK->m_eFactionClass;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 471
// RVA: 0x3862D0
void __fastcall UFG::FactionInterface::SetFaction(
        UFG::FactionInterface *this,
        UFG::SimObjectCVBase *pObject,
        UFG::qSymbol *newFactionSymbol)
{
  UFG::eFactionClassEnum v5; // ebp
  signed __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax
  signed __int16 v8; // cx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rsi
  UFG::qStaticSymbol *v12; // rbx
  UFG::qPropertySet *WritableProperties; // rax
  char *v14; // rax

  v5 = (unsigned int)UFG::FactionInterface::MapSymbolToFaction(newFactionSymbol);
  if ( pObject )
  {
    m_Flags = pObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(pObject);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          pObject,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          pObject,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      UFG::SimObjectCharacterPropertiesComponent::SetFactionClass(ComponentOfTypeHK, v5);
    v8 = pObject->m_Flags;
    if ( (v8 & 0x4000) != 0 )
    {
      m_pComponent = pObject->m_Components.p[22].m_pComponent;
    }
    else if ( v8 >= 0 )
    {
      if ( (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(pObject, UFG::AIEntityComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(pObject, UFG::AIEntityComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = pObject->m_Components.p[22].m_pComponent;
    }
    if ( m_pComponent && (m_pComponent->m_Flags & 3) == 1 )
      UFG::NearbyCharacterManager::RemoveCharacter(
        UFG::NearbyCharacterManager::s_pInstance,
        (UFG::AIEntityComponent *)m_pComponent);
  }
  else
  {
    m_pComponent = 0i64;
  }
  m_pSceneObj = pObject->m_pSceneObj;
  if ( m_pSceneObj )
  {
    v12 = UFG::FactionInterface::MapFactionToSymbol(this, v5);
    WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(m_pSceneObj);
    UFG::qPropertySet::Set<UFG::qSymbol>(WritableProperties, (UFG::qArray<unsigned long,0> *)&qSymbol_FactionClass, v12);
  }
  else
  {
    v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pObject->m_Name);
    UFG::qPrintf("This sim object does not have a Scene object!  (%s)\n", v14);
  }
  if ( m_pComponent )
  {
    if ( (m_pComponent->m_Flags & 3) == 1 )
      UFG::NearbyCharacterManager::AddCharacter(
        UFG::NearbyCharacterManager::s_pInstance,
        (UFG::AIEntityComponent *)m_pComponent);
  }
}

// File Line: 530
// RVA: 0x362650
__int64 __fastcall UFG::FactionInterface::GetStanding(
        UFG::FactionInterface *this,
        UFG::SimObjectCVBase *pSource,
        UFG::SimObjectCVBase *pTarget)
{
  __int64 Faction; // rbx

  Faction = (int)UFG::FactionInterface::GetFaction(this, pSource);
  return (unsigned int)this->mStandings[Faction][(int)UFG::FactionInterface::GetFaction(this, pTarget)];
}

// File Line: 546
// RVA: 0x3626A0
__int64 __fastcall UFG::FactionInterface::GetStanding(
        UFG::FactionInterface *this,
        UFG::eFactionClassEnum source,
        UFG::eFactionClassEnum target)
{
  return (unsigned int)this->mStandings[source][target];
}

// File Line: 559
// RVA: 0x36DBA0
__int64 __fastcall UFG::FactionInterface::MapSymbolToFaction(UFG::qSymbol *symbol)
{
  unsigned int mUID; // edx
  __int64 result; // rax

  mUID = symbol->mUID;
  result = 17i64;
  if ( symbol->mUID == UFG::FactionSym_INVALID.mUID )
    return 0i64;
  if ( mUID == UFG::FactionSym_INDIFFERENT.mUID )
    return 1i64;
  if ( mUID == UFG::FactionSym_PLAYER.mUID )
    return 2i64;
  if ( mUID == UFG::FactionSym_LAW.mUID )
    return 3i64;
  if ( mUID == UFG::FactionSym_TRIAD_WINSTON.mUID )
    return 4i64;
  if ( mUID == UFG::FactionSym_TRIAD_DOGEYES.mUID )
    return 5i64;
  if ( mUID == UFG::FactionSym_TRIAD_SONNY.mUID )
    return 6i64;
  if ( mUID == UFG::FactionSym_TRIAD_JIIANG.mUID )
    return 7i64;
  if ( mUID == UFG::FactionSym_TRIAD_CHEUK.mUID )
    return 8i64;
  if ( mUID == UFG::FactionSym_TRIAD_TWOCHIN.mUID )
    return 9i64;
  if ( mUID == UFG::FactionSym_TRIAD_GENERIC.mUID )
    return 10i64;
  if ( mUID == UFG::FactionSym_TRIAD_WATERSTREET.mUID )
    return 11i64;
  if ( mUID == UFG::FactionSym_TRIAD_18K.mUID )
    return 12i64;
  if ( mUID == UFG::FactionSym_TRIAD_DOGBOYS.mUID )
    return 13i64;
  if ( mUID == UFG::FactionSym_TRIAD_SUNONYEE.mUID )
    return 14i64;
  if ( mUID == UFG::FactionSym_TRIAD_LEE.mUID )
    return 15i64;
  if ( mUID == UFG::FactionSym_BOUNCER.mUID )
    return 16i64;
  if ( mUID != UFG::FactionSym_INNOCENT.mUID )
  {
    if ( mUID == UFG::FactionSym_STUDENT.mUID )
    {
      return 18i64;
    }
    else if ( mUID == UFG::FactionSym_AMBIENT_AGGRESSIVE.mUID )
    {
      return 19i64;
    }
    else if ( mUID == UFG::FactionSym_AMBIENT_GROUP_1.mUID )
    {
      return 20i64;
    }
    else if ( mUID == UFG::FactionSym_AMBIENT_GROUP_2.mUID )
    {
      return 21i64;
    }
    else if ( mUID == UFG::FactionSym_AMBIENT_GROUP_3.mUID )
    {
      return 22i64;
    }
    else if ( mUID == UFG::FactionSym_AMBIENT_GROUP_4.mUID )
    {
      return 23i64;
    }
    else if ( mUID == UFG::FactionSym_NETWORK_TEAM_1.mUID )
    {
      return 24i64;
    }
    else if ( mUID == UFG::FactionSym_NETWORK_TEAM_2.mUID )
    {
      return 25i64;
    }
    else if ( mUID == UFG::FactionSym_NETWORK_TEAM_3.mUID )
    {
      return 26i64;
    }
    else if ( mUID == UFG::FactionSym_NETWORK_TEAM_4.mUID )
    {
      return 27i64;
    }
    else if ( mUID == UFG::FactionSym_NETWORK_TEAM_5.mUID )
    {
      return 28i64;
    }
    else if ( mUID == UFG::FactionSym_NETWORK_TEAM_6.mUID )
    {
      return 29i64;
    }
    else if ( mUID == UFG::FactionSym_NETWORK_TEAM_7.mUID )
    {
      return 30i64;
    }
    else if ( mUID == UFG::FactionSym_NETWORK_TEAM_8.mUID )
    {
      return 31i64;
    }
    else if ( mUID == UFG::FactionSym_HOSTILE_SPECIAL_1.mUID )
    {
      return 32i64;
    }
    else if ( mUID == UFG::FactionSym_HOSTILE_SPECIAL_2.mUID )
    {
      return 33i64;
    }
    else if ( mUID == UFG::FactionSym_ALLIED_SPECIAL_1.mUID )
    {
      return 34i64;
    }
    else if ( mUID == UFG::FactionSym_ALLIED_SPECIAL_2.mUID )
    {
      return 35i64;
    }
    else if ( mUID == UFG::FactionSym_LAW_HOSTILE.mUID )
    {
      return 36i64;
    }
    else if ( mUID == UFG::FactionSym_ROOSTER1.mUID )
    {
      return 37i64;
    }
    else if ( mUID == UFG::FactionSym_ROOSTER2.mUID )
    {
      return 38i64;
    }
  }
  return result;
}

// File Line: 574
// RVA: 0x36DDD0
signed __int64 __fastcall UFG::FactionInterface::MapSymbolToStanding(UFG::qSymbol *symbol)
{
  unsigned int mUID; // eax
  unsigned int v2; // edx

  mUID = symbol->mUID;
  v2 = 0;
  if ( symbol->mUID != FactionStandingSym_ALLIED.mUID )
  {
    if ( mUID == FactionStandingSym_INDIFFERENT.mUID )
      return 1i64;
    if ( mUID == FactionStandingSym_HOSTILE.mUID )
      return 2i64;
    if ( mUID == FactionStandingSym_SCARED.mUID )
      return 3;
  }
  return v2;
}

// File Line: 589
// RVA: 0x36D980
UFG::qStaticSymbol *__fastcall UFG::FactionInterface::MapFactionToSymbol(
        UFG::FactionInterface *this,
        UFG::eFactionClassEnum faction)
{
  __int64 v3[40]; // [rsp+0h] [rbp-100h]

  v3[0] = (__int64)&UFG::FactionSym_INVALID;
  v3[1] = (__int64)&UFG::FactionSym_INDIFFERENT;
  v3[2] = (__int64)&UFG::FactionSym_PLAYER;
  v3[3] = (__int64)&UFG::FactionSym_LAW;
  v3[4] = (__int64)&UFG::FactionSym_TRIAD_WINSTON;
  v3[5] = (__int64)&UFG::FactionSym_TRIAD_DOGEYES;
  v3[6] = (__int64)&UFG::FactionSym_TRIAD_SONNY;
  v3[7] = (__int64)&UFG::FactionSym_TRIAD_JIIANG;
  v3[8] = (__int64)&UFG::FactionSym_TRIAD_CHEUK;
  v3[9] = (__int64)&UFG::FactionSym_TRIAD_TWOCHIN;
  v3[10] = (__int64)&UFG::FactionSym_TRIAD_GENERIC;
  v3[11] = (__int64)&UFG::FactionSym_TRIAD_WATERSTREET;
  v3[12] = (__int64)&UFG::FactionSym_TRIAD_18K;
  v3[13] = (__int64)&UFG::FactionSym_TRIAD_DOGBOYS;
  v3[14] = (__int64)&UFG::FactionSym_TRIAD_SUNONYEE;
  v3[15] = (__int64)&UFG::FactionSym_TRIAD_LEE;
  v3[16] = (__int64)&UFG::FactionSym_BOUNCER;
  v3[17] = (__int64)&UFG::FactionSym_INNOCENT;
  v3[18] = (__int64)&UFG::FactionSym_STUDENT;
  v3[19] = (__int64)&UFG::FactionSym_AMBIENT_AGGRESSIVE;
  v3[20] = (__int64)&UFG::FactionSym_AMBIENT_GROUP_1;
  v3[21] = (__int64)&UFG::FactionSym_AMBIENT_GROUP_2;
  v3[22] = (__int64)&UFG::FactionSym_AMBIENT_GROUP_3;
  v3[23] = (__int64)&UFG::FactionSym_AMBIENT_GROUP_4;
  v3[24] = (__int64)&UFG::FactionSym_NETWORK_TEAM_1;
  v3[25] = (__int64)&UFG::FactionSym_NETWORK_TEAM_2;
  v3[26] = (__int64)&UFG::FactionSym_NETWORK_TEAM_3;
  v3[27] = (__int64)&UFG::FactionSym_NETWORK_TEAM_4;
  v3[28] = (__int64)&UFG::FactionSym_NETWORK_TEAM_5;
  v3[29] = (__int64)&UFG::FactionSym_NETWORK_TEAM_6;
  v3[30] = (__int64)&UFG::FactionSym_NETWORK_TEAM_7;
  v3[31] = (__int64)&UFG::FactionSym_NETWORK_TEAM_8;
  v3[32] = (__int64)&UFG::FactionSym_HOSTILE_SPECIAL_1;
  v3[33] = (__int64)&UFG::FactionSym_HOSTILE_SPECIAL_2;
  v3[34] = (__int64)&UFG::FactionSym_ALLIED_SPECIAL_1;
  v3[35] = (__int64)&UFG::FactionSym_ALLIED_SPECIAL_2;
  v3[36] = (__int64)&UFG::FactionSym_LAW_HOSTILE;
  v3[37] = (__int64)&UFG::FactionSym_ROOSTER1;
  v3[38] = (__int64)&UFG::FactionSym_ROOSTER2;
  return (UFG::qStaticSymbol *)v3[faction];
}

// File Line: 602
// RVA: 0x36DB60
UFG::qStaticSymbol *__fastcall UFG::FactionInterface::MapStandingToSymbol(
        UFG::FactionInterface *this,
        UFG::eFactionStandingEnum standing)
{
  __int64 v3[5]; // [rsp+0h] [rbp-28h]

  v3[0] = (__int64)&FactionStandingSym_ALLIED;
  v3[1] = (__int64)&FactionStandingSym_INDIFFERENT;
  v3[2] = (__int64)&FactionStandingSym_HOSTILE;
  v3[3] = (__int64)&FactionStandingSym_SCARED;
  return (UFG::qStaticSymbol *)v3[standing];
}

