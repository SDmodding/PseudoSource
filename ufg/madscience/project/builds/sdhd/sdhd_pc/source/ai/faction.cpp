// File Line: 36
// RVA: 0x14AED50
__int64 UFG::_dynamic_initializer_for__FactionStandingSym_ALLIED__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ALLIED", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&FactionStandingSym_ALLIED, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__FactionStandingSym_ALLIED__);
}

// File Line: 40
// RVA: 0x14AF210
__int64 UFG::_dynamic_initializer_for__FactionSym_NETWORK_TEAM_1__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("NETWORK_TEAM_1", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::FactionSym_NETWORK_TEAM_1, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__FactionSym_NETWORK_TEAM_1__);
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
UFG::GameStatTracker *__fastcall UFG::FactionInterface::Get()
{
  return UFG::GameStatTracker::Instance();
}

// File Line: 282
// RVA: 0x382A00
void __fastcall UFG::FactionInterface::Reset(UFG::FactionInterface *this)
{
  UFG::FactionInterface::InternalReset(this);
}

// File Line: 319
// RVA: 0x3694F0
void __fastcall UFG::FactionInterface::InternalReset(UFG::FactionInterface *this)
{
  UFG::FactionInterface *v1; // rax
  signed __int64 v2; // rdx
  UFG::eFactionStandingEnum *v3; // rdx
  signed __int64 v4; // r8
  UFG::eFactionStandingEnum *v5; // rax
  signed __int64 v6; // rax

  v1 = this;
  v2 = 95i64;
  do
  {
    *(_QWORD *)&v1->mStandings[0][0] = 4294967297i64;
    *(_QWORD *)&v1->mStandings[0][2] = 4294967297i64;
    *(_QWORD *)&v1->mStandings[0][4] = 4294967297i64;
    v1 = (UFG::FactionInterface *)((char *)v1 + 64);
    *(_QWORD *)&v1[-1].mStandings[38][29] = 4294967297i64;
    *(_QWORD *)&v1[-1].mStandings[38][31] = 4294967297i64;
    *(_QWORD *)&v1[-1].mStandings[38][33] = 4294967297i64;
    *(_QWORD *)&v1[-1].mStandings[38][35] = 4294967297i64;
    *(_QWORD *)&v1[-1].mStandings[38][37] = 4294967297i64;
    --v2;
  }
  while ( v2 );
  v1->mStandings[0][0] = 1;
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
    *(_QWORD *)(v5 + 21) = 8589934594i64;
    *(_QWORD *)(v5 + 23) = 8589934594i64;
    *(_QWORD *)(v5 + 25) = 8589934594i64;
    *(_QWORD *)(v5 + 27) = 8589934594i64;
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
void __fastcall UFG::FactionInterface::SetStanding(UFG::FactionInterface *this, UFG::eFactionClassEnum source, UFG::eFactionClassEnum target, UFG::eFactionStandingEnum standing)
{
  this->mStandings[0][(signed int)target + 39i64 * (signed int)source] = standing;
  this->mStandings[0][(signed int)source + 39i64 * (signed int)target] = standing;
}

// File Line: 457
// RVA: 0x35F580
__int64 __fastcall UFG::FactionInterface::GetFaction(UFG::FactionInterface *this, UFG::SimObject *pObject)
{
  unsigned __int16 v2; // cx
  UFG::SimObjectCharacterPropertiesComponent *v3; // rax
  __int64 result; // rax

  if ( pObject
    && ((v2 = pObject->m_Flags, !((v2 >> 14) & 1)) ? ((v2 & 0x8000u) == 0 ? (!((v2 >> 13) & 1) ? (!((v2 >> 12) & 1) ? (v3 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(pObject, UFG::SimObjectCharacterPropertiesComponent::_TypeUID)) : (v3 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pObject, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v3 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pObject, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v3 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)pObject))) : (v3 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)pObject)),
        v3) )
  {
    result = (unsigned int)v3->m_eFactionClass;
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 471
// RVA: 0x3862D0
void __fastcall UFG::FactionInterface::SetFaction(UFG::FactionInterface *this, UFG::SimObject *pObject, UFG::qSymbol *newFactionSymbol)
{
  UFG::FactionInterface *v3; // r14
  UFG::SimObject *v4; // rbx
  UFG::eFactionClassEnum v5; // ebp
  unsigned __int16 v6; // dx
  UFG::SimObjectCharacterPropertiesComponent *v7; // rax
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rdi
  UFG::SimComponent *v10; // rax
  UFG::SceneObjectProperties *v11; // rsi
  UFG::qStaticSymbol *v12; // rbx
  UFG::qPropertySet *v13; // rax
  char *v14; // rax

  v3 = this;
  v4 = pObject;
  v5 = (unsigned int)UFG::FactionInterface::MapSymbolToFaction(newFactionSymbol);
  if ( v4 )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)v4);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)v4,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)v4,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             v4,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)v4);
    }
    if ( v7 )
      UFG::SimObjectCharacterPropertiesComponent::SetFactionClass(v7, v5);
    v8 = v4->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = v4->m_Components.p[22].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v4, UFG::AIEntityComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v4, UFG::AIEntityComponent::_TypeUID);
      }
      else
      {
        v10 = UFG::SimObject::GetComponentOfType(v4, UFG::AIEntityComponent::_TypeUID);
      }
      v9 = v10;
    }
    else
    {
      v9 = v4->m_Components.p[22].m_pComponent;
    }
    if ( v9 && (v9->m_Flags & 3) == 1 )
      UFG::NearbyCharacterManager::RemoveCharacter(
        UFG::NearbyCharacterManager::s_pInstance,
        (UFG::AIEntityComponent *)v9);
  }
  else
  {
    v9 = 0i64;
  }
  v11 = v4->m_pSceneObj;
  if ( v11 )
  {
    v12 = UFG::FactionInterface::MapFactionToSymbol(v3, v5);
    v13 = UFG::SceneObjectProperties::GetWritableProperties(v11);
    UFG::qPropertySet::Set<UFG::qSymbol>(v13, (UFG::qSymbol *)&qSymbol_FactionClass.mUID, (UFG::qSymbol *)&v12->mUID);
  }
  else
  {
    v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->m_Name);
    UFG::qPrintf("This sim object does not have a Scene object!  (%s)\n", v14);
  }
  if ( v9 )
  {
    if ( (v9->m_Flags & 3) == 1 )
      UFG::NearbyCharacterManager::AddCharacter(UFG::NearbyCharacterManager::s_pInstance, (UFG::AIEntityComponent *)v9);
  }
}

// File Line: 530
// RVA: 0x362650
__int64 __fastcall UFG::FactionInterface::GetStanding(UFG::FactionInterface *this, UFG::SimObject *pSource, UFG::SimObject *pTarget)
{
  UFG::SimObject *v3; // rdi
  UFG::FactionInterface *v4; // rsi
  __int64 v5; // rbx

  v3 = pTarget;
  v4 = this;
  v5 = (signed int)UFG::FactionInterface::GetFaction(this, pSource);
  return (unsigned int)v4->mStandings[0][(signed int)UFG::FactionInterface::GetFaction(v4, v3) + 39 * v5];
}

// File Line: 546
// RVA: 0x3626A0
__int64 __fastcall UFG::FactionInterface::GetStanding(UFG::FactionInterface *this, UFG::eFactionClassEnum source, UFG::eFactionClassEnum target)
{
  return (unsigned int)this->mStandings[0][(signed int)target + 39i64 * (signed int)source];
}

// File Line: 559
// RVA: 0x36DBA0
signed __int64 __fastcall UFG::FactionInterface::MapSymbolToFaction(UFG::qSymbol *symbol)
{
  unsigned int v1; // edx
  signed __int64 result; // rax

  v1 = symbol->mUID;
  result = 17i64;
  if ( symbol->mUID == UFG::FactionSym_INVALID.mUID )
    return 0i64;
  if ( v1 == UFG::FactionSym_INDIFFERENT.mUID )
    return 1i64;
  if ( v1 == UFG::FactionSym_PLAYER.mUID )
    return 2i64;
  if ( v1 == UFG::FactionSym_LAW.mUID )
    return 3i64;
  if ( v1 == UFG::FactionSym_TRIAD_WINSTON.mUID )
    return 4i64;
  if ( v1 == UFG::FactionSym_TRIAD_DOGEYES.mUID )
    return 5i64;
  if ( v1 == UFG::FactionSym_TRIAD_SONNY.mUID )
    return 6i64;
  if ( v1 == UFG::FactionSym_TRIAD_JIIANG.mUID )
    return 7i64;
  if ( v1 == UFG::FactionSym_TRIAD_CHEUK.mUID )
    return 8i64;
  if ( v1 == UFG::FactionSym_TRIAD_TWOCHIN.mUID )
    return 9i64;
  if ( v1 == UFG::FactionSym_TRIAD_GENERIC.mUID )
    return 10i64;
  if ( v1 == UFG::FactionSym_TRIAD_WATERSTREET.mUID )
    return 11i64;
  if ( v1 == UFG::FactionSym_TRIAD_18K.mUID )
    return 12i64;
  if ( v1 == UFG::FactionSym_TRIAD_DOGBOYS.mUID )
    return 13i64;
  if ( v1 == UFG::FactionSym_TRIAD_SUNONYEE.mUID )
    return 14i64;
  if ( v1 == UFG::FactionSym_TRIAD_LEE.mUID )
    return 15i64;
  if ( v1 == UFG::FactionSym_BOUNCER.mUID )
    return 16i64;
  if ( v1 != UFG::FactionSym_INNOCENT.mUID )
  {
    if ( v1 == UFG::FactionSym_STUDENT.mUID )
    {
      result = 18i64;
    }
    else if ( v1 == UFG::FactionSym_AMBIENT_AGGRESSIVE.mUID )
    {
      result = 19i64;
    }
    else if ( v1 == UFG::FactionSym_AMBIENT_GROUP_1.mUID )
    {
      result = 20i64;
    }
    else if ( v1 == UFG::FactionSym_AMBIENT_GROUP_2.mUID )
    {
      result = 21i64;
    }
    else if ( v1 == UFG::FactionSym_AMBIENT_GROUP_3.mUID )
    {
      result = 22i64;
    }
    else if ( v1 == UFG::FactionSym_AMBIENT_GROUP_4.mUID )
    {
      result = 23i64;
    }
    else if ( v1 == UFG::FactionSym_NETWORK_TEAM_1.mUID )
    {
      result = 24i64;
    }
    else if ( v1 == UFG::FactionSym_NETWORK_TEAM_2.mUID )
    {
      result = 25i64;
    }
    else if ( v1 == UFG::FactionSym_NETWORK_TEAM_3.mUID )
    {
      result = 26i64;
    }
    else if ( v1 == UFG::FactionSym_NETWORK_TEAM_4.mUID )
    {
      result = 27i64;
    }
    else if ( v1 == UFG::FactionSym_NETWORK_TEAM_5.mUID )
    {
      result = 28i64;
    }
    else if ( v1 == UFG::FactionSym_NETWORK_TEAM_6.mUID )
    {
      result = 29i64;
    }
    else if ( v1 == UFG::FactionSym_NETWORK_TEAM_7.mUID )
    {
      result = 30i64;
    }
    else if ( v1 == UFG::FactionSym_NETWORK_TEAM_8.mUID )
    {
      result = 31i64;
    }
    else if ( v1 == UFG::FactionSym_HOSTILE_SPECIAL_1.mUID )
    {
      result = 32i64;
    }
    else if ( v1 == UFG::FactionSym_HOSTILE_SPECIAL_2.mUID )
    {
      result = 33i64;
    }
    else if ( v1 == UFG::FactionSym_ALLIED_SPECIAL_1.mUID )
    {
      result = 34i64;
    }
    else if ( v1 == UFG::FactionSym_ALLIED_SPECIAL_2.mUID )
    {
      result = 35i64;
    }
    else if ( v1 == UFG::FactionSym_LAW_HOSTILE.mUID )
    {
      result = 36i64;
    }
    else if ( v1 == UFG::FactionSym_ROOSTER1.mUID )
    {
      result = 37i64;
    }
    else if ( v1 == UFG::FactionSym_ROOSTER2.mUID )
    {
      result = 38i64;
    }
  }
  return result;
}

// File Line: 574
// RVA: 0x36DDD0
signed __int64 __fastcall UFG::FactionInterface::MapSymbolToStanding(UFG::qSymbol *symbol)
{
  unsigned int v1; // eax
  unsigned int v2; // edx

  v1 = symbol->mUID;
  v2 = 0;
  if ( symbol->mUID != FactionStandingSym_ALLIED.mUID )
  {
    if ( v1 == FactionStandingSym_INDIFFERENT.mUID )
      return 1i64;
    if ( v1 == FactionStandingSym_HOSTILE.mUID )
      return 2i64;
    if ( v1 == FactionStandingSym_SCARED.mUID )
      v2 = 3;
  }
  return v2;
}

// File Line: 589
// RVA: 0x36D980
UFG::qStaticSymbol *__fastcall UFG::FactionInterface::MapFactionToSymbol(UFG::FactionInterface *this, UFG::eFactionClassEnum faction)
{
  UFG::qStaticSymbol *v3; // [rsp+0h] [rbp-100h]
  UFG::qStaticSymbol *v4; // [rsp+8h] [rbp-F8h]
  UFG::qStaticSymbol *v5; // [rsp+10h] [rbp-F0h]
  UFG::qStaticSymbol *v6; // [rsp+18h] [rbp-E8h]
  UFG::qStaticSymbol *v7; // [rsp+20h] [rbp-E0h]
  UFG::qStaticSymbol *v8; // [rsp+28h] [rbp-D8h]
  UFG::qStaticSymbol *v9; // [rsp+30h] [rbp-D0h]
  UFG::qStaticSymbol *v10; // [rsp+38h] [rbp-C8h]
  UFG::qStaticSymbol *v11; // [rsp+40h] [rbp-C0h]
  UFG::qStaticSymbol *v12; // [rsp+48h] [rbp-B8h]
  UFG::qStaticSymbol *v13; // [rsp+50h] [rbp-B0h]
  UFG::qStaticSymbol *v14; // [rsp+58h] [rbp-A8h]
  UFG::qStaticSymbol *v15; // [rsp+60h] [rbp-A0h]
  UFG::qStaticSymbol *v16; // [rsp+68h] [rbp-98h]
  UFG::qStaticSymbol *v17; // [rsp+70h] [rbp-90h]
  UFG::qStaticSymbol *v18; // [rsp+78h] [rbp-88h]
  UFG::qStaticSymbol *v19; // [rsp+80h] [rbp-80h]
  UFG::qStaticSymbol *v20; // [rsp+88h] [rbp-78h]
  UFG::qStaticSymbol *v21; // [rsp+90h] [rbp-70h]
  UFG::qStaticSymbol *v22; // [rsp+98h] [rbp-68h]
  UFG::qStaticSymbol *v23; // [rsp+A0h] [rbp-60h]
  UFG::qStaticSymbol *v24; // [rsp+A8h] [rbp-58h]
  UFG::qStaticSymbol *v25; // [rsp+B0h] [rbp-50h]
  UFG::qStaticSymbol *v26; // [rsp+B8h] [rbp-48h]
  UFG::qStaticSymbol *v27; // [rsp+C0h] [rbp-40h]
  UFG::qStaticSymbol *v28; // [rsp+C8h] [rbp-38h]
  UFG::qStaticSymbol *v29; // [rsp+D0h] [rbp-30h]
  UFG::qStaticSymbol *v30; // [rsp+D8h] [rbp-28h]
  UFG::qStaticSymbol *v31; // [rsp+E0h] [rbp-20h]
  UFG::qStaticSymbol *v32; // [rsp+E8h] [rbp-18h]
  UFG::qStaticSymbol *v33; // [rsp+F0h] [rbp-10h]
  UFG::qStaticSymbol *v34; // [rsp+F8h] [rbp-8h]
  UFG::qStaticSymbol *v35; // [rsp+100h] [rbp+0h]
  UFG::qStaticSymbol *v36; // [rsp+108h] [rbp+8h]
  UFG::qStaticSymbol *v37; // [rsp+110h] [rbp+10h]
  UFG::qStaticSymbol *v38; // [rsp+118h] [rbp+18h]
  UFG::qStaticSymbol *v39; // [rsp+120h] [rbp+20h]
  UFG::qStaticSymbol *v40; // [rsp+128h] [rbp+28h]
  UFG::qStaticSymbol *v41; // [rsp+130h] [rbp+30h]

  v3 = &UFG::FactionSym_INVALID;
  v4 = &UFG::FactionSym_INDIFFERENT;
  v5 = &UFG::FactionSym_PLAYER;
  v6 = &UFG::FactionSym_LAW;
  v7 = &UFG::FactionSym_TRIAD_WINSTON;
  v8 = &UFG::FactionSym_TRIAD_DOGEYES;
  v9 = &UFG::FactionSym_TRIAD_SONNY;
  v10 = &UFG::FactionSym_TRIAD_JIIANG;
  v11 = &UFG::FactionSym_TRIAD_CHEUK;
  v12 = &UFG::FactionSym_TRIAD_TWOCHIN;
  v13 = &UFG::FactionSym_TRIAD_GENERIC;
  v14 = &UFG::FactionSym_TRIAD_WATERSTREET;
  v15 = &UFG::FactionSym_TRIAD_18K;
  v16 = &UFG::FactionSym_TRIAD_DOGBOYS;
  v17 = &UFG::FactionSym_TRIAD_SUNONYEE;
  v18 = &UFG::FactionSym_TRIAD_LEE;
  v19 = &UFG::FactionSym_BOUNCER;
  v20 = &UFG::FactionSym_INNOCENT;
  v21 = &UFG::FactionSym_STUDENT;
  v22 = &UFG::FactionSym_AMBIENT_AGGRESSIVE;
  v23 = &UFG::FactionSym_AMBIENT_GROUP_1;
  v24 = &UFG::FactionSym_AMBIENT_GROUP_2;
  v25 = &UFG::FactionSym_AMBIENT_GROUP_3;
  v26 = &UFG::FactionSym_AMBIENT_GROUP_4;
  v27 = &UFG::FactionSym_NETWORK_TEAM_1;
  v28 = &UFG::FactionSym_NETWORK_TEAM_2;
  v29 = &UFG::FactionSym_NETWORK_TEAM_3;
  v30 = &UFG::FactionSym_NETWORK_TEAM_4;
  v31 = &UFG::FactionSym_NETWORK_TEAM_5;
  v32 = &UFG::FactionSym_NETWORK_TEAM_6;
  v33 = &UFG::FactionSym_NETWORK_TEAM_7;
  v34 = &UFG::FactionSym_NETWORK_TEAM_8;
  v35 = &UFG::FactionSym_HOSTILE_SPECIAL_1;
  v36 = &UFG::FactionSym_HOSTILE_SPECIAL_2;
  v37 = &UFG::FactionSym_ALLIED_SPECIAL_1;
  v38 = &UFG::FactionSym_ALLIED_SPECIAL_2;
  v39 = &UFG::FactionSym_LAW_HOSTILE;
  v40 = &UFG::FactionSym_ROOSTER1;
  v41 = &UFG::FactionSym_ROOSTER2;
  return (&v3)[faction];
}

// File Line: 602
// RVA: 0x36DB60
UFG::qStaticSymbol *__fastcall UFG::FactionInterface::MapStandingToSymbol(UFG::FactionInterface *this, UFG::eFactionStandingEnum standing)
{
  UFG::qStaticSymbol *v3; // [rsp+0h] [rbp-28h]
  UFG::qStaticSymbol *v4; // [rsp+8h] [rbp-20h]
  UFG::qStaticSymbol *v5; // [rsp+10h] [rbp-18h]
  UFG::qStaticSymbol *v6; // [rsp+18h] [rbp-10h]

  v3 = &FactionStandingSym_ALLIED;
  v4 = &FactionStandingSym_INDIFFERENT;
  v5 = &FactionStandingSym_HOSTILE;
  v6 = &FactionStandingSym_SCARED;
  return (&v3)[standing];
}

