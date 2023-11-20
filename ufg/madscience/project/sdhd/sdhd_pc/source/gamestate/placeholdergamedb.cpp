// File Line: 18
// RVA: 0x14E9BA0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::GangMemberStatData_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::GangMemberStatData", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::GangMemberStatData,UFG::qReflectObject>::sInventory.vfptr,
    "UFG::GangMemberStatData",
    v0);
  UFG::qReflectObjectType<UFG::GangMemberStatData,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::GangMemberStatData>::`vftable';
  UFG::qReflectInventory<UFG::GangMemberStatData>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::GangMemberStatData,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::GangMemberStatData,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::GangMemberStatData_UFG::qReflectObject_::sInventory__);
}

// File Line: 19
// RVA: 0x14E9700
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::WeaponStatData_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::WeaponStatData", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::WeaponStatData,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::WeaponStatData>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 20
// RVA: 0x14E9A80
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::RangedWeaponStatData_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 21
// RVA: 0x14E9AB0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::ThrownWeaponStatData_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::ThrownWeaponStatData,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 22
// RVA: 0x14E9A20
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::MeleeWeaponStatData_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::MeleeWeaponStatData,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 23
// RVA: 0x14E9E20
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::PlayerStatData_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::PlayerStatData", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::PlayerStatData,UFG::qReflectObject>::sInventory.vfptr,
    "UFG::PlayerStatData",
    v0);
  UFG::qReflectObjectType<UFG::PlayerStatData,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::PlayerStatData>::`vftable';
  UFG::qReflectInventory<UFG::PlayerStatData>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::PlayerStatData,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::PlayerStatData,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::PlayerStatData_UFG::qReflectObject_::sInventory__);
}

// File Line: 28
// RVA: 0x14EF760
__int64 UFG::_dynamic_initializer_for__mgSym_Counterfeiting_Sweatshop__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Counterfeiting: Sweatshop", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::mgSym_Counterfeiting_Sweatshop, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__mgSym_Counterfeiting_Sweatshop__);
}

// File Line: 34
// RVA: 0x14E9290
__int64 dynamic_initializer_for__UFG::PlaceholderGameDB::msRivalIds__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PlaceholderGameDB::msRivalIds__);
}

// File Line: 39
// RVA: 0x14E9270
__int64 dynamic_initializer_for__UFG::PlaceholderGameDB::msNumRivalPlayers__()
{
  __int64 result; // rax

  result = UFG::size_of_fake_list;
  UFG::PlaceholderGameDB::msNumRivalPlayers = UFG::size_of_fake_list;
  return result;
}

// File Line: 57
// RVA: 0x40C480
__int64 __fastcall UFG::GetMeleeWeaponEnumFromName(const char *sName)
{
  const char *v1; // rbp
  unsigned int v2; // esi
  unsigned int v3; // ebx
  const char **v4; // rdi
  UFG::qString v6; // [rsp+28h] [rbp-30h]

  v1 = sName;
  UFG::qString::qString(&v6, "%s%s", "eMELEE_WEAPON_", sName, -2i64);
  v2 = 0;
  v3 = 0;
  v4 = UFG::MeleeWeaponNames;
  while ( (unsigned int)UFG::qStringCompare(*v4, v1, -1)
       && (unsigned int)UFG::qStringCompareInsensitive(*v4, v6.mData, -1) )
  {
    ++v3;
    ++v4;
    if ( v3 >= 4 )
      goto LABEL_7;
  }
  v2 = v3;
LABEL_7:
  UFG::qString::~qString(&v6);
  return v2;
}

// File Line: 73
// RVA: 0x40C720
__int64 __fastcall UFG::GetRangedWeaponEnumFromName(const char *sName)
{
  const char *v1; // rbp
  unsigned int v2; // esi
  unsigned int v3; // ebx
  const char **v4; // rdi
  UFG::qString v6; // [rsp+28h] [rbp-30h]

  v1 = sName;
  UFG::qString::qString(&v6, "%s%s", "eRANGED_WEAPON_", sName, -2i64);
  v2 = 0;
  v3 = 0;
  v4 = UFG::RangedWeaponNames;
  while ( (unsigned int)UFG::qStringCompare(*v4, v1, -1)
       && (unsigned int)UFG::qStringCompareInsensitive(*v4, v6.mData, -1) )
  {
    ++v3;
    ++v4;
    if ( v3 >= 6 )
      goto LABEL_7;
  }
  v2 = v3;
LABEL_7:
  UFG::qString::~qString(&v6);
  return v2;
}

// File Line: 89
// RVA: 0x40C8D0
__int64 __fastcall UFG::GetThrownWeaponEnumFromName(const char *sName)
{
  const char *v1; // rbp
  unsigned int v2; // esi
  unsigned int v3; // ebx
  const char **v4; // rdi
  UFG::qString v6; // [rsp+28h] [rbp-30h]

  v1 = sName;
  UFG::qString::qString(&v6, "%s%s", "eTHROWN_WEAPON_", sName, -2i64);
  v2 = 0;
  v3 = 0;
  v4 = UFG::ThrownWeaponNames;
  while ( (unsigned int)UFG::qStringCompare(*v4, v1, -1)
       && (unsigned int)UFG::qStringCompareInsensitive(*v4, v6.mData, -1) )
  {
    ++v3;
    ++v4;
    if ( v3 >= 5 )
      goto LABEL_7;
  }
  v2 = v3;
LABEL_7:
  UFG::qString::~qString(&v6);
  return v2;
}

// File Line: 114
// RVA: 0x14E9350
__int64 dynamic_initializer_for__UFG::PlaceholderGameDB::msURL__()
{
  UFG::qString::qString(&UFG::PlaceholderGameDB::msURL, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::PlaceholderGameDB::msURL__);
}

// File Line: 117
// RVA: 0x14E92E0
__int64 dynamic_initializer_for__UFG::PlaceholderGameDB::msServerAddress__()
{
  UFG::qString::qString(&UFG::PlaceholderGameDB::msServerAddress, "localhost");
  return atexit(dynamic_atexit_destructor_for__UFG::PlaceholderGameDB::msServerAddress__);
}

// File Line: 118
// RVA: 0x14E91C0
__int64 dynamic_initializer_for__UFG::PlaceholderGameDB::msCommodityName__()
{
  UFG::qString::qString(&UFG::PlaceholderGameDB::msCommodityName, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::PlaceholderGameDB::msCommodityName__);
}

// File Line: 121
// RVA: 0x14E9190
__int64 dynamic_initializer_for__UFG::PlaceholderGameDB::msBlackmarketText__()
{
  UFG::qString::qString(&UFG::PlaceholderGameDB::msBlackmarketText, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::PlaceholderGameDB::msBlackmarketText__);
}

// File Line: 587
// RVA: 0x40A530
__int64 __fastcall UFG::PlaceholderGameDB::CreateNewRacket(const char *racketType)
{
  UFG::PlaceholderGameDB *v1; // rdi
  const char *v2; // rbp
  __int64 v3; // rsi
  unsigned int v4; // edx
  unsigned int v5; // ebx
  unsigned int v6; // edx
  UFG::PlaceholderGameDB *v7; // rax
  signed __int64 v8; // rbx
  __int64 result; // rax

  v1 = UFG::PlaceholderGameDB::ms_pSingleton;
  v2 = racketType;
  v3 = UFG::PlaceholderGameDB::ms_pSingleton->mRackets.size;
  v4 = UFG::PlaceholderGameDB::ms_pSingleton->mRackets.capacity;
  v5 = v3 + 1;
  if ( (signed int)v3 + 1 > v4 )
  {
    if ( v4 )
      v6 = 2 * v4;
    else
      v6 = 1;
    for ( ; v6 < v5; v6 *= 2 )
      ;
    if ( v6 - v5 > 0x10000 )
      v6 = v3 + 65537;
    UFG::qArray<UFG::RacketInstanceData,0>::Reallocate(
      &UFG::PlaceholderGameDB::ms_pSingleton->mRackets,
      v6,
      "qArray.Add");
  }
  v1->mRackets.size = v5;
  v7 = UFG::PlaceholderGameDB::ms_pSingleton;
  v8 = (signed __int64)&v1->mRackets.p[v3];
  *(_DWORD *)(v8 + 40) = ++v7->mNextRacketID;
  *(_DWORD *)(v8 + 68) = 1;
  UFG::qString::Set((UFG::qString *)v8, v2);
  *(_DWORD *)(v8 + 48) = UFG::RacketMetagameDB::GetTypeIdFromTypeString((UFG::qString *)v8);
  result = *(unsigned int *)(v8 + 40);
  *(_DWORD *)(v8 + 44) = -1;
  return result;
}

// File Line: 653
// RVA: 0x40BF30
__int64 __fastcall UFG::PlaceholderGameDB::GetBlockIdByIndex(UFG::TurfInstanceData *data, int i)
{
  return data->blockId[i];
}

// File Line: 659
// RVA: 0x40C6D0
__int64 __fastcall UFG::PlaceholderGameDB::GetRacketIdByIndex(UFG::TurfBlockInstanceData *data, int i)
{
  return data->racketId[i];
}

// File Line: 685
// RVA: 0x40CB90
UFG::TurfInstanceData *__fastcall UFG::PlaceholderGameDB::GetTurfInstanceDataForPlayerId(UFG::PlaceholderGameDB *this, unsigned int id)
{
  unsigned int v2; // er8
  __int64 v3; // rax
  UFG::TurfInstanceData *v4; // r9
  unsigned int *v5; // rcx

  v2 = this->mTurfs.size;
  v3 = 0i64;
  if ( !v2 )
    return 0i64;
  v4 = this->mTurfs.p;
  v5 = &v4->ownerPlayerId;
  while ( *v5 != id )
  {
    v3 = (unsigned int)(v3 + 1);
    v5 += 34;
    if ( (unsigned int)v3 >= v2 )
      return 0i64;
  }
  return &v4[v3];
}

// File Line: 694
// RVA: 0x40CAF0
UFG::TurfInstanceData *__fastcall UFG::PlaceholderGameDB::GetTurfInstanceDataForMarkerId(UFG::PlaceholderGameDB *this, unsigned int id)
{
  unsigned int v2; // ebx
  unsigned int v3; // er14
  UFG::PlaceholderGameDB *v4; // rsi
  signed __int64 v5; // rdi
  UFG::TurfInstanceData *v6; // rbp

  v2 = 0;
  v3 = id;
  v4 = this;
  if ( !this->mTurfs.size )
    return 0i64;
  while ( 1 )
  {
    v5 = v2;
    v6 = &v4->mTurfs.p[v5];
    if ( v6->locationName.mStringHash32 == -1 )
      v6->locationName.mStringHash32 = UFG::qStringHash32(v6->locationName.mData, 0xFFFFFFFF);
    if ( v6->locationName.mStringHash32 == v3 && v4->mTurfs.p[v5].ownerPlayerId - 1 > 1 )
      break;
    if ( ++v2 >= v4->mTurfs.size )
      return 0i64;
  }
  return &v4->mTurfs.p[v2];
}

// File Line: 712
// RVA: 0x40CAA0
UFG::TurfInstanceData *__fastcall UFG::PlaceholderGameDB::GetTurfInstanceDataForBlockId(UFG::PlaceholderGameDB *this, unsigned int blockID)
{
  unsigned int v2; // er10
  unsigned int v3; // er8
  UFG::TurfInstanceData *v4; // r11
  signed __int64 v5; // r9
  unsigned int v6; // ecx
  _DWORD *v7; // rax

  v2 = this->mTurfs.size;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->mTurfs.p;
    v5 = (signed __int64)v4->blockId;
    while ( 2 )
    {
      v6 = 0;
      v7 = (_DWORD *)v5;
      do
      {
        if ( *v7 == blockID )
          return &v4[v3];
        ++v6;
        ++v7;
      }
      while ( v6 < 8 );
      ++v3;
      v5 += 136i64;
      if ( v3 < v2 )
        continue;
      break;
    }
  }
  return 0i64;
}

// File Line: 741
// RVA: 0x40CA20
UFG::TurfBlockInstanceData *__fastcall UFG::PlaceholderGameDB::GetTurfBlockInstanceData(UFG::PlaceholderGameDB *this, unsigned int id)
{
  unsigned int v2; // er8
  __int64 v3; // rax
  UFG::TurfBlockInstanceData *v4; // r9
  UFG::TurfBlockInstanceData *v5; // rcx

  v2 = this->mTurfBlocks.size;
  v3 = 0i64;
  if ( !v2 )
    return 0i64;
  v4 = this->mTurfBlocks.p;
  v5 = this->mTurfBlocks.p;
  while ( v5->id != id )
  {
    v3 = (unsigned int)(v3 + 1);
    ++v5;
    if ( (unsigned int)v3 >= v2 )
      return 0i64;
  }
  return &v4[v3];
}

// File Line: 753
// RVA: 0x40CA50
UFG::TurfBlockInstanceData *__fastcall UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(UFG::PlaceholderGameDB *this, unsigned int racketID)
{
  unsigned int v2; // er10
  __int64 v3; // r8
  UFG::TurfBlockInstanceData *v4; // r11
  signed __int64 v5; // r9
  unsigned int v6; // ecx
  _DWORD *v7; // rax

  v2 = this->mTurfBlocks.size;
  v3 = 0i64;
  if ( v2 )
  {
    v4 = this->mTurfBlocks.p;
    v5 = (signed __int64)v4->racketId;
    while ( 2 )
    {
      v6 = 0;
      v7 = (_DWORD *)v5;
      do
      {
        if ( *v7 == racketID )
          return &v4[v3];
        ++v6;
        ++v7;
      }
      while ( v6 < 4 );
      v3 = (unsigned int)(v3 + 1);
      v5 += 20i64;
      if ( (unsigned int)v3 < v2 )
        continue;
      break;
    }
  }
  return 0i64;
}

// File Line: 767
// RVA: 0x40C6E0
UFG::RacketInstanceData *__fastcall UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB *this, unsigned int id)
{
  unsigned int v2; // er8
  __int64 v3; // rax
  UFG::RacketInstanceData *v4; // r9
  unsigned int *v5; // rcx

  v2 = this->mRackets.size;
  v3 = 0i64;
  if ( !v2 )
    return 0i64;
  v4 = this->mRackets.p;
  v5 = &v4->id;
  while ( *v5 != id )
  {
    v3 = (unsigned int)(v3 + 1);
    v5 += 20;
    if ( (unsigned int)v3 >= v2 )
      return 0i64;
  }
  return &v4[v3];
}

// File Line: 782
// RVA: 0x40BFD0
UFG::GangMemberStatData *__fastcall UFG::PlaceholderGameDB::GetGangMemberStatDataForPlayerId(UFG::PlaceholderGameDB *this, unsigned int id, UFG::eFightingClassEnum eFC)
{
  signed __int64 v3; // r9
  unsigned int v4; // eax
  UFG::PlayerStatData *v5; // r11
  unsigned int *v6; // rcx

  v3 = 0i64;
  v4 = 0;
  if ( UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.size )
  {
    v5 = UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.p;
    v6 = &v5->id;
    while ( *v6 != id )
    {
      ++v4;
      v6 += 1204;
      if ( v4 >= UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.size )
        return (UFG::GangMemberStatData *)(v3 + 160i64 * (signed int)eFC + 3216);
    }
    v3 = (signed __int64)&v5[v4];
  }
  return (UFG::GangMemberStatData *)(v3 + 160i64 * (signed int)eFC + 3216);
}

// File Line: 790
// RVA: 0x40C530
UFG::MeleeWeaponStatData *__fastcall UFG::PlaceholderGameDB::GetMeleeWeaponStatDataForPlayerId(UFG::PlaceholderGameDB *this, unsigned int id, const char *pcWeaponType, bool enforcer)
{
  __int64 v4; // rdi
  unsigned int v5; // eax
  UFG::PlayerStatData *v6; // r11
  unsigned int *v7; // rcx
  signed __int64 v8; // rbx

  v4 = 0i64;
  v5 = 0;
  if ( UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.size )
  {
    v6 = UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.p;
    v7 = &v6->id;
    while ( *v7 != id )
    {
      ++v5;
      v7 += 1204;
      if ( v5 >= UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.size )
        goto LABEL_5;
    }
    v8 = (signed __int64)&v6[v5];
  }
  else
  {
LABEL_5:
    v8 = 0i64;
  }
  LOBYTE(v4) = enforcer == 0;
  return (UFG::MeleeWeaponStatData *)(1520 * v4
                                    + 256
                                    + v8
                                    + 96i64 * (signed int)UFG::GetMeleeWeaponEnumFromName(pcWeaponType));
}

// File Line: 802
// RVA: 0x40C980
UFG::ThrownWeaponStatData *__fastcall UFG::PlaceholderGameDB::GetThrownWeaponStatDataForPlayerId(UFG::PlaceholderGameDB *this, unsigned int id, const char *pcWeaponType, bool enforcer)
{
  __int64 v4; // rdi
  unsigned int v5; // eax
  UFG::PlayerStatData *v6; // r11
  unsigned int *v7; // rcx
  signed __int64 v8; // rbx

  v4 = 0i64;
  v5 = 0;
  if ( UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.size )
  {
    v6 = UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.p;
    v7 = &v6->id;
    while ( *v7 != id )
    {
      ++v5;
      v7 += 1204;
      if ( v5 >= UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.size )
        goto LABEL_5;
    }
    v8 = (signed __int64)&v6[v5];
  }
  else
  {
LABEL_5:
    v8 = 0i64;
  }
  LOBYTE(v4) = enforcer == 0;
  return (UFG::ThrownWeaponStatData *)(1520 * v4
                                     + 1216
                                     + v8
                                     + 96i64 * (signed int)UFG::GetThrownWeaponEnumFromName(pcWeaponType));
}

// File Line: 814
// RVA: 0x40C7D0
UFG::RangedWeaponStatData *__fastcall UFG::PlaceholderGameDB::GetRangedWeaponStatDataForPlayerId(UFG::PlaceholderGameDB *this, unsigned int id, const char *pcWeaponType, bool enforcer)
{
  __int64 v4; // rdi
  unsigned int v5; // eax
  UFG::PlayerStatData *v6; // r11
  unsigned int *v7; // rcx
  signed __int64 v8; // rbx

  v4 = 0i64;
  v5 = 0;
  if ( UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.size )
  {
    v6 = UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.p;
    v7 = &v6->id;
    while ( *v7 != id )
    {
      ++v5;
      v7 += 1204;
      if ( v5 >= UFG::PlaceholderGameDB::ms_pSingleton->mPlayers.size )
        goto LABEL_5;
    }
    v8 = (signed __int64)&v6[v5];
  }
  else
  {
LABEL_5:
    v8 = 0i64;
  }
  LOBYTE(v4) = enforcer == 0;
  return (UFG::RangedWeaponStatData *)(1520 * v4
                                     + 640
                                     + v8
                                     + 96i64 * (signed int)UFG::GetRangedWeaponEnumFromName(pcWeaponType));
}

// File Line: 1198
// RVA: 0x14E9280
__int64 dynamic_initializer_for__UFG::RacketMetagameDB::msRacketDefintions__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::RacketMetagameDB::msRacketDefintions__);
}

// File Line: 1669
// RVA: 0x40CBD0
__int64 __fastcall UFG::RacketMetagameDB::GetTypeIdFromTypeString(UFG::qString *type_string)
{
  UFG::qString *v1; // rdi
  int v2; // ebx

  v1 = type_string;
  v2 = 0;
  if ( !UFG::RacketMetagameDB::msRacketDefintions.size )
    return (unsigned int)MEMORY[0];
  while ( !UFG::qString::operator==(v1, &UFG::RacketMetagameDB::msRacketDefintions.p[v2].mRacketName) )
  {
    if ( ++v2 >= UFG::RacketMetagameDB::msRacketDefintions.size )
      return (unsigned int)MEMORY[0];
  }
  return UFG::RacketMetagameDB::msRacketDefintions.p[v2].mRacketTypeID;
}

