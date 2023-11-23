// File Line: 39
// RVA: 0x152FD30
__int64 UFG::_dynamic_initializer_for__qSymbol_Type__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Type", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_Type, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_Type__);
}

// File Line: 40
// RVA: 0x152E230
__int64 UFG::_dynamic_initializer_for__qSymbol_AssetId__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AssetId", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_AssetId, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_AssetId__);
}

// File Line: 41
// RVA: 0x152FBF0
__int64 UFG::_dynamic_initializer_for__qSymbol_Text__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Text", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_Text, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_Text__);
}

// File Line: 42
// RVA: 0x152F130
__int64 UFG::_dynamic_initializer_for__qSymbol_Icon__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Icon", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_Icon, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_Icon__);
}

// File Line: 43
// RVA: 0x152F970
__int64 UFG::_dynamic_initializer_for__qSymbol_Permanent__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Permanent", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_Permanent, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_Permanent__);
}

// File Line: 45
// RVA: 0x152FDB0
__int64 UFG::_dynamic_initializer_for__qSymbol_UIMissionComplete__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MISSION_COMPLETE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_UIMissionComplete, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_UIMissionComplete__);
}

// File Line: 46
// RVA: 0x152FD70
__int64 UFG::_dynamic_initializer_for__qSymbol_UIHintText__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("HINT_TEXT", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_UIHintText, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_UIHintText__);
}

// File Line: 48
// RVA: 0x152F770
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierNone__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("None", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierNone, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierNone__);
}

// File Line: 49
// RVA: 0x152F6F0
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierMinor__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Minor", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierMinor, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierMinor__);
}

// File Line: 50
// RVA: 0x152F670
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierMiddle__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Middle", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierMiddle, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierMiddle__);
}

// File Line: 51
// RVA: 0x152F5F0
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierMajor__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Major", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierMajor, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierMajor__);
}

// File Line: 56
// RVA: 0x4A7D30
void __fastcall UFG::RewardsHandler::HandleRewardList(
        UFG::ShowRewardType showRewardType,
        UFG::qPropertySet *pItemPropertySet,
        unsigned int *uiscreen_type)
{
  bool v5; // di
  unsigned int mUID; // ebx
  char *v7; // r15
  bool *v8; // rax
  bool v9; // r14
  char *v10; // rdi
  char *v11; // rax
  unsigned int v12; // eax
  UFG::GameLogManager *Instance; // rcx
  UFG::GameStatTracker *v14; // rdi
  UFG::GameStatTracker *v15; // rax
  unsigned int v16; // edx
  UFG::GameStatTracker *v17; // r8
  UFG::GameStatTracker *v18; // rax
  UFG::GameStatTracker *v19; // rax
  UFG::GameStatTracker *v20; // rax
  UFG::GameStat::MapBoolStat v21; // ecx
  UFG::GameStatTracker *v22; // rax
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::DoorComponent *ComponentOfType; // rax
  UFG::GameStatTracker *v25; // rax
  UFG::GameStatTracker *v26; // rax
  UFG::GameStatTracker *v27; // rax
  unsigned int v28; // ecx
  UFG::GameStatTracker *v29; // r8
  UFG::GameStatTracker *v30; // rax
  UFG::qArray<unsigned long,0> *v31; // rax
  UFG::qArray<unsigned long,0> *v32; // rax
  UFG::qArray<unsigned long,0> *v33; // rax
  UFG::GameStatTracker *v34; // rsi
  UFG::eFactionStandingEnum v35; // edi
  UFG::eFactionClassEnum v36; // ebx
  UFG::eFactionClassEnum v37; // eax
  UFG::GameStatTracker *v38; // rax
  UFG::GameStatTracker *v39; // rax
  UFG::qArray<unsigned long,0> *v40; // rax
  int *v41; // rax
  UFG::qSymbol *v42; // rbx
  UFG::GameStatTracker *v43; // rax
  unsigned int v44; // edx
  UFG::GameStatTracker *v45; // r8
  UFG::qArray<unsigned long,0> *v46; // rax
  int v47; // ebx
  UFG::GameStatTracker *v48; // rax
  UFG::UIHKScreenHud *v49; // rax
  UFG::GameStatTracker *v50; // rax
  UFG::qArray<unsigned long,0> *v51; // rax
  int v52; // ebx
  UFG::GameStatTracker *v53; // rax
  UFG::ProgressionTracker *v54; // rax
  UFG::ProgressionTracker *v55; // rdi
  UFG::qBaseTreeRB *v56; // rbx
  UFG::qArray<unsigned long,0> *v57; // rax
  bool *v58; // rax
  bool *p_uiscreen_typea; // rdx
  UFG::GameStatTracker *v60; // rax
  AnimationGroupHandleContainer *p_mAnimationGroupHandleContainer; // rdi
  UFG::GameSnapshot *v62; // rdx
  UFG::GameStatTracker *v63; // rax
  UFG::GameStatTracker *v64; // rax
  UFG::GameStatTracker *v65; // rax
  UFG::GameStatTracker *v66; // rax
  UFG::GameStatTracker *v67; // rax
  UFG::GameStatTracker *v68; // rax
  UFG::GameStatTracker *v69; // rax
  UFG::qSymbol v70[2]; // [rsp+8h] [rbp-39h] BYREF
  UFG::qSymbol assetID; // [rsp+10h] [rbp-31h] BYREF
  UFG::qSymbol symbol; // [rsp+14h] [rbp-2Dh] BYREF
  UFG::qSymbol v73[2]; // [rsp+18h] [rbp-29h] BYREF
  UFG::qSymbol v74; // [rsp+20h] [rbp-21h] BYREF
  UFG::qSymbol v75; // [rsp+24h] [rbp-1Dh] BYREF
  UFG::qSymbol v76; // [rsp+28h] [rbp-19h] BYREF
  UFG::qSymbol v77; // [rsp+2Ch] [rbp-15h] BYREF
  UFG::qSymbol v78; // [rsp+30h] [rbp-11h] BYREF
  UFG::qSymbol v79; // [rsp+34h] [rbp-Dh] BYREF
  UFG::qWiseSymbol v80; // [rsp+38h] [rbp-9h] BYREF
  __int64 v81; // [rsp+40h] [rbp-1h]
  UFG::qString v82; // [rsp+48h] [rbp+7h] BYREF
  UFG::qSymbol uiscreen_typea; // [rsp+A8h] [rbp+67h] BYREF
  UFG::qSymbol result; // [rsp+C0h] [rbp+7Fh] BYREF

  v81 = -2i64;
  v5 = showRewardType == ShowReward;
  mUID = PropertyUtils::Get<UFG::qSymbol>(
           pItemPropertySet,
           (UFG::qArray<unsigned long,0> *)&qSymbol_Type,
           DEPTH_RECURSE)->mUID;
  v7 = PropertyUtils::Get<char const *>(
         pItemPropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_AssetId,
         DEPTH_RECURSE);
  UFG::qSymbol::create_from_string(&result, v7);
  v8 = PropertyUtils::Get<bool>(pItemPropertySet, (UFG::qArray<unsigned long,0> *)&qSymbol_Permanent, DEPTH_RECURSE);
  if ( v8 )
    v9 = *v8;
  else
    v9 = 0;
  if ( v5 )
  {
    v10 = PropertyUtils::Get<char const *>(
            pItemPropertySet,
            (UFG::qArray<unsigned long,0> *)&qSymbol_Text,
            DEPTH_RECURSE);
    v11 = PropertyUtils::Get<char const *>(
            pItemPropertySet,
            (UFG::qArray<unsigned long,0> *)&qSymbol_Icon,
            DEPTH_RECURSE);
    v12 = UFG::qStringHash32(v11, 0xFFFFFFFF);
    *(_QWORD *)&v73[0].mUID = &uiscreen_typea;
    uiscreen_typea.mUID = *uiscreen_type;
    UFG::UIHKScreenMissionComplete::AddReward(v10, v12, (__int64)&uiscreen_typea);
    uiscreen_typea.mUID = qSymbol_GameLogType_RewardsUpgrades_14.mUID;
    Instance = UFG::GameLogManager::getInstance();
    UFG::GameLogManager::LogItem(Instance, (UFG::qSymbol)&uiscreen_typea, v10);
    UFG::RewardsHandler::mItemUnlocked = 1;
  }
  v14 = &sGameStatTracker;
  if ( v9 )
  {
    v15 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v15 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapBool::SetStatus(v15->mpSnapshots[0]->mpMapBools[83], &result, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v16 = _S12_6;
        if ( (_S12_6 & 1) == 0 )
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
        if ( (v16 & 1) == 0 )
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
      }
    }
  }
  if ( mUID > 0x6732E074 )
  {
    if ( mUID > 0x958197CB )
    {
      if ( mUID > 0xAD5FAF23 )
      {
        if ( mUID == -129728948 )
        {
          v69 = UFG::GameStatTracker::Instance();
          if ( (*((_BYTE *)v69 + 6216) & 1) == 0 )
          {
            UFG::PersistentData::MapBool::SetStatus(v69->mpSnapshots[0]->mpMapBools[0], &result, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
              uiscreen_typea.mUID = result.mUID;
              v21 = DynamicTutorials;
              goto LABEL_137;
            }
          }
        }
        else if ( mUID == -74896581 )
        {
          v68 = UFG::GameStatTracker::Instance();
          if ( (*((_BYTE *)v68 + 6216) & 1) == 0 )
          {
            UFG::PersistentData::MapBool::SetStatus(v68->mpSnapshots[0]->mpMapBools[6], &result, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
              uiscreen_typea.mUID = result.mUID;
              v21 = Collectible_Melee;
              goto LABEL_137;
            }
          }
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0xAD5FAF23:
            v67 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v67, Collectible_CaseDoc, &result, 1);
            return;
          case 0x9773EC16:
            v66 = UFG::GameStatTracker::Instance();
            if ( (*((_BYTE *)v66 + 6216) & 1) == 0 )
            {
              UFG::PersistentData::MapBool::SetStatus(v66->mpSnapshots[0]->mpMapBools[61], &result, 1);
              if ( UFG::GameStatAction::PostStat::sIsEnabled )
              {
                *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
                uiscreen_typea.mUID = result.mUID;
                v21 = Asset_Clothing;
                goto LABEL_137;
              }
            }
            break;
          case 0x9B06086B:
            v65 = UFG::GameStatTracker::Instance();
            if ( (*((_BYTE *)v65 + 6216) & 1) == 0 )
            {
              UFG::PersistentData::MapBool::SetStatus(v65->mpSnapshots[0]->mpMapBools[62], &result, 1);
              if ( UFG::GameStatAction::PostStat::sIsEnabled )
              {
                *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
                uiscreen_typea.mUID = result.mUID;
                v21 = Asset_Vehicle;
                goto LABEL_137;
              }
            }
            break;
          case 0xACB107F7:
            v64 = UFG::GameStatTracker::Instance();
            if ( (*((_BYTE *)v64 + 6216) & 1) == 0 )
            {
              UFG::PersistentData::MapBool::SetStatus(v64->mpSnapshots[0]->mpMapBools[63], &result, 1);
              if ( UFG::GameStatAction::PostStat::sIsEnabled )
              {
                *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
                uiscreen_typea.mUID = result.mUID;
                v21 = Asset_Boat;
                goto LABEL_137;
              }
            }
            break;
        }
      }
      return;
    }
    if ( mUID == -1786669109 )
    {
      p_mAnimationGroupHandleContainer = &UFG::ProgressionTracker::Instance()->mAnimationGroupHandleContainer;
      v62 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
      if ( v62->mStrings[6].mValue.mLength )
        AnimationGroupHandleContainer::Remove(p_mAnimationGroupHandleContainer, v62->mStrings[6].mValue.mData);
      UFG::qString::qString(&v82, v7);
      v63 = UFG::GameStatTracker::Instance();
      if ( (*((_BYTE *)v63 + 6216) & 1) == 0 )
        UFG::qString::Set(&v63->mpSnapshots[0]->mStrings[6].mValue, v82.mData, v82.mLength, 0i64, 0);
      UFG::qString::~qString(&v82);
      AnimationGroupHandleContainer::Add(p_mAnimationGroupHandleContainer, v7, eANIM_PRIORITY_REQUIRED);
      AnimationGroupHandleContainer::Bind(p_mAnimationGroupHandleContainer);
      return;
    }
    if ( mUID <= 0x8A5A95FC )
    {
      switch ( mUID )
      {
        case 0x8A5A95FC:
          v50 = UFG::GameStatTracker::Instance();
          if ( (*((_BYTE *)v50 + 6216) & 1) == 0 )
          {
            UFG::PersistentData::MapBool::SetStatus(v50->mpSnapshots[0]->mpMapBools[64], &result, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
              uiscreen_typea.mUID = result.mUID;
              v21 = Asset_Weapon;
              goto LABEL_137;
            }
          }
          break;
        case 0x748078A5u:
          v46 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v75, "Status");
          v47 = *PropertyUtils::Get<long>(pItemPropertySet, v46, DEPTH_RECURSE);
          v48 = UFG::GameStatTracker::Instance();
          if ( (*((_BYTE *)v48 + 6216) & 1) == 0 )
          {
            UFG::PersistentData::MapInt::SetStatus(v48->mpSnapshots[0]->mpMapInts[18], &result, v47);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              uiscreen_typea.mUID = result.mUID;
              UFG::GameStatAction::PostStat::AchieveMapInt(Collectible_CaseLeads, (UFG::qSymbol)&uiscreen_typea);
            }
          }
          if ( v47 == 2 )
          {
            v49 = UFG::UIHKScreenHud::getInstance();
            if ( v49 )
              UFG::UIHKScreenHud::LeadUnlocked(v49, (UFG::qSymbol)&assetID);
          }
          break;
        case 0x810BC917:
          v39 = UFG::GameStatTracker::Instance();
          if ( (*((_BYTE *)v39 + 6216) & 1) == 0 )
            v39->mpSnapshots[0]->mBools[2].mValue = 1;
          v40 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v74, "BioId");
          v41 = UFG::qPropertySet::Get<long>(pItemPropertySet, v40, DEPTH_RECURSE);
          v42 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v80, *v41);
          v43 = UFG::GameStatTracker::Instance();
          if ( (*((_BYTE *)v43 + 6216) & 1) == 0 )
          {
            UFG::PersistentData::MapBool::SetStatus(v43->mpSnapshots[0]->mpMapBools[22], v42, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              v44 = _S12_6;
              if ( (_S12_6 & 1) == 0 )
              {
                _S12_6 |= 1u;
                UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                v44 = _S12_6;
              }
              v45 = &sGameStatTracker;
              if ( UFG::GameStatTracker::mspInstance )
                v45 = UFG::GameStatTracker::mspInstance;
              UFG::GameStatTracker::mspInstance = v45;
              if ( (v44 & 1) == 0 )
              {
                _S12_6 = v44 | 1;
                UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                v45 = UFG::GameStatTracker::mspInstance;
              }
              if ( v45 )
                v14 = v45;
              UFG::GameStatTracker::mspInstance = v14;
            }
          }
          break;
        case 0x82369252:
          v38 = UFG::GameStatTracker::Instance();
          if ( (*((_BYTE *)v38 + 6216) & 1) == 0 )
          {
            UFG::PersistentData::MapBool::SetStatus(v38->mpSnapshots[0]->mpMapBools[3], &result, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
              uiscreen_typea.mUID = result.mUID;
              v21 = Collectible_BusStop;
              goto LABEL_137;
            }
          }
          break;
      }
      return;
    }
    if ( mUID == -1950744936 )
    {
      v60 = UFG::GameStatTracker::Instance();
      if ( (*((_BYTE *)v60 + 6216) & 1) == 0 )
      {
        UFG::PersistentData::MapBool::SetStatus(v60->mpSnapshots[0]->mpMapBools[4], &result, 1);
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
          uiscreen_typea.mUID = result.mUID;
          v21 = Collectible_Gunplay;
          goto LABEL_137;
        }
      }
      return;
    }
    if ( mUID != -1907341976 )
    {
      if ( mUID == -1819210089 )
      {
        v51 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v76, "Faction");
        v52 = *PropertyUtils::Get<long>(pItemPropertySet, v51, DEPTH_RECURSE);
        v53 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v53 + 6216) & 1) == 0 )
        {
          UFG::PersistentData::MapInt::SetStatus(v53->mpSnapshots[0]->mpMapInts[17], &result, v52);
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            uiscreen_typea.mUID = result.mUID;
            UFG::GameStatAction::PostStat::AchieveMapInt(Collectible_AreaOwnership, (UFG::qSymbol)&uiscreen_typea);
          }
        }
      }
      return;
    }
    v54 = UFG::ProgressionTracker::Instance();
    v55 = v54;
    if ( !result.mUID )
      goto LABEL_101;
    v56 = UFG::qBaseTreeRB::Get(&v54->mGameSlices.mTree, result.mUID);
    if ( v56 )
      goto LABEL_102;
    if ( result.mUID )
      v56 = UFG::qBaseTreeRB::Get(&v55->mContainerGameSlices.mTree, result.mUID);
    else
LABEL_101:
      v56 = 0i64;
LABEL_102:
    if ( v56 )
    {
      LOBYTE(uiscreen_typea.mUID) = 0;
      v57 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v73, "GiveRewards");
      v58 = UFG::qPropertySet::Get<bool>(pItemPropertySet, v57, DEPTH_RECURSE);
      p_uiscreen_typea = (bool *)&uiscreen_typea;
      if ( v58 )
        p_uiscreen_typea = v58;
      UFG::GameSlice::_SimulateComplete((UFG::GameSlice *)v56, *p_uiscreen_typea);
    }
    return;
  }
  if ( mUID == 1731387508 )
  {
    v31 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v77, "FactionA");
    UFG::qPropertySet::Get<UFG::qSymbol>(pItemPropertySet, v31, DEPTH_RECURSE);
    v32 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v78, "FactionB");
    UFG::qPropertySet::Get<UFG::qSymbol>(pItemPropertySet, v32, DEPTH_RECURSE);
    v33 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v79, "Standing");
    uiscreen_typea.mUID = UFG::qPropertySet::Get<UFG::qSymbol>(pItemPropertySet, v33, DEPTH_RECURSE)->mUID;
    v34 = UFG::FactionInterface::Get();
    v35 = (unsigned int)UFG::FactionInterface::MapSymbolToStanding(&uiscreen_typea);
    v36 = (unsigned int)UFG::FactionInterface::MapSymbolToFaction(&symbol);
    v37 = (unsigned int)UFG::FactionInterface::MapSymbolToFaction(v70);
    UFG::FactionInterface::SetStanding(&v34->mFactionInterface, v37, v36, v35);
    return;
  }
  if ( mUID > 0x28B63779 )
  {
    if ( mUID == 1141147779 )
    {
      v30 = UFG::GameStatTracker::Instance();
      if ( (*((_BYTE *)v30 + 6216) & 1) == 0 )
      {
        UFG::PersistentData::MapBool::SetStatus(v30->mpSnapshots[0]->mpMapBools[31], &result, 1);
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
          uiscreen_typea.mUID = result.mUID;
          v21 = Collectible_SpyCam;
          goto LABEL_137;
        }
      }
    }
    else if ( mUID == 1571868732 )
    {
      v27 = UFG::GameStatTracker::Instance();
      if ( (*((_BYTE *)v27 + 6216) & 1) == 0 )
      {
        UFG::PersistentData::MapBool::SetStatus(v27->mpSnapshots[0]->mpMapBools[76], &result, 0);
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v28 = _S12_6;
          if ( (_S12_6 & 1) == 0 )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            v28 = _S12_6;
          }
          v29 = &sGameStatTracker;
          if ( UFG::GameStatTracker::mspInstance )
            v29 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v29;
          if ( (v28 & 1) == 0 )
          {
            _S12_6 = v28 | 1;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            v29 = UFG::GameStatTracker::mspInstance;
          }
          if ( v29 )
            v14 = v29;
          UFG::GameStatTracker::mspInstance = v14;
        }
      }
    }
  }
  else if ( mUID == 683030393 )
  {
    v26 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v26 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapBool::SetStatus(v26->mpSnapshots[0]->mpMapBools[10], &result, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
        uiscreen_typea.mUID = result.mUID;
        v21 = Collectible_WeaponSpawner;
        goto LABEL_137;
      }
    }
  }
  else if ( mUID == 8816707 )
  {
    v25 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v25 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapBool::SetStatus(v25->mpSnapshots[0]->mpMapBools[5], &result, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
        uiscreen_typea.mUID = result.mUID;
        v21 = Collectible_HidingSpot;
        goto LABEL_137;
      }
    }
  }
  else if ( mUID == 424071789 )
  {
    v22 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v22 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapBool::SetStatus(v22->mpSnapshots[0]->mpMapBools[13], &result, 0);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        uiscreen_typea.mUID = result.mUID;
        UFG::GameStatAction::PostStat::AchieveMapBool(DoorStateLocked, (UFG::qSymbol)&uiscreen_typea);
      }
    }
    SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, &result);
    if ( SimObject )
    {
      ComponentOfType = (UFG::DoorComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)SimObject,
                                                UFG::DoorComponent::_TypeUID);
      if ( ComponentOfType )
        UFG::DoorComponent::UpdateLockedState(ComponentOfType);
    }
  }
  else
  {
    if ( mUID != 457439182 )
    {
      if ( mUID == 484171945 )
      {
        v19 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v19, Collectible_HijackReturn, &result, 1);
      }
      return;
    }
    v20 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v20 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapBool::SetStatus(v20->mpSnapshots[0]->mpMapBools[12], &result, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        *(_QWORD *)&v70[0].mUID = &uiscreen_typea;
        uiscreen_typea.mUID = result.mUID;
        v21 = Collectible_Safehouse;
LABEL_137:
        UFG::GameStatAction::PostStat::AchieveMapBool(v21, (UFG::qSymbol)&uiscreen_typea);
      }
    }
  }
}

// File Line: 264
// RVA: 0x4AA7A0
char __fastcall UFG::RewardsHandler::HandleRewards(
        UFG::ShowRewardType showRewardType,
        UFG::qSymbol *rewardPropertySetName,
        UFG::SceneObjectProperties *pCollectible)
{
  UFG::qPropertySet *PropertySet; // rax

  PropertySet = UFG::PropertySetManager::FindPropertySet(rewardPropertySetName);
  if ( PropertySet )
    PropertySet = UFG::PropertySetManager::GetPropertySet(rewardPropertySetName);
  return UFG::RewardsHandler::HandleRewards(showRewardType, PropertySet, pCollectible);
}

// File Line: 270
// RVA: 0x4A89C0
char __fastcall UFG::RewardsHandler::HandleRewards(
        UFG::ShowRewardType showRewardType,
        UFG::qPropertySet *pProperties,
        UFG::SceneObjectProperties *pCollectible)
{
  unsigned int v4; // r12d
  char v5; // r14
  UFG::GameStatTracker *v6; // r15
  UFG::qArray<unsigned long,0> *v7; // rax
  UFG::qSymbol *v8; // rax
  UFG::qSymbol *v9; // rdi
  UFG::ShowRewardType *v10; // rcx
  UFG::ShowRewardType v11; // ebx
  UFG::qArray<unsigned long,0> *v12; // rax
  UFG::qSymbol *v13; // rax
  UFG::qSymbol *v14; // rcx
  unsigned int mUID; // esi
  UFG::qArray<unsigned long,0> *v16; // rax
  UFG::qSymbol *v17; // rax
  unsigned int v18; // edi
  UFG::qArray<unsigned long,0> *v19; // rax
  bool *v20; // rax
  UFG::ShowRewardType **p_result; // rcx
  UFG::qArray<unsigned long,0> *v22; // rax
  UFG::qArray<unsigned long,0> *v23; // rax
  int *v24; // rax
  unsigned int *v25; // rcx
  unsigned int v26; // edi
  UFG::qArray<unsigned long,0> *v27; // rax
  char *v28; // rdi
  UFG::qArray<unsigned long,0> *v29; // rax
  unsigned int v30; // ecx
  char *mData; // rcx
  UFG::ProgressionTracker *v32; // rax
  UFG::OSuiteLeaderboardManager *v33; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::qSymbol *v35; // rax
  UFG::qArray<unsigned long,0> *v36; // rax
  int *v37; // rax
  UFG::GameStatTracker *v38; // rax
  UFG::GameStatTracker *v39; // rax
  unsigned int v40; // edx
  UFG::GameStatTracker *v41; // r8
  UFG::GameStatTracker *v42; // rax
  UFG::qArray<unsigned long,0> *v43; // rax
  bool *v44; // rax
  int CopScoreBuffed; // edi
  UFG::qArray<unsigned long,0> *v46; // rax
  unsigned int v47; // edi
  bool v48; // al
  UFG::qArray<unsigned long,0> *v49; // rax
  int CappedScorePerMission; // edi
  UFG::qArray<unsigned long,0> *v51; // rax
  int v52; // ecx
  int v53; // eax
  int v54; // eax
  float TriadScorePercentage; // xmm0_4
  UFG::qArray<unsigned long,0> *v56; // rax
  UFG::qArray<unsigned long,0> *v57; // rax
  int v58; // ecx
  int v59; // eax
  int v60; // eax
  UFG::GameSlice *mpActiveMaster; // r14
  const char *mText; // rdi
  UFG::OSuiteLeaderboardManager *v63; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingSliceName; // rdi
  UFG::GameStatTracker *v65; // rax
  signed int Stat; // eax
  int v67; // ecx
  UFG::OSuiteLeaderboardManager *v68; // rax
  UFG::GameStatTracker *v69; // rax
  UFG::GameStatTracker *v70; // rax
  int mLeaderboardId; // r14d
  unsigned __int64 v72; // rdi
  UFG::SocialLogDataManager *v73; // rax
  UFG::qArray<unsigned long,0> *v74; // rax
  char *v75; // rdi
  UFG::qArray<unsigned long,0> *v76; // rax
  unsigned int v77; // edx
  int XPLevel; // edi
  int v79; // edi
  UFG::GameStatTracker *v80; // rdi
  UFG::qArray<unsigned long,0> *v81; // rax
  char *v82; // rdi
  UFG::qArray<unsigned long,0> *v83; // rax
  unsigned int v84; // edi
  UFG::qString *v85; // rax
  int v86; // edi
  int v87; // edi
  UFG::qArray<unsigned long,0> *v88; // rax
  int *v89; // rax
  UFG::ShowRewardType **p_uiscreen_type; // rcx
  int v91; // edi
  UFG::qArray<unsigned long,0> *v92; // rax
  char *v93; // rsi
  UFG::qArray<unsigned long,0> *v94; // rax
  char *v95; // rdi
  unsigned int v96; // eax
  int v97; // edi
  UFG::qArray<unsigned long,0> *v98; // rax
  int *v99; // rax
  int *v100; // rcx
  int v101; // r8d
  UFG::qArray<unsigned long,0> *v102; // rax
  UFG::qSymbol *v103; // rax
  int v104; // eax
  UFG::qSymbol *v105; // rdi
  UFG::ProgressionTracker *v106; // rax
  UFG::qBaseTreeRB *v107; // rax
  int v108; // ecx
  UFG::qSymbol *v109; // rdi
  UFG::ProgressionTracker *v110; // rax
  UFG::qSymbol *v111; // rdi
  UFG::ProgressionTracker *v112; // rax
  UFG::qBaseTreeRB *v113; // rsi
  UFG::qSymbol *v114; // rdi
  UFG::ProgressionTracker *v115; // rax
  UFG::qSymbol *v116; // rdi
  UFG::ProgressionTracker *v117; // rax
  UFG::qBaseTreeRB *v118; // rcx
  int *v119; // rax
  UFG::GameStatTracker *v120; // rax
  UFG::SimObjectCharacter *LocalPlayer; // rax
  __int16 m_Flags; // dx
  UFG::HealthComponent *m_pComponent; // rdi
  UFG::SimComponent *v124; // rax
  int mValue; // esi
  UFG::qArray<unsigned long,0> *v126; // rax
  int *v127; // rax
  UFG::ShowRewardType **v128; // rcx
  int v129; // eax
  UFG::qArray<unsigned long,0> *v130; // rax
  char *v131; // rdi
  UFG::qArray<unsigned long,0> *v132; // rax
  char *v133; // rsi
  unsigned int v134; // eax
  UFG::qArray<unsigned long,0> *v135; // rax
  int *v136; // rax
  int *v137; // rcx
  int v138; // edx
  UFG::qArray<unsigned long,0> *v139; // rax
  char *v140; // rdi
  UFG::qArray<unsigned long,0> *v141; // rax
  char *v142; // rsi
  unsigned int v143; // eax
  UFG::qArray<unsigned long,0> *v144; // rax
  int *v145; // rax
  int *v146; // rcx
  int v147; // edx
  UFG::qArray<unsigned long,0> *v148; // rax
  char *v149; // rdi
  UFG::qArray<unsigned long,0> *v150; // rax
  char *v151; // rsi
  unsigned int v152; // eax
  UFG::qArray<unsigned long,0> *v153; // rax
  int *v154; // rax
  int *v155; // rcx
  int v156; // edx
  UFG::qArray<unsigned long,0> *v157; // rax
  char *v158; // rdi
  UFG::qArray<unsigned long,0> *v159; // rax
  char *v160; // rsi
  unsigned int v161; // eax
  UFG::qArray<unsigned long,0> *v162; // rax
  bool *v163; // rax
  UFG::ShowRewardType **v164; // rcx
  char v165; // cl
  UFG::qArray<unsigned long,0> *v166; // rax
  char *v167; // rdi
  UFG::qArray<unsigned long,0> *v168; // rax
  char *v169; // rsi
  unsigned int v170; // eax
  UFG::qArray<unsigned long,0> *v171; // rax
  bool *v172; // rax
  UFG::ShowRewardType **v173; // rcx
  UFG::qArray<unsigned long,0> *v174; // rax
  bool *v175; // rax
  UFG::ShowRewardType **v176; // rcx
  char v177; // cl
  UFG::qArray<unsigned long,0> *v178; // rax
  char *v179; // rdi
  UFG::qArray<unsigned long,0> *v180; // rax
  char *v181; // rsi
  unsigned int v182; // eax
  UFG::qArray<unsigned long,0> *v183; // rax
  bool *v184; // rax
  UFG::ShowRewardType **v185; // rcx
  UFG::qArray<unsigned long,0> *v186; // rax
  bool *v187; // rax
  UFG::ShowRewardType **v188; // rcx
  char v189; // cl
  UFG::qArray<unsigned long,0> *v190; // rax
  char *v191; // rdi
  UFG::qArray<unsigned long,0> *v192; // rax
  char *v193; // rsi
  unsigned int v194; // eax
  UFG::qArray<unsigned long,0> *v195; // rax
  bool *v196; // rax
  UFG::ShowRewardType **v197; // rcx
  char v198; // cl
  UFG::qArray<unsigned long,0> *v199; // rax
  char *v200; // rdi
  UFG::qArray<unsigned long,0> *v201; // rax
  char *v202; // rsi
  unsigned int v203; // eax
  UFG::qArray<unsigned long,0> *v204; // rax
  bool *v205; // rax
  UFG::ShowRewardType **v206; // rcx
  char v207; // cl
  UFG::qArray<unsigned long,0> *v208; // rax
  char *v209; // rdi
  UFG::qArray<unsigned long,0> *v210; // rax
  char *v211; // rsi
  unsigned int v212; // eax
  UFG::qArray<unsigned long,0> *v213; // rax
  bool *v214; // rax
  UFG::ShowRewardType **v215; // rcx
  char v216; // cl
  UFG::qArray<unsigned long,0> *v217; // rax
  char *v218; // rdi
  UFG::qArray<unsigned long,0> *v219; // rax
  char *v220; // rsi
  unsigned int v221; // eax
  UFG::qArray<unsigned long,0> *v222; // rax
  bool *v223; // rax
  UFG::ShowRewardType **v224; // rcx
  char v225; // cl
  UFG::qArray<unsigned long,0> *v226; // rax
  char *v227; // rdi
  UFG::qArray<unsigned long,0> *v228; // rax
  char *v229; // rsi
  unsigned int v230; // eax
  UFG::qArray<unsigned long,0> *v231; // rax
  UFG::qPropertyList *v232; // rax
  UFG::qPropertyList *v233; // rdi
  unsigned int mNumElements; // esi
  UFG::ShowRewardType v235; // r15d
  char *ValuePtr; // rax
  __int64 v237; // rcx
  UFG::PerkGoalTracker *v238; // rax
  unsigned int NumGoalsSatisfied; // eax
  UFG::CopSystem *v240; // rax
  const char *caption; // [rsp+30h] [rbp-D0h]
  char *captiona; // [rsp+30h] [rbp-D0h]
  bool *captionb; // [rsp+30h] [rbp-D0h]
  char *captionc; // [rsp+30h] [rbp-D0h]
  const char *captiond; // [rsp+30h] [rbp-D0h]
  const char *captione; // [rsp+30h] [rbp-D0h]
  char *captionf; // [rsp+30h] [rbp-D0h]
  UFG::qSymbol gameslice_subtype; // [rsp+38h] [rbp-C8h] BYREF
  UFG::qSymbol gameslice_type; // [rsp+3Ch] [rbp-C4h] BYREF
  UFG::qSymbol symGameSlice[2]; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qSymbol v252[2]; // [rsp+48h] [rbp-B8h] BYREF
  int score; // [rsp+50h] [rbp-B0h]
  unsigned int v254; // [rsp+54h] [rbp-ACh]
  UFG::qSymbol v255[2]; // [rsp+58h] [rbp-A8h] BYREF
  UFG::qString v256; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v257; // [rsp+88h] [rbp-78h]
  UFG::SocialLogData data; // [rsp+90h] [rbp-70h] BYREF
  int v259; // [rsp+150h] [rbp+50h]
  void *mem; // [rsp+158h] [rbp+58h]
  UFG::ShowRewardType showRewardTypea; // [rsp+1B0h] [rbp+B0h] BYREF
  UFG::ShowRewardType *uiscreen_type; // [rsp+1B8h] [rbp+B8h] BYREF
  UFG::SceneObjectProperties *v263; // [rsp+1C0h] [rbp+C0h]
  UFG::ShowRewardType *result; // [rsp+1C8h] [rbp+C8h] BYREF

  v263 = pCollectible;
  showRewardTypea = showRewardType;
  v257 = -2i64;
  v4 = 0;
  v254 = 0;
  v5 = showRewardType == ShowReward;
  LOBYTE(uiscreen_type) = showRewardType == ShowReward;
  if ( !pProperties )
    return 0;
  v6 = UFG::GameStatTracker::Instance();
  UFG::RewardsHandler::mItemUnlocked = 0;
  v7 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "UIScreenType");
  v8 = UFG::qPropertySet::Get<UFG::qSymbol>(pProperties, v7, DEPTH_RECURSE);
  v9 = &UFG::gNullQSymbol;
  v10 = (UFG::ShowRewardType *)&UFG::gNullQSymbol;
  if ( v8 )
    v10 = (UFG::ShowRewardType *)v8;
  v11 = *v10;
  v12 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "GamesliceType");
  v13 = UFG::qPropertySet::Get<UFG::qSymbol>(pProperties, v12, DEPTH_RECURSE);
  v14 = &UFG::gNullQSymbol;
  if ( v13 )
    v14 = v13;
  mUID = v14->mUID;
  v16 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "GamesliceSubType");
  v17 = UFG::qPropertySet::Get<UFG::qSymbol>(pProperties, v16, DEPTH_RECURSE);
  if ( v17 )
    v9 = v17;
  v18 = v9->mUID;
  if ( v5 )
  {
    LOBYTE(result) = 1;
    v19 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(symGameSlice, "ShowRewardScreen");
    v20 = UFG::qPropertySet::Get<bool>(pProperties, v19, DEPTH_RECURSE);
    p_result = &result;
    if ( v20 )
      p_result = (UFG::ShowRewardType **)v20;
    v5 = *(_BYTE *)p_result;
    v22 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(symGameSlice, "CompletionText");
    UFG::qPropertySet::Get<char const *>(pProperties, v22, DEPTH_RECURSE);
    if ( v5 )
    {
      *(_QWORD *)&v252[0].mUID = &gameslice_subtype;
      *(_QWORD *)&v255[0].mUID = &gameslice_type;
      LODWORD(result) = v11;
      gameslice_subtype.mUID = v18;
      gameslice_type.mUID = mUID;
      UFG::RewardsHandler::UISetup((__int64)&gameslice_type, (__int64)&gameslice_subtype, (__int64)&result, pProperties);
      UFG::GameStatAction::Player::ClampAndSetCombatMeter(0.0);
      v5 = (char)uiscreen_type;
    }
    else
    {
      LOBYTE(uiscreen_type) = 0;
      showRewardTypea = DoNotShowReward;
    }
  }
  LODWORD(result) = 0;
  v23 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(symGameSlice, "MoneyAdjustment");
  v24 = UFG::qPropertySet::Get<long>(pProperties, v23, DEPTH_RECURSE);
  v25 = (unsigned int *)&result;
  if ( v24 )
    v25 = (unsigned int *)v24;
  v26 = *v25;
  gameslice_subtype.mUID = v26;
  if ( v26 )
  {
    if ( v5 )
    {
      v27 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                              (UFG::qSymbol *)&result,
                                              "MoneyAdjustmentIcon");
      v28 = UFG::qPropertySet::Get<char const *>(pProperties, v27, DEPTH_RECURSE);
      v29 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&gameslice_type, "MoneyAdjustmentText");
      caption = UFG::qPropertySet::Get<char const *>(pProperties, v29, DEPTH_RECURSE);
      v30 = UFG::qStringHash32(v28, 0xFFFFFFFF);
      symGameSlice[0].mUID = v30;
      if ( caption && *caption )
      {
        LODWORD(result) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(caption, v30, (__int64)&result);
        v26 = gameslice_subtype.mUID;
      }
      else
      {
        LODWORD(result) = v11;
        v26 = gameslice_subtype.mUID;
        mData = UFG::qString::FormatEx(
                  &v256,
                  "<img src=Icon_Reward_Cash height=24 width=24 vspace=-8>HK $%d",
                  gameslice_subtype.mUID)->mData;
        UFG::UIHKScreenMissionComplete::AddReward(mData, symGameSlice[0].mUID, (__int64)&result);
        UFG::qString::~qString(&v256);
      }
      UFG::RewardsHandler::mItemUnlocked = 1;
    }
    v32 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::ApplyMonetaryReward(v32, v26);
    v33 = UFG::OSuiteLeaderboardManager::Instance();
    LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                            v33,
                                            "StatAwardsMogul");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, v26);
    if ( v5 )
    {
      v35 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "Reward");
      UFG::GameStatAction::Money::SendTransactionTelemetry(&pProperties->mName, v35, v26);
    }
  }
  v36 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "UnlockableBioId");
  v37 = UFG::qPropertySet::Get<long>(pProperties, v36, DEPTH_RECURSE);
  if ( v37 )
  {
    LODWORD(result) = *v37;
    v38 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v38 + 6216) & 1) == 0 )
      v38->mpSnapshots[0]->mBools[2].mValue = 1;
    captiona = (char *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, (unsigned int)result);
    v39 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v39 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapBool::SetStatus(v39->mpSnapshots[0]->mpMapBools[22], (UFG::qSymbol *)captiona, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v40 = _S12_6;
        if ( (_S12_6 & 1) == 0 )
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
        if ( (v40 & 1) == 0 )
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
      }
    }
  }
  v43 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                          (UFG::qSymbol *)&result,
                                          "EnableMissionScoring");
  v44 = UFG::qPropertySet::Get<bool>(pProperties, v43, DEPTH_RECURSE);
  if ( v44 && *v44 )
  {
    CopScoreBuffed = UFG::GameStatAction::MissionScoring::GetCopScoreBuffed();
    score = CopScoreBuffed;
    LODWORD(result) = UFG::GameStatAction::MissionScoring::GetTriadScoreBuffed();
    gameslice_subtype.mUID = CopScoreBuffed + (_DWORD)result;
    gameslice_type.mUID = UFG::GameStatAction::MissionScoring::GetTotalScoreUncapped();
    v46 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(symGameSlice, "FixedMissionScoring");
    captionb = UFG::qPropertySet::Get<bool>(pProperties, v46, DEPTH_RECURSE);
    v47 = 1;
    v254 = 1;
    v48 = 1;
    if ( mUID != UFG::qSymbol::create_from_string(v255, "DLC_POLICE")->mUID )
    {
      v47 = 3;
      v254 = 3;
      if ( mUID != UFG::qSymbol::create_from_string(v252, "DLC_TRIAD")->mUID )
        v48 = 0;
    }
    if ( (v47 & 2) != 0 )
    {
      v47 &= ~2u;
      v254 = v47;
    }
    if ( (v47 & 1) != 0 )
      v254 = v47 & 0xFFFFFFFE;
    if ( v48 )
    {
      if ( captionb && *captionb )
      {
        v49 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                (UFG::qSymbol *)&uiscreen_type,
                                                "CopStartingScore");
        CappedScorePerMission = *UFG::qPropertySet::Get<long>(pProperties, v49, DEPTH_RECURSE);
        score = CappedScorePerMission;
        v51 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                (UFG::qSymbol *)&uiscreen_type,
                                                "TriadBaseScore");
        v52 = *UFG::qPropertySet::Get<long>(pProperties, v51, DEPTH_RECURSE);
        LODWORD(result) = v52;
        gameslice_subtype.mUID = v52 + CappedScorePerMission;
        gameslice_type.mUID = v52 + CappedScorePerMission;
        UFG::UIHKScreenMissionComplete::mClearMissionScoreAfter = 0;
        v53 = 0;
        if ( CappedScorePerMission > 0 )
          v53 = 100;
        qword_14243121C = (float)v53;
        v54 = 0;
        if ( v52 > 0 )
          v54 = 100;
        TriadScorePercentage = (float)v54;
      }
      else
      {
        qword_14243121C = UFG::GameStatAction::MissionScoring::GetCopScorePercentage();
        TriadScorePercentage = UFG::GameStatAction::MissionScoring::GetTriadScorePercentage();
        CappedScorePerMission = score;
      }
    }
    else if ( captionb && *captionb )
    {
      v56 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                              (UFG::qSymbol *)&uiscreen_type,
                                              "CopStartingScore");
      CappedScorePerMission = *UFG::qPropertySet::Get<long>(pProperties, v56, DEPTH_RECURSE);
      score = CappedScorePerMission;
      v57 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                              (UFG::qSymbol *)&uiscreen_type,
                                              "TriadBaseScore");
      v58 = *UFG::qPropertySet::Get<long>(pProperties, v57, DEPTH_RECURSE);
      LODWORD(result) = v58;
      gameslice_subtype.mUID = v58 + CappedScorePerMission;
      gameslice_type.mUID = v58 + CappedScorePerMission;
      UFG::UIHKScreenMissionComplete::mClearMissionScoreAfter = 1;
      v59 = 0;
      if ( CappedScorePerMission > 0 )
        v59 = 100;
      qword_14243121C = (float)v59;
      v60 = 0;
      if ( v58 > 0 )
        v60 = 100;
      TriadScorePercentage = (float)v60;
    }
    else
    {
      UFG::UIHKScreenMissionComplete::mClearMissionScoreAfter = 1;
      mpActiveMaster = UFG::ProgressionTracker::Instance()->mpActiveMaster;
      captionc = (char *)mpActiveMaster;
      if ( mpActiveMaster )
      {
        mText = mpActiveMaster->mName.mText;
        v63 = UFG::OSuiteLeaderboardManager::Instance();
        LeaderboardDataUsingSliceName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingSliceName(v63, mText);
        *(_QWORD *)&v252[0].mUID = LeaderboardDataUsingSliceName;
        if ( LeaderboardDataUsingSliceName )
        {
          v65 = UFG::GameStatTracker::Instance();
          Stat = UFG::GameStatTracker::GetStat(
                   v65,
                   LeaderboardScoreIntList,
                   &LeaderboardDataUsingSliceName->mLeaderboardName);
          v67 = gameslice_type.mUID;
          if ( Stat < (int)gameslice_type.mUID )
          {
            v68 = UFG::OSuiteLeaderboardManager::Instance();
            UFG::OSuiteLeaderboardManager::UploadMissionResult(
              v68,
              (UFG::allocator::free_link *)LeaderboardDataUsingSliceName,
              gameslice_type.mUID,
              (UFG::allocator::free_link *)UFG::DataSynchronizer::UpdateLeaderboardCallback);
            v69 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(
              v69,
              LeaderboardDirtyScoreBoolList,
              &LeaderboardDataUsingSliceName->mLeaderboardName,
              1);
            v70 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(
              v70,
              LeaderboardScoreIntList,
              &LeaderboardDataUsingSliceName->mLeaderboardName,
              gameslice_type.mUID);
            mLeaderboardId = LeaderboardDataUsingSliceName->mLeaderboardId;
            v72 = UFG::OnlineUtil::CurrentTimeMillis();
            UFG::SocialLogData::SocialLogData(&data);
            data.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable;
            v259 = 0;
            mem = 0i64;
            data.m_iCommId = CommId_NewHighScore;
            data.m_iTimeStamp = v72;
            data.m_iLeaderboardId = mLeaderboardId;
            data.m_iScore = gameslice_type.mUID;
            v73 = UFG::SocialLogDataManager::Instance();
            UFG::SocialLogDataManager::AddToSaveData(v73, &data);
            UFG::UIHKScreenMissionComplete::sIsHighscore = 1;
            data.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable;
            if ( mem )
              operator delete[](mem);
            UFG::SocialLogData::~SocialLogData(&data);
            mpActiveMaster = (UFG::GameSlice *)captionc;
            LeaderboardDataUsingSliceName = *(UFG::OSuiteLeaderboardData **)&v252[0].mUID;
            v67 = gameslice_type.mUID;
          }
          if ( lastGameSlice != mpActiveMaster )
          {
            UFG::DataSynchronizer::SendBeatChallengeMessageIfNeeded(LeaderboardDataUsingSliceName, v67, 0);
            lastGameSlice = mpActiveMaster;
          }
        }
        symGameSlice[0] = (UFG::qSymbol)mpActiveMaster->mNode.mUID;
        CappedScorePerMission = UFG::RewardsHandler::GetCappedScorePerMission(score, CopScore, symGameSlice);
        score = CappedScorePerMission;
        symGameSlice[0] = (UFG::qSymbol)mpActiveMaster->mNode.mUID;
        LODWORD(result) = UFG::RewardsHandler::GetCappedScorePerMission((int)result, TriadScore, symGameSlice);
      }
      else
      {
        CappedScorePerMission = score;
      }
      qword_14243121C = UFG::GameStatAction::MissionScoring::GetCopScorePercentage();
      TriadScorePercentage = UFG::GameStatAction::MissionScoring::GetTriadScorePercentage();
      v5 = (char)uiscreen_type;
    }
    *(float *)&qword_142431CEC = TriadScorePercentage;
    UFG::UIHKScreenMissionComplete::AddPoliceScore(CappedScorePerMission);
    UFG::UIHKScreenMissionComplete::AddTriadScore((int)result);
    UFG::UIHKScreenMissionComplete::AddMissionScore(gameslice_subtype.mUID);
    UFG::UIHKScreenMissionComplete::AddUncappedMissionScore(gameslice_type.mUID);
    if ( v5 )
    {
      v74 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                              (UFG::qSymbol *)&uiscreen_type,
                                              "CopXPIcon");
      v75 = PropertyUtils::Get<char const *>(pProperties, v74, DEPTH_RECURSE);
      v76 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "CopXPText");
      captiond = PropertyUtils::Get<char const *>(pProperties, v76, DEPTH_RECURSE);
      v77 = UFG::qStringHash32(v75, 0xFFFFFFFF);
      if ( captiond && *captiond )
        UFG::UIHKScreenMissionComplete::AddPoliceReward(captiond, v77);
      CappedScorePerMission = score;
      *((float *)&qword_142431204 + 1) = *((float *)&qword_142431204 + 1) + (float)score;
      UFG::RewardsHandler::mItemUnlocked = 1;
    }
    gameslice_subtype.mUID = v6->mpSnapshots[0]->mInts[30].mValue;
    LODWORD(uiscreen_type) = gameslice_subtype.mUID + CappedScorePerMission;
    XPLevel = UFG::GameStatTracker::GetXPLevel(v6, ThresholdType_Cop, gameslice_subtype.mUID);
    symGameSlice[0].mUID = UFG::GameStatTracker::GetXPLevel(v6, ThresholdType_Cop, (int)uiscreen_type);
    if ( symGameSlice[0].mUID != XPLevel )
    {
      UFG::GameStatTracker::ApplyDelta(v6, CopUpgradePoint, symGameSlice[0].mUID - XPLevel);
      if ( (int)symGameSlice[0].mUID >= 10 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(30);
    }
    *(float *)&qword_142431204 = (float)(int)gameslice_subtype.mUID;
    v79 = score;
    *((float *)&qword_142431204 + 1) = (float)score;
    *(float *)&qword_142431214 = (float)(int)UFG::GameStatTracker::GetPercentageToNextXPLevel(
                                               v6,
                                               ThresholdType_Cop,
                                               gameslice_subtype.mUID);
    if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
    {
      v6->mpSnapshots[0]->mInts[30].mValue += v79;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( (_S12_6 & 1) != 0 )
        {
          v80 = &sGameStatTracker;
        }
        else
        {
          _S12_6 |= 1u;
          v80 = &sGameStatTracker;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        if ( UFG::GameStatTracker::mspInstance )
          v80 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v80;
      }
    }
    *((float *)&qword_142431214 + 1) = (float)(int)UFG::GameStatTracker::GetPercentageToNextXPLevel(
                                                     v6,
                                                     ThresholdType_Cop,
                                                     (int)uiscreen_type);
    *(&qword_14243121C + 1) = *(float *)v6->mMaxXPThresholdLevels;
    if ( v5 )
    {
      v81 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                              (UFG::qSymbol *)&uiscreen_type,
                                              "TriadXPIcon");
      v82 = PropertyUtils::Get<char const *>(pProperties, v81, DEPTH_RECURSE);
      v83 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "TriadXPText");
      captione = PropertyUtils::Get<char const *>(pProperties, v83, DEPTH_RECURSE);
      v84 = UFG::qStringHash32(v82, 0xFFFFFFFF);
      if ( captione && *captione )
      {
        UFG::UIHKScreenMissionComplete::AddTriadReward(captione, v84);
      }
      else
      {
        v85 = UFG::qString::FormatEx(&v256, " $%d rewarded", (unsigned int)result);
        UFG::UIHKScreenMissionComplete::AddTriadReward(v85->mData, v84);
        UFG::qString::~qString(&v256);
      }
      *((float *)&qword_142431CD4 + 1) = *((float *)&qword_142431CD4 + 1) + (float)(int)result;
      UFG::RewardsHandler::mItemUnlocked = 1;
    }
    gameslice_subtype.mUID = v6->mpSnapshots[0]->mInts[31].mValue;
    LODWORD(uiscreen_type) = gameslice_subtype.mUID + (_DWORD)result;
    v86 = UFG::GameStatTracker::GetXPLevel(v6, ThresholdType_Triad, gameslice_subtype.mUID);
    symGameSlice[0].mUID = UFG::GameStatTracker::GetXPLevel(v6, ThresholdType_Triad, (int)uiscreen_type);
    if ( symGameSlice[0].mUID != v86 )
    {
      UFG::GameStatTracker::ApplyDelta(v6, TriadUpgradePoint, symGameSlice[0].mUID - v86);
      if ( (int)symGameSlice[0].mUID >= 10 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(29);
    }
    *(float *)&qword_142431CD4 = (float)(int)gameslice_subtype.mUID;
    v87 = (int)result;
    *((float *)&qword_142431CD4 + 1) = (float)(int)result;
    *(float *)&qword_142431CE4 = (float)(int)UFG::GameStatTracker::GetPercentageToNextXPLevel(
                                               v6,
                                               ThresholdType_Triad,
                                               gameslice_subtype.mUID);
    UFG::GameStatTracker::ApplyDelta(v6, TriadXP, v87);
    *((float *)&qword_142431CE4 + 1) = (float)(int)UFG::GameStatTracker::GetPercentageToNextXPLevel(
                                                     v6,
                                                     ThresholdType_Triad,
                                                     (int)uiscreen_type);
    HIDWORD(qword_142431CEC) = v6->mMaxXPThresholdLevels[1];
  }
  else
  {
    UFG::UIHKScreenMissionComplete::mClearMissionScoreAfter = 0;
  }
  if ( UFG::ProgressionTracker::Instance()->mModeType != ModeType_Challenge || mUID == qSymbol_Race_14.mUID )
  {
    LODWORD(uiscreen_type) = 0;
    v88 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                            (UFG::qSymbol *)&result,
                                            "StandingAdjustment");
    v89 = UFG::qPropertySet::Get<long>(pProperties, v88, DEPTH_RECURSE);
    p_uiscreen_type = &uiscreen_type;
    if ( v89 )
      p_uiscreen_type = (UFG::ShowRewardType **)v89;
    v91 = *(_DWORD *)p_uiscreen_type;
    LODWORD(uiscreen_type) = v91;
    if ( v91 )
    {
      if ( v5 )
      {
        v92 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                (UFG::qSymbol *)&result,
                                                "StandingAdjustmentIcon");
        v93 = PropertyUtils::Get<char const *>(pProperties, v92, DEPTH_RECURSE);
        v94 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "StandingAdjustmentText");
        v95 = PropertyUtils::Get<char const *>(pProperties, v94, DEPTH_RECURSE);
        v96 = UFG::qStringHash32(v93, 0xFFFFFFFF);
        UFG::UIHKScreenMissionComplete::AddFaceReward(v95, v96);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v91 = (int)uiscreen_type;
      }
      v97 = (int)(float)(UFG::PlayerBuffTracker::GetFaceXPBonusPercent() * (float)v91) + v91;
      *(float *)&qword_1424332D4 = (float)v6->mpSnapshots[0]->mInts[29].mValue;
      *((float *)&qword_1424332D4 + 1) = (float)v97;
      *(float *)&qword_1424332E4 = (float)(int)UFG::GameStatTracker::GetPercentageToNextLevel(v6, Standing);
      UFG::GameStatTracker::ApplyDelta(v6, Standing, v97);
      *((float *)&qword_1424332E4 + 1) = (float)(int)UFG::GameStatTracker::GetPercentageToNextLevel(v6, Standing);
      HIDWORD(qword_1424332EC) = v6->m_iMaxFaceLevel;
    }
    LODWORD(uiscreen_type) = 0;
    v98 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "MinimumStanding");
    v99 = UFG::qPropertySet::Get<long>(pProperties, v98, DEPTH_RECURSE);
    v100 = (int *)&uiscreen_type;
    if ( v99 )
      v100 = v99;
    v101 = *v100;
    if ( *v100 && (float)v101 > (float)v6->mpSnapshots[0]->mInts[29].mValue )
      UFG::GameStatTracker::SetStat(v6, Standing, v101);
  }
  if ( UFG::ProgressionTracker::Instance()->mModeType != ModeType_Challenge )
  {
    v102 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                             (UFG::qSymbol *)&uiscreen_type,
                                             "UnlockAchievement");
    v103 = UFG::qPropertySet::Get<UFG::qSymbol>(pProperties, v102, DEPTH_RECURSE);
    if ( v103 )
    {
      v104 = UFG::HKAchievementTrophyManager::mapAchievmentStringToID(v103->mUID);
      if ( v104 == 21 )
      {
        v105 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&uiscreen_type, "S_HJ");
        v106 = UFG::ProgressionTracker::Instance();
        v107 = UFG::ProgressionTracker::Find(v106, v105, 0);
        if ( v107 && SWORD2(v107[5].mRoot.mParent) >= 5 )
        {
          v108 = 21;
LABEL_134:
          UFG::AchievementTrophyManager::UnlockAchievementTrophy(v108);
        }
      }
      else if ( v104 == 27 )
      {
        v109 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&uiscreen_type, "F_FC1");
        v110 = UFG::ProgressionTracker::Instance();
        captionf = (char *)UFG::ProgressionTracker::Find(v110, v109, 0);
        v111 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "F_FC2");
        v112 = UFG::ProgressionTracker::Instance();
        v113 = UFG::ProgressionTracker::Find(v112, v111, 0);
        v114 = UFG::qSymbol::create_from_string(v252, "F_FC3");
        v115 = UFG::ProgressionTracker::Instance();
        *(_QWORD *)&symGameSlice[0].mUID = UFG::ProgressionTracker::Find(v115, v114, 0);
        v116 = UFG::qSymbol::create_from_string(v255, "F_FC4");
        v117 = UFG::ProgressionTracker::Instance();
        v118 = UFG::ProgressionTracker::Find(v117, v116, 0);
        if ( captionf
          && *((__int16 *)captionf + 182) > 0
          && v113
          && SWORD2(v113[5].mRoot.mParent) > 0
          && *(_QWORD *)&symGameSlice[0].mUID
          && *(__int16 *)(*(_QWORD *)&symGameSlice[0].mUID + 364i64) > 0
          && v118
          && SWORD2(v118[5].mRoot.mParent) > 0 )
        {
          v108 = 27;
          goto LABEL_134;
        }
      }
      else if ( v104 > 0 )
      {
        v108 = v104;
        goto LABEL_134;
      }
    }
    v119 = UFG::qPropertySet::Get<long>(
             pProperties,
             (UFG::qArray<unsigned long,0> *)&UFG::GameStat::Symbol_MaxHealthUpgradePoint,
             DEPTH_RECURSE);
    result = (UFG::ShowRewardType *)v119;
    if ( v119 )
    {
      if ( *v119 > 0 )
      {
        v120 = UFG::GameStatTracker::Instance();
        LODWORD(uiscreen_type) = (unsigned int)UFG::GameStatTracker::GetNumHealthShrinesCollected(v120) % 5;
        LocalPlayer = UFG::GetLocalPlayer();
        if ( LocalPlayer )
        {
          m_Flags = LocalPlayer->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = (UFG::HealthComponent *)LocalPlayer->m_Components.p[6].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            v124 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::HealthComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::HealthComponent::_TypeUID);
            m_pComponent = (UFG::HealthComponent *)v124;
          }
          else
          {
            m_pComponent = (UFG::HealthComponent *)LocalPlayer->m_Components.p[6].m_pComponent;
          }
          if ( m_pComponent )
          {
            mValue = (int)v6->mpSnapshots[0]->mFloats[40].mValue;
            if ( !(_DWORD)uiscreen_type )
            {
              mValue += *result + 4 * *result;
              UFG::GameStatTracker::SetStat(v6, MaxHealth, (float)mValue);
              UFG::HealthComponent::SetMaxHealth(m_pComponent, mValue);
              UFG::HudAudio::PlayHudSound(0x1ED74491u, 0i64);
            }
            UFG::HealthComponent::SetHealth(m_pComponent, mValue, 0i64);
          }
        }
      }
    }
    LODWORD(uiscreen_type) = 0;
    v126 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                             (UFG::qSymbol *)&result,
                                             "MaxHealthAdjustment");
    v127 = UFG::qPropertySet::Get<long>(pProperties, v126, DEPTH_RECURSE);
    v128 = &uiscreen_type;
    if ( v127 )
      v128 = (UFG::ShowRewardType **)v127;
    v129 = *(_DWORD *)v128;
    LODWORD(result) = v129;
    if ( v129 )
    {
      if ( v5 )
      {
        v130 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 (UFG::qSymbol *)&uiscreen_type,
                                                 "MaxHealthAdjustmentIcon");
        v131 = PropertyUtils::Get<char const *>(pProperties, v130, DEPTH_RECURSE);
        v132 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "MaxHealthAdjustmentText");
        v133 = PropertyUtils::Get<char const *>(pProperties, v132, DEPTH_RECURSE);
        v134 = UFG::qStringHash32(v131, 0xFFFFFFFF);
        LODWORD(uiscreen_type) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v133, v134, (__int64)&uiscreen_type);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v129 = (int)result;
      }
      UFG::GameStatTracker::ApplyDelta(v6, MaxHealth, (float)v129);
    }
    LODWORD(uiscreen_type) = 0;
    v135 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                             (UFG::qSymbol *)&result,
                                             "StatueDefensiveStage");
    v136 = UFG::qPropertySet::Get<long>(pProperties, v135, DEPTH_RECURSE);
    v137 = (int *)&uiscreen_type;
    if ( v136 )
      v137 = v136;
    v138 = *v137;
    LODWORD(result) = v138;
    if ( v138 )
    {
      if ( v5 )
      {
        v139 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 (UFG::qSymbol *)&uiscreen_type,
                                                 "TriadStageIcon");
        v140 = PropertyUtils::Get<char const *>(pProperties, v139, DEPTH_RECURSE);
        v141 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "TriadStageText");
        v142 = PropertyUtils::Get<char const *>(pProperties, v141, DEPTH_RECURSE);
        v143 = UFG::qStringHash32(v140, 0xFFFFFFFF);
        LODWORD(uiscreen_type) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v142, v143, (__int64)&uiscreen_type);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v138 = (int)result;
      }
      if ( v6->mpSnapshots[0]->mInts[22].mValue > v138 )
        v138 = v6->mpSnapshots[0]->mInts[22].mValue;
      UFG::GameStatTracker::SetStat(v6, StatueDefensiveStage, v138);
    }
    LODWORD(uiscreen_type) = 0;
    v144 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                             (UFG::qSymbol *)&result,
                                             "StatueOffensiveStage");
    v145 = UFG::qPropertySet::Get<long>(pProperties, v144, DEPTH_RECURSE);
    v146 = (int *)&uiscreen_type;
    if ( v145 )
      v146 = v145;
    v147 = *v146;
    LODWORD(result) = v147;
    if ( v147 )
    {
      if ( v5 )
      {
        v148 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 (UFG::qSymbol *)&uiscreen_type,
                                                 "TriadStageIcon");
        v149 = PropertyUtils::Get<char const *>(pProperties, v148, DEPTH_RECURSE);
        v150 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "TriadStageText");
        v151 = PropertyUtils::Get<char const *>(pProperties, v150, DEPTH_RECURSE);
        v152 = UFG::qStringHash32(v149, 0xFFFFFFFF);
        LODWORD(uiscreen_type) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v151, v152, (__int64)&uiscreen_type);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v147 = (int)result;
      }
      if ( v6->mpSnapshots[0]->mInts[23].mValue > v147 )
        v147 = v6->mpSnapshots[0]->mInts[23].mValue;
      UFG::GameStatTracker::SetStat(v6, StatueOffensiveStage, v147);
    }
    LODWORD(uiscreen_type) = 0;
    v153 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                             (UFG::qSymbol *)&result,
                                             "GunplayUpgradeStage");
    v154 = UFG::qPropertySet::Get<long>(pProperties, v153, DEPTH_RECURSE);
    v155 = (int *)&uiscreen_type;
    if ( v154 )
      v155 = v154;
    v156 = *v155;
    LODWORD(result) = v156;
    if ( v156 )
    {
      if ( v5 )
      {
        v157 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 (UFG::qSymbol *)&uiscreen_type,
                                                 "CopStageIcon");
        v158 = PropertyUtils::Get<char const *>(pProperties, v157, DEPTH_RECURSE);
        v159 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "CopStageText");
        v160 = PropertyUtils::Get<char const *>(pProperties, v159, DEPTH_RECURSE);
        v161 = UFG::qStringHash32(v158, 0xFFFFFFFF);
        LODWORD(uiscreen_type) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v160, v161, (__int64)&uiscreen_type);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v156 = (int)result;
      }
      if ( v6->mpSnapshots[0]->mInts[26].mValue > v156 )
        v156 = v6->mpSnapshots[0]->mInts[26].mValue;
      UFG::GameStatTracker::SetStat(v6, GunplayUpgradeStage, v156);
    }
    LOBYTE(uiscreen_type) = 0;
    v162 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "EnablePDA");
    v163 = UFG::qPropertySet::Get<bool>(pProperties, v162, DEPTH_RECURSE);
    v164 = &uiscreen_type;
    if ( v163 )
      v164 = (UFG::ShowRewardType **)v163;
    v165 = *(_BYTE *)v164;
    LOBYTE(uiscreen_type) = v165;
    if ( v165 )
    {
      if ( v5 )
      {
        v166 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 (UFG::qSymbol *)&result,
                                                 "EnablePDAIcon");
        v167 = PropertyUtils::Get<char const *>(pProperties, v166, DEPTH_RECURSE);
        v168 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "EnablePDAText");
        v169 = PropertyUtils::Get<char const *>(pProperties, v168, DEPTH_RECURSE);
        v170 = UFG::qStringHash32(v167, 0xFFFFFFFF);
        LODWORD(result) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v169, v170, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v165 = (char)uiscreen_type;
      }
      if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
        v6->mpSnapshots[0]->mBools[4].mValue = v165;
    }
    LOBYTE(uiscreen_type) = 0;
    v171 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "EnableValet");
    v172 = UFG::qPropertySet::Get<bool>(pProperties, v171, DEPTH_RECURSE);
    v173 = &uiscreen_type;
    if ( v172 )
      v173 = (UFG::ShowRewardType **)v172;
    if ( *(_BYTE *)v173 && (*((_BYTE *)v6 + 6216) & 1) == 0 )
      v6->mpSnapshots[0]->mBools[5].mValue = *(_BYTE *)v173;
    LOBYTE(uiscreen_type) = 0;
    v174 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "EnableSpyCams");
    v175 = UFG::qPropertySet::Get<bool>(pProperties, v174, DEPTH_RECURSE);
    v176 = &uiscreen_type;
    if ( v175 )
      v176 = (UFG::ShowRewardType **)v175;
    v177 = *(_BYTE *)v176;
    LOBYTE(uiscreen_type) = v177;
    if ( v177 )
    {
      if ( v5 )
      {
        v178 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 (UFG::qSymbol *)&result,
                                                 "EnableSpyCamsIcon");
        v179 = PropertyUtils::Get<char const *>(pProperties, v178, DEPTH_RECURSE);
        v180 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "EnableSpyCamsText");
        v181 = PropertyUtils::Get<char const *>(pProperties, v180, DEPTH_RECURSE);
        v182 = UFG::qStringHash32(v179, 0xFFFFFFFF);
        LODWORD(result) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v181, v182, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v177 = (char)uiscreen_type;
      }
      if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
        v6->mpSnapshots[0]->mBools[3].mValue = v177;
    }
    LOBYTE(uiscreen_type) = 0;
    v183 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "EnableKaraoke");
    v184 = UFG::qPropertySet::Get<bool>(pProperties, v183, DEPTH_RECURSE);
    v185 = &uiscreen_type;
    if ( v184 )
      v185 = (UFG::ShowRewardType **)v184;
    if ( *(_BYTE *)v185 && (*((_BYTE *)v6 + 6216) & 1) == 0 )
      v6->mpSnapshots[0]->mBools[32].mValue = *(_BYTE *)v185;
    LOBYTE(uiscreen_type) = 0;
    v186 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                             (UFG::qSymbol *)&result,
                                             "EnableHealthShrineIndicators");
    v187 = UFG::qPropertySet::Get<bool>(pProperties, v186, DEPTH_RECURSE);
    v188 = &uiscreen_type;
    if ( v187 )
      v188 = (UFG::ShowRewardType **)v187;
    v189 = *(_BYTE *)v188;
    LOBYTE(uiscreen_type) = v189;
    if ( v189 )
    {
      if ( v5 )
      {
        v190 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 (UFG::qSymbol *)&result,
                                                 "EnableHealthShrineIndicatorsIcon");
        v191 = UFG::qPropertySet::Get<char const *>(pProperties, v190, DEPTH_RECURSE);
        v192 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 v252,
                                                 "EnableHealthShrineIndicatorsText");
        v193 = UFG::qPropertySet::Get<char const *>(pProperties, v192, DEPTH_RECURSE);
        v194 = UFG::qStringHash32(v191, 0xFFFFFFFF);
        LODWORD(result) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v193, v194, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v189 = (char)uiscreen_type;
      }
      if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
        v6->mpSnapshots[0]->mBools[6].mValue = v189;
    }
    LOBYTE(uiscreen_type) = 0;
    v195 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                             (UFG::qSymbol *)&result,
                                             "EnableSpyCamIndicators");
    v196 = UFG::qPropertySet::Get<bool>(pProperties, v195, DEPTH_RECURSE);
    v197 = &uiscreen_type;
    if ( v196 )
      v197 = (UFG::ShowRewardType **)v196;
    v198 = *(_BYTE *)v197;
    LOBYTE(uiscreen_type) = v198;
    if ( v198 )
    {
      if ( v5 )
      {
        v199 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 (UFG::qSymbol *)&result,
                                                 "EnableSpyCamIndicatorsIcon");
        v200 = UFG::qPropertySet::Get<char const *>(pProperties, v199, DEPTH_RECURSE);
        v201 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "EnableSpyCamIndicatorsText");
        v202 = UFG::qPropertySet::Get<char const *>(pProperties, v201, DEPTH_RECURSE);
        v203 = UFG::qStringHash32(v200, 0xFFFFFFFF);
        LODWORD(result) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v202, v203, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v198 = (char)uiscreen_type;
      }
      if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
        v6->mpSnapshots[0]->mBools[8].mValue = v198;
    }
    LOBYTE(uiscreen_type) = 0;
    v204 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                             (UFG::qSymbol *)&result,
                                             "EnableLockboxIndicators");
    v205 = UFG::qPropertySet::Get<bool>(pProperties, v204, DEPTH_RECURSE);
    v206 = &uiscreen_type;
    if ( v205 )
      v206 = (UFG::ShowRewardType **)v205;
    v207 = *(_BYTE *)v206;
    LOBYTE(uiscreen_type) = v207;
    if ( v207 )
    {
      if ( v5 )
      {
        v208 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 (UFG::qSymbol *)&result,
                                                 "EnableLockboxIndicatorsIcon");
        v209 = PropertyUtils::Get<char const *>(pProperties, v208, DEPTH_RECURSE);
        v210 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "EnableLockboxIndicatorsText");
        v211 = PropertyUtils::Get<char const *>(pProperties, v210, DEPTH_RECURSE);
        v212 = UFG::qStringHash32(v209, 0xFFFFFFFF);
        LODWORD(result) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v211, v212, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v207 = (char)uiscreen_type;
      }
      if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
        v6->mpSnapshots[0]->mBools[7].mValue = v207;
    }
    LOBYTE(uiscreen_type) = 0;
    v213 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                             (UFG::qSymbol *)&result,
                                             "EnableJumpIndicators");
    v214 = UFG::qPropertySet::Get<bool>(pProperties, v213, DEPTH_RECURSE);
    v215 = &uiscreen_type;
    if ( v214 )
      v215 = (UFG::ShowRewardType **)v214;
    v216 = *(_BYTE *)v215;
    LOBYTE(uiscreen_type) = v216;
    if ( v216 )
    {
      if ( v5 )
      {
        v217 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 (UFG::qSymbol *)&result,
                                                 "EnableJumpIndicatorsIcon");
        v218 = PropertyUtils::Get<char const *>(pProperties, v217, DEPTH_RECURSE);
        v219 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "EnableJumpIndicatorsText");
        v220 = PropertyUtils::Get<char const *>(pProperties, v219, DEPTH_RECURSE);
        v221 = UFG::qStringHash32(v218, 0xFFFFFFFF);
        LODWORD(result) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v220, v221, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v216 = (char)uiscreen_type;
      }
      if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
        v6->mpSnapshots[0]->mBools[10].mValue = v216;
    }
    LOBYTE(uiscreen_type) = 0;
    v222 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                             (UFG::qSymbol *)&result,
                                             "EnableJadeStatueIndicators");
    v223 = UFG::qPropertySet::Get<bool>(pProperties, v222, DEPTH_RECURSE);
    v224 = &uiscreen_type;
    if ( v223 )
      v224 = (UFG::ShowRewardType **)v223;
    v225 = *(_BYTE *)v224;
    LOBYTE(uiscreen_type) = v225;
    if ( v225 )
    {
      if ( v5 )
      {
        v226 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                 (UFG::qSymbol *)&result,
                                                 "EnableJadeStatueIndicatorsIcon");
        v227 = PropertyUtils::Get<char const *>(pProperties, v226, DEPTH_RECURSE);
        v228 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v252, "EnableJadeStatueIndicatorsText");
        v229 = PropertyUtils::Get<char const *>(pProperties, v228, DEPTH_RECURSE);
        v230 = UFG::qStringHash32(v227, 0xFFFFFFFF);
        LODWORD(result) = v11;
        UFG::UIHKScreenMissionComplete::AddReward(v229, v230, (__int64)&result);
        UFG::RewardsHandler::mItemUnlocked = 1;
        v225 = (char)uiscreen_type;
      }
      if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
        v6->mpSnapshots[0]->mBools[9].mValue = v225;
    }
    v231 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                             (UFG::qSymbol *)&uiscreen_type,
                                             "UnlockItems");
    v232 = UFG::qPropertySet::Get<UFG::qPropertyList>(pProperties, v231, DEPTH_RECURSE);
    v233 = v232;
    if ( v232 )
    {
      mNumElements = v232->mNumElements;
      if ( mNumElements )
      {
        v235 = showRewardTypea;
        do
        {
          ValuePtr = UFG::qPropertyList::GetValuePtr(v233, 0x1Au, v4);
          if ( ValuePtr )
          {
            v237 = *(_QWORD *)ValuePtr;
            if ( *(_QWORD *)ValuePtr )
            {
              if ( &ValuePtr[v237] )
              {
                result = &showRewardTypea;
                showRewardTypea = v11;
                UFG::RewardsHandler::HandleRewardList(
                  v235,
                  (UFG::qPropertySet *)&ValuePtr[v237],
                  (unsigned int *)&showRewardTypea);
              }
            }
          }
          ++v4;
        }
        while ( v4 < mNumElements );
      }
    }
  }
  if ( v5 )
  {
    v238 = UFG::PerkGoalTracker::Instance();
    NumGoalsSatisfied = UFG::PerkGoalTracker::GetNumGoalsSatisfied(v238);
    if ( NumGoalsSatisfied )
    {
      UFG::qString::qString(&v256, "%d Perk Goals Succeeded", NumGoalsSatisfied);
      uiscreen_type = &showRewardTypea;
      showRewardTypea = v11;
      UFG::UIHKScreenMissionComplete::AddReward(v256.mData, UFG::gRewardIcon_CopJob, (__int64)&showRewardTypea);
      UFG::RewardsHandler::mItemUnlocked = 1;
      UFG::qString::~qString(&v256);
    }
  }
  if ( UFG::RewardsHandler::mItemUnlocked )
  {
    uiscreen_type = &showRewardTypea;
    showRewardTypea = v11;
  }
  if ( v5 )
  {
    if ( v11 == qSymbol_UIMissionComplete.mUID )
    {
      v240 = UFG::CopSystem::Instance();
      ((void (__fastcall *)(UFG::CopSystem *, _QWORD, _QWORD))v240->vfptr[88].__vecDelDtor)(v240, 0i64, 0i64);
    }
  }
  return 1;
}             UFG::RewardsHandler::HandleRewardList(
                  v235,
                  (UFG::qPropertySet *)&ValuePtr

// File Line: 849
// RVA: 0x4C2F20
void __fastcall UFG::RewardsHandler::UISetup(
        __int64 gameslice_type,
        unsigned int *gameslice_subtype,
        _DWORD *screen_type,
        UFG::qPropertySet *pReward)
{
  UFG::qArray<unsigned long,0> *v6; // rax
  bool *v7; // rax
  UFG::qSymbol *p_gamesliceSubType; // rcx
  char mUID; // r9
  unsigned int TrueCount; // r12d
  unsigned int size; // esi
  const char *v12; // rdi
  unsigned int v13; // ebx
  __int64 MapBoolStatEnum; // r15
  UFG::PersistentData::MapBool *v15; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *v16; // r15
  UFG::GameStatTracker *v17; // rax
  int v18; // ebx
  const char *v19; // rax
  char *v20; // rbx
  UFG::qArray<unsigned long,0> *v21; // r8
  UFG::qPropertySet *PropertySet; // rdi
  UFG::qArray<unsigned long,0> *v23; // rax
  UFG::qPropertyList *v24; // rax
  char *ValuePtr; // rax
  UFG::qPropertySet *v26; // rbx
  UFG::qArray<unsigned long,0> *v27; // rax
  const char *v28; // rax
  const char *v29; // rax
  const char *v30; // rax
  const char *v31; // rdx
  const char *v32; // rax
  const char *v33; // rbx
  UFG::UIHKInfoPopupWidget *v34; // rax
  UFG::qSymbol gamesliceType; // [rsp+8h] [rbp-59h] BYREF
  UFG::qSymbol result[2]; // [rsp+10h] [rbp-51h] BYREF
  UFG::qSymbol v37[2]; // [rsp+18h] [rbp-49h] BYREF
  UFG::qString depth; // [rsp+20h] [rbp-41h] BYREF
  __int64 v39; // [rsp+48h] [rbp-19h]
  UFG::qSymbol *v40; // [rsp+50h] [rbp-11h]
  UFG::qString v41; // [rsp+58h] [rbp-9h] BYREF
  UFG::qSymbol gamesliceSubType; // [rsp+C8h] [rbp+67h] BYREF
  UFG::SceneObjectProperties *retaddr; // [rsp+D8h] [rbp+77h]
  char *caption; // [rsp+E0h] [rbp+7Fh]

  v39 = -2i64;
  if ( *screen_type == qSymbol_UIMissionComplete.mUID )
  {
    LOBYTE(gamesliceSubType.mUID) = 0;
    v6 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(result, "ShowExperienceTutorial");
    v7 = UFG::qPropertySet::Get<bool>(pReward, v6, DEPTH_RECURSE);
    p_gamesliceSubType = &gamesliceSubType;
    if ( v7 )
      p_gamesliceSubType = (UFG::qSymbol *)v7;
    mUID = p_gamesliceSubType->mUID;
    *(_QWORD *)&v37[0].mUID = &gamesliceSubType;
    *(_QWORD *)&result[0].mUID = &gamesliceType;
    gamesliceSubType.mUID = *gameslice_subtype;
    UFG::UIHKScreenMissionComplete::Activate((__int64)&gamesliceType, (__int64)&gamesliceSubType, caption, mUID);
    UFG::RewardsHandler::mItemUnlocked = 1;
  }
  else if ( *screen_type == qSymbol_UIHintText.mUID && retaddr )
  {
    TrueCount = 0;
    size = 0;
    v12 = &customCaption;
    gamesliceSubType.mUID = qSymbol_none_14.mUID;
    PropertyUtils::GetWithDefault<UFG::qSymbol>(
      result,
      retaddr,
      (UFG::qArray<unsigned long,0> *)&SimSym_CollectibleType,
      &gamesliceType.mUID,
      DEPTH_RECURSE);
    v13 = result[0].mUID;
    if ( result[0].mUID != -1 )
    {
      MapBoolStatEnum = (int)UFG::GameStat::GetMapBoolStatEnum(result, 1);
      v15 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[MapBoolStatEnum];
      TrueCount = UFG::PersistentData::MapBool::GetTrueCount(v15);
      if ( v15->mKeepType )
      {
        if ( (unsigned int)(v15->mKeepType - 1) > 1 )
          size = 0;
        else
          size = v15->mNames.size;
      }
      else
      {
        size = v15->mValues.size;
      }
      switch ( (int)MapBoolStatEnum )
      {
        case 23:
          gamesliceSubType.mUID = qSymbol_Collectible_HealthShrine_14.mUID;
          v12 = "$COMMON_ABERDEEN";
          break;
        case 24:
          gamesliceSubType.mUID = qSymbol_Collectible_HealthShrine_14.mUID;
          v12 = "$COMMON_CENTRAL";
          break;
        case 25:
          gamesliceSubType.mUID = qSymbol_Collectible_HealthShrine_14.mUID;
          v12 = "$COMMON_KENNEDY_TOWN";
          break;
        case 26:
          gamesliceSubType.mUID = qSymbol_Collectible_HealthShrine_14.mUID;
          v12 = "$COMMON_NORTH_POINT";
          break;
        case 27:
          gamesliceSubType.mUID = qSymbol_Collectible_LockBox_14.mUID;
          v12 = "$COMMON_ABERDEEN";
          break;
        case 28:
          gamesliceSubType.mUID = qSymbol_Collectible_LockBox_14.mUID;
          v12 = "$COMMON_CENTRAL";
          break;
        case 29:
          gamesliceSubType.mUID = qSymbol_Collectible_LockBox_14.mUID;
          v12 = "$COMMON_KENNEDY_TOWN";
          break;
        case 30:
          gamesliceSubType.mUID = qSymbol_Collectible_LockBox_14.mUID;
          v12 = "$COMMON_NORTH_POINT";
          break;
        default:
          gamesliceSubType.mUID = v13;
          break;
      }
    }
    v16 = (UFG::qNode<UFG::qString,UFG::qString> *)UFG::UI::LocalizeText(v12);
    UFG::qString::qString(&depth);
    if ( gamesliceSubType.mUID == qSymbol_Collectible_HealthShrine_14.mUID )
    {
      v17 = UFG::GameStatTracker::Instance();
      v18 = (unsigned int)UFG::GameStatTracker::GetNumHealthShrinesCollected(v17) % 5;
      UFG::UIHKInfoPopupWidget::Get()->HealthShrineUpgradeProgress = v18;
      if ( v18 )
      {
        v19 = UFG::UI::LocalizeText("$HUD_COLLECTIBLES_HEALTHSHRINE_PROGRESS");
        LODWORD(depth.mNext) = 5 - v18;
        depth.mPrev = v16;
        UFG::qString::Format(&depth, v19, TrueCount, size);
      }
      else
      {
        UFG::qString::Format(&depth, "$HUD_COLLECTIBLES_HEALTHSHRINE_SUCCESS");
      }
    }
    else if ( gamesliceSubType.mUID == qSymbol_Collectible_LockBox_14.mUID )
    {
      v20 = 0i64;
      v40 = result;
      v21 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v37, "RewardsPropertySet");
      PropertyUtils::GetWithDefault<UFG::qSymbol>(&gamesliceType, retaddr, v21, &result[0].mUID, DEPTH_RECURSE);
      if ( gamesliceType.mUID != -1 )
      {
        PropertySet = UFG::PropertySetManager::GetPropertySet(&gamesliceType);
        if ( PropertySet )
        {
          v23 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v37, "UnlockItems");
          v24 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, v23, DEPTH_RECURSE);
          if ( v24 )
          {
            if ( v24->mNumElements )
            {
              ValuePtr = UFG::qPropertyList::GetValuePtr(v24, 0x1Au, 0);
              if ( ValuePtr && *(_QWORD *)ValuePtr )
                v26 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
              else
                v26 = 0i64;
              v27 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(v37, "Text");
              v20 = PropertyUtils::Get<char const *>(v26, v27, DEPTH_RECURSE);
            }
          }
        }
      }
      v28 = UFG::UI::LocalizeText("$HUD_COLLECTIBLES_LOCKBOX_SUCCESS");
      depth.mPrev = v16;
      UFG::qString::Format(&depth, v28, TrueCount, size);
      if ( v20 )
      {
        UFG::qString::operator+=(&depth, "<br><br>");
        v29 = UFG::UI::LocalizeText("$HUD_LOCKBOX_CLOTHING_FOUND");
        UFG::qString::operator+=(&depth, v29);
        UFG::qString::operator+=(&depth, " ");
        v30 = UFG::UI::LocalizeText(v20);
        UFG::qString::operator+=(&depth, v30);
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
      UFG::qString::qString(&v41);
      if ( PropertyUtils::PropertyExists(retaddr, (UFG::qArray<unsigned long,0> *)&qSymbol_Collectible_Caption_14) )
        v31 = (const char *)PropertyUtils::Get<char const *>(
                              retaddr,
                              (UFG::qArray<unsigned long,0> *)&qSymbol_Collectible_Caption_14);
      else
        v31 = "$HUD_COLLECTIBLE_GENERIC_SUCCESS";
      UFG::qString::Set(&v41, v31);
      v32 = UFG::UI::LocalizeText(v41.mData);
      v33 = v32;
      if ( (int)size > 0 && v32 && (int)UFG::qStringLength(v32) > 0 )
        UFG::qString::Format(&depth, v33, TrueCount, size);
      UFG::qString::~qString(&v41);
    }
    v34 = UFG::UIHKInfoPopupWidget::Get();
    UFG::UIHKInfoPopupWidget::Show(v34, depth.mData, &gamesliceSubType, 5.0, POSITION_DEFAULT);
    UFG::RewardsHandler::mItemUnlocked = 1;
    UFG::qString::~qString(&depth);
  }
}

// File Line: 999
// RVA: 0x4A1D50
__int64 __fastcall UFG::RewardsHandler::GetCappedScorePerMission(
        int score,
        UFG::GameStat::MapInt32Stat dbEntry,
        UFG::qSymbol *symGameSlice)
{
  __int64 v4; // rbp
  UFG::GameStatTracker *v6; // rbx
  UFG::PersistentData::MapInt *v7; // rdx
  __int64 v8; // rax
  UFG::PersistentData::KeyValue *p; // rcx
  int mIntValue; // ebx
  UFG::GameStatTracker *v11; // rax

  v4 = dbEntry;
  v6 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  p = v7->mValues.p;
  while ( p->mKey.mUID != symGameSlice->mUID )
  {
    v8 = (unsigned int)(v8 + 1);
    ++p;
    if ( (unsigned int)v8 >= v7->mValues.size )
      goto LABEL_12;
  }
  if ( (_DWORD)v8 == -1 )
LABEL_12:
    mIntValue = 0;
  else
    mIntValue = v7->mValues.p[v8].mIntValue;
  if ( mIntValue >= score )
    return 0i64;
  v11 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v11, (UFG::GameStat::MapInt32Stat)v4, symGameSlice, score);
  return (unsigned int)(score - mIntValue);
}

