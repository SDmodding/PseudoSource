// File Line: 28
// RVA: 0xBB940
void __fastcall UFG::UIAmbientMapBlipData::UIAmbientMapBlipData(UFG::UIAmbientMapBlipData *this)
{
  this->mID.mUID = -1;
}

// File Line: 66
// RVA: 0xCD400
void __fastcall UFG::UIAmbientMapBlipData::UpdateIcon(
        UFG::UIAmbientMapBlipData *this,
        UFG::UIMapBlipManager *iconManager,
        bool isWorldMap)
{
  unsigned int mUID; // edx
  UFG::UIMapBlip *v7; // rbx
  UFG::UIMapBlipTypeManager *v8; // rax
  unsigned int v9; // r9d
  UFG::UIHKMinimapBlipType *v10; // r11
  unsigned int v11; // edx
  unsigned int v12; // r9d
  int v13; // r8d
  unsigned int v14; // r10d
  UFG::UIHKMinimapBlipType *v15; // rdx
  bool IsCollected; // al
  UFG::UIMapBlipTypeManager *v17; // rax
  unsigned int v18; // r9d
  UFG::UIHKMinimapBlipType *p; // r11
  unsigned int v20; // edx
  unsigned int v21; // r9d
  int v22; // r8d
  unsigned int v23; // r10d
  UFG::GameStatTracker *v24; // rax
  UFG::GameStat::BoolStat v25; // edx
  bool mVisible; // zf
  UFG::UIMapBlipTypeManager *v27; // rax
  unsigned int v28; // r9d
  unsigned int v29; // edx
  unsigned int v30; // r9d
  unsigned int v31; // r10d
  UFG::UIMapBlipTypeManager *Instance; // rax
  unsigned int mNumTypes; // r9d
  unsigned int v34; // edx
  unsigned int v35; // r9d
  unsigned int v36; // r10d
  UFG::UIMapBlipTypeManager *v37; // rax
  unsigned int v38; // r9d
  unsigned int v39; // edx
  unsigned int v40; // r9d
  unsigned int v41; // r10d
  UFG::GameStatTracker *v42; // rax
  UFG::UIMapBlipTypeManager *v43; // rax
  unsigned int v44; // r9d
  unsigned int v45; // edx
  unsigned int v46; // r9d
  unsigned int v47; // r10d
  UFG::UIMapBlipTypeManager *v48; // rax
  unsigned int v49; // r9d
  unsigned int v50; // edx
  unsigned int v51; // r9d
  unsigned int v52; // r10d
  UFG::UIMapBlipTypeManager *v53; // rax
  unsigned int v54; // r9d
  unsigned int v55; // edx
  unsigned int v56; // r9d
  unsigned int v57; // r10d
  UFG::UIHKMinimapBlipType *v58; // rdx

  if ( iconManager )
  {
    mUID = this->mID.mUID;
    if ( mUID )
    {
      v7 = (UFG::UIMapBlip *)UFG::qBaseTreeRB::Get(&iconManager->mIconList.mIconData.mTree, mUID);
      if ( v7 )
      {
        if ( this->mCollectibleType )
        {
          switch ( this->mCollectibleType )
          {
            case COLLECTIBLE_SPY_CAM:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(this) )
              {
                v24 = UFG::GameStatTracker::Instance();
                v25 = EnableSpyCamIndicators;
                goto LABEL_37;
              }
              v7->mChanged |= v7->mVisible != isWorldMap;
              v7->mVisible = isWorldMap;
              if ( isWorldMap && !this->mIconTypeSetAsCollected )
              {
                this->mIconTypeSetAsCollected = 1;
                if ( (_S14 & 8) == 0 )
                {
                  _S14 |= 8u;
                  UFG::qSymbolUC::create_from_string(&security_camera_collected, "security_camera_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_51_::_dynamic_atexit_destructor_for__security_camera_collected__);
                }
                Instance = UFG::UIMapBlipTypeManager::getInstance();
                if ( security_camera_collected.mUID != -1 )
                {
                  mNumTypes = Instance->mNumTypes;
                  if ( mNumTypes )
                  {
                    p = Instance->mData.p;
                    v34 = 0;
                    v35 = mNumTypes - 1;
                    do
                    {
                      v22 = v34 + ((v35 - v34) >> 1);
                      v36 = *(unsigned int *)((char *)&p->TypeNameSymbol.mUID + (unsigned int)(112 * v22));
                      if ( v36 >= security_camera_collected.mUID )
                      {
                        if ( v36 <= security_camera_collected.mUID )
                          goto LABEL_130;
                        v35 = v22 - 1;
                      }
                      else
                      {
                        v34 = v22 + 1;
                      }
                    }
                    while ( v34 <= v35 );
                  }
                }
              }
              return;
            case COLLECTIBLE_HEALTH_SHRINE:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(this) )
              {
                v24 = UFG::GameStatTracker::Instance();
                v25 = EnableHealthShrineIndicators;
                goto LABEL_37;
              }
              v7->mChanged |= v7->mVisible != isWorldMap;
              v7->mVisible = isWorldMap;
              if ( isWorldMap && !this->mIconTypeSetAsCollected )
              {
                this->mIconTypeSetAsCollected = 1;
                if ( (_S14 & 2) == 0 )
                {
                  _S14 |= 2u;
                  UFG::qSymbolUC::create_from_string(&shrine_collected, "shrine_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_25_::_dynamic_atexit_destructor_for__shrine_collected__);
                }
                v17 = UFG::UIMapBlipTypeManager::getInstance();
                if ( shrine_collected.mUID != -1 )
                {
                  v18 = v17->mNumTypes;
                  if ( v18 )
                  {
                    p = v17->mData.p;
                    v20 = 0;
                    v21 = v18 - 1;
                    do
                    {
                      v22 = v20 + ((v21 - v20) >> 1);
                      v23 = *(unsigned int *)((char *)&p->TypeNameSymbol.mUID + (unsigned int)(112 * v22));
                      if ( v23 >= shrine_collected.mUID )
                      {
                        if ( v23 <= shrine_collected.mUID )
                          goto LABEL_130;
                        v21 = v22 - 1;
                      }
                      else
                      {
                        v20 = v22 + 1;
                      }
                    }
                    while ( v20 <= v21 );
                  }
                }
              }
              return;
            case COLLECTIBLE_LOCKBOX:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(this) )
              {
                v24 = UFG::GameStatTracker::Instance();
                v25 = EnableLockboxIndicators;
                goto LABEL_37;
              }
              v7->mChanged |= v7->mVisible != isWorldMap;
              v7->mVisible = isWorldMap;
              if ( isWorldMap && !this->mIconTypeSetAsCollected )
              {
                this->mIconTypeSetAsCollected = 1;
                if ( (_S14 & 0x10) == 0 )
                {
                  _S14 |= 0x10u;
                  UFG::qSymbolUC::create_from_string(&lockbox_collected, "lockbox_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_64_::_dynamic_atexit_destructor_for__lockbox_collected__);
                }
                v37 = UFG::UIMapBlipTypeManager::getInstance();
                if ( lockbox_collected.mUID != -1 )
                {
                  v38 = v37->mNumTypes;
                  if ( v38 )
                  {
                    p = v37->mData.p;
                    v39 = 0;
                    v40 = v38 - 1;
                    do
                    {
                      v22 = v39 + ((v40 - v39) >> 1);
                      v41 = *(unsigned int *)((char *)&p->TypeNameSymbol.mUID + (unsigned int)(112 * v22));
                      if ( v41 >= lockbox_collected.mUID )
                      {
                        if ( v41 <= lockbox_collected.mUID )
                          goto LABEL_130;
                        v40 = v22 - 1;
                      }
                      else
                      {
                        v39 = v22 + 1;
                      }
                    }
                    while ( v39 <= v40 );
                  }
                }
              }
              return;
            case COLLECTIBLE_SAFE_HOUSE:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(this) )
                goto LABEL_21;
              if ( (_S14 & 1) == 0 )
              {
                _S14 |= 1u;
                UFG::qSymbolUC::create_from_string(&safe_house_unlocked, "safe_house_unlocked");
                atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_18_::_dynamic_atexit_destructor_for__safe_house_unlocked__);
              }
              v8 = UFG::UIMapBlipTypeManager::getInstance();
              if ( safe_house_unlocked.mUID == -1 )
                goto LABEL_21;
              v9 = v8->mNumTypes;
              if ( !v9 )
                goto LABEL_21;
              v10 = v8->mData.p;
              v11 = 0;
              v12 = v9 - 1;
              while ( 1 )
              {
                v13 = v11 + ((v12 - v11) >> 1);
                v14 = *(unsigned int *)((char *)&v10->TypeNameSymbol.mUID + (unsigned int)(112 * v13));
                if ( v14 >= safe_house_unlocked.mUID )
                {
                  if ( v14 <= safe_house_unlocked.mUID )
                  {
                    v15 = (UFG::UIHKMinimapBlipType *)((char *)v10 + (unsigned int)(112 * v13));
                    if ( v15 )
                      UFG::UIMapBlip::SetType(v7, v15);
                    goto LABEL_21;
                  }
                  v12 = v13 - 1;
                }
                else
                {
                  v11 = v13 + 1;
                }
                if ( v11 > v12 )
                  goto LABEL_21;
              }
            case COLLECTIBLE_UNDERCOVER_SAFE_HOUSE:
            case COLLECTIBLE_HIDING_SPOT:
            case COLLECTIBLE_HIDING_SPOT_GARAGE:
              goto LABEL_21;
            case COLLECTIBLE_BOOST_REGION:
              v42 = UFG::GameStatTracker::Instance();
              if ( UFG::GameStatTracker::GetStat(v42, EnableJumpIndicators) )
                goto LABEL_38;
LABEL_21:
              IsCollected = UFG::UIAmbientMapBlipData::IsCollected(this);
              v7->mChanged |= v7->mVisible != IsCollected;
              v7->mVisible = IsCollected;
              return;
            case COLLECTIBLE_MELEE_UPGRADE:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(this) )
              {
                v24 = UFG::GameStatTracker::Instance();
                v25 = EnableJadeStatueIndicators;
                goto LABEL_37;
              }
              v7->mChanged |= v7->mVisible != isWorldMap;
              v7->mVisible = isWorldMap;
              if ( isWorldMap && !this->mIconTypeSetAsCollected )
              {
                this->mIconTypeSetAsCollected = 1;
                if ( (_S14 & 4) == 0 )
                {
                  _S14 |= 4u;
                  UFG::qSymbolUC::create_from_string(&shrine_collected_0, "melee_upgrade_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_38_::_dynamic_atexit_destructor_for__shrine_collected__);
                }
                v27 = UFG::UIMapBlipTypeManager::getInstance();
                if ( shrine_collected_0.mUID != -1 )
                {
                  v28 = v27->mNumTypes;
                  if ( v28 )
                  {
                    p = v27->mData.p;
                    v29 = 0;
                    v30 = v28 - 1;
                    do
                    {
                      v22 = v29 + ((v30 - v29) >> 1);
                      v31 = *(unsigned int *)((char *)&p->TypeNameSymbol.mUID + (unsigned int)(112 * v22));
                      if ( v31 >= shrine_collected_0.mUID )
                      {
                        if ( v31 <= shrine_collected_0.mUID )
                          goto LABEL_130;
                        v30 = v22 - 1;
                      }
                      else
                      {
                        v29 = v22 + 1;
                      }
                    }
                    while ( v29 <= v30 );
                  }
                }
              }
              return;
            case COLLECTIBLE_GHOST_ORB:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(this) )
              {
                v24 = UFG::GameStatTracker::Instance();
                v25 = EnableDLC01CollectibleIndicators;
                goto LABEL_37;
              }
              v7->mChanged |= v7->mVisible != isWorldMap;
              v7->mVisible = isWorldMap;
              if ( isWorldMap && !this->mIconTypeSetAsCollected )
              {
                this->mIconTypeSetAsCollected = 1;
                if ( (_S14 & 0x20) == 0 )
                {
                  _S14 |= 0x20u;
                  UFG::qSymbolUC::create_from_string(&ghost_orb_collected, "ghost_orb_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_83_::_dynamic_atexit_destructor_for__ghost_orb_collected__);
                }
                v43 = UFG::UIMapBlipTypeManager::getInstance();
                if ( ghost_orb_collected.mUID != -1 )
                {
                  v44 = v43->mNumTypes;
                  if ( v44 )
                  {
                    p = v43->mData.p;
                    v45 = 0;
                    v46 = v44 - 1;
                    do
                    {
                      v22 = v45 + ((v46 - v45) >> 1);
                      v47 = *(unsigned int *)((char *)&p->TypeNameSymbol.mUID + (unsigned int)(112 * v22));
                      if ( v47 >= ghost_orb_collected.mUID )
                      {
                        if ( v47 <= ghost_orb_collected.mUID )
                          goto LABEL_130;
                        v46 = v22 - 1;
                      }
                      else
                      {
                        v45 = v22 + 1;
                      }
                    }
                    while ( v45 <= v46 );
                  }
                }
              }
              return;
            case COLLECTIBLE_BOMB_BAG:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(this) )
              {
                v24 = UFG::GameStatTracker::Instance();
                v25 = EnableDLC03CollectibleIndicators;
                goto LABEL_37;
              }
              v7->mChanged |= v7->mVisible != isWorldMap;
              v7->mVisible = isWorldMap;
              if ( isWorldMap && !this->mIconTypeSetAsCollected )
              {
                this->mIconTypeSetAsCollected = 1;
                if ( (_S14 & 0x80u) == 0 )
                {
                  _S14 |= 0x80u;
                  UFG::qSymbolUC::create_from_string(&evidence_bag_collected, "evidence_bag_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_109_::_dynamic_atexit_destructor_for__evidence_bag_collected__);
                }
                v53 = UFG::UIMapBlipTypeManager::getInstance();
                if ( evidence_bag_collected.mUID != -1 )
                {
                  v54 = v53->mNumTypes;
                  if ( v54 )
                  {
                    p = v53->mData.p;
                    v55 = 0;
                    v56 = v54 - 1;
                    do
                    {
                      v22 = v55 + ((v56 - v55) >> 1);
                      v57 = *(unsigned int *)((char *)&p->TypeNameSymbol.mUID + (unsigned int)(112 * v22));
                      if ( v57 >= evidence_bag_collected.mUID )
                      {
                        if ( v57 <= evidence_bag_collected.mUID )
                          goto LABEL_130;
                        v56 = v22 - 1;
                      }
                      else
                      {
                        v55 = v22 + 1;
                      }
                    }
                    while ( v55 <= v56 );
                  }
                }
              }
              return;
            case COLLECTIBLE_ZODIAC:
              if ( UFG::UIAmbientMapBlipData::IsCollected(this) )
              {
                v7->mChanged |= v7->mVisible != isWorldMap;
                v7->mVisible = isWorldMap;
                if ( isWorldMap && !this->mIconTypeSetAsCollected )
                {
                  this->mIconTypeSetAsCollected = 1;
                  if ( (_S14 & 0x40) == 0 )
                  {
                    _S14 |= 0x40u;
                    UFG::qSymbolUC::create_from_string(&fire_statue_collected, "fire_statue_collected");
                    atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_96_::_dynamic_atexit_destructor_for__fire_statue_collected__);
                  }
                  v48 = UFG::UIMapBlipTypeManager::getInstance();
                  if ( fire_statue_collected.mUID != -1 )
                  {
                    v49 = v48->mNumTypes;
                    if ( v49 )
                    {
                      p = v48->mData.p;
                      v50 = 0;
                      v51 = v49 - 1;
                      while ( 1 )
                      {
                        v22 = v50 + ((v51 - v50) >> 1);
                        v52 = *(unsigned int *)((char *)&p->TypeNameSymbol.mUID + (unsigned int)(112 * v22));
                        if ( v52 >= fire_statue_collected.mUID )
                        {
                          if ( v52 <= fire_statue_collected.mUID )
                          {
LABEL_130:
                            v58 = (UFG::UIHKMinimapBlipType *)((char *)p + (unsigned int)(112 * v22));
                            if ( v58 )
                              UFG::UIMapBlip::SetType(v7, v58);
                            return;
                          }
                          v51 = v22 - 1;
                        }
                        else
                        {
                          v50 = v22 + 1;
                        }
                        if ( v50 > v51 )
                          return;
                      }
                    }
                  }
                }
              }
              else
              {
                v24 = UFG::GameStatTracker::Instance();
                v25 = EnableDLC02CollectibleIndicators;
LABEL_37:
                if ( UFG::GameStatTracker::GetStat(v24, v25) )
                {
LABEL_38:
                  mVisible = v7->mVisible;
                  v7->mVisible = 1;
                }
                else
                {
                  mVisible = !v7->mVisible;
                  v7->mVisible = 0;
                }
                v7->mChanged |= !mVisible;
              }
              break;
            default:
              return;
          }
        }
        else
        {
          v7->mChanged |= !v7->mVisible;
          v7->mVisible = 1;
        }
      }
    }
  }
}

// File Line: 317
// RVA: 0xC0FA0
__int64 __fastcall UFG::UIAmbientMapBlipData::GetID(UFG::UIAmbientMapBlipData *this)
{
  return this->mID.mUID;
}

// File Line: 323
// RVA: 0xC49E0
const char *__fastcall UFG::UIAmbientMapBlipData::GetType(UFG::UIAmbientMapBlipData *this)
{
  __int64 v2[15]; // [rsp+0h] [rbp-78h]

  v2[0] = (__int64)"Generic_Interactive_Object";
  v2[1] = (__int64)"security_camera";
  v2[2] = (__int64)"shrine";
  v2[3] = (__int64)"lockbox";
  v2[4] = (__int64)"safe_house";
  v2[5] = (__int64)"undercover_safe_house";
  v2[6] = (__int64)"hiding_spot";
  v2[7] = (__int64)"hiding_spot_garage";
  v2[8] = (__int64)"bus_stop";
  v2[9] = (__int64)"jump";
  v2[10] = (__int64)"melee_upgrade";
  v2[11] = (__int64)"ghost_orb";
  v2[12] = (__int64)"fire_statue";
  v2[13] = (__int64)"evidence_bag";
  return (const char *)v2[this->mCollectibleType];
}

// File Line: 366
// RVA: 0xC5BF0
bool __fastcall UFG::UIAmbientMapBlipData::IsCollected(UFG::UIAmbientMapBlipData *this)
{
  UFG::GameStatTracker *v2; // rax
  UFG::GameStat::MapBoolStat v3; // edx
  UFG::PersistentData::MapBool *MapBool; // rax
  UFG::UIAmbientMapBlipData::eZoneInfo mZoneInfo; // ecx
  __int32 v7; // ecx
  __int32 v8; // ecx
  UFG::UIAmbientMapBlipData::eZoneInfo v9; // ecx
  __int32 v10; // ecx
  __int32 v11; // ecx

  switch ( this->mCollectibleType )
  {
    case COLLECTIBLE_SPY_CAM:
      v2 = UFG::GameStatTracker::Instance();
      v3 = Collectible_SpyCam;
      goto LABEL_3;
    case COLLECTIBLE_HEALTH_SHRINE:
      mZoneInfo = this->mZoneInfo;
      if ( mZoneInfo )
      {
        v7 = mZoneInfo - 1;
        if ( v7 )
        {
          v8 = v7 - 1;
          if ( v8 )
          {
            if ( v8 != 1 )
              return 0;
            v2 = UFG::GameStatTracker::Instance();
            v3 = Collectible_HealthShrineNP;
          }
          else
          {
            v2 = UFG::GameStatTracker::Instance();
            v3 = Collectible_HealthShrineKT;
          }
        }
        else
        {
          v2 = UFG::GameStatTracker::Instance();
          v3 = Collectible_HealthShrineCN;
        }
      }
      else
      {
        v2 = UFG::GameStatTracker::Instance();
        v3 = Collectible_HealthShrineAB;
      }
      goto LABEL_3;
    case COLLECTIBLE_LOCKBOX:
      v9 = this->mZoneInfo;
      if ( v9 == SPHERE )
      {
        v2 = UFG::GameStatTracker::Instance();
        v3 = Collectible_LockBoxAB;
        goto LABEL_3;
      }
      v10 = v9 - 1;
      if ( !v10 )
      {
        v2 = UFG::GameStatTracker::Instance();
        v3 = Collectible_LockBoxCN;
        goto LABEL_3;
      }
      v11 = v10 - 1;
      if ( !v11 )
      {
        v2 = UFG::GameStatTracker::Instance();
        v3 = Collectible_LockBoxKT;
        goto LABEL_3;
      }
      if ( v11 == 1 )
      {
        v2 = UFG::GameStatTracker::Instance();
        v3 = Collectible_LockBoxNP;
LABEL_3:
        MapBool = UFG::GameStatTracker::GetMapBool(v2, v3);
        return UFG::PersistentData::MapBool::GetStatus(MapBool, &this->mID);
      }
      return 0;
    case COLLECTIBLE_SAFE_HOUSE:
    case COLLECTIBLE_UNDERCOVER_SAFE_HOUSE:
      v2 = UFG::GameStatTracker::Instance();
      v3 = Collectible_Safehouse;
      goto LABEL_3;
    case COLLECTIBLE_HIDING_SPOT:
    case COLLECTIBLE_HIDING_SPOT_GARAGE:
      v2 = UFG::GameStatTracker::Instance();
      v3 = Collectible_HidingSpot;
      goto LABEL_3;
    case COLLECTIBLE_BUS_STOP:
      v2 = UFG::GameStatTracker::Instance();
      v3 = Collectible_BusStop;
      goto LABEL_3;
    case COLLECTIBLE_BOOST_REGION:
      v2 = UFG::GameStatTracker::Instance();
      v3 = Collectible_BoostRegion;
      goto LABEL_3;
    case COLLECTIBLE_MELEE_UPGRADE:
      v2 = UFG::GameStatTracker::Instance();
      v3 = Collectible_Melee;
      goto LABEL_3;
    case COLLECTIBLE_GHOST_ORB:
      v2 = UFG::GameStatTracker::Instance();
      v3 = Collectible_DLC_01;
      goto LABEL_3;
    case COLLECTIBLE_BOMB_BAG:
      v2 = UFG::GameStatTracker::Instance();
      v3 = Collectible_DLC_03;
      goto LABEL_3;
    case COLLECTIBLE_ZODIAC:
      v2 = UFG::GameStatTracker::Instance();
      v3 = Collectible_DLC_02;
      goto LABEL_3;
    default:
      return 0;
  }
}

// File Line: 500
// RVA: 0xCEAF0
__int64 __fastcall UFG::UIAmbientMapBlipData::XMLConvertBlipType(const char *type)
{
  int v3; // eax
  unsigned int v4; // ecx

  if ( !UFG::qStringCompareInsensitive(type, "HidingSpot", -1) )
    return 6i64;
  if ( !UFG::qStringCompareInsensitive(type, "HealthShrine", -1) )
    return 2i64;
  if ( !UFG::qStringCompareInsensitive(type, "LockBox", -1) )
    return 3i64;
  if ( !UFG::qStringCompareInsensitive(type, "SpyCam", -1) )
    return 1i64;
  if ( !UFG::qStringCompareInsensitive(type, "BusStop", -1) )
    return 8i64;
  if ( !UFG::qStringCompareInsensitive(type, "Safehouse", -1) )
    return 4i64;
  if ( !UFG::qStringCompareInsensitive(type, "UndercoverSafehouse", -1) )
    return 5i64;
  if ( !UFG::qStringCompareInsensitive(type, "BoostRegion", -1) )
    return 9i64;
  if ( !UFG::qStringCompareInsensitive(type, "MeleeUpgrade", -1) )
    return 10i64;
  if ( !UFG::qStringCompareInsensitive(type, "GhostOrb", -1) )
    return 11i64;
  if ( !UFG::qStringCompareInsensitive(type, "BombBag", -1) )
    return 12i64;
  v3 = UFG::qStringCompareInsensitive(type, "ZodiacStatue", -1);
  v4 = 0;
  if ( !v3 )
    return 13;
  return v4;
}

// File Line: 597
// RVA: 0xCEF70
UFG::UIAmbientMapBlipManager *__fastcall UFG::UIAmbientMapBlipManager::getInstance()
{
  UFG::UIAmbientMapBlipManager *result; // rax
  char *v1; // rax

  result = sUIAmbientMapBlipManager;
  if ( !sUIAmbientMapBlipManager )
  {
    v1 = UFG::qMalloc((unsigned int)((_DWORD)sUIAmbientMapBlipManager + 24), "UIAmbientMapBlipManager", 0i64);
    if ( v1 )
    {
      *((_QWORD *)v1 + 1) = 0i64;
      *(_QWORD *)v1 = 0i64;
      *((_QWORD *)v1 + 2) = 0i64;
    }
    else
    {
      v1 = 0i64;
    }
    sUIAmbientMapBlipManager = (UFG::UIAmbientMapBlipManager *)v1;
    UFG::UIAmbientMapBlipManager::Init((UFG::UIAmbientMapBlipManager *)v1);
    return sUIAmbientMapBlipManager;
  }
  return result;
}

// File Line: 611
// RVA: 0xC4F70
void __fastcall UFG::UIAmbientMapBlipManager::Init(UFG::UIAmbientMapBlipManager *this)
{
  UFG::UIAmbientMapBlipData *p; // rcx
  bool *p_mIconTypeSetAsCollected; // rbx
  SimpleXML::XMLDocument *v4; // rax
  SimpleXML::XMLDocument *v5; // rbp
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLDocument *v7; // rcx
  SimpleXML::XMLNode *i; // rdi
  char *Name; // rax
  unsigned int Attribute; // r15d
  char *v11; // rbx
  double v12; // xmm0_8
  float v13; // xmm6_4
  double v14; // xmm0_8
  float v15; // xmm7_4
  double v16; // xmm0_8
  char *v17; // r14
  UFG::UIAmbientMapBlipData::eCollectibleType v18; // ebx
  UFG::qWiseSymbol *v19; // rax
  int v20; // ecx
  UFG::UIAmbientMapBlipData::eZoneInfo v21; // eax
  UFG::UIAmbientMapBlipData item; // [rsp+28h] [rbp-A0h] BYREF
  UFG::qString v23; // [rsp+48h] [rbp-80h] BYREF
  UFG::qWiseSymbol result; // [rsp+D0h] [rbp+8h] BYREF

  UFG::qString::qString(&v23, "Data\\UI\\Game\\ui_ambient_map_blips.xml");
  p = this->mData.p;
  if ( p )
  {
    p_mIconTypeSetAsCollected = &p[-1].mIconTypeSetAsCollected;
    `eh vector destructor iterator(
      p,
      0x1Cui64,
      *(_DWORD *)&p[-1].mIconTypeSetAsCollected,
      (void (__fastcall *)(void *))_);
    operator delete[](p_mIconTypeSetAsCollected);
  }
  this->mData.p = 0i64;
  *(_QWORD *)&this->mData.size = 0i64;
  this->mCount = 0;
  v4 = SimpleXML::XMLDocument::Open(v23.mData, 1ui64, 0i64);
  v5 = v4;
  if ( v4 )
  {
    Node = SimpleXML::XMLDocument::GetNode(v4, "ambient_blips", 0i64);
    v7 = v5;
    if ( Node )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v5, 0i64, Node); i; i = SimpleXML::XMLDocument::GetNode(
                                                                               v5,
                                                                               0i64,
                                                                               i) )
      {
        Name = SimpleXML::XMLNode::GetName(i);
        if ( !UFG::qStringCompareInsensitive(Name, "blip", -1) )
        {
          Attribute = SimpleXML::XMLNode::GetAttribute(i, "nameID", 0);
          v11 = SimpleXML::XMLNode::GetAttribute(i, "type", "invalid");
          v12 = SimpleXML::XMLNode::GetAttribute(i, "pos_x", 0.0);
          v13 = *(float *)&v12;
          v14 = SimpleXML::XMLNode::GetAttribute(i, "pos_y", 0.0);
          v15 = *(float *)&v14;
          v16 = SimpleXML::XMLNode::GetAttribute(i, "pos_z", 0.0);
          v17 = SimpleXML::XMLNode::GetAttribute(i, "zone", "invalid");
          v18 = UFG::UIAmbientMapBlipData::XMLConvertBlipType(v11);
          if ( v18 != COLLECTIBLE_BUS_STOP )
          {
            v19 = UFG::qSymbol::qSymbol(&result, Attribute);
            item.mCollectibleType = v18;
            item.mID.mUID = v19->mUID;
            item.mIconTypeSetAsCollected = 0;
            item.mPosition.x = v13;
            item.mPosition.y = v15;
            item.mPosition.z = *(float *)&v16;
            v20 = v17[1] | (*v17 << 8);
            switch ( v20 )
            {
              case 20048:
                item.mZoneInfo = BOX;
                break;
              case 16706:
                item.mZoneInfo = SPHERE;
                break;
              case 19284:
                item.mZoneInfo = TRIANGLE;
                break;
              default:
                v21 = CAPSULE;
                if ( v20 == 17230 )
                  v21 = CYLINDER;
                item.mZoneInfo = v21;
                break;
            }
            UFG::qArray<UFG::UIAmbientMapBlipData,0>::Add(&this->mData, &item, "qArray.Add");
            ++this->mCount;
          }
        }
      }
      v7 = v5;
    }
    SimpleXML::XMLDocument::~XMLDocument(v7);
    operator delete[](v5);
  }
  UFG::qString::~qString(&v23);
}

// File Line: 671
// RVA: 0xC4B70
void __fastcall UFG::UIAmbientMapBlipManager::HandleScreenInit(UFG::UIAmbientMapBlipManager *this)
{
  int v1; // eax
  UFG::UIAmbientMapBlipData *v2; // rdx

  v1 = 0;
  for ( this->mUpdateTimer = 0.0; v1 < this->mCount; ++v1 )
  {
    v2 = &this->mData.p[v1];
    if ( v2 )
      v2->mIconTypeSetAsCollected = 0;
  }
}

// File Line: 728
// RVA: 0xC0D80
UFG::UIAmbientMapBlipData *__fastcall UFG::UIAmbientMapBlipManager::GetBlipData(
        UFG::UIAmbientMapBlipManager *this,
        int index)
{
  return &this->mData.p[index];
}

// File Line: 734
// RVA: 0xCBF90
void __fastcall UFG::UIAmbientMapBlipManager::Update(
        UFG::UIAmbientMapBlipManager *this,
        float elapsed,
        UFG::UIMapBlipManager *iconMan,
        bool isWorldMap)
{
  float v5; // xmm2_4
  int mCount; // esi
  int i; // ebx
  UFG::UIAmbientMapBlipData *v10; // rcx

  v5 = this->mUpdateTimer - elapsed;
  this->mUpdateTimer = v5;
  if ( v5 <= 0.0 )
  {
    this->mUpdateTimer = 2.0;
    if ( iconMan )
    {
      mCount = this->mCount;
      for ( i = 0; i < mCount; ++i )
      {
        v10 = &this->mData.p[i];
        if ( v10 )
          UFG::UIAmbientMapBlipData::UpdateIcon(v10, iconMan, isWorldMap, 0.0);
      }
    }
  }
}

