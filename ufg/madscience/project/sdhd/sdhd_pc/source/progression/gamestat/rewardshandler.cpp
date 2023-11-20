// File Line: 39
// RVA: 0x152FD30
__int64 UFG::_dynamic_initializer_for__qSymbol_Type__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Type", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_Type, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_Type__);
}

// File Line: 40
// RVA: 0x152E230
__int64 UFG::_dynamic_initializer_for__qSymbol_AssetId__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AssetId", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_AssetId, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_AssetId__);
}

// File Line: 41
// RVA: 0x152FBF0
__int64 UFG::_dynamic_initializer_for__qSymbol_Text__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Text", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_Text, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_Text__);
}

// File Line: 42
// RVA: 0x152F130
__int64 UFG::_dynamic_initializer_for__qSymbol_Icon__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Icon", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_Icon, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_Icon__);
}

// File Line: 43
// RVA: 0x152F970
__int64 UFG::_dynamic_initializer_for__qSymbol_Permanent__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Permanent", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_Permanent, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_Permanent__);
}

// File Line: 45
// RVA: 0x152FDB0
__int64 UFG::_dynamic_initializer_for__qSymbol_UIMissionComplete__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MISSION_COMPLETE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_UIMissionComplete, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_UIMissionComplete__);
}

// File Line: 46
// RVA: 0x152FD70
__int64 UFG::_dynamic_initializer_for__qSymbol_UIHintText__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("HINT_TEXT", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_UIHintText, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_UIHintText__);
}

// File Line: 48
// RVA: 0x152F770
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierNone__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("None", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierNone, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierNone__);
}

// File Line: 49
// RVA: 0x152F6F0
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierMinor__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Minor", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierMinor, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierMinor__);
}

// File Line: 50
// RVA: 0x152F670
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierMiddle__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Middle", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierMiddle, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierMiddle__);
}

// File Line: 51
// RVA: 0x152F5F0
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierMajor__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Major", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierMajor, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierMajor__);
}

// File Line: 56
// RVA: 0x4A7D30
void __fastcall UFG::RewardsHandler::HandleRewardList(UFG::ShowRewardType showRewardType, UFG::qPropertySet *pItemPropertySet, __int64 uiscreen_type)
{
  unsigned int *v3; // r12
  UFG::qPropertySet *v4; // rsi
  bool v5; // di
  unsigned int v6; // ebx
  char *v7; // r15
  bool *v8; // rax
  bool v9; // r14
  char *v10; // rdi
  char *v11; // rax
  unsigned int v12; // eax
  UFG::GameLogManager *v13; // rcx
  UFG::GameStatTracker *v14; // rdi
  UFG::GameStatTracker *v15; // rax
  unsigned int v16; // edx
  UFG::GameStatTracker *v17; // r8
  UFG::GameStatTracker *v18; // rax
  __int64 v19; // rax
  UFG::GameStatTracker *v20; // rax
  UFG::GameStatTracker *v21; // rax
  UFG::GameStat::MapBoolStat v22; // ecx
  UFG::GameStatTracker *v23; // rax
  UFG::qBaseNodeRB *v24; // rax
  UFG::DoorComponent *v25; // rax
  UFG::GameStatTracker *v26; // rax
  UFG::GameStatTracker *v27; // rax
  UFG::GameStatTracker *v28; // rax
  unsigned int v29; // ecx
  UFG::GameStatTracker *v30; // r8
  __int64 v31; // rax
  UFG::GameStatTracker *v32; // rax
  UFG::qSymbol *v33; // rax
  UFG::qSymbol *v34; // rax
  UFG::qSymbol *v35; // rax
  UFG::GameStatTracker *v36; // rsi
  UFG::eFactionStandingEnum v37; // edi
  UFG::eFactionClassEnum v38; // ebx
  UFG::eFactionClassEnum v39; // eax
  UFG::GameStatTracker *v40; // rax
  UFG::GameStatTracker *v41; // rax
  UFG::qSymbol *v42; // rax
  unsigned int *v43; // rax
  UFG::qSymbol *v44; // rbx
  UFG::GameStatTracker *v45; // rax
  unsigned int v46; // edx
  UFG::GameStatTracker *v47; // r8
  __int64 v48; // rax
  UFG::qSymbol *v49; // rax
  int v50; // ebx
  UFG::GameStatTracker *v51; // rax
  UFG::UIHKScreenHud *v52; // rax
  UFG::GameStatTracker *v53; // rax
  UFG::qSymbol *v54; // rax
  int v55; // ebx
  UFG::GameStatTracker *v56; // rax
  UFG::ProgressionTracker *v57; // rax
  UFG::ProgressionTracker *v58; // rdi
  UFG::qBaseTreeRB *v59; // rbx
  UFG::qSymbol *v60; // rax
  bool *v61; // rax
  bool *v62; // rdx
  UFG::GameStatTracker *v63; // rax
  AnimationGroupHandleContainer *v64; // rdi
  UFG::GameSnapshot *v65; // rdx
  UFG::GameStatTracker *v66; // rax
  UFG::GameStatTracker *v67; // rax
  UFG::GameStatTracker *v68; // rax
  UFG::GameStatTracker *v69; // rax
  UFG::GameStatTracker *v70; // rax
  UFG::GameStatTracker *v71; // rax
  UFG::GameStatTracker *v72; // rax
  UFG::qSymbol v73[2]; // [rsp+8h] [rbp-39h]
  UFG::qSymbol assetID; // [rsp+10h] [rbp-31h]
  UFG::qSymbol symbol; // [rsp+14h] [rbp-2Dh]
  UFG::qSymbol v76[2]; // [rsp+18h] [rbp-29h]
  UFG::qSymbol v77; // [rsp+20h] [rbp-21h]
  UFG::qSymbol v78; // [rsp+24h] [rbp-1Dh]
  UFG::qSymbol v79; // [rsp+28h] [rbp-19h]
  UFG::qSymbol v80; // [rsp+2Ch] [rbp-15h]
  UFG::qSymbol v81; // [rsp+30h] [rbp-11h]
  UFG::qSymbol v82; // [rsp+34h] [rbp-Dh]
  UFG::qWiseSymbol v83; // [rsp+38h] [rbp-9h]
  __int64 v84; // [rsp+40h] [rbp-1h]
  UFG::qString v85; // [rsp+48h] [rbp+7h]
  UFG::qSymbol uiscreen_typea; // [rsp+A8h] [rbp+67h]
  UFG::qSymbol result; // [rsp+C0h] [rbp+7Fh]

  v84 = -2i64;
  v3 = (unsigned int *)uiscreen_type;
  v4 = pItemPropertySet;
  v5 = showRewardType == 0;
  v6 = PropertyUtils::Get<UFG::qSymbol>(pItemPropertySet, (UFG::qSymbol *)&qSymbol_Type.mUID, DEPTH_RECURSE)->mUID;
  v7 = PropertyUtils::Get<char const *>(v4, (UFG::qSymbol *)&qSymbol_AssetId.mUID, DEPTH_RECURSE);
  UFG::qSymbol::create_from_string(&result, v7);
  v8 = PropertyUtils::Get<bool>(v4, (UFG::qSymbol *)&qSymbol_Permanent.mUID, DEPTH_RECURSE);
  if ( v8 )
    v9 = *v8;
  else
    v9 = 0;
  if ( v5 )
  {
    v10 = PropertyUtils::Get<char const *>(v4, (UFG::qSymbol *)&qSymbol_Text.mUID, DEPTH_RECURSE);
    v11 = PropertyUtils::Get<char const *>(v4, (UFG::qSymbol *)&qSymbol_Icon.mUID, DEPTH_RECURSE);
    v12 = UFG::qStringHash32(v11, 0xFFFFFFFF);
    *(_QWORD *)&v76[0].mUID = &uiscreen_typea;
    uiscreen_typea.mUID = *v3;
    UFG::UIHKScreenMissionComplete::AddReward(v10, v12, (__int64)&uiscreen_typea);
    uiscreen_typea.mUID = qSymbol_GameLogType_RewardsUpgrades_14.mUID;
    v13 = UFG::GameLogManager::getInstance();
    UFG::GameLogManager::LogItem(v13, (UFG::qSymbol)&uiscreen_typea, v10);
    UFG::RewardsHandler::mItemUnlocked = 1;
  }
  v14 = &sGameStatTracker;
  if ( v9 )
  {
    v15 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v15 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v15->mpSnapshots[0]->mpMapBools[83], &result, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v16 = _S12_6;
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v16 = _S12_6;
        }
        v17 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v17 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v17;
        if ( !(v16 & 1) )
        {
          _S12_6 = v16 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v17 = UFG::GameStatTracker::mspInstance;
        }
        v18 = &sGameStatTracker;
        if ( v17 )
          v18 = v17;
        UFG::GameStatTracker::mspInstance = v18;
        v19 = v18->mpSnapshots[0]->mpMapBools[83]->mKeepType;
      }
    }
  }
  if ( v6 > 0x6732E074 )
  {
    if ( v6 > 0x958197CB )
    {
      if ( v6 > 0xAD5FAF23 )
      {
        if ( v6 == -129728948 )
        {
          v72 = UFG::GameStatTracker::Instance();
          if ( !(*((_BYTE *)v72 + 6216) & 1) )
          {
            UFG::PersistentData::MapBool::SetStatus(v72->mpSnapshots[0]->mpMapBools[0], &result, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
              uiscreen_typea.mUID = result.mUID;
              v22 = 0;
              goto LABEL_137;
            }
          }
        }
        else if ( v6 == -74896581 )
        {
          v71 = UFG::GameStatTracker::Instance();
          if ( !(*((_BYTE *)v71 + 6216) & 1) )
          {
            UFG::PersistentData::MapBool::SetStatus(v71->mpSnapshots[0]->mpMapBools[6], &result, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
              uiscreen_typea.mUID = result.mUID;
              v22 = 6;
              goto LABEL_137;
            }
          }
        }
      }
      else
      {
        switch ( v6 )
        {
          case 0xAD5FAF23:
            v70 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v70, Collectible_CaseDoc, &result, 1);
            return;
          case 0x9773EC16:
            v69 = UFG::GameStatTracker::Instance();
            if ( !(*((_BYTE *)v69 + 6216) & 1) )
            {
              UFG::PersistentData::MapBool::SetStatus(v69->mpSnapshots[0]->mpMapBools[61], &result, 1);
              if ( UFG::GameStatAction::PostStat::sIsEnabled )
              {
                *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
                uiscreen_typea.mUID = result.mUID;
                v22 = 61;
                goto LABEL_137;
              }
            }
            break;
          case 0x9B06086B:
            v68 = UFG::GameStatTracker::Instance();
            if ( !(*((_BYTE *)v68 + 6216) & 1) )
            {
              UFG::PersistentData::MapBool::SetStatus(v68->mpSnapshots[0]->mpMapBools[62], &result, 1);
              if ( UFG::GameStatAction::PostStat::sIsEnabled )
              {
                *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
                uiscreen_typea.mUID = result.mUID;
                v22 = 62;
                goto LABEL_137;
              }
            }
            break;
          case 0xACB107F7:
            v67 = UFG::GameStatTracker::Instance();
            if ( !(*((_BYTE *)v67 + 6216) & 1) )
            {
              UFG::PersistentData::MapBool::SetStatus(v67->mpSnapshots[0]->mpMapBools[63], &result, 1);
              if ( UFG::GameStatAction::PostStat::sIsEnabled )
              {
                *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
                uiscreen_typea.mUID = result.mUID;
                v22 = 63;
                goto LABEL_137;
              }
            }
            break;
        }
      }
      return;
    }
    if ( v6 == -1786669109 )
    {
      v64 = &UFG::ProgressionTracker::Instance()->mAnimationGroupHandleContainer;
      v65 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
      if ( v65->mStrings[6].mValue.mLength )
        AnimationGroupHandleContainer::Remove(v64, v65->mStrings[6].mValue.mData);
      UFG::qString::qString(&v85, v7);
      v66 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v66 + 6216) & 1) )
        UFG::qString::Set(&v66->mpSnapshots[0]->mStrings[6].mValue, v85.mData, v85.mLength, 0i64, 0);
      UFG::qString::~qString(&v85);
      AnimationGroupHandleContainer::Add(v64, v7, eANIM_PRIORITY_REQUIRED);
      AnimationGroupHandleContainer::Bind(v64);
      return;
    }
    if ( v6 <= 0x8A5A95FC )
    {
      switch ( v6 )
      {
        case 0x8A5A95FC:
          v53 = UFG::GameStatTracker::Instance();
          if ( !(*((_BYTE *)v53 + 6216) & 1) )
          {
            UFG::PersistentData::MapBool::SetStatus(v53->mpSnapshots[0]->mpMapBools[64], &result, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
              uiscreen_typea.mUID = result.mUID;
              v22 = 64;
              goto LABEL_137;
            }
          }
          break;
        case 0x748078A5u:
          v49 = UFG::qSymbol::create_from_string(&v78, "Status");
          v50 = *PropertyUtils::Get<long>(v4, v49, DEPTH_RECURSE);
          v51 = UFG::GameStatTracker::Instance();
          if ( !(*((_BYTE *)v51 + 6216) & 1) )
          {
            UFG::PersistentData::MapInt::SetStatus(v51->mpSnapshots[0]->mpMapInts[18], &result, v50);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              uiscreen_typea.mUID = result.mUID;
              UFG::GameStatAction::PostStat::AchieveMapInt(Collectible_CaseLeads, (UFG::qSymbol)&uiscreen_typea);
            }
          }
          if ( v50 == 2 )
          {
            v52 = UFG::UIHKScreenHud::getInstance();
            if ( v52 )
              UFG::UIHKScreenHud::LeadUnlocked(v52, (UFG::qSymbol)&assetID);
          }
          break;
        case 0x810BC917:
          v41 = UFG::GameStatTracker::Instance();
          if ( !(*((_BYTE *)v41 + 6216) & 1) )
            v41->mpSnapshots[0]->mBools[2].mValue = 1;
          v42 = UFG::qSymbol::create_from_string(&v77, "BioId");
          v43 = (unsigned int *)UFG::qPropertySet::Get<long>(v4, v42, DEPTH_RECURSE);
          v44 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v83, *v43);
          v45 = UFG::GameStatTracker::Instance();
          if ( !(*((_BYTE *)v45 + 6216) & 1) )
          {
            UFG::PersistentData::MapBool::SetStatus(v45->mpSnapshots[0]->mpMapBools[22], v44, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              v46 = _S12_6;
              if ( !(_S12_6 & 1) )
              {
                _S12_6 |= 1u;
                UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                v46 = _S12_6;
              }
              v47 = &sGameStatTracker;
              if ( UFG::GameStatTracker::mspInstance )
                v47 = UFG::GameStatTracker::mspInstance;
              UFG::GameStatTracker::mspInstance = v47;
              if ( !(v46 & 1) )
              {
                _S12_6 = v46 | 1;
                UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                v47 = UFG::GameStatTracker::mspInstance;
              }
              if ( v47 )
                v14 = v47;
              UFG::GameStatTracker::mspInstance = v14;
              v48 = v14->mpSnapshots[0]->mpMapBools[22]->mKeepType;
            }
          }
          break;
        case 0x82369252:
          v40 = UFG::GameStatTracker::Instance();
          if ( !(*((_BYTE *)v40 + 6216) & 1) )
          {
            UFG::PersistentData::MapBool::SetStatus(v40->mpSnapshots[0]->mpMapBools[3], &result, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
              uiscreen_typea.mUID = result.mUID;
              v22 = 3;
              goto LABEL_137;
            }
          }
          break;
      }
      return;
    }
    if ( v6 == -1950744936 )
    {
      v63 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v63 + 6216) & 1) )
      {
        UFG::PersistentData::MapBool::SetStatus(v63->mpSnapshots[0]->mpMapBools[4], &result, 1);
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
          uiscreen_typea.mUID = result.mUID;
          v22 = 4;
          goto LABEL_137;
        }
      }
      return;
    }
    if ( v6 != -1907341976 )
    {
      if ( v6 == -1819210089 )
      {
        v54 = UFG::qSymbol::create_from_string(&v79, "Faction");
        v55 = *PropertyUtils::Get<long>(v4, v54, DEPTH_RECURSE);
        v56 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v56 + 6216) & 1) )
        {
          UFG::PersistentData::MapInt::SetStatus(v56->mpSnapshots[0]->mpMapInts[17], &result, v55);
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            uiscreen_typea.mUID = result.mUID;
            UFG::GameStatAction::PostStat::AchieveMapInt(Collectible_AreaOwnership, (UFG::qSymbol)&uiscreen_typea);
          }
        }
      }
      return;
    }
    v57 = UFG::ProgressionTracker::Instance();
    v58 = v57;
    if ( !result.mUID )
      goto LABEL_140;
    v59 = UFG::qBaseTreeRB::Get(&v57->mGameSlices.mTree, result.mUID);
    if ( v59 )
      goto LABEL_102;
    if ( result.mUID )
      v59 = UFG::qBaseTreeRB::Get(&v58->mContainerGameSlices.mTree, result.mUID);
    else
LABEL_140:
      v59 = 0i64;
LABEL_102:
    if ( v59 )
    {
      LOBYTE(uiscreen_typea.mUID) = 0;
      v60 = UFG::qSymbol::create_from_string(v76, "GiveRewards");
      v61 = UFG::qPropertySet::Get<bool>(v4, v60, DEPTH_RECURSE);
      v62 = (bool *)&uiscreen_typea;
      if ( v61 )
        v62 = v61;
      UFG::GameSlice::_SimulateComplete((UFG::GameSlice *)v59, *v62);
    }
    return;
  }
  if ( v6 == 1731387508 )
  {
    v33 = UFG::qSymbol::create_from_string(&v80, "FactionA");
    v73[0] = (UFG::qSymbol)UFG::qPropertySet::Get<UFG::qSymbol>(v4, v33, DEPTH_RECURSE)->mUID;
    v34 = UFG::qSymbol::create_from_string(&v81, "FactionB");
    symbol.mUID = UFG::qPropertySet::Get<UFG::qSymbol>(v4, v34, DEPTH_RECURSE)->mUID;
    v35 = UFG::qSymbol::create_from_string(&v82, "Standing");
    uiscreen_typea.mUID = UFG::qPropertySet::Get<UFG::qSymbol>(v4, v35, DEPTH_RECURSE)->mUID;
    v36 = UFG::FactionInterface::Get();
    v37 = (unsigned int)UFG::FactionInterface::MapSymbolToStanding(&uiscreen_typea);
    v38 = (unsigned int)UFG::FactionInterface::MapSymbolToFaction(&symbol);
    v39 = (unsigned int)UFG::FactionInterface::MapSymbolToFaction(v73);
    UFG::FactionInterface::SetStanding(&v36->mFactionInterface, v39, v38, v37);
    return;
  }
  if ( v6 > 0x28B63779 )
  {
    if ( v6 == 1141147779 )
    {
      v32 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v32 + 6216) & 1) )
      {
        UFG::PersistentData::MapBool::SetStatus(v32->mpSnapshots[0]->mpMapBools[31], &result, 1);
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
          uiscreen_typea.mUID = result.mUID;
          v22 = 31;
          goto LABEL_137;
        }
      }
    }
    else if ( v6 == 1571868732 )
    {
      v28 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v28 + 6216) & 1) )
      {
        UFG::PersistentData::MapBool::SetStatus(v28->mpSnapshots[0]->mpMapBools[76], &result, 0);
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v29 = _S12_6;
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            v29 = _S12_6;
          }
          v30 = &sGameStatTracker;
          if ( UFG::GameStatTracker::mspInstance )
            v30 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v30;
          if ( !(v29 & 1) )
          {
            _S12_6 = v29 | 1;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            v30 = UFG::GameStatTracker::mspInstance;
          }
          if ( v30 )
            v14 = v30;
          UFG::GameStatTracker::mspInstance = v14;
          v31 = v14->mpSnapshots[0]->mpMapBools[76]->mKeepType;
        }
      }
    }
  }
  else if ( v6 == 683030393 )
  {
    v27 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v27 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v27->mpSnapshots[0]->mpMapBools[10], &result, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
        uiscreen_typea.mUID = result.mUID;
        v22 = 10;
        goto LABEL_137;
      }
    }
  }
  else if ( v6 == 8816707 )
  {
    v26 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v26 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v26->mpSnapshots[0]->mpMapBools[5], &result, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
        uiscreen_typea.mUID = result.mUID;
        v22 = 5;
        goto LABEL_137;
      }
    }
  }
  else if ( v6 == 424071789 )
  {
    v23 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v23 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v23->mpSnapshots[0]->mpMapBools[13], &result, 0);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        uiscreen_typea.mUID = result.mUID;
        UFG::GameStatAction::PostStat::AchieveMapBool(DoorStateLocked, (UFG::qSymbol)&uiscreen_typea);
      }
    }
    v24 = UFG::Simulation::GetSimObject(&UFG::gSim, &result);
    if ( v24 )
    {
      v25 = (UFG::DoorComponent *)UFG::SimObject::GetComponentOfType(
                                    (UFG::SimObject *)v24,
                                    UFG::DoorComponent::_TypeUID);
      if ( v25 )
        UFG::DoorComponent::UpdateLockedState(v25);
    }
  }
  else
  {
    if ( v6 != 457439182 )
    {
      if ( v6 == 484171945 )
      {
        v20 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v20, Collectible_HijackReturn, &result, 1);
      }
      return;
    }
    v21 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v21 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v21->mpSnapshots[0]->mpMapBools[12], &result, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
        uiscreen_typea.mUID = result.mUID;
        v22 = 12;
LABEL_137:
        UFG::GameStatAction::PostStat::AchieveMapBool(v22, (UFG::qSymbol)&uiscreen_typea);
        return;
      }
    }
  }
}lt, 1);
      }
      return;
    }
    v21 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v21 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v21->mpSnapshots[0]->mpMapBools[12], &result, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
        uiscreen_typea.mUID = result.mUID;
        v22 = 12;
LABEL_137:
        UFG::GameStatAction::PostStat::AchieveMapBool(v22, (UFG::qSymbol)&uiscreen_typea);
        return;
      }
    }

// File Line: 264
// RVA: 0x4AA7A0
char __fastcall UFG::RewardsHandler::HandleRewards(UFG::ShowRewardType showRewardType, __int64 rewardPropertySetName, UFG::SceneObjectProperties *pCollectible)
{
  UFG::ShowRewardType v3; // esi
  UFG::SceneObjectProperties *v4; // rdi
  UFG::qSymbol *v5; // rbx
  UFG::qPropertySet *v6; // rax

  v3 = showRewardType;
  v4 = pCollectible;
  v5 = (UFG::qSymbol *)rewardPropertySetName;
  v6 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)rewardPropertySetName);
  if ( v6 )
    v6 = UFG::PropertySetManager::GetPropertySet(v5);
  return UFG::RewardsHandler::HandleRewards(v3, v6, v4);
}

// File Line: 270
// RVA: 0x4A89C0
char __fastcall UFG::RewardsHandler::HandleRewards(UFG::ShowRewardType showRewardType, UFG::qPropertySet *pProperties, UFG::SceneObjectProperties *pCollectible)
{
  UFG::qPropertySet *v3; // r13
  unsigned int v4; // er12
  char v5; // r14
  UFG::GameStatTracker *v6; // r15
  UFG::qSymbol *v7; // rax
  UFG::qSymbol *v8; // rax
  UFG::qSymbol *v9; // rdi
  UFG::qSymbol *v10; // rcx
  unsigned __int32 v11; // ebx
  UFG::qSymbol *v12; // rax
  UFG::qSymbol *v13; // rax
  UFG::qSymbol *v14; // rcx
  unsigned int v15; // esi
  UFG::qSymbol *v16; // rax
  UFG::qSymbol *v17; // rax
  unsigned int v18; // edi
  UFG::qSymbol *v19; // rax
  bool *v20; // rax
  UFG::qSymbol *v21; // rcx
  UFG::qSymbol *v22; // rax
  UFG::qSymbol *v23; // rax
  int *v24; // rax
  UFG::qSymbol *v25; // rcx
  unsigned int v26; // edi
  UFG::qSymbol *v27; // rax
  char *v28; // rdi
  UFG::qSymbol *v29; // rax
  unsigned int v30; // ecx
  char *v31; // rcx
  UFG::ProgressionTracker *v32; // rax
  UFG::OSuiteLeaderboardManager *v33; // rax
  UFG::OSuiteLeaderboardData *v34; // rax
  UFG::qSymbol *v35; // rax
  UFG::qSymbol *v36; // rax
  unsigned int *v37; // rax
  UFG::GameStatTracker *v38; // rax
  UFG::GameStatTracker *v39; // rax
  unsigned int v40; // edx
  UFG::GameStatTracker *v41; // r8
  UFG::GameStatTracker *v42; // rax
  __int64 v43; // rax
  UFG::qSymbol *v44; // rax
  bool *v45; // rax
  int v46; // edi
  UFG::qSymbol *v47; // rax
  signed int v48; // edi
  bool v49; // al
  UFG::qSymbol *v50; // rax
  int v51; // edi
  UFG::qSymbol *v52; // rax
  signed int v53; // ecx
  signed int v54; // eax
  signed int v55; // eax
  float v56; // xmm0_4
  UFG::qSymbol *v57; // rax
  UFG::qSymbol *v58; // rax
  signed int v59; // ecx
  signed int v60; // eax
  signed int v61; // eax
  UFG::GameSlice *v62; // r14
  const char *v63; // rdi
  UFG::OSuiteLeaderboardManager *v64; // rax
  UFG::OSuiteLeaderboardData *v65; // rdi
  UFG::GameStatTracker *v66; // rax
  signed int v67; // eax
  int v68; // ecx
  UFG::OSuiteLeaderboardManager *v69; // rax
  UFG::GameStatTracker *v70; // rax
  UFG::GameStatTracker *v71; // rax
  int v72; // er14
  unsigned __int64 v73; // rdi
  UFG::SocialLogDataManager *v74; // rax
  UFG::qSymbol *v75; // rax
  char *v76; // rdi
  UFG::qSymbol *v77; // rax
  unsigned int v78; // edx
  int v79; // edi
  int v80; // edi
  UFG::GameStatTracker *v81; // rdi
  UFG::qSymbol *v82; // rax
  char *v83; // rdi
  UFG::qSymbol *v84; // rax
  unsigned int v85; // edi
  UFG::qString *v86; // rax
  int v87; // edi
  int v88; // edi
  UFG::qSymbol *v89; // rax
  int *v90; // rax
  UFG::qSymbol *v91; // rcx
  signed int v92; // edi
  UFG::qSymbol *v93; // rax
  char *v94; // rsi
  UFG::qSymbol *v95; // rax
  char *v96; // rdi
  unsigned int v97; // eax
  int v98; // edi
  UFG::qSymbol *v99; // rax
  int *v100; // rax
  UFG::qSymbol *v101; // rcx
  int v102; // er8
  UFG::qSymbol *v103; // rax
  UFG::qSymbol *v104; // rax
  int v105; // eax
  UFG::qSymbol *v106; // rdi
  UFG::ProgressionTracker *v107; // rax
  UFG::qBaseTreeRB *v108; // rax
  int v109; // ecx
  UFG::qSymbol *v110; // rdi
  UFG::ProgressionTracker *v111; // rax
  UFG::qSymbol *v112; // rdi
  UFG::ProgressionTracker *v113; // rax
  UFG::qBaseTreeRB *v114; // rsi
  UFG::qSymbol *v115; // rdi
  UFG::ProgressionTracker *v116; // rax
  UFG::qSymbol *v117; // rdi
  UFG::ProgressionTracker *v118; // rax
  UFG::qBaseTreeRB *v119; // rcx
  int *v120; // rax
  UFG::GameStatTracker *v121; // rax
  UFG::SimObjectCharacter *v122; // rax
  unsigned __int16 v123; // dx
  UFG::HealthComponent *v124; // rdi
  UFG::SimComponent *v125; // rax
  int v126; // esi
  UFG::qSymbol *v127; // rax
  int *v128; // rax
  UFG::qSymbol *v129; // rcx
  signed int v130; // eax
  UFG::qSymbol *v131; // rax
  char *v132; // rdi
  UFG::qSymbol *v133; // rax
  char *v134; // rsi
  unsigned int v135; // eax
  UFG::qSymbol *v136; // rax
  int *v137; // rax
  UFG::qSymbol *v138; // rcx
  signed int v139; // edx
  UFG::qSymbol *v140; // rax
  char *v141; // rdi
  UFG::qSymbol *v142; // rax
  char *v143; // rsi
  unsigned int v144; // eax
  UFG::qSymbol *v145; // rax
  int *v146; // rax
  UFG::qSymbol *v147; // rcx
  signed int v148; // edx
  UFG::qSymbol *v149; // rax
  char *v150; // rdi
  UFG::qSymbol *v151; // rax
  char *v152; // rsi
  unsigned int v153; // eax
  UFG::qSymbol *v154; // rax
  int *v155; // rax
  UFG::qSymbol *v156; // rcx
  signed int v157; // edx
  UFG::qSymbol *v158; // rax
  char *v159; // rdi
  UFG::qSymbol *v160; // rax
  char *v161; // rsi
  unsigned int v162; // eax
  UFG::qSymbol *v163; // rax
  bool *v164; // rax
  UFG::qSymbol *v165; // rcx
  char v166; // cl
  UFG::qSymbol *v167; // rax
  char *v168; // rdi
  UFG::qSymbol *v169; // rax
  char *v170; // rsi
  unsigned int v171; // eax
  UFG::qSymbol *v172; // rax
  bool *v173; // rax
  UFG::qSymbol *v174; // rcx
  UFG::qSymbol *v175; // rax
  bool *v176; // rax
  UFG::qSymbol *v177; // rcx
  char v178; // cl
  UFG::qSymbol *v179; // rax
  char *v180; // rdi
  UFG::qSymbol *v181; // rax
  char *v182; // rsi
  unsigned int v183; // eax
  UFG::qSymbol *v184; // rax
  bool *v185; // rax
  UFG::qSymbol *v186; // rcx
  UFG::qSymbol *v187; // rax
  bool *v188; // rax
  UFG::qSymbol *v189; // rcx
  char v190; // cl
  UFG::qSymbol *v191; // rax
  char *v192; // rdi
  UFG::qSymbol *v193; // rax
  char *v194; // rsi
  unsigned int v195; // eax
  UFG::qSymbol *v196; // rax
  bool *v197; // rax
  UFG::qSymbol *v198; // rcx
  char v199; // cl
  UFG::qSymbol *v200; // rax
  char *v201; // rdi
  UFG::qSymbol *v202; // rax
  char *v203; // rsi
  unsigned int v204; // eax
  UFG::qSymbol *v205; // rax
  bool *v206; // rax
  UFG::qSymbol *v207; // rcx
  char v208; // cl
  UFG::qSymbol *v209; // rax
  char *v210; // rdi
  UFG::qSymbol *v211; // rax
  char *v212; // rsi
  unsigned int v213; // eax
  UFG::qSymbol *v214; // rax
  bool *v215; // rax
  UFG::qSymbol *v216; // rcx
  char v217; // cl
  UFG::qSymbol *v218; // rax
  char *v219; // rdi
  UFG::qSymbol *v220; // rax
  char *v221; // rsi
  unsigned int v222; // eax
  UFG::qSymbol *v223; // rax
  bool *v224; // rax
  UFG::qSymbol *v225; // rcx
  char v226; // cl
  UFG::qSymbol *v227; // rax
  char *v228; // rdi
  UFG::qSymbol *v229; // rax
  char *v230; // rsi
  unsigned int v231; // eax
  UFG::qSymbol *v232; // rax
  UFG::qPropertyList *v233; // rax
  UFG::qPropertyList *v234; // rdi
  unsigned int v235; // esi
  UFG::ShowRewardType v236; // er15
  char *v237; // rax
  __int64 v238; // rcx
  UFG::PerkGoalTracker *v239; // rax
  unsigned int v240; // eax
  UFG::CopSystem *v241; // rax
  const char *caption; // [rsp+30h] [rbp-D0h]
  char *captiona; // [rsp+30h] [rbp-D0h]
  char *captionb; // [rsp+30h] [rbp-D0h]
  char *captionc; // [rsp+30h] [rbp-D0h]
  const char *captiond; // [rsp+30h] [rbp-D0h]
  const char *captione; // [rsp+30h] [rbp-D0h]
  char *captionf; // [rsp+30h] [rbp-D0h]
  UFG::qSymbol gameslice_subtype; // [rsp+38h] [rbp-C8h]
  UFG::qSymbol gameslice_type; // [rsp+3Ch] [rbp-C4h]
  UFG::qSymbol symGameSlice[2]; // [rsp+40h] [rbp-C0h]
  UFG::qSymbol v253[2]; // [rsp+48h] [rbp-B8h]
  int score; // [rsp+50h] [rbp-B0h]
  unsigned int v255; // [rsp+54h] [rbp-ACh]
  UFG::qSymbol v256[2]; // [rsp+58h] [rbp-A8h]
  UFG::qString v257; // [rsp+60h] [rbp-A0h]
  __int64 v258; // [rsp+88h] [rbp-78h]
  UFG::SocialLogData data; // [rsp+90h] [rbp-70h]
  int v260; // [rsp+150h] [rbp+50h]
  void *mem; // [rsp+158h] [rbp+58h]
  UFG::ShowRewardType showRewardTypea; // [rsp+1B0h] [rbp+B0h]
  UFG::qSymbol uiscreen_type; // [rsp+1B8h] [rbp+B8h]
  UFG::SceneObjectProperties *v264; // [rsp+1C0h] [rbp+C0h]
  UFG::qSymbol result; // [rsp+1C8h] [rbp+C8h]

  v264 = pCollectible;
  showRewardTypea = showRewardType;
  v258 = -2i64;
  v3 = pProperties;
  v4 = 0;
  v255 = 0;
  v5 = showRewardType == 0;
  LOBYTE(uiscreen_type.mUID) = showRewardType == 0;
  if ( !pProperties )
    return 0;
  v6 = UFG::GameStatTracker::Instance();
  UFG::RewardsHandler::mItemUnlocked = 0;
  v7 = UFG::qSymbol::create_from_string(&result, "UIScreenType");
  v8 = UFG::qPropertySet::Get<UFG::qSymbol>(v3, v7, DEPTH_RECURSE);
  v9 = &UFG::gNullQSymbol;
  v10 = &UFG::gNullQSymbol;
  if ( v8 )
    v10 = v8;
  v11 = v10->mUID;
  v12 = UFG::qSymbol::create_from_string(&result, "GamesliceType");
  v13 = UFG::qPropertySet::Get<UFG::qSymbol>(v3, v12, DEPTH_RECURSE);
  v14 = &UFG::gNullQSymbol;
  if ( v13 )
    v14 = v13;
  v15 = v14->mUID;
  v16 = UFG::qSymbol::create_from_string(&result, "GamesliceSubType");
  v17 = UFG::qPropertySet::Get<UFG::qSymbol>(v3, v16, DEPTH_RECURSE);
  if ( v17 )
    v9 = v17;
  v18 = v9->mUID;
  if ( v5 )
  {
    LOBYTE(result.mUID) = 1;
    v19 = UFG::qSymbol::create_from_string(symGameSlice, "ShowRewardScreen");
    v20 = UFG::qPropertySet::Get<bool>(v3, v19, DEPTH_RECURSE);
    v21 = &result;
    if ( v20 )
      v21 = (UFG::qSymbol *)v20;
    v5 = v21->mUID;
    v22 = UFG::qSymbol::create_from_string(symGameSlice, "CompletionText");
    UFG::qPropertySet::Get<char const *>(v3, v22, DEPTH_RECURSE);
    if ( v5 )
    {
      *(_QWORD *)&v253[0].mUID = &gameslice_subtype;
      *(_QWORD *)&v256[0].mUID = &gameslice_type;
      result.mUID = v11;
      gameslice_subtype.mUID = v18;
      gameslice_type.mUID = v15;
      UFG::RewardsHandler::UISetup((__int64)&gameslice_type, (__int64)&gameslice_subtype, (__int64)&result, v3);
      UFG::GameStatAction::Player::ClampAndSetCombatMeter(0.0);
      v5 = uiscreen_type.mUID;
    }
    else
    {
      LOBYTE(uiscreen_type.mUID) = 0;
      showRewardTypea = 1;
    }
  }
  result.mUID = 0;
  v23 = UFG::qSymbol::create_from_string(symGameSlice, "MoneyAdjustment");
  v24 = UFG::qPropertySet::Get<long>(v3, v23, DEPTH_RECURSE);
  v25 = &result;
  if ( v24 )
    v25 = (UFG::qSymbol *)v24;
  v26 = v25->mUID;
  gameslice_subtype.mUID = v26;
  if ( v26 )
  {
    if ( v5 )
    {
      v27 = UFG::qSymbol::create_from_string(&result, "MoneyAdjustmentIcon");
      v28 = UFG::qPropertySet::Get<char const *>(v3, v27, DEPTH_RECURSE);
      v29 = UFG::qSymbol::create_from_string(&gameslice_type, "MoneyAdjustmentText");
      caption = UFG::qPropertySet::Get<char const *>(v3, v29, DEPTH_RECURSE);
      v30 = UFG::qStringHash32(v28, 0xFFFFFFFF);
      symGameSlice[0].mUID = v30;
      if ( caption && *caption )
      {
        result.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(caption, v30, (__int64)&result);
        v26 = gameslice_subtype.mUID;
      }
      else
      {
        result.mUID = v11;
        v26 = gameslice_subtype.mUID;
        v31 = UFG::qString::FormatEx(
                &v257,
                "<img src=Icon_Reward_Cash height=24 width=24 vspace=-8>HK $%d",
                gameslice_subtype.mUID)->mData;
        UFG::UIHKScreenMissionComplete::AddReward(v31, symGameSlice[0].mUID, (__int64)&result);
        UFG::qString::~qString(&v257);
      }
      UFG::RewardsHandler::mItemUnlocked = 1;
    }
    v32 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::ApplyMonetaryReward(v32, v26);
    v33 = UFG::OSuiteLeaderboardManager::Instance();
    v34 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v33, "StatAwardsMogul");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v34, v26);
    if ( v5 )
    {
      v35 = UFG::qSymbol::create_from_string(&result, "Reward");
      UFG::GameStatAction::Money::SendTransactionTelemetry(&v3->mName, v35, v26);
    }
  }
  v36 = UFG::qSymbol::create_from_string(&result, "UnlockableBioId");
  v37 = (unsigned int *)UFG::qPropertySet::Get<long>(v3, v36, DEPTH_RECURSE);
  if ( v37 )
  {
    result.mUID = *v37;
    v38 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v38 + 6216) & 1) )
      v38->mpSnapshots[0]->mBools[2].mValue = 1;
    captiona = (char *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, result.mUID);
    v39 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v39 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v39->mpSnapshots[0]->mpMapBools[22], (UFG::qSymbol *)captiona, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v40 = _S12_6;
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v40 = _S12_6;
        }
        v41 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v41 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v41;
        if ( !(v40 & 1) )
        {
          _S12_6 = v40 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v41 = UFG::GameStatTracker::mspInstance;
        }
        v42 = &sGameStatTracker;
        if ( v41 )
          v42 = v41;
        UFG::GameStatTracker::mspInstance = v42;
        v43 = v42->mpSnapshots[0]->mpMapBools[22]->mKeepType;
      }
    }
  }
  v44 = UFG::qSymbol::create_from_string(&result, "EnableMissionScoring");
  v45 = UFG::qPropertySet::Get<bool>(v3, v44, DEPTH_RECURSE);
  if ( v45 && *v45 )
  {
    v46 = UFG::GameStatAction::MissionScoring::GetCopScoreBuffed();
    score = v46;
    result.mUID = UFG::GameStatAction::MissionScoring::GetTriadScoreBuffed();
    gameslice_subtype.mUID = v46 + result.mUID;
    gameslice_type.mUID = UFG::GameStatAction::MissionScoring::GetTotalScoreUncapped();
    v47 = UFG::qSymbol::create_from_string(symGameSlice, "FixedMissionScoring");
    captionb = (char *)UFG::qPropertySet::Get<bool>(v3, v47, DEPTH_RECURSE);
    v48 = 1;
    v255 = 1;
    v49 = 1;
    if ( v15 != UFG::qSymbol::create_from_string(v256, "DLC_POLICE")->mUID )
    {
      v48 = 3;
      v255 = 3;
      if ( v15 != UFG::qSymbol::create_from_string(v253, "DLC_TRIAD")->mUID )
        v49 = 0;
    }
    if ( v48 & 2 )
    {
      v48 &= 0xFFFFFFFD;
      v255 = v48;
    }
    if ( v48 & 1 )
      v255 = v48 & 0xFFFFFFFE;
    if ( v49 )
    {
      if ( captionb && *captionb )
      {
        v50 = UFG::qSymbol::create_from_string(&uiscreen_type, "CopStartingScore");
        score = *UFG::qPropertySet::Get<long>(v3, v50, DEPTH_RECURSE);
        v51 = score;
        v52 = UFG::qSymbol::create_from_string(&uiscreen_type, "TriadBaseScore");
        v53 = *UFG::qPropertySet::Get<long>(v3, v52, DEPTH_RECURSE);
        result.mUID = v53;
        gameslice_subtype.mUID = v53 + v51;
        gameslice_type.mUID = v53 + v51;
        UFG::UIHKScreenMissionComplete::mClearMissionScoreAfter = 0;
        v54 = 0;
        if ( v51 > 0 )
          v54 = 100;
        flt_14243121C = (float)v54;
        v55 = 0;
        if ( v53 > 0 )
          v55 = 100;
        v56 = (float)v55;
      }
      else
      {
        flt_14243121C = UFG::GameStatAction::MissionScoring::GetCopScorePercentage();
        v56 = UFG::GameStatAction::MissionScoring::GetTriadScorePercentage();
        v51 = score;
      }
    }
    else if ( captionb && *captionb )
    {
      v57 = UFG::qSymbol::create_from_string(&uiscreen_type, "CopStartingScore");
      score = *UFG::qPropertySet::Get<long>(v3, v57, DEPTH_RECURSE);
      v51 = score;
      v58 = UFG::qSymbol::create_from_string(&uiscreen_type, "TriadBaseScore");
      v59 = *UFG::qPropertySet::Get<long>(v3, v58, DEPTH_RECURSE);
      result.mUID = v59;
      gameslice_subtype.mUID = v59 + v51;
      gameslice_type.mUID = v59 + v51;
      UFG::UIHKScreenMissionComplete::mClearMissionScoreAfter = 1;
      v60 = 0;
      if ( v51 > 0 )
        v60 = 100;
      flt_14243121C = (float)v60;
      v61 = 0;
      if ( v59 > 0 )
        v61 = 100;
      v56 = (float)v61;
    }
    else
    {
      UFG::UIHKScreenMissionComplete::mClearMissionScoreAfter = 1;
      v62 = UFG::ProgressionTracker::Instance()->mpActiveMaster;
      captionc = (char *)v62;
      if ( v62 )
      {
        v63 = v62->mName.mText;
        v64 = UFG::OSuiteLeaderboardManager::Instance();
        v65 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingSliceName(v64, v63);
        *(_QWORD *)&v253[0].mUID = v65;
        if ( v65 )
        {
          v66 = UFG::GameStatTracker::Instance();
          v67 = UFG::GameStatTracker::GetStat(v66, LeaderboardScoreIntList, &v65->mLeaderboardName);
          v68 = gameslice_type.mUID;
          if ( v67 < (signed int)gameslice_type.mUID )
          {
            v69 = UFG::OSuiteLeaderboardManager::Instance();
            UFG::OSuiteLeaderboardManager::UploadMissionResult(
              v69,
              v65,
              gameslice_type.mUID,
              UFG::DataSynchronizer::UpdateLeaderboardCallback);
            v70 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v70, LeaderboardDirtyScoreBoolList, &v65->mLeaderboardName, 1);
            v71 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v71, LeaderboardScoreIntList, &v65->mLeaderboardName, gameslice_type.mUID);
            v72 = v65->mLeaderboardId;
            v73 = UFG::OnlineUtil::CurrentTimeMillis();
            UFG::SocialLogData::SocialLogData(&data);
            data.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable;
            v260 = 0;
            mem = 0i64;
            data.m_iCommId = 0;
            data.m_iTimeStamp = v73;
            data.m_iLeaderboardId = v72;
            data.m_iScore = gameslice_type.mUID;
            v74 = UFG::SocialLogDataManager::Instance();
            UFG::SocialLogDataManager::AddToSaveData(v74, &data);
            UFG::UIHKScreenMissionComplete::sIsHighscore = 1;
            data.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable;
            if ( mem )
              operator delete[](mem);
            UFG::SocialLogData::~SocialLogData(&data);
            v62 = (UFG::GameSlice *)captionc;
            v65 = *(UFG::OSuiteLeaderboardData **)&v253[0].mUID;
            v68 = gameslice_type.mUID;
          }
          if ( lastGameSlice != v62 )
          {
            UFG::DataSynchronizer::SendBeatChallengeMessageIfNeeded(v65, v68, 0);
            lastGameSlice = v62;
          }
        }
        symGameSlice[0] = (UFG::qSymbol)v62->mNode.mUID;
        v51 = UFG::RewardsHandler::GetCappedScorePerMission(score, CopScore, (__int64)symGameSlice);
        score = v51;
        symGameSlice[0] = (UFG::qSymbol)v62->mNode.mUID;
        result.mUID = UFG::RewardsHandler::GetCappedScorePerMission(result.mUID, TriadScore, (__int64)symGameSlice);
      }
      else
      {
        v51 = score;
      }
      flt_14243121C = UFG::GameStatAction::MissionScoring::GetCopScorePercentage();
      v56 = UFG::GameStatAction::MissionScoring::GetTriadScorePercentage();
      v5 = uiscreen_type.mUID;
    }
    unk_142431CEC = LODWORD(v56);
    UFG::UIHKScreenMissionComplete::AddPoliceScore(v51);
    UFG::UIHKScreenMissionComplete::AddTriadScore(result.mUID);
    UFG::UIHKScreenMissionComplete::AddMissionScore(gameslice_subtype.mUID);
    UFG::UIHKScreenMissionComplete::AddUncappedMissionScore(gameslice_type.mUID);
    if ( v5 )
    {
      v75 = UFG::qSymbol::create_from_string(&uiscreen_type, "CopXPIcon");
      v76 = PropertyUtils::Get<char const *>(v3, v75, DEPTH_RECURSE);
      v77 = UFG::qSymbol::create_from_string(v253, "CopXPText");
      captiond = PropertyUtils::Get<char const *>(v3, v77, DEPTH_RECURSE);
      v78 = UFG::qStringHash32(v76, 0xFFFFFFFF);
      if ( captiond && *captiond )
        UFG::UIHKScreenMissionComplete::AddPoliceReward(captiond, v78);
      v51 = score;
      unk_142431208 = unk_142431208 + (float)score;
      UFG::RewardsHandler::mItemUnlocked = 1;
    }
    gameslice_subtype.mUID = v6->mpSnapshots[0]->mInts[30].mValue;
    uiscreen_type.mUID = gameslice_subtype.mUID + v51;
    v79 = UFG::GameStatTracker::GetXPLevel(v6, 0, gameslice_subtype.mUID);
    symGameSlice[0].mUID = UFG::GameStatTracker::GetXPLevel(v6, 0, uiscreen_type.mUID);
    if ( symGameSlice[0].mUID != v79 )
    {
      UFG::GameStatTracker::ApplyDelta(v6, CopUpgradePoint, symGameSlice[0].mUID - v79);
      if ( (signed int)symGameSlice[0].mUID >= 10 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(30);
    }
    unk_142431204 = (float)(signed int)gameslice_subtype.mUID;
    v80 = score;
    unk_142431208 = (float)score;
    unk_142431214 = (float)(signed int)UFG::GameStatTracker::GetPercentageToNextXPLevel(v6, 0, gameslice_subtype.mUID);
    if ( !(*((_BYTE *)v6 + 6216) & 1) )
    {
      v6->mpSnapshots[0]->mInts[30].mValue += v80;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( _S12_6 & 1 )
        {
          v81 = &sGameStatTracker;
        }
        else
        {
          _S12_6 |= 1u;
          v81 = &sGameStatTracker;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        if ( UFG::GameStatTracker::mspInstance )
          v81 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v81;
      }
    }
    unk_142431218 = (float)(signed int)UFG::GameStatTracker::GetPercentageToNextXPLevel(v6, 0, uiscreen_type.mUID);
    unk_142431220 = v6->mMaxXPThresholdLevels[0];
    if ( v5 )
    {
      v82 = UFG::qSymbol::create_from_string(&uiscreen_type, "TriadXPIcon");
      v83 = PropertyUtils::Get<char const *>(v3, v82, DEPTH_RECURSE);
      v84 = UFG::qSymbol::create_from_string(v253, "TriadXPText");
      captione = PropertyUtils::Get<char const *>(v3, v84, DEPTH_RECURSE);
      v85 = UFG::qStringHash32(v83, 0xFFFFFFFF);
      if ( captione && *captione )
      {
        UFG::UIHKScreenMissionComplete::AddTriadReward(captione, v85);
      }
      else
      {
        v86 = UFG::qString::FormatEx(&v257, " $%d rewarded", result.mUID);
        UFG::UIHKScreenMissionComplete::AddTriadReward(v86->mData, v85);
        UFG::qString::~qString(&v257);
      }
      unk_142431CD8 = unk_142431CD8 + (float)(signed int)result.mUID;
      UFG::RewardsHandler::mItemUnlocked = 1;
    }
    gameslice_subtype.mUID = v6->mpSnapshots[0]->mInts[31].mValue;
    uiscreen_type.mUID = gameslice_subtype.mUID + result.mUID;
    v87 = UFG::GameStatTracker::GetXPLevel(v6, ThresholdType_Triad, gameslice_subtype.mUID);
    symGameSlice[0].mUID = UFG::GameStatTracker::GetXPLevel(v6, ThresholdType_Triad, uiscreen_type.mUID);
    if ( symGameSlice[0].mUID != v87 )
    {
      UFG::GameStatTracker::ApplyDelta(v6, TriadUpgradePoint, symGameSlice[0].mUID - v87);
      if ( (signed int)symGameSlice[0].mUID >= 10 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(29);
    }
    unk_142431CD4 = (float)(signed int)gameslice_subtype.mUID;
    v88 = result.mUID;
    unk_142431CD8 = (float)(signed int)result.mUID;
    unk_142431CE4 = (float)(signed int)UFG::GameStatTracker::GetPercentageToNextXPLevel(
                                         v6,
                                         ThresholdType_Triad,
                                         gameslice_subtype.mUID);
    UFG::GameStatTracker::ApplyDelta(v6, TriadXP, v88);
    unk_142431CE8 = (float)(signed int)UFG::GameStatTracker::GetPercentageToNextXPLevel(
                                         v6,
                                         ThresholdType_Triad,
                                         uiscreen_type.mUID);
    unk_142431CF0 = v6->mMaxXPThresholdLevels[1];
  }
  else
  {
    UFG::UIHKScreenMissionComplete::mClearMissionScoreAfter = 0;
  }
  if ( UFG::ProgressionTracker::Instance()->mModeType != 2 || v15 == qSymbol_Race_14.mUID )
  {
    uiscreen_type.mUID = 0;
    v89 = UFG::qSymbol::create_from_string(&result, "StandingAdjustment");
    v90 = UFG::qPropertySet::Get<long>(v3, v89, DEPTH_RECURSE);
    v91 = &uiscreen_type;
    if ( v90 )
      v91 = (UFG::qSymbol *)v90;
    v92 = v91->mUID;
    uiscreen_type.mUID = v92;
    if ( v92 )
    {
      if ( v5 )
      {
        v93 = UFG::qSymbol::create_from_string(&result, "StandingAdjustmentIcon");
        v94 = PropertyUtils::Get<char const *>(v3, v93, DEPTH_RECURSE);
        v95 = UFG::qSymbol::create_from_string(v253, "StandingAdjustmentText");
        v96 = PropertyUtils::Get<char const *>(v3, v95, DEPTH_RECURSE);
        v97 = UFG::qStringHash32(v94, 0xFFFFFFFF);
        UFG::UIHKScreenMissionComplete::AddFaceReward(v96, v97);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v92 = uiscreen_type.mUID;
      }
      v98 = (signed int)(float)(UFG::PlayerBuffTracker::GetFaceXPBonusPercent() * (float)v92) + v92;
      unk_1424332D4 = (float)v6->mpSnapshots[0]->mInts[29].mValue;
      unk_1424332D8 = (float)v98;
      unk_1424332E4 = (float)(signed int)UFG::GameStatTracker::GetPercentageToNextLevel(v6, Standing);
      UFG::GameStatTracker::ApplyDelta(v6, Standing, v98);
      unk_1424332E8 = (float)(signed int)UFG::GameStatTracker::GetPercentageToNextLevel(v6, Standing);
      unk_1424332F0 = v6->m_iMaxFaceLevel;
    }
    uiscreen_type.mUID = 0;
    v99 = UFG::qSymbol::create_from_string(&result, "MinimumStanding");
    v100 = UFG::qPropertySet::Get<long>(v3, v99, DEPTH_RECURSE);
    v101 = &uiscreen_type;
    if ( v100 )
      v101 = (UFG::qSymbol *)v100;
    v102 = v101->mUID;
    if ( v101->mUID && (float)v102 > (float)v6->mpSnapshots[0]->mInts[29].mValue )
      UFG::GameStatTracker::SetStat(v6, Standing, v102);
  }
  if ( UFG::ProgressionTracker::Instance()->mModeType != 2 )
  {
    v103 = UFG::qSymbol::create_from_string(&uiscreen_type, "UnlockAchievement");
    v104 = UFG::qPropertySet::Get<UFG::qSymbol>(v3, v103, DEPTH_RECURSE);
    if ( v104 )
    {
      v105 = UFG::HKAchievementTrophyManager::mapAchievmentStringToID(v104->mUID);
      if ( v105 == 21 )
      {
        v106 = UFG::qSymbol::create_from_string(&uiscreen_type, "S_HJ");
        v107 = UFG::ProgressionTracker::Instance();
        v108 = UFG::ProgressionTracker::Find(v107, v106, 0);
        if ( v108 && SWORD2(v108[5].mRoot.mParent) >= 5 )
        {
          v109 = 21;
LABEL_134:
          UFG::AchievementTrophyManager::UnlockAchievementTrophy(v109);
          goto LABEL_135;
        }
      }
      else if ( v105 == 27 )
      {
        v110 = UFG::qSymbol::create_from_string(&uiscreen_type, "F_FC1");
        v111 = UFG::ProgressionTracker::Instance();
        captionf = (char *)UFG::ProgressionTracker::Find(v111, v110, 0);
        v112 = UFG::qSymbol::create_from_string(&result, "F_FC2");
        v113 = UFG::ProgressionTracker::Instance();
        v114 = UFG::ProgressionTracker::Find(v113, v112, 0);
        v115 = UFG::qSymbol::create_from_string(v253, "F_FC3");
        v116 = UFG::ProgressionTracker::Instance();
        *(_QWORD *)&symGameSlice[0].mUID = UFG::ProgressionTracker::Find(v116, v115, 0);
        v117 = UFG::qSymbol::create_from_string(v256, "F_FC4");
        v118 = UFG::ProgressionTracker::Instance();
        v119 = UFG::ProgressionTracker::Find(v118, v117, 0);
        if ( captionf
          && *((_WORD *)captionf + 182) > 0
          && v114
          && SWORD2(v114[5].mRoot.mParent) > 0
          && *(_QWORD *)&symGameSlice[0].mUID
          && *(_WORD *)(*(_QWORD *)&symGameSlice[0].mUID + 364i64) > 0
          && v119
          && SWORD2(v119[5].mRoot.mParent) > 0 )
        {
          v109 = 27;
          goto LABEL_134;
        }
      }
      else if ( v105 > 0 )
      {
        v109 = v105;
        goto LABEL_134;
      }
    }
LABEL_135:
    v120 = UFG::qPropertySet::Get<long>(
             v3,
             (UFG::qSymbol *)&UFG::GameStat::Symbol_MaxHealthUpgradePoint.mUID,
             DEPTH_RECURSE);
    *(_QWORD *)&result.mUID = v120;
    if ( v120 )
    {
      if ( *v120 > 0 )
      {
        v121 = UFG::GameStatTracker::Instance();
        uiscreen_type.mUID = (unsigned int)UFG::GameStatTracker::GetNumHealthShrinesCollected(v121) % 5;
        v122 = UFG::GetLocalPlayer();
        if ( v122 )
        {
          v123 = v122->m_Flags;
          if ( (v123 >> 14) & 1 )
          {
            v124 = (UFG::HealthComponent *)v122->m_Components.p[6].m_pComponent;
          }
          else if ( (v123 & 0x8000u) == 0 )
          {
            if ( (v123 >> 13) & 1 )
              v125 = UFG::SimObjectGame::GetComponentOfTypeHK(
                       (UFG::SimObjectGame *)&v122->vfptr,
                       UFG::HealthComponent::_TypeUID);
            else
              v125 = (v123 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v122->vfptr,
                                          UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                              (UFG::SimObject *)&v122->vfptr,
                                                                              UFG::HealthComponent::_TypeUID);
            v124 = (UFG::HealthComponent *)v125;
          }
          else
          {
            v124 = (UFG::HealthComponent *)v122->m_Components.p[6].m_pComponent;
          }
          if ( v124 )
          {
            v126 = (signed int)v6->mpSnapshots[0]->mFloats[40].mValue;
            if ( !uiscreen_type.mUID )
            {
              v126 += **(_DWORD **)&result.mUID + 4 * **(_DWORD **)&result.mUID;
              UFG::GameStatTracker::SetStat(v6, MaxHealth, (float)v126);
              UFG::HealthComponent::SetMaxHealth(v124, v126);
              UFG::HudAudio::PlayHudSound(0x1ED74491u, 0i64);
            }
            UFG::HealthComponent::SetHealth(v124, v126, 0i64);
          }
        }
      }
    }
    uiscreen_type.mUID = 0;
    v127 = UFG::qSymbol::create_from_string(&result, "MaxHealthAdjustment");
    v128 = UFG::qPropertySet::Get<long>(v3, v127, DEPTH_RECURSE);
    v129 = &uiscreen_type;
    if ( v128 )
      v129 = (UFG::qSymbol *)v128;
    v130 = v129->mUID;
    result.mUID = v130;
    if ( v130 )
    {
      if ( v5 )
      {
        v131 = UFG::qSymbol::create_from_string(&uiscreen_type, "MaxHealthAdjustmentIcon");
        v132 = PropertyUtils::Get<char const *>(v3, v131, DEPTH_RECURSE);
        v133 = UFG::qSymbol::create_from_string(v253, "MaxHealthAdjustmentText");
        v134 = PropertyUtils::Get<char const *>(v3, v133, DEPTH_RECURSE);
        v135 = UFG::qStringHash32(v132, 0xFFFFFFFF);
        uiscreen_type.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v134, v135, (__int64)&uiscreen_type);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v130 = result.mUID;
      }
      UFG::GameStatTracker::ApplyDelta(v6, MaxHealth, (float)v130);
    }
    uiscreen_type.mUID = 0;
    v136 = UFG::qSymbol::create_from_string(&result, "StatueDefensiveStage");
    v137 = UFG::qPropertySet::Get<long>(v3, v136, DEPTH_RECURSE);
    v138 = &uiscreen_type;
    if ( v137 )
      v138 = (UFG::qSymbol *)v137;
    v139 = v138->mUID;
    result.mUID = v139;
    if ( v139 )
    {
      if ( v5 )
      {
        v140 = UFG::qSymbol::create_from_string(&uiscreen_type, "TriadStageIcon");
        v141 = PropertyUtils::Get<char const *>(v3, v140, DEPTH_RECURSE);
        v142 = UFG::qSymbol::create_from_string(v253, "TriadStageText");
        v143 = PropertyUtils::Get<char const *>(v3, v142, DEPTH_RECURSE);
        v144 = UFG::qStringHash32(v141, 0xFFFFFFFF);
        uiscreen_type.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v143, v144, (__int64)&uiscreen_type);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v139 = result.mUID;
      }
      if ( v6->mpSnapshots[0]->mInts[22].mValue > v139 )
        v139 = v6->mpSnapshots[0]->mInts[22].mValue;
      UFG::GameStatTracker::SetStat(v6, StatueDefensiveStage, v139);
    }
    uiscreen_type.mUID = 0;
    v145 = UFG::qSymbol::create_from_string(&result, "StatueOffensiveStage");
    v146 = UFG::qPropertySet::Get<long>(v3, v145, DEPTH_RECURSE);
    v147 = &uiscreen_type;
    if ( v146 )
      v147 = (UFG::qSymbol *)v146;
    v148 = v147->mUID;
    result.mUID = v148;
    if ( v148 )
    {
      if ( v5 )
      {
        v149 = UFG::qSymbol::create_from_string(&uiscreen_type, "TriadStageIcon");
        v150 = PropertyUtils::Get<char const *>(v3, v149, DEPTH_RECURSE);
        v151 = UFG::qSymbol::create_from_string(v253, "TriadStageText");
        v152 = PropertyUtils::Get<char const *>(v3, v151, DEPTH_RECURSE);
        v153 = UFG::qStringHash32(v150, 0xFFFFFFFF);
        uiscreen_type.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v152, v153, (__int64)&uiscreen_type);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v148 = result.mUID;
      }
      if ( v6->mpSnapshots[0]->mInts[23].mValue > v148 )
        v148 = v6->mpSnapshots[0]->mInts[23].mValue;
      UFG::GameStatTracker::SetStat(v6, StatueOffensiveStage, v148);
    }
    uiscreen_type.mUID = 0;
    v154 = UFG::qSymbol::create_from_string(&result, "GunplayUpgradeStage");
    v155 = UFG::qPropertySet::Get<long>(v3, v154, DEPTH_RECURSE);
    v156 = &uiscreen_type;
    if ( v155 )
      v156 = (UFG::qSymbol *)v155;
    v157 = v156->mUID;
    result.mUID = v157;
    if ( v157 )
    {
      if ( v5 )
      {
        v158 = UFG::qSymbol::create_from_string(&uiscreen_type, "CopStageIcon");
        v159 = PropertyUtils::Get<char const *>(v3, v158, DEPTH_RECURSE);
        v160 = UFG::qSymbol::create_from_string(v253, "CopStageText");
        v161 = PropertyUtils::Get<char const *>(v3, v160, DEPTH_RECURSE);
        v162 = UFG::qStringHash32(v159, 0xFFFFFFFF);
        uiscreen_type.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v161, v162, (__int64)&uiscreen_type);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v157 = result.mUID;
      }
      if ( v6->mpSnapshots[0]->mInts[26].mValue > v157 )
        v157 = v6->mpSnapshots[0]->mInts[26].mValue;
      UFG::GameStatTracker::SetStat(v6, GunplayUpgradeStage, v157);
    }
    LOBYTE(uiscreen_type.mUID) = 0;
    v163 = UFG::qSymbol::create_from_string(&result, "EnablePDA");
    v164 = UFG::qPropertySet::Get<bool>(v3, v163, DEPTH_RECURSE);
    v165 = &uiscreen_type;
    if ( v164 )
      v165 = (UFG::qSymbol *)v164;
    v166 = v165->mUID;
    LOBYTE(uiscreen_type.mUID) = v166;
    if ( v166 )
    {
      if ( v5 )
      {
        v167 = UFG::qSymbol::create_from_string(&result, "EnablePDAIcon");
        v168 = PropertyUtils::Get<char const *>(v3, v167, DEPTH_RECURSE);
        v169 = UFG::qSymbol::create_from_string(v253, "EnablePDAText");
        v170 = PropertyUtils::Get<char const *>(v3, v169, DEPTH_RECURSE);
        v171 = UFG::qStringHash32(v168, 0xFFFFFFFF);
        result.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v170, v171, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v166 = uiscreen_type.mUID;
      }
      if ( !(*((_BYTE *)v6 + 6216) & 1) )
        v6->mpSnapshots[0]->mBools[4].mValue = v166;
    }
    LOBYTE(uiscreen_type.mUID) = 0;
    v172 = UFG::qSymbol::create_from_string(&result, "EnableValet");
    v173 = UFG::qPropertySet::Get<bool>(v3, v172, DEPTH_RECURSE);
    v174 = &uiscreen_type;
    if ( v173 )
      v174 = (UFG::qSymbol *)v173;
    if ( LOBYTE(v174->mUID) && !(*((_BYTE *)v6 + 6216) & 1) )
      v6->mpSnapshots[0]->mBools[5].mValue = v174->mUID;
    LOBYTE(uiscreen_type.mUID) = 0;
    v175 = UFG::qSymbol::create_from_string(&result, "EnableSpyCams");
    v176 = UFG::qPropertySet::Get<bool>(v3, v175, DEPTH_RECURSE);
    v177 = &uiscreen_type;
    if ( v176 )
      v177 = (UFG::qSymbol *)v176;
    v178 = v177->mUID;
    LOBYTE(uiscreen_type.mUID) = v178;
    if ( v178 )
    {
      if ( v5 )
      {
        v179 = UFG::qSymbol::create_from_string(&result, "EnableSpyCamsIcon");
        v180 = PropertyUtils::Get<char const *>(v3, v179, DEPTH_RECURSE);
        v181 = UFG::qSymbol::create_from_string(v253, "EnableSpyCamsText");
        v182 = PropertyUtils::Get<char const *>(v3, v181, DEPTH_RECURSE);
        v183 = UFG::qStringHash32(v180, 0xFFFFFFFF);
        result.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v182, v183, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v178 = uiscreen_type.mUID;
      }
      if ( !(*((_BYTE *)v6 + 6216) & 1) )
        v6->mpSnapshots[0]->mBools[3].mValue = v178;
    }
    LOBYTE(uiscreen_type.mUID) = 0;
    v184 = UFG::qSymbol::create_from_string(&result, "EnableKaraoke");
    v185 = UFG::qPropertySet::Get<bool>(v3, v184, DEPTH_RECURSE);
    v186 = &uiscreen_type;
    if ( v185 )
      v186 = (UFG::qSymbol *)v185;
    if ( LOBYTE(v186->mUID) && !(*((_BYTE *)v6 + 6216) & 1) )
      v6->mpSnapshots[0]->mBools[32].mValue = v186->mUID;
    LOBYTE(uiscreen_type.mUID) = 0;
    v187 = UFG::qSymbol::create_from_string(&result, "EnableHealthShrineIndicators");
    v188 = UFG::qPropertySet::Get<bool>(v3, v187, DEPTH_RECURSE);
    v189 = &uiscreen_type;
    if ( v188 )
      v189 = (UFG::qSymbol *)v188;
    v190 = v189->mUID;
    LOBYTE(uiscreen_type.mUID) = v190;
    if ( v190 )
    {
      if ( v5 )
      {
        v191 = UFG::qSymbol::create_from_string(&result, "EnableHealthShrineIndicatorsIcon");
        v192 = UFG::qPropertySet::Get<char const *>(v3, v191, DEPTH_RECURSE);
        v193 = UFG::qSymbol::create_from_string(v253, "EnableHealthShrineIndicatorsText");
        v194 = UFG::qPropertySet::Get<char const *>(v3, v193, DEPTH_RECURSE);
        v195 = UFG::qStringHash32(v192, 0xFFFFFFFF);
        result.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v194, v195, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v190 = uiscreen_type.mUID;
      }
      if ( !(*((_BYTE *)v6 + 6216) & 1) )
        v6->mpSnapshots[0]->mBools[6].mValue = v190;
    }
    LOBYTE(uiscreen_type.mUID) = 0;
    v196 = UFG::qSymbol::create_from_string(&result, "EnableSpyCamIndicators");
    v197 = UFG::qPropertySet::Get<bool>(v3, v196, DEPTH_RECURSE);
    v198 = &uiscreen_type;
    if ( v197 )
      v198 = (UFG::qSymbol *)v197;
    v199 = v198->mUID;
    LOBYTE(uiscreen_type.mUID) = v199;
    if ( v199 )
    {
      if ( v5 )
      {
        v200 = UFG::qSymbol::create_from_string(&result, "EnableSpyCamIndicatorsIcon");
        v201 = UFG::qPropertySet::Get<char const *>(v3, v200, DEPTH_RECURSE);
        v202 = UFG::qSymbol::create_from_string(v253, "EnableSpyCamIndicatorsText");
        v203 = UFG::qPropertySet::Get<char const *>(v3, v202, DEPTH_RECURSE);
        v204 = UFG::qStringHash32(v201, 0xFFFFFFFF);
        result.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v203, v204, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v199 = uiscreen_type.mUID;
      }
      if ( !(*((_BYTE *)v6 + 6216) & 1) )
        v6->mpSnapshots[0]->mBools[8].mValue = v199;
    }
    LOBYTE(uiscreen_type.mUID) = 0;
    v205 = UFG::qSymbol::create_from_string(&result, "EnableLockboxIndicators");
    v206 = UFG::qPropertySet::Get<bool>(v3, v205, DEPTH_RECURSE);
    v207 = &uiscreen_type;
    if ( v206 )
      v207 = (UFG::qSymbol *)v206;
    v208 = v207->mUID;
    LOBYTE(uiscreen_type.mUID) = v208;
    if ( v208 )
    {
      if ( v5 )
      {
        v209 = UFG::qSymbol::create_from_string(&result, "EnableLockboxIndicatorsIcon");
        v210 = PropertyUtils::Get<char const *>(v3, v209, DEPTH_RECURSE);
        v211 = UFG::qSymbol::create_from_string(v253, "EnableLockboxIndicatorsText");
        v212 = PropertyUtils::Get<char const *>(v3, v211, DEPTH_RECURSE);
        v213 = UFG::qStringHash32(v210, 0xFFFFFFFF);
        result.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v212, v213, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v208 = uiscreen_type.mUID;
      }
      if ( !(*((_BYTE *)v6 + 6216) & 1) )
        v6->mpSnapshots[0]->mBools[7].mValue = v208;
    }
    LOBYTE(uiscreen_type.mUID) = 0;
    v214 = UFG::qSymbol::create_from_string(&result, "EnableJumpIndicators");
    v215 = UFG::qPropertySet::Get<bool>(v3, v214, DEPTH_RECURSE);
    v216 = &uiscreen_type;
    if ( v215 )
      v216 = (UFG::qSymbol *)v215;
    v217 = v216->mUID;
    LOBYTE(uiscreen_type.mUID) = v217;
    if ( v217 )
    {
      if ( v5 )
      {
        v218 = UFG::qSymbol::create_from_string(&result, "EnableJumpIndicatorsIcon");
        v219 = PropertyUtils::Get<char const *>(v3, v218, DEPTH_RECURSE);
        v220 = UFG::qSymbol::create_from_string(v253, "EnableJumpIndicatorsText");
        v221 = PropertyUtils::Get<char const *>(v3, v220, DEPTH_RECURSE);
        v222 = UFG::qStringHash32(v219, 0xFFFFFFFF);
        result.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v221, v222, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v217 = uiscreen_type.mUID;
      }
      if ( !(*((_BYTE *)v6 + 6216) & 1) )
        v6->mpSnapshots[0]->mBools[10].mValue = v217;
    }
    LOBYTE(uiscreen_type.mUID) = 0;
    v223 = UFG::qSymbol::create_from_string(&result, "EnableJadeStatueIndicators");
    v224 = UFG::qPropertySet::Get<bool>(v3, v223, DEPTH_RECURSE);
    v225 = &uiscreen_type;
    if ( v224 )
      v225 = (UFG::qSymbol *)v224;
    v226 = v225->mUID;
    LOBYTE(uiscreen_type.mUID) = v226;
    if ( v226 )
    {
      if ( v5 )
      {
        v227 = UFG::qSymbol::create_from_string(&result, "EnableJadeStatueIndicatorsIcon");
        v228 = PropertyUtils::Get<char const *>(v3, v227, DEPTH_RECURSE);
        v229 = UFG::qSymbol::create_from_string(v253, "EnableJadeStatueIndicatorsText");
        v230 = PropertyUtils::Get<char const *>(v3, v229, DEPTH_RECURSE);
        v231 = UFG::qStringHash32(v228, 0xFFFFFFFF);
        result.mUID = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v230, v231, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v226 = uiscreen_type.mUID;
      }
      if ( !(*((_BYTE *)v6 + 6216) & 1) )
        v6->mpSnapshots[0]->mBools[9].mValue = v226;
    }
    v232 = UFG::qSymbol::create_from_string(&uiscreen_type, "UnlockItems");
    v233 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, v232, DEPTH_RECURSE);
    v234 = v233;
    if ( v233 )
    {
      v235 = v233->mNumElements;
      if ( v235 )
      {
        v236 = showRewardTypea;
        do
        {
          v237 = UFG::qPropertyList::GetValuePtr(v234, 0x1Au, v4);
          if ( v237 )
          {
            v238 = *(_QWORD *)v237;
            if ( *(_QWORD *)v237 )
            {
              if ( &v237[v238] )
              {
                *(_QWORD *)&result.mUID = &showRewardTypea;
                showRewardTypea = v11;
                UFG::RewardsHandler::HandleRewardList(v236, (UFG::qPropertySet *)&v237[v238], (__int64)&showRewardTypea);
              }
            }
          }
          ++v4;
        }
        while ( v4 < v235 );
      }
    }
  }
  if ( v5 )
  {
    v239 = UFG::PerkGoalTracker::Instance();
    v240 = UFG::PerkGoalTracker::GetNumGoalsSatisfied(v239);
    if ( v240 )
    {
      UFG::qString::qString(&v257, "%d Perk Goals Succeeded", v240);
      *(_QWORD *)&uiscreen_type.mUID = &showRewardTypea;
      showRewardTypea = v11;
      UFG::UIHKScreenMissionComplete::AddReward(v257.mData, UFG::gRewardIcon_CopJob, (__int64)&showRewardTypea);
      UFG::RewardsHandler::mItemUnlocked = 1;
      UFG::qString::~qString(&v257);
    }
  }
  if ( UFG::RewardsHandler::mItemUnlocked )
  {
    *(_QWORD *)&uiscreen_type.mUID = &showRewardTypea;
    showRewardTypea = v11;
  }
  if ( v5 )
  {
    if ( v11 == qSymbol_UIMissionComplete.mUID )
    {
      v241 = UFG::CopSystem::Instance();
      ((void (__fastcall *)(UFG::CopSystem *, _QWORD, _QWORD))v241->vfptr[88].__vecDelDtor)(v241, 0i64, 0i64);
    }
  }
  return 1;
}(UFG::CopSystem *, _QWORD, _QWORD))v241->vfptr[88].__vecDelDtor)(v241, 0i64, 0i64);
    }
  }
  return 1;
}

// File Line: 849
// RVA: 0x4C2F20
void __fastcall UFG::RewardsHandler::UISetup(__int64 gameslice_type, __int64 gameslice_subtype, __int64 screen_type, UFG::qPropertySet *pReward)
{
  UFG::qPropertySet *v4; // rbx
  unsigned int *v5; // rdi
  unsigned int *v6; // rsi
  UFG::qSymbol *v7; // rax
  bool *v8; // rax
  UFG::qSymbol *v9; // rcx
  char v10; // r9
  unsigned int v11; // er12
  unsigned int v12; // esi
  const char *v13; // rdi
  unsigned int v14; // ebx
  __int64 v15; // r15
  UFG::PersistentData::MapBool *v16; // rsi
  const char *v17; // r15
  UFG::GameStatTracker *v18; // rax
  int v19; // ebx
  const char *v20; // rax
  char *v21; // rbx
  UFG::qSymbol *v22; // r8
  UFG::qPropertySet *v23; // rdi
  UFG::qSymbol *v24; // rax
  UFG::qPropertyList *v25; // rax
  char *v26; // rax
  UFG::qPropertySet *v27; // rbx
  UFG::qSymbol *v28; // rax
  const char *v29; // rax
  const char *v30; // rax
  const char *v31; // rax
  const char *v32; // rdx
  const char *v33; // rax
  const char *v34; // rbx
  UFG::UIHKInfoPopupWidget *v35; // rax
  UFG::qSymbol gamesliceType; // [rsp+8h] [rbp-59h]
  UFG::qSymbol result[2]; // [rsp+10h] [rbp-51h]
  UFG::qSymbol v38[2]; // [rsp+18h] [rbp-49h]
  UFG::qPropertyDepth depth[2]; // [rsp+20h] [rbp-41h]
  int v40; // [rsp+28h] [rbp-39h]
  char *v41; // [rsp+38h] [rbp-29h]
  __int64 v42; // [rsp+48h] [rbp-19h]
  UFG::qSymbol *v43; // [rsp+50h] [rbp-11h]
  UFG::qString v44; // [rsp+58h] [rbp-9h]
  UFG::qSymbol gamesliceSubType; // [rsp+C8h] [rbp+67h]
  UFG::SceneObjectProperties *retaddr; // [rsp+D8h] [rbp+77h]
  char *caption; // [rsp+E0h] [rbp+7Fh]

  v42 = -2i64;
  v4 = pReward;
  v5 = (unsigned int *)gameslice_subtype;
  v6 = (unsigned int *)gameslice_type;
  if ( *(_DWORD *)screen_type == qSymbol_UIMissionComplete.mUID )
  {
    LOBYTE(gamesliceSubType.mUID) = 0;
    v7 = UFG::qSymbol::create_from_string(result, "ShowExperienceTutorial");
    v8 = UFG::qPropertySet::Get<bool>(v4, v7, DEPTH_RECURSE);
    v9 = &gamesliceSubType;
    if ( v8 )
      v9 = (UFG::qSymbol *)v8;
    v10 = v9->mUID;
    *(_QWORD *)&v38[0].mUID = &gamesliceSubType;
    *(_QWORD *)&result[0].mUID = &gamesliceType;
    gamesliceSubType.mUID = *v5;
    gamesliceType.mUID = *v6;
    UFG::UIHKScreenMissionComplete::Activate((__int64)&gamesliceType, (__int64)&gamesliceSubType, caption, v10);
    UFG::RewardsHandler::mItemUnlocked = 1;
  }
  else if ( *(_DWORD *)screen_type == qSymbol_UIHintText.mUID && retaddr )
  {
    v11 = 0;
    v12 = 0;
    v13 = &customWorldMapCaption;
    gamesliceSubType.mUID = qSymbol_none_14.mUID;
    PropertyUtils::GetWithDefault<UFG::qSymbol>(
      result,
      retaddr,
      (UFG::qSymbol *)&SimSym_CollectibleType.mUID,
      (__int64)&gamesliceType,
      DEPTH_RECURSE);
    v14 = result[0].mUID;
    if ( result[0].mUID != -1 )
    {
      v15 = (signed int)UFG::GameStat::GetMapBoolStatEnum(result, 1);
      v16 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[v15];
      v11 = UFG::PersistentData::MapBool::GetTrueCount(v16);
      if ( v16->mKeepType )
      {
        if ( (unsigned int)(v16->mKeepType - 1) > 1 )
          v12 = 0;
        else
          v12 = v16->mNames.size;
      }
      else
      {
        v12 = v16->mValues.size;
      }
      switch ( (_DWORD)v15 )
      {
        case 0x17:
          gamesliceSubType.mUID = qSymbol_Collectible_HealthShrine_14.mUID;
          v13 = "$COMMON_ABERDEEN";
          break;
        case 0x18:
          gamesliceSubType.mUID = qSymbol_Collectible_HealthShrine_14.mUID;
          v13 = "$COMMON_CENTRAL";
          break;
        case 0x19:
          gamesliceSubType.mUID = qSymbol_Collectible_HealthShrine_14.mUID;
          v13 = "$COMMON_KENNEDY_TOWN";
          break;
        case 0x1A:
          gamesliceSubType.mUID = qSymbol_Collectible_HealthShrine_14.mUID;
          v13 = "$COMMON_NORTH_POINT";
          break;
        case 0x1B:
          gamesliceSubType.mUID = qSymbol_Collectible_LockBox_14.mUID;
          v13 = "$COMMON_ABERDEEN";
          break;
        case 0x1C:
          gamesliceSubType.mUID = qSymbol_Collectible_LockBox_14.mUID;
          v13 = "$COMMON_CENTRAL";
          break;
        case 0x1D:
          gamesliceSubType.mUID = qSymbol_Collectible_LockBox_14.mUID;
          v13 = "$COMMON_KENNEDY_TOWN";
          break;
        case 0x1E:
          gamesliceSubType.mUID = qSymbol_Collectible_LockBox_14.mUID;
          v13 = "$COMMON_NORTH_POINT";
          break;
        default:
          gamesliceSubType.mUID = v14;
          break;
      }
    }
    v17 = UFG::UI::LocalizeText(v13);
    UFG::qString::qString((UFG::qString *)depth);
    if ( gamesliceSubType.mUID == qSymbol_Collectible_HealthShrine_14.mUID )
    {
      v18 = UFG::GameStatTracker::Instance();
      v19 = (unsigned int)UFG::GameStatTracker::GetNumHealthShrinesCollected(v18) % 5;
      UFG::UIHKInfoPopupWidget::Get()->HealthShrineUpgradeProgress = v19;
      if ( v19 )
      {
        v20 = UFG::UI::LocalizeText("$HUD_COLLECTIBLES_HEALTHSHRINE_PROGRESS");
        v40 = 5 - v19;
        *(_QWORD *)depth = v17;
        UFG::qString::Format((UFG::qString *)depth, v20, v11, v12, v17, *(_QWORD *)&v40);
      }
      else
      {
        UFG::qString::Format((UFG::qString *)depth, "$HUD_COLLECTIBLES_HEALTHSHRINE_SUCCESS");
      }
    }
    else if ( gamesliceSubType.mUID == qSymbol_Collectible_LockBox_14.mUID )
    {
      v21 = 0i64;
      v43 = result;
      v22 = UFG::qSymbol::create_from_string(v38, "RewardsPropertySet");
      PropertyUtils::GetWithDefault<UFG::qSymbol>(&gamesliceType, retaddr, v22, (__int64)result, DEPTH_RECURSE);
      if ( gamesliceType.mUID != -1 )
      {
        v23 = UFG::PropertySetManager::GetPropertySet(&gamesliceType);
        if ( v23 )
        {
          v24 = UFG::qSymbol::create_from_string(v38, "UnlockItems");
          v25 = UFG::qPropertySet::Get<UFG::qPropertyList>(v23, v24, DEPTH_RECURSE);
          if ( v25 )
          {
            if ( v25->mNumElements > 0 )
            {
              v26 = UFG::qPropertyList::GetValuePtr(v25, 0x1Au, 0);
              if ( v26 && *(_QWORD *)v26 )
                v27 = (UFG::qPropertySet *)&v26[*(_QWORD *)v26];
              else
                v27 = 0i64;
              v28 = UFG::qSymbol::create_from_string(v38, "Text");
              v21 = PropertyUtils::Get<char const *>(v27, v28, DEPTH_RECURSE);
            }
          }
        }
      }
      v29 = UFG::UI::LocalizeText("$HUD_COLLECTIBLES_LOCKBOX_SUCCESS");
      *(_QWORD *)depth = v17;
      UFG::qString::Format((UFG::qString *)depth, v29, v11, v12, v17);
      if ( v21 )
      {
        UFG::qString::operator+=((UFG::qString *)depth, "<br><br>");
        v30 = UFG::UI::LocalizeText("$HUD_LOCKBOX_CLOTHING_FOUND");
        UFG::qString::operator+=((UFG::qString *)depth, v30);
        UFG::qString::operator+=((UFG::qString *)depth, " ");
        v31 = UFG::UI::LocalizeText(v21);
        UFG::qString::operator+=((UFG::qString *)depth, v31);
      }
    }
    else if ( gamesliceSubType.mUID == qSymbol_Collectible_DLC_01_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_02_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_03_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_04_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_05_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_06_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_07_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_08_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_09_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_10_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_11_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_12_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_13_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_14_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_15_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_16_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_17_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_18_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_19_14.mUID
           || gamesliceSubType.mUID == qSymbol_Collectible_DLC_20_14.mUID )
    {
      UFG::qString::qString(&v44);
      if ( PropertyUtils::PropertyExists(retaddr, (UFG::qSymbol *)&qSymbol_Collectible_Caption_14.mUID) )
        v32 = (const char *)PropertyUtils::Get<char const *>(
                              retaddr,
                              (UFG::qSymbol *)&qSymbol_Collectible_Caption_14.mUID);
      else
        v32 = "$HUD_COLLECTIBLE_GENERIC_SUCCESS";
      UFG::qString::Set(&v44, v32);
      v33 = UFG::UI::LocalizeText(v44.mData);
      v34 = v33;
      if ( (signed int)v12 > 0 && v33 && (signed int)UFG::qStringLength(v33) > 0 )
        UFG::qString::Format((UFG::qString *)depth, v34, v11, v12);
      UFG::qString::~qString(&v44);
    }
    v35 = UFG::UIHKInfoPopupWidget::Get();
    UFG::UIHKInfoPopupWidget::Show(v35, v41, &gamesliceSubType, 5.0, 0);
    UFG::RewardsHandler::mItemUnlocked = 1;
    UFG::qString::~qString((UFG::qString *)depth);
  }
}

// File Line: 999
// RVA: 0x4A1D50
__int64 __fastcall UFG::RewardsHandler::GetCappedScorePerMission(int score, UFG::GameStat::MapInt32Stat dbEntry, __int64 symGameSlice)
{
  UFG::qSymbol *v3; // rsi
  __int64 v4; // rbp
  int v5; // edi
  UFG::GameStatTracker *v6; // rbx
  UFG::PersistentData::MapInt *v7; // rdx
  __int64 v8; // rax
  UFG::PersistentData::KeyValue *v9; // rcx
  int v10; // ebx
  UFG::GameStatTracker *v11; // rax

  v3 = (UFG::qSymbol *)symGameSlice;
  v4 = dbEntry;
  v5 = score;
  v6 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v6 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v6;
  v7 = v6->mpSnapshots[0]->mpMapInts[v4];
  v8 = 0i64;
  if ( !v7->mValues.size )
    goto LABEL_12;
  v9 = v7->mValues.p;
  while ( v9->mKey.mUID != v3->mUID )
  {
    v8 = (unsigned int)(v8 + 1);
    ++v9;
    if ( (unsigned int)v8 >= v7->mValues.size )
      goto LABEL_12;
  }
  if ( (_DWORD)v8 != -1 )
    v10 = v7->mValues.p[v8].mIntValue;
  else
LABEL_12:
    v10 = 0;
  if ( v10 >= v5 )
    return 0i64;
  v11 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v11, (UFG::GameStat::MapInt32Stat)v4, v3, v5);
  return (unsigned int)(v5 - v10);
}

