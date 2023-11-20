// File Line: 28
// RVA: 0xBB940
void __fastcall UFG::UIAmbientMapBlipData::UIAmbientMapBlipData(UFG::UIAmbientMapBlipData *this)
{
  this->mID.mUID = -1;
}

// File Line: 66
// RVA: 0xCD400
void __usercall UFG::UIAmbientMapBlipData::UpdateIcon(UFG::UIAmbientMapBlipData *this@<rcx>, UFG::UIMapBlipManager *iconManager@<rdx>, bool isWorldMap@<r8b>, float a4@<xmm0>)
{
  bool v4; // si
  UFG::UIMapBlipManager *v5; // rax
  UFG::UIAmbientMapBlipData *v6; // rdi
  unsigned int v7; // edx
  UFG::UIMapBlip *v8; // rbx
  UFG::UIMapBlipTypeManager *v9; // rax
  unsigned int v10; // er9
  UFG::UIHKMinimapBlipType *v11; // r11
  unsigned int v12; // edx
  unsigned int v13; // er9
  unsigned int v14; // er8
  unsigned int v15; // er10
  UFG::UIHKMinimapBlipType *v16; // rdx
  bool v17; // al
  UFG::UIMapBlipTypeManager *v18; // rax
  unsigned int v19; // er9
  UFG::UIHKMinimapBlipType *v20; // r11
  unsigned int v21; // edx
  unsigned int v22; // er9
  unsigned int v23; // er8
  unsigned int v24; // er10
  UFG::GameStatTracker *v25; // rax
  UFG::GameStat::BoolStat v26; // edx
  bool v27; // zf
  UFG::UIMapBlipTypeManager *v28; // rax
  unsigned int v29; // er9
  unsigned int v30; // edx
  unsigned int v31; // er9
  unsigned int v32; // er10
  UFG::UIMapBlipTypeManager *v33; // rax
  unsigned int v34; // er9
  unsigned int v35; // edx
  unsigned int v36; // er9
  unsigned int v37; // er10
  UFG::UIMapBlipTypeManager *v38; // rax
  unsigned int v39; // er9
  unsigned int v40; // edx
  unsigned int v41; // er9
  unsigned int v42; // er10
  UFG::GameStatTracker *v43; // rax
  UFG::UIMapBlipTypeManager *v44; // rax
  unsigned int v45; // er9
  unsigned int v46; // edx
  unsigned int v47; // er9
  unsigned int v48; // er10
  UFG::UIMapBlipTypeManager *v49; // rax
  unsigned int v50; // er9
  unsigned int v51; // edx
  unsigned int v52; // er9
  unsigned int v53; // er10
  UFG::UIMapBlipTypeManager *v54; // rax
  unsigned int v55; // er9
  unsigned int v56; // edx
  unsigned int v57; // er9
  unsigned int v58; // er10
  UFG::UIHKMinimapBlipType *v59; // rdx

  if ( iconManager )
  {
    v4 = isWorldMap;
    v5 = iconManager;
    v6 = this;
    v7 = this->mID.mUID;
    if ( v7 )
    {
      v8 = (UFG::UIMapBlip *)UFG::qBaseTreeRB::Get(&v5->mIconList.mIconData.mTree, v7);
      if ( v8 )
      {
        if ( v6->mCollectibleType )
        {
          switch ( v6->mCollectibleType )
          {
            case 1:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(v6) )
              {
                v25 = UFG::GameStatTracker::Instance();
                v26 = 8;
                goto LABEL_37;
              }
              v8->mChanged |= v8->mVisible != v4;
              v8->mVisible = v4;
              if ( v4 && !v6->mIconTypeSetAsCollected )
              {
                v6->mIconTypeSetAsCollected = 1;
                if ( !(_S14 & 8) )
                {
                  _S14 |= 8u;
                  UFG::qSymbolUC::create_from_string(&security_camera_collected, "security_camera_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_51_::_dynamic_atexit_destructor_for__security_camera_collected__);
                }
                v33 = UFG::UIMapBlipTypeManager::getInstance();
                if ( security_camera_collected.mUID != -1 )
                {
                  v34 = v33->mNumTypes;
                  if ( v34 )
                  {
                    v20 = v33->mData.p;
                    v35 = 0;
                    v36 = v34 - 1;
                    do
                    {
                      v23 = v35 + ((v36 - v35) >> 1);
                      v37 = v20[v35 + ((v36 - v35) >> 1)].TypeNameSymbol.mUID;
                      if ( v37 >= security_camera_collected.mUID )
                      {
                        if ( v37 <= security_camera_collected.mUID )
                          goto LABEL_130;
                        v36 = v23 - 1;
                      }
                      else
                      {
                        v35 = v23 + 1;
                      }
                    }
                    while ( v35 <= v36 );
                  }
                }
              }
              return;
            case 2:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(v6) )
              {
                v25 = UFG::GameStatTracker::Instance();
                v26 = 6;
                goto LABEL_37;
              }
              v8->mChanged |= v8->mVisible != v4;
              v8->mVisible = v4;
              if ( v4 && !v6->mIconTypeSetAsCollected )
              {
                v6->mIconTypeSetAsCollected = 1;
                if ( !(_S14 & 2) )
                {
                  _S14 |= 2u;
                  UFG::qSymbolUC::create_from_string(&shrine_collected, "shrine_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_25_::_dynamic_atexit_destructor_for__shrine_collected__);
                }
                v18 = UFG::UIMapBlipTypeManager::getInstance();
                if ( shrine_collected.mUID != -1 )
                {
                  v19 = v18->mNumTypes;
                  if ( v19 )
                  {
                    v20 = v18->mData.p;
                    v21 = 0;
                    v22 = v19 - 1;
                    do
                    {
                      v23 = v21 + ((v22 - v21) >> 1);
                      v24 = v20[v21 + ((v22 - v21) >> 1)].TypeNameSymbol.mUID;
                      if ( v24 >= shrine_collected.mUID )
                      {
                        if ( v24 <= shrine_collected.mUID )
                          goto LABEL_130;
                        v22 = v23 - 1;
                      }
                      else
                      {
                        v21 = v23 + 1;
                      }
                    }
                    while ( v21 <= v22 );
                  }
                }
              }
              return;
            case 3:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(v6) )
              {
                v25 = UFG::GameStatTracker::Instance();
                v26 = 7;
                goto LABEL_37;
              }
              v8->mChanged |= v8->mVisible != v4;
              v8->mVisible = v4;
              if ( v4 && !v6->mIconTypeSetAsCollected )
              {
                v6->mIconTypeSetAsCollected = 1;
                if ( !(_S14 & 0x10) )
                {
                  _S14 |= 0x10u;
                  UFG::qSymbolUC::create_from_string(&lockbox_collected, "lockbox_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_64_::_dynamic_atexit_destructor_for__lockbox_collected__);
                }
                v38 = UFG::UIMapBlipTypeManager::getInstance();
                if ( lockbox_collected.mUID != -1 )
                {
                  v39 = v38->mNumTypes;
                  if ( v39 )
                  {
                    v20 = v38->mData.p;
                    v40 = 0;
                    v41 = v39 - 1;
                    do
                    {
                      v23 = v40 + ((v41 - v40) >> 1);
                      v42 = v20[v40 + ((v41 - v40) >> 1)].TypeNameSymbol.mUID;
                      if ( v42 >= lockbox_collected.mUID )
                      {
                        if ( v42 <= lockbox_collected.mUID )
                          goto LABEL_130;
                        v41 = v23 - 1;
                      }
                      else
                      {
                        v40 = v23 + 1;
                      }
                    }
                    while ( v40 <= v41 );
                  }
                }
              }
              return;
            case 4:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(v6) )
                goto LABEL_21;
              if ( !(_S14 & 1) )
              {
                _S14 |= 1u;
                UFG::qSymbolUC::create_from_string(&safe_house_unlocked, "safe_house_unlocked");
                atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_18_::_dynamic_atexit_destructor_for__safe_house_unlocked__);
              }
              v9 = UFG::UIMapBlipTypeManager::getInstance();
              if ( safe_house_unlocked.mUID == -1 )
                goto LABEL_21;
              v10 = v9->mNumTypes;
              if ( !v10 )
                goto LABEL_21;
              v11 = v9->mData.p;
              v12 = 0;
              v13 = v10 - 1;
              while ( 1 )
              {
                v14 = v12 + ((v13 - v12) >> 1);
                v15 = v11[v12 + ((v13 - v12) >> 1)].TypeNameSymbol.mUID;
                if ( v15 >= safe_house_unlocked.mUID )
                {
                  if ( v15 <= safe_house_unlocked.mUID )
                  {
                    v16 = &v11[v14];
                    if ( v16 )
                      UFG::UIMapBlip::SetType(v8, v16, a4);
                    goto LABEL_21;
                  }
                  v13 = v14 - 1;
                }
                else
                {
                  v12 = v14 + 1;
                }
                if ( v12 > v13 )
                  goto LABEL_21;
              }
            case 5:
            case 6:
            case 7:
              goto LABEL_21;
            case 9:
              v43 = UFG::GameStatTracker::Instance();
              if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v43, EnableJumpIndicators) )
                goto LABEL_38;
LABEL_21:
              v17 = UFG::UIAmbientMapBlipData::IsCollected(v6);
              v8->mChanged |= v8->mVisible != v17;
              v8->mVisible = v17;
              return;
            case 0xA:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(v6) )
              {
                v25 = UFG::GameStatTracker::Instance();
                v26 = 9;
                goto LABEL_37;
              }
              v8->mChanged |= v8->mVisible != v4;
              v8->mVisible = v4;
              if ( v4 && !v6->mIconTypeSetAsCollected )
              {
                v6->mIconTypeSetAsCollected = 1;
                if ( !(_S14 & 4) )
                {
                  _S14 |= 4u;
                  UFG::qSymbolUC::create_from_string(&shrine_collected_0, "melee_upgrade_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_38_::_dynamic_atexit_destructor_for__shrine_collected__);
                }
                v28 = UFG::UIMapBlipTypeManager::getInstance();
                if ( shrine_collected_0.mUID != -1 )
                {
                  v29 = v28->mNumTypes;
                  if ( v29 )
                  {
                    v20 = v28->mData.p;
                    v30 = 0;
                    v31 = v29 - 1;
                    do
                    {
                      v23 = v30 + ((v31 - v30) >> 1);
                      v32 = v20[v30 + ((v31 - v30) >> 1)].TypeNameSymbol.mUID;
                      if ( v32 >= shrine_collected_0.mUID )
                      {
                        if ( v32 <= shrine_collected_0.mUID )
                          goto LABEL_130;
                        v31 = v23 - 1;
                      }
                      else
                      {
                        v30 = v23 + 1;
                      }
                    }
                    while ( v30 <= v31 );
                  }
                }
              }
              return;
            case 0xB:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(v6) )
              {
                v25 = UFG::GameStatTracker::Instance();
                v26 = 12;
                goto LABEL_37;
              }
              v8->mChanged |= v8->mVisible != v4;
              v8->mVisible = v4;
              if ( v4 && !v6->mIconTypeSetAsCollected )
              {
                v6->mIconTypeSetAsCollected = 1;
                if ( !(_S14 & 0x20) )
                {
                  _S14 |= 0x20u;
                  UFG::qSymbolUC::create_from_string(&ghost_orb_collected, "ghost_orb_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_83_::_dynamic_atexit_destructor_for__ghost_orb_collected__);
                }
                v44 = UFG::UIMapBlipTypeManager::getInstance();
                if ( ghost_orb_collected.mUID != -1 )
                {
                  v45 = v44->mNumTypes;
                  if ( v45 )
                  {
                    v20 = v44->mData.p;
                    v46 = 0;
                    v47 = v45 - 1;
                    do
                    {
                      v23 = v46 + ((v47 - v46) >> 1);
                      v48 = v20[v46 + ((v47 - v46) >> 1)].TypeNameSymbol.mUID;
                      if ( v48 >= ghost_orb_collected.mUID )
                      {
                        if ( v48 <= ghost_orb_collected.mUID )
                          goto LABEL_130;
                        v47 = v23 - 1;
                      }
                      else
                      {
                        v46 = v23 + 1;
                      }
                    }
                    while ( v46 <= v47 );
                  }
                }
              }
              return;
            case 0xC:
              if ( !UFG::UIAmbientMapBlipData::IsCollected(v6) )
              {
                v25 = UFG::GameStatTracker::Instance();
                v26 = 14;
                goto LABEL_37;
              }
              v8->mChanged |= v8->mVisible != v4;
              v8->mVisible = v4;
              if ( v4 && !v6->mIconTypeSetAsCollected )
              {
                v6->mIconTypeSetAsCollected = 1;
                if ( (_S14 & 0x80u) == 0 )
                {
                  _S14 |= 0x80u;
                  UFG::qSymbolUC::create_from_string(&evidence_bag_collected, "evidence_bag_collected");
                  atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_109_::_dynamic_atexit_destructor_for__evidence_bag_collected__);
                }
                v54 = UFG::UIMapBlipTypeManager::getInstance();
                if ( evidence_bag_collected.mUID != -1 )
                {
                  v55 = v54->mNumTypes;
                  if ( v55 )
                  {
                    v20 = v54->mData.p;
                    v56 = 0;
                    v57 = v55 - 1;
                    do
                    {
                      v23 = v56 + ((v57 - v56) >> 1);
                      v58 = v20[v56 + ((v57 - v56) >> 1)].TypeNameSymbol.mUID;
                      if ( v58 >= evidence_bag_collected.mUID )
                      {
                        if ( v58 <= evidence_bag_collected.mUID )
                          goto LABEL_130;
                        v57 = v23 - 1;
                      }
                      else
                      {
                        v56 = v23 + 1;
                      }
                    }
                    while ( v56 <= v57 );
                  }
                }
              }
              return;
            case 0xD:
              if ( UFG::UIAmbientMapBlipData::IsCollected(v6) )
              {
                v8->mChanged |= v8->mVisible != v4;
                v8->mVisible = v4;
                if ( v4 && !v6->mIconTypeSetAsCollected )
                {
                  v6->mIconTypeSetAsCollected = 1;
                  if ( !(_S14 & 0x40) )
                  {
                    _S14 |= 0x40u;
                    UFG::qSymbolUC::create_from_string(&fire_statue_collected, "fire_statue_collected");
                    atexit(UFG::UIAmbientMapBlipData::UpdateIcon_::_96_::_dynamic_atexit_destructor_for__fire_statue_collected__);
                  }
                  v49 = UFG::UIMapBlipTypeManager::getInstance();
                  if ( fire_statue_collected.mUID != -1 )
                  {
                    v50 = v49->mNumTypes;
                    if ( v50 )
                    {
                      v20 = v49->mData.p;
                      v51 = 0;
                      v52 = v50 - 1;
                      while ( 1 )
                      {
                        v23 = v51 + ((v52 - v51) >> 1);
                        v53 = v20[v51 + ((v52 - v51) >> 1)].TypeNameSymbol.mUID;
                        if ( v53 >= fire_statue_collected.mUID )
                        {
                          if ( v53 <= fire_statue_collected.mUID )
                          {
LABEL_130:
                            v59 = &v20[v23];
                            if ( v59 )
                              UFG::UIMapBlip::SetType(v8, v59, a4);
                            return;
                          }
                          v52 = v23 - 1;
                        }
                        else
                        {
                          v51 = v23 + 1;
                        }
                        if ( v51 > v52 )
                          return;
                      }
                    }
                  }
                }
              }
              else
              {
                v25 = UFG::GameStatTracker::Instance();
                v26 = 13;
LABEL_37:
                if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v25, v26) )
                {
LABEL_38:
                  v27 = v8->mVisible == 1;
                  v8->mVisible = 1;
                }
                else
                {
                  v27 = v8->mVisible == 0;
                  v8->mVisible = 0;
                }
                v8->mChanged |= !v27;
              }
              break;
            default:
              return;
          }
        }
        else
        {
          v8->mChanged |= v8->mVisible != 1;
          v8->mVisible = 1;
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
  const char *v2; // [rsp+0h] [rbp-78h]
  const char *v3; // [rsp+8h] [rbp-70h]
  const char *v4; // [rsp+10h] [rbp-68h]
  const char *v5; // [rsp+18h] [rbp-60h]
  const char *v6; // [rsp+20h] [rbp-58h]
  const char *v7; // [rsp+28h] [rbp-50h]
  const char *v8; // [rsp+30h] [rbp-48h]
  const char *v9; // [rsp+38h] [rbp-40h]
  const char *v10; // [rsp+40h] [rbp-38h]
  const char *v11; // [rsp+48h] [rbp-30h]
  const char *v12; // [rsp+50h] [rbp-28h]
  const char *v13; // [rsp+58h] [rbp-20h]
  const char *v14; // [rsp+60h] [rbp-18h]
  const char *v15; // [rsp+68h] [rbp-10h]

  v2 = "Generic_Interactive_Object";
  v3 = "security_camera";
  v4 = "shrine";
  v5 = "lockbox";
  v6 = "safe_house";
  v7 = "undercover_safe_house";
  v8 = "hiding_spot";
  v9 = "hiding_spot_garage";
  v10 = "bus_stop";
  v11 = "jump";
  v12 = "melee_upgrade";
  v13 = "ghost_orb";
  v14 = "fire_statue";
  v15 = "evidence_bag";
  return (&v2)[this->mCollectibleType];
}

// File Line: 366
// RVA: 0xC5BF0
bool __fastcall UFG::UIAmbientMapBlipData::IsCollected(UFG::UIAmbientMapBlipData *this)
{
  UFG::UIAmbientMapBlipData *v1; // rbx
  UFG::GameStatTracker *v2; // rax
  UFG::GameStat::MapBoolStat v3; // edx
  UFG::PersistentData::MapBool *v4; // rax
  UFG::UIAmbientMapBlipData::eZoneInfo v6; // ecx
  int v7; // ecx
  int v8; // ecx
  UFG::UIAmbientMapBlipData::eZoneInfo v9; // ecx
  int v10; // ecx
  int v11; // ecx

  v1 = this;
  switch ( this->mCollectibleType )
  {
    case 1:
      v2 = UFG::GameStatTracker::Instance();
      v3 = 31;
      goto LABEL_3;
    case 2:
      v6 = this->mZoneInfo;
      if ( v6 )
      {
        v7 = v6 - 1;
        if ( v7 )
        {
          v8 = v7 - 1;
          if ( v8 )
          {
            if ( v8 != 1 )
              return 0;
            v2 = UFG::GameStatTracker::Instance();
            v3 = 26;
          }
          else
          {
            v2 = UFG::GameStatTracker::Instance();
            v3 = 25;
          }
        }
        else
        {
          v2 = UFG::GameStatTracker::Instance();
          v3 = 24;
        }
      }
      else
      {
        v2 = UFG::GameStatTracker::Instance();
        v3 = 23;
      }
      goto LABEL_3;
    case 3:
      v9 = this->mZoneInfo;
      if ( v9 == SPHERE )
      {
        v2 = UFG::GameStatTracker::Instance();
        v3 = 27;
        goto LABEL_3;
      }
      v10 = v9 - 1;
      if ( !v10 )
      {
        v2 = UFG::GameStatTracker::Instance();
        v3 = 28;
        goto LABEL_3;
      }
      v11 = v10 - 1;
      if ( !v11 )
      {
        v2 = UFG::GameStatTracker::Instance();
        v3 = 29;
        goto LABEL_3;
      }
      if ( v11 == 1 )
      {
        v2 = UFG::GameStatTracker::Instance();
        v3 = 30;
LABEL_3:
        v4 = UFG::GameStatTracker::GetMapBool(v2, v3);
        return UFG::PersistentData::MapBool::GetStatus(v4, &v1->mID);
      }
      return 0;
    case 4:
    case 5:
      v2 = UFG::GameStatTracker::Instance();
      v3 = 12;
      goto LABEL_3;
    case 6:
    case 7:
      v2 = UFG::GameStatTracker::Instance();
      v3 = 5;
      goto LABEL_3;
    case 8:
      v2 = UFG::GameStatTracker::Instance();
      v3 = 3;
      goto LABEL_3;
    case 9:
      v2 = UFG::GameStatTracker::Instance();
      v3 = 1;
      goto LABEL_3;
    case 0xA:
      v2 = UFG::GameStatTracker::Instance();
      v3 = 6;
      goto LABEL_3;
    case 0xB:
      v2 = UFG::GameStatTracker::Instance();
      v3 = 34;
      goto LABEL_3;
    case 0xC:
      v2 = UFG::GameStatTracker::Instance();
      v3 = 36;
      goto LABEL_3;
    case 0xD:
      v2 = UFG::GameStatTracker::Instance();
      v3 = 35;
      goto LABEL_3;
    default:
      return 0;
  }
}

// File Line: 500
// RVA: 0xCEAF0
signed __int64 __fastcall UFG::UIAmbientMapBlipData::XMLConvertBlipType(const char *type)
{
  const char *v1; // rbx
  int v3; // eax
  unsigned int v4; // ecx

  v1 = type;
  if ( !UFG::qStringCompareInsensitive(type, "HidingSpot", -1) )
    return 6i64;
  if ( !UFG::qStringCompareInsensitive(v1, "HealthShrine", -1) )
    return 2i64;
  if ( !UFG::qStringCompareInsensitive(v1, "LockBox", -1) )
    return 3i64;
  if ( !UFG::qStringCompareInsensitive(v1, "SpyCam", -1) )
    return 1i64;
  if ( !UFG::qStringCompareInsensitive(v1, "BusStop", -1) )
    return 8i64;
  if ( !UFG::qStringCompareInsensitive(v1, "Safehouse", -1) )
    return 4i64;
  if ( !UFG::qStringCompareInsensitive(v1, "UndercoverSafehouse", -1) )
    return 5i64;
  if ( !UFG::qStringCompareInsensitive(v1, "BoostRegion", -1) )
    return 9i64;
  if ( !UFG::qStringCompareInsensitive(v1, "MeleeUpgrade", -1) )
    return 10i64;
  if ( !UFG::qStringCompareInsensitive(v1, "GhostOrb", -1) )
    return 11i64;
  if ( !UFG::qStringCompareInsensitive(v1, "BombBag", -1) )
    return 12i64;
  v3 = UFG::qStringCompareInsensitive(v1, "ZodiacStatue", -1);
  v4 = 0;
  if ( !v3 )
    v4 = 13;
  return v4;
}

// File Line: 597
// RVA: 0xCEF70
UFG::UIAmbientMapBlipManager *__fastcall UFG::UIAmbientMapBlipManager::getInstance(float a1)
{
  UFG::UIAmbientMapBlipManager *result; // rax
  char *v2; // rax

  result = sUIAmbientMapBlipManager;
  if ( !sUIAmbientMapBlipManager )
  {
    v2 = UFG::qMalloc((unsigned int)((_DWORD)sUIAmbientMapBlipManager + 24), "UIAmbientMapBlipManager", 0i64);
    if ( v2 )
    {
      *((_QWORD *)v2 + 1) = 0i64;
      *(_QWORD *)v2 = 0i64;
      *((_QWORD *)v2 + 2) = 0i64;
    }
    else
    {
      v2 = 0i64;
    }
    sUIAmbientMapBlipManager = (UFG::UIAmbientMapBlipManager *)v2;
    UFG::UIAmbientMapBlipManager::Init((UFG::UIAmbientMapBlipManager *)v2, a1);
    result = sUIAmbientMapBlipManager;
  }
  return result;
}

// File Line: 611
// RVA: 0xC4F70
void __usercall UFG::UIAmbientMapBlipManager::Init(UFG::UIAmbientMapBlipManager *this@<rcx>, float a2@<xmm0>)
{
  UFG::UIAmbientMapBlipManager *v2; // rsi
  UFG::UIAmbientMapBlipData *v3; // rcx
  bool *v4; // rbx
  SimpleXML::XMLDocument *v5; // rax
  SimpleXML::XMLDocument *v6; // rbp
  SimpleXML::XMLNode *v7; // rax
  SimpleXML::XMLDocument *v8; // rcx
  SimpleXML::XMLNode *i; // rdi
  char *v10; // rax
  unsigned int v11; // er15
  char *v12; // rbx
  char *v13; // r14
  UFG::UIAmbientMapBlipData::eCollectibleType v14; // ebx
  UFG::qWiseSymbol *v15; // rax
  int v16; // ecx
  UFG::UIAmbientMapBlipData::eZoneInfo v17; // eax
  UFG::UIAmbientMapBlipData item; // [rsp+28h] [rbp-A0h]
  UFG::qString v19; // [rsp+48h] [rbp-80h]
  UFG::qWiseSymbol result; // [rsp+D0h] [rbp+8h]

  v2 = this;
  UFG::qString::qString(&v19, "Data\\UI\\Game\\ui_ambient_map_blips.xml");
  v3 = v2->mData.p;
  if ( v3 )
  {
    v4 = &v3[-1].mIconTypeSetAsCollected;
    `eh vector destructor iterator(
      v3,
      0x1Cui64,
      *(_DWORD *)&v3[-1].mIconTypeSetAsCollected,
      (void (__fastcall *)(void *))_);
    operator delete[](v4);
  }
  v2->mData.p = 0i64;
  *(_QWORD *)&v2->mData.size = 0i64;
  v2->mCount = 0;
  v5 = SimpleXML::XMLDocument::Open(v19.mData, 1ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    v7 = SimpleXML::XMLDocument::GetNode(v5, "ambient_blips", 0i64);
    v8 = v6;
    if ( v7 )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v6, 0i64, v7); i; i = SimpleXML::XMLDocument::GetNode(v6, 0i64, i) )
      {
        if ( i )
        {
          v10 = SimpleXML::XMLNode::GetName(i);
          if ( !UFG::qStringCompareInsensitive(v10, "blip", -1) )
          {
            v11 = SimpleXML::XMLNode::GetAttribute(i, "nameID", 0);
            v12 = SimpleXML::XMLNode::GetAttribute(i, "type", "invalid");
            SimpleXML::XMLNode::GetAttribute(i, "pos_x", 0.0);
            SimpleXML::XMLNode::GetAttribute(i, "pos_y", 0.0);
            SimpleXML::XMLNode::GetAttribute(i, "pos_z", 0.0);
            v13 = SimpleXML::XMLNode::GetAttribute(i, "zone", "invalid");
            v14 = UFG::UIAmbientMapBlipData::XMLConvertBlipType(v12);
            if ( v14 != 8 )
            {
              v15 = UFG::qSymbol::qSymbol(&result, v11);
              item.mCollectibleType = v14;
              item.mID.mUID = v15->mUID;
              item.mIconTypeSetAsCollected = 0;
              item.mPosition.x = a2;
              item.mPosition.y = a2;
              item.mPosition.z = a2;
              v16 = v13[1] | (*v13 << 8);
              switch ( v16 )
              {
                case 20048:
                  item.mZoneInfo = 3;
                  break;
                case 16706:
                  item.mZoneInfo = 0;
                  break;
                case 19284:
                  item.mZoneInfo = 2;
                  break;
                default:
                  v17 = 4;
                  if ( v16 == 17230 )
                    v17 = 1;
                  item.mZoneInfo = v17;
                  break;
              }
              UFG::qArray<UFG::UIAmbientMapBlipData,0>::Add(&v2->mData, &item, "qArray.Add");
              ++v2->mCount;
            }
          }
        }
      }
      v8 = v6;
    }
    SimpleXML::XMLDocument::~XMLDocument(v8);
    operator delete[](v6);
  }
  UFG::qString::~qString(&v19);
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
UFG::UIAmbientMapBlipData *__fastcall UFG::UIAmbientMapBlipManager::GetBlipData(UFG::UIAmbientMapBlipManager *this, int index)
{
  return &this->mData.p[index];
}

// File Line: 734
// RVA: 0xCBF90
void __fastcall UFG::UIAmbientMapBlipManager::Update(UFG::UIAmbientMapBlipManager *this, float elapsed, UFG::UIMapBlipManager *iconMan, bool isWorldMap)
{
  bool v4; // r14
  float v5; // xmm2_4
  UFG::UIMapBlipManager *v6; // rbp
  UFG::UIAmbientMapBlipManager *v7; // rdi
  int v8; // esi
  int i; // ebx
  UFG::UIAmbientMapBlipData *v10; // rcx

  v4 = isWorldMap;
  v5 = this->mUpdateTimer - elapsed;
  v6 = iconMan;
  v7 = this;
  this->mUpdateTimer = v5;
  if ( v5 <= 0.0 )
  {
    this->mUpdateTimer = 2.0;
    if ( iconMan )
    {
      v8 = this->mCount;
      for ( i = 0; i < v8; ++i )
      {
        v10 = &v7->mData.p[i];
        if ( v10 )
          UFG::UIAmbientMapBlipData::UpdateIcon(v10, v6, v4, 0.0);
      }
    }
  }
}

